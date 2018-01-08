#include <lib/sj-lib-common/common.h>

struct {
    int refcount;
    int size;
    int count;
    char data[1];
} g_empty = { 1, 1, 0, "" };
#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_array_char_typeId 23
#define sjs_string_typeId 21
#define sjs_class_typeId 26
#define sjs_hash_i32_weak_class_typeId 27

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_hash_i32_weak_class sjs_hash_i32_weak_class;

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
    void* v;
};

struct td_sjs_string {
    int _refCount;
    int32_t offset;
    int32_t count;
    sjs_array_char data;
    bool _isnullterminated;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

struct td_sjs_hash_i32_weak_class {
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
char* string_char(sjs_string* str);
#ifndef i32_weak_class_hash_typedef
#define i32_weak_class_hash_typedef
KHASH_INIT_TYPEDEF(i32_weak_class_hash_type, int32_t, sjs_class*)
#endif
#ifndef i32_weak_class_hash_typedef
#define i32_weak_class_hash_typedef
KHASH_INIT_TYPEDEF(i32_weak_class_hash_type, int32_t, sjs_class*)
#endif
int32_t g_loglevel_debug;
int32_t g_loglevel_error;
int32_t g_loglevel_fatal;
int32_t g_loglevel_info;
int32_t g_loglevel_trace;
int32_t g_loglevel_warn;

sjs_hash_i32_weak_class g_a = { -1 };
sjs_class* g_c = 0;
int32_t g_clocks_per_sec;
float g_f32_pi;
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
uint32_t g_u32_maxvalue;
int32_t result1;
sjs_string sjt_call1 = { -1 };
sjs_class* sjt_call2 = 0;
sjs_string sjt_call6 = { -1 };
sjs_class* sjt_call7 = 0;
int32_option sjt_capture2;
int32_option sjt_capture5;
sjs_class* sjt_funcold2 = 0;
int32_t sjt_functionParam12;
sjs_string* sjt_functionParam13 = 0;
int32_t sjt_functionParam14;
int32_t sjt_functionParam15;
int32_t sjt_functionParam19;
int32_t sjt_functionParam4;
sjs_class* sjt_functionParam5 = 0;
sjs_string* sjt_functionParam6 = 0;
int32_t sjt_functionParam7;
int32_t sjt_functionParam8;
sjs_hash_i32_weak_class* sjt_parent3 = 0;
sjs_hash_i32_weak_class* sjt_parent4 = 0;
sjs_hash_i32_weak_class* sjt_parent8 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getsize(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_i32_weak_class(sjs_hash_i32_weak_class* _this);
void sjf_hash_i32_weak_class__weakptrremovekey(sjs_hash_i32_weak_class* _parent, int32_t key);
void sjf_hash_i32_weak_class__weakptrremovevalue(sjs_hash_i32_weak_class* _parent, sjs_class* val);
void sjf_hash_i32_weak_class_copy(sjs_hash_i32_weak_class* _this, sjs_hash_i32_weak_class* _from);
void sjf_hash_i32_weak_class_destroy(sjs_hash_i32_weak_class* _this);
void sjf_hash_i32_weak_class_getat(sjs_hash_i32_weak_class* _parent, int32_t key, sjs_class** _return);
void sjf_hash_i32_weak_class_heap(sjs_hash_i32_weak_class* _this);
void sjf_hash_i32_weak_class_setat(sjs_hash_i32_weak_class* _parent, int32_t key, sjs_class* val);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return);
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
char* string_char(sjs_string* str) {
    sjf_string_nullterminate(str);
    return ((sjs_array*)str->data.v)->data;
}
#include <lib/sj-lib-common/common.cpp>
#ifndef i32_weak_class_hash_function
#define i32_weak_class_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(i32_weak_class_hash_type, int32_t, sjs_class*, 1, sjf_i32_hash, sjf_i32_isequal)
#else
KHASH_INIT_FUNCTION(i32_weak_class_hash_type, int32_t, sjs_class*, 1, sjf_i32_hash, sjf_i32_isequal)
#endif
#endif
#ifndef i32_weak_class_hash_function
#define i32_weak_class_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(i32_weak_class_hash_type, int32_t, sjs_class*, 1, sjf_i32_hash, sjf_i32_isequal)
#else
KHASH_INIT_FUNCTION(i32_weak_class_hash_type, int32_t, sjs_class*, 1, sjf_i32_hash, sjf_i32_isequal)
#endif
#endif
void sjf_array_char(sjs_array_char* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return) {
    void* newv;

#line 170 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 172
    sjs_array* arr = (sjs_array*)_parent->v;
#line 173
    if (offset + count > arr->count) {
#line 174
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 175
    }
#line 177
    if (count > arr->count - offset) {
#line 178
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 179
    }
#line 181
    sjs_array* newArr = createarray(newsize * sizeof(char));
#line 182
    if (!newArr) {
#line 183
        halt("grow: out of memory\n");
#line 184
    }
#line 186
    newv = newArr;
#line 187
    char* p = (char*)arr->data + offset;
#line 188
    char* newp = (char*)newArr->data;
#line 190
    newArr->refcount = 1;
#line 191
    newArr->size = newsize;
#line 192
    newArr->count = count;
#line 194
    #if true
#line 195
    memcpy(newp, p, sizeof(char) * count);
#line 196
    #else
#line 197
    for (int i = 0; i < count; i++) {
#line 198
        #line 171 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 199
    }
#line 200
    #endif
#line 200
    _return->_refCount = 1;
#line 202
    _return->v = newv;
#line 202
    sjf_array_char(_return);
}

void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return) {
    void* newv;

#line 170 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 172
    sjs_array* arr = (sjs_array*)_parent->v;
#line 173
    if (offset + count > arr->count) {
#line 174
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 175
    }
#line 177
    if (count > arr->count - offset) {
#line 178
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 179
    }
#line 181
    sjs_array* newArr = createarray(newsize * sizeof(char));
#line 182
    if (!newArr) {
#line 183
        halt("grow: out of memory\n");
#line 184
    }
#line 186
    newv = newArr;
#line 187
    char* p = (char*)arr->data + offset;
#line 188
    char* newp = (char*)newArr->data;
#line 190
    newArr->refcount = 1;
#line 191
    newArr->size = newsize;
#line 192
    newArr->count = count;
#line 194
    #if true
#line 195
    memcpy(newp, p, sizeof(char) * count);
#line 196
    #else
#line 197
    for (int i = 0; i < count; i++) {
#line 198
        #line 171 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 199
    }
#line 200
    #endif
#line 200
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
#line 200
    (*_return)->_refCount = 1;
#line 202
    (*_return)->v = newv;
#line 202
    sjf_array_char_heap((*_return));
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 365
    sjs_array* arr = (sjs_array*)_this->v;
#line 366
    arr->refcount++;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 370 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 371
    arr->refcount--;
#line 372
    if (arr->refcount == 0) {
#line 373
        #if !true && !false
#line 374
        char* p = (char*)arr->data;
#line 375
        for (int i = 0; i < arr->count; i++) {
#line 376
            ;
#line 377
        }
#line 378
        #endif
#line 379
        free(arr);
#line 380
    }
}

void sjf_array_char_getsize(sjs_array_char* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 2 "hash5.sj"
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
#line 10 "lib/sj-lib-common/debug.sj"
    debugout("%s\n", string_char(data));
}

void sjf_hash_i32_weak_class(sjs_hash_i32_weak_class* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(i32_weak_class_hash_type);
}

void sjf_hash_i32_weak_class__weakptrremovekey(sjs_hash_i32_weak_class* _parent, int32_t key) {
#line 180 "lib/sj-lib-common/hash.sj"
    #if false
#line 181
    khash_t(i32_weak_class_hash_type)* p = (khash_t(i32_weak_class_hash_type)*)_parent->_hash;    
#line 182
    khiter_t k = kh_get(i32_weak_class_hash_type, p, key);
#line 183
    if (k != kh_end(p)) {
#line 184
        kh_del(i32_weak_class_hash_type, p, k);
#line 185
    }
#line 186
    #endif
}

void sjf_hash_i32_weak_class__weakptrremovevalue(sjs_hash_i32_weak_class* _parent, sjs_class* val) {
#line 192 "lib/sj-lib-common/hash.sj"
    #if true
#line 193
    khash_t(i32_weak_class_hash_type)* p = (khash_t(i32_weak_class_hash_type)*)_parent->_hash;
#line 194
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 195
        if (kh_exist(p, k)) {
#line 196
            sjs_class* t = kh_value(p, k);
#line 197
            if (t == val) {
#line 198
                kh_del(i32_weak_class_hash_type, p, k);
#line 199
            }
#line 200
        }
#line 201
    }
#line 202
    #endif
}

