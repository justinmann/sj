#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_func(sjs_class* _parent, int32_t* _return);
void sjf_global(int32_t* _return);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_func(sjs_class* _parent, int32_t* _return) {
    int32_t temp1;

    temp1 = _parent->x;

    *_return = temp1;
}

void sjf_global(int32_t* _return) {
    sjs_class* c;
    sjs_class* result2;
    int32_t result3;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 1;
    sjf_class(sjv_temp1, &result2);
    c = result2;
    c->_refCount++;
    sjf_class_func(c, &result3);

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
