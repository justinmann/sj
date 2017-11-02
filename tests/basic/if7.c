#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float sjf_global();

float sjf_global() {
    float ifResult1;
    if (false) {
        ifResult1 = 1;
    } else {
        ifResult1 = 1.0;
    }
    return ifResult1;
}

int main() {
    sjf_global();
    return 0;
}
