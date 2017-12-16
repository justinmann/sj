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

typedef struct td_void_option void_option;
struct td_void_option {
    bool isEmpty;
    void* value;
};
const void_option void_empty = { true };

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
int32_t sjv_a;
uint32_t sjv_b;
uint64_t sjv_c;
int64_t sjv_d;
float sjv_e;
double sjv_f;

void main_destroy(void);

int main(int argc, char** argv) {
#line 1 "math1.sj"
    sjt_math1 = 4;
#line 1
    sjt_math2 = 5;
#line 1
    sjv_a = sjt_math1 + sjt_math2;
#line 2
    sjt_math3 = (uint32_t)4u;
#line 2
    sjt_math4 = (uint32_t)5u;
#line 2
    sjv_b = sjt_math3 + sjt_math4;
#line 3
    sjt_math5 = 4ull;
#line 3
    sjt_math6 = 5ull;
#line 3
    sjv_c = sjt_math5 + sjt_math6;
#line 4
    sjt_math7 = 4ll;
#line 4
    sjt_math8 = 5ll;
#line 4
    sjv_d = sjt_math7 + sjt_math8;
#line 5
    sjt_math9 = 4.0f;
#line 5
    sjt_math10 = 5.0f;
#line 5
    sjv_e = sjt_math9 + sjt_math10;
#line 6
    sjt_math11 = 4.0;
#line 6
    sjt_math12 = 5.0;
#line 6
    sjv_f = sjt_math11 + sjt_math12;
    main_destroy();
    return 0;
}

void main_destroy() {
}
