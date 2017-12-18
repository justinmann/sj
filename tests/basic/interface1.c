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
#define sjs_namespace1_class_typeId 2
#define sji_namespace1_foo_typeId 3
#define sjs_namespace2_class_typeId 4
#define sji_namespace2_foo_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_namespace1_class sjs_namespace1_class;
typedef struct td_sji_namespace1_foo sji_namespace1_foo;
typedef struct td_sjs_namespace2_class sjs_namespace2_class;
typedef struct td_sji_namespace2_foo sji_namespace2_foo;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_namespace1_class {
    int _refCount;
};

struct td_sji_namespace1_foo {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test1)(void* _parent, int32_t* _return);
};

struct td_sjs_namespace2_class {
    int _refCount;
};

struct td_sji_namespace2_foo {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test2)(void* _parent, int32_t* _return);
};

sjs_namespace1_class* sjt_cast1;
sjs_namespace2_class* sjt_cast2;
sji_namespace1_foo* sjv_a;
sji_namespace2_foo* sjv_b;

void sjf_namespace1_class(sjs_namespace1_class* _this);
sjs_object* sjf_namespace1_class_asInterface(sjs_namespace1_class* _this, int typeId);
sji_namespace1_foo* sjf_namespace1_class_as_sji_namespace1_foo(sjs_namespace1_class* _this);
void sjf_namespace1_class_copy(sjs_namespace1_class* _this, sjs_namespace1_class* _from);
void sjf_namespace1_class_destroy(sjs_namespace1_class* _this);
void sjf_namespace1_class_heap(sjs_namespace1_class* _this);
sjs_object* sjf_namespace1_class_heap_asInterface(sjs_namespace1_class* _this, int typeId);
sji_namespace1_foo* sjf_namespace1_class_heap_as_sji_namespace1_foo(sjs_namespace1_class* _this);
void sjf_namespace1_class_namespace1_test1(sjs_namespace1_class* _parent, int32_t* _return);
void sjf_namespace2_class(sjs_namespace2_class* _this);
sjs_object* sjf_namespace2_class_asInterface(sjs_namespace2_class* _this, int typeId);
sji_namespace2_foo* sjf_namespace2_class_as_sji_namespace2_foo(sjs_namespace2_class* _this);
void sjf_namespace2_class_copy(sjs_namespace2_class* _this, sjs_namespace2_class* _from);
void sjf_namespace2_class_destroy(sjs_namespace2_class* _this);
void sjf_namespace2_class_heap(sjs_namespace2_class* _this);
sjs_object* sjf_namespace2_class_heap_asInterface(sjs_namespace2_class* _this, int typeId);
sji_namespace2_foo* sjf_namespace2_class_heap_as_sji_namespace2_foo(sjs_namespace2_class* _this);
void sjf_namespace2_class_namespace2_test2(sjs_namespace2_class* _parent, int32_t* _return);
void sji_namespace1_foo_copy(sji_namespace1_foo* _this, sji_namespace1_foo* _from);
void sji_namespace1_foo_destroy(sji_namespace1_foo* _this);
void sji_namespace2_foo_copy(sji_namespace2_foo* _this, sji_namespace2_foo* _from);
void sji_namespace2_foo_destroy(sji_namespace2_foo* _this);
void main_destroy(void);

void sjf_namespace1_class(sjs_namespace1_class* _this) {
}

sjs_object* sjf_namespace1_class_asInterface(sjs_namespace1_class* _this, int typeId) {
    switch (typeId) {
        case sji_namespace1_foo_typeId:  {
            return (sjs_object*)sjf_namespace1_class_as_sji_namespace1_foo(_this);
        }
    }

    return 0;
}

