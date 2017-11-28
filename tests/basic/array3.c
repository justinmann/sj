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
#define sjs_class_typeId 4
#define sjs_class_heap_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_array_heap_class sjs_array_heap_class;
typedef struct td_sjs_array_heap_class_heap sjs_array_heap_class_heap;
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

struct td_sjs_class {
    int32_t x;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
    int32_t x;
};

int32_t dotTemp1;
int32_t sjt_cast1;
sjs_array_heap_class* sjt_dot1;
sjs_class* sjt_dot2;
int32_t sjt_functionParam1;
sjs_class_heap* sjt_functionParam2;
int32_t sjt_functionParam3;
sjs_class_heap* sjt_functionParam4;
int32_t sjt_functionParam5;
sjs_class_heap* sjt_functionParam6;
int32_t sjt_functionParam7;
sjs_array_heap_class_heap* sjv_a;
sjs_class_heap* sjv_c;

void sjf_array_heap_class(sjs_array_heap_class* _this);
void sjf_array_heap_class_copy(sjs_array_heap_class* _this, sjs_array_heap_class* to);
void sjf_array_heap_class_destroy(sjs_array_heap_class* _this);
void sjf_array_heap_class_getAt_heap(sjs_array_heap_class* _parent, int32_t index, sjs_class_heap** _return);
void sjf_array_heap_class_heap(sjs_array_heap_class_heap* _this);
void sjf_array_heap_class_initAt(sjs_array_heap_class* _parent, int32_t index, sjs_class_heap* item);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
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
		(*_return) = p[index];
(*_return)->_refCount++;
;		
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

void sjf_array_heap_class_initAt(sjs_array_heap_class* _parent, int32_t index, sjs_class_heap* item) {
    
		if (index >= _parent->size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, _parent->size);
			exit(-1);
		}

		sjs_class_heap** p = (sjs_class_heap**)_parent->data;
		p[index] = item;
p[index]->_refCount++;
;
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

int main(int argc, char** argv) {
    sjv_a = (sjs_array_heap_class_heap*)malloc(sizeof(sjs_array_heap_class_heap));
    sjv_a->_refCount = 1;
    sjv_a->size = 3;
    sjt_cast1 = 0;
    sjv_a->data = (uintptr_t)sjt_cast1;
    sjv_a->_isGlobal = false;
    sjf_array_heap_class_heap(sjv_a);
    sjt_functionParam1 = 0;
    sjt_functionParam2 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjt_functionParam2->_refCount = 1;
    sjt_functionParam2->x = 1;
    sjf_class_heap(sjt_functionParam2);
    sjf_array_heap_class_initAt((sjs_array_heap_class*)(((char*)sjv_a) + sizeof(intptr_t)), sjt_functionParam1, sjt_functionParam2);
    sjt_functionParam3 = 1;
    sjt_functionParam4 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjt_functionParam4->_refCount = 1;
    sjt_functionParam4->x = 2;
    sjf_class_heap(sjt_functionParam4);
    sjf_array_heap_class_initAt((sjs_array_heap_class*)(((char*)sjv_a) + sizeof(intptr_t)), sjt_functionParam3, sjt_functionParam4);
    sjt_functionParam5 = 2;
    sjt_functionParam6 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjt_functionParam6->_refCount = 1;
    sjt_functionParam6->x = 3;
    sjf_class_heap(sjt_functionParam6);
    sjf_array_heap_class_initAt((sjs_array_heap_class*)(((char*)sjv_a) + sizeof(intptr_t)), sjt_functionParam5, sjt_functionParam6);
    sjt_dot1 = (sjs_array_heap_class*)(((char*)sjv_a) + sizeof(intptr_t));
    sjt_functionParam7 = 0;
    sjf_array_heap_class_getAt_heap(sjt_dot1, sjt_functionParam7, &sjv_c);
    sjt_dot2 = (sjs_class*)(((char*)sjv_c) + sizeof(intptr_t));
    dotTemp1 = sjt_dot2->x;
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_functionParam2->_refCount--;
    if (sjt_functionParam2->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjt_functionParam2) + sizeof(intptr_t)));
    }
    sjt_functionParam4->_refCount--;
    if (sjt_functionParam4->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjt_functionParam4) + sizeof(intptr_t)));
    }
    sjt_functionParam6->_refCount--;
    if (sjt_functionParam6->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjt_functionParam6) + sizeof(intptr_t)));
    }
    sjv_a->_refCount--;
    if (sjv_a->_refCount <= 0) {
        sjf_array_heap_class_destroy((sjs_array_heap_class*)(((char*)sjv_a) + sizeof(intptr_t)));
    }
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjv_c) + sizeof(intptr_t)));
    }
}
