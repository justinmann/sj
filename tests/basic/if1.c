#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t _retVal;
    int32_t ifResult1;
    if (true) {
        ifResult1 = 1;
    } else {
        ifResult1 = 2;
    }
    _retVal = (ifResult1);
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
