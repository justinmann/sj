#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_array_class sjs_array_class;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_global sjs_global;
typedef struct td_sjs_list_class sjs_list_class;

struct td_sjs_array_class {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

struct td_sjs_global {
    int _refCount;
};

struct td_sjs_list_class {
    int _refCount;
    sjs_global* _parent;
    int32_t count;
    sjs_array_class* data;
};

void sjf_array_class(sjs_array_class* _this, sjs_array_class** _return);
void sjf_array_class_destroy(sjs_array_class* _this);
void sjf_array_class_getAt(sjs_array_class* _parent, int32_t index, sjs_class** _return);
void sjf_array_class_grow(sjs_array_class* _parent, int32_t newSize, sjs_array_class** _return);
void sjf_array_class_setAt(sjs_array_class* _parent, int32_t index, sjs_class* item);
void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_global(sjs_global* _this, int32_t* _return);
void sjf_global_destroy(sjs_global* _this);
void sjf_list_class(sjs_list_class* _this, sjs_list_class** _return);
void sjf_list_class_add(sjs_list_class* _parent, sjs_class* item, int32_t* _return);
void sjf_list_class_destroy(sjs_list_class* _this);
void sjf_list_class_getAt(sjs_list_class* _parent, int32_t index, sjs_class** _return);
void sjf_list_class_setSize(sjs_list_class* _parent, int32_t size, sjs_array_class** _return);

void sjf_array_class(sjs_array_class* _this, sjs_array_class** _return) {
    
		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)malloc(_this->size * sizeof(sjs_class*));
		}
	;
    _this->_refCount++;

    *_return = _this;
}

void sjf_array_class_destroy(sjs_array_class* _this) {
    
	if (!_this->_isGlobal) {
		free((sjs_class**)_this->data);	
	}
;
}

void sjf_array_class_getAt(sjs_array_class* _parent, int32_t index, sjs_class** _return) {
    
		

		if (index >= _parent->size || index < 0) {
			exit(-1);
		}

		sjs_class** p = (sjs_class**)_parent->data;
		sjs_class* val = p[index];
		if (!false) {
			if (val == 0) {
				exit(-1);
			}
		}
		*_return = val;		
	;
}

void sjf_array_class_grow(sjs_array_class* _parent, int32_t newSize, sjs_array_class** _return) {
    
		

		if (_parent->size != newSize) {
			if (newSize < _parent->size) {
				exit(-1);
			}
			
			if (_parent->_isGlobal) {
				_parent->_isGlobal = false;
				sjs_class** p = (sjs_class**)_parent->data;
				_parent->data = (uintptr_t)malloc(newSize * sizeof(sjs_class*));
				memcpy((void*)_parent->data, p, _parent->size * sizeof(sjs_class*));
			} else {
				_parent->data = (uintptr_t)realloc((void*)_parent->data, newSize * sizeof(sjs_class*));
			}
			_parent->size = newSize;
		}

		*_return = _parent;
	;
}

