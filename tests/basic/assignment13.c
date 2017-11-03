#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int32_t sjf_global();

int32_t sjf_global() {
    int32_t a;
    a = 0;
    return a += 1;
}

int main() {
    sjf_global();
    return 0;
}
