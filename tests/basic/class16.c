#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_aa sjs_aa;

struct td_sjs_a {
    int _refCount;
    int32_t x;
    sjs_aa* b;
};

struct td_sjs_aa {
    int _refCount;
    sjs_a* _parent;
};

sjs_a* sjf_a(sjs_a* _this);
sjs_aa* sjf_a_aa(sjs_aa* _this);
int32_t sjf_a_aa_c(sjs_aa* _parent);
void sjf_a_aa_destroy(sjs_aa* _this);
void sjf_a_destroy(sjs_a* _this);
int32_t sjf_global();

sjs_a* sjf_a(sjs_a* _this) {
    sjs_a* _retVal;
    _retVal = (_this);
    return _retVal;
}

sjs_aa* sjf_a_aa(sjs_aa* _this) {
    sjs_aa* _retVal;
    _retVal = (_this);
    return _retVal;
}

int32_t sjf_a_aa_c(sjs_aa* _parent) {
    int32_t _retVal;
    _retVal = (_parent->_parent->x);
    return _retVal;
}

void sjf_a_aa_destroy(sjs_aa* _this) {
}

void sjf_a_destroy(sjs_a* _this) {
    sjf_a_aa_destroy(_this->b);
}

int32_t sjf_global() {
    int32_t _retVal;
    sjs_a* a;
    sjs_aa* d;
    sjs_aa sjd_temp1;
    sjs_a sjd_temp2;
    sjs_aa* sjv_temp1;
    sjs_a* sjv_temp2;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->x = 1;
    sjv_temp2->b = sjf_a_aa(sjv_temp1);
    a = sjf_a(sjv_temp2);
    sjf_a_aa_c((a->b));
    d = a->b;
    _retVal = (sjf_a_aa_c((d)));
    sjf_a_aa_destroy(sjv_temp1);
    sjf_a_destroy(sjv_temp2);
    return _retVal;
}

int main() {
    sjf_global();
    return 0;
}
