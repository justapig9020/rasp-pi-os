#include "mm/mm.h"
#include "sysregs.h"

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

_init_el:
    ldr    x0, =SCTLR_VALUE_MMU_DISABLED
    msr    sctlr_el1, x0

    ldr    x0, =HCR_VALUE
    msr    hcr_el2, x0

    ldr    x0, =SCR_VALUE
    msr    scr_el3, x0

    ldr x0, =SPSR_VALUE
    msr spsr_el3, x0

    adr x0, _init_el0
    msr elr_el3, x0
    eret

_init_el0:
    mov sp, #LOW_MEMORY // init stack

    adr x0, bss_begin
    adr x1, bss_end
    sub x1, x1, x0
    bl bzero
    bl main

    b _loop
