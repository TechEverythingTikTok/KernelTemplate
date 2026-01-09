##### This is a basic Multiboot2-compliant bootable kernel (32-bit mode)

It's not even close to being a complete OS; you create your own OS from here.
This is just a starter template to save you some time and get you going.
I strongly recommend reading the Multiboot2 spec to understand what you are doing.

###### https://www.gnu.org/software/grub/manual/multiboot2/multiboot.html

multiboot.asm
> Multiboot2 compliant header, 8 byte aligned, contains:
> Magic Number
> Protected Mode Code
> Header Length
> Checksum
> Tags

boot.asm
> Sets up the stack, pushes the Multiboot2 values to the stack, and calls kmain
> Halts the CPU if control is returned

gdt.asm / gdt.c
> Handles initialization of GDT (Global Descriptor Table)

isr.asm
> Handles the ISR stubs (you can add more functions from 47 on; software interrupts)

idt.c
> Handles initialization of IDT (Interrupt Descriptor Table)

pic.c / pic.h
> Handles PIC remapping, IRQ mask clearing and unclearing, and PIC EOI

isr.c
> Common isr C handler
> !! THIS FILE IS JUST A TEMPLATE; YOU WILL COMPLETE THIS WITH YOUR OWN FUNCTIONS AND METHODS !!

panic.h / panic.c
> Responsible for panic handling. Manually called for now. Just disable interrupts and halt

initalltags.h / initalltags.c / tags.h
> Responsible for tag initialization and accessing later when needed

io.h
> inb(), outb() and io_wait() functions

stdio.c / stdio.h
> debug_out() function to output string to COM1 serial

kernel.c
> Responsible for being called, getting arguments, handling initializer function calls, and more later

grub.cfg
> Configuration for GRUB. You can tweak some values here. Not much flexibility

linker.ld
> Script for the ld command to handle proper linking between files

Makefile
> Convenience script. I strongly recommend you use Makefile / CMake during your development process of this OS or any of your projects

Required tools:
> make
> gcc
> ld (comes with gcc)
> nasm
> grub

I recommend you have an emulator like qemu and run this with qemu-system-i386