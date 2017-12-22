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
#define sjs_func_typeId 3
#define sji_bar_vtbl_typeId 4
#define sji_bar_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_func sjs_func;
typedef struct td_sji_bar_vtbl sji_bar_vtbl;
typedef struct td_sji_bar sji_bar;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_func {
    int _refCount;
};

struct td_sji_bar_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
};

struct td_sji_bar {
    sjs_object* _parent;
    sji_bar_vtbl* _vtbl;
};

sji_bar_vtbl sjs_func_bar_vtbl;
sjs_func* sjv_a = 0;
sji_bar sjv_c = { 0 };

void sjf_func_copy(sjs_func* _this, sjs_func* _from);
void sjf_func_destroy(sjs_func* _this);
void sjf_func_heap(sjs_func* _this);
void sjf_func_heap_as_sji_bar(sjs_func* _this, sji_bar* _return);
void sjf_func_heap_asinterface(sjs_func* _this, int typeId, sjs_interface* _return);
void main_destroy(void);

void sjf_func_copy(sjs_func* _this, sjs_func* _from) {
}

void sjf_func_destroy(sjs_func* _this) {
}

void sjf_func_heap(sjs_func* _this) {
    sjs_func* sjt_cast1 = 0;

    sjt_cast1 = _this;
    sjf_func_as_sji_bar(sjt_cast1, &sjv_c);
    delete_cb weakptrcb1 = { &sjv_c._parent, weakptr_clear };
    if (sjv_c._parent != 0) { weakptr_cb_add(sjv_c._parent, weakptrcb1); }
}

void sjf_func_heap_as_sji_bar(sjs_func* _this, sji_bar* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_func_bar_vtbl;
}

void sjf_func_heap_asinterface(sjs_func* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_bar_typeId:  {
            sjf_func_heap_as_sji_bar(_this, (sji_bar*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

int main(int argc, char** argv) {
    sjs_func_bar_vtbl.destroy = (void(*)(void*))sjf_func_destroy;
    sjs_func_bar_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_func_heap_asinterface;
    sjv_c._parent = 0;
    sjv_a = (sjs_func*)malloc(sizeof(sjs_func));
    sjv_a->_refCount = 1;
    sjf_func_heap(sjv_a);
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
        sjf_func_destroy(sjv_a);
        free(sjv_a);
    }
    delete_cb weakptrcb2 = { &sjv_c._parent, weakptr_clear };
    if (sjv_c._parent != 0) { weakptr_cb_remove(sjv_c._parent, weakptrcb2); }
}
