#include "std/stdio.h"
#include "peripherals/uart.h"
#define BUF_SIZE 1024

int abs(int n) {
    return (n ^ (n >> 31)) - (n >> 31);
} // TEMP, should be place into some math relative library

static char buf[BUF_SIZE];
static unsigned int buf_len;

void _int_to_str(int n) {
    if (n > 10) {
        _int_to_str(n / 10);
    }
    register int digit = n % 10;
    buf[buf_len++] = digit + '0';
}

void int_to_str(int n) {
    if (n < 0) {
        n = abs(n);
        buf[buf_len++] = '-';
    }
    _int_to_str(n);
}

char hex_to_char(unsigned char h) {
    if (h >= 0 && h <= 9)
        return h + '0';

    char hex;
    switch (h) {
    case 0xa:
        hex = 'a';
        break;
    case 0xb:
        hex = 'b';
        break;
    case 0xc:
        hex = 'c';
        break;
    case 0xd:
        hex = 'd';
        break;
    case 0xe:
        hex = 'e';
        break;
    case 0xf:
        hex = 'f';
        break;
    }
    return hex;
}

void hex_to_str(unsigned long h) {
    if (h > 0xf) {
        hex_to_str(h >> 4);
    }
    register char hex = hex_to_char(h & 0xf);
    buf[buf_len++] = hex;
}

void parse_fmt(char *fmt[], void *arg) {
    switch (**fmt) {
    case 'd':
        *fmt += 1;
        int_to_str(*(int *)arg);
        break;
    case 'x':
        *fmt += 1;
        hex_to_str(*(unsigned long *)arg);
        break;
    case 'c':
        *fmt += 1;
        buf[buf_len++] = *(char *)arg;
        if (*(char *)arg == '\r') {
            buf[buf_len++] = '\n';
        }
        break;
    }
}

void parse_fmt_str(char fmt[], va_list args) {
    while (1) {
        void *next_arg;
        switch (*fmt) {
        case '%':
            next_arg = va_arg_ptr(args);
            fmt++;
            parse_fmt(&fmt, next_arg);
            break;
        case '\0':
            return;
            break;
        case '\n':
            fmt++;
            buf[buf_len++] = '\r';
            buf[buf_len++] = '\n';
            break;
        case '\\':
            fmt++;
        default:
            buf[buf_len++] = *fmt++;
            break;
        }
    }
}

int _printf(va_peding_para, char fmt[], ...) {
    va_list args;
    va_start(args, fmt);

    buf_len = 0;
    parse_fmt_str(fmt, args);
    uart_write(buf, buf_len);

    va_end(args);
    return buf_len;
}
