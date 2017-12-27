#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_math_typeId 2
#define sjs_class_typeId 3

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_math sjs_math;
typedef struct td_sjs_class sjs_class;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_math {
    int _refCount;
};

struct td_sjs_class {
    int _refCount;
    sjs_math m;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
int32_t sjt_functionParam5;
sjs_class* sjt_parent2 = 0;
int32_t sjt_void1;
sjs_class sjv_c = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_class(sjs_class* _this);
void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_math(sjs_math* _this);
void sjf_math_copy(sjs_math* _this, sjs_math* _from);
void sjf_math_destroy(sjs_math* _this);
void sjf_math_heap(sjs_math* _this);
void sjf_math_sub(sjs_math* _parent, int32_t x, int32_t y, int32_t* _return);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_class(sjs_class* _this) {
}

void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t sjt_functionParam1;

    sjt_functionParam1 = x;
    sjf_class_foo(_parent, sjt_functionParam1, _return);
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->m._refCount = 1;
    sjf_math_copy(&_this->m, &_from->m);
}

void sjf_class_destroy(sjs_class* _this) {
    if (_this->m._refCount == 1) { sjf_math_destroy(&_this->m); }
;
}

void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return) {
    if ((x > 0)) {
        int32_t sjt_functionParam2;
        int32_t sjt_functionParam3;
        int32_t sjt_functionParam4;
        sjs_math* sjt_parent1 = 0;

        sjt_parent1 = &_parent->m;
        sjt_functionParam3 = x;
        sjt_functionParam4 = 1;
        sjf_math_sub(sjt_parent1, sjt_functionParam3, sjt_functionParam4, &sjt_functionParam2);
        sjf_class_bar(_parent, sjt_functionParam2, _return);
    } else {
        (*_return) = 0;
    }
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

void sjf_math(sjs_math* _this) {
}

void sjf_math_copy(sjs_math* _this, sjs_math* _from) {
}

void sjf_math_destroy(sjs_math* _this) {
}

void sjf_math_heap(sjs_math* _this) {
}

void sjf_math_sub(sjs_math* _parent, int32_t x, int32_t y, int32_t* _return) {
    (*_return) = x - y;
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
    sjv_c._refCount = 1;
    sjv_c.m._refCount = 1;
    sjf_math(&sjv_c.m);
    sjf_class(&sjv_c);
    sjt_parent2 = &sjv_c;
    sjt_functionParam5 = 4;
    sjf_class_foo(sjt_parent2, sjt_functionParam5, &sjt_void1);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
