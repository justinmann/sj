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
#define sjs_hash_weak_class_i32_typeId 4
#define sjs_array_char_typeId 5
#define sjs_string_typeId 6

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_hash_weak_class_i32 sjs_hash_weak_class_i32;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

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

struct td_sjs_hash_weak_class_i32 {
    int _refCount;
    void* _hash;
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
#ifndef weak_class_i32_hash_typedef
#define weak_class_i32_hash_typedef
KHASH_INIT_TYPEDEF(weak_class_i32_hash_type, sjs_class*, int32_t)
#endif
#ifndef weak_class_i32_hash_typedef
#define weak_class_i32_hash_typedef
KHASH_INIT_TYPEDEF(weak_class_i32_hash_type, sjs_class*, int32_t)
#endif
int32_t result1;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call2 = { -1 };
sjs_class* sjt_functionParam1 = 0;
int32_t sjt_functionParam2;
sjs_string* sjt_functionParam3 = 0;
int32_t sjt_functionParam4;
sjs_class* sjt_functionParam5 = 0;
sjs_string* sjt_functionParam7 = 0;
int32_t sjt_functionParam8;
sjs_class* sjt_functionParam9 = 0;
bool sjt_ifElse1;
bool sjt_ifElse2;
int32_option sjt_isEmpty1;
int32_option sjt_isEmpty2;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_hash_weak_class_i32* sjt_parent1 = 0;
sjs_hash_weak_class_i32* sjt_parent2 = 0;
sjs_hash_weak_class_i32* sjt_parent4 = 0;
sjs_hash_weak_class_i32 sjv_a = { -1 };
sjs_class* sjv_c = 0;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_hash(sjs_class* _parent, uint32_t* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_class_isequal(sjs_class* _parent, sjs_class* c, bool* _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_weak_class_i32(sjs_hash_weak_class_i32* _this);
void sjf_hash_weak_class_i32__weakptrremovekey(sjs_hash_weak_class_i32* _parent, sjs_class* key);
void sjf_hash_weak_class_i32__weakptrremovevalue(sjs_hash_weak_class_i32* _parent, int32_t val);
void sjf_hash_weak_class_i32_copy(sjs_hash_weak_class_i32* _this, sjs_hash_weak_class_i32* _from);
void sjf_hash_weak_class_i32_destroy(sjs_hash_weak_class_i32* _this);
void sjf_hash_weak_class_i32_getat(sjs_hash_weak_class_i32* _parent, sjs_class* key, int32_option* _return);
void sjf_hash_weak_class_i32_heap(sjs_hash_weak_class_i32* _this);
void sjf_hash_weak_class_i32_setat(sjs_hash_weak_class_i32* _parent, sjs_class* key, int32_t val);
void sjf_i32_asstring(int32_t val, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, sjs_string** _return);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string* _this);
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
#ifndef weak_class_i32_hash_function
#define weak_class_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(weak_class_i32_hash_type, sjs_class*, int32_t, 1, sjf_class_hash, sjf_class_isequal)
#else
KHASH_INIT_FUNCTION(weak_class_i32_hash_type, sjs_class*, int32_t, 1, sjf_class_hash, sjf_class_isequal)
#endif
#endif
#ifndef weak_class_i32_hash_function
#define weak_class_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(weak_class_i32_hash_type, sjs_class*, int32_t, 1, sjf_class_hash, sjf_class_isequal)
#else
KHASH_INIT_FUNCTION(weak_class_i32_hash_type, sjs_class*, int32_t, 1, sjf_class_hash, sjf_class_isequal)
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

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_hash(sjs_class* _parent, uint32_t* _return) {
    int32_t sjt_cast1;
    sjs_class* sjt_dot1 = 0;

    sjt_dot1 = _parent;
    sjt_cast1 = (sjt_dot1)->x;
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_isequal(sjs_class* _parent, sjs_class* c, bool* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sjs_class* sjt_dot2 = 0;
    sjs_class* sjt_dot3 = 0;

    sjt_dot2 = _parent;
    sjt_compare1 = (sjt_dot2)->x;
    sjt_dot3 = c;
    sjt_compare2 = (sjt_dot3)->x;
    (*_return) = sjt_compare1 == sjt_compare2;
}

void sjf_debug_writeline(sjs_string* data) {
    #ifdef _WINDOWS
    OutputDebugStringA((char*)data->data.data);
    OutputDebugStringA("\n");
    #else
    fprintf(stderr, "%s\n", (char*)data->data.data);
    #endif
}

void sjf_hash_weak_class_i32(sjs_hash_weak_class_i32* _this) {
    _this->_hash = kh_init(weak_class_i32_hash_type);
}

void sjf_hash_weak_class_i32__weakptrremovekey(sjs_hash_weak_class_i32* _parent, sjs_class* key) {
    #if true
    khash_t(weak_class_i32_hash_type)* p = (khash_t(weak_class_i32_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(weak_class_i32_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(weak_class_i32_hash_type, p, k);
    }
    #endif
}

void sjf_hash_weak_class_i32__weakptrremovevalue(sjs_hash_weak_class_i32* _parent, int32_t val) {
    #if false
    khash_t(weak_class_i32_hash_type)* p = (khash_t(weak_class_i32_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            int32_t t = kh_value(p, k);
            if ((t == val)) {
                kh_del(weak_class_i32_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_weak_class_i32_copy(sjs_hash_weak_class_i32* _this, sjs_hash_weak_class_i32* _from) {
    _this->_hash = _from->_hash;
    ptr_retain(_this->_hash);
}

void sjf_hash_weak_class_i32_destroy(sjs_hash_weak_class_i32* _this) {
    if (ptr_release(_this->_hash)) {
        khash_t(weak_class_i32_hash_type)* p = (khash_t(weak_class_i32_hash_type)*)_this->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if true
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_weak_class_i32__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                delete_cb weakptrcb3 = { &kh_key(p, k), weakptr_clear };
if (kh_key(p, k) != 0) { weakptr_cb_remove(kh_key(p, k), weakptrcb3); }
;
                #endif
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_weak_class_i32__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k), cb);
                #else
                ;
                #endif
            }
        }
        kh_destroy(weak_class_i32_hash_type, _this->_hash);
    }
}

void sjf_hash_weak_class_i32_getat(sjs_hash_weak_class_i32* _parent, sjs_class* key, int32_option* _return) {
    khash_t(weak_class_i32_hash_type)* p = (khash_t(weak_class_i32_hash_type)*)_parent->_hash;
    #if false
    khiter_t k = kh_get(weak_class_i32_hash_type, p, *key);
    #else
    khiter_t k = kh_get(weak_class_i32_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return) = int32_empty;
return;
    }
    _return->isvalid = true;
_return->value = kh_val(p, k);
return;;
}

void sjf_hash_weak_class_i32_heap(sjs_hash_weak_class_i32* _this) {
    _this->_hash = kh_init(weak_class_i32_hash_type);
}

void sjf_hash_weak_class_i32_setat(sjs_hash_weak_class_i32* _parent, sjs_class* key, int32_t val) {
    khash_t(weak_class_i32_hash_type)* p = (khash_t(weak_class_i32_hash_type)*)_parent->_hash;
    #if false
    khiter_t k = kh_get(weak_class_i32_hash_type, p, *key);
    #else
    khiter_t k = kh_get(weak_class_i32_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    ;
}
int ret;
#if false
k = kh_put(weak_class_i32_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(weak_class_i32_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(weak_class_i32_hash_type, p, k);
#if true
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_weak_class_i32__weakptrremovekey };
weakptr_cb_add(key, cb);
#else
sjs_class* t;
t = key;
delete_cb weakptrcb4 = { &t, weakptr_clear };
if (t != 0) { weakptr_cb_add(t, weakptrcb4); }
;
#endif
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_weak_class_i32__weakptrremovevalue };
weakptr_cb_add(val, cb);
kh_val(p, k) = val;
#else
kh_val(p, k) = val;
;
#endif
}

void sjf_i32_asstring(int32_t val, sjs_string* _return) {
    int32_t sjt_math3;
    int32_t sjt_math4;
    int32_t sjt_math5;
    int32_t sjt_math6;
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = malloc(sizeof(char) * 50);
    snprintf((char*)sjv_data, 50, "%d", val);
    sjv_count = strlen((char*)sjv_data);
    _return->_refCount = 1;
    _return->count = sjv_count;
    _return->data._refCount = 1;
    sjt_math3 = sjv_count;
    sjt_math4 = 1;
    _return->data.datasize = sjt_math3 + sjt_math4;
    _return->data.data = sjv_data;
    _return->data._isglobal = false;
    sjt_math5 = sjv_count;
    sjt_math6 = 1;
    _return->data.count = sjt_math5 + sjt_math6;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, sjs_string** _return) {
    int32_t sjt_math10;
    int32_t sjt_math7;
    int32_t sjt_math8;
    int32_t sjt_math9;
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = malloc(sizeof(char) * 50);
    snprintf((char*)sjv_data, 50, "%d", val);
    sjv_count = strlen((char*)sjv_data);
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = sjv_count;
    (*_return)->data._refCount = 1;
    sjt_math7 = sjv_count;
    sjt_math8 = 1;
    (*_return)->data.datasize = sjt_math7 + sjt_math8;
    (*_return)->data.data = sjv_data;
    (*_return)->data._isglobal = false;
    sjt_math9 = sjv_count;
    sjt_math10 = 1;
    (*_return)->data.count = sjt_math9 + sjt_math10;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
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

void sjf_string_heap(sjs_string* _this) {
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
    sjf_hash_weak_class_i32(&sjv_a);
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->x = 1;
    sjf_class_heap(sjv_c);
    sjt_parent1 = &sjv_a;
    sjt_functionParam1 = sjv_c;
    delete_cb weakptrcb5 = { &sjt_functionParam1, weakptr_clear };
    if (sjt_functionParam1 != 0) { weakptr_cb_add(sjt_functionParam1, weakptrcb5); }
    sjt_functionParam2 = 1;
    sjf_hash_weak_class_i32_setat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent2 = &sjv_a;
    sjt_functionParam5 = sjv_c;
    delete_cb weakptrcb6 = { &sjt_functionParam5, weakptr_clear };
    if (sjt_functionParam5 != 0) { weakptr_cb_add(sjt_functionParam5, weakptrcb6); }
    sjf_hash_weak_class_i32_getat(sjt_parent2, sjt_functionParam5, &sjt_isEmpty1);
    sjt_ifElse1 = sjt_isEmpty1.isvalid;
    if (sjt_ifElse1) {
        sjs_class* sjt_functionParam6 = 0;
        int32_option sjt_getValue1;
        sjs_hash_weak_class_i32* sjt_parent3 = 0;

        sjt_parent3 = &sjv_a;
        sjt_functionParam6 = sjv_c;
        delete_cb weakptrcb7 = { &sjt_functionParam6, weakptr_clear };
        if (sjt_functionParam6 != 0) { weakptr_cb_add(sjt_functionParam6, weakptrcb7); }
        sjf_hash_weak_class_i32_getat(sjt_parent3, sjt_functionParam6, &sjt_getValue1);
        sjt_functionParam4 = sjt_getValue1.value;

        delete_cb weakptrcb10 = { &sjt_functionParam6, weakptr_clear };
        if (sjt_functionParam6 != 0) { weakptr_cb_remove(sjt_functionParam6, weakptrcb10); }
    } else {
        int32_t result2;
        int32_t sjt_negate2;

        sjt_negate2 = 1;
        result2 = -sjt_negate2;
        sjt_functionParam4 = result2;
    }

    sjf_i32_asstring(sjt_functionParam4, &sjt_call1);
    sjt_functionParam3 = &sjt_call1;
    sjf_debug_writeline(sjt_functionParam3);
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }

    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->x = 2;
    sjf_class_heap(sjv_c);
    sjt_parent4 = &sjv_a;
    sjt_functionParam9 = sjv_c;
    delete_cb weakptrcb8 = { &sjt_functionParam9, weakptr_clear };
    if (sjt_functionParam9 != 0) { weakptr_cb_add(sjt_functionParam9, weakptrcb8); }
    sjf_hash_weak_class_i32_getat(sjt_parent4, sjt_functionParam9, &sjt_isEmpty2);
    sjt_ifElse2 = sjt_isEmpty2.isvalid;
    if (sjt_ifElse2) {
        sjs_class* sjt_functionParam10 = 0;
        int32_option sjt_getValue2;
        sjs_hash_weak_class_i32* sjt_parent5 = 0;

        sjt_parent5 = &sjv_a;
        sjt_functionParam10 = sjv_c;
        delete_cb weakptrcb9 = { &sjt_functionParam10, weakptr_clear };
        if (sjt_functionParam10 != 0) { weakptr_cb_add(sjt_functionParam10, weakptrcb9); }
        sjf_hash_weak_class_i32_getat(sjt_parent5, sjt_functionParam10, &sjt_getValue2);
        sjt_functionParam8 = sjt_getValue2.value;

        delete_cb weakptrcb11 = { &sjt_functionParam10, weakptr_clear };
        if (sjt_functionParam10 != 0) { weakptr_cb_remove(sjt_functionParam10, weakptrcb11); }
    } else {
        int32_t result3;
        int32_t sjt_negate3;

        sjt_negate3 = 1;
        result3 = -sjt_negate3;
        sjt_functionParam8 = result3;
    }

    sjf_i32_asstring(sjt_functionParam8, &sjt_call2);
    sjt_functionParam7 = &sjt_call2;
    sjf_debug_writeline(sjt_functionParam7);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    delete_cb weakptrcb12 = { &sjt_functionParam1, weakptr_clear };
    if (sjt_functionParam1 != 0) { weakptr_cb_remove(sjt_functionParam1, weakptrcb12); }
    delete_cb weakptrcb13 = { &sjt_functionParam5, weakptr_clear };
    if (sjt_functionParam5 != 0) { weakptr_cb_remove(sjt_functionParam5, weakptrcb13); }
    delete_cb weakptrcb14 = { &sjt_functionParam9, weakptr_clear };
    if (sjt_functionParam9 != 0) { weakptr_cb_remove(sjt_functionParam9, weakptrcb14); }
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
    if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
    if (sjv_a._refCount == 1) { sjf_hash_weak_class_i32_destroy(&sjv_a); }
}
