#include <lib/common/common.h>

const char* sjg_string1 = "hi";
const char* sjg_string2 = "hello";
const char* sjg_string3 = "good bye";
const char* sjg_string4 = "bye";
const char* sjg_string5 = "empty";

#define sjs_log_typeId 1
#define sjs_array_char_typeId 2
#define sjs_string_typeId 3
#define sjs_hash_stringstring_typeId 4

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_hash_stringstring sjs_hash_stringstring;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
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

struct td_sjs_hash_stringstring {
    int _refCount;
    void* _hash;
};

#ifndef string_string_hash_typedef
#define string_string_hash_typedef
KHASH_INIT_TYPEDEF(string_string_hash_type, sjs_string, sjs_string)
#endif
#ifndef string_string_hash_typedef
#define string_string_hash_typedef
KHASH_INIT_TYPEDEF(string_string_hash_type, sjs_string, sjs_string)
#endif
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call10 = { -1 };
sjs_string sjt_call11 = { -1 };
sjs_string sjt_call12 = { -1 };
sjs_string sjt_call13 = { -1 };
sjs_string sjt_call14 = { -1 };
sjs_string sjt_call15 = { -1 };
sjs_string sjt_call16 = { -1 };
sjs_string sjt_call17 = { -1 };
sjs_string sjt_call18 = { -1 };
sjs_string sjt_call19 = { -1 };
sjs_string sjt_call2 = { -1 };
sjs_string sjt_call20 = { -1 };
sjs_string sjt_call21 = { -1 };
sjs_string sjt_call22 = { -1 };
sjs_string sjt_call23 = { -1 };
sjs_string sjt_call24 = { -1 };
sjs_string sjt_call25 = { -1 };
sjs_string sjt_call26 = { -1 };
sjs_string sjt_call27 = { -1 };
sjs_string sjt_call28 = { -1 };
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string sjt_call6 = { -1 };
sjs_string sjt_call7 = { -1 };
sjs_string sjt_call8 = { -1 };
sjs_string sjt_call9 = { -1 };
sjs_string* sjt_functionParam10 = 0;
int32_t sjt_functionParam2;
sjs_string* sjt_functionParam20 = 0;
sjs_string* sjt_functionParam22 = 0;
int32_t sjt_functionParam23;
int32_t sjt_functionParam24;
sjs_string* sjt_functionParam25 = 0;
sjs_string* sjt_functionParam26 = 0;
sjs_string* sjt_functionParam27 = 0;
sjs_string* sjt_functionParam29 = 0;
sjs_string* sjt_functionParam3 = 0;
int32_t sjt_functionParam30;
int32_t sjt_functionParam31;
sjs_string* sjt_functionParam32 = 0;
sjs_string* sjt_functionParam33 = 0;
sjs_string* sjt_functionParam34 = 0;
sjs_string* sjt_functionParam36 = 0;
int32_t sjt_functionParam37;
int32_t sjt_functionParam38;
sjs_string* sjt_functionParam4 = 0;
sjs_string* sjt_functionParam5 = 0;
sjs_string* sjt_functionParam6 = 0;
sjs_string* sjt_parent15 = 0;
sjs_hash_stringstring* sjt_parent16 = 0;
sjs_hash_stringstring* sjt_parent18 = 0;
sjs_hash_stringstring* sjt_parent19 = 0;
sjs_hash_stringstring* sjt_parent2 = 0;
sjs_string* sjt_parent20 = 0;
sjs_hash_stringstring* sjt_parent21 = 0;
sjs_hash_stringstring* sjt_parent23 = 0;
sjs_hash_stringstring* sjt_parent24 = 0;
sjs_string* sjt_parent25 = 0;
sjs_hash_stringstring* sjt_parent26 = 0;
sjs_hash_stringstring* sjt_parent28 = 0;
sjs_hash_stringstring* sjt_parent3 = 0;
sjs_hash_stringstring* sjt_parent4 = 0;
sjs_hash_stringstring sjv_a = { -1 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_stringstring(sjs_hash_stringstring* _this);
void sjf_hash_stringstring__weakptrremovekey(sjs_hash_stringstring* _parent, sjs_string* key);
void sjf_hash_stringstring__weakptrremovevalue(sjs_hash_stringstring* _parent, sjs_string* val);
void sjf_hash_stringstring_copy(sjs_hash_stringstring* _this, sjs_hash_stringstring* _from);
void sjf_hash_stringstring_destroy(sjs_hash_stringstring* _this);
void sjf_hash_stringstring_getat(sjs_hash_stringstring* _parent, sjs_string* key, sjs_string* _return);
void sjf_hash_stringstring_getcount(sjs_hash_stringstring* _parent, int32_t* _return);
void sjf_hash_stringstring_heap(sjs_hash_stringstring* _this);
void sjf_hash_stringstring_remove(sjs_hash_stringstring* _parent, sjs_string* key);
void sjf_hash_stringstring_resize(sjs_hash_stringstring* _parent, int32_t newbuckets);
void sjf_hash_stringstring_setat(sjs_hash_stringstring* _parent, sjs_string* key, sjs_string* val);
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
void sjf_string_hash(sjs_string* _parent, uint32_t* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return);
void sjf_string_nullterminate(sjs_string* _parent);
void main_destroy(void);

#include <lib/common/common.c>
#ifndef string_string_hash_function
#define string_string_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_string_hash_type, sjs_string, sjs_string, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_string_hash_type, sjs_string, sjs_string, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
#ifndef string_string_hash_function
#define string_string_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_string_hash_type, sjs_string, sjs_string, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_string_hash_type, sjs_string, sjs_string, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
void sjf_array_char(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !true && !false
            char* p = (char*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
        }
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    char* p = (char*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        #if true
        memcpy(newp, p, sizeof(char) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
        #endif
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->isglobal = false;
    _return->count = _parent->count;
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        #if true
        memcpy(newp, p, sizeof(char) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
        #endif
    }
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->isglobal = false;
    (*_return)->count = _parent->count;
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    char* p = (char*)_parent->data;
    p[index] = item;
;
    _parent->count = index + 1;
}

void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
    if (_parent->count != test->count) {
        *_return = false;
    }
    bool result = memcmp(_parent->data, test->data, _parent->count * sizeof(char)) == 0;
    (*_return) = result;
return;;      
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent7 = 0;

    sjt_parent7 = data;
    sjf_string_nullterminate(sjt_parent7);
    debugout("%s\n", (char*)data->data.data);
}

void sjf_hash_stringstring(sjs_hash_stringstring* _this) {
    _this->_hash = kh_init(string_string_hash_type);
}

void sjf_hash_stringstring__weakptrremovekey(sjs_hash_stringstring* _parent, sjs_string* key) {
    #if false
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(string_string_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(string_string_hash_type, p, k);
    }
    #endif
}

void sjf_hash_stringstring__weakptrremovevalue(sjs_hash_stringstring* _parent, sjs_string* val) {
    #if false
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            sjs_string t = kh_value(p, k);
            if (t == val) {
                kh_del(string_string_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_stringstring_copy(sjs_hash_stringstring* _this, sjs_hash_stringstring* _from) {
    _this->_hash = _from->_hash;
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_this->_hash;
    p->refcount++;
}

void sjf_hash_stringstring_destroy(sjs_hash_stringstring* _this) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_this->_hash;
    p->refcount--;
    if (p->refcount == 0) {
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_stringstring__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_stringstring__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k), cb);
                #else
                ;
                #endif
            }
        }
        kh_destroy(string_string_hash_type, _this->_hash);
    }
}

