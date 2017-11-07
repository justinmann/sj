#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t ifResult1;

    if (false) {
        ifResult1 = 1;
    } else {
        ifResult1 = (int32_t)0;
    }

    return ifResult1;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
