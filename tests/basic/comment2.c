#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_global();

int sjf_global() {
    return 1;
}

int main() {
    sjf_global();
    return 0;
}
