#include <stdio.h>
#include <stdlib.h>

float sjf_func(float x);
float sjf_global();

float sjf_func(float x) {
    return x;
}

float sjf_global() {
    return sjf_func((1.0));
}

int main() {
    sjf_global();
    return 0;
}
