#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_class_typeId 2
#define cb_i32_typeId 3
#define cb_i32_heap_typeId 4

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_cb_i32 cb_i32;
typedef struct td_cb_i32_heap cb_i32_heap;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
};

struct td_cb_i32 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, int32_t* _return);
};

struct td_cb_i32_heap {
    cb_i32 inner;
    void (*_destroy)(sjs_object*);
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_class* sjv_c = 0;
cb_i32_heap sjv_cb;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_func(sjs_class* _parent, int32_t* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_func(sjs_class* _parent, int32_t* _return) {
    (*_return) = 0;
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
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjf_class_heap(sjv_c);
    sjv_cb.inner._parent = (sjs_object*)sjv_c;
    sjv_cb.inner._parent->_refCount++;
    sjv_cb._destroy = (void(*)(sjs_object*))sjf_class_destroy;
    sjv_cb.inner._cb = (void(*)(sjs_object*, int32_t*))sjf_class_func;
    if ((uintptr_t)sjv_cb.inner._parent > 1) {
        sjv_cb.inner._parent->_refCount--;
        if (sjv_cb.inner._parent->_refCount <= 0) {
            sjv_cb._destroy(sjv_cb.inner._parent);
            free(sjv_cb.inner._parent);
        }
    }

    sjv_cb.inner._parent = (sjs_object*)sjv_c;
    sjv_cb.inner._parent->_refCount++;
    sjv_cb._destroy = (void(*)(sjs_object*))sjf_class_destroy;
    sjv_cb.inner._cb = (void(*)(sjs_object*, int32_t*))sjf_class_func;
    main_destroy();
    return 0;
}

void main_destroy() {

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }
    if ((uintptr_t)sjv_cb.inner._parent > 1) {
        sjv_cb.inner._parent->_refCount--;
        if (sjv_cb.inner._parent->_refCount <= 0) {
            sjv_cb._destroy(sjv_cb.inner._parent);
            free(sjv_cb.inner._parent);
        }
    }
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
