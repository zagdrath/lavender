#!/bin/sh

# Create directories
mkdir -p build/boot
mkdir -p build/boot/grub

# Move files
mv build/lavender.bin build/boot/lavender.bin

# Create GRUB config
cat > grub.cfg << EOF
menuentry "Lavender" {
	multiboot /boot/lavender.bin
}
EOF

# Move GRUB config
mv grub.cfg build/boot/grub/grub.cfg

# Make ISO
grub-mkrescue -o build/boot/lavender.iso build

# Run QEMO
qemu-system-i386 -cdrom build/boot/lavender.iso