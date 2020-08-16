#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

#include <stdint.h>
typedef volatile uint32_t *reg_t;
typedef volatile uint32_t regv_t;

#define PERIPHERAL_BASE 0x7E000000 // Base address on bus
#define PERIPHERAL_SIZE 0x1000000

#endif
