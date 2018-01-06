#include <lib/sj-lib-common/common.h>

#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_array_i32_typeId 21
#define sjs_array_f32_typeId 23
#define cb_i32_f32_typeId 25
#define cb_i32_f32_heap_typeId 25
#define cb_f32_bool_typeId 29
#define cb_f32_bool_heap_typeId 29
#define sjs_sum_typeId 32
#define cb_sum_f32_sum_typeId 34
#define cb_sum_f32_sum_heap_typeId 34
#define cb_sum_f32_sum_heap_sum_typeId 36
#define cb_sum_f32_sum_heap_sum_heap_typeId 36

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sjs_array_f32 sjs_array_f32;
typedef struct td_cb_i32_f32 cb_i32_f32;
typedef struct td_cb_i32_f32_heap cb_i32_f32_heap;
typedef struct td_cb_f32_bool cb_f32_bool;
typedef struct td_cb_f32_bool_heap cb_f32_bool_heap;
typedef struct td_sjs_sum sjs_sum;
typedef struct td_cb_sum_f32_sum cb_sum_f32_sum;
typedef struct td_cb_sum_f32_sum_heap cb_sum_f32_sum_heap;
typedef struct td_cb_sum_f32_sum_heap_sum cb_sum_f32_sum_heap_sum;
typedef struct td_cb_sum_f32_sum_heap_sum_heap cb_sum_f32_sum_heap_sum_heap;

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

struct td_sjs_array_i32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_array_f32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_cb_i32_f32 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, int32_t, float* _return);
};

struct td_cb_i32_f32_heap {
    cb_i32_f32 inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_f32_bool {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, float, bool* _return);
};

struct td_cb_f32_bool_heap {
    cb_f32_bool inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_sum {
    int _refCount;
    float x;
};

struct td_cb_sum_f32_sum {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_sum*, float, sjs_sum* _return);
};

struct td_cb_sum_f32_sum_heap {
    cb_sum_f32_sum inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_sum_f32_sum_heap_sum {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_sum*, float, sjs_sum* _return);
    void (*_cb_heap)(sjs_object* _parent, sjs_sum*, float, sjs_sum** _return);
};

