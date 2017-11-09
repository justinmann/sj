#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global();

void sjf_global() {
    bool result1;
    bool whileValue1;
    int32_t x;

    x = 10;
    result1 = x > 0;
    whileValue1 = result1;
    while (whileValue1) {
        int32_t result2;
        bool result3;

        result2 = x - 1;
        x = result2;
        result3 = x > 0;
        whileValue1 = result3;
    }
}

int main() {
    sjf_global();

    return 0;
}
