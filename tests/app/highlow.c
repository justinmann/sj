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

const char* sjg_string1 = "Shall we play\n";
const char* sjg_string2 = "Too high\n";
const char* sjg_string3 = "Too Low\n";
const char* sjg_string4 = "Correct\n";

#define sjs_anon1_typeId 1
#define sjs_anon2_typeId 2
#define sjs_anon3_typeId 3
#define sjs_anon4_typeId 4
#define sjs_array_char_typeId 5
#define sjs_object_typeId 6
#define sjs_string_typeId 7

typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_anon4 sjs_anon4;
typedef struct td_sjs_array_char sjs_array_char;
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
void sjf_anon1_readLine(sjs_string** _return);
void sjf_anon1_write(sjs_anon1* _parent, sjs_string* data);
void sjf_anon2(sjs_anon2* _this, sjs_anon2** _return);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon2_toInt(sjs_string* text, int32_t* _return);
void sjf_anon3(sjs_anon3* _this, sjs_anon3** _return);
void sjf_anon3_destroy(sjs_anon3* _this);
void sjf_anon3_nextInt(int32_t* _return);
void sjf_anon4(sjs_anon4* _this, sjs_anon4** _return);
void sjf_anon4_destroy(sjs_anon4* _this);
void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_global(void);
void sjf_string(sjs_string* _this, sjs_string** _return);
void sjf_string_destroy(sjs_string* _this);

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_readLine(sjs_string** _return) {
    uintptr_t data;
    uintptr_t result6;
    int32_t result7;
    int32_t size;
    sjs_array_char* sjv_temp7;
    sjs_string* sjv_temp8;

    result6 = (uintptr_t)0;
    data = result6;
    size = 1024;
    
			
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
    result7 = size - 1;
    sjv_temp7 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp7->_refCount = 1;
    sjv_temp7->size = size;
    sjv_temp7->data = data;
    sjv_temp7->_isGlobal = false;
    sjf_array_char(sjv_temp7, &sjv_temp7);
    sjv_temp8 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp8->_refCount = 1;
    sjv_temp8->count = result7;
    sjv_temp8->data = sjv_temp7;
    sjv_temp8->data->_refCount++;
    sjf_string(sjv_temp8, &sjv_temp8);
    sjv_temp8->_refCount++;

    sjv_temp7->_refCount--;
    if (sjv_temp7->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp7);
        free(sjv_temp7);
    }
    sjv_temp8->_refCount--;
    if (sjv_temp8->_refCount <= 0) {
        sjf_string_destroy(sjv_temp8);
        free(sjv_temp8);
    }

    *_return = sjv_temp8;
}

void sjf_anon1_write(sjs_anon1* _parent, sjs_string* data) {
    
			
			
			printf("%s\n", (char*)data->data->data);
		;
}

