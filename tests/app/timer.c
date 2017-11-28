#ifdef WIN32
#include <SDL.h>
#endif
#ifdef __APPLE__
#include <SDL2/SDL.h>
#endif
#ifdef __APPLE__
#include <SDL2_ttf/SDL_ttf.h>
#endif
#ifdef WIN32
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

const char* sjg_string1 = "click";
const char* sjg_string11 = "render - 2";
const char* sjg_string4 = "";
const char* sjg_string5 = "48px serif";
const char* sjg_string6 = "48px serif";
const char* sjg_string7 = "mainLoop - ";
const char* sjg_string9 = "setRect - 2";

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
#define sjs_size_typeId 16
#define sjs_size_heap_typeId 17
#define sjs_sdlSurace_typeId 18
#define sjs_rect_typeId 19
#define sjs_rect_heap_typeId 20
#define sjs_color_typeId 21
#define sjs_color_heap_typeId 22
#define sji_surface_typeId 23
#define sjs_sdlSurace_heap_typeId 24
#define sjs_array_heap_element_typeId 25
#define sjs_array_heap_element_heap_typeId 26
#define sjs_element_typeId 27
#define sji_element_typeId 28
#define sjs_element_heap_typeId 29
#define sjs_button_typeId 30
#define sjs_button_heap_typeId 31

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
typedef struct td_sjs_size sjs_size;
typedef struct td_sjs_size_heap sjs_size_heap;
typedef struct td_sjs_sdlSurace sjs_sdlSurace;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_rect_heap sjs_rect_heap;
typedef struct td_sjs_color sjs_color;
typedef struct td_sjs_color_heap sjs_color_heap;
typedef struct td_sji_surface sji_surface;
typedef struct td_sjs_sdlSurace_heap sjs_sdlSurace_heap;
typedef struct td_sjs_array_heap_element sjs_array_heap_element;
typedef struct td_sjs_array_heap_element_heap sjs_array_heap_element_heap;
typedef struct td_sjs_element sjs_element;
typedef struct td_sji_element sji_element;
typedef struct td_sjs_element_heap sjs_element_heap;
typedef struct td_sjs_button sjs_button;
typedef struct td_sjs_button_heap sjs_button_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_anon5 {
    int structsNeedAValue;
};

struct td_sjs_anon5_heap {
    intptr_t _refCount;
};

struct td_sjs_anon4 {
    int structsNeedAValue;
};

struct td_sjs_anon4_heap {
    intptr_t _refCount;
};

struct td_sjs_anon3 {
    int structsNeedAValue;
};

struct td_sjs_anon3_heap {
    intptr_t _refCount;
};

struct td_sjs_anon2 {
    int structsNeedAValue;
};

struct td_sjs_anon2_heap {
    intptr_t _refCount;
};

struct td_sjs_anon1 {
    int structsNeedAValue;
};

struct td_sjs_anon1_heap {
    intptr_t _refCount;
};

