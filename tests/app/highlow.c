#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* sjg_string1 = "Shall we play\n";
const char* sjg_string2 = "Too high\n";
const char* sjg_string3 = "Too Low\n";
const char* sjg_string4 = "Correct\n";

typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_array_char sjs_array_char;
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
void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_global(void);
void sjf_string(sjs_string* _this, sjs_string** _return);
void sjf_string_destroy(sjs_string* _this);

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return) {
     
		_this->_fd = (uintptr_t)stdout;
	;
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_readLine(sjs_string** _return) {
    uintptr_t data;
    uintptr_t result7;
    int32_t result8;
    int32_t size;
    sjs_array_char* sjv_temp6;
    sjs_string* sjv_temp7;

    result7 = (uintptr_t)0;
    data = result7;
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
    result8 = size - 1;
    sjv_temp6 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp6->_refCount = 1;
    sjv_temp6->size = size;
    sjv_temp6->data = data;
    sjv_temp6->_isGlobal = false;
    sjf_array_char(sjv_temp6, &sjv_temp6);
    sjv_temp7 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp7->_refCount = 1;
    sjv_temp7->count = result8;
    sjv_temp7->data = sjv_temp6;
    sjv_temp7->data->_refCount++;
    sjf_string(sjv_temp7, &sjv_temp7);
    sjv_temp7->_refCount++;

    sjv_temp6->_refCount--;
    if (sjv_temp6->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp6);
        free(sjv_temp6);
    }
    sjv_temp7->_refCount--;
    if (sjv_temp7->_refCount <= 0) {
        sjf_string_destroy(sjv_temp7);
        free(sjv_temp7);
    }

    *_return = sjv_temp7;
}

