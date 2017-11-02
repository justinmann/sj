#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_class_func();
int sjf_global();

int sjf_class_func() {
    return 1;
}

int sjf_global() {
    int d;
    return d = sjf_class_func();
}

int main() {
    sjf_global();
    return 0;
}
