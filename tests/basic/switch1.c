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
#define sjs_class_heap_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_class {
    int32_t bob;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
    int32_t bob;
};

sjs_class sjt_call1;
sjs_class* sjt_functionParam1;
sjs_class* sjt_parent1;
bool sjt_switch1;
sjs_class sjv_a;
int32_t sjv_y;
sjs_class* underscore1;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_class_isequal(sjs_class* _parent, sjs_class* r, bool* _return);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 1 "switch1.sj"
    _this->bob = _from->bob;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_class_isequal(sjs_class* _parent, sjs_class* r, bool* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sjs_class* sjt_dot1;
    sjs_class* sjt_dot2;

#line 3 "switch1.sj"
    sjt_dot1 = _parent;
#line 4
    sjt_compare1 = (sjt_dot1)->bob;
#line 3
    sjt_dot2 = r;
#line 4
    sjt_compare2 = (sjt_dot2)->bob;
#line 4
    (*_return) = sjt_compare1 == sjt_compare2;
}

int main(int argc, char** argv) {
#line 8 "switch1.sj"
    sjv_a.bob = 3;
#line 8
    sjf_class(&sjv_a);
#line 9
    underscore1 = &sjv_a;
#line 9
    sjt_parent1 = underscore1;
#line 10
    sjt_call1.bob = 4;
#line 10
    sjf_class(&sjt_call1);
#line 10
    sjt_functionParam1 = &sjt_call1;
#line 10
    sjf_class_isequal(sjt_parent1, sjt_functionParam1, &sjt_switch1);
    if (sjt_switch1) {
#line 10 "switch1.sj"
        sjv_y = 1;
    } else {
        sjs_class sjt_call2;
        sjs_class* sjt_functionParam2;
        sjs_class* sjt_parent2;
        bool sjt_switch2;

#line 9 "switch1.sj"
        sjt_parent2 = underscore1;
#line 11
        sjt_call2.bob = 2;
#line 11
        sjf_class(&sjt_call2);
#line 11
        sjt_functionParam2 = &sjt_call2;
#line 11
        sjf_class_isequal(sjt_parent2, sjt_functionParam2, &sjt_switch2);
        if (sjt_switch2) {
#line 11 "switch1.sj"
            sjv_y = 2;
        } else {
#line 12 "switch1.sj"
            sjv_y = 3;
        }

        sjf_class_destroy(&sjt_call2);
    }
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_class_destroy(&sjt_call1);
    sjf_class_destroy(&sjv_a);
}
