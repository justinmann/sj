#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_fancyMath sjs_fancyMath;

struct td_sjs_fancyMath {
    int _refCount;
    int32_t x;
};

sjs_fancyMath* sjf_fancyMath(sjs_fancyMath* _this);
sjs_fancyMath* sjf_fancyMath_add(sjs_fancyMath* _parent, sjs_fancyMath* num);
void sjf_fancyMath_destroy(sjs_fancyMath* _this);
sjs_fancyMath* sjf_fancyMath_divide(sjs_fancyMath* _parent, sjs_fancyMath* num);
int32_t sjf_fancyMath_getX(sjs_fancyMath* _parent);
sjs_fancyMath* sjf_fancyMath_increment(sjs_fancyMath* _parent);
sjs_fancyMath* sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num);
sjs_fancyMath* sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num);
sjs_fancyMath* sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num);
int32_t sjf_global();

sjs_fancyMath* sjf_fancyMath(sjs_fancyMath* _this) {
    _this->_refCount++;

    return _this;
}

sjs_fancyMath* sjf_fancyMath_add(sjs_fancyMath* _parent, sjs_fancyMath* num) {
    sjs_fancyMath* result5;
    int32_t result6;
    int32_t result7;
    int32_t result8;
    sjs_fancyMath* sjv_temp3;
    int32_t temp1;

    temp1 = _parent->x;
    result6 = sjf_fancyMath_getX(num);
    result7 = temp1 + result6;
    result8 = result7 + 1;
    sjv_temp3 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp3->_refCount = 1;
    sjv_temp3->x = result8;
    result5 = sjf_fancyMath(sjv_temp3);

    sjv_temp3->_refCount--;
    if (sjv_temp3->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp3);
        free(sjv_temp3);
    }

    return result5;
}

void sjf_fancyMath_destroy(sjs_fancyMath* _this) {
}

sjs_fancyMath* sjf_fancyMath_divide(sjs_fancyMath* _parent, sjs_fancyMath* num) {
    sjs_fancyMath* result20;
    int32_t result21;
    int32_t result22;
    int32_t result23;
    sjs_fancyMath* sjv_temp6;
    int32_t temp5;

    temp5 = _parent->x;
    result21 = sjf_fancyMath_getX(num);
    result22 = temp5 / result21;
    result23 = result22 + 1;
    sjv_temp6 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp6->_refCount = 1;
    sjv_temp6->x = result23;
    result20 = sjf_fancyMath(sjv_temp6);

    sjv_temp6->_refCount--;
    if (sjv_temp6->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp6);
        free(sjv_temp6);
    }

    return result20;
}

int32_t sjf_fancyMath_getX(sjs_fancyMath* _parent) {
    int32_t temp2;

    temp2 = _parent->x;

    return temp2;
}

sjs_fancyMath* sjf_fancyMath_increment(sjs_fancyMath* _parent) {
    sjs_fancyMath* result34;
    int32_t result35;
    sjs_fancyMath* sjv_temp8;
    int32_t temp7;

    temp7 = _parent->x;
    result35 = temp7 + 1;
    sjv_temp8 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp8->_refCount = 1;
    sjv_temp8->x = result35;
    result34 = sjf_fancyMath(sjv_temp8);

    sjv_temp8->_refCount--;
    if (sjv_temp8->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp8);
        free(sjv_temp8);
    }

    return result34;
}

sjs_fancyMath* sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num) {
    sjs_fancyMath* result25;
    int32_t result26;
    int32_t result27;
    int32_t result28;
    sjs_fancyMath* sjv_temp7;
    int32_t temp6;

    temp6 = _parent->x;
    result26 = sjf_fancyMath_getX(num);
    result27 = temp6 % result26;
    result28 = result27 + 1;
    sjv_temp7 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp7->_refCount = 1;
    sjv_temp7->x = result28;
    result25 = sjf_fancyMath(sjv_temp7);

    sjv_temp7->_refCount--;
    if (sjv_temp7->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp7);
        free(sjv_temp7);
    }

    return result25;
}

sjs_fancyMath* sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num) {
    sjs_fancyMath* result15;
    int32_t result16;
    int32_t result17;
    int32_t result18;
    sjs_fancyMath* sjv_temp5;
    int32_t temp4;

    temp4 = _parent->x;
    result16 = sjf_fancyMath_getX(num);
    result17 = temp4 * result16;
    result18 = result17 + 1;
    sjv_temp5 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp5->_refCount = 1;
    sjv_temp5->x = result18;
    result15 = sjf_fancyMath(sjv_temp5);

    sjv_temp5->_refCount--;
    if (sjv_temp5->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp5);
        free(sjv_temp5);
    }

    return result15;
}

sjs_fancyMath* sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num) {
    sjs_fancyMath* result10;
    int32_t result11;
    int32_t result12;
    int32_t result13;
    sjs_fancyMath* sjv_temp4;
    int32_t temp3;

    temp3 = _parent->x;
    result11 = sjf_fancyMath_getX(num);
    result12 = temp3 - result11;
    result13 = result12 + 1;
    sjv_temp4 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp4->_refCount = 1;
    sjv_temp4->x = result13;
    result10 = sjf_fancyMath(sjv_temp4);

    sjv_temp4->_refCount--;
    if (sjv_temp4->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp4);
        free(sjv_temp4);
    }

    return result10;
}

