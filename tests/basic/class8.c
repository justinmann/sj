#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int32_t x;
    int32_t y;
};

sjs_class* sjf_class(sjs_class* _this);
sjs_class* sjf_class_destroy(sjs_class* _this);
int32_t sjf_global();

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

sjs_class* sjf_class_destroy(sjs_class* _this) {
    free(_this);
}

int32_t sjf_global() {
    sjs_class* c;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->x = 1;
    sjv_temp1->y = 2;
    c = sjf_class(sjv_temp1);
    sjf_class_destroy(sjv_temp1);
    return (c->x) + (c->y);
}

int main() {
    sjf_global();
    return 0;
}
