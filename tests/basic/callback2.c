#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_sum_typeId 2
#define sjs_class_i32_typeId 3
#define cb_i32_void_typeId 4
#define cb_i32_void_heap_typeId 5
#define sjs_array_i32_typeId 6

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_sum sjs_sum;
typedef struct td_sjs_class_i32 sjs_class_i32;
typedef struct td_cb_i32_void cb_i32_void;
typedef struct td_cb_i32_void_heap cb_i32_void_heap;
typedef struct td_sjs_array_i32 sjs_array_i32;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_sum {
    int _refCount;
    int32_t total;
};

struct td_sjs_class_i32 {
    int _refCount;
    int32_t item1;
    int32_t item2;
};

struct td_cb_i32_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, int32_t);
};

struct td_cb_i32_void_heap {
    cb_i32_void inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_array_i32 {
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
cb_i32_void sjt_functionParam10;
cb_i32_void_heap sjt_functionParam3;
int32_t sjt_functionParam4;
int32_t sjt_functionParam5;
int32_t sjt_functionParam6;
int32_t sjt_functionParam7;
sjs_class_i32* sjt_parent1 = 0;
sjs_array_i32* sjt_parent2 = 0;
sjs_array_i32* sjt_parent3 = 0;
sjs_array_i32* sjt_parent4 = 0;
sjs_array_i32 sjv_a = { -1 };
sjs_class_i32 sjv_c = { -1 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
sjs_sum* sjv_s = 0;
uint32_t sjv_u32_maxvalue;

void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_each(sjs_array_i32* _parent, cb_i32_void cb);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_class_i32(sjs_class_i32* _this);
void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from);
void sjf_class_i32_destroy(sjs_class_i32* _this);
void sjf_class_i32_each(sjs_class_i32* _parent, cb_i32_void_heap cb);
void sjf_class_i32_heap(sjs_class_i32* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_sum(sjs_sum* _this);
void sjf_sum_copy(sjs_sum* _this, sjs_sum* _from);
void sjf_sum_destroy(sjs_sum* _this);
void sjf_sum_heap(sjs_sum* _this);
void sjf_sum_invoke(sjs_sum* _parent, int32_t a);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_array_i32(sjs_array_i32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(int32_t) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
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

void sjf_array_i32_destroy(sjs_array_i32* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            int32_t* p = (int32_t*)_this->data;
            #if !true
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
        }
    }
}

void sjf_array_i32_each(sjs_array_i32* _parent, cb_i32_void cb) {
    int32_t i;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

    sjt_forStart1 = 0;
    sjt_forEnd1 = _parent->count;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        int32_t sjt_functionParam8;
        int32_t sjt_functionParam9;

        sjt_functionParam9 = i;
        sjf_array_i32_getat(_parent, sjt_functionParam9, &sjt_functionParam8);
        cb._cb(cb._parent, sjt_functionParam8);
        i++;
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
        _this->data = (int*)malloc(_this->datasize * sizeof(int32_t) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
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

void sjf_class_i32(sjs_class_i32* _this) {
}

void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from) {
    _this->item1 = _from->item1;
    _this->item2 = _from->item2;
}

void sjf_class_i32_destroy(sjs_class_i32* _this) {
}

void sjf_class_i32_each(sjs_class_i32* _parent, cb_i32_void_heap cb) {
    int32_t sjt_functionParam1;
    int32_t sjt_functionParam2;

    sjt_functionParam1 = _parent->item1;
    cb.inner._cb(cb.inner._parent, sjt_functionParam1);
    sjt_functionParam2 = _parent->item2;
    cb.inner._cb(cb.inner._parent, sjt_functionParam2);
}

void sjf_class_i32_heap(sjs_class_i32* _this) {
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
    _this->total = _from->total;
}

void sjf_sum_destroy(sjs_sum* _this) {
}

void sjf_sum_heap(sjs_sum* _this) {
}

void sjf_sum_invoke(sjs_sum* _parent, int32_t a) {
    _parent->total = _parent->total + a;
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
    sjv_s = (sjs_sum*)malloc(sizeof(sjs_sum));
    sjv_s->_refCount = 1;
    sjv_s->total = 0;
    sjf_sum_heap(sjv_s);
    sjv_c._refCount = 1;
    sjv_c.item1 = 3;
    sjv_c.item2 = 4;
    sjf_class_i32(&sjv_c);
    sjt_parent1 = &sjv_c;
    sjt_functionParam3.inner._parent = (sjs_object*)sjv_s;
    sjt_functionParam3.inner._parent->_refCount++;
    sjt_functionParam3._destroy = (void(*)(sjs_object*))sjf_sum_destroy;
    sjt_functionParam3.inner._cb = (void(*)(sjs_object*,int32_t))sjf_sum_invoke;
    sjf_class_i32_each(sjt_parent1, sjt_functionParam3);
    sjv_a._refCount = 1;
    sjv_a.datasize = 2;
    sjv_a.data = 0;
    sjv_a.isglobal = false;
    sjv_a.count = 0;
    sjf_array_i32(&sjv_a);
    sjs_array_i32* array1;
    array1 = &sjv_a;
    sjt_parent2 = array1;
    sjt_functionParam4 = 0;
    sjt_functionParam5 = 1;
    sjf_array_i32_initat(sjt_parent2, sjt_functionParam4, sjt_functionParam5);
    sjt_parent3 = array1;
    sjt_functionParam6 = 1;
    sjt_functionParam7 = 2;
    sjf_array_i32_initat(sjt_parent3, sjt_functionParam6, sjt_functionParam7);
    sjt_parent4 = &sjv_a;
    sjt_functionParam10._parent = (sjs_object*)sjv_s;
    sjt_functionParam10._cb = (void(*)(sjs_object*,int32_t))sjf_sum_invoke;
    sjf_array_i32_each(sjt_parent4, sjt_functionParam10);
    main_destroy();
    return 0;
}

void main_destroy() {

    if ((uintptr_t)sjt_functionParam3.inner._parent > 1) {
        sjt_functionParam3.inner._parent->_refCount--;
        if (sjt_functionParam3.inner._parent->_refCount <= 0) {
            sjt_functionParam3._destroy(sjt_functionParam3.inner._parent);
            free(sjt_functionParam3.inner._parent);
        }
    }
    sjv_s->_refCount--;
    if (sjv_s->_refCount <= 0) {
        weakptr_release(sjv_s);
        sjf_sum_destroy(sjv_s);
        free(sjv_s);
    }
    if (sjv_a._refCount == 1) { sjf_array_i32_destroy(&sjv_a); }
;
    if (sjv_c._refCount == 1) { sjf_class_i32_destroy(&sjv_c); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
