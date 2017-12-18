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

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

sjs_class sjt_call1 = { -1 };
sjs_class* sjt_copy1 = 0;
sjs_class* sjt_functionParam1 = 0;
bool sjt_ifElse1;
bool sjt_ifElse2;
bool sjt_ifElse4;
int32_option sjt_isEmpty1;
sjs_class* sjt_isEmpty2 = 0;
sjs_class* sjt_isEmpty4 = 0;
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
    bool sjt_ifElse5;
    bool sjt_ifElse6;
    int32_option sjt_isEmpty5;
    sjs_class* sjt_isEmpty6 = 0;

    sjt_isEmpty6 = c;
    sjt_ifElse6 = (sjt_isEmpty6 == 0);
    if (sjt_ifElse6) {
        sjt_isEmpty5 = int32_empty;
    } else {
        sjs_class* sjt_dot3 = 0;
        int32_t sjt_value3;
        int32_option value3;

        sjt_dot3 = c;
        sjt_value3 = (sjt_dot3)->x;
        value3.isempty = false;
        value3.value = sjt_value3;
        sjt_isEmpty5 = value3;
    }

    sjt_ifElse5 = sjt_isEmpty5.isempty;
    if (sjt_ifElse5) {
        (*_return) = 0;
    } else {
        int32_option sjt_getValue2;
        bool sjt_ifElse7;
        sjs_class* sjt_isEmpty7 = 0;

        sjt_isEmpty7 = c;
        sjt_ifElse7 = (sjt_isEmpty7 == 0);
        if (sjt_ifElse7) {
            sjt_getValue2 = int32_empty;
        } else {
            sjs_class* sjt_dot4 = 0;
            int32_t sjt_value4;
            int32_option value4;

            sjt_dot4 = c;
            sjt_value4 = (sjt_dot4)->x;
            value4.isempty = false;
            value4.value = sjt_value4;
            sjt_getValue2 = value4;
        }

        (*_return) = sjt_getValue2.value;
    }
}

int main(int argc, char** argv) {
    sjv_c._refCount = 1;
    sjv_c.x = 1;
    sjf_class(&sjv_c);
    sjt_isEmpty2 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjt_ifElse2 = (sjt_isEmpty2 == 0);
    if (sjt_ifElse2) {
        sjt_isEmpty1 = int32_empty;
    } else {
        sjs_class* sjt_dot1 = 0;
        int32_t sjt_value1;
        int32_option value1;

        sjt_dot1 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_value1 = (sjt_dot1)->x;
        value1.isempty = false;
        value1.value = sjt_value1;
        sjt_isEmpty1 = value1;
    }

    sjt_ifElse1 = sjt_isEmpty1.isempty;
    if (sjt_ifElse1) {
        sjv_d = 0;
    } else {
        int32_option sjt_getValue1;
        bool sjt_ifElse3;
        sjs_class* sjt_isEmpty3 = 0;

        sjt_isEmpty3 = (sjv_c._refCount != -1 ? &sjv_c : 0);
        sjt_ifElse3 = (sjt_isEmpty3 == 0);
        if (sjt_ifElse3) {
            sjt_getValue1 = int32_empty;
        } else {
            sjs_class* sjt_dot2 = 0;
            int32_t sjt_value2;
            int32_option value2;

            sjt_dot2 = (sjv_c._refCount != -1 ? &sjv_c : 0);
            sjt_value2 = (sjt_dot2)->x;
            value2.isempty = false;
            value2.value = sjt_value2;
            sjt_getValue1 = value2;
        }

        sjv_d = sjt_getValue1.value;
    }

    sjt_isEmpty4 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    sjt_ifElse4 = (sjt_isEmpty4 == 0);
    if (sjt_ifElse4) {
        sjt_call1._refCount = 1;
        sjt_call1.x = 2;
        sjf_class(&sjt_call1);
        sjt_copy1 = &sjt_call1;
    } else {
        sjt_copy1 = (sjv_c._refCount != -1 ? &sjv_c : 0);
    }

    sjv_e._refCount = 1;
    sjf_class_copy(&sjv_e, sjt_copy1);
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

    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
    if (sjv_e._refCount == 1) { sjf_class_destroy(&sjv_e); }
}
