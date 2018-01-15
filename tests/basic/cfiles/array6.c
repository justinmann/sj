#include <lib/sj-lib-common/common.h>

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
#define sjs_array_i32_typeId 26
#define sjs_array_f32_typeId 28
#define cb_i32_f32_typeId 30
#define cb_i32_f32_heap_typeId 30
#define cb_f32_bool_typeId 35
#define cb_f32_bool_heap_typeId 35
#define sjs_sum_typeId 39
#define cb_sum_f32_sum_typeId 41
#define cb_sum_f32_sum_heap_typeId 41
#define cb_sum_f32_sum_heap_sum_typeId 43
#define cb_sum_f32_sum_heap_sum_heap_typeId 43

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
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

struct td_sjs_array_i32 {
    int _refCount;
    void* v;
};

struct td_sjs_array_f32 {
    int _refCount;
    void* v;
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
char* string_char(sjs_string* str);
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
float g_f32_pi;
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
uint32_t g_u32_maxvalue;
int32_t result1;
sjs_sum sjt_call3 = { -1 };
cb_i32_f32 sjt_functionParam14;
cb_f32_bool sjt_functionParam19;
sjs_sum* sjt_functionParam26 = 0;
cb_sum_f32_sum sjt_functionParam27;
int32_t sjt_functionParam4;
int32_t sjt_functionParam5;
int32_t sjt_functionParam6;
int32_t sjt_functionParam7;
int32_t sjt_functionParam8;
int32_t sjt_functionParam9;
sjs_array_i32* sjt_parent3 = 0;
sjs_array_i32* sjt_parent4 = 0;
sjs_array_i32* sjt_parent5 = 0;
sjs_array_i32* sjt_parent6 = 0;
sjs_array_f32* sjt_parent7 = 0;
sjs_array_f32* sjt_parent8 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_gettotalcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_f32(sjs_array_f32* _this);
void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from);
void sjf_array_f32_destroy(sjs_array_f32* _this);
void sjf_array_f32_filter(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32* _return);
void sjf_array_f32_filter_heap(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32** _return);
void sjf_array_f32_foldl_sum(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum* _return);
void sjf_array_f32_foldl_sum_heap(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum** _return);
void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return);
void sjf_array_f32_getcount(sjs_array_f32* _parent, int32_t* _return);
void sjf_array_f32_heap(sjs_array_f32* _this);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_getcount(sjs_array_i32* _parent, int32_t* _return);
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
void sjf_string_nullterminate(sjs_string* _parent);
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

void sjf_array_f32(sjs_array_f32* _this) {
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

void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_f32_destroy(sjs_array_f32* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !true && !false
#line 381
        float* p = (float*)arr->data;
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

void sjf_array_f32_filter(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32* _return) {
    int32_t i;
    void* newdata;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;

#line 133 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 135
    sjs_array* arr = (sjs_array*)_parent->v;
#line 136
    sjs_array* newArr = createarray(sizeof(float), arr->count);
#line 137
    newdata = (void*)newArr;
#line 139
    sjt_forStart3 = 0;
#line 139
    sjf_array_f32_getcount(_parent, &sjt_forEnd3);
#line 139
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        float item;
        bool sjt_capture2;
        int32_t sjt_functionParam15;
        float sjt_functionParam16;

#line 139 "lib/sj-lib-common/array.sj"
        sjt_functionParam15 = i;
#line 139
        sjf_array_f32_getat(_parent, sjt_functionParam15, &item);
#line 141
        sjt_functionParam16 = item;
#line 141
        cb._cb(cb._parent, sjt_functionParam16, &sjt_capture2);
        if (sjt_capture2) {
#line 143 "lib/sj-lib-common/array.sj"
            float* p = (float*)newArr->data;
#line 144
            #line 142 "lib/sj-lib-common/array.sj"
p[newArr->count] = item;
;
#line 145
            newArr->count++;
        }

#line 139
        i++;
    }

#line 139
    _return->_refCount = 1;
#line 149
    _return->v = newdata;
#line 149
    sjf_array_f32(_return);
}

void sjf_array_f32_filter_heap(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32** _return) {
    int32_t i;
    void* newdata;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;

#line 133 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 135
    sjs_array* arr = (sjs_array*)_parent->v;
#line 136
    sjs_array* newArr = createarray(sizeof(float), arr->count);
#line 137
    newdata = (void*)newArr;
#line 139
    sjt_forStart4 = 0;
#line 139
    sjf_array_f32_getcount(_parent, &sjt_forEnd4);
#line 139
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        float item;
        bool sjt_capture3;
        int32_t sjt_functionParam17;
        float sjt_functionParam18;

#line 139 "lib/sj-lib-common/array.sj"
        sjt_functionParam17 = i;
#line 139
        sjf_array_f32_getat(_parent, sjt_functionParam17, &item);
#line 141
        sjt_functionParam18 = item;
#line 141
        cb._cb(cb._parent, sjt_functionParam18, &sjt_capture3);
        if (sjt_capture3) {
#line 143 "lib/sj-lib-common/array.sj"
            float* p = (float*)newArr->data;
#line 144
            #line 142 "lib/sj-lib-common/array.sj"
p[newArr->count] = item;
;
#line 145
            newArr->count++;
        }

#line 139
        i++;
    }

#line 139
    (*_return) = (sjs_array_f32*)malloc(sizeof(sjs_array_f32));
#line 139
    (*_return)->_refCount = 1;
#line 149
    (*_return)->v = newdata;
#line 149
    sjf_array_f32_heap((*_return));
}

