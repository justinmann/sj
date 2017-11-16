#include <assert.h>
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

const char* sjg_string1 = "hello";
const char* sjg_string2 = "bob";

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
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newSize, sjs_array_char** _return);
void sjf_array_char_setAt(sjs_array_char* _parent, int32_t index, char item);
void sjf_global_destroy(sjs_global* _this);
void sjf_string(sjs_string* _this, sjs_string** _return);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return);

sjs_global global;
sjs_anon4 sjd_temp1;
sjs_anon3 sjd_temp2;
sjs_anon2 sjd_temp3;
sjs_anon1 sjd_temp4;
sjs_string sjd_temp5;
sjs_array_char sjd_temp6;
sjs_string sjd_temp7;
sjs_array_char sjd_temp8;

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return) {

    *_return = _this;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon2(sjs_anon2* _this, sjs_anon2** _return) {

    *_return = _this;
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_anon3(sjs_anon3* _this, sjs_anon3** _return) {

    *_return = _this;
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

void sjf_anon4(sjs_anon4* _this, sjs_anon4** _return) {

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

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newSize, sjs_array_char** _return) {
    
		
		

		if (_parent->size != newSize) {
			if (newSize < _parent->size) {
				printf("grow: new size smaller than old size %d:%d\n", newSize, _parent->size);
				exit(-1);
			}
			
			if (_parent->_isGlobal) {
				_parent->_isGlobal = false;
				char* p = (char*)_parent->data;
				_parent->data = (uintptr_t)calloc(newSize * sizeof(char), 1);
				if (!_parent->data) {
					printf("grow: out of memory\n");
					exit(-1);				
				}
				memcpy((void*)_parent->data, p, _parent->size * sizeof(char));
			} else {
				_parent->data = (uintptr_t)realloc((void*)_parent->data, newSize * sizeof(char));
				if (!_parent->data) {
					printf("grow: out of memory\n");
					exit(-1);				
				}
				memset((char*)_parent->data + _parent->size, 0, (newSize - _parent->size) * sizeof(char));
			}
			_parent->size = newSize;
		}

		*_return = _parent;
	;
}

void sjf_array_char_setAt(sjs_array_char* _parent, int32_t index, char item) {
    
		
		

		if (index >= _parent->size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, _parent->size);
			exit(-1);
		}

		char* p = (char*)_parent->data;
#if !true
		if (p[index] != 0) {
			;
		}
#endif
		;
		p[index] = item;
	;
}

void sjf_global_destroy(sjs_global* _this) {
}

void sjf_string(sjs_string* _this, sjs_string** _return) {

    *_return = _this;
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t dotTemp1;
    bool result2;

    dotTemp1 = item->count;
    result2 = dotTemp1 > 0;
    if (result2) {
        sjs_array_char* dotTemp14;
        int32_t dotTemp15;
        int32_t dotTemp2;
        int32_t dotTemp3;
        sjs_array_char* dotTemp4;
        int32_t dotTemp5;
        int32_t dotTemp9;
        int32_t i;
        int32_t loopEnd1;
        char result12;
        int32_t result3;
        int32_t result4;
        bool result5;

        dotTemp2 = _parent->count;
        dotTemp3 = item->count;
        result3 = dotTemp2 + dotTemp3;
        result4 = result3 + 1;
        dotTemp4 = _parent->data;
        dotTemp5 = dotTemp4->size;
        result5 = result4 > dotTemp5;
        if (result5) {
            sjs_array_char* dotTemp6;
            int32_t dotTemp7;
            int32_t dotTemp8;
            sjs_array_char* result6;
            int32_t result7;
            int32_t result8;

            dotTemp6 = _parent->data;
            result6 = 0;
            dotTemp7 = _parent->count;
            dotTemp8 = item->count;
            result7 = dotTemp7 + dotTemp8;
            result8 = result7 + 1;
            sjf_array_char_grow(dotTemp6, result8, &result6);

            result6->_refCount--;
            printf("RELEASE\tsjs_array_char*\t%0x\tvoid sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return)\t%d\n", (uintptr_t)result6, result6->_refCount);
            if (result6->_refCount <= 0) {
                sjf_array_char_destroy(result6);
                free(result6);
            }
        }

        i = 0;
        dotTemp9 = item->count;
        loopEnd1 = dotTemp9;
        while (i < loopEnd1) {
            sjs_array_char* dotTemp10;
            int32_t dotTemp11;
            int32_t dotTemp13;
            int32_t result11;
            char result9;

            dotTemp10 = _parent->data;
            dotTemp11 = _parent->count;
            result9 = 0;
            sjf_string_getAt(item, i, &result9);
            sjf_array_char_setAt(dotTemp10, dotTemp11, result9);
            dotTemp13 = _parent->count;
            result11 = dotTemp13 + 1;
            _parent->count = result11;
            i++;
        }

        dotTemp14 = _parent->data;
        dotTemp15 = _parent->count;
        result12 = (char)0;
        sjf_array_char_setAt(dotTemp14, dotTemp15, result12);
    }

    *_return = _parent;
}

void sjf_string_destroy(sjs_string* _this) {
    _this->data->_refCount--;
    printf("RELEASE\tsjs_array_char*\t%0x\tvoid sjf_string_destroy(sjs_string* _this)\t%d\n", (uintptr_t)_this->data, _this->data->_refCount);;
    if (_this->data->_refCount <= 0) {
        sjf_array_char_destroy(_this->data);
    }
}

void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return) {
    sjs_array_char* dotTemp12;
    char result10;

    dotTemp12 = _parent->data;
    result10 = 0;
    sjf_array_char_getAt(dotTemp12, index, &result10);

    *_return = result10;
}

int main() {
    global._refCount = 1;
    sjs_global* _this = &global;
    sjs_string* a;
    sjs_anon1* console;
    sjs_anon4* convert;
    sjs_anon2* parse;
    sjs_anon3* random;
    sjs_string* result1;
    sjs_anon4* sjv_temp1;
    sjs_anon3* sjv_temp2;
    sjs_anon2* sjv_temp3;
    sjs_anon1* sjv_temp4;
    sjs_string* sjv_temp5;
    sjs_array_char* sjv_temp6;
    sjs_string* sjv_temp7;
    sjs_array_char* sjv_temp8;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    printf("RETAIN\tsjs_anon4*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp1, sjv_temp1->_refCount);;
    sjf_anon4(sjv_temp1, &sjv_temp1);
    convert = sjv_temp1;
    convert->_refCount++;
    printf("RETAIN\tsjs_anon4*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)convert, convert->_refCount);;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    printf("RETAIN\tsjs_anon3*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp2, sjv_temp2->_refCount);;
    sjf_anon3(sjv_temp2, &sjv_temp2);
    random = sjv_temp2;
    random->_refCount++;
    printf("RETAIN\tsjs_anon3*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)random, random->_refCount);;
    sjv_temp3 = &sjd_temp3;
    sjv_temp3->_refCount = 1;
    printf("RETAIN\tsjs_anon2*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp3, sjv_temp3->_refCount);;
    sjf_anon2(sjv_temp3, &sjv_temp3);
    parse = sjv_temp3;
    parse->_refCount++;
    printf("RETAIN\tsjs_anon2*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)parse, parse->_refCount);;
    sjv_temp4 = &sjd_temp4;
    sjv_temp4->_refCount = 1;
    printf("RETAIN\tsjs_anon1*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp4, sjv_temp4->_refCount);;
    sjf_anon1(sjv_temp4, &sjv_temp4);
    console = sjv_temp4;
    console->_refCount++;
    printf("RETAIN\tsjs_anon1*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)console, console->_refCount);;
    sjv_temp5 = &sjd_temp5;
    sjv_temp5->_parent = _this;
    sjv_temp5->_refCount = 1;
    printf("RETAIN\tsjs_string*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp5, sjv_temp5->_refCount);;
    sjv_temp6 = &sjd_temp6;
    sjv_temp6->_refCount = 1;
    printf("RETAIN\tsjs_array_char*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp6, sjv_temp6->_refCount);;
    sjv_temp6->size = 6;
    sjv_temp6->data = (uintptr_t)sjg_string1;
    sjv_temp6->_isGlobal = false;
    sjf_array_char(sjv_temp6, &sjv_temp6);
    sjv_temp5->count = 5;
    sjv_temp5->data = sjv_temp6;
    sjv_temp5->data->_refCount++;
    printf("RETAIN\tsjs_array_char*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp5->data, sjv_temp5->data->_refCount);;
    sjf_string(sjv_temp5, &sjv_temp5);
    result1 = 0;
    sjv_temp7 = &sjd_temp7;
    sjv_temp7->_parent = _this;
    sjv_temp7->_refCount = 1;
    printf("RETAIN\tsjs_string*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp7, sjv_temp7->_refCount);;
    sjv_temp8 = &sjd_temp8;
    sjv_temp8->_refCount = 1;
    printf("RETAIN\tsjs_array_char*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp8, sjv_temp8->_refCount);;
    sjv_temp8->size = 4;
    sjv_temp8->data = (uintptr_t)sjg_string2;
    sjv_temp8->_isGlobal = false;
    sjf_array_char(sjv_temp8, &sjv_temp8);
    sjv_temp7->count = 3;
    sjv_temp7->data = sjv_temp8;
    sjv_temp7->data->_refCount++;
    printf("RETAIN\tsjs_array_char*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp7->data, sjv_temp7->data->_refCount);;
    sjf_string(sjv_temp7, &sjv_temp7);
    sjf_string_add(sjv_temp5, sjv_temp7, &result1);
    a = result1;
    a->_refCount++;
    printf("RETAIN\tsjs_string*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)a, a->_refCount);;

    a->_refCount--;
    printf("RELEASE\tsjs_string*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)a, a->_refCount);
    if (a->_refCount <= 0) {
        sjf_string_destroy(a);
    }
    console->_refCount--;
    printf("RELEASE\tsjs_anon1*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)console, console->_refCount);
    if (console->_refCount <= 0) {
        sjf_anon1_destroy(console);
    }
    convert->_refCount--;
    printf("RELEASE\tsjs_anon4*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)convert, convert->_refCount);
    if (convert->_refCount <= 0) {
        sjf_anon4_destroy(convert);
    }
    parse->_refCount--;
    printf("RELEASE\tsjs_anon2*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)parse, parse->_refCount);
    if (parse->_refCount <= 0) {
        sjf_anon2_destroy(parse);
    }
    random->_refCount--;
    printf("RELEASE\tsjs_anon3*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)random, random->_refCount);
    if (random->_refCount <= 0) {
        sjf_anon3_destroy(random);
    }
    result1->_refCount--;
    printf("RELEASE\tsjs_string*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)result1, result1->_refCount);
    if (result1->_refCount <= 0) {
        sjf_string_destroy(result1);
        free(result1);
    }
    sjv_temp1->_refCount--;
    printf("RELEASE\tsjs_anon4*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp1, sjv_temp1->_refCount);
    if (sjv_temp1->_refCount <= 0) {
        sjf_anon4_destroy(sjv_temp1);
    }
    sjv_temp2->_refCount--;
    printf("RELEASE\tsjs_anon3*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp2, sjv_temp2->_refCount);
    if (sjv_temp2->_refCount <= 0) {
        sjf_anon3_destroy(sjv_temp2);
    }
    sjv_temp3->_refCount--;
    printf("RELEASE\tsjs_anon2*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp3, sjv_temp3->_refCount);
    if (sjv_temp3->_refCount <= 0) {
        sjf_anon2_destroy(sjv_temp3);
    }
    sjv_temp4->_refCount--;
    printf("RELEASE\tsjs_anon1*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp4, sjv_temp4->_refCount);
    if (sjv_temp4->_refCount <= 0) {
        sjf_anon1_destroy(sjv_temp4);
    }
    sjv_temp5->_refCount--;
    printf("RELEASE\tsjs_string*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp5, sjv_temp5->_refCount);
    if (sjv_temp5->_refCount <= 0) {
        sjf_string_destroy(sjv_temp5);
    }
    sjv_temp6->_refCount--;
    printf("RELEASE\tsjs_array_char*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp6, sjv_temp6->_refCount);
    if (sjv_temp6->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp6);
    }
    sjv_temp7->_refCount--;
    printf("RELEASE\tsjs_string*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp7, sjv_temp7->_refCount);
    if (sjv_temp7->_refCount <= 0) {
        sjf_string_destroy(sjv_temp7);
    }
    sjv_temp8->_refCount--;
    printf("RELEASE\tsjs_array_char*\t%0x\tvoid sjf_global(sjs_global* _this)\t%d\n", (uintptr_t)sjv_temp8, sjv_temp8->_refCount);
    if (sjv_temp8->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp8);
    }
    assert(sjd_temp1._refCount == 0);
    assert(sjd_temp2._refCount == 0);
    assert(sjd_temp3._refCount == 0);
    assert(sjd_temp4._refCount == 0);
    assert(sjd_temp5._refCount == 0);
    assert(sjd_temp6._refCount == 0);
    assert(sjd_temp7._refCount == 0);
    assert(sjd_temp8._refCount == 0);
    sjf_global_destroy(&global);
    return 0;
}
