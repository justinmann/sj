#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_global();

int sjf_global() {
    int x;
    x = 1;
    x = 2;
    return (x) + (1);
}

int main() {
    sjf_global();
    return 0;
}
