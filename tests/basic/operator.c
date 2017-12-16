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

typedef struct td_void_option void_option;
struct td_void_option {
    bool isEmpty;
    void* value;
};
const void_option void_empty = { true };

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
sjs_fancyMath* sjt_parent12;
sjs_fancyMath* sjt_parent15;
sjs_fancyMath* sjt_parent16;
sjs_fancyMath* sjt_parent17;
sjs_fancyMath* sjt_parent18;
sjs_fancyMath* sjt_parent19;
sjs_fancyMath* sjt_parent20;
sjs_fancyMath* sjt_parent21;
sjs_fancyMath* sjt_parent22;
sjs_fancyMath* sjt_parent23;
sjs_fancyMath* sjt_parent3;
sjs_fancyMath* sjt_parent6;
sjs_fancyMath* sjt_parent9;
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
    sjs_fancyMath* sjt_dot1;
    int32_t sjt_math1;
    int32_t sjt_math2;
    int32_t sjt_math3;
    int32_t sjt_math4;
    sjs_fancyMath* sjt_parent1;

#line 4 "operator.sj"
    sjt_dot1 = _parent;
#line 5
    sjt_math3 = (sjt_dot1)->x;
#line 4
    sjt_parent1 = num;
#line 4
    sjf_fancyMath_getX(sjt_parent1, &sjt_math4);
#line 5
    sjt_math1 = sjt_math3 + sjt_math4;
#line 5
    sjt_math2 = 1;
#line 5
    _return->x = sjt_math1 + sjt_math2;
#line 5
    sjf_fancyMath(_return);
}

void sjf_fancyMath_add_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return) {
    sjs_fancyMath* sjt_dot3;
    int32_t sjt_math5;
    int32_t sjt_math6;
    int32_t sjt_math7;
    int32_t sjt_math8;
    sjs_fancyMath* sjt_parent2;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
#line 4 "operator.sj"
    sjt_dot3 = _parent;
#line 5
    sjt_math7 = (sjt_dot3)->x;
#line 4
    sjt_parent2 = num;
#line 4
    sjf_fancyMath_getX(sjt_parent2, &sjt_math8);
#line 5
    sjt_math5 = sjt_math7 + sjt_math8;
#line 5
    sjt_math6 = 1;
#line 5
    (*_return)->x = sjt_math5 + sjt_math6;
#line 5
    sjf_fancyMath_heap((*_return));
}

void sjf_fancyMath_copy(sjs_fancyMath* _this, sjs_fancyMath* _from) {
#line 1 "operator.sj"
    _this->x = _from->x;
}

void sjf_fancyMath_destroy(sjs_fancyMath* _this) {
}

void sjf_fancyMath_divide(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return) {
    sjs_fancyMath* sjt_dot8;
    int32_t sjt_math25;
    int32_t sjt_math26;
    int32_t sjt_math27;
    int32_t sjt_math28;
    sjs_fancyMath* sjt_parent10;

#line 16 "operator.sj"
    sjt_dot8 = _parent;
#line 17
    sjt_math27 = (sjt_dot8)->x;
#line 16
    sjt_parent10 = num;
#line 16
    sjf_fancyMath_getX(sjt_parent10, &sjt_math28);
#line 17
    sjt_math25 = sjt_math27 / sjt_math28;
#line 17
    sjt_math26 = 1;
#line 17
    _return->x = sjt_math25 + sjt_math26;
#line 17
    sjf_fancyMath(_return);
}

void sjf_fancyMath_divide_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return) {
    sjs_fancyMath* sjt_dot9;
    int32_t sjt_math29;
    int32_t sjt_math30;
    int32_t sjt_math31;
    int32_t sjt_math32;
    sjs_fancyMath* sjt_parent11;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
#line 16 "operator.sj"
    sjt_dot9 = _parent;
#line 17
    sjt_math31 = (sjt_dot9)->x;
#line 16
    sjt_parent11 = num;
#line 16
    sjf_fancyMath_getX(sjt_parent11, &sjt_math32);
#line 17
    sjt_math29 = sjt_math31 / sjt_math32;
#line 17
    sjt_math30 = 1;
#line 17
    (*_return)->x = sjt_math29 + sjt_math30;
#line 17
    sjf_fancyMath_heap((*_return));
}

void sjf_fancyMath_getX(sjs_fancyMath* _parent, int32_t* _return) {
    sjs_fancyMath* sjt_dot2;

#line 32 "operator.sj"
    sjt_dot2 = _parent;
#line 32
    (*_return) = (sjt_dot2)->x;
}

void sjf_fancyMath_heap(sjs_fancyMath_heap* _this) {
}

