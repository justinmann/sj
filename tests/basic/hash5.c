#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_class_typeId 2
#define sjs_hash_i32_weak_class_typeId 3
#define sjs_array_char_typeId 4
#define sjs_string_typeId 5

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_hash_i32_weak_class sjs_hash_i32_weak_class;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

struct td_sjs_hash_i32_weak_class {
    int _refCount;
    void* _hash;
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

#ifndef i32_weak_class_hash_typedef
#define i32_weak_class_hash_typedef
KHASH_INIT_TYPEDEF(i32_weak_class_hash_type, int32_t, sjs_class*)
#endif
#ifndef i32_weak_class_hash_typedef
#define i32_weak_class_hash_typedef
KHASH_INIT_TYPEDEF(i32_weak_class_hash_type, int32_t, sjs_class*)
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
sjs_string sjt_call6 = { -1 };
sjs_class* sjt_call7 = 0;
sjs_class* sjt_funcold1 = 0;
int32_t sjt_functionParam1;
int32_t sjt_functionParam10;
int32_t sjt_functionParam11;
sjs_class* sjt_functionParam2 = 0;
sjs_string* sjt_functionParam3 = 0;
int32_t sjt_functionParam4;
int32_t sjt_functionParam5;
sjs_string* sjt_functionParam9 = 0;
sjs_hash_i32_weak_class* sjt_parent1 = 0;
sjs_hash_i32_weak_class* sjt_parent2 = 0;
sjs_hash_i32_weak_class* sjt_parent6 = 0;
sjs_hash_i32_weak_class sjv_a = { -1 };
sjs_class* sjv_c = 0;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_i32_weak_class(sjs_hash_i32_weak_class* _this);
void sjf_hash_i32_weak_class__weakptrremovekey(sjs_hash_i32_weak_class* _parent, int32_t key);
void sjf_hash_i32_weak_class__weakptrremovevalue(sjs_hash_i32_weak_class* _parent, sjs_class* val);
void sjf_hash_i32_weak_class_copy(sjs_hash_i32_weak_class* _this, sjs_hash_i32_weak_class* _from);
void sjf_hash_i32_weak_class_destroy(sjs_hash_i32_weak_class* _this);
void sjf_hash_i32_weak_class_getat(sjs_hash_i32_weak_class* _parent, int32_t key, sjs_class** _return);
void sjf_hash_i32_weak_class_heap(sjs_hash_i32_weak_class* _this);
void sjf_hash_i32_weak_class_setat(sjs_hash_i32_weak_class* _parent, int32_t key, sjs_class* val);
void sjf_i32_asstring(int32_t val, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, sjs_string** _return);
void sjf_i32_hash(int32_t val, uint32_t* _return);
void sjf_i32_isequal(int32_t l, int32_t r, bool* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string* _this);
void main_destroy(void);

#include <lib/common/common.c>
#ifndef i32_weak_class_hash_function
#define i32_weak_class_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(i32_weak_class_hash_type, int32_t, sjs_class*, 1, sjf_i32_hash, sjf_i32_isequal)
#else
KHASH_INIT_FUNCTION(i32_weak_class_hash_type, int32_t, sjs_class*, 1, sjf_i32_hash, sjf_i32_isequal)
#endif
#endif
#ifndef i32_weak_class_hash_function
#define i32_weak_class_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(i32_weak_class_hash_type, int32_t, sjs_class*, 1, sjf_i32_hash, sjf_i32_isequal)
#else
KHASH_INIT_FUNCTION(i32_weak_class_hash_type, int32_t, sjs_class*, 1, sjf_i32_hash, sjf_i32_isequal)
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

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
    debugout("%s\n", (char*)data->data.data);
}

void sjf_hash_i32_weak_class(sjs_hash_i32_weak_class* _this) {
    _this->_hash = kh_init(i32_weak_class_hash_type);
}

void sjf_hash_i32_weak_class__weakptrremovekey(sjs_hash_i32_weak_class* _parent, int32_t key) {
    #if false
    khash_t(i32_weak_class_hash_type)* p = (khash_t(i32_weak_class_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(i32_weak_class_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(i32_weak_class_hash_type, p, k);
    }
    #endif
}

void sjf_hash_i32_weak_class__weakptrremovevalue(sjs_hash_i32_weak_class* _parent, sjs_class* val) {
    #if true
    khash_t(i32_weak_class_hash_type)* p = (khash_t(i32_weak_class_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            sjs_class* t = kh_value(p, k);
            if ((t == val)) {
                kh_del(i32_weak_class_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_i32_weak_class_copy(sjs_hash_i32_weak_class* _this, sjs_hash_i32_weak_class* _from) {
    _this->_hash = _from->_hash;
    ptr_retain(_this->_hash);
}

void sjf_hash_i32_weak_class_destroy(sjs_hash_i32_weak_class* _this) {
    if (ptr_release(_this->_hash)) {
        khash_t(i32_weak_class_hash_type)* p = (khash_t(i32_weak_class_hash_type)*)_this->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_i32_weak_class__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if true
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_i32_weak_class__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k), cb);
                #else
                delete_cb weakptrcb6 = { &kh_value(p, k), weakptr_clear };
if (kh_value(p, k) != 0) { weakptr_cb_remove(kh_value(p, k), weakptrcb6); }
;
                #endif
            }
        }
        kh_destroy(i32_weak_class_hash_type, _this->_hash);
    }
}

void sjf_hash_i32_weak_class_getat(sjs_hash_i32_weak_class* _parent, int32_t key, sjs_class** _return) {
    khash_t(i32_weak_class_hash_type)* p = (khash_t(i32_weak_class_hash_type)*)_parent->_hash;
    #if false
    khiter_t k = kh_get(i32_weak_class_hash_type, p, *key);
    #else
    khiter_t k = kh_get(i32_weak_class_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return) = 0;
delete_cb weakptrcb10 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb10); }
return;
    }
    (*_return) = kh_val(p, k);
delete_cb weakptrcb11 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb11); }
return;;
}

