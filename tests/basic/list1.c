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
#define sjs_array_heap_class_typeId 2
#define sjs_array_heap_class_heap_typeId 3
#define sjs_list_heap_class_typeId 4
#define sjs_list_heap_class_heap_typeId 5
#define sjs_class_typeId 6
#define sjs_class_heap_typeId 7

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_array_heap_class sjs_array_heap_class;
typedef struct td_sjs_array_heap_class_heap sjs_array_heap_class_heap;
typedef struct td_sjs_list_heap_class sjs_list_heap_class;
typedef struct td_sjs_list_heap_class_heap sjs_list_heap_class_heap;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_array_heap_class {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_heap_class_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_list_heap_class {
    int32_t count;
    sjs_array_heap_class data;
};

struct td_sjs_list_heap_class_heap {
    intptr_t _refCount;
    int32_t count;
    sjs_array_heap_class data;
};

struct td_sjs_class {
    int32_t x;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
    int32_t x;
};

int32_t sjt_cast1;
sjs_list_heap_class* sjt_dot6;
sjs_class* sjt_dot8;
int32_t sjt_forEnd1;
int32_t sjt_forStart1;
int32_t sjt_functionParam7;
sjs_list_heap_class sjv_a;
sjs_class_heap* sjv_c;
int32_t x;

void sjf_array_heap_class(sjs_array_heap_class* _this);
void sjf_array_heap_class_copy(sjs_array_heap_class* _this, sjs_array_heap_class* to);
void sjf_array_heap_class_destroy(sjs_array_heap_class* _this);
void sjf_array_heap_class_getAt_heap(sjs_array_heap_class* _parent, int32_t index, sjs_class_heap** _return);
void sjf_array_heap_class_grow(sjs_array_heap_class* _parent, int32_t new_size);
void sjf_array_heap_class_heap(sjs_array_heap_class_heap* _this);
void sjf_array_heap_class_setAt(sjs_array_heap_class* _parent, int32_t index, sjs_class_heap* item);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_list_heap_class(sjs_list_heap_class* _this);
void sjf_list_heap_class_add(sjs_list_heap_class* _parent, sjs_class_heap* item, int32_t* _return);
void sjf_list_heap_class_copy(sjs_list_heap_class* _this, sjs_list_heap_class* to);
void sjf_list_heap_class_destroy(sjs_list_heap_class* _this);
void sjf_list_heap_class_getAt_heap(sjs_list_heap_class* _parent, int32_t index, sjs_class_heap** _return);
void sjf_list_heap_class_heap(sjs_list_heap_class_heap* _this);
void sjf_list_heap_class_setSize(sjs_list_heap_class* _parent, int32_t size);
void main_destroy(void);

void sjf_array_heap_class(sjs_array_heap_class* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sjs_class_heap*), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_array_heap_class_copy(sjs_array_heap_class* _this, sjs_array_heap_class* to) {
    _this->size = to->size;
    _this->data = to->data;
    _this->_isGlobal = to->_isGlobal;
}

void sjf_array_heap_class_destroy(sjs_array_heap_class* _this) {
    if (!_this->_isGlobal && _this->data) {
        free((sjs_class_heap**)_this->data);
        _this->data = 0;
    }
}

void sjf_array_heap_class_getAt_heap(sjs_array_heap_class* _parent, int32_t index, sjs_class_heap** _return) {
    if (index >= _parent->size || index < 0) {
        printf("getAt: out of bounds\n");
        exit(-1);
    }
    sjs_class_heap** p = (sjs_class_heap**)_parent->data;
    (*_return) = p[index];
    (*_return)->_refCount++;
    ;
}

void sjf_array_heap_class_grow(sjs_array_heap_class* _parent, int32_t new_size) {
    if (_parent->size != new_size) {
        if (new_size < _parent->size) {
            printf("grow: new _parent->size smaller than old _parent->size %d:%d\n", new_size, _parent->size);
            exit(-1);
        }
        if (_parent->_isGlobal) {
            _parent->_isGlobal = false;
            sjs_class_heap** p = (sjs_class_heap**)_parent->data;
            _parent->data = (uintptr_t)calloc(new_size * sizeof(sjs_class_heap*), 1);
            if (!_parent->data) {
                printf("grow: out of memory\n");
                exit(-1);
            }
            memcpy((void*)_parent->data, p, _parent->size * sizeof(sjs_class_heap*));
        } else {
            _parent->data = (uintptr_t)realloc((void*)_parent->data, new_size * sizeof(sjs_class_heap*));
            if (!_parent->data) {
                printf("grow: out of memory\n");
                exit(-1);
            }
            memset((sjs_class_heap**)_parent->data + _parent->size, 0, (new_size - _parent->size) * sizeof(sjs_class_heap*));
        }
        _parent->size = new_size;
    }
}

void sjf_array_heap_class_heap(sjs_array_heap_class_heap* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sjs_class_heap*), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_array_heap_class_setAt(sjs_array_heap_class* _parent, int32_t index, sjs_class_heap* item) {
    if (index >= _parent->size || index < 0) {
        printf("setAt: out of bounds %d:%d\n", index, _parent->size);
        exit(-1);
    }
    sjs_class_heap** p = (sjs_class_heap**)_parent->data;
    p[index]->_refCount--;
    if (p[index]->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)p[index]) + sizeof(intptr_t)));
    }
    ;
    p[index] = item;
    p[index]->_refCount++;
    ;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* to) {
    _this->x = to->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_list_heap_class(sjs_list_heap_class* _this) {
}

void sjf_list_heap_class_add(sjs_list_heap_class* _parent, sjs_class_heap* item, int32_t* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sjs_array_heap_class* sjt_dot2;
    sjs_array_heap_class* sjt_dot5;
    int32_t sjt_functionParam3;
    sjs_class_heap* sjt_functionParam4;
    bool sjt_ifElse1;
    int32_t sjt_math3;
    int32_t sjt_math4;

    sjt_compare1 = (_parent)->count;
    sjt_dot2 = &(_parent)->data;
    sjt_compare2 = (sjt_dot2)->size;
    sjt_ifElse1 = sjt_compare1 > sjt_compare2;
    if (sjt_ifElse1) {
        sjs_array_heap_class* sjt_dot4;
        int32_t sjt_functionParam2;
        int32_t sjt_math1;
        int32_t sjt_math2;

        sjt_dot4 = &(_parent)->data;
        sjt_math1 = (sjt_dot4)->size;
        sjt_math2 = 2;
        sjt_functionParam2 = sjt_math1 * sjt_math2;
        sjf_list_heap_class_setSize(_parent, sjt_functionParam2);
    }

    sjt_dot5 = &(_parent)->data;
    sjt_functionParam3 = (_parent)->count;
    sjt_functionParam4 = item;
    sjt_functionParam4->_refCount++;
    sjf_array_heap_class_setAt(sjt_dot5, sjt_functionParam3, sjt_functionParam4);
    sjt_math3 = (_parent)->count;
    sjt_math4 = 1;
    _parent->count = sjt_math3 + sjt_math4;
    (*_return) = _parent->count;

    sjt_functionParam4->_refCount--;
    if (sjt_functionParam4->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjt_functionParam4) + sizeof(intptr_t)));
    }
}

