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
    int32_option d;
};

sjs_class* sjt_dot1;
bool sjt_isEmpty1;
int32_option sjt_isEmpty2;
bool sjt_isEmpty3;
int32_option sjt_isEmpty4;
bool sjt_isEmpty5;
int32_option sjt_isEmpty6;
int32_t sjt_value1;
int32_option sjv_a;
int32_option sjv_b;
sjs_class sjv_c;
int32_t sjv_w;
int32_t sjv_x;
int32_t sjv_y;
int32_option value1;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->d = _from->d;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

int main(int argc, char** argv) {
    sjv_a = int32_empty;
    sjt_value1 = 5;
    value1.isempty = false;
    value1.value = sjt_value1;
    sjv_b = value1;
    sjv_c.d = int32_empty;
    sjf_class(&sjv_c);
    sjt_isEmpty2 = sjv_a;
    sjt_isEmpty1 = sjt_isEmpty2.isempty;
    if (!sjt_isEmpty1) {
        int32_t ifValue1;
        int32_option sjt_getValue1;

        sjt_getValue1 = sjv_a;
        ifValue1 = sjt_getValue1.value;
        sjv_w = ifValue1;
    } else {
        sjv_w = 2;
    }

    sjt_isEmpty4 = sjv_b;
    sjt_isEmpty3 = sjt_isEmpty4.isempty;
    if (!sjt_isEmpty3) {
        int32_t ifValue2;
        int32_option sjt_getValue2;

        sjt_getValue2 = sjv_b;
        ifValue2 = sjt_getValue2.value;
        sjv_x = ifValue2;
    } else {
        sjv_x = 2;
    }

    sjt_dot1 = &sjv_c;
    sjt_isEmpty6 = (sjt_dot1)->d;
    sjt_isEmpty5 = sjt_isEmpty6.isempty;
    if (!sjt_isEmpty5) {
        int32_t ifValue3;
        sjs_class* sjt_dot2;
        int32_option sjt_getValue3;

        sjt_dot2 = &sjv_c;
        sjt_getValue3 = (sjt_dot2)->d;
        ifValue3 = sjt_getValue3.value;
        sjv_y = ifValue3;
    } else {
        sjv_y = 1;
    }
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjf_class_destroy(&sjv_c);
}
