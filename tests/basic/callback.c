#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isempty;
    int32_t value;
};
const int32_option int32_empty = { true };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isempty;
    uint32_t value;
};
const uint32_option uint32_empty = { true };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isempty;
    int64_t value;
};
const int64_option int64_empty = { true };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isempty;
    uint64_t value;
};
const uint64_option uint64_empty = { true };

typedef struct td_void_option void_option;
struct td_void_option {
    bool isempty;
    void* value;
};
const void_option void_empty = { true };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isempty;
    char value;
};
const char_option char_empty = { true };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isempty;
    float value;
};
const float_option float_empty = { true };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isempty;
    double value;
};
const double_option double_empty = { true };

#define sjs_object_typeId 1
#define cb_i32_data_heap_data_typeId 2
#define cb_i32_data_heap_data_heap_typeId 3
#define sjs_data_typeId 4
#define sjs_class_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_cb_i32_data_heap_data cb_i32_data_heap_data;
typedef struct td_cb_i32_data_heap_data_heap cb_i32_data_heap_data_heap;
typedef struct td_sjs_data sjs_data;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_cb_i32_data_heap_data {
    void* _parent;
    void (*_cb)(void* _parent, int32_t, sjs_data* _return);
    void (*_cb_heap)(void* _parent, int32_t, sjs_data** _return);
};

struct td_cb_i32_data_heap_data_heap {
    cb_i32_data_heap_data inner;
    void (*_destroy)(void*);
};

struct td_sjs_data {
    int _refCount;
    int32_t x;
};

struct td_sjs_class {
    int _refCount;
    int32_t b;
};

cb_i32_data_heap_data sjt_callback1;
cb_i32_data_heap_data sjt_callback2;
cb_i32_data_heap_data sjt_callback3;
cb_i32_data_heap_data sjt_callback5;
cb_i32_data_heap_data sjt_callback6;
cb_i32_data_heap_data sjt_callback7;
cb_i32_data_heap_data sjt_callback8;
cb_i32_data_heap_data sjt_callback9;
int32_t sjt_functionParam1;
int32_t sjt_functionParam10;
int32_t sjt_functionParam11;
int32_t sjt_functionParam2;
int32_t sjt_functionParam3;
cb_i32_data_heap_data sjt_functionParam5;
cb_i32_data_heap_data sjt_functionParam6;
int32_t sjt_functionParam7;
int32_t sjt_functionParam8;
int32_t sjt_functionParam9;
cb_i32_data_heap_data sjt_getValue1;
cb_i32_data_heap_data sjt_value1;
cb_i32_data_heap_data sjv_a;
int32_t sjv_a2;
sjs_data* sjv_b = 0;
int32_t sjv_b2;
sjs_class sjv_c = { -1 };
sjs_class* sjv_c_heap = 0;
sjs_data sjv_d = { -1 };
sjs_data sjv_e = { -1 };
cb_i32_data_heap_data sjv_f1;
cb_i32_data_heap_data sjv_f2;
cb_i32_data_heap_data_heap sjv_f3;
sjs_data sjv_g = { -1 };
cb_i32_data_heap_data sjv_h;
cb_i32_data_heap_data sjv_i;
cb_i32_data_heap_data sjv_j;
sjs_data sjv_k = { -1 };
cb_i32_data_heap_data_heap sjv_l;
sjs_data sjv_m = { -1 };
sjs_data* sjv_n = 0;
cb_i32_data_heap_data sjv_o;
sjs_data sjv_p = { -1 };

void sjf_callback(cb_i32_data_heap_data f, int32_t* _return);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_func(sjs_class* _parent, int32_t a, sjs_data* _return);
void sjf_class_func_heap(sjs_class* _parent, int32_t a, sjs_data** _return);
void sjf_class_heap(sjs_class* _this);
void sjf_data(sjs_data* _this);
void sjf_data_copy(sjs_data* _this, sjs_data* _from);
void sjf_data_destroy(sjs_data* _this);
void sjf_data_heap(sjs_data* _this);
void sjf_func(int32_t a, sjs_data* _return);
void sjf_func2_data(int32_t a, sjs_data* _return);
void sjf_func2_data_callback(void * _parent, int32_t a, sjs_data* _return);
void sjf_func2_data_heap(int32_t a, sjs_data** _return);
void sjf_func2_data_heap_callback(void * _parent, int32_t a, sjs_data** _return);
void sjf_func_callback(void * _parent, int32_t a, sjs_data* _return);
void sjf_func_heap(int32_t a, sjs_data** _return);
void sjf_func_heap_callback(void * _parent, int32_t a, sjs_data** _return);
void sjf_getcallback_heap(cb_i32_data_heap_data_heap* _return);
void main_destroy(void);

