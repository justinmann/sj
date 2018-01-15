#include <lib/sj-lib-common/common.h>

struct {
    int refcount;
    int size;
    int count;
    char data[1];
} sjg_string1 = { 1, 1, 0, ""};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string2 = { 1, 11, 10, " kaka pipi"};
struct {
    int refcount;
    int size;
    int count;
    char data[19];
} sjg_string3 = { 1, 19, 18, "timetocalc(msec): "};

struct {
    int refcount;
    int size;
    int count;
    char data[0];
} g_empty = { 1, 0, 0 };
#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_array_char_typeId 23
#define sjs_string_typeId 21

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

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

#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
char* string_char(sjs_string* str);
int32_t g_loglevel_debug;
int32_t g_loglevel_error;
int32_t g_loglevel_fatal;
int32_t g_loglevel_info;
int32_t g_loglevel_trace;
int32_t g_loglevel_warn;

int32_t g_clocks_per_sec;
int64_t g_end;
float g_f32_pi;
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
int64_t g_start;
sjs_string g_str = { -1 };
uint32_t g_u32_maxvalue;
int32_t i;
int32_t result1;
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string sjt_call5 = { -1 };
int64_t sjt_cast4;
int32_t sjt_cast5;
int32_t sjt_forEnd1;
int32_t sjt_forStart1;
sjs_string* sjt_functionParam40 = 0;
sjs_string* sjt_functionParam41 = 0;
double sjt_functionParam42;
sjs_string* sjt_parent27 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_gettotalcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_char_touppercase(char x, char* _return);
void sjf_clock(int64_t* _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_f64_asstring(double val, sjs_string* _return);
void sjf_f64_asstring_heap(double val, sjs_string** _return);
void sjf_f64_pow(double x, double y, double* _return);
void sjf_f64_sqrt(double v, double* _return);
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
void sjf_string_heap(sjs_string* _this);
void sjf_string_nullterminate(sjs_string* _parent);
void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return);
void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return);
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
    return ((sjs_array*)str->data.v)->data + str->offset;
}
#include <lib/sj-lib-common/common.cpp>
void sjf_array_char(sjs_array_char* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(char), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    char* p = (char*)arr->data + offset;
#line 187
    char* newp = (char*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(char) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_char(_return);
}

void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(char), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    char* p = (char*)arr->data + offset;
#line 187
    char* newp = (char*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(char) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_char_heap((*_return));
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !true && !false
#line 381
        char* p = (char*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    char* p = (char*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_char_gettotalcount(sjs_array_char* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    char* p = (char*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 64
    arr->count = index + 1;
}

void sjf_char_touppercase(char x, char* _return) {
#line 3 "lib/sj-lib-common/char.sj"
    #line 2 "lib/sj-lib-common/char.sj"
(*_return) = toupper(x);
return;
}

void sjf_clock(int64_t* _return) {
#line 3 "lib/sj-lib-common/clock.sj"
    #line 2 "lib/sj-lib-common/clock.sj"
(*_return) = clock();
return;;
}

void sjf_debug_writeline(sjs_string* data) {
#line 10 "lib/sj-lib-common/debug.sj"
    debugout("%s\n", string_char(data));
}

void sjf_f64_asstring(double val, sjs_string* _return) {
    int32_t count;
    void* v;

#line 2 "lib/sj-lib-common/f64.sj"
    v = 0;
#line 3
    count = 0;
#line 5
    sjs_array* arr = createarray(1, 256);
#line 6
    snprintf(arr->data, 256, "%lf", val);
#line 7
    arr->count = (int)strlen(arr->data);
#line 8
    count = arr->count;
#line 9
    v = arr;
#line 9
    _return->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    _return->offset = 0;
#line 11 "lib/sj-lib-common/f64.sj"
    _return->count = count;
#line 11
    _return->data._refCount = 1;
#line 11
    _return->data.v = v;
#line 11
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_f64_asstring_heap(double val, sjs_string** _return) {
    int32_t count;
    void* v;

#line 2 "lib/sj-lib-common/f64.sj"
    v = 0;
#line 3
    count = 0;
#line 5
    sjs_array* arr = createarray(1, 256);
#line 6
    snprintf(arr->data, 256, "%lf", val);
#line 7
    arr->count = (int)strlen(arr->data);
#line 8
    count = arr->count;
#line 9
    v = arr;
#line 9
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 9
    (*_return)->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    (*_return)->offset = 0;
#line 11 "lib/sj-lib-common/f64.sj"
    (*_return)->count = count;
#line 11
    (*_return)->data._refCount = 1;
#line 11
    (*_return)->data.v = v;
#line 11
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_f64_pow(double x, double y, double* _return) {
#line 32 "lib/sj-lib-common/f64.sj"
    #line 31 "lib/sj-lib-common/f64.sj"
(*_return) = pow(x, y);
return;;
}

void sjf_f64_sqrt(double v, double* _return) {
#line 38 "lib/sj-lib-common/f64.sj"
    #line 37 "lib/sj-lib-common/f64.sj"
(*_return) = sqrt(v);
return;;
}

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
#line 188 "lib/sj-lib-common/hash.sj"
    #if false
#line 189
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;    
#line 190
    khiter_t k = kh_get(type_bool_hash_type, p, key);
#line 191
    if (k != kh_end(p)) {
#line 192
        kh_del(type_bool_hash_type, p, k);
#line 193
    }
#line 194
    #endif
}

void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val) {
#line 200 "lib/sj-lib-common/hash.sj"
    #if false
#line 201
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
#line 202
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 203
        if (kh_exist(p, k)) {
#line 204
            bool t = kh_value(p, k);
#line 205
            if (t == val) {
#line 206
                kh_del(type_bool_hash_type, p, k);
#line 207
            }
#line 208
        }
#line 209
    }
#line 210
    #endif
}

void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from) {
#line 238 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 239
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 240
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
#line 244 "lib/sj-lib-common/hash.sj"
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 245
    p->refcount--;
#line 246
    if (p->refcount == 0) {
#line 247
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 248
            if (kh_exist(p, k)) {
#line 250
                #if false
#line 251
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovekey };
#line 252
                weakptr_cb_remove(kh_key(p, k), cb);
#line 253
                #else
#line 254
                ;
#line 255
                #endif
#line 257
                #if false
#line 258
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovevalue };
#line 259
                weakptr_cb_remove(kh_value(p, k), cb);
#line 260
                #else
#line 261
                ;
#line 262
                #endif
#line 263
            }
#line 264
        }
#line 265
        kh_destroy(type_bool_hash_type, (khash_t(type_bool_hash_type)*)_this->_hash);
#line 266
    }
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
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
    sjs_array* arr = createarray(1, 256);
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
    sjs_array* arr = createarray(1, 256);
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

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy(_return, _parent);
    } else {
        bool sjt_capture2;
        int32_t sjt_capture3;
        sjs_array_char* sjt_parent3 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent3 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent3, &sjt_capture3);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture3) {
            int32_t sjt_capture4;
            sjs_array_char* sjt_parent4 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent4 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent4, &sjt_capture4);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture2 = ((_parent->offset + _parent->count) == sjt_capture4);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture2 = false;
        }

        if (sjt_capture2) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd2;
            int32_t sjt_forStart2;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart2 = 0;
