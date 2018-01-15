#include <lib/sj-lib-common/common.h>

struct {
    int refcount;
    int size;
    int count;
    char data[3];
} sjg_string1 = { 1, 3, 2, ", "};
struct {
    int refcount;
    int size;
    int count;
    char data[1];
} sjg_string2 = { 1, 1, 0, ""};

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
#define sjs_array_weak_class_typeId 28

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_array_weak_class sjs_array_weak_class;

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
    int32_t x;
};

struct td_sjs_array_weak_class {
    int _refCount;
    void* v;
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

sjs_array_weak_class g_a = { -1 };
sjs_class* g_c = 0;
int32_t g_clocks_per_sec;
sjs_class* g_d = 0;
float g_f32_pi;
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
uint32_t g_u32_maxvalue;
int32_t result1;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call16 = { -1 };
sjs_string sjt_call17 = { -1 };
sjs_string sjt_call18 = { -1 };
sjs_string sjt_call19 = { -1 };
sjs_string sjt_call20 = { -1 };
sjs_class* sjt_funcold6 = 0;
sjs_class* sjt_funcold7 = 0;
int32_t sjt_functionParam4;
sjs_string* sjt_functionParam44 = 0;
sjs_string* sjt_functionParam45 = 0;
sjs_string* sjt_functionParam46 = 0;
sjs_string* sjt_functionParam47 = 0;
sjs_string* sjt_functionParam48 = 0;
sjs_class* sjt_functionParam5 = 0;
int32_t sjt_functionParam6;
sjs_class* sjt_functionParam7 = 0;
sjs_string* sjt_functionParam8 = 0;
sjs_array_weak_class* sjt_parent31 = 0;
sjs_array_weak_class* sjt_parent32 = 0;
sjs_array_weak_class* sjt_parent33 = 0;
sjs_array_weak_class* sjt_parent4 = 0;
sjs_array_weak_class* sjt_parent5 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_gettotalcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_weak_class(sjs_array_weak_class* _this);
void sjf_array_weak_class_asstring(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string* _return);
void sjf_array_weak_class_asstring_heap(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string** _return);
void sjf_array_weak_class_copy(sjs_array_weak_class* _this, sjs_array_weak_class* _from);
void sjf_array_weak_class_destroy(sjs_array_weak_class* _this);
void sjf_array_weak_class_getat(sjs_array_weak_class* _parent, int32_t index, sjs_class** _return);
void sjf_array_weak_class_getat_heap(sjs_array_weak_class* _parent, int32_t index, sjs_class** _return);
void sjf_array_weak_class_getcount(sjs_array_weak_class* _parent, int32_t* _return);
void sjf_array_weak_class_heap(sjs_array_weak_class* _this);
void sjf_array_weak_class_initat(sjs_array_weak_class* _parent, int32_t index, sjs_class* item);
void sjf_class(sjs_class* _this);
void sjf_class_asstring(sjs_class* _parent, sjs_string* _return);
void sjf_class_asstring_heap(sjs_class* _parent, sjs_string** _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return);
void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_nullterminate(sjs_string* _parent);
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

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    char* p = (char*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
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

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
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
    char* p = (char*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 64
    arr->count = index + 1;
}

void sjf_array_weak_class(sjs_array_weak_class* _this) {
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

void sjf_array_weak_class_asstring(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string* _return) {
    int32_t i;
    sjs_string result = { -1 };
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

    result._refCount = 1;
#line 295 "lib/sj-lib-common/array.sj"
    result.offset = 0;
#line 295
    result.count = 0;
#line 295
    result.data._refCount = 1;
#line 295
    result.data.v = &sjg_string2;
#line 295
    sjf_array_char(&result.data);
#line 16 "lib/sj-lib-common/string.sj"
    result._isnullterminated = false;
#line 16
    sjf_string(&result);
#line 296 "lib/sj-lib-common/array.sj"
    sjt_forStart1 = 0;
#line 296
    sjf_array_weak_class_getcount(_parent, &sjt_forEnd1);
#line 296
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_class* sjt_call2 = 0;
        sjs_string sjt_call3 = { -1 };
        sjs_string sjt_call6 = { -1 };
        sjs_string sjt_call8 = { -1 };
        sjs_string* sjt_capture9 = 0;
        sjs_string sjt_funcold2 = { -1 };
        sjs_string sjt_funcold3 = { -1 };
        sjs_string* sjt_functionParam29 = 0;
        int32_t sjt_functionParam30;
        sjs_string* sjt_parent24 = 0;

        if (i != 0) {
            sjs_string* sjt_functionParam28 = 0;
            sjs_string* sjt_parent23 = 0;

#line 18 "lib/sj-lib-common/string.sj"
            sjt_parent23 = &result;
#line 294 "lib/sj-lib-common/array.sj"
            sjt_functionParam28 = sep;
#line 294
            sjf_string_add(sjt_parent23, sjt_functionParam28, &sjt_funcold2);
#line 294
            if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 18 "lib/sj-lib-common/string.sj"
            sjf_string_copy(&result, &sjt_funcold2);
        }

#line 18 "lib/sj-lib-common/string.sj"
        sjt_parent24 = &result;
#line 296 "lib/sj-lib-common/array.sj"
        sjt_functionParam30 = i;
#line 296
        sjf_array_weak_class_getat(_parent, sjt_functionParam30, &sjt_call2);
        if (sjt_call2 != 0) {
            sjs_class* sjt_call4 = 0;
            int32_t sjt_functionParam35;
            sjs_class* sjt_parent25 = 0;
            sjs_string* sjt_value2 = 0;

#line 296 "lib/sj-lib-common/array.sj"
            sjt_functionParam35 = i;
#line 296
            sjf_array_weak_class_getat(_parent, sjt_functionParam35, &sjt_call4);
#line 300
            sjt_parent25 = sjt_call4;
#line 300
            sjf_class_asstring(sjt_parent25, &sjt_call3);
#line 300
            sjt_value2 = &sjt_call3;
#line 300
            sjt_capture9 = sjt_value2;

            delete_cb weakptrcb8 = { &sjt_call4, weakptr_clear };
            if (sjt_call4 != 0) { weakptr_cb_remove(sjt_call4, weakptrcb8); }
        } else {
#line 300 "lib/sj-lib-common/array.sj"
            sjt_capture9 = 0;
        }

        if (sjt_capture9 != 0) {
            sjs_class* sjt_call5 = 0;
            int32_t sjt_functionParam36;

#line 296 "lib/sj-lib-common/array.sj"
            sjt_functionParam36 = i;
#line 296
            sjf_array_weak_class_getat(_parent, sjt_functionParam36, &sjt_call5);
            if (sjt_call5 != 0) {
                sjs_class* sjt_call7 = 0;
                int32_t sjt_functionParam37;
                sjs_class* sjt_parent26 = 0;
                sjs_string* sjt_value3 = 0;

#line 296 "lib/sj-lib-common/array.sj"
                sjt_functionParam37 = i;
#line 296
                sjf_array_weak_class_getat(_parent, sjt_functionParam37, &sjt_call7);
#line 300
                sjt_parent26 = sjt_call7;
#line 300
                sjf_class_asstring(sjt_parent26, &sjt_call6);
#line 300
                sjt_value3 = &sjt_call6;
#line 300
                sjt_functionParam29 = sjt_value3;

                delete_cb weakptrcb9 = { &sjt_call7, weakptr_clear };
                if (sjt_call7 != 0) { weakptr_cb_remove(sjt_call7, weakptrcb9); }
            } else {
#line 300 "lib/sj-lib-common/array.sj"
                sjt_functionParam29 = 0;
            }

            delete_cb weakptrcb10 = { &sjt_call5, weakptr_clear };
            if (sjt_call5 != 0) { weakptr_cb_remove(sjt_call5, weakptrcb10); }
        } else {
            sjt_call8._refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
            sjt_call8.offset = 0;
#line 14
            sjt_call8.count = 0;
#line 14
            sjt_call8.data._refCount = 1;
#line 27 "lib/sj-lib-common/array.sj"
            sjt_call8.data.v = 0;
#line 27
            sjf_array_char(&sjt_call8.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call8._isnullterminated = false;
#line 16
            sjf_string(&sjt_call8);
#line 300 "lib/sj-lib-common/array.sj"
            sjt_functionParam29 = &sjt_call8;
        }

#line 296
        sjf_string_add(sjt_parent24, sjt_functionParam29, &sjt_funcold3);
#line 296
        if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 18 "lib/sj-lib-common/string.sj"
        sjf_string_copy(&result, &sjt_funcold3);
#line 296 "lib/sj-lib-common/array.sj"
        i++;

        delete_cb weakptrcb11 = { &sjt_call2, weakptr_clear };
        if (sjt_call2 != 0) { weakptr_cb_remove(sjt_call2, weakptrcb11); }
        if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
        if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
;
        if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
        if (sjt_funcold2._refCount == 1) { sjf_string_destroy(&sjt_funcold2); }
;
        if (sjt_funcold3._refCount == 1) { sjf_string_destroy(&sjt_funcold3); }
;
    }

#line 296
    _return->_refCount = 1;
#line 294
    sjf_string_copy(_return, &result);

    if (result._refCount == 1) { sjf_string_destroy(&result); }
;
}

void sjf_array_weak_class_asstring_heap(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string** _return) {
    int32_t i;
    sjs_string result = { -1 };
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;

    result._refCount = 1;
#line 295 "lib/sj-lib-common/array.sj"
    result.offset = 0;
#line 295
    result.count = 0;
#line 295
    result.data._refCount = 1;
#line 295
    result.data.v = &sjg_string2;
#line 295
    sjf_array_char(&result.data);
#line 16 "lib/sj-lib-common/string.sj"
    result._isnullterminated = false;
#line 16
    sjf_string(&result);
#line 296 "lib/sj-lib-common/array.sj"
    sjt_forStart6 = 0;
#line 296
    sjf_array_weak_class_getcount(_parent, &sjt_forEnd6);
#line 296
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        sjs_string sjt_call10 = { -1 };
        sjs_string sjt_call13 = { -1 };
        sjs_string sjt_call15 = { -1 };
        sjs_class* sjt_call9 = 0;
        sjs_string* sjt_capture10 = 0;
        sjs_string sjt_funcold4 = { -1 };
        sjs_string sjt_funcold5 = { -1 };
        sjs_string* sjt_functionParam39 = 0;
        int32_t sjt_functionParam40;
        sjs_string* sjt_parent28 = 0;

        if (i != 0) {
            sjs_string* sjt_functionParam38 = 0;
            sjs_string* sjt_parent27 = 0;

#line 18 "lib/sj-lib-common/string.sj"
            sjt_parent27 = &result;
#line 294 "lib/sj-lib-common/array.sj"
            sjt_functionParam38 = sep;
#line 294
            sjf_string_add(sjt_parent27, sjt_functionParam38, &sjt_funcold4);
#line 294
            if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 18 "lib/sj-lib-common/string.sj"
            sjf_string_copy(&result, &sjt_funcold4);
        }

#line 18 "lib/sj-lib-common/string.sj"
        sjt_parent28 = &result;
#line 296 "lib/sj-lib-common/array.sj"
        sjt_functionParam40 = i;
#line 296
        sjf_array_weak_class_getat(_parent, sjt_functionParam40, &sjt_call9);
        if (sjt_call9 != 0) {
            sjs_class* sjt_call11 = 0;
            int32_t sjt_functionParam41;
            sjs_class* sjt_parent29 = 0;
            sjs_string* sjt_value4 = 0;

#line 296 "lib/sj-lib-common/array.sj"
            sjt_functionParam41 = i;
#line 296
            sjf_array_weak_class_getat(_parent, sjt_functionParam41, &sjt_call11);
#line 300
            sjt_parent29 = sjt_call11;
#line 300
            sjf_class_asstring(sjt_parent29, &sjt_call10);
#line 300
            sjt_value4 = &sjt_call10;
#line 300
            sjt_capture10 = sjt_value4;

            delete_cb weakptrcb12 = { &sjt_call11, weakptr_clear };
            if (sjt_call11 != 0) { weakptr_cb_remove(sjt_call11, weakptrcb12); }
        } else {
#line 300 "lib/sj-lib-common/array.sj"
            sjt_capture10 = 0;
        }

        if (sjt_capture10 != 0) {
            sjs_class* sjt_call12 = 0;
            int32_t sjt_functionParam42;

#line 296 "lib/sj-lib-common/array.sj"
            sjt_functionParam42 = i;
#line 296
            sjf_array_weak_class_getat(_parent, sjt_functionParam42, &sjt_call12);
            if (sjt_call12 != 0) {
                sjs_class* sjt_call14 = 0;
                int32_t sjt_functionParam43;
                sjs_class* sjt_parent30 = 0;
                sjs_string* sjt_value5 = 0;

#line 296 "lib/sj-lib-common/array.sj"
                sjt_functionParam43 = i;
#line 296
                sjf_array_weak_class_getat(_parent, sjt_functionParam43, &sjt_call14);
#line 300
                sjt_parent30 = sjt_call14;
#line 300
                sjf_class_asstring(sjt_parent30, &sjt_call13);
#line 300
                sjt_value5 = &sjt_call13;
#line 300
                sjt_functionParam39 = sjt_value5;

                delete_cb weakptrcb13 = { &sjt_call14, weakptr_clear };
                if (sjt_call14 != 0) { weakptr_cb_remove(sjt_call14, weakptrcb13); }
            } else {
#line 300 "lib/sj-lib-common/array.sj"
                sjt_functionParam39 = 0;
            }

            delete_cb weakptrcb14 = { &sjt_call12, weakptr_clear };
            if (sjt_call12 != 0) { weakptr_cb_remove(sjt_call12, weakptrcb14); }
        } else {
            sjt_call15._refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
            sjt_call15.offset = 0;
#line 14
            sjt_call15.count = 0;
#line 14
            sjt_call15.data._refCount = 1;
#line 27 "lib/sj-lib-common/array.sj"
            sjt_call15.data.v = 0;
#line 27
            sjf_array_char(&sjt_call15.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call15._isnullterminated = false;
#line 16
            sjf_string(&sjt_call15);
#line 300 "lib/sj-lib-common/array.sj"
            sjt_functionParam39 = &sjt_call15;
        }

#line 296
        sjf_string_add(sjt_parent28, sjt_functionParam39, &sjt_funcold5);
#line 296
        if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 18 "lib/sj-lib-common/string.sj"
        sjf_string_copy(&result, &sjt_funcold5);
#line 296 "lib/sj-lib-common/array.sj"
        i++;

        delete_cb weakptrcb15 = { &sjt_call9, weakptr_clear };
        if (sjt_call9 != 0) { weakptr_cb_remove(sjt_call9, weakptrcb15); }
        if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
;
        if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
        if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
;
        if (sjt_funcold4._refCount == 1) { sjf_string_destroy(&sjt_funcold4); }
;
        if (sjt_funcold5._refCount == 1) { sjf_string_destroy(&sjt_funcold5); }
;
    }

#line 296
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 296
    (*_return)->_refCount = 1;
#line 294
    sjf_string_copy((*_return), &result);

    if (result._refCount == 1) { sjf_string_destroy(&result); }
;
}

void sjf_array_weak_class_copy(sjs_array_weak_class* _this, sjs_array_weak_class* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_weak_class_destroy(sjs_array_weak_class* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !false
#line 381
        sjs_class** p = (sjs_class**)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            delete_cb weakptrcb3 = { &p[i], weakptr_clear };
if (p[i] != 0) { weakptr_cb_remove(p[i], weakptrcb3); }
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

void sjf_array_weak_class_getat(sjs_array_weak_class* _parent, int32_t index, sjs_class** _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_class** p = (sjs_class**)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
#line 42
delete_cb weakptrcb7 = { &(*_return), weakptr_clear };
#line 42
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb7); }
return;;       
}

void sjf_array_weak_class_getat_heap(sjs_array_weak_class* _parent, int32_t index, sjs_class** _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_class** p = (sjs_class**)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
if ((*_return) != 0) {
    (*_return)->_refCount++;
}
return;;       
}

void sjf_array_weak_class_getcount(sjs_array_weak_class* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_weak_class_heap(sjs_array_weak_class* _this) {
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

void sjf_array_weak_class_initat(sjs_array_weak_class* _parent, int32_t index, sjs_class* item) {
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
    sjs_class** p = (sjs_class**)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
#line 52
delete_cb weakptrcb4 = { &p[index], weakptr_clear };
#line 52
if (p[index] != 0) { weakptr_cb_add(p[index], weakptrcb4); }
;
#line 64
    arr->count = index + 1;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_asstring(sjs_class* _parent, sjs_string* _return) {
    int32_t sjt_functionParam31;
    int32_t sjt_functionParam32;

#line 4 "weak2.sj"
    sjt_functionParam31 = _parent->x;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam32 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam31, sjt_functionParam32, _return);
}

void sjf_class_asstring_heap(sjs_class* _parent, sjs_string** _return) {
    int32_t sjt_functionParam33;
    int32_t sjt_functionParam34;

#line 4 "weak2.sj"
    sjt_functionParam33 = _parent->x;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam34 = 10;
#line 22
    sjf_i32_asstring_heap(sjt_functionParam33, sjt_functionParam34, _return);
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 2 "weak2.sj"
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
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

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t count;
    void* vresult;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    vresult = 0;
#line 26
    sjs_array* arr = createarray(1, 256);
#line 27
    vresult = (void*)arr;
#line 28
    char *tmp = (char*)arr->data + 128;
#line 29
    char *tp = (char*)arr->data + 128;
#line 30
    int i;
#line 31
    unsigned v;
#line 33
    int sign = (base == 10 && val < 0);    
#line 34
    if (sign)
#line 35
    v = -val;
#line 36
    else
#line 37
    v = (unsigned)val;
#line 39
    while (v || tp == tmp)
#line 40
    {
#line 41
        i = v % base;
#line 42
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 43
        if (i < 10)
#line 44
        *tp++ = i + '0';
#line 45
        else
#line 46
        *tp++ = i + 'a' - 10;
#line 47
    }
#line 49
    int len = tp - tmp;
#line 51
    char* sp = (char*)arr->data;
#line 52
    if (sign) 
#line 53
    {
#line 54
        *sp++ = '-';
#line 55
        len++;
#line 56
    }
#line 58
    while (tp > tmp)
#line 59
    *sp++ = *--tp;
#line 61
    arr->count = len;
#line 62
    count = len;
#line 62
    _return->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    _return->offset = 0;
#line 64 "lib/sj-lib-common/i32.sj"
    _return->count = count;
#line 64
    _return->data._refCount = 1;
#line 64
    _return->data.v = vresult;
#line 64
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t count;
    void* vresult;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    vresult = 0;
#line 26
    sjs_array* arr = createarray(1, 256);
#line 27
    vresult = (void*)arr;
#line 28
    char *tmp = (char*)arr->data + 128;
#line 29
    char *tp = (char*)arr->data + 128;
#line 30
    int i;
#line 31
    unsigned v;
#line 33
    int sign = (base == 10 && val < 0);    
#line 34
    if (sign)
#line 35
    v = -val;
#line 36
    else
#line 37
    v = (unsigned)val;
#line 39
    while (v || tp == tmp)
#line 40
    {
#line 41
        i = v % base;
#line 42
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 43
        if (i < 10)
#line 44
        *tp++ = i + '0';
#line 45
        else
#line 46
        *tp++ = i + 'a' - 10;
#line 47
    }
#line 49
    int len = tp - tmp;
#line 51
    char* sp = (char*)arr->data;
#line 52
    if (sign) 
#line 53
    {
#line 54
        *sp++ = '-';
#line 55
        len++;
#line 56
    }
#line 58
    while (tp > tmp)
#line 59
    *sp++ = *--tp;
#line 61
    arr->count = len;
#line 62
    count = len;
#line 62
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 62
    (*_return)->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    (*_return)->offset = 0;
#line 64 "lib/sj-lib-common/i32.sj"
    (*_return)->count = count;
#line 64
    (*_return)->data._refCount = 1;
#line 64
    (*_return)->data.v = vresult;
#line 64
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
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

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy(_return, _parent);
    } else {
        bool sjt_capture3;
        int32_t sjt_capture4;
        sjs_array_char* sjt_parent6 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent6 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent6, &sjt_capture4);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture4) {
            int32_t sjt_capture5;
            sjs_array_char* sjt_parent7 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent7 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent7, &sjt_capture5);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture3 = ((_parent->offset + _parent->count) == sjt_capture5);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture3 = false;
        }

        if (sjt_capture3) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd2;
            int32_t sjt_forStart2;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart2 = 0;
#line 27
            sjt_forEnd2 = item->count;
#line 27
            i = sjt_forStart2;
            while (i < sjt_forEnd2) {
                char sjt_functionParam10;
                int32_t sjt_functionParam12;
                int32_t sjt_functionParam9;
                sjs_string* sjt_parent10 = 0;
                sjs_array_char* sjt_parent8 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent8 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam9 = newcount;
#line 18
                sjt_parent10 = item;
#line 27
                sjt_functionParam12 = i;
#line 27
                sjf_string_getat(sjt_parent10, sjt_functionParam12, &sjt_functionParam10);
#line 27
                sjf_array_char_initat(sjt_parent8, sjt_functionParam9, sjt_functionParam10);
#line 29
                newcount = newcount + 1;
#line 27
                i++;
            }

#line 27
            _return->_refCount = 1;
#line 32
            _return->offset = _parent->offset;
#line 32
            _return->count = newcount;
#line 32
            _return->data._refCount = 1;
#line 32
            sjf_array_char_copy(&_return->data, &_parent->data);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd3;
            int32_t sjt_forStart3;
            int32_t sjt_functionParam13;
            int32_t sjt_functionParam14;
            int32_t sjt_functionParam15;
            sjs_array_char* sjt_parent11 = 0;
            sjs_array_char* sjt_parent12 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent11 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam13 = _parent->offset;
#line 34
            sjt_functionParam14 = _parent->count;
#line 34
            sjt_functionParam15 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent11, sjt_functionParam13, sjt_functionParam14, sjt_functionParam15, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent12 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent12, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart3 = 0;
#line 37
            sjt_forEnd3 = item->count;
#line 37
            i = sjt_forStart3;
            while (i < sjt_forEnd3) {
                int32_t sjt_functionParam16;
                char sjt_functionParam17;
                int32_t sjt_functionParam18;
                sjs_array_char* sjt_parent13 = 0;
                sjs_string* sjt_parent14 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent13 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam16 = newcount;
#line 18
                sjt_parent14 = item;
#line 37
                sjt_functionParam18 = i;
#line 37
                sjf_string_getat(sjt_parent14, sjt_functionParam18, &sjt_functionParam17);
#line 37
                sjf_array_char_initat(sjt_parent13, sjt_functionParam16, sjt_functionParam17);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            _return->_refCount = 1;
#line 42
            _return->offset = 0;
#line 42
            _return->count = newcount;
#line 42
            _return->data._refCount = 1;
#line 42
            sjf_array_char_copy(&_return->data, &newdata);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy((*_return), _parent);
    } else {
        bool sjt_capture6;
        int32_t sjt_capture7;
        sjs_array_char* sjt_parent15 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent15 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent15, &sjt_capture7);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture7) {
            int32_t sjt_capture8;
            sjs_array_char* sjt_parent16 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent16 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent16, &sjt_capture8);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture6 = ((_parent->offset + _parent->count) == sjt_capture8);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture6 = false;
        }

