#include <lib/common/common.h>

#define sjs_log_typeId 15
#define sjs_class_i32_typeId 18
#define sji_bar_typeId 20
#define sji_foo_i32_typeId 19

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class_i32 sjs_class_i32;
typedef struct td_sji_bar_vtbl sji_bar_vtbl;
typedef struct td_sji_bar sji_bar;
typedef struct td_sji_foo_i32_vtbl sji_foo_i32_vtbl;
typedef struct td_sji_foo_i32 sji_foo_i32;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class_i32 {
    int _refCount;
};

struct td_sji_bar_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*test2)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_bar {
    sjs_object* _parent;
    sji_bar_vtbl* _vtbl;
};

struct td_sji_foo_i32_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*test1)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_foo_i32 {
    sjs_object* _parent;
    sji_foo_i32_vtbl* _vtbl;
};

sji_bar_vtbl sjs_class_i32_bar_vtbl;
sji_foo_i32_vtbl sjs_class_i32_foo_vtbl;
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_class_i32 sjt_call1 = { -1 };
sjs_class_i32* sjt_cast1 = 0;
sji_foo_i32 sjt_cast2 = { 0 };
sji_foo_i32 sjt_parent1 = { 0 };
int32_t sjt_void1;
sji_foo_i32 sjv_a = { 0 };
sji_bar sjv_b = { 0 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_class_i32(sjs_class_i32* _this);
void sjf_class_i32_as_sji_bar(sjs_class_i32* _this, sji_bar* _return);
void sjf_class_i32_as_sji_foo_i32(sjs_class_i32* _this, sji_foo_i32* _return);
void sjf_class_i32_asinterface(sjs_class_i32* _this, int typeId, sjs_interface* _return);
void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from);
void sjf_class_i32_destroy(sjs_class_i32* _this);
void sjf_class_i32_getclasstype(sjs_object* _this, int* _return);
void sjf_class_i32_heap(sjs_class_i32* _this);
void sjf_class_i32_test1(sjs_class_i32* _parent, int32_t* _return);
void sjf_class_i32_test2(sjs_class_i32* _parent, int32_t* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_class_i32(sjs_class_i32* _this) {
}

void sjf_class_i32_as_sji_bar(sjs_class_i32* _this, sji_bar* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_i32_bar_vtbl;
}

void sjf_class_i32_as_sji_foo_i32(sjs_class_i32* _this, sji_foo_i32* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_i32_foo_vtbl;
}

void sjf_class_i32_asinterface(sjs_class_i32* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_bar_typeId:  {
            sjf_class_i32_as_sji_bar(_this, (sji_bar*)_return);
            break;
        }

        case sji_foo_i32_typeId:  {
            sjf_class_i32_as_sji_foo_i32(_this, (sji_foo_i32*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from) {
}

void sjf_class_i32_destroy(sjs_class_i32* _this) {
}

void sjf_class_i32_getclasstype(sjs_object* _this, int* _return) {
    *_return = 18;
}

void sjf_class_i32_heap(sjs_class_i32* _this) {
}

void sjf_class_i32_test1(sjs_class_i32* _parent, int32_t* _return) {
    (*_return) = 1;
}

void sjf_class_i32_test2(sjs_class_i32* _parent, int32_t* _return) {
    (*_return) = 2;
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
    sjs_class_i32_bar_vtbl.destroy = (void(*)(void*))sjf_class_i32_destroy;
    sjs_class_i32_bar_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_i32_asinterface;
    sjs_class_i32_bar_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_class_i32_getclasstype;
    sjs_class_i32_bar_vtbl.test2 = (void(*)(sjs_object*, int32_t*))sjf_class_i32_test2;
    sjs_class_i32_foo_vtbl.destroy = (void(*)(void*))sjf_class_i32_destroy;
    sjs_class_i32_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_i32_asinterface;
    sjs_class_i32_foo_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_class_i32_getclasstype;
    sjs_class_i32_foo_vtbl.test1 = (void(*)(sjs_object*, int32_t*))sjf_class_i32_test1;
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
    sjf_class_i32(&sjt_call1);
    sjt_cast1 = &sjt_call1;
    sjf_class_i32_as_sji_foo_i32(sjt_cast1, &sjv_a);
    sjt_parent1 = sjv_a;
    sjt_parent1._vtbl->test1(sjt_parent1._parent, &sjt_void1);
    sjt_cast2 = sjv_a;
    sjt_cast2._vtbl->asinterface(sjt_cast2._parent, sji_bar_typeId, (sjs_interface*)&sjv_b);
    if (sjv_b._parent != 0) {
        sji_bar sjt_parent2 = { 0 };
        int32_t sjt_value1;
        int32_option value1;

        sjt_parent2 = sjv_b;
        sjt_parent2._vtbl->test2(sjt_parent2._parent, &sjt_value1);
        value1.isvalid = true;
        value1.value = sjt_value1;
    } else {
    }
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_class_i32_destroy(&sjt_call1); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
