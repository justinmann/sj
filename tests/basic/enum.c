#include <lib/common/common.h>

const char* sjg_string1 = "a";
const char* sjg_string2 = "b";
const char* sjg_string3 = "c";
const char* sjg_string4 = "";

#define sjs_hash_type_bool_typeId 17
#define sjs_log_typeId 22
#define sjs_array_char_typeId 25
#define sjs_string_typeId 26

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
int32_t sjv_bar2_a;
int32_t sjv_bar2_b;
int32_t sjv_bar2_c;
int32_t sjv_bar_a;
int32_t sjv_bar_b;
int32_t sjv_bar_c;
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_string* sjt_functionParam5 = 0;
int32_option sjv_b;
sjs_string sjv_c = { -1 };
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
void sjf_bar_asstring(int32_t e, sjs_string* _return);
void sjf_bar_asstring_heap(int32_t e, sjs_string** _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_func(int32_option* _return);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
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

void sjf_bar_asstring(int32_t e, sjs_string* _return) {
    int32_t underscore1;

    underscore1 = e;
    if (underscore1 == 0) {
        _return->_refCount = 1;
        _return->count = 1;
        _return->data._refCount = 1;
        _return->data.datasize = 1;
        _return->data.data = (void*)sjg_string1;
        _return->data.isglobal = true;
        _return->data.count = 1;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
    } else {
        if (underscore1 == 1) {
            _return->_refCount = 1;
            _return->count = 1;
            _return->data._refCount = 1;
            _return->data.datasize = 1;
            _return->data.data = (void*)sjg_string2;
            _return->data.isglobal = true;
            _return->data.count = 1;
            sjf_array_char(&_return->data);
            _return->_isnullterminated = false;
            sjf_string(_return);
        } else {
            if (underscore1 == 2) {
                _return->_refCount = 1;
                _return->count = 1;
                _return->data._refCount = 1;
                _return->data.datasize = 1;
                _return->data.data = (void*)sjg_string3;
                _return->data.isglobal = true;
                _return->data.count = 1;
                sjf_array_char(&_return->data);
                _return->_isnullterminated = false;
                sjf_string(_return);
            } else {
                _return->_refCount = 1;
                _return->count = 0;
                _return->data._refCount = 1;
                _return->data.datasize = 0;
                _return->data.data = (void*)sjg_string4;
                _return->data.isglobal = true;
                _return->data.count = 0;
                sjf_array_char(&_return->data);
                _return->_isnullterminated = false;
                sjf_string(_return);
            }
        }
    }
}

void sjf_bar_asstring_heap(int32_t e, sjs_string** _return) {
    int32_t underscore2;

    underscore2 = e;
    if (underscore2 == 0) {
        sjs_string sjt_call1 = { -1 };

        sjt_call1._refCount = 1;
        sjt_call1.count = 1;
        sjt_call1.data._refCount = 1;
        sjt_call1.data.datasize = 1;
        sjt_call1.data.data = (void*)sjg_string1;
        sjt_call1.data.isglobal = true;
        sjt_call1.data.count = 1;
        sjf_array_char(&sjt_call1.data);
        sjt_call1._isnullterminated = false;
        sjf_string(&sjt_call1);
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        sjf_string_copy((*_return), &sjt_call1);

        if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    } else {
        if (underscore2 == 1) {
            sjs_string sjt_call2 = { -1 };

            sjt_call2._refCount = 1;
            sjt_call2.count = 1;
            sjt_call2.data._refCount = 1;
            sjt_call2.data.datasize = 1;
            sjt_call2.data.data = (void*)sjg_string2;
            sjt_call2.data.isglobal = true;
            sjt_call2.data.count = 1;
            sjf_array_char(&sjt_call2.data);
            sjt_call2._isnullterminated = false;
            sjf_string(&sjt_call2);
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
            (*_return)->_refCount = 1;
            sjf_string_copy((*_return), &sjt_call2);

            if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
        } else {
            if (underscore2 == 2) {
                sjs_string sjt_call3 = { -1 };

                sjt_call3._refCount = 1;
                sjt_call3.count = 1;
                sjt_call3.data._refCount = 1;
                sjt_call3.data.datasize = 1;
                sjt_call3.data.data = (void*)sjg_string3;
                sjt_call3.data.isglobal = true;
                sjt_call3.data.count = 1;
                sjf_array_char(&sjt_call3.data);
                sjt_call3._isnullterminated = false;
                sjf_string(&sjt_call3);
                (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
                (*_return)->_refCount = 1;
                sjf_string_copy((*_return), &sjt_call3);

                if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
            } else {
                sjs_string sjt_call4 = { -1 };

                sjt_call4._refCount = 1;
                sjt_call4.count = 0;
                sjt_call4.data._refCount = 1;
                sjt_call4.data.datasize = 0;
                sjt_call4.data.data = (void*)sjg_string4;
                sjt_call4.data.isglobal = true;
                sjt_call4.data.count = 0;
                sjf_array_char(&sjt_call4.data);
                sjt_call4._isnullterminated = false;
                sjf_string(&sjt_call4);
                (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
                (*_return)->_refCount = 1;
                sjf_string_copy((*_return), &sjt_call4);

                if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
            }
        }
    }
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent3 = 0;

    sjt_parent3 = data;
    sjf_string_nullterminate(sjt_parent3);
    debugout("%s\n", (char*)data->data.data);
}

void sjf_func(int32_option* _return) {
    int32_t sjt_value1;
    int32_option value1;

    sjt_value1 = sjv_bar_a;
    value1.isvalid = true;
    value1.value = sjt_value1;
    (*_return) = value1;
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

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_funcold1 = { -1 };

    result2 = !(&_parent->data)->isglobal;
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam3;
        char sjt_functionParam4;
        sjs_array_char* sjt_parent2 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam2;
            sjs_array_char* sjt_parent1 = 0;

            sjt_funcold1._refCount = 1;
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
            sjt_parent1 = &_parent->data;
            sjt_functionParam2 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent1, sjt_functionParam2, &sjt_funcold1);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
        }

        sjt_parent2 = &_parent->data;
        sjt_functionParam3 = _parent->count;
        sjt_functionParam4 = '\0';
        sjf_array_char_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
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

int main(int argc, char** argv) {
    sjv_loglevel_trace = 0;
    sjv_loglevel_debug = 1;
    sjv_loglevel_info = 2;
    sjv_loglevel_warn = 3;
    sjv_loglevel_error = 4;
    sjv_loglevel_fatal = 5;
    sjv_bar_a = 0;
    sjv_bar_b = 1;
    sjv_bar_c = 2;
    sjv_bar2_a = 0;
    sjv_bar2_b = 1;
    sjv_bar2_c = 2;
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
    sjf_func(&sjv_b);
    if (sjv_b.isvalid) {
        int32_t sjt_functionParam1;
        int32_option sjt_getValue1;

        sjv_c._refCount = 1;
        sjt_getValue1 = sjv_b;
        sjt_functionParam1 = sjt_getValue1.value;
        sjf_bar_asstring(sjt_functionParam1, &sjv_c);
    } else {
        sjv_c._refCount = -1;
    }

    sjt_functionParam5 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjf_debug_writeline(sjt_functionParam5);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_c._refCount == 1) { sjf_string_destroy(&sjv_c); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
}
