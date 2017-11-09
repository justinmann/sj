#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global();

void sjf_global() {
    float result1;

    result1 = (float)5;
}

int main() {
    sjf_global();

    return 0;
}
