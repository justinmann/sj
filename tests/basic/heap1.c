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
void sjf_class_destroy(sjs_class* _this);
void sjf_func(sjs_class** _return);
void sjf_global();

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_func(sjs_class** _return) {
    sjs_class* a;
    sjs_class* result2;
    sjs_class* result3;
    sjs_class* sjv_temp1;
    sjs_class* sjv_temp2;

    sjv_temp1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp1->_refCount = 1;
    sjf_class(sjv_temp1, &result2);
    a = result2;
    a->_refCount++;
    sjv_temp2 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp2->_refCount = 1;
    sjf_class(sjv_temp2, &result3);
    a->_refCount--;
    if (a->_refCount == 0) {
        sjf_class_destroy(a);
        free(a);
    }

    a = result3;

    a->_refCount--;
    if (a->_refCount == 0) {
        sjf_class_destroy(a);
        free(a);
    }
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_class_destroy(result2);
        free(result2);
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

    *_return = result3;
}

void sjf_global() {
    sjs_class* b;
    sjs_class* result1;

    sjf_func(&result1);
    b = result1;
    b->_refCount++;

    b->_refCount--;
    if (b->_refCount == 0) {
        sjf_class_destroy(b);
        free(b);
    }
    result1->_refCount--;
    if (result1->_refCount == 0) {
        sjf_class_destroy(result1);
        free(result1);
    }
}

int main() {
    sjf_global();

    return 0;
}
