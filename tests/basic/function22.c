#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_object sjs_object;

int sjs_object_typeId = 1;

struct td_sjs_object {
    int _refCount;
};

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
