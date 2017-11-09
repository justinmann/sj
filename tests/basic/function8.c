#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_func(int32_t x, int32_t y, int32_t* _return);
void sjf_global();

void sjf_func(int32_t x, int32_t y, int32_t* _return) {
    int32_t result2;

    result2 = x + y;

    *_return = result2;
}

void sjf_global() {
    int32_t result1;

    result1 = 0;
    sjf_func(1, 1, &result1);
}

int main() {
    sjf_global();

    return 0;
}
