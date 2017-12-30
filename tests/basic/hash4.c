#include <lib/common/common.h>

const char* sjg_string1 = " = ";

#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sji_interface_typeId 21
#define sjs_hash_heap_iface_interface_i32_typeId 22
#define sjs_class_typeId 27
#define cb_heap_iface_interface_i32_void_typeId 32
#define cb_heap_iface_interface_i32_void_heap_typeId 32
#define cb_local_iface_interface_i32_void_typeId 44
#define cb_local_iface_interface_i32_void_heap_typeId 44
#define sjs_array_char_typeId 37
#define sjs_string_typeId 35

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sji_interface sji_interface;
typedef struct td_sji_interface_vtbl sji_interface_vtbl;
typedef struct td_sjs_hash_heap_iface_interface_i32 sjs_hash_heap_iface_interface_i32;
typedef struct td_sjs_class sjs_class;
typedef struct td_cb_heap_iface_interface_i32_void cb_heap_iface_interface_i32_void;
typedef struct td_cb_heap_iface_interface_i32_void_heap cb_heap_iface_interface_i32_void_heap;
typedef struct td_cb_local_iface_interface_i32_void cb_local_iface_interface_i32_void;
typedef struct td_cb_local_iface_interface_i32_void_heap cb_local_iface_interface_i32_void_heap;
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

struct td_sji_interface {
    sjs_object* _parent;
    sji_interface_vtbl* _vtbl;
};

struct td_sji_interface_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*bob)(sjs_object* _parent, int32_t* _return);
    void (*hash)(sjs_object* _parent, uint32_t* _return);
    void (*isequal)(sjs_object* _parent, sji_interface b, bool* _return);
};

struct td_sjs_hash_heap_iface_interface_i32 {
    int _refCount;
    void* _hash;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

struct td_cb_heap_iface_interface_i32_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sji_interface, int32_t);
};

struct td_cb_heap_iface_interface_i32_void_heap {
    cb_heap_iface_interface_i32_void inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_local_iface_interface_i32_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sji_interface, int32_t);
};

