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
    uint32_t b;
    uint64_t c;
    int64_t d;
    float e;
    double f;
    int32_t result1;
    uint32_t result2;
    uint64_t result3;
    int64_t result4;
    float result5;
    double result6;

    result1 = 4 + 5;
    a = result1;
    result2 = (uint32_t)4u + (uint32_t)5u;
    b = result2;
    result3 = 4ull + 5ull;
    c = result3;
    result4 = 4ll + 5ll;
    d = result4;
    result5 = 4.0f + 5.0f;
    e = result5;
    result6 = 4.0 + 5.0;
    f = result6;
}

int main() {
    sjf_global();

    return 0;
}
