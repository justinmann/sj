#ifdef EMSCRIPTEN
#include <SDL.h>
#endif
#ifdef WIN32
#include <SDL.h>
#endif
#ifdef __APPLE__
#include <SDL2/SDL.h>
#endif
#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#endif
#ifdef __APPLE__
#include <SDL2_ttf/SDL_ttf.h>
#endif
#ifdef EMSCRIPTEN
#include <SDL_image.h>
#endif
#ifdef WIN32
#include <SDL_image.h>
#endif
#ifdef EMSCRIPTEN
#include <SDL_ttf.h>
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

const char* sjg_string10 = "assets/buttonPressed.png";
const char* sjg_string11 = "Button Text";
const char* sjg_string13 = "buttonElement onMouseUp ";
const char* sjg_string14 = ", ";
const char* sjg_string17 = "buttonElement onMouseDown";
const char* sjg_string19 = "buttonElement onMouseMove";
const char* sjg_string3 = "assets/sample.ttf";
const char* sjg_string4 = "assets/sample.ttf";
const char* sjg_string6 = "assets/buttonNormal.png";
const char* sjg_string8 = "assets/buttonHot.png";

#define sjs_object_typeId 1
#define sjs_anon8_typeId 2
#define sjs_anon8_heap_typeId 3
#define sjs_anon7_typeId 4
#define sjs_anon7_heap_typeId 5
#define sjs_anon6_typeId 6
#define sjs_anon6_heap_typeId 7
#define sjs_anon5_typeId 8
#define sjs_anon5_heap_typeId 9
#define sjs_anon4_typeId 10
#define sjs_anon4_heap_typeId 11
#define sjs_anon3_typeId 12
#define sjs_anon3_heap_typeId 13
#define sjs_anon2_typeId 14
#define sjs_anon2_heap_typeId 15
#define sjs_anon1_typeId 16
#define sjs_anon1_heap_typeId 17
#define sjs_size_typeId 18
#define sjs_size_heap_typeId 19
#define sjs_sdlSurface_typeId 20
#define sjs_rect_typeId 21
#define sjs_rect_heap_typeId 22
#define sjs_color_typeId 23
#define sjs_color_heap_typeId 24
#define sjs_texture_typeId 25
#define sjs_texture_heap_typeId 26
#define sjs_image_typeId 27
#define sjs_image_heap_typeId 28
#define sjs_array_char_typeId 29
#define sjs_array_char_heap_typeId 30
#define sjs_string_typeId 31
#define sjs_string_heap_typeId 32
#define sjs_font_typeId 33
#define sjs_font_heap_typeId 34
#define sji_surface_typeId 35
#define sjs_sdlSurface_heap_typeId 36
#define sjs_array_heap_element_typeId 37
#define sjs_array_heap_element_heap_typeId 38
#define sjs_borderLayout_typeId 39
#define sji_element_typeId 40
#define sji_borderChild_typeId 41
#define sjs_borderLayout_heap_typeId 42
#define sjs_borderChild_typeId 43
#define sjs_borderChild_heap_typeId 44
#define sjs_buttonElement_typeId 45
#define sjs_point_typeId 46
#define sjs_point_heap_typeId 47
#define sji_mouseHandler_typeId 48
#define sjs_buttonElement_heap_typeId 49

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_anon8 sjs_anon8;
typedef struct td_sjs_anon8_heap sjs_anon8_heap;
typedef struct td_sjs_anon7 sjs_anon7;
typedef struct td_sjs_anon7_heap sjs_anon7_heap;
typedef struct td_sjs_anon6 sjs_anon6;
typedef struct td_sjs_anon6_heap sjs_anon6_heap;
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
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_array_char_heap sjs_array_char_heap;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_string_heap sjs_string_heap;
typedef struct td_sjs_font sjs_font;
typedef struct td_sjs_font_heap sjs_font_heap;
typedef struct td_sji_surface sji_surface;
typedef struct td_sjs_sdlSurface_heap sjs_sdlSurface_heap;
typedef struct td_sjs_array_heap_element sjs_array_heap_element;
typedef struct td_sjs_array_heap_element_heap sjs_array_heap_element_heap;
typedef struct td_sjs_borderLayout sjs_borderLayout;
typedef struct td_sji_element sji_element;
typedef struct td_sji_borderChild sji_borderChild;
typedef struct td_sjs_borderLayout_heap sjs_borderLayout_heap;
typedef struct td_sjs_borderChild sjs_borderChild;
typedef struct td_sjs_borderChild_heap sjs_borderChild_heap;
typedef struct td_sjs_buttonElement sjs_buttonElement;
typedef struct td_sjs_point sjs_point;
typedef struct td_sjs_point_heap sjs_point_heap;
typedef struct td_sji_mouseHandler sji_mouseHandler;
typedef struct td_sjs_buttonElement_heap sjs_buttonElement_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_anon8 {
    int32_t fill;
    int32_t left;
    int32_t right;
    int32_t top;
    int32_t bottom;
};

struct td_sjs_anon8_heap {
    intptr_t _refCount;
    int32_t fill;
    int32_t left;
    int32_t right;
    int32_t top;
    int32_t bottom;
};

struct td_sjs_anon7 {
    int structsNeedAValue;
};

struct td_sjs_anon7_heap {
    intptr_t _refCount;
};

struct td_sjs_anon6 {
    int structsNeedAValue;
};

struct td_sjs_anon6_heap {
    intptr_t _refCount;
};

struct td_sjs_anon5 {
    int32_t normal;
    int32_t hot;
    int32_t pressed;
};

struct td_sjs_anon5_heap {
    intptr_t _refCount;
    int32_t normal;
    int32_t hot;
    int32_t pressed;
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

struct td_sjs_font {
    sjs_string src;
    int32_t size;
    uintptr_t data;
};

struct td_sjs_font_heap {
    intptr_t _refCount;
    sjs_string src;
    int32_t size;
    uintptr_t data;
};

struct td_sji_surface {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*clear)(void* _parent);
    void (*present)(void* _parent);
    void (*getSize)(void* _parent, sjs_size* _return);
    void (*getSize_heap)(void* _parent, sjs_size_heap** _return);
    void (*fillRect)(void* _parent, sjs_rect* rect, sjs_color* color);
    void (*drawImage)(void* _parent, sjs_rect* rect, sjs_image* image);
    void (*drawText)(void* _parent, sjs_rect* rect, sjs_font* font, sjs_string* text, sjs_color* color);
    void (*getTextSize)(void* _parent, sjs_font* font, sjs_string* text, sjs_size* _return);
    void (*getTextSize_heap)(void* _parent, sjs_font* font, sjs_string* text, sjs_size_heap** _return);
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

struct td_sjs_borderLayout {
    sjs_array_heap_element children;
    sjs_rect rect;
};

struct td_sji_element {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*getSize)(void* _parent, sjs_size* maxSize, sjs_size* _return);
    void (*getSize_heap)(void* _parent, sjs_size* maxSize, sjs_size_heap** _return);
    void (*setRect)(void* _parent, sjs_rect* rect);
    void (*render)(void* _parent, sji_surface* surface);
    void (*getChildren)(void* _parent, sjs_array_heap_element** _return);
};

struct td_sji_borderChild {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*getPosition)(void* _parent, int32_t* _return);
};

struct td_sjs_borderLayout_heap {
    intptr_t _refCount;
    sjs_array_heap_element children;
    sjs_rect rect;
};

struct td_sjs_borderChild {
    sji_element* child;
    sjs_rect rect;
    int32_t position;
    sjs_array_heap_element_heap* _children;
};

struct td_sjs_borderChild_heap {
    intptr_t _refCount;
    sji_element* child;
    sjs_rect rect;
    int32_t position;
    sjs_array_heap_element_heap* _children;
};

struct td_sjs_buttonElement {
    sjs_string text;
    sjs_color textColor;
    sjs_font font;
    sjs_rect rect;
    sjs_image normalImage;
    sjs_image hotImage;
    sjs_image pressedImage;
    int32_t state;
};

struct td_sjs_point {
    int32_t x;
    int32_t y;
};

struct td_sjs_point_heap {
    intptr_t _refCount;
    int32_t x;
    int32_t y;
};

struct td_sji_mouseHandler {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*onMouseUp)(void* _parent, sjs_point* point);
    void (*onMouseDown)(void* _parent, sjs_point* point);
    void (*onMouseMove)(void* _parent, sjs_point* point);
};

struct td_sjs_buttonElement_heap {
    intptr_t _refCount;
    sjs_string text;
    sjs_color textColor;
    sjs_font font;
    sjs_rect rect;
    sjs_image normalImage;
    sjs_image hotImage;
    sjs_image pressedImage;
    int32_t state;
};


	
	
	
	
    
	
	
    
	
	
    

