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
#define sjs_namespace1_class_typeId 3
#define sji_namespace1_foo_vtbl_typeId 4
#define sji_namespace1_foo_typeId 5
#define sjs_namespace2_class_typeId 6
#define sji_namespace2_foo_vtbl_typeId 7
#define sji_namespace2_foo_typeId 8

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_namespace1_class sjs_namespace1_class;
typedef struct td_sji_namespace1_foo_vtbl sji_namespace1_foo_vtbl;
typedef struct td_sji_namespace1_foo sji_namespace1_foo;
typedef struct td_sjs_namespace2_class sjs_namespace2_class;
typedef struct td_sji_namespace2_foo_vtbl sji_namespace2_foo_vtbl;
typedef struct td_sji_namespace2_foo sji_namespace2_foo;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_namespace1_class {
    int _refCount;
};

struct td_sji_namespace1_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*test1)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_namespace1_foo {
    sjs_object* _parent;
    sji_namespace1_foo_vtbl* _vtbl;
};

struct td_sjs_namespace2_class {
    int _refCount;
};

struct td_sji_namespace2_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*test2)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_namespace2_foo {
    sjs_object* _parent;
    sji_namespace2_foo_vtbl* _vtbl;
};

sji_namespace1_foo_vtbl sjs_namespace1_class_foo_vtbl;
sji_namespace2_foo_vtbl sjs_namespace2_class_foo_vtbl;
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
sjs_namespace1_class sjt_call1 = { -1 };
sjs_namespace2_class sjt_call2 = { -1 };
sjs_namespace1_class* sjt_cast1 = 0;
sjs_namespace2_class* sjt_cast2 = 0;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sji_namespace1_foo sjv_a = { 0 };
sji_namespace2_foo sjv_b = { 0 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
uint32_t sjv_u32_maxvalue;

void sjf_namespace1_class(sjs_namespace1_class* _this);
void sjf_namespace1_class_as_sji_namespace1_foo(sjs_namespace1_class* _this, sji_namespace1_foo* _return);
void sjf_namespace1_class_asinterface(sjs_namespace1_class* _this, int typeId, sjs_interface* _return);
void sjf_namespace1_class_copy(sjs_namespace1_class* _this, sjs_namespace1_class* _from);
void sjf_namespace1_class_destroy(sjs_namespace1_class* _this);
void sjf_namespace1_class_heap(sjs_namespace1_class* _this);
void sjf_namespace1_class_namespace1_test1(sjs_namespace1_class* _parent, int32_t* _return);
void sjf_namespace2_class(sjs_namespace2_class* _this);
void sjf_namespace2_class_as_sji_namespace2_foo(sjs_namespace2_class* _this, sji_namespace2_foo* _return);
void sjf_namespace2_class_asinterface(sjs_namespace2_class* _this, int typeId, sjs_interface* _return);
void sjf_namespace2_class_copy(sjs_namespace2_class* _this, sjs_namespace2_class* _from);
void sjf_namespace2_class_destroy(sjs_namespace2_class* _this);
void sjf_namespace2_class_heap(sjs_namespace2_class* _this);
void sjf_namespace2_class_namespace2_test2(sjs_namespace2_class* _parent, int32_t* _return);
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
void sjf_namespace1_class(sjs_namespace1_class* _this) {
}

void sjf_namespace1_class_as_sji_namespace1_foo(sjs_namespace1_class* _this, sji_namespace1_foo* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_namespace1_class_foo_vtbl;
}

void sjf_namespace1_class_asinterface(sjs_namespace1_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_namespace1_foo_typeId:  {
            sjf_namespace1_class_as_sji_namespace1_foo(_this, (sji_namespace1_foo*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_namespace1_class_copy(sjs_namespace1_class* _this, sjs_namespace1_class* _from) {
}

void sjf_namespace1_class_destroy(sjs_namespace1_class* _this) {
}

void sjf_namespace1_class_heap(sjs_namespace1_class* _this) {
}

void sjf_namespace1_class_namespace1_test1(sjs_namespace1_class* _parent, int32_t* _return) {
    (*_return) = 5;
}

void sjf_namespace2_class(sjs_namespace2_class* _this) {
}

void sjf_namespace2_class_as_sji_namespace2_foo(sjs_namespace2_class* _this, sji_namespace2_foo* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_namespace2_class_foo_vtbl;
}

void sjf_namespace2_class_asinterface(sjs_namespace2_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_namespace2_foo_typeId:  {
            sjf_namespace2_class_as_sji_namespace2_foo(_this, (sji_namespace2_foo*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_namespace2_class_copy(sjs_namespace2_class* _this, sjs_namespace2_class* _from) {
}

void sjf_namespace2_class_destroy(sjs_namespace2_class* _this) {
}

void sjf_namespace2_class_heap(sjs_namespace2_class* _this) {
}

void sjf_namespace2_class_namespace2_test2(sjs_namespace2_class* _parent, int32_t* _return) {
    (*_return) = 5;
}

int main(int argc, char** argv) {
    sjs_namespace1_class_foo_vtbl.destroy = (void(*)(void*))sjf_namespace1_class_destroy;
    sjs_namespace1_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_namespace1_class_asinterface;
    sjs_namespace1_class_foo_vtbl.test1 = (void(*)(sjs_object*, int32_t*))sjf_namespace1_class_namespace1_test1;
    sjs_namespace2_class_foo_vtbl.destroy = (void(*)(void*))sjf_namespace2_class_destroy;
    sjs_namespace2_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_namespace2_class_asinterface;
    sjs_namespace2_class_foo_vtbl.test2 = (void(*)(sjs_object*, int32_t*))sjf_namespace2_class_namespace2_test2;
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
    sjf_namespace1_class(&sjt_call1);
    sjt_cast1 = &sjt_call1;
    sjf_namespace1_class_as_sji_namespace1_foo(sjt_cast1, &sjv_a);
    sjt_call2._refCount = 1;
    sjf_namespace2_class(&sjt_call2);
    sjt_cast2 = &sjt_call2;
    sjf_namespace2_class_as_sji_namespace2_foo(sjt_cast2, &sjv_b);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_namespace1_class_destroy(&sjt_call1); }
    if (sjt_call2._refCount == 1) { sjf_namespace2_class_destroy(&sjt_call2); }
}
