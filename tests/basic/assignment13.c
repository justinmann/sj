#include <stdio.h>
#include <stdlib.h>

int sjf_global();

int sjf_global() {
    int a;
    a = 0;
    return a += 1;
}

int main() {
    sjf_global();
    return 0;
}
