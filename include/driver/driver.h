#ifndef _DRIVER_H_
#define _DRIVER_H_

struct driver {
    int open(char*, int);
    int read(int, void*, unsigned int);
    int write(int, void*, unsigned int);
    int close(int);
};

#endif
