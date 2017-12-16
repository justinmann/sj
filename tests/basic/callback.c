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

typedef struct td_void_option void_option;
struct td_void_option {
    bool isEmpty;
    void* value;
};
const void_option void_empty = { true };

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
    cb_i32_data_heap_data inner;
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
cb_i32_data_heap_data sjv_h;
cb_i32_data_heap_data sjv_i;
cb_i32_data_heap_data sjv_j;
sjs_data sjv_k;
cb_i32_data_heap_data_heap sjv_l;
sjs_data sjv_m;
sjs_data_heap* sjv_n;
cb_i32_data_heap_data sjv_o;
sjs_data sjv_p;

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
void sjf_func2_data(int32_t a, sjs_data* _return);
void sjf_func2_data_callback(void * _parent, int32_t a, sjs_data* _return);
void sjf_func2_data_heap(int32_t a, sjs_data_heap** _return);
void sjf_func2_data_heap_callback(void * _parent, int32_t a, sjs_data_heap** _return);
void sjf_func_callback(void * _parent, int32_t a, sjs_data* _return);
void sjf_func_heap(int32_t a, sjs_data_heap** _return);
void sjf_func_heap_callback(void * _parent, int32_t a, sjs_data_heap** _return);
void sjf_getCallback_heap(cb_i32_data_heap_data_heap* _return);
void main_destroy(void);

void sjf_callback(cb_i32_data_heap_data f, int32_t* _return) {
    cb_i32_data_heap_data sjt_callback4;
    sjs_data* sjt_dot3;
    int32_t sjt_functionParam4;
    sjs_data sjv_d;

#line 32 "callback.sj"
    sjt_callback4 = f;
#line 33
    sjt_functionParam4 = 12;
#line 33
    sjt_callback4._cb(sjt_callback4._parent, sjt_functionParam4, &sjv_d);
#line 1
    sjt_dot3 = &sjv_d;
#line 32
    (*_return) = (sjt_dot3)->x;

    sjf_data_destroy(&sjv_d);
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 5 "callback.sj"
    _this->b = _from->b;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_func(sjs_class* _parent, int32_t a, sjs_data* _return) {
    sjs_class* sjt_dot1;
    int32_t sjt_math5;
    int32_t sjt_math6;

#line 7 "callback.sj"
    sjt_math5 = a;
#line 7
    sjt_dot1 = _parent;
#line 8
    sjt_math6 = (sjt_dot1)->b;
#line 8
    _return->x = sjt_math5 + sjt_math6;
#line 8
    sjf_data(_return);
}

void sjf_class_func_heap(sjs_class* _parent, int32_t a, sjs_data_heap** _return) {
    sjs_class* sjt_dot2;
    int32_t sjt_math7;
    int32_t sjt_math8;

    (*_return) = (sjs_data_heap*)malloc(sizeof(sjs_data_heap));
    (*_return)->_refCount = 1;
#line 7 "callback.sj"
    sjt_math7 = a;
#line 7
    sjt_dot2 = _parent;
#line 8
    sjt_math8 = (sjt_dot2)->b;
#line 8
    (*_return)->x = sjt_math7 + sjt_math8;
#line 8
    sjf_data_heap((*_return));
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_data(sjs_data* _this) {
}

void sjf_data_copy(sjs_data* _this, sjs_data* _from) {
#line 1 "callback.sj"
    _this->x = _from->x;
}

void sjf_data_destroy(sjs_data* _this) {
}

void sjf_data_heap(sjs_data_heap* _this) {
}

void sjf_func(int32_t a, sjs_data* _return) {
    int32_t sjt_math1;
    int32_t sjt_math2;

#line 12 "callback.sj"
    sjt_math1 = a;
#line 13
    sjt_math2 = 2;
#line 13
    _return->x = sjt_math1 + sjt_math2;
#line 13
    sjf_data(_return);
}

void sjf_func2_data(int32_t a, sjs_data* _return) {
    int32_t sjt_math10;
    int32_t sjt_math9;

#line 16 "callback.sj"
    sjt_math9 = a;
#line 17
    sjt_math10 = 2;
#line 17
    _return->x = sjt_math9 + sjt_math10;
#line 17
    sjf_data(_return);
}

void sjf_func2_data_callback(void * _parent, int32_t a, sjs_data* _return) {
    sjf_func2_data(a, _return);
}

void sjf_func2_data_heap(int32_t a, sjs_data_heap** _return) {
    int32_t sjt_math11;
    int32_t sjt_math12;

    (*_return) = (sjs_data_heap*)malloc(sizeof(sjs_data_heap));
    (*_return)->_refCount = 1;
#line 16 "callback.sj"
    sjt_math11 = a;
#line 17
    sjt_math12 = 2;
#line 17
    (*_return)->x = sjt_math11 + sjt_math12;
#line 17
    sjf_data_heap((*_return));
}

void sjf_func2_data_heap_callback(void * _parent, int32_t a, sjs_data_heap** _return) {
    sjf_func2_data_heap(a, _return);
}

void sjf_func_callback(void * _parent, int32_t a, sjs_data* _return) {
    sjf_func(a, _return);
}

void sjf_func_heap(int32_t a, sjs_data_heap** _return) {
    int32_t sjt_math3;
    int32_t sjt_math4;

    (*_return) = (sjs_data_heap*)malloc(sizeof(sjs_data_heap));
    (*_return)->_refCount = 1;
#line 12 "callback.sj"
    sjt_math3 = a;
#line 13
    sjt_math4 = 2;
#line 13
    (*_return)->x = sjt_math3 + sjt_math4;
#line 13
    sjf_data_heap((*_return));
}

void sjf_func_heap_callback(void * _parent, int32_t a, sjs_data_heap** _return) {
    sjf_func_heap(a, _return);
}

void sjf_getCallback_heap(cb_i32_data_heap_data_heap* _return) {
    sjs_class_heap* sjv_c;

    sjv_c = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjv_c->_refCount = 1;
#line 6 "callback.sj"
    sjv_c->b = 15;
#line 6
    sjf_class_heap(sjv_c);
#line 29
    sjs_class_heap* callback1;
#line 29
    callback1 = sjv_c;
#line 29
    callback1->_refCount++;
#line 29
    (*_return).inner._parent = (void*)(sjs_class*)(((char*)callback1) + sizeof(intptr_t));
#line 29
    (*_return)._destroy = (void(*)(void*))sjf_class_destroy;
#line 29
    (*_return).inner._cb = (void(*)(void*,int32_t, sjs_data*))sjf_class_func;
#line 29
    (*_return).inner._cb_heap = (void(*)(void*,int32_t, sjs_data_heap**))sjf_class_func_heap;

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjv_c) + sizeof(intptr_t)));
    }
}

