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

const char* sjg_string1 = "sjCTX";
const char* sjg_string10 = "render - 2";
const char* sjg_string11 = "mainLoop - 1";
const char* sjg_string2 = "fillRect";
const char* sjg_string3 = "#";
const char* sjg_string4 = "click";
const char* sjg_string5 = "";
const char* sjg_string6 = "48px serif";
const char* sjg_string7 = "button - render - 1";
const char* sjg_string8 = "button - render - 2";
const char* sjg_string9 = "setRect - 2";

#define sji_element_typeId 1
#define sji_surface_typeId 2
#define sjs_anon1_typeId 3
#define sjs_anon2_typeId 4
#define sjs_anon3_typeId 5
#define sjs_anon4_typeId 6
#define sjs_anon5_typeId 7
#define sjs_array_char_typeId 8
#define sjs_array_sji_element_typeId 9
#define sjs_button_typeId 10
#define sjs_color_typeId 11
#define sjs_element_typeId 12
#define sjs_global_typeId 13
#define sjs_htmlCanvas2d_typeId 14
#define sjs_object_typeId 15
#define sjs_rect_typeId 16
#define sjs_string_typeId 17

typedef struct td_sji_element sji_element;
typedef struct td_sji_surface sji_surface;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_anon4 sjs_anon4;
typedef struct td_sjs_anon5 sjs_anon5;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_array_sji_element sjs_array_sji_element;
typedef struct td_sjs_button sjs_button;
typedef struct td_sjs_color sjs_color;
typedef struct td_sjs_element sjs_element;
typedef struct td_sjs_global sjs_global;
typedef struct td_sjs_htmlCanvas2d sjs_htmlCanvas2d;
typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_string sjs_string;

struct td_sji_element {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*setRect)(sjs_object* _parent, sjs_rect* );
    void (*render)(sjs_object* _parent, sji_surface* );
};

struct td_sji_surface {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*fillRect)(sjs_object* _parent, sjs_rect* , sjs_color* );
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

