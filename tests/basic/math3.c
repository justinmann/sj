#include <stdio.h>
#include <stdlib.h>

int sjf_global();

int sjf_global() {
    return 92233720368547758070;
}

int main() {
    sjf_global();
    return 0;
}
