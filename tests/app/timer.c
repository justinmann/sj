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
#define sjs_borderLayout_heap_typeId 41
#define sjs_borderChild_typeId 42
#define sji_borderChild_typeId 43
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
typedef struct td_sjs_borderLayout_heap sjs_borderLayout_heap;
typedef struct td_sjs_borderChild sjs_borderChild;
typedef struct td_sji_borderChild sji_borderChild;
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
    void (*setRect)(void* _parent, sjs_rect* rect);
    void (*render)(void* _parent, sji_surface* surface);
    void (*getChildren)(void* _parent, sjs_array_heap_element** _return);
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

struct td_sji_borderChild {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*getPosition)(void* _parent, int32_t* _return);
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


	
	
	
	
    
	
	
    
	
	
    

sjs_string sjt_call7;
sjs_string sjt_call8;
sjs_string sjt_call9;
sjs_sdlSurface_heap* sjt_cast1;
sjs_buttonElement_heap* sjt_cast10;
int32_t sjt_cast4;
int32_t sjt_cast5;
sjs_borderLayout_heap* sjt_cast6;
int32_t sjt_cast7;
sjs_borderChild_heap* sjt_cast8;
sjs_anon6* sjt_dot57;
sjs_anon7* sjt_dot58;
sji_surface* sjt_dot59;
sji_surface* sjt_dot60;
sji_surface* sjt_dot61;
sjs_anon5* sjt_dot62;
sjs_anon8* sjt_dot63;
int32_t sjt_functionParam26;
int32_t sjt_functionParam3;
sji_element* sjt_functionParam4;
sjs_string* sjt_interfaceParam17;
sjs_string* sjt_interfaceParam18;
sjs_string* sjt_interfaceParam19;
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
    int32_t sjt_cast12;
    int32_t sjt_math19;
    int32_t sjt_math20;
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
    int32_t sjt_cast13;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjv_count;
    uintptr_t sjv_data;

    sjv_count = 0;
    sjt_cast13 = 0;
    sjv_data = (uintptr_t)sjt_cast13;
    
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
    int32_t sjt_cast14;

    _return->src.count = 17;
    _return->src.data.size = 18;
    _return->src.data.data = (uintptr_t)sjg_string3;
    _return->src.data._isGlobal = false;
    sjf_array_char(&_return->src.data);
    sjf_string(&_return->src);
    _return->size = 12;
    sjt_cast14 = 0;
    _return->data = (uintptr_t)sjt_cast14;
    sjf_font(_return);
}

void sjf_anon7_getFont_heap(sjs_anon7* _parent, int32_t typeId, sjs_font_heap** _return) {
    int32_t sjt_cast15;

    (*_return) = (sjs_font_heap*)malloc(sizeof(sjs_font_heap));
    (*_return)->_refCount = 1;
    (*_return)->src.count = 17;
    (*_return)->src.data.size = 18;
    (*_return)->src.data.data = (uintptr_t)sjg_string4;
    (*_return)->src.data._isGlobal = false;
    sjf_array_char(&(*_return)->src.data);
    sjf_string(&(*_return)->src);
    (*_return)->size = 12;
    sjt_cast15 = 0;
    (*_return)->data = (uintptr_t)sjt_cast15;
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
    bool sjt_ifElse3;
    sjs_array_heap_element_heap* sjt_isEmpty1;

    sjt_isEmpty1 = (_parent)->_children;
    if (sjt_isEmpty1 != 0) {
        sjt_isEmpty1->_refCount++;
    }

    sjt_ifElse3 = (sjt_isEmpty1 == 0);
    if (sjt_ifElse3) {
        int32_t sjt_cast9;
        int32_t sjt_functionParam5;
        sji_element* sjt_functionParam6;
        sjs_array_heap_element_heap* sjt_value2;

        sjt_value2 = (sjs_array_heap_element_heap*)malloc(sizeof(sjs_array_heap_element_heap));
        sjt_value2->_refCount = 1;
        sjt_value2->size = 1;
        sjt_cast9 = 0;
        sjt_value2->data = (uintptr_t)sjt_cast9;
        sjt_value2->_isGlobal = false;
        sjf_array_heap_element_heap(sjt_value2);
        sjt_functionParam5 = 0;
        sjt_functionParam6 = (_parent)->child;
        sjt_functionParam6->_refCount++;
        sjf_array_heap_element_initAt((sjs_array_heap_element*)(((char*)sjt_value2) + sizeof(intptr_t)), sjt_functionParam5, sjt_functionParam6);
        if (_parent->_children != 0) {
            _parent->_children->_refCount--;
            if (_parent->_children->_refCount <= 0) {
                sjf_array_heap_element_destroy((sjs_array_heap_element*)(((char*)_parent->_children) + sizeof(intptr_t)));
            }
        }

        _parent->_children = sjt_value2;
        if (_parent->_children != 0) {
            _parent->_children->_refCount++;
        }

        sjt_functionParam6->_refCount--;
        if (sjt_functionParam6->_refCount <= 0) {
            sji_element_destroy(sjt_functionParam6);
        }
        sjt_value2->_refCount--;
        if (sjt_value2->_refCount <= 0) {
            sjf_array_heap_element_destroy((sjs_array_heap_element*)(((char*)sjt_value2) + sizeof(intptr_t)));
        }
    } else {
    }

    (*_return) = (sjs_array_heap_element*)(((char*)(_parent)->_children) + sizeof(intptr_t));

    if (sjt_isEmpty1 != 0) {
        sjt_isEmpty1->_refCount--;
        if (sjt_isEmpty1->_refCount <= 0) {
            sjf_array_heap_element_destroy((sjs_array_heap_element*)(((char*)sjt_isEmpty1) + sizeof(intptr_t)));
        }
    }
}

