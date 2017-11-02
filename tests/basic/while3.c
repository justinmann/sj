#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_global();

int sjf_global() {
    int x;
    x = 10;
    while ((x) > (0)) {
        x = (x) - (1);
    }
    return x;
}

int main() {
    sjf_global();
    return 0;
}
