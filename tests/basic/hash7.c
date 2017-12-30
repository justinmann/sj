#include <lib/common/common.h>

const char* sjg_string1 = "hi";
const char* sjg_string2 = "hello";
const char* sjg_string3 = "good bye";
const char* sjg_string4 = "bye";
const char* sjg_string5 = "empty";

#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_array_char_typeId 21
#define sjs_string_typeId 22
#define sjs_hash_stringstring_typeId 23

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_hash_stringstring sjs_hash_stringstring;

struct td_sjs_hash_type_bool {
    int _refCount;
    void* _hash;
};

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
    sjs_hash_type_bool traceincludes;
    sjs_hash_type_bool debugincludes;
    sjs_hash_type_bool infoincludes;
    sjs_hash_type_bool warnincludes;
    sjs_hash_type_bool errorincludes;
    sjs_hash_type_bool fatalincludes;
};

struct td_sjs_array_char {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_string {
    int _refCount;
    int32_t count;
    sjs_array_char data;
    bool _isnullterminated;
};

struct td_sjs_hash_stringstring {
    int _refCount;
    void* _hash;
};

#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef string_string_hash_typedef
#define string_string_hash_typedef
KHASH_INIT_TYPEDEF(string_string_hash_type, sjs_string, sjs_string)
#endif
#ifndef string_string_hash_typedef
#define string_string_hash_typedef
KHASH_INIT_TYPEDEF(string_string_hash_type, sjs_string, sjs_string)
#endif
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call10 = { -1 };
sjs_string sjt_call11 = { -1 };
sjs_string sjt_call12 = { -1 };
sjs_string sjt_call13 = { -1 };
sjs_string sjt_call14 = { -1 };
sjs_string sjt_call15 = { -1 };
sjs_string sjt_call16 = { -1 };
sjs_string sjt_call17 = { -1 };
sjs_string sjt_call18 = { -1 };
sjs_string sjt_call19 = { -1 };
sjs_string sjt_call2 = { -1 };
sjs_string sjt_call20 = { -1 };
sjs_string sjt_call21 = { -1 };
sjs_string sjt_call22 = { -1 };
sjs_string sjt_call23 = { -1 };
sjs_string sjt_call24 = { -1 };
sjs_string sjt_call25 = { -1 };
sjs_string sjt_call26 = { -1 };
sjs_string sjt_call27 = { -1 };
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string sjt_call5 = { -1 };
sjs_string sjt_call6 = { -1 };
sjs_string sjt_call7 = { -1 };
sjs_string sjt_call8 = { -1 };
sjs_string sjt_call9 = { -1 };
sjs_string* sjt_functionParam10 = 0;
int32_t sjt_functionParam2;
sjs_string* sjt_functionParam20 = 0;
sjs_string* sjt_functionParam22 = 0;
int32_t sjt_functionParam23;
int32_t sjt_functionParam24;
sjs_string* sjt_functionParam25 = 0;
sjs_string* sjt_functionParam26 = 0;
sjs_string* sjt_functionParam27 = 0;
sjs_string* sjt_functionParam29 = 0;
sjs_string* sjt_functionParam3 = 0;
int32_t sjt_functionParam30;
int32_t sjt_functionParam31;
sjs_string* sjt_functionParam32 = 0;
sjs_string* sjt_functionParam33 = 0;
sjs_string* sjt_functionParam34 = 0;
sjs_string* sjt_functionParam36 = 0;
int32_t sjt_functionParam37;
int32_t sjt_functionParam38;
sjs_string* sjt_functionParam4 = 0;
sjs_string* sjt_functionParam5 = 0;
sjs_string* sjt_functionParam6 = 0;
sjs_string* sjt_parent15 = 0;
sjs_hash_stringstring* sjt_parent16 = 0;
sjs_hash_stringstring* sjt_parent18 = 0;
sjs_hash_stringstring* sjt_parent19 = 0;
sjs_hash_stringstring* sjt_parent2 = 0;
sjs_string* sjt_parent20 = 0;
sjs_hash_stringstring* sjt_parent21 = 0;
sjs_hash_stringstring* sjt_parent23 = 0;
sjs_hash_stringstring* sjt_parent24 = 0;
sjs_string* sjt_parent25 = 0;
sjs_hash_stringstring* sjt_parent26 = 0;
sjs_hash_stringstring* sjt_parent28 = 0;
sjs_hash_stringstring* sjt_parent3 = 0;
sjs_hash_stringstring* sjt_parent4 = 0;
sjs_hash_stringstring sjv_a = { -1 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
sjs_hash_type_bool sjv_log_excludeall = { -1 };
sjs_hash_type_bool sjv_log_includeall = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_stringstring(sjs_hash_stringstring* _this);
void sjf_hash_stringstring__weakptrremovekey(sjs_hash_stringstring* _parent, sjs_string* key);
void sjf_hash_stringstring__weakptrremovevalue(sjs_hash_stringstring* _parent, sjs_string* val);
void sjf_hash_stringstring_copy(sjs_hash_stringstring* _this, sjs_hash_stringstring* _from);
void sjf_hash_stringstring_destroy(sjs_hash_stringstring* _this);
void sjf_hash_stringstring_getat(sjs_hash_stringstring* _parent, sjs_string* key, sjs_string* _return);
void sjf_hash_stringstring_getat_heap(sjs_hash_stringstring* _parent, sjs_string* key, sjs_string** _return);
void sjf_hash_stringstring_getcount(sjs_hash_stringstring* _parent, int32_t* _return);
void sjf_hash_stringstring_heap(sjs_hash_stringstring* _this);
void sjf_hash_stringstring_remove(sjs_hash_stringstring* _parent, sjs_string* key);
void sjf_hash_stringstring_resize(sjs_hash_stringstring* _parent, int32_t newbuckets);
void sjf_hash_stringstring_setat(sjs_hash_stringstring* _parent, sjs_string* key, sjs_string* val);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return);
void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_hash(sjs_string* _parent, uint32_t* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return);
void sjf_string_nullterminate(sjs_string* _parent);
void sjf_type_hash(int32_t val, uint32_t* _return);
void sjf_type_isequal(int32_t l, int32_t r, bool* _return);
void main_destroy(void);

#ifndef type_bool_hash_function
#define type_bool_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#else
KHASH_INIT_FUNCTION(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#endif
#endif
#ifndef type_bool_hash_function
#define type_bool_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#else
KHASH_INIT_FUNCTION(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#endif
#endif
#include <lib/common/common.c>
#ifndef string_string_hash_function
#define string_string_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_string_hash_type, sjs_string, sjs_string, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_string_hash_type, sjs_string, sjs_string, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
#ifndef string_string_hash_function
#define string_string_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_string_hash_type, sjs_string, sjs_string, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_string_hash_type, sjs_string, sjs_string, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
void sjf_array_char(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !true && !false
            char* p = (char*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
        }
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    char* p = (char*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        #if true
        memcpy(newp, p, sizeof(char) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
        #endif
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->isglobal = false;
    _return->count = _parent->count;
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        #if true
        memcpy(newp, p, sizeof(char) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
        #endif
    }
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->isglobal = false;
    (*_return)->count = _parent->count;
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    char* p = (char*)_parent->data;
    p[index] = item;
;
    _parent->count = index + 1;
}

void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
    if (_parent->count != test->count) {
        *_return = false;
    }
    bool result = memcmp(_parent->data, test->data, _parent->count * sizeof(char)) == 0;
    (*_return) = result;
return;;      
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent7 = 0;

    sjt_parent7 = data;
    sjf_string_nullterminate(sjt_parent7);
    debugout("%s\n", (char*)data->data.data);
}

void sjf_hash_stringstring(sjs_hash_stringstring* _this) {
    _this->_hash = kh_init(string_string_hash_type);
}

void sjf_hash_stringstring__weakptrremovekey(sjs_hash_stringstring* _parent, sjs_string* key) {
    #if false
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(string_string_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(string_string_hash_type, p, k);
    }
    #endif
}

void sjf_hash_stringstring__weakptrremovevalue(sjs_hash_stringstring* _parent, sjs_string* val) {
    #if false
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            sjs_string t = kh_value(p, k);
            if (t == val) {
                kh_del(string_string_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_stringstring_copy(sjs_hash_stringstring* _this, sjs_hash_stringstring* _from) {
    _this->_hash = _from->_hash;
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_this->_hash;
    p->refcount++;
}

void sjf_hash_stringstring_destroy(sjs_hash_stringstring* _this) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_this->_hash;
    p->refcount--;
    if (p->refcount == 0) {
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_stringstring__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_stringstring__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k), cb);
                #else
                ;
                #endif
            }
        }
        kh_destroy(string_string_hash_type, _this->_hash);
    }
}

void sjf_hash_stringstring_getat(sjs_hash_stringstring* _parent, sjs_string* key, sjs_string* _return) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_string_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_string_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        _return->_refCount = -1;
return;
    }
    sjs_string* copyoption13 = (kh_val(p, k)._refCount != -1 ? &kh_val(p, k) : 0);
if (copyoption13 != 0) {
    _return->_refCount = 1;
    sjf_string_copy(_return, copyoption13);
} else {
    _return->_refCount = -1;
}
return;;
}

