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
const char* sjg_string11 = "setRect - 2";
const char* sjg_string13 = "render - 2";
const char* sjg_string4 = "";
const char* sjg_string5 = "48px serif";
const char* sjg_string6 = "48px serif";
const char* sjg_string7 = "assets/hello2.bmp";
const char* sjg_string9 = "mainLoop - ";

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
#define sjs_sdlSurface_typeId 18
#define sjs_rect_typeId 19
#define sjs_rect_heap_typeId 20
#define sjs_color_typeId 21
#define sjs_color_heap_typeId 22
#define sjs_texture_typeId 23
#define sjs_texture_heap_typeId 24
#define sjs_image_typeId 25
#define sjs_image_heap_typeId 26
#define sji_surface_typeId 27
#define sjs_sdlSurface_heap_typeId 28
#define sjs_array_heap_element_typeId 29
#define sjs_array_heap_element_heap_typeId 30
#define sjs_fillElement_typeId 31
#define sji_element_typeId 32
#define sjs_fillElement_heap_typeId 33
#define sjs_buttonElement_typeId 34
#define sjs_buttonElement_heap_typeId 35
#define sjs_imageElement_typeId 36
#define sjs_imageElement_heap_typeId 37

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
typedef struct td_sjs_sdlSurface sjs_sdlSurface;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_rect_heap sjs_rect_heap;
typedef struct td_sjs_color sjs_color;
typedef struct td_sjs_color_heap sjs_color_heap;
typedef struct td_sjs_texture sjs_texture;
typedef struct td_sjs_texture_heap sjs_texture_heap;
typedef struct td_sjs_image sjs_image;
typedef struct td_sjs_image_heap sjs_image_heap;
typedef struct td_sji_surface sji_surface;
typedef struct td_sjs_sdlSurface_heap sjs_sdlSurface_heap;
typedef struct td_sjs_array_heap_element sjs_array_heap_element;
typedef struct td_sjs_array_heap_element_heap sjs_array_heap_element_heap;
typedef struct td_sjs_fillElement sjs_fillElement;
typedef struct td_sji_element sji_element;
typedef struct td_sjs_fillElement_heap sjs_fillElement_heap;
typedef struct td_sjs_buttonElement sjs_buttonElement;
typedef struct td_sjs_buttonElement_heap sjs_buttonElement_heap;
typedef struct td_sjs_imageElement sjs_imageElement;
typedef struct td_sjs_imageElement_heap sjs_imageElement_heap;

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

struct td_sjs_sdlSurface {
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

struct td_sjs_texture {
    uintptr_t tex;
};

struct td_sjs_texture_heap {
    intptr_t _refCount;
    uintptr_t tex;
};

struct td_sjs_image {
    sjs_texture texture;
    sjs_rect rect;
};

struct td_sjs_image_heap {
    intptr_t _refCount;
    sjs_texture texture;
    sjs_rect rect;
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
    void (*drawImage)(void* _parent, sjs_rect* rect, sjs_image* image);
    void (*getTexture)(void* _parent, sjs_string* src, sjs_texture* _return);
    void (*getTexture_heap)(void* _parent, sjs_string* src, sjs_texture_heap** _return);
};

struct td_sjs_sdlSurface_heap {
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

struct td_sjs_fillElement {
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

struct td_sjs_fillElement_heap {
    intptr_t _refCount;
    sjs_array_heap_element children;
    sjs_rect rect;
};

struct td_sjs_buttonElement {
    sjs_string text;
    sjs_string font;
    sjs_rect rect;
    int32_t offset;
};

struct td_sjs_buttonElement_heap {
    intptr_t _refCount;
    sjs_string text;
    sjs_string font;
    sjs_rect rect;
    int32_t offset;
};

struct td_sjs_imageElement {
    sjs_image image;
    sjs_rect rect;
};

struct td_sjs_imageElement_heap {
    intptr_t _refCount;
    sjs_image image;
    sjs_rect rect;
};


	
	
	
	
	
	
	
	

#ifdef EMSCRIPTEN
	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
#endif	
	SDL_Texture* renderText(const char* message, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);

sjs_string sjt_call6;
sjs_sdlSurface_heap* sjt_cast1;
int32_t sjt_cast4;
int32_t sjt_cast5;
sjs_fillElement_heap* sjt_cast6;
int32_t sjt_cast7;
sjs_buttonElement_heap* sjt_cast8;
sjs_imageElement_heap* sjt_cast9;
sjs_anon5* sjt_dot27;
sji_surface* sjt_dot30;
int32_t sjt_functionParam10;
int32_t sjt_functionParam11;
sji_element* sjt_functionParam12;
int32_t sjt_functionParam6;
sji_element* sjt_functionParam7;
sjs_string* sjt_interfaceParam7;
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
void sjf_buttonElement(sjs_buttonElement* _this);
sjs_object* sjf_buttonElement_asInterface(sjs_buttonElement* _this, int typeId);
sji_element* sjf_buttonElement_as_sji_element(sjs_buttonElement* _this);
void sjf_buttonElement_copy(sjs_buttonElement* _this, sjs_buttonElement* to);
void sjf_buttonElement_destroy(sjs_buttonElement* _this);
void sjf_buttonElement_heap(sjs_buttonElement_heap* _this);
sjs_object* sjf_buttonElement_heap_asInterface(sjs_buttonElement_heap* _this, int typeId);
sji_element* sjf_buttonElement_heap_as_sji_element(sjs_buttonElement_heap* _this);
void sjf_buttonElement_render(sjs_buttonElement* _parent, sji_surface* surface);
void sjf_buttonElement_setRect(sjs_buttonElement* _parent, sjs_rect* rect_);
void sjf_color(sjs_color* _this);
void sjf_color_copy(sjs_color* _this, sjs_color* to);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color_heap* _this);
void sjf_fillElement(sjs_fillElement* _this);
sjs_object* sjf_fillElement_asInterface(sjs_fillElement* _this, int typeId);
sji_element* sjf_fillElement_as_sji_element(sjs_fillElement* _this);
void sjf_fillElement_copy(sjs_fillElement* _this, sjs_fillElement* to);
void sjf_fillElement_destroy(sjs_fillElement* _this);
void sjf_fillElement_heap(sjs_fillElement_heap* _this);
sjs_object* sjf_fillElement_heap_asInterface(sjs_fillElement_heap* _this, int typeId);
sji_element* sjf_fillElement_heap_as_sji_element(sjs_fillElement_heap* _this);
void sjf_fillElement_render(sjs_fillElement* _parent, sji_surface* surface);
void sjf_fillElement_setRect(sjs_fillElement* _parent, sjs_rect* rect_);
void sjf_image(sjs_image* _this);
void sjf_imageElement(sjs_imageElement* _this);
sjs_object* sjf_imageElement_asInterface(sjs_imageElement* _this, int typeId);
sji_element* sjf_imageElement_as_sji_element(sjs_imageElement* _this);
void sjf_imageElement_copy(sjs_imageElement* _this, sjs_imageElement* to);
void sjf_imageElement_destroy(sjs_imageElement* _this);
void sjf_imageElement_heap(sjs_imageElement_heap* _this);
sjs_object* sjf_imageElement_heap_asInterface(sjs_imageElement_heap* _this, int typeId);
sji_element* sjf_imageElement_heap_as_sji_element(sjs_imageElement_heap* _this);
void sjf_imageElement_render(sjs_imageElement* _parent, sji_surface* surface);
void sjf_imageElement_setRect(sjs_imageElement* _parent, sjs_rect* rect_);
void sjf_image_copy(sjs_image* _this, sjs_image* to);
void sjf_image_destroy(sjs_image* _this);
void sjf_image_heap(sjs_image_heap* _this);
void sjf_mainLoop(void);
void sjf_onClick(double timestemp, int32_t x, int32_t y);
void sjf_rect(sjs_rect* _this);
void sjf_rect_addMargin(sjs_rect* _parent, int32_t l, int32_t t, int32_t r, int32_t b, sjs_rect* _return);
void sjf_rect_addMargin_heap(sjs_rect* _parent, int32_t l, int32_t t, int32_t r, int32_t b, sjs_rect_heap** _return);
void sjf_rect_copy(sjs_rect* _this, sjs_rect* to);
void sjf_rect_destroy(sjs_rect* _this);
void sjf_rect_heap(sjs_rect_heap* _this);
void sjf_runLoop(void);
void sjf_sdlSurface(sjs_sdlSurface* _this);
sjs_object* sjf_sdlSurface_asInterface(sjs_sdlSurface* _this, int typeId);
sji_surface* sjf_sdlSurface_as_sji_surface(sjs_sdlSurface* _this);
void sjf_sdlSurface_clear(sjs_sdlSurface* _parent);
void sjf_sdlSurface_copy(sjs_sdlSurface* _this, sjs_sdlSurface* to);
void sjf_sdlSurface_destroy(sjs_sdlSurface* _this);
void sjf_sdlSurface_drawImage(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_image* image);
void sjf_sdlSurface_fillRect(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_color* color);
void sjf_sdlSurface_getSize(sjs_sdlSurface* _parent, sjs_size** _return);
void sjf_sdlSurface_getTexture(sjs_sdlSurface* _parent, sjs_string* src, sjs_texture* _return);
void sjf_sdlSurface_getTexture_heap(sjs_sdlSurface* _parent, sjs_string* src, sjs_texture_heap** _return);
void sjf_sdlSurface_heap(sjs_sdlSurface_heap* _this);
sjs_object* sjf_sdlSurface_heap_asInterface(sjs_sdlSurface_heap* _this, int typeId);
sji_surface* sjf_sdlSurface_heap_as_sji_surface(sjs_sdlSurface_heap* _this);
void sjf_sdlSurface_present(sjs_sdlSurface* _parent);
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
void sjf_texture(sjs_texture* _this);
void sjf_texture_copy(sjs_texture* _this, sjs_texture* to);
void sjf_texture_destroy(sjs_texture* _this);
void sjf_texture_getSize(sjs_texture* _parent, sjs_size* _return);
void sjf_texture_getSize_heap(sjs_texture* _parent, sjs_size_heap** _return);
void sjf_texture_heap(sjs_texture_heap* _this);
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
    int32_t sjt_cast11;
    int32_t sjt_math43;
    int32_t sjt_math44;
    int32_t sjv_count;
    uintptr_t sjv_data;

