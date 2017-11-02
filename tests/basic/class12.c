#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
};

sjs_class* sjf_class(sjs_class* _this);
int sjf_class_bar(int x);
int sjf_class_foo(int x);

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int sjf_class_bar(int x) {
    return sjf_class_foo((x));
}

int sjf_class_foo(int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_class_bar(((x) - (1)));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int main() {
    sjs_class* c;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    c = sjf_class(sjv_temp1);
    sjf_class_foo((4));
    return 0;
}