void sjf_borderChild_getPosition(sjs_borderChild* _parent, int32_t* _return) {
    (*_return) = (_parent)->position;
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
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_borderChild_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_borderChild_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_borderChild_getChildren;

    return _interface;
}

void sjf_borderChild_render(sjs_borderChild* _parent, sji_surface* surface) {
    sji_element* sjt_dot18;
    sji_surface* sjt_interfaceParam4;

    sjt_dot18 = (_parent)->child;
    sjt_interfaceParam4 = surface;
    sjt_interfaceParam4->_refCount++;
    sjt_dot18->render((void*)(((char*)sjt_dot18->_parent) + sizeof(intptr_t)), sjt_interfaceParam4);

    sjt_interfaceParam4->_refCount--;
    if (sjt_interfaceParam4->_refCount <= 0) {
        sji_surface_destroy(sjt_interfaceParam4);
    }
}

void sjf_borderChild_setRect(sjs_borderChild* _parent, sjs_rect* rect_) {
    sji_element* sjt_dot17;
    sjs_rect* sjt_interfaceParam3;

    sjf_rect_copy(&_parent->rect, rect_);
    sjt_dot17 = (_parent)->child;
    sjt_interfaceParam3 = &(_parent)->rect;
    sjt_dot17->setRect((void*)(((char*)sjt_dot17->_parent) + sizeof(intptr_t)), sjt_interfaceParam3);
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
    sjs_array_heap_element* sjt_value1;
    sjs_array_heap_element* sjv_a;

    sjv_a = &(_parent)->children;
    sjt_value1 = sjv_a;
    (*_return) = sjt_value1;
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
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_borderLayout_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_borderLayout_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_borderLayout_getChildren;

    return _interface;
}

void sjf_borderLayout_render(sjs_borderLayout* _parent, sji_surface* surface) {
    int32_t i;
    sjs_array_heap_element* sjt_dot14;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;

    sjt_forStart2 = 0;
    i = sjt_forStart2;
    sjt_dot14 = &(_parent)->children;
    sjt_forEnd2 = (sjt_dot14)->size;
    while (i < sjt_forEnd2) {
        sjs_array_heap_element* sjt_dot15;
        sji_element* sjt_dot16;
        int32_t sjt_functionParam2;
        sji_surface* sjt_interfaceParam2;
        sji_element* sjv_child;

        sjt_dot15 = &(_parent)->children;
        sjt_functionParam2 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot15, sjt_functionParam2, &sjv_child);
        sjt_dot16 = sjv_child;
        sjt_interfaceParam2 = surface;
        sjt_interfaceParam2->_refCount++;
        sjt_dot16->render((void*)(((char*)sjt_dot16->_parent) + sizeof(intptr_t)), sjt_interfaceParam2);
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
}

void sjf_borderLayout_setRect(sjs_borderLayout* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_array_heap_element* sjt_dot11;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

    sjf_rect_copy(&_parent->rect, rect_);
    sjt_forStart1 = 0;
    i = sjt_forStart1;
    sjt_dot11 = &(_parent)->children;
    sjt_forEnd1 = (sjt_dot11)->size;
    while (i < sjt_forEnd1) {
        sjs_array_heap_element* sjt_dot12;
        sji_element* sjt_dot13;
        int32_t sjt_functionParam1;
        sjs_rect* sjt_interfaceParam1;
        sji_element* sjv_child;

        sjt_dot12 = &(_parent)->children;
        sjt_functionParam1 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot12, sjt_functionParam1, &sjv_child);
        sjt_dot13 = sjv_child;
        sjt_interfaceParam1 = &(_parent)->rect;
        sjt_dot13->setRect((void*)(((char*)sjt_dot13->_parent) + sizeof(intptr_t)), sjt_interfaceParam1);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }
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
    sjs_string sjt_call5;
    sjs_anon1* sjt_dot52;
    sjs_anon5* sjt_dot53;
    sjs_string* sjt_functionParam24;

    sjt_dot52 = &sjv_console;
    sjt_call5.count = 25;
    sjt_call5.data.size = 26;
    sjt_call5.data.data = (uintptr_t)sjg_string17;
    sjt_call5.data._isGlobal = false;
    sjf_array_char(&sjt_call5.data);
    sjf_string(&sjt_call5);
    sjt_functionParam24 = &sjt_call5;
    sjf_anon1_write(sjt_dot52, sjt_functionParam24);
    sjt_dot53 = &sjv_buttonState;
    _parent->state = (sjt_dot53)->pressed;

    sjf_string_destroy(&sjt_call5);
}

