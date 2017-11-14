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
#define sjs_b_typeId 2
#define sjs_c_typeId 3
#define sjs_object_typeId 4

typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_b sjs_b;
typedef struct td_sjs_c sjs_c;
typedef struct td_sjs_object sjs_object;

struct td_sjs_a {
    int _refCount;
};

struct td_sjs_b {
    int _refCount;
    sjs_a* a;
};

struct td_sjs_c {
    int _refCount;
    sjs_b* b;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_a(sjs_a* _this, sjs_a** _return);
void sjf_a_destroy(sjs_a* _this);
void sjf_b(sjs_b* _this, sjs_b** _return);
void sjf_b_destroy(sjs_b* _this);
void sjf_c(sjs_c* _this, sjs_c** _return);
void sjf_c_destroy(sjs_c* _this);

sjs_a sjd_temp1;
sjs_b sjd_temp2;
sjs_c sjd_temp3;

void sjf_a(sjs_a* _this, sjs_a** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_a_destroy(sjs_a* _this) {
}

void sjf_b(sjs_b* _this, sjs_b** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_b_destroy(sjs_b* _this) {
    sjf_a_destroy(_this->a);
}

void sjf_c(sjs_c* _this, sjs_c** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_c_destroy(sjs_c* _this) {
    sjf_b_destroy(_this->b);
}

int main() {
    sjs_a* sjv_temp1;
    sjs_b* sjv_temp2;
    sjs_c* sjv_temp3;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_a(sjv_temp1, &sjv_temp1);
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->a = sjv_temp1;
    sjv_temp2->a->_refCount++;
    sjf_b(sjv_temp2, &sjv_temp2);
    sjv_temp3 = &sjd_temp3;
    sjv_temp3->_refCount = 1;
    sjv_temp3->b = sjv_temp2;
    sjv_temp3->b->_refCount++;
    sjf_c(sjv_temp3, &sjv_temp3);
    sjf_a_destroy(&sjd_temp1);
    sjf_b_destroy(&sjd_temp2);
    sjf_c_destroy(&sjd_temp3);
    return 0;
}
