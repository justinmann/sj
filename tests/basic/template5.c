#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    b = sjf_class_f32_func();
    return d = sjf_class_func_i32();
}

int main() {
    sjf_global();
    return 0;
}
