#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define sji_anon1_foo_typeId 1
#define sji_anon2_foo_typeId 2
#define sjs_anon1_typeId 3
#define sjs_anon1_class_typeId 4
#define sjs_anon2_typeId 5
#define sjs_anon2_class_typeId 6
#define sjs_object_typeId 7

typedef struct td_sji_anon1_foo sji_anon1_foo;
typedef struct td_sji_anon2_foo sji_anon2_foo;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon1_class sjs_anon1_class;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon2_class sjs_anon2_class;
typedef struct td_sjs_object sjs_object;

struct td_sji_anon1_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test1)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_anon2_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test2)(sjs_object* _parent, int32_t* _return);
};

struct td_sjs_anon1 {
    int _refCount;
};

struct td_sjs_anon1_class {
    int _refCount;
};

struct td_sjs_anon2 {
    int _refCount;
};

struct td_sjs_anon2_class {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return);
void sjf_anon1_class(sjs_anon1_class* _this, sjs_anon1_class** _return);
sjs_object* sjf_anon1_class_asInterface(sjs_anon1_class* _this, int typeId);
sji_anon1_foo* sjf_anon1_class_as_sji_anon1_foo(sjs_anon1_class* _this);
void sjf_anon1_class_destroy(sjs_anon1_class* _this);
void sjf_anon1_class_test1(sjs_anon1_class* _parent, int32_t* _return);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon2(sjs_anon2* _this, sjs_anon2** _return);
void sjf_anon2_class(sjs_anon2_class* _this, sjs_anon2_class** _return);
sjs_object* sjf_anon2_class_asInterface(sjs_anon2_class* _this, int typeId);
sji_anon2_foo* sjf_anon2_class_as_sji_anon2_foo(sjs_anon2_class* _this);
void sjf_anon2_class_destroy(sjs_anon2_class* _this);
void sjf_anon2_class_test2(sjs_anon2_class* _parent, int32_t* _return);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_global(void);
void sji_anon1_foo_destroy(sji_anon1_foo* _this);
void sji_anon2_foo_destroy(sji_anon2_foo* _this);

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon1_class(sjs_anon1_class* _this, sjs_anon1_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

sjs_object* sjf_anon1_class_asInterface(sjs_anon1_class* _this, int typeId) {
    switch (typeId) {
        case sji_anon1_foo_typeId: return sjf_anon1_class_as_sji_anon1_foo(_this);
    }

    return 0;
}

sji_anon1_foo* sjf_anon1_class_as_sji_anon1_foo(sjs_anon1_class* _this) {
    sji_anon1_foo* _interface = (sji_anon1_foo*)malloc(sizeof(sji_anon1_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = sjf_anon1_class_destroy;
    _interface->asInterface = sjf_anon1_class_asInterface;
    _interface->test1 = sjf_anon1_class_test1;
    return _interface;
}

void sjf_anon1_class_destroy(sjs_anon1_class* _this) {
}

void sjf_anon1_class_test1(sjs_anon1_class* _parent, int32_t* _return) {

    *_return = 5;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon2(sjs_anon2* _this, sjs_anon2** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon2_class(sjs_anon2_class* _this, sjs_anon2_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

sjs_object* sjf_anon2_class_asInterface(sjs_anon2_class* _this, int typeId) {
    switch (typeId) {
        case sji_anon2_foo_typeId: return sjf_anon2_class_as_sji_anon2_foo(_this);
    }

    return 0;
}

sji_anon2_foo* sjf_anon2_class_as_sji_anon2_foo(sjs_anon2_class* _this) {
    sji_anon2_foo* _interface = (sji_anon2_foo*)malloc(sizeof(sji_anon2_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = sjf_anon2_class_destroy;
    _interface->asInterface = sjf_anon2_class_asInterface;
    _interface->test2 = sjf_anon2_class_test2;
    return _interface;
}

void sjf_anon2_class_destroy(sjs_anon2_class* _this) {
}

void sjf_anon2_class_test2(sjs_anon2_class* _parent, int32_t* _return) {

    *_return = 5;
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_global(void) {
    sjs_anon1 sjd_temp1;
    sjs_anon2 sjd_temp2;
    sjs_anon1_class sjd_temp3;
    sjs_anon2_class sjd_temp4;
    sji_anon1_foo* a;
    sji_anon2_foo* b;
    sjs_anon1* namespace1;
    sjs_anon2* namespace2;
    sji_anon1_foo* result1;
    sji_anon2_foo* result2;
    sjs_anon1* sjv_temp1;
    sjs_anon2* sjv_temp2;
    sjs_anon1_class* sjv_temp3;
    sjs_anon2_class* sjv_temp4;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_anon1(sjv_temp1, &sjv_temp1);
    namespace1 = sjv_temp1;
    namespace1->_refCount++;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjf_anon2(sjv_temp2, &sjv_temp2);
    namespace2 = sjv_temp2;
    namespace2->_refCount++;
    sjv_temp3 = &sjd_temp3;
    sjv_temp3->_refCount = 1;
    sjf_anon1_class(sjv_temp3, &sjv_temp3);
    result1 = sjf_anon1_class_as_sji_anon1_foo(sjv_temp3);
    a = result1;
    a->_refCount++;
    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sji_anon1_foo_destroy(result1);
        free(result1);
    }

    sjv_temp4 = &sjd_temp4;

    sjv_temp4->_refCount = 1;

    sjf_anon2_class(sjv_temp4, &sjv_temp4);

    result2 = sjf_anon2_class_as_sji_anon2_foo(sjv_temp4);

    b = result2;

    b->_refCount++;

    result2->_refCount--;

    if (result2->_refCount <= 0) {
        sji_anon2_foo_destroy(result2);
        free(result2);
    }

    a->_refCount--;
    if (a->_refCount <= 0) {
        sji_anon1_foo_destroy(a);
        free(a);
    }
    b->_refCount--;
    if (b->_refCount <= 0) {
        sji_anon2_foo_destroy(b);
        free(b);
    }
    sjf_anon1_destroy(&sjd_temp1);
    sjf_anon2_destroy(&sjd_temp2);
    sjf_anon1_class_destroy(&sjd_temp3);
    sjf_anon2_class_destroy(&sjd_temp4);
}

void sji_anon1_foo_destroy(sji_anon1_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

void sji_anon2_foo_destroy(sji_anon2_foo* _this) {
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