struct td_sjs_array_char {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_char_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_string {
    int32_t count;
    sjs_array_char data;
};

struct td_sjs_string_heap {
    intptr_t _refCount;
    int32_t count;
    sjs_array_char data;
};

struct td_sjs_size {
    int32_t w;
    int32_t h;
};

struct td_sjs_size_heap {
    intptr_t _refCount;
    int32_t w;
    int32_t h;
};

struct td_sjs_sdlSurace {
    sjs_size size;
    uintptr_t win;
    uintptr_t ren;
};

struct td_sjs_rect {
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct td_sjs_rect_heap {
    intptr_t _refCount;
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct td_sjs_color {
    int32_t r;
    int32_t g;
    int32_t b;
    int32_t a;
};

struct td_sjs_color_heap {
    intptr_t _refCount;
    int32_t r;
    int32_t g;
    int32_t b;
    int32_t a;
};

struct td_sji_surface {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*clear)(void* _parent);
    void (*present)(void* _parent);
    void (*getSize)(void* _parent, sjs_size** _return);
    void (*fillRect)(void* _parent, sjs_rect* rect, sjs_color* color);
};

struct td_sjs_sdlSurace_heap {
    intptr_t _refCount;
    sjs_size size;
    uintptr_t win;
    uintptr_t ren;
};

struct td_sjs_array_heap_element {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_heap_element_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_element {
    sjs_array_heap_element children;
    sjs_rect rect;
};

struct td_sji_element {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*setRect)(void* _parent, sjs_rect* rect);
    void (*render)(void* _parent, sji_surface* surface);
};

struct td_sjs_element_heap {
    intptr_t _refCount;
    sjs_array_heap_element children;
    sjs_rect rect;
};

struct td_sjs_button {
    sjs_string text;
    sjs_string font;
    sjs_rect rect;
    int32_t offset;
};

struct td_sjs_button_heap {
    intptr_t _refCount;
    sjs_string text;
    sjs_string font;
    sjs_rect rect;
    int32_t offset;
};


	
	
	
	
	
	
	
	

#ifdef EMSCRIPTEN
	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
#endif	
	SDL_Texture* renderText(const char* message, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);

sjs_sdlSurace_heap* sjt_cast1;
int32_t sjt_cast2;
int32_t sjt_cast3;
sjs_element_heap* sjt_cast4;
int32_t sjt_cast5;
sjs_button_heap* sjt_cast6;
sjs_anon5* sjt_dot17;
int32_t sjt_functionParam10;
int32_t sjt_functionParam6;
sji_element* sjt_functionParam7;
sji_element* sjt_value1;
sjs_anon1 sjv_console;
sjs_anon4 sjv_convert;
int32_t sjv_frame;
sjs_anon2 sjv_parse;
sjs_anon3 sjv_random;
sji_element* sjv_root;
sji_surface* sjv_rootSurface;
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
void sjf_mainLoop(void);
void sjf_onClick(double timestemp, int32_t x, int32_t y);
void sjf_rect(sjs_rect* _this);
void sjf_rect_copy(sjs_rect* _this, sjs_rect* to);
void sjf_rect_destroy(sjs_rect* _this);
void sjf_rect_heap(sjs_rect_heap* _this);
void sjf_runLoop(void);
void sjf_sdlSurace(sjs_sdlSurace* _this);
sjs_object* sjf_sdlSurace_asInterface(sjs_sdlSurace* _this, int typeId);
sji_surface* sjf_sdlSurace_as_sji_surface(sjs_sdlSurace* _this);
void sjf_sdlSurace_clear(sjs_sdlSurace* _parent);
void sjf_sdlSurace_copy(sjs_sdlSurace* _this, sjs_sdlSurace* to);
void sjf_sdlSurace_destroy(sjs_sdlSurace* _this);
void sjf_sdlSurace_fillRect(sjs_sdlSurace* _parent, sjs_rect* rect, sjs_color* color);
void sjf_sdlSurace_getSize(sjs_sdlSurace* _parent, sjs_size** _return);
void sjf_sdlSurace_heap(sjs_sdlSurace_heap* _this);
sjs_object* sjf_sdlSurace_heap_asInterface(sjs_sdlSurace_heap* _this, int typeId);
sji_surface* sjf_sdlSurace_heap_as_sji_surface(sjs_sdlSurace_heap* _this);
void sjf_sdlSurace_present(sjs_sdlSurace* _parent);
void sjf_size(sjs_size* _this);
void sjf_size_copy(sjs_size* _this, sjs_size* to);
void sjf_size_destroy(sjs_size* _this);
void sjf_size_heap(sjs_size_heap* _this);
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
    int32_t sjt_cast8;
    int32_t sjt_math19;
    int32_t sjt_math20;
    int32_t sjv_count;
    uintptr_t sjv_data;

