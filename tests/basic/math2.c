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
    int64_t a;
    int64_t b;
    int64_t c;
    int32_t d;
    int32_t e;
    uint32_t f;
    uint64_t g;

    a = (-9223372036854775807ll - 1ll);
    b = -9223372036854775807ll;
    c = 9223372036854775807ll;
    d = -2147483648;
    e = 2147483647;
    f = (uint32_t)4294967295u;
    g = 18446744073709551615ull;
}

int main() {
    sjf_global();

    return 0;
}
