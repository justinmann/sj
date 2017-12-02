









#ifdef WIN32
#pragma warning(disable:4996)
#define GLEW_STATIC
#include <windows.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#ifdef EMSCRIPTEN
#include <GLES3/gl3.h>
#endif
#ifdef __APPLE__
#include <OpenGL/gl.h>
#endif
#ifdef EMSCRIPTEN
#include <SDL.h>
#endif
#ifdef WIN32
#include <SDL.h>
#endif
#ifdef __APPLE__
#include <SDL2/SDL.h>
#endif
#include <assert.h>
#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#ifdef EMSCRIPTEN
#include <emscripten/html5.h>
#endif
#include <float.h>
#include <ft2build.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include FT_FREETYPE_H
#include FT_LCD_FILTER_H
#include FT_STROKER_H

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


/**
 * Maximum number of attributes per vertex
 *
 * @private
 */
#define MAX_VERTEX_ATTRIBUTE 16


/**
 *  Generic vertex attribute.
 */
typedef struct vertex_attribute_t
{
    /**
     *  atribute name
     */
    GLchar * name;

    /**
     * index of the generic vertex attribute to be modified.
     */
    GLuint index;

    /**
     * Number of components per generic vertex attribute.
     *
     * Must be 1, 2, 3, or 4. The initial value is 4.
     */
    GLint size;

    /**
     *  data type of each component in the array.
     *
     *  Symbolic constants GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT,
     *  GL_UNSIGNED_SHORT, GL_INT, GL_UNSIGNED_INT, GL_FLOAT, or GL_DOUBLE are
     *  accepted. The initial value is GL_FLOAT.
     */
    GLenum type;

    /**
     *  whether fixed-point data values should be normalized (GL_TRUE) or
     *  converted directly as fixed-point values (GL_FALSE) when they are
     *  accessed.
     */
    GLboolean normalized;

    /**
     *  byte offset between consecutive generic vertex attributes.
     *
     *  If stride is 0, the generic vertex attributes are understood to be
     *  tightly packed in the array. The initial value is 0.
     */
    GLsizei stride;

    /**
     *  pointer to the first component of the first attribute element in the
     *  array.
     */
    GLvoid * pointer;

    /**
     * pointer to the function that enable this attribute.
     */
    void ( * enable )(void *);

} vertex_attribute_t;


/**
 *  Generic vector structure.
 *
 * @memberof vector
 */
typedef struct vector_t
 {
     /** Pointer to dynamically allocated items. */
     void * items;

     /** Number of items that can be held in currently allocated storage. */
     size_t capacity;

     /** Number of items. */
     size_t size;

     /** Size (in bytes) of a single item. */
     size_t item_size;
} vector_t;


#undef __FTERRORS_H__
#define FT_ERRORDEF( e, v, s )  { e, s },
#define FT_ERROR_START_LIST     {
#define FT_ERROR_END_LIST       { 0, 0 } };
const struct {
    int          code;
    const char*  message;
} FT_Errors[] =
#include FT_ERRORS_H    


/**
 * Tuple of 4 ints.
 *
 * Each field can be addressed using several aliases:
 *  - First component:  <b>x</b>, <b>r</b>, <b>red</b> or <b>vstart</b>
 *  - Second component: <b>y</b>, <b>g</b>, <b>green</b> or <b>vcount</b>
 *  - Third component:  <b>z</b>, <b>b</b>, <b>blue</b>, <b>width</b> or <b>istart</b>
 *  - Fourth component: <b>w</b>, <b>a</b>, <b>alpha</b>, <b>height</b> or <b>icount</b>
 *
 */
typedef union
{
    int data[4];    /**< All compoments at once     */
    struct {
        int x;      /**< Alias for first component  */
        int y;      /**< Alias for second component */
        int z;      /**< Alias for third component  */
        int w;      /**< Alias for fourht component */
    };
    struct {
        int x_;     /**< Alias for first component  */
        int y_;     /**< Alias for second component */
        int width;  /**< Alias for third component  */
        int height; /**< Alias for fourth component */
    };
    struct {
        int r;      /**< Alias for first component  */
        int g;      /**< Alias for second component */
        int b;      /**< Alias for third component  */
        int a;      /**< Alias for fourth component */
    };
    struct {
        int red;    /**< Alias for first component  */
        int green;  /**< Alias for second component */
        int blue;   /**< Alias for third component  */
        int alpha;  /**< Alias for fourth component */
    };
    struct {
        int vstart; /**< Alias for first component  */
        int vcount; /**< Alias for second component */
        int istart; /**< Alias for third component  */
        int icount; /**< Alias for fourth component */
    };
} ivec4;

/**
 * Tuple of 3 ints.
 *
 * Each field can be addressed using several aliases:
 *  - First component:  <b>x</b>, <b>r</b> or <b>red</b>
 *  - Second component: <b>y</b>, <b>g</b> or <b>green</b>
 *  - Third component:  <b>z</b>, <b>b</b> or <b>blue</b>
 *
 */
typedef union
{
    int data[3];    /**< All compoments at once     */
    struct {
        int x;      /**< Alias for first component  */
        int y;      /**< Alias for second component */
        int z;      /**< Alias for third component  */
    };
    struct {
        int r;      /**< Alias for first component  */
        int g;      /**< Alias for second component */
        int b;      /**< Alias for third component  */
    };
    struct {
        int red;    /**< Alias for first component  */
        int green;  /**< Alias for second component */
        int blue;   /**< Alias for third component  */
    };
} ivec3;


/**
 * Tuple of 2 ints.
 *
 * Each field can be addressed using several aliases:
 *  - First component: <b>x</b>, <b>s</b> or <b>start</b>
 *  - Second component: <b>y</b>, <b>t</b> or <b>end</b>
 *
 */
typedef union
{
    int data[2];    /**< All compoments at once     */
    struct {
        int x;      /**< Alias for first component  */
        int y;      /**< Alias for second component */
    };
    struct {
        int s;      /**< Alias for first component  */
        int t;      /**< Alias for second component */
    };
    struct {
        int start;  /**< Alias for first component  */
        int end;    /**< Alias for second component */
    };
} ivec2;


/**
 * Tuple of 4 floats.
 *
 * Each field can be addressed using several aliases:
 *  - First component:  <b>x</b>, <b>left</b>, <b>r</b> or <b>red</b>
 *  - Second component: <b>y</b>, <b>top</b>, <b>g</b> or <b>green</b>
 *  - Third component:  <b>z</b>, <b>width</b>, <b>b</b> or <b>blue</b>
 *  - Fourth component: <b>w</b>, <b>height</b>, <b>a</b> or <b>alpha</b>
 */
typedef union
{
    float data[4];    /**< All compoments at once    */
    struct {
        float x;      /**< Alias for first component */
        float y;      /**< Alias for second component */
        float z;      /**< Alias for third component  */
        float w;      /**< Alias for fourth component */
    };
    struct {
        float left;   /**< Alias for first component */
        float top;    /**< Alias for second component */
        float width;  /**< Alias for third component  */
        float height; /**< Alias for fourth component */
    };
    struct {
        float r;      /**< Alias for first component */
        float g;      /**< Alias for second component */
        float b;      /**< Alias for third component  */
        float a;      /**< Alias for fourth component */
    };
    struct {
        float red;    /**< Alias for first component */
        float green;  /**< Alias for second component */
        float blue;   /**< Alias for third component  */
        float alpha;  /**< Alias for fourth component */
    };
} vec4;


/**
 * Tuple of 3 floats
 *
 * Each field can be addressed using several aliases:
 *  - First component:  <b>x</b>, <b>r</b> or <b>red</b>
 *  - Second component: <b>y</b>, <b>g</b> or <b>green</b>
 *  - Third component:  <b>z</b>, <b>b</b> or <b>blue</b>
 */
typedef union
{
    float data[3];   /**< All compoments at once    */
    struct {
        float x;     /**< Alias for first component */
        float y;     /**< Alias fo second component */
        float z;     /**< Alias fo third component  */
    };
    struct {
        float r;     /**< Alias for first component */
        float g;     /**< Alias fo second component */
        float b;     /**< Alias fo third component  */
    };
    struct {
        float red;   /**< Alias for first component */
        float green; /**< Alias fo second component */
        float blue;  /**< Alias fo third component  */
    };
} vec3;


/**
 * Tuple of 2 floats
 *
 * Each field can be addressed using several aliases:
 *  - First component:  <b>x</b> or <b>s</b>
 *  - Second component: <b>y</b> or <b>t</b>
 */
typedef union
{
    float data[2]; /**< All components at once     */
    struct {
        float x;   /**< Alias for first component  */
        float y;   /**< Alias for second component */
    };
    struct {
        float s;   /**< Alias for first component  */
        float t;   /**< Alias for second component */
    };
} vec2;

/**
 * A texture atlas is used to pack several small regions into a single texture.
 */
typedef struct texture_atlas_t
{
    /**
     * Allocated nodes
     */
    vector_t * nodes;

    /**
     *  Width (in pixels) of the underlying texture
     */
    size_t width;

    /**
     * Height (in pixels) of the underlying texture
     */
    size_t height;

    /**
     * Depth (in bytes) of the underlying texture
     */
    size_t depth;

    /**
     * Allocated surface size
     */
    size_t used;

    /**
     * Texture identity (OpenGL)
     */
    unsigned int id;

    /**
     * Atlas data
     */
    unsigned char * data;

} texture_atlas_t;    

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
#define sjs_margin_typeId 27
#define sjs_margin_heap_typeId 28
#define sjs_image_typeId 29
#define sjs_image_heap_typeId 30
#define sjs_array_char_typeId 31
#define sjs_array_char_heap_typeId 32
#define sjs_string_typeId 33
#define sjs_string_heap_typeId 34
#define sjs_font_typeId 35
#define sjs_font_heap_typeId 36
#define sji_surface_typeId 37
#define sjs_sdlSurface_heap_typeId 38
#define sjs_array_heap_element_typeId 39
#define sjs_array_heap_element_heap_typeId 40
#define sjs_borderLayout_typeId 41
#define sji_element_typeId 42
#define sji_borderChild_typeId 43
#define sjs_borderLayout_heap_typeId 44
#define sjs_borderChild_typeId 45
#define sjs_borderChild_heap_typeId 46
#define sjs_buttonElement_typeId 47
#define sjs_point_typeId 48
#define sjs_point_heap_typeId 49
#define sji_mouseHandler_typeId 50
#define sjs_buttonElement_heap_typeId 51
#define sjs_boxElement_typeId 52
#define sjs_boxElement_heap_typeId 53

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
typedef struct td_sjs_margin sjs_margin;
typedef struct td_sjs_margin_heap sjs_margin_heap;
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
typedef struct td_sjs_boxElement sjs_boxElement;
typedef struct td_sjs_boxElement_heap sjs_boxElement_heap;

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

struct td_sjs_margin {
    int32_t l;
    int32_t t;
    int32_t r;
    int32_t b;
};

struct td_sjs_margin_heap {
    intptr_t _refCount;
    int32_t l;
    int32_t t;
    int32_t r;
    int32_t b;
};

struct td_sjs_image {
    sjs_texture texture;
    sjs_rect rect;
    sjs_margin margin;
};

struct td_sjs_image_heap {
    intptr_t _refCount;
    sjs_texture texture;
    sjs_rect rect;
    sjs_margin margin;
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
    void (*drawRect)(void* _parent, sjs_rect* rect, sjs_color* color);
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
    void (*getRect)(void* _parent, sjs_rect** _return);
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
    sjs_margin margin;
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
    sjs_margin margin;
};

struct td_sjs_boxElement {
    sjs_color color;
    sjs_size idealSize;
    sjs_rect rect;
};

struct td_sjs_boxElement_heap {
    intptr_t _refCount;
    sjs_color color;
    sjs_size idealSize;
    sjs_rect rect;
};


/*
 * Compute the local gradient at edge pixels using convolution filters.
 * The gradient is computed only at edge pixels. At other places in the
 * image, it is never used, and it's mostly zero anyway.
 */
void computegradient(double *img, int w, int h, double *gx, double *gy);

/*
 * A somewhat tricky function to approximate the distance to an edge in a
 * certain pixel, with consideration to either the local gradient (gx,gy)
 * or the direction to the pixel (dx,dy) and the pixel greyscale value a.
 * The latter alternative, using (dx,dy), is the metric used by edtaa2().
 * Using a local estimate of the edge gradient (gx,gy) yields much better
 * accuracy at and near edges, and reduces the error even at distant pixels
 * provided that the gradient direction is accurately estimated.
 */
double edgedf(double gx, double gy, double a);


double distaa3(double *img, double *gximg, double *gyimg, int w, int c, int xc, int yc, int xi, int yi);

// Shorthand macro: add ubiquitous parameters dist, gx, gy, img and w and call distaa3()
#define DISTAA(c,xc,yc,xi,yi) (distaa3(img, gx, gy, w, c, xc, yc, xi, yi))

void edtaa3(double *img, double *gx, double *gy, int w, int h, short *distx, short *disty, double *dist);  


double *
make_distance_mapd( double *img,
                    unsigned int width, unsigned int height );

unsigned char *
make_distance_mapb( unsigned char *img,
                    unsigned int width, unsigned int height );    


/**
* Returns the size in bytes of a given UTF-8 encoded character surrogate
*
* @param character  An UTF-8 encoded character
*
* @return  The length of the surrogate in bytes.
*/
size_t
utf8_surrogate_len( const char* character );

/**
* Return the length of the given UTF-8 encoded and
* NULL terminated string.
*
* @param string  An UTF-8 encoded string
*
* @return  The length of the string in characters.
*/
size_t
utf8_strlen( const char* string );

/**
* Converts a given UTF-8 encoded character to its UTF-32 LE equivalent
*
* @param character  An UTF-8 encoded character
*
* @return  The equivalent of the given character in UTF-32 LE
*          encoding.
*/
uint32_t
utf8_to_utf32( const char * character );


/**
 * Generic vertex buffer.
 */
typedef struct vertex_buffer_t
{
    /** Format of the vertex buffer. */
    char * format;

    /** Vector of vertices. */
    vector_t * vertices;

#ifdef FREETYPE_GL_USE_VAO
    /** GL identity of the Vertex Array Object */
    GLuint VAO_id;
#endif

    /** GL identity of the vertices buffer. */
    GLuint vertices_id;

    /** Vector of indices. */
    vector_t * indices;

    /** GL identity of the indices buffer. */
    GLuint indices_id;

    /** Current size of the vertices buffer in GPU */
    size_t GPU_vsize;

    /** Current size of the indices buffer in GPU*/
    size_t GPU_isize;

    /** GL primitives to render. */
    GLenum mode;

    /** Whether the vertex buffer needs to be uploaded to GPU memory. */
    char state;

    /** Individual items */
    vector_t * items;

    /** Array of attributes. */
    vertex_attribute_t *attributes[MAX_VERTEX_ATTRIBUTE];
} vertex_buffer_t;

#ifdef WIN32
// strndup() is not available on Windows
char *strndup( const char *s1, size_t n);
#endif

/**
 * Creates an empty vertex buffer.
 *
 * @param  format a string describing vertex format.
 * @return        an empty vertex buffer.
 */
  vertex_buffer_t *
  vertex_buffer_new( const char *format );


/**
 * Deletes vertex buffer and releases GPU memory.
 *
 * @param  self  a vertex buffer
 */
  void
  vertex_buffer_delete( vertex_buffer_t * self );


/**
 *  Returns the number of items in the vertex buffer
 *
 *  @param  self  a vertex buffer
 *  @return       number of items
 */
  size_t
  vertex_buffer_size( const vertex_buffer_t *self );


/**
 *  Returns vertex format
 *
 *  @param  self  a vertex buffer
 *  @return       vertex format
 */
  const char *
  vertex_buffer_format( const vertex_buffer_t *self );


/**
 * Print information about a vertex buffer
 *
 * @param  self  a vertex buffer
 */
  void
  vertex_buffer_print( vertex_buffer_t * self );


/**
 * Prepare vertex buffer for render.
 *
 * @param  self  a vertex buffer
 * @param  mode  render mode
 */
  void
  vertex_buffer_render_setup ( vertex_buffer_t *self,
                               GLenum mode );


/**
 * Finish rendering by setting back modified states
 *
 * @param  self  a vertex buffer
 */
  void
  vertex_buffer_render_finish ( vertex_buffer_t *self );


/**
 * Render vertex buffer.
 *
 * @param  self  a vertex buffer
 * @param  mode  render mode
 */
  void
  vertex_buffer_render ( vertex_buffer_t *self,
                         GLenum mode );


/**
 * Render a specified item from the vertex buffer.
 *
 * @param  self   a vertex buffer
 * @param  index index of the item to be rendered
 */
  void
  vertex_buffer_render_item ( vertex_buffer_t *self,
                              size_t index );


/**
 * Upload buffer to GPU memory.
 *
 * @param  self  a vertex buffer
 */
  void
  vertex_buffer_upload( vertex_buffer_t *self );


/**
 * Clear all items.
 *
 * @param  self  a vertex buffer
 */
  void
  vertex_buffer_clear( vertex_buffer_t *self );


/**
 * Appends indices at the end of the buffer.
 *
 * @param  self     a vertex buffer
 * @param  indices  indices to be appended
 * @param  icount   number of indices to be appended
 *
 * @private
 */
  void
  vertex_buffer_push_back_indices ( vertex_buffer_t *self,
                                    const GLuint * indices,
                                    const size_t icount );


/**
 * Appends vertices at the end of the buffer.
 *
 * @note Internal use
 *
 * @param  self     a vertex buffer
 * @param  vertices vertices to be appended
 * @param  vcount   number of vertices to be appended
 *
 * @private
 */
  void
  vertex_buffer_push_back_vertices ( vertex_buffer_t *self,
                                     const void * vertices,
                                     const size_t vcount );


/**
 * Insert indices in the buffer.
 *
 * @param  self    a vertex buffer
 * @param  index   location before which to insert indices
 * @param  indices indices to be appended
 * @param  icount  number of indices to be appended
 *
 * @private
 */
  void
  vertex_buffer_insert_indices ( vertex_buffer_t *self,
                                 const size_t index,
                                 const GLuint *indices,
                                 const size_t icount );


/**
 * Insert vertices in the buffer.
 *
 * @param  self     a vertex buffer
 * @param  index    location before which to insert vertices
 * @param  vertices vertices to be appended
 * @param  vcount   number of vertices to be appended
 *
 * @private
 */
  void
  vertex_buffer_insert_vertices ( vertex_buffer_t *self,
                                  const size_t index,
                                  const void *vertices,
                                  const size_t vcount );

/**
 * Erase indices in the buffer.
 *
 * @param  self   a vertex buffer
 * @param  first  the index of the first index to be erased
 * @param  last   the index of the last index to be erased
 *
 * @private
 */
  void
  vertex_buffer_erase_indices ( vertex_buffer_t *self,
                                const size_t first,
                                const size_t last );

/**
 * Erase vertices in the buffer.
 *
 * @param  self   a vertex buffer
 * @param  first  the index of the first vertex to be erased
 * @param  last   the index of the last vertex to be erased
 *
 * @private
 */
  void
  vertex_buffer_erase_vertices ( vertex_buffer_t *self,
                                 const size_t first,
                                 const size_t last );


/**
 * Append a new item to the collection.
 *
 * @param  self   a vertex buffer
 * @param  vcount   number of vertices
 * @param  vertices raw vertices data
 * @param  icount   number of indices
 * @param  indices  raw indices data
 */
  size_t
  vertex_buffer_push_back( vertex_buffer_t * self,
                           const void * vertices, const size_t vcount,
                           const GLuint * indices, const size_t icount );


/**
 * Insert a new item into the vertex buffer.
 *
 * @param  self      a vertex buffer
 * @param  index     location before which to insert item
 * @param  vertices  raw vertices data
 * @param  vcount    number of vertices
 * @param  indices   raw indices data
 * @param  icount    number of indices
 */
  size_t
  vertex_buffer_insert( vertex_buffer_t * self,
                        const size_t index,
                        const void * vertices, const size_t vcount,
                        const GLuint * indices, const size_t icount );

/**
 * Erase an item from the vertex buffer.
 *
 * @param  self     a vertex buffer
 * @param  index    index of the item to be deleted
 */
  void
  vertex_buffer_erase( vertex_buffer_t * self,
                       const size_t index );    


/**
 * Create an attribute from the given parameters.
 *
 * @param size       number of component
 * @param type       data type
 * @param normalized Whether fixed-point data values should be normalized
                     (GL_TRUE) or converted directly as fixed-point values
                     (GL_FALSE) when they are  accessed.
 * @param stride     byte offset between consecutive attributes.
 * @param pointer    pointer to the first component of the first attribute
 *                   element in the array.
 * @return           a new initialized vertex attribute.
 *
 * @private
 */
vertex_attribute_t *
vertex_attribute_new( GLchar * name,
                      GLint size,
                      GLenum type,
                      GLboolean normalized,
                      GLsizei stride,
                      GLvoid *pointer );



/**
 * Delete a vertex attribute.
 *
 * @param  self a vertex attribute
 *
 */
void
vertex_attribute_delete( vertex_attribute_t * self );


/**
 * Create an attribute from the given description.
 *
 * @param  format Format string specifies the format of a vertex attribute.
 * @return        an initialized vertex attribute
 *
 * @private
 */
  vertex_attribute_t *
  vertex_attribute_parse( char *format );

/**
 * Enable a vertex attribute.
 *
 * @param attr  a vertex attribute
 *
 * @private
 */
  void
  vertex_attribute_enable( vertex_attribute_t *attr );    



/**
 * @file   vector.h
 * @author Nicolas Rougier (Nicolas.Rougier@inria.fr)
 *
 * @defgroup vector Vector
 *
 * The vector structure and accompanying functions loosely mimic the STL C++
 * vector class. It is used by @ref texture-atlas (for storing nodes), @ref
 * texture-font (for storing glyphs) and @ref font-manager (for storing fonts).
 * More information at http://www.cppreference.com/wiki/container/vector/start
 *
 * <b>Example Usage</b>:
 * @code
 *
 * int main( int arrgc, char *argv[] )
 * {
 *   int i,j = 1;
 *   vector_t * vector = vector_new( sizeof(int) );
 *   vector_push_back( &i );
 *
 *   j = * (int *) vector_get( vector, 0 );
 *   vector_delete( vector);
 *
 *   return 0;
 * }
 * @endcode
 *
 * @{
 */

/**
 * Creates a new empty vector.
 *
 * @param   item_size    item size in bytes
 * @return               a new empty vector
 *
 */
  vector_t *
  vector_new( size_t item_size );


/**
 *  Deletes a vector.
 *
 *  @param self a vector structure
 *
 */
  void
  vector_delete( vector_t *self );


/**
 *  Returns a pointer to the item located at specified index.
 *
 *  @param  self  a vector structure
 *  @param  index the index of the item to be returned
 *  @return       pointer on the specified item
 */
  const void *
  vector_get( const vector_t *self,
              size_t index );


