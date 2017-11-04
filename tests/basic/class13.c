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
    sjs_class* _retVal;
    _retVal = (_this);
    return _retVal;
}

int32_t sjf_class_bar(sjs_class* _parent, int32_t x) {
    int32_t _retVal;
    _retVal = (sjf_class_foo((_parent), (x)));
    return _retVal;
}

void sjf_class_destroy(sjs_class* _this) {
    free(_this);
}

int32_t sjf_class_foo(sjs_class* _parent, int32_t x) {
    int32_t _retVal;
    int32_t ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_class_bar((_parent), (sjf_math_sub((x), (1))));
    } else {
        ifResult1 = 0;
    }
    _retVal = (ifResult1);
    return _retVal;
}

int32_t sjf_global() {
    int32_t _retVal;
    sjs_class* c;
    sjs_math sjd_temp1;
    sjs_class sjd_temp2;
    sjs_math* sjv_temp1;
    sjs_class* sjv_temp2;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->m = sjf_math(sjv_temp1);
    c = sjf_class(sjv_temp2);
    _retVal = (sjf_class_foo((c), (4)));
    sjf_math_destroy(sjv_temp1);
    sjf_class_destroy(sjv_temp2);
    return _retVal;
}

sjs_math* sjf_math(sjs_math* _this) {
    sjs_math* _retVal;
    _retVal = (_this);
    return _retVal;
}

void sjf_math_destroy(sjs_math* _this) {
    free(_this);
}

int32_t sjf_math_sub(int32_t x, int32_t y) {
    int32_t _retVal;
    _retVal = ((x) - (y));
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
