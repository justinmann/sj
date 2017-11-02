#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float sjf_global();

float sjf_global() {
    return (float)(5);
}

int main() {
    sjf_global();
    return 0;
}
