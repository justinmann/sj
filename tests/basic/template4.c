#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int32_t sjf_class_func();
int32_t sjf_global();

int32_t sjf_class_func() {
    return 1;
}

int32_t sjf_global() {
    int32_t d;
    return d = sjf_class_func();
}

int main() {
    sjf_global();
    return 0;
}
