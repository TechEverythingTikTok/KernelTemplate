##### This is a basic Multiboot2-compliant bootable kernel (32-bit mode) 

It's not even close to being a complete OS; you create your own OS from here.
This is just a starter template to save you some time and get you going.
I strongly recommend reading the Multiboot2 spec to understand what you are doing.

###### https://www.gnu.org/software/grub/manual/multiboot2/multiboot.html

Also, read the OSDev wiki for a better learning experience.
###### https://wiki.osdev.org/


### FILES
multiboot.asm
> - Multiboot2 compliant header, 8 byte aligned, contains:
> - Magic Number
> - Protected Mode Code
> - Header Length
> - Checksum
> - Tags

boot.asm
> - Sets up the stack, pushes the Multiboot2 values to the stack, and calls kmain
> - Halts the CPU if control is returned

panic.h / panic.c
> - Responsible for panic handling. Manually called for now. Just disables interrupts and halts

initalltags.h / initalltags.c
> - Responsible for tag initialization and accessing later when needed

kernel.c
> - Responsible for being called, getting arguments, handling initializer function calls, and more later

grub.cfg
> - Configuration for GRUB. You can tweak some values here. Not much flexibility

linker.ld
> - Script for the ld command to handle proper linking between files

Makefile
> - Convenience script. I strongly recommend you use Makefile / CMake during your development process of this OS or any of your projects

### Setup Docker
1. Install Docker
2. Run the following command if you havent built the image(besure Docker engine is on or else itll error!)
``
docker build dockerenv -t kernel-buildenv
``
3. Enter build environment:

- Linux or MacOS: `docker run --rm -it -v "$(pwd)":/root/env kernel-buildenv`
- Windows (CMD): `docker run --rm -it -v "%cd%":/root/env kernel-buildenv`
- Windows (PowerShell): `docker run --rm -it -v "${pwd}:/root/env" kernel-buildenv`
- Please use the linux command if you are using WSL, msys2 or git bash
-> NOTE: If you are having trouble with an unshared drive, ensure your docker daemon -> has access to the drive you're development environment is in. For Docker Desktop, -> this is in "Settings > Shared Drives" or "Settings > Resources > File Sharing".


### Required tools
> - make - use Makefile to automatically run compile commands (not needed, but HEAVILY recommended for organizing.)
> - gcc - compile .c files
> - ld (comes with gcc) - link files to make them work
> - nasm - Make .asm files into .o
> - grub - Make ISO
> - docker(not needed, but HEAVILY recommended for organizing.)

I recommend you have an emulator like qemu and run this with qemu-system-i386
