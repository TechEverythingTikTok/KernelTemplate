// kernel.c
// 32 bit

#include <stdint.h>
#include <stdbool.h>
#include "panic.h"
#include "Multiboot/tags.h"
#include "Multiboot/initalltags.h"

/*
init function that is called from boot.asm

[u32] - mb2_ident - identifier for multiboot2; must contain the value 0x36d76289
[u32] - mb2_addr - address for multiboot2 structure
*/
void kmain(uint32_t mb2_ident, uint32_t mb2_addr) {
    if (mb2_ident != 0x36d76289) {
        // invalid multiboot2 identifier
        panic();
        return;
    }

    if (mb2_addr & 7) {
        // unaligned mbi
        panic();
        return;
    }

    multiboot_basic_tag_t* tag;

    for (
        tag = (multiboot_basic_tag_t*)(mb2_addr + 8);
        tag->type != MULTIBOOT_END_TYPE;
        tag = (multiboot_basic_tag_t*)((uint8_t*)tag + ((tag->size + 7) & ~7))
    ) {
        // loop through each tag
        mb2_tag_init(tag);
    }

    while (true) {
        __asm__ volatile("hlt");
    }
}
