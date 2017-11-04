#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t _retVal;
    int32_t x;
    _retVal = (x = 1);
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
