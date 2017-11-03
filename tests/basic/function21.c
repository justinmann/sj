#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int32_t sjf_func();
int32_t sjf_func_bar();
int32_t sjf_global();

int32_t sjf_func() {
    return sjf_func_bar();
}

int32_t sjf_func_bar() {
    return 9;
}

int32_t sjf_global() {
    return sjf_func();
}

int main() {
    sjf_global();
    return 0;
}
