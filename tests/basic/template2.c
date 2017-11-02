#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct td_sjs_class_int sjs_class_int;

struct td_sjs_class_int {
    int x;
};

sjs_class_int* sjf_class_int(sjs_class_int* _this);
int sjf_global();

sjs_class_int* sjf_class_int(sjs_class_int* _this) {
    return _this;
}

int sjf_global() {
    sjs_class_int* c;
    sjs_class_int sjd_temp1;
    sjs_class_int* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->x = 1;
    c = sjf_class_int(sjv_temp1);
    return c->x;
}

int main() {
    sjf_global();
    return 0;
}
