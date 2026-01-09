; multiboot.asm
; multiboot2 compliant header
section .multiboot
align 8 ; must be 8 byte aligned
header_start:
    dd 0xe85250d6                   ; magic number
    dd 0                            ; protected mode
    dd (header_end - header_start)  ; header length (difference between end and start)

    ; checksum
    ; sum of all fields above subtracted from 0x100000000
    dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

    ; tags

    ; tag structure
    ; -------------
    ; [u16] - type
    ; [u16] - flags
    ; [u32] - size
    ; [varies] - specific tag information
    ; -------------
    ; see multiboot2 spec for specific tag information
    ; insert more tags here
    ; end tag comes last

    ; end tag
    dw 0
    dw 0
    dd 8
header_end: