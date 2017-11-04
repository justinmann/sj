#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

double sjf_func();
bool sjf_global();

double sjf_func() {
    double _retVal;
    _retVal = (-3.0);
    return _retVal;
}

bool sjf_global() {
    bool _retVal;
    _retVal = ((sjf_func()) < (4.0));
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
