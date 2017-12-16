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
#define sjs_class_heap_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_class {
    int32_t x;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
    int32_t x;
};

int32_t sjt_functionParam1;
sjs_class* sjt_functionParam2;
sjs_class_heap* sjv_c;
int32_t void1;
int32_t void2;

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_class_tostring(sjs_class* x, int32_t* _return);
void sjf_i32_tostring(int32_t x, int32_t* _return);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 7 "helper.sj"
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_class_tostring(sjs_class* x, int32_t* _return) {
#line 10 "helper.sj"
    (*_return) = 2;
}

void sjf_i32_tostring(int32_t x, int32_t* _return) {
#line 4 "helper.sj"
    (*_return) = 1;
}

int main(int argc, char** argv) {
#line 14 "helper.sj"
    sjt_functionParam1 = 3;
#line 14
    sjf_i32_tostring(sjt_functionParam1, &void1);
#line 14
    sjv_c = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
#line 14
    sjv_c->_refCount = 1;
#line 15
    sjv_c->x = 3;
#line 15
    sjf_class_heap(sjv_c);
#line 16
    sjt_functionParam2 = (sjs_class*)(((char*)sjv_c) + sizeof(intptr_t));
#line 16
    sjf_class_tostring(sjt_functionParam2, &void2);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjv_c) + sizeof(intptr_t)));
    }
}
