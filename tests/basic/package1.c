#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_a_class_typeId 2
#define sji_a_foo_vtbl_typeId 3
#define sji_a_foo_typeId 4
#define sjs_b_class_typeId 5
#define sji_b_foo_vtbl_typeId 6
#define sji_b_foo_typeId 7

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_a_class sjs_a_class;
typedef struct td_sji_a_foo_vtbl sji_a_foo_vtbl;
typedef struct td_sji_a_foo sji_a_foo;
typedef struct td_sjs_b_class sjs_b_class;
typedef struct td_sji_b_foo_vtbl sji_b_foo_vtbl;
typedef struct td_sji_b_foo sji_b_foo;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_a_class {
    int _refCount;
};

struct td_sji_a_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*bar)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_a_foo {
    sjs_object* _parent;
    sji_a_foo_vtbl* _vtbl;
};

struct td_sjs_b_class {
    int _refCount;
};

struct td_sji_b_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*bar)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_b_foo {
    sjs_object* _parent;
    sji_b_foo_vtbl* _vtbl;
};

sji_a_foo_vtbl sjs_a_class_foo_vtbl;
sji_b_foo_vtbl sjs_b_class_foo_vtbl;
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_a_class sjt_call1 = { -1 };
sjs_b_class sjt_call2 = { -1 };
sjs_a_class* sjt_cast1 = 0;
sjs_b_class* sjt_cast2 = 0;
sji_a_foo sjt_parent1 = { 0 };
sji_b_foo sjt_parent2 = { 0 };
int32_t sjv_a_x;
int32_t sjv_b;
int32_t sjv_b_d;
int32_t sjv_b_x;
int32_t sjv_c;
sji_a_foo sjv_e = { 0 };
void* sjv_emptystringdata;
int32_t sjv_f;
float sjv_f32_pi;
sji_b_foo sjv_h = { 0 };
int32_t sjv_i;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;
int32_t sjv_y;

void sjf_a_class(sjs_a_class* _this);
void sjf_a_class_a_bar(sjs_a_class* _parent, int32_t* _return);
void sjf_a_class_as_sji_a_foo(sjs_a_class* _this, sji_a_foo* _return);
void sjf_a_class_asinterface(sjs_a_class* _this, int typeId, sjs_interface* _return);
void sjf_a_class_copy(sjs_a_class* _this, sjs_a_class* _from);
void sjf_a_class_destroy(sjs_a_class* _this);
void sjf_a_class_heap(sjs_a_class* _this);
void sjf_a_func(int32_t* _return);
void sjf_b_class(sjs_b_class* _this);
void sjf_b_class_as_sji_b_foo(sjs_b_class* _this, sji_b_foo* _return);
void sjf_b_class_asinterface(sjs_b_class* _this, int typeId, sjs_interface* _return);
void sjf_b_class_b_bar(sjs_b_class* _parent, int32_t* _return);
void sjf_b_class_copy(sjs_b_class* _this, sjs_b_class* _from);
void sjf_b_class_destroy(sjs_b_class* _this);
void sjf_b_class_heap(sjs_b_class* _this);
void sjf_b_func(int32_t* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_a_class(sjs_a_class* _this) {
}

void sjf_a_class_a_bar(sjs_a_class* _parent, int32_t* _return) {
    sjf_a_func(_return);
}

void sjf_a_class_as_sji_a_foo(sjs_a_class* _this, sji_a_foo* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_a_class_foo_vtbl;
}

void sjf_a_class_asinterface(sjs_a_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_a_foo_typeId:  {
            sjf_a_class_as_sji_a_foo(_this, (sji_a_foo*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_a_class_copy(sjs_a_class* _this, sjs_a_class* _from) {
}

void sjf_a_class_destroy(sjs_a_class* _this) {
}

void sjf_a_class_heap(sjs_a_class* _this) {
}

void sjf_a_func(int32_t* _return) {
    (*_return) = sjv_a_x;
}

void sjf_b_class(sjs_b_class* _this) {
}

void sjf_b_class_as_sji_b_foo(sjs_b_class* _this, sji_b_foo* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_b_class_foo_vtbl;
}

void sjf_b_class_asinterface(sjs_b_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_b_foo_typeId:  {
            sjf_b_class_as_sji_b_foo(_this, (sji_b_foo*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
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

void sjf_b_func(int32_t* _return) {
    (*_return) = sjv_b_x;
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
    sjs_a_class_foo_vtbl.destroy = (void(*)(void*))sjf_a_class_destroy;
    sjs_a_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_a_class_asinterface;
    sjs_a_class_foo_vtbl.bar = (void(*)(sjs_object*, int32_t*))sjf_a_class_a_bar;
    sjs_b_class_foo_vtbl.destroy = (void(*)(void*))sjf_b_class_destroy;
    sjs_b_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_b_class_asinterface;
    sjs_b_class_foo_vtbl.bar = (void(*)(sjs_object*, int32_t*))sjf_b_class_b_bar;
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
    sjv_a_x = 0;
    sjv_b_x = 1;
    sjv_b_d = 12;
    sjv_b = sjv_b_x;
    sjf_b_func(&sjv_c);
    sjv_y = 0;
    sjt_call1._refCount = 1;
    sjf_a_class(&sjt_call1);
    sjt_cast1 = &sjt_call1;
    sjf_a_class_as_sji_a_foo(sjt_cast1, &sjv_e);
    sjt_parent1 = sjv_e;
    sjt_parent1._vtbl->bar(sjt_parent1._parent, &sjv_f);
    sjt_call2._refCount = 1;
    sjf_b_class(&sjt_call2);
    sjt_cast2 = &sjt_call2;
    sjf_b_class_as_sji_b_foo(sjt_cast2, &sjv_h);
    sjt_parent2 = sjv_h;
    sjt_parent2._vtbl->bar(sjt_parent2._parent, &sjv_i);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_a_class_destroy(&sjt_call1); }
;
    if (sjt_call2._refCount == 1) { sjf_b_class_destroy(&sjt_call2); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
