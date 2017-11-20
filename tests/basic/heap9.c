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

#define sjs_class_typeId 1
#define sjs_class_heap_typeId 2
#define sjs_object_typeId 3

typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;
typedef struct td_sjs_object sjs_object;

struct td_sjs_class {
    int structsNeedAValue;
};

struct td_sjs_class_heap {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_foo1(sjs_class** _return);
void sjf_foo2(sjs_class_heap** _return);

sjs_class sjd_temp2;

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* to) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_foo1(sjs_class** _return) {
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjf_class(sjv_temp1);
    sjf_class_destroy(&sjd_temp1);

    *_return = sjv_temp1;
}

void sjf_foo2(sjs_class_heap** _return) {
    sjs_class_heap* sjv_temp2;

    sjv_temp2 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjv_temp2->_refCount = 1;
    sjf_class_heap(sjv_temp2);

    sjv_temp2->_refCount--;
    if (sjv_temp2->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjv_temp2) + sizeof(int)));
        free(sjv_temp2);
    }

    *_return = sjv_temp2;
}

int main() {
    sjs_class* result1;
    sjs_class_heap* result2;
    sjs_class* x1;
    sjs_class_heap* x2;

    result1 = &sjd_temp2;
    sjf_foo1(&result1);
    x1 = result1;
    result2 = 0;
    sjf_foo2(&result2);
    x2 = result2;
    if (x2 != 0) {
        x2->_refCount++;
    }

    if (result2 != 0) {
        result2->_refCount--;
        if (result2->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)result2) + sizeof(int)));
            free(result2);
        }
    }
    if (x2 != 0) {
        x2->_refCount--;
        if (x2->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)x2) + sizeof(int)));
            free(x2);
        }
    }
    sjf_class_destroy(&sjd_temp2);
    return 0;
}