void sjf_array_f32_foldl_sum(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum* _return) {
    int32_t i;
    sjs_sum* r = 0;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;

#line 152 "lib/sj-lib-common/array.sj"
    r = initial;
#line 154
    sjt_forStart5 = 0;
#line 154
    sjf_array_f32_getcount(_parent, &sjt_forEnd5);
#line 154
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        sjs_sum sjt_call1 = { -1 };
        sjs_sum* sjt_functionParam20 = 0;
        float sjt_functionParam21;
        int32_t sjt_functionParam22;

#line 155 "lib/sj-lib-common/array.sj"
        sjt_functionParam20 = r;
#line 154
        sjt_functionParam22 = i;
#line 154
        sjf_array_f32_getat(_parent, sjt_functionParam22, &sjt_functionParam21);
#line 154
        cb._cb(cb._parent, sjt_functionParam20, sjt_functionParam21, &sjt_call1);
#line 155
        r = &sjt_call1;
#line 154
        i++;

        if (sjt_call1._refCount == 1) { sjf_sum_destroy(&sjt_call1); }
;
    }

#line 154
    _return->_refCount = 1;
#line 152
    sjf_sum_copy(_return, r);
}

void sjf_array_f32_foldl_sum_heap(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum** _return) {
    int32_t i;
    sjs_sum* r = 0;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;

#line 152 "lib/sj-lib-common/array.sj"
    r = initial;
#line 154
    sjt_forStart6 = 0;
#line 154
    sjf_array_f32_getcount(_parent, &sjt_forEnd6);
#line 154
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        sjs_sum sjt_call2 = { -1 };
        sjs_sum* sjt_functionParam23 = 0;
        float sjt_functionParam24;
        int32_t sjt_functionParam25;

#line 155 "lib/sj-lib-common/array.sj"
        sjt_functionParam23 = r;
#line 154
        sjt_functionParam25 = i;
#line 154
        sjf_array_f32_getat(_parent, sjt_functionParam25, &sjt_functionParam24);
#line 154
        cb._cb(cb._parent, sjt_functionParam23, sjt_functionParam24, &sjt_call2);
#line 155
        r = &sjt_call2;
#line 154
        i++;

        if (sjt_call2._refCount == 1) { sjf_sum_destroy(&sjt_call2); }
;
    }

#line 154
    (*_return) = (sjs_sum*)malloc(sizeof(sjs_sum));
#line 154
    (*_return)->_refCount = 1;
#line 152
    sjf_sum_copy((*_return), r);
}

