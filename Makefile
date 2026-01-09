ASM = nasm -f elf32
GCC = gcc -m32 -ffreestanding -fno-stack-protector -fno-pie -Wall -Wextra -nostdlib -Iinclude -c
LD = ld -m elf_i386 -T linker.ld -o iso/boot/kernel.bin

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

	grub-mkrescue -o os.iso iso