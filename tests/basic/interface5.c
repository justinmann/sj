#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_class_i32 sjs_class_i32;
typedef struct td_sjs_object sjs_object;

int sji_foo_typeId = 1;
int sjs_class_i32_typeId = 2;
int sjs_object_typeId = 3;

struct td_sji_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    void (*test)(sjs_object* _parent, int32_t* _return);
};

struct td_sjs_class_i32 {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class_i32(sjs_class_i32* _this, sjs_class_i32** _return);
sji_foo* sjf_class_i32_asFoo(sjs_class_i32* _this);
void sjf_class_i32_destroy(sjs_class_i32* _this);
void sjf_class_i32_test(sjs_class_i32* _parent, int32_t* _return);
void sjf_global(void);
void sji_foo_destroy(sji_foo* _this);

void sjf_class_i32(sjs_class_i32* _this, sjs_class_i32** _return) {
    _this->_refCount++;

    *_return = _this;
}

sji_foo* sjf_class_i32_asFoo(sjs_class_i32* _this) {
    sji_foo* _interface = (sji_foo*)malloc(sizeof(sji_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->test = sjf_class_i32_test;
    return _interface;
}

void sjf_class_i32_destroy(sjs_class_i32* _this) {
}

void sjf_class_i32_test(sjs_class_i32* _parent, int32_t* _return) {

    *_return = 5;
}

void sjf_global(void) {
    sjs_class_i32 sjd_temp1;
    sji_foo* a;
    sji_foo* result1;
    int32_t result2;
    sjs_class_i32* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_class_i32(sjv_temp1, &sjv_temp1);
    result1 = sjf_class_i32_asFoo(sjv_temp1);
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
    sjf_class_i32_destroy(&sjd_temp1);
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
