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
    bool _isglobal;
    int32_t count;
};

struct td_sjs_string {
    int _refCount;
    int32_t count;
    sjs_array_char data;
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
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string sjt_call5 = { -1 };
sjs_string sjt_call6 = { -1 };
sjs_string sjt_call7 = { -1 };
sjs_string sjt_call8 = { -1 };
sjs_string sjt_call9 = { -1 };
int32_t sjt_functionParam2;
sjs_string* sjt_functionParam27 = 0;
sjs_string* sjt_functionParam29 = 0;
sjs_string* sjt_functionParam3 = 0;
int32_t sjt_functionParam30;
sjs_string* sjt_functionParam31 = 0;
sjs_string* sjt_functionParam32 = 0;
sjs_string* sjt_functionParam33 = 0;
sjs_string* sjt_functionParam35 = 0;
int32_t sjt_functionParam36;
sjs_string* sjt_functionParam37 = 0;
sjs_string* sjt_functionParam38 = 0;
sjs_string* sjt_functionParam39 = 0;
sjs_string* sjt_functionParam4 = 0;
sjs_string* sjt_functionParam41 = 0;
int32_t sjt_functionParam42;
sjs_string* sjt_functionParam5 = 0;
sjs_string* sjt_functionParam6 = 0;
sjs_string* sjt_functionParam7 = 0;
sjs_string* sjt_parent18 = 0;
sjs_hash_stringstring* sjt_parent19 = 0;
sjs_hash_stringstring* sjt_parent2 = 0;
sjs_hash_stringstring* sjt_parent21 = 0;
sjs_hash_stringstring* sjt_parent22 = 0;
sjs_string* sjt_parent23 = 0;
sjs_hash_stringstring* sjt_parent24 = 0;
sjs_hash_stringstring* sjt_parent26 = 0;
sjs_hash_stringstring* sjt_parent27 = 0;
sjs_string* sjt_parent28 = 0;
sjs_hash_stringstring* sjt_parent29 = 0;
sjs_hash_stringstring* sjt_parent3 = 0;
sjs_hash_stringstring* sjt_parent31 = 0;
sjs_hash_stringstring* sjt_parent4 = 0;
sjs_hash_stringstring sjv_a = { -1 };
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
void sjf_array_char_setat(sjs_array_char* _parent, int32_t index, char item);
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
void sjf_i32_asstring(int32_t val, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, sjs_string** _return);
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
        _this->data = malloc(_this->datasize * sizeof(char));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            char* p = (char*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
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
        sjv_newdata = malloc(newsize * sizeof(char));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
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
        sjv_newdata = malloc(newsize * sizeof(char));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
    }
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    (*_return)->count = _parent->count;
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(char));
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

void sjf_array_char_setat(sjs_array_char* _parent, int32_t index, char item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    char* p = (char*)_parent->data;
    ;
    p[index] = item;
;
}

