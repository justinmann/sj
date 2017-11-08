#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(float* _return);

void sjf_global(float* _return) {
    float result2;

    result2 = (float)5;

    *_return = result2;
}

int main() {
    float result1;

    sjf_global(&result1);

    return 0;
}