/**
 *  Returns a pointer to the first item.
 *
 *  @param  self  a vector structure
 *  @return       pointer on the first item
 */
  const void *
  vector_front( const vector_t *self );


/**
 *  Returns a pointer to the last item
 *
 *  @param  self  a vector structure
 *  @return pointer on the last item
 */
  const void *
  vector_back( const vector_t *self );


/**
 *  Check if an item is contained within the vector.
 *
 *  @param  self  a vector structure
 *  @param  item  item to be searched in the vector
 *  @param  cmp   a pointer a comparison function
 *  @return       1 if item is contained within the vector, 0 otherwise
 */
  int
  vector_contains( const vector_t *self,
                   const void *item,
                   int (*cmp)(const void *, const void *) );


/**
 *  Checks whether the vector is empty.
 *
 *  @param  self  a vector structure
 *  @return       1 if the vector is empty, 0 otherwise
 */
  int
  vector_empty( const vector_t *self );


/**
 *  Returns the number of items
 *
 *  @param  self  a vector structure
 *  @return       number of items
 */
  size_t
  vector_size( const vector_t *self );


/**
 *  Reserve storage such that it can hold at last size items.
 *
 *  @param  self  a vector structure
 *  @param  size  the new storage capacity
 */
  void
  vector_reserve( vector_t *self,
                  const size_t size );


/**
 *  Returns current storage capacity
 *
 *  @param  self  a vector structure
 *  @return       storage capacity
 */
  size_t
  vector_capacity( const vector_t *self );


/**
 *  Decrease capacity to fit actual size.
 *
 *  @param  self  a vector structure
 */
  void
  vector_shrink( vector_t *self );


/**
 *  Removes all items.
 *
 *  @param  self  a vector structure
 */
  void
  vector_clear( vector_t *self );


/**
 *  Replace an item.
 *
 *  @param  self  a vector structure
 *  @param  index the index of the item to be replaced
 *  @param  item  the new item
 */
  void
  vector_set( vector_t *self,
              const size_t index,
              const void *item );


/**
 *  Erase an item.
 *
 *  @param  self  a vector structure
 *  @param  index the index of the item to be erased
 */
  void
  vector_erase( vector_t *self,
                const size_t index );


/**
 *  Erase a range of items.
 *
 *  @param  self  a vector structure
 *  @param  first the index of the first item to be erased
 *  @param  last  the index of the last item to be erased
 */
  void
  vector_erase_range( vector_t *self,
                      const size_t first,
                      const size_t last );


/**
 *  Appends given item to the end of the vector.
 *
 *  @param  self a vector structure
 *  @param  item the item to be inserted
 */
  void
  vector_push_back( vector_t *self,
                    const void *item );


/**
 *  Removes the last item of the vector.
 *
 *  @param  self a vector structure
 */
  void
  vector_pop_back( vector_t *self );


/**
 *  Resizes the vector to contain size items
 *
 *  If the current size is less than size, additional items are appended and
 *  initialized with value. If the current size is greater than size, the
 *  vector is reduced to its first size elements.
 *
 *  @param  self a vector structure
 *  @param  size the new size
 */
  void
  vector_resize( vector_t *self,
                 const size_t size );


/**
 *  Insert a single item at specified index.
 *
 *  @param  self  a vector structure
 *  @param  index location before which to insert item
 *  @param  item  the item to be inserted
 */
  void
  vector_insert( vector_t *self,
                 const size_t index,
                 const void *item );


/**
 *  Insert raw data at specified index.
 *
 *  @param  self  a vector structure
 *  @param  index location before which to insert item
 *  @param  data  a pointer to the items to be inserted
 *  @param  count the number of items to be inserted
 */
  void
  vector_insert_data( vector_t *self,
                      const size_t index,
                      const void * data,
                      const size_t count );


/**
 *  Append raw data to the end of the vector.
 *
 *  @param  self  a vector structure
 *  @param  data  a pointer to the items to be inserted
 *  @param  count the number of items to be inserted
 */
  void
  vector_push_back_data( vector_t *self,
                         const void * data,
                         const size_t count );


/**
 *  Sort vector items according to cmp function.
 *
 *  @param  self  a vector structure
 *  @param  cmp   a pointer a comparison function
 */
  void
  vector_sort( vector_t *self,
               int (*cmp)(const void *, const void *) );    




/**
 * A list of possible ways to render a glyph.
 */
typedef enum rendermode_t
{
    RENDER_NORMAL,
    RENDER_OUTLINE_EDGE,
    RENDER_OUTLINE_POSITIVE,
    RENDER_OUTLINE_NEGATIVE,
    RENDER_SIGNED_DISTANCE_FIELD
} rendermode_t;


/**
 * A structure that hold a kerning value relatively to a Unicode
 * codepoint.
 *
 * This structure cannot be used alone since the (necessary) right
 * Unicode codepoint is implicitely held by the owner of this structure.
 */
typedef struct kerning_t
{
    /**
     * Left Unicode codepoint in the kern pair in UTF-32 LE encoding.
     */
    uint32_t codepoint;

    /**
     * Kerning value (in fractional pixels).
     */
    float kerning;

} kerning_t;




/*
 * Glyph metrics:
 * --------------
 *
 *                       xmin                     xmax
 *                        |                         |
 *                        |<-------- width -------->|
 *                        |                         |
 *              |         +-------------------------+----------------- ymax
 *              |         |    ggggggggg   ggggg    |     ^        ^
 *              |         |   g:::::::::ggg::::g    |     |        |
 *              |         |  g:::::::::::::::::g    |     |        |
 *              |         | g::::::ggggg::::::gg    |     |        |
 *              |         | g:::::g     g:::::g     |     |        |
 *    offset_x -|-------->| g:::::g     g:::::g     |  offset_y    |
 *              |         | g:::::g     g:::::g     |     |        |
 *              |         | g::::::g    g:::::g     |     |        |
 *              |         | g:::::::ggggg:::::g     |     |        |
 *              |         |  g::::::::::::::::g     |     |      height
 *              |         |   gg::::::::::::::g     |     |        |
 *  baseline ---*---------|---- gggggggg::::::g-----*--------      |
 *            / |         |             g:::::g     |              |
 *     origin   |         | gggggg      g:::::g     |              |
 *              |         | g:::::gg   gg:::::g     |              |
 *              |         |  g::::::ggg:::::::g     |              |
 *              |         |   gg:::::::::::::g      |              |
 *              |         |     ggg::::::ggg        |              |
 *              |         |         gggggg          |              v
 *              |         +-------------------------+----------------- ymin
 *              |                                   |
 *              |------------- advance_x ---------->|
 */

/**
 * A structure that describe a glyph.
 */
typedef struct texture_glyph_t
{
    /**
     * Unicode codepoint this glyph represents in UTF-32 LE encoding.
     */
    uint32_t codepoint;

    /**
     * Glyph's width in pixels.
     */
    size_t width;

    /**
     * Glyph's height in pixels.
     */
    size_t height;

    /**
     * Glyph's left bearing expressed in integer pixels.
     */
    int offset_x;

    /**
     * Glyphs's top bearing expressed in integer pixels.
     *
     * Remember that this is the distance from the baseline to the top-most
     * glyph scanline, upwards y coordinates being positive.
     */
    int offset_y;

    /**
     * For horizontal text layouts, this is the horizontal distance (in
     * fractional pixels) used to increment the pen position when the glyph is
     * drawn as part of a string of text.
     */
    float advance_x;

    /**
     * For vertical text layouts, this is the vertical distance (in fractional
     * pixels) used to increment the pen position when the glyph is drawn as
     * part of a string of text.
     */
    float advance_y;

    /**
     * First normalized texture coordinate (x) of top-left corner
     */
    float s0;

    /**
     * Second normalized texture coordinate (y) of top-left corner
     */
    float t0;

    /**
     * First normalized texture coordinate (x) of bottom-right corner
     */
    float s1;

    /**
     * Second normalized texture coordinate (y) of bottom-right corner
     */
    float t1;

    /**
     * A vector of kerning pairs relative to this glyph.
     */
    vector_t * kerning;

    /**
     * Mode this glyph was rendered
     */
    rendermode_t rendermode;

    /**
     * Glyph outline thickness
     */
    float outline_thickness;

} texture_glyph_t;



/**
 *  Texture font structure.
 */
typedef struct texture_font_t
{
    /**
     * Vector of glyphs contained in this font.
     */
    vector_t * glyphs;

    /**
     * Atlas structure to store glyphs data.
     */
    texture_atlas_t * atlas;

    /**
     * font location
     */
    enum {
        TEXTURE_FONT_FILE = 0,
        TEXTURE_FONT_MEMORY,
    } location;

    union {
        /**
         * Font filename, for when location == TEXTURE_FONT_FILE
         */
        char *filename;

        /**
         * Font memory address, for when location == TEXTURE_FONT_MEMORY
         */
        struct {
            const void *base;
            size_t size;
        } memory;
    };

    /**
     * Font size
     */
    float size;

    /**
     * Whether to use autohint when rendering font
     */
    int hinting;

    /**
     * Mode the font is rendering its next glyph
     */
    rendermode_t rendermode;

    /**
     * Outline thickness
     */
    float outline_thickness;

    /**
     * Whether to use our own lcd filter.
     */
    int filtering;

    /**
     * LCD filter weights
     */
    unsigned char lcd_weights[5];

    /**
     * Whether to use kerning if available
     */
    int kerning;


    /**
     * This field is simply used to compute a default line spacing (i.e., the
     * baseline-to-baseline distance) when writing text with this font. Note
     * that it usually is larger than the sum of the ascender and descender
     * taken as absolute values. There is also no guarantee that no glyphs
     * extend above or below subsequent baselines when using this distance.
     */
    float height;

    /**
     * This field is the distance that must be placed between two lines of
     * text. The baseline-to-baseline distance should be computed as:
     * ascender - descender + linegap
     */
    float linegap;

    /**
     * The ascender is the vertical distance from the horizontal baseline to
     * the highest 'character' coordinate in a font face. Unfortunately, font
     * formats define the ascender differently. For some, it represents the
     * ascent of all capital latin characters (without accents), for others it
     * is the ascent of the highest accented character, and finally, other
     * formats define it as being equal to bbox.yMax.
     */
    float ascender;

    /**
     * The descender is the vertical distance from the horizontal baseline to
     * the lowest 'character' coordinate in a font face. Unfortunately, font
     * formats define the descender differently. For some, it represents the
     * descent of all capital latin characters (without accents), for others it
     * is the ascent of the lowest accented character, and finally, other
     * formats define it as being equal to bbox.yMin. This field is negative
     * for values below the baseline.
     */
    float descender;

    /**
     * The position of the underline line for this face. It is the center of
     * the underlining stem. Only relevant for scalable formats.
     */
    float underline_position;

    /**
     * The thickness of the underline for this face. Only relevant for scalable
     * formats.
     */
    float underline_thickness;

} texture_font_t;



/**
 * This function creates a new texture font from given filename and size.  The
 * texture atlas is used to store glyph on demand. Note the depth of the atlas
 * will determine if the font is rendered as alpha channel only (depth = 1) or
 * RGB (depth = 3) that correspond to subpixel rendering (if available on your
 * freetype implementation).
 *
 * @param atlas     A texture atlas
 * @param pt_size   Size of font to be created (in points)
 * @param filename  A font filename
 *
 * @return A new empty font (no glyph inside yet)
 *
 */
  texture_font_t *
  texture_font_new_from_file( texture_atlas_t * atlas,
                              const float pt_size,
                              const char * filename );


/**
 * This function creates a new texture font from a memory location and size.
 * The texture atlas is used to store glyph on demand. Note the depth of the
 * atlas will determine if the font is rendered as alpha channel only
 * (depth = 1) or RGB (depth = 3) that correspond to subpixel rendering (if
 * available on your freetype implementation).
 *
 * @param atlas       A texture atlas
 * @param pt_size     Size of font to be created (in points)
 * @param memory_base Start of the font file in memory
 * @param memory_size Size of the font file memory region, in bytes
 *
 * @return A new empty font (no glyph inside yet)
 *
 */
  texture_font_t *
  texture_font_new_from_memory( texture_atlas_t *atlas,
                                float pt_size,
                                const void *memory_base,
                                size_t memory_size );

/**
 * Delete a texture font. Note that this does not delete the glyph from the
 * texture atlas.
 *
 * @param self a valid texture font
 */
  void
  texture_font_delete( texture_font_t * self );


/**
 * Request a new glyph from the font. If it has not been created yet, it will
 * be.
 *
 * @param self      A valid texture font
 * @param codepoint Character codepoint to be loaded in UTF-8 encoding.
 *
 * @return A pointer on the new glyph or 0 if the texture atlas is not big
 *         enough
 *
 */
  texture_glyph_t *
  texture_font_get_glyph( texture_font_t * self,
                          const char * codepoint );

/** 
 * Request an already loaded glyph from the font. 
 * 
 * @param self      A valid texture font
 * @param codepoint Character codepoint to be found in UTF-8 encoding.
 *
 * @return A pointer on the glyph or 0 if the glyph is not loaded
 */
 texture_glyph_t *
 texture_font_find_glyph( texture_font_t * self,
                          const char * codepoint );
    
/**
 * Request the loading of a given glyph.
 *
 * @param self       A valid texture font
 * @param codepoints Character codepoint to be loaded in UTF-8 encoding.
 *
 * @return One if the glyph could be loaded, zero if not.
 */
  int
  texture_font_load_glyph( texture_font_t * self,
                           const char * codepoint );

/**
 * Request the loading of several glyphs at once.
 *
 * @param self       A valid texture font
 * @param codepoints Character codepoints to be loaded in UTF-8 encoding. May
 *                   contain duplicates.
 *
 * @return Number of missed glyph if the texture is not big enough to hold
 *         every glyphs.
 */
  size_t
  texture_font_load_glyphs( texture_font_t * self,
                            const char * codepoints );
  /*
   *Increases the size of a fonts texture atlas
   *Invalidates all pointers to font->atlas->data
   *Changes the UV Coordinates of existing glyphs in the font
   *
   *@param self A valid texture font
   *@param width_new Width of the texture atlas after resizing (must be bigger or equal to current width)
   *@param height_new Height of the texture atlas after resizing (must be bigger or equal to current height)
   */
  void
  texture_font_enlarge_atlas( texture_font_t * self, size_t width_new,
                              size_t height_new);
/**
 * Get the kerning between two horizontal glyphs.
 *
 * @param self      A valid texture glyph
 * @param codepoint Character codepoint of the peceding character in UTF-8 encoding.
 *
 * @return x kerning value
 */
float
texture_glyph_get_kerning( const texture_glyph_t * self,
                           const char * codepoint );


/**
 * Creates a new empty glyph
 *
 * @return a new empty glyph (not valid)
 */
texture_glyph_t *
texture_glyph_new( void );    


/**
 * Creates a new empty texture atlas.
 *
 * @param   width   width of the atlas
 * @param   height  height of the atlas
 * @param   depth   bit depth of the atlas
 * @return          a new empty texture atlas.
 *
 */
  texture_atlas_t *
  texture_atlas_new( const size_t width,
                     const size_t height,
                     const size_t depth );


/**
 *  Deletes a texture atlas.
 *
 *  @param self a texture atlas structure
 *
 */
  void
  texture_atlas_delete( texture_atlas_t * self );


/**
 *  Allocate a new region in the atlas.
 *
 *  @param self   a texture atlas structure
 *  @param width  width of the region to allocate
 *  @param height height of the region to allocate
 *  @return       Coordinates of the allocated region
 *
 */
  ivec4
  texture_atlas_get_region( texture_atlas_t * self,
                            const size_t width,
                            const size_t height );


/**
 *  Upload data to the specified atlas region.
 *
 *  @param self   a texture atlas structure
 *  @param x      x coordinate the region
 *  @param y      y coordinate the region
 *  @param width  width of the region
 *  @param height height of the region
 *  @param data   data to be uploaded into the specified region
 *  @param stride stride of the data
 *
 */
  void
  texture_atlas_set_region( texture_atlas_t * self,
                            const size_t x,
                            const size_t y,
                            const size_t width,
                            const size_t height,
                            const unsigned char *data,
                            const size_t stride );

/**
 *  Remove all allocated regions from the atlas.
 *
 *  @param self   a texture atlas structure
 */
  void
  texture_atlas_clear( texture_atlas_t * self );    


/**
 * Read a fragment or vertex shader from a file
 *
 * @param filename file to read shader from
 * @return         a newly-allocated text buffer containing code. This buffer
 *                 must be freed after usage.
 *
 */
  char *
  shader_read( const char *filename );


/**
 * Compile a shader from a text buffer.
 *
 * @param source code of the shader
 * @param type   type of the shader
 *
 * @return a handle on the compiled program
 *
 */
  GLuint
  shader_compile( const char* source,
                  const GLenum type );


/**
 * Load a vertex and fragment shader sources and build program
 *
 * @param  vert_filename vertex shader filename
 * @param  frag_filename fragment shader filename
 *
 * @return a handle on the built program
 *
 */
  GLuint
  shader_load( const char * vert_filename,
               const char * frag_filename );    

sjs_string sjt_call14;
sjs_string sjt_call15;
sjs_string sjt_call16;
sjs_sdlSurface_heap* sjt_cast1;
sjs_borderChild_heap* sjt_cast10;
sjs_buttonElement_heap* sjt_cast12;
sjs_borderChild_heap* sjt_cast18;
sjs_boxElement_heap* sjt_cast19;
sjs_boxElement_heap* sjt_cast20;
int32_t sjt_cast4;
int32_t sjt_cast5;
sjs_borderLayout_heap* sjt_cast6;
int32_t sjt_cast9;
sjs_anon6* sjt_dot159;
sjs_anon7* sjt_dot160;
sji_surface* sjt_dot161;
sji_surface* sjt_dot162;
sji_surface* sjt_dot163;
sjs_anon5* sjt_dot164;
sjs_anon8* sjt_dot165;
sjs_anon6* sjt_dot169;
sjs_anon8* sjt_dot170;
sjs_anon6* sjt_dot171;
int32_t sjt_functionParam32;
int32_t sjt_functionParam33;
sji_element* sjt_functionParam34;
int32_t sjt_functionParam37;
sji_element* sjt_functionParam38;
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
int32_t sjv_i32_max;
int32_t sjv_i32_min;
sjs_anon2 sjv_parse;
sjs_anon3 sjv_random;
sji_element* sjv_root;
sji_surface* sjv_rootSurface;
sjs_anon7 sjv_style;
uint32_t sjv_u32_max;

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
void sjf_anon6_green(sjs_anon6* _parent, sjs_color* _return);
void sjf_anon6_green_heap(sjs_anon6* _parent, sjs_color_heap** _return);
void sjf_anon6_heap(sjs_anon6_heap* _this);
void sjf_anon6_red(sjs_anon6* _parent, sjs_color* _return);
void sjf_anon6_red_heap(sjs_anon6* _parent, sjs_color_heap** _return);
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
void sjf_borderChild_getRect(sjs_borderChild* _parent, sjs_rect** _return);
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
void sjf_borderLayout_getRect(sjs_borderLayout* _parent, sjs_rect** _return);
void sjf_borderLayout_getSize(sjs_borderLayout* _parent, sjs_size* maxSize, sjs_size* _return);
void sjf_borderLayout_getSize_heap(sjs_borderLayout* _parent, sjs_size* maxSize, sjs_size_heap** _return);
void sjf_borderLayout_heap(sjs_borderLayout_heap* _this);
sjs_object* sjf_borderLayout_heap_asInterface(sjs_borderLayout_heap* _this, int typeId);
sji_element* sjf_borderLayout_heap_as_sji_element(sjs_borderLayout_heap* _this);
void sjf_borderLayout_render(sjs_borderLayout* _parent, sji_surface* surface);
void sjf_borderLayout_setRect(sjs_borderLayout* _parent, sjs_rect* rect_);
void sjf_boxElement(sjs_boxElement* _this);
sjs_object* sjf_boxElement_asInterface(sjs_boxElement* _this, int typeId);
sji_element* sjf_boxElement_as_sji_element(sjs_boxElement* _this);
void sjf_boxElement_copy(sjs_boxElement* _this, sjs_boxElement* to);
void sjf_boxElement_destroy(sjs_boxElement* _this);
void sjf_boxElement_getChildren(sjs_boxElement* _parent, sjs_array_heap_element** _return);
void sjf_boxElement_getRect(sjs_boxElement* _parent, sjs_rect** _return);
void sjf_boxElement_getSize(sjs_boxElement* _parent, sjs_size* maxSize, sjs_size* _return);
void sjf_boxElement_getSize_heap(sjs_boxElement* _parent, sjs_size* maxSize, sjs_size_heap** _return);
void sjf_boxElement_heap(sjs_boxElement_heap* _this);
sjs_object* sjf_boxElement_heap_asInterface(sjs_boxElement_heap* _this, int typeId);
sji_element* sjf_boxElement_heap_as_sji_element(sjs_boxElement_heap* _this);
void sjf_boxElement_render(sjs_boxElement* _parent, sji_surface* surface);
void sjf_boxElement_setRect(sjs_boxElement* _parent, sjs_rect* rect_);
void sjf_buttonElement(sjs_buttonElement* _this);
sjs_object* sjf_buttonElement_asInterface(sjs_buttonElement* _this, int typeId);
sji_element* sjf_buttonElement_as_sji_element(sjs_buttonElement* _this);
sji_mouseHandler* sjf_buttonElement_as_sji_mouseHandler(sjs_buttonElement* _this);
void sjf_buttonElement_copy(sjs_buttonElement* _this, sjs_buttonElement* to);
void sjf_buttonElement_destroy(sjs_buttonElement* _this);
void sjf_buttonElement_getChildren(sjs_buttonElement* _parent, sjs_array_heap_element** _return);
void sjf_buttonElement_getRect(sjs_buttonElement* _parent, sjs_rect** _return);
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
void sjf_margin(sjs_margin* _this);
void sjf_margin_copy(sjs_margin* _this, sjs_margin* to);
void sjf_margin_destroy(sjs_margin* _this);
void sjf_margin_heap(sjs_margin_heap* _this);
void sjf_point(sjs_point* _this);
void sjf_point_copy(sjs_point* _this, sjs_point* to);
void sjf_point_destroy(sjs_point* _this);
void sjf_point_heap(sjs_point_heap* _this);
void sjf_rect(sjs_rect* _this);
void sjf_rect_containsPoint(sjs_rect* _parent, sjs_point* point, bool* _return);
void sjf_rect_copy(sjs_rect* _this, sjs_rect* to);
void sjf_rect_destroy(sjs_rect* _this);
void sjf_rect_heap(sjs_rect_heap* _this);
void sjf_rect_subtractMargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return);
void sjf_rect_subtractMargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect_heap** _return);
void sjf_runLoop(void);
void sjf_sdlSurface(sjs_sdlSurface* _this);
sjs_object* sjf_sdlSurface_asInterface(sjs_sdlSurface* _this, int typeId);
sji_surface* sjf_sdlSurface_as_sji_surface(sjs_sdlSurface* _this);
void sjf_sdlSurface_clear(sjs_sdlSurface* _parent);
void sjf_sdlSurface_copy(sjs_sdlSurface* _this, sjs_sdlSurface* to);
void sjf_sdlSurface_destroy(sjs_sdlSurface* _this);
void sjf_sdlSurface_drawImage(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_image* image);
void sjf_sdlSurface_drawRect(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_color* color);
void sjf_sdlSurface_drawText(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_font* font, sjs_string* text, sjs_color* color);
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
void sjf_size_addMargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return);
void sjf_size_addMargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size_heap** _return);
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




