#include <lib/common/common.h>

#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_class_typeId 21
#define sjs_hash_weak_class_i32_typeId 22
#define sjs_array_char_typeId 31
#define sjs_string_typeId 29

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_hash_weak_class_i32 sjs_hash_weak_class_i32;
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

struct td_sjs_hash_weak_class_i32 {
    int _refCount;
    void* _hash;
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
#ifndef weak_class_i32_hash_typedef
#define weak_class_i32_hash_typedef
KHASH_INIT_TYPEDEF(weak_class_i32_hash_type, sjs_class*, int32_t)
#endif
#ifndef weak_class_i32_hash_typedef
#define weak_class_i32_hash_typedef
KHASH_INIT_TYPEDEF(weak_class_i32_hash_type, sjs_class*, int32_t)
#endif
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call2 = { -1 };
int32_option sjt_capture1;
int32_option sjt_capture2;
sjs_class* sjt_funcold2 = 0;
sjs_class* sjt_functionParam1 = 0;
int32_t sjt_functionParam10;
sjs_string* sjt_functionParam11 = 0;
int32_t sjt_functionParam12;
sjs_class* sjt_functionParam13 = 0;
int32_t sjt_functionParam15;
int32_t sjt_functionParam2;
sjs_string* sjt_functionParam6 = 0;
int32_t sjt_functionParam7;
sjs_class* sjt_functionParam8 = 0;
sjs_hash_weak_class_i32* sjt_parent1 = 0;
sjs_hash_weak_class_i32* sjt_parent5 = 0;
sjs_hash_weak_class_i32* sjt_parent7 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };
sjs_hash_weak_class_i32 sjv_a = { -1 };
sjs_class* sjv_c = 0;
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
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_hash(sjs_class* _parent, uint32_t* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_class_isequal(sjs_class* _parent, sjs_class* c, bool* _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_hash_weak_class_i32(sjs_hash_weak_class_i32* _this);
void sjf_hash_weak_class_i32__weakptrremovekey(sjs_hash_weak_class_i32* _parent, sjs_class* key);
void sjf_hash_weak_class_i32__weakptrremovevalue(sjs_hash_weak_class_i32* _parent, int32_t val);
void sjf_hash_weak_class_i32_copy(sjs_hash_weak_class_i32* _this, sjs_hash_weak_class_i32* _from);
void sjf_hash_weak_class_i32_destroy(sjs_hash_weak_class_i32* _this);
void sjf_hash_weak_class_i32_getat(sjs_hash_weak_class_i32* _parent, sjs_class* key, int32_option* _return);
void sjf_hash_weak_class_i32_heap(sjs_hash_weak_class_i32* _this);
void sjf_hash_weak_class_i32_setat(sjs_hash_weak_class_i32* _parent, sjs_class* key, int32_t val);
void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
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
#include <lib/common/common.c>
#ifndef weak_class_i32_hash_function
#define weak_class_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(weak_class_i32_hash_type, sjs_class*, int32_t, 1, sjf_class_hash, sjf_class_isequal)
#else
KHASH_INIT_FUNCTION(weak_class_i32_hash_type, sjs_class*, int32_t, 1, sjf_class_hash, sjf_class_isequal)
#endif
#endif
#ifndef weak_class_i32_hash_function
#define weak_class_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(weak_class_i32_hash_type, sjs_class*, int32_t, 1, sjf_class_hash, sjf_class_isequal)
#else
KHASH_INIT_FUNCTION(weak_class_i32_hash_type, sjs_class*, int32_t, 1, sjf_class_hash, sjf_class_isequal)
#endif
#endif
void sjf_array_char(sjs_array_char* _this) {
#line 309 "lib/common/array.sj"
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
#line 1 "lib/common/array.sj"
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
#line 333 "lib/common/array.sj"
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

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    void* sjv_newdata;

#line 135 "lib/common/array.sj"
    sjv_newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
#line 143
        int* refcount = (int*)sjv_newdata - 1;
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
        char* newp = (char*)sjv_newdata;
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
            #line 136 "lib/common/array.sj"
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
    _return->data = sjv_newdata;
#line 4
    _return->isglobal = false;
#line 164
    _return->count = _parent->count;
#line 164
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    void* sjv_newdata;

#line 135 "lib/common/array.sj"
    sjv_newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
#line 143
        int* refcount = (int*)sjv_newdata - 1;
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
        char* newp = (char*)sjv_newdata;
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
            #line 136 "lib/common/array.sj"
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
    (*_return)->data = sjv_newdata;
#line 4
    (*_return)->isglobal = false;
#line 164
    (*_return)->count = _parent->count;
#line 164
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 309 "lib/common/array.sj"
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
#line 36 "lib/common/array.sj"
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
    #line 34 "lib/common/array.sj"
p[index] = item;
;
#line 45
    _parent->count = index + 1;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 2 "hash6.sj"
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_hash(sjs_class* _parent, uint32_t* _return) {
    int32_t sjt_cast2;

#line 5 "hash6.sj"
    sjt_cast2 = _parent->x;
#line 5
    (*_return) = (uint32_t)sjt_cast2;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_isequal(sjs_class* _parent, sjs_class* c, bool* _return) {
#line 6 "hash6.sj"
    (*_return) = _parent->x == c->x;
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent4 = 0;

#line 9 "lib/common/debug.sj"
    sjt_parent4 = data;
#line 9
    sjf_string_nullterminate(sjt_parent4);
#line 12
    debugout("%s\n", (char*)data->data.data);
}

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

void sjf_hash_weak_class_i32(sjs_hash_weak_class_i32* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(weak_class_i32_hash_type);
}

void sjf_hash_weak_class_i32__weakptrremovekey(sjs_hash_weak_class_i32* _parent, sjs_class* key) {
#line 180 "lib/common/hash.sj"
    #if true
#line 181
    khash_t(weak_class_i32_hash_type)* p = (khash_t(weak_class_i32_hash_type)*)_parent->_hash;    
#line 182
    khiter_t k = kh_get(weak_class_i32_hash_type, p, key);
#line 183
    if (k != kh_end(p)) {
#line 184
        kh_del(weak_class_i32_hash_type, p, k);
#line 185
    }
#line 186
    #endif
}

void sjf_hash_weak_class_i32__weakptrremovevalue(sjs_hash_weak_class_i32* _parent, int32_t val) {
#line 192 "lib/common/hash.sj"
    #if false
#line 193
    khash_t(weak_class_i32_hash_type)* p = (khash_t(weak_class_i32_hash_type)*)_parent->_hash;
#line 194
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 195
        if (kh_exist(p, k)) {
#line 196
            int32_t t = kh_value(p, k);
#line 197
            if (t == val) {
#line 198
                kh_del(weak_class_i32_hash_type, p, k);
#line 199
            }
#line 200
        }
#line 201
    }
#line 202
    #endif
}

void sjf_hash_weak_class_i32_copy(sjs_hash_weak_class_i32* _this, sjs_hash_weak_class_i32* _from) {
#line 230 "lib/common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(weak_class_i32_hash_type)* p = (khash_t(weak_class_i32_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_weak_class_i32_destroy(sjs_hash_weak_class_i32* _this) {
#line 236 "lib/common/hash.sj"
    khash_t(weak_class_i32_hash_type)* p = (khash_t(weak_class_i32_hash_type)*)_this->_hash;
#line 237
    p->refcount--;
#line 238
    if (p->refcount == 0) {
#line 239
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 240
            if (kh_exist(p, k)) {
#line 242
                #if true
#line 243
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_weak_class_i32__weakptrremovekey };
#line 244
                weakptr_cb_remove(kh_key(p, k), cb);
#line 245
                #else
#line 246
                delete_cb weakptrcb3 = { &kh_key(p, k), weakptr_clear };
if (kh_key(p, k) != 0) { weakptr_cb_remove(kh_key(p, k), weakptrcb3); }
;
#line 247
                #endif
#line 249
                #if false
#line 250
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_weak_class_i32__weakptrremovevalue };
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
        kh_destroy(weak_class_i32_hash_type, _this->_hash);
#line 258
    }
}

void sjf_hash_weak_class_i32_getat(sjs_hash_weak_class_i32* _parent, sjs_class* key, int32_option* _return) {
#line 23 "lib/common/hash.sj"
    khash_t(weak_class_i32_hash_type)* p = (khash_t(weak_class_i32_hash_type)*)_parent->_hash;
#line 25
    #if false
#line 26
    khiter_t k = kh_get(weak_class_i32_hash_type, p, *key);
#line 27
    #else
#line 28
    khiter_t k = kh_get(weak_class_i32_hash_type, p, key);
#line 29
    #endif
#line 31
    if (k == kh_end(p)) {
#line 32
        #line 22 "lib/common/hash.sj"
(*_return) = int32_empty;
return;
#line 33
    }
#line 34
    #line 22 "lib/common/hash.sj"
_return->isvalid = true;
#line 22
_return->value = kh_val(p, k);
return;;
}

void sjf_hash_weak_class_i32_heap(sjs_hash_weak_class_i32* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(weak_class_i32_hash_type);
}

void sjf_hash_weak_class_i32_setat(sjs_hash_weak_class_i32* _parent, sjs_class* key, int32_t val) {
#line 40 "lib/common/hash.sj"
    khash_t(weak_class_i32_hash_type)* p = (khash_t(weak_class_i32_hash_type)*)_parent->_hash;
#line 42
    #if false
#line 43
    khiter_t k = kh_get(weak_class_i32_hash_type, p, *key);
#line 44
    #else
#line 45
    khiter_t k = kh_get(weak_class_i32_hash_type, p, key);
#line 46
    #endif
#line 48
    if (k != kh_end(p)) {            
#line 49
    ;
#line 50
}
#line 52
int ret;
#line 53
#if false
#line 54
k = kh_put(weak_class_i32_hash_type, _parent->_hash, *key, &ret);
#line 55
#else
#line 56
k = kh_put(weak_class_i32_hash_type, _parent->_hash, key, &ret);
#line 57
#endif
#line 59
if (!ret) kh_del(weak_class_i32_hash_type, p, k);
#line 61
#if true
#line 62
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_weak_class_i32__weakptrremovekey };
#line 63
weakptr_cb_add(key, cb);
#line 64
#else
#line 65
sjs_class* t;
#line 66
#line 38 "lib/common/hash.sj"
t = key;
#line 38
delete_cb weakptrcb4 = { &t, weakptr_clear };
#line 38
if (t != 0) { weakptr_cb_add(t, weakptrcb4); }
;
#line 67
#endif
#line 69
#if false
#line 70
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_weak_class_i32__weakptrremovevalue };
#line 71
weakptr_cb_add(val, cb);
#line 72
kh_val(p, k) = val;
#line 73
#else
#line 74
#line 38 "lib/common/hash.sj"
kh_val(p, k) = val;
;
#line 75
#endif
}

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t sjv_count;
    void* sjv_data;

