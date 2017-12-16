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
#define sjs_anon1_typeId 2
#define sjs_anon1_heap_typeId 3
#define sjs_anon2_typeId 4
#define sjs_anon2_heap_typeId 5
#define sjs_anon1_class_typeId 6
#define sjs_anon1_class_heap_typeId 7
#define sji_anon1_foo_typeId 8
#define sjs_anon2_class_typeId 9
#define sjs_anon2_class_heap_typeId 10
#define sji_anon2_foo_typeId 11

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon1_heap sjs_anon1_heap;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon2_heap sjs_anon2_heap;
typedef struct td_sjs_anon1_class sjs_anon1_class;
typedef struct td_sjs_anon1_class_heap sjs_anon1_class_heap;
typedef struct td_sji_anon1_foo sji_anon1_foo;
typedef struct td_sjs_anon2_class sjs_anon2_class;
typedef struct td_sjs_anon2_class_heap sjs_anon2_class_heap;
typedef struct td_sji_anon2_foo sji_anon2_foo;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_anon1 {
    int structsNeedAValue;
};

struct td_sjs_anon1_heap {
    intptr_t _refCount;
};

struct td_sjs_anon2 {
    int structsNeedAValue;
};

struct td_sjs_anon2_heap {
    intptr_t _refCount;
};

struct td_sjs_anon1_class {
    int structsNeedAValue;
};

struct td_sjs_anon1_class_heap {
    intptr_t _refCount;
};

struct td_sji_anon1_foo {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test1)(void* _parent, int32_t* _return);
};

struct td_sjs_anon2_class {
    int structsNeedAValue;
};

struct td_sjs_anon2_class_heap {
    intptr_t _refCount;
};

struct td_sji_anon2_foo {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test2)(void* _parent, int32_t* _return);
};

sjs_anon1_class_heap* sjt_cast1;
sjs_anon2_class_heap* sjt_cast2;
sjs_anon1* sjt_parent1;
sjs_anon2* sjt_parent2;
sji_anon1_foo* sjv_a;
sji_anon2_foo* sjv_b;
sjs_anon1 sjv_namespace1;
sjs_anon2 sjv_namespace2;

void sjf_anon1(sjs_anon1* _this);
void sjf_anon1_class(sjs_anon1_class* _this, sjs_anon1* _parent);
sjs_object* sjf_anon1_class_asInterface(sjs_anon1_class* _this, int typeId);
sji_anon1_foo* sjf_anon1_class_as_sji_anon1_foo(sjs_anon1_class* _this);
void sjf_anon1_class_copy(sjs_anon1_class* _this, sjs_anon1_class* _from);
void sjf_anon1_class_destroy(sjs_anon1_class* _this);
void sjf_anon1_class_heap(sjs_anon1_class_heap* _this, sjs_anon1* _parent);
sjs_object* sjf_anon1_class_heap_asInterface(sjs_anon1_class_heap* _this, int typeId);
sji_anon1_foo* sjf_anon1_class_heap_as_sji_anon1_foo(sjs_anon1_class_heap* _this);
void sjf_anon1_class_test1(sjs_anon1_class* _parent, int32_t* _return);
void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* _from);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_heap(sjs_anon1_heap* _this);
void sjf_anon2(sjs_anon2* _this);
void sjf_anon2_class(sjs_anon2_class* _this, sjs_anon2* _parent);
sjs_object* sjf_anon2_class_asInterface(sjs_anon2_class* _this, int typeId);
sji_anon2_foo* sjf_anon2_class_as_sji_anon2_foo(sjs_anon2_class* _this);
void sjf_anon2_class_copy(sjs_anon2_class* _this, sjs_anon2_class* _from);
void sjf_anon2_class_destroy(sjs_anon2_class* _this);
void sjf_anon2_class_heap(sjs_anon2_class_heap* _this, sjs_anon2* _parent);
sjs_object* sjf_anon2_class_heap_asInterface(sjs_anon2_class_heap* _this, int typeId);
sji_anon2_foo* sjf_anon2_class_heap_as_sji_anon2_foo(sjs_anon2_class_heap* _this);
void sjf_anon2_class_test2(sjs_anon2_class* _parent, int32_t* _return);
void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* _from);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon2_heap(sjs_anon2_heap* _this);
void sji_anon1_foo_copy(sji_anon1_foo* _this, sji_anon1_foo* _from);
void sji_anon1_foo_destroy(sji_anon1_foo* _this);
void sji_anon2_foo_copy(sji_anon2_foo* _this, sji_anon2_foo* _from);
void sji_anon2_foo_destroy(sji_anon2_foo* _this);
void main_destroy(void);

