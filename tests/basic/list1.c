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
    int _refCount;
};

struct td_sjs_array_heap_class {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_heap_class_heap {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_list_heap_class {
    int32_t count;
    sjs_array_heap_class data;
};

struct td_sjs_list_heap_class_heap {
    int _refCount;
    int32_t count;
    sjs_array_heap_class data;
};

struct td_sjs_class {
    int32_t x;
};

struct td_sjs_class_heap {
    int _refCount;
    int32_t x;
};

void sjf_array_heap_class(sjs_array_heap_class* _this);
void sjf_array_heap_class_copy(sjs_array_heap_class* _this, sjs_array_heap_class* to);
void sjf_array_heap_class_destroy(sjs_array_heap_class* _this);
void sjf_array_heap_class_getAt_heap(sjs_array_heap_class* _parent, int32_t index, sjs_class_heap** _return);
void sjf_array_heap_class_grow(sjs_array_heap_class* _parent, int32_t newSize);
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
	;
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
;
}

void sjf_array_heap_class_getAt_heap(sjs_array_heap_class* _parent, int32_t index, sjs_class_heap** _return) {
    
		

		if (index >= _parent->size || index < 0) {
			printf("getAt: out of bounds\n");
			exit(-1);
		}

		sjs_class_heap** p = (sjs_class_heap**)_parent->data;
		sjs_class_heap* val = p[index];
#if !false
		if (val == 0) {
			printf("getAt: value is not defined at %d\n", index);
			exit(-1);
		}
#endif
		*_return = val;		
	;
}

void sjf_array_heap_class_grow(sjs_array_heap_class* _parent, int32_t newSize) {
    
		
		

		if (_parent->size != newSize) {
			if (newSize < _parent->size) {
				printf("grow: new size smaller than old size %d:%d\n", newSize, _parent->size);
				exit(-1);
			}
			
			if (_parent->_isGlobal) {
				_parent->_isGlobal = false;
				sjs_class_heap** p = (sjs_class_heap**)_parent->data;
				_parent->data = (uintptr_t)calloc(newSize * sizeof(sjs_class_heap*), 1);
				if (!_parent->data) {
					printf("grow: out of memory\n");
					exit(-1);				
				}
				memcpy((void*)_parent->data, p, _parent->size * sizeof(sjs_class_heap*));
			} else {
				_parent->data = (uintptr_t)realloc((void*)_parent->data, newSize * sizeof(sjs_class_heap*));
				if (!_parent->data) {
					printf("grow: out of memory\n");
					exit(-1);				
				}
				memset((sjs_class_heap**)_parent->data + _parent->size, 0, (newSize - _parent->size) * sizeof(sjs_class_heap*));
			}
			_parent->size = newSize;
		}
	;
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
	;
}

void sjf_array_heap_class_setAt(sjs_array_heap_class* _parent, int32_t index, sjs_class_heap* item) {
    
		

		if (index >= _parent->size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, _parent->size);
			exit(-1);
		}

		sjs_class_heap** p = (sjs_class_heap**)_parent->data;
#if !false
		if (p[index] != 0) {
			 p[index]->_refCount--;
if ( p[index]->_refCount <= 0) {
    sjf_class_destroy((sjs_class*)(((char*) p[index]) + sizeof(int)));
}
;
		}
#endif
		 item->_refCount++;
;
		p[index] = item;
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
    int32_t dotTemp1;
    sjs_array_heap_class dotTemp2;
    int32_t dotTemp3;
    sjs_array_heap_class dotTemp7;
    int32_t dotTemp8;
    int32_t dotTemp9;
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sjs_array_heap_class* sjt_dot2;
    sjs_array_heap_class* sjt_dot5;
    int32_t sjt_functionParam3;
    sjs_class_heap* sjt_functionParam4;
    bool sjt_ifElse1;
    int32_t sjt_math3;
    int32_t sjt_math4;

    dotTemp1 = _parent->count;
    sjt_compare1 = dotTemp1;
    dotTemp2 = _parent->data;
    sjt_dot2 = &dotTemp2;
    dotTemp3 = sjt_dot2->size;
    sjt_compare2 = dotTemp3;
    sjt_ifElse1 = sjt_compare1 > sjt_compare2;
    if (sjt_ifElse1) {
        sjs_array_heap_class dotTemp5;
        int32_t dotTemp6;
        sjs_array_heap_class* sjt_dot4;
        int32_t sjt_functionParam2;
        int32_t sjt_math1;
        int32_t sjt_math2;

        dotTemp5 = _parent->data;
        sjt_dot4 = &dotTemp5;
        dotTemp6 = sjt_dot4->size;
        sjt_math1 = dotTemp6;
        sjt_math2 = 2;
        sjt_functionParam2 = sjt_math1 * sjt_math2;
        sjf_list_heap_class_setSize(_parent, sjt_functionParam2);

        sjf_array_heap_class_destroy(&dotTemp5);
    }

