#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t x;
    int32_t y;
    x = y = 2;
    return (x) + (y);
}

int main() {
    sjf_global();
    return 0;
}
