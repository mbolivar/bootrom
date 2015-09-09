/**
 * Copyright (c) 2015 Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <stddef.h>
#include <string.h>
#include "bootrom.h"
#include "tftf.h"
#include "debug.h"
#include "data_loading.h"
#include "chipapi.h"
#include "crypto.h"
#include "unipro.h"
#include "utils.h"
#include "error.h"

#define NEW_VALIDATION


typedef struct {
    tftf_header header;
    crypto_processing_state crypto_state;
    unsigned char hash[HASH_DIGEST_SIZE];
    tftf_signature signature;
} tftf_processing_state;


static tftf_processing_state tftf;

/*
 * Prototypes
 */
bool valid_tftf_header(tftf_header * header);

static int load_tftf_header(data_load_ops *ops) {
    tftf_section_descriptor *section;
    uint32_t unipro_vid = 0;
    uint32_t unipro_pid = 0;
    uint32_t ara_vid = 0;
    uint32_t ara_pid = 0;
    uint32_t read_stat;

    tftf.crypto_state = CRYPTO_STATE_INIT;

    if (ops->load(&tftf.header, TFTF_HEADER_SIZE, false)) {
        set_last_error(BRE_TFTF_LOAD_HEADER);
        return -1;
    }

    if (!valid_tftf_header(&tftf.header)) {
        /* (valid_tftf_header took care of error reporting) */
        return -1;
    }

    /*
     * Check that the UniPro and Ara VID+PID matches the corresponding chip
     * VID+PID.
     *
     * Note: a 0-valued image VID/PID acts as a wild card and no comparison
     * takes place for that VID/PID.
     * TA-12 Read  DME attribute (DDBL1)
     */
    chip_unipro_attr_read(DME_DDBL1_MANUFACTURERID, &unipro_vid, 0,
                          ATTR_LOCAL, &read_stat);
    chip_unipro_attr_read(DME_DDBL1_PRODUCTID, &unipro_pid, 0,
                          ATTR_LOCAL, &read_stat);
    /* TA-14 Write/Read  DME attribute (New area of 16 words) */
    chip_unipro_attr_read(DME_DDBL2_VID, &ara_vid, 0, ATTR_LOCAL, &read_stat);
    chip_unipro_attr_read(DME_DDBL2_PID, &ara_pid, 0, ATTR_LOCAL, &read_stat);
    if (((tftf.header.unipro_vid != 0) &&
         (tftf.header.unipro_vid != unipro_vid)) ||
        ((tftf.header.unipro_pid != 0) &&
         (tftf.header.unipro_pid != unipro_pid)) ||
        ((tftf.header.ara_vid != 0) &&
         (tftf.header.ara_vid != ara_vid)) ||
        ((tftf.header.ara_pid != 0) &&
         (tftf.header.ara_pid != ara_pid))) {
        dbgprint("Image does not match our VID/PID\r\n");
        set_last_error(BRE_TFTF_VIDPID_MISMATCH);
#ifndef _PRODUCTION
        dbgprint("        __chip__ __tftf__\r\n");
        dbgprintx32("U-MID = ", unipro_vid, " ");
        dbgprintx32(NULL, tftf.header.unipro_vid, "\r\n");
        dbgprintx32("U-PID = ", unipro_pid, " ");
        dbgprintx32(NULL, tftf.header.unipro_pid, "\r\n");
        dbgprintx32("A-MID = ", ara_vid, " ");
        dbgprintx32(NULL, tftf.header.ara_vid, "\r\n");
        dbgprintx32("A-PID = ", ara_pid, " ");
        dbgprintx32(NULL, tftf.header.ara_pid, "\r\n");
#endif
        return -1;
    }


     /*
      * Process the TFTF sections
      */
    section = &tftf.header.sections[0];
    while(1) {
        if ((uint32_t)section - (uint32_t)&tftf.header >= TFTF_HEADER_SIZE) {
            dbgprint("too many tftf sections?\r\n");
            set_last_error(BRE_TFTF_HEADER_SIZE);
            return -1;
        }

        if (section->section_type == TFTF_SECTION_END) {
            break;
        }

        if (section->section_type == TFTF_SECTION_SIGNATURE) {
            if (tftf.crypto_state == CRYPTO_STATE_INIT) {
                uint32_t header_hash_len;

                /* found the first signature block, start hashing */
                hash_start();
                tftf.crypto_state = CRYPTO_STATE_HASHING;
                header_hash_len = (uint32_t)section - (uint32_t)&tftf.header;
                hash_update((unsigned char *)&tftf.header, header_hash_len);
            }
        } else {
            if (section->section_type == TFTF_SECTION_COMPRESSED_CODE ||
                section->section_type == TFTF_SECTION_COMPRESSED_DATA) {
                dbgprint("compressed section not supported in boot ROM\r\n");
                set_last_error(BRE_TFTF_COMPRESSION_UNSUPPORTED);
                return -1;
            }

            if (tftf.crypto_state == CRYPTO_STATE_HASHING &&
                section->section_type != TFTF_SECTION_CERTIFICATE) {
                dbgprint("illegal section after first signature\r\n");
                set_last_error(BRE_TFTF_SECTION_AFTER_SIGNATURE);
                return -1;
            }

            uint32_t sec_top = section->copy_offset + section->expanded_length;
            if (section->expanded_length < section->section_length ||
                sec_top > tftf.header.expanded_length) {
                dbgprint("section out of memory range\r\n");
                set_last_error(BRE_TFTF_MEMORY_RANGE);
                return -1;
            }
        }
        section++;
    }

    /* the header is validated */
    return 0;
}

