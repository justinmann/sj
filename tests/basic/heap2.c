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
#define sjs_class_anon1_typeId 3
#define sjs_class_typeId 4

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_class_anon1 sjs_class_anon1;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_class_anon1 {
    int _refCount;
    int32_t x;
};

struct td_sjs_class {
    int _refCount;
    sjs_class_anon1 data;
};

sjs_class* sjt_parent1 = 0;
sjs_class sjv_c = { -1 };
sjs_class_anon1 sjv_d = { -1 };

void sjf_class(sjs_class* _this);
void sjf_class_anon1(sjs_class_anon1* _this, sjs_class* _parent);
void sjf_class_anon1_copy(sjs_class_anon1* _this, sjs_class_anon1* _from);
void sjf_class_anon1_destroy(sjs_class_anon1* _this);
void sjf_class_anon1_heap(sjs_class_anon1* _this, sjs_class* _parent);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_get(sjs_class* _parent, sjs_class_anon1* _return);
void sjf_class_get_heap(sjs_class* _parent, sjs_class_anon1** _return);
void sjf_class_heap(sjs_class* _this);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_anon1(sjs_class_anon1* _this, sjs_class* _parent) {
}

void sjf_class_anon1_copy(sjs_class_anon1* _this, sjs_class_anon1* _from) {
    _this->x = _from->x;
}

void sjf_class_anon1_destroy(sjs_class_anon1* _this) {
}

void sjf_class_anon1_heap(sjs_class_anon1* _this, sjs_class* _parent) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->data._refCount = 1;
    sjf_class_anon1_copy(&_this->data, &_from->data);
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_get(sjs_class* _parent, sjs_class_anon1* _return) {
    sjs_class_anon1* sjt_copy1 = 0;
    sjs_class* sjt_dot1 = 0;

    sjt_dot1 = _parent;
    sjt_copy1 = &(sjt_dot1)->data;
    _return->_refCount = 1;
    sjf_class_anon1_copy(_return, sjt_copy1);
}

void sjf_class_get_heap(sjs_class* _parent, sjs_class_anon1** _return) {
    sjs_class_anon1* sjt_copy2 = 0;
    sjs_class* sjt_dot2 = 0;

    sjt_dot2 = _parent;
    sjt_copy2 = &(sjt_dot2)->data;
    (*_return) = (sjs_class_anon1*)malloc(sizeof(sjs_class_anon1));
    (*_return)->_refCount = 1;
    sjf_class_anon1_copy((*_return), sjt_copy2);
}

void sjf_class_heap(sjs_class* _this) {
}

int main(int argc, char** argv) {
    sjv_c._refCount = 1;
    sjv_c.data._refCount = 1;
    sjv_c.data.x = 0;
    sjf_class_anon1(&sjv_c.data, &sjv_c);
    sjf_class(&sjv_c);
    sjt_parent1 = &sjv_c;
    sjf_class_get(sjt_parent1, &sjv_d);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
    if (sjv_d._refCount == 1) { sjf_class_anon1_destroy(&sjv_d); }
}
