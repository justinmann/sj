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

const char* sjg_string1 = "bob";
const char* sjg_string2 = "foo";
const char* sjg_string3 = "bob";

#define sjs_object_typeId 1
#define sjs_anon4_typeId 2
#define sjs_anon4_heap_typeId 3
#define sjs_anon3_typeId 4
#define sjs_anon3_heap_typeId 5
#define sjs_anon2_typeId 6
#define sjs_anon2_heap_typeId 7
#define sjs_anon1_typeId 8
#define sjs_anon1_heap_typeId 9
#define sjs_array_char_typeId 10
#define sjs_array_char_heap_typeId 11
#define sjs_string_typeId 12
#define sjs_string_heap_typeId 13
#define sjs_tuple2_i32_string_typeId 14
#define sjs_tuple2_i32_string_heap_typeId 15
#define sjs_tuple3_string_f64_i32_typeId 16
#define sjs_tuple3_string_f64_i32_heap_typeId 17

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_anon4 sjs_anon4;
typedef struct td_sjs_anon4_heap sjs_anon4_heap;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_anon3_heap sjs_anon3_heap;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon2_heap sjs_anon2_heap;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon1_heap sjs_anon1_heap;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_array_char_heap sjs_array_char_heap;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_string_heap sjs_string_heap;
typedef struct td_sjs_tuple2_i32_string sjs_tuple2_i32_string;
typedef struct td_sjs_tuple2_i32_string_heap sjs_tuple2_i32_string_heap;
typedef struct td_sjs_tuple3_string_f64_i32 sjs_tuple3_string_f64_i32;
typedef struct td_sjs_tuple3_string_f64_i32_heap sjs_tuple3_string_f64_i32_heap;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_anon4 {
    int structsNeedAValue;
};

struct td_sjs_anon4_heap {
    int _refCount;
};

struct td_sjs_anon3 {
    int structsNeedAValue;
};

struct td_sjs_anon3_heap {
    int _refCount;
};

struct td_sjs_anon2 {
    int structsNeedAValue;
};

struct td_sjs_anon2_heap {
    int _refCount;
};

struct td_sjs_anon1 {
    int structsNeedAValue;
};

struct td_sjs_anon1_heap {
    int _refCount;
};

struct td_sjs_array_char {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_char_heap {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_string {
    int32_t count;
    sjs_array_char data;
};

struct td_sjs_string_heap {
    int _refCount;
    int32_t count;
    sjs_array_char data;
};

struct td_sjs_tuple2_i32_string {
    int32_t item1;
    sjs_string item2;
};

struct td_sjs_tuple2_i32_string_heap {
    int _refCount;
    int32_t item1;
    sjs_string item2;
};

struct td_sjs_tuple3_string_f64_i32 {
    sjs_string item1;
    double item2;
    int32_t item3;
};

struct td_sjs_tuple3_string_f64_i32_heap {
    int _refCount;
    sjs_string item1;
    double item2;
    int32_t item3;
};

void sjf_anon1(sjs_anon1* _this);
void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* to);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_heap(sjs_anon1_heap* _this);
void sjf_anon2(sjs_anon2* _this);
void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* to);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon2_heap(sjs_anon2_heap* _this);
void sjf_anon3(sjs_anon3* _this);
void sjf_anon3_copy(sjs_anon3* _this, sjs_anon3* to);
void sjf_anon3_destroy(sjs_anon3* _this);
void sjf_anon3_heap(sjs_anon3_heap* _this);
void sjf_anon4(sjs_anon4* _this);
void sjf_anon4_copy(sjs_anon4* _this, sjs_anon4* to);
void sjf_anon4_destroy(sjs_anon4* _this);
void sjf_anon4_heap(sjs_anon4_heap* _this);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* to);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char_heap* _this);
void sjf_func(sjs_tuple2_i32_string* _return);
void sjf_func_heap(sjs_tuple2_i32_string_heap** _return);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* to);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string_heap* _this);
void sjf_tuple2_i32_string(sjs_tuple2_i32_string* _this);
void sjf_tuple2_i32_string_copy(sjs_tuple2_i32_string* _this, sjs_tuple2_i32_string* to);
void sjf_tuple2_i32_string_destroy(sjs_tuple2_i32_string* _this);
void sjf_tuple2_i32_string_heap(sjs_tuple2_i32_string_heap* _this);
void sjf_tuple3_string_f64_i32(sjs_tuple3_string_f64_i32* _this);
void sjf_tuple3_string_f64_i32_copy(sjs_tuple3_string_f64_i32* _this, sjs_tuple3_string_f64_i32* to);
void sjf_tuple3_string_f64_i32_destroy(sjs_tuple3_string_f64_i32* _this);
void sjf_tuple3_string_f64_i32_heap(sjs_tuple3_string_f64_i32_heap* _this);


