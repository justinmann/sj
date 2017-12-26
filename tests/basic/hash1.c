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
const char* sjg_string1 = "not found";

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
#define sjs_hash_i32i32_typeId 4
#define sjs_array_char_typeId 5
#define sjs_string_typeId 6

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_hash_i32i32 sjs_hash_i32i32;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_hash_i32i32 {
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
#ifndef i32_i32_hash_typedef
#define i32_i32_hash_typedef
KHASH_INIT_TYPEDEF(i32_i32_hash_type, int32_t, int32_t)
#endif
#ifndef i32_i32_hash_typedef
#define i32_i32_hash_typedef
KHASH_INIT_TYPEDEF(i32_i32_hash_type, int32_t, int32_t)
#endif
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_string sjt_call1 = { -1 };
int32_t sjt_functionParam1;
int32_t sjt_functionParam2;
int32_t sjt_functionParam3;
sjs_string* sjt_functionParam5 = 0;
bool sjt_ifElse1;
bool sjt_ifElse2;
int32_option sjt_isEmpty1;
sjs_string* sjt_isEmpty2 = 0;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_hash_i32i32* sjt_parent1 = 0;
sjs_hash_i32i32* sjt_parent2 = 0;
sjs_hash_i32i32 sjv_a = { -1 };
int32_option sjv_b;
sjs_string sjv_c = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_i32i32(sjs_hash_i32i32* _this);
void sjf_hash_i32i32__weakptrremovekey(sjs_hash_i32i32* _parent, int32_t key);
void sjf_hash_i32i32__weakptrremovevalue(sjs_hash_i32i32* _parent, int32_t val);
void sjf_hash_i32i32_copy(sjs_hash_i32i32* _this, sjs_hash_i32i32* _from);
void sjf_hash_i32i32_destroy(sjs_hash_i32i32* _this);
void sjf_hash_i32i32_getat(sjs_hash_i32i32* _parent, int32_t key, int32_option* _return);
void sjf_hash_i32i32_heap(sjs_hash_i32i32* _this);
void sjf_hash_i32i32_setat(sjs_hash_i32i32* _parent, int32_t key, int32_t val);
void sjf_i32_asstring(int32_t val, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, sjs_string** _return);
void sjf_i32_hash(int32_t val, uint32_t* _return);
void sjf_i32_isequal(int32_t l, int32_t r, bool* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string* _this);
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
#ifndef i32_i32_hash_function
#define i32_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(i32_i32_hash_type, int32_t, int32_t, 1, sjf_i32_hash, sjf_i32_isequal)
#else
KHASH_INIT_FUNCTION(i32_i32_hash_type, int32_t, int32_t, 1, sjf_i32_hash, sjf_i32_isequal)
#endif
#endif
#ifndef i32_i32_hash_function
#define i32_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(i32_i32_hash_type, int32_t, int32_t, 1, sjf_i32_hash, sjf_i32_isequal)
#else
KHASH_INIT_FUNCTION(i32_i32_hash_type, int32_t, int32_t, 1, sjf_i32_hash, sjf_i32_isequal)
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

void sjf_debug_writeline(sjs_string* data) {
    debugout("%s\n", (char*)data->data.data);
}

void sjf_hash_i32i32(sjs_hash_i32i32* _this) {
    _this->_hash = kh_init(i32_i32_hash_type);
}

void sjf_hash_i32i32__weakptrremovekey(sjs_hash_i32i32* _parent, int32_t key) {
    #if false
    khash_t(i32_i32_hash_type)* p = (khash_t(i32_i32_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(i32_i32_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(i32_i32_hash_type, p, k);
    }
    #endif
}

void sjf_hash_i32i32__weakptrremovevalue(sjs_hash_i32i32* _parent, int32_t val) {
    #if false
    khash_t(i32_i32_hash_type)* p = (khash_t(i32_i32_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            int32_t t = kh_value(p, k);
            if ((t == val)) {
                kh_del(i32_i32_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_i32i32_copy(sjs_hash_i32i32* _this, sjs_hash_i32i32* _from) {
    _this->_hash = _from->_hash;
    ptr_retain(_this->_hash);
}

void sjf_hash_i32i32_destroy(sjs_hash_i32i32* _this) {
    if (ptr_release(_this->_hash)) {
        khash_t(i32_i32_hash_type)* p = (khash_t(i32_i32_hash_type)*)_this->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_i32i32__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_i32i32__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k), cb);
                #else
                ;
                #endif
            }
        }
        kh_destroy(i32_i32_hash_type, _this->_hash);
    }
}

void sjf_hash_i32i32_getat(sjs_hash_i32i32* _parent, int32_t key, int32_option* _return) {
    khash_t(i32_i32_hash_type)* p = (khash_t(i32_i32_hash_type)*)_parent->_hash;
    #if false
    khiter_t k = kh_get(i32_i32_hash_type, p, *key);
    #else
    khiter_t k = kh_get(i32_i32_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return) = int32_empty;
return;
    }
    _return->isvalid = true;
_return->value = kh_val(p, k);
return;;
}

void sjf_hash_i32i32_heap(sjs_hash_i32i32* _this) {
    _this->_hash = kh_init(i32_i32_hash_type);
}

void sjf_hash_i32i32_setat(sjs_hash_i32i32* _parent, int32_t key, int32_t val) {
    khash_t(i32_i32_hash_type)* p = (khash_t(i32_i32_hash_type)*)_parent->_hash;
    #if false
    khiter_t k = kh_get(i32_i32_hash_type, p, *key);
    #else
    khiter_t k = kh_get(i32_i32_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    ;
}
int ret;
#if false
k = kh_put(i32_i32_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(i32_i32_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(i32_i32_hash_type, p, k);
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_i32i32__weakptrremovekey };
weakptr_cb_add(key, cb);
#else
int32_t t;
t = key;
;
#endif
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_i32i32__weakptrremovevalue };
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

void sjf_i32_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

    sjt_cast1 = val;
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_i32_isequal(int32_t l, int32_t r, bool* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;

    sjt_compare1 = l;
    sjt_compare2 = r;
    (*_return) = sjt_compare1 == sjt_compare2;
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

void sjf_string(sjs_string* _this) {
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_heap(sjs_string* _this) {
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
    sjv_a._refCount = 1;
    sjf_hash_i32i32(&sjv_a);
    sjt_parent1 = &sjv_a;
    sjt_functionParam1 = 1;
    sjt_functionParam2 = 2;
    sjf_hash_i32i32_setat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent2 = &sjv_a;
    sjt_functionParam3 = 1;
    sjf_hash_i32i32_getat(sjt_parent2, sjt_functionParam3, &sjv_b);
    sjt_isEmpty1 = sjv_b;
    sjt_ifElse1 = sjt_isEmpty1.isvalid;
    if (sjt_ifElse1) {
        int32_t sjt_functionParam4;
        int32_option sjt_getValue1;

        sjt_getValue1 = sjv_b;
        sjt_functionParam4 = sjt_getValue1.value;
        sjf_i32_asstring(sjt_functionParam4, &sjv_c);
    } else {
        sjv_c._refCount = -1;
    }

    sjt_isEmpty2 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjt_ifElse2 = (sjt_isEmpty2 != 0);
    if (sjt_ifElse2) {
        sjt_functionParam5 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    } else {
        sjt_call1._refCount = 1;
        sjt_call1.count = 9;
        sjt_call1.data._refCount = 1;
        sjt_call1.data.datasize = 10;
        sjt_call1.data.data = (void*)sjg_string1;
        sjt_call1.data._isglobal = true;
        sjt_call1.data.count = 10;
        sjf_array_char(&sjt_call1.data);
        sjf_string(&sjt_call1);
        sjt_functionParam5 = &sjt_call1;
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

    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjv_a._refCount == 1) { sjf_hash_i32i32_destroy(&sjv_a); }
;
    if (sjv_c._refCount == 1) { sjf_string_destroy(&sjv_c); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
