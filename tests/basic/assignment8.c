#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(int32_t* _return);

void sjf_global(int32_t* _return) {
    int32_t x;
    int32_t y;

    y = 2;
    x = 2;

    *_return = 2;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
