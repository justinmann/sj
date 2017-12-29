#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_inner_typeId 2
#define sjs_class_typeId 3
#define sjs_class2_typeId 4

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_inner sjs_inner;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class2 sjs_class2;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_inner {
    int _refCount;
};

struct td_sjs_class {
    int _refCount;
    sjs_inner inner;
};

struct td_sjs_class2 {
    int _refCount;
    sjs_inner inner;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;
sjs_class sjv_x3 = { -1 };
sjs_class2 sjv_x7 = { -1 };

void sjf_class(sjs_class* _this);
void sjf_class2(sjs_class2* _this);
void sjf_class2_copy(sjs_class2* _this, sjs_class2* _from);
void sjf_class2_destroy(sjs_class2* _this);
void sjf_class2_heap(sjs_class2* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_inner(sjs_inner* _this);
void sjf_inner_copy(sjs_inner* _this, sjs_inner* _from);
void sjf_inner_destroy(sjs_inner* _this);
void sjf_inner_heap(sjs_inner* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_class(sjs_class* _this) {
}

void sjf_class2(sjs_class2* _this) {
}

void sjf_class2_copy(sjs_class2* _this, sjs_class2* _from) {
    _this->inner._refCount = 1;
    sjf_inner_copy((_this->inner._refCount != -1 ? &_this->inner : 0), (_from->inner._refCount != -1 ? &_from->inner : 0));
}

void sjf_class2_destroy(sjs_class2* _this) {
    if (_this->inner._refCount == 1) { sjf_inner_destroy(&_this->inner); }
;
}

void sjf_class2_heap(sjs_class2* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->inner._refCount = 1;
    sjf_inner_copy(&_this->inner, &_from->inner);
}

void sjf_class_destroy(sjs_class* _this) {
    if (_this->inner._refCount == 1) { sjf_inner_destroy(&_this->inner); }
;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_inner(sjs_inner* _this) {
}

void sjf_inner_copy(sjs_inner* _this, sjs_inner* _from) {
}

void sjf_inner_destroy(sjs_inner* _this) {
}

void sjf_inner_heap(sjs_inner* _this) {
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
    sjv_x3._refCount = 1;
    sjv_x3.inner._refCount = 1;
    sjf_inner(&sjv_x3.inner);
    sjf_class(&sjv_x3);
    sjv_x7._refCount = 1;
    sjv_x7.inner._refCount = 1;
    sjf_inner(&sjv_x7.inner);
    sjf_class2(&sjv_x7);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_x3._refCount == 1) { sjf_class_destroy(&sjv_x3); }
;
    if (sjv_x7._refCount == 1) { sjf_class2_destroy(&sjv_x7); }
;
}
