#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_math sjs_math;

struct td_sjs_class {
    sjs_math* m;
};

struct td_sjs_math {
};

sjs_class* sjf_class(sjs_class* _this);
int sjf_class_bar(sjs_class* _parent, int x);
int sjf_class_foo(sjs_class* _parent, int x);
int sjf_global();
sjs_math* sjf_math(sjs_math* _this);
int sjf_math_sub(int x, int y);

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int sjf_class_bar(sjs_class* _parent, int x) {
    return sjf_class_foo((_parent), (x));
}

int sjf_class_foo(sjs_class* _parent, int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_class_bar((_parent), (sjf_math_sub((x), (1))));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int sjf_global() {
    sjs_class* c;
    sjs_math sjd_temp1;
    sjs_class sjd_temp2;
    sjs_math* sjv_temp1;
    sjs_class* sjv_temp2;
    sjv_temp1 = &sjd_temp1;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->m = sjf_math(sjv_temp1);
    c = sjf_class(sjv_temp2);
    return sjf_class_foo((c), (4));
}

sjs_math* sjf_math(sjs_math* _this) {
    return _this;
}

int sjf_math_sub(int x, int y) {
    return (x) - (y);
}

int main() {
    sjf_global();
    return 0;
}
