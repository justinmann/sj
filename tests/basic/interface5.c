#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isempty;
    int32_t value;
};
const int32_option int32_empty = { true };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isempty;
    uint32_t value;
};
const uint32_option uint32_empty = { true };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isempty;
    int64_t value;
};
const int64_option int64_empty = { true };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isempty;
    uint64_t value;
};
const uint64_option uint64_empty = { true };

typedef struct td_void_option void_option;
struct td_void_option {
    bool isempty;
    void* value;
};
const void_option void_empty = { true };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isempty;
    char value;
};
const char_option char_empty = { true };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isempty;
    float value;
};
const float_option float_empty = { true };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isempty;
    double value;
};
const double_option double_empty = { true };

#define sjs_object_typeId 1
#define sjs_class_i32_typeId 2
#define sji_bar_typeId 3
#define sji_foo_i32_typeId 4

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class_i32 sjs_class_i32;
typedef struct td_sji_bar sji_bar;
typedef struct td_sji_foo_i32 sji_foo_i32;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_class_i32 {
    int _refCount;
};

struct td_sji_bar {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test2)(void* _parent, int32_t* _return);
};

struct td_sji_foo_i32 {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test1)(void* _parent, int32_t* _return);
};

sjs_class_i32* sjt_cast1 = 0;
sji_foo_i32* sjt_cast2 = 0;
bool sjt_ifElse1;
sji_bar* sjt_isEmpty1 = 0;
sji_foo_i32* sjt_parent1 = 0;
sji_foo_i32* sjv_a = 0;
sji_bar* sjv_b = 0;
int32_t void1;

void sjf_class_i32(sjs_class_i32* _this);
sjs_object* sjf_class_i32_asInterface(sjs_class_i32* _this, int typeId);
sji_bar* sjf_class_i32_as_sji_bar(sjs_class_i32* _this);
sji_foo_i32* sjf_class_i32_as_sji_foo_i32(sjs_class_i32* _this);
void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from);
void sjf_class_i32_destroy(sjs_class_i32* _this);
void sjf_class_i32_heap(sjs_class_i32* _this);
sjs_object* sjf_class_i32_heap_asInterface(sjs_class_i32* _this, int typeId);
sji_bar* sjf_class_i32_heap_as_sji_bar(sjs_class_i32* _this);
sji_foo_i32* sjf_class_i32_heap_as_sji_foo_i32(sjs_class_i32* _this);
void sjf_class_i32_test1(sjs_class_i32* _parent, int32_t* _return);
void sjf_class_i32_test2(sjs_class_i32* _parent, int32_t* _return);
void sji_bar_copy(sji_bar* _this, sji_bar* _from);
void sji_bar_destroy(sji_bar* _this);
void sji_foo_i32_copy(sji_foo_i32* _this, sji_foo_i32* _from);
void sji_foo_i32_destroy(sji_foo_i32* _this);
void main_destroy(void);

void sjf_class_i32(sjs_class_i32* _this) {
}

sjs_object* sjf_class_i32_asInterface(sjs_class_i32* _this, int typeId) {
    switch (typeId) {
        case sji_bar_typeId:  {
            return (sjs_object*)sjf_class_i32_as_sji_bar(_this);
        }

        case sji_foo_i32_typeId:  {
            return (sjs_object*)sjf_class_i32_as_sji_foo_i32(_this);
        }
    }

    return 0;
}

sji_bar* sjf_class_i32_as_sji_bar(sjs_class_i32* _this) {
    sji_bar* _interface;
    _interface = (sji_bar*)malloc(sizeof(sji_bar));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_i32_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_i32_asInterface;
    _interface->test2 = (void(*)(void*, int32_t*))sjf_class_i32_test2;

    return _interface;
}

sji_foo_i32* sjf_class_i32_as_sji_foo_i32(sjs_class_i32* _this) {
    sji_foo_i32* _interface;
    _interface = (sji_foo_i32*)malloc(sizeof(sji_foo_i32));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_i32_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_i32_asInterface;
    _interface->test1 = (void(*)(void*, int32_t*))sjf_class_i32_test1;

    return _interface;
}

