#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_class_func();
int32_t sjf_global();

int32_t sjf_class_func() {
    int32_t _retVal;
    _retVal = (1);
    return _retVal;
}

int32_t sjf_global() {
    int32_t _retVal;
    int32_t d;
    _retVal = (d = sjf_class_func());
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