void sjf_anon1(sjs_anon1* _this) {
}

void sjf_anon1_class(sjs_anon1_class* _this, sjs_anon1* _parent) {
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

void sjf_anon1_class_copy(sjs_anon1_class* _this, sjs_anon1_class* _from) {
}

void sjf_anon1_class_destroy(sjs_anon1_class* _this) {
}

void sjf_anon1_class_heap(sjs_anon1_class_heap* _this, sjs_anon1* _parent) {
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
#line 7 "interface1.sj"
    (*_return) = 5;
}

void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* _from) {
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1_heap* _this) {
}

void sjf_anon2(sjs_anon2* _this) {
}

void sjf_anon2_class(sjs_anon2_class* _this, sjs_anon2* _parent) {
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

void sjf_anon2_class_copy(sjs_anon2_class* _this, sjs_anon2_class* _from) {
}

void sjf_anon2_class_destroy(sjs_anon2_class* _this) {
}

void sjf_anon2_class_heap(sjs_anon2_class_heap* _this, sjs_anon2* _parent) {
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
#line 17 "interface1.sj"
    (*_return) = 5;
}

void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* _from) {
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_anon2_heap(sjs_anon2_heap* _this) {
}

void sji_anon1_foo_copy(sji_anon1_foo* _this, sji_anon1_foo* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->test1 = _from->test1;
}

void sji_anon1_foo_destroy(sji_anon1_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

void sji_anon2_foo_copy(sji_anon2_foo* _this, sji_anon2_foo* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->test2 = _from->test2;
}

void sji_anon2_foo_destroy(sji_anon2_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
    sjf_anon1(&sjv_namespace1);
    sjf_anon2(&sjv_namespace2);
#line 6 "interface1.sj"
    sjt_parent1 = &sjv_namespace1;
#line 6
    sjt_cast1 = (sjs_anon1_class_heap*)malloc(sizeof(sjs_anon1_class_heap));
#line 6
    sjt_cast1->_refCount = 1;
#line 6
    sjf_anon1_class_heap(sjt_cast1, sjt_parent1);
#line 2
    sjv_a = (sji_anon1_foo*)sjf_anon1_class_heap_as_sji_anon1_foo(sjt_cast1);
#line 16
    sjt_parent2 = &sjv_namespace2;
#line 16
    sjt_cast2 = (sjs_anon2_class_heap*)malloc(sizeof(sjs_anon2_class_heap));
#line 16
    sjt_cast2->_refCount = 1;
#line 16
    sjf_anon2_class_heap(sjt_cast2, sjt_parent2);
#line 12
    sjv_b = (sji_anon2_foo*)sjf_anon2_class_heap_as_sji_anon2_foo(sjt_cast2);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_cast1->_refCount--;
    if (sjt_cast1->_refCount <= 0) {
        sjf_anon1_class_destroy((sjs_anon1_class*)(((char*)sjt_cast1) + sizeof(intptr_t)));
    }
    sjt_cast2->_refCount--;
    if (sjt_cast2->_refCount <= 0) {
        sjf_anon2_class_destroy((sjs_anon2_class*)(((char*)sjt_cast2) + sizeof(intptr_t)));
    }
    sjv_a->_refCount--;
    if (sjv_a->_refCount <= 0) {
        sji_anon1_foo_destroy(sjv_a);
    }
    sjv_b->_refCount--;
    if (sjv_b->_refCount <= 0) {
        sji_anon2_foo_destroy(sjv_b);
    }
    sjf_anon1_destroy(&sjv_namespace1);
    sjf_anon2_destroy(&sjv_namespace2);
}
