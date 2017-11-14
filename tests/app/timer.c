#include <emscripten.h>
#include <emscripten/html5.h>
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

const char* sjg_string1 = "foo";
const char* sjg_string2 = "root";
const char* sjg_string3 = "hi";
const char* sjg_string4 = "click";
const char* sjg_string5 = "";

#define sji_element_typeId 1
#define sjs_anon1_typeId 2
#define sjs_anon2_typeId 3
#define sjs_anon3_typeId 4
#define sjs_anon4_typeId 5
#define sjs_array_char_typeId 6
#define sjs_array_sji_element_typeId 7
#define sjs_element_typeId 8
#define sjs_global_typeId 9
#define sjs_object_typeId 10
#define sjs_string_typeId 11
#define sjs_timerElement_typeId 12

typedef struct td_sji_element sji_element;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_anon4 sjs_anon4;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_array_sji_element sjs_array_sji_element;
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
};

struct td_sjs_anon2 {
    int _refCount;
};

struct td_sjs_anon3 {
    int _refCount;
};

struct td_sjs_anon4 {
    int _refCount;
    sjs_global* _parent;
};

struct td_sjs_array_char {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_sji_element {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_element {
    int _refCount;
    sjs_global* _parent;
    sjs_string* id;
    sjs_array_sji_element* children;
};

struct td_sjs_global {
    int _refCount;
    sjs_anon4* convert;
    sjs_anon1* console;
    sjs_timerElement* timerElement;
    sjs_element* rootElement;
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
    int32_t counter;
};


	

	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_write(sjs_anon1* _parent, sjs_string* data);
void sjf_anon2(sjs_anon2* _this, sjs_anon2** _return);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon3(sjs_anon3* _this, sjs_anon3** _return);
void sjf_anon3_destroy(sjs_anon3* _this);
void sjf_anon4(sjs_anon4* _this, sjs_anon4** _return);
void sjf_anon4_destroy(sjs_anon4* _this);
void sjf_anon4_i32toString(sjs_anon4* _parent, int32_t val, sjs_string** _return);
void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newSize, sjs_array_char** _return);
void sjf_array_char_setAt(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_sji_element(sjs_array_sji_element* _this, sjs_array_sji_element** _return);
void sjf_array_sji_element_destroy(sjs_array_sji_element* _this);
void sjf_array_sji_element_getAt(sjs_array_sji_element* _parent, int32_t index, sji_element** _return);
void sjf_array_sji_element_setAt(sjs_array_sji_element* _parent, int32_t index, sji_element* item);
void sjf_element(sjs_element* _this, sjs_element** _return);
sjs_object* sjf_element_asInterface(sjs_element* _this, int typeId);
sji_element* sjf_element_as_sji_element(sjs_element* _this);
void sjf_element_destroy(sjs_element* _this);
void sjf_element_toHTML(sjs_element* _parent, sjs_string** _return);
void sjf_element_update(sjs_element* _parent);
void sjf_global_destroy(sjs_global* _this);
void sjf_mainLoop(sjs_global* _parent);
void sjf_onClick(sjs_global* _parent, double timestemp, int32_t x, int32_t y);
void sjf_string(sjs_string* _this, sjs_string** _return);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return);
void sjf_timerElement(sjs_timerElement* _this, sjs_timerElement** _return);
sjs_object* sjf_timerElement_asInterface(sjs_timerElement* _this, int typeId);
sji_element* sjf_timerElement_as_sji_element(sjs_timerElement* _this);
void sjf_timerElement_destroy(sjs_timerElement* _this);
void sjf_timerElement_onTick(sjs_timerElement* _parent, int32_t* _return);
void sjf_timerElement_toHTML(sjs_timerElement* _parent, sjs_string** _return);
void sji_element_destroy(sji_element* _this);

sjs_global global;
sjs_anon3 sjd_temp1;
sjs_anon2 sjd_temp2;
sjs_timerElement sjd_temp3;
sjs_array_sji_element sjd_temp4;
sjs_element sjd_temp5;


	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
		sjf_onClick(&global, mouseEvent->timestamp, mouseEvent->targetX, mouseEvent->targetY);
		return true;
	}

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
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

