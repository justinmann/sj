#include <assert.h>
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

#define sjs_fancyMath_typeId 1
#define sjs_object_typeId 2

typedef struct td_sjs_fancyMath sjs_fancyMath;
typedef struct td_sjs_object sjs_object;

struct td_sjs_fancyMath {
    int _refCount;
    int32_t x;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_fancyMath(sjs_fancyMath* _this, sjs_fancyMath** _return);
void sjf_fancyMath_add(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return);
void sjf_fancyMath_destroy(sjs_fancyMath* _this);
void sjf_fancyMath_divide(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return);
void sjf_fancyMath_getX(sjs_fancyMath* _parent, int32_t* _return);
void sjf_fancyMath_increment(sjs_fancyMath* _parent, sjs_fancyMath** _return);
void sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return);
void sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return);
void sjf_fancyMath_setBob(sjs_fancyMath* _parent, int32_t i, int32_t* _return);
void sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return);


void sjf_fancyMath(sjs_fancyMath* _this, sjs_fancyMath** _return) {
    _this->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath(sjs_fancyMath* _this, sjs_fancyMath** _return)\t%d\n", (uintptr_t)_this, _this->_refCount);;

    *_return = _this;
}

void sjf_fancyMath_add(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return) {
    int32_t dotTemp1;
    int32_t result2;
    int32_t result3;
    int32_t result4;
    sjs_fancyMath* sjv_temp3;

    sjv_temp3 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp3->_refCount = 1;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_add(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp3, sjv_temp3->_refCount);;
    dotTemp1 = _parent->x;
    result2 = 0;
    sjf_fancyMath_getX(num, &result2);
    result3 = dotTemp1 + result2;
    result4 = result3 + 1;
    sjv_temp3->x = result4;
    sjf_fancyMath(sjv_temp3, &sjv_temp3);
    sjv_temp3->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_add(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp3, sjv_temp3->_refCount);;

    sjv_temp3->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_add(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp3, sjv_temp3->_refCount);
    if (sjv_temp3->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp3);
        free(sjv_temp3);
    }

    *_return = sjv_temp3;
}

void sjf_fancyMath_destroy(sjs_fancyMath* _this) {
}

void sjf_fancyMath_divide(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return) {
    int32_t dotTemp5;
    int32_t result14;
    int32_t result15;
    int32_t result16;
    sjs_fancyMath* sjv_temp6;

    sjv_temp6 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp6->_refCount = 1;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_divide(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp6, sjv_temp6->_refCount);;
    dotTemp5 = _parent->x;
    result14 = 0;
    sjf_fancyMath_getX(num, &result14);
    result15 = dotTemp5 / result14;
    result16 = result15 + 1;
    sjv_temp6->x = result16;
    sjf_fancyMath(sjv_temp6, &sjv_temp6);
    sjv_temp6->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_divide(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp6, sjv_temp6->_refCount);;

    sjv_temp6->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_divide(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp6, sjv_temp6->_refCount);
    if (sjv_temp6->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp6);
        free(sjv_temp6);
    }

    *_return = sjv_temp6;
}

void sjf_fancyMath_getX(sjs_fancyMath* _parent, int32_t* _return) {
    int32_t dotTemp2;

    dotTemp2 = _parent->x;

    *_return = dotTemp2;
}

void sjf_fancyMath_increment(sjs_fancyMath* _parent, sjs_fancyMath** _return) {
    int32_t dotTemp7;
    int32_t result26;
    sjs_fancyMath* sjv_temp8;

    sjv_temp8 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp8->_refCount = 1;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_increment(sjs_fancyMath* _parent, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp8, sjv_temp8->_refCount);;
    dotTemp7 = _parent->x;
    result26 = dotTemp7 + 1;
    sjv_temp8->x = result26;
    sjf_fancyMath(sjv_temp8, &sjv_temp8);
    sjv_temp8->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_increment(sjs_fancyMath* _parent, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp8, sjv_temp8->_refCount);;

    sjv_temp8->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_increment(sjs_fancyMath* _parent, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp8, sjv_temp8->_refCount);
    if (sjv_temp8->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp8);
        free(sjv_temp8);
    }

    *_return = sjv_temp8;
}

void sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return) {
    int32_t dotTemp6;
    int32_t result18;
    int32_t result19;
    int32_t result20;
    sjs_fancyMath* sjv_temp7;

    sjv_temp7 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp7->_refCount = 1;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp7, sjv_temp7->_refCount);;
    dotTemp6 = _parent->x;
    result18 = 0;
    sjf_fancyMath_getX(num, &result18);
    result19 = dotTemp6 % result18;
    result20 = result19 + 1;
    sjv_temp7->x = result20;
    sjf_fancyMath(sjv_temp7, &sjv_temp7);
    sjv_temp7->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp7, sjv_temp7->_refCount);;

    sjv_temp7->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp7, sjv_temp7->_refCount);
    if (sjv_temp7->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp7);
        free(sjv_temp7);
    }

    *_return = sjv_temp7;
}

void sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return) {
    int32_t dotTemp4;
    int32_t result10;
    int32_t result11;
    int32_t result12;
    sjs_fancyMath* sjv_temp5;

    sjv_temp5 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp5->_refCount = 1;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp5, sjv_temp5->_refCount);;
    dotTemp4 = _parent->x;
    result10 = 0;
    sjf_fancyMath_getX(num, &result10);
    result11 = dotTemp4 * result10;
    result12 = result11 + 1;
    sjv_temp5->x = result12;
    sjf_fancyMath(sjv_temp5, &sjv_temp5);
    sjv_temp5->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp5, sjv_temp5->_refCount);;

    sjv_temp5->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp5, sjv_temp5->_refCount);
    if (sjv_temp5->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp5);
        free(sjv_temp5);
    }

    *_return = sjv_temp5;
}

void sjf_fancyMath_setBob(sjs_fancyMath* _parent, int32_t i, int32_t* _return) {
    _parent->x = i;

    *_return = i;
}

void sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return) {
    int32_t dotTemp3;
    int32_t result6;
    int32_t result7;
    int32_t result8;
    sjs_fancyMath* sjv_temp4;

    sjv_temp4 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp4->_refCount = 1;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp4, sjv_temp4->_refCount);;
    dotTemp3 = _parent->x;
    result6 = 0;
    sjf_fancyMath_getX(num, &result6);
    result7 = dotTemp3 - result6;
    result8 = result7 + 1;
    sjv_temp4->x = result8;
    sjf_fancyMath(sjv_temp4, &sjv_temp4);
    sjv_temp4->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp4, sjv_temp4->_refCount);;

    sjv_temp4->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return)\t%d\n", (uintptr_t)sjv_temp4, sjv_temp4->_refCount);
    if (sjv_temp4->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp4);
        free(sjv_temp4);
    }

    *_return = sjv_temp4;
}

