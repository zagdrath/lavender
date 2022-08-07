#!/bin/sh

# Make directories
mkdir build

# Build the bootloader
i686-elf-as arch/i386/boot.s -o build/boot.o

# Build main kernel file
i686-elf-gcc drivers/ports.h drivers/ports.c drivers/display.c drivers/display.h kernel/kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -nostdlib -Wall -Wextra -r

# Link the kernel
i686-elf-gcc -T arch/i386/linker.ld -o build/lavender.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o -lgcc