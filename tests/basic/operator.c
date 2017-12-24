#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_fancymath_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_fancymath sjs_fancymath;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_fancymath {
    int _refCount;
    int32_t x;
};

sjs_fancymath* sjt_functionParam1 = 0;
int32_t sjt_functionParam10;
int32_t sjt_functionParam11;
sjs_fancymath* sjt_functionParam2 = 0;
sjs_fancymath* sjt_functionParam3 = 0;
sjs_fancymath* sjt_functionParam4 = 0;
sjs_fancymath* sjt_functionParam5 = 0;
sjs_fancymath* sjt_functionParam6 = 0;
sjs_fancymath* sjt_functionParam7 = 0;
sjs_fancymath* sjt_functionParam8 = 0;
sjs_fancymath* sjt_functionParam9 = 0;
sjs_fancymath* sjt_parent12 = 0;
sjs_fancymath* sjt_parent15 = 0;
sjs_fancymath* sjt_parent16 = 0;
sjs_fancymath* sjt_parent17 = 0;
sjs_fancymath* sjt_parent18 = 0;
sjs_fancymath* sjt_parent19 = 0;
sjs_fancymath* sjt_parent20 = 0;
sjs_fancymath* sjt_parent21 = 0;
sjs_fancymath* sjt_parent22 = 0;
sjs_fancymath* sjt_parent23 = 0;
sjs_fancymath* sjt_parent24 = 0;
sjs_fancymath* sjt_parent3 = 0;
sjs_fancymath* sjt_parent6 = 0;
sjs_fancymath* sjt_parent9 = 0;
sjs_fancymath sjv_a = { -1 };
sjs_fancymath sjv_b = { -1 };
sjs_fancymath sjv_c = { -1 };
sjs_fancymath sjv_d = { -1 };
sjs_fancymath sjv_e = { -1 };
sjs_fancymath sjv_f = { -1 };
sjs_fancymath sjv_g = { -1 };
int32_t sjv_i;
int32_t sjv_ii;
int32_t sjv_j;
sjs_fancymath sjv_k = { -1 };

