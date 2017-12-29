#include <lib/common/common.h>

#define sjs_log_typeId 15
#define sjs_class_typeId 18
#define sjs_bob_typeId 16
#define sji_foo_typeId 19
#define cb_bob_heap_bob_typeId 20
#define cb_bob_heap_bob_heap_typeId 20

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_bob sjs_bob;
typedef struct td_sji_foo_vtbl sji_foo_vtbl;
typedef struct td_sji_foo sji_foo;
typedef struct td_cb_bob_heap_bob cb_bob_heap_bob;
typedef struct td_cb_bob_heap_bob_heap cb_bob_heap_bob_heap;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
    int32_t bar;
};

struct td_sjs_bob {
    int _refCount;
    int32_t x;
};

struct td_sji_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*getbar)(sjs_object* _parent, sjs_bob* _return);
    void (*getbar_heap)(sjs_object* _parent, sjs_bob** _return);
};

struct td_sji_foo {
    sjs_object* _parent;
    sji_foo_vtbl* _vtbl;
};

struct td_cb_bob_heap_bob {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_bob* _return);
    void (*_cb_heap)(sjs_object* _parent, sjs_bob** _return);
};

struct td_cb_bob_heap_bob_heap {
    cb_bob_heap_bob inner;
    void (*_destroy)(sjs_object*);
};

sji_foo_vtbl sjs_class_foo_vtbl;
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_class sjt_call1 = { -1 };
sjs_class* sjt_cast1 = 0;
sjs_bob sjv_a = { -1 };
sjs_bob* sjv_b = 0;
cb_bob_heap_bob sjv_cb;
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
sji_foo sjv_f = { 0 };
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_bob(sjs_bob* _this);
void sjf_bob_copy(sjs_bob* _this, sjs_bob* _from);
void sjf_bob_destroy(sjs_bob* _this);
void sjf_bob_heap(sjs_bob* _this);
void sjf_class(sjs_class* _this);
void sjf_class_as_sji_foo(sjs_class* _this, sji_foo* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_getbar(sjs_class* _parent, sjs_bob* _return);
void sjf_class_getbar_heap(sjs_class* _parent, sjs_bob** _return);
void sjf_class_getclasstype(sjs_object* _this, int* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_bob(sjs_bob* _this) {
}

void sjf_bob_copy(sjs_bob* _this, sjs_bob* _from) {
    _this->x = _from->x;
}

void sjf_bob_destroy(sjs_bob* _this) {
}

void sjf_bob_heap(sjs_bob* _this) {
}

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

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->bar = _from->bar;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_getbar(sjs_class* _parent, sjs_bob* _return) {
    _return->_refCount = 1;
    _return->x = _parent->bar;
    sjf_bob(_return);
}

void sjf_class_getbar_heap(sjs_class* _parent, sjs_bob** _return) {
    (*_return) = (sjs_bob*)malloc(sizeof(sjs_bob));
    (*_return)->_refCount = 1;
    (*_return)->x = _parent->bar;
    sjf_bob_heap((*_return));
}

void sjf_class_getclasstype(sjs_object* _this, int* _return) {
    *_return = 18;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
    _this->minlevel = _from->minlevel;
}

void sjf_log_destroy(sjs_log* _this) {
}

void sjf_log_heap(sjs_log* _this) {
}

int main(int argc, char** argv) {
    sjs_class_foo_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
    sjs_class_foo_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_class_getclasstype;
    sjs_class_foo_vtbl.getbar = (void(*)(sjs_object*, sjs_bob*))sjf_class_getbar;
    sjs_class_foo_vtbl.getbar_heap = (void(*)(sjs_object*, sjs_bob**))sjf_class_getbar_heap;
    sjv_loglevel_trace = 0;
    sjv_loglevel_debug = 1;
    sjv_loglevel_info = 2;
    sjv_loglevel_warn = 3;
    sjv_loglevel_error = 4;
    sjv_loglevel_fatal = 5;
    sjv_f32_pi = 3.14159265358979323846f;
    sjv_u32_maxvalue = (uint32_t)4294967295u;
    result1 = -1;
    sjv_i32_maxvalue = result1 - 2147483647;
    sjv_i32_minvalue = 2147483647;
    sjv_log._refCount = 1;
    sjv_log.minlevel = sjv_loglevel_warn;
    sjf_log(&sjv_log);
    sjv_emptystringdata = 0;
    sjv_emptystringdata = "";
    ptr_init();
    weakptr_init();
    sjv_clocks_per_sec = 0;
    sjv_clocks_per_sec = CLOCKS_PER_SEC;
    sjt_call1._refCount = 1;
    sjt_call1.bar = 0;
    sjf_class(&sjt_call1);
    sjt_cast1 = &sjt_call1;
    sjf_class_as_sji_foo(sjt_cast1, &sjv_f);
    delete_cb weakptrcb1 = { &sjv_f._parent, weakptr_clear };
    if (sjv_f._parent != 0) { weakptr_cb_add(sjv_f._parent, weakptrcb1); }
    if (sjv_f._parent != 0) {
        sji_foo sjt_capture1 = { 0 };
        cb_bob_heap_bob sjt_value1;

        sjt_capture1 = sjv_f;
        sjt_value1._parent = sjt_capture1._parent;
        sjt_value1._cb = sjt_capture1._vtbl->getbar;
        sjt_value1._cb_heap = sjt_capture1._vtbl->getbar_heap;
        sjv_cb = sjt_value1;
    } else {
        sjv_cb._parent = 0;
    }

    sjv_cb._cb(sjv_cb._parent, &sjv_a);
    sjv_cb._cb_heap(sjv_cb._parent, &sjv_b);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjv_b->_refCount--;
    if (sjv_b->_refCount <= 0) {
        weakptr_release(sjv_b);
        sjf_bob_destroy(sjv_b);
        free(sjv_b);
    }
    delete_cb weakptrcb2 = { &sjv_f._parent, weakptr_clear };
    if (sjv_f._parent != 0) { weakptr_cb_remove(sjv_f._parent, weakptrcb2); }
    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
;
    if (sjv_a._refCount == 1) { sjf_bob_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
