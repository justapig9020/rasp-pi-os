#include "peripherals/gpio.h"

void gpio_init(unsigned int pin, enum GPIO_MODE mode) {
    reg_t reg = GPFSEL0;
    regv_t value;
    if (pin > 9) {
        pin %= 10;
        reg = GPFSEL1;
    }
    value = *reg;
    value &= ~(7 << (pin * 3));
    value |= mode << (pin * 3);
    *reg = value;
}

void gpio_set(unsigned int pin) {
    reg_t reg = GPSET0;
    if (pin > 31) {
        pin %= 32;
        reg = GPSET1;
    }
    *reg |= 1 << pin;
}
