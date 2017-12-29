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
    int32_t x;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
int32_option sjt_capture1;
sjs_class* sjt_capture4 = 0;
sjs_class* sjt_functionParam1 = 0;
sjs_class sjt_value3 = { -1 };
int32_t sjt_void1;
sjs_class sjv_c = { -1 };
int32_t sjv_clocks_per_sec;
int32_t sjv_d;
sjs_class sjv_e = { -1 };
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
void sjf_func(sjs_class* c, int32_t* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_func(sjs_class* c, int32_t* _return) {
    int32_option sjt_capture7;

    if (c != 0) {
        sjs_class* sjt_capture8 = 0;
        int32_t sjt_value4;
        int32_option value3;

        sjt_capture8 = c;
        sjt_value4 = sjt_capture8->x;
        value3.isvalid = true;
        value3.value = sjt_value4;
        sjt_capture7 = value3;
    } else {
        sjt_capture7 = int32_empty;
    }

    if (sjt_capture7.isvalid) {
        int32_option sjt_getValue2;

        if (c != 0) {
            sjs_class* sjt_capture9 = 0;
            int32_t sjt_value5;
            int32_option value4;

            sjt_capture9 = c;
            sjt_value5 = sjt_capture9->x;
            value4.isvalid = true;
            value4.value = sjt_value5;
            sjt_getValue2 = value4;
        } else {
            sjt_getValue2 = int32_empty;
        }

        (*_return) = sjt_getValue2.value;
    } else {
        (*_return) = 0;
    }
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
    sjv_c._refCount = 1;
    sjv_c.x = 1;
    sjf_class(&sjv_c);
    if ((sjv_c._refCount != -1 ? &sjv_c : 0) != 0) {
        sjs_class* sjt_capture2 = 0;
        int32_t sjt_value1;
        int32_option value1;

        sjt_capture2 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_value1 = sjt_capture2->x;
        value1.isvalid = true;
        value1.value = sjt_value1;
        sjt_capture1 = value1;
    } else {
        sjt_capture1 = int32_empty;
    }

    if (sjt_capture1.isvalid) {
        int32_option sjt_getValue1;

        if ((sjv_c._refCount != -1 ? &sjv_c : 0) != 0) {
            sjs_class* sjt_capture3 = 0;
            int32_t sjt_value2;
            int32_option value2;

            sjt_capture3 = (sjv_c._refCount != -1 ? &sjv_c : 0);
            sjt_value2 = sjt_capture3->x;
            value2.isvalid = true;
            value2.value = sjt_value2;
            sjt_getValue1 = value2;
        } else {
            sjt_getValue1 = int32_empty;
        }

        sjv_d = sjt_getValue1.value;
    } else {
        sjv_d = 0;
    }

    if ((sjv_c._refCount != -1 ? &sjv_c : 0) != 0) {
        sjs_class* sjt_capture5 = 0;

        sjt_capture5 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_value3._refCount = 1;
        sjf_class_copy(&sjt_value3, sjt_capture5);
        sjt_capture4 = (sjt_value3._refCount != -1 ? &sjt_value3 : 0);
    } else {
        sjt_capture4 = 0;
    }

    if (sjt_capture4 != 0) {
        if ((sjv_c._refCount != -1 ? &sjv_c : 0) != 0) {
            sjs_class* sjt_capture6 = 0;

            sjt_capture6 = (sjv_c._refCount != -1 ? &sjv_c : 0);
            sjv_e._refCount = 1;
            sjf_class_copy(&sjv_e, sjt_capture6);
        } else {
            sjv_e._refCount = -1;
        }
    } else {
        sjv_e._refCount = 1;
        sjv_e.x = 2;
        sjf_class(&sjv_e);
    }

    sjt_functionParam1 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjf_func(sjt_functionParam1, &sjt_void1);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_value3._refCount == 1) { sjf_class_destroy(&sjt_value3); }
;
    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
;
    if (sjv_e._refCount == 1) { sjf_class_destroy(&sjv_e); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
