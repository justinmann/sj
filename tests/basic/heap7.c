#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_foo_typeId 2

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_foo sjs_foo;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_foo {
    int _refCount;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_foo sjt_call1 = { -1 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
sjs_foo* sjv_heap_x1 = 0;
sjs_foo* sjv_heap_x2 = 0;
sjs_foo* sjv_heap_x3 = 0;
sjs_foo* sjv_heap_y = 0;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_foo* sjv_local_x1 = 0;
sjs_foo* sjv_local_x2 = 0;
sjs_foo* sjv_local_x3 = 0;
sjs_foo* sjv_local_y = 0;
sjs_log sjv_log = { -1 };
sjs_foo sjv_stack_x1 = { -1 };
sjs_foo sjv_stack_x2 = { -1 };
sjs_foo sjv_stack_x3 = { -1 };
sjs_foo sjv_stack_y = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_foo(sjs_foo* _this);
void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from);
void sjf_foo_destroy(sjs_foo* _this);
void sjf_foo_heap(sjs_foo* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_foo(sjs_foo* _this) {
}

void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from) {
}

void sjf_foo_destroy(sjs_foo* _this) {
}

void sjf_foo_heap(sjs_foo* _this) {
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
    sjv_heap_y = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_heap_y->_refCount = 1;
    sjf_foo_heap(sjv_heap_y);
    sjv_stack_y._refCount = 1;
    sjf_foo(&sjv_stack_y);
    sjt_call1._refCount = 1;
    sjf_foo(&sjt_call1);
    sjv_local_y = &sjt_call1;
    sjv_heap_x1 = sjv_heap_y;
    sjv_heap_x1->_refCount++;
    sjv_heap_x2 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_heap_x2->_refCount = 1;
    sjf_foo_copy(sjv_heap_x2, (&sjv_stack_y));
    sjv_heap_x3 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_heap_x3->_refCount = 1;
    sjf_foo_copy(sjv_heap_x3, sjv_local_y);
    sjv_stack_x1._refCount = 1;
    sjf_foo_copy(&sjv_stack_x1, (&sjv_stack_y));
    sjv_stack_x2._refCount = 1;
    sjf_foo_copy(&sjv_stack_x2, sjv_heap_y);
    sjv_stack_x3._refCount = 1;
    sjf_foo_copy(&sjv_stack_x3, sjv_local_y);
    sjv_local_x1 = sjv_heap_y;
    sjv_local_x2 = &sjv_stack_y;
    sjv_local_x3 = sjv_local_y;
    main_destroy();
    return 0;
}

void main_destroy() {

    sjv_heap_x1->_refCount--;
    if (sjv_heap_x1->_refCount <= 0) {
        weakptr_release(sjv_heap_x1);
        sjf_foo_destroy(sjv_heap_x1);
        free(sjv_heap_x1);
    }
    sjv_heap_x2->_refCount--;
    if (sjv_heap_x2->_refCount <= 0) {
        weakptr_release(sjv_heap_x2);
        sjf_foo_destroy(sjv_heap_x2);
        free(sjv_heap_x2);
    }
    sjv_heap_x3->_refCount--;
    if (sjv_heap_x3->_refCount <= 0) {
        weakptr_release(sjv_heap_x3);
        sjf_foo_destroy(sjv_heap_x3);
        free(sjv_heap_x3);
    }
    sjv_heap_y->_refCount--;
    if (sjv_heap_y->_refCount <= 0) {
        weakptr_release(sjv_heap_y);
        sjf_foo_destroy(sjv_heap_y);
        free(sjv_heap_y);
    }
    if (sjt_call1._refCount == 1) { sjf_foo_destroy(&sjt_call1); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_stack_x1._refCount == 1) { sjf_foo_destroy(&sjv_stack_x1); }
;
    if (sjv_stack_x2._refCount == 1) { sjf_foo_destroy(&sjv_stack_x2); }
;
    if (sjv_stack_x3._refCount == 1) { sjf_foo_destroy(&sjv_stack_x3); }
;
    if (sjv_stack_y._refCount == 1) { sjf_foo_destroy(&sjv_stack_y); }
;
}
