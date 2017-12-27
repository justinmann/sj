#include <lib/common/common.h>

const char* sjg_string1 = "false";
const char* sjg_string2 = "true";

#define sjs_log_typeId 1
#define sjs_class_typeId 2
#define sjs_array_char_typeId 3
#define sjs_string_typeId 4

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
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
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call2 = { -1 };
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string sjt_call5 = { -1 };
sjs_string sjt_call6 = { -1 };
sjs_class* sjt_funcold1 = 0;
sjs_string* sjt_functionParam1 = 0;
bool sjt_functionParam10;
sjs_string* sjt_functionParam11 = 0;
bool sjt_functionParam12;
bool sjt_functionParam2;
sjs_string* sjt_functionParam3 = 0;
bool sjt_functionParam4;
sjs_string* sjt_functionParam5 = 0;
bool sjt_functionParam6;
sjs_string* sjt_functionParam7 = 0;
bool sjt_functionParam8;
sjs_string* sjt_functionParam9 = 0;
sjs_class* sjv_c = 0;
sjs_class* sjv_d = 0;
sjs_class* sjv_e = 0;
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
void sjf_bool_asstring(bool val, sjs_string* _return);
void sjf_bool_asstring_heap(bool val, sjs_string** _return);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
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

void sjf_bool_asstring(bool val, sjs_string* _return) {
    if (val) {
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 5;
        _return->data.data = (void*)sjg_string2;
        _return->data._isglobal = true;
        _return->data.count = 5;
        sjf_array_char(&_return->data);
        sjf_string(_return);
    } else {
        _return->_refCount = 1;
        _return->count = 5;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string1;
        _return->data._isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        sjf_string(_return);
    }
}

void sjf_bool_asstring_heap(bool val, sjs_string** _return) {
    if (val) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = 4;
        (*_return)->data._refCount = 1;
        (*_return)->data.datasize = 5;
        (*_return)->data.data = (void*)sjg_string2;
        (*_return)->data._isglobal = true;
        (*_return)->data.count = 5;
        sjf_array_char(&(*_return)->data);
        sjf_string_heap((*_return));
    } else {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = 5;
        (*_return)->data._refCount = 1;
        (*_return)->data.datasize = 6;
        (*_return)->data.data = (void*)sjg_string1;
        (*_return)->data._isglobal = true;
        (*_return)->data.count = 6;
        sjf_array_char(&(*_return)->data);
        sjf_string_heap((*_return));
    }
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
    debugout("%s\n", (char*)data->data.data);
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
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjf_class_heap(sjv_c);
    sjv_d = sjv_c;
    delete_cb weakptrcb1 = { &sjv_d, weakptr_clear };
    if (sjv_d != 0) { weakptr_cb_add(sjv_d, weakptrcb1); }
    sjv_e = sjv_c;
    delete_cb weakptrcb2 = { &sjv_e, weakptr_clear };
    if (sjv_e != 0) { weakptr_cb_add(sjv_e, weakptrcb2); }
    sjt_functionParam2 = (sjv_d == 0);
    sjf_bool_asstring(sjt_functionParam2, &sjt_call1);
    sjt_functionParam1 = &sjt_call1;
    sjf_debug_writeline(sjt_functionParam1);
    sjt_functionParam4 = (sjv_e == 0);
    sjf_bool_asstring(sjt_functionParam4, &sjt_call2);
    sjt_functionParam3 = &sjt_call2;
    sjf_debug_writeline(sjt_functionParam3);
    delete_cb weakptrcb3 = { &sjv_e, weakptr_clear };
    if (sjv_e != 0) { weakptr_cb_remove(sjv_e, weakptrcb3); }
    delete_cb weakptrcb4 = { &sjv_e, weakptr_clear };
    if (sjv_e != 0) { weakptr_cb_remove(sjv_e, weakptrcb4); }
    sjv_e = 0;
    delete_cb weakptrcb5 = { &sjv_e, weakptr_clear };
    if (sjv_e != 0) { weakptr_cb_add(sjv_e, weakptrcb5); }
    sjt_functionParam6 = (sjv_d == 0);
    sjf_bool_asstring(sjt_functionParam6, &sjt_call3);
    sjt_functionParam5 = &sjt_call3;
    sjf_debug_writeline(sjt_functionParam5);
    sjt_functionParam8 = (sjv_e == 0);
    sjf_bool_asstring(sjt_functionParam8, &sjt_call4);
    sjt_functionParam7 = &sjt_call4;
    sjf_debug_writeline(sjt_functionParam7);
    sjt_funcold1 = sjv_c;
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjf_class_heap(sjv_c);
    sjt_funcold1->_refCount--;
    if (sjt_funcold1->_refCount <= 0) {
        weakptr_release(sjt_funcold1);
        sjf_class_destroy(sjt_funcold1);
        free(sjt_funcold1);
    }

    sjt_functionParam10 = (sjv_d == 0);
    sjf_bool_asstring(sjt_functionParam10, &sjt_call5);
    sjt_functionParam9 = &sjt_call5;
    sjf_debug_writeline(sjt_functionParam9);
    sjt_functionParam12 = (sjv_e == 0);
    sjf_bool_asstring(sjt_functionParam12, &sjt_call6);
    sjt_functionParam11 = &sjt_call6;
    sjf_debug_writeline(sjt_functionParam11);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }
    delete_cb weakptrcb6 = { &sjv_d, weakptr_clear };
    if (sjv_d != 0) { weakptr_cb_remove(sjv_d, weakptrcb6); }
    delete_cb weakptrcb7 = { &sjv_e, weakptr_clear };
    if (sjv_e != 0) { weakptr_cb_remove(sjv_e, weakptrcb7); }
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
    if (sjt_call5._refCount == 1) { sjf_string_destroy(&sjt_call5); }
;
    if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
