#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t sjf_class_func();
int32_t sjf_global();

int32_t sjf_class_func() {

    return 1;
}

int32_t sjf_global() {
    int32_t d;
    int32_t result2;

    result2 = sjf_class_func();
    d = result2;

    return result2;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
