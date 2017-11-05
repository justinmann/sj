#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_func();
int32_t sjf_func_bar();
int32_t sjf_global();

int32_t sjf_func() {
    int32_t result3;

    result3 = sjf_func_bar();


    return result3;
}

int32_t sjf_func_bar() {
    return 9;
}

int32_t sjf_global() {
    int32_t result2;

    result2 = sjf_func();


    return result2;
}

int main() {
    int32_t result1;

    result1 = sjf_global();


    return 0;
}
