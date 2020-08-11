#include "peripherals/uart.h"

inline void init_devices(void) { init_uart(9600); }

void init_kernel(void) {
    init_devices();

    uart_write("Hello, world\r\n", sizeof("Hello, world\r\n"));
    while (1) {
        char recv;
        uart_read(&recv, 1);
        uart_write(recv, 1);
        if (recv == '\r') {
            uart_write('\n', 1);
        }
    }
}
