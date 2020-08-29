#include "peripherals/uart.h"

void uart_init(void)
{
    unsigned int selector;

	selector = get32(GPFSEL1);
	selector &= ~(7<<12);                   // clean gpio14
	selector |= 4<<12;                      // set alt5 for gpio14
	selector &= ~(7<<15);                   // clean gpio15
	selector |= 4<<15;                      // set alt5 for gpio15
	put32(GPFSEL1,selector);

	put32(GPPUD,0);
	delay(150);
	put32(GPPUDCLK0,(1<<14)|(1<<15));
	delay(150);
	put32(GPPUDCLK0,0);

    //uart 
    put32(UART_IBRD, UART_DIV_INT); //set baudrate 115200
    put32(UART_FBRD, UART_DIV_BOU);
    put32(UART_LCRH, (1 << 4) | (3 << 5));
    put32(UART_CR, (1 | (1 << 8) | (1 << 9)));
}
char uart_getchar()
{

}
int uart_read(char*, int)
{

}
int uart_write(char*, int)
{

}