    sjv_count = 0;
    sjt_cast8 = 0;
    sjv_data = (uintptr_t)sjt_cast8;
    
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
    sjt_math19 = sjv_count;
    sjt_math20 = 1;
    _return->data.size = sjt_math19 + sjt_math20;
    _return->data.data = sjv_data;
    _return->data._isGlobal = false;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_anon4_i32toString_heap(sjs_anon4* _parent, int32_t val, int32_t base, int32_t minLength, sjs_string_heap** _return) {
    int32_t sjt_cast9;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjv_count;
    uintptr_t sjv_data;

    sjv_count = 0;
    sjt_cast9 = 0;
    sjv_data = (uintptr_t)sjt_cast9;
    
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
    sjt_math21 = sjv_count;
    sjt_math22 = 1;
    (*_return)->data.size = sjt_math21 + sjt_math22;
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
    _return->data.data = (uintptr_t)sjg_string5;
    _return->data._isGlobal = false;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_anon5_getFont_heap(sjs_anon5* _parent, int32_t typeId, sjs_string_heap** _return) {
    (*_return) = (sjs_string_heap*)malloc(sizeof(sjs_string_heap));
    (*_return)->_refCount = 1;
    (*_return)->count = 10;
    (*_return)->data.size = 11;
    (*_return)->data.data = (uintptr_t)sjg_string6;
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
    sjs_anon5* sjt_dot10;
    int32_t sjt_functionParam8;
    sjs_string void1;

    sjt_dot10 = &sjv_style;
    sjt_functionParam8 = 1;
    sjf_anon5_getFont(sjt_dot10, sjt_functionParam8, &void1);

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
    _this->offset = to->offset;
}

void sjf_button_destroy(sjs_button* _this) {
}

void sjf_button_heap(sjs_button_heap* _this) {
    sjs_anon5* sjt_dot16;
    int32_t sjt_functionParam9;
    sjs_string void2;

    sjt_dot16 = &sjv_style;
    sjt_functionParam9 = 1;
    sjf_anon5_getFont(sjt_dot16, sjt_functionParam9, &void2);

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
    int32_t dotTemp10;
    sjs_rect* dotTemp11;
    int32_t dotTemp12;
    int32_t dotTemp13;
    sjs_rect* dotTemp14;
    int32_t dotTemp15;
    sjs_rect* dotTemp16;
    int32_t dotTemp17;
    int32_t dotTemp18;
    int32_t dotTemp19;
    sjs_rect* dotTemp9;
    sjs_rect sjt_call4;
    sjs_color sjt_call5;
    sji_surface* sjt_dot11;
    sjs_rect* sjt_dot12;
    sjs_rect* sjt_dot13;
    sjs_rect* sjt_dot14;
    sjs_rect* sjt_dot15;
    sjs_rect* sjt_interfaceParam3;
    sjs_color* sjt_interfaceParam4;
    int32_t sjt_math1;
    int32_t sjt_math2;
    int32_t sjt_math3;
    int32_t sjt_math4;
    int32_t sjt_math5;
    int32_t sjt_math6;
    int32_t sjt_math7;
    int32_t sjt_math8;

    sjt_dot11 = surface;
    dotTemp9 = &_parent->rect;
    sjt_dot12 = dotTemp9;
    dotTemp10 = sjt_dot12->x;
    sjt_call4.x = dotTemp10;
    dotTemp11 = &_parent->rect;
    sjt_dot13 = dotTemp11;
    dotTemp12 = sjt_dot13->y;
    sjt_math1 = dotTemp12;
    dotTemp13 = _parent->offset;
    sjt_math2 = dotTemp13;
    sjt_call4.y = sjt_math1 + sjt_math2;
    dotTemp14 = &_parent->rect;
    sjt_dot14 = dotTemp14;
    dotTemp15 = sjt_dot14->w;
    sjt_call4.w = dotTemp15;
    dotTemp16 = &_parent->rect;
    sjt_dot15 = dotTemp16;
    dotTemp17 = sjt_dot15->h;
    sjt_math3 = dotTemp17;
    sjt_math5 = 2;
    dotTemp18 = _parent->offset;
    sjt_math6 = dotTemp18;
    sjt_math4 = sjt_math5 * sjt_math6;
    sjt_call4.h = sjt_math3 - sjt_math4;
    sjf_rect(&sjt_call4);
    sjt_interfaceParam3 = &sjt_call4;
    sjt_call5.r = 255;
    sjt_call5.g = 0;
    sjt_call5.b = 0;
    sjt_call5.a = 255;
    sjf_color(&sjt_call5);
    sjt_interfaceParam4 = &sjt_call5;
    sjt_dot11->fillRect((void*)(((char*)sjt_dot11->_parent) + sizeof(intptr_t)), sjt_interfaceParam3, sjt_interfaceParam4);
    dotTemp19 = _parent->offset;
    sjt_math7 = dotTemp19;
    sjt_math8 = 1;
    _parent->offset = sjt_math7 + sjt_math8;

    sjf_rect_destroy(&sjt_call4);
    sjf_color_destroy(&sjt_call5);
}

void sjf_button_setRect(sjs_button* _parent, sjs_rect* rect_) {
    sjf_rect_copy(&_parent->rect, rect_);
}

void sjf_color(sjs_color* _this) {
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
    sjs_array_heap_element* dotTemp6;
    int32_t dotTemp7;
    int32_t i;
    sjs_string sjt_call3;
    sjs_anon1* sjt_dot6;
    sjs_array_heap_element* sjt_dot7;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;
    sjs_string* sjt_functionParam4;

    sjt_dot6 = &sjv_console;
    sjt_call3.count = 10;
    sjt_call3.data.size = 11;
    sjt_call3.data.data = (uintptr_t)sjg_string11;
    sjt_call3.data._isGlobal = false;
    sjf_array_char(&sjt_call3.data);
    sjf_string(&sjt_call3);
    sjt_functionParam4 = &sjt_call3;
    sjf_anon1_write(sjt_dot6, sjt_functionParam4);
    sjt_forStart2 = 0;
    i = sjt_forStart2;
    dotTemp6 = &_parent->children;
    sjt_dot7 = dotTemp6;
    dotTemp7 = sjt_dot7->size;
    sjt_forEnd2 = dotTemp7;
    while (i < sjt_forEnd2) {
        sjs_array_heap_element* dotTemp8;
        sjs_array_heap_element* sjt_dot8;
        sji_element* sjt_dot9;
        int32_t sjt_functionParam5;
        sji_surface* sjt_interfaceParam2;
        sji_element* sjv_child;

        dotTemp8 = &_parent->children;
        sjt_dot8 = dotTemp8;
        sjt_functionParam5 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot8, sjt_functionParam5, &sjv_child);
        sjt_dot9 = sjv_child;
        sjt_interfaceParam2 = surface;
        sjt_interfaceParam2->_refCount++;
        sjt_dot9->render((void*)(((char*)sjt_dot9->_parent) + sizeof(intptr_t)), sjt_interfaceParam2);
        i++;

        sjt_interfaceParam2->_refCount--;
        if (sjt_interfaceParam2->_refCount <= 0) {
            sji_surface_destroy(sjt_interfaceParam2);
        }
        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }

    sjf_string_destroy(&sjt_call3);
}

void sjf_element_setRect(sjs_element* _parent, sjs_rect* rect_) {
    sjs_array_heap_element* dotTemp2;
    int32_t dotTemp3;
    int32_t i;
    sjs_string sjt_call2;
    sjs_anon1* sjt_dot2;
    sjs_array_heap_element* sjt_dot3;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    sjs_string* sjt_functionParam2;

    sjt_dot2 = &sjv_console;
    sjt_call2.count = 11;
    sjt_call2.data.size = 12;
    sjt_call2.data.data = (uintptr_t)sjg_string9;
    sjt_call2.data._isGlobal = false;
    sjf_array_char(&sjt_call2.data);
    sjf_string(&sjt_call2);
    sjt_functionParam2 = &sjt_call2;
    sjf_anon1_write(sjt_dot2, sjt_functionParam2);
    sjf_rect_copy(&_parent->rect, rect_);
    sjt_forStart1 = 0;
    i = sjt_forStart1;
    dotTemp2 = &_parent->children;
    sjt_dot3 = dotTemp2;
    dotTemp3 = sjt_dot3->size;
    sjt_forEnd1 = dotTemp3;
    while (i < sjt_forEnd1) {
        sjs_array_heap_element* dotTemp4;
        sjs_rect* dotTemp5;
        sjs_array_heap_element* sjt_dot4;
        sji_element* sjt_dot5;
        int32_t sjt_functionParam3;
        sjs_rect* sjt_interfaceParam1;
        sji_element* sjv_child;

        dotTemp4 = &_parent->children;
        sjt_dot4 = dotTemp4;
        sjt_functionParam3 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot4, sjt_functionParam3, &sjv_child);
        sjt_dot5 = sjv_child;
        dotTemp5 = &_parent->rect;
        sjt_interfaceParam1 = dotTemp5;
        sjt_dot5->setRect((void*)(((char*)sjt_dot5->_parent) + sizeof(intptr_t)), sjt_interfaceParam1);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }

