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
#define sjs_inner_typeId 2
#define sjs_inner_heap_typeId 3
#define sjs_class_typeId 4
#define sjs_class_heap_typeId 5
#define sjs_class2_typeId 6
#define sjs_class2_heap_typeId 7

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_inner sjs_inner;
typedef struct td_sjs_inner_heap sjs_inner_heap;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;
typedef struct td_sjs_class2 sjs_class2;
typedef struct td_sjs_class2_heap sjs_class2_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_inner {
    int structsNeedAValue;
};

struct td_sjs_inner_heap {
    intptr_t _refCount;
};

struct td_sjs_class {
    sjs_inner inner;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
    sjs_inner inner;
};

struct td_sjs_class2 {
    sjs_inner_heap* inner;
};

struct td_sjs_class2_heap {
    intptr_t _refCount;
    sjs_inner_heap* inner;
};

sjs_class_heap* sjt_value1;
sjs_inner_heap* sjt_value2;
sjs_inner_heap* sjt_value3;
sjs_class2_heap* sjt_value4;
sjs_inner_heap* sjt_value5;
sjs_class sjv_x1;
sjs_class_heap* sjv_x2;
sjs_class_heap* sjv_x4;
sjs_class2 sjv_x5;
sjs_class2_heap* sjv_x6;
sjs_class2_heap* sjv_x8;

void sjf_class(sjs_class* _this);
void sjf_class2(sjs_class2* _this);
void sjf_class2_copy(sjs_class2* _this, sjs_class2* to);
void sjf_class2_destroy(sjs_class2* _this);
void sjf_class2_heap(sjs_class2_heap* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_inner(sjs_inner* _this);
void sjf_inner_copy(sjs_inner* _this, sjs_inner* to);
void sjf_inner_destroy(sjs_inner* _this);
void sjf_inner_heap(sjs_inner_heap* _this);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class2(sjs_class2* _this) {
}

void sjf_class2_copy(sjs_class2* _this, sjs_class2* to) {
    _this->inner = 0;
    sjf_inner_copy((sjs_inner*)(((char*)_this->inner) + sizeof(intptr_t)), (sjs_inner*)(((char*)to->inner) + sizeof(intptr_t)));
}

void sjf_class2_destroy(sjs_class2* _this) {
    if (_this->inner != 0) {
        _this->inner->_refCount--;
        if (_this->inner->_refCount <= 0) {
            sjf_inner_destroy((sjs_inner*)(((char*)_this->inner) + sizeof(intptr_t)));
        }
    }
}

void sjf_class2_heap(sjs_class2_heap* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* to) {
    sjf_inner_copy(&_this->inner, &to->inner);
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_inner(sjs_inner* _this) {
}

void sjf_inner_copy(sjs_inner* _this, sjs_inner* to) {
}

void sjf_inner_destroy(sjs_inner* _this) {
}

void sjf_inner_heap(sjs_inner_heap* _this) {
}

int main() {
    sjf_inner(&sjv_x1.inner);
    sjf_class(&sjv_x1);
    sjv_x2 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjv_x2->_refCount = 1;
    sjf_inner(&sjv_x2->inner);
    sjf_class_heap(sjv_x2);
    sjt_value1 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjt_value1->_refCount = 1;
    sjf_inner(&sjt_value1->inner);
    sjf_class_heap(sjt_value1);
    sjv_x4 = sjt_value1;
    if (sjv_x4 != 0) {
        sjv_x4->_refCount++;
    }

    sjt_value2 = (sjs_inner_heap*)malloc(sizeof(sjs_inner_heap));
    sjt_value2->_refCount = 1;
    sjf_inner_heap(sjt_value2);
    sjv_x5.inner = sjt_value2;
    if (sjv_x5.inner != 0) {
        sjv_x5.inner->_refCount++;
    }

    sjf_class2(&sjv_x5);
    sjv_x6 = (sjs_class2_heap*)malloc(sizeof(sjs_class2_heap));
    sjv_x6->_refCount = 1;
    sjt_value3 = (sjs_inner_heap*)malloc(sizeof(sjs_inner_heap));
    sjt_value3->_refCount = 1;
    sjf_inner_heap(sjt_value3);
    sjv_x6->inner = sjt_value3;
    if (sjv_x6->inner != 0) {
        sjv_x6->inner->_refCount++;
    }

    sjf_class2_heap(sjv_x6);
    sjt_value4 = (sjs_class2_heap*)malloc(sizeof(sjs_class2_heap));
    sjt_value4->_refCount = 1;
    sjt_value5 = (sjs_inner_heap*)malloc(sizeof(sjs_inner_heap));
    sjt_value5->_refCount = 1;
    sjf_inner_heap(sjt_value5);
    sjt_value4->inner = sjt_value5;
    if (sjt_value4->inner != 0) {
        sjt_value4->inner->_refCount++;
    }

    sjf_class2_heap(sjt_value4);
    sjv_x8 = sjt_value4;
    if (sjv_x8 != 0) {
        sjv_x8->_refCount++;
    }
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_value1->_refCount--;
    if (sjt_value1->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjt_value1) + sizeof(intptr_t)));
    }
    sjt_value2->_refCount--;
    if (sjt_value2->_refCount <= 0) {
        sjf_inner_destroy((sjs_inner*)(((char*)sjt_value2) + sizeof(intptr_t)));
    }
    sjt_value3->_refCount--;
    if (sjt_value3->_refCount <= 0) {
        sjf_inner_destroy((sjs_inner*)(((char*)sjt_value3) + sizeof(intptr_t)));
    }
    sjt_value4->_refCount--;
    if (sjt_value4->_refCount <= 0) {
        sjf_class2_destroy((sjs_class2*)(((char*)sjt_value4) + sizeof(intptr_t)));
    }
    sjt_value5->_refCount--;
    if (sjt_value5->_refCount <= 0) {
        sjf_inner_destroy((sjs_inner*)(((char*)sjt_value5) + sizeof(intptr_t)));
    }
    sjv_x2->_refCount--;
    if (sjv_x2->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjv_x2) + sizeof(intptr_t)));
    }
    if (sjv_x4 != 0) {
        sjv_x4->_refCount--;
        if (sjv_x4->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjv_x4) + sizeof(intptr_t)));
        }
    }
    sjv_x6->_refCount--;
    if (sjv_x6->_refCount <= 0) {
        sjf_class2_destroy((sjs_class2*)(((char*)sjv_x6) + sizeof(intptr_t)));
    }
    if (sjv_x8 != 0) {
        sjv_x8->_refCount--;
        if (sjv_x8->_refCount <= 0) {
            sjf_class2_destroy((sjs_class2*)(((char*)sjv_x8) + sizeof(intptr_t)));
        }
    }
    sjf_class_destroy(&sjv_x1);
    sjf_class2_destroy(&sjv_x5);
}
