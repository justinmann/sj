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
    int32_t ifResult1;

    if (false) {
        ifResult1 = 1;
    } else {
        int32_t ifResult2;

        if (true) {
            ifResult2 = 2;
        } else {
            ifResult2 = (int32_t)0;
        }

        ifResult1 = ifResult2;
    }
}

int main() {
    sjf_global();

    return 0;
}