void sjf_hash_stringstring_getat(sjs_hash_stringstring* _parent, sjs_string* key, sjs_string* _return) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_string_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_string_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        _return->_refCount = -1;
return;
    }
    _return->_refCount = 1;
sjf_string_copy(_return, (kh_val(p, k)._refCount != -1 ? &kh_val(p, k) : 0));
return;;
}

void sjf_hash_stringstring_getcount(sjs_hash_stringstring* _parent, int32_t* _return) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    int x = kh_size(p);
    (*_return) = x;
return;;
}

void sjf_hash_stringstring_heap(sjs_hash_stringstring* _this) {
    _this->_hash = kh_init(string_string_hash_type);
}

void sjf_hash_stringstring_remove(sjs_hash_stringstring* _parent, sjs_string* key) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_string_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_string_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    ;
    kh_del(string_string_hash_type, p, k);
}
}

void sjf_hash_stringstring_resize(sjs_hash_stringstring* _parent, int32_t newbuckets) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    kh_resize(string_string_hash_type, p, newbuckets);
}

void sjf_hash_stringstring_setat(sjs_hash_stringstring* _parent, sjs_string* key, sjs_string* val) {
    khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_string_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_string_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    ;
}
int ret;
#if true
k = kh_put(string_string_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(string_string_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(string_string_hash_type, p, k);
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_stringstring__weakptrremovekey };
weakptr_cb_add(key, cb);
#else
sjs_string t;
t._refCount = 1;
sjf_string_copy(&t, key);
;
#endif
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_stringstring__weakptrremovevalue };
weakptr_cb_add(val, cb);
kh_val(p, k) = val;
#else
kh_val(p, k)._refCount = 1;
sjf_string_copy(&kh_val(p, k), val);
;
#endif
}

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    *refcount = 1;
    char *tmp = (char*)sjv_data + 128;
    char *tp = (char*)sjv_data + 128;
    int i;
    unsigned v;
    int sign = (base == 10 && val < 0);    
    if (sign)
    v = -val;
    else
    v = (unsigned)val;
    while (v || tp == tmp)
    {
        i = v % base;
        v /= base; // v/=base uses less CPU clocks than v=v/base does
        if (i < 10)
        *tp++ = i + '0';
        else
        *tp++ = i + 'a' - 10;
    }
    int len = tp - tmp;
    char* sp = (char*)sjv_data;
    if (sign) 
    {
        *sp++ = '-';
        len++;
    }
    while (tp > tmp)
    *sp++ = *--tp;
    sjv_count = len;
    _return->_refCount = 1;
    _return->count = sjv_count;
    _return->data._refCount = 1;
    _return->data.datasize = 256;
    _return->data.data = sjv_data;
    _return->data.isglobal = false;
    _return->data.count = sjv_count;
    sjf_array_char(&_return->data);
    _return->_isnullterminated = false;
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    *refcount = 1;
    char *tmp = (char*)sjv_data + 128;
    char *tp = (char*)sjv_data + 128;
    int i;
    unsigned v;
    int sign = (base == 10 && val < 0);    
    if (sign)
    v = -val;
    else
    v = (unsigned)val;
    while (v || tp == tmp)
    {
        i = v % base;
        v /= base; // v/=base uses less CPU clocks than v=v/base does
        if (i < 10)
        *tp++ = i + '0';
        else
        *tp++ = i + 'a' - 10;
    }
    int len = tp - tmp;
    char* sp = (char*)sjv_data;
    if (sign) 
    {
        *sp++ = '-';
        len++;
    }
    while (tp > tmp)
    *sp++ = *--tp;
    sjv_count = len;
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = sjv_count;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 256;
    (*_return)->data.data = sjv_data;
    (*_return)->data.isglobal = false;
    (*_return)->data.count = sjv_count;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
    sjf_string_heap((*_return));
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
    _this->minlevel = _from->minlevel;
}