void sjf_anon3(sjs_anon3* _this, sjs_anon3** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

void sjf_anon4(sjs_anon4* _this, sjs_anon4** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon4_destroy(sjs_anon4* _this) {
}

void sjf_anon4_i32toString(sjs_anon4* _parent, int32_t val, sjs_string** _return) {
    int32_t count;
    uintptr_t data;
    uintptr_t result2;
    int32_t result3;
    sjs_array_char* sjv_temp5;
    sjs_string* sjv_temp6;

    count = 0;
    result2 = (uintptr_t)0;
    data = result2;
    
			char buf[32] = { 0 };
			int i = 30;	
			do {
				buf[i] = "0123456789"[val % 10];	
				i--;
				val /= 10;
			} while (val && i);
			count = 30 - i;
			data = (uintptr_t)malloc(sizeof(char) * (count + 1));
			memcpy((void*)data, &buf[i+1], count + 1);
		;
    result3 = count + 1;
    sjv_temp5 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp5->_refCount = 1;
    sjv_temp5->size = result3;
    sjv_temp5->data = data;
    sjv_temp5->_isGlobal = false;
    sjf_array_char(sjv_temp5, &sjv_temp5);
    sjv_temp6 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp6->_refCount = 1;
    sjv_temp6->count = count;
    sjv_temp6->data = sjv_temp5;
    sjv_temp6->data->_refCount++;
    sjf_string(sjv_temp6, &sjv_temp6);
    sjv_temp6->_refCount++;

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

    *_return = sjv_temp6;
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
				memset((void*)_parent->data + _parent->size, 0, newSize - _parent->size);
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

void sjf_array_sji_element(sjs_array_sji_element* _this, sjs_array_sji_element** _return) {
    
		if (_this->size < 0) {
			exit(-1);
		}

		if (_this->data) {
			_this->_isGlobal = true;
		} else {
			_this->data = (uintptr_t)calloc(_this->size * sizeof(sji_element*), 1);
			if (!_this->data) {
				printf("grow: out of memory\n");
				exit(-1);				
			}
		}
	;
    _this->_refCount++;

    *_return = _this;
}

void sjf_array_sji_element_destroy(sjs_array_sji_element* _this) {
    
	if (!_this->_isGlobal && _this->data) {
		free((sji_element**)_this->data);
		_this->data = 0;	
	}
;
}

void sjf_array_sji_element_getAt(sjs_array_sji_element* _parent, int32_t index, sji_element** _return) {
    
		

		if (index >= _parent->size || index < 0) {
			printf("getAt: out of bounds\n");
			exit(-1);
		}

		sji_element** p = (sji_element**)_parent->data;
		sji_element* val = p[index];
#if !false
		if (val == 0) {
			printf("getAt: value is not defined at %d\n", index);
			exit(-1);
		}
#endif
		*_return = val;		
	;
}

void sjf_array_sji_element_setAt(sjs_array_sji_element* _parent, int32_t index, sji_element* item) {
    
		
		

		if (index >= _parent->size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, _parent->size);
			exit(-1);
		}

		sji_element** p = (sji_element**)_parent->data;
#if !false
		if (p[index] != 0) {
			 p[index]->_refCount--;
if ( p[index]->_refCount <= 0) {
    sji_element_destroy( p[index]);
    free( p[index]);
}
;
		}
#endif
		 item->_refCount++;
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
        case sji_element_typeId: return (sjs_object*)sjf_element_as_sji_element(_this);
    }

    return 0;
}

sji_element* sjf_element_as_sji_element(sjs_element* _this) {
    sji_element* _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(sjs_object*))sjf_element_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_element_asInterface;
    _interface->toHTML = (void(*)(sjs_object*, sjs_string**))sjf_element_toHTML;
    return _interface;
}

void sjf_element_destroy(sjs_element* _this) {
    sjf_string_destroy(_this->id);
    sjf_array_sji_element_destroy(_this->children);
}

void sjf_element_toHTML(sjs_element* _parent, sjs_string** _return) {
    sjs_array_char* sjv_temp13;
    sjs_string* sjv_temp14;

    sjv_temp13 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp13->_refCount = 1;
    sjv_temp13->size = 3;
    sjv_temp13->data = (uintptr_t)sjg_string3;
    sjv_temp13->_isGlobal = false;
    sjf_array_char(sjv_temp13, &sjv_temp13);
    sjv_temp14 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp14->_refCount = 1;
    sjv_temp14->count = 2;
    sjv_temp14->data = sjv_temp13;
    sjv_temp14->data->_refCount++;
    sjf_string(sjv_temp14, &sjv_temp14);
    sjv_temp14->_refCount++;

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

    *_return = sjv_temp14;
}