struct td_cb_sum_f32_sum_heap_sum_heap {
    cb_sum_f32_sum_heap_sum inner;
    void (*_destroy)(sjs_object*);
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

sjs_array_i32 g_a = { -1 };
sjs_array_f32 g_b = { -1 };
sjs_array_f32 g_c = { -1 };
int32_t g_clocks_per_sec;
sjs_sum g_d = { -1 };
void* g_emptystringdata;
float g_f32_pi;
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
uint32_t g_u32_maxvalue;
int32_t result1;
sjs_sum sjt_call3 = { -1 };
int32_t sjt_functionParam1;
cb_i32_f32 sjt_functionParam11;
cb_f32_bool sjt_functionParam16;
int32_t sjt_functionParam2;
sjs_sum* sjt_functionParam23 = 0;
cb_sum_f32_sum sjt_functionParam24;
int32_t sjt_functionParam3;
int32_t sjt_functionParam4;
int32_t sjt_functionParam5;
int32_t sjt_functionParam6;
sjs_array_i32* sjt_parent1 = 0;
sjs_array_i32* sjt_parent2 = 0;
sjs_array_i32* sjt_parent3 = 0;
sjs_array_i32* sjt_parent4 = 0;
sjs_array_f32* sjt_parent5 = 0;
sjs_array_f32* sjt_parent6 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_array_f32(sjs_array_f32* _this);
void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from);
void sjf_array_f32_destroy(sjs_array_f32* _this);
void sjf_array_f32_filter(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32* _return);
void sjf_array_f32_filter_heap(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32** _return);
void sjf_array_f32_foldl_sum(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum* _return);
void sjf_array_f32_foldl_sum_heap(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum** _return);
void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return);
void sjf_array_f32_heap(sjs_array_f32* _this);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_i32_map_f32(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32* _return);
void sjf_array_i32_map_f32_heap(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32** _return);
void sjf_double(int32_t x, float* _return);
void sjf_double_callback(void * _parent, int32_t x, float* _return);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_lessthan5(float x, bool* _return);
void sjf_lessthan5_callback(void * _parent, float x, bool* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_sum(sjs_sum* _this);
void sjf_sum_copy(sjs_sum* _this, sjs_sum* _from);
void sjf_sum_destroy(sjs_sum* _this);
void sjf_sum_heap(sjs_sum* _this);
void sjf_sumadd(sjs_sum* sum, float x, sjs_sum* _return);
void sjf_sumadd_callback(void * _parent, sjs_sum* sum, float x, sjs_sum* _return);
void sjf_sumadd_heap(sjs_sum* sum, float x, sjs_sum** _return);
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
#include <lib/sj-lib-common/common.cpp>
void sjf_array_f32(sjs_array_f32* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(float) + sizeof(int)) + 1;
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

void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from) {
#line 1 "lib/sj-lib-common/array.sj"
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

void sjf_array_f32_destroy(sjs_array_f32* _this) {
#line 333 "lib/sj-lib-common/array.sj"
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
            float* p = (float*)_this->data;
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

void sjf_array_f32_filter(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32* _return) {
    int32_t i;
    int32_t newcount;
    void* newdata;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;

#line 98 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 99
    newcount = 0;
#line 101
    newdata = (int*)malloc(_parent->count * sizeof(float) + sizeof(int)) + 1;
#line 102
    int* refcount = (int*)newdata - 1;
#line 103
    *refcount = 1;
#line 105
    sjt_forStart3 = 0;
#line 105
    sjt_forEnd3 = _parent->count;
#line 105
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        float item;
        bool sjt_capture1;
        int32_t sjt_functionParam12;
        float sjt_functionParam13;

#line 105 "lib/sj-lib-common/array.sj"
        sjt_functionParam12 = i;
#line 105
        sjf_array_f32_getat(_parent, sjt_functionParam12, &item);
#line 107
        sjt_functionParam13 = item;
#line 107
        cb._cb(cb._parent, sjt_functionParam13, &sjt_capture1);
        if (sjt_capture1) {
#line 109 "lib/sj-lib-common/array.sj"
            float* p = (float*)newdata;
#line 110
            #line 108 "lib/sj-lib-common/array.sj"
p[newcount] = item;
;
#line 112
            newcount = newcount + 1;
        }

#line 105
        i++;
    }

#line 105
    _return->_refCount = 1;
#line 115
    _return->datasize = _parent->count;
#line 115
    _return->data = newdata;
#line 4
    _return->isglobal = false;
#line 115
    _return->count = newcount;
#line 115
    sjf_array_f32(_return);
}

void sjf_array_f32_filter_heap(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32** _return) {
    int32_t i;
    int32_t newcount;
    void* newdata;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;

#line 98 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 99
    newcount = 0;
#line 101
    newdata = (int*)malloc(_parent->count * sizeof(float) + sizeof(int)) + 1;
#line 102
    int* refcount = (int*)newdata - 1;
#line 103
    *refcount = 1;
#line 105
    sjt_forStart4 = 0;
#line 105
    sjt_forEnd4 = _parent->count;
#line 105
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        float item;
        bool sjt_capture2;
        int32_t sjt_functionParam14;
        float sjt_functionParam15;

#line 105 "lib/sj-lib-common/array.sj"
        sjt_functionParam14 = i;
#line 105
        sjf_array_f32_getat(_parent, sjt_functionParam14, &item);
#line 107
        sjt_functionParam15 = item;
#line 107
        cb._cb(cb._parent, sjt_functionParam15, &sjt_capture2);
        if (sjt_capture2) {
#line 109 "lib/sj-lib-common/array.sj"
            float* p = (float*)newdata;
#line 110
            #line 108 "lib/sj-lib-common/array.sj"
p[newcount] = item;
;
#line 112
            newcount = newcount + 1;
        }

#line 105
        i++;
    }

#line 105
    (*_return) = (sjs_array_f32*)malloc(sizeof(sjs_array_f32));
#line 105
    (*_return)->_refCount = 1;
#line 115
    (*_return)->datasize = _parent->count;
#line 115
    (*_return)->data = newdata;
#line 4
    (*_return)->isglobal = false;
#line 115
    (*_return)->count = newcount;
#line 115
    sjf_array_f32_heap((*_return));
}

