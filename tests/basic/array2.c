#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_array_i32 sjs_array_i32;

struct td_sjs_array_i32 {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

void sjf_array_i32(sjs_array_i32* _this, sjs_array_i32** _return);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getAt(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_setAt(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_global(int32_t* _return);

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

void sjf_global(int32_t* _return) {
    sjs_array_i32* a;
    sjs_array_i32* result2;
    uintptr_t result3;
    int32_t result4;
    sjs_array_i32 sjd_temp1;
    sjs_array_i32* sjv_array1;
    sjs_array_i32* sjv_temp1;

    result3 = (uintptr_t)0;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->size = 3;
    sjv_temp1->data = result3;
    sjv_temp1->_isGlobal = false;
    sjf_array_i32(sjv_temp1, &result2);
    sjv_array1 = result2;
    sjv_array1->_refCount++;
    sjf_array_i32_setAt(sjv_array1, 0, 1);
    sjf_array_i32_setAt(sjv_array1, 1, 2);
    sjf_array_i32_setAt(sjv_array1, 2, 3);
    a = sjv_array1;
    a->_refCount++;
    sjf_array_i32_getAt(a, 0, &result4);

    sjf_array_i32_destroy(a);
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_array_i32_destroy(result2);
        free(result2);
    }
    sjf_array_i32_destroy(sjv_array1);
    sjf_array_i32_destroy(sjv_temp1);

    *_return = result4;
}

int main() {
    int32_t result1;

    sjf_global(&result1);

    return 0;
}
