#include <lib/common/common.h>

const char* sjg_string1 = "he\"llo";
const char* sjg_string2 = "he\nllo";
const char* sjg_string3 = "hello";

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
    bool isglobal;
    int32_t count;
};

struct td_sjs_string {
    int _refCount;
    int32_t count;
    sjs_array_char data;
    bool _isnullterminated;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
int32_t sjt_functionParam2;
sjs_string* sjt_functionParam4 = 0;
sjs_string* sjt_functionParam6 = 0;
sjs_string* sjt_parent2 = 0;
sjs_string* sjt_parent4 = 0;
sjs_string* sjt_parent6 = 0;
sjs_string sjv_a = { -1 };
sjs_string sjv_b = { -1 };
char sjv_c;
int32_t sjv_clocks_per_sec;
char sjv_d;
char sjv_e;
void* sjv_emptystringdata;
sjs_string sjv_f = { -1 };
float sjv_f32_pi;
char sjv_h;
bool sjv_i;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
bool sjv_j;
bool sjv_k;
bool sjv_l;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_array_char_islessorequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return);
void sjf_string_islessorequal(sjs_string* _parent, sjs_string* test, bool* _return);
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

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    char* p = (char*)_parent->data;
    (*_return) = p[index];
return;;       
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

void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
    if (_parent->count != test->count) {
        *_return = false;
    }
    bool result = memcmp(_parent->data, test->data, _parent->count * sizeof(char)) == 0;
    (*_return) = result;
return;;      
}

void sjf_array_char_islessorequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
    bool result = memcmp(_parent->data, test->data, (_parent->count < test->count ? _parent->count : test->count) * sizeof(char)) <= 0;     
    (*_return) = result;
return;;      
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

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam1;
    sjs_array_char* sjt_parent1 = 0;

    sjt_parent1 = &_parent->data;
    sjt_functionParam1 = index;
    sjf_array_char_getat(sjt_parent1, sjt_functionParam1, _return);
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_array_char* sjt_functionParam3 = 0;
    sjs_array_char* sjt_parent3 = 0;

    sjt_parent3 = &_parent->data;
    sjt_functionParam3 = &test->data;
    sjf_array_char_isequal(sjt_parent3, sjt_functionParam3, _return);
}

void sjf_string_islessorequal(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_array_char* sjt_functionParam5 = 0;
    sjs_array_char* sjt_parent5 = 0;

    sjt_parent5 = &_parent->data;
    sjt_functionParam5 = &test->data;
    sjf_array_char_islessorequal(sjt_parent5, sjt_functionParam5, _return);
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
    sjv_a._refCount = 1;
    sjv_a.count = 7;
    sjv_a.data._refCount = 1;
    sjv_a.data.datasize = 7;
    sjv_a.data.data = (void*)sjg_string1;
    sjv_a.data.isglobal = true;
    sjv_a.data.count = 7;
    sjf_array_char(&sjv_a.data);
    sjv_a._isnullterminated = false;
    sjf_string(&sjv_a);
    sjv_b._refCount = 1;
    sjv_b.count = 7;
    sjv_b.data._refCount = 1;
    sjv_b.data.datasize = 7;
    sjv_b.data.data = (void*)sjg_string2;
    sjv_b.data.isglobal = true;
    sjv_b.data.count = 7;
    sjf_array_char(&sjv_b.data);
    sjv_b._isnullterminated = false;
    sjf_string(&sjv_b);
    sjv_c = 'a';
    sjv_d = '\'';
    sjv_e = '\n';
    sjv_f._refCount = 1;
    sjv_f.count = 5;
    sjv_f.data._refCount = 1;
    sjv_f.data.datasize = 5;
    sjv_f.data.data = (void*)sjg_string3;
    sjv_f.data.isglobal = true;
    sjv_f.data.count = 5;
    sjf_array_char(&sjv_f.data);
    sjv_f._isnullterminated = false;
    sjf_string(&sjv_f);
    sjt_parent2 = &sjv_a;
    sjt_functionParam2 = 0;
    sjf_string_getat(sjt_parent2, sjt_functionParam2, &sjv_h);
    sjv_i = sjv_h == 'h';
    sjt_parent4 = &sjv_f;
    sjt_functionParam4 = &sjv_a;
    sjf_string_isequal(sjt_parent4, sjt_functionParam4, &sjv_j);
    sjt_parent6 = &sjv_f;
    sjt_functionParam6 = &sjv_a;
    sjf_string_islessorequal(sjt_parent6, sjt_functionParam6, &sjv_k);
    sjv_l = (&sjv_f) == (&sjv_a);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_a._refCount == 1) { sjf_string_destroy(&sjv_a); }
;
    if (sjv_b._refCount == 1) { sjf_string_destroy(&sjv_b); }
;
    if (sjv_f._refCount == 1) { sjf_string_destroy(&sjv_f); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