/*
 * Compute the local gradient at edge pixels using convolution filters.
 * The gradient is computed only at edge pixels. At other places in the
 * image, it is never used, and it's mostly zero anyway.
 */
void computegradient(double *img, int w, int h, double *gx, double *gy)
{
    int i,j,k;
    double glength;
#define SQRT2 1.4142136
    for(i = 1; i < h-1; i++) { // Avoid edges where the kernels would spill over
        for(j = 1; j < w-1; j++) {
            k = i*w + j;
            if((img[k]>0.0) && (img[k]<1.0)) { // Compute gradient for edge pixels only
                gx[k] = -img[k-w-1] - SQRT2*img[k-1] - img[k+w-1] + img[k-w+1] + SQRT2*img[k+1] + img[k+w+1];
                gy[k] = -img[k-w-1] - SQRT2*img[k-w] - img[k-w+1] + img[k+w-1] + SQRT2*img[k+w] + img[k+w+1];
                glength = gx[k]*gx[k] + gy[k]*gy[k];
                if(glength > 0.0) { // Avoid division by zero
                    glength = sqrt(glength);
                    gx[k]=gx[k]/glength;
                    gy[k]=gy[k]/glength;
                }
            }
        }
    }
    // TODO: Compute reasonable values for gx, gy also around the image edges.
    // (These are zero now, which reduces the accuracy for a 1-pixel wide region
	// around the image edge.) 2x2 kernels would be suitable for this.
}

/*
 * A somewhat tricky function to approximate the distance to an edge in a
 * certain pixel, with consideration to either the local gradient (gx,gy)
 * or the direction to the pixel (dx,dy) and the pixel greyscale value a.
 * The latter alternative, using (dx,dy), is the metric used by edtaa2().
 * Using a local estimate of the edge gradient (gx,gy) yields much better
 * accuracy at and near edges, and reduces the error even at distant pixels
 * provided that the gradient direction is accurately estimated.
 */
double edgedf(double gx, double gy, double a)
{
    double df, glength, temp, a1;

    if ((gx == 0) || (gy == 0)) { // Either A) gu or gv are zero, or B) both
        df = 0.5-a;  // Linear approximation is A) correct or B) a fair guess
    } else {
        glength = sqrt(gx*gx + gy*gy);
        if(glength>0) {
            gx = gx/glength;
            gy = gy/glength;
        }
        /* Everything is symmetric wrt sign and transposition,
         * so move to first octant (gx>=0, gy>=0, gx>=gy) to
         * avoid handling all possible edge directions.
         */
        gx = fabs(gx);
        gy = fabs(gy);
        if(gx<gy) {
            temp = gx;
            gx = gy;
            gy = temp;
        }
        a1 = 0.5*gy/gx;
        if (a < a1) { // 0 <= a < a1
            df = 0.5*(gx + gy) - sqrt(2.0*gx*gy*a);
        } else if (a < (1.0-a1)) { // a1 <= a <= 1-a1
            df = (0.5-a)*gx;
        } else { // 1-a1 < a <= 1
            df = -0.5*(gx + gy) + sqrt(2.0*gx*gy*(1.0-a));
        }
    }
    return df;
}

double distaa3(double *img, double *gximg, double *gyimg, int w, int c, int xc, int yc, int xi, int yi)
{
  double di, df, dx, dy, gx, gy, a;
  int closest;

  closest = c-xc-yc*w; // Index to the edge pixel pointed to from c
  a = img[closest];    // Grayscale value at the edge pixel
  gx = gximg[closest]; // X gradient component at the edge pixel
  gy = gyimg[closest]; // Y gradient component at the edge pixel

  if(a > 1.0) a = 1.0;
  if(a < 0.0) a = 0.0; // Clip grayscale values outside the range [0,1]
  if(a == 0.0) return 1000000.0; // Not an object pixel, return "very far" ("don't know yet")

  dx = (double)xi;
  dy = (double)yi;
  di = sqrt(dx*dx + dy*dy); // Length of integer vector, like a traditional EDT
  if(di==0) { // Use local gradient only at edges
      // Estimate based on local gradient only
      df = edgedf(gx, gy, a);
  } else {
      // Estimate gradient based on direction to edge (accurate for large di)
      df = edgedf(dx, dy, a);
  }
  return di + df; // Same metric as edtaa2, except at edges (where di=0)
}

// Shorthand macro: add ubiquitous parameters dist, gx, gy, img and w and call distaa3()
#define DISTAA(c,xc,yc,xi,yi) (distaa3(img, gx, gy, w, c, xc, yc, xi, yi))

void edtaa3(double *img, double *gx, double *gy, int w, int h, short *distx, short *disty, double *dist)
{
  int x, y, i, c;
  int offset_u, offset_ur, offset_r, offset_rd,
  offset_d, offset_dl, offset_l, offset_lu;
  double olddist, newdist;
  int cdistx, cdisty, newdistx, newdisty;
  int changed;
  double epsilon = 1e-3;

  /* Initialize index offsets for the current image width */
  offset_u = -w;
  offset_ur = -w+1;
  offset_r = 1;
  offset_rd = w+1;
  offset_d = w;
  offset_dl = w-1;
  offset_l = -1;
  offset_lu = -w-1;

  /* Initialize the distance images */
  for(i=0; i<w*h; i++) {
    distx[i] = 0; // At first, all pixels point to
    disty[i] = 0; // themselves as the closest known.
    if(img[i] <= 0.0)
      {
	dist[i]= 1000000.0; // Big value, means "not set yet"
      }
    else if (img[i]<1.0) {
      dist[i] = edgedf(gx[i], gy[i], img[i]); // Gradient-assisted estimate
    }
    else {
      dist[i]= 0.0; // Inside the object
    }
  }

  /* Perform the transformation */
  do
    {
      changed = 0;

      /* Scan rows, except first row */
      for(y=1; y<h; y++)
        {

          /* move index to leftmost pixel of current row */
          i = y*w;

          /* scan right, propagate distances from above & left */

          /* Leftmost pixel is special, has no left neighbors */
          olddist = dist[i];
          if(olddist > 0) // If non-zero distance or not set yet
            {
	      c = i + offset_u; // Index of candidate for testing
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx;
              newdisty = cdisty+1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_ur;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx-1;
              newdisty = cdisty+1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  changed = 1;
                }
            }
          i++;

          /* Middle pixels have all neighbors */
          for(x=1; x<w-1; x++, i++)
            {
              olddist = dist[i];
              if(olddist <= 0) continue; // No need to update further

	      c = i+offset_l;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx+1;
              newdisty = cdisty;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_lu;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx+1;
              newdisty = cdisty+1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_u;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx;
              newdisty = cdisty+1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_ur;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx-1;
              newdisty = cdisty+1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  changed = 1;
                }
            }

          /* Rightmost pixel of row is special, has no right neighbors */
          olddist = dist[i];
          if(olddist > 0) // If not already zero distance
            {
	      c = i+offset_l;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx+1;
              newdisty = cdisty;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_lu;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx+1;
              newdisty = cdisty+1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_u;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx;
              newdisty = cdisty+1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  changed = 1;
                }
            }

          /* Move index to second rightmost pixel of current row. */
          /* Rightmost pixel is skipped, it has no right neighbor. */
          i = y*w + w-2;

          /* scan left, propagate distance from right */
          for(x=w-2; x>=0; x--, i--)
            {
              olddist = dist[i];
              if(olddist <= 0) continue; // Already zero distance

	      c = i+offset_r;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx-1;
              newdisty = cdisty;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  changed = 1;
                }
            }
        }

      /* Scan rows in reverse order, except last row */
      for(y=h-2; y>=0; y--)
        {
          /* move index to rightmost pixel of current row */
          i = y*w + w-1;

          /* Scan left, propagate distances from below & right */

          /* Rightmost pixel is special, has no right neighbors */
          olddist = dist[i];
          if(olddist > 0) // If not already zero distance
            {
	      c = i+offset_d;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx;
              newdisty = cdisty-1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_dl;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx+1;
              newdisty = cdisty-1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  changed = 1;
                }
            }
          i--;

          /* Middle pixels have all neighbors */
          for(x=w-2; x>0; x--, i--)
            {
              olddist = dist[i];
              if(olddist <= 0) continue; // Already zero distance

	      c = i+offset_r;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx-1;
              newdisty = cdisty;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_rd;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx-1;
              newdisty = cdisty-1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_d;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx;
              newdisty = cdisty-1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
                  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_dl;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx+1;
              newdisty = cdisty-1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
                  dist[i]=newdist;
                  changed = 1;
                }
            }
          /* Leftmost pixel is special, has no left neighbors */
          olddist = dist[i];
          if(olddist > 0) // If not already zero distance
            {
	      c = i+offset_r;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx-1;
              newdisty = cdisty;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
                  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_rd;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx-1;
              newdisty = cdisty-1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
		  dist[i]=newdist;
                  olddist=newdist;
                  changed = 1;
                }

	      c = i+offset_d;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx;
              newdisty = cdisty-1;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
                  dist[i]=newdist;
                  changed = 1;
                }
            }

          /* Move index to second leftmost pixel of current row. */
          /* Leftmost pixel is skipped, it has no left neighbor. */
          i = y*w + 1;
          for(x=1; x<w; x++, i++)
            {
              /* scan right, propagate distance from left */
              olddist = dist[i];
              if(olddist <= 0) continue; // Already zero distance

	      c = i+offset_l;
	      cdistx = distx[c];
	      cdisty = disty[c];
              newdistx = cdistx+1;
              newdisty = cdisty;
              newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
              if(newdist < olddist-epsilon)
                {
                  distx[i]=newdistx;
                  disty[i]=newdisty;
                  dist[i]=newdist;
                  changed = 1;
                }
            }
        }
    }
  while(changed); // Sweep until no more updates are made

  /* The transformation is completed. */

}


double *
make_distance_mapd( double *data, unsigned int width, unsigned int height )
{
    short * xdist = (short *)  malloc( width * height * sizeof(short) );
    short * ydist = (short *)  malloc( width * height * sizeof(short) );
    double * gx   = (double *) calloc( width * height, sizeof(double) );
    double * gy      = (double *) calloc( width * height, sizeof(double) );
    double * outside = (double *) calloc( width * height, sizeof(double) );
    double * inside  = (double *) calloc( width * height, sizeof(double) );
    double vmin = DBL_MAX;
    unsigned int i;

    // Compute outside = edtaa3(bitmap); % Transform background (0's)
    computegradient( data, width, height, gx, gy);
    edtaa3(data, gx, gy, width, height, xdist, ydist, outside);
    for( i=0; i<width*height; ++i)
        if( outside[i] < 0.0 )
            outside[i] = 0.0;

    // Compute inside = edtaa3(1-bitmap); % Transform foreground (1's)
    memset( gx, 0, sizeof(double)*width*height );
    memset( gy, 0, sizeof(double)*width*height );
    for( i=0; i<width*height; ++i)
        data[i] = 1 - data[i];
    computegradient( data, width, height, gx, gy );
    edtaa3( data, gx, gy, width, height, xdist, ydist, inside );
    for( i=0; i<width*height; ++i )
        if( inside[i] < 0 )
            inside[i] = 0.0;

    // distmap = outside - inside; % Bipolar distance field
    for( i=0; i<width*height; ++i)
    {
        outside[i] -= inside[i];
        if( outside[i] < vmin )
            vmin = outside[i];
    }

    vmin = fabs(vmin);

    for( i=0; i<width*height; ++i)
    {
        double v = outside[i];
        if     ( v < -vmin) outside[i] = -vmin;
        else if( v > +vmin) outside[i] = +vmin;
        data[i] = (outside[i]+vmin)/(2*vmin);
    }

    free( xdist );
    free( ydist );
    free( gx );
    free( gy );
    free( outside );
    free( inside );
    return data;
}

unsigned char *
make_distance_mapb( unsigned char *img,
                    unsigned int width, unsigned int height )
{
    double * data    = (double *) calloc( width * height, sizeof(double) );
    unsigned char *out = (unsigned char *) malloc( width * height * sizeof(unsigned char) );
    unsigned int i;

    // find minimimum and maximum values
    double img_min = DBL_MAX;
    double img_max = DBL_MIN;

    for( i=0; i<width*height; ++i)
    {
        double v = img[i];
        data[i] = v;
        if (v > img_max)
            img_max = v;
        if (v < img_min)
            img_min = v;
    }

    // Map values from 0 - 255 to 0.0 - 1.0
    for( i=0; i<width*height; ++i)
        data[i] = (img[i]-img_min)/img_max;

    data = make_distance_mapd(data, width, height);

    // map values from 0.0 - 1.0 to 0 - 255
    for( i=0; i<width*height; ++i)
        out[i] = (unsigned char)(255*(1-data[i]));

    free( data );

    return out;
}


// ----------------------------------------------------- utf8_surrogate_len ---
size_t
utf8_surrogate_len( const char* character )
{
    size_t result = 0;
    char test_char;

    if (!character)
        return 0;

    test_char = character[0];

    if ((test_char & 0x80) == 0)
        return 1;

    while (test_char & 0x80)
    {
        test_char <<= 1;
        result++;
    }

    return result;
}

// ------------------------------------------------------------ utf8_strlen ---
size_t
utf8_strlen( const char* string )
{
    const char* ptr = string;
    size_t result = 0;

    while (*ptr)
    {
        ptr += utf8_surrogate_len(ptr);
        result++;
    }

    return result;
}

uint32_t
utf8_to_utf32( const char * character )
{
    uint32_t result = -1;

    if( !character )
    {
        return result;
    }

    if( ( character[0] & 0x80 ) == 0x0 )
    {
        result = character[0];
    }

    if( ( character[0] & 0xC0 ) == 0xC0 )
    {
        result = ( ( character[0] & 0x3F ) << 6 ) | ( character[1] & 0x3F );
    }

    if( ( character[0] & 0xE0 ) == 0xE0 )
    {
        result = ( ( character[0] & 0x1F ) << ( 6 + 6 ) ) | ( ( character[1] & 0x3F ) << 6 ) | ( character[2] & 0x3F );
    }

    if( ( character[0] & 0xF0 ) == 0xF0 )
    {
        result = ( ( character[0] & 0x0F ) << ( 6 + 6 + 6 ) ) | ( ( character[1] & 0x3F ) << ( 6 + 6 ) ) | ( ( character[2] & 0x3F ) << 6 ) | ( character[3] & 0x3F );
    }

    if( ( character[0] & 0xF8 ) == 0xF8 )
    {
        result = ( ( character[0] & 0x07 ) << ( 6 + 6 + 6 + 6 ) ) | ( ( character[1] & 0x3F ) << ( 6 + 6 + 6 ) ) | ( ( character[2] & 0x3F ) << ( 6 + 6 ) ) | ( ( character[3] & 0x3F ) << 6 ) | ( character[4] & 0x3F );
    }

    return result;
}








#ifdef WIN32
// strndup() is not available on Windows
char *strndup( const char *s1, size_t n)
{
    char *copy= (char*)malloc( n+1 );
    memcpy( copy, s1, n );
    copy[n] = 0;
    return copy;
};
#endif

/**
 * Buffer status
 */
#define CLEAN  (0)
#define DIRTY  (1)
#define FROZEN (2)


// ----------------------------------------------------------------------------
vertex_buffer_t *
vertex_buffer_new( const char *format )
{
    size_t i, index = 0, stride = 0;
    const char *start = 0, *end = 0;
    GLchar *pointer = 0;

    vertex_buffer_t *self = (vertex_buffer_t *) malloc (sizeof(vertex_buffer_t));
    if( !self )
    {
        return NULL;
    }

    self->format = strdup( format );

    for( i=0; i<MAX_VERTEX_ATTRIBUTE; ++i )
    {
        self->attributes[i] = 0;
    }

    start = format;
    do
    {
        char *desc = 0;
        vertex_attribute_t *attribute;
        GLuint attribute_size = 0;
        end = (char *) (strchr(start+1, ','));

        if (end == NULL)
        {
            desc = strdup( start );
        }
        else
        {
            desc = strndup( start, end-start );
        }
        attribute = vertex_attribute_parse( desc );
        start = end+1;
        free(desc);
        attribute->pointer = pointer;

        switch( attribute->type )
        {
        case GL_BOOL:           attribute_size = sizeof(GLboolean); break;
        case GL_BYTE:           attribute_size = sizeof(GLbyte); break;
        case GL_UNSIGNED_BYTE:  attribute_size = sizeof(GLubyte); break;
        case GL_SHORT:          attribute_size = sizeof(GLshort); break;
        case GL_UNSIGNED_SHORT: attribute_size = sizeof(GLushort); break;
        case GL_INT:            attribute_size = sizeof(GLint); break;
        case GL_UNSIGNED_INT:   attribute_size = sizeof(GLuint); break;
        case GL_FLOAT:          attribute_size = sizeof(GLfloat); break;
        default:                attribute_size = 0;
        }
        stride  += attribute->size*attribute_size;
        pointer += attribute->size*attribute_size;
        self->attributes[index] = attribute;
        index++;
    } while ( end && (index < MAX_VERTEX_ATTRIBUTE) );

    for( i=0; i<index; ++i )
    {
        self->attributes[i]->stride = stride;
    }

#ifdef FREETYPE_GL_USE_VAO
    self->VAO_id = 0;
#endif

    self->vertices = vector_new( stride );
    self->vertices_id  = 0;
    self->GPU_vsize = 0;

    self->indices = vector_new( sizeof(GLuint) );
    self->indices_id  = 0;
    self->GPU_isize = 0;

    self->items = vector_new( sizeof(ivec4) );
    self->state = DIRTY;
    self->mode = GL_TRIANGLES;
    return self;
}



// ----------------------------------------------------------------------------
void
vertex_buffer_delete( vertex_buffer_t *self )
{
    size_t i;

    assert( self );

    for( i=0; i<MAX_VERTEX_ATTRIBUTE; ++i )
    {
        if( self->attributes[i] )
        {
            vertex_attribute_delete( self->attributes[i] );
        }
    }

#ifdef FREETYPE_GL_USE_VAO
    if( self->VAO_id )
    {
        glDeleteVertexArrays( 1, &self->VAO_id );
    }
    self->VAO_id = 0;
#endif

    vector_delete( self->vertices );
    self->vertices = 0;
    if( self->vertices_id )
    {
        glDeleteBuffers( 1, &self->vertices_id );
    }
    self->vertices_id = 0;

    vector_delete( self->indices );
    self->indices = 0;
    if( self->indices_id )
    {
        glDeleteBuffers( 1, &self->indices_id );
    }
    self->indices_id = 0;

    vector_delete( self->items );

    if( self->format )
    {
        free( self->format );
    }
    self->format = 0;
    self->state = 0;
    free( self );
}


// ----------------------------------------------------------------------------
const char *
vertex_buffer_format( const vertex_buffer_t *self )
{
    assert( self );

    return self->format;
}


// ----------------------------------------------------------------------------
size_t
vertex_buffer_size( const vertex_buffer_t *self )
{
    assert( self );

    return vector_size( self->items );
}


// ----------------------------------------------------------------------------
void
vertex_buffer_print( vertex_buffer_t * self )
{
    int i = 0;
    static char *gltypes[9] = {
        "GL_BOOL",
        "GL_BYTE",
        "GL_UNSIGNED_BYTE",
        "GL_SHORT",
        "GL_UNSIGNED_SHORT",
        "GL_INT",
        "GL_UNSIGNED_INT",
        "GL_FLOAT",
        "GL_VOID"
    };

    assert(self);

    fprintf( stderr, "%zu vertices, %zu indices\n",
             vector_size( self->vertices ), vector_size( self->indices ) );
    while( self->attributes[i] )
    {
        int j = 8;
        switch( self->attributes[i]->type )
        {
        case GL_BOOL:           j=0; break;
        case GL_BYTE:           j=1; break;
        case GL_UNSIGNED_BYTE:  j=2; break;
        case GL_SHORT:          j=3; break;
        case GL_UNSIGNED_SHORT: j=4; break;
        case GL_INT:            j=5; break;
        case GL_UNSIGNED_INT:   j=6; break;
        case GL_FLOAT:          j=7; break;
        default:                j=8; break;
        }
        fprintf(stderr, "%s : %dx%s (+%p)\n",
                self->attributes[i]->name,
                self->attributes[i]->size,
                gltypes[j],
                self->attributes[i]->pointer);

        i += 1;
    }
}


// ----------------------------------------------------------------------------
void
vertex_buffer_upload ( vertex_buffer_t *self )
{
    size_t vsize, isize;

    if( self->state == FROZEN )
    {
        return;
    }

    if( !self->vertices_id )
    {
        glGenBuffers( 1, &self->vertices_id );
    }
    if( !self->indices_id )
    {
        glGenBuffers( 1, &self->indices_id );
    }

    vsize = self->vertices->size*self->vertices->item_size;
    isize = self->indices->size*self->indices->item_size;


    // Always upload vertices first such that indices do not point to non
    // existing data (if we get interrupted in between for example).

    // Upload vertices
    glBindBuffer( GL_ARRAY_BUFFER, self->vertices_id );
    if( vsize != self->GPU_vsize )
    {
        glBufferData( GL_ARRAY_BUFFER,
                      vsize, self->vertices->items, GL_DYNAMIC_DRAW );
        self->GPU_vsize = vsize;
    }
    else
    {
        glBufferSubData( GL_ARRAY_BUFFER,
                         0, vsize, self->vertices->items );
    }
    glBindBuffer( GL_ARRAY_BUFFER, 0 );

    // Upload indices
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, self->indices_id );
    if( isize != self->GPU_isize )
    {
        glBufferData( GL_ELEMENT_ARRAY_BUFFER,
                      isize, self->indices->items, GL_DYNAMIC_DRAW );
        self->GPU_isize = isize;
    }
    else
    {
        glBufferSubData( GL_ELEMENT_ARRAY_BUFFER,
                         0, isize, self->indices->items );
    }
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}



// ----------------------------------------------------------------------------
void
vertex_buffer_clear( vertex_buffer_t *self )
{
    assert( self );

    self->state = FROZEN;
    vector_clear( self->indices );
    vector_clear( self->vertices );
    vector_clear( self->items );
    self->state = DIRTY;
}