void sjf_element_update(sjs_element* _parent) {
    sjs_array_sji_element* dotTemp23;
    int32_t dotTemp24;
    sjs_string* html;
    int32_t i;
    int32_t loopEnd2;
    sjs_array_char* sjv_temp19;
    sjs_string* sjv_temp20;

    sjv_temp19 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp19->_refCount = 1;
    sjv_temp19->size = 1;
    sjv_temp19->data = (uintptr_t)sjg_string5;
    sjv_temp19->_isGlobal = false;
    sjf_array_char(sjv_temp19, &sjv_temp19);
    sjv_temp20 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp20->_refCount = 1;
    sjv_temp20->count = 0;
    sjv_temp20->data = sjv_temp19;
    sjv_temp20->data->_refCount++;
    sjf_string(sjv_temp20, &sjv_temp20);
    html = sjv_temp20;
    html->_refCount++;
    i = 0;
    dotTemp23 = _parent->children;
    dotTemp24 = dotTemp23->size;
    loopEnd2 = dotTemp24;
    while (i < loopEnd2) {
        sji_element* child;
        sjs_array_sji_element* dotTemp25;
        sji_element* result20;
        sjs_string* result21;
        sjs_string* result22;

        dotTemp25 = _parent->children;
        result20 = 0;
        sjf_array_sji_element_getAt(dotTemp25, i, &result20);
        child = result20;
        child->_refCount++;
        result21 = 0;
        result22 = 0;
        child->toHTML(child->_parent, &result22);
        sjf_string_add(html, result22, &result21);
        i++;

        result20->_refCount--;
        if (result20->_refCount <= 0) {
            sji_element_destroy(result20);
            free(result20);
        }
        result21->_refCount--;
        if (result21->_refCount <= 0) {
            sjf_string_destroy(result21);
            free(result21);
        }
        result22->_refCount--;
        if (result22->_refCount <= 0) {
            sjf_string_destroy(result22);
            free(result22);
        }
    }

    
			

			EM_ASM_({
				document.body.innerHTML = UTF8ToString($1);
			}, _parent->id->data->data, html->data->data);
		;

    html->_refCount--;
    if (html->_refCount <= 0) {
        sjf_string_destroy(html);
        free(html);
    }
    sjv_temp19->_refCount--;
    if (sjv_temp19->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp19);
        free(sjv_temp19);
    }
    sjv_temp20->_refCount--;
    if (sjv_temp20->_refCount <= 0) {
        sjf_string_destroy(sjv_temp20);
        free(sjv_temp20);
    }
}

void sjf_global_destroy(sjs_global* _this) {
}

void sjf_mainLoop(sjs_global* _parent) {
    sjs_timerElement* dotTemp20;
    sjs_element* dotTemp22;
    int32_t result18;

    dotTemp20 = _parent->timerElement;
    result18 = 0;
    sjf_timerElement_onTick(dotTemp20, &result18);
    dotTemp22 = _parent->rootElement;
    sjf_element_update(dotTemp22);
}

void sjf_onClick(sjs_global* _parent, double timestemp, int32_t x, int32_t y) {
    sjs_anon1* dotTemp19;
    sjs_array_char* sjv_temp16;
    sjs_string* sjv_temp17;

    dotTemp19 = _parent->console;
    sjv_temp16 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp16->_refCount = 1;
    sjv_temp16->size = 6;
    sjv_temp16->data = (uintptr_t)sjg_string4;
    sjv_temp16->_isGlobal = false;
    sjf_array_char(sjv_temp16, &sjv_temp16);
    sjv_temp17 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp17->_refCount = 1;
    sjv_temp17->count = 5;
    sjv_temp17->data = sjv_temp16;
    sjv_temp17->data->_refCount++;
    sjf_string(sjv_temp17, &sjv_temp17);
    sjf_anon1_write(dotTemp19, sjv_temp17);

    sjv_temp16->_refCount--;
    if (sjv_temp16->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp16);
        free(sjv_temp16);
    }
    sjv_temp17->_refCount--;
    if (sjv_temp17->_refCount <= 0) {
        sjf_string_destroy(sjv_temp17);
        free(sjv_temp17);
    }
}

