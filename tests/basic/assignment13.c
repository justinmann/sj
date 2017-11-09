#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(void);

void sjf_global(void) {
    int32_t a;
    int32_t result1;

    a = 0;
    result1 = a + 1;
    a = result1;
}

int main() {
    sjf_global();

    return 0;
}
