#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_class_bool_float();
int sjf_class_int_bool();
int sjf_global();

int sjf_class_bool_float() {
    return 1;
}

int sjf_class_int_bool() {
    return 1;
}

int sjf_global() {
    int a;
    int c;
    a = sjf_class_int_bool();
    return c = sjf_class_bool_float();
}

int main() {
    sjf_global();
    return 0;
}
