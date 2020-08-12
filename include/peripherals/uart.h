#ifndef _UART_H_
#define _UART_H_

#include "peripherals.h"

#define UART_BASE   (PERIPHERAL_BASE + 0x20100)
#define UART_DR     (UART_BASE)
#define UART_RSRECR (UART_BASE + 0x4)
#define UART_FR     (UART_BASE + 0x18)
#define UART_ILPR   (UART_BASE + 0x20)
#define UART_IBRD   (UART_BASE + 0x24)
#define UART_FBRD   (UART_BASE + 0x28)
#define UART_LCRH   (UART_BASE + 0x2c)
#define UART_CR     (UART_BASE + 0x30)
#define UART_IFLS   (UART_BASE + 0x34)
#define UART_IMSC   (UART_BASE + 0x38)
#define UART_RIS    (UART_BASE + 0x3c)
#define UART_MIS    (UART_BASE + 0x40)
#define UART_ICR    (UART_BASE + 0x44)
#define UART_DMACR  (UART_BASE + 0x48)
#define UART_ITCR   (UART_BASE + 0x80)
#define UART_ITIP   (UART_BASE + 0x84)
#define UART_ITOP   (UART_BASE + 0x88)
#define UART_TDR    (UART_BASE + 0x8c)


#define MHZ             *1000000
#define UART_CLK        48 MHZ
#define BAUD_RATE       115200
#define BAUD_RATE_DIV   ((double)UART_CLK / 16 * BAUD_RATE)
#define UART_DIV_INT    ((unsigned int) BAUD_RATE_DIV)
#define UART_DIV_BOU    ((double) (BAUD_RATE_DIV - UART_DIV_INT) * 64 + 0.5)

void uart_init(void);
char uart_getchar();
int uart_read(char*, int);
int uart_write(char*, int);

#endif
