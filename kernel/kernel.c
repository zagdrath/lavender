/**
 * Lavender kernel entry
 *
 * Copyright (C) 2022 Codex Microsystems.
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "kernel.h"
#include "../drivers/display.h"

void start_kernel() {
    clear();

	char str[] = "Welcome to Lavender.";
    printf(str);
}