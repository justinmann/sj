#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

double sjf_func();
bool sjf_global();

double sjf_func() {
    return -3.0;
}

bool sjf_global() {
    return (sjf_func()) < (4.0);
}

int main() {
    sjf_global();
    return 0;
}
