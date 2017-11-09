#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global();

void sjf_global() {
    int32_t result1;

    result1 = -4 + 5;
}

int main() {
    sjf_global();

    return 0;
}
