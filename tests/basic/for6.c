#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sjf_global();

int sjf_global() {
    int loopEnd1;
    int x;
    int y;
    y = 0;
    x = 2;
    loopEnd1 = 1;
    while (x <= loopEnd1) {
        y = (y) + (x);
        x++;
    }
    return y;
}

int main() {
    sjf_global();
    return 0;
}
