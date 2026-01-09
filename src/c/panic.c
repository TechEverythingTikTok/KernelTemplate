// panic.c
// 32 bit

#include "panic.h"

/*
halt kernel and panic
*/
__attribute__((noreturn))
void panic() {
    __asm__ volatile ("cli");
    __asm__ volatile ("hlt");
    __builtin_unreachable();
}