void sjf_fancyMath_increment(sjs_fancyMath* _parent, sjs_fancyMath* _return) {
    sjs_fancyMath* sjt_dot12;
    int32_t sjt_math41;
    int32_t sjt_math42;

#line 24 "operator.sj"
    sjt_dot12 = _parent;
#line 25
    sjt_math41 = (sjt_dot12)->x;
#line 25
    sjt_math42 = 1;
#line 25
    _return->x = sjt_math41 + sjt_math42;
#line 25
    sjf_fancyMath(_return);
}

void sjf_fancyMath_increment_heap(sjs_fancyMath* _parent, sjs_fancyMath_heap** _return) {
    sjs_fancyMath* sjt_dot13;
    int32_t sjt_math43;
    int32_t sjt_math44;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
#line 24 "operator.sj"
    sjt_dot13 = _parent;
#line 25
    sjt_math43 = (sjt_dot13)->x;
#line 25
    sjt_math44 = 1;
#line 25
    (*_return)->x = sjt_math43 + sjt_math44;
#line 25
    sjf_fancyMath_heap((*_return));
}

void sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return) {
    sjs_fancyMath* sjt_dot10;
    int32_t sjt_math33;
    int32_t sjt_math34;
    int32_t sjt_math35;
    int32_t sjt_math36;
    sjs_fancyMath* sjt_parent13;

#line 20 "operator.sj"
    sjt_dot10 = _parent;
#line 21
    sjt_math35 = (sjt_dot10)->x;
#line 20
    sjt_parent13 = num;
#line 20
    sjf_fancyMath_getX(sjt_parent13, &sjt_math36);
#line 21
    sjt_math33 = sjt_math35 % sjt_math36;
#line 21
    sjt_math34 = 1;
#line 21
    _return->x = sjt_math33 + sjt_math34;
#line 21
    sjf_fancyMath(_return);
}

void sjf_fancyMath_modulus_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return) {
    sjs_fancyMath* sjt_dot11;
    int32_t sjt_math37;
    int32_t sjt_math38;
    int32_t sjt_math39;
    int32_t sjt_math40;
    sjs_fancyMath* sjt_parent14;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
#line 20 "operator.sj"
    sjt_dot11 = _parent;
#line 21
    sjt_math39 = (sjt_dot11)->x;
#line 20
    sjt_parent14 = num;
#line 20
    sjf_fancyMath_getX(sjt_parent14, &sjt_math40);
#line 21
    sjt_math37 = sjt_math39 % sjt_math40;
#line 21
    sjt_math38 = 1;
#line 21
    (*_return)->x = sjt_math37 + sjt_math38;
#line 21
    sjf_fancyMath_heap((*_return));
}

void sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return) {
    sjs_fancyMath* sjt_dot6;
    int32_t sjt_math17;
    int32_t sjt_math18;
    int32_t sjt_math19;
    int32_t sjt_math20;
    sjs_fancyMath* sjt_parent7;

#line 12 "operator.sj"
    sjt_dot6 = _parent;
#line 13
    sjt_math19 = (sjt_dot6)->x;
#line 12
    sjt_parent7 = num;
#line 12
    sjf_fancyMath_getX(sjt_parent7, &sjt_math20);
#line 13
    sjt_math17 = sjt_math19 * sjt_math20;
#line 13
    sjt_math18 = 1;
#line 13
    _return->x = sjt_math17 + sjt_math18;
#line 13
    sjf_fancyMath(_return);
}

void sjf_fancyMath_multiply_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return) {
    sjs_fancyMath* sjt_dot7;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjt_math23;
    int32_t sjt_math24;
    sjs_fancyMath* sjt_parent8;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
#line 12 "operator.sj"
    sjt_dot7 = _parent;
#line 13
    sjt_math23 = (sjt_dot7)->x;
#line 12
    sjt_parent8 = num;
#line 12
    sjf_fancyMath_getX(sjt_parent8, &sjt_math24);
#line 13
    sjt_math21 = sjt_math23 * sjt_math24;
#line 13
    sjt_math22 = 1;
#line 13
    (*_return)->x = sjt_math21 + sjt_math22;
#line 13
    sjf_fancyMath_heap((*_return));
}

void sjf_fancyMath_setBob(sjs_fancyMath* _parent, int32_t i, int32_t* _return) {
    sjs_fancyMath* sjt_dot14;

#line 36 "operator.sj"
    sjt_dot14 = _parent;
#line 36
    sjt_dot14->x = i;
#line 37
    (*_return) = sjt_dot14->x;
}

void sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath* _return) {
    sjs_fancyMath* sjt_dot4;
    int32_t sjt_math10;
    int32_t sjt_math11;
    int32_t sjt_math12;
    int32_t sjt_math9;
    sjs_fancyMath* sjt_parent4;

#line 8 "operator.sj"
    sjt_dot4 = _parent;
#line 9
    sjt_math11 = (sjt_dot4)->x;
#line 8
    sjt_parent4 = num;
#line 8
    sjf_fancyMath_getX(sjt_parent4, &sjt_math12);
#line 9
    sjt_math9 = sjt_math11 - sjt_math12;
#line 9
    sjt_math10 = 1;
#line 9
    _return->x = sjt_math9 + sjt_math10;
#line 9
    sjf_fancyMath(_return);
}

void sjf_fancyMath_subtract_heap(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath_heap** _return) {
    sjs_fancyMath* sjt_dot5;
    int32_t sjt_math13;
    int32_t sjt_math14;
    int32_t sjt_math15;
    int32_t sjt_math16;
    sjs_fancyMath* sjt_parent5;

    (*_return) = (sjs_fancyMath_heap*)malloc(sizeof(sjs_fancyMath_heap));
    (*_return)->_refCount = 1;
#line 8 "operator.sj"
    sjt_dot5 = _parent;
#line 9
    sjt_math15 = (sjt_dot5)->x;
#line 8
    sjt_parent5 = num;
#line 8
    sjf_fancyMath_getX(sjt_parent5, &sjt_math16);
#line 9
    sjt_math13 = sjt_math15 - sjt_math16;
#line 9
    sjt_math14 = 1;
#line 9
    (*_return)->x = sjt_math13 + sjt_math14;
#line 9
    sjf_fancyMath_heap((*_return));
}

int main(int argc, char** argv) {
#line 41 "operator.sj"
    sjv_a.x = 1;
#line 41
    sjf_fancyMath(&sjv_a);
#line 42
    sjv_b.x = 2;
#line 42
    sjf_fancyMath(&sjv_b);
#line 4
    sjt_parent3 = &sjv_a;
#line 43
    sjt_functionParam1 = &sjv_b;
#line 43
    sjf_fancyMath_add(sjt_parent3, sjt_functionParam1, &sjv_c);
#line 8
    sjt_parent6 = &sjv_a;
#line 44
    sjt_functionParam2 = &sjv_b;
#line 44
    sjf_fancyMath_subtract(sjt_parent6, sjt_functionParam2, &sjv_d);
#line 12
    sjt_parent9 = &sjv_a;
#line 45
    sjt_functionParam3 = &sjv_b;
#line 45
    sjf_fancyMath_multiply(sjt_parent9, sjt_functionParam3, &sjv_e);
#line 16
    sjt_parent12 = &sjv_a;
#line 46
    sjt_functionParam4 = &sjv_b;
#line 46
    sjf_fancyMath_divide(sjt_parent12, sjt_functionParam4, &sjv_f);
#line 20
    sjt_parent15 = &sjv_a;
#line 47
    sjt_functionParam5 = &sjv_b;
#line 47
    sjf_fancyMath_modulus(sjt_parent15, sjt_functionParam5, &sjv_g);
#line 4
    sjt_parent16 = &sjv_c;
#line 48
    sjt_functionParam6 = &sjv_c;
#line 48
    sjf_fancyMath_add(sjt_parent16, sjt_functionParam6, &sjv_c);
#line 8
    sjt_parent17 = &sjv_d;
#line 49
    sjt_functionParam7 = &sjv_d;
#line 49
    sjf_fancyMath_subtract(sjt_parent17, sjt_functionParam7, &sjv_d);
#line 12
    sjt_parent18 = &sjv_d;
#line 50
    sjt_functionParam8 = &sjv_d;
#line 50
    sjf_fancyMath_multiply(sjt_parent18, sjt_functionParam8, &sjv_d);
#line 16
    sjt_parent19 = &sjv_d;
#line 51
    sjt_functionParam9 = &sjv_d;
#line 51
    sjf_fancyMath_divide(sjt_parent19, sjt_functionParam9, &sjv_d);
#line 24
    sjt_parent20 = &sjv_e;
#line 24
    sjf_fancyMath_increment(sjt_parent20, &sjv_e);
#line 24
    sjt_parent21 = &sjv_f;
#line 24
    sjf_fancyMath_increment(sjt_parent21, &sjv_f);
#line 32
    sjt_parent22 = &sjv_f;
#line 32
    sjf_fancyMath_getX(sjt_parent22, &sjv_i);
#line 36
    sjt_parent23 = &sjv_a;
#line 55
    sjt_functionParam10 = 12;
#line 55
    sjf_fancyMath_setBob(sjt_parent23, sjt_functionParam10, &sjv_j);
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