void sjf_hash_i32_weak_class_copy(sjs_hash_i32_weak_class* _this, sjs_hash_i32_weak_class* _from) {
#line 230 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(i32_weak_class_hash_type)* p = (khash_t(i32_weak_class_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_i32_weak_class_destroy(sjs_hash_i32_weak_class* _this) {
#line 236 "lib/sj-lib-common/hash.sj"
    khash_t(i32_weak_class_hash_type)* p = (khash_t(i32_weak_class_hash_type)*)_this->_hash;
#line 237
    p->refcount--;
#line 238
    if (p->refcount == 0) {
#line 239
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 240
            if (kh_exist(p, k)) {
#line 242
                #if false
#line 243
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_i32_weak_class__weakptrremovekey };
#line 244
                weakptr_cb_remove(kh_key(p, k), cb);
#line 245
                #else
#line 246
                ;
#line 247
                #endif
#line 249
                #if true
#line 250
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_i32_weak_class__weakptrremovevalue };
#line 251
                weakptr_cb_remove(kh_value(p, k), cb);
#line 252
                #else
#line 253
                delete_cb weakptrcb6 = { &kh_value(p, k), weakptr_clear };
if (kh_value(p, k) != 0) { weakptr_cb_remove(kh_value(p, k), weakptrcb6); }
;
#line 254
                #endif
#line 255
            }
