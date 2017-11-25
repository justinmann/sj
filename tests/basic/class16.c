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
#define sjs_a_aa_typeId 2
#define sjs_a_aa_heap_typeId 3
#define sjs_a_typeId 4
#define sjs_a_heap_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_a_aa sjs_a_aa;
typedef struct td_sjs_a_aa_heap sjs_a_aa_heap;
typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_a_heap sjs_a_heap;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_a_aa {
    sjs_a* _parent;
};

struct td_sjs_a_aa_heap {
    int _refCount;
    sjs_a* _parent;
};

struct td_sjs_a {
    int32_t x;
    sjs_a_aa b;
};

struct td_sjs_a_heap {
    int _refCount;
    int32_t x;
    sjs_a_aa b;
};

void sjf_a(sjs_a* _this);
void sjf_a_aa(sjs_a_aa* _this);
void sjf_a_aa_c(sjs_a_aa* _parent, int32_t* _return);
void sjf_a_aa_copy(sjs_a_aa* _this, sjs_a_aa* to);
void sjf_a_aa_destroy(sjs_a_aa* _this);
void sjf_a_aa_heap(sjs_a_aa_heap* _this);
void sjf_a_copy(sjs_a* _this, sjs_a* to);
void sjf_a_destroy(sjs_a* _this);
void sjf_a_heap(sjs_a_heap* _this);


void sjf_a(sjs_a* _this) {
}

void sjf_a_aa(sjs_a_aa* _this) {
}

void sjf_a_aa_c(sjs_a_aa* _parent, int32_t* _return) {
    int32_t dotTemp2;
    sjs_a* tempParent1;

    tempParent1 = _parent->_parent;
    dotTemp2 = tempParent1->x;
    (*_return) = dotTemp2;
}

void sjf_a_aa_copy(sjs_a_aa* _this, sjs_a_aa* to) {
}

void sjf_a_aa_destroy(sjs_a_aa* _this) {
}

void sjf_a_aa_heap(sjs_a_aa_heap* _this) {
}

void sjf_a_copy(sjs_a* _this, sjs_a* to) {
    _this->x = to->x;
    sjf_a_aa_copy(&_this->b, &to->b);
}

void sjf_a_destroy(sjs_a* _this) {
}

void sjf_a_heap(sjs_a_heap* _this) {
}

int main() {
    sjs_a a;
    sjs_a_aa d;
    sjs_a_aa dotTemp1;
    sjs_a_aa dotTemp3;
    sjs_a_aa* sjt_dot1;
    sjs_a* sjt_dot2;
    sjs_a* sjt_dot3;
    sjs_a_aa* sjt_dot4;
    int32_t void1;
    int32_t void2;

    a.x = 1;
    a.b._parent = a._parent;
    sjf_a_aa(&a.b);
    sjf_a(&a);
    sjt_dot2 = &a;
    dotTemp1 = sjt_dot2->b;
    sjt_dot1 = &dotTemp1;
    sjf_a_aa_c(sjt_dot1, &void1);
    sjt_dot3 = &a;
    dotTemp3 = sjt_dot3->b;
    sjf_a_aa_copy(&d, &dotTemp3);
    sjt_dot4 = &d;
    sjf_a_aa_c(sjt_dot4, &void2);

    sjf_a_destroy(&a);
    sjf_a_aa_destroy(&d);
    sjf_a_aa_destroy(&dotTemp1);
    sjf_a_aa_destroy(&dotTemp3);
    return 0;
}
