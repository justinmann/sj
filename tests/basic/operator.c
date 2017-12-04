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
#define sjs_fancyMath_typeId 2
#define sjs_fancyMath_heap_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_fancyMath sjs_fancyMath;
typedef struct td_sjs_fancyMath_heap sjs_fancyMath_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_fancyMath {
    int32_t x;
};

struct td_sjs_fancyMath_heap {
    intptr_t _refCount;
    int32_t x;
};

sjs_fancyMath* sjt_dot1;
sjs_fancyMath* sjt_dot10;
sjs_fancyMath* sjt_dot13;
sjs_fancyMath* sjt_dot16;
sjs_fancyMath* sjt_dot17;
sjs_fancyMath* sjt_dot18;
sjs_fancyMath* sjt_dot19;
sjs_fancyMath* sjt_dot20;
sjs_fancyMath* sjt_dot21;
sjs_fancyMath* sjt_dot22;
sjs_fancyMath* sjt_dot23;
sjs_fancyMath* sjt_dot4;
sjs_fancyMath* sjt_dot7;
sjs_fancyMath* sjt_functionParam1;
int32_t sjt_functionParam10;
sjs_fancyMath* sjt_functionParam2;
sjs_fancyMath* sjt_functionParam3;
sjs_fancyMath* sjt_functionParam4;
sjs_fancyMath* sjt_functionParam5;
sjs_fancyMath* sjt_functionParam6;
sjs_fancyMath* sjt_functionParam7;
sjs_fancyMath* sjt_functionParam8;
sjs_fancyMath* sjt_functionParam9;
sjs_fancyMath sjv_a;
sjs_fancyMath sjv_b;
sjs_fancyMath sjv_c;
sjs_fancyMath sjv_d;
sjs_fancyMath sjv_e;
sjs_fancyMath sjv_f;
sjs_fancyMath sjv_g;
int32_t sjv_i;
int32_t sjv_j;

void sjf_fancyMath(sjs_fancyMath* _this);
void sjf_fancyMath_add(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return);
void sjf_fancyMath_add_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return);
void sjf_fancyMath_copy(sjs_fancyMath* _this, sjs_fancyMath* _from);
void sjf_fancyMath_destroy(sjs_fancyMath* _this);
void sjf_fancyMath_divide(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return);
void sjf_fancyMath_divide_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return);
void sjf_fancyMath_getX(sjs_fancyMath* _parent, int32_t* _return);
void sjf_fancyMath_heap(sjs_fancyMath_heap* _this);
void sjf_fancyMath_increment(sjs_fancyMath* _parent, sjs_fancyMath* _return);
void sjf_fancyMath_increment_heap(sjs_fancyMath* _parent, sjs_fancyMath_heap** _return);
void sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return);
void sjf_fancyMath_modulus_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return);
void sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return);
void sjf_fancyMath_multiply_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return);
void sjf_fancyMath_setBob(sjs_fancyMath* _parent, int32_t i, int32_t* _return);
void sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return);
void sjf_fancyMath_subtract_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return);
void main_destroy(void);

void sjf_fancyMath(sjs_fancyMath* _this) {
}

void sjf_fancyMath_add(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return) {
    sjs_fancyMath* sjt_dot2;
    int32_t sjt_math1;
    int32_t sjt_math2;
    int32_t sjt_math3;
    int32_t sjt_math4;

    sjt_math3 = (_parent)->x;
    sjt_dot2 = num;
    sjf_fancyMath_getX(sjt_dot2, &sjt_math4);
    sjt_math1 = sjt_math3 + sjt_math4;
    sjt_math2 = 1;
    _return->x = sjt_math1 + sjt_math2;
    sjf_fancyMath(_return);
}

void sjf_fancyMath_add_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return) {
    sjs_fancyMath* sjt_dot3;
    int32_t sjt_math5;
    int32_t sjt_math6;
    int32_t sjt_math7;
    int32_t sjt_math8;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
    sjt_math7 = (_parent)->x;
    sjt_dot3 = num;
    sjf_fancyMath_getX(sjt_dot3, &sjt_math8);
    sjt_math5 = sjt_math7 + sjt_math8;
    sjt_math6 = 1;
    (*_return)->x = sjt_math5 + sjt_math6;
    sjf_fancyMath_heap((*_return));
}

void sjf_fancyMath_copy(sjs_fancyMath* _this, sjs_fancyMath* _from) {
    _this->x = _from->x;
}

