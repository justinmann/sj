#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_global sjs_global;
typedef struct td_sjs_object sjs_object;

int sjs_anon1_typeId = 1;
int sjs_class_typeId = 2;
int sjs_global_typeId = 3;
int sjs_object_typeId = 4;

struct td_sjs_anon1 {
    int _refCount;
    int32_t test;
};

struct td_sjs_class {
    int _refCount;
    sjs_global* _parent;
};

struct td_sjs_global {
    int _refCount;
    sjs_anon1* math;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_sub(sjs_anon1* _parent, int32_t x, int32_t y, int32_t* _return);
void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return);
void sjf_global(sjs_global* _this);
void sjf_global_destroy(sjs_global* _this);

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_sub(sjs_anon1* _parent, int32_t x, int32_t y, int32_t* _return) {
    int32_t result5;
    int32_t result6;
    int32_t temp3;

    result5 = x - y;
    temp3 = _parent->test;
    result6 = result5 - temp3;

    *_return = result6;
}

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_bar(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t result7;

    result7 = 0;
    sjf_class_foo(_parent, x, &result7);

    *_return = result7;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_foo(sjs_class* _parent, int32_t x, int32_t* _return) {
    int32_t ifResult1;
    bool result2;

    result2 = x > 0;
    if (result2) {
        int32_t result3;
        int32_t result4;
        sjs_global* temp1;
        sjs_anon1* temp2;

        result3 = 0;
        temp1 = _parent->_parent;
        temp2 = temp1->math;
        result4 = 0;
        sjf_anon1_sub(temp2, x, 1, &result4);
        sjf_class_bar(_parent, result4, &result3);
        ifResult1 = result3;

        temp2->_refCount--;
        if (temp2->_refCount <= 0) {
            sjf_anon1_destroy(temp2);
            free(temp2);
        }
    } else {
        ifResult1 = 0;
    }

    *_return = ifResult1;
}

void sjf_global(sjs_global* _this) {
    sjs_class sjd_temp1;
    sjs_class* c;
    int32_t result1;
    sjs_anon1* sjv_temp1;
    sjs_class* sjv_temp2;

    sjv_temp1 = (sjs_anon1*)malloc(sizeof(sjs_anon1));
    sjv_temp1->_refCount = 1;
    sjv_temp1->test = 1;
    sjf_anon1(sjv_temp1, &sjv_temp1);
    _this->math = sjv_temp1;
    _this->math->_refCount++;
    sjv_temp2 = &sjd_temp1;
    sjv_temp2->_refCount = 1;
    sjf_class(sjv_temp2, &sjv_temp2);
    c = sjv_temp2;
    c->_refCount++;
    result1 = 0;
    sjf_class_foo(c, 4, &result1);

    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount <= 0) {
        sjf_anon1_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjf_class_destroy(&sjd_temp1);
}

void sjf_global_destroy(sjs_global* _this) {
}

int main() {
    sjs_global sjd_temp2;
    sjs_global* sjv_temp3;

    sjv_temp3 = &sjd_temp2;
    sjv_temp3->_refCount = 1;
    sjf_global(sjv_temp3);
    sjf_global_destroy(&sjd_temp2);

    return 0;
}