#line 27
            sjt_forEnd2 = item->count;
#line 27
            i = sjt_forStart2;
            while (i < sjt_forEnd2) {
                char sjt_functionParam10;
                int32_t sjt_functionParam12;
                int32_t sjt_functionParam9;
                sjs_array_char* sjt_parent5 = 0;
                sjs_string* sjt_parent7 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent5 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam9 = newcount;
#line 18
                sjt_parent7 = item;
#line 27
                sjt_functionParam12 = i;
#line 27
                sjf_string_getat(sjt_parent7, sjt_functionParam12, &sjt_functionParam10);
#line 27
                sjf_array_char_initat(sjt_parent5, sjt_functionParam9, sjt_functionParam10);
#line 29
                newcount = newcount + 1;
#line 27
                i++;
            }

#line 27
            _return->_refCount = 1;
#line 32
            _return->offset = _parent->offset;
#line 32
            _return->count = newcount;
#line 32
            _return->data._refCount = 1;
#line 32
            sjf_array_char_copy(&_return->data, &_parent->data);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd3;
            int32_t sjt_forStart3;
            int32_t sjt_functionParam13;
            int32_t sjt_functionParam14;
            int32_t sjt_functionParam15;
            sjs_array_char* sjt_parent8 = 0;
            sjs_array_char* sjt_parent9 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent8 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam13 = _parent->offset;
