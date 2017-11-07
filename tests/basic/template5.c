#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t sjf_class_f32_func();
int32_t sjf_class_func_i32();
int32_t sjf_global();

int32_t sjf_class_f32_func() {

    return 1;
}

int32_t sjf_class_func_i32() {

    return 1;
}

int32_t sjf_global() {
    int32_t b;
    int32_t d;
    int32_t result2;
    int32_t result3;

    result2 = sjf_class_f32_func();
    b = result2;
    result3 = sjf_class_func_i32();
    d = result3;

    return result3;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