void sjf_anon1(sjs_anon1* _this) {
}

void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* to) {
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1_heap* _this) {
}

void sjf_anon2(sjs_anon2* _this) {
}

void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* to) {
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_anon2_heap(sjs_anon2_heap* _this) {
}

void sjf_anon3(sjs_anon3* _this) {
}

void sjf_anon3_copy(sjs_anon3* _this, sjs_anon3* to) {
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

void sjf_anon3_heap(sjs_anon3_heap* _this) {
}

void sjf_anon4(sjs_anon4* _this) {
}

void sjf_anon4_copy(sjs_anon4* _this, sjs_anon4* to) {
}

void sjf_anon4_destroy(sjs_anon4* _this) {
}

void sjf_anon4_heap(sjs_anon4_heap* _this) {
}

void sjf_array_char(sjs_array_char* _this) {
    
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
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* to) {
    _this->size = to->size;
    _this->data = to->data;
    _this->_isGlobal = to->_isGlobal;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    
	if (!_this->_isGlobal && _this->data) {
		free((char*)_this->data);
		_this->data = 0;	
	}
;
}

void sjf_array_char_heap(sjs_array_char_heap* _this) {
    
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
}

void sjf_func(sjs_tuple2_i32_string* _return) {
    _return->item1 = 1;
    _return->item2.count = 3;
    _return->item2.data.size = 4;
    _return->item2.data.data = (uintptr_t)sjg_string1;
    _return->item2.data._isGlobal = false;
    sjf_array_char(&_return->item2.data);
    sjf_string(&_return->item2);
    sjf_tuple2_i32_string(_return);
}

void sjf_func_heap(sjs_tuple2_i32_string_heap** _return) {
    (*_return) = (sjs_tuple2_i32_string_heap*)malloc(sizeof(sjs_tuple2_i32_string_heap));
    (*_return)->_refCount = 1;
    (*_return)->item1 = 1;
    (*_return)->item2.count = 3;
    (*_return)->item2.data.size = 4;
    (*_return)->item2.data.data = (uintptr_t)sjg_string3;
    (*_return)->item2.data._isGlobal = false;
    sjf_array_char(&(*_return)->item2.data);
    sjf_string(&(*_return)->item2);
    sjf_tuple2_i32_string_heap((*_return));
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_copy(sjs_string* _this, sjs_string* to) {
    _this->count = to->count;
    sjf_array_char_copy(&_this->data, &to->data);
}

void sjf_string_destroy(sjs_string* _this) {
}

void sjf_string_heap(sjs_string_heap* _this) {
}

void sjf_tuple2_i32_string(sjs_tuple2_i32_string* _this) {
}

void sjf_tuple2_i32_string_copy(sjs_tuple2_i32_string* _this, sjs_tuple2_i32_string* to) {
    _this->item1 = to->item1;
    sjf_string_copy(&_this->item2, &to->item2);
}

void sjf_tuple2_i32_string_destroy(sjs_tuple2_i32_string* _this) {
}

void sjf_tuple2_i32_string_heap(sjs_tuple2_i32_string_heap* _this) {
}

void sjf_tuple3_string_f64_i32(sjs_tuple3_string_f64_i32* _this) {
}

void sjf_tuple3_string_f64_i32_copy(sjs_tuple3_string_f64_i32* _this, sjs_tuple3_string_f64_i32* to) {
    sjf_string_copy(&_this->item1, &to->item1);
    _this->item2 = to->item2;
    _this->item3 = to->item3;
}

void sjf_tuple3_string_f64_i32_destroy(sjs_tuple3_string_f64_i32* _this) {
}

void sjf_tuple3_string_f64_i32_heap(sjs_tuple3_string_f64_i32_heap* _this) {
}

int main() {
    int32_t a;
    sjs_string* b;
    int32_t c;
    sjs_anon1* console;
    sjs_anon4* convert;
    sjs_string* d;
    int32_t dotTemp1;
    sjs_string dotTemp2;
    int32_t dotTemp3;
    sjs_string dotTemp4;
    int32_t dotTemp5;
    sjs_string dotTemp6;
    sjs_string dotTemp7;
    double dotTemp8;
    sjs_string* e;
    double f;
    sjs_anon2* parse;
    sjs_anon3* random;
    sjs_anon4 sjt_call1;
    sjs_anon3 sjt_call2;
    sjs_anon2 sjt_call3;
    sjs_anon1 sjt_call4;
    sjs_tuple2_i32_string sjt_call5;
    sjs_tuple2_i32_string sjt_call6;
    sjs_tuple2_i32_string sjt_call7;
    sjs_tuple3_string_f64_i32 sjt_call8;
    sjs_tuple2_i32_string* sjt_dot1;
    sjs_tuple2_i32_string* sjt_dot2;
    sjs_tuple2_i32_string* sjt_dot3;
    sjs_tuple2_i32_string* sjt_dot4;
    sjs_tuple2_i32_string* sjt_dot5;
    sjs_tuple2_i32_string* sjt_dot6;
    sjs_tuple3_string_f64_i32* sjt_dot7;
    sjs_tuple3_string_f64_i32* sjt_dot8;
    sjs_tuple2_i32_string* t;
    sjs_tuple2_i32_string* tupleResult1;
    sjs_tuple2_i32_string* tupleResult2;
    sjs_tuple3_string_f64_i32* tupleResult3;

    sjf_anon4(&sjt_call1);
    convert = &sjt_call1;
    sjf_anon3(&sjt_call2);
    random = &sjt_call2;
    sjf_anon2(&sjt_call3);
    parse = &sjt_call3;
    sjf_anon1(&sjt_call4);
    console = &sjt_call4;
    sjf_func(&sjt_call5);
    t = &sjt_call5;
    sjt_dot1 = t;
    dotTemp1 = sjt_dot1->item1;
    a = dotTemp1;
    sjt_dot2 = t;
    dotTemp2 = sjt_dot2->item2;
    b = &dotTemp2;
    sjf_func(&sjt_call6);
    tupleResult1 = &sjt_call6;
    sjt_dot3 = tupleResult1;
    dotTemp3 = sjt_dot3->item1;
    a = dotTemp3;
    sjt_dot4 = tupleResult1;
    dotTemp4 = sjt_dot4->item2;
    b = &dotTemp4;
    sjf_func(&sjt_call7);
    tupleResult2 = &sjt_call7;
    sjt_dot5 = tupleResult2;
    dotTemp5 = sjt_dot5->item1;
    c = dotTemp5;
    sjt_dot6 = tupleResult2;
    dotTemp6 = sjt_dot6->item2;
    d = &dotTemp6;
    sjt_call8.item1.count = 3;
    sjt_call8.item1.data.size = 4;
    sjt_call8.item1.data.data = (uintptr_t)sjg_string2;
    sjt_call8.item1.data._isGlobal = false;
    sjf_array_char(&sjt_call8.item1.data);
    sjf_string(&sjt_call8.item1);
    sjt_call8.item2 = 1.0;
    sjt_call8.item3 = 4;
    sjf_tuple3_string_f64_i32(&sjt_call8);
    tupleResult3 = &sjt_call8;
    sjt_dot7 = tupleResult3;
    dotTemp7 = sjt_dot7->item1;
    e = &dotTemp7;
    sjt_dot8 = tupleResult3;
    dotTemp8 = sjt_dot8->item2;
    f = dotTemp8;

    sjf_string_destroy(&dotTemp2);
    sjf_string_destroy(&dotTemp4);
    sjf_string_destroy(&dotTemp6);
    sjf_string_destroy(&dotTemp7);
    sjf_anon4_destroy(&sjt_call1);
    sjf_anon3_destroy(&sjt_call2);
    sjf_anon2_destroy(&sjt_call3);
    sjf_anon1_destroy(&sjt_call4);
    sjf_tuple2_i32_string_destroy(&sjt_call5);
    sjf_tuple2_i32_string_destroy(&sjt_call6);
    sjf_tuple2_i32_string_destroy(&sjt_call7);
    sjf_tuple3_string_f64_i32_destroy(&sjt_call8);
    return 0;
}
