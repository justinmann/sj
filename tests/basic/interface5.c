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
#define sjs_class_i32_typeId 2
#define sji_bar_typeId 3
#define sji_foo_typeId 4
#define sjs_class_i32_heap_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class_i32 sjs_class_i32;
typedef struct td_sji_bar sji_bar;
typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_class_i32_heap sjs_class_i32_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_class_i32 {
    int structsNeedAValue;
};

struct td_sji_bar {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test2)(void* _parent, int32_t* _return);
};

struct td_sji_foo {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test1)(void* _parent, int32_t* _return);
};

struct td_sjs_class_i32_heap {
    intptr_t _refCount;
};

sjs_class_i32_heap* sjt_cast1;
sji_foo* sjt_cast2;
sji_foo* sjt_dot1;
bool sjt_ifElse1;
sji_bar* sjt_isEmpty1;
sji_foo* sjv_a;
sji_bar* sjv_b;
int32_t void1;

void sjf_class_i32(sjs_class_i32* _this);
sjs_object* sjf_class_i32_asInterface(sjs_class_i32* _this, int typeId);
sji_bar* sjf_class_i32_as_sji_bar(sjs_class_i32* _this);
sji_foo* sjf_class_i32_as_sji_foo(sjs_class_i32* _this);
void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from);
void sjf_class_i32_destroy(sjs_class_i32* _this);
void sjf_class_i32_heap(sjs_class_i32_heap* _this);
sjs_object* sjf_class_i32_heap_asInterface(sjs_class_i32_heap* _this, int typeId);
sji_bar* sjf_class_i32_heap_as_sji_bar(sjs_class_i32_heap* _this);
sji_foo* sjf_class_i32_heap_as_sji_foo(sjs_class_i32_heap* _this);
void sjf_class_i32_test1(sjs_class_i32* _parent, int32_t* _return);
void sjf_class_i32_test2(sjs_class_i32* _parent, int32_t* _return);
void sji_bar_copy(sji_bar* _this, sji_bar* _from);
void sji_bar_destroy(sji_bar* _this);
void sji_foo_copy(sji_foo* _this, sji_foo* _from);
void sji_foo_destroy(sji_foo* _this);
void main_destroy(void);

void sjf_class_i32(sjs_class_i32* _this) {
}

sjs_object* sjf_class_i32_asInterface(sjs_class_i32* _this, int typeId) {
    switch (typeId) {
        case sji_bar_typeId:  {
            return (sjs_object*)sjf_class_i32_as_sji_bar(_this);
        }

        case sji_foo_typeId:  {
            return (sjs_object*)sjf_class_i32_as_sji_foo(_this);
        }
    }

    return 0;
}

sji_bar* sjf_class_i32_as_sji_bar(sjs_class_i32* _this) {
    sji_bar* _interface;
    _interface = (sji_bar*)malloc(sizeof(sji_bar));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_i32_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_i32_asInterface;
    _interface->test2 = (void(*)(void*, int32_t*))sjf_class_i32_test2;

    return _interface;
}

