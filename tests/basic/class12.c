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
void sjf_global(int32_t* _return);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_bar(int32_t x, int32_t* _return) {
    int32_t result7;

    sjf_class_foo(x, &result7);

    *_return = result7;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_foo(int32_t x, int32_t* _return) {
    int32_t ifResult1;
    bool result4;

    result4 = x > 0;
    if (result4) {
        int32_t result5;
        int32_t result6;

        result6 = x - 1;
        sjf_class_bar(result6, &result5);
        ifResult1 = result5;
    } else {
        ifResult1 = 0;
    }

    *_return = ifResult1;
}

void sjf_global(int32_t* _return) {
    sjs_class* c;
    sjs_class* result2;
    int32_t result3;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_class(sjv_temp1, &result2);
    c = result2;
    c->_refCount++;
    sjf_class_foo(4, &result3);

    sjf_class_destroy(c);
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_class_destroy(result2);
        free(result2);
    }
    sjf_class_destroy(sjv_temp1);

    *_return = result3;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
