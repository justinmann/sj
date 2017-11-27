#ifdef __MSVC__
#include <SDL.h>
#endif
#ifdef __APPLE__
#include <SDL2/SDL.h>
#endif
#ifdef __APPLE__
#include <SDL2_ttf/SDL_ttf.h>
#endif
#ifdef __MSVC__
#include <SDL_ttf.h>
#endif
#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#ifdef EMSCRIPTEN
#include <emscripten/html5.h>
#endif
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

const char* sjg_string11 = "fillRect";
const char* sjg_string12 = "#";
const char* sjg_string15 = "setRect - 2";
const char* sjg_string17 = "render - 2";
const char* sjg_string19 = "button - render - 1";
const char* sjg_string2 = "sjCTX";
const char* sjg_string20 = "button - render - 2";
const char* sjg_string3 = "click";
const char* sjg_string6 = "";
const char* sjg_string7 = "48px serif";
const char* sjg_string8 = "48px serif";
const char* sjg_string9 = "mainLoop - 1";

#define sjs_object_typeId 1
#define sjs_anon5_typeId 2
#define sjs_anon5_heap_typeId 3
#define sjs_anon4_typeId 4
#define sjs_anon4_heap_typeId 5
#define sjs_anon3_typeId 6
#define sjs_anon3_heap_typeId 7
#define sjs_anon2_typeId 8
#define sjs_anon2_heap_typeId 9
#define sjs_anon1_typeId 10
#define sjs_anon1_heap_typeId 11
#define sjs_array_char_typeId 12
#define sjs_array_char_heap_typeId 13
#define sjs_string_typeId 14
#define sjs_string_heap_typeId 15
#define sjs_htmlCanvas2d_typeId 16
#define sji_surface_typeId 17
#define sjs_htmlCanvas2d_heap_typeId 18
#define sjs_array_heap_element_typeId 19
#define sjs_array_heap_element_heap_typeId 20
#define sjs_rect_typeId 21
#define sjs_rect_heap_typeId 22
#define sjs_element_typeId 23
#define sji_element_typeId 24
#define sjs_element_heap_typeId 25
#define sjs_button_typeId 26
#define sjs_color_typeId 27
#define sjs_color_heap_typeId 28
#define sjs_button_heap_typeId 29

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_anon5 sjs_anon5;
typedef struct td_sjs_anon5_heap sjs_anon5_heap;
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
typedef struct td_sjs_htmlCanvas2d sjs_htmlCanvas2d;
typedef struct td_sji_surface sji_surface;
typedef struct td_sjs_htmlCanvas2d_heap sjs_htmlCanvas2d_heap;
typedef struct td_sjs_array_heap_element sjs_array_heap_element;
typedef struct td_sjs_array_heap_element_heap sjs_array_heap_element_heap;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_rect_heap sjs_rect_heap;
typedef struct td_sjs_element sjs_element;
typedef struct td_sji_element sji_element;
typedef struct td_sjs_element_heap sjs_element_heap;
typedef struct td_sjs_button sjs_button;
typedef struct td_sjs_color sjs_color;
typedef struct td_sjs_color_heap sjs_color_heap;
typedef struct td_sjs_button_heap sjs_button_heap;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_anon5 {
    int structsNeedAValue;
};

struct td_sjs_anon5_heap {
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

struct td_sjs_htmlCanvas2d {
    sjs_string ctxVarName;
};

struct td_sji_surface {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*fillRect)(void* _parent, sjs_rect* rect, sjs_color* color);
};

struct td_sjs_htmlCanvas2d_heap {
    int _refCount;
    sjs_string ctxVarName;
};

