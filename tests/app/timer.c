#include <emscripten.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* sjg_string1 = "root";
const char* sjg_string2 = "foo";
const char* sjg_string3 = "hi";
const char* sjg_string4 = "";

#define sji_element_typeId 1
#define sjs_anon1_typeId 2
#define sjs_anon2_typeId 3
#define sjs_anon3_typeId 4
#define sjs_array_#element_typeId 5
#define sjs_array_char_typeId 6
#define sjs_element_typeId 7
#define sjs_global_typeId 8
#define sjs_object_typeId 9
#define sjs_string_typeId 10
#define sjs_timerElement_typeId 11

typedef struct td_sji_element sji_element;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_array_#element sjs_array_#element;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_element sjs_element;
typedef struct td_sjs_global sjs_global;
typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_timerElement sjs_timerElement;

struct td_sji_element {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*toHTML)(sjs_object* _parent, sjs_string** _return);
};

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

struct td_sjs_array_#element {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_char {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_element {
    int _refCount;
    sjs_global* _parent;
    sjs_string* id;
    sjs_array_#element* children;
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

struct td_sjs_timerElement {
    int _refCount;
    sjs_global* _parent;
    int32_t count;
};

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon2(sjs_anon2* _this, sjs_anon2** _return);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon3(sjs_anon3* _this, sjs_anon3** _return);
void sjf_anon3_destroy(sjs_anon3* _this);
void sjf_array_#element(sjs_array_#element* _this, sjs_array_#element** _return);
void sjf_array_#element_destroy(sjs_array_#element* _this);
void sjf_array_#element_getAt(sjs_array_#element* _parent, int32_t index, sji_element** _return);
void sjf_array_#element_setAt(sjs_array_#element* _parent, int32_t index, sji_element* item);
void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newSize, sjs_array_char** _return);
void sjf_array_char_setAt(sjs_array_char* _parent, int32_t index, char item);
void sjf_element(sjs_element* _this, sjs_element** _return);
sjs_object* sjf_element_asInterface(sjs_element* _this, int typeId);
sji_element* sjf_element_as_sji_element(sjs_element* _this);
void sjf_element_destroy(sjs_element* _this);
void sjf_element_toHTML(sjs_element* _parent, sjs_string** _return);
void sjf_element_update(sjs_element* _parent);
void sjf_global(sjs_global* _this);
void sjf_global_destroy(sjs_global* _this);
void sjf_string(sjs_string* _this, sjs_string** _return);
void sjf_string_add(sjs_string* _parent, sjs_string* item);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return);
void sjf_timerElement(sjs_timerElement* _this, sjs_timerElement** _return);
sjs_object* sjf_timerElement_asInterface(sjs_timerElement* _this, int typeId);
sji_element* sjf_timerElement_as_sji_element(sjs_timerElement* _this);
void sjf_timerElement_destroy(sjs_timerElement* _this);
void sjf_timerElement_toHTML(sjs_timerElement* _parent, sjs_string** _return);
void sji_element_destroy(sji_element* _this);

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

void sjf_array_#element(sjs_array_#element* _this, sjs_array_#element** _return) {
    
		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)malloc(_this->size * sizeof(sji_element*));
		}
	;
    _this->_refCount++;

    *_return = _this;
}

void sjf_array_#element_destroy(sjs_array_#element* _this) {
    
	if (!_this->_isGlobal) {
		free((sji_element**)_this->data);	
	}
;
}

void sjf_array_#element_getAt(sjs_array_#element* _parent, int32_t index, sji_element** _return) {
    
		

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

void sjf_array_#element_setAt(sjs_array_#element* _parent, int32_t index, sji_element* item) {
    
		
		

		if (index >= _parent->size || index < 0) {
			exit(-1);
		}

		char* p = (char*)_parent->data;
		;
		;
		p[index] = item;
	;
}

