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
    int32_t ifResult1;

    if (false) {
        ifResult1 = 1;
    } else {
        ifResult1 = (int32_t)0;
    }
}

int main() {
    sjf_global();

    return 0;
}
