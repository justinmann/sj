#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_array_i32 sjs_array_i32;

struct td_sjs_array_i32 {
    int _refCount;
    int32_t count;
    int32_t _size;
    uintptr_t _data;
};

sjs_array_i32* sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_setAt(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_i32_setSize(sjs_array_i32* _parent, int32_t x);
sjs_array_i32* sjf_global();

sjs_array_i32* sjf_array_i32(sjs_array_i32* _this) {
    int32_t temp1;

    temp1 = _this->count;
    sjf_array_i32_setSize(_this, temp1);
    _this->_refCount++;

    return _this;
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
    
	free((int32_t*)_this->_data);	
;
}

void sjf_array_i32_setAt(sjs_array_i32* _parent, int32_t index, int32_t item) {
    
		
		

		if (index >= _parent->count || index < 0) {
			exit(-1);
		}

		int32_t* p = (int32_t*)_parent->_data;
		;
		;
		p[index] = item;
	;
}

void sjf_array_i32_setSize(sjs_array_i32* _parent, int32_t x) {
    
		

		if (x < 0) {
			exit(-1);
		}

		if (_parent->_size != x) {
			if (x != 0) {
				if (_parent->_data == 0) {
					_parent->_data = (uintptr_t)malloc(x * sizeof(int32_t));
				} else {
					_parent->_data = (uintptr_t)realloc((void*)_parent->_data, x * sizeof(int32_t));
				}
			}
			_parent->_size = x;
		}
	;
}

sjs_array_i32* sjf_global() {
    sjs_array_i32* a;
    sjs_array_i32* array;
    sjs_array_i32* result2;
    uintptr_t result3;
    sjs_array_i32 sjd_temp1;
    sjs_array_i32* sjv_temp1;

    result3 = (uintptr_t)0;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->count = 0;
    sjv_temp1->_size = 0;
    sjv_temp1->_data = result3;
    result2 = sjf_array_i32(sjv_temp1);
    array = result2;
    array->_refCount++;
    sjf_array_i32_setSize(array, 3);
    sjf_array_i32_setAt(array, 0, 1);
    sjf_array_i32_setAt(array, 1, 2);
    sjf_array_i32_setAt(array, 2, 3);
    a = array;
    a->_refCount++;
    array->_refCount++;

    a->_refCount--;
    if (a->_refCount == 0) {
        sjf_array_i32_destroy(a);
        free(a);
    }
    array->_refCount--;
    if (array->_refCount == 0) {
        sjf_array_i32_destroy(array);
        free(array);
    }
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_array_i32_destroy(result2);
        free(result2);
    }
    sjf_array_i32_destroy(sjv_temp1);

    return array;
}

int main() {
    sjs_array_i32* result1;

    result1 = sjf_global();

    return 0;
}
