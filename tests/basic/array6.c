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
#define sjs_array_i32_typeId 3
#define sjs_array_f32_typeId 4
#define cb_i32_f32_typeId 5
#define cb_i32_f32_heap_typeId 6
#define cb_f32_bool_typeId 7
#define cb_f32_bool_heap_typeId 8
#define sjs_sum_typeId 9
#define cb_sum_f32_sum_typeId 10
#define cb_sum_f32_sum_heap_typeId 11
#define cb_sum_f32_sum_heap_sum_typeId 12
#define cb_sum_f32_sum_heap_sum_heap_typeId 13

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sjs_array_f32 sjs_array_f32;
typedef struct td_cb_i32_f32 cb_i32_f32;
typedef struct td_cb_i32_f32_heap cb_i32_f32_heap;
typedef struct td_cb_f32_bool cb_f32_bool;
typedef struct td_cb_f32_bool_heap cb_f32_bool_heap;
typedef struct td_sjs_sum sjs_sum;
typedef struct td_cb_sum_f32_sum cb_sum_f32_sum;
typedef struct td_cb_sum_f32_sum_heap cb_sum_f32_sum_heap;
typedef struct td_cb_sum_f32_sum_heap_sum cb_sum_f32_sum_heap_sum;
typedef struct td_cb_sum_f32_sum_heap_sum_heap cb_sum_f32_sum_heap_sum_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_array_i32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_array_f32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_cb_i32_f32 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, int32_t, float* _return);
};

struct td_cb_i32_f32_heap {
    cb_i32_f32 inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_f32_bool {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, float, bool* _return);
};

struct td_cb_f32_bool_heap {
    cb_f32_bool inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_sum {
    int _refCount;
    float x;
};

struct td_cb_sum_f32_sum {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_sum*, float, sjs_sum* _return);
};

struct td_cb_sum_f32_sum_heap {
    cb_sum_f32_sum inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_sum_f32_sum_heap_sum {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_sum*, float, sjs_sum* _return);
    void (*_cb_heap)(sjs_object* _parent, sjs_sum*, float, sjs_sum** _return);
};

struct td_cb_sum_f32_sum_heap_sum_heap {
    cb_sum_f32_sum_heap_sum inner;
    void (*_destroy)(sjs_object*);
};

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
int32_t result1;
sjs_sum sjt_call3 = { -1 };
int32_t sjt_functionParam1;
cb_i32_f32 sjt_functionParam11;
cb_f32_bool sjt_functionParam16;
int32_t sjt_functionParam2;
sjs_sum* sjt_functionParam23 = 0;
cb_sum_f32_sum sjt_functionParam24;
int32_t sjt_functionParam3;
int32_t sjt_functionParam4;
int32_t sjt_functionParam5;
int32_t sjt_functionParam6;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_array_i32* sjt_parent1 = 0;
sjs_array_i32* sjt_parent2 = 0;
sjs_array_i32* sjt_parent3 = 0;
sjs_array_i32* sjt_parent4 = 0;
sjs_array_f32* sjt_parent5 = 0;
sjs_array_f32* sjt_parent6 = 0;
sjs_array_i32 sjv_a = { -1 };
sjs_array_f32 sjv_b = { -1 };
sjs_array_f32 sjv_c = { -1 };
sjs_sum sjv_d = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
uint32_t sjv_u32_maxvalue;

void sjf_array_f32(sjs_array_f32* _this);
void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from);
void sjf_array_f32_destroy(sjs_array_f32* _this);
void sjf_array_f32_filter(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32* _return);
void sjf_array_f32_filter_heap(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32** _return);
void sjf_array_f32_foldl_sum(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum* _return);
void sjf_array_f32_foldl_sum_heap(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum** _return);
void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return);
void sjf_array_f32_heap(sjs_array_f32* _this);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_i32_map_f32(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32* _return);
void sjf_array_i32_map_f32_heap(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32** _return);
void sjf_double(int32_t x, float* _return);
void sjf_double_callback(void * _parent, int32_t x, float* _return);
void sjf_lessthan5(float x, bool* _return);
void sjf_lessthan5_callback(void * _parent, float x, bool* _return);
void sjf_sum(sjs_sum* _this);
void sjf_sum_copy(sjs_sum* _this, sjs_sum* _from);
void sjf_sum_destroy(sjs_sum* _this);
void sjf_sum_heap(sjs_sum* _this);
void sjf_sumadd(sjs_sum* sum, float x, sjs_sum* _return);
void sjf_sumadd_callback(void * _parent, sjs_sum* sum, float x, sjs_sum* _return);
void sjf_sumadd_heap(sjs_sum* sum, float x, sjs_sum** _return);
void main_destroy(void);

