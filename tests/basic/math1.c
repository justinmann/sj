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
    int _refCount;
};



int main() {
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
    return 0;
}
