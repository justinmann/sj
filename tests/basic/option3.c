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

bool sjt_isEmpty1;
sjs_class* sjt_isEmpty2;
sjs_class sjv_a = { -1 };
int32_t sjv_b;
sjs_class sjv_c = { -1 };

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_func(sjs_class* _return);
void sjf_func_heap(sjs_class** _return);
void sjf_test(sjs_class* _return);
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

void sjf_func(sjs_class* _return) {
    _return->_refCount = -1;
}

void sjf_func_heap(sjs_class** _return) {
    (*_return) = 0;
    if ((*_return) != 0) {
        (*_return)->_refCount++;
    }
}

void sjf_test(sjs_class* _return) {
    bool sjt_ifElse1;
    sjs_class sjt_value1 = { -1 };
    sjs_class sjt_value2 = { -1 };

    sjt_ifElse1 = true;
    if (sjt_ifElse1) {
        bool sjt_ifElse2;
        sjs_class* sjt_isEmpty3;

        sjt_isEmpty3 = 0;
        sjt_ifElse2 = (sjt_isEmpty3 == 0);
        if (sjt_ifElse2) {
            _return->_refCount = -1;
        } else {
            sjs_class* sjt_copy1;

            sjt_copy1 = 0;
            _return->_refCount = 1;
            sjf_class_copy(_return, sjt_copy1);
        }
    } else {
        bool sjt_ifElse3;
        sjs_class* sjt_isEmpty4;

        sjt_value1._refCount = 1;
        sjt_value1.x = 2;
        sjf_class(&sjt_value1);
        sjt_isEmpty4 = (sjt_value1._refCount != -1 ? &sjt_value1 : 0);
        sjt_ifElse3 = (sjt_isEmpty4 == 0);
        if (sjt_ifElse3) {
            _return->_refCount = -1;
        } else {
            sjs_class* sjt_copy2;

            sjt_value2._refCount = 1;
            sjt_value2.x = 2;
            sjf_class(&sjt_value2);
            sjt_copy2 = (sjt_value2._refCount != -1 ? &sjt_value2 : 0);
            _return->_refCount = 1;
            sjf_class_copy(_return, sjt_copy2);
        }
    }

    if (sjt_value1._refCount == 1) { sjf_class_destroy(&sjt_value1); }
    if (sjt_value2._refCount == 1) { sjf_class_destroy(&sjt_value2); }
}

int main(int argc, char** argv) {
    sjf_func(&sjv_a);
    sjt_isEmpty2 = (sjv_a._refCount != -1 ? &sjv_a : 0);
    sjt_isEmpty1 = (sjt_isEmpty2 == 0);
    if (!sjt_isEmpty1) {
        sjs_class* ifValue1;
        sjs_class* sjt_dot1;

        ifValue1 = (sjv_a._refCount != -1 ? &sjv_a : 0);
        sjt_dot1 = ifValue1;
        sjv_b = (sjt_dot1)->x;
    } else {
        sjv_b = 0;
    }

    sjf_test(&sjv_c);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_a._refCount == 1) { sjf_class_destroy(&sjv_a); }
    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
}
