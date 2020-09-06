#include "std/stdio.h"
#include "util/cpu.h"

static void set_el3_ret_el(unsigned int el) {
    unsigned long spsr_el3 = get_spsr_el3();
    printf("spsr: 0x%x\n", spsr_el3);

    printf("Going to el: %d\n", el);
    el &= 0b11;

    spsr_el3 &= ~(0xf);
    spsr_el3 |= el << 2;

    printf("Setting spsr: 0x%x\n", spsr_el3);
    set_spsr_el3(spsr_el3);
}

void __attribute__((noreturn)) ret_el(unsigned int el, void *addr) {
    set_el3_ret_addr(addr);
    set_el3_ret_el(el);
    printf("Prepare to eret\n");
    eret();
}
