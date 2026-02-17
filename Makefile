# Compiler configuration
ASM = nasm -f elf32
GCC = gcc -m32 -ffreestanding -fno-stack-protector -fno-pie -Wall -Wextra -nostdlib -Iinclude -c
LD = ld -m elf_i386 -T linker.ld -o iso/boot/kernel.bin

# Kernel configuration
KERNEL_NAME = x32_KERNEL

# Main Logic
# DISCLAIMER:
# Do not touch this unless you REALLY know what you are doing
# Only touch this when fixing a bug or adding a feature/folder/file(we should get dynamic file handling)

# Also someone PLEASE add dynamic file handling... - HashedVsy 19:56 17.02.2026
# American format:
# HashedVsy 7:56PM 02.17.2026
all:
	$(ASM) src/asm/multiboot.asm -o build/multiboot.o
	$(ASM) src/asm/boot.asm -o build/boot.o

	$(GCC) src/c/Multiboot/initalltags.c -o build/initalltags.o
	$(GCC) src/c/panic.c -o build/panic.o
	$(GCC) src/c/kernel.c -o build/kernel.o

	$(LD) \
		build/multiboot.o build/boot.o \
		build/initalltags.o \
		build/panic.o \
		build/kernel.o

	grub-mkrescue -o $(KERNEL_NAME).iso iso