void sjf_array_f32_foldl_sum(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum* _return) {
    int32_t i;
    sjs_sum* r = 0;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;

#line 118 "lib/sj-lib-common/array.sj"
    r = initial;
#line 120
    sjt_forStart5 = 0;
#line 120
    sjt_forEnd5 = _parent->count;
#line 120
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        sjs_sum sjt_call1 = { -1 };
        sjs_sum* sjt_functionParam17 = 0;
        float sjt_functionParam18;
        int32_t sjt_functionParam19;

#line 121 "lib/sj-lib-common/array.sj"
        sjt_functionParam17 = r;
#line 120
        sjt_functionParam19 = i;
#line 120
        sjf_array_f32_getat(_parent, sjt_functionParam19, &sjt_functionParam18);
#line 120
        cb._cb(cb._parent, sjt_functionParam17, sjt_functionParam18, &sjt_call1);
#line 121
        r = &sjt_call1;
#line 120
        i++;

        if (sjt_call1._refCount == 1) { sjf_sum_destroy(&sjt_call1); }
;
    }

#line 120
    _return->_refCount = 1;
#line 118
    sjf_sum_copy(_return, r);
}

void sjf_array_f32_foldl_sum_heap(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum** _return) {
    int32_t i;
    sjs_sum* r = 0;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;

#line 118 "lib/sj-lib-common/array.sj"
    r = initial;
#line 120
    sjt_forStart6 = 0;
#line 120
    sjt_forEnd6 = _parent->count;
#line 120
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        sjs_sum sjt_call2 = { -1 };
        sjs_sum* sjt_functionParam20 = 0;
        float sjt_functionParam21;
        int32_t sjt_functionParam22;

#line 121 "lib/sj-lib-common/array.sj"
        sjt_functionParam20 = r;
#line 120
        sjt_functionParam22 = i;
#line 120
        sjf_array_f32_getat(_parent, sjt_functionParam22, &sjt_functionParam21);
#line 120
        cb._cb(cb._parent, sjt_functionParam20, sjt_functionParam21, &sjt_call2);
#line 121
        r = &sjt_call2;
#line 120
        i++;

        if (sjt_call2._refCount == 1) { sjf_sum_destroy(&sjt_call2); }
;
    }

#line 120
    (*_return) = (sjs_sum*)malloc(sizeof(sjs_sum));
#line 120
    (*_return)->_refCount = 1;
#line 118
    sjf_sum_copy((*_return), r);
}

