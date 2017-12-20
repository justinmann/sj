#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isvalid;
    int32_t value;
};
const int32_option int32_empty = { false };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isvalid;
    uint32_t value;
};
const uint32_option uint32_empty = { false };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isvalid;
    int64_t value;
};
const int64_option int64_empty = { false };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isvalid;
    uint64_t value;
};
const uint64_option uint64_empty = { false };

typedef struct td_void_option void_option;
struct td_void_option {
    bool isvalid;
    void* value;
};
const void_option void_empty = { false };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isvalid;
    char value;
};
const char_option char_empty = { false };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isvalid;
    float value;
};
const float_option float_empty = { false };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isvalid;
    double value;
};
const double_option double_empty = { false };

#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_class_i32_char_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_class_i32_char sjs_class_i32_char;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_class_i32_char {
    int _refCount;
    int32_t x;
};

sjs_class_i32_char sjt_call1 = { -1 };
sjs_class_i32_char sjt_call2 = { -1 };
int32_t sjt_functionParam1;
sjs_class_i32_char* sjt_functionParam2 = 0;
int32_t sjt_functionParam3;
sjs_class_i32_char* sjt_functionParam4 = 0;
int32_t sjv_a;
int32_t sjv_b;

void sjf_class_i32_char(sjs_class_i32_char* _this);
void sjf_class_i32_char_copy(sjs_class_i32_char* _this, sjs_class_i32_char* _from);
void sjf_class_i32_char_destroy(sjs_class_i32_char* _this);
void sjf_class_i32_char_heap(sjs_class_i32_char* _this);
void sjf_i32_addclass_bang_i32_char(int32_t x, sjs_class_i32_char* y, int32_t* _return);
void main_destroy(void);

void sjf_class_i32_char(sjs_class_i32_char* _this) {
}

void sjf_class_i32_char_copy(sjs_class_i32_char* _this, sjs_class_i32_char* _from) {
    _this->x = _from->x;
}

void sjf_class_i32_char_destroy(sjs_class_i32_char* _this) {
}

void sjf_class_i32_char_heap(sjs_class_i32_char* _this) {
}

void sjf_i32_addclass_bang_i32_char(int32_t x, sjs_class_i32_char* y, int32_t* _return) {
    sjs_class_i32_char* sjt_dot1 = 0;
    int32_t sjt_math1;
    int32_t sjt_math2;

    sjt_math1 = x;
    sjt_dot1 = y;
    sjt_math2 = (sjt_dot1)->x;
    (*_return) = sjt_math1 + sjt_math2;
}

int main(int argc, char** argv) {
    sjt_functionParam1 = 1;
    sjt_call1._refCount = 1;
    sjt_call1.x = 2;
    sjf_class_i32_char(&sjt_call1);
    sjt_functionParam2 = &sjt_call1;
    sjf_i32_addclass_bang_i32_char(sjt_functionParam1, sjt_functionParam2, &sjv_a);
    sjt_functionParam3 = 1;
    sjt_call2._refCount = 1;
    sjt_call2.x = 2;
    sjf_class_i32_char(&sjt_call2);
    sjt_functionParam4 = &sjt_call2;
    sjf_i32_addclass_bang_i32_char(sjt_functionParam3, sjt_functionParam4, &sjv_b);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_class_i32_char_destroy(&sjt_call1); }
    if (sjt_call2._refCount == 1) { sjf_class_i32_char_destroy(&sjt_call2); }
}
