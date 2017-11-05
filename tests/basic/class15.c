#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_anon_0 sjs_anon_0;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_global sjs_global;

struct td_sjs_anon_0 {
    int _refCount;
    int32_t test;
};

struct td_sjs_class {
    int _refCount;
    sjs_global* _parent;
};

struct td_sjs_global {
    int _refCount;
    sjs_anon_0* math;
};

sjs_anon_0* sjf_anon_0(sjs_anon_0* _this);
void sjf_anon_0_destroy(sjs_anon_0* _this);
int32_t sjf_anon_0_sub(sjs_anon_0* _parent, int32_t x, int32_t y);
sjs_class* sjf_class(sjs_class* _this);
int32_t sjf_class_bar(sjs_class* _parent, int32_t x);
void sjf_class_destroy(sjs_class* _this);
int32_t sjf_class_foo(sjs_class* _parent, int32_t x);
int32_t sjf_global(sjs_global* _this);
void sjf_global_destroy(sjs_global* _this);

sjs_anon_0* sjf_anon_0(sjs_anon_0* _this) {

    return _this;
}

void sjf_anon_0_destroy(sjs_anon_0* _this) {
}

int32_t sjf_anon_0_sub(sjs_anon_0* _parent, int32_t x, int32_t y) {
    int32_t result8;
    int32_t result9;
    int32_t temp3;

    result8 = x - y;
    temp3 = _parent->test;
    result9 = result8 - temp3;

    return result9;
}

sjs_class* sjf_class(sjs_class* _this) {

    return _this;
}

int32_t sjf_class_bar(sjs_class* _parent, int32_t x) {
    int32_t result10;

    result10 = sjf_class_foo(_parent, x);

    return result10;
}

void sjf_class_destroy(sjs_class* _this) {
}

int32_t sjf_class_foo(sjs_class* _parent, int32_t x) {
    int32_t ifResult1;
    bool result5;

    result5 = x > 0;
    if (result5) {
        int32_t result6;
        int32_t result7;
        sjs_global* temp1;
        sjs_anon_0* temp2;

        temp1 = _parent->_parent;
        temp2 = temp1->math;
        result7 = sjf_anon_0_sub(temp2, x, 1);
        result6 = sjf_class_bar(_parent, result7);
        ifResult1 = result6;

        sjf_global_destroy(temp1);
        temp2->_refCount--;
        if (temp2->_refCount == 0) {
            sjf_anon_0_destroy(temp2);
            free(temp2);
        }
    } else {
        ifResult1 = 0;
    }

    return ifResult1;
}

int32_t sjf_global(sjs_global* _this) {
    sjs_class* c;
    sjs_anon_0* result2;
    sjs_class* result3;
    int32_t result4;
    sjs_class sjd_temp1;
    sjs_anon_0* sjv_temp1;
    sjs_class* sjv_temp2;

    sjv_temp1 = (sjs_anon_0*)malloc(sizeof(sjs_anon_0));
    sjv_temp1->_refCount = 1;
    sjv_temp1->test = 1;
    result2 = sjf_anon_0(sjv_temp1);
    _this->math = result2;
    _this->math->_refCount++;
    sjv_temp2 = &sjd_temp1;
    sjv_temp2->_refCount = 1;
    result3 = sjf_class(sjv_temp2);
    c = result3;
    c->_refCount++;
    result4 = sjf_class_foo(c, 4);

    sjf_class_destroy(c);
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_anon_0_destroy(result2);
        free(result2);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_class_destroy(result3);
        free(result3);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount == 0) {
        sjf_anon_0_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjf_class_destroy(sjv_temp2);

    return result4;
}

void sjf_global_destroy(sjs_global* _this) {
}

int main() {
    int32_t result1;
    sjs_global sjd_temp2;
    sjs_global* sjv_temp3;

    sjv_temp3 = &sjd_temp2;
    sjv_temp3->_refCount = 1;
    result1 = sjf_global(sjv_temp3);

    sjf_global_destroy(sjv_temp3);

    return 0;
}
