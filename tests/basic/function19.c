#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_func(int32_t x, int32_t* _return);
void sjf_global(int32_t* _return);

void sjf_func(int32_t x, int32_t* _return) {
    int32_t ifResult1;
    bool result3;

    result3 = x > 0;
    if (result3) {
        int32_t result4;
        int32_t result5;

        result5 = x - 1;
        sjf_func(result5, &result4);
        ifResult1 = result4;
    } else {
        ifResult1 = 0;
    }

    *_return = ifResult1;
}

void sjf_global(int32_t* _return) {
    int32_t result2;

    sjf_func(4, &result2);

    *_return = result2;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
