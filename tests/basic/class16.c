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
    return _this;
}

sjs_aa* sjf_a_aa(sjs_aa* _this) {
    return _this;
}

int32_t sjf_a_aa_c(sjs_aa* _parent) {
    sjs_a* temp2;
    int32_t temp3;
    temp2 = _parent->_parent;
    temp3 = temp2->x;
    sjf_a_destroy(temp2);
    return temp3;
}

void sjf_a_aa_destroy(sjs_aa* _this) {
}

void sjf_a_destroy(sjs_a* _this) {
    sjf_a_aa_destroy(_this->b);
}

int32_t sjf_global() {
    sjs_a* a;
    sjs_aa* d;
    sjs_a* result2;
    sjs_aa* result3;
    int32_t result4;
    int32_t result5;
    sjs_aa sjd_temp1;
    sjs_a sjd_temp2;
    sjs_aa* sjv_temp1;
    sjs_a* sjv_temp2;
    sjs_aa* temp1;
    sjs_aa* temp4;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    result3 = sjf_a_aa(sjv_temp1);
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->x = 1;
    sjv_temp2->b = result3;
    result2 = sjf_a(sjv_temp2);
    a = result2;
    temp1 = a->b;
    result4 = sjf_a_aa_c(temp1);
    temp4 = a->b;
    d = temp4;
    result5 = sjf_a_aa_c(d);
    sjf_a_destroy(a);
    sjf_a_aa_destroy(d);
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_a_destroy(result2);
        free(result2);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_a_aa_destroy(result3);
        free(result3);
    }
    sjf_a_aa_destroy(sjv_temp1);
    sjf_a_destroy(sjv_temp2);
    sjf_a_aa_destroy(temp1);
    sjf_a_aa_destroy(temp4);
    return result5;
}

int main() {
    int32_t result1;
    result1 = sjf_global();
    return 0;
}
