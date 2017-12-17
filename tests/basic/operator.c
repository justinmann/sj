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
#define sjs_fancymath_typeId 2
#define sjs_fancymath_heap_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_fancymath sjs_fancymath;
typedef struct td_sjs_fancymath_heap sjs_fancymath_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_fancymath {
    int32_t x;
};

struct td_sjs_fancymath_heap {
    intptr_t _refCount;
    int32_t x;
};

sjs_fancymath* sjt_functionParam1;
int32_t sjt_functionParam10;
int32_t sjt_functionParam11;
sjs_fancymath* sjt_functionParam2;
sjs_fancymath* sjt_functionParam3;
sjs_fancymath* sjt_functionParam4;
sjs_fancymath* sjt_functionParam5;
sjs_fancymath* sjt_functionParam6;
sjs_fancymath* sjt_functionParam7;
sjs_fancymath* sjt_functionParam8;
sjs_fancymath* sjt_functionParam9;
sjs_fancymath* sjt_parent12;
sjs_fancymath* sjt_parent15;
sjs_fancymath* sjt_parent16;
sjs_fancymath* sjt_parent17;
sjs_fancymath* sjt_parent18;
sjs_fancymath* sjt_parent19;
sjs_fancymath* sjt_parent20;
sjs_fancymath* sjt_parent21;
sjs_fancymath* sjt_parent22;
sjs_fancymath* sjt_parent23;
sjs_fancymath* sjt_parent24;
sjs_fancymath* sjt_parent3;
sjs_fancymath* sjt_parent6;
sjs_fancymath* sjt_parent9;
sjs_fancymath sjv_a;
sjs_fancymath sjv_b;
sjs_fancymath sjv_c;
sjs_fancymath sjv_d;
sjs_fancymath sjv_e;
sjs_fancymath sjv_f;
sjs_fancymath sjv_g;
int32_t sjv_i;
int32_t sjv_ii;
int32_t sjv_j;
sjs_fancymath sjv_k;

void sjf_fancymath(sjs_fancymath* _this);
void sjf_fancymath_add(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_add_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath_heap** _return);
void sjf_fancymath_copy(sjs_fancymath* _this, sjs_fancymath* _from);
void sjf_fancymath_destroy(sjs_fancymath* _this);
void sjf_fancymath_divide(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_divide_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath_heap** _return);
void sjf_fancymath_dividei32(sjs_fancymath* _parent, int32_t num, sjs_fancymath* _return);
void sjf_fancymath_dividei32_heap(sjs_fancymath* _parent, int32_t num, sjs_fancymath_heap** _return);
void sjf_fancymath_getx(sjs_fancymath* _parent, int32_t* _return);
void sjf_fancymath_heap(sjs_fancymath_heap* _this);
void sjf_fancymath_increment(sjs_fancymath* _parent, sjs_fancymath* _return);
void sjf_fancymath_increment_heap(sjs_fancymath* _parent, sjs_fancymath_heap** _return);
void sjf_fancymath_modulus(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_modulus_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath_heap** _return);
void sjf_fancymath_multiply(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_multiply_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath_heap** _return);
void sjf_fancymath_setbob(sjs_fancymath* _parent, int32_t i, int32_t* _return);
void sjf_fancymath_subtract(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_subtract_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath_heap** _return);
void main_destroy(void);

void sjf_fancymath(sjs_fancymath* _this) {
}

void sjf_fancymath_add(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot1;
    int32_t sjt_math1;
    int32_t sjt_math2;
    int32_t sjt_math3;
    int32_t sjt_math4;
    sjs_fancymath* sjt_parent1;

#line 4 "operator.sj"
    sjt_dot1 = _parent;
#line 5
    sjt_math3 = (sjt_dot1)->x;
#line 4
    sjt_parent1 = num;
#line 4
    sjf_fancymath_getx(sjt_parent1, &sjt_math4);
#line 5
    sjt_math1 = sjt_math3 + sjt_math4;
#line 5
    sjt_math2 = 1;
#line 5
    _return->x = sjt_math1 + sjt_math2;
#line 5
    sjf_fancymath(_return);
}

