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
#define sjs_class_typeId 2

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

int32_t sjt_functionParam1;
sjs_class* sjt_functionParam2 = 0;
sjs_class* sjv_c = 0;
int32_t void1;
int32_t void2;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_class_tostring(sjs_class* x, int32_t* _return);
void sjf_i32_tostring(int32_t x, int32_t* _return);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_tostring(sjs_class* x, int32_t* _return) {
    (*_return) = 2;
}

void sjf_i32_tostring(int32_t x, int32_t* _return) {
    (*_return) = 1;
}

int main(int argc, char** argv) {
    sjt_functionParam1 = 3;
    sjf_i32_tostring(sjt_functionParam1, &void1);
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->x = 3;
    sjf_class_heap(sjv_c);
    sjt_functionParam2 = sjv_c;
    sjf_class_tostring(sjt_functionParam2, &void2);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
    }
}
