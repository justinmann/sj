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
#define sji_foo_typeId 3
#define sjs_bar_typeId 4
#define sjs_bar_heap_typeId 5
#define sjs_class_heap_typeId 6

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;
typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_bar sjs_bar;
typedef struct td_sjs_bar_heap sjs_bar_heap;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_class {
    int structsNeedAValue;
};

struct td_sji_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test)(void* _parent, int32_t , sjs_bar* _return);
    void (*test_heap)(void* _parent, int32_t , sjs_bar_heap** _return);
};

struct td_sjs_bar {
    int structsNeedAValue;
};

struct td_sjs_bar_heap {
    int _refCount;
};

struct td_sjs_class_heap {
    int _refCount;
};

void sjf_bar(sjs_bar* _this);
void sjf_bar_copy(sjs_bar* _this, sjs_bar* to);
void sjf_bar_destroy(sjs_bar* _this);
void sjf_bar_heap(sjs_bar_heap* _this);
void sjf_class(sjs_class* _this);
sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId);
sji_foo* sjf_class_as_sji_foo(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
sjs_object* sjf_class_heap_asInterface(sjs_class_heap* _this, int typeId);
sji_foo* sjf_class_heap_as_sji_foo(sjs_class_heap* _this);
void sjf_class_test(sjs_class* _parent, int32_t a, sjs_bar* _return);
void sjf_class_test_heap(sjs_class* _parent, int32_t a, sjs_bar_heap** _return);
void sji_foo_destroy(sji_foo* _this);


void sjf_bar(sjs_bar* _this) {
}

void sjf_bar_copy(sjs_bar* _this, sjs_bar* to) {
}

void sjf_bar_destroy(sjs_bar* _this) {
}

void sjf_bar_heap(sjs_bar_heap* _this) {
}

void sjf_class(sjs_class* _this) {
}

sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId) {
    switch (typeId) {
        case sji_foo_typeId:  {
            return (sjs_object*)sjf_class_as_sji_foo(_this);
        }
    }

    return 0;
}

sji_foo* sjf_class_as_sji_foo(sjs_class* _this) {
    sji_foo* _interface;
    _interface = (sji_foo*)malloc(sizeof(sji_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_asInterface;
    _interface->test = (void(*)(void*,int32_t, sjs_bar*))sjf_class_test;
    _interface->test_heap = (void(*)(void*,int32_t, sjs_bar_heap**))sjf_class_test_heap;

    return _interface;
}

void sjf_class_copy(sjs_class* _this, sjs_class* to) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

sjs_object* sjf_class_heap_asInterface(sjs_class_heap* _this, int typeId) {
    switch (typeId) {
        case sji_foo_typeId:  {
            return (sjs_object*)sjf_class_heap_as_sji_foo(_this);
        }
    }

    return 0;
}

sji_foo* sjf_class_heap_as_sji_foo(sjs_class_heap* _this) {
    sji_foo* _interface;
    _interface = (sji_foo*)malloc(sizeof(sji_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_heap_asInterface;
    _interface->test = (void(*)(void*,int32_t, sjs_bar*))sjf_class_test;
    _interface->test_heap = (void(*)(void*,int32_t, sjs_bar_heap**))sjf_class_test_heap;

    return _interface;
}

void sjf_class_test(sjs_class* _parent, int32_t a, sjs_bar* _return) {
    sjf_bar(_return);
}

void sjf_class_test_heap(sjs_class* _parent, int32_t a, sjs_bar_heap** _return) {
    (*_return) = (sjs_bar_heap*)malloc(sizeof(sjs_bar_heap));
    (*_return)->_refCount = 1;
    sjf_bar_heap((*_return));
}

void sji_foo_destroy(sji_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main() {
    sji_foo* a;
    sjs_bar b;
    sjs_bar_heap* c;
    sjs_class_heap* sjt_cast1;
    sji_foo* sjt_dot1;
    sji_foo* sjt_dot2;
    int32_t sjt_interfaceParam1;
    int32_t sjt_interfaceParam2;

    sjt_cast1 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjt_cast1->_refCount = 1;
    sjf_class_heap(sjt_cast1);
    a = (sji_foo*)sjf_class_heap_as_sji_foo(sjt_cast1);
    sjt_dot1 = a;
    sjt_interfaceParam1 = 1;
    sjt_dot1->test(sjt_dot1->_parent, sjt_interfaceParam1, &b);
    sjt_dot2 = a;
    sjt_interfaceParam2 = 1;
    c = (sjs_bar_heap*)malloc(sizeof(sjs_bar_heap));
    c->_refCount = 1;
    sjt_dot2->test_heap(sjt_dot2->_parent, sjt_interfaceParam2, &c);

    a->_refCount--;
    if (a->_refCount <= 0) {
        sji_foo_destroy(a);
    }
    c->_refCount--;
    if (c->_refCount <= 0) {
        sjf_bar_destroy((sjs_bar*)(((char*)c) + sizeof(int)));
    }
    sjt_cast1->_refCount--;
    if (sjt_cast1->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjt_cast1) + sizeof(int)));
    }
    sjf_bar_destroy(&b);
    return 0;
}