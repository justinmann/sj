#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int x;
};

sjs_class* sjf_class(sjs_class* _this);
int sjf_class_func(sjs_class* _parent);

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int sjf_class_func(sjs_class* _parent) {
    return _parent->x;
}

int main() {
    sjs_class* c;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->x = 1;
    c = sjf_class(sjv_temp1);
    sjf_class_func((c));
    return 0;
}