#line 256
        }
#line 257
        kh_destroy(i32_weak_class_hash_type, (khash_t(i32_weak_class_hash_type)*)_this->_hash);
#line 258
    }
}

void sjf_hash_i32_weak_class_getat(sjs_hash_i32_weak_class* _parent, int32_t key, sjs_class** _return) {
#line 23 "lib/sj-lib-common/hash.sj"
    khash_t(i32_weak_class_hash_type)* p = (khash_t(i32_weak_class_hash_type)*)_parent->_hash;
#line 25
    #if false
#line 26
    khiter_t k = kh_get(i32_weak_class_hash_type, p, *key);
#line 27
    #else
#line 28
    khiter_t k = kh_get(i32_weak_class_hash_type, p, key);
#line 29
    #endif
#line 31
    if (k == kh_end(p)) {
#line 32
        #line 22 "lib/sj-lib-common/hash.sj"
(*_return) = 0;
#line 22
delete_cb weakptrcb10 = { &(*_return), weakptr_clear };
#line 22
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb10); }
return;
#line 33
    }
#line 34
    #line 22 "lib/sj-lib-common/hash.sj"
(*_return) = kh_val(p, k);
#line 22
delete_cb weakptrcb11 = { &(*_return), weakptr_clear };
#line 22
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb11); }
return;;
}

void sjf_hash_i32_weak_class_heap(sjs_hash_i32_weak_class* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(i32_weak_class_hash_type);
}

void sjf_hash_i32_weak_class_setat(sjs_hash_i32_weak_class* _parent, int32_t key, sjs_class* val) {
#line 40 "lib/sj-lib-common/hash.sj"
    khash_t(i32_weak_class_hash_type)* p = (khash_t(i32_weak_class_hash_type)*)_parent->_hash;
#line 42
    #if false
#line 43
    khiter_t k = kh_get(i32_weak_class_hash_type, p, *key);
#line 44
    #else
#line 45
    khiter_t k = kh_get(i32_weak_class_hash_type, p, key);
#line 46
    #endif
#line 48
    if (k != kh_end(p)) {            
#line 49
    delete_cb weakptrcb7 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_remove(kh_val(p, k), weakptrcb7); }
;
#line 50
}
#line 52
int ret;
#line 53
#if false
#line 54
k = kh_put(i32_weak_class_hash_type, p, *key, &ret);
#line 55
#else
#line 56
k = kh_put(i32_weak_class_hash_type, p, key, &ret);
#line 57
#endif
#line 59
if (!ret) kh_del(i32_weak_class_hash_type, p, k);
#line 61
#if false
#line 62
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_i32_weak_class__weakptrremovekey };
#line 63
weakptr_cb_add(key, cb);
#line 64
#else
#line 65
int32_t t;
#line 66
#line 38 "lib/sj-lib-common/hash.sj"
t = key;
;
#line 67
#endif
#line 69
#if true
#line 70
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_i32_weak_class__weakptrremovevalue };
#line 71
weakptr_cb_add(val, cb);
#line 72
kh_val(p, k) = val;
#line 73
#else
#line 74
#line 38 "lib/sj-lib-common/hash.sj"
kh_val(p, k) = val;
#line 38
delete_cb weakptrcb8 = { &kh_val(p, k), weakptr_clear };
#line 38
if (kh_val(p, k) != 0) { weakptr_cb_add(kh_val(p, k), weakptrcb8); }
;
#line 75
#endif
}

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
#line 180 "lib/sj-lib-common/hash.sj"
    #if false
