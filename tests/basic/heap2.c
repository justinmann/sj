#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_class sjs_class;

struct td_sjs_anon1 {
    int _refCount;
    int32_t x;
};

struct td_sjs_class {
    int _refCount;
    sjs_anon1* data;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_anon1(sjs_anon1* _this, sjs_anon1** _return);
void sjf_class_anon1_destroy(sjs_anon1* _this);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_get(sjs_class* _parent, sjs_anon1** _return);
void sjf_global(void);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_anon1(sjs_anon1* _this, sjs_anon1** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_anon1_destroy(sjs_anon1* _this) {
}

void sjf_class_destroy(sjs_class* _this) {
    _this->data->_refCount--;
    if (_this->data->_refCount <= 0) {
        sjf_class_anon1_destroy(_this->data);
        free(_this->data);
    }
}

void sjf_class_get(sjs_class* _parent, sjs_anon1** _return) {
    sjs_anon1* temp1;

    temp1 = _parent->data;
    temp1->_refCount++;

    temp1->_refCount--;
    if (temp1->_refCount <= 0) {
        sjf_class_anon1_destroy(temp1);
        free(temp1);
    }

    *_return = temp1;
}

void sjf_global(void) {
    sjs_class sjd_temp1;
    sjs_class* c;
    sjs_anon1* d;
    sjs_anon1* result1;
    sjs_anon1* sjv_temp1;
    sjs_class* sjv_temp2;

    sjv_temp1 = (sjs_anon1*)malloc(sizeof(sjs_anon1));
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 0;
    sjf_class_anon1(sjv_temp1, &sjv_temp1);
    sjv_temp2 = &sjd_temp1;
    sjv_temp2->_refCount = 1;
    sjv_temp2->data = sjv_temp1;
    sjv_temp2->data->_refCount++;
    sjf_class(sjv_temp2, &sjv_temp2);
    c = sjv_temp2;
    c->_refCount++;
    result1 = 0;
    sjf_class_get(c, &result1);
    d = result1;
    d->_refCount++;

    d->_refCount--;
    if (d->_refCount <= 0) {
        sjf_class_anon1_destroy(d);
        free(d);
    }
    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sjf_class_anon1_destroy(result1);
        free(result1);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount <= 0) {
        sjf_class_anon1_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjf_class_destroy(&sjd_temp1);
}

int main() {
    sjf_global();

    return 0;
}
