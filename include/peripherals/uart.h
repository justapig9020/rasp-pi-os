#ifndef _UART_H_
#define _UART_H_

#include "peripherals.h"

#define UART_BASE (PERIPHERAL_BASE + 0x201000)
#define UART_DR ((reg_t)(UART_BASE))
#define UART_RSRECR ((reg_t)(UART_BASE + 0x4))
#define UART_FR ((reg_t)(UART_BASE + 0x18))
#define UART_ILPR ((reg_t)(UART_BASE + 0x20))
#define UART_IBRD ((reg_t)(UART_BASE + 0x24))
#define UART_FBRD ((reg_t)(UART_BASE + 0x28))
#define UART_LCRH ((reg_t)(UART_BASE + 0x2c))
#define UART_CR ((reg_t)(UART_BASE + 0x30))
#define UART_IFLS ((reg_t)(UART_BASE + 0x34))
#define UART_IMSC ((reg_t)(UART_BASE + 0x38))
#define UART_RIS ((reg_t)(UART_BASE + 0x3c))
#define UART_MIS ((reg_t)(UART_BASE + 0x40))
#define UART_ICR ((reg_t)(UART_BASE + 0x44))
#define UART_DMACR ((reg_t)(UART_BASE + 0x48))
#define UART_ITCR ((reg_t)(URT_BASE + 0x80))
#define UART_ITIP ((reg_t)(UART_BASE + 0x84))
#define UART_ITOP ((reg_t)(UART_BASE + 0x88))
#define UART_TDR ((reg_t)(UART_BASE + 0x8c))

#define MHZ *1000000
#define UART_CLK 48 MHZ
#define BAUD_RATE 9600
#define BAUD_RATE_DIV ((double)UART_CLK / (BAUD_RATE << 4))
#define UART_DIV_INT ((unsigned int)BAUD_RATE_DIV)
#define UART_DIV_BOU ((double)(BAUD_RATE_DIV - UART_DIV_INT) * 64 + 0.5)

void uart_init(void);
char uart_getchar();
int uart_read(char *, int);
int uart_write(char *, int);

#endif
