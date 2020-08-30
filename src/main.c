#include "peripherals/gpio.h"
#include "peripherals/uart.h"
#include "std/stdio.h"

static inline void devices_init(void) { uart_init(); }

void prt_99() {
    for (int i = 0; i < 10; i++) {
        int j;
        for (j = 0; j < 5; j++) {
            printf("%d * %d = %d\t", i, j, i * j);
        }
        printf("\n");
        for (; j < 10; j++) {
            printf("%d * %d = %d\t", i, j, i * j);
        }
        printf("\n");
    }
}

void prt_hex() {
    for (unsigned long i = 0; i <= 0xff; i++) {
        printf("0x%x ", i);
        if ((i & 0xf) == 0xf) {
            printf("\n");
        }
    }
}

void init_kernel(void) {
    devices_init();
    printf("Hello ,World!\n");

    prt_99();
    prt_hex();

    while (1) {
        char recv;
        uart_read(&recv, 1);
        printf("%c", recv);
    }
}
