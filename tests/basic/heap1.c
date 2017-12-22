#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_class_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_class {
    int _refCount;
};

sjs_class sjv_b = { -1 };

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_func(sjs_class* _return);
void sjf_func_heap(sjs_class** _return);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_func(sjs_class* _return) {
    sjs_class sjt_call1 = { -1 };
    sjs_class sjt_call2 = { -1 };
    sjs_class* sjt_copy1 = 0;
    sjs_class* sjt_copy2 = 0;
    sjs_class* sjt_copy3 = 0;
    sjs_class sjv_a = { -1 };

    sjt_call1._refCount = 1;
    sjf_class(&sjt_call1);
    sjt_copy1 = &sjt_call1;
    sjv_a._refCount = 1;
    sjf_class_copy(&sjv_a, sjt_copy1);
    sjt_call2._refCount = 1;
    sjf_class(&sjt_call2);
    sjt_copy2 = &sjt_call2;
    sjv_a._refCount = 1;
    sjf_class_copy(&sjv_a, sjt_copy2);
    sjt_copy3 = &sjv_a;
    _return->_refCount = 1;
    sjf_class_copy(_return, sjt_copy3);

    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
    if (sjt_call2._refCount == 1) { sjf_class_destroy(&sjt_call2); }
    if (sjv_a._refCount == 1) { sjf_class_destroy(&sjv_a); }
}

void sjf_func_heap(sjs_class** _return) {
    sjs_class sjt_call3 = { -1 };
    sjs_class sjt_call4 = { -1 };
    sjs_class* sjt_copy4 = 0;
    sjs_class* sjt_copy5 = 0;
    sjs_class* sjt_copy6 = 0;
    sjs_class sjv_a = { -1 };

    sjt_call3._refCount = 1;
    sjf_class(&sjt_call3);
    sjt_copy4 = &sjt_call3;
    sjv_a._refCount = 1;
    sjf_class_copy(&sjv_a, sjt_copy4);
    sjt_call4._refCount = 1;
    sjf_class(&sjt_call4);
    sjt_copy5 = &sjt_call4;
    sjv_a._refCount = 1;
    sjf_class_copy(&sjv_a, sjt_copy5);
    sjt_copy6 = &sjv_a;
    (*_return) = (sjs_class*)malloc(sizeof(sjs_class));
    (*_return)->_refCount = 1;
    sjf_class_copy((*_return), sjt_copy6);

    if (sjt_call3._refCount == 1) { sjf_class_destroy(&sjt_call3); }
    if (sjt_call4._refCount == 1) { sjf_class_destroy(&sjt_call4); }
    if (sjv_a._refCount == 1) { sjf_class_destroy(&sjv_a); }
}

int main(int argc, char** argv) {
    sjf_func(&sjv_b);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_b._refCount == 1) { sjf_class_destroy(&sjv_b); }
}
