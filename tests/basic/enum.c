#include <lib/common/common.h>

const char* sjg_string1 = "a";
const char* sjg_string2 = "b";
const char* sjg_string3 = "c";
const char* sjg_string4 = "";

#define sjs_log_typeId 1
#define sjs_array_char_typeId 2
#define sjs_string_typeId 3

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

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
sjs_string* sjt_functionParam2 = 0;
int32_option sjv_b;
sjs_string sjv_c = { -1 };
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
void sjf_bar_asstring(int32_t e, sjs_string* _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_func(int32_option* _return);
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

void sjf_bar_asstring(int32_t e, sjs_string* _return) {
    int32_t underscore1;

    underscore1 = e;
    if ((underscore1 == 0)) {
        _return->_refCount = 1;
        _return->count = 1;
        _return->data._refCount = 1;
        _return->data.datasize = 2;
        _return->data.data = (void*)sjg_string1;
        _return->data._isglobal = true;
        _return->data.count = 2;
        sjf_array_char(&_return->data);
        sjf_string(_return);
    } else {
        if ((underscore1 == 1)) {
            _return->_refCount = 1;
            _return->count = 1;
            _return->data._refCount = 1;
            _return->data.datasize = 2;
            _return->data.data = (void*)sjg_string2;
            _return->data._isglobal = true;
            _return->data.count = 2;
            sjf_array_char(&_return->data);
            sjf_string(_return);
        } else {
            if ((underscore1 == 2)) {
                _return->_refCount = 1;
                _return->count = 1;
                _return->data._refCount = 1;
                _return->data.datasize = 2;
                _return->data.data = (void*)sjg_string3;
                _return->data._isglobal = true;
                _return->data.count = 2;
                sjf_array_char(&_return->data);
                sjf_string(_return);
            } else {
                _return->_refCount = 1;
                _return->count = 0;
                _return->data._refCount = 1;
                _return->data.datasize = 1;
                _return->data.data = (void*)sjg_string4;
                _return->data._isglobal = true;
                _return->data.count = 1;
                sjf_array_char(&_return->data);
                sjf_string(_return);
            }
        }
    }
}

void sjf_debug_writeline(sjs_string* data) {
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
    sjv_log._refCount = 1;
    sjv_log.minlevel = sjv_loglevel_warn;
    sjf_log(&sjv_log);
    sjv_emptystringdata = 0;
    sjv_emptystringdata = "";
    ptr_init();
    weakptr_init();
    sjf_func(&sjv_b);
    if (sjv_b.isvalid) {
        int32_t sjt_functionParam1;
        int32_option sjt_getValue1;

        sjt_getValue1 = sjv_b;
        sjt_functionParam1 = sjt_getValue1.value;
        sjf_bar_asstring(sjt_functionParam1, &sjv_c);
    } else {
        sjv_c._refCount = -1;
    }

    sjt_functionParam2 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjf_debug_writeline(sjt_functionParam2);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_c._refCount == 1) { sjf_string_destroy(&sjv_c); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