void sjf_anon1_write(sjs_anon1* _parent, sjs_string* data) {
    
			
				
			fwrite((void*)data->data->data, sizeof(char), data->count, (FILE*)_parent->_fd);
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

void sjf_global(void) {
    sjs_anon3 sjd_temp1;
    sjs_anon2 sjd_temp2;
    sjs_anon1 sjd_temp3;
    sjs_anon1* console;
    bool isCorrect;
    int32_t num;
    sjs_anon2* parse;
    sjs_anon3* random;
    uintptr_t result1;
    int32_t result2;
    int32_t result3;
    int32_t result4;
    bool result5;
    sjs_anon3* sjv_temp1;
    sjs_array_char* sjv_temp12;
    sjs_string* sjv_temp13;
    sjs_anon2* sjv_temp2;
    sjs_anon1* sjv_temp3;
    sjs_array_char* sjv_temp4;
    sjs_string* sjv_temp5;
    bool whileValue1;

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
    sjv_temp4->size = 15;
    sjv_temp4->data = (uintptr_t)sjg_string1;
    sjv_temp4->_isGlobal = false;
    sjf_array_char(sjv_temp4, &sjv_temp4);
    sjv_temp5 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp5->_refCount = 1;
    sjv_temp5->count = 14;
    sjv_temp5->data = sjv_temp4;
    sjv_temp5->data->_refCount++;
    sjf_string(sjv_temp5, &sjv_temp5);
    sjf_anon1_write(console, sjv_temp5);
    sjf_anon3_nextInt(&result2);
    result3 = result2 % 10;
    result4 = result3 + 1;
    num = result4;
    isCorrect = false;
    result5 = !isCorrect;
    whileValue1 = result5;
    while (whileValue1) {
        int32_t guess;
        bool ifResult1;
        bool result10;
        bool result12;
        sjs_string* result6;
        int32_t result9;
        sjs_string* str;

        result6 = 0;
        sjf_anon1_readLine(&result6);
        str = result6;
        str->_refCount++;
        result9 = 0;
        sjf_anon2_toInt(str, &result9);
        guess = result9;
        result10 = guess < num;
        if (result10) {
            sjs_array_char* sjv_temp8;
            sjs_string* sjv_temp9;

            sjv_temp8 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
            sjv_temp8->_refCount = 1;
            sjv_temp8->size = 9;
            sjv_temp8->data = (uintptr_t)sjg_string3;
            sjv_temp8->_isGlobal = false;
            sjf_array_char(sjv_temp8, &sjv_temp8);
            sjv_temp9 = (sjs_string*)malloc(sizeof(sjs_string));
            sjv_temp9->_refCount = 1;
            sjv_temp9->count = 8;
            sjv_temp9->data = sjv_temp8;
            sjv_temp9->data->_refCount++;
            sjf_string(sjv_temp9, &sjv_temp9);
            sjf_anon1_write(console, sjv_temp9);
            ifResult1 = false;

            sjv_temp8->_refCount--;
            if (sjv_temp8->_refCount <= 0) {
                sjf_array_char_destroy(sjv_temp8);
                free(sjv_temp8);
            }
            sjv_temp9->_refCount--;
            if (sjv_temp9->_refCount <= 0) {
                sjf_string_destroy(sjv_temp9);
                free(sjv_temp9);
            }
        } else {
            bool ifResult2;
            bool result11;

            result11 = guess > num;
            if (result11) {
                sjs_array_char* sjv_temp10;
                sjs_string* sjv_temp11;

                sjv_temp10 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
                sjv_temp10->_refCount = 1;
                sjv_temp10->size = 10;
                sjv_temp10->data = (uintptr_t)sjg_string2;
                sjv_temp10->_isGlobal = false;
                sjf_array_char(sjv_temp10, &sjv_temp10);
                sjv_temp11 = (sjs_string*)malloc(sizeof(sjs_string));
                sjv_temp11->_refCount = 1;
                sjv_temp11->count = 9;
                sjv_temp11->data = sjv_temp10;
                sjv_temp11->data->_refCount++;
                sjf_string(sjv_temp11, &sjv_temp11);
                sjf_anon1_write(console, sjv_temp11);
                ifResult2 = false;

                sjv_temp10->_refCount--;
                if (sjv_temp10->_refCount <= 0) {
                    sjf_array_char_destroy(sjv_temp10);
                    free(sjv_temp10);
                }
                sjv_temp11->_refCount--;
                if (sjv_temp11->_refCount <= 0) {
                    sjf_string_destroy(sjv_temp11);
                    free(sjv_temp11);
                }
            } else {
                ifResult2 = true;
            }

            ifResult1 = ifResult2;
        }

        isCorrect = ifResult1;

        result12 = !isCorrect;

        whileValue1 = result12;

        result6->_refCount--;
        if (result6->_refCount <= 0) {
            sjf_string_destroy(result6);
            free(result6);
        }
        str->_refCount--;
        if (str->_refCount <= 0) {
            sjf_string_destroy(str);
            free(str);
        }
    }

    sjv_temp12 = (sjs_array_char*)malloc(sizeof(sjs_array_char));

    sjv_temp12->_refCount = 1;

    sjv_temp12->size = 9;

    sjv_temp12->data = (uintptr_t)sjg_string4;

    sjv_temp12->_isGlobal = false;

    sjf_array_char(sjv_temp12, &sjv_temp12);

    sjv_temp13 = (sjs_string*)malloc(sizeof(sjs_string));

    sjv_temp13->_refCount = 1;

    sjv_temp13->count = 8;

    sjv_temp13->data = sjv_temp12;

    sjv_temp13->data->_refCount++;

    sjf_string(sjv_temp13, &sjv_temp13);

    sjf_anon1_write(console, sjv_temp13);

    sjv_temp12->_refCount--;
    if (sjv_temp12->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp12);
        free(sjv_temp12);
    }
    sjv_temp13->_refCount--;
    if (sjv_temp13->_refCount <= 0) {
        sjf_string_destroy(sjv_temp13);
        free(sjv_temp13);
    }
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
    sjf_anon3_destroy(&sjd_temp1);
    sjf_anon2_destroy(&sjd_temp2);
    sjf_anon1_destroy(&sjd_temp3);
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
