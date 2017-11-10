#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    void (*test)(int32_t _return);
};

struct td_sjs_class_i32 {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class_i32(sjs_class_i32* _this, sjs_class_i32** _return);
void sjf_class_i32_destroy(sjs_class_i32* _this);
void sjf_global(void);

void sjf_class_i32(sjs_class_i32* _this, sjs_class_i32** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_i32_destroy(sjs_class_i32* _this) {
}

void sjf_global(void) {
    sjs_class_i32 sjd_temp1;
    sji_foo* a;
    sji_foo* result1;
    sjs_class_i32* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_class_i32(sjv_temp1, &sjv_temp1);
    result1 = (sji_foo*)sjv_temp1;
    a = result1;
    a->_refCount++;
    sjf_class_i32_destroy(&sjd_temp1);
}

int main() {
    sjf_global();

    return 0;
}
