#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define sjs_array_i32_typeId 1
#define sjs_object_typeId 2

typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sjs_object sjs_object;

struct td_sjs_array_i32 {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_array_i32(sjs_array_i32* _this, sjs_array_i32** _return);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getAt(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_setAt(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_global(void);

void sjf_array_i32(sjs_array_i32* _this, sjs_array_i32** _return) {
    
		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)malloc(_this->size * sizeof(int32_t));
		}
	;
    _this->_refCount++;

    *_return = _this;
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
    
	if (!_this->_isGlobal) {
		free((int32_t*)_this->data);	
	}
;
}

void sjf_array_i32_getAt(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
    
		

		if (index >= _parent->size || index < 0) {
			exit(-1);
		}

		int32_t* p = (int32_t*)_parent->data;
		int32_t val = p[index];
		if (!true) {
			if (val == 0) {
				exit(-1);
			}
		}
		*_return = val;		
	;
}

void sjf_array_i32_setAt(sjs_array_i32* _parent, int32_t index, int32_t item) {
    
		
		

		if (index >= _parent->size || index < 0) {
			exit(-1);
		}

		int32_t* p = (int32_t*)_parent->data;
		;
		;
		p[index] = item;
	;
}

void sjf_global(void) {
    sjs_array_i32 sjd_temp1;
    sjs_array_i32* a;
    int32_t c;
    uintptr_t result1;
    int32_t result2;
    sjs_array_i32* sjv_temp1;

    result1 = (uintptr_t)0;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->size = 1;
    sjv_temp1->data = result1;
    sjv_temp1->_isGlobal = false;
    sjf_array_i32(sjv_temp1, &sjv_temp1);
    a = sjv_temp1;
    a->_refCount++;
    sjf_array_i32_setAt(a, 0, 1);
    sjf_array_i32_getAt(a, 0, &result2);
    c = result2;
    sjf_array_i32_destroy(&sjd_temp1);
}

int main() {
    sjf_global();

    return 0;
}
