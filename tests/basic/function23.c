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
#define sjs_func_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_func sjs_func;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_func {
    int _refCount;
    int32_t x;
    int32_t y;
    int32_t z;
};

sjs_func void1 = { -1 };
sjs_func void2 = { -1 };

void sjf_func(sjs_func* _this);
void sjf_func_copy(sjs_func* _this, sjs_func* _from);
void sjf_func_destroy(sjs_func* _this);
void sjf_func_heap(sjs_func* _this);
void main_destroy(void);

void sjf_func(sjs_func* _this) {
}

void sjf_func_copy(sjs_func* _this, sjs_func* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
    _this->z = _from->z;
}

void sjf_func_destroy(sjs_func* _this) {
}

void sjf_func_heap(sjs_func* _this) {
}

int main(int argc, char** argv) {
    void1._refCount = 1;
    void1.x = 4;
    void1.y = 5;
    void1.z = 6;
    sjf_func(&void1);
    void2._refCount = 1;
    void2.x = 7;
    void2.y = 8;
    void2.z = 9;
    sjf_func(&void2);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (void1._refCount == 1) { sjf_func_destroy(&void1); }
    if (void2._refCount == 1) { sjf_func_destroy(&void2); }
}
