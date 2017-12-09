#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define sjs_object_typeId 1
#define sjs_array_i32_typeId 2
#define sjs_array_i32_heap_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sjs_array_i32_heap sjs_array_i32_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_array_i32 {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_i32_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

int32_t sjt_cast1;
sjs_array_i32* sjt_dot1;
sjs_array_i32* sjt_dot2;
int32_t sjt_functionParam1;
int32_t sjt_functionParam2;
int32_t sjt_functionParam3;
sjs_array_i32 sjv_a;
int32_t sjv_c;

void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getAt(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32_heap* _this);
void sjf_array_i32_setAt(sjs_array_i32* _parent, int32_t index, int32_t item);
void main_destroy(void);

void sjf_array_i32(sjs_array_i32* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        exit(-1);
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(int32_t), 1);
#line 110
        if (!_this->data) {
#line 110
            printf("grow: out of memory\n");
#line 110
            exit(-1);
#line 110
        }
#line 110
    }
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
#line 1 ".\..\lib\common\array.sj"
    _this->size = _from->size;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isGlobal = _from->_isGlobal;
#line 129
    _this->data = _from->data;
#line 129
    if (!_this->_isGlobal && _this->data) {
#line 129
        _retain((void*)_this->data);
#line 129
    }
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
#line 136 ".\..\lib\common\array.sj"
    if (!_this->_isGlobal && _this->data) {
#line 136
        if (_release((void*)_this->data)) {
#line 136
            free((int32_t*)_this->data);
#line 136
        }
#line 136
    }
}

void sjf_array_i32_getAt(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
#line 6 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 6
        printf("getAt: out of bounds\n");
#line 6
        exit(-1);
#line 6
    }
#line 6
    int32_t* p = (int32_t*)_parent->data;
#line 6
    #line 6 ".\..\lib\common\array.sj"
#line 6
    (*_return) = p[index];
#line 6
    ;
}

void sjf_array_i32_heap(sjs_array_i32_heap* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        exit(-1);
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(int32_t), 1);
#line 110
        if (!_this->data) {
#line 110
            printf("grow: out of memory\n");
#line 110
            exit(-1);
#line 110
        }
#line 110
    }
}

void sjf_array_i32_setAt(sjs_array_i32* _parent, int32_t index, int32_t item) {
#line 30 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 30
        printf("setAt: out of bounds %d:%d\n", index, _parent->size);
#line 30
        exit(-1);
#line 30
    }
#line 30
    int32_t* p = (int32_t*)_parent->data;
#line 30
    ;
#line 30
    #line 29 ".\..\lib\common\array.sj"
#line 30
    p[index] = item;
#line 30
    ;
}

int main(int argc, char** argv) {
#line 3 ".\basic\array1.sj"
    sjv_a.size = 1;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast1 = 0;
#line 3
    sjv_a.data = (uintptr_t)sjt_cast1;
#line 4
    sjv_a._isGlobal = false;
#line 0 ""
    sjf_array_i32(&sjv_a);
#line 4 ".\basic\array1.sj"
    sjt_dot1 = &sjv_a;
#line 4
    sjt_functionParam1 = 0;
#line 4
    sjt_functionParam2 = 1;
#line 0 ""
    sjf_array_i32_setAt(sjt_dot1, sjt_functionParam1, sjt_functionParam2);
#line 5 ".\basic\array1.sj"
    sjt_dot2 = &sjv_a;
#line 5
    sjt_functionParam3 = 0;
#line 0 ""
    sjf_array_i32_getAt(sjt_dot2, sjt_functionParam3, &sjv_c);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_array_i32_destroy(&sjv_a);
}
