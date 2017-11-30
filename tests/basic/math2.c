#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isEmpty;
    int32_t value;
};
const int32_option int32_empty = { true };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isEmpty;
    uint32_t value;
};
const uint32_option uint32_empty = { true };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isEmpty;
    int64_t value;
};
const int64_option int64_empty = { true };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isEmpty;
    uint64_t value;
};
const uint64_option uint64_empty = { true };

typedef struct td_uintptr_option uintptr_option;
struct td_uintptr_option {
    bool isEmpty;
    uintptr_t value;
};
const uintptr_option uintptr_empty = { true };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isEmpty;
    char value;
};
const char_option char_empty = { true };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isEmpty;
    float value;
};
const float_option float_empty = { true };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isEmpty;
    double value;
};
const double_option double_empty = { true };

#define sjs_object_typeId 1

typedef struct td_sjs_object sjs_object;

struct td_sjs_object {
    intptr_t _refCount;
};

int64_t sjv_a;
int64_t sjv_b;
int64_t sjv_c;
int32_t sjv_d;
int32_t sjv_e;
uint32_t sjv_f;
uint64_t sjv_g;

void main_destroy(void);

int main(int argc, char** argv) {
    sjv_a = (-9223372036854775807ll - 1ll);
    sjv_b = -9223372036854775807ll;
    sjv_c = 9223372036854775807ll;
    sjv_d = (-2147483647 - 1);
    sjv_e = 2147483647;
    sjv_f = (uint32_t)4294967295u;
    sjv_g = 18446744073709551615ull;
    main_destroy();
    return 0;
}

void main_destroy() {
}
