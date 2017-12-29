#include <lib/common/common.h>

#define sjs_log_typeId 15
#define sjs_class_typeId 16

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_class sjv_b = { -1 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_func(sjs_class* _return);
void sjf_func_heap(sjs_class** _return);
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

void sjf_class_heap(sjs_class* _this) {
}

void sjf_func(sjs_class* _return) {
    sjs_class sjt_call1 = { -1 };
    sjs_class sjt_call2 = { -1 };
    sjs_class sjv_a = { -1 };

    sjt_call1._refCount = 1;
    sjf_class(&sjt_call1);
    sjv_a._refCount = 1;
    sjf_class_copy(&sjv_a, (&sjt_call1));
    sjt_call2._refCount = 1;
    sjf_class(&sjt_call2);
    if (sjv_a._refCount == 1) { sjf_class_destroy(&sjv_a); }
;
    sjv_a._refCount = 1;
    sjf_class_copy(&sjv_a, (&sjt_call2));
    _return->_refCount = 1;
    sjf_class_copy(_return, (&sjv_a));

    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
;
    if (sjt_call2._refCount == 1) { sjf_class_destroy(&sjt_call2); }
;
    if (sjv_a._refCount == 1) { sjf_class_destroy(&sjv_a); }
;
}

void sjf_func_heap(sjs_class** _return) {
    sjs_class sjt_call3 = { -1 };
    sjs_class sjt_call4 = { -1 };
    sjs_class sjv_a = { -1 };

    sjt_call3._refCount = 1;
    sjf_class(&sjt_call3);
    sjv_a._refCount = 1;
    sjf_class_copy(&sjv_a, (&sjt_call3));
    sjt_call4._refCount = 1;
    sjf_class(&sjt_call4);
    if (sjv_a._refCount == 1) { sjf_class_destroy(&sjv_a); }
;
    sjv_a._refCount = 1;
    sjf_class_copy(&sjv_a, (&sjt_call4));
    (*_return) = (sjs_class*)malloc(sizeof(sjs_class));
    (*_return)->_refCount = 1;
    sjf_class_copy((*_return), (&sjv_a));

    if (sjt_call3._refCount == 1) { sjf_class_destroy(&sjt_call3); }
;
    if (sjt_call4._refCount == 1) { sjf_class_destroy(&sjt_call4); }
;
    if (sjv_a._refCount == 1) { sjf_class_destroy(&sjv_a); }
;
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
    sjf_func(&sjv_b);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_b._refCount == 1) { sjf_class_destroy(&sjv_b); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