#line 23 "lib/common/i32.sj"
    sjv_count = 0;
#line 24
    sjv_data = 0;
#line 26
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 27
    int* refcount = (int*)sjv_data - 1;
#line 28
    *refcount = 1;
#line 30
    char *tmp = (char*)sjv_data + 128;
#line 31
    char *tp = (char*)sjv_data + 128;
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
    char* sp = (char*)sjv_data;
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
    sjv_count = len;
#line 63
    _return->_refCount = 1;
#line 65
    _return->count = sjv_count;
#line 65
    _return->data._refCount = 1;
#line 65
    _return->data.datasize = 256;
#line 65
    _return->data.data = sjv_data;
#line 4 "lib/common/array.sj"
    _return->data.isglobal = false;
#line 65 "lib/common/i32.sj"
    _return->data.count = sjv_count;
#line 65
    sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t sjv_count;
    void* sjv_data;

#line 23 "lib/common/i32.sj"
    sjv_count = 0;
#line 24
    sjv_data = 0;
#line 26
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 27
    int* refcount = (int*)sjv_data - 1;
#line 28
    *refcount = 1;
#line 30
    char *tmp = (char*)sjv_data + 128;
#line 31
    char *tp = (char*)sjv_data + 128;
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
    char* sp = (char*)sjv_data;
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
    sjv_count = len;
