#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool sjf_global();

bool sjf_global() {
    bool result2;

    result2 = -3.0 > 4.0;

    return result2;
}

int main() {
    bool result1;

    result1 = sjf_global();

    return 0;
}
