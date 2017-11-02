#include <stdio.h>
#include <stdlib.h>

int sjf_func(int x, int y);

int sjf_func(int x, int y) {
    return (x) + (y);
}

int main() {
    sjf_func((1), (1));
    return 0;
}