sjs_string sjt_call12;
sjs_string sjt_call13;
sjs_string sjt_call14;
sjs_sdlSurface_heap* sjt_cast1;
sjs_borderChild_heap* sjt_cast10;
sjs_buttonElement_heap* sjt_cast12;
int32_t sjt_cast4;
int32_t sjt_cast5;
sjs_borderLayout_heap* sjt_cast6;
int32_t sjt_cast9;
sjs_anon6* sjt_dot134;
sjs_anon7* sjt_dot135;
sji_surface* sjt_dot136;
sji_surface* sjt_dot137;
sji_surface* sjt_dot138;
sjs_anon5* sjt_dot139;
sjs_anon8* sjt_dot140;
int32_t sjt_functionParam29;
int32_t sjt_functionParam4;
sji_element* sjt_functionParam5;
sjs_string* sjt_interfaceParam28;
sjs_string* sjt_interfaceParam29;
sjs_string* sjt_interfaceParam30;
sjs_anon8 sjv_borderPosition;
sjs_anon5 sjv_buttonState;
sjs_anon6 sjv_colors;
sjs_anon1 sjv_console;
sjs_anon4 sjv_convert;
int32_t sjv_frame;
sjs_anon2 sjv_parse;
sjs_anon3 sjv_random;
sji_element* sjv_root;
sji_surface* sjv_rootSurface;
sjs_anon7 sjv_style;

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
void sjf_anon5_heap(sjs_anon5_heap* _this);
void sjf_anon6(sjs_anon6* _this);
void sjf_anon6_black(sjs_anon6* _parent, sjs_color* _return);
void sjf_anon6_black_heap(sjs_anon6* _parent, sjs_color_heap** _return);
void sjf_anon6_copy(sjs_anon6* _this, sjs_anon6* to);
void sjf_anon6_destroy(sjs_anon6* _this);
void sjf_anon6_heap(sjs_anon6_heap* _this);
void sjf_anon7(sjs_anon7* _this);
void sjf_anon7_copy(sjs_anon7* _this, sjs_anon7* to);
void sjf_anon7_destroy(sjs_anon7* _this);
void sjf_anon7_getFont(sjs_anon7* _parent, int32_t typeId, sjs_font* _return);
void sjf_anon7_getFont_heap(sjs_anon7* _parent, int32_t typeId, sjs_font_heap** _return);
void sjf_anon7_heap(sjs_anon7_heap* _this);
void sjf_anon8(sjs_anon8* _this);
void sjf_anon8_copy(sjs_anon8* _this, sjs_anon8* to);
void sjf_anon8_destroy(sjs_anon8* _this);
void sjf_anon8_heap(sjs_anon8_heap* _this);
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
void sjf_borderChild(sjs_borderChild* _this);
sjs_object* sjf_borderChild_asInterface(sjs_borderChild* _this, int typeId);
sji_borderChild* sjf_borderChild_as_sji_borderChild(sjs_borderChild* _this);
sji_element* sjf_borderChild_as_sji_element(sjs_borderChild* _this);
void sjf_borderChild_copy(sjs_borderChild* _this, sjs_borderChild* to);
void sjf_borderChild_destroy(sjs_borderChild* _this);
void sjf_borderChild_getChildren(sjs_borderChild* _parent, sjs_array_heap_element** _return);
void sjf_borderChild_getPosition(sjs_borderChild* _parent, int32_t* _return);
void sjf_borderChild_getSize(sjs_borderChild* _parent, sjs_size* maxSize, sjs_size* _return);
void sjf_borderChild_getSize_heap(sjs_borderChild* _parent, sjs_size* maxSize, sjs_size_heap** _return);
void sjf_borderChild_heap(sjs_borderChild_heap* _this);
sjs_object* sjf_borderChild_heap_asInterface(sjs_borderChild_heap* _this, int typeId);
sji_borderChild* sjf_borderChild_heap_as_sji_borderChild(sjs_borderChild_heap* _this);
sji_element* sjf_borderChild_heap_as_sji_element(sjs_borderChild_heap* _this);
void sjf_borderChild_render(sjs_borderChild* _parent, sji_surface* surface);
void sjf_borderChild_setRect(sjs_borderChild* _parent, sjs_rect* rect_);
void sjf_borderLayout(sjs_borderLayout* _this);
sjs_object* sjf_borderLayout_asInterface(sjs_borderLayout* _this, int typeId);
sji_element* sjf_borderLayout_as_sji_element(sjs_borderLayout* _this);
void sjf_borderLayout_copy(sjs_borderLayout* _this, sjs_borderLayout* to);
void sjf_borderLayout_destroy(sjs_borderLayout* _this);
void sjf_borderLayout_getChildren(sjs_borderLayout* _parent, sjs_array_heap_element** _return);
void sjf_borderLayout_getSize(sjs_borderLayout* _parent, sjs_size* maxSize, sjs_size* _return);
void sjf_borderLayout_getSize_heap(sjs_borderLayout* _parent, sjs_size* maxSize, sjs_size_heap** _return);
void sjf_borderLayout_heap(sjs_borderLayout_heap* _this);
sjs_object* sjf_borderLayout_heap_asInterface(sjs_borderLayout_heap* _this, int typeId);
sji_element* sjf_borderLayout_heap_as_sji_element(sjs_borderLayout_heap* _this);
void sjf_borderLayout_render(sjs_borderLayout* _parent, sji_surface* surface);
void sjf_borderLayout_setRect(sjs_borderLayout* _parent, sjs_rect* rect_);
void sjf_buttonElement(sjs_buttonElement* _this);
sjs_object* sjf_buttonElement_asInterface(sjs_buttonElement* _this, int typeId);
sji_element* sjf_buttonElement_as_sji_element(sjs_buttonElement* _this);
sji_mouseHandler* sjf_buttonElement_as_sji_mouseHandler(sjs_buttonElement* _this);
void sjf_buttonElement_copy(sjs_buttonElement* _this, sjs_buttonElement* to);
void sjf_buttonElement_destroy(sjs_buttonElement* _this);
void sjf_buttonElement_getChildren(sjs_buttonElement* _parent, sjs_array_heap_element** _return);
void sjf_buttonElement_getSize(sjs_buttonElement* _parent, sjs_size* maxSize, sjs_size* _return);
void sjf_buttonElement_getSize_heap(sjs_buttonElement* _parent, sjs_size* maxSize, sjs_size_heap** _return);
void sjf_buttonElement_heap(sjs_buttonElement_heap* _this);
sjs_object* sjf_buttonElement_heap_asInterface(sjs_buttonElement_heap* _this, int typeId);
sji_element* sjf_buttonElement_heap_as_sji_element(sjs_buttonElement_heap* _this);
sji_mouseHandler* sjf_buttonElement_heap_as_sji_mouseHandler(sjs_buttonElement_heap* _this);
void sjf_buttonElement_onMouseDown(sjs_buttonElement* _parent, sjs_point* point);
void sjf_buttonElement_onMouseMove(sjs_buttonElement* _parent, sjs_point* point);
void sjf_buttonElement_onMouseUp(sjs_buttonElement* _parent, sjs_point* point);
void sjf_buttonElement_render(sjs_buttonElement* _parent, sji_surface* surface);
void sjf_buttonElement_setRect(sjs_buttonElement* _parent, sjs_rect* rect_);
void sjf_color(sjs_color* _this);
void sjf_color_copy(sjs_color* _this, sjs_color* to);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color_heap* _this);
void sjf_fireMouseDown(sji_element* element, sjs_point* point);
void sjf_fireMouseUp(sji_element* element, sjs_point* point);
void sjf_font(sjs_font* _this);
void sjf_font_copy(sjs_font* _this, sjs_font* to);
void sjf_font_destroy(sjs_font* _this);
void sjf_font_heap(sjs_font_heap* _this);
void sjf_image(sjs_image* _this);
void sjf_image_copy(sjs_image* _this, sjs_image* to);
void sjf_image_destroy(sjs_image* _this);
void sjf_image_heap(sjs_image_heap* _this);
void sjf_mainLoop(void);
void sjf_point(sjs_point* _this);
void sjf_point_copy(sjs_point* _this, sjs_point* to);
void sjf_point_destroy(sjs_point* _this);
void sjf_point_heap(sjs_point_heap* _this);
void sjf_rect(sjs_rect* _this);
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
void sjf_sdlSurface_drawText(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_font* font, sjs_string* text, sjs_color* color);
void sjf_sdlSurface_fillRect(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_color* color);
void sjf_sdlSurface_getSize(sjs_sdlSurface* _parent, sjs_size* _return);
void sjf_sdlSurface_getSize_heap(sjs_sdlSurface* _parent, sjs_size_heap** _return);
void sjf_sdlSurface_getTextSize(sjs_sdlSurface* _parent, sjs_font* font, sjs_string* text, sjs_size* _return);
void sjf_sdlSurface_getTextSize_heap(sjs_sdlSurface* _parent, sjs_font* font, sjs_string* text, sjs_size_heap** _return);
void sjf_sdlSurface_getTexture(sjs_sdlSurface* _parent, sjs_string* src, sjs_texture* _return);
void sjf_sdlSurface_getTexture_heap(sjs_sdlSurface* _parent, sjs_string* src, sjs_texture_heap** _return);
void sjf_sdlSurface_heap(sjs_sdlSurface_heap* _this);
sjs_object* sjf_sdlSurface_heap_asInterface(sjs_sdlSurface_heap* _this, int typeId);
sji_surface* sjf_sdlSurface_heap_as_sji_surface(sjs_sdlSurface_heap* _this);
void sjf_sdlSurface_present(sjs_sdlSurface* _parent);
void sjf_size(sjs_size* _this);
void sjf_size_cap(sjs_size* _parent, sjs_size* maxSize, sjs_size* _return);
void sjf_size_cap_heap(sjs_size* _parent, sjs_size* maxSize, sjs_size_heap** _return);
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
void sji_borderChild_copy(sji_borderChild* _this, sji_borderChild* _from);
void sji_borderChild_destroy(sji_borderChild* _this);
void sji_element_copy(sji_element* _this, sji_element* _from);
void sji_element_destroy(sji_element* _this);
void sji_mouseHandler_copy(sji_mouseHandler* _this, sji_mouseHandler* _from);
void sji_mouseHandler_destroy(sji_mouseHandler* _this);
void sji_surface_copy(sji_surface* _this, sji_surface* _from);
void sji_surface_destroy(sji_surface* _this);
void main_destroy(void);

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
    int32_t sjt_cast14;
    int32_t sjt_math39;
    int32_t sjt_math40;
    int32_t sjv_count;
    uintptr_t sjv_data;

    sjv_count = 0;
    sjt_cast14 = 0;
    sjv_data = (uintptr_t)sjt_cast14;
    
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
    sjt_math39 = sjv_count;
    sjt_math40 = 1;
    _return->data.size = sjt_math39 + sjt_math40;
    _return->data.data = sjv_data;
    _return->data._isGlobal = false;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_anon4_i32toString_heap(sjs_anon4* _parent, int32_t val, int32_t base, int32_t minLength, sjs_string_heap** _return) {
    int32_t sjt_cast15;
    int32_t sjt_math41;
    int32_t sjt_math42;
    int32_t sjv_count;
    uintptr_t sjv_data;

    sjv_count = 0;
    sjt_cast15 = 0;
    sjv_data = (uintptr_t)sjt_cast15;
    
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
    sjt_math41 = sjv_count;
    sjt_math42 = 1;
    (*_return)->data.size = sjt_math41 + sjt_math42;
    (*_return)->data.data = sjv_data;
    (*_return)->data._isGlobal = false;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_anon5(sjs_anon5* _this) {
}

void sjf_anon5_copy(sjs_anon5* _this, sjs_anon5* to) {
    _this->normal = to->normal;
    _this->hot = to->hot;
    _this->pressed = to->pressed;
}

void sjf_anon5_destroy(sjs_anon5* _this) {
}

void sjf_anon5_heap(sjs_anon5_heap* _this) {
}

void sjf_anon6(sjs_anon6* _this) {
}

void sjf_anon6_black(sjs_anon6* _parent, sjs_color* _return) {
    _return->r = 0;
    _return->g = 0;
    _return->b = 0;
    _return->a = 255;
    sjf_color(_return);
}

void sjf_anon6_black_heap(sjs_anon6* _parent, sjs_color_heap** _return) {
    (*_return) = (sjs_color_heap*)malloc(sizeof(sjs_color_heap));
    (*_return)->_refCount = 1;
    (*_return)->r = 0;
    (*_return)->g = 0;
    (*_return)->b = 0;
    (*_return)->a = 255;
    sjf_color_heap((*_return));
}

void sjf_anon6_copy(sjs_anon6* _this, sjs_anon6* to) {
}

void sjf_anon6_destroy(sjs_anon6* _this) {
}

void sjf_anon6_heap(sjs_anon6_heap* _this) {
}

void sjf_anon7(sjs_anon7* _this) {
}

void sjf_anon7_copy(sjs_anon7* _this, sjs_anon7* to) {
}

void sjf_anon7_destroy(sjs_anon7* _this) {
}

void sjf_anon7_getFont(sjs_anon7* _parent, int32_t typeId, sjs_font* _return) {
    int32_t sjt_cast16;

    _return->src.count = 17;
    _return->src.data.size = 18;
    _return->src.data.data = (uintptr_t)sjg_string3;
    _return->src.data._isGlobal = false;
    sjf_array_char(&_return->src.data);
    sjf_string(&_return->src);
    _return->size = 12;
    sjt_cast16 = 0;
    _return->data = (uintptr_t)sjt_cast16;
    sjf_font(_return);
}

void sjf_anon7_getFont_heap(sjs_anon7* _parent, int32_t typeId, sjs_font_heap** _return) {
    int32_t sjt_cast17;

    (*_return) = (sjs_font_heap*)malloc(sizeof(sjs_font_heap));
    (*_return)->_refCount = 1;
    (*_return)->src.count = 17;
    (*_return)->src.data.size = 18;
    (*_return)->src.data.data = (uintptr_t)sjg_string4;
    (*_return)->src.data._isGlobal = false;
    sjf_array_char(&(*_return)->src.data);
    sjf_string(&(*_return)->src);
    (*_return)->size = 12;
    sjt_cast17 = 0;
    (*_return)->data = (uintptr_t)sjt_cast17;
    sjf_font_heap((*_return));
}

void sjf_anon7_heap(sjs_anon7_heap* _this) {
}

void sjf_anon8(sjs_anon8* _this) {
}

void sjf_anon8_copy(sjs_anon8* _this, sjs_anon8* to) {
    _this->fill = to->fill;
    _this->left = to->left;
    _this->right = to->right;
    _this->top = to->top;
    _this->bottom = to->bottom;
}

void sjf_anon8_destroy(sjs_anon8* _this) {
}

void sjf_anon8_heap(sjs_anon8_heap* _this) {
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

void sjf_borderChild(sjs_borderChild* _this) {
}

sjs_object* sjf_borderChild_asInterface(sjs_borderChild* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_borderChild_as_sji_element(_this);
        }

        case sji_borderChild_typeId:  {
            return (sjs_object*)sjf_borderChild_as_sji_borderChild(_this);
        }
    }

    return 0;
}

sji_borderChild* sjf_borderChild_as_sji_borderChild(sjs_borderChild* _this) {
    sji_borderChild* _interface;
    _interface = (sji_borderChild*)malloc(sizeof(sji_borderChild));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_borderChild_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_borderChild_asInterface;
    _interface->getPosition = (void(*)(void*, int32_t*))sjf_borderChild_getPosition;

    return _interface;
}

sji_element* sjf_borderChild_as_sji_element(sjs_borderChild* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_borderChild_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_borderChild_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_borderChild_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_borderChild_getSize_heap;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_borderChild_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_borderChild_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_borderChild_getChildren;

    return _interface;
}

void sjf_borderChild_copy(sjs_borderChild* _this, sjs_borderChild* to) {
    _this->child = (sji_element*)malloc(sizeof(sji_element));
    _this->child->_refCount = 1;
    sji_element_copy(_this->child, to->child);
    sjf_rect_copy(&_this->rect, &to->rect);
    _this->position = to->position;
    _this->_children = 0;
    sjf_array_heap_element_copy((sjs_array_heap_element*)(((char*)_this->_children) + sizeof(intptr_t)), (sjs_array_heap_element*)(((char*)to->_children) + sizeof(intptr_t)));
}

void sjf_borderChild_destroy(sjs_borderChild* _this) {
    _this->child->_refCount--;
    if (_this->child->_refCount <= 0) {
        sji_element_destroy(_this->child);
    }

    if (_this->_children != 0) {
        _this->_children->_refCount--;
        if (_this->_children->_refCount <= 0) {
            sjf_array_heap_element_destroy((sjs_array_heap_element*)(((char*)_this->_children) + sizeof(intptr_t)));
        }
    }
}

void sjf_borderChild_getChildren(sjs_borderChild* _parent, sjs_array_heap_element** _return) {
    bool sjt_ifElse15;
    sjs_array_heap_element_heap* sjt_isEmpty7;

    sjt_isEmpty7 = (_parent)->_children;
    if (sjt_isEmpty7 != 0) {
        sjt_isEmpty7->_refCount++;
    }

    sjt_ifElse15 = (sjt_isEmpty7 == 0);
    if (sjt_ifElse15) {
        int32_t sjt_cast11;
        int32_t sjt_functionParam6;
        sji_element* sjt_functionParam7;
        sjs_array_heap_element_heap* sjt_value6;

        sjt_value6 = (sjs_array_heap_element_heap*)malloc(sizeof(sjs_array_heap_element_heap));
        sjt_value6->_refCount = 1;
        sjt_value6->size = 1;
        sjt_cast11 = 0;
        sjt_value6->data = (uintptr_t)sjt_cast11;
        sjt_value6->_isGlobal = false;
        sjf_array_heap_element_heap(sjt_value6);
        sjt_functionParam6 = 0;
        sjt_functionParam7 = (_parent)->child;
        sjt_functionParam7->_refCount++;
        sjf_array_heap_element_initAt((sjs_array_heap_element*)(((char*)sjt_value6) + sizeof(intptr_t)), sjt_functionParam6, sjt_functionParam7);
        if (_parent->_children != 0) {
            _parent->_children->_refCount--;
            if (_parent->_children->_refCount <= 0) {
                sjf_array_heap_element_destroy((sjs_array_heap_element*)(((char*)_parent->_children) + sizeof(intptr_t)));
            }
        }

        _parent->_children = sjt_value6;
        if (_parent->_children != 0) {
            _parent->_children->_refCount++;
        }

        sjt_functionParam7->_refCount--;
        if (sjt_functionParam7->_refCount <= 0) {
            sji_element_destroy(sjt_functionParam7);
        }
        sjt_value6->_refCount--;
        if (sjt_value6->_refCount <= 0) {
            sjf_array_heap_element_destroy((sjs_array_heap_element*)(((char*)sjt_value6) + sizeof(intptr_t)));
        }
    } else {
    }

    (*_return) = (sjs_array_heap_element*)(((char*)(_parent)->_children) + sizeof(intptr_t));

    if (sjt_isEmpty7 != 0) {
        sjt_isEmpty7->_refCount--;
        if (sjt_isEmpty7->_refCount <= 0) {
            sjf_array_heap_element_destroy((sjs_array_heap_element*)(((char*)sjt_isEmpty7) + sizeof(intptr_t)));
        }
    }
}

void sjf_borderChild_getPosition(sjs_borderChild* _parent, int32_t* _return) {
    (*_return) = (_parent)->position;
}

