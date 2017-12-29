#include <lib/common/common.h>

#define sjs_log_typeId 16
#define sjs_class_typeId 18
#define sjs_bar_typeId 15
#define sji_foo_typeId 19

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_bar sjs_bar;
typedef struct td_sji_foo_vtbl sji_foo_vtbl;
typedef struct td_sji_foo sji_foo;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
};

struct td_sjs_bar {
    int _refCount;
};

struct td_sji_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*test)(sjs_object* _parent, int32_t a, sjs_bar* _return);
    void (*test_heap)(sjs_object* _parent, int32_t a, sjs_bar** _return);
};

struct td_sji_foo {
    sjs_object* _parent;
    sji_foo_vtbl* _vtbl;
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
int32_t sjt_interfaceParam1;
int32_t sjt_interfaceParam2;
sji_foo sjt_parent1 = { 0 };
sji_foo sjt_parent2 = { 0 };
sji_foo sjv_a = { 0 };
sjs_bar sjv_b = { -1 };
sjs_bar* sjv_c = 0;
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_bar(sjs_bar* _this);
void sjf_bar_copy(sjs_bar* _this, sjs_bar* _from);
void sjf_bar_destroy(sjs_bar* _this);
void sjf_bar_heap(sjs_bar* _this);
void sjf_class(sjs_class* _this);
void sjf_class_as_sji_foo(sjs_class* _this, sji_foo* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_getclasstype(sjs_object* _this, int* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_class_test(sjs_class* _parent, int32_t a, sjs_bar* _return);
void sjf_class_test_heap(sjs_class* _parent, int32_t a, sjs_bar** _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
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
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_getclasstype(sjs_object* _this, int* _return) {
    *_return = 18;
}

void sjf_class_heap(sjs_class* _this) {
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
    sjs_class_foo_vtbl.test = (void(*)(sjs_object*,int32_t, sjs_bar*))sjf_class_test;
    sjs_class_foo_vtbl.test_heap = (void(*)(sjs_object*,int32_t, sjs_bar**))sjf_class_test_heap;
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
    sjf_class(&sjt_call1);
    sjt_cast1 = &sjt_call1;
    sjf_class_as_sji_foo(sjt_cast1, &sjv_a);
    sjt_parent1 = sjv_a;
    sjt_interfaceParam1 = 1;
    sjv_b._refCount = 1;
    sjt_parent1._vtbl->test(sjt_parent1._parent, sjt_interfaceParam1, &sjv_b);
    sjt_parent2 = sjv_a;
    sjt_interfaceParam2 = 1;
    sjv_c = (sjs_bar*)malloc(sizeof(sjs_bar));
    sjv_c->_refCount = 1;
    sjt_parent2._vtbl->test_heap(sjt_parent2._parent, sjt_interfaceParam2, &sjv_c);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_bar_destroy(sjv_c);
        free(sjv_c);
    }
    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
;
    if (sjv_b._refCount == 1) { sjf_bar_destroy(&sjv_b); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
