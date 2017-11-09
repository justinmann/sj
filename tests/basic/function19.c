#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_func(int32_t x, int32_t* _return);
void sjf_global();

void sjf_func(int32_t x, int32_t* _return) {
    int32_t ifResult1;
    bool result2;

    result2 = x > 0;
    if (result2) {
        int32_t result3;
        int32_t result4;

        result3 = 0;
        result4 = x - 1;
        sjf_func(result4, &result3);
        ifResult1 = result3;
    } else {
        ifResult1 = 0;
    }

    *_return = ifResult1;
}

void sjf_global() {
    int32_t result1;

    result1 = 0;
    sjf_func(4, &result1);
}

int main() {
    sjf_global();

    return 0;
}
