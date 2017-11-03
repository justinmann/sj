#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t x;
    x = 1;
    x = 2;
    return (x) + (1);
}

int main() {
    sjf_global();
    return 0;
}