void sjf_debug_writeline(sjs_string* data) {
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
            if ((t == val)) {
                kh_del(string_string_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_stringstring_copy(sjs_hash_stringstring* _this, sjs_hash_stringstring* _from) {
    _this->_hash = _from->_hash;
    ptr_retain(_this->_hash);
}

void sjf_hash_stringstring_destroy(sjs_hash_stringstring* _this) {
    if (ptr_release(_this->_hash)) {
        khash_t(string_string_hash_type)* p = (khash_t(string_string_hash_type)*)_this->_hash;
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

void sjf_i32_asstring(int32_t val, sjs_string* _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = malloc(sizeof(char) * 50);
    snprintf((char*)sjv_data, 50, "%d", val);
    sjv_count = strlen((char*)sjv_data);
    _return->_refCount = 1;
    _return->count = sjv_count;
    _return->data._refCount = 1;
    _return->data.datasize = sjv_count + 1;
    _return->data.data = sjv_data;
    _return->data._isglobal = false;
    _return->data.count = sjv_count + 1;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, sjs_string** _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = malloc(sizeof(char) * 50);
    snprintf((char*)sjv_data, 50, "%d", val);
    sjv_count = strlen((char*)sjv_data);
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = sjv_count;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = sjv_count + 1;
    (*_return)->data.data = sjv_data;
    (*_return)->data._isglobal = false;
    (*_return)->data.count = sjv_count + 1;
    sjf_array_char(&(*_return)->data);
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

    if ((item->count == 0)) {
        _return->_refCount = 1;
        _return->count = _parent->count;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&_parent->data));
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_cast1;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;
        char sjt_functionParam10;
        int32_t sjt_functionParam12;
        int32_t sjt_functionParam16;
        char sjt_functionParam17;
        int32_t sjt_functionParam8;
        int32_t sjt_functionParam9;
        sjs_array_char* sjt_parent11 = 0;
        sjs_array_char* sjt_parent5 = 0;
        sjs_array_char* sjt_parent6 = 0;
        sjs_string* sjt_parent8 = 0;
        int32_t sjv_newcount;

        sjt_parent5 = &_parent->data;
        sjt_functionParam8 = (_parent->count + item->count) + 1;
        sjf_array_char_grow(sjt_parent5, sjt_functionParam8, &sjv_newdata);
        sjv_newcount = _parent->count;
        sjt_parent6 = &sjv_newdata;
        sjt_functionParam9 = sjv_newcount;
        sjt_parent8 = item;
        sjt_functionParam12 = 0;
        sjf_string_getat(sjt_parent8, sjt_functionParam12, &sjt_functionParam10);
        sjf_array_char_setat(sjt_parent6, sjt_functionParam9, sjt_functionParam10);
        sjv_newcount = sjv_newcount + 1;
        sjt_forStart1 = 1;
        sjt_forEnd1 = item->count;
        i = sjt_forStart1;
        while (i < sjt_forEnd1) {
            int32_t sjt_functionParam13;
            char sjt_functionParam14;
            int32_t sjt_functionParam15;
            sjs_string* sjt_parent10 = 0;
            sjs_array_char* sjt_parent9 = 0;

            sjt_parent9 = &sjv_newdata;
            sjt_functionParam13 = sjv_newcount;
            sjt_parent10 = item;
            sjt_functionParam15 = i;
            sjf_string_getat(sjt_parent10, sjt_functionParam15, &sjt_functionParam14);
            sjf_array_char_initat(sjt_parent9, sjt_functionParam13, sjt_functionParam14);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        sjt_parent11 = &sjv_newdata;
        sjt_functionParam16 = sjv_newcount;
        sjt_cast1 = 0;
        sjt_functionParam17 = (char)sjt_cast1;
        sjf_array_char_initat(sjt_parent11, sjt_functionParam16, sjt_functionParam17);
        _return->_refCount = 1;
        _return->count = sjv_newcount;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&sjv_newdata));
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char sjv_newdata = { -1 };

    if ((item->count == 0)) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = _parent->count;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, (&_parent->data));
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_cast2;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjt_functionParam18;
        int32_t sjt_functionParam19;
        char sjt_functionParam20;
        int32_t sjt_functionParam21;
        int32_t sjt_functionParam25;
        char sjt_functionParam26;
        sjs_array_char* sjt_parent12 = 0;
        sjs_array_char* sjt_parent13 = 0;
        sjs_string* sjt_parent14 = 0;
        sjs_array_char* sjt_parent17 = 0;
        int32_t sjv_newcount;

        sjt_parent12 = &_parent->data;
        sjt_functionParam18 = (_parent->count + item->count) + 1;
        sjf_array_char_grow(sjt_parent12, sjt_functionParam18, &sjv_newdata);
        sjv_newcount = _parent->count;
        sjt_parent13 = &sjv_newdata;
        sjt_functionParam19 = sjv_newcount;
        sjt_parent14 = item;
        sjt_functionParam21 = 0;
        sjf_string_getat(sjt_parent14, sjt_functionParam21, &sjt_functionParam20);
        sjf_array_char_setat(sjt_parent13, sjt_functionParam19, sjt_functionParam20);
        sjv_newcount = sjv_newcount + 1;
        sjt_forStart2 = 1;
        sjt_forEnd2 = item->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam22;
            char sjt_functionParam23;
            int32_t sjt_functionParam24;
            sjs_array_char* sjt_parent15 = 0;
            sjs_string* sjt_parent16 = 0;

            sjt_parent15 = &sjv_newdata;
            sjt_functionParam22 = sjv_newcount;
            sjt_parent16 = item;
            sjt_functionParam24 = i;
            sjf_string_getat(sjt_parent16, sjt_functionParam24, &sjt_functionParam23);
            sjf_array_char_initat(sjt_parent15, sjt_functionParam22, sjt_functionParam23);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        sjt_parent17 = &sjv_newdata;
        sjt_functionParam25 = sjv_newcount;
        sjt_cast2 = 0;
        sjt_functionParam26 = (char)sjt_cast2;
        sjf_array_char_initat(sjt_parent17, sjt_functionParam25, sjt_functionParam26);
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, (&sjv_newdata));
        sjf_string_heap((*_return));
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam11;
    sjs_array_char* sjt_parent7 = 0;

    sjt_parent7 = &_parent->data;
    sjt_functionParam11 = index;
    sjf_array_char_getat(sjt_parent7, sjt_functionParam11, _return);
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
    sjt_call1.data.datasize = 3;
    sjt_call1.data.data = (void*)sjg_string1;
    sjt_call1.data._isglobal = true;
    sjt_call1.data.count = 3;
    sjf_array_char(&sjt_call1.data);
    sjf_string(&sjt_call1);
    sjt_functionParam3 = &sjt_call1;
    sjt_call2._refCount = 1;
    sjt_call2.count = 5;
    sjt_call2.data._refCount = 1;
    sjt_call2.data.datasize = 6;
    sjt_call2.data.data = (void*)sjg_string2;
    sjt_call2.data._isglobal = true;
    sjt_call2.data.count = 6;
    sjf_array_char(&sjt_call2.data);
    sjf_string(&sjt_call2);
    sjt_functionParam4 = &sjt_call2;
    sjf_hash_stringstring_setat(sjt_parent3, sjt_functionParam3, sjt_functionParam4);
    sjt_parent4 = hash1;
    sjt_call3._refCount = 1;
    sjt_call3.count = 3;
    sjt_call3.data._refCount = 1;
    sjt_call3.data.datasize = 4;
    sjt_call3.data.data = (void*)sjg_string4;
    sjt_call3.data._isglobal = true;
    sjt_call3.data.count = 4;
    sjf_array_char(&sjt_call3.data);
    sjf_string(&sjt_call3);
    sjt_functionParam5 = &sjt_call3;
    sjt_call4._refCount = 1;
    sjt_call4.count = 8;
    sjt_call4.data._refCount = 1;
    sjt_call4.data.datasize = 9;
    sjt_call4.data.data = (void*)sjg_string3;
    sjt_call4.data._isglobal = true;
    sjt_call4.data.count = 9;
    sjf_array_char(&sjt_call4.data);
    sjf_string(&sjt_call4);
    sjt_functionParam6 = &sjt_call4;
    sjf_hash_stringstring_setat(sjt_parent4, sjt_functionParam5, sjt_functionParam6);
    sjt_parent19 = &sjv_a;
    sjt_call7._refCount = 1;
    sjt_call7.count = 2;
    sjt_call7.data._refCount = 1;
    sjt_call7.data.datasize = 3;
    sjt_call7.data.data = (void*)sjg_string1;
    sjt_call7.data._isglobal = true;
    sjt_call7.data.count = 3;
    sjf_array_char(&sjt_call7.data);
    sjf_string(&sjt_call7);
    sjt_functionParam27 = &sjt_call7;
    sjf_hash_stringstring_getat(sjt_parent19, sjt_functionParam27, &sjt_call6);
    if (((sjt_call6._refCount != -1 ? &sjt_call6 : 0) != 0)) {
        sjs_string* sjt_functionParam28 = 0;
        sjs_hash_stringstring* sjt_parent20 = 0;

        sjt_parent20 = &sjv_a;
        sjt_call9._refCount = 1;
        sjt_call9.count = 2;
        sjt_call9.data._refCount = 1;
        sjt_call9.data.datasize = 3;
        sjt_call9.data.data = (void*)sjg_string1;
        sjt_call9.data._isglobal = true;
        sjt_call9.data.count = 3;
        sjf_array_char(&sjt_call9.data);
        sjf_string(&sjt_call9);
        sjt_functionParam28 = &sjt_call9;
        sjf_hash_stringstring_getat(sjt_parent20, sjt_functionParam28, &sjt_call8);
        sjt_parent18 = (sjt_call8._refCount != -1 ? &sjt_call8 : 0);
    } else {
        sjt_call10._refCount = 1;
        sjt_call10.count = 5;
        sjt_call10.data._refCount = 1;
        sjt_call10.data.datasize = 6;
        sjt_call10.data.data = (void*)sjg_string5;
        sjt_call10.data._isglobal = true;
        sjt_call10.data.count = 6;
        sjf_array_char(&sjt_call10.data);
        sjf_string(&sjt_call10);
        sjt_parent18 = &sjt_call10;
    }

    sjt_parent21 = &sjv_a;
    sjf_hash_stringstring_getcount(sjt_parent21, &sjt_functionParam30);
    sjf_i32_asstring(sjt_functionParam30, &sjt_call11);
    sjt_functionParam29 = &sjt_call11;
    sjf_string_add(sjt_parent18, sjt_functionParam29, &sjt_call5);
    sjt_functionParam7 = &sjt_call5;
    sjf_debug_writeline(sjt_functionParam7);
    sjt_parent22 = &sjv_a;
    sjt_call12._refCount = 1;
    sjt_call12.count = 3;
    sjt_call12.data._refCount = 1;
    sjt_call12.data.datasize = 4;
    sjt_call12.data.data = (void*)sjg_string4;
    sjt_call12.data._isglobal = true;
    sjt_call12.data.count = 4;
    sjf_array_char(&sjt_call12.data);
    sjf_string(&sjt_call12);
    sjt_functionParam31 = &sjt_call12;
    sjf_hash_stringstring_remove(sjt_parent22, sjt_functionParam31);
    sjt_parent24 = &sjv_a;
    sjt_call15._refCount = 1;
    sjt_call15.count = 2;
    sjt_call15.data._refCount = 1;
    sjt_call15.data.datasize = 3;
    sjt_call15.data.data = (void*)sjg_string1;
    sjt_call15.data._isglobal = true;
    sjt_call15.data.count = 3;
    sjf_array_char(&sjt_call15.data);
    sjf_string(&sjt_call15);
    sjt_functionParam33 = &sjt_call15;
    sjf_hash_stringstring_getat(sjt_parent24, sjt_functionParam33, &sjt_call14);
    if (((sjt_call14._refCount != -1 ? &sjt_call14 : 0) != 0)) {
        sjs_string* sjt_functionParam34 = 0;
        sjs_hash_stringstring* sjt_parent25 = 0;

        sjt_parent25 = &sjv_a;
        sjt_call17._refCount = 1;
        sjt_call17.count = 2;
        sjt_call17.data._refCount = 1;
        sjt_call17.data.datasize = 3;
        sjt_call17.data.data = (void*)sjg_string1;
        sjt_call17.data._isglobal = true;
        sjt_call17.data.count = 3;
        sjf_array_char(&sjt_call17.data);
        sjf_string(&sjt_call17);
        sjt_functionParam34 = &sjt_call17;
        sjf_hash_stringstring_getat(sjt_parent25, sjt_functionParam34, &sjt_call16);
        sjt_parent23 = (sjt_call16._refCount != -1 ? &sjt_call16 : 0);
    } else {
        sjt_call18._refCount = 1;
        sjt_call18.count = 5;
        sjt_call18.data._refCount = 1;
        sjt_call18.data.datasize = 6;
        sjt_call18.data.data = (void*)sjg_string5;
        sjt_call18.data._isglobal = true;
        sjt_call18.data.count = 6;
        sjf_array_char(&sjt_call18.data);
        sjf_string(&sjt_call18);
        sjt_parent23 = &sjt_call18;
    }

    sjt_parent26 = &sjv_a;
    sjf_hash_stringstring_getcount(sjt_parent26, &sjt_functionParam36);
    sjf_i32_asstring(sjt_functionParam36, &sjt_call19);
    sjt_functionParam35 = &sjt_call19;
    sjf_string_add(sjt_parent23, sjt_functionParam35, &sjt_call13);
    sjt_functionParam32 = &sjt_call13;
    sjf_debug_writeline(sjt_functionParam32);
    sjt_parent27 = &sjv_a;
    sjt_call20._refCount = 1;
    sjt_call20.count = 2;
    sjt_call20.data._refCount = 1;
    sjt_call20.data.datasize = 3;
    sjt_call20.data.data = (void*)sjg_string1;
    sjt_call20.data._isglobal = true;
    sjt_call20.data.count = 3;
    sjf_array_char(&sjt_call20.data);
    sjf_string(&sjt_call20);
    sjt_functionParam37 = &sjt_call20;
    sjf_hash_stringstring_remove(sjt_parent27, sjt_functionParam37);
    sjt_parent29 = &sjv_a;
    sjt_call23._refCount = 1;
    sjt_call23.count = 2;
    sjt_call23.data._refCount = 1;
    sjt_call23.data.datasize = 3;
    sjt_call23.data.data = (void*)sjg_string1;
    sjt_call23.data._isglobal = true;
    sjt_call23.data.count = 3;
    sjf_array_char(&sjt_call23.data);
    sjf_string(&sjt_call23);
    sjt_functionParam39 = &sjt_call23;
    sjf_hash_stringstring_getat(sjt_parent29, sjt_functionParam39, &sjt_call22);
    if (((sjt_call22._refCount != -1 ? &sjt_call22 : 0) != 0)) {
        sjs_string* sjt_functionParam40 = 0;
        sjs_hash_stringstring* sjt_parent30 = 0;

        sjt_parent30 = &sjv_a;
        sjt_call25._refCount = 1;
        sjt_call25.count = 2;
        sjt_call25.data._refCount = 1;
        sjt_call25.data.datasize = 3;
        sjt_call25.data.data = (void*)sjg_string1;
        sjt_call25.data._isglobal = true;
        sjt_call25.data.count = 3;
        sjf_array_char(&sjt_call25.data);
        sjf_string(&sjt_call25);
        sjt_functionParam40 = &sjt_call25;
        sjf_hash_stringstring_getat(sjt_parent30, sjt_functionParam40, &sjt_call24);
        sjt_parent28 = (sjt_call24._refCount != -1 ? &sjt_call24 : 0);
    } else {
        sjt_call26._refCount = 1;
        sjt_call26.count = 5;
        sjt_call26.data._refCount = 1;
        sjt_call26.data.datasize = 6;
        sjt_call26.data.data = (void*)sjg_string5;
        sjt_call26.data._isglobal = true;
        sjt_call26.data.count = 6;
        sjf_array_char(&sjt_call26.data);
        sjf_string(&sjt_call26);
        sjt_parent28 = &sjt_call26;
    }

    sjt_parent31 = &sjv_a;
    sjf_hash_stringstring_getcount(sjt_parent31, &sjt_functionParam42);
    sjf_i32_asstring(sjt_functionParam42, &sjt_call27);
    sjt_functionParam41 = &sjt_call27;
    sjf_string_add(sjt_parent28, sjt_functionParam41, &sjt_call21);
    sjt_functionParam38 = &sjt_call21;
    sjf_debug_writeline(sjt_functionParam38);
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
    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
    if (sjt_call5._refCount == 1) { sjf_string_destroy(&sjt_call5); }
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
