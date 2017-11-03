#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    a = sjf_class_i32();
    b = sjf_class_f32();
    return c = sjf_class_bool();
}

int main() {
    sjf_global();
    return 0;
}