sji_namespace1_foo* sjf_namespace1_class_as_sji_namespace1_foo(sjs_namespace1_class* _this) {
    sji_namespace1_foo* _interface;
    _interface = (sji_namespace1_foo*)malloc(sizeof(sji_namespace1_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_namespace1_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_namespace1_class_asInterface;
    _interface->test1 = (void(*)(void*, int32_t*))sjf_namespace1_class_namespace1_test1;

    return _interface;
}

void sjf_namespace1_class_copy(sjs_namespace1_class* _this, sjs_namespace1_class* _from) {
}

void sjf_namespace1_class_destroy(sjs_namespace1_class* _this) {
}

void sjf_namespace1_class_heap(sjs_namespace1_class* _this) {
}

sjs_object* sjf_namespace1_class_heap_asInterface(sjs_namespace1_class* _this, int typeId) {
    switch (typeId) {
        case sji_namespace1_foo_typeId:  {
            return (sjs_object*)sjf_namespace1_class_heap_as_sji_namespace1_foo(_this);
        }
    }

    return 0;
}

sji_namespace1_foo* sjf_namespace1_class_heap_as_sji_namespace1_foo(sjs_namespace1_class* _this) {
    sji_namespace1_foo* _interface;
    _interface = (sji_namespace1_foo*)malloc(sizeof(sji_namespace1_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_namespace1_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_namespace1_class_heap_asInterface;
    _interface->test1 = (void(*)(void*, int32_t*))sjf_namespace1_class_namespace1_test1;

    return _interface;
}

void sjf_namespace1_class_namespace1_test1(sjs_namespace1_class* _parent, int32_t* _return) {
    (*_return) = 5;
}

void sjf_namespace2_class(sjs_namespace2_class* _this) {
}

sjs_object* sjf_namespace2_class_asInterface(sjs_namespace2_class* _this, int typeId) {
    switch (typeId) {
        case sji_namespace2_foo_typeId:  {
            return (sjs_object*)sjf_namespace2_class_as_sji_namespace2_foo(_this);
        }
    }

    return 0;
}

sji_namespace2_foo* sjf_namespace2_class_as_sji_namespace2_foo(sjs_namespace2_class* _this) {
    sji_namespace2_foo* _interface;
    _interface = (sji_namespace2_foo*)malloc(sizeof(sji_namespace2_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_namespace2_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_namespace2_class_asInterface;
    _interface->test2 = (void(*)(void*, int32_t*))sjf_namespace2_class_namespace2_test2;

    return _interface;
}

void sjf_namespace2_class_copy(sjs_namespace2_class* _this, sjs_namespace2_class* _from) {
}

void sjf_namespace2_class_destroy(sjs_namespace2_class* _this) {
}

void sjf_namespace2_class_heap(sjs_namespace2_class* _this) {
}

sjs_object* sjf_namespace2_class_heap_asInterface(sjs_namespace2_class* _this, int typeId) {
    switch (typeId) {
        case sji_namespace2_foo_typeId:  {
            return (sjs_object*)sjf_namespace2_class_heap_as_sji_namespace2_foo(_this);
        }
    }

    return 0;
}

sji_namespace2_foo* sjf_namespace2_class_heap_as_sji_namespace2_foo(sjs_namespace2_class* _this) {
    sji_namespace2_foo* _interface;
    _interface = (sji_namespace2_foo*)malloc(sizeof(sji_namespace2_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_namespace2_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_namespace2_class_heap_asInterface;
    _interface->test2 = (void(*)(void*, int32_t*))sjf_namespace2_class_namespace2_test2;

    return _interface;
}

void sjf_namespace2_class_namespace2_test2(sjs_namespace2_class* _parent, int32_t* _return) {
    (*_return) = 5;
}

void sji_namespace1_foo_copy(sji_namespace1_foo* _this, sji_namespace1_foo* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->test1 = _from->test1;
}

void sji_namespace1_foo_destroy(sji_namespace1_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

void sji_namespace2_foo_copy(sji_namespace2_foo* _this, sji_namespace2_foo* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->test2 = _from->test2;
}

void sji_namespace2_foo_destroy(sji_namespace2_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
    sjt_cast1 = (sjs_namespace1_class*)malloc(sizeof(sjs_namespace1_class));
    sjt_cast1->_refCount = 1;
    sjf_namespace1_class_heap(sjt_cast1);
    sjv_a = (sji_namespace1_foo*)sjf_namespace1_class_heap_as_sji_namespace1_foo(sjt_cast1);
    sjt_cast2 = (sjs_namespace2_class*)malloc(sizeof(sjs_namespace2_class));
    sjt_cast2->_refCount = 1;
    sjf_namespace2_class_heap(sjt_cast2);
    sjv_b = (sji_namespace2_foo*)sjf_namespace2_class_heap_as_sji_namespace2_foo(sjt_cast2);
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
        sjf_namespace1_class_destroy(sjt_cast1);
    }
    sjt_cast2->_refCount--;
    if (sjt_cast2->_refCount <= 0) {
        sjf_namespace2_class_destroy(sjt_cast2);
    }
    sjv_a->_refCount--;
    if (sjv_a->_refCount <= 0) {
        sji_namespace1_foo_destroy(sjv_a);
    }
    sjv_b->_refCount--;
    if (sjv_b->_refCount <= 0) {
        sji_namespace2_foo_destroy(sjv_b);
    }
}
