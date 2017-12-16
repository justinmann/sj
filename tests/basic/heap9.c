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
#define sjs_class_typeId 2
#define sjs_class_heap_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_class {
    int structsNeedAValue;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
};

sjs_class sjv_x1;
sjs_class_heap* sjv_x2;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_foo1(sjs_class* _return);
void sjf_foo1_heap(sjs_class_heap** _return);
void sjf_foo2_heap(sjs_class_heap** _return);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_foo1(sjs_class* _return) {
    sjf_class(_return);
}

void sjf_foo1_heap(sjs_class_heap** _return) {
    (*_return) = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    (*_return)->_refCount = 1;
    sjf_class_heap((*_return));
}

void sjf_foo2_heap(sjs_class_heap** _return) {
    sjs_class_heap* sjt_value1;

    sjt_value1 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjt_value1->_refCount = 1;
    sjf_class_heap(sjt_value1);
#line 8 "heap9.sj"
    (*_return) = sjt_value1;
    if ((*_return) != 0) {
        (*_return)->_refCount++;
    }

    sjt_value1->_refCount--;
    if (sjt_value1->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjt_value1) + sizeof(intptr_t)));
    }
}

int main(int argc, char** argv) {
    sjf_foo1(&sjv_x1);
    sjf_foo2_heap(&sjv_x2);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_x2 != 0) {
        sjv_x2->_refCount--;
        if (sjv_x2->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjv_x2) + sizeof(intptr_t)));
        }
    }
    sjf_class_destroy(&sjv_x1);
}
