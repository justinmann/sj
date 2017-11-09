#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_func(int32_t x, int32_t* _return);
void sjf_global(void);

void sjf_func(int32_t x, int32_t* _return) {

    *_return = x;
}

void sjf_global(void) {
    int32_t result1;

    result1 = 0;
    sjf_func(3, &result1);
}

int main() {
    sjf_global();

    return 0;
}
