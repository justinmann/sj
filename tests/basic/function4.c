#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

double sjf_func();
bool sjf_global();

double sjf_func() {

    return -3.0;
}

bool sjf_global() {
    double result2;
    bool result3;

    result2 = sjf_func();
    result3 = result2 < 4.0;

    return result3;
}

int main() {
    bool result1;

    result1 = sjf_global();

    return 0;
}
