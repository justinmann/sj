#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_math sjs_math;

struct td_sjs_class {
    int _refCount;
    sjs_math* m;
};

struct td_sjs_math {
    int _refCount;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_global(void);
void sjf_math(sjs_math* _this, sjs_math** _return);
void sjf_math_destroy(sjs_math* _this);
void sjf_math_sub(int32_t x, int32_t y, int32_t* _return);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t result6;

    result6 = 0;
    sjf_class_foo(_parent, x, &result6);

    *_return = result6;
}

void sjf_class_destroy(sjs_class* _this) {
    sjf_math_destroy(_this->m);
}

void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t ifResult1;
    bool result2;

    result2 = x > 0;
    if (result2) {
        int32_t result3;
        int32_t result4;
        sjs_math* temp1;

        result3 = 0;
        temp1 = _parent->m;
        result4 = 0;
        sjf_math_sub(x, 1, &result4);
        sjf_class_bar(_parent, result4, &result3);
        ifResult1 = result3;
    } else {
        ifResult1 = 0;
    }

    *_return = ifResult1;
}

void sjf_global(void) {
    sjs_math sjd_temp1;
    sjs_class sjd_temp2;
    sjs_class* c;
    int32_t result1;
    sjs_math* sjv_temp1;
    sjs_class* sjv_temp2;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_math(sjv_temp1, &sjv_temp1);
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->m = sjv_temp1;
    sjv_temp2->m->_refCount++;
    sjf_class(sjv_temp2, &sjv_temp2);
    c = sjv_temp2;
    c->_refCount++;
    result1 = 0;
    sjf_class_foo(c, 4, &result1);
    sjf_math_destroy(&sjd_temp1);
    sjf_class_destroy(&sjd_temp2);
}

void sjf_math(sjs_math* _this, sjs_math** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_math_destroy(sjs_math* _this) {
}

void sjf_math_sub(int32_t x, int32_t y, int32_t* _return) {
    int32_t result5;

    result5 = x - y;

    *_return = result5;
}

int main() {
    sjf_global();

    return 0;
}