void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from) {
}

void sjf_class_i32_destroy(sjs_class_i32* _this) {
}

void sjf_class_i32_heap(sjs_class_i32* _this) {
}

sjs_object* sjf_class_i32_heap_asInterface(sjs_class_i32* _this, int typeId) {
    switch (typeId) {
        case sji_bar_typeId:  {
            return (sjs_object*)sjf_class_i32_heap_as_sji_bar(_this);
        }

        case sji_foo_i32_typeId:  {
            return (sjs_object*)sjf_class_i32_heap_as_sji_foo_i32(_this);
        }
    }

    return 0;
}

sji_bar* sjf_class_i32_heap_as_sji_bar(sjs_class_i32* _this) {
    sji_bar* _interface;
    _interface = (sji_bar*)malloc(sizeof(sji_bar));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_i32_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_i32_heap_asInterface;
    _interface->test2 = (void(*)(void*, int32_t*))sjf_class_i32_test2;

    return _interface;
}

sji_foo_i32* sjf_class_i32_heap_as_sji_foo_i32(sjs_class_i32* _this) {
    sji_foo_i32* _interface;
    _interface = (sji_foo_i32*)malloc(sizeof(sji_foo_i32));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_i32_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_i32_heap_asInterface;
    _interface->test1 = (void(*)(void*, int32_t*))sjf_class_i32_test1;

    return _interface;
}

void sjf_class_i32_test1(sjs_class_i32* _parent, int32_t* _return) {
    (*_return) = 1;
}

void sjf_class_i32_test2(sjs_class_i32* _parent, int32_t* _return) {
    (*_return) = 2;
}

void sji_bar_copy(sji_bar* _this, sji_bar* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->test2 = _from->test2;
}

void sji_bar_destroy(sji_bar* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

void sji_foo_i32_copy(sji_foo_i32* _this, sji_foo_i32* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->test1 = _from->test1;
}

void sji_foo_i32_destroy(sji_foo_i32* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
    sjt_cast1 = (sjs_class_i32*)malloc(sizeof(sjs_class_i32));
    sjt_cast1->_refCount = 1;
    sjf_class_i32_heap(sjt_cast1);
    sjv_a = (sji_foo_i32*)sjf_class_i32_heap_as_sji_foo_i32(sjt_cast1);
    sjt_parent1 = sjv_a;
    sjt_parent1->test1(sjt_parent1->_parent, &void1);
    sjt_cast2 = sjv_a;
    sjt_cast2->_refCount++;
    sjv_b = (sji_bar*)sjt_cast2->asInterface(sjt_cast2->_parent, sji_bar_typeId);
    sjt_isEmpty1 = sjv_b;
    sjt_ifElse1 = (sjt_isEmpty1 == 0);
    if (sjt_ifElse1) {
    } else {
        sji_bar* sjt_parent2 = 0;
        int32_t sjt_value1;
        int32_option value1;

        sjt_parent2 = sjv_b;
        sjt_parent2->test2(sjt_parent2->_parent, &sjt_value1);
        value1.isempty = false;
        value1.value = sjt_value1;
    }
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjt_cast1->_refCount--;
    if (sjt_cast1->_refCount <= 0) {
        sjf_class_i32_destroy(sjt_cast1);
    }
    sjt_cast2->_refCount--;
    if (sjt_cast2->_refCount <= 0) {
        sji_foo_i32_destroy(sjt_cast2);
    }
    sjv_a->_refCount--;
    if (sjv_a->_refCount <= 0) {
        sji_foo_i32_destroy(sjv_a);
    }
    if (sjv_b != 0) {
        sjv_b->_refCount--;
        if (sjv_b->_refCount <= 0) {
            sji_bar_destroy(sjv_b);
        }
    }
}
