#include <lib/common/common.h>

const char* sjg_string1 = "";
const char* sjg_string2 = " kaka pipi";
const char* sjg_string3 = "timetocalc(msec): ";

#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_array_char_typeId 22
#define sjs_string_typeId 23

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
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
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t i;
int32_t result1;
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string sjt_call5 = { -1 };
int64_t sjt_cast4;
int32_t sjt_cast5;
int32_t sjt_forEnd1;
int32_t sjt_forStart1;
sjs_string* sjt_functionParam30 = 0;
sjs_string* sjt_functionParam31 = 0;
double sjt_functionParam32;
sjs_string* sjt_parent18 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
int64_t sjv_end;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
sjs_hash_type_bool sjv_log_excludeall = { -1 };
sjs_hash_type_bool sjv_log_includeall = { -1 };
int64_t sjv_start;
sjs_string sjv_str = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_char_touppercase(char x, char* _return);
void sjf_clock(int64_t* _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_f64_asstring(double val, sjs_string* _return);
void sjf_f64_asstring_heap(double val, sjs_string** _return);
void sjf_f64_pow(double x, double y, double* _return);
void sjf_f64_sqrt(double v, double* _return);
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
void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return);
void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return);
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

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    char* p = (char*)_parent->data;
#line 14
    #line 8 "lib/common/array.sj"
(*_return) = p[index];
return;;       
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

void sjf_char_touppercase(char x, char* _return) {
#line 3 "lib/common/char.sj"
    #line 2 "lib/common/char.sj"
(*_return) = toupper(x);
return;
}

void sjf_clock(int64_t* _return) {
#line 3 "lib/common/clock.sj"
    #line 2 "lib/common/clock.sj"
(*_return) = clock();
return;;
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent17 = 0;

#line 9 "lib/common/debug.sj"
    sjt_parent17 = data;
#line 9
    sjf_string_nullterminate(sjt_parent17);
#line 12
    debugout("%s\n", (char*)data->data.data);
}

void sjf_f64_asstring(double val, sjs_string* _return) {
    int32_t sjv_count;
    void* sjv_data;

#line 2 "lib/common/f64.sj"
    sjv_count = 0;
#line 3
    sjv_data = 0;
#line 5
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 6
    int* refcount = (int*)sjv_data - 1;
#line 7
    *refcount = 1;
#line 8
    snprintf((char*)sjv_data, 256, "%lf", val);
#line 9
    sjv_count = (int)strlen((char*)sjv_data);
#line 9
    _return->_refCount = 1;
#line 11
    _return->count = sjv_count;
#line 11
    _return->data._refCount = 1;
#line 11
    _return->data.datasize = sjv_count;
#line 11
    _return->data.data = sjv_data;
#line 4 "lib/common/array.sj"
    _return->data.isglobal = false;
#line 11 "lib/common/f64.sj"
    _return->data.count = sjv_count;
#line 11
    sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_f64_asstring_heap(double val, sjs_string** _return) {
    int32_t sjv_count;
    void* sjv_data;

#line 2 "lib/common/f64.sj"
    sjv_count = 0;
#line 3
    sjv_data = 0;
#line 5
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 6
    int* refcount = (int*)sjv_data - 1;
#line 7
    *refcount = 1;
#line 8
    snprintf((char*)sjv_data, 256, "%lf", val);
#line 9
    sjv_count = (int)strlen((char*)sjv_data);
#line 9
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 9
    (*_return)->_refCount = 1;
#line 11
    (*_return)->count = sjv_count;
#line 11
    (*_return)->data._refCount = 1;
#line 11
    (*_return)->data.datasize = sjv_count;
#line 11
    (*_return)->data.data = sjv_data;
#line 4 "lib/common/array.sj"
    (*_return)->data.isglobal = false;
#line 11 "lib/common/f64.sj"
    (*_return)->data.count = sjv_count;
#line 11
    sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));
}

void sjf_f64_pow(double x, double y, double* _return) {
#line 16 "lib/common/f64.sj"
    #line 15 "lib/common/f64.sj"
(*_return) = pow(x, y);
return;;
}

