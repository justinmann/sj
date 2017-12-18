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
#define sjs_class_typeId 2
#define cb_i32_void_typeId 3
#define cb_i32_void_heap_typeId 4

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;
typedef struct td_cb_i32_void cb_i32_void;
typedef struct td_cb_i32_void_heap cb_i32_void_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_class {
    int _refCount;
    int32_t total;
};

struct td_cb_i32_void {
    void* _parent;
    void (*_cb)(void* _parent, int32_t);
};

struct td_cb_i32_void_heap {
    cb_i32_void inner;
    void (*_destroy)(void*);
};

sjs_class* sjt_parent1 = 0;
sjs_class* sjv_c = 0;
int32_t void1;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_func(sjs_class* _parent, int32_t x);
void sjf_class_heap(sjs_class* _this);
void sjf_class_run(sjs_class* _parent, int32_t* _return);
void sjf_domath(cb_i32_void_heap cb);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->total = _from->total;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_func(sjs_class* _parent, int32_t x) {
    sjs_class* sjt_dot1 = 0;
    sjs_class* sjt_dot2 = 0;
    int32_t sjt_math1;
    int32_t sjt_math2;

    sjt_dot1 = _parent;
    sjt_dot2 = _parent;
    sjt_math1 = (sjt_dot2)->total;
    sjt_math2 = x;
    sjt_dot1->total = sjt_math1 + sjt_math2;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_run(sjs_class* _parent, int32_t* _return) {
    sjs_class* sjt_dot3 = 0;
    cb_i32_void_heap sjt_functionParam3;

    sjs_class* callback1;
    callback1 = _parent;
    callback1->_refCount++;
    sjt_functionParam3.inner._parent = (void*)callback1;
    sjt_functionParam3._destroy = (void(*)(void*))sjf_class_destroy;
    sjt_functionParam3.inner._cb = (void(*)(void*,int32_t))sjf_class_func;
    sjf_domath(sjt_functionParam3);
    sjt_dot3 = _parent;
    (*_return) = (sjt_dot3)->total;

    if ((uintptr_t)sjt_functionParam3.inner._parent > 1) {
        ((sjs_object*)((char*)sjt_functionParam3.inner._parent - sizeof(intptr_t)))->_refCount--;
        if (((sjs_object*)((char*)sjt_functionParam3.inner._parent - sizeof(intptr_t)))->_refCount <= 0) {
            sjt_functionParam3._destroy(sjt_functionParam3.inner._parent);
        }
    }
}

void sjf_domath(cb_i32_void_heap cb) {
    cb_i32_void sjt_callback1;
    cb_i32_void sjt_callback2;
    int32_t sjt_functionParam1;
    int32_t sjt_functionParam2;

    sjt_callback1 = cb.inner;
    sjt_functionParam1 = 1;
    sjt_callback1._cb(sjt_callback1._parent, sjt_functionParam1);
    sjt_callback2 = cb.inner;
    sjt_functionParam2 = 2;
    sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam2);
}

int main(int argc, char** argv) {
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->total = 0;
    sjf_class_heap(sjv_c);
    sjt_parent1 = sjv_c;
    sjt_parent1->_refCount++;
    sjf_class_run(sjt_parent1, &void1);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjt_parent1->_refCount--;
    if (sjt_parent1->_refCount <= 0) {
        sjf_class_destroy(sjt_parent1);
    }
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        sjf_class_destroy(sjv_c);
    }
}
