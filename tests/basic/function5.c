#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_func(int x);
int sjf_global();

int sjf_func(int x) {
    return x;
}

int sjf_global() {
    return sjf_func((1));
}

int main() {
    sjf_global();
    return 0;
}
