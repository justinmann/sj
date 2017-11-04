#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int _refCount;
};

sjs_class* sjf_class(sjs_class* _this);
void sjf_class_destroy(sjs_class* _this);
sjs_class* sjf_func();
sjs_class* sjf_global();

sjs_class* sjf_class(sjs_class* _this) {
    sjs_class* _retVal;
    _retVal = (_this);
    return _retVal;
}

void sjf_class_destroy(sjs_class* _this) {
}

sjs_class* sjf_func() {
    sjs_class* _retVal;
    sjs_class* a;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjs_class* sjv_temp2;
    sjv_temp1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp1->_refCount = 1;
    a = sjf_class(sjv_temp1);
    sjv_temp2 = &sjd_temp1;
    sjv_temp2->_refCount = 1;
    _retVal = (a = sjf_class(sjv_temp2));
    a->_refCount--;
    if (a->_refCount == 0) {
        sjf_class_destroy(a);
        free(a);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount == 0) {
        sjf_class_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjf_class_destroy(sjv_temp2);
    return _retVal;
}

sjs_class* sjf_global() {
    sjs_class* _retVal;
    _retVal = (sjf_func());
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
