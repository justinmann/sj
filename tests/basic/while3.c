#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t _retVal;
    int32_t x;
    x = 10;
    while ((x) > (0)) {
        x = (x) - (1);
    }
    _retVal = (x);
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
