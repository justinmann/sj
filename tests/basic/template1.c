#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_class_bool();
int32_t sjf_class_f32();
int32_t sjf_class_i32();
int32_t sjf_global();

int32_t sjf_class_bool() {
    int32_t _retVal;
    _retVal = (1);
    return _retVal;
}

int32_t sjf_class_f32() {
    int32_t _retVal;
    _retVal = (1);
    return _retVal;
}

int32_t sjf_class_i32() {
    int32_t _retVal;
    _retVal = (1);
    return _retVal;
}

int32_t sjf_global() {
    int32_t _retVal;
    int32_t a;
    int32_t b;
    int32_t c;
    a = sjf_class_i32();
    b = sjf_class_f32();
    _retVal = (c = sjf_class_bool());
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
