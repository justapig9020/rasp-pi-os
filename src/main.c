#include "peripherals/gpio.h"
#include "peripherals/uart.h"
#include <stdint.h>

static inline void devices_init(void) { uart_init(); }

void init_kernel(void) {
    devices_init();
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
