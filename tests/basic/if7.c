#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(double* _return);

void sjf_global(double* _return) {
    double ifResult1;

    if (false) {
        ifResult1 = 1;
    } else {
        ifResult1 = 1.0;
    }

    *_return = ifResult1;
}

int main() {
    double result1;

    sjf_global(&result1);

    return 0;
}
