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
};

sjs_func* sjt_parent1 = 0;
sjs_func* sjv_a = 0;
sjs_func* sjv_b = 0;

void sjf_func_bar_heap(sjs_func* _parent, sjs_func** _return);
void sjf_func_copy(sjs_func* _this, sjs_func* _from);
void sjf_func_destroy(sjs_func* _this);
void sjf_func_heap(sjs_func* _this);
void main_destroy(void);

void sjf_func_bar_heap(sjs_func* _parent, sjs_func** _return) {
    (*_return) = _parent;
    (*_return)->_refCount++;
}

void sjf_func_copy(sjs_func* _this, sjs_func* _from) {
}

void sjf_func_destroy(sjs_func* _this) {
}

void sjf_func_heap(sjs_func* _this) {
}

int main(int argc, char** argv) {
    sjv_a = (sjs_func*)malloc(sizeof(sjs_func));
    sjv_a->_refCount = 1;
    sjf_func_heap(sjv_a);
    sjt_parent1 = sjv_a;
    sjt_parent1->_refCount++;
    sjf_func_bar_heap(sjt_parent1, &sjv_b);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjt_parent1->_refCount--;
    if (sjt_parent1->_refCount <= 0) {
        weakptr_release(sjt_parent1);
        sjf_func_destroy(sjt_parent1);
        free(sjt_parent1);
    }
    sjv_a->_refCount--;
    if (sjv_a->_refCount <= 0) {
        weakptr_release(sjv_a);
        sjf_func_destroy(sjv_a);
        free(sjv_a);
    }
    sjv_b->_refCount--;
    if (sjv_b->_refCount <= 0) {
        weakptr_release(sjv_b);
        sjf_func_destroy(sjv_b);
        free(sjv_b);
    }
}
