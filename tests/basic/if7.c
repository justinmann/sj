#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global();

void sjf_global() {
    double ifResult1;

    if (false) {
        ifResult1 = 1;
    } else {
        ifResult1 = 1.0;
    }
}

int main() {
    sjf_global();

    return 0;
}