#line 34
            sjt_functionParam14 = _parent->count;
#line 34
            sjt_functionParam15 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent8, sjt_functionParam13, sjt_functionParam14, sjt_functionParam15, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent9 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent9, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart3 = 0;
#line 37
            sjt_forEnd3 = item->count;
#line 37
            i = sjt_forStart3;
            while (i < sjt_forEnd3) {
                int32_t sjt_functionParam16;
                char sjt_functionParam17;
                int32_t sjt_functionParam18;
                sjs_array_char* sjt_parent10 = 0;
                sjs_string* sjt_parent11 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent10 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam16 = newcount;
#line 18
                sjt_parent11 = item;
#line 37
                sjt_functionParam18 = i;
#line 37
                sjf_string_getat(sjt_parent11, sjt_functionParam18, &sjt_functionParam17);
#line 37
                sjf_array_char_initat(sjt_parent10, sjt_functionParam16, sjt_functionParam17);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            _return->_refCount = 1;
#line 42
            _return->offset = 0;
#line 42
            _return->count = newcount;
#line 42
            _return->data._refCount = 1;
#line 42
            sjf_array_char_copy(&_return->data, &newdata);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy((*_return), _parent);
    } else {
        bool sjt_capture5;
        int32_t sjt_capture6;
        sjs_array_char* sjt_parent12 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent12 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent12, &sjt_capture6);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture6) {
            int32_t sjt_capture7;
            sjs_array_char* sjt_parent13 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent13 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent13, &sjt_capture7);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture5 = ((_parent->offset + _parent->count) == sjt_capture7);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture5 = false;
        }

        if (sjt_capture5) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd4;
            int32_t sjt_forStart4;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart4 = 0;
#line 27
            sjt_forEnd4 = item->count;
#line 27
            i = sjt_forStart4;
            while (i < sjt_forEnd4) {
                int32_t sjt_functionParam19;
                char sjt_functionParam20;
                int32_t sjt_functionParam21;
                sjs_array_char* sjt_parent14 = 0;
                sjs_string* sjt_parent15 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent14 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam19 = newcount;
#line 18
                sjt_parent15 = item;
#line 27
                sjt_functionParam21 = i;
#line 27
                sjf_string_getat(sjt_parent15, sjt_functionParam21, &sjt_functionParam20);
#line 27
                sjf_array_char_initat(sjt_parent14, sjt_functionParam19, sjt_functionParam20);
#line 29
                newcount = newcount + 1;
#line 27
                i++;
            }

#line 27
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 27
            (*_return)->_refCount = 1;
#line 32
            (*_return)->offset = _parent->offset;
#line 32
            (*_return)->count = newcount;
#line 32
            (*_return)->data._refCount = 1;
#line 32
            sjf_array_char_copy(&(*_return)->data, &_parent->data);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd5;
            int32_t sjt_forStart5;
            int32_t sjt_functionParam22;
            int32_t sjt_functionParam23;
            int32_t sjt_functionParam24;
            sjs_array_char* sjt_parent16 = 0;
            sjs_array_char* sjt_parent17 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent16 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam22 = _parent->offset;
#line 34
            sjt_functionParam23 = _parent->count;
#line 34
            sjt_functionParam24 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent16, sjt_functionParam22, sjt_functionParam23, sjt_functionParam24, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent17 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent17, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart5 = 0;
#line 37
            sjt_forEnd5 = item->count;
