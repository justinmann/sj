#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t _retVal;
    int32_t a;
    a = 0;
    _retVal = (a += 1);
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
