; boot.asm
; 32 bit

section .bss
stack_bottom:   resb 8192   ; stack bottom (reserved 8KB)

section .text
bits 32         ; 32 bit mode
extern kmain    ; C function
global _start   ; _start label is just below

_start:
    ; disable interrupts
    cli

    ; set up stack
    mov esp, stack_bottom + 8192    ; esp is now pointing to stack top
    and esp, 0xFFFFFFF0             ; 16-byte align

    push ebx    ; multiboot2 physical address
    push eax    ; multiboot 2 identifier

    call kmain  ; call kmain function in C

    add esp, 8  ; pop both arguments

    jmp .end    ; handle end
.end:
    cli         ; disable interrupts
    hlt         ; permanently relax CPU
    jmp .end    ; useless jump back to .end, just a fail safe