void halt(const char * format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
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
void sjf_array_f32(sjs_array_f32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(float));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_f32_destroy(sjs_array_f32* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            float* p = (float*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_f32_filter(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32* _return) {
    int32_t i;
    sjs_array_f32* sjt_dot7 = 0;
    sjs_array_f32* sjt_dot8 = 0;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;
    int32_t sjv_newcount;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newcount = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart3 = 0;
    sjt_dot7 = _parent;
    sjt_forEnd3 = sjt_dot7->count;
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        cb_f32_bool sjt_callback3;
        int32_t sjt_functionParam12;
        float sjt_functionParam13;
        bool sjt_ifElse1;
        float sjv_item;

        sjt_functionParam12 = i;
        sjf_array_f32_getat(_parent, sjt_functionParam12, &sjv_item);
        sjt_callback3 = cb;
        sjt_functionParam13 = sjv_item;
        sjt_callback3._cb(sjt_callback3._parent, sjt_functionParam13, &sjt_ifElse1);
        if (sjt_ifElse1) {
            int32_t sjt_math5;
            int32_t sjt_math6;

            float* p = (float*)sjv_newdata;
            p[sjv_newcount] = sjv_item;
;
            sjt_math5 = sjv_newcount;
            sjt_math6 = 1;
            sjv_newcount = sjt_math5 + sjt_math6;
        }

        i++;
    }

    _return->_refCount = 1;
    sjt_dot8 = _parent;
    _return->datasize = sjt_dot8->count;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    _return->count = sjv_newcount;
    sjf_array_f32(_return);
}

void sjf_array_f32_filter_heap(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32** _return) {
    int32_t i;
    sjs_array_f32* sjt_dot10 = 0;
    sjs_array_f32* sjt_dot9 = 0;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    int32_t sjv_newcount;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newcount = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart4 = 0;
    sjt_dot9 = _parent;
    sjt_forEnd4 = sjt_dot9->count;
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        cb_f32_bool sjt_callback4;
        int32_t sjt_functionParam14;
        float sjt_functionParam15;
        bool sjt_ifElse2;
        float sjv_item;

        sjt_functionParam14 = i;
        sjf_array_f32_getat(_parent, sjt_functionParam14, &sjv_item);
        sjt_callback4 = cb;
        sjt_functionParam15 = sjv_item;
        sjt_callback4._cb(sjt_callback4._parent, sjt_functionParam15, &sjt_ifElse2);
        if (sjt_ifElse2) {
            int32_t sjt_math7;
            int32_t sjt_math8;

            float* p = (float*)sjv_newdata;
            p[sjv_newcount] = sjv_item;
;
            sjt_math7 = sjv_newcount;
            sjt_math8 = 1;
            sjv_newcount = sjt_math7 + sjt_math8;
        }

        i++;
    }

    (*_return) = (sjs_array_f32*)malloc(sizeof(sjs_array_f32));
    (*_return)->_refCount = 1;
    sjt_dot10 = _parent;
    (*_return)->datasize = sjt_dot10->count;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    (*_return)->count = sjv_newcount;
    sjf_array_f32_heap((*_return));
}

void sjf_array_f32_foldl_sum(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum* _return) {
    int32_t i;
    sjs_sum* sjt_copy1 = 0;
    sjs_array_f32* sjt_dot11 = 0;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;
    sjs_sum* sjv_r = 0;

    sjv_r = initial;
    sjt_forStart5 = 0;
    sjt_dot11 = _parent;
    sjt_forEnd5 = sjt_dot11->count;
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        sjs_sum sjt_call1 = { -1 };
        cb_sum_f32_sum sjt_callback5;
        sjs_sum* sjt_functionParam17 = 0;
        float sjt_functionParam18;
        int32_t sjt_functionParam19;

        sjt_callback5 = cb;
        sjt_functionParam17 = sjv_r;
        sjt_functionParam19 = i;
        sjf_array_f32_getat(_parent, sjt_functionParam19, &sjt_functionParam18);
        sjt_callback5._cb(sjt_callback5._parent, sjt_functionParam17, sjt_functionParam18, &sjt_call1);
        sjv_r = &sjt_call1;
        i++;

        if (sjt_call1._refCount == 1) { sjf_sum_destroy(&sjt_call1); }
    }

    sjt_copy1 = sjv_r;
    _return->_refCount = 1;
    sjf_sum_copy(_return, sjt_copy1);
}

