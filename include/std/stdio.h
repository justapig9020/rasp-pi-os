#ifndef _STDIO_H_
#define _STDIO_H_

#include "stdarg.h"
#define printf(a, ...) _printf(va_peding_arg, a, ##__VA_ARGS__)
#define scanf(a, ...) _scanf(va_peding_arg, a, ##__VA_ARGS__)
int _printf(va_peding_para, char fmt[], ...);
int _scanf(va_peding_para, char fmt[], ...);

#endif
