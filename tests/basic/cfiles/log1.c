#include <lib/common/common.h>

const char* sjg_string1 = "trace";
const char* sjg_string10 = "init";
const char* sjg_string11 = "oh my god";
const char* sjg_string12 = "doThing1";
const char* sjg_string13 = "bool";
const char* sjg_string14 = "()stack string";
const char* sjg_string15 = "char";
const char* sjg_string16 = "f32";
const char* sjg_string17 = "f64";
const char* sjg_string18 = "i32";
const char* sjg_string19 = "i64";
const char* sjg_string2 = "debug";
const char* sjg_string20 = "loglevel";
const char* sjg_string21 = "ptr";
const char* sjg_string22 = "array!char";
const char* sjg_string23 = "getat";
const char* sjg_string24 = "grow";
const char* sjg_string25 = "initat";
const char* sjg_string26 = "char_touppercase";
const char* sjg_string27 = "class";
const char* sjg_string28 = "dothing1";
const char* sjg_string29 = "writeline";
const char* sjg_string3 = "info";
const char* sjg_string30 = "global";
const char* sjg_string31 = "hash![type, bool]";
const char* sjg_string32 = "_weakptrremovekey";
const char* sjg_string33 = "_weakptrremovevalue";
const char* sjg_string34 = "lambda1";
const char* sjg_string35 = "invoke";
const char* sjg_string36 = "lambda2";
const char* sjg_string37 = "lambda3";
const char* sjg_string38 = "log";
const char* sjg_string39 = "_write";
const char* sjg_string4 = "warn";
const char* sjg_string40 = "loglevel_asstring";
const char* sjg_string41 = "string";
const char* sjg_string42 = "add";
const char* sjg_string43 = "nullterminate";
const char* sjg_string44 = "touppercase";
const char* sjg_string45 = "type_asstring";
const char* sjg_string46 = "type_hash";
const char* sjg_string47 = "type_isequal";
const char* sjg_string48 = "type";
const char* sjg_string49 = "u32";
const char* sjg_string5 = "error";
const char* sjg_string50 = "u64";
const char* sjg_string51 = "void";
const char* sjg_string6 = "fatal";
const char* sjg_string7 = "";
const char* sjg_string8 = " [";
const char* sjg_string9 = "] ";

#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_class_typeId 21
#define sjs_array_char_typeId 28
#define sjs_string_typeId 24
#define cb_string_heap_string_typeId 25
#define cb_string_heap_string_heap_typeId 25
#define sjs_lambda2_typeId 39
#define sjs_lambda3_typeId 42
#define sjs_lambda1_typeId 45

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_cb_string_heap_string cb_string_heap_string;
typedef struct td_cb_string_heap_string_heap cb_string_heap_string_heap;
typedef struct td_sjs_lambda2 sjs_lambda2;
typedef struct td_sjs_lambda3 sjs_lambda3;
typedef struct td_sjs_lambda1 sjs_lambda1;

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

struct td_sjs_class {
    int _refCount;
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

struct td_cb_string_heap_string {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_string* _return);
    void (*_cb_heap)(sjs_object* _parent, sjs_string** _return);
};

