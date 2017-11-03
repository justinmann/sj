#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sjf_global();

void sjf_global() {
    int32_t loopEnd1;
    int32_t x;
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
