#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int _refCount;
};

sjs_class* sjf_class(sjs_class* _this);
int32_t sjf_class_bar(int32_t x);
void sjf_class_destroy(sjs_class* _this);
int32_t sjf_class_foo(int32_t x);
int32_t sjf_global();

sjs_class* sjf_class(sjs_class* _this) {
    _this->_refCount++;

    return _this;
}

int32_t sjf_class_bar(int32_t x) {
    int32_t result7;

    result7 = sjf_class_foo(x);

    return result7;
}

void sjf_class_destroy(sjs_class* _this) {
}

int32_t sjf_class_foo(int32_t x) {
    int32_t ifResult1;
    bool result4;

    result4 = x > 0;
    if (result4) {
        int32_t result5;
        int32_t result6;

        result6 = x - 1;
        result5 = sjf_class_bar(result6);
        ifResult1 = result5;
    } else {
        ifResult1 = 0;
    }

    return ifResult1;
}

int32_t sjf_global() {
    sjs_class* c;
    sjs_class* result2;
    int32_t result3;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    result2 = sjf_class(sjv_temp1);
    c = result2;
    c->_refCount++;
    result3 = sjf_class_foo(4);

    sjf_class_destroy(c);
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_class_destroy(result2);
        free(result2);
    }
    sjf_class_destroy(sjv_temp1);

    return result3;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
