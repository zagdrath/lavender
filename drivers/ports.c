/*
 * Copyright (C) 2022 Codex Microsystems
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "../include/ports.h"

unsigned char byte_in(unsigned short port) {
    unsigned char result;
    asm("in %%dx, %%al" : "=a"(result) : "d"(port));
    return result;
}

void byte_out(unsigned short port, unsigned char data) {
    asm("out %%al, %%dx" : : "a"(data), "d"(port));
}

unsigned short word_in(unsigned short port) {
    unsigned short result;
    asm("in %%dx, %%ax" : "=a"(result) : "d"(port));
    return result;
}

void word_out(unsigned short port, unsigned char data) {
    asm("out %%ax, %%dx" : : "a"(data), "d"(port));
}