#line 181
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;    
#line 182
    khiter_t k = kh_get(type_bool_hash_type, p, key);
#line 183
    if (k != kh_end(p)) {
#line 184
        kh_del(type_bool_hash_type, p, k);
#line 185
    }
#line 186
    #endif
}

void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val) {
#line 192 "lib/sj-lib-common/hash.sj"
    #if false
#line 193
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
#line 194
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 195
        if (kh_exist(p, k)) {
#line 196
            bool t = kh_value(p, k);
#line 197
            if (t == val) {
#line 198
                kh_del(type_bool_hash_type, p, k);
#line 199
            }
#line 200
        }
#line 201
    }
#line 202
    #endif
}

void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from) {
#line 230 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
#line 236 "lib/sj-lib-common/hash.sj"
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 237
    p->refcount--;
#line 238
    if (p->refcount == 0) {
#line 239
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 240
            if (kh_exist(p, k)) {
#line 242
                #if false
#line 243
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovekey };
#line 244
                weakptr_cb_remove(kh_key(p, k), cb);
#line 245
                #else
#line 246
                ;
#line 247
                #endif
#line 249
                #if false
#line 250
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovevalue };
#line 251
                weakptr_cb_remove(kh_value(p, k), cb);
#line 252
                #else
#line 253
                ;
#line 254
                #endif
#line 255
            }
#line 256
        }
#line 257
        kh_destroy(type_bool_hash_type, (khash_t(type_bool_hash_type)*)_this->_hash);
#line 258
    }
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t count;
    void* vresult;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    vresult = 0;
#line 26
    sjs_array* arr = createarray(256);
#line 27
    vresult = (void*)arr;
#line 28
    char *tmp = (char*)arr->data + 128;
#line 29
    char *tp = (char*)arr->data + 128;
#line 30
    int i;
#line 31
    unsigned v;
#line 33
    int sign = (base == 10 && val < 0);    
#line 34
    if (sign)
#line 35
    v = -val;
#line 36
    else
#line 37
    v = (unsigned)val;
#line 39
    while (v || tp == tmp)
#line 40
    {
#line 41
        i = v % base;
#line 42
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 43
        if (i < 10)
#line 44
        *tp++ = i + '0';
#line 45
        else
#line 46
        *tp++ = i + 'a' - 10;
#line 47
    }
#line 49
    int len = tp - tmp;
#line 51
    char* sp = (char*)arr->data;
#line 52
    if (sign) 
#line 53
    {
#line 54
        *sp++ = '-';
#line 55
        len++;
#line 56
    }
#line 58
    while (tp > tmp)
#line 59
    *sp++ = *--tp;
#line 61
    arr->count = len;
#line 62
    count = len;
#line 62
    _return->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    _return->offset = 0;
#line 64 "lib/sj-lib-common/i32.sj"
    _return->count = count;
#line 64
    _return->data._refCount = 1;
#line 64
    _return->data.v = vresult;
#line 64
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t count;
    void* vresult;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    vresult = 0;
#line 26
    sjs_array* arr = createarray(256);
#line 27
    vresult = (void*)arr;
#line 28
    char *tmp = (char*)arr->data + 128;
#line 29
    char *tp = (char*)arr->data + 128;
#line 30
    int i;
#line 31
    unsigned v;
#line 33
    int sign = (base == 10 && val < 0);    
#line 34
    if (sign)
#line 35
    v = -val;
#line 36
    else
#line 37
    v = (unsigned)val;
#line 39
    while (v || tp == tmp)
#line 40
    {
#line 41
        i = v % base;
#line 42
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 43
        if (i < 10)
#line 44
        *tp++ = i + '0';
#line 45
        else
#line 46
        *tp++ = i + 'a' - 10;
#line 47
    }
