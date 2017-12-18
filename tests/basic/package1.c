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
#define sjs_a_class_typeId 2
#define sji_a_foo_typeId 3
#define sjs_b_class_typeId 4
#define sji_b_foo_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_a_class sjs_a_class;
typedef struct td_sji_a_foo sji_a_foo;
typedef struct td_sjs_b_class sjs_b_class;
typedef struct td_sji_b_foo sji_b_foo;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_a_class {
    int _refCount;
};

struct td_sji_a_foo {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*bar)(void* _parent, int32_t* _return);
};

struct td_sjs_b_class {
    int _refCount;
};

struct td_sji_b_foo {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*bar)(void* _parent, int32_t* _return);
};

sjs_a_class* sjt_cast1 = 0;
sjs_b_class* sjt_cast2 = 0;
sji_a_foo* sjt_parent1 = 0;
sji_b_foo* sjt_parent2 = 0;
int32_t sjv_a_x;
int32_t sjv_b;
int32_t sjv_b_d;
int32_t sjv_b_x;
int32_t sjv_c;
sji_a_foo* sjv_e = 0;
int32_t sjv_f;
sji_b_foo* sjv_h = 0;
int32_t sjv_i;
int32_t sjv_y;

void sjf_a_class(sjs_a_class* _this);
void sjf_a_class_a_bar(sjs_a_class* _parent, int32_t* _return);
sjs_object* sjf_a_class_asInterface(sjs_a_class* _this, int typeId);
sji_a_foo* sjf_a_class_as_sji_a_foo(sjs_a_class* _this);
void sjf_a_class_copy(sjs_a_class* _this, sjs_a_class* _from);
void sjf_a_class_destroy(sjs_a_class* _this);
void sjf_a_class_heap(sjs_a_class* _this);
sjs_object* sjf_a_class_heap_asInterface(sjs_a_class* _this, int typeId);
sji_a_foo* sjf_a_class_heap_as_sji_a_foo(sjs_a_class* _this);
void sjf_a_func(int32_t* _return);
void sjf_b_class(sjs_b_class* _this);
sjs_object* sjf_b_class_asInterface(sjs_b_class* _this, int typeId);
sji_b_foo* sjf_b_class_as_sji_b_foo(sjs_b_class* _this);
void sjf_b_class_b_bar(sjs_b_class* _parent, int32_t* _return);
void sjf_b_class_copy(sjs_b_class* _this, sjs_b_class* _from);
void sjf_b_class_destroy(sjs_b_class* _this);
void sjf_b_class_heap(sjs_b_class* _this);
sjs_object* sjf_b_class_heap_asInterface(sjs_b_class* _this, int typeId);
sji_b_foo* sjf_b_class_heap_as_sji_b_foo(sjs_b_class* _this);
void sjf_b_func(int32_t* _return);
void sji_a_foo_copy(sji_a_foo* _this, sji_a_foo* _from);
void sji_a_foo_destroy(sji_a_foo* _this);
void sji_b_foo_copy(sji_b_foo* _this, sji_b_foo* _from);
void sji_b_foo_destroy(sji_b_foo* _this);
void main_destroy(void);

void sjf_a_class(sjs_a_class* _this) {
}

void sjf_a_class_a_bar(sjs_a_class* _parent, int32_t* _return) {
    sjf_a_func(_return);
}

sjs_object* sjf_a_class_asInterface(sjs_a_class* _this, int typeId) {
    switch (typeId) {
        case sji_a_foo_typeId:  {
            return (sjs_object*)sjf_a_class_as_sji_a_foo(_this);
        }
    }

    return 0;
}

