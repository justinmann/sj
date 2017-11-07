#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float sjf_global();

float sjf_global() {
    float result2;

    result2 = (float)5;

    return result2;
}

int main() {
    float result1;

    result1 = sjf_global();

    return 0;
}
