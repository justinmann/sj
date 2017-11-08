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
void sjf_global(int32_t* _return);
void sjf_math(sjs_math* _this, sjs_math** _return);
void sjf_math_destroy(sjs_math* _this);
void sjf_math_sub(int32_t x, int32_t y, int32_t* _return);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t result9;

    sjf_class_foo(_parent, x, &result9);

    *_return = result9;
}

void sjf_class_destroy(sjs_class* _this) {
    sjf_math_destroy(_this->m);
}

void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t ifResult1;
    bool result5;

    result5 = x > 0;
    if (result5) {
        int32_t result6;
        int32_t result7;
        sjs_math* temp1;

        temp1 = _parent->m;
        sjf_math_sub(x, 1, &result7);
        sjf_class_bar(_parent, result7, &result6);
        ifResult1 = result6;

        sjf_math_destroy(temp1);
    } else {
        ifResult1 = 0;
    }

    *_return = ifResult1;
}

void sjf_global(int32_t* _return) {
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
    sjf_math(sjv_temp1, &result3);
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->m = result3;
    sjv_temp2->m->_refCount++;
    sjf_class(sjv_temp2, &result2);
    c = result2;
    c->_refCount++;
    sjf_class_foo(c, 4, &result4);

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

    *_return = result4;
}

void sjf_math(sjs_math* _this, sjs_math** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_math_destroy(sjs_math* _this) {
}

void sjf_math_sub(int32_t x, int32_t y, int32_t* _return) {
    int32_t result8;

    result8 = x - y;

    *_return = result8;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