        if (sjt_capture6) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd4;
            int32_t sjt_forStart4;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart4 = 0;
#line 27
            sjt_forEnd4 = item->count;
#line 27
            i = sjt_forStart4;
            while (i < sjt_forEnd4) {
                int32_t sjt_functionParam19;
                char sjt_functionParam20;
                int32_t sjt_functionParam21;
                sjs_array_char* sjt_parent17 = 0;
                sjs_string* sjt_parent18 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent17 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam19 = newcount;
#line 18
                sjt_parent18 = item;
#line 27
                sjt_functionParam21 = i;
#line 27
                sjf_string_getat(sjt_parent18, sjt_functionParam21, &sjt_functionParam20);
#line 27
                sjf_array_char_initat(sjt_parent17, sjt_functionParam19, sjt_functionParam20);
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
            (*_return)->offset = _parent->offset;
#line 32
            (*_return)->count = newcount;
#line 32
            (*_return)->data._refCount = 1;
#line 32
            sjf_array_char_copy(&(*_return)->data, &_parent->data);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd5;
            int32_t sjt_forStart5;
            int32_t sjt_functionParam22;
            int32_t sjt_functionParam23;
            int32_t sjt_functionParam24;
            sjs_array_char* sjt_parent19 = 0;
            sjs_array_char* sjt_parent20 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent19 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam22 = _parent->offset;
#line 34
            sjt_functionParam23 = _parent->count;
#line 34
            sjt_functionParam24 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent19, sjt_functionParam22, sjt_functionParam23, sjt_functionParam24, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent20 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent20, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart5 = 0;
#line 37
            sjt_forEnd5 = item->count;
#line 37
            i = sjt_forStart5;
            while (i < sjt_forEnd5) {
                int32_t sjt_functionParam25;
                char sjt_functionParam26;
                int32_t sjt_functionParam27;
                sjs_array_char* sjt_parent21 = 0;
                sjs_string* sjt_parent22 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent21 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam25 = newcount;
#line 18
                sjt_parent22 = item;
#line 37
                sjt_functionParam27 = i;
#line 37
                sjf_string_getat(sjt_parent22, sjt_functionParam27, &sjt_functionParam26);
#line 37
                sjf_array_char_initat(sjt_parent21, sjt_functionParam25, sjt_functionParam26);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 37
            (*_return)->_refCount = 1;
#line 42
            (*_return)->offset = 0;
#line 42
            (*_return)->count = newcount;
#line 42
            (*_return)->data._refCount = 1;
#line 42
            sjf_array_char_copy(&(*_return)->data, &newdata);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
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

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam11;
    sjs_array_char* sjt_parent9 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent9 = &_parent->data;
#line 64 "lib/sj-lib-common/string.sj"
    sjt_functionParam11 = _parent->offset + index;
#line 64
    sjf_array_char_getat(sjt_parent9, sjt_functionParam11, _return);
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
    g_c = (sjs_class*)malloc(sizeof(sjs_class));
#line 9
    g_c->_refCount = 1;
#line 7 "weak2.sj"
    g_c->x = 1;
#line 7
    sjf_class_heap(g_c);
#line 7
    g_d = (sjs_class*)malloc(sizeof(sjs_class));
#line 7
    g_d->_refCount = 1;
#line 8
    g_d->x = 2;
#line 8
    sjf_class_heap(g_d);
#line 8
    g_a._refCount = 1;
#line 9
    g_a.v = createarray(sizeof(sjs_class*), 2);
#line 9
    sjf_array_weak_class(&g_a);
#line 9
    sjs_array_weak_class* array1;
#line 9
    array1 = &g_a;
#line 9
    sjt_parent4 = array1;
#line 9
    sjt_functionParam4 = 0;
#line 9
    sjt_functionParam5 = g_c;
#line 9
    delete_cb weakptrcb5 = { &sjt_functionParam5, weakptr_clear };
#line 9
    if (sjt_functionParam5 != 0) { weakptr_cb_add(sjt_functionParam5, weakptrcb5); }
#line 9
    sjf_array_weak_class_initat(sjt_parent4, sjt_functionParam4, sjt_functionParam5);
#line 9
    sjt_parent5 = array1;
#line 9
    sjt_functionParam6 = 1;
#line 9
    sjt_functionParam7 = g_d;
#line 9
    delete_cb weakptrcb6 = { &sjt_functionParam7, weakptr_clear };
#line 9
    if (sjt_functionParam7 != 0) { weakptr_cb_add(sjt_functionParam7, weakptrcb6); }
#line 9
    sjf_array_weak_class_initat(sjt_parent5, sjt_functionParam6, sjt_functionParam7);
#line 294 "lib/sj-lib-common/array.sj"
    sjt_parent31 = &g_a;
#line 294
    sjt_call16._refCount = 1;
#line 294
    sjt_call16.offset = 0;
#line 294
    sjt_call16.count = 2;
#line 294
    sjt_call16.data._refCount = 1;
#line 294
    sjt_call16.data.v = &sjg_string1;
#line 294
    sjf_array_char(&sjt_call16.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call16._isnullterminated = false;
#line 16
    sjf_string(&sjt_call16);
#line 294 "lib/sj-lib-common/array.sj"
    sjt_functionParam44 = &sjt_call16;
#line 294
    sjf_array_weak_class_asstring(sjt_parent31, sjt_functionParam44, &sjt_call1);
#line 11 "weak2.sj"
    sjt_functionParam8 = &sjt_call1;
#line 11
    sjf_debug_writeline(sjt_functionParam8);
#line 11
    sjt_funcold6 = (sjs_class*)malloc(sizeof(sjs_class));
#line 11
    sjt_funcold6->_refCount = 1;
#line 13
    sjt_funcold6->x = 3;
#line 13
    sjf_class_heap(sjt_funcold6);
#line 13
    g_c->_refCount--;
    if (g_c->_refCount <= 0) {
        weakptr_release(g_c);
        sjf_class_destroy(g_c);
        free(g_c);
    }

#line 2
    g_c = sjt_funcold6;
#line 2
    g_c->_refCount++;
#line 294 "lib/sj-lib-common/array.sj"
    sjt_parent32 = &g_a;
#line 294
    sjt_call18._refCount = 1;
#line 294
    sjt_call18.offset = 0;
#line 294
    sjt_call18.count = 2;
#line 294
    sjt_call18.data._refCount = 1;
#line 294
    sjt_call18.data.v = &sjg_string1;
#line 294
    sjf_array_char(&sjt_call18.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call18._isnullterminated = false;
#line 16
    sjf_string(&sjt_call18);
#line 294 "lib/sj-lib-common/array.sj"
    sjt_functionParam46 = &sjt_call18;
#line 294
    sjf_array_weak_class_asstring(sjt_parent32, sjt_functionParam46, &sjt_call17);
#line 15 "weak2.sj"
    sjt_functionParam45 = &sjt_call17;
#line 15
    sjf_debug_writeline(sjt_functionParam45);
#line 15
    sjt_funcold7 = (sjs_class*)malloc(sizeof(sjs_class));
#line 15
    sjt_funcold7->_refCount = 1;
#line 17
    sjt_funcold7->x = 4;
#line 17
    sjf_class_heap(sjt_funcold7);
#line 17
    g_d->_refCount--;
    if (g_d->_refCount <= 0) {
        weakptr_release(g_d);
        sjf_class_destroy(g_d);
        free(g_d);
    }

#line 2
    g_d = sjt_funcold7;
#line 2
    g_d->_refCount++;
#line 294 "lib/sj-lib-common/array.sj"
    sjt_parent33 = &g_a;
#line 294
    sjt_call20._refCount = 1;
#line 294
    sjt_call20.offset = 0;
#line 294
    sjt_call20.count = 2;
#line 294
    sjt_call20.data._refCount = 1;
#line 294
    sjt_call20.data.v = &sjg_string1;
#line 294
    sjf_array_char(&sjt_call20.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call20._isnullterminated = false;
#line 16
    sjf_string(&sjt_call20);
#line 294 "lib/sj-lib-common/array.sj"
    sjt_functionParam48 = &sjt_call20;
#line 294
    sjf_array_weak_class_asstring(sjt_parent33, sjt_functionParam48, &sjt_call19);
#line 19 "weak2.sj"
    sjt_functionParam47 = &sjt_call19;
#line 19
    sjf_debug_writeline(sjt_functionParam47);
    main_destroy();
    return 0;
}

void main_destroy() {

    g_c->_refCount--;
    if (g_c->_refCount <= 0) {
        weakptr_release(g_c);
        sjf_class_destroy(g_c);
        free(g_c);
    }
    g_d->_refCount--;
    if (g_d->_refCount <= 0) {
        weakptr_release(g_d);
        sjf_class_destroy(g_d);
        free(g_d);
    }
    sjt_funcold6->_refCount--;
    if (sjt_funcold6->_refCount <= 0) {
        weakptr_release(sjt_funcold6);
        sjf_class_destroy(sjt_funcold6);
        free(sjt_funcold6);
    }
    sjt_funcold7->_refCount--;
    if (sjt_funcold7->_refCount <= 0) {
        weakptr_release(sjt_funcold7);
        sjf_class_destroy(sjt_funcold7);
        free(sjt_funcold7);
    }
    delete_cb weakptrcb16 = { &sjt_functionParam5, weakptr_clear };
    if (sjt_functionParam5 != 0) { weakptr_cb_remove(sjt_functionParam5, weakptrcb16); }
    delete_cb weakptrcb17 = { &sjt_functionParam7, weakptr_clear };
    if (sjt_functionParam7 != 0) { weakptr_cb_remove(sjt_functionParam7, weakptrcb17); }
    if (g_a._refCount == 1) { sjf_array_weak_class_destroy(&g_a); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
;
    if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
;
    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
;
    if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
;
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
