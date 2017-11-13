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

const char* sjg_string1 = "5";

#define sji_foo_typeId 1
#define sjs_anon1_typeId 2
#define sjs_anon2_typeId 3
#define sjs_anon3_typeId 4
#define sjs_anon4_typeId 5
#define sjs_array_char_typeId 6
#define sjs_class_typeId 7
#define sjs_object_typeId 8
#define sjs_string_typeId 9

typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_anon4 sjs_anon4;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_string sjs_string;

struct td_sji_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*test)(sjs_object* _parent, sjs_string** _return);
};

struct td_sjs_anon1 {
    int _refCount;
    uintptr_t _fd;
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

struct td_sjs_class {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_string {
    int _refCount;
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
void sjf_class(sjs_class* _this, sjs_class** _return);
sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId);
sji_foo* sjf_class_as_sji_foo(sjs_class* _this);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_test(sjs_class* _parent, sjs_string** _return);
void sjf_global(void);
void sjf_string(sjs_string* _this, sjs_string** _return);
void sjf_string_destroy(sjs_string* _this);
void sji_foo_destroy(sji_foo* _this);

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return) {
     
		
		_this->_fd = (uintptr_t)stdout;
	;
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
			_this->data = (uintptr_t)malloc(_this->size * sizeof(char));
		}
	;
    _this->_refCount++;

    *_return = _this;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    
	if (!_this->_isGlobal) {
		free((char*)_this->data);	
	}
;
}

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId) {
    switch (typeId) {
        case sji_foo_typeId: return (sjs_object*)sjf_class_as_sji_foo(_this);
    }

    return 0;
}

sji_foo* sjf_class_as_sji_foo(sjs_class* _this) {
    sji_foo* _interface = (sji_foo*)malloc(sizeof(sji_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(sjs_object*))sjf_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_asInterface;
    _interface->test = (void(*)(sjs_object*, sjs_string**))sjf_class_test;
    return _interface;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_test(sjs_class* _parent, sjs_string** _return) {
    sjs_array_char* sjv_temp5;
    sjs_string* sjv_temp6;

    sjv_temp5 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp5->_refCount = 1;
    sjv_temp5->size = 1;
    sjv_temp5->data = (uintptr_t)sjg_string1;
    sjv_temp5->_isGlobal = false;
    sjf_array_char(sjv_temp5, &sjv_temp5);
    sjv_temp6 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp6->_refCount = 1;
    sjv_temp6->count = 0;
    sjv_temp6->data = sjv_temp5;
    sjv_temp6->data->_refCount++;
    sjf_string(sjv_temp6, &sjv_temp6);
    sjv_temp6->_refCount++;

    sjv_temp5->_refCount--;
    if (sjv_temp5->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp5);
        free(sjv_temp5);
    }
    sjv_temp6->_refCount--;
    if (sjv_temp6->_refCount <= 0) {
        sjf_string_destroy(sjv_temp6);
        free(sjv_temp6);
    }

    *_return = sjv_temp6;
}

void sjf_global(void) {
    sjs_anon4 sjd_temp1;
    sjs_anon3 sjd_temp2;
    sjs_anon2 sjd_temp3;
    sjs_anon1 sjd_temp4;
    sjs_class sjd_temp5;
    sji_foo* a;
    sjs_anon1* console;
    sjs_anon4* convert;
    sjs_anon2* parse;
    sjs_anon3* random;
    uintptr_t result1;
    sji_foo* result2;
    sjs_string* result3;
    sjs_anon4* sjv_temp1;
    sjs_anon3* sjv_temp2;
    sjs_anon2* sjv_temp3;
    sjs_anon1* sjv_temp4;
    sjs_class* sjv_temp7;

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
    result1 = (uintptr_t)0;
    sjv_temp4 = &sjd_temp4;
    sjv_temp4->_refCount = 1;
    sjv_temp4->_fd = result1;
    sjf_anon1(sjv_temp4, &sjv_temp4);
    console = sjv_temp4;
    console->_refCount++;
    sjv_temp7 = &sjd_temp5;
    sjv_temp7->_refCount = 1;
    sjf_class(sjv_temp7, &sjv_temp7);
    result2 = sjf_class_as_sji_foo(sjv_temp7);
    a = result2;
    a->_refCount++;
    result2->_refCount--;
    if (result2->_refCount <= 0) {
        sji_foo_destroy(result2);
        free(result2);
    }

    result3 = 0;

    a->test(a->_parent, &result3);

    a->_refCount--;
    if (a->_refCount <= 0) {
        sji_foo_destroy(a);
        free(a);
    }
    result3->_refCount--;
    if (result3->_refCount <= 0) {
        sjf_string_destroy(result3);
        free(result3);
    }
    sjf_anon4_destroy(&sjd_temp1);
    sjf_anon3_destroy(&sjd_temp2);
    sjf_anon2_destroy(&sjd_temp3);
    sjf_anon1_destroy(&sjd_temp4);
    sjf_class_destroy(&sjd_temp5);
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

void sji_foo_destroy(sji_foo* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main() {
    sjf_global();

    return 0;
}