void sjf_fancyMath_destroy(sjs_fancyMath* _this) {
}

void sjf_fancyMath_divide(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return) {
    sjs_fancyMath* sjt_dot11;
    int32_t sjt_math25;
    int32_t sjt_math26;
    int32_t sjt_math27;
    int32_t sjt_math28;

    sjt_math27 = (_parent)->x;
    sjt_dot11 = num;
    sjf_fancyMath_getX(sjt_dot11, &sjt_math28);
    sjt_math25 = sjt_math27 / sjt_math28;
    sjt_math26 = 1;
    _return->x = sjt_math25 + sjt_math26;
    sjf_fancyMath(_return);
}

void sjf_fancyMath_divide_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return) {
    sjs_fancyMath* sjt_dot12;
    int32_t sjt_math29;
    int32_t sjt_math30;
    int32_t sjt_math31;
    int32_t sjt_math32;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
    sjt_math31 = (_parent)->x;
    sjt_dot12 = num;
    sjf_fancyMath_getX(sjt_dot12, &sjt_math32);
    sjt_math29 = sjt_math31 / sjt_math32;
    sjt_math30 = 1;
    (*_return)->x = sjt_math29 + sjt_math30;
    sjf_fancyMath_heap((*_return));
}

void sjf_fancyMath_getX(sjs_fancyMath* _parent, int32_t* _return) {
    (*_return) = (_parent)->x;
}

void sjf_fancyMath_heap(sjs_fancyMath_heap* _this) {
}

void sjf_fancyMath_increment(sjs_fancyMath* _parent, sjs_fancyMath* _return) {
    int32_t sjt_math41;
    int32_t sjt_math42;

    sjt_math41 = (_parent)->x;
    sjt_math42 = 1;
    _return->x = sjt_math41 + sjt_math42;
    sjf_fancyMath(_return);
}

void sjf_fancyMath_increment_heap(sjs_fancyMath* _parent, sjs_fancyMath_heap** _return) {
    int32_t sjt_math43;
    int32_t sjt_math44;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
    sjt_math43 = (_parent)->x;
    sjt_math44 = 1;
    (*_return)->x = sjt_math43 + sjt_math44;
    sjf_fancyMath_heap((*_return));
}

void sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return) {
    sjs_fancyMath* sjt_dot14;
    int32_t sjt_math33;
    int32_t sjt_math34;
    int32_t sjt_math35;
    int32_t sjt_math36;

    sjt_math35 = (_parent)->x;
    sjt_dot14 = num;
    sjf_fancyMath_getX(sjt_dot14, &sjt_math36);
    sjt_math33 = sjt_math35 % sjt_math36;
    sjt_math34 = 1;
    _return->x = sjt_math33 + sjt_math34;
    sjf_fancyMath(_return);
}

void sjf_fancyMath_modulus_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return) {
    sjs_fancyMath* sjt_dot15;
    int32_t sjt_math37;
    int32_t sjt_math38;
    int32_t sjt_math39;
    int32_t sjt_math40;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
    sjt_math39 = (_parent)->x;
    sjt_dot15 = num;
    sjf_fancyMath_getX(sjt_dot15, &sjt_math40);
    sjt_math37 = sjt_math39 % sjt_math40;
    sjt_math38 = 1;
    (*_return)->x = sjt_math37 + sjt_math38;
    sjf_fancyMath_heap((*_return));
}

void sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return) {
    sjs_fancyMath* sjt_dot8;
    int32_t sjt_math17;
    int32_t sjt_math18;
    int32_t sjt_math19;
    int32_t sjt_math20;

    sjt_math19 = (_parent)->x;
    sjt_dot8 = num;
    sjf_fancyMath_getX(sjt_dot8, &sjt_math20);
    sjt_math17 = sjt_math19 * sjt_math20;
    sjt_math18 = 1;
    _return->x = sjt_math17 + sjt_math18;
    sjf_fancyMath(_return);
}

void sjf_fancyMath_multiply_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return) {
    sjs_fancyMath* sjt_dot9;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjt_math23;
    int32_t sjt_math24;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
    sjt_math23 = (_parent)->x;
    sjt_dot9 = num;
    sjf_fancyMath_getX(sjt_dot9, &sjt_math24);
    sjt_math21 = sjt_math23 * sjt_math24;
    sjt_math22 = 1;
    (*_return)->x = sjt_math21 + sjt_math22;
    sjf_fancyMath_heap((*_return));
}