void sjf_array_class_setAt(sjs_array_class* _parent, int32_t index, sjs_class* item) {
    
		
		

		if (index >= _parent->size || index < 0) {
			exit(-1);
		}

		sjs_class** p = (sjs_class**)_parent->data;
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

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_global(sjs_global* _this, int32_t* _return) {
    sjs_list_class* a;
    sjs_class* c;
    int32_t loopEnd1;
    sjs_class* result12;
    sjs_list_class* result2;
    sjs_array_class* result3;
    uintptr_t result4;
    sjs_array_class sjd_temp1;
    sjs_list_class sjd_temp2;
    sjs_array_class* sjv_temp1;
    sjs_list_class* sjv_temp2;
    int32_t temp11;
    int32_t x;

    result4 = (uintptr_t)0;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->size = 0;
    sjv_temp1->data = result4;
    sjv_temp1->_isGlobal = false;
    sjf_array_class(sjv_temp1, &result3);
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->count = 0;
    sjv_temp2->data = result3;
    sjv_temp2->data->_refCount++;
    sjf_list_class(sjv_temp2, &result2);
    a = result2;
    a->_refCount++;
    x = 1;
    loopEnd1 = 100000;
    while (x <= loopEnd1) {
        int32_t result5;
        sjs_class* result6;
        sjs_class* sjv_temp3;

        sjv_temp3 = (sjs_class*)malloc(sizeof(sjs_class));
        sjv_temp3->_refCount = 1;
        sjv_temp3->x = x;
        sjf_class(sjv_temp3, &result6);
        sjf_list_class_add(a, result6, &result5);
        x++;

        result6->_refCount--;
        if (result6->_refCount == 0) {
            sjf_class_destroy(result6);
            free(result6);
        }
        sjv_temp3->_refCount--;
        if (sjv_temp3->_refCount == 0) {
            sjf_class_destroy(sjv_temp3);
            free(sjv_temp3);
        }
    }

    sjf_list_class_getAt(a, 0, &result12);

    c = result12;

    c->_refCount++;

    temp11 = c->x;

    sjf_list_class_destroy(a);
    c->_refCount--;
    if (c->_refCount == 0) {
        sjf_class_destroy(c);
        free(c);
    }
    result12->_refCount--;
    if (result12->_refCount == 0) {
        sjf_class_destroy(result12);
        free(result12);
    }
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_list_class_destroy(result2);
        free(result2);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_array_class_destroy(result3);
        free(result3);
    }
    sjf_array_class_destroy(sjv_temp1);
    sjf_list_class_destroy(sjv_temp2);

    *_return = temp11;
}

void sjf_global_destroy(sjs_global* _this) {
}

void sjf_list_class(sjs_list_class* _this, sjs_list_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_list_class_add(sjs_list_class* _parent, sjs_class* item, int32_t* _return) {
    int32_t result11;
    bool result7;
    int32_t temp1;
    sjs_array_class* temp2;
    int32_t temp3;
    sjs_array_class* temp7;
    int32_t temp8;
    int32_t temp9;

    temp1 = _parent->count;
    temp2 = _parent->data;
    temp3 = temp2->size;
    result7 = temp1 > temp3;
    if (result7) {
        sjs_array_class* result8;
        int32_t result9;
        sjs_array_class* temp4;
        int32_t temp5;

        temp4 = _parent->data;
        temp5 = temp4->size;
        result9 = temp5 * 2;
        sjf_list_class_setSize(_parent, result9, &result8);

        result8->_refCount--;
        if (result8->_refCount == 0) {
            sjf_array_class_destroy(result8);
            free(result8);
        }
        sjf_array_class_destroy(temp4);
    }

    temp7 = _parent->data;

    temp8 = _parent->count;

    sjf_array_class_setAt(temp7, temp8, item);

    temp9 = _parent->count;

    result11 = temp9 + 1;

    _parent->count = result11;

    sjf_array_class_destroy(temp2);
    sjf_array_class_destroy(temp7);

    *_return = result11;
}

void sjf_list_class_destroy(sjs_list_class* _this) {
    sjf_array_class_destroy(_this->data);
}

void sjf_list_class_getAt(sjs_list_class* _parent, int32_t index, sjs_class** _return) {
    sjs_class* result13;
    sjs_array_class* temp10;

    temp10 = _parent->data;
    sjf_array_class_getAt(temp10, index, &result13);

    sjf_array_class_destroy(temp10);

    *_return = result13;
}

void sjf_list_class_setSize(sjs_list_class* _parent, int32_t size, sjs_array_class** _return) {
    sjs_array_class* result10;
    sjs_array_class* temp6;

    temp6 = _parent->data;
    sjf_array_class_grow(temp6, size, &result10);

    sjf_array_class_destroy(temp6);

    *_return = result10;
}

int main() {
    int32_t result1;
    sjs_global sjd_temp3;
    sjs_global* sjv_temp4;

    sjv_temp4 = &sjd_temp3;
    sjv_temp4->_refCount = 1;
    sjf_global(sjv_temp4, &result1);

    sjf_global_destroy(sjv_temp4);

    return 0;
}