struct td_sjs_array_heap_element {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_heap_element_heap {
    int _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_rect {
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct td_sjs_rect_heap {
    int _refCount;
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct td_sjs_element {
    sjs_array_heap_element children;
    sjs_rect rect;
};

struct td_sji_element {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*setRect)(void* _parent, sjs_rect* rect);
    void (*render)(void* _parent, sji_surface* surface);
};

struct td_sjs_element_heap {
    int _refCount;
    sjs_array_heap_element children;
    sjs_rect rect;
};

struct td_sjs_button {
    sjs_string text;
    sjs_string font;
    sjs_rect rect;
};

struct td_sjs_color {
    int32_t r;
    int32_t g;
    int32_t b;
    int32_t a;
};

struct td_sjs_color_heap {
    int _refCount;
    int32_t r;
    int32_t g;
    int32_t b;
    int32_t a;
};

struct td_sjs_button_heap {
    int _refCount;
    sjs_string text;
    sjs_string font;
    sjs_rect rect;
};


	
	
	
	
	
	
	
	

#ifdef EMSCRIPTEN
	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
#endif	
	SDL_Texture* renderText(const char* message, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);

sjs_htmlCanvas2d_heap* sjt_cast1;
sjs_element_heap* sjt_cast5;
int32_t sjt_cast6;
sjs_button_heap* sjt_cast7;
sjs_anon5* sjt_dot35;
int32_t sjt_functionParam30;
sji_element* sjt_functionParam31;
int32_t sjt_functionParam36;
sji_element* sjt_value1;
sjs_anon1 sjv_console;
sjs_anon4 sjv_convert;
sjs_anon2 sjv_parse;
sjs_anon3 sjv_random;
sji_element* sjv_root;
sji_surface* sjv_rootCanvas;
sjs_anon5 sjv_style;

void sjf_anon1(sjs_anon1* _this);
void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* to);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_heap(sjs_anon1_heap* _this);
void sjf_anon1_write(sjs_anon1* _parent, sjs_string* data);
void sjf_anon2(sjs_anon2* _this);
void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* to);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon2_heap(sjs_anon2_heap* _this);
void sjf_anon3(sjs_anon3* _this);
void sjf_anon3_copy(sjs_anon3* _this, sjs_anon3* to);
void sjf_anon3_destroy(sjs_anon3* _this);
void sjf_anon3_heap(sjs_anon3_heap* _this);
void sjf_anon4(sjs_anon4* _this);
void sjf_anon4_copy(sjs_anon4* _this, sjs_anon4* to);
void sjf_anon4_destroy(sjs_anon4* _this);
void sjf_anon4_heap(sjs_anon4_heap* _this);
void sjf_anon4_i32toString(sjs_anon4* _parent, int32_t val, int32_t base, int32_t minLength, sjs_string* _return);
void sjf_anon4_i32toString_heap(sjs_anon4* _parent, int32_t val, int32_t base, int32_t minLength, sjs_string_heap** _return);
void sjf_anon5(sjs_anon5* _this);
void sjf_anon5_copy(sjs_anon5* _this, sjs_anon5* to);
void sjf_anon5_destroy(sjs_anon5* _this);
void sjf_anon5_getFont(sjs_anon5* _parent, int32_t typeId, sjs_string* _return);
void sjf_anon5_getFont_heap(sjs_anon5* _parent, int32_t typeId, sjs_string_heap** _return);
void sjf_anon5_heap(sjs_anon5_heap* _this);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* to);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t new_size);
void sjf_array_char_heap(sjs_array_char_heap* _this);
void sjf_array_char_setAt(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_heap_element(sjs_array_heap_element* _this);
void sjf_array_heap_element_copy(sjs_array_heap_element* _this, sjs_array_heap_element* to);
void sjf_array_heap_element_destroy(sjs_array_heap_element* _this);
void sjf_array_heap_element_getAt_heap(sjs_array_heap_element* _parent, int32_t index, sji_element** _return);
void sjf_array_heap_element_heap(sjs_array_heap_element_heap* _this);
void sjf_array_heap_element_initAt(sjs_array_heap_element* _parent, int32_t index, sji_element* item);
void sjf_button(sjs_button* _this);
sjs_object* sjf_button_asInterface(sjs_button* _this, int typeId);
sji_element* sjf_button_as_sji_element(sjs_button* _this);
void sjf_button_copy(sjs_button* _this, sjs_button* to);
void sjf_button_destroy(sjs_button* _this);
void sjf_button_heap(sjs_button_heap* _this);
sjs_object* sjf_button_heap_asInterface(sjs_button_heap* _this, int typeId);
sji_element* sjf_button_heap_as_sji_element(sjs_button_heap* _this);
void sjf_button_render(sjs_button* _parent, sji_surface* surface);
void sjf_button_setRect(sjs_button* _parent, sjs_rect* rect_);
void sjf_color(sjs_color* _this);
void sjf_color_asString(sjs_color* _parent, sjs_string** _return);
void sjf_color_copy(sjs_color* _this, sjs_color* to);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color_heap* _this);
void sjf_element(sjs_element* _this);
sjs_object* sjf_element_asInterface(sjs_element* _this, int typeId);
sji_element* sjf_element_as_sji_element(sjs_element* _this);
void sjf_element_copy(sjs_element* _this, sjs_element* to);
void sjf_element_destroy(sjs_element* _this);
void sjf_element_heap(sjs_element_heap* _this);
sjs_object* sjf_element_heap_asInterface(sjs_element_heap* _this, int typeId);
sji_element* sjf_element_heap_as_sji_element(sjs_element_heap* _this);
void sjf_element_render(sjs_element* _parent, sji_surface* surface);
void sjf_element_setRect(sjs_element* _parent, sjs_rect* rect_);
void sjf_htmlCanvas2d(sjs_htmlCanvas2d* _this);
sjs_object* sjf_htmlCanvas2d_asInterface(sjs_htmlCanvas2d* _this, int typeId);
sji_surface* sjf_htmlCanvas2d_as_sji_surface(sjs_htmlCanvas2d* _this);
void sjf_htmlCanvas2d_copy(sjs_htmlCanvas2d* _this, sjs_htmlCanvas2d* to);
void sjf_htmlCanvas2d_destroy(sjs_htmlCanvas2d* _this);
void sjf_htmlCanvas2d_fillRect(sjs_htmlCanvas2d* _parent, sjs_rect* rect, sjs_color* color);
void sjf_htmlCanvas2d_heap(sjs_htmlCanvas2d_heap* _this);
sjs_object* sjf_htmlCanvas2d_heap_asInterface(sjs_htmlCanvas2d_heap* _this, int typeId);
sji_surface* sjf_htmlCanvas2d_heap_as_sji_surface(sjs_htmlCanvas2d_heap* _this);
void sjf_mainLoop(void);
void sjf_onClick(double timestemp, int32_t x, int32_t y);
void sjf_rect(sjs_rect* _this);
void sjf_rect_copy(sjs_rect* _this, sjs_rect* to);
void sjf_rect_destroy(sjs_rect* _this);
void sjf_rect_heap(sjs_rect_heap* _this);
void sjf_runLoop(void);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* to);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_heap(sjs_string_heap* _this);
void sji_element_destroy(sji_element* _this);
void sji_surface_destroy(sji_surface* _this);
void main_destroy(void);


#ifdef EMSCRIPTEN
	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
		sjf_onClick(&global, mouseEvent->timestamp, mouseEvent->targetX, mouseEvent->targetY);
		return true;
	}
#endif	

SDL_Texture* renderText(const char* message, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer) {
    //Open the font
    TTF_Font *font = TTF_OpenFont(fontFile, fontSize);
    if (font == 0) {
        printf("TTF_OpenFont Error: %s\n", SDL_GetError());
        return 0;
    }
    //We need to first render to a surface as that's what TTF_RenderText returns, then
    //load that surface into a texture
    SDL_Surface *surf = TTF_RenderText_Blended(font, message, color);
    if (surf == 0) {
        TTF_CloseFont(font);
        printf("TTF_RenderText Error: %s\n", SDL_GetError());
        return 0;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == 0) {
        printf("CreateTexture Error: %s\n", SDL_GetError());
    }
    //Clean up the surface and font
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}


void sjf_anon1(sjs_anon1* _this) {
}