void sjf_fancymath(sjs_fancymath* _this);
void sjf_fancymath_add(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_add_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_copy(sjs_fancymath* _this, sjs_fancymath* _from);
void sjf_fancymath_destroy(sjs_fancymath* _this);
void sjf_fancymath_divide(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_divide_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_dividei32(sjs_fancymath* _parent, int32_t num, sjs_fancymath* _return);
void sjf_fancymath_dividei32_heap(sjs_fancymath* _parent, int32_t num, sjs_fancymath** _return);
void sjf_fancymath_getx(sjs_fancymath* _parent, int32_t* _return);
void sjf_fancymath_heap(sjs_fancymath* _this);
void sjf_fancymath_increment(sjs_fancymath* _parent, sjs_fancymath* _return);
void sjf_fancymath_increment_heap(sjs_fancymath* _parent, sjs_fancymath** _return);
void sjf_fancymath_modulus(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_modulus_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_multiply(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_multiply_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void sjf_fancymath_setbob(sjs_fancymath* _parent, int32_t i, int32_t* _return);
void sjf_fancymath_subtract(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return);
void sjf_fancymath_subtract_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return);
void main_destroy(void);

void sjf_fancymath(sjs_fancymath* _this) {
}

void sjf_fancymath_add(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot1 = 0;
    int32_t sjt_math1;
    int32_t sjt_math2;
    int32_t sjt_math3;
    int32_t sjt_math4;
    sjs_fancymath* sjt_parent1 = 0;

    _return->_refCount = 1;
    sjt_dot1 = _parent;
    sjt_math3 = (sjt_dot1)->x;
    sjt_parent1 = num;
    sjf_fancymath_getx(sjt_parent1, &sjt_math4);
    sjt_math1 = sjt_math3 + sjt_math4;
    sjt_math2 = 1;
    _return->x = sjt_math1 + sjt_math2;
    sjf_fancymath(_return);
}

void sjf_fancymath_add_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot3 = 0;
    int32_t sjt_math5;
    int32_t sjt_math6;
    int32_t sjt_math7;
    int32_t sjt_math8;
    sjs_fancymath* sjt_parent2 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot3 = _parent;
    sjt_math7 = (sjt_dot3)->x;
    sjt_parent2 = num;
    sjf_fancymath_getx(sjt_parent2, &sjt_math8);
    sjt_math5 = sjt_math7 + sjt_math8;
    sjt_math6 = 1;
    (*_return)->x = sjt_math5 + sjt_math6;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_copy(sjs_fancymath* _this, sjs_fancymath* _from) {
    _this->x = _from->x;
}

void sjf_fancymath_destroy(sjs_fancymath* _this) {
}

void sjf_fancymath_divide(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot8 = 0;
    int32_t sjt_math25;
    int32_t sjt_math26;
    int32_t sjt_math27;
    int32_t sjt_math28;
    sjs_fancymath* sjt_parent10 = 0;

    _return->_refCount = 1;
    sjt_dot8 = _parent;
    sjt_math27 = (sjt_dot8)->x;
    sjt_parent10 = num;
    sjf_fancymath_getx(sjt_parent10, &sjt_math28);
    sjt_math25 = sjt_math27 / sjt_math28;
    sjt_math26 = 1;
    _return->x = sjt_math25 + sjt_math26;
    sjf_fancymath(_return);
}

void sjf_fancymath_divide_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot9 = 0;
    int32_t sjt_math29;
    int32_t sjt_math30;
    int32_t sjt_math31;
    int32_t sjt_math32;
    sjs_fancymath* sjt_parent11 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot9 = _parent;
    sjt_math31 = (sjt_dot9)->x;
    sjt_parent11 = num;
    sjf_fancymath_getx(sjt_parent11, &sjt_math32);
    sjt_math29 = sjt_math31 / sjt_math32;
    sjt_math30 = 1;
    (*_return)->x = sjt_math29 + sjt_math30;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_dividei32(sjs_fancymath* _parent, int32_t num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot15 = 0;
    int32_t sjt_math45;
    int32_t sjt_math46;
    int32_t sjt_math47;
    int32_t sjt_math48;

    _return->_refCount = 1;
    sjt_dot15 = _parent;
    sjt_math47 = (sjt_dot15)->x;
    sjt_math48 = num;
    sjt_math45 = sjt_math47 / sjt_math48;
    sjt_math46 = 1;
    _return->x = sjt_math45 + sjt_math46;
    sjf_fancymath(_return);
}

void sjf_fancymath_dividei32_heap(sjs_fancymath* _parent, int32_t num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot16 = 0;
    int32_t sjt_math49;
    int32_t sjt_math50;
    int32_t sjt_math51;
    int32_t sjt_math52;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot16 = _parent;
    sjt_math51 = (sjt_dot16)->x;
    sjt_math52 = num;
    sjt_math49 = sjt_math51 / sjt_math52;
    sjt_math50 = 1;
    (*_return)->x = sjt_math49 + sjt_math50;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_getx(sjs_fancymath* _parent, int32_t* _return) {
    sjs_fancymath* sjt_dot2 = 0;

    sjt_dot2 = _parent;
    (*_return) = (sjt_dot2)->x;
}

void sjf_fancymath_heap(sjs_fancymath* _this) {
}

void sjf_fancymath_increment(sjs_fancymath* _parent, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot12 = 0;
    int32_t sjt_math41;
    int32_t sjt_math42;

    _return->_refCount = 1;
    sjt_dot12 = _parent;
    sjt_math41 = (sjt_dot12)->x;
    sjt_math42 = 1;
    _return->x = sjt_math41 + sjt_math42;
    sjf_fancymath(_return);
}

void sjf_fancymath_increment_heap(sjs_fancymath* _parent, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot13 = 0;
    int32_t sjt_math43;
    int32_t sjt_math44;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot13 = _parent;
    sjt_math43 = (sjt_dot13)->x;
    sjt_math44 = 1;
    (*_return)->x = sjt_math43 + sjt_math44;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_modulus(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot10 = 0;
    int32_t sjt_math33;
    int32_t sjt_math34;
    int32_t sjt_math35;
    int32_t sjt_math36;
    sjs_fancymath* sjt_parent13 = 0;

    _return->_refCount = 1;
    sjt_dot10 = _parent;
    sjt_math35 = (sjt_dot10)->x;
    sjt_parent13 = num;
    sjf_fancymath_getx(sjt_parent13, &sjt_math36);
    sjt_math33 = sjt_math35 % sjt_math36;
    sjt_math34 = 1;
    _return->x = sjt_math33 + sjt_math34;
    sjf_fancymath(_return);
}

void sjf_fancymath_modulus_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot11 = 0;
    int32_t sjt_math37;
    int32_t sjt_math38;
    int32_t sjt_math39;
    int32_t sjt_math40;
    sjs_fancymath* sjt_parent14 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot11 = _parent;
    sjt_math39 = (sjt_dot11)->x;
    sjt_parent14 = num;
    sjf_fancymath_getx(sjt_parent14, &sjt_math40);
    sjt_math37 = sjt_math39 % sjt_math40;
    sjt_math38 = 1;
    (*_return)->x = sjt_math37 + sjt_math38;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_multiply(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot6 = 0;
    int32_t sjt_math17;
    int32_t sjt_math18;
    int32_t sjt_math19;
    int32_t sjt_math20;
    sjs_fancymath* sjt_parent7 = 0;

    _return->_refCount = 1;
    sjt_dot6 = _parent;
    sjt_math19 = (sjt_dot6)->x;
    sjt_parent7 = num;
    sjf_fancymath_getx(sjt_parent7, &sjt_math20);
    sjt_math17 = sjt_math19 * sjt_math20;
    sjt_math18 = 1;
    _return->x = sjt_math17 + sjt_math18;
    sjf_fancymath(_return);
}

void sjf_fancymath_multiply_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot7 = 0;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjt_math23;
    int32_t sjt_math24;
    sjs_fancymath* sjt_parent8 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot7 = _parent;
    sjt_math23 = (sjt_dot7)->x;
    sjt_parent8 = num;
    sjf_fancymath_getx(sjt_parent8, &sjt_math24);
    sjt_math21 = sjt_math23 * sjt_math24;
    sjt_math22 = 1;
    (*_return)->x = sjt_math21 + sjt_math22;
    sjf_fancymath_heap((*_return));
}

void sjf_fancymath_setbob(sjs_fancymath* _parent, int32_t i, int32_t* _return) {
    sjs_fancymath* sjt_dot14 = 0;

    sjt_dot14 = _parent;
    sjt_dot14->x = i;
    (*_return) = sjt_dot14->x;
}

void sjf_fancymath_subtract(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath* _return) {
    sjs_fancymath* sjt_dot4 = 0;
    int32_t sjt_math10;
    int32_t sjt_math11;
    int32_t sjt_math12;
    int32_t sjt_math9;
    sjs_fancymath* sjt_parent4 = 0;

    _return->_refCount = 1;
    sjt_dot4 = _parent;
    sjt_math11 = (sjt_dot4)->x;
    sjt_parent4 = num;
    sjf_fancymath_getx(sjt_parent4, &sjt_math12);
    sjt_math9 = sjt_math11 - sjt_math12;
    sjt_math10 = 1;
    _return->x = sjt_math9 + sjt_math10;
    sjf_fancymath(_return);
}

void sjf_fancymath_subtract_heap(sjs_fancymath* _parent, sjs_fancymath* num, sjs_fancymath** _return) {
    sjs_fancymath* sjt_dot5 = 0;
    int32_t sjt_math13;
    int32_t sjt_math14;
    int32_t sjt_math15;
    int32_t sjt_math16;
    sjs_fancymath* sjt_parent5 = 0;

    (*_return) = (sjs_fancymath*)malloc(sizeof(sjs_fancymath));
    (*_return)->_refCount = 1;
    sjt_dot5 = _parent;
    sjt_math15 = (sjt_dot5)->x;
    sjt_parent5 = num;
    sjf_fancymath_getx(sjt_parent5, &sjt_math16);
    sjt_math13 = sjt_math15 - sjt_math16;
    sjt_math14 = 1;
    (*_return)->x = sjt_math13 + sjt_math14;
    sjf_fancymath_heap((*_return));
}

int main(int argc, char** argv) {
    sjv_a._refCount = 1;
    sjv_a.x = 1;
    sjf_fancymath(&sjv_a);
    sjv_b._refCount = 1;
    sjv_b.x = 2;
    sjf_fancymath(&sjv_b);
    sjv_ii = 2;
    sjt_parent3 = &sjv_a;
    sjt_functionParam1 = &sjv_b;
    sjf_fancymath_add(sjt_parent3, sjt_functionParam1, &sjv_c);
    sjt_parent6 = &sjv_a;
    sjt_functionParam2 = &sjv_b;
    sjf_fancymath_subtract(sjt_parent6, sjt_functionParam2, &sjv_d);
    sjt_parent9 = &sjv_a;
    sjt_functionParam3 = &sjv_b;
    sjf_fancymath_multiply(sjt_parent9, sjt_functionParam3, &sjv_e);
    sjt_parent12 = &sjv_a;
    sjt_functionParam4 = &sjv_b;
    sjf_fancymath_divide(sjt_parent12, sjt_functionParam4, &sjv_f);
    sjt_parent15 = &sjv_a;
    sjt_functionParam5 = &sjv_b;
    sjf_fancymath_modulus(sjt_parent15, sjt_functionParam5, &sjv_g);
    sjt_parent16 = &sjv_c;
    sjt_functionParam6 = &sjv_c;
    sjf_fancymath_add(sjt_parent16, sjt_functionParam6, &sjv_c);
    sjt_parent17 = &sjv_d;
    sjt_functionParam7 = &sjv_d;
    sjf_fancymath_subtract(sjt_parent17, sjt_functionParam7, &sjv_d);
    sjt_parent18 = &sjv_d;
    sjt_functionParam8 = &sjv_d;
    sjf_fancymath_multiply(sjt_parent18, sjt_functionParam8, &sjv_d);
    sjt_parent19 = &sjv_d;
    sjt_functionParam9 = &sjv_d;
    sjf_fancymath_divide(sjt_parent19, sjt_functionParam9, &sjv_d);
    sjt_parent20 = &sjv_e;
    sjf_fancymath_increment(sjt_parent20, &sjv_e);
    sjt_parent21 = &sjv_f;
    sjf_fancymath_increment(sjt_parent21, &sjv_f);
    sjt_parent22 = &sjv_f;
    sjf_fancymath_getx(sjt_parent22, &sjv_i);
    sjt_parent23 = &sjv_a;
    sjt_functionParam10 = 12;
    sjf_fancymath_setbob(sjt_parent23, sjt_functionParam10, &sjv_j);
    sjt_parent24 = &sjv_a;
    sjt_functionParam11 = sjv_ii;
    sjf_fancymath_dividei32(sjt_parent24, sjt_functionParam11, &sjv_k);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_a._refCount == 1) { sjf_fancymath_destroy(&sjv_a); }
    if (sjv_b._refCount == 1) { sjf_fancymath_destroy(&sjv_b); }
    if (sjv_c._refCount == 1) { sjf_fancymath_destroy(&sjv_c); }
    if (sjv_d._refCount == 1) { sjf_fancymath_destroy(&sjv_d); }
    if (sjv_e._refCount == 1) { sjf_fancymath_destroy(&sjv_e); }
    if (sjv_f._refCount == 1) { sjf_fancymath_destroy(&sjv_f); }
    if (sjv_g._refCount == 1) { sjf_fancymath_destroy(&sjv_g); }
    if (sjv_k._refCount == 1) { sjf_fancymath_destroy(&sjv_k); }
}
