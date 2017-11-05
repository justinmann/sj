#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_func(int32_t x);
int32_t sjf_global();

int32_t sjf_func(int32_t x) {

    return x;
}

int32_t sjf_global() {
    int32_t result2;

    result2 = sjf_func(3);

    return result2;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
