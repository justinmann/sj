#include <assert.h>
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

#define sjs_array_sjs_class_typeId 1
#define sjs_class_typeId 2
#define sjs_object_typeId 3

typedef struct td_sjs_array_sjs_class sjs_array_sjs_class;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_object sjs_object;

struct td_sjs_array_sjs_class {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_class {
    int _refCount;
    int32_t bob;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_array_sjs_class(sjs_array_sjs_class* _this, sjs_array_sjs_class** _return);
void sjf_array_sjs_class_destroy(sjs_array_sjs_class* _this);
void sjf_array_sjs_class_setAt(sjs_array_sjs_class* _parent, int32_t index, sjs_class* item);
void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_destroy(sjs_class* _this);

sjs_array_sjs_class sjd_temp1;

void sjf_array_sjs_class(sjs_array_sjs_class* _this, sjs_array_sjs_class** _return) {
    
		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)calloc(_this->size * sizeof(sjs_class*), 1);
			if (!_this->data) {
				printf("grow: out of memory\n");
				exit(-1);				
			}
		}
	;
    _this->_refCount++;
    printf("RETAIN\tsjs_array_sjs_class*\t%0x\tvoid sjf_array_sjs_class(sjs_array_sjs_class* _this, sjs_array_sjs_class** _return)\t%d\n", (uintptr_t)_this, _this->_refCount);;

    *_return = _this;
}

void sjf_array_sjs_class_destroy(sjs_array_sjs_class* _this) {
    
	if (!_this->_isGlobal && _this->data) {
		free((sjs_class**)_this->data);
		_this->data = 0;	
	}
;
}

void sjf_array_sjs_class_setAt(sjs_array_sjs_class* _parent, int32_t index, sjs_class* item) {
    
		
		

		if (index >= _parent->size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, _parent->size);
			exit(-1);
		}

		sjs_class** p = (sjs_class**)_parent->data;
#if !false
		if (p[index] != 0) {
			 p[index]->_refCount--;
printf("RELEASE\tsjs_class*\t%0x\t\t%d\n", (uintptr_t) p[index],  p[index]->_refCount);
if ( p[index]->_refCount <= 0) {
    sjf_class_destroy( p[index]);
    free( p[index]);
}
;
		}
#endif
		 item->_refCount++;
;
		p[index] = item;
	;
}

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;
    printf("RETAIN\tsjs_class*\t%0x\tvoid sjf_class(sjs_class* _this, sjs_class** _return)\t%d\n", (uintptr_t)_this, _this->_refCount);;

    *_return = _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

int main() {
    sjs_array_sjs_class* a;
    uintptr_t result1;
    sjs_array_sjs_class* sjv_temp1;
    sjs_class* sjv_temp2;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    printf("RETAIN\tsjs_array_sjs_class*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)sjv_temp1, sjv_temp1->_refCount);;
    result1 = (uintptr_t)0;
    sjv_temp1->size = 2;
    sjv_temp1->data = result1;
    sjv_temp1->_isGlobal = false;
    sjf_array_sjs_class(sjv_temp1, &sjv_temp1);
    a = sjv_temp1;
    a->_refCount++;
    printf("RETAIN\tsjs_array_sjs_class*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)a, a->_refCount);;
    sjv_temp2 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp2->_refCount = 1;
    printf("RETAIN\tsjs_class*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)sjv_temp2, sjv_temp2->_refCount);;
    sjv_temp2->bob = 1;
    sjf_class(sjv_temp2, &sjv_temp2);
    sjf_array_sjs_class_setAt(a, 0, sjv_temp2);

    sjv_temp2->_refCount--;
    printf("RELEASE\tsjs_class*\t%0x\tvoid sjf_global(void)\t%d\n", (uintptr_t)sjv_temp2, sjv_temp2->_refCount);
    if (sjv_temp2->_refCount <= 0) {
        sjf_class_destroy(sjv_temp2);
        free(sjv_temp2);
    }
    assert(sjd_temp1._refCount == 0);
    return 0;
}
