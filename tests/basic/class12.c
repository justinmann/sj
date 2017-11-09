#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int _refCount;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_bar(int32_t x, int32_t* _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_foo(int32_t x, int32_t* _return);
void sjf_global(void);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_bar(int32_t x, int32_t* _return) {
    int32_t result5;

    result5 = 0;
    sjf_class_foo(x, &result5);

    *_return = result5;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_foo(int32_t x, int32_t* _return) {
    int32_t ifResult1;
    bool result2;

    result2 = x > 0;
    if (result2) {
        int32_t result3;
        int32_t result4;

        result3 = 0;
        result4 = x - 1;
        sjf_class_bar(result4, &result3);
        ifResult1 = result3;
    } else {
        ifResult1 = 0;
    }

    *_return = ifResult1;
}

void sjf_global(void) {
    sjs_class sjd_temp1;
    sjs_class* c;
    int32_t result1;
    sjs_class* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_class(sjv_temp1, &sjv_temp1);
    c = sjv_temp1;
    c->_refCount++;
    result1 = 0;
    sjf_class_foo(4, &result1);
    sjf_class_destroy(&sjd_temp1);
}

int main() {
    sjf_global();

    return 0;
}
