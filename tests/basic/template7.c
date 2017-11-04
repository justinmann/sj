#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class_i32 sjs_class_i32;

struct td_sjs_class_i32 {
    int _refCount;
};

sjs_class_i32* sjf_class_i32(sjs_class_i32* _this);
void sjf_class_i32_destroy(sjs_class_i32* _this);
int32_t sjf_global();

sjs_class_i32* sjf_class_i32(sjs_class_i32* _this) {
    sjs_class_i32* _retVal;
    _retVal = (_this);
    return _retVal;
}

void sjf_class_i32_destroy(sjs_class_i32* _this) {
    free(_this);
}

int32_t sjf_global() {
    int32_t _retVal;
    sjs_class_i32* c;
    sjs_class_i32 sjd_temp1;
    sjs_class_i32* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    c = sjf_class_i32(sjv_temp1);
    _retVal = (1);
    sjf_class_i32_destroy(sjv_temp1);
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
