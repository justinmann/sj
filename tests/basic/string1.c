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
typedef struct td_sjs_string sjs_string;

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

struct td_sjs_string {
    int _refCount;
    sjs_global* _parent;
    int32_t count;
    sjs_array_char* data;
};

sjs_anon1* sjf_anon1(sjs_anon1* _this);
void sjf_anon1_destroy(sjs_anon1* _this);
sjs_anon2* sjf_anon2(sjs_anon2* _this);
void sjf_anon2_destroy(sjs_anon2* _this);
sjs_anon3* sjf_anon3(sjs_anon3* _this);
void sjf_anon3_destroy(sjs_anon3* _this);
sjs_array_char* sjf_array_char(sjs_array_char* _this);
void sjf_array_char_destroy(sjs_array_char* _this);
char sjf_array_char_getAt(sjs_array_char* _parent, int32_t index);
bool sjf_array_char_isEqual(sjs_array_char* _parent, sjs_array_char* test);
bool sjf_array_char_isLessOrEqual(sjs_array_char* _parent, sjs_array_char* test);
bool sjf_global(sjs_global* _this);
void sjf_global_destroy(sjs_global* _this);
sjs_string* sjf_string(sjs_string* _this);
void sjf_string_destroy(sjs_string* _this);
char sjf_string_getAt(sjs_string* _parent, int32_t index);
bool sjf_string_isEqual(sjs_string* _parent, sjs_string* test);
bool sjf_string_isLessOrEqual(sjs_string* _parent, sjs_string* test);

