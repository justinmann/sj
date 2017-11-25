#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
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

#define sjs_object_typeId 1
#define sjs_array_class_typeId 2
#define sjs_array_class_heap_typeId 3
#define sjs_class_typeId 4
#define sjs_class_heap_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_array_class sjs_array_class;
typedef struct td_sjs_array_class_heap sjs_array_class_heap;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_array_class {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_class_heap {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_class {
    int32_t x;
};

struct td_sjs_class_heap {
    int _refCount;
    int32_t x;
};

void sjf_array_class(sjs_array_class* _this);
void sjf_array_class_copy(sjs_array_class* _this, sjs_array_class* to);
void sjf_array_class_destroy(sjs_array_class* _this);
void sjf_array_class_getAt(sjs_array_class* _parent, int32_t index, sjs_class* _return);
void sjf_array_class_heap(sjs_array_class_heap* _this);
void sjf_array_class_setAt(sjs_array_class* _parent, int32_t index, sjs_class* item);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);


void sjf_array_class(sjs_array_class* _this) {
    
		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)calloc(_this->size * sizeof(sjs_class), 1);
			if (!_this->data) {
				printf("grow: out of memory\n");
				exit(-1);				
			}
		}
	;
}

void sjf_array_class_copy(sjs_array_class* _this, sjs_array_class* to) {
    _this->size = to->size;
    _this->data = to->data;
    _this->_isGlobal = to->_isGlobal;
}

void sjf_array_class_destroy(sjs_array_class* _this) {
    
	if (!_this->_isGlobal && _this->data) {
		free((sjs_class*)_this->data);
		_this->data = 0;	
	}
;
}

void sjf_array_class_getAt(sjs_array_class* _parent, int32_t index, sjs_class* _return) {
    
		int32_t size;
		int32_t dotTemp3;

dotTemp3 = _parent->size;
size = dotTemp3;
;
		uintptr_t data;
		uintptr_t dotTemp4;

dotTemp4 = _parent->data;
data = dotTemp4;
;

		if (index >= size || index < 0) {
			printf("getAt: out of bounds\n");
			exit(-1);
		}

		sjs_class* p = (sjs_class*)data;
		sjf_class_copy(_return, &p[index]);
;		
	;
}

void sjf_array_class_heap(sjs_array_class_heap* _this) {
    
		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)calloc(_this->size * sizeof(sjs_class), 1);
			if (!_this->data) {
				printf("grow: out of memory\n");
				exit(-1);				
			}
		}
	;
}

void sjf_array_class_setAt(sjs_array_class* _parent, int32_t index, sjs_class* item) {
    
		int32_t size;
		int32_t dotTemp1;

dotTemp1 = _parent->size;
size = dotTemp1;
;
		uintptr_t data;
		uintptr_t dotTemp2;

dotTemp2 = _parent->data;
data = dotTemp2;
;

		if (index >= size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, size);
			exit(-1);
		}

		sjs_class* p = (sjs_class*)data;
		;
		sjf_class_copy(&p[index], item);
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

int main() {
    sjs_array_class a;
    sjs_class b;
    int32_t c;
    int32_t dotTemp5;
    sjs_class sjt_call1;
    int32_t sjt_cast1;
    sjs_array_class* sjt_dot1;
    sjs_array_class* sjt_dot2;
    sjs_class* sjt_dot3;
    int32_t sjt_functionParam1;
    sjs_class* sjt_functionParam2;
    int32_t sjt_functionParam3;

    a.size = 1;
    sjt_cast1 = 0;
    a.data = (uintptr_t)sjt_cast1;
    a._isGlobal = false;
    sjf_array_class(&a);
    sjt_dot1 = &a;
    sjt_functionParam1 = 0;
    sjt_call1.x = 1;
    sjf_class(&sjt_call1);
    sjt_functionParam2 = &sjt_call1;
    sjf_array_class_setAt(sjt_dot1, sjt_functionParam1, sjt_functionParam2);
    sjt_dot2 = &a;
    sjt_functionParam3 = 0;
    sjf_array_class_getAt(sjt_dot2, sjt_functionParam3, &b);
    sjt_dot3 = &b;
    dotTemp5 = sjt_dot3->x;
    c = dotTemp5;

    sjf_array_class_destroy(&a);
    sjf_class_destroy(&b);
    sjf_class_destroy(&sjt_call1);
    return 0;
}