void sjf_fancymath_add_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath_heap** _return) {
    sjs_fancymath* sjt_dot3;
    int32_t sjt_math5;
    int32_t sjt_math6;
    int32_t sjt_math7;
    int32_t sjt_math8;
    sjs_fancymath* sjt_parent2;

    (*_return) = (sjs_fancymath_heap*)malloc(sizeof(sjs_fancymath_heap));
    (*_return)->_refCount = 1;
#line 4 "operator.sj"
    sjt_dot3 = _parent;
#line 5
    sjt_math7 = (sjt_dot3)->x;
#line 4
    sjt_parent2 = num;
#line 4
    sjf_fancymath_getx(sjt_parent2, &sjt_math8);
#line 5
    sjt_math5 = sjt_math7 + sjt_math8;
#line 5
    sjt_math6 = 1;
#line 5
    (*_return)->x = sjt_math5 + sjt_math6;
#line 5
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_copy(sjs_fancymath* _this, sjs_fancymath* _from) {
#line 1 "operator.sj"
    _this->x = _from->x;
}

void sjf_fancymath_destroy(sjs_fancymath* _this) {
}

void sjf_fancymath_divide(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot8;
    int32_t sjt_math25;
    int32_t sjt_math26;
    int32_t sjt_math27;
    int32_t sjt_math28;
    sjs_fancymath* sjt_parent10;

#line 16 "operator.sj"
    sjt_dot8 = _parent;
#line 17
    sjt_math27 = (sjt_dot8)->x;
#line 16
    sjt_parent10 = num;
#line 16
    sjf_fancymath_getx(sjt_parent10, &sjt_math28);
#line 17
    sjt_math25 = sjt_math27 / sjt_math28;
#line 17
    sjt_math26 = 1;
#line 17
    _return->x = sjt_math25 + sjt_math26;
#line 17
    sjf_fancymath(_return);
}

void sjf_fancymath_divide_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath_heap** _return) {
    sjs_fancymath* sjt_dot9;
    int32_t sjt_math29;
    int32_t sjt_math30;
    int32_t sjt_math31;
    int32_t sjt_math32;
    sjs_fancymath* sjt_parent11;

    (*_return) = (sjs_fancymath_heap*)malloc(sizeof(sjs_fancymath_heap));
    (*_return)->_refCount = 1;
#line 16 "operator.sj"
    sjt_dot9 = _parent;
#line 17
    sjt_math31 = (sjt_dot9)->x;
#line 16
    sjt_parent11 = num;
#line 16
    sjf_fancymath_getx(sjt_parent11, &sjt_math32);
#line 17
    sjt_math29 = sjt_math31 / sjt_math32;
#line 17
    sjt_math30 = 1;
#line 17
    (*_return)->x = sjt_math29 + sjt_math30;
#line 17
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_dividei32(sjs_fancymath* _parent, int32_t num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot15;
    int32_t sjt_math45;
    int32_t sjt_math46;
    int32_t sjt_math47;
    int32_t sjt_math48;

#line 20 "operator.sj"
    sjt_dot15 = _parent;
#line 21
    sjt_math47 = (sjt_dot15)->x;
#line 20
    sjt_math48 = num;
#line 21
    sjt_math45 = sjt_math47 / sjt_math48;
#line 21
    sjt_math46 = 1;
#line 21
    _return->x = sjt_math45 + sjt_math46;
#line 21
    sjf_fancymath(_return);
}

void sjf_fancymath_dividei32_heap(sjs_fancymath* _parent, int32_t num, sjs_fancymath_heap** _return) {
    sjs_fancymath* sjt_dot16;
    int32_t sjt_math49;
    int32_t sjt_math50;
    int32_t sjt_math51;
    int32_t sjt_math52;

    (*_return) = (sjs_fancymath_heap*)malloc(sizeof(sjs_fancymath_heap));
    (*_return)->_refCount = 1;
#line 20 "operator.sj"
    sjt_dot16 = _parent;
#line 21
    sjt_math51 = (sjt_dot16)->x;
#line 20
    sjt_math52 = num;
#line 21
    sjt_math49 = sjt_math51 / sjt_math52;
#line 21
    sjt_math50 = 1;
#line 21
    (*_return)->x = sjt_math49 + sjt_math50;
#line 21
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_getx(sjs_fancymath* _parent, int32_t* _return) {
    sjs_fancymath* sjt_dot2;

#line 36 "operator.sj"
    sjt_dot2 = _parent;
#line 36
    (*_return) = (sjt_dot2)->x;
}

void sjf_fancymath_heap(sjs_fancymath_heap* _this) {
}

void sjf_fancymath_increment(sjs_fancymath* _parent, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot12;
    int32_t sjt_math41;
    int32_t sjt_math42;

#line 28 "operator.sj"
    sjt_dot12 = _parent;
#line 29
    sjt_math41 = (sjt_dot12)->x;
#line 29
    sjt_math42 = 1;
#line 29
    _return->x = sjt_math41 + sjt_math42;
#line 29
    sjf_fancymath(_return);
}

void sjf_fancymath_increment_heap(sjs_fancymath* _parent, sjs_fancymath_heap** _return) {
    sjs_fancymath* sjt_dot13;
    int32_t sjt_math43;
    int32_t sjt_math44;

    (*_return) = (sjs_fancymath_heap*)malloc(sizeof(sjs_fancymath_heap));
    (*_return)->_refCount = 1;
#line 28 "operator.sj"
    sjt_dot13 = _parent;
#line 29
    sjt_math43 = (sjt_dot13)->x;
#line 29
    sjt_math44 = 1;
#line 29
    (*_return)->x = sjt_math43 + sjt_math44;
#line 29
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_modulus(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot10;
    int32_t sjt_math33;
    int32_t sjt_math34;
    int32_t sjt_math35;
    int32_t sjt_math36;
    sjs_fancymath* sjt_parent13;

#line 24 "operator.sj"
    sjt_dot10 = _parent;
#line 25
    sjt_math35 = (sjt_dot10)->x;
#line 24
    sjt_parent13 = num;
#line 24
    sjf_fancymath_getx(sjt_parent13, &sjt_math36);
#line 25
    sjt_math33 = sjt_math35 % sjt_math36;
#line 25
    sjt_math34 = 1;
#line 25
    _return->x = sjt_math33 + sjt_math34;
#line 25
    sjf_fancymath(_return);
}

void sjf_fancymath_modulus_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath_heap** _return) {
    sjs_fancymath* sjt_dot11;
    int32_t sjt_math37;
    int32_t sjt_math38;
    int32_t sjt_math39;
    int32_t sjt_math40;
    sjs_fancymath* sjt_parent14;

    (*_return) = (sjs_fancymath_heap*)malloc(sizeof(sjs_fancymath_heap));
    (*_return)->_refCount = 1;
#line 24 "operator.sj"
    sjt_dot11 = _parent;
#line 25
    sjt_math39 = (sjt_dot11)->x;
#line 24
    sjt_parent14 = num;
#line 24
    sjf_fancymath_getx(sjt_parent14, &sjt_math40);
#line 25
    sjt_math37 = sjt_math39 % sjt_math40;
#line 25
    sjt_math38 = 1;
#line 25
    (*_return)->x = sjt_math37 + sjt_math38;
#line 25
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_multiply(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot6;
    int32_t sjt_math17;
    int32_t sjt_math18;
    int32_t sjt_math19;
    int32_t sjt_math20;
    sjs_fancymath* sjt_parent7;

#line 12 "operator.sj"
    sjt_dot6 = _parent;
#line 13
    sjt_math19 = (sjt_dot6)->x;
#line 12
    sjt_parent7 = num;
#line 12
    sjf_fancymath_getx(sjt_parent7, &sjt_math20);
#line 13
    sjt_math17 = sjt_math19 * sjt_math20;
#line 13
    sjt_math18 = 1;
#line 13
    _return->x = sjt_math17 + sjt_math18;
#line 13
    sjf_fancymath(_return);
}

void sjf_fancymath_multiply_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath_heap** _return) {
    sjs_fancymath* sjt_dot7;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjt_math23;
    int32_t sjt_math24;
    sjs_fancymath* sjt_parent8;

    (*_return) = (sjs_fancymath_heap*)malloc(sizeof(sjs_fancymath_heap));
    (*_return)->_refCount = 1;
#line 12 "operator.sj"
    sjt_dot7 = _parent;
#line 13
    sjt_math23 = (sjt_dot7)->x;
#line 12
    sjt_parent8 = num;
#line 12
    sjf_fancymath_getx(sjt_parent8, &sjt_math24);
#line 13
    sjt_math21 = sjt_math23 * sjt_math24;
#line 13
    sjt_math22 = 1;
#line 13
    (*_return)->x = sjt_math21 + sjt_math22;
#line 13
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_setbob(sjs_fancymath* _parent, int32_t i, int32_t* _return) {
    sjs_fancymath* sjt_dot14;

#line 40 "operator.sj"
    sjt_dot14 = _parent;
#line 40
    sjt_dot14->x = i;
#line 41
    (*_return) = sjt_dot14->x;
}

void sjf_fancymath_subtract(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot4;
    int32_t sjt_math10;
    int32_t sjt_math11;
    int32_t sjt_math12;
    int32_t sjt_math9;
    sjs_fancymath* sjt_parent4;

#line 8 "operator.sj"
    sjt_dot4 = _parent;
#line 9
    sjt_math11 = (sjt_dot4)->x;
#line 8
    sjt_parent4 = num;
#line 8
    sjf_fancymath_getx(sjt_parent4, &sjt_math12);
#line 9
    sjt_math9 = sjt_math11 - sjt_math12;
#line 9
    sjt_math10 = 1;
#line 9
    _return->x = sjt_math9 + sjt_math10;
#line 9
    sjf_fancymath(_return);
}

void sjf_fancymath_subtract_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath_heap** _return) {
    sjs_fancymath* sjt_dot5;
    int32_t sjt_math13;
    int32_t sjt_math14;
    int32_t sjt_math15;
    int32_t sjt_math16;
    sjs_fancymath* sjt_parent5;

    (*_return) = (sjs_fancymath_heap*)malloc(sizeof(sjs_fancymath_heap));
    (*_return)->_refCount = 1;
#line 8 "operator.sj"
    sjt_dot5 = _parent;
#line 9
    sjt_math15 = (sjt_dot5)->x;
#line 8
    sjt_parent5 = num;
#line 8
    sjf_fancymath_getx(sjt_parent5, &sjt_math16);
#line 9
    sjt_math13 = sjt_math15 - sjt_math16;
#line 9
    sjt_math14 = 1;
#line 9
    (*_return)->x = sjt_math13 + sjt_math14;
#line 9
    sjf_fancymath_heap((*_return));
}

int main(int argc, char** argv) {
#line 45 "operator.sj"
    sjv_a.x = 1;
#line 45
    sjf_fancymath(&sjv_a);
#line 46
    sjv_b.x = 2;
#line 46
    sjf_fancymath(&sjv_b);
#line 47
    sjv_ii = 2;
#line 4
    sjt_parent3 = &sjv_a;
#line 48
    sjt_functionParam1 = &sjv_b;
#line 48
    sjf_fancymath_add(sjt_parent3, sjt_functionParam1, &sjv_c);
#line 8
    sjt_parent6 = &sjv_a;
#line 49
    sjt_functionParam2 = &sjv_b;
#line 49
    sjf_fancymath_subtract(sjt_parent6, sjt_functionParam2, &sjv_d);
#line 12
    sjt_parent9 = &sjv_a;
#line 50
    sjt_functionParam3 = &sjv_b;
#line 50
    sjf_fancymath_multiply(sjt_parent9, sjt_functionParam3, &sjv_e);
#line 16
    sjt_parent12 = &sjv_a;
#line 51
    sjt_functionParam4 = &sjv_b;
#line 51
    sjf_fancymath_divide(sjt_parent12, sjt_functionParam4, &sjv_f);
#line 24
    sjt_parent15 = &sjv_a;
#line 52
    sjt_functionParam5 = &sjv_b;
#line 52
    sjf_fancymath_modulus(sjt_parent15, sjt_functionParam5, &sjv_g);
#line 4
    sjt_parent16 = &sjv_c;
#line 53
    sjt_functionParam6 = &sjv_c;
#line 53
    sjf_fancymath_add(sjt_parent16, sjt_functionParam6, &sjv_c);
#line 8
    sjt_parent17 = &sjv_d;
#line 54
    sjt_functionParam7 = &sjv_d;
#line 54
    sjf_fancymath_subtract(sjt_parent17, sjt_functionParam7, &sjv_d);
#line 12
    sjt_parent18 = &sjv_d;
#line 55
    sjt_functionParam8 = &sjv_d;
#line 55
    sjf_fancymath_multiply(sjt_parent18, sjt_functionParam8, &sjv_d);
#line 16
    sjt_parent19 = &sjv_d;
#line 56
    sjt_functionParam9 = &sjv_d;
#line 56
    sjf_fancymath_divide(sjt_parent19, sjt_functionParam9, &sjv_d);
#line 28
    sjt_parent20 = &sjv_e;
#line 28
    sjf_fancymath_increment(sjt_parent20, &sjv_e);
#line 28
    sjt_parent21 = &sjv_f;
#line 28
    sjf_fancymath_increment(sjt_parent21, &sjv_f);
#line 36
    sjt_parent22 = &sjv_f;
#line 36
    sjf_fancymath_getx(sjt_parent22, &sjv_i);
#line 40
    sjt_parent23 = &sjv_a;
#line 60
    sjt_functionParam10 = 12;
#line 60
    sjf_fancymath_setbob(sjt_parent23, sjt_functionParam10, &sjv_j);
#line 20
    sjt_parent24 = &sjv_a;
#line 61
    sjt_functionParam11 = sjv_ii;
#line 61
    sjf_fancymath_dividei32(sjt_parent24, sjt_functionParam11, &sjv_k);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_fancymath_destroy(&sjv_a);
    sjf_fancymath_destroy(&sjv_b);
    sjf_fancymath_destroy(&sjv_c);
    sjf_fancymath_destroy(&sjv_d);
    sjf_fancymath_destroy(&sjv_e);
    sjf_fancymath_destroy(&sjv_f);
    sjf_fancymath_destroy(&sjv_g);
    sjf_fancymath_destroy(&sjv_k);
}
