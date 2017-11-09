#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global();

void sjf_global() {
    int32_t ifResult1;

    if (false) {
        ifResult1 = 1;
    } else {
        ifResult1 = 2;
    }
}

int main() {
    sjf_global();

    return 0;
}
