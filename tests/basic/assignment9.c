#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_global();

int sjf_global() {
    int x;
    int y;
    x = y = 2;
    return (x) + (y);
}

int main() {
    sjf_global();
    return 0;
}
