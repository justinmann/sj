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
#define sjs_anon1_typeId 2
#define sjs_anon1_heap_typeId 3
#define sjs_anon2_typeId 4
#define sjs_anon2_heap_typeId 5
#define sjs_anon1_class_typeId 6
#define sji_anon1_foo_typeId 7
#define sjs_anon1_class_heap_typeId 8
#define sjs_anon2_class_typeId 9
#define sji_anon2_foo_typeId 10
#define sjs_anon2_class_heap_typeId 11

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon1_heap sjs_anon1_heap;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon2_heap sjs_anon2_heap;
typedef struct td_sjs_anon1_class sjs_anon1_class;
typedef struct td_sji_anon1_foo sji_anon1_foo;
typedef struct td_sjs_anon1_class_heap sjs_anon1_class_heap;
typedef struct td_sjs_anon2_class sjs_anon2_class;
typedef struct td_sji_anon2_foo sji_anon2_foo;
typedef struct td_sjs_anon2_class_heap sjs_anon2_class_heap;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_anon1 {
    int structsNeedAValue;
};

struct td_sjs_anon1_heap {
    int _refCount;
};

struct td_sjs_anon2 {
    int structsNeedAValue;
};

struct td_sjs_anon2_heap {
    int _refCount;
};

struct td_sjs_anon1_class {
    sjs_anon1* _parent;
};

struct td_sji_anon1_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test1)(void* _parent, int32_t* _return);
};

struct td_sjs_anon1_class_heap {
    int _refCount;
    sjs_anon1* _parent;
};

struct td_sjs_anon2_class {
    sjs_anon2* _parent;
};

struct td_sji_anon2_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test2)(void* _parent, int32_t* _return);
};

struct td_sjs_anon2_class_heap {
    int _refCount;
    sjs_anon2* _parent;
};

void sjf_anon1(sjs_anon1* _this);
void sjf_anon1_class(sjs_anon1_class* _this);
sjs_object* sjf_anon1_class_asInterface(sjs_anon1_class* _this, int typeId);
sji_anon1_foo* sjf_anon1_class_as_sji_anon1_foo(sjs_anon1_class* _this);
void sjf_anon1_class_copy(sjs_anon1_class* _this, sjs_anon1_class* to);
void sjf_anon1_class_destroy(sjs_anon1_class* _this);
void sjf_anon1_class_heap(sjs_anon1_class_heap* _this);
sjs_object* sjf_anon1_class_heap_asInterface(sjs_anon1_class_heap* _this, int typeId);
sji_anon1_foo* sjf_anon1_class_heap_as_sji_anon1_foo(sjs_anon1_class_heap* _this);
void sjf_anon1_class_test1(sjs_anon1_class* _parent, int32_t* _return);
void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* to);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_heap(sjs_anon1_heap* _this);
void sjf_anon2(sjs_anon2* _this);
void sjf_anon2_class(sjs_anon2_class* _this);
sjs_object* sjf_anon2_class_asInterface(sjs_anon2_class* _this, int typeId);
sji_anon2_foo* sjf_anon2_class_as_sji_anon2_foo(sjs_anon2_class* _this);
void sjf_anon2_class_copy(sjs_anon2_class* _this, sjs_anon2_class* to);
void sjf_anon2_class_destroy(sjs_anon2_class* _this);
void sjf_anon2_class_heap(sjs_anon2_class_heap* _this);
sjs_object* sjf_anon2_class_heap_asInterface(sjs_anon2_class_heap* _this, int typeId);
sji_anon2_foo* sjf_anon2_class_heap_as_sji_anon2_foo(sjs_anon2_class_heap* _this);
void sjf_anon2_class_test2(sjs_anon2_class* _parent, int32_t* _return);
void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* to);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon2_heap(sjs_anon2_heap* _this);
void sji_anon1_foo_destroy(sji_anon1_foo* _this);
void sji_anon2_foo_destroy(sji_anon2_foo* _this);


void sjf_anon1(sjs_anon1* _this) {
}

void sjf_anon1_class(sjs_anon1_class* _this) {
}

sjs_object* sjf_anon1_class_asInterface(sjs_anon1_class* _this, int typeId) {
    switch (typeId) {
        case sji_anon1_foo_typeId:  {
            return (sjs_object*)sjf_anon1_class_as_sji_anon1_foo(_this);
        }
    }

    return 0;
}

