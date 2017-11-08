#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(double* _return);

void sjf_global(double* _return) {
    double result2;

    result2 = 4.0 + 5.0;

    *_return = result2;
}

int main() {
    double result1;

    sjf_global(&result1);

    return 0;
}
