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

bool sjt_ifElse1;

void main_destroy(void);

int main(int argc, char** argv) {
#line 1 "if5.sj"
    sjt_ifElse1 = false;
    if (sjt_ifElse1) {
    } else {
        bool sjt_ifElse2;

#line 1 "if5.sj"
        sjt_ifElse2 = false;
        if (sjt_ifElse2) {
        } else {
            bool sjt_ifElse3;

#line 1 "if5.sj"
            sjt_ifElse3 = false;
            if (sjt_ifElse3) {
            } else {
                bool sjt_ifElse4;

#line 1 "if5.sj"
                sjt_ifElse4 = false;
                if (sjt_ifElse4) {
                } else {
                    bool sjt_ifElse5;

#line 1 "if5.sj"
                    sjt_ifElse5 = false;
                    if (sjt_ifElse5) {
                    } else {
                        bool sjt_ifElse6;

#line 1 "if5.sj"
                        sjt_ifElse6 = false;
                        if (sjt_ifElse6) {
                        } else {
                            bool sjt_ifElse7;

#line 1 "if5.sj"
                            sjt_ifElse7 = false;
                            if (sjt_ifElse7) {
                            } else {
                            }
                        }
                    }
                }
            }
        }
    }
    main_destroy();
    return 0;
}

void main_destroy() {
}
