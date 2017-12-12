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

typedef struct td_uintptr_option uintptr_option;
struct td_uintptr_option {
    bool isEmpty;
    uintptr_t value;
};
const uintptr_option uintptr_empty = { true };

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
#define sjs_class_typeId 2
#define sjs_class_heap_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_class {
    int32_option d;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
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
void sjf_class_heap(sjs_class_heap* _this);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 1 "ifValue.sj"
    _this->d = _from->d;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

int main(int argc, char** argv) {
#line 5 "ifValue.sj"
    sjv_a = int32_empty;
#line 6
    sjt_value1 = 5;
#line 6
    value1.isEmpty = false;
#line 6
    value1.value = sjt_value1;
#line 6
    sjv_b = value1;
#line 2
    sjv_c.d = int32_empty;
#line 2
    sjf_class(&sjv_c);
#line 9
    sjt_isEmpty2 = sjv_a;
#line 9
    sjt_isEmpty1 = sjt_isEmpty2.isEmpty;
    if (!sjt_isEmpty1) {
        int32_t ifValue1;
        int32_option sjt_getValue1;

#line 9 "ifValue.sj"
        sjt_getValue1 = sjv_a;
#line 9
        ifValue1 = sjt_getValue1.value;
#line 9
        sjv_w = ifValue1;
    } else {
#line 12 "ifValue.sj"
        sjv_w = 2;
    }

#line 15
    sjt_isEmpty4 = sjv_b;
#line 15
    sjt_isEmpty3 = sjt_isEmpty4.isEmpty;
    if (!sjt_isEmpty3) {
        int32_t ifValue2;
        int32_option sjt_getValue2;

#line 15 "ifValue.sj"
        sjt_getValue2 = sjv_b;
#line 15
        ifValue2 = sjt_getValue2.value;
#line 15
        sjv_x = ifValue2;
    } else {
#line 18 "ifValue.sj"
        sjv_x = 2;
    }

#line 1
    sjt_dot1 = &sjv_c;
#line 21
    sjt_isEmpty6 = (sjt_dot1)->d;
#line 21
    sjt_isEmpty5 = sjt_isEmpty6.isEmpty;
    if (!sjt_isEmpty5) {
        int32_t ifValue3;
        sjs_class* sjt_dot2;
        int32_option sjt_getValue3;

#line 1 "ifValue.sj"
        sjt_dot2 = &sjv_c;
#line 21
        sjt_getValue3 = (sjt_dot2)->d;
#line 21
        ifValue3 = sjt_getValue3.value;
#line 21
        sjv_y = ifValue3;
    } else {
#line 24 "ifValue.sj"
        sjv_y = 1;
    }
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_class_destroy(&sjv_c);
}
