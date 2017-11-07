#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool sjf_global();

bool sjf_global() {
    bool result2;

    result2 = -3 == 4;

    return result2;
}

int main() {
    bool result1;

    result1 = sjf_global();

    return 0;
}
