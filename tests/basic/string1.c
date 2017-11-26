#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
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

const char* sjg_string1 = "he\"llo";
const char* sjg_string2 = "he\nllo";
const char* sjg_string3 = "hello";

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

sjs_string a;
sjs_string b;
char c;
sjs_anon1 console;
sjs_anon4 convert;
char d;
char e;
sjs_string f;
char h;
bool i;
bool j;
bool k;
bool l;
sjs_anon2 parse;
sjs_anon3 random;
char sjt_compare1;
char sjt_compare2;
sjs_string* sjt_compare3;
sjs_string* sjt_compare4;
sjs_string* sjt_dot1;
sjs_string* sjt_dot3;
sjs_string* sjt_dot6;
int32_t sjt_functionParam2;
sjs_string* sjt_functionParam4;
sjs_string* sjt_functionParam6;

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
void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_heap(sjs_array_char_heap* _this);
void sjf_array_char_isEqual(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_array_char_isLessOrEqual(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* to);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_heap(sjs_string_heap* _this);
void sjf_string_isEqual(sjs_string* _parent, sjs_string* test, bool* _return);
void sjf_string_isLessOrEqual(sjs_string* _parent, sjs_string* test, bool* _return);
void main_destroy();

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

void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return) {
    
		if (index >= _parent->size || index < 0) {
			printf("getAt: out of bounds\n");
			exit(-1);
		}

		char* p = (char*)_parent->data;
		(*_return) = p[index];
;		
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

void sjf_array_char_isEqual(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
    
		if (_parent->size != test->size) {
			*_return = false;
		}

		*_return = memcmp((void*)_parent->data, (void*)test->data, _parent->size * sizeof(char)) == 0;		
	;
}

void sjf_array_char_isLessOrEqual(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
    
		*_return = memcmp((void*)_parent->data, (void*)test->data, (_parent->size < test->size ? _parent->size : test->size) * sizeof(char)) <= 0;		
	;
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_copy(sjs_string* _this, sjs_string* to) {
    _this->count = to->count;
    sjf_array_char_copy(&_this->data, &to->data);
}

void sjf_string_destroy(sjs_string* _this) {
}

void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return) {
    sjs_array_char dotTemp1;
    sjs_array_char* sjt_dot2;
    int32_t sjt_functionParam1;

    dotTemp1 = _parent->data;
    sjt_dot2 = &dotTemp1;
    sjt_functionParam1 = index;
    sjf_array_char_getAt(sjt_dot2, sjt_functionParam1, &(*_return));

    sjf_array_char_destroy(&dotTemp1);
}

void sjf_string_heap(sjs_string_heap* _this) {
}

void sjf_string_isEqual(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_array_char dotTemp2;
    sjs_array_char dotTemp3;
    sjs_array_char* sjt_dot4;
    sjs_string* sjt_dot5;
    sjs_array_char* sjt_functionParam3;

    dotTemp2 = _parent->data;
    sjt_dot4 = &dotTemp2;
    sjt_dot5 = test;
    dotTemp3 = sjt_dot5->data;
    sjt_functionParam3 = &dotTemp3;
    sjf_array_char_isEqual(sjt_dot4, sjt_functionParam3, &(*_return));

    sjf_array_char_destroy(&dotTemp2);
    sjf_array_char_destroy(&dotTemp3);
}

void sjf_string_isLessOrEqual(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_array_char dotTemp4;
    sjs_array_char dotTemp5;
    sjs_array_char* sjt_dot7;
    sjs_string* sjt_dot8;
    sjs_array_char* sjt_functionParam5;

    dotTemp4 = _parent->data;
    sjt_dot7 = &dotTemp4;
    sjt_dot8 = test;
    dotTemp5 = sjt_dot8->data;
    sjt_functionParam5 = &dotTemp5;
    sjf_array_char_isLessOrEqual(sjt_dot7, sjt_functionParam5, &(*_return));

    sjf_array_char_destroy(&dotTemp4);
    sjf_array_char_destroy(&dotTemp5);
}

int main() {
    sjf_anon4(&convert);
    sjf_anon3(&random);
    sjf_anon2(&parse);
    sjf_anon1(&console);
    a.count = 7;
    a.data.size = 8;
    a.data.data = (uintptr_t)sjg_string1;
    a.data._isGlobal = false;
    sjf_array_char(&a.data);
    sjf_string(&a);
    b.count = 7;
    b.data.size = 8;
    b.data.data = (uintptr_t)sjg_string2;
    b.data._isGlobal = false;
    sjf_array_char(&b.data);
    sjf_string(&b);
    c = 'a';
    d = '\'';
    e = '\n';
    f.count = 5;
    f.data.size = 6;
    f.data.data = (uintptr_t)sjg_string3;
    f.data._isGlobal = false;
    sjf_array_char(&f.data);
    sjf_string(&f);
    sjt_dot1 = &a;
    sjt_functionParam2 = 0;
    sjf_string_getAt(sjt_dot1, sjt_functionParam2, &h);
    sjt_compare1 = h;
    sjt_compare2 = 'h';
    i = sjt_compare1 == sjt_compare2;
    sjt_dot3 = &f;
    sjt_functionParam4 = &a;
    sjf_string_isEqual(sjt_dot3, sjt_functionParam4, &j);
    sjt_dot6 = &f;
    sjt_functionParam6 = &a;
    sjf_string_isLessOrEqual(sjt_dot6, sjt_functionParam6, &k);
    sjt_compare3 = &f;
    sjt_compare4 = &a;
    l = sjt_compare3 == sjt_compare4;
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_string_destroy(&a);
    sjf_string_destroy(&b);
    sjf_anon1_destroy(&console);
    sjf_anon4_destroy(&convert);
    sjf_string_destroy(&f);
    sjf_anon2_destroy(&parse);
    sjf_anon3_destroy(&random);
}
