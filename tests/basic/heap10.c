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
#define sjs_inner_typeId 2
#define sjs_class_typeId 3
#define sjs_class2_typeId 4

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_inner sjs_inner;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class2 sjs_class2;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_inner {
    int _refCount;
};

struct td_sjs_class {
    int _refCount;
    sjs_inner inner;
};

struct td_sjs_class2 {
    int _refCount;
    sjs_inner inner;
};

sjs_class* sjt_value1;
sjs_class2* sjt_value2;
sjs_class sjv_x1;
sjs_class* sjv_x2;
sjs_class* sjv_x4;
sjs_class2 sjv_x5;
sjs_class2* sjv_x6;
sjs_class2* sjv_x8;

void sjf_class(sjs_class* _this);
void sjf_class2(sjs_class2* _this);
void sjf_class2_copy(sjs_class2* _this, sjs_class2* _from);
void sjf_class2_destroy(sjs_class2* _this);
void sjf_class2_heap(sjs_class2* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_inner(sjs_inner* _this);
void sjf_inner_copy(sjs_inner* _this, sjs_inner* _from);
void sjf_inner_destroy(sjs_inner* _this);
void sjf_inner_heap(sjs_inner* _this);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class2(sjs_class2* _this) {
}

void sjf_class2_copy(sjs_class2* _this, sjs_class2* _from) {
    sjf_inner_copy((_this->inner._refCount != -1 ? &_this->inner : 0), (_from->inner._refCount != -1 ? &_from->inner : 0));
}

void sjf_class2_destroy(sjs_class2* _this) {
}

void sjf_class2_heap(sjs_class2* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    sjf_inner_copy(&_this->inner, &_from->inner);
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_inner(sjs_inner* _this) {
}

void sjf_inner_copy(sjs_inner* _this, sjs_inner* _from) {
}

void sjf_inner_destroy(sjs_inner* _this) {
}

void sjf_inner_heap(sjs_inner* _this) {
}

int main(int argc, char** argv) {
    sjf_inner(&sjv_x1.inner);
    sjf_class(&sjv_x1);
    sjv_x2 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_x2->_refCount = 1;
    sjf_inner(&sjv_x2->inner);
    sjf_class_heap(sjv_x2);
    sjt_value1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjt_value1->_refCount = 1;
    sjf_inner(&sjt_value1->inner);
    sjf_class_heap(sjt_value1);
    sjv_x4 = sjt_value1;
    if (sjv_x4 != 0) {
        sjv_x4->_refCount++;
    }

    sjv_x5.inner._refCount = 1;
    sjf_inner(&sjv_x5.inner);
    sjf_class2(&sjv_x5);
    sjv_x6 = (sjs_class2*)malloc(sizeof(sjs_class2));
    sjv_x6->_refCount = 1;
    sjv_x6->inner._refCount = 1;
    sjf_inner(&sjv_x6->inner);
    sjf_class2_heap(sjv_x6);
    sjt_value2 = (sjs_class2*)malloc(sizeof(sjs_class2));
    sjt_value2->_refCount = 1;
    sjt_value2->inner._refCount = 1;
    sjf_inner(&sjt_value2->inner);
    sjf_class2_heap(sjt_value2);
    sjv_x8 = sjt_value2;
    if (sjv_x8 != 0) {
        sjv_x8->_refCount++;
    }
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjt_value1->_refCount--;
    if (sjt_value1->_refCount <= 0) {
        sjf_class_destroy(sjt_value1);
    }
    sjt_value2->_refCount--;
    if (sjt_value2->_refCount <= 0) {
        sjf_class2_destroy(sjt_value2);
    }
    sjv_x2->_refCount--;
    if (sjv_x2->_refCount <= 0) {
        sjf_class_destroy(sjv_x2);
    }
    if (sjv_x4 != 0) {
        sjv_x4->_refCount--;
        if (sjv_x4->_refCount <= 0) {
            sjf_class_destroy(sjv_x4);
        }
    }
    sjv_x6->_refCount--;
    if (sjv_x6->_refCount <= 0) {
        sjf_class2_destroy(sjv_x6);
    }
    if (sjv_x8 != 0) {
        sjv_x8->_refCount--;
        if (sjv_x8->_refCount <= 0) {
            sjf_class2_destroy(sjv_x8);
        }
    }
    sjf_class_destroy(&sjv_x1);
    sjf_class2_destroy(&sjv_x5);
}