void sjf_string(sjs_string* _this, sjs_string** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t dotTemp3;
    bool result5;

    dotTemp3 = item->count;
    result5 = dotTemp3 > 0;
    if (result5) {
        int32_t dotTemp11;
        sjs_array_char* dotTemp16;
        int32_t dotTemp17;
        int32_t dotTemp4;
        int32_t dotTemp5;
        sjs_array_char* dotTemp6;
        int32_t dotTemp7;
        int32_t i;
        int32_t loopEnd1;
        char result15;
        int32_t result6;
        int32_t result7;
        bool result8;

        dotTemp4 = _parent->count;
        dotTemp5 = item->count;
        result6 = dotTemp4 + dotTemp5;
        result7 = result6 + 1;
        dotTemp6 = _parent->data;
        dotTemp7 = dotTemp6->size;
        result8 = result7 > dotTemp7;
        if (result8) {
            int32_t dotTemp10;
            sjs_array_char* dotTemp8;
            int32_t dotTemp9;
            int32_t result10;
            int32_t result11;
            sjs_array_char* result9;

            dotTemp8 = _parent->data;
            result9 = 0;
            dotTemp9 = _parent->count;
            dotTemp10 = item->count;
            result10 = dotTemp9 + dotTemp10;
            result11 = result10 + 1;
            sjf_array_char_grow(dotTemp8, result11, &result9);

            result9->_refCount--;
            if (result9->_refCount <= 0) {
                sjf_array_char_destroy(result9);
                free(result9);
            }
        }

        i = 0;

        dotTemp11 = item->count;

        loopEnd1 = dotTemp11;

        while (i < loopEnd1) {
            sjs_array_char* dotTemp12;
            int32_t dotTemp13;
            int32_t dotTemp15;
            char result12;
            int32_t result14;

            dotTemp12 = _parent->data;
            dotTemp13 = _parent->count;
            result12 = 0;
            sjf_string_getAt(item, i, &result12);
            sjf_array_char_setAt(dotTemp12, dotTemp13, result12);
            dotTemp15 = _parent->count;
            result14 = dotTemp15 + 1;
            _parent->count = result14;
            i++;
        }

        dotTemp16 = _parent->data;

        dotTemp17 = _parent->count;

        result15 = (char)0;

        sjf_array_char_setAt(dotTemp16, dotTemp17, result15);
    }

    _parent->_refCount++;

    *_return = _parent;
}

void sjf_string_destroy(sjs_string* _this) {
    _this->data->_refCount--;
    if (_this->data->_refCount <= 0) {
        sjf_array_char_destroy(_this->data);
        free(_this->data);
    }
}

void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return) {
    sjs_array_char* dotTemp14;
    char result13;

    dotTemp14 = _parent->data;
    result13 = 0;
    sjf_array_char_getAt(dotTemp14, index, &result13);

    *_return = result13;
}

void sjf_timerElement(sjs_timerElement* _this, sjs_timerElement** _return) {
    _this->_refCount++;

    *_return = _this;
}

sjs_object* sjf_timerElement_asInterface(sjs_timerElement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId: return (sjs_object*)sjf_timerElement_as_sji_element(_this);
    }

    return 0;
}

sji_element* sjf_timerElement_as_sji_element(sjs_timerElement* _this) {
    sji_element* _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(sjs_object*))sjf_timerElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_timerElement_asInterface;
    _interface->toHTML = (void(*)(sjs_object*, sjs_string**))sjf_timerElement_toHTML;
    return _interface;
}

void sjf_timerElement_destroy(sjs_timerElement* _this) {
}

void sjf_timerElement_onTick(sjs_timerElement* _parent, int32_t* _return) {
    int32_t dotTemp21;
    int32_t result19;

    dotTemp21 = _parent->counter;
    result19 = dotTemp21 + 1;
    _parent->counter = result19;

    *_return = result19;
}

void sjf_timerElement_toHTML(sjs_timerElement* _parent, sjs_string** _return) {
    sjs_string* a;
    sjs_string* b;
    sjs_anon4* dotTemp1;
    int32_t dotTemp2;
    sjs_string* result1;
    sjs_string* result4;
    sjs_array_char* sjv_temp7;
    sjs_string* sjv_temp8;
    sjs_global* tempParent1;

    tempParent1 = _parent->_parent;
    dotTemp1 = tempParent1->convert;
    result1 = 0;
    dotTemp2 = _parent->counter;
    sjf_anon4_i32toString(dotTemp1, dotTemp2, &result1);
    a = result1;
    a->_refCount++;
    sjv_temp7 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp7->_refCount = 1;
    sjv_temp7->size = 4;
    sjv_temp7->data = (uintptr_t)sjg_string1;
    sjv_temp7->_isGlobal = false;
    sjf_array_char(sjv_temp7, &sjv_temp7);
    sjv_temp8 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp8->_refCount = 1;
    sjv_temp8->count = 3;
    sjv_temp8->data = sjv_temp7;
    sjv_temp8->data->_refCount++;
    sjf_string(sjv_temp8, &sjv_temp8);
    b = sjv_temp8;
    b->_refCount++;
    result4 = 0;
    sjf_string_add(b, a, &result4);

    a->_refCount--;
    if (a->_refCount <= 0) {
        sjf_string_destroy(a);
        free(a);
    }
    b->_refCount--;
    if (b->_refCount <= 0) {
        sjf_string_destroy(b);
        free(b);
    }
    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sjf_string_destroy(result1);
        free(result1);
    }
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

    *_return = result4;
}

