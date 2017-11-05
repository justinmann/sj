#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int _refCount;
    int32_t m;
};

int32_t sjf_class(sjs_class* _this);
void sjf_class_destroy(sjs_class* _this);
int32_t sjf_class_inner(sjs_class* _parent);
int32_t sjf_global();

int32_t sjf_class(sjs_class* _this) {
    int32_t result3;

    _this->m = 1;
    result3 = sjf_class_inner(_this);

    return result3;
}

void sjf_class_destroy(sjs_class* _this) {
}

int32_t sjf_class_inner(sjs_class* _parent) {
    int32_t temp1;

    temp1 = _parent->m;

    return temp1;
}

int32_t sjf_global() {
    int32_t result2;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    result2 = sjf_class(sjv_temp1);

    sjf_class_destroy(sjv_temp1);

    return result2;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
