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
    int32_t result1;
    int32_t x;
    int32_t y;

    y = 1;
    x = 2;
    result1 = x + y;
}

int main() {
    sjf_global();

    return 0;
}