void sjf_borderChild_getSize(sjs_borderChild* _parent, sjs_size* maxSize, sjs_size* _return) {
    sji_element* sjt_dot84;
    sjs_size* sjt_interfaceParam8;

    sjt_dot84 = (_parent)->child;
    sjt_interfaceParam8 = maxSize;
    sjt_dot84->getSize((void*)(((char*)sjt_dot84->_parent) + sizeof(intptr_t)), sjt_interfaceParam8, _return);
}

void sjf_borderChild_getSize_heap(sjs_borderChild* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sji_element* sjt_dot85;
    sjs_size* sjt_interfaceParam9;

    sjt_dot85 = (_parent)->child;
    sjt_interfaceParam9 = maxSize;
    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_dot85->getSize_heap((void*)(((char*)sjt_dot85->_parent) + sizeof(intptr_t)), sjt_interfaceParam9, _return);
}

void sjf_borderChild_heap(sjs_borderChild_heap* _this) {
}

sjs_object* sjf_borderChild_heap_asInterface(sjs_borderChild_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_borderChild_heap_as_sji_element(_this);
        }

        case sji_borderChild_typeId:  {
            return (sjs_object*)sjf_borderChild_heap_as_sji_borderChild(_this);
        }
    }

    return 0;
}

sji_borderChild* sjf_borderChild_heap_as_sji_borderChild(sjs_borderChild_heap* _this) {
    sji_borderChild* _interface;
    _interface = (sji_borderChild*)malloc(sizeof(sji_borderChild));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_borderChild_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_borderChild_heap_asInterface;
    _interface->getPosition = (void(*)(void*, int32_t*))sjf_borderChild_getPosition;

    return _interface;
}

sji_element* sjf_borderChild_heap_as_sji_element(sjs_borderChild_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_borderChild_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_borderChild_heap_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_borderChild_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_borderChild_getSize_heap;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_borderChild_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_borderChild_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_borderChild_getChildren;

    return _interface;
}

void sjf_borderChild_render(sjs_borderChild* _parent, sji_surface* surface) {
    sji_element* sjt_dot87;
    sji_surface* sjt_interfaceParam11;

    sjt_dot87 = (_parent)->child;
    sjt_interfaceParam11 = surface;
    sjt_interfaceParam11->_refCount++;
    sjt_dot87->render((void*)(((char*)sjt_dot87->_parent) + sizeof(intptr_t)), sjt_interfaceParam11);

    sjt_interfaceParam11->_refCount--;
    if (sjt_interfaceParam11->_refCount <= 0) {
        sji_surface_destroy(sjt_interfaceParam11);
    }
}

void sjf_borderChild_setRect(sjs_borderChild* _parent, sjs_rect* rect_) {
    sji_element* sjt_dot86;
    sjs_rect* sjt_interfaceParam10;

    sjf_rect_copy(&_parent->rect, rect_);
    sjt_dot86 = (_parent)->child;
    sjt_interfaceParam10 = &(_parent)->rect;
    sjt_dot86->setRect((void*)(((char*)sjt_dot86->_parent) + sizeof(intptr_t)), sjt_interfaceParam10);
}

void sjf_borderLayout(sjs_borderLayout* _this) {
}

