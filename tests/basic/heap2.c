#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_anon_1 sjs_anon_1;
typedef struct td_sjs_class sjs_class;

struct td_sjs_anon_1 {
    int _refCount;
    int32_t x;
};

struct td_sjs_class {
    int _refCount;
    sjs_anon_1* data;
};

sjs_class* sjf_class(sjs_class* _this);
sjs_anon_1* sjf_class_anon_1(sjs_anon_1* _this);
void sjf_class_anon_1_destroy(sjs_anon_1* _this);
void sjf_class_destroy(sjs_class* _this);
sjs_anon_1* sjf_class_get(sjs_class* _parent);
sjs_anon_1* sjf_global();

sjs_class* sjf_class(sjs_class* _this) {
    _this->_refCount++;

    return _this;
}

sjs_anon_1* sjf_class_anon_1(sjs_anon_1* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_class_anon_1_destroy(sjs_anon_1* _this) {
}

void sjf_class_destroy(sjs_class* _this) {
    _this->data->_refCount--;
    if (_this->data->_refCount <= 0) {
        sjf_class_anon_1_destroy(_this->data);
        free(_this->data);
    }
}

sjs_anon_1* sjf_class_get(sjs_class* _parent) {
    sjs_anon_1* temp1;

    temp1 = _parent->data;
    temp1->_refCount++;

    temp1->_refCount--;
    if (temp1->_refCount == 0) {
        sjf_class_anon_1_destroy(temp1);
        free(temp1);
    }

    return temp1;
}

sjs_anon_1* sjf_global() {
    sjs_class* c;
    sjs_anon_1* d;
    sjs_class* result2;
    sjs_anon_1* result3;
    sjs_anon_1* result4;
    sjs_class sjd_temp1;
    sjs_anon_1* sjv_temp1;
    sjs_class* sjv_temp2;

    sjv_temp1 = (sjs_anon_1*)malloc(sizeof(sjs_anon_1));
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 0;
    result3 = sjf_class_anon_1(sjv_temp1);
    sjv_temp2 = &sjd_temp1;
    sjv_temp2->_refCount = 1;
    sjv_temp2->data = result3;
    sjv_temp2->data++;
    result2 = sjf_class(sjv_temp2);
    c = result2;
    c->_refCount++;
    result4 = sjf_class_get(c);
    d = result4;

    sjf_class_destroy(c);
    d->_refCount--;
    if (d->_refCount == 0) {
        sjf_class_anon_1_destroy(d);
        free(d);
    }
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_class_destroy(result2);
        free(result2);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_class_anon_1_destroy(result3);
        free(result3);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount == 0) {
        sjf_class_anon_1_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjf_class_destroy(sjv_temp2);

    return result4;
}

int main() {
    sjs_anon_1* result1;

    result1 = sjf_global();

    return 0;
}
