#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isEmpty;
    int32_t value;
};
const int32_option int32_empty = { true };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isEmpty;
    uint32_t value;
};
const uint32_option uint32_empty = { true };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isEmpty;
    int64_t value;
};
const int64_option int64_empty = { true };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isEmpty;
    uint64_t value;
};
const uint64_option uint64_empty = { true };

typedef struct td_uintptr_option uintptr_option;
struct td_uintptr_option {
    bool isEmpty;
    uintptr_t value;
};
const uintptr_option uintptr_empty = { true };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isEmpty;
    char value;
};
const char_option char_empty = { true };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isEmpty;
    float value;
};
const float_option float_empty = { true };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isEmpty;
    double value;
};
const double_option double_empty = { true };

#define sjs_object_typeId 1
#define cb_i32_data_heap_data_typeId 2
#define cb_i32_data_heap_data_heap_typeId 3
#define sjs_data_typeId 4
#define sjs_data_heap_typeId 5
#define sjs_class_typeId 6
#define sjs_class_heap_typeId 7

typedef struct td_sjs_object sjs_object;
typedef struct td_cb_i32_data_heap_data cb_i32_data_heap_data;
typedef struct td_cb_i32_data_heap_data_heap cb_i32_data_heap_data_heap;
typedef struct td_sjs_data sjs_data;
typedef struct td_sjs_data_heap sjs_data_heap;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_cb_i32_data_heap_data {
    void* _parent;
    void (*_cb)(void* _parent, int32_t, sjs_data* _return);
    void (*_cb_heap)(void* _parent, int32_t, sjs_data_heap** _return);
};

struct td_cb_i32_data_heap_data_heap {
    sjs_object* _parent;
    void (*_cb)(void* _parent, int32_t, sjs_data* _return);
    void (*_cb_heap)(void* _parent, int32_t, sjs_data_heap** _return);
    void (*_destroy)(void*);
};

struct td_sjs_data {
    int32_t x;
};

struct td_sjs_data_heap {
    intptr_t _refCount;
    int32_t x;
};

struct td_sjs_class {
    int32_t b;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
    int32_t b;
};

sjs_class* sjt_dot3;
sjs_class* sjt_dot4;
sjs_class* sjt_dot5;
int32_t sjt_functionParam1;
int32_t sjt_functionParam2;
int32_t sjt_functionParam3;
cb_i32_data_heap_data sjt_functionParam5;
cb_i32_data_heap_data sjt_functionParam6;
int32_t sjt_functionParam7;
int32_t sjt_functionParam8;
int32_t sjt_functionParam9;
cb_i32_data_heap_data sjv_a;
int32_t sjv_a2;
sjs_data_heap* sjv_b;
int32_t sjv_b2;
sjs_class sjv_c;
sjs_class_heap* sjv_c_heap;
sjs_data sjv_d;
sjs_data sjv_e;
cb_i32_data_heap_data sjv_f1;
cb_i32_data_heap_data sjv_f2;
cb_i32_data_heap_data_heap sjv_f3;
sjs_data sjv_g;
cb_i32_data_heap_data_heap sjv_l;
sjs_data sjv_m;
sjs_data_heap* sjv_n;

void sjf_callback(cb_i32_data_heap_data f, int32_t* _return);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_func(sjs_class* _parent, int32_t a, sjs_data* _return);
void sjf_class_func_heap(sjs_class* _parent, int32_t a, sjs_data_heap** _return);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_data(sjs_data* _this);
void sjf_data_copy(sjs_data* _this, sjs_data* _from);
void sjf_data_destroy(sjs_data* _this);
void sjf_data_heap(sjs_data_heap* _this);
void sjf_func(int32_t a, sjs_data* _return);
void sjf_func_callback(void * _parent, int32_t a, sjs_data* _return);
void sjf_func_heap(int32_t a, sjs_data_heap** _return);
void sjf_func_heap_callback(void * _parent, int32_t a, sjs_data_heap** _return);
void sjf_getCallback_heap(cb_i32_data_heap_data_heap* _return);
void main_destroy(void);

