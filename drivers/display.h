/**
 * Lavender display functions
 *
 * Copyright (C) 2022 Codex Microsystems.
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#define VGA_CTRL_REGISTER 0x3d4
#define VGA_DATA_REGISTER 0x3d5
#define VGA_OFFSET_LOW 0x0f
#define VGA_OFFSET_HIGH 0x0e

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f

void print_string(char *string);
void clear_screen();