void sjf_log_destroy(sjs_log* _this) {
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
        _return->count = _parent->count;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&_parent->data));
        _return->_isnullterminated = false;
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam11;
            sjs_array_char* sjt_parent8 = 0;

            sjt_parent8 = &_parent->data;
            sjt_functionParam11 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent8, sjt_functionParam11, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, (&_parent->data));
        }

        sjv_newcount = _parent->count;
        sjt_forStart1 = 0;
        sjt_forEnd1 = item->count;
        i = sjt_forStart1;
        while (i < sjt_forEnd1) {
            int32_t sjt_functionParam12;
            char sjt_functionParam13;
            int32_t sjt_functionParam15;
            sjs_string* sjt_parent11 = 0;
            sjs_array_char* sjt_parent9 = 0;

            sjt_parent9 = &sjv_newdata;
            sjt_functionParam12 = sjv_newcount;
            sjt_parent11 = item;
            sjt_functionParam15 = i;
            sjf_string_getat(sjt_parent11, sjt_functionParam15, &sjt_functionParam13);
            sjf_array_char_initat(sjt_parent9, sjt_functionParam12, sjt_functionParam13);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        _return->_refCount = 1;
        _return->count = sjv_newcount;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&sjv_newdata));
        _return->_isnullterminated = false;
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
        (*_return)->count = _parent->count;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, (&_parent->data));
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam16;
            sjs_array_char* sjt_parent12 = 0;

            sjt_parent12 = &_parent->data;
            sjt_functionParam16 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent12, sjt_functionParam16, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, (&_parent->data));
        }

        sjv_newcount = _parent->count;
        sjt_forStart2 = 0;
        sjt_forEnd2 = item->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam17;
            char sjt_functionParam18;
            int32_t sjt_functionParam19;
            sjs_array_char* sjt_parent13 = 0;
            sjs_string* sjt_parent14 = 0;

            sjt_parent13 = &sjv_newdata;
            sjt_functionParam17 = sjv_newcount;
            sjt_parent14 = item;
            sjt_functionParam19 = i;
            sjf_string_getat(sjt_parent14, sjt_functionParam19, &sjt_functionParam18);
            sjf_array_char_initat(sjt_parent13, sjt_functionParam17, sjt_functionParam18);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, (&sjv_newdata));
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam14;
    sjs_array_char* sjt_parent10 = 0;

    sjt_parent10 = &_parent->data;
    sjt_functionParam14 = index;
    sjf_array_char_getat(sjt_parent10, sjt_functionParam14, _return);
}

