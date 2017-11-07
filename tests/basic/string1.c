#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const char* sjg_string1 = "he\"llo";
const char* sjg_string2 = "he\nllo";
const char* sjg_string3 = "hello";

typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon2 sjs_anon2;
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
     
		_this->_fd = (uintptr_t)fopen(stdout, "w");
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

sjs_array_char* sjf_array_char(sjs_array_char* _this) {
    
	

	if (_this->size < 0) {
		exit(-1);
	}

	if (_this->data) {
		_this->_isGlobal = true;
	} else {
		_this->data = (uintptr_t)malloc(_this->size * sizeof(char));
	}

	 _this->_refCount++;
;
	return _this;
;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    
	free((char*)_this->data);	
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
    
		

		return memcmp((void*)_parent->data, (void*)test->data, min(_parent->size, test->size) * sizeof(char)) <= 0;		
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
    sjs_array_char* result10;
    char result11;
    bool result13;
    bool result14;
    bool result16;
    bool result18;
    sjs_anon2* result2;
    sjs_anon1* result3;
    uintptr_t result4;
    sjs_string* result5;
    sjs_array_char* result6;
    sjs_string* result7;
    sjs_array_char* result8;
    sjs_string* result9;
    sjs_anon2 sjd_temp1;
    sjs_anon1 sjd_temp2;
    sjs_array_char sjd_temp3;
    sjs_string sjd_temp4;
    sjs_array_char sjd_temp5;
    sjs_string sjd_temp6;
    sjs_array_char sjd_temp7;
    sjs_string sjd_temp8;
    sjs_anon2* sjv_temp1;
    sjs_anon1* sjv_temp2;
    sjs_array_char* sjv_temp3;
    sjs_string* sjv_temp4;
    sjs_array_char* sjv_temp5;
    sjs_string* sjv_temp6;
    sjs_array_char* sjv_temp7;
    sjs_string* sjv_temp8;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    result2 = sjf_anon2(sjv_temp1);
    parse = result2;
    parse->_refCount++;
    result4 = (uintptr_t)0;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->_fd = result4;
    result3 = sjf_anon1(sjv_temp2);
    console = result3;
    console->_refCount++;
    sjv_temp3 = &sjd_temp3;
    sjv_temp3->_refCount = 1;
    sjv_temp3->size = 8;
    sjv_temp3->data = sjg_string1;
    sjv_temp3->_isGlobal = false;
    result6 = sjf_array_char(sjv_temp3);
    sjv_temp4 = &sjd_temp4;
    sjv_temp4->_refCount = 1;
    sjv_temp4->count = 7;
    sjv_temp4->data = result6;
    sjv_temp4->data++;
    result5 = sjf_string(sjv_temp4);
    a = result5;
    a->_refCount++;
    sjv_temp5 = &sjd_temp5;
    sjv_temp5->_refCount = 1;
    sjv_temp5->size = 8;
    sjv_temp5->data = sjg_string2;
    sjv_temp5->_isGlobal = false;
    result8 = sjf_array_char(sjv_temp5);
    sjv_temp6 = &sjd_temp6;
    sjv_temp6->_refCount = 1;
    sjv_temp6->count = 7;
    sjv_temp6->data = result8;
    sjv_temp6->data++;
    result7 = sjf_string(sjv_temp6);
    b = result7;
    b->_refCount++;
    c = 'a';
    d = '\'';
    e = '\n';
    sjv_temp7 = &sjd_temp7;
    sjv_temp7->_refCount = 1;
    sjv_temp7->size = 6;
    sjv_temp7->data = sjg_string3;
    sjv_temp7->_isGlobal = false;
    result10 = sjf_array_char(sjv_temp7);
    sjv_temp8 = &sjd_temp8;
    sjv_temp8->_refCount = 1;
    sjv_temp8->count = 5;
    sjv_temp8->data = result10;
    sjv_temp8->data++;
    result9 = sjf_string(sjv_temp8);
    f = result9;
    f->_refCount++;
    result11 = sjf_string_getAt(a, 0);
    h = result11;
    result13 = h == 'h';
    i = result13;
    result14 = sjf_string_isEqual(f, a);
    j = result14;
    result16 = sjf_string_isLessOrEqual(f, a);
    k = result16;
    result18 = f == a;
    l = result18;

    sjf_string_destroy(a);
    sjf_string_destroy(b);
    sjf_anon1_destroy(console);
    sjf_string_destroy(f);
    sjf_anon2_destroy(parse);
    result10->_refCount--;
    if (result10->_refCount == 0) {
        sjf_array_char_destroy(result10);
        free(result10);
    }
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_anon2_destroy(result2);
        free(result2);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_anon1_destroy(result3);
        free(result3);
    }
    result5->_refCount--;
    if (result5->_refCount == 0) {
        sjf_string_destroy(result5);
        free(result5);
    }
    result6->_refCount--;
    if (result6->_refCount == 0) {
        sjf_array_char_destroy(result6);
        free(result6);
    }
    result7->_refCount--;
    if (result7->_refCount == 0) {
        sjf_string_destroy(result7);
        free(result7);
    }
    result8->_refCount--;
    if (result8->_refCount == 0) {
        sjf_array_char_destroy(result8);
        free(result8);
    }
    result9->_refCount--;
    if (result9->_refCount == 0) {
        sjf_string_destroy(result9);
        free(result9);
    }
    sjf_anon2_destroy(sjv_temp1);
    sjf_anon1_destroy(sjv_temp2);
    sjf_array_char_destroy(sjv_temp3);
    sjf_string_destroy(sjv_temp4);
    sjf_array_char_destroy(sjv_temp5);
    sjf_string_destroy(sjv_temp6);
    sjf_array_char_destroy(sjv_temp7);
    sjf_string_destroy(sjv_temp8);

    return result18;
}

void sjf_global_destroy(sjs_global* _this) {
}

sjs_string* sjf_string(sjs_string* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_string_destroy(sjs_string* _this) {
    _this->data->_refCount--;
    if (_this->data->_refCount <= 0) {
        sjf_array_char_destroy(_this->data);
        free(_this->data);
    }
}

char sjf_string_getAt(sjs_string* _parent, int32_t index) {
    char result12;
    sjs_array_char* temp1;

    temp1 = _parent->data;
    result12 = sjf_array_char_getAt(temp1, index);

    temp1->_refCount--;
    if (temp1->_refCount == 0) {
        sjf_array_char_destroy(temp1);
        free(temp1);
    }

    return result12;
}

bool sjf_string_isEqual(sjs_string* _parent, sjs_string* test) {
    bool result15;
    sjs_array_char* temp2;
    sjs_array_char* temp3;

    temp2 = _parent->data;
    temp3 = test->data;
    result15 = sjf_array_char_isEqual(temp2, temp3);

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

    return result15;
}

bool sjf_string_isLessOrEqual(sjs_string* _parent, sjs_string* test) {
    bool result17;
    sjs_array_char* temp4;
    sjs_array_char* temp5;

    temp4 = _parent->data;
    temp5 = test->data;
    result17 = sjf_array_char_isLessOrEqual(temp4, temp5);

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

    return result17;
}

int main() {
    bool result1;
    sjs_global sjd_temp9;
    sjs_global* sjv_temp9;

    sjv_temp9 = &sjd_temp9;
    sjv_temp9->_refCount = 1;
    result1 = sjf_global(sjv_temp9);

    sjf_global_destroy(sjv_temp9);

    return 0;
}