#line 37
            i = sjt_forStart5;
            while (i < sjt_forEnd5) {
                int32_t sjt_functionParam25;
                char sjt_functionParam26;
                int32_t sjt_functionParam27;
                sjs_array_char* sjt_parent18 = 0;
                sjs_string* sjt_parent19 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent18 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam25 = newcount;
#line 18
                sjt_parent19 = item;
#line 37
                sjt_functionParam27 = i;
#line 37
                sjf_string_getat(sjt_parent19, sjt_functionParam27, &sjt_functionParam26);
#line 37
                sjf_array_char_initat(sjt_parent18, sjt_functionParam25, sjt_functionParam26);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 37
            (*_return)->_refCount = 1;
#line 42
            (*_return)->offset = 0;
#line 42
            (*_return)->count = newcount;
#line 42
            (*_return)->data._refCount = 1;
#line 42
            sjf_array_char_copy(&(*_return)->data, &newdata);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
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

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam11;
    sjs_array_char* sjt_parent6 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent6 = &_parent->data;
#line 64 "lib/sj-lib-common/string.sj"
    sjt_functionParam11 = _parent->offset + index;
#line 64
    sjf_array_char_getat(sjt_parent6, sjt_functionParam11, _return);
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
        sjf_array_char_gettotalcount(sjt_parent1, &sjt_capture1);
        if (((_parent->offset + _parent->count) + 1) > sjt_capture1) {
            int32_t sjt_functionParam1;
            int32_t sjt_functionParam2;
            int32_t sjt_functionParam3;
            sjs_array_char* sjt_parent2 = 0;

#line 168 "lib/sj-lib-common/array.sj"
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
#line 168 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
#line 136 "lib/sj-lib-common/string.sj"
            _parent->offset = 0;
        }

#line 139 "lib/sj-lib-common/string.sj"
        ((sjs_array*)_parent->data.v)->data[_parent->offset + _parent->count] = 0;
#line 141
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return) {
    sjs_array_char a = { -1 };
    int32_t i;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;
    void* v;

#line 120 "lib/sj-lib-common/string.sj"
    v = 0;
#line 122
    sjs_array* arr = createarray(1, ((_parent->count - 1) / 256 + 1) * 256);
#line 123
    v = arr;
#line 123
    a._refCount = 1;
#line 125
    a.v = v;
#line 125
    sjf_array_char(&a);
#line 126
    sjt_forStart6 = 0;
#line 126
    sjt_forEnd6 = _parent->count;
#line 126
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        int32_t sjt_functionParam29;
        char sjt_functionParam30;
        char sjt_functionParam31;
        int32_t sjt_functionParam32;
        sjs_array_char* sjt_parent21 = 0;
        sjs_array_char* sjt_parent22 = 0;

#line 52 "lib/sj-lib-common/array.sj"
        sjt_parent21 = &a;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam29 = i;
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent22 = &_parent->data;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam32 = i;
#line 126
        sjf_array_char_getat(sjt_parent22, sjt_functionParam32, &sjt_functionParam31);
#line 126
        sjf_char_touppercase(sjt_functionParam31, &sjt_functionParam30);
#line 126
        sjf_array_char_initat(sjt_parent21, sjt_functionParam29, sjt_functionParam30);
#line 126
        i++;
    }

#line 126
    _return->_refCount = 1;
#line 13
    _return->offset = 0;
#line 129
    _return->count = _parent->count;
#line 129
    _return->data._refCount = 1;
#line 129
    sjf_array_char_copy(&_return->data, &a);
#line 16
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);

    if (a._refCount == 1) { sjf_array_char_destroy(&a); }
;
}

