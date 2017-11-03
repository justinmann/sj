#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int32_t sjf_func(int32_t x);
int32_t sjf_global();

int32_t sjf_func(int32_t x) {
    return x;
}

int32_t sjf_global() {
    return sjf_func((3));
}

int main() {
    sjf_global();
    return 0;
}