void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return) {
#line 9 "lib/sj-lib-common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    float* p = (float*)_parent->data;
#line 14
    #line 8 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_f32_heap(sjs_array_f32* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(float) + sizeof(int)) + 1;
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

void sjf_array_i32(sjs_array_i32* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(int32_t) + sizeof(int)) + 1;
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

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
#line 1 "lib/sj-lib-common/array.sj"
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

void sjf_array_i32_destroy(sjs_array_i32* _this) {
#line 333 "lib/sj-lib-common/array.sj"
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
            int32_t* p = (int32_t*)_this->data;
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

void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
#line 9 "lib/sj-lib-common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    int32_t* p = (int32_t*)_parent->data;
#line 14
    #line 8 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_i32_heap(sjs_array_i32* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(int32_t) + sizeof(int)) + 1;
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

void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item) {
#line 36 "lib/sj-lib-common/array.sj"
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
    int32_t* p = (int32_t*)_parent->data;
#line 44
    #line 34 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_i32_map_f32(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32* _return) {
    int32_t i;
    void* newdata;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

#line 81 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 83
    newdata = (int*)malloc(_parent->count * sizeof(float) + sizeof(int)) + 1;
#line 84
    int* refcount = (int*)newdata - 1;
#line 85
    *refcount = 1;
#line 87
    sjt_forStart1 = 0;
#line 87
    sjt_forEnd1 = _parent->count;
#line 87
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        float newitem;
        int32_t sjt_functionParam7;
        int32_t sjt_functionParam8;

#line 87 "lib/sj-lib-common/array.sj"
        sjt_functionParam8 = i;
#line 87
        sjf_array_i32_getat(_parent, sjt_functionParam8, &sjt_functionParam7);
#line 87
        cb._cb(cb._parent, sjt_functionParam7, &newitem);
#line 90
        float* p = (float*)newdata;
#line 91
        #line 89 "lib/sj-lib-common/array.sj"
p[i] = newitem;
;
#line 87
        i++;
    }

#line 87
    _return->_refCount = 1;
#line 94
    _return->datasize = _parent->count;
#line 94
    _return->data = newdata;
#line 4
    _return->isglobal = false;
#line 94
    _return->count = _parent->count;
#line 94
    sjf_array_f32(_return);
}

void sjf_array_i32_map_f32_heap(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32** _return) {
    int32_t i;
    void* newdata;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;

#line 81 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 83
    newdata = (int*)malloc(_parent->count * sizeof(float) + sizeof(int)) + 1;
#line 84
    int* refcount = (int*)newdata - 1;
#line 85
    *refcount = 1;
#line 87
    sjt_forStart2 = 0;
#line 87
    sjt_forEnd2 = _parent->count;
#line 87
    i = sjt_forStart2;
    while (i < sjt_forEnd2) {
        float newitem;
        int32_t sjt_functionParam10;
        int32_t sjt_functionParam9;

#line 87 "lib/sj-lib-common/array.sj"
        sjt_functionParam10 = i;
#line 87
        sjf_array_i32_getat(_parent, sjt_functionParam10, &sjt_functionParam9);
#line 87
        cb._cb(cb._parent, sjt_functionParam9, &newitem);
#line 90
        float* p = (float*)newdata;
#line 91
        #line 89 "lib/sj-lib-common/array.sj"
p[i] = newitem;
;
#line 87
        i++;
    }

#line 87
    (*_return) = (sjs_array_f32*)malloc(sizeof(sjs_array_f32));
#line 87
    (*_return)->_refCount = 1;
#line 94
    (*_return)->datasize = _parent->count;
#line 94
    (*_return)->data = newdata;
#line 4
    (*_return)->isglobal = false;
#line 94
    (*_return)->count = _parent->count;
#line 94
    sjf_array_f32_heap((*_return));
}

void sjf_double(int32_t x, float* _return) {
    int32_t sjt_cast2;

#line 2 "array6.sj"
    sjt_cast2 = x;
#line 3
    (*_return) = (float)sjt_cast2 * 2.0f;
}

