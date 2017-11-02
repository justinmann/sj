#include <stdio.h>
#include <stdlib.h>

int sjf_global();

int sjf_global() {
    int x;
    int y;
    return x = y = 2;
}

int main() {
    sjf_global();
    return 0;
}