struct td_sjs_anon5 {
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

struct td_sjs_button {
    int _refCount;
    sjs_global* _parent;
    sjs_string* text;
    sjs_string* font;
    sjs_rect* rect;
};

struct td_sjs_color {
    int _refCount;
    sjs_global* _parent;
    int32_t r;
    int32_t g;
    int32_t b;
    int32_t a;
};

struct td_sjs_element {
    int _refCount;
    sjs_global* _parent;
    sjs_array_sji_element* children;
    sjs_rect* rect;
};

struct td_sjs_global {
    int _refCount;
    sjs_anon1* console;
    sjs_anon4* convert;
    sjs_anon5* style;
    sji_element* root;
    sji_surface* rootCanvas;
};

struct td_sjs_htmlCanvas2d {
    int _refCount;
    sjs_global* _parent;
    sjs_string* ctxVarName;
};

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_rect {
    int _refCount;
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct td_sjs_string {
    int _refCount;
    sjs_global* _parent;
    int32_t count;
    sjs_array_char* data;
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
void sjf_anon4_i32toString(sjs_anon4* _parent, int32_t val, int32_t base, int32_t minLength, sjs_string** _return);
void sjf_anon5(sjs_anon5* _this, sjs_anon5** _return);
void sjf_anon5_destroy(sjs_anon5* _this);
void sjf_anon5_getFont(sjs_anon5* _parent, int32_t typeId, sjs_string** _return);
void sjf_array_char(sjs_array_char* _this, sjs_array_char** _return);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newSize, sjs_array_char** _return);
void sjf_array_char_setAt(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_sji_element(sjs_array_sji_element* _this, sjs_array_sji_element** _return);
void sjf_array_sji_element_destroy(sjs_array_sji_element* _this);
void sjf_array_sji_element_getAt(sjs_array_sji_element* _parent, int32_t index, sji_element** _return);
void sjf_array_sji_element_setAt(sjs_array_sji_element* _parent, int32_t index, sji_element* item);
void sjf_button(sjs_button* _this, sjs_button** _return);
sjs_object* sjf_button_asInterface(sjs_button* _this, int typeId);
sji_element* sjf_button_as_sji_element(sjs_button* _this);
void sjf_button_destroy(sjs_button* _this);
void sjf_button_render(sjs_button* _parent, sji_surface* surface);
void sjf_button_setRect(sjs_button* _parent, sjs_rect* rect_);
void sjf_color(sjs_color* _this, sjs_color** _return);
void sjf_color_asString(sjs_color* _parent, sjs_string** _return);
void sjf_color_destroy(sjs_color* _this);
void sjf_element(sjs_element* _this, sjs_element** _return);
sjs_object* sjf_element_asInterface(sjs_element* _this, int typeId);
sji_element* sjf_element_as_sji_element(sjs_element* _this);
void sjf_element_destroy(sjs_element* _this);
void sjf_element_render(sjs_element* _parent, sji_surface* surface);
void sjf_element_setRect(sjs_element* _parent, sjs_rect* rect_);
void sjf_global_destroy(sjs_global* _this);
void sjf_htmlCanvas2d(sjs_htmlCanvas2d* _this, sjs_htmlCanvas2d** _return);
sjs_object* sjf_htmlCanvas2d_asInterface(sjs_htmlCanvas2d* _this, int typeId);
sji_surface* sjf_htmlCanvas2d_as_sji_surface(sjs_htmlCanvas2d* _this);
void sjf_htmlCanvas2d_destroy(sjs_htmlCanvas2d* _this);
void sjf_htmlCanvas2d_fillRect(sjs_htmlCanvas2d* _parent, sjs_rect* rect, sjs_color* color);
void sjf_mainLoop(sjs_global* _parent);
void sjf_onClick(sjs_global* _parent, double timestemp, int32_t x, int32_t y);
void sjf_rect(sjs_rect* _this, sjs_rect** _return);
void sjf_rect_destroy(sjs_rect* _this);
void sjf_string(sjs_string* _this, sjs_string** _return);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return);
void sji_element_destroy(sji_element* _this);
void sji_surface_destroy(sji_surface* _this);

sjs_global global;
sjs_anon3 sjd_temp1;
sjs_anon2 sjd_temp2;
sjs_htmlCanvas2d sjd_temp3;
sjs_element sjd_temp4;
sjs_array_sji_element sjd_temp5;
sjs_button sjd_temp7;


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

void sjf_anon4_i32toString(sjs_anon4* _parent, int32_t val, int32_t base, int32_t minLength, sjs_string** _return) {
    int32_t count;
    uintptr_t data;
    uintptr_t result15;
    int32_t result16;
    sjs_string* sjv_temp10;
    sjs_array_char* sjv_temp11;

    count = 0;
    result15 = (uintptr_t)0;
    data = result15;
    
			if (base < 2) {
				printf("base is too small");
				exit(-1);
			}

			if (base > 16) {
				printf("base is too large");
				exit(-1);
			}

			char buf[32] = { 0 };
			int i = 30;	
			do {
				buf[i] = "0123456789ABCDEF"[val % base];	
				i--;
				val /= base;
			} while (val && i);
			count = 30 - i;

			if (count < minLength) {				
			}

			data = (uintptr_t)malloc(sizeof(char) * (count + 1));
			memcpy((void*)data, &buf[i+1], count + 1);
			printf("%s\n", (char*)data);
		;
    sjv_temp10 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp10->_parent = _parent->_parent;
    sjv_temp10->_refCount = 1;
    sjv_temp11 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp11->_refCount = 1;
    result16 = count + 1;
    sjv_temp11->size = result16;
    sjv_temp11->data = data;
    sjv_temp11->_isGlobal = false;
    sjf_array_char(sjv_temp11, &sjv_temp11);
    sjv_temp10->count = count;
    sjv_temp10->data = sjv_temp11;
    sjv_temp10->data->_refCount++;
    sjf_string(sjv_temp10, &sjv_temp10);
    sjv_temp10->_refCount++;

    sjv_temp10->_refCount--;
    if (sjv_temp10->_refCount <= 0) {
        sjf_string_destroy(sjv_temp10);
        free(sjv_temp10);
    }
    sjv_temp11->_refCount--;
    if (sjv_temp11->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp11);
        free(sjv_temp11);
    }

    *_return = sjv_temp10;
}

void sjf_anon5(sjs_anon5* _this, sjs_anon5** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon5_destroy(sjs_anon5* _this) {
}

void sjf_anon5_getFont(sjs_anon5* _parent, int32_t typeId, sjs_string** _return) {
    sjs_string* sjv_temp23;
    sjs_array_char* sjv_temp24;

    sjv_temp23 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp23->_parent = _parent->_parent;
    sjv_temp23->_refCount = 1;
    sjv_temp24 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp24->_refCount = 1;
    sjv_temp24->size = 11;
    sjv_temp24->data = (uintptr_t)sjg_string6;
    sjv_temp24->_isGlobal = false;
    sjf_array_char(sjv_temp24, &sjv_temp24);
    sjv_temp23->count = 10;
    sjv_temp23->data = sjv_temp24;
    sjv_temp23->data->_refCount++;
    sjf_string(sjv_temp23, &sjv_temp23);
    sjv_temp23->_refCount++;

    sjv_temp23->_refCount--;
    if (sjv_temp23->_refCount <= 0) {
        sjf_string_destroy(sjv_temp23);
        free(sjv_temp23);
    }
    sjv_temp24->_refCount--;
    if (sjv_temp24->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp24);
        free(sjv_temp24);
    }

    *_return = sjv_temp23;
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

void sjf_button(sjs_button* _this, sjs_button** _return) {
    sjs_anon5* dotTemp35;
    sjs_string* result27;

    dotTemp35 = _this->_parent->style;
    result27 = 0;
    sjf_anon5_getFont(dotTemp35, 1, &result27);
    _this->_refCount++;

    result27->_refCount--;
    if (result27->_refCount <= 0) {
        sjf_string_destroy(result27);
        free(result27);
    }

    *_return = _this;
}

sjs_object* sjf_button_asInterface(sjs_button* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId: return (sjs_object*)sjf_button_as_sji_element(_this);
    }

    return 0;
}

sji_element* sjf_button_as_sji_element(sjs_button* _this) {
    sji_element* _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(sjs_object*))sjf_button_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_button_asInterface;
    _interface->setRect = (void(*)(sjs_object*,sjs_rect*))sjf_button_setRect;
    _interface->render = (void(*)(sjs_object*,sji_surface*))sjf_button_render;
    return _interface;
}