void sjf_double_callback(void * _parent, int32_t x, float* _return) {
    sjf_double(x, _return);
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

void sjf_lessthan5(float x, bool* _return) {
#line 7 "array6.sj"
    (*_return) = x < 5.0f;
}

void sjf_lessthan5_callback(void * _parent, float x, bool* _return) {
    sjf_lessthan5(x, _return);
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

void sjf_sum(sjs_sum* _this) {
}

void sjf_sum_copy(sjs_sum* _this, sjs_sum* _from) {
#line 14 "array6.sj"
    _this->x = _from->x;
}

void sjf_sum_destroy(sjs_sum* _this) {
}

void sjf_sum_heap(sjs_sum* _this) {
}

void sjf_sumadd(sjs_sum* sum, float x, sjs_sum* _return) {
    _return->_refCount = 1;
#line 19 "array6.sj"
    _return->x = sum->x + x;
#line 19
    sjf_sum(_return);
}

void sjf_sumadd_callback(void * _parent, sjs_sum* sum, float x, sjs_sum* _return) {
    sjf_sumadd(sum, x, _return);
}

void sjf_sumadd_heap(sjs_sum* sum, float x, sjs_sum** _return) {
    (*_return) = (sjs_sum*)malloc(sizeof(sjs_sum));
    (*_return)->_refCount = 1;
#line 19 "array6.sj"
    (*_return)->x = sum->x + x;
#line 19
    sjf_sum_heap((*_return));
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
    g_emptystringdata = (void*)"";
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
#line 22 "array6.sj"
    g_a.datasize = 3;
#line 3 "lib/sj-lib-common/array.sj"
    g_a.data = 0;
#line 4
    g_a.isglobal = false;
#line 5
    g_a.count = 0;
#line 5
    sjf_array_i32(&g_a);
#line 22 "array6.sj"
    sjs_array_i32* array1;
#line 22
    array1 = &g_a;
#line 22
    sjt_parent1 = array1;
#line 22
    sjt_functionParam1 = 0;
#line 22
    sjt_functionParam2 = 1;
#line 22
    sjf_array_i32_initat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
#line 22
    sjt_parent2 = array1;
#line 22
    sjt_functionParam3 = 1;
#line 22
    sjt_functionParam4 = 2;
#line 22
    sjf_array_i32_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
#line 22
    sjt_parent3 = array1;
#line 22
    sjt_functionParam5 = 2;
#line 22
    sjt_functionParam6 = 3;
#line 22
    sjf_array_i32_initat(sjt_parent3, sjt_functionParam5, sjt_functionParam6);
#line 80 "lib/sj-lib-common/array.sj"
    sjt_parent4 = &g_a;
#line 23 "array6.sj"
    sjt_functionParam11._parent = (sjs_object*)1;
#line 23
    sjt_functionParam11._cb = (void(*)(sjs_object*,int32_t, float*))sjf_double_callback;
#line 23
    sjf_array_i32_map_f32(sjt_parent4, sjt_functionParam11, &g_b);
#line 97 "lib/sj-lib-common/array.sj"
    sjt_parent5 = &g_b;
#line 24 "array6.sj"
    sjt_functionParam16._parent = (sjs_object*)1;
#line 24
    sjt_functionParam16._cb = (void(*)(sjs_object*,float, bool*))sjf_lessthan5_callback;
#line 24
    sjf_array_f32_filter(sjt_parent5, sjt_functionParam16, &g_c);
#line 118 "lib/sj-lib-common/array.sj"
    sjt_parent6 = &g_c;
#line 118
    sjt_call3._refCount = 1;
#line 15 "array6.sj"
    sjt_call3.x = 0.0f;
#line 15
    sjf_sum(&sjt_call3);
#line 25
    sjt_functionParam23 = &sjt_call3;
#line 25
    sjt_functionParam24._parent = (sjs_object*)1;
#line 25
    sjt_functionParam24._cb = (void(*)(sjs_object*,sjs_sum*,float, sjs_sum*))sjf_sumadd_callback;
#line 25
    sjf_array_f32_foldl_sum(sjt_parent6, sjt_functionParam23, sjt_functionParam24, &g_d);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (g_a._refCount == 1) { sjf_array_i32_destroy(&g_a); }
;
    if (g_b._refCount == 1) { sjf_array_f32_destroy(&g_b); }
;
    if (g_c._refCount == 1) { sjf_array_f32_destroy(&g_c); }
;
    if (g_d._refCount == 1) { sjf_sum_destroy(&g_d); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (sjt_call3._refCount == 1) { sjf_sum_destroy(&sjt_call3); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
