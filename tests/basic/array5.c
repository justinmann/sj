#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_class_typeId 2
#define sjs_array_class_typeId 3

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_array_class sjs_array_class;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

struct td_sjs_array_class {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_class sjt_call1 = { -1 };
sjs_class sjt_call2 = { -1 };
sjs_class sjt_call3 = { -1 };
sjs_class sjt_call4 = { -1 };
int32_t sjt_functionParam1;
sjs_class* sjt_functionParam2 = 0;
int32_t sjt_functionParam3;
sjs_class* sjt_functionParam4 = 0;
int32_t sjt_functionParam5;
sjs_class* sjt_functionParam6 = 0;
int32_t sjt_functionParam7;
sjs_array_class* sjt_parent1 = 0;
sjs_array_class* sjt_parent2 = 0;
sjs_array_class* sjt_parent3 = 0;
sjs_array_class* sjt_parent4 = 0;
sjs_array_class sjv_a = { -1 };
sjs_class* sjv_c = 0;
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_class(sjs_array_class* _this);
void sjf_array_class_copy(sjs_array_class* _this, sjs_array_class* _from);
void sjf_array_class_destroy(sjs_array_class* _this);
void sjf_array_class_getat(sjs_array_class* _parent, int32_t index, sjs_class* _return);
void sjf_array_class_heap(sjs_array_class* _this);
void sjf_array_class_initat(sjs_array_class* _parent, int32_t index, sjs_class* item);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_array_class(sjs_array_class* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_class_copy(sjs_array_class* _this, sjs_array_class* _from) {
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

void sjf_array_class_destroy(sjs_array_class* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            sjs_class* p = (sjs_class*)_this->data;
            #if !false
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
        }
    }
}

void sjf_array_class_getat(sjs_array_class* _parent, int32_t index, sjs_class* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_class* p = (sjs_class*)_parent->data;
    _return->_refCount = 1;
sjf_class_copy(_return, &p[index]);
return;;       
}

void sjf_array_class_heap(sjs_array_class* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_class_initat(sjs_array_class* _parent, int32_t index, sjs_class* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sjs_class* p = (sjs_class*)_parent->data;
    p[index]._refCount = 1;
sjf_class_copy(&p[index], item);
;
    _parent->count = index + 1;
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

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
    _this->minlevel = _from->minlevel;
}

void sjf_log_destroy(sjs_log* _this) {
}

void sjf_log_heap(sjs_log* _this) {
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
    sjv_a.datasize = 3;
    sjv_a.data = 0;
    sjv_a.isglobal = false;
    sjv_a.count = 0;
    sjf_array_class(&sjv_a);
    sjs_array_class* array1;
    array1 = &sjv_a;
    sjt_parent1 = array1;
    sjt_functionParam1 = 0;
    sjt_call1._refCount = 1;
    sjt_call1.x = 1;
    sjf_class(&sjt_call1);
    sjt_functionParam2 = &sjt_call1;
    sjf_array_class_initat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent2 = array1;
    sjt_functionParam3 = 1;
    sjt_call2._refCount = 1;
    sjt_call2.x = 2;
    sjf_class(&sjt_call2);
    sjt_functionParam4 = &sjt_call2;
    sjf_array_class_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
    sjt_parent3 = array1;
    sjt_functionParam5 = 2;
    sjt_call3._refCount = 1;
    sjt_call3.x = 3;
    sjf_class(&sjt_call3);
    sjt_functionParam6 = &sjt_call3;
    sjf_array_class_initat(sjt_parent3, sjt_functionParam5, sjt_functionParam6);
    sjt_parent4 = &sjv_a;
    sjt_functionParam7 = 0;
    sjf_array_class_getat(sjt_parent4, sjt_functionParam7, &sjt_call4);
    sjv_c = &sjt_call4;
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
;
    if (sjt_call2._refCount == 1) { sjf_class_destroy(&sjt_call2); }
;
    if (sjt_call3._refCount == 1) { sjf_class_destroy(&sjt_call3); }
;
    if (sjt_call4._refCount == 1) { sjf_class_destroy(&sjt_call4); }
;
    if (sjv_a._refCount == 1) { sjf_array_class_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
