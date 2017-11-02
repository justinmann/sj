#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_func();
int sjf_func_bar();
int sjf_global();

int sjf_func() {
    return sjf_func_bar();
}

int sjf_func_bar() {
    return 9;
}

int sjf_global() {
    return sjf_func();
}

int main() {
    sjf_global();
    return 0;
}