#line 63
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 63
    (*_return)->_refCount = 1;
#line 65
    (*_return)->count = sjv_count;
#line 65
    (*_return)->data._refCount = 1;
#line 65
    (*_return)->data.datasize = 256;
#line 65
    (*_return)->data.data = sjv_data;
#line 4 "lib/common/array.sj"
    (*_return)->data.isglobal = false;
#line 65 "lib/common/i32.sj"
    (*_return)->data.count = sjv_count;
#line 65
    sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));
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

void sjf_string(sjs_string* _this) {
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 6 "lib/common/string.sj"
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

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_funcold1 = { -1 };

#line 73 "lib/common/string.sj"
    result2 = !(&_parent->data)->isglobal;
#line 73
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam4;
        char sjt_functionParam5;
        sjs_array_char* sjt_parent3 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam3;
            sjs_array_char* sjt_parent2 = 0;

            sjt_funcold1._refCount = 1;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
#line 134
            sjt_parent2 = &_parent->data;
#line 75 "lib/common/string.sj"
            sjt_functionParam3 = _parent->count + 1;
#line 75
            sjf_array_char_grow(sjt_parent2, sjt_functionParam3, &sjt_funcold1);
#line 75
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
        }

#line 34 "lib/common/array.sj"
        sjt_parent3 = &_parent->data;
