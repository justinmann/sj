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

#define sjs_a_typeId 1
#define sjs_a_aa_typeId 2
#define sjs_object_typeId 3

typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_a_aa sjs_a_aa;
typedef struct td_sjs_object sjs_object;

struct td_sjs_a {
    int _refCount;
    int32_t x;
    sjs_a_aa* b;
};

struct td_sjs_a_aa {
    int _refCount;
    sjs_a* _parent;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_a(sjs_a* _this, sjs_a** _return);
void sjf_a_aa(sjs_a_aa* _this, sjs_a_aa** _return);
void sjf_a_aa_c(sjs_a_aa* _parent, int32_t* _return);
void sjf_a_aa_destroy(sjs_a_aa* _this);
void sjf_a_destroy(sjs_a* _this);

sjs_a_aa sjd_temp1;
sjs_a sjd_temp2;

void sjf_a(sjs_a* _this, sjs_a** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_a_aa(sjs_a_aa* _this, sjs_a_aa** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_a_aa_c(sjs_a_aa* _parent, int32_t* _return) {
    int32_t dotTemp2;
    sjs_a* tempParent1;

    tempParent1 = _parent->_parent;
    dotTemp2 = tempParent1->x;

    *_return = dotTemp2;
}

void sjf_a_aa_destroy(sjs_a_aa* _this) {
}

void sjf_a_destroy(sjs_a* _this) {
    sjf_a_aa_destroy(_this->b);
}

int main() {
    sjs_a* a;
    sjs_a_aa* d;
    sjs_a_aa* dotTemp1;
    sjs_a_aa* dotTemp3;
    int32_t result1;
    int32_t result2;
    sjs_a_aa* sjv_temp1;
    sjs_a* sjv_temp2;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_a_aa(sjv_temp1, &sjv_temp1);
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->x = 1;
    sjv_temp2->b = sjv_temp1;
    sjv_temp2->b->_refCount++;
    sjf_a(sjv_temp2, &sjv_temp2);
    a = sjv_temp2;
    a->_refCount++;
    dotTemp1 = a->b;
    result1 = 0;
    sjf_a_aa_c(dotTemp1, &result1);
    dotTemp3 = a->b;
    d = dotTemp3;
    d->_refCount++;
    result2 = 0;
    sjf_a_aa_c(d, &result2);
    sjf_a_aa_destroy(&sjd_temp1);
    sjf_a_destroy(&sjd_temp2);
    return 0;
}
