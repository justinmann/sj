#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define sji_foo_typeId 1
#define sjs_class_typeId 2
#define sjs_object_typeId 3

typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_object sjs_object;

struct td_sji_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test)(sjs_object* _parent, int32_t* _return);
};

struct td_sjs_class {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId);
sji_foo* sjf_class_as_sji_foo(sjs_class* _this);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_test(sjs_class* _parent, int32_t* _return);
void sjf_global(void);
void sji_foo_destroy(sji_foo* _this);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId) {
    switch (typeId) {
        case sji_foo_typeId: return sjf_class_as_sji_foo(_this);
    }

    return 0;
}

sji_foo* sjf_class_as_sji_foo(sjs_class* _this) {
    sji_foo* _interface = (sji_foo*)malloc(sizeof(sji_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = sjf_class_destroy;
    _interface->asInterface = sjf_class_asInterface;
    _interface->test = sjf_class_test;
    return _interface;
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
    int32_t result2;
    sjs_class* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_class(sjv_temp1, &sjv_temp1);
    result1 = sjf_class_as_sji_foo(sjv_temp1);
    a = result1;
    a->_refCount++;
    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sji_foo_destroy(result1);
        free(result1);
    }

    a->test(a->_parent, &result2);

    a->_refCount--;
    if (a->_refCount <= 0) {
        sji_foo_destroy(a);
        free(a);
    }
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