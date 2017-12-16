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

typedef struct td_void_option void_option;
struct td_void_option {
    bool isEmpty;
    void* value;
};
const void_option void_empty = { true };

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

typedef struct td_sjs_object sjs_object;

struct td_sjs_object {
    intptr_t _refCount;
};

int32_option sjv_b;
int32_t sjv_bar2_a;
int32_t sjv_bar2_b;
int32_t sjv_bar2_c;
int32_t sjv_bar_a;
int32_t sjv_bar_b;
int32_t sjv_bar_c;

void sjf_func(int32_option* _return);
void main_destroy(void);

void sjf_func(int32_option* _return) {
    int32_t sjt_value1;
    int32_option value1;

#line 15 "enum.sj"
    sjt_value1 = sjv_bar_a;
#line 15
    value1.isEmpty = false;
#line 15
    value1.value = sjt_value1;
#line 15
    (*_return) = value1;
}

int main(int argc, char** argv) {
#line 1 "enum.sj"
    sjv_bar_a = 0;
#line 1
    sjv_bar_b = 1;
#line 1
    sjv_bar_c = 2;
#line 8
    sjv_bar2_a = 0;
#line 8
    sjv_bar2_b = 1;
#line 8
    sjv_bar2_c = 2;
#line 8
    sjf_func(&sjv_b);
    main_destroy();
    return 0;
}

void main_destroy() {
}
