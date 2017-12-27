#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_a_typeId 2
#define sjs_b_typeId 3
#define sjs_c_typeId 4

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_b sjs_b;
typedef struct td_sjs_c sjs_c;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_a {
    int _refCount;
};

struct td_sjs_b {
    int _refCount;
    sjs_a a;
};

struct td_sjs_c {
    int _refCount;
    sjs_b b;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_c sjt_void1 = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_a(sjs_a* _this);
void sjf_a_copy(sjs_a* _this, sjs_a* _from);
void sjf_a_destroy(sjs_a* _this);
void sjf_a_heap(sjs_a* _this);
void sjf_b(sjs_b* _this);
void sjf_b_copy(sjs_b* _this, sjs_b* _from);
void sjf_b_destroy(sjs_b* _this);
void sjf_b_heap(sjs_b* _this);
void sjf_c(sjs_c* _this);
void sjf_c_copy(sjs_c* _this, sjs_c* _from);
void sjf_c_destroy(sjs_c* _this);
void sjf_c_heap(sjs_c* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_a(sjs_a* _this) {
}

void sjf_a_copy(sjs_a* _this, sjs_a* _from) {
}

void sjf_a_destroy(sjs_a* _this) {
}

void sjf_a_heap(sjs_a* _this) {
}

void sjf_b(sjs_b* _this) {
}

void sjf_b_copy(sjs_b* _this, sjs_b* _from) {
    _this->a._refCount = 1;
    sjf_a_copy(&_this->a, &_from->a);
}

void sjf_b_destroy(sjs_b* _this) {
    if (_this->a._refCount == 1) { sjf_a_destroy(&_this->a); }
;
}

void sjf_b_heap(sjs_b* _this) {
}

void sjf_c(sjs_c* _this) {
}

void sjf_c_copy(sjs_c* _this, sjs_c* _from) {
    _this->b._refCount = 1;
    sjf_b_copy(&_this->b, &_from->b);
}

void sjf_c_destroy(sjs_c* _this) {
    if (_this->b._refCount == 1) { sjf_b_destroy(&_this->b); }
;
}

void sjf_c_heap(sjs_c* _this) {
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
    sjt_void1._refCount = 1;
    sjt_void1.b._refCount = 1;
    sjt_void1.b.a._refCount = 1;
    sjf_a(&sjt_void1.b.a);
    sjf_b(&sjt_void1.b);
    sjf_c(&sjt_void1);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_void1._refCount == 1) { sjf_c_destroy(&sjt_void1); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
