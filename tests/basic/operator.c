#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

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
void sjf_global(void);

void sjf_fancyMath(sjs_fancyMath* _this, sjs_fancyMath** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_fancyMath_add(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return) {
    int32_t result2;
    int32_t result3;
    int32_t result4;
    sjs_fancyMath* sjv_temp3;
    int32_t temp1;

    temp1 = _parent->x;
    result2 = 0;
    sjf_fancyMath_getX(num, &result2);
    result3 = temp1 + result2;
    result4 = result3 + 1;
    sjv_temp3 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp3->_refCount = 1;
    sjv_temp3->x = result4;
    sjf_fancyMath(sjv_temp3, &sjv_temp3);
    sjv_temp3->_refCount++;

    sjv_temp3->_refCount--;
    if (sjv_temp3->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp3);
        free(sjv_temp3);
    }

    *_return = sjv_temp3;
}

void sjf_fancyMath_destroy(sjs_fancyMath* _this) {
}

void sjf_fancyMath_divide(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return) {
    int32_t result14;
    int32_t result15;
    int32_t result16;
    sjs_fancyMath* sjv_temp6;
    int32_t temp5;

    temp5 = _parent->x;
    result14 = 0;
    sjf_fancyMath_getX(num, &result14);
    result15 = temp5 / result14;
    result16 = result15 + 1;
    sjv_temp6 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp6->_refCount = 1;
    sjv_temp6->x = result16;
    sjf_fancyMath(sjv_temp6, &sjv_temp6);
    sjv_temp6->_refCount++;

    sjv_temp6->_refCount--;
    if (sjv_temp6->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp6);
        free(sjv_temp6);
    }

    *_return = sjv_temp6;
}

void sjf_fancyMath_getX(sjs_fancyMath* _parent, int32_t* _return) {
    int32_t temp2;

    temp2 = _parent->x;

    *_return = temp2;
}

void sjf_fancyMath_increment(sjs_fancyMath* _parent, sjs_fancyMath** _return) {
    int32_t result26;
    sjs_fancyMath* sjv_temp8;
    int32_t temp7;

    temp7 = _parent->x;
    result26 = temp7 + 1;
    sjv_temp8 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp8->_refCount = 1;
    sjv_temp8->x = result26;
    sjf_fancyMath(sjv_temp8, &sjv_temp8);
    sjv_temp8->_refCount++;

    sjv_temp8->_refCount--;
    if (sjv_temp8->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp8);
        free(sjv_temp8);
    }

    *_return = sjv_temp8;
}

void sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return) {
    int32_t result18;
    int32_t result19;
    int32_t result20;
    sjs_fancyMath* sjv_temp7;
    int32_t temp6;

    temp6 = _parent->x;
    result18 = 0;
    sjf_fancyMath_getX(num, &result18);
    result19 = temp6 % result18;
    result20 = result19 + 1;
    sjv_temp7 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp7->_refCount = 1;
    sjv_temp7->x = result20;
    sjf_fancyMath(sjv_temp7, &sjv_temp7);
    sjv_temp7->_refCount++;

    sjv_temp7->_refCount--;
    if (sjv_temp7->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp7);
        free(sjv_temp7);
    }

    *_return = sjv_temp7;
}

void sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num, sjs_fancyMath** _return) {
    int32_t result10;
    int32_t result11;
    int32_t result12;
    sjs_fancyMath* sjv_temp5;
    int32_t temp4;

    temp4 = _parent->x;
    result10 = 0;
    sjf_fancyMath_getX(num, &result10);
    result11 = temp4 * result10;
    result12 = result11 + 1;
    sjv_temp5 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp5->_refCount = 1;
    sjv_temp5->x = result12;
    sjf_fancyMath(sjv_temp5, &sjv_temp5);
    sjv_temp5->_refCount++;

    sjv_temp5->_refCount--;
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
    int32_t result6;
    int32_t result7;
    int32_t result8;
    sjs_fancyMath* sjv_temp4;
    int32_t temp3;

    temp3 = _parent->x;
    result6 = 0;
    sjf_fancyMath_getX(num, &result6);
    result7 = temp3 - result6;
    result8 = result7 + 1;
    sjv_temp4 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp4->_refCount = 1;
    sjv_temp4->x = result8;
    sjf_fancyMath(sjv_temp4, &sjv_temp4);
    sjv_temp4->_refCount++;

    sjv_temp4->_refCount--;
    if (sjv_temp4->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp4);
        free(sjv_temp4);
    }

    *_return = sjv_temp4;
}

