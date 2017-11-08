#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_func(double* _return);
void sjf_global(bool* _return);

void sjf_func(double* _return) {

    *_return = -3.0;
}

void sjf_global(bool* _return) {
    double result2;
    bool result3;

    sjf_func(&result2);
    result3 = result2 < 4.0;

    *_return = result3;
}

int main() {
    bool result1;

    sjf_global(&result1);

    return 0;
}
