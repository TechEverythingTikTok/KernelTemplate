SECTIONS {
    . = 2M;

    .multiboot :
    {
        *(.multiboot)
    }

    .text :
    {
        *(.text)
    }

    .bss :
    {
        *(.bss)
        *(COMMON)
    }

    .rodata :
    {
        *(.rodata)
    }

    .data :
    {
        *(.data)
    }
}