void sjf_callback(cb_i32_data_heap_data f, int32_t* _return) {
    cb_i32_data_heap_data sjt_callback4;
    sjs_data* sjt_dot3 = 0;
    int32_t sjt_functionParam4;
    sjs_data sjv_d = { -1 };

    sjt_callback4 = f;
    sjt_functionParam4 = 12;
    sjt_callback4._cb(sjt_callback4._parent, sjt_functionParam4, &sjv_d);
    sjt_dot3 = &sjv_d;
    (*_return) = (sjt_dot3)->x;

    if (sjv_d._refCount == 1) { sjf_data_destroy(&sjv_d); }
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->b = _from->b;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_func(sjs_class* _parent, int32_t a, sjs_data* _return) {
    sjs_class* sjt_dot1 = 0;
    int32_t sjt_math5;
    int32_t sjt_math6;

    _return->_refCount = 1;
    sjt_math5 = a;
    sjt_dot1 = _parent;
    sjt_math6 = (sjt_dot1)->b;
    _return->x = sjt_math5 + sjt_math6;
    sjf_data(_return);
}

void sjf_class_func_heap(sjs_class* _parent, int32_t a, sjs_data** _return) {
    sjs_class* sjt_dot2 = 0;
    int32_t sjt_math7;
    int32_t sjt_math8;

    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
    sjt_math7 = a;
    sjt_dot2 = _parent;
    sjt_math8 = (sjt_dot2)->b;
    (*_return)->x = sjt_math7 + sjt_math8;
    sjf_data_heap((*_return));
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_data(sjs_data* _this) {
}

void sjf_data_copy(sjs_data* _this, sjs_data* _from) {
    _this->x = _from->x;
}

void sjf_data_destroy(sjs_data* _this) {
}

void sjf_data_heap(sjs_data* _this) {
}

void sjf_func(int32_t a, sjs_data* _return) {
    int32_t sjt_math1;
    int32_t sjt_math2;

    _return->_refCount = 1;
    sjt_math1 = a;
    sjt_math2 = 2;
    _return->x = sjt_math1 + sjt_math2;
    sjf_data(_return);
}

void sjf_func2_data(int32_t a, sjs_data* _return) {
    int32_t sjt_math10;
    int32_t sjt_math9;

    _return->_refCount = 1;
    sjt_math9 = a;
    sjt_math10 = 2;
    _return->x = sjt_math9 + sjt_math10;
    sjf_data(_return);
}

void sjf_func2_data_callback(void * _parent, int32_t a, sjs_data* _return) {
    sjf_func2_data(a, _return);
}

void sjf_func2_data_heap(int32_t a, sjs_data** _return) {
    int32_t sjt_math11;
    int32_t sjt_math12;

    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
    sjt_math11 = a;
    sjt_math12 = 2;
    (*_return)->x = sjt_math11 + sjt_math12;
    sjf_data_heap((*_return));
}

void sjf_func2_data_heap_callback(void * _parent, int32_t a, sjs_data** _return) {
    sjf_func2_data_heap(a, _return);
}

void sjf_func_callback(void * _parent, int32_t a, sjs_data* _return) {
    sjf_func(a, _return);
}

void sjf_func_heap(int32_t a, sjs_data** _return) {
    int32_t sjt_math3;
    int32_t sjt_math4;

    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
    sjt_math3 = a;
    sjt_math4 = 2;
    (*_return)->x = sjt_math3 + sjt_math4;
    sjf_data_heap((*_return));
}

void sjf_func_heap_callback(void * _parent, int32_t a, sjs_data** _return) {
    sjf_func_heap(a, _return);
}

void sjf_getcallback_heap(cb_i32_data_heap_data_heap* _return) {
    sjs_class* sjv_c = 0;

    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->b = 15;
    sjf_class_heap(sjv_c);
    sjs_class* callback1;
    callback1 = sjv_c;
    callback1->_refCount++;
    (*_return).inner._parent = (void*)callback1;
    (*_return)._destroy = (void(*)(void*))sjf_class_destroy;
    (*_return).inner._cb = (void(*)(void*,int32_t, sjs_data*))sjf_class_func;
    (*_return).inner._cb_heap = (void(*)(void*,int32_t, sjs_data**))sjf_class_func_heap;

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        sjf_class_destroy(sjv_c);
    }
}

int main(int argc, char** argv) {
    sjv_a._parent = (void*)1;
    sjv_a._cb = (void(*)(void*,int32_t, sjs_data*))sjf_func_callback;
    sjv_a._cb_heap = (void(*)(void*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjt_callback1 = sjv_a;
    sjt_functionParam1 = 1;
    sjt_callback1._cb_heap(sjt_callback1._parent, sjt_functionParam1, &sjv_b);
    sjf_getcallback_heap(&sjv_l);
    sjt_callback2 = sjv_l.inner;
    sjt_functionParam2 = 1;
    sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam2, &sjv_m);
    sjt_callback3 = sjv_l.inner;
    sjt_functionParam3 = 1;
    sjt_callback3._cb_heap(sjt_callback3._parent, sjt_functionParam3, &sjv_n);
    sjv_c._refCount = 1;
    sjv_c.b = 15;
    sjf_class(&sjv_c);
    sjt_functionParam5._parent = (void*)1;
    sjt_functionParam5._cb = (void(*)(void*,int32_t, sjs_data*))sjf_func_callback;
    sjt_functionParam5._cb_heap = (void(*)(void*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjf_callback(sjt_functionParam5, &sjv_a2);
    sjt_functionParam6._parent = &sjv_c;
    sjt_functionParam6._cb = (void(*)(void*,int32_t, sjs_data*))sjf_class_func;
    sjt_functionParam6._cb_heap = (void(*)(void*,int32_t, sjs_data**))sjf_class_func_heap;
    sjf_callback(sjt_functionParam6, &sjv_b2);
    sjv_f1._parent = (void*)1;
    sjv_f1._cb = (void(*)(void*,int32_t, sjs_data*))sjf_func_callback;
    sjv_f1._cb_heap = (void(*)(void*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjt_callback5 = sjv_f1;
    sjt_functionParam7 = 1;
    sjt_callback5._cb(sjt_callback5._parent, sjt_functionParam7, &sjv_d);
    sjv_f2._parent = &sjv_c;
    sjv_f2._cb = (void(*)(void*,int32_t, sjs_data*))sjf_class_func;
    sjv_f2._cb_heap = (void(*)(void*,int32_t, sjs_data**))sjf_class_func_heap;
    sjt_callback6 = sjv_f2;
    sjt_functionParam8 = 2;
    sjt_callback6._cb(sjt_callback6._parent, sjt_functionParam8, &sjv_e);
    sjv_c_heap = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c_heap->_refCount = 1;
    sjv_c_heap->b = 15;
    sjf_class_heap(sjv_c_heap);
    sjs_class* callback2;
    callback2 = sjv_c_heap;
    callback2->_refCount++;
    sjv_f3.inner._parent = (void*)callback2;
    sjv_f3._destroy = (void(*)(void*))sjf_class_destroy;
    sjv_f3.inner._cb = (void(*)(void*,int32_t, sjs_data*))sjf_class_func;
    sjv_f3.inner._cb_heap = (void(*)(void*,int32_t, sjs_data**))sjf_class_func_heap;
    sjt_callback7 = sjv_f3.inner;
    sjt_functionParam9 = 3;
    sjt_callback7._cb(sjt_callback7._parent, sjt_functionParam9, &sjv_g);
    sjv_h._parent = 0;
    sjt_value1._parent = (void*)1;
    sjt_value1._cb = (void(*)(void*,int32_t, sjs_data*))sjf_func_callback;
    sjt_value1._cb_heap = (void(*)(void*,int32_t, sjs_data**))sjf_func_heap_callback;
    sjv_i = sjt_value1;
    sjt_getValue1 = sjv_i;
    if (sjt_getValue1._parent == 0) { exit(-1); }
    sjv_j = sjt_getValue1;
    sjt_callback8 = sjv_j;
    sjt_functionParam10 = 12;
    sjt_callback8._cb(sjt_callback8._parent, sjt_functionParam10, &sjv_k);
    sjv_o._parent = (void*)1;
    sjv_o._cb = (void(*)(void*,int32_t, sjs_data*))sjf_func2_data_callback;
    sjv_o._cb_heap = (void(*)(void*,int32_t, sjs_data**))sjf_func2_data_heap_callback;
    sjt_callback9 = sjv_l.inner;
    sjt_functionParam11 = 1;
    sjt_callback9._cb(sjt_callback9._parent, sjt_functionParam11, &sjv_p);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjv_b->_refCount--;
    if (sjv_b->_refCount <= 0) {
        sjf_data_destroy(sjv_b);
    }
    sjv_c_heap->_refCount--;
    if (sjv_c_heap->_refCount <= 0) {
        sjf_class_destroy(sjv_c_heap);
    }
    if ((uintptr_t)sjv_f3.inner._parent > 1) {
        ((sjs_object*)((char*)sjv_f3.inner._parent - sizeof(intptr_t)))->_refCount--;
        if (((sjs_object*)((char*)sjv_f3.inner._parent - sizeof(intptr_t)))->_refCount <= 0) {
            sjv_f3._destroy(sjv_f3.inner._parent);
        }
    }
    if ((uintptr_t)sjv_l.inner._parent > 1) {
        ((sjs_object*)((char*)sjv_l.inner._parent - sizeof(intptr_t)))->_refCount--;
        if (((sjs_object*)((char*)sjv_l.inner._parent - sizeof(intptr_t)))->_refCount <= 0) {
            sjv_l._destroy(sjv_l.inner._parent);
        }
    }
    sjv_n->_refCount--;
    if (sjv_n->_refCount <= 0) {
        sjf_data_destroy(sjv_n);
    }
    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
    if (sjv_d._refCount == 1) { sjf_data_destroy(&sjv_d); }
    if (sjv_e._refCount == 1) { sjf_data_destroy(&sjv_e); }
    if (sjv_g._refCount == 1) { sjf_data_destroy(&sjv_g); }
    if (sjv_k._refCount == 1) { sjf_data_destroy(&sjv_k); }
    if (sjv_m._refCount == 1) { sjf_data_destroy(&sjv_m); }
    if (sjv_p._refCount == 1) { sjf_data_destroy(&sjv_p); }
}
