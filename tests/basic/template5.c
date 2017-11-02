#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_class_float_func();
int sjf_class_func_int();
int sjf_global();

int sjf_class_float_func() {
    return 1;
}

int sjf_class_func_int() {
    return 1;
}

int sjf_global() {
    int b;
    int d;
    b = sjf_class_float_func();
    return d = sjf_class_func_int();
}

int main() {
    sjf_global();
    return 0;
}
