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

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_class {
    int32_t m;
};

void sjf_class(sjs_class* _this, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_inner(sjs_class* _parent, int32_t* _return);


void sjf_class(sjs_class* _this, int32_t* _return) {
    sjf_class_inner(_this, &(*_return));
}

void sjf_class_copy(sjs_class* _this, sjs_class* to) {
    _this->m = to->m;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_inner(sjs_class* _parent, int32_t* _return) {
    (*_return) = m;
}

int main() {
    sjs_class object1;
    int32_t void1;

    object1.m = 1;
    sjf_class(&object1, &void1);

    sjf_class_destroy(&object1);
    return 0;
}
