#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t loopEnd1;
    int32_t x;
    int32_t y;
    y = 0;
    x = 2;
    loopEnd1 = 4;
    while (x <= loopEnd1) {
        y = (y) + (x);
        x++;
    }
    return y;
}

int main() {
    sjf_global();
    return 0;
}
