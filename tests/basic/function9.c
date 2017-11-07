#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t sjf_func(int32_t x, int32_t y);
int32_t sjf_global();

int32_t sjf_func(int32_t x, int32_t y) {
    int32_t result3;

    result3 = x + y;

    return result3;
}

int32_t sjf_global() {
    int32_t result2;

    result2 = sjf_func(2, 1);

    return result2;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
