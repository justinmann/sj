#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_class_f32_func();
int32_t sjf_class_func_i32();
int32_t sjf_global();

int32_t sjf_class_f32_func() {
    int32_t _retVal;
    _retVal = (1);
    return _retVal;
}

int32_t sjf_class_func_i32() {
    int32_t _retVal;
    _retVal = (1);
    return _retVal;
}

int32_t sjf_global() {
    int32_t _retVal;
    int32_t b;
    int32_t d;
    b = sjf_class_f32_func();
    _retVal = (d = sjf_class_func_i32());
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
