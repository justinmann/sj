#include <stdio.h>
#include <stdlib.h>

int sjf_global();

int sjf_global() {
    int ifResult1;
    if (false) {
        ifResult1 = 1;
    } else {
        ifResult1 = 2;
    }
    return ifResult1;
}

int main() {
    sjf_global();
    return 0;
}