void sjf_buttonElement_onMouseMove(sjs_buttonElement* _parent, sjs_point* point) {
    sjs_string sjt_call6;
    int32_t sjt_compare19;
    int32_t sjt_compare20;
    sjs_anon1* sjt_dot54;
    sjs_anon5* sjt_dot55;
    sjs_string* sjt_functionParam25;
    bool sjt_ifElse9;

    sjt_dot54 = &sjv_console;
    sjt_call6.count = 25;
    sjt_call6.data.size = 26;
    sjt_call6.data.data = (uintptr_t)sjg_string19;
    sjt_call6.data._isGlobal = false;
    sjf_array_char(&sjt_call6.data);
    sjf_string(&sjt_call6);
    sjt_functionParam25 = &sjt_call6;
    sjf_anon1_write(sjt_dot54, sjt_functionParam25);
    sjt_compare19 = (_parent)->state;
    sjt_dot55 = &sjv_buttonState;
    sjt_compare20 = (sjt_dot55)->normal;
    sjt_ifElse9 = sjt_compare19 == sjt_compare20;
    if (sjt_ifElse9) {
        sjs_anon5* sjt_dot56;

        sjt_dot56 = &sjv_buttonState;
        _parent->state = (sjt_dot56)->hot;
    } else {
    }

    sjf_string_destroy(&sjt_call6);
}

void sjf_buttonElement_onMouseUp(sjs_buttonElement* _parent, sjs_point* point) {
    sjs_string sjt_call1;
    sjs_string sjt_call2;
    sjs_string sjt_call3;
    sjs_string sjt_call4;
    sjs_anon1* sjt_dot33;
    sjs_string* sjt_dot34;
    sjs_string* sjt_dot35;
    sjs_string* sjt_dot36;
    sjs_anon4* sjt_dot47;
    sjs_point* sjt_dot48;
    sjs_anon4* sjt_dot49;
    sjs_point* sjt_dot50;
    sjs_anon5* sjt_dot51;
    sjs_string* sjt_functionParam15;
    int32_t sjt_functionParam16;
    int32_t sjt_functionParam17;
    int32_t sjt_functionParam18;
    sjs_string* sjt_functionParam19;
    sjs_string* sjt_functionParam20;
    int32_t sjt_functionParam21;
    int32_t sjt_functionParam22;
    int32_t sjt_functionParam23;
    sjs_string* sjt_functionParam7;

    sjt_dot33 = &sjv_console;
    sjt_call1.count = 24;
    sjt_call1.data.size = 25;
    sjt_call1.data.data = (uintptr_t)sjg_string13;
    sjt_call1.data._isGlobal = false;
    sjf_array_char(&sjt_call1.data);
    sjf_string(&sjt_call1);
    sjt_dot36 = &sjt_call1;
    sjt_dot47 = &sjv_convert;
    sjt_dot48 = point;
    sjt_functionParam16 = (sjt_dot48)->x;
    sjt_functionParam17 = 10;
    sjt_functionParam18 = 0;
    sjf_anon4_i32toString(sjt_dot47, sjt_functionParam16, sjt_functionParam17, sjt_functionParam18, &sjt_call2);
    sjt_functionParam15 = &sjt_call2;
    sjf_string_add(sjt_dot36, sjt_functionParam15, &sjt_dot35);
    sjt_call3.count = 2;
    sjt_call3.data.size = 3;
    sjt_call3.data.data = (uintptr_t)sjg_string14;
    sjt_call3.data._isGlobal = false;
    sjf_array_char(&sjt_call3.data);
    sjf_string(&sjt_call3);
    sjt_functionParam19 = &sjt_call3;
    sjf_string_add(sjt_dot35, sjt_functionParam19, &sjt_dot34);
    sjt_dot49 = &sjv_convert;
    sjt_dot50 = point;
    sjt_functionParam21 = (sjt_dot50)->y;
    sjt_functionParam22 = 10;
    sjt_functionParam23 = 0;
    sjf_anon4_i32toString(sjt_dot49, sjt_functionParam21, sjt_functionParam22, sjt_functionParam23, &sjt_call4);
    sjt_functionParam20 = &sjt_call4;
    sjf_string_add(sjt_dot34, sjt_functionParam20, &sjt_functionParam7);
    sjf_anon1_write(sjt_dot33, sjt_functionParam7);
    sjt_dot51 = &sjv_buttonState;
    _parent->state = (sjt_dot51)->normal;

    sjf_string_destroy(&sjt_call1);
    sjf_string_destroy(&sjt_call2);
    sjf_string_destroy(&sjt_call3);
    sjf_string_destroy(&sjt_call4);
}

