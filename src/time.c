#include "time.h"
void delay(register unsigned int n) {
    while (n) {
        n--;
    }
}
