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

const char* sjg_string1 = "he\"llo";
const char* sjg_string2 = "he\nllo";
const char* sjg_string3 = "hello";

#define sjs_anon1_typeId 1
#define sjs_anon2_typeId 2
#define sjs_anon3_typeId 3
#define sjs_anon4_typeId 4
#define sjs_array_char_typeId 5
#define sjs_global_typeId 6
#define sjs_object_typeId 7
#define sjs_string_typeId 8

typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_anon4 sjs_anon4;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_global sjs_global;
typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_string sjs_string;

struct td_sjs_anon1 {
    int _refCount;
};

struct td_sjs_anon2 {
    int _refCount;
};

struct td_sjs_anon3 {
    int _refCount;
};

struct td_sjs_anon4 {
    int _refCount;
};

struct td_sjs_array_char {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_global {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_string {
    int _refCount;
    sjs_global* _parent;
    int32_t count;
    sjs_array_char* data;
};

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon2(sjs_anon2* _this, sjs_anon2** _return);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon3(sjs_anon3* _this, sjs_anon3** _return);
void sjf_anon3_destroy(sjs_anon3* _this);
void sjf_anon4(sjs_anon4* _this, sjs_anon4** _return);
void sjf_anon4_destroy(sjs_anon4* _this);
void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_isEqual(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_array_char_isLessOrEqual(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_global_destroy(sjs_global* _this);
void sjf_string(sjs_string* _this, sjs_string** _return);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_isEqual(sjs_string* _parent, sjs_string* test, bool* _return);
void sjf_string_isLessOrEqual(sjs_string* _parent, sjs_string* test, bool* _return);

sjs_global global;
sjs_anon4 sjd_temp1;
sjs_anon3 sjd_temp2;
sjs_anon2 sjd_temp3;
sjs_anon1 sjd_temp4;
sjs_string sjd_temp5;
sjs_string sjd_temp6;
sjs_string sjd_temp7;

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon2(sjs_anon2* _this, sjs_anon2** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_anon3(sjs_anon3* _this, sjs_anon3** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

void sjf_anon4(sjs_anon4* _this, sjs_anon4** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon4_destroy(sjs_anon4* _this) {
}

void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return) {
    
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
    _this->_refCount++;

    *_return = _this;
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
		char val = p[index];
#if !true
		if (val == 0) {
			printf("getAt: value is not defined at %d\n", index);
			exit(-1);
		}
#endif
		*_return = val;		
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

void sjf_global_destroy(sjs_global* _this) {
}

void sjf_string(sjs_string* _this, sjs_string** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_string_destroy(sjs_string* _this) {
    _this->data->_refCount--;
    if (_this->data->_refCount <= 0) {
        sjf_array_char_destroy(_this->data);
        free(_this->data);
    }
}

void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return) {
    sjs_array_char* dotTemp1;
    char result2;

    dotTemp1 = _parent->data;
    result2 = 0;
    sjf_array_char_getAt(dotTemp1, index, &result2);

    *_return = result2;
}

void sjf_string_isEqual(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_array_char* dotTemp2;
    sjs_array_char* dotTemp3;
    bool result5;

    dotTemp2 = _parent->data;
    result5 = 0;
    dotTemp3 = test->data;
    sjf_array_char_isEqual(dotTemp2, dotTemp3, &result5);

    *_return = result5;
}

void sjf_string_isLessOrEqual(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_array_char* dotTemp4;
    sjs_array_char* dotTemp5;
    bool result7;

    dotTemp4 = _parent->data;
    result7 = 0;
    dotTemp5 = test->data;
    sjf_array_char_isLessOrEqual(dotTemp4, dotTemp5, &result7);

    *_return = result7;
}

int main() {
    global._refCount = 1;
    sjs_global* _this = &global;
    sjs_string* a;
    sjs_string* b;
    char c;
    sjs_anon1* console;
    sjs_anon4* convert;
    char d;
    char e;
    sjs_string* f;
    char h;
    bool i;
    bool j;
    bool k;
    bool l;
    sjs_anon2* parse;
    sjs_anon3* random;
    char result1;
    bool result3;
    bool result4;
    bool result6;
    bool result8;
    sjs_anon4* sjv_temp1;
    sjs_string* sjv_temp10;
    sjs_anon3* sjv_temp2;
    sjs_anon2* sjv_temp3;
    sjs_anon1* sjv_temp4;
    sjs_array_char* sjv_temp5;
    sjs_string* sjv_temp6;
    sjs_array_char* sjv_temp7;
    sjs_string* sjv_temp8;
    sjs_array_char* sjv_temp9;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_anon4(sjv_temp1, &sjv_temp1);
    convert = sjv_temp1;
    convert->_refCount++;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjf_anon3(sjv_temp2, &sjv_temp2);
    random = sjv_temp2;
    random->_refCount++;
    sjv_temp3 = &sjd_temp3;
    sjv_temp3->_refCount = 1;
    sjf_anon2(sjv_temp3, &sjv_temp3);
    parse = sjv_temp3;
    parse->_refCount++;
    sjv_temp4 = &sjd_temp4;
    sjv_temp4->_refCount = 1;
    sjf_anon1(sjv_temp4, &sjv_temp4);
    console = sjv_temp4;
    console->_refCount++;
    sjv_temp5 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp5->_refCount = 1;
    sjv_temp5->size = 8;
    sjv_temp5->data = (uintptr_t)sjg_string1;
    sjv_temp5->_isGlobal = false;
    sjf_array_char(sjv_temp5, &sjv_temp5);
    sjv_temp6 = &sjd_temp5;
    sjv_temp6->_refCount = 1;
    sjv_temp6->count = 7;
    sjv_temp6->data = sjv_temp5;
    sjv_temp6->data->_refCount++;
    sjf_string(sjv_temp6, &sjv_temp6);
    a = sjv_temp6;
    a->_refCount++;
    sjv_temp7 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp7->_refCount = 1;
    sjv_temp7->size = 8;
    sjv_temp7->data = (uintptr_t)sjg_string2;
    sjv_temp7->_isGlobal = false;
    sjf_array_char(sjv_temp7, &sjv_temp7);
    sjv_temp8 = &sjd_temp6;
    sjv_temp8->_refCount = 1;
    sjv_temp8->count = 7;
    sjv_temp8->data = sjv_temp7;
    sjv_temp8->data->_refCount++;
    sjf_string(sjv_temp8, &sjv_temp8);
    b = sjv_temp8;
    b->_refCount++;
    c = 'a';
    d = '\'';
    e = '\n';
    sjv_temp9 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp9->_refCount = 1;
    sjv_temp9->size = 6;
    sjv_temp9->data = (uintptr_t)sjg_string3;
    sjv_temp9->_isGlobal = false;
    sjf_array_char(sjv_temp9, &sjv_temp9);
    sjv_temp10 = &sjd_temp7;
    sjv_temp10->_refCount = 1;
    sjv_temp10->count = 5;
    sjv_temp10->data = sjv_temp9;
    sjv_temp10->data->_refCount++;
    sjf_string(sjv_temp10, &sjv_temp10);
    f = sjv_temp10;
    f->_refCount++;
    result1 = 0;
    sjf_string_getAt(a, 0, &result1);
    h = result1;
    result3 = h == 'h';
    i = result3;
    result4 = 0;
    sjf_string_isEqual(f, a, &result4);
    j = result4;
    result6 = 0;
    sjf_string_isLessOrEqual(f, a, &result6);
    k = result6;
    result8 = f == a;
    l = result8;

    sjv_temp5->_refCount--;
    if (sjv_temp5->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp5);
        free(sjv_temp5);
    }
    sjv_temp7->_refCount--;
    if (sjv_temp7->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp7);
        free(sjv_temp7);
    }
    sjv_temp9->_refCount--;
    if (sjv_temp9->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp9);
        free(sjv_temp9);
    }
    sjf_anon4_destroy(&sjd_temp1);
    sjf_anon3_destroy(&sjd_temp2);
    sjf_anon2_destroy(&sjd_temp3);
    sjf_anon1_destroy(&sjd_temp4);
    sjf_string_destroy(&sjd_temp5);
    sjf_string_destroy(&sjd_temp6);
    sjf_string_destroy(&sjd_temp7);
    sjf_global_destroy(&global);
    return 0;
}
