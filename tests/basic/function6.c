#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_func(int32_t x);
int32_t sjf_global();

int32_t sjf_func(int32_t x) {
    int32_t _retVal;
    _retVal = (x);
    return _retVal;
}

int32_t sjf_global() {
    int32_t _retVal;
    _retVal = (sjf_func((2)));
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
