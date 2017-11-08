#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(int32_t* _return);

void sjf_global(int32_t* _return) {
    int32_t loopEnd1;
    int32_t x;
    int32_t y;

    y = 0;
    x = 2;
    loopEnd1 = 1;
    while (x <= loopEnd1) {
        int32_t result2;

        result2 = y + x;
        y = result2;
        x++;
    }

    *_return = y;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