#line 49
    int len = tp - tmp;
#line 51
    char* sp = (char*)arr->data;
#line 52
    if (sign) 
#line 53
    {
#line 54
        *sp++ = '-';
#line 55
        len++;
#line 56
    }
#line 58
    while (tp > tmp)
#line 59
    *sp++ = *--tp;
#line 61
    arr->count = len;
#line 62
    count = len;
#line 62
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 62
    (*_return)->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    (*_return)->offset = 0;
#line 64 "lib/sj-lib-common/i32.sj"
    (*_return)->count = count;
#line 64
    (*_return)->data._refCount = 1;
#line 64
    (*_return)->data.v = vresult;
#line 64
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_i32_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast2;

#line 77 "lib/sj-lib-common/i32.sj"
    sjt_cast2 = val;
#line 78
    (*_return) = (uint32_t)sjt_cast2;
}

void sjf_i32_isequal(int32_t l, int32_t r, bool* _return) {
#line 82 "lib/sj-lib-common/i32.sj"
    (*_return) = l == r;
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
#line 13 "lib/sj-lib-common/log.sj"
    _this->minlevel = _from->minlevel;
#line 13
    sjs_hash_type_bool* copyoption2 = (_from->traceincludes._refCount != -1 ? &_from->traceincludes : 0);
    if (copyoption2 != 0) {
        _this->traceincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->traceincludes, copyoption2);
    } else {
        _this->traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption3 = (_from->debugincludes._refCount != -1 ? &_from->debugincludes : 0);
    if (copyoption3 != 0) {
        _this->debugincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->debugincludes, copyoption3);
    } else {
        _this->debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption4 = (_from->infoincludes._refCount != -1 ? &_from->infoincludes : 0);
    if (copyoption4 != 0) {
        _this->infoincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->infoincludes, copyoption4);
    } else {
        _this->infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption5 = (_from->warnincludes._refCount != -1 ? &_from->warnincludes : 0);
    if (copyoption5 != 0) {
        _this->warnincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->warnincludes, copyoption5);
    } else {
        _this->warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption6 = (_from->errorincludes._refCount != -1 ? &_from->errorincludes : 0);
    if (copyoption6 != 0) {
        _this->errorincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->errorincludes, copyoption6);
    } else {
        _this->errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption7 = (_from->fatalincludes._refCount != -1 ? &_from->fatalincludes : 0);
    if (copyoption7 != 0) {
        _this->fatalincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->fatalincludes, copyoption7);
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

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 12 "lib/sj-lib-common/string.sj"
    _this->offset = _from->offset;
#line 12
    _this->count = _from->count;
#line 12
    _this->data._refCount = 1;
#line 12
    sjf_array_char_copy(&_this->data, &_from->data);
#line 12
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    sjs_array_char sjt_funcold1 = { -1 };

#line 133 "lib/sj-lib-common/string.sj"
    result2 = !_parent->_isnullterminated;
    if (result2) {
        int32_t sjt_capture1;
        sjs_array_char* sjt_parent1 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent1 = &_parent->data;
#line 35
        sjf_array_char_getsize(sjt_parent1, &sjt_capture1);
        if ((_parent->count + 1) > sjt_capture1) {
            int32_t sjt_functionParam1;
            int32_t sjt_functionParam2;
            int32_t sjt_functionParam3;
            sjs_array_char* sjt_parent2 = 0;

            sjt_funcold1._refCount = 1;
#line 169 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
#line 169
            sjt_parent2 = &_parent->data;
#line 135 "lib/sj-lib-common/string.sj"
            sjt_functionParam1 = _parent->offset;
#line 135
            sjt_functionParam2 = _parent->count;
#line 135
            sjt_functionParam3 = _parent->count + 1;
#line 135
            sjf_array_char_clone(sjt_parent2, sjt_functionParam1, sjt_functionParam2, sjt_functionParam3, &sjt_funcold1);
#line 135
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 169 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
#line 136 "lib/sj-lib-common/string.sj"
            _parent->offset = 0;
        }

#line 139 "lib/sj-lib-common/string.sj"
        ((sjs_array*)_parent->data.v)->data[_parent->count] = 0;
#line 141
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

#line 5 "lib/sj-lib-common/type.sj"
    sjt_cast1 = val;
#line 6
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
#line 10 "lib/sj-lib-common/type.sj"
    (*_return) = l == r;
}

int main(int argc, char** argv) {
#line 1 "lib/sj-lib-common/log.sj"
    g_loglevel_trace = 0;
#line 1
    g_loglevel_debug = 1;
#line 1
    g_loglevel_info = 2;
#line 1
    g_loglevel_warn = 3;
#line 1
    g_loglevel_error = 4;
#line 1
    g_loglevel_fatal = 5;
#line 1 "lib/sj-lib-common/f32.sj"
    g_f32_pi = 3.14159265358979323846f;
#line 1 "lib/sj-lib-common/i32.sj"
    g_u32_maxvalue = (uint32_t)4294967295u;
#line 3
    result1 = -1;
#line 3
    g_i32_maxvalue = result1 - 2147483647;
#line 4
    g_i32_minvalue = 2147483647;
#line 10 "lib/sj-lib-common/log.sj"
    g_log_includeall._refCount = -1;
#line 10
    sjt_value1._refCount = 1;
#line 10
    sjf_hash_type_bool(&sjt_value1);
#line 11
    sjs_hash_type_bool* copyoption1 = &sjt_value1;
    if (copyoption1 != 0) {
        g_log_excludeall._refCount = 1;
#line 11 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log_excludeall, copyoption1);
    } else {
        g_log_excludeall._refCount = -1;
    }

#line 11
    g_log._refCount = 1;
#line 13
    g_log.minlevel = g_loglevel_warn;
#line 13
    sjs_hash_type_bool* copyoption8 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption8 != 0) {
        g_log.traceincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.traceincludes, copyoption8);
    } else {
        g_log.traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption9 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption9 != 0) {
        g_log.debugincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.debugincludes, copyoption9);
    } else {
        g_log.debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption10 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption10 != 0) {
        g_log.infoincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.infoincludes, copyoption10);
    } else {
        g_log.infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption11 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption11 != 0) {
        g_log.warnincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.warnincludes, copyoption11);
    } else {
        g_log.warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption12 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption12 != 0) {
        g_log.errorincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.errorincludes, copyoption12);
    } else {
        g_log.errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption13 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption13 != 0) {
        g_log.fatalincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.fatalincludes, copyoption13);
    } else {
        g_log.fatalincludes._refCount = -1;
    }

