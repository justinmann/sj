#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* sjg_string1 = "5";

typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_string sjs_string;

int sji_foo_typeId = 1;
int sjs_anon1_typeId = 2;
int sjs_anon2_typeId = 3;
int sjs_anon3_typeId = 4;
int sjs_array_char_typeId = 5;
int sjs_class_typeId = 6;
int sjs_object_typeId = 7;
int sjs_string_typeId = 8;

struct td_sji_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
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
void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_class(sjs_class* _this, sjs_class** _return);
sji_foo* sjf_class_asFoo(sjs_class* _this);
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

sji_foo* sjf_class_asFoo(sjs_class* _this) {
    sji_foo* _interface = (sji_foo*)malloc(sizeof(sji_foo));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->test = sjf_class_test;
    return _interface;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_test(sjs_class* _parent, sjs_string** _return) {
    sjs_array_char* sjv_temp4;
    sjs_string* sjv_temp5;

    sjv_temp4 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp4->_refCount = 1;
    sjv_temp4->size = 1;
    sjv_temp4->data = (uintptr_t)sjg_string1;
    sjv_temp4->_isGlobal = false;
    sjf_array_char(sjv_temp4, &sjv_temp4);
    sjv_temp5 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp5->_refCount = 1;
    sjv_temp5->count = 0;
    sjv_temp5->data = sjv_temp4;
    sjv_temp5->data->_refCount++;
    sjf_string(sjv_temp5, &sjv_temp5);
    sjv_temp5->_refCount++;

    sjv_temp4->_refCount--;
    if (sjv_temp4->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp4);
        free(sjv_temp4);
    }
    sjv_temp5->_refCount--;
    if (sjv_temp5->_refCount <= 0) {
        sjf_string_destroy(sjv_temp5);
        free(sjv_temp5);
    }

    *_return = sjv_temp5;
}

void sjf_global(void) {
    sjs_anon3 sjd_temp1;
    sjs_anon2 sjd_temp2;
    sjs_anon1 sjd_temp3;
    sjs_class sjd_temp4;
    sji_foo* a;
    sjs_anon1* console;
    sjs_anon2* parse;
    sjs_anon3* random;
    uintptr_t result1;
    sji_foo* result2;
    sjs_anon3* sjv_temp1;
    sjs_anon2* sjv_temp2;
    sjs_anon1* sjv_temp3;
    sjs_class* sjv_temp6;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_anon3(sjv_temp1, &sjv_temp1);
    random = sjv_temp1;
    random->_refCount++;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjf_anon2(sjv_temp2, &sjv_temp2);
    parse = sjv_temp2;
    parse->_refCount++;
    result1 = (uintptr_t)0;
    sjv_temp3 = &sjd_temp3;
    sjv_temp3->_refCount = 1;
    sjv_temp3->_fd = result1;
    sjf_anon1(sjv_temp3, &sjv_temp3);
    console = sjv_temp3;
    console->_refCount++;
    sjv_temp6 = &sjd_temp4;
    sjv_temp6->_refCount = 1;
    sjf_class(sjv_temp6, &sjv_temp6);
    result2 = sjf_class_asFoo(sjv_temp6);
    a = result2;
    a->_refCount++;
    sjf_anon3_destroy(&sjd_temp1);
    sjf_anon2_destroy(&sjd_temp2);
    sjf_anon1_destroy(&sjd_temp3);
    sjf_class_destroy(&sjd_temp4);
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