void sjf_global(void) {
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
    sjv_temp1->x = 1;
    sjf_fancyMath(sjv_temp1, &sjv_temp1);
    a = sjv_temp1;
    a->_refCount++;
    sjv_temp2 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp2->_refCount = 1;
    sjv_temp2->x = 2;
    sjf_fancyMath(sjv_temp2, &sjv_temp2);
    b = sjv_temp2;
    b->_refCount++;
    result1 = 0;
    sjf_fancyMath_add(a, b, &result1);
    c = result1;
    c->_refCount++;
    result5 = 0;
    sjf_fancyMath_subtract(a, b, &result5);
    d = result5;
    d->_refCount++;
    result9 = 0;
    sjf_fancyMath_multiply(a, b, &result9);
    e = result9;
    e->_refCount++;
    result13 = 0;
    sjf_fancyMath_divide(a, b, &result13);
    f = result13;
    f->_refCount++;
    result17 = 0;
    sjf_fancyMath_modulus(a, b, &result17);
    g = result17;
    g->_refCount++;
    result21 = 0;
    sjf_fancyMath_add(c, c, &result21);
    c->_refCount--;
    if (c->_refCount <= 0) {
        sjf_fancyMath_destroy(c);
        free(c);
    }

    c = result21;

    c->_refCount++;

    result22 = 0;

    sjf_fancyMath_subtract(d, d, &result22);

    d->_refCount--;

    if (d->_refCount <= 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }

    d = result22;

    d->_refCount++;

    result23 = 0;

    sjf_fancyMath_multiply(d, d, &result23);

    d->_refCount--;

    if (d->_refCount <= 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }

    d = result23;

    d->_refCount++;

    result24 = 0;

    sjf_fancyMath_divide(d, d, &result24);

    d->_refCount--;

    if (d->_refCount <= 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }

    d = result24;

    d->_refCount++;

    result25 = 0;

    sjf_fancyMath_increment(e, &result25);

    e->_refCount--;

    if (e->_refCount <= 0) {
        sjf_fancyMath_destroy(e);
        free(e);
    }

    e = result25;

    e->_refCount++;

    result27 = 0;

    sjf_fancyMath_increment(f, &result27);

    f->_refCount--;

    if (f->_refCount <= 0) {
        sjf_fancyMath_destroy(f);
        free(f);
    }

    f = result27;

    f->_refCount++;

    result28 = 0;

    sjf_fancyMath_getX(f, &result28);

    i = result28;

    result29 = 0;

    sjf_fancyMath_setBob(a, 12, &result29);

    j = result29;

    a->_refCount--;
    if (a->_refCount <= 0) {
        sjf_fancyMath_destroy(a);
        free(a);
    }
    b->_refCount--;
    if (b->_refCount <= 0) {
        sjf_fancyMath_destroy(b);
        free(b);
    }
    c->_refCount--;
    if (c->_refCount <= 0) {
        sjf_fancyMath_destroy(c);
        free(c);
    }
    d->_refCount--;
    if (d->_refCount <= 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }
    e->_refCount--;
    if (e->_refCount <= 0) {
        sjf_fancyMath_destroy(e);
        free(e);
    }
    f->_refCount--;
    if (f->_refCount <= 0) {
        sjf_fancyMath_destroy(f);
        free(f);
    }
    g->_refCount--;
    if (g->_refCount <= 0) {
        sjf_fancyMath_destroy(g);
        free(g);
    }
    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sjf_fancyMath_destroy(result1);
        free(result1);
    }
    result13->_refCount--;
    if (result13->_refCount <= 0) {
        sjf_fancyMath_destroy(result13);
        free(result13);
    }
    result17->_refCount--;
    if (result17->_refCount <= 0) {
        sjf_fancyMath_destroy(result17);
        free(result17);
    }
    result21->_refCount--;
    if (result21->_refCount <= 0) {
        sjf_fancyMath_destroy(result21);
        free(result21);
    }
    result22->_refCount--;
    if (result22->_refCount <= 0) {
        sjf_fancyMath_destroy(result22);
        free(result22);
    }
    result23->_refCount--;
    if (result23->_refCount <= 0) {
        sjf_fancyMath_destroy(result23);
        free(result23);
    }
    result24->_refCount--;
    if (result24->_refCount <= 0) {
        sjf_fancyMath_destroy(result24);
        free(result24);
    }
    result25->_refCount--;
    if (result25->_refCount <= 0) {
        sjf_fancyMath_destroy(result25);
        free(result25);
    }
    result27->_refCount--;
    if (result27->_refCount <= 0) {
        sjf_fancyMath_destroy(result27);
        free(result27);
    }
    result5->_refCount--;
    if (result5->_refCount <= 0) {
        sjf_fancyMath_destroy(result5);
        free(result5);
    }
    result9->_refCount--;
    if (result9->_refCount <= 0) {
        sjf_fancyMath_destroy(result9);
        free(result9);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjv_temp2->_refCount--;
    if (sjv_temp2->_refCount <= 0) {
        sjf_fancyMath_destroy(sjv_temp2);
        free(sjv_temp2);
    }
}

int main() {
    sjf_global();

    return 0;
}
