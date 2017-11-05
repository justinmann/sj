#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_math sjs_math;

struct td_sjs_class {
    int _refCount;
    sjs_math* m;
};

struct td_sjs_math {
    int _refCount;
};

sjs_class* sjf_class(sjs_class* _this);
int32_t sjf_class_bar(sjs_class* _parent, int32_t x);
void sjf_class_destroy(sjs_class* _this);
int32_t sjf_class_foo(sjs_class* _parent, int32_t x);
int32_t sjf_global();
sjs_math* sjf_math(sjs_math* _this);
void sjf_math_destroy(sjs_math* _this);
int32_t sjf_math_sub(int32_t x, int32_t y);

sjs_class* sjf_class(sjs_class* _this) {

    return _this;
}

int32_t sjf_class_bar(sjs_class* _parent, int32_t x) {
    int32_t result9;

    result9 = sjf_class_foo(_parent, x);

    return result9;
}

void sjf_class_destroy(sjs_class* _this) {
    sjf_math_destroy(_this->m);
}

int32_t sjf_class_foo(sjs_class* _parent, int32_t x) {
    int32_t ifResult1;
    bool result5;

    result5 = x > 0;
    if (result5) {
        int32_t result6;
        int32_t result7;
        sjs_math* temp1;

        temp1 = _parent->m;
        result7 = sjf_math_sub(x, 1);
        result6 = sjf_class_bar(_parent, result7);
        ifResult1 = result6;

        sjf_math_destroy(temp1);
    } else {
        ifResult1 = 0;
    }

    return ifResult1;
}

int32_t sjf_global() {
    sjs_class* c;
    sjs_class* result2;
    sjs_math* result3;
    int32_t result4;
    sjs_math sjd_temp1;
    sjs_class sjd_temp2;
    sjs_math* sjv_temp1;
    sjs_class* sjv_temp2;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    result3 = sjf_math(sjv_temp1);
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->m = result3;
    result2 = sjf_class(sjv_temp2);
    c = result2;
    c->_refCount++;
    result4 = sjf_class_foo(c, 4);

    sjf_class_destroy(c);
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_class_destroy(result2);
        free(result2);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_math_destroy(result3);
        free(result3);
    }
    sjf_math_destroy(sjv_temp1);
    sjf_class_destroy(sjv_temp2);

    return result4;
}

sjs_math* sjf_math(sjs_math* _this) {

    return _this;
}

void sjf_math_destroy(sjs_math* _this) {
}

int32_t sjf_math_sub(int32_t x, int32_t y) {
    int32_t result8;

    result8 = x - y;

    return result8;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