void sjf_button_destroy(sjs_button* _this) {
    sjf_string_destroy(_this->text);
    sjf_string_destroy(_this->font);
    _this->rect->_refCount--;
    if (_this->rect->_refCount <= 0) {
        sjf_rect_destroy(_this->rect);
        free(_this->rect);
    }
}

void sjf_button_render(sjs_button* _parent, sji_surface* surface) {
    sjs_color sjd_temp6;
    sjs_anon1* dotTemp36;
    sjs_rect* dotTemp37;
    sjs_anon1* dotTemp38;
    sjs_string* sjv_temp25;
    sjs_array_char* sjv_temp26;
    sjs_color* sjv_temp27;
    sjs_string* sjv_temp28;
    sjs_array_char* sjv_temp29;
    sjs_global* tempParent8;
    sjs_global* tempParent9;

    tempParent8 = _parent->_parent;
    dotTemp36 = tempParent8->console;
    sjv_temp25 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp25->_parent = _parent->_parent;
    sjv_temp25->_refCount = 1;
    sjv_temp26 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp26->_refCount = 1;
    sjv_temp26->size = 20;
    sjv_temp26->data = (uintptr_t)sjg_string7;
    sjv_temp26->_isGlobal = false;
    sjf_array_char(sjv_temp26, &sjv_temp26);
    sjv_temp25->count = 19;
    sjv_temp25->data = sjv_temp26;
    sjv_temp25->data->_refCount++;
    sjf_string(sjv_temp25, &sjv_temp25);
    sjf_anon1_write(dotTemp36, sjv_temp25);
    dotTemp37 = _parent->rect;
    sjv_temp27 = &sjd_temp6;
    sjv_temp27->_parent = _parent->_parent;
    sjv_temp27->_refCount = 1;
    sjv_temp27->r = 255;
    sjv_temp27->g = 0;
    sjv_temp27->b = 0;
    sjv_temp27->a = 255;
    sjf_color(sjv_temp27, &sjv_temp27);
    surface->fillRect(surface->_parent, dotTemp37, sjv_temp27);
    tempParent9 = _parent->_parent;
    dotTemp38 = tempParent9->console;
    sjv_temp28 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp28->_parent = _parent->_parent;
    sjv_temp28->_refCount = 1;
    sjv_temp29 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp29->_refCount = 1;
    sjv_temp29->size = 20;
    sjv_temp29->data = (uintptr_t)sjg_string8;
    sjv_temp29->_isGlobal = false;
    sjf_array_char(sjv_temp29, &sjv_temp29);
    sjv_temp28->count = 19;
    sjv_temp28->data = sjv_temp29;
    sjv_temp28->data->_refCount++;
    sjf_string(sjv_temp28, &sjv_temp28);
    sjf_anon1_write(dotTemp38, sjv_temp28);

    sjv_temp25->_refCount--;
    if (sjv_temp25->_refCount <= 0) {
        sjf_string_destroy(sjv_temp25);
        free(sjv_temp25);
    }
    sjv_temp26->_refCount--;
    if (sjv_temp26->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp26);
        free(sjv_temp26);
    }
    sjv_temp28->_refCount--;
    if (sjv_temp28->_refCount <= 0) {
        sjf_string_destroy(sjv_temp28);
        free(sjv_temp28);
    }
    sjv_temp29->_refCount--;
    if (sjv_temp29->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp29);
        free(sjv_temp29);
    }
    sjf_color_destroy(&sjd_temp6);
}

void sjf_button_setRect(sjs_button* _parent, sjs_rect* rect_) {
    _parent->rect->_refCount--;
    if (_parent->rect->_refCount <= 0) {
        sjf_rect_destroy(_parent->rect);
        free(_parent->rect);
    }

    _parent->rect = rect_;
    _parent->rect->_refCount++;
}

