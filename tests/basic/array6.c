#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_array_i32_typeId 2
#define sjs_array_f32_typeId 3
#define cb_i32_f32_typeId 4
#define cb_i32_f32_heap_typeId 5
#define cb_f32_bool_typeId 6
#define cb_f32_bool_heap_typeId 7
#define sjs_sum_typeId 8
#define cb_sum_f32_sum_typeId 9
#define cb_sum_f32_sum_heap_typeId 10
#define cb_sum_f32_sum_heap_sum_typeId 11
#define cb_sum_f32_sum_heap_sum_heap_typeId 12

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sjs_array_f32 sjs_array_f32;
typedef struct td_cb_i32_f32 cb_i32_f32;
typedef struct td_cb_i32_f32_heap cb_i32_f32_heap;
typedef struct td_cb_f32_bool cb_f32_bool;
typedef struct td_cb_f32_bool_heap cb_f32_bool_heap;
typedef struct td_sjs_sum sjs_sum;
typedef struct td_cb_sum_f32_sum cb_sum_f32_sum;
typedef struct td_cb_sum_f32_sum_heap cb_sum_f32_sum_heap;
typedef struct td_cb_sum_f32_sum_heap_sum cb_sum_f32_sum_heap_sum;
typedef struct td_cb_sum_f32_sum_heap_sum_heap cb_sum_f32_sum_heap_sum_heap;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_array_i32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_array_f32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_cb_i32_f32 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, int32_t, float* _return);
};

struct td_cb_i32_f32_heap {
    cb_i32_f32 inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_f32_bool {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, float, bool* _return);
};

struct td_cb_f32_bool_heap {
    cb_f32_bool inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_sum {
    int _refCount;
    float x;
};

struct td_cb_sum_f32_sum {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_sum*, float, sjs_sum* _return);
};

struct td_cb_sum_f32_sum_heap {
    cb_sum_f32_sum inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_sum_f32_sum_heap_sum {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_sum*, float, sjs_sum* _return);
    void (*_cb_heap)(sjs_object* _parent, sjs_sum*, float, sjs_sum** _return);
};

struct td_cb_sum_f32_sum_heap_sum_heap {
    cb_sum_f32_sum_heap_sum inner;
    void (*_destroy)(sjs_object*);
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_sum sjt_call3 = { -1 };
int32_t sjt_functionParam1;
cb_i32_f32 sjt_functionParam11;
cb_f32_bool sjt_functionParam16;
int32_t sjt_functionParam2;
sjs_sum* sjt_functionParam23 = 0;
cb_sum_f32_sum sjt_functionParam24;
int32_t sjt_functionParam3;
int32_t sjt_functionParam4;
int32_t sjt_functionParam5;
int32_t sjt_functionParam6;
sjs_array_i32* sjt_parent1 = 0;
sjs_array_i32* sjt_parent2 = 0;
sjs_array_i32* sjt_parent3 = 0;
sjs_array_i32* sjt_parent4 = 0;
sjs_array_f32* sjt_parent5 = 0;
sjs_array_f32* sjt_parent6 = 0;
sjs_array_i32 sjv_a = { -1 };
sjs_array_f32 sjv_b = { -1 };
sjs_array_f32 sjv_c = { -1 };
sjs_sum sjv_d = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_f32(sjs_array_f32* _this);
void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from);
void sjf_array_f32_destroy(sjs_array_f32* _this);
void sjf_array_f32_filter(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32* _return);
void sjf_array_f32_filter_heap(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32** _return);
void sjf_array_f32_foldl_sum(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum* _return);
void sjf_array_f32_foldl_sum_heap(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum** _return);
void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return);
void sjf_array_f32_heap(sjs_array_f32* _this);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_i32_map_f32(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32* _return);
void sjf_array_i32_map_f32_heap(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32** _return);
void sjf_double(int32_t x, float* _return);
void sjf_double_callback(void * _parent, int32_t x, float* _return);
void sjf_lessthan5(float x, bool* _return);
void sjf_lessthan5_callback(void * _parent, float x, bool* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_sum(sjs_sum* _this);
void sjf_sum_copy(sjs_sum* _this, sjs_sum* _from);
void sjf_sum_destroy(sjs_sum* _this);
void sjf_sum_heap(sjs_sum* _this);
void sjf_sumadd(sjs_sum* sum, float x, sjs_sum* _return);
void sjf_sumadd_callback(void * _parent, sjs_sum* sum, float x, sjs_sum* _return);
void sjf_sumadd_heap(sjs_sum* sum, float x, sjs_sum** _return);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_array_f32(sjs_array_f32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(float));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_f32_destroy(sjs_array_f32* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            float* p = (float*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_f32_filter(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32* _return) {
    int32_t i;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;
    int32_t sjv_newcount;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newcount = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart3 = 0;
    sjt_forEnd3 = _parent->count;
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        bool sjt_capture1;
        int32_t sjt_functionParam12;
        float sjt_functionParam13;
        float sjv_item;

        sjt_functionParam12 = i;
        sjf_array_f32_getat(_parent, sjt_functionParam12, &sjv_item);
        sjt_functionParam13 = sjv_item;
        cb._cb(cb._parent, sjt_functionParam13, &sjt_capture1);
        if (sjt_capture1) {
            float* p = (float*)sjv_newdata;
            p[sjv_newcount] = sjv_item;
;
            sjv_newcount = sjv_newcount + 1;
        }

        i++;
    }

    _return->_refCount = 1;
    _return->datasize = _parent->count;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    _return->count = sjv_newcount;
    sjf_array_f32(_return);
}

void sjf_array_f32_filter_heap(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32** _return) {
    int32_t i;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    int32_t sjv_newcount;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newcount = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart4 = 0;
    sjt_forEnd4 = _parent->count;
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        bool sjt_capture2;
        int32_t sjt_functionParam14;
        float sjt_functionParam15;
        float sjv_item;

        sjt_functionParam14 = i;
        sjf_array_f32_getat(_parent, sjt_functionParam14, &sjv_item);
        sjt_functionParam15 = sjv_item;
        cb._cb(cb._parent, sjt_functionParam15, &sjt_capture2);
        if (sjt_capture2) {
            float* p = (float*)sjv_newdata;
            p[sjv_newcount] = sjv_item;
;
            sjv_newcount = sjv_newcount + 1;
        }

        i++;
    }

    (*_return) = (sjs_array_f32*)malloc(sizeof(sjs_array_f32));
    (*_return)->_refCount = 1;
    (*_return)->datasize = _parent->count;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    (*_return)->count = sjv_newcount;
    sjf_array_f32_heap((*_return));
}

void sjf_array_f32_foldl_sum(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum* _return) {
    int32_t i;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;
    sjs_sum* sjv_r = 0;

    sjv_r = initial;
    sjt_forStart5 = 0;
    sjt_forEnd5 = _parent->count;
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        sjs_sum sjt_call1 = { -1 };
        sjs_sum* sjt_functionParam17 = 0;
        float sjt_functionParam18;
        int32_t sjt_functionParam19;

        sjt_functionParam17 = sjv_r;
        sjt_functionParam19 = i;
        sjf_array_f32_getat(_parent, sjt_functionParam19, &sjt_functionParam18);
        cb._cb(cb._parent, sjt_functionParam17, sjt_functionParam18, &sjt_call1);
        sjv_r = &sjt_call1;
        i++;

        if (sjt_call1._refCount == 1) { sjf_sum_destroy(&sjt_call1); }
;
    }

    _return->_refCount = 1;
    sjf_sum_copy(_return, sjv_r);
}

