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

int32_t a;
uint32_t b;
uint64_t c;
int64_t d;
float e;
double f;
int32_t sjt_math1;
float sjt_math10;
double sjt_math11;
double sjt_math12;
int32_t sjt_math2;
uint32_t sjt_math3;
uint32_t sjt_math4;
uint64_t sjt_math5;
uint64_t sjt_math6;
int64_t sjt_math7;
int64_t sjt_math8;
float sjt_math9;

void main_destroy();

int main() {
    sjt_math1 = 4;
    sjt_math2 = 5;
    a = sjt_math1 + sjt_math2;
    sjt_math3 = (uint32_t)4u;
    sjt_math4 = (uint32_t)5u;
    b = sjt_math3 + sjt_math4;
    sjt_math5 = 4ull;
    sjt_math6 = 5ull;
    c = sjt_math5 + sjt_math6;
    sjt_math7 = 4ll;
    sjt_math8 = 5ll;
    d = sjt_math7 + sjt_math8;
    sjt_math9 = 4.0f;
    sjt_math10 = 5.0f;
    e = sjt_math9 + sjt_math10;
    sjt_math11 = 4.0;
    sjt_math12 = 5.0;
    f = sjt_math11 + sjt_math12;
    main_destroy();
    return 0;
}

void main_destroy() {
}
