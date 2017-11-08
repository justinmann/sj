#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_class_bool(int32_t* _return);
void sjf_class_f32(int32_t* _return);
void sjf_class_i32(int32_t* _return);
void sjf_global(int32_t* _return);

void sjf_class_bool(int32_t* _return) {

    *_return = 1;
}

void sjf_class_f32(int32_t* _return) {

    *_return = 1;
}

void sjf_class_i32(int32_t* _return) {

    *_return = 1;
}

void sjf_global(int32_t* _return) {
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t result2;
    int32_t result3;
    int32_t result4;

    sjf_class_i32(&result2);
    a = result2;
    sjf_class_f32(&result3);
    b = result3;
    sjf_class_bool(&result4);
    c = result4;

    *_return = result4;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
