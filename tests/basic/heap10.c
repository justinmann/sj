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
#define sjs_class_typeId 3
#define sjs_class_heap_typeId 4
#define sjs_class2_typeId 5
#define sjs_inner_heap_typeId 6
#define sjs_class2_heap_typeId 7

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_inner sjs_inner;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;
typedef struct td_sjs_class2 sjs_class2;
typedef struct td_sjs_inner_heap sjs_inner_heap;
typedef struct td_sjs_class2_heap sjs_class2_heap;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_inner {
    int structsNeedAValue;
};

struct td_sjs_class {
    sjs_inner inner;
};

struct td_sjs_class_heap {
    int _refCount;
    sjs_inner inner;
};

struct td_sjs_class2 {
    sjs_inner_heap* inner;
};

struct td_sjs_inner_heap {
    int _refCount;
};

struct td_sjs_class2_heap {
    int _refCount;
    sjs_inner_heap* inner;
};

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


void sjf_class(sjs_class* _this) {
}

void sjf_class2(sjs_class2* _this) {
}

void sjf_class2_copy(sjs_class2* _this, sjs_class2* to) {
    _this->inner = 0;
    sjf_inner_copy((sjs_inner*)(((char*)_this->inner) + sizeof(int)), (sjs_inner*)(((char*)to->inner) + sizeof(int)));
}

void sjf_class2_destroy(sjs_class2* _this) {
    if (_this->inner != 0) {
        _this->inner->_refCount--;
        if (_this->inner->_refCount <= 0) {
            sjf_inner_destroy((sjs_inner*)(((char*)_this->inner) + sizeof(int)));
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
    sjs_class_heap* temp1;
    sjs_inner_heap* temp2;
    sjs_inner_heap* temp3;
    sjs_class2_heap* temp4;
    sjs_inner_heap* temp5;
    sjs_class x1;
    sjs_class_heap* x2;
    sjs_class_heap* x4;
    sjs_class2 x5;
    sjs_class2_heap* x6;
    sjs_class2_heap* x8;

    sjf_inner(&x1.inner);
    sjf_class(&x1);
    x2 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    x2->_refCount = 1;
    sjf_inner(&x2->inner);
    sjf_class_heap(x2);
    temp1 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    temp1->_refCount = 1;
    sjf_inner(&temp1->inner);
    sjf_class_heap(temp1);
    x4 = temp1;
    if (x4 != 0) {
        x4->_refCount++;
    }

    temp2 = (sjs_inner_heap*)malloc(sizeof(sjs_inner_heap));
    temp2->_refCount = 1;
    sjf_inner_heap(temp2);
    x5.inner = temp2;
    if (x5.inner != 0) {
        x5.inner->_refCount++;
    }

    sjf_class2(&x5);
    x6 = (sjs_class2_heap*)malloc(sizeof(sjs_class2_heap));
    x6->_refCount = 1;
    temp3 = (sjs_inner_heap*)malloc(sizeof(sjs_inner_heap));
    temp3->_refCount = 1;
    sjf_inner_heap(temp3);
    x6->inner = temp3;
    if (x6->inner != 0) {
        x6->inner->_refCount++;
    }

    sjf_class2_heap(x6);
    temp4 = (sjs_class2_heap*)malloc(sizeof(sjs_class2_heap));
    temp4->_refCount = 1;
    temp5 = (sjs_inner_heap*)malloc(sizeof(sjs_inner_heap));
    temp5->_refCount = 1;
    sjf_inner_heap(temp5);
    temp4->inner = temp5;
    if (temp4->inner != 0) {
        temp4->inner->_refCount++;
    }

    sjf_class2_heap(temp4);
    x8 = temp4;
    if (x8 != 0) {
        x8->_refCount++;
    }

    temp1->_refCount--;
    if (temp1->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)temp1) + sizeof(int)));
    }
    temp2->_refCount--;
    if (temp2->_refCount <= 0) {
        sjf_inner_destroy((sjs_inner*)(((char*)temp2) + sizeof(int)));
    }
    temp3->_refCount--;
    if (temp3->_refCount <= 0) {
        sjf_inner_destroy((sjs_inner*)(((char*)temp3) + sizeof(int)));
    }
    temp4->_refCount--;
    if (temp4->_refCount <= 0) {
        sjf_class2_destroy((sjs_class2*)(((char*)temp4) + sizeof(int)));
    }
    temp5->_refCount--;
    if (temp5->_refCount <= 0) {
        sjf_inner_destroy((sjs_inner*)(((char*)temp5) + sizeof(int)));
    }
    x2->_refCount--;
    if (x2->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)x2) + sizeof(int)));
    }
    if (x4 != 0) {
        x4->_refCount--;
        if (x4->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)x4) + sizeof(int)));
        }
    }
    x6->_refCount--;
    if (x6->_refCount <= 0) {
        sjf_class2_destroy((sjs_class2*)(((char*)x6) + sizeof(int)));
    }
    if (x8 != 0) {
        x8->_refCount--;
        if (x8->_refCount <= 0) {
            sjf_class2_destroy((sjs_class2*)(((char*)x8) + sizeof(int)));
        }
    }
    sjf_class_destroy(&x1);
    sjf_class2_destroy(&x5);
    return 0;
}