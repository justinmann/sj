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

typedef struct td_sjs_object sjs_object;

struct td_sjs_object {
    int _refCount;
};



int main() {
    int32_t ifResult1;

    if (false) {
        ifResult1 = 1;
    } else {
        int32_t ifResult2;

        if (false) {
            ifResult2 = 2;
        } else {
            int32_t ifResult3;

            if (false) {
                ifResult3 = 2;
            } else {
                int32_t ifResult4;

                if (false) {
                    ifResult4 = 2;
                } else {
                    int32_t ifResult5;

                    if (false) {
                        ifResult5 = 2;
                    } else {
                        int32_t ifResult6;

                        if (false) {
                            ifResult6 = 2;
                        } else {
                            int32_t ifResult7;

                            if (false) {
                                ifResult7 = 2;
                            } else {
                                ifResult7 = 3;
                            }

                            ifResult6 = ifResult7;
                        }

                        ifResult5 = ifResult6;
                    }

                    ifResult4 = ifResult5;
                }

                ifResult3 = ifResult4;
            }

            ifResult2 = ifResult3;
        }

        ifResult1 = ifResult2;
    }
    return 0;
}
