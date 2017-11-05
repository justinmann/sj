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
    return _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

sjs_class* sjf_func() {
    sjs_class* a;
    sjs_class* result3;
    sjs_class* result4;
    sjs_class* sjv_temp1;
    sjs_class* sjv_temp2;

    sjv_temp1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp1->_refCount = 1;
    result3 = sjf_class(sjv_temp1);
    a = result3;
    a->_refCount++;
    sjv_temp2 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp2->_refCount = 1;
    result4 = sjf_class(sjv_temp2);
    a = result4;
    a->_refCount++;

    a->_refCount--;
    if (a->_refCount == 0) {
        sjf_class_destroy(a);
        free(a);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_class_destroy(result3);
        free(result3);
    }
    result4->_refCount--;
    if (result4->_refCount == 0) {
        sjf_class_destroy(result4);
        free(result4);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount == 0) {
        sjf_class_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjv_temp2->_refCount--;
    if (sjv_temp2->_refCount == 0) {
        sjf_class_destroy(sjv_temp2);
        free(sjv_temp2);
    }

    return result4;
}

sjs_class* sjf_global() {
    sjs_class* result2;

    result2 = sjf_func();

    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_class_destroy(result2);
        free(result2);
    }

    return result2;
}

int main() {
    sjs_class* result1;

    result1 = sjf_global();

    result1->_refCount--;
    if (result1->_refCount == 0) {
        sjf_class_destroy(result1);
        free(result1);
    }

    return 0;
}
