#ifndef _CPU_H_
#define _CPU_H_

int get_el();
void set_el3_ret_addr(void *);
unsigned long get_spsr_el3();
void set_spsr_el3(unsigned long);
void __attribute__((noreturn)) eret();

#endif
