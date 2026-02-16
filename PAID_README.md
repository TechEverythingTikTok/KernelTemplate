##### Multiboot2-Compliant Bootable Kernel (32-bit)

This is a minimal Multiboot2-compliant 32-bit kernel template designed to give you a clean starting point for OS development.

It is not a complete operating system.
It provides the fundamental bootstrapping and early initialization required to begin building your own OS.

You are strongly encouraged to read the Multiboot2 specification to fully understand the boot process and the structures being used:

https://www.gnu.org/software/grub/manual/multiboot2/multiboot.html

Project Structure:

> multiboot.asm
8-byte aligned Multiboot2 header
Includes:
- Magic number
- Header length
- Checksum
- Required tags
- Protected mode entry code

> boot.asm
- Sets up the stack
- Pushes Multiboot2-provided values
- Transfers control to kmain()
- Halts the CPU if execution returns

> gdt.asm / gdt.c
- Initializes the Global Descriptor Table (GDT)

> idt.c
- Initializes the Interrupt Descriptor Table (IDT)

> isr.asm
- Defines ISR stubs
- Software interrupts available starting from vector 47

> isr.c
- Common C-level ISR handler
- This file is intentionally minimal — extend it with your own handlers and logic

> pic.c / pic.h
- PIC remapping
- IRQ mask control
- End-of-interrupt (EOI) handling

> panic.c / panic.h
- Basic panic handler
- Disables interrupts and halts execution (Currently manually triggered)

> initalltags.c / initalltags.h / tags.h
- Multiboot2 tag parsing and storage
- Provides access to bootloader-provided information

> io.h
- inb(), outb(), and io_wait() port I/O functions

> stdio.c / stdio.h
- debug_out() function
- Serial output via COM1 (useful for debugging)

> kernel.c
- Kernel entry logic (kmain)
- Argument handling
- Responsible for initialization flow
- Designed to be extended

> grub.cfg
- GRUB configuration file
- Minimal configuration for booting the kernel

> linker.ld
- Linker script
- Ensures correct memory layout and section placement

> Makefile
- Build automation
- Highly recommended for structured OS development workflows

>> Required Tools
- make
- gcc
- ld (included with GCC)
- nasm
- grub
- xorriso required for grub-mkrescue

Use an emulator such as qemu-system-i386

> This template exists to remove the repetitive setup phase of OS development and allow you to focus on implementing:
- Memory management
- Scheduling
- Filesystems
- Drivers
- System calls

It provides a clean, understandable base — nothing more.
