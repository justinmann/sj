#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int b;
};

sjs_class* sjf_class(sjs_class* _this);

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int main() {
    sjs_class* a;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->b = 0;
    a = sjf_class(sjv_temp1);
    a->b = 1;
    return 0;
}
