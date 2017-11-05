#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void sjf_global();

void sjf_global() {
    bool whileValue1;

    whileValue1 = false;
    while (whileValue1) {
        whileValue1 = false;
    }


}

int main() {
    sjf_global();
    return 0;
}