void sjf_f64_sqrt(double v, double* _return) {
#line 22 "lib/common/f64.sj"
    #line 21 "lib/common/f64.sj"
(*_return) = sqrt(v);
return;;
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

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
#line 18 "lib/common/string.sj"
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
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam6;
            sjs_array_char* sjt_parent1 = 0;

#line 134 "lib/common/array.sj"
            sjt_parent1 = &_parent->data;
#line 21 "lib/common/string.sj"
            sjt_functionParam6 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent1, sjt_functionParam6, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
#line 20 "lib/common/string.sj"
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

#line 25 "lib/common/string.sj"
        sjv_newcount = _parent->count;
#line 27
        sjt_forStart2 = 0;
#line 27
        sjt_forEnd2 = item->count;
#line 27
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam10;
            int32_t sjt_functionParam7;
            char sjt_functionParam8;
            sjs_array_char* sjt_parent2 = 0;
            sjs_string* sjt_parent4 = 0;

#line 34 "lib/common/array.sj"
            sjt_parent2 = &sjv_newdata;
#line 28 "lib/common/string.sj"
            sjt_functionParam7 = sjv_newcount;
#line 16
            sjt_parent4 = item;
#line 27
            sjt_functionParam10 = i;
#line 27
            sjf_string_getat(sjt_parent4, sjt_functionParam10, &sjt_functionParam8);
#line 27
            sjf_array_char_initat(sjt_parent2, sjt_functionParam7, sjt_functionParam8);
#line 29
            sjv_newcount = sjv_newcount + 1;
#line 27
            i++;
        }

#line 27
        _return->_refCount = 1;
#line 32
        _return->count = sjv_newcount;
#line 32
        _return->data._refCount = 1;
#line 32
        sjf_array_char_copy(&_return->data, &sjv_newdata);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 18 "lib/common/string.sj"
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
        int32_t sjt_forEnd3;
        int32_t sjt_forStart3;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam11;
            sjs_array_char* sjt_parent5 = 0;

#line 134 "lib/common/array.sj"
            sjt_parent5 = &_parent->data;
#line 21 "lib/common/string.sj"
            sjt_functionParam11 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent5, sjt_functionParam11, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
#line 20 "lib/common/string.sj"
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

#line 25 "lib/common/string.sj"
        sjv_newcount = _parent->count;
#line 27
        sjt_forStart3 = 0;
#line 27
        sjt_forEnd3 = item->count;
#line 27
        i = sjt_forStart3;
        while (i < sjt_forEnd3) {
            int32_t sjt_functionParam12;
            char sjt_functionParam13;
            int32_t sjt_functionParam14;
            sjs_array_char* sjt_parent6 = 0;
            sjs_string* sjt_parent7 = 0;

#line 34 "lib/common/array.sj"
            sjt_parent6 = &sjv_newdata;
#line 28 "lib/common/string.sj"
            sjt_functionParam12 = sjv_newcount;
#line 16
            sjt_parent7 = item;
#line 27
            sjt_functionParam14 = i;
#line 27
            sjf_string_getat(sjt_parent7, sjt_functionParam14, &sjt_functionParam13);
#line 27
            sjf_array_char_initat(sjt_parent6, sjt_functionParam12, sjt_functionParam13);
#line 29
            sjv_newcount = sjv_newcount + 1;
#line 27
            i++;
        }

#line 27
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 27
        (*_return)->_refCount = 1;
#line 32
        (*_return)->count = sjv_newcount;
#line 32
        (*_return)->data._refCount = 1;
#line 32
        sjf_array_char_copy(&(*_return)->data, &sjv_newdata);
#line 14
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
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

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam9;
    sjs_array_char* sjt_parent3 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent3 = &_parent->data;
#line 36 "lib/common/string.sj"
    sjt_functionParam9 = index;
#line 36
    sjf_array_char_getat(sjt_parent3, sjt_functionParam9, _return);
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_funcold3 = { -1 };

#line 73 "lib/common/string.sj"
    result2 = !(&_parent->data)->isglobal;
#line 73
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam28;
        char sjt_functionParam29;
        sjs_array_char* sjt_parent16 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam27;
            sjs_array_char* sjt_parent15 = 0;

            sjt_funcold3._refCount = 1;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&sjt_funcold3, &_parent->data);
