#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_aa sjs_aa;

struct td_sjs_a {
    int32_t x;
    sjs_aa* b;
};

struct td_sjs_aa {
    sjs_a* _parent;
};

sjs_a* sjf_a(sjs_a* _this);
sjs_aa* sjf_a_aa(sjs_aa* _this);
int32_t sjf_a_aa_c(sjs_aa* _parent);
int32_t sjf_global();

sjs_a* sjf_a(sjs_a* _this) {
    return _this;
}

sjs_aa* sjf_a_aa(sjs_aa* _this) {
    return _this;
}

int32_t sjf_a_aa_c(sjs_aa* _parent) {
    return _parent->_parent->x;
}

int32_t sjf_global() {
    sjs_a* a;
    sjs_aa* d;
    sjs_aa sjd_temp1;
    sjs_a sjd_temp2;
    sjs_aa* sjv_temp1;
    sjs_a* sjv_temp2;
    sjv_temp1 = &sjd_temp1;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->x = 1;
    sjv_temp2->b = sjf_a_aa(sjv_temp1);
    a = sjf_a(sjv_temp2);
    sjf_a_aa_c((a->b));
    d = a->b;
    return sjf_a_aa_c((d));
}

int main() {
    sjf_global();
    return 0;
}
