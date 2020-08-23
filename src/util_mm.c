#include "util/mm.h"

void bzero(char *src, unsigned int len) {
    for (int i = 0; i < len; i++) {
        *(src++) = 0;
    }
}
