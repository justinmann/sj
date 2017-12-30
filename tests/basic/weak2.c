#include <lib/common/common.h>

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
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call12 = { -1 };
sjs_string sjt_call13 = { -1 };
sjs_string sjt_call14 = { -1 };
sjs_string sjt_call15 = { -1 };
sjs_string sjt_call16 = { -1 };
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
sjs_array_weak_class sjv_a = { -1 };
sjs_class* sjv_c = 0;
int32_t sjv_clocks_per_sec;
sjs_class* sjv_d = 0;
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

void sjf_array_weak_class(sjs_array_weak_class* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class*) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_weak_class_asstring(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string* _return) {
    int32_t i;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    sjs_string sjv_result = { -1 };

    sjv_result._refCount = 1;
    sjv_result.count = 0;
    sjv_result.data._refCount = 1;
    sjv_result.data.datasize = 0;
    sjv_result.data.data = (void*)sjg_string2;
    sjv_result.data.isglobal = true;
    sjv_result.data.count = 0;
    sjf_array_char(&sjv_result.data);
    sjv_result._isnullterminated = false;
    sjf_string(&sjv_result);
    sjt_forStart1 = 0;
    sjt_forEnd1 = _parent->count;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_class* sjt_call2 = 0;
        sjs_string sjt_call6 = { -1 };
        sjs_string* sjt_capture1 = 0;
        sjs_string sjt_funcold2 = { -1 };
        sjs_string sjt_funcold3 = { -1 };
        sjs_string* sjt_functionParam19 = 0;
        int32_t sjt_functionParam20;
        sjs_string* sjt_parent14 = 0;
        sjs_string sjt_value1 = { -1 };
        sjs_string sjt_value2 = { -1 };

        if (i != 0) {
            sjs_string* sjt_functionParam18 = 0;
            sjs_string* sjt_parent13 = 0;

            sjt_funcold2._refCount = 1;
            sjf_string_copy(&sjt_funcold2, &sjv_result);
            sjt_parent13 = &sjv_result;
            sjt_functionParam18 = sep;
            sjf_string_add(sjt_parent13, sjt_functionParam18, &sjt_funcold2);
            if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
            sjf_string_copy(&sjv_result, &sjt_funcold2);
        }

        sjt_funcold3._refCount = 1;
        sjf_string_copy(&sjt_funcold3, &sjv_result);
        sjt_parent14 = &sjv_result;
        sjt_functionParam20 = i;
        sjf_array_weak_class_getat(_parent, sjt_functionParam20, &sjt_call2);
        if (sjt_call2 != 0) {
            sjs_class* sjt_call3 = 0;
            int32_t sjt_functionParam25;
            sjs_class* sjt_parent15 = 0;

            sjt_functionParam25 = i;
            sjf_array_weak_class_getat(_parent, sjt_functionParam25, &sjt_call3);
            sjt_parent15 = sjt_call3;
            sjf_class_asstring(sjt_parent15, &sjt_value1);
            sjt_capture1 = (sjt_value1._refCount != -1 ? &sjt_value1 : 0);

            delete_cb weakptrcb8 = { &sjt_call3, weakptr_clear };
            if (sjt_call3 != 0) { weakptr_cb_remove(sjt_call3, weakptrcb8); }
        } else {
            sjt_capture1 = 0;
        }

        if (sjt_capture1 != 0) {
            sjs_class* sjt_call4 = 0;
            int32_t sjt_functionParam26;

            sjt_functionParam26 = i;
            sjf_array_weak_class_getat(_parent, sjt_functionParam26, &sjt_call4);
            if (sjt_call4 != 0) {
                sjs_class* sjt_call5 = 0;
                int32_t sjt_functionParam27;
                sjs_class* sjt_parent16 = 0;

                sjt_functionParam27 = i;
                sjf_array_weak_class_getat(_parent, sjt_functionParam27, &sjt_call5);
                sjt_parent16 = sjt_call5;
                sjf_class_asstring(sjt_parent16, &sjt_value2);
                sjt_functionParam19 = (sjt_value2._refCount != -1 ? &sjt_value2 : 0);

                delete_cb weakptrcb9 = { &sjt_call5, weakptr_clear };
                if (sjt_call5 != 0) { weakptr_cb_remove(sjt_call5, weakptrcb9); }
            } else {
                sjt_functionParam19 = 0;
            }

            delete_cb weakptrcb10 = { &sjt_call4, weakptr_clear };
            if (sjt_call4 != 0) { weakptr_cb_remove(sjt_call4, weakptrcb10); }
        } else {
            sjt_call6._refCount = 1;
            sjt_call6.count = 0;
            sjt_call6.data._refCount = 1;
            sjt_call6.data.datasize = 0;
            sjt_call6.data.data = (void*)sjg_string2;
            sjt_call6.data.isglobal = true;
            sjt_call6.data.count = 0;
            sjf_array_char(&sjt_call6.data);
            sjt_call6._isnullterminated = false;
            sjf_string(&sjt_call6);
            sjt_functionParam19 = &sjt_call6;
        }

        sjf_string_add(sjt_parent14, sjt_functionParam19, &sjt_funcold3);
        if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
        sjf_string_copy(&sjv_result, &sjt_funcold3);
        i++;

        delete_cb weakptrcb11 = { &sjt_call2, weakptr_clear };
        if (sjt_call2 != 0) { weakptr_cb_remove(sjt_call2, weakptrcb11); }
        if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
;
        if (sjt_funcold2._refCount == 1) { sjf_string_destroy(&sjt_funcold2); }
;
        if (sjt_funcold3._refCount == 1) { sjf_string_destroy(&sjt_funcold3); }
;
        if (sjt_value1._refCount == 1) { sjf_string_destroy(&sjt_value1); }
;
        if (sjt_value2._refCount == 1) { sjf_string_destroy(&sjt_value2); }
;
    }

    _return->_refCount = 1;
    sjf_string_copy(_return, &sjv_result);

    if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
}

