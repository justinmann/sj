#include <lib/common/common.h>

#define sjs_log_typeId 15
#define sjs_func_typeId 17
#define sji_bar_typeId 16

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_func sjs_func;
typedef struct td_sji_bar_vtbl sji_bar_vtbl;
typedef struct td_sji_bar sji_bar;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_func {
    int _refCount;
};

struct td_sji_bar_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_bar {
    sjs_object* _parent;
    sji_bar_vtbl* _vtbl;
};

sji_bar_vtbl sjs_func_bar_vtbl;
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_func* sjv_a = 0;
sji_bar sjv_c = { 0 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_func_as_sji_bar(sjs_func* _this, sji_bar* _return);
void sjf_func_asinterface(sjs_func* _this, int typeId, sjs_interface* _return);
void sjf_func_copy(sjs_func* _this, sjs_func* _from);
void sjf_func_destroy(sjs_func* _this);
void sjf_func_getclasstype(sjs_object* _this, int* _return);
void sjf_func_heap(sjs_func* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_func_as_sji_bar(sjs_func* _this, sji_bar* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_func_bar_vtbl;
}

void sjf_func_asinterface(sjs_func* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_bar_typeId:  {
            sjf_func_as_sji_bar(_this, (sji_bar*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_func_copy(sjs_func* _this, sjs_func* _from) {
}

void sjf_func_destroy(sjs_func* _this) {
}

void sjf_func_getclasstype(sjs_object* _this, int* _return) {
    *_return = 17;
}

void sjf_func_heap(sjs_func* _this) {
    sjs_func* sjt_cast1 = 0;

    sjt_cast1 = _this;
    delete_cb weakptrcb1 = { &sjv_c._parent, weakptr_clear };
    if (sjv_c._parent != 0) { weakptr_cb_remove(sjv_c._parent, weakptrcb1); }
    sjf_func_as_sji_bar(sjt_cast1, &sjv_c);
    delete_cb weakptrcb2 = { &sjv_c._parent, weakptr_clear };
    if (sjv_c._parent != 0) { weakptr_cb_add(sjv_c._parent, weakptrcb2); }
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
    sjs_func_bar_vtbl.destroy = (void(*)(void*))sjf_func_destroy;
    sjs_func_bar_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_func_asinterface;
    sjs_func_bar_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_func_getclasstype;
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
    sjv_c._parent = 0;
    sjv_a = (sjs_func*)malloc(sizeof(sjs_func));
    sjv_a->_refCount = 1;
    sjf_func_heap(sjv_a);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjv_a->_refCount--;
    if (sjv_a->_refCount <= 0) {
        weakptr_release(sjv_a);
        sjf_func_destroy(sjv_a);
        free(sjv_a);
    }
    delete_cb weakptrcb3 = { &sjv_c._parent, weakptr_clear };
    if (sjv_c._parent != 0) { weakptr_cb_remove(sjv_c._parent, weakptrcb3); }
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
