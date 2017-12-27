#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_class_typeId 2
#define cb_i32_typeId 3
#define cb_i32_heap_typeId 4
#define sjs_lambda1_typeId 5
#define sjs_array_char_typeId 6
#define sjs_string_typeId 7

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_cb_i32 cb_i32;
typedef struct td_cb_i32_heap cb_i32_heap;
typedef struct td_sjs_lambda1 sjs_lambda1;
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

struct td_cb_i32 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, int32_t* _return);
};

struct td_cb_i32_heap {
    cb_i32 inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_lambda1 {
    int _refCount;
    sjs_class lambdaparam1;
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

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
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
void sjf_do(void);
void sjf_func(cb_i32_heap cb, int32_t* _return);
void sjf_i32_asstring(int32_t val, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, sjs_string** _return);
void sjf_lambda1(sjs_lambda1* _this);
void sjf_lambda1_copy(sjs_lambda1* _this, sjs_lambda1* _from);
void sjf_lambda1_destroy(sjs_lambda1* _this);
void sjf_lambda1_heap(sjs_lambda1* _this);
void sjf_lambda1_invoke(sjs_lambda1* _parent, int32_t* _return);
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

void sjf_do(void) {
    sjs_lambda1* sjt_call1 = 0;
    sjs_string sjt_call2 = { -1 };
    cb_i32_heap sjt_functionParam1;
    sjs_string* sjt_functionParam2 = 0;
    int32_t sjt_functionParam3;
    int32_t sjv_a;
    sjs_class sjv_c = { -1 };

    sjv_c._refCount = 1;
    sjv_c.x = 12;
    sjf_class(&sjv_c);
    sjs_lambda1* lambainit1;
    sjt_call1 = (sjs_lambda1*)malloc(sizeof(sjs_lambda1));
    sjt_call1->_refCount = 1;
    sjt_call1->lambdaparam1._refCount = 1;
    sjf_class_copy(&sjt_call1->lambdaparam1, &sjv_c);
    sjf_lambda1_heap(sjt_call1);
    lambainit1 = sjt_call1;
    sjt_functionParam1.inner._parent = (sjs_object*)lambainit1;
    sjt_functionParam1.inner._parent->_refCount++;
    sjt_functionParam1._destroy = (void(*)(sjs_object*))sjf_lambda1_destroy;
    sjt_functionParam1.inner._cb = (void(*)(sjs_object*, int32_t*))sjf_lambda1_invoke;
    sjf_func(sjt_functionParam1, &sjv_a);
    sjt_functionParam3 = (&sjv_c)->x;
    sjf_i32_asstring(sjt_functionParam3, &sjt_call2);
    sjt_functionParam2 = &sjt_call2;
    sjf_debug_writeline(sjt_functionParam2);

    sjt_call1->_refCount--;
    if (sjt_call1->_refCount <= 0) {
        weakptr_release(sjt_call1);
        sjf_lambda1_destroy(sjt_call1);
        free(sjt_call1);
    }
    if ((uintptr_t)sjt_functionParam1.inner._parent > 1) {
        sjt_functionParam1.inner._parent->_refCount--;
        if (sjt_functionParam1.inner._parent->_refCount <= 0) {
            sjt_functionParam1._destroy(sjt_functionParam1.inner._parent);
            free(sjt_functionParam1.inner._parent);
        }
    }
    if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
;
}

void sjf_func(cb_i32_heap cb, int32_t* _return) {
    cb.inner._cb(cb.inner._parent, _return);
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

void sjf_lambda1(sjs_lambda1* _this) {
}

void sjf_lambda1_copy(sjs_lambda1* _this, sjs_lambda1* _from) {
    _this->lambdaparam1._refCount = 1;
    sjf_class_copy(&_this->lambdaparam1, &_from->lambdaparam1);
}

void sjf_lambda1_destroy(sjs_lambda1* _this) {
    if (_this->lambdaparam1._refCount == 1) { sjf_class_destroy(&_this->lambdaparam1); }
;
}

void sjf_lambda1_heap(sjs_lambda1* _this) {
}

void sjf_lambda1_invoke(sjs_lambda1* _parent, int32_t* _return) {
    (&_parent->lambdaparam1)->x = (&_parent->lambdaparam1)->x + 1;
    (*_return) = (&_parent->lambdaparam1)->x;
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
    sjf_do();
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