sji_anon1_foo* sjf_anon1_class_as_sji_anon1_foo(sjs_anon1_class* _this) {
    sji_anon1_foo* _interface;
    _interface = (sji_anon1_foo*)malloc(sizeof(sji_anon1_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_anon1_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_anon1_class_asInterface;
    _interface->test1 = (void(*)(void*, int32_t*))sjf_anon1_class_test1;

    return _interface;
}

void sjf_anon1_class_copy(sjs_anon1_class* _this, sjs_anon1_class* to) {
}

void sjf_anon1_class_destroy(sjs_anon1_class* _this) {
}

void sjf_anon1_class_heap(sjs_anon1_class_heap* _this) {
}

sjs_object* sjf_anon1_class_heap_asInterface(sjs_anon1_class_heap* _this, int typeId) {
    switch (typeId) {
        case sji_anon1_foo_typeId:  {
            return (sjs_object*)sjf_anon1_class_heap_as_sji_anon1_foo(_this);
        }
    }

    return 0;
}

sji_anon1_foo* sjf_anon1_class_heap_as_sji_anon1_foo(sjs_anon1_class_heap* _this) {
    sji_anon1_foo* _interface;
    _interface = (sji_anon1_foo*)malloc(sizeof(sji_anon1_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_anon1_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_anon1_class_heap_asInterface;
    _interface->test1 = (void(*)(void*, int32_t*))sjf_anon1_class_test1;

    return _interface;
}

void sjf_anon1_class_test1(sjs_anon1_class* _parent, int32_t* _return) {
    (*_return) = 5;
}

void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* to) {
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1_heap* _this) {
}

void sjf_anon2(sjs_anon2* _this) {
}

void sjf_anon2_class(sjs_anon2_class* _this) {
}

sjs_object* sjf_anon2_class_asInterface(sjs_anon2_class* _this, int typeId) {
    switch (typeId) {
        case sji_anon2_foo_typeId:  {
            return (sjs_object*)sjf_anon2_class_as_sji_anon2_foo(_this);
        }
    }

    return 0;
}

sji_anon2_foo* sjf_anon2_class_as_sji_anon2_foo(sjs_anon2_class* _this) {
    sji_anon2_foo* _interface;
    _interface = (sji_anon2_foo*)malloc(sizeof(sji_anon2_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_anon2_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_anon2_class_asInterface;
    _interface->test2 = (void(*)(void*, int32_t*))sjf_anon2_class_test2;

    return _interface;
}

void sjf_anon2_class_copy(sjs_anon2_class* _this, sjs_anon2_class* to) {
}

void sjf_anon2_class_destroy(sjs_anon2_class* _this) {
}

void sjf_anon2_class_heap(sjs_anon2_class_heap* _this) {
}

sjs_object* sjf_anon2_class_heap_asInterface(sjs_anon2_class_heap* _this, int typeId) {
    switch (typeId) {
        case sji_anon2_foo_typeId:  {
            return (sjs_object*)sjf_anon2_class_heap_as_sji_anon2_foo(_this);
        }
    }

    return 0;
}

sji_anon2_foo* sjf_anon2_class_heap_as_sji_anon2_foo(sjs_anon2_class_heap* _this) {
    sji_anon2_foo* _interface;
    _interface = (sji_anon2_foo*)malloc(sizeof(sji_anon2_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_anon2_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_anon2_class_heap_asInterface;
    _interface->test2 = (void(*)(void*, int32_t*))sjf_anon2_class_test2;

    return _interface;
}

void sjf_anon2_class_test2(sjs_anon2_class* _parent, int32_t* _return) {
    (*_return) = 5;
}

void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* to) {
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_anon2_heap(sjs_anon2_heap* _this) {
}

void sji_anon1_foo_destroy(sji_anon1_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

void sji_anon2_foo_destroy(sji_anon2_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main() {
    sji_anon1_foo* a;
    sji_anon2_foo* b;
    sjs_anon1 namespace1;
    sjs_anon2 namespace2;
    sjs_anon1_class_heap* sjt_cast1;
    sjs_anon2_class_heap* sjt_cast2;
    sjs_anon1* sjt_dot1;
    sjs_anon2* sjt_dot2;

    sjf_anon1(&namespace1);
    sjf_anon2(&namespace2);
    sjt_dot1 = &namespace1;
    sjt_cast1 = (sjs_anon1_class_heap*)malloc(sizeof(sjs_anon1_class_heap));
    sjt_cast1->_refCount = 1;
    sjt_cast1->_parent = sjt_dot1;
    sjf_anon1_class_heap(sjt_cast1);
    a = (sji_anon1_foo*)sjf_anon1_class_heap_as_sji_anon1_foo(sjt_cast1);
    sjt_dot2 = &namespace2;
    sjt_cast2 = (sjs_anon2_class_heap*)malloc(sizeof(sjs_anon2_class_heap));
    sjt_cast2->_refCount = 1;
    sjt_cast2->_parent = sjt_dot2;
    sjf_anon2_class_heap(sjt_cast2);
    b = (sji_anon2_foo*)sjf_anon2_class_heap_as_sji_anon2_foo(sjt_cast2);

    a->_refCount--;
    if (a->_refCount <= 0) {
        sji_anon1_foo_destroy(a);
    }
    b->_refCount--;
    if (b->_refCount <= 0) {
        sji_anon2_foo_destroy(b);
    }
    sjt_cast1->_refCount--;
    if (sjt_cast1->_refCount <= 0) {
        sjf_anon1_class_destroy((sjs_anon1_class*)(((char*)sjt_cast1) + sizeof(int)));
    }
    sjt_cast2->_refCount--;
    if (sjt_cast2->_refCount <= 0) {
        sjf_anon2_class_destroy((sjs_anon2_class*)(((char*)sjt_cast2) + sizeof(int)));
    }
    sjf_anon1_destroy(&namespace1);
    sjf_anon2_destroy(&namespace2);
    return 0;
}
