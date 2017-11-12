#include <stdbool.h>
#include <stdint.h>
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

void sjf_class_bool_f32(int32_t* _return);
void sjf_class_i32_bool(int32_t* _return);
void sjf_global(void);

void sjf_class_bool_f32(int32_t* _return) {

    *_return = 1;
}

void sjf_class_i32_bool(int32_t* _return) {

    *_return = 1;
}

void sjf_global(void) {
    int32_t a;
    int32_t c;
    int32_t result1;
    int32_t result2;

    result1 = 0;
    sjf_class_i32_bool(&result1);
    a = result1;
    result2 = 0;
    sjf_class_bool_f32(&result2);
    c = result2;
}

int main() {
    sjf_global();

    return 0;
}
