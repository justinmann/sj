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
    intptr_t _refCount;
};

struct td_sjs_math {
    int structsNeedAValue;
};

struct td_sjs_math_heap {
    intptr_t _refCount;
};

struct td_sjs_class {
    sjs_math m;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
    sjs_math m;
};

int32_t sjt_functionParam5;
sjs_class* sjt_parent2;
sjs_class sjv_c;
int32_t void1;

void sjf_class(sjs_class* _this);
void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_math(sjs_math* _this);
void sjf_math_copy(sjs_math* _this, sjs_math* _from);
void sjf_math_destroy(sjs_math* _this);
void sjf_math_heap(sjs_math_heap* _this);
void sjf_math_sub(sjs_math* _parent, int32_t x, int32_t y, int32_t* _return);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t sjt_functionParam1;

#line 15 ".\basic\class13.sj"
    sjt_functionParam1 = x;
#line 0 ""
    sjf_class_foo(_parent, sjt_functionParam1, _return);
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 6 ".\basic\class13.sj"
    sjf_math_copy(&_this->m, &_from->m);
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    bool sjt_ifElse1;

#line 8 ".\basic\class13.sj"
    sjt_compare1 = x;
#line 9
    sjt_compare2 = 0;
#line 9
    sjt_ifElse1 = sjt_compare1 > sjt_compare2;
    if (sjt_ifElse1) {
        sjs_class* sjt_dot1;
        int32_t sjt_functionParam2;
        int32_t sjt_functionParam3;
        int32_t sjt_functionParam4;
        sjs_math* sjt_parent1;

#line 8 ".\basic\class13.sj"
        sjt_dot1 = _parent;
#line 2
        sjt_parent1 = &(sjt_dot1)->m;
#line 8
        sjt_functionParam3 = x;
#line 10
        sjt_functionParam4 = 1;
#line 0 ""
        sjf_math_sub(sjt_parent1, sjt_functionParam3, sjt_functionParam4, &sjt_functionParam2);
        sjf_class_bar(_parent, sjt_functionParam2, _return);
    } else {
#line 12 ".\basic\class13.sj"
        (*_return) = 0;
    }
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_math(sjs_math* _this) {
}

void sjf_math_copy(sjs_math* _this, sjs_math* _from) {
}

void sjf_math_destroy(sjs_math* _this) {
}

void sjf_math_heap(sjs_math_heap* _this) {
}

void sjf_math_sub(sjs_math* _parent, int32_t x, int32_t y, int32_t* _return) {
    int32_t sjt_math1;
    int32_t sjt_math2;

#line 2 ".\basic\class13.sj"
    sjt_math1 = x;
#line 2
    sjt_math2 = y;
#line 3
    (*_return) = sjt_math1 - sjt_math2;
}

int main(int argc, char** argv) {
    sjf_math(&sjv_c.m);
    sjf_class(&sjv_c);
#line 8 ".\basic\class13.sj"
    sjt_parent2 = &sjv_c;
#line 20
    sjt_functionParam5 = 4;
#line 0 ""
    sjf_class_foo(sjt_parent2, sjt_functionParam5, &void1);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_class_destroy(&sjv_c);
}
