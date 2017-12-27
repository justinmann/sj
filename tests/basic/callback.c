#ifdef __GNUC__
#if __x86_64__ 
#define __LINUX__
#define __64__
#elif __i386__ 
#define __LINUX__
#define __32__
#else
#define __LINUX__
#define __32__
#endif
#elif _MSC_VER
#if _WIN64 
#define __WINDOWS__
#define __64__
#elif _WIN32 
#define __WINDOWS__
#define __32__
#else
#error "WINDOWS UNSUPPORTED BITS"
#endif
#else
#error "UNKNOWN PLATFORM"
#endif
#include <lib/common/khash.h>
#include <lib/common/value_option_types.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __WINDOWS__
#include <windows.h>
#endif

typedef struct td_delete_cb delete_cb;
typedef struct td_delete_cb_list delete_cb_list;
struct td_delete_cb {
    void* _parent;
    void (*_cb)(void* _parent, void* object);
};
struct td_delete_cb_list {
    int size;
    delete_cb cb[5];
    delete_cb_list* next;
};
#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_log_typeId 3
#define cb_i32_data_heap_data_typeId 4
#define cb_i32_data_heap_data_heap_typeId 5
#define sjs_data_typeId 6
#define sjs_class_typeId 7

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_log sjs_log;
typedef struct td_cb_i32_data_heap_data cb_i32_data_heap_data;
typedef struct td_cb_i32_data_heap_data_heap cb_i32_data_heap_data_heap;
typedef struct td_sjs_data sjs_data;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_cb_i32_data_heap_data {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, int32_t, sjs_data* _return);
    void (*_cb_heap)(sjs_object* _parent, int32_t, sjs_data** _return);
};

