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
#define sjs_foo_typeId 2
#define sjs_foo_heap_typeId 3
#define sjs_bar_typeId 4
#define sjs_bar_heap_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_foo sjs_foo;
typedef struct td_sjs_foo_heap sjs_foo_heap;
typedef struct td_sjs_bar sjs_bar;
typedef struct td_sjs_bar_heap sjs_bar_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_foo {
    int32_t x;
};

struct td_sjs_foo_heap {
    intptr_t _refCount;
    int32_t x;
};

struct td_sjs_bar {
    sjs_foo f;
};

struct td_sjs_bar_heap {
    intptr_t _refCount;
    sjs_foo f;
};

int32_t dotTemp1;
sjs_foo* sjt_dot1;
sjs_bar* sjt_functionParam1;
sjs_bar sjv_b;

void sjf_bar(sjs_bar* _this);
void sjf_bar_copy(sjs_bar* _this, sjs_bar* to);
void sjf_bar_destroy(sjs_bar* _this);
void sjf_bar_heap(sjs_bar_heap* _this);
void sjf_foo(sjs_foo* _this);
void sjf_foo_copy(sjs_foo* _this, sjs_foo* to);
void sjf_foo_destroy(sjs_foo* _this);
void sjf_foo_heap(sjs_foo_heap* _this);
void sjf_func(sjs_bar* b, sjs_foo** _return);
void main_destroy(void);

void sjf_bar(sjs_bar* _this) {
}

void sjf_bar_copy(sjs_bar* _this, sjs_bar* to) {
    sjf_foo_copy(&_this->f, &to->f);
}

void sjf_bar_destroy(sjs_bar* _this) {
}

void sjf_bar_heap(sjs_bar_heap* _this) {
}

void sjf_foo(sjs_foo* _this) {
}

void sjf_foo_copy(sjs_foo* _this, sjs_foo* to) {
    _this->x = to->x;
}

void sjf_foo_destroy(sjs_foo* _this) {
}

void sjf_foo_heap(sjs_foo_heap* _this) {
}

void sjf_func(sjs_bar* b, sjs_foo** _return) {
    sjs_bar* sjt_dot2;

    sjt_dot2 = b;
    sjt_dot2->f.x = 2;
    sjf_foo(&sjt_dot2->f);
    (*_return) = &sjt_dot2->f;
}

int main(int argc, char** argv) {
    sjv_b.f.x = 1;
    sjf_foo(&sjv_b.f);
    sjf_bar(&sjv_b);
    sjt_functionParam1 = &sjv_b;
    sjf_func(sjt_functionParam1, &sjt_dot1);
    dotTemp1 = sjt_dot1->x;
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_bar_destroy(&sjv_b);
}