#line 134
            sjt_parent15 = &_parent->data;
#line 75 "lib/common/string.sj"
            sjt_functionParam27 = _parent->count + 1;
#line 75
            sjf_array_char_grow(sjt_parent15, sjt_functionParam27, &sjt_funcold3);
#line 75
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold3);
        }

#line 34 "lib/common/array.sj"
        sjt_parent16 = &_parent->data;
#line 77 "lib/common/string.sj"
        sjt_functionParam28 = _parent->count;
#line 77
        sjt_functionParam29 = '\0';
#line 77
        sjf_array_char_initat(sjt_parent16, sjt_functionParam28, sjt_functionParam29);
#line 78
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold3._refCount == 1) { sjf_array_char_destroy(&sjt_funcold3); }
;
}

void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return) {
    int32_t i;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    sjs_array_char sjv_a = { -1 };

    sjv_a._refCount = 1;
#line 65 "lib/common/string.sj"
    sjv_a.datasize = (((_parent->count - 1) / 256) + 1) * 256;
#line 3 "lib/common/array.sj"
    sjv_a.data = 0;
#line 4
    sjv_a.isglobal = false;
#line 5
    sjv_a.count = 0;
#line 5
    sjf_array_char(&sjv_a);
#line 66 "lib/common/string.sj"
    sjt_forStart4 = 0;
#line 66
    sjt_forEnd4 = _parent->count;
#line 66
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        int32_t sjt_functionParam16;
        char sjt_functionParam17;
        char sjt_functionParam18;
        int32_t sjt_functionParam19;
        sjs_array_char* sjt_parent10 = 0;
        sjs_array_char* sjt_parent9 = 0;

#line 34 "lib/common/array.sj"
        sjt_parent9 = &sjv_a;
#line 66 "lib/common/string.sj"
        sjt_functionParam16 = i;
#line 7 "lib/common/array.sj"
        sjt_parent10 = &_parent->data;
#line 66 "lib/common/string.sj"
        sjt_functionParam19 = i;
#line 66
        sjf_array_char_getat(sjt_parent10, sjt_functionParam19, &sjt_functionParam18);
#line 66
        sjf_char_touppercase(sjt_functionParam18, &sjt_functionParam17);
#line 66
        sjf_array_char_initat(sjt_parent9, sjt_functionParam16, sjt_functionParam17);
#line 66
        i++;
    }

#line 66
    _return->_refCount = 1;
#line 69
    _return->count = _parent->count;
#line 69
    _return->data._refCount = 1;
#line 69
    sjf_array_char_copy(&_return->data, &sjv_a);
#line 14
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);

    if (sjv_a._refCount == 1) { sjf_array_char_destroy(&sjv_a); }
;
}

void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return) {
    int32_t i;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;
    sjs_array_char sjv_a = { -1 };

    sjv_a._refCount = 1;
#line 65 "lib/common/string.sj"
    sjv_a.datasize = (((_parent->count - 1) / 256) + 1) * 256;
#line 3 "lib/common/array.sj"
    sjv_a.data = 0;
#line 4
    sjv_a.isglobal = false;
#line 5
    sjv_a.count = 0;
#line 5
    sjf_array_char(&sjv_a);
#line 66 "lib/common/string.sj"
    sjt_forStart5 = 0;
#line 66
    sjt_forEnd5 = _parent->count;
#line 66
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        int32_t sjt_functionParam20;
        char sjt_functionParam21;
        char sjt_functionParam22;
        int32_t sjt_functionParam23;
        sjs_array_char* sjt_parent11 = 0;
        sjs_array_char* sjt_parent12 = 0;

#line 34 "lib/common/array.sj"
        sjt_parent11 = &sjv_a;
#line 66 "lib/common/string.sj"
        sjt_functionParam20 = i;
#line 7 "lib/common/array.sj"
        sjt_parent12 = &_parent->data;
#line 66 "lib/common/string.sj"
        sjt_functionParam23 = i;
#line 66
        sjf_array_char_getat(sjt_parent12, sjt_functionParam23, &sjt_functionParam22);
#line 66
        sjf_char_touppercase(sjt_functionParam22, &sjt_functionParam21);
#line 66
        sjf_array_char_initat(sjt_parent11, sjt_functionParam20, sjt_functionParam21);
#line 66
        i++;
    }