void sjf_color(sjs_color* _this, sjs_color** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_color_asString(sjs_color* _parent, sjs_string** _return) {
    sjs_anon4* dotTemp17;
    int32_t dotTemp18;
    sjs_anon4* dotTemp19;
    int32_t dotTemp20;
    sjs_anon4* dotTemp21;
    int32_t dotTemp22;
    sjs_anon4* dotTemp23;
    int32_t dotTemp24;
    sjs_string* result14;
    sjs_string* result17;
    sjs_string* result18;
    sjs_string* result19;
    sjs_string* result2;
    sjs_string* result20;
    sjs_string* result21;
    sjs_string* result22;
    sjs_string* sjv_temp8;
    sjs_array_char* sjv_temp9;
    sjs_global* tempParent2;
    sjs_global* tempParent3;
    sjs_global* tempParent4;
    sjs_global* tempParent5;

    sjv_temp8 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp8->_parent = _parent->_parent;
    sjv_temp8->_refCount = 1;
    sjv_temp9 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp9->_refCount = 1;
    sjv_temp9->size = 2;
    sjv_temp9->data = (uintptr_t)sjg_string3;
    sjv_temp9->_isGlobal = false;
    sjf_array_char(sjv_temp9, &sjv_temp9);
    sjv_temp8->count = 1;
    sjv_temp8->data = sjv_temp9;
    sjv_temp8->data->_refCount++;
    sjf_string(sjv_temp8, &sjv_temp8);
    result2 = 0;
    tempParent2 = _parent->_parent;
    dotTemp17 = tempParent2->convert;
    result14 = 0;
    dotTemp18 = _parent->a;
    sjf_anon4_i32toString(dotTemp17, dotTemp18, 16, 2, &result14);
    sjf_string_add(sjv_temp8, result14, &result2);
    result17 = 0;
    tempParent3 = _parent->_parent;
    dotTemp19 = tempParent3->convert;
    result18 = 0;
    dotTemp20 = _parent->r;
    sjf_anon4_i32toString(dotTemp19, dotTemp20, 16, 2, &result18);
    sjf_string_add(result2, result18, &result17);
    result19 = 0;
    tempParent4 = _parent->_parent;
    dotTemp21 = tempParent4->convert;
    result20 = 0;
    dotTemp22 = _parent->g;
    sjf_anon4_i32toString(dotTemp21, dotTemp22, 16, 2, &result20);
    sjf_string_add(result17, result20, &result19);
    result21 = 0;
    tempParent5 = _parent->_parent;
    dotTemp23 = tempParent5->convert;
    result22 = 0;
    dotTemp24 = _parent->b;
    sjf_anon4_i32toString(dotTemp23, dotTemp24, 16, 2, &result22);
    sjf_string_add(result19, result22, &result21);

    result14->_refCount--;
    if (result14->_refCount <= 0) {
        sjf_string_destroy(result14);
        free(result14);
    }
    result17->_refCount--;
    if (result17->_refCount <= 0) {
        sjf_string_destroy(result17);
        free(result17);
    }
    result18->_refCount--;
    if (result18->_refCount <= 0) {
        sjf_string_destroy(result18);
        free(result18);
    }
    result19->_refCount--;
    if (result19->_refCount <= 0) {
        sjf_string_destroy(result19);
        free(result19);
    }
    result2->_refCount--;
    if (result2->_refCount <= 0) {
        sjf_string_destroy(result2);
        free(result2);
    }
    result20->_refCount--;
    if (result20->_refCount <= 0) {
        sjf_string_destroy(result20);
        free(result20);
    }
    result22->_refCount--;
    if (result22->_refCount <= 0) {
        sjf_string_destroy(result22);
        free(result22);
    }
    sjv_temp8->_refCount--;
    if (sjv_temp8->_refCount <= 0) {
        sjf_string_destroy(sjv_temp8);
        free(sjv_temp8);
    }
    sjv_temp9->_refCount--;
    if (sjv_temp9->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp9);
        free(sjv_temp9);
    }

    *_return = result21;
}

void sjf_color_destroy(sjs_color* _this) {
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
    _interface->setRect = (void(*)(sjs_object*,sjs_rect*))sjf_element_setRect;
    _interface->render = (void(*)(sjs_object*,sji_surface*))sjf_element_render;
    return _interface;
}

void sjf_element_destroy(sjs_element* _this) {
    sjf_array_sji_element_destroy(_this->children);
    _this->rect->_refCount--;
    if (_this->rect->_refCount <= 0) {
        sjf_rect_destroy(_this->rect);
        free(_this->rect);
    }
}

void sjf_element_render(sjs_element* _parent, sji_surface* surface) {
    sjs_anon1* dotTemp31;
    sjs_array_sji_element* dotTemp32;
    int32_t dotTemp33;
    int32_t i;
    int32_t loopEnd3;
    sjs_string* sjv_temp19;
    sjs_array_char* sjv_temp20;
    sjs_global* tempParent7;

    tempParent7 = _parent->_parent;
    dotTemp31 = tempParent7->console;
    sjv_temp19 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp19->_parent = _parent->_parent;
    sjv_temp19->_refCount = 1;
    sjv_temp20 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp20->_refCount = 1;
    sjv_temp20->size = 11;
    sjv_temp20->data = (uintptr_t)sjg_string10;
    sjv_temp20->_isGlobal = false;
    sjf_array_char(sjv_temp20, &sjv_temp20);
    sjv_temp19->count = 10;
    sjv_temp19->data = sjv_temp20;
    sjv_temp19->data->_refCount++;
    sjf_string(sjv_temp19, &sjv_temp19);
    sjf_anon1_write(dotTemp31, sjv_temp19);
    i = 0;
    dotTemp32 = _parent->children;
    dotTemp33 = dotTemp32->size;
    loopEnd3 = dotTemp33;
    while (i < loopEnd3) {
        sji_element* child;
        sjs_array_sji_element* dotTemp34;
        sji_element* result25;

        dotTemp34 = _parent->children;
        result25 = 0;
        sjf_array_sji_element_getAt(dotTemp34, i, &result25);
        child = result25;
        child->_refCount++;
        child->render(child->_parent, surface);
        i++;

        result25->_refCount--;
        if (result25->_refCount <= 0) {
            sji_element_destroy(result25);
            free(result25);
        }
    }

    sjv_temp19->_refCount--;
    if (sjv_temp19->_refCount <= 0) {
        sjf_string_destroy(sjv_temp19);
        free(sjv_temp19);
    }
    sjv_temp20->_refCount--;
    if (sjv_temp20->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp20);
        free(sjv_temp20);
    }
}

