#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct td_sjs_class sjs_class;

struct td_sjs_class {
};

sjs_class* sjf_class(sjs_class* _this);
int32_t sjf_class_bar(int32_t x);
sjs_class* sjf_class_destroy(sjs_class* _this);
int32_t sjf_class_foo(int32_t x);
int32_t sjf_global();

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int32_t sjf_class_bar(int32_t x) {
    return sjf_class_foo((x));
}

sjs_class* sjf_class_destroy(sjs_class* _this) {
    free(_this);
}

int32_t sjf_class_foo(int32_t x) {
    int32_t ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_class_bar(((x) - (1)));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int32_t sjf_global() {
    sjs_class* c;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    c = sjf_class(sjv_temp1);
    return sjf_class_foo((4));
}

int main() {
    sjf_global();
    return 0;
}
