#ifdef __GNUC__
#if __x86_64__ 
#define __LINUX__
#define __64__
#elif __i386__ 
#define __LINUX__
#define __32__
#else
Invalid bits
#endif
#elif _MSC_VER
#if _WIN64 
#define __WINDOWS__
#define __64__
#elif _WIN32 
#define __WINDOWS__
#define __32__
#else
Invalid bits
#endif
#else
Invalid compiler
#endif
#include "lib/common/khash.h"
#include "lib/common/value_option_types.h"
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
#define sjs_foo_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_foo sjs_foo;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_foo {
    int _refCount;
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
sjs_foo sjt_call1 = { -1 };
sjs_foo* sjt_copy1 = 0;
sjs_foo* sjt_copy2 = 0;
sjs_foo* sjt_copy3 = 0;
sjs_foo* sjt_copy4 = 0;
sjs_foo* sjt_copy5 = 0;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
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
sjs_foo sjv_stack_x1 = { -1 };
sjs_foo sjv_stack_x2 = { -1 };
sjs_foo sjv_stack_x3 = { -1 };
sjs_foo sjv_stack_y = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_foo(sjs_foo* _this);
void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from);
void sjf_foo_destroy(sjs_foo* _this);
void sjf_foo_heap(sjs_foo* _this);
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
void sjf_foo(sjs_foo* _this) {
}

void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from) {
}

void sjf_foo_destroy(sjs_foo* _this) {
}

void sjf_foo_heap(sjs_foo* _this) {
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
    sjt_copy1 = &sjv_stack_y;
    sjv_heap_x2 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_heap_x2->_refCount = 1;
    sjf_foo_copy(sjv_heap_x2, sjt_copy1);
    sjt_copy2 = sjv_local_y;
    sjv_heap_x3 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_heap_x3->_refCount = 1;
    sjf_foo_copy(sjv_heap_x3, sjt_copy2);
    sjt_copy3 = &sjv_stack_y;
    sjv_stack_x1._refCount = 1;
    sjf_foo_copy(&sjv_stack_x1, sjt_copy3);
    sjt_copy4 = sjv_heap_y;
    sjv_stack_x2._refCount = 1;
    sjf_foo_copy(&sjv_stack_x2, sjt_copy4);
    sjt_copy5 = sjv_local_y;
    sjv_stack_x3._refCount = 1;
    sjf_foo_copy(&sjv_stack_x3, sjt_copy5);
    sjv_local_x1 = sjv_heap_y;
    sjv_local_x2 = &sjv_stack_y;
    sjv_local_x3 = sjv_local_y;
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
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
    if (sjv_stack_x1._refCount == 1) { sjf_foo_destroy(&sjv_stack_x1); }
    if (sjv_stack_x2._refCount == 1) { sjf_foo_destroy(&sjv_stack_x2); }
    if (sjv_stack_x3._refCount == 1) { sjf_foo_destroy(&sjv_stack_x3); }
    if (sjv_stack_y._refCount == 1) { sjf_foo_destroy(&sjv_stack_y); }
}
