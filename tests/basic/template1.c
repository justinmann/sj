#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_class_bool();
int32_t sjf_class_f32();
int32_t sjf_class_i32();
int32_t sjf_global();

int32_t sjf_class_bool() {

    return 1;
}

int32_t sjf_class_f32() {

    return 1;
}

int32_t sjf_class_i32() {

    return 1;
}

int32_t sjf_global() {
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t result2;
    int32_t result3;
    int32_t result4;

    result2 = sjf_class_i32();
    a = result2;
    result3 = sjf_class_f32();
    b = result3;
    result4 = sjf_class_bool();
    c = result4;

    return result4;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