void sjf_hash_stringstring_getat_heap(sjs_hash_stringstring* _parent, sjs_string* key, sjs_string** _return) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_string_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_string_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return) = 0;
if ((*_return) != 0) {
    (*_return)->_refCount++;
}
return;
    }
    sjs_string* copyoption14 = (kh_val(p, k)._refCount != -1 ? &kh_val(p, k) : 0);
if (copyoption14 != 0) {
    (*_return) = 0;
    sjf_string_copy((*_return), copyoption14);
} else {
    (*_return) = 0;
}
return;;
}

void sjf_hash_stringstring_getcount(sjs_hash_stringstring* _parent, int32_t* _return) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    int x = kh_size(p);
    (*_return) = x;
return;;
}

void sjf_hash_stringstring_heap(sjs_hash_stringstring* _this) {
    _this->_hash = kh_init(string_string_hash_type);
}

void sjf_hash_stringstring_remove(sjs_hash_stringstring* _parent, sjs_string* key) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_string_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_string_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    ;
    kh_del(string_string_hash_type, p, k);
}
}

void sjf_hash_stringstring_resize(sjs_hash_stringstring* _parent, int32_t newbuckets) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    kh_resize(string_string_hash_type, p, newbuckets);
}

void sjf_hash_stringstring_setat(sjs_hash_stringstring* _parent, sjs_string* key, sjs_string* val) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_string_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_string_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    ;
}
int ret;
#if true
k = kh_put(string_string_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(string_string_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(string_string_hash_type, p, k);
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_stringstring__weakptrremovekey };
weakptr_cb_add(key, cb);
#else
sjs_string t;
t._refCount = 1;
sjf_string_copy(&t, key);
;
#endif
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_stringstring__weakptrremovevalue };
weakptr_cb_add(val, cb);
kh_val(p, k) = val;
#else
kh_val(p, k)._refCount = 1;
sjf_string_copy(&kh_val(p, k), val);
;
#endif
}

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
    #if false
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(type_bool_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(type_bool_hash_type, p, k);
    }
    #endif
}