void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return) {
    
		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)malloc(_this->size * sizeof(sji_element*));
		}
	;
    _this->_refCount++;

    *_return = _this;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    
	if (!_this->_isGlobal) {
		free((sji_element**)_this->data);	
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

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newSize, sjs_array_char** _return) {
    
		
		

		if (_parent->size != newSize) {
			if (newSize < _parent->size) {
				exit(-1);
			}
			
			if (_parent->_isGlobal) {
				_parent->_isGlobal = false;
				char* p = (char*)_parent->data;
				_parent->data = (uintptr_t)malloc(newSize * sizeof(char));
				memcpy((void*)_parent->data, p, _parent->size * sizeof(char));
			} else {
				_parent->data = (uintptr_t)realloc((void*)_parent->data, newSize * sizeof(char));
			}
			_parent->size = newSize;
		}

		*_return = _parent;
	;
}

void sjf_array_char_setAt(sjs_array_char* _parent, int32_t index, char item) {
    
		
		

		if (index >= _parent->size || index < 0) {
			exit(-1);
		}

		char* p = (char*)_parent->data;
		;
		;
		p[index] = item;
	;
}

void sjf_element(sjs_element* _this, sjs_element** _return) {
    _this->_refCount++;

    *_return = _this;
}

sjs_object* sjf_element_asInterface(sjs_element* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId: return sjf_element_as_sji_element(_this);
    }

    return 0;
}

sji_element* sjf_element_as_sji_element(sjs_element* _this) {
    sji_element* _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = sjf_element_destroy;
    _interface->asInterface = sjf_element_asInterface;
    _interface->toHTML = sjf_element_toHTML;
    return _interface;
}

void sjf_element_destroy(sjs_element* _this) {
    sjf_string_destroy(_this->id);
    sjf_array_#element_destroy(_this->children);
}

void sjf_element_toHTML(sjs_element* _parent, sjs_string** _return) {
    sjs_array_char* sjv_temp10;
    sjs_string* sjv_temp11;

    sjv_temp10 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp10->_refCount = 1;
    sjv_temp10->size = 2;
    sjv_temp10->data = (uintptr_t)sjg_string3;
    sjv_temp10->_isGlobal = false;
    sjf_array_char(sjv_temp10, &sjv_temp10);
    sjv_temp11 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp11->_refCount = 1;
    sjv_temp11->count = 1;
    sjv_temp11->data = sjv_temp10;
    sjv_temp11->data->_refCount++;
    sjf_string(sjv_temp11, &sjv_temp11);
    sjv_temp11->_refCount++;

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

    *_return = sjv_temp11;
}

void sjf_element_update(sjs_element* _parent) {
    sjs_string* html;
    int32_t i;
    int32_t loopEnd1;
    sjs_array_char* sjv_temp13;
    sjs_string* sjv_temp14;
    sjs_array_#element* temp1;
    int32_t temp2;

    sjv_temp13 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp13->_refCount = 1;
    sjv_temp13->size = 0;
    sjv_temp13->data = (uintptr_t)sjg_string4;
    sjv_temp13->_isGlobal = false;
    sjf_array_char(sjv_temp13, &sjv_temp13);
    sjv_temp14 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp14->_refCount = 1;
    sjv_temp14->count = -1;
    sjv_temp14->data = sjv_temp13;
    sjv_temp14->data->_refCount++;
    sjf_string(sjv_temp14, &sjv_temp14);
    html = sjv_temp14;
    html->_refCount++;
    i = 0;
    temp1 = _parent->children;
    temp2 = temp1->size;
    loopEnd1 = temp2;
    while (i <= loopEnd1) {
        sji_element sjd_temp7;
        sji_element* child;
        sji_element* result4;
        sjs_string* result5;
        sjs_array_#element* temp3;

        temp3 = _parent->children;
        result4 = &sjd_temp7;
        sjf_array_#element_getAt(temp3, i, &result4);
        child = result4;
        child->_refCount++;
        result5 = 0;
        child->toHTML(child->_parent, &result5);
        sjf_string_add(html, result5);
        i++;

        result5->_refCount--;
        if (result5->_refCount <= 0) {
            sjf_string_destroy(result5);
            free(result5);
        }
        sji_element_destroy(&sjd_temp7);
    }

    
			

			EM_ASM_({
				document.getElementById(UTF8ToString($0)).innerHTML = UTF8ToString($1);
			}, _parent->id->data, html->data);
		;

    html->_refCount--;
    if (html->_refCount <= 0) {
        sjf_string_destroy(html);
        free(html);
    }
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
}

