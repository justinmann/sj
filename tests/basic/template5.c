#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_class_f32_func(int32_t* _return);
void sjf_class_func_i32(int32_t* _return);
void sjf_global(int32_t* _return);

void sjf_class_f32_func(int32_t* _return) {

    *_return = 1;
}

void sjf_class_func_i32(int32_t* _return) {

    *_return = 1;
}

void sjf_global(int32_t* _return) {
    int32_t b;
    int32_t d;
    int32_t result2;
    int32_t result3;

    sjf_class_f32_func(&result2);
    b = result2;
    sjf_class_func_i32(&result3);
    d = result3;

    *_return = result3;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
