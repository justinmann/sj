#include <lib/common/common.h>

const char* sjg_string1 = "bob";

#define sjs_log_typeId 15
#define sjs_array_char_typeId 17
#define sjs_string_typeId 18
#define sjs_tuple2_i32_string_typeId 19
#define sjs_tuple2_f64_i32_typeId 20

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_tuple2_i32_string sjs_tuple2_i32_string;
typedef struct td_sjs_tuple2_f64_i32 sjs_tuple2_f64_i32;

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

struct td_sjs_tuple2_i32_string {
    int _refCount;
    int32_t item1;
    sjs_string item2;
};

struct td_sjs_tuple2_f64_i32 {
    int _refCount;
    double item1;
    int32_t item2;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
int32_t sjv_a;
sjs_string sjv_b = { -1 };
int32_t sjv_c;
int32_t sjv_clocks_per_sec;
sjs_string sjv_d = { -1 };
double sjv_e;
void* sjv_emptystringdata;
int32_t sjv_f;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
sjs_tuple2_i32_string sjv_t = { -1 };
sjs_tuple2_i32_string sjv_tupleresult1 = { -1 };
sjs_tuple2_i32_string sjv_tupleresult2 = { -1 };
sjs_tuple2_f64_i32 sjv_tupleresult3 = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_func(sjs_tuple2_i32_string* _return);
void sjf_func_heap(sjs_tuple2_i32_string** _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string* _this);
void sjf_tuple2_f64_i32(sjs_tuple2_f64_i32* _this);
void sjf_tuple2_f64_i32_copy(sjs_tuple2_f64_i32* _this, sjs_tuple2_f64_i32* _from);
void sjf_tuple2_f64_i32_destroy(sjs_tuple2_f64_i32* _this);
void sjf_tuple2_f64_i32_heap(sjs_tuple2_f64_i32* _this);
void sjf_tuple2_i32_string(sjs_tuple2_i32_string* _this);
void sjf_tuple2_i32_string_copy(sjs_tuple2_i32_string* _this, sjs_tuple2_i32_string* _from);
void sjf_tuple2_i32_string_destroy(sjs_tuple2_i32_string* _this);
void sjf_tuple2_i32_string_heap(sjs_tuple2_i32_string* _this);
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

void sjf_func(sjs_tuple2_i32_string* _return) {
    _return->_refCount = 1;
    _return->item1 = 1;
    _return->item2._refCount = 1;
    _return->item2.count = 3;
    _return->item2.data._refCount = 1;
    _return->item2.data.datasize = 3;
    _return->item2.data.data = (void*)sjg_string1;
    _return->item2.data.isglobal = true;
    _return->item2.data.count = 3;
    sjf_array_char(&_return->item2.data);
    _return->item2._isnullterminated = false;
    sjf_string(&_return->item2);
    sjf_tuple2_i32_string(_return);
}

void sjf_func_heap(sjs_tuple2_i32_string** _return) {
    (*_return) = (sjs_tuple2_i32_string*)malloc(sizeof(sjs_tuple2_i32_string));
    (*_return)->_refCount = 1;
    (*_return)->item1 = 1;
    (*_return)->item2._refCount = 1;
    (*_return)->item2.count = 3;
    (*_return)->item2.data._refCount = 1;
    (*_return)->item2.data.datasize = 3;
    (*_return)->item2.data.data = (void*)sjg_string1;
    (*_return)->item2.data.isglobal = true;
    (*_return)->item2.data.count = 3;
    sjf_array_char(&(*_return)->item2.data);
    (*_return)->item2._isnullterminated = false;
    sjf_string(&(*_return)->item2);
    sjf_tuple2_i32_string_heap((*_return));
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

void sjf_tuple2_f64_i32(sjs_tuple2_f64_i32* _this) {
}

void sjf_tuple2_f64_i32_copy(sjs_tuple2_f64_i32* _this, sjs_tuple2_f64_i32* _from) {
    _this->item1 = _from->item1;
    _this->item2 = _from->item2;
}

void sjf_tuple2_f64_i32_destroy(sjs_tuple2_f64_i32* _this) {
}

void sjf_tuple2_f64_i32_heap(sjs_tuple2_f64_i32* _this) {
}

void sjf_tuple2_i32_string(sjs_tuple2_i32_string* _this) {
}

void sjf_tuple2_i32_string_copy(sjs_tuple2_i32_string* _this, sjs_tuple2_i32_string* _from) {
    _this->item1 = _from->item1;
    _this->item2._refCount = 1;
    sjf_string_copy(&_this->item2, &_from->item2);
}

void sjf_tuple2_i32_string_destroy(sjs_tuple2_i32_string* _this) {
    if (_this->item2._refCount == 1) { sjf_string_destroy(&_this->item2); }
;
}

void sjf_tuple2_i32_string_heap(sjs_tuple2_i32_string* _this) {
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
    sjf_func(&sjv_t);
    sjv_a = (&sjv_t)->item1;
    sjv_b._refCount = 1;
    sjf_string_copy(&sjv_b, (&(&sjv_t)->item2));
    sjf_func(&sjv_tupleresult1);
    sjv_a = (&sjv_tupleresult1)->item1;
    if (sjv_b._refCount == 1) { sjf_string_destroy(&sjv_b); }
;
    sjf_string_copy(&sjv_b, &(&sjv_tupleresult1)->item2);
    sjf_func(&sjv_tupleresult2);
    sjv_c = (&sjv_tupleresult2)->item1;
    sjv_d._refCount = 1;
    sjf_string_copy(&sjv_d, &(&sjv_tupleresult2)->item2);
    sjv_tupleresult3._refCount = 1;
    sjv_tupleresult3.item1 = 1.0;
    sjv_tupleresult3.item2 = 4;
    sjf_tuple2_f64_i32(&sjv_tupleresult3);
    sjv_e = (&sjv_tupleresult3)->item1;
    sjv_f = (&sjv_tupleresult3)->item2;
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_b._refCount == 1) { sjf_string_destroy(&sjv_b); }
;
    if (sjv_d._refCount == 1) { sjf_string_destroy(&sjv_d); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_t._refCount == 1) { sjf_tuple2_i32_string_destroy(&sjv_t); }
;
    if (sjv_tupleresult1._refCount == 1) { sjf_tuple2_i32_string_destroy(&sjv_tupleresult1); }
;
    if (sjv_tupleresult2._refCount == 1) { sjf_tuple2_i32_string_destroy(&sjv_tupleresult2); }
;
    if (sjv_tupleresult3._refCount == 1) { sjf_tuple2_f64_i32_destroy(&sjv_tupleresult3); }
;
}
