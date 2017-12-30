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
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

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
cb_i32_data_heap_data sjt_value1;
cb_i32_data_heap_data sjv_a;
int32_t sjv_a2;
sjs_data* sjv_b = 0;
int32_t sjv_b2;
sjs_class sjv_c = { -1 };
sjs_class* sjv_c_heap = 0;
int32_t sjv_clocks_per_sec;
sjs_data sjv_d = { -1 };
sjs_data sjv_e = { -1 };
void* sjv_emptystringdata;
cb_i32_data_heap_data sjv_f1;
cb_i32_data_heap_data sjv_f2;
cb_i32_data_heap_data_heap sjv_f3;
float sjv_f32_pi;
sjs_data sjv_g = { -1 };
cb_i32_data_heap_data sjv_h;
cb_i32_data_heap_data sjv_i;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
cb_i32_data_heap_data sjv_j;
sjs_data sjv_k = { -1 };
cb_i32_data_heap_data_heap sjv_l;
sjs_log sjv_log = { -1 };
sjs_hash_type_bool sjv_log_excludeall = { -1 };
sjs_hash_type_bool sjv_log_includeall = { -1 };
sjs_data sjv_m = { -1 };
sjs_data* sjv_n = 0;
cb_i32_data_heap_data sjv_o;
sjs_data sjv_p = { -1 };
uint32_t sjv_u32_maxvalue;

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
    int32_t sjt_functionParam4;
    sjs_data sjv_d = { -1 };

    sjt_functionParam4 = 12;
    f._cb(f._parent, sjt_functionParam4, &sjv_d);
    (*_return) = (&sjv_d)->x;

    if (sjv_d._refCount == 1) { sjf_data_destroy(&sjv_d); }
;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->b = _from->b;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_func(sjs_class* _parent, int32_t a, sjs_data* _return) {
    _return->_refCount = 1;
    _return->x = a + _parent->b;
    sjf_data(_return);
}

