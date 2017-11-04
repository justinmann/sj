#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_math sjs_math;

struct td_sjs_class {
    sjs_math* m;
};

struct td_sjs_math {
};

sjs_class* sjf_class(sjs_class* _this);
int32_t sjf_class_bar(sjs_class* _parent, int32_t x);
sjs_class* sjf_class_destroy(sjs_class* _this);
int32_t sjf_class_foo(sjs_class* _parent, int32_t x);
int32_t sjf_global();
sjs_math* sjf_math(sjs_math* _this);
sjs_math* sjf_math_destroy(sjs_math* _this);
int32_t sjf_math_sub(int32_t x, int32_t y);

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int32_t sjf_class_bar(sjs_class* _parent, int32_t x) {
    return sjf_class_foo((_parent), (x));
}

sjs_class* sjf_class_destroy(sjs_class* _this) {
    free(_this);
}

int32_t sjf_class_foo(sjs_class* _parent, int32_t x) {
    int32_t ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_class_bar((_parent), (sjf_math_sub((x), (1))));
    } else {
        ifResult1 = 0;
    }
    ifResult1->_refCount--;
    if (ifResult1->_refCount == 0) {
        free(ifResult1);
    }
    return ifResult1;
}

int32_t sjf_global() {
    sjs_class* c;
    sjs_math sjd_temp1;
    sjs_class sjd_temp2;
    sjs_math* sjv_temp1;
    sjs_class* sjv_temp2;
    sjv_temp1 = &sjd_temp1;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->m = sjf_math(sjv_temp1);
    c = sjf_class(sjv_temp2);
    sjf_math_destroy(sjv_temp1);
    sjf_class_destroy(sjv_temp2);
    return sjf_class_foo((c), (4));
}

sjs_math* sjf_math(sjs_math* _this) {
    return _this;
}

sjs_math* sjf_math_destroy(sjs_math* _this) {
    free(_this);
}

int32_t sjf_math_sub(int32_t x, int32_t y) {
    return (x) - (y);
}

int main() {
    sjf_global();
    return 0;
}
