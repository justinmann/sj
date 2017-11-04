#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool sjf_global();

bool sjf_global() {
    return true;
}

int main() {
    sjf_global();
    return 0;
}
