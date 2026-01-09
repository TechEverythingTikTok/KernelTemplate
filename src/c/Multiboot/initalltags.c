// initall.c
// 32 bit

#include <stdint.h>
#include <stddef.h>
#include "Multiboot/tags.h"

// tags defined here, initialized in mb2_tag_init
const multiboot_boot_cli_tag_t*                     boot_cli_tag                = NULL;
const multiboot_bootloader_name_tag_t*              bootloader_name_tag         = NULL;
const multiboot_modules_tag_t*                      modules_tag                 = NULL;
const multiboot_basic_memory_tag_t*                 basic_memory_tag            = NULL;
const multiboot_bios_boot_device_tag_t*             bootdev_tag                 = NULL;
const multiboot_mmap_tag_t*                         mmap_tag                    = NULL;
const multiboot_vbe_info_tag_t*                     vbe_info_tag                = NULL;
const multiboot_framebuffer_info_tag_t*             framebuffer_info_tag        = NULL;
const multiboot_elf_symbols_tag_t*                  elf_symbols_tag             = NULL;
const multiboot_apm_table_tag_t*                    apm_tag                     = NULL;
const multiboot_efi_32_bit_system_table_pointer*    efi_sys_table_pointer_tag   = NULL;
const multiboot_smbios_tables*                      smbios_tables_tag           = NULL;

/*
function is called from kmain
initialize given tag to the specific variable

[multiboot_basic_tag_t*] tag - tag that will be casted and placed accordingly
*/
void mb2_tag_init(multiboot_basic_tag_t* tag) {
    switch (tag->type) {
    case MULTIBOOT_BOOT_CLI_TYPE:
        boot_cli_tag = (const multiboot_boot_cli_tag_t*)tag;
        break;
    case MULTIBOOT_BOOTLOADER_NAME_TYPE:
        bootloader_name_tag = (const multiboot_bootloader_name_tag_t*)tag;
        break;
    case MULTIBOOT_MODULES_TYPE:
        modules_tag = (const multiboot_modules_tag_t*)tag;
        break;
    case MULTIBOOT_BASIC_MEMORY_INFO_TYPE:
        basic_memory_tag = (const multiboot_basic_memory_tag_t*)tag;
        break;
    case MULTIBOOT_BIOS_BOOT_DEVICE_TYPE:
        bootdev_tag = (const multiboot_bios_boot_device_tag_t*)tag;
        break;
    case MULTIBOOT_MMAP_TYPE:
        mmap_tag = (const multiboot_mmap_tag_t*)tag;
        break;
    case MULTIBOOT_VBE_INFO_TYPE:
        vbe_info_tag = (const multiboot_vbe_info_tag_t*)tag;
        break;
    case MULTIBOOT_FRAMEBUFFER_INFO_TYPE:
        framebuffer_info_tag = (const multiboot_framebuffer_info_tag_t*)tag;
        break;
    case MULTIBOOT_ELF_SYMBOLS_TYPE:
        elf_symbols_tag = (const multiboot_elf_symbols_tag_t*)tag;
        break;
    case MULTIBOOT_APM_TABLE_TYPE:
        apm_tag = (const multiboot_apm_table_tag_t*)tag;
        break;
    case MULTIBOOT_EFI_32_BIT_SYSTEM_TABLE_POINTER_TYPE:
        efi_sys_table_pointer_tag = (const multiboot_efi_32_bit_system_table_pointer*)tag;
        break;
    case MULTIBOOT_SMBIOS_TABLES:
        smbios_tables_tag = (const multiboot_smbios_tables*)tag;
        break;
    default:
        break;
    }
}