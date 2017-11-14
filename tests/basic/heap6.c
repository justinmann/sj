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

#define sjs_foo_typeId 1
#define sjs_object_typeId 2

typedef struct td_sjs_foo sjs_foo;
typedef struct td_sjs_object sjs_object;

struct td_sjs_foo {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_bar(sjs_foo** _return);
void sjf_foo(sjs_foo* _this, sjs_foo** _return);
void sjf_foo_destroy(sjs_foo* _this);


void sjf_bar(sjs_foo** _return) {
    sjs_foo* sjv_temp1;

    sjv_temp1 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_temp1->_refCount = 1;
    sjf_foo(sjv_temp1, &sjv_temp1);
    sjv_temp1->_refCount++;

    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount <= 0) {
        sjf_foo_destroy(sjv_temp1);
        free(sjv_temp1);
    }

    *_return = sjv_temp1;
}

void sjf_foo(sjs_foo* _this, sjs_foo** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_foo_destroy(sjs_foo* _this) {
}

int main() {
    sjs_foo* a;
    sjs_foo* result1;

    result1 = 0;
    sjf_bar(&result1);
    a = result1;
    a->_refCount++;

    a->_refCount--;
    if (a->_refCount <= 0) {
        sjf_foo_destroy(a);
        free(a);
    }
    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sjf_foo_destroy(result1);
        free(result1);
    }
    return 0;
}
