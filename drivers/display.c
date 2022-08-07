/**
 * Lavender display functions
 *
 * Copyright (C) 2022 Codex Microsystems.
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "display.h"
#include "ports.h"

int CURRENT_CURSOR_POSITION = 0;

void set_cursor_position(int offset);
int get_cursor_position();

void clear() {
    char* video_memory = (char*) VIDEO_ADDRESS;
    int row = 0;
    for(row = 0; row < TOTAL_COLS * TOTAL_ROWS; row++)
    {
        video_memory[row * 2] = ' ';
        video_memory[row * 2 + 1] = 0x0f;
    }
    CURRENT_CURSOR_POSITION = 0x00;
    set_cursor_position(CURRENT_CURSOR_POSITION);
}

void printf(char *str) {
    char* video_memory = (char*) VIDEO_ADDRESS;
    int pos = 0;
    int cursorPosition = get_cursor_position();
    while(str[pos] != 0)
    {
        video_memory[cursorPosition] = str[pos++];
        video_memory[cursorPosition + 1] = 0x0f;
        cursorPosition = cursorPosition + 2;
    }
    set_cursor_position(cursorPosition);
}

int get_cursor_position() {
    byte_out(REG_SCREEN_CTRL, 14);
    int position = byte_in(REG_SCREEN_DATA) << 8;

    byte_out(REG_SCREEN_CTRL, 15);
    position += byte_in(REG_SCREEN_DATA);

    return position * 2;
}

void set_cursor_position(int offset)
{
    offset /= 2;
    byte_out(REG_SCREEN_CTRL, 14);
    byte_out(REG_SCREEN_DATA, offset >> 8);

    byte_out(REG_SCREEN_CTRL, 15);
    byte_out(REG_SCREEN_DATA, offset & 0xff);
}