int32_t sjf_global() {
    sjs_fancyMath* a;
    sjs_fancyMath* b;
    sjs_fancyMath* c;
    sjs_fancyMath* d;
    sjs_fancyMath* e;
    sjs_fancyMath* f;
    sjs_fancyMath* g;
    int32_t i;
    sjs_fancyMath* result14;
    sjs_fancyMath* result19;
    sjs_fancyMath* result2;
    sjs_fancyMath* result24;
    sjs_fancyMath* result29;
    sjs_fancyMath* result3;
    sjs_fancyMath* result30;
    sjs_fancyMath* result31;
    sjs_fancyMath* result32;
    sjs_fancyMath* result33;
    sjs_fancyMath* result36;
    int32_t result37;
    sjs_fancyMath* result4;
    sjs_fancyMath* result9;
    sjs_fancyMath* sjv_temp1;
    sjs_fancyMath* sjv_temp2;

    sjv_temp1 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 1;
    result2 = sjf_fancyMath(sjv_temp1);
    a = result2;
    a->_refCount++;
    sjv_temp2 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp2->_refCount = 1;
    sjv_temp2->x = 2;
    result3 = sjf_fancyMath(sjv_temp2);
    b = result3;
    b->_refCount++;
    result4 = sjf_fancyMath_add(a, b);
    c = result4;
    c->_refCount++;
    result9 = sjf_fancyMath_subtract(a, b);
    d = result9;
    d->_refCount++;
    result14 = sjf_fancyMath_multiply(a, b);
    e = result14;
    e->_refCount++;
    result19 = sjf_fancyMath_divide(a, b);
    f = result19;
    f->_refCount++;
    result24 = sjf_fancyMath_modulus(a, b);
    g = result24;
    g->_refCount++;
    result29 = sjf_fancyMath_add(c, c);
    c->_refCount--;
    if (c->_refCount == 0) {
        sjf_fancyMath_destroy(c);
        free(c);
    }

    c = result29;

    c->_refCount++;

    result30 = sjf_fancyMath_subtract(d, d);

    d->_refCount--;

    if (d->_refCount == 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }

    d = result30;

    d->_refCount++;

    result31 = sjf_fancyMath_multiply(d, d);

    d->_refCount--;

    if (d->_refCount == 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }

    d = result31;

    d->_refCount++;

    result32 = sjf_fancyMath_divide(d, d);

    d->_refCount--;

    if (d->_refCount == 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }

    d = result32;

    d->_refCount++;

    result33 = sjf_fancyMath_increment(e);

    e->_refCount--;

    if (e->_refCount == 0) {
        sjf_fancyMath_destroy(e);
        free(e);
    }

    e = result33;

    e->_refCount++;

    result36 = sjf_fancyMath_increment(f);

    f->_refCount--;

    if (f->_refCount == 0) {
        sjf_fancyMath_destroy(f);
        free(f);
    }

    f = result36;

    f->_refCount++;

    result37 = sjf_fancyMath_getX(f);

    i = result37;

    a->_refCount--;
    if (a->_refCount == 0) {
        sjf_fancyMath_destroy(a);
        free(a);
    }
    b->_refCount--;
    if (b->_refCount == 0) {
        sjf_fancyMath_destroy(b);
        free(b);
    }
    c->_refCount--;
    if (c->_refCount == 0) {
        sjf_fancyMath_destroy(c);
        free(c);
    }
    d->_refCount--;
    if (d->_refCount == 0) {
        sjf_fancyMath_destroy(d);
        free(d);
    }
    e->_refCount--;
    if (e->_refCount == 0) {
        sjf_fancyMath_destroy(e);
        free(e);
    }
    f->_refCount--;
    if (f->_refCount == 0) {
        sjf_fancyMath_destroy(f);
        free(f);
    }
    g->_refCount--;
    if (g->_refCount == 0) {
        sjf_fancyMath_destroy(g);
        free(g);
    }
    result14->_refCount--;
    if (result14->_refCount == 0) {
        sjf_fancyMath_destroy(result14);
        free(result14);
    }
    result19->_refCount--;
    if (result19->_refCount == 0) {
        sjf_fancyMath_destroy(result19);
        free(result19);
    }
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_fancyMath_destroy(result2);
        free(result2);
    }
    result24->_refCount--;
    if (result24->_refCount == 0) {
        sjf_fancyMath_destroy(result24);
        free(result24);
    }
    result29->_refCount--;
    if (result29->_refCount == 0) {
        sjf_fancyMath_destroy(result29);
        free(result29);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_fancyMath_destroy(result3);
        free(result3);
    }
    result30->_refCount--;
    if (result30->_refCount == 0) {
        sjf_fancyMath_destroy(result30);
        free(result30);
    }
    result31->_refCount--;
    if (result31->_refCount == 0) {
        sjf_fancyMath_destroy(result31);
        free(result31);
    }
    result32->_refCount--;
    if (result32->_refCount == 0) {
        sjf_fancyMath_destroy(result32);
        free(result32);
    }
    result33->_refCount--;
    if (result33->_refCount == 0) {
        sjf_fancyMath_destroy(result33);
        free(result33);
    }
    result36->_refCount--;
    if (result36->_refCount == 0) {
        sjf_fancyMath_destroy(result36);
        free(result36);
    }
    result4->_refCount--;
    if (result4->_refCount == 0) {
        sjf_fancyMath_destroy(result4);
        free(result4);
    }
    result9->_refCount--;
    if (result9->_refCount == 0) {
        sjf_fancyMath_destroy(result9);
        free(result9);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjv_temp2->_refCount--;
    if (sjv_temp2->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp2);
        free(sjv_temp2);
    }

    return result37;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
