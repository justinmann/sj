#include <lib/common/common.h>

const char* sjg_string1 = "foo";
const char* sjg_string2 = "bob";
const char* sjg_string3 = "not found";

#define sjs_log_typeId 1
#define sjs_array_char_typeId 2
#define sjs_string_typeId 3
#define sji_interface_vtbl_typeId 4
#define sji_interface_typeId 5
#define sjs_hash_string_heap_iface_interface_typeId 6
#define sjs_class_typeId 7

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sji_interface_vtbl sji_interface_vtbl;
typedef struct td_sji_interface sji_interface;
typedef struct td_sjs_hash_string_heap_iface_interface sjs_hash_string_heap_iface_interface;
typedef struct td_sjs_class sjs_class;

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

struct td_sji_interface_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*bob)(sjs_object* _parent, sjs_string* _return);
    void (*bob_heap)(sjs_object* _parent, sjs_string** _return);
};

struct td_sji_interface {
    sjs_object* _parent;
    sji_interface_vtbl* _vtbl;
};

struct td_sjs_hash_string_heap_iface_interface {
    int _refCount;
    void* _hash;
};

struct td_sjs_class {
    int _refCount;
};

sji_interface_vtbl sjs_class_interface_vtbl;
#ifndef string_heap_iface_interface_hash_typedef
#define string_heap_iface_interface_hash_typedef
KHASH_INIT_TYPEDEF(string_heap_iface_interface_hash_type, sjs_string, sji_interface)
#endif
#ifndef string_heap_iface_interface_hash_typedef
#define string_heap_iface_interface_hash_typedef
KHASH_INIT_TYPEDEF(string_heap_iface_interface_hash_type, sjs_string, sji_interface)
#endif
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_string sjt_call1 = { -1 };
sjs_class* sjt_call2 = 0;
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call5 = { -1 };
sjs_string* sjt_capture1 = 0;
sjs_class* sjt_cast1 = 0;
sjs_string* sjt_functionParam2 = 0;
sji_interface sjt_functionParam3 = { 0 };
sjs_string* sjt_functionParam4 = 0;
sjs_string* sjt_functionParam8 = 0;
sjs_hash_string_heap_iface_interface* sjt_parent2 = 0;
sjs_hash_string_heap_iface_interface* sjt_parent3 = 0;
sjs_string sjt_value1 = { -1 };
sjs_string sjt_value2 = { -1 };
sjs_hash_string_heap_iface_interface sjv_a = { -1 };
sji_interface sjv_b = { 0 };
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
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_class(sjs_class* _this);
void sjf_class_as_sji_interface(sjs_class* _this, sji_interface* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_bob(sjs_class* _parent, sjs_string* _return);
void sjf_class_bob_heap(sjs_class* _parent, sjs_string** _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_string_heap_iface_interface(sjs_hash_string_heap_iface_interface* _this);
void sjf_hash_string_heap_iface_interface__weakptrremovekey(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key);
void sjf_hash_string_heap_iface_interface__weakptrremovevalue(sjs_hash_string_heap_iface_interface* _parent, sji_interface val);
void sjf_hash_string_heap_iface_interface_copy(sjs_hash_string_heap_iface_interface* _this, sjs_hash_string_heap_iface_interface* _from);
void sjf_hash_string_heap_iface_interface_destroy(sjs_hash_string_heap_iface_interface* _this);
void sjf_hash_string_heap_iface_interface_getat_heap(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key, sji_interface* _return);
void sjf_hash_string_heap_iface_interface_heap(sjs_hash_string_heap_iface_interface* _this);
void sjf_hash_string_heap_iface_interface_setat(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key, sji_interface val);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_hash(sjs_string* _parent, uint32_t* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return);
void sjf_string_nullterminate(sjs_string* _parent);
void main_destroy(void);

#include <lib/common/common.c>
#ifndef string_heap_iface_interface_hash_function
#define string_heap_iface_interface_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_heap_iface_interface_hash_type, sjs_string, sji_interface, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_heap_iface_interface_hash_type, sjs_string, sji_interface, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
#ifndef string_heap_iface_interface_hash_function
#define string_heap_iface_interface_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_heap_iface_interface_hash_type, sjs_string, sji_interface, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_heap_iface_interface_hash_type, sjs_string, sji_interface, 1, sjf_string_hash, sjf_string_isequal)
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

void sjf_class_bob(sjs_class* _parent, sjs_string* _return) {
    _return->_refCount = 1;
    _return->count = 3;
    _return->data._refCount = 1;
    _return->data.datasize = 3;
    _return->data.data = (void*)sjg_string2;
    _return->data.isglobal = true;
    _return->data.count = 3;
    sjf_array_char(&_return->data);
    _return->_isnullterminated = false;
    sjf_string(_return);
}

void sjf_class_bob_heap(sjs_class* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = 3;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 3;
    (*_return)->data.data = (void*)sjg_string2;
    (*_return)->data.isglobal = true;
    (*_return)->data.count = 3;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
    sjf_string_heap((*_return));
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent6 = 0;

    sjt_parent6 = data;
    sjf_string_nullterminate(sjt_parent6);
    debugout("%s\n", (char*)data->data.data);
}

void sjf_hash_string_heap_iface_interface(sjs_hash_string_heap_iface_interface* _this) {
    _this->_hash = kh_init(string_heap_iface_interface_hash_type);
}

void sjf_hash_string_heap_iface_interface__weakptrremovekey(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key) {
    #if false
    khash_t(string_heap_iface_interface_hash_type)* p = (khash_t(string_heap_iface_interface_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(string_heap_iface_interface_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(string_heap_iface_interface_hash_type, p, k);
    }
    #endif
}

void sjf_hash_string_heap_iface_interface__weakptrremovevalue(sjs_hash_string_heap_iface_interface* _parent, sji_interface val) {
    #if false
    khash_t(string_heap_iface_interface_hash_type)* p = (khash_t(string_heap_iface_interface_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            sji_interface t = kh_value(p, k);
            if (t._parent == val._parent) {
                kh_del(string_heap_iface_interface_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_string_heap_iface_interface_copy(sjs_hash_string_heap_iface_interface* _this, sjs_hash_string_heap_iface_interface* _from) {
    _this->_hash = _from->_hash;
    khash_t(string_heap_iface_interface_hash_type)* p = (khash_t(string_heap_iface_interface_hash_type)*)_this->_hash;
    p->refcount++;
}

void sjf_hash_string_heap_iface_interface_destroy(sjs_hash_string_heap_iface_interface* _this) {
    khash_t(string_heap_iface_interface_hash_type)* p = (khash_t(string_heap_iface_interface_hash_type)*)_this->_hash;
    p->refcount--;
    if (p->refcount == 0) {
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_heap_iface_interface__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_heap_iface_interface__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k)._parent, cb);
                #else
                if (kh_value(p, k)._parent != 0) {
    kh_value(p, k)._parent->_refCount--;
    if (kh_value(p, k)._parent->_refCount <= 0) {
        kh_value(p, k)._vtbl->destroy(kh_value(p, k)._parent);
        free(kh_value(p, k)._parent);
    }
}
;
                #endif
            }
        }
        kh_destroy(string_heap_iface_interface_hash_type, _this->_hash);
    }
}

void sjf_hash_string_heap_iface_interface_getat_heap(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key, sji_interface* _return) {
    khash_t(string_heap_iface_interface_hash_type)* p = (khash_t(string_heap_iface_interface_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_heap_iface_interface_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_heap_iface_interface_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return)._parent = 0;
return;
    }
    (*_return) = kh_val(p, k);
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;
}

void sjf_hash_string_heap_iface_interface_heap(sjs_hash_string_heap_iface_interface* _this) {
    _this->_hash = kh_init(string_heap_iface_interface_hash_type);
}

void sjf_hash_string_heap_iface_interface_setat(sjs_hash_string_heap_iface_interface* _parent, sjs_string* key, sji_interface val) {
    khash_t(string_heap_iface_interface_hash_type)* p = (khash_t(string_heap_iface_interface_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_heap_iface_interface_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_heap_iface_interface_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    if (kh_val(p, k)._parent != 0) {
    kh_val(p, k)._parent->_refCount--;
    if (kh_val(p, k)._parent->_refCount <= 0) {
        kh_val(p, k)._vtbl->destroy(kh_val(p, k)._parent);
        free(kh_val(p, k)._parent);
    }
}
;
}
int ret;
#if true
k = kh_put(string_heap_iface_interface_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(string_heap_iface_interface_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(string_heap_iface_interface_hash_type, p, k);
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_heap_iface_interface__weakptrremovekey };
weakptr_cb_add(key, cb);
#else
sjs_string t;
t._refCount = 1;
sjf_string_copy(&t, key);
;
#endif
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_heap_iface_interface__weakptrremovevalue };
weakptr_cb_add(val._parent, cb);
kh_val(p, k) = val;
#else
kh_val(p, k) = val;
if (kh_val(p, k)._parent != 0) {
    kh_val(p, k)._parent->_refCount++;
}
;
#endif
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
    sjs_array_char sjt_call4 = { -1 };

    result2 = !(&_parent->data)->isglobal;
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam6;
        char sjt_functionParam7;
        sjs_array_char* sjt_parent5 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam5;
            sjs_array_char* sjt_parent4 = 0;

            sjt_parent4 = &_parent->data;
            sjt_functionParam5 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent4, sjt_functionParam5, &sjt_call4);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            _parent->data._refCount = 1;
            sjf_array_char_copy(&_parent->data, (&sjt_call4));
        }

        sjt_parent5 = &_parent->data;
        sjt_functionParam6 = _parent->count;
        sjt_functionParam7 = '\0';
        sjf_array_char_initat(sjt_parent5, sjt_functionParam6, sjt_functionParam7);
        _parent->_isnullterminated = true;
    }

    if (sjt_call4._refCount == 1) { sjf_array_char_destroy(&sjt_call4); }
;
}

int main(int argc, char** argv) {
    sjs_class_interface_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_interface_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
    sjs_class_interface_vtbl.bob = (void(*)(sjs_object*, sjs_string*))sjf_class_bob;
    sjs_class_interface_vtbl.bob_heap = (void(*)(sjs_object*, sjs_string**))sjf_class_bob_heap;
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
    sjf_hash_string_heap_iface_interface(&sjv_a);
    sjt_parent2 = &sjv_a;
    sjt_call1._refCount = 1;
    sjt_call1.count = 3;
    sjt_call1.data._refCount = 1;
    sjt_call1.data.datasize = 3;
    sjt_call1.data.data = (void*)sjg_string1;
    sjt_call1.data.isglobal = true;
    sjt_call1.data.count = 3;
    sjf_array_char(&sjt_call1.data);
    sjt_call1._isnullterminated = false;
    sjf_string(&sjt_call1);
    sjt_functionParam2 = &sjt_call1;
    sjt_call2 = (sjs_class*)malloc(sizeof(sjs_class));
    sjt_call2->_refCount = 1;
    sjf_class_heap(sjt_call2);
    sjt_cast1 = sjt_call2;
    sjf_class_as_sji_interface(sjt_cast1, &sjt_functionParam3);
    if (sjt_functionParam3._parent != 0) {
        sjt_functionParam3._parent->_refCount++;
    }

    sjf_hash_string_heap_iface_interface_setat(sjt_parent2, sjt_functionParam2, sjt_functionParam3);
    sjt_parent3 = &sjv_a;
    sjt_call3._refCount = 1;
    sjt_call3.count = 3;
    sjt_call3.data._refCount = 1;
    sjt_call3.data.datasize = 3;
    sjt_call3.data.data = (void*)sjg_string1;
    sjt_call3.data.isglobal = true;
    sjt_call3.data.count = 3;
    sjf_array_char(&sjt_call3.data);
    sjt_call3._isnullterminated = false;
    sjf_string(&sjt_call3);
    sjt_functionParam4 = &sjt_call3;
    sjf_hash_string_heap_iface_interface_getat_heap(sjt_parent3, sjt_functionParam4, &sjv_b);
    if (sjv_b._parent != 0) {
        sji_interface sjt_parent7 = { 0 };

        sjt_parent7 = sjv_b;
        sjt_value1._refCount = 1;
        sjt_parent7._vtbl->bob(sjt_parent7._parent, &sjt_value1);
        sjt_capture1 = (sjt_value1._refCount != -1 ? &sjt_value1 : 0);
    } else {
        sjt_capture1 = 0;
    }

    if (sjt_capture1 != 0) {
        if (sjv_b._parent != 0) {
            sji_interface sjt_parent8 = { 0 };

            sjt_parent8 = sjv_b;
            sjt_value2._refCount = 1;
            sjt_parent8._vtbl->bob(sjt_parent8._parent, &sjt_value2);
            sjt_functionParam8 = (sjt_value2._refCount != -1 ? &sjt_value2 : 0);
        } else {
            sjt_functionParam8 = 0;
        }
    } else {
        sjt_call5._refCount = 1;
        sjt_call5.count = 9;
        sjt_call5.data._refCount = 1;
        sjt_call5.data.datasize = 9;
        sjt_call5.data.data = (void*)sjg_string3;
        sjt_call5.data.isglobal = true;
        sjt_call5.data.count = 9;
        sjf_array_char(&sjt_call5.data);
        sjt_call5._isnullterminated = false;
        sjf_string(&sjt_call5);
        sjt_functionParam8 = &sjt_call5;
    }

    sjf_debug_writeline(sjt_functionParam8);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_call2->_refCount--;
    if (sjt_call2->_refCount <= 0) {
        weakptr_release(sjt_call2);
        sjf_class_destroy(sjt_call2);
        free(sjt_call2);
    }
    if (sjt_functionParam3._parent != 0) {
        sjt_functionParam3._parent->_refCount--;
        if (sjt_functionParam3._parent->_refCount <= 0) {
            sjt_functionParam3._vtbl->destroy(sjt_functionParam3._parent);
            free(sjt_functionParam3._parent);
        }
    }
    if (sjv_b._parent != 0) {
        sjv_b._parent->_refCount--;
        if (sjv_b._parent->_refCount <= 0) {
            sjv_b._vtbl->destroy(sjv_b._parent);
            free(sjv_b._parent);
        }
    }
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
    if (sjt_call5._refCount == 1) { sjf_string_destroy(&sjt_call5); }
;
    if (sjt_value1._refCount == 1) { sjf_string_destroy(&sjt_value1); }
;
    if (sjt_value2._refCount == 1) { sjf_string_destroy(&sjt_value2); }
;
    if (sjv_a._refCount == 1) { sjf_hash_string_heap_iface_interface_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