void sjf_array_f32_foldl_sum_heap(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum** _return) {
    int32_t i;
    sjs_sum* sjt_copy2 = 0;
    sjs_array_f32* sjt_dot12 = 0;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;
    sjs_sum* sjv_r = 0;

    sjv_r = initial;
    sjt_forStart6 = 0;
    sjt_dot12 = _parent;
    sjt_forEnd6 = sjt_dot12->count;
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        sjs_sum sjt_call2 = { -1 };
        cb_sum_f32_sum sjt_callback6;
        sjs_sum* sjt_functionParam20 = 0;
        float sjt_functionParam21;
        int32_t sjt_functionParam22;

        sjt_callback6 = cb;
        sjt_functionParam20 = sjv_r;
        sjt_functionParam22 = i;
        sjf_array_f32_getat(_parent, sjt_functionParam22, &sjt_functionParam21);
        sjt_callback6._cb(sjt_callback6._parent, sjt_functionParam20, sjt_functionParam21, &sjt_call2);
        sjv_r = &sjt_call2;
        i++;

        if (sjt_call2._refCount == 1) { sjf_sum_destroy(&sjt_call2); }
    }

    sjt_copy2 = sjv_r;
    (*_return) = (sjs_sum*)malloc(sizeof(sjs_sum));
    (*_return)->_refCount = 1;
    sjf_sum_copy((*_return), sjt_copy2);
}

void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    float* p = (float*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_f32_heap(sjs_array_f32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(float));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32(sjs_array_i32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(int32_t));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            int32_t* p = (int32_t*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    int32_t* p = (int32_t*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_i32_heap(sjs_array_i32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(int32_t));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    int32_t* p = (int32_t*)_parent->data;
    p[index] = item;
;
    _parent->count = index + 1;
}

void sjf_array_i32_map_f32(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32* _return) {
    int32_t i;
    sjs_array_i32* sjt_dot1 = 0;
    sjs_array_i32* sjt_dot2 = 0;
    sjs_array_i32* sjt_dot3 = 0;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart1 = 0;
    sjt_dot1 = _parent;
    sjt_forEnd1 = sjt_dot1->count;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        cb_i32_f32 sjt_callback1;
        int32_t sjt_functionParam7;
        int32_t sjt_functionParam8;
        float sjv_newitem;

        sjt_callback1 = cb;
        sjt_functionParam8 = i;
        sjf_array_i32_getat(_parent, sjt_functionParam8, &sjt_functionParam7);
        sjt_callback1._cb(sjt_callback1._parent, sjt_functionParam7, &sjv_newitem);
        float* p = (float*)sjv_newdata;
        p[i] = sjv_newitem;
;
        i++;
    }

    _return->_refCount = 1;
    sjt_dot2 = _parent;
    _return->datasize = sjt_dot2->count;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot3 = _parent;
    _return->count = sjt_dot3->count;
    sjf_array_f32(_return);
}

void sjf_array_i32_map_f32_heap(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32** _return) {
    int32_t i;
    sjs_array_i32* sjt_dot4 = 0;
    sjs_array_i32* sjt_dot5 = 0;
    sjs_array_i32* sjt_dot6 = 0;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart2 = 0;
    sjt_dot4 = _parent;
    sjt_forEnd2 = sjt_dot4->count;
    i = sjt_forStart2;
    while (i < sjt_forEnd2) {
        cb_i32_f32 sjt_callback2;
        int32_t sjt_functionParam10;
        int32_t sjt_functionParam9;
        float sjv_newitem;

        sjt_callback2 = cb;
        sjt_functionParam10 = i;
        sjf_array_i32_getat(_parent, sjt_functionParam10, &sjt_functionParam9);
        sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam9, &sjv_newitem);
        float* p = (float*)sjv_newdata;
        p[i] = sjv_newitem;
;
        i++;
    }

    (*_return) = (sjs_array_f32*)malloc(sizeof(sjs_array_f32));
    (*_return)->_refCount = 1;
    sjt_dot5 = _parent;
    (*_return)->datasize = sjt_dot5->count;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot6 = _parent;
    (*_return)->count = sjt_dot6->count;
    sjf_array_f32_heap((*_return));
}

void sjf_double(int32_t x, float* _return) {
    int32_t sjt_cast1;
    float sjt_math3;
    float sjt_math4;

    sjt_cast1 = x;
    sjt_math3 = (float)sjt_cast1;
    sjt_math4 = 2.0f;
    (*_return) = sjt_math3 * sjt_math4;
}

void sjf_double_callback(void * _parent, int32_t x, float* _return) {
    sjf_double(x, _return);
}

void sjf_lessthan5(float x, bool* _return) {
    float sjt_compare1;
    float sjt_compare2;

    sjt_compare1 = x;
    sjt_compare2 = 5.0f;
    (*_return) = sjt_compare1 < sjt_compare2;
}

