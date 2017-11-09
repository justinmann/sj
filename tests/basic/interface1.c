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
void sjf_global(void);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_global(void) {
    sjs_class sjd_temp1;
    sjs_* a;
    sjs_* result1;
    sjs_class* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_class(sjv_temp1, &sjv_temp1);
    result1 = (sjs_*)sjv_temp1;
    a = result1;
    a->_refCount++;
    sjf_class_destroy(&sjd_temp1);
}

int main() {
    sjf_global();

    return 0;
}
