#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const char* sjg_string1 = "he\"llo";
const char* sjg_string2 = "he\nllo";
const char* sjg_string3 = "hello";

typedef struct td_sjs_array_char sjs_array_char;

struct td_sjs_array_char {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

sjs_array_char* sjf_array_char(sjs_array_char* _this);
void sjf_array_char_destroy(sjs_array_char* _this);
char sjf_array_char_getAt(sjs_array_char* _parent, int32_t index);
char sjf_global();

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

char sjf_global() {
    sjs_array_char* a;
    sjs_array_char* b;
    char c;
    char d;
    char e;
    sjs_array_char* f;
    char h;
    sjs_array_char* result2;
    sjs_array_char* result3;
    sjs_array_char* result4;
    char result5;
    sjs_array_char sjd_temp1;
    sjs_array_char sjd_temp2;
    sjs_array_char sjd_temp3;
    sjs_array_char* sjv_temp1;
    sjs_array_char* sjv_temp2;
    sjs_array_char* sjv_temp3;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjv_temp1->size = 7;
    sjv_temp1->data = sjg_string1;
    sjv_temp1->_isGlobal = false;
    result2 = sjf_array_char(sjv_temp1);
    a = result2;
    a->_refCount++;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjv_temp2->size = 7;
    sjv_temp2->data = sjg_string2;
    sjv_temp2->_isGlobal = false;
    result3 = sjf_array_char(sjv_temp2);
    b = result3;
    b->_refCount++;
    c = 'a';
    d = '\'';
    e = '\n';
    sjv_temp3 = &sjd_temp3;
    sjv_temp3->_refCount = 1;
    sjv_temp3->size = 5;
    sjv_temp3->data = sjg_string3;
    sjv_temp3->_isGlobal = false;
    result4 = sjf_array_char(sjv_temp3);
    f = result4;
    f->_refCount++;
    result5 = sjf_array_char_getAt(a, 0);
    h = result5;

    sjf_array_char_destroy(a);
    sjf_array_char_destroy(b);
    sjf_array_char_destroy(f);
    result2->_refCount--;
    if (result2->_refCount == 0) {
        sjf_array_char_destroy(result2);
        free(result2);
    }
    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_array_char_destroy(result3);
        free(result3);
    }
    result4->_refCount--;
    if (result4->_refCount == 0) {
        sjf_array_char_destroy(result4);
        free(result4);
    }
    sjf_array_char_destroy(sjv_temp1);
    sjf_array_char_destroy(sjv_temp2);
    sjf_array_char_destroy(sjv_temp3);

    return result5;
}

int main() {
    char result1;

    result1 = sjf_global();

    return 0;
}
