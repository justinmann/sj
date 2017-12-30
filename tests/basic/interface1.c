#include <lib/common/common.h>

#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_namespace1_class_typeId 22
#define sji_namespace1_foo_typeId 23
#define sjs_namespace2_class_typeId 25
#define sji_namespace2_foo_typeId 26

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_namespace1_class sjs_namespace1_class;
typedef struct td_sji_namespace1_foo_vtbl sji_namespace1_foo_vtbl;
typedef struct td_sji_namespace1_foo sji_namespace1_foo;
typedef struct td_sjs_namespace2_class sjs_namespace2_class;
typedef struct td_sji_namespace2_foo_vtbl sji_namespace2_foo_vtbl;
typedef struct td_sji_namespace2_foo sji_namespace2_foo;

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

struct td_sjs_namespace1_class {
    int _refCount;
};

struct td_sji_namespace1_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*test1)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_namespace1_foo {
    sjs_object* _parent;
    sji_namespace1_foo_vtbl* _vtbl;
};

struct td_sjs_namespace2_class {
    int _refCount;
};

struct td_sji_namespace2_foo_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*test2)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_namespace2_foo {
    sjs_object* _parent;
    sji_namespace2_foo_vtbl* _vtbl;
};

sji_namespace1_foo_vtbl sjs_namespace1_class_foo_vtbl;
sji_namespace2_foo_vtbl sjs_namespace2_class_foo_vtbl;
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
sjs_namespace1_class sjt_call1 = { -1 };
sjs_namespace2_class sjt_call2 = { -1 };
sjs_namespace1_class* sjt_cast2 = 0;
sjs_namespace2_class* sjt_cast3 = 0;
sji_namespace1_foo sjv_a = { 0 };
sji_namespace2_foo sjv_b = { 0 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
sjs_hash_type_bool sjv_log_excludeall = { -1 };
sjs_hash_type_bool sjv_log_includeall = { -1 };
uint32_t sjv_u32_maxvalue;

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
void sjf_namespace1_class(sjs_namespace1_class* _this);
void sjf_namespace1_class_as_sji_namespace1_foo(sjs_namespace1_class* _this, sji_namespace1_foo* _return);
void sjf_namespace1_class_asinterface(sjs_namespace1_class* _this, int typeId, sjs_interface* _return);
void sjf_namespace1_class_copy(sjs_namespace1_class* _this, sjs_namespace1_class* _from);
void sjf_namespace1_class_destroy(sjs_namespace1_class* _this);
void sjf_namespace1_class_getclasstype(sjs_object* _this, int* _return);
void sjf_namespace1_class_heap(sjs_namespace1_class* _this);
void sjf_namespace1_class_namespace1_test1(sjs_namespace1_class* _parent, int32_t* _return);
void sjf_namespace2_class(sjs_namespace2_class* _this);
void sjf_namespace2_class_as_sji_namespace2_foo(sjs_namespace2_class* _this, sji_namespace2_foo* _return);
void sjf_namespace2_class_asinterface(sjs_namespace2_class* _this, int typeId, sjs_interface* _return);
void sjf_namespace2_class_copy(sjs_namespace2_class* _this, sjs_namespace2_class* _from);
void sjf_namespace2_class_destroy(sjs_namespace2_class* _this);
void sjf_namespace2_class_getclasstype(sjs_object* _this, int* _return);
void sjf_namespace2_class_heap(sjs_namespace2_class* _this);
void sjf_namespace2_class_namespace2_test2(sjs_namespace2_class* _parent, int32_t* _return);
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

void sjf_namespace1_class(sjs_namespace1_class* _this) {
}

void sjf_namespace1_class_as_sji_namespace1_foo(sjs_namespace1_class* _this, sji_namespace1_foo* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_namespace1_class_foo_vtbl;
}

void sjf_namespace1_class_asinterface(sjs_namespace1_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_namespace1_foo_typeId:  {
            sjf_namespace1_class_as_sji_namespace1_foo(_this, (sji_namespace1_foo*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_namespace1_class_copy(sjs_namespace1_class* _this, sjs_namespace1_class* _from) {
}

void sjf_namespace1_class_destroy(sjs_namespace1_class* _this) {
}

void sjf_namespace1_class_getclasstype(sjs_object* _this, int* _return) {
    *_return = 22;
}

void sjf_namespace1_class_heap(sjs_namespace1_class* _this) {
}

void sjf_namespace1_class_namespace1_test1(sjs_namespace1_class* _parent, int32_t* _return) {
    (*_return) = 5;
}

void sjf_namespace2_class(sjs_namespace2_class* _this) {
}

void sjf_namespace2_class_as_sji_namespace2_foo(sjs_namespace2_class* _this, sji_namespace2_foo* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_namespace2_class_foo_vtbl;
}

void sjf_namespace2_class_asinterface(sjs_namespace2_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_namespace2_foo_typeId:  {
            sjf_namespace2_class_as_sji_namespace2_foo(_this, (sji_namespace2_foo*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_namespace2_class_copy(sjs_namespace2_class* _this, sjs_namespace2_class* _from) {
}

void sjf_namespace2_class_destroy(sjs_namespace2_class* _this) {
}

void sjf_namespace2_class_getclasstype(sjs_object* _this, int* _return) {
    *_return = 25;
}

void sjf_namespace2_class_heap(sjs_namespace2_class* _this) {
}

void sjf_namespace2_class_namespace2_test2(sjs_namespace2_class* _parent, int32_t* _return) {
    (*_return) = 5;
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
    sjs_namespace1_class_foo_vtbl.destroy = (void(*)(void*))sjf_namespace1_class_destroy;
    sjs_namespace1_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_namespace1_class_asinterface;
    sjs_namespace1_class_foo_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_namespace1_class_getclasstype;
    sjs_namespace1_class_foo_vtbl.test1 = (void(*)(sjs_object*, int32_t*))sjf_namespace1_class_namespace1_test1;
    sjs_namespace2_class_foo_vtbl.destroy = (void(*)(void*))sjf_namespace2_class_destroy;
    sjs_namespace2_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_namespace2_class_asinterface;
    sjs_namespace2_class_foo_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_namespace2_class_getclasstype;
    sjs_namespace2_class_foo_vtbl.test2 = (void(*)(sjs_object*, int32_t*))sjf_namespace2_class_namespace2_test2;
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
    sjt_call1._refCount = 1;
    sjf_namespace1_class(&sjt_call1);
    sjt_cast2 = &sjt_call1;
    sjf_namespace1_class_as_sji_namespace1_foo(sjt_cast2, &sjv_a);
    sjt_call2._refCount = 1;
    sjf_namespace2_class(&sjt_call2);
    sjt_cast3 = &sjt_call2;
    sjf_namespace2_class_as_sji_namespace2_foo(sjt_cast3, &sjv_b);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_namespace1_class_destroy(&sjt_call1); }
;
    if (sjt_call2._refCount == 1) { sjf_namespace2_class_destroy(&sjt_call2); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
}
