#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_aa sjs_aa;
typedef struct td_sjs_object sjs_object;

int sjs_a_typeId = 1;
int sjs_aa_typeId = 2;
int sjs_object_typeId = 3;

struct td_sjs_a {
    int _refCount;
    int32_t x;
    sjs_aa* b;
};

struct td_sjs_aa {
    int _refCount;
    sjs_a* _parent;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_a(sjs_a* _this, sjs_a** _return);
void sjf_a_aa(sjs_aa* _this, sjs_aa** _return);
void sjf_a_aa_c(sjs_aa* _parent, int32_t* _return);
void sjf_a_aa_destroy(sjs_aa* _this);
void sjf_a_destroy(sjs_a* _this);
void sjf_global(void);

void sjf_a(sjs_a* _this, sjs_a** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_a_aa(sjs_aa* _this, sjs_aa** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_a_aa_c(sjs_aa* _parent, int32_t* _return) {
    sjs_a* temp2;
    int32_t temp3;

    temp2 = _parent->_parent;
    temp3 = temp2->x;

    *_return = temp3;
}

void sjf_a_aa_destroy(sjs_aa* _this) {
}

void sjf_a_destroy(sjs_a* _this) {
    sjf_a_aa_destroy(_this->b);
}

void sjf_global(void) {
    sjs_aa sjd_temp1;
    sjs_a sjd_temp2;
    sjs_a* a;
    sjs_aa* d;
    int32_t result1;
    int32_t result2;
    sjs_aa* sjv_temp1;
    sjs_a* sjv_temp2;
    sjs_aa* temp1;
    sjs_aa* temp4;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_a_aa(sjv_temp1, &sjv_temp1);
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->x = 1;
    sjv_temp2->b = sjv_temp1;
    sjv_temp2->b->_refCount++;
    sjf_a(sjv_temp2, &sjv_temp2);
    a = sjv_temp2;
    a->_refCount++;
    temp1 = a->b;
    result1 = 0;
    sjf_a_aa_c(temp1, &result1);
    temp4 = a->b;
    d = temp4;
    d->_refCount++;
    result2 = 0;
    sjf_a_aa_c(d, &result2);
    sjf_a_aa_destroy(&sjd_temp1);
    sjf_a_destroy(&sjd_temp2);
}

int main() {
    sjf_global();

    return 0;
}
