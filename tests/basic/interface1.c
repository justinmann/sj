#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_namespace1_class_typeId 2
#define sji_namespace1_foo_vtbl_typeId 3
#define sji_namespace1_foo_typeId 4
#define sjs_namespace2_class_typeId 5
#define sji_namespace2_foo_vtbl_typeId 6
#define sji_namespace2_foo_typeId 7

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_namespace1_class sjs_namespace1_class;
typedef struct td_sji_namespace1_foo_vtbl sji_namespace1_foo_vtbl;
typedef struct td_sji_namespace1_foo sji_namespace1_foo;
typedef struct td_sjs_namespace2_class sjs_namespace2_class;
typedef struct td_sji_namespace2_foo_vtbl sji_namespace2_foo_vtbl;
typedef struct td_sji_namespace2_foo sji_namespace2_foo;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_namespace1_class {
    int _refCount;
};

struct td_sji_namespace1_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*test1)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_namespace1_foo {
    sjs_object* _parent;
    sji_namespace1_foo_vtbl* _vtbl;
};

struct td_sjs_namespace2_class {
    int _refCount;
};

struct td_sji_namespace2_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*test2)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_namespace2_foo {
    sjs_object* _parent;
    sji_namespace2_foo_vtbl* _vtbl;
};

sji_namespace1_foo_vtbl sjs_namespace1_class_foo_vtbl;
sji_namespace2_foo_vtbl sjs_namespace2_class_foo_vtbl;
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_namespace1_class sjt_call1 = { -1 };
sjs_namespace2_class sjt_call2 = { -1 };
sjs_namespace1_class* sjt_cast1 = 0;
sjs_namespace2_class* sjt_cast2 = 0;
sji_namespace1_foo sjv_a = { 0 };
sji_namespace2_foo sjv_b = { 0 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_namespace1_class(sjs_namespace1_class* _this);
void sjf_namespace1_class_as_sji_namespace1_foo(sjs_namespace1_class* _this, sji_namespace1_foo* _return);
void sjf_namespace1_class_asinterface(sjs_namespace1_class* _this, int typeId, sjs_interface* _return);
void sjf_namespace1_class_copy(sjs_namespace1_class* _this, sjs_namespace1_class* _from);
void sjf_namespace1_class_destroy(sjs_namespace1_class* _this);
void sjf_namespace1_class_heap(sjs_namespace1_class* _this);
void sjf_namespace1_class_namespace1_test1(sjs_namespace1_class* _parent, int32_t* _return);
void sjf_namespace2_class(sjs_namespace2_class* _this);
void sjf_namespace2_class_as_sji_namespace2_foo(sjs_namespace2_class* _this, sji_namespace2_foo* _return);
void sjf_namespace2_class_asinterface(sjs_namespace2_class* _this, int typeId, sjs_interface* _return);
void sjf_namespace2_class_copy(sjs_namespace2_class* _this, sjs_namespace2_class* _from);
void sjf_namespace2_class_destroy(sjs_namespace2_class* _this);
void sjf_namespace2_class_heap(sjs_namespace2_class* _this);
void sjf_namespace2_class_namespace2_test2(sjs_namespace2_class* _parent, int32_t* _return);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
    _this->minlevel = _from->minlevel;
}

void sjf_log_destroy(sjs_log* _this) {
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_namespace1_class(sjs_namespace1_class* _this) {
}

void sjf_namespace1_class_as_sji_namespace1_foo(sjs_namespace1_class* _this, sji_namespace1_foo* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_namespace1_class_foo_vtbl;
}

void sjf_namespace1_class_asinterface(sjs_namespace1_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_namespace1_foo_typeId:  {
            sjf_namespace1_class_as_sji_namespace1_foo(_this, (sji_namespace1_foo*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_namespace1_class_copy(sjs_namespace1_class* _this, sjs_namespace1_class* _from) {
}

void sjf_namespace1_class_destroy(sjs_namespace1_class* _this) {
}

void sjf_namespace1_class_heap(sjs_namespace1_class* _this) {
}

void sjf_namespace1_class_namespace1_test1(sjs_namespace1_class* _parent, int32_t* _return) {
    (*_return) = 5;
}

void sjf_namespace2_class(sjs_namespace2_class* _this) {
}

void sjf_namespace2_class_as_sji_namespace2_foo(sjs_namespace2_class* _this, sji_namespace2_foo* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_namespace2_class_foo_vtbl;
}

void sjf_namespace2_class_asinterface(sjs_namespace2_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_namespace2_foo_typeId:  {
            sjf_namespace2_class_as_sji_namespace2_foo(_this, (sji_namespace2_foo*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_namespace2_class_copy(sjs_namespace2_class* _this, sjs_namespace2_class* _from) {
}

void sjf_namespace2_class_destroy(sjs_namespace2_class* _this) {
}

void sjf_namespace2_class_heap(sjs_namespace2_class* _this) {
}

void sjf_namespace2_class_namespace2_test2(sjs_namespace2_class* _parent, int32_t* _return) {
    (*_return) = 5;
}

int main(int argc, char** argv) {
    sjs_namespace1_class_foo_vtbl.destroy = (void(*)(void*))sjf_namespace1_class_destroy;
    sjs_namespace1_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_namespace1_class_asinterface;
    sjs_namespace1_class_foo_vtbl.test1 = (void(*)(sjs_object*, int32_t*))sjf_namespace1_class_namespace1_test1;
    sjs_namespace2_class_foo_vtbl.destroy = (void(*)(void*))sjf_namespace2_class_destroy;
    sjs_namespace2_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_namespace2_class_asinterface;
    sjs_namespace2_class_foo_vtbl.test2 = (void(*)(sjs_object*, int32_t*))sjf_namespace2_class_namespace2_test2;
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
    sjt_call1._refCount = 1;
    sjf_namespace1_class(&sjt_call1);
    sjt_cast1 = &sjt_call1;
    sjf_namespace1_class_as_sji_namespace1_foo(sjt_cast1, &sjv_a);
    sjt_call2._refCount = 1;
    sjf_namespace2_class(&sjt_call2);
    sjt_cast2 = &sjt_call2;
    sjf_namespace2_class_as_sji_namespace2_foo(sjt_cast2, &sjv_b);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_namespace1_class_destroy(&sjt_call1); }
;
    if (sjt_call2._refCount == 1) { sjf_namespace2_class_destroy(&sjt_call2); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
