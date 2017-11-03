#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t x;
    int32_t y;
    return x = y = 2;
}

int main() {
    sjf_global();
    return 0;
}