void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val) {
    #if false
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            bool t = kh_value(p, k);
            if (t == val) {
                kh_del(type_bool_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from) {
    _this->_hash = _from->_hash;
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
    p->refcount--;
    if (p->refcount == 0) {
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k), cb);
                #else
                ;
                #endif
            }
        }
        kh_destroy(type_bool_hash_type, _this->_hash);
    }
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    *refcount = 1;
    char *tmp = (char*)sjv_data + 128;
    char *tp = (char*)sjv_data + 128;
    int i;
    unsigned v;
    int sign = (base == 10 && val < 0);    
    if (sign)
    v = -val;
    else
    v = (unsigned)val;
    while (v || tp == tmp)
    {
        i = v % base;
        v /= base; // v/=base uses less CPU clocks than v=v/base does
        if (i < 10)
        *tp++ = i + '0';
        else
        *tp++ = i + 'a' - 10;
    }
    int len = tp - tmp;
    char* sp = (char*)sjv_data;
    if (sign) 
    {
        *sp++ = '-';
        len++;
    }
    while (tp > tmp)
    *sp++ = *--tp;
    sjv_count = len;
    _return->_refCount = 1;
    _return->count = sjv_count;
    _return->data._refCount = 1;
    _return->data.datasize = 256;
    _return->data.data = sjv_data;
    _return->data.isglobal = false;
    _return->data.count = sjv_count;
    sjf_array_char(&_return->data);
    _return->_isnullterminated = false;
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    *refcount = 1;
    char *tmp = (char*)sjv_data + 128;
    char *tp = (char*)sjv_data + 128;
    int i;
    unsigned v;
    int sign = (base == 10 && val < 0);    
    if (sign)
    v = -val;
    else
    v = (unsigned)val;
    while (v || tp == tmp)
    {
        i = v % base;
        v /= base; // v/=base uses less CPU clocks than v=v/base does
        if (i < 10)
        *tp++ = i + '0';
        else
        *tp++ = i + 'a' - 10;
    }
    int len = tp - tmp;
    char* sp = (char*)sjv_data;
    if (sign) 
    {
        *sp++ = '-';
        len++;
    }
    while (tp > tmp)
    *sp++ = *--tp;
    sjv_count = len;
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = sjv_count;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 256;
    (*_return)->data.data = sjv_data;
    (*_return)->data.isglobal = false;
    (*_return)->data.count = sjv_count;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
    sjf_string_heap((*_return));
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
    _this->minlevel = _from->minlevel;
    sjs_hash_type_bool* copyoption1 = (_from->traceincludes._refCount != -1 ? &_from->traceincludes : 0);
    if (copyoption1 != 0) {
        _this->traceincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->traceincludes, copyoption1);
    } else {
        _this->traceincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption2 = (_from->debugincludes._refCount != -1 ? &_from->debugincludes : 0);
    if (copyoption2 != 0) {
        _this->debugincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->debugincludes, copyoption2);
    } else {
        _this->debugincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption3 = (_from->infoincludes._refCount != -1 ? &_from->infoincludes : 0);
    if (copyoption3 != 0) {
        _this->infoincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->infoincludes, copyoption3);
    } else {
        _this->infoincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption4 = (_from->warnincludes._refCount != -1 ? &_from->warnincludes : 0);
    if (copyoption4 != 0) {
        _this->warnincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->warnincludes, copyoption4);
    } else {
        _this->warnincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption5 = (_from->errorincludes._refCount != -1 ? &_from->errorincludes : 0);
    if (copyoption5 != 0) {
        _this->errorincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->errorincludes, copyoption5);
    } else {
        _this->errorincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption6 = (_from->fatalincludes._refCount != -1 ? &_from->fatalincludes : 0);
    if (copyoption6 != 0) {
        _this->fatalincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->fatalincludes, copyoption6);
    } else {
        _this->fatalincludes._refCount = -1;
    }
}

