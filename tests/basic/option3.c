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
sjs_class sjv_a = { -1 };
int32_t sjv_b;
sjs_class sjv_c = { -1 };
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
void sjf_test(sjs_class* _return);
void sjf_test_heap(sjs_class** _return);
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

void sjf_func(sjs_class* _return) {
    _return->_refCount = -1;
}

void sjf_func_heap(sjs_class** _return) {
    (*_return) = 0;
    if ((*_return) != 0) {
        (*_return)->_refCount++;
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

void sjf_test(sjs_class* _return) {
    sjs_class sjt_value1 = { -1 };
    sjs_class sjt_value2 = { -1 };

    if (true) {
        if (0 != 0) {
            sjs_class* sjt_capture1 = 0;

            sjt_capture1 = 0;
            _return->_refCount = 1;
            sjf_class_copy(_return, sjt_capture1);
        } else {
            _return->_refCount = -1;
        }
    } else {
        sjt_value1._refCount = 1;
        sjt_value1.x = 2;
        sjf_class(&sjt_value1);
        if ((sjt_value1._refCount != -1 ? &sjt_value1 : 0) != 0) {
            sjs_class* sjt_capture2 = 0;

            sjt_value2._refCount = 1;
            sjt_value2.x = 2;
            sjf_class(&sjt_value2);
            sjt_capture2 = (sjt_value2._refCount != -1 ? &sjt_value2 : 0);
            _return->_refCount = 1;
            sjf_class_copy(_return, sjt_capture2);
        } else {
            _return->_refCount = -1;
        }
    }

    if (sjt_value1._refCount == 1) { sjf_class_destroy(&sjt_value1); }
;
    if (sjt_value2._refCount == 1) { sjf_class_destroy(&sjt_value2); }
;
}

void sjf_test_heap(sjs_class** _return) {
    if (true) {
        if (0 != 0) {
            sjs_class* sjt_capture3 = 0;
            sjs_class* sjt_value3 = 0;

            sjt_capture3 = 0;
            sjt_value3 = (sjs_class*)malloc(sizeof(sjs_class));
            sjt_value3->_refCount = 1;
            sjf_class_copy(sjt_value3, sjt_capture3);
            (*_return) = sjt_value3;
            if ((*_return) != 0) {
                (*_return)->_refCount++;
            }

            sjt_value3->_refCount--;
            if (sjt_value3->_refCount <= 0) {
                weakptr_release(sjt_value3);
                sjf_class_destroy(sjt_value3);
                free(sjt_value3);
            }
        } else {
            (*_return) = 0;
            if ((*_return) != 0) {
                (*_return)->_refCount++;
            }
        }
    } else {
        sjs_class* sjt_value4 = 0;

        sjt_value4 = (sjs_class*)malloc(sizeof(sjs_class));
        sjt_value4->_refCount = 1;
        sjt_value4->x = 2;
        sjf_class_heap(sjt_value4);
        if (sjt_value4 != 0) {
            sjs_class* sjt_capture4 = 0;
            sjs_class* sjt_value5 = 0;
            sjs_class* sjt_value6 = 0;

            sjt_value6 = (sjs_class*)malloc(sizeof(sjs_class));
            sjt_value6->_refCount = 1;
            sjt_value6->x = 2;
            sjf_class_heap(sjt_value6);
            sjt_capture4 = sjt_value6;
            sjt_value5 = (sjs_class*)malloc(sizeof(sjs_class));
            sjt_value5->_refCount = 1;
            sjf_class_copy(sjt_value5, sjt_capture4);
            (*_return) = sjt_value5;
            if ((*_return) != 0) {
                (*_return)->_refCount++;
            }

            sjt_value5->_refCount--;
            if (sjt_value5->_refCount <= 0) {
                weakptr_release(sjt_value5);
                sjf_class_destroy(sjt_value5);
                free(sjt_value5);
            }
            sjt_value6->_refCount--;
            if (sjt_value6->_refCount <= 0) {
                weakptr_release(sjt_value6);
                sjf_class_destroy(sjt_value6);
                free(sjt_value6);
            }
        } else {
            (*_return) = 0;
            if ((*_return) != 0) {
                (*_return)->_refCount++;
            }
        }

        sjt_value4->_refCount--;
        if (sjt_value4->_refCount <= 0) {
            weakptr_release(sjt_value4);
            sjf_class_destroy(sjt_value4);
            free(sjt_value4);
        }
    }
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
    sjf_func(&sjv_a);
    if (((sjv_a._refCount != -1 ? &sjv_a : 0) != 0)) {
        sjs_class* ifValue1 = 0;

        ifValue1 = (sjv_a._refCount != -1 ? &sjv_a : 0);
        sjv_b = ifValue1->x;
    } else {
        sjv_b = 0;
    }

    sjf_test(&sjv_c);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_a._refCount == 1) { sjf_class_destroy(&sjv_a); }
;
    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
