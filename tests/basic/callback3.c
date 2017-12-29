#include <lib/common/common.h>

#define sjs_log_typeId 15
#define sjs_class_typeId 16
#define cb_i32_void_typeId 19
#define cb_i32_void_heap_typeId 19

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_cb_i32_void cb_i32_void;
typedef struct td_cb_i32_void_heap cb_i32_void_heap;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
    int32_t total;
};

struct td_cb_i32_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, int32_t);
};

struct td_cb_i32_void_heap {
    cb_i32_void inner;
    void (*_destroy)(sjs_object*);
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_class* sjt_parent1 = 0;
int32_t sjt_void1;
sjs_class* sjv_c = 0;
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_func(sjs_class* _parent, int32_t x);
void sjf_class_heap(sjs_class* _this);
void sjf_class_run(sjs_class* _parent, int32_t* _return);
void sjf_domath(cb_i32_void_heap cb);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->total = _from->total;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_func(sjs_class* _parent, int32_t x) {
    _parent->total = _parent->total + x;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_run(sjs_class* _parent, int32_t* _return) {
    cb_i32_void_heap sjt_functionParam3;

    sjt_functionParam3.inner._parent = (sjs_object*)_parent;
    sjt_functionParam3.inner._parent->_refCount++;
    sjt_functionParam3._destroy = (void(*)(sjs_object*))sjf_class_destroy;
    sjt_functionParam3.inner._cb = (void(*)(sjs_object*,int32_t))sjf_class_func;
    sjf_domath(sjt_functionParam3);
    (*_return) = _parent->total;

    if ((uintptr_t)sjt_functionParam3.inner._parent > 1) {
        sjt_functionParam3.inner._parent->_refCount--;
        if (sjt_functionParam3.inner._parent->_refCount <= 0) {
            sjt_functionParam3._destroy(sjt_functionParam3.inner._parent);
            free(sjt_functionParam3.inner._parent);
        }
    }
}

void sjf_domath(cb_i32_void_heap cb) {
    int32_t sjt_functionParam1;
    int32_t sjt_functionParam2;

    sjt_functionParam1 = 1;
    cb.inner._cb(cb.inner._parent, sjt_functionParam1);
    sjt_functionParam2 = 2;
    cb.inner._cb(cb.inner._parent, sjt_functionParam2);
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
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->total = 0;
    sjf_class_heap(sjv_c);
    sjt_parent1 = sjv_c;
    sjt_parent1->_refCount++;
    sjf_class_run(sjt_parent1, &sjt_void1);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_parent1->_refCount--;
    if (sjt_parent1->_refCount <= 0) {
        weakptr_release(sjt_parent1);
        sjf_class_destroy(sjt_parent1);
        free(sjt_parent1);
    }
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
