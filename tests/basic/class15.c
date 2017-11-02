#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_anon_0 sjs_anon_0;
typedef struct td_sjs_class sjs_class;

struct td_sjs_anon_0 {
};

struct td_sjs_class {
    sjs_global* _parent;
};

sjs_anon_0* sjf_anon_0(sjs_anon_0* _this);
int sjf_anon_0_sub(int x, int y);
sjs_class* sjf_class(sjs_class* _this);
int sjf_class_bar(sjs_class* _parent, int x);
int sjf_class_foo(sjs_class* _parent, int x);

sjs_anon_0* sjf_anon_0(sjs_anon_0* _this) {
    return _this;
}

int sjf_anon_0_sub(int x, int y) {
    return (x) - (y);
}

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int sjf_class_bar(sjs_class* _parent, int x) {
    return sjf_class_foo((_parent), (x));
}

int sjf_class_foo(sjs_class* _parent, int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_class_bar((_parent), (sjf_anon_0_sub((x), (1))));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int main() {
    sjs_class* c;
    sjs_class sjd_temp1;
    sjs_anon_0* sjv_temp1;
    sjs_class* sjv_temp2;
    sjv_temp1 = (sjs_anon_0*)malloc(sizeof(sjs_anon_0));
    math = sjf_anon_0(sjv_temp1);
    sjv_temp2 = &sjd_temp1;
    c = sjf_class(sjv_temp2);
    sjf_class_foo((c), (4));
    return 0;
}
