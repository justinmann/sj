#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_object sjs_object;

int sji_foo_typeId = 1;
int sjs_class_typeId = 2;
int sjs_object_typeId = 3;

struct td_sji_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
};

struct td_sjs_class {
    int _refCount;
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
    sji_foo* a;
    sji_foo* result1;
    sjs_class* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_class(sjv_temp1, &sjv_temp1);
    result1 = (sji_foo*)sjv_temp1;
    a = result1;
    a->_refCount++;
    sjf_class_destroy(&sjd_temp1);
}

int main() {
    sjf_global();

    return 0;
}
