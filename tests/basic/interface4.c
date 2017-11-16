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

#define sji_foo_typeId 1
#define sjs_class_typeId 2
#define sjs_object_typeId 3

typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_object sjs_object;

struct td_sji_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test)(sjs_object* _parent, int32_t* _return);
};

struct td_sjs_class {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId);
sji_foo* sjf_class_as_sji_foo(sjs_class* _this);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_test(sjs_class* _parent, int32_t* _return);
void sji_foo_destroy(sji_foo* _this);

sjs_class sjd_temp1;

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;
    printf("RETAIN\tsjs_class*\t%0x\tvoid sjf_class(sjs_class* _this, sjs_class** _return)\t%d\n", (uintptr_t)_this, _this->_refCount);;

    *_return = _this;
}

sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId) {
    switch (typeId) {
        case sji_foo_typeId: return (sjs_object*)sjf_class_as_sji_foo(_this);
    }

    return 0;
}

sji_foo* sjf_class_as_sji_foo(sjs_class* _this) {
    sji_foo* _interface = (sji_foo*)malloc(sizeof(sji_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(sjs_object*))sjf_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_asInterface;
    _interface->test = (void(*)(sjs_object*, int32_t*))sjf_class_test;
    return _interface;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_test(sjs_class* _parent, int32_t* _return) {

    *_return = 5;
}

void sji_foo_destroy(sji_foo* _this) {
    _this->_parent->_refCount--;
    printf("RELEASE\tvoid sji_foo_destroy(sji_foo* _this)\t%0x\tvoid sji_foo_destroy(sji_foo* _this)\t%d\n", (uintptr_t)_this->_parent, _this->_parent->_refCount);;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main() {
    sji_foo* a;
    sji_foo* result1;
    int32_t result2;
    sjs_class* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    printf("RETAIN\tsjs_class*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)sjv_temp1, sjv_temp1->_refCount);;
    sjf_class(sjv_temp1, &sjv_temp1);
    result1 = sjf_class_as_sji_foo(sjv_temp1);
    a = result1;
    a->_refCount++;
    printf("RETAIN\tsji_foo*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)a, a->_refCount);;
    result1->_refCount--;
    printf("RELEASE\tsji_foo*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result1, result1->_refCount);;
    if (result1->_refCount <= 0) {
        sji_foo_destroy(result1);
        free(result1);
    }

    a->test(a->_parent, &result2);

    a->_refCount--;
    printf("RELEASE\tsji_foo*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)a, a->_refCount);
    if (a->_refCount <= 0) {
        sji_foo_destroy(a);
        free(a);
    }
    assert(sjd_temp1._refCount == 0);
    return 0;
}
