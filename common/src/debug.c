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
#include "debug.h"
#include "bootrom.h"

#ifdef _DEBUG

char * dbgprint_buf;
char * dbgprint_insert_point;


/**
 * @brief Initialize the debug subsystem
 *
 * @returns Nothing
 */
void dbginit(void) {
    /* Call the chip-specific code to set up the debug serial UART */
    chip_dbginit();
#ifdef _SIMULATION
    /*
     * For simulation, we also have a 1-line buffer in the communication_area
     */
    communication_area *p = (communication_area *)&_communication_area;
    dbgprint_buf = &p->dbgprint_buf[0];
    dbgprint_insert_point = dbgprint_buf;
#endif
}


/**
 * @brief Print out a character
 *
 * @param x The character to print
 *
 * @returns Nothing
 */
void dbgputc(int x) {
    /*
     * Call the chip-specific code to write the char to the debug serial UART
     */
    chip_dbgputc(x);
#ifdef _SIMULATION
    if ((x == '\r') || (x == '\n')) {
        /*
         * Start a new line by resetting back to the beginning of the buffer.
         */
        dbgprint_insert_point = dbgprint_buf;
    }
    else if (dbgprint_insert_point < &dbgprint_buf[DBGPRINT_BUF_LENGTH-1]) {
        /* Append the character and keep the string null-terminated */
        *dbgprint_insert_point++ = (char)x;
        *dbgprint_insert_point = '\0';
    }
#endif
}


/**
 * @brief Print out a string
 *
 * @param str The string to display (safe with NULL pointer)
 *
 * @returns Nothing
 */
void dbgprint(char *str) {
    if (str != NULL) {
        while (*str != 0) {
            dbgputc(*str);
            str++;
        }
    }
}

/**
 * @brief Print out a boolean as a T/F flag
 *
 * @param flag The boolean to display
 *
 * @returns Nothing
 */
void dbgprintbool(uint8_t flag) {
    dbgputc(flag? 'T' : 'F');
}

/**
 * @brief Print out an 8-bit unsigned integer in hex
 *
 * @param num The number to display
 *
 * @returns Nothing
 */
void dbgprinthex8(uint8_t num) {
    int digit;
    int nybble;

    for (digit = 1; digit >= 0; digit--) {
        nybble = (num >> (digit << 2)) & 0x0f;
        if (nybble < 10) {
            dbgputc('0' + nybble);
        } else {
            dbgputc('a' + (nybble - 10));
        }
    }
}

/**
 * @brief Print out a 32-bit unsigned integer in hex
 *
 * @param num The number to display
 *
 * @returns Nothing
 */
void dbgprinthex32(uint32_t num) {
    int byte;
    uint8_t byte_value;

    for (byte = 3; byte >= 0; byte--) {
        byte_value = (num >> (byte << 3)) & 0x0ff;
        dbgprinthex8(byte_value);
    }
}

/**
 * @brief Print out a 64-bit unsigned integer in hex
 *
 * @param num The number to display
 *
 * @returns Nothing
 */
void dbgprinthex64(uint64_t num) {
    int byte;
    uint8_t byte_value;

    for (byte = 7; byte >= 0; byte--) {
        byte_value = (num >> (byte << 3)) & 0x0ff;
        dbgprinthex8(byte_value);
    }
}

/**
 * @brief Print out a byte array
 *
 * @param buf Pointer to the memory to display
 * @param len The length in bytes of the buffer
 *
 * @returns Nothing
 */
void dbgprinthexbuf(uint8_t * buf, int len) {
    int count_on_line = 16;
    while (len > 0) {
        dbgprinthex8(*buf++);
        count_on_line--;
        if (count_on_line == 0) {
            dbgprint("\r\n");
            count_on_line = 16;
        } else {
            dbgputc(' ');
        }
        len--;
    }
}

/**
 * @brief Print out a message containing a 32-bit unsigned integer
 *
 * @param s1 The optional string to issue before the number.
 * @param num The number to display
 * @param s2 The optional string to issue after the number.
 *
 * @returns Nothing
 */
void dbgprintx32(char * s1, uint32_t num, char * s2) {
    dbgprint(s1);
    dbgprinthex32(num);
    dbgprint(s2);
}

/**
 * @brief Print out a message containing a 64-bit unsigned integer
 *
 * @param s1 The optional string to issue before the number.
 * @param num The number to display
 * @param s2 The optional string to issue after the number.
 *
 * @returns Nothing
 */
void dbgprintx64(char * s1, uint64_t num, char * s2) {
    dbgprint(s1);
    dbgprinthex64(num);
    dbgprint(s2);
}

/**
 * @brief Print out a message containing a byte array
 *
 * @param s1 The optional string to issue before the number.
 * @param buf Pointer to the memory to display
 * @param len The length in bytes of the buffer
 * @param s2 The optional string to issue after the number.
 *
 * @returns Nothing
 */
void dbgprintxbuf(char * s1, uint8_t * buf, int len, char * s2) {
    dbgprint(s1);
    dbgprinthexbuf(buf, len);
    dbgprint(s2);
}

#endif  /* #ifdef _DEBUG */
