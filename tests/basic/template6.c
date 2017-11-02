#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_class_func_int();
int sjf_global();

int sjf_class_func_int() {
    return 1;
}

int sjf_global() {
    int d;
    return d = sjf_class_func_int();
}

int main() {
    sjf_global();
    return 0;
}
