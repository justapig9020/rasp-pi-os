#ifndef _STDARG_H_
#define _STDARG_H_

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned long *va_list;
#define va_start(ptr, base) (ptr = ((va_list)&base) + 1)
#define va_arg(ptr, type) (*(type *)ptr++)
#define va_arg_ptr(ptr) ((void *)ptr++)
#define va_end(ptr) (ptr = NULL)
#define va_peding_para                                                         \
    int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7
#define va_peding_arg 0, 1, 2, 3, 4, 5, 6, 7

#endif
