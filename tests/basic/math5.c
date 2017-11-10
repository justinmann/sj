#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct td_sjs_object sjs_object;

int sjs_object_typeId = 1;

struct td_sjs_object {
    int _refCount;
};

void sjf_global(void);

void sjf_global(void) {
    double result1;

    result1 = 4.0 + 5.0;
}

int main() {
    sjf_global();

    return 0;
}