sjs_object* sjf_borderLayout_asInterface(sjs_borderLayout* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_borderLayout_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_borderLayout_as_sji_element(sjs_borderLayout* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_borderLayout_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_borderLayout_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_borderLayout_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_borderLayout_getSize_heap;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_borderLayout_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_borderLayout_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_borderLayout_getChildren;

    return _interface;
}

void sjf_borderLayout_copy(sjs_borderLayout* _this, sjs_borderLayout* to) {
    sjf_array_heap_element_copy(&_this->children, &to->children);
    sjf_rect_copy(&_this->rect, &to->rect);
}

void sjf_borderLayout_destroy(sjs_borderLayout* _this) {
}

void sjf_borderLayout_getChildren(sjs_borderLayout* _parent, sjs_array_heap_element** _return) {
    sjs_array_heap_element* sjt_value5;
    sjs_array_heap_element* sjv_a;

    sjv_a = &(_parent)->children;
    sjt_value5 = sjv_a;
    (*_return) = sjt_value5;
}

void sjf_borderLayout_getSize(sjs_borderLayout* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size* sjt_dot11;
    sjs_size* sjt_dot12;

    sjt_dot11 = maxSize;
    _return->w = (sjt_dot11)->w;
    sjt_dot12 = maxSize;
    _return->h = (sjt_dot12)->h;
    sjf_size(_return);
}

void sjf_borderLayout_getSize_heap(sjs_borderLayout* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size* sjt_dot13;
    sjs_size* sjt_dot14;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_dot13 = maxSize;
    (*_return)->w = (sjt_dot13)->w;
    sjt_dot14 = maxSize;
    (*_return)->h = (sjt_dot14)->h;
    sjf_size_heap((*_return));
}

void sjf_borderLayout_heap(sjs_borderLayout_heap* _this) {
}

sjs_object* sjf_borderLayout_heap_asInterface(sjs_borderLayout_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_borderLayout_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_borderLayout_heap_as_sji_element(sjs_borderLayout_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_borderLayout_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_borderLayout_heap_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_borderLayout_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_borderLayout_getSize_heap;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_borderLayout_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_borderLayout_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_borderLayout_getChildren;

    return _interface;
}

void sjf_borderLayout_render(sjs_borderLayout* _parent, sji_surface* surface) {
    int32_t i;
    sjs_array_heap_element* sjt_dot81;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;

    sjt_forStart3 = 0;
    i = sjt_forStart3;
    sjt_dot81 = &(_parent)->children;
    sjt_forEnd3 = (sjt_dot81)->size;
    while (i < sjt_forEnd3) {
        sjs_array_heap_element* sjt_dot82;
        sji_element* sjt_dot83;
        int32_t sjt_functionParam3;
        sji_surface* sjt_interfaceParam7;
        sji_element* sjv_child;

        sjt_dot82 = &(_parent)->children;
        sjt_functionParam3 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot82, sjt_functionParam3, &sjv_child);
        sjt_dot83 = sjv_child;
        sjt_interfaceParam7 = surface;
        sjt_interfaceParam7->_refCount++;
        sjt_dot83->render((void*)(((char*)sjt_dot83->_parent) + sizeof(intptr_t)), sjt_interfaceParam7);
        i++;

        sjt_interfaceParam7->_refCount--;
        if (sjt_interfaceParam7->_refCount <= 0) {
            sji_surface_destroy(sjt_interfaceParam7);
        }
        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }
}

void sjf_borderLayout_setRect(sjs_borderLayout* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_array_heap_element* sjt_dot15;
    sjs_array_heap_element* sjt_dot74;
    int32_t sjt_forEnd1;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart1;
    int32_t sjt_forStart2;
    sjs_rect sjv_remaining;

    sjf_rect_copy(&_parent->rect, rect_);
    sjf_rect_copy(&sjv_remaining, rect_);
    sjt_forStart1 = 0;
    i = sjt_forStart1;
    sjt_dot15 = &(_parent)->children;
    sjt_forEnd1 = (sjt_dot15)->size;
    while (i < sjt_forEnd1) {
        sji_element* sjt_cast7;
        int32_t sjt_compare10;
        int32_t sjt_compare9;
        sjs_array_heap_element* sjt_dot16;
        sjs_anon8* sjt_dot20;
        int32_t sjt_functionParam1;
        bool sjt_ifElse3;
        bool sjt_ifElse4;
        bool sjt_ifElse6;
        int32_option sjt_isEmpty1;
        sji_borderChild* sjt_isEmpty2;
        sji_borderChild* sjv_borderChild;
        sji_element* sjv_child;
        int32_t sjv_position;

        sjt_dot16 = &(_parent)->children;
        sjt_functionParam1 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot16, sjt_functionParam1, &sjv_child);
        sjt_cast7 = sjv_child;
        sjt_cast7->_refCount++;
        sjv_borderChild = (sji_borderChild*)sjt_cast7->asInterface(sjt_cast7->_parent, sji_borderChild_typeId);
        sjt_isEmpty2 = sjv_borderChild;
        if (sjt_isEmpty2 != 0) {
            sjt_isEmpty2->_refCount++;
        }

        sjt_ifElse4 = (sjt_isEmpty2 == 0);
        if (sjt_ifElse4) {
            sjt_isEmpty1 = int32_empty;
        } else {
            sji_borderChild* sjt_dot17;
            sji_borderChild* sjt_getValue1;
            int32_t sjt_value1;
            int32_option value1;

            sjt_getValue1 = sjv_borderChild;
            if (sjt_getValue1 != 0) {
                sjt_getValue1->_refCount++;
            }

            sjt_dot17 = sjt_getValue1;
            sjt_dot17->getPosition((void*)(((char*)sjt_dot17->_parent) + sizeof(intptr_t)), &sjt_value1);
            value1.isEmpty = false;
            value1.value = sjt_value1;
            sjt_isEmpty1 = value1;

            if (sjt_getValue1 != 0) {
                sjt_getValue1->_refCount--;
                if (sjt_getValue1->_refCount <= 0) {
                    sji_borderChild_destroy(sjt_getValue1);
                }
            }
        }

        sjt_ifElse3 = sjt_isEmpty1.isEmpty;
        if (sjt_ifElse3) {
            sjs_anon8* sjt_dot18;

            sjt_dot18 = &sjv_borderPosition;
            sjv_position = (sjt_dot18)->fill;
        } else {
            int32_option sjt_getValue2;
            bool sjt_ifElse5;
            sji_borderChild* sjt_isEmpty3;

            sjt_isEmpty3 = sjv_borderChild;
            if (sjt_isEmpty3 != 0) {
                sjt_isEmpty3->_refCount++;
            }

            sjt_ifElse5 = (sjt_isEmpty3 == 0);
            if (sjt_ifElse5) {
                sjt_getValue2 = int32_empty;
            } else {
                sji_borderChild* sjt_dot19;
                sji_borderChild* sjt_getValue3;
                int32_t sjt_value2;
                int32_option value2;

                sjt_getValue3 = sjv_borderChild;
                if (sjt_getValue3 != 0) {
                    sjt_getValue3->_refCount++;
                }

                sjt_dot19 = sjt_getValue3;
                sjt_dot19->getPosition((void*)(((char*)sjt_dot19->_parent) + sizeof(intptr_t)), &sjt_value2);
                value2.isEmpty = false;
                value2.value = sjt_value2;
                sjt_getValue2 = value2;

                if (sjt_getValue3 != 0) {
                    sjt_getValue3->_refCount--;
                    if (sjt_getValue3->_refCount <= 0) {
                        sji_borderChild_destroy(sjt_getValue3);
                    }
                }
            }

            sjv_position = sjt_getValue2.value;

            if (sjt_isEmpty3 != 0) {
                sjt_isEmpty3->_refCount--;
                if (sjt_isEmpty3->_refCount <= 0) {
                    sji_borderChild_destroy(sjt_isEmpty3);
                }
            }
        }

        sjt_compare9 = sjv_position;
        sjt_dot20 = &sjv_borderPosition;
        sjt_compare10 = (sjt_dot20)->fill;
        sjt_ifElse6 = sjt_compare9 != sjt_compare10;
        if (sjt_ifElse6) {
            sjs_size sjt_call1;
            int32_t sjt_compare11;
            int32_t sjt_compare12;
            sji_element* sjt_dot21;
            sjs_rect* sjt_dot22;
            sjs_rect* sjt_dot23;
            sjs_anon8* sjt_dot24;
            bool sjt_ifElse7;
            sjs_size* sjt_interfaceParam1;
            sjs_size sjv_childSize;

            sjt_dot21 = sjv_child;
            sjt_dot22 = &sjv_remaining;
            sjt_call1.w = (sjt_dot22)->w;
            sjt_dot23 = &sjv_remaining;
            sjt_call1.h = (sjt_dot23)->h;
            sjf_size(&sjt_call1);
            sjt_interfaceParam1 = &sjt_call1;
            sjt_dot21->getSize((void*)(((char*)sjt_dot21->_parent) + sizeof(intptr_t)), sjt_interfaceParam1, &sjv_childSize);
            sjt_compare11 = sjv_position;
            sjt_dot24 = &sjv_borderPosition;
            sjt_compare12 = (sjt_dot24)->left;
            sjt_ifElse7 = sjt_compare11 == sjt_compare12;
            if (sjt_ifElse7) {
                sjs_rect sjt_call2;
                sji_element* sjt_dot25;
                sjs_rect* sjt_dot26;
                sjs_rect* sjt_dot27;
                sjs_size* sjt_dot28;
                sjs_rect* sjt_dot29;
                sjs_rect* sjt_dot30;
                sjs_size* sjt_dot31;
                sjs_rect* sjt_dot32;
                sjs_rect* sjt_dot33;
                sjs_size* sjt_dot34;
                sjs_rect* sjt_dot35;
                sjs_rect* sjt_interfaceParam2;
                int32_t sjt_math1;
                int32_t sjt_math2;
                int32_t sjt_math3;
                int32_t sjt_math4;

                sjt_dot25 = sjv_child;
                sjt_dot26 = &sjv_remaining;
                sjt_call2.x = (sjt_dot26)->x;
                sjt_dot27 = &sjv_remaining;
                sjt_call2.y = (sjt_dot27)->y;
                sjt_dot28 = &sjv_childSize;
                sjt_call2.w = (sjt_dot28)->w;
                sjt_dot29 = &sjv_remaining;
                sjt_call2.h = (sjt_dot29)->h;
                sjf_rect(&sjt_call2);
                sjt_interfaceParam2 = &sjt_call2;
                sjt_dot25->setRect((void*)(((char*)sjt_dot25->_parent) + sizeof(intptr_t)), sjt_interfaceParam2);
                sjt_dot30 = &sjv_remaining;
                sjt_math1 = (sjt_dot30)->x;
                sjt_dot31 = &sjv_childSize;
                sjt_math2 = (sjt_dot31)->w;
                sjv_remaining.x = sjt_math1 + sjt_math2;
                sjt_dot32 = &sjv_remaining;
                sjv_remaining.y = (sjt_dot32)->y;
                sjt_dot33 = &sjv_remaining;
                sjt_math3 = (sjt_dot33)->w;
                sjt_dot34 = &sjv_childSize;
                sjt_math4 = (sjt_dot34)->w;
                sjv_remaining.w = sjt_math3 - sjt_math4;
                sjt_dot35 = &sjv_remaining;
                sjv_remaining.h = (sjt_dot35)->h;
                sjf_rect(&sjv_remaining);

                sjf_rect_destroy(&sjt_call2);
            } else {
                int32_t sjt_compare13;
                int32_t sjt_compare14;
                sjs_anon8* sjt_dot36;
                bool sjt_ifElse8;

                sjt_compare13 = sjv_position;
                sjt_dot36 = &sjv_borderPosition;
                sjt_compare14 = (sjt_dot36)->right;
                sjt_ifElse8 = sjt_compare13 == sjt_compare14;
                if (sjt_ifElse8) {
                    sjs_rect sjt_call3;
                    sji_element* sjt_dot37;
                    sjs_rect* sjt_dot38;
                    sjs_rect* sjt_dot39;
                    sjs_size* sjt_dot40;
                    sjs_rect* sjt_dot41;
                    sjs_size* sjt_dot42;
                    sjs_rect* sjt_dot43;
                    sjs_rect* sjt_dot44;
                    sjs_rect* sjt_dot45;
                    sjs_rect* sjt_dot46;
                    sjs_size* sjt_dot47;
                    sjs_rect* sjt_dot48;
                    sjs_rect* sjt_interfaceParam3;
                    int32_t sjt_math10;
                    int32_t sjt_math5;
                    int32_t sjt_math6;
                    int32_t sjt_math7;
                    int32_t sjt_math8;
                    int32_t sjt_math9;

                    sjt_dot37 = sjv_child;
                    sjt_dot38 = &sjv_remaining;
                    sjt_math7 = (sjt_dot38)->x;
                    sjt_dot39 = &sjv_remaining;
                    sjt_math8 = (sjt_dot39)->w;
                    sjt_math5 = sjt_math7 + sjt_math8;
                    sjt_dot40 = &sjv_childSize;
                    sjt_math6 = (sjt_dot40)->w;
                    sjt_call3.x = sjt_math5 - sjt_math6;
                    sjt_dot41 = &sjv_remaining;
                    sjt_call3.y = (sjt_dot41)->y;
                    sjt_dot42 = &sjv_childSize;
                    sjt_call3.w = (sjt_dot42)->w;
                    sjt_dot43 = &sjv_remaining;
                    sjt_call3.h = (sjt_dot43)->h;
                    sjf_rect(&sjt_call3);
                    sjt_interfaceParam3 = &sjt_call3;
                    sjt_dot37->setRect((void*)(((char*)sjt_dot37->_parent) + sizeof(intptr_t)), sjt_interfaceParam3);
                    sjt_dot44 = &sjv_remaining;
                    sjv_remaining.x = (sjt_dot44)->x;
                    sjt_dot45 = &sjv_remaining;
                    sjv_remaining.y = (sjt_dot45)->y;
                    sjt_dot46 = &sjv_remaining;
                    sjt_math9 = (sjt_dot46)->w;
                    sjt_dot47 = &sjv_childSize;
                    sjt_math10 = (sjt_dot47)->w;
                    sjv_remaining.w = sjt_math9 - sjt_math10;
                    sjt_dot48 = &sjv_remaining;
                    sjv_remaining.h = (sjt_dot48)->h;
                    sjf_rect(&sjv_remaining);

                    sjf_rect_destroy(&sjt_call3);
                } else {
                    int32_t sjt_compare15;
                    int32_t sjt_compare16;
                    sjs_anon8* sjt_dot49;
                    bool sjt_ifElse9;

                    sjt_compare15 = sjv_position;
                    sjt_dot49 = &sjv_borderPosition;
                    sjt_compare16 = (sjt_dot49)->top;
                    sjt_ifElse9 = sjt_compare15 == sjt_compare16;
                    if (sjt_ifElse9) {
                        sjs_rect sjt_call4;
                        sji_element* sjt_dot50;
                        sjs_rect* sjt_dot51;
                        sjs_rect* sjt_dot52;
                        sjs_rect* sjt_dot53;
                        sjs_size* sjt_dot54;
                        sjs_rect* sjt_dot55;
                        sjs_rect* sjt_dot56;
                        sjs_size* sjt_dot57;
                        sjs_rect* sjt_dot58;
                        sjs_rect* sjt_dot59;
                        sjs_size* sjt_dot60;
                        sjs_rect* sjt_interfaceParam4;
                        int32_t sjt_math11;
                        int32_t sjt_math12;
                        int32_t sjt_math13;
                        int32_t sjt_math14;

                        sjt_dot50 = sjv_child;
                        sjt_dot51 = &sjv_remaining;
                        sjt_call4.x = (sjt_dot51)->x;
                        sjt_dot52 = &sjv_remaining;
                        sjt_call4.y = (sjt_dot52)->y;
                        sjt_dot53 = &sjv_remaining;
                        sjt_call4.w = (sjt_dot53)->w;
                        sjt_dot54 = &sjv_childSize;
                        sjt_call4.h = (sjt_dot54)->h;
                        sjf_rect(&sjt_call4);
                        sjt_interfaceParam4 = &sjt_call4;
                        sjt_dot50->setRect((void*)(((char*)sjt_dot50->_parent) + sizeof(intptr_t)), sjt_interfaceParam4);
                        sjt_dot55 = &sjv_remaining;
                        sjv_remaining.x = (sjt_dot55)->x;
                        sjt_dot56 = &sjv_remaining;
                        sjt_math11 = (sjt_dot56)->y;
                        sjt_dot57 = &sjv_childSize;
                        sjt_math12 = (sjt_dot57)->h;
                        sjv_remaining.y = sjt_math11 + sjt_math12;
                        sjt_dot58 = &sjv_remaining;
                        sjv_remaining.w = (sjt_dot58)->w;
                        sjt_dot59 = &sjv_remaining;
                        sjt_math13 = (sjt_dot59)->h;
                        sjt_dot60 = &sjv_childSize;
                        sjt_math14 = (sjt_dot60)->h;
                        sjv_remaining.h = sjt_math13 - sjt_math14;
                        sjf_rect(&sjv_remaining);

                        sjf_rect_destroy(&sjt_call4);
                    } else {
                        int32_t sjt_compare17;
                        int32_t sjt_compare18;
                        sjs_anon8* sjt_dot61;
                        bool sjt_ifElse10;

                        sjt_compare17 = sjv_position;
                        sjt_dot61 = &sjv_borderPosition;
                        sjt_compare18 = (sjt_dot61)->bottom;
                        sjt_ifElse10 = sjt_compare17 == sjt_compare18;
                        if (sjt_ifElse10) {
                            sjs_rect sjt_call5;
                            sji_element* sjt_dot62;
                            sjs_rect* sjt_dot63;
                            sjs_rect* sjt_dot64;
                            sjs_rect* sjt_dot65;
                            sjs_size* sjt_dot66;
                            sjs_rect* sjt_dot67;
                            sjs_size* sjt_dot68;
                            sjs_rect* sjt_dot69;
                            sjs_rect* sjt_dot70;
                            sjs_rect* sjt_dot71;
                            sjs_rect* sjt_dot72;
                            sjs_size* sjt_dot73;
                            sjs_rect* sjt_interfaceParam5;
                            int32_t sjt_math15;
                            int32_t sjt_math16;
                            int32_t sjt_math17;
                            int32_t sjt_math18;
                            int32_t sjt_math19;
                            int32_t sjt_math20;

                            sjt_dot62 = sjv_child;
                            sjt_dot63 = &sjv_remaining;
                            sjt_call5.x = (sjt_dot63)->x;
                            sjt_dot64 = &sjv_remaining;
                            sjt_math17 = (sjt_dot64)->y;
                            sjt_dot65 = &sjv_remaining;
                            sjt_math18 = (sjt_dot65)->h;
                            sjt_math15 = sjt_math17 + sjt_math18;
                            sjt_dot66 = &sjv_childSize;
                            sjt_math16 = (sjt_dot66)->h;
                            sjt_call5.y = sjt_math15 - sjt_math16;
                            sjt_dot67 = &sjv_remaining;
                            sjt_call5.w = (sjt_dot67)->w;
                            sjt_dot68 = &sjv_childSize;
                            sjt_call5.h = (sjt_dot68)->h;
                            sjf_rect(&sjt_call5);
                            sjt_interfaceParam5 = &sjt_call5;
                            sjt_dot62->setRect((void*)(((char*)sjt_dot62->_parent) + sizeof(intptr_t)), sjt_interfaceParam5);
                            sjt_dot69 = &sjv_remaining;
                            sjv_remaining.x = (sjt_dot69)->x;
                            sjt_dot70 = &sjv_remaining;
                            sjv_remaining.y = (sjt_dot70)->y;
                            sjt_dot71 = &sjv_remaining;
                            sjv_remaining.w = (sjt_dot71)->w;
                            sjt_dot72 = &sjv_remaining;
                            sjt_math19 = (sjt_dot72)->h;
                            sjt_dot73 = &sjv_childSize;
                            sjt_math20 = (sjt_dot73)->h;
                            sjv_remaining.h = sjt_math19 - sjt_math20;
                            sjf_rect(&sjv_remaining);

                            sjf_rect_destroy(&sjt_call5);
                        }
                    }
                }
            }

            sjf_size_destroy(&sjt_call1);
            sjf_size_destroy(&sjv_childSize);
        }

        i++;

        sjt_cast7->_refCount--;
        if (sjt_cast7->_refCount <= 0) {
            sji_element_destroy(sjt_cast7);
        }
        if (sjt_isEmpty2 != 0) {
            sjt_isEmpty2->_refCount--;
            if (sjt_isEmpty2->_refCount <= 0) {
                sji_borderChild_destroy(sjt_isEmpty2);
            }
        }
        if (sjv_borderChild != 0) {
            sjv_borderChild->_refCount--;
            if (sjv_borderChild->_refCount <= 0) {
                sji_borderChild_destroy(sjv_borderChild);
            }
        }
        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }

    sjt_forStart2 = 0;
    i = sjt_forStart2;
    sjt_dot74 = &(_parent)->children;
    sjt_forEnd2 = (sjt_dot74)->size;
    while (i < sjt_forEnd2) {
        sji_element* sjt_cast8;
        int32_t sjt_compare19;
        int32_t sjt_compare20;
        sjs_array_heap_element* sjt_dot75;
        sjs_anon8* sjt_dot79;
        int32_t sjt_functionParam2;
        bool sjt_ifElse11;
        bool sjt_ifElse12;
        bool sjt_ifElse14;
        int32_option sjt_isEmpty4;
        sji_borderChild* sjt_isEmpty5;
        sji_borderChild* sjv_borderChild2;
        sji_element* sjv_child2;
        int32_t sjv_position2;

        sjt_dot75 = &(_parent)->children;
        sjt_functionParam2 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot75, sjt_functionParam2, &sjv_child2);
        sjt_cast8 = sjv_child2;
        sjt_cast8->_refCount++;
        sjv_borderChild2 = (sji_borderChild*)sjt_cast8->asInterface(sjt_cast8->_parent, sji_borderChild_typeId);
        sjt_isEmpty5 = sjv_borderChild2;
        if (sjt_isEmpty5 != 0) {
            sjt_isEmpty5->_refCount++;
        }

        sjt_ifElse12 = (sjt_isEmpty5 == 0);
        if (sjt_ifElse12) {
            sjt_isEmpty4 = int32_empty;
        } else {
            sji_borderChild* sjt_dot76;
            sji_borderChild* sjt_getValue4;
            int32_t sjt_value3;
            int32_option value3;

            sjt_getValue4 = sjv_borderChild2;
            if (sjt_getValue4 != 0) {
                sjt_getValue4->_refCount++;
            }

            sjt_dot76 = sjt_getValue4;
            sjt_dot76->getPosition((void*)(((char*)sjt_dot76->_parent) + sizeof(intptr_t)), &sjt_value3);
            value3.isEmpty = false;
            value3.value = sjt_value3;
            sjt_isEmpty4 = value3;

            if (sjt_getValue4 != 0) {
                sjt_getValue4->_refCount--;
                if (sjt_getValue4->_refCount <= 0) {
                    sji_borderChild_destroy(sjt_getValue4);
                }
            }
        }

        sjt_ifElse11 = sjt_isEmpty4.isEmpty;
        if (sjt_ifElse11) {
            sjs_anon8* sjt_dot77;

            sjt_dot77 = &sjv_borderPosition;
            sjv_position2 = (sjt_dot77)->fill;
        } else {
            int32_option sjt_getValue5;
            bool sjt_ifElse13;
            sji_borderChild* sjt_isEmpty6;

            sjt_isEmpty6 = sjv_borderChild2;
            if (sjt_isEmpty6 != 0) {
                sjt_isEmpty6->_refCount++;
            }

            sjt_ifElse13 = (sjt_isEmpty6 == 0);
            if (sjt_ifElse13) {
                sjt_getValue5 = int32_empty;
            } else {
                sji_borderChild* sjt_dot78;
                sji_borderChild* sjt_getValue6;
                int32_t sjt_value4;
                int32_option value4;

                sjt_getValue6 = sjv_borderChild2;
                if (sjt_getValue6 != 0) {
                    sjt_getValue6->_refCount++;
                }

                sjt_dot78 = sjt_getValue6;
                sjt_dot78->getPosition((void*)(((char*)sjt_dot78->_parent) + sizeof(intptr_t)), &sjt_value4);
                value4.isEmpty = false;
                value4.value = sjt_value4;
                sjt_getValue5 = value4;

                if (sjt_getValue6 != 0) {
                    sjt_getValue6->_refCount--;
                    if (sjt_getValue6->_refCount <= 0) {
                        sji_borderChild_destroy(sjt_getValue6);
                    }
                }
            }

            sjv_position2 = sjt_getValue5.value;

            if (sjt_isEmpty6 != 0) {
                sjt_isEmpty6->_refCount--;
                if (sjt_isEmpty6->_refCount <= 0) {
                    sji_borderChild_destroy(sjt_isEmpty6);
                }
            }
        }

        sjt_compare19 = sjv_position2;
        sjt_dot79 = &sjv_borderPosition;
        sjt_compare20 = (sjt_dot79)->fill;
        sjt_ifElse14 = sjt_compare19 == sjt_compare20;
        if (sjt_ifElse14) {
            sji_element* sjt_dot80;
            sjs_rect* sjt_interfaceParam6;

            sjt_dot80 = sjv_child2;
            sjt_interfaceParam6 = &sjv_remaining;
            sjt_dot80->setRect((void*)(((char*)sjt_dot80->_parent) + sizeof(intptr_t)), sjt_interfaceParam6);
        }

        i++;

        sjt_cast8->_refCount--;
        if (sjt_cast8->_refCount <= 0) {
            sji_element_destroy(sjt_cast8);
        }
        if (sjt_isEmpty5 != 0) {
            sjt_isEmpty5->_refCount--;
            if (sjt_isEmpty5->_refCount <= 0) {
                sji_borderChild_destroy(sjt_isEmpty5);
            }
        }
        if (sjv_borderChild2 != 0) {
            sjv_borderChild2->_refCount--;
            if (sjv_borderChild2->_refCount <= 0) {
                sji_borderChild_destroy(sjv_borderChild2);
            }
        }
        sjv_child2->_refCount--;
        if (sjv_child2->_refCount <= 0) {
            sji_element_destroy(sjv_child2);
        }
    }

    sjf_rect_destroy(&sjv_remaining);
}

