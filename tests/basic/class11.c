#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int x;
};

sjs_class* sjf_class(sjs_class* _this);
sjs_class* sjf_func();

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

sjs_class* sjf_func() {
    sjs_class* sjv_temp1;
    sjv_temp1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp1->x = 1;
    return sjf_class(sjv_temp1);
}

int main() {
    sjf_func()->x;
    return 0;
}