void sjf_anon2(sjs_anon2* _this, sjs_anon2** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_anon2_toInt(sjs_string* text, int32_t* _return) {
    int32_t x;

    x = 0;
    
			char* e;
		    int v = (int)strtol((char*)text->data->data, &e, 10);
		    
		    if (*e != '\0') {
		        x = 0;
		    }
		    else {
		    	x = v;
			}
	    ;

    *_return = x;
}

void sjf_anon3(sjs_anon3* _this, sjs_anon3** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

void sjf_anon3_nextInt(int32_t* _return) {
    
		int x = rand();
		*_return = x;
	;
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

void sjf_global(void) {
    sjs_anon4 sjd_temp1;
    sjs_anon3 sjd_temp2;
    sjs_anon2 sjd_temp3;
    sjs_anon1 sjd_temp4;
    sjs_anon1* console;
    sjs_anon4* convert;
    bool isCorrect;
    int32_t num;
    sjs_anon2* parse;
    sjs_anon3* random;
    int32_t result1;
    int32_t result2;
    int32_t result3;
    bool result4;
    sjs_anon4* sjv_temp1;
    sjs_array_char* sjv_temp13;
    sjs_string* sjv_temp14;
    sjs_anon3* sjv_temp2;
    sjs_anon2* sjv_temp3;
    sjs_anon1* sjv_temp4;
    sjs_array_char* sjv_temp5;
    sjs_string* sjv_temp6;
    bool whileValue1;

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
    sjv_temp5->size = 16;
    sjv_temp5->data = (uintptr_t)sjg_string1;
    sjv_temp5->_isGlobal = false;
    sjf_array_char(sjv_temp5, &sjv_temp5);
    sjv_temp6 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp6->_refCount = 1;
    sjv_temp6->count = 15;
    sjv_temp6->data = sjv_temp5;
    sjv_temp6->data->_refCount++;
    sjf_string(sjv_temp6, &sjv_temp6);
    sjf_anon1_write(console, sjv_temp6);
    sjf_anon3_nextInt(&result1);
    result2 = result1 % 10;
    result3 = result2 + 1;
    num = result3;
    isCorrect = false;
    result4 = !isCorrect;
    whileValue1 = result4;
    while (whileValue1) {
        int32_t guess;
        bool ifResult1;
        bool result11;
        sjs_string* result5;
        int32_t result8;
        bool result9;
        sjs_string* str;

        result5 = 0;
        sjf_anon1_readLine(&result5);
        str = result5;
        str->_refCount++;
        result8 = 0;
        sjf_anon2_toInt(str, &result8);
        guess = result8;
        result9 = guess < num;
        if (result9) {
            sjs_string* sjv_temp10;
            sjs_array_char* sjv_temp9;

            sjv_temp9 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
            sjv_temp9->_refCount = 1;
            sjv_temp9->size = 10;
            sjv_temp9->data = (uintptr_t)sjg_string3;
            sjv_temp9->_isGlobal = false;
            sjf_array_char(sjv_temp9, &sjv_temp9);
            sjv_temp10 = (sjs_string*)malloc(sizeof(sjs_string));
            sjv_temp10->_refCount = 1;
            sjv_temp10->count = 9;
            sjv_temp10->data = sjv_temp9;
            sjv_temp10->data->_refCount++;
            sjf_string(sjv_temp10, &sjv_temp10);
            sjf_anon1_write(console, sjv_temp10);
            ifResult1 = false;

            sjv_temp10->_refCount--;
            if (sjv_temp10->_refCount <= 0) {
                sjf_string_destroy(sjv_temp10);
                free(sjv_temp10);
            }
            sjv_temp9->_refCount--;
            if (sjv_temp9->_refCount <= 0) {
                sjf_array_char_destroy(sjv_temp9);
                free(sjv_temp9);
            }
        } else {
            bool ifResult2;
            bool result10;

            result10 = guess > num;
            if (result10) {
                sjs_array_char* sjv_temp11;
                sjs_string* sjv_temp12;

                sjv_temp11 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
                sjv_temp11->_refCount = 1;
                sjv_temp11->size = 11;
                sjv_temp11->data = (uintptr_t)sjg_string2;
                sjv_temp11->_isGlobal = false;
                sjf_array_char(sjv_temp11, &sjv_temp11);
                sjv_temp12 = (sjs_string*)malloc(sizeof(sjs_string));
                sjv_temp12->_refCount = 1;
                sjv_temp12->count = 10;
                sjv_temp12->data = sjv_temp11;
                sjv_temp12->data->_refCount++;
                sjf_string(sjv_temp12, &sjv_temp12);
                sjf_anon1_write(console, sjv_temp12);
                ifResult2 = false;

                sjv_temp11->_refCount--;
                if (sjv_temp11->_refCount <= 0) {
                    sjf_array_char_destroy(sjv_temp11);
                    free(sjv_temp11);
                }
                sjv_temp12->_refCount--;
                if (sjv_temp12->_refCount <= 0) {
                    sjf_string_destroy(sjv_temp12);
                    free(sjv_temp12);
                }
            } else {
                ifResult2 = true;
            }

            ifResult1 = ifResult2;
        }

        isCorrect = ifResult1;

        result11 = !isCorrect;

        whileValue1 = result11;

        result5->_refCount--;
        if (result5->_refCount <= 0) {
            sjf_string_destroy(result5);
            free(result5);
        }
        str->_refCount--;
        if (str->_refCount <= 0) {
            sjf_string_destroy(str);
            free(str);
        }
    }

    sjv_temp13 = (sjs_array_char*)malloc(sizeof(sjs_array_char));

    sjv_temp13->_refCount = 1;

    sjv_temp13->size = 10;

    sjv_temp13->data = (uintptr_t)sjg_string4;

    sjv_temp13->_isGlobal = false;

    sjf_array_char(sjv_temp13, &sjv_temp13);

    sjv_temp14 = (sjs_string*)malloc(sizeof(sjs_string));

    sjv_temp14->_refCount = 1;

    sjv_temp14->count = 9;

    sjv_temp14->data = sjv_temp13;

    sjv_temp14->data->_refCount++;

    sjf_string(sjv_temp14, &sjv_temp14);

    sjf_anon1_write(console, sjv_temp14);

    sjv_temp13->_refCount--;
    if (sjv_temp13->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp13);
        free(sjv_temp13);
    }
    sjv_temp14->_refCount--;
    if (sjv_temp14->_refCount <= 0) {
        sjf_string_destroy(sjv_temp14);
        free(sjv_temp14);
    }
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
    sjf_anon4_destroy(&sjd_temp1);
    sjf_anon3_destroy(&sjd_temp2);
    sjf_anon2_destroy(&sjd_temp3);
    sjf_anon1_destroy(&sjd_temp4);
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

int main() {
    sjf_global();

    return 0;
}