// ----------------------------------------------------------------------------
void
vertex_buffer_render_setup ( vertex_buffer_t *self, GLenum mode )
{
    size_t i;

#ifdef FREETYPE_GL_USE_VAO
    // Unbind so no existing VAO-state is overwritten,
    // (e.g. the GL_ELEMENT_ARRAY_BUFFER-binding).
    glBindVertexArray( 0 );
#endif

    if( self->state != CLEAN )
    {
        vertex_buffer_upload( self );
        self->state = CLEAN;
    }

#ifdef FREETYPE_GL_USE_VAO
    if( self->VAO_id == 0 )
    {
        // Generate and set up VAO

        glGenVertexArrays( 1, &self->VAO_id );
        glBindVertexArray( self->VAO_id );

        glBindBuffer( GL_ARRAY_BUFFER, self->vertices_id );

        for( i=0; i<MAX_VERTEX_ATTRIBUTE; ++i )
        {
            vertex_attribute_t *attribute = self->attributes[i];
            if( attribute == 0 )
            {
                continue;
            }
            else
            {
                vertex_attribute_enable( attribute );
            }
        }

        glBindBuffer( GL_ARRAY_BUFFER, 0 );

        if( self->indices->size )
        {
            glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, self->indices_id );
        }
    }

    // Bind VAO for drawing
    glBindVertexArray( self->VAO_id );
#else

    glBindBuffer( GL_ARRAY_BUFFER, self->vertices_id );

    for( i=0; i<MAX_VERTEX_ATTRIBUTE; ++i )
    {
        vertex_attribute_t *attribute = self->attributes[i];
        if ( attribute == 0 )
        {
            continue;
        }
        else
        {
            vertex_attribute_enable( attribute );
        }
    }

    if( self->indices->size )
    {
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, self->indices_id );
    }
#endif

    self->mode = mode;
}

// ----------------------------------------------------------------------------
void
vertex_buffer_render_finish ( vertex_buffer_t *self )
{
#ifdef FREETYPE_GL_USE_VAO
    glBindVertexArray( 0 );
#else
    int i;

    for( i=0; i<MAX_VERTEX_ATTRIBUTE; ++i )
    {
        vertex_attribute_t *attribute = self->attributes[i];
        if( attribute == 0 )
        {
            continue;
        }
        else
        {
            glDisableVertexAttribArray( attribute->index );
        }
    }

    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
#endif
}


// ----------------------------------------------------------------------------
void
vertex_buffer_render_item ( vertex_buffer_t *self,
                            size_t index )
{
    ivec4 * item = (ivec4 *) vector_get( self->items, index );
    assert( self );
    assert( index < vector_size( self->items ) );


    if( self->indices->size )
    {
        size_t start = item->istart;
        size_t count = item->icount;
        glDrawElements( self->mode, count, GL_UNSIGNED_INT, (void *)(start*sizeof(GLuint)) );
    }
    else if( self->vertices->size )
    {
        size_t start = item->vstart;
        size_t count = item->vcount;
        glDrawArrays( self->mode, start*self->vertices->item_size, count);
    }
}


// ----------------------------------------------------------------------------
void
vertex_buffer_render ( vertex_buffer_t *self, GLenum mode )
{
    size_t vcount = self->vertices->size;
    size_t icount = self->indices->size;

    vertex_buffer_render_setup( self, mode );
    if( icount )
    {
        glDrawElements( mode, icount, GL_UNSIGNED_INT, 0 );
    }
    else
    {
        glDrawArrays( mode, 0, vcount );
    }
    vertex_buffer_render_finish( self );
}



// ----------------------------------------------------------------------------
void
vertex_buffer_push_back_indices ( vertex_buffer_t * self,
                                  const GLuint * indices,
                                  const size_t icount )
{
    assert( self );

    self->state |= DIRTY;
    vector_push_back_data( self->indices, indices, icount );
}



// ----------------------------------------------------------------------------
void
vertex_buffer_push_back_vertices ( vertex_buffer_t * self,
                                   const void * vertices,
                                   const size_t vcount )
{
    assert( self );

    self->state |= DIRTY;
    vector_push_back_data( self->vertices, vertices, vcount );
}



// ----------------------------------------------------------------------------
void
vertex_buffer_insert_indices ( vertex_buffer_t *self,
                               const size_t index,
                               const GLuint *indices,
                               const size_t count )
{
    assert( self );
    assert( self->indices );
    assert( index < self->indices->size+1 );

    self->state |= DIRTY;
    vector_insert_data( self->indices, index, indices, count );
}



// ----------------------------------------------------------------------------
void
vertex_buffer_insert_vertices( vertex_buffer_t *self,
                               const size_t index,
                               const void *vertices,
                               const size_t vcount )
{
    size_t i;
    assert( self );
    assert( self->vertices );
    assert( index < self->vertices->size+1 );

    self->state |= DIRTY;

     for( i=0; i<self->indices->size; ++i )
    {
        if( *(GLuint *)(vector_get( self->indices, i )) > index )
        {
            *(GLuint *)(vector_get( self->indices, i )) += index;
        }
    }

    vector_insert_data( self->vertices, index, vertices, vcount );
}



// ----------------------------------------------------------------------------
void
vertex_buffer_erase_indices( vertex_buffer_t *self,
                             const size_t first,
                             const size_t last )
{
    assert( self );
    assert( self->indices );
    assert( first < self->indices->size );
    assert( (last) <= self->indices->size );

    self->state |= DIRTY;
    vector_erase_range( self->indices, first, last );
}



// ----------------------------------------------------------------------------
void
vertex_buffer_erase_vertices( vertex_buffer_t *self,
                              const size_t first,
                              const size_t last )
{
    size_t i;
    assert( self );
    assert( self->vertices );
    assert( first < self->vertices->size );
    assert( last <= self->vertices->size );
    assert( last > first );

    self->state |= DIRTY;
    for( i=0; i<self->indices->size; ++i )
    {
        if( *(GLuint *)(vector_get( self->indices, i )) > first )
        {
            *(GLuint *)(vector_get( self->indices, i )) -= (last-first);
        }
    }
    vector_erase_range( self->vertices, first, last );
}



// ----------------------------------------------------------------------------
size_t
vertex_buffer_push_back( vertex_buffer_t * self,
                         const void * vertices, const size_t vcount,
                         const GLuint * indices, const size_t icount )
{
    return vertex_buffer_insert( self, vector_size( self->items ),
                                 vertices, vcount, indices, icount );
}

// ----------------------------------------------------------------------------
size_t
vertex_buffer_insert( vertex_buffer_t * self, const size_t index,
                      const void * vertices, const size_t vcount,
                      const GLuint * indices, const size_t icount )
{
    size_t vstart, istart, i;
    ivec4 item;
    assert( self );
    assert( vertices );
    assert( indices );

    self->state = FROZEN;

    // Push back vertices
    vstart = vector_size( self->vertices );
    vertex_buffer_push_back_vertices( self, vertices, vcount );

    // Push back indices
    istart = vector_size( self->indices );
    vertex_buffer_push_back_indices( self, indices, icount );

    // Update indices within the vertex buffer
    for( i=0; i<icount; ++i )
    {
        *(GLuint *)(vector_get( self->indices, istart+i )) += vstart;
    }

    // Insert item
    item.x = vstart;
    item.y = vcount;
    item.z = istart;
    item.w = icount;
    vector_insert( self->items, index, &item );

    self->state = DIRTY;
    return index;
}

// ----------------------------------------------------------------------------
void
vertex_buffer_erase( vertex_buffer_t * self,
                     const size_t index )
{
    ivec4 * item;
    int vstart;
    size_t vcount, istart, icount, i;

    assert( self );
    assert( index < vector_size( self->items ) );

    item = (ivec4 *) vector_get( self->items, index );
    vstart = item->vstart;
    vcount = item->vcount;
    istart = item->istart;
    icount = item->icount;

    // Update items
    for( i=0; i<vector_size(self->items); ++i )
    {
        ivec4 * item = (ivec4 *) vector_get( self->items, i );
        if( item->vstart > vstart)
        {
            item->vstart -= vcount;
            item->istart -= icount;
        }
    }

    self->state = FROZEN;
    vertex_buffer_erase_indices( self, istart, istart+icount );
    vertex_buffer_erase_vertices( self, vstart, vstart+vcount );
    vector_erase( self->items, index );
    self->state = DIRTY;
}








// ----------------------------------------------------------------------------
vertex_attribute_t *
vertex_attribute_new( GLchar * name,
                      GLint size,
                      GLenum type,
                      GLboolean normalized,
                      GLsizei stride,
                      GLvoid *pointer )
{
    vertex_attribute_t *attribute =
        (vertex_attribute_t *) malloc (sizeof(vertex_attribute_t));

    assert( size > 0 );

    attribute->name       = (GLchar *) strdup( name );
    attribute->index      = -1;
    attribute->size       = size;
    attribute->type       = type;
    attribute->normalized = normalized;
    attribute->stride     = stride;
    attribute->pointer    = pointer;
    return attribute;
}



// ----------------------------------------------------------------------------
void
vertex_attribute_delete( vertex_attribute_t * self )
{
    assert( self );

    free( self->name );
    free( self );
}



// ----------------------------------------------------------------------------
vertex_attribute_t *
vertex_attribute_parse( char *format )
{
    GLenum type = 0;
    int size;
    int normalized = 0;
    char ctype;
    char *name;
    vertex_attribute_t *attr;
    char *p = strchr(format, ':');
    if( p != NULL)
    {
        name = strndup(format, p-format);
        if( *(++p) == '\0' )
        {
            fprintf( stderr, "No size specified for '%s' attribute\n", name );
            free( name );
            return 0;
        }
        size = *p - '0';

        if( *(++p) == '\0' )
        {
            fprintf( stderr, "No format specified for '%s' attribute\n", name );
            free( name );
            return 0;
        }
        ctype = *p;

        if( *(++p) != '\0' )
        {
            if( *p == 'n' )
            {
                normalized = 1;
            }
        }

    }
    else
    {
        fprintf(stderr, "Vertex attribute format not understood ('%s')\n", format );
        return 0;
    }

    switch( ctype )
    {
    case 'b': type = GL_BYTE;           break;
    case 'B': type = GL_UNSIGNED_BYTE;  break;
    case 's': type = GL_SHORT;          break;
    case 'S': type = GL_UNSIGNED_SHORT; break;
    case 'i': type = GL_INT;            break;
    case 'I': type = GL_UNSIGNED_INT;   break;
    case 'f': type = GL_FLOAT;          break;
    default:  type = 0;                 break;
    }


    attr = vertex_attribute_new( name, size, type, normalized, 0, 0 );
    free( name );
    return attr;
}



// ----------------------------------------------------------------------------
void
vertex_attribute_enable( vertex_attribute_t *attr )
{
    if( attr->index == -1 )
    {
        GLint program;
        glGetIntegerv( GL_CURRENT_PROGRAM, &program );
        if( program == 0)
        {
            return;
        }
        attr->index = glGetAttribLocation( program, attr->name );
        if( attr->index == -1 )
        {
            return;
        }
    }
    glEnableVertexAttribArray( attr->index );
    glVertexAttribPointer( attr->index, attr->size, attr->type,
                           attr->normalized, attr->stride, attr->pointer );
}








// ------------------------------------------------------------- vector_new ---
vector_t *
vector_new( size_t item_size )
{
    vector_t *self = (vector_t *) malloc( sizeof(vector_t) );
    assert( item_size );

    if( !self )
    {
        fprintf( stderr,
                 "line %d: No more memory for allocating data\n", __LINE__ );
        exit( EXIT_FAILURE );
    }
    self->item_size = item_size;
    self->size      = 0;
    self->capacity  = 1;
    self->items     = malloc( self->item_size * self->capacity );
    return self;
}



// ---------------------------------------------------------- vector_delete ---
void
vector_delete( vector_t *self )
{
    assert( self );

    free( self->items );
    free( self );
}



// ------------------------------------------------------------- vector_get ---
const void *
vector_get( const vector_t *self,
            size_t index )
{
    assert( self );
    assert( self->size );
    assert( index  < self->size );

    return (char*)(self->items) + index * self->item_size;
}



// ----------------------------------------------------------- vector_front ---
const void *
vector_front( const vector_t *self )
{
    assert( self );
    assert( self->size );

    return vector_get( self, 0 );
}


// ------------------------------------------------------------ vector_back ---
const void *
vector_back( const vector_t *self )
{
    assert( self );
    assert( self->size );

    return vector_get( self, self->size-1 );
}


// -------------------------------------------------------- vector_contains ---
int
vector_contains( const vector_t *self,
                 const void *item,
                 int (*cmp)(const void *, const void *) )
{
    size_t i;
    assert( self );

    for( i=0; i<self->size; ++i )
    {
        if( (*cmp)(item, vector_get(self,i) ) == 0 )
        {
            return 1;
        }
    }
   return 0;
}


// ----------------------------------------------------------- vector_empty ---
int
vector_empty( const vector_t *self )
{
    assert( self );

    return self->size == 0;
}


// ------------------------------------------------------------ vector_size ---
size_t
vector_size( const vector_t *self )
{
    assert( self );

    return self->size;
}


// --------------------------------------------------------- vector_reserve ---
void
vector_reserve( vector_t *self,
                const size_t size )
{
    assert( self );

    if( self->capacity < size)
    {
        self->items = realloc( self->items, size * self->item_size );
        self->capacity = size;
    }
}


// -------------------------------------------------------- vector_capacity ---
size_t
vector_capacity( const vector_t *self )
{
    assert( self );

    return self->capacity;
}


// ---------------------------------------------------------- vector_shrink ---
void
vector_shrink( vector_t *self )
{
    assert( self );

    if( self->capacity > self->size )
    {
        self->items = realloc( self->items, self->size * self->item_size );
    }
    self->capacity = self->size;
}


// ----------------------------------------------------------- vector_clear ---
void
vector_clear( vector_t *self )
{
    assert( self );

    self->size = 0;
}


// ------------------------------------------------------------- vector_set ---
void
vector_set( vector_t *self,
            const size_t index,
            const void *item )
{
    assert( self );
    assert( self->size );
    assert( index  < self->size );

    memcpy( (char *)(self->items) + index * self->item_size,
            item, self->item_size );
}


// ---------------------------------------------------------- vector_insert ---
void
vector_insert( vector_t *self,
               const size_t index,
               const void *item )
{
    assert( self );
    assert( index <= self->size);

    if( self->capacity <= self->size )
    {
        vector_reserve(self, 2 * self->capacity );
    }
    if( index < self->size )
    {
        memmove( (char *)(self->items) + (index + 1) * self->item_size,
                 (char *)(self->items) + (index + 0) * self->item_size,
                 (self->size - index)  * self->item_size);
    }
    self->size++;
    vector_set( self, index, item );
}


// ----------------------------------------------------- vector_erase_range ---
void
vector_erase_range( vector_t *self,
                    const size_t first,
                    const size_t last )
{
    assert( self );
    assert( first < self->size );
    assert( last  < self->size+1 );
    assert( first < last );

    memmove( (char *)(self->items) + first * self->item_size,
             (char *)(self->items) + last  * self->item_size,
             (self->size - last)   * self->item_size);
    self->size -= (last-first);
}


// ----------------------------------------------------------- vector_erase ---
void
vector_erase( vector_t *self,
              const size_t index )
{
    assert( self );
    assert( index < self->size );

    vector_erase_range( self, index, index+1 );
}


// ------------------------------------------------------- vector_push_back ---
void
vector_push_back( vector_t *self,
                  const void *item )
{
    vector_insert( self, self->size, item );
}


// -------------------------------------------------------- vector_pop_back ---
void
vector_pop_back( vector_t *self )
{
    assert( self );
    assert( self->size );

    self->size--;
}


// ---------------------------------------------------------- vector_resize ---
void
vector_resize( vector_t *self,
               const size_t size )
{
    assert( self );

    if( size > self->capacity)
    {
        vector_reserve( self, size );
        self->size = self->capacity;
    }
    else
    {
        self->size = size;
    }
}


// -------------------------------------------------- vector_push_back_data ---
void
vector_push_back_data( vector_t *self,
                       const void * data,
                       const size_t count )
{
    assert( self );
    assert( data );
    assert( count );

    if( self->capacity < (self->size+count) )
    {
        vector_reserve(self, self->size+count);
    }
    memmove( (char *)(self->items) + self->size * self->item_size, data,
             count*self->item_size );
    self->size += count;
}


// ----------------------------------------------------- vector_insert_data ---
void
vector_insert_data( vector_t *self,
                    const size_t index,
                    const void * data,
                    const size_t count )
{
    assert( self );
    assert( index < self->size );
    assert( data );
    assert( count );

    if( self->capacity < (self->size+count) )
    {
        vector_reserve(self, self->size+count);
    }
    memmove( (char *)(self->items) + (index + count ) * self->item_size,
             (char *)(self->items) + (index ) * self->item_size,
             count*self->item_size );
    memmove( (char *)(self->items) + index * self->item_size, data,
             count*self->item_size );
    self->size += count;
}


// ------------------------------------------------------------ vector_sort ---
void
vector_sort( vector_t *self,
             int (*cmp)(const void *, const void *) )
{
    assert( self );
    assert( self->size );

    qsort(self->items, self->size, self->item_size, cmp);
}













#define HRES  64
#define HRESf 64.f
#define DPI   72

// ------------------------------------------------- texture_font_load_face ---
static int
texture_font_load_face(texture_font_t *self, float size,
        FT_Library *library, FT_Face *face)
{
    FT_Error error;
    FT_Matrix matrix = {
        (int)((1.0/HRES) * 0x10000L),
        (int)((0.0)      * 0x10000L),
        (int)((0.0)      * 0x10000L),
        (int)((1.0)      * 0x10000L)};

    assert(library);
    assert(size);

    /* Initialize library */
    error = FT_Init_FreeType(library);
    if(error) {
        fprintf(stderr, "FT_Error (0x%02x) : %s\n",
                FT_Errors[error].code, FT_Errors[error].message);
        goto cleanup;
    }

    /* Load face */
    switch (self->location) {
    case TEXTURE_FONT_FILE:
        error = FT_New_Face(*library, self->filename, 0, face);
        break;

    case TEXTURE_FONT_MEMORY:
        error = FT_New_Memory_Face(*library,
            self->memory.base, self->memory.size, 0, face);
        break;
    }

    if(error) {
        fprintf(stderr, "FT_Error (line %d, code 0x%02x) : %s\n",
                __LINE__, FT_Errors[error].code, FT_Errors[error].message);
        goto cleanup_library;
    }

    /* Select charmap */
    error = FT_Select_Charmap(*face, FT_ENCODING_UNICODE);
    if(error) {
        fprintf(stderr, "FT_Error (line %d, code 0x%02x) : %s\n",
                __LINE__, FT_Errors[error].code, FT_Errors[error].message);
        goto cleanup_face;
    }

    /* Set char size */
    error = FT_Set_Char_Size(*face, (int)(size * HRES), 0, DPI * HRES, DPI);

    if(error) {
        fprintf(stderr, "FT_Error (line %d, code 0x%02x) : %s\n",
                __LINE__, FT_Errors[error].code, FT_Errors[error].message);
        goto cleanup_face;
    }

    /* Set transform matrix */
    FT_Set_Transform(*face, &matrix, NULL);

    return 1;

cleanup_face:
    FT_Done_Face( *face );
cleanup_library:
    FT_Done_FreeType( *library );
cleanup:
    return 0;
}

// ------------------------------------------------------ texture_glyph_new ---
texture_glyph_t *
texture_glyph_new(void)
{
    texture_glyph_t *self = (texture_glyph_t *) malloc( sizeof(texture_glyph_t) );
    if(self == NULL) {
        fprintf( stderr,
                "line %d: No more memory for allocating data\n", __LINE__);
        return NULL;
    }

    self->codepoint  = -1;
    self->width     = 0;
    self->height    = 0;
    self->rendermode = RENDER_NORMAL;
    self->outline_thickness = 0.0;
    self->offset_x  = 0;
    self->offset_y  = 0;
    self->advance_x = 0.0;
    self->advance_y = 0.0;
    self->s0        = 0.0;
    self->t0        = 0.0;
    self->s1        = 0.0;
    self->t1        = 0.0;
    self->kerning   = vector_new( sizeof(kerning_t) );
    return self;
}


// --------------------------------------------------- texture_glyph_delete ---
void
texture_glyph_delete( texture_glyph_t *self )
{
    assert( self );
    vector_delete( self->kerning );
    free( self );
}

// ---------------------------------------------- texture_glyph_get_kerning ---
float
texture_glyph_get_kerning( const texture_glyph_t * self,
                           const char * codepoint )
{
    size_t i;
    uint32_t ucodepoint = utf8_to_utf32( codepoint );

    assert( self );
    for( i=0; i<vector_size(self->kerning); ++i )
    {
        kerning_t * kerning = (kerning_t *) vector_get( self->kerning, i );
        if( kerning->codepoint == ucodepoint )
        {
            return kerning->kerning;
        }
    }
    return 0;
}


// ------------------------------------------ texture_font_generate_kerning ---
void
texture_font_generate_kerning( texture_font_t *self,
                               FT_Library *library, FT_Face *face )
{
    size_t i, j;
    FT_UInt glyph_index, prev_index;
    texture_glyph_t *glyph, *prev_glyph;
    FT_Vector kerning;

    assert( self );

    /* For each glyph couple combination, check if kerning is necessary */
    /* Starts at index 1 since 0 is for the special backgroudn glyph */
    for( i=1; i<self->glyphs->size; ++i )
    {
        glyph = *(texture_glyph_t **) vector_get( self->glyphs, i );
        glyph_index = FT_Get_Char_Index( *face, glyph->codepoint );
        vector_clear( glyph->kerning );

        for( j=1; j<self->glyphs->size; ++j )
        {
            prev_glyph = *(texture_glyph_t **) vector_get( self->glyphs, j );
            prev_index = FT_Get_Char_Index( *face, prev_glyph->codepoint );
            FT_Get_Kerning( *face, prev_index, glyph_index, FT_KERNING_UNFITTED, &kerning );
            // printf("%c(%d)-%c(%d): %ld\n",
            //       prev_glyph->codepoint, prev_glyph->codepoint,
            //       glyph_index, glyph_index, kerning.x);
            if( kerning.x )
            {
                kerning_t k = {prev_glyph->codepoint, kerning.x / (float)(HRESf*HRESf)};
                vector_push_back( glyph->kerning, &k );
            }
        }
    }
}