sjs_anon1* sjf_anon1(sjs_anon1* _this) {
     
		_this->_fd = (uintptr_t)stdout;
	;
    _this->_refCount++;

    return _this;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

sjs_anon2* sjf_anon2(sjs_anon2* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

sjs_anon3* sjf_anon3(sjs_anon3* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

sjs_array_char* sjf_array_char(sjs_array_char* _this) {
    
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

    return _this;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    
	if (!_this->_isGlobal) {
		free((char*)_this->data);	
	}
;
}

char sjf_array_char_getAt(sjs_array_char* _parent, int32_t index) {
    
		

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
		return val;		
	;
}

bool sjf_array_char_isEqual(sjs_array_char* _parent, sjs_array_char* test) {
    
		

		if (_parent->size != test->size) {
			return false;
		}

		return memcmp((void*)_parent->data, (void*)test->data, _parent->size * sizeof(char)) == 0;		
	;
}

bool sjf_array_char_isLessOrEqual(sjs_array_char* _parent, sjs_array_char* test) {
    
		

		return memcmp((void*)_parent->data, (void*)test->data, (_parent->size < test->size ? _parent->size : test->size) * sizeof(char)) <= 0;		
	;
}

bool sjf_global(sjs_global* _this) {
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
    sjs_string* result10;
    sjs_array_char* result11;
    char result12;
    bool result14;
    bool result15;
    bool result17;
    bool result19;
    sjs_anon3* result2;
    sjs_anon2* result3;
    sjs_anon1* result4;
    uintptr_t result5;
    sjs_string* result6;
    sjs_array_char* result7;
    sjs_string* result8;
    sjs_array_char* result9;
    sjs_anon3 sjd_temp1;
    sjs_anon2 sjd_temp2;
    sjs_anon1 sjd_temp3;
    sjs_string sjd_temp4;
    sjs_string sjd_temp5;
    sjs_string sjd_temp6;
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
    result2 = sjf_anon3(sjv_temp1);
    random = result2;
    random->_refCount++;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    result3 = sjf_anon2(sjv_temp2);
    parse = result3;
    parse->_refCount++;
    result5 = (uintptr_t)0;
    sjv_temp3 = &sjd_temp3;
    sjv_temp3->_refCount = 1;
    sjv_temp3->_fd = result5;
    result4 = sjf_anon1(sjv_temp3);
    console = result4;
    console->_refCount++;
    sjv_temp4 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp4->_refCount = 1;
    sjv_temp4->size = 7;
    sjv_temp4->data = (uintptr_t)sjg_string1;
    sjv_temp4->_isGlobal = false;
    result7 = sjf_array_char(sjv_temp4);
    sjv_temp5 = &sjd_temp4;
    sjv_temp5->_refCount = 1;
    sjv_temp5->count = 6;
    sjv_temp5->data = result7;
    sjv_temp5->data->_refCount++;
    result6 = sjf_string(sjv_temp5);
    a = result6;
    a->_refCount++;
    sjv_temp6 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp6->_refCount = 1;
    sjv_temp6->size = 7;
    sjv_temp6->data = (uintptr_t)sjg_string2;
    sjv_temp6->_isGlobal = false;
    result9 = sjf_array_char(sjv_temp6);
    sjv_temp7 = &sjd_temp5;
    sjv_temp7->_refCount = 1;
    sjv_temp7->count = 6;
    sjv_temp7->data = result9;
    sjv_temp7->data->_refCount++;
    result8 = sjf_string(sjv_temp7);
    b = result8;
    b->_refCount++;
    c = 'a';
    d = '\'';
    e = '\n';
    sjv_temp8 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp8->_refCount = 1;
    sjv_temp8->size = 5;
    sjv_temp8->data = (uintptr_t)sjg_string3;
    sjv_temp8->_isGlobal = false;
    result11 = sjf_array_char(sjv_temp8);
    sjv_temp9 = &sjd_temp6;
    sjv_temp9->_refCount = 1;
    sjv_temp9->count = 4;
    sjv_temp9->data = result11;
    sjv_temp9->data->_refCount++;
    result10 = sjf_string(sjv_temp9);
    f = result10;
    f->_refCount++;
    result12 = sjf_string_getAt(a, 0);
    h = result12;
    result14 = h == 'h';
    i = result14;
    result15 = sjf_string_isEqual(f, a);
    j = result15;
    result17 = sjf_string_isLessOrEqual(f, a);
    k = result17;
    result19 = f == a;
    l = result19;

    sjf_string_destroy(a);
    sjf_string_destroy(b);
    sjf_anon1_destroy(console);
    sjf_string_destroy(f);
    sjf_anon2_destroy(parse);
    sjf_anon3_destroy(random);
    result10->_refCount--;
    if (result10->_refCount == 0) {
        sjf_string_destroy(result10);
        free(result10);
    }
    result11->_refCount--;
    if (result11->_refCount == 0) {
        sjf_array_char_destroy(result11);
        free(result11);
    }
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_anon3_destroy(result2);
        free(result2);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_anon2_destroy(result3);
        free(result3);
    }
    result4->_refCount--;
    if (result4->_refCount == 0) {
        sjf_anon1_destroy(result4);
        free(result4);
    }
    result6->_refCount--;
    if (result6->_refCount == 0) {
        sjf_string_destroy(result6);
        free(result6);
    }
    result7->_refCount--;
    if (result7->_refCount == 0) {
        sjf_array_char_destroy(result7);
        free(result7);
    }
    result8->_refCount--;
    if (result8->_refCount == 0) {
        sjf_string_destroy(result8);
        free(result8);
    }
    result9->_refCount--;
    if (result9->_refCount == 0) {
        sjf_array_char_destroy(result9);
        free(result9);
    }
    sjf_anon3_destroy(sjv_temp1);
    sjf_anon2_destroy(sjv_temp2);
    sjf_anon1_destroy(sjv_temp3);
    sjv_temp4->_refCount--;
    if (sjv_temp4->_refCount == 0) {
        sjf_array_char_destroy(sjv_temp4);
        free(sjv_temp4);
    }
    sjf_string_destroy(sjv_temp5);
    sjv_temp6->_refCount--;
    if (sjv_temp6->_refCount == 0) {
        sjf_array_char_destroy(sjv_temp6);
        free(sjv_temp6);
    }
    sjf_string_destroy(sjv_temp7);
    sjv_temp8->_refCount--;
    if (sjv_temp8->_refCount == 0) {
        sjf_array_char_destroy(sjv_temp8);
        free(sjv_temp8);
    }
    sjf_string_destroy(sjv_temp9);

    return result19;
}

void sjf_global_destroy(sjs_global* _this) {
}

sjs_string* sjf_string(sjs_string* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_string_destroy(sjs_string* _this) {
    _this->data->_refCount--;
    if (_this->data->_refCount == 0) {
        sjf_array_char_destroy(_this->data);
        free(_this->data);
    }
}

char sjf_string_getAt(sjs_string* _parent, int32_t index) {
    char result13;
    sjs_array_char* temp1;

    temp1 = _parent->data;
    result13 = sjf_array_char_getAt(temp1, index);

    temp1->_refCount--;
    if (temp1->_refCount == 0) {
        sjf_array_char_destroy(temp1);
        free(temp1);
    }

    return result13;
}

bool sjf_string_isEqual(sjs_string* _parent, sjs_string* test) {
    bool result16;
    sjs_array_char* temp2;
    sjs_array_char* temp3;

    temp2 = _parent->data;
    temp3 = test->data;
    result16 = sjf_array_char_isEqual(temp2, temp3);

    temp2->_refCount--;
    if (temp2->_refCount == 0) {
        sjf_array_char_destroy(temp2);
        free(temp2);
    }
    temp3->_refCount--;
    if (temp3->_refCount == 0) {
        sjf_array_char_destroy(temp3);
        free(temp3);
    }

    return result16;
}

bool sjf_string_isLessOrEqual(sjs_string* _parent, sjs_string* test) {
    bool result18;
    sjs_array_char* temp4;
    sjs_array_char* temp5;

    temp4 = _parent->data;
    temp5 = test->data;
    result18 = sjf_array_char_isLessOrEqual(temp4, temp5);

    temp4->_refCount--;
    if (temp4->_refCount == 0) {
        sjf_array_char_destroy(temp4);
        free(temp4);
    }
    temp5->_refCount--;
    if (temp5->_refCount == 0) {
        sjf_array_char_destroy(temp5);
        free(temp5);
    }

    return result18;
}

int main() {
    bool result1;
    sjs_global sjd_temp7;
    sjs_global* sjv_temp10;

    sjv_temp10 = &sjd_temp7;
    sjv_temp10->_refCount = 1;
    result1 = sjf_global(sjv_temp10);

    sjf_global_destroy(sjv_temp10);

    return 0;
}
