#include <stdio.h>
#include <stdlib.h>

int sjf_global();

int sjf_global() {
    return 9223372036854775807;
}

int main() {
    sjf_global();
    return 0;
}