void sjf_element_setRect(sjs_element* _parent, sjs_rect* rect_) {
    sjs_anon1* dotTemp26;
    sjs_array_sji_element* dotTemp27;
    int32_t dotTemp28;
    int32_t i;
    int32_t loopEnd2;
    sjs_string* sjv_temp17;
    sjs_array_char* sjv_temp18;
    sjs_global* tempParent6;

    tempParent6 = _parent->_parent;
    dotTemp26 = tempParent6->console;
    sjv_temp17 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp17->_parent = _parent->_parent;
    sjv_temp17->_refCount = 1;
    sjv_temp18 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp18->_refCount = 1;
    sjv_temp18->size = 12;
    sjv_temp18->data = (uintptr_t)sjg_string9;
    sjv_temp18->_isGlobal = false;
    sjf_array_char(sjv_temp18, &sjv_temp18);
    sjv_temp17->count = 11;
    sjv_temp17->data = sjv_temp18;
    sjv_temp17->data->_refCount++;
    sjf_string(sjv_temp17, &sjv_temp17);
    sjf_anon1_write(dotTemp26, sjv_temp17);
    _parent->rect->_refCount--;
    if (_parent->rect->_refCount <= 0) {
        sjf_rect_destroy(_parent->rect);
        free(_parent->rect);
    }

    _parent->rect = rect_;
    _parent->rect->_refCount++;
    i = 0;
    dotTemp27 = _parent->children;
    dotTemp28 = dotTemp27->size;
    loopEnd2 = dotTemp28;
    while (i < loopEnd2) {
        sji_element* child;
        sjs_array_sji_element* dotTemp29;
        sjs_rect* dotTemp30;
        sji_element* result24;

        dotTemp29 = _parent->children;
        result24 = 0;
        sjf_array_sji_element_getAt(dotTemp29, i, &result24);
        child = result24;
        child->_refCount++;
        dotTemp30 = _parent->rect;
        child->setRect(child->_parent, dotTemp30);
        i++;

        result24->_refCount--;
        if (result24->_refCount <= 0) {
            sji_element_destroy(result24);
            free(result24);
        }
    }

    sjv_temp17->_refCount--;
    if (sjv_temp17->_refCount <= 0) {
        sjf_string_destroy(sjv_temp17);
        free(sjv_temp17);
    }
    sjv_temp18->_refCount--;
    if (sjv_temp18->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp18);
        free(sjv_temp18);
    }
}

void sjf_global_destroy(sjs_global* _this) {
}

void sjf_htmlCanvas2d(sjs_htmlCanvas2d* _this, sjs_htmlCanvas2d** _return) {
    
		EM_ASM({
			var canvas = document.getElementById("canvas");
			var ctx = canvas.getContext('2d');
			window[UTF8ToString($0)] = ctx;
		}, _this->ctxVarName->data);
	;
    _this->_refCount++;

    *_return = _this;
}

sjs_object* sjf_htmlCanvas2d_asInterface(sjs_htmlCanvas2d* _this, int typeId) {
    switch (typeId) {
        case sji_surface_typeId: return (sjs_object*)sjf_htmlCanvas2d_as_sji_surface(_this);
    }

    return 0;
}

sji_surface* sjf_htmlCanvas2d_as_sji_surface(sjs_htmlCanvas2d* _this) {
    sji_surface* _interface = (sji_surface*)malloc(sizeof(sji_surface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(sjs_object*))sjf_htmlCanvas2d_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_htmlCanvas2d_asInterface;
    _interface->fillRect = (void(*)(sjs_object*,sjs_rect*,sjs_color*))sjf_htmlCanvas2d_fillRect;
    return _interface;
}

void sjf_htmlCanvas2d_destroy(sjs_htmlCanvas2d* _this) {
    sjf_string_destroy(_this->ctxVarName);
}

void sjf_htmlCanvas2d_fillRect(sjs_htmlCanvas2d* _parent, sjs_rect* rect, sjs_color* color) {
    sjs_string* colorText;
    sjs_anon1* dotTemp1;
    sjs_string* result1;
    sjs_string* sjv_temp6;
    sjs_array_char* sjv_temp7;
    sjs_global* tempParent1;

    tempParent1 = _parent->_parent;
    dotTemp1 = tempParent1->console;
    sjv_temp6 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp6->_parent = _parent->_parent;
    sjv_temp6->_refCount = 1;
    sjv_temp7 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp7->_refCount = 1;
    sjv_temp7->size = 9;
    sjv_temp7->data = (uintptr_t)sjg_string2;
    sjv_temp7->_isGlobal = false;
    sjf_array_char(sjv_temp7, &sjv_temp7);
    sjv_temp6->count = 8;
    sjv_temp6->data = sjv_temp7;
    sjv_temp6->data->_refCount++;
    sjf_string(sjv_temp6, &sjv_temp6);
    sjf_anon1_write(dotTemp1, sjv_temp6);
    result1 = 0;
    sjf_color_asString(color, &result1);
    colorText = result1;
    colorText->_refCount++;
    
			EM_ASM_({
			debugger;
				var ctx = window[UTF8ToString($0)];
				ctx.fillStyle = UTF8ToString($5);
				ctx.fillRect($1, $2, $3, $4);
			}, _parent->ctxVarName->data, rect->x, rect->y, rect->w, rect->h, colorText->data);
		;

    colorText->_refCount--;
    if (colorText->_refCount <= 0) {
        sjf_string_destroy(colorText);
        free(colorText);
    }
    result1->_refCount--;
    if (result1->_refCount <= 0) {
        sjf_string_destroy(result1);
        free(result1);
    }
    sjv_temp6->_refCount--;
    if (sjv_temp6->_refCount <= 0) {
        sjf_string_destroy(sjv_temp6);
        free(sjv_temp6);
    }
    sjv_temp7->_refCount--;
    if (sjv_temp7->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp7);
        free(sjv_temp7);
    }
}