#line 77 "lib/common/string.sj"
        sjt_functionParam4 = _parent->count;
#line 77
        sjt_functionParam5 = '\0';
#line 77
        sjf_array_char_initat(sjt_parent3, sjt_functionParam4, sjt_functionParam5);
#line 78
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
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
    sjv_a._refCount = 1;
#line 9
    sjf_hash_weak_class_i32(&sjv_a);
#line 9
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
#line 9
    sjv_c->_refCount = 1;
#line 10 "hash6.sj"
    sjv_c->x = 1;
#line 10
    sjf_class_heap(sjv_c);
#line 38 "lib/common/hash.sj"
    sjt_parent1 = &sjv_a;
#line 11 "hash6.sj"
    sjt_functionParam1 = sjv_c;
#line 11
    delete_cb weakptrcb5 = { &sjt_functionParam1, weakptr_clear };
#line 11
    if (sjt_functionParam1 != 0) { weakptr_cb_add(sjt_functionParam1, weakptrcb5); }
#line 11
    sjt_functionParam2 = 1;
#line 11
    sjf_hash_weak_class_i32_setat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
#line 21 "lib/common/hash.sj"
    sjt_parent5 = &sjv_a;
#line 12 "hash6.sj"
    sjt_functionParam8 = sjv_c;
#line 12
    delete_cb weakptrcb6 = { &sjt_functionParam8, weakptr_clear };
#line 12
    if (sjt_functionParam8 != 0) { weakptr_cb_add(sjt_functionParam8, weakptrcb6); }
#line 12
    sjf_hash_weak_class_i32_getat(sjt_parent5, sjt_functionParam8, &sjt_capture1);
    if (sjt_capture1.isvalid) {
        sjs_class* sjt_functionParam9 = 0;
        int32_option sjt_getValue1;
        sjs_hash_weak_class_i32* sjt_parent6 = 0;

#line 21 "lib/common/hash.sj"
        sjt_parent6 = &sjv_a;
#line 12 "hash6.sj"
        sjt_functionParam9 = sjv_c;
#line 12
        delete_cb weakptrcb7 = { &sjt_functionParam9, weakptr_clear };
#line 12
        if (sjt_functionParam9 != 0) { weakptr_cb_add(sjt_functionParam9, weakptrcb7); }
#line 12
        sjf_hash_weak_class_i32_getat(sjt_parent6, sjt_functionParam9, &sjt_getValue1);
#line 12
        sjt_functionParam7 = sjt_getValue1.value;

        delete_cb weakptrcb10 = { &sjt_functionParam9, weakptr_clear };
        if (sjt_functionParam9 != 0) { weakptr_cb_remove(sjt_functionParam9, weakptrcb10); }
    } else {
        int32_t result4;

#line 12 "hash6.sj"
        result4 = -1;
#line 12
        sjt_functionParam7 = result4;
    }

