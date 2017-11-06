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
    int32_t x;
};

sjs_array_class* sjf_array_class(sjs_array_class* _this);
void sjf_array_class_destroy(sjs_array_class* _this);
sjs_class* sjf_array_class_getAt(sjs_array_class* _parent, int32_t index);
void sjf_array_class_setAt(sjs_array_class* _parent, int32_t index, sjs_class* item);
void sjf_array_class_setSize(sjs_array_class* _parent, int32_t x);
sjs_class* sjf_class(sjs_class* _this);
void sjf_class_destroy(sjs_class* _this);
int32_t sjf_global();

sjs_array_class* sjf_array_class(sjs_array_class* _this) {
    int32_t temp1;

    temp1 = _this->count;
    sjf_array_class_setSize(_this, temp1);
    _this->_refCount++;

    return _this;
}

void sjf_array_class_destroy(sjs_array_class* _this) {
    
	free((sjs_class**)_this->_data);	
;
}

sjs_class* sjf_array_class_getAt(sjs_array_class* _parent, int32_t index) {
    
		

		if (index >= count || index < 0) {
			exit(-1);
		}

		sjs_class** p = (sjs_class**)_parent->_data;
		sjs_class* val = p[index];
		if (!false) {
			if (val == 0) {
				exit(-1);
			}
		}
		return val;		
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

void sjf_array_class_setSize(sjs_array_class* _parent, int32_t x) {
    
		

		if (x < 0) {
			exit(-1);
		}

		if (_parent->_size != x) {
			if (x != 0) {
				if (_parent->_data == 0) {
					_parent->_data = (uintptr_t)malloc(x * sizeof(sjs_class*));
				} else {
					_parent->_data = (uintptr_t)realloc((void*)_parent->_data, x * sizeof(sjs_class*));
				}
			}
			_parent->_size = x;
		}
	;
}

sjs_class* sjf_class(sjs_class* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

int32_t sjf_global() {
    sjs_array_class* a;
    sjs_class* b;
    int32_t c;
    sjs_array_class* result2;
    uintptr_t result3;
    sjs_class* result4;
    sjs_class* result5;
    sjs_array_class sjd_temp1;
    sjs_array_class* sjv_temp1;
    sjs_class* sjv_temp2;
    int32_t temp2;

    result3 = (uintptr_t)0;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->count = 1;
    sjv_temp1->_size = 0;
    sjv_temp1->_data = result3;
    result2 = sjf_array_class(sjv_temp1);
    a = result2;
    a->_refCount++;
    sjv_temp2 = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_temp2->_refCount = 1;
    sjv_temp2->x = 1;
    result4 = sjf_class(sjv_temp2);
    sjf_array_class_setAt(a, 0, result4);
    result5 = sjf_array_class_getAt(a, 0);
    b = result5;
    b->_refCount++;
    temp2 = b->x;
    c = temp2;

    sjf_array_class_destroy(a);
    sjf_class_destroy(b);
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_array_class_destroy(result2);
        free(result2);
    }
    result4->_refCount--;
    if (result4->_refCount == 0) {
        sjf_class_destroy(result4);
        free(result4);
    }
    result5->_refCount--;
    if (result5->_refCount == 0) {
        sjf_class_destroy(result5);
        free(result5);
    }
    sjf_array_class_destroy(sjv_temp1);
    sjv_temp2->_refCount--;
    if (sjv_temp2->_refCount == 0) {
        sjf_class_destroy(sjv_temp2);
        free(sjv_temp2);
    }

    return c;
}

int main() {
    int32_t result1;

    result1 = sjf_global();

    return 0;
}