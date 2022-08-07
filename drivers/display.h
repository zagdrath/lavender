/**
 * Lavender display functions
 *
 * Copyright (C) 2022 Codex Microsystems.
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#define VIDEO_ADDRESS 0xb8000
#define TOTAL_ROWS 25
#define TOTAL_COLS 80
#define STANDARD_MSG_COLOR 0x0f // Black bg, white foreground
#define ERROR_MSG_COLOR 0xf4 // Red bg, white background

#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

void clear();
void printf(char* str);