#include "peripherals/uart.h"
#include "peripherals/gpio.h"
#include "util/time.h"

int uart_read(char *des, int len) {
    int i;
    for (i = 0; i < len; i++) {
        while (*UART_FR & (1 << 4))
            ;
        des[i] = *UART_DR & 0xff;
    }
    return i;
}

int uart_write(char *src, int len) {
    int i;
    for (i = 0; i < len; i++) {
        while (*UART_FR & (1 << 5))
            ;
        *UART_DR = (*UART_DR & (~0xff)) | src[i];
    }
    return i;
}

char uart_getchar() {
    char ret;
    uart_read(&ret, 1);
    return ret;
}

void uart_init(void) {
    unsigned int selector;

    selector = *GPFSEL1;
    selector &= ~(7 << 12);
    selector |= 4 << 12; // set alt0 for gpio14
    selector &= ~(7 << 15);
    selector |= 4 << 15; // set alt0 for gpio15
    *GPFSEL1 = selector;

    *GPPUD = 0;
    delay(150);
    *GPPUDCLK0 = (1 << 14) | (1 << 15);
    delay(150);
    *GPPUDCLK0 = 0;

    // uart
    *UART_IBRD = UART_DIV_INT; // set baud rate
    *UART_FBRD = UART_DIV_BOU; // set baud rate
    *UART_LCRH = (1 << 4) | (3 << 5);
    *UART_CR = (1 | (1 << 8) | (1 << 9));
}