void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return) {
    sjs_array_char a = { -1 };
    int32_t i;
    int32_t sjt_forEnd7;
    int32_t sjt_forStart7;
    void* v;

#line 120 "lib/sj-lib-common/string.sj"
    v = 0;
#line 122
    sjs_array* arr = createarray(1, ((_parent->count - 1) / 256 + 1) * 256);
#line 123
    v = arr;
#line 123
    a._refCount = 1;
#line 125
    a.v = v;
#line 125
    sjf_array_char(&a);
#line 126
    sjt_forStart7 = 0;
#line 126
    sjt_forEnd7 = _parent->count;
#line 126
    i = sjt_forStart7;
    while (i < sjt_forEnd7) {
        int32_t sjt_functionParam33;
        char sjt_functionParam34;
        char sjt_functionParam35;
        int32_t sjt_functionParam36;
        sjs_array_char* sjt_parent23 = 0;
        sjs_array_char* sjt_parent24 = 0;

#line 52 "lib/sj-lib-common/array.sj"
        sjt_parent23 = &a;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam33 = i;
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent24 = &_parent->data;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam36 = i;
#line 126
        sjf_array_char_getat(sjt_parent24, sjt_functionParam36, &sjt_functionParam35);
#line 126
        sjf_char_touppercase(sjt_functionParam35, &sjt_functionParam34);
#line 126
        sjf_array_char_initat(sjt_parent23, sjt_functionParam33, sjt_functionParam34);
#line 126
        i++;
    }

#line 126
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 126
    (*_return)->_refCount = 1;
#line 13
    (*_return)->offset = 0;
#line 129
    (*_return)->count = _parent->count;
#line 129
    (*_return)->data._refCount = 1;
#line 129
    sjf_array_char_copy(&(*_return)->data, &a);
#line 16
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));

    if (a._refCount == 1) { sjf_array_char_destroy(&a); }
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
    sjf_clock(&g_start);
#line 9
    g_str._refCount = 1;
#line 3 "perf1.sj"
    g_str.offset = 0;
#line 3
    g_str.count = 0;
#line 3
    g_str.data._refCount = 1;
#line 3
    g_str.data.v = &sjg_string1;
