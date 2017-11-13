#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

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
#define sjs_global_typeId 3
#define sjs_list_sjs_class_typeId 4
#define sjs_object_typeId 5

typedef struct td_sjs_array_sjs_class sjs_array_sjs_class;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_global sjs_global;
typedef struct td_sjs_list_sjs_class sjs_list_sjs_class;
typedef struct td_sjs_object sjs_object;

struct td_sjs_array_sjs_class {
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

struct td_sjs_list_sjs_class {
    int _refCount;
    sjs_global* _parent;
    int32_t count;
    sjs_array_sjs_class* data;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_array_sjs_class(sjs_array_sjs_class* _this, sjs_array_sjs_class** _return);
void sjf_array_sjs_class_destroy(sjs_array_sjs_class* _this);
void sjf_array_sjs_class_getAt(sjs_array_sjs_class* _parent, int32_t index, sjs_class** _return);
void sjf_array_sjs_class_grow(sjs_array_sjs_class* _parent, int32_t newSize, sjs_array_sjs_class** _return);
void sjf_array_sjs_class_setAt(sjs_array_sjs_class* _parent, int32_t index, sjs_class* item);
void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_global(sjs_global* _this);
void sjf_global_destroy(sjs_global* _this);
void sjf_list_sjs_class(sjs_list_sjs_class* _this, sjs_list_sjs_class** _return);
void sjf_list_sjs_class_add(sjs_list_sjs_class* _parent, sjs_class* item, int32_t* _return);
void sjf_list_sjs_class_destroy(sjs_list_sjs_class* _this);
void sjf_list_sjs_class_getAt(sjs_list_sjs_class* _parent, int32_t index, sjs_class** _return);
void sjf_list_sjs_class_setSize(sjs_list_sjs_class* _parent, int32_t size, sjs_array_sjs_class** _return);

void sjf_array_sjs_class(sjs_array_sjs_class* _this, sjs_array_sjs_class** _return) {
    
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

void sjf_array_sjs_class_destroy(sjs_array_sjs_class* _this) {
    
	if (!_this->_isGlobal) {
		free((sjs_class**)_this->data);	
	}
;
}

void sjf_array_sjs_class_getAt(sjs_array_sjs_class* _parent, int32_t index, sjs_class** _return) {
    
		

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

void sjf_array_sjs_class_grow(sjs_array_sjs_class* _parent, int32_t newSize, sjs_array_sjs_class** _return) {
    
		
		

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

void sjf_array_sjs_class_setAt(sjs_array_sjs_class* _parent, int32_t index, sjs_class* item) {
    
		
		

		if (index >= _parent->size || index < 0) {
			exit(-1);
		}

		sjs_class** p = (sjs_class**)_parent->data;
		 p[index]->_refCount--;
if ( p[index]->_refCount <= 0) {
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

void sjf_global(sjs_global* _this) {
    sjs_array_sjs_class sjd_temp1;
    sjs_list_sjs_class sjd_temp2;
    sjs_list_sjs_class* a;
    sjs_class* c;
    int32_t loopEnd1;
    uintptr_t result1;
    sjs_class* result8;
    sjs_array_sjs_class* sjv_temp1;
    sjs_list_sjs_class* sjv_temp2;
    int32_t temp11;
    int32_t x;

    result1 = (uintptr_t)0;
    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->size = 0;
    sjv_temp1->data = result1;
    sjv_temp1->_isGlobal = false;
    sjf_array_sjs_class(sjv_temp1, &sjv_temp1);
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->count = 0;
    sjv_temp2->data = sjv_temp1;
    sjv_temp2->data->_refCount++;
    sjf_list_sjs_class(sjv_temp2, &sjv_temp2);
    a = sjv_temp2;
    a->_refCount++;
    x = 1;
    loopEnd1 = 100000;
    while (x <= loopEnd1) {
        int32_t result2;
        sjs_class* sjv_temp3;

        result2 = 0;
        sjv_temp3 = (sjs_class*)malloc(sizeof(sjs_class));
        sjv_temp3->_refCount = 1;
        sjv_temp3->x = x;
        sjf_class(sjv_temp3, &sjv_temp3);
        sjf_list_sjs_class_add(a, sjv_temp3, &result2);
        x++;

        sjv_temp3->_refCount--;
        if (sjv_temp3->_refCount <= 0) {
            sjf_class_destroy(sjv_temp3);
            free(sjv_temp3);
        }
    }

    result8 = 0;

    sjf_list_sjs_class_getAt(a, 0, &result8);

    c = result8;

    c->_refCount++;

    temp11 = c->x;

    c->_refCount--;
    if (c->_refCount <= 0) {
        sjf_class_destroy(c);
        free(c);
    }
    result8->_refCount--;
    if (result8->_refCount <= 0) {
        sjf_class_destroy(result8);
        free(result8);
    }
    sjf_array_sjs_class_destroy(&sjd_temp1);
    sjf_list_sjs_class_destroy(&sjd_temp2);
}

void sjf_global_destroy(sjs_global* _this) {
}

void sjf_list_sjs_class(sjs_list_sjs_class* _this, sjs_list_sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_list_sjs_class_add(sjs_list_sjs_class* _parent, sjs_class* item, int32_t* _return) {
    bool result3;
    int32_t result7;
    int32_t temp1;
    sjs_array_sjs_class* temp2;
    int32_t temp3;
    sjs_array_sjs_class* temp7;
    int32_t temp8;
    int32_t temp9;

    temp1 = _parent->count;
    temp2 = _parent->data;
    temp3 = temp2->size;
    result3 = temp1 > temp3;
    if (result3) {
        sjs_array_sjs_class* result4;
        int32_t result5;
        sjs_array_sjs_class* temp4;
        int32_t temp5;

        result4 = 0;
        temp4 = _parent->data;
        temp5 = temp4->size;
        result5 = temp5 * 2;
        sjf_list_sjs_class_setSize(_parent, result5, &result4);

        result4->_refCount--;
        if (result4->_refCount <= 0) {
            sjf_array_sjs_class_destroy(result4);
            free(result4);
        }
    }

    temp7 = _parent->data;

    temp8 = _parent->count;

    sjf_array_sjs_class_setAt(temp7, temp8, item);

    temp9 = _parent->count;

    result7 = temp9 + 1;

    _parent->count = result7;

    *_return = result7;
}

void sjf_list_sjs_class_destroy(sjs_list_sjs_class* _this) {
    sjf_array_sjs_class_destroy(_this->data);
}

void sjf_list_sjs_class_getAt(sjs_list_sjs_class* _parent, int32_t index, sjs_class** _return) {
    sjs_class* result9;
    sjs_array_sjs_class* temp10;

    temp10 = _parent->data;
    result9 = 0;
    sjf_array_sjs_class_getAt(temp10, index, &result9);

    *_return = result9;
}

void sjf_list_sjs_class_setSize(sjs_list_sjs_class* _parent, int32_t size, sjs_array_sjs_class** _return) {
    sjs_array_sjs_class* result6;
    sjs_array_sjs_class* temp6;

    temp6 = _parent->data;
    result6 = 0;
    sjf_array_sjs_class_grow(temp6, size, &result6);

    *_return = result6;
}

int main() {
    sjs_global sjd_temp3;
    sjs_global* sjv_temp4;

    sjv_temp4 = &sjd_temp3;
    sjv_temp4->_refCount = 1;
    sjf_global(sjv_temp4);
    sjf_global_destroy(&sjd_temp3);

    return 0;
}
