#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_class_bool_f32();
int32_t sjf_class_i32_bool();
int32_t sjf_global();

int32_t sjf_class_bool_f32() {
    int32_t _retVal;
    _retVal = (1);
    return _retVal;
}

int32_t sjf_class_i32_bool() {
    int32_t _retVal;
    _retVal = (1);
    return _retVal;
}

int32_t sjf_global() {
    int32_t _retVal;
    int32_t a;
    int32_t c;
    a = sjf_class_i32_bool();
    _retVal = (c = sjf_class_bool_f32());
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