    sjf_string_destroy(&sjt_call2);
}

void sjf_mainLoop(void) {
    bool result1;
    bool sjt_ifElse1;
    sji_surface* sjt_isEmpty1;
    int32_t sjt_math23;
    int32_t sjt_math24;
    bool sjt_not1;

    sjt_isEmpty1 = sjv_rootSurface;
    if (sjt_isEmpty1 != 0) {
        sjt_isEmpty1->_refCount++;
    }

    sjt_not1 = (sjt_isEmpty1 == 0);
    result1 = !sjt_not1;
    sjt_ifElse1 = result1;
    if (sjt_ifElse1) {
        int32_t dotTemp35;
        int32_t dotTemp36;
        bool result2;
        bool result3;
        sjs_string sjt_call6;
        sjs_string sjt_call7;
        sjs_anon1* sjt_dot18;
        sjs_string* sjt_dot19;
        sjs_anon4* sjt_dot30;
        sji_surface* sjt_dot31;
        sji_surface* sjt_dot32;
        sjs_size* sjt_dot33;
        sjs_size* sjt_dot34;
        sji_surface* sjt_dot37;
        sjs_string* sjt_functionParam11;
        sjs_string* sjt_functionParam19;
        int32_t sjt_functionParam20;
        int32_t sjt_functionParam21;
        int32_t sjt_functionParam22;
        sji_surface* sjt_getValue1;
        bool sjt_ifElse4;
        bool sjt_ifElse5;
        sji_element* sjt_isEmpty2;
        sji_element* sjt_isEmpty3;
        bool sjt_not2;
        bool sjt_not3;
        sjs_rect sjv_rect;
        sjs_size* sjv_size;
        sji_surface* sjv_surf;

        sjt_dot18 = &sjv_console;
        sjt_call6.count = 11;
        sjt_call6.data.size = 12;
        sjt_call6.data.data = (uintptr_t)sjg_string7;
        sjt_call6.data._isGlobal = false;
        sjf_array_char(&sjt_call6.data);
        sjf_string(&sjt_call6);
        sjt_dot19 = &sjt_call6;
        sjt_dot30 = &sjv_convert;
        sjt_functionParam20 = sjv_frame;
        sjt_functionParam21 = 10;
        sjt_functionParam22 = 0;
        sjf_anon4_i32toString(sjt_dot30, sjt_functionParam20, sjt_functionParam21, sjt_functionParam22, &sjt_call7);
        sjt_functionParam19 = &sjt_call7;
        sjf_string_add(sjt_dot19, sjt_functionParam19, &sjt_functionParam11);
        sjf_anon1_write(sjt_dot18, sjt_functionParam11);
        sjt_getValue1 = sjv_rootSurface;
        if (sjt_getValue1 != 0) {
            sjt_getValue1->_refCount++;
        }

        if (sjt_getValue1 == 0) { exit(-1); };
        sjv_surf = sjt_getValue1;
        sjv_surf->_refCount++;
        sjt_dot31 = sjv_surf;
        sjt_dot31->clear((void*)(((char*)sjt_dot31->_parent) + sizeof(intptr_t)));
        sjt_dot32 = sjv_surf;
        sjt_dot32->getSize((void*)(((char*)sjt_dot32->_parent) + sizeof(intptr_t)), &sjv_size);
        sjv_rect.x = 0;
        sjv_rect.y = 0;
        sjt_dot33 = sjv_size;
        dotTemp35 = sjt_dot33->w;
        sjv_rect.w = dotTemp35;
        sjt_dot34 = sjv_size;
        dotTemp36 = sjt_dot34->h;
        sjv_rect.h = dotTemp36;
        sjf_rect(&sjv_rect);
        sjt_isEmpty2 = sjv_root;
        if (sjt_isEmpty2 != 0) {
            sjt_isEmpty2->_refCount++;
        }

        sjt_not2 = (sjt_isEmpty2 == 0);
        result2 = !sjt_not2;
        sjt_ifElse4 = result2;
        if (sjt_ifElse4) {
            sji_element* sjt_dot35;
            sji_element* sjt_getValue2;
            sjs_rect* sjt_interfaceParam5;

            sjt_getValue2 = sjv_root;
            if (sjt_getValue2 != 0) {
                sjt_getValue2->_refCount++;
            }

            sjt_dot35 = sjt_getValue2;
            sjt_interfaceParam5 = &sjv_rect;
            sjt_dot35->setRect((void*)(((char*)sjt_dot35->_parent) + sizeof(intptr_t)), sjt_interfaceParam5);

            if (sjt_getValue2 != 0) {
                sjt_getValue2->_refCount--;
                if (sjt_getValue2->_refCount <= 0) {
                    sji_element_destroy(sjt_getValue2);
                }
            }
        }

        sjt_isEmpty3 = sjv_root;
        if (sjt_isEmpty3 != 0) {
            sjt_isEmpty3->_refCount++;
        }

        sjt_not3 = (sjt_isEmpty3 == 0);
        result3 = !sjt_not3;
        sjt_ifElse5 = result3;
        if (sjt_ifElse5) {
            sji_element* sjt_dot36;
            sji_element* sjt_getValue3;
            sji_surface* sjt_interfaceParam6;

            sjt_getValue3 = sjv_root;
            if (sjt_getValue3 != 0) {
                sjt_getValue3->_refCount++;
            }

            sjt_dot36 = sjt_getValue3;
            sjt_interfaceParam6 = sjv_surf;
            sjt_interfaceParam6->_refCount++;
            sjt_dot36->render((void*)(((char*)sjt_dot36->_parent) + sizeof(intptr_t)), sjt_interfaceParam6);

            if (sjt_getValue3 != 0) {
                sjt_getValue3->_refCount--;
                if (sjt_getValue3->_refCount <= 0) {
                    sji_element_destroy(sjt_getValue3);
                }
            }
            sjt_interfaceParam6->_refCount--;
            if (sjt_interfaceParam6->_refCount <= 0) {
                sji_surface_destroy(sjt_interfaceParam6);
            }
        }

        sjt_dot37 = sjv_surf;
        sjt_dot37->present((void*)(((char*)sjt_dot37->_parent) + sizeof(intptr_t)));

        if (sjt_getValue1 != 0) {
            sjt_getValue1->_refCount--;
            if (sjt_getValue1->_refCount <= 0) {
                sji_surface_destroy(sjt_getValue1);
            }
        }
        if (sjt_isEmpty2 != 0) {
            sjt_isEmpty2->_refCount--;
            if (sjt_isEmpty2->_refCount <= 0) {
                sji_element_destroy(sjt_isEmpty2);
            }
        }
        if (sjt_isEmpty3 != 0) {
            sjt_isEmpty3->_refCount--;
            if (sjt_isEmpty3->_refCount <= 0) {
                sji_element_destroy(sjt_isEmpty3);
            }
        }
        sjv_surf->_refCount--;
        if (sjv_surf->_refCount <= 0) {
            sji_surface_destroy(sjv_surf);
        }
        sjf_string_destroy(&sjt_call6);
        sjf_string_destroy(&sjt_call7);
        sjf_rect_destroy(&sjv_rect);
    }

    sjt_math23 = sjv_frame;
    sjt_math24 = 1;
    sjv_frame = sjt_math23 + sjt_math24;

    if (sjt_isEmpty1 != 0) {
        sjt_isEmpty1->_refCount--;
        if (sjt_isEmpty1->_refCount <= 0) {
            sji_surface_destroy(sjt_isEmpty1);
        }
    }
}

void sjf_onClick(double timestemp, int32_t x, int32_t y) {
    sjs_string sjt_call1;
    sjs_anon1* sjt_dot1;
    sjs_string* sjt_functionParam1;

    sjt_dot1 = &sjv_console;
    sjt_call1.count = 5;
    sjt_call1.data.size = 6;
    sjt_call1.data.data = (uintptr_t)sjg_string1;
    sjt_call1.data._isGlobal = false;
    sjf_array_char(&sjt_call1.data);
    sjf_string(&sjt_call1);
    sjt_functionParam1 = &sjt_call1;
    sjf_anon1_write(sjt_dot1, sjt_functionParam1);

    sjf_string_destroy(&sjt_call1);
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
	bool quit = false;
    while (!quit) {
        sjf_mainLoop();

        //Handle events on queue
		SDL_Event e;
        while(SDL_PollEvent( &e ) != 0) {
            //User requests quit
            if( e.type == SDL_QUIT ) {
                quit = true;
            }
        }
    }
#endif	
	;
}

void sjf_sdlSurace(sjs_sdlSurace* _this) {
    
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
	        printf("SDL_Init Error: %s\n", SDL_GetError());
	        exit(-1);
	    }