sji_foo* sjf_class_i32_as_sji_foo(sjs_class_i32* _this) {
    sji_foo* _interface;
    _interface = (sji_foo*)malloc(sizeof(sji_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_i32_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_i32_asInterface;
    _interface->test1 = (void(*)(void*, int32_t*))sjf_class_i32_test1;

    return _interface;
}

void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from) {
}

void sjf_class_i32_destroy(sjs_class_i32* _this) {
}

void sjf_class_i32_heap(sjs_class_i32_heap* _this) {
}

sjs_object* sjf_class_i32_heap_asInterface(sjs_class_i32_heap* _this, int typeId) {
    switch (typeId) {
        case sji_bar_typeId:  {
            return (sjs_object*)sjf_class_i32_heap_as_sji_bar(_this);
        }

        case sji_foo_typeId:  {
            return (sjs_object*)sjf_class_i32_heap_as_sji_foo(_this);
        }
    }

    return 0;
}

sji_bar* sjf_class_i32_heap_as_sji_bar(sjs_class_i32_heap* _this) {
    sji_bar* _interface;
    _interface = (sji_bar*)malloc(sizeof(sji_bar));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_i32_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_i32_heap_asInterface;
    _interface->test2 = (void(*)(void*, int32_t*))sjf_class_i32_test2;

    return _interface;
}

sji_foo* sjf_class_i32_heap_as_sji_foo(sjs_class_i32_heap* _this) {
    sji_foo* _interface;
    _interface = (sji_foo*)malloc(sizeof(sji_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_i32_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_i32_heap_asInterface;
    _interface->test1 = (void(*)(void*, int32_t*))sjf_class_i32_test1;

    return _interface;
}

void sjf_class_i32_test1(sjs_class_i32* _parent, int32_t* _return) {
    (*_return) = 1;
}

void sjf_class_i32_test2(sjs_class_i32* _parent, int32_t* _return) {
    (*_return) = 2;
}

void sji_bar_copy(sji_bar* _this, sji_bar* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->test2 = _from->test2;
}

void sji_bar_destroy(sji_bar* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

void sji_foo_copy(sji_foo* _this, sji_foo* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->test1 = _from->test1;
}

void sji_foo_destroy(sji_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
    sjt_cast1 = (sjs_class_i32_heap*)malloc(sizeof(sjs_class_i32_heap));
    sjt_cast1->_refCount = 1;
    sjf_class_i32_heap(sjt_cast1);
    sjv_a = (sji_foo*)sjf_class_i32_heap_as_sji_foo(sjt_cast1);
    sjt_dot1 = sjv_a;
    sjt_dot1->test1((void*)(((char*)sjt_dot1->_parent) + sizeof(intptr_t)), &void1);
    sjt_cast2 = sjv_a;
    sjt_cast2->_refCount++;
    sjv_b = (sji_bar*)sjt_cast2->asInterface(sjt_cast2->_parent, sji_bar_typeId);
    sjt_isEmpty1 = sjv_b;
    if (sjt_isEmpty1 != 0) {
        sjt_isEmpty1->_refCount++;
    }

    sjt_ifElse1 = (sjt_isEmpty1 == 0);
    if (sjt_ifElse1) {
    } else {
        sji_bar* sjt_dot2;
        sji_bar* sjt_getValue1;
        int32_t sjt_value1;
        int32_option value1;

        sjt_getValue1 = sjv_b;
        if (sjt_getValue1 != 0) {
            sjt_getValue1->_refCount++;
        }

        sjt_dot2 = sjt_getValue1;
        sjt_dot2->test2((void*)(((char*)sjt_dot2->_parent) + sizeof(intptr_t)), &sjt_value1);
        value1.isEmpty = false;
        value1.value = sjt_value1;

        if (sjt_getValue1 != 0) {
            sjt_getValue1->_refCount--;
            if (sjt_getValue1->_refCount <= 0) {
                sji_bar_destroy(sjt_getValue1);
            }
        }
    }
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_cast1->_refCount--;
    if (sjt_cast1->_refCount <= 0) {
        sjf_class_i32_destroy((sjs_class_i32*)(((char*)sjt_cast1) + sizeof(intptr_t)));
    }
    sjt_cast2->_refCount--;
    if (sjt_cast2->_refCount <= 0) {
        sji_foo_destroy(sjt_cast2);
    }
    if (sjt_isEmpty1 != 0) {
        sjt_isEmpty1->_refCount--;
        if (sjt_isEmpty1->_refCount <= 0) {
            sji_bar_destroy(sjt_isEmpty1);
        }
    }
    sjv_a->_refCount--;
    if (sjv_a->_refCount <= 0) {
        sji_foo_destroy(sjv_a);
    }
    if (sjv_b != 0) {
        sjv_b->_refCount--;
        if (sjv_b->_refCount <= 0) {
            sji_bar_destroy(sjv_b);
        }
    }
}
