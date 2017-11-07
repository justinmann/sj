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

sjs_anon1* sjf_anon1(sjs_anon1* _this);
void sjf_anon1_destroy(sjs_anon1* _this);
sjs_string* sjf_anon1_readLine();
void sjf_anon1_write(sjs_anon1* _parent, sjs_string* data);
sjs_anon2* sjf_anon2(sjs_anon2* _this);
void sjf_anon2_destroy(sjs_anon2* _this);
int32_t sjf_anon2_toInt(sjs_string* text);
sjs_anon3* sjf_anon3(sjs_anon3* _this);
void sjf_anon3_destroy(sjs_anon3* _this);
int32_t sjf_anon3_nextInt();
sjs_array_char* sjf_array_char(sjs_array_char* _this);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_global();
sjs_string* sjf_string(sjs_string* _this);
void sjf_string_destroy(sjs_string* _this);

sjs_anon1* sjf_anon1(sjs_anon1* _this) {
     
		_this->_fd = (uintptr_t)stdout;
	;
    _this->_refCount++;

    return _this;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

sjs_string* sjf_anon1_readLine() {
    uintptr_t data;
    uintptr_t result12;
    sjs_string* result13;
    int32_t result14;
    sjs_array_char* result15;
    int32_t size;
    sjs_array_char* sjv_temp6;
    sjs_string* sjv_temp7;

    result12 = (uintptr_t)0;
    data = result12;
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
    result14 = size - 1;
    sjv_temp6 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp6->_refCount = 1;
    sjv_temp6->size = size;
    sjv_temp6->data = data;
    sjv_temp6->_isGlobal = false;
    result15 = sjf_array_char(sjv_temp6);
    sjv_temp7 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp7->_refCount = 1;
    sjv_temp7->count = result14;
    sjv_temp7->data = result15;
    sjv_temp7->data->_refCount++;
    result13 = sjf_string(sjv_temp7);

    result15->_refCount--;
    if (result15->_refCount == 0) {
        sjf_array_char_destroy(result15);
        free(result15);
    }
    sjv_temp6->_refCount--;
    if (sjv_temp6->_refCount == 0) {
        sjf_array_char_destroy(sjv_temp6);
        free(sjv_temp6);
    }
    sjv_temp7->_refCount--;
    if (sjv_temp7->_refCount == 0) {
        sjf_string_destroy(sjv_temp7);
        free(sjv_temp7);
    }

    return result13;
}

void sjf_anon1_write(sjs_anon1* _parent, sjs_string* data) {
    
		
			
		fwrite(data->data->data, sizeof(char), data->count, (FILE*)_parent->_fd);
	;
}

sjs_anon2* sjf_anon2(sjs_anon2* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

int32_t sjf_anon2_toInt(sjs_string* text) {
    
		char* e;
	    int v = strtol((char*)text->data->data, &e, 10);
	    
	    if (*e != '\0') {
	        return 0;
	    }
	    
	    return v;
    ;
}

sjs_anon3* sjf_anon3(sjs_anon3* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

int32_t sjf_anon3_nextInt() {
    
		return rand();
	;
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
    
	free((char*)_this->data);	
;
}

void sjf_global() {
    sjs_anon1* console;
    bool isCorrect;
    int32_t num;
    sjs_anon2* parse;
    sjs_anon3* random;
    sjs_anon3* result1;
    bool result10;
    sjs_anon2* result2;
    bool result23;
    sjs_string* result24;
    sjs_array_char* result25;
    sjs_anon1* result3;
    uintptr_t result4;
    sjs_string* result5;
    sjs_array_char* result6;
    int32_t result7;
    int32_t result8;
    int32_t result9;
    sjs_anon3 sjd_temp1;
    sjs_anon2 sjd_temp2;
    sjs_anon1 sjd_temp3;
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
    result1 = sjf_anon3(sjv_temp1);
    random = result1;
    random->_refCount++;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    result2 = sjf_anon2(sjv_temp2);
    parse = result2;
    parse->_refCount++;
    result4 = (uintptr_t)0;
    sjv_temp3 = &sjd_temp3;
    sjv_temp3->_refCount = 1;
    sjv_temp3->_fd = result4;
    result3 = sjf_anon1(sjv_temp3);
    console = result3;
    console->_refCount++;
    sjv_temp4 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp4->_refCount = 1;
    sjv_temp4->size = 15;
    sjv_temp4->data = (uintptr_t)sjg_string1;
    sjv_temp4->_isGlobal = false;
    result6 = sjf_array_char(sjv_temp4);
    sjv_temp5 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp5->_refCount = 1;
    sjv_temp5->count = 14;
    sjv_temp5->data = result6;
    sjv_temp5->data->_refCount++;
    result5 = sjf_string(sjv_temp5);
    sjf_anon1_write(console, result5);
    result7 = sjf_anon3_nextInt();
    result8 = result7 % 10;
    result9 = result8 + 1;
    num = result9;
    isCorrect = false;
    result10 = !isCorrect;
    whileValue1 = result10;
    result23 = !isCorrect;
    while (whileValue1) {
        int32_t guess;
        bool ifResult1;
        sjs_string* result11;
        int32_t result16;
        bool result17;
        sjs_string* str;

        result11 = sjf_anon1_readLine();
        str = result11;
        str->_refCount++;
        result16 = sjf_anon2_toInt(str);
        guess = result16;
        result17 = guess < num;
        if (result17) {
            sjs_string* result18;
            sjs_array_char* result19;
            sjs_array_char* sjv_temp8;
            sjs_string* sjv_temp9;

            sjv_temp8 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
            sjv_temp8->_refCount = 1;
            sjv_temp8->size = 9;
            sjv_temp8->data = (uintptr_t)sjg_string3;
            sjv_temp8->_isGlobal = false;
            result19 = sjf_array_char(sjv_temp8);
            sjv_temp9 = (sjs_string*)malloc(sizeof(sjs_string));
            sjv_temp9->_refCount = 1;
            sjv_temp9->count = 8;
            sjv_temp9->data = result19;
            sjv_temp9->data->_refCount++;
            result18 = sjf_string(sjv_temp9);
            sjf_anon1_write(console, result18);
            ifResult1 = false;

            result18->_refCount--;
            if (result18->_refCount == 0) {
                sjf_string_destroy(result18);
                free(result18);
            }
            result19->_refCount--;
            if (result19->_refCount == 0) {
                sjf_array_char_destroy(result19);
                free(result19);
            }
            sjv_temp8->_refCount--;
            if (sjv_temp8->_refCount == 0) {
                sjf_array_char_destroy(sjv_temp8);
                free(sjv_temp8);
            }
            sjv_temp9->_refCount--;
            if (sjv_temp9->_refCount == 0) {
                sjf_string_destroy(sjv_temp9);
                free(sjv_temp9);
            }
        } else {
            bool ifResult2;
            bool result20;

            result20 = guess > num;
            if (result20) {
                sjs_string* result21;
                sjs_array_char* result22;
                sjs_array_char* sjv_temp10;
                sjs_string* sjv_temp11;

                sjv_temp10 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
                sjv_temp10->_refCount = 1;
                sjv_temp10->size = 10;
                sjv_temp10->data = (uintptr_t)sjg_string2;
                sjv_temp10->_isGlobal = false;
                result22 = sjf_array_char(sjv_temp10);
                sjv_temp11 = (sjs_string*)malloc(sizeof(sjs_string));
                sjv_temp11->_refCount = 1;
                sjv_temp11->count = 9;
                sjv_temp11->data = result22;
                sjv_temp11->data->_refCount++;
                result21 = sjf_string(sjv_temp11);
                sjf_anon1_write(console, result21);
                ifResult2 = false;

                result21->_refCount--;
                if (result21->_refCount == 0) {
                    sjf_string_destroy(result21);
                    free(result21);
                }
                result22->_refCount--;
                if (result22->_refCount == 0) {
                    sjf_array_char_destroy(result22);
                    free(result22);
                }
                sjv_temp10->_refCount--;
                if (sjv_temp10->_refCount == 0) {
                    sjf_array_char_destroy(sjv_temp10);
                    free(sjv_temp10);
                }
                sjv_temp11->_refCount--;
                if (sjv_temp11->_refCount == 0) {
                    sjf_string_destroy(sjv_temp11);
                    free(sjv_temp11);
                }
            } else {
                ifResult2 = true;
            }

            ifResult1 = ifResult2;
        }

        isCorrect = ifResult1;

        whileValue1 = result23;

        result11->_refCount--;
        if (result11->_refCount == 0) {
            sjf_string_destroy(result11);
            free(result11);
        }
        str->_refCount--;
        if (str->_refCount == 0) {
            sjf_string_destroy(str);
            free(str);
        }
    }

    sjv_temp12 = (sjs_array_char*)malloc(sizeof(sjs_array_char));

    sjv_temp12->_refCount = 1;

    sjv_temp12->size = 9;

    sjv_temp12->data = (uintptr_t)sjg_string4;

    sjv_temp12->_isGlobal = false;

    result25 = sjf_array_char(sjv_temp12);

    sjv_temp13 = (sjs_string*)malloc(sizeof(sjs_string));

    sjv_temp13->_refCount = 1;

    sjv_temp13->count = 8;

    sjv_temp13->data = result25;

    sjv_temp13->data->_refCount++;

    result24 = sjf_string(sjv_temp13);

    sjf_anon1_write(console, result24);

    sjf_anon1_destroy(console);
    sjf_anon2_destroy(parse);
    sjf_anon3_destroy(random);
    result1->_refCount--;
    if (result1->_refCount == 0) {
        sjf_anon3_destroy(result1);
        free(result1);
    }
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_anon2_destroy(result2);
        free(result2);
    }
    result24->_refCount--;
    if (result24->_refCount == 0) {
        sjf_string_destroy(result24);
        free(result24);
    }
    result25->_refCount--;
    if (result25->_refCount == 0) {
        sjf_array_char_destroy(result25);
        free(result25);
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
    sjf_anon3_destroy(sjv_temp1);
    sjv_temp12->_refCount--;
    if (sjv_temp12->_refCount == 0) {
        sjf_array_char_destroy(sjv_temp12);
        free(sjv_temp12);
    }
    sjv_temp13->_refCount--;
    if (sjv_temp13->_refCount == 0) {
        sjf_string_destroy(sjv_temp13);
        free(sjv_temp13);
    }
    sjf_anon2_destroy(sjv_temp2);
    sjf_anon1_destroy(sjv_temp3);
    sjv_temp4->_refCount--;
    if (sjv_temp4->_refCount == 0) {
        sjf_array_char_destroy(sjv_temp4);
        free(sjv_temp4);
    }
    sjv_temp5->_refCount--;
    if (sjv_temp5->_refCount == 0) {
        sjf_string_destroy(sjv_temp5);
        free(sjv_temp5);
    }
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

int main() {
    sjf_global();

    return 0;
}
