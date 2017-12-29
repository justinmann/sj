#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_func_typeId 2

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_func sjs_func;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_func {
    int _refCount;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_func* sjt_parent1 = 0;
sjs_func* sjv_a = 0;
sjs_func* sjv_b = 0;
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_func_bar_heap(sjs_func* _parent, sjs_func** _return);
void sjf_func_copy(sjs_func* _this, sjs_func* _from);
void sjf_func_destroy(sjs_func* _this);
void sjf_func_heap(sjs_func* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_func_bar_heap(sjs_func* _parent, sjs_func** _return) {
    (*_return) = _parent;
    (*_return)->_refCount++;
}

void sjf_func_copy(sjs_func* _this, sjs_func* _from) {
}

void sjf_func_destroy(sjs_func* _this) {
}

void sjf_func_heap(sjs_func* _this) {
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
    sjv_a = (sjs_func*)malloc(sizeof(sjs_func));
    sjv_a->_refCount = 1;
    sjf_func_heap(sjv_a);
    sjt_parent1 = sjv_a;
    sjt_parent1->_refCount++;
    sjf_func_bar_heap(sjt_parent1, &sjv_b);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_parent1->_refCount--;
    if (sjt_parent1->_refCount <= 0) {
        weakptr_release(sjt_parent1);
        sjf_func_destroy(sjt_parent1);
        free(sjt_parent1);
    }
    sjv_a->_refCount--;
    if (sjv_a->_refCount <= 0) {
        weakptr_release(sjv_a);
        sjf_func_destroy(sjv_a);
        free(sjv_a);
    }
    sjv_b->_refCount--;
    if (sjv_b->_refCount <= 0) {
        weakptr_release(sjv_b);
        sjf_func_destroy(sjv_b);
        free(sjv_b);
    }
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
