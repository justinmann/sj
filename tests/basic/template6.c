#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_class_func_i32();
int32_t sjf_global();

int32_t sjf_class_func_i32() {
    return 1;
}

int32_t sjf_global() {
    int32_t d;
    int32_t result2;

    result2 = sjf_class_func_i32();
    d = result2;


    return result2;
}

int main() {
    int32_t result1;

    result1 = sjf_global();


    return 0;
}
