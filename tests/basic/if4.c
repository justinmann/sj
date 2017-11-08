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
        int32_t ifResult2;

        if (true) {
            ifResult2 = 2;
        } else {
            ifResult2 = (int32_t)0;
        }

        ifResult1 = ifResult2;
    }

    *_return = ifResult1;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