#line 13
    sjf_log(&g_log);
#line 2 "lib/sj-lib-common/weakptr.sj"
    ptr_init();
#line 3
    weakptr_init();
#line 7 "lib/sj-lib-common/clock.sj"
    g_clocks_per_sec = 0;
#line 9
    g_clocks_per_sec = CLOCKS_PER_SEC;
#line 9
    g_a._refCount = 1;
#line 9
    sjf_hash_i32_weak_class(&g_a);
#line 9
    g_c = (sjs_class*)malloc(sizeof(sjs_class));
#line 9
    g_c->_refCount = 1;
#line 7 "hash5.sj"
    g_c->x = 1;
#line 7
    sjf_class_heap(g_c);
#line 38 "lib/sj-lib-common/hash.sj"
    sjt_parent3 = &g_a;
#line 8 "hash5.sj"
    sjt_functionParam4 = 0;
#line 8
    sjt_functionParam5 = g_c;
#line 8
    delete_cb weakptrcb9 = { &sjt_functionParam5, weakptr_clear };
#line 8
    if (sjt_functionParam5 != 0) { weakptr_cb_add(sjt_functionParam5, weakptrcb9); }
#line 8
    sjf_hash_i32_weak_class_setat(sjt_parent3, sjt_functionParam4, sjt_functionParam5);
#line 21 "lib/sj-lib-common/hash.sj"
    sjt_parent4 = &g_a;
#line 9 "hash5.sj"
    sjt_functionParam8 = 0;
