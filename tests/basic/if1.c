#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t ifResult1;
    if (true) {
        ifResult1 = 1;
    } else {
        ifResult1 = 2;
    }
    return ifResult1;
}

int main() {
    sjf_global();
    return 0;
}
