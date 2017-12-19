#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isvalid;
    int32_t value;
};
const int32_option int32_empty = { false };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isvalid;
    uint32_t value;
};
const uint32_option uint32_empty = { false };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isvalid;
    int64_t value;
};
const int64_option int64_empty = { false };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isvalid;
    uint64_t value;
};
const uint64_option uint64_empty = { false };

typedef struct td_void_option void_option;
struct td_void_option {
    bool isvalid;
    void* value;
};
const void_option void_empty = { false };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isvalid;
    char value;
};
const char_option char_empty = { false };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isvalid;
    float value;
};
const float_option float_empty = { false };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isvalid;
    double value;
};
const double_option double_empty = { false };

#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_inner_typeId 3
#define sjs_class_typeId 4
#define sjs_class2_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_inner sjs_inner;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class2 sjs_class2;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_inner {
    int _refCount;
};

struct td_sjs_class {
    int _refCount;
    sjs_inner inner;
};

struct td_sjs_class2 {
    int _refCount;
    sjs_inner inner;
};

sjs_class sjv_x3 = { -1 };
sjs_class2 sjv_x7 = { -1 };

void sjf_class(sjs_class* _this);
void sjf_class2(sjs_class2* _this);
void sjf_class2_copy(sjs_class2* _this, sjs_class2* _from);
void sjf_class2_destroy(sjs_class2* _this);
void sjf_class2_heap(sjs_class2* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_inner(sjs_inner* _this);
void sjf_inner_copy(sjs_inner* _this, sjs_inner* _from);
void sjf_inner_destroy(sjs_inner* _this);
void sjf_inner_heap(sjs_inner* _this);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class2(sjs_class2* _this) {
}

void sjf_class2_copy(sjs_class2* _this, sjs_class2* _from) {
    _this->inner._refCount = 1;
    sjf_inner_copy((_this->inner._refCount != -1 ? &_this->inner : 0), (_from->inner._refCount != -1 ? &_from->inner : 0));
}

void sjf_class2_destroy(sjs_class2* _this) {
}

void sjf_class2_heap(sjs_class2* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->inner._refCount = 1;
    sjf_inner_copy(&_this->inner, &_from->inner);
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_inner(sjs_inner* _this) {
}

void sjf_inner_copy(sjs_inner* _this, sjs_inner* _from) {
}

void sjf_inner_destroy(sjs_inner* _this) {
}

void sjf_inner_heap(sjs_inner* _this) {
}

int main(int argc, char** argv) {
    sjv_x3._refCount = 1;
    sjv_x3.inner._refCount = 1;
    sjf_inner(&sjv_x3.inner);
    sjf_class(&sjv_x3);
    sjv_x7._refCount = 1;
    sjv_x7.inner._refCount = 1;
    sjf_inner(&sjv_x7.inner);
    sjf_class2(&sjv_x7);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_x3._refCount == 1) { sjf_class_destroy(&sjv_x3); }
    if (sjv_x7._refCount == 1) { sjf_class2_destroy(&sjv_x7); }
}