#line 9
    sjf_hash_i32_weak_class_getat(sjt_parent4, sjt_functionParam8, &sjt_call2);
    if (sjt_call2 != 0) {
        sjs_class* sjt_call3 = 0;
        sjs_class* sjt_capture3 = 0;
        int32_t sjt_functionParam9;
        sjs_hash_i32_weak_class* sjt_parent5 = 0;
        int32_t sjt_value2;

#line 21 "lib/sj-lib-common/hash.sj"
        sjt_parent5 = &g_a;
#line 9 "hash5.sj"
        sjt_functionParam9 = 0;
#line 9
        sjf_hash_i32_weak_class_getat(sjt_parent5, sjt_functionParam9, &sjt_call3);
#line 9
        sjt_capture3 = sjt_call3;
#line 9
        sjt_value2 = sjt_capture3->x;
#line 9
        sjt_capture2.isvalid = true;
#line 9
        sjt_capture2.value = sjt_value2;

        delete_cb weakptrcb12 = { &sjt_call3, weakptr_clear };
        if (sjt_call3 != 0) { weakptr_cb_remove(sjt_call3, weakptrcb12); }
    } else {
#line 9 "hash5.sj"
        sjt_capture2 = int32_empty;
    }

    if (sjt_capture2.isvalid) {
        sjs_class* sjt_call4 = 0;
        int32_t sjt_functionParam10;
        int32_option sjt_getValue1;
        sjs_hash_i32_weak_class* sjt_parent6 = 0;

#line 21 "lib/sj-lib-common/hash.sj"
        sjt_parent6 = &g_a;
#line 9 "hash5.sj"
        sjt_functionParam10 = 0;
#line 9
        sjf_hash_i32_weak_class_getat(sjt_parent6, sjt_functionParam10, &sjt_call4);
        if (sjt_call4 != 0) {
            sjs_class* sjt_call5 = 0;
            sjs_class* sjt_capture4 = 0;
            int32_t sjt_functionParam11;
            sjs_hash_i32_weak_class* sjt_parent7 = 0;
            int32_t sjt_value3;

#line 21 "lib/sj-lib-common/hash.sj"
            sjt_parent7 = &g_a;
#line 9 "hash5.sj"
            sjt_functionParam11 = 0;
#line 9
            sjf_hash_i32_weak_class_getat(sjt_parent7, sjt_functionParam11, &sjt_call5);
#line 9
            sjt_capture4 = sjt_call5;
#line 9
            sjt_value3 = sjt_capture4->x;
#line 9
            sjt_getValue1.isvalid = true;
#line 9
            sjt_getValue1.value = sjt_value3;

            delete_cb weakptrcb13 = { &sjt_call5, weakptr_clear };
            if (sjt_call5 != 0) { weakptr_cb_remove(sjt_call5, weakptrcb13); }
        } else {
#line 9 "hash5.sj"
            sjt_getValue1 = int32_empty;
        }

#line 9
        sjt_functionParam7 = sjt_getValue1.value;

        delete_cb weakptrcb14 = { &sjt_call4, weakptr_clear };
        if (sjt_call4 != 0) { weakptr_cb_remove(sjt_call4, weakptrcb14); }
    } else {
        int32_t result3;

#line 9 "hash5.sj"
        result3 = -1;
#line 9
        sjt_functionParam7 = result3;
    }

#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam12 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam7, sjt_functionParam12, &sjt_call1);
#line 9 "hash5.sj"
    sjt_functionParam6 = &sjt_call1;
#line 9
    sjf_debug_writeline(sjt_functionParam6);
#line 2
    sjt_funcold2 = g_c;
#line 2
    sjt_funcold2->_refCount++;
#line 2
    sjt_funcold2 = (sjs_class*)malloc(sizeof(sjs_class));
#line 2
    sjt_funcold2->_refCount = 1;
#line 10
    sjt_funcold2->x = 2;
#line 10
    sjf_class_heap(sjt_funcold2);
#line 10
    g_c->_refCount--;
    if (g_c->_refCount <= 0) {
        weakptr_release(g_c);
        sjf_class_destroy(g_c);
        free(g_c);
    }

#line 2
    g_c = sjt_funcold2;
#line 2
    g_c->_refCount++;
#line 21 "lib/sj-lib-common/hash.sj"
    sjt_parent8 = &g_a;
#line 11 "hash5.sj"
    sjt_functionParam15 = 0;