void sjf_log_destroy(sjs_log* _this) {
    if (_this->traceincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->traceincludes); }
;
    if (_this->debugincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->debugincludes); }
;
    if (_this->infoincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->infoincludes); }
;
    if (_this->warnincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->warnincludes); }
;
    if (_this->errorincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->errorincludes); }
;
    if (_this->fatalincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->fatalincludes); }
;
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
        _return->count = _parent->count;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, &_parent->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam11;
            sjs_array_char* sjt_parent8 = 0;

            sjt_parent8 = &_parent->data;
            sjt_functionParam11 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent8, sjt_functionParam11, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart1 = 0;
        sjt_forEnd1 = item->count;
        i = sjt_forStart1;
        while (i < sjt_forEnd1) {
            int32_t sjt_functionParam12;
            char sjt_functionParam13;
            int32_t sjt_functionParam15;
            sjs_string* sjt_parent11 = 0;
            sjs_array_char* sjt_parent9 = 0;

            sjt_parent9 = &sjv_newdata;
            sjt_functionParam12 = sjv_newcount;
            sjt_parent11 = item;
            sjt_functionParam15 = i;
            sjf_string_getat(sjt_parent11, sjt_functionParam15, &sjt_functionParam13);
            sjf_array_char_initat(sjt_parent9, sjt_functionParam12, sjt_functionParam13);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        _return->_refCount = 1;
        _return->count = sjv_newcount;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, &sjv_newdata);
        _return->_isnullterminated = false;
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = _parent->count;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, &_parent->data);
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam16;
            sjs_array_char* sjt_parent12 = 0;

            sjt_parent12 = &_parent->data;
            sjt_functionParam16 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent12, sjt_functionParam16, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart2 = 0;
        sjt_forEnd2 = item->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam17;
            char sjt_functionParam18;
            int32_t sjt_functionParam19;
            sjs_array_char* sjt_parent13 = 0;
            sjs_string* sjt_parent14 = 0;

            sjt_parent13 = &sjv_newdata;
            sjt_functionParam17 = sjv_newcount;
            sjt_parent14 = item;
            sjt_functionParam19 = i;
            sjf_string_getat(sjt_parent14, sjt_functionParam19, &sjt_functionParam18);
            sjf_array_char_initat(sjt_parent13, sjt_functionParam17, sjt_functionParam18);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, &sjv_newdata);
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam14;
    sjs_array_char* sjt_parent10 = 0;

    sjt_parent10 = &_parent->data;
    sjt_functionParam14 = index;
    sjf_array_char_getat(sjt_parent10, sjt_functionParam14, _return);
}

