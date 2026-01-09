// tags.h
// 32 bit

// This file defines Multiboot2 tag structures as specified by the GNU Multiboot2 spec.
// All structures are laid out to match the spec exactly; no padding is assumed.
// REFER TO THE MULTIBOOT2 SPEC FOR MORE INFORMATION
// https://www.gnu.org/software/grub/manual/multiboot2/multiboot.html

#ifndef TAGS_H
#define TAGS_H

#include <stdint.h>

#define MULTIBOOT_END_TYPE                              0
#define MULTIBOOT_BOOT_CLI_TYPE                         1
#define MULTIBOOT_BOOTLOADER_NAME_TYPE                  2
#define MULTIBOOT_MODULES_TYPE                          3
#define MULTIBOOT_BASIC_MEMORY_INFO_TYPE                4
#define MULTIBOOT_BIOS_BOOT_DEVICE_TYPE                 5
#define MULTIBOOT_MMAP_TYPE                             6
#define MULTIBOOT_VBE_INFO_TYPE                         7
#define MULTIBOOT_FRAMEBUFFER_INFO_TYPE                 8
#define MULTIBOOT_ELF_SYMBOLS_TYPE                      9
#define MULTIBOOT_APM_TABLE_TYPE                        10
#define MULTIBOOT_EFI_32_BIT_SYSTEM_TABLE_POINTER_TYPE  11
#define MULTIBOOT_SMBIOS_TABLES                         13

/*
basic tag structure:
[u32] - type
[u32] - size
*/

// basic tag
typedef struct {
    uint32_t type;
    uint32_t size;
} multiboot_basic_tag_t;

// basic memory information
typedef struct {
    uint32_t type;      // 4
    uint32_t size;      // 16
    uint32_t mem_lower;
    uint32_t mem_upper;
} multiboot_basic_memory_tag_t;

// BIOS boot device
typedef struct {
    uint32_t type;      // 5
    uint32_t size;      // 20
    uint32_t biosdev;
    uint32_t partition;
    uint32_t sub_partition;
} multiboot_bios_boot_device_tag_t;

// boot CLI
typedef struct {
    uint32_t type;      // 1
    uint32_t size;
    uint8_t string[];
} multiboot_boot_cli_tag_t;

// modules
typedef struct {
    uint32_t type;      // 3
    uint32_t size;
    uint32_t mod_start;
    uint32_t mod_end;
    uint8_t string[];
} multiboot_modules_tag_t;

// ELF symbols
typedef struct {
    uint32_t type;      // 9
    uint32_t size;
    uint16_t num;
    uint16_t entry_size;
    uint16_t shndx;
    uint16_t reserved;
    uint8_t section_headers_fragments[];
} multiboot_elf_symbols_tag_t;

// memory map (mmap)
typedef struct {
    uint64_t base_addr;
    uint64_t length;
    uint32_t type;
    uint32_t reserved;
} multiboot_mmap_entries_tag_t;
typedef struct {
    uint32_t type;      // 6
    uint32_t size;
    uint32_t entry_size;
    uint32_t entry_version;
    multiboot_mmap_entries_tag_t entries[];
} multiboot_mmap_tag_t;

// bootloader name
typedef struct {
    uint32_t type;      // 2
    uint32_t size;
    uint8_t string[];
} multiboot_bootloader_name_tag_t;

// APM table
typedef struct {
    uint32_t type;      // 10
    uint32_t size;      // 28
    uint16_t version;
    uint16_t cseg;
    uint32_t offset;
    uint16_t cseg_16;
    uint16_t dseg;
    uint16_t flags;
    uint16_t cseg_len;
    uint16_t cseg_16_len;
    uint16_t dseg_len;
} multiboot_apm_table_tag_t;

// VBE info
typedef struct {
    uint32_t type;      // 7
    uint32_t size;      // 784
    uint16_t vbe_mode;
    uint16_t vbe_interface_seg;
    uint16_t vbe_interface_off;
    uint16_t vbe_interface_len;
    uint8_t vbe_control_info[512];
    uint8_t vbe_mode_info[256];
} multiboot_vbe_info_tag_t;

// framebuffer info
typedef struct {
    uint8_t red_value;
    uint8_t green_value;
    uint8_t blue_value;
} multiboot_framebuffer_indexed_color_descriptors;
typedef struct {
    uint32_t framebuffer_palette_num_colors;
    multiboot_framebuffer_indexed_color_descriptors framebuffer_palette[];
} multiboot_framebuffer_indexed_color;
typedef struct {
    uint8_t framebuffer_red_field_pos;
    uint8_t framebuffer_red_mask_size;
    uint8_t framebuffer_green_field_pos;
    uint8_t framebuffer_green_mask_size;
    uint8_t framebuffer_blue_field_pos;
    uint8_t framebuffer_blue_mask_size;
} multiboot_framebuffer_rgb_color;
typedef struct {
    uint32_t type;      // 8
    uint32_t size;
    uint64_t framebuffer_addr;
    uint32_t framebuffer_pitch;
    uint32_t framebuffer_width;
    uint32_t framebuffer_height;
    uint8_t framebuffer_bpp;
    uint8_t framebuffer_type;
    uint8_t reserved;
    union {
        multiboot_framebuffer_indexed_color indexed;
        multiboot_framebuffer_rgb_color rgb;
    };
} multiboot_framebuffer_info_tag_t;

// EFI 32 bit system table pointer
typedef struct {
    uint32_t type;      // 11
    uint32_t size;      // 12
    uintptr_t pointer;
} multiboot_efi_32_bit_system_table_pointer;

// SMBIOS tables
typedef struct {
    uint32_t type;      // 13
    uint32_t size;
    uint8_t major;
    uint8_t minor;
    uint8_t reserved_smbios[6];
} multiboot_smbios_tables;

#endif