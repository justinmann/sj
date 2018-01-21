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
    char data[4];
} sjg_string10 = { 1, 4, 3, "ptr"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string11 = { 1, 7, 6, "#iface"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string12 = { 1, 11, 10, "array!char"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string13 = { 1, 6, 5, "clone"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string14 = { 1, 9, 8, "getcount"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string15 = { 1, 14, 13, "gettotalcount"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string16 = { 1, 6, 5, "class"};
struct {
    int refcount;
    int size;
    int count;
    char data[2];
} sjg_string17 = { 1, 2, 1, "b"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string18 = { 1, 10, 9, "writeline"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string19 = { 1, 7, 6, "global"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string2 = { 1, 5, 4, "bool"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string20 = { 1, 18, 17, "hash![type, bool]"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string21 = { 1, 18, 17, "_weakptrremovekey"};
struct {
    int refcount;
    int size;
    int count;
    char data[20];
} sjg_string22 = { 1, 20, 19, "_weakptrremovevalue"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string23 = { 1, 4, 3, "log"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string24 = { 1, 7, 6, "string"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string25 = { 1, 14, 13, "nullterminate"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string26 = { 1, 14, 13, "type_asstring"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string27 = { 1, 10, 9, "type_hash"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string28 = { 1, 13, 12, "type_isequal"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string29 = { 1, 5, 4, "type"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string3 = { 1, 6, 5, "()i32"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string30 = { 1, 4, 3, "u32"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string31 = { 1, 4, 3, "u64"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string32 = { 1, 5, 4, "void"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string4 = { 1, 5, 4, "char"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string5 = { 1, 4, 3, "f32"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string6 = { 1, 4, 3, "f64"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string7 = { 1, 4, 3, "i32"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string8 = { 1, 4, 3, "i64"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string9 = { 1, 9, 8, "loglevel"};

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
#define sjs_class_typeId 27
#define sji_iface_typeId 28

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_class sjs_class;
typedef struct td_sji_iface_vtbl sji_iface_vtbl;
typedef struct td_sji_iface sji_iface;

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
};

struct td_sji_iface_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_iface {
    sjs_object* _parent;
    sji_iface_vtbl* _vtbl;
};

sji_iface_vtbl sjs_class_iface_vtbl;
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

sjs_class g_a = { -1 };
int32_t g_clocks_per_sec;
int32_t g_d1;
int32_t g_d2;
int32_t g_d3;
int32_t g_d4;
float g_f32_pi;
sji_iface g_i = { 0 };
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
int32_t g_t1;
int32_t g_t2;
int32_t g_t3;
int32_t g_t4;
int32_t g_t5;
uint32_t g_u32_maxvalue;
int32_t result1;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call2 = { -1 };
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string sjt_call5 = { -1 };
sjs_string sjt_call6 = { -1 };
sjs_string sjt_call7 = { -1 };
sjs_string sjt_call8 = { -1 };
sjs_string sjt_call9 = { -1 };
sjs_class* sjt_cast2 = 0;
sjs_string* sjt_functionParam10 = 0;
int32_t sjt_functionParam11;
sjs_string* sjt_functionParam12 = 0;
int32_t sjt_functionParam13;
sjs_string* sjt_functionParam14 = 0;
int32_t sjt_functionParam15;
sjs_string* sjt_functionParam16 = 0;
int32_t sjt_functionParam17;
sjs_string* sjt_functionParam18 = 0;
int32_t sjt_functionParam19;
sjs_string* sjt_functionParam20 = 0;
int32_t sjt_functionParam21;
sjs_string* sjt_functionParam4 = 0;
int32_t sjt_functionParam5;
sjs_string* sjt_functionParam6 = 0;
int32_t sjt_functionParam7;
sjs_string* sjt_functionParam8 = 0;
int32_t sjt_functionParam9;
sji_iface sjt_parent4 = { 0 };
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_gettotalcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_class(sjs_class* _this);
void sjf_class_as_sji_iface(sjs_class* _this, sji_iface* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_getclasstype(sjs_object* _this, int* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string* _this);
void sjf_string_nullterminate(sjs_string* _parent);
void sjf_type_asstring(int32_t t, sjs_string* _return);
void sjf_type_asstring_heap(int32_t t, sjs_string** _return);
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

void sjf_class(sjs_class* _this) {
}

void sjf_class_as_sji_iface(sjs_class* _this, sji_iface* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_iface_vtbl;
}

void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_iface_typeId:  {
            sjf_class_as_sji_iface(_this, (sji_iface*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_getclasstype(sjs_object* _this, int* _return) {
    *_return = 27;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
#line 10 "lib/sj-lib-common/debug.sj"
    debugout("%s\n", string_char(data));
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
        int32_t sjt_capture2;
        sjs_array_char* sjt_parent1 = 0;
        sjs_array_char* sjt_parent2 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent1 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent1, &sjt_capture1);
#line 29
        sjt_parent2 = &_parent->data;
#line 29
        sjf_array_char_getcount(sjt_parent2, &sjt_capture2);
        if ((((_parent->offset + _parent->count) + 1) > sjt_capture1) || ((_parent->offset + _parent->count) != sjt_capture2)) {
            int32_t sjt_functionParam1;
            int32_t sjt_functionParam2;
            int32_t sjt_functionParam3;
            sjs_array_char* sjt_parent3 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent3 = &_parent->data;
#line 135 "lib/sj-lib-common/string.sj"
            sjt_functionParam1 = _parent->offset;
#line 135
            sjt_functionParam2 = _parent->count;
#line 135
            sjt_functionParam3 = _parent->count + 1;
#line 135
            sjf_array_char_clone(sjt_parent3, sjt_functionParam1, sjt_functionParam2, sjt_functionParam3, &sjt_funcold1);
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

void sjf_type_asstring(int32_t t, sjs_string* _return) {
    switch (t) {
        case 8:
        _return->_refCount = 1;
        _return->offset = 0;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.v = &sjg_string2;
        sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 30:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string3;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 9:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string4;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 6:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string5;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 7:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string6;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 1:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string7;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 2:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string8;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 12:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string9;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 5:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string10;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 28:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string11;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 13:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 0;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string1;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 23:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 10;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string12;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 26:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string13;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 25:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string14;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 24:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string15;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 27:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string16;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 29:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 1;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string17;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 31:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string18;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 14:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string19;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 15:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string20;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 18:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string21;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 19:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 19;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string22;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 20:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string23;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 21:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string24;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 22:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string25;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 32:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string26;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 16:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string27;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 17:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string28;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 11:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string29;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 3:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string30;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 4:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string31;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 10:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string32;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        default:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 0;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string1;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
    }
}

void sjf_type_asstring_heap(int32_t t, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 2 "lib/sj-lib-common/type.sj"
    (*_return)->offset = 0;
#line 2
    (*_return)->count = 0;
#line 2
    (*_return)->data._refCount = 1;
#line 2
    (*_return)->data.v = &sjg_string1;
#line 2
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
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
    sjs_class_iface_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_iface_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
    sjs_class_iface_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_class_getclasstype;
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
    sjf_class(&g_a);
#line 7 "type1.sj"
    sjt_cast2 = &g_a;
#line 1
    sjf_class_as_sji_iface(sjt_cast2, &g_i);
#line 9
    g_t1 = 27;
#line 10
    g_t2 = 1;
#line 11
    g_t3 = 30;
#line 12
    g_t4 = 28;
#line 1
    sjt_parent4 = g_i;
#line 13
    sjt_parent4._vtbl->getclasstype(sjt_parent4._parent, &g_t5);
#line 14
    g_d1 = 1;
#line 15
    g_d2 = 27;
#line 16
    g_d3 = 30;
#line 17
    g_d4 = 28;
#line 19
    sjt_functionParam5 = g_t1;
#line 19
    sjf_type_asstring(sjt_functionParam5, &sjt_call1);
#line 19
    sjt_functionParam4 = &sjt_call1;
#line 19
    sjf_debug_writeline(sjt_functionParam4);
#line 20
    sjt_functionParam7 = g_t2;
#line 20
    sjf_type_asstring(sjt_functionParam7, &sjt_call2);
#line 20
    sjt_functionParam6 = &sjt_call2;
#line 20
    sjf_debug_writeline(sjt_functionParam6);
#line 21
    sjt_functionParam9 = g_t3;
#line 21
    sjf_type_asstring(sjt_functionParam9, &sjt_call3);
#line 21
    sjt_functionParam8 = &sjt_call3;
#line 21
    sjf_debug_writeline(sjt_functionParam8);
#line 22
    sjt_functionParam11 = g_t4;
#line 22
    sjf_type_asstring(sjt_functionParam11, &sjt_call4);
#line 22
    sjt_functionParam10 = &sjt_call4;
#line 22
    sjf_debug_writeline(sjt_functionParam10);
#line 23
    sjt_functionParam13 = g_t5;
#line 23
    sjf_type_asstring(sjt_functionParam13, &sjt_call5);
#line 23
    sjt_functionParam12 = &sjt_call5;
#line 23
    sjf_debug_writeline(sjt_functionParam12);
#line 24
    sjt_functionParam15 = g_d1;
#line 24
    sjf_type_asstring(sjt_functionParam15, &sjt_call6);
#line 24
    sjt_functionParam14 = &sjt_call6;
#line 24
    sjf_debug_writeline(sjt_functionParam14);
#line 25
    sjt_functionParam17 = g_d2;
#line 25
    sjf_type_asstring(sjt_functionParam17, &sjt_call7);
#line 25
    sjt_functionParam16 = &sjt_call7;
#line 25
    sjf_debug_writeline(sjt_functionParam16);
#line 26
    sjt_functionParam19 = g_d3;
#line 26
    sjf_type_asstring(sjt_functionParam19, &sjt_call8);
#line 26
    sjt_functionParam18 = &sjt_call8;
#line 26
    sjf_debug_writeline(sjt_functionParam18);
#line 27
    sjt_functionParam21 = g_d4;
#line 27
    sjf_type_asstring(sjt_functionParam21, &sjt_call9);
#line 27
    sjt_functionParam20 = &sjt_call9;
#line 27
    sjf_debug_writeline(sjt_functionParam20);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (g_a._refCount == 1) { sjf_class_destroy(&g_a); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
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
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
