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
#define sjs_fancymath_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_fancymath sjs_fancymath;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_fancymath {
    int _refCount;
    int32_t x;
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
sjs_fancymath* sjt_functionParam1 = 0;
int32_t sjt_functionParam10;
int32_t sjt_functionParam11;
sjs_fancymath* sjt_functionParam2 = 0;
sjs_fancymath* sjt_functionParam3 = 0;
sjs_fancymath* sjt_functionParam4 = 0;
sjs_fancymath* sjt_functionParam5 = 0;
sjs_fancymath* sjt_functionParam6 = 0;
sjs_fancymath* sjt_functionParam7 = 0;
sjs_fancymath* sjt_functionParam8 = 0;
sjs_fancymath* sjt_functionParam9 = 0;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_fancymath* sjt_parent12 = 0;
sjs_fancymath* sjt_parent15 = 0;
sjs_fancymath* sjt_parent16 = 0;
sjs_fancymath* sjt_parent17 = 0;
sjs_fancymath* sjt_parent18 = 0;
sjs_fancymath* sjt_parent19 = 0;
sjs_fancymath* sjt_parent20 = 0;
sjs_fancymath* sjt_parent21 = 0;
sjs_fancymath* sjt_parent22 = 0;
sjs_fancymath* sjt_parent23 = 0;
sjs_fancymath* sjt_parent24 = 0;
sjs_fancymath* sjt_parent3 = 0;
sjs_fancymath* sjt_parent6 = 0;
sjs_fancymath* sjt_parent9 = 0;
sjs_fancymath sjv_a = { -1 };
sjs_fancymath sjv_b = { -1 };
sjs_fancymath sjv_c = { -1 };
sjs_fancymath sjv_d = { -1 };
sjs_fancymath sjv_e = { -1 };
void* sjv_emptystringdata;
sjs_fancymath sjv_f = { -1 };
float sjv_f32_pi;
sjs_fancymath sjv_g = { -1 };
int32_t sjv_i;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
int32_t sjv_ii;
int32_t sjv_j;
sjs_fancymath sjv_k = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_fancymath(sjs_fancymath* _this);
void sjf_fancymath_add(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_add_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_copy(sjs_fancymath* _this, sjs_fancymath* _from);
void sjf_fancymath_destroy(sjs_fancymath* _this);
void sjf_fancymath_divide(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_divide_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_dividei32(sjs_fancymath* _parent, int32_t num, sjs_fancymath* _return);
void sjf_fancymath_dividei32_heap(sjs_fancymath* _parent, int32_t num, sjs_fancymath** _return);
void sjf_fancymath_getx(sjs_fancymath* _parent, int32_t* _return);
void sjf_fancymath_heap(sjs_fancymath* _this);
void sjf_fancymath_increment(sjs_fancymath* _parent, sjs_fancymath* _return);
void sjf_fancymath_increment_heap(sjs_fancymath* _parent, sjs_fancymath** _return);
void sjf_fancymath_modulus(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_modulus_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_multiply(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_multiply_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_setbob(sjs_fancymath* _parent, int32_t i, int32_t* _return);
void sjf_fancymath_subtract(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_subtract_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
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
void sjf_fancymath(sjs_fancymath* _this) {
}

void sjf_fancymath_add(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot1 = 0;
    int32_t sjt_math3;
    int32_t sjt_math4;
    int32_t sjt_math5;
    int32_t sjt_math6;
    sjs_fancymath* sjt_parent1 = 0;

    _return->_refCount = 1;
    sjt_dot1 = _parent;
    sjt_math5 = sjt_dot1->x;
    sjt_parent1 = num;
    sjf_fancymath_getx(sjt_parent1, &sjt_math6);
    sjt_math3 = sjt_math5 + sjt_math6;
    sjt_math4 = 1;
    _return->x = sjt_math3 + sjt_math4;
    sjf_fancymath(_return);
}

void sjf_fancymath_add_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot3 = 0;
    int32_t sjt_math10;
    int32_t sjt_math7;
    int32_t sjt_math8;
    int32_t sjt_math9;
    sjs_fancymath* sjt_parent2 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot3 = _parent;
    sjt_math9 = sjt_dot3->x;
    sjt_parent2 = num;
    sjf_fancymath_getx(sjt_parent2, &sjt_math10);
    sjt_math7 = sjt_math9 + sjt_math10;
    sjt_math8 = 1;
    (*_return)->x = sjt_math7 + sjt_math8;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_copy(sjs_fancymath* _this, sjs_fancymath* _from) {
    _this->x = _from->x;
}

void sjf_fancymath_destroy(sjs_fancymath* _this) {
}

void sjf_fancymath_divide(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot8 = 0;
    int32_t sjt_math27;
    int32_t sjt_math28;
    int32_t sjt_math29;
    int32_t sjt_math30;
    sjs_fancymath* sjt_parent10 = 0;

    _return->_refCount = 1;
    sjt_dot8 = _parent;
    sjt_math29 = sjt_dot8->x;
    sjt_parent10 = num;
    sjf_fancymath_getx(sjt_parent10, &sjt_math30);
    sjt_math27 = sjt_math29 / sjt_math30;
    sjt_math28 = 1;
    _return->x = sjt_math27 + sjt_math28;
    sjf_fancymath(_return);
}

void sjf_fancymath_divide_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot9 = 0;
    int32_t sjt_math31;
    int32_t sjt_math32;
    int32_t sjt_math33;
    int32_t sjt_math34;
    sjs_fancymath* sjt_parent11 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot9 = _parent;
    sjt_math33 = sjt_dot9->x;
    sjt_parent11 = num;
    sjf_fancymath_getx(sjt_parent11, &sjt_math34);
    sjt_math31 = sjt_math33 / sjt_math34;
    sjt_math32 = 1;
    (*_return)->x = sjt_math31 + sjt_math32;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_dividei32(sjs_fancymath* _parent, int32_t num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot15 = 0;
    int32_t sjt_math47;
    int32_t sjt_math48;
    int32_t sjt_math49;
    int32_t sjt_math50;

    _return->_refCount = 1;
    sjt_dot15 = _parent;
    sjt_math49 = sjt_dot15->x;
    sjt_math50 = num;
    sjt_math47 = sjt_math49 / sjt_math50;
    sjt_math48 = 1;
    _return->x = sjt_math47 + sjt_math48;
    sjf_fancymath(_return);
}

void sjf_fancymath_dividei32_heap(sjs_fancymath* _parent, int32_t num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot16 = 0;
    int32_t sjt_math51;
    int32_t sjt_math52;
    int32_t sjt_math53;
    int32_t sjt_math54;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot16 = _parent;
    sjt_math53 = sjt_dot16->x;
    sjt_math54 = num;
    sjt_math51 = sjt_math53 / sjt_math54;
    sjt_math52 = 1;
    (*_return)->x = sjt_math51 + sjt_math52;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_getx(sjs_fancymath* _parent, int32_t* _return) {
    sjs_fancymath* sjt_dot2 = 0;

    sjt_dot2 = _parent;
    (*_return) = sjt_dot2->x;
}

void sjf_fancymath_heap(sjs_fancymath* _this) {
}

void sjf_fancymath_increment(sjs_fancymath* _parent, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot12 = 0;
    int32_t sjt_math43;
    int32_t sjt_math44;

    _return->_refCount = 1;
    sjt_dot12 = _parent;
    sjt_math43 = sjt_dot12->x;
    sjt_math44 = 1;
    _return->x = sjt_math43 + sjt_math44;
    sjf_fancymath(_return);
}

void sjf_fancymath_increment_heap(sjs_fancymath* _parent, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot13 = 0;
    int32_t sjt_math45;
    int32_t sjt_math46;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot13 = _parent;
    sjt_math45 = sjt_dot13->x;
    sjt_math46 = 1;
    (*_return)->x = sjt_math45 + sjt_math46;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_modulus(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot10 = 0;
    int32_t sjt_math35;
    int32_t sjt_math36;
    int32_t sjt_math37;
    int32_t sjt_math38;
    sjs_fancymath* sjt_parent13 = 0;

    _return->_refCount = 1;
    sjt_dot10 = _parent;
    sjt_math37 = sjt_dot10->x;
    sjt_parent13 = num;
    sjf_fancymath_getx(sjt_parent13, &sjt_math38);
    sjt_math35 = sjt_math37 % sjt_math38;
    sjt_math36 = 1;
    _return->x = sjt_math35 + sjt_math36;
    sjf_fancymath(_return);
}

void sjf_fancymath_modulus_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot11 = 0;
    int32_t sjt_math39;
    int32_t sjt_math40;
    int32_t sjt_math41;
    int32_t sjt_math42;
    sjs_fancymath* sjt_parent14 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot11 = _parent;
    sjt_math41 = sjt_dot11->x;
    sjt_parent14 = num;
    sjf_fancymath_getx(sjt_parent14, &sjt_math42);
    sjt_math39 = sjt_math41 % sjt_math42;
    sjt_math40 = 1;
    (*_return)->x = sjt_math39 + sjt_math40;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_multiply(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot6 = 0;
    int32_t sjt_math19;
    int32_t sjt_math20;
    int32_t sjt_math21;
    int32_t sjt_math22;
    sjs_fancymath* sjt_parent7 = 0;

    _return->_refCount = 1;
    sjt_dot6 = _parent;
    sjt_math21 = sjt_dot6->x;
    sjt_parent7 = num;
    sjf_fancymath_getx(sjt_parent7, &sjt_math22);
    sjt_math19 = sjt_math21 * sjt_math22;
    sjt_math20 = 1;
    _return->x = sjt_math19 + sjt_math20;
    sjf_fancymath(_return);
}

void sjf_fancymath_multiply_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot7 = 0;
    int32_t sjt_math23;
    int32_t sjt_math24;
    int32_t sjt_math25;
    int32_t sjt_math26;
    sjs_fancymath* sjt_parent8 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot7 = _parent;
    sjt_math25 = sjt_dot7->x;
    sjt_parent8 = num;
    sjf_fancymath_getx(sjt_parent8, &sjt_math26);
    sjt_math23 = sjt_math25 * sjt_math26;
    sjt_math24 = 1;
    (*_return)->x = sjt_math23 + sjt_math24;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_setbob(sjs_fancymath* _parent, int32_t i, int32_t* _return) {
    sjs_fancymath* sjt_dot14 = 0;

    sjt_dot14 = _parent;
    sjt_dot14->x = i;
    (*_return) = sjt_dot14->x;
}

void sjf_fancymath_subtract(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot4 = 0;
    int32_t sjt_math11;
    int32_t sjt_math12;
    int32_t sjt_math13;
    int32_t sjt_math14;
    sjs_fancymath* sjt_parent4 = 0;

    _return->_refCount = 1;
    sjt_dot4 = _parent;
    sjt_math13 = sjt_dot4->x;
    sjt_parent4 = num;
    sjf_fancymath_getx(sjt_parent4, &sjt_math14);
    sjt_math11 = sjt_math13 - sjt_math14;
    sjt_math12 = 1;
    _return->x = sjt_math11 + sjt_math12;
    sjf_fancymath(_return);
}

void sjf_fancymath_subtract_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot5 = 0;
    int32_t sjt_math15;
    int32_t sjt_math16;
    int32_t sjt_math17;
    int32_t sjt_math18;
    sjs_fancymath* sjt_parent5 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot5 = _parent;
    sjt_math17 = sjt_dot5->x;
    sjt_parent5 = num;
    sjf_fancymath_getx(sjt_parent5, &sjt_math18);
    sjt_math15 = sjt_math17 - sjt_math18;
    sjt_math16 = 1;
    (*_return)->x = sjt_math15 + sjt_math16;
    sjf_fancymath_heap((*_return));
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
    sjv_a.x = 1;
    sjf_fancymath(&sjv_a);
    sjv_b._refCount = 1;
    sjv_b.x = 2;
    sjf_fancymath(&sjv_b);
    sjv_ii = 2;
    sjt_parent3 = &sjv_a;
    sjt_functionParam1 = &sjv_b;
    sjf_fancymath_add(sjt_parent3, sjt_functionParam1, &sjv_c);
    sjt_parent6 = &sjv_a;
    sjt_functionParam2 = &sjv_b;
    sjf_fancymath_subtract(sjt_parent6, sjt_functionParam2, &sjv_d);
    sjt_parent9 = &sjv_a;
    sjt_functionParam3 = &sjv_b;
    sjf_fancymath_multiply(sjt_parent9, sjt_functionParam3, &sjv_e);
    sjt_parent12 = &sjv_a;
    sjt_functionParam4 = &sjv_b;
    sjf_fancymath_divide(sjt_parent12, sjt_functionParam4, &sjv_f);
    sjt_parent15 = &sjv_a;
    sjt_functionParam5 = &sjv_b;
    sjf_fancymath_modulus(sjt_parent15, sjt_functionParam5, &sjv_g);
    sjt_parent16 = &sjv_c;
    sjt_functionParam6 = &sjv_c;
    sjf_fancymath_add(sjt_parent16, sjt_functionParam6, &sjv_c);
    sjt_parent17 = &sjv_d;
    sjt_functionParam7 = &sjv_d;
    sjf_fancymath_subtract(sjt_parent17, sjt_functionParam7, &sjv_d);
    sjt_parent18 = &sjv_d;
    sjt_functionParam8 = &sjv_d;
    sjf_fancymath_multiply(sjt_parent18, sjt_functionParam8, &sjv_d);
    sjt_parent19 = &sjv_d;
    sjt_functionParam9 = &sjv_d;
    sjf_fancymath_divide(sjt_parent19, sjt_functionParam9, &sjv_d);
    sjt_parent20 = &sjv_e;
    sjf_fancymath_increment(sjt_parent20, &sjv_e);
    sjt_parent21 = &sjv_f;
    sjf_fancymath_increment(sjt_parent21, &sjv_f);
    sjt_parent22 = &sjv_f;
    sjf_fancymath_getx(sjt_parent22, &sjv_i);
    sjt_parent23 = &sjv_a;
    sjt_functionParam10 = 12;
    sjf_fancymath_setbob(sjt_parent23, sjt_functionParam10, &sjv_j);
    sjt_parent24 = &sjv_a;
    sjt_functionParam11 = sjv_ii;
    sjf_fancymath_dividei32(sjt_parent24, sjt_functionParam11, &sjv_k);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_a._refCount == 1) { sjf_fancymath_destroy(&sjv_a); }
    if (sjv_b._refCount == 1) { sjf_fancymath_destroy(&sjv_b); }
    if (sjv_c._refCount == 1) { sjf_fancymath_destroy(&sjv_c); }
    if (sjv_d._refCount == 1) { sjf_fancymath_destroy(&sjv_d); }
    if (sjv_e._refCount == 1) { sjf_fancymath_destroy(&sjv_e); }
    if (sjv_f._refCount == 1) { sjf_fancymath_destroy(&sjv_f); }
    if (sjv_g._refCount == 1) { sjf_fancymath_destroy(&sjv_g); }
    if (sjv_k._refCount == 1) { sjf_fancymath_destroy(&sjv_k); }
}