#line 11
    sjf_hash_i32_weak_class_getat(sjt_parent8, sjt_functionParam15, &sjt_call7);
    if (sjt_call7 != 0) {
        sjs_class* sjt_call8 = 0;
        sjs_class* sjt_capture6 = 0;
        int32_t sjt_functionParam16;
        sjs_hash_i32_weak_class* sjt_parent9 = 0;
        int32_t sjt_value4;

#line 21 "lib/sj-lib-common/hash.sj"
        sjt_parent9 = &g_a;
#line 11 "hash5.sj"
        sjt_functionParam16 = 0;
#line 11
        sjf_hash_i32_weak_class_getat(sjt_parent9, sjt_functionParam16, &sjt_call8);
#line 11
        sjt_capture6 = sjt_call8;
#line 11
        sjt_value4 = sjt_capture6->x;
#line 11
        sjt_capture5.isvalid = true;
#line 11
        sjt_capture5.value = sjt_value4;

        delete_cb weakptrcb15 = { &sjt_call8, weakptr_clear };
        if (sjt_call8 != 0) { weakptr_cb_remove(sjt_call8, weakptrcb15); }
    } else {
#line 11 "hash5.sj"
        sjt_capture5 = int32_empty;
    }

    if (sjt_capture5.isvalid) {
        sjs_class* sjt_call9 = 0;
        int32_t sjt_functionParam17;
        int32_option sjt_getValue2;
        sjs_hash_i32_weak_class* sjt_parent10 = 0;

#line 21 "lib/sj-lib-common/hash.sj"
        sjt_parent10 = &g_a;
#line 11 "hash5.sj"
        sjt_functionParam17 = 0;
#line 11
        sjf_hash_i32_weak_class_getat(sjt_parent10, sjt_functionParam17, &sjt_call9);
        if (sjt_call9 != 0) {
            sjs_class* sjt_call10 = 0;
            sjs_class* sjt_capture7 = 0;
            int32_t sjt_functionParam18;
            sjs_hash_i32_weak_class* sjt_parent11 = 0;
            int32_t sjt_value5;

#line 21 "lib/sj-lib-common/hash.sj"
            sjt_parent11 = &g_a;
#line 11 "hash5.sj"
            sjt_functionParam18 = 0;
#line 11
            sjf_hash_i32_weak_class_getat(sjt_parent11, sjt_functionParam18, &sjt_call10);
#line 11
            sjt_capture7 = sjt_call10;
#line 11
            sjt_value5 = sjt_capture7->x;
#line 11
            sjt_getValue2.isvalid = true;
#line 11
            sjt_getValue2.value = sjt_value5;

            delete_cb weakptrcb16 = { &sjt_call10, weakptr_clear };
            if (sjt_call10 != 0) { weakptr_cb_remove(sjt_call10, weakptrcb16); }
        } else {
#line 11 "hash5.sj"
            sjt_getValue2 = int32_empty;
        }

#line 11
        sjt_functionParam14 = sjt_getValue2.value;

        delete_cb weakptrcb17 = { &sjt_call9, weakptr_clear };
        if (sjt_call9 != 0) { weakptr_cb_remove(sjt_call9, weakptrcb17); }
    } else {
        int32_t result4;

#line 11 "hash5.sj"
        result4 = -1;
#line 11
        sjt_functionParam14 = result4;
    }

#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam19 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam14, sjt_functionParam19, &sjt_call6);
#line 11 "hash5.sj"
    sjt_functionParam13 = &sjt_call6;
#line 11
    sjf_debug_writeline(sjt_functionParam13);
    main_destroy();
    return 0;
}

void main_destroy() {

    g_c->_refCount--;
    if (g_c->_refCount <= 0) {
        weakptr_release(g_c);
        sjf_class_destroy(g_c);
        free(g_c);
    }
    delete_cb weakptrcb18 = { &sjt_call2, weakptr_clear };
    if (sjt_call2 != 0) { weakptr_cb_remove(sjt_call2, weakptrcb18); }
    delete_cb weakptrcb19 = { &sjt_call7, weakptr_clear };
    if (sjt_call7 != 0) { weakptr_cb_remove(sjt_call7, weakptrcb19); }
    sjt_funcold2->_refCount--;
    if (sjt_funcold2->_refCount <= 0) {
        weakptr_release(sjt_funcold2);
        sjf_class_destroy(sjt_funcold2);
        free(sjt_funcold2);
    }
    delete_cb weakptrcb20 = { &sjt_functionParam5, weakptr_clear };
    if (sjt_functionParam5 != 0) { weakptr_cb_remove(sjt_functionParam5, weakptrcb20); }
    if (g_a._refCount == 1) { sjf_hash_i32_weak_class_destroy(&g_a); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
