#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_foo sjs_foo;

struct td_sjs_foo {
    int _refCount;
};

void sjf_bar(sjs_foo** _return);
void sjf_foo(sjs_foo* _this, sjs_foo** _return);
void sjf_foo_destroy(sjs_foo* _this);
void sjf_global();

void sjf_bar(sjs_foo** _return) {
    sjs_foo* sjv_temp1;

    sjv_temp1 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_temp1->_refCount = 1;
    sjf_foo(sjv_temp1, &sjv_temp1);
    sjv_temp1->_refCount++;

    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount <= 0) {
        sjf_foo_destroy(sjv_temp1);
        free(sjv_temp1);
    }

    *_return = sjv_temp1;
}

void sjf_foo(sjs_foo* _this, sjs_foo** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_foo_destroy(sjs_foo* _this) {
}

void sjf_global() {
    sjs_foo* a;
    sjs_foo* result1;

    result1 = 0;
    sjf_bar(&result1);
    a = result1;
    a->_refCount++;

    a->_refCount--;
    if (a->_refCount <= 0) {
        sjf_foo_destroy(a);
        free(a);
    }
    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sjf_foo_destroy(result1);
        free(result1);
    }
}

int main() {
    sjf_global();

    return 0;
}
