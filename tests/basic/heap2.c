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
#define sjs_class_anon1_typeId 2
#define sjs_class_anon1_heap_typeId 3
#define sjs_class_typeId 4
#define sjs_class_heap_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class_anon1 sjs_class_anon1;
typedef struct td_sjs_class_anon1_heap sjs_class_anon1_heap;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_class_anon1 {
    sjs_class* _parent;
    int32_t x;
};

struct td_sjs_class_anon1_heap {
    int _refCount;
    sjs_class* _parent;
    int32_t x;
};

struct td_sjs_class {
    sjs_class_anon1 data;
};

struct td_sjs_class_heap {
    int _refCount;
    sjs_class_anon1 data;
};

sjs_class c;
sjs_class_anon1* d;
sjs_class* sjt_dot1;

void sjf_class(sjs_class* _this);
void sjf_class_anon1(sjs_class_anon1* _this);
void sjf_class_anon1_copy(sjs_class_anon1* _this, sjs_class_anon1* to);
void sjf_class_anon1_destroy(sjs_class_anon1* _this);
void sjf_class_anon1_heap(sjs_class_anon1_heap* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_get(sjs_class* _parent, sjs_class_anon1** _return);
void sjf_class_heap(sjs_class_heap* _this);
void main_destroy();

void sjf_class(sjs_class* _this) {
}

void sjf_class_anon1(sjs_class_anon1* _this) {
}

void sjf_class_anon1_copy(sjs_class_anon1* _this, sjs_class_anon1* to) {
    _this->x = to->x;
}

void sjf_class_anon1_destroy(sjs_class_anon1* _this) {
}

void sjf_class_anon1_heap(sjs_class_anon1_heap* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* to) {
    sjf_class_anon1_copy(&_this->data, &to->data);
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_get(sjs_class* _parent, sjs_class_anon1** _return) {
    sjs_class_anon1 dotTemp1;

    dotTemp1 = _parent->data;
    (*_return) = &dotTemp1;

    sjf_class_anon1_destroy(&dotTemp1);
}

void sjf_class_heap(sjs_class_heap* _this) {
}

int main() {
    c.data._parent = c._parent;
    c.data.x = 0;
    sjf_class_anon1(&c.data);
    sjf_class(&c);
    sjt_dot1 = &c;
    sjf_class_get(sjt_dot1, &d);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_class_destroy(&c);
}
