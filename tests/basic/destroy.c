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
sjs_class* sjf_global();

sjs_class* sjf_class(sjs_class* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_class_destroy(sjs_class* _this) {
    _this->x = 2;
}

sjs_class* sjf_global() {
    sjs_class* c;
    sjs_class* result2;
    sjs_class* sjv_temp1;

    sjv_temp1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 1;
    result2 = sjf_class(sjv_temp1);
    c = result2;

    c->_refCount--;
    if (c->_refCount == 0) {
        sjf_class_destroy(c);
        free(c);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount == 0) {
        sjf_class_destroy(sjv_temp1);
        free(sjv_temp1);
    }

    return result2;
}

int main() {
    sjs_class* result1;

    result1 = sjf_global();

    return 0;
}
