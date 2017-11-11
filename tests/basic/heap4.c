#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define sjs_a_typeId 1
#define sjs_b_typeId 2
#define sjs_c_typeId 3
#define sjs_object_typeId 4

typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_b sjs_b;
typedef struct td_sjs_c sjs_c;
typedef struct td_sjs_object sjs_object;

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

struct td_sjs_object {
    int _refCount;
};

void sjf_a(sjs_a* _this, sjs_a** _return);
void sjf_a_destroy(sjs_a* _this);
void sjf_b(sjs_b* _this, sjs_b** _return);
void sjf_b_destroy(sjs_b* _this);
void sjf_c(sjs_c* _this, sjs_c** _return);
void sjf_c_destroy(sjs_c* _this);
void sjf_global(void);

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
    sjf_a_destroy(_this->a);
}

void sjf_c(sjs_c* _this, sjs_c** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_c_destroy(sjs_c* _this) {
    sjf_b_destroy(_this->b);
}

void sjf_global(void) {
    sjs_a sjd_temp1;
    sjs_b sjd_temp2;
    sjs_c sjd_temp3;
    sjs_a* sjv_temp1;
    sjs_b* sjv_temp2;
    sjs_c* sjv_temp3;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_a(sjv_temp1, &sjv_temp1);
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->a = sjv_temp1;
    sjv_temp2->a->_refCount++;
    sjf_b(sjv_temp2, &sjv_temp2);
    sjv_temp3 = &sjd_temp3;
    sjv_temp3->_refCount = 1;
    sjv_temp3->b = sjv_temp2;
    sjv_temp3->b->_refCount++;
    sjf_c(sjv_temp3, &sjv_temp3);
    sjf_a_destroy(&sjd_temp1);
    sjf_b_destroy(&sjd_temp2);
    sjf_c_destroy(&sjd_temp3);
}

int main() {
    sjf_global();

    return 0;
}
