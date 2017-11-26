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
    int _refCount;
};

struct td_sjs_array_char {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_char_heap {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_a {
    sjs_array_char data;
};

struct td_sjs_a_heap {
    int _refCount;
    sjs_array_char data;
};

int32_t sjt_cast1;
sjs_a void1;

void sjf_a(sjs_a* _this);
void sjf_a_copy(sjs_a* _this, sjs_a* to);
void sjf_a_destroy(sjs_a* _this);
void sjf_a_heap(sjs_a_heap* _this);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* to);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char_heap* _this);
void main_destroy();

void sjf_a(sjs_a* _this) {
}

void sjf_a_copy(sjs_a* _this, sjs_a* to) {
    sjf_array_char_copy(&_this->data, &to->data);
}

void sjf_a_destroy(sjs_a* _this) {
}

void sjf_a_heap(sjs_a_heap* _this) {
}

void sjf_array_char(sjs_array_char* _this) {
    
		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)calloc(_this->size * sizeof(char), 1);
			if (!_this->data) {
				printf("grow: out of memory\n");
				exit(-1);				
			}
		}
	;
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* to) {
    _this->size = to->size;
    _this->data = to->data;
    _this->_isGlobal = to->_isGlobal;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    
	if (!_this->_isGlobal && _this->data) {
		free((char*)_this->data);
		_this->data = 0;	
	}
;
}

void sjf_array_char_heap(sjs_array_char_heap* _this) {
    
		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)calloc(_this->size * sizeof(char), 1);
			if (!_this->data) {
				printf("grow: out of memory\n");
				exit(-1);				
			}
		}
	;
}

int main() {
    void1.data.size = 0;
    sjt_cast1 = 0;
    void1.data.data = (uintptr_t)sjt_cast1;
    void1.data._isGlobal = false;
    sjf_array_char(&void1.data);
    sjf_a(&void1);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_a_destroy(&void1);
}
