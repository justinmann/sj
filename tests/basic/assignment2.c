#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t sjf_global();

int64_t sjf_global() {
    int64_t result2;
    int64_t x;
    result2 = (int64_t)1;
    x = result2;
    return result2;
}

int main() {
    int64_t result1;
    result1 = sjf_global();
    return 0;
}