void sjf_array_weak_class_asstring_heap(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string** _return) {
    int32_t i;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    sjs_string sjv_result = { -1 };

    sjv_result._refCount = 1;
    sjv_result.count = 0;
    sjv_result.data._refCount = 1;
    sjv_result.data.datasize = 0;
    sjv_result.data.data = (void*)sjg_string2;
    sjv_result.data.isglobal = true;
    sjv_result.data.count = 0;
    sjf_array_char(&sjv_result.data);
    sjv_result._isnullterminated = false;
    sjf_string(&sjv_result);
    sjt_forStart4 = 0;
    sjt_forEnd4 = _parent->count;
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        sjs_string sjt_call11 = { -1 };
        sjs_class* sjt_call7 = 0;
        sjs_string* sjt_capture2 = 0;
        sjs_string sjt_funcold4 = { -1 };
        sjs_string sjt_funcold5 = { -1 };
        sjs_string* sjt_functionParam29 = 0;
        int32_t sjt_functionParam30;
        sjs_string* sjt_parent18 = 0;
        sjs_string sjt_value3 = { -1 };
        sjs_string sjt_value4 = { -1 };

        if (i != 0) {
            sjs_string* sjt_functionParam28 = 0;
            sjs_string* sjt_parent17 = 0;

            sjt_funcold4._refCount = 1;
            sjf_string_copy(&sjt_funcold4, &sjv_result);
            sjt_parent17 = &sjv_result;
            sjt_functionParam28 = sep;
            sjf_string_add(sjt_parent17, sjt_functionParam28, &sjt_funcold4);
            if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
            sjf_string_copy(&sjv_result, &sjt_funcold4);
        }

        sjt_funcold5._refCount = 1;
        sjf_string_copy(&sjt_funcold5, &sjv_result);
        sjt_parent18 = &sjv_result;
        sjt_functionParam30 = i;
        sjf_array_weak_class_getat(_parent, sjt_functionParam30, &sjt_call7);
        if (sjt_call7 != 0) {
            sjs_class* sjt_call8 = 0;
            int32_t sjt_functionParam31;
            sjs_class* sjt_parent19 = 0;

            sjt_functionParam31 = i;
            sjf_array_weak_class_getat(_parent, sjt_functionParam31, &sjt_call8);
            sjt_parent19 = sjt_call8;
            sjf_class_asstring(sjt_parent19, &sjt_value3);
            sjt_capture2 = (sjt_value3._refCount != -1 ? &sjt_value3 : 0);

            delete_cb weakptrcb12 = { &sjt_call8, weakptr_clear };
            if (sjt_call8 != 0) { weakptr_cb_remove(sjt_call8, weakptrcb12); }
        } else {
            sjt_capture2 = 0;
        }

        if (sjt_capture2 != 0) {
            sjs_class* sjt_call9 = 0;
            int32_t sjt_functionParam32;

            sjt_functionParam32 = i;
            sjf_array_weak_class_getat(_parent, sjt_functionParam32, &sjt_call9);
            if (sjt_call9 != 0) {
                sjs_class* sjt_call10 = 0;
                int32_t sjt_functionParam33;
                sjs_class* sjt_parent20 = 0;

                sjt_functionParam33 = i;
                sjf_array_weak_class_getat(_parent, sjt_functionParam33, &sjt_call10);
                sjt_parent20 = sjt_call10;
                sjf_class_asstring(sjt_parent20, &sjt_value4);
                sjt_functionParam29 = (sjt_value4._refCount != -1 ? &sjt_value4 : 0);

                delete_cb weakptrcb13 = { &sjt_call10, weakptr_clear };
                if (sjt_call10 != 0) { weakptr_cb_remove(sjt_call10, weakptrcb13); }
            } else {
                sjt_functionParam29 = 0;
            }

            delete_cb weakptrcb14 = { &sjt_call9, weakptr_clear };
            if (sjt_call9 != 0) { weakptr_cb_remove(sjt_call9, weakptrcb14); }
        } else {
            sjt_call11._refCount = 1;
            sjt_call11.count = 0;
            sjt_call11.data._refCount = 1;
            sjt_call11.data.datasize = 0;
            sjt_call11.data.data = (void*)sjg_string2;
            sjt_call11.data.isglobal = true;
            sjt_call11.data.count = 0;
            sjf_array_char(&sjt_call11.data);
            sjt_call11._isnullterminated = false;
            sjf_string(&sjt_call11);
            sjt_functionParam29 = &sjt_call11;
        }

        sjf_string_add(sjt_parent18, sjt_functionParam29, &sjt_funcold5);
        if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
        sjf_string_copy(&sjv_result, &sjt_funcold5);
        i++;

        delete_cb weakptrcb15 = { &sjt_call7, weakptr_clear };
        if (sjt_call7 != 0) { weakptr_cb_remove(sjt_call7, weakptrcb15); }
        if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
;
        if (sjt_funcold4._refCount == 1) { sjf_string_destroy(&sjt_funcold4); }
;
        if (sjt_funcold5._refCount == 1) { sjf_string_destroy(&sjt_funcold5); }
;
        if (sjt_value3._refCount == 1) { sjf_string_destroy(&sjt_value3); }
;
        if (sjt_value4._refCount == 1) { sjf_string_destroy(&sjt_value4); }
;
    }

    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    sjf_string_copy((*_return), &sjv_result);

    if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
}

