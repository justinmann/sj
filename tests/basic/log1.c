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
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_class* sjt_parent32 = 0;
sjs_class sjv_c = { -1 };
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

void sjf_char_touppercase(char x, char* _return) {
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

    sjt_parent27 = &sjv_log;
    sjt_functionParam41 = 21;
    sjs_lambda2* lambainit1;
    sjt_call28._refCount = 1;
    sjf_lambda2(&sjt_call28);
    lambainit1 = &sjt_call28;
    sjt_functionParam42._parent = (sjs_object*)lambainit1;
    sjt_functionParam42._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda2_invoke;
    sjt_functionParam42._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda2_invoke_heap;
    sjf_log_info(sjt_parent27, sjt_functionParam41, sjt_functionParam42);
    sjt_parent28 = &sjv_log;
    sjt_functionParam47 = 21;
    sjs_lambda3* lambainit2;
    sjt_call29._refCount = 1;
    sjf_lambda3(&sjt_call29);
    lambainit2 = &sjt_call29;
    sjt_functionParam48._parent = (sjs_object*)lambainit2;
    sjt_functionParam48._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda3_invoke;
    sjt_functionParam48._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda3_invoke_heap;
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

    sjt_parent31 = &sjv_log;
    sjt_functionParam53 = 21;
    sjs_lambda1* lambainit5;
    sjt_call32._refCount = 1;
    sjf_lambda1(&sjt_call32);
    lambainit5 = &sjt_call32;
    sjt_functionParam54._parent = (sjs_object*)lambainit5;
    sjt_functionParam54._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda1_invoke;
    sjt_functionParam54._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda1_invoke_heap;
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

    sjt_parent29 = &sjv_log;
    sjt_functionParam49 = 21;
    sjs_lambda2* lambainit3;
    sjt_call30._refCount = 1;
    sjf_lambda2(&sjt_call30);
    lambainit3 = &sjt_call30;
    sjt_functionParam50._parent = (sjs_object*)lambainit3;
    sjt_functionParam50._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda2_invoke;
    sjt_functionParam50._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda2_invoke_heap;
    sjf_log_info(sjt_parent29, sjt_functionParam49, sjt_functionParam50);
    sjt_parent30 = &sjv_log;
    sjt_functionParam51 = 21;
    sjs_lambda3* lambainit4;
    sjt_call31._refCount = 1;
    sjf_lambda3(&sjt_call31);
    lambainit4 = &sjt_call31;
    sjt_functionParam52._parent = (sjs_object*)lambainit4;
    sjt_functionParam52._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda3_invoke;
    sjt_functionParam52._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda3_invoke_heap;
    sjf_log_error(sjt_parent30, sjt_functionParam51, sjt_functionParam52);

    if (sjt_call30._refCount == 1) { sjf_lambda2_destroy(&sjt_call30); }
;
    if (sjt_call31._refCount == 1) { sjf_lambda3_destroy(&sjt_call31); }
;
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent5 = 0;

    sjt_parent5 = data;
    sjf_string_nullterminate(sjt_parent5);
    debugout("%s\n", (char*)data->data.data);
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

void sjf_hash_type_bool_getat(sjs_hash_type_bool* _parent, int32_t key, bool_option* _return) {
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
    #if false
    khiter_t k = kh_get(type_bool_hash_type, p, *key);
    #else
    khiter_t k = kh_get(type_bool_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return) = bool_empty;
return;
    }
    _return->isvalid = true;
_return->value = kh_val(p, k);
return;;
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
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
    _return->count = 8;
    _return->data._refCount = 1;
    _return->data.datasize = 8;
    _return->data.data = (void*)sjg_string12;
    _return->data.isglobal = true;
    _return->data.count = 8;
    sjf_array_char(&_return->data);
    _return->_isnullterminated = false;
    sjf_string(_return);
}

void sjf_lambda1_invoke_heap(sjs_lambda1* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = 8;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 8;
    (*_return)->data.data = (void*)sjg_string12;
    (*_return)->data.isglobal = true;
    (*_return)->data.count = 8;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
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
    _return->count = 4;
    _return->data._refCount = 1;
    _return->data.datasize = 4;
    _return->data.data = (void*)sjg_string10;
    _return->data.isglobal = true;
    _return->data.count = 4;
    sjf_array_char(&_return->data);
    _return->_isnullterminated = false;
    sjf_string(_return);
}

