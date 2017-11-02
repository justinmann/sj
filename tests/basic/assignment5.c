#include <stdio.h>
#include <stdlib.h>

int sjf_global();

int sjf_global() {
    int x;
    int y;
    y = 1;
    x = 2;
    return (x) + (y);
}

int main() {
    sjf_global();
    return 0;
}