static int process_tftf_section(data_load_ops *ops,
                                tftf_section_descriptor *section) {
    unsigned char *dest;
    bool hash_loaded_data = false;

    if (section->section_type == TFTF_SECTION_SIGNATURE) {
        dbgprint("WARNING: signature verification not implemented yet\r\n");
        if (ops->load(&tftf.signature, sizeof(tftf.signature), false)) {
            dbgprint("error loading signature\r\n");
            set_last_error(BRE_TFTF_LOAD_SIGNATURE);
            return -1;
        }
        switch (tftf.crypto_state) {
        case CRYPTO_STATE_HASHING:
            hash_final(tftf.hash);
            tftf.crypto_state = CRYPTO_STATE_HASHED;
            /* fall through */
        case CRYPTO_STATE_HASHED:
            if (verify_signature(tftf.hash, &tftf.signature) == 0) {
                tftf.crypto_state = CRYPTO_STATE_VERIFIED;
            }
            break;
        default:
            /* For other state, nothing need to be done here */
            break;
        }
        return 0;
    }

    dest = (unsigned char*)tftf.header.load_base + section->copy_offset;

    if (tftf.crypto_state == CRYPTO_STATE_HASHING) {
        hash_loaded_data = true;
    }

    if (ops->load(dest, section->section_length, hash_loaded_data)) {
        dbgprint("invalid tftf header size\r\n");
        set_last_error(BRE_TFTF_HEADER_SIZE);
        return -1;
    }


    return 0;
}

int load_tftf_image(data_load_ops *ops, uint32_t *is_secure_image) {
    tftf_section_descriptor *section;

    *is_secure_image = 0;

    if (load_tftf_header(ops)) {
        /* (load_tftf_header took care of error reporting) */
        return -1;
    }

    section = &tftf.header.sections[0];
    while(section->section_type != TFTF_SECTION_END) {
        if (process_tftf_section(ops, section)) {
            /* (process_tftf_section took care of error reporting)
             */
            return -1;
        }
        section++;
    }

    if (tftf.crypto_state == CRYPTO_STATE_VERIFIED) {
        /* finished loading and verifying secured image */
        *is_secure_image = 1;
    }

    communication_area *p = (communication_area *)&_communication_area;
    memcpy(p->stage_2_firmware_description,
           tftf.header.build_timestamp,
           sizeof(p->stage_2_firmware_description));

    if (tftf.crypto_state != CRYPTO_STATE_VERIFIED &&
        tftf.crypto_state != CRYPTO_STATE_INIT) {
        /**
         * this image contains signature blocks
         * but none of them were able to verify the data
         * so this image is corrupted
         */
        dbgprint("TFTF image corrupted\r\n");
        *is_secure_image = 0;
        return -1;
    }

    return 0;
}

void jump_to_image(void) {
    dbgflush();
    communication_area *p = (communication_area *)&_communication_area;
    p->boot_stage = NEXT_BOOT_STAGE;
    chip_jump_to_image(tftf.header.start_location);
}

/**
 * @brief Determine if the TFTF section type is valid
 *
 * @param section_type The section type to check
 *
 * @returns True if a valid section type, false otherwise
 */
bool valid_tftf_type(uint32_t section_type) {
     return (((section_type >= TFTF_SECTION_RAW_CODE) &&
              (section_type <= TFTF_SECTION_MANIFEST)) ||
             (section_type == TFTF_SECTION_SIGNATURE) ||
             (section_type == TFTF_SECTION_CERTIFICATE) ||
             (section_type == TFTF_SECTION_END));
}

/**
 * @brief Validate a TFTF section descriptor
 *
 * @param section The TFTF section descriptor to validate
 * @param header The TFTF header to which it belongs
 * @param section_contains_start Pointer to a flag that will be set if the
 *        image entry point lies within this section. (Untouched if not)
 * @param end_of_sections Pointer to a flag that will be set if the section
 *        type is the end-of-section-table marker. (Untouched if not)
 *
 * @returns True if valid section, false otherwise
 */