#line 66
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 66
    (*_return)->_refCount = 1;
#line 69
    (*_return)->count = _parent->count;
#line 69
    (*_return)->data._refCount = 1;
#line 69
    sjf_array_char_copy(&(*_return)->data, &sjv_a);
#line 14
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));

    if (sjv_a._refCount == 1) { sjf_array_char_destroy(&sjv_a); }
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
    sjf_clock(&sjv_start);
#line 9
    sjv_str._refCount = 1;
#line 3 "perf1.sj"
    sjv_str.count = 0;
#line 3
    sjv_str.data._refCount = 1;
#line 3
    sjv_str.data.datasize = 0;
#line 3
    sjv_str.data.data = (void*)sjg_string1;
#line 3
    sjv_str.data.isglobal = true;
#line 3
    sjv_str.data.count = 0;
#line 3
    sjf_array_char(&sjv_str.data);
#line 14 "lib/common/string.sj"
    sjv_str._isnullterminated = false;
#line 14
    sjf_string(&sjv_str);
#line 4 "perf1.sj"
    sjt_forStart1 = 0;
#line 4
    sjt_forEnd1 = 50000000;
#line 4
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_string sjt_call1 = { -1 };
        sjs_string sjt_call2 = { -1 };
        int32_t sjt_cast2;
        int32_t sjt_cast3;
        sjs_string sjt_funcold1 = { -1 };
        sjs_string sjt_funcold2 = { -1 };
        double sjt_functionParam1;
        sjs_string* sjt_functionParam15 = 0;
        double sjt_functionParam2;
        double sjt_functionParam3;
        int32_t sjt_functionParam4;
        int32_t sjt_functionParam5;
        sjs_string* sjt_parent13 = 0;
        sjs_string* sjt_parent8 = 0;
        double sjt_void1;
        double sjt_void2;
        int32_t sjv_j;
        sjs_string sjv_s1 = { -1 };
        sjs_string sjv_s2 = { -1 };
        sjs_string sjv_s3 = { -1 };

#line 4 "perf1.sj"
        sjt_cast2 = i;
#line 5
        sjt_functionParam1 = (double)sjt_cast2;
#line 5
        sjf_f64_sqrt(sjt_functionParam1, &sjt_void1);
#line 4
        sjt_cast3 = i;
#line 6
        sjt_functionParam2 = (double)sjt_cast3;
#line 6
        sjt_functionParam3 = 2.56;
#line 6
        sjf_f64_pow(sjt_functionParam2, sjt_functionParam3, &sjt_void2);
#line 7
        sjv_j = i * 745;
#line 4
        sjt_functionParam4 = i;
#line 22 "lib/common/i32.sj"
        sjt_functionParam5 = 10;
#line 22
        sjf_i32_asstring(sjt_functionParam4, sjt_functionParam5, &sjv_s1);
#line 16 "lib/common/string.sj"
        sjt_parent8 = &sjv_s1;
#line 16
        sjt_call1._refCount = 1;
#line 9 "perf1.sj"
        sjt_call1.count = 10;
#line 9
        sjt_call1.data._refCount = 1;
#line 9
        sjt_call1.data.datasize = 10;
#line 9
        sjt_call1.data.data = (void*)sjg_string2;
#line 9
        sjt_call1.data.isglobal = true;
#line 9
        sjt_call1.data.count = 10;
#line 9
        sjf_array_char(&sjt_call1.data);
#line 14 "lib/common/string.sj"
        sjt_call1._isnullterminated = false;
#line 14
        sjf_string(&sjt_call1);
#line 9 "perf1.sj"
        sjt_functionParam15 = &sjt_call1;
#line 9
        sjf_string_add(sjt_parent8, sjt_functionParam15, &sjv_s2);
#line 64 "lib/common/string.sj"
        sjt_parent13 = &sjv_s2;
