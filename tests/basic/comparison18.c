#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(void);

void sjf_global(void) {
    bool result1;

    result1 = -3.0 != 4.0;
}

int main() {
    sjf_global();

    return 0;
}
