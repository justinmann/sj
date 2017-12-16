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
    int structsNeedAValue;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
};

sjs_class* sjv_b;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_func(sjs_class** _return);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_func(sjs_class** _return) {
    sjs_class sjt_call1;
    sjs_class sjt_call2;
    sjs_class* sjt_copy1;
    sjs_class* sjt_copy2;
    sjs_class sjv_a;

    sjf_class(&sjt_call1);
#line 4 "heap1.sj"
    sjt_copy1 = &sjt_call1;
#line 4
    sjf_class_copy(&sjv_a, sjt_copy1);
#line 4
    sjf_class(&sjt_call2);
#line 5
    sjt_copy2 = &sjt_call2;
#line 5
    sjf_class_copy(&sjv_a, sjt_copy2);
#line 5
    (*_return) = &sjv_a;

    sjf_class_destroy(&sjt_call1);
    sjf_class_destroy(&sjt_call2);
    sjf_class_destroy(&sjv_a);
}

int main(int argc, char** argv) {
    sjf_func(&sjv_b);
    main_destroy();
    return 0;
}

void main_destroy() {
}
