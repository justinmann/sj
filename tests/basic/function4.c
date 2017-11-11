#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define sjs_object_typeId 1

typedef struct td_sjs_object sjs_object;

struct td_sjs_object {
    int _refCount;
};

void sjf_func(double* _return);
void sjf_global(void);

void sjf_func(double* _return) {

    *_return = -3.0;
}

void sjf_global(void) {
    double result1;
    bool result2;

    result1 = 0;
    sjf_func(&result1);
    result2 = result1 < 4.0;
}

int main() {
    sjf_global();

    return 0;
}
