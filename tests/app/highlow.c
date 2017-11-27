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

const char* sjg_string1 = "Shall we play\n";
const char* sjg_string2 = "Too high\n";
const char* sjg_string3 = "Too Low\n";
const char* sjg_string4 = "Correct\n";

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

bool result1;
sjs_string sjt_call1;
sjs_string sjt_call4;
sjs_anon1* sjt_dot1;
sjs_anon3* sjt_dot2;
sjs_anon1* sjt_dot7;
sjs_string* sjt_functionParam1;
sjs_string* sjt_functionParam5;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_math3;
int32_t sjt_math4;
bool sjt_not1;
bool sjt_while1;
sjs_anon1 sjv_console;
sjs_anon4 sjv_convert;
bool sjv_isCorrect;
int32_t sjv_num;
sjs_anon2 sjv_parse;
sjs_anon3 sjv_random;

void sjf_anon1(sjs_anon1* _this);
void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* to);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_heap(sjs_anon1_heap* _this);
void sjf_anon1_readLine(sjs_anon1* _parent, sjs_string* _return);
void sjf_anon1_write(sjs_anon1* _parent, sjs_string* data);
void sjf_anon2(sjs_anon2* _this);
void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* to);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon2_heap(sjs_anon2_heap* _this);
void sjf_anon2_toInt(sjs_anon2* _parent, sjs_string* text, int32_t* _return);
void sjf_anon3(sjs_anon3* _this);
void sjf_anon3_copy(sjs_anon3* _this, sjs_anon3* to);
void sjf_anon3_destroy(sjs_anon3* _this);
void sjf_anon3_heap(sjs_anon3_heap* _this);
void sjf_anon3_nextInt(sjs_anon3* _parent, int32_t* _return);
void sjf_anon4(sjs_anon4* _this);
void sjf_anon4_copy(sjs_anon4* _this, sjs_anon4* to);
void sjf_anon4_destroy(sjs_anon4* _this);
void sjf_anon4_heap(sjs_anon4_heap* _this);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* to);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char_heap* _this);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* to);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string_heap* _this);
void main_destroy(void);

void sjf_anon1(sjs_anon1* _this) {
}

void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* to) {
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1_heap* _this) {
}