void sjf_lambda2_invoke_heap(sjs_lambda2* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = 4;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 4;
    (*_return)->data.data = (void*)sjg_string10;
    (*_return)->data.isglobal = true;
    (*_return)->data.count = 4;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
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
    _return->count = 9;
    _return->data._refCount = 1;
    _return->data.datasize = 9;
    _return->data.data = (void*)sjg_string11;
    _return->data.isglobal = true;
    _return->data.count = 9;
    sjf_array_char(&_return->data);
    _return->_isnullterminated = false;
    sjf_string(_return);
}

void sjf_lambda3_invoke_heap(sjs_lambda3* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = 9;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 9;
    (*_return)->data.data = (void*)sjg_string11;
    (*_return)->data.isglobal = true;
    (*_return)->data.count = 9;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
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

            ifValue1 = includes;
            sjt_parent1 = ifValue1;
            sjt_functionParam1 = t;
            sjf_hash_type_bool_getat(sjt_parent1, sjt_functionParam1, &sjt_capture2);
            if (sjt_capture2.isvalid) {
                int32_t sjt_functionParam2;
                bool_option sjt_getValue1;
                sjs_hash_type_bool* sjt_parent2 = 0;

                sjt_parent2 = ifValue1;
                sjt_functionParam2 = t;
                sjf_hash_type_bool_getat(sjt_parent2, sjt_functionParam2, &sjt_getValue1);
                sjt_capture1 = sjt_getValue1.value;
            } else {
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

                sjt_functionParam24 = level;
                sjf_loglevel_asstring(sjt_functionParam24, &sjt_call6);
                sjt_parent21 = &sjt_call6;
                sjf_string_touppercase(sjt_parent21, &sjt_call5);
                sjt_parent16 = &sjt_call5;
                sjt_call14._refCount = 1;
                sjt_call14.count = 2;
                sjt_call14.data._refCount = 1;
                sjt_call14.data.datasize = 2;
                sjt_call14.data.data = (void*)sjg_string8;
                sjt_call14.data.isglobal = true;
                sjt_call14.data.count = 2;
                sjf_array_char(&sjt_call14.data);
                sjt_call14._isnullterminated = false;
                sjf_string(&sjt_call14);
                sjt_functionParam25 = &sjt_call14;
                sjf_string_add(sjt_parent16, sjt_functionParam25, &sjt_call4);
                sjt_parent15 = &sjt_call4;
                sjt_functionParam27 = t;
                sjf_type_asstring(sjt_functionParam27, &sjt_call15);
                sjt_functionParam26 = &sjt_call15;
                sjf_string_add(sjt_parent15, sjt_functionParam26, &sjt_call3);
                sjt_parent14 = &sjt_call3;
                sjt_call16._refCount = 1;
                sjt_call16.count = 2;
                sjt_call16.data._refCount = 1;
                sjt_call16.data.datasize = 2;
                sjt_call16.data.data = (void*)sjg_string9;
                sjt_call16.data.isglobal = true;
                sjt_call16.data.count = 2;
                sjf_array_char(&sjt_call16.data);
                sjt_call16._isnullterminated = false;
                sjf_string(&sjt_call16);
                sjt_functionParam28 = &sjt_call16;
                sjf_string_add(sjt_parent14, sjt_functionParam28, &sjt_call2);
                sjt_parent13 = &sjt_call2;
                cb._cb(cb._parent, &sjt_call17);
                sjt_functionParam29 = &sjt_call17;
                sjf_string_add(sjt_parent13, sjt_functionParam29, &sjt_call1);
                sjt_functionParam6 = &sjt_call1;
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

            sjt_functionParam31 = level;
            sjf_loglevel_asstring(sjt_functionParam31, &sjt_call23);
            sjt_parent26 = &sjt_call23;
            sjf_string_touppercase(sjt_parent26, &sjt_call22);
            sjt_parent25 = &sjt_call22;
            sjt_call24._refCount = 1;
            sjt_call24.count = 2;
            sjt_call24.data._refCount = 1;
            sjt_call24.data.datasize = 2;
            sjt_call24.data.data = (void*)sjg_string8;
            sjt_call24.data.isglobal = true;
            sjt_call24.data.count = 2;
            sjf_array_char(&sjt_call24.data);
            sjt_call24._isnullterminated = false;
            sjf_string(&sjt_call24);
            sjt_functionParam32 = &sjt_call24;
            sjf_string_add(sjt_parent25, sjt_functionParam32, &sjt_call21);
            sjt_parent24 = &sjt_call21;
            sjt_functionParam34 = t;
            sjf_type_asstring(sjt_functionParam34, &sjt_call25);
            sjt_functionParam33 = &sjt_call25;
            sjf_string_add(sjt_parent24, sjt_functionParam33, &sjt_call20);
            sjt_parent23 = &sjt_call20;
            sjt_call26._refCount = 1;
            sjt_call26.count = 2;
            sjt_call26.data._refCount = 1;
            sjt_call26.data.datasize = 2;
            sjt_call26.data.data = (void*)sjg_string9;
            sjt_call26.data.isglobal = true;
            sjt_call26.data.count = 2;
            sjf_array_char(&sjt_call26.data);
            sjt_call26._isnullterminated = false;
            sjf_string(&sjt_call26);
            sjt_functionParam35 = &sjt_call26;
            sjf_string_add(sjt_parent23, sjt_functionParam35, &sjt_call19);
            sjt_parent22 = &sjt_call19;
            cb._cb(cb._parent, &sjt_call27);
            sjt_functionParam36 = &sjt_call27;
            sjf_string_add(sjt_parent22, sjt_functionParam36, &sjt_call18);
            sjt_functionParam30 = &sjt_call18;
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

void sjf_log_error(sjs_log* _parent, int32_t t, cb_string_heap_string cb) {
    int32_t sjt_functionParam43;
    sjs_hash_type_bool* sjt_functionParam44 = 0;
    int32_t sjt_functionParam45;
    cb_string_heap_string sjt_functionParam46;

    sjt_functionParam43 = sjv_loglevel_error;
    sjt_functionParam44 = (_parent->errorincludes._refCount != -1 ? &_parent->errorincludes : 0);
    sjt_functionParam45 = t;
    sjt_functionParam46 = cb;
    sjf_log__write(_parent, sjt_functionParam43, sjt_functionParam44, sjt_functionParam45, sjt_functionParam46);
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_log_info(sjs_log* _parent, int32_t t, cb_string_heap_string cb) {
    int32_t sjt_functionParam37;
    sjs_hash_type_bool* sjt_functionParam38 = 0;
    int32_t sjt_functionParam39;
    cb_string_heap_string sjt_functionParam40;

    sjt_functionParam37 = sjv_loglevel_info;
    sjt_functionParam38 = (_parent->infoincludes._refCount != -1 ? &_parent->infoincludes : 0);
    sjt_functionParam39 = t;
    sjt_functionParam40 = cb;
    sjf_log__write(_parent, sjt_functionParam37, sjt_functionParam38, sjt_functionParam39, sjt_functionParam40);
}

void sjf_loglevel_asstring(int32_t e, sjs_string* _return) {
    int32_t underscore1;

    underscore1 = e;
    if (underscore1 == 0) {
        _return->_refCount = 1;
        _return->count = 5;
        _return->data._refCount = 1;
        _return->data.datasize = 5;
        _return->data.data = (void*)sjg_string1;
        _return->data.isglobal = true;
        _return->data.count = 5;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
    } else {
        if (underscore1 == 1) {
            _return->_refCount = 1;
            _return->count = 5;
            _return->data._refCount = 1;
            _return->data.datasize = 5;
            _return->data.data = (void*)sjg_string2;
            _return->data.isglobal = true;
            _return->data.count = 5;
            sjf_array_char(&_return->data);
            _return->_isnullterminated = false;
            sjf_string(_return);
        } else {
            if (underscore1 == 2) {
                _return->_refCount = 1;
                _return->count = 4;
                _return->data._refCount = 1;
                _return->data.datasize = 4;
                _return->data.data = (void*)sjg_string3;
                _return->data.isglobal = true;
                _return->data.count = 4;
                sjf_array_char(&_return->data);
                _return->_isnullterminated = false;
                sjf_string(_return);
            } else {
                if (underscore1 == 3) {
                    _return->_refCount = 1;
                    _return->count = 4;
                    _return->data._refCount = 1;
                    _return->data.datasize = 4;
                    _return->data.data = (void*)sjg_string4;
                    _return->data.isglobal = true;
                    _return->data.count = 4;
                    sjf_array_char(&_return->data);
                    _return->_isnullterminated = false;
                    sjf_string(_return);
                } else {
                    if (underscore1 == 4) {
                        _return->_refCount = 1;
                        _return->count = 5;
                        _return->data._refCount = 1;
                        _return->data.datasize = 5;
                        _return->data.data = (void*)sjg_string5;
                        _return->data.isglobal = true;
                        _return->data.count = 5;
                        sjf_array_char(&_return->data);
                        _return->_isnullterminated = false;
                        sjf_string(_return);
                    } else {
                        if (underscore1 == 5) {
                            _return->_refCount = 1;
                            _return->count = 5;
                            _return->data._refCount = 1;
                            _return->data.datasize = 5;
                            _return->data.data = (void*)sjg_string6;
                            _return->data.isglobal = true;
                            _return->data.count = 5;
                            sjf_array_char(&_return->data);
                            _return->_isnullterminated = false;
                            sjf_string(_return);
                        } else {
                            _return->_refCount = 1;
                            _return->count = 0;
                            _return->data._refCount = 1;
                            _return->data.datasize = 0;
                            _return->data.data = (void*)sjg_string7;
                            _return->data.isglobal = true;
                            _return->data.count = 0;
                            sjf_array_char(&_return->data);
                            _return->_isnullterminated = false;
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

    underscore2 = e;
    if (underscore2 == 0) {
        sjs_string sjt_call7 = { -1 };

        sjt_call7._refCount = 1;
        sjt_call7.count = 5;
        sjt_call7.data._refCount = 1;
        sjt_call7.data.datasize = 5;
        sjt_call7.data.data = (void*)sjg_string1;
        sjt_call7.data.isglobal = true;
        sjt_call7.data.count = 5;
        sjf_array_char(&sjt_call7.data);
        sjt_call7._isnullterminated = false;
        sjf_string(&sjt_call7);
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        sjf_string_copy((*_return), &sjt_call7);

        if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
;
    } else {
        if (underscore2 == 1) {
            sjs_string sjt_call8 = { -1 };

            sjt_call8._refCount = 1;
            sjt_call8.count = 5;
            sjt_call8.data._refCount = 1;
            sjt_call8.data.datasize = 5;
            sjt_call8.data.data = (void*)sjg_string2;
            sjt_call8.data.isglobal = true;
            sjt_call8.data.count = 5;
            sjf_array_char(&sjt_call8.data);
            sjt_call8._isnullterminated = false;
            sjf_string(&sjt_call8);
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
            (*_return)->_refCount = 1;
            sjf_string_copy((*_return), &sjt_call8);

            if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
        } else {
            if (underscore2 == 2) {
                sjs_string sjt_call9 = { -1 };

                sjt_call9._refCount = 1;
                sjt_call9.count = 4;
                sjt_call9.data._refCount = 1;
                sjt_call9.data.datasize = 4;
                sjt_call9.data.data = (void*)sjg_string3;
                sjt_call9.data.isglobal = true;
                sjt_call9.data.count = 4;
                sjf_array_char(&sjt_call9.data);
                sjt_call9._isnullterminated = false;
                sjf_string(&sjt_call9);
                (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
                (*_return)->_refCount = 1;
                sjf_string_copy((*_return), &sjt_call9);

                if (sjt_call9._refCount == 1) { sjf_string_destroy(&sjt_call9); }
;
            } else {
                if (underscore2 == 3) {
                    sjs_string sjt_call10 = { -1 };

                    sjt_call10._refCount = 1;
                    sjt_call10.count = 4;
                    sjt_call10.data._refCount = 1;
                    sjt_call10.data.datasize = 4;
                    sjt_call10.data.data = (void*)sjg_string4;
                    sjt_call10.data.isglobal = true;
                    sjt_call10.data.count = 4;
                    sjf_array_char(&sjt_call10.data);
                    sjt_call10._isnullterminated = false;
                    sjf_string(&sjt_call10);
                    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
                    (*_return)->_refCount = 1;
                    sjf_string_copy((*_return), &sjt_call10);

                    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
;
                } else {
                    if (underscore2 == 4) {
                        sjs_string sjt_call11 = { -1 };

                        sjt_call11._refCount = 1;
                        sjt_call11.count = 5;
                        sjt_call11.data._refCount = 1;
                        sjt_call11.data.datasize = 5;
                        sjt_call11.data.data = (void*)sjg_string5;
                        sjt_call11.data.isglobal = true;
                        sjt_call11.data.count = 5;
                        sjf_array_char(&sjt_call11.data);
                        sjt_call11._isnullterminated = false;
                        sjf_string(&sjt_call11);
                        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
                        (*_return)->_refCount = 1;
                        sjf_string_copy((*_return), &sjt_call11);

                        if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
;
                    } else {
                        if (underscore2 == 5) {
                            sjs_string sjt_call12 = { -1 };

                            sjt_call12._refCount = 1;
                            sjt_call12.count = 5;
                            sjt_call12.data._refCount = 1;
                            sjt_call12.data.datasize = 5;
                            sjt_call12.data.data = (void*)sjg_string6;
                            sjt_call12.data.isglobal = true;
                            sjt_call12.data.count = 5;
                            sjf_array_char(&sjt_call12.data);
                            sjt_call12._isnullterminated = false;
                            sjf_string(&sjt_call12);
                            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
                            (*_return)->_refCount = 1;
                            sjf_string_copy((*_return), &sjt_call12);

                            if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
;
                        } else {
                            sjs_string sjt_call13 = { -1 };

                            sjt_call13._refCount = 1;
                            sjt_call13.count = 0;
                            sjt_call13.data._refCount = 1;
                            sjt_call13.data.datasize = 0;
                            sjt_call13.data.data = (void*)sjg_string7;
                            sjt_call13.data.isglobal = true;
                            sjt_call13.data.count = 0;
                            sjf_array_char(&sjt_call13.data);
                            sjt_call13._isnullterminated = false;
                            sjf_string(&sjt_call13);
                            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
                            (*_return)->_refCount = 1;
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
            int32_t sjt_functionParam7;
            sjs_array_char* sjt_parent6 = 0;

            sjt_parent6 = &_parent->data;
            sjt_functionParam7 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent6, sjt_functionParam7, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart1 = 0;
        sjt_forEnd1 = item->count;
        i = sjt_forStart1;
        while (i < sjt_forEnd1) {
            int32_t sjt_functionParam11;
            int32_t sjt_functionParam8;
            char sjt_functionParam9;
            sjs_array_char* sjt_parent7 = 0;
            sjs_string* sjt_parent9 = 0;

            sjt_parent7 = &sjv_newdata;
            sjt_functionParam8 = sjv_newcount;
            sjt_parent9 = item;
            sjt_functionParam11 = i;
            sjf_string_getat(sjt_parent9, sjt_functionParam11, &sjt_functionParam9);
            sjf_array_char_initat(sjt_parent7, sjt_functionParam8, sjt_functionParam9);
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
            int32_t sjt_functionParam12;
            sjs_array_char* sjt_parent10 = 0;

            sjt_parent10 = &_parent->data;
            sjt_functionParam12 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent10, sjt_functionParam12, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart2 = 0;
        sjt_forEnd2 = item->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam13;
            char sjt_functionParam14;
            int32_t sjt_functionParam15;
            sjs_array_char* sjt_parent11 = 0;
            sjs_string* sjt_parent12 = 0;

            sjt_parent11 = &sjv_newdata;
            sjt_functionParam13 = sjv_newcount;
            sjt_parent12 = item;
            sjt_functionParam15 = i;
            sjf_string_getat(sjt_parent12, sjt_functionParam15, &sjt_functionParam14);
            sjf_array_char_initat(sjt_parent11, sjt_functionParam13, sjt_functionParam14);
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
    int32_t sjt_functionParam10;
    sjs_array_char* sjt_parent8 = 0;

    sjt_parent8 = &_parent->data;
    sjt_functionParam10 = index;
    sjf_array_char_getat(sjt_parent8, sjt_functionParam10, _return);
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_funcold1 = { -1 };

    result2 = !(&_parent->data)->isglobal;
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam4;
        char sjt_functionParam5;
        sjs_array_char* sjt_parent4 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam3;
            sjs_array_char* sjt_parent3 = 0;

            sjt_funcold1._refCount = 1;
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
            sjt_parent3 = &_parent->data;
            sjt_functionParam3 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent3, sjt_functionParam3, &sjt_funcold1);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
        }

        sjt_parent4 = &_parent->data;
        sjt_functionParam4 = _parent->count;
        sjt_functionParam5 = '\0';
        sjf_array_char_initat(sjt_parent4, sjt_functionParam4, sjt_functionParam5);
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return) {
    int32_t i;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;
    sjs_array_char sjv_a = { -1 };

    sjv_a._refCount = 1;
    sjv_a.datasize = (((_parent->count - 1) / 256) + 1) * 256;
    sjv_a.data = 0;
    sjv_a.isglobal = false;
    sjv_a.count = 0;
    sjf_array_char(&sjv_a);
    sjt_forStart3 = 0;
    sjt_forEnd3 = _parent->count;
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        int32_t sjt_functionParam16;
        char sjt_functionParam17;
        char sjt_functionParam18;
        int32_t sjt_functionParam19;
        sjs_array_char* sjt_parent17 = 0;
        sjs_array_char* sjt_parent18 = 0;

        sjt_parent17 = &sjv_a;
        sjt_functionParam16 = i;
        sjt_parent18 = &_parent->data;
        sjt_functionParam19 = i;
        sjf_array_char_getat(sjt_parent18, sjt_functionParam19, &sjt_functionParam18);
        sjf_char_touppercase(sjt_functionParam18, &sjt_functionParam17);
        sjf_array_char_initat(sjt_parent17, sjt_functionParam16, sjt_functionParam17);
        i++;
    }

    _return->_refCount = 1;
    _return->count = _parent->count;
    _return->data._refCount = 1;
    sjf_array_char_copy(&_return->data, &sjv_a);
    _return->_isnullterminated = false;
    sjf_string(_return);

    if (sjv_a._refCount == 1) { sjf_array_char_destroy(&sjv_a); }
;
}

void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return) {
    int32_t i;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    sjs_array_char sjv_a = { -1 };

    sjv_a._refCount = 1;
    sjv_a.datasize = (((_parent->count - 1) / 256) + 1) * 256;
    sjv_a.data = 0;
    sjv_a.isglobal = false;
    sjv_a.count = 0;
    sjf_array_char(&sjv_a);
    sjt_forStart4 = 0;
    sjt_forEnd4 = _parent->count;
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        int32_t sjt_functionParam20;
        char sjt_functionParam21;
        char sjt_functionParam22;
        int32_t sjt_functionParam23;
        sjs_array_char* sjt_parent19 = 0;
        sjs_array_char* sjt_parent20 = 0;

        sjt_parent19 = &sjv_a;
        sjt_functionParam20 = i;
        sjt_parent20 = &_parent->data;
        sjt_functionParam23 = i;
        sjf_array_char_getat(sjt_parent20, sjt_functionParam23, &sjt_functionParam22);
        sjf_char_touppercase(sjt_functionParam22, &sjt_functionParam21);
        sjf_array_char_initat(sjt_parent19, sjt_functionParam20, sjt_functionParam21);
        i++;
    }

    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = _parent->count;
    (*_return)->data._refCount = 1;
    sjf_array_char_copy(&(*_return)->data, &sjv_a);
    (*_return)->_isnullterminated = false;
    sjf_string_heap((*_return));

    if (sjv_a._refCount == 1) { sjf_array_char_destroy(&sjv_a); }
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
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 25:
        _return->_refCount = 1;
        _return->count = 14;
        _return->data._refCount = 1;
        _return->data.datasize = 14;
        _return->data.data = (void*)sjg_string14;
        _return->data.isglobal = true;
        _return->data.count = 14;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 9:
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 4;
        _return->data.data = (void*)sjg_string15;
        _return->data.isglobal = true;
        _return->data.count = 4;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 6:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string16;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 7:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string17;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 1:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string18;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 2:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string19;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 12:
        _return->_refCount = 1;
        _return->count = 8;
        _return->data._refCount = 1;
        _return->data.datasize = 8;
        _return->data.data = (void*)sjg_string20;
        _return->data.isglobal = true;
        _return->data.count = 8;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 5:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string21;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 13:
        _return->_refCount = 1;
        _return->count = 0;
        _return->data._refCount = 1;
        _return->data.datasize = 0;
        _return->data.data = (void*)sjg_string7;
        _return->data.isglobal = true;
        _return->data.count = 0;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 28:
        _return->_refCount = 1;
        _return->count = 10;
        _return->data._refCount = 1;
        _return->data.datasize = 10;
        _return->data.data = (void*)sjg_string22;
        _return->data.isglobal = true;
        _return->data.count = 10;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 33:
        _return->_refCount = 1;
        _return->count = 5;
        _return->data._refCount = 1;
        _return->data.datasize = 5;
        _return->data.data = (void*)sjg_string23;
        _return->data.isglobal = true;
        _return->data.count = 5;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 29:
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 4;
        _return->data.data = (void*)sjg_string24;
        _return->data.isglobal = true;
        _return->data.count = 4;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 30:
        _return->_refCount = 1;
        _return->count = 6;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string25;
        _return->data.isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 34:
        _return->_refCount = 1;
        _return->count = 16;
        _return->data._refCount = 1;
        _return->data.datasize = 16;
        _return->data.data = (void*)sjg_string26;
        _return->data.isglobal = true;
        _return->data.count = 16;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 21:
        _return->_refCount = 1;
        _return->count = 5;
        _return->data._refCount = 1;
        _return->data.datasize = 5;
        _return->data.data = (void*)sjg_string27;
        _return->data.isglobal = true;
        _return->data.count = 5;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 44:
        _return->_refCount = 1;
        _return->count = 8;
        _return->data._refCount = 1;
        _return->data.datasize = 8;
        _return->data.data = (void*)sjg_string28;
        _return->data.isglobal = true;
        _return->data.count = 8;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 26:
        _return->_refCount = 1;
        _return->count = 9;
        _return->data._refCount = 1;
        _return->data.datasize = 9;
        _return->data.data = (void*)sjg_string29;
        _return->data.isglobal = true;
        _return->data.count = 9;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 14:
        _return->_refCount = 1;
        _return->count = 6;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string30;
        _return->data.isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 15:
        _return->_refCount = 1;
        _return->count = 17;
        _return->data._refCount = 1;
        _return->data.datasize = 17;
        _return->data.data = (void*)sjg_string31;
        _return->data.isglobal = true;
        _return->data.count = 17;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 18:
        _return->_refCount = 1;
        _return->count = 17;
        _return->data._refCount = 1;
        _return->data.datasize = 17;
        _return->data.data = (void*)sjg_string32;
        _return->data.isglobal = true;
        _return->data.count = 17;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 19:
        _return->_refCount = 1;
        _return->count = 19;
        _return->data._refCount = 1;
        _return->data.datasize = 19;
        _return->data.data = (void*)sjg_string33;
        _return->data.isglobal = true;
        _return->data.count = 19;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 38:
        _return->_refCount = 1;
        _return->count = 5;
        _return->data._refCount = 1;
        _return->data.datasize = 5;
        _return->data.data = (void*)sjg_string23;
        _return->data.isglobal = true;
        _return->data.count = 5;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 45:
        _return->_refCount = 1;
        _return->count = 7;
        _return->data._refCount = 1;
        _return->data.datasize = 7;
        _return->data.data = (void*)sjg_string34;
        _return->data.isglobal = true;
        _return->data.count = 7;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 46:
        _return->_refCount = 1;
        _return->count = 6;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string35;
        _return->data.isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 39:
        _return->_refCount = 1;
        _return->count = 7;
        _return->data._refCount = 1;
        _return->data.datasize = 7;
        _return->data.data = (void*)sjg_string36;
        _return->data.isglobal = true;
        _return->data.count = 7;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 40:
        _return->_refCount = 1;
        _return->count = 6;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string35;
        _return->data.isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 42:
        _return->_refCount = 1;
        _return->count = 7;
        _return->data._refCount = 1;
        _return->data.datasize = 7;
        _return->data.data = (void*)sjg_string37;
        _return->data.isglobal = true;
        _return->data.count = 7;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 43:
        _return->_refCount = 1;
        _return->count = 6;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string35;
        _return->data.isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 20:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string38;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 23:
        _return->_refCount = 1;
        _return->count = 6;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string39;
        _return->data.isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 41:
        _return->_refCount = 1;
        _return->count = 5;
        _return->data._refCount = 1;
        _return->data.datasize = 5;
        _return->data.data = (void*)sjg_string5;
        _return->data.isglobal = true;
        _return->data.count = 5;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 22:
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 4;
        _return->data.data = (void*)sjg_string3;
        _return->data.isglobal = true;
        _return->data.count = 4;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 31:
        _return->_refCount = 1;
        _return->count = 17;
        _return->data._refCount = 1;
        _return->data.datasize = 17;
        _return->data.data = (void*)sjg_string40;
        _return->data.isglobal = true;
        _return->data.count = 17;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 24:
        _return->_refCount = 1;
        _return->count = 6;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string41;
        _return->data.isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 35:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string42;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 36:
        _return->_refCount = 1;
        _return->count = 5;
        _return->data._refCount = 1;
        _return->data.datasize = 5;
        _return->data.data = (void*)sjg_string23;
        _return->data.isglobal = true;
        _return->data.count = 5;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 27:
        _return->_refCount = 1;
        _return->count = 13;
        _return->data._refCount = 1;
        _return->data.datasize = 13;
        _return->data.data = (void*)sjg_string43;
        _return->data.isglobal = true;
        _return->data.count = 13;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 32:
        _return->_refCount = 1;
        _return->count = 11;
        _return->data._refCount = 1;
        _return->data.datasize = 11;
        _return->data.data = (void*)sjg_string44;
        _return->data.isglobal = true;
        _return->data.count = 11;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 37:
        _return->_refCount = 1;
        _return->count = 13;
        _return->data._refCount = 1;
        _return->data.datasize = 13;
        _return->data.data = (void*)sjg_string45;
        _return->data.isglobal = true;
        _return->data.count = 13;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 16:
        _return->_refCount = 1;
        _return->count = 9;
        _return->data._refCount = 1;
        _return->data.datasize = 9;
        _return->data.data = (void*)sjg_string46;
        _return->data.isglobal = true;
        _return->data.count = 9;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 17:
        _return->_refCount = 1;
        _return->count = 12;
        _return->data._refCount = 1;
        _return->data.datasize = 12;
        _return->data.data = (void*)sjg_string47;
        _return->data.isglobal = true;
        _return->data.count = 12;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 11:
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 4;
        _return->data.data = (void*)sjg_string48;
        _return->data.isglobal = true;
        _return->data.count = 4;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 3:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string49;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 4:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string50;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 10:
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 4;
        _return->data.data = (void*)sjg_string51;
        _return->data.isglobal = true;
        _return->data.count = 4;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        default:
        _return->_refCount = 1;
        _return->count = 0;
        _return->data._refCount = 1;
        _return->data.datasize = 0;
        _return->data.data = (void*)sjg_string7;
        _return->data.isglobal = true;
        _return->data.count = 0;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
    }
}

void sjf_type_asstring_heap(int32_t t, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = 0;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 0;
    (*_return)->data.data = (void*)sjg_string7;
    (*_return)->data.isglobal = true;
    (*_return)->data.count = 0;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
    sjf_string_heap((*_return));
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
    (&sjv_log)->minlevel = sjv_loglevel_info;
    sjv_c._refCount = 1;
    sjf_class(&sjv_c);
    sjt_parent32 = &sjv_c;
    sjf_class_dothing1(sjt_parent32);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
}