void sji_element_destroy(sji_element* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main() {
    global._refCount = 1;
    sjs_global* _this = &global;
    sjs_timerElement* dotTemp18;
    sjs_anon2* parse;
    sjs_anon3* random;
    uintptr_t result16;
    sji_element* result17;
    sjs_array_sji_element* sjv_array1;
    sjs_anon4* sjv_temp1;
    sjs_array_char* sjv_temp10;
    sjs_string* sjv_temp11;
    sjs_array_sji_element* sjv_temp12;
    sjs_element* sjv_temp15;
    sjs_anon3* sjv_temp2;
    sjs_anon2* sjv_temp3;
    sjs_anon1* sjv_temp4;
    sjs_timerElement* sjv_temp9;

    sjv_temp1 = (sjs_anon4*)malloc(sizeof(sjs_anon4));
    sjv_temp1->_refCount = 1;
    sjf_anon4(sjv_temp1, &sjv_temp1);
    _this->convert = sjv_temp1;
    _this->convert->_refCount++;
    sjv_temp2 = &sjd_temp1;
    sjv_temp2->_refCount = 1;
    sjf_anon3(sjv_temp2, &sjv_temp2);
    random = sjv_temp2;
    random->_refCount++;
    sjv_temp3 = &sjd_temp2;
    sjv_temp3->_refCount = 1;
    sjf_anon2(sjv_temp3, &sjv_temp3);
    parse = sjv_temp3;
    parse->_refCount++;
    sjv_temp4 = (sjs_anon1*)malloc(sizeof(sjs_anon1));
    sjv_temp4->_refCount = 1;
    sjf_anon1(sjv_temp4, &sjv_temp4);
    _this->console = sjv_temp4;
    _this->console->_refCount++;
    sjv_temp9 = &sjd_temp3;
    sjv_temp9->_refCount = 1;
    sjv_temp9->counter = 0;
    sjf_timerElement(sjv_temp9, &sjv_temp9);
    _this->timerElement = sjv_temp9;
    _this->timerElement->_refCount++;
    sjv_temp10 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp10->_refCount = 1;
    sjv_temp10->size = 5;
    sjv_temp10->data = (uintptr_t)sjg_string2;
    sjv_temp10->_isGlobal = false;
    sjf_array_char(sjv_temp10, &sjv_temp10);
    sjv_temp11 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp11->_refCount = 1;
    sjv_temp11->count = 4;
    sjv_temp11->data = sjv_temp10;
    sjv_temp11->data->_refCount++;
    sjf_string(sjv_temp11, &sjv_temp11);
    result16 = (uintptr_t)0;
    sjv_temp12 = &sjd_temp4;
    sjv_temp12->_refCount = 1;
    sjv_temp12->size = 1;
    sjv_temp12->data = result16;
    sjv_temp12->_isGlobal = false;
    sjf_array_sji_element(sjv_temp12, &sjv_temp12);
    sjv_array1 = sjv_temp12;
    sjv_array1->_refCount++;
    dotTemp18 = _this->timerElement;
    result17 = sjf_timerElement_as_sji_element(dotTemp18);
    sjf_array_sji_element_setAt(sjv_array1, 0, result17);
    sjv_temp15 = &sjd_temp5;
    sjv_temp15->_refCount = 1;
    sjv_temp15->id = sjv_temp11;
    sjv_temp15->id->_refCount++;
    sjv_temp15->children = sjv_array1;
    sjv_temp15->children->_refCount++;
    sjf_element(sjv_temp15, &sjv_temp15);
    _this->rootElement = sjv_temp15;
    _this->rootElement->_refCount++;
    
	emscripten_set_click_callback(0, &global, false, em_onClick);
;

    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount <= 0) {
        sjf_anon4_destroy(sjv_temp1);
        free(sjv_temp1);
    }
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
    sjv_temp4->_refCount--;
    if (sjv_temp4->_refCount <= 0) {
        sjf_anon1_destroy(sjv_temp4);
        free(sjv_temp4);
    }
    emscripten_set_main_loop_arg((em_arg_callback_func)sjf_mainLoop, &global, 0, 0);
    return 0;
}
void main_destroy() {
    sjf_anon3_destroy(&sjd_temp1);
    sjf_anon2_destroy(&sjd_temp2);
    sjf_timerElement_destroy(&sjd_temp3);
    sjf_array_sji_element_destroy(&sjd_temp4);
    sjf_element_destroy(&sjd_temp5);
    sjf_global_destroy(&global);
}
