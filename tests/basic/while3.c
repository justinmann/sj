#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_global();

int32_t sjf_global() {
    bool result2;
    bool result4;
    bool whileValue1;
    int32_t x;

    x = 10;
    result2 = x > 0;
    whileValue1 = result2;
    result4 = x > 0;
    while (whileValue1) {
        int32_t result3;

        result3 = x - 1;
        x = result3;
        whileValue1 = result4;
    }

    return x;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
