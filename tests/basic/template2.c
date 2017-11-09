#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_class_i32 sjs_class_i32;

struct td_sjs_class_i32 {
    int _refCount;
    int32_t x;
};

void sjf_class_i32(sjs_class_i32* _this, sjs_class_i32** _return);
void sjf_class_i32_destroy(sjs_class_i32* _this);
void sjf_global(void);

void sjf_class_i32(sjs_class_i32* _this, sjs_class_i32** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_i32_destroy(sjs_class_i32* _this) {
}

void sjf_global(void) {
    sjs_class_i32 sjd_temp1;
    sjs_class_i32* c;
    sjs_class_i32* sjv_temp1;
    int32_t temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 1;
    sjf_class_i32(sjv_temp1, &sjv_temp1);
    c = sjv_temp1;
    c->_refCount++;
    temp1 = c->x;
    sjf_class_i32_destroy(&sjd_temp1);
}

int main() {
    sjf_global();

    return 0;
}
