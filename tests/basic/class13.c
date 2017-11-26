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
#define sjs_math_typeId 2
#define sjs_math_heap_typeId 3
#define sjs_class_typeId 4
#define sjs_class_heap_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_math sjs_math;
typedef struct td_sjs_math_heap sjs_math_heap;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_math {
    int structsNeedAValue;
};

struct td_sjs_math_heap {
    int _refCount;
};

struct td_sjs_class {
    sjs_math m;
};

struct td_sjs_class_heap {
    int _refCount;
    sjs_math m;
};

sjs_class c;
sjs_class* sjt_dot1;
int32_t sjt_functionParam5;
int32_t void1;

void sjf_class(sjs_class* _this);
void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_math(sjs_math* _this);
void sjf_math_copy(sjs_math* _this, sjs_math* to);
void sjf_math_destroy(sjs_math* _this);
void sjf_math_heap(sjs_math_heap* _this);
void sjf_math_sub(sjs_math* _parent, int32_t x, int32_t y, int32_t* _return);
void main_destroy();

void sjf_class(sjs_class* _this) {
}

void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t sjt_functionParam1;

    sjt_functionParam1 = x;
    sjf_class_foo(_parent, sjt_functionParam1, &(*_return));
}

void sjf_class_copy(sjs_class* _this, sjs_class* to) {
    sjf_math_copy(&_this->m, &to->m);
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
        sjs_math dotTemp1;
        sjs_math* sjt_dot2;
        int32_t sjt_functionParam2;
        int32_t sjt_functionParam3;
        int32_t sjt_functionParam4;

        dotTemp1 = _parent->m;
        sjt_dot2 = &dotTemp1;
        sjt_functionParam3 = x;
        sjt_functionParam4 = 1;
        sjf_math_sub(sjt_dot2, sjt_functionParam3, sjt_functionParam4, &sjt_functionParam2);
        sjf_class_bar(_parent, sjt_functionParam2, &(*_return));

        sjf_math_destroy(&dotTemp1);
    } else {
        (*_return) = 0;
    }
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_math(sjs_math* _this) {
}

void sjf_math_copy(sjs_math* _this, sjs_math* to) {
}

void sjf_math_destroy(sjs_math* _this) {
}

void sjf_math_heap(sjs_math_heap* _this) {
}

void sjf_math_sub(sjs_math* _parent, int32_t x, int32_t y, int32_t* _return) {
    int32_t sjt_math1;
    int32_t sjt_math2;

    sjt_math1 = x;
    sjt_math2 = y;
    (*_return) = sjt_math1 - sjt_math2;
}

int main() {
    sjf_math(&c.m);
    sjf_class(&c);
    sjt_dot1 = &c;
    sjt_functionParam5 = 4;
    sjf_class_foo(sjt_dot1, sjt_functionParam5, &void1);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_class_destroy(&c);
}