#line 64
        sjf_string_touppercase(sjt_parent13, &sjv_s3);
        if ((i % 300) == 0) {
            sjt_funcold1._refCount = 1;
#line 6 "lib/common/string.sj"
            sjf_string_copy(&sjt_funcold1, &sjv_str);
#line 6
            sjt_funcold1._refCount = 1;
#line 12 "perf1.sj"
            sjt_funcold1.count = 0;
#line 12
            sjt_funcold1.data._refCount = 1;
#line 12
            sjt_funcold1.data.datasize = 0;
#line 12
            sjt_funcold1.data.data = (void*)sjg_string1;
#line 12
            sjt_funcold1.data.isglobal = true;
#line 12
            sjt_funcold1.data.count = 0;
#line 12
            sjf_array_char(&sjt_funcold1.data);
#line 14 "lib/common/string.sj"
            sjt_funcold1._isnullterminated = false;
#line 14
            sjf_string(&sjt_funcold1);
#line 14
            if (sjv_str._refCount == 1) { sjf_string_destroy(&sjv_str); }
;
#line 6
            sjf_string_copy(&sjv_str, &sjt_funcold1);
        } else {
            sjs_string* sjt_functionParam24 = 0;
            int32_t sjt_functionParam25;
            int32_t sjt_functionParam26;
            sjs_string* sjt_parent14 = 0;

            sjt_funcold2._refCount = 1;
#line 16 "lib/common/string.sj"
            sjf_string_copy(&sjt_funcold2, &sjv_str);
#line 16
            sjt_parent14 = &sjv_str;
#line 4 "perf1.sj"
            sjt_functionParam25 = i;
#line 14
            sjt_functionParam26 = 16;
#line 14
            sjf_i32_asstring(sjt_functionParam25, sjt_functionParam26, &sjt_call2);
#line 14
            sjt_functionParam24 = &sjt_call2;
#line 14
            sjf_string_add(sjt_parent14, sjt_functionParam24, &sjt_funcold2);
#line 14
            if (sjv_str._refCount == 1) { sjf_string_destroy(&sjv_str); }
;
#line 16 "lib/common/string.sj"
            sjf_string_copy(&sjv_str, &sjt_funcold2);
        }

#line 4 "perf1.sj"
        i++;

        if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
        if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
        if (sjt_funcold1._refCount == 1) { sjf_string_destroy(&sjt_funcold1); }
;
        if (sjt_funcold2._refCount == 1) { sjf_string_destroy(&sjt_funcold2); }
;
        if (sjv_s1._refCount == 1) { sjf_string_destroy(&sjv_s1); }
;
        if (sjv_s2._refCount == 1) { sjf_string_destroy(&sjv_s2); }
;
        if (sjv_s3._refCount == 1) { sjf_string_destroy(&sjv_s3); }
;
    }

#line 4
    sjf_clock(&sjv_end);
#line 4
    sjt_call4._refCount = 1;
#line 19
    sjt_call4.count = 18;
#line 19
    sjt_call4.data._refCount = 1;
#line 19
    sjt_call4.data.datasize = 18;
#line 19
    sjt_call4.data.data = (void*)sjg_string3;
#line 19
    sjt_call4.data.isglobal = true;
#line 19
    sjt_call4.data.count = 18;
#line 19
    sjf_array_char(&sjt_call4.data);
#line 14 "lib/common/string.sj"
    sjt_call4._isnullterminated = false;
#line 14
    sjf_string(&sjt_call4);
#line 19 "perf1.sj"
    sjt_parent18 = &sjt_call4;
#line 19
    sjt_cast4 = sjv_end - sjv_start;
#line 19
    sjt_cast5 = sjv_clocks_per_sec;
#line 19
    sjt_functionParam32 = ((double)sjt_cast4 * 1000.0) / (double)sjt_cast5;
#line 19
    sjf_f64_asstring(sjt_functionParam32, &sjt_call5);
#line 19
    sjt_functionParam31 = &sjt_call5;
#line 19
    sjf_string_add(sjt_parent18, sjt_functionParam31, &sjt_call3);
#line 19
    sjt_functionParam30 = &sjt_call3;
#line 19
    sjf_debug_writeline(sjt_functionParam30);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
    if (sjt_call5._refCount == 1) { sjf_string_destroy(&sjt_call5); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
    if (sjv_str._refCount == 1) { sjf_string_destroy(&sjv_str); }
;
}