sji_a_foo* sjf_a_class_as_sji_a_foo(sjs_a_class* _this) {
    sji_a_foo* _interface;
    _interface = (sji_a_foo*)malloc(sizeof(sji_a_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_a_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_a_class_asInterface;
    _interface->bar = (void(*)(void*, int32_t*))sjf_a_class_a_bar;

    return _interface;
}

void sjf_a_class_copy(sjs_a_class* _this, sjs_a_class* _from) {
}

void sjf_a_class_destroy(sjs_a_class* _this) {
}

void sjf_a_class_heap(sjs_a_class* _this) {
}

sjs_object* sjf_a_class_heap_asInterface(sjs_a_class* _this, int typeId) {
    switch (typeId) {
        case sji_a_foo_typeId:  {
            return (sjs_object*)sjf_a_class_heap_as_sji_a_foo(_this);
        }
    }

    return 0;
}

sji_a_foo* sjf_a_class_heap_as_sji_a_foo(sjs_a_class* _this) {
    sji_a_foo* _interface;
    _interface = (sji_a_foo*)malloc(sizeof(sji_a_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_a_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_a_class_heap_asInterface;
    _interface->bar = (void(*)(void*, int32_t*))sjf_a_class_a_bar;

    return _interface;
}

void sjf_a_func(int32_t* _return) {
    (*_return) = sjv_a_x;
}

void sjf_b_class(sjs_b_class* _this) {
}

sjs_object* sjf_b_class_asInterface(sjs_b_class* _this, int typeId) {
    switch (typeId) {
        case sji_b_foo_typeId:  {
            return (sjs_object*)sjf_b_class_as_sji_b_foo(_this);
        }
    }

    return 0;
}

sji_b_foo* sjf_b_class_as_sji_b_foo(sjs_b_class* _this) {
    sji_b_foo* _interface;
    _interface = (sji_b_foo*)malloc(sizeof(sji_b_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_b_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_b_class_asInterface;
    _interface->bar = (void(*)(void*, int32_t*))sjf_b_class_b_bar;

    return _interface;
}

void sjf_b_class_b_bar(sjs_b_class* _parent, int32_t* _return) {
    sjf_b_func(_return);
}

void sjf_b_class_copy(sjs_b_class* _this, sjs_b_class* _from) {
}

void sjf_b_class_destroy(sjs_b_class* _this) {
}

void sjf_b_class_heap(sjs_b_class* _this) {
}

sjs_object* sjf_b_class_heap_asInterface(sjs_b_class* _this, int typeId) {
    switch (typeId) {
        case sji_b_foo_typeId:  {
            return (sjs_object*)sjf_b_class_heap_as_sji_b_foo(_this);
        }
    }

    return 0;
}

sji_b_foo* sjf_b_class_heap_as_sji_b_foo(sjs_b_class* _this) {
    sji_b_foo* _interface;
    _interface = (sji_b_foo*)malloc(sizeof(sji_b_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_b_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_b_class_heap_asInterface;
    _interface->bar = (void(*)(void*, int32_t*))sjf_b_class_b_bar;

    return _interface;
}

void sjf_b_func(int32_t* _return) {
    (*_return) = sjv_b_x;
}

void sji_a_foo_copy(sji_a_foo* _this, sji_a_foo* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->bar = _from->bar;
}

void sji_a_foo_destroy(sji_a_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

void sji_b_foo_copy(sji_b_foo* _this, sji_b_foo* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->bar = _from->bar;
}

void sji_b_foo_destroy(sji_b_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
    sjv_a_x = 0;
    sjv_b_x = 1;
    sjv_b_d = 12;
    sjv_b = sjv_b_x;
    sjf_b_func(&sjv_c);
    sjv_y = 0;
    sjt_cast1 = (sjs_a_class*)malloc(sizeof(sjs_a_class));
    sjt_cast1->_refCount = 1;
    sjf_a_class_heap(sjt_cast1);
    sjv_e = (sji_a_foo*)sjf_a_class_heap_as_sji_a_foo(sjt_cast1);
    sjt_parent1 = sjv_e;
    sjt_parent1->bar(sjt_parent1->_parent, &sjv_f);
    sjt_cast2 = (sjs_b_class*)malloc(sizeof(sjs_b_class));
    sjt_cast2->_refCount = 1;
    sjf_b_class_heap(sjt_cast2);
    sjv_h = (sji_b_foo*)sjf_b_class_heap_as_sji_b_foo(sjt_cast2);
    sjt_parent2 = sjv_h;
    sjt_parent2->bar(sjt_parent2->_parent, &sjv_i);
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
        weakptr_release(sjt_cast1);
        sjf_a_class_destroy(sjt_cast1);
    }
    sjt_cast2->_refCount--;
    if (sjt_cast2->_refCount <= 0) {
        weakptr_release(sjt_cast2);
        sjf_b_class_destroy(sjt_cast2);
    }
    sjv_e->_refCount--;
    if (sjv_e->_refCount <= 0) {
        weakptr_release(sjv_e);
        sji_a_foo_destroy(sjv_e);
    }
    sjv_h->_refCount--;
    if (sjv_h->_refCount <= 0) {
        weakptr_release(sjv_h);
        sji_b_foo_destroy(sjv_h);
    }
}
