#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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

sjs_bar* sjf_bar(sjs_bar* _this);
void sjf_bar_destroy(sjs_bar* _this);
sjs_foo* sjf_foo(sjs_foo* _this);
void sjf_foo_destroy(sjs_foo* _this);
sjs_foo* sjf_func(sjs_bar* b);
int32_t sjf_global();

sjs_bar* sjf_bar(sjs_bar* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_bar_destroy(sjs_bar* _this) {
    _this->f->_refCount--;
    if (_this->f->_refCount <= 0) {
        sjf_foo_destroy(_this->f);
        free(_this->f);
    }
}

sjs_foo* sjf_foo(sjs_foo* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_foo_destroy(sjs_foo* _this) {
}

sjs_foo* sjf_func(sjs_bar* b) {
    sjs_foo* result5;
    sjs_foo* sjv_temp3;

    sjv_temp3 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_temp3->_refCount = 1;
    sjv_temp3->x = 2;
    result5 = sjf_foo(sjv_temp3);
    b->f->_refCount--;
    if (b->f->_refCount == 0) {
        sjf_foo_destroy(b->f);
        free(b->f);
    }

    b->f = result5;

    sjv_temp3->_refCount--;
    if (sjv_temp3->_refCount == 0) {
        sjf_foo_destroy(sjv_temp3);
        free(sjv_temp3);
    }

    return result5;
}

int32_t sjf_global() {
    sjs_bar* b;
    sjs_bar* result2;
    sjs_foo* result3;
    sjs_foo* result4;
    sjs_bar sjd_temp1;
    sjs_foo* sjv_temp1;
    sjs_bar* sjv_temp2;
    int32_t temp1;

    sjv_temp1 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 1;
    result3 = sjf_foo(sjv_temp1);
    sjv_temp2 = &sjd_temp1;
    sjv_temp2->_refCount = 1;
    sjv_temp2->f = result3;
    sjv_temp2->f++;
    result2 = sjf_bar(sjv_temp2);
    b = result2;
    b->_refCount++;
    result4 = sjf_func(b);
    temp1 = result4->x;

    sjf_bar_destroy(b);
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_bar_destroy(result2);
        free(result2);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_foo_destroy(result3);
        free(result3);
    }
    result4->_refCount--;
    if (result4->_refCount == 0) {
        sjf_foo_destroy(result4);
        free(result4);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount == 0) {
        sjf_foo_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjf_bar_destroy(sjv_temp2);

    return temp1;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}
