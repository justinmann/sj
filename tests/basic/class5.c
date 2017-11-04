#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

sjs_class* sjf_class(sjs_class* _this);
void sjf_class_destroy(sjs_class* _this);
int32_t sjf_global();

sjs_class* sjf_class(sjs_class* _this) {
    sjs_class* _retVal;
    _retVal = (_this);
    return _retVal;
}

void sjf_class_destroy(sjs_class* _this) {
}

int32_t sjf_global() {
    int32_t _retVal;
    sjs_class* c;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 0;
    c = sjf_class(sjv_temp1);
    _retVal = (c->x);
    sjf_class_destroy(sjv_temp1);
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
