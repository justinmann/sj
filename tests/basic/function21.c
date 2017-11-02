#include <stdio.h>
#include <stdlib.h>

int sjf_func();
int sjf_func_bar();

int sjf_func() {
    return sjf_func_bar();
}

int sjf_func_bar() {
    return 9;
}

int main() {
    sjf_func();
    return 0;
}
