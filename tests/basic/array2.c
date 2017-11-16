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

#define sjs_array_int32_t_typeId 1
#define sjs_object_typeId 2

typedef struct td_sjs_array_int32_t sjs_array_int32_t;
typedef struct td_sjs_object sjs_object;

struct td_sjs_array_int32_t {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_array_int32_t(sjs_array_int32_t* _this, sjs_array_int32_t** _return);
void sjf_array_int32_t_destroy(sjs_array_int32_t* _this);
void sjf_array_int32_t_getAt(sjs_array_int32_t* _parent, int32_t index, int32_t* _return);
void sjf_array_int32_t_setAt(sjs_array_int32_t* _parent, int32_t index, int32_t item);

sjs_array_int32_t sjd_temp1;

void sjf_array_int32_t(sjs_array_int32_t* _this, sjs_array_int32_t** _return) {
    
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
    _this->_refCount++;

    *_return = _this;
}

void sjf_array_int32_t_destroy(sjs_array_int32_t* _this) {
    
	if (!_this->_isGlobal && _this->data) {
		free((int32_t*)_this->data);
		_this->data = 0;	
	}
;
}

void sjf_array_int32_t_getAt(sjs_array_int32_t* _parent, int32_t index, int32_t* _return) {
    
		

		if (index >= _parent->size || index < 0) {
			printf("getAt: out of bounds\n");
			exit(-1);
		}

		int32_t* p = (int32_t*)_parent->data;
		int32_t val = p[index];
#if !true
		if (val == 0) {
			printf("getAt: value is not defined at %d\n", index);
			exit(-1);
		}
#endif
		*_return = val;		
	;
}

void sjf_array_int32_t_setAt(sjs_array_int32_t* _parent, int32_t index, int32_t item) {
    
		
		

		if (index >= _parent->size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, _parent->size);
			exit(-1);
		}

		int32_t* p = (int32_t*)_parent->data;
#if !true
		if (p[index] != 0) {
			;
		}
#endif
		;
		p[index] = item;
	;
}

int main() {
    sjs_array_int32_t* a;
    uintptr_t result1;
    int32_t result2;
    sjs_array_int32_t* sjv_array1;
    sjs_array_int32_t* sjv_temp1;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    result1 = (uintptr_t)0;
    sjv_temp1->size = 3;
    sjv_temp1->data = result1;
    sjv_temp1->_isGlobal = false;
    sjf_array_int32_t(sjv_temp1, &sjv_temp1);
    sjv_array1 = sjv_temp1;
    sjv_array1->_refCount++;
    sjf_array_int32_t_setAt(sjv_array1, 0, 1);
    sjf_array_int32_t_setAt(sjv_array1, 1, 2);
    sjf_array_int32_t_setAt(sjv_array1, 2, 3);
    a = sjv_array1;
    a->_refCount++;
    sjf_array_int32_t_getAt(a, 0, &result2);
    sjf_array_int32_t_destroy(&sjd_temp1);
    return 0;
}
