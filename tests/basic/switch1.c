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

int32_t sjt_compare1;
int32_t sjt_compare2;
bool sjt_switch1;
int32_t sjv_a;
int32_t sjv_y;
int32_t underscore1;

void main_destroy(void);

int main(int argc, char** argv) {
#line 1 "switch1.sj"
    sjv_a = 3;
#line 2
    underscore1 = sjv_a;
#line 2
    sjt_compare1 = underscore1;
#line 3
    sjt_compare2 = 0;
#line 3
    sjt_switch1 = sjt_compare1 == sjt_compare2;
    if (sjt_switch1) {
#line 3 "switch1.sj"
        sjv_y = 1;
    } else {
        int32_t sjt_compare3;
        int32_t sjt_compare4;
        bool sjt_switch2;

#line 2 "switch1.sj"
        sjt_compare3 = underscore1;
#line 4
        sjt_compare4 = 2;
#line 4
        sjt_switch2 = sjt_compare3 == sjt_compare4;
        if (sjt_switch2) {
#line 4 "switch1.sj"
            sjv_y = 2;
        } else {
#line 5 "switch1.sj"
            sjv_y = 3;
        }
    }
    main_destroy();
    return 0;
}

void main_destroy() {
}
