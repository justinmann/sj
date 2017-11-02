#include <stdio.h>
#include <stdlib.h>

int sjf_bar();
int sjf_func();
int sjf_global();

int sjf_bar() {
    return 9;
}

int sjf_func() {
    return sjf_bar();
}

int sjf_global() {
    return sjf_func();
}

int main() {
    sjf_global();
    return 0;
}
