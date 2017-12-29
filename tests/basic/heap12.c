#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_class_typeId 2
#define sjs_array_heap_class_typeId 3
#define sjs_list_heap_class_typeId 4

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_array_heap_class sjs_array_heap_class;
typedef struct td_sjs_list_heap_class sjs_list_heap_class;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

struct td_sjs_array_heap_class {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_list_heap_class {
    int _refCount;
    sjs_array_heap_class array;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t i;
int32_t result1;
int32_t sjt_forEnd1;
int32_t sjt_forStart1;
sjs_list_heap_class sjv_a = { -1 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_heap_class(sjs_array_heap_class* _this);
void sjf_array_heap_class_copy(sjs_array_heap_class* _this, sjs_array_heap_class* _from);
void sjf_array_heap_class_destroy(sjs_array_heap_class* _this);
void sjf_array_heap_class_grow(sjs_array_heap_class* _parent, int32_t newsize, sjs_array_heap_class* _return);
void sjf_array_heap_class_grow_heap(sjs_array_heap_class* _parent, int32_t newsize, sjs_array_heap_class** _return);
void sjf_array_heap_class_heap(sjs_array_heap_class* _this);
void sjf_array_heap_class_initat(sjs_array_heap_class* _parent, int32_t index, sjs_class* item);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_i32_max(int32_t a, int32_t b, int32_t* _return);
void sjf_list_heap_class(sjs_list_heap_class* _this);
void sjf_list_heap_class_add(sjs_list_heap_class* _parent, sjs_class* item);
void sjf_list_heap_class_copy(sjs_list_heap_class* _this, sjs_list_heap_class* _from);
void sjf_list_heap_class_destroy(sjs_list_heap_class* _this);
void sjf_list_heap_class_heap(sjs_list_heap_class* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_array_heap_class(sjs_array_heap_class* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class*) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_class_copy(sjs_array_heap_class* _this, sjs_array_heap_class* _from) {
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

void sjf_array_heap_class_destroy(sjs_array_heap_class* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            sjs_class** p = (sjs_class**)_this->data;
            #if !false
            for (int i = 0; i < _this->count; i++) {
                p[i]->_refCount--;
if (p[i]->_refCount <= 0) {
    weakptr_release(p[i]);
    sjf_class_destroy(p[i]);
    free(p[i]);
}
;
            }
            #endif
            free(refcount);
        }
    }
}

void sjf_array_heap_class_grow(sjs_array_heap_class* _parent, int32_t newsize, sjs_array_heap_class* _return) {
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(sjs_class*))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sjs_class** p = (sjs_class**)_parent->data;
        sjs_class** newp = (sjs_class**)sjv_newdata;
        int count = _parent->count;
        #if false
        memcpy(newp, p, sizeof(sjs_class*) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
newp[i]->_refCount++;
;
        }
        #endif
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->isglobal = false;
    _return->count = _parent->count;
    sjf_array_heap_class(_return);
}

void sjf_array_heap_class_grow_heap(sjs_array_heap_class* _parent, int32_t newsize, sjs_array_heap_class** _return) {
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(sjs_class*))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sjs_class** p = (sjs_class**)_parent->data;
        sjs_class** newp = (sjs_class**)sjv_newdata;
        int count = _parent->count;
        #if false
        memcpy(newp, p, sizeof(sjs_class*) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
newp[i]->_refCount++;
;
        }
        #endif
    }
    (*_return) = (sjs_array_heap_class*)malloc(sizeof(sjs_array_heap_class));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->isglobal = false;
    (*_return)->count = _parent->count;
    sjf_array_heap_class_heap((*_return));
}

void sjf_array_heap_class_heap(sjs_array_heap_class* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class*) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_class_initat(sjs_array_heap_class* _parent, int32_t index, sjs_class* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sjs_class** p = (sjs_class**)_parent->data;
    p[index] = item;
p[index]->_refCount++;
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

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    if (a < b) {
        (*_return) = b;
    } else {
        (*_return) = a;
    }
}

void sjf_list_heap_class(sjs_list_heap_class* _this) {
}

void sjf_list_heap_class_add(sjs_list_heap_class* _parent, sjs_class* item) {
    sjs_array_heap_class sjt_call1 = { -1 };
    int32_t sjt_functionParam4;
    sjs_class* sjt_functionParam5 = 0;
    sjs_array_heap_class* sjt_parent2 = 0;

    if ((&_parent->array)->count >= (&_parent->array)->datasize) {
        int32_t sjt_functionParam1;
        int32_t sjt_functionParam2;
        int32_t sjt_functionParam3;
        sjs_array_heap_class* sjt_parent1 = 0;

        sjt_parent1 = &_parent->array;
        sjt_functionParam2 = 10;
        sjt_functionParam3 = (&_parent->array)->datasize * 2;
        sjf_i32_max(sjt_functionParam2, sjt_functionParam3, &sjt_functionParam1);
        sjf_array_heap_class_grow(sjt_parent1, sjt_functionParam1, &sjt_call1);
        if (_parent->array._refCount == 1) { sjf_array_heap_class_destroy(&_parent->array); }
;
        _parent->array._refCount = 1;
        sjf_array_heap_class_copy(&_parent->array, (&sjt_call1));
    }

    sjt_parent2 = &_parent->array;
    sjt_functionParam4 = (&_parent->array)->count;
    sjt_functionParam5 = item;
    sjt_functionParam5->_refCount++;
    sjf_array_heap_class_initat(sjt_parent2, sjt_functionParam4, sjt_functionParam5);

    sjt_functionParam5->_refCount--;
    if (sjt_functionParam5->_refCount <= 0) {
        weakptr_release(sjt_functionParam5);
        sjf_class_destroy(sjt_functionParam5);
        free(sjt_functionParam5);
    }
    if (sjt_call1._refCount == 1) { sjf_array_heap_class_destroy(&sjt_call1); }
;
}

void sjf_list_heap_class_copy(sjs_list_heap_class* _this, sjs_list_heap_class* _from) {
    _this->array._refCount = 1;
    sjf_array_heap_class_copy(&_this->array, &_from->array);
}

void sjf_list_heap_class_destroy(sjs_list_heap_class* _this) {
    if (_this->array._refCount == 1) { sjf_array_heap_class_destroy(&_this->array); }
;
}

void sjf_list_heap_class_heap(sjs_list_heap_class* _this) {
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
    sjv_a.array._refCount = 1;
    sjv_a.array.datasize = 0;
    sjv_a.array.data = 0;
    sjv_a.array.isglobal = false;
    sjv_a.array.count = 0;
    sjf_array_heap_class(&sjv_a.array);
    sjf_list_heap_class(&sjv_a);
    sjt_forStart1 = 0;
    sjt_forEnd1 = 100;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_class* sjt_functionParam6 = 0;
        sjs_list_heap_class* sjt_parent3 = 0;

        sjt_parent3 = &sjv_a;
        sjt_functionParam6 = (sjs_class*)malloc(sizeof(sjs_class));
        sjt_functionParam6->_refCount = 1;
        sjt_functionParam6->x = i;
        sjf_class_heap(sjt_functionParam6);
        sjf_list_heap_class_add(sjt_parent3, sjt_functionParam6);
        i++;

        sjt_functionParam6->_refCount--;
        if (sjt_functionParam6->_refCount <= 0) {
            weakptr_release(sjt_functionParam6);
            sjf_class_destroy(sjt_functionParam6);
            free(sjt_functionParam6);
        }
    }
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_a._refCount == 1) { sjf_list_heap_class_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
