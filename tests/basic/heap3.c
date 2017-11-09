#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_bar sjs_bar;
typedef struct td_sjs_foo sjs_foo;

struct td_sjs_bar {
    int _refCount;
    sjs_foo* f;
};

struct td_sjs_foo {
    int _refCount;
    int32_t x;
};

void sjf_bar(sjs_bar* _this, sjs_bar** _return);
void sjf_bar_destroy(sjs_bar* _this);
void sjf_foo(sjs_foo* _this, sjs_foo** _return);
void sjf_foo_destroy(sjs_foo* _this);
void sjf_func(sjs_bar* b, sjs_foo** _return);
void sjf_global();

void sjf_bar(sjs_bar* _this, sjs_bar** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_bar_destroy(sjs_bar* _this) {
    _this->f->_refCount--;
    if (_this->f->_refCount <= 0) {
        sjf_foo_destroy(_this->f);
        free(_this->f);
    }
}

void sjf_foo(sjs_foo* _this, sjs_foo** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_foo_destroy(sjs_foo* _this) {
}

void sjf_func(sjs_bar* b, sjs_foo** _return) {
    sjs_foo* sjv_temp3;

    sjv_temp3 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_temp3->_refCount = 1;
    sjv_temp3->x = 2;
    sjf_foo(sjv_temp3, &sjv_temp3);
    b->f->_refCount--;
    if (b->f->_refCount <= 0) {
        sjf_foo_destroy(b->f);
        free(b->f);
    }

    b->f = sjv_temp3;

    b->f->_refCount++;

    sjv_temp3->_refCount++;

    sjv_temp3->_refCount--;
    if (sjv_temp3->_refCount <= 0) {
        sjf_foo_destroy(sjv_temp3);
        free(sjv_temp3);
    }

    *_return = sjv_temp3;
}

void sjf_global() {
    sjs_bar sjd_temp1;
    sjs_bar* b;
    sjs_foo* result1;
    sjs_foo* sjv_temp1;
    sjs_bar* sjv_temp2;
    int32_t temp1;

    sjv_temp1 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 1;
    sjf_foo(sjv_temp1, &sjv_temp1);
    sjv_temp2 = &sjd_temp1;
    sjv_temp2->_refCount = 1;
    sjv_temp2->f = sjv_temp1;
    sjv_temp2->f->_refCount++;
    sjf_bar(sjv_temp2, &sjv_temp2);
    b = sjv_temp2;
    b->_refCount++;
    result1 = 0;
    sjf_func(b, &result1);
    temp1 = result1->x;

    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sjf_foo_destroy(result1);
        free(result1);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount <= 0) {
        sjf_foo_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjf_bar_destroy(&sjd_temp1);
}

int main() {
    sjf_global();

    return 0;
}
