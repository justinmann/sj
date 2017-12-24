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
#define sji_foo_typeId 4
#define sji_foo_vtbl_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_class sjs_class;
typedef struct td_sji_foo sji_foo;
typedef struct td_sji_foo_vtbl sji_foo_vtbl;

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

struct td_sji_foo {
    sjs_object* _parent;
    sji_foo_vtbl* _vtbl;
};

struct td_sji_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*test)(sjs_object* _parent, int32_t* _return);
    void (*isequal)(sjs_object* _parent, sji_foo f, bool* _return);
};

sji_foo_vtbl sjs_class_foo_vtbl;
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
sjs_class sjt_call1 = { -1 };
sjs_class sjt_call2 = { -1 };
sjs_class* sjt_cast1 = 0;
sjs_class* sjt_cast2 = 0;
sji_foo sjt_compare3 = { 0 };
sji_foo sjt_compare4 = { 0 };
sji_foo sjt_compare5 = { 0 };
sji_foo sjt_compare6 = { 0 };
sji_foo sjt_interfaceParam1 = { 0 };
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sji_foo sjt_parent2 = { 0 };
sji_foo sjv_a = { 0 };
sji_foo sjv_b = { 0 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
bool sjv_t1;
bool sjv_t2;
bool sjv_t3;
uint32_t sjv_u32_maxvalue;

void sjf_class(sjs_class* _this);
void sjf_class_as_sji_foo(sjs_class* _this, sji_foo* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_class_isequal(sjs_class* _parent, sji_foo f, bool* _return);
void sjf_class_test(sjs_class* _parent, int32_t* _return);
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

void sjf_class_as_sji_foo(sjs_class* _this, sji_foo* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_foo_vtbl;
}

void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_foo_typeId:  {
            sjf_class_as_sji_foo(_this, (sji_foo*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_isequal(sjs_class* _parent, sji_foo f, bool* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sji_foo sjt_parent1 = { 0 };

    sjf_class_test(_parent, &sjt_compare1);
    sjt_parent1 = f;
    sjt_parent1._vtbl->test(sjt_parent1._parent, &sjt_compare2);
    (*_return) = sjt_compare1 == sjt_compare2;
}

void sjf_class_test(sjs_class* _parent, int32_t* _return) {
    sjs_class* sjt_dot1 = 0;

    sjt_dot1 = _parent;
    (*_return) = (sjt_dot1)->x;
}

int main(int argc, char** argv) {
    sjs_class_foo_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
    sjs_class_foo_vtbl.test = (void(*)(sjs_object*, int32_t*))sjf_class_test;
    sjs_class_foo_vtbl.isequal = (void(*)(sjs_object*,sji_foo, bool*))sjf_class_isequal;
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
    sjt_call1._refCount = 1;
    sjt_call1.x = 1;
    sjf_class(&sjt_call1);
    sjt_cast1 = &sjt_call1;
    sjf_class_as_sji_foo(sjt_cast1, &sjv_a);
    sjt_call2._refCount = 1;
    sjt_call2.x = 1;
    sjf_class(&sjt_call2);
    sjt_cast2 = &sjt_call2;
    sjf_class_as_sji_foo(sjt_cast2, &sjv_b);
    sjt_compare3 = sjv_a;
    sjt_compare4 = sjv_a;
    sjv_t1 = sjt_compare3._parent == sjt_compare4._parent;
    sjt_compare5 = sjv_a;
    sjt_compare6 = sjv_b;
    sjv_t2 = sjt_compare5._parent == sjt_compare6._parent;
    sjt_parent2 = sjv_a;
    sjt_interfaceParam1 = sjv_b;
    sjt_parent2._vtbl->isequal(sjt_parent2._parent, sjt_interfaceParam1, &sjv_t3);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
    if (sjt_call2._refCount == 1) { sjf_class_destroy(&sjt_call2); }
}
