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
#define sji_foo_vtbl_typeId 3
#define sji_foo_typeId 4
#define sjs_class_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sji_foo_vtbl sji_foo_vtbl;
typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sji_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getx)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_foo {
    sjs_object* _parent;
    sji_foo_vtbl* _vtbl;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

sji_foo_vtbl sjs_class_foo_vtbl;
sjs_class sjt_call1 = { -1 };
sjs_class sjt_call2 = { -1 };
sjs_class* sjt_cast1 = 0;
sjs_class* sjt_cast2 = 0;
int32_t sjt_functionParam1;
sji_foo sjt_functionParam2 = { 0 };
int32_t sjt_functionParam3;
sji_foo sjt_functionParam4 = { 0 };
int32_t sjv_a;
int32_t sjv_b;

void sjf_class(sjs_class* _this);
void sjf_class_as_sji_foo(sjs_class* _this, sji_foo* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_getx(sjs_class* _parent, int32_t* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_class_heap_as_sji_foo(sjs_class* _this, sji_foo* _return);
void sjf_class_heap_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_i32_add_hash_foo(int32_t x, sji_foo y, int32_t* _return);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_as_sji_foo(sjs_class* _this, sji_foo* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_foo_vtbl;
}

void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_foo_typeId:  {
            sjf_class_as_sji_foo(_this, (sji_foo*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_getx(sjs_class* _parent, int32_t* _return) {
    sjs_class* sjt_dot1 = 0;

    sjt_dot1 = _parent;
    (*_return) = (sjt_dot1)->x;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_heap_as_sji_foo(sjs_class* _this, sji_foo* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_foo_vtbl;
}

void sjf_class_heap_asinterface(sjs_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_foo_typeId:  {
            sjf_class_heap_as_sji_foo(_this, (sji_foo*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_i32_add_hash_foo(int32_t x, sji_foo y, int32_t* _return) {
    int32_t sjt_math1;
    int32_t sjt_math2;
    sji_foo sjt_parent1 = { 0 };

    sjt_math1 = x;
    sjt_parent1 = y;
    sjt_parent1._vtbl->getx(sjt_parent1._parent, &sjt_math2);
    (*_return) = sjt_math1 + sjt_math2;
}

int main(int argc, char** argv) {
    sjs_class_foo_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
    sjs_class_foo_vtbl.getx = (void(*)(sjs_object*, int32_t*))sjf_class_getx;
    sjt_functionParam1 = 1;
    sjt_call1._refCount = 1;
    sjt_call1.x = 2;
    sjf_class(&sjt_call1);
    sjt_cast1 = &sjt_call1;
    sjf_class_as_sji_foo(sjt_cast1, &sjt_functionParam2);
    sjf_i32_add_hash_foo(sjt_functionParam1, sjt_functionParam2, &sjv_a);
    sjt_functionParam3 = 1;
    sjt_call2._refCount = 1;
    sjt_call2.x = 2;
    sjf_class(&sjt_call2);
    sjt_cast2 = &sjt_call2;
    sjf_class_as_sji_foo(sjt_cast2, &sjt_functionParam4);
    sjf_i32_add_hash_foo(sjt_functionParam3, sjt_functionParam4, &sjv_b);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
    if (sjt_call2._refCount == 1) { sjf_class_destroy(&sjt_call2); }
}
