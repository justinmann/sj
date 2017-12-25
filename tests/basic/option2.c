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
#define sjs_class_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_class {
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
sjs_class* sjt_functionParam1 = 0;
bool sjt_ifElse1;
bool sjt_ifElse2;
bool sjt_ifElse4;
bool sjt_ifElse5;
int32_option sjt_isEmpty1;
sjs_class* sjt_isEmpty2 = 0;
sjs_class* sjt_isEmpty4 = 0;
sjs_class* sjt_isEmpty5 = 0;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_class sjt_value3 = { -1 };
sjs_class sjv_c = { -1 };
int32_t sjv_d;
sjs_class sjv_e = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
uint32_t sjv_u32_maxvalue;
int32_t void1;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_func(sjs_class* c, int32_t* _return);
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
    bool sjt_ifElse7;
    bool sjt_ifElse8;
    int32_option sjt_isEmpty7;
    sjs_class* sjt_isEmpty8 = 0;

    sjt_isEmpty8 = c;
    sjt_ifElse8 = (sjt_isEmpty8 != 0);
    if (sjt_ifElse8) {
        sjs_class* sjt_dot3 = 0;
        int32_t sjt_value4;
        int32_option value3;

        sjt_dot3 = c;
        sjt_value4 = sjt_dot3->x;
        value3.isvalid = true;
        value3.value = sjt_value4;
        sjt_isEmpty7 = value3;
    } else {
        sjt_isEmpty7 = int32_empty;
    }

    sjt_ifElse7 = sjt_isEmpty7.isvalid;
    if (sjt_ifElse7) {
        int32_option sjt_getValue2;
        bool sjt_ifElse9;
        sjs_class* sjt_isEmpty9 = 0;

        sjt_isEmpty9 = c;
        sjt_ifElse9 = (sjt_isEmpty9 != 0);
        if (sjt_ifElse9) {
            sjs_class* sjt_dot4 = 0;
            int32_t sjt_value5;
            int32_option value4;

            sjt_dot4 = c;
            sjt_value5 = sjt_dot4->x;
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
    sjv_c._refCount = 1;
    sjv_c.x = 1;
    sjf_class(&sjv_c);
    sjt_isEmpty2 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjt_ifElse2 = (sjt_isEmpty2 != 0);
    if (sjt_ifElse2) {
        sjs_class* sjt_dot1 = 0;
        int32_t sjt_value1;
        int32_option value1;

        sjt_dot1 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_value1 = sjt_dot1->x;
        value1.isvalid = true;
        value1.value = sjt_value1;
        sjt_isEmpty1 = value1;
    } else {
        sjt_isEmpty1 = int32_empty;
    }

    sjt_ifElse1 = sjt_isEmpty1.isvalid;
    if (sjt_ifElse1) {
        int32_option sjt_getValue1;
        bool sjt_ifElse3;
        sjs_class* sjt_isEmpty3 = 0;

        sjt_isEmpty3 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_ifElse3 = (sjt_isEmpty3 != 0);
        if (sjt_ifElse3) {
            sjs_class* sjt_dot2 = 0;
            int32_t sjt_value2;
            int32_option value2;

            sjt_dot2 = (sjv_c._refCount != -1 ? &sjv_c : 0);
            sjt_value2 = sjt_dot2->x;
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

    sjt_isEmpty5 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjt_ifElse5 = (sjt_isEmpty5 != 0);
    if (sjt_ifElse5) {
        sjs_class* sjt_copy1 = 0;

        sjt_copy1 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_value3._refCount = 1;
        sjf_class_copy(&sjt_value3, sjt_copy1);
        sjt_isEmpty4 = (sjt_value3._refCount != -1 ? &sjt_value3 : 0);
    } else {
        sjt_isEmpty4 = 0;
    }

    sjt_ifElse4 = (sjt_isEmpty4 != 0);
    if (sjt_ifElse4) {
        bool sjt_ifElse6;
        sjs_class* sjt_isEmpty6 = 0;

        sjt_isEmpty6 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_ifElse6 = (sjt_isEmpty6 != 0);
        if (sjt_ifElse6) {
            sjs_class* sjt_copy2 = 0;

            sjt_copy2 = (sjv_c._refCount != -1 ? &sjv_c : 0);
            sjv_e._refCount = 1;
            sjf_class_copy(&sjv_e, sjt_copy2);
        } else {
            sjv_e._refCount = -1;
        }
    } else {
        sjv_e._refCount = 1;
        sjv_e.x = 2;
        sjf_class(&sjv_e);
    }

    sjt_functionParam1 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjf_func(sjt_functionParam1, &void1);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_value3._refCount == 1) { sjf_class_destroy(&sjt_value3); }
    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
    if (sjv_e._refCount == 1) { sjf_class_destroy(&sjv_e); }
}
