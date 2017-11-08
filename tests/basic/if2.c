#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(int32_t* _return);

void sjf_global(int32_t* _return) {
    int32_t ifResult1;

    if (false) {
        ifResult1 = 1;
    } else {
        ifResult1 = 2;
    }

    *_return = ifResult1;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
