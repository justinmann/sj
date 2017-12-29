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
    int32_option d;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
int32_t sjt_value1;
int32_option sjv_a;
int32_option sjv_b;
sjs_class sjv_c = { -1 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;
int32_t sjv_w;
int32_t sjv_x;
int32_t sjv_y;
int32_option value1;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
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
    _this->d = _from->d;
}

void sjf_class_destroy(sjs_class* _this) {
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
    sjv_clocks_per_sec = 0;
    sjv_clocks_per_sec = CLOCKS_PER_SEC;
    sjv_a = int32_empty;
    sjt_value1 = 5;
    value1.isvalid = true;
    value1.value = sjt_value1;
    sjv_b = value1;
    sjv_c._refCount = 1;
    sjv_c.d = int32_empty;
    sjf_class(&sjv_c);
    if (sjv_a.isvalid) {
        int32_t ifValue1;
        int32_option sjt_getValue1;

        sjt_getValue1 = sjv_a;
        ifValue1 = sjt_getValue1.value;
        sjv_w = ifValue1;
    } else {
        sjv_w = 2;
    }

    if (sjv_b.isvalid) {
        int32_t ifValue2;
        int32_option sjt_getValue2;

        sjt_getValue2 = sjv_b;
        ifValue2 = sjt_getValue2.value;
        sjv_x = ifValue2;
    } else {
        sjv_x = 2;
    }

    if ((&sjv_c)->d.isvalid) {
        int32_t ifValue3;
        int32_option sjt_getValue3;

        sjt_getValue3 = (&sjv_c)->d;
        ifValue3 = sjt_getValue3.value;
        sjv_y = ifValue3;
    } else {
        sjv_y = 1;
    }
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