void sjf_mainLoop(sjs_global* _parent) {
    sjs_anon1* dotTemp40;
    sji_element* dotTemp41;
    sji_element* dotTemp43;
    bool result31;
    bool result32;
    sjs_string* sjv_temp36;
    sjs_array_char* sjv_temp37;

    dotTemp40 = _parent->console;
    sjv_temp36 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp36->_parent = _parent;
    sjv_temp36->_refCount = 1;
    sjv_temp37 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp37->_refCount = 1;
    sjv_temp37->size = 13;
    sjv_temp37->data = (uintptr_t)sjg_string11;
    sjv_temp37->_isGlobal = false;
    sjf_array_char(sjv_temp37, &sjv_temp37);
    sjv_temp36->count = 12;
    sjv_temp36->data = sjv_temp37;
    sjv_temp36->data->_refCount++;
    sjf_string(sjv_temp36, &sjv_temp36);
    sjf_anon1_write(dotTemp40, sjv_temp36);
    dotTemp41 = _parent->root;
    result31 = !(dotTemp41 == 0);
    if (result31) {
        sji_element* dotTemp42;
        sjs_rect* sjv_temp38;

        dotTemp42 = _parent->root;
        sjv_temp38 = (sjs_rect*)malloc(sizeof(sjs_rect));
        sjv_temp38->_refCount = 1;
        sjv_temp38->x = 0;
        sjv_temp38->y = 0;
        sjv_temp38->w = 100;
        sjv_temp38->h = 100;
        sjf_rect(sjv_temp38, &sjv_temp38);
        dotTemp42->setRect(dotTemp42->_parent, sjv_temp38);

        sjv_temp38->_refCount--;
        if (sjv_temp38->_refCount <= 0) {
            sjf_rect_destroy(sjv_temp38);
            free(sjv_temp38);
        }
    }

    dotTemp43 = _parent->root;
    result32 = !(dotTemp43 == 0);
    if (result32) {
        sji_element* dotTemp44;
        sji_surface* dotTemp45;

        dotTemp44 = _parent->root;
        dotTemp45 = _parent->rootCanvas;
        dotTemp44->render(dotTemp44->_parent, dotTemp45);
    }

    sjv_temp36->_refCount--;
    if (sjv_temp36->_refCount <= 0) {
        sjf_string_destroy(sjv_temp36);
        free(sjv_temp36);
    }
    sjv_temp37->_refCount--;
    if (sjv_temp37->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp37);
        free(sjv_temp37);
    }
}

void sjf_onClick(sjs_global* _parent, double timestemp, int32_t x, int32_t y) {
    sjs_anon1* dotTemp25;
    sjs_string* sjv_temp15;
    sjs_array_char* sjv_temp16;

    dotTemp25 = _parent->console;
    sjv_temp15 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp15->_parent = _parent;
    sjv_temp15->_refCount = 1;
    sjv_temp16 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp16->_refCount = 1;
    sjv_temp16->size = 6;
    sjv_temp16->data = (uintptr_t)sjg_string4;
    sjv_temp16->_isGlobal = false;
    sjf_array_char(sjv_temp16, &sjv_temp16);
    sjv_temp15->count = 5;
    sjv_temp15->data = sjv_temp16;
    sjv_temp15->data->_refCount++;
    sjf_string(sjv_temp15, &sjv_temp15);
    sjf_anon1_write(dotTemp25, sjv_temp15);

    sjv_temp15->_refCount--;
    if (sjv_temp15->_refCount <= 0) {
        sjf_string_destroy(sjv_temp15);
        free(sjv_temp15);
    }
    sjv_temp16->_refCount--;
    if (sjv_temp16->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp16);
        free(sjv_temp16);
    }
}

