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
    int32_t bob;
};

sjs_class sjt_call1 = { -1 };
sjs_class* sjt_functionParam1 = 0;
sjs_class* sjt_parent1 = 0;
bool sjt_switch1;
sjs_class sjv_a = { -1 };
int32_t sjv_y;
sjs_class* underscore1 = 0;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_class_isequal(sjs_class* _parent, sjs_class* r, bool* _return);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->bob = _from->bob;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_isequal(sjs_class* _parent, sjs_class* r, bool* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sjs_class* sjt_dot1 = 0;
    sjs_class* sjt_dot2 = 0;

    sjt_dot1 = _parent;
    sjt_compare1 = (sjt_dot1)->bob;
    sjt_dot2 = r;
    sjt_compare2 = (sjt_dot2)->bob;
    (*_return) = sjt_compare1 == sjt_compare2;
}

int main(int argc, char** argv) {
    sjv_a._refCount = 1;
    sjv_a.bob = 3;
    sjf_class(&sjv_a);
    underscore1 = &sjv_a;
    sjt_parent1 = underscore1;
    sjt_call1._refCount = 1;
    sjt_call1.bob = 4;
    sjf_class(&sjt_call1);
    sjt_functionParam1 = &sjt_call1;
    sjf_class_isequal(sjt_parent1, sjt_functionParam1, &sjt_switch1);
    if (sjt_switch1) {
        sjv_y = 1;
    } else {
        sjs_class sjt_call2 = { -1 };
        sjs_class* sjt_functionParam2 = 0;
        sjs_class* sjt_parent2 = 0;
        bool sjt_switch2;

        sjt_parent2 = underscore1;
        sjt_call2._refCount = 1;
        sjt_call2.bob = 2;
        sjf_class(&sjt_call2);
        sjt_functionParam2 = &sjt_call2;
        sjf_class_isequal(sjt_parent2, sjt_functionParam2, &sjt_switch2);
        if (sjt_switch2) {
            sjv_y = 2;
        } else {
            sjv_y = 3;
        }

        if (sjt_call2._refCount == 1) { sjf_class_destroy(&sjt_call2); }
    }
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
    if (sjv_a._refCount == 1) { sjf_class_destroy(&sjv_a); }
}
