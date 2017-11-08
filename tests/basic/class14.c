#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int _refCount;
    int32_t m;
};

void sjf_class(sjs_class* _this, int32_t* _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_inner(sjs_class* _parent, int32_t* _return);
void sjf_global(int32_t* _return);

void sjf_class(sjs_class* _this, int32_t* _return) {
    int32_t result3;

    _this->m = 1;
    sjf_class_inner(_this, &result3);

    *_return = result3;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_inner(sjs_class* _parent, int32_t* _return) {
    int32_t temp1;

    temp1 = _parent->m;

    *_return = temp1;
}

void sjf_global(int32_t* _return) {
    int32_t result2;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_class(sjv_temp1, &result2);

    sjf_class_destroy(sjv_temp1);

    *_return = result2;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
