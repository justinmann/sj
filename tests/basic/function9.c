#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_func(int x, int y);
int sjf_global();

int sjf_func(int x, int y) {
    return (x) + (y);
}

int sjf_global() {
    return sjf_func((2), (1));
}

int main() {
    sjf_global();
    return 0;
}
