#include "std/stdio.h"
#include "peripherals/uart.h"
#define BUF_SIZE 1024

static char o_buf[BUF_SIZE];
static unsigned int buf_len;

int abs(int n) {
    return (n ^ (n >> 31)) - (n >> 31);
} // TEMP, should be place into some math relative library

static int _int_to_str(int n, char buf[]) {
    static int len;
    len = 0;
    if (n > 10) {
        _int_to_str(n / 10, buf);
    }
    register int digit = n % 10;
    buf[len++] = digit + '0';
    return len;
}

int int_to_str(int n, char buf[]) {
    int neg = 0;
    if (n < 0) {
        n = abs(n);
        *buf = '-';
        neg = 1;
    }
    return _int_to_str(n, buf + neg) + neg;
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

int hex_to_str(unsigned long h, char buf[]) {
    static int len;
    len = 0;
    if (h > 0xf) {
        hex_to_str(h >> 4, buf);
    }
    register char hex = hex_to_char(h & 0xf);
    buf[len++] = hex;
    return len;
}

static void parse_fmt(char *fmt[], void *arg) {
    switch (**fmt) {
    case 'd':
        *fmt += 1;
        buf_len += int_to_str(*(int *)arg, o_buf + buf_len);
        break;
    case 'x':
        *fmt += 1;
        buf_len += hex_to_str(*(unsigned long *)arg, o_buf + buf_len);
        break;
    case 'c':
        *fmt += 1;
        o_buf[buf_len++] = *(char *)arg;
        if (*(char *)arg == '\r') {
            o_buf[buf_len++] = '\n';
        }
        break;
    }
}

static void parse_fmt_str(char fmt[], va_list args) {
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
            o_buf[buf_len++] = '\r';
            o_buf[buf_len++] = '\n';
            break;
        case '\\':
            fmt++;
        default:
            o_buf[buf_len++] = *fmt++;
            break;
        }
    }
}

int _printf(va_peding_para, char fmt[], ...) {
    va_list args;
    va_start(args, fmt);

    buf_len = 0;
    parse_fmt_str(fmt, args);
    uart_write(o_buf, buf_len);

    va_end(args);
    return buf_len;
}