void sjf_buttonElement(sjs_buttonElement* _this) {
}

sjs_object* sjf_buttonElement_asInterface(sjs_buttonElement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_buttonElement_as_sji_element(_this);
        }

        case sji_mouseHandler_typeId:  {
            return (sjs_object*)sjf_buttonElement_as_sji_mouseHandler(_this);
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
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_buttonElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_buttonElement_getSize_heap;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_buttonElement_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_buttonElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_buttonElement_getChildren;

    return _interface;
}

sji_mouseHandler* sjf_buttonElement_as_sji_mouseHandler(sjs_buttonElement* _this) {
    sji_mouseHandler* _interface;
    _interface = (sji_mouseHandler*)malloc(sizeof(sji_mouseHandler));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_buttonElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_buttonElement_asInterface;
    _interface->onMouseUp = (void(*)(void*,sjs_point*))sjf_buttonElement_onMouseUp;
    _interface->onMouseDown = (void(*)(void*,sjs_point*))sjf_buttonElement_onMouseDown;
    _interface->onMouseMove = (void(*)(void*,sjs_point*))sjf_buttonElement_onMouseMove;

    return _interface;
}

void sjf_buttonElement_copy(sjs_buttonElement* _this, sjs_buttonElement* to) {
    sjf_string_copy(&_this->text, &to->text);
    sjf_color_copy(&_this->textColor, &to->textColor);
    sjf_font_copy(&_this->font, &to->font);
    sjf_rect_copy(&_this->rect, &to->rect);
    sjf_image_copy(&_this->normalImage, &to->normalImage);
    sjf_image_copy(&_this->hotImage, &to->hotImage);
    sjf_image_copy(&_this->pressedImage, &to->pressedImage);
    _this->state = to->state;
}

void sjf_buttonElement_destroy(sjs_buttonElement* _this) {
}

void sjf_buttonElement_getChildren(sjs_buttonElement* _parent, sjs_array_heap_element** _return) {
    (*_return) = 0;
}

void sjf_buttonElement_getSize(sjs_buttonElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sji_surface* sjt_dot88;
    sjs_size* sjt_dot89;
    sjs_size* sjt_functionParam8;
    sjs_font* sjt_interfaceParam12;
    sjs_string* sjt_interfaceParam13;
    sjs_size sjv_textSize;

    sjt_dot88 = sjv_rootSurface;
    sjt_interfaceParam12 = &(_parent)->font;
    sjt_interfaceParam13 = &(_parent)->text;
    sjt_dot88->getTextSize((void*)(((char*)sjt_dot88->_parent) + sizeof(intptr_t)), sjt_interfaceParam12, sjt_interfaceParam13, &sjv_textSize);
    sjt_dot89 = &sjv_textSize;
    sjt_functionParam8 = maxSize;
    sjf_size_cap(sjt_dot89, sjt_functionParam8, _return);

    sjf_size_destroy(&sjv_textSize);
}

void sjf_buttonElement_getSize_heap(sjs_buttonElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sji_surface* sjt_dot94;
    sjs_size* sjt_dot95;
    sjs_size* sjt_functionParam9;
    sjs_font* sjt_interfaceParam14;
    sjs_string* sjt_interfaceParam15;
    sjs_size sjv_textSize;

    sjt_dot94 = sjv_rootSurface;
    sjt_interfaceParam14 = &(_parent)->font;
    sjt_interfaceParam15 = &(_parent)->text;
    sjt_dot94->getTextSize((void*)(((char*)sjt_dot94->_parent) + sizeof(intptr_t)), sjt_interfaceParam14, sjt_interfaceParam15, &sjv_textSize);
    sjt_dot95 = &sjv_textSize;
    sjt_functionParam9 = maxSize;
    sjf_size_cap_heap(sjt_dot95, sjt_functionParam9, _return);

    sjf_size_destroy(&sjv_textSize);
}

void sjf_buttonElement_heap(sjs_buttonElement_heap* _this) {
}

sjs_object* sjf_buttonElement_heap_asInterface(sjs_buttonElement_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_buttonElement_heap_as_sji_element(_this);
        }

        case sji_mouseHandler_typeId:  {
            return (sjs_object*)sjf_buttonElement_heap_as_sji_mouseHandler(_this);
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
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_buttonElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_buttonElement_getSize_heap;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_buttonElement_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_buttonElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_buttonElement_getChildren;

    return _interface;
}

sji_mouseHandler* sjf_buttonElement_heap_as_sji_mouseHandler(sjs_buttonElement_heap* _this) {
    sji_mouseHandler* _interface;
    _interface = (sji_mouseHandler*)malloc(sizeof(sji_mouseHandler));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_buttonElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_buttonElement_heap_asInterface;
    _interface->onMouseUp = (void(*)(void*,sjs_point*))sjf_buttonElement_onMouseUp;
    _interface->onMouseDown = (void(*)(void*,sjs_point*))sjf_buttonElement_onMouseDown;
    _interface->onMouseMove = (void(*)(void*,sjs_point*))sjf_buttonElement_onMouseMove;

    return _interface;
}

void sjf_buttonElement_onMouseDown(sjs_buttonElement* _parent, sjs_point* point) {
    sjs_string sjt_call10;
    sjs_anon1* sjt_dot129;
    sjs_anon5* sjt_dot130;
    sjs_string* sjt_functionParam27;

    sjt_dot129 = &sjv_console;
    sjt_call10.count = 25;
    sjt_call10.data.size = 26;
    sjt_call10.data.data = (uintptr_t)sjg_string17;
    sjt_call10.data._isGlobal = false;
    sjf_array_char(&sjt_call10.data);
    sjf_string(&sjt_call10);
    sjt_functionParam27 = &sjt_call10;
    sjf_anon1_write(sjt_dot129, sjt_functionParam27);
    sjt_dot130 = &sjv_buttonState;
    _parent->state = (sjt_dot130)->pressed;

    sjf_string_destroy(&sjt_call10);
}

void sjf_buttonElement_onMouseMove(sjs_buttonElement* _parent, sjs_point* point) {
    sjs_string sjt_call11;
    int32_t sjt_compare35;
    int32_t sjt_compare36;
    sjs_anon1* sjt_dot131;
    sjs_anon5* sjt_dot132;
    sjs_string* sjt_functionParam28;
    bool sjt_ifElse23;

    sjt_dot131 = &sjv_console;
    sjt_call11.count = 25;
    sjt_call11.data.size = 26;
    sjt_call11.data.data = (uintptr_t)sjg_string19;
    sjt_call11.data._isGlobal = false;
    sjf_array_char(&sjt_call11.data);
    sjf_string(&sjt_call11);
    sjt_functionParam28 = &sjt_call11;
    sjf_anon1_write(sjt_dot131, sjt_functionParam28);
    sjt_compare35 = (_parent)->state;
    sjt_dot132 = &sjv_buttonState;
    sjt_compare36 = (sjt_dot132)->normal;
    sjt_ifElse23 = sjt_compare35 == sjt_compare36;
    if (sjt_ifElse23) {
        sjs_anon5* sjt_dot133;

        sjt_dot133 = &sjv_buttonState;
        _parent->state = (sjt_dot133)->hot;
    } else {
    }

    sjf_string_destroy(&sjt_call11);
}

void sjf_buttonElement_onMouseUp(sjs_buttonElement* _parent, sjs_point* point) {
    sjs_string sjt_call6;
    sjs_string sjt_call7;
    sjs_string sjt_call8;
    sjs_string sjt_call9;
    sjs_anon1* sjt_dot110;
    sjs_string* sjt_dot111;
    sjs_string* sjt_dot112;
    sjs_string* sjt_dot113;
    sjs_anon4* sjt_dot124;
    sjs_point* sjt_dot125;
    sjs_anon4* sjt_dot126;
    sjs_point* sjt_dot127;
    sjs_anon5* sjt_dot128;
    sjs_string* sjt_functionParam10;
    sjs_string* sjt_functionParam18;
    int32_t sjt_functionParam19;
    int32_t sjt_functionParam20;
    int32_t sjt_functionParam21;
    sjs_string* sjt_functionParam22;
    sjs_string* sjt_functionParam23;
    int32_t sjt_functionParam24;
    int32_t sjt_functionParam25;
    int32_t sjt_functionParam26;

    sjt_dot110 = &sjv_console;
    sjt_call6.count = 24;
    sjt_call6.data.size = 25;
    sjt_call6.data.data = (uintptr_t)sjg_string13;
    sjt_call6.data._isGlobal = false;
    sjf_array_char(&sjt_call6.data);
    sjf_string(&sjt_call6);
    sjt_dot113 = &sjt_call6;
    sjt_dot124 = &sjv_convert;
    sjt_dot125 = point;
    sjt_functionParam19 = (sjt_dot125)->x;
    sjt_functionParam20 = 10;
    sjt_functionParam21 = 0;
    sjf_anon4_i32toString(sjt_dot124, sjt_functionParam19, sjt_functionParam20, sjt_functionParam21, &sjt_call7);
    sjt_functionParam18 = &sjt_call7;
    sjf_string_add(sjt_dot113, sjt_functionParam18, &sjt_dot112);
    sjt_call8.count = 2;
    sjt_call8.data.size = 3;
    sjt_call8.data.data = (uintptr_t)sjg_string14;
    sjt_call8.data._isGlobal = false;
    sjf_array_char(&sjt_call8.data);
    sjf_string(&sjt_call8);
    sjt_functionParam22 = &sjt_call8;
    sjf_string_add(sjt_dot112, sjt_functionParam22, &sjt_dot111);
    sjt_dot126 = &sjv_convert;
    sjt_dot127 = point;
    sjt_functionParam24 = (sjt_dot127)->y;
    sjt_functionParam25 = 10;
    sjt_functionParam26 = 0;
    sjf_anon4_i32toString(sjt_dot126, sjt_functionParam24, sjt_functionParam25, sjt_functionParam26, &sjt_call9);
    sjt_functionParam23 = &sjt_call9;
    sjf_string_add(sjt_dot111, sjt_functionParam23, &sjt_functionParam10);
    sjf_anon1_write(sjt_dot110, sjt_functionParam10);
    sjt_dot128 = &sjv_buttonState;
    _parent->state = (sjt_dot128)->normal;

    sjf_string_destroy(&sjt_call6);
    sjf_string_destroy(&sjt_call7);
    sjf_string_destroy(&sjt_call8);
    sjf_string_destroy(&sjt_call9);
}

