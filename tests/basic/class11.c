#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define sjs_class_typeId 1
#define sjs_object_typeId 2

typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_object sjs_object;

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_func(sjs_class** _return);
void sjf_global(void);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_func(sjs_class** _return) {
    sjs_class* sjv_temp1;

    sjv_temp1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 1;
    sjf_class(sjv_temp1, &sjv_temp1);
    sjv_temp1->_refCount++;

    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount <= 0) {
        sjf_class_destroy(sjv_temp1);
        free(sjv_temp1);
    }

    *_return = sjv_temp1;
}

void sjf_global(void) {
    sjs_class* result1;
    int32_t temp1;

    result1 = 0;
    sjf_func(&result1);
    temp1 = result1->x;

    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sjf_class_destroy(result1);
        free(result1);
    }
}

int main() {
    sjf_global();

    return 0;
}
