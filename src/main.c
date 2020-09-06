#include "exception.h"
#include "peripherals/gpio.h"
#include "peripherals/uart.h"
#include "std/stdio.h"
#include "util/cpu.h"

static inline void devices_init(void) { uart_init(); }

void main(void);

void init_kernel(void) {
    devices_init();
    printf("Hello ,World!\n");
    printf("Current EL: %d\n", get_el());
    // ret_el(0, main);
}

void main(void) {
    // devices_init();
    printf("Current EL: %d\n", get_el());
    while (1) {
        char recv;
        uart_read(&recv, 1);
        printf("%c", recv);
    }
}