// ------------------------------------------------------ texture_font_init ---
static int
texture_font_init(texture_font_t *self)
{
    FT_Library library;
    FT_Face face;
    FT_Size_Metrics metrics;

    assert(self->atlas);
    assert(self->size > 0);
    assert((self->location == TEXTURE_FONT_FILE && self->filename)
        || (self->location == TEXTURE_FONT_MEMORY
            && self->memory.base && self->memory.size));

    self->glyphs = vector_new(sizeof(texture_glyph_t *));
    self->height = 0;
    self->ascender = 0;
    self->descender = 0;
    self->rendermode = RENDER_NORMAL;
    self->outline_thickness = 0.0;
    self->hinting = 1;
    self->kerning = 1;
    self->filtering = 1;

    // FT_LCD_FILTER_LIGHT   is (0x00, 0x55, 0x56, 0x55, 0x00)
    // FT_LCD_FILTER_DEFAULT is (0x10, 0x40, 0x70, 0x40, 0x10)
    self->lcd_weights[0] = 0x10;
    self->lcd_weights[1] = 0x40;
    self->lcd_weights[2] = 0x70;
    self->lcd_weights[3] = 0x40;
    self->lcd_weights[4] = 0x10;

    if (!texture_font_load_face(self, self->size * 100.f, &library, &face))
        return -1;

    self->underline_position = face->underline_position / (float)(HRESf*HRESf) * self->size;
    self->underline_position = roundf( self->underline_position );
    if( self->underline_position > -2 )
    {
        self->underline_position = -2.0;
    }

    self->underline_thickness = face->underline_thickness / (float)(HRESf*HRESf) * self->size;
    self->underline_thickness = roundf( self->underline_thickness );
    if( self->underline_thickness < 1 )
    {
        self->underline_thickness = 1.0;
    }

    metrics = face->size->metrics;
    self->ascender = (metrics.ascender >> 6) / 100.0f;
    self->descender = (metrics.descender >> 6) / 100.0f;
    self->height = (metrics.height >> 6) / 100.0f;
    self->linegap = self->height - self->ascender + self->descender;
    FT_Done_Face( face );
    FT_Done_FreeType( library );

    /* NULL is a special glyph */
    texture_font_get_glyph( self, NULL );

    return 0;
}

// --------------------------------------------- texture_font_new_from_file ---
texture_font_t *
texture_font_new_from_file(texture_atlas_t *atlas, const float pt_size,
        const char *filename)
{
    texture_font_t *self;

    assert(filename);

    self = calloc(1, sizeof(*self));
    if (!self) {
        fprintf(stderr,
                "line %d: No more memory for allocating data\n", __LINE__);
        return NULL;
    }

    self->atlas = atlas;
    self->size  = pt_size;

    self->location = TEXTURE_FONT_FILE;
    self->filename = strdup(filename);

    if (texture_font_init(self)) {
        texture_font_delete(self);
        return NULL;
    }

    return self;
}

// ------------------------------------------- texture_font_new_from_memory ---
texture_font_t *
texture_font_new_from_memory(texture_atlas_t *atlas, float pt_size,
        const void *memory_base, size_t memory_size)
{
    texture_font_t *self;

    assert(memory_base);
    assert(memory_size);

    self = calloc(1, sizeof(*self));
    if (!self) {
        fprintf(stderr,
                "line %d: No more memory for allocating data\n", __LINE__);
        return NULL;
    }

    self->atlas = atlas;
    self->size  = pt_size;

    self->location = TEXTURE_FONT_MEMORY;
    self->memory.base = memory_base;
    self->memory.size = memory_size;

    if (texture_font_init(self)) {
        texture_font_delete(self);
        return NULL;
    }

    return self;
}

// ---------------------------------------------------- texture_font_delete ---
void
texture_font_delete( texture_font_t *self )
{
    size_t i;
    texture_glyph_t *glyph;

    assert( self );

    if(self->location == TEXTURE_FONT_FILE && self->filename)
        free( self->filename );

    for( i=0; i<vector_size( self->glyphs ); ++i)
    {
        glyph = *(texture_glyph_t **) vector_get( self->glyphs, i );
        texture_glyph_delete( glyph);
    }

    vector_delete( self->glyphs );
    free( self );
}

texture_glyph_t *
texture_font_find_glyph( texture_font_t * self,
                         const char * codepoint )
{
    size_t i;
    texture_glyph_t *glyph;
    uint32_t ucodepoint = utf8_to_utf32( codepoint );

    for( i = 0; i < self->glyphs->size; ++i )
    {
        glyph = *(texture_glyph_t **) vector_get( self->glyphs, i );
        // If codepoint is -1, we don't care about outline type or thickness
        if( (glyph->codepoint == ucodepoint) &&
            ((ucodepoint == -1) ||
             ((glyph->rendermode == self->rendermode) &&
              (glyph->outline_thickness == self->outline_thickness)) ))
        {
            return glyph;
        }
    }

    return NULL;
}

// ------------------------------------------------ texture_font_load_glyph ---
int
texture_font_load_glyph( texture_font_t * self,
                         const char * codepoint )
{
    size_t i, x, y;

    FT_Library library;
    FT_Error error;
    FT_Face face;
    FT_Glyph ft_glyph;
    FT_GlyphSlot slot;
    FT_Bitmap ft_bitmap;

    FT_UInt glyph_index;
    texture_glyph_t *glyph;
    FT_Int32 flags = 0;
    int ft_glyph_top = 0;
    int ft_glyph_left = 0;

    ivec4 region;
    size_t missed = 0;


    if (!texture_font_load_face(self, self->size, &library, &face))
        return 0;

    /* Check if codepoint has been already loaded */
    if (texture_font_find_glyph(self, codepoint)) {
        FT_Done_Face(face);
        FT_Done_FreeType(library);
        return 1;
    }

    /* codepoint NULL is special : it is used for line drawing (overline,
     * underline, strikethrough) and background.
     */
    if( !codepoint )
    {
        ivec4 region = texture_atlas_get_region( self->atlas, 5, 5 );
        texture_glyph_t * glyph = texture_glyph_new( );
        static unsigned char data[4*4*3] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
                                            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
                                            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
                                            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        if ( region.x < 0 )
        {
            fprintf( stderr, "Texture atlas is full (line %d)\n",  __LINE__ );
            FT_Done_Face( face );
            FT_Done_FreeType( library );
            return 0;
        }
        texture_atlas_set_region( self->atlas, region.x, region.y, 4, 4, data, 0 );
        glyph->codepoint = -1;
        glyph->s0 = (region.x+2)/(float)self->atlas->width;
        glyph->t0 = (region.y+2)/(float)self->atlas->height;
        glyph->s1 = (region.x+3)/(float)self->atlas->width;
        glyph->t1 = (region.y+3)/(float)self->atlas->height;
        vector_push_back( self->glyphs, &glyph );

        FT_Done_Face(face);
        FT_Done_FreeType(library);
        return 1;
    }

    flags = 0;
    ft_glyph_top = 0;
    ft_glyph_left = 0;
    glyph_index = FT_Get_Char_Index( face, (FT_ULong)utf8_to_utf32( codepoint ) );
    // WARNING: We use texture-atlas depth to guess if user wants
    //          LCD subpixel rendering

    if( self->rendermode != RENDER_NORMAL && self->rendermode != RENDER_SIGNED_DISTANCE_FIELD )
    {
        flags |= FT_LOAD_NO_BITMAP;
    }
    else
    {
        flags |= FT_LOAD_RENDER;
    }

    if( !self->hinting )
    {
        flags |= FT_LOAD_NO_HINTING | FT_LOAD_NO_AUTOHINT;
    }
    else
    {
        flags |= FT_LOAD_FORCE_AUTOHINT;
    }

    if( self->atlas->depth == 3 )
    {
        FT_Library_SetLcdFilter( library, FT_LCD_FILTER_LIGHT );
        flags |= FT_LOAD_TARGET_LCD;

        if( self->filtering )
        {
            FT_Library_SetLcdFilterWeights( library, self->lcd_weights );
        }
    }

    error = FT_Load_Glyph( face, glyph_index, flags );
    if( error )
    {
        fprintf( stderr, "FT_Error (line %d, code 0x%02x) : %s\n",
                 __LINE__, FT_Errors[error].code, FT_Errors[error].message );
        FT_Done_Face( face );
        FT_Done_FreeType( library );
        return 0;
    }

    if( self->rendermode == RENDER_NORMAL || self->rendermode == RENDER_SIGNED_DISTANCE_FIELD )
    {
        slot            = face->glyph;
        ft_bitmap       = slot->bitmap;
        ft_glyph_top    = slot->bitmap_top;
        ft_glyph_left   = slot->bitmap_left;
    }
    else
    {
        FT_Stroker stroker;
        FT_BitmapGlyph ft_bitmap_glyph;

        error = FT_Stroker_New( library, &stroker );

        if( error )
        {
            fprintf(stderr, "FT_Error (0x%02x) : %s\n",
                    FT_Errors[error].code, FT_Errors[error].message);
            goto cleanup_stroker;
        }

        FT_Stroker_Set(stroker,
                        (int)(self->outline_thickness * HRES),
                        FT_STROKER_LINECAP_ROUND,
                        FT_STROKER_LINEJOIN_ROUND,
                        0);

        error = FT_Get_Glyph( face->glyph, &ft_glyph);

        if( error )
        {
            fprintf(stderr, "FT_Error (0x%02x) : %s\n",
                    FT_Errors[error].code, FT_Errors[error].message);
            goto cleanup_stroker;
        }

        if( self->rendermode == RENDER_OUTLINE_EDGE )
            error = FT_Glyph_Stroke( &ft_glyph, stroker, 1 );
        else if ( self->rendermode == RENDER_OUTLINE_POSITIVE )
            error = FT_Glyph_StrokeBorder( &ft_glyph, stroker, 0, 1 );
        else if ( self->rendermode == RENDER_OUTLINE_NEGATIVE )
            error = FT_Glyph_StrokeBorder( &ft_glyph, stroker, 1, 1 );

        if( error )
        {
            fprintf(stderr, "FT_Error (0x%02x) : %s\n",
                    FT_Errors[error].code, FT_Errors[error].message);
            goto cleanup_stroker;
        }

        if( self->atlas->depth == 1 )
            error = FT_Glyph_To_Bitmap( &ft_glyph, FT_RENDER_MODE_NORMAL, 0, 1);
        else
            error = FT_Glyph_To_Bitmap( &ft_glyph, FT_RENDER_MODE_LCD, 0, 1);

        if( error )
        {
            fprintf(stderr, "FT_Error (0x%02x) : %s\n",
                    FT_Errors[error].code, FT_Errors[error].message);
            goto cleanup_stroker;
        }

        ft_bitmap_glyph = (FT_BitmapGlyph) ft_glyph;
        ft_bitmap       = ft_bitmap_glyph->bitmap;
        ft_glyph_top    = ft_bitmap_glyph->top;
        ft_glyph_left   = ft_bitmap_glyph->left;

cleanup_stroker:
        FT_Stroker_Done( stroker );

        if( error )
        {
            FT_Done_Face( face );
            FT_Done_FreeType( library );
            return 0;
        }
    }

    struct {
        int left;
        int top;
        int right;
        int bottom;
    } padding = { 0, 0, 1, 1 };

    if( self->rendermode == RENDER_SIGNED_DISTANCE_FIELD )
    {
        padding.top = 1;
        padding.left = 1;
    }

    size_t src_w = ft_bitmap.width/self->atlas->depth;
    size_t src_h = ft_bitmap.rows;

    size_t tgt_w = src_w + padding.left + padding.right;
    size_t tgt_h = src_h + padding.top + padding.bottom;

    region = texture_atlas_get_region( self->atlas, tgt_w, tgt_h );

    if ( region.x < 0 )
    {
        fprintf( stderr, "Texture atlas is full (line %d)\n",  __LINE__ );
        FT_Done_Face( face );
        FT_Done_FreeType( library );
        return 0;
    }

    x = region.x;
    y = region.y;

    unsigned char *buffer = calloc( tgt_w * tgt_h * self->atlas->depth, sizeof(unsigned char) );

    unsigned char *dst_ptr = buffer + (padding.top * tgt_w + padding.left) * self->atlas->depth;
    unsigned char *src_ptr = ft_bitmap.buffer;
    for( i = 0; i < src_h; i++ )
    {
        //difference between width and pitch: https://www.freetype.org/freetype2/docs/reference/ft2-basic_types.html
        memcpy( dst_ptr, src_ptr, ft_bitmap.width);
        dst_ptr += tgt_w * self->atlas->depth;
        src_ptr += ft_bitmap.pitch;
    }

    if( self->rendermode == RENDER_SIGNED_DISTANCE_FIELD )
    {
        unsigned char *sdf = make_distance_mapb( buffer, tgt_w, tgt_h );
        free( buffer );
        buffer = sdf;
    }

    texture_atlas_set_region( self->atlas, x, y, tgt_w, tgt_h, buffer, tgt_w * self->atlas->depth);

    free( buffer );

    glyph = texture_glyph_new( );
    glyph->codepoint = utf8_to_utf32( codepoint );
    glyph->width    = tgt_w;
    glyph->height   = tgt_h;
    glyph->rendermode = self->rendermode;
    glyph->outline_thickness = self->outline_thickness;
    glyph->offset_x = ft_glyph_left;
    glyph->offset_y = ft_glyph_top;
    glyph->s0       = x/(float)self->atlas->width;
    glyph->t0       = y/(float)self->atlas->height;
    glyph->s1       = (x + glyph->width)/(float)self->atlas->width;
    glyph->t1       = (y + glyph->height)/(float)self->atlas->height;

    // Discard hinting to get advance
    FT_Load_Glyph( face, glyph_index, FT_LOAD_RENDER | FT_LOAD_NO_HINTING);
    slot = face->glyph;
    glyph->advance_x = slot->advance.x / HRESf;
    glyph->advance_y = slot->advance.y / HRESf;

    vector_push_back( self->glyphs, &glyph );

    if( self->rendermode != RENDER_NORMAL && self->rendermode != RENDER_SIGNED_DISTANCE_FIELD )
        FT_Done_Glyph( ft_glyph );

    texture_font_generate_kerning( self, &library, &face );

    FT_Done_Face( face );
    FT_Done_FreeType( library );

    return 1;
}

// ----------------------------------------------- texture_font_load_glyphs ---
size_t
texture_font_load_glyphs( texture_font_t * self,
                          const char * codepoints )
{
    size_t i;

    /* Load each glyph */
    for( i = 0; i < strlen(codepoints); i += utf8_surrogate_len(codepoints + i) ) {
        if( !texture_font_load_glyph( self, codepoints + i ) )
            return utf8_strlen( codepoints + i );
    }

    return 0;
}


// ------------------------------------------------- texture_font_get_glyph ---
texture_glyph_t *
texture_font_get_glyph( texture_font_t * self,
                        const char * codepoint )
{
    texture_glyph_t *glyph;

    assert( self );
    assert( self->filename );
    assert( self->atlas );

    /* Check if codepoint has been already loaded */
    if( (glyph = texture_font_find_glyph( self, codepoint )) )
        return glyph;

    /* Glyph has not been already loaded */
    if( texture_font_load_glyph( self, codepoint ) )
        return texture_font_find_glyph( self, codepoint );

    return NULL;
}

// ------------------------------------------------- texture_font_enlarge_atlas ---
void
texture_font_enlarge_atlas( texture_font_t * self, size_t width_new,
			    size_t height_new)
{
    assert(self);
    assert(self->atlas);
    //ensure size increased
    assert(width_new >= self->atlas->width);
    assert(height_new >= self->atlas->height);
    assert(width_new + height_new > self->atlas->width + self->atlas->height);
    texture_atlas_t* ta = self->atlas;
    size_t width_old = ta->width;
    size_t height_old = ta->height;
    //allocate new buffer
    unsigned char* data_old = ta->data;
    ta->data = calloc(1,width_new*height_new * sizeof(char)*ta->depth);
    //update atlas size
    ta->width = width_new;
    ta->height = height_new;
    //add node reflecting the gained space on the right
    if(width_new>width_old){
    	ivec3 node;
        node.x = width_old - 1;
        node.y = 1;
        node.z = width_new - width_old;
        vector_push_back(ta->nodes, &node);
    }
    //copy over data from the old buffer, skipping first row and column because of the margin
    size_t pixel_size = sizeof(char) * ta->depth;
    size_t old_row_size = width_old * pixel_size;
    texture_atlas_set_region(ta, 1, 1, width_old - 2, height_old - 2, data_old + old_row_size + pixel_size, old_row_size);
    free(data_old);
    //change uv coordinates of existing glyphs to reflect size change
    float mulw = (float)width_old / width_new;
    float mulh = (float)height_old / height_new;
    size_t i;
    for (i = 0; i < vector_size(self->glyphs); i++) {
    	texture_glyph_t* g = *(texture_glyph_t**)vector_get(self->glyphs, i);
    	g->s0 *= mulw;
    	g->s1 *= mulw;
    	g->t0 *= mulh;
    	g->t1 *= mulh;
    }
}









// ------------------------------------------------------ texture_atlas_new ---
texture_atlas_t *
texture_atlas_new( const size_t width,
                   const size_t height,
                   const size_t depth )
{
    texture_atlas_t *self = (texture_atlas_t *) malloc( sizeof(texture_atlas_t) );

    // We want a one pixel border around the whole atlas to avoid any artefact when
    // sampling texture
    ivec3 node = {{1,1,width-2}};

    assert( (depth == 1) || (depth == 3) || (depth == 4) );
    if( self == NULL)
    {
        fprintf( stderr,
                 "line %d: No more memory for allocating data\n", __LINE__ );
        exit( EXIT_FAILURE );
    }
    self->nodes = vector_new( sizeof(ivec3) );
    self->used = 0;
    self->width = width;
    self->height = height;
    self->depth = depth;
    self->id = 0;

    vector_push_back( self->nodes, &node );
    self->data = (unsigned char *)
        calloc( width*height*depth, sizeof(unsigned char) );

    if( self->data == NULL)
    {
        fprintf( stderr,
                 "line %d: No more memory for allocating data\n", __LINE__ );
        exit( EXIT_FAILURE );
    }

    return self;
}


// --------------------------------------------------- texture_atlas_delete ---
void
texture_atlas_delete( texture_atlas_t *self )
{
    assert( self );
    vector_delete( self->nodes );
    if( self->data )
    {
        free( self->data );
    }
    free( self );
}


// ----------------------------------------------- texture_atlas_set_region ---
void
texture_atlas_set_region( texture_atlas_t * self,
                          const size_t x,
                          const size_t y,
                          const size_t width,
                          const size_t height,
                          const unsigned char * data,
                          const size_t stride )
{
    size_t i;
    size_t depth;
    size_t charsize;

    assert( self );
    assert( x > 0);
    assert( y > 0);
    assert( x < (self->width-1));
    assert( (x + width) <= (self->width-1));
    assert( y < (self->height-1));
    assert( (y + height) <= (self->height-1));
	
    //prevent copying data from undefined position 
    //and prevent memcpy's undefined behavior when count is zero
    assert(height == 0 || (data != NULL && width > 0));

    depth = self->depth;
    charsize = sizeof(char);
    for( i=0; i<height; ++i )
    {
        memcpy( self->data+((y+i)*self->width + x ) * charsize * depth,
                data + (i*stride) * charsize, width * charsize * depth  );
    }
}


// ------------------------------------------------------ texture_atlas_fit ---
int
texture_atlas_fit( texture_atlas_t * self,
                   const size_t index,
                   const size_t width,
                   const size_t height )
{
    ivec3 *node;
    int x, y, width_left;
	size_t i;

    assert( self );

    node = (ivec3 *) (vector_get( self->nodes, index ));
    x = node->x;
	y = node->y;
    width_left = width;
	i = index;

	if ( (x + width) > (self->width-1) )
    {
		return -1;
    }
	y = node->y;
	while( width_left > 0 )
	{
        node = (ivec3 *) (vector_get( self->nodes, i ));
        if( node->y > y )
        {
            y = node->y;
        }
		if( (y + height) > (self->height-1) )
        {
			return -1;
        }
		width_left -= node->z;
		++i;
	}
	return y;
}


// ---------------------------------------------------- texture_atlas_merge ---
void
texture_atlas_merge( texture_atlas_t * self )
{
    ivec3 *node, *next;
    size_t i;

    assert( self );

	for( i=0; i< self->nodes->size-1; ++i )
    {
        node = (ivec3 *) (vector_get( self->nodes, i ));
        next = (ivec3 *) (vector_get( self->nodes, i+1 ));
		if( node->y == next->y )
		{
			node->z += next->z;
            vector_erase( self->nodes, i+1 );
			--i;
		}
    }
}


