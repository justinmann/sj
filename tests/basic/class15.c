#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct td_sjs_anon_0 sjs_anon_0;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_global sjs_global;

struct td_sjs_anon_0 {
    int32_t test;
};

struct td_sjs_class {
    sjs_global* _parent;
};

struct td_sjs_global {
    sjs_anon_0* math;
};

sjs_anon_0* sjf_anon_0(sjs_anon_0* _this);
int32_t sjf_anon_0_sub(sjs_anon_0* _parent, int32_t x, int32_t y);
sjs_class* sjf_class(sjs_class* _this);
int32_t sjf_class_bar(sjs_class* _parent, int32_t x);
int32_t sjf_class_foo(sjs_class* _parent, int32_t x);
int32_t sjf_global(sjs_global* _this);

sjs_anon_0* sjf_anon_0(sjs_anon_0* _this) {
    return _this;
}

int32_t sjf_anon_0_sub(sjs_anon_0* _parent, int32_t x, int32_t y) {
    return ((x) - (y)) - (_parent->test);
}

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int32_t sjf_class_bar(sjs_class* _parent, int32_t x) {
    return sjf_class_foo((_parent), (x));
}

int32_t sjf_class_foo(sjs_class* _parent, int32_t x) {
    int32_t ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_class_bar((_parent), (sjf_anon_0_sub((_parent->_parent->math), (x), (1))));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int32_t sjf_global(sjs_global* _this) {
    sjs_class* c;
    sjs_class sjd_temp1;
    sjs_anon_0* sjv_temp1;
    sjs_class* sjv_temp2;
    sjv_temp1 = (sjs_anon_0*)malloc(sizeof(sjs_anon_0));
    sjv_temp1->test = 1;
    _this->math = sjf_anon_0(sjv_temp1);
    sjv_temp2 = &sjd_temp1;
    c = sjf_class(sjv_temp2);
    return sjf_class_foo((c), (4));
}

int main() {
    sjs_global sjd_temp2;
    sjs_global* sjv_temp3;
    sjv_temp3 = &sjd_temp2;
    sjf_global(sjv_temp3);
    return 0;
}