	    if (TTF_Init() != 0) {
	        printf("TTF_Init Error: %s\n", SDL_GetError());
	        exit(-1);
	    }

	    _this->win = (uintptr_t)SDL_CreateWindow("Hello World!", 100, 100, _this->size.w, _this->size.h, SDL_WINDOW_SHOWN);
	    if (_this->win == 0) {
	        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
	        exit(-1);
	    }

	    _this->ren = (uintptr_t)SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	    if (_this->ren == 0) {
	        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
	        exit(-1);
	    }
	;
}

sjs_object* sjf_sdlSurace_asInterface(sjs_sdlSurace* _this, int typeId) {
    switch (typeId) {
        case sji_surface_typeId:  {
            return (sjs_object*)sjf_sdlSurace_as_sji_surface(_this);
        }
    }

    return 0;
}

sji_surface* sjf_sdlSurace_as_sji_surface(sjs_sdlSurace* _this) {
    sji_surface* _interface;
    _interface = (sji_surface*)malloc(sizeof(sji_surface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_sdlSurace_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_sdlSurace_asInterface;
    _interface->clear = (void(*)(void*))sjf_sdlSurace_clear;
    _interface->present = (void(*)(void*))sjf_sdlSurace_present;
    _interface->getSize = (void(*)(void*, sjs_size**))sjf_sdlSurace_getSize;
    _interface->fillRect = (void(*)(void*,sjs_rect*,sjs_color*))sjf_sdlSurace_fillRect;

    return _interface;
}

void sjf_sdlSurace_clear(sjs_sdlSurace* _parent) {
    
		SDL_SetRenderDrawColor((SDL_Renderer*)_parent->ren, 0, 0, 0, 0);
		SDL_RenderClear((SDL_Renderer*)_parent->ren);
	;
}

void sjf_sdlSurace_copy(sjs_sdlSurace* _this, sjs_sdlSurace* to) {
    sjf_size_copy(&_this->size, &to->size);
    _this->win = to->win;
    _this->ren = to->ren;
}

void sjf_sdlSurace_destroy(sjs_sdlSurace* _this) {
    
	SDL_DestroyRenderer((SDL_Renderer*)_this->ren);
	SDL_DestroyWindow((SDL_Window*)_this->win);
;
}

void sjf_sdlSurace_fillRect(sjs_sdlSurace* _parent, sjs_rect* rect, sjs_color* color) {
    
		SDL_SetRenderDrawColor((SDL_Renderer*)_parent->ren, color->r, color->g, color->b, color->a);
		SDL_RenderDrawRect((SDL_Renderer*)_parent->ren, (SDL_Rect*)rect);
	;
}

void sjf_sdlSurace_getSize(sjs_sdlSurace* _parent, sjs_size** _return) {
    sjs_size* dotTemp1;

    dotTemp1 = &_parent->size;
    (*_return) = dotTemp1;
}

void sjf_sdlSurace_heap(sjs_sdlSurace_heap* _this) {
    
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
	        printf("SDL_Init Error: %s\n", SDL_GetError());
	        exit(-1);
	    }

	    if (TTF_Init() != 0) {
	        printf("TTF_Init Error: %s\n", SDL_GetError());
	        exit(-1);
	    }

	    _this->win = (uintptr_t)SDL_CreateWindow("Hello World!", 100, 100, _this->size.w, _this->size.h, SDL_WINDOW_SHOWN);
	    if (_this->win == 0) {
	        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
	        exit(-1);
	    }

	    _this->ren = (uintptr_t)SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	    if (_this->ren == 0) {
	        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
	        exit(-1);
	    }
	;
}

sjs_object* sjf_sdlSurace_heap_asInterface(sjs_sdlSurace_heap* _this, int typeId) {
    switch (typeId) {
        case sji_surface_typeId:  {
            return (sjs_object*)sjf_sdlSurace_heap_as_sji_surface(_this);
        }
    }

    return 0;
}

sji_surface* sjf_sdlSurace_heap_as_sji_surface(sjs_sdlSurace_heap* _this) {
    sji_surface* _interface;
    _interface = (sji_surface*)malloc(sizeof(sji_surface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_sdlSurace_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_sdlSurace_heap_asInterface;
    _interface->clear = (void(*)(void*))sjf_sdlSurace_clear;
    _interface->present = (void(*)(void*))sjf_sdlSurace_present;
    _interface->getSize = (void(*)(void*, sjs_size**))sjf_sdlSurace_getSize;
    _interface->fillRect = (void(*)(void*,sjs_rect*,sjs_color*))sjf_sdlSurace_fillRect;

    return _interface;
}

void sjf_sdlSurace_present(sjs_sdlSurace* _parent) {
    
		SDL_RenderPresent((SDL_Renderer*)_parent->ren);
	;
}

void sjf_size(sjs_size* _this) {
}

void sjf_size_copy(sjs_size* _this, sjs_size* to) {
    _this->w = to->w;
    _this->h = to->h;
}

void sjf_size_destroy(sjs_size* _this) {
}

void sjf_size_heap(sjs_size_heap* _this) {
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t dotTemp20;
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sjs_string* sjt_dot20;
    bool sjt_ifElse2;

    sjt_dot20 = item;
    dotTemp20 = sjt_dot20->count;
    sjt_compare1 = dotTemp20;
    sjt_compare2 = 0;
    sjt_ifElse2 = sjt_compare1 > sjt_compare2;
    if (sjt_ifElse2) {
        int32_t dotTemp21;
        int32_t dotTemp22;
        sjs_array_char* dotTemp23;
        int32_t dotTemp24;
        int32_t dotTemp28;
        sjs_array_char* dotTemp33;
        int32_t dotTemp34;
        int32_t i;
        int32_t sjt_cast7;
        int32_t sjt_compare3;
        int32_t sjt_compare4;
        sjs_string* sjt_dot21;
        sjs_array_char* sjt_dot22;
        sjs_string* sjt_dot25;
        sjs_array_char* sjt_dot29;
        int32_t sjt_forEnd3;
        int32_t sjt_forStart3;
        int32_t sjt_functionParam17;
        char sjt_functionParam18;
        bool sjt_ifElse3;
        int32_t sjt_math10;
        int32_t sjt_math11;
        int32_t sjt_math12;
        int32_t sjt_math9;

        dotTemp21 = _parent->count;
        sjt_math11 = dotTemp21;
        sjt_dot21 = item;
        dotTemp22 = sjt_dot21->count;
        sjt_math12 = dotTemp22;
        sjt_math9 = sjt_math11 + sjt_math12;
        sjt_math10 = 1;
        sjt_compare3 = sjt_math9 + sjt_math10;
        dotTemp23 = &_parent->data;
        sjt_dot22 = dotTemp23;
        dotTemp24 = sjt_dot22->size;
        sjt_compare4 = dotTemp24;
        sjt_ifElse3 = sjt_compare3 > sjt_compare4;
        if (sjt_ifElse3) {
            sjs_array_char* dotTemp25;
            int32_t dotTemp26;
            int32_t dotTemp27;
            sjs_array_char* sjt_dot23;
            sjs_string* sjt_dot24;
            int32_t sjt_functionParam12;
            int32_t sjt_math13;
            int32_t sjt_math14;
            int32_t sjt_math15;
            int32_t sjt_math16;

            dotTemp25 = &_parent->data;
            sjt_dot23 = dotTemp25;
            dotTemp26 = _parent->count;
            sjt_math15 = dotTemp26;
            sjt_dot24 = item;
            dotTemp27 = sjt_dot24->count;
            sjt_math16 = dotTemp27;
            sjt_math13 = sjt_math15 + sjt_math16;
            sjt_math14 = 1;
            sjt_functionParam12 = sjt_math13 + sjt_math14;
            sjf_array_char_grow(sjt_dot23, sjt_functionParam12);
        }

        sjt_forStart3 = 0;
        i = sjt_forStart3;
        sjt_dot25 = item;
        dotTemp28 = sjt_dot25->count;
        sjt_forEnd3 = dotTemp28;
        while (i < sjt_forEnd3) {
            sjs_array_char* dotTemp29;
            int32_t dotTemp30;
            int32_t dotTemp32;
            sjs_array_char* sjt_dot26;
            sjs_string* sjt_dot27;
            int32_t sjt_functionParam13;
            char sjt_functionParam14;
            int32_t sjt_functionParam16;
            int32_t sjt_math17;
            int32_t sjt_math18;

            dotTemp29 = &_parent->data;
            sjt_dot26 = dotTemp29;
            dotTemp30 = _parent->count;
            sjt_functionParam13 = dotTemp30;
            sjt_dot27 = item;
            sjt_functionParam16 = i;
            sjf_string_getAt(sjt_dot27, sjt_functionParam16, &sjt_functionParam14);
            sjf_array_char_setAt(sjt_dot26, sjt_functionParam13, sjt_functionParam14);
            dotTemp32 = _parent->count;
            sjt_math17 = dotTemp32;
            sjt_math18 = 1;
            _parent->count = sjt_math17 + sjt_math18;
            i++;
        }

        dotTemp33 = &_parent->data;
        sjt_dot29 = dotTemp33;
        dotTemp34 = _parent->count;
        sjt_functionParam17 = dotTemp34;
        sjt_cast7 = 0;
        sjt_functionParam18 = (char)sjt_cast7;
        sjf_array_char_setAt(sjt_dot29, sjt_functionParam17, sjt_functionParam18);
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
    sjs_array_char* dotTemp31;
    sjs_array_char* sjt_dot28;
    int32_t sjt_functionParam15;

    dotTemp31 = &_parent->data;
    sjt_dot28 = dotTemp31;
    sjt_functionParam15 = index;
    sjf_array_char_getAt(sjt_dot28, sjt_functionParam15, &(*_return));
}

void sjf_string_heap(sjs_string_heap* _this) {
}

void sji_element_destroy(sji_element* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

void sji_surface_destroy(sji_surface* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
    sjf_anon5(&sjv_style);
    sjf_anon4(&sjv_convert);
    sjf_anon3(&sjv_random);
    sjf_anon2(&sjv_parse);
    sjf_anon1(&sjv_console);
    sjv_root = 0;
    if (sjv_root != 0) {
        sjv_root->_refCount++;
    }

    sjv_rootSurface = 0;
    if (sjv_rootSurface != 0) {
        sjv_rootSurface->_refCount++;
    }

    sjv_frame = 0;
    sjt_cast1 = (sjs_sdlSurace_heap*)malloc(sizeof(sjs_sdlSurace_heap));
    sjt_cast1->_refCount = 1;
    sjt_cast1->size.w = 640;
    sjt_cast1->size.h = 480;
    sjf_size(&sjt_cast1->size);
    sjt_cast2 = 0;
    sjt_cast1->win = (uintptr_t)sjt_cast2;
    sjt_cast3 = 0;
    sjt_cast1->ren = (uintptr_t)sjt_cast3;
    sjf_sdlSurace_heap(sjt_cast1);
    if (sjv_rootSurface != 0) {
        sjv_rootSurface->_refCount--;
        if (sjv_rootSurface->_refCount <= 0) {
            sji_surface_destroy(sjv_rootSurface);
        }
    }

    sjv_rootSurface = (sji_surface*)sjf_sdlSurace_heap_as_sji_surface(sjt_cast1);
    sjt_cast4 = (sjs_element_heap*)malloc(sizeof(sjs_element_heap));
    sjt_cast4->_refCount = 1;
    sjt_cast4->children.size = 1;
    sjt_cast5 = 0;
    sjt_cast4->children.data = (uintptr_t)sjt_cast5;
    sjt_cast4->children._isGlobal = false;
    sjf_array_heap_element(&sjt_cast4->children);
    sjt_functionParam6 = 0;
    sjt_cast6 = (sjs_button_heap*)malloc(sizeof(sjs_button_heap));
    sjt_cast6->_refCount = 1;
    sjt_cast6->text.count = 0;
    sjt_cast6->text.data.size = 1;
    sjt_cast6->text.data.data = (uintptr_t)sjg_string4;
    sjt_cast6->text.data._isGlobal = false;
    sjf_array_char(&sjt_cast6->text.data);
    sjf_string(&sjt_cast6->text);
    sjt_dot17 = &sjv_style;
    sjt_functionParam10 = 0;
    sjf_anon5_getFont(sjt_dot17, sjt_functionParam10, &sjt_cast6->font);
    sjt_cast6->rect.x = 0;
    sjt_cast6->rect.y = 0;
    sjt_cast6->rect.w = 0;
    sjt_cast6->rect.h = 0;
    sjf_rect(&sjt_cast6->rect);
    sjt_cast6->offset = 0;
    sjf_button_heap(sjt_cast6);
    sjt_functionParam7 = (sji_element*)sjf_button_heap_as_sji_element(sjt_cast6);
    sjf_array_heap_element_initAt(&sjt_cast4->children, sjt_functionParam6, sjt_functionParam7);
    sjt_cast4->rect.x = 0;
    sjt_cast4->rect.y = 0;
    sjt_cast4->rect.w = 0;
    sjt_cast4->rect.h = 0;
    sjf_rect(&sjt_cast4->rect);
    sjf_element_heap(sjt_cast4);
    sjt_value1 = (sji_element*)sjf_element_heap_as_sji_element(sjt_cast4);
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
        sjf_sdlSurace_destroy((sjs_sdlSurace*)(((char*)sjt_cast1) + sizeof(intptr_t)));
    }
    sjt_cast4->_refCount--;
    if (sjt_cast4->_refCount <= 0) {
        sjf_element_destroy((sjs_element*)(((char*)sjt_cast4) + sizeof(intptr_t)));
    }
    sjt_cast6->_refCount--;
    if (sjt_cast6->_refCount <= 0) {
        sjf_button_destroy((sjs_button*)(((char*)sjt_cast6) + sizeof(intptr_t)));
    }
    sjt_functionParam7->_refCount--;
    if (sjt_functionParam7->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam7);
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
    if (sjv_rootSurface != 0) {
        sjv_rootSurface->_refCount--;
        if (sjv_rootSurface->_refCount <= 0) {
            sji_surface_destroy(sjv_rootSurface);
        }
    }
    sjf_anon1_destroy(&sjv_console);
    sjf_anon4_destroy(&sjv_convert);
    sjf_anon2_destroy(&sjv_parse);
    sjf_anon3_destroy(&sjv_random);
    sjf_anon5_destroy(&sjv_style);
}
