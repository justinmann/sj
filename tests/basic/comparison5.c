#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool sjf_global();

bool sjf_global() {
    bool _retVal;
    _retVal = ((-3) <= (4));
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
