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
#define sjs_class_typeId 2
#define sjs_class_heap_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_class {
    int structsNeedAValue;
};

struct td_sjs_class_heap {
    int _refCount;
};

void sjf_class(sjs_class* _this);
void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_heap(sjs_class_heap* _this);


void sjf_class(sjs_class* _this) {
}

void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t sjt_functionParam1;

    sjt_functionParam1 = x;
    sjf_class_foo(_parent, sjt_functionParam1, &(*_return));
}

void sjf_class_copy(sjs_class* _this, sjs_class* to) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    bool sjt_ifElse1;

    sjt_compare1 = x;
    sjt_compare2 = 0;
    sjt_ifElse1 = sjt_compare1 > sjt_compare2;
    if (sjt_ifElse1) {
        int32_t sjt_functionParam2;
        int32_t sjt_math1;
        int32_t sjt_math2;

        sjt_math1 = x;
        sjt_math2 = 1;
        sjt_functionParam2 = sjt_math1 - sjt_math2;
        sjf_class_bar(_parent, sjt_functionParam2, &(*_return));
    } else {
        (*_return) = 0;
    }
}

void sjf_class_heap(sjs_class_heap* _this) {
}

int main() {
    sjs_class c;
    sjs_class* sjt_dot1;
    int32_t sjt_functionParam3;
    int32_t void1;

    sjf_class(&c);
    sjt_dot1 = &c;
    sjt_functionParam3 = 4;
    sjf_class_foo(sjt_dot1, sjt_functionParam3, &void1);

    sjf_class_destroy(&c);
    return 0;
}
