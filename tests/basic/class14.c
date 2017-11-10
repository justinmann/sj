#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_object sjs_object;

int sjs_class_typeId = 1;
int sjs_object_typeId = 2;

struct td_sjs_class {
    int _refCount;
    int32_t m;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class(sjs_class* _this, int32_t* _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_inner(sjs_class* _parent, int32_t* _return);
void sjf_global(void);

void sjf_class(sjs_class* _this, int32_t* _return) {
    int32_t result2;

    _this->m = 1;
    result2 = 0;
    sjf_class_inner(_this, &result2);

    *_return = result2;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_inner(sjs_class* _parent, int32_t* _return) {
    int32_t temp1;

    temp1 = _parent->m;

    *_return = temp1;
}

void sjf_global(void) {
    sjs_class sjd_temp1;
    int32_t result1;
    sjs_class* sjv_temp1;

    result1 = 0;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_class(sjv_temp1, &result1);
    sjf_class_destroy(&sjd_temp1);
}

int main() {
    sjf_global();

    return 0;
}
