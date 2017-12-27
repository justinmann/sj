#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sji_foo_vtbl_typeId 2
#define sji_foo_typeId 3
#define sjs_class_typeId 4

typedef struct td_sjs_log sjs_log;
typedef struct td_sji_foo_vtbl sji_foo_vtbl;
typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_class sjs_class;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
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
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
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
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_class(sjs_class* _this);
void sjf_class_as_sji_foo(sjs_class* _this, sji_foo* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_getx(sjs_class* _parent, int32_t* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_i32_add_hash_foo(int32_t x, sji_foo y, int32_t* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
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
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_getx(sjs_class* _parent, int32_t* _return) {
    (*_return) = _parent->x;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_i32_add_hash_foo(int32_t x, sji_foo y, int32_t* _return) {
    int32_t sjt_capture1;
    sji_foo sjt_parent1 = { 0 };

    sjt_parent1 = y;
    sjt_parent1._vtbl->getx(sjt_parent1._parent, &sjt_capture1);
    (*_return) = x + sjt_capture1;
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
    sjs_class_foo_vtbl.getx = (void(*)(sjs_object*, int32_t*))sjf_class_getx;
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
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
;
    if (sjt_call2._refCount == 1) { sjf_class_destroy(&sjt_call2); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