void sjf_lessthan5_callback(void * _parent, float x, bool* _return) {
    sjf_lessthan5(x, _return);
}

void sjf_sum(sjs_sum* _this) {
}

void sjf_sum_copy(sjs_sum* _this, sjs_sum* _from) {
    _this->x = _from->x;
}

void sjf_sum_destroy(sjs_sum* _this) {
}

void sjf_sum_heap(sjs_sum* _this) {
}

void sjf_sumadd(sjs_sum* sum, float x, sjs_sum* _return) {
    sjs_sum* sjt_dot13 = 0;
    float sjt_math10;
    float sjt_math9;

    _return->_refCount = 1;
    sjt_dot13 = sum;
    sjt_math9 = sjt_dot13->x;
    sjt_math10 = x;
    _return->x = sjt_math9 + sjt_math10;
    sjf_sum(_return);
}

void sjf_sumadd_callback(void * _parent, sjs_sum* sum, float x, sjs_sum* _return) {
    sjf_sumadd(sum, x, _return);
}

void sjf_sumadd_heap(sjs_sum* sum, float x, sjs_sum** _return) {
    sjs_sum* sjt_dot14 = 0;
    float sjt_math11;
    float sjt_math12;

    (*_return) = (sjs_sum*)malloc(sizeof(sjs_sum));
    (*_return)->_refCount = 1;
    sjt_dot14 = sum;
    sjt_math11 = sjt_dot14->x;
    sjt_math12 = x;
    (*_return)->x = sjt_math11 + sjt_math12;
    sjf_sum_heap((*_return));
}

int main(int argc, char** argv) {
    sjv_f32_pi = 3.14159265358979323846f;
    sjv_u32_maxvalue = (uint32_t)4294967295u;
    sjt_negate1 = 1;
    result1 = -sjt_negate1;
    sjt_math1 = result1;
    sjt_math2 = 2147483647;
    sjv_i32_maxvalue = sjt_math1 - sjt_math2;
    sjv_i32_minvalue = 2147483647;
    sjv_emptystringdata = 0;
    sjv_emptystringdata = "";
    ptr_init();
    weakptr_init();
    sjv_a._refCount = 1;
    sjv_a.datasize = 3;
    sjv_a.data = 0;
    sjv_a._isglobal = false;
    sjv_a.count = 0;
    sjf_array_i32(&sjv_a);
    sjs_array_i32* array1;
    array1 = &sjv_a;
    sjt_parent1 = array1;
    sjt_functionParam1 = 0;
    sjt_functionParam2 = 1;
    sjf_array_i32_initat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent2 = array1;
    sjt_functionParam3 = 1;
    sjt_functionParam4 = 2;
    sjf_array_i32_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
    sjt_parent3 = array1;
    sjt_functionParam5 = 2;
    sjt_functionParam6 = 3;
    sjf_array_i32_initat(sjt_parent3, sjt_functionParam5, sjt_functionParam6);
    sjt_parent4 = &sjv_a;
    sjt_functionParam11._parent = (sjs_object*)1;
    sjt_functionParam11._cb = (void(*)(sjs_object*,int32_t, float*))sjf_double_callback;
    sjf_array_i32_map_f32(sjt_parent4, sjt_functionParam11, &sjv_b);
    sjt_parent5 = &sjv_b;
    sjt_functionParam16._parent = (sjs_object*)1;
    sjt_functionParam16._cb = (void(*)(sjs_object*,float, bool*))sjf_lessthan5_callback;
    sjf_array_f32_filter(sjt_parent5, sjt_functionParam16, &sjv_c);
    sjt_parent6 = &sjv_c;
    sjt_call3._refCount = 1;
    sjt_call3.x = 0.0f;
    sjf_sum(&sjt_call3);
    sjt_functionParam23 = &sjt_call3;
    sjt_functionParam24._parent = (sjs_object*)1;
    sjt_functionParam24._cb = (void(*)(sjs_object*,sjs_sum*,float, sjs_sum*))sjf_sumadd_callback;
    sjf_array_f32_foldl_sum(sjt_parent6, sjt_functionParam23, sjt_functionParam24, &sjv_d);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_call3._refCount == 1) { sjf_sum_destroy(&sjt_call3); }
    if (sjv_a._refCount == 1) { sjf_array_i32_destroy(&sjv_a); }
    if (sjv_b._refCount == 1) { sjf_array_f32_destroy(&sjv_b); }
    if (sjv_c._refCount == 1) { sjf_array_f32_destroy(&sjv_c); }
    if (sjv_d._refCount == 1) { sjf_sum_destroy(&sjv_d); }
}
