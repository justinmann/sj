#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_class_bool();
int sjf_class_float();
int sjf_class_int();
int sjf_global();

int sjf_class_bool() {
    return 1;
}

int sjf_class_float() {
    return 1;
}

int sjf_class_int() {
    return 1;
}

int sjf_global() {
    int a;
    int b;
    int c;
    a = sjf_class_int();
    b = sjf_class_float();
    return c = sjf_class_bool();
}

int main() {
    sjf_global();
    return 0;
}
