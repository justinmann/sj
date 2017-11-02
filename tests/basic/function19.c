#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_func(int x);
int sjf_global();

int sjf_func(int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_func(((x) - (1)));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int sjf_global() {
    return sjf_func((4));
}

int main() {
    sjf_global();
    return 0;
}
