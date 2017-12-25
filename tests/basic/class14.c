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
    int32_t m;
};

sjs_class object1 = { -1 };
int32_t void1;

void sjf_class(sjs_class* _this, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_inner(sjs_class* _parent, int32_t* _return);
void main_destroy(void);

void sjf_class(sjs_class* _this, int32_t* _return) {
    sjf_class_inner(_this, _return);
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->m = _from->m;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_inner(sjs_class* _parent, int32_t* _return) {
    sjs_class* sjt_dot1 = 0;

    sjt_dot1 = _parent;
    (*_return) = sjt_dot1->m;
}

int main(int argc, char** argv) {
    object1._refCount = 1;
    object1.m = 1;
    sjf_class(&object1, &void1);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (object1._refCount == 1) { sjf_class_destroy(&object1); }
}
