#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_global(bool* _return);

void sjf_global(bool* _return) {
    bool result2;

    result2 = -3 == 4;

    *_return = result2;
}

int main() {
    bool result1;

    sjf_global(&result1);

    return 0;
}
