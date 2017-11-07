#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t sjf_func(int32_t x);
int32_t sjf_global();

int32_t sjf_func(int32_t x) {
    int32_t ifResult1;
    bool result3;

    result3 = x > 0;
    if (result3) {
        int32_t result4;
        int32_t result5;

        result5 = x - 1;
        result4 = sjf_func(result5);
        ifResult1 = result4;
    } else {
        ifResult1 = 0;
    }

    return ifResult1;
}

int32_t sjf_global() {
    int32_t result2;

    result2 = sjf_func(4);

    return result2;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
