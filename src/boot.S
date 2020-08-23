#include "mm/mm.h"

.section ".text.boot"

.globl _reset
_reset:
    mrs x0, mpidr_el1
    and x0, x0, #0xFF // seperate processor id
    cbz x0, _init_c

// all processor stay in a infinity loop, except processor 0
_loop:
    b _loop

_init_c:
    mov sp, #LOW_MEMORY // init stack

    adr x0, bss_begin
    adr x1, bss_end
    sub x1, x1, x0
    bl bzero
    bl init_kernel
    b _loop
