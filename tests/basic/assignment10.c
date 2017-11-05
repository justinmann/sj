#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t a;
    int32_t result2;

    a = 0;
    result2 = a + 1;
    a = result2;


    return result2;
}

int main() {
    int32_t result1;

    result1 = sjf_global();


    return 0;
}
