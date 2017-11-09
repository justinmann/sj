#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(void);

void sjf_global(void) {
    bool whileValue1;

    whileValue1 = false;
    while (whileValue1) {
        whileValue1 = false;
    }
}

int main() {
    sjf_global();

    return 0;
}
