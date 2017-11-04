#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_bar();
int32_t sjf_func();
int32_t sjf_global();

int32_t sjf_bar() {
    int32_t _retVal;
    _retVal = (9);
    return _retVal;
}

int32_t sjf_func() {
    int32_t _retVal;
    _retVal = (sjf_bar());
    return _retVal;
}

int32_t sjf_global() {
    int32_t _retVal;
    _retVal = (sjf_func());
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
