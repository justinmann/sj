#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_array_char_typeId 2
#define sjs_string_typeId 3
#define sjs_class_typeId 4

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
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

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
int32_t sjt_functionParam1;
int32_t sjt_functionParam2;
sjs_class* sjt_functionParam3 = 0;
sjs_string sjt_void1 = { -1 };
int32_t sjt_void2;
sjs_class* sjv_c = 0;
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
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_class(sjs_class* _this);
void sjf_class_asstring(sjs_class* x, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return);
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

void sjf_class(sjs_class* _this) {
}

void sjf_class_asstring(sjs_class* x, int32_t* _return) {
    (*_return) = 2;
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
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
    sjt_functionParam1 = 3;
    sjt_functionParam2 = 10;
    sjf_i32_asstring(sjt_functionParam1, sjt_functionParam2, &sjt_void1);
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->x = 3;
    sjf_class_heap(sjv_c);
    sjt_functionParam3 = sjv_c;
    sjf_class_asstring(sjt_functionParam3, &sjt_void2);
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
    if (sjt_void1._refCount == 1) { sjf_string_destroy(&sjt_void1); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
