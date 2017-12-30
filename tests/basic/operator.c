#include <lib/common/common.h>

#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_fancymath_typeId 21

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_fancymath sjs_fancymath;

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

struct td_sjs_fancymath {
    int _refCount;
    int32_t x;
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
sjs_fancymath sjt_funcold1 = { -1 };
sjs_fancymath sjt_funcold2 = { -1 };
sjs_fancymath sjt_funcold3 = { -1 };
sjs_fancymath sjt_funcold4 = { -1 };
sjs_fancymath sjt_funcold5 = { -1 };
sjs_fancymath sjt_funcold6 = { -1 };
sjs_fancymath* sjt_functionParam1 = 0;
int32_t sjt_functionParam10;
int32_t sjt_functionParam11;
sjs_fancymath* sjt_functionParam2 = 0;
sjs_fancymath* sjt_functionParam3 = 0;
sjs_fancymath* sjt_functionParam4 = 0;
sjs_fancymath* sjt_functionParam5 = 0;
sjs_fancymath* sjt_functionParam6 = 0;
sjs_fancymath* sjt_functionParam7 = 0;
sjs_fancymath* sjt_functionParam8 = 0;
sjs_fancymath* sjt_functionParam9 = 0;
sjs_fancymath* sjt_parent12 = 0;
sjs_fancymath* sjt_parent15 = 0;
sjs_fancymath* sjt_parent16 = 0;
sjs_fancymath* sjt_parent17 = 0;
sjs_fancymath* sjt_parent18 = 0;
sjs_fancymath* sjt_parent19 = 0;
sjs_fancymath* sjt_parent20 = 0;
sjs_fancymath* sjt_parent21 = 0;
sjs_fancymath* sjt_parent22 = 0;
sjs_fancymath* sjt_parent23 = 0;
sjs_fancymath* sjt_parent24 = 0;
sjs_fancymath* sjt_parent3 = 0;
sjs_fancymath* sjt_parent6 = 0;
sjs_fancymath* sjt_parent9 = 0;
sjs_fancymath sjv_a = { -1 };
sjs_fancymath sjv_b = { -1 };
sjs_fancymath sjv_c = { -1 };
int32_t sjv_clocks_per_sec;
sjs_fancymath sjv_d = { -1 };
sjs_fancymath sjv_e = { -1 };
void* sjv_emptystringdata;
sjs_fancymath sjv_f = { -1 };
float sjv_f32_pi;
sjs_fancymath sjv_g = { -1 };
int32_t sjv_i;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
int32_t sjv_ii;
int32_t sjv_j;
sjs_fancymath sjv_k = { -1 };
sjs_log sjv_log = { -1 };
sjs_hash_type_bool sjv_log_excludeall = { -1 };
sjs_hash_type_bool sjv_log_includeall = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_fancymath(sjs_fancymath* _this);
void sjf_fancymath_add(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_add_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_copy(sjs_fancymath* _this, sjs_fancymath* _from);
void sjf_fancymath_destroy(sjs_fancymath* _this);
void sjf_fancymath_divide(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_divide_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_dividei32(sjs_fancymath* _parent, int32_t num, sjs_fancymath* _return);
void sjf_fancymath_dividei32_heap(sjs_fancymath* _parent, int32_t num, sjs_fancymath** _return);
void sjf_fancymath_getx(sjs_fancymath* _parent, int32_t* _return);
void sjf_fancymath_heap(sjs_fancymath* _this);
void sjf_fancymath_increment(sjs_fancymath* _parent, sjs_fancymath* _return);
void sjf_fancymath_increment_heap(sjs_fancymath* _parent, sjs_fancymath** _return);
void sjf_fancymath_modulus(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_modulus_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_multiply(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_multiply_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_setbob(sjs_fancymath* _parent, int32_t i, int32_t* _return);
void sjf_fancymath_subtract(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_subtract_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
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
void sjf_fancymath(sjs_fancymath* _this) {
}

void sjf_fancymath_add(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    int32_t sjt_capture1;
    sjs_fancymath* sjt_parent1 = 0;

    _return->_refCount = 1;
    sjt_parent1 = num;
    sjf_fancymath_getx(sjt_parent1, &sjt_capture1);
    _return->x = (_parent->x + sjt_capture1) + 1;
    sjf_fancymath(_return);
}

void sjf_fancymath_add_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    int32_t sjt_capture2;
    sjs_fancymath* sjt_parent2 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_parent2 = num;
    sjf_fancymath_getx(sjt_parent2, &sjt_capture2);
    (*_return)->x = (_parent->x + sjt_capture2) + 1;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_copy(sjs_fancymath* _this, sjs_fancymath* _from) {
    _this->x = _from->x;
}

void sjf_fancymath_destroy(sjs_fancymath* _this) {
}

void sjf_fancymath_divide(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    int32_t sjt_capture7;
    sjs_fancymath* sjt_parent10 = 0;

    _return->_refCount = 1;
    sjt_parent10 = num;
    sjf_fancymath_getx(sjt_parent10, &sjt_capture7);
    _return->x = (_parent->x / sjt_capture7) + 1;
    sjf_fancymath(_return);
}

void sjf_fancymath_divide_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    int32_t sjt_capture8;
    sjs_fancymath* sjt_parent11 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_parent11 = num;
    sjf_fancymath_getx(sjt_parent11, &sjt_capture8);
    (*_return)->x = (_parent->x / sjt_capture8) + 1;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_dividei32(sjs_fancymath* _parent, int32_t num, sjs_fancymath* _return) {
    _return->_refCount = 1;
    _return->x = (_parent->x / num) + 1;
    sjf_fancymath(_return);
}

void sjf_fancymath_dividei32_heap(sjs_fancymath* _parent, int32_t num, sjs_fancymath** _return) {
    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    (*_return)->x = (_parent->x / num) + 1;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_getx(sjs_fancymath* _parent, int32_t* _return) {
    (*_return) = _parent->x;
}

void sjf_fancymath_heap(sjs_fancymath* _this) {
}

void sjf_fancymath_increment(sjs_fancymath* _parent, sjs_fancymath* _return) {
    _return->_refCount = 1;
    _return->x = _parent->x + 1;
    sjf_fancymath(_return);
}

void sjf_fancymath_increment_heap(sjs_fancymath* _parent, sjs_fancymath** _return) {
    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    (*_return)->x = _parent->x + 1;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_modulus(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    int32_t sjt_capture9;
    sjs_fancymath* sjt_parent13 = 0;

    _return->_refCount = 1;
    sjt_parent13 = num;
    sjf_fancymath_getx(sjt_parent13, &sjt_capture9);
    _return->x = (_parent->x % sjt_capture9) + 1;
    sjf_fancymath(_return);
}

void sjf_fancymath_modulus_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    int32_t sjt_capture10;
    sjs_fancymath* sjt_parent14 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_parent14 = num;
    sjf_fancymath_getx(sjt_parent14, &sjt_capture10);
    (*_return)->x = (_parent->x % sjt_capture10) + 1;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_multiply(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    int32_t sjt_capture5;
    sjs_fancymath* sjt_parent7 = 0;

    _return->_refCount = 1;
    sjt_parent7 = num;
    sjf_fancymath_getx(sjt_parent7, &sjt_capture5);
    _return->x = (_parent->x * sjt_capture5) + 1;
    sjf_fancymath(_return);
}

void sjf_fancymath_multiply_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    int32_t sjt_capture6;
    sjs_fancymath* sjt_parent8 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_parent8 = num;
    sjf_fancymath_getx(sjt_parent8, &sjt_capture6);
    (*_return)->x = (_parent->x * sjt_capture6) + 1;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_setbob(sjs_fancymath* _parent, int32_t i, int32_t* _return) {
    _parent->x = i;
    (*_return) = _parent->x;
}

void sjf_fancymath_subtract(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    int32_t sjt_capture3;
    sjs_fancymath* sjt_parent4 = 0;

    _return->_refCount = 1;
    sjt_parent4 = num;
    sjf_fancymath_getx(sjt_parent4, &sjt_capture3);
    _return->x = (_parent->x - sjt_capture3) + 1;
    sjf_fancymath(_return);
}

void sjf_fancymath_subtract_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    int32_t sjt_capture4;
    sjs_fancymath* sjt_parent5 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_parent5 = num;
    sjf_fancymath_getx(sjt_parent5, &sjt_capture4);
    (*_return)->x = (_parent->x - sjt_capture4) + 1;
    sjf_fancymath_heap((*_return));
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
    sjv_a._refCount = 1;
    sjv_a.x = 1;
    sjf_fancymath(&sjv_a);
    sjv_b._refCount = 1;
    sjv_b.x = 2;
    sjf_fancymath(&sjv_b);
    sjv_ii = 2;
    sjt_parent3 = &sjv_a;
    sjt_functionParam1 = &sjv_b;
    sjf_fancymath_add(sjt_parent3, sjt_functionParam1, &sjv_c);
    sjt_parent6 = &sjv_a;
    sjt_functionParam2 = &sjv_b;
    sjf_fancymath_subtract(sjt_parent6, sjt_functionParam2, &sjv_d);
    sjt_parent9 = &sjv_a;
    sjt_functionParam3 = &sjv_b;
    sjf_fancymath_multiply(sjt_parent9, sjt_functionParam3, &sjv_e);
    sjt_parent12 = &sjv_a;
    sjt_functionParam4 = &sjv_b;
    sjf_fancymath_divide(sjt_parent12, sjt_functionParam4, &sjv_f);
    sjt_parent15 = &sjv_a;
    sjt_functionParam5 = &sjv_b;
    sjf_fancymath_modulus(sjt_parent15, sjt_functionParam5, &sjv_g);
    sjt_funcold1._refCount = 1;
    sjf_fancymath_copy(&sjt_funcold1, &sjv_c);
    sjt_parent16 = &sjv_c;
    sjt_functionParam6 = &sjv_c;
    sjf_fancymath_add(sjt_parent16, sjt_functionParam6, &sjt_funcold1);
    if (sjv_c._refCount == 1) { sjf_fancymath_destroy(&sjv_c); }
;
    sjf_fancymath_copy(&sjv_c, &sjt_funcold1);
    sjt_funcold2._refCount = 1;
    sjf_fancymath_copy(&sjt_funcold2, &sjv_d);
    sjt_parent17 = &sjv_d;
    sjt_functionParam7 = &sjv_d;
    sjf_fancymath_subtract(sjt_parent17, sjt_functionParam7, &sjt_funcold2);
    if (sjv_d._refCount == 1) { sjf_fancymath_destroy(&sjv_d); }
;
    sjf_fancymath_copy(&sjv_d, &sjt_funcold2);
    sjt_funcold3._refCount = 1;
    sjf_fancymath_copy(&sjt_funcold3, &sjv_d);
    sjt_parent18 = &sjv_d;
    sjt_functionParam8 = &sjv_d;
    sjf_fancymath_multiply(sjt_parent18, sjt_functionParam8, &sjt_funcold3);
    if (sjv_d._refCount == 1) { sjf_fancymath_destroy(&sjv_d); }
;
    sjf_fancymath_copy(&sjv_d, &sjt_funcold3);
    sjt_funcold4._refCount = 1;
    sjf_fancymath_copy(&sjt_funcold4, &sjv_d);
    sjt_parent19 = &sjv_d;
    sjt_functionParam9 = &sjv_d;
    sjf_fancymath_divide(sjt_parent19, sjt_functionParam9, &sjt_funcold4);
    if (sjv_d._refCount == 1) { sjf_fancymath_destroy(&sjv_d); }
;
    sjf_fancymath_copy(&sjv_d, &sjt_funcold4);
    sjt_funcold5._refCount = 1;
    sjf_fancymath_copy(&sjt_funcold5, &sjv_e);
    sjt_parent20 = &sjv_e;
    sjf_fancymath_increment(sjt_parent20, &sjt_funcold5);
    if (sjv_e._refCount == 1) { sjf_fancymath_destroy(&sjv_e); }
;
    sjf_fancymath_copy(&sjv_e, &sjt_funcold5);
    sjt_funcold6._refCount = 1;
    sjf_fancymath_copy(&sjt_funcold6, &sjv_f);
    sjt_parent21 = &sjv_f;
    sjf_fancymath_increment(sjt_parent21, &sjt_funcold6);
    if (sjv_f._refCount == 1) { sjf_fancymath_destroy(&sjv_f); }
;
    sjf_fancymath_copy(&sjv_f, &sjt_funcold6);
    sjt_parent22 = &sjv_f;
    sjf_fancymath_getx(sjt_parent22, &sjv_i);
    sjt_parent23 = &sjv_a;
    sjt_functionParam10 = 12;
    sjf_fancymath_setbob(sjt_parent23, sjt_functionParam10, &sjv_j);
    sjt_parent24 = &sjv_a;
    sjt_functionParam11 = sjv_ii;
    sjf_fancymath_dividei32(sjt_parent24, sjt_functionParam11, &sjv_k);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_funcold1._refCount == 1) { sjf_fancymath_destroy(&sjt_funcold1); }
;
    if (sjt_funcold2._refCount == 1) { sjf_fancymath_destroy(&sjt_funcold2); }
;
    if (sjt_funcold3._refCount == 1) { sjf_fancymath_destroy(&sjt_funcold3); }
;
    if (sjt_funcold4._refCount == 1) { sjf_fancymath_destroy(&sjt_funcold4); }
;
    if (sjt_funcold5._refCount == 1) { sjf_fancymath_destroy(&sjt_funcold5); }
;
    if (sjt_funcold6._refCount == 1) { sjf_fancymath_destroy(&sjt_funcold6); }
;
    if (sjv_a._refCount == 1) { sjf_fancymath_destroy(&sjv_a); }
;
    if (sjv_b._refCount == 1) { sjf_fancymath_destroy(&sjv_b); }
;
    if (sjv_c._refCount == 1) { sjf_fancymath_destroy(&sjv_c); }
;
    if (sjv_d._refCount == 1) { sjf_fancymath_destroy(&sjv_d); }
;
    if (sjv_e._refCount == 1) { sjf_fancymath_destroy(&sjv_e); }
;
    if (sjv_f._refCount == 1) { sjf_fancymath_destroy(&sjv_f); }
;
    if (sjv_g._refCount == 1) { sjf_fancymath_destroy(&sjv_g); }
;
    if (sjv_k._refCount == 1) { sjf_fancymath_destroy(&sjv_k); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
}
