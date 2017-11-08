#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_func(int32_t x, int32_t y, int32_t* _return);
void sjf_global(int32_t* _return);

void sjf_func(int32_t x, int32_t y, int32_t* _return) {
    int32_t result3;

    result3 = x + y;

    *_return = result3;
}

void sjf_global(int32_t* _return) {
    int32_t result2;

    sjf_func(2, 1, &result2);

    *_return = result2;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