bool valid_tftf_section(tftf_section_descriptor * section,
                        tftf_header * header,
                        bool * section_contains_start,
                        bool * end_of_sections) {
    uint32_t    section_start;
    uint32_t    section_end;
    uint32_t    tftf_end;
    tftf_section_descriptor * other_section;

    if (!valid_tftf_type(section->section_type)) {
        dbgprint("Invalid section type found\r\n");
        set_last_error(BRE_TFTF_HEADER_TYPE);
        return false;
    }

    /* Is this the end-of-table marker? */
    if (section->section_type == TFTF_SECTION_END) {
        *end_of_sections = true;
        return true;
    }

    /*
     * Convert the section limits to absolute addresses to compare against
     * absolute addresses found in the TFTF header.
     */
    section_start = header->load_base + section->copy_offset;
    section_end = section_start + section->expanded_length;
    tftf_end = header->load_base + header->expanded_length;

    /* Does the section fall outside the overall TFTF span? */
    if ((section_start < header->load_base) || (section_end > tftf_end)) {
        dbgprint("TFTF section outside of TFTF\r\n");
        set_last_error(BRE_TFTF_MEMORY_RANGE);
        return false;
    }

    /* Does the section contain the entry point? */
    if ((header->start_location >= section_start) &&
        (header->start_location < section_end) &&
        (section->section_type == TFTF_SECTION_RAW_CODE)) {
        /*****/dbgprint("TFTF section contains start\r\n");
        *section_contains_start = true;
    }

    /*
     * Check this section for collision against all following sections.
     * Since we're called in a scanning fashion from the start to the end of
     * the sections array, all sections before us have already validated that
     * they don't collide with us.
     */
    for (other_section = section + 1;
         ((other_section < &header->sections[TFTF_MAX_SECTIONS]) &&
          (other_section->section_type != TFTF_SECTION_SIGNATURE) &&
          (other_section->section_type != TFTF_SECTION_END));
         other_section++) {
        if ((other_section->section_type != TFTF_SECTION_END) &&
            (other_section->expanded_length >= section->copy_offset) &&
            (other_section->copy_offset < section->expanded_length)) {
            dbgprint("TFTF sections collide\r\n");
            set_last_error(BRE_TFTF_COLLISION);
            return false;
        }
    }

    return true;
}

/**
 * @brief Validate a TFTF header
 *
 * @param header The TFTF header to validate
 *
 * @returns True if valid TFTF header, false otherwise
 */
bool valid_tftf_header(tftf_header * header) {
    tftf_section_descriptor * section;
    bool section_contains_start = false;
    bool end_of_sections = false;

    /* Verify the sentinel */
    if (header->sentinel_value != TFTF_SENTINEL) {
        dbgprintx32("TFTF invalid sentinel: ", header->sentinel_value, "\r\n");
        set_last_error(BRE_TFTF_SENTINEL);
        return false;
    }

    /* Verify the expanded/compressed lengths are sane */
    if (header->expanded_length < header->load_length) {
        dbgprintx32("TFTF compressed > raw: ", header->sentinel_value, "\r\n");
        set_last_error(BRE_TFTF_COMPRESSION_BAD);
        return false;
    }

    /* Verify that the TFTF fits in available memory */
    if (chip_validate_data_load_location((void *)header->load_base,
                                         header->expanded_length)) {
        dbgprintx32("TFTF length: ", header->sentinel_value, "\r\n");
        set_last_error(BRE_TFTF_MEMORY_RANGE);
        return false;
    }

    /* Verify all of the sections */
    for (section = &header->sections[0];
         (section < &header->sections[TFTF_MAX_SECTIONS]) && !end_of_sections;
         section++) {
        if (!valid_tftf_section(section, header, &section_contains_start,
                                &end_of_sections)) {
            /* (valid_tftf_section took care of error reporting) */
            return false;
        }
    }
    if (!end_of_sections) {
        dbgprint("TFTF no-end-of-sections marker");
        set_last_error(BRE_TFTF_NO_TABLE_END);
        return false;
    }

    /* Verify that, if this TFTF has a start address, it falls in one of our code sections. */
    if ((header->start_location != 0) && !section_contains_start) {
        dbgprint("Start address does not fall in any code section\r\n");
        return false;
    }

    /*
     * Verify that the remainder of the header (i.e., unused section
     * descriptors and the padding) is zero-filled
     */
    if (!is_constant_fill((uint8_t *)section,
                          (uint32_t)&header[1] - (uint32_t)section,
                          0x00)) {
        dbgprint("TFTF non-zero fill\r\n");
        set_last_error(BRE_TFTF_NON_ZERO_PAD);
        return false;
    }

    return true;
}