void sjf_hash_i32_weak_class_heap(sjs_hash_i32_weak_class* _this) {
    _this->_hash = kh_init(i32_weak_class_hash_type);
}

void sjf_hash_i32_weak_class_setat(sjs_hash_i32_weak_class* _parent, int32_t key, sjs_class* val) {
    khash_t(i32_weak_class_hash_type)* p = (khash_t(i32_weak_class_hash_type)*)_parent->_hash;
    #if false
    khiter_t k = kh_get(i32_weak_class_hash_type, p, *key);
    #else
    khiter_t k = kh_get(i32_weak_class_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    delete_cb weakptrcb7 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_remove(kh_val(p, k), weakptrcb7); }
;
}
int ret;
#if false
k = kh_put(i32_weak_class_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(i32_weak_class_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(i32_weak_class_hash_type, p, k);
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_i32_weak_class__weakptrremovekey };
weakptr_cb_add(key, cb);
#else
int32_t t;
t = key;
;
#endif
#if true
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_i32_weak_class__weakptrremovevalue };
weakptr_cb_add(val, cb);
kh_val(p, k) = val;
#else
kh_val(p, k) = val;
delete_cb weakptrcb8 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_add(kh_val(p, k), weakptrcb8); }
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

void sjf_i32_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

    sjt_cast1 = val;
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_i32_isequal(int32_t l, int32_t r, bool* _return) {
    (*_return) = l == r;
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
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_heap(sjs_string* _this) {
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
    sjf_hash_i32_weak_class(&sjv_a);
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->x = 1;
    sjf_class_heap(sjv_c);
    sjt_parent1 = &sjv_a;
    sjt_functionParam1 = 0;
    sjt_functionParam2 = sjv_c;
    delete_cb weakptrcb9 = { &sjt_functionParam2, weakptr_clear };
    if (sjt_functionParam2 != 0) { weakptr_cb_add(sjt_functionParam2, weakptrcb9); }
    sjf_hash_i32_weak_class_setat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent2 = &sjv_a;
    sjt_functionParam5 = 0;
    sjf_hash_i32_weak_class_getat(sjt_parent2, sjt_functionParam5, &sjt_call2);
    if ((sjt_call2 != 0)) {
        sjs_class* sjt_call3 = 0;
        sjs_class* sjt_capture1 = 0;
        int32_t sjt_functionParam6;
        sjs_hash_i32_weak_class* sjt_parent3 = 0;
        int32_t sjt_value1;
        int32_option value1;

        sjt_parent3 = &sjv_a;
        sjt_functionParam6 = 0;
        sjf_hash_i32_weak_class_getat(sjt_parent3, sjt_functionParam6, &sjt_call3);
        sjt_capture1 = sjt_call3;
        sjt_value1 = sjt_capture1->x;
        value1.isvalid = true;
        value1.value = sjt_value1;

        delete_cb weakptrcb12 = { &sjt_call3, weakptr_clear };
        if (sjt_call3 != 0) { weakptr_cb_remove(sjt_call3, weakptrcb12); }
    } else {
    }

    if (int32_empty.isvalid) {
        sjs_class* sjt_call4 = 0;
        int32_t sjt_functionParam7;
        int32_option sjt_getValue1;
        sjs_hash_i32_weak_class* sjt_parent4 = 0;

        sjt_parent4 = &sjv_a;
        sjt_functionParam7 = 0;
        sjf_hash_i32_weak_class_getat(sjt_parent4, sjt_functionParam7, &sjt_call4);
        if ((sjt_call4 != 0)) {
            sjs_class* sjt_call5 = 0;
            sjs_class* sjt_capture2 = 0;
            int32_t sjt_functionParam8;
            sjs_hash_i32_weak_class* sjt_parent5 = 0;
            int32_t sjt_value2;
            int32_option value2;

            sjt_parent5 = &sjv_a;
            sjt_functionParam8 = 0;
            sjf_hash_i32_weak_class_getat(sjt_parent5, sjt_functionParam8, &sjt_call5);
            sjt_capture2 = sjt_call5;
            sjt_value2 = sjt_capture2->x;
            value2.isvalid = true;
            value2.value = sjt_value2;
            sjt_getValue1 = value2;

            delete_cb weakptrcb13 = { &sjt_call5, weakptr_clear };
            if (sjt_call5 != 0) { weakptr_cb_remove(sjt_call5, weakptrcb13); }
        } else {
            sjt_getValue1 = int32_empty;
        }

        sjt_functionParam4 = sjt_getValue1.value;

        delete_cb weakptrcb14 = { &sjt_call4, weakptr_clear };
        if (sjt_call4 != 0) { weakptr_cb_remove(sjt_call4, weakptrcb14); }
    } else {
        int32_t result2;

        result2 = -1;
        sjt_functionParam4 = result2;
    }

    sjf_i32_asstring(sjt_functionParam4, &sjt_call1);
    sjt_functionParam3 = &sjt_call1;
    sjf_debug_writeline(sjt_functionParam3);
    sjt_funcold1 = sjv_c;
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->x = 2;
    sjf_class_heap(sjv_c);
    sjt_funcold1->_refCount--;
    if (sjt_funcold1->_refCount <= 0) {
        weakptr_release(sjt_funcold1);
        sjf_class_destroy(sjt_funcold1);
        free(sjt_funcold1);
    }

    sjt_parent6 = &sjv_a;
    sjt_functionParam11 = 0;
    sjf_hash_i32_weak_class_getat(sjt_parent6, sjt_functionParam11, &sjt_call7);
    if ((sjt_call7 != 0)) {
        sjs_class* sjt_call8 = 0;
        sjs_class* sjt_capture3 = 0;
        int32_t sjt_functionParam12;
        sjs_hash_i32_weak_class* sjt_parent7 = 0;
        int32_t sjt_value3;
        int32_option value3;

        sjt_parent7 = &sjv_a;
        sjt_functionParam12 = 0;
        sjf_hash_i32_weak_class_getat(sjt_parent7, sjt_functionParam12, &sjt_call8);
        sjt_capture3 = sjt_call8;
        sjt_value3 = sjt_capture3->x;
        value3.isvalid = true;
        value3.value = sjt_value3;

        delete_cb weakptrcb15 = { &sjt_call8, weakptr_clear };
        if (sjt_call8 != 0) { weakptr_cb_remove(sjt_call8, weakptrcb15); }
    } else {
    }

    if (int32_empty.isvalid) {
        sjs_class* sjt_call9 = 0;
        int32_t sjt_functionParam13;
        int32_option sjt_getValue2;
        sjs_hash_i32_weak_class* sjt_parent8 = 0;

        sjt_parent8 = &sjv_a;
        sjt_functionParam13 = 0;
        sjf_hash_i32_weak_class_getat(sjt_parent8, sjt_functionParam13, &sjt_call9);
        if ((sjt_call9 != 0)) {
            sjs_class* sjt_call10 = 0;
            sjs_class* sjt_capture4 = 0;
            int32_t sjt_functionParam14;
            sjs_hash_i32_weak_class* sjt_parent9 = 0;
            int32_t sjt_value4;
            int32_option value4;

            sjt_parent9 = &sjv_a;
            sjt_functionParam14 = 0;
            sjf_hash_i32_weak_class_getat(sjt_parent9, sjt_functionParam14, &sjt_call10);
            sjt_capture4 = sjt_call10;
            sjt_value4 = sjt_capture4->x;
            value4.isvalid = true;
            value4.value = sjt_value4;
            sjt_getValue2 = value4;

            delete_cb weakptrcb16 = { &sjt_call10, weakptr_clear };
            if (sjt_call10 != 0) { weakptr_cb_remove(sjt_call10, weakptrcb16); }
        } else {
            sjt_getValue2 = int32_empty;
        }

        sjt_functionParam10 = sjt_getValue2.value;

        delete_cb weakptrcb17 = { &sjt_call9, weakptr_clear };
        if (sjt_call9 != 0) { weakptr_cb_remove(sjt_call9, weakptrcb17); }
    } else {
        int32_t result3;

        result3 = -1;
        sjt_functionParam10 = result3;
    }

    sjf_i32_asstring(sjt_functionParam10, &sjt_call6);
    sjt_functionParam9 = &sjt_call6;
    sjf_debug_writeline(sjt_functionParam9);
    main_destroy();
    return 0;
}

void main_destroy() {

    delete_cb weakptrcb18 = { &sjt_call2, weakptr_clear };
    if (sjt_call2 != 0) { weakptr_cb_remove(sjt_call2, weakptrcb18); }
    delete_cb weakptrcb19 = { &sjt_call7, weakptr_clear };
    if (sjt_call7 != 0) { weakptr_cb_remove(sjt_call7, weakptrcb19); }
    delete_cb weakptrcb20 = { &sjt_functionParam2, weakptr_clear };
    if (sjt_functionParam2 != 0) { weakptr_cb_remove(sjt_functionParam2, weakptrcb20); }
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
;
    if (sjv_a._refCount == 1) { sjf_hash_i32_weak_class_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