void sjf_string_hash(sjs_string* _parent, uint32_t* _return) {
    (*_return) = kh_str_hash_func((char*)_parent->data.data);
return;;
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_array_char* sjt_functionParam1 = 0;
    sjs_array_char* sjt_parent1 = 0;

    sjt_parent1 = &_parent->data;
    sjt_functionParam1 = &test->data;
    sjf_array_char_isequal(sjt_parent1, sjt_functionParam1, _return);
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_call5 = { -1 };

    result2 = !(&_parent->data)->isglobal;
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam8;
        char sjt_functionParam9;
        sjs_array_char* sjt_parent6 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam7;
            sjs_array_char* sjt_parent5 = 0;

            sjt_parent5 = &_parent->data;
            sjt_functionParam7 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent5, sjt_functionParam7, &sjt_call5);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            _parent->data._refCount = 1;
            sjf_array_char_copy(&_parent->data, (&sjt_call5));
        }

        sjt_parent6 = &_parent->data;
        sjt_functionParam8 = _parent->count;
        sjt_functionParam9 = '\0';
        sjf_array_char_initat(sjt_parent6, sjt_functionParam8, sjt_functionParam9);
        _parent->_isnullterminated = true;
    }

    if (sjt_call5._refCount == 1) { sjf_array_char_destroy(&sjt_call5); }
