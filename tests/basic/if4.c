#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_global();

int sjf_global() {
    int ifResult1;
    if (false) {
        ifResult1 = 1;
    } else {
        int ifResult2;
        if (true) {
            ifResult2 = 2;
        }
        ifResult1 = ifResult2;
    }
    return ifResult1;
}

int main() {
    sjf_global();
    return 0;
}
