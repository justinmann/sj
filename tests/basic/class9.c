#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
};

sjs_class* sjf_class(sjs_class* _this);
int sjf_class_func();

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int sjf_class_func() {
    return 1;
}

int main() {
    sjs_class* c;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    c = sjf_class(sjv_temp1);
    sjf_class_func();
    return 0;
}
