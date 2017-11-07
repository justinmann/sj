#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool sjf_global();

bool sjf_global() {

    return false;
}

int main() {
    bool result1;

    result1 = sjf_global();

    return 0;
}