void sjf_buttonElement_render(sjs_buttonElement* _parent, sji_surface* surface) {
    int32_t sjt_compare25;
    int32_t sjt_compare26;
    sji_surface* sjt_dot102;
    sjs_rect* sjt_dot103;
    sjs_size* sjt_dot104;
    sjs_rect* sjt_dot105;
    sjs_size* sjt_dot106;
    sjs_size* sjt_dot107;
    sjs_size* sjt_dot108;
    sji_surface* sjt_dot109;
    sjs_anon5* sjt_dot96;
    bool sjt_ifElse18;
    sjs_font* sjt_interfaceParam22;
    sjs_string* sjt_interfaceParam23;
    sjs_rect* sjt_interfaceParam24;
    sjs_font* sjt_interfaceParam25;
    sjs_string* sjt_interfaceParam26;
    sjs_color* sjt_interfaceParam27;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjt_math23;
    int32_t sjt_math24;
    int32_t sjt_math25;
    int32_t sjt_math26;
    int32_t sjt_math27;
    int32_t sjt_math28;
    sjs_rect sjv_textRect;
    sjs_size sjv_textSize;

    sjt_compare25 = (_parent)->state;
    sjt_dot96 = &sjv_buttonState;
    sjt_compare26 = (sjt_dot96)->normal;
    sjt_ifElse18 = sjt_compare25 == sjt_compare26;
    if (sjt_ifElse18) {
        sji_surface* sjt_dot97;
        sjs_rect* sjt_interfaceParam16;
        sjs_image* sjt_interfaceParam17;

        sjt_dot97 = surface;
        sjt_interfaceParam16 = &(_parent)->rect;
        sjt_interfaceParam17 = &(_parent)->normalImage;
        sjt_dot97->drawImage((void*)(((char*)sjt_dot97->_parent) + sizeof(intptr_t)), sjt_interfaceParam16, sjt_interfaceParam17);
    } else {
        int32_t sjt_compare27;
        int32_t sjt_compare28;
        sjs_anon5* sjt_dot98;
        bool sjt_ifElse19;

        sjt_compare27 = (_parent)->state;
        sjt_dot98 = &sjv_buttonState;
        sjt_compare28 = (sjt_dot98)->hot;
        sjt_ifElse19 = sjt_compare27 == sjt_compare28;
        if (sjt_ifElse19) {
            sji_surface* sjt_dot99;
            sjs_rect* sjt_interfaceParam18;
            sjs_image* sjt_interfaceParam19;

            sjt_dot99 = surface;
            sjt_interfaceParam18 = &(_parent)->rect;
            sjt_interfaceParam19 = &(_parent)->hotImage;
            sjt_dot99->drawImage((void*)(((char*)sjt_dot99->_parent) + sizeof(intptr_t)), sjt_interfaceParam18, sjt_interfaceParam19);
        } else {
            int32_t sjt_compare29;
            int32_t sjt_compare30;
            sjs_anon5* sjt_dot100;
            bool sjt_ifElse20;

            sjt_compare29 = (_parent)->state;
            sjt_dot100 = &sjv_buttonState;
            sjt_compare30 = (sjt_dot100)->pressed;
            sjt_ifElse20 = sjt_compare29 == sjt_compare30;
            if (sjt_ifElse20) {
                sji_surface* sjt_dot101;
                sjs_rect* sjt_interfaceParam20;
                sjs_image* sjt_interfaceParam21;

                sjt_dot101 = surface;
                sjt_interfaceParam20 = &(_parent)->rect;
                sjt_interfaceParam21 = &(_parent)->pressedImage;
                sjt_dot101->drawImage((void*)(((char*)sjt_dot101->_parent) + sizeof(intptr_t)), sjt_interfaceParam20, sjt_interfaceParam21);
            }
        }
    }

    sjt_dot102 = surface;
    sjt_interfaceParam22 = &(_parent)->font;
    sjt_interfaceParam23 = &(_parent)->text;
    sjt_dot102->getTextSize((void*)(((char*)sjt_dot102->_parent) + sizeof(intptr_t)), sjt_interfaceParam22, sjt_interfaceParam23, &sjv_textSize);
    sjt_dot103 = &(_parent)->rect;
    sjt_math23 = (sjt_dot103)->w;
    sjt_dot104 = &sjv_textSize;
    sjt_math24 = (sjt_dot104)->w;
    sjt_math21 = sjt_math23 - sjt_math24;
    sjt_math22 = 2;
    sjv_textRect.x = sjt_math21 / sjt_math22;
    sjt_dot105 = &(_parent)->rect;
    sjt_math27 = (sjt_dot105)->h;
    sjt_dot106 = &sjv_textSize;
    sjt_math28 = (sjt_dot106)->h;
    sjt_math25 = sjt_math27 - sjt_math28;
    sjt_math26 = 2;
    sjv_textRect.y = sjt_math25 / sjt_math26;
    sjt_dot107 = &sjv_textSize;
    sjv_textRect.w = (sjt_dot107)->w;
    sjt_dot108 = &sjv_textSize;
    sjv_textRect.h = (sjt_dot108)->h;
    sjf_rect(&sjv_textRect);
    sjt_dot109 = surface;
    sjt_interfaceParam24 = &sjv_textRect;
    sjt_interfaceParam25 = &(_parent)->font;
    sjt_interfaceParam26 = &(_parent)->text;
    sjt_interfaceParam27 = &(_parent)->textColor;
    sjt_dot109->drawText((void*)(((char*)sjt_dot109->_parent) + sizeof(intptr_t)), sjt_interfaceParam24, sjt_interfaceParam25, sjt_interfaceParam26, sjt_interfaceParam27);

    sjf_rect_destroy(&sjv_textRect);
    sjf_size_destroy(&sjv_textSize);
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

void sjf_fireMouseDown(sji_element* element, sjs_point* point) {
    bool result3;
    bool result4;
    sji_element* sjt_cast19;
    sji_element* sjt_dot153;
    bool sjt_ifElse28;
    bool sjt_ifElse29;
    sji_mouseHandler* sjt_isEmpty10;
    sjs_array_heap_element* sjt_isEmpty11;
    bool sjt_not3;
    bool sjt_not4;
    sjs_array_heap_element* sjv_children;
    sji_mouseHandler* sjv_mouseHandler;

    sjt_cast19 = element;
    sjt_cast19->_refCount++;
    sjv_mouseHandler = (sji_mouseHandler*)sjt_cast19->asInterface(sjt_cast19->_parent, sji_mouseHandler_typeId);
    sjt_isEmpty10 = sjv_mouseHandler;
    if (sjt_isEmpty10 != 0) {
        sjt_isEmpty10->_refCount++;
    }

    sjt_not3 = (sjt_isEmpty10 == 0);
    result3 = !sjt_not3;
    sjt_ifElse28 = result3;
    if (sjt_ifElse28) {
        sji_mouseHandler* sjt_dot152;
        sji_mouseHandler* sjt_getValue9;
        sjs_point* sjt_interfaceParam34;

        sjt_getValue9 = sjv_mouseHandler;
        if (sjt_getValue9 != 0) {
            sjt_getValue9->_refCount++;
        }

        sjt_dot152 = sjt_getValue9;
        sjt_interfaceParam34 = point;
        sjt_dot152->onMouseDown((void*)(((char*)sjt_dot152->_parent) + sizeof(intptr_t)), sjt_interfaceParam34);

        if (sjt_getValue9 != 0) {
            sjt_getValue9->_refCount--;
            if (sjt_getValue9->_refCount <= 0) {
                sji_mouseHandler_destroy(sjt_getValue9);
            }
        }
    }

    sjt_dot153 = element;
    sjt_dot153->getChildren((void*)(((char*)sjt_dot153->_parent) + sizeof(intptr_t)), &sjv_children);
    sjt_isEmpty11 = sjv_children;
    sjt_not4 = (sjt_isEmpty11 == 0);
    result4 = !sjt_not4;
    sjt_ifElse29 = result4;
    if (sjt_ifElse29) {
        int32_t i;
        sjs_array_heap_element* sjt_dot154;
        int32_t sjt_forEnd6;
        int32_t sjt_forStart6;
        sjs_array_heap_element* sjt_getValue10;
        sjs_array_heap_element* sjv_c;

        sjt_getValue10 = sjv_children;
        if (sjt_getValue10 == 0) { exit(-1); };
        sjv_c = sjt_getValue10;
        sjt_forStart6 = 0;
        i = sjt_forStart6;
        sjt_dot154 = sjv_c;
        sjt_forEnd6 = (sjt_dot154)->size;
        while (i < sjt_forEnd6) {
            sjs_array_heap_element* sjt_dot155;
            sji_element* sjt_functionParam35;
            int32_t sjt_functionParam36;
            sjs_point* sjt_functionParam37;

            sjt_dot155 = sjv_c;
            sjt_functionParam36 = i;
            sjf_array_heap_element_getAt_heap(sjt_dot155, sjt_functionParam36, &sjt_functionParam35);
            sjt_functionParam37 = point;
            sjf_fireMouseDown(sjt_functionParam35, sjt_functionParam37);
            i++;

            sjt_functionParam35->_refCount--;
            if (sjt_functionParam35->_refCount <= 0) {
                sji_element_destroy(sjt_functionParam35);
            }
        }
    }

    sjt_cast19->_refCount--;
    if (sjt_cast19->_refCount <= 0) {
        sji_element_destroy(sjt_cast19);
    }
    if (sjt_isEmpty10 != 0) {
        sjt_isEmpty10->_refCount--;
        if (sjt_isEmpty10->_refCount <= 0) {
            sji_mouseHandler_destroy(sjt_isEmpty10);
        }
    }
    if (sjv_mouseHandler != 0) {
        sjv_mouseHandler->_refCount--;
        if (sjv_mouseHandler->_refCount <= 0) {
            sji_mouseHandler_destroy(sjv_mouseHandler);
        }
    }
}

void sjf_fireMouseUp(sji_element* element, sjs_point* point) {
    bool result1;
    bool result2;
    sji_element* sjt_cast18;
    sji_element* sjt_dot149;
    bool sjt_ifElse25;
    bool sjt_ifElse26;
    sji_mouseHandler* sjt_isEmpty8;
    sjs_array_heap_element* sjt_isEmpty9;
    bool sjt_not1;
    bool sjt_not2;
    sjs_array_heap_element* sjv_children;
    sji_mouseHandler* sjv_mouseHandler;

    sjt_cast18 = element;
    sjt_cast18->_refCount++;
    sjv_mouseHandler = (sji_mouseHandler*)sjt_cast18->asInterface(sjt_cast18->_parent, sji_mouseHandler_typeId);
    sjt_isEmpty8 = sjv_mouseHandler;
    if (sjt_isEmpty8 != 0) {
        sjt_isEmpty8->_refCount++;
    }

    sjt_not1 = (sjt_isEmpty8 == 0);
    result1 = !sjt_not1;
    sjt_ifElse25 = result1;
    if (sjt_ifElse25) {
        sji_mouseHandler* sjt_dot148;
        sji_mouseHandler* sjt_getValue7;
        sjs_point* sjt_interfaceParam33;

        sjt_getValue7 = sjv_mouseHandler;
        if (sjt_getValue7 != 0) {
            sjt_getValue7->_refCount++;
        }

        sjt_dot148 = sjt_getValue7;
        sjt_interfaceParam33 = point;
        sjt_dot148->onMouseUp((void*)(((char*)sjt_dot148->_parent) + sizeof(intptr_t)), sjt_interfaceParam33);

        if (sjt_getValue7 != 0) {
            sjt_getValue7->_refCount--;
            if (sjt_getValue7->_refCount <= 0) {
                sji_mouseHandler_destroy(sjt_getValue7);
            }
        }
    }

    sjt_dot149 = element;
    sjt_dot149->getChildren((void*)(((char*)sjt_dot149->_parent) + sizeof(intptr_t)), &sjv_children);
    sjt_isEmpty9 = sjv_children;
    sjt_not2 = (sjt_isEmpty9 == 0);
    result2 = !sjt_not2;
    sjt_ifElse26 = result2;
    if (sjt_ifElse26) {
        int32_t i;
        sjs_array_heap_element* sjt_dot150;
        int32_t sjt_forEnd5;
        int32_t sjt_forStart5;
        sjs_array_heap_element* sjt_getValue8;
        sjs_array_heap_element* sjv_c;

        sjt_getValue8 = sjv_children;
        if (sjt_getValue8 == 0) { exit(-1); };
        sjv_c = sjt_getValue8;
        sjt_forStart5 = 0;
        i = sjt_forStart5;
        sjt_dot150 = sjv_c;
        sjt_forEnd5 = (sjt_dot150)->size;
        while (i < sjt_forEnd5) {
            sjs_array_heap_element* sjt_dot151;
            sji_element* sjt_functionParam30;
            int32_t sjt_functionParam31;
            sjs_point* sjt_functionParam32;

            sjt_dot151 = sjv_c;
            sjt_functionParam31 = i;
            sjf_array_heap_element_getAt_heap(sjt_dot151, sjt_functionParam31, &sjt_functionParam30);
            sjt_functionParam32 = point;
            sjf_fireMouseUp(sjt_functionParam30, sjt_functionParam32);
            i++;

            sjt_functionParam30->_refCount--;
            if (sjt_functionParam30->_refCount <= 0) {
                sji_element_destroy(sjt_functionParam30);
            }
        }
    }

    sjt_cast18->_refCount--;
    if (sjt_cast18->_refCount <= 0) {
        sji_element_destroy(sjt_cast18);
    }
    if (sjt_isEmpty8 != 0) {
        sjt_isEmpty8->_refCount--;
        if (sjt_isEmpty8->_refCount <= 0) {
            sji_mouseHandler_destroy(sjt_isEmpty8);
        }
    }
    if (sjv_mouseHandler != 0) {
        sjv_mouseHandler->_refCount--;
        if (sjv_mouseHandler->_refCount <= 0) {
            sji_mouseHandler_destroy(sjv_mouseHandler);
        }
    }
}

void sjf_font(sjs_font* _this) {
    
	    _this->data = (uintptr_t)TTF_OpenFont((char*)_this->src.data.data, _this->size);
	    if (_this->data == 0) {
	        printf("TTF_OpenFont Error\n");
	    }	
	;
}

void sjf_font_copy(sjs_font* _this, sjs_font* to) {
    sjf_string_copy(&_this->src, &to->src);
    _this->size = to->size;
    _this->data = to->data;
}

void sjf_font_destroy(sjs_font* _this) {
    
	TTF_CloseFont((TTF_Font*)_this->data);	
;
}

void sjf_font_heap(sjs_font_heap* _this) {
    
	    _this->data = (uintptr_t)TTF_OpenFont((char*)_this->src.data.data, _this->size);
	    if (_this->data == 0) {
	        printf("TTF_OpenFont Error\n");
	    }	
	;
}

void sjf_image(sjs_image* _this) {
    bool sjt_and1;
    bool sjt_and2;
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    sjs_rect* sjt_dot1;
    sjs_rect* sjt_dot2;
    bool sjt_ifElse1;

    sjt_dot1 = &_this->rect;
    sjt_compare1 = (sjt_dot1)->w;
    sjt_compare2 = 0;
    sjt_and1 = sjt_compare1 == sjt_compare2;
    sjt_dot2 = &_this->rect;
    sjt_compare3 = (sjt_dot2)->h;
    sjt_compare4 = 0;
    sjt_and2 = sjt_compare3 == sjt_compare4;
    sjt_ifElse1 = sjt_and1 && sjt_and2;
    if (sjt_ifElse1) {
        sjs_texture* sjt_dot3;
        sjs_size* sjt_dot4;
        sjs_size* sjt_dot5;
        sjs_size sjv_size;

        sjt_dot3 = &_this->texture;
        sjf_texture_getSize(sjt_dot3, &sjv_size);
        _this->rect.x = 0;
        _this->rect.y = 0;
        sjt_dot4 = &sjv_size;
        _this->rect.w = (sjt_dot4)->w;
        sjt_dot5 = &sjv_size;
        _this->rect.h = (sjt_dot5)->h;
        sjf_rect(&_this->rect);

        sjf_size_destroy(&sjv_size);
    }
}

void sjf_image_copy(sjs_image* _this, sjs_image* to) {
    sjf_texture_copy(&_this->texture, &to->texture);
    sjf_rect_copy(&_this->rect, &to->rect);
}

void sjf_image_destroy(sjs_image* _this) {
}

void sjf_image_heap(sjs_image_heap* _this) {
    sjs_rect* dotTemp1;
    sjs_rect* dotTemp2;
    bool sjt_and3;
    bool sjt_and4;
    int32_t sjt_compare5;
    int32_t sjt_compare6;
    int32_t sjt_compare7;
    int32_t sjt_compare8;
    sjs_rect* sjt_dot6;
    sjs_rect* sjt_dot7;
    bool sjt_ifElse2;

    dotTemp1 = &_this->rect;
    sjt_dot6 = dotTemp1;
    sjt_compare5 = (sjt_dot6)->w;
    sjt_compare6 = 0;
    sjt_and3 = sjt_compare5 == sjt_compare6;
    dotTemp2 = &_this->rect;
    sjt_dot7 = dotTemp2;
    sjt_compare7 = (sjt_dot7)->h;
    sjt_compare8 = 0;
    sjt_and4 = sjt_compare7 == sjt_compare8;
    sjt_ifElse2 = sjt_and3 && sjt_and4;
    if (sjt_ifElse2) {
        sjs_texture* dotTemp3;
        sjs_size* sjt_dot10;
        sjs_texture* sjt_dot8;
        sjs_size* sjt_dot9;
        sjs_size sjv_size;

        dotTemp3 = &_this->texture;
        sjt_dot8 = dotTemp3;
        sjf_texture_getSize(sjt_dot8, &sjv_size);
        _this->rect.x = 0;
        _this->rect.y = 0;
        sjt_dot9 = &sjv_size;
        _this->rect.w = (sjt_dot9)->w;
        sjt_dot10 = &sjv_size;
        _this->rect.h = (sjt_dot10)->h;
        sjf_rect(&_this->rect);

        sjf_size_destroy(&sjv_size);
    }
}

void sjf_mainLoop(void) {
    sji_surface* sjt_dot141;
    sji_surface* sjt_dot142;
    sjs_size* sjt_dot143;
    sjs_size* sjt_dot144;
    sji_element* sjt_dot145;
    sji_element* sjt_dot146;
    sji_surface* sjt_dot147;
    bool sjt_ifElse24;
    bool sjt_ifElse27;
    sjs_rect* sjt_interfaceParam31;
    sji_surface* sjt_interfaceParam32;
    int32_t sjt_math43;
    int32_t sjt_math44;
    bool sjv_isMouseDown;
    bool sjv_isMouseUp;
    sjs_rect sjv_rect;
    sjs_size sjv_size;
    int32_t sjv_x;
    int32_t sjv_y;

    sjt_dot141 = sjv_rootSurface;
    sjt_dot141->clear((void*)(((char*)sjt_dot141->_parent) + sizeof(intptr_t)));
    sjt_dot142 = sjv_rootSurface;
    sjt_dot142->getSize((void*)(((char*)sjt_dot142->_parent) + sizeof(intptr_t)), &sjv_size);
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot143 = &sjv_size;
    sjv_rect.w = (sjt_dot143)->w;
    sjt_dot144 = &sjv_size;
    sjv_rect.h = (sjt_dot144)->h;
    sjf_rect(&sjv_rect);
    sjt_dot145 = sjv_root;
    sjt_interfaceParam31 = &sjv_rect;
    sjt_dot145->setRect((void*)(((char*)sjt_dot145->_parent) + sizeof(intptr_t)), sjt_interfaceParam31);
    sjt_dot146 = sjv_root;
    sjt_interfaceParam32 = sjv_rootSurface;
    sjt_interfaceParam32->_refCount++;
    sjt_dot146->render((void*)(((char*)sjt_dot146->_parent) + sizeof(intptr_t)), sjt_interfaceParam32);
    sjt_dot147 = sjv_rootSurface;
    sjt_dot147->present((void*)(((char*)sjt_dot147->_parent) + sizeof(intptr_t)));
    sjv_isMouseUp = false;
    sjv_isMouseDown = false;
    sjv_x = 0;
    sjv_y = 0;
    
        SDL_Event e;
        while(SDL_PollEvent( &e ) != 0) {
            switch (e.type) {
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    printf("SDL_MOUSEBUTTONDOWN\n");
                    sjv_isMouseDown = true;
                    sjv_x = e.button.x;
                    sjv_y = e.button.x;
                    break;
                case SDL_MOUSEBUTTONUP:
                    printf("SDL_MOUSEBUTTONUP\n");
                    sjv_isMouseUp = true;
                    sjv_x = e.button.x;
                    sjv_y = e.button.x;
                    break;
            }
        }
    
    ;
    sjt_ifElse24 = sjv_isMouseUp;
    if (sjt_ifElse24) {
        sjs_point sjt_call15;
        sji_element* sjt_functionParam33;
        sjs_point* sjt_functionParam34;

        sjt_functionParam33 = sjv_root;
        sjt_functionParam33->_refCount++;
        sjt_call15.x = sjv_x;
        sjt_call15.y = sjv_y;
        sjf_point(&sjt_call15);
        sjt_functionParam34 = &sjt_call15;
        sjf_fireMouseUp(sjt_functionParam33, sjt_functionParam34);

        sjt_functionParam33->_refCount--;
        if (sjt_functionParam33->_refCount <= 0) {
            sji_element_destroy(sjt_functionParam33);
        }
        sjf_point_destroy(&sjt_call15);
    }

    sjt_ifElse27 = sjv_isMouseDown;
    if (sjt_ifElse27) {
        sjs_point sjt_call16;
        sji_element* sjt_functionParam38;
        sjs_point* sjt_functionParam39;

        sjt_functionParam38 = sjv_root;
        sjt_functionParam38->_refCount++;
        sjt_call16.x = sjv_x;
        sjt_call16.y = sjv_y;
        sjf_point(&sjt_call16);
        sjt_functionParam39 = &sjt_call16;
        sjf_fireMouseDown(sjt_functionParam38, sjt_functionParam39);

        sjt_functionParam38->_refCount--;
        if (sjt_functionParam38->_refCount <= 0) {
            sji_element_destroy(sjt_functionParam38);
        }
        sjf_point_destroy(&sjt_call16);
    }

    sjt_math43 = sjv_frame;
    sjt_math44 = 1;
    sjv_frame = sjt_math43 + sjt_math44;

    sjt_interfaceParam32->_refCount--;
    if (sjt_interfaceParam32->_refCount <= 0) {
        sji_surface_destroy(sjt_interfaceParam32);
    }
    sjf_rect_destroy(&sjv_rect);
    sjf_size_destroy(&sjv_size);
}

void sjf_point(sjs_point* _this) {
}

void sjf_point_copy(sjs_point* _this, sjs_point* to) {
    _this->x = to->x;
    _this->y = to->y;
}

void sjf_point_destroy(sjs_point* _this) {
}

void sjf_point_heap(sjs_point_heap* _this) {
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
	emscripten_set_main_loop((em_callback_func)sjf_mainLoop, 0, 0);
	exit(0);
#else
	bool quit = false;
    while (!quit) {
        sjf_mainLoop();
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

	    _this->win = (uintptr_t)SDL_CreateWindow("Hello World!", 100, 100, _this->size.w, _this->size.h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
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
    _interface->getSize = (void(*)(void*, sjs_size*))sjf_sdlSurface_getSize;
    _interface->getSize_heap = (void(*)(void*, sjs_size_heap**))sjf_sdlSurface_getSize_heap;
    _interface->fillRect = (void(*)(void*,sjs_rect*,sjs_color*))sjf_sdlSurface_fillRect;
    _interface->drawImage = (void(*)(void*,sjs_rect*,sjs_image*))sjf_sdlSurface_drawImage;
    _interface->drawText = (void(*)(void*,sjs_rect*,sjs_font*,sjs_string*,sjs_color*))sjf_sdlSurface_drawText;
    _interface->getTextSize = (void(*)(void*,sjs_font*,sjs_string*, sjs_size*))sjf_sdlSurface_getTextSize;
    _interface->getTextSize_heap = (void(*)(void*,sjs_font*,sjs_string*, sjs_size_heap**))sjf_sdlSurface_getTextSize_heap;
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
    
		if (image->texture.tex) {
			SDL_RenderCopy((SDL_Renderer*)_parent->ren, (SDL_Texture*)image->texture.tex, (SDL_Rect*)&(image->rect), (SDL_Rect*)rect);
		}
	;
}

void sjf_sdlSurface_drawText(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_font* font, sjs_string* text, sjs_color* color) {
    
		if (((char*)text->data.data)[0] != 0) {
			SDL_Color sdlColor;
			sdlColor.r = color->r;
			sdlColor.g = color->g;
			sdlColor.b = color->b;
			sdlColor.a = color->a;
		    SDL_Surface *surf = TTF_RenderText_Blended((TTF_Font*)font->data, (char*)text->data.data, sdlColor);
		    if (surf == 0) {
		        printf("TTF_RenderText Error: %s\n", SDL_GetError());
		    }

		    SDL_Texture *texture = SDL_CreateTextureFromSurface((SDL_Renderer*)_parent->ren, surf);
		    if (texture == 0) {
		        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
		    }

		    SDL_RenderCopy((SDL_Renderer*)_parent->ren, texture, NULL, (SDL_Rect*)rect);

		    SDL_DestroyTexture(texture);

		    //Clean up the surface and font
		    SDL_FreeSurface(surf);
	    }
	;
}

void sjf_sdlSurface_fillRect(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_color* color) {
    
		SDL_SetRenderDrawColor((SDL_Renderer*)_parent->ren, color->r, color->g, color->b, color->a);
		SDL_RenderDrawRect((SDL_Renderer*)_parent->ren, (SDL_Rect*)rect);
	;
}

void sjf_sdlSurface_getSize(sjs_sdlSurface* _parent, sjs_size* _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
     
			SDL_GetRendererOutputSize((SDL_Renderer*)_parent->ren, &sjv_w, &sjv_h);
		;
    _return->w = sjv_w;
    _return->h = sjv_h;
    sjf_size(_return);
}

void sjf_sdlSurface_getSize_heap(sjs_sdlSurface* _parent, sjs_size_heap** _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
     
			SDL_GetRendererOutputSize((SDL_Renderer*)_parent->ren, &sjv_w, &sjv_h);
		;
    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    (*_return)->w = sjv_w;
    (*_return)->h = sjv_h;
    sjf_size_heap((*_return));
}

void sjf_sdlSurface_getTextSize(sjs_sdlSurface* _parent, sjs_font* font, sjs_string* text, sjs_size* _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    
			TTF_SizeUTF8((TTF_Font*)font->data, (char*)text->data.data, &sjv_w, &sjv_h);
		;
    _return->w = sjv_w;
    _return->h = sjv_h;
    sjf_size(_return);
}

void sjf_sdlSurface_getTextSize_heap(sjs_sdlSurface* _parent, sjs_font* font, sjs_string* text, sjs_size_heap** _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    
			TTF_SizeUTF8((TTF_Font*)font->data, (char*)text->data.data, &sjv_w, &sjv_h);
		;
    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    (*_return)->w = sjv_w;
    (*_return)->h = sjv_h;
    sjf_size_heap((*_return));
}

void sjf_sdlSurface_getTexture(sjs_sdlSurface* _parent, sjs_string* src, sjs_texture* _return) {
    int32_t sjt_cast2;
    uintptr_t sjv_tex;

    sjt_cast2 = 0;
    sjv_tex = (uintptr_t)sjt_cast2;
    
		    SDL_Surface* bmp = IMG_Load((char*)src->data.data);
		    if (bmp == 0) {
		        printf("IMG_Load Error: %s for '%s'\n", SDL_GetError(), (char*)src->data.data);
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
    
		    SDL_Surface* bmp = IMG_Load((char*)src->data.data);
		    if (bmp == 0) {
		        printf("IMG_Load Error: %s for '%s'\n", SDL_GetError(), (char*)src->data.data);
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

	    _this->win = (uintptr_t)SDL_CreateWindow("Hello World!", 100, 100, _this->size.w, _this->size.h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
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
    _interface->getSize = (void(*)(void*, sjs_size*))sjf_sdlSurface_getSize;
    _interface->getSize_heap = (void(*)(void*, sjs_size_heap**))sjf_sdlSurface_getSize_heap;
    _interface->fillRect = (void(*)(void*,sjs_rect*,sjs_color*))sjf_sdlSurface_fillRect;
    _interface->drawImage = (void(*)(void*,sjs_rect*,sjs_image*))sjf_sdlSurface_drawImage;
    _interface->drawText = (void(*)(void*,sjs_rect*,sjs_font*,sjs_string*,sjs_color*))sjf_sdlSurface_drawText;
    _interface->getTextSize = (void(*)(void*,sjs_font*,sjs_string*, sjs_size*))sjf_sdlSurface_getTextSize;
    _interface->getTextSize_heap = (void(*)(void*,sjs_font*,sjs_string*, sjs_size_heap**))sjf_sdlSurface_getTextSize_heap;
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

void sjf_size_cap(sjs_size* _parent, sjs_size* maxSize, sjs_size* _return) {
    int32_t sjt_compare21;
    int32_t sjt_compare22;
    sjs_size* sjt_dot90;
    bool sjt_ifElse16;

    sjt_compare21 = (_parent)->w;
    sjt_dot90 = maxSize;
    sjt_compare22 = (sjt_dot90)->w;
    sjt_ifElse16 = sjt_compare21 < sjt_compare22;
    if (sjt_ifElse16) {
        _return->w = (_parent)->w;
    } else {
        sjs_size* sjt_dot91;

        sjt_dot91 = maxSize;
        _return->w = (sjt_dot91)->w;
    }

    _return->h = 0;
    sjf_size(_return);
}

void sjf_size_cap_heap(sjs_size* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    int32_t sjt_compare23;
    int32_t sjt_compare24;
    sjs_size* sjt_dot92;
    bool sjt_ifElse17;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_compare23 = (_parent)->w;
    sjt_dot92 = maxSize;
    sjt_compare24 = (sjt_dot92)->w;
    sjt_ifElse17 = sjt_compare23 < sjt_compare24;
    if (sjt_ifElse17) {
        (*_return)->w = (_parent)->w;
    } else {
        sjs_size* sjt_dot93;

        sjt_dot93 = maxSize;
        (*_return)->w = (sjt_dot93)->w;
    }

    (*_return)->h = 0;
    sjf_size_heap((*_return));
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
    int32_t sjt_compare31;
    int32_t sjt_compare32;
    sjs_string* sjt_dot114;
    bool sjt_ifElse21;

    sjt_dot114 = item;
    sjt_compare31 = (sjt_dot114)->count;
    sjt_compare32 = 0;
    sjt_ifElse21 = sjt_compare31 > sjt_compare32;
    if (sjt_ifElse21) {
        int32_t i;
        int32_t sjt_cast13;
        int32_t sjt_compare33;
        int32_t sjt_compare34;
        sjs_string* sjt_dot115;
        sjs_array_char* sjt_dot116;
        sjs_string* sjt_dot119;
        sjs_array_char* sjt_dot123;
        int32_t sjt_forEnd4;
        int32_t sjt_forStart4;
        int32_t sjt_functionParam16;
        char sjt_functionParam17;
        bool sjt_ifElse22;
        int32_t sjt_math29;
        int32_t sjt_math30;
        int32_t sjt_math31;
        int32_t sjt_math32;

        sjt_math31 = (_parent)->count;
        sjt_dot115 = item;
        sjt_math32 = (sjt_dot115)->count;
        sjt_math29 = sjt_math31 + sjt_math32;
        sjt_math30 = 1;
        sjt_compare33 = sjt_math29 + sjt_math30;
        sjt_dot116 = &(_parent)->data;
        sjt_compare34 = (sjt_dot116)->size;
        sjt_ifElse22 = sjt_compare33 > sjt_compare34;
        if (sjt_ifElse22) {
            sjs_array_char* sjt_dot117;
            sjs_string* sjt_dot118;
            int32_t sjt_functionParam11;
            int32_t sjt_math33;
            int32_t sjt_math34;
            int32_t sjt_math35;
            int32_t sjt_math36;

            sjt_dot117 = &(_parent)->data;
            sjt_math35 = (_parent)->count;
            sjt_dot118 = item;
            sjt_math36 = (sjt_dot118)->count;
            sjt_math33 = sjt_math35 + sjt_math36;
            sjt_math34 = 1;
            sjt_functionParam11 = sjt_math33 + sjt_math34;
            sjf_array_char_grow(sjt_dot117, sjt_functionParam11);
        }

        sjt_forStart4 = 0;
        i = sjt_forStart4;
        sjt_dot119 = item;
        sjt_forEnd4 = (sjt_dot119)->count;
        while (i < sjt_forEnd4) {
            sjs_array_char* sjt_dot120;
            sjs_string* sjt_dot121;
            int32_t sjt_functionParam12;
            char sjt_functionParam13;
            int32_t sjt_functionParam15;
            int32_t sjt_math37;
            int32_t sjt_math38;

            sjt_dot120 = &(_parent)->data;
            sjt_functionParam12 = (_parent)->count;
            sjt_dot121 = item;
            sjt_functionParam15 = i;
            sjf_string_getAt(sjt_dot121, sjt_functionParam15, &sjt_functionParam13);
            sjf_array_char_setAt(sjt_dot120, sjt_functionParam12, sjt_functionParam13);
            sjt_math37 = (_parent)->count;
            sjt_math38 = 1;
            _parent->count = sjt_math37 + sjt_math38;
            i++;
        }

        sjt_dot123 = &(_parent)->data;
        sjt_functionParam16 = (_parent)->count;
        sjt_cast13 = 0;
        sjt_functionParam17 = (char)sjt_cast13;
        sjf_array_char_setAt(sjt_dot123, sjt_functionParam16, sjt_functionParam17);
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
    sjs_array_char* sjt_dot122;
    int32_t sjt_functionParam14;

    sjt_dot122 = &(_parent)->data;
    sjt_functionParam14 = index;
    sjf_array_char_getAt(sjt_dot122, sjt_functionParam14, _return);
}

void sjf_string_heap(sjs_string_heap* _this) {
}

void sjf_texture(sjs_texture* _this) {
}

void sjf_texture_copy(sjs_texture* _this, sjs_texture* to) {
    _this->tex = to->tex;
}

void sjf_texture_destroy(sjs_texture* _this) {
    
	if (_this->tex) {
		SDL_DestroyTexture((SDL_Texture*)_this->tex);	
	}
;
}

void sjf_texture_getSize(sjs_texture* _parent, sjs_size* _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    
			if (_parent->tex) {
				SDL_QueryTexture((SDL_Texture*)_parent->tex, NULL, NULL, &sjv_w, &sjv_h);
			}
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
    
			if (_parent->tex) {
				SDL_QueryTexture((SDL_Texture*)_parent->tex, NULL, NULL, &sjv_w, &sjv_h);
			}
		;
    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    (*_return)->w = sjv_w;
    (*_return)->h = sjv_h;
    sjf_size_heap((*_return));
}

void sjf_texture_heap(sjs_texture_heap* _this) {
}

void sji_borderChild_copy(sji_borderChild* _this, sji_borderChild* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->getPosition = _from->getPosition;
}

void sji_borderChild_destroy(sji_borderChild* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

void sji_element_copy(sji_element* _this, sji_element* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->getSize = _from->getSize;
    _this->getSize = _from->getSize;
    _this->setRect = _from->setRect;
    _this->render = _from->render;
    _this->getChildren = _from->getChildren;
}

void sji_element_destroy(sji_element* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

void sji_mouseHandler_copy(sji_mouseHandler* _this, sji_mouseHandler* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->onMouseUp = _from->onMouseUp;
    _this->onMouseDown = _from->onMouseDown;
    _this->onMouseMove = _from->onMouseMove;
}

void sji_mouseHandler_destroy(sji_mouseHandler* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

void sji_surface_copy(sji_surface* _this, sji_surface* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->clear = _from->clear;
    _this->present = _from->present;
    _this->getSize = _from->getSize;
    _this->getSize = _from->getSize;
    _this->fillRect = _from->fillRect;
    _this->drawImage = _from->drawImage;
    _this->drawText = _from->drawText;
    _this->getTextSize = _from->getTextSize;
    _this->getTextSize = _from->getTextSize;
    _this->getTexture = _from->getTexture;
    _this->getTexture = _from->getTexture;
}

void sji_surface_destroy(sji_surface* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
    sjv_borderPosition.fill = 0;
    sjv_borderPosition.left = 1;
    sjv_borderPosition.right = 2;
    sjv_borderPosition.top = 3;
    sjv_borderPosition.bottom = 4;
    sjf_anon8(&sjv_borderPosition);
    sjf_anon7(&sjv_style);
    sjf_anon6(&sjv_colors);
    sjv_buttonState.normal = 0;
    sjv_buttonState.hot = 1;
    sjv_buttonState.pressed = 2;
    sjf_anon5(&sjv_buttonState);
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
    sjt_cast6 = (sjs_borderLayout_heap*)malloc(sizeof(sjs_borderLayout_heap));
    sjt_cast6->_refCount = 1;
    sjt_cast6->children.size = 1;
    sjt_cast9 = 0;
    sjt_cast6->children.data = (uintptr_t)sjt_cast9;
    sjt_cast6->children._isGlobal = false;
    sjf_array_heap_element(&sjt_cast6->children);
    sjt_functionParam4 = 0;
    sjt_cast10 = (sjs_borderChild_heap*)malloc(sizeof(sjs_borderChild_heap));
    sjt_cast10->_refCount = 1;
    sjt_cast12 = (sjs_buttonElement_heap*)malloc(sizeof(sjs_buttonElement_heap));
    sjt_cast12->_refCount = 1;
    sjt_cast12->text.count = 11;
    sjt_cast12->text.data.size = 12;
    sjt_cast12->text.data.data = (uintptr_t)sjg_string11;
    sjt_cast12->text.data._isGlobal = false;
    sjf_array_char(&sjt_cast12->text.data);
    sjf_string(&sjt_cast12->text);
    sjt_dot134 = &sjv_colors;
    sjf_anon6_black(sjt_dot134, &sjt_cast12->textColor);
    sjt_dot135 = &sjv_style;
    sjt_functionParam29 = 0;
    sjf_anon7_getFont(sjt_dot135, sjt_functionParam29, &sjt_cast12->font);
    sjt_cast12->rect.x = 0;
    sjt_cast12->rect.y = 0;
    sjt_cast12->rect.w = 0;
    sjt_cast12->rect.h = 0;
    sjf_rect(&sjt_cast12->rect);
    sjt_dot136 = sjv_rootSurface;
    sjt_call12.count = 23;
    sjt_call12.data.size = 24;
    sjt_call12.data.data = (uintptr_t)sjg_string6;
    sjt_call12.data._isGlobal = false;
    sjf_array_char(&sjt_call12.data);
    sjf_string(&sjt_call12);
    sjt_interfaceParam28 = &sjt_call12;
    sjt_dot136->getTexture((void*)(((char*)sjt_dot136->_parent) + sizeof(intptr_t)), sjt_interfaceParam28, &sjt_cast12->normalImage.texture);
    sjt_cast12->normalImage.rect.x = 0;
    sjt_cast12->normalImage.rect.y = 0;
    sjt_cast12->normalImage.rect.w = 0;
    sjt_cast12->normalImage.rect.h = 0;
    sjf_rect(&sjt_cast12->normalImage.rect);
    sjf_image(&sjt_cast12->normalImage);
    sjt_dot137 = sjv_rootSurface;
    sjt_call13.count = 20;
    sjt_call13.data.size = 21;
    sjt_call13.data.data = (uintptr_t)sjg_string8;
    sjt_call13.data._isGlobal = false;
    sjf_array_char(&sjt_call13.data);
    sjf_string(&sjt_call13);
    sjt_interfaceParam29 = &sjt_call13;
    sjt_dot137->getTexture((void*)(((char*)sjt_dot137->_parent) + sizeof(intptr_t)), sjt_interfaceParam29, &sjt_cast12->hotImage.texture);
    sjt_cast12->hotImage.rect.x = 0;
    sjt_cast12->hotImage.rect.y = 0;
    sjt_cast12->hotImage.rect.w = 0;
    sjt_cast12->hotImage.rect.h = 0;
    sjf_rect(&sjt_cast12->hotImage.rect);
    sjf_image(&sjt_cast12->hotImage);
    sjt_dot138 = sjv_rootSurface;
    sjt_call14.count = 24;
    sjt_call14.data.size = 25;
    sjt_call14.data.data = (uintptr_t)sjg_string10;
    sjt_call14.data._isGlobal = false;
    sjf_array_char(&sjt_call14.data);
    sjf_string(&sjt_call14);
    sjt_interfaceParam30 = &sjt_call14;
    sjt_dot138->getTexture((void*)(((char*)sjt_dot138->_parent) + sizeof(intptr_t)), sjt_interfaceParam30, &sjt_cast12->pressedImage.texture);
    sjt_cast12->pressedImage.rect.x = 0;
    sjt_cast12->pressedImage.rect.y = 0;
    sjt_cast12->pressedImage.rect.w = 0;
    sjt_cast12->pressedImage.rect.h = 0;
    sjf_rect(&sjt_cast12->pressedImage.rect);
    sjf_image(&sjt_cast12->pressedImage);
    sjt_dot139 = &sjv_buttonState;
    sjt_cast12->state = (sjt_dot139)->normal;
    sjf_buttonElement_heap(sjt_cast12);
    sjt_cast10->child = (sji_element*)sjf_buttonElement_heap_as_sji_element(sjt_cast12);
    sjt_cast10->rect.x = 0;
    sjt_cast10->rect.y = 0;
    sjt_cast10->rect.w = 0;
    sjt_cast10->rect.h = 0;
    sjf_rect(&sjt_cast10->rect);
    sjt_dot140 = &sjv_borderPosition;
    sjt_cast10->position = (sjt_dot140)->left;
    sjt_cast10->_children = 0;
    if (sjt_cast10->_children != 0) {
        sjt_cast10->_children->_refCount++;
    }

    sjf_borderChild_heap(sjt_cast10);
    sjt_functionParam5 = (sji_element*)sjf_borderChild_heap_as_sji_element(sjt_cast10);
    sjf_array_heap_element_initAt(&sjt_cast6->children, sjt_functionParam4, sjt_functionParam5);
    sjt_cast6->rect.x = 0;
    sjt_cast6->rect.y = 0;
    sjt_cast6->rect.w = 0;
    sjt_cast6->rect.h = 0;
    sjf_rect(&sjt_cast6->rect);
    sjf_borderLayout_heap(sjt_cast6);
    sjv_root = (sji_element*)sjf_borderLayout_heap_as_sji_element(sjt_cast6);
    sjf_runLoop();
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_cast1->_refCount--;
    if (sjt_cast1->_refCount <= 0) {
        sjf_sdlSurface_destroy((sjs_sdlSurface*)(((char*)sjt_cast1) + sizeof(intptr_t)));
    }
    sjt_cast10->_refCount--;
    if (sjt_cast10->_refCount <= 0) {
        sjf_borderChild_destroy((sjs_borderChild*)(((char*)sjt_cast10) + sizeof(intptr_t)));
    }
    sjt_cast12->_refCount--;
    if (sjt_cast12->_refCount <= 0) {
        sjf_buttonElement_destroy((sjs_buttonElement*)(((char*)sjt_cast12) + sizeof(intptr_t)));
    }
    sjt_cast6->_refCount--;
    if (sjt_cast6->_refCount <= 0) {
        sjf_borderLayout_destroy((sjs_borderLayout*)(((char*)sjt_cast6) + sizeof(intptr_t)));
    }
    sjt_functionParam5->_refCount--;
    if (sjt_functionParam5->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam5);
    }
    sjv_root->_refCount--;
    if (sjv_root->_refCount <= 0) {
        sji_element_destroy(sjv_root);
    }
    sjv_rootSurface->_refCount--;
    if (sjv_rootSurface->_refCount <= 0) {
        sji_surface_destroy(sjv_rootSurface);
    }
    sjf_string_destroy(&sjt_call12);
    sjf_string_destroy(&sjt_call13);
    sjf_string_destroy(&sjt_call14);
    sjf_anon8_destroy(&sjv_borderPosition);
    sjf_anon5_destroy(&sjv_buttonState);
    sjf_anon6_destroy(&sjv_colors);
    sjf_anon1_destroy(&sjv_console);
    sjf_anon4_destroy(&sjv_convert);
    sjf_anon2_destroy(&sjv_parse);
    sjf_anon3_destroy(&sjv_random);
    sjf_anon7_destroy(&sjv_style);
}
