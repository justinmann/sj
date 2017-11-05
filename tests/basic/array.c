#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_array_class sjs_array_class;
typedef struct td_sjs_class sjs_class;

struct td_sjs_array_class {
    int _refCount;
    int32_t count;
    int32_t _size;
    uintptr_t _data;
};

struct td_sjs_class {
    int _refCount;
    int32_t bob;
};

sjs_array_class* sjf_array_class(sjs_array_class* _this);
void sjf_array_class_destroy(sjs_array_class* _this);
void sjf_array_class_set(int32_t index, sjs_class* item);
void sjf_array_class_setSize(int32_t x);
sjs_class* sjf_class(sjs_class* _this);
void sjf_class_destroy(sjs_class* _this);
void sjf_global();

sjs_array_class* sjf_array_class(sjs_array_class* _this) {
    int32_t temp1;

    temp1 = _this->count;
    sjf_array_class_setSize(temp1);

    return _this;
}

void sjf_array_class_destroy(sjs_array_class* _this) {
    
	free((##t)_this->_data);	
;
}

void sjf_array_class_set(int32_t index, sjs_class* item) {
    
		if (index >= count || index < 0) {
			exit(-1);
		}

		#t#* p = _parent->data;
		#t#_release(p[index]);
		#t#_retain(item);
		p[index] = item;
	;
}

void sjf_array_class_setSize(int32_t x) {
    
		if (x < 0) {
			exit(-1);
		}

		if (_size != x) {
			if (x != 0) {
				if (_parent->_data == 0) {
					_parent->_data = malloc(x * sizeof(##t));
				} else {
					_parent->_data = realloc(x * sizeof(##t));
				}
			}
			_size = x;
		}
	;
}

sjs_class* sjf_class(sjs_class* _this) {

    return _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_global() {
    sjs_array_class* a;
    sjs_array_class* result1;
    uintptr_t result2;
    sjs_class* result3;
    sjs_class* result4;
    sjs_array_class sjd_temp1;
    sjs_array_class* sjv_temp1;
    sjs_class* sjv_temp2;
    sjs_class* sjv_temp3;

    result2 = (uintptr_t)0;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->count = 2;
    sjv_temp1->_size = 0;
    sjv_temp1->_data = result2;
    result1 = sjf_array_class(sjv_temp1);
    a = result1;
    a->_refCount++;
    sjv_temp2 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp2->_refCount = 1;
    sjv_temp2->bob = 1;
    result3 = sjf_class(sjv_temp2);
    sjf_array_class_set(0, result3);
    sjv_temp3 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp3->_refCount = 1;
    sjv_temp3->bob = 2;
    result4 = sjf_class(sjv_temp3);
    sjf_array_class_set(1, result4);

    sjf_array_class_destroy(a);
    result1->_refCount--;
    if (result1->_refCount == 0) {
        sjf_array_class_destroy(result1);
        free(result1);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_class_destroy(result3);
        free(result3);
    }
    result4->_refCount--;
    if (result4->_refCount == 0) {
        sjf_class_destroy(result4);
        free(result4);
    }
    sjf_array_class_destroy(sjv_temp1);
    sjv_temp2->_refCount--;
    if (sjv_temp2->_refCount == 0) {
        sjf_class_destroy(sjv_temp2);
        free(sjv_temp2);
    }
    sjv_temp3->_refCount--;
    if (sjv_temp3->_refCount == 0) {
        sjf_class_destroy(sjv_temp3);
        free(sjv_temp3);
    }
}

int main() {
    sjf_global();

    return 0;
}