    sjv_count = 0;
    sjt_cast11 = 0;
    sjv_data = (uintptr_t)sjt_cast11;
    
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
    sjt_math43 = sjv_count;
    sjt_math44 = 1;
    _return->data.size = sjt_math43 + sjt_math44;
    _return->data.data = sjv_data;
    _return->data._isGlobal = false;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_anon4_i32toString_heap(sjs_anon4* _parent, int32_t val, int32_t base, int32_t minLength, sjs_string_heap** _return) {
    int32_t sjt_cast12;
    int32_t sjt_math45;
    int32_t sjt_math46;
    int32_t sjv_count;
    uintptr_t sjv_data;

    sjv_count = 0;
    sjt_cast12 = 0;
    sjv_data = (uintptr_t)sjt_cast12;
    
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
    sjt_math45 = sjv_count;
    sjt_math46 = 1;
    (*_return)->data.size = sjt_math45 + sjt_math46;
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

void sjf_buttonElement(sjs_buttonElement* _this) {
    sjs_anon5* sjt_dot20;
    int32_t sjt_functionParam8;
    sjs_string void1;

    sjt_dot20 = &sjv_style;
    sjt_functionParam8 = 1;
    sjf_anon5_getFont(sjt_dot20, sjt_functionParam8, &void1);

    sjf_string_destroy(&void1);
}

sjs_object* sjf_buttonElement_asInterface(sjs_buttonElement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_buttonElement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_buttonElement_as_sji_element(sjs_buttonElement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_buttonElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_buttonElement_asInterface;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_buttonElement_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_buttonElement_render;

    return _interface;
}

void sjf_buttonElement_copy(sjs_buttonElement* _this, sjs_buttonElement* to) {
    sjf_string_copy(&_this->text, &to->text);
    sjf_string_copy(&_this->font, &to->font);
    sjf_rect_copy(&_this->rect, &to->rect);
    _this->offset = to->offset;
}

void sjf_buttonElement_destroy(sjs_buttonElement* _this) {
}

void sjf_buttonElement_heap(sjs_buttonElement_heap* _this) {
    sjs_anon5* sjt_dot26;
    int32_t sjt_functionParam9;
    sjs_string void2;

    sjt_dot26 = &sjv_style;
    sjt_functionParam9 = 1;
    sjf_anon5_getFont(sjt_dot26, sjt_functionParam9, &void2);

    sjf_string_destroy(&void2);
}

sjs_object* sjf_buttonElement_heap_asInterface(sjs_buttonElement_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_buttonElement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_buttonElement_heap_as_sji_element(sjs_buttonElement_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_buttonElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_buttonElement_heap_asInterface;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_buttonElement_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_buttonElement_render;

    return _interface;
}

void sjf_buttonElement_render(sjs_buttonElement* _parent, sji_surface* surface) {
    sjs_rect* dotTemp20;
    int32_t dotTemp21;
    sjs_rect* dotTemp22;
    int32_t dotTemp23;
    int32_t dotTemp24;
    sjs_rect* dotTemp25;
    int32_t dotTemp26;
    sjs_rect* dotTemp27;
    int32_t dotTemp28;
    int32_t dotTemp29;
    int32_t dotTemp30;
    sjs_rect sjt_call4;
    sjs_color sjt_call5;
    sji_surface* sjt_dot21;
    sjs_rect* sjt_dot22;
    sjs_rect* sjt_dot23;
    sjs_rect* sjt_dot24;
    sjs_rect* sjt_dot25;
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

    sjt_dot21 = surface;
    dotTemp20 = &_parent->rect;
    sjt_dot22 = dotTemp20;
    dotTemp21 = sjt_dot22->x;
    sjt_call4.x = dotTemp21;
    dotTemp22 = &_parent->rect;
    sjt_dot23 = dotTemp22;
    dotTemp23 = sjt_dot23->y;
    sjt_math1 = dotTemp23;
    dotTemp24 = _parent->offset;
    sjt_math2 = dotTemp24;
    sjt_call4.y = sjt_math1 + sjt_math2;
    dotTemp25 = &_parent->rect;
    sjt_dot24 = dotTemp25;
    dotTemp26 = sjt_dot24->w;
    sjt_call4.w = dotTemp26;
    dotTemp27 = &_parent->rect;
    sjt_dot25 = dotTemp27;
    dotTemp28 = sjt_dot25->h;
    sjt_math3 = dotTemp28;
    sjt_math5 = 2;
    dotTemp29 = _parent->offset;
    sjt_math6 = dotTemp29;
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
    sjt_dot21->fillRect((void*)(((char*)sjt_dot21->_parent) + sizeof(intptr_t)), sjt_interfaceParam3, sjt_interfaceParam4);
    dotTemp30 = _parent->offset;
    sjt_math7 = dotTemp30;
    sjt_math8 = 1;
    _parent->offset = sjt_math7 + sjt_math8;

    sjf_rect_destroy(&sjt_call4);
    sjf_color_destroy(&sjt_call5);
}

void sjf_buttonElement_setRect(sjs_buttonElement* _parent, sjs_rect* rect_) {
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

void sjf_fillElement(sjs_fillElement* _this) {
}

sjs_object* sjf_fillElement_asInterface(sjs_fillElement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_fillElement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_fillElement_as_sji_element(sjs_fillElement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_fillElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_fillElement_asInterface;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_fillElement_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_fillElement_render;

    return _interface;
}

void sjf_fillElement_copy(sjs_fillElement* _this, sjs_fillElement* to) {
    sjf_array_heap_element_copy(&_this->children, &to->children);
    sjf_rect_copy(&_this->rect, &to->rect);
}

void sjf_fillElement_destroy(sjs_fillElement* _this) {
}

void sjf_fillElement_heap(sjs_fillElement_heap* _this) {
}

sjs_object* sjf_fillElement_heap_asInterface(sjs_fillElement_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_fillElement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_fillElement_heap_as_sji_element(sjs_fillElement_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_fillElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_fillElement_heap_asInterface;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_fillElement_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_fillElement_render;

    return _interface;
}

void sjf_fillElement_render(sjs_fillElement* _parent, sji_surface* surface) {
    sjs_array_heap_element* dotTemp17;
    int32_t dotTemp18;
    int32_t i;
    sjs_string sjt_call3;
    sjs_anon1* sjt_dot16;
    sjs_array_heap_element* sjt_dot17;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;
    sjs_string* sjt_functionParam4;

    sjt_dot16 = &sjv_console;
    sjt_call3.count = 10;
    sjt_call3.data.size = 11;
    sjt_call3.data.data = (uintptr_t)sjg_string13;
    sjt_call3.data._isGlobal = false;
    sjf_array_char(&sjt_call3.data);
    sjf_string(&sjt_call3);
    sjt_functionParam4 = &sjt_call3;
    sjf_anon1_write(sjt_dot16, sjt_functionParam4);
    sjt_forStart2 = 0;
    i = sjt_forStart2;
    dotTemp17 = &_parent->children;
    sjt_dot17 = dotTemp17;
    dotTemp18 = sjt_dot17->size;
    sjt_forEnd2 = dotTemp18;
    while (i < sjt_forEnd2) {
        sjs_array_heap_element* dotTemp19;
        sjs_array_heap_element* sjt_dot18;
        sji_element* sjt_dot19;
        int32_t sjt_functionParam5;
        sji_surface* sjt_interfaceParam2;
        sji_element* sjv_child;

        dotTemp19 = &_parent->children;
        sjt_dot18 = dotTemp19;
        sjt_functionParam5 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot18, sjt_functionParam5, &sjv_child);
        sjt_dot19 = sjv_child;
        sjt_interfaceParam2 = surface;
        sjt_interfaceParam2->_refCount++;
        sjt_dot19->render((void*)(((char*)sjt_dot19->_parent) + sizeof(intptr_t)), sjt_interfaceParam2);
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

void sjf_fillElement_setRect(sjs_fillElement* _parent, sjs_rect* rect_) {
    sjs_array_heap_element* dotTemp13;
    int32_t dotTemp14;
    int32_t i;
    sjs_string sjt_call2;
    sjs_anon1* sjt_dot12;
    sjs_array_heap_element* sjt_dot13;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    sjs_string* sjt_functionParam2;

    sjt_dot12 = &sjv_console;
    sjt_call2.count = 11;
    sjt_call2.data.size = 12;
    sjt_call2.data.data = (uintptr_t)sjg_string11;
    sjt_call2.data._isGlobal = false;
    sjf_array_char(&sjt_call2.data);
    sjf_string(&sjt_call2);
    sjt_functionParam2 = &sjt_call2;
    sjf_anon1_write(sjt_dot12, sjt_functionParam2);
    sjf_rect_copy(&_parent->rect, rect_);
    sjt_forStart1 = 0;
    i = sjt_forStart1;
    dotTemp13 = &_parent->children;
    sjt_dot13 = dotTemp13;
    dotTemp14 = sjt_dot13->size;
    sjt_forEnd1 = dotTemp14;
    while (i < sjt_forEnd1) {
        sjs_array_heap_element* dotTemp15;
        sjs_rect* dotTemp16;
        sjs_array_heap_element* sjt_dot14;
        sji_element* sjt_dot15;
        int32_t sjt_functionParam3;
        sjs_rect* sjt_interfaceParam1;
        sji_element* sjv_child;

        dotTemp15 = &_parent->children;
        sjt_dot14 = dotTemp15;
        sjt_functionParam3 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot14, sjt_functionParam3, &sjv_child);
        sjt_dot15 = sjv_child;
        dotTemp16 = &_parent->rect;
        sjt_interfaceParam1 = dotTemp16;
        sjt_dot15->setRect((void*)(((char*)sjt_dot15->_parent) + sizeof(intptr_t)), sjt_interfaceParam1);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }

    sjf_string_destroy(&sjt_call2);
}

void sjf_image(sjs_image* _this) {
    int32_t dotTemp1;
    int32_t dotTemp2;
    bool sjt_and1;
    bool sjt_and2;
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    sjs_rect* sjt_dot2;
    sjs_rect* sjt_dot3;
    bool sjt_ifElse1;

    sjt_dot2 = &_this->rect;
    dotTemp1 = sjt_dot2->w;
    sjt_compare1 = dotTemp1;
    sjt_compare2 = 0;
    sjt_and1 = sjt_compare1 == sjt_compare2;
    sjt_dot3 = &_this->rect;
    dotTemp2 = sjt_dot3->h;
    sjt_compare3 = dotTemp2;
    sjt_compare4 = 0;
    sjt_and2 = sjt_compare3 == sjt_compare4;
    sjt_ifElse1 = sjt_and1 && sjt_and2;
    if (sjt_ifElse1) {
        int32_t dotTemp3;
        int32_t dotTemp4;
        sjs_texture* sjt_dot4;
        sjs_size* sjt_dot5;
        sjs_size* sjt_dot6;
        sjs_size sjv_size;

        sjt_dot4 = &_this->texture;
        sjf_texture_getSize(sjt_dot4, &sjv_size);
        _this->rect.x = 0;
        _this->rect.y = 0;
        sjt_dot5 = &sjv_size;
        dotTemp3 = sjt_dot5->w;
        _this->rect.w = dotTemp3;
        sjt_dot6 = &sjv_size;
        dotTemp4 = sjt_dot6->h;
        _this->rect.h = dotTemp4;
        sjf_rect(&_this->rect);

        sjf_size_destroy(&sjv_size);
    }
}

void sjf_imageElement(sjs_imageElement* _this) {
}

sjs_object* sjf_imageElement_asInterface(sjs_imageElement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_imageElement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_imageElement_as_sji_element(sjs_imageElement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_imageElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_imageElement_asInterface;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_imageElement_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_imageElement_render;

    return _interface;
}

void sjf_imageElement_copy(sjs_imageElement* _this, sjs_imageElement* to) {
    sjf_image_copy(&_this->image, &to->image);
    sjf_rect_copy(&_this->rect, &to->rect);
}

void sjf_imageElement_destroy(sjs_imageElement* _this) {
}

void sjf_imageElement_heap(sjs_imageElement_heap* _this) {
}

sjs_object* sjf_imageElement_heap_asInterface(sjs_imageElement_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_imageElement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_imageElement_heap_as_sji_element(sjs_imageElement_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_imageElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_imageElement_heap_asInterface;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_imageElement_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_imageElement_render;

    return _interface;
}

void sjf_imageElement_render(sjs_imageElement* _parent, sji_surface* surface) {
    sjs_rect* dotTemp39;
    sjs_image* dotTemp40;
    sji_surface* sjt_dot29;
    sjs_rect* sjt_interfaceParam5;
    sjs_image* sjt_interfaceParam6;

    sjt_dot29 = surface;
    dotTemp39 = &_parent->rect;
    sjt_interfaceParam5 = dotTemp39;
    dotTemp40 = &_parent->image;
    sjt_interfaceParam6 = dotTemp40;
    sjt_dot29->drawImage((void*)(((char*)sjt_dot29->_parent) + sizeof(intptr_t)), sjt_interfaceParam5, sjt_interfaceParam6);
}

void sjf_imageElement_setRect(sjs_imageElement* _parent, sjs_rect* rect_) {
    sjs_rect* sjt_dot28;
    int32_t sjt_functionParam13;
    int32_t sjt_functionParam14;
    int32_t sjt_functionParam15;
    int32_t sjt_functionParam16;

    sjt_dot28 = rect_;
    sjt_functionParam13 = 10;
    sjt_functionParam14 = 10;
    sjt_functionParam15 = 10;
    sjt_functionParam16 = 10;
    sjf_rect_addMargin(sjt_dot28, sjt_functionParam13, sjt_functionParam14, sjt_functionParam15, sjt_functionParam16, &_parent->rect);
}

void sjf_image_copy(sjs_image* _this, sjs_image* to) {
    sjf_texture_copy(&_this->texture, &to->texture);
    sjf_rect_copy(&_this->rect, &to->rect);
}

void sjf_image_destroy(sjs_image* _this) {
}

void sjf_image_heap(sjs_image_heap* _this) {
    sjs_rect* dotTemp5;
    int32_t dotTemp6;
    sjs_rect* dotTemp7;
    int32_t dotTemp8;
    bool sjt_and3;
    bool sjt_and4;
    int32_t sjt_compare5;
    int32_t sjt_compare6;
    int32_t sjt_compare7;
    int32_t sjt_compare8;
    sjs_rect* sjt_dot7;
    sjs_rect* sjt_dot8;
    bool sjt_ifElse2;

    dotTemp5 = &_this->rect;
    sjt_dot7 = dotTemp5;
    dotTemp6 = sjt_dot7->w;
    sjt_compare5 = dotTemp6;
    sjt_compare6 = 0;
    sjt_and3 = sjt_compare5 == sjt_compare6;
    dotTemp7 = &_this->rect;
    sjt_dot8 = dotTemp7;
    dotTemp8 = sjt_dot8->h;
    sjt_compare7 = dotTemp8;
    sjt_compare8 = 0;
    sjt_and4 = sjt_compare7 == sjt_compare8;
    sjt_ifElse2 = sjt_and3 && sjt_and4;
    if (sjt_ifElse2) {
        int32_t dotTemp10;
        int32_t dotTemp11;
        sjs_texture* dotTemp9;
        sjs_size* sjt_dot10;
        sjs_size* sjt_dot11;
        sjs_texture* sjt_dot9;
        sjs_size sjv_size;

        dotTemp9 = &_this->texture;
        sjt_dot9 = dotTemp9;
        sjf_texture_getSize(sjt_dot9, &sjv_size);
        _this->rect.x = 0;
        _this->rect.y = 0;
        sjt_dot10 = &sjv_size;
        dotTemp10 = sjt_dot10->w;
        _this->rect.w = dotTemp10;
        sjt_dot11 = &sjv_size;
        dotTemp11 = sjt_dot11->h;
        _this->rect.h = dotTemp11;
        sjf_rect(&_this->rect);

        sjf_size_destroy(&sjv_size);
    }
}

void sjf_mainLoop(void) {
    int32_t dotTemp56;
    int32_t dotTemp57;
    sjs_string sjt_call7;
    sjs_string sjt_call8;
    sjs_anon1* sjt_dot31;
    sjs_string* sjt_dot32;
    sjs_anon4* sjt_dot43;
    sji_surface* sjt_dot44;
    sji_surface* sjt_dot45;
    sjs_size* sjt_dot46;
    sjs_size* sjt_dot47;
    sji_element* sjt_dot48;
    sji_element* sjt_dot49;
    sji_surface* sjt_dot50;
    sjs_string* sjt_functionParam17;
    sjs_string* sjt_functionParam25;
    int32_t sjt_functionParam26;
    int32_t sjt_functionParam27;
    int32_t sjt_functionParam28;
    sjs_rect* sjt_interfaceParam8;
    sji_surface* sjt_interfaceParam9;
    int32_t sjt_math47;
    int32_t sjt_math48;
    sjs_rect sjv_rect;
    sjs_size* sjv_size;

    sjt_dot31 = &sjv_console;
    sjt_call7.count = 11;
    sjt_call7.data.size = 12;
    sjt_call7.data.data = (uintptr_t)sjg_string9;
    sjt_call7.data._isGlobal = false;
    sjf_array_char(&sjt_call7.data);
    sjf_string(&sjt_call7);
    sjt_dot32 = &sjt_call7;
    sjt_dot43 = &sjv_convert;
    sjt_functionParam26 = sjv_frame;
    sjt_functionParam27 = 10;
    sjt_functionParam28 = 0;
    sjf_anon4_i32toString(sjt_dot43, sjt_functionParam26, sjt_functionParam27, sjt_functionParam28, &sjt_call8);
    sjt_functionParam25 = &sjt_call8;
    sjf_string_add(sjt_dot32, sjt_functionParam25, &sjt_functionParam17);
    sjf_anon1_write(sjt_dot31, sjt_functionParam17);
    sjt_dot44 = sjv_rootSurface;
    sjt_dot44->clear((void*)(((char*)sjt_dot44->_parent) + sizeof(intptr_t)));
    sjt_dot45 = sjv_rootSurface;
    sjt_dot45->getSize((void*)(((char*)sjt_dot45->_parent) + sizeof(intptr_t)), &sjv_size);
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot46 = sjv_size;
    dotTemp56 = sjt_dot46->w;
    sjv_rect.w = dotTemp56;
    sjt_dot47 = sjv_size;
    dotTemp57 = sjt_dot47->h;
    sjv_rect.h = dotTemp57;
    sjf_rect(&sjv_rect);
    sjt_dot48 = sjv_root;
    sjt_interfaceParam8 = &sjv_rect;
    sjt_dot48->setRect((void*)(((char*)sjt_dot48->_parent) + sizeof(intptr_t)), sjt_interfaceParam8);
    sjt_dot49 = sjv_root;
    sjt_interfaceParam9 = sjv_rootSurface;
    sjt_interfaceParam9->_refCount++;
    sjt_dot49->render((void*)(((char*)sjt_dot49->_parent) + sizeof(intptr_t)), sjt_interfaceParam9);
    sjt_dot50 = sjv_rootSurface;
    sjt_dot50->present((void*)(((char*)sjt_dot50->_parent) + sizeof(intptr_t)));
    sjt_math47 = sjv_frame;
    sjt_math48 = 1;
    sjv_frame = sjt_math47 + sjt_math48;

    sjt_interfaceParam9->_refCount--;
    if (sjt_interfaceParam9->_refCount <= 0) {
        sji_surface_destroy(sjt_interfaceParam9);
    }
    sjf_string_destroy(&sjt_call7);
    sjf_string_destroy(&sjt_call8);
    sjf_rect_destroy(&sjv_rect);
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

void sjf_rect_addMargin(sjs_rect* _parent, int32_t l, int32_t t, int32_t r, int32_t b, sjs_rect* _return) {
    int32_t dotTemp31;
    int32_t dotTemp32;
    int32_t dotTemp33;
    int32_t dotTemp34;
    int32_t sjt_math10;
    int32_t sjt_math11;
    int32_t sjt_math12;
    int32_t sjt_math13;
    int32_t sjt_math14;
    int32_t sjt_math15;
    int32_t sjt_math16;
    int32_t sjt_math17;
    int32_t sjt_math18;
    int32_t sjt_math19;
    int32_t sjt_math20;
    int32_t sjt_math9;

    dotTemp31 = _parent->x;
    sjt_math9 = dotTemp31;
    sjt_math10 = l;
    _return->x = sjt_math9 + sjt_math10;
    dotTemp32 = _parent->y;
    sjt_math11 = dotTemp32;
    sjt_math12 = t;
    _return->y = sjt_math11 + sjt_math12;
    dotTemp33 = _parent->w;
    sjt_math15 = dotTemp33;
    sjt_math16 = l;
    sjt_math13 = sjt_math15 - sjt_math16;
    sjt_math14 = r;
    _return->w = sjt_math13 - sjt_math14;
    dotTemp34 = _parent->h;
    sjt_math19 = dotTemp34;
    sjt_math20 = t;
    sjt_math17 = sjt_math19 - sjt_math20;
    sjt_math18 = b;
    _return->h = sjt_math17 - sjt_math18;
    sjf_rect(_return);
}

void sjf_rect_addMargin_heap(sjs_rect* _parent, int32_t l, int32_t t, int32_t r, int32_t b, sjs_rect_heap** _return) {
    int32_t dotTemp35;
    int32_t dotTemp36;
    int32_t dotTemp37;
    int32_t dotTemp38;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjt_math23;
    int32_t sjt_math24;
    int32_t sjt_math25;
    int32_t sjt_math26;
    int32_t sjt_math27;
    int32_t sjt_math28;
    int32_t sjt_math29;
    int32_t sjt_math30;
    int32_t sjt_math31;
    int32_t sjt_math32;

    (*_return) = (sjs_rect_heap*)malloc(sizeof(sjs_rect_heap));
    (*_return)->_refCount = 1;
    dotTemp35 = _parent->x;
    sjt_math21 = dotTemp35;
    sjt_math22 = l;
    (*_return)->x = sjt_math21 + sjt_math22;
    dotTemp36 = _parent->y;
    sjt_math23 = dotTemp36;
    sjt_math24 = t;
    (*_return)->y = sjt_math23 + sjt_math24;
    dotTemp37 = _parent->w;
    sjt_math27 = dotTemp37;
    sjt_math28 = l;
    sjt_math25 = sjt_math27 - sjt_math28;
    sjt_math26 = r;
    (*_return)->w = sjt_math25 - sjt_math26;
    dotTemp38 = _parent->h;
    sjt_math31 = dotTemp38;
    sjt_math32 = t;
    sjt_math29 = sjt_math31 - sjt_math32;
    sjt_math30 = b;
    (*_return)->h = sjt_math29 - sjt_math30;
    sjf_rect_heap((*_return));
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

void sjf_sdlSurface(sjs_sdlSurface* _this) {
    
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

sjs_object* sjf_sdlSurface_asInterface(sjs_sdlSurface* _this, int typeId) {
    switch (typeId) {
        case sji_surface_typeId:  {
            return (sjs_object*)sjf_sdlSurface_as_sji_surface(_this);
        }
    }

    return 0;
}

sji_surface* sjf_sdlSurface_as_sji_surface(sjs_sdlSurface* _this) {
    sji_surface* _interface;
    _interface = (sji_surface*)malloc(sizeof(sji_surface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_sdlSurface_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_sdlSurface_asInterface;
    _interface->clear = (void(*)(void*))sjf_sdlSurface_clear;
    _interface->present = (void(*)(void*))sjf_sdlSurface_present;
    _interface->getSize = (void(*)(void*, sjs_size**))sjf_sdlSurface_getSize;
    _interface->fillRect = (void(*)(void*,sjs_rect*,sjs_color*))sjf_sdlSurface_fillRect;
    _interface->drawImage = (void(*)(void*,sjs_rect*,sjs_image*))sjf_sdlSurface_drawImage;
    _interface->getTexture = (void(*)(void*,sjs_string*, sjs_texture*))sjf_sdlSurface_getTexture;
    _interface->getTexture_heap = (void(*)(void*,sjs_string*, sjs_texture_heap**))sjf_sdlSurface_getTexture_heap;

    return _interface;
}

void sjf_sdlSurface_clear(sjs_sdlSurface* _parent) {
    
		SDL_SetRenderDrawColor((SDL_Renderer*)_parent->ren, 0, 0, 0, 0);
		SDL_RenderClear((SDL_Renderer*)_parent->ren);
	;
}

void sjf_sdlSurface_copy(sjs_sdlSurface* _this, sjs_sdlSurface* to) {
    sjf_size_copy(&_this->size, &to->size);
    _this->win = to->win;
    _this->ren = to->ren;
}

void sjf_sdlSurface_destroy(sjs_sdlSurface* _this) {
    
	SDL_DestroyRenderer((SDL_Renderer*)_this->ren);
	SDL_DestroyWindow((SDL_Window*)_this->win);
;
}

void sjf_sdlSurface_drawImage(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_image* image) {
    
		SDL_RenderCopy((SDL_Renderer*)_parent->ren, (SDL_Texture*)image->texture.tex, (SDL_Rect*)&(image->rect), (SDL_Rect*)rect)
	;
}

void sjf_sdlSurface_fillRect(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_color* color) {
    
		SDL_SetRenderDrawColor((SDL_Renderer*)_parent->ren, color->r, color->g, color->b, color->a);
		SDL_RenderDrawRect((SDL_Renderer*)_parent->ren, (SDL_Rect*)rect);
	;
}

void sjf_sdlSurface_getSize(sjs_sdlSurface* _parent, sjs_size** _return) {
    sjs_size* dotTemp12;

    dotTemp12 = &_parent->size;
    (*_return) = dotTemp12;
}

void sjf_sdlSurface_getTexture(sjs_sdlSurface* _parent, sjs_string* src, sjs_texture* _return) {
    int32_t sjt_cast2;
    uintptr_t sjv_tex;

    sjt_cast2 = 0;
    sjv_tex = (uintptr_t)sjt_cast2;
    
		    SDL_Surface* bmp = SDL_LoadBMP((char*)src->data.data);
		    if (bmp == 0) {
		        printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
		    }

		    sjv_tex = (uintptr_t)SDL_CreateTextureFromSurface((SDL_Renderer*)_parent->ren, bmp);
		    SDL_FreeSurface(bmp);
		    if (sjv_tex == 0) {
		        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
		    }
		;
    _return->tex = sjv_tex;
    sjf_texture(_return);
}

void sjf_sdlSurface_getTexture_heap(sjs_sdlSurface* _parent, sjs_string* src, sjs_texture_heap** _return) {
    int32_t sjt_cast3;
    uintptr_t sjv_tex;

    sjt_cast3 = 0;
    sjv_tex = (uintptr_t)sjt_cast3;
    
		    SDL_Surface* bmp = SDL_LoadBMP((char*)src->data.data);
		    if (bmp == 0) {
		        printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
		    }

		    sjv_tex = (uintptr_t)SDL_CreateTextureFromSurface((SDL_Renderer*)_parent->ren, bmp);
		    SDL_FreeSurface(bmp);
		    if (sjv_tex == 0) {
		        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
		    }
		;
    (*_return) = (sjs_texture_heap*)malloc(sizeof(sjs_texture_heap));
    (*_return)->_refCount = 1;
    (*_return)->tex = sjv_tex;
    sjf_texture_heap((*_return));
}

void sjf_sdlSurface_heap(sjs_sdlSurface_heap* _this) {
    
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

sjs_object* sjf_sdlSurface_heap_asInterface(sjs_sdlSurface_heap* _this, int typeId) {
    switch (typeId) {
        case sji_surface_typeId:  {
            return (sjs_object*)sjf_sdlSurface_heap_as_sji_surface(_this);
        }
    }

    return 0;
}

sji_surface* sjf_sdlSurface_heap_as_sji_surface(sjs_sdlSurface_heap* _this) {
    sji_surface* _interface;
    _interface = (sji_surface*)malloc(sizeof(sji_surface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_sdlSurface_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_sdlSurface_heap_asInterface;
    _interface->clear = (void(*)(void*))sjf_sdlSurface_clear;
    _interface->present = (void(*)(void*))sjf_sdlSurface_present;
    _interface->getSize = (void(*)(void*, sjs_size**))sjf_sdlSurface_getSize;
    _interface->fillRect = (void(*)(void*,sjs_rect*,sjs_color*))sjf_sdlSurface_fillRect;
    _interface->drawImage = (void(*)(void*,sjs_rect*,sjs_image*))sjf_sdlSurface_drawImage;
    _interface->getTexture = (void(*)(void*,sjs_string*, sjs_texture*))sjf_sdlSurface_getTexture;
    _interface->getTexture_heap = (void(*)(void*,sjs_string*, sjs_texture_heap**))sjf_sdlSurface_getTexture_heap;

    return _interface;
}

void sjf_sdlSurface_present(sjs_sdlSurface* _parent) {
    
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
    int32_t dotTemp41;
    int32_t sjt_compare10;
    int32_t sjt_compare9;
    sjs_string* sjt_dot33;
    bool sjt_ifElse3;

    sjt_dot33 = item;
    dotTemp41 = sjt_dot33->count;
    sjt_compare9 = dotTemp41;
    sjt_compare10 = 0;
    sjt_ifElse3 = sjt_compare9 > sjt_compare10;
    if (sjt_ifElse3) {
        int32_t dotTemp42;
        int32_t dotTemp43;
        sjs_array_char* dotTemp44;
        int32_t dotTemp45;
        int32_t dotTemp49;
        sjs_array_char* dotTemp54;
        int32_t dotTemp55;
        int32_t i;
        int32_t sjt_cast10;
        int32_t sjt_compare11;
        int32_t sjt_compare12;
        sjs_string* sjt_dot34;
        sjs_array_char* sjt_dot35;
        sjs_string* sjt_dot38;
        sjs_array_char* sjt_dot42;
        int32_t sjt_forEnd3;
        int32_t sjt_forStart3;
        int32_t sjt_functionParam23;
        char sjt_functionParam24;
        bool sjt_ifElse4;
        int32_t sjt_math33;
        int32_t sjt_math34;
        int32_t sjt_math35;
        int32_t sjt_math36;

        dotTemp42 = _parent->count;
        sjt_math35 = dotTemp42;
        sjt_dot34 = item;
        dotTemp43 = sjt_dot34->count;
        sjt_math36 = dotTemp43;
        sjt_math33 = sjt_math35 + sjt_math36;
        sjt_math34 = 1;
        sjt_compare11 = sjt_math33 + sjt_math34;
        dotTemp44 = &_parent->data;
        sjt_dot35 = dotTemp44;
        dotTemp45 = sjt_dot35->size;
        sjt_compare12 = dotTemp45;
        sjt_ifElse4 = sjt_compare11 > sjt_compare12;
        if (sjt_ifElse4) {
            sjs_array_char* dotTemp46;
            int32_t dotTemp47;
            int32_t dotTemp48;
            sjs_array_char* sjt_dot36;
            sjs_string* sjt_dot37;
            int32_t sjt_functionParam18;
            int32_t sjt_math37;
            int32_t sjt_math38;
            int32_t sjt_math39;
            int32_t sjt_math40;

            dotTemp46 = &_parent->data;
            sjt_dot36 = dotTemp46;
            dotTemp47 = _parent->count;
            sjt_math39 = dotTemp47;
            sjt_dot37 = item;
            dotTemp48 = sjt_dot37->count;
            sjt_math40 = dotTemp48;
            sjt_math37 = sjt_math39 + sjt_math40;
            sjt_math38 = 1;
            sjt_functionParam18 = sjt_math37 + sjt_math38;
            sjf_array_char_grow(sjt_dot36, sjt_functionParam18);
        }

        sjt_forStart3 = 0;
        i = sjt_forStart3;
        sjt_dot38 = item;
        dotTemp49 = sjt_dot38->count;
        sjt_forEnd3 = dotTemp49;
        while (i < sjt_forEnd3) {
            sjs_array_char* dotTemp50;
            int32_t dotTemp51;
            int32_t dotTemp53;
            sjs_array_char* sjt_dot39;
            sjs_string* sjt_dot40;
            int32_t sjt_functionParam19;
            char sjt_functionParam20;
            int32_t sjt_functionParam22;
            int32_t sjt_math41;
            int32_t sjt_math42;

            dotTemp50 = &_parent->data;
            sjt_dot39 = dotTemp50;
            dotTemp51 = _parent->count;
            sjt_functionParam19 = dotTemp51;
            sjt_dot40 = item;
            sjt_functionParam22 = i;
            sjf_string_getAt(sjt_dot40, sjt_functionParam22, &sjt_functionParam20);
            sjf_array_char_setAt(sjt_dot39, sjt_functionParam19, sjt_functionParam20);
            dotTemp53 = _parent->count;
            sjt_math41 = dotTemp53;
            sjt_math42 = 1;
            _parent->count = sjt_math41 + sjt_math42;
            i++;
        }

        dotTemp54 = &_parent->data;
        sjt_dot42 = dotTemp54;
        dotTemp55 = _parent->count;
        sjt_functionParam23 = dotTemp55;
        sjt_cast10 = 0;
        sjt_functionParam24 = (char)sjt_cast10;
        sjf_array_char_setAt(sjt_dot42, sjt_functionParam23, sjt_functionParam24);
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
    sjs_array_char* dotTemp52;
    sjs_array_char* sjt_dot41;
    int32_t sjt_functionParam21;

    dotTemp52 = &_parent->data;
    sjt_dot41 = dotTemp52;
    sjt_functionParam21 = index;
    sjf_array_char_getAt(sjt_dot41, sjt_functionParam21, &(*_return));
}

void sjf_string_heap(sjs_string_heap* _this) {
}

void sjf_texture(sjs_texture* _this) {
}

void sjf_texture_copy(sjs_texture* _this, sjs_texture* to) {
    _this->tex = to->tex;
}

void sjf_texture_destroy(sjs_texture* _this) {
    
	SDL_DestroyTexture((SDL_Texture*)_this->tex);	
;
}

void sjf_texture_getSize(sjs_texture* _parent, sjs_size* _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    
			SDL_QueryTexture((SDL_Texture*)_parent->tex, NULL, NULL, &sjv_w, &sjv_h);
		;
    _return->w = sjv_w;
    _return->h = sjv_h;
    sjf_size(_return);
}

void sjf_texture_getSize_heap(sjs_texture* _parent, sjs_size_heap** _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    
			SDL_QueryTexture((SDL_Texture*)_parent->tex, NULL, NULL, &sjv_w, &sjv_h);
		;
    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    (*_return)->w = sjv_w;
    (*_return)->h = sjv_h;
    sjf_size_heap((*_return));
}

void sjf_texture_heap(sjs_texture_heap* _this) {
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
    sjv_frame = 0;
    sjt_cast1 = (sjs_sdlSurface_heap*)malloc(sizeof(sjs_sdlSurface_heap));
    sjt_cast1->_refCount = 1;
    sjt_cast1->size.w = 640;
    sjt_cast1->size.h = 480;
    sjf_size(&sjt_cast1->size);
    sjt_cast4 = 0;
    sjt_cast1->win = (uintptr_t)sjt_cast4;
    sjt_cast5 = 0;
    sjt_cast1->ren = (uintptr_t)sjt_cast5;
    sjf_sdlSurface_heap(sjt_cast1);
    sjv_rootSurface = (sji_surface*)sjf_sdlSurface_heap_as_sji_surface(sjt_cast1);
    sjt_cast6 = (sjs_fillElement_heap*)malloc(sizeof(sjs_fillElement_heap));
    sjt_cast6->_refCount = 1;
    sjt_cast6->children.size = 2;
    sjt_cast7 = 0;
    sjt_cast6->children.data = (uintptr_t)sjt_cast7;
    sjt_cast6->children._isGlobal = false;
    sjf_array_heap_element(&sjt_cast6->children);
    sjt_functionParam6 = 0;
    sjt_cast8 = (sjs_buttonElement_heap*)malloc(sizeof(sjs_buttonElement_heap));
    sjt_cast8->_refCount = 1;
    sjt_cast8->text.count = 0;
    sjt_cast8->text.data.size = 1;
    sjt_cast8->text.data.data = (uintptr_t)sjg_string4;
    sjt_cast8->text.data._isGlobal = false;
    sjf_array_char(&sjt_cast8->text.data);
    sjf_string(&sjt_cast8->text);
    sjt_dot27 = &sjv_style;
    sjt_functionParam10 = 0;
    sjf_anon5_getFont(sjt_dot27, sjt_functionParam10, &sjt_cast8->font);
    sjt_cast8->rect.x = 0;
    sjt_cast8->rect.y = 0;
    sjt_cast8->rect.w = 0;
    sjt_cast8->rect.h = 0;
    sjf_rect(&sjt_cast8->rect);
    sjt_cast8->offset = 0;
    sjf_buttonElement_heap(sjt_cast8);
    sjt_functionParam7 = (sji_element*)sjf_buttonElement_heap_as_sji_element(sjt_cast8);
    sjf_array_heap_element_initAt(&sjt_cast6->children, sjt_functionParam6, sjt_functionParam7);
    sjt_functionParam11 = 1;
    sjt_cast9 = (sjs_imageElement_heap*)malloc(sizeof(sjs_imageElement_heap));
    sjt_cast9->_refCount = 1;
    sjt_dot30 = sjv_rootSurface;
    sjt_call6.count = 17;
    sjt_call6.data.size = 18;
    sjt_call6.data.data = (uintptr_t)sjg_string7;
    sjt_call6.data._isGlobal = false;
    sjf_array_char(&sjt_call6.data);
    sjf_string(&sjt_call6);
    sjt_interfaceParam7 = &sjt_call6;
    sjt_dot30->getTexture((void*)(((char*)sjt_dot30->_parent) + sizeof(intptr_t)), sjt_interfaceParam7, &sjt_cast9->image.texture);
    sjt_cast9->image.rect.x = 0;
    sjt_cast9->image.rect.y = 0;
    sjt_cast9->image.rect.w = 0;
    sjt_cast9->image.rect.h = 0;
    sjf_rect(&sjt_cast9->image.rect);
    sjf_image(&sjt_cast9->image);
    sjt_cast9->rect.x = 0;
    sjt_cast9->rect.y = 0;
    sjt_cast9->rect.w = 0;
    sjt_cast9->rect.h = 0;
    sjf_rect(&sjt_cast9->rect);
    sjf_imageElement_heap(sjt_cast9);
    sjt_functionParam12 = (sji_element*)sjf_imageElement_heap_as_sji_element(sjt_cast9);
    sjf_array_heap_element_initAt(&sjt_cast6->children, sjt_functionParam11, sjt_functionParam12);
    sjt_cast6->rect.x = 0;
    sjt_cast6->rect.y = 0;
    sjt_cast6->rect.w = 0;
    sjt_cast6->rect.h = 0;
    sjf_rect(&sjt_cast6->rect);
    sjf_fillElement_heap(sjt_cast6);
    sjt_value1 = (sji_element*)sjf_fillElement_heap_as_sji_element(sjt_cast6);
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
        sjf_sdlSurface_destroy((sjs_sdlSurface*)(((char*)sjt_cast1) + sizeof(intptr_t)));
    }
    sjt_cast6->_refCount--;
    if (sjt_cast6->_refCount <= 0) {
        sjf_fillElement_destroy((sjs_fillElement*)(((char*)sjt_cast6) + sizeof(intptr_t)));
    }
    sjt_cast8->_refCount--;
    if (sjt_cast8->_refCount <= 0) {
        sjf_buttonElement_destroy((sjs_buttonElement*)(((char*)sjt_cast8) + sizeof(intptr_t)));
    }
    sjt_cast9->_refCount--;
    if (sjt_cast9->_refCount <= 0) {
        sjf_imageElement_destroy((sjs_imageElement*)(((char*)sjt_cast9) + sizeof(intptr_t)));
    }
    sjt_functionParam12->_refCount--;
    if (sjt_functionParam12->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam12);
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
    sjv_rootSurface->_refCount--;
    if (sjv_rootSurface->_refCount <= 0) {
        sji_surface_destroy(sjv_rootSurface);
    }
    sjf_string_destroy(&sjt_call6);
    sjf_anon1_destroy(&sjv_console);
    sjf_anon4_destroy(&sjv_convert);
    sjf_anon2_destroy(&sjv_parse);
    sjf_anon3_destroy(&sjv_random);
    sjf_anon5_destroy(&sjv_style);
}
