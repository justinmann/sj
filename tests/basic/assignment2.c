#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(int64_t* _return);

void sjf_global(int64_t* _return) {
    int64_t result2;
    int64_t x;

    result2 = (int64_t)1;
    x = result2;

    *_return = result2;
}

int main() {
    int64_t result1;

    sjf_global(&result1);

    return 0;
}