// ----------------------------------------------- texture_atlas_get_region ---
ivec4
texture_atlas_get_region( texture_atlas_t * self,
                          const size_t width,
                          const size_t height )
{
	int y, best_index;
    size_t best_height, best_width;
    ivec3 *node, *prev;
    ivec4 region = {{0,0,width,height}};
    size_t i;

    assert( self );

    best_height = UINT_MAX;
    best_index  = -1;
    best_width = UINT_MAX;
	for( i=0; i<self->nodes->size; ++i )
	{
        y = texture_atlas_fit( self, i, width, height );
		if( y >= 0 )
		{
            node = (ivec3 *) vector_get( self->nodes, i );
			if( ( (y + height) < best_height ) ||
                ( ((y + height) == best_height) && (node->z > 0 && (size_t)node->z < best_width)) )
			{
				best_height = y + height;
				best_index = i;
				best_width = node->z;
				region.x = node->x;
				region.y = y;
			}
        }
    }

	if( best_index == -1 )
    {
        region.x = -1;
        region.y = -1;
        region.width = 0;
        region.height = 0;
        return region;
    }

    node = (ivec3 *) malloc( sizeof(ivec3) );
    if( node == NULL)
    {
        fprintf( stderr,
                 "line %d: No more memory for allocating data\n", __LINE__ );
        exit( EXIT_FAILURE );
    }
    node->x = region.x;
    node->y = region.y + height;
    node->z = width;
    vector_insert( self->nodes, best_index, node );
    free( node );

    for(i = best_index+1; i < self->nodes->size; ++i)
    {
        node = (ivec3 *) vector_get( self->nodes, i );
        prev = (ivec3 *) vector_get( self->nodes, i-1 );

        if (node->x < (prev->x + prev->z) )
        {
            int shrink = prev->x + prev->z - node->x;
            node->x += shrink;
            node->z -= shrink;
            if (node->z <= 0)
            {
                vector_erase( self->nodes, i );
                --i;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    texture_atlas_merge( self );
    self->used += width * height;
    return region;
}


// ---------------------------------------------------- texture_atlas_clear ---
void
texture_atlas_clear( texture_atlas_t * self )
{
    ivec3 node = {{1,1,1}};

    assert( self );
    assert( self->data );

    vector_clear( self->nodes );
    self->used = 0;
    // We want a one pixel border around the whole atlas to avoid any artefact when
    // sampling texture
    node.z = self->width-2;

    vector_push_back( self->nodes, &node );
    memset( self->data, 0, self->width*self->height*self->depth );
}







// ------------------------------------------------------------ shader_read ---
char *
shader_read( const char *filename )
{
    FILE * file;
    char * buffer;
	size_t size;

#ifdef WIN32
    errno_t err;
    if( (err  = fopen_s( &file, filename, "rb" )) !=0 ) {
#else
    file = fopen( filename, "rb" );
    if( !file ) {
#endif
        fprintf( stderr, "Unable to open file \"%s\".\n", filename );
		return 0;
    }
	fseek( file, 0, SEEK_END );
	size = ftell( file );
	fseek(file, 0, SEEK_SET );
    buffer = (char *) malloc( (size+1) * sizeof( char *) );
	fread( buffer, sizeof(char), size, file );
    buffer[size] = 0;
    fclose( file );
    return buffer;
}



// --------------------------------------------------------- shader_compile ---
GLuint
shader_compile( const char* source,
                const GLenum type )
{
    GLint compile_status;
    GLuint handle = glCreateShader( type );
    glShaderSource( handle, 1, &source, 0 );
    glCompileShader( handle );

    glGetShaderiv( handle, GL_COMPILE_STATUS, &compile_status );
    if( compile_status == GL_FALSE )
    {
        GLchar messages[256];
        glGetShaderInfoLog( handle, sizeof(messages), 0, &messages[0] );
        fprintf( stderr, "%s: %s\n", source, messages );
        exit( EXIT_FAILURE );
    }
    return handle;
}


// ------------------------------------------------------------ shader_load ---
GLuint
shader_load( const char * vert_filename,
              const char * frag_filename )
{
    GLuint handle = glCreateProgram( );
    GLint link_status;

    if( vert_filename && strlen( vert_filename ) )
    {
        char *vert_source = shader_read( vert_filename );
        GLuint vert_shader = shader_compile( vert_source, GL_VERTEX_SHADER);
        glAttachShader( handle, vert_shader);
        glDeleteShader( vert_shader );
        free( vert_source );
    }
    if( frag_filename && strlen( frag_filename ) )
    {
        char *frag_source = shader_read( frag_filename );
        GLuint frag_shader = shader_compile( frag_source, GL_FRAGMENT_SHADER);
        glAttachShader( handle, frag_shader);
        glDeleteShader( frag_shader );
        free( frag_source );
    }

    glLinkProgram( handle );

    glGetProgramiv( handle, GL_LINK_STATUS, &link_status );
    if (link_status == GL_FALSE)
    {
        GLchar messages[256];
        glGetProgramInfoLog( handle, sizeof(messages), 0, &messages[0] );
        fprintf( stderr, "%s\n", messages );
        exit(1);
    }
    return handle;
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
    int32_t sjt_cast14;
    int32_t sjt_math83;
    int32_t sjt_math84;
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
    sjt_math83 = sjv_count;
    sjt_math84 = 1;
    _return->data.size = sjt_math83 + sjt_math84;
    _return->data.data = sjv_data;
    _return->data._isGlobal = false;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_anon4_i32toString_heap(sjs_anon4* _parent, int32_t val, int32_t base, int32_t minLength, sjs_string_heap** _return) {
    int32_t sjt_cast15;
    int32_t sjt_math85;
    int32_t sjt_math86;
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
    sjt_math85 = sjv_count;
    sjt_math86 = 1;
    (*_return)->data.size = sjt_math85 + sjt_math86;
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

void sjf_anon6_green(sjs_anon6* _parent, sjs_color* _return) {
    _return->r = 0;
    _return->g = 255;
    _return->b = 0;
    _return->a = 255;
    sjf_color(_return);
}

void sjf_anon6_green_heap(sjs_anon6* _parent, sjs_color_heap** _return) {
    (*_return) = (sjs_color_heap*)malloc(sizeof(sjs_color_heap));
    (*_return)->_refCount = 1;
    (*_return)->r = 0;
    (*_return)->g = 255;
    (*_return)->b = 0;
    (*_return)->a = 255;
    sjf_color_heap((*_return));
}

void sjf_anon6_heap(sjs_anon6_heap* _this) {
}

void sjf_anon6_red(sjs_anon6* _parent, sjs_color* _return) {
    _return->r = 255;
    _return->g = 0;
    _return->b = 0;
    _return->a = 255;
    sjf_color(_return);
}

void sjf_anon6_red_heap(sjs_anon6* _parent, sjs_color_heap** _return) {
    (*_return) = (sjs_color_heap*)malloc(sizeof(sjs_color_heap));
    (*_return)->_refCount = 1;
    (*_return)->r = 255;
    (*_return)->g = 0;
    (*_return)->b = 0;
    (*_return)->a = 255;
    sjf_color_heap((*_return));
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
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_borderChild_getRect;
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

void sjf_borderChild_getRect(sjs_borderChild* _parent, sjs_rect** _return) {
    (*_return) = &(_parent)->rect;
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
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_borderChild_getRect;
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
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_borderLayout_getRect;
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

void sjf_borderLayout_getRect(sjs_borderLayout* _parent, sjs_rect** _return) {
    (*_return) = &(_parent)->rect;
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
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_borderLayout_getRect;
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

void sjf_boxElement(sjs_boxElement* _this) {
}

sjs_object* sjf_boxElement_asInterface(sjs_boxElement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_boxElement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_boxElement_as_sji_element(sjs_boxElement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_boxElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_boxElement_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_boxElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_boxElement_getSize_heap;
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_boxElement_getRect;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_boxElement_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_boxElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_boxElement_getChildren;

    return _interface;
}

void sjf_boxElement_copy(sjs_boxElement* _this, sjs_boxElement* to) {
    sjf_color_copy(&_this->color, &to->color);
    sjf_size_copy(&_this->idealSize, &to->idealSize);
    sjf_rect_copy(&_this->rect, &to->rect);
}

void sjf_boxElement_destroy(sjs_boxElement* _this) {
}

void sjf_boxElement_getChildren(sjs_boxElement* _parent, sjs_array_heap_element** _return) {
    (*_return) = 0;
}

void sjf_boxElement_getRect(sjs_boxElement* _parent, sjs_rect** _return) {
    (*_return) = &(_parent)->rect;
}

void sjf_boxElement_getSize(sjs_boxElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size* sjt_dot166;
    sjs_size* sjt_functionParam35;

    sjt_dot166 = &(_parent)->idealSize;
    sjt_functionParam35 = maxSize;
    sjf_size_cap(sjt_dot166, sjt_functionParam35, _return);
}

void sjf_boxElement_getSize_heap(sjs_boxElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size* sjt_dot167;
    sjs_size* sjt_functionParam36;

    sjt_dot167 = &(_parent)->idealSize;
    sjt_functionParam36 = maxSize;
    sjf_size_cap_heap(sjt_dot167, sjt_functionParam36, _return);
}

void sjf_boxElement_heap(sjs_boxElement_heap* _this) {
}

sjs_object* sjf_boxElement_heap_asInterface(sjs_boxElement_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_boxElement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_boxElement_heap_as_sji_element(sjs_boxElement_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_boxElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_boxElement_heap_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_boxElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_boxElement_getSize_heap;
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_boxElement_getRect;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_boxElement_setRect;
    _interface->render = (void(*)(void*,sji_surface*))sjf_boxElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_boxElement_getChildren;

    return _interface;
}

void sjf_boxElement_render(sjs_boxElement* _parent, sji_surface* surface) {
    sji_surface* sjt_dot168;
    sjs_rect* sjt_interfaceParam31;
    sjs_color* sjt_interfaceParam32;

    sjt_dot168 = surface;
    sjt_interfaceParam31 = &(_parent)->rect;
    sjt_interfaceParam32 = &(_parent)->color;
    sjt_dot168->drawRect((void*)(((char*)sjt_dot168->_parent) + sizeof(intptr_t)), sjt_interfaceParam31, sjt_interfaceParam32);
}

void sjf_boxElement_setRect(sjs_boxElement* _parent, sjs_rect* rect_) {
    sjf_rect_copy(&_parent->rect, rect_);
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
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_buttonElement_getRect;
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
    sjf_margin_copy(&_this->margin, &to->margin);
}

void sjf_buttonElement_destroy(sjs_buttonElement* _this) {
}

void sjf_buttonElement_getChildren(sjs_buttonElement* _parent, sjs_array_heap_element** _return) {
    (*_return) = 0;
}

void sjf_buttonElement_getRect(sjs_buttonElement* _parent, sjs_rect** _return) {
    (*_return) = &(_parent)->rect;
}

void sjf_buttonElement_getSize(sjs_buttonElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size sjt_call6;
    sji_surface* sjt_dot88;
    sjs_size* sjt_dot89;
    sjs_size* sjt_dot90;
    sjs_margin* sjt_functionParam8;
    sjs_size* sjt_functionParam9;
    sjs_font* sjt_interfaceParam12;
    sjs_string* sjt_interfaceParam13;
    sjs_size sjv_textSize;

    sjt_dot88 = sjv_rootSurface;
    sjt_interfaceParam12 = &(_parent)->font;
    sjt_interfaceParam13 = &(_parent)->text;
    sjt_dot88->getTextSize((void*)(((char*)sjt_dot88->_parent) + sizeof(intptr_t)), sjt_interfaceParam12, sjt_interfaceParam13, &sjv_textSize);
    sjt_dot90 = &sjv_textSize;
    sjt_functionParam8 = &(_parent)->margin;
    sjf_size_addMargin(sjt_dot90, sjt_functionParam8, &sjt_call6);
    sjt_dot89 = &sjt_call6;
    sjt_functionParam9 = maxSize;
    sjf_size_cap(sjt_dot89, sjt_functionParam9, _return);

    sjf_size_destroy(&sjt_call6);
    sjf_size_destroy(&sjv_textSize);
}

void sjf_buttonElement_getSize_heap(sjs_buttonElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size sjt_call7;
    sji_surface* sjt_dot103;
    sjs_size* sjt_dot104;
    sjs_size* sjt_dot105;
    sjs_margin* sjt_functionParam10;
    sjs_size* sjt_functionParam11;
    sjs_font* sjt_interfaceParam14;
    sjs_string* sjt_interfaceParam15;
    sjs_size sjv_textSize;

    sjt_dot103 = sjv_rootSurface;
    sjt_interfaceParam14 = &(_parent)->font;
    sjt_interfaceParam15 = &(_parent)->text;
    sjt_dot103->getTextSize((void*)(((char*)sjt_dot103->_parent) + sizeof(intptr_t)), sjt_interfaceParam14, sjt_interfaceParam15, &sjv_textSize);
    sjt_dot105 = &sjv_textSize;
    sjt_functionParam10 = &(_parent)->margin;
    sjf_size_addMargin(sjt_dot105, sjt_functionParam10, &sjt_call7);
    sjt_dot104 = &sjt_call7;
    sjt_functionParam11 = maxSize;
    sjf_size_cap_heap(sjt_dot104, sjt_functionParam11, _return);

    sjf_size_destroy(&sjt_call7);
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
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_buttonElement_getRect;
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
    sjs_string sjt_call12;
    sjs_anon1* sjt_dot154;
    sjs_anon5* sjt_dot155;
    sjs_string* sjt_functionParam30;

    sjt_dot154 = &sjv_console;
    sjt_call12.count = 25;
    sjt_call12.data.size = 26;
    sjt_call12.data.data = (uintptr_t)sjg_string17;
    sjt_call12.data._isGlobal = false;
    sjf_array_char(&sjt_call12.data);
    sjf_string(&sjt_call12);
    sjt_functionParam30 = &sjt_call12;
    sjf_anon1_write(sjt_dot154, sjt_functionParam30);
    sjt_dot155 = &sjv_buttonState;
    _parent->state = (sjt_dot155)->pressed;

    sjf_string_destroy(&sjt_call12);
}

void sjf_buttonElement_onMouseMove(sjs_buttonElement* _parent, sjs_point* point) {
    sjs_string sjt_call13;
    int32_t sjt_compare35;
    int32_t sjt_compare36;
    sjs_anon1* sjt_dot156;
    sjs_anon5* sjt_dot157;
    sjs_string* sjt_functionParam31;
    bool sjt_ifElse23;

    sjt_dot156 = &sjv_console;
    sjt_call13.count = 25;
    sjt_call13.data.size = 26;
    sjt_call13.data.data = (uintptr_t)sjg_string19;
    sjt_call13.data._isGlobal = false;
    sjf_array_char(&sjt_call13.data);
    sjf_string(&sjt_call13);
    sjt_functionParam31 = &sjt_call13;
    sjf_anon1_write(sjt_dot156, sjt_functionParam31);
    sjt_compare35 = (_parent)->state;
    sjt_dot157 = &sjv_buttonState;
    sjt_compare36 = (sjt_dot157)->normal;
    sjt_ifElse23 = sjt_compare35 == sjt_compare36;
    if (sjt_ifElse23) {
        sjs_anon5* sjt_dot158;

        sjt_dot158 = &sjv_buttonState;
        _parent->state = (sjt_dot158)->hot;
    } else {
    }

    sjf_string_destroy(&sjt_call13);
}

void sjf_buttonElement_onMouseUp(sjs_buttonElement* _parent, sjs_point* point) {
    sjs_string sjt_call10;
    sjs_string sjt_call11;
    sjs_string sjt_call8;
    sjs_string sjt_call9;
    sjs_anon1* sjt_dot135;
    sjs_string* sjt_dot136;
    sjs_string* sjt_dot137;
    sjs_string* sjt_dot138;
    sjs_anon4* sjt_dot149;
    sjs_point* sjt_dot150;
    sjs_anon4* sjt_dot151;
    sjs_point* sjt_dot152;
    sjs_anon5* sjt_dot153;
    sjs_string* sjt_functionParam13;
    sjs_string* sjt_functionParam21;
    int32_t sjt_functionParam22;
    int32_t sjt_functionParam23;
    int32_t sjt_functionParam24;
    sjs_string* sjt_functionParam25;
    sjs_string* sjt_functionParam26;
    int32_t sjt_functionParam27;
    int32_t sjt_functionParam28;
    int32_t sjt_functionParam29;

    sjt_dot135 = &sjv_console;
    sjt_call8.count = 24;
    sjt_call8.data.size = 25;
    sjt_call8.data.data = (uintptr_t)sjg_string13;
    sjt_call8.data._isGlobal = false;
    sjf_array_char(&sjt_call8.data);
    sjf_string(&sjt_call8);
    sjt_dot138 = &sjt_call8;
    sjt_dot149 = &sjv_convert;
    sjt_dot150 = point;
    sjt_functionParam22 = (sjt_dot150)->x;
    sjt_functionParam23 = 10;
    sjt_functionParam24 = 0;
    sjf_anon4_i32toString(sjt_dot149, sjt_functionParam22, sjt_functionParam23, sjt_functionParam24, &sjt_call9);
    sjt_functionParam21 = &sjt_call9;
    sjf_string_add(sjt_dot138, sjt_functionParam21, &sjt_dot137);
    sjt_call10.count = 2;
    sjt_call10.data.size = 3;
    sjt_call10.data.data = (uintptr_t)sjg_string14;
    sjt_call10.data._isGlobal = false;
    sjf_array_char(&sjt_call10.data);
    sjf_string(&sjt_call10);
    sjt_functionParam25 = &sjt_call10;
    sjf_string_add(sjt_dot137, sjt_functionParam25, &sjt_dot136);
    sjt_dot151 = &sjv_convert;
    sjt_dot152 = point;
    sjt_functionParam27 = (sjt_dot152)->y;
    sjt_functionParam28 = 10;
    sjt_functionParam29 = 0;
    sjf_anon4_i32toString(sjt_dot151, sjt_functionParam27, sjt_functionParam28, sjt_functionParam29, &sjt_call11);
    sjt_functionParam26 = &sjt_call11;
    sjf_string_add(sjt_dot136, sjt_functionParam26, &sjt_functionParam13);
    sjf_anon1_write(sjt_dot135, sjt_functionParam13);
    sjt_dot153 = &sjv_buttonState;
    _parent->state = (sjt_dot153)->normal;

    sjf_string_destroy(&sjt_call10);
    sjf_string_destroy(&sjt_call11);
    sjf_string_destroy(&sjt_call8);
    sjf_string_destroy(&sjt_call9);
}

void sjf_buttonElement_render(sjs_buttonElement* _parent, sji_surface* surface) {
    int32_t sjt_compare25;
    int32_t sjt_compare26;
    sjs_anon5* sjt_dot106;
    sji_surface* sjt_dot112;
    sjs_rect* sjt_dot113;
    sjs_rect* sjt_dot126;
    sjs_rect* sjt_dot127;
    sjs_size* sjt_dot128;
    sjs_rect* sjt_dot129;
    sjs_rect* sjt_dot130;
    sjs_size* sjt_dot131;
    sjs_size* sjt_dot132;
    sjs_size* sjt_dot133;
    sji_surface* sjt_dot134;
    sjs_margin* sjt_functionParam12;
    bool sjt_ifElse18;
    sjs_font* sjt_interfaceParam22;
    sjs_string* sjt_interfaceParam23;
    sjs_rect* sjt_interfaceParam24;
    sjs_font* sjt_interfaceParam25;
    sjs_string* sjt_interfaceParam26;
    sjs_color* sjt_interfaceParam27;
    int32_t sjt_math61;
    int32_t sjt_math62;
    int32_t sjt_math63;
    int32_t sjt_math64;
    int32_t sjt_math65;
    int32_t sjt_math66;
    int32_t sjt_math67;
    int32_t sjt_math68;
    int32_t sjt_math69;
    int32_t sjt_math70;
    int32_t sjt_math71;
    int32_t sjt_math72;
    sjs_rect sjv_innerRect;
    sjs_rect sjv_textRect;
    sjs_size sjv_textSize;

    sjt_compare25 = (_parent)->state;
    sjt_dot106 = &sjv_buttonState;
    sjt_compare26 = (sjt_dot106)->normal;
    sjt_ifElse18 = sjt_compare25 == sjt_compare26;
    if (sjt_ifElse18) {
        sji_surface* sjt_dot107;
        sjs_rect* sjt_interfaceParam16;
        sjs_image* sjt_interfaceParam17;

        sjt_dot107 = surface;
        sjt_interfaceParam16 = &(_parent)->rect;
        sjt_interfaceParam17 = &(_parent)->normalImage;
        sjt_dot107->drawImage((void*)(((char*)sjt_dot107->_parent) + sizeof(intptr_t)), sjt_interfaceParam16, sjt_interfaceParam17);
    } else {
        int32_t sjt_compare27;
        int32_t sjt_compare28;
        sjs_anon5* sjt_dot108;
        bool sjt_ifElse19;

        sjt_compare27 = (_parent)->state;
        sjt_dot108 = &sjv_buttonState;
        sjt_compare28 = (sjt_dot108)->hot;
        sjt_ifElse19 = sjt_compare27 == sjt_compare28;
        if (sjt_ifElse19) {
            sji_surface* sjt_dot109;
            sjs_rect* sjt_interfaceParam18;
            sjs_image* sjt_interfaceParam19;

            sjt_dot109 = surface;
            sjt_interfaceParam18 = &(_parent)->rect;
            sjt_interfaceParam19 = &(_parent)->hotImage;
            sjt_dot109->drawImage((void*)(((char*)sjt_dot109->_parent) + sizeof(intptr_t)), sjt_interfaceParam18, sjt_interfaceParam19);
        } else {
            int32_t sjt_compare29;
            int32_t sjt_compare30;
            sjs_anon5* sjt_dot110;
            bool sjt_ifElse20;

            sjt_compare29 = (_parent)->state;
            sjt_dot110 = &sjv_buttonState;
            sjt_compare30 = (sjt_dot110)->pressed;
            sjt_ifElse20 = sjt_compare29 == sjt_compare30;
            if (sjt_ifElse20) {
                sji_surface* sjt_dot111;
                sjs_rect* sjt_interfaceParam20;
                sjs_image* sjt_interfaceParam21;

                sjt_dot111 = surface;
                sjt_interfaceParam20 = &(_parent)->rect;
                sjt_interfaceParam21 = &(_parent)->pressedImage;
                sjt_dot111->drawImage((void*)(((char*)sjt_dot111->_parent) + sizeof(intptr_t)), sjt_interfaceParam20, sjt_interfaceParam21);
            }
        }
    }

    sjt_dot112 = surface;
    sjt_interfaceParam22 = &(_parent)->font;
    sjt_interfaceParam23 = &(_parent)->text;
    sjt_dot112->getTextSize((void*)(((char*)sjt_dot112->_parent) + sizeof(intptr_t)), sjt_interfaceParam22, sjt_interfaceParam23, &sjv_textSize);
    sjt_dot113 = &(_parent)->rect;
    sjt_functionParam12 = &(_parent)->margin;
    sjf_rect_subtractMargin(sjt_dot113, sjt_functionParam12, &sjv_innerRect);
    sjt_dot126 = &sjv_innerRect;
    sjt_math61 = (sjt_dot126)->x;
    sjt_dot127 = &sjv_innerRect;
    sjt_math65 = (sjt_dot127)->w;
    sjt_dot128 = &sjv_textSize;
    sjt_math66 = (sjt_dot128)->w;
    sjt_math63 = sjt_math65 - sjt_math66;
    sjt_math64 = 2;
    sjt_math62 = sjt_math63 / sjt_math64;
    sjv_textRect.x = sjt_math61 + sjt_math62;
    sjt_dot129 = &sjv_innerRect;
    sjt_math67 = (sjt_dot129)->y;
    sjt_dot130 = &sjv_innerRect;
    sjt_math71 = (sjt_dot130)->h;
    sjt_dot131 = &sjv_textSize;
    sjt_math72 = (sjt_dot131)->h;
    sjt_math69 = sjt_math71 - sjt_math72;
    sjt_math70 = 2;
    sjt_math68 = sjt_math69 / sjt_math70;
    sjv_textRect.y = sjt_math67 + sjt_math68;
    sjt_dot132 = &sjv_textSize;
    sjv_textRect.w = (sjt_dot132)->w;
    sjt_dot133 = &sjv_textSize;
    sjv_textRect.h = (sjt_dot133)->h;
    sjf_rect(&sjv_textRect);
    sjt_dot134 = surface;
    sjt_interfaceParam24 = &sjv_textRect;
    sjt_interfaceParam25 = &(_parent)->font;
    sjt_interfaceParam26 = &(_parent)->text;
    sjt_interfaceParam27 = &(_parent)->textColor;
    sjt_dot134->drawText((void*)(((char*)sjt_dot134->_parent) + sizeof(intptr_t)), sjt_interfaceParam24, sjt_interfaceParam25, sjt_interfaceParam26, sjt_interfaceParam27);

    sjf_rect_destroy(&sjv_innerRect);
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
    bool result4;
    sji_element* sjt_cast22;
    sjs_rect* sjt_dot189;
    sji_element* sjt_dot190;
    sji_element* sjt_dot192;
    sjs_point* sjt_functionParam45;
    bool sjt_ifElse29;
    bool sjt_ifElse31;
    sjs_array_heap_element* sjt_isEmpty11;
    bool sjt_not4;
    sjs_array_heap_element* sjv_children;
    sji_mouseHandler* sjv_mouseHandler;

    sjt_cast22 = element;
    sjt_cast22->_refCount++;
    sjv_mouseHandler = (sji_mouseHandler*)sjt_cast22->asInterface(sjt_cast22->_parent, sji_mouseHandler_typeId);
    sjt_dot190 = element;
    sjt_dot190->getRect((void*)(((char*)sjt_dot190->_parent) + sizeof(intptr_t)), &sjt_dot189);
    sjt_functionParam45 = point;
    sjf_rect_containsPoint(sjt_dot189, sjt_functionParam45, &sjt_ifElse29);
    if (sjt_ifElse29) {
        bool result3;
        bool sjt_ifElse30;
        sji_mouseHandler* sjt_isEmpty10;
        bool sjt_not3;

        sjt_isEmpty10 = sjv_mouseHandler;
        if (sjt_isEmpty10 != 0) {
            sjt_isEmpty10->_refCount++;
        }

        sjt_not3 = (sjt_isEmpty10 == 0);
        result3 = !sjt_not3;
        sjt_ifElse30 = result3;
        if (sjt_ifElse30) {
            sji_mouseHandler* sjt_dot191;
            sji_mouseHandler* sjt_getValue9;
            sjs_point* sjt_interfaceParam36;

            sjt_getValue9 = sjv_mouseHandler;
            if (sjt_getValue9 != 0) {
                sjt_getValue9->_refCount++;
            }

            sjt_dot191 = sjt_getValue9;
            sjt_interfaceParam36 = point;
            sjt_dot191->onMouseDown((void*)(((char*)sjt_dot191->_parent) + sizeof(intptr_t)), sjt_interfaceParam36);

            if (sjt_getValue9 != 0) {
                sjt_getValue9->_refCount--;
                if (sjt_getValue9->_refCount <= 0) {
                    sji_mouseHandler_destroy(sjt_getValue9);
                }
            }
        }

        if (sjt_isEmpty10 != 0) {
            sjt_isEmpty10->_refCount--;
            if (sjt_isEmpty10->_refCount <= 0) {
                sji_mouseHandler_destroy(sjt_isEmpty10);
            }
        }
    }

    sjt_dot192 = element;
    sjt_dot192->getChildren((void*)(((char*)sjt_dot192->_parent) + sizeof(intptr_t)), &sjv_children);
    sjt_isEmpty11 = sjv_children;
    sjt_not4 = (sjt_isEmpty11 == 0);
    result4 = !sjt_not4;
    sjt_ifElse31 = result4;
    if (sjt_ifElse31) {
        int32_t i;
        sjs_array_heap_element* sjt_dot193;
        int32_t sjt_forEnd6;
        int32_t sjt_forStart6;
        sjs_array_heap_element* sjt_getValue10;
        sjs_array_heap_element* sjv_c;

        sjt_getValue10 = sjv_children;
        if (sjt_getValue10 == 0) { exit(-1); };
        sjv_c = sjt_getValue10;
        sjt_forStart6 = 0;
        i = sjt_forStart6;
        sjt_dot193 = sjv_c;
        sjt_forEnd6 = (sjt_dot193)->size;
        while (i < sjt_forEnd6) {
            sjs_array_heap_element* sjt_dot194;
            sji_element* sjt_functionParam46;
            int32_t sjt_functionParam47;
            sjs_point* sjt_functionParam48;

            sjt_dot194 = sjv_c;
            sjt_functionParam47 = i;
            sjf_array_heap_element_getAt_heap(sjt_dot194, sjt_functionParam47, &sjt_functionParam46);
            sjt_functionParam48 = point;
            sjf_fireMouseDown(sjt_functionParam46, sjt_functionParam48);
            i++;

            sjt_functionParam46->_refCount--;
            if (sjt_functionParam46->_refCount <= 0) {
                sji_element_destroy(sjt_functionParam46);
            }
        }
    }

    sjt_cast22->_refCount--;
    if (sjt_cast22->_refCount <= 0) {
        sji_element_destroy(sjt_cast22);
    }
    if (sjv_mouseHandler != 0) {
        sjv_mouseHandler->_refCount--;
        if (sjv_mouseHandler->_refCount <= 0) {
            sji_mouseHandler_destroy(sjv_mouseHandler);
        }
    }
}

void sjf_fireMouseUp(sji_element* element, sjs_point* point) {
    bool result2;
    sji_element* sjt_cast21;
    sjs_rect* sjt_dot179;
    sji_element* sjt_dot180;
    sji_element* sjt_dot186;
    sjs_point* sjt_functionParam39;
    bool sjt_ifElse25;
    bool sjt_ifElse27;
    sjs_array_heap_element* sjt_isEmpty9;
    bool sjt_not2;
    sjs_array_heap_element* sjv_children;
    sji_mouseHandler* sjv_mouseHandler;

    sjt_cast21 = element;
    sjt_cast21->_refCount++;
    sjv_mouseHandler = (sji_mouseHandler*)sjt_cast21->asInterface(sjt_cast21->_parent, sji_mouseHandler_typeId);
    sjt_dot180 = element;
    sjt_dot180->getRect((void*)(((char*)sjt_dot180->_parent) + sizeof(intptr_t)), &sjt_dot179);
    sjt_functionParam39 = point;
    sjf_rect_containsPoint(sjt_dot179, sjt_functionParam39, &sjt_ifElse25);
    if (sjt_ifElse25) {
        bool result1;
        bool sjt_ifElse26;
        sji_mouseHandler* sjt_isEmpty8;
        bool sjt_not1;

        sjt_isEmpty8 = sjv_mouseHandler;
        if (sjt_isEmpty8 != 0) {
            sjt_isEmpty8->_refCount++;
        }

        sjt_not1 = (sjt_isEmpty8 == 0);
        result1 = !sjt_not1;
        sjt_ifElse26 = result1;
        if (sjt_ifElse26) {
            sji_mouseHandler* sjt_dot185;
            sji_mouseHandler* sjt_getValue7;
            sjs_point* sjt_interfaceParam35;

            sjt_getValue7 = sjv_mouseHandler;
            if (sjt_getValue7 != 0) {
                sjt_getValue7->_refCount++;
            }

            sjt_dot185 = sjt_getValue7;
            sjt_interfaceParam35 = point;
            sjt_dot185->onMouseUp((void*)(((char*)sjt_dot185->_parent) + sizeof(intptr_t)), sjt_interfaceParam35);

            if (sjt_getValue7 != 0) {
                sjt_getValue7->_refCount--;
                if (sjt_getValue7->_refCount <= 0) {
                    sji_mouseHandler_destroy(sjt_getValue7);
                }
            }
        }

        if (sjt_isEmpty8 != 0) {
            sjt_isEmpty8->_refCount--;
            if (sjt_isEmpty8->_refCount <= 0) {
                sji_mouseHandler_destroy(sjt_isEmpty8);
            }
        }
    }

    sjt_dot186 = element;
    sjt_dot186->getChildren((void*)(((char*)sjt_dot186->_parent) + sizeof(intptr_t)), &sjv_children);
    sjt_isEmpty9 = sjv_children;
    sjt_not2 = (sjt_isEmpty9 == 0);
    result2 = !sjt_not2;
    sjt_ifElse27 = result2;
    if (sjt_ifElse27) {
        int32_t i;
        sjs_array_heap_element* sjt_dot187;
        int32_t sjt_forEnd5;
        int32_t sjt_forStart5;
        sjs_array_heap_element* sjt_getValue8;
        sjs_array_heap_element* sjv_c;

        sjt_getValue8 = sjv_children;
        if (sjt_getValue8 == 0) { exit(-1); };
        sjv_c = sjt_getValue8;
        sjt_forStart5 = 0;
        i = sjt_forStart5;
        sjt_dot187 = sjv_c;
        sjt_forEnd5 = (sjt_dot187)->size;
        while (i < sjt_forEnd5) {
            sjs_array_heap_element* sjt_dot188;
            sji_element* sjt_functionParam40;
            int32_t sjt_functionParam41;
            sjs_point* sjt_functionParam42;

            sjt_dot188 = sjv_c;
            sjt_functionParam41 = i;
            sjf_array_heap_element_getAt_heap(sjt_dot188, sjt_functionParam41, &sjt_functionParam40);
            sjt_functionParam42 = point;
            sjf_fireMouseUp(sjt_functionParam40, sjt_functionParam42);
            i++;

            sjt_functionParam40->_refCount--;
            if (sjt_functionParam40->_refCount <= 0) {
                sji_element_destroy(sjt_functionParam40);
            }
        }
    }

    sjt_cast21->_refCount--;
    if (sjt_cast21->_refCount <= 0) {
        sji_element_destroy(sjt_cast21);
    }
    if (sjv_mouseHandler != 0) {
        sjv_mouseHandler->_refCount--;
        if (sjv_mouseHandler->_refCount <= 0) {
            sji_mouseHandler_destroy(sjv_mouseHandler);
        }
    }
}

void sjf_font(sjs_font* _this) {
}

void sjf_font_copy(sjs_font* _this, sjs_font* to) {
    sjf_string_copy(&_this->src, &to->src);
    _this->size = to->size;
    _this->data = to->data;
}

void sjf_font_destroy(sjs_font* _this) {
    
//	TTF_CloseFont((TTF_Font*)_this->data);	
;
}

void sjf_font_heap(sjs_font_heap* _this) {
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
    sjf_margin_copy(&_this->margin, &to->margin);
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
    sji_surface* sjt_dot172;
    sji_surface* sjt_dot173;
    sjs_size* sjt_dot174;
    sjs_size* sjt_dot175;
    sji_element* sjt_dot176;
    sji_element* sjt_dot177;
    sji_surface* sjt_dot178;
    bool sjt_ifElse24;
    bool sjt_ifElse28;
    sjs_rect* sjt_interfaceParam33;
    sji_surface* sjt_interfaceParam34;
    int32_t sjt_math91;
    int32_t sjt_math92;
    bool sjv_isMouseDown;
    bool sjv_isMouseUp;
    sjs_rect sjv_rect;
    sjs_size sjv_size;
    int32_t sjv_x;
    int32_t sjv_y;

    sjt_dot172 = sjv_rootSurface;
    sjt_dot172->clear((void*)(((char*)sjt_dot172->_parent) + sizeof(intptr_t)));
    sjt_dot173 = sjv_rootSurface;
    sjt_dot173->getSize((void*)(((char*)sjt_dot173->_parent) + sizeof(intptr_t)), &sjv_size);
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot174 = &sjv_size;
    sjv_rect.w = (sjt_dot174)->w;
    sjt_dot175 = &sjv_size;
    sjv_rect.h = (sjt_dot175)->h;
    sjf_rect(&sjv_rect);
    sjt_dot176 = sjv_root;
    sjt_interfaceParam33 = &sjv_rect;
    sjt_dot176->setRect((void*)(((char*)sjt_dot176->_parent) + sizeof(intptr_t)), sjt_interfaceParam33);
    sjt_dot177 = sjv_root;
    sjt_interfaceParam34 = sjv_rootSurface;
    sjt_interfaceParam34->_refCount++;
    sjt_dot177->render((void*)(((char*)sjt_dot177->_parent) + sizeof(intptr_t)), sjt_interfaceParam34);
    sjt_dot178 = sjv_rootSurface;
    sjt_dot178->present((void*)(((char*)sjt_dot178->_parent) + sizeof(intptr_t)));
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
        sjs_point sjt_call17;
        sji_element* sjt_functionParam43;
        sjs_point* sjt_functionParam44;

        sjt_functionParam43 = sjv_root;
        sjt_functionParam43->_refCount++;
        sjt_call17.x = sjv_x;
        sjt_call17.y = sjv_y;
        sjf_point(&sjt_call17);
        sjt_functionParam44 = &sjt_call17;
        sjf_fireMouseUp(sjt_functionParam43, sjt_functionParam44);

        sjt_functionParam43->_refCount--;
        if (sjt_functionParam43->_refCount <= 0) {
            sji_element_destroy(sjt_functionParam43);
        }
        sjf_point_destroy(&sjt_call17);
    }

    sjt_ifElse28 = sjv_isMouseDown;
    if (sjt_ifElse28) {
        sjs_point sjt_call18;
        sji_element* sjt_functionParam49;
        sjs_point* sjt_functionParam50;

        sjt_functionParam49 = sjv_root;
        sjt_functionParam49->_refCount++;
        sjt_call18.x = sjv_x;
        sjt_call18.y = sjv_y;
        sjf_point(&sjt_call18);
        sjt_functionParam50 = &sjt_call18;
        sjf_fireMouseDown(sjt_functionParam49, sjt_functionParam50);

        sjt_functionParam49->_refCount--;
        if (sjt_functionParam49->_refCount <= 0) {
            sji_element_destroy(sjt_functionParam49);
        }
        sjf_point_destroy(&sjt_call18);
    }

    sjt_math91 = sjv_frame;
    sjt_math92 = 1;
    sjv_frame = sjt_math91 + sjt_math92;

    sjt_interfaceParam34->_refCount--;
    if (sjt_interfaceParam34->_refCount <= 0) {
        sji_surface_destroy(sjt_interfaceParam34);
    }
    sjf_rect_destroy(&sjv_rect);
    sjf_size_destroy(&sjv_size);
}

void sjf_margin(sjs_margin* _this) {
}

void sjf_margin_copy(sjs_margin* _this, sjs_margin* to) {
    _this->l = to->l;
    _this->t = to->t;
    _this->r = to->r;
    _this->b = to->b;
}

void sjf_margin_destroy(sjs_margin* _this) {
}

void sjf_margin_heap(sjs_margin_heap* _this) {
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

void sjf_rect_containsPoint(sjs_rect* _parent, sjs_point* point, bool* _return) {
    bool sjt_and10;
    bool sjt_and5;
    bool sjt_and6;
    bool sjt_and7;
    bool sjt_and8;
    bool sjt_and9;
    int32_t sjt_compare37;
    int32_t sjt_compare38;
    int32_t sjt_compare39;
    int32_t sjt_compare40;
    int32_t sjt_compare41;
    int32_t sjt_compare42;
    int32_t sjt_compare43;
    int32_t sjt_compare44;
    sjs_point* sjt_dot181;
    sjs_point* sjt_dot182;
    sjs_point* sjt_dot183;
    sjs_point* sjt_dot184;
    int32_t sjt_math87;
    int32_t sjt_math88;
    int32_t sjt_math89;
    int32_t sjt_math90;

    sjt_compare37 = (_parent)->x;
    sjt_dot181 = point;
    sjt_compare38 = (sjt_dot181)->x;
    sjt_and5 = sjt_compare37 <= sjt_compare38;
    sjt_compare39 = (_parent)->y;
    sjt_dot182 = point;
    sjt_compare40 = (sjt_dot182)->x;
    sjt_and7 = sjt_compare39 <= sjt_compare40;
    sjt_dot183 = point;
    sjt_compare41 = (sjt_dot183)->x;
    sjt_math87 = (_parent)->x;
    sjt_math88 = (_parent)->w;
    sjt_compare42 = sjt_math87 + sjt_math88;
    sjt_and9 = sjt_compare41 < sjt_compare42;
    sjt_dot184 = point;
    sjt_compare43 = (sjt_dot184)->y;
    sjt_math89 = (_parent)->y;
    sjt_math90 = (_parent)->h;
    sjt_compare44 = sjt_math89 + sjt_math90;
    sjt_and10 = sjt_compare43 < sjt_compare44;
    sjt_and8 = sjt_and9 && sjt_and10;
    sjt_and6 = sjt_and7 && sjt_and8;
    (*_return) = sjt_and5 && sjt_and6;
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

void sjf_rect_subtractMargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    sjs_margin* sjt_dot114;
    sjs_margin* sjt_dot115;
    sjs_margin* sjt_dot116;
    sjs_margin* sjt_dot117;
    sjs_margin* sjt_dot118;
    sjs_margin* sjt_dot119;
    int32_t sjt_math37;
    int32_t sjt_math38;
    int32_t sjt_math39;
    int32_t sjt_math40;
    int32_t sjt_math41;
    int32_t sjt_math42;
    int32_t sjt_math43;
    int32_t sjt_math44;
    int32_t sjt_math45;
    int32_t sjt_math46;
    int32_t sjt_math47;
    int32_t sjt_math48;

    sjt_math37 = (_parent)->x;
    sjt_dot114 = margin;
    sjt_math38 = (sjt_dot114)->l;
    _return->x = sjt_math37 + sjt_math38;
    sjt_math39 = (_parent)->y;
    sjt_dot115 = margin;
    sjt_math40 = (sjt_dot115)->t;
    _return->y = sjt_math39 + sjt_math40;
    sjt_math43 = (_parent)->w;
    sjt_dot116 = margin;
    sjt_math44 = (sjt_dot116)->l;
    sjt_math41 = sjt_math43 - sjt_math44;
    sjt_dot117 = margin;
    sjt_math42 = (sjt_dot117)->r;
    _return->w = sjt_math41 - sjt_math42;
    sjt_math47 = (_parent)->h;
    sjt_dot118 = margin;
    sjt_math48 = (sjt_dot118)->t;
    sjt_math45 = sjt_math47 - sjt_math48;
    sjt_dot119 = margin;
    sjt_math46 = (sjt_dot119)->b;
    _return->h = sjt_math45 - sjt_math46;
    sjf_rect(_return);
}

void sjf_rect_subtractMargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect_heap** _return) {
    sjs_margin* sjt_dot120;
    sjs_margin* sjt_dot121;
    sjs_margin* sjt_dot122;
    sjs_margin* sjt_dot123;
    sjs_margin* sjt_dot124;
    sjs_margin* sjt_dot125;
    int32_t sjt_math49;
    int32_t sjt_math50;
    int32_t sjt_math51;
    int32_t sjt_math52;
    int32_t sjt_math53;
    int32_t sjt_math54;
    int32_t sjt_math55;
    int32_t sjt_math56;
    int32_t sjt_math57;
    int32_t sjt_math58;
    int32_t sjt_math59;
    int32_t sjt_math60;

    (*_return) = (sjs_rect_heap*)malloc(sizeof(sjs_rect_heap));
    (*_return)->_refCount = 1;
    sjt_math49 = (_parent)->x;
    sjt_dot120 = margin;
    sjt_math50 = (sjt_dot120)->l;
    (*_return)->x = sjt_math49 + sjt_math50;
    sjt_math51 = (_parent)->y;
    sjt_dot121 = margin;
    sjt_math52 = (sjt_dot121)->t;
    (*_return)->y = sjt_math51 + sjt_math52;
    sjt_math55 = (_parent)->w;
    sjt_dot122 = margin;
    sjt_math56 = (sjt_dot122)->l;
    sjt_math53 = sjt_math55 - sjt_math56;
    sjt_dot123 = margin;
    sjt_math54 = (sjt_dot123)->r;
    (*_return)->w = sjt_math53 - sjt_math54;
    sjt_math59 = (_parent)->h;
    sjt_dot124 = margin;
    sjt_math60 = (sjt_dot124)->t;
    sjt_math57 = sjt_math59 - sjt_math60;
    sjt_dot125 = margin;
    sjt_math58 = (sjt_dot125)->b;
    (*_return)->h = sjt_math57 - sjt_math58;
    sjf_rect_heap((*_return));
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

#ifdef __APPLE__
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	    _this->win = (uintptr_t)SDL_CreateWindow("Hello World!", 100, 100, _this->size.w, _this->size.h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	    if (_this->win == 0) {
	        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
	        exit(-1);
	    }

	    SDL_GL_CreateContext((SDL_Window*)_this->win);
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
    _interface->drawRect = (void(*)(void*,sjs_rect*,sjs_color*))sjf_sdlSurface_drawRect;
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
    
/*
		if (image->texture.tex) {
			if (image->margin.l > 0) {
				if (image->margin.t > 0) {
					SDL_Rect leftTopSrcRect;
					leftTopSrcRect.x = image->rect.x;
					leftTopSrcRect.y = image->rect.y;
					leftTopSrcRect.w = image->margin.l;
					leftTopSrcRect.h = image->margin.t;

					SDL_Rect leftTopDestRect;
					leftTopDestRect.x = rect->x;
					leftTopDestRect.y = rect->y;
					leftTopDestRect.w = image->margin.l;
					leftTopDestRect.h = image->margin.t;
					SDL_RenderCopy((SDL_Renderer*)_parent->ren, (SDL_Texture*)image->texture.tex, &leftTopSrcRect, &leftTopDestRect);
				}

				SDL_Rect leftSrcRect;
				leftSrcRect.x = image->rect.x;
				leftSrcRect.y = image->rect.y + image->margin.t;
				leftSrcRect.w = image->margin.l;
				leftSrcRect.h = image->rect.h - image->margin.t - image->margin.b;

				SDL_Rect leftDestRect;
				leftDestRect.x = rect->x;
				leftDestRect.y = rect->y + image->margin.t;
				leftDestRect.w = image->margin.l;
				leftDestRect.h = rect->h - image->margin.t - image->margin.b;
				SDL_RenderCopy((SDL_Renderer*)_parent->ren, (SDL_Texture*)image->texture.tex, &leftSrcRect, &leftDestRect);

				if (image->margin.b > 0) {
					SDL_Rect leftBottomSrcRect;
					leftBottomSrcRect.x = image->rect.x;
					leftBottomSrcRect.y = image->rect.y + image->rect.h - image->margin.b;
					leftBottomSrcRect.w = image->margin.l;
					leftBottomSrcRect.h = image->margin.b;

					SDL_Rect leftBottomDestRect;
					leftBottomDestRect.x = rect->x;
					leftBottomDestRect.y = rect->y + rect->h - image->margin.b;
					leftBottomDestRect.w = image->margin.l;
					leftBottomDestRect.h = image->margin.b;
					SDL_RenderCopy((SDL_Renderer*)_parent->ren, (SDL_Texture*)image->texture.tex, &leftBottomSrcRect, &leftBottomDestRect);
				}
			}

			if (image->margin.r > 0) {
				if (image->margin.t > 0) {
					SDL_Rect rightTopSrcRect;
					rightTopSrcRect.x = image->rect.x + image->rect.w - image->margin.r;
					rightTopSrcRect.y = image->rect.y;
					rightTopSrcRect.w = image->margin.r;
					rightTopSrcRect.h = image->margin.t;

					SDL_Rect rightTopDestRect;
					rightTopDestRect.x = rect->x + rect->w - image->margin.r;
					rightTopDestRect.y = rect->y;
					rightTopDestRect.w = image->margin.r;
					rightTopDestRect.h = image->margin.t;
					SDL_RenderCopy((SDL_Renderer*)_parent->ren, (SDL_Texture*)image->texture.tex, &rightTopSrcRect, &rightTopDestRect);
				}

				SDL_Rect rightSrcRect;
				rightSrcRect.x = image->rect.x + image->rect.w - image->margin.r;
				rightSrcRect.y = image->rect.y + image->margin.t;
				rightSrcRect.w = image->margin.r;
				rightSrcRect.h = image->rect.h - image->margin.t - image->margin.b;

				SDL_Rect rightDestRect;
				rightDestRect.x = rect->x + rect->w - image->margin.r;
				rightDestRect.y = rect->y + image->margin.t;
				rightDestRect.w = image->margin.r;
				rightDestRect.h = rect->h - image->margin.t - image->margin.b;
				SDL_RenderCopy((SDL_Renderer*)_parent->ren, (SDL_Texture*)image->texture.tex, &rightSrcRect, &rightDestRect);

				if (image->margin.b > 0) {
					SDL_Rect rightBottomSrcRect;
					rightBottomSrcRect.x = image->rect.x + image->rect.w - image->margin.r;
					rightBottomSrcRect.y = image->rect.y + image->rect.h - image->margin.b;
					rightBottomSrcRect.w = image->margin.r;
					rightBottomSrcRect.h = image->margin.b;

					SDL_Rect rightBottomDestRect;
					rightBottomDestRect.x = rect->x + rect->w - image->margin.r;
					rightBottomDestRect.y = rect->y + rect->h - image->margin.b;
					rightBottomDestRect.w = image->margin.r;
					rightBottomDestRect.h = image->margin.b;
					SDL_RenderCopy((SDL_Renderer*)_parent->ren, (SDL_Texture*)image->texture.tex, &rightBottomSrcRect, &rightBottomDestRect);
				}
			}

			if (image->margin.t > 0) {
				SDL_Rect middleTopSrcRect;
				middleTopSrcRect.x = image->rect.x + image->margin.l;
				middleTopSrcRect.y = image->rect.y;
				middleTopSrcRect.w = image->rect.w - image->margin.l - image->margin.r;
				middleTopSrcRect.h = image->margin.t;

				SDL_Rect middleTopDestRect;
				middleTopDestRect.x = rect->x + image->margin.l;
				middleTopDestRect.y = rect->y;
				middleTopDestRect.w = rect->w - image->margin.l - image->margin.r;
				middleTopDestRect.h = image->margin.t;
				SDL_RenderCopy((SDL_Renderer*)_parent->ren, (SDL_Texture*)image->texture.tex, &middleTopSrcRect, &middleTopDestRect);
			}

			SDL_Rect middleSrcRect;
			middleSrcRect.x = image->rect.x + image->margin.l;
			middleSrcRect.y = image->rect.y + image->margin.t;
			middleSrcRect.w = image->rect.w - image->margin.l - image->margin.r;
			middleSrcRect.h = image->rect.h - image->margin.t - image->margin.b;

			SDL_Rect middleDestRect;
			middleDestRect.x = rect->x + image->margin.l;
			middleDestRect.y = rect->y + image->margin.t;
			middleDestRect.w = rect->w - image->margin.l - image->margin.r;
			middleDestRect.h = rect->h - image->margin.t - image->margin.b;
			SDL_RenderCopy((SDL_Renderer*)_parent->ren, (SDL_Texture*)image->texture.tex, &middleSrcRect, &middleDestRect);

			if (image->margin.b > 0) {
				SDL_Rect middleBottomSrcRect;
				middleBottomSrcRect.x = image->rect.x + image->margin.l;
				middleBottomSrcRect.y = image->rect.y + image->rect.h - image->margin.b;
				middleBottomSrcRect.w = image->rect.w - image->margin.l - image->margin.r;
				middleBottomSrcRect.h = image->margin.b;

				SDL_Rect middleBottomDestRect;
				middleBottomDestRect.x = rect->x + image->margin.l;
				middleBottomDestRect.y = rect->y + rect->h - image->margin.b;
				middleBottomDestRect.w = rect->w - image->margin.l - image->margin.r;
				middleBottomDestRect.h = image->margin.b;
				SDL_RenderCopy((SDL_Renderer*)_parent->ren, (SDL_Texture*)image->texture.tex, &middleBottomSrcRect, &middleBottomDestRect);
			}
		}
*/
	;
}

void sjf_sdlSurface_drawRect(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_color* color) {
    
/*
		SDL_SetRenderDrawColor((SDL_Renderer*)_parent->ren, color->r, color->g, color->b, color->a);
		SDL_RenderFillRect((SDL_Renderer*)_parent->ren, (SDL_Rect*)rect);
*/
	;
}

void sjf_sdlSurface_drawText(sjs_sdlSurface* _parent, sjs_rect* rect, sjs_font* font, sjs_string* text, sjs_color* color) {
    
/*
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
*/	    
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
    _return->w = sjv_w;
    _return->h = sjv_h;
    sjf_size(_return);
}

void sjf_sdlSurface_getTextSize_heap(sjs_sdlSurface* _parent, sjs_font* font, sjs_string* text, sjs_size_heap** _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
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
    _return->tex = sjv_tex;
    sjf_texture(_return);
}

void sjf_sdlSurface_getTexture_heap(sjs_sdlSurface* _parent, sjs_string* src, sjs_texture_heap** _return) {
    int32_t sjt_cast3;
    uintptr_t sjv_tex;

    sjt_cast3 = 0;
    sjv_tex = (uintptr_t)sjt_cast3;
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

#ifdef __APPLE__
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	    _this->win = (uintptr_t)SDL_CreateWindow("Hello World!", 100, 100, _this->size.w, _this->size.h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	    if (_this->win == 0) {
	        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
	        exit(-1);
	    }

	    SDL_GL_CreateContext((SDL_Window*)_this->win);
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
    _interface->drawRect = (void(*)(void*,sjs_rect*,sjs_color*))sjf_sdlSurface_drawRect;
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

void sjf_size_addMargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    sjs_margin* sjt_dot91;
    sjs_margin* sjt_dot92;
    sjs_margin* sjt_dot93;
    sjs_margin* sjt_dot94;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjt_math23;
    int32_t sjt_math24;
    int32_t sjt_math25;
    int32_t sjt_math26;
    int32_t sjt_math27;
    int32_t sjt_math28;

    sjt_math23 = (_parent)->w;
    sjt_dot91 = margin;
    sjt_math24 = (sjt_dot91)->l;
    sjt_math21 = sjt_math23 + sjt_math24;
    sjt_dot92 = margin;
    sjt_math22 = (sjt_dot92)->r;
    _return->w = sjt_math21 + sjt_math22;
    sjt_math27 = (_parent)->h;
    sjt_dot93 = margin;
    sjt_math28 = (sjt_dot93)->t;
    sjt_math25 = sjt_math27 + sjt_math28;
    sjt_dot94 = margin;
    sjt_math26 = (sjt_dot94)->b;
    _return->h = sjt_math25 + sjt_math26;
    sjf_size(_return);
}

void sjf_size_addMargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size_heap** _return) {
    sjs_margin* sjt_dot95;
    sjs_margin* sjt_dot96;
    sjs_margin* sjt_dot97;
    sjs_margin* sjt_dot98;
    int32_t sjt_math29;
    int32_t sjt_math30;
    int32_t sjt_math31;
    int32_t sjt_math32;
    int32_t sjt_math33;
    int32_t sjt_math34;
    int32_t sjt_math35;
    int32_t sjt_math36;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_math31 = (_parent)->w;
    sjt_dot95 = margin;
    sjt_math32 = (sjt_dot95)->l;
    sjt_math29 = sjt_math31 + sjt_math32;
    sjt_dot96 = margin;
    sjt_math30 = (sjt_dot96)->r;
    (*_return)->w = sjt_math29 + sjt_math30;
    sjt_math35 = (_parent)->h;
    sjt_dot97 = margin;
    sjt_math36 = (sjt_dot97)->t;
    sjt_math33 = sjt_math35 + sjt_math36;
    sjt_dot98 = margin;
    sjt_math34 = (sjt_dot98)->b;
    (*_return)->h = sjt_math33 + sjt_math34;
    sjf_size_heap((*_return));
}

void sjf_size_cap(sjs_size* _parent, sjs_size* maxSize, sjs_size* _return) {
    int32_t sjt_compare21;
    int32_t sjt_compare22;
    sjs_size* sjt_dot99;
    bool sjt_ifElse16;

    sjt_compare21 = (_parent)->w;
    sjt_dot99 = maxSize;
    sjt_compare22 = (sjt_dot99)->w;
    sjt_ifElse16 = sjt_compare21 < sjt_compare22;
    if (sjt_ifElse16) {
        _return->w = (_parent)->w;
    } else {
        sjs_size* sjt_dot100;

        sjt_dot100 = maxSize;
        _return->w = (sjt_dot100)->w;
    }

    _return->h = 0;
    sjf_size(_return);
}

void sjf_size_cap_heap(sjs_size* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    int32_t sjt_compare23;
    int32_t sjt_compare24;
    sjs_size* sjt_dot101;
    bool sjt_ifElse17;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_compare23 = (_parent)->w;
    sjt_dot101 = maxSize;
    sjt_compare24 = (sjt_dot101)->w;
    sjt_ifElse17 = sjt_compare23 < sjt_compare24;
    if (sjt_ifElse17) {
        (*_return)->w = (_parent)->w;
    } else {
        sjs_size* sjt_dot102;

        sjt_dot102 = maxSize;
        (*_return)->w = (sjt_dot102)->w;
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
    sjs_string* sjt_dot139;
    bool sjt_ifElse21;

    sjt_dot139 = item;
    sjt_compare31 = (sjt_dot139)->count;
    sjt_compare32 = 0;
    sjt_ifElse21 = sjt_compare31 > sjt_compare32;
    if (sjt_ifElse21) {
        int32_t i;
        int32_t sjt_cast13;
        int32_t sjt_compare33;
        int32_t sjt_compare34;
        sjs_string* sjt_dot140;
        sjs_array_char* sjt_dot141;
        sjs_string* sjt_dot144;
        sjs_array_char* sjt_dot148;
        int32_t sjt_forEnd4;
        int32_t sjt_forStart4;
        int32_t sjt_functionParam19;
        char sjt_functionParam20;
        bool sjt_ifElse22;
        int32_t sjt_math73;
        int32_t sjt_math74;
        int32_t sjt_math75;
        int32_t sjt_math76;

        sjt_math75 = (_parent)->count;
        sjt_dot140 = item;
        sjt_math76 = (sjt_dot140)->count;
        sjt_math73 = sjt_math75 + sjt_math76;
        sjt_math74 = 1;
        sjt_compare33 = sjt_math73 + sjt_math74;
        sjt_dot141 = &(_parent)->data;
        sjt_compare34 = (sjt_dot141)->size;
        sjt_ifElse22 = sjt_compare33 > sjt_compare34;
        if (sjt_ifElse22) {
            sjs_array_char* sjt_dot142;
            sjs_string* sjt_dot143;
            int32_t sjt_functionParam14;
            int32_t sjt_math77;
            int32_t sjt_math78;
            int32_t sjt_math79;
            int32_t sjt_math80;

            sjt_dot142 = &(_parent)->data;
            sjt_math79 = (_parent)->count;
            sjt_dot143 = item;
            sjt_math80 = (sjt_dot143)->count;
            sjt_math77 = sjt_math79 + sjt_math80;
            sjt_math78 = 1;
            sjt_functionParam14 = sjt_math77 + sjt_math78;
            sjf_array_char_grow(sjt_dot142, sjt_functionParam14);
        }

        sjt_forStart4 = 0;
        i = sjt_forStart4;
        sjt_dot144 = item;
        sjt_forEnd4 = (sjt_dot144)->count;
        while (i < sjt_forEnd4) {
            sjs_array_char* sjt_dot145;
            sjs_string* sjt_dot146;
            int32_t sjt_functionParam15;
            char sjt_functionParam16;
            int32_t sjt_functionParam18;
            int32_t sjt_math81;
            int32_t sjt_math82;

            sjt_dot145 = &(_parent)->data;
            sjt_functionParam15 = (_parent)->count;
            sjt_dot146 = item;
            sjt_functionParam18 = i;
            sjf_string_getAt(sjt_dot146, sjt_functionParam18, &sjt_functionParam16);
            sjf_array_char_setAt(sjt_dot145, sjt_functionParam15, sjt_functionParam16);
            sjt_math81 = (_parent)->count;
            sjt_math82 = 1;
            _parent->count = sjt_math81 + sjt_math82;
            i++;
        }

        sjt_dot148 = &(_parent)->data;
        sjt_functionParam19 = (_parent)->count;
        sjt_cast13 = 0;
        sjt_functionParam20 = (char)sjt_cast13;
        sjf_array_char_setAt(sjt_dot148, sjt_functionParam19, sjt_functionParam20);
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
    sjs_array_char* sjt_dot147;
    int32_t sjt_functionParam17;

    sjt_dot147 = &(_parent)->data;
    sjt_functionParam17 = index;
    sjf_array_char_getAt(sjt_dot147, sjt_functionParam17, _return);
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
    _this->getRect = _from->getRect;
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
    _this->drawRect = _from->drawRect;
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
    sjv_i32_max = (-2147483647 - 1);
    sjv_i32_min = 2147483647;
    sjv_u32_max = (uint32_t)4294967295u;
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
    sjt_cast6->children.size = 3;
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
    sjt_dot159 = &sjv_colors;
    sjf_anon6_black(sjt_dot159, &sjt_cast12->textColor);
    sjt_dot160 = &sjv_style;
    sjt_functionParam32 = 0;
    sjf_anon7_getFont(sjt_dot160, sjt_functionParam32, &sjt_cast12->font);
    sjt_cast12->rect.x = 0;
    sjt_cast12->rect.y = 0;
    sjt_cast12->rect.w = 0;
    sjt_cast12->rect.h = 0;
    sjf_rect(&sjt_cast12->rect);
    sjt_dot161 = sjv_rootSurface;
    sjt_call14.count = 23;
    sjt_call14.data.size = 24;
    sjt_call14.data.data = (uintptr_t)sjg_string6;
    sjt_call14.data._isGlobal = false;
    sjf_array_char(&sjt_call14.data);
    sjf_string(&sjt_call14);
    sjt_interfaceParam28 = &sjt_call14;
    sjt_dot161->getTexture((void*)(((char*)sjt_dot161->_parent) + sizeof(intptr_t)), sjt_interfaceParam28, &sjt_cast12->normalImage.texture);
    sjt_cast12->normalImage.rect.x = 0;
    sjt_cast12->normalImage.rect.y = 0;
    sjt_cast12->normalImage.rect.w = 0;
    sjt_cast12->normalImage.rect.h = 0;
    sjf_rect(&sjt_cast12->normalImage.rect);
    sjt_cast12->normalImage.margin.l = 2;
    sjt_cast12->normalImage.margin.t = 2;
    sjt_cast12->normalImage.margin.r = 2;
    sjt_cast12->normalImage.margin.b = 2;
    sjf_margin(&sjt_cast12->normalImage.margin);
    sjf_image(&sjt_cast12->normalImage);
    sjt_dot162 = sjv_rootSurface;
    sjt_call15.count = 20;
    sjt_call15.data.size = 21;
    sjt_call15.data.data = (uintptr_t)sjg_string8;
    sjt_call15.data._isGlobal = false;
    sjf_array_char(&sjt_call15.data);
    sjf_string(&sjt_call15);
    sjt_interfaceParam29 = &sjt_call15;
    sjt_dot162->getTexture((void*)(((char*)sjt_dot162->_parent) + sizeof(intptr_t)), sjt_interfaceParam29, &sjt_cast12->hotImage.texture);
    sjt_cast12->hotImage.rect.x = 0;
    sjt_cast12->hotImage.rect.y = 0;
    sjt_cast12->hotImage.rect.w = 0;
    sjt_cast12->hotImage.rect.h = 0;
    sjf_rect(&sjt_cast12->hotImage.rect);
    sjt_cast12->hotImage.margin.l = 2;
    sjt_cast12->hotImage.margin.t = 2;
    sjt_cast12->hotImage.margin.r = 2;
    sjt_cast12->hotImage.margin.b = 2;
    sjf_margin(&sjt_cast12->hotImage.margin);
    sjf_image(&sjt_cast12->hotImage);
    sjt_dot163 = sjv_rootSurface;
    sjt_call16.count = 24;
    sjt_call16.data.size = 25;
    sjt_call16.data.data = (uintptr_t)sjg_string10;
    sjt_call16.data._isGlobal = false;
    sjf_array_char(&sjt_call16.data);
    sjf_string(&sjt_call16);
    sjt_interfaceParam30 = &sjt_call16;
    sjt_dot163->getTexture((void*)(((char*)sjt_dot163->_parent) + sizeof(intptr_t)), sjt_interfaceParam30, &sjt_cast12->pressedImage.texture);
    sjt_cast12->pressedImage.rect.x = 0;
    sjt_cast12->pressedImage.rect.y = 0;
    sjt_cast12->pressedImage.rect.w = 0;
    sjt_cast12->pressedImage.rect.h = 0;
    sjf_rect(&sjt_cast12->pressedImage.rect);
    sjt_cast12->pressedImage.margin.l = 2;
    sjt_cast12->pressedImage.margin.t = 2;
    sjt_cast12->pressedImage.margin.r = 2;
    sjt_cast12->pressedImage.margin.b = 2;
    sjf_margin(&sjt_cast12->pressedImage.margin);
    sjf_image(&sjt_cast12->pressedImage);
    sjt_dot164 = &sjv_buttonState;
    sjt_cast12->state = (sjt_dot164)->normal;
    sjt_cast12->margin.l = 10;
    sjt_cast12->margin.t = 10;
    sjt_cast12->margin.r = 10;
    sjt_cast12->margin.b = 10;
    sjf_margin(&sjt_cast12->margin);
    sjf_buttonElement_heap(sjt_cast12);
    sjt_cast10->child = (sji_element*)sjf_buttonElement_heap_as_sji_element(sjt_cast12);
    sjt_cast10->rect.x = 0;
    sjt_cast10->rect.y = 0;
    sjt_cast10->rect.w = 0;
    sjt_cast10->rect.h = 0;
    sjf_rect(&sjt_cast10->rect);
    sjt_dot165 = &sjv_borderPosition;
    sjt_cast10->position = (sjt_dot165)->left;
    sjt_cast10->_children = 0;
    if (sjt_cast10->_children != 0) {
        sjt_cast10->_children->_refCount++;
    }

    sjf_borderChild_heap(sjt_cast10);
    sjt_functionParam5 = (sji_element*)sjf_borderChild_heap_as_sji_element(sjt_cast10);
    sjf_array_heap_element_initAt(&sjt_cast6->children, sjt_functionParam4, sjt_functionParam5);
    sjt_functionParam33 = 1;
    sjt_cast18 = (sjs_borderChild_heap*)malloc(sizeof(sjs_borderChild_heap));
    sjt_cast18->_refCount = 1;
    sjt_cast19 = (sjs_boxElement_heap*)malloc(sizeof(sjs_boxElement_heap));
    sjt_cast19->_refCount = 1;
    sjt_dot169 = &sjv_colors;
    sjf_anon6_red(sjt_dot169, &sjt_cast19->color);
    sjt_cast19->idealSize.w = 50;
    sjt_cast19->idealSize.h = sjv_i32_max;
    sjf_size(&sjt_cast19->idealSize);
    sjt_cast19->rect.x = 0;
    sjt_cast19->rect.y = 0;
    sjt_cast19->rect.w = 0;
    sjt_cast19->rect.h = 0;
    sjf_rect(&sjt_cast19->rect);
    sjf_boxElement_heap(sjt_cast19);
    sjt_cast18->child = (sji_element*)sjf_boxElement_heap_as_sji_element(sjt_cast19);
    sjt_cast18->rect.x = 0;
    sjt_cast18->rect.y = 0;
    sjt_cast18->rect.w = 0;
    sjt_cast18->rect.h = 0;
    sjf_rect(&sjt_cast18->rect);
    sjt_dot170 = &sjv_borderPosition;
    sjt_cast18->position = (sjt_dot170)->right;
    sjt_cast18->_children = 0;
    if (sjt_cast18->_children != 0) {
        sjt_cast18->_children->_refCount++;
    }

    sjf_borderChild_heap(sjt_cast18);
    sjt_functionParam34 = (sji_element*)sjf_borderChild_heap_as_sji_element(sjt_cast18);
    sjf_array_heap_element_initAt(&sjt_cast6->children, sjt_functionParam33, sjt_functionParam34);
    sjt_functionParam37 = 2;
    sjt_cast20 = (sjs_boxElement_heap*)malloc(sizeof(sjs_boxElement_heap));
    sjt_cast20->_refCount = 1;
    sjt_dot171 = &sjv_colors;
    sjf_anon6_green(sjt_dot171, &sjt_cast20->color);
    sjt_cast20->idealSize.w = 0;
    sjt_cast20->idealSize.h = 0;
    sjf_size(&sjt_cast20->idealSize);
    sjt_cast20->rect.x = 0;
    sjt_cast20->rect.y = 0;
    sjt_cast20->rect.w = 0;
    sjt_cast20->rect.h = 0;
    sjf_rect(&sjt_cast20->rect);
    sjf_boxElement_heap(sjt_cast20);
    sjt_functionParam38 = (sji_element*)sjf_boxElement_heap_as_sji_element(sjt_cast20);
    sjf_array_heap_element_initAt(&sjt_cast6->children, sjt_functionParam37, sjt_functionParam38);
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
    sjt_cast18->_refCount--;
    if (sjt_cast18->_refCount <= 0) {
        sjf_borderChild_destroy((sjs_borderChild*)(((char*)sjt_cast18) + sizeof(intptr_t)));
    }
    sjt_cast19->_refCount--;
    if (sjt_cast19->_refCount <= 0) {
        sjf_boxElement_destroy((sjs_boxElement*)(((char*)sjt_cast19) + sizeof(intptr_t)));
    }
    sjt_cast20->_refCount--;
    if (sjt_cast20->_refCount <= 0) {
        sjf_boxElement_destroy((sjs_boxElement*)(((char*)sjt_cast20) + sizeof(intptr_t)));
    }
    sjt_cast6->_refCount--;
    if (sjt_cast6->_refCount <= 0) {
        sjf_borderLayout_destroy((sjs_borderLayout*)(((char*)sjt_cast6) + sizeof(intptr_t)));
    }
    sjt_functionParam34->_refCount--;
    if (sjt_functionParam34->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam34);
    }
    sjt_functionParam38->_refCount--;
    if (sjt_functionParam38->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam38);
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
    sjf_string_destroy(&sjt_call14);
    sjf_string_destroy(&sjt_call15);
    sjf_string_destroy(&sjt_call16);
    sjf_anon8_destroy(&sjv_borderPosition);
    sjf_anon5_destroy(&sjv_buttonState);
    sjf_anon6_destroy(&sjv_colors);
    sjf_anon1_destroy(&sjv_console);
    sjf_anon4_destroy(&sjv_convert);
    sjf_anon2_destroy(&sjv_parse);
    sjf_anon3_destroy(&sjv_random);
    sjf_anon7_destroy(&sjv_style);
}