void sjf_list_heap_class_copy(sjs_list_heap_class* _this, sjs_list_heap_class* to) {
    _this->count = to->count;
    sjf_array_heap_class_copy(&_this->data, &to->data);
}

void sjf_list_heap_class_destroy(sjs_list_heap_class* _this) {
}

void sjf_list_heap_class_getAt_heap(sjs_list_heap_class* _parent, int32_t index, sjs_class_heap** _return) {
    sjs_array_heap_class* sjt_dot7;
    int32_t sjt_functionParam6;

    sjt_dot7 = &(_parent)->data;
    sjt_functionParam6 = index;
    sjf_array_heap_class_getAt_heap(sjt_dot7, sjt_functionParam6, _return);
}

void sjf_list_heap_class_heap(sjs_list_heap_class_heap* _this) {
}

void sjf_list_heap_class_setSize(sjs_list_heap_class* _parent, int32_t size) {
    sjs_array_heap_class* sjt_dot3;
    int32_t sjt_functionParam1;

    sjt_dot3 = &(_parent)->data;
    sjt_functionParam1 = size;
    sjf_array_heap_class_grow(sjt_dot3, sjt_functionParam1);
}

int main(int argc, char** argv) {
    sjv_a.count = 0;
    sjv_a.data.size = 0;
    sjt_cast1 = 0;
    sjv_a.data.data = (uintptr_t)sjt_cast1;
    sjv_a.data._isGlobal = false;
    sjf_array_heap_class(&sjv_a.data);
    sjf_list_heap_class(&sjv_a);
    sjt_forStart1 = 1;
    x = sjt_forStart1;
    sjt_forEnd1 = 100000;
    while (x < sjt_forEnd1) {
        sjs_list_heap_class* sjt_dot1;
        sjs_class_heap* sjt_functionParam5;
        int32_t void1;

        sjt_dot1 = &sjv_a;
        sjt_functionParam5 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
        sjt_functionParam5->_refCount = 1;
        sjt_functionParam5->x = x;
        sjf_class_heap(sjt_functionParam5);
        sjf_list_heap_class_add(sjt_dot1, sjt_functionParam5, &void1);
        x++;

        sjt_functionParam5->_refCount--;
        if (sjt_functionParam5->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjt_functionParam5) + sizeof(intptr_t)));
        }
    }

    sjt_dot6 = &sjv_a;
    sjt_functionParam7 = 0;
    sjf_list_heap_class_getAt_heap(sjt_dot6, sjt_functionParam7, &sjv_c);
    sjt_dot8 = (sjs_class*)(((char*)sjv_c) + sizeof(intptr_t));
    main_destroy();
    return 0;
}

void main_destroy() {

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjv_c) + sizeof(intptr_t)));
    }
    sjf_list_heap_class_destroy(&sjv_a);
}
