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
    int32_t y;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_global(void);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_global(void) {
    sjs_class sjd_temp1;
    sjs_class* c;
    int32_t result1;
    sjs_class* sjv_temp1;
    int32_t temp1;
    int32_t temp2;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->x = 1;
    sjv_temp1->y = 2;
    sjf_class(sjv_temp1, &sjv_temp1);
    c = sjv_temp1;
    c->_refCount++;
    temp1 = c->x;
    temp2 = c->y;
    result1 = temp1 + temp2;
    sjf_class_destroy(&sjd_temp1);
}

int main() {
    sjf_global();

    return 0;
}
