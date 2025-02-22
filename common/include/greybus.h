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

#ifndef __COMMON_INCLUDE_GREYBUS_H
#define __COMMON_INCLUDE_GREYBUS_H

#define GREYBUS_MAJOR_VERSION        0
#define GREYBUS_MINOR_VERSION        1

typedef struct {
    uint16_t size;
    uint16_t id;
    uint8_t  type;
    uint8_t  status;
    uint16_t padding;
} __attribute__ ((packed)) gb_operation_header;

#define GB_TYPE_RESPONSE  0x80

#define GB_CTRL_OP_VERSION           0x01
#define GB_CTRL_OP_PROBE_AP          0x02
#define GB_CTRL_OP_GET_MANIFEST_SIZE 0x03
#define GB_CTRL_OP_GET_MANIFEST      0x04
#define GB_CTRL_OP_CONNECTED         0x05
#define GB_CTRL_OP_DISCONNECTED      0x06

#define GB_OP_SUCCESS                0x00
#define GB_OP_INVALID                0x06
#define GB_OP_UNKNOWN_ERROR          0xFE

#define GB_MAX_PAYLOAD_SIZE          (0x200)

#define CONTROL_CPORT 0

int control_cport_handler(uint32_t cportid,
                          void *data,
                          size_t len);

int greybus_op_response(uint32_t cport,
                        gb_operation_header *op_header,
                        uint8_t status,
                        unsigned char *payload_data,
                        uint16_t payload_size);

int greybus_send_request(uint32_t cport,
                         uint16_t id,
                         uint8_t type,
                         unsigned char *payload_data,
                         uint16_t payload_size);

#endif /* __COMMON_INCLUDE_GREYBUS_H */
