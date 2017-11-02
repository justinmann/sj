#include <stdio.h>
#include <stdlib.h>

int sjf_bar();
int sjf_func();

int sjf_bar() {
    return 9;
}

int sjf_func() {
    return sjf_bar();
}

int main() {
    sjf_func();
    return 0;
}
