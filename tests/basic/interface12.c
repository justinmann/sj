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
#define sjs_foo_typeId 3
#define sji_bar_vtbl_typeId 4
#define sji_bar_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_foo sjs_foo;
typedef struct td_sji_bar_vtbl sji_bar_vtbl;
typedef struct td_sji_bar sji_bar;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_foo {
    int _refCount;
};

struct td_sji_bar_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getx)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_bar {
    sjs_object* _parent;
    sji_bar_vtbl* _vtbl;
};

sji_bar_vtbl sjs_foo_bar_vtbl;
sjs_foo* sjt_cast1 = 0;
sjs_foo* sjv_a = 0;
sji_bar sjv_b = { 0 };

void sjf_foo(sjs_foo* _this);
void sjf_foo_as_sji_bar(sjs_foo* _this, sji_bar* _return);
void sjf_foo_asinterface(sjs_foo* _this, int typeId, sjs_interface* _return);
void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from);
void sjf_foo_destroy(sjs_foo* _this);
void sjf_foo_getx(sjs_foo* _parent, int32_t* _return);
void sjf_foo_heap(sjs_foo* _this);
void sjf_foo_heap_as_sji_bar(sjs_foo* _this, sji_bar* _return);
void sjf_foo_heap_asinterface(sjs_foo* _this, int typeId, sjs_interface* _return);
void main_destroy(void);

void sjf_foo(sjs_foo* _this) {
}

void sjf_foo_as_sji_bar(sjs_foo* _this, sji_bar* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_foo_bar_vtbl;
}

void sjf_foo_asinterface(sjs_foo* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_bar_typeId:  {
            sjf_foo_as_sji_bar(_this, (sji_bar*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from) {
}

void sjf_foo_destroy(sjs_foo* _this) {
}

void sjf_foo_getx(sjs_foo* _parent, int32_t* _return) {
    (*_return) = 0;
}

void sjf_foo_heap(sjs_foo* _this) {
}

void sjf_foo_heap_as_sji_bar(sjs_foo* _this, sji_bar* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_foo_bar_vtbl;
}

void sjf_foo_heap_asinterface(sjs_foo* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_bar_typeId:  {
            sjf_foo_heap_as_sji_bar(_this, (sji_bar*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

int main(int argc, char** argv) {
    sjs_foo_bar_vtbl.destroy = (void(*)(void*))sjf_foo_destroy;
    sjs_foo_bar_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_foo_asinterface;
    sjs_foo_bar_vtbl.getx = (void(*)(sjs_object*, int32_t*))sjf_foo_getx;
    sjv_a = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_a->_refCount = 1;
    sjf_foo_heap(sjv_a);
    sjt_cast1 = sjv_a;
    sjf_foo_as_sji_bar(sjt_cast1, &sjv_b);
    if (sjv_b._parent != 0) {
        sjv_b._parent->_refCount++;
    }
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjv_a->_refCount--;
    if (sjv_a->_refCount <= 0) {
        weakptr_release(sjv_a);
        sjf_foo_destroy(sjv_a);
        free(sjv_a);
    }
    if (sjv_b._parent != 0) {
        sjv_b._parent->_refCount--;
        if (sjv_b._parent->_refCount <= 0) {
            sjv_b._vtbl->destroy(sjv_b._parent);
            free(sjv_b._parent);
        }
    }
}
