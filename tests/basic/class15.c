#include <stdbool.h>
#include <stdint.h>
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

#define sjs_anon1_typeId 1
#define sjs_class_typeId 2
#define sjs_global_typeId 3
#define sjs_object_typeId 4

typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_global sjs_global;
typedef struct td_sjs_object sjs_object;

struct td_sjs_anon1 {
    int _refCount;
    int32_t test;
};

struct td_sjs_class {
    int _refCount;
    sjs_global* _parent;
};

struct td_sjs_global {
    int _refCount;
    sjs_anon1* math;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_sub(sjs_anon1* _parent, int32_t x, int32_t y, int32_t* _return);
void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_global(sjs_global* _this);
void sjf_global_destroy(sjs_global* _this);

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_sub(sjs_anon1* _parent, int32_t x, int32_t y, int32_t* _return) {
    int32_t dotTemp2;
    int32_t result5;
    int32_t result6;

    result5 = x - y;
    dotTemp2 = _parent->test;
    result6 = result5 - dotTemp2;

    *_return = result6;
}

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t result7;

    result7 = 0;
    sjf_class_foo(_parent, x, &result7);

    *_return = result7;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t ifResult1;
    bool result2;

    result2 = x > 0;
    if (result2) {
        sjs_anon1* dotTemp1;
        int32_t result3;
        int32_t result4;
        sjs_global* tempParent1;

        result3 = 0;
        tempParent1 = _parent->_parent;
        dotTemp1 = tempParent1->math;
        result4 = 0;
        sjf_anon1_sub(dotTemp1, x, 1, &result4);
        sjf_class_bar(_parent, result4, &result3);
        ifResult1 = result3;
    } else {
        ifResult1 = 0;
    }

    *_return = ifResult1;
}

void sjf_global(sjs_global* _this) {
    sjs_class sjd_temp1;
    sjs_class* c;
    int32_t result1;
    sjs_anon1* sjv_temp1;
    sjs_class* sjv_temp2;

    sjv_temp1 = (sjs_anon1*)malloc(sizeof(sjs_anon1));
    sjv_temp1->_refCount = 1;
    sjv_temp1->test = 1;
    sjf_anon1(sjv_temp1, &sjv_temp1);
    _this->math = sjv_temp1;
    _this->math->_refCount++;
    sjv_temp2 = &sjd_temp1;
    sjv_temp2->_refCount = 1;
    sjf_class(sjv_temp2, &sjv_temp2);
    c = sjv_temp2;
    c->_refCount++;
    result1 = 0;
    sjf_class_foo(c, 4, &result1);

    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount <= 0) {
        sjf_anon1_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjf_class_destroy(&sjd_temp1);
}

void sjf_global_destroy(sjs_global* _this) {
}

int main() {
    sjs_global sjd_temp2;
    sjs_global* sjv_temp3;

    sjv_temp3 = &sjd_temp2;
    sjv_temp3->_refCount = 1;
    sjf_global(sjv_temp3);
    sjf_global_destroy(&sjd_temp2);

    return 0;
}
