#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(void);

void sjf_global(void) {
    int64_t result1;
    int64_t x;

    result1 = (int64_t)1;
    x = result1;
}

int main() {
    sjf_global();

    return 0;
}
