#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define sjs_object_typeId 1

typedef struct td_sjs_object sjs_object;

struct td_sjs_object {
    int _refCount;
};

void sjf_global(void);

void sjf_global(void) {
    int32_t a;
    int32_t result1;

    a = 0;
    result1 = a + 1;
    a = result1;
}

int main() {
    sjf_global();

    return 0;
}