#line 3
    sjf_array_char(&g_str.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_str._isnullterminated = false;
#line 16
    sjf_string(&g_str);
#line 4 "perf1.sj"
    sjt_forStart1 = 0;
#line 4
    sjt_forEnd1 = 50000000;
#line 4
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        int32_t g_j;
        sjs_string g_s1 = { -1 };
        sjs_string g_s2 = { -1 };
        sjs_string g_s3 = { -1 };
        sjs_string sjt_call1 = { -1 };
        sjs_string sjt_call2 = { -1 };
        int32_t sjt_cast2;
        int32_t sjt_cast3;
        sjs_string sjt_funcold2 = { -1 };
        sjs_string sjt_funcold3 = { -1 };
        sjs_string* sjt_functionParam28 = 0;
        double sjt_functionParam4;
        double sjt_functionParam5;
        double sjt_functionParam6;
        int32_t sjt_functionParam7;
        int32_t sjt_functionParam8;
        sjs_string* sjt_parent20 = 0;
        sjs_string* sjt_parent25 = 0;
        double sjt_void1;
        double sjt_void2;

#line 4 "perf1.sj"
        sjt_cast2 = i;
#line 5
        sjt_functionParam4 = (double)sjt_cast2;
#line 5
        sjf_f64_sqrt(sjt_functionParam4, &sjt_void1);
#line 4
        sjt_cast3 = i;
#line 6
        sjt_functionParam5 = (double)sjt_cast3;
#line 6
        sjt_functionParam6 = 2.56;
#line 6
        sjf_f64_pow(sjt_functionParam5, sjt_functionParam6, &sjt_void2);
#line 7
        g_j = i * 745;
#line 4
        sjt_functionParam7 = i;
#line 22 "lib/sj-lib-common/i32.sj"
        sjt_functionParam8 = 10;
#line 22
        sjf_i32_asstring(sjt_functionParam7, sjt_functionParam8, &g_s1);
#line 18 "lib/sj-lib-common/string.sj"
        sjt_parent20 = &g_s1;
#line 18
        sjt_call1._refCount = 1;
#line 9 "perf1.sj"
        sjt_call1.offset = 0;
#line 9
        sjt_call1.count = 10;
#line 9
        sjt_call1.data._refCount = 1;
#line 9
        sjt_call1.data.v = &sjg_string2;
#line 9
        sjf_array_char(&sjt_call1.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call1._isnullterminated = false;
#line 16
        sjf_string(&sjt_call1);
#line 9 "perf1.sj"
        sjt_functionParam28 = &sjt_call1;
#line 9
        sjf_string_add(sjt_parent20, sjt_functionParam28, &g_s2);
#line 119 "lib/sj-lib-common/string.sj"
        sjt_parent25 = &g_s2;
#line 119
        sjf_string_touppercase(sjt_parent25, &g_s3);
        if ((i % 300) == 0) {
            sjt_funcold2._refCount = 1;
#line 12 "perf1.sj"
            sjt_funcold2.offset = 0;
#line 12
            sjt_funcold2.count = 0;
#line 12
            sjt_funcold2.data._refCount = 1;
#line 12
            sjt_funcold2.data.v = &sjg_string1;
#line 12
            sjf_array_char(&sjt_funcold2.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_funcold2._isnullterminated = false;
#line 16
            sjf_string(&sjt_funcold2);
#line 16
            if (g_str._refCount == 1) { sjf_string_destroy(&g_str); }
;
#line 12
            sjf_string_copy(&g_str, &sjt_funcold2);
        } else {
            sjs_string* sjt_functionParam37 = 0;
            int32_t sjt_functionParam38;
            int32_t sjt_functionParam39;
            sjs_string* sjt_parent26 = 0;

#line 18 "lib/sj-lib-common/string.sj"
            sjt_parent26 = &g_str;
#line 4 "perf1.sj"
            sjt_functionParam38 = i;
#line 14
            sjt_functionParam39 = 16;
#line 14
            sjf_i32_asstring(sjt_functionParam38, sjt_functionParam39, &sjt_call2);
#line 14
            sjt_functionParam37 = &sjt_call2;
#line 14
            sjf_string_add(sjt_parent26, sjt_functionParam37, &sjt_funcold3);
#line 14
            if (g_str._refCount == 1) { sjf_string_destroy(&g_str); }
;
#line 18 "lib/sj-lib-common/string.sj"
            sjf_string_copy(&g_str, &sjt_funcold3);
        }

#line 4 "perf1.sj"
        i++;

        if (g_s1._refCount == 1) { sjf_string_destroy(&g_s1); }
;
        if (g_s2._refCount == 1) { sjf_string_destroy(&g_s2); }
;
        if (g_s3._refCount == 1) { sjf_string_destroy(&g_s3); }
;
        if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
        if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
        if (sjt_funcold2._refCount == 1) { sjf_string_destroy(&sjt_funcold2); }
;
        if (sjt_funcold3._refCount == 1) { sjf_string_destroy(&sjt_funcold3); }
;
    }

#line 4
    sjf_clock(&g_end);
#line 4
    sjt_call4._refCount = 1;
#line 19
    sjt_call4.offset = 0;
#line 19
    sjt_call4.count = 18;
#line 19
    sjt_call4.data._refCount = 1;
#line 19
    sjt_call4.data.v = &sjg_string3;
#line 19
    sjf_array_char(&sjt_call4.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call4._isnullterminated = false;
#line 16
    sjf_string(&sjt_call4);
#line 19 "perf1.sj"
    sjt_parent27 = &sjt_call4;
#line 19
    sjt_cast4 = g_end - g_start;
#line 19
    sjt_cast5 = g_clocks_per_sec;
#line 19
    sjt_functionParam42 = ((double)sjt_cast4 * 1000.0) / (double)sjt_cast5;
#line 19
    sjf_f64_asstring(sjt_functionParam42, &sjt_call5);
#line 19
    sjt_functionParam41 = &sjt_call5;
#line 19
    sjf_string_add(sjt_parent27, sjt_functionParam41, &sjt_call3);
#line 19
    sjt_functionParam40 = &sjt_call3;
#line 19
    sjf_debug_writeline(sjt_functionParam40);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (g_str._refCount == 1) { sjf_string_destroy(&g_str); }
;
    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
    if (sjt_call5._refCount == 1) { sjf_string_destroy(&sjt_call5); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
