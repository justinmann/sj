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
#define sjs_array_char_typeId 2
#define sjs_array_char_heap_typeId 3
#define sjs_a_typeId 4
#define sjs_a_heap_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_array_char_heap sjs_array_char_heap;
typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_a_heap sjs_a_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_array_char {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_char_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_a {
    sjs_array_char data;
};

struct td_sjs_a_heap {
    intptr_t _refCount;
    sjs_array_char data;
};

int32_t sjt_cast1;
sjs_a void1;

void sjf_a(sjs_a* _this);
void sjf_a_copy(sjs_a* _this, sjs_a* _from);
void sjf_a_destroy(sjs_a* _this);
void sjf_a_heap(sjs_a_heap* _this);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char_heap* _this);
void main_destroy(void);

void sjf_a(sjs_a* _this) {
}

void sjf_a_copy(sjs_a* _this, sjs_a* _from) {
#line 3 ".\basic\heap5.sj"
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_a_destroy(sjs_a* _this) {
}

void sjf_a_heap(sjs_a_heap* _this) {
}

void sjf_array_char(sjs_array_char* _this) {
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
        _this->data = (uintptr_t)calloc(_this->size * sizeof(char), 1);
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

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
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

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 136 ".\..\lib\common\array.sj"
    if (!_this->_isGlobal && _this->data) {
#line 136
        if (_release((void*)_this->data)) {
#line 136
            free((char*)_this->data);
#line 136
        }
#line 136
    }
}

void sjf_array_char_heap(sjs_array_char_heap* _this) {
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
        _this->data = (uintptr_t)calloc(_this->size * sizeof(char), 1);
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

int main(int argc, char** argv) {
#line 4 ".\basic\heap5.sj"
    void1.data.size = 0;
#line 4
    sjt_cast1 = 0;
#line 4
    void1.data.data = (uintptr_t)sjt_cast1;
#line 4 ".\..\lib\common\array.sj"
    void1.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&void1.data);
    sjf_a(&void1);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_a_destroy(&void1);
}
