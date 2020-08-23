#include "peripherals/gpio.h"
#include <stdint.h>
//#include "peripherals/uart.h"

// inline void devices_init(void) { uart_init(); }

void init_gpio4() {
    uint32_t value = *((volatile uint32_t *)GPFSEL0);
    value &= ~(7 << (3 * 4));
    value |= 1 << (3 * 4);
    *((volatile uint32_t *)GPFSEL0) = value;
}

void set_gpio4() {
    uint32_t value = *((volatile uint32_t *)GPSET0);
    value |= 1 << 4;
    *((volatile uint32_t *)GPSET0) = value;
}

void init_kernel(void) {
    // devices_init();
    // uart_init();

    init_gpio4();
    set_gpio4();
    while (1)
        ;

    /*
    uart_write("Hello, world\r\n", sizeof("Hello, world\r\n"));
    while (1) {
        char recv;
        uart_read(&recv, 1);
        uart_write(&recv, 1);
        if (recv == '\r') {
            uart_write("\n", 1);
        }
    }
    */
}
