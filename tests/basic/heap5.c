#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_array_char sjs_array_char;

struct td_sjs_a {
    int _refCount;
    sjs_array_char* data;
};

struct td_sjs_array_char {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

sjs_a* sjf_a(sjs_a* _this);
void sjf_a_destroy(sjs_a* _this);
sjs_array_char* sjf_array_char(sjs_array_char* _this);
void sjf_array_char_destroy(sjs_array_char* _this);
sjs_a* sjf_global();

sjs_a* sjf_a(sjs_a* _this) {
    _this->_refCount++;

    return _this;
}

void sjf_a_destroy(sjs_a* _this) {
    _this->data->_refCount--;
    if (_this->data->_refCount == 0) {
        sjf_array_char_destroy(_this->data);
        free(_this->data);
    }
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

sjs_a* sjf_global() {
    sjs_a* result2;
    sjs_array_char* result3;
    uintptr_t result4;
    sjs_array_char* sjv_temp1;
    sjs_a* sjv_temp2;

    result4 = (uintptr_t)0;
    sjv_temp1 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp1->_refCount = 1;
    sjv_temp1->size = 0;
    sjv_temp1->data = result4;
    sjv_temp1->_isGlobal = false;
    result3 = sjf_array_char(sjv_temp1);
    sjv_temp2 = (sjs_a*)malloc(sizeof(sjs_a));
    sjv_temp2->_refCount = 1;
    sjv_temp2->data = result3;
    sjv_temp2->data->_refCount++;
    result2 = sjf_a(sjv_temp2);

    result3->_refCount--;
    if (result3->_refCount == 0) {
        sjf_array_char_destroy(result3);
        free(result3);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount == 0) {
        sjf_array_char_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjv_temp2->_refCount--;
    if (sjv_temp2->_refCount == 0) {
        sjf_a_destroy(sjv_temp2);
        free(sjv_temp2);
    }

    return result2;
}

int main() {
    sjs_a* result1;

    result1 = sjf_global();

    return 0;
}