void sjf_global(sjs_global* _this) {
    sjs_anon3 sjd_temp1;
    sjs_anon2 sjd_temp2;
    sjs_anon1 sjd_temp3;
    sjs_array_#element sjd_temp4;
    sjs_timerElement sjd_temp5;
    sjs_element sjd_temp6;
    sjs_anon1* console;
    sjs_anon2* parse;
    sjs_anon3* random;
    uintptr_t result1;
    uintptr_t result2;
    sji_element* result3;
    sjs_element* rootElement;
    sjs_array_#element* sjv_array1;
    sjs_anon3* sjv_temp1;
    sjs_element* sjv_temp12;
    sjs_anon2* sjv_temp2;
    sjs_anon1* sjv_temp3;
    sjs_array_char* sjv_temp4;
    sjs_string* sjv_temp5;
    sjs_array_#element* sjv_temp6;
    sjs_timerElement* sjv_temp9;

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
    sjv_temp4->size = 4;
    sjv_temp4->data = (uintptr_t)sjg_string1;
    sjv_temp4->_isGlobal = false;
    sjf_array_char(sjv_temp4, &sjv_temp4);
    sjv_temp5 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp5->_refCount = 1;
    sjv_temp5->count = 3;
    sjv_temp5->data = sjv_temp4;
    sjv_temp5->data->_refCount++;
    sjf_string(sjv_temp5, &sjv_temp5);
    result2 = (uintptr_t)0;
    sjv_temp6 = &sjd_temp4;
    sjv_temp6->_refCount = 1;
    sjv_temp6->size = 1;
    sjv_temp6->data = result2;
    sjv_temp6->_isGlobal = false;
    sjf_array_#element(sjv_temp6, &sjv_temp6);
    sjv_array1 = sjv_temp6;
    sjv_array1->_refCount++;
    sjv_temp9 = &sjd_temp5;
    sjv_temp9->_refCount = 1;
    sjv_temp9->count = 0;
    sjf_timerElement(sjv_temp9, &sjv_temp9);
    result3 = sjf_timerElement_as_sji_element(sjv_temp9);
    sjf_array_#element_setAt(sjv_array1, 0, result3);
    sjv_temp12 = &sjd_temp6;
    sjv_temp12->_refCount = 1;
    sjv_temp12->id = sjv_temp5;
    sjv_temp12->id->_refCount++;
    sjv_temp12->children = sjv_array1;
    sjv_temp12->children->_refCount++;
    sjf_element(sjv_temp12, &sjv_temp12);
    rootElement = sjv_temp12;
    rootElement->_refCount++;
    sjf_element_update(rootElement);

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
    sjf_array_#element_destroy(&sjd_temp4);
    sjf_timerElement_destroy(&sjd_temp5);
    sjf_element_destroy(&sjd_temp6);
}

void sjf_global_destroy(sjs_global* _this) {
}