void sjf_string_hash(sjs_string* _parent, uint32_t* _return) {
    (*_return) = kh_str_hash_func((char*)_parent->data.data);
return;;
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_array_char* sjt_functionParam1 = 0;
    sjs_array_char* sjt_parent1 = 0;

    sjt_parent1 = &_parent->data;
    sjt_functionParam1 = &test->data;
    sjf_array_char_isequal(sjt_parent1, sjt_functionParam1, _return);
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_funcold1 = { -1 };

    result2 = !(&_parent->data)->isglobal;
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam8;
        char sjt_functionParam9;
        sjs_array_char* sjt_parent6 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam7;
            sjs_array_char* sjt_parent5 = 0;

            sjt_funcold1._refCount = 1;
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
            sjt_parent5 = &_parent->data;
            sjt_functionParam7 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent5, sjt_functionParam7, &sjt_funcold1);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
        }

        sjt_parent6 = &_parent->data;
        sjt_functionParam8 = _parent->count;
        sjt_functionParam9 = '\0';
        sjf_array_char_initat(sjt_parent6, sjt_functionParam8, sjt_functionParam9);
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

    sjt_cast1 = val;
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
    (*_return) = l == r;
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
    result1 = -1;
    sjv_i32_maxvalue = result1 - 2147483647;
    sjv_i32_minvalue = 2147483647;
    sjv_log_includeall._refCount = -1;
    sjv_log_excludeall._refCount = 1;
    sjv_log_excludeall._refCount = 1;
    sjf_hash_type_bool(&sjv_log_excludeall);
    sjv_log._refCount = 1;
    sjv_log.minlevel = sjv_loglevel_warn;
    sjs_hash_type_bool* copyoption7 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption7 != 0) {
        sjv_log.traceincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.traceincludes, copyoption7);
    } else {
        sjv_log.traceincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption8 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption8 != 0) {
        sjv_log.debugincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.debugincludes, copyoption8);
    } else {
        sjv_log.debugincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption9 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption9 != 0) {
        sjv_log.infoincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.infoincludes, copyoption9);
    } else {
        sjv_log.infoincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption10 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption10 != 0) {
        sjv_log.warnincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.warnincludes, copyoption10);
    } else {
        sjv_log.warnincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption11 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption11 != 0) {
        sjv_log.errorincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.errorincludes, copyoption11);
    } else {
        sjv_log.errorincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption12 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption12 != 0) {
        sjv_log.fatalincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.fatalincludes, copyoption12);
    } else {
        sjv_log.fatalincludes._refCount = -1;
    }

    sjf_log(&sjv_log);
    sjv_emptystringdata = 0;
    sjv_emptystringdata = "";
    ptr_init();
    weakptr_init();
    sjv_clocks_per_sec = 0;
    sjv_clocks_per_sec = CLOCKS_PER_SEC;
    sjv_a._refCount = 1;
    sjf_hash_stringstring(&sjv_a);
    sjs_hash_stringstring* hash1;
    hash1 = &sjv_a;
    sjt_parent2 = hash1;
    sjt_functionParam2 = 1;
    sjf_hash_stringstring_resize(sjt_parent2, sjt_functionParam2);
    sjt_parent3 = hash1;
    sjt_call1._refCount = 1;
    sjt_call1.count = 2;
    sjt_call1.data._refCount = 1;
    sjt_call1.data.datasize = 2;
    sjt_call1.data.data = (void*)sjg_string1;
    sjt_call1.data.isglobal = true;
    sjt_call1.data.count = 2;
    sjf_array_char(&sjt_call1.data);
    sjt_call1._isnullterminated = false;
    sjf_string(&sjt_call1);
    sjt_functionParam3 = &sjt_call1;
    sjt_call2._refCount = 1;
    sjt_call2.count = 5;
    sjt_call2.data._refCount = 1;
    sjt_call2.data.datasize = 5;
    sjt_call2.data.data = (void*)sjg_string2;
    sjt_call2.data.isglobal = true;
    sjt_call2.data.count = 5;
    sjf_array_char(&sjt_call2.data);
    sjt_call2._isnullterminated = false;
    sjf_string(&sjt_call2);
    sjt_functionParam4 = &sjt_call2;
    sjf_hash_stringstring_setat(sjt_parent3, sjt_functionParam3, sjt_functionParam4);
    sjt_parent4 = hash1;
    sjt_call3._refCount = 1;
    sjt_call3.count = 3;
    sjt_call3.data._refCount = 1;
    sjt_call3.data.datasize = 3;
    sjt_call3.data.data = (void*)sjg_string4;
    sjt_call3.data.isglobal = true;
    sjt_call3.data.count = 3;
    sjf_array_char(&sjt_call3.data);
    sjt_call3._isnullterminated = false;
    sjf_string(&sjt_call3);
    sjt_functionParam5 = &sjt_call3;
    sjt_call4._refCount = 1;
    sjt_call4.count = 8;
    sjt_call4.data._refCount = 1;
    sjt_call4.data.datasize = 8;
    sjt_call4.data.data = (void*)sjg_string3;
    sjt_call4.data.isglobal = true;
    sjt_call4.data.count = 8;
    sjf_array_char(&sjt_call4.data);
    sjt_call4._isnullterminated = false;
    sjf_string(&sjt_call4);
    sjt_functionParam6 = &sjt_call4;
    sjf_hash_stringstring_setat(sjt_parent4, sjt_functionParam5, sjt_functionParam6);
    sjt_parent16 = &sjv_a;
    sjt_call7._refCount = 1;
    sjt_call7.count = 2;
    sjt_call7.data._refCount = 1;
    sjt_call7.data.datasize = 2;
    sjt_call7.data.data = (void*)sjg_string1;
    sjt_call7.data.isglobal = true;
    sjt_call7.data.count = 2;
    sjf_array_char(&sjt_call7.data);
    sjt_call7._isnullterminated = false;
    sjf_string(&sjt_call7);
    sjt_functionParam20 = &sjt_call7;
    sjf_hash_stringstring_getat(sjt_parent16, sjt_functionParam20, &sjt_call6);
    if ((sjt_call6._refCount != -1 ? &sjt_call6 : 0) != 0) {
        sjs_string* sjt_functionParam21 = 0;
        sjs_hash_stringstring* sjt_parent17 = 0;

        sjt_parent17 = &sjv_a;
        sjt_call9._refCount = 1;
        sjt_call9.count = 2;
        sjt_call9.data._refCount = 1;
        sjt_call9.data.datasize = 2;
        sjt_call9.data.data = (void*)sjg_string1;
        sjt_call9.data.isglobal = true;
        sjt_call9.data.count = 2;
        sjf_array_char(&sjt_call9.data);
        sjt_call9._isnullterminated = false;
        sjf_string(&sjt_call9);
        sjt_functionParam21 = &sjt_call9;
        sjf_hash_stringstring_getat(sjt_parent17, sjt_functionParam21, &sjt_call8);
        sjt_parent15 = (sjt_call8._refCount != -1 ? &sjt_call8 : 0);
    } else {
        sjt_call10._refCount = 1;
        sjt_call10.count = 5;
        sjt_call10.data._refCount = 1;
        sjt_call10.data.datasize = 5;
        sjt_call10.data.data = (void*)sjg_string5;
        sjt_call10.data.isglobal = true;
        sjt_call10.data.count = 5;
        sjf_array_char(&sjt_call10.data);
        sjt_call10._isnullterminated = false;
        sjf_string(&sjt_call10);
        sjt_parent15 = &sjt_call10;
    }

    sjt_parent18 = &sjv_a;
    sjf_hash_stringstring_getcount(sjt_parent18, &sjt_functionParam23);
    sjt_functionParam24 = 10;
    sjf_i32_asstring(sjt_functionParam23, sjt_functionParam24, &sjt_call11);
    sjt_functionParam22 = &sjt_call11;
    sjf_string_add(sjt_parent15, sjt_functionParam22, &sjt_call5);
    sjt_functionParam10 = &sjt_call5;
    sjf_debug_writeline(sjt_functionParam10);
    sjt_parent19 = &sjv_a;
    sjt_call12._refCount = 1;
    sjt_call12.count = 3;
    sjt_call12.data._refCount = 1;
    sjt_call12.data.datasize = 3;
    sjt_call12.data.data = (void*)sjg_string4;
    sjt_call12.data.isglobal = true;
    sjt_call12.data.count = 3;
    sjf_array_char(&sjt_call12.data);
    sjt_call12._isnullterminated = false;
    sjf_string(&sjt_call12);
    sjt_functionParam25 = &sjt_call12;
    sjf_hash_stringstring_remove(sjt_parent19, sjt_functionParam25);
    sjt_parent21 = &sjv_a;
    sjt_call15._refCount = 1;
    sjt_call15.count = 2;
    sjt_call15.data._refCount = 1;
    sjt_call15.data.datasize = 2;
    sjt_call15.data.data = (void*)sjg_string1;
    sjt_call15.data.isglobal = true;
    sjt_call15.data.count = 2;
    sjf_array_char(&sjt_call15.data);
    sjt_call15._isnullterminated = false;
    sjf_string(&sjt_call15);
    sjt_functionParam27 = &sjt_call15;
    sjf_hash_stringstring_getat(sjt_parent21, sjt_functionParam27, &sjt_call14);
    if ((sjt_call14._refCount != -1 ? &sjt_call14 : 0) != 0) {
        sjs_string* sjt_functionParam28 = 0;
        sjs_hash_stringstring* sjt_parent22 = 0;

        sjt_parent22 = &sjv_a;
        sjt_call17._refCount = 1;
        sjt_call17.count = 2;
        sjt_call17.data._refCount = 1;
        sjt_call17.data.datasize = 2;
        sjt_call17.data.data = (void*)sjg_string1;
        sjt_call17.data.isglobal = true;
        sjt_call17.data.count = 2;
        sjf_array_char(&sjt_call17.data);
        sjt_call17._isnullterminated = false;
        sjf_string(&sjt_call17);
        sjt_functionParam28 = &sjt_call17;
        sjf_hash_stringstring_getat(sjt_parent22, sjt_functionParam28, &sjt_call16);
        sjt_parent20 = (sjt_call16._refCount != -1 ? &sjt_call16 : 0);
    } else {
        sjt_call18._refCount = 1;
        sjt_call18.count = 5;
        sjt_call18.data._refCount = 1;
        sjt_call18.data.datasize = 5;
        sjt_call18.data.data = (void*)sjg_string5;
        sjt_call18.data.isglobal = true;
        sjt_call18.data.count = 5;
        sjf_array_char(&sjt_call18.data);
        sjt_call18._isnullterminated = false;
        sjf_string(&sjt_call18);
        sjt_parent20 = &sjt_call18;
    }

    sjt_parent23 = &sjv_a;
    sjf_hash_stringstring_getcount(sjt_parent23, &sjt_functionParam30);
    sjt_functionParam31 = 10;
    sjf_i32_asstring(sjt_functionParam30, sjt_functionParam31, &sjt_call19);
    sjt_functionParam29 = &sjt_call19;
    sjf_string_add(sjt_parent20, sjt_functionParam29, &sjt_call13);
    sjt_functionParam26 = &sjt_call13;
    sjf_debug_writeline(sjt_functionParam26);
    sjt_parent24 = &sjv_a;
    sjt_call20._refCount = 1;
    sjt_call20.count = 2;
    sjt_call20.data._refCount = 1;
    sjt_call20.data.datasize = 2;
    sjt_call20.data.data = (void*)sjg_string1;
    sjt_call20.data.isglobal = true;
    sjt_call20.data.count = 2;
    sjf_array_char(&sjt_call20.data);
    sjt_call20._isnullterminated = false;
    sjf_string(&sjt_call20);
    sjt_functionParam32 = &sjt_call20;
    sjf_hash_stringstring_remove(sjt_parent24, sjt_functionParam32);
    sjt_parent26 = &sjv_a;
    sjt_call23._refCount = 1;
    sjt_call23.count = 2;
    sjt_call23.data._refCount = 1;
    sjt_call23.data.datasize = 2;
    sjt_call23.data.data = (void*)sjg_string1;
    sjt_call23.data.isglobal = true;
    sjt_call23.data.count = 2;
    sjf_array_char(&sjt_call23.data);
    sjt_call23._isnullterminated = false;
    sjf_string(&sjt_call23);
    sjt_functionParam34 = &sjt_call23;
    sjf_hash_stringstring_getat(sjt_parent26, sjt_functionParam34, &sjt_call22);
    if ((sjt_call22._refCount != -1 ? &sjt_call22 : 0) != 0) {
        sjs_string* sjt_functionParam35 = 0;
        sjs_hash_stringstring* sjt_parent27 = 0;

        sjt_parent27 = &sjv_a;
        sjt_call25._refCount = 1;
        sjt_call25.count = 2;
        sjt_call25.data._refCount = 1;
        sjt_call25.data.datasize = 2;
        sjt_call25.data.data = (void*)sjg_string1;
        sjt_call25.data.isglobal = true;
        sjt_call25.data.count = 2;
        sjf_array_char(&sjt_call25.data);
        sjt_call25._isnullterminated = false;
        sjf_string(&sjt_call25);
        sjt_functionParam35 = &sjt_call25;
        sjf_hash_stringstring_getat(sjt_parent27, sjt_functionParam35, &sjt_call24);
        sjt_parent25 = (sjt_call24._refCount != -1 ? &sjt_call24 : 0);
    } else {
        sjt_call26._refCount = 1;
        sjt_call26.count = 5;
        sjt_call26.data._refCount = 1;
        sjt_call26.data.datasize = 5;
        sjt_call26.data.data = (void*)sjg_string5;
        sjt_call26.data.isglobal = true;
        sjt_call26.data.count = 5;
        sjf_array_char(&sjt_call26.data);
        sjt_call26._isnullterminated = false;
        sjf_string(&sjt_call26);
        sjt_parent25 = &sjt_call26;
    }

    sjt_parent28 = &sjv_a;
    sjf_hash_stringstring_getcount(sjt_parent28, &sjt_functionParam37);
    sjt_functionParam38 = 10;
    sjf_i32_asstring(sjt_functionParam37, sjt_functionParam38, &sjt_call27);
    sjt_functionParam36 = &sjt_call27;
    sjf_string_add(sjt_parent25, sjt_functionParam36, &sjt_call21);
    sjt_functionParam33 = &sjt_call21;
    sjf_debug_writeline(sjt_functionParam33);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
;
    if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
;
    if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
;
    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
;
    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
;
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
;
    if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
;
    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
;
    if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
;
    if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
;
    if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
;
    if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
;
    if (sjt_call23._refCount == 1) { sjf_string_destroy(&sjt_call23); }
;
    if (sjt_call24._refCount == 1) { sjf_string_destroy(&sjt_call24); }
;
    if (sjt_call25._refCount == 1) { sjf_string_destroy(&sjt_call25); }
;
    if (sjt_call26._refCount == 1) { sjf_string_destroy(&sjt_call26); }
;
    if (sjt_call27._refCount == 1) { sjf_string_destroy(&sjt_call27); }
;
    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
    if (sjt_call5._refCount == 1) { sjf_string_destroy(&sjt_call5); }
;
    if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
;
    if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
;
    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
    if (sjt_call9._refCount == 1) { sjf_string_destroy(&sjt_call9); }
;
    if (sjv_a._refCount == 1) { sjf_hash_stringstring_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
}
