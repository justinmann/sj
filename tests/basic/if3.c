#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(void);

void sjf_global(void) {
    int32_t ifResult1;

    if (false) {
        ifResult1 = 1;
    } else {
        ifResult1 = (int32_t)0;
    }
}

int main() {
    sjf_global();

    return 0;
}
