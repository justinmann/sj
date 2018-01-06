#include <lib/sj-lib-common/common.h>

const char* sjg_string1 = ", ";
const char* sjg_string2 = "";

#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_class_typeId 21
#define sjs_array_weak_class_typeId 22
#define sjs_array_char_typeId 27
#define sjs_string_typeId 25

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_array_weak_class sjs_array_weak_class;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

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
    int32_t x;
};

struct td_sjs_array_weak_class {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
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

sjs_array_weak_class g_a = { -1 };
sjs_class* g_c = 0;
int32_t g_clocks_per_sec;
sjs_class* g_d = 0;
void* g_emptystringdata;
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
int32_t sjt_functionParam1;
sjs_class* sjt_functionParam2 = 0;
int32_t sjt_functionParam3;
sjs_string* sjt_functionParam34 = 0;
sjs_string* sjt_functionParam35 = 0;
sjs_string* sjt_functionParam36 = 0;
sjs_string* sjt_functionParam37 = 0;
sjs_string* sjt_functionParam38 = 0;
sjs_class* sjt_functionParam4 = 0;
sjs_string* sjt_functionParam8 = 0;
sjs_array_weak_class* sjt_parent1 = 0;
sjs_array_weak_class* sjt_parent2 = 0;
sjs_array_weak_class* sjt_parent21 = 0;
sjs_array_weak_class* sjt_parent22 = 0;
sjs_array_weak_class* sjt_parent23 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_weak_class(sjs_array_weak_class* _this);
void sjf_array_weak_class_asstring(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string* _return);
void sjf_array_weak_class_asstring_heap(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string** _return);
void sjf_array_weak_class_copy(sjs_array_weak_class* _this, sjs_array_weak_class* _from);
void sjf_array_weak_class_destroy(sjs_array_weak_class* _this);
void sjf_array_weak_class_getat(sjs_array_weak_class* _parent, int32_t index, sjs_class** _return);
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
#include <lib/sj-lib-common/common.cpp>
void sjf_array_char(sjs_array_char* _this) {
#line 309 "lib/sj-lib-common/array.sj"
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

void sjf_array_char_destroy(sjs_array_char* _this) {
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
#line 9 "lib/sj-lib-common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    char* p = (char*)_parent->data;
#line 14
    #line 8 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    void* newdata;

#line 135 "lib/sj-lib-common/array.sj"
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
            #line 136 "lib/sj-lib-common/array.sj"
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

#line 135 "lib/sj-lib-common/array.sj"
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
            #line 136 "lib/sj-lib-common/array.sj"
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
#line 309 "lib/sj-lib-common/array.sj"
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
    char* p = (char*)_parent->data;
#line 44
    #line 34 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_weak_class(sjs_array_weak_class* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class*) + sizeof(int)) + 1;
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

void sjf_array_weak_class_asstring(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string* _return) {
    int32_t i;
    sjs_string result = { -1 };
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

    result._refCount = 1;
#line 259 "lib/sj-lib-common/array.sj"
    result.count = 0;
#line 259
    result.data._refCount = 1;
#line 259
    result.data.datasize = 0;
#line 259
    result.data.data = (void*)sjg_string2;
#line 259
    result.data.isglobal = true;
#line 259
    result.data.count = 0;
#line 259
    sjf_array_char(&result.data);
#line 14 "lib/sj-lib-common/string.sj"
    result._isnullterminated = false;
#line 14
    sjf_string(&result);
#line 260 "lib/sj-lib-common/array.sj"
    sjt_forStart1 = 0;
#line 260
    sjt_forEnd1 = _parent->count;
#line 260
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_class* sjt_call2 = 0;
        sjs_string sjt_call3 = { -1 };
        sjs_string sjt_call6 = { -1 };
        sjs_string sjt_call8 = { -1 };
        sjs_string* sjt_capture2 = 0;
        sjs_string sjt_funcold2 = { -1 };
        sjs_string sjt_funcold3 = { -1 };
        sjs_string* sjt_functionParam19 = 0;
        int32_t sjt_functionParam20;
        sjs_string* sjt_parent14 = 0;

        if (i != 0) {
            sjs_string* sjt_functionParam18 = 0;
            sjs_string* sjt_parent13 = 0;

            sjt_funcold2._refCount = 1;
#line 16 "lib/sj-lib-common/string.sj"
            sjf_string_copy(&sjt_funcold2, &result);
#line 16
            sjt_parent13 = &result;
#line 258 "lib/sj-lib-common/array.sj"
            sjt_functionParam18 = sep;
#line 258
            sjf_string_add(sjt_parent13, sjt_functionParam18, &sjt_funcold2);
#line 258
            if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 16 "lib/sj-lib-common/string.sj"
            sjf_string_copy(&result, &sjt_funcold2);
        }

        sjt_funcold3._refCount = 1;
#line 16 "lib/sj-lib-common/string.sj"
        sjf_string_copy(&sjt_funcold3, &result);
#line 16
        sjt_parent14 = &result;
#line 260 "lib/sj-lib-common/array.sj"
        sjt_functionParam20 = i;
#line 260
        sjf_array_weak_class_getat(_parent, sjt_functionParam20, &sjt_call2);
        if (sjt_call2 != 0) {
            sjs_class* sjt_call4 = 0;
            int32_t sjt_functionParam25;
            sjs_class* sjt_parent15 = 0;
            sjs_string* sjt_value2 = 0;

#line 260 "lib/sj-lib-common/array.sj"
            sjt_functionParam25 = i;
#line 260
            sjf_array_weak_class_getat(_parent, sjt_functionParam25, &sjt_call4);
#line 264
            sjt_parent15 = sjt_call4;
#line 264
            sjf_class_asstring(sjt_parent15, &sjt_call3);
#line 264
            sjt_value2 = &sjt_call3;
#line 264
            sjt_capture2 = sjt_value2;

            delete_cb weakptrcb8 = { &sjt_call4, weakptr_clear };
            if (sjt_call4 != 0) { weakptr_cb_remove(sjt_call4, weakptrcb8); }
        } else {
#line 264 "lib/sj-lib-common/array.sj"
            sjt_capture2 = 0;
        }

        if (sjt_capture2 != 0) {
            sjs_class* sjt_call5 = 0;
            int32_t sjt_functionParam26;

#line 260 "lib/sj-lib-common/array.sj"
            sjt_functionParam26 = i;
#line 260
            sjf_array_weak_class_getat(_parent, sjt_functionParam26, &sjt_call5);
            if (sjt_call5 != 0) {
                sjs_class* sjt_call7 = 0;
                int32_t sjt_functionParam27;
                sjs_class* sjt_parent16 = 0;
                sjs_string* sjt_value3 = 0;

#line 260 "lib/sj-lib-common/array.sj"
                sjt_functionParam27 = i;
#line 260
                sjf_array_weak_class_getat(_parent, sjt_functionParam27, &sjt_call7);
#line 264
                sjt_parent16 = sjt_call7;
#line 264
                sjf_class_asstring(sjt_parent16, &sjt_call6);
#line 264
                sjt_value3 = &sjt_call6;
#line 264
                sjt_functionParam19 = sjt_value3;

                delete_cb weakptrcb9 = { &sjt_call7, weakptr_clear };
                if (sjt_call7 != 0) { weakptr_cb_remove(sjt_call7, weakptrcb9); }
            } else {
#line 264 "lib/sj-lib-common/array.sj"
                sjt_functionParam19 = 0;
            }

            delete_cb weakptrcb10 = { &sjt_call5, weakptr_clear };
            if (sjt_call5 != 0) { weakptr_cb_remove(sjt_call5, weakptrcb10); }
        } else {
            sjt_call8._refCount = 1;
#line 264 "lib/sj-lib-common/array.sj"
            sjt_call8.count = 0;
#line 264
            sjt_call8.data._refCount = 1;
#line 264
            sjt_call8.data.datasize = 0;
#line 264
            sjt_call8.data.data = (void*)sjg_string2;
#line 264
            sjt_call8.data.isglobal = true;
#line 264
            sjt_call8.data.count = 0;
#line 264
            sjf_array_char(&sjt_call8.data);
#line 14 "lib/sj-lib-common/string.sj"
            sjt_call8._isnullterminated = false;
#line 14
            sjf_string(&sjt_call8);
#line 264 "lib/sj-lib-common/array.sj"
            sjt_functionParam19 = &sjt_call8;
        }

#line 260
        sjf_string_add(sjt_parent14, sjt_functionParam19, &sjt_funcold3);
#line 260
        if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 16 "lib/sj-lib-common/string.sj"
        sjf_string_copy(&result, &sjt_funcold3);
#line 260 "lib/sj-lib-common/array.sj"
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

#line 260
    _return->_refCount = 1;
#line 258
    sjf_string_copy(_return, &result);

    if (result._refCount == 1) { sjf_string_destroy(&result); }
;
}

void sjf_array_weak_class_asstring_heap(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string** _return) {
    int32_t i;
    sjs_string result = { -1 };
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;

    result._refCount = 1;
#line 259 "lib/sj-lib-common/array.sj"
    result.count = 0;
#line 259
    result.data._refCount = 1;
#line 259
    result.data.datasize = 0;
#line 259
    result.data.data = (void*)sjg_string2;
#line 259
    result.data.isglobal = true;
#line 259
    result.data.count = 0;
#line 259
    sjf_array_char(&result.data);
#line 14 "lib/sj-lib-common/string.sj"
    result._isnullterminated = false;
#line 14
    sjf_string(&result);
#line 260 "lib/sj-lib-common/array.sj"
    sjt_forStart4 = 0;
#line 260
    sjt_forEnd4 = _parent->count;
#line 260
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        sjs_string sjt_call10 = { -1 };
        sjs_string sjt_call13 = { -1 };
        sjs_string sjt_call15 = { -1 };
        sjs_class* sjt_call9 = 0;
        sjs_string* sjt_capture3 = 0;
        sjs_string sjt_funcold4 = { -1 };
        sjs_string sjt_funcold5 = { -1 };
        sjs_string* sjt_functionParam29 = 0;
        int32_t sjt_functionParam30;
        sjs_string* sjt_parent18 = 0;

        if (i != 0) {
            sjs_string* sjt_functionParam28 = 0;
            sjs_string* sjt_parent17 = 0;

            sjt_funcold4._refCount = 1;
#line 16 "lib/sj-lib-common/string.sj"
            sjf_string_copy(&sjt_funcold4, &result);
#line 16
            sjt_parent17 = &result;
#line 258 "lib/sj-lib-common/array.sj"
            sjt_functionParam28 = sep;
#line 258
            sjf_string_add(sjt_parent17, sjt_functionParam28, &sjt_funcold4);
#line 258
            if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 16 "lib/sj-lib-common/string.sj"
            sjf_string_copy(&result, &sjt_funcold4);
        }

        sjt_funcold5._refCount = 1;
#line 16 "lib/sj-lib-common/string.sj"
        sjf_string_copy(&sjt_funcold5, &result);
#line 16
        sjt_parent18 = &result;
#line 260 "lib/sj-lib-common/array.sj"
        sjt_functionParam30 = i;
#line 260
        sjf_array_weak_class_getat(_parent, sjt_functionParam30, &sjt_call9);
        if (sjt_call9 != 0) {
            sjs_class* sjt_call11 = 0;
            int32_t sjt_functionParam31;
            sjs_class* sjt_parent19 = 0;
            sjs_string* sjt_value4 = 0;

#line 260 "lib/sj-lib-common/array.sj"
            sjt_functionParam31 = i;
#line 260
            sjf_array_weak_class_getat(_parent, sjt_functionParam31, &sjt_call11);
#line 264
            sjt_parent19 = sjt_call11;
#line 264
            sjf_class_asstring(sjt_parent19, &sjt_call10);
#line 264
            sjt_value4 = &sjt_call10;
#line 264
            sjt_capture3 = sjt_value4;

            delete_cb weakptrcb12 = { &sjt_call11, weakptr_clear };
            if (sjt_call11 != 0) { weakptr_cb_remove(sjt_call11, weakptrcb12); }
        } else {
#line 264 "lib/sj-lib-common/array.sj"
            sjt_capture3 = 0;
        }

        if (sjt_capture3 != 0) {
            sjs_class* sjt_call12 = 0;
            int32_t sjt_functionParam32;

#line 260 "lib/sj-lib-common/array.sj"
            sjt_functionParam32 = i;
#line 260
            sjf_array_weak_class_getat(_parent, sjt_functionParam32, &sjt_call12);
            if (sjt_call12 != 0) {
                sjs_class* sjt_call14 = 0;
                int32_t sjt_functionParam33;
                sjs_class* sjt_parent20 = 0;
                sjs_string* sjt_value5 = 0;

#line 260 "lib/sj-lib-common/array.sj"
                sjt_functionParam33 = i;
#line 260
                sjf_array_weak_class_getat(_parent, sjt_functionParam33, &sjt_call14);
#line 264
                sjt_parent20 = sjt_call14;
#line 264
                sjf_class_asstring(sjt_parent20, &sjt_call13);
#line 264
                sjt_value5 = &sjt_call13;
#line 264
                sjt_functionParam29 = sjt_value5;

                delete_cb weakptrcb13 = { &sjt_call14, weakptr_clear };
                if (sjt_call14 != 0) { weakptr_cb_remove(sjt_call14, weakptrcb13); }
            } else {
#line 264 "lib/sj-lib-common/array.sj"
                sjt_functionParam29 = 0;
            }

            delete_cb weakptrcb14 = { &sjt_call12, weakptr_clear };
            if (sjt_call12 != 0) { weakptr_cb_remove(sjt_call12, weakptrcb14); }
        } else {
            sjt_call15._refCount = 1;
#line 264 "lib/sj-lib-common/array.sj"
            sjt_call15.count = 0;
#line 264
            sjt_call15.data._refCount = 1;
#line 264
            sjt_call15.data.datasize = 0;
#line 264
            sjt_call15.data.data = (void*)sjg_string2;
#line 264
            sjt_call15.data.isglobal = true;
#line 264
            sjt_call15.data.count = 0;
#line 264
            sjf_array_char(&sjt_call15.data);
#line 14 "lib/sj-lib-common/string.sj"
            sjt_call15._isnullterminated = false;
#line 14
            sjf_string(&sjt_call15);
#line 264 "lib/sj-lib-common/array.sj"
            sjt_functionParam29 = &sjt_call15;
        }

#line 260
        sjf_string_add(sjt_parent18, sjt_functionParam29, &sjt_funcold5);
#line 260
        if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 16 "lib/sj-lib-common/string.sj"
        sjf_string_copy(&result, &sjt_funcold5);
#line 260 "lib/sj-lib-common/array.sj"
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

#line 260
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 260
    (*_return)->_refCount = 1;
#line 258
    sjf_string_copy((*_return), &result);

    if (result._refCount == 1) { sjf_string_destroy(&result); }
;
}

void sjf_array_weak_class_copy(sjs_array_weak_class* _this, sjs_array_weak_class* _from) {
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

void sjf_array_weak_class_destroy(sjs_array_weak_class* _this) {
#line 333 "lib/sj-lib-common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !false && !false
#line 338
            sjs_class** p = (sjs_class**)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                delete_cb weakptrcb3 = { &p[i], weakptr_clear };
if (p[i] != 0) { weakptr_cb_remove(p[i], weakptrcb3); }
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

void sjf_array_weak_class_getat(sjs_array_weak_class* _parent, int32_t index, sjs_class** _return) {
#line 9 "lib/sj-lib-common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sjs_class** p = (sjs_class**)_parent->data;
#line 14
    #line 8 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
#line 8
delete_cb weakptrcb7 = { &(*_return), weakptr_clear };
#line 8
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb7); }
return;;       
}

void sjf_array_weak_class_heap(sjs_array_weak_class* _this) {
#line 309 "lib/sj-lib-common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class*) + sizeof(int)) + 1;
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

void sjf_array_weak_class_initat(sjs_array_weak_class* _parent, int32_t index, sjs_class* item) {
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
    sjs_class** p = (sjs_class**)_parent->data;
#line 44
    #line 34 "lib/sj-lib-common/array.sj"
p[index] = item;
#line 34
delete_cb weakptrcb4 = { &p[index], weakptr_clear };
#line 34
if (p[index] != 0) { weakptr_cb_add(p[index], weakptrcb4); }
;
#line 45
    _parent->count = index + 1;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_asstring(sjs_class* _parent, sjs_string* _return) {
    int32_t sjt_functionParam21;
    int32_t sjt_functionParam22;

#line 4 "weak2.sj"
    sjt_functionParam21 = _parent->x;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam22 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam21, sjt_functionParam22, _return);
}

void sjf_class_asstring_heap(sjs_class* _parent, sjs_string** _return) {
    int32_t sjt_functionParam23;
    int32_t sjt_functionParam24;

#line 4 "weak2.sj"
    sjt_functionParam23 = _parent->x;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam24 = 10;
#line 22
    sjf_i32_asstring_heap(sjt_functionParam23, sjt_functionParam24, _return);
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
    sjs_string* sjt_parent5 = 0;

#line 9 "lib/sj-lib-common/debug.sj"
    sjt_parent5 = data;
#line 9
    sjf_string_nullterminate(sjt_parent5);
#line 12
    debugout("%s\n", (char*)data->data.data);
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

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t count;
    void* data;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    data = 0;
#line 26
    data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 27
    int* refcount = (int*)data - 1;
#line 28
    *refcount = 1;
#line 30
    char *tmp = (char*)data + 128;
#line 31
    char *tp = (char*)data + 128;
#line 32
    int i;
#line 33
    unsigned v;
#line 35
    int sign = (base == 10 && val < 0);    
#line 36
    if (sign)
#line 37
    v = -val;
#line 38
    else
#line 39
    v = (unsigned)val;
#line 41
    while (v || tp == tmp)
#line 42
    {
#line 43
        i = v % base;
#line 44
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 45
        if (i < 10)
#line 46
        *tp++ = i + '0';
#line 47
        else
#line 48
        *tp++ = i + 'a' - 10;
#line 49
    }
#line 51
    int len = tp - tmp;
#line 53
    char* sp = (char*)data;
#line 54
    if (sign) 
#line 55
    {
#line 56
        *sp++ = '-';
#line 57
        len++;
#line 58
    }
#line 60
    while (tp > tmp)
#line 61
    *sp++ = *--tp;
#line 63
    count = len;
#line 63
    _return->_refCount = 1;
#line 65
    _return->count = count;
#line 65
    _return->data._refCount = 1;
#line 65
    _return->data.datasize = 256;
#line 65
    _return->data.data = data;
#line 4 "lib/sj-lib-common/array.sj"
    _return->data.isglobal = false;
#line 65 "lib/sj-lib-common/i32.sj"
    _return->data.count = count;
#line 65
    sjf_array_char(&_return->data);
#line 14 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t count;
    void* data;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    data = 0;
#line 26
    data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 27
    int* refcount = (int*)data - 1;
#line 28
    *refcount = 1;
#line 30
    char *tmp = (char*)data + 128;
#line 31
    char *tp = (char*)data + 128;
#line 32
    int i;
#line 33
    unsigned v;
#line 35
    int sign = (base == 10 && val < 0);    
#line 36
    if (sign)
#line 37
    v = -val;
#line 38
    else
#line 39
    v = (unsigned)val;
#line 41
    while (v || tp == tmp)
#line 42
    {
#line 43
        i = v % base;
#line 44
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 45
        if (i < 10)
#line 46
        *tp++ = i + '0';
#line 47
        else
#line 48
        *tp++ = i + 'a' - 10;
#line 49
    }
#line 51
    int len = tp - tmp;
#line 53
    char* sp = (char*)data;
#line 54
    if (sign) 
#line 55
    {
#line 56
        *sp++ = '-';
#line 57
        len++;
#line 58
    }
#line 60
    while (tp > tmp)
#line 61
    *sp++ = *--tp;
#line 63
    count = len;
#line 63
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 63
    (*_return)->_refCount = 1;
#line 65
    (*_return)->count = count;
#line 65
    (*_return)->data._refCount = 1;
#line 65
    (*_return)->data.datasize = 256;
#line 65
    (*_return)->data.data = data;
#line 4 "lib/sj-lib-common/array.sj"
    (*_return)->data.isglobal = false;
#line 65 "lib/sj-lib-common/i32.sj"
    (*_return)->data.count = count;
#line 65
    sjf_array_char(&(*_return)->data);
#line 14 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
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
#line 18 "lib/sj-lib-common/string.sj"
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
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam9;
            sjs_array_char* sjt_parent6 = 0;

#line 134 "lib/sj-lib-common/array.sj"
            sjt_parent6 = &_parent->data;
#line 21 "lib/sj-lib-common/string.sj"
            sjt_functionParam9 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent6, sjt_functionParam9, &newdata);
        } else {
            newdata._refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
            sjf_array_char_copy(&newdata, &_parent->data);
        }

#line 25 "lib/sj-lib-common/string.sj"
        newcount = _parent->count;
#line 27
        sjt_forStart2 = 0;
#line 27
        sjt_forEnd2 = item->count;
#line 27
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam10;
            char sjt_functionParam11;
            int32_t sjt_functionParam13;
            sjs_array_char* sjt_parent7 = 0;
            sjs_string* sjt_parent9 = 0;

#line 34 "lib/sj-lib-common/array.sj"
            sjt_parent7 = &newdata;
#line 28 "lib/sj-lib-common/string.sj"
            sjt_functionParam10 = newcount;
#line 16
            sjt_parent9 = item;
#line 27
            sjt_functionParam13 = i;
#line 27
            sjf_string_getat(sjt_parent9, sjt_functionParam13, &sjt_functionParam11);
#line 27
            sjf_array_char_initat(sjt_parent7, sjt_functionParam10, sjt_functionParam11);
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
#line 18 "lib/sj-lib-common/string.sj"
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
        int32_t sjt_forEnd3;
        int32_t sjt_forStart3;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam14;
            sjs_array_char* sjt_parent10 = 0;

#line 134 "lib/sj-lib-common/array.sj"
            sjt_parent10 = &_parent->data;
#line 21 "lib/sj-lib-common/string.sj"
            sjt_functionParam14 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent10, sjt_functionParam14, &newdata);
        } else {
            newdata._refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
            sjf_array_char_copy(&newdata, &_parent->data);
        }

#line 25 "lib/sj-lib-common/string.sj"
        newcount = _parent->count;
#line 27
        sjt_forStart3 = 0;
#line 27
        sjt_forEnd3 = item->count;
#line 27
        i = sjt_forStart3;
        while (i < sjt_forEnd3) {
            int32_t sjt_functionParam15;
            char sjt_functionParam16;
            int32_t sjt_functionParam17;
            sjs_array_char* sjt_parent11 = 0;
            sjs_string* sjt_parent12 = 0;

#line 34 "lib/sj-lib-common/array.sj"
            sjt_parent11 = &newdata;
#line 28 "lib/sj-lib-common/string.sj"
            sjt_functionParam15 = newcount;
#line 16
            sjt_parent12 = item;
#line 27
            sjt_functionParam17 = i;
#line 27
            sjf_string_getat(sjt_parent12, sjt_functionParam17, &sjt_functionParam16);
#line 27
            sjf_array_char_initat(sjt_parent11, sjt_functionParam15, sjt_functionParam16);
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
#line 6 "lib/sj-lib-common/string.sj"
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
    int32_t sjt_functionParam12;
    sjs_array_char* sjt_parent8 = 0;

#line 7 "lib/sj-lib-common/array.sj"
    sjt_parent8 = &_parent->data;
#line 36 "lib/sj-lib-common/string.sj"
    sjt_functionParam12 = index;
#line 36
    sjf_array_char_getat(sjt_parent8, sjt_functionParam12, _return);
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool sjt_capture1;
    sjs_array_char sjt_funcold1 = { -1 };

#line 73 "lib/sj-lib-common/string.sj"
    result2 = !(&_parent->data)->isglobal;
    if (result2) {
        bool result3;

#line 73 "lib/sj-lib-common/string.sj"
        result3 = !_parent->_isnullterminated;
#line 73
        sjt_capture1 = result3;
    } else {
#line 73 "lib/sj-lib-common/string.sj"
        sjt_capture1 = false;
    }

    if (sjt_capture1) {
        int32_t sjt_functionParam6;
        char sjt_functionParam7;
        sjs_array_char* sjt_parent4 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam5;
            sjs_array_char* sjt_parent3 = 0;

            sjt_funcold1._refCount = 1;
#line 134 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
#line 134
            sjt_parent3 = &_parent->data;
#line 75 "lib/sj-lib-common/string.sj"
            sjt_functionParam5 = _parent->count + 1;
#line 75
            sjf_array_char_grow(sjt_parent3, sjt_functionParam5, &sjt_funcold1);
#line 75
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 134 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
        }

#line 34 "lib/sj-lib-common/array.sj"
        sjt_parent4 = &_parent->data;
#line 77 "lib/sj-lib-common/string.sj"
        sjt_functionParam6 = _parent->count;
#line 77
        sjt_functionParam7 = '\0';
#line 77
        sjf_array_char_initat(sjt_parent4, sjt_functionParam6, sjt_functionParam7);
#line 78
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
    g_a.datasize = 2;
#line 3 "lib/sj-lib-common/array.sj"
    g_a.data = 0;
#line 4
    g_a.isglobal = false;
#line 5
    g_a.count = 0;
#line 5
    sjf_array_weak_class(&g_a);
#line 9 "weak2.sj"
    sjs_array_weak_class* array1;
#line 9
    array1 = &g_a;
#line 9
    sjt_parent1 = array1;
#line 9
    sjt_functionParam1 = 0;
#line 9
    sjt_functionParam2 = g_c;
#line 9
    delete_cb weakptrcb5 = { &sjt_functionParam2, weakptr_clear };
#line 9
    if (sjt_functionParam2 != 0) { weakptr_cb_add(sjt_functionParam2, weakptrcb5); }
#line 9
    sjf_array_weak_class_initat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
#line 9
    sjt_parent2 = array1;
#line 9
    sjt_functionParam3 = 1;
#line 9
    sjt_functionParam4 = g_d;
#line 9
    delete_cb weakptrcb6 = { &sjt_functionParam4, weakptr_clear };
#line 9
    if (sjt_functionParam4 != 0) { weakptr_cb_add(sjt_functionParam4, weakptrcb6); }
#line 9
    sjf_array_weak_class_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
#line 258 "lib/sj-lib-common/array.sj"
    sjt_parent21 = &g_a;
#line 258
    sjt_call16._refCount = 1;
#line 258
    sjt_call16.count = 2;
#line 258
    sjt_call16.data._refCount = 1;
#line 258
    sjt_call16.data.datasize = 2;
#line 258
    sjt_call16.data.data = (void*)sjg_string1;
#line 258
    sjt_call16.data.isglobal = true;
#line 258
    sjt_call16.data.count = 2;
#line 258
    sjf_array_char(&sjt_call16.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call16._isnullterminated = false;
#line 14
    sjf_string(&sjt_call16);
#line 258 "lib/sj-lib-common/array.sj"
    sjt_functionParam34 = &sjt_call16;
#line 258
    sjf_array_weak_class_asstring(sjt_parent21, sjt_functionParam34, &sjt_call1);
#line 11 "weak2.sj"
    sjt_functionParam8 = &sjt_call1;
#line 11
    sjf_debug_writeline(sjt_functionParam8);
#line 2
    sjt_funcold6 = g_c;
#line 2
    sjt_funcold6->_refCount++;
#line 2
    sjt_funcold6 = (sjs_class*)malloc(sizeof(sjs_class));
#line 2
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
#line 258 "lib/sj-lib-common/array.sj"
    sjt_parent22 = &g_a;
#line 258
    sjt_call18._refCount = 1;
#line 258
    sjt_call18.count = 2;
#line 258
    sjt_call18.data._refCount = 1;
#line 258
    sjt_call18.data.datasize = 2;
#line 258
    sjt_call18.data.data = (void*)sjg_string1;
#line 258
    sjt_call18.data.isglobal = true;
#line 258
    sjt_call18.data.count = 2;
#line 258
    sjf_array_char(&sjt_call18.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call18._isnullterminated = false;
#line 14
    sjf_string(&sjt_call18);
#line 258 "lib/sj-lib-common/array.sj"
    sjt_functionParam36 = &sjt_call18;
#line 258
    sjf_array_weak_class_asstring(sjt_parent22, sjt_functionParam36, &sjt_call17);
#line 15 "weak2.sj"
    sjt_functionParam35 = &sjt_call17;
#line 15
    sjf_debug_writeline(sjt_functionParam35);
#line 2
    sjt_funcold7 = g_d;
#line 2
    sjt_funcold7->_refCount++;
#line 2
    sjt_funcold7 = (sjs_class*)malloc(sizeof(sjs_class));
#line 2
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
#line 258 "lib/sj-lib-common/array.sj"
    sjt_parent23 = &g_a;
#line 258
    sjt_call20._refCount = 1;
#line 258
    sjt_call20.count = 2;
#line 258
    sjt_call20.data._refCount = 1;
#line 258
    sjt_call20.data.datasize = 2;
#line 258
    sjt_call20.data.data = (void*)sjg_string1;
#line 258
    sjt_call20.data.isglobal = true;
#line 258
    sjt_call20.data.count = 2;
#line 258
    sjf_array_char(&sjt_call20.data);
#line 14 "lib/sj-lib-common/string.sj"
    sjt_call20._isnullterminated = false;
#line 14
    sjf_string(&sjt_call20);
#line 258 "lib/sj-lib-common/array.sj"
    sjt_functionParam38 = &sjt_call20;
#line 258
    sjf_array_weak_class_asstring(sjt_parent23, sjt_functionParam38, &sjt_call19);
#line 19 "weak2.sj"
    sjt_functionParam37 = &sjt_call19;
#line 19
    sjf_debug_writeline(sjt_functionParam37);
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
    delete_cb weakptrcb16 = { &sjt_functionParam2, weakptr_clear };
    if (sjt_functionParam2 != 0) { weakptr_cb_remove(sjt_functionParam2, weakptrcb16); }
    delete_cb weakptrcb17 = { &sjt_functionParam4, weakptr_clear };
    if (sjt_functionParam4 != 0) { weakptr_cb_remove(sjt_functionParam4, weakptrcb17); }
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
