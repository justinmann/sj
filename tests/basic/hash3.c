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
const char* sjg_string1 = "foo";
const char* sjg_string2 = "bob";
const char* sjg_string3 = "bob";
const char* sjg_string4 = "foo";
const char* sjg_string5 = "not found";

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
#define sjs_array_char_typeId 3
#define sjs_string_typeId 4
#define sji_interface_vtbl_typeId 5
#define sji_interface_typeId 6
#define sjs_hash_string_heap_iface_interface_typeId 7
#define sjs_class_typeId 8

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sji_interface_vtbl sji_interface_vtbl;
typedef struct td_sji_interface sji_interface;
typedef struct td_sjs_hash_string_heap_iface_interface sjs_hash_string_heap_iface_interface;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_array_char {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_string {
    int _refCount;
    int32_t count;
    sjs_array_char data;
};

struct td_sji_interface_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*bob)(sjs_object* _parent, sjs_string* _return);
    void (*bob_heap)(sjs_object* _parent, sjs_string** _return);
};

struct td_sji_interface {
    sjs_object* _parent;
    sji_interface_vtbl* _vtbl;
};

struct td_sjs_hash_string_heap_iface_interface {
    int _refCount;
    void* _hash;
};

struct td_sjs_class {
    int _refCount;
};

sji_interface_vtbl sjs_class_interface_vtbl;
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
#ifndef string_heap_iface_interface_hash_typedef
#define string_heap_iface_interface_hash_typedef
KHASH_INIT_TYPEDEF(string_heap_iface_interface_hash_type, sjs_string, sji_interface)
#endif
#ifndef string_heap_iface_interface_hash_typedef
#define string_heap_iface_interface_hash_typedef
KHASH_INIT_TYPEDEF(string_heap_iface_interface_hash_type, sjs_string, sji_interface)
#endif
int32_t result1;
sjs_string sjt_call1 = { -1 };
sjs_class* sjt_call2 = 0;
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_class* sjt_cast1 = 0;
sjs_string* sjt_functionParam2 = 0;
sji_interface sjt_functionParam3 = { 0 };
sjs_string* sjt_functionParam4 = 0;
sjs_string* sjt_functionParam5 = 0;
bool sjt_ifElse1;
bool sjt_ifElse2;
sjs_string* sjt_isEmpty1 = 0;
sji_interface sjt_isEmpty2 = { 0 };
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_hash_string_heap_iface_interface* sjt_parent2 = 0;
sjs_hash_string_heap_iface_interface* sjt_parent3 = 0;
sjs_string sjt_value1 = { -1 };
sjs_string sjt_value2 = { -1 };
sjs_hash_string_heap_iface_interface sjv_a = { -1 };
sji_interface sjv_b = { 0 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_class(sjs_class* _this);
void sjf_class_as_sji_interface(sjs_class* _this, sji_interface* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_bob(sjs_class* _parent, sjs_string* _return);
void sjf_class_bob_heap(sjs_class* _parent, sjs_string** _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_string_heap_iface_interface(sjs_hash_string_heap_iface_interface* _this);
void sjf_hash_string_heap_iface_interface__weakptrremovekey(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key);
void sjf_hash_string_heap_iface_interface__weakptrremovevalue(sjs_hash_string_heap_iface_interface* _parent, sji_interface val);
void sjf_hash_string_heap_iface_interface_copy(sjs_hash_string_heap_iface_interface* _this, sjs_hash_string_heap_iface_interface* _from);
void sjf_hash_string_heap_iface_interface_destroy(sjs_hash_string_heap_iface_interface* _this);
void sjf_hash_string_heap_iface_interface_getat_heap(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key, sji_interface* _return);
void sjf_hash_string_heap_iface_interface_heap(sjs_hash_string_heap_iface_interface* _this);
void sjf_hash_string_heap_iface_interface_setat(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key, sji_interface val);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_hash(sjs_string* _parent, uint32_t* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return);
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
#ifndef string_heap_iface_interface_hash_function
#define string_heap_iface_interface_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_heap_iface_interface_hash_type, sjs_string, sji_interface, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_heap_iface_interface_hash_type, sjs_string, sji_interface, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
#ifndef string_heap_iface_interface_hash_function
#define string_heap_iface_interface_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_heap_iface_interface_hash_type, sjs_string, sji_interface, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_heap_iface_interface_hash_type, sjs_string, sji_interface, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
void sjf_array_char(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(char));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            char* p = (char*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_char_heap(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(char));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
    if (_parent->count != test->count) {
        *_return = false;
    }
    bool result = memcmp(_parent->data, test->data, _parent->count * sizeof(char)) == 0;
    (*_return) = result;
return;;		
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_as_sji_interface(sjs_class* _this, sji_interface* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_interface_vtbl;
}

void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_interface_typeId:  {
            sjf_class_as_sji_interface(_this, (sji_interface*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_class_bob(sjs_class* _parent, sjs_string* _return) {
    _return->_refCount = 1;
    _return->count = 3;
    _return->data._refCount = 1;
    _return->data.datasize = 4;
    _return->data.data = (void*)sjg_string2;
    _return->data._isglobal = true;
    _return->data.count = 4;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_class_bob_heap(sjs_class* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = 3;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 4;
    (*_return)->data.data = (void*)sjg_string3;
    (*_return)->data._isglobal = true;
    (*_return)->data.count = 4;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
    printf("%s\n", (char*)data->data.data);
}

void sjf_hash_string_heap_iface_interface(sjs_hash_string_heap_iface_interface* _this) {
    _this->_hash = kh_init(string_heap_iface_interface_hash_type);
}

void sjf_hash_string_heap_iface_interface__weakptrremovekey(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key) {
    #if false
    khash_t(string_heap_iface_interface_hash_type)* p = (khash_t(string_heap_iface_interface_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(string_heap_iface_interface_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(string_heap_iface_interface_hash_type, p, k);
    }
    #endif
}

void sjf_hash_string_heap_iface_interface__weakptrremovevalue(sjs_hash_string_heap_iface_interface* _parent, sji_interface val) {
    #if false
    khash_t(string_heap_iface_interface_hash_type)* p = (khash_t(string_heap_iface_interface_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            sji_interface t = kh_value(p, k);
            if ((t._parent == val._parent)) {
                kh_del(string_heap_iface_interface_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_string_heap_iface_interface_copy(sjs_hash_string_heap_iface_interface* _this, sjs_hash_string_heap_iface_interface* _from) {
    _this->_hash = _from->_hash;
    ptr_retain(_this->_hash);
}

void sjf_hash_string_heap_iface_interface_destroy(sjs_hash_string_heap_iface_interface* _this) {
    if (ptr_release(_this->_hash)) {
        khash_t(string_heap_iface_interface_hash_type)* p = (khash_t(string_heap_iface_interface_hash_type)*)_this->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_heap_iface_interface__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_heap_iface_interface__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k)._parent, cb);
                #else
                if (kh_value(p, k)._parent != 0) {
    kh_value(p, k)._parent->_refCount--;
    if (kh_value(p, k)._parent->_refCount <= 0) {
        kh_value(p, k)._vtbl->destroy(kh_value(p, k)._parent);
        free(kh_value(p, k)._parent);
    }
}
;
                #endif
            }
        }
        kh_destroy(string_heap_iface_interface_hash_type, _this->_hash);
    }
}

void sjf_hash_string_heap_iface_interface_getat_heap(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key, sji_interface* _return) {
    khash_t(string_heap_iface_interface_hash_type)* p = (khash_t(string_heap_iface_interface_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_heap_iface_interface_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_heap_iface_interface_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return)._parent = 0;
return;
    }
    (*_return) = kh_val(p, k);
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;
}

void sjf_hash_string_heap_iface_interface_heap(sjs_hash_string_heap_iface_interface* _this) {
    _this->_hash = kh_init(string_heap_iface_interface_hash_type);
}

void sjf_hash_string_heap_iface_interface_setat(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key, sji_interface val) {
    khash_t(string_heap_iface_interface_hash_type)* p = (khash_t(string_heap_iface_interface_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_heap_iface_interface_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_heap_iface_interface_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    if (kh_val(p, k)._parent != 0) {
    kh_val(p, k)._parent->_refCount--;
    if (kh_val(p, k)._parent->_refCount <= 0) {
        kh_val(p, k)._vtbl->destroy(kh_val(p, k)._parent);
        free(kh_val(p, k)._parent);
    }
}
;
}
int ret;
#if true
k = kh_put(string_heap_iface_interface_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(string_heap_iface_interface_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(string_heap_iface_interface_hash_type, p, k);
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_heap_iface_interface__weakptrremovekey };
weakptr_cb_add(key, cb);
#else
sjs_string t;
t._refCount = 1;
sjf_string_copy(&t, key);
;
#endif
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_heap_iface_interface__weakptrremovevalue };
weakptr_cb_add(val._parent, cb);
kh_val(p, k) = val;
#else
kh_val(p, k) = val;
if (kh_val(p, k)._parent != 0) {
    kh_val(p, k)._parent->_refCount++;
}
;
#endif
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
}

void sjf_string_hash(sjs_string* _parent, uint32_t* _return) {
    (*_return) = kh_str_hash_func((char*)_parent->data.data);
return;;
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_string* sjt_dot1 = 0;
    sjs_string* sjt_dot2 = 0;
    sjs_array_char* sjt_functionParam1 = 0;
    sjs_array_char* sjt_parent1 = 0;

    sjt_dot1 = _parent;
    sjt_parent1 = &(sjt_dot1)->data;
    sjt_dot2 = test;
    sjt_functionParam1 = &(sjt_dot2)->data;
    sjf_array_char_isequal(sjt_parent1, sjt_functionParam1, _return);
}

int main(int argc, char** argv) {
    sjs_class_interface_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_interface_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
    sjs_class_interface_vtbl.bob = (void(*)(sjs_object*, sjs_string*))sjf_class_bob;
    sjs_class_interface_vtbl.bob_heap = (void(*)(sjs_object*, sjs_string**))sjf_class_bob_heap;
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
    sjf_hash_string_heap_iface_interface(&sjv_a);
    sjt_parent2 = &sjv_a;
    sjt_call1._refCount = 1;
    sjt_call1.count = 3;
    sjt_call1.data._refCount = 1;
    sjt_call1.data.datasize = 4;
    sjt_call1.data.data = (void*)sjg_string1;
    sjt_call1.data._isglobal = true;
    sjt_call1.data.count = 4;
    sjf_array_char(&sjt_call1.data);
    sjf_string(&sjt_call1);
    sjt_functionParam2 = &sjt_call1;
    sjt_call2 = (sjs_class*)malloc(sizeof(sjs_class));
    sjt_call2->_refCount = 1;
    sjf_class_heap(sjt_call2);
    sjt_cast1 = sjt_call2;
    sjf_class_as_sji_interface(sjt_cast1, &sjt_functionParam3);
    if (sjt_functionParam3._parent != 0) {
        sjt_functionParam3._parent->_refCount++;
    }

    sjf_hash_string_heap_iface_interface_setat(sjt_parent2, sjt_functionParam2, sjt_functionParam3);
    sjt_parent3 = &sjv_a;
    sjt_call3._refCount = 1;
    sjt_call3.count = 3;
    sjt_call3.data._refCount = 1;
    sjt_call3.data.datasize = 4;
    sjt_call3.data.data = (void*)sjg_string4;
    sjt_call3.data._isglobal = true;
    sjt_call3.data.count = 4;
    sjf_array_char(&sjt_call3.data);
    sjf_string(&sjt_call3);
    sjt_functionParam4 = &sjt_call3;
    sjf_hash_string_heap_iface_interface_getat_heap(sjt_parent3, sjt_functionParam4, &sjv_b);
    sjt_isEmpty2 = sjv_b;
    sjt_ifElse2 = (sjt_isEmpty2._parent != 0);
    if (sjt_ifElse2) {
        sji_interface sjt_parent4 = { 0 };

        sjt_parent4 = sjv_b;
        sjt_value1._refCount = 1;
        sjt_parent4._vtbl->bob(sjt_parent4._parent, &sjt_value1);
        sjt_isEmpty1 = (sjt_value1._refCount != -1 ? &sjt_value1 : 0);
    } else {
        sjt_isEmpty1 = 0;
    }

    sjt_ifElse1 = (sjt_isEmpty1 != 0);
    if (sjt_ifElse1) {
        bool sjt_ifElse3;
        sji_interface sjt_isEmpty3 = { 0 };

        sjt_isEmpty3 = sjv_b;
        sjt_ifElse3 = (sjt_isEmpty3._parent != 0);
        if (sjt_ifElse3) {
            sji_interface sjt_parent5 = { 0 };

            sjt_parent5 = sjv_b;
            sjt_value2._refCount = 1;
            sjt_parent5._vtbl->bob(sjt_parent5._parent, &sjt_value2);
            sjt_functionParam5 = (sjt_value2._refCount != -1 ? &sjt_value2 : 0);
        } else {
            sjt_functionParam5 = 0;
        }
    } else {
        sjt_call4._refCount = 1;
        sjt_call4.count = 9;
        sjt_call4.data._refCount = 1;
        sjt_call4.data.datasize = 10;
        sjt_call4.data.data = (void*)sjg_string5;
        sjt_call4.data._isglobal = true;
        sjt_call4.data.count = 10;
        sjf_array_char(&sjt_call4.data);
        sjf_string(&sjt_call4);
        sjt_functionParam5 = &sjt_call4;
    }

    sjf_debug_writeline(sjt_functionParam5);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjt_call2->_refCount--;
    if (sjt_call2->_refCount <= 0) {
        weakptr_release(sjt_call2);
        sjf_class_destroy(sjt_call2);
        free(sjt_call2);
    }
    if (sjt_functionParam3._parent != 0) {
        sjt_functionParam3._parent->_refCount--;
        if (sjt_functionParam3._parent->_refCount <= 0) {
            sjt_functionParam3._vtbl->destroy(sjt_functionParam3._parent);
            free(sjt_functionParam3._parent);
        }
    }
    if (sjv_b._parent != 0) {
        sjv_b._parent->_refCount--;
        if (sjv_b._parent->_refCount <= 0) {
            sjv_b._vtbl->destroy(sjv_b._parent);
            free(sjv_b._parent);
        }
    }
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
    if (sjt_value1._refCount == 1) { sjf_string_destroy(&sjt_value1); }
    if (sjt_value2._refCount == 1) { sjf_string_destroy(&sjt_value2); }
    if (sjv_a._refCount == 1) { sjf_hash_string_heap_iface_interface_destroy(&sjv_a); }
}
