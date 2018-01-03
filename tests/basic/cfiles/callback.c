#include <lib/common/common.h>

#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define cb_i32_data_heap_data_typeId 23
#define cb_i32_data_heap_data_heap_typeId 23
#define sjs_data_typeId 21
#define sjs_class_typeId 25

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_cb_i32_data_heap_data cb_i32_data_heap_data;
typedef struct td_cb_i32_data_heap_data_heap cb_i32_data_heap_data_heap;
typedef struct td_sjs_data sjs_data;
typedef struct td_sjs_class sjs_class;

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

struct td_cb_i32_data_heap_data {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, int32_t, sjs_data* _return);
    void (*_cb_heap)(sjs_object* _parent, int32_t, sjs_data** _return);
};

struct td_cb_i32_data_heap_data_heap {
    cb_i32_data_heap_data inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_data {
    int _refCount;
    int32_t x;
};

struct td_sjs_class {
    int _refCount;
    int32_t b;
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

cb_i32_data_heap_data g_a;
int32_t g_a2;
sjs_data* g_b = 0;
int32_t g_b2;
sjs_class g_c = { -1 };
sjs_class* g_c_heap = 0;
int32_t g_clocks_per_sec;
sjs_data g_d = { -1 };
sjs_data g_e = { -1 };
void* g_emptystringdata;
cb_i32_data_heap_data g_f1;
cb_i32_data_heap_data g_f2;
cb_i32_data_heap_data_heap g_f3;
float g_f32_pi;
sjs_data g_g = { -1 };
cb_i32_data_heap_data g_h;
cb_i32_data_heap_data g_i;
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
cb_i32_data_heap_data g_j;
sjs_data g_k = { -1 };
cb_i32_data_heap_data_heap g_l;
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
sjs_data g_m = { -1 };
sjs_data* g_n = 0;
cb_i32_data_heap_data g_o;
sjs_data g_p = { -1 };
uint32_t g_u32_maxvalue;
int32_t result1;
int32_t sjt_functionParam1;
int32_t sjt_functionParam10;
int32_t sjt_functionParam11;
int32_t sjt_functionParam2;
int32_t sjt_functionParam3;
cb_i32_data_heap_data sjt_functionParam5;
cb_i32_data_heap_data sjt_functionParam6;
int32_t sjt_functionParam7;
int32_t sjt_functionParam8;
int32_t sjt_functionParam9;
cb_i32_data_heap_data sjt_getValue1;
sjs_hash_type_bool sjt_value1 = { -1 };
cb_i32_data_heap_data sjt_value2;

void sjf_callback(cb_i32_data_heap_data f, int32_t* _return);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_func(sjs_class* _parent, int32_t a, sjs_data* _return);
void sjf_class_func_heap(sjs_class* _parent, int32_t a, sjs_data** _return);
void sjf_class_heap(sjs_class* _this);
void sjf_data(sjs_data* _this);
void sjf_data_copy(sjs_data* _this, sjs_data* _from);
void sjf_data_destroy(sjs_data* _this);
void sjf_data_heap(sjs_data* _this);
void sjf_func(int32_t a, sjs_data* _return);
void sjf_func2_data(int32_t a, sjs_data* _return);
void sjf_func2_data_callback(void * _parent, int32_t a, sjs_data* _return);
void sjf_func2_data_heap(int32_t a, sjs_data** _return);
void sjf_func2_data_heap_callback(void * _parent, int32_t a, sjs_data** _return);
void sjf_func_callback(void * _parent, int32_t a, sjs_data* _return);
void sjf_func_heap(int32_t a, sjs_data** _return);
void sjf_func_heap_callback(void * _parent, int32_t a, sjs_data** _return);
void sjf_getcallback_heap(cb_i32_data_heap_data_heap* _return);
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
void sjf_callback(cb_i32_data_heap_data f, int32_t* _return) {
    sjs_data d = { -1 };
    int32_t sjt_functionParam4;

#line 34 "callback.sj"
    sjt_functionParam4 = 12;
#line 34
    f._cb(f._parent, sjt_functionParam4, &d);
#line 33
    (*_return) = (&d)->x;

    if (d._refCount == 1) { sjf_data_destroy(&d); }
;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 6 "callback.sj"
    _this->b = _from->b;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_func(sjs_class* _parent, int32_t a, sjs_data* _return) {
    _return->_refCount = 1;
#line 9 "callback.sj"
    _return->x = a + _parent->b;
#line 9
    sjf_data(_return);
}

void sjf_class_func_heap(sjs_class* _parent, int32_t a, sjs_data** _return) {
    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
#line 9 "callback.sj"
    (*_return)->x = a + _parent->b;
#line 9
    sjf_data_heap((*_return));
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_data(sjs_data* _this) {
}

void sjf_data_copy(sjs_data* _this, sjs_data* _from) {
#line 2 "callback.sj"
    _this->x = _from->x;
}

void sjf_data_destroy(sjs_data* _this) {
}

void sjf_data_heap(sjs_data* _this) {
}

void sjf_func(int32_t a, sjs_data* _return) {
    _return->_refCount = 1;
#line 14 "callback.sj"
    _return->x = a + 2;
#line 14
    sjf_data(_return);
}

void sjf_func2_data(int32_t a, sjs_data* _return) {
    _return->_refCount = 1;
#line 18 "callback.sj"
    _return->x = a + 2;
#line 18
    sjf_data(_return);
}

void sjf_func2_data_callback(void * _parent, int32_t a, sjs_data* _return) {
    sjf_func2_data(a, _return);
}

void sjf_func2_data_heap(int32_t a, sjs_data** _return) {
    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
#line 18 "callback.sj"
    (*_return)->x = a + 2;
#line 18
    sjf_data_heap((*_return));
}

void sjf_func2_data_heap_callback(void * _parent, int32_t a, sjs_data** _return) {
    sjf_func2_data_heap(a, _return);
}

void sjf_func_callback(void * _parent, int32_t a, sjs_data* _return) {
    sjf_func(a, _return);
}

void sjf_func_heap(int32_t a, sjs_data** _return) {
    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
#line 14 "callback.sj"
    (*_return)->x = a + 2;
#line 14
    sjf_data_heap((*_return));
}

void sjf_func_heap_callback(void * _parent, int32_t a, sjs_data** _return) {
    sjf_func_heap(a, _return);
}

void sjf_getcallback_heap(cb_i32_data_heap_data_heap* _return) {
    sjs_class* c = 0;

    c = (sjs_class*)malloc(sizeof(sjs_class));
    c->_refCount = 1;
#line 7 "callback.sj"
    c->b = 15;
#line 7
    sjf_class_heap(c);
#line 30
    (*_return).inner._parent = (sjs_object*)c;
#line 30
    (*_return).inner._parent->_refCount++;
#line 30
    (*_return)._destroy = (void(*)(sjs_object*))sjf_class_destroy;
#line 30
    (*_return).inner._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
#line 30
    (*_return).inner._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;

    c->_refCount--;
    if (c->_refCount <= 0) {
        weakptr_release(c);
        sjf_class_destroy(c);
        free(c);
    }
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
        kh_destroy(type_bool_hash_type, _this->_hash);
#line 258
    }
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
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
#line 1 "lib/sj-lib-common/string.sj"
    g_emptystringdata = 0;
#line 3
    g_emptystringdata = "";
#line 2 "lib/sj-lib-common/weakptr.sj"
    ptr_init();
#line 3
    weakptr_init();
#line 7 "lib/sj-lib-common/clock.sj"
    g_clocks_per_sec = 0;
#line 9
    g_clocks_per_sec = CLOCKS_PER_SEC;
#line 38 "callback.sj"
    g_a._parent = (sjs_object*)1;
#line 38
    g_a._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
#line 38
    g_a._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
#line 39
    sjt_functionParam1 = 1;
#line 39
    g_a._cb_heap(g_a._parent, sjt_functionParam1, &g_b);
#line 39
    sjf_getcallback_heap(&g_l);
#line 41
    sjt_functionParam2 = 1;
#line 41
    g_l.inner._cb(g_l.inner._parent, sjt_functionParam2, &g_m);
#line 42
    sjt_functionParam3 = 1;
#line 42
    g_l.inner._cb_heap(g_l.inner._parent, sjt_functionParam3, &g_n);
#line 42
    g_c._refCount = 1;
#line 7
    g_c.b = 15;
#line 7
    sjf_class(&g_c);
#line 44
    sjt_functionParam5._parent = (sjs_object*)1;
#line 44
    sjt_functionParam5._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
#line 44
    sjt_functionParam5._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
#line 44
    sjf_callback(sjt_functionParam5, &g_a2);
#line 45
    sjt_functionParam6._parent = (sjs_object*)&g_c;
#line 45
    sjt_functionParam6._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
#line 45
    sjt_functionParam6._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;
#line 45
    sjf_callback(sjt_functionParam6, &g_b2);
#line 46
    g_f1._parent = (sjs_object*)1;
#line 46
    g_f1._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
#line 46
    g_f1._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
#line 47
    sjt_functionParam7 = 1;
#line 47
    g_f1._cb(g_f1._parent, sjt_functionParam7, &g_d);
#line 48
    g_f2._parent = (sjs_object*)&g_c;
#line 48
    g_f2._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
#line 48
    g_f2._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;
#line 49
    sjt_functionParam8 = 2;
#line 49
    g_f2._cb(g_f2._parent, sjt_functionParam8, &g_e);
#line 49
    g_c_heap = (sjs_class*)malloc(sizeof(sjs_class));
#line 49
    g_c_heap->_refCount = 1;
#line 7
    g_c_heap->b = 15;
#line 7
    sjf_class_heap(g_c_heap);
#line 51
    g_f3.inner._parent = (sjs_object*)g_c_heap;
#line 51
    g_f3.inner._parent->_refCount++;
#line 51
    g_f3._destroy = (void(*)(sjs_object*))sjf_class_destroy;
#line 51
    g_f3.inner._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
#line 51
    g_f3.inner._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;
#line 52
    sjt_functionParam9 = 3;
#line 52
    g_f3.inner._cb(g_f3.inner._parent, sjt_functionParam9, &g_g);
#line 53
    g_h._parent = 0;
#line 54
    sjt_value2._parent = (sjs_object*)1;
#line 54
    sjt_value2._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
#line 54
    sjt_value2._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
#line 54
    g_i = sjt_value2;
#line 55
    sjt_getValue1 = g_i;
#line 55
    if (sjt_getValue1._parent == 0) { exit(-1); }
#line 55
    g_j = sjt_getValue1;
#line 56
    sjt_functionParam10 = 12;
#line 56
    g_j._cb(g_j._parent, sjt_functionParam10, &g_k);
#line 57
    g_o._parent = (sjs_object*)1;
#line 57
    g_o._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func2_data_callback;
#line 57
    g_o._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func2_data_heap_callback;
#line 58
    sjt_functionParam11 = 1;
#line 58
    g_l.inner._cb(g_l.inner._parent, sjt_functionParam11, &g_p);
    main_destroy();
    return 0;
}

void main_destroy() {

    g_b->_refCount--;
    if (g_b->_refCount <= 0) {
        weakptr_release(g_b);
        sjf_data_destroy(g_b);
        free(g_b);
    }
    g_c_heap->_refCount--;
    if (g_c_heap->_refCount <= 0) {
        weakptr_release(g_c_heap);
        sjf_class_destroy(g_c_heap);
        free(g_c_heap);
    }
    if ((uintptr_t)g_f3.inner._parent > 1) {
        g_f3.inner._parent->_refCount--;
        if (g_f3.inner._parent->_refCount <= 0) {
            g_f3._destroy(g_f3.inner._parent);
            free(g_f3.inner._parent);
        }
    }
    if ((uintptr_t)g_l.inner._parent > 1) {
        g_l.inner._parent->_refCount--;
        if (g_l.inner._parent->_refCount <= 0) {
            g_l._destroy(g_l.inner._parent);
            free(g_l.inner._parent);
        }
    }
    g_n->_refCount--;
    if (g_n->_refCount <= 0) {
        weakptr_release(g_n);
        sjf_data_destroy(g_n);
        free(g_n);
    }
    if (g_c._refCount == 1) { sjf_class_destroy(&g_c); }
;
    if (g_d._refCount == 1) { sjf_data_destroy(&g_d); }
;
    if (g_e._refCount == 1) { sjf_data_destroy(&g_e); }
;
    if (g_g._refCount == 1) { sjf_data_destroy(&g_g); }
;
    if (g_k._refCount == 1) { sjf_data_destroy(&g_k); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (g_m._refCount == 1) { sjf_data_destroy(&g_m); }
;
    if (g_p._refCount == 1) { sjf_data_destroy(&g_p); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
