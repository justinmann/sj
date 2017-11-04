#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct td_sjs_class_i32 sjs_class_i32;

struct td_sjs_class_i32 {
    int32_t x;
};

sjs_class_i32* sjf_class_i32(sjs_class_i32* _this);
sjs_class_i32* sjf_class_i32_destroy(sjs_class_i32* _this);
int32_t sjf_global();

sjs_class_i32* sjf_class_i32(sjs_class_i32* _this) {
    return _this;
}

sjs_class_i32* sjf_class_i32_destroy(sjs_class_i32* _this) {
    free(_this);
}

int32_t sjf_global() {
    sjs_class_i32* c;
    sjs_class_i32 sjd_temp1;
    sjs_class_i32* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->x = 1;
    c = sjf_class_i32(sjv_temp1);
    sjf_class_i32_destroy(sjv_temp1);
    return c->x;
}

int main() {
    sjf_global();
    return 0;
}
