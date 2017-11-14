#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isEmpty;
    int32_t value;
};
const int32_option int32_empty = { true };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isEmpty;
    uint32_t value;
};
const uint32_option uint32_empty = { true };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isEmpty;
    int64_t value;
};
const int64_option int64_empty = { true };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isEmpty;
    uint64_t value;
};
const uint64_option uint64_empty = { true };

typedef struct td_uintptr_option uintptr_option;
struct td_uintptr_option {
    bool isEmpty;
    uintptr_t value;
};
const uintptr_option uintptr_empty = { true };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isEmpty;
    char value;
};
const char_option char_empty = { true };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isEmpty;
    float value;
};
const float_option float_empty = { true };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isEmpty;
    double value;
};
const double_option double_empty = { true };

#define sji_bar_typeId 1
#define sji_foo_typeId 2
#define sjs_class_int32_t_typeId 3
#define sjs_object_typeId 4

typedef struct td_sji_bar sji_bar;
typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_class_int32_t sjs_class_int32_t;
typedef struct td_sjs_object sjs_object;

struct td_sji_bar {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test2)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test1)(sjs_object* _parent, int32_t* _return);
};

struct td_sjs_class_int32_t {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class_int32_t(sjs_class_int32_t* _this, sjs_class_int32_t** _return);
sjs_object* sjf_class_int32_t_asInterface(sjs_class_int32_t* _this, int typeId);
sji_bar* sjf_class_int32_t_as_sji_bar(sjs_class_int32_t* _this);
sji_foo* sjf_class_int32_t_as_sji_foo(sjs_class_int32_t* _this);
void sjf_class_int32_t_destroy(sjs_class_int32_t* _this);
void sjf_class_int32_t_test1(sjs_class_int32_t* _parent, int32_t* _return);
void sjf_class_int32_t_test2(sjs_class_int32_t* _parent, int32_t* _return);
void sji_bar_destroy(sji_bar* _this);
void sji_foo_destroy(sji_foo* _this);

sjs_class_int32_t sjd_temp1;

void sjf_class_int32_t(sjs_class_int32_t* _this, sjs_class_int32_t** _return) {
    _this->_refCount++;

    *_return = _this;
}

sjs_object* sjf_class_int32_t_asInterface(sjs_class_int32_t* _this, int typeId) {
    switch (typeId) {
        case sji_bar_typeId: return (sjs_object*)sjf_class_int32_t_as_sji_bar(_this);
        case sji_foo_typeId: return (sjs_object*)sjf_class_int32_t_as_sji_foo(_this);
    }

    return 0;
}

sji_bar* sjf_class_int32_t_as_sji_bar(sjs_class_int32_t* _this) {
    sji_bar* _interface = (sji_bar*)malloc(sizeof(sji_bar));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(sjs_object*))sjf_class_int32_t_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_int32_t_asInterface;
    _interface->test2 = (void(*)(sjs_object*, int32_t*))sjf_class_int32_t_test2;
    return _interface;
}

sji_foo* sjf_class_int32_t_as_sji_foo(sjs_class_int32_t* _this) {
    sji_foo* _interface = (sji_foo*)malloc(sizeof(sji_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(sjs_object*))sjf_class_int32_t_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_int32_t_asInterface;
    _interface->test1 = (void(*)(sjs_object*, int32_t*))sjf_class_int32_t_test1;
    return _interface;
}

void sjf_class_int32_t_destroy(sjs_class_int32_t* _this) {
}

void sjf_class_int32_t_test1(sjs_class_int32_t* _parent, int32_t* _return) {

    *_return = 1;
}

void sjf_class_int32_t_test2(sjs_class_int32_t* _parent, int32_t* _return) {

    *_return = 2;
}

void sji_bar_destroy(sji_bar* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

void sji_foo_destroy(sji_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main() {
    sji_foo* a;
    sji_bar* b;
    int32_option ifResult1;
    sji_foo* result1;
    int32_t result2;
    sji_bar* result3;
    sjs_class_int32_t* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_class_int32_t(sjv_temp1, &sjv_temp1);
    result1 = sjf_class_int32_t_as_sji_foo(sjv_temp1);
    a = result1;
    a->_refCount++;
    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sji_foo_destroy(result1);
        free(result1);
    }

    a->test1(a->_parent, &result2);

    result3 = (sji_bar*)a->asInterface(a->_parent, sji_bar_typeId);

    b = result3;

    if (b != 0) {
        b->_refCount++;
    }

    if (result3 != 0) {
        result3->_refCount--;
        if (result3->_refCount <= 0) {
            sji_bar_destroy(result3);
            free(result3);
        }
    }

    if (b == 0) {
        ifResult1 = int32_empty;
    } else {
        int32_t result4;
        int32_option value1;

        b->test2(b->_parent, &result4);
        value1.isEmpty = false;
        value1.value = result4;
        ifResult1 = value1;
    }

    a->_refCount--;
    if (a->_refCount <= 0) {
        sji_foo_destroy(a);
        free(a);
    }
    if (b != 0) {
        b->_refCount--;
        if (b->_refCount <= 0) {
            sji_bar_destroy(b);
            free(b);
        }
    }
    sjf_class_int32_t_destroy(&sjd_temp1);
    return 0;
}