void sjf_rect(sjs_rect* _this, sjs_rect** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_rect_destroy(sjs_rect* _this) {
}

void sjf_string(sjs_string* _this, sjs_string** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t dotTemp2;
    bool result3;

    dotTemp2 = item->count;
    result3 = dotTemp2 > 0;
    if (result3) {
        int32_t dotTemp10;
        sjs_array_char* dotTemp15;
        int32_t dotTemp16;
        int32_t dotTemp3;
        int32_t dotTemp4;
        sjs_array_char* dotTemp5;
        int32_t dotTemp6;
        int32_t i;
        int32_t loopEnd1;
        char result13;
        int32_t result4;
        int32_t result5;
        bool result6;

        dotTemp3 = _parent->count;
        dotTemp4 = item->count;
        result4 = dotTemp3 + dotTemp4;
        result5 = result4 + 1;
        dotTemp5 = _parent->data;
        dotTemp6 = dotTemp5->size;
        result6 = result5 > dotTemp6;
        if (result6) {
            sjs_array_char* dotTemp7;
            int32_t dotTemp8;
            int32_t dotTemp9;
            sjs_array_char* result7;
            int32_t result8;
            int32_t result9;

            dotTemp7 = _parent->data;
            result7 = 0;
            dotTemp8 = _parent->count;
            dotTemp9 = item->count;
            result8 = dotTemp8 + dotTemp9;
            result9 = result8 + 1;
            sjf_array_char_grow(dotTemp7, result9, &result7);

            result7->_refCount--;
            if (result7->_refCount <= 0) {
                sjf_array_char_destroy(result7);
                free(result7);
            }
        }

        i = 0;
        dotTemp10 = item->count;
        loopEnd1 = dotTemp10;
        while (i < loopEnd1) {
            sjs_array_char* dotTemp11;
            int32_t dotTemp12;
            int32_t dotTemp14;
            char result10;
            int32_t result12;

            dotTemp11 = _parent->data;
            dotTemp12 = _parent->count;
            result10 = 0;
            sjf_string_getAt(item, i, &result10);
            sjf_array_char_setAt(dotTemp11, dotTemp12, result10);
            dotTemp14 = _parent->count;
            result12 = dotTemp14 + 1;
            _parent->count = result12;
            i++;
        }

        dotTemp15 = _parent->data;
        dotTemp16 = _parent->count;
        result13 = (char)0;
        sjf_array_char_setAt(dotTemp15, dotTemp16, result13);
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
    sjs_array_char* dotTemp13;
    char result11;

    dotTemp13 = _parent->data;
    result11 = 0;
    sjf_array_char_getAt(dotTemp13, index, &result11);

    *_return = result11;
}

void sji_element_destroy(sji_element* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

void sji_surface_destroy(sji_surface* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main() {
    global._refCount = 1;
    sjs_global* _this = &global;
    sjs_anon5* dotTemp39;
    sjs_anon2* parse;
    sjs_anon3* random;
    sji_surface* result23;
    uintptr_t result26;
    sjs_string* result28;
    sji_element* result29;
    sji_element* result30;
    sjs_array_sji_element* sjv_array1;
    sjs_anon5* sjv_temp1;
    sjs_htmlCanvas2d* sjv_temp12;
    sjs_string* sjv_temp13;
    sjs_array_char* sjv_temp14;
    sjs_anon4* sjv_temp2;
    sjs_element* sjv_temp21;
    sjs_array_sji_element* sjv_temp22;
    sjs_anon3* sjv_temp3;
    sjs_button* sjv_temp30;
    sjs_string* sjv_temp31;
    sjs_array_char* sjv_temp32;
    sjs_rect* sjv_temp33;
    sjs_rect* sjv_temp34;
    sjs_anon2* sjv_temp4;
    sjs_anon1* sjv_temp5;

    sjv_temp1 = (sjs_anon5*)malloc(sizeof(sjs_anon5));
    sjv_temp1->_parent = _this;
    sjv_temp1->_refCount = 1;
    sjf_anon5(sjv_temp1, &sjv_temp1);
    _this->style = sjv_temp1;
    _this->style->_refCount++;
    sjv_temp2 = (sjs_anon4*)malloc(sizeof(sjs_anon4));
    sjv_temp2->_parent = _this;
    sjv_temp2->_refCount = 1;
    sjf_anon4(sjv_temp2, &sjv_temp2);
    _this->convert = sjv_temp2;
    _this->convert->_refCount++;
    sjv_temp3 = &sjd_temp1;
    sjv_temp3->_refCount = 1;
    sjf_anon3(sjv_temp3, &sjv_temp3);
    random = sjv_temp3;
    random->_refCount++;
    sjv_temp4 = &sjd_temp2;
    sjv_temp4->_refCount = 1;
    sjf_anon2(sjv_temp4, &sjv_temp4);
    parse = sjv_temp4;
    parse->_refCount++;
    sjv_temp5 = (sjs_anon1*)malloc(sizeof(sjs_anon1));
    sjv_temp5->_refCount = 1;
    sjf_anon1(sjv_temp5, &sjv_temp5);
    _this->console = sjv_temp5;
    _this->console->_refCount++;
    if (_this->root != 0) {
        _this->root->_refCount--;
        if (_this->root->_refCount <= 0) {
            sji_element_destroy(_this->root);
            free(_this->root);
        }
    }

    _this->root = 0;
    if (_this->root != 0) {
        _this->root->_refCount++;
    }

    sjv_temp12 = &sjd_temp3;
    sjv_temp12->_parent = _this;
    sjv_temp12->_refCount = 1;
    sjv_temp13 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp13->_parent = sjv_temp12->_parent;
    sjv_temp13->_refCount = 1;
    sjv_temp14 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp14->_refCount = 1;
    sjv_temp14->size = 6;
    sjv_temp14->data = (uintptr_t)sjg_string1;
    sjv_temp14->_isGlobal = false;
    sjf_array_char(sjv_temp14, &sjv_temp14);
    sjv_temp13->count = 5;
    sjv_temp13->data = sjv_temp14;
    sjv_temp13->data->_refCount++;
    sjf_string(sjv_temp13, &sjv_temp13);
    sjv_temp12->ctxVarName = sjv_temp13;
    sjv_temp12->ctxVarName->_refCount++;
    sjf_htmlCanvas2d(sjv_temp12, &sjv_temp12);
    result23 = sjf_htmlCanvas2d_as_sji_surface(sjv_temp12);
    _this->rootCanvas = result23;
    _this->rootCanvas->_refCount++;
    result23->_refCount--;
    if (result23->_refCount <= 0) {
        sji_surface_destroy(result23);
        free(result23);
    }

    
	emscripten_set_click_callback(0, &global, false, em_onClick);
;
    sjv_temp21 = &sjd_temp4;
    sjv_temp21->_parent = _this;
    sjv_temp21->_refCount = 1;
    sjv_temp22 = &sjd_temp5;
    sjv_temp22->_refCount = 1;
    result26 = (uintptr_t)0;
    sjv_temp22->size = 1;
    sjv_temp22->data = result26;
    sjv_temp22->_isGlobal = false;
    sjf_array_sji_element(sjv_temp22, &sjv_temp22);
    sjv_array1 = sjv_temp22;
    sjv_array1->_refCount++;
    sjv_temp30 = &sjd_temp7;
    sjv_temp30->_parent = _this;
    sjv_temp30->_refCount = 1;
    sjv_temp31 = (sjs_string*)malloc(sizeof(sjs_string));
    sjv_temp31->_parent = sjv_temp30->_parent;
    sjv_temp31->_refCount = 1;
    sjv_temp32 = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    sjv_temp32->_refCount = 1;
    sjv_temp32->size = 1;
    sjv_temp32->data = (uintptr_t)sjg_string5;
    sjv_temp32->_isGlobal = false;
    sjf_array_char(sjv_temp32, &sjv_temp32);
    sjv_temp31->count = 0;
    sjv_temp31->data = sjv_temp32;
    sjv_temp31->data->_refCount++;
    sjf_string(sjv_temp31, &sjv_temp31);
    dotTemp39 = sjv_temp30->_parent->style;
    result28 = 0;
    sjf_anon5_getFont(dotTemp39, 0, &result28);
    sjv_temp33 = (sjs_rect*)malloc(sizeof(sjs_rect));
    sjv_temp33->_refCount = 1;
    sjv_temp33->x = 0;
    sjv_temp33->y = 0;
    sjv_temp33->w = 0;
    sjv_temp33->h = 0;
    sjf_rect(sjv_temp33, &sjv_temp33);
    sjv_temp30->text = sjv_temp31;
    sjv_temp30->text->_refCount++;
    sjv_temp30->font = result28;
    sjv_temp30->font->_refCount++;
    sjv_temp30->rect = sjv_temp33;
    sjv_temp30->rect->_refCount++;
    sjf_button(sjv_temp30, &sjv_temp30);
    result29 = sjf_button_as_sji_element(sjv_temp30);
    sjf_array_sji_element_setAt(sjv_array1, 0, result29);
    sjv_temp34 = (sjs_rect*)malloc(sizeof(sjs_rect));
    sjv_temp34->_refCount = 1;
    sjv_temp34->x = 0;
    sjv_temp34->y = 0;
    sjv_temp34->w = 0;
    sjv_temp34->h = 0;
    sjf_rect(sjv_temp34, &sjv_temp34);
    sjv_temp21->children = sjv_array1;
    sjv_temp21->children->_refCount++;
    sjv_temp21->rect = sjv_temp34;
    sjv_temp21->rect->_refCount++;
    sjf_element(sjv_temp21, &sjv_temp21);
    result30 = sjf_element_as_sji_element(sjv_temp21);
    if (_this->root != 0) {
        _this->root->_refCount--;
        if (_this->root->_refCount <= 0) {
            sji_element_destroy(_this->root);
            free(_this->root);
        }
    }

    _this->root = result30;
    if (_this->root != 0) {
        _this->root->_refCount++;
    }

    result28->_refCount--;
    if (result28->_refCount <= 0) {
        sjf_string_destroy(result28);
        free(result28);
    }
    sjv_temp1->_refCount--;
    if (sjv_temp1->_refCount <= 0) {
        sjf_anon5_destroy(sjv_temp1);
        free(sjv_temp1);
    }
    sjv_temp13->_refCount--;
    if (sjv_temp13->_refCount <= 0) {
        sjf_string_destroy(sjv_temp13);
        free(sjv_temp13);
    }
    sjv_temp14->_refCount--;
    if (sjv_temp14->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp14);
        free(sjv_temp14);
    }
    sjv_temp2->_refCount--;
    if (sjv_temp2->_refCount <= 0) {
        sjf_anon4_destroy(sjv_temp2);
        free(sjv_temp2);
    }
    sjv_temp31->_refCount--;
    if (sjv_temp31->_refCount <= 0) {
        sjf_string_destroy(sjv_temp31);
        free(sjv_temp31);
    }
    sjv_temp32->_refCount--;
    if (sjv_temp32->_refCount <= 0) {
        sjf_array_char_destroy(sjv_temp32);
        free(sjv_temp32);
    }
    sjv_temp33->_refCount--;
    if (sjv_temp33->_refCount <= 0) {
        sjf_rect_destroy(sjv_temp33);
        free(sjv_temp33);
    }
    sjv_temp34->_refCount--;
    if (sjv_temp34->_refCount <= 0) {
        sjf_rect_destroy(sjv_temp34);
        free(sjv_temp34);
    }
    sjv_temp5->_refCount--;
    if (sjv_temp5->_refCount <= 0) {
        sjf_anon1_destroy(sjv_temp5);
        free(sjv_temp5);
    }
    emscripten_set_main_loop_arg((em_arg_callback_func)sjf_mainLoop, &global, 0, 0);
    return 0;
}
void main_destroy() {
    sjf_anon3_destroy(&sjd_temp1);
    sjf_anon2_destroy(&sjd_temp2);
    sjf_htmlCanvas2d_destroy(&sjd_temp3);
    sjf_element_destroy(&sjd_temp4);
    sjf_array_sji_element_destroy(&sjd_temp5);
    sjf_button_destroy(&sjd_temp7);
    sjf_global_destroy(&global);
}