void sjf_anon1_readLine(sjs_anon1* _parent, sjs_string* _return) {
    int32_t sjt_cast1;
    int32_t sjt_math5;
    int32_t sjt_math6;
    uintptr_t sjv_data;
    int32_t sjv_size;

    sjt_cast1 = 0;
    sjv_data = (uintptr_t)sjt_cast1;
    sjv_size = 1024;
    
			
		    char* str = (char*)malloc(size);
		    int index = 0;
		    char ch = ' ';
		    do {
		        ch = getchar();
		        if (ch != '\n') {
		            str[index] = ch;
		            index++;
		            if (index >= size) {
		                size *= 2;
		                str = (char*)realloc(str, size);
		            }
		        }
		    } while (ch != '\n');

			str[index] = 0;
		    index++;
		    data = (uintptr_t)str;
		    size = index;
		;
    sjt_math5 = sjv_size;
    sjt_math6 = 1;
    _return->count = sjt_math5 - sjt_math6;
    _return->data.size = sjv_size;
    _return->data.data = sjv_data;
    _return->data._isGlobal = false;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_anon1_write(sjs_anon1* _parent, sjs_string* data) {
    
			
			printf("%s\n", (char*)data->data.data);
		;
}

void sjf_anon2(sjs_anon2* _this) {
}

void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* to) {
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_anon2_heap(sjs_anon2_heap* _this) {
}

void sjf_anon2_toInt(sjs_anon2* _parent, sjs_string* text, int32_t* _return) {
    int32_t sjv_x;

    sjv_x = 0;
    
			char* e;
		    int v = (int)strtol((char*)text->data.data, &e, 10);
		    
		    if (*e != '\0') {
		        sjv_x = 0;
		    }
		    else {
		    	sjv_x = v;
			}
	    ;
    (*_return) = sjv_x;
}

void sjf_anon3(sjs_anon3* _this) {
}

void sjf_anon3_copy(sjs_anon3* _this, sjs_anon3* to) {
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

void sjf_anon3_heap(sjs_anon3_heap* _this) {
}

void sjf_anon3_nextInt(sjs_anon3* _parent, int32_t* _return) {
    
		int x = rand();
		*_return = x;
	;
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

int main() {
    sjf_anon4(&sjv_convert);
    sjf_anon3(&sjv_random);
    sjf_anon2(&sjv_parse);
    sjf_anon1(&sjv_console);
    sjt_dot1 = &sjv_console;
    sjt_call1.count = 15;
    sjt_call1.data.size = 16;
    sjt_call1.data.data = (uintptr_t)sjg_string1;
    sjt_call1.data._isGlobal = false;
    sjf_array_char(&sjt_call1.data);
    sjf_string(&sjt_call1);
    sjt_functionParam1 = &sjt_call1;
    sjf_anon1_write(sjt_dot1, sjt_functionParam1);
    sjt_dot2 = &sjv_random;
    sjf_anon3_nextInt(sjt_dot2, &sjt_math3);
    sjt_math4 = 10;
    sjt_math1 = sjt_math3 % sjt_math4;
    sjt_math2 = 1;
    sjv_num = sjt_math1 + sjt_math2;
    sjv_isCorrect = false;
    sjt_not1 = sjv_isCorrect;
    result1 = !sjt_not1;
    sjt_while1 = result1;
    while (sjt_while1) {
        bool result2;
        int32_t sjt_compare1;
        int32_t sjt_compare2;
        sjs_anon1* sjt_dot3;
        sjs_anon2* sjt_dot4;
        sjs_string* sjt_functionParam2;
        bool sjt_ifElse1;
        bool sjt_not2;
        int32_t sjv_guess;
        sjs_string sjv_str;

        sjt_dot3 = &sjv_console;
        sjf_anon1_readLine(sjt_dot3, &sjv_str);
        sjt_dot4 = &sjv_parse;
        sjt_functionParam2 = &sjv_str;
        sjf_anon2_toInt(sjt_dot4, sjt_functionParam2, &sjv_guess);
        sjt_compare1 = sjv_guess;
        sjt_compare2 = sjv_num;
        sjt_ifElse1 = sjt_compare1 < sjt_compare2;
        if (sjt_ifElse1) {
            sjs_string sjt_call2;
            sjs_anon1* sjt_dot5;
            sjs_string* sjt_functionParam3;

            sjt_dot5 = &sjv_console;
            sjt_call2.count = 9;
            sjt_call2.data.size = 10;
            sjt_call2.data.data = (uintptr_t)sjg_string3;
            sjt_call2.data._isGlobal = false;
            sjf_array_char(&sjt_call2.data);
            sjf_string(&sjt_call2);
            sjt_functionParam3 = &sjt_call2;
            sjf_anon1_write(sjt_dot5, sjt_functionParam3);
            sjv_isCorrect = false;

            sjf_string_destroy(&sjt_call2);
        } else {
            int32_t sjt_compare3;
            int32_t sjt_compare4;
            bool sjt_ifElse2;

            sjt_compare3 = sjv_guess;
            sjt_compare4 = sjv_num;
            sjt_ifElse2 = sjt_compare3 > sjt_compare4;
            if (sjt_ifElse2) {
                sjs_string sjt_call3;
                sjs_anon1* sjt_dot6;
                sjs_string* sjt_functionParam4;

                sjt_dot6 = &sjv_console;
                sjt_call3.count = 10;
                sjt_call3.data.size = 11;
                sjt_call3.data.data = (uintptr_t)sjg_string2;
                sjt_call3.data._isGlobal = false;
                sjf_array_char(&sjt_call3.data);
                sjf_string(&sjt_call3);
                sjt_functionParam4 = &sjt_call3;
                sjf_anon1_write(sjt_dot6, sjt_functionParam4);
                sjv_isCorrect = false;

                sjf_string_destroy(&sjt_call3);
            } else {
                sjv_isCorrect = true;
            }
        }

        sjt_not2 = sjv_isCorrect;
        result2 = !sjt_not2;
        sjt_while1 = result2;

        sjf_string_destroy(&sjv_str);
    }

    sjt_dot7 = &sjv_console;
    sjt_call4.count = 9;
    sjt_call4.data.size = 10;
    sjt_call4.data.data = (uintptr_t)sjg_string4;
    sjt_call4.data._isGlobal = false;
    sjf_array_char(&sjt_call4.data);
    sjf_string(&sjt_call4);
    sjt_functionParam5 = &sjt_call4;
    sjf_anon1_write(sjt_dot7, sjt_functionParam5);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_string_destroy(&sjt_call1);
    sjf_string_destroy(&sjt_call4);
    sjf_anon1_destroy(&sjv_console);
    sjf_anon4_destroy(&sjv_convert);
    sjf_anon2_destroy(&sjv_parse);
    sjf_anon3_destroy(&sjv_random);
}