void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    float* p = (float*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_f32_getcount(sjs_array_f32* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_f32_heap(sjs_array_f32* _this) {
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

void sjf_array_i32(sjs_array_i32* _this) {
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

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !true && !false
#line 381
        int32_t* p = (int32_t*)arr->data;
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

void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    int32_t* p = (int32_t*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_i32_getcount(sjs_array_i32* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_i32_heap(sjs_array_i32* _this) {
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

void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item) {
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
    int32_t* p = (int32_t*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 64
    arr->count = index + 1;
}

void sjf_array_i32_map_f32(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32* _return) {
    int32_t i;
    void* newdata;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

#line 115 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 117
    sjs_array* arr = (sjs_array*)_parent->v;
#line 118
    sjs_array* newArr = createarray(sizeof(float), arr->count);
#line 119
    newArr->count = arr->count;
#line 120
    newdata = (void*)newArr;
#line 122
    sjt_forStart1 = 0;
#line 122
    sjf_array_i32_getcount(_parent, &sjt_forEnd1);
#line 122
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        float newitem;
        int32_t sjt_functionParam10;
        int32_t sjt_functionParam11;

#line 122 "lib/sj-lib-common/array.sj"
        sjt_functionParam11 = i;
#line 122
        sjf_array_i32_getat(_parent, sjt_functionParam11, &sjt_functionParam10);
#line 122
        cb._cb(cb._parent, sjt_functionParam10, &newitem);
#line 125
        float* p = (float*)newArr->data;
#line 126
        #line 124 "lib/sj-lib-common/array.sj"
p[i] = newitem;
;
#line 122
        i++;
    }

#line 122
    _return->_refCount = 1;
#line 129
    _return->v = newdata;
#line 129
    sjf_array_f32(_return);
}

void sjf_array_i32_map_f32_heap(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32** _return) {
    int32_t i;
    void* newdata;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;

#line 115 "lib/sj-lib-common/array.sj"
    newdata = 0;
#line 117
    sjs_array* arr = (sjs_array*)_parent->v;
#line 118
    sjs_array* newArr = createarray(sizeof(float), arr->count);
#line 119
    newArr->count = arr->count;
#line 120
    newdata = (void*)newArr;
#line 122
    sjt_forStart2 = 0;
#line 122
    sjf_array_i32_getcount(_parent, &sjt_forEnd2);
#line 122
    i = sjt_forStart2;
    while (i < sjt_forEnd2) {
        float newitem;
        int32_t sjt_functionParam12;
        int32_t sjt_functionParam13;

#line 122 "lib/sj-lib-common/array.sj"
        sjt_functionParam13 = i;
#line 122
        sjf_array_i32_getat(_parent, sjt_functionParam13, &sjt_functionParam12);
#line 122
        cb._cb(cb._parent, sjt_functionParam12, &newitem);
#line 125
        float* p = (float*)newArr->data;
#line 126
        #line 124 "lib/sj-lib-common/array.sj"
p[i] = newitem;
;
#line 122
        i++;
    }

#line 122
    (*_return) = (sjs_array_f32*)malloc(sizeof(sjs_array_f32));
#line 122
    (*_return)->_refCount = 1;
#line 129
    (*_return)->v = newdata;
#line 129
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
    g_a.v = createarray(sizeof(int32_t), 3);
#line 22
    sjf_array_i32(&g_a);
#line 22
    sjs_array_i32* array1;
#line 22
    array1 = &g_a;
#line 22
    sjt_parent3 = array1;
#line 22
    sjt_functionParam4 = 0;
#line 22
    sjt_functionParam5 = 1;
#line 22
    sjf_array_i32_initat(sjt_parent3, sjt_functionParam4, sjt_functionParam5);
#line 22
    sjt_parent4 = array1;
#line 22
    sjt_functionParam6 = 1;
#line 22
    sjt_functionParam7 = 2;
#line 22
    sjf_array_i32_initat(sjt_parent4, sjt_functionParam6, sjt_functionParam7);
#line 22
    sjt_parent5 = array1;
#line 22
    sjt_functionParam8 = 2;
#line 22
    sjt_functionParam9 = 3;
#line 22
    sjf_array_i32_initat(sjt_parent5, sjt_functionParam8, sjt_functionParam9);
#line 114 "lib/sj-lib-common/array.sj"
    sjt_parent6 = &g_a;
#line 23 "array6.sj"
    sjt_functionParam14._parent = (sjs_object*)1;
#line 23
    sjt_functionParam14._cb = (void(*)(sjs_object*,int32_t, float*))sjf_double_callback;
#line 23
    sjf_array_i32_map_f32(sjt_parent6, sjt_functionParam14, &g_b);
#line 132 "lib/sj-lib-common/array.sj"
    sjt_parent7 = &g_b;
#line 24 "array6.sj"
    sjt_functionParam19._parent = (sjs_object*)1;
#line 24
    sjt_functionParam19._cb = (void(*)(sjs_object*,float, bool*))sjf_lessthan5_callback;
#line 24
    sjf_array_f32_filter(sjt_parent7, sjt_functionParam19, &g_c);
#line 152 "lib/sj-lib-common/array.sj"
    sjt_parent8 = &g_c;
#line 152
    sjt_call3._refCount = 1;
#line 15 "array6.sj"
    sjt_call3.x = 0.0f;
#line 15
    sjf_sum(&sjt_call3);
#line 25
    sjt_functionParam26 = &sjt_call3;
#line 25
    sjt_functionParam27._parent = (sjs_object*)1;
#line 25
    sjt_functionParam27._cb = (void(*)(sjs_object*,sjs_sum*,float, sjs_sum*))sjf_sumadd_callback;
#line 25
    sjf_array_f32_foldl_sum(sjt_parent8, sjt_functionParam26, sjt_functionParam27, &g_d);
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
