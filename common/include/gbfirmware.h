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

#ifndef __COMMON_INCLUDE_GBFIRMWARE_H
#define __COMMON_INCLUDE_GBFIRMWARE_H

extern uint32_t gbfw_cportid;

/* Greybus FirmWare request types */
#define GB_FW_OP_INVALID            0x00
#define GB_FW_OP_PROTOCOL_VERSION   0x01
#define GB_FW_OP_FIRMWARE_SIZE      0x02
#define GB_FW_OP_GET_FIRMWARE       0x03
#define GB_FW_OP_READY_TO_BOOT      0x04

/* Greybus FirmWare boot statuses */
#define GB_FW_BOOT_STATUS_INVALID   0x00
#define GB_FW_BOOT_STATUS_INSECURE  0x01
#define GB_FW_BOOT_STATUS_SECURE    0x02

/* Greybus FirmWare boot instructions */
#define GB_FW_BOOT_INSTR_FAILURE   0x00
#define GB_FW_BOOT_INSTR_OK        0x01

/* Greybus FirmWare error codes */
#define GB_FW_ERR_INVALID          (-1)
#define GB_FW_ERR_FAILURE          (-2)

/* Boot stage whose firmware we request */
#define NEXT_BOOT_STAGE            (BOOT_STAGE + 1)

/* Greybus FirmWare request and response payloads */
struct __attribute__ ((__packed__)) gbfw_protocol_version_request {
  uint8_t major, minor;
};

struct __attribute__ ((__packed__)) gbfw_firmware_size_request {
  uint8_t stage;
};

struct __attribute__ ((__packed__)) gbfw_firmware_size_response {
  size_t size;
};

struct __attribute__ ((__packed__)) gbfw_get_firmware_request {
  uint32_t offset, size;
};

struct __attribute__ ((__packed__)) gbfw_ready_to_boot_request {
  uint8_t status;
};

int greybus_cport_connect(void);
int greybus_cport_disconnect(void);

#endif
