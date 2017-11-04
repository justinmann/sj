#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t x;
    x = 1;
    return (x) + (1);
}

int main() {
    sjf_global();
    return 0;
}
