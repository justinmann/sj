#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int32_t x;
};

sjs_class* sjf_class(sjs_class* _this);
sjs_class* sjf_class_destroy(sjs_class* _this);
sjs_class* sjf_global();

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

sjs_class* sjf_class_destroy(sjs_class* _this) {
    _this->x = 2;
    free(_this);
}

sjs_class* sjf_global() {
    sjs_class* c;
    sjs_class* sjv_temp1;
    sjv_temp1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp1->x = 1;
    return c = sjf_class(sjv_temp1);
}

int main() {
    sjf_global();
    return 0;
}