void sjf_string(sjs_string* _this, sjs_string** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_string_add(sjs_string* _parent, sjs_string* item) {
    int32_t i;
    int32_t loopEnd2;
    int32_t result10;
    char result14;
    int32_t result6;
    bool result7;
    int32_t temp12;
    sjs_array_char* temp17;
    int32_t temp18;
    int32_t temp4;
    int32_t temp5;
    sjs_array_char* temp6;
    int32_t temp7;

    temp4 = _parent->count;
    temp5 = item->count;
    result6 = temp4 + temp5;
    temp6 = _parent->data;
    temp7 = temp6->size;
    result7 = result6 > temp7;
    if (result7) {
        sjs_array_char sjd_temp8;
        sjs_array_char* result8;
        int32_t result9;
        int32_t temp10;
        int32_t temp11;
        sjs_array_char* temp8;
        sjs_array_char* temp9;

        temp8 = _parent->data;
        result8 = &sjd_temp8;
        temp9 = _parent->data;
        temp10 = temp9->size;
        temp11 = item->count;
        result9 = temp10 + temp11;
        sjf_array_char_grow(temp8, result9, &result8);

        temp8->_refCount--;
        if (temp8->_refCount <= 0) {
            sjf_array_char_destroy(temp8);
            free(temp8);
        }
        temp9->_refCount--;
        if (temp9->_refCount <= 0) {
            sjf_array_char_destroy(temp9);
            free(temp9);
        }
        sjf_array_char_destroy(&sjd_temp8);
    }

    i = 0;

    temp12 = item->count;

    result10 = temp12 - 1;

    loopEnd2 = result10;

    while (i <= loopEnd2) {
        char result11;
        int32_t result13;
        sjs_array_char* temp13;
        int32_t temp14;
        int32_t temp16;

        temp13 = _parent->data;
        temp14 = _parent->count;
        result11 = 0;
        sjf_string_getAt(item, i, &result11);
        sjf_array_char_setAt(temp13, temp14, result11);
        temp16 = _parent->count;
        result13 = temp16 + 1;
        _parent->count = result13;
        i++;

        temp13->_refCount--;
        if (temp13->_refCount <= 0) {
            sjf_array_char_destroy(temp13);
            free(temp13);
        }
    }

    temp17 = _parent->data;

    temp18 = _parent->count;

    result14 = (char)0;

    sjf_array_char_setAt(temp17, temp18, result14);

    temp17->_refCount--;
    if (temp17->_refCount <= 0) {
        sjf_array_char_destroy(temp17);
        free(temp17);
    }
    temp6->_refCount--;
    if (temp6->_refCount <= 0) {
        sjf_array_char_destroy(temp6);
        free(temp6);
    }
}

void sjf_string_destroy(sjs_string* _this) {
    _this->data->_refCount--;
    if (_this->data->_refCount <= 0) {
        sjf_array_char_destroy(_this->data);
        free(_this->data);
    }
}

void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return) {
    char result12;
    sjs_array_char* temp15;

    temp15 = _parent->data;
    result12 = 0;
    sjf_array_char_getAt(temp15, index, &result12);

    temp15->_refCount--;
    if (temp15->_refCount <= 0) {
        sjf_array_char_destroy(temp15);
        free(temp15);
    }

    *_return = result12;
}

void sjf_timerElement(sjs_timerElement* _this, sjs_timerElement** _return) {
    _this->_refCount++;

    *_return = _this;
}

sjs_object* sjf_timerElement_asInterface(sjs_timerElement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId: return sjf_timerElement_as_sji_element(_this);
    }

    return 0;
}

sji_element* sjf_timerElement_as_sji_element(sjs_timerElement* _this) {
    sji_element* _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = sjf_timerElement_destroy;
    _interface->asInterface = sjf_timerElement_asInterface;
    _interface->toHTML = sjf_timerElement_toHTML;
    return _interface;
}

void sjf_timerElement_destroy(sjs_timerElement* _this) {
}

void sjf_timerElement_toHTML(sjs_timerElement* _parent, sjs_string** _return) {
    sjs_array_char* sjv_temp7;
    sjs_string* sjv_temp8;

    sjv_temp7 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp7->_refCount = 1;
    sjv_temp7->size = 3;
    sjv_temp7->data = (uintptr_t)sjg_string2;
    sjv_temp7->_isGlobal = false;
    sjf_array_char(sjv_temp7, &sjv_temp7);
    sjv_temp8 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp8->_refCount = 1;
    sjv_temp8->count = 2;
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

void sji_element_destroy(sji_element* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main() {
    sjs_global sjd_temp9;
    sjs_global* sjv_temp15;

    sjv_temp15 = &sjd_temp9;
    sjv_temp15->_refCount = 1;
    sjf_global(sjv_temp15);
    sjf_global_destroy(&sjd_temp9);

    return 0;
}
