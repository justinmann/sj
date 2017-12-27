#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_class_typeId 2

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
    int32_t bob;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_class sjt_call1 = { -1 };
bool sjt_capture1;
sjs_class* sjt_functionParam1 = 0;
sjs_class* sjt_parent1 = 0;
sjs_class sjv_a = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;
int32_t sjv_y;
sjs_class* underscore1 = 0;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_class_isequal(sjs_class* _parent, sjs_class* r, bool* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->bob = _from->bob;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_isequal(sjs_class* _parent, sjs_class* r, bool* _return) {
    (*_return) = _parent->bob == r->bob;
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
    sjv_a._refCount = 1;
    sjv_a.bob = 3;
    sjf_class(&sjv_a);
    underscore1 = &sjv_a;
    sjt_parent1 = underscore1;
    sjt_call1._refCount = 1;
    sjt_call1.bob = 4;
    sjf_class(&sjt_call1);
    sjt_functionParam1 = &sjt_call1;
    sjf_class_isequal(sjt_parent1, sjt_functionParam1, &sjt_capture1);
    if (sjt_capture1) {
        sjv_y = 1;
    } else {
        sjs_class sjt_call2 = { -1 };
        bool sjt_capture2;
        sjs_class* sjt_functionParam2 = 0;
        sjs_class* sjt_parent2 = 0;

        sjt_parent2 = underscore1;
        sjt_call2._refCount = 1;
        sjt_call2.bob = 2;
        sjf_class(&sjt_call2);
        sjt_functionParam2 = &sjt_call2;
        sjf_class_isequal(sjt_parent2, sjt_functionParam2, &sjt_capture2);
        if (sjt_capture2) {
            sjv_y = 2;
        } else {
            sjv_y = 3;
        }

        if (sjt_call2._refCount == 1) { sjf_class_destroy(&sjt_call2); }
;
    }
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
;
    if (sjv_a._refCount == 1) { sjf_class_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
