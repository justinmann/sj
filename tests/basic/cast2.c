#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(void);

void sjf_global(void) {
    int64_t result1;

    result1 = (int64_t)5.0;
}

int main() {
    sjf_global();

    return 0;
}