void sjf_buttonElement_render(sjs_buttonElement* _parent, sji_surface* surface) {
    int32_t sjt_compare10;
    int32_t sjt_compare9;
    sjs_anon5* sjt_dot19;
    sji_surface* sjt_dot25;
    sjs_rect* sjt_dot26;
    sjs_size* sjt_dot27;
    sjs_rect* sjt_dot28;
    sjs_size* sjt_dot29;
    sjs_size* sjt_dot30;
    sjs_size* sjt_dot31;
    sji_surface* sjt_dot32;
    bool sjt_ifElse4;
    sjs_font* sjt_interfaceParam11;
    sjs_string* sjt_interfaceParam12;
    sjs_rect* sjt_interfaceParam13;
    sjs_font* sjt_interfaceParam14;
    sjs_string* sjt_interfaceParam15;
    sjs_color* sjt_interfaceParam16;
    int32_t sjt_math1;
    int32_t sjt_math2;
    int32_t sjt_math3;
    int32_t sjt_math4;
    int32_t sjt_math5;
    int32_t sjt_math6;
    int32_t sjt_math7;
    int32_t sjt_math8;
    sjs_rect sjv_textRect;
    sjs_size sjv_textSize;

    sjt_compare9 = (_parent)->state;
    sjt_dot19 = &sjv_buttonState;
    sjt_compare10 = (sjt_dot19)->normal;
    sjt_ifElse4 = sjt_compare9 == sjt_compare10;
    if (sjt_ifElse4) {
        sji_surface* sjt_dot20;
        sjs_rect* sjt_interfaceParam5;
        sjs_image* sjt_interfaceParam6;

        sjt_dot20 = surface;
        sjt_interfaceParam5 = &(_parent)->rect;
        sjt_interfaceParam6 = &(_parent)->normalImage;
        sjt_dot20->drawImage((void*)(((char*)sjt_dot20->_parent) + sizeof(intptr_t)), sjt_interfaceParam5, sjt_interfaceParam6);
    } else {
        int32_t sjt_compare11;
        int32_t sjt_compare12;
        sjs_anon5* sjt_dot21;
        bool sjt_ifElse5;

        sjt_compare11 = (_parent)->state;
        sjt_dot21 = &sjv_buttonState;
        sjt_compare12 = (sjt_dot21)->hot;
        sjt_ifElse5 = sjt_compare11 == sjt_compare12;
        if (sjt_ifElse5) {
            sji_surface* sjt_dot22;
            sjs_rect* sjt_interfaceParam7;
            sjs_image* sjt_interfaceParam8;

            sjt_dot22 = surface;
            sjt_interfaceParam7 = &(_parent)->rect;
            sjt_interfaceParam8 = &(_parent)->hotImage;
            sjt_dot22->drawImage((void*)(((char*)sjt_dot22->_parent) + sizeof(intptr_t)), sjt_interfaceParam7, sjt_interfaceParam8);
        } else {
            int32_t sjt_compare13;
            int32_t sjt_compare14;
            sjs_anon5* sjt_dot23;
            bool sjt_ifElse6;

            sjt_compare13 = (_parent)->state;
            sjt_dot23 = &sjv_buttonState;
            sjt_compare14 = (sjt_dot23)->pressed;
            sjt_ifElse6 = sjt_compare13 == sjt_compare14;
            if (sjt_ifElse6) {
                sji_surface* sjt_dot24;
                sjs_image* sjt_interfaceParam10;
                sjs_rect* sjt_interfaceParam9;

                sjt_dot24 = surface;
                sjt_interfaceParam9 = &(_parent)->rect;
                sjt_interfaceParam10 = &(_parent)->pressedImage;
                sjt_dot24->drawImage((void*)(((char*)sjt_dot24->_parent) + sizeof(intptr_t)), sjt_interfaceParam9, sjt_interfaceParam10);
            }
        }
    }

    sjt_dot25 = surface;
    sjt_interfaceParam11 = &(_parent)->font;
    sjt_interfaceParam12 = &(_parent)->text;
    sjt_dot25->getTextSize((void*)(((char*)sjt_dot25->_parent) + sizeof(intptr_t)), sjt_interfaceParam11, sjt_interfaceParam12, &sjv_textSize);
    sjt_dot26 = &(_parent)->rect;
    sjt_math3 = (sjt_dot26)->w;
    sjt_dot27 = &sjv_textSize;
    sjt_math4 = (sjt_dot27)->w;
    sjt_math1 = sjt_math3 - sjt_math4;
    sjt_math2 = 2;
    sjv_textRect.x = sjt_math1 / sjt_math2;
    sjt_dot28 = &(_parent)->rect;
    sjt_math7 = (sjt_dot28)->h;
    sjt_dot29 = &sjv_textSize;
    sjt_math8 = (sjt_dot29)->h;
    sjt_math5 = sjt_math7 - sjt_math8;
    sjt_math6 = 2;
    sjv_textRect.y = sjt_math5 / sjt_math6;
    sjt_dot30 = &sjv_textSize;
    sjv_textRect.w = (sjt_dot30)->w;
    sjt_dot31 = &sjv_textSize;
    sjv_textRect.h = (sjt_dot31)->h;
    sjf_rect(&sjv_textRect);
    sjt_dot32 = surface;
    sjt_interfaceParam13 = &sjv_textRect;
    sjt_interfaceParam14 = &(_parent)->font;
    sjt_interfaceParam15 = &(_parent)->text;
    sjt_interfaceParam16 = &(_parent)->textColor;
    sjt_dot32->drawText((void*)(((char*)sjt_dot32->_parent) + sizeof(intptr_t)), sjt_interfaceParam13, sjt_interfaceParam14, sjt_interfaceParam15, sjt_interfaceParam16);

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
    sji_element* sjt_cast17;
    sji_element* sjt_dot76;
    bool sjt_ifElse14;
    bool sjt_ifElse15;
    sji_mouseHandler* sjt_isEmpty4;
    sjs_array_heap_element* sjt_isEmpty5;
    bool sjt_not3;
    bool sjt_not4;
    sjs_array_heap_element* sjv_children;
    sji_mouseHandler* sjv_mouseHandler;

    sjt_cast17 = element;
    sjt_cast17->_refCount++;
    sjv_mouseHandler = (sji_mouseHandler*)sjt_cast17->asInterface(sjt_cast17->_parent, sji_mouseHandler_typeId);
    sjt_isEmpty4 = sjv_mouseHandler;
    if (sjt_isEmpty4 != 0) {
        sjt_isEmpty4->_refCount++;
    }

    sjt_not3 = (sjt_isEmpty4 == 0);
    result3 = !sjt_not3;
    sjt_ifElse14 = result3;
    if (sjt_ifElse14) {
        sji_mouseHandler* sjt_dot75;
        sji_mouseHandler* sjt_getValue3;
        sjs_point* sjt_interfaceParam23;

        sjt_getValue3 = sjv_mouseHandler;
        if (sjt_getValue3 != 0) {
            sjt_getValue3->_refCount++;
        }

        sjt_dot75 = sjt_getValue3;
        sjt_interfaceParam23 = point;
        sjt_dot75->onMouseDown((void*)(((char*)sjt_dot75->_parent) + sizeof(intptr_t)), sjt_interfaceParam23);

        if (sjt_getValue3 != 0) {
            sjt_getValue3->_refCount--;
            if (sjt_getValue3->_refCount <= 0) {
                sji_mouseHandler_destroy(sjt_getValue3);
            }
        }
    }

    sjt_dot76 = element;
    sjt_dot76->getChildren((void*)(((char*)sjt_dot76->_parent) + sizeof(intptr_t)), &sjv_children);
    sjt_isEmpty5 = sjv_children;
    sjt_not4 = (sjt_isEmpty5 == 0);
    result4 = !sjt_not4;
    sjt_ifElse15 = result4;
    if (sjt_ifElse15) {
        int32_t i;
        sjs_array_heap_element* sjt_dot77;
        int32_t sjt_forEnd5;
        int32_t sjt_forStart5;
        sjs_array_heap_element* sjt_getValue4;
        sjs_array_heap_element* sjv_c;

        sjt_getValue4 = sjv_children;
        if (sjt_getValue4 == 0) { exit(-1); };
        sjv_c = sjt_getValue4;
        sjt_forStart5 = 0;
        i = sjt_forStart5;
        sjt_dot77 = sjv_c;
        sjt_forEnd5 = (sjt_dot77)->size;
        while (i < sjt_forEnd5) {
            sjs_array_heap_element* sjt_dot78;
            sji_element* sjt_functionParam32;
            int32_t sjt_functionParam33;
            sjs_point* sjt_functionParam34;

            sjt_dot78 = sjv_c;
            sjt_functionParam33 = i;
            sjf_array_heap_element_getAt_heap(sjt_dot78, sjt_functionParam33, &sjt_functionParam32);
            sjt_functionParam34 = point;
            sjf_fireMouseDown(sjt_functionParam32, sjt_functionParam34);
            i++;

            sjt_functionParam32->_refCount--;
            if (sjt_functionParam32->_refCount <= 0) {
                sji_element_destroy(sjt_functionParam32);
            }
        }
    }

    sjt_cast17->_refCount--;
    if (sjt_cast17->_refCount <= 0) {
        sji_element_destroy(sjt_cast17);
    }
    if (sjt_isEmpty4 != 0) {
        sjt_isEmpty4->_refCount--;
        if (sjt_isEmpty4->_refCount <= 0) {
            sji_mouseHandler_destroy(sjt_isEmpty4);
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
    sji_element* sjt_cast16;
    sji_element* sjt_dot72;
    bool sjt_ifElse11;
    bool sjt_ifElse12;
    sji_mouseHandler* sjt_isEmpty2;
    sjs_array_heap_element* sjt_isEmpty3;
    bool sjt_not1;
    bool sjt_not2;
    sjs_array_heap_element* sjv_children;
    sji_mouseHandler* sjv_mouseHandler;

    sjt_cast16 = element;
    sjt_cast16->_refCount++;
    sjv_mouseHandler = (sji_mouseHandler*)sjt_cast16->asInterface(sjt_cast16->_parent, sji_mouseHandler_typeId);
    sjt_isEmpty2 = sjv_mouseHandler;
    if (sjt_isEmpty2 != 0) {
        sjt_isEmpty2->_refCount++;
    }

    sjt_not1 = (sjt_isEmpty2 == 0);
    result1 = !sjt_not1;
    sjt_ifElse11 = result1;
    if (sjt_ifElse11) {
        sji_mouseHandler* sjt_dot71;
        sji_mouseHandler* sjt_getValue1;
        sjs_point* sjt_interfaceParam22;

        sjt_getValue1 = sjv_mouseHandler;
        if (sjt_getValue1 != 0) {
            sjt_getValue1->_refCount++;
        }

        sjt_dot71 = sjt_getValue1;
        sjt_interfaceParam22 = point;
        sjt_dot71->onMouseUp((void*)(((char*)sjt_dot71->_parent) + sizeof(intptr_t)), sjt_interfaceParam22);

        if (sjt_getValue1 != 0) {
            sjt_getValue1->_refCount--;
            if (sjt_getValue1->_refCount <= 0) {
                sji_mouseHandler_destroy(sjt_getValue1);
            }
        }
    }

    sjt_dot72 = element;
    sjt_dot72->getChildren((void*)(((char*)sjt_dot72->_parent) + sizeof(intptr_t)), &sjv_children);
    sjt_isEmpty3 = sjv_children;
    sjt_not2 = (sjt_isEmpty3 == 0);
    result2 = !sjt_not2;
    sjt_ifElse12 = result2;
    if (sjt_ifElse12) {
        int32_t i;
        sjs_array_heap_element* sjt_dot73;
        int32_t sjt_forEnd4;
        int32_t sjt_forStart4;
        sjs_array_heap_element* sjt_getValue2;
        sjs_array_heap_element* sjv_c;

        sjt_getValue2 = sjv_children;
        if (sjt_getValue2 == 0) { exit(-1); };
        sjv_c = sjt_getValue2;
        sjt_forStart4 = 0;
        i = sjt_forStart4;
        sjt_dot73 = sjv_c;
        sjt_forEnd4 = (sjt_dot73)->size;
        while (i < sjt_forEnd4) {
            sjs_array_heap_element* sjt_dot74;
            sji_element* sjt_functionParam27;
            int32_t sjt_functionParam28;
            sjs_point* sjt_functionParam29;

            sjt_dot74 = sjv_c;
            sjt_functionParam28 = i;
            sjf_array_heap_element_getAt_heap(sjt_dot74, sjt_functionParam28, &sjt_functionParam27);
            sjt_functionParam29 = point;
            sjf_fireMouseUp(sjt_functionParam27, sjt_functionParam29);
            i++;

            sjt_functionParam27->_refCount--;
            if (sjt_functionParam27->_refCount <= 0) {
                sji_element_destroy(sjt_functionParam27);
            }
        }
    }

    sjt_cast16->_refCount--;
    if (sjt_cast16->_refCount <= 0) {
        sji_element_destroy(sjt_cast16);
    }
    if (sjt_isEmpty2 != 0) {
        sjt_isEmpty2->_refCount--;
        if (sjt_isEmpty2->_refCount <= 0) {
            sji_mouseHandler_destroy(sjt_isEmpty2);
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
    sji_surface* sjt_dot64;
    sji_surface* sjt_dot65;
    sjs_size* sjt_dot66;
    sjs_size* sjt_dot67;
    sji_element* sjt_dot68;
    sji_element* sjt_dot69;
    sji_surface* sjt_dot70;
    bool sjt_ifElse10;
    bool sjt_ifElse13;
    sjs_rect* sjt_interfaceParam20;
    sji_surface* sjt_interfaceParam21;
    int32_t sjt_math23;
    int32_t sjt_math24;
    bool sjv_isMouseDown;
    bool sjv_isMouseUp;
    sjs_rect sjv_rect;
    sjs_size sjv_size;
    int32_t sjv_x;
    int32_t sjv_y;

    sjt_dot64 = sjv_rootSurface;
    sjt_dot64->clear((void*)(((char*)sjt_dot64->_parent) + sizeof(intptr_t)));
    sjt_dot65 = sjv_rootSurface;
    sjt_dot65->getSize((void*)(((char*)sjt_dot65->_parent) + sizeof(intptr_t)), &sjv_size);
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot66 = &sjv_size;
    sjv_rect.w = (sjt_dot66)->w;
    sjt_dot67 = &sjv_size;
    sjv_rect.h = (sjt_dot67)->h;
    sjf_rect(&sjv_rect);
    sjt_dot68 = sjv_root;
    sjt_interfaceParam20 = &sjv_rect;
    sjt_dot68->setRect((void*)(((char*)sjt_dot68->_parent) + sizeof(intptr_t)), sjt_interfaceParam20);
    sjt_dot69 = sjv_root;
    sjt_interfaceParam21 = sjv_rootSurface;
    sjt_interfaceParam21->_refCount++;
    sjt_dot69->render((void*)(((char*)sjt_dot69->_parent) + sizeof(intptr_t)), sjt_interfaceParam21);
    sjt_dot70 = sjv_rootSurface;
    sjt_dot70->present((void*)(((char*)sjt_dot70->_parent) + sizeof(intptr_t)));
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
    sjt_ifElse10 = sjv_isMouseUp;
    if (sjt_ifElse10) {
        sjs_point sjt_call10;
        sji_element* sjt_functionParam30;
        sjs_point* sjt_functionParam31;

        sjt_functionParam30 = sjv_root;
        sjt_functionParam30->_refCount++;
        sjt_call10.x = sjv_x;
        sjt_call10.y = sjv_y;
        sjf_point(&sjt_call10);
        sjt_functionParam31 = &sjt_call10;
        sjf_fireMouseUp(sjt_functionParam30, sjt_functionParam31);

        sjt_functionParam30->_refCount--;
        if (sjt_functionParam30->_refCount <= 0) {
            sji_element_destroy(sjt_functionParam30);
        }
        sjf_point_destroy(&sjt_call10);
    }

    sjt_ifElse13 = sjv_isMouseDown;
    if (sjt_ifElse13) {
        sjs_point sjt_call11;
        sji_element* sjt_functionParam35;
        sjs_point* sjt_functionParam36;

        sjt_functionParam35 = sjv_root;
        sjt_functionParam35->_refCount++;
        sjt_call11.x = sjv_x;
        sjt_call11.y = sjv_y;
        sjf_point(&sjt_call11);
        sjt_functionParam36 = &sjt_call11;
        sjf_fireMouseDown(sjt_functionParam35, sjt_functionParam36);

        sjt_functionParam35->_refCount--;
        if (sjt_functionParam35->_refCount <= 0) {
            sji_element_destroy(sjt_functionParam35);
        }
        sjf_point_destroy(&sjt_call11);
    }

    sjt_math23 = sjv_frame;
    sjt_math24 = 1;
    sjv_frame = sjt_math23 + sjt_math24;

    sjt_interfaceParam21->_refCount--;
    if (sjt_interfaceParam21->_refCount <= 0) {
        sji_surface_destroy(sjt_interfaceParam21);
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
    int32_t sjt_compare15;
    int32_t sjt_compare16;
    sjs_string* sjt_dot37;
    bool sjt_ifElse7;

    sjt_dot37 = item;
    sjt_compare15 = (sjt_dot37)->count;
    sjt_compare16 = 0;
    sjt_ifElse7 = sjt_compare15 > sjt_compare16;
    if (sjt_ifElse7) {
        int32_t i;
        int32_t sjt_cast11;
        int32_t sjt_compare17;
        int32_t sjt_compare18;
        sjs_string* sjt_dot38;
        sjs_array_char* sjt_dot39;
        sjs_string* sjt_dot42;
        sjs_array_char* sjt_dot46;
        int32_t sjt_forEnd3;
        int32_t sjt_forStart3;
        int32_t sjt_functionParam13;
        char sjt_functionParam14;
        bool sjt_ifElse8;
        int32_t sjt_math10;
        int32_t sjt_math11;
        int32_t sjt_math12;
        int32_t sjt_math9;

        sjt_math11 = (_parent)->count;
        sjt_dot38 = item;
        sjt_math12 = (sjt_dot38)->count;
        sjt_math9 = sjt_math11 + sjt_math12;
        sjt_math10 = 1;
        sjt_compare17 = sjt_math9 + sjt_math10;
        sjt_dot39 = &(_parent)->data;
        sjt_compare18 = (sjt_dot39)->size;
        sjt_ifElse8 = sjt_compare17 > sjt_compare18;
        if (sjt_ifElse8) {
            sjs_array_char* sjt_dot40;
            sjs_string* sjt_dot41;
            int32_t sjt_functionParam8;
            int32_t sjt_math13;
            int32_t sjt_math14;
            int32_t sjt_math15;
            int32_t sjt_math16;

            sjt_dot40 = &(_parent)->data;
            sjt_math15 = (_parent)->count;
            sjt_dot41 = item;
            sjt_math16 = (sjt_dot41)->count;
            sjt_math13 = sjt_math15 + sjt_math16;
            sjt_math14 = 1;
            sjt_functionParam8 = sjt_math13 + sjt_math14;
            sjf_array_char_grow(sjt_dot40, sjt_functionParam8);
        }

        sjt_forStart3 = 0;
        i = sjt_forStart3;
        sjt_dot42 = item;
        sjt_forEnd3 = (sjt_dot42)->count;
        while (i < sjt_forEnd3) {
            sjs_array_char* sjt_dot43;
            sjs_string* sjt_dot44;
            char sjt_functionParam10;
            int32_t sjt_functionParam12;
            int32_t sjt_functionParam9;
            int32_t sjt_math17;
            int32_t sjt_math18;

            sjt_dot43 = &(_parent)->data;
            sjt_functionParam9 = (_parent)->count;
            sjt_dot44 = item;
            sjt_functionParam12 = i;
            sjf_string_getAt(sjt_dot44, sjt_functionParam12, &sjt_functionParam10);
            sjf_array_char_setAt(sjt_dot43, sjt_functionParam9, sjt_functionParam10);
            sjt_math17 = (_parent)->count;
            sjt_math18 = 1;
            _parent->count = sjt_math17 + sjt_math18;
            i++;
        }

        sjt_dot46 = &(_parent)->data;
        sjt_functionParam13 = (_parent)->count;
        sjt_cast11 = 0;
        sjt_functionParam14 = (char)sjt_cast11;
        sjf_array_char_setAt(sjt_dot46, sjt_functionParam13, sjt_functionParam14);
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
    sjs_array_char* sjt_dot45;
    int32_t sjt_functionParam11;

    sjt_dot45 = &(_parent)->data;
    sjt_functionParam11 = index;
    sjf_array_char_getAt(sjt_dot45, sjt_functionParam11, &(*_return));
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
    sjt_cast7 = 0;
    sjt_cast6->children.data = (uintptr_t)sjt_cast7;
    sjt_cast6->children._isGlobal = false;
    sjf_array_heap_element(&sjt_cast6->children);
    sjt_functionParam3 = 0;
    sjt_cast8 = (sjs_borderChild_heap*)malloc(sizeof(sjs_borderChild_heap));
    sjt_cast8->_refCount = 1;
    sjt_cast10 = (sjs_buttonElement_heap*)malloc(sizeof(sjs_buttonElement_heap));
    sjt_cast10->_refCount = 1;
    sjt_cast10->text.count = 11;
    sjt_cast10->text.data.size = 12;
    sjt_cast10->text.data.data = (uintptr_t)sjg_string11;
    sjt_cast10->text.data._isGlobal = false;
    sjf_array_char(&sjt_cast10->text.data);
    sjf_string(&sjt_cast10->text);
    sjt_dot57 = &sjv_colors;
    sjf_anon6_black(sjt_dot57, &sjt_cast10->textColor);
    sjt_dot58 = &sjv_style;
    sjt_functionParam26 = 0;
    sjf_anon7_getFont(sjt_dot58, sjt_functionParam26, &sjt_cast10->font);
    sjt_cast10->rect.x = 0;
    sjt_cast10->rect.y = 0;
    sjt_cast10->rect.w = 0;
    sjt_cast10->rect.h = 0;
    sjf_rect(&sjt_cast10->rect);
    sjt_dot59 = sjv_rootSurface;
    sjt_call7.count = 23;
    sjt_call7.data.size = 24;
    sjt_call7.data.data = (uintptr_t)sjg_string6;
    sjt_call7.data._isGlobal = false;
    sjf_array_char(&sjt_call7.data);
    sjf_string(&sjt_call7);
    sjt_interfaceParam17 = &sjt_call7;
    sjt_dot59->getTexture((void*)(((char*)sjt_dot59->_parent) + sizeof(intptr_t)), sjt_interfaceParam17, &sjt_cast10->normalImage.texture);
    sjt_cast10->normalImage.rect.x = 0;
    sjt_cast10->normalImage.rect.y = 0;
    sjt_cast10->normalImage.rect.w = 0;
    sjt_cast10->normalImage.rect.h = 0;
    sjf_rect(&sjt_cast10->normalImage.rect);
    sjf_image(&sjt_cast10->normalImage);
    sjt_dot60 = sjv_rootSurface;
    sjt_call8.count = 20;
    sjt_call8.data.size = 21;
    sjt_call8.data.data = (uintptr_t)sjg_string8;
    sjt_call8.data._isGlobal = false;
    sjf_array_char(&sjt_call8.data);
    sjf_string(&sjt_call8);
    sjt_interfaceParam18 = &sjt_call8;
    sjt_dot60->getTexture((void*)(((char*)sjt_dot60->_parent) + sizeof(intptr_t)), sjt_interfaceParam18, &sjt_cast10->hotImage.texture);
    sjt_cast10->hotImage.rect.x = 0;
    sjt_cast10->hotImage.rect.y = 0;
    sjt_cast10->hotImage.rect.w = 0;
    sjt_cast10->hotImage.rect.h = 0;
    sjf_rect(&sjt_cast10->hotImage.rect);
    sjf_image(&sjt_cast10->hotImage);
    sjt_dot61 = sjv_rootSurface;
    sjt_call9.count = 24;
    sjt_call9.data.size = 25;
    sjt_call9.data.data = (uintptr_t)sjg_string10;
    sjt_call9.data._isGlobal = false;
    sjf_array_char(&sjt_call9.data);
    sjf_string(&sjt_call9);
    sjt_interfaceParam19 = &sjt_call9;
    sjt_dot61->getTexture((void*)(((char*)sjt_dot61->_parent) + sizeof(intptr_t)), sjt_interfaceParam19, &sjt_cast10->pressedImage.texture);
    sjt_cast10->pressedImage.rect.x = 0;
    sjt_cast10->pressedImage.rect.y = 0;
    sjt_cast10->pressedImage.rect.w = 0;
    sjt_cast10->pressedImage.rect.h = 0;
    sjf_rect(&sjt_cast10->pressedImage.rect);
    sjf_image(&sjt_cast10->pressedImage);
    sjt_dot62 = &sjv_buttonState;
    sjt_cast10->state = (sjt_dot62)->normal;
    sjf_buttonElement_heap(sjt_cast10);
    sjt_cast8->child = (sji_element*)sjf_buttonElement_heap_as_sji_element(sjt_cast10);
    sjt_cast8->rect.x = 0;
    sjt_cast8->rect.y = 0;
    sjt_cast8->rect.w = 0;
    sjt_cast8->rect.h = 0;
    sjf_rect(&sjt_cast8->rect);
    sjt_dot63 = &sjv_borderPosition;
    sjt_cast8->position = (sjt_dot63)->left;
    sjt_cast8->_children = 0;
    if (sjt_cast8->_children != 0) {
        sjt_cast8->_children->_refCount++;
    }

    sjf_borderChild_heap(sjt_cast8);
    sjt_functionParam4 = (sji_element*)sjf_borderChild_heap_as_sji_element(sjt_cast8);
    sjf_array_heap_element_initAt(&sjt_cast6->children, sjt_functionParam3, sjt_functionParam4);
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
        sjf_buttonElement_destroy((sjs_buttonElement*)(((char*)sjt_cast10) + sizeof(intptr_t)));
    }
    sjt_cast6->_refCount--;
    if (sjt_cast6->_refCount <= 0) {
        sjf_borderLayout_destroy((sjs_borderLayout*)(((char*)sjt_cast6) + sizeof(intptr_t)));
    }
    sjt_cast8->_refCount--;
    if (sjt_cast8->_refCount <= 0) {
        sjf_borderChild_destroy((sjs_borderChild*)(((char*)sjt_cast8) + sizeof(intptr_t)));
    }
    sjt_functionParam4->_refCount--;
    if (sjt_functionParam4->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam4);
    }
    sjv_root->_refCount--;
    if (sjv_root->_refCount <= 0) {
        sji_element_destroy(sjv_root);
    }
    sjv_rootSurface->_refCount--;
    if (sjv_rootSurface->_refCount <= 0) {
        sji_surface_destroy(sjv_rootSurface);
    }
    sjf_string_destroy(&sjt_call7);
    sjf_string_destroy(&sjt_call8);
    sjf_string_destroy(&sjt_call9);
    sjf_anon8_destroy(&sjv_borderPosition);
    sjf_anon5_destroy(&sjv_buttonState);
    sjf_anon6_destroy(&sjv_colors);
    sjf_anon1_destroy(&sjv_console);
    sjf_anon4_destroy(&sjv_convert);
    sjf_anon2_destroy(&sjv_parse);
    sjf_anon3_destroy(&sjv_random);
    sjf_anon7_destroy(&sjv_style);
}
