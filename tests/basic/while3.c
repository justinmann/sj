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
    bool result1;
    bool whileValue1;
    int32_t x;

    x = 10;
    result1 = x > 0;
    whileValue1 = result1;
    while (whileValue1) {
        int32_t result2;
        bool result3;

        result2 = x - 1;
        x = result2;
        result3 = x > 0;
        whileValue1 = result3;
    }
}

int main() {
    sjf_global();

    return 0;
}
