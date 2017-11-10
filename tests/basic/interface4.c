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
    void (*test)(int32_t _return);
};

struct td_sjs_class {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_test(sjs_class* _parent, int32_t* _return);
void sjf_global(void);
void sji_foo_destroy(sji_foo* _this);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_test(sjs_class* _parent, int32_t* _return) {

    *_return = 5;
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

void sji_foo_destroy(sji_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main() {
    sjf_global();

    return 0;
}