struct td_cb_string_heap_string_heap {
    cb_string_heap_string inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_lambda2 {
    int _refCount;
};

struct td_sjs_lambda3 {
    int _refCount;
};

struct td_sjs_lambda1 {
    int _refCount;
};

#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
int32_t g_loglevel_debug;
int32_t g_loglevel_error;
int32_t g_loglevel_fatal;
int32_t g_loglevel_info;
int32_t g_loglevel_trace;
int32_t g_loglevel_warn;

sjs_class g_c = { -1 };
int32_t g_clocks_per_sec;
void* g_emptystringdata;
float g_f32_pi;
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
uint32_t g_u32_maxvalue;
int32_t result1;
sjs_class* sjt_parent32 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_char_touppercase(char x, char* _return);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_dothing1(sjs_class* _parent);
void sjf_class_heap(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_getat(sjs_hash_type_bool* _parent, int32_t key, bool_option* _return);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_lambda1(sjs_lambda1* _this);
void sjf_lambda1_copy(sjs_lambda1* _this, sjs_lambda1* _from);
void sjf_lambda1_destroy(sjs_lambda1* _this);
void sjf_lambda1_heap(sjs_lambda1* _this);
void sjf_lambda1_invoke(sjs_lambda1* _parent, sjs_string* _return);
void sjf_lambda1_invoke_heap(sjs_lambda1* _parent, sjs_string** _return);
void sjf_lambda2(sjs_lambda2* _this);
void sjf_lambda2_copy(sjs_lambda2* _this, sjs_lambda2* _from);
void sjf_lambda2_destroy(sjs_lambda2* _this);
void sjf_lambda2_heap(sjs_lambda2* _this);
void sjf_lambda2_invoke(sjs_lambda2* _parent, sjs_string* _return);
void sjf_lambda2_invoke_heap(sjs_lambda2* _parent, sjs_string** _return);
void sjf_lambda3(sjs_lambda3* _this);
void sjf_lambda3_copy(sjs_lambda3* _this, sjs_lambda3* _from);
void sjf_lambda3_destroy(sjs_lambda3* _this);
void sjf_lambda3_heap(sjs_lambda3* _this);
void sjf_lambda3_invoke(sjs_lambda3* _parent, sjs_string* _return);
void sjf_lambda3_invoke_heap(sjs_lambda3* _parent, sjs_string** _return);
void sjf_log(sjs_log* _this);
void sjf_log__write(sjs_log* _parent, int32_t level, sjs_hash_type_bool* includes, int32_t t, cb_string_heap_string cb);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_error(sjs_log* _parent, int32_t t, cb_string_heap_string cb);
void sjf_log_heap(sjs_log* _this);
void sjf_log_info(sjs_log* _parent, int32_t t, cb_string_heap_string cb);
void sjf_loglevel_asstring(int32_t e, sjs_string* _return);
void sjf_loglevel_asstring_heap(int32_t e, sjs_string** _return);
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
#include <lib/common/common.c>
void sjf_array_char(sjs_array_char* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 333 "lib/common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !true && !false
#line 338
            char* p = (char*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    char* p = (char*)_parent->data;
#line 14
    #line 8 "lib/common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    void* newdata;

#line 135 "lib/common/array.sj"
    newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
#line 143
        int* refcount = (int*)newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        char* p = (char*)_parent->data;
#line 151
        char* newp = (char*)newdata;
#line 153
        int count = _parent->count;
#line 155
        #if true
#line 156
        memcpy(newp, p, sizeof(char) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            #line 136 "lib/common/array.sj"
newp[i] = p[i];
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    _return->_refCount = 1;
#line 134
    _return->datasize = newsize;
#line 164
    _return->data = newdata;
#line 4
    _return->isglobal = false;
#line 164
    _return->count = _parent->count;
#line 164
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    void* newdata;

#line 135 "lib/common/array.sj"
    newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
#line 143
        int* refcount = (int*)newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        char* p = (char*)_parent->data;
#line 151
        char* newp = (char*)newdata;
#line 153
        int count = _parent->count;
#line 155
        #if true
#line 156
        memcpy(newp, p, sizeof(char) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            #line 136 "lib/common/array.sj"
newp[i] = p[i];
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
#line 162
    (*_return)->_refCount = 1;
#line 134
    (*_return)->datasize = newsize;
#line 164
    (*_return)->data = newdata;
#line 4
    (*_return)->isglobal = false;
#line 164
    (*_return)->count = _parent->count;
#line 164
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
#line 36 "lib/common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    char* p = (char*)_parent->data;
#line 44
    #line 34 "lib/common/array.sj"
p[index] = item;
;
#line 45
    _parent->count = index + 1;
}

void sjf_char_touppercase(char x, char* _return) {
#line 3 "lib/common/char.sj"
    #line 2 "lib/common/char.sj"
(*_return) = toupper(x);
return;
}

void sjf_class(sjs_class* _this) {
    sjs_lambda2 sjt_call28 = { -1 };
    sjs_lambda3 sjt_call29 = { -1 };
    int32_t sjt_functionParam41;
    cb_string_heap_string sjt_functionParam42;
    int32_t sjt_functionParam47;
    cb_string_heap_string sjt_functionParam48;
    sjs_log* sjt_parent27 = 0;
    sjs_log* sjt_parent28 = 0;

#line 30 "lib/common/log.sj"
    sjt_parent27 = &g_log;
#line 6 "log1.sj"
    sjt_functionParam41 = 21;
#line 6
    sjs_lambda2* lambainit1;
#line 6
    sjt_call28._refCount = 1;
#line 6
    sjf_lambda2(&sjt_call28);
#line 6
    lambainit1 = &sjt_call28;
#line 6
    sjt_functionParam42._parent = (sjs_object*)lambainit1;
#line 6
    sjt_functionParam42._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda2_invoke;
#line 6
    sjt_functionParam42._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda2_invoke_heap;
#line 6
    sjf_log_info(sjt_parent27, sjt_functionParam41, sjt_functionParam42);
#line 38 "lib/common/log.sj"
    sjt_parent28 = &g_log;
#line 7 "log1.sj"
    sjt_functionParam47 = 21;
#line 7
    sjs_lambda3* lambainit2;
#line 7
    sjt_call29._refCount = 1;
#line 7
    sjf_lambda3(&sjt_call29);
#line 7
    lambainit2 = &sjt_call29;
#line 7
    sjt_functionParam48._parent = (sjs_object*)lambainit2;
#line 7
    sjt_functionParam48._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda3_invoke;
#line 7
    sjt_functionParam48._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda3_invoke_heap;
#line 7
    sjf_log_error(sjt_parent28, sjt_functionParam47, sjt_functionParam48);

    if (sjt_call28._refCount == 1) { sjf_lambda2_destroy(&sjt_call28); }
;
    if (sjt_call29._refCount == 1) { sjf_lambda3_destroy(&sjt_call29); }
;
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_dothing1(sjs_class* _parent) {
    sjs_lambda1 sjt_call32 = { -1 };
    int32_t sjt_functionParam53;
    cb_string_heap_string sjt_functionParam54;
    sjs_log* sjt_parent31 = 0;

#line 30 "lib/common/log.sj"
    sjt_parent31 = &g_log;
#line 3 "log1.sj"
    sjt_functionParam53 = 21;
#line 3
    sjs_lambda1* lambainit5;
#line 3
    sjt_call32._refCount = 1;
#line 3
    sjf_lambda1(&sjt_call32);
#line 3
    lambainit5 = &sjt_call32;
#line 3
    sjt_functionParam54._parent = (sjs_object*)lambainit5;
#line 3
    sjt_functionParam54._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda1_invoke;
#line 3
    sjt_functionParam54._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda1_invoke_heap;
#line 3
    sjf_log_info(sjt_parent31, sjt_functionParam53, sjt_functionParam54);

    if (sjt_call32._refCount == 1) { sjf_lambda1_destroy(&sjt_call32); }
;
}

void sjf_class_heap(sjs_class* _this) {
    sjs_lambda2 sjt_call30 = { -1 };
    sjs_lambda3 sjt_call31 = { -1 };
    int32_t sjt_functionParam49;
    cb_string_heap_string sjt_functionParam50;
    int32_t sjt_functionParam51;
    cb_string_heap_string sjt_functionParam52;
    sjs_log* sjt_parent29 = 0;
    sjs_log* sjt_parent30 = 0;

#line 30 "lib/common/log.sj"
    sjt_parent29 = &g_log;
#line 6 "log1.sj"
    sjt_functionParam49 = 21;
#line 6
    sjs_lambda2* lambainit3;
#line 6
    sjt_call30._refCount = 1;
#line 6
    sjf_lambda2(&sjt_call30);
#line 6
    lambainit3 = &sjt_call30;
#line 6
    sjt_functionParam50._parent = (sjs_object*)lambainit3;
#line 6
    sjt_functionParam50._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda2_invoke;
#line 6
    sjt_functionParam50._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda2_invoke_heap;
#line 6
    sjf_log_info(sjt_parent29, sjt_functionParam49, sjt_functionParam50);
#line 38 "lib/common/log.sj"
    sjt_parent30 = &g_log;
#line 7 "log1.sj"
    sjt_functionParam51 = 21;
#line 7
    sjs_lambda3* lambainit4;
#line 7
    sjt_call31._refCount = 1;
#line 7
    sjf_lambda3(&sjt_call31);
#line 7
    lambainit4 = &sjt_call31;
#line 7
    sjt_functionParam52._parent = (sjs_object*)lambainit4;
#line 7
    sjt_functionParam52._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda3_invoke;
#line 7
    sjt_functionParam52._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda3_invoke_heap;
#line 7
    sjf_log_error(sjt_parent30, sjt_functionParam51, sjt_functionParam52);

    if (sjt_call30._refCount == 1) { sjf_lambda2_destroy(&sjt_call30); }
;
    if (sjt_call31._refCount == 1) { sjf_lambda3_destroy(&sjt_call31); }
;
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent5 = 0;

#line 9 "lib/common/debug.sj"
    sjt_parent5 = data;
#line 9
    sjf_string_nullterminate(sjt_parent5);
#line 12
    debugout("%s\n", (char*)data->data.data);
}

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
#line 180 "lib/common/hash.sj"
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
#line 192 "lib/common/hash.sj"
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
#line 230 "lib/common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
#line 236 "lib/common/hash.sj"
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
        kh_destroy(type_bool_hash_type, _this->_hash);
#line 258
    }
}

void sjf_hash_type_bool_getat(sjs_hash_type_bool* _parent, int32_t key, bool_option* _return) {
#line 23 "lib/common/hash.sj"
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
#line 25
    #if false
#line 26
    khiter_t k = kh_get(type_bool_hash_type, p, *key);
#line 27
    #else
#line 28
    khiter_t k = kh_get(type_bool_hash_type, p, key);
#line 29
    #endif
#line 31
    if (k == kh_end(p)) {
#line 32
        #line 22 "lib/common/hash.sj"
(*_return) = bool_empty;
return;
#line 33
    }
#line 34
    #line 22 "lib/common/hash.sj"
_return->isvalid = true;
#line 22
_return->value = kh_val(p, k);
return;;
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_lambda1(sjs_lambda1* _this) {
}

void sjf_lambda1_copy(sjs_lambda1* _this, sjs_lambda1* _from) {
}

void sjf_lambda1_destroy(sjs_lambda1* _this) {
}

void sjf_lambda1_heap(sjs_lambda1* _this) {
}

void sjf_lambda1_invoke(sjs_lambda1* _parent, sjs_string* _return) {
    _return->_refCount = 1;
#line 3 "log1.sj"
    _return->count = 8;
#line 3
    _return->data._refCount = 1;
#line 3
    _return->data.datasize = 8;
#line 3
    _return->data.data = (void*)sjg_string12;
#line 3
    _return->data.isglobal = true;
#line 3
    _return->data.count = 8;
#line 3
    sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_lambda1_invoke_heap(sjs_lambda1* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 3 "log1.sj"
    (*_return)->count = 8;
#line 3
    (*_return)->data._refCount = 1;
#line 3
    (*_return)->data.datasize = 8;
#line 3
    (*_return)->data.data = (void*)sjg_string12;
#line 3
    (*_return)->data.isglobal = true;
#line 3
    (*_return)->data.count = 8;
#line 3
    sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));
}

void sjf_lambda2(sjs_lambda2* _this) {
}

void sjf_lambda2_copy(sjs_lambda2* _this, sjs_lambda2* _from) {
}

void sjf_lambda2_destroy(sjs_lambda2* _this) {
}

void sjf_lambda2_heap(sjs_lambda2* _this) {
}

void sjf_lambda2_invoke(sjs_lambda2* _parent, sjs_string* _return) {
    _return->_refCount = 1;
#line 6 "log1.sj"
    _return->count = 4;
#line 6
    _return->data._refCount = 1;
#line 6
    _return->data.datasize = 4;
#line 6
    _return->data.data = (void*)sjg_string10;
#line 6
    _return->data.isglobal = true;
#line 6
    _return->data.count = 4;
#line 6
    sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_lambda2_invoke_heap(sjs_lambda2* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 6 "log1.sj"
    (*_return)->count = 4;
#line 6
    (*_return)->data._refCount = 1;
#line 6
    (*_return)->data.datasize = 4;
#line 6
    (*_return)->data.data = (void*)sjg_string10;
#line 6
    (*_return)->data.isglobal = true;
#line 6
    (*_return)->data.count = 4;
#line 6
    sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));
}

void sjf_lambda3(sjs_lambda3* _this) {
}

void sjf_lambda3_copy(sjs_lambda3* _this, sjs_lambda3* _from) {
}

void sjf_lambda3_destroy(sjs_lambda3* _this) {
}

void sjf_lambda3_heap(sjs_lambda3* _this) {
}

void sjf_lambda3_invoke(sjs_lambda3* _parent, sjs_string* _return) {
    _return->_refCount = 1;
#line 7 "log1.sj"
    _return->count = 9;
#line 7
    _return->data._refCount = 1;
#line 7
    _return->data.datasize = 9;
#line 7
    _return->data.data = (void*)sjg_string11;
#line 7
    _return->data.isglobal = true;
#line 7
    _return->data.count = 9;
#line 7
    sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_lambda3_invoke_heap(sjs_lambda3* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 7 "log1.sj"
    (*_return)->count = 9;
#line 7
    (*_return)->data._refCount = 1;
#line 7
    (*_return)->data.datasize = 9;
#line 7
    (*_return)->data.data = (void*)sjg_string11;
#line 7
    (*_return)->data.isglobal = true;
#line 7
    (*_return)->data.count = 9;
#line 7
    sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));
}

void sjf_log(sjs_log* _this) {
}

void sjf_log__write(sjs_log* _parent, int32_t level, sjs_hash_type_bool* includes, int32_t t, cb_string_heap_string cb) {
    if (level >= _parent->minlevel) {
        if ((includes != 0)) {
            sjs_hash_type_bool* ifValue1 = 0;
            sjs_string sjt_call1 = { -1 };
            sjs_string sjt_call14 = { -1 };
            sjs_string sjt_call15 = { -1 };
            sjs_string sjt_call16 = { -1 };
            sjs_string sjt_call17 = { -1 };
            sjs_string sjt_call2 = { -1 };
            sjs_string sjt_call3 = { -1 };
            sjs_string sjt_call4 = { -1 };
            sjs_string sjt_call5 = { -1 };
            sjs_string sjt_call6 = { -1 };
            bool sjt_capture1;
            bool_option sjt_capture2;
            int32_t sjt_functionParam1;
            sjs_hash_type_bool* sjt_parent1 = 0;

#line 46 "lib/common/log.sj"
            ifValue1 = includes;
#line 21 "lib/common/hash.sj"
            sjt_parent1 = ifValue1;
#line 46 "lib/common/log.sj"
            sjt_functionParam1 = t;
#line 46
            sjf_hash_type_bool_getat(sjt_parent1, sjt_functionParam1, &sjt_capture2);
            if (sjt_capture2.isvalid) {
                int32_t sjt_functionParam2;
                bool_option sjt_getValue1;
                sjs_hash_type_bool* sjt_parent2 = 0;

#line 21 "lib/common/hash.sj"
                sjt_parent2 = ifValue1;
#line 46 "lib/common/log.sj"
                sjt_functionParam2 = t;
#line 46
                sjf_hash_type_bool_getat(sjt_parent2, sjt_functionParam2, &sjt_getValue1);
#line 49
                sjt_capture1 = sjt_getValue1.value;
            } else {
#line 49 "lib/common/log.sj"
                sjt_capture1 = false;
            }

            if (sjt_capture1) {
                int32_t sjt_functionParam24;
                sjs_string* sjt_functionParam25 = 0;
                sjs_string* sjt_functionParam26 = 0;
                int32_t sjt_functionParam27;
                sjs_string* sjt_functionParam28 = 0;
                sjs_string* sjt_functionParam29 = 0;
                sjs_string* sjt_functionParam6 = 0;
                sjs_string* sjt_parent13 = 0;
                sjs_string* sjt_parent14 = 0;
                sjs_string* sjt_parent15 = 0;
                sjs_string* sjt_parent16 = 0;
                sjs_string* sjt_parent21 = 0;

#line 46 "lib/common/log.sj"
                sjt_functionParam24 = level;
#line 46
                sjf_loglevel_asstring(sjt_functionParam24, &sjt_call6);
#line 50
                sjt_parent21 = &sjt_call6;
#line 50
                sjf_string_touppercase(sjt_parent21, &sjt_call5);
#line 50
                sjt_parent16 = &sjt_call5;
#line 50
                sjt_call14._refCount = 1;
#line 50
                sjt_call14.count = 2;
#line 50
                sjt_call14.data._refCount = 1;
#line 50
                sjt_call14.data.datasize = 2;
#line 50
                sjt_call14.data.data = (void*)sjg_string8;
#line 50
                sjt_call14.data.isglobal = true;
#line 50
                sjt_call14.data.count = 2;
#line 50
                sjf_array_char(&sjt_call14.data);
#line 14 "lib/common/string.sj"
                sjt_call14._isnullterminated = false;
#line 14
                sjf_string(&sjt_call14);
#line 50 "lib/common/log.sj"
                sjt_functionParam25 = &sjt_call14;
#line 50
                sjf_string_add(sjt_parent16, sjt_functionParam25, &sjt_call4);
#line 50
                sjt_parent15 = &sjt_call4;
#line 46
                sjt_functionParam27 = t;
#line 46
                sjf_type_asstring(sjt_functionParam27, &sjt_call15);
#line 50
                sjt_functionParam26 = &sjt_call15;
#line 50
                sjf_string_add(sjt_parent15, sjt_functionParam26, &sjt_call3);
#line 50
                sjt_parent14 = &sjt_call3;
#line 50
                sjt_call16._refCount = 1;
#line 50
                sjt_call16.count = 2;
#line 50
                sjt_call16.data._refCount = 1;
#line 50
                sjt_call16.data.datasize = 2;
#line 50
                sjt_call16.data.data = (void*)sjg_string9;
#line 50
                sjt_call16.data.isglobal = true;
#line 50
                sjt_call16.data.count = 2;
#line 50
                sjf_array_char(&sjt_call16.data);
#line 14 "lib/common/string.sj"
                sjt_call16._isnullterminated = false;
#line 14
                sjf_string(&sjt_call16);
#line 50 "lib/common/log.sj"
                sjt_functionParam28 = &sjt_call16;
#line 50
                sjf_string_add(sjt_parent14, sjt_functionParam28, &sjt_call2);
#line 50
                sjt_parent13 = &sjt_call2;
#line 50
                cb._cb(cb._parent, &sjt_call17);
#line 50
                sjt_functionParam29 = &sjt_call17;
#line 50
                sjf_string_add(sjt_parent13, sjt_functionParam29, &sjt_call1);
#line 50
                sjt_functionParam6 = &sjt_call1;
#line 50
                sjf_debug_writeline(sjt_functionParam6);
            }

            if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
            if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
;
            if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
;
            if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
;
            if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
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
        } else {
            sjs_string sjt_call18 = { -1 };
            sjs_string sjt_call19 = { -1 };
            sjs_string sjt_call20 = { -1 };
            sjs_string sjt_call21 = { -1 };
            sjs_string sjt_call22 = { -1 };
            sjs_string sjt_call23 = { -1 };
            sjs_string sjt_call24 = { -1 };
            sjs_string sjt_call25 = { -1 };
            sjs_string sjt_call26 = { -1 };
            sjs_string sjt_call27 = { -1 };
            sjs_string* sjt_functionParam30 = 0;
            int32_t sjt_functionParam31;
            sjs_string* sjt_functionParam32 = 0;
            sjs_string* sjt_functionParam33 = 0;
            int32_t sjt_functionParam34;
            sjs_string* sjt_functionParam35 = 0;
            sjs_string* sjt_functionParam36 = 0;
            sjs_string* sjt_parent22 = 0;
            sjs_string* sjt_parent23 = 0;
            sjs_string* sjt_parent24 = 0;
            sjs_string* sjt_parent25 = 0;
            sjs_string* sjt_parent26 = 0;

#line 46 "lib/common/log.sj"
            sjt_functionParam31 = level;
#line 46
            sjf_loglevel_asstring(sjt_functionParam31, &sjt_call23);
#line 53
            sjt_parent26 = &sjt_call23;
#line 53
            sjf_string_touppercase(sjt_parent26, &sjt_call22);
#line 53
            sjt_parent25 = &sjt_call22;
#line 53
            sjt_call24._refCount = 1;
#line 53
            sjt_call24.count = 2;
#line 53
            sjt_call24.data._refCount = 1;
#line 53
            sjt_call24.data.datasize = 2;
#line 53
            sjt_call24.data.data = (void*)sjg_string8;
#line 53
            sjt_call24.data.isglobal = true;
#line 53
            sjt_call24.data.count = 2;
#line 53
            sjf_array_char(&sjt_call24.data);
#line 14 "lib/common/string.sj"
            sjt_call24._isnullterminated = false;
#line 14
            sjf_string(&sjt_call24);
#line 53 "lib/common/log.sj"
            sjt_functionParam32 = &sjt_call24;
#line 53
            sjf_string_add(sjt_parent25, sjt_functionParam32, &sjt_call21);
#line 53
            sjt_parent24 = &sjt_call21;
#line 46
            sjt_functionParam34 = t;
#line 46
            sjf_type_asstring(sjt_functionParam34, &sjt_call25);
#line 53
            sjt_functionParam33 = &sjt_call25;
#line 53
            sjf_string_add(sjt_parent24, sjt_functionParam33, &sjt_call20);
#line 53
            sjt_parent23 = &sjt_call20;
#line 53
            sjt_call26._refCount = 1;
#line 53
            sjt_call26.count = 2;
#line 53
            sjt_call26.data._refCount = 1;
#line 53
            sjt_call26.data.datasize = 2;
#line 53
            sjt_call26.data.data = (void*)sjg_string9;
#line 53
            sjt_call26.data.isglobal = true;
#line 53
            sjt_call26.data.count = 2;
#line 53
            sjf_array_char(&sjt_call26.data);
#line 14 "lib/common/string.sj"
            sjt_call26._isnullterminated = false;
#line 14
            sjf_string(&sjt_call26);
#line 53 "lib/common/log.sj"
            sjt_functionParam35 = &sjt_call26;
#line 53
            sjf_string_add(sjt_parent23, sjt_functionParam35, &sjt_call19);
#line 53
            sjt_parent22 = &sjt_call19;
#line 53
            cb._cb(cb._parent, &sjt_call27);
#line 53
            sjt_functionParam36 = &sjt_call27;
#line 53
            sjf_string_add(sjt_parent22, sjt_functionParam36, &sjt_call18);
#line 53
            sjt_functionParam30 = &sjt_call18;
#line 53
            sjf_debug_writeline(sjt_functionParam30);

            if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
;
            if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
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
        }
    }
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
#line 13 "lib/common/log.sj"
    _this->minlevel = _from->minlevel;
#line 13
    sjs_hash_type_bool* copyoption2 = (_from->traceincludes._refCount != -1 ? &_from->traceincludes : 0);
    if (copyoption2 != 0) {
        _this->traceincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->traceincludes, copyoption2);
    } else {
        _this->traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption3 = (_from->debugincludes._refCount != -1 ? &_from->debugincludes : 0);
    if (copyoption3 != 0) {
        _this->debugincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->debugincludes, copyoption3);
    } else {
        _this->debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption4 = (_from->infoincludes._refCount != -1 ? &_from->infoincludes : 0);
    if (copyoption4 != 0) {
        _this->infoincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->infoincludes, copyoption4);
    } else {
        _this->infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption5 = (_from->warnincludes._refCount != -1 ? &_from->warnincludes : 0);
    if (copyoption5 != 0) {
        _this->warnincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->warnincludes, copyoption5);
    } else {
        _this->warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption6 = (_from->errorincludes._refCount != -1 ? &_from->errorincludes : 0);
    if (copyoption6 != 0) {
        _this->errorincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->errorincludes, copyoption6);
    } else {
        _this->errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption7 = (_from->fatalincludes._refCount != -1 ? &_from->fatalincludes : 0);
    if (copyoption7 != 0) {
        _this->fatalincludes._refCount = 1;
#line 13 "lib/common/log.sj"
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

void sjf_log_error(sjs_log* _parent, int32_t t, cb_string_heap_string cb) {
    int32_t sjt_functionParam43;
    sjs_hash_type_bool* sjt_functionParam44 = 0;
    int32_t sjt_functionParam45;
    cb_string_heap_string sjt_functionParam46;

#line 39 "lib/common/log.sj"
    sjt_functionParam43 = g_loglevel_error;
#line 39
    sjt_functionParam44 = (_parent->errorincludes._refCount != -1 ? &_parent->errorincludes : 0);
#line 38
    sjt_functionParam45 = t;
#line 38
    sjt_functionParam46 = cb;
#line 38
    sjf_log__write(_parent, sjt_functionParam43, sjt_functionParam44, sjt_functionParam45, sjt_functionParam46);
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_log_info(sjs_log* _parent, int32_t t, cb_string_heap_string cb) {
    int32_t sjt_functionParam37;
    sjs_hash_type_bool* sjt_functionParam38 = 0;
    int32_t sjt_functionParam39;
    cb_string_heap_string sjt_functionParam40;

#line 31 "lib/common/log.sj"
    sjt_functionParam37 = g_loglevel_info;
#line 31
    sjt_functionParam38 = (_parent->infoincludes._refCount != -1 ? &_parent->infoincludes : 0);
#line 30
    sjt_functionParam39 = t;
#line 30
    sjt_functionParam40 = cb;
#line 30
    sjf_log__write(_parent, sjt_functionParam37, sjt_functionParam38, sjt_functionParam39, sjt_functionParam40);
}

void sjf_loglevel_asstring(int32_t e, sjs_string* _return) {
    int32_t underscore1;

#line 1 "lib/common/log.sj"
    underscore1 = e;
    if (underscore1 == 0) {
        _return->_refCount = 1;
#line 1 "lib/common/log.sj"
        _return->count = 5;
#line 1
        _return->data._refCount = 1;
#line 1
        _return->data.datasize = 5;
#line 1
        _return->data.data = (void*)sjg_string1;
#line 1
        _return->data.isglobal = true;
#line 1
        _return->data.count = 5;
#line 1
        sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    } else {
        if (underscore1 == 1) {
            _return->_refCount = 1;
#line 1 "lib/common/log.sj"
            _return->count = 5;
#line 1
            _return->data._refCount = 1;
#line 1
            _return->data.datasize = 5;
#line 1
            _return->data.data = (void*)sjg_string2;
#line 1
            _return->data.isglobal = true;
#line 1
            _return->data.count = 5;
#line 1
            sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
            _return->_isnullterminated = false;
#line 14
            sjf_string(_return);
        } else {
            if (underscore1 == 2) {
                _return->_refCount = 1;
#line 1 "lib/common/log.sj"
                _return->count = 4;
#line 1
                _return->data._refCount = 1;
#line 1
                _return->data.datasize = 4;
#line 1
                _return->data.data = (void*)sjg_string3;
#line 1
                _return->data.isglobal = true;
#line 1
                _return->data.count = 4;
#line 1
                sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
                _return->_isnullterminated = false;
#line 14
                sjf_string(_return);
            } else {
                if (underscore1 == 3) {
                    _return->_refCount = 1;
#line 1 "lib/common/log.sj"
                    _return->count = 4;
#line 1
                    _return->data._refCount = 1;
#line 1
                    _return->data.datasize = 4;
#line 1
                    _return->data.data = (void*)sjg_string4;
#line 1
                    _return->data.isglobal = true;
#line 1
                    _return->data.count = 4;
#line 1
                    sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
                    _return->_isnullterminated = false;
#line 14
                    sjf_string(_return);
                } else {
                    if (underscore1 == 4) {
                        _return->_refCount = 1;
#line 1 "lib/common/log.sj"
                        _return->count = 5;
#line 1
                        _return->data._refCount = 1;
#line 1
                        _return->data.datasize = 5;
#line 1
                        _return->data.data = (void*)sjg_string5;
#line 1
                        _return->data.isglobal = true;
#line 1
                        _return->data.count = 5;
#line 1
                        sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
                        _return->_isnullterminated = false;
#line 14
                        sjf_string(_return);
                    } else {
                        if (underscore1 == 5) {
                            _return->_refCount = 1;
#line 1 "lib/common/log.sj"
                            _return->count = 5;
#line 1
                            _return->data._refCount = 1;
#line 1
                            _return->data.datasize = 5;
#line 1
                            _return->data.data = (void*)sjg_string6;
#line 1
                            _return->data.isglobal = true;
#line 1
                            _return->data.count = 5;
#line 1
                            sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
                            _return->_isnullterminated = false;
#line 14
                            sjf_string(_return);
                        } else {
                            _return->_refCount = 1;
#line 1 "lib/common/log.sj"
                            _return->count = 0;
#line 1
                            _return->data._refCount = 1;
#line 1
                            _return->data.datasize = 0;
#line 1
                            _return->data.data = (void*)sjg_string7;
#line 1
                            _return->data.isglobal = true;
#line 1
                            _return->data.count = 0;
#line 1
                            sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
                            _return->_isnullterminated = false;
#line 14
                            sjf_string(_return);
                        }
                    }
                }
            }
        }
    }
}

void sjf_loglevel_asstring_heap(int32_t e, sjs_string** _return) {
    int32_t underscore2;

#line 1 "lib/common/log.sj"
    underscore2 = e;
    if (underscore2 == 0) {
        sjs_string sjt_call7 = { -1 };

        sjt_call7._refCount = 1;
#line 1 "lib/common/log.sj"
        sjt_call7.count = 5;
#line 1
        sjt_call7.data._refCount = 1;
#line 1
        sjt_call7.data.datasize = 5;
#line 1
        sjt_call7.data.data = (void*)sjg_string1;
#line 1
        sjt_call7.data.isglobal = true;
#line 1
        sjt_call7.data.count = 5;
#line 1
        sjf_array_char(&sjt_call7.data);
#line 14 "lib/common/string.sj"
        sjt_call7._isnullterminated = false;
#line 14
        sjf_string(&sjt_call7);
#line 14
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
        (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
        sjf_string_copy((*_return), &sjt_call7);

        if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
;
    } else {
        if (underscore2 == 1) {
            sjs_string sjt_call8 = { -1 };

            sjt_call8._refCount = 1;
#line 1 "lib/common/log.sj"
            sjt_call8.count = 5;
#line 1
            sjt_call8.data._refCount = 1;
#line 1
            sjt_call8.data.datasize = 5;
#line 1
            sjt_call8.data.data = (void*)sjg_string2;
#line 1
            sjt_call8.data.isglobal = true;
#line 1
            sjt_call8.data.count = 5;
#line 1
            sjf_array_char(&sjt_call8.data);
#line 14 "lib/common/string.sj"
            sjt_call8._isnullterminated = false;
#line 14
            sjf_string(&sjt_call8);
#line 14
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
            (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
            sjf_string_copy((*_return), &sjt_call8);

            if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
        } else {
            if (underscore2 == 2) {
                sjs_string sjt_call9 = { -1 };

                sjt_call9._refCount = 1;
#line 1 "lib/common/log.sj"
                sjt_call9.count = 4;
#line 1
                sjt_call9.data._refCount = 1;
#line 1
                sjt_call9.data.datasize = 4;
#line 1
                sjt_call9.data.data = (void*)sjg_string3;
#line 1
                sjt_call9.data.isglobal = true;
#line 1
                sjt_call9.data.count = 4;
#line 1
                sjf_array_char(&sjt_call9.data);
#line 14 "lib/common/string.sj"
                sjt_call9._isnullterminated = false;
#line 14
                sjf_string(&sjt_call9);
#line 14
                (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
                (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
                sjf_string_copy((*_return), &sjt_call9);

                if (sjt_call9._refCount == 1) { sjf_string_destroy(&sjt_call9); }
;
            } else {
                if (underscore2 == 3) {
                    sjs_string sjt_call10 = { -1 };

                    sjt_call10._refCount = 1;
#line 1 "lib/common/log.sj"
                    sjt_call10.count = 4;
#line 1
                    sjt_call10.data._refCount = 1;
#line 1
                    sjt_call10.data.datasize = 4;
#line 1
                    sjt_call10.data.data = (void*)sjg_string4;
#line 1
                    sjt_call10.data.isglobal = true;
#line 1
                    sjt_call10.data.count = 4;
#line 1
                    sjf_array_char(&sjt_call10.data);
#line 14 "lib/common/string.sj"
                    sjt_call10._isnullterminated = false;
#line 14
                    sjf_string(&sjt_call10);
#line 14
                    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
                    (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
                    sjf_string_copy((*_return), &sjt_call10);

                    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
;
                } else {
                    if (underscore2 == 4) {
                        sjs_string sjt_call11 = { -1 };

                        sjt_call11._refCount = 1;
#line 1 "lib/common/log.sj"
                        sjt_call11.count = 5;
#line 1
                        sjt_call11.data._refCount = 1;
#line 1
                        sjt_call11.data.datasize = 5;
#line 1
                        sjt_call11.data.data = (void*)sjg_string5;
#line 1
                        sjt_call11.data.isglobal = true;
#line 1
                        sjt_call11.data.count = 5;
#line 1
                        sjf_array_char(&sjt_call11.data);
#line 14 "lib/common/string.sj"
                        sjt_call11._isnullterminated = false;
#line 14
                        sjf_string(&sjt_call11);
#line 14
                        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
                        (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
                        sjf_string_copy((*_return), &sjt_call11);

                        if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
;
                    } else {
                        if (underscore2 == 5) {
                            sjs_string sjt_call12 = { -1 };

                            sjt_call12._refCount = 1;
#line 1 "lib/common/log.sj"
                            sjt_call12.count = 5;
#line 1
                            sjt_call12.data._refCount = 1;
#line 1
                            sjt_call12.data.datasize = 5;
#line 1
                            sjt_call12.data.data = (void*)sjg_string6;
#line 1
                            sjt_call12.data.isglobal = true;
#line 1
                            sjt_call12.data.count = 5;
#line 1
                            sjf_array_char(&sjt_call12.data);
#line 14 "lib/common/string.sj"
                            sjt_call12._isnullterminated = false;
#line 14
                            sjf_string(&sjt_call12);
#line 14
                            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
                            (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
                            sjf_string_copy((*_return), &sjt_call12);

                            if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
;
                        } else {
                            sjs_string sjt_call13 = { -1 };

                            sjt_call13._refCount = 1;
#line 1 "lib/common/log.sj"
                            sjt_call13.count = 0;
#line 1
                            sjt_call13.data._refCount = 1;
#line 1
                            sjt_call13.data.datasize = 0;
#line 1
                            sjt_call13.data.data = (void*)sjg_string7;
#line 1
                            sjt_call13.data.isglobal = true;
#line 1
                            sjt_call13.data.count = 0;
#line 1
                            sjf_array_char(&sjt_call13.data);
#line 14 "lib/common/string.sj"
                            sjt_call13._isnullterminated = false;
#line 14
                            sjf_string(&sjt_call13);
#line 14
                            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
                            (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
                            sjf_string_copy((*_return), &sjt_call13);

                            if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
                        }
                    }
                }
            }
        }
    }
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
#line 18 "lib/common/string.sj"
        _return->count = _parent->count;
#line 18
        _return->data._refCount = 1;
#line 18
        sjf_array_char_copy(&_return->data, &_parent->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t newcount;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam7;
            sjs_array_char* sjt_parent6 = 0;

#line 134 "lib/common/array.sj"
            sjt_parent6 = &_parent->data;
#line 21 "lib/common/string.sj"
            sjt_functionParam7 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent6, sjt_functionParam7, &newdata);
        } else {
            newdata._refCount = 1;
#line 20 "lib/common/string.sj"
            sjf_array_char_copy(&newdata, &_parent->data);
        }

#line 25 "lib/common/string.sj"
        newcount = _parent->count;
#line 27
        sjt_forStart1 = 0;
#line 27
        sjt_forEnd1 = item->count;
#line 27
        i = sjt_forStart1;
        while (i < sjt_forEnd1) {
            int32_t sjt_functionParam11;
            int32_t sjt_functionParam8;
            char sjt_functionParam9;
            sjs_array_char* sjt_parent7 = 0;
            sjs_string* sjt_parent9 = 0;

#line 34 "lib/common/array.sj"
            sjt_parent7 = &newdata;
#line 28 "lib/common/string.sj"
            sjt_functionParam8 = newcount;
#line 16
            sjt_parent9 = item;
#line 27
            sjt_functionParam11 = i;
#line 27
            sjf_string_getat(sjt_parent9, sjt_functionParam11, &sjt_functionParam9);
#line 27
            sjf_array_char_initat(sjt_parent7, sjt_functionParam8, sjt_functionParam9);
#line 29
            newcount = newcount + 1;
#line 27
            i++;
        }

#line 27
        _return->_refCount = 1;
#line 32
        _return->count = newcount;
#line 32
        _return->data._refCount = 1;
#line 32
        sjf_array_char_copy(&_return->data, &newdata);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 18 "lib/common/string.sj"
        (*_return)->count = _parent->count;
#line 18
        (*_return)->data._refCount = 1;
#line 18
        sjf_array_char_copy(&(*_return)->data, &_parent->data);
#line 14
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t newcount;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam12;
            sjs_array_char* sjt_parent10 = 0;

#line 134 "lib/common/array.sj"
            sjt_parent10 = &_parent->data;
#line 21 "lib/common/string.sj"
            sjt_functionParam12 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent10, sjt_functionParam12, &newdata);
        } else {
            newdata._refCount = 1;
#line 20 "lib/common/string.sj"
            sjf_array_char_copy(&newdata, &_parent->data);
        }

#line 25 "lib/common/string.sj"
        newcount = _parent->count;
#line 27
        sjt_forStart2 = 0;
#line 27
        sjt_forEnd2 = item->count;
#line 27
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam13;
            char sjt_functionParam14;
            int32_t sjt_functionParam15;
            sjs_array_char* sjt_parent11 = 0;
            sjs_string* sjt_parent12 = 0;

#line 34 "lib/common/array.sj"
            sjt_parent11 = &newdata;
#line 28 "lib/common/string.sj"
            sjt_functionParam13 = newcount;
#line 16
            sjt_parent12 = item;
#line 27
            sjt_functionParam15 = i;
#line 27
            sjf_string_getat(sjt_parent12, sjt_functionParam15, &sjt_functionParam14);
#line 27
            sjf_array_char_initat(sjt_parent11, sjt_functionParam13, sjt_functionParam14);
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
        (*_return)->count = newcount;
#line 32
        (*_return)->data._refCount = 1;
#line 32
        sjf_array_char_copy(&(*_return)->data, &newdata);
#line 14
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 6 "lib/common/string.sj"
    _this->count = _from->count;
#line 6
    _this->data._refCount = 1;
#line 6
    sjf_array_char_copy(&_this->data, &_from->data);
#line 6
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam10;
    sjs_array_char* sjt_parent8 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent8 = &_parent->data;
#line 36 "lib/common/string.sj"
    sjt_functionParam10 = index;
#line 36
    sjf_array_char_getat(sjt_parent8, sjt_functionParam10, _return);
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_funcold1 = { -1 };

#line 73 "lib/common/string.sj"
    result2 = !(&_parent->data)->isglobal;
#line 73
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam4;
        char sjt_functionParam5;
        sjs_array_char* sjt_parent4 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam3;
            sjs_array_char* sjt_parent3 = 0;

            sjt_funcold1._refCount = 1;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
#line 134
            sjt_parent3 = &_parent->data;
#line 75 "lib/common/string.sj"
            sjt_functionParam3 = _parent->count + 1;
#line 75
            sjf_array_char_grow(sjt_parent3, sjt_functionParam3, &sjt_funcold1);
#line 75
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
        }

#line 34 "lib/common/array.sj"
        sjt_parent4 = &_parent->data;
#line 77 "lib/common/string.sj"
        sjt_functionParam4 = _parent->count;
#line 77
        sjt_functionParam5 = '\0';
#line 77
        sjf_array_char_initat(sjt_parent4, sjt_functionParam4, sjt_functionParam5);
#line 78
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return) {
    sjs_array_char a = { -1 };
    int32_t i;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;

    a._refCount = 1;
#line 65 "lib/common/string.sj"
    a.datasize = (((_parent->count - 1) / 256) + 1) * 256;
#line 3 "lib/common/array.sj"
    a.data = 0;
#line 4
    a.isglobal = false;
#line 5
    a.count = 0;
#line 5
    sjf_array_char(&a);
#line 66 "lib/common/string.sj"
    sjt_forStart3 = 0;
#line 66
    sjt_forEnd3 = _parent->count;
#line 66
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        int32_t sjt_functionParam16;
        char sjt_functionParam17;
        char sjt_functionParam18;
        int32_t sjt_functionParam19;
        sjs_array_char* sjt_parent17 = 0;
        sjs_array_char* sjt_parent18 = 0;

#line 34 "lib/common/array.sj"
        sjt_parent17 = &a;
#line 66 "lib/common/string.sj"
        sjt_functionParam16 = i;
#line 7 "lib/common/array.sj"
        sjt_parent18 = &_parent->data;
#line 66 "lib/common/string.sj"
        sjt_functionParam19 = i;
#line 66
        sjf_array_char_getat(sjt_parent18, sjt_functionParam19, &sjt_functionParam18);
#line 66
        sjf_char_touppercase(sjt_functionParam18, &sjt_functionParam17);
#line 66
        sjf_array_char_initat(sjt_parent17, sjt_functionParam16, sjt_functionParam17);
#line 66
        i++;
    }

#line 66
    _return->_refCount = 1;
#line 69
    _return->count = _parent->count;
#line 69
    _return->data._refCount = 1;
#line 69
    sjf_array_char_copy(&_return->data, &a);
#line 14
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);

    if (a._refCount == 1) { sjf_array_char_destroy(&a); }
;
}

void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return) {
    sjs_array_char a = { -1 };
    int32_t i;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;

    a._refCount = 1;
#line 65 "lib/common/string.sj"
    a.datasize = (((_parent->count - 1) / 256) + 1) * 256;
#line 3 "lib/common/array.sj"
    a.data = 0;
#line 4
    a.isglobal = false;
#line 5
    a.count = 0;
#line 5
    sjf_array_char(&a);
#line 66 "lib/common/string.sj"
    sjt_forStart4 = 0;
#line 66
    sjt_forEnd4 = _parent->count;
#line 66
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        int32_t sjt_functionParam20;
        char sjt_functionParam21;
        char sjt_functionParam22;
        int32_t sjt_functionParam23;
        sjs_array_char* sjt_parent19 = 0;
        sjs_array_char* sjt_parent20 = 0;

#line 34 "lib/common/array.sj"
        sjt_parent19 = &a;
#line 66 "lib/common/string.sj"
        sjt_functionParam20 = i;
#line 7 "lib/common/array.sj"
        sjt_parent20 = &_parent->data;
#line 66 "lib/common/string.sj"
        sjt_functionParam23 = i;
#line 66
        sjf_array_char_getat(sjt_parent20, sjt_functionParam23, &sjt_functionParam22);
#line 66
        sjf_char_touppercase(sjt_functionParam22, &sjt_functionParam21);
#line 66
        sjf_array_char_initat(sjt_parent19, sjt_functionParam20, sjt_functionParam21);
#line 66
        i++;
    }

#line 66
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 66
    (*_return)->_refCount = 1;
#line 69
    (*_return)->count = _parent->count;
#line 69
    (*_return)->data._refCount = 1;
#line 69
    sjf_array_char_copy(&(*_return)->data, &a);
#line 14
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));

    if (a._refCount == 1) { sjf_array_char_destroy(&a); }
;
}

void sjf_type_asstring(int32_t t, sjs_string* _return) {
    switch (t) {
        case 8:
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 4;
        _return->data.data = (void*)sjg_string13;
        _return->data.isglobal = true;
        _return->data.count = 4;
        sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 25:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string14;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 9:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string15;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 6:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string16;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 7:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string17;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 1:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string18;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 2:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string19;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 12:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string20;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 5:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string21;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 13:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 0;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 0;
#line 14
        _return->data.data = (void*)sjg_string7;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 0;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 28:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 10;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 10;
#line 14
        _return->data.data = (void*)sjg_string22;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 10;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 33:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string23;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 29:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string24;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 30:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string25;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 34:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 16;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 16;
#line 14
        _return->data.data = (void*)sjg_string26;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 16;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 21:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string27;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 44:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string28;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 26:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string29;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 14:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string30;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 15:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string31;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 18:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string32;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 19:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 19;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 19;
#line 14
        _return->data.data = (void*)sjg_string33;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 19;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 38:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string23;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 45:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string34;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 46:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string35;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 39:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string36;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 40:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string35;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 42:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string37;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 43:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string35;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 20:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string38;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 23:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string39;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 41:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string5;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 22:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string3;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 31:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string40;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 24:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string41;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 35:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string42;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 36:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string23;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 27:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string43;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 32:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 11;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 11;
#line 14
        _return->data.data = (void*)sjg_string44;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 11;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 37:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string45;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 16:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string46;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 17:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string47;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 11:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string48;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 3:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string49;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 4:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string50;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 10:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string51;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        default:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 0;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 0;
#line 14
        _return->data.data = (void*)sjg_string7;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 0;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
    }
}

void sjf_type_asstring_heap(int32_t t, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 2 "lib/common/type.sj"
    (*_return)->count = 0;
#line 2
    (*_return)->data._refCount = 1;
#line 2
    (*_return)->data.datasize = 0;
#line 2
    (*_return)->data.data = (void*)sjg_string7;
#line 2
    (*_return)->data.isglobal = true;
#line 2
    (*_return)->data.count = 0;
#line 2
    sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

#line 5 "lib/common/type.sj"
    sjt_cast1 = val;
#line 6
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
#line 10 "lib/common/type.sj"
    (*_return) = l == r;
}

int main(int argc, char** argv) {
#line 1 "lib/common/log.sj"
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
#line 1 "lib/common/f32.sj"
    g_f32_pi = 3.14159265358979323846f;
#line 1 "lib/common/i32.sj"
    g_u32_maxvalue = (uint32_t)4294967295u;
#line 3
    result1 = -1;
#line 3
    g_i32_maxvalue = result1 - 2147483647;
#line 4
    g_i32_minvalue = 2147483647;
#line 10 "lib/common/log.sj"
    g_log_includeall._refCount = -1;
#line 10
    sjt_value1._refCount = 1;
#line 10
    sjf_hash_type_bool(&sjt_value1);
#line 11
    sjs_hash_type_bool* copyoption1 = &sjt_value1;
    if (copyoption1 != 0) {
        g_log_excludeall._refCount = 1;
#line 11 "lib/common/log.sj"
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
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.traceincludes, copyoption8);
    } else {
        g_log.traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption9 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption9 != 0) {
        g_log.debugincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.debugincludes, copyoption9);
    } else {
        g_log.debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption10 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption10 != 0) {
        g_log.infoincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.infoincludes, copyoption10);
    } else {
        g_log.infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption11 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption11 != 0) {
        g_log.warnincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.warnincludes, copyoption11);
    } else {
        g_log.warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption12 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption12 != 0) {
        g_log.errorincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.errorincludes, copyoption12);
    } else {
        g_log.errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption13 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption13 != 0) {
        g_log.fatalincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.fatalincludes, copyoption13);
    } else {
        g_log.fatalincludes._refCount = -1;
    }

#line 13
    sjf_log(&g_log);
#line 1 "lib/common/string.sj"
    g_emptystringdata = 0;
#line 3
    g_emptystringdata = "";
#line 2 "lib/common/weakptr.sj"
    ptr_init();
#line 3
    weakptr_init();
#line 7 "lib/common/clock.sj"
    g_clocks_per_sec = 0;
#line 9
    g_clocks_per_sec = CLOCKS_PER_SEC;
#line 11 "log1.sj"
    (&g_log)->minlevel = g_loglevel_info;
#line 11
    g_c._refCount = 1;
#line 11
    sjf_class(&g_c);
#line 2
    sjt_parent32 = &g_c;
#line 2
    sjf_class_dothing1(sjt_parent32);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (g_c._refCount == 1) { sjf_class_destroy(&g_c); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
