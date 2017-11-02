#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_func();
int sjf_global();

int sjf_func() {
    return 1;
}

int sjf_global() {
    return sjf_func();
}

int main() {
    sjf_global();
    return 0;
}
