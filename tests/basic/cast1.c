#include <stdio.h>
#include <stdlib.h>

float sjf_global();

float sjf_global() {
    return (float)(5);
}

int main() {
    sjf_global();
    return 0;
}
