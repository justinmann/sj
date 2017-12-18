#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isempty;
    int32_t value;
};
const int32_option int32_empty = { true };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isempty;
    uint32_t value;
};
const uint32_option uint32_empty = { true };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isempty;
    int64_t value;
};
const int64_option int64_empty = { true };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isempty;
    uint64_t value;
};
const uint64_option uint64_empty = { true };

typedef struct td_void_option void_option;
struct td_void_option {
    bool isempty;
    void* value;
};
const void_option void_empty = { true };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isempty;
    char value;
};
const char_option char_empty = { true };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isempty;
    float value;
};
const float_option float_empty = { true };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isempty;
    double value;
};
const double_option double_empty = { true };

#define sjs_object_typeId 1
#define sjs_class_typeId 2
#define sjs_bar_typeId 3
#define sji_foo_typeId 4

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_bar sjs_bar;
typedef struct td_sji_foo sji_foo;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_class {
    int _refCount;
};

struct td_sjs_bar {
    int _refCount;
};

struct td_sji_foo {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test)(void* _parent, int32_t a, sjs_bar* _return);
    void (*test_heap)(void* _parent, int32_t a, sjs_bar** _return);
};

sjs_class* sjt_cast1 = 0;
int32_t sjt_interfaceParam1;
int32_t sjt_interfaceParam2;
sji_foo* sjt_parent1 = 0;
sji_foo* sjt_parent2 = 0;
sji_foo* sjv_a = 0;
sjs_bar sjv_b = { -1 };
sjs_bar* sjv_c = 0;

void sjf_bar(sjs_bar* _this);
void sjf_bar_copy(sjs_bar* _this, sjs_bar* _from);
void sjf_bar_destroy(sjs_bar* _this);
void sjf_bar_heap(sjs_bar* _this);
void sjf_class(sjs_class* _this);
sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId);
sji_foo* sjf_class_as_sji_foo(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
sjs_object* sjf_class_heap_asInterface(sjs_class* _this, int typeId);
sji_foo* sjf_class_heap_as_sji_foo(sjs_class* _this);
void sjf_class_test(sjs_class* _parent, int32_t a, sjs_bar* _return);
void sjf_class_test_heap(sjs_class* _parent, int32_t a, sjs_bar** _return);
void sji_foo_copy(sji_foo* _this, sji_foo* _from);
void sji_foo_destroy(sji_foo* _this);
void main_destroy(void);

void sjf_bar(sjs_bar* _this) {
}

void sjf_bar_copy(sjs_bar* _this, sjs_bar* _from) {
}

void sjf_bar_destroy(sjs_bar* _this) {
}

void sjf_bar_heap(sjs_bar* _this) {
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
    _interface->test_heap = (void(*)(void*,int32_t, sjs_bar**))sjf_class_test_heap;

    return _interface;
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

sjs_object* sjf_class_heap_asInterface(sjs_class* _this, int typeId) {
    switch (typeId) {
        case sji_foo_typeId:  {
            return (sjs_object*)sjf_class_heap_as_sji_foo(_this);
        }
    }

    return 0;
}

sji_foo* sjf_class_heap_as_sji_foo(sjs_class* _this) {
    sji_foo* _interface;
    _interface = (sji_foo*)malloc(sizeof(sji_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_heap_asInterface;
    _interface->test = (void(*)(void*,int32_t, sjs_bar*))sjf_class_test;
    _interface->test_heap = (void(*)(void*,int32_t, sjs_bar**))sjf_class_test_heap;

    return _interface;
}

void sjf_class_test(sjs_class* _parent, int32_t a, sjs_bar* _return) {
    _return->_refCount = 1;
    sjf_bar(_return);
}

void sjf_class_test_heap(sjs_class* _parent, int32_t a, sjs_bar** _return) {
    (*_return) = (sjs_bar*)malloc(sizeof(sjs_bar));
    (*_return)->_refCount = 1;
    sjf_bar_heap((*_return));
}

void sji_foo_copy(sji_foo* _this, sji_foo* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->test = _from->test;
    _this->test = _from->test;
}

void sji_foo_destroy(sji_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
    sjt_cast1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjt_cast1->_refCount = 1;
    sjf_class_heap(sjt_cast1);
    sjv_a = (sji_foo*)sjf_class_heap_as_sji_foo(sjt_cast1);
    sjt_parent1 = sjv_a;
    sjt_interfaceParam1 = 1;
    sjv_b._refCount = 1;
    sjt_parent1->test(sjt_parent1->_parent, sjt_interfaceParam1, &sjv_b);
    sjt_parent2 = sjv_a;
    sjt_interfaceParam2 = 1;
    sjv_c = (sjs_bar*)malloc(sizeof(sjs_bar));
    sjv_c->_refCount = 1;
    sjt_parent2->test_heap(sjt_parent2->_parent, sjt_interfaceParam2, &sjv_c);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjt_cast1->_refCount--;
    if (sjt_cast1->_refCount <= 0) {
        sjf_class_destroy(sjt_cast1);
    }
    sjv_a->_refCount--;
    if (sjv_a->_refCount <= 0) {
        sji_foo_destroy(sjv_a);
    }
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        sjf_bar_destroy(sjv_c);
    }
    if (sjv_b._refCount == 1) { sjf_bar_destroy(&sjv_b); }
}
