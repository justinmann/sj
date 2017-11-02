#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sjf_global();

void sjf_global() {
    int loopEnd1;
    int x;
    x = 1;
    loopEnd1 = 10;
    while (x <= loopEnd1) {
        x++;
    }
}

int main() {
    sjf_global();
    return 0;
}
