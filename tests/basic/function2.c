#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_func(int32_t* _return);
void sjf_global(int32_t* _return);

void sjf_func(int32_t* _return) {

    *_return = 1;
}

void sjf_global(int32_t* _return) {
    int32_t result2;

    sjf_func(&result2);

    *_return = result2;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
