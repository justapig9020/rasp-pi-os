.globl get_el
get_el:
    mrs x0, CurrentEL
    lsr w0, w0, #2
    ret

.globl set_el3_ret_addr
set_el3_ret_addr:
    msr elr_el3, x0
    ret

.globl get_spsr_el3
get_spsr_el3:
    mrs x0, spsr_el3
    ret

.globl set_spsr_el3
set_spsr_el3:
    msr spsr_el3, x0
    ret

.globl eret
eret:
    eret