void sjf_array_weak_class_copy(sjs_array_weak_class* _this, sjs_array_weak_class* _from) {
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

void sjf_array_weak_class_destroy(sjs_array_weak_class* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !false && !false
            sjs_class** p = (sjs_class**)_this->data;
            for (int i = 0; i < _this->count; i++) {
                delete_cb weakptrcb3 = { &p[i], weakptr_clear };
if (p[i] != 0) { weakptr_cb_remove(p[i], weakptrcb3); }
;
            }
            #endif
            free(refcount);
        }
    }
}

void sjf_array_weak_class_getat(sjs_array_weak_class* _parent, int32_t index, sjs_class** _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_class** p = (sjs_class**)_parent->data;
    (*_return) = p[index];
delete_cb weakptrcb7 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb7); }
return;;       
}

void sjf_array_weak_class_heap(sjs_array_weak_class* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class*) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_weak_class_initat(sjs_array_weak_class* _parent, int32_t index, sjs_class* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sjs_class** p = (sjs_class**)_parent->data;
    p[index] = item;
delete_cb weakptrcb4 = { &p[index], weakptr_clear };
if (p[index] != 0) { weakptr_cb_add(p[index], weakptrcb4); }
;
    _parent->count = index + 1;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_asstring(sjs_class* _parent, sjs_string* _return) {
    int32_t sjt_functionParam21;
    int32_t sjt_functionParam22;

    sjt_functionParam21 = _parent->x;
    sjt_functionParam22 = 10;
    sjf_i32_asstring(sjt_functionParam21, sjt_functionParam22, _return);
}

void sjf_class_asstring_heap(sjs_class* _parent, sjs_string** _return) {
    int32_t sjt_functionParam23;
    int32_t sjt_functionParam24;

    sjt_functionParam23 = _parent->x;
    sjt_functionParam24 = 10;
    sjf_i32_asstring_heap(sjt_functionParam23, sjt_functionParam24, _return);
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent5 = 0;

    sjt_parent5 = data;
    sjf_string_nullterminate(sjt_parent5);
    debugout("%s\n", (char*)data->data.data);
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
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam9;
            sjs_array_char* sjt_parent6 = 0;

            sjt_parent6 = &_parent->data;
            sjt_functionParam9 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent6, sjt_functionParam9, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart2 = 0;
        sjt_forEnd2 = item->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam10;
            char sjt_functionParam11;
            int32_t sjt_functionParam13;
            sjs_array_char* sjt_parent7 = 0;
            sjs_string* sjt_parent9 = 0;

            sjt_parent7 = &sjv_newdata;
            sjt_functionParam10 = sjv_newcount;
            sjt_parent9 = item;
            sjt_functionParam13 = i;
            sjf_string_getat(sjt_parent9, sjt_functionParam13, &sjt_functionParam11);
            sjf_array_char_initat(sjt_parent7, sjt_functionParam10, sjt_functionParam11);
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
        int32_t sjt_forEnd3;
        int32_t sjt_forStart3;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam14;
            sjs_array_char* sjt_parent10 = 0;

            sjt_parent10 = &_parent->data;
            sjt_functionParam14 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent10, sjt_functionParam14, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart3 = 0;
        sjt_forEnd3 = item->count;
        i = sjt_forStart3;
        while (i < sjt_forEnd3) {
            int32_t sjt_functionParam15;
            char sjt_functionParam16;
            int32_t sjt_functionParam17;
            sjs_array_char* sjt_parent11 = 0;
            sjs_string* sjt_parent12 = 0;

            sjt_parent11 = &sjv_newdata;
            sjt_functionParam15 = sjv_newcount;
            sjt_parent12 = item;
            sjt_functionParam17 = i;
            sjf_string_getat(sjt_parent12, sjt_functionParam17, &sjt_functionParam16);
            sjf_array_char_initat(sjt_parent11, sjt_functionParam15, sjt_functionParam16);
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
    sjs_array_char* sjt_parent8 = 0;

    sjt_parent8 = &_parent->data;
    sjt_functionParam12 = index;
    sjf_array_char_getat(sjt_parent8, sjt_functionParam12, _return);
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
        sjs_array_char* sjt_parent4 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam5;
            sjs_array_char* sjt_parent3 = 0;

            sjt_funcold1._refCount = 1;
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
            sjt_parent3 = &_parent->data;
            sjt_functionParam5 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent3, sjt_functionParam5, &sjt_funcold1);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
        }

        sjt_parent4 = &_parent->data;
        sjt_functionParam6 = _parent->count;
        sjt_functionParam7 = '\0';
        sjf_array_char_initat(sjt_parent4, sjt_functionParam6, sjt_functionParam7);
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
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->x = 1;
    sjf_class_heap(sjv_c);
    sjv_d = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_d->_refCount = 1;
    sjv_d->x = 2;
    sjf_class_heap(sjv_d);
    sjv_a._refCount = 1;
    sjv_a.datasize = 2;
    sjv_a.data = 0;
    sjv_a.isglobal = false;
    sjv_a.count = 0;
    sjf_array_weak_class(&sjv_a);
    sjs_array_weak_class* array1;
    array1 = &sjv_a;
    sjt_parent1 = array1;
    sjt_functionParam1 = 0;
    sjt_functionParam2 = sjv_c;
    delete_cb weakptrcb5 = { &sjt_functionParam2, weakptr_clear };
    if (sjt_functionParam2 != 0) { weakptr_cb_add(sjt_functionParam2, weakptrcb5); }
    sjf_array_weak_class_initat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent2 = array1;
    sjt_functionParam3 = 1;
    sjt_functionParam4 = sjv_d;
    delete_cb weakptrcb6 = { &sjt_functionParam4, weakptr_clear };
    if (sjt_functionParam4 != 0) { weakptr_cb_add(sjt_functionParam4, weakptrcb6); }
    sjf_array_weak_class_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
    sjt_parent21 = &sjv_a;
    sjt_call12._refCount = 1;
    sjt_call12.count = 2;
    sjt_call12.data._refCount = 1;
    sjt_call12.data.datasize = 2;
    sjt_call12.data.data = (void*)sjg_string1;
    sjt_call12.data.isglobal = true;
    sjt_call12.data.count = 2;
    sjf_array_char(&sjt_call12.data);
    sjt_call12._isnullterminated = false;
    sjf_string(&sjt_call12);
    sjt_functionParam34 = &sjt_call12;
    sjf_array_weak_class_asstring(sjt_parent21, sjt_functionParam34, &sjt_call1);
    sjt_functionParam8 = &sjt_call1;
    sjf_debug_writeline(sjt_functionParam8);
    sjt_funcold6 = sjv_c;
    sjt_funcold6->_refCount++;
    sjt_funcold6 = (sjs_class*)malloc(sizeof(sjs_class));
    sjt_funcold6->_refCount = 1;
    sjt_funcold6->x = 3;
    sjf_class_heap(sjt_funcold6);
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }

    sjv_c = sjt_funcold6;
    sjv_c->_refCount++;
    sjt_parent22 = &sjv_a;
    sjt_call14._refCount = 1;
    sjt_call14.count = 2;
    sjt_call14.data._refCount = 1;
    sjt_call14.data.datasize = 2;
    sjt_call14.data.data = (void*)sjg_string1;
    sjt_call14.data.isglobal = true;
    sjt_call14.data.count = 2;
    sjf_array_char(&sjt_call14.data);
    sjt_call14._isnullterminated = false;
    sjf_string(&sjt_call14);
    sjt_functionParam36 = &sjt_call14;
    sjf_array_weak_class_asstring(sjt_parent22, sjt_functionParam36, &sjt_call13);
    sjt_functionParam35 = &sjt_call13;
    sjf_debug_writeline(sjt_functionParam35);
    sjt_funcold7 = sjv_d;
    sjt_funcold7->_refCount++;
    sjt_funcold7 = (sjs_class*)malloc(sizeof(sjs_class));
    sjt_funcold7->_refCount = 1;
    sjt_funcold7->x = 4;
    sjf_class_heap(sjt_funcold7);
    sjv_d->_refCount--;
    if (sjv_d->_refCount <= 0) {
        weakptr_release(sjv_d);
        sjf_class_destroy(sjv_d);
        free(sjv_d);
    }

    sjv_d = sjt_funcold7;
    sjv_d->_refCount++;
    sjt_parent23 = &sjv_a;
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
    sjt_functionParam38 = &sjt_call16;
    sjf_array_weak_class_asstring(sjt_parent23, sjt_functionParam38, &sjt_call15);
    sjt_functionParam37 = &sjt_call15;
    sjf_debug_writeline(sjt_functionParam37);
    main_destroy();
    return 0;
}

void main_destroy() {

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
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }
    sjv_d->_refCount--;
    if (sjv_d->_refCount <= 0) {
        weakptr_release(sjv_d);
        sjf_class_destroy(sjv_d);
        free(sjv_d);
    }
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
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
    if (sjv_a._refCount == 1) { sjf_array_weak_class_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
}
