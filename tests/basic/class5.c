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

    return _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

int32_t sjf_global() {
    sjs_class* c;
    sjs_class* result2;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    int32_t temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 0;
    result2 = sjf_class(sjv_temp1);
    c = result2;
    c->_refCount++;
    temp1 = c->x;

    sjf_class_destroy(c);
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_class_destroy(result2);
        free(result2);
    }
    sjf_class_destroy(sjv_temp1);

    return temp1;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
