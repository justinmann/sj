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
    int64_t result1;
    int64_t x;

    result1 = (int64_t)1;
    x = result1;
}

int main() {
    sjf_global();

    return 0;
}
