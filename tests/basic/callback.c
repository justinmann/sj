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
#define cb_void_typeId 2
#define cb_void_heap_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_cb_void cb_void;
typedef struct td_cb_void_heap cb_void_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_cb_void {
    void* _parent;
    void (*_cb)(void* _parent);
};

struct td_cb_void_heap {
    sjs_object* _parent;
    void (*_cb)(void* _parent);
};

cb_void callback1;
cb_void sjv_f;

void main_destroy(void);

int main(int argc, char** argv) {
#line 5 ".\basic\callback.sj"
    sjv_f = callback1;
#line 0 ""
    sjv_f._cb(sjv_f._parent);
    main_destroy();
    return 0;
}

void main_destroy() {
}
