#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t _retVal;
    int32_t x;
    int32_t y;
    y = 1;
    x = 2;
    _retVal = ((x) + (y));
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