struct td_cb_local_iface_interface_i32_void_heap {
    cb_local_iface_interface_i32_void inner;
    void (*_destroy)(sjs_object*);
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

sji_interface_vtbl sjs_class_interface_vtbl;
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef heap_iface_interface_i32_hash_typedef
#define heap_iface_interface_i32_hash_typedef
KHASH_INIT_TYPEDEF(heap_iface_interface_i32_hash_type, sji_interface, int32_t)
#endif
#ifndef heap_iface_interface_i32_hash_typedef
#define heap_iface_interface_i32_hash_typedef
KHASH_INIT_TYPEDEF(heap_iface_interface_i32_hash_type, sji_interface, int32_t)
#endif
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_class* sjt_call1 = 0;
sjs_class* sjt_call2 = 0;
sjs_string sjt_call8 = { -1 };
sjs_class* sjt_cast2 = 0;
sjs_class* sjt_cast4 = 0;
sji_interface sjt_functionParam1 = { 0 };
int32_t sjt_functionParam2;
sjs_string* sjt_functionParam24 = 0;
int32_t sjt_functionParam25;
int32_t sjt_functionParam26;
sji_interface sjt_functionParam3 = { 0 };
cb_heap_iface_interface_i32_void sjt_functionParam4;
sjs_hash_heap_iface_interface_i32* sjt_parent1 = 0;
sjs_hash_heap_iface_interface_i32* sjt_parent3 = 0;
sjs_hash_heap_iface_interface_i32* sjt_parent4 = 0;
sjs_hash_heap_iface_interface_i32 sjv_a = { -1 };
int32_option sjv_b;
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
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_class(sjs_class* _this);
void sjf_class_as_sji_interface(sjs_class* _this, sji_interface* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_bob(sjs_class* _parent, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_getclasstype(sjs_object* _this, int* _return);
void sjf_class_hash(sjs_class* _parent, uint32_t* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_class_isequal(sjs_class* _parent, sji_interface b, bool* _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_heap_iface_interface_i32(sjs_hash_heap_iface_interface_i32* _this);
void sjf_hash_heap_iface_interface_i32__weakptrremovekey(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key);
void sjf_hash_heap_iface_interface_i32__weakptrremovevalue(sjs_hash_heap_iface_interface_i32* _parent, int32_t val);
void sjf_hash_heap_iface_interface_i32_copy(sjs_hash_heap_iface_interface_i32* _this, sjs_hash_heap_iface_interface_i32* _from);
void sjf_hash_heap_iface_interface_i32_destroy(sjs_hash_heap_iface_interface_i32* _this);
void sjf_hash_heap_iface_interface_i32_each(sjs_hash_heap_iface_interface_i32* _parent, cb_heap_iface_interface_i32_void cb);
void sjf_hash_heap_iface_interface_i32_getat(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key, int32_option* _return);
void sjf_hash_heap_iface_interface_i32_heap(sjs_hash_heap_iface_interface_i32* _this);
void sjf_hash_heap_iface_interface_i32_setat(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key, int32_t val);
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
void sjf_print(sji_interface k, int32_t v);
void sjf_print_callback(void * _parent, sji_interface k, int32_t v);
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
void sji_interface_hash(sji_interface _parent, uint32_t* _return);
void sji_interface_isequal(sji_interface _parent, sji_interface b, bool* _return);
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
#ifndef heap_iface_interface_i32_hash_function
#define heap_iface_interface_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(heap_iface_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
#else
KHASH_INIT_FUNCTION(heap_iface_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
#endif
#endif
#ifndef heap_iface_interface_i32_hash_function
#define heap_iface_interface_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(heap_iface_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
#else
KHASH_INIT_FUNCTION(heap_iface_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
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

void sjf_class(sjs_class* _this) {
}

void sjf_class_as_sji_interface(sjs_class* _this, sji_interface* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_interface_vtbl;
}

void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_interface_typeId:  {
            sjf_class_as_sji_interface(_this, (sji_interface*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_class_bob(sjs_class* _parent, int32_t* _return) {
    (*_return) = _parent->x;
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_getclasstype(sjs_object* _this, int* _return) {
    *_return = 27;
}

void sjf_class_hash(sjs_class* _parent, uint32_t* _return) {
    int32_t sjt_cast3;

    sjf_class_bob(_parent, &sjt_cast3);
    (*_return) = (uint32_t)sjt_cast3;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_isequal(sjs_class* _parent, sji_interface b, bool* _return) {
    int32_t sjt_capture1;
    int32_t sjt_capture2;
    sji_interface sjt_parent2 = { 0 };

    sjf_class_bob(_parent, &sjt_capture1);
    sjt_parent2 = b;
    sjt_parent2._vtbl->bob(sjt_parent2._parent, &sjt_capture2);
    (*_return) = sjt_capture1 == sjt_capture2;
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent7 = 0;

    sjt_parent7 = data;
    sjf_string_nullterminate(sjt_parent7);
    debugout("%s\n", (char*)data->data.data);
}

void sjf_hash_heap_iface_interface_i32(sjs_hash_heap_iface_interface_i32* _this) {
    _this->_hash = kh_init(heap_iface_interface_i32_hash_type);
}

void sjf_hash_heap_iface_interface_i32__weakptrremovekey(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key) {
    #if false
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(heap_iface_interface_i32_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(heap_iface_interface_i32_hash_type, p, k);
    }
    #endif
}

void sjf_hash_heap_iface_interface_i32__weakptrremovevalue(sjs_hash_heap_iface_interface_i32* _parent, int32_t val) {
    #if false
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            int32_t t = kh_value(p, k);
            if (t == val) {
                kh_del(heap_iface_interface_i32_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_heap_iface_interface_i32_copy(sjs_hash_heap_iface_interface_i32* _this, sjs_hash_heap_iface_interface_i32* _from) {
    _this->_hash = _from->_hash;
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_this->_hash;
    p->refcount++;
}

void sjf_hash_heap_iface_interface_i32_destroy(sjs_hash_heap_iface_interface_i32* _this) {
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_this->_hash;
    p->refcount--;
    if (p->refcount == 0) {
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_heap_iface_interface_i32__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k)._parent, cb);
                #else
                if (kh_key(p, k)._parent != 0) {
    kh_key(p, k)._parent->_refCount--;
    if (kh_key(p, k)._parent->_refCount <= 0) {
        kh_key(p, k)._vtbl->destroy(kh_key(p, k)._parent);
        free(kh_key(p, k)._parent);
    }
}
;
                #endif
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_heap_iface_interface_i32__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k), cb);
                #else
                ;
                #endif
            }
        }
        kh_destroy(heap_iface_interface_i32_hash_type, _this->_hash);
    }
}

void sjf_hash_heap_iface_interface_i32_each(sjs_hash_heap_iface_interface_i32* _parent, cb_heap_iface_interface_i32_void cb) {
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            cb._cb(
            cb._parent, 
            #if false
            &kh_key(p, k), 
            #else
            kh_key(p, k), 
            #endif
            #if false
            &kh_value(p, k)
            #else
            kh_value(p, k)
            #endif
            );
        }
    }
}

void sjf_hash_heap_iface_interface_i32_getat(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key, int32_option* _return) {
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_parent->_hash;
    #if false
    khiter_t k = kh_get(heap_iface_interface_i32_hash_type, p, *key);
    #else
    khiter_t k = kh_get(heap_iface_interface_i32_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return) = int32_empty;
return;
    }
    _return->isvalid = true;
_return->value = kh_val(p, k);
return;;
}

void sjf_hash_heap_iface_interface_i32_heap(sjs_hash_heap_iface_interface_i32* _this) {
    _this->_hash = kh_init(heap_iface_interface_i32_hash_type);
}

void sjf_hash_heap_iface_interface_i32_setat(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key, int32_t val) {
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_parent->_hash;
    #if false
    khiter_t k = kh_get(heap_iface_interface_i32_hash_type, p, *key);
    #else
    khiter_t k = kh_get(heap_iface_interface_i32_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    ;
}
int ret;
#if false
k = kh_put(heap_iface_interface_i32_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(heap_iface_interface_i32_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(heap_iface_interface_i32_hash_type, p, k);
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_heap_iface_interface_i32__weakptrremovekey };
weakptr_cb_add(key._parent, cb);
#else
sji_interface t;
t = key;
if (t._parent != 0) {
    t._parent->_refCount++;
}
;
#endif
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_heap_iface_interface_i32__weakptrremovevalue };
weakptr_cb_add(val, cb);
kh_val(p, k) = val;
#else
kh_val(p, k) = val;
;
#endif
}

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

void sjf_print(sji_interface k, int32_t v) {
    sjs_string sjt_call3 = { -1 };
    sjs_string sjt_call4 = { -1 };
    sjs_string sjt_call5 = { -1 };
    sjs_string sjt_call6 = { -1 };
    sjs_string sjt_call7 = { -1 };
    int32_t sjt_functionParam18;
    int32_t sjt_functionParam19;
    sjs_string* sjt_functionParam20 = 0;
    sjs_string* sjt_functionParam21 = 0;
    int32_t sjt_functionParam22;
    int32_t sjt_functionParam23;
    sjs_string* sjt_functionParam8 = 0;
    sjs_string* sjt_parent15 = 0;
    sjs_string* sjt_parent16 = 0;
    sji_interface sjt_parent17 = { 0 };

    sjt_parent17 = k;
    sjt_parent17._vtbl->bob(sjt_parent17._parent, &sjt_functionParam18);
    sjt_functionParam19 = 10;
    sjf_i32_asstring(sjt_functionParam18, sjt_functionParam19, &sjt_call5);
    sjt_parent16 = &sjt_call5;
    sjt_call6._refCount = 1;
    sjt_call6.count = 3;
    sjt_call6.data._refCount = 1;
    sjt_call6.data.datasize = 3;
    sjt_call6.data.data = (void*)sjg_string1;
    sjt_call6.data.isglobal = true;
    sjt_call6.data.count = 3;
    sjf_array_char(&sjt_call6.data);
    sjt_call6._isnullterminated = false;
    sjf_string(&sjt_call6);
    sjt_functionParam20 = &sjt_call6;
    sjf_string_add(sjt_parent16, sjt_functionParam20, &sjt_call4);
    sjt_parent15 = &sjt_call4;
    sjt_functionParam22 = v;
    sjt_functionParam23 = 10;
    sjf_i32_asstring(sjt_functionParam22, sjt_functionParam23, &sjt_call7);
    sjt_functionParam21 = &sjt_call7;
    sjf_string_add(sjt_parent15, sjt_functionParam21, &sjt_call3);
    sjt_functionParam8 = &sjt_call3;
    sjf_debug_writeline(sjt_functionParam8);

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
}

void sjf_print_callback(void * _parent, sji_interface k, int32_t v) {
    sjf_print(k, v);
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
        _return->count = _parent->count;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, &_parent->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam9;
            sjs_array_char* sjt_parent8 = 0;

            sjt_parent8 = &_parent->data;
            sjt_functionParam9 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent8, sjt_functionParam9, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart1 = 0;
        sjt_forEnd1 = item->count;
        i = sjt_forStart1;
        while (i < sjt_forEnd1) {
            int32_t sjt_functionParam10;
            char sjt_functionParam11;
            int32_t sjt_functionParam13;
            sjs_string* sjt_parent11 = 0;
            sjs_array_char* sjt_parent9 = 0;

            sjt_parent9 = &sjv_newdata;
            sjt_functionParam10 = sjv_newcount;
            sjt_parent11 = item;
            sjt_functionParam13 = i;
            sjf_string_getat(sjt_parent11, sjt_functionParam13, &sjt_functionParam11);
            sjf_array_char_initat(sjt_parent9, sjt_functionParam10, sjt_functionParam11);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        _return->_refCount = 1;
        _return->count = sjv_newcount;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, &sjv_newdata);
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
        sjf_array_char_copy(&(*_return)->data, &_parent->data);
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam14;
            sjs_array_char* sjt_parent12 = 0;

            sjt_parent12 = &_parent->data;
            sjt_functionParam14 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent12, sjt_functionParam14, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart2 = 0;
        sjt_forEnd2 = item->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam15;
            char sjt_functionParam16;
            int32_t sjt_functionParam17;
            sjs_array_char* sjt_parent13 = 0;
            sjs_string* sjt_parent14 = 0;

            sjt_parent13 = &sjv_newdata;
            sjt_functionParam15 = sjv_newcount;
            sjt_parent14 = item;
            sjt_functionParam17 = i;
            sjf_string_getat(sjt_parent14, sjt_functionParam17, &sjt_functionParam16);
            sjf_array_char_initat(sjt_parent13, sjt_functionParam15, sjt_functionParam16);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, &sjv_newdata);
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
    int32_t sjt_functionParam12;
    sjs_array_char* sjt_parent10 = 0;

    sjt_parent10 = &_parent->data;
    sjt_functionParam12 = index;
    sjf_array_char_getat(sjt_parent10, sjt_functionParam12, _return);
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_funcold1 = { -1 };

    result2 = !(&_parent->data)->isglobal;
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam6;
        char sjt_functionParam7;
        sjs_array_char* sjt_parent6 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam5;
            sjs_array_char* sjt_parent5 = 0;

            sjt_funcold1._refCount = 1;
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
            sjt_parent5 = &_parent->data;
            sjt_functionParam5 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent5, sjt_functionParam5, &sjt_funcold1);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
        }

        sjt_parent6 = &_parent->data;
        sjt_functionParam6 = _parent->count;
        sjt_functionParam7 = '\0';
        sjf_array_char_initat(sjt_parent6, sjt_functionParam6, sjt_functionParam7);
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

    sjt_cast1 = val;
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
    (*_return) = l == r;
}

void sji_interface_hash(sji_interface _parent, uint32_t* _return) {
    _parent._vtbl->hash(_parent._parent, _return);
}

void sji_interface_isequal(sji_interface _parent, sji_interface b, bool* _return) {
    _parent._vtbl->isequal(_parent._parent, b, _return);
}

int main(int argc, char** argv) {
    sjs_class_interface_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_interface_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
    sjs_class_interface_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_class_getclasstype;
    sjs_class_interface_vtbl.bob = (void(*)(sjs_object*, int32_t*))sjf_class_bob;
    sjs_class_interface_vtbl.hash = (void(*)(sjs_object*, uint32_t*))sjf_class_hash;
    sjs_class_interface_vtbl.isequal = (void(*)(sjs_object*,sji_interface, bool*))sjf_class_isequal;
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
    sjv_a._refCount = 1;
    sjf_hash_heap_iface_interface_i32(&sjv_a);
    sjt_parent1 = &sjv_a;
    sjt_call1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjt_call1->_refCount = 1;
    sjt_call1->x = 32;
    sjf_class_heap(sjt_call1);
    sjt_cast2 = sjt_call1;
    sjf_class_as_sji_interface(sjt_cast2, &sjt_functionParam1);
    if (sjt_functionParam1._parent != 0) {
        sjt_functionParam1._parent->_refCount++;
    }

    sjt_functionParam2 = 1;
    sjf_hash_heap_iface_interface_i32_setat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent3 = &sjv_a;
    sjt_call2 = (sjs_class*)malloc(sizeof(sjs_class));
    sjt_call2->_refCount = 1;
    sjt_call2->x = 1;
    sjf_class_heap(sjt_call2);
    sjt_cast4 = sjt_call2;
    sjf_class_as_sji_interface(sjt_cast4, &sjt_functionParam3);
    if (sjt_functionParam3._parent != 0) {
        sjt_functionParam3._parent->_refCount++;
    }

    sjf_hash_heap_iface_interface_i32_getat(sjt_parent3, sjt_functionParam3, &sjv_b);
    sjt_parent4 = &sjv_a;
    sjt_functionParam4._parent = (sjs_object*)1;
    sjt_functionParam4._cb = (void(*)(sjs_object*,sji_interface,int32_t))sjf_print_callback;
    sjf_hash_heap_iface_interface_i32_each(sjt_parent4, sjt_functionParam4);
    if (sjv_b.isvalid) {
        int32_option sjt_getValue1;

        sjt_getValue1 = sjv_b;
        sjt_functionParam25 = sjt_getValue1.value;
    } else {
        int32_t result4;

        result4 = -1;
        sjt_functionParam25 = result4;
    }

    sjt_functionParam26 = 10;
    sjf_i32_asstring(sjt_functionParam25, sjt_functionParam26, &sjt_call8);
    sjt_functionParam24 = &sjt_call8;
    sjf_debug_writeline(sjt_functionParam24);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_call1->_refCount--;
    if (sjt_call1->_refCount <= 0) {
        weakptr_release(sjt_call1);
        sjf_class_destroy(sjt_call1);
        free(sjt_call1);
    }
    sjt_call2->_refCount--;
    if (sjt_call2->_refCount <= 0) {
        weakptr_release(sjt_call2);
        sjf_class_destroy(sjt_call2);
        free(sjt_call2);
    }
    if (sjt_functionParam1._parent != 0) {
        sjt_functionParam1._parent->_refCount--;
        if (sjt_functionParam1._parent->_refCount <= 0) {
            sjt_functionParam1._vtbl->destroy(sjt_functionParam1._parent);
            free(sjt_functionParam1._parent);
        }
    }
    if (sjt_functionParam3._parent != 0) {
        sjt_functionParam3._parent->_refCount--;
        if (sjt_functionParam3._parent->_refCount <= 0) {
            sjt_functionParam3._vtbl->destroy(sjt_functionParam3._parent);
            free(sjt_functionParam3._parent);
        }
    }
    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
    if (sjv_a._refCount == 1) { sjf_hash_heap_iface_interface_i32_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
}
