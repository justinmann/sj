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
    int32_t x;
};

sjs_class* sjt_functionParam1 = 0;
bool sjt_ifElse1;
bool sjt_ifElse2;
bool sjt_ifElse4;
bool sjt_ifElse5;
int32_option sjt_isEmpty1;
sjs_class* sjt_isEmpty2 = 0;
sjs_class* sjt_isEmpty4 = 0;
sjs_class* sjt_isEmpty5 = 0;
sjs_class sjt_value3 = { -1 };
sjs_class sjv_c = { -1 };
int32_t sjv_d;
sjs_class sjv_e = { -1 };
int32_t void1;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_func(sjs_class* c, int32_t* _return);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_func(sjs_class* c, int32_t* _return) {
    bool sjt_ifElse7;
    bool sjt_ifElse8;
    int32_option sjt_isEmpty7;
    sjs_class* sjt_isEmpty8 = 0;

    sjt_isEmpty8 = c;
    sjt_ifElse8 = (sjt_isEmpty8 != 0);
    if (sjt_ifElse8) {
        sjs_class* sjt_dot3 = 0;
        int32_t sjt_value4;
        int32_option value3;

        sjt_dot3 = c;
        sjt_value4 = (sjt_dot3)->x;
        value3.isvalid = true;
        value3.value = sjt_value4;
        sjt_isEmpty7 = value3;
    } else {
        sjt_isEmpty7 = int32_empty;
    }

    sjt_ifElse7 = sjt_isEmpty7.isvalid;
    if (sjt_ifElse7) {
        int32_option sjt_getValue2;
        bool sjt_ifElse9;
        sjs_class* sjt_isEmpty9 = 0;

        sjt_isEmpty9 = c;
        sjt_ifElse9 = (sjt_isEmpty9 != 0);
        if (sjt_ifElse9) {
            sjs_class* sjt_dot4 = 0;
            int32_t sjt_value5;
            int32_option value4;

            sjt_dot4 = c;
            sjt_value5 = (sjt_dot4)->x;
            value4.isvalid = true;
            value4.value = sjt_value5;
            sjt_getValue2 = value4;
        } else {
            sjt_getValue2 = int32_empty;
        }

        (*_return) = sjt_getValue2.value;
    } else {
        (*_return) = 0;
    }
}

int main(int argc, char** argv) {
    sjv_c._refCount = 1;
    sjv_c.x = 1;
    sjf_class(&sjv_c);
    sjt_isEmpty2 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjt_ifElse2 = (sjt_isEmpty2 != 0);
    if (sjt_ifElse2) {
        sjs_class* sjt_dot1 = 0;
        int32_t sjt_value1;
        int32_option value1;

        sjt_dot1 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_value1 = (sjt_dot1)->x;
        value1.isvalid = true;
        value1.value = sjt_value1;
        sjt_isEmpty1 = value1;
    } else {
        sjt_isEmpty1 = int32_empty;
    }

    sjt_ifElse1 = sjt_isEmpty1.isvalid;
    if (sjt_ifElse1) {
        int32_option sjt_getValue1;
        bool sjt_ifElse3;
        sjs_class* sjt_isEmpty3 = 0;

        sjt_isEmpty3 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_ifElse3 = (sjt_isEmpty3 != 0);
        if (sjt_ifElse3) {
            sjs_class* sjt_dot2 = 0;
            int32_t sjt_value2;
            int32_option value2;

            sjt_dot2 = (sjv_c._refCount != -1 ? &sjv_c : 0);
            sjt_value2 = (sjt_dot2)->x;
            value2.isvalid = true;
            value2.value = sjt_value2;
            sjt_getValue1 = value2;
        } else {
            sjt_getValue1 = int32_empty;
        }

        sjv_d = sjt_getValue1.value;
    } else {
        sjv_d = 0;
    }

    sjt_isEmpty5 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjt_ifElse5 = (sjt_isEmpty5 != 0);
    if (sjt_ifElse5) {
        sjs_class* sjt_copy1 = 0;

        sjt_copy1 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_value3._refCount = 1;
        sjf_class_copy(&sjt_value3, sjt_copy1);
        sjt_isEmpty4 = (sjt_value3._refCount != -1 ? &sjt_value3 : 0);
    } else {
        sjt_isEmpty4 = 0;
    }

    sjt_ifElse4 = (sjt_isEmpty4 != 0);
    if (sjt_ifElse4) {
        bool sjt_ifElse6;
        sjs_class* sjt_isEmpty6 = 0;

        sjt_isEmpty6 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_ifElse6 = (sjt_isEmpty6 != 0);
        if (sjt_ifElse6) {
            sjs_class* sjt_copy2 = 0;

            sjt_copy2 = (sjv_c._refCount != -1 ? &sjv_c : 0);
            sjv_e._refCount = 1;
            sjf_class_copy(&sjv_e, sjt_copy2);
        } else {
            sjv_e._refCount = -1;
        }
    } else {
        sjv_e._refCount = 1;
        sjv_e.x = 2;
        sjf_class(&sjv_e);
    }

    sjt_functionParam1 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjf_func(sjt_functionParam1, &void1);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_value3._refCount == 1) { sjf_class_destroy(&sjt_value3); }
    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
    if (sjv_e._refCount == 1) { sjf_class_destroy(&sjv_e); }
}
