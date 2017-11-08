#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_b sjs_b;
typedef struct td_sjs_c sjs_c;

struct td_sjs_a {
    int _refCount;
};

struct td_sjs_b {
    int _refCount;
    sjs_a* a;
};

struct td_sjs_c {
    int _refCount;
    sjs_b* b;
};

void sjf_a(sjs_a* _this, sjs_a** _return);
void sjf_a_destroy(sjs_a* _this);
void sjf_b(sjs_b* _this, sjs_b** _return);
void sjf_b_destroy(sjs_b* _this);
void sjf_c(sjs_c* _this, sjs_c** _return);
void sjf_c_destroy(sjs_c* _this);
void sjf_global(sjs_c** _return);

void sjf_a(sjs_a* _this, sjs_a** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_a_destroy(sjs_a* _this) {
}

void sjf_b(sjs_b* _this, sjs_b** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_b_destroy(sjs_b* _this) {
    _this->a->_refCount--;
    if (_this->a->_refCount == 0) {
        sjf_a_destroy(_this->a);
        free(_this->a);
    }
}

void sjf_c(sjs_c* _this, sjs_c** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_c_destroy(sjs_c* _this) {
    _this->b->_refCount--;
    if (_this->b->_refCount == 0) {
        sjf_b_destroy(_this->b);
        free(_this->b);
    }
}

void sjf_global(sjs_c** _return) {
    sjs_c* result2;
    sjs_b* result3;
    sjs_a* result4;
    sjs_a* sjv_temp1;
    sjs_b* sjv_temp2;
    sjs_c* sjv_temp3;

    sjv_temp1 = (sjs_a*)malloc(sizeof(sjs_a));
    sjv_temp1->_refCount = 1;
    sjf_a(sjv_temp1, &result4);
    sjv_temp2 = (sjs_b*)malloc(sizeof(sjs_b));
    sjv_temp2->_refCount = 1;
    sjv_temp2->a = result4;
    sjv_temp2->a->_refCount++;
    sjf_b(sjv_temp2, &result3);
    sjv_temp3 = (sjs_c*)malloc(sizeof(sjs_c));
    sjv_temp3->_refCount = 1;
    sjv_temp3->b = result3;
    sjv_temp3->b->_refCount++;
    sjf_c(sjv_temp3, &result2);

    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_b_destroy(result3);
        free(result3);
    }
    result4->_refCount--;
    if (result4->_refCount == 0) {
        sjf_a_destroy(result4);
        free(result4);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount == 0) {
        sjf_a_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjv_temp2->_refCount--;
    if (sjv_temp2->_refCount == 0) {
        sjf_b_destroy(sjv_temp2);
        free(sjv_temp2);
    }
    sjv_temp3->_refCount--;
    if (sjv_temp3->_refCount == 0) {
        sjf_c_destroy(sjv_temp3);
        free(sjv_temp3);
    }

    *_return = result2;
}

int main() {
    sjs_c* result1;

    sjf_global(&result1);

    return 0;
}