#line 22 "lib/common/i32.sj"
    sjt_functionParam10 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam7, sjt_functionParam10, &sjt_call1);
#line 12 "hash6.sj"
    sjt_functionParam6 = &sjt_call1;
#line 12
    sjf_debug_writeline(sjt_functionParam6);
#line 2
    sjt_funcold2 = sjv_c;
#line 2
    sjt_funcold2->_refCount++;
#line 2
    sjt_funcold2 = (sjs_class*)malloc(sizeof(sjs_class));
#line 2
    sjt_funcold2->_refCount = 1;
#line 13
    sjt_funcold2->x = 2;
#line 13
    sjf_class_heap(sjt_funcold2);
#line 13
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }

#line 2
    sjv_c = sjt_funcold2;
#line 2
    sjv_c->_refCount++;
#line 21 "lib/common/hash.sj"
    sjt_parent7 = &sjv_a;
#line 14 "hash6.sj"
    sjt_functionParam13 = sjv_c;
#line 14
    delete_cb weakptrcb8 = { &sjt_functionParam13, weakptr_clear };
#line 14
    if (sjt_functionParam13 != 0) { weakptr_cb_add(sjt_functionParam13, weakptrcb8); }
#line 14
    sjf_hash_weak_class_i32_getat(sjt_parent7, sjt_functionParam13, &sjt_capture2);
    if (sjt_capture2.isvalid) {
        sjs_class* sjt_functionParam14 = 0;
        int32_option sjt_getValue2;
        sjs_hash_weak_class_i32* sjt_parent8 = 0;

#line 21 "lib/common/hash.sj"
        sjt_parent8 = &sjv_a;
#line 14 "hash6.sj"
        sjt_functionParam14 = sjv_c;
#line 14
        delete_cb weakptrcb9 = { &sjt_functionParam14, weakptr_clear };
#line 14
        if (sjt_functionParam14 != 0) { weakptr_cb_add(sjt_functionParam14, weakptrcb9); }
#line 14
        sjf_hash_weak_class_i32_getat(sjt_parent8, sjt_functionParam14, &sjt_getValue2);
#line 14
        sjt_functionParam12 = sjt_getValue2.value;

        delete_cb weakptrcb11 = { &sjt_functionParam14, weakptr_clear };
        if (sjt_functionParam14 != 0) { weakptr_cb_remove(sjt_functionParam14, weakptrcb11); }
    } else {
        int32_t result5;

#line 14 "hash6.sj"
        result5 = -1;
#line 14
        sjt_functionParam12 = result5;
    }

#line 22 "lib/common/i32.sj"
    sjt_functionParam15 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam12, sjt_functionParam15, &sjt_call2);
#line 14 "hash6.sj"
    sjt_functionParam11 = &sjt_call2;
#line 14
    sjf_debug_writeline(sjt_functionParam11);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_funcold2->_refCount--;
    if (sjt_funcold2->_refCount <= 0) {
        weakptr_release(sjt_funcold2);
        sjf_class_destroy(sjt_funcold2);
        free(sjt_funcold2);
    }
    delete_cb weakptrcb12 = { &sjt_functionParam1, weakptr_clear };
    if (sjt_functionParam1 != 0) { weakptr_cb_remove(sjt_functionParam1, weakptrcb12); }
    delete_cb weakptrcb13 = { &sjt_functionParam13, weakptr_clear };
    if (sjt_functionParam13 != 0) { weakptr_cb_remove(sjt_functionParam13, weakptrcb13); }
    delete_cb weakptrcb14 = { &sjt_functionParam8, weakptr_clear };
    if (sjt_functionParam8 != 0) { weakptr_cb_remove(sjt_functionParam8, weakptrcb14); }
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
    if (sjv_a._refCount == 1) { sjf_hash_weak_class_i32_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
}
