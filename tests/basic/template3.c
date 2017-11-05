#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_class_bool_f32();
int32_t sjf_class_i32_bool();
int32_t sjf_global();

int32_t sjf_class_bool_f32() {

    return 1;
}

int32_t sjf_class_i32_bool() {

    return 1;
}

int32_t sjf_global() {
    int32_t a;
    int32_t c;
    int32_t result2;
    int32_t result3;

    result2 = sjf_class_i32_bool();
    a = result2;
    result3 = sjf_class_bool_f32();
    c = result3;

    return result3;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
