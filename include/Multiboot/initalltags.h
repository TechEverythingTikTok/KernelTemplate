// initall.h
// 32 bit

#ifndef INITALL_H
#define INITALL_H

#include "Multiboot/tags.h"

// tags defined here, initialized in mb2_tag_init
extern const multiboot_boot_cli_tag_t*                     boot_cli_tag;
extern const multiboot_bootloader_name_tag_t*              bootloader_name_tag;
extern const multiboot_modules_tag_t*                      modules_tag;
extern const multiboot_basic_memory_tag_t*                 basic_memory_tag;
extern const multiboot_bios_boot_device_tag_t*             bootdev_tag;
extern const multiboot_mmap_tag_t*                         mmap_tag;
extern const multiboot_vbe_info_tag_t*                     vbe_info_tag;
extern const multiboot_framebuffer_info_tag_t*             framebuffer_info_tag;
extern const multiboot_elf_symbols_tag_t*                  elf_symbols_tag;
extern const multiboot_apm_table_tag_t*                    apm_tag;
extern const multiboot_efi_32_bit_system_table_pointer*    efi_sys_table_pointer_tag;
extern const multiboot_smbios_tables*                      smbios_tables_tag;

/*
function that is called from kmain

[multiboot_basic_tag_t*] tag - tag that will be casted and placed accordingly
*/
void mb2_tag_init(multiboot_basic_tag_t* tag);

#endif