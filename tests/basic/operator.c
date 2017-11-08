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
sjs_fancyMath* sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num);
sjs_fancyMath* sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num);
sjs_fancyMath* sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num);
sjs_fancyMath* sjf_global();

sjs_fancyMath* sjf_fancyMath(sjs_fancyMath* _this) {
    _this->_refCount++;

    return _this;
}

sjs_fancyMath* sjf_fancyMath_add(sjs_fancyMath* _parent, sjs_fancyMath* num) {
    sjs_fancyMath* result5;
    int32_t result6;
    int32_t result7;
    sjs_fancyMath* sjv_temp3;
    int32_t temp1;
    int32_t temp2;

    temp1 = _parent->x;
    temp2 = num->x;
    result6 = temp1 + temp2;
    result7 = result6 + 1;
    sjv_temp3 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp3->_refCount = 1;
    sjv_temp3->x = result7;
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
    sjs_fancyMath* result17;
    int32_t result18;
    int32_t result19;
    sjs_fancyMath* sjv_temp6;
    int32_t temp7;
    int32_t temp8;

    temp7 = _parent->x;
    temp8 = num->x;
    result18 = temp7 / temp8;
    result19 = result18 + 1;
    sjv_temp6 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp6->_refCount = 1;
    sjv_temp6->x = result19;
    result17 = sjf_fancyMath(sjv_temp6);

    sjv_temp6->_refCount--;
    if (sjv_temp6->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp6);
        free(sjv_temp6);
    }

    return result17;
}

sjs_fancyMath* sjf_fancyMath_modulus(sjs_fancyMath* _parent, sjs_fancyMath* num) {
    sjs_fancyMath* result21;
    int32_t result22;
    int32_t result23;
    sjs_fancyMath* sjv_temp7;
    int32_t temp10;
    int32_t temp9;

    temp9 = _parent->x;
    temp10 = num->x;
    result22 = temp9 % temp10;
    result23 = result22 + 1;
    sjv_temp7 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp7->_refCount = 1;
    sjv_temp7->x = result23;
    result21 = sjf_fancyMath(sjv_temp7);

    sjv_temp7->_refCount--;
    if (sjv_temp7->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp7);
        free(sjv_temp7);
    }

    return result21;
}

sjs_fancyMath* sjf_fancyMath_multiply(sjs_fancyMath* _parent, sjs_fancyMath* num) {
    sjs_fancyMath* result13;
    int32_t result14;
    int32_t result15;
    sjs_fancyMath* sjv_temp5;
    int32_t temp5;
    int32_t temp6;

    temp5 = _parent->x;
    temp6 = num->x;
    result14 = temp5 * temp6;
    result15 = result14 + 1;
    sjv_temp5 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp5->_refCount = 1;
    sjv_temp5->x = result15;
    result13 = sjf_fancyMath(sjv_temp5);

    sjv_temp5->_refCount--;
    if (sjv_temp5->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp5);
        free(sjv_temp5);
    }

    return result13;
}

sjs_fancyMath* sjf_fancyMath_subtract(sjs_fancyMath* _parent, sjs_fancyMath* num) {
    int32_t result10;
    int32_t result11;
    sjs_fancyMath* result9;
    sjs_fancyMath* sjv_temp4;
    int32_t temp3;
    int32_t temp4;

    temp3 = _parent->x;
    temp4 = num->x;
    result10 = temp3 - temp4;
    result11 = result10 + 1;
    sjv_temp4 = (sjs_fancyMath*)malloc(sizeof(sjs_fancyMath));
    sjv_temp4->_refCount = 1;
    sjv_temp4->x = result11;
    result9 = sjf_fancyMath(sjv_temp4);

    sjv_temp4->_refCount--;
    if (sjv_temp4->_refCount == 0) {
        sjf_fancyMath_destroy(sjv_temp4);
        free(sjv_temp4);
    }

    return result9;
}

sjs_fancyMath* sjf_global() {
    sjs_fancyMath* a;
    sjs_fancyMath* b;
    sjs_fancyMath* c;
    sjs_fancyMath* d;
    sjs_fancyMath* e;
    sjs_fancyMath* f;
    sjs_fancyMath* g;
    sjs_fancyMath* result12;
    sjs_fancyMath* result16;
    sjs_fancyMath* result2;
    sjs_fancyMath* result20;
    sjs_fancyMath* result3;
    sjs_fancyMath* result4;
    sjs_fancyMath* result8;
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
    result8 = sjf_fancyMath_subtract(a, b);
    d = result8;
    d->_refCount++;
    result12 = sjf_fancyMath_multiply(a, b);
    e = result12;
    e->_refCount++;
    result16 = sjf_fancyMath_divide(a, b);
    f = result16;
    f->_refCount++;
    result20 = sjf_fancyMath_modulus(a, b);
    g = result20;

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
    result12->_refCount--;
    if (result12->_refCount == 0) {
        sjf_fancyMath_destroy(result12);
        free(result12);
    }
    result16->_refCount--;
    if (result16->_refCount == 0) {
        sjf_fancyMath_destroy(result16);
        free(result16);
    }
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_fancyMath_destroy(result2);
        free(result2);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_fancyMath_destroy(result3);
        free(result3);
    }
    result4->_refCount--;
    if (result4->_refCount == 0) {
        sjf_fancyMath_destroy(result4);
        free(result4);
    }
    result8->_refCount--;
    if (result8->_refCount == 0) {
        sjf_fancyMath_destroy(result8);
        free(result8);
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

    return result20;
}

int main() {
    sjs_fancyMath* result1;

    result1 = sjf_global();

    return 0;
}