void sjf_class_func_heap(sjs_class* _parent, int32_t a, sjs_data** _return) {
    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
    (*_return)->x = a + _parent->b;
    sjf_data_heap((*_return));
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_data(sjs_data* _this) {
}

void sjf_data_copy(sjs_data* _this, sjs_data* _from) {
    _this->x = _from->x;
}

void sjf_data_destroy(sjs_data* _this) {
}

void sjf_data_heap(sjs_data* _this) {
}

void sjf_func(int32_t a, sjs_data* _return) {
    _return->_refCount = 1;
    _return->x = a + 2;
    sjf_data(_return);
}

void sjf_func2_data(int32_t a, sjs_data* _return) {
    _return->_refCount = 1;
    _return->x = a + 2;
    sjf_data(_return);
}

void sjf_func2_data_callback(void * _parent, int32_t a, sjs_data* _return) {
    sjf_func2_data(a, _return);
}

void sjf_func2_data_heap(int32_t a, sjs_data** _return) {
    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
    (*_return)->x = a + 2;
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
    (*_return)->x = a + 2;
    sjf_data_heap((*_return));
}

void sjf_func_heap_callback(void * _parent, int32_t a, sjs_data** _return) {
    sjf_func_heap(a, _return);
}

void sjf_getcallback_heap(cb_i32_data_heap_data_heap* _return) {
    sjs_class* sjv_c = 0;

    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->b = 15;
    sjf_class_heap(sjv_c);
    (*_return).inner._parent = (sjs_object*)sjv_c;
    (*_return).inner._parent->_refCount++;
    (*_return)._destroy = (void(*)(sjs_object*))sjf_class_destroy;
    (*_return).inner._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
    (*_return).inner._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }
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
    sjv_a._parent = (sjs_object*)1;
    sjv_a._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
    sjv_a._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjt_functionParam1 = 1;
    sjv_a._cb_heap(sjv_a._parent, sjt_functionParam1, &sjv_b);
    sjf_getcallback_heap(&sjv_l);
    sjt_functionParam2 = 1;
    sjv_l.inner._cb(sjv_l.inner._parent, sjt_functionParam2, &sjv_m);
    sjt_functionParam3 = 1;
    sjv_l.inner._cb_heap(sjv_l.inner._parent, sjt_functionParam3, &sjv_n);
    sjv_c._refCount = 1;
    sjv_c.b = 15;
    sjf_class(&sjv_c);
    sjt_functionParam5._parent = (sjs_object*)1;
    sjt_functionParam5._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
    sjt_functionParam5._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjf_callback(sjt_functionParam5, &sjv_a2);
    sjt_functionParam6._parent = (sjs_object*)&sjv_c;
    sjt_functionParam6._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
    sjt_functionParam6._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;
    sjf_callback(sjt_functionParam6, &sjv_b2);
    sjv_f1._parent = (sjs_object*)1;
    sjv_f1._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
    sjv_f1._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjt_functionParam7 = 1;
    sjv_f1._cb(sjv_f1._parent, sjt_functionParam7, &sjv_d);
    sjv_f2._parent = (sjs_object*)&sjv_c;
    sjv_f2._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
    sjv_f2._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;
    sjt_functionParam8 = 2;
    sjv_f2._cb(sjv_f2._parent, sjt_functionParam8, &sjv_e);
    sjv_c_heap = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c_heap->_refCount = 1;
    sjv_c_heap->b = 15;
    sjf_class_heap(sjv_c_heap);
    sjv_f3.inner._parent = (sjs_object*)sjv_c_heap;
    sjv_f3.inner._parent->_refCount++;
    sjv_f3._destroy = (void(*)(sjs_object*))sjf_class_destroy;
    sjv_f3.inner._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_class_func;
    sjv_f3.inner._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_class_func_heap;
    sjt_functionParam9 = 3;
    sjv_f3.inner._cb(sjv_f3.inner._parent, sjt_functionParam9, &sjv_g);
    sjv_h._parent = 0;
    sjt_value1._parent = (sjs_object*)1;
    sjt_value1._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func_callback;
    sjt_value1._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjv_i = sjt_value1;
    sjt_getValue1 = sjv_i;
    if (sjt_getValue1._parent == 0) { exit(-1); }
    sjv_j = sjt_getValue1;
    sjt_functionParam10 = 12;
    sjv_j._cb(sjv_j._parent, sjt_functionParam10, &sjv_k);
    sjv_o._parent = (sjs_object*)1;
    sjv_o._cb = (void(*)(sjs_object*,int32_t, sjs_data*))sjf_func2_data_callback;
    sjv_o._cb_heap = (void(*)(sjs_object*,int32_t, sjs_data**))sjf_func2_data_heap_callback;
    sjt_functionParam11 = 1;
    sjv_l.inner._cb(sjv_l.inner._parent, sjt_functionParam11, &sjv_p);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjv_b->_refCount--;
    if (sjv_b->_refCount <= 0) {
        weakptr_release(sjv_b);
        sjf_data_destroy(sjv_b);
        free(sjv_b);
    }
    sjv_c_heap->_refCount--;
    if (sjv_c_heap->_refCount <= 0) {
        weakptr_release(sjv_c_heap);
        sjf_class_destroy(sjv_c_heap);
        free(sjv_c_heap);
    }
    if ((uintptr_t)sjv_f3.inner._parent > 1) {
        sjv_f3.inner._parent->_refCount--;
        if (sjv_f3.inner._parent->_refCount <= 0) {
            sjv_f3._destroy(sjv_f3.inner._parent);
            free(sjv_f3.inner._parent);
        }
    }
    if ((uintptr_t)sjv_l.inner._parent > 1) {
        sjv_l.inner._parent->_refCount--;
        if (sjv_l.inner._parent->_refCount <= 0) {
            sjv_l._destroy(sjv_l.inner._parent);
            free(sjv_l.inner._parent);
        }
    }
    sjv_n->_refCount--;
    if (sjv_n->_refCount <= 0) {
        weakptr_release(sjv_n);
        sjf_data_destroy(sjv_n);
        free(sjv_n);
    }
    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
;
    if (sjv_d._refCount == 1) { sjf_data_destroy(&sjv_d); }
;
    if (sjv_e._refCount == 1) { sjf_data_destroy(&sjv_e); }
;
    if (sjv_g._refCount == 1) { sjf_data_destroy(&sjv_g); }
;
    if (sjv_k._refCount == 1) { sjf_data_destroy(&sjv_k); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
    if (sjv_m._refCount == 1) { sjf_data_destroy(&sjv_m); }
;
    if (sjv_p._refCount == 1) { sjf_data_destroy(&sjv_p); }
;
}
