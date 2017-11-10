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

void sjf_func(int32_t* _return);
void sjf_func_bar(int32_t* _return);
void sjf_global(void);

void sjf_func(int32_t* _return) {
    int32_t result2;

    result2 = 0;
    sjf_func_bar(&result2);

    *_return = result2;
}

void sjf_func_bar(int32_t* _return) {

    *_return = 9;
}

void sjf_global(void) {
    int32_t result1;

    result1 = 0;
    sjf_func(&result1);
}

int main() {
    sjf_global();

    return 0;
}
