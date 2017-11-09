#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_func(double* _return);
void sjf_global();

void sjf_func(double* _return) {

    *_return = -3.0;
}

void sjf_global() {
    double result1;
    bool result2;

    result1 = 0;
    sjf_func(&result1);
    result2 = result1 < 4.0;
}

int main() {
    sjf_global();

    return 0;
}
