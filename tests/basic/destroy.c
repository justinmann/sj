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
void sjf_global(sjs_class** _return);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_destroy(sjs_class* _this) {
    _this->x = 2;
}

void sjf_global(sjs_class** _return) {
    sjs_class* c;
    sjs_class* result2;
    sjs_class* sjv_temp1;

    sjv_temp1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 1;
    sjf_class(sjv_temp1, &result2);
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

    *_return = result2;
}

int main() {
    sjs_class* result1;

    sjf_global(&result1);

    return 0;
}