void sjf_array_f32_foldl_sum_heap(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum** _return) {
    int32_t i;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;
    sjs_sum* sjv_r = 0;

    sjv_r = initial;
    sjt_forStart6 = 0;
    sjt_forEnd6 = _parent->count;
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        sjs_sum sjt_call2 = { -1 };
        sjs_sum* sjt_functionParam20 = 0;
        float sjt_functionParam21;
        int32_t sjt_functionParam22;

        sjt_functionParam20 = sjv_r;
        sjt_functionParam22 = i;
        sjf_array_f32_getat(_parent, sjt_functionParam22, &sjt_functionParam21);
        cb._cb(cb._parent, sjt_functionParam20, sjt_functionParam21, &sjt_call2);
        sjv_r = &sjt_call2;
        i++;

        if (sjt_call2._refCount == 1) { sjf_sum_destroy(&sjt_call2); }
;
    }

    (*_return) = (sjs_sum*)malloc(sizeof(sjs_sum));
    (*_return)->_refCount = 1;
    sjf_sum_copy((*_return), sjv_r);
}

void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    float* p = (float*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_f32_heap(sjs_array_f32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(float));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32(sjs_array_i32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(int32_t));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            int32_t* p = (int32_t*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    int32_t* p = (int32_t*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_i32_heap(sjs_array_i32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(int32_t));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    int32_t* p = (int32_t*)_parent->data;
    p[index] = item;
;
    _parent->count = index + 1;
}

void sjf_array_i32_map_f32(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32* _return) {
    int32_t i;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart1 = 0;
    sjt_forEnd1 = _parent->count;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        int32_t sjt_functionParam7;
        int32_t sjt_functionParam8;
        float sjv_newitem;

        sjt_functionParam8 = i;
        sjf_array_i32_getat(_parent, sjt_functionParam8, &sjt_functionParam7);
        cb._cb(cb._parent, sjt_functionParam7, &sjv_newitem);
        float* p = (float*)sjv_newdata;
        p[i] = sjv_newitem;
;
        i++;
    }

    _return->_refCount = 1;
    _return->datasize = _parent->count;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    _return->count = _parent->count;
    sjf_array_f32(_return);
}

void sjf_array_i32_map_f32_heap(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32** _return) {
    int32_t i;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart2 = 0;
    sjt_forEnd2 = _parent->count;
    i = sjt_forStart2;
    while (i < sjt_forEnd2) {
        int32_t sjt_functionParam10;
        int32_t sjt_functionParam9;
        float sjv_newitem;

        sjt_functionParam10 = i;
        sjf_array_i32_getat(_parent, sjt_functionParam10, &sjt_functionParam9);
        cb._cb(cb._parent, sjt_functionParam9, &sjv_newitem);
        float* p = (float*)sjv_newdata;
        p[i] = sjv_newitem;
;
        i++;
    }

    (*_return) = (sjs_array_f32*)malloc(sizeof(sjs_array_f32));
    (*_return)->_refCount = 1;
    (*_return)->datasize = _parent->count;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    (*_return)->count = _parent->count;
    sjf_array_f32_heap((*_return));
}

void sjf_double(int32_t x, float* _return) {
    int32_t sjt_cast1;

    sjt_cast1 = x;
    (*_return) = (float)sjt_cast1 * 2.0f;
}

void sjf_double_callback(void * _parent, int32_t x, float* _return) {
    sjf_double(x, _return);
}

void sjf_lessthan5(float x, bool* _return) {
    (*_return) = x < 5.0f;
}

void sjf_lessthan5_callback(void * _parent, float x, bool* _return) {
    sjf_lessthan5(x, _return);
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

void sjf_sum(sjs_sum* _this) {
}

void sjf_sum_copy(sjs_sum* _this, sjs_sum* _from) {
    _this->x = _from->x;
}

void sjf_sum_destroy(sjs_sum* _this) {
}

void sjf_sum_heap(sjs_sum* _this) {
}

void sjf_sumadd(sjs_sum* sum, float x, sjs_sum* _return) {
    _return->_refCount = 1;
    _return->x = sum->x + x;
    sjf_sum(_return);
}

void sjf_sumadd_callback(void * _parent, sjs_sum* sum, float x, sjs_sum* _return) {
    sjf_sumadd(sum, x, _return);
}

void sjf_sumadd_heap(sjs_sum* sum, float x, sjs_sum** _return) {
    (*_return) = (sjs_sum*)malloc(sizeof(sjs_sum));
    (*_return)->_refCount = 1;
    (*_return)->x = sum->x + x;
    sjf_sum_heap((*_return));
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
    sjv_a.datasize = 3;
    sjv_a.data = 0;
    sjv_a._isglobal = false;
    sjv_a.count = 0;
    sjf_array_i32(&sjv_a);
    sjs_array_i32* array1;
    array1 = &sjv_a;
    sjt_parent1 = array1;
    sjt_functionParam1 = 0;
    sjt_functionParam2 = 1;
    sjf_array_i32_initat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent2 = array1;
    sjt_functionParam3 = 1;
    sjt_functionParam4 = 2;
    sjf_array_i32_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
    sjt_parent3 = array1;
    sjt_functionParam5 = 2;
    sjt_functionParam6 = 3;
    sjf_array_i32_initat(sjt_parent3, sjt_functionParam5, sjt_functionParam6);
    sjt_parent4 = &sjv_a;
    sjt_functionParam11._parent = (sjs_object*)1;
    sjt_functionParam11._cb = (void(*)(sjs_object*,int32_t, float*))sjf_double_callback;
    sjf_array_i32_map_f32(sjt_parent4, sjt_functionParam11, &sjv_b);
    sjt_parent5 = &sjv_b;
    sjt_functionParam16._parent = (sjs_object*)1;
    sjt_functionParam16._cb = (void(*)(sjs_object*,float, bool*))sjf_lessthan5_callback;
    sjf_array_f32_filter(sjt_parent5, sjt_functionParam16, &sjv_c);
    sjt_parent6 = &sjv_c;
    sjt_call3._refCount = 1;
    sjt_call3.x = 0.0f;
    sjf_sum(&sjt_call3);
    sjt_functionParam23 = &sjt_call3;
    sjt_functionParam24._parent = (sjs_object*)1;
    sjt_functionParam24._cb = (void(*)(sjs_object*,sjs_sum*,float, sjs_sum*))sjf_sumadd_callback;
    sjf_array_f32_foldl_sum(sjt_parent6, sjt_functionParam23, sjt_functionParam24, &sjv_d);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call3._refCount == 1) { sjf_sum_destroy(&sjt_call3); }
;
    if (sjv_a._refCount == 1) { sjf_array_i32_destroy(&sjv_a); }
;
    if (sjv_b._refCount == 1) { sjf_array_f32_destroy(&sjv_b); }
;
    if (sjv_c._refCount == 1) { sjf_array_f32_destroy(&sjv_c); }
;
    if (sjv_d._refCount == 1) { sjf_sum_destroy(&sjv_d); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
