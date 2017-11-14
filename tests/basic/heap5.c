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

#define sjs_a_typeId 1
#define sjs_array_char_typeId 2
#define sjs_object_typeId 3

typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_object sjs_object;

struct td_sjs_a {
    int _refCount;
    sjs_array_char* data;
};

struct td_sjs_array_char {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_a(sjs_a* _this, sjs_a** _return);
void sjf_a_destroy(sjs_a* _this);
void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_global(void);

void sjf_a(sjs_a* _this, sjs_a** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_a_destroy(sjs_a* _this) {
    sjf_array_char_destroy(_this->data);
}

void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return) {
    
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
    _this->_refCount++;

    *_return = _this;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    
	if (!_this->_isGlobal && _this->data) {
		free((char*)_this->data);
		_this->data = 0;	
	}
;
}

void sjf_global(void) {
    sjs_array_char sjd_temp1;
    sjs_a sjd_temp2;
    uintptr_t result1;
    sjs_array_char* sjv_temp1;
    sjs_a* sjv_temp2;

    result1 = (uintptr_t)0;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->size = 0;
    sjv_temp1->data = result1;
    sjv_temp1->_isGlobal = false;
    sjf_array_char(sjv_temp1, &sjv_temp1);
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->data = sjv_temp1;
    sjv_temp2->data->_refCount++;
    sjf_a(sjv_temp2, &sjv_temp2);
    sjf_array_char_destroy(&sjd_temp1);
    sjf_a_destroy(&sjd_temp2);
}

int main() {
    sjf_global();

    return 0;
}
