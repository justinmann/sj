#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

double sjf_global();

double sjf_global() {
    double ifResult1;

    if (false) {
        ifResult1 = 1;
    } else {
        ifResult1 = 1.0;
    }

    return ifResult1;
}

int main() {
    double result1;

    result1 = sjf_global();

    return 0;
}
