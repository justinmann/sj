#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char sjf_global();

char sjf_global() {
    char c;
    char d;
    char e;

    c = 'a';
    d = '\'';
    e = '\n';

    return '\n';
}

int main() {
    char result1;

    result1 = sjf_global();

    return 0;
}
