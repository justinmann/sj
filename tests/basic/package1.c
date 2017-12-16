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

typedef struct td_sjs_object sjs_object;

struct td_sjs_object {
    intptr_t _refCount;
};

int32_t sjv_b;
int32_t sjv_c;
int32_t sjv_x;
int32_t sjv_y;

void sjf_b_func(int32_t* _return);
void main_destroy(void);

void sjf_b_func(int32_t* _return) {
#line 6 "package1.sj"
    (*_return) = sjv_x;
}

int main(int argc, char** argv) {
#line 2 "package1.sj"
    sjv_x = 0;
#line 10
    sjv_b = sjv_x;
#line 10
    sjf_b_func(&sjv_c);
#line 19
    sjv_y = 0;
    main_destroy();
    return 0;
}

void main_destroy() {
}