void sjf_callback(cb_i32_data_heap_data f, int32_t* _return) {
    sjs_data* sjt_dot2;
    int32_t sjt_functionParam4;
    sjs_data sjv_d;

    sjt_functionParam4 = 12;
    f._cb(f._parent, sjt_functionParam4, &sjv_d);
    sjt_dot2 = &sjv_d;
    (*_return) = (sjt_dot2)->x;

    sjf_data_destroy(&sjv_d);
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->b = _from->b;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_func(sjs_class* _parent, int32_t a, sjs_data* _return) {
    int32_t sjt_math5;
    int32_t sjt_math6;

    sjt_math5 = a;
    sjt_math6 = (_parent)->b;
    _return->x = sjt_math5 + sjt_math6;
    sjf_data(_return);
}

void sjf_class_func_heap(sjs_class* _parent, int32_t a, sjs_data_heap** _return) {
    int32_t sjt_math7;
    int32_t sjt_math8;

    (*_return) = (sjs_data_heap*)malloc(sizeof(sjs_data_heap));
    (*_return)->_refCount = 1;
    sjt_math7 = a;
    sjt_math8 = (_parent)->b;
    (*_return)->x = sjt_math7 + sjt_math8;
    sjf_data_heap((*_return));
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_data(sjs_data* _this) {
}

void sjf_data_copy(sjs_data* _this, sjs_data* _from) {
    _this->x = _from->x;
}

void sjf_data_destroy(sjs_data* _this) {
}

void sjf_data_heap(sjs_data_heap* _this) {
}

void sjf_func(int32_t a, sjs_data* _return) {
    int32_t sjt_math1;
    int32_t sjt_math2;

    sjt_math1 = a;
    sjt_math2 = 2;
    _return->x = sjt_math1 + sjt_math2;
    sjf_data(_return);
}

void sjf_func_callback(void * _parent, int32_t a, sjs_data* _return) {
    sjf_func(a, _return);
}

void sjf_func_heap(int32_t a, sjs_data_heap** _return) {
    int32_t sjt_math3;
    int32_t sjt_math4;

    (*_return) = (sjs_data_heap*)malloc(sizeof(sjs_data_heap));
    (*_return)->_refCount = 1;
    sjt_math3 = a;
    sjt_math4 = 2;
    (*_return)->x = sjt_math3 + sjt_math4;
    sjf_data_heap((*_return));
}

void sjf_func_heap_callback(void * _parent, int32_t a, sjs_data_heap** _return) {
    sjf_func_heap(a, _return);
}

void sjf_getCallback_heap(cb_i32_data_heap_data_heap* _return) {
    sjs_class* sjt_dot1;
    sjs_class_heap* sjv_c;

    sjv_c = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjv_c->_refCount = 1;
    sjv_c->b = 15;
    sjf_class_heap(sjv_c);
    sjt_dot1 = (sjs_class*)(((char*)sjv_c) + sizeof(intptr_t));
    (*_return)._parent = (sjs_object*)((char*)sjt_dot1 - sizeof(intptr_t));
    (*_return)._parent->_refCount++;
    (*_return)._destroy = sjf_class_destroy;
    (*_return)._cb = sjf_class_func;
    (*_return)._cb_heap = sjf_class_func_heap;

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjv_c) + sizeof(intptr_t)));
    }
}

int main(int argc, char** argv) {
    sjv_a._parent = (void*)0;
    sjv_a._cb = sjf_func_callback;
    sjv_a._cb_heap = sjf_func_heap_callback;
    sjt_functionParam1 = 1;
    sjv_a._cb_heap(sjv_a._parent, sjt_functionParam1, &sjv_b);
    sjf_getCallback_heap(&sjv_l);
    sjt_functionParam2 = 1;
    sjv_l._cb(sjv_l._parent, sjt_functionParam2, &sjv_m);
    sjt_functionParam3 = 1;
    sjv_l._cb_heap(sjv_l._parent, sjt_functionParam3, &sjv_n);
    sjv_c.b = 15;
    sjf_class(&sjv_c);
    sjt_functionParam5._parent = (void*)0;
    sjt_functionParam5._cb = sjf_func_callback;
    sjt_functionParam5._cb_heap = sjf_func_heap_callback;
    sjf_callback(sjt_functionParam5, &sjv_a2);
    sjt_dot3 = &sjv_c;
    sjt_functionParam6._parent = (void*)sjt_dot3;
    sjt_functionParam6._cb = sjf_class_func;
    sjt_functionParam6._cb_heap = sjf_class_func_heap;
    sjf_callback(sjt_functionParam6, &sjv_b2);
    sjv_f1._parent = (void*)0;
    sjv_f1._cb = sjf_func_callback;
    sjv_f1._cb_heap = sjf_func_heap_callback;
    sjt_functionParam7 = 1;
    sjv_f1._cb(sjv_f1._parent, sjt_functionParam7, &sjv_d);
    sjt_dot4 = &sjv_c;
    sjv_f2._parent = (void*)sjt_dot4;
    sjv_f2._cb = sjf_class_func;
    sjv_f2._cb_heap = sjf_class_func_heap;
    sjt_functionParam8 = 2;
    sjv_f2._cb(sjv_f2._parent, sjt_functionParam8, &sjv_e);
    sjv_c_heap = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjv_c_heap->_refCount = 1;
    sjv_c_heap->b = 15;
    sjf_class_heap(sjv_c_heap);
    sjt_dot5 = (sjs_class*)(((char*)sjv_c_heap) + sizeof(intptr_t));
    sjv_f3._parent = (sjs_object*)((char*)sjt_dot5 - sizeof(intptr_t));
    sjv_f3._parent->_refCount++;
    sjv_f3._destroy = sjf_class_destroy;
    sjv_f3._cb = sjf_class_func;
    sjv_f3._cb_heap = sjf_class_func_heap;
    sjt_functionParam9 = 3;
    sjv_f3._cb(sjv_f3._parent, sjt_functionParam9, &sjv_g);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjv_b->_refCount--;
    if (sjv_b->_refCount <= 0) {
        sjf_data_destroy((sjs_data*)(((char*)sjv_b) + sizeof(intptr_t)));
    }
    sjv_c_heap->_refCount--;
    if (sjv_c_heap->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjv_c_heap) + sizeof(intptr_t)));
    }
    if (sjv_f3._parent != 0) {
        sjv_f3._parent->_refCount--;
        if (sjv_f3._parent->_refCount <= 0) {
            sjv_f3._destroy((void*)(((char*)sjv_f3._parent) + sizeof(intptr_t)));
        }
    }
    if (sjv_l._parent != 0) {
        sjv_l._parent->_refCount--;
        if (sjv_l._parent->_refCount <= 0) {
            sjv_l._destroy((void*)(((char*)sjv_l._parent) + sizeof(intptr_t)));
        }
    }
    sjv_n->_refCount--;
    if (sjv_n->_refCount <= 0) {
        sjf_data_destroy((sjs_data*)(((char*)sjv_n) + sizeof(intptr_t)));
    }
    sjf_class_destroy(&sjv_c);
    sjf_data_destroy(&sjv_d);
    sjf_data_destroy(&sjv_e);
    sjf_data_destroy(&sjv_g);
    sjf_data_destroy(&sjv_m);
}
