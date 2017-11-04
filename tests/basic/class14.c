#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
    int32_t m;
};

int32_t sjf_class(sjs_class* _this);
int32_t sjf_class_destroy(sjs_class* _this);
int32_t sjf_class_inner(sjs_class* _parent);
int32_t sjf_global();

int32_t sjf_class(sjs_class* _this) {
    _this->m = 1;
    return sjf_class_inner((_this));
}

int32_t sjf_class_destroy(sjs_class* _this) {
    free(_this);
}

int32_t sjf_class_inner(sjs_class* _parent) {
    return _parent->m;
}

int32_t sjf_global() {
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    sjf_class_destroy(sjv_temp1);
    return sjf_class(sjv_temp1);
}

int main() {
    sjf_global();
    return 0;
}