;
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
    sjv_log._refCount = 1;
    sjv_log.minlevel = sjv_loglevel_warn;
    sjf_log(&sjv_log);
    sjv_emptystringdata = 0;
    sjv_emptystringdata = "";
    ptr_init();
    weakptr_init();
    sjv_clocks_per_sec = 0;
    sjv_clocks_per_sec = CLOCKS_PER_SEC;
    sjv_a._refCount = 1;
    sjf_hash_stringstring(&sjv_a);
    sjs_hash_stringstring* hash1;
    hash1 = &sjv_a;
    sjt_parent2 = hash1;
    sjt_functionParam2 = 1;
    sjf_hash_stringstring_resize(sjt_parent2, sjt_functionParam2);
    sjt_parent3 = hash1;
    sjt_call1._refCount = 1;
    sjt_call1.count = 2;
    sjt_call1.data._refCount = 1;
    sjt_call1.data.datasize = 2;
    sjt_call1.data.data = (void*)sjg_string1;
    sjt_call1.data.isglobal = true;
    sjt_call1.data.count = 2;
    sjf_array_char(&sjt_call1.data);
    sjt_call1._isnullterminated = false;
    sjf_string(&sjt_call1);
    sjt_functionParam3 = &sjt_call1;
    sjt_call2._refCount = 1;
    sjt_call2.count = 5;
    sjt_call2.data._refCount = 1;
    sjt_call2.data.datasize = 5;
    sjt_call2.data.data = (void*)sjg_string2;
    sjt_call2.data.isglobal = true;
    sjt_call2.data.count = 5;
    sjf_array_char(&sjt_call2.data);
    sjt_call2._isnullterminated = false;
    sjf_string(&sjt_call2);
    sjt_functionParam4 = &sjt_call2;
    sjf_hash_stringstring_setat(sjt_parent3, sjt_functionParam3, sjt_functionParam4);
    sjt_parent4 = hash1;
    sjt_call3._refCount = 1;
    sjt_call3.count = 3;
    sjt_call3.data._refCount = 1;
    sjt_call3.data.datasize = 3;
    sjt_call3.data.data = (void*)sjg_string4;
    sjt_call3.data.isglobal = true;
    sjt_call3.data.count = 3;
    sjf_array_char(&sjt_call3.data);
    sjt_call3._isnullterminated = false;
    sjf_string(&sjt_call3);
    sjt_functionParam5 = &sjt_call3;
    sjt_call4._refCount = 1;
    sjt_call4.count = 8;
    sjt_call4.data._refCount = 1;
    sjt_call4.data.datasize = 8;
    sjt_call4.data.data = (void*)sjg_string3;
    sjt_call4.data.isglobal = true;
    sjt_call4.data.count = 8;
    sjf_array_char(&sjt_call4.data);
    sjt_call4._isnullterminated = false;
    sjf_string(&sjt_call4);
    sjt_functionParam6 = &sjt_call4;
    sjf_hash_stringstring_setat(sjt_parent4, sjt_functionParam5, sjt_functionParam6);
    sjt_parent16 = &sjv_a;
    sjt_call8._refCount = 1;
    sjt_call8.count = 2;
    sjt_call8.data._refCount = 1;
    sjt_call8.data.datasize = 2;
    sjt_call8.data.data = (void*)sjg_string1;
    sjt_call8.data.isglobal = true;
    sjt_call8.data.count = 2;
    sjf_array_char(&sjt_call8.data);
    sjt_call8._isnullterminated = false;
    sjf_string(&sjt_call8);
    sjt_functionParam20 = &sjt_call8;
    sjf_hash_stringstring_getat(sjt_parent16, sjt_functionParam20, &sjt_call7);
    if ((sjt_call7._refCount != -1 ? &sjt_call7 : 0) != 0) {
        sjs_string* sjt_functionParam21 = 0;
        sjs_hash_stringstring* sjt_parent17 = 0;

        sjt_parent17 = &sjv_a;
        sjt_call10._refCount = 1;
        sjt_call10.count = 2;
        sjt_call10.data._refCount = 1;
        sjt_call10.data.datasize = 2;
        sjt_call10.data.data = (void*)sjg_string1;
        sjt_call10.data.isglobal = true;
        sjt_call10.data.count = 2;
        sjf_array_char(&sjt_call10.data);
        sjt_call10._isnullterminated = false;
        sjf_string(&sjt_call10);
        sjt_functionParam21 = &sjt_call10;
        sjf_hash_stringstring_getat(sjt_parent17, sjt_functionParam21, &sjt_call9);
        sjt_parent15 = (sjt_call9._refCount != -1 ? &sjt_call9 : 0);
    } else {
        sjt_call11._refCount = 1;
        sjt_call11.count = 5;
        sjt_call11.data._refCount = 1;
        sjt_call11.data.datasize = 5;
        sjt_call11.data.data = (void*)sjg_string5;
        sjt_call11.data.isglobal = true;
        sjt_call11.data.count = 5;
        sjf_array_char(&sjt_call11.data);
        sjt_call11._isnullterminated = false;
        sjf_string(&sjt_call11);
        sjt_parent15 = &sjt_call11;
    }

    sjt_parent18 = &sjv_a;
    sjf_hash_stringstring_getcount(sjt_parent18, &sjt_functionParam23);
    sjt_functionParam24 = 10;
    sjf_i32_asstring(sjt_functionParam23, sjt_functionParam24, &sjt_call12);
    sjt_functionParam22 = &sjt_call12;
    sjf_string_add(sjt_parent15, sjt_functionParam22, &sjt_call6);
    sjt_functionParam10 = &sjt_call6;
    sjf_debug_writeline(sjt_functionParam10);
    sjt_parent19 = &sjv_a;
    sjt_call13._refCount = 1;
    sjt_call13.count = 3;
    sjt_call13.data._refCount = 1;
    sjt_call13.data.datasize = 3;
    sjt_call13.data.data = (void*)sjg_string4;
    sjt_call13.data.isglobal = true;
    sjt_call13.data.count = 3;
    sjf_array_char(&sjt_call13.data);
    sjt_call13._isnullterminated = false;
    sjf_string(&sjt_call13);
    sjt_functionParam25 = &sjt_call13;
    sjf_hash_stringstring_remove(sjt_parent19, sjt_functionParam25);
    sjt_parent21 = &sjv_a;
    sjt_call16._refCount = 1;
    sjt_call16.count = 2;
    sjt_call16.data._refCount = 1;
    sjt_call16.data.datasize = 2;
    sjt_call16.data.data = (void*)sjg_string1;
    sjt_call16.data.isglobal = true;
    sjt_call16.data.count = 2;
    sjf_array_char(&sjt_call16.data);
    sjt_call16._isnullterminated = false;
    sjf_string(&sjt_call16);
    sjt_functionParam27 = &sjt_call16;
    sjf_hash_stringstring_getat(sjt_parent21, sjt_functionParam27, &sjt_call15);
    if ((sjt_call15._refCount != -1 ? &sjt_call15 : 0) != 0) {
        sjs_string* sjt_functionParam28 = 0;
        sjs_hash_stringstring* sjt_parent22 = 0;

        sjt_parent22 = &sjv_a;
        sjt_call18._refCount = 1;
        sjt_call18.count = 2;
        sjt_call18.data._refCount = 1;
        sjt_call18.data.datasize = 2;
        sjt_call18.data.data = (void*)sjg_string1;
        sjt_call18.data.isglobal = true;
        sjt_call18.data.count = 2;
        sjf_array_char(&sjt_call18.data);
        sjt_call18._isnullterminated = false;
        sjf_string(&sjt_call18);
        sjt_functionParam28 = &sjt_call18;
        sjf_hash_stringstring_getat(sjt_parent22, sjt_functionParam28, &sjt_call17);
        sjt_parent20 = (sjt_call17._refCount != -1 ? &sjt_call17 : 0);
    } else {
        sjt_call19._refCount = 1;
        sjt_call19.count = 5;
        sjt_call19.data._refCount = 1;
        sjt_call19.data.datasize = 5;
        sjt_call19.data.data = (void*)sjg_string5;
        sjt_call19.data.isglobal = true;
        sjt_call19.data.count = 5;
        sjf_array_char(&sjt_call19.data);
        sjt_call19._isnullterminated = false;
        sjf_string(&sjt_call19);
        sjt_parent20 = &sjt_call19;
    }

    sjt_parent23 = &sjv_a;
    sjf_hash_stringstring_getcount(sjt_parent23, &sjt_functionParam30);
    sjt_functionParam31 = 10;
    sjf_i32_asstring(sjt_functionParam30, sjt_functionParam31, &sjt_call20);
    sjt_functionParam29 = &sjt_call20;
    sjf_string_add(sjt_parent20, sjt_functionParam29, &sjt_call14);
    sjt_functionParam26 = &sjt_call14;
    sjf_debug_writeline(sjt_functionParam26);
    sjt_parent24 = &sjv_a;
    sjt_call21._refCount = 1;
    sjt_call21.count = 2;
    sjt_call21.data._refCount = 1;
    sjt_call21.data.datasize = 2;
    sjt_call21.data.data = (void*)sjg_string1;
    sjt_call21.data.isglobal = true;
    sjt_call21.data.count = 2;
    sjf_array_char(&sjt_call21.data);
    sjt_call21._isnullterminated = false;
    sjf_string(&sjt_call21);
    sjt_functionParam32 = &sjt_call21;
    sjf_hash_stringstring_remove(sjt_parent24, sjt_functionParam32);
    sjt_parent26 = &sjv_a;
    sjt_call24._refCount = 1;
    sjt_call24.count = 2;
    sjt_call24.data._refCount = 1;
    sjt_call24.data.datasize = 2;
    sjt_call24.data.data = (void*)sjg_string1;
    sjt_call24.data.isglobal = true;
    sjt_call24.data.count = 2;
    sjf_array_char(&sjt_call24.data);
    sjt_call24._isnullterminated = false;
    sjf_string(&sjt_call24);
    sjt_functionParam34 = &sjt_call24;
    sjf_hash_stringstring_getat(sjt_parent26, sjt_functionParam34, &sjt_call23);
    if ((sjt_call23._refCount != -1 ? &sjt_call23 : 0) != 0) {
        sjs_string* sjt_functionParam35 = 0;
        sjs_hash_stringstring* sjt_parent27 = 0;

        sjt_parent27 = &sjv_a;
        sjt_call26._refCount = 1;
        sjt_call26.count = 2;
        sjt_call26.data._refCount = 1;
        sjt_call26.data.datasize = 2;
        sjt_call26.data.data = (void*)sjg_string1;
        sjt_call26.data.isglobal = true;
        sjt_call26.data.count = 2;
        sjf_array_char(&sjt_call26.data);
        sjt_call26._isnullterminated = false;
        sjf_string(&sjt_call26);
        sjt_functionParam35 = &sjt_call26;
        sjf_hash_stringstring_getat(sjt_parent27, sjt_functionParam35, &sjt_call25);
        sjt_parent25 = (sjt_call25._refCount != -1 ? &sjt_call25 : 0);
    } else {
        sjt_call27._refCount = 1;
        sjt_call27.count = 5;
        sjt_call27.data._refCount = 1;
        sjt_call27.data.datasize = 5;
        sjt_call27.data.data = (void*)sjg_string5;
        sjt_call27.data.isglobal = true;
        sjt_call27.data.count = 5;
        sjf_array_char(&sjt_call27.data);
        sjt_call27._isnullterminated = false;
        sjf_string(&sjt_call27);
        sjt_parent25 = &sjt_call27;
    }

    sjt_parent28 = &sjv_a;
    sjf_hash_stringstring_getcount(sjt_parent28, &sjt_functionParam37);
    sjt_functionParam38 = 10;
    sjf_i32_asstring(sjt_functionParam37, sjt_functionParam38, &sjt_call28);
    sjt_functionParam36 = &sjt_call28;
    sjf_string_add(sjt_parent25, sjt_functionParam36, &sjt_call22);
    sjt_functionParam33 = &sjt_call22;
    sjf_debug_writeline(sjt_functionParam33);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
;
    if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
;
    if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
;
    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
;
    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
;
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
;
    if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
;
    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
;
    if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
;
    if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
;
    if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
;
    if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
;
    if (sjt_call23._refCount == 1) { sjf_string_destroy(&sjt_call23); }
;
    if (sjt_call24._refCount == 1) { sjf_string_destroy(&sjt_call24); }
;
    if (sjt_call25._refCount == 1) { sjf_string_destroy(&sjt_call25); }
;
    if (sjt_call26._refCount == 1) { sjf_string_destroy(&sjt_call26); }
;
    if (sjt_call27._refCount == 1) { sjf_string_destroy(&sjt_call27); }
;
    if (sjt_call28._refCount == 1) { sjf_string_destroy(&sjt_call28); }
;
    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
    if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
;
    if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
;
    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
    if (sjt_call9._refCount == 1) { sjf_string_destroy(&sjt_call9); }
;
    if (sjv_a._refCount == 1) { sjf_hash_stringstring_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
