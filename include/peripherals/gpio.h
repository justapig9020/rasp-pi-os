#include "peripherals.h"

#ifndef _GPIO_H_
#define _GPIO_H_

#define GPIO_BASE (PERIPHERAL_BASE + 0x200000)
#define GPFSEL0 ((reg_t)(GPIO_BASE + 0x0))
#define GPFSEL1 ((reg_t)(GPIO_BASE + 0x4))
#define GPFSEL2 ((reg_t)(GPIO_BASE + 0x8))
#define GPFSEL3 ((reg_t)(GPIO_BASE + 0xc))
#define GPFSEL4 ((reg_t)(GPIO_BASE + 0x10))
#define GPFSEL5 ((reg_t)(GPIO_BASE + 0x14))
#define GPSET0 ((reg_t)(GPIO_BASE + 0x1c))
#define GPSET1 ((reg_t)(GPIO_BASE + 0x20))
#define GPCLR0 ((reg_t)(GPIO_BASE + 0x28))
#define GPCLR1 ((reg_t)(GPIO_BASE + 0x2c))
#define GPLEV0 ((reg_t)(GPIO_BASE + 0x34))
#define GPLEV1 ((reg_t)(GPIO_BASE + 0x38))
#define GPEDS0 ((reg_t)(GPIO_BASE + 0x40))
#define GPEDS1 ((reg_t)(GPIO_BASE + 0x44))
#define GPREN0 ((reg_t)(GPIO_BASE + 0x4c))
#define GPREN1 ((reg_t)(GPIO_BASE + 0x50))
#define GPFEN0 ((reg_t)(GPIO_BASE + 0x58))
#define GPFEN1 ((reg_t)(GPIO_BASE + 0x5c))
#define GPHEN0 ((reg_t)(GPIO_BASE + 0x64))
#define GPHEN1 ((reg_t)(GPIO_BASE + 0x68))
#define GPLEN0 ((reg_t)(GPIO_BASE + 0x70))
#define GPLEN1 ((reg_t)(GPIO_BASE + 0x74))
#define GPAREN0 ((reg_t)(GPIO_BASE + 0x7c))
#define GPAREN1 ((reg_t)(GPIO_BASE + 0x80))
#define GPAFEN0 ((reg_t)(GPIO_BASE + 0x88))
#define GPAFEN1 ((reg_t)(GPIO_BASE + 0x8c))
#define GPPUD ((reg_t)(GPIO_BASE + 0x94))
#define GPPUDCLK0 ((reg_t)(GPIO_BASE + 0x98))
#define GPPUDCLK1 ((reg_t)(GPIO_BASE + 0x9c))

#endif
