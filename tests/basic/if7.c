#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

double sjf_global();

double sjf_global() {
    double _retVal;
    double ifResult1;
    if (false) {
        ifResult1 = 1;
    } else {
        ifResult1 = 1.0;
    }
    _retVal = (ifResult1);
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