struct td_cb_i32_data_heap_data_heap {
    cb_i32_data_heap_data inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_data {
    int _refCount;
    int32_t x;
};

struct td_sjs_class {
    int _refCount;
    int32_t b;
};

void debugout(const char * format, ...);
void debugoutv(const char * format, va_list args);
void halt(const char * format, ...);
void ptr_hash(void* p, uint32_t* result);
void ptr_isequal(void *p1, void* p2, bool* result);
void delete_cb_list_free(delete_cb_list* d);
void delete_cb_list_add(delete_cb_list* d, delete_cb cb);
void delete_cb_list_remove(delete_cb_list* d, delete_cb cb);
void delete_cb_list_invoke(delete_cb_list* d, void* p);
void weakptr_init();
void weakptr_release(void* v);
void weakptr_cb_add(void* v, delete_cb cb);
void weakptr_cb_remove(void* v, delete_cb cb);
void weakptr_clear(void* parent, void* v);
void ptr_init();
void ptr_retain(void* ptr);
bool ptr_release(void* ptr);
#include <lib/common/object.h>
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
cb_i32_data_heap_data sjt_callback1;
cb_i32_data_heap_data sjt_callback2;
cb_i32_data_heap_data sjt_callback3;
cb_i32_data_heap_data sjt_callback5;
cb_i32_data_heap_data sjt_callback6;
cb_i32_data_heap_data sjt_callback7;
cb_i32_data_heap_data sjt_callback8;
cb_i32_data_heap_data sjt_callback9;
int32_t sjt_functionParam1;
int32_t sjt_functionParam10;
int32_t sjt_functionParam11;
int32_t sjt_functionParam2;
int32_t sjt_functionParam3;
cb_i32_data_heap_data sjt_functionParam5;
cb_i32_data_heap_data sjt_functionParam6;
int32_t sjt_functionParam7;
int32_t sjt_functionParam8;
int32_t sjt_functionParam9;
cb_i32_data_heap_data sjt_getValue1;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
cb_i32_data_heap_data sjt_value1;
cb_i32_data_heap_data sjv_a;
int32_t sjv_a2;
sjs_data* sjv_b = 0;
int32_t sjv_b2;
sjs_class sjv_c = { -1 };
sjs_class* sjv_c_heap = 0;
sjs_data sjv_d = { -1 };
sjs_data sjv_e = { -1 };
void* sjv_emptystringdata;
cb_i32_data_heap_data sjv_f1;
cb_i32_data_heap_data sjv_f2;
cb_i32_data_heap_data_heap sjv_f3;
float sjv_f32_pi;
sjs_data sjv_g = { -1 };
cb_i32_data_heap_data sjv_h;
cb_i32_data_heap_data sjv_i;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
cb_i32_data_heap_data sjv_j;
sjs_data sjv_k = { -1 };
cb_i32_data_heap_data_heap sjv_l;
sjs_log sjv_log = { -1 };
sjs_data sjv_m = { -1 };
sjs_data* sjv_n = 0;
cb_i32_data_heap_data sjv_o;
sjs_data sjv_p = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_callback(cb_i32_data_heap_data f, int32_t* _return);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_func(sjs_class* _parent, int32_t a, sjs_data* _return);
void sjf_class_func_heap(sjs_class* _parent, int32_t a, sjs_data** _return);
void sjf_class_heap(sjs_class* _this);
void sjf_data(sjs_data* _this);
void sjf_data_copy(sjs_data* _this, sjs_data* _from);
void sjf_data_destroy(sjs_data* _this);
void sjf_data_heap(sjs_data* _this);
void sjf_func(int32_t a, sjs_data* _return);
void sjf_func2_data(int32_t a, sjs_data* _return);
void sjf_func2_data_callback(void * _parent, int32_t a, sjs_data* _return);
void sjf_func2_data_heap(int32_t a, sjs_data** _return);
void sjf_func2_data_heap_callback(void * _parent, int32_t a, sjs_data** _return);
void sjf_func_callback(void * _parent, int32_t a, sjs_data* _return);
void sjf_func_heap(int32_t a, sjs_data** _return);
void sjf_func_heap_callback(void * _parent, int32_t a, sjs_data** _return);
void sjf_getcallback_heap(cb_i32_data_heap_data_heap* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

void debugout(const char * format, ...) {
    va_list args;
    va_start(args, format);
    debugoutv(format, args);
    va_end(args);
}
void debugoutv(const char * format, va_list args) {
    #ifdef _WINDOWS
    char text[1024];
    vsnprintf(text, sizeof(text), format, args);
    OutputDebugStringA(text);
    #else
    vfprintf(stderr, format, args);
    #endif
}
void halt(const char * format, ...) {
    va_list args;
    va_start(args, format);
    debugoutv(format, args);
    va_end(args);
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    exit(-1);
}
void ptr_hash(void* p, uint32_t* result) {
    #ifdef __32__
    *result = kh_int_hash_func((uintptr_t)p);
    #else
    *result = kh_int64_hash_func((uintptr_t)p);
    #endif
}
void ptr_isequal(void *p1, void* p2, bool* result) {
    *result = (p1 == p2);
}
void delete_cb_list_free(delete_cb_list* d) {
    if (d->next) {
        delete_cb_list_free(d->next);
    }
    free(d);
}
void delete_cb_list_add(delete_cb_list* d, delete_cb cb) {
    if (d->size < 5) {
        d->cb[d->size] = cb;
        d->size++;
    }
    else {
        if (!d->next) {
            d->next = (delete_cb_list*)malloc(sizeof(delete_cb_list));
        }
        delete_cb_list_add(d->next, cb);
    }
}
void delete_cb_list_remove(delete_cb_list* d, delete_cb cb) {
    for (int i = 0; i < d->size; i++) {
        if (d->cb[i]._parent == cb._parent && d->cb[i]._cb == cb._cb) {
            for (int j = i; j < d->size - 1; j++) {
                d->cb[j] = d->cb[j + 1];
            }
            d->size--;
        }
    }
    if (d->next) {
        delete_cb_list_remove(d->next, cb);
    }
}
void delete_cb_list_invoke(delete_cb_list* d, void* p) {
    for (int i = 0; i < d->size; i++) {
        d->cb[i]._cb(d->cb[i]._parent, p);
    }
    if (d->next) {
        delete_cb_list_invoke(d->next, p);
    }
}
KHASH_INIT_TYPEDEF(weakptr_hashtable_type, void*, delete_cb_list)
KHASH_INIT_FUNCTION(weakptr_hashtable_type, void*, delete_cb_list, 1, ptr_hash, ptr_isequal)
khash_t(weakptr_hashtable_type)* weakptr_hashtable;
void weakptr_init() {
    weakptr_hashtable = kh_init(weakptr_hashtable_type);
}
void weakptr_release(void* v) {
    khiter_t k = kh_get(weakptr_hashtable_type, weakptr_hashtable, v);
    if (k != kh_end(weakptr_hashtable)) {
        delete_cb_list* d = &kh_value(weakptr_hashtable, k);
        delete_cb_list_invoke(d, v);
        if (d->next) {
            delete_cb_list_free(d->next);
        }
        kh_del(weakptr_hashtable_type, weakptr_hashtable, k);
    }
}
void weakptr_cb_add(void* v, delete_cb cb) {
    delete_cb_list* d;
    khiter_t k = kh_get(weakptr_hashtable_type, weakptr_hashtable, v);
    if (k == kh_end(weakptr_hashtable)) {
        int ret;
        khiter_t k = kh_put(weakptr_hashtable_type, weakptr_hashtable, v, &ret);
        if (!ret) kh_del(weakptr_hashtable_type, weakptr_hashtable, k);
        d = &kh_value(weakptr_hashtable, k);
        d->size = 0;
        d->next = 0;
    }
    else {
        d = &kh_value(weakptr_hashtable, k);
    }
    delete_cb_list_add(d, cb);
}
void weakptr_cb_remove(void* v, delete_cb cb) {
    khiter_t k = kh_get(weakptr_hashtable_type, weakptr_hashtable, v);
    if (k != kh_end(weakptr_hashtable)) {
        delete_cb_list* d = &kh_value(weakptr_hashtable, k);
        delete_cb_list_remove(d, cb);
    }
}
KHASH_INIT_TYPEDEF(ptr_hashtable_type, void*, int)
KHASH_INIT_FUNCTION(ptr_hashtable_type, void*, int, 1, ptr_hash, ptr_isequal)
khash_t(ptr_hashtable_type)* ptr_hashtable;
void ptr_init() {
    ptr_hashtable = kh_init(ptr_hashtable_type);
}
void ptr_retain(void* v) {
    khiter_t k = kh_get(ptr_hashtable_type, ptr_hashtable, v);
    if (k == kh_end(ptr_hashtable)) {
        int ret;
        khiter_t k = kh_put(ptr_hashtable_type, ptr_hashtable, v, &ret);
        if (!ret) kh_del(ptr_hashtable_type, ptr_hashtable, k);
        kh_value(ptr_hashtable, k) = 1;
    }
    else {
        kh_value(ptr_hashtable, k)++;
    }
}
bool ptr_release(void* v) {
    khiter_t k = kh_get(ptr_hashtable_type, ptr_hashtable, v);
    if (k != kh_end(ptr_hashtable)) {
        kh_value(ptr_hashtable, k)--;
        if (kh_value(ptr_hashtable, k) == 0) {
            kh_del(ptr_hashtable_type, ptr_hashtable, k);
        }
        return false;
    }
    return true;
}
void weakptr_clear(void* parent, void* v) {
    void** p = (void**)parent;
    if (*p != v) {
        halt("weakptr was changed without clearing callback");
    }
    *p = 0;
}
#include <lib/common/object.c>
void sjf_callback(cb_i32_data_heap_data f, int32_t* _return) {
    cb_i32_data_heap_data sjt_callback4;
    sjs_data* sjt_dot3 = 0;
    int32_t sjt_functionParam4;
    sjs_data sjv_d = { -1 };

    sjt_callback4 = f;
    sjt_functionParam4 = 12;
    sjt_callback4._cb(sjt_callback4._parent, sjt_functionParam4, &sjv_d);
    sjt_dot3 = &sjv_d;
    (*_return) = sjt_dot3->x;

    if (sjv_d._refCount == 1) { sjf_data_destroy(&sjv_d); }
;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->b = _from->b;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_func(sjs_class* _parent, int32_t a, sjs_data* _return) {
    sjs_class* sjt_dot1 = 0;
    int32_t sjt_math7;
    int32_t sjt_math8;

    _return->_refCount = 1;
    sjt_math7 = a;
    sjt_dot1 = _parent;
    sjt_math8 = sjt_dot1->b;
    _return->x = sjt_math7 + sjt_math8;
    sjf_data(_return);
}

void sjf_class_func_heap(sjs_class* _parent, int32_t a, sjs_data** _return) {
    sjs_class* sjt_dot2 = 0;
    int32_t sjt_math10;
    int32_t sjt_math9;

    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
    sjt_math9 = a;
    sjt_dot2 = _parent;
    sjt_math10 = sjt_dot2->b;
    (*_return)->x = sjt_math9 + sjt_math10;
    sjf_data_heap((*_return));
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_data(sjs_data* _this) {
}

void sjf_data_copy(sjs_data* _this, sjs_data* _from) {
    _this->x = _from->x;
}

void sjf_data_destroy(sjs_data* _this) {
}

void sjf_data_heap(sjs_data* _this) {
}

void sjf_func(int32_t a, sjs_data* _return) {
    int32_t sjt_math3;
    int32_t sjt_math4;

    _return->_refCount = 1;
    sjt_math3 = a;
    sjt_math4 = 2;
    _return->x = sjt_math3 + sjt_math4;
    sjf_data(_return);
}

void sjf_func2_data(int32_t a, sjs_data* _return) {
    int32_t sjt_math11;
    int32_t sjt_math12;

    _return->_refCount = 1;
    sjt_math11 = a;
    sjt_math12 = 2;
    _return->x = sjt_math11 + sjt_math12;
    sjf_data(_return);
}

void sjf_func2_data_callback(void * _parent, int32_t a, sjs_data* _return) {
    sjf_func2_data(a, _return);
}

void sjf_func2_data_heap(int32_t a, sjs_data** _return) {
    int32_t sjt_math13;
    int32_t sjt_math14;

    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
    sjt_math13 = a;
    sjt_math14 = 2;
    (*_return)->x = sjt_math13 + sjt_math14;
    sjf_data_heap((*_return));
}

void sjf_func2_data_heap_callback(void * _parent, int32_t a, sjs_data** _return) {
    sjf_func2_data_heap(a, _return);
}

void sjf_func_callback(void * _parent, int32_t a, sjs_data* _return) {
    sjf_func(a, _return);
}

void sjf_func_heap(int32_t a, sjs_data** _return) {
    int32_t sjt_math5;
    int32_t sjt_math6;

    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
    sjt_math5 = a;
    sjt_math6 = 2;
    (*_return)->x = sjt_math5 + sjt_math6;
    sjf_data_heap((*_return));
}

void sjf_func_heap_callback(void * _parent, int32_t a, sjs_data** _return) {
    sjf_func_heap(a, _return);
}

void sjf_getcallback_heap(cb_i32_data_heap_data_heap* _return) {
    sjs_class* sjv_c = 0;

    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->b = 15;
    sjf_class_heap(sjv_c);
    (*_return).inner._parent = (sjs_object*)sjv_c;
    (*_return).inner._parent->_refCount++;
    (*_return)._destroy = (void(*)(sjs_object*))sjf_class_destroy;
    (*_return).inner._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
    (*_return).inner._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
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
    sjt_negate1 = 1;
    result1 = -sjt_negate1;
    sjt_math1 = result1;
    sjt_math2 = 2147483647;
    sjv_i32_maxvalue = sjt_math1 - sjt_math2;
    sjv_i32_minvalue = 2147483647;
    sjv_log._refCount = 1;
    sjv_log.minlevel = sjv_loglevel_warn;
    sjf_log(&sjv_log);
    sjv_emptystringdata = 0;
    sjv_emptystringdata = "";
    ptr_init();
    weakptr_init();
    sjv_a._parent = (sjs_object*)1;
    sjv_a._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
    sjv_a._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjt_callback1 = sjv_a;
    sjt_functionParam1 = 1;
    sjt_callback1._cb_heap(sjt_callback1._parent, sjt_functionParam1, &sjv_b);
    sjf_getcallback_heap(&sjv_l);
    sjt_callback2 = sjv_l.inner;
    sjt_functionParam2 = 1;
    sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam2, &sjv_m);
    sjt_callback3 = sjv_l.inner;
    sjt_functionParam3 = 1;
    sjt_callback3._cb_heap(sjt_callback3._parent, sjt_functionParam3, &sjv_n);
    sjv_c._refCount = 1;
    sjv_c.b = 15;
    sjf_class(&sjv_c);
    sjt_functionParam5._parent = (sjs_object*)1;
    sjt_functionParam5._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
    sjt_functionParam5._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjf_callback(sjt_functionParam5, &sjv_a2);
    sjt_functionParam6._parent = (sjs_object*)&sjv_c;
    sjt_functionParam6._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
    sjt_functionParam6._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;
    sjf_callback(sjt_functionParam6, &sjv_b2);
    sjv_f1._parent = (sjs_object*)1;
    sjv_f1._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
    sjv_f1._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjt_callback5 = sjv_f1;
    sjt_functionParam7 = 1;
    sjt_callback5._cb(sjt_callback5._parent, sjt_functionParam7, &sjv_d);
    sjv_f2._parent = (sjs_object*)&sjv_c;
    sjv_f2._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
    sjv_f2._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;
    sjt_callback6 = sjv_f2;
    sjt_functionParam8 = 2;
    sjt_callback6._cb(sjt_callback6._parent, sjt_functionParam8, &sjv_e);
    sjv_c_heap = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c_heap->_refCount = 1;
    sjv_c_heap->b = 15;
    sjf_class_heap(sjv_c_heap);
    sjv_f3.inner._parent = (sjs_object*)sjv_c_heap;
    sjv_f3.inner._parent->_refCount++;
    sjv_f3._destroy = (void(*)(sjs_object*))sjf_class_destroy;
    sjv_f3.inner._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
    sjv_f3.inner._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;
    sjt_callback7 = sjv_f3.inner;
    sjt_functionParam9 = 3;
    sjt_callback7._cb(sjt_callback7._parent, sjt_functionParam9, &sjv_g);
    sjv_h._parent = 0;
    sjt_value1._parent = (sjs_object*)1;
    sjt_value1._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
    sjt_value1._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjv_i = sjt_value1;
    sjt_getValue1 = sjv_i;
    if (sjt_getValue1._parent == 0) { exit(-1); }
    sjv_j = sjt_getValue1;
    sjt_callback8 = sjv_j;
    sjt_functionParam10 = 12;
    sjt_callback8._cb(sjt_callback8._parent, sjt_functionParam10, &sjv_k);
    sjv_o._parent = (sjs_object*)1;
    sjv_o._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func2_data_callback;
    sjv_o._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func2_data_heap_callback;
    sjt_callback9 = sjv_l.inner;
    sjt_functionParam11 = 1;
    sjt_callback9._cb(sjt_callback9._parent, sjt_functionParam11, &sjv_p);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjv_b->_refCount--;
    if (sjv_b->_refCount <= 0) {
        weakptr_release(sjv_b);
        sjf_data_destroy(sjv_b);
        free(sjv_b);
    }
    sjv_c_heap->_refCount--;
    if (sjv_c_heap->_refCount <= 0) {
        weakptr_release(sjv_c_heap);
        sjf_class_destroy(sjv_c_heap);
        free(sjv_c_heap);
    }
    if ((uintptr_t)sjv_f3.inner._parent > 1) {
        sjv_f3.inner._parent->_refCount--;
        if (sjv_f3.inner._parent->_refCount <= 0) {
            sjv_f3._destroy(sjv_f3.inner._parent);
            free(sjv_f3.inner._parent);
        }
    }
    if ((uintptr_t)sjv_l.inner._parent > 1) {
        sjv_l.inner._parent->_refCount--;
        if (sjv_l.inner._parent->_refCount <= 0) {
            sjv_l._destroy(sjv_l.inner._parent);
            free(sjv_l.inner._parent);
        }
    }
    sjv_n->_refCount--;
    if (sjv_n->_refCount <= 0) {
        weakptr_release(sjv_n);
        sjf_data_destroy(sjv_n);
        free(sjv_n);
    }
    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
;
    if (sjv_d._refCount == 1) { sjf_data_destroy(&sjv_d); }
;
    if (sjv_e._refCount == 1) { sjf_data_destroy(&sjv_e); }
;
    if (sjv_g._refCount == 1) { sjf_data_destroy(&sjv_g); }
;
    if (sjv_k._refCount == 1) { sjf_data_destroy(&sjv_k); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_m._refCount == 1) { sjf_data_destroy(&sjv_m); }
;
    if (sjv_p._refCount == 1) { sjf_data_destroy(&sjv_p); }
;
}