int main(int argc, char** argv) {
#line 37 "callback.sj"
    sjv_a._parent = (void*)1;
#line 37
    sjv_a._cb = (void(*)(void*,int32_t, sjs_data*))sjf_func_callback;
#line 37
    sjv_a._cb_heap = (void(*)(void*,int32_t, sjs_data_heap**))sjf_func_heap_callback;
#line 38
    sjt_callback1 = sjv_a;
#line 38
    sjt_functionParam1 = 1;
#line 38
    sjt_callback1._cb_heap(sjt_callback1._parent, sjt_functionParam1, &sjv_b);
#line 38
    sjf_getCallback_heap(&sjv_l);
#line 40
    sjt_callback2 = sjv_l.inner;
#line 40
    sjt_functionParam2 = 1;
#line 40
    sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam2, &sjv_m);
#line 41
    sjt_callback3 = sjv_l.inner;
#line 41
    sjt_functionParam3 = 1;
#line 41
    sjt_callback3._cb_heap(sjt_callback3._parent, sjt_functionParam3, &sjv_n);
#line 6
    sjv_c.b = 15;
#line 6
    sjf_class(&sjv_c);
#line 43
    sjt_functionParam5._parent = (void*)1;
#line 43
    sjt_functionParam5._cb = (void(*)(void*,int32_t, sjs_data*))sjf_func_callback;
#line 43
    sjt_functionParam5._cb_heap = (void(*)(void*,int32_t, sjs_data_heap**))sjf_func_heap_callback;
#line 43
    sjf_callback(sjt_functionParam5, &sjv_a2);
#line 44
    sjt_functionParam6._parent = &sjv_c;
#line 44
    sjt_functionParam6._cb = (void(*)(void*,int32_t, sjs_data*))sjf_class_func;
