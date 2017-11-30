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
#define sjs_anon1_typeId 2
#define sjs_anon1_heap_typeId 3
#define sjs_class_typeId 4
#define sjs_class_heap_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon1_heap sjs_anon1_heap;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_anon1 {
    int32_t test;
};

struct td_sjs_anon1_heap {
    intptr_t _refCount;
    int32_t test;
};

struct td_sjs_class {
    int structsNeedAValue;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
};

sjs_class* sjt_dot1;
int32_t sjt_functionParam5;
sjs_class sjv_c;
sjs_anon1 sjv_math;
int32_t void1;

void sjf_anon1(sjs_anon1* _this);
void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* to);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_heap(sjs_anon1_heap* _this);
void sjf_anon1_sub(sjs_anon1* _parent, int32_t x, int32_t y, int32_t* _return);
void sjf_class(sjs_class* _this);
void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_heap(sjs_class_heap* _this);
void main_destroy(void);

void sjf_anon1(sjs_anon1* _this) {
}

void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* to) {
    _this->test = to->test;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1_heap* _this) {
}

void sjf_anon1_sub(sjs_anon1* _parent, int32_t x, int32_t y, int32_t* _return) {
    int32_t sjt_math1;
    int32_t sjt_math2;
    int32_t sjt_math3;
    int32_t sjt_math4;

    sjt_math3 = x;
    sjt_math4 = y;
    sjt_math1 = sjt_math3 - sjt_math4;
    sjt_math2 = (_parent)->test;
    (*_return) = sjt_math1 - sjt_math2;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t sjt_functionParam1;

    sjt_functionParam1 = x;
    sjf_class_foo(_parent, sjt_functionParam1, _return);
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
        sjs_anon1* sjt_dot2;
        int32_t sjt_functionParam2;
        int32_t sjt_functionParam3;
        int32_t sjt_functionParam4;

        sjt_dot2 = &sjv_math;
        sjt_functionParam3 = x;
        sjt_functionParam4 = 1;
        sjf_anon1_sub(sjt_dot2, sjt_functionParam3, sjt_functionParam4, &sjt_functionParam2);
        sjf_class_bar(_parent, sjt_functionParam2, _return);
    } else {
        (*_return) = 0;
    }
}

void sjf_class_heap(sjs_class_heap* _this) {
}

int main(int argc, char** argv) {
    sjv_math.test = 1;
    sjf_anon1(&sjv_math);
    sjf_class(&sjv_c);
    sjt_dot1 = &sjv_c;
    sjt_functionParam5 = 4;
    sjf_class_foo(sjt_dot1, sjt_functionParam5, &void1);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_class_destroy(&sjv_c);
    sjf_anon1_destroy(&sjv_math);
}