void sjf_fancyMath_setBob(sjs_fancyMath* _parent, int32_t i, int32_t* _return) {
    _parent->x = i;
    (*_return) = _parent->x;
}

void sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return) {
    sjs_fancyMath* sjt_dot5;
    int32_t sjt_math10;
    int32_t sjt_math11;
    int32_t sjt_math12;
    int32_t sjt_math9;

    sjt_math11 = (_parent)->x;
    sjt_dot5 = num;
    sjf_fancyMath_getX(sjt_dot5, &sjt_math12);
    sjt_math9 = sjt_math11 - sjt_math12;
    sjt_math10 = 1;
    _return->x = sjt_math9 + sjt_math10;
    sjf_fancyMath(_return);
}

void sjf_fancyMath_subtract_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return) {
    sjs_fancyMath* sjt_dot6;
    int32_t sjt_math13;
    int32_t sjt_math14;
    int32_t sjt_math15;
    int32_t sjt_math16;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
    sjt_math15 = (_parent)->x;
    sjt_dot6 = num;
    sjf_fancyMath_getX(sjt_dot6, &sjt_math16);
    sjt_math13 = sjt_math15 - sjt_math16;
    sjt_math14 = 1;
    (*_return)->x = sjt_math13 + sjt_math14;
    sjf_fancyMath_heap((*_return));
}

int main(int argc, char** argv) {
    sjv_a.x = 1;
    sjf_fancyMath(&sjv_a);
    sjv_b.x = 2;
    sjf_fancyMath(&sjv_b);
    sjt_dot1 = &sjv_a;
    sjt_functionParam1 = &sjv_b;
    sjf_fancyMath_add(sjt_dot1, sjt_functionParam1, &sjv_c);
    sjt_dot4 = &sjv_a;
    sjt_functionParam2 = &sjv_b;
    sjf_fancyMath_subtract(sjt_dot4, sjt_functionParam2, &sjv_d);
    sjt_dot7 = &sjv_a;
    sjt_functionParam3 = &sjv_b;
    sjf_fancyMath_multiply(sjt_dot7, sjt_functionParam3, &sjv_e);
    sjt_dot10 = &sjv_a;
    sjt_functionParam4 = &sjv_b;
    sjf_fancyMath_divide(sjt_dot10, sjt_functionParam4, &sjv_f);
    sjt_dot13 = &sjv_a;
    sjt_functionParam5 = &sjv_b;
    sjf_fancyMath_modulus(sjt_dot13, sjt_functionParam5, &sjv_g);
    sjt_dot16 = &sjv_c;
    sjt_functionParam6 = &sjv_c;
    sjf_fancyMath_add(sjt_dot16, sjt_functionParam6, &sjv_c);
    sjt_dot17 = &sjv_d;
    sjt_functionParam7 = &sjv_d;
    sjf_fancyMath_subtract(sjt_dot17, sjt_functionParam7, &sjv_d);
    sjt_dot18 = &sjv_d;
    sjt_functionParam8 = &sjv_d;
    sjf_fancyMath_multiply(sjt_dot18, sjt_functionParam8, &sjv_d);
    sjt_dot19 = &sjv_d;
    sjt_functionParam9 = &sjv_d;
    sjf_fancyMath_divide(sjt_dot19, sjt_functionParam9, &sjv_d);
    sjt_dot20 = &sjv_e;
    sjf_fancyMath_increment(sjt_dot20, &sjv_e);
    sjt_dot21 = &sjv_f;
    sjf_fancyMath_increment(sjt_dot21, &sjv_f);
    sjt_dot22 = &sjv_f;
    sjf_fancyMath_getX(sjt_dot22, &sjv_i);
    sjt_dot23 = &sjv_a;
    sjt_functionParam10 = 12;
    sjf_fancyMath_setBob(sjt_dot23, sjt_functionParam10, &sjv_j);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_fancyMath_destroy(&sjv_a);
    sjf_fancyMath_destroy(&sjv_b);
    sjf_fancyMath_destroy(&sjv_c);
    sjf_fancyMath_destroy(&sjv_d);
    sjf_fancyMath_destroy(&sjv_e);
    sjf_fancyMath_destroy(&sjv_f);
    sjf_fancyMath_destroy(&sjv_g);
}
