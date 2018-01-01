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
sjs_hash_type_bool sjt_value1 = { -1 };
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

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_log(sjs_log* _this) {
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
#line 8 "interface1.sj"
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
#line 18 "interface1.sj"
    (*_return) = 5;
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
    sjs_namespace1_class_foo_vtbl.destroy = (void(*)(void*))sjf_namespace1_class_destroy;
    sjs_namespace1_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_namespace1_class_asinterface;
    sjs_namespace1_class_foo_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_namespace1_class_getclasstype;
    sjs_namespace1_class_foo_vtbl.test1 = (void(*)(sjs_object*, int32_t*))sjf_namespace1_class_namespace1_test1;
    sjs_namespace2_class_foo_vtbl.destroy = (void(*)(void*))sjf_namespace2_class_destroy;
    sjs_namespace2_class_foo_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_namespace2_class_asinterface;
    sjs_namespace2_class_foo_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_namespace2_class_getclasstype;
    sjs_namespace2_class_foo_vtbl.test2 = (void(*)(sjs_object*, int32_t*))sjf_namespace2_class_namespace2_test2;
#line 1 "lib/common/log.sj"
    sjv_loglevel_trace = 0;
#line 1
    sjv_loglevel_debug = 1;
#line 1
    sjv_loglevel_info = 2;
#line 1
    sjv_loglevel_warn = 3;
#line 1
    sjv_loglevel_error = 4;
#line 1
    sjv_loglevel_fatal = 5;
#line 1 "lib/common/f32.sj"
    sjv_f32_pi = 3.14159265358979323846f;
#line 1 "lib/common/i32.sj"
    sjv_u32_maxvalue = (uint32_t)4294967295u;
#line 3
    result1 = -1;
#line 3
    sjv_i32_maxvalue = result1 - 2147483647;
#line 4
    sjv_i32_minvalue = 2147483647;
#line 10 "lib/common/log.sj"
    sjv_log_includeall._refCount = -1;
#line 10
    sjt_value1._refCount = 1;
#line 10
    sjf_hash_type_bool(&sjt_value1);
#line 11
    sjs_hash_type_bool* copyoption1 = &sjt_value1;
    if (copyoption1 != 0) {
        sjv_log_excludeall._refCount = 1;
#line 11 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log_excludeall, copyoption1);
    } else {
        sjv_log_excludeall._refCount = -1;
    }

#line 11
    sjv_log._refCount = 1;
#line 13
    sjv_log.minlevel = sjv_loglevel_warn;
#line 13
    sjs_hash_type_bool* copyoption8 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption8 != 0) {
        sjv_log.traceincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.traceincludes, copyoption8);
    } else {
        sjv_log.traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption9 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption9 != 0) {
        sjv_log.debugincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.debugincludes, copyoption9);
    } else {
        sjv_log.debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption10 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption10 != 0) {
        sjv_log.infoincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.infoincludes, copyoption10);
    } else {
        sjv_log.infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption11 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption11 != 0) {
        sjv_log.warnincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.warnincludes, copyoption11);
    } else {
        sjv_log.warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption12 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption12 != 0) {
        sjv_log.errorincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.errorincludes, copyoption12);
    } else {
        sjv_log.errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption13 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption13 != 0) {
        sjv_log.fatalincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.fatalincludes, copyoption13);
    } else {
        sjv_log.fatalincludes._refCount = -1;
    }

#line 13
    sjf_log(&sjv_log);
#line 1 "lib/common/string.sj"
    sjv_emptystringdata = 0;
#line 3
    sjv_emptystringdata = "";
#line 2 "lib/common/weakptr.sj"
    ptr_init();
#line 3
    weakptr_init();
#line 7 "lib/common/clock.sj"
    sjv_clocks_per_sec = 0;
#line 9
    sjv_clocks_per_sec = CLOCKS_PER_SEC;
#line 9
    sjt_call1._refCount = 1;
#line 9
    sjf_namespace1_class(&sjt_call1);
#line 22 "interface1.sj"
    sjt_cast2 = &sjt_call1;
#line 3
    sjf_namespace1_class_as_sji_namespace1_foo(sjt_cast2, &sjv_a);
#line 3
    sjt_call2._refCount = 1;
#line 3
    sjf_namespace2_class(&sjt_call2);
#line 23
    sjt_cast3 = &sjt_call2;
#line 13
    sjf_namespace2_class_as_sji_namespace2_foo(sjt_cast3, &sjv_b);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_namespace1_class_destroy(&sjt_call1); }
;
    if (sjt_call2._refCount == 1) { sjf_namespace2_class_destroy(&sjt_call2); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
}