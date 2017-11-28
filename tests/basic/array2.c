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
int32_t sjt_functionParam1;
int32_t sjt_functionParam2;
int32_t sjt_functionParam3;
int32_t sjt_functionParam4;
int32_t sjt_functionParam5;
int32_t sjt_functionParam6;
int32_t sjt_functionParam7;
sjs_array_i32 sjv_a;
int32_t void1;

void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* to);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getAt(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32_heap* _this);
void sjf_array_i32_initAt(sjs_array_i32* _parent, int32_t index, int32_t item);
void main_destroy(void);

void sjf_array_i32(sjs_array_i32* _this) {
    
		

		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)calloc(_this->size * sizeof(int32_t), 1);
			if (!_this->data) {
				printf("grow: out of memory\n");
				exit(-1);				
			}
		}
	;
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* to) {
    _this->size = to->size;
    _this->data = to->data;
    _this->_isGlobal = to->_isGlobal;
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
    
	if (!_this->_isGlobal && _this->data) {
		free((int32_t*)_this->data);
		_this->data = 0;	
	}
;
}

void sjf_array_i32_getAt(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
    
		if (index >= _parent->size || index < 0) {
			printf("getAt: out of bounds\n");
			exit(-1);
		}

		int32_t* p = (int32_t*)_parent->data;
		(*_return) = p[index];
;		
	;
}

void sjf_array_i32_heap(sjs_array_i32_heap* _this) {
    
		

		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)calloc(_this->size * sizeof(int32_t), 1);
			if (!_this->data) {
				printf("grow: out of memory\n");
				exit(-1);				
			}
		}
	;
}

void sjf_array_i32_initAt(sjs_array_i32* _parent, int32_t index, int32_t item) {
    
		if (index >= _parent->size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, _parent->size);
			exit(-1);
		}

		int32_t* p = (int32_t*)_parent->data;
		p[index] = item;
;
	;
}

int main() {
    sjv_a.size = 3;
    sjt_cast1 = 0;
    sjv_a.data = (uintptr_t)sjt_cast1;
    sjv_a._isGlobal = false;
    sjf_array_i32(&sjv_a);
    sjt_functionParam1 = 0;
    sjt_functionParam2 = 1;
    sjf_array_i32_initAt(&sjv_a, sjt_functionParam1, sjt_functionParam2);
    sjt_functionParam3 = 1;
    sjt_functionParam4 = 2;
    sjf_array_i32_initAt(&sjv_a, sjt_functionParam3, sjt_functionParam4);
    sjt_functionParam5 = 2;
    sjt_functionParam6 = 3;
    sjf_array_i32_initAt(&sjv_a, sjt_functionParam5, sjt_functionParam6);
    sjt_dot1 = &sjv_a;
    sjt_functionParam7 = 0;
    sjf_array_i32_getAt(sjt_dot1, sjt_functionParam7, &void1);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_array_i32_destroy(&sjv_a);
}
