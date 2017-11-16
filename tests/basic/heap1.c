#include <assert.h>
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
#define sjs_object_typeId 2

typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_object sjs_object;

struct td_sjs_class {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_func(sjs_class** _return);


void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;
    printf("RETAIN\tsjs_class*\t%0x\tvoid sjf_class(sjs_class* _this, sjs_class** _return)\t%d\n", (uintptr_t)_this, _this->_refCount);;

    *_return = _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_func(sjs_class** _return) {
    sjs_class* a;
    sjs_class* sjv_temp1;
    sjs_class* sjv_temp2;

    sjv_temp1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp1->_refCount = 1;
    printf("RETAIN\tsjs_class*\t%0x\tvoid sjf_func(sjs_class** _return)\t%d\n", (uintptr_t)sjv_temp1, sjv_temp1->_refCount);;
    sjf_class(sjv_temp1, &sjv_temp1);
    a = sjv_temp1;
    a->_refCount++;
    printf("RETAIN\tsjs_class*\t%0x\tvoid sjf_func(sjs_class** _return)\t%d\n", (uintptr_t)a, a->_refCount);;
    sjv_temp2 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp2->_refCount = 1;
    printf("RETAIN\tsjs_class*\t%0x\tvoid sjf_func(sjs_class** _return)\t%d\n", (uintptr_t)sjv_temp2, sjv_temp2->_refCount);;
    sjf_class(sjv_temp2, &sjv_temp2);
    a->_refCount--;
    printf("RELEASE\tsjs_class*\t%0x\tvoid sjf_func(sjs_class** _return)\t%d\n", (uintptr_t)a, a->_refCount);;
    if (a->_refCount <= 0) {
        sjf_class_destroy(a);
        free(a);
    }

    a = sjv_temp2;
    a->_refCount++;
    printf("RETAIN\tsjs_class*\t%0x\tvoid sjf_func(sjs_class** _return)\t%d\n", (uintptr_t)a, a->_refCount);;
    sjv_temp2->_refCount++;
    printf("RETAIN\tsjs_class*\t%0x\tvoid sjf_func(sjs_class** _return)\t%d\n", (uintptr_t)sjv_temp2, sjv_temp2->_refCount);;

    a->_refCount--;
    printf("RELEASE\tsjs_class*\t%0x\tvoid sjf_func(sjs_class** _return)\t%d\n", (uintptr_t)a, a->_refCount);
    if (a->_refCount <= 0) {
        sjf_class_destroy(a);
        free(a);
    }
    sjv_temp1->_refCount--;
    printf("RELEASE\tsjs_class*\t%0x\tvoid sjf_func(sjs_class** _return)\t%d\n", (uintptr_t)sjv_temp1, sjv_temp1->_refCount);
    if (sjv_temp1->_refCount <= 0) {
        sjf_class_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjv_temp2->_refCount--;
    printf("RELEASE\tsjs_class*\t%0x\tvoid sjf_func(sjs_class** _return)\t%d\n", (uintptr_t)sjv_temp2, sjv_temp2->_refCount);
    if (sjv_temp2->_refCount <= 0) {
        sjf_class_destroy(sjv_temp2);
        free(sjv_temp2);
    }

    *_return = sjv_temp2;
}

int main() {
    sjs_class* b;
    sjs_class* result1;

    result1 = 0;
    sjf_func(&result1);
    b = result1;
    b->_refCount++;
    printf("RETAIN\tsjs_class*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)b, b->_refCount);;

    b->_refCount--;
    printf("RELEASE\tsjs_class*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)b, b->_refCount);
    if (b->_refCount <= 0) {
        sjf_class_destroy(b);
        free(b);
    }
    result1->_refCount--;
    printf("RELEASE\tsjs_class*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result1, result1->_refCount);
    if (result1->_refCount <= 0) {
        sjf_class_destroy(result1);
        free(result1);
    }
    return 0;
}
