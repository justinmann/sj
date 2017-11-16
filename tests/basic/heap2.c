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

#define sjs_class_typeId 1
#define sjs_class_anon1_typeId 2
#define sjs_object_typeId 3

typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_anon1 sjs_class_anon1;
typedef struct td_sjs_object sjs_object;

struct td_sjs_class {
    int _refCount;
    sjs_class_anon1* data;
};

struct td_sjs_class_anon1 {
    int _refCount;
    int32_t x;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_anon1(sjs_class_anon1* _this, sjs_class_anon1** _return);
void sjf_class_anon1_destroy(sjs_class_anon1* _this);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_get(sjs_class* _parent, sjs_class_anon1** _return);

sjs_class sjd_temp1;

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_anon1(sjs_class_anon1* _this, sjs_class_anon1** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_anon1_destroy(sjs_class_anon1* _this) {
}

void sjf_class_destroy(sjs_class* _this) {
    _this->data->_refCount--;
    if (_this->data->_refCount <= 0) {
        sjf_class_anon1_destroy(_this->data);
        free(_this->data);
    }
}

void sjf_class_get(sjs_class* _parent, sjs_class_anon1** _return) {
    sjs_class_anon1* dotTemp1;

    dotTemp1 = _parent->data;

    *_return = dotTemp1;
}

int main() {
    sjs_class* c;
    sjs_class_anon1* d;
    sjs_class_anon1* result1;
    sjs_class* sjv_temp1;
    sjs_class_anon1* sjv_temp2;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp2 = (sjs_class_anon1*)malloc(sizeof(sjs_class_anon1));
    sjv_temp2->_refCount = 1;
    sjv_temp2->x = 0;
    sjf_class_anon1(sjv_temp2, &sjv_temp2);
    sjv_temp1->data = sjv_temp2;
    sjv_temp1->data->_refCount++;
    sjf_class(sjv_temp1, &sjv_temp1);
    c = sjv_temp1;
    c->_refCount++;
    result1 = 0;
    sjf_class_get(c, &result1);
    d = result1;
    d->_refCount++;

    d->_refCount--;
    if (d->_refCount <= 0) {
        sjf_class_anon1_destroy(d);
        free(d);
    }
    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sjf_class_anon1_destroy(result1);
        free(result1);
    }
    sjv_temp2->_refCount--;
    if (sjv_temp2->_refCount <= 0) {
        sjf_class_anon1_destroy(sjv_temp2);
        free(sjv_temp2);
    }
    sjf_class_destroy(&sjd_temp1);
    return 0;
}
