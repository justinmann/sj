#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int m;
};

int sjf_class(sjs_class* _this);
int sjf_class_inner(sjs_class* _parent);

int sjf_class(sjs_class* _this) {
    _this->m = 1;
    return sjf_class_inner((_this));
}

int sjf_class_inner(sjs_class* _parent) {
    return _parent->m;
}

int main() {
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    sjf_class(sjv_temp1);
    return 0;
}
