#include <stdio.h>
#include <stdlib.h>

void sjf_foo();
void sjf_global();

void sjf_foo() {
}

void sjf_global() {
    return sjf_foo();
}

int main() {
    sjf_global();
    return 0;
}
