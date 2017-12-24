#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_math_typeId 3
#define sjs_class_typeId 4

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_math sjs_math;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_math {
    int _refCount;
    int32_t test;
};

struct td_sjs_class {
    int _refCount;
};

int32_t sjt_functionParam5;
sjs_class* sjt_parent2 = 0;
sjs_class sjv_c = { -1 };
sjs_math sjv_math = { -1 };
int32_t void1;

void sjf_class(sjs_class* _this);
void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_math(sjs_math* _this);
void sjf_math_copy(sjs_math* _this, sjs_math* _from);
void sjf_math_destroy(sjs_math* _this);
void sjf_math_heap(sjs_math* _this);
void sjf_math_sub(sjs_math* _parent, int32_t x, int32_t y, int32_t* _return);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t sjt_functionParam1;

    sjt_functionParam1 = x;
    sjf_class_foo(_parent, sjt_functionParam1, _return);
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    bool sjt_ifElse1;

    sjt_compare1 = x;
    sjt_compare2 = 0;
    sjt_ifElse1 = sjt_compare1 > sjt_compare2;
    if (sjt_ifElse1) {
        int32_t sjt_functionParam2;
        int32_t sjt_functionParam3;
        int32_t sjt_functionParam4;
        sjs_math* sjt_parent1 = 0;

        sjt_parent1 = &sjv_math;
        sjt_functionParam3 = x;
        sjt_functionParam4 = 1;
        sjf_math_sub(sjt_parent1, sjt_functionParam3, sjt_functionParam4, &sjt_functionParam2);
        sjf_class_bar(_parent, sjt_functionParam2, _return);
    } else {
        (*_return) = 0;
    }
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_math(sjs_math* _this) {
}

void sjf_math_copy(sjs_math* _this, sjs_math* _from) {
    _this->test = _from->test;
}

void sjf_math_destroy(sjs_math* _this) {
}

void sjf_math_heap(sjs_math* _this) {
}

void sjf_math_sub(sjs_math* _parent, int32_t x, int32_t y, int32_t* _return) {
    sjs_math* sjt_dot1 = 0;
    int32_t sjt_math1;
    int32_t sjt_math2;
    int32_t sjt_math3;
    int32_t sjt_math4;

    sjt_math3 = x;
    sjt_math4 = y;
    sjt_math1 = sjt_math3 - sjt_math4;
    sjt_dot1 = _parent;
    sjt_math2 = (sjt_dot1)->test;
    (*_return) = sjt_math1 - sjt_math2;
}

int main(int argc, char** argv) {
    sjv_math._refCount = 1;
    sjv_math.test = 1;
    sjf_math(&sjv_math);
    sjv_c._refCount = 1;
    sjf_class(&sjv_c);
    sjt_parent2 = &sjv_c;
    sjt_functionParam5 = 4;
    sjf_class_foo(sjt_parent2, sjt_functionParam5, &void1);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
    if (sjv_math._refCount == 1) { sjf_math_destroy(&sjv_math); }
}