    dotTemp7 = _parent->data;
    sjt_dot5 = &dotTemp7;
    dotTemp8 = _parent->count;
    sjt_functionParam3 = dotTemp8;
    sjt_functionParam4 = item;
    sjt_functionParam4->_refCount++;
    sjf_array_heap_class_setAt(sjt_dot5, sjt_functionParam3, sjt_functionParam4);
    dotTemp9 = _parent->count;
    sjt_math3 = dotTemp9;
    sjt_math4 = 1;
    _parent->count = sjt_math3 + sjt_math4;
    (*_return) = _parent->count;

    sjt_functionParam4->_refCount--;
    if (sjt_functionParam4->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjt_functionParam4) + sizeof(int)));
    }
    sjf_array_heap_class_destroy(&dotTemp2);
    sjf_array_heap_class_destroy(&dotTemp7);
}

void sjf_list_heap_class_copy(sjs_list_heap_class* _this, sjs_list_heap_class* to) {
    _this->count = to->count;
    sjf_array_heap_class_copy(&_this->data, &to->data);
}

void sjf_list_heap_class_destroy(sjs_list_heap_class* _this) {
}

void sjf_list_heap_class_getAt_heap(sjs_list_heap_class* _parent, int32_t index, sjs_class_heap** _return) {
    sjs_array_heap_class dotTemp10;
    sjs_array_heap_class* sjt_dot7;
    int32_t sjt_functionParam6;

    dotTemp10 = _parent->data;
    sjt_dot7 = &dotTemp10;
    sjt_functionParam6 = index;
    sjf_array_heap_class_getAt_heap(sjt_dot7, sjt_functionParam6, &(*_return));

    sjf_array_heap_class_destroy(&dotTemp10);
}

void sjf_list_heap_class_heap(sjs_list_heap_class_heap* _this) {
}

void sjf_list_heap_class_setSize(sjs_list_heap_class* _parent, int32_t size) {
    sjs_array_heap_class dotTemp4;
    sjs_array_heap_class* sjt_dot3;
    int32_t sjt_functionParam1;

    dotTemp4 = _parent->data;
    sjt_dot3 = &dotTemp4;
    sjt_functionParam1 = size;
    sjf_array_heap_class_grow(sjt_dot3, sjt_functionParam1);

    sjf_array_heap_class_destroy(&dotTemp4);
}

int main() {
    sjs_list_heap_class a;
    sjs_class_heap* c;
    int32_t sjt_cast1;
    sjs_list_heap_class* sjt_dot6;
    sjs_class* sjt_dot8;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    int32_t sjt_functionParam7;
    int32_t x;

    a.count = 0;
    a.data.size = 0;
    sjt_cast1 = 0;
    a.data.data = (uintptr_t)sjt_cast1;
    a.data._isGlobal = false;
    sjf_array_heap_class(&a.data);
    sjf_list_heap_class(&a);
    sjt_forStart1 = 1;
    x = sjt_forStart1;
    sjt_forEnd1 = 100000;
    while (x < sjt_forEnd1) {
        sjs_list_heap_class* sjt_dot1;
        sjs_class_heap* sjt_functionParam5;
        int32_t void1;

        sjt_dot1 = &a;
        sjt_functionParam5 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
        sjt_functionParam5->_refCount = 1;
        sjt_functionParam5->x = x;
        sjf_class_heap(sjt_functionParam5);
        sjf_list_heap_class_add(sjt_dot1, sjt_functionParam5, &void1);
        x++;

        sjt_functionParam5->_refCount--;
        if (sjt_functionParam5->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjt_functionParam5) + sizeof(int)));
        }
    }

    sjt_dot6 = &a;
    sjt_functionParam7 = 0;
    sjf_list_heap_class_getAt_heap(sjt_dot6, sjt_functionParam7, &c);
    sjt_dot8 = (sjs_class*)(((char*)c) + sizeof(int));

    c->_refCount--;
    if (c->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)c) + sizeof(int)));
    }
    sjf_list_heap_class_destroy(&a);
    return 0;
}