void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* to) {
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1_heap* _this) {
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

void sjf_anon3(sjs_anon3* _this) {
}

void sjf_anon3_copy(sjs_anon3* _this, sjs_anon3* to) {
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

void sjf_anon3_heap(sjs_anon3_heap* _this) {
}

void sjf_anon4(sjs_anon4* _this) {
}

void sjf_anon4_copy(sjs_anon4* _this, sjs_anon4* to) {
}

void sjf_anon4_destroy(sjs_anon4* _this) {
}

void sjf_anon4_heap(sjs_anon4_heap* _this) {
}

void sjf_anon4_i32toString(sjs_anon4* _parent, int32_t val, int32_t base, int32_t minLength, sjs_string* _return) {
    int32_t sjt_cast3;
    int32_t sjt_math11;
    int32_t sjt_math12;
    int32_t sjv_count;
    uintptr_t sjv_data;

    sjv_count = 0;
    sjt_cast3 = 0;
    sjv_data = (uintptr_t)sjt_cast3;
    
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
			sjv_count = 30 - i;

			if (sjv_count < minLength) {				
			}

			sjv_data = (uintptr_t)malloc(sizeof(char) * (sjv_count + 1));
			memcpy((void*)sjv_data, &buf[i+1], sjv_count + 1);
			printf("%s\n", (char*)sjv_data);
		;
    _return->count = sjv_count;
    sjt_math11 = sjv_count;
    sjt_math12 = 1;
    _return->data.size = sjt_math11 + sjt_math12;
    _return->data.data = sjv_data;
    _return->data._isGlobal = false;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_anon4_i32toString_heap(sjs_anon4* _parent, int32_t val, int32_t base, int32_t minLength, sjs_string_heap** _return) {
    int32_t sjt_cast4;
    int32_t sjt_math13;
    int32_t sjt_math14;
    int32_t sjv_count;
    uintptr_t sjv_data;

    sjv_count = 0;
    sjt_cast4 = 0;
    sjv_data = (uintptr_t)sjt_cast4;
    
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
			sjv_count = 30 - i;

			if (sjv_count < minLength) {				
			}

			sjv_data = (uintptr_t)malloc(sizeof(char) * (sjv_count + 1));
			memcpy((void*)sjv_data, &buf[i+1], sjv_count + 1);
			printf("%s\n", (char*)sjv_data);
		;
    (*_return) = (sjs_string_heap*)malloc(sizeof(sjs_string_heap));
    (*_return)->_refCount = 1;
    (*_return)->count = sjv_count;
    sjt_math13 = sjv_count;
    sjt_math14 = 1;
    (*_return)->data.size = sjt_math13 + sjt_math14;
    (*_return)->data.data = sjv_data;
    (*_return)->data._isGlobal = false;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_anon5(sjs_anon5* _this) {
}

void sjf_anon5_copy(sjs_anon5* _this, sjs_anon5* to) {
}

void sjf_anon5_destroy(sjs_anon5* _this) {
}

void sjf_anon5_getFont(sjs_anon5* _parent, int32_t typeId, sjs_string* _return) {
    _return->count = 10;
    _return->data.size = 11;
    _return->data.data = (uintptr_t)sjg_string7;
    _return->data._isGlobal = false;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_anon5_getFont_heap(sjs_anon5* _parent, int32_t typeId, sjs_string_heap** _return) {
    (*_return) = (sjs_string_heap*)malloc(sizeof(sjs_string_heap));
    (*_return)->_refCount = 1;
    (*_return)->count = 10;
    (*_return)->data.size = 11;
    (*_return)->data.data = (uintptr_t)sjg_string8;
    (*_return)->data._isGlobal = false;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_anon5_heap(sjs_anon5_heap* _this) {
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

void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return) {
    
		if (index >= _parent->size || index < 0) {
			printf("getAt: out of bounds\n");
			exit(-1);
		}

		char* p = (char*)_parent->data;
		(*_return) = p[index];
;		
	;
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t new_size) {
    
		if (_parent->size != new_size) {
			if (new_size < _parent->size) {
				printf("grow: new _parent->size smaller than old _parent->size %d:%d\n", new_size, _parent->size);
				exit(-1);
			}
			
			if (_parent->_isGlobal) {
				_parent->_isGlobal = false;
				char* p = (char*)_parent->data;
				_parent->data = (uintptr_t)calloc(new_size * sizeof(char), 1);
				if (!_parent->data) {
					printf("grow: out of memory\n");
					exit(-1);				
				}
				memcpy((void*)_parent->data, p, _parent->size * sizeof(char));
			} else {
				_parent->data = (uintptr_t)realloc((void*)_parent->data, new_size * sizeof(char));
				if (!_parent->data) {
					printf("grow: out of memory\n");
					exit(-1);				
				}
				memset((char*)_parent->data + _parent->size, 0, (new_size - _parent->size) * sizeof(char));
			}
			_parent->size = new_size;
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

void sjf_array_char_setAt(sjs_array_char* _parent, int32_t index, char item) {
    
		if (index >= _parent->size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, _parent->size);
			exit(-1);
		}

		char* p = (char*)_parent->data;
		;
		p[index] = item;
;
	;
}

void sjf_array_heap_element(sjs_array_heap_element* _this) {
    
		

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
}

void sjf_array_heap_element_copy(sjs_array_heap_element* _this, sjs_array_heap_element* to) {
    _this->size = to->size;
    _this->data = to->data;
    _this->_isGlobal = to->_isGlobal;
}

void sjf_array_heap_element_destroy(sjs_array_heap_element* _this) {
    
	if (!_this->_isGlobal && _this->data) {
		free((sji_element**)_this->data);
		_this->data = 0;	
	}
;
}

void sjf_array_heap_element_getAt_heap(sjs_array_heap_element* _parent, int32_t index, sji_element** _return) {
    
		if (index >= _parent->size || index < 0) {
			printf("getAt: out of bounds\n");
			exit(-1);
		}

		sji_element** p = (sji_element**)_parent->data;
		(*_return) = p[index];
(*_return)->_refCount++;
;		
	;
}

void sjf_array_heap_element_heap(sjs_array_heap_element_heap* _this) {
    
		

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
}

void sjf_array_heap_element_initAt(sjs_array_heap_element* _parent, int32_t index, sji_element* item) {
    
		if (index >= _parent->size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, _parent->size);
			exit(-1);
		}

		sji_element** p = (sji_element**)_parent->data;
		p[index] = item;
p[index]->_refCount++;
;
	;
}

void sjf_button(sjs_button* _this) {
    sjs_anon5* sjt_dot30;
    int32_t sjt_functionParam32;
    sjs_string void1;

    sjt_dot30 = &sjv_style;
    sjt_functionParam32 = 1;
    sjf_anon5_getFont(sjt_dot30, sjt_functionParam32, &void1);

    sjf_string_destroy(&void1);
}

sjs_object* sjf_button_asInterface(sjs_button* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_button_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_button_as_sji_element(sjs_button* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_button_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_button_asInterface;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_button_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_button_render;

    return _interface;
}

void sjf_button_copy(sjs_button* _this, sjs_button* to) {
    sjf_string_copy(&_this->text, &to->text);
    sjf_string_copy(&_this->font, &to->font);
    sjf_rect_copy(&_this->rect, &to->rect);
}

void sjf_button_destroy(sjs_button* _this) {
}

void sjf_button_heap(sjs_button_heap* _this) {
    sjs_anon5* sjt_dot34;
    int32_t sjt_functionParam35;
    sjs_string void2;

    sjt_dot34 = &sjv_style;
    sjt_functionParam35 = 1;
    sjf_anon5_getFont(sjt_dot34, sjt_functionParam35, &void2);

    sjf_string_destroy(&void2);
}

sjs_object* sjf_button_heap_asInterface(sjs_button_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_button_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_button_heap_as_sji_element(sjs_button_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_button_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_button_heap_asInterface;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_button_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_button_render;

    return _interface;
}

void sjf_button_render(sjs_button* _parent, sji_surface* surface) {
    sjs_rect dotTemp27;
    sjs_string sjt_call10;
    sjs_color sjt_call11;
    sjs_string sjt_call12;
    sjs_anon1* sjt_dot31;
    sji_surface* sjt_dot32;
    sjs_anon1* sjt_dot33;
    sjs_string* sjt_functionParam33;
    sjs_string* sjt_functionParam34;
    sjs_rect* sjt_interfaceParam3;
    sjs_color* sjt_interfaceParam4;

    sjt_dot31 = &sjv_console;
    sjt_call10.count = 19;
    sjt_call10.data.size = 20;
    sjt_call10.data.data = (uintptr_t)sjg_string19;
    sjt_call10.data._isGlobal = false;
    sjf_array_char(&sjt_call10.data);
    sjf_string(&sjt_call10);
    sjt_functionParam33 = &sjt_call10;
    sjf_anon1_write(sjt_dot31, sjt_functionParam33);
    sjt_dot32 = surface;
    dotTemp27 = _parent->rect;
    sjt_interfaceParam3 = &dotTemp27;
    sjt_call11.r = 255;
    sjt_call11.g = 0;
    sjt_call11.b = 0;
    sjt_call11.a = 255;
    sjf_color(&sjt_call11);
    sjt_interfaceParam4 = &sjt_call11;
    sjt_dot32->fillRect((void*)(((char*)sjt_dot32->_parent) + sizeof(int)), sjt_interfaceParam3, sjt_interfaceParam4);
    sjt_dot33 = &sjv_console;
    sjt_call12.count = 19;
    sjt_call12.data.size = 20;
    sjt_call12.data.data = (uintptr_t)sjg_string20;
    sjt_call12.data._isGlobal = false;
    sjf_array_char(&sjt_call12.data);
    sjf_string(&sjt_call12);
    sjt_functionParam34 = &sjt_call12;
    sjf_anon1_write(sjt_dot33, sjt_functionParam34);

    sjf_rect_destroy(&dotTemp27);
    sjf_string_destroy(&sjt_call10);
    sjf_color_destroy(&sjt_call11);
    sjf_string_destroy(&sjt_call12);
}

void sjf_button_setRect(sjs_button* _parent, sjs_rect* rect_) {
    sjf_rect_copy(&_parent->rect, rect_);
}

void sjf_color(sjs_color* _this) {
}

void sjf_color_asString(sjs_color* _parent, sjs_string** _return) {
    int32_t dotTemp16;
    int32_t dotTemp17;
    int32_t dotTemp18;
    int32_t dotTemp19;
    sjs_string sjt_call2;
    sjs_string sjt_call3;
    sjs_string sjt_call4;
    sjs_string sjt_call5;
    sjs_string sjt_call6;
    sjs_anon4* sjt_dot17;
    sjs_anon4* sjt_dot18;
    sjs_anon4* sjt_dot19;
    sjs_anon4* sjt_dot20;
    sjs_string* sjt_dot3;
    sjs_string* sjt_dot4;
    sjs_string* sjt_dot5;
    sjs_string* sjt_dot6;
    int32_t sjt_functionParam10;
    int32_t sjt_functionParam11;
    int32_t sjt_functionParam12;
    sjs_string* sjt_functionParam13;
    int32_t sjt_functionParam14;
    int32_t sjt_functionParam15;
    int32_t sjt_functionParam16;
    sjs_string* sjt_functionParam17;
    int32_t sjt_functionParam18;
    int32_t sjt_functionParam19;
    int32_t sjt_functionParam20;
    sjs_string* sjt_functionParam21;
    int32_t sjt_functionParam22;
    int32_t sjt_functionParam23;
    int32_t sjt_functionParam24;
    sjs_string* sjt_functionParam9;

    sjt_call2.count = 1;
    sjt_call2.data.size = 2;
    sjt_call2.data.data = (uintptr_t)sjg_string12;
    sjt_call2.data._isGlobal = false;
    sjf_array_char(&sjt_call2.data);
    sjf_string(&sjt_call2);
    sjt_dot6 = &sjt_call2;
    sjt_dot17 = &sjv_convert;
    dotTemp16 = _parent->a;
    sjt_functionParam10 = dotTemp16;
    sjt_functionParam11 = 16;
    sjt_functionParam12 = 2;
    sjf_anon4_i32toString(sjt_dot17, sjt_functionParam10, sjt_functionParam11, sjt_functionParam12, &sjt_call3);
    sjt_functionParam9 = &sjt_call3;
    sjf_string_add(sjt_dot6, sjt_functionParam9, &sjt_dot5);
    sjt_dot18 = &sjv_convert;
    dotTemp17 = _parent->r;
    sjt_functionParam14 = dotTemp17;
    sjt_functionParam15 = 16;
    sjt_functionParam16 = 2;
    sjf_anon4_i32toString(sjt_dot18, sjt_functionParam14, sjt_functionParam15, sjt_functionParam16, &sjt_call4);
    sjt_functionParam13 = &sjt_call4;
    sjf_string_add(sjt_dot5, sjt_functionParam13, &sjt_dot4);
    sjt_dot19 = &sjv_convert;
    dotTemp18 = _parent->g;
    sjt_functionParam18 = dotTemp18;
    sjt_functionParam19 = 16;
    sjt_functionParam20 = 2;
    sjf_anon4_i32toString(sjt_dot19, sjt_functionParam18, sjt_functionParam19, sjt_functionParam20, &sjt_call5);
    sjt_functionParam17 = &sjt_call5;
    sjf_string_add(sjt_dot4, sjt_functionParam17, &sjt_dot3);
    sjt_dot20 = &sjv_convert;
    dotTemp19 = _parent->b;
    sjt_functionParam22 = dotTemp19;
    sjt_functionParam23 = 16;
    sjt_functionParam24 = 2;
    sjf_anon4_i32toString(sjt_dot20, sjt_functionParam22, sjt_functionParam23, sjt_functionParam24, &sjt_call6);
    sjt_functionParam21 = &sjt_call6;
    sjf_string_add(sjt_dot3, sjt_functionParam21, &(*_return));

    sjf_string_destroy(&sjt_call2);
    sjf_string_destroy(&sjt_call3);
    sjf_string_destroy(&sjt_call4);
    sjf_string_destroy(&sjt_call5);
    sjf_string_destroy(&sjt_call6);
}

void sjf_color_copy(sjs_color* _this, sjs_color* to) {
    _this->r = to->r;
    _this->g = to->g;
    _this->b = to->b;
    _this->a = to->a;
}

void sjf_color_destroy(sjs_color* _this) {
}

void sjf_color_heap(sjs_color_heap* _this) {
}

void sjf_element(sjs_element* _this) {
}

sjs_object* sjf_element_asInterface(sjs_element* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_element_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_element_as_sji_element(sjs_element* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_element_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_element_asInterface;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_element_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_element_render;

    return _interface;
}

void sjf_element_copy(sjs_element* _this, sjs_element* to) {
    sjf_array_heap_element_copy(&_this->children, &to->children);
    sjf_rect_copy(&_this->rect, &to->rect);
}

void sjf_element_destroy(sjs_element* _this) {
}

void sjf_element_heap(sjs_element_heap* _this) {
}

sjs_object* sjf_element_heap_asInterface(sjs_element_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_element_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_element_heap_as_sji_element(sjs_element_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_element_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_element_heap_asInterface;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_element_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_element_render;

    return _interface;
}

void sjf_element_render(sjs_element* _parent, sji_surface* surface) {
    sjs_array_heap_element dotTemp24;
    int32_t dotTemp25;
    int32_t i;
    sjs_string sjt_call9;
    sjs_anon1* sjt_dot26;
    sjs_array_heap_element* sjt_dot27;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;
    sjs_string* sjt_functionParam28;

    sjt_dot26 = &sjv_console;
    sjt_call9.count = 10;
    sjt_call9.data.size = 11;
    sjt_call9.data.data = (uintptr_t)sjg_string17;
    sjt_call9.data._isGlobal = false;
    sjf_array_char(&sjt_call9.data);
    sjf_string(&sjt_call9);
    sjt_functionParam28 = &sjt_call9;
    sjf_anon1_write(sjt_dot26, sjt_functionParam28);
    sjt_forStart3 = 0;
    i = sjt_forStart3;
    dotTemp24 = _parent->children;
    sjt_dot27 = &dotTemp24;
    dotTemp25 = sjt_dot27->size;
    sjt_forEnd3 = dotTemp25;
    while (i < sjt_forEnd3) {
        sjs_array_heap_element dotTemp26;
        sjs_array_heap_element* sjt_dot28;
        sji_element* sjt_dot29;
        int32_t sjt_functionParam29;
        sji_surface* sjt_interfaceParam2;
        sji_element* sjv_child;

        dotTemp26 = _parent->children;
        sjt_dot28 = &dotTemp26;
        sjt_functionParam29 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot28, sjt_functionParam29, &sjv_child);
        sjt_dot29 = sjv_child;
        sjt_interfaceParam2 = surface;
        sjt_interfaceParam2->_refCount++;
        sjt_dot29->render((void*)(((char*)sjt_dot29->_parent) + sizeof(int)), sjt_interfaceParam2);
        i++;

        sjt_interfaceParam2->_refCount--;
        if (sjt_interfaceParam2->_refCount <= 0) {
            sji_surface_destroy(sjt_interfaceParam2);
        }
        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
        sjf_array_heap_element_destroy(&dotTemp26);
    }

    sjf_array_heap_element_destroy(&dotTemp24);
    sjf_string_destroy(&sjt_call9);
}

void sjf_element_setRect(sjs_element* _parent, sjs_rect* rect_) {
    sjs_array_heap_element dotTemp20;
    int32_t dotTemp21;
    int32_t i;
    sjs_string sjt_call8;
    sjs_anon1* sjt_dot22;
    sjs_array_heap_element* sjt_dot23;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;
    sjs_string* sjt_functionParam26;

    sjt_dot22 = &sjv_console;
    sjt_call8.count = 11;
    sjt_call8.data.size = 12;
    sjt_call8.data.data = (uintptr_t)sjg_string15;
    sjt_call8.data._isGlobal = false;
    sjf_array_char(&sjt_call8.data);
    sjf_string(&sjt_call8);
    sjt_functionParam26 = &sjt_call8;
    sjf_anon1_write(sjt_dot22, sjt_functionParam26);
    sjf_rect_copy(&_parent->rect, rect_);
    sjt_forStart2 = 0;
    i = sjt_forStart2;
    dotTemp20 = _parent->children;
    sjt_dot23 = &dotTemp20;
    dotTemp21 = sjt_dot23->size;
    sjt_forEnd2 = dotTemp21;
    while (i < sjt_forEnd2) {
        sjs_array_heap_element dotTemp22;
        sjs_rect dotTemp23;
        sjs_array_heap_element* sjt_dot24;
        sji_element* sjt_dot25;
        int32_t sjt_functionParam27;
        sjs_rect* sjt_interfaceParam1;
        sji_element* sjv_child;

        dotTemp22 = _parent->children;
        sjt_dot24 = &dotTemp22;
        sjt_functionParam27 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot24, sjt_functionParam27, &sjv_child);
        sjt_dot25 = sjv_child;
        dotTemp23 = _parent->rect;
        sjt_interfaceParam1 = &dotTemp23;
        sjt_dot25->setRect((void*)(((char*)sjt_dot25->_parent) + sizeof(int)), sjt_interfaceParam1);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
        sjf_array_heap_element_destroy(&dotTemp22);
        sjf_rect_destroy(&dotTemp23);
    }

    sjf_array_heap_element_destroy(&dotTemp20);
    sjf_string_destroy(&sjt_call8);
}

void sjf_htmlCanvas2d(sjs_htmlCanvas2d* _this) {
}

sjs_object* sjf_htmlCanvas2d_asInterface(sjs_htmlCanvas2d* _this, int typeId) {
    switch (typeId) {
        case sji_surface_typeId:  {
            return (sjs_object*)sjf_htmlCanvas2d_as_sji_surface(_this);
        }
    }

    return 0;
}

sji_surface* sjf_htmlCanvas2d_as_sji_surface(sjs_htmlCanvas2d* _this) {
    sji_surface* _interface;
    _interface = (sji_surface*)malloc(sizeof(sji_surface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_htmlCanvas2d_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_htmlCanvas2d_asInterface;
    _interface->fillRect = (void(*)(void*,sjs_rect*,sjs_color*))sjf_htmlCanvas2d_fillRect;

    return _interface;
}

void sjf_htmlCanvas2d_copy(sjs_htmlCanvas2d* _this, sjs_htmlCanvas2d* to) {
    sjf_string_copy(&_this->ctxVarName, &to->ctxVarName);
}

void sjf_htmlCanvas2d_destroy(sjs_htmlCanvas2d* _this) {
}

void sjf_htmlCanvas2d_fillRect(sjs_htmlCanvas2d* _parent, sjs_rect* rect, sjs_color* color) {
    sjs_string sjt_call1;
    sjs_anon1* sjt_dot1;
    sjs_color* sjt_dot2;
    sjs_string* sjt_functionParam1;
    sjs_string* sjv_colorText;

    sjt_dot1 = &sjv_console;
    sjt_call1.count = 8;
    sjt_call1.data.size = 9;
    sjt_call1.data.data = (uintptr_t)sjg_string11;
    sjt_call1.data._isGlobal = false;
    sjf_array_char(&sjt_call1.data);
    sjf_string(&sjt_call1);
    sjt_functionParam1 = &sjt_call1;
    sjf_anon1_write(sjt_dot1, sjt_functionParam1);
    sjt_dot2 = color;
    sjf_color_asString(sjt_dot2, &sjv_colorText);

    sjf_string_destroy(&sjt_call1);
}

void sjf_htmlCanvas2d_heap(sjs_htmlCanvas2d_heap* _this) {
}

sjs_object* sjf_htmlCanvas2d_heap_asInterface(sjs_htmlCanvas2d_heap* _this, int typeId) {
    switch (typeId) {
        case sji_surface_typeId:  {
            return (sjs_object*)sjf_htmlCanvas2d_heap_as_sji_surface(_this);
        }
    }

    return 0;
}

sji_surface* sjf_htmlCanvas2d_heap_as_sji_surface(sjs_htmlCanvas2d_heap* _this) {
    sji_surface* _interface;
    _interface = (sji_surface*)malloc(sizeof(sji_surface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_htmlCanvas2d_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_htmlCanvas2d_heap_asInterface;
    _interface->fillRect = (void(*)(void*,sjs_rect*,sjs_color*))sjf_htmlCanvas2d_fillRect;

    return _interface;
}

void sjf_mainLoop(void) {
    bool result1;
    bool result2;
    sjs_string sjt_call13;
    sjs_anon1* sjt_dot36;
    sjs_string* sjt_functionParam37;
    bool sjt_ifElse3;
    bool sjt_ifElse4;
    sji_element* sjt_isEmpty1;
    sji_element* sjt_isEmpty2;
    bool sjt_not1;
    bool sjt_not2;

    sjt_dot36 = &sjv_console;
    sjt_call13.count = 12;
    sjt_call13.data.size = 13;
    sjt_call13.data.data = (uintptr_t)sjg_string9;
    sjt_call13.data._isGlobal = false;
    sjf_array_char(&sjt_call13.data);
    sjf_string(&sjt_call13);
    sjt_functionParam37 = &sjt_call13;
    sjf_anon1_write(sjt_dot36, sjt_functionParam37);
    sjt_isEmpty1 = sjv_root;
    if (sjt_isEmpty1 != 0) {
        sjt_isEmpty1->_refCount++;
    }

    sjt_not1 = (sjt_isEmpty1 == 0);
    result1 = !sjt_not1;
    sjt_ifElse3 = result1;
    if (sjt_ifElse3) {
        sjs_rect sjt_call14;
        sji_element* sjt_dot37;
        sji_element* sjt_getValue1;
        sjs_rect* sjt_interfaceParam5;

        sjt_getValue1 = sjv_root;
        if (sjt_getValue1 != 0) {
            sjt_getValue1->_refCount++;
        }

        sjt_dot37 = sjt_getValue1;
        sjt_call14.x = 0;
        sjt_call14.y = 0;
        sjt_call14.w = 100;
        sjt_call14.h = 100;
        sjf_rect(&sjt_call14);
        sjt_interfaceParam5 = &sjt_call14;
        sjt_dot37->setRect((void*)(((char*)sjt_dot37->_parent) + sizeof(int)), sjt_interfaceParam5);

        if (sjt_getValue1 != 0) {
            sjt_getValue1->_refCount--;
            if (sjt_getValue1->_refCount <= 0) {
                sji_element_destroy(sjt_getValue1);
            }
        }
        sjf_rect_destroy(&sjt_call14);
    }

    sjt_isEmpty2 = sjv_root;
    if (sjt_isEmpty2 != 0) {
        sjt_isEmpty2->_refCount++;
    }

    sjt_not2 = (sjt_isEmpty2 == 0);
    result2 = !sjt_not2;
    sjt_ifElse4 = result2;
    if (sjt_ifElse4) {
        sji_element* sjt_dot38;
        sji_element* sjt_getValue2;
        sji_surface* sjt_interfaceParam6;

        sjt_getValue2 = sjv_root;
        if (sjt_getValue2 != 0) {
            sjt_getValue2->_refCount++;
        }

        sjt_dot38 = sjt_getValue2;
        sjt_interfaceParam6 = sjv_rootCanvas;
        sjt_interfaceParam6->_refCount++;
        sjt_dot38->render((void*)(((char*)sjt_dot38->_parent) + sizeof(int)), sjt_interfaceParam6);

        if (sjt_getValue2 != 0) {
            sjt_getValue2->_refCount--;
            if (sjt_getValue2->_refCount <= 0) {
                sji_element_destroy(sjt_getValue2);
            }
        }
        sjt_interfaceParam6->_refCount--;
        if (sjt_interfaceParam6->_refCount <= 0) {
            sji_surface_destroy(sjt_interfaceParam6);
        }
    }

    if (sjt_isEmpty1 != 0) {
        sjt_isEmpty1->_refCount--;
        if (sjt_isEmpty1->_refCount <= 0) {
            sji_element_destroy(sjt_isEmpty1);
        }
    }
    if (sjt_isEmpty2 != 0) {
        sjt_isEmpty2->_refCount--;
        if (sjt_isEmpty2->_refCount <= 0) {
            sji_element_destroy(sjt_isEmpty2);
        }
    }
    sjf_string_destroy(&sjt_call13);
}

void sjf_onClick(double timestemp, int32_t x, int32_t y) {
    sjs_string sjt_call7;
    sjs_anon1* sjt_dot21;
    sjs_string* sjt_functionParam25;

    sjt_dot21 = &sjv_console;
    sjt_call7.count = 5;
    sjt_call7.data.size = 6;
    sjt_call7.data.data = (uintptr_t)sjg_string3;
    sjt_call7.data._isGlobal = false;
    sjf_array_char(&sjt_call7.data);
    sjf_string(&sjt_call7);
    sjt_functionParam25 = &sjt_call7;
    sjf_anon1_write(sjt_dot21, sjt_functionParam25);

    sjf_string_destroy(&sjt_call7);
}

void sjf_rect(sjs_rect* _this) {
}

void sjf_rect_copy(sjs_rect* _this, sjs_rect* to) {
    _this->x = to->x;
    _this->y = to->y;
    _this->w = to->w;
    _this->h = to->h;
}

void sjf_rect_destroy(sjs_rect* _this) {
}

void sjf_rect_heap(sjs_rect_heap* _this) {
}

void sjf_runLoop(void) {
    
#ifdef EMSCRIPTEN
	emscripten_set_main_loop_arg((em_arg_callback_func)sjf_mainLoop, &global, 0, 0);
	exit(0);
#else
    while (true) {
        sjf_mainLoop();
    }
#endif	
	;
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t dotTemp1;
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sjs_string* sjt_dot7;
    bool sjt_ifElse1;

    sjt_dot7 = item;
    dotTemp1 = sjt_dot7->count;
    sjt_compare1 = dotTemp1;
    sjt_compare2 = 0;
    sjt_ifElse1 = sjt_compare1 > sjt_compare2;
    if (sjt_ifElse1) {
        sjs_array_char dotTemp14;
        int32_t dotTemp15;
        int32_t dotTemp2;
        int32_t dotTemp3;
        sjs_array_char dotTemp4;
        int32_t dotTemp5;
        int32_t dotTemp9;
        int32_t i;
        int32_t sjt_cast2;
        int32_t sjt_compare3;
        int32_t sjt_compare4;
        sjs_string* sjt_dot12;
        sjs_array_char* sjt_dot16;
        sjs_string* sjt_dot8;
        sjs_array_char* sjt_dot9;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;
        int32_t sjt_functionParam7;
        char sjt_functionParam8;
        bool sjt_ifElse2;
        int32_t sjt_math1;
        int32_t sjt_math2;
        int32_t sjt_math3;
        int32_t sjt_math4;

        dotTemp2 = _parent->count;
        sjt_math3 = dotTemp2;
        sjt_dot8 = item;
        dotTemp3 = sjt_dot8->count;
        sjt_math4 = dotTemp3;
        sjt_math1 = sjt_math3 + sjt_math4;
        sjt_math2 = 1;
        sjt_compare3 = sjt_math1 + sjt_math2;
        dotTemp4 = _parent->data;
        sjt_dot9 = &dotTemp4;
        dotTemp5 = sjt_dot9->size;
        sjt_compare4 = dotTemp5;
        sjt_ifElse2 = sjt_compare3 > sjt_compare4;
        if (sjt_ifElse2) {
            sjs_array_char dotTemp6;
            int32_t dotTemp7;
            int32_t dotTemp8;
            sjs_array_char* sjt_dot10;
            sjs_string* sjt_dot11;
            int32_t sjt_functionParam2;
            int32_t sjt_math5;
            int32_t sjt_math6;
            int32_t sjt_math7;
            int32_t sjt_math8;

            dotTemp6 = _parent->data;
            sjt_dot10 = &dotTemp6;
            dotTemp7 = _parent->count;
            sjt_math7 = dotTemp7;
            sjt_dot11 = item;
            dotTemp8 = sjt_dot11->count;
            sjt_math8 = dotTemp8;
            sjt_math5 = sjt_math7 + sjt_math8;
            sjt_math6 = 1;
            sjt_functionParam2 = sjt_math5 + sjt_math6;
            sjf_array_char_grow(sjt_dot10, sjt_functionParam2);

            sjf_array_char_destroy(&dotTemp6);
        }

        sjt_forStart1 = 0;
        i = sjt_forStart1;
        sjt_dot12 = item;
        dotTemp9 = sjt_dot12->count;
        sjt_forEnd1 = dotTemp9;
        while (i < sjt_forEnd1) {
            sjs_array_char dotTemp10;
            int32_t dotTemp11;
            int32_t dotTemp13;
            sjs_array_char* sjt_dot13;
            sjs_string* sjt_dot14;
            int32_t sjt_functionParam3;
            char sjt_functionParam4;
            int32_t sjt_functionParam6;
            int32_t sjt_math10;
            int32_t sjt_math9;

            dotTemp10 = _parent->data;
            sjt_dot13 = &dotTemp10;
            dotTemp11 = _parent->count;
            sjt_functionParam3 = dotTemp11;
            sjt_dot14 = item;
            sjt_functionParam6 = i;
            sjf_string_getAt(sjt_dot14, sjt_functionParam6, &sjt_functionParam4);
            sjf_array_char_setAt(sjt_dot13, sjt_functionParam3, sjt_functionParam4);
            dotTemp13 = _parent->count;
            sjt_math9 = dotTemp13;
            sjt_math10 = 1;
            _parent->count = sjt_math9 + sjt_math10;
            i++;

            sjf_array_char_destroy(&dotTemp10);
        }

        dotTemp14 = _parent->data;
        sjt_dot16 = &dotTemp14;
        dotTemp15 = _parent->count;
        sjt_functionParam7 = dotTemp15;
        sjt_cast2 = 0;
        sjt_functionParam8 = (char)sjt_cast2;
        sjf_array_char_setAt(sjt_dot16, sjt_functionParam7, sjt_functionParam8);

        sjf_array_char_destroy(&dotTemp14);
        sjf_array_char_destroy(&dotTemp4);
    }

    (*_return) = _parent;
}

void sjf_string_copy(sjs_string* _this, sjs_string* to) {
    _this->count = to->count;
    sjf_array_char_copy(&_this->data, &to->data);
}

void sjf_string_destroy(sjs_string* _this) {
}

void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return) {
    sjs_array_char dotTemp12;
    sjs_array_char* sjt_dot15;
    int32_t sjt_functionParam5;

    dotTemp12 = _parent->data;
    sjt_dot15 = &dotTemp12;
    sjt_functionParam5 = index;
    sjf_array_char_getAt(sjt_dot15, sjt_functionParam5, &(*_return));

    sjf_array_char_destroy(&dotTemp12);
}

void sjf_string_heap(sjs_string_heap* _this) {
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
    sjf_anon5(&sjv_style);
    sjf_anon4(&sjv_convert);
    sjf_anon3(&sjv_random);
    sjf_anon2(&sjv_parse);
    sjf_anon1(&sjv_console);
    sjv_root = 0;
    if (sjv_root != 0) {
        sjv_root->_refCount++;
    }

    sjt_cast1 = (sjs_htmlCanvas2d_heap*)malloc(sizeof(sjs_htmlCanvas2d_heap));
    sjt_cast1->_refCount = 1;
    sjt_cast1->ctxVarName.count = 5;
    sjt_cast1->ctxVarName.data.size = 6;
    sjt_cast1->ctxVarName.data.data = (uintptr_t)sjg_string2;
    sjt_cast1->ctxVarName.data._isGlobal = false;
    sjf_array_char(&sjt_cast1->ctxVarName.data);
    sjf_string(&sjt_cast1->ctxVarName);
    sjf_htmlCanvas2d_heap(sjt_cast1);
    sjv_rootCanvas = (sji_surface*)sjf_htmlCanvas2d_heap_as_sji_surface(sjt_cast1);
    
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() != 0) {
        printf("TTF_Init Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == 0) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == 0) {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Surface* bmp = SDL_LoadBMP("assets/hello2.bmp");
    if (bmp == 0) {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if (tex == 0) {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Color color = { 255, 255, 255, 255 };
    SDL_Texture* image = renderText("Mallory & Madison is awesome!", "assets/sample.ttf", color, 32, ren);
    if (image == 0) {
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
;
    sjt_cast5 = (sjs_element_heap*)malloc(sizeof(sjs_element_heap));
    sjt_cast5->_refCount = 1;
    sjt_cast5->children.size = 1;
    sjt_cast6 = 0;
    sjt_cast5->children.data = (uintptr_t)sjt_cast6;
    sjt_cast5->children._isGlobal = false;
    sjf_array_heap_element(&sjt_cast5->children);
    sjt_functionParam30 = 0;
    sjt_cast7 = (sjs_button_heap*)malloc(sizeof(sjs_button_heap));
    sjt_cast7->_refCount = 1;
    sjt_cast7->text.count = 0;
    sjt_cast7->text.data.size = 1;
    sjt_cast7->text.data.data = (uintptr_t)sjg_string6;
    sjt_cast7->text.data._isGlobal = false;
    sjf_array_char(&sjt_cast7->text.data);
    sjf_string(&sjt_cast7->text);
    sjt_dot35 = &sjv_style;
    sjt_functionParam36 = 0;
    sjf_anon5_getFont(sjt_dot35, sjt_functionParam36, &sjt_cast7->font);
    sjt_cast7->rect.x = 0;
    sjt_cast7->rect.y = 0;
    sjt_cast7->rect.w = 0;
    sjt_cast7->rect.h = 0;
    sjf_rect(&sjt_cast7->rect);
    sjf_button_heap(sjt_cast7);
    sjt_functionParam31 = (sji_element*)sjf_button_heap_as_sji_element(sjt_cast7);
    sjf_array_heap_element_initAt(&sjt_cast5->children, sjt_functionParam30, sjt_functionParam31);
    sjt_cast5->rect.x = 0;
    sjt_cast5->rect.y = 0;
    sjt_cast5->rect.w = 0;
    sjt_cast5->rect.h = 0;
    sjf_rect(&sjt_cast5->rect);
    sjf_element_heap(sjt_cast5);
    sjt_value1 = (sji_element*)sjf_element_heap_as_sji_element(sjt_cast5);
    if (sjv_root != 0) {
        sjv_root->_refCount--;
        if (sjv_root->_refCount <= 0) {
            sji_element_destroy(sjv_root);
        }
    }

    sjv_root = sjt_value1;
    if (sjv_root != 0) {
        sjv_root->_refCount++;
    }

    sjf_runLoop();
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_cast1->_refCount--;
    if (sjt_cast1->_refCount <= 0) {
        sjf_htmlCanvas2d_destroy((sjs_htmlCanvas2d*)(((char*)sjt_cast1) + sizeof(int)));
    }
    sjt_cast5->_refCount--;
    if (sjt_cast5->_refCount <= 0) {
        sjf_element_destroy((sjs_element*)(((char*)sjt_cast5) + sizeof(int)));
    }
    sjt_cast7->_refCount--;
    if (sjt_cast7->_refCount <= 0) {
        sjf_button_destroy((sjs_button*)(((char*)sjt_cast7) + sizeof(int)));
    }
    sjt_functionParam31->_refCount--;
    if (sjt_functionParam31->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam31);
    }
    sjt_value1->_refCount--;
    if (sjt_value1->_refCount <= 0) {
        sji_element_destroy(sjt_value1);
    }
    if (sjv_root != 0) {
        sjv_root->_refCount--;
        if (sjv_root->_refCount <= 0) {
            sji_element_destroy(sjv_root);
        }
    }
    sjv_rootCanvas->_refCount--;
    if (sjv_rootCanvas->_refCount <= 0) {
        sji_surface_destroy(sjv_rootCanvas);
    }
    sjf_anon1_destroy(&sjv_console);
    sjf_anon4_destroy(&sjv_convert);
    sjf_anon2_destroy(&sjv_parse);
    sjf_anon3_destroy(&sjv_random);
    sjf_anon5_destroy(&sjv_style);
}
