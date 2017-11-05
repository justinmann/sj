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
sjs_class* sjf_func();
int32_t sjf_global();

sjs_class* sjf_class(sjs_class* _this) {

    return _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

sjs_class* sjf_func() {
    sjs_class* result3;
    sjs_class* sjv_temp1;

    sjv_temp1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 1;
    result3 = sjf_class(sjv_temp1);

    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_class_destroy(result3);
        free(result3);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount == 0) {
        sjf_class_destroy(sjv_temp1);
        free(sjv_temp1);
    }

    return result3;
}

int32_t sjf_global() {
    sjs_class* result2;
    int32_t temp1;

    result2 = sjf_func();
    temp1 = result2->x;

    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_class_destroy(result2);
        free(result2);
    }

    return temp1;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