int main() {
    sjs_fancyMath* a;
    sjs_fancyMath* b;
    sjs_fancyMath* c;
    sjs_fancyMath* d;
    sjs_fancyMath* e;
    sjs_fancyMath* f;
    sjs_fancyMath* g;
    int32_t i;
    int32_t j;
    sjs_fancyMath* result1;
    sjs_fancyMath* result13;
    sjs_fancyMath* result17;
    sjs_fancyMath* result21;
    sjs_fancyMath* result22;
    sjs_fancyMath* result23;
    sjs_fancyMath* result24;
    sjs_fancyMath* result25;
    sjs_fancyMath* result27;
    int32_t result28;
    int32_t result29;
    sjs_fancyMath* result5;
    sjs_fancyMath* result9;
    sjs_fancyMath* sjv_temp1;
    sjs_fancyMath* sjv_temp2;

    sjv_temp1 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp1->_refCount = 1;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)sjv_temp1, sjv_temp1->_refCount);;
    sjv_temp1->x = 1;
    sjf_fancyMath(sjv_temp1, &sjv_temp1);
    a = sjv_temp1;
    a->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)a, a->_refCount);;
    sjv_temp2 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp2->_refCount = 1;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)sjv_temp2, sjv_temp2->_refCount);;
    sjv_temp2->x = 2;
    sjf_fancyMath(sjv_temp2, &sjv_temp2);
    b = sjv_temp2;
    b->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)b, b->_refCount);;
    result1 = 0;
    sjf_fancyMath_add(a, b, &result1);
    c = result1;
    c->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)c, c->_refCount);;
    result5 = 0;
    sjf_fancyMath_subtract(a, b, &result5);
    d = result5;
    d->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)d, d->_refCount);;
    result9 = 0;
    sjf_fancyMath_multiply(a, b, &result9);
    e = result9;
    e->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)e, e->_refCount);;
    result13 = 0;
    sjf_fancyMath_divide(a, b, &result13);
    f = result13;
    f->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)f, f->_refCount);;
    result17 = 0;
    sjf_fancyMath_modulus(a, b, &result17);
    g = result17;
    g->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)g, g->_refCount);;
    result21 = 0;
    sjf_fancyMath_add(c, c, &result21);
    c->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)c, c->_refCount);;
    if (c->_refCount <= 0) {
        sjf_fancyMath_destroy(c);
        free(c);
    }

    c = result21;
    c->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)c, c->_refCount);;
    result22 = 0;
    sjf_fancyMath_subtract(d, d, &result22);
    d->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)d, d->_refCount);;
    if (d->_refCount <= 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }

    d = result22;
    d->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)d, d->_refCount);;
    result23 = 0;
    sjf_fancyMath_multiply(d, d, &result23);
    d->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)d, d->_refCount);;
    if (d->_refCount <= 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }

    d = result23;
    d->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)d, d->_refCount);;
    result24 = 0;
    sjf_fancyMath_divide(d, d, &result24);
    d->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)d, d->_refCount);;
    if (d->_refCount <= 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }

    d = result24;
    d->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)d, d->_refCount);;
    result25 = 0;
    sjf_fancyMath_increment(e, &result25);
    e->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)e, e->_refCount);;
    if (e->_refCount <= 0) {
        sjf_fancyMath_destroy(e);
        free(e);
    }

    e = result25;
    e->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)e, e->_refCount);;
    result27 = 0;
    sjf_fancyMath_increment(f, &result27);
    f->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)f, f->_refCount);;
    if (f->_refCount <= 0) {
        sjf_fancyMath_destroy(f);
        free(f);
    }

    f = result27;
    f->_refCount++;
    printf("RETAIN\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)f, f->_refCount);;
    result28 = 0;
    sjf_fancyMath_getX(f, &result28);
    i = result28;
    result29 = 0;
    sjf_fancyMath_setBob(a, 12, &result29);
    j = result29;

    a->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)a, a->_refCount);
    if (a->_refCount <= 0) {
        sjf_fancyMath_destroy(a);
        free(a);
    }
    b->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)b, b->_refCount);
    if (b->_refCount <= 0) {
        sjf_fancyMath_destroy(b);
        free(b);
    }
    c->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)c, c->_refCount);
    if (c->_refCount <= 0) {
        sjf_fancyMath_destroy(c);
        free(c);
    }
    d->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)d, d->_refCount);
    if (d->_refCount <= 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }
    e->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)e, e->_refCount);
    if (e->_refCount <= 0) {
        sjf_fancyMath_destroy(e);
        free(e);
    }
    f->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)f, f->_refCount);
    if (f->_refCount <= 0) {
        sjf_fancyMath_destroy(f);
        free(f);
    }
    g->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)g, g->_refCount);
    if (g->_refCount <= 0) {
        sjf_fancyMath_destroy(g);
        free(g);
    }
    result1->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result1, result1->_refCount);
    if (result1->_refCount <= 0) {
        sjf_fancyMath_destroy(result1);
        free(result1);
    }
    result13->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result13, result13->_refCount);
    if (result13->_refCount <= 0) {
        sjf_fancyMath_destroy(result13);
        free(result13);
    }
    result17->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result17, result17->_refCount);
    if (result17->_refCount <= 0) {
        sjf_fancyMath_destroy(result17);
        free(result17);
    }
    result21->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result21, result21->_refCount);
    if (result21->_refCount <= 0) {
        sjf_fancyMath_destroy(result21);
        free(result21);
    }
    result22->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result22, result22->_refCount);
    if (result22->_refCount <= 0) {
        sjf_fancyMath_destroy(result22);
        free(result22);
    }
    result23->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result23, result23->_refCount);
    if (result23->_refCount <= 0) {
        sjf_fancyMath_destroy(result23);
        free(result23);
    }
    result24->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result24, result24->_refCount);
    if (result24->_refCount <= 0) {
        sjf_fancyMath_destroy(result24);
        free(result24);
    }
    result25->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result25, result25->_refCount);
    if (result25->_refCount <= 0) {
        sjf_fancyMath_destroy(result25);
        free(result25);
    }
    result27->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result27, result27->_refCount);
    if (result27->_refCount <= 0) {
        sjf_fancyMath_destroy(result27);
        free(result27);
    }
    result5->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result5, result5->_refCount);
    if (result5->_refCount <= 0) {
        sjf_fancyMath_destroy(result5);
        free(result5);
    }
    result9->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)result9, result9->_refCount);
    if (result9->_refCount <= 0) {
        sjf_fancyMath_destroy(result9);
        free(result9);
    }
    sjv_temp1->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)sjv_temp1, sjv_temp1->_refCount);
    if (sjv_temp1->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjv_temp2->_refCount--;
    printf("RELEASE\tsjs_fancyMath*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)sjv_temp2, sjv_temp2->_refCount);
    if (sjv_temp2->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp2);
        free(sjv_temp2);
    }
    return 0;
}
