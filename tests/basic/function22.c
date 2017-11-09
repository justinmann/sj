#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sjf_foo(void);
void sjf_global(void);

void sjf_foo(void) {
}

void sjf_global(void) {
    sjf_foo();
}

int main() {
    sjf_global();

    return 0;
}