#line 44
    sjt_functionParam6._cb_heap = (void(*)(void*,int32_t, sjs_data_heap**))sjf_class_func_heap;
#line 44
    sjf_callback(sjt_functionParam6, &sjv_b2);
#line 45
    sjv_f1._parent = (void*)1;
#line 45
    sjv_f1._cb = (void(*)(void*,int32_t, sjs_data*))sjf_func_callback;
#line 45
    sjv_f1._cb_heap = (void(*)(void*,int32_t, sjs_data_heap**))sjf_func_heap_callback;
#line 46
    sjt_callback5 = sjv_f1;
#line 46
    sjt_functionParam7 = 1;
#line 46
    sjt_callback5._cb(sjt_callback5._parent, sjt_functionParam7, &sjv_d);
#line 47
    sjv_f2._parent = &sjv_c;
#line 47
    sjv_f2._cb = (void(*)(void*,int32_t, sjs_data*))sjf_class_func;
#line 47
    sjv_f2._cb_heap = (void(*)(void*,int32_t, sjs_data_heap**))sjf_class_func_heap;
#line 48
    sjt_callback6 = sjv_f2;
#line 48
    sjt_functionParam8 = 2;
#line 48
    sjt_callback6._cb(sjt_callback6._parent, sjt_functionParam8, &sjv_e);
#line 48
    sjv_c_heap = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
#line 48
    sjv_c_heap->_refCount = 1;
#line 6
    sjv_c_heap->b = 15;
#line 6
    sjf_class_heap(sjv_c_heap);
#line 50
    sjs_class_heap* callback2;
#line 50
    callback2 = sjv_c_heap;
#line 50
    callback2->_refCount++;
#line 50
    sjv_f3.inner._parent = (void*)(sjs_class*)(((char*)callback2) + sizeof(intptr_t));
#line 50
    sjv_f3._destroy = (void(*)(void*))sjf_class_destroy;
#line 50
    sjv_f3.inner._cb = (void(*)(void*,int32_t, sjs_data*))sjf_class_func;
#line 50
    sjv_f3.inner._cb_heap = (void(*)(void*,int32_t, sjs_data_heap**))sjf_class_func_heap;
#line 51
    sjt_callback7 = sjv_f3.inner;
#line 51
    sjt_functionParam9 = 3;
#line 51
    sjt_callback7._cb(sjt_callback7._parent, sjt_functionParam9, &sjv_g);
#line 52
    sjv_h._parent = 0;
#line 53
    sjt_value1._parent = (void*)1;
#line 53
    sjt_value1._cb = (void(*)(void*,int32_t, sjs_data*))sjf_func_callback;
#line 53
    sjt_value1._cb_heap = (void(*)(void*,int32_t, sjs_data_heap**))sjf_func_heap_callback;
#line 53
    sjv_i = sjt_value1;
#line 54
    sjt_getValue1 = sjv_i;
#line 54
    if (sjt_getValue1._parent == 0) { exit(-1); }
#line 54
    sjv_j = sjt_getValue1;
#line 55
    sjt_callback8 = sjv_j;
#line 55
    sjt_functionParam10 = 12;
#line 55
    sjt_callback8._cb(sjt_callback8._parent, sjt_functionParam10, &sjv_k);
#line 56
    sjv_o._parent = (void*)1;
#line 56
    sjv_o._cb = (void(*)(void*,int32_t, sjs_data*))sjf_func2_data_callback;
#line 56
    sjv_o._cb_heap = (void(*)(void*,int32_t, sjs_data_heap**))sjf_func2_data_heap_callback;
#line 57
    sjt_callback9 = sjv_l.inner;
#line 57
    sjt_functionParam11 = 1;
#line 57
    sjt_callback9._cb(sjt_callback9._parent, sjt_functionParam11, &sjv_p);
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
        sjf_data_destroy((sjs_data*)(((char*)sjv_n) + sizeof(intptr_t)));
    }
    sjf_class_destroy(&sjv_c);
    sjf_data_destroy(&sjv_d);
    sjf_data_destroy(&sjv_e);
    sjf_data_destroy(&sjv_g);
    sjf_data_destroy(&sjv_k);
    sjf_data_destroy(&sjv_m);
    sjf_data_destroy(&sjv_p);
}
