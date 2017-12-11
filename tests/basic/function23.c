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
#define sjs_func_typeId 2
#define sjs_func_heap_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_func sjs_func;
typedef struct td_sjs_func_heap sjs_func_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_func {
    int32_t x;
    int32_t y;
    int32_t z;
};

struct td_sjs_func_heap {
    intptr_t _refCount;
    int32_t x;
    int32_t y;
    int32_t z;
};

sjs_func void1;
sjs_func void2;

void sjf_func(sjs_func* _this);
void sjf_func_copy(sjs_func* _this, sjs_func* _from);
void sjf_func_destroy(sjs_func* _this);
void sjf_func_heap(sjs_func_heap* _this);
void main_destroy(void);

void sjf_func(sjs_func* _this) {
}

void sjf_func_copy(sjs_func* _this, sjs_func* _from) {
#line 1 "function23.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
#line 1
    _this->z = _from->z;
}

void sjf_func_destroy(sjs_func* _this) {
}

void sjf_func_heap(sjs_func_heap* _this) {
}

int main(int argc, char** argv) {
#line 4 "function23.sj"
    void1.x = 4;
#line 5
    void1.y = 5;
#line 6
    void1.z = 6;
#line 6
    sjf_func(&void1);
#line 7
    void2.x = 7;
#line 7
    void2.y = 8;
#line 7
    void2.z = 9;
#line 7
    sjf_func(&void2);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_func_destroy(&void1);
    sjf_func_destroy(&void2);
}
