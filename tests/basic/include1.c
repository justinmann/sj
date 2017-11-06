#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_sjs_array_class sjs_array_class;
typedef struct td_sjs_class sjs_class;

struct td_sjs_array_class {
    int _refCount;
    int32_t size;
    uintptr_t _data;
};

struct td_sjs_class {
    int _refCount;
    int32_t bob;
};

sjs_array_class* sjf_array_class(sjs_array_class* _this);
void sjf_array_class_destroy(sjs_array_class* _this);
void sjf_array_class_setAt(sjs_array_class* _parent, int32_t index, sjs_class* item);
sjs_class* sjf_class(sjs_class* _this);
void sjf_class_destroy(sjs_class* _this);
void sjf_global();

sjs_array_class* sjf_array_class(sjs_array_class* _this) {
    
		if (_this->size < 0) {
			exit(-1);
		}

		_this->_data = (uintptr_t)malloc(_this->size * sizeof(sjs_class*));
	;
    _this->_refCount++;

    return _this;
}

void sjf_array_class_destroy(sjs_array_class* _this) {
    
	free((sjs_class**)_this->_data);	
;
}

void sjf_array_class_setAt(sjs_array_class* _parent, int32_t index, sjs_class* item) {
    
		
		

		if (index >= _parent->count || index < 0) {
			exit(-1);
		}

		sjs_class** p = (sjs_class**)_parent->_data;
		 p[index]->_refCount--;
if ( p[index]->_refCount == 0) {
    sjf_class_destroy( p[index]);
    free( p[index]);
}
;
		 item->_refCount++;
;
		p[index] = item;
	;
}

sjs_class* sjf_class(sjs_class* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_global() {
    sjs_array_class* a;
    sjs_array_class* result1;
    uintptr_t result2;
    sjs_class* result3;
    sjs_array_class sjd_temp1;
    sjs_array_class* sjv_temp1;
    sjs_class* sjv_temp2;

    result2 = (uintptr_t)0;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->size = 2;
    sjv_temp1->_data = result2;
    result1 = sjf_array_class(sjv_temp1);
    a = result1;
    a->_refCount++;
    sjv_temp2 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp2->_refCount = 1;
    sjv_temp2->bob = 1;
    result3 = sjf_class(sjv_temp2);
    sjf_array_class_setAt(a, 0, result3);

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
    sjf_array_class_destroy(sjv_temp1);
    sjv_temp2->_refCount--;
    if (sjv_temp2->_refCount == 0) {
        sjf_class_destroy(sjv_temp2);
        free(sjv_temp2);
    }
}

int main() {
    sjf_global();

    return 0;
}
