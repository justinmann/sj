#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* sjg_string1 = "he\"llo";
const char* sjg_string2 = "he\nllo";
const char* sjg_string3 = "hello";

typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_global sjs_global;
typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_string sjs_string;

int sjs_anon1_typeId = 1;
int sjs_anon2_typeId = 2;
int sjs_anon3_typeId = 3;
int sjs_array_char_typeId = 4;
int sjs_global_typeId = 5;
int sjs_object_typeId = 6;
int sjs_string_typeId = 7;

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
void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_isEqual(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_array_char_isLessOrEqual(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_global(sjs_global* _this);
void sjf_global_destroy(sjs_global* _this);
void sjf_string(sjs_string* _this, sjs_string** _return);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_isEqual(sjs_string* _parent, sjs_string* test, bool* _return);
void sjf_string_isLessOrEqual(sjs_string* _parent, sjs_string* test, bool* _return);

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

void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return) {
    
		

		if (index >= _parent->size || index < 0) {
			exit(-1);
		}

		char* p = (char*)_parent->data;
		char val = p[index];
		if (!true) {
			if (val == 0) {
				exit(-1);
			}
		}
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

void sjf_global(sjs_global* _this) {
    sjs_anon3 sjd_temp1;
    sjs_anon2 sjd_temp2;
    sjs_anon1 sjd_temp3;
    sjs_string sjd_temp4;
    sjs_string sjd_temp5;
    sjs_string sjd_temp6;
    sjs_string* a;
    sjs_string* b;
    char c;
    sjs_anon1* console;
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
    uintptr_t result1;
    char result2;
    bool result4;
    bool result5;
    bool result7;
    bool result9;
    sjs_anon3* sjv_temp1;
    sjs_anon2* sjv_temp2;
    sjs_anon1* sjv_temp3;
    sjs_array_char* sjv_temp4;
    sjs_string* sjv_temp5;
    sjs_array_char* sjv_temp6;
    sjs_string* sjv_temp7;
    sjs_array_char* sjv_temp8;
    sjs_string* sjv_temp9;

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
    sjv_temp4 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp4->_refCount = 1;
    sjv_temp4->size = 7;
    sjv_temp4->data = (uintptr_t)sjg_string1;
    sjv_temp4->_isGlobal = false;
    sjf_array_char(sjv_temp4, &sjv_temp4);
    sjv_temp5 = &sjd_temp4;
    sjv_temp5->_refCount = 1;
    sjv_temp5->count = 6;
    sjv_temp5->data = sjv_temp4;
    sjv_temp5->data->_refCount++;
    sjf_string(sjv_temp5, &sjv_temp5);
    a = sjv_temp5;
    a->_refCount++;
    sjv_temp6 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp6->_refCount = 1;
    sjv_temp6->size = 7;
    sjv_temp6->data = (uintptr_t)sjg_string2;
    sjv_temp6->_isGlobal = false;
    sjf_array_char(sjv_temp6, &sjv_temp6);
    sjv_temp7 = &sjd_temp5;
    sjv_temp7->_refCount = 1;
    sjv_temp7->count = 6;
    sjv_temp7->data = sjv_temp6;
    sjv_temp7->data->_refCount++;
    sjf_string(sjv_temp7, &sjv_temp7);
    b = sjv_temp7;
    b->_refCount++;
    c = 'a';
    d = '\'';
    e = '\n';
    sjv_temp8 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp8->_refCount = 1;
    sjv_temp8->size = 5;
    sjv_temp8->data = (uintptr_t)sjg_string3;
    sjv_temp8->_isGlobal = false;
    sjf_array_char(sjv_temp8, &sjv_temp8);
    sjv_temp9 = &sjd_temp6;
    sjv_temp9->_refCount = 1;
    sjv_temp9->count = 4;
    sjv_temp9->data = sjv_temp8;
    sjv_temp9->data->_refCount++;
    sjf_string(sjv_temp9, &sjv_temp9);
    f = sjv_temp9;
    f->_refCount++;
    result2 = 0;
    sjf_string_getAt(a, 0, &result2);
    h = result2;
    result4 = h == 'h';
    i = result4;
    result5 = 0;
    sjf_string_isEqual(f, a, &result5);
    j = result5;
    result7 = 0;
    sjf_string_isLessOrEqual(f, a, &result7);
    k = result7;
    result9 = f == a;
    l = result9;

    sjv_temp4->_refCount--;
    if (sjv_temp4->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp4);
        free(sjv_temp4);
    }
    sjv_temp6->_refCount--;
    if (sjv_temp6->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp6);
        free(sjv_temp6);
    }
    sjv_temp8->_refCount--;
    if (sjv_temp8->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp8);
        free(sjv_temp8);
    }
    sjf_anon3_destroy(&sjd_temp1);
    sjf_anon2_destroy(&sjd_temp2);
    sjf_anon1_destroy(&sjd_temp3);
    sjf_string_destroy(&sjd_temp4);
    sjf_string_destroy(&sjd_temp5);
    sjf_string_destroy(&sjd_temp6);
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
    char result3;
    sjs_array_char* temp1;

    temp1 = _parent->data;
    result3 = 0;
    sjf_array_char_getAt(temp1, index, &result3);

    temp1->_refCount--;
    if (temp1->_refCount <= 0) {
        sjf_array_char_destroy(temp1);
        free(temp1);
    }

    *_return = result3;
}

void sjf_string_isEqual(sjs_string* _parent, sjs_string* test, bool* _return) {
    bool result6;
    sjs_array_char* temp2;
    sjs_array_char* temp3;

    temp2 = _parent->data;
    result6 = 0;
    temp3 = test->data;
    sjf_array_char_isEqual(temp2, temp3, &result6);

    temp2->_refCount--;
    if (temp2->_refCount <= 0) {
        sjf_array_char_destroy(temp2);
        free(temp2);
    }
    temp3->_refCount--;
    if (temp3->_refCount <= 0) {
        sjf_array_char_destroy(temp3);
        free(temp3);
    }

    *_return = result6;
}

void sjf_string_isLessOrEqual(sjs_string* _parent, sjs_string* test, bool* _return) {
    bool result8;
    sjs_array_char* temp4;
    sjs_array_char* temp5;

    temp4 = _parent->data;
    result8 = 0;
    temp5 = test->data;
    sjf_array_char_isLessOrEqual(temp4, temp5, &result8);

    temp4->_refCount--;
    if (temp4->_refCount <= 0) {
        sjf_array_char_destroy(temp4);
        free(temp4);
    }
    temp5->_refCount--;
    if (temp5->_refCount <= 0) {
        sjf_array_char_destroy(temp5);
        free(temp5);
    }

    *_return = result8;
}

int main() {
    sjs_global sjd_temp7;
    sjs_global* sjv_temp10;

    sjv_temp10 = &sjd_temp7;
    sjv_temp10->_refCount = 1;
    sjf_global(sjv_temp10);
    sjf_global_destroy(&sjd_temp7);

    return 0;
}
