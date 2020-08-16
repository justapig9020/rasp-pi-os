#include "peripherals/gpio.h"
#include "peripherals/uart.h"

inline void devices_init(void) {
    uart_init();
    gpio_init(4, OUTPUT);
}

void init_kernel(void) {
    // devices_init();
    uart_init();

    gpio_set(4);
    uart_write("Hello, world\r\n", sizeof("Hello, world\r\n"));
    while (1) {
        char recv;
        uart_read(&recv, 1);
        uart_write(&recv, 1);
        if (recv == '\r') {
            uart_write("\n", 1);
        }
    }
}
