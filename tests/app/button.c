#ifdef __GNUC__
#if __x86_64__ 
#define __LINUX__
#define __64__
#elif __i386__ 
#define __LINUX__
#define __32__
#else
Invalid bits
#endif
#elif _MSC_VER
#if _WIN64 
#define __WINDOWS__
#define __64__
#elif _WIN32 
#define __WINDOWS__
#define __32__
#else
Invalid bits
#endif
#else
Invalid compiler
#endif
#ifdef WIN32
#pragma warning(disable:4996)
#define GLEW_STATIC
#include <windows.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif
/**
* Maximum number of attributes per vertex
*
* @private
*/
#define MAX_VERTEX_ATTRIBUTE 16    
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
#include <lib/common/khash.h>
#include <lib/common/value_option_types.h>
#include <lib/ui/obj_parser.h>
#include <limits.h>
#include <math.h>
#include <png.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __WINDOWS__
#include <windows.h>
#endif
#include FT_FREETYPE_H
#include FT_LCD_FILTER_H
#include FT_STROKER_H

typedef struct td_delete_cb delete_cb;
typedef struct td_delete_cb_list delete_cb_list;
typedef struct vector_td vector_t;
typedef struct vertex_attribute_td vertex_attribute_t;
typedef struct vertex_buffer_td vertex_buffer_t;
const char* sjg_string1 = "shaders/v3f-t2f.vert";
const char* sjg_string10 = "shaders/v3f-t2f-n3f-phong.vert";
const char* sjg_string11 = "shaders/v3f-t2f-n3f-phong.frag";
const char* sjg_string12 = "shaders/v3f-t2f-c4f.vert";
const char* sjg_string13 = "shaders/v3f-t2f-c4f.frag";
const char* sjg_string14 = "vertex:3f,tex_coord:2f,normal:3f";
const char* sjg_string15 = "shaders/saturate.frag";
const char* sjg_string17 = "assets/arial.ttf";
const char* sjg_string18 = "assets/buttonNormal.png";
const char* sjg_string19 = "assets/buttonHot.png";
const char* sjg_string2 = "shaders/blur-horizontal.frag";
const char* sjg_string20 = "assets/buttonPressed.png";
const char* sjg_string21 = "texture";
const char* sjg_string22 = "model";
const char* sjg_string23 = "view";
const char* sjg_string24 = "projection";
const char* sjg_string25 = "release";
const char* sjg_string26 = "release done";
const char* sjg_string27 = "button1";
const char* sjg_string28 = "button1Text";
const char* sjg_string29 = "count : ";
const char* sjg_string3 = "shaders/blur-vertical.frag";
const char* sjg_string30 = "bob";
const char* sjg_string31 = "viewport being pop'ed is wrong";
const char* sjg_string4 = "shaders/fade.frag";
const char* sjg_string5 = "shaders/v3f-c4f.vert";
const char* sjg_string6 = "shaders/v3f-c4f.frag";
const char* sjg_string7 = "shaders/v3f-t2f.frag";
const char* sjg_string8 = "shaders/v3f-n3f-phong.vert";
const char* sjg_string9 = "shaders/v3f-n3f-phong.frag";

struct td_delete_cb {
    void* _parent;
    void (*_cb)(void* _parent, void* object);
};
struct td_delete_cb_list {
    int size;
    delete_cb cb[5];
    delete_cb_list* next;
};
typedef struct {
    float x, y, z;    // position
    float r, g, b, a; // color
} vertex3_color4_t; 
typedef struct {
    float x, y, z;    // position
    float s, t;       // texture
} vertex3_texture2_t;   
typedef struct {
    float x, y, z;    // position
    float s, t;       // texture
    float r, g, b, a; // color
} vertex3_texture2_color3_t;    
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
typedef struct texture_atlas_t texture_atlas_td; 
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
    texture_atlas_td * atlas;
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
*  Generic vector structure.
*
* @memberof vector
*/
struct vector_td
{
    /** Pointer to dynamically allocated items. */
    void * items;
    /** Number of items that can be held in currently allocated storage. */
    size_t capacity;
    /** Number of items. */
    size_t size;
    /** Size (in bytes) of a single item. */
    size_t item_size;
};
/**
*  Generic vertex attribute.
*/
struct vertex_attribute_td
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
};
/**
* Generic vertex buffer.
*/
struct vertex_buffer_td
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
};
#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_windowrenderer_typeId 3
#define sjs_color_typeId 4
#define sjs_size_typeId 5
#define sjs_mat4_typeId 6
#define sjs_rect_typeId 7
#define sjs_scene2d_typeId 8
#define sjs_array_char_typeId 9
#define sjs_string_typeId 10
#define sjs_vec3_typeId 11
#define sjs_light_typeId 12
#define sji_model_typeId 13
#define sjs_array_heap_iface_model_typeId 14
#define sjs_list_heap_iface_model_typeId 15
#define sjs_point_typeId 16
#define sjs_mouseevent_typeId 17
#define sji_model_vtbl_typeId 18
#define sjs_hash_string_weak_iface_model_typeId 19
#define sji_element_vtbl_typeId 20
#define sji_element_typeId 21
#define sjs_hash_string_weak_iface_element_typeId 22
#define sjs_array_heap_iface_animation_typeId 23
#define sjs_list_heap_iface_animation_typeId 24
#define sjs_anon1_typeId 25
#define sji_animation_vtbl_typeId 26
#define sji_animation_typeId 27
#define sjs_shader_typeId 28
#define sjs_fontkey_typeId 29
#define sjs_font_typeId 30
#define sjs_hash_fontkey_weak_font_typeId 31
#define sjs_array_rect_typeId 32
#define sjs_list_rect_typeId 33
#define sjs_array_u32_typeId 34
#define sjs_list_u32_typeId 35
#define sjs_anon2_typeId 36
#define sjs_controller_typeId 37
#define sjs_array_heap_iface_element_typeId 38
#define sjs_margin_typeId 39
#define sjs_array_gridunit_typeId 40
#define sjs_gridlayout_typeId 41
#define sjs_gridunit_typeId 42
#define sjs_array_i32_typeId 43
#define sji_gridchild_vtbl_typeId 44
#define sji_gridchild_typeId 45
#define sjs_texture_typeId 46
#define sjs_image_typeId 47
#define cb_void_typeId 48
#define cb_void_heap_typeId 49
#define sjs_textrenderer_typeId 50
#define sjs_imagerenderer_typeId 51
#define sji_clickable_vtbl_typeId 52
#define sji_clickable_typeId 53
#define sjs_clickgesture_typeId 54
#define sjs_buttonelement_typeId 55
#define sji_textelement_vtbl_typeId 56
#define sji_textelement_typeId 57
#define sjs_textelement_typeId 58

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_windowrenderer sjs_windowrenderer;
typedef struct td_sjs_color sjs_color;
typedef struct td_sjs_size sjs_size;
typedef struct td_sjs_mat4 sjs_mat4;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_scene2d sjs_scene2d;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_vec3 sjs_vec3;
typedef struct td_sjs_light sjs_light;
typedef struct td_sji_model sji_model;
typedef struct td_sjs_array_heap_iface_model sjs_array_heap_iface_model;
typedef struct td_sjs_list_heap_iface_model sjs_list_heap_iface_model;
typedef struct td_sjs_point sjs_point;
typedef struct td_sjs_mouseevent sjs_mouseevent;
typedef struct td_sji_model_vtbl sji_model_vtbl;
typedef struct td_sjs_hash_string_weak_iface_model sjs_hash_string_weak_iface_model;
typedef struct td_sji_element_vtbl sji_element_vtbl;
typedef struct td_sji_element sji_element;
typedef struct td_sjs_hash_string_weak_iface_element sjs_hash_string_weak_iface_element;
typedef struct td_sjs_array_heap_iface_animation sjs_array_heap_iface_animation;
typedef struct td_sjs_list_heap_iface_animation sjs_list_heap_iface_animation;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sji_animation_vtbl sji_animation_vtbl;
typedef struct td_sji_animation sji_animation;
typedef struct td_sjs_shader sjs_shader;
typedef struct td_sjs_fontkey sjs_fontkey;
typedef struct td_sjs_font sjs_font;
typedef struct td_sjs_hash_fontkey_weak_font sjs_hash_fontkey_weak_font;
typedef struct td_sjs_array_rect sjs_array_rect;
typedef struct td_sjs_list_rect sjs_list_rect;
typedef struct td_sjs_array_u32 sjs_array_u32;
typedef struct td_sjs_list_u32 sjs_list_u32;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_controller sjs_controller;
typedef struct td_sjs_array_heap_iface_element sjs_array_heap_iface_element;
typedef struct td_sjs_margin sjs_margin;
typedef struct td_sjs_array_gridunit sjs_array_gridunit;
typedef struct td_sjs_gridlayout sjs_gridlayout;
typedef struct td_sjs_gridunit sjs_gridunit;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sji_gridchild_vtbl sji_gridchild_vtbl;
typedef struct td_sji_gridchild sji_gridchild;
typedef struct td_sjs_texture sjs_texture;
typedef struct td_sjs_image sjs_image;
typedef struct td_cb_void cb_void;
typedef struct td_cb_void_heap cb_void_heap;
typedef struct td_sjs_textrenderer sjs_textrenderer;
typedef struct td_sjs_imagerenderer sjs_imagerenderer;
typedef struct td_sji_clickable_vtbl sji_clickable_vtbl;
typedef struct td_sji_clickable sji_clickable;
typedef struct td_sjs_clickgesture sjs_clickgesture;
typedef struct td_sjs_buttonelement sjs_buttonelement;
typedef struct td_sji_textelement_vtbl sji_textelement_vtbl;
typedef struct td_sji_textelement sji_textelement;
typedef struct td_sjs_textelement sjs_textelement;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_windowrenderer {
    int _refCount;
    SDL_Window* win;
    SDL_Renderer* ren;
};

struct td_sjs_color {
    int _refCount;
    float r;
    float g;
    float b;
    float a;
};

struct td_sjs_size {
    int _refCount;
    int32_t w;
    int32_t h;
};

struct td_sjs_mat4 {
    int _refCount;
    float m00;
    float m01;
    float m02;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
    float m30;
    float m31;
    float m32;
    float m33;
};

struct td_sjs_rect {
    int _refCount;
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct td_sjs_scene2d {
    int _refCount;
    sjs_size _size;
    sjs_mat4 model;
    sjs_mat4 view;
    sjs_mat4 projection;
    sjs_rect windowrect;
};

struct td_sjs_array_char {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_string {
    int _refCount;
    int32_t count;
    sjs_array_char data;
};

struct td_sjs_vec3 {
    int _refCount;
    float x;
    float y;
    float z;
};

struct td_sjs_light {
    int _refCount;
    sjs_vec3 pos;
    sjs_color diffusecolor;
    sjs_color speccolor;
};

struct td_sji_model {
    sjs_object* _parent;
    sji_model_vtbl* _vtbl;
};

struct td_sjs_array_heap_iface_model {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_list_heap_iface_model {
    int _refCount;
    sjs_array_heap_iface_model array;
};

struct td_sjs_point {
    int _refCount;
    int32_t x;
    int32_t y;
};

struct td_sjs_mouseevent {
    int _refCount;
    int32_t type;
    sjs_point point;
    bool iscaptured;
    bool isleftdown;
};

struct td_sji_model_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*update)(sjs_object* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
    void (*getz)(sjs_object* _parent, float* _return);
    void (*getcenter)(sjs_object* _parent, sjs_vec3* _return);
    void (*getcenter_heap)(sjs_object* _parent, sjs_vec3** _return);
    void (*getworld)(sjs_object* _parent, sjs_mat4* _return);
    void (*getworld_heap)(sjs_object* _parent, sjs_mat4** _return);
    void (*renderorqueue)(sjs_object* _parent, sjs_list_heap_iface_model* zqueue);
    void (*render)(sjs_object* _parent);
    void (*firemouseevent)(sjs_object* _parent, sjs_mouseevent* mouseevent);
};

struct td_sjs_hash_string_weak_iface_model {
    int _refCount;
    void* _hash;
};

struct td_sji_element_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getsize)(sjs_object* _parent, sjs_size* maxsize, sjs_size* _return);
    void (*getsize_heap)(sjs_object* _parent, sjs_size* maxsize, sjs_size** _return);
    void (*getrect)(sjs_object* _parent, sjs_rect* _return);
    void (*getrect_heap)(sjs_object* _parent, sjs_rect** _return);
    void (*setrect)(sjs_object* _parent, sjs_rect* rect);
    void (*render)(sjs_object* _parent, sjs_scene2d* scene);
    void (*firemouseevent)(sjs_object* _parent, sjs_mouseevent* mouseevent, bool* _return);
};

struct td_sji_element {
    sjs_object* _parent;
    sji_element_vtbl* _vtbl;
};

struct td_sjs_hash_string_weak_iface_element {
    int _refCount;
    void* _hash;
};

struct td_sjs_array_heap_iface_animation {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_list_heap_iface_animation {
    int _refCount;
    sjs_array_heap_iface_animation array;
};

struct td_sjs_anon1 {
    int _refCount;
    sjs_list_heap_iface_animation animations;
    int32_t current;
};

struct td_sji_animation_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*nextframe)(sjs_object* _parent, int32_t time, bool* _return);
};

struct td_sji_animation {
    sjs_object* _parent;
    sji_animation_vtbl* _vtbl;
};

struct td_sjs_shader {
    int _refCount;
    sjs_string vertex;
    sjs_string pixel;
    GLuint id;
};

struct td_sjs_fontkey {
    int _refCount;
    sjs_string src;
    float size;
};

struct td_sjs_font {
    int _refCount;
    sjs_string src;
    float size;
    texture_font_t* font;
    texture_atlas_t* atlas;
};

struct td_sjs_hash_fontkey_weak_font {
    int _refCount;
    void* _hash;
};

struct td_sjs_array_rect {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_list_rect {
    int _refCount;
    sjs_array_rect array;
};

struct td_sjs_array_u32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_list_u32 {
    int _refCount;
    sjs_array_u32 array;
};

struct td_sjs_anon2 {
    int _refCount;
};

struct td_sjs_controller {
    int _refCount;
    int32_t _button1count;
};

struct td_sjs_array_heap_iface_element {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_margin {
    int _refCount;
    int32_t l;
    int32_t t;
    int32_t r;
    int32_t b;
};

struct td_sjs_array_gridunit {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_gridlayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    sjs_array_gridunit cols;
    sjs_array_gridunit rows;
    sjs_rect _rect;
};

struct td_sjs_gridunit {
    int _refCount;
    int32_t amount;
    int32_t type;
};

struct td_sjs_array_i32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sji_gridchild_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getrow)(sjs_object* _parent, int32_t* _return);
    void (*getcol)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_gridchild {
    sjs_object* _parent;
    sji_gridchild_vtbl* _vtbl;
};

struct td_sjs_texture {
    int _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_image {
    int _refCount;
    sjs_texture texture;
    sjs_rect rect;
    sjs_margin margin;
};

struct td_cb_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent);
};

struct td_cb_void_heap {
    cb_void inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_textrenderer {
    int _refCount;
    sjs_string text;
    sjs_point point;
    sjs_color color;
    sjs_font font;
    vertex_buffer_t* buffer;
};

struct td_sjs_imagerenderer {
    int _refCount;
    sjs_rect rect;
    sjs_image image;
    vertex_buffer_t* buffer;
};

struct td_sji_clickable_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*onclickgestureenter)(sjs_object* _parent, sji_element element);
    void (*onclickgestureleave)(sjs_object* _parent, sji_element element);
    void (*onclickgesturepress)(sjs_object* _parent, sji_element element);
    void (*onclickgestureclick)(sjs_object* _parent, sji_element element);
};

struct td_sji_clickable {
    sjs_object* _parent;
    sji_clickable_vtbl* _vtbl;
};

struct td_sjs_clickgesture {
    int _refCount;
    sji_element element;
    sji_clickable clickable;
    sjs_rect rect;
    int32_t _state;
};

struct td_sjs_buttonelement {
    int _refCount;
    sjs_string text;
    sjs_color textcolor;
    sjs_font* font;
    sjs_image normalimage;
    sjs_image hotimage;
    sjs_image pressedimage;
    sjs_margin margin;
    cb_void_heap onclick;
    sjs_rect _rect;
    sjs_textrenderer _textrenderer;
    sjs_imagerenderer _imagerenderer;
    sjs_clickgesture _clickgesture;
};

struct td_sji_textelement_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*gettext)(sjs_object* _parent, sjs_string* _return);
    void (*gettext_heap)(sjs_object* _parent, sjs_string** _return);
    void (*settext)(sjs_object* _parent, sjs_string* v);
};

struct td_sji_textelement {
    sjs_object* _parent;
    sji_textelement_vtbl* _vtbl;
};

struct td_sjs_textelement {
    int _refCount;
    sjs_string id;
    sjs_font* font;
    sjs_string text;
    sjs_color color;
    sjs_margin margin;
    int32_t halign;
    int32_t valign;
    sjs_rect _rect;
    sjs_textrenderer _textrenderer;
};

sji_clickable_vtbl sjs_buttonelement_clickable_vtbl;
sji_element_vtbl sjs_buttonelement_element_vtbl;
sji_element_vtbl sjs_gridlayout_element_vtbl;
sji_element_vtbl sjs_textelement_element_vtbl;
sji_textelement_vtbl sjs_textelement_textelement_vtbl;
void halt(const char * format, ...);
void ptr_hash(void* p, uint32_t* result);
void ptr_isequal(void *p1, void* p2, bool* result);
void delete_cb_list_free(delete_cb_list* d);
void delete_cb_list_add(delete_cb_list* d, delete_cb cb);
void delete_cb_list_remove(delete_cb_list* d, delete_cb cb);
void delete_cb_list_invoke(delete_cb_list* d, void* p);
void weakptr_init();
void weakptr_release(void* v);
void weakptr_cb_add(void* v, delete_cb cb);
void weakptr_cb_remove(void* v, delete_cb cb);
void weakptr_clear(void* parent, void* v);
void ptr_init();
void ptr_retain(void* ptr);
bool ptr_release(void* ptr);
#ifndef string_weak_iface_model_hash_typedef
#define string_weak_iface_model_hash_typedef
KHASH_INIT_TYPEDEF(string_weak_iface_model_hash_type, sjs_string, sji_model)
#endif
#ifndef string_weak_iface_model_hash_typedef
#define string_weak_iface_model_hash_typedef
KHASH_INIT_TYPEDEF(string_weak_iface_model_hash_type, sjs_string, sji_model)
#endif
#ifndef string_weak_iface_element_hash_typedef
#define string_weak_iface_element_hash_typedef
KHASH_INIT_TYPEDEF(string_weak_iface_element_hash_type, sjs_string, sji_element)
#endif
#ifndef string_weak_iface_element_hash_typedef
#define string_weak_iface_element_hash_typedef
KHASH_INIT_TYPEDEF(string_weak_iface_element_hash_type, sjs_string, sji_element)
#endif
double *
make_distance_mapd( double *img,
unsigned int width, unsigned int height );
unsigned char *
make_distance_mapb( unsigned char *img,
unsigned int width, unsigned int height );    
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
#ifndef fontkey_weak_font_hash_typedef
#define fontkey_weak_font_hash_typedef
KHASH_INIT_TYPEDEF(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*)
#endif
#ifndef fontkey_weak_font_hash_typedef
#define fontkey_weak_font_hash_typedef
KHASH_INIT_TYPEDEF(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*)
#endif
void glid_retain(GLuint id);
bool glid_release(GLuint id);
void glid_gethash(GLuint id, uint32_t* result);
void glid_isequal(GLuint id1, GLuint id2, bool* result);
/* Freetype GL - A C OpenGL Freetype engine
*
* Distributed under the OSI-approved BSD 2-Clause License.  See accompanying
* file `LICENSE` for more details.
*/
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
void add_text(vertex_buffer_t * buffer, texture_font_t * font, char *text, vec4 * color, vec2 * pen);   
vec2 get_text_size(texture_font_t * font, char *text);
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
* @file   vector.h
* @author Nicolas Rougier (Nicolas.Rougier@inria.fr)
*
* @defgroup vector Vector
*
* The vector structure and accompanying functions loosely mimic the STL C++
* vector class. It is used by @ref texture-atlas (for storing nodes), @ref
* texture-font (for storing glyphs) and @ref font-manager (for storing fonts).
* More information at http://www.cppreference.com/wiki/container/vector/start
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
int32_t sjv_borderposition_bottom;
int32_t sjv_borderposition_fill;
int32_t sjv_borderposition_left;
int32_t sjv_borderposition_right;
int32_t sjv_borderposition_top;
int32_t sjv_clickstate_entered;
int32_t sjv_clickstate_none;
int32_t sjv_clickstate_pressed;
int32_t sjv_flowlayoutorientation_bottomtop;
int32_t sjv_flowlayoutorientation_leftright;
int32_t sjv_flowlayoutorientation_rightleft;
int32_t sjv_flowlayoutorientation_topbottom;
int32_t sjv_glblendfunctype_gl_constant_alpha;
int32_t sjv_glblendfunctype_gl_constant_color;
int32_t sjv_glblendfunctype_gl_dst_alpha;
int32_t sjv_glblendfunctype_gl_dst_color;
int32_t sjv_glblendfunctype_gl_one;
int32_t sjv_glblendfunctype_gl_one_minus_constant_alpha;
int32_t sjv_glblendfunctype_gl_one_minus_constant_color;
int32_t sjv_glblendfunctype_gl_one_minus_dst_alpha;
int32_t sjv_glblendfunctype_gl_one_minus_dst_color;
int32_t sjv_glblendfunctype_gl_one_minus_src_alpha;
int32_t sjv_glblendfunctype_gl_one_minus_src_color;
int32_t sjv_glblendfunctype_gl_src_alpha;
int32_t sjv_glblendfunctype_gl_src_alpha_saturate;
int32_t sjv_glblendfunctype_gl_src_color;
int32_t sjv_glblendfunctype_gl_zero;
int32_t sjv_glfeature_gl_blend;
int32_t sjv_glfeature_gl_cull_face;
int32_t sjv_glfeature_gl_depth_test;
int32_t sjv_glfeature_gl_dither;
int32_t sjv_glfeature_gl_polygon_offset_fill;
int32_t sjv_glfeature_gl_sample_alpha_to_coverage;
int32_t sjv_glfeature_gl_sample_coverage;
int32_t sjv_glfeature_gl_scissor_test;
int32_t sjv_glfeature_gl_stencil_test;
int32_t sjv_glframebufferattachment_gl_color_attachment0;
int32_t sjv_glframebufferattachment_gl_depth_attachment;
int32_t sjv_glframebufferattachment_gl_stencil_attachment;
int32_t sjv_glframebufferstatus_gl_framebuffer_complete;
int32_t sjv_glframebufferstatus_gl_framebuffer_incomplete_attachment;
int32_t sjv_glframebufferstatus_gl_framebuffer_incomplete_missing_attachment;
int32_t sjv_glframebufferstatus_gl_framebuffer_unsupported;
int32_t sjv_glframebuffertexture_gl_texture_2d;
int32_t sjv_glframebuffertexture_gl_texture_cube_map_negative_x;
int32_t sjv_glframebuffertexture_gl_texture_cube_map_negative_y;
int32_t sjv_glframebuffertexture_gl_texture_cube_map_negative_z;
int32_t sjv_glframebuffertexture_gl_texture_cube_map_positive_x;
int32_t sjv_glframebuffertexture_gl_texture_cube_map_positive_y;
int32_t sjv_glframebuffertexture_gl_texture_cube_map_positive_z;
int32_t sjv_glrenderbufferformat_gl_depth_component16;
int32_t sjv_glrenderbufferformat_gl_rgb565;
int32_t sjv_glrenderbufferformat_gl_rgb5_a1;
int32_t sjv_glrenderbufferformat_gl_rgba4;
int32_t sjv_glrenderbufferformat_gl_stencil_index8;
int32_t sjv_gltexture_gl_texture_2d;
int32_t sjv_gltexture_gl_texture_cube_map;
int32_t sjv_gltextureattribute_gl_texture_mag_filter;
int32_t sjv_gltextureattribute_gl_texture_min_filter;
int32_t sjv_gltextureattribute_gl_texture_wrap_s;
int32_t sjv_gltextureattribute_gl_texture_wrap_t;
int32_t sjv_gltextureformat_gl_alpha;
int32_t sjv_gltextureformat_gl_luminance;
int32_t sjv_gltextureformat_gl_luminance_alpha;
int32_t sjv_gltextureformat_gl_rgb;
int32_t sjv_gltextureformat_gl_rgba;
int32_t sjv_gltexturetype_gl_unsigned_byte;
int32_t sjv_gltexturetype_gl_unsigned_short_4_4_4_4;
int32_t sjv_gltexturetype_gl_unsigned_short_5_5_5_1;
int32_t sjv_gltexturetype_gl_unsigned_short_5_6_5;
int32_t sjv_gltexturevalue_gl_clamp_to_edge;
int32_t sjv_gltexturevalue_gl_linear;
int32_t sjv_gltexturevalue_gl_linear_mipmap_linear;
int32_t sjv_gltexturevalue_gl_linear_mipmap_nearest;
int32_t sjv_gltexturevalue_gl_mirrored_repeat;
int32_t sjv_gltexturevalue_gl_nearest;
int32_t sjv_gltexturevalue_gl_nearest_mipmap_linear;
int32_t sjv_gltexturevalue_gl_nearest_mipmap_nearest;
int32_t sjv_gltexturevalue_gl_repeat;
int32_t sjv_gridunittype_fixed;
int32_t sjv_gridunittype_star;
int32_t sjv_imagestretch_aspectratio;
int32_t sjv_imagestretch_center;
int32_t sjv_imagestretch_fill;
int32_t sjv_listlayoutorientation_bottomtop;
int32_t sjv_listlayoutorientation_leftright;
int32_t sjv_listlayoutorientation_rightleft;
int32_t sjv_listlayoutorientation_topbottom;
int32_t sjv_mouseeventtype_down;
int32_t sjv_mouseeventtype_move;
int32_t sjv_mouseeventtype_up;
int32_t sjv_texthorizontal_center;
int32_t sjv_texthorizontal_left;
int32_t sjv_texthorizontal_right;
int32_t sjv_textvertical_bottom;
int32_t sjv_textvertical_center;
int32_t sjv_textvertical_top;

int32_t result1;
sjs_string sjt_call21 = { -1 };
sjs_string sjt_call22 = { -1 };
sjs_string sjt_call23 = { -1 };
sjs_gridlayout* sjt_call3 = 0;
sjs_textelement* sjt_call32 = 0;
sjs_gridunit sjt_call35 = { -1 };
sjs_gridunit sjt_call36 = { -1 };
sjs_gridunit sjt_call37 = { -1 };
sjs_gridunit sjt_call38 = { -1 };
sjs_gridunit sjt_call39 = { -1 };
sjs_gridunit sjt_call40 = { -1 };
sjs_buttonelement* sjt_call5 = 0;
sjs_gridlayout* sjt_cast1 = 0;
sjs_textelement* sjt_cast10 = 0;
sjs_buttonelement* sjt_cast3 = 0;
sjs_color* sjt_copy18 = 0;
sjs_color* sjt_copy34 = 0;
sjs_string* sjt_functionParam107 = 0;
sjs_string* sjt_functionParam108 = 0;
sjs_string* sjt_functionParam109 = 0;
int32_t sjt_functionParam134;
sji_element sjt_functionParam135 = { 0 };
int32_t sjt_functionParam148;
int32_t sjt_functionParam149;
sjs_gridunit* sjt_functionParam150 = 0;
int32_t sjt_functionParam151;
sjs_gridunit* sjt_functionParam152 = 0;
int32_t sjt_functionParam153;
sjs_gridunit* sjt_functionParam154 = 0;
int32_t sjt_functionParam155;
sjs_gridunit* sjt_functionParam156 = 0;
int32_t sjt_functionParam157;
sjs_gridunit* sjt_functionParam158 = 0;
int32_t sjt_functionParam159;
sjs_gridunit* sjt_functionParam160 = 0;
int32_t sjt_functionParam39;
sji_element sjt_functionParam40 = { 0 };
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_array_heap_iface_element* sjt_parent28 = 0;
sjs_anon2* sjt_parent51 = 0;
sjs_array_heap_iface_element* sjt_parent69 = 0;
sjs_anon2* sjt_parent81 = 0;
sjs_array_gridunit* sjt_parent82 = 0;
sjs_array_gridunit* sjt_parent83 = 0;
sjs_array_gridunit* sjt_parent84 = 0;
sjs_array_gridunit* sjt_parent85 = 0;
sjs_array_gridunit* sjt_parent86 = 0;
sjs_array_gridunit* sjt_parent87 = 0;
sjs_anon1 sjv_animator = { -1 };
sjs_shader sjv_blurhorizontalshader = { -1 };
sjs_shader sjv_blurverticalshader = { -1 };
sjs_shader sjv_boxshader = { -1 };
sjs_color sjv_colors_black = { -1 };
sjs_color sjv_colors_blue = { -1 };
sjs_color sjv_colors_gray = { -1 };
sjs_color sjv_colors_green = { -1 };
sjs_color sjv_colors_red = { -1 };
sjs_color sjv_colors_white = { -1 };
sjs_hash_string_weak_iface_element sjv_elementsbyid = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
sjs_shader sjv_fadeshader = { -1 };
sjs_hash_fontkey_weak_font sjv_fonthash = { -1 };
sjs_list_u32 sjv_glframebuffers = { -1 };
sjs_list_rect sjv_glviewports = { -1 };
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_shader sjv_imageshader = { -1 };
sjs_rect sjv_looplastrect = { -1 };
sjs_hash_string_weak_iface_model sjv_modelsbyid = { -1 };
sji_element sjv_mouse_captureelement = { 0 };
sjs_shader sjv_phongcolorshader = { -1 };
sjs_shader sjv_phongtextureshader = { -1 };
sji_element sjv_root = { 0 };
sjs_controller* sjv_rootcontroller = 0;
sjs_scene2d sjv_rootscene = { -1 };
sjs_windowrenderer sjv_rootwindowrenderer = { -1 };
sjs_shader sjv_saturateshader = { -1 };
sjs_anon2 sjv_style = { -1 };
sjs_shader sjv_textshader = { -1 };
uint32_t sjv_u32_maxvalue;
sjs_string sjv_vertex_location_texture_normal_format = { -1 };

void sjf_anon1(sjs_anon1* _this);
void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* _from);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_heap(sjs_anon1* _this);
void sjf_anon1_nextframe(sjs_anon1* _parent, int32_t time);
void sjf_anon2(sjs_anon2* _this);
void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* _from);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon2_getfont_heap(sjs_anon2* _parent, sjs_font** _return);
void sjf_anon2_heap(sjs_anon2* _this);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_array_char_setat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_gridunit(sjs_array_gridunit* _this);
void sjf_array_gridunit_copy(sjs_array_gridunit* _this, sjs_array_gridunit* _from);
void sjf_array_gridunit_destroy(sjs_array_gridunit* _this);
void sjf_array_gridunit_getat(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit* _return);
void sjf_array_gridunit_heap(sjs_array_gridunit* _this);
void sjf_array_gridunit_initat(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit* item);
void sjf_array_heap_iface_animation(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_animation_copy(sjs_array_heap_iface_animation* _this, sjs_array_heap_iface_animation* _from);
void sjf_array_heap_iface_animation_destroy(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_animation_getat_heap(sjs_array_heap_iface_animation* _parent, int32_t index, sji_animation* _return);
void sjf_array_heap_iface_animation_heap(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_element(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_copy(sjs_array_heap_iface_element* _this, sjs_array_heap_iface_element* _from);
void sjf_array_heap_iface_element_destroy(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_getat_heap(sjs_array_heap_iface_element* _parent, int32_t index, sji_element* _return);
void sjf_array_heap_iface_element_heap(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_initat(sjs_array_heap_iface_element* _parent, int32_t index, sji_element item);
void sjf_array_heap_iface_model(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from);
void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_rect(sjs_array_rect* _this);
void sjf_array_rect_copy(sjs_array_rect* _this, sjs_array_rect* _from);
void sjf_array_rect_destroy(sjs_array_rect* _this);
void sjf_array_rect_getat(sjs_array_rect* _parent, int32_t index, sjs_rect* _return);
void sjf_array_rect_grow(sjs_array_rect* _parent, int32_t newsize, sjs_array_rect* _return);
void sjf_array_rect_grow_heap(sjs_array_rect* _parent, int32_t newsize, sjs_array_rect** _return);
void sjf_array_rect_heap(sjs_array_rect* _this);
void sjf_array_rect_initat(sjs_array_rect* _parent, int32_t index, sjs_rect* item);
void sjf_array_u32(sjs_array_u32* _this);
void sjf_array_u32_copy(sjs_array_u32* _this, sjs_array_u32* _from);
void sjf_array_u32_destroy(sjs_array_u32* _this);
void sjf_array_u32_heap(sjs_array_u32* _this);
void sjf_buttonelement_as_sji_clickable(sjs_buttonelement* _this, sji_clickable* _return);
void sjf_buttonelement_as_sji_element(sjs_buttonelement* _this, sji_element* _return);
void sjf_buttonelement_asinterface(sjs_buttonelement* _this, int typeId, sjs_interface* _return);
void sjf_buttonelement_copy(sjs_buttonelement* _this, sjs_buttonelement* _from);
void sjf_buttonelement_destroy(sjs_buttonelement* _this);
void sjf_buttonelement_firemouseevent(sjs_buttonelement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_buttonelement_getrect(sjs_buttonelement* _parent, sjs_rect* _return);
void sjf_buttonelement_getrect_heap(sjs_buttonelement* _parent, sjs_rect** _return);
void sjf_buttonelement_getsize(sjs_buttonelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_buttonelement_getsize_heap(sjs_buttonelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_buttonelement_heap(sjs_buttonelement* _this);
void sjf_buttonelement_onclickgestureclick(sjs_buttonelement* _parent, sji_element element);
void sjf_buttonelement_onclickgestureenter(sjs_buttonelement* _parent, sji_element element);
void sjf_buttonelement_onclickgestureleave(sjs_buttonelement* _parent, sji_element element);
void sjf_buttonelement_onclickgesturepress(sjs_buttonelement* _parent, sji_element element);
void sjf_buttonelement_render(sjs_buttonelement* _parent, sjs_scene2d* scene);
void sjf_buttonelement_setrect(sjs_buttonelement* _parent, sjs_rect* rect_);
void sjf_clickgesture(sjs_clickgesture* _this);
void sjf_clickgesture_copy(sjs_clickgesture* _this, sjs_clickgesture* _from);
void sjf_clickgesture_destroy(sjs_clickgesture* _this);
void sjf_clickgesture_firemouseevent(sjs_clickgesture* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_clickgesture_getstate(sjs_clickgesture* _parent, int32_t* _return);
void sjf_clickgesture_heap(sjs_clickgesture* _this);
void sjf_color(sjs_color* _this);
void sjf_color_copy(sjs_color* _this, sjs_color* _from);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color* _this);
void sjf_console_writeline(sjs_string* data);
void sjf_controller(sjs_controller* _this);
void sjf_controller_button1clicked(sjs_controller* _parent);
void sjf_controller_copy(sjs_controller* _this, sjs_controller* _from);
void sjf_controller_destroy(sjs_controller* _this);
void sjf_controller_heap(sjs_controller* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_f32_hash(float val, uint32_t* _return);
void sjf_font(sjs_font* _this);
void sjf_font_copy(sjs_font* _this, sjs_font* _from);
void sjf_font_destroy(sjs_font* _this);
void sjf_font_gettextsize(sjs_font* _parent, sjs_string* str, sjs_size* _return);
void sjf_font_gettextsize_heap(sjs_font* _parent, sjs_string* str, sjs_size** _return);
void sjf_font_heap(sjs_font* _this);
void sjf_font_load_heap(sjs_string* src, float size, sjs_font** _return);
void sjf_fontkey(sjs_fontkey* _this);
void sjf_fontkey_copy(sjs_fontkey* _this, sjs_fontkey* _from);
void sjf_fontkey_destroy(sjs_fontkey* _this);
void sjf_fontkey_hash(sjs_fontkey* _parent, uint32_t* _return);
void sjf_fontkey_heap(sjs_fontkey* _this);
void sjf_fontkey_isequal(sjs_fontkey* _parent, sjs_fontkey* x, bool* _return);
void sjf_glbindtexture(int32_t type, sjs_texture* texture);
void sjf_glblendfunc(int32_t sfactor, int32_t dfactor);
void sjf_glclearcolor(sjs_color* color);
void sjf_glenable(int32_t feature);
void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return);
void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect);
void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect);
void sjf_gluniformi32(int32_t loc, int32_t v);
void sjf_gluniformmat4(int32_t loc, sjs_mat4* m);
void sjf_gluseprogram(sjs_shader* shader);
void sjf_gridlayout(sjs_gridlayout* _this);
void sjf_gridlayout_as_sji_element(sjs_gridlayout* _this, sji_element* _return);
void sjf_gridlayout_asinterface(sjs_gridlayout* _this, int typeId, sjs_interface* _return);
void sjf_gridlayout_copy(sjs_gridlayout* _this, sjs_gridlayout* _from);
void sjf_gridlayout_destroy(sjs_gridlayout* _this);
void sjf_gridlayout_firemouseevent(sjs_gridlayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_gridlayout_getrect(sjs_gridlayout* _parent, sjs_rect* _return);
void sjf_gridlayout_getrect_heap(sjs_gridlayout* _parent, sjs_rect** _return);
void sjf_gridlayout_getsize(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_gridlayout_getsize_heap(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_gridlayout_heap(sjs_gridlayout* _this);
void sjf_gridlayout_render(sjs_gridlayout* _parent, sjs_scene2d* scene);
void sjf_gridlayout_setrect(sjs_gridlayout* _parent, sjs_rect* rect_);
void sjf_gridunit(sjs_gridunit* _this);
void sjf_gridunit_copy(sjs_gridunit* _this, sjs_gridunit* _from);
void sjf_gridunit_destroy(sjs_gridunit* _this);
void sjf_gridunit_heap(sjs_gridunit* _this);
void sjf_halt(sjs_string* reason);
void sjf_hash_fontkey_weak_font(sjs_hash_fontkey_weak_font* _this);
void sjf_hash_fontkey_weak_font__weakptrremovekey(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key);
void sjf_hash_fontkey_weak_font__weakptrremovevalue(sjs_hash_fontkey_weak_font* _parent, sjs_font* val);
void sjf_hash_fontkey_weak_font_copy(sjs_hash_fontkey_weak_font* _this, sjs_hash_fontkey_weak_font* _from);
void sjf_hash_fontkey_weak_font_destroy(sjs_hash_fontkey_weak_font* _this);
void sjf_hash_fontkey_weak_font_getat(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font** _return);
void sjf_hash_fontkey_weak_font_heap(sjs_hash_fontkey_weak_font* _this);
void sjf_hash_fontkey_weak_font_setat(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font* val);
void sjf_hash_string_weak_iface_element(sjs_hash_string_weak_iface_element* _this);
void sjf_hash_string_weak_iface_element__weakptrremovekey(sjs_hash_string_weak_iface_element* _parent, sjs_string* key);
void sjf_hash_string_weak_iface_element__weakptrremovevalue(sjs_hash_string_weak_iface_element* _parent, sji_element val);
void sjf_hash_string_weak_iface_element_copy(sjs_hash_string_weak_iface_element* _this, sjs_hash_string_weak_iface_element* _from);
void sjf_hash_string_weak_iface_element_destroy(sjs_hash_string_weak_iface_element* _this);
void sjf_hash_string_weak_iface_element_getat(sjs_hash_string_weak_iface_element* _parent, sjs_string* key, sji_element* _return);
void sjf_hash_string_weak_iface_element_heap(sjs_hash_string_weak_iface_element* _this);
void sjf_hash_string_weak_iface_element_setat(sjs_hash_string_weak_iface_element* _parent, sjs_string* key, sji_element val);
void sjf_hash_string_weak_iface_model(sjs_hash_string_weak_iface_model* _this);
void sjf_hash_string_weak_iface_model__weakptrremovekey(sjs_hash_string_weak_iface_model* _parent, sjs_string* key);
void sjf_hash_string_weak_iface_model__weakptrremovevalue(sjs_hash_string_weak_iface_model* _parent, sji_model val);
void sjf_hash_string_weak_iface_model_copy(sjs_hash_string_weak_iface_model* _this, sjs_hash_string_weak_iface_model* _from);
void sjf_hash_string_weak_iface_model_destroy(sjs_hash_string_weak_iface_model* _this);
void sjf_hash_string_weak_iface_model_heap(sjs_hash_string_weak_iface_model* _this);
void sjf_i32_asmargin(int32_t x, sjs_margin* _return);
void sjf_i32_asmargin_heap(int32_t x, sjs_margin** _return);
void sjf_i32_asstring(int32_t val, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, sjs_string** _return);
void sjf_i32_max(int32_t a, int32_t b, int32_t* _return);
void sjf_image(sjs_image* _this);
void sjf_image_copy(sjs_image* _this, sjs_image* _from);
void sjf_image_destroy(sjs_image* _this);
void sjf_image_heap(sjs_image* _this);
void sjf_imagerenderer(sjs_imagerenderer* _this);
void sjf_imagerenderer_copy(sjs_imagerenderer* _this, sjs_imagerenderer* _from);
void sjf_imagerenderer_destroy(sjs_imagerenderer* _this);
void sjf_imagerenderer_heap(sjs_imagerenderer* _this);
void sjf_imagerenderer_render(sjs_imagerenderer* _parent, sjs_scene2d* scene);
void sjf_light(sjs_light* _this);
void sjf_light_copy(sjs_light* _this, sjs_light* _from);
void sjf_light_destroy(sjs_light* _this);
void sjf_light_heap(sjs_light* _this);
void sjf_list_heap_iface_animation(sjs_list_heap_iface_animation* _this);
void sjf_list_heap_iface_animation_copy(sjs_list_heap_iface_animation* _this, sjs_list_heap_iface_animation* _from);
void sjf_list_heap_iface_animation_destroy(sjs_list_heap_iface_animation* _this);
void sjf_list_heap_iface_animation_getat_heap(sjs_list_heap_iface_animation* _parent, int32_t index, sji_animation* _return);
void sjf_list_heap_iface_animation_getcount(sjs_list_heap_iface_animation* _parent, int32_t* _return);
void sjf_list_heap_iface_animation_heap(sjs_list_heap_iface_animation* _this);
void sjf_list_heap_iface_animation_removeat(sjs_list_heap_iface_animation* _parent, int32_t index);
void sjf_list_heap_iface_model(sjs_list_heap_iface_model* _this);
void sjf_list_heap_iface_model_copy(sjs_list_heap_iface_model* _this, sjs_list_heap_iface_model* _from);
void sjf_list_heap_iface_model_destroy(sjs_list_heap_iface_model* _this);
void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this);
void sjf_list_rect(sjs_list_rect* _this);
void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item);
void sjf_list_rect_copy(sjs_list_rect* _this, sjs_list_rect* _from);
void sjf_list_rect_destroy(sjs_list_rect* _this);
void sjf_list_rect_getat(sjs_list_rect* _parent, int32_t index, sjs_rect* _return);
void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return);
void sjf_list_rect_heap(sjs_list_rect* _this);
void sjf_list_rect_removeat(sjs_list_rect* _parent, int32_t index);
void sjf_list_u32(sjs_list_u32* _this);
void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from);
void sjf_list_u32_destroy(sjs_list_u32* _this);
void sjf_list_u32_heap(sjs_list_u32* _this);
void sjf_mainloop(void);
void sjf_margin(sjs_margin* _this);
void sjf_margin_copy(sjs_margin* _this, sjs_margin* _from);
void sjf_margin_destroy(sjs_margin* _this);
void sjf_margin_heap(sjs_margin* _this);
void sjf_mat4(sjs_mat4* _this);
void sjf_mat4_copy(sjs_mat4* _this, sjs_mat4* _from);
void sjf_mat4_destroy(sjs_mat4* _this);
void sjf_mat4_heap(sjs_mat4* _this);
void sjf_mat4_identity(sjs_mat4* _return);
void sjf_mat4_identity_heap(sjs_mat4** _return);
void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return);
void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return);
void sjf_mat4_scale(float x, float y, float z, sjs_mat4* _return);
void sjf_mat4_scale_heap(float x, float y, float z, sjs_mat4** _return);
void sjf_mouse_capture(sji_element element);
void sjf_mouse_hascapture(sji_element element, bool* _return);
void sjf_mouse_release(sji_element element);
void sjf_mouseevent(sjs_mouseevent* _this);
void sjf_mouseevent_copy(sjs_mouseevent* _this, sjs_mouseevent* _from);
void sjf_mouseevent_destroy(sjs_mouseevent* _this);
void sjf_mouseevent_firechildren(sjs_mouseevent* _parent, sjs_array_heap_iface_element* children, bool* _return);
void sjf_mouseevent_heap(sjs_mouseevent* _this);
void sjf_point(sjs_point* _this);
void sjf_point_copy(sjs_point* _this, sjs_point* _from);
void sjf_point_destroy(sjs_point* _this);
void sjf_point_heap(sjs_point* _this);
void sjf_rect(sjs_rect* _this);
void sjf_rect_containspoint(sjs_rect* _parent, sjs_point* point, bool* _return);
void sjf_rect_copy(sjs_rect* _this, sjs_rect* _from);
void sjf_rect_destroy(sjs_rect* _this);
void sjf_rect_heap(sjs_rect* _this);
void sjf_rect_isequal(sjs_rect* _parent, sjs_rect* rect, bool* _return);
void sjf_rect_subtractmargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return);
void sjf_rect_subtractmargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect** _return);
void sjf_runloop(void);
void sjf_scene2d(sjs_scene2d* _this);
void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from);
void sjf_scene2d_destroy(sjs_scene2d* _this);
void sjf_scene2d_end(sjs_scene2d* _parent);
void sjf_scene2d_heap(sjs_scene2d* _this);
void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size);
void sjf_scene2d_start(sjs_scene2d* _parent);
void sjf_shader(sjs_shader* _this);
void sjf_shader_copy(sjs_shader* _this, sjs_shader* _from);
void sjf_shader_destroy(sjs_shader* _this);
void sjf_shader_heap(sjs_shader* _this);
void sjf_size(sjs_size* _this);
void sjf_size_addmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return);
void sjf_size_addmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return);
void sjf_size_copy(sjs_size* _this, sjs_size* _from);
void sjf_size_destroy(sjs_size* _this);
void sjf_size_heap(sjs_size* _this);
void sjf_size_isequal(sjs_size* _parent, sjs_size* size, bool* _return);
void sjf_size_min(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_size_min_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return);
void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_hash(sjs_string* _parent, uint32_t* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return);
void sjf_textelement_as_sji_element(sjs_textelement* _this, sji_element* _return);
void sjf_textelement_as_sji_textelement(sjs_textelement* _this, sji_textelement* _return);
void sjf_textelement_asinterface(sjs_textelement* _this, int typeId, sjs_interface* _return);
void sjf_textelement_copy(sjs_textelement* _this, sjs_textelement* _from);
void sjf_textelement_destroy(sjs_textelement* _this);
void sjf_textelement_firemouseevent(sjs_textelement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_textelement_getrect(sjs_textelement* _parent, sjs_rect* _return);
void sjf_textelement_getrect_heap(sjs_textelement* _parent, sjs_rect** _return);
void sjf_textelement_getsize(sjs_textelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_textelement_getsize_heap(sjs_textelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_textelement_gettext(sjs_textelement* _parent, sjs_string* _return);
void sjf_textelement_gettext_heap(sjs_textelement* _parent, sjs_string** _return);
void sjf_textelement_heap(sjs_textelement* _this);
void sjf_textelement_render(sjs_textelement* _parent, sjs_scene2d* scene);
void sjf_textelement_setrect(sjs_textelement* _parent, sjs_rect* rect_);
void sjf_textelement_settext(sjs_textelement* _parent, sjs_string* text_);
void sjf_textrenderer(sjs_textrenderer* _this);
void sjf_textrenderer_copy(sjs_textrenderer* _this, sjs_textrenderer* _from);
void sjf_textrenderer_destroy(sjs_textrenderer* _this);
void sjf_textrenderer_heap(sjs_textrenderer* _this);
void sjf_textrenderer_render(sjs_textrenderer* _parent, sjs_scene2d* scene);
void sjf_texture(sjs_texture* _this);
void sjf_texture_copy(sjs_texture* _this, sjs_texture* _from);
void sjf_texture_destroy(sjs_texture* _this);
void sjf_texture_frompng(sjs_string* filename, sjs_texture* _return);
void sjf_texture_frompng_heap(sjs_string* filename, sjs_texture** _return);
void sjf_texture_getsize(sjs_texture* _parent, sjs_size* _return);
void sjf_texture_getsize_heap(sjs_texture* _parent, sjs_size** _return);
void sjf_texture_heap(sjs_texture* _this);
void sjf_vec3(sjs_vec3* _this);
void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from);
void sjf_vec3_destroy(sjs_vec3* _this);
void sjf_vec3_heap(sjs_vec3* _this);
void sjf_windowrenderer(sjs_windowrenderer* _this);
void sjf_windowrenderer_copy(sjs_windowrenderer* _this, sjs_windowrenderer* _from);
void sjf_windowrenderer_destroy(sjs_windowrenderer* _this);
void sjf_windowrenderer_getsize(sjs_windowrenderer* _parent, sjs_size* _return);
void sjf_windowrenderer_getsize_heap(sjs_windowrenderer* _parent, sjs_size** _return);
void sjf_windowrenderer_heap(sjs_windowrenderer* _this);
void sjf_windowrenderer_present(sjs_windowrenderer* _parent);
void main_destroy(void);

void halt(const char * format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    exit(-1);
}
void ptr_hash(void* p, uint32_t* result) {
    #ifdef __32__
    *result = kh_int_hash_func((uintptr_t)p);
    #else
    *result = kh_int64_hash_func((uintptr_t)p);
    #endif
}
void ptr_isequal(void *p1, void* p2, bool* result) {
    *result = (p1 == p2);
}
void delete_cb_list_free(delete_cb_list* d) {
    if (d->next) {
        delete_cb_list_free(d->next);
    }
    free(d);
}
void delete_cb_list_add(delete_cb_list* d, delete_cb cb) {
    if (d->size < 5) {
        d->cb[d->size] = cb;
        d->size++;
    }
    else {
        if (!d->next) {
            d->next = (delete_cb_list*)malloc(sizeof(delete_cb_list));
        }
        delete_cb_list_add(d->next, cb);
    }
}
void delete_cb_list_remove(delete_cb_list* d, delete_cb cb) {
    for (int i = 0; i < d->size; i++) {
        if (d->cb[i]._parent == cb._parent && d->cb[i]._cb == cb._cb) {
            for (int j = i; j < d->size - 1; j++) {
                d->cb[j] = d->cb[j + 1];
            }
            d->size--;
        }
    }
    if (d->next) {
        delete_cb_list_remove(d->next, cb);
    }
}
void delete_cb_list_invoke(delete_cb_list* d, void* p) {
    for (int i = 0; i < d->size; i++) {
        d->cb[i]._cb(d->cb[i]._parent, p);
    }
    if (d->next) {
        delete_cb_list_invoke(d->next, p);
    }
}
KHASH_INIT_TYPEDEF(weakptr_hashtable_type, void*, delete_cb_list)
KHASH_INIT_FUNCTION(weakptr_hashtable_type, void*, delete_cb_list, 1, ptr_hash, ptr_isequal)
khash_t(weakptr_hashtable_type)* weakptr_hashtable;
void weakptr_init() {
    weakptr_hashtable = kh_init(weakptr_hashtable_type);
}
void weakptr_release(void* v) {
    khiter_t k = kh_get(weakptr_hashtable_type, weakptr_hashtable, v);
    if (k != kh_end(weakptr_hashtable)) {
        delete_cb_list* d = &kh_value(weakptr_hashtable, k);
        delete_cb_list_invoke(d, v);
        if (d->next) {
            delete_cb_list_free(d->next);
        }
        kh_del(weakptr_hashtable_type, weakptr_hashtable, k);
    }
}
void weakptr_cb_add(void* v, delete_cb cb) {
    delete_cb_list* d;
    khiter_t k = kh_get(weakptr_hashtable_type, weakptr_hashtable, v);
    if (k == kh_end(weakptr_hashtable)) {
        int ret;
        khiter_t k = kh_put(weakptr_hashtable_type, weakptr_hashtable, v, &ret);
        if (!ret) kh_del(weakptr_hashtable_type, weakptr_hashtable, k);
        d = &kh_value(weakptr_hashtable, k);
        d->size = 0;
        d->next = 0;
    }
    else {
        d = &kh_value(weakptr_hashtable, k);
    }
    delete_cb_list_add(d, cb);
}
void weakptr_cb_remove(void* v, delete_cb cb) {
    khiter_t k = kh_get(weakptr_hashtable_type, weakptr_hashtable, v);
    if (k != kh_end(weakptr_hashtable)) {
        delete_cb_list* d = &kh_value(weakptr_hashtable, k);
        delete_cb_list_remove(d, cb);
    }
}
KHASH_INIT_TYPEDEF(ptr_hashtable_type, void*, int)
KHASH_INIT_FUNCTION(ptr_hashtable_type, void*, int, 1, ptr_hash, ptr_isequal)
khash_t(ptr_hashtable_type)* ptr_hashtable;
void ptr_init() {
    ptr_hashtable = kh_init(ptr_hashtable_type);
}
void ptr_retain(void* v) {
    khiter_t k = kh_get(ptr_hashtable_type, ptr_hashtable, v);
    if (k == kh_end(ptr_hashtable)) {
        int ret;
        khiter_t k = kh_put(ptr_hashtable_type, ptr_hashtable, v, &ret);
        if (!ret) kh_del(ptr_hashtable_type, ptr_hashtable, k);
        kh_value(ptr_hashtable, k) = 1;
    }
    else {
        kh_value(ptr_hashtable, k)++;
    }
}
bool ptr_release(void* v) {
    khiter_t k = kh_get(ptr_hashtable_type, ptr_hashtable, v);
    if (k != kh_end(ptr_hashtable)) {
        kh_value(ptr_hashtable, k)--;
        if (kh_value(ptr_hashtable, k) == 0) {
            kh_del(ptr_hashtable_type, ptr_hashtable, k);
        }
        return false;
    }
    return true;
}
void weakptr_clear(void* parent, void* v) {
    void** p = (void**)parent;
    if (*p != v) {
        halt("weakptr was changed without clearing callback");
    }
    *p = 0;
}
#ifndef string_weak_iface_model_hash_function
#define string_weak_iface_model_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_weak_iface_model_hash_type, sjs_string, sji_model, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_weak_iface_model_hash_type, sjs_string, sji_model, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
#ifndef string_weak_iface_model_hash_function
#define string_weak_iface_model_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_weak_iface_model_hash_type, sjs_string, sji_model, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_weak_iface_model_hash_type, sjs_string, sji_model, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
#ifndef string_weak_iface_element_hash_function
#define string_weak_iface_element_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_weak_iface_element_hash_type, sjs_string, sji_element, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_weak_iface_element_hash_type, sjs_string, sji_element, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
#ifndef string_weak_iface_element_hash_function
#define string_weak_iface_element_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_weak_iface_element_hash_type, sjs_string, sji_element, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_weak_iface_element_hash_type, sjs_string, sji_element, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
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
    // Avoid edges where the kernels would spill over
    for(i = 1; i < h-1; i++) {
        for(j = 1; j < w-1; j++) {
            k = i*w + j;
            // Compute gradient for edge pixels only
            if((img[k]>0.0) && (img[k]<1.0)) {
                gx[k] = -img[k-w-1] - SQRT2*img[k-1] - img[k+w-1] + img[k-w+1] + SQRT2*img[k+1] + img[k+w+1];
                gy[k] = -img[k-w-1] - SQRT2*img[k-w] - img[k-w+1] + img[k+w-1] + SQRT2*img[k+w] + img[k+w+1];
                glength = gx[k]*gx[k] + gy[k]*gy[k];
                if(glength > 0.0) {
                    // Avoid division by zero
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
    // Either A) gu or gv are zero, or B) both
    if ((gx == 0) || (gy == 0)) {
        // Linear approximation is A) correct or B) a fair guess
        df = 0.5-a;  
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
        if (a < a1) {
            // 0 <= a < a1
            df = 0.5*(gx + gy) - sqrt(2.0*gx*gy*a);
        } else if (a < (1.0-a1)) {
            // a1 <= a <= 1-a1
            df = (0.5-a)*gx;
        } else {
            // 1-a1 < a <= 1
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
    if(di==0) {
        // Use local gradient only at edges
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
#ifndef fontkey_weak_font_hash_function
#define fontkey_weak_font_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*, 1, sjf_fontkey_hash, sjf_fontkey_isequal)
#else
KHASH_INIT_FUNCTION(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*, 1, sjf_fontkey_hash, sjf_fontkey_isequal)
#endif
#endif
#ifndef fontkey_weak_font_hash_function
#define fontkey_weak_font_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*, 1, sjf_fontkey_hash, sjf_fontkey_isequal)
#else
KHASH_INIT_FUNCTION(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*, 1, sjf_fontkey_hash, sjf_fontkey_isequal)
#endif
#endif
KHASH_INIT_TYPEDEF(glid_hash_type, GLuint, int)
KHASH_INIT_FUNCTION(glid_hash_type, GLuint, int, 1, glid_gethash, glid_isequal)
khash_t(glid_hash_type)* glid_hash;
void glid_gethash(GLuint id, uint32_t* result) {
    *result = kh_int_hash_func(id);
}
void glid_isequal(GLuint id1, GLuint id2, bool* result) {
    *result = (id2 == id2);
}
void glid_init() {
    glid_hash = kh_init(glid_hash_type);
}
void glid_retain(GLuint id) {
    khiter_t k = kh_get(glid_hash_type, glid_hash, id);
    if (k == kh_end(glid_hash)) {
        int ret;
        khiter_t k = kh_put(glid_hash_type, glid_hash, id, &ret);
        if (!ret) kh_del(glid_hash_type, glid_hash, k);
        kh_value(glid_hash, k) = 1;
    }
    else {
        kh_value(glid_hash, k)++;
    }
}
bool glid_release(GLuint id) {
    khiter_t k = kh_get(glid_hash_type, glid_hash, id);
    if (k != kh_end(glid_hash)) {
        kh_value(glid_hash, k)--;
        if (kh_value(glid_hash, k) == 0) {
            kh_del(glid_hash_type, glid_hash, k);
        }
        return false;
    }
    return true;
}
char *repl_str(const char *str, const char *from, const char *to) {
    /* Adjust each of the below values to suit your needs. */
    /* Increment positions cache size initially by this number. */
    size_t cache_sz_inc = 16;
    /* Thereafter, each time capacity needs to be increased,
    * multiply the increment by this factor. */
    const size_t cache_sz_inc_factor = 3;
    /* But never increment capacity by more than this number. */
    const size_t cache_sz_inc_max = 1048576;
    char *pret, *ret = NULL;
    const char *pstr2, *pstr = str;
    size_t i, count = 0;
    #if (__STDC_VERSION__ >= 199901L)
    uintptr_t *pos_cache_tmp, *pos_cache = NULL;
    #else
    ptrdiff_t *pos_cache_tmp, *pos_cache = NULL;
    #endif
    size_t cache_sz = 0;
    size_t cpylen, orglen, retlen, tolen = 0, fromlen = strlen(from);
    /* Find all matches and cache their positions. */
    while ((pstr2 = strstr(pstr, from)) != NULL) {
        count++;
        /* Increase the cache size when necessary. */
        if (cache_sz < count) {
            cache_sz += cache_sz_inc;
            pos_cache_tmp = realloc(pos_cache, sizeof(*pos_cache) * cache_sz);
            if (pos_cache_tmp == NULL) {
                goto end_repl_str;
            } else pos_cache = pos_cache_tmp;
            cache_sz_inc *= cache_sz_inc_factor;
            if (cache_sz_inc > cache_sz_inc_max) {
                cache_sz_inc = cache_sz_inc_max;
            }
        }
        pos_cache[count-1] = pstr2 - str;
        pstr = pstr2 + fromlen;
    }
    orglen = pstr - str + strlen(pstr);
    /* Allocate memory for the post-replacement string. */
    if (count > 0) {
        tolen = strlen(to);
        retlen = orglen + (tolen - fromlen) * count;
    } else  retlen = orglen;
    ret = malloc(retlen + 1);
    if (ret == NULL) {
        goto end_repl_str;
    }
    if (count == 0) {
        /* If no matches, then just duplicate the string. */
        strcpy(ret, str);
    } else {
        /* Otherwise, duplicate the string whilst performing
        * the replacements using the position cache. */
        pret = ret;
        memcpy(pret, str, pos_cache[0]);
        pret += pos_cache[0];
        for (i = 0; i < count; i++) {
            memcpy(pret, to, tolen);
            pret += tolen;
            pstr = str + pos_cache[i] + fromlen;
            cpylen = (i == count-1 ? orglen : pos_cache[i+1]) - pos_cache[i] - fromlen;
            memcpy(pret, pstr, cpylen);
            pret += cpylen;
        }
        ret[retlen] = '\0';
    }
    end_repl_str:
    /* Free the cache and return the post-replacement string,
    * which will be NULL in the event of an error. */
    free(pos_cache);
    return ret;
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
        #ifdef __APPLE__
        char* prev = buffer;
        buffer = repl_str(buffer, "mediump", "");
        free(prev);
        #endif
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
            halt("%s: %s\n", source, messages);
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
            halt("%s\n", messages );
        }
        return handle;
    }
    void add_text(vertex_buffer_t * buffer, texture_font_t * font, char *text, vec4 * color, vec2 * pen) {
        pen->y += (float)(int)font->ascender;
        size_t i;
        float r = color->red, g = color->green, b = color->blue, a = color->alpha;
        for (i = 0; i < strlen(text); ++i) {
            texture_glyph_t *glyph = texture_font_get_glyph( font, text + i );
            if (glyph != NULL) {
                float kerning = 0.0f;
                if( i > 0) {
                    kerning = texture_glyph_get_kerning( glyph, text + i - 1 );
                }
                pen->x += kerning;
                float x0 = (float)(int)( pen->x + glyph->offset_x );
                float y0 = (float)(int)( pen->y + glyph->height - glyph->offset_y );
                float x1 = (float)(int)( x0 + glyph->width );
                float y1 = (float)(int)( y0 - glyph->height );
                float s0 = glyph->s0;
                float t0 = glyph->t0;
                float s1 = glyph->s1;
                float t1 = glyph->t1;
                GLuint index = (GLuint)buffer->vertices->size;
                GLuint indices[] = { //
                index, index+1, index+2,
                index, index+2, index+3 };
                vertex3_texture2_color3_t vertices[] = { //
                { x0, y1, 0.0f,  s0,t0,  r,g,b,a },
                { x0, y0, 0.0f,  s0,t1,  r,g,b,a },
                { x1, y0, 0.0f,  s1,t1,  r,g,b,a },
                { x1, y1, 0.0f,  s1,t0,  r,g,b,a } };
                vertex_buffer_push_back_indices( buffer, indices, 6 );
                vertex_buffer_push_back_vertices( buffer, vertices, 4 );
                pen->x += glyph->advance_x;
            }
        }
    }   
    vec2 get_text_size(texture_font_t * font, char *text) {
        vec2 size = {{ 0, font->height }};
        size_t i;
        for( i = 0; i < strlen(text); ++i ) {
            texture_glyph_t *glyph = texture_font_get_glyph(font, text + i);
            if (glyph != NULL) {
                float kerning = 0.0f;
                if( i > 0) {
                    kerning = texture_glyph_get_kerning(glyph, text + i - 1);
                }
                size.x += kerning;
                size.x += glyph->advance_x;
            }
        }
        return size;
    }   
    GLuint png_texture_load(const char * file_name, int * width, int * height)
    {
        // This function was originally written by David Grayson for
        // https://github.com/DavidEGrayson/ahrs-visualizer
        png_byte header[8];
        FILE *fp = fopen(file_name, "rb");
        if (fp == 0)
        {
            perror(file_name);
            return 0;
        }
        // read the header
        fread(header, 1, 8, fp);
        if (png_sig_cmp(header, 0, 8))
        {
            fprintf(stderr, "error: %s is not a PNG.\n", file_name);
            fclose(fp);
            return 0;
        }
        png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
        if (!png_ptr)
        {
            fprintf(stderr, "error: png_create_read_struct returned 0.\n");
            fclose(fp);
            return 0;
        }
        // create png info struct
        png_infop info_ptr = png_create_info_struct(png_ptr);
        if (!info_ptr)
        {
            fprintf(stderr, "error: png_create_info_struct returned 0.\n");
            png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
            fclose(fp);
            return 0;
        }
        // create png info struct
        png_infop end_info = png_create_info_struct(png_ptr);
        if (!end_info)
        {
            fprintf(stderr, "error: png_create_info_struct returned 0.\n");
            png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
            fclose(fp);
            return 0;
        }
        // the code in this if statement gets called if libpng encounters an error
        if (setjmp(png_jmpbuf(png_ptr))) {
            fprintf(stderr, "error from libpng\n");
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            fclose(fp);
            return 0;
        }
        // init png reading
        png_init_io(png_ptr, fp);
        // let libpng know you already read the first 8 bytes
        png_set_sig_bytes(png_ptr, 8);
        // read all the info up to the image data
        png_read_info(png_ptr, info_ptr);
        // variables to pass to get info
        int bit_depth, color_type;
        png_uint_32 temp_width, temp_height;
        // get info about png
        png_get_IHDR(png_ptr, info_ptr, &temp_width, &temp_height, &bit_depth, &color_type,
        NULL, NULL, NULL);
        if (width){ *width = temp_width; }
        if (height){ *height = temp_height; }
        //printf("%s: %lux%lu %d\n", file_name, temp_width, temp_height, color_type);
        if (bit_depth != 8)
        {
            fprintf(stderr, "%s: Unsupported bit depth %d.  Must be 8.\n", file_name, bit_depth);
            return 0;
        }
        GLint format;
        switch(color_type)
        {
            case PNG_COLOR_TYPE_RGB:
            format = GL_RGB;
            break;
            case PNG_COLOR_TYPE_RGB_ALPHA:
            format = GL_RGBA;
            break;
            default:
            fprintf(stderr, "%s: Unknown libpng color type %d.\n", file_name, color_type);
            return 0;
        }
        // Update the png info struct.
        png_read_update_info(png_ptr, info_ptr);
        // Row size in bytes.
        int rowbytes = png_get_rowbytes(png_ptr, info_ptr);
        // glTexImage2d requires rows to be 4-byte aligned
        rowbytes += 3 - ((rowbytes-1) % 4);
        // Allocate the image_data as a big block, to be given to opengl
        png_byte * image_data = (png_byte *)malloc(rowbytes * temp_height * sizeof(png_byte)+15);
        if (image_data == NULL)
        {
            fprintf(stderr, "error: could not allocate memory for PNG image data\n");
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            fclose(fp);
            return 0;
        }
        // row_pointers is for pointing to image_data for reading the png with libpng
        png_byte ** row_pointers = (png_byte **)malloc(temp_height * sizeof(png_byte *));
        if (row_pointers == NULL)
        {
            fprintf(stderr, "error: could not allocate memory for PNG row pointers\n");
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            free(image_data);
            fclose(fp);
            return 0;
        }
        // set the individual row_pointers to point at the correct offsets of image_data
        for (unsigned int i = 0; i < temp_height; i++)
        {
            row_pointers[temp_height - 1 - i] = image_data + i * rowbytes;
        }
        // read the png into image_data through row_pointers
        png_read_image(png_ptr, row_pointers);
        // Generate the OpenGL texture object
        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexImage2D(GL_TEXTURE_2D, 0, format, temp_width, temp_height, 0, format, GL_UNSIGNED_BYTE, image_data);
        // clean up
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        free(image_data);
        free(row_pointers);
        fclose(fp);
        return texture;
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
            halt("line %d: No more memory for allocating data\n", __LINE__ );
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
            halt("line %d: No more memory for allocating data\n", __LINE__ );
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
            halt("line %d: No more memory for allocating data\n", __LINE__ );
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
    #define HRES  64
    #define HRESf 64.f
    #define DPI   72
    // ------------------------------------------------- texture_font_load_face ---
    static int
    texture_font_load_face(texture_font_t *self, float size,
    FT_Library *library, FT_Face *face)
    {
        FT_Error error;
        FT_Matrix matrix = { //
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
        FT_Glyph ft_glyph = { 0 };
        FT_GlyphSlot slot;
        FT_Bitmap ft_bitmap;
        FT_UInt glyph_index;
        texture_glyph_t *glyph;
        FT_Int32 flags = 0;
        int ft_glyph_top = 0;
        int ft_glyph_left = 0;
        ivec4 region;
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
            unsigned char *sdf = make_distance_mapb( buffer, (unsigned int)tgt_w, (unsigned int)tgt_h );
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
    // ------------------------------------------------------------- vector_new ---
    vector_t *
    vector_new( size_t item_size )
    {
        vector_t *self = (vector_t *) malloc( sizeof(vector_t) );
        assert( item_size );
        if( !self )
        {
            halt("line %d: No more memory for allocating data\n", __LINE__ );
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
    #include <lib/ui/obj_parser.c>
void sjf_anon1(sjs_anon1* _this) {
}

void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* _from) {
    _this->animations._refCount = 1;
    sjf_list_heap_iface_animation_copy(&_this->animations, &_from->animations);
    _this->current = _from->current;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1* _this) {
}

void sjf_anon1_nextframe(sjs_anon1* _parent, int32_t time) {
    int32_t sjt_compare95;
    int32_t sjt_compare96;
    sjs_anon1* sjt_dot293 = 0;
    sjs_anon1* sjt_dot296 = 0;
    bool sjt_ifElse42;
    sjs_list_heap_iface_animation* sjt_parent88 = 0;

    sjt_dot293 = _parent;
    sjt_dot293->current = time;
    sjt_dot296 = _parent;
    sjt_parent88 = &(sjt_dot296)->animations;
    sjf_list_heap_iface_animation_getcount(sjt_parent88, &sjt_compare95);
    sjt_compare96 = 0;
    sjt_ifElse42 = sjt_compare95 > sjt_compare96;
    if (sjt_ifElse42) {
        int32_t i;
        sjs_anon1* sjt_dot297 = 0;
        int32_t sjt_forEnd10;
        int32_t sjt_forStart10;
        sjs_list_heap_iface_animation* sjt_parent89 = 0;

        sjt_forStart10 = 0;
        sjt_dot297 = _parent;
        sjt_parent89 = &(sjt_dot297)->animations;
        sjf_list_heap_iface_animation_getcount(sjt_parent89, &sjt_forEnd10);
        i = sjt_forEnd10 - 1;
        while (i >= sjt_forStart10) {
            sjs_anon1* sjt_dot299 = 0;
            int32_t sjt_functionParam162;
            bool sjt_ifElse43;
            int32_t sjt_interfaceParam9;
            sjs_list_heap_iface_animation* sjt_parent91 = 0;
            sji_animation sjt_parent92 = { 0 };
            sji_animation sjv_a = { 0 };

            sjt_dot299 = _parent;
            sjt_parent91 = &(sjt_dot299)->animations;
            sjt_functionParam162 = i;
            sjf_list_heap_iface_animation_getat_heap(sjt_parent91, sjt_functionParam162, &sjv_a);
            sjt_parent92 = sjv_a;
            sjt_interfaceParam9 = time;
            sjt_parent92._vtbl->nextframe(sjt_parent92._parent, sjt_interfaceParam9, &sjt_ifElse43);
            if (sjt_ifElse43) {
                sjs_anon1* sjt_dot300 = 0;
                int32_t sjt_functionParam163;
                sjs_list_heap_iface_animation* sjt_parent93 = 0;

                sjt_dot300 = _parent;
                sjt_parent93 = &(sjt_dot300)->animations;
                sjt_functionParam163 = i;
                sjf_list_heap_iface_animation_removeat(sjt_parent93, sjt_functionParam163);
            }

            i--;

            if (sjv_a._parent != 0) {
                sjv_a._parent->_refCount--;
                if (sjv_a._parent->_refCount <= 0) {
                    sjv_a._vtbl->destroy(sjv_a._parent);
                    free(sjv_a._parent);
                }
            }
        }
    }
}

void sjf_anon2(sjs_anon2* _this) {
}

void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* _from) {
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_anon2_getfont_heap(sjs_anon2* _parent, sjs_font** _return) {
    sjs_string sjt_call20 = { -1 };
    sjs_string* sjt_functionParam105 = 0;
    float sjt_functionParam106;

    sjt_call20._refCount = 1;
    sjt_call20.count = 16;
    sjt_call20.data._refCount = 1;
    sjt_call20.data.datasize = 17;
    sjt_call20.data.data = (void*)sjg_string17;
    sjt_call20.data._isglobal = true;
    sjt_call20.data.count = 17;
    sjf_array_char(&sjt_call20.data);
    sjf_string(&sjt_call20);
    sjt_functionParam105 = &sjt_call20;
    sjt_functionParam106 = 24.0f;
    sjf_font_load_heap(sjt_functionParam105, sjt_functionParam106, _return);

    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
}

void sjf_anon2_heap(sjs_anon2* _this) {
}

void sjf_array_char(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(char));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            char* p = (char*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    char* p = (char*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    sjs_array_char* sjt_dot234 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(char));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot234 = _parent;
    _return->count = (sjt_dot234)->count;
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    sjs_array_char* sjt_dot235 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(char));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
    }
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot235 = _parent;
    (*_return)->count = (sjt_dot235)->count;
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(char));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    char* p = (char*)_parent->data;
    p[index] = item;
;
    _parent->count = index + 1;
}

void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
    if (_parent->count != test->count) {
        *_return = false;
    }
    bool result = memcmp(_parent->data, test->data, _parent->count * sizeof(char)) == 0;
    (*_return) = result;
return;;      
}

void sjf_array_char_setat(sjs_array_char* _parent, int32_t index, char item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    char* p = (char*)_parent->data;
    ;
    p[index] = item;
;
}

void sjf_array_gridunit(sjs_array_gridunit* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_gridunit));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_gridunit_copy(sjs_array_gridunit* _this, sjs_array_gridunit* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_gridunit_destroy(sjs_array_gridunit* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sjs_gridunit* p = (sjs_gridunit*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_gridunit_getat(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_gridunit* p = (sjs_gridunit*)_parent->data;
    _return->_refCount = 1;
sjf_gridunit_copy(_return, &p[index]);
return;;       
}

void sjf_array_gridunit_heap(sjs_array_gridunit* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_gridunit));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_gridunit_initat(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sjs_gridunit* p = (sjs_gridunit*)_parent->data;
    p[index]._refCount = 1;
sjf_gridunit_copy(&p[index], item);
;
    _parent->count = index + 1;
}

void sjf_array_heap_iface_animation(sjs_array_heap_iface_animation* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_animation));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_iface_animation_copy(sjs_array_heap_iface_animation* _this, sjs_array_heap_iface_animation* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_heap_iface_animation_destroy(sjs_array_heap_iface_animation* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sji_animation* p = (sji_animation*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
            }
            free(p);
        }
    }
}

void sjf_array_heap_iface_animation_getat_heap(sjs_array_heap_iface_animation* _parent, int32_t index, sji_animation* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sji_animation* p = (sji_animation*)_parent->data;
    (*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_animation_heap(sjs_array_heap_iface_animation* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_animation));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_iface_element(sjs_array_heap_iface_element* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_element));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_iface_element_copy(sjs_array_heap_iface_element* _this, sjs_array_heap_iface_element* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_heap_iface_element_destroy(sjs_array_heap_iface_element* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sji_element* p = (sji_element*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
            }
            free(p);
        }
    }
}

void sjf_array_heap_iface_element_getat_heap(sjs_array_heap_iface_element* _parent, int32_t index, sji_element* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sji_element* p = (sji_element*)_parent->data;
    (*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_element_heap(sjs_array_heap_iface_element* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_element));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_iface_element_initat(sjs_array_heap_iface_element* _parent, int32_t index, sji_element item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sji_element* p = (sji_element*)_parent->data;
    p[index] = item;
if (p[index]._parent != 0) {
    p[index]._parent->_refCount++;
}
;
    _parent->count = index + 1;
}

void sjf_array_heap_iface_model(sjs_array_heap_iface_model* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_model));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sji_model* p = (sji_model*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
            }
            free(p);
        }
    }
}

void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_model));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32(sjs_array_i32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(int32_t));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            int32_t* p = (int32_t*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    int32_t* p = (int32_t*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_i32_heap(sjs_array_i32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(int32_t));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    int32_t* p = (int32_t*)_parent->data;
    p[index] = item;
;
    _parent->count = index + 1;
}

void sjf_array_rect(sjs_array_rect* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_rect));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_rect_copy(sjs_array_rect* _this, sjs_array_rect* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_rect_destroy(sjs_array_rect* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sjs_rect* p = (sjs_rect*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_rect_getat(sjs_array_rect* _parent, int32_t index, sjs_rect* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_rect* p = (sjs_rect*)_parent->data;
    _return->_refCount = 1;
sjf_rect_copy(_return, &p[index]);
return;;       
}

void sjf_array_rect_grow(sjs_array_rect* _parent, int32_t newsize, sjs_array_rect* _return) {
    sjs_array_rect* sjt_dot330 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(sjs_rect));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sjs_rect* p = (sjs_rect*)_parent->data;
        sjs_rect* newp = (sjs_rect*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i]._refCount = 1;
sjf_rect_copy(&newp[i], &p[i]);
;
        }
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot330 = _parent;
    _return->count = (sjt_dot330)->count;
    sjf_array_rect(_return);
}

void sjf_array_rect_grow_heap(sjs_array_rect* _parent, int32_t newsize, sjs_array_rect** _return) {
    sjs_array_rect* sjt_dot331 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(sjs_rect));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sjs_rect* p = (sjs_rect*)_parent->data;
        sjs_rect* newp = (sjs_rect*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i]._refCount = 1;
sjf_rect_copy(&newp[i], &p[i]);
;
        }
    }
    (*_return) = (sjs_array_rect*)malloc(sizeof(sjs_array_rect));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot331 = _parent;
    (*_return)->count = (sjt_dot331)->count;
    sjf_array_rect_heap((*_return));
}

void sjf_array_rect_heap(sjs_array_rect* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_rect));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_rect_initat(sjs_array_rect* _parent, int32_t index, sjs_rect* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sjs_rect* p = (sjs_rect*)_parent->data;
    p[index]._refCount = 1;
sjf_rect_copy(&p[index], item);
;
    _parent->count = index + 1;
}

void sjf_array_u32(sjs_array_u32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(uint32_t));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_u32_copy(sjs_array_u32* _this, sjs_array_u32* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_u32_destroy(sjs_array_u32* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            uint32_t* p = (uint32_t*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_u32_heap(sjs_array_u32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(uint32_t));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_buttonelement_as_sji_clickable(sjs_buttonelement* _this, sji_clickable* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_buttonelement_clickable_vtbl;
}

void sjf_buttonelement_as_sji_element(sjs_buttonelement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_buttonelement_element_vtbl;
}

void sjf_buttonelement_asinterface(sjs_buttonelement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_buttonelement_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        case sji_clickable_typeId:  {
            sjf_buttonelement_as_sji_clickable(_this, (sji_clickable*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_buttonelement_copy(sjs_buttonelement* _this, sjs_buttonelement* _from) {
    _this->text._refCount = 1;
    sjf_string_copy(&_this->text, &_from->text);
    _this->textcolor._refCount = 1;
    sjf_color_copy(&_this->textcolor, &_from->textcolor);
    _this->font = _from->font;
    _this->font->_refCount++;
    _this->normalimage._refCount = 1;
    sjf_image_copy((_this->normalimage._refCount != -1 ? &_this->normalimage : 0), (_from->normalimage._refCount != -1 ? &_from->normalimage : 0));
    _this->hotimage._refCount = 1;
    sjf_image_copy((_this->hotimage._refCount != -1 ? &_this->hotimage : 0), (_from->hotimage._refCount != -1 ? &_from->hotimage : 0));
    _this->pressedimage._refCount = 1;
    sjf_image_copy((_this->pressedimage._refCount != -1 ? &_this->pressedimage : 0), (_from->pressedimage._refCount != -1 ? &_from->pressedimage : 0));
    _this->margin._refCount = 1;
    sjf_margin_copy(&_this->margin, &_from->margin);
    _this->onclick = _from->onclick;
    if ((uintptr_t)_this->onclick.inner._parent > 1) {
        _this->onclick.inner._parent->_refCount++;
    }

    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    _this->_textrenderer._refCount = 1;
    sjf_textrenderer_copy((_this->_textrenderer._refCount != -1 ? &_this->_textrenderer : 0), (_from->_textrenderer._refCount != -1 ? &_from->_textrenderer : 0));
    _this->_imagerenderer._refCount = 1;
    sjf_imagerenderer_copy((_this->_imagerenderer._refCount != -1 ? &_this->_imagerenderer : 0), (_from->_imagerenderer._refCount != -1 ? &_from->_imagerenderer : 0));
    _this->_clickgesture._refCount = 1;
    sjf_clickgesture_copy(&_this->_clickgesture, &_from->_clickgesture);
}

void sjf_buttonelement_destroy(sjs_buttonelement* _this) {
    _this->font->_refCount--;
    if (_this->font->_refCount <= 0) {
        weakptr_release(_this->font);
        sjf_font_destroy(_this->font);
        free(_this->font);
    }

    if ((uintptr_t)_this->onclick.inner._parent > 1) {
        _this->onclick.inner._parent->_refCount--;
        if (_this->onclick.inner._parent->_refCount <= 0) {
            _this->onclick._destroy(_this->onclick.inner._parent);
            free(_this->onclick.inner._parent);
        }
    }
}

void sjf_buttonelement_firemouseevent(sjs_buttonelement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_buttonelement* sjt_dot222 = 0;
    sjs_mouseevent* sjt_functionParam101 = 0;
    sjs_clickgesture* sjt_parent48 = 0;

    sjt_dot222 = _parent;
    sjt_parent48 = &(sjt_dot222)->_clickgesture;
    sjt_functionParam101 = mouseevent;
    sjf_clickgesture_firemouseevent(sjt_parent48, sjt_functionParam101, _return);
}

void sjf_buttonelement_getrect(sjs_buttonelement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy6 = 0;
    sjs_buttonelement* sjt_dot135 = 0;

    sjt_dot135 = _parent;
    sjt_copy6 = &(sjt_dot135)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy6);
}

void sjf_buttonelement_getrect_heap(sjs_buttonelement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy7 = 0;
    sjs_buttonelement* sjt_dot136 = 0;

    sjt_dot136 = _parent;
    sjt_copy7 = &(sjt_dot136)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy7);
}

void sjf_buttonelement_getsize(sjs_buttonelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size sjt_call8 = { -1 };
    sjs_buttonelement* sjt_dot113 = 0;
    sjs_buttonelement* sjt_dot114 = 0;
    sjs_buttonelement* sjt_dot115 = 0;
    sjs_string* sjt_functionParam41 = 0;
    sjs_margin* sjt_functionParam42 = 0;
    sjs_size* sjt_functionParam43 = 0;
    sjs_size* sjt_parent31 = 0;
    sjs_font* sjt_parent32 = 0;
    sjs_size* sjt_parent33 = 0;
    sjs_size sjv_textsize = { -1 };

    sjt_dot113 = _parent;
    sjt_parent32 = (sjt_dot113)->font;
    sjt_dot114 = _parent;
    sjt_functionParam41 = &(sjt_dot114)->text;
    sjf_font_gettextsize(sjt_parent32, sjt_functionParam41, &sjt_call8);
    sjt_parent31 = &sjt_call8;
    sjt_dot115 = _parent;
    sjt_functionParam42 = &(sjt_dot115)->margin;
    sjf_size_addmargin(sjt_parent31, sjt_functionParam42, &sjv_textsize);
    sjt_parent33 = &sjv_textsize;
    sjt_functionParam43 = maxsize;
    sjf_size_min(sjt_parent33, sjt_functionParam43, _return);

    if (sjt_call8._refCount == 1) { sjf_size_destroy(&sjt_call8); }
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
}

void sjf_buttonelement_getsize_heap(sjs_buttonelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size sjt_call9 = { -1 };
    sjs_buttonelement* sjt_dot132 = 0;
    sjs_buttonelement* sjt_dot133 = 0;
    sjs_buttonelement* sjt_dot134 = 0;
    sjs_string* sjt_functionParam44 = 0;
    sjs_margin* sjt_functionParam45 = 0;
    sjs_size* sjt_functionParam46 = 0;
    sjs_size* sjt_parent34 = 0;
    sjs_font* sjt_parent35 = 0;
    sjs_size* sjt_parent36 = 0;
    sjs_size sjv_textsize = { -1 };

    sjt_dot132 = _parent;
    sjt_parent35 = (sjt_dot132)->font;
    sjt_dot133 = _parent;
    sjt_functionParam44 = &(sjt_dot133)->text;
    sjf_font_gettextsize(sjt_parent35, sjt_functionParam44, &sjt_call9);
    sjt_parent34 = &sjt_call9;
    sjt_dot134 = _parent;
    sjt_functionParam45 = &(sjt_dot134)->margin;
    sjf_size_addmargin(sjt_parent34, sjt_functionParam45, &sjv_textsize);
    sjt_parent36 = &sjv_textsize;
    sjt_functionParam46 = maxsize;
    sjf_size_min_heap(sjt_parent36, sjt_functionParam46, _return);

    if (sjt_call9._refCount == 1) { sjf_size_destroy(&sjt_call9); }
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
}

void sjf_buttonelement_heap(sjs_buttonelement* _this) {
    sjs_buttonelement* sjt_cast4 = 0;
    sjs_buttonelement* sjt_cast5 = 0;

    _this->_clickgesture._refCount = 1;
    sjt_cast4 = _this;
    sjf_buttonelement_as_sji_element(sjt_cast4, &_this->_clickgesture.element);
    delete_cb weakptrcb18 = { &_this->_clickgesture.element._parent, weakptr_clear };
    if (_this->_clickgesture.element._parent != 0) { weakptr_cb_add(_this->_clickgesture.element._parent, weakptrcb18); }
    sjt_cast5 = _this;
    sjf_buttonelement_as_sji_clickable(sjt_cast5, &_this->_clickgesture.clickable);
    delete_cb weakptrcb19 = { &_this->_clickgesture.clickable._parent, weakptr_clear };
    if (_this->_clickgesture.clickable._parent != 0) { weakptr_cb_add(_this->_clickgesture.clickable._parent, weakptrcb19); }
    _this->_clickgesture.rect._refCount = 1;
    _this->_clickgesture.rect.x = 0;
    _this->_clickgesture.rect.y = 0;
    _this->_clickgesture.rect.w = 0;
    _this->_clickgesture.rect.h = 0;
    sjf_rect(&_this->_clickgesture.rect);
    _this->_clickgesture._state = sjv_clickstate_none;
    sjf_clickgesture(&_this->_clickgesture);
}

void sjf_buttonelement_onclickgestureclick(sjs_buttonelement* _parent, sji_element element) {
    sjs_buttonelement* sjt_dot226 = 0;
    sjs_buttonelement* sjt_dot227 = 0;
    bool sjt_isEmpty22;
    cb_void sjt_isEmpty23;

    sjt_dot226 = _parent;
    sjt_dot226->_imagerenderer._refCount = -1;
    sjt_dot227 = _parent;
    sjt_isEmpty23 = (sjt_dot227)->onclick.inner;
    sjt_isEmpty22 = (sjt_isEmpty23._parent != 0);
    if (sjt_isEmpty22) {
        cb_void_heap ifValue13;
        cb_void sjt_callback1;
        sjs_buttonelement* sjt_dot228 = 0;
        cb_void_heap sjt_getValue1;

        sjt_dot228 = _parent;
        sjt_getValue1 = (sjt_dot228)->onclick;
        if ((uintptr_t)sjt_getValue1.inner._parent > 1) {
            sjt_getValue1.inner._parent->_refCount++;
        }

        ifValue13 = sjt_getValue1;
        if ((uintptr_t)ifValue13.inner._parent > 1) {
            ifValue13.inner._parent->_refCount++;
        }

        sjt_callback1 = ifValue13.inner;
        sjt_callback1._cb(sjt_callback1._parent);

        if ((uintptr_t)ifValue13.inner._parent > 1) {
            ifValue13.inner._parent->_refCount--;
            if (ifValue13.inner._parent->_refCount <= 0) {
                ifValue13._destroy(ifValue13.inner._parent);
                free(ifValue13.inner._parent);
            }
        }
        if ((uintptr_t)sjt_getValue1.inner._parent > 1) {
            sjt_getValue1.inner._parent->_refCount--;
            if (sjt_getValue1.inner._parent->_refCount <= 0) {
                sjt_getValue1._destroy(sjt_getValue1.inner._parent);
                free(sjt_getValue1.inner._parent);
            }
        }
    }
}

void sjf_buttonelement_onclickgestureenter(sjs_buttonelement* _parent, sji_element element) {
    sjs_buttonelement* sjt_dot223 = 0;

    sjt_dot223 = _parent;
    sjt_dot223->_imagerenderer._refCount = -1;
}

void sjf_buttonelement_onclickgestureleave(sjs_buttonelement* _parent, sji_element element) {
    sjs_buttonelement* sjt_dot224 = 0;

    sjt_dot224 = _parent;
    sjt_dot224->_imagerenderer._refCount = -1;
}

void sjf_buttonelement_onclickgesturepress(sjs_buttonelement* _parent, sji_element element) {
    sjs_buttonelement* sjt_dot225 = 0;

    sjt_dot225 = _parent;
    sjt_dot225->_imagerenderer._refCount = -1;
}

void sjf_buttonelement_render(sjs_buttonelement* _parent, sjs_scene2d* scene) {
    sjs_buttonelement* sjt_dot151 = 0;
    sjs_buttonelement* sjt_dot162 = 0;
    sjs_buttonelement* sjt_dot177 = 0;
    sjs_buttonelement* sjt_dot184 = 0;
    bool sjt_ifElse20;
    bool sjt_ifElse24;
    bool sjt_ifElse25;
    bool sjt_ifElse26;
    sjs_imagerenderer* sjt_isEmpty10 = 0;
    sjs_textrenderer* sjt_isEmpty11 = 0;
    sjs_imagerenderer* sjt_isEmpty3 = 0;
    sjs_textrenderer* sjt_isEmpty9 = 0;
    sjs_image sjv_image = { -1 };
    sjs_rect sjv_innerrect = { -1 };
    sjs_size sjv_textsize = { -1 };

    sjt_dot151 = _parent;
    sjt_isEmpty3 = ((sjt_dot151)->_imagerenderer._refCount != -1 ? &(sjt_dot151)->_imagerenderer : 0);
    sjt_ifElse20 = (sjt_isEmpty3 == 0);
    if (sjt_ifElse20) {
        int32_t sjt_compare49;
        int32_t sjt_compare50;
        sjs_buttonelement* sjt_dot153 = 0;
        bool sjt_isEmpty7;
        sjs_image* sjt_isEmpty8 = 0;
        sjs_clickgesture* sjt_parent38 = 0;
        bool sjt_switch1;
        int32_t underscore1;

        sjt_dot153 = _parent;
        sjt_parent38 = &(sjt_dot153)->_clickgesture;
        sjf_clickgesture_getstate(sjt_parent38, &underscore1);
        sjt_compare49 = underscore1;
        sjt_compare50 = sjv_clickstate_entered;
        sjt_switch1 = sjt_compare49 == sjt_compare50;
        if (sjt_switch1) {
            sjs_buttonelement* sjt_dot154 = 0;
            bool sjt_ifElse21;
            sjs_image* sjt_isEmpty4 = 0;

            sjt_dot154 = _parent;
            sjt_isEmpty4 = ((sjt_dot154)->hotimage._refCount != -1 ? &(sjt_dot154)->hotimage : 0);
            sjt_ifElse21 = (sjt_isEmpty4 != 0);
            if (sjt_ifElse21) {
                sjs_image* sjt_copy10 = 0;
                sjs_buttonelement* sjt_dot155 = 0;

                sjt_dot155 = _parent;
                sjt_copy10 = ((sjt_dot155)->hotimage._refCount != -1 ? &(sjt_dot155)->hotimage : 0);
                sjv_image._refCount = 1;
                sjf_image_copy(&sjv_image, sjt_copy10);
            } else {
                sjv_image._refCount = -1;
            }
        } else {
            int32_t sjt_compare51;
            int32_t sjt_compare52;
            bool sjt_switch2;

            sjt_compare51 = underscore1;
            sjt_compare52 = sjv_clickstate_pressed;
            sjt_switch2 = sjt_compare51 == sjt_compare52;
            if (sjt_switch2) {
                sjs_buttonelement* sjt_dot156 = 0;
                bool sjt_ifElse22;
                sjs_image* sjt_isEmpty5 = 0;

                sjt_dot156 = _parent;
                sjt_isEmpty5 = ((sjt_dot156)->pressedimage._refCount != -1 ? &(sjt_dot156)->pressedimage : 0);
                sjt_ifElse22 = (sjt_isEmpty5 != 0);
                if (sjt_ifElse22) {
                    sjs_image* sjt_copy11 = 0;
                    sjs_buttonelement* sjt_dot157 = 0;

                    sjt_dot157 = _parent;
                    sjt_copy11 = ((sjt_dot157)->pressedimage._refCount != -1 ? &(sjt_dot157)->pressedimage : 0);
                    sjv_image._refCount = 1;
                    sjf_image_copy(&sjv_image, sjt_copy11);
                } else {
                    sjv_image._refCount = -1;
                }
            } else {
                sjs_buttonelement* sjt_dot158 = 0;
                bool sjt_ifElse23;
                sjs_image* sjt_isEmpty6 = 0;

                sjt_dot158 = _parent;
                sjt_isEmpty6 = ((sjt_dot158)->normalimage._refCount != -1 ? &(sjt_dot158)->normalimage : 0);
                sjt_ifElse23 = (sjt_isEmpty6 != 0);
                if (sjt_ifElse23) {
                    sjs_image* sjt_copy12 = 0;
                    sjs_buttonelement* sjt_dot159 = 0;

                    sjt_dot159 = _parent;
                    sjt_copy12 = ((sjt_dot159)->normalimage._refCount != -1 ? &(sjt_dot159)->normalimage : 0);
                    sjv_image._refCount = 1;
                    sjf_image_copy(&sjv_image, sjt_copy12);
                } else {
                    sjv_image._refCount = -1;
                }
            }
        }

        sjt_isEmpty8 = (sjv_image._refCount != -1 ? &sjv_image : 0);
        sjt_isEmpty7 = (sjt_isEmpty8 != 0);
        if (sjt_isEmpty7) {
            sjs_image* ifValue5 = 0;
            sjs_rect* sjt_copy13 = 0;
            sjs_image* sjt_copy14 = 0;
            sjs_buttonelement* sjt_dot160 = 0;
            sjs_buttonelement* sjt_dot161 = 0;

            ifValue5 = (sjv_image._refCount != -1 ? &sjv_image : 0);
            sjt_dot160 = _parent;
            sjt_dot160->_imagerenderer._refCount = 1;
            sjt_dot161 = _parent;
            sjt_copy13 = &(sjt_dot161)->_rect;
            sjt_dot160->_imagerenderer.rect._refCount = 1;
            sjf_rect_copy(&sjt_dot160->_imagerenderer.rect, sjt_copy13);
            sjt_copy14 = ifValue5;
            sjt_dot160->_imagerenderer.image._refCount = 1;
            sjf_image_copy(&sjt_dot160->_imagerenderer.image, sjt_copy14);
            sjf_imagerenderer(&sjt_dot160->_imagerenderer);
        }
    }

    sjt_dot162 = _parent;
    sjt_isEmpty9 = ((sjt_dot162)->_textrenderer._refCount != -1 ? &(sjt_dot162)->_textrenderer : 0);
    sjt_ifElse24 = (sjt_isEmpty9 == 0);
    if (sjt_ifElse24) {
        sjs_string* sjt_copy15 = 0;
        sjs_color* sjt_copy16 = 0;
        sjs_font* sjt_copy17 = 0;
        sjs_buttonelement* sjt_dot163 = 0;
        sjs_buttonelement* sjt_dot164 = 0;
        sjs_buttonelement* sjt_dot165 = 0;
        sjs_buttonelement* sjt_dot166 = 0;
        sjs_buttonelement* sjt_dot167 = 0;
        sjs_buttonelement* sjt_dot168 = 0;
        sjs_rect* sjt_dot169 = 0;
        sjs_rect* sjt_dot170 = 0;
        sjs_size* sjt_dot171 = 0;
        sjs_rect* sjt_dot172 = 0;
        sjs_rect* sjt_dot173 = 0;
        sjs_size* sjt_dot174 = 0;
        sjs_buttonelement* sjt_dot175 = 0;
        sjs_buttonelement* sjt_dot176 = 0;
        sjs_margin* sjt_functionParam48 = 0;
        sjs_string* sjt_functionParam49 = 0;
        int32_t sjt_math109;
        int32_t sjt_math110;
        int32_t sjt_math111;
        int32_t sjt_math112;
        int32_t sjt_math113;
        int32_t sjt_math114;
        int32_t sjt_math115;
        int32_t sjt_math116;
        int32_t sjt_math117;
        int32_t sjt_math118;
        int32_t sjt_math119;
        int32_t sjt_math120;
        sjs_rect* sjt_parent39 = 0;
        sjs_font* sjt_parent40 = 0;

        sjt_dot163 = _parent;
        sjt_parent39 = &(sjt_dot163)->_rect;
        sjt_dot164 = _parent;
        sjt_functionParam48 = &(sjt_dot164)->margin;
        sjf_rect_subtractmargin(sjt_parent39, sjt_functionParam48, &sjv_innerrect);
        sjt_dot165 = _parent;
        sjt_parent40 = (sjt_dot165)->font;
        sjt_dot166 = _parent;
        sjt_functionParam49 = &(sjt_dot166)->text;
        sjf_font_gettextsize(sjt_parent40, sjt_functionParam49, &sjv_textsize);
        sjt_dot167 = _parent;
        sjt_dot167->_textrenderer._refCount = 1;
        sjt_dot168 = _parent;
        sjt_copy15 = &(sjt_dot168)->text;
        sjt_dot167->_textrenderer.text._refCount = 1;
        sjf_string_copy(&sjt_dot167->_textrenderer.text, sjt_copy15);
        sjt_dot167->_textrenderer.point._refCount = 1;
        sjt_dot169 = &sjv_innerrect;
        sjt_math109 = (sjt_dot169)->x;
        sjt_dot170 = &sjv_innerrect;
        sjt_math113 = (sjt_dot170)->w;
        sjt_dot171 = &sjv_textsize;
        sjt_math114 = (sjt_dot171)->w;
        sjt_math111 = sjt_math113 - sjt_math114;
        sjt_math112 = 2;
        sjt_math110 = sjt_math111 / sjt_math112;
        sjt_dot167->_textrenderer.point.x = sjt_math109 + sjt_math110;
        sjt_dot172 = &sjv_innerrect;
        sjt_math115 = (sjt_dot172)->y;
        sjt_dot173 = &sjv_innerrect;
        sjt_math119 = (sjt_dot173)->h;
        sjt_dot174 = &sjv_textsize;
        sjt_math120 = (sjt_dot174)->h;
        sjt_math117 = sjt_math119 - sjt_math120;
        sjt_math118 = 2;
        sjt_math116 = sjt_math117 / sjt_math118;
        sjt_dot167->_textrenderer.point.y = sjt_math115 + sjt_math116;
        sjf_point(&sjt_dot167->_textrenderer.point);
        sjt_dot175 = _parent;
        sjt_copy16 = &(sjt_dot175)->textcolor;
        sjt_dot167->_textrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot167->_textrenderer.color, sjt_copy16);
        sjt_dot176 = _parent;
        sjt_copy17 = (sjt_dot176)->font;
        sjt_dot167->_textrenderer.font._refCount = 1;
        sjf_font_copy(&sjt_dot167->_textrenderer.font, sjt_copy17);
        sjf_textrenderer(&sjt_dot167->_textrenderer);
    }

    sjt_dot177 = _parent;
    sjt_isEmpty10 = ((sjt_dot177)->_imagerenderer._refCount != -1 ? &(sjt_dot177)->_imagerenderer : 0);
    sjt_ifElse25 = (sjt_isEmpty10 != 0);
    if (sjt_ifElse25) {
        sjs_buttonelement* sjt_dot183 = 0;
        sjs_scene2d* sjt_functionParam71 = 0;
        sjs_imagerenderer* sjt_parent41 = 0;

        sjt_dot183 = _parent;
        sjt_parent41 = ((sjt_dot183)->_imagerenderer._refCount != -1 ? &(sjt_dot183)->_imagerenderer : 0);
        sjt_functionParam71 = scene;
        sjf_imagerenderer_render(sjt_parent41, sjt_functionParam71);
    }

    sjt_dot184 = _parent;
    sjt_isEmpty11 = ((sjt_dot184)->_textrenderer._refCount != -1 ? &(sjt_dot184)->_textrenderer : 0);
    sjt_ifElse26 = (sjt_isEmpty11 != 0);
    if (sjt_ifElse26) {
        sjs_buttonelement* sjt_dot188 = 0;
        sjs_scene2d* sjt_functionParam91 = 0;
        sjs_textrenderer* sjt_parent42 = 0;

        sjt_dot188 = _parent;
        sjt_parent42 = ((sjt_dot188)->_textrenderer._refCount != -1 ? &(sjt_dot188)->_textrenderer : 0);
        sjt_functionParam91 = scene;
        sjf_textrenderer_render(sjt_parent42, sjt_functionParam91);
    }

    if (sjv_image._refCount == 1) { sjf_image_destroy(&sjv_image); }
    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
}

void sjf_buttonelement_setrect(sjs_buttonelement* _parent, sjs_rect* rect_) {
    bool result2;
    sjs_buttonelement* sjt_dot145 = 0;
    sjs_rect* sjt_functionParam47 = 0;
    bool sjt_ifElse19;
    bool sjt_not1;
    sjs_rect* sjt_parent37 = 0;

    sjt_dot145 = _parent;
    sjt_parent37 = &(sjt_dot145)->_rect;
    sjt_functionParam47 = rect_;
    sjf_rect_isequal(sjt_parent37, sjt_functionParam47, &sjt_not1);
    result2 = !sjt_not1;
    sjt_ifElse19 = result2;
    if (sjt_ifElse19) {
        sjs_rect* sjt_copy8 = 0;
        sjs_rect* sjt_copy9 = 0;
        sjs_buttonelement* sjt_dot146 = 0;
        sjs_clickgesture* sjt_dot147 = 0;
        sjs_buttonelement* sjt_dot148 = 0;
        sjs_buttonelement* sjt_dot149 = 0;
        sjs_buttonelement* sjt_dot150 = 0;

        sjt_dot146 = _parent;
        sjt_copy8 = rect_;
        sjt_dot146->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot146->_rect, sjt_copy8);
        sjt_dot148 = _parent;
        sjt_dot147 = &(sjt_dot148)->_clickgesture;
        sjt_copy9 = rect_;
        sjt_dot147->rect._refCount = 1;
        sjf_rect_copy(&sjt_dot147->rect, sjt_copy9);
        sjt_dot149 = _parent;
        sjt_dot149->_textrenderer._refCount = -1;
        sjt_dot150 = _parent;
        sjt_dot150->_imagerenderer._refCount = -1;
    }
}

void sjf_clickgesture(sjs_clickgesture* _this) {
}

void sjf_clickgesture_copy(sjs_clickgesture* _this, sjs_clickgesture* _from) {
    _this->element = _from->element;
    delete_cb weakptrcb14 = { &_this->element._parent, weakptr_clear };
    if (_this->element._parent != 0) { weakptr_cb_add(_this->element._parent, weakptrcb14); }
    _this->clickable = _from->clickable;
    delete_cb weakptrcb15 = { &_this->clickable._parent, weakptr_clear };
    if (_this->clickable._parent != 0) { weakptr_cb_add(_this->clickable._parent, weakptrcb15); }
    _this->rect._refCount = 1;
    sjf_rect_copy(&_this->rect, &_from->rect);
    _this->_state = _from->_state;
}

void sjf_clickgesture_destroy(sjs_clickgesture* _this) {
    delete_cb weakptrcb16 = { &_this->element._parent, weakptr_clear };
    if (_this->element._parent != 0) { weakptr_cb_remove(_this->element._parent, weakptrcb16); }
    delete_cb weakptrcb17 = { &_this->clickable._parent, weakptr_clear };
    if (_this->clickable._parent != 0) { weakptr_cb_remove(_this->clickable._parent, weakptrcb17); }
}

void sjf_clickgesture_firemouseevent(sjs_clickgesture* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_clickgesture* sjt_dot189 = 0;
    bool sjt_isEmpty12;
    sji_element sjt_isEmpty13 = { 0 };

    sjt_dot189 = _parent;
    sjt_isEmpty13 = (sjt_dot189)->element;
    sjt_isEmpty12 = (sjt_isEmpty13._parent != 0);
    if (sjt_isEmpty12) {
        sji_element ifValue7 = { 0 };
        sjs_clickgesture* sjt_dot190 = 0;
        sjs_clickgesture* sjt_dot201 = 0;
        sjs_mouseevent* sjt_dot202 = 0;
        sjs_point* sjt_functionParam92 = 0;
        bool sjt_ifElse27;
        sjs_rect* sjt_parent43 = 0;

        sjt_dot190 = _parent;
        ifValue7 = (sjt_dot190)->element;
        if (ifValue7._parent != 0) {
            ifValue7._parent->_refCount++;
        }

        sjt_dot201 = _parent;
        sjt_parent43 = &(sjt_dot201)->rect;
        sjt_dot202 = mouseevent;
        sjt_functionParam92 = &(sjt_dot202)->point;
        sjf_rect_containspoint(sjt_parent43, sjt_functionParam92, &sjt_ifElse27);
        if (sjt_ifElse27) {
            int32_t sjt_compare61;
            int32_t sjt_compare62;
            sjs_mouseevent* sjt_dot203 = 0;
            bool sjt_switch3;
            int32_t underscore3;

            sjt_dot203 = mouseevent;
            underscore3 = (sjt_dot203)->type;
            sjt_compare61 = underscore3;
            sjt_compare62 = sjv_mouseeventtype_up;
            sjt_switch3 = sjt_compare61 == sjt_compare62;
            if (sjt_switch3) {
                sjs_clickgesture* sjt_dot204 = 0;
                sjs_clickgesture* sjt_dot205 = 0;
                sji_element sjt_functionParam95 = { 0 };
                bool sjt_ifElse29;
                sji_clickable sjt_isEmpty16 = { 0 };

                sjt_dot204 = _parent;
                sjt_dot204->_state = sjv_clickstate_none;
                sjt_functionParam95 = ifValue7;
                if (sjt_functionParam95._parent != 0) {
                    sjt_functionParam95._parent->_refCount++;
                }

                sjf_mouse_release(sjt_functionParam95);
                sjt_dot205 = _parent;
                sjt_isEmpty16 = (sjt_dot205)->clickable;
                sjt_ifElse29 = (sjt_isEmpty16._parent != 0);
                if (sjt_ifElse29) {
                    sjs_clickgesture* sjt_dot206 = 0;
                    sji_element sjt_interfaceParam4 = { 0 };
                    sji_clickable sjt_parent44 = { 0 };

                    sjt_dot206 = _parent;
                    sjt_parent44 = (sjt_dot206)->clickable;
                    sjt_interfaceParam4 = ifValue7;
                    sjt_parent44._vtbl->onclickgestureclick(sjt_parent44._parent, sjt_interfaceParam4);
                }

                (*_return) = false;

                if (sjt_functionParam95._parent != 0) {
                    sjt_functionParam95._parent->_refCount--;
                    if (sjt_functionParam95._parent->_refCount <= 0) {
                        sjt_functionParam95._vtbl->destroy(sjt_functionParam95._parent);
                        free(sjt_functionParam95._parent);
                    }
                }
            } else {
                int32_t sjt_compare65;
                int32_t sjt_compare66;
                bool sjt_switch4;

                sjt_compare65 = underscore3;
                sjt_compare66 = sjv_mouseeventtype_down;
                sjt_switch4 = sjt_compare65 == sjt_compare66;
                if (sjt_switch4) {
                    sjs_clickgesture* sjt_dot207 = 0;
                    sjs_clickgesture* sjt_dot208 = 0;
                    sji_element sjt_functionParam96 = { 0 };
                    bool sjt_ifElse30;
                    sji_clickable sjt_isEmpty17 = { 0 };

                    sjt_dot207 = _parent;
                    sjt_dot207->_state = sjv_clickstate_pressed;
                    sjt_functionParam96 = ifValue7;
                    if (sjt_functionParam96._parent != 0) {
                        sjt_functionParam96._parent->_refCount++;
                    }

                    sjf_mouse_capture(sjt_functionParam96);
                    sjt_dot208 = _parent;
                    sjt_isEmpty17 = (sjt_dot208)->clickable;
                    sjt_ifElse30 = (sjt_isEmpty17._parent != 0);
                    if (sjt_ifElse30) {
                        sjs_clickgesture* sjt_dot209 = 0;
                        sji_element sjt_interfaceParam5 = { 0 };
                        sji_clickable sjt_parent45 = { 0 };

                        sjt_dot209 = _parent;
                        sjt_parent45 = (sjt_dot209)->clickable;
                        sjt_interfaceParam5 = ifValue7;
                        sjt_parent45._vtbl->onclickgesturepress(sjt_parent45._parent, sjt_interfaceParam5);
                    }

                    (*_return) = false;

                    if (sjt_functionParam96._parent != 0) {
                        sjt_functionParam96._parent->_refCount--;
                        if (sjt_functionParam96._parent->_refCount <= 0) {
                            sjt_functionParam96._vtbl->destroy(sjt_functionParam96._parent);
                            free(sjt_functionParam96._parent);
                        }
                    }
                } else {
                    int32_t sjt_compare67;
                    int32_t sjt_compare68;
                    bool sjt_switch5;

                    sjt_compare67 = underscore3;
                    sjt_compare68 = sjv_mouseeventtype_move;
                    sjt_switch5 = sjt_compare67 == sjt_compare68;
                    if (sjt_switch5) {
                        int32_t sjt_compare69;
                        int32_t sjt_compare70;
                        sjs_clickgesture* sjt_dot210 = 0;
                        sji_element sjt_functionParam97 = { 0 };
                        bool sjt_ifElse31;

                        sjt_dot210 = _parent;
                        sjt_compare69 = (sjt_dot210)->_state;
                        sjt_compare70 = sjv_clickstate_none;
                        sjt_ifElse31 = sjt_compare69 == sjt_compare70;
                        if (sjt_ifElse31) {
                            sjs_mouseevent* sjt_dot211 = 0;
                            sjs_clickgesture* sjt_dot214 = 0;
                            bool sjt_ifElse32;
                            bool sjt_ifElse33;
                            sji_clickable sjt_isEmpty18 = { 0 };

                            sjt_dot211 = mouseevent;
                            sjt_ifElse32 = (sjt_dot211)->isleftdown;
                            if (sjt_ifElse32) {
                                sjs_clickgesture* sjt_dot212 = 0;

                                sjt_dot212 = _parent;
                                sjt_dot212->_state = sjv_clickstate_pressed;
                            } else {
                                sjs_clickgesture* sjt_dot213 = 0;

                                sjt_dot213 = _parent;
                                sjt_dot213->_state = sjv_clickstate_entered;
                            }

                            sjt_dot214 = _parent;
                            sjt_isEmpty18 = (sjt_dot214)->clickable;
                            sjt_ifElse33 = (sjt_isEmpty18._parent != 0);
                            if (sjt_ifElse33) {
                                sjs_clickgesture* sjt_dot215 = 0;
                                sji_element sjt_interfaceParam6 = { 0 };
                                sji_clickable sjt_parent46 = { 0 };

                                sjt_dot215 = _parent;
                                sjt_parent46 = (sjt_dot215)->clickable;
                                sjt_interfaceParam6 = ifValue7;
                                sjt_parent46._vtbl->onclickgestureenter(sjt_parent46._parent, sjt_interfaceParam6);
                            }
                        }

                        sjt_functionParam97 = ifValue7;
                        if (sjt_functionParam97._parent != 0) {
                            sjt_functionParam97._parent->_refCount++;
                        }

                        sjf_mouse_hascapture(sjt_functionParam97, _return);

                        if (sjt_functionParam97._parent != 0) {
                            sjt_functionParam97._parent->_refCount--;
                            if (sjt_functionParam97._parent->_refCount <= 0) {
                                sjt_functionParam97._vtbl->destroy(sjt_functionParam97._parent);
                                free(sjt_functionParam97._parent);
                            }
                        }
                    } else {
                        (*_return) = true;
                    }
                }
            }
        } else {
            bool sjt_and19;
            bool sjt_and20;
            int32_t sjt_compare73;
            int32_t sjt_compare74;
            int32_t sjt_compare75;
            int32_t sjt_compare76;
            int32_t sjt_compare77;
            int32_t sjt_compare78;
            sjs_clickgesture* sjt_dot216 = 0;
            sjs_clickgesture* sjt_dot217 = 0;
            sjs_mouseevent* sjt_dot221 = 0;
            sji_element sjt_functionParam98 = { 0 };
            bool sjt_ifElse34;
            bool sjt_ifElse36;
            bool sjt_or1;
            bool sjt_or2;

            sjt_dot216 = _parent;
            sjt_compare73 = (sjt_dot216)->_state;
            sjt_compare74 = sjv_clickstate_entered;
            sjt_or1 = sjt_compare73 == sjt_compare74;
            sjt_dot217 = _parent;
            sjt_compare75 = (sjt_dot217)->_state;
            sjt_compare76 = sjv_clickstate_pressed;
            sjt_or2 = sjt_compare75 == sjt_compare76;
            sjt_ifElse34 = sjt_or1 || sjt_or2;
            if (sjt_ifElse34) {
                sjs_clickgesture* sjt_dot218 = 0;
                sjs_clickgesture* sjt_dot220 = 0;
                bool sjt_ifElse35;
                sji_clickable sjt_isEmpty21 = { 0 };

                sjt_dot218 = _parent;
                sjt_isEmpty21 = (sjt_dot218)->clickable;
                sjt_ifElse35 = (sjt_isEmpty21._parent != 0);
                if (sjt_ifElse35) {
                    sjs_clickgesture* sjt_dot219 = 0;
                    sji_element sjt_interfaceParam7 = { 0 };
                    sji_clickable sjt_parent47 = { 0 };

                    sjt_dot219 = _parent;
                    sjt_parent47 = (sjt_dot219)->clickable;
                    sjt_interfaceParam7 = ifValue7;
                    sjt_parent47._vtbl->onclickgestureleave(sjt_parent47._parent, sjt_interfaceParam7);
                }

                sjt_dot220 = _parent;
                sjt_dot220->_state = sjv_clickstate_none;
            }

            sjt_dot221 = mouseevent;
            sjt_compare77 = (sjt_dot221)->type;
            sjt_compare78 = sjv_mouseeventtype_up;
            sjt_and19 = sjt_compare77 == sjt_compare78;
            sjt_functionParam98 = ifValue7;
            if (sjt_functionParam98._parent != 0) {
                sjt_functionParam98._parent->_refCount++;
            }

            sjf_mouse_hascapture(sjt_functionParam98, &sjt_and20);
            sjt_ifElse36 = sjt_and19 && sjt_and20;
            if (sjt_ifElse36) {
                sji_element sjt_functionParam99 = { 0 };

                sjt_functionParam99 = ifValue7;
                if (sjt_functionParam99._parent != 0) {
                    sjt_functionParam99._parent->_refCount++;
                }

                sjf_mouse_release(sjt_functionParam99);
                (*_return) = false;

                if (sjt_functionParam99._parent != 0) {
                    sjt_functionParam99._parent->_refCount--;
                    if (sjt_functionParam99._parent->_refCount <= 0) {
                        sjt_functionParam99._vtbl->destroy(sjt_functionParam99._parent);
                        free(sjt_functionParam99._parent);
                    }
                }
            } else {
                sji_element sjt_functionParam100 = { 0 };

                sjt_functionParam100 = ifValue7;
                if (sjt_functionParam100._parent != 0) {
                    sjt_functionParam100._parent->_refCount++;
                }

                sjf_mouse_hascapture(sjt_functionParam100, _return);

                if (sjt_functionParam100._parent != 0) {
                    sjt_functionParam100._parent->_refCount--;
                    if (sjt_functionParam100._parent->_refCount <= 0) {
                        sjt_functionParam100._vtbl->destroy(sjt_functionParam100._parent);
                        free(sjt_functionParam100._parent);
                    }
                }
            }

            if (sjt_functionParam98._parent != 0) {
                sjt_functionParam98._parent->_refCount--;
                if (sjt_functionParam98._parent->_refCount <= 0) {
                    sjt_functionParam98._vtbl->destroy(sjt_functionParam98._parent);
                    free(sjt_functionParam98._parent);
                }
            }
        }

        if (ifValue7._parent != 0) {
            ifValue7._parent->_refCount--;
            if (ifValue7._parent->_refCount <= 0) {
                ifValue7._vtbl->destroy(ifValue7._parent);
                free(ifValue7._parent);
            }
        }
    } else {
        (*_return) = true;
    }
}

void sjf_clickgesture_getstate(sjs_clickgesture* _parent, int32_t* _return) {
    sjs_clickgesture* sjt_dot152 = 0;

    sjt_dot152 = _parent;
    (*_return) = (sjt_dot152)->_state;
}

void sjf_clickgesture_heap(sjs_clickgesture* _this) {
}

void sjf_color(sjs_color* _this) {
}

void sjf_color_copy(sjs_color* _this, sjs_color* _from) {
    _this->r = _from->r;
    _this->g = _from->g;
    _this->b = _from->b;
    _this->a = _from->a;
}

void sjf_color_destroy(sjs_color* _this) {
}

void sjf_color_heap(sjs_color* _this) {
}

void sjf_console_writeline(sjs_string* data) {
    printf("%s\n", (char*)data->data.data);
}

void sjf_controller(sjs_controller* _this) {
}

void sjf_controller_button1clicked(sjs_controller* _parent) {
    sjs_string sjt_call24 = { -1 };
    sji_element sjt_call25 = { 0 };
    sjs_string sjt_call26 = { -1 };
    sjs_controller* sjt_dot229 = 0;
    sjs_controller* sjt_dot230 = 0;
    sjs_string* sjt_functionParam110 = 0;
    sjs_string* sjt_functionParam111 = 0;
    bool sjt_isEmpty26;
    sji_element sjt_isEmpty27 = { 0 };
    int32_t sjt_math125;
    int32_t sjt_math126;
    sjs_hash_string_weak_iface_element* sjt_parent52 = 0;

    sjt_dot229 = _parent;
    sjt_dot230 = _parent;
    sjt_math125 = (sjt_dot230)->_button1count;
    sjt_math126 = 1;
    sjt_dot229->_button1count = sjt_math125 + sjt_math126;
    sjt_call24._refCount = 1;
    sjt_call24.count = 7;
    sjt_call24.data._refCount = 1;
    sjt_call24.data.datasize = 8;
    sjt_call24.data.data = (void*)sjg_string27;
    sjt_call24.data._isglobal = true;
    sjt_call24.data.count = 8;
    sjf_array_char(&sjt_call24.data);
    sjf_string(&sjt_call24);
    sjt_functionParam110 = &sjt_call24;
    sjf_debug_writeline(sjt_functionParam110);
    sjt_parent52 = &sjv_elementsbyid;
    sjt_call26._refCount = 1;
    sjt_call26.count = 11;
    sjt_call26.data._refCount = 1;
    sjt_call26.data.datasize = 12;
    sjt_call26.data.data = (void*)sjg_string28;
    sjt_call26.data._isglobal = true;
    sjt_call26.data.count = 12;
    sjf_array_char(&sjt_call26.data);
    sjf_string(&sjt_call26);
    sjt_functionParam111 = &sjt_call26;
    sjf_hash_string_weak_iface_element_getat(sjt_parent52, sjt_functionParam111, &sjt_call25);
    sjt_isEmpty27 = sjt_call25;
    sjt_isEmpty26 = (sjt_isEmpty27._parent != 0);
    if (sjt_isEmpty26) {
        sji_element ifValue15 = { 0 };
        sji_element sjt_call27 = { 0 };
        sjs_string sjt_call28 = { -1 };
        sji_element sjt_cast6 = { 0 };
        sjs_string* sjt_functionParam112 = 0;
        bool sjt_isEmpty28;
        sji_textelement sjt_isEmpty29 = { 0 };
        sjs_hash_string_weak_iface_element* sjt_parent53 = 0;

        sjt_parent53 = &sjv_elementsbyid;
        sjt_call28._refCount = 1;
        sjt_call28.count = 11;
        sjt_call28.data._refCount = 1;
        sjt_call28.data.datasize = 12;
        sjt_call28.data.data = (void*)sjg_string28;
        sjt_call28.data._isglobal = true;
        sjt_call28.data.count = 12;
        sjf_array_char(&sjt_call28.data);
        sjf_string(&sjt_call28);
        sjt_functionParam112 = &sjt_call28;
        sjf_hash_string_weak_iface_element_getat(sjt_parent53, sjt_functionParam112, &sjt_call27);
        ifValue15 = sjt_call27;
        sjt_cast6 = ifValue15;
        sjt_cast6._vtbl->asinterface(sjt_cast6._parent, sji_textelement_typeId, (sjs_interface*)&sjt_isEmpty29);
        sjt_isEmpty28 = (sjt_isEmpty29._parent != 0);
        if (sjt_isEmpty28) {
            sji_textelement ifValue16 = { 0 };
            sjs_string sjt_call29 = { -1 };
            sjs_string sjt_call30 = { -1 };
            sjs_string sjt_call31 = { -1 };
            sji_element sjt_cast7 = { 0 };
            sjs_controller* sjt_dot250 = 0;
            sjs_string* sjt_functionParam132 = 0;
            int32_t sjt_functionParam133;
            sjs_string* sjt_interfaceParam8 = 0;
            sji_textelement sjt_parent54 = { 0 };
            sjs_string* sjt_parent68 = 0;

            sjt_cast7 = ifValue15;
            sjt_cast7._vtbl->asinterface(sjt_cast7._parent, sji_textelement_typeId, (sjs_interface*)&ifValue16);
            sjt_parent54 = ifValue16;
            sjt_call30._refCount = 1;
            sjt_call30.count = 8;
            sjt_call30.data._refCount = 1;
            sjt_call30.data.datasize = 9;
            sjt_call30.data.data = (void*)sjg_string29;
            sjt_call30.data._isglobal = true;
            sjt_call30.data.count = 9;
            sjf_array_char(&sjt_call30.data);
            sjf_string(&sjt_call30);
            sjt_parent68 = &sjt_call30;
            sjt_dot250 = _parent;
            sjt_functionParam133 = (sjt_dot250)->_button1count;
            sjf_i32_asstring(sjt_functionParam133, &sjt_call31);
            sjt_functionParam132 = &sjt_call31;
            sjf_string_add(sjt_parent68, sjt_functionParam132, &sjt_call29);
            sjt_interfaceParam8 = &sjt_call29;
            sjt_parent54._vtbl->settext(sjt_parent54._parent, sjt_interfaceParam8);

            if (sjt_call29._refCount == 1) { sjf_string_destroy(&sjt_call29); }
            if (sjt_call30._refCount == 1) { sjf_string_destroy(&sjt_call30); }
            if (sjt_call31._refCount == 1) { sjf_string_destroy(&sjt_call31); }
        }

        delete_cb weakptrcb29 = { &sjt_call27._parent, weakptr_clear };
        if (sjt_call27._parent != 0) { weakptr_cb_remove(sjt_call27._parent, weakptrcb29); }
        if (sjt_call28._refCount == 1) { sjf_string_destroy(&sjt_call28); }
    }

    delete_cb weakptrcb30 = { &sjt_call25._parent, weakptr_clear };
    if (sjt_call25._parent != 0) { weakptr_cb_remove(sjt_call25._parent, weakptrcb30); }
    if (sjt_call24._refCount == 1) { sjf_string_destroy(&sjt_call24); }
    if (sjt_call26._refCount == 1) { sjf_string_destroy(&sjt_call26); }
}

void sjf_controller_copy(sjs_controller* _this, sjs_controller* _from) {
    _this->_button1count = _from->_button1count;
}

void sjf_controller_destroy(sjs_controller* _this) {
}

void sjf_controller_heap(sjs_controller* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
    #ifdef _WINDOWS
    OutputDebugStringA((char*)data->data.data);
    OutputDebugStringA("\n");
    #else
    fprintf(stderr, "%s\n", (char*)data->data.data);
    #endif
}

void sjf_f32_hash(float val, uint32_t* _return) {
    uint32_t sjv_result;

    sjv_result = (uint32_t)0u;
    int32_t* p = (int32_t*)&val;
    sjv_result = *p;
    (*_return) = sjv_result;
}

void sjf_font(sjs_font* _this) {
    _this->atlas = texture_atlas_new( 512, 512, 3 );
    _this->font = texture_font_new_from_file(_this->atlas, _this->size, (char*)_this->src.data.data);
    if (_this->font == 0) {
        printf("texture_font_new_from_file Error\n");
    }   
    glGenTextures( 1, &_this->atlas->id );
    glBindTexture( GL_TEXTURE_2D, _this->atlas->id );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, (int)_this->atlas->width, (int)_this->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->atlas->data );
}

void sjf_font_copy(sjs_font* _this, sjs_font* _from) {
    _this->src._refCount = 1;
    sjf_string_copy(&_this->src, &_from->src);
    _this->size = _from->size;
    _this->atlas = _from->atlas;
    ptr_retain(_this->atlas);
    _this->font = _from->font;
    ptr_retain(_this->font);
}

void sjf_font_destroy(sjs_font* _this) {
    if (ptr_release(_this->atlas)) {
        texture_atlas_delete(_this->atlas);
    }
    if (ptr_release(_this->font)) {
        texture_font_delete(_this->font);
    }
}

void sjf_font_gettextsize(sjs_font* _parent, sjs_string* str, sjs_size* _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    vec2 size = get_text_size(_parent->font, (char*)str->data.data);
    sjv_w = (int)size.x;
    sjv_h = (int)size.y;
    _return->_refCount = 1;
    _return->w = sjv_w;
    _return->h = sjv_h;
    sjf_size(_return);
}

void sjf_font_gettextsize_heap(sjs_font* _parent, sjs_string* str, sjs_size** _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    vec2 size = get_text_size(_parent->font, (char*)str->data.data);
    sjv_w = (int)size.x;
    sjv_h = (int)size.y;
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    (*_return)->w = sjv_w;
    (*_return)->h = sjv_h;
    sjf_size_heap((*_return));
}

void sjf_font_heap(sjs_font* _this) {
    _this->atlas = texture_atlas_new( 512, 512, 3 );
    _this->font = texture_font_new_from_file(_this->atlas, _this->size, (char*)_this->src.data.data);
    if (_this->font == 0) {
        printf("texture_font_new_from_file Error\n");
    }   
    glGenTextures( 1, &_this->atlas->id );
    glBindTexture( GL_TEXTURE_2D, _this->atlas->id );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, (int)_this->atlas->width, (int)_this->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->atlas->data );
}

void sjf_font_load_heap(sjs_string* src, float size, sjs_font** _return) {
    sjs_string* sjt_copy19 = 0;
    sjs_fontkey* sjt_functionParam102 = 0;
    bool sjt_isEmpty24;
    sjs_font* sjt_isEmpty25 = 0;
    sjs_hash_fontkey_weak_font* sjt_parent49 = 0;
    sjs_font* sjv_h = 0;
    sjs_fontkey sjv_k = { -1 };
    sjs_font* sjv_w = 0;

    sjv_k._refCount = 1;
    sjt_copy19 = src;
    sjv_k.src._refCount = 1;
    sjf_string_copy(&sjv_k.src, sjt_copy19);
    sjv_k.size = size;
    sjf_fontkey(&sjv_k);
    sjt_parent49 = &sjv_fonthash;
    sjt_functionParam102 = &sjv_k;
    sjf_hash_fontkey_weak_font_getat(sjt_parent49, sjt_functionParam102, &sjv_w);
    sjv_h = sjv_w;
    if (sjv_h != 0) {
        sjv_h->_refCount++;
    }

    sjt_isEmpty25 = sjv_h;
    sjt_isEmpty24 = (sjt_isEmpty25 != 0);
    if (sjt_isEmpty24) {
        sjs_font* ifValue4 = 0;

        ifValue4 = sjv_h;
        if (ifValue4 != 0) {
            ifValue4->_refCount++;
        }

        (*_return) = ifValue4;
        (*_return)->_refCount++;

        ifValue4->_refCount--;
        if (ifValue4->_refCount <= 0) {
            weakptr_release(ifValue4);
            sjf_font_destroy(ifValue4);
            free(ifValue4);
        }
    } else {
        sjs_string* sjt_copy20 = 0;
        sjs_fontkey* sjt_functionParam103 = 0;
        sjs_font* sjt_functionParam104 = 0;
        sjs_hash_fontkey_weak_font* sjt_parent50 = 0;
        sjs_font* sjv_result = 0;

        sjv_result = (sjs_font*)malloc(sizeof(sjs_font));
        sjv_result->_refCount = 1;
        sjt_copy20 = src;
        sjv_result->src._refCount = 1;
        sjf_string_copy(&sjv_result->src, sjt_copy20);
        sjv_result->size = size;
        sjf_font_heap(sjv_result);
        sjt_parent50 = &sjv_fonthash;
        sjt_functionParam103 = &sjv_k;
        sjt_functionParam104 = sjv_result;
        delete_cb weakptrcb24 = { &sjt_functionParam104, weakptr_clear };
        if (sjt_functionParam104 != 0) { weakptr_cb_add(sjt_functionParam104, weakptrcb24); }
        sjf_hash_fontkey_weak_font_setat(sjt_parent50, sjt_functionParam103, sjt_functionParam104);
        (*_return) = sjv_result;
        (*_return)->_refCount++;

        delete_cb weakptrcb31 = { &sjt_functionParam104, weakptr_clear };
        if (sjt_functionParam104 != 0) { weakptr_cb_remove(sjt_functionParam104, weakptrcb31); }
        sjv_result->_refCount--;
        if (sjv_result->_refCount <= 0) {
            weakptr_release(sjv_result);
            sjf_font_destroy(sjv_result);
            free(sjv_result);
        }
    }

    if (sjv_h != 0) {
        sjv_h->_refCount--;
        if (sjv_h->_refCount <= 0) {
            weakptr_release(sjv_h);
            sjf_font_destroy(sjv_h);
            free(sjv_h);
        }
    }
    delete_cb weakptrcb32 = { &sjv_w, weakptr_clear };
    if (sjv_w != 0) { weakptr_cb_remove(sjv_w, weakptrcb32); }
    if (sjv_k._refCount == 1) { sjf_fontkey_destroy(&sjv_k); }
}

void sjf_fontkey(sjs_fontkey* _this) {
}

void sjf_fontkey_copy(sjs_fontkey* _this, sjs_fontkey* _from) {
    _this->src._refCount = 1;
    sjf_string_copy(&_this->src, &_from->src);
    _this->size = _from->size;
}

void sjf_fontkey_destroy(sjs_fontkey* _this) {
}

void sjf_fontkey_hash(sjs_fontkey* _parent, uint32_t* _return) {
    sjs_fontkey* sjt_dot3 = 0;
    sjs_fontkey* sjt_dot4 = 0;
    float sjt_functionParam10;
    uint32_t sjt_math3;
    uint32_t sjt_math4;
    sjs_string* sjt_parent2 = 0;

    sjt_dot3 = _parent;
    sjt_parent2 = &(sjt_dot3)->src;
    sjf_string_hash(sjt_parent2, &sjt_math3);
    sjt_dot4 = _parent;
    sjt_functionParam10 = (sjt_dot4)->size;
    sjf_f32_hash(sjt_functionParam10, &sjt_math4);
    (*_return) = sjt_math3 ^ sjt_math4;
}

void sjf_fontkey_heap(sjs_fontkey* _this) {
}

void sjf_fontkey_isequal(sjs_fontkey* _parent, sjs_fontkey* x, bool* _return) {
    bool sjt_and1;
    bool sjt_and2;
    float sjt_compare1;
    float sjt_compare2;
    sjs_fontkey* sjt_dot5 = 0;
    sjs_fontkey* sjt_dot6 = 0;
    sjs_fontkey* sjt_dot7 = 0;
    sjs_fontkey* sjt_dot8 = 0;
    sjs_string* sjt_functionParam11 = 0;
    sjs_string* sjt_parent3 = 0;

    sjt_dot5 = _parent;
    sjt_parent3 = &(sjt_dot5)->src;
    sjt_dot6 = x;
    sjt_functionParam11 = &(sjt_dot6)->src;
    sjf_string_isequal(sjt_parent3, sjt_functionParam11, &sjt_and1);
    sjt_dot7 = _parent;
    sjt_compare1 = (sjt_dot7)->size;
    sjt_dot8 = x;
    sjt_compare2 = (sjt_dot8)->size;
    sjt_and2 = sjt_compare1 == sjt_compare2;
    (*_return) = sjt_and1 && sjt_and2;
}

void sjf_glbindtexture(int32_t type, sjs_texture* texture) {
    glBindTexture(type, texture->id);
}

void sjf_glblendfunc(int32_t sfactor, int32_t dfactor) {
    glBlendFunc(sfactor, dfactor);
}

void sjf_glclearcolor(sjs_color* color) {
    glClearColor(color->r, color->g, color->b, color->a);
}

void sjf_glenable(int32_t feature) {
    glEnable(feature);
}

void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return) {
    int result = glGetUniformLocation(shader->id, (char*)name->data.data);
    (*_return) = result;
return;;
}

void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect) {
    bool result10;
    sjs_rect sjt_call41 = { -1 };
    sjs_string sjt_call42 = { -1 };
    int32_t sjt_compare103;
    int32_t sjt_compare104;
    sjs_rect* sjt_dot342 = 0;
    sjs_rect* sjt_dot343 = 0;
    sjs_rect* sjt_dot344 = 0;
    sjs_rect* sjt_dot345 = 0;
    sjs_rect* sjt_dot346 = 0;
    sjs_rect* sjt_dot347 = 0;
    int32_t sjt_functionParam186;
    sjs_rect* sjt_functionParam187 = 0;
    int32_t sjt_functionParam189;
    bool sjt_ifElse47;
    bool sjt_ifElse48;
    int32_t sjt_math251;
    int32_t sjt_math252;
    int32_t sjt_math253;
    int32_t sjt_math254;
    int32_t sjt_math255;
    int32_t sjt_math256;
    int32_t sjt_math257;
    int32_t sjt_math258;
    bool sjt_not5;
    sjs_rect* sjt_parent105 = 0;
    sjs_list_rect* sjt_parent107 = 0;
    sjs_list_rect* sjt_parent108 = 0;
    sjs_list_rect* sjt_parent109 = 0;
    sjs_list_rect* sjt_parent110 = 0;
    sjs_list_rect* sjt_parent111 = 0;
    sjs_rect sjv_newrect = { -1 };
    sjs_rect sjv_oldrect = { -1 };

    sjv_oldrect._refCount = 1;
    sjt_dot342 = rect;
    sjv_oldrect.x = (sjt_dot342)->x;
    sjt_dot343 = scenerect;
    sjt_math251 = (sjt_dot343)->h;
    sjt_dot344 = rect;
    sjt_math253 = (sjt_dot344)->y;
    sjt_dot345 = rect;
    sjt_math254 = (sjt_dot345)->h;
    sjt_math252 = sjt_math253 + sjt_math254;
    sjv_oldrect.y = sjt_math251 - sjt_math252;
    sjt_dot346 = rect;
    sjv_oldrect.w = (sjt_dot346)->w;
    sjt_dot347 = rect;
    sjv_oldrect.h = (sjt_dot347)->h;
    sjf_rect(&sjv_oldrect);
    sjt_parent107 = &sjv_glviewports;
    sjt_parent108 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent108, &sjt_math255);
    sjt_math256 = 1;
    sjt_functionParam186 = sjt_math255 - sjt_math256;
    sjf_list_rect_getat(sjt_parent107, sjt_functionParam186, &sjt_call41);
    sjt_parent105 = &sjt_call41;
    sjt_functionParam187 = &sjv_oldrect;
    sjf_rect_isequal(sjt_parent105, sjt_functionParam187, &sjt_not5);
    result10 = !sjt_not5;
    sjt_ifElse47 = result10;
    if (sjt_ifElse47) {
        sjs_string* sjt_functionParam188 = 0;

        sjt_call42._refCount = 1;
        sjt_call42.count = 30;
        sjt_call42.data._refCount = 1;
        sjt_call42.data.datasize = 31;
        sjt_call42.data.data = (void*)sjg_string31;
        sjt_call42.data._isglobal = true;
        sjt_call42.data.count = 31;
        sjf_array_char(&sjt_call42.data);
        sjf_string(&sjt_call42);
        sjt_functionParam188 = &sjt_call42;
        sjf_halt(sjt_functionParam188);
    }

    sjt_parent109 = &sjv_glviewports;
    sjt_parent110 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent110, &sjt_math257);
    sjt_math258 = 1;
    sjt_functionParam189 = sjt_math257 - sjt_math258;
    sjf_list_rect_removeat(sjt_parent109, sjt_functionParam189);
    sjt_parent111 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent111, &sjt_compare103);
    sjt_compare104 = 0;
    sjt_ifElse48 = sjt_compare103 > sjt_compare104;
    if (sjt_ifElse48) {
        int32_t sjt_functionParam190;
        int32_t sjt_math259;
        int32_t sjt_math260;
        sjs_list_rect* sjt_parent112 = 0;
        sjs_list_rect* sjt_parent113 = 0;

        sjt_parent112 = &sjv_glviewports;
        sjt_parent113 = &sjv_glviewports;
        sjf_list_rect_getcount(sjt_parent113, &sjt_math259);
        sjt_math260 = 1;
        sjt_functionParam190 = sjt_math259 - sjt_math260;
        sjf_list_rect_getat(sjt_parent112, sjt_functionParam190, &sjv_newrect);
    } else {
        sjv_newrect._refCount = 1;
        sjv_newrect.x = 0;
        sjv_newrect.y = 0;
        sjv_newrect.w = 0;
        sjv_newrect.h = 0;
        sjf_rect(&sjv_newrect);
    }

    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjt_call41._refCount == 1) { sjf_rect_destroy(&sjt_call41); }
    if (sjt_call42._refCount == 1) { sjf_string_destroy(&sjt_call42); }
    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
    if (sjv_oldrect._refCount == 1) { sjf_rect_destroy(&sjv_oldrect); }
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect* sjt_dot319 = 0;
    sjs_rect* sjt_dot320 = 0;
    sjs_rect* sjt_dot321 = 0;
    sjs_rect* sjt_dot322 = 0;
    sjs_rect* sjt_dot323 = 0;
    sjs_rect* sjt_dot324 = 0;
    sjs_rect* sjt_functionParam181 = 0;
    int32_t sjt_math245;
    int32_t sjt_math246;
    int32_t sjt_math247;
    int32_t sjt_math248;
    sjs_list_rect* sjt_parent100 = 0;
    sjs_rect sjv_newrect = { -1 };

    sjv_newrect._refCount = 1;
    sjt_dot319 = rect;
    sjv_newrect.x = (sjt_dot319)->x;
    sjt_dot320 = scenerect;
    sjt_math245 = (sjt_dot320)->h;
    sjt_dot321 = rect;
    sjt_math247 = (sjt_dot321)->y;
    sjt_dot322 = rect;
    sjt_math248 = (sjt_dot322)->h;
    sjt_math246 = sjt_math247 + sjt_math248;
    sjv_newrect.y = sjt_math245 - sjt_math246;
    sjt_dot323 = rect;
    sjv_newrect.w = (sjt_dot323)->w;
    sjt_dot324 = rect;
    sjv_newrect.h = (sjt_dot324)->h;
    sjf_rect(&sjv_newrect);
    sjt_parent100 = &sjv_glviewports;
    sjt_functionParam181 = &sjv_newrect;
    sjf_list_rect_add(sjt_parent100, sjt_functionParam181);
    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
}

void sjf_gluniformi32(int32_t loc, int32_t v) {
    glUniform1i(loc, v);
}

void sjf_gluniformmat4(int32_t loc, sjs_mat4* m) {
    glUniformMatrix4fv(loc, 1, 0, (GLfloat*)&m->m00);
}

void sjf_gluseprogram(sjs_shader* shader) {
    glUseProgram(shader->id);
}

void sjf_gridlayout(sjs_gridlayout* _this) {
}

void sjf_gridlayout_as_sji_element(sjs_gridlayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_gridlayout_element_vtbl;
}

void sjf_gridlayout_asinterface(sjs_gridlayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_gridlayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_gridlayout_copy(sjs_gridlayout* _this, sjs_gridlayout* _from) {
    _this->children._refCount = 1;
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
    _this->margin._refCount = 1;
    sjf_margin_copy(&_this->margin, &_from->margin);
    _this->cols._refCount = 1;
    sjf_array_gridunit_copy(&_this->cols, &_from->cols);
    _this->rows._refCount = 1;
    sjf_array_gridunit_copy(&_this->rows, &_from->rows);
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_gridlayout_destroy(sjs_gridlayout* _this) {
}

void sjf_gridlayout_firemouseevent(sjs_gridlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_gridlayout* sjt_dot84 = 0;
    sjs_array_heap_iface_element* sjt_functionParam38 = 0;
    sjs_mouseevent* sjt_parent27 = 0;

    sjt_parent27 = mouseevent;
    sjt_dot84 = _parent;
    sjt_functionParam38 = &(sjt_dot84)->children;
    sjf_mouseevent_firechildren(sjt_parent27, sjt_functionParam38, _return);
}

void sjf_gridlayout_getrect(sjs_gridlayout* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy1 = 0;
    sjs_gridlayout* sjt_dot13 = 0;

    sjt_dot13 = _parent;
    sjt_copy1 = &(sjt_dot13)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy1);
}

void sjf_gridlayout_getrect_heap(sjs_gridlayout* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy2 = 0;
    sjs_gridlayout* sjt_dot14 = 0;

    sjt_dot14 = _parent;
    sjt_copy2 = &(sjt_dot14)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy2);
}

void sjf_gridlayout_getsize(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot10 = 0;
    sjs_size* sjt_dot9 = 0;

    _return->_refCount = 1;
    sjt_dot9 = maxsize;
    _return->w = (sjt_dot9)->w;
    sjt_dot10 = maxsize;
    _return->h = (sjt_dot10)->h;
    sjf_size(_return);
}

void sjf_gridlayout_getsize_heap(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot11 = 0;
    sjs_size* sjt_dot12 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot11 = maxsize;
    (*_return)->w = (sjt_dot11)->w;
    sjt_dot12 = maxsize;
    (*_return)->h = (sjt_dot12)->h;
    sjf_size_heap((*_return));
}

void sjf_gridlayout_heap(sjs_gridlayout* _this) {
}

void sjf_gridlayout_render(sjs_gridlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot80 = 0;
    sjs_gridlayout* sjt_dot81 = 0;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;

    sjt_forStart6 = 0;
    sjt_dot81 = _parent;
    sjt_dot80 = &(sjt_dot81)->children;
    sjt_forEnd6 = (sjt_dot80)->count;
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        sjs_gridlayout* sjt_dot82 = 0;
        int32_t sjt_functionParam36;
        sjs_scene2d* sjt_interfaceParam2 = 0;
        sjs_array_heap_iface_element* sjt_parent23 = 0;
        sji_element sjt_parent24 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot82 = _parent;
        sjt_parent23 = &(sjt_dot82)->children;
        sjt_functionParam36 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent23, sjt_functionParam36, &sjv_child);
        sjt_parent24 = sjv_child;
        sjt_interfaceParam2 = scene;
        sjt_parent24._vtbl->render(sjt_parent24._parent, sjt_interfaceParam2);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }
}

void sjf_gridlayout_setrect(sjs_gridlayout* _parent, sjs_rect* rect_) {
    int32_t c;
    int32_t i;
    int32_t r;
    int32_t sjt_compare15;
    int32_t sjt_compare16;
    int32_t sjt_compare17;
    int32_t sjt_compare18;
    int32_t sjt_compare5;
    int32_t sjt_compare6;
    int32_t sjt_compare7;
    int32_t sjt_compare8;
    sjs_rect* sjt_copy3 = 0;
    sjs_gridlayout* sjt_dot15 = 0;
    sjs_gridlayout* sjt_dot36 = 0;
    sjs_array_gridunit* sjt_dot37 = 0;
    sjs_gridlayout* sjt_dot38 = 0;
    sjs_array_gridunit* sjt_dot45 = 0;
    sjs_gridlayout* sjt_dot46 = 0;
    sjs_rect* sjt_dot47 = 0;
    sjs_array_gridunit* sjt_dot48 = 0;
    sjs_gridlayout* sjt_dot49 = 0;
    sjs_array_gridunit* sjt_dot55 = 0;
    sjs_gridlayout* sjt_dot56 = 0;
    sjs_array_gridunit* sjt_dot63 = 0;
    sjs_gridlayout* sjt_dot64 = 0;
    sjs_rect* sjt_dot65 = 0;
    sjs_array_gridunit* sjt_dot66 = 0;
    sjs_gridlayout* sjt_dot67 = 0;
    sjs_array_heap_iface_element* sjt_dot73 = 0;
    sjs_gridlayout* sjt_dot74 = 0;
    int32_t sjt_forEnd1;
    int32_t sjt_forEnd2;
    int32_t sjt_forEnd3;
    int32_t sjt_forEnd4;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart1;
    int32_t sjt_forStart2;
    int32_t sjt_forStart3;
    int32_t sjt_forStart4;
    int32_t sjt_forStart5;
    sjs_margin* sjt_functionParam12 = 0;
    int32_t sjt_functionParam14;
    int32_t sjt_functionParam15;
    int32_t sjt_functionParam22;
    int32_t sjt_functionParam23;
    bool sjt_ifElse2;
    bool sjt_ifElse3;
    bool sjt_ifElse7;
    bool sjt_ifElse8;
    int32_t sjt_math41;
    int32_t sjt_math42;
    int32_t sjt_math67;
    int32_t sjt_math68;
    sjs_array_i32* sjt_parent10 = 0;
    sjs_rect* sjt_parent4 = 0;
    sjs_array_i32* sjt_parent6 = 0;
    int32_t sjv_cnext;
    int32_t sjv_colfixed;
    int32_t sjv_colstarremainder;
    int32_t sjv_colstars;
    int32_t sjv_colstarunit;
    sjs_rect sjv_innerrect = { -1 };
    int32_t sjv_rnext;
    int32_t sjv_rowfixed;
    int32_t sjv_rowstarremainder;
    int32_t sjv_rowstars;
    int32_t sjv_rowstarunit;
    int32_t sjv_x;
    sjs_array_i32 sjv_xpos = { -1 };
    int32_t sjv_y;
    sjs_array_i32 sjv_ypos = { -1 };

    sjt_dot15 = _parent;
    sjt_copy3 = rect_;
    sjt_dot15->_rect._refCount = 1;
    sjf_rect_copy(&sjt_dot15->_rect, sjt_copy3);
    sjt_parent4 = rect_;
    sjt_dot36 = _parent;
    sjt_functionParam12 = &(sjt_dot36)->margin;
    sjf_rect_subtractmargin(sjt_parent4, sjt_functionParam12, &sjv_innerrect);
    sjv_rowfixed = 0;
    sjv_rowstars = 0;
    sjt_forStart1 = 0;
    sjt_dot38 = _parent;
    sjt_dot37 = &(sjt_dot38)->rows;
    sjt_forEnd1 = (sjt_dot37)->count;
    r = sjt_forStart1;
    while (r < sjt_forEnd1) {
        int32_t sjt_compare3;
        int32_t sjt_compare4;
        sjs_gridlayout* sjt_dot39 = 0;
        sjs_gridunit* sjt_dot40 = 0;
        int32_t sjt_functionParam13;
        bool sjt_ifElse1;
        sjs_array_gridunit* sjt_parent5 = 0;
        sjs_gridunit sjv_row = { -1 };

        sjt_dot39 = _parent;
        sjt_parent5 = &(sjt_dot39)->rows;
        sjt_functionParam13 = r;
        sjf_array_gridunit_getat(sjt_parent5, sjt_functionParam13, &sjv_row);
        sjt_dot40 = &sjv_row;
        sjt_compare3 = (sjt_dot40)->type;
        sjt_compare4 = sjv_gridunittype_star;
        sjt_ifElse1 = sjt_compare3 == sjt_compare4;
        if (sjt_ifElse1) {
            sjs_gridunit* sjt_dot41 = 0;
            int32_t sjt_math29;
            int32_t sjt_math30;

            sjt_math29 = sjv_rowstars;
            sjt_dot41 = &sjv_row;
            sjt_math30 = (sjt_dot41)->amount;
            sjv_rowstars = sjt_math29 + sjt_math30;
        } else {
            sjs_gridunit* sjt_dot42 = 0;
            int32_t sjt_math31;
            int32_t sjt_math32;

            sjt_math31 = sjv_rowfixed;
            sjt_dot42 = &sjv_row;
            sjt_math32 = (sjt_dot42)->amount;
            sjv_rowfixed = sjt_math31 + sjt_math32;
        }

        r++;

        if (sjv_row._refCount == 1) { sjf_gridunit_destroy(&sjv_row); }
    }

    sjt_compare5 = sjv_rowstars;
    sjt_compare6 = 0;
    sjt_ifElse2 = sjt_compare5 > sjt_compare6;
    if (sjt_ifElse2) {
        sjs_rect* sjt_dot43 = 0;
        int32_t sjt_math33;
        int32_t sjt_math34;
        int32_t sjt_math35;
        int32_t sjt_math36;

        sjt_dot43 = &sjv_innerrect;
        sjt_math35 = (sjt_dot43)->h;
        sjt_math36 = sjv_rowfixed;
        sjt_math33 = sjt_math35 - sjt_math36;
        sjt_math34 = sjv_rowstars;
        sjv_rowstarunit = sjt_math33 / sjt_math34;
    } else {
        sjv_rowstarunit = 0;
    }

    sjt_compare7 = sjv_rowstars;
    sjt_compare8 = 0;
    sjt_ifElse3 = sjt_compare7 > sjt_compare8;
    if (sjt_ifElse3) {
        sjs_rect* sjt_dot44 = 0;
        int32_t sjt_math37;
        int32_t sjt_math38;
        int32_t sjt_math39;
        int32_t sjt_math40;

        sjt_dot44 = &sjv_innerrect;
        sjt_math39 = (sjt_dot44)->h;
        sjt_math40 = sjv_rowfixed;
        sjt_math37 = sjt_math39 - sjt_math40;
        sjt_math38 = sjv_rowstars;
        sjv_rowstarremainder = sjt_math37 % sjt_math38;
    } else {
        sjv_rowstarremainder = 0;
    }

    sjv_ypos._refCount = 1;
    sjt_dot46 = _parent;
    sjt_dot45 = &(sjt_dot46)->rows;
    sjt_math41 = (sjt_dot45)->count;
    sjt_math42 = 1;
    sjv_ypos.datasize = sjt_math41 + sjt_math42;
    sjv_ypos.data = 0;
    sjv_ypos._isglobal = false;
    sjv_ypos.count = 0;
    sjf_array_i32(&sjv_ypos);
    sjt_dot47 = &sjv_innerrect;
    sjv_y = (sjt_dot47)->y;
    sjt_parent6 = &sjv_ypos;
    sjt_functionParam14 = 0;
    sjt_functionParam15 = sjv_y;
    sjf_array_i32_initat(sjt_parent6, sjt_functionParam14, sjt_functionParam15);
    sjt_forStart2 = 0;
    sjt_dot49 = _parent;
    sjt_dot48 = &(sjt_dot49)->rows;
    sjt_forEnd2 = (sjt_dot48)->count;
    r = sjt_forStart2;
    while (r < sjt_forEnd2) {
        int32_t sjt_compare10;
        int32_t sjt_compare9;
        sjs_gridlayout* sjt_dot50 = 0;
        sjs_gridunit* sjt_dot51 = 0;
        int32_t sjt_functionParam16;
        int32_t sjt_functionParam19;
        int32_t sjt_functionParam20;
        bool sjt_ifElse4;
        int32_t sjt_math53;
        int32_t sjt_math54;
        sjs_array_gridunit* sjt_parent7 = 0;
        sjs_array_i32* sjt_parent8 = 0;
        sjs_gridunit sjv_row = { -1 };

        sjt_dot50 = _parent;
        sjt_parent7 = &(sjt_dot50)->rows;
        sjt_functionParam16 = r;
        sjf_array_gridunit_getat(sjt_parent7, sjt_functionParam16, &sjv_row);
        sjt_dot51 = &sjv_row;
        sjt_compare9 = (sjt_dot51)->type;
        sjt_compare10 = sjv_gridunittype_star;
        sjt_ifElse4 = sjt_compare9 == sjt_compare10;
        if (sjt_ifElse4) {
            sjs_gridunit* sjt_dot52 = 0;
            sjs_gridunit* sjt_dot53 = 0;
            int32_t sjt_functionParam17;
            int32_t sjt_functionParam18;
            int32_t sjt_math43;
            int32_t sjt_math44;
            int32_t sjt_math45;
            int32_t sjt_math46;
            int32_t sjt_math47;
            int32_t sjt_math48;
            int32_t sjt_math49;
            int32_t sjt_math50;

            sjt_math43 = sjv_y;
            sjt_math45 = sjv_rowstarunit;
            sjt_dot52 = &sjv_row;
            sjt_math46 = (sjt_dot52)->amount;
            sjt_math44 = sjt_math45 * sjt_math46;
            sjv_y = sjt_math43 + sjt_math44;
            sjt_math47 = sjv_y;
            sjt_functionParam17 = 0;
            sjt_functionParam18 = sjv_rowstarremainder;
            sjf_i32_max(sjt_functionParam17, sjt_functionParam18, &sjt_math48);
            sjv_y = sjt_math47 + sjt_math48;
            sjt_math49 = sjv_rowstarremainder;
            sjt_dot53 = &sjv_row;
            sjt_math50 = (sjt_dot53)->amount;
            sjv_rowstarremainder = sjt_math49 - sjt_math50;
        } else {
            sjs_gridunit* sjt_dot54 = 0;
            int32_t sjt_math51;
            int32_t sjt_math52;

            sjt_math51 = sjv_y;
            sjt_dot54 = &sjv_row;
            sjt_math52 = (sjt_dot54)->amount;
            sjv_y = sjt_math51 + sjt_math52;
        }

        sjt_parent8 = &sjv_ypos;
        sjt_math53 = r;
        sjt_math54 = 1;
        sjt_functionParam19 = sjt_math53 + sjt_math54;
        sjt_functionParam20 = sjv_y;
        sjf_array_i32_initat(sjt_parent8, sjt_functionParam19, sjt_functionParam20);
        r++;

        if (sjv_row._refCount == 1) { sjf_gridunit_destroy(&sjv_row); }
    }

    sjv_colfixed = 0;
    sjv_colstars = 0;
    sjt_forStart3 = 0;
    sjt_dot56 = _parent;
    sjt_dot55 = &(sjt_dot56)->cols;
    sjt_forEnd3 = (sjt_dot55)->count;
    c = sjt_forStart3;
    while (c < sjt_forEnd3) {
        int32_t sjt_compare13;
        int32_t sjt_compare14;
        sjs_gridlayout* sjt_dot57 = 0;
        sjs_gridunit* sjt_dot58 = 0;
        int32_t sjt_functionParam21;
        bool sjt_ifElse6;
        sjs_array_gridunit* sjt_parent9 = 0;
        sjs_gridunit sjv_col = { -1 };

        sjt_dot57 = _parent;
        sjt_parent9 = &(sjt_dot57)->cols;
        sjt_functionParam21 = c;
        sjf_array_gridunit_getat(sjt_parent9, sjt_functionParam21, &sjv_col);
        sjt_dot58 = &sjv_col;
        sjt_compare13 = (sjt_dot58)->type;
        sjt_compare14 = sjv_gridunittype_star;
        sjt_ifElse6 = sjt_compare13 == sjt_compare14;
        if (sjt_ifElse6) {
            sjs_gridunit* sjt_dot59 = 0;
            int32_t sjt_math55;
            int32_t sjt_math56;

            sjt_math55 = sjv_colstars;
            sjt_dot59 = &sjv_col;
            sjt_math56 = (sjt_dot59)->amount;
            sjv_colstars = sjt_math55 + sjt_math56;
        } else {
            sjs_gridunit* sjt_dot60 = 0;
            int32_t sjt_math57;
            int32_t sjt_math58;

            sjt_math57 = sjv_colfixed;
            sjt_dot60 = &sjv_col;
            sjt_math58 = (sjt_dot60)->amount;
            sjv_colfixed = sjt_math57 + sjt_math58;
        }

        c++;

        if (sjv_col._refCount == 1) { sjf_gridunit_destroy(&sjv_col); }
    }

    sjt_compare15 = sjv_colstars;
    sjt_compare16 = 0;
    sjt_ifElse7 = sjt_compare15 > sjt_compare16;
    if (sjt_ifElse7) {
        sjs_rect* sjt_dot61 = 0;
        int32_t sjt_math59;
        int32_t sjt_math60;
        int32_t sjt_math61;
        int32_t sjt_math62;

        sjt_dot61 = &sjv_innerrect;
        sjt_math61 = (sjt_dot61)->w;
        sjt_math62 = sjv_colfixed;
        sjt_math59 = sjt_math61 - sjt_math62;
        sjt_math60 = sjv_colstars;
        sjv_colstarunit = sjt_math59 / sjt_math60;
    } else {
        sjv_colstarunit = 0;
    }

    sjt_compare17 = sjv_colstars;
    sjt_compare18 = 0;
    sjt_ifElse8 = sjt_compare17 > sjt_compare18;
    if (sjt_ifElse8) {
        sjs_rect* sjt_dot62 = 0;
        int32_t sjt_math63;
        int32_t sjt_math64;
        int32_t sjt_math65;
        int32_t sjt_math66;

        sjt_dot62 = &sjv_innerrect;
        sjt_math65 = (sjt_dot62)->w;
        sjt_math66 = sjv_colfixed;
        sjt_math63 = sjt_math65 - sjt_math66;
        sjt_math64 = sjv_colstars;
        sjv_colstarremainder = sjt_math63 % sjt_math64;
    } else {
        sjv_colstarremainder = 0;
    }

    sjv_xpos._refCount = 1;
    sjt_dot64 = _parent;
    sjt_dot63 = &(sjt_dot64)->cols;
    sjt_math67 = (sjt_dot63)->count;
    sjt_math68 = 1;
    sjv_xpos.datasize = sjt_math67 + sjt_math68;
    sjv_xpos.data = 0;
    sjv_xpos._isglobal = false;
    sjv_xpos.count = 0;
    sjf_array_i32(&sjv_xpos);
    sjt_dot65 = &sjv_innerrect;
    sjv_x = (sjt_dot65)->x;
    sjt_parent10 = &sjv_xpos;
    sjt_functionParam22 = 0;
    sjt_functionParam23 = sjv_x;
    sjf_array_i32_initat(sjt_parent10, sjt_functionParam22, sjt_functionParam23);
    sjt_forStart4 = 0;
    sjt_dot67 = _parent;
    sjt_dot66 = &(sjt_dot67)->cols;
    sjt_forEnd4 = (sjt_dot66)->count;
    c = sjt_forStart4;
    while (c < sjt_forEnd4) {
        int32_t sjt_compare19;
        int32_t sjt_compare20;
        sjs_gridlayout* sjt_dot68 = 0;
        sjs_gridunit* sjt_dot69 = 0;
        int32_t sjt_functionParam24;
        int32_t sjt_functionParam27;
        int32_t sjt_functionParam28;
        bool sjt_ifElse9;
        int32_t sjt_math79;
        int32_t sjt_math80;
        sjs_array_gridunit* sjt_parent11 = 0;
        sjs_array_i32* sjt_parent12 = 0;
        sjs_gridunit sjv_col = { -1 };

        sjt_dot68 = _parent;
        sjt_parent11 = &(sjt_dot68)->cols;
        sjt_functionParam24 = c;
        sjf_array_gridunit_getat(sjt_parent11, sjt_functionParam24, &sjv_col);
        sjt_dot69 = &sjv_col;
        sjt_compare19 = (sjt_dot69)->type;
        sjt_compare20 = sjv_gridunittype_star;
        sjt_ifElse9 = sjt_compare19 == sjt_compare20;
        if (sjt_ifElse9) {
            sjs_gridunit* sjt_dot70 = 0;
            sjs_gridunit* sjt_dot71 = 0;
            int32_t sjt_functionParam25;
            int32_t sjt_functionParam26;
            int32_t sjt_math69;
            int32_t sjt_math70;
            int32_t sjt_math71;
            int32_t sjt_math72;
            int32_t sjt_math73;
            int32_t sjt_math74;
            int32_t sjt_math75;
            int32_t sjt_math76;

            sjt_math69 = sjv_x;
            sjt_math71 = sjv_colstarunit;
            sjt_dot70 = &sjv_col;
            sjt_math72 = (sjt_dot70)->amount;
            sjt_math70 = sjt_math71 * sjt_math72;
            sjv_x = sjt_math69 + sjt_math70;
            sjt_math73 = sjv_x;
            sjt_functionParam25 = 0;
            sjt_functionParam26 = sjv_colstarremainder;
            sjf_i32_max(sjt_functionParam25, sjt_functionParam26, &sjt_math74);
            sjv_x = sjt_math73 + sjt_math74;
            sjt_math75 = sjv_colstarremainder;
            sjt_dot71 = &sjv_col;
            sjt_math76 = (sjt_dot71)->amount;
            sjv_colstarremainder = sjt_math75 - sjt_math76;
        } else {
            sjs_gridunit* sjt_dot72 = 0;
            int32_t sjt_math77;
            int32_t sjt_math78;

            sjt_math77 = sjv_x;
            sjt_dot72 = &sjv_col;
            sjt_math78 = (sjt_dot72)->amount;
            sjv_x = sjt_math77 + sjt_math78;
        }

        sjt_parent12 = &sjv_xpos;
        sjt_math79 = c;
        sjt_math80 = 1;
        sjt_functionParam27 = sjt_math79 + sjt_math80;
        sjt_functionParam28 = sjv_x;
        sjf_array_i32_initat(sjt_parent12, sjt_functionParam27, sjt_functionParam28);
        c++;

        if (sjv_col._refCount == 1) { sjf_gridunit_destroy(&sjv_col); }
    }

    sjv_rnext = 0;
    sjv_cnext = 0;
    sjt_forStart5 = 0;
    sjt_dot74 = _parent;
    sjt_dot73 = &(sjt_dot74)->children;
    sjt_forEnd5 = (sjt_dot73)->count;
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        sjs_rect sjt_call4 = { -1 };
        sji_element sjt_cast2 = { 0 };
        sjs_gridlayout* sjt_dot75 = 0;
        int32_t sjt_functionParam29;
        int32_t sjt_functionParam30;
        int32_t sjt_functionParam31;
        int32_t sjt_functionParam32;
        int32_t sjt_functionParam33;
        int32_t sjt_functionParam34;
        int32_t sjt_functionParam35;
        sjs_rect* sjt_interfaceParam1 = 0;
        bool sjt_isEmpty1;
        sji_gridchild sjt_isEmpty2 = { 0 };
        int32_t sjt_math85;
        int32_t sjt_math86;
        int32_t sjt_math87;
        int32_t sjt_math88;
        int32_t sjt_math89;
        int32_t sjt_math90;
        int32_t sjt_math91;
        int32_t sjt_math92;
        sjs_array_heap_iface_element* sjt_parent13 = 0;
        sji_element sjt_parent16 = { 0 };
        sjs_array_i32* sjt_parent17 = 0;
        sjs_array_i32* sjt_parent18 = 0;
        sjs_array_i32* sjt_parent19 = 0;
        sjs_array_i32* sjt_parent20 = 0;
        sjs_array_i32* sjt_parent21 = 0;
        sjs_array_i32* sjt_parent22 = 0;
        int32_t sjv_c;
        sji_element sjv_child = { 0 };
        sji_gridchild sjv_gridchild = { 0 };
        int32_t sjv_r;

        sjv_r = 0;
        sjv_c = 0;
        sjt_dot75 = _parent;
        sjt_parent13 = &(sjt_dot75)->children;
        sjt_functionParam29 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent13, sjt_functionParam29, &sjv_child);
        sjt_cast2 = sjv_child;
        sjt_cast2._vtbl->asinterface(sjt_cast2._parent, sji_gridchild_typeId, (sjs_interface*)&sjv_gridchild);
        if (sjv_gridchild._parent != 0) {
            sjv_gridchild._parent->_refCount++;
        }

        sjt_isEmpty2 = sjv_gridchild;
        sjt_isEmpty1 = (sjt_isEmpty2._parent != 0);
        if (sjt_isEmpty1) {
            sji_gridchild ifValue1 = { 0 };
            sji_gridchild sjt_parent14 = { 0 };
            sji_gridchild sjt_parent15 = { 0 };

            ifValue1 = sjv_gridchild;
            if (ifValue1._parent != 0) {
                ifValue1._parent->_refCount++;
            }

            sjt_parent14 = ifValue1;
            sjt_parent14._vtbl->getrow(sjt_parent14._parent, &sjv_r);
            sjt_parent15 = ifValue1;
            sjt_parent15._vtbl->getcol(sjt_parent15._parent, &sjv_c);

            if (ifValue1._parent != 0) {
                ifValue1._parent->_refCount--;
                if (ifValue1._parent->_refCount <= 0) {
                    ifValue1._vtbl->destroy(ifValue1._parent);
                    free(ifValue1._parent);
                }
            }
        } else {
            int32_t sjt_compare21;
            int32_t sjt_compare22;
            sjs_array_gridunit* sjt_dot76 = 0;
            sjs_gridlayout* sjt_dot77 = 0;
            bool sjt_ifElse10;
            int32_t sjt_math81;
            int32_t sjt_math82;

            sjv_r = sjv_rnext;
            sjv_c = sjv_cnext;
            sjt_math81 = sjv_cnext;
            sjt_math82 = 1;
            sjv_cnext = sjt_math81 + sjt_math82;
            sjt_compare21 = sjv_cnext;
            sjt_dot77 = _parent;
            sjt_dot76 = &(sjt_dot77)->cols;
            sjt_compare22 = (sjt_dot76)->count;
            sjt_ifElse10 = sjt_compare21 >= sjt_compare22;
            if (sjt_ifElse10) {
                int32_t sjt_compare23;
                int32_t sjt_compare24;
                sjs_array_gridunit* sjt_dot78 = 0;
                sjs_gridlayout* sjt_dot79 = 0;
                bool sjt_ifElse11;
                int32_t sjt_math83;
                int32_t sjt_math84;

                sjv_cnext = 0;
                sjt_math83 = sjv_rnext;
                sjt_math84 = 1;
                sjv_rnext = sjt_math83 + sjt_math84;
                sjt_compare23 = sjv_rnext;
                sjt_dot79 = _parent;
                sjt_dot78 = &(sjt_dot79)->rows;
                sjt_compare24 = (sjt_dot78)->count;
                sjt_ifElse11 = sjt_compare23 >= sjt_compare24;
                if (sjt_ifElse11) {
                    sjv_rnext = 0;
                }
            }
        }

        sjt_parent16 = sjv_child;
        sjt_call4._refCount = 1;
        sjt_parent17 = &sjv_xpos;
        sjt_functionParam30 = sjv_c;
        sjf_array_i32_getat(sjt_parent17, sjt_functionParam30, &sjt_call4.x);
        sjt_parent18 = &sjv_ypos;
        sjt_functionParam31 = sjv_r;
        sjf_array_i32_getat(sjt_parent18, sjt_functionParam31, &sjt_call4.y);
        sjt_parent19 = &sjv_xpos;
        sjt_math87 = sjv_c;
        sjt_math88 = 1;
        sjt_functionParam32 = sjt_math87 + sjt_math88;
        sjf_array_i32_getat(sjt_parent19, sjt_functionParam32, &sjt_math85);
        sjt_parent20 = &sjv_xpos;
        sjt_functionParam33 = sjv_c;
        sjf_array_i32_getat(sjt_parent20, sjt_functionParam33, &sjt_math86);
        sjt_call4.w = sjt_math85 - sjt_math86;
        sjt_parent21 = &sjv_ypos;
        sjt_math91 = sjv_r;
        sjt_math92 = 1;
        sjt_functionParam34 = sjt_math91 + sjt_math92;
        sjf_array_i32_getat(sjt_parent21, sjt_functionParam34, &sjt_math89);
        sjt_parent22 = &sjv_ypos;
        sjt_functionParam35 = sjv_r;
        sjf_array_i32_getat(sjt_parent22, sjt_functionParam35, &sjt_math90);
        sjt_call4.h = sjt_math89 - sjt_math90;
        sjf_rect(&sjt_call4);
        sjt_interfaceParam1 = &sjt_call4;
        sjt_parent16._vtbl->setrect(sjt_parent16._parent, sjt_interfaceParam1);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjv_gridchild._parent != 0) {
            sjv_gridchild._parent->_refCount--;
            if (sjv_gridchild._parent->_refCount <= 0) {
                sjv_gridchild._vtbl->destroy(sjv_gridchild._parent);
                free(sjv_gridchild._parent);
            }
        }
        if (sjt_call4._refCount == 1) { sjf_rect_destroy(&sjt_call4); }
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
    if (sjv_xpos._refCount == 1) { sjf_array_i32_destroy(&sjv_xpos); }
    if (sjv_ypos._refCount == 1) { sjf_array_i32_destroy(&sjv_ypos); }
}

void sjf_gridunit(sjs_gridunit* _this) {
}

void sjf_gridunit_copy(sjs_gridunit* _this, sjs_gridunit* _from) {
    _this->amount = _from->amount;
    _this->type = _from->type;
}

void sjf_gridunit_destroy(sjs_gridunit* _this) {
}

void sjf_gridunit_heap(sjs_gridunit* _this) {
}

void sjf_halt(sjs_string* reason) {
    halt("%s\n", (char*)reason->data.data);
}

void sjf_hash_fontkey_weak_font(sjs_hash_fontkey_weak_font* _this) {
    _this->_hash = kh_init(fontkey_weak_font_hash_type);
}

void sjf_hash_fontkey_weak_font__weakptrremovekey(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key) {
    #if false
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(fontkey_weak_font_hash_type, p, k);
    }
    #endif
}

void sjf_hash_fontkey_weak_font__weakptrremovevalue(sjs_hash_fontkey_weak_font* _parent, sjs_font* val) {
    #if true
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            sjs_font* t = kh_value(p, k);
            if ((t == val)) {
                kh_del(fontkey_weak_font_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_fontkey_weak_font_copy(sjs_hash_fontkey_weak_font* _this, sjs_hash_fontkey_weak_font* _from) {
    _this->_hash = _from->_hash;
    ptr_retain(_this->_hash);
}

void sjf_hash_fontkey_weak_font_destroy(sjs_hash_fontkey_weak_font* _this) {
    if (ptr_release(_this->_hash)) {
        khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_this->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if true
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k), cb);
                #else
                delete_cb weakptrcb13 = { &kh_value(p, k), weakptr_clear };
if (kh_value(p, k) != 0) { weakptr_cb_remove(kh_value(p, k), weakptrcb13); }
;
                #endif
            }
        }
        kh_destroy(fontkey_weak_font_hash_type, _this->_hash);
    }
}

void sjf_hash_fontkey_weak_font_getat(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font** _return) {
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, *key);
    #else
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return) = 0;
delete_cb weakptrcb20 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb20); }
return;
    }
    (*_return) = kh_val(p, k);
delete_cb weakptrcb21 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb21); }
return;;
}

void sjf_hash_fontkey_weak_font_heap(sjs_hash_fontkey_weak_font* _this) {
    _this->_hash = kh_init(fontkey_weak_font_hash_type);
}

void sjf_hash_fontkey_weak_font_setat(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font* val) {
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, *key);
    #else
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    delete_cb weakptrcb22 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_remove(kh_val(p, k), weakptrcb22); }
;
}
int ret;
#if true
k = kh_put(fontkey_weak_font_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(fontkey_weak_font_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(fontkey_weak_font_hash_type, p, k);
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovekey };
weakptr_cb_add(key, cb);
#else
sjs_fontkey t;
t._refCount = 1;
sjf_fontkey_copy(&t, key);
;
#endif
#if true
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovevalue };
weakptr_cb_add(val, cb);
kh_val(p, k) = val;
#else
kh_val(p, k) = val;
delete_cb weakptrcb23 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_add(kh_val(p, k), weakptrcb23); }
;
#endif
}

void sjf_hash_string_weak_iface_element(sjs_hash_string_weak_iface_element* _this) {
    _this->_hash = kh_init(string_weak_iface_element_hash_type);
}

void sjf_hash_string_weak_iface_element__weakptrremovekey(sjs_hash_string_weak_iface_element* _parent, sjs_string* key) {
    #if false
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(string_weak_iface_element_hash_type, p, k);
    }
    #endif
}

void sjf_hash_string_weak_iface_element__weakptrremovevalue(sjs_hash_string_weak_iface_element* _parent, sji_element val) {
    #if true
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            sji_element t = kh_value(p, k);
            if ((t._parent == val._parent)) {
                kh_del(string_weak_iface_element_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_string_weak_iface_element_copy(sjs_hash_string_weak_iface_element* _this, sjs_hash_string_weak_iface_element* _from) {
    _this->_hash = _from->_hash;
    ptr_retain(_this->_hash);
}

void sjf_hash_string_weak_iface_element_destroy(sjs_hash_string_weak_iface_element* _this) {
    if (ptr_release(_this->_hash)) {
        khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_this->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if true
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k)._parent, cb);
                #else
                delete_cb weakptrcb12 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb12); }
;
                #endif
            }
        }
        kh_destroy(string_weak_iface_element_hash_type, _this->_hash);
    }
}

void sjf_hash_string_weak_iface_element_getat(sjs_hash_string_weak_iface_element* _parent, sjs_string* key, sji_element* _return) {
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return)._parent = 0;
return;
    }
    (*_return) = kh_val(p, k);
delete_cb weakptrcb25 = { &(*_return)._parent, weakptr_clear };
if ((*_return)._parent != 0) { weakptr_cb_add((*_return)._parent, weakptrcb25); }
return;;
}

void sjf_hash_string_weak_iface_element_heap(sjs_hash_string_weak_iface_element* _this) {
    _this->_hash = kh_init(string_weak_iface_element_hash_type);
}

void sjf_hash_string_weak_iface_element_setat(sjs_hash_string_weak_iface_element* _parent, sjs_string* key, sji_element val) {
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    delete_cb weakptrcb26 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_remove(kh_val(p, k)._parent, weakptrcb26); }
;
}
int ret;
#if true
k = kh_put(string_weak_iface_element_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(string_weak_iface_element_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(string_weak_iface_element_hash_type, p, k);
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovekey };
weakptr_cb_add(key, cb);
#else
sjs_string t;
t._refCount = 1;
sjf_string_copy(&t, key);
;
#endif
#if true
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovevalue };
weakptr_cb_add(val._parent, cb);
kh_val(p, k) = val;
#else
kh_val(p, k) = val;
delete_cb weakptrcb27 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_add(kh_val(p, k)._parent, weakptrcb27); }
;
#endif
}

void sjf_hash_string_weak_iface_model(sjs_hash_string_weak_iface_model* _this) {
    _this->_hash = kh_init(string_weak_iface_model_hash_type);
}

void sjf_hash_string_weak_iface_model__weakptrremovekey(sjs_hash_string_weak_iface_model* _parent, sjs_string* key) {
    #if false
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(string_weak_iface_model_hash_type, p, k);
    }
    #endif
}

void sjf_hash_string_weak_iface_model__weakptrremovevalue(sjs_hash_string_weak_iface_model* _parent, sji_model val) {
    #if true
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            sji_model t = kh_value(p, k);
            if ((t._parent == val._parent)) {
                kh_del(string_weak_iface_model_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_string_weak_iface_model_copy(sjs_hash_string_weak_iface_model* _this, sjs_hash_string_weak_iface_model* _from) {
    _this->_hash = _from->_hash;
    ptr_retain(_this->_hash);
}

void sjf_hash_string_weak_iface_model_destroy(sjs_hash_string_weak_iface_model* _this) {
    if (ptr_release(_this->_hash)) {
        khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_this->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if true
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k)._parent, cb);
                #else
                delete_cb weakptrcb11 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb11); }
;
                #endif
            }
        }
        kh_destroy(string_weak_iface_model_hash_type, _this->_hash);
    }
}

void sjf_hash_string_weak_iface_model_heap(sjs_hash_string_weak_iface_model* _this) {
    _this->_hash = kh_init(string_weak_iface_model_hash_type);
}

void sjf_i32_asmargin(int32_t x, sjs_margin* _return) {
    _return->_refCount = 1;
    _return->l = x;
    _return->t = x;
    _return->r = x;
    _return->b = x;
    sjf_margin(_return);
}

void sjf_i32_asmargin_heap(int32_t x, sjs_margin** _return) {
    (*_return) = (sjs_margin*)malloc(sizeof(sjs_margin));
    (*_return)->_refCount = 1;
    (*_return)->l = x;
    (*_return)->t = x;
    (*_return)->r = x;
    (*_return)->b = x;
    sjf_margin_heap((*_return));
}

void sjf_i32_asstring(int32_t val, sjs_string* _return) {
    int32_t sjt_math143;
    int32_t sjt_math144;
    int32_t sjt_math145;
    int32_t sjt_math146;
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = malloc(sizeof(char) * 50);
    snprintf((char*)sjv_data, 50, "%d", val);
    sjv_count = strlen((char*)sjv_data);
    _return->_refCount = 1;
    _return->count = sjv_count;
    _return->data._refCount = 1;
    sjt_math143 = sjv_count;
    sjt_math144 = 1;
    _return->data.datasize = sjt_math143 + sjt_math144;
    _return->data.data = sjv_data;
    _return->data._isglobal = false;
    sjt_math145 = sjv_count;
    sjt_math146 = 1;
    _return->data.count = sjt_math145 + sjt_math146;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, sjs_string** _return) {
    int32_t sjt_math147;
    int32_t sjt_math148;
    int32_t sjt_math149;
    int32_t sjt_math150;
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = malloc(sizeof(char) * 50);
    snprintf((char*)sjv_data, 50, "%d", val);
    sjv_count = strlen((char*)sjv_data);
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = sjv_count;
    (*_return)->data._refCount = 1;
    sjt_math147 = sjv_count;
    sjt_math148 = 1;
    (*_return)->data.datasize = sjt_math147 + sjt_math148;
    (*_return)->data.data = sjv_data;
    (*_return)->data._isglobal = false;
    sjt_math149 = sjv_count;
    sjt_math150 = 1;
    (*_return)->data.count = sjt_math149 + sjt_math150;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    int32_t sjt_compare11;
    int32_t sjt_compare12;
    bool sjt_ifElse5;

    sjt_compare11 = a;
    sjt_compare12 = b;
    sjt_ifElse5 = sjt_compare11 < sjt_compare12;
    if (sjt_ifElse5) {
        (*_return) = b;
    } else {
        (*_return) = a;
    }
}

void sjf_image(sjs_image* _this) {
    bool sjt_and3;
    bool sjt_and4;
    sjs_rect sjt_call6 = { -1 };
    int32_t sjt_compare25;
    int32_t sjt_compare26;
    int32_t sjt_compare27;
    int32_t sjt_compare28;
    sjs_rect* sjt_dot85 = 0;
    sjs_rect* sjt_dot86 = 0;
    bool sjt_ifElse13;
    sjs_size sjv_size = { -1 };

    sjt_dot85 = &_this->rect;
    sjt_compare25 = (sjt_dot85)->w;
    sjt_compare26 = 0;
    sjt_and3 = sjt_compare25 == sjt_compare26;
    sjt_dot86 = &_this->rect;
    sjt_compare27 = (sjt_dot86)->h;
    sjt_compare28 = 0;
    sjt_and4 = sjt_compare27 == sjt_compare28;
    sjt_ifElse13 = sjt_and3 && sjt_and4;
    if (sjt_ifElse13) {
        sjs_rect* sjt_copy4 = 0;
        sjs_size* sjt_dot95 = 0;
        sjs_size* sjt_dot96 = 0;
        sjs_texture* sjt_parent29 = 0;

        sjt_parent29 = &_this->texture;
        sjf_texture_getsize(sjt_parent29, &sjv_size);
        sjt_call6._refCount = 1;
        sjt_call6.x = 0;
        sjt_call6.y = 0;
        sjt_dot95 = &sjv_size;
        sjt_call6.w = (sjt_dot95)->w;
        sjt_dot96 = &sjv_size;
        sjt_call6.h = (sjt_dot96)->h;
        sjf_rect(&sjt_call6);
        sjt_copy4 = &sjt_call6;
        _this->rect._refCount = 1;
        sjf_rect_copy(&_this->rect, sjt_copy4);
    }

    if (sjt_call6._refCount == 1) { sjf_rect_destroy(&sjt_call6); }
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
}

void sjf_image_copy(sjs_image* _this, sjs_image* _from) {
    _this->texture._refCount = 1;
    sjf_texture_copy(&_this->texture, &_from->texture);
    _this->rect._refCount = 1;
    sjf_rect_copy(&_this->rect, &_from->rect);
    _this->margin._refCount = 1;
    sjf_margin_copy(&_this->margin, &_from->margin);
}

void sjf_image_destroy(sjs_image* _this) {
}

void sjf_image_heap(sjs_image* _this) {
    bool sjt_and5;
    bool sjt_and6;
    sjs_rect sjt_call7 = { -1 };
    int32_t sjt_compare29;
    int32_t sjt_compare30;
    int32_t sjt_compare31;
    int32_t sjt_compare32;
    sjs_rect* sjt_dot97 = 0;
    sjs_rect* sjt_dot98 = 0;
    bool sjt_ifElse14;
    sjs_size sjv_size = { -1 };

    sjt_dot97 = &_this->rect;
    sjt_compare29 = (sjt_dot97)->w;
    sjt_compare30 = 0;
    sjt_and5 = sjt_compare29 == sjt_compare30;
    sjt_dot98 = &_this->rect;
    sjt_compare31 = (sjt_dot98)->h;
    sjt_compare32 = 0;
    sjt_and6 = sjt_compare31 == sjt_compare32;
    sjt_ifElse14 = sjt_and5 && sjt_and6;
    if (sjt_ifElse14) {
        sjs_rect* sjt_copy5 = 0;
        sjs_size* sjt_dot100 = 0;
        sjs_size* sjt_dot99 = 0;
        sjs_texture* sjt_parent30 = 0;

        sjt_parent30 = &_this->texture;
        sjf_texture_getsize(sjt_parent30, &sjv_size);
        sjt_call7._refCount = 1;
        sjt_call7.x = 0;
        sjt_call7.y = 0;
        sjt_dot99 = &sjv_size;
        sjt_call7.w = (sjt_dot99)->w;
        sjt_dot100 = &sjv_size;
        sjt_call7.h = (sjt_dot100)->h;
        sjf_rect(&sjt_call7);
        sjt_copy5 = &sjt_call7;
        _this->rect._refCount = 1;
        sjf_rect_copy(&_this->rect, sjt_copy5);
    }

    if (sjt_call7._refCount == 1) { sjf_rect_destroy(&sjt_call7); }
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
}

void sjf_imagerenderer(sjs_imagerenderer* _this) {
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
    float x0 = (float)_this->rect.x;
    float x1 = (float)(_this->rect.x + _this->image.margin.l);
    float x2 = (float)(_this->rect.x + _this->rect.w - _this->image.margin.r);
    float x3 = (float)(_this->rect.x + _this->rect.w);
    float y0 = (float)_this->rect.y;
    float y1 = (float)(_this->rect.y + _this->image.margin.t);
    float y2 = (float)(_this->rect.y + _this->rect.h - _this->image.margin.b);
    float y3 = (float)(_this->rect.y + _this->rect.h);
    float s0 = (float)_this->image.rect.x / (float)_this->image.texture.size.w;
    float s1 = (float)(_this->image.rect.x + _this->image.margin.l) / (float)_this->image.texture.size.w;
    float s2 = (float)(_this->image.rect.x + _this->image.rect.w - _this->image.margin.r) / (float)_this->image.texture.size.w;
    float s3 = (float)(_this->image.rect.x + _this->image.rect.w) / (float)_this->image.texture.size.w;
    float t3 = (float)_this->image.rect.y / (float)_this->image.texture.size.h;
    float t2 = (float)(_this->image.rect.y + _this->image.margin.b) / (float)_this->image.texture.size.h;
    float t1 = (float)(_this->image.rect.y + _this->image.rect.h - _this->image.margin.t) / (float)_this->image.texture.size.h;
    float t0 = (float)(_this->image.rect.y + _this->image.rect.h) / (float)_this->image.texture.size.h;
    if (_this->image.margin.t > 0) {
        if (_this->image.margin.l > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x0, y0, 0.0f,  s0, t0 },
            { x0, y1, 0.0f,  s0, t1 },
            { x1, y1, 0.0f,  s1, t1 },
            { x1, y0, 0.0f,  s1, t0 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x1, y0, 0.0f,  s1, t0 },
            { x1, y1, 0.0f,  s1, t1 },
            { x2, y1, 0.0f,  s2, t1 },
            { x2, y0, 0.0f,  s2, t0 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        if (_this->image.margin.r > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x2, y0, 0.0f,  s2, t0 },
            { x2, y1, 0.0f,  s2, t1 },
            { x3, y1, 0.0f,  s3, t1 },
            { x3, y0, 0.0f,  s3, t0 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
    }
    {
        if (_this->image.margin.l > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x0, y1, 0.0f,  s0, t1 },
            { x0, y2, 0.0f,  s0, t2 },
            { x1, y2, 0.0f,  s1, t2 },
            { x1, y1, 0.0f,  s1, t1 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x1, y1, 0.0f,  s1, t1 },
            { x1, y2, 0.0f,  s1, t2 },
            { x2, y2, 0.0f,  s2, t2 },
            { x2, y1, 0.0f,  s2, t1 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        if (_this->image.margin.r > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x2, y1, 0.0f,  s2, t1 },
            { x2, y2, 0.0f,  s2, t2 },
            { x3, y2, 0.0f,  s3, t2 },
            { x3, y1, 0.0f,  s3, t1 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
    }
    if (_this->image.margin.b > 0) {
        if (_this->image.margin.l > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x0, y2, 0.0f,  s0, t2 },
            { x0, y3, 0.0f,  s0, t3 },
            { x1, y3, 0.0f,  s1, t3 },
            { x1, y2, 0.0f,  s1, t2 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x1, y2, 0.0f,  s1, t2 },
            { x1, y3, 0.0f,  s1, t3 },
            { x2, y3, 0.0f,  s2, t3 },
            { x2, y2, 0.0f,  s2, t2 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        if (_this->image.margin.r > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x2, y2, 0.0f,  s2, t2 },
            { x2, y3, 0.0f,  s2, t3 },
            { x3, y3, 0.0f,  s3, t3 },
            { x3, y2, 0.0f,  s3, t2 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
    }
}

void sjf_imagerenderer_copy(sjs_imagerenderer* _this, sjs_imagerenderer* _from) {
    _this->rect._refCount = 1;
    sjf_rect_copy(&_this->rect, &_from->rect);
    _this->image._refCount = 1;
    sjf_image_copy(&_this->image, &_from->image);
    _this->buffer = _from->buffer;
    ptr_retain(_this->buffer);
}

void sjf_imagerenderer_destroy(sjs_imagerenderer* _this) {
    if (ptr_release(_this->buffer)) {
        vertex_buffer_delete(_this->buffer);
    }  
}

void sjf_imagerenderer_heap(sjs_imagerenderer* _this) {
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
    float x0 = (float)_this->rect.x;
    float x1 = (float)(_this->rect.x + _this->image.margin.l);
    float x2 = (float)(_this->rect.x + _this->rect.w - _this->image.margin.r);
    float x3 = (float)(_this->rect.x + _this->rect.w);
    float y0 = (float)_this->rect.y;
    float y1 = (float)(_this->rect.y + _this->image.margin.t);
    float y2 = (float)(_this->rect.y + _this->rect.h - _this->image.margin.b);
    float y3 = (float)(_this->rect.y + _this->rect.h);
    float s0 = (float)_this->image.rect.x / (float)_this->image.texture.size.w;
    float s1 = (float)(_this->image.rect.x + _this->image.margin.l) / (float)_this->image.texture.size.w;
    float s2 = (float)(_this->image.rect.x + _this->image.rect.w - _this->image.margin.r) / (float)_this->image.texture.size.w;
    float s3 = (float)(_this->image.rect.x + _this->image.rect.w) / (float)_this->image.texture.size.w;
    float t3 = (float)_this->image.rect.y / (float)_this->image.texture.size.h;
    float t2 = (float)(_this->image.rect.y + _this->image.margin.b) / (float)_this->image.texture.size.h;
    float t1 = (float)(_this->image.rect.y + _this->image.rect.h - _this->image.margin.t) / (float)_this->image.texture.size.h;
    float t0 = (float)(_this->image.rect.y + _this->image.rect.h) / (float)_this->image.texture.size.h;
    if (_this->image.margin.t > 0) {
        if (_this->image.margin.l > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x0, y0, 0.0f,  s0, t0 },
            { x0, y1, 0.0f,  s0, t1 },
            { x1, y1, 0.0f,  s1, t1 },
            { x1, y0, 0.0f,  s1, t0 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x1, y0, 0.0f,  s1, t0 },
            { x1, y1, 0.0f,  s1, t1 },
            { x2, y1, 0.0f,  s2, t1 },
            { x2, y0, 0.0f,  s2, t0 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        if (_this->image.margin.r > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x2, y0, 0.0f,  s2, t0 },
            { x2, y1, 0.0f,  s2, t1 },
            { x3, y1, 0.0f,  s3, t1 },
            { x3, y0, 0.0f,  s3, t0 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
    }
    {
        if (_this->image.margin.l > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x0, y1, 0.0f,  s0, t1 },
            { x0, y2, 0.0f,  s0, t2 },
            { x1, y2, 0.0f,  s1, t2 },
            { x1, y1, 0.0f,  s1, t1 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x1, y1, 0.0f,  s1, t1 },
            { x1, y2, 0.0f,  s1, t2 },
            { x2, y2, 0.0f,  s2, t2 },
            { x2, y1, 0.0f,  s2, t1 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        if (_this->image.margin.r > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x2, y1, 0.0f,  s2, t1 },
            { x2, y2, 0.0f,  s2, t2 },
            { x3, y2, 0.0f,  s3, t2 },
            { x3, y1, 0.0f,  s3, t1 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
    }
    if (_this->image.margin.b > 0) {
        if (_this->image.margin.l > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x0, y2, 0.0f,  s0, t2 },
            { x0, y3, 0.0f,  s0, t3 },
            { x1, y3, 0.0f,  s1, t3 },
            { x1, y2, 0.0f,  s1, t2 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x1, y2, 0.0f,  s1, t2 },
            { x1, y3, 0.0f,  s1, t3 },
            { x2, y3, 0.0f,  s2, t3 },
            { x2, y2, 0.0f,  s2, t2 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
        if (_this->image.margin.r > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
            index, index+1, index+2,
            index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
            { x2, y2, 0.0f,  s2, t2 },
            { x2, y3, 0.0f,  s2, t3 },
            { x3, y3, 0.0f,  s3, t3 },
            { x3, y2, 0.0f,  s3, t2 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
    }
}

void sjf_imagerenderer_render(sjs_imagerenderer* _parent, sjs_scene2d* scene) {
    sjs_string sjt_call10 = { -1 };
    sjs_string sjt_call11 = { -1 };
    sjs_string sjt_call12 = { -1 };
    sjs_string sjt_call13 = { -1 };
    sjs_image* sjt_dot178 = 0;
    sjs_imagerenderer* sjt_dot179 = 0;
    sjs_scene2d* sjt_dot180 = 0;
    sjs_scene2d* sjt_dot181 = 0;
    sjs_scene2d* sjt_dot182 = 0;
    int32_t sjt_functionParam50;
    sjs_texture* sjt_functionParam51 = 0;
    sjs_shader* sjt_functionParam52 = 0;
    int32_t sjt_functionParam53;
    int32_t sjt_functionParam54;
    int32_t sjt_functionParam55;
    sjs_shader* sjt_functionParam56 = 0;
    sjs_string* sjt_functionParam57 = 0;
    int32_t sjt_functionParam58;
    int32_t sjt_functionParam59;
    sjs_shader* sjt_functionParam60 = 0;
    sjs_string* sjt_functionParam61 = 0;
    sjs_mat4* sjt_functionParam62 = 0;
    int32_t sjt_functionParam63;
    sjs_shader* sjt_functionParam64 = 0;
    sjs_string* sjt_functionParam65 = 0;
    sjs_mat4* sjt_functionParam66 = 0;
    int32_t sjt_functionParam67;
    sjs_shader* sjt_functionParam68 = 0;
    sjs_string* sjt_functionParam69 = 0;
    sjs_mat4* sjt_functionParam70 = 0;

    sjt_functionParam50 = sjv_gltexture_gl_texture_2d;
    sjt_dot179 = _parent;
    sjt_dot178 = &(sjt_dot179)->image;
    sjt_functionParam51 = &(sjt_dot178)->texture;
    sjf_glbindtexture(sjt_functionParam50, sjt_functionParam51);
    sjt_functionParam52 = &sjv_imageshader;
    sjf_gluseprogram(sjt_functionParam52);
    sjt_functionParam53 = sjv_glblendfunctype_gl_src_alpha;
    sjt_functionParam54 = sjv_glblendfunctype_gl_one_minus_src_alpha;
    sjf_glblendfunc(sjt_functionParam53, sjt_functionParam54);
    sjt_functionParam56 = &sjv_imageshader;
    sjt_call10._refCount = 1;
    sjt_call10.count = 7;
    sjt_call10.data._refCount = 1;
    sjt_call10.data.datasize = 8;
    sjt_call10.data.data = (void*)sjg_string21;
    sjt_call10.data._isglobal = true;
    sjt_call10.data.count = 8;
    sjf_array_char(&sjt_call10.data);
    sjf_string(&sjt_call10);
    sjt_functionParam57 = &sjt_call10;
    sjf_glgetuniformlocation(sjt_functionParam56, sjt_functionParam57, &sjt_functionParam55);
    sjt_functionParam58 = 0;
    sjf_gluniformi32(sjt_functionParam55, sjt_functionParam58);
    sjt_functionParam60 = &sjv_imageshader;
    sjt_call11._refCount = 1;
    sjt_call11.count = 5;
    sjt_call11.data._refCount = 1;
    sjt_call11.data.datasize = 6;
    sjt_call11.data.data = (void*)sjg_string22;
    sjt_call11.data._isglobal = true;
    sjt_call11.data.count = 6;
    sjf_array_char(&sjt_call11.data);
    sjf_string(&sjt_call11);
    sjt_functionParam61 = &sjt_call11;
    sjf_glgetuniformlocation(sjt_functionParam60, sjt_functionParam61, &sjt_functionParam59);
    sjt_dot180 = scene;
    sjt_functionParam62 = &(sjt_dot180)->model;
    sjf_gluniformmat4(sjt_functionParam59, sjt_functionParam62);
    sjt_functionParam64 = &sjv_imageshader;
    sjt_call12._refCount = 1;
    sjt_call12.count = 4;
    sjt_call12.data._refCount = 1;
    sjt_call12.data.datasize = 5;
    sjt_call12.data.data = (void*)sjg_string23;
    sjt_call12.data._isglobal = true;
    sjt_call12.data.count = 5;
    sjf_array_char(&sjt_call12.data);
    sjf_string(&sjt_call12);
    sjt_functionParam65 = &sjt_call12;
    sjf_glgetuniformlocation(sjt_functionParam64, sjt_functionParam65, &sjt_functionParam63);
    sjt_dot181 = scene;
    sjt_functionParam66 = &(sjt_dot181)->view;
    sjf_gluniformmat4(sjt_functionParam63, sjt_functionParam66);
    sjt_functionParam68 = &sjv_imageshader;
    sjt_call13._refCount = 1;
    sjt_call13.count = 10;
    sjt_call13.data._refCount = 1;
    sjt_call13.data.datasize = 11;
    sjt_call13.data.data = (void*)sjg_string24;
    sjt_call13.data._isglobal = true;
    sjt_call13.data.count = 11;
    sjf_array_char(&sjt_call13.data);
    sjf_string(&sjt_call13);
    sjt_functionParam69 = &sjt_call13;
    sjf_glgetuniformlocation(sjt_functionParam68, sjt_functionParam69, &sjt_functionParam67);
    sjt_dot182 = scene;
    sjt_functionParam70 = &(sjt_dot182)->projection;
    sjf_gluniformmat4(sjt_functionParam67, sjt_functionParam70);
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);

    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
    if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
    if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
}

void sjf_light(sjs_light* _this) {
}

void sjf_light_copy(sjs_light* _this, sjs_light* _from) {
    _this->pos._refCount = 1;
    sjf_vec3_copy(&_this->pos, &_from->pos);
    _this->diffusecolor._refCount = 1;
    sjf_color_copy(&_this->diffusecolor, &_from->diffusecolor);
    _this->speccolor._refCount = 1;
    sjf_color_copy(&_this->speccolor, &_from->speccolor);
}

void sjf_light_destroy(sjs_light* _this) {
}

void sjf_light_heap(sjs_light* _this) {
}

void sjf_list_heap_iface_animation(sjs_list_heap_iface_animation* _this) {
}

void sjf_list_heap_iface_animation_copy(sjs_list_heap_iface_animation* _this, sjs_list_heap_iface_animation* _from) {
    _this->array._refCount = 1;
    sjf_array_heap_iface_animation_copy(&_this->array, &_from->array);
}

void sjf_list_heap_iface_animation_destroy(sjs_list_heap_iface_animation* _this) {
}

void sjf_list_heap_iface_animation_getat_heap(sjs_list_heap_iface_animation* _parent, int32_t index, sji_animation* _return) {
    sjs_list_heap_iface_animation* sjt_dot298 = 0;
    int32_t sjt_functionParam161;
    sjs_array_heap_iface_animation* sjt_parent90 = 0;

    sjt_dot298 = _parent;
    sjt_parent90 = &(sjt_dot298)->array;
    sjt_functionParam161 = index;
    sjf_array_heap_iface_animation_getat_heap(sjt_parent90, sjt_functionParam161, _return);
}

void sjf_list_heap_iface_animation_getcount(sjs_list_heap_iface_animation* _parent, int32_t* _return) {
    sjs_array_heap_iface_animation* sjt_dot294 = 0;
    sjs_list_heap_iface_animation* sjt_dot295 = 0;

    sjt_dot295 = _parent;
    sjt_dot294 = &(sjt_dot295)->array;
    (*_return) = (sjt_dot294)->count;
}

void sjf_list_heap_iface_animation_heap(sjs_list_heap_iface_animation* _this) {
}

void sjf_list_heap_iface_animation_removeat(sjs_list_heap_iface_animation* _parent, int32_t index) {
    if (index < 0 || index >= _parent->array.count) {
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
    }
    sji_animation* p = (sji_animation*)_parent->array.data;
    if (index != _parent->array.count - 1) {
        memcpy(p + index, p + index + 1, (_parent->array.count - index - 1) * sizeof(sji_animation));
    }
    _parent->array.count--;
}

void sjf_list_heap_iface_model(sjs_list_heap_iface_model* _this) {
}

void sjf_list_heap_iface_model_copy(sjs_list_heap_iface_model* _this, sjs_list_heap_iface_model* _from) {
    _this->array._refCount = 1;
    sjf_array_heap_iface_model_copy(&_this->array, &_from->array);
}

void sjf_list_heap_iface_model_destroy(sjs_list_heap_iface_model* _this) {
}

void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this) {
}

void sjf_list_rect(sjs_list_rect* _this) {
}

void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item) {
    int32_t sjt_compare101;
    int32_t sjt_compare102;
    sjs_array_rect* sjt_dot325 = 0;
    sjs_list_rect* sjt_dot326 = 0;
    sjs_array_rect* sjt_dot327 = 0;
    sjs_list_rect* sjt_dot328 = 0;
    sjs_list_rect* sjt_dot335 = 0;
    sjs_array_rect* sjt_dot336 = 0;
    sjs_list_rect* sjt_dot337 = 0;
    int32_t sjt_functionParam179;
    sjs_rect* sjt_functionParam180 = 0;
    bool sjt_ifElse45;
    sjs_array_rect* sjt_parent99 = 0;

    sjt_dot326 = _parent;
    sjt_dot325 = &(sjt_dot326)->array;
    sjt_compare101 = (sjt_dot325)->count;
    sjt_dot328 = _parent;
    sjt_dot327 = &(sjt_dot328)->array;
    sjt_compare102 = (sjt_dot327)->datasize;
    sjt_ifElse45 = sjt_compare101 >= sjt_compare102;
    if (sjt_ifElse45) {
        sjs_list_rect* sjt_dot329 = 0;
        sjs_list_rect* sjt_dot332 = 0;
        sjs_array_rect* sjt_dot333 = 0;
        sjs_list_rect* sjt_dot334 = 0;
        int32_t sjt_functionParam176;
        int32_t sjt_functionParam177;
        int32_t sjt_functionParam178;
        int32_t sjt_math249;
        int32_t sjt_math250;
        sjs_array_rect* sjt_parent98 = 0;

        sjt_dot329 = _parent;
        sjt_dot332 = _parent;
        sjt_parent98 = &(sjt_dot332)->array;
        sjt_functionParam177 = 10;
        sjt_dot334 = _parent;
        sjt_dot333 = &(sjt_dot334)->array;
        sjt_math249 = (sjt_dot333)->datasize;
        sjt_math250 = 2;
        sjt_functionParam178 = sjt_math249 * sjt_math250;
        sjf_i32_max(sjt_functionParam177, sjt_functionParam178, &sjt_functionParam176);
        sjf_array_rect_grow(sjt_parent98, sjt_functionParam176, &sjt_dot329->array);
    }

    sjt_dot335 = _parent;
    sjt_parent99 = &(sjt_dot335)->array;
    sjt_dot337 = _parent;
    sjt_dot336 = &(sjt_dot337)->array;
    sjt_functionParam179 = (sjt_dot336)->count;
    sjt_functionParam180 = item;
    sjf_array_rect_initat(sjt_parent99, sjt_functionParam179, sjt_functionParam180);
}

void sjf_list_rect_copy(sjs_list_rect* _this, sjs_list_rect* _from) {
    _this->array._refCount = 1;
    sjf_array_rect_copy(&_this->array, &_from->array);
}

void sjf_list_rect_destroy(sjs_list_rect* _this) {
}

void sjf_list_rect_getat(sjs_list_rect* _parent, int32_t index, sjs_rect* _return) {
    sjs_list_rect* sjt_dot348 = 0;
    int32_t sjt_functionParam185;
    sjs_array_rect* sjt_parent106 = 0;

    sjt_dot348 = _parent;
    sjt_parent106 = &(sjt_dot348)->array;
    sjt_functionParam185 = index;
    sjf_array_rect_getat(sjt_parent106, sjt_functionParam185, _return);
}

void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return) {
    sjs_array_rect* sjt_dot349 = 0;
    sjs_list_rect* sjt_dot350 = 0;

    sjt_dot350 = _parent;
    sjt_dot349 = &(sjt_dot350)->array;
    (*_return) = (sjt_dot349)->count;
}

void sjf_list_rect_heap(sjs_list_rect* _this) {
}

void sjf_list_rect_removeat(sjs_list_rect* _parent, int32_t index) {
    if (index < 0 || index >= _parent->array.count) {
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
    }
    sjs_rect* p = (sjs_rect*)_parent->array.data;
    if (index != _parent->array.count - 1) {
        memcpy(p + index, p + index + 1, (_parent->array.count - index - 1) * sizeof(sjs_rect));
    }
    _parent->array.count--;
}

void sjf_list_u32(sjs_list_u32* _this) {
}

void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from) {
    _this->array._refCount = 1;
    sjf_array_u32_copy(&_this->array, &_from->array);
}

void sjf_list_u32_destroy(sjs_list_u32* _this) {
}

void sjf_list_u32_heap(sjs_list_u32* _this) {
}

void sjf_mainloop(void) {
    bool result9;
    sjs_size* sjt_dot340 = 0;
    sjs_size* sjt_dot341 = 0;
    int32_t sjt_functionParam164;
    sjs_size* sjt_functionParam175 = 0;
    sjs_rect* sjt_functionParam184 = 0;
    bool sjt_ifElse46;
    sjs_scene2d* sjt_interfaceParam11 = 0;
    bool sjt_isEmpty34;
    int32_option sjt_isEmpty35;
    bool sjt_not4;
    sjs_scene2d* sjt_parent101 = 0;
    sjs_rect* sjt_parent102 = 0;
    sji_element sjt_parent104 = { 0 };
    sjs_scene2d* sjt_parent114 = 0;
    sjs_windowrenderer* sjt_parent115 = 0;
    sjs_anon1* sjt_parent94 = 0;
    sjs_windowrenderer* sjt_parent95 = 0;
    sjs_scene2d* sjt_parent97 = 0;
    int32_option sjv_mouse_eventtype;
    bool sjv_mouse_isleftdown;
    int32_t sjv_mouse_x;
    int32_t sjv_mouse_y;
    sjs_rect sjv_rect = { -1 };
    bool sjv_shouldcontinue;
    sjs_size sjv_size = { -1 };
    int32_t sjv_ticks;

    sjv_ticks = 0;
    sjv_ticks = SDL_GetTicks();
    sjt_parent94 = &sjv_animator;
    sjt_functionParam164 = sjv_ticks;
    sjf_anon1_nextframe(sjt_parent94, sjt_functionParam164);
    sjt_parent95 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_getsize(sjt_parent95, &sjv_size);
    sjt_parent97 = &sjv_rootscene;
    sjt_functionParam175 = &sjv_size;
    sjf_scene2d_setsize(sjt_parent97, sjt_functionParam175);
    sjt_parent101 = &sjv_rootscene;
    sjf_scene2d_start(sjt_parent101);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot340 = &sjv_size;
    sjv_rect.w = (sjt_dot340)->w;
    sjt_dot341 = &sjv_size;
    sjv_rect.h = (sjt_dot341)->h;
    sjf_rect(&sjv_rect);
    sjt_parent102 = &sjv_looplastrect;
    sjt_functionParam184 = &sjv_rect;
    sjf_rect_isequal(sjt_parent102, sjt_functionParam184, &sjt_not4);
    result9 = !sjt_not4;
    sjt_ifElse46 = result9;
    if (sjt_ifElse46) {
        sjs_rect* sjt_interfaceParam10 = 0;
        sji_element sjt_parent103 = { 0 };

        sjt_parent103 = sjv_root;
        sjt_interfaceParam10 = &sjv_rect;
        sjt_parent103._vtbl->setrect(sjt_parent103._parent, sjt_interfaceParam10);
    }

    sjt_parent104 = sjv_root;
    sjt_interfaceParam11 = &sjv_rootscene;
    sjt_parent104._vtbl->render(sjt_parent104._parent, sjt_interfaceParam11);
    sjt_parent114 = &sjv_rootscene;
    sjf_scene2d_end(sjt_parent114);
    sjt_parent115 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_present(sjt_parent115);
    SDL_Event e;
    while(SDL_PollEvent( &e ) != 0) {
        sjv_mouse_eventtype = int32_empty;
        sjv_mouse_x = 0;
        sjv_mouse_y = 0;
        sjv_mouse_isleftdown = false;
        switch (e.type) {
            case SDL_QUIT:
            exit(0);
            break;
            case SDL_MOUSEBUTTONDOWN:
            sjv_mouse_eventtype.isvalid = true;
            sjv_mouse_eventtype.value = sjv_mouseeventtype_down;
            sjv_mouse_x = e.button.x;
            sjv_mouse_y = e.button.y;
            sjv_mouse_isleftdown = e.button.state & SDL_BUTTON(SDL_BUTTON_LEFT);
            break;
            case SDL_MOUSEBUTTONUP:
            sjv_mouse_eventtype.isvalid = true;
            sjv_mouse_eventtype.value = sjv_mouseeventtype_up;
            sjv_mouse_x = e.button.x;
            sjv_mouse_y = e.button.y;
            sjv_mouse_isleftdown = e.button.state & SDL_BUTTON(SDL_BUTTON_LEFT);
            break;
            case SDL_MOUSEMOTION:
            sjv_mouse_eventtype.isvalid = true;
            sjv_mouse_eventtype.value = sjv_mouseeventtype_move;
            sjv_mouse_x = e.motion.x;
            sjv_mouse_y = e.motion.y;
            sjv_mouse_isleftdown = SDL_GetGlobalMouseState(0, 0) & SDL_BUTTON(SDL_BUTTON_LEFT);
            break;
        }
        sjv_shouldcontinue = true;
        sjt_isEmpty35 = sjv_mouse_eventtype;
        sjt_isEmpty34 = sjt_isEmpty35.isvalid;
        if (sjt_isEmpty34) {
            int32_t ifValue21;
            int32_option sjt_getValue2;
            bool sjt_isEmpty36;
            sji_element sjt_isEmpty37 = { 0 };

            sjt_getValue2 = sjv_mouse_eventtype;
            ifValue21 = sjt_getValue2.value;
            sjt_isEmpty37 = sjv_mouse_captureelement;
            sjt_isEmpty36 = (sjt_isEmpty37._parent != 0);
            if (sjt_isEmpty36) {
                sji_element ifValue22 = { 0 };
                sjs_mouseevent sjt_call43 = { -1 };
                sjs_mouseevent* sjt_interfaceParam12 = 0;
                sji_element sjt_parent116 = { 0 };

                ifValue22 = sjv_mouse_captureelement;
                if (ifValue22._parent != 0) {
                    ifValue22._parent->_refCount++;
                }

                sjt_parent116 = ifValue22;
                sjt_call43._refCount = 1;
                sjt_call43.type = ifValue21;
                sjt_call43.point._refCount = 1;
                sjt_call43.point.x = sjv_mouse_x;
                sjt_call43.point.y = sjv_mouse_y;
                sjf_point(&sjt_call43.point);
                sjt_call43.iscaptured = true;
                sjt_call43.isleftdown = sjv_mouse_isleftdown;
                sjf_mouseevent(&sjt_call43);
                sjt_interfaceParam12 = &sjt_call43;
                sjt_parent116._vtbl->firemouseevent(sjt_parent116._parent, sjt_interfaceParam12, &sjv_shouldcontinue);

                if (ifValue22._parent != 0) {
                    ifValue22._parent->_refCount--;
                    if (ifValue22._parent->_refCount <= 0) {
                        ifValue22._vtbl->destroy(ifValue22._parent);
                        free(ifValue22._parent);
                    }
                }
                if (sjt_call43._refCount == 1) { sjf_mouseevent_destroy(&sjt_call43); }
            } else {
                sjs_mouseevent sjt_call44 = { -1 };
                sjs_mouseevent* sjt_interfaceParam13 = 0;
                sji_element sjt_parent117 = { 0 };

                sjt_parent117 = sjv_root;
                sjt_call44._refCount = 1;
                sjt_call44.type = ifValue21;
                sjt_call44.point._refCount = 1;
                sjt_call44.point.x = sjv_mouse_x;
                sjt_call44.point.y = sjv_mouse_y;
                sjf_point(&sjt_call44.point);
                sjt_call44.iscaptured = false;
                sjt_call44.isleftdown = sjv_mouse_isleftdown;
                sjf_mouseevent(&sjt_call44);
                sjt_interfaceParam13 = &sjt_call44;
                sjt_parent117._vtbl->firemouseevent(sjt_parent117._parent, sjt_interfaceParam13, &sjv_shouldcontinue);

                if (sjt_call44._refCount == 1) { sjf_mouseevent_destroy(&sjt_call44); }
            }
        }

    }

    if (sjv_rect._refCount == 1) { sjf_rect_destroy(&sjv_rect); }
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
}

void sjf_margin(sjs_margin* _this) {
}

void sjf_margin_copy(sjs_margin* _this, sjs_margin* _from) {
    _this->l = _from->l;
    _this->t = _from->t;
    _this->r = _from->r;
    _this->b = _from->b;
}

void sjf_margin_destroy(sjs_margin* _this) {
}

void sjf_margin_heap(sjs_margin* _this) {
}

void sjf_mat4(sjs_mat4* _this) {
}

void sjf_mat4_copy(sjs_mat4* _this, sjs_mat4* _from) {
    _this->m00 = _from->m00;
    _this->m01 = _from->m01;
    _this->m02 = _from->m02;
    _this->m03 = _from->m03;
    _this->m10 = _from->m10;
    _this->m11 = _from->m11;
    _this->m12 = _from->m12;
    _this->m13 = _from->m13;
    _this->m20 = _from->m20;
    _this->m21 = _from->m21;
    _this->m22 = _from->m22;
    _this->m23 = _from->m23;
    _this->m30 = _from->m30;
    _this->m31 = _from->m31;
    _this->m32 = _from->m32;
    _this->m33 = _from->m33;
}

void sjf_mat4_destroy(sjs_mat4* _this) {
}

void sjf_mat4_heap(sjs_mat4* _this) {
}

void sjf_mat4_identity(sjs_mat4* _return) {
    _return->_refCount = 1;
    _return->m00 = 1.0f;
    _return->m01 = 0.0f;
    _return->m02 = 0.0f;
    _return->m03 = 0.0f;
    _return->m10 = 0.0f;
    _return->m11 = 1.0f;
    _return->m12 = 0.0f;
    _return->m13 = 0.0f;
    _return->m20 = 0.0f;
    _return->m21 = 0.0f;
    _return->m22 = 1.0f;
    _return->m23 = 0.0f;
    _return->m30 = 0.0f;
    _return->m31 = 0.0f;
    _return->m32 = 0.0f;
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_identity_heap(sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    (*_return)->m00 = 1.0f;
    (*_return)->m01 = 0.0f;
    (*_return)->m02 = 0.0f;
    (*_return)->m03 = 0.0f;
    (*_return)->m10 = 0.0f;
    (*_return)->m11 = 1.0f;
    (*_return)->m12 = 0.0f;
    (*_return)->m13 = 0.0f;
    (*_return)->m20 = 0.0f;
    (*_return)->m21 = 0.0f;
    (*_return)->m22 = 1.0f;
    (*_return)->m23 = 0.0f;
    (*_return)->m30 = 0.0f;
    (*_return)->m31 = 0.0f;
    (*_return)->m32 = 0.0f;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return) {
    float result5;
    float sjt_math171;
    float sjt_math172;
    float sjt_math173;
    float sjt_math174;
    float sjt_math175;
    float sjt_math176;
    float sjt_math177;
    float sjt_math178;
    float sjt_math179;
    float sjt_math180;
    float sjt_math181;
    float sjt_math182;
    float sjt_math183;
    float sjt_math184;
    float sjt_math185;
    float sjt_math186;
    float sjt_math187;
    float sjt_math188;
    float sjt_math189;
    float sjt_math190;
    float sjt_math191;
    float sjt_math192;
    float sjt_math193;
    float sjt_math194;
    float sjt_math195;
    float sjt_math196;
    float sjt_math197;
    float sjt_math198;
    float sjt_math199;
    float sjt_math200;
    float sjt_math201;
    float sjt_math202;
    float sjt_math203;
    float sjt_math204;
    float sjt_math205;
    float sjt_math206;
    float sjt_negate2;

    _return->_refCount = 1;
    sjt_math171 = 2.0f;
    sjt_math173 = right;
    sjt_math174 = left;
    sjt_math172 = sjt_math173 - sjt_math174;
    _return->m00 = sjt_math171 / sjt_math172;
    _return->m01 = 0.0f;
    _return->m02 = 0.0f;
    _return->m03 = 0.0f;
    _return->m10 = 0.0f;
    sjt_math175 = 2.0f;
    sjt_math177 = top;
    sjt_math178 = bottom;
    sjt_math176 = sjt_math177 - sjt_math178;
    _return->m11 = sjt_math175 / sjt_math176;
    _return->m12 = 0.0f;
    _return->m13 = 0.0f;
    _return->m20 = 0.0f;
    _return->m21 = 0.0f;
    sjt_negate2 = 2.0f;
    result5 = -sjt_negate2;
    sjt_math179 = result5;
    sjt_math181 = zfar;
    sjt_math182 = znear;
    sjt_math180 = sjt_math181 - sjt_math182;
    _return->m22 = sjt_math179 / sjt_math180;
    _return->m23 = 0.0f;
    sjt_math183 = 0.0f;
    sjt_math187 = right;
    sjt_math188 = left;
    sjt_math185 = sjt_math187 + sjt_math188;
    sjt_math189 = right;
    sjt_math190 = left;
    sjt_math186 = sjt_math189 - sjt_math190;
    sjt_math184 = sjt_math185 / sjt_math186;
    _return->m30 = sjt_math183 - sjt_math184;
    sjt_math191 = 0.0f;
    sjt_math195 = top;
    sjt_math196 = bottom;
    sjt_math193 = sjt_math195 + sjt_math196;
    sjt_math197 = top;
    sjt_math198 = bottom;
    sjt_math194 = sjt_math197 - sjt_math198;
    sjt_math192 = sjt_math193 / sjt_math194;
    _return->m31 = sjt_math191 - sjt_math192;
    sjt_math199 = 0.0f;
    sjt_math203 = zfar;
    sjt_math204 = znear;
    sjt_math201 = sjt_math203 + sjt_math204;
    sjt_math205 = zfar;
    sjt_math206 = znear;
    sjt_math202 = sjt_math205 - sjt_math206;
    sjt_math200 = sjt_math201 / sjt_math202;
    _return->m32 = sjt_math199 - sjt_math200;
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return) {
    float result6;
    float sjt_math207;
    float sjt_math208;
    float sjt_math209;
    float sjt_math210;
    float sjt_math211;
    float sjt_math212;
    float sjt_math213;
    float sjt_math214;
    float sjt_math215;
    float sjt_math216;
    float sjt_math217;
    float sjt_math218;
    float sjt_math219;
    float sjt_math220;
    float sjt_math221;
    float sjt_math222;
    float sjt_math223;
    float sjt_math224;
    float sjt_math225;
    float sjt_math226;
    float sjt_math227;
    float sjt_math228;
    float sjt_math229;
    float sjt_math230;
    float sjt_math231;
    float sjt_math232;
    float sjt_math233;
    float sjt_math234;
    float sjt_math235;
    float sjt_math236;
    float sjt_math237;
    float sjt_math238;
    float sjt_math239;
    float sjt_math240;
    float sjt_math241;
    float sjt_math242;
    float sjt_negate3;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_math207 = 2.0f;
    sjt_math209 = right;
    sjt_math210 = left;
    sjt_math208 = sjt_math209 - sjt_math210;
    (*_return)->m00 = sjt_math207 / sjt_math208;
    (*_return)->m01 = 0.0f;
    (*_return)->m02 = 0.0f;
    (*_return)->m03 = 0.0f;
    (*_return)->m10 = 0.0f;
    sjt_math211 = 2.0f;
    sjt_math213 = top;
    sjt_math214 = bottom;
    sjt_math212 = sjt_math213 - sjt_math214;
    (*_return)->m11 = sjt_math211 / sjt_math212;
    (*_return)->m12 = 0.0f;
    (*_return)->m13 = 0.0f;
    (*_return)->m20 = 0.0f;
    (*_return)->m21 = 0.0f;
    sjt_negate3 = 2.0f;
    result6 = -sjt_negate3;
    sjt_math215 = result6;
    sjt_math217 = zfar;
    sjt_math218 = znear;
    sjt_math216 = sjt_math217 - sjt_math218;
    (*_return)->m22 = sjt_math215 / sjt_math216;
    (*_return)->m23 = 0.0f;
    sjt_math219 = 0.0f;
    sjt_math223 = right;
    sjt_math224 = left;
    sjt_math221 = sjt_math223 + sjt_math224;
    sjt_math225 = right;
    sjt_math226 = left;
    sjt_math222 = sjt_math225 - sjt_math226;
    sjt_math220 = sjt_math221 / sjt_math222;
    (*_return)->m30 = sjt_math219 - sjt_math220;
    sjt_math227 = 0.0f;
    sjt_math231 = top;
    sjt_math232 = bottom;
    sjt_math229 = sjt_math231 + sjt_math232;
    sjt_math233 = top;
    sjt_math234 = bottom;
    sjt_math230 = sjt_math233 - sjt_math234;
    sjt_math228 = sjt_math229 / sjt_math230;
    (*_return)->m31 = sjt_math227 - sjt_math228;
    sjt_math235 = 0.0f;
    sjt_math239 = zfar;
    sjt_math240 = znear;
    sjt_math237 = sjt_math239 + sjt_math240;
    sjt_math241 = zfar;
    sjt_math242 = znear;
    sjt_math238 = sjt_math241 - sjt_math242;
    sjt_math236 = sjt_math237 / sjt_math238;
    (*_return)->m32 = sjt_math235 - sjt_math236;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_scale(float x, float y, float z, sjs_mat4* _return) {
    _return->_refCount = 1;
    _return->m00 = x;
    _return->m01 = 0.0f;
    _return->m02 = 0.0f;
    _return->m03 = 0.0f;
    _return->m10 = 0.0f;
    _return->m11 = y;
    _return->m12 = 0.0f;
    _return->m13 = 0.0f;
    _return->m20 = 0.0f;
    _return->m21 = 0.0f;
    _return->m22 = z;
    _return->m23 = 0.0f;
    _return->m30 = 0.0f;
    _return->m31 = 0.0f;
    _return->m32 = 0.0f;
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_scale_heap(float x, float y, float z, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    (*_return)->m00 = x;
    (*_return)->m01 = 0.0f;
    (*_return)->m02 = 0.0f;
    (*_return)->m03 = 0.0f;
    (*_return)->m10 = 0.0f;
    (*_return)->m11 = y;
    (*_return)->m12 = 0.0f;
    (*_return)->m13 = 0.0f;
    (*_return)->m20 = 0.0f;
    (*_return)->m21 = 0.0f;
    (*_return)->m22 = z;
    (*_return)->m23 = 0.0f;
    (*_return)->m30 = 0.0f;
    (*_return)->m31 = 0.0f;
    (*_return)->m32 = 0.0f;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));
}

void sjf_mouse_capture(sji_element element) {
    sji_element sjt_value1 = { 0 };

    sjt_value1 = element;
    if (sjt_value1._parent != 0) {
        sjt_value1._parent->_refCount++;
    }

    if (sjv_mouse_captureelement._parent != 0) {
        sjv_mouse_captureelement._parent->_refCount--;
        if (sjv_mouse_captureelement._parent->_refCount <= 0) {
            sjv_mouse_captureelement._vtbl->destroy(sjv_mouse_captureelement._parent);
            free(sjv_mouse_captureelement._parent);
        }
    }

    sjv_mouse_captureelement = sjt_value1;
    if (sjv_mouse_captureelement._parent != 0) {
        sjv_mouse_captureelement._parent->_refCount++;
    }

    SDL_CaptureMouse(true);

    if (sjt_value1._parent != 0) {
        sjt_value1._parent->_refCount--;
        if (sjt_value1._parent->_refCount <= 0) {
            sjt_value1._vtbl->destroy(sjt_value1._parent);
            free(sjt_value1._parent);
        }
    }
}

void sjf_mouse_hascapture(sji_element element, bool* _return) {
    bool sjt_isEmpty19;
    sji_element sjt_isEmpty20 = { 0 };

    sjt_isEmpty20 = sjv_mouse_captureelement;
    sjt_isEmpty19 = (sjt_isEmpty20._parent != 0);
    if (sjt_isEmpty19) {
        sji_element ifValue8 = { 0 };
        sji_element sjt_compare71 = { 0 };
        sji_element sjt_compare72 = { 0 };

        ifValue8 = sjv_mouse_captureelement;
        if (ifValue8._parent != 0) {
            ifValue8._parent->_refCount++;
        }

        sjt_compare71 = ifValue8;
        sjt_compare72 = element;
        (*_return) = sjt_compare71._parent == sjt_compare72._parent;

        if (ifValue8._parent != 0) {
            ifValue8._parent->_refCount--;
            if (ifValue8._parent->_refCount <= 0) {
                ifValue8._vtbl->destroy(ifValue8._parent);
                free(ifValue8._parent);
            }
        }
    } else {
        (*_return) = false;
    }
}

void sjf_mouse_release(sji_element element) {
    sjs_string sjt_call18 = { -1 };
    sjs_string* sjt_functionParam93 = 0;
    bool sjt_isEmpty14;
    sji_element sjt_isEmpty15 = { 0 };

    sjt_call18._refCount = 1;
    sjt_call18.count = 7;
    sjt_call18.data._refCount = 1;
    sjt_call18.data.datasize = 8;
    sjt_call18.data.data = (void*)sjg_string25;
    sjt_call18.data._isglobal = true;
    sjt_call18.data.count = 8;
    sjf_array_char(&sjt_call18.data);
    sjf_string(&sjt_call18);
    sjt_functionParam93 = &sjt_call18;
    sjf_console_writeline(sjt_functionParam93);
    sjt_isEmpty15 = sjv_mouse_captureelement;
    sjt_isEmpty14 = (sjt_isEmpty15._parent != 0);
    if (sjt_isEmpty14) {
        sji_element ifValue10 = { 0 };
        sjs_string sjt_call19 = { -1 };
        sji_element sjt_compare63 = { 0 };
        sji_element sjt_compare64 = { 0 };
        bool sjt_ifElse28;

        ifValue10 = sjv_mouse_captureelement;
        if (ifValue10._parent != 0) {
            ifValue10._parent->_refCount++;
        }

        sjt_compare63 = ifValue10;
        sjt_compare64 = element;
        sjt_ifElse28 = sjt_compare63._parent == sjt_compare64._parent;
        if (sjt_ifElse28) {
            sjs_string* sjt_functionParam94 = 0;

            sjt_call19._refCount = 1;
            sjt_call19.count = 12;
            sjt_call19.data._refCount = 1;
            sjt_call19.data.datasize = 13;
            sjt_call19.data.data = (void*)sjg_string26;
            sjt_call19.data._isglobal = true;
            sjt_call19.data.count = 13;
            sjf_array_char(&sjt_call19.data);
            sjf_string(&sjt_call19);
            sjt_functionParam94 = &sjt_call19;
            sjf_console_writeline(sjt_functionParam94);
            sjv_mouse_captureelement._parent = 0;
            SDL_CaptureMouse(false);
        }

        if (ifValue10._parent != 0) {
            ifValue10._parent->_refCount--;
            if (ifValue10._parent->_refCount <= 0) {
                ifValue10._vtbl->destroy(ifValue10._parent);
                free(ifValue10._parent);
            }
        }
        if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
    }

    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
}

void sjf_mouseevent(sjs_mouseevent* _this) {
}

void sjf_mouseevent_copy(sjs_mouseevent* _this, sjs_mouseevent* _from) {
    _this->type = _from->type;
    _this->point._refCount = 1;
    sjf_point_copy(&_this->point, &_from->point);
    _this->iscaptured = _from->iscaptured;
    _this->isleftdown = _from->isleftdown;
}

void sjf_mouseevent_destroy(sjs_mouseevent* _this) {
}

void sjf_mouseevent_firechildren(sjs_mouseevent* _parent, sjs_array_heap_iface_element* children, bool* _return) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot83 = 0;
    int32_t sjt_forEnd7;
    int32_t sjt_forStart7;
    bool sjv_shouldcontinue;

    sjv_shouldcontinue = true;
    sjt_forStart7 = 0;
    sjt_dot83 = children;
    sjt_forEnd7 = (sjt_dot83)->count;
    i = sjt_forEnd7 - 1;
    while (i >= sjt_forStart7) {
        bool sjt_ifElse12;

        sjt_ifElse12 = sjv_shouldcontinue;
        if (sjt_ifElse12) {
            int32_t sjt_functionParam37;
            sjs_mouseevent* sjt_interfaceParam3 = 0;
            sjs_array_heap_iface_element* sjt_parent25 = 0;
            sji_element sjt_parent26 = { 0 };
            sji_element sjv_child = { 0 };

            sjt_parent25 = children;
            sjt_functionParam37 = i;
            sjf_array_heap_iface_element_getat_heap(sjt_parent25, sjt_functionParam37, &sjv_child);
            sjt_parent26 = sjv_child;
            sjt_interfaceParam3 = _parent;
            sjt_parent26._vtbl->firemouseevent(sjt_parent26._parent, sjt_interfaceParam3, &sjv_shouldcontinue);

            if (sjv_child._parent != 0) {
                sjv_child._parent->_refCount--;
                if (sjv_child._parent->_refCount <= 0) {
                    sjv_child._vtbl->destroy(sjv_child._parent);
                    free(sjv_child._parent);
                }
            }
        }

        i--;
    }

    (*_return) = sjv_shouldcontinue;
}

void sjf_mouseevent_heap(sjs_mouseevent* _this) {
}

void sjf_point(sjs_point* _this) {
}

void sjf_point_copy(sjs_point* _this, sjs_point* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
}

void sjf_point_destroy(sjs_point* _this) {
}

void sjf_point_heap(sjs_point* _this) {
}

void sjf_rect(sjs_rect* _this) {
}

void sjf_rect_containspoint(sjs_rect* _parent, sjs_point* point, bool* _return) {
    bool sjt_and13;
    bool sjt_and14;
    bool sjt_and15;
    bool sjt_and16;
    bool sjt_and17;
    bool sjt_and18;
    int32_t sjt_compare53;
    int32_t sjt_compare54;
    int32_t sjt_compare55;
    int32_t sjt_compare56;
    int32_t sjt_compare57;
    int32_t sjt_compare58;
    int32_t sjt_compare59;
    int32_t sjt_compare60;
    sjs_rect* sjt_dot191 = 0;
    sjs_point* sjt_dot192 = 0;
    sjs_rect* sjt_dot193 = 0;
    sjs_point* sjt_dot194 = 0;
    sjs_point* sjt_dot195 = 0;
    sjs_rect* sjt_dot196 = 0;
    sjs_rect* sjt_dot197 = 0;
    sjs_point* sjt_dot198 = 0;
    sjs_rect* sjt_dot199 = 0;
    sjs_rect* sjt_dot200 = 0;
    int32_t sjt_math121;
    int32_t sjt_math122;
    int32_t sjt_math123;
    int32_t sjt_math124;

    sjt_dot191 = _parent;
    sjt_compare53 = (sjt_dot191)->x;
    sjt_dot192 = point;
    sjt_compare54 = (sjt_dot192)->x;
    sjt_and13 = sjt_compare53 <= sjt_compare54;
    sjt_dot193 = _parent;
    sjt_compare55 = (sjt_dot193)->y;
    sjt_dot194 = point;
    sjt_compare56 = (sjt_dot194)->y;
    sjt_and15 = sjt_compare55 <= sjt_compare56;
    sjt_dot195 = point;
    sjt_compare57 = (sjt_dot195)->x;
    sjt_dot196 = _parent;
    sjt_math121 = (sjt_dot196)->x;
    sjt_dot197 = _parent;
    sjt_math122 = (sjt_dot197)->w;
    sjt_compare58 = sjt_math121 + sjt_math122;
    sjt_and17 = sjt_compare57 < sjt_compare58;
    sjt_dot198 = point;
    sjt_compare59 = (sjt_dot198)->y;
    sjt_dot199 = _parent;
    sjt_math123 = (sjt_dot199)->y;
    sjt_dot200 = _parent;
    sjt_math124 = (sjt_dot200)->h;
    sjt_compare60 = sjt_math123 + sjt_math124;
    sjt_and18 = sjt_compare59 < sjt_compare60;
    sjt_and16 = sjt_and17 && sjt_and18;
    sjt_and14 = sjt_and15 && sjt_and16;
    (*_return) = sjt_and13 && sjt_and14;
}

void sjf_rect_copy(sjs_rect* _this, sjs_rect* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
    _this->w = _from->w;
    _this->h = _from->h;
}

void sjf_rect_destroy(sjs_rect* _this) {
}

void sjf_rect_heap(sjs_rect* _this) {
}

void sjf_rect_isequal(sjs_rect* _parent, sjs_rect* rect, bool* _return) {
    bool sjt_and10;
    bool sjt_and11;
    bool sjt_and12;
    bool sjt_and7;
    bool sjt_and8;
    bool sjt_and9;
    int32_t sjt_compare41;
    int32_t sjt_compare42;
    int32_t sjt_compare43;
    int32_t sjt_compare44;
    int32_t sjt_compare45;
    int32_t sjt_compare46;
    int32_t sjt_compare47;
    int32_t sjt_compare48;
    sjs_rect* sjt_dot137 = 0;
    sjs_rect* sjt_dot138 = 0;
    sjs_rect* sjt_dot139 = 0;
    sjs_rect* sjt_dot140 = 0;
    sjs_rect* sjt_dot141 = 0;
    sjs_rect* sjt_dot142 = 0;
    sjs_rect* sjt_dot143 = 0;
    sjs_rect* sjt_dot144 = 0;

    sjt_dot137 = _parent;
    sjt_compare41 = (sjt_dot137)->x;
    sjt_dot138 = rect;
    sjt_compare42 = (sjt_dot138)->x;
    sjt_and7 = sjt_compare41 == sjt_compare42;
    sjt_dot139 = _parent;
    sjt_compare43 = (sjt_dot139)->y;
    sjt_dot140 = rect;
    sjt_compare44 = (sjt_dot140)->y;
    sjt_and9 = sjt_compare43 == sjt_compare44;
    sjt_dot141 = _parent;
    sjt_compare45 = (sjt_dot141)->w;
    sjt_dot142 = rect;
    sjt_compare46 = (sjt_dot142)->w;
    sjt_and11 = sjt_compare45 == sjt_compare46;
    sjt_dot143 = _parent;
    sjt_compare47 = (sjt_dot143)->h;
    sjt_dot144 = rect;
    sjt_compare48 = (sjt_dot144)->h;
    sjt_and12 = sjt_compare47 == sjt_compare48;
    sjt_and10 = sjt_and11 && sjt_and12;
    sjt_and8 = sjt_and9 && sjt_and10;
    (*_return) = sjt_and7 && sjt_and8;
}

void sjf_rect_subtractmargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    sjs_rect* sjt_dot16 = 0;
    sjs_margin* sjt_dot17 = 0;
    sjs_rect* sjt_dot18 = 0;
    sjs_margin* sjt_dot19 = 0;
    sjs_rect* sjt_dot20 = 0;
    sjs_margin* sjt_dot21 = 0;
    sjs_margin* sjt_dot22 = 0;
    sjs_rect* sjt_dot23 = 0;
    sjs_margin* sjt_dot24 = 0;
    sjs_margin* sjt_dot25 = 0;
    int32_t sjt_math10;
    int32_t sjt_math11;
    int32_t sjt_math12;
    int32_t sjt_math13;
    int32_t sjt_math14;
    int32_t sjt_math15;
    int32_t sjt_math16;
    int32_t sjt_math5;
    int32_t sjt_math6;
    int32_t sjt_math7;
    int32_t sjt_math8;
    int32_t sjt_math9;

    _return->_refCount = 1;
    sjt_dot16 = _parent;
    sjt_math5 = (sjt_dot16)->x;
    sjt_dot17 = margin;
    sjt_math6 = (sjt_dot17)->l;
    _return->x = sjt_math5 + sjt_math6;
    sjt_dot18 = _parent;
    sjt_math7 = (sjt_dot18)->y;
    sjt_dot19 = margin;
    sjt_math8 = (sjt_dot19)->t;
    _return->y = sjt_math7 + sjt_math8;
    sjt_dot20 = _parent;
    sjt_math11 = (sjt_dot20)->w;
    sjt_dot21 = margin;
    sjt_math12 = (sjt_dot21)->l;
    sjt_math9 = sjt_math11 - sjt_math12;
    sjt_dot22 = margin;
    sjt_math10 = (sjt_dot22)->r;
    _return->w = sjt_math9 - sjt_math10;
    sjt_dot23 = _parent;
    sjt_math15 = (sjt_dot23)->h;
    sjt_dot24 = margin;
    sjt_math16 = (sjt_dot24)->t;
    sjt_math13 = sjt_math15 - sjt_math16;
    sjt_dot25 = margin;
    sjt_math14 = (sjt_dot25)->b;
    _return->h = sjt_math13 - sjt_math14;
    sjf_rect(_return);
}

void sjf_rect_subtractmargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect** _return) {
    sjs_rect* sjt_dot26 = 0;
    sjs_margin* sjt_dot27 = 0;
    sjs_rect* sjt_dot28 = 0;
    sjs_margin* sjt_dot29 = 0;
    sjs_rect* sjt_dot30 = 0;
    sjs_margin* sjt_dot31 = 0;
    sjs_margin* sjt_dot32 = 0;
    sjs_rect* sjt_dot33 = 0;
    sjs_margin* sjt_dot34 = 0;
    sjs_margin* sjt_dot35 = 0;
    int32_t sjt_math17;
    int32_t sjt_math18;
    int32_t sjt_math19;
    int32_t sjt_math20;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjt_math23;
    int32_t sjt_math24;
    int32_t sjt_math25;
    int32_t sjt_math26;
    int32_t sjt_math27;
    int32_t sjt_math28;

    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjt_dot26 = _parent;
    sjt_math17 = (sjt_dot26)->x;
    sjt_dot27 = margin;
    sjt_math18 = (sjt_dot27)->l;
    (*_return)->x = sjt_math17 + sjt_math18;
    sjt_dot28 = _parent;
    sjt_math19 = (sjt_dot28)->y;
    sjt_dot29 = margin;
    sjt_math20 = (sjt_dot29)->t;
    (*_return)->y = sjt_math19 + sjt_math20;
    sjt_dot30 = _parent;
    sjt_math23 = (sjt_dot30)->w;
    sjt_dot31 = margin;
    sjt_math24 = (sjt_dot31)->l;
    sjt_math21 = sjt_math23 - sjt_math24;
    sjt_dot32 = margin;
    sjt_math22 = (sjt_dot32)->r;
    (*_return)->w = sjt_math21 - sjt_math22;
    sjt_dot33 = _parent;
    sjt_math27 = (sjt_dot33)->h;
    sjt_dot34 = margin;
    sjt_math28 = (sjt_dot34)->t;
    sjt_math25 = sjt_math27 - sjt_math28;
    sjt_dot35 = margin;
    sjt_math26 = (sjt_dot35)->b;
    (*_return)->h = sjt_math25 - sjt_math26;
    sjf_rect_heap((*_return));
}

void sjf_runloop(void) {
    #ifdef EMSCRIPTEN
    emscripten_set_main_loop((em_callback_func)sjf_mainloop, 0, 0);
    exit(0);
    #else
    bool quit = false;
    while (!quit) {
        sjf_mainloop();
    }
    #endif 
}

void sjf_scene2d(sjs_scene2d* _this) {
}

void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from) {
    _this->_size._refCount = 1;
    sjf_size_copy(&_this->_size, &_from->_size);
    _this->model._refCount = 1;
    sjf_mat4_copy(&_this->model, &_from->model);
    _this->view._refCount = 1;
    sjf_mat4_copy(&_this->view, &_from->view);
    _this->projection._refCount = 1;
    sjf_mat4_copy(&_this->projection, &_from->projection);
    _this->windowrect._refCount = 1;
    sjf_rect_copy(&_this->windowrect, &_from->windowrect);
}

void sjf_scene2d_destroy(sjs_scene2d* _this) {
}

void sjf_scene2d_end(sjs_scene2d* _parent) {
    sjs_scene2d* sjt_dot351 = 0;
    sjs_scene2d* sjt_dot352 = 0;
    sjs_rect* sjt_functionParam191 = 0;
    sjs_rect* sjt_functionParam192 = 0;

    sjt_dot351 = _parent;
    sjt_functionParam191 = &(sjt_dot351)->windowrect;
    sjt_dot352 = _parent;
    sjt_functionParam192 = &(sjt_dot352)->windowrect;
    sjf_glpopviewport(sjt_functionParam191, sjt_functionParam192);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result4;
    sjs_scene2d* sjt_dot305 = 0;
    sjs_size* sjt_functionParam165 = 0;
    bool sjt_ifElse44;
    bool sjt_not3;
    sjs_size* sjt_parent96 = 0;

    sjt_dot305 = _parent;
    sjt_parent96 = &(sjt_dot305)->_size;
    sjt_functionParam165 = size;
    sjf_size_isequal(sjt_parent96, sjt_functionParam165, &sjt_not3);
    result4 = !sjt_not3;
    sjt_ifElse44 = result4;
    if (sjt_ifElse44) {
        float result7;
        float result8;
        int32_t sjt_cast12;
        int32_t sjt_cast13;
        sjs_size* sjt_copy35 = 0;
        sjs_scene2d* sjt_dot306 = 0;
        sjs_scene2d* sjt_dot307 = 0;
        sjs_size* sjt_dot308 = 0;
        sjs_scene2d* sjt_dot309 = 0;
        sjs_size* sjt_dot310 = 0;
        sjs_scene2d* sjt_dot311 = 0;
        sjs_scene2d* sjt_dot312 = 0;
        sjs_scene2d* sjt_dot313 = 0;
        float sjt_functionParam166;
        float sjt_functionParam167;
        float sjt_functionParam168;
        float sjt_functionParam169;
        float sjt_functionParam170;
        float sjt_functionParam171;
        float sjt_functionParam172;
        float sjt_functionParam173;
        float sjt_functionParam174;
        int32_t sjt_math243;
        int32_t sjt_math244;
        float sjt_negate4;
        float sjt_negate5;

        sjt_dot306 = _parent;
        sjt_copy35 = size;
        sjt_dot306->_size._refCount = 1;
        sjf_size_copy(&sjt_dot306->_size, sjt_copy35);
        sjt_dot307 = _parent;
        sjt_functionParam166 = 0.0f;
        sjt_dot309 = _parent;
        sjt_dot308 = &(sjt_dot309)->_size;
        sjt_cast12 = (sjt_dot308)->w;
        sjt_functionParam167 = (float)sjt_cast12;
        sjt_math243 = 0;
        sjt_dot311 = _parent;
        sjt_dot310 = &(sjt_dot311)->_size;
        sjt_math244 = (sjt_dot310)->h;
        sjt_cast13 = sjt_math243 - sjt_math244;
        sjt_functionParam168 = (float)sjt_cast13;
        sjt_functionParam169 = 0.0f;
        sjt_negate4 = 1.0f;
        result7 = -sjt_negate4;
        sjt_functionParam170 = result7;
        sjt_functionParam171 = 1.0f;
        sjf_mat4_orthographic(sjt_functionParam166, sjt_functionParam167, sjt_functionParam168, sjt_functionParam169, sjt_functionParam170, sjt_functionParam171, &sjt_dot307->projection);
        sjt_dot312 = _parent;
        sjt_functionParam172 = 1.0f;
        sjt_negate5 = 1.0f;
        result8 = -sjt_negate5;
        sjt_functionParam173 = result8;
        sjt_functionParam174 = 1.0f;
        sjf_mat4_scale(sjt_functionParam172, sjt_functionParam173, sjt_functionParam174, &sjt_dot312->model);
        sjt_dot313 = _parent;
        sjf_mat4_identity(&sjt_dot313->view);
    }
}

void sjf_scene2d_start(sjs_scene2d* _parent) {
    sjs_scene2d* sjt_dot314 = 0;
    sjs_size* sjt_dot315 = 0;
    sjs_scene2d* sjt_dot316 = 0;
    sjs_size* sjt_dot317 = 0;
    sjs_scene2d* sjt_dot318 = 0;
    sjs_scene2d* sjt_dot338 = 0;
    sjs_scene2d* sjt_dot339 = 0;
    sjs_rect* sjt_functionParam182 = 0;
    sjs_rect* sjt_functionParam183 = 0;

    sjt_dot314 = _parent;
    sjt_dot314->windowrect._refCount = 1;
    sjt_dot314->windowrect.x = 0;
    sjt_dot314->windowrect.y = 0;
    sjt_dot316 = _parent;
    sjt_dot315 = &(sjt_dot316)->_size;
    sjt_dot314->windowrect.w = (sjt_dot315)->w;
    sjt_dot318 = _parent;
    sjt_dot317 = &(sjt_dot318)->_size;
    sjt_dot314->windowrect.h = (sjt_dot317)->h;
    sjf_rect(&sjt_dot314->windowrect);
    sjt_dot338 = _parent;
    sjt_functionParam182 = &(sjt_dot338)->windowrect;
    sjt_dot339 = _parent;
    sjt_functionParam183 = &(sjt_dot339)->windowrect;
    sjf_glpushviewport(sjt_functionParam182, sjt_functionParam183);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_DEPTH_TEST );
}

void sjf_shader(sjs_shader* _this) {
    _this->id = shader_load((char*)_this->vertex.data.data, (char*)_this->pixel.data.data);
}

void sjf_shader_copy(sjs_shader* _this, sjs_shader* _from) {
    _this->vertex._refCount = 1;
    sjf_string_copy(&_this->vertex, &_from->vertex);
    _this->pixel._refCount = 1;
    sjf_string_copy(&_this->pixel, &_from->pixel);
    _this->id = _from->id;
    glid_retain(_this->id);
}

void sjf_shader_destroy(sjs_shader* _this) {
    if (glid_release(_this->id)) {
        glDeleteShader(_this->id);
    }
}

void sjf_shader_heap(sjs_shader* _this) {
    _this->id = shader_load((char*)_this->vertex.data.data, (char*)_this->pixel.data.data);
}

void sjf_size(sjs_size* _this) {
}

void sjf_size_addmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    sjs_size* sjt_dot101 = 0;
    sjs_margin* sjt_dot102 = 0;
    sjs_margin* sjt_dot103 = 0;
    sjs_size* sjt_dot104 = 0;
    sjs_margin* sjt_dot105 = 0;
    sjs_margin* sjt_dot106 = 0;
    int32_t sjt_math100;
    int32_t sjt_math93;
    int32_t sjt_math94;
    int32_t sjt_math95;
    int32_t sjt_math96;
    int32_t sjt_math97;
    int32_t sjt_math98;
    int32_t sjt_math99;

    _return->_refCount = 1;
    sjt_dot101 = _parent;
    sjt_math95 = (sjt_dot101)->w;
    sjt_dot102 = margin;
    sjt_math96 = (sjt_dot102)->l;
    sjt_math93 = sjt_math95 + sjt_math96;
    sjt_dot103 = margin;
    sjt_math94 = (sjt_dot103)->r;
    _return->w = sjt_math93 + sjt_math94;
    sjt_dot104 = _parent;
    sjt_math99 = (sjt_dot104)->h;
    sjt_dot105 = margin;
    sjt_math100 = (sjt_dot105)->t;
    sjt_math97 = sjt_math99 + sjt_math100;
    sjt_dot106 = margin;
    sjt_math98 = (sjt_dot106)->b;
    _return->h = sjt_math97 + sjt_math98;
    sjf_size(_return);
}

void sjf_size_addmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    sjs_size* sjt_dot107 = 0;
    sjs_margin* sjt_dot108 = 0;
    sjs_margin* sjt_dot109 = 0;
    sjs_size* sjt_dot110 = 0;
    sjs_margin* sjt_dot111 = 0;
    sjs_margin* sjt_dot112 = 0;
    int32_t sjt_math101;
    int32_t sjt_math102;
    int32_t sjt_math103;
    int32_t sjt_math104;
    int32_t sjt_math105;
    int32_t sjt_math106;
    int32_t sjt_math107;
    int32_t sjt_math108;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot107 = _parent;
    sjt_math103 = (sjt_dot107)->w;
    sjt_dot108 = margin;
    sjt_math104 = (sjt_dot108)->l;
    sjt_math101 = sjt_math103 + sjt_math104;
    sjt_dot109 = margin;
    sjt_math102 = (sjt_dot109)->r;
    (*_return)->w = sjt_math101 + sjt_math102;
    sjt_dot110 = _parent;
    sjt_math107 = (sjt_dot110)->h;
    sjt_dot111 = margin;
    sjt_math108 = (sjt_dot111)->t;
    sjt_math105 = sjt_math107 + sjt_math108;
    sjt_dot112 = margin;
    sjt_math106 = (sjt_dot112)->b;
    (*_return)->h = sjt_math105 + sjt_math106;
    sjf_size_heap((*_return));
}

void sjf_size_copy(sjs_size* _this, sjs_size* _from) {
    _this->w = _from->w;
    _this->h = _from->h;
}

void sjf_size_destroy(sjs_size* _this) {
}

void sjf_size_heap(sjs_size* _this) {
}

void sjf_size_isequal(sjs_size* _parent, sjs_size* size, bool* _return) {
    bool sjt_and21;
    bool sjt_and22;
    int32_t sjt_compare100;
    int32_t sjt_compare97;
    int32_t sjt_compare98;
    int32_t sjt_compare99;
    sjs_size* sjt_dot301 = 0;
    sjs_size* sjt_dot302 = 0;
    sjs_size* sjt_dot303 = 0;
    sjs_size* sjt_dot304 = 0;

    sjt_dot301 = _parent;
    sjt_compare97 = (sjt_dot301)->w;
    sjt_dot302 = size;
    sjt_compare98 = (sjt_dot302)->w;
    sjt_and21 = sjt_compare97 == sjt_compare98;
    sjt_dot303 = _parent;
    sjt_compare99 = (sjt_dot303)->h;
    sjt_dot304 = size;
    sjt_compare100 = (sjt_dot304)->h;
    sjt_and22 = sjt_compare99 == sjt_compare100;
    (*_return) = sjt_and21 && sjt_and22;
}

void sjf_size_min(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t sjt_compare33;
    int32_t sjt_compare34;
    int32_t sjt_compare35;
    int32_t sjt_compare36;
    sjs_size* sjt_dot116 = 0;
    sjs_size* sjt_dot117 = 0;
    sjs_size* sjt_dot120 = 0;
    sjs_size* sjt_dot121 = 0;
    bool sjt_ifElse15;
    bool sjt_ifElse16;

    _return->_refCount = 1;
    sjt_dot116 = _parent;
    sjt_compare33 = (sjt_dot116)->w;
    sjt_dot117 = maxsize;
    sjt_compare34 = (sjt_dot117)->w;
    sjt_ifElse15 = sjt_compare33 < sjt_compare34;
    if (sjt_ifElse15) {
        sjs_size* sjt_dot118 = 0;

        sjt_dot118 = _parent;
        _return->w = (sjt_dot118)->w;
    } else {
        sjs_size* sjt_dot119 = 0;

        sjt_dot119 = maxsize;
        _return->w = (sjt_dot119)->w;
    }

    sjt_dot120 = _parent;
    sjt_compare35 = (sjt_dot120)->h;
    sjt_dot121 = maxsize;
    sjt_compare36 = (sjt_dot121)->h;
    sjt_ifElse16 = sjt_compare35 < sjt_compare36;
    if (sjt_ifElse16) {
        sjs_size* sjt_dot122 = 0;

        sjt_dot122 = _parent;
        _return->h = (sjt_dot122)->h;
    } else {
        sjs_size* sjt_dot123 = 0;

        sjt_dot123 = maxsize;
        _return->h = (sjt_dot123)->h;
    }

    sjf_size(_return);
}

void sjf_size_min_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t sjt_compare37;
    int32_t sjt_compare38;
    int32_t sjt_compare39;
    int32_t sjt_compare40;
    sjs_size* sjt_dot124 = 0;
    sjs_size* sjt_dot125 = 0;
    sjs_size* sjt_dot128 = 0;
    sjs_size* sjt_dot129 = 0;
    bool sjt_ifElse17;
    bool sjt_ifElse18;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot124 = _parent;
    sjt_compare37 = (sjt_dot124)->w;
    sjt_dot125 = maxsize;
    sjt_compare38 = (sjt_dot125)->w;
    sjt_ifElse17 = sjt_compare37 < sjt_compare38;
    if (sjt_ifElse17) {
        sjs_size* sjt_dot126 = 0;

        sjt_dot126 = _parent;
        (*_return)->w = (sjt_dot126)->w;
    } else {
        sjs_size* sjt_dot127 = 0;

        sjt_dot127 = maxsize;
        (*_return)->w = (sjt_dot127)->w;
    }

    sjt_dot128 = _parent;
    sjt_compare39 = (sjt_dot128)->h;
    sjt_dot129 = maxsize;
    sjt_compare40 = (sjt_dot129)->h;
    sjt_ifElse18 = sjt_compare39 < sjt_compare40;
    if (sjt_ifElse18) {
        sjs_size* sjt_dot130 = 0;

        sjt_dot130 = _parent;
        (*_return)->h = (sjt_dot130)->h;
    } else {
        sjs_size* sjt_dot131 = 0;

        sjt_dot131 = maxsize;
        (*_return)->h = (sjt_dot131)->h;
    }

    sjf_size_heap((*_return));
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    int32_t sjt_compare79;
    int32_t sjt_compare80;
    sjs_string* sjt_dot231 = 0;
    bool sjt_ifElse37;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot231 = item;
    sjt_compare79 = (sjt_dot231)->count;
    sjt_compare80 = 0;
    sjt_ifElse37 = sjt_compare79 == sjt_compare80;
    if (sjt_ifElse37) {
        sjs_array_char* sjt_copy21 = 0;
        sjs_string* sjt_dot232 = 0;
        sjs_string* sjt_dot233 = 0;

        _return->_refCount = 1;
        sjt_dot232 = _parent;
        _return->count = (sjt_dot232)->count;
        sjt_dot233 = _parent;
        sjt_copy21 = &(sjt_dot233)->data;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy21);
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_cast8;
        sjs_array_char* sjt_copy22 = 0;
        sjs_string* sjt_dot236 = 0;
        sjs_string* sjt_dot237 = 0;
        sjs_string* sjt_dot238 = 0;
        sjs_string* sjt_dot239 = 0;
        sjs_string* sjt_dot241 = 0;
        int32_t sjt_forEnd8;
        int32_t sjt_forStart8;
        int32_t sjt_functionParam113;
        int32_t sjt_functionParam114;
        char sjt_functionParam115;
        int32_t sjt_functionParam117;
        int32_t sjt_functionParam121;
        char sjt_functionParam122;
        int32_t sjt_math127;
        int32_t sjt_math128;
        int32_t sjt_math129;
        int32_t sjt_math130;
        int32_t sjt_math131;
        int32_t sjt_math132;
        sjs_array_char* sjt_parent55 = 0;
        sjs_array_char* sjt_parent56 = 0;
        sjs_string* sjt_parent58 = 0;
        sjs_array_char* sjt_parent61 = 0;
        int32_t sjv_newcount;

        sjt_dot236 = _parent;
        sjt_parent55 = &(sjt_dot236)->data;
        sjt_dot237 = _parent;
        sjt_math129 = (sjt_dot237)->count;
        sjt_dot238 = item;
        sjt_math130 = (sjt_dot238)->count;
        sjt_math127 = sjt_math129 + sjt_math130;
        sjt_math128 = 1;
        sjt_functionParam113 = sjt_math127 + sjt_math128;
        sjf_array_char_grow(sjt_parent55, sjt_functionParam113, &sjv_newdata);
        sjt_dot239 = _parent;
        sjv_newcount = (sjt_dot239)->count;
        sjt_parent56 = &sjv_newdata;
        sjt_functionParam114 = sjv_newcount;
        sjt_parent58 = item;
        sjt_functionParam117 = 0;
        sjf_string_getat(sjt_parent58, sjt_functionParam117, &sjt_functionParam115);
        sjf_array_char_setat(sjt_parent56, sjt_functionParam114, sjt_functionParam115);
        sjt_math131 = sjv_newcount;
        sjt_math132 = 1;
        sjv_newcount = sjt_math131 + sjt_math132;
        sjt_forStart8 = 1;
        sjt_dot241 = item;
        sjt_forEnd8 = (sjt_dot241)->count;
        i = sjt_forStart8;
        while (i < sjt_forEnd8) {
            int32_t sjt_functionParam118;
            char sjt_functionParam119;
            int32_t sjt_functionParam120;
            int32_t sjt_math133;
            int32_t sjt_math134;
            sjs_array_char* sjt_parent59 = 0;
            sjs_string* sjt_parent60 = 0;

            sjt_parent59 = &sjv_newdata;
            sjt_functionParam118 = sjv_newcount;
            sjt_parent60 = item;
            sjt_functionParam120 = i;
            sjf_string_getat(sjt_parent60, sjt_functionParam120, &sjt_functionParam119);
            sjf_array_char_initat(sjt_parent59, sjt_functionParam118, sjt_functionParam119);
            sjt_math133 = sjv_newcount;
            sjt_math134 = 1;
            sjv_newcount = sjt_math133 + sjt_math134;
            i++;
        }

        sjt_parent61 = &sjv_newdata;
        sjt_functionParam121 = sjv_newcount;
        sjt_cast8 = 0;
        sjt_functionParam122 = (char)sjt_cast8;
        sjf_array_char_initat(sjt_parent61, sjt_functionParam121, sjt_functionParam122);
        _return->_refCount = 1;
        _return->count = sjv_newcount;
        sjt_copy22 = &sjv_newdata;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy22);
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t sjt_compare81;
    int32_t sjt_compare82;
    sjs_string* sjt_dot242 = 0;
    bool sjt_ifElse38;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot242 = item;
    sjt_compare81 = (sjt_dot242)->count;
    sjt_compare82 = 0;
    sjt_ifElse38 = sjt_compare81 == sjt_compare82;
    if (sjt_ifElse38) {
        sjs_array_char* sjt_copy23 = 0;
        sjs_string* sjt_dot243 = 0;
        sjs_string* sjt_dot244 = 0;

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        sjt_dot243 = _parent;
        (*_return)->count = (sjt_dot243)->count;
        sjt_dot244 = _parent;
        sjt_copy23 = &(sjt_dot244)->data;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy23);
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_cast9;
        sjs_array_char* sjt_copy24 = 0;
        sjs_string* sjt_dot245 = 0;
        sjs_string* sjt_dot246 = 0;
        sjs_string* sjt_dot247 = 0;
        sjs_string* sjt_dot248 = 0;
        sjs_string* sjt_dot249 = 0;
        int32_t sjt_forEnd9;
        int32_t sjt_forStart9;
        int32_t sjt_functionParam123;
        int32_t sjt_functionParam124;
        char sjt_functionParam125;
        int32_t sjt_functionParam126;
        int32_t sjt_functionParam130;
        char sjt_functionParam131;
        int32_t sjt_math135;
        int32_t sjt_math136;
        int32_t sjt_math137;
        int32_t sjt_math138;
        int32_t sjt_math139;
        int32_t sjt_math140;
        sjs_array_char* sjt_parent62 = 0;
        sjs_array_char* sjt_parent63 = 0;
        sjs_string* sjt_parent64 = 0;
        sjs_array_char* sjt_parent67 = 0;
        int32_t sjv_newcount;

        sjt_dot245 = _parent;
        sjt_parent62 = &(sjt_dot245)->data;
        sjt_dot246 = _parent;
        sjt_math137 = (sjt_dot246)->count;
        sjt_dot247 = item;
        sjt_math138 = (sjt_dot247)->count;
        sjt_math135 = sjt_math137 + sjt_math138;
        sjt_math136 = 1;
        sjt_functionParam123 = sjt_math135 + sjt_math136;
        sjf_array_char_grow(sjt_parent62, sjt_functionParam123, &sjv_newdata);
        sjt_dot248 = _parent;
        sjv_newcount = (sjt_dot248)->count;
        sjt_parent63 = &sjv_newdata;
        sjt_functionParam124 = sjv_newcount;
        sjt_parent64 = item;
        sjt_functionParam126 = 0;
        sjf_string_getat(sjt_parent64, sjt_functionParam126, &sjt_functionParam125);
        sjf_array_char_setat(sjt_parent63, sjt_functionParam124, sjt_functionParam125);
        sjt_math139 = sjv_newcount;
        sjt_math140 = 1;
        sjv_newcount = sjt_math139 + sjt_math140;
        sjt_forStart9 = 1;
        sjt_dot249 = item;
        sjt_forEnd9 = (sjt_dot249)->count;
        i = sjt_forStart9;
        while (i < sjt_forEnd9) {
            int32_t sjt_functionParam127;
            char sjt_functionParam128;
            int32_t sjt_functionParam129;
            int32_t sjt_math141;
            int32_t sjt_math142;
            sjs_array_char* sjt_parent65 = 0;
            sjs_string* sjt_parent66 = 0;

            sjt_parent65 = &sjv_newdata;
            sjt_functionParam127 = sjv_newcount;
            sjt_parent66 = item;
            sjt_functionParam129 = i;
            sjf_string_getat(sjt_parent66, sjt_functionParam129, &sjt_functionParam128);
            sjf_array_char_initat(sjt_parent65, sjt_functionParam127, sjt_functionParam128);
            sjt_math141 = sjv_newcount;
            sjt_math142 = 1;
            sjv_newcount = sjt_math141 + sjt_math142;
            i++;
        }

        sjt_parent67 = &sjv_newdata;
        sjt_functionParam130 = sjv_newcount;
        sjt_cast9 = 0;
        sjt_functionParam131 = (char)sjt_cast9;
        sjf_array_char_initat(sjt_parent67, sjt_functionParam130, sjt_functionParam131);
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        sjt_copy24 = &sjv_newdata;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy24);
        sjf_string_heap((*_return));
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    sjs_string* sjt_dot240 = 0;
    int32_t sjt_functionParam116;
    sjs_array_char* sjt_parent57 = 0;

    sjt_dot240 = _parent;
    sjt_parent57 = &(sjt_dot240)->data;
    sjt_functionParam116 = index;
    sjf_array_char_getat(sjt_parent57, sjt_functionParam116, _return);
}

void sjf_string_hash(sjs_string* _parent, uint32_t* _return) {
    (*_return) = kh_str_hash_func((char*)_parent->data.data);
return;;
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_string* sjt_dot1 = 0;
    sjs_string* sjt_dot2 = 0;
    sjs_array_char* sjt_functionParam9 = 0;
    sjs_array_char* sjt_parent1 = 0;

    sjt_dot1 = _parent;
    sjt_parent1 = &(sjt_dot1)->data;
    sjt_dot2 = test;
    sjt_functionParam9 = &(sjt_dot2)->data;
    sjf_array_char_isequal(sjt_parent1, sjt_functionParam9, _return);
}

void sjf_textelement_as_sji_element(sjs_textelement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_textelement_element_vtbl;
}

void sjf_textelement_as_sji_textelement(sjs_textelement* _this, sji_textelement* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_textelement_textelement_vtbl;
}

void sjf_textelement_asinterface(sjs_textelement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_textelement_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        case sji_textelement_typeId:  {
            sjf_textelement_as_sji_textelement(_this, (sji_textelement*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_textelement_copy(sjs_textelement* _this, sjs_textelement* _from) {
    _this->id._refCount = 1;
    sjf_string_copy((_this->id._refCount != -1 ? &_this->id : 0), (_from->id._refCount != -1 ? &_from->id : 0));
    _this->font = _from->font;
    _this->font->_refCount++;
    _this->text._refCount = 1;
    sjf_string_copy(&_this->text, &_from->text);
    _this->color._refCount = 1;
    sjf_color_copy(&_this->color, &_from->color);
    _this->margin._refCount = 1;
    sjf_margin_copy(&_this->margin, &_from->margin);
    _this->halign = _from->halign;
    _this->valign = _from->valign;
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    _this->_textrenderer._refCount = 1;
    sjf_textrenderer_copy((_this->_textrenderer._refCount != -1 ? &_this->_textrenderer : 0), (_from->_textrenderer._refCount != -1 ? &_from->_textrenderer : 0));
}

void sjf_textelement_destroy(sjs_textelement* _this) {
    _this->font->_refCount--;
    if (_this->font->_refCount <= 0) {
        weakptr_release(_this->font);
        sjf_font_destroy(_this->font);
        free(_this->font);
    }
}

void sjf_textelement_firemouseevent(sjs_textelement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    (*_return) = true;
}

void sjf_textelement_getrect(sjs_textelement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy25 = 0;
    sjs_textelement* sjt_dot257 = 0;

    sjt_dot257 = _parent;
    sjt_copy25 = &(sjt_dot257)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy25);
}

void sjf_textelement_getrect_heap(sjs_textelement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy26 = 0;
    sjs_textelement* sjt_dot258 = 0;

    sjt_dot258 = _parent;
    sjt_copy26 = &(sjt_dot258)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy26);
}

void sjf_textelement_getsize(sjs_textelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size sjt_call33 = { -1 };
    sjs_textelement* sjt_dot251 = 0;
    sjs_textelement* sjt_dot252 = 0;
    sjs_textelement* sjt_dot253 = 0;
    sjs_string* sjt_functionParam138 = 0;
    sjs_margin* sjt_functionParam139 = 0;
    sjs_size* sjt_functionParam140 = 0;
    sjs_size* sjt_parent71 = 0;
    sjs_font* sjt_parent72 = 0;
    sjs_size* sjt_parent73 = 0;
    sjs_size sjv_textsize = { -1 };

    sjt_dot251 = _parent;
    sjt_parent72 = (sjt_dot251)->font;
    sjt_dot252 = _parent;
    sjt_functionParam138 = &(sjt_dot252)->text;
    sjf_font_gettextsize(sjt_parent72, sjt_functionParam138, &sjt_call33);
    sjt_parent71 = &sjt_call33;
    sjt_dot253 = _parent;
    sjt_functionParam139 = &(sjt_dot253)->margin;
    sjf_size_addmargin(sjt_parent71, sjt_functionParam139, &sjv_textsize);
    sjt_parent73 = &sjv_textsize;
    sjt_functionParam140 = maxsize;
    sjf_size_min(sjt_parent73, sjt_functionParam140, _return);

    if (sjt_call33._refCount == 1) { sjf_size_destroy(&sjt_call33); }
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
}

void sjf_textelement_getsize_heap(sjs_textelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size sjt_call34 = { -1 };
    sjs_textelement* sjt_dot254 = 0;
    sjs_textelement* sjt_dot255 = 0;
    sjs_textelement* sjt_dot256 = 0;
    sjs_string* sjt_functionParam141 = 0;
    sjs_margin* sjt_functionParam142 = 0;
    sjs_size* sjt_functionParam143 = 0;
    sjs_size* sjt_parent74 = 0;
    sjs_font* sjt_parent75 = 0;
    sjs_size* sjt_parent76 = 0;
    sjs_size sjv_textsize = { -1 };

    sjt_dot254 = _parent;
    sjt_parent75 = (sjt_dot254)->font;
    sjt_dot255 = _parent;
    sjt_functionParam141 = &(sjt_dot255)->text;
    sjf_font_gettextsize(sjt_parent75, sjt_functionParam141, &sjt_call34);
    sjt_parent74 = &sjt_call34;
    sjt_dot256 = _parent;
    sjt_functionParam142 = &(sjt_dot256)->margin;
    sjf_size_addmargin(sjt_parent74, sjt_functionParam142, &sjv_textsize);
    sjt_parent76 = &sjv_textsize;
    sjt_functionParam143 = maxsize;
    sjf_size_min_heap(sjt_parent76, sjt_functionParam143, _return);

    if (sjt_call34._refCount == 1) { sjf_size_destroy(&sjt_call34); }
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
}

void sjf_textelement_gettext(sjs_textelement* _parent, sjs_string* _return) {
    sjs_string* sjt_copy31 = 0;
    sjs_textelement* sjt_dot289 = 0;

    sjt_dot289 = _parent;
    sjt_copy31 = &(sjt_dot289)->text;
    _return->_refCount = 1;
    sjf_string_copy(_return, sjt_copy31);
}

void sjf_textelement_gettext_heap(sjs_textelement* _parent, sjs_string** _return) {
    sjs_string* sjt_copy32 = 0;
    sjs_textelement* sjt_dot290 = 0;

    sjt_dot290 = _parent;
    sjt_copy32 = &(sjt_dot290)->text;
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    sjf_string_copy((*_return), sjt_copy32);
}

void sjf_textelement_heap(sjs_textelement* _this) {
    bool sjt_isEmpty30;
    sjs_string* sjt_isEmpty31 = 0;

    sjt_isEmpty31 = (_this->id._refCount != -1 ? &_this->id : 0);
    sjt_isEmpty30 = (sjt_isEmpty31 != 0);
    if (sjt_isEmpty30) {
        sjs_string* ifValue20 = 0;
        sjs_textelement* sjt_cast11 = 0;
        sjs_string* sjt_functionParam136 = 0;
        sji_element sjt_functionParam137 = { 0 };
        sjs_hash_string_weak_iface_element* sjt_parent70 = 0;

        ifValue20 = (_this->id._refCount != -1 ? &_this->id : 0);
        sjt_parent70 = &sjv_elementsbyid;
        sjt_functionParam136 = ifValue20;
        sjt_cast11 = _this;
        sjf_textelement_as_sji_element(sjt_cast11, &sjt_functionParam137);
        delete_cb weakptrcb28 = { &sjt_functionParam137._parent, weakptr_clear };
        if (sjt_functionParam137._parent != 0) { weakptr_cb_add(sjt_functionParam137._parent, weakptrcb28); }
        sjf_hash_string_weak_iface_element_setat(sjt_parent70, sjt_functionParam136, sjt_functionParam137);

        delete_cb weakptrcb33 = { &sjt_functionParam137._parent, weakptr_clear };
        if (sjt_functionParam137._parent != 0) { weakptr_cb_remove(sjt_functionParam137._parent, weakptrcb33); }
    }
}

void sjf_textelement_render(sjs_textelement* _parent, sjs_scene2d* scene) {
    sjs_textelement* sjt_dot262 = 0;
    sjs_textelement* sjt_dot287 = 0;
    bool sjt_ifElse40;
    bool sjt_ifElse41;
    sjs_textrenderer* sjt_isEmpty32 = 0;
    sjs_textrenderer* sjt_isEmpty33 = 0;
    sjs_rect sjv_innerrect = { -1 };
    sjs_size sjv_textsize = { -1 };

    sjt_dot262 = _parent;
    sjt_isEmpty32 = ((sjt_dot262)->_textrenderer._refCount != -1 ? &(sjt_dot262)->_textrenderer : 0);
    sjt_ifElse40 = (sjt_isEmpty32 == 0);
    if (sjt_ifElse40) {
        int32_t sjt_compare83;
        int32_t sjt_compare84;
        int32_t sjt_compare89;
        int32_t sjt_compare90;
        sjs_string* sjt_copy28 = 0;
        sjs_color* sjt_copy29 = 0;
        sjs_font* sjt_copy30 = 0;
        sjs_textelement* sjt_dot263 = 0;
        sjs_textelement* sjt_dot264 = 0;
        sjs_textelement* sjt_dot265 = 0;
        sjs_textelement* sjt_dot266 = 0;
        sjs_textelement* sjt_dot267 = 0;
        sjs_textelement* sjt_dot275 = 0;
        sjs_textelement* sjt_dot283 = 0;
        sjs_textelement* sjt_dot284 = 0;
        sjs_textelement* sjt_dot285 = 0;
        sjs_textelement* sjt_dot286 = 0;
        sjs_string* sjt_functionParam145 = 0;
        sjs_margin* sjt_functionParam146 = 0;
        sjs_font* sjt_parent78 = 0;
        sjs_rect* sjt_parent79 = 0;
        bool sjt_switch6;
        bool sjt_switch9;
        int32_t sjv_x;
        int32_t sjv_y;
        int32_t underscore5;
        int32_t underscore6;

        sjt_dot263 = _parent;
        sjt_parent78 = (sjt_dot263)->font;
        sjt_dot264 = _parent;
        sjt_functionParam145 = &(sjt_dot264)->text;
        sjf_font_gettextsize(sjt_parent78, sjt_functionParam145, &sjv_textsize);
        sjt_dot265 = _parent;
        sjt_parent79 = &(sjt_dot265)->_rect;
        sjt_dot266 = _parent;
        sjt_functionParam146 = &(sjt_dot266)->margin;
        sjf_rect_subtractmargin(sjt_parent79, sjt_functionParam146, &sjv_innerrect);
        sjt_dot267 = _parent;
        underscore5 = (sjt_dot267)->halign;
        sjt_compare83 = underscore5;
        sjt_compare84 = sjv_texthorizontal_left;
        sjt_switch6 = sjt_compare83 == sjt_compare84;
        if (sjt_switch6) {
            sjs_rect* sjt_dot268 = 0;

            sjt_dot268 = &sjv_innerrect;
            sjv_x = (sjt_dot268)->x;
        } else {
            int32_t sjt_compare85;
            int32_t sjt_compare86;
            bool sjt_switch7;

            sjt_compare85 = underscore5;
            sjt_compare86 = sjv_texthorizontal_right;
            sjt_switch7 = sjt_compare85 == sjt_compare86;
            if (sjt_switch7) {
                sjs_rect* sjt_dot269 = 0;
                sjs_rect* sjt_dot270 = 0;
                sjs_size* sjt_dot271 = 0;
                int32_t sjt_math151;
                int32_t sjt_math152;
                int32_t sjt_math153;
                int32_t sjt_math154;

                sjt_dot269 = &sjv_innerrect;
                sjt_math153 = (sjt_dot269)->x;
                sjt_dot270 = &sjv_innerrect;
                sjt_math154 = (sjt_dot270)->w;
                sjt_math151 = sjt_math153 + sjt_math154;
                sjt_dot271 = &sjv_textsize;
                sjt_math152 = (sjt_dot271)->w;
                sjv_x = sjt_math151 - sjt_math152;
            } else {
                int32_t sjt_compare87;
                int32_t sjt_compare88;
                bool sjt_switch8;

                sjt_compare87 = underscore5;
                sjt_compare88 = sjv_texthorizontal_center;
                sjt_switch8 = sjt_compare87 == sjt_compare88;
                if (sjt_switch8) {
                    sjs_rect* sjt_dot272 = 0;
                    sjs_rect* sjt_dot273 = 0;
                    sjs_size* sjt_dot274 = 0;
                    int32_t sjt_math155;
                    int32_t sjt_math156;
                    int32_t sjt_math157;
                    int32_t sjt_math158;
                    int32_t sjt_math159;
                    int32_t sjt_math160;

                    sjt_dot272 = &sjv_innerrect;
                    sjt_math155 = (sjt_dot272)->x;
                    sjt_dot273 = &sjv_innerrect;
                    sjt_math159 = (sjt_dot273)->w;
                    sjt_dot274 = &sjv_textsize;
                    sjt_math160 = (sjt_dot274)->w;
                    sjt_math157 = sjt_math159 - sjt_math160;
                    sjt_math158 = 2;
                    sjt_math156 = sjt_math157 / sjt_math158;
                    sjv_x = sjt_math155 + sjt_math156;
                } else {
                    sjv_x = 0;
                }
            }
        }

        sjt_dot275 = _parent;
        underscore6 = (sjt_dot275)->valign;
        sjt_compare89 = underscore6;
        sjt_compare90 = sjv_textvertical_top;
        sjt_switch9 = sjt_compare89 == sjt_compare90;
        if (sjt_switch9) {
            sjs_rect* sjt_dot276 = 0;

            sjt_dot276 = &sjv_innerrect;
            sjv_y = (sjt_dot276)->y;
        } else {
            int32_t sjt_compare91;
            int32_t sjt_compare92;
            bool sjt_switch10;

            sjt_compare91 = underscore6;
            sjt_compare92 = sjv_textvertical_bottom;
            sjt_switch10 = sjt_compare91 == sjt_compare92;
            if (sjt_switch10) {
                sjs_rect* sjt_dot277 = 0;
                sjs_rect* sjt_dot278 = 0;
                sjs_size* sjt_dot279 = 0;
                int32_t sjt_math161;
                int32_t sjt_math162;
                int32_t sjt_math163;
                int32_t sjt_math164;

                sjt_dot277 = &sjv_innerrect;
                sjt_math163 = (sjt_dot277)->y;
                sjt_dot278 = &sjv_innerrect;
                sjt_math164 = (sjt_dot278)->h;
                sjt_math161 = sjt_math163 + sjt_math164;
                sjt_dot279 = &sjv_textsize;
                sjt_math162 = (sjt_dot279)->h;
                sjv_y = sjt_math161 - sjt_math162;
            } else {
                int32_t sjt_compare93;
                int32_t sjt_compare94;
                bool sjt_switch11;

                sjt_compare93 = underscore6;
                sjt_compare94 = sjv_textvertical_center;
                sjt_switch11 = sjt_compare93 == sjt_compare94;
                if (sjt_switch11) {
                    sjs_rect* sjt_dot280 = 0;
                    sjs_rect* sjt_dot281 = 0;
                    sjs_size* sjt_dot282 = 0;
                    int32_t sjt_math165;
                    int32_t sjt_math166;
                    int32_t sjt_math167;
                    int32_t sjt_math168;
                    int32_t sjt_math169;
                    int32_t sjt_math170;

                    sjt_dot280 = &sjv_innerrect;
                    sjt_math165 = (sjt_dot280)->y;
                    sjt_dot281 = &sjv_innerrect;
                    sjt_math169 = (sjt_dot281)->h;
                    sjt_dot282 = &sjv_textsize;
                    sjt_math170 = (sjt_dot282)->h;
                    sjt_math167 = sjt_math169 - sjt_math170;
                    sjt_math168 = 2;
                    sjt_math166 = sjt_math167 / sjt_math168;
                    sjv_y = sjt_math165 + sjt_math166;
                } else {
                    sjv_y = 0;
                }
            }
        }

        sjt_dot283 = _parent;
        sjt_dot283->_textrenderer._refCount = 1;
        sjt_dot284 = _parent;
        sjt_copy28 = &(sjt_dot284)->text;
        sjt_dot283->_textrenderer.text._refCount = 1;
        sjf_string_copy(&sjt_dot283->_textrenderer.text, sjt_copy28);
        sjt_dot283->_textrenderer.point._refCount = 1;
        sjt_dot283->_textrenderer.point.x = sjv_x;
        sjt_dot283->_textrenderer.point.y = sjv_y;
        sjf_point(&sjt_dot283->_textrenderer.point);
        sjt_dot285 = _parent;
        sjt_copy29 = &(sjt_dot285)->color;
        sjt_dot283->_textrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot283->_textrenderer.color, sjt_copy29);
        sjt_dot286 = _parent;
        sjt_copy30 = (sjt_dot286)->font;
        sjt_dot283->_textrenderer.font._refCount = 1;
        sjf_font_copy(&sjt_dot283->_textrenderer.font, sjt_copy30);
        sjf_textrenderer(&sjt_dot283->_textrenderer);
    }

    sjt_dot287 = _parent;
    sjt_isEmpty33 = ((sjt_dot287)->_textrenderer._refCount != -1 ? &(sjt_dot287)->_textrenderer : 0);
    sjt_ifElse41 = (sjt_isEmpty33 != 0);
    if (sjt_ifElse41) {
        sjs_textelement* sjt_dot288 = 0;
        sjs_scene2d* sjt_functionParam147 = 0;
        sjs_textrenderer* sjt_parent80 = 0;

        sjt_dot288 = _parent;
        sjt_parent80 = ((sjt_dot288)->_textrenderer._refCount != -1 ? &(sjt_dot288)->_textrenderer : 0);
        sjt_functionParam147 = scene;
        sjf_textrenderer_render(sjt_parent80, sjt_functionParam147);
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
}

void sjf_textelement_setrect(sjs_textelement* _parent, sjs_rect* rect_) {
    bool result3;
    sjs_textelement* sjt_dot259 = 0;
    sjs_rect* sjt_functionParam144 = 0;
    bool sjt_ifElse39;
    bool sjt_not2;
    sjs_rect* sjt_parent77 = 0;

    sjt_dot259 = _parent;
    sjt_parent77 = &(sjt_dot259)->_rect;
    sjt_functionParam144 = rect_;
    sjf_rect_isequal(sjt_parent77, sjt_functionParam144, &sjt_not2);
    result3 = !sjt_not2;
    sjt_ifElse39 = result3;
    if (sjt_ifElse39) {
        sjs_rect* sjt_copy27 = 0;
        sjs_textelement* sjt_dot260 = 0;
        sjs_textelement* sjt_dot261 = 0;

        sjt_dot260 = _parent;
        sjt_copy27 = rect_;
        sjt_dot260->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot260->_rect, sjt_copy27);
        sjt_dot261 = _parent;
        sjt_dot261->_textrenderer._refCount = -1;
    }
}

void sjf_textelement_settext(sjs_textelement* _parent, sjs_string* text_) {
    sjs_string* sjt_copy33 = 0;
    sjs_textelement* sjt_dot291 = 0;
    sjs_textelement* sjt_dot292 = 0;

    sjt_dot291 = _parent;
    sjt_copy33 = text_;
    sjt_dot291->text._refCount = 1;
    sjf_string_copy(&sjt_dot291->text, sjt_copy33);
    sjt_dot292 = _parent;
    sjt_dot292->_textrenderer._refCount = -1;
}

void sjf_textrenderer(sjs_textrenderer* _this) {
    vec2 pen = {{ (float)_this->point.x, (float)_this->point.y }};
    vec4 color = {{ _this->color.r, _this->color.g, _this->color.b, _this->color.a }};
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f,color:4f");
    add_text(_this->buffer, _this->font.font, (char*)_this->text.data.data, &color, &pen);
    glBindTexture(GL_TEXTURE_2D, _this->font.font->atlas->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)_this->font.font->atlas->width, (int)_this->font.font->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->font.font->atlas->data );
}

void sjf_textrenderer_copy(sjs_textrenderer* _this, sjs_textrenderer* _from) {
    _this->text._refCount = 1;
    sjf_string_copy(&_this->text, &_from->text);
    _this->point._refCount = 1;
    sjf_point_copy(&_this->point, &_from->point);
    _this->color._refCount = 1;
    sjf_color_copy(&_this->color, &_from->color);
    _this->font._refCount = 1;
    sjf_font_copy(&_this->font, &_from->font);
    _this->buffer = _from->buffer;
    ptr_retain(_this->buffer);
}

void sjf_textrenderer_destroy(sjs_textrenderer* _this) {
    if (ptr_release(_this->buffer)) {
        vertex_buffer_delete(_this->buffer);
    }  
}

void sjf_textrenderer_heap(sjs_textrenderer* _this) {
    vec2 pen = {{ (float)_this->point.x, (float)_this->point.y }};
    vec4 color = {{ _this->color.r, _this->color.g, _this->color.b, _this->color.a }};
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f,color:4f");
    add_text(_this->buffer, _this->font.font, (char*)_this->text.data.data, &color, &pen);
    glBindTexture(GL_TEXTURE_2D, _this->font.font->atlas->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)_this->font.font->atlas->width, (int)_this->font.font->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->font.font->atlas->data );
}

void sjf_textrenderer_render(sjs_textrenderer* _parent, sjs_scene2d* scene) {
    sjs_string sjt_call14 = { -1 };
    sjs_string sjt_call15 = { -1 };
    sjs_string sjt_call16 = { -1 };
    sjs_string sjt_call17 = { -1 };
    sjs_scene2d* sjt_dot185 = 0;
    sjs_scene2d* sjt_dot186 = 0;
    sjs_scene2d* sjt_dot187 = 0;
    sjs_shader* sjt_functionParam72 = 0;
    int32_t sjt_functionParam73;
    int32_t sjt_functionParam74;
    int32_t sjt_functionParam75;
    sjs_shader* sjt_functionParam76 = 0;
    sjs_string* sjt_functionParam77 = 0;
    int32_t sjt_functionParam78;
    int32_t sjt_functionParam79;
    sjs_shader* sjt_functionParam80 = 0;
    sjs_string* sjt_functionParam81 = 0;
    sjs_mat4* sjt_functionParam82 = 0;
    int32_t sjt_functionParam83;
    sjs_shader* sjt_functionParam84 = 0;
    sjs_string* sjt_functionParam85 = 0;
    sjs_mat4* sjt_functionParam86 = 0;
    int32_t sjt_functionParam87;
    sjs_shader* sjt_functionParam88 = 0;
    sjs_string* sjt_functionParam89 = 0;
    sjs_mat4* sjt_functionParam90 = 0;

    glBindTexture(GL_TEXTURE_2D, _parent->font.atlas->id);
    sjt_functionParam72 = &sjv_textshader;
    sjf_gluseprogram(sjt_functionParam72);
    sjt_functionParam73 = sjv_glblendfunctype_gl_src_alpha;
    sjt_functionParam74 = sjv_glblendfunctype_gl_one_minus_src_alpha;
    sjf_glblendfunc(sjt_functionParam73, sjt_functionParam74);
    sjt_functionParam76 = &sjv_textshader;
    sjt_call14._refCount = 1;
    sjt_call14.count = 7;
    sjt_call14.data._refCount = 1;
    sjt_call14.data.datasize = 8;
    sjt_call14.data.data = (void*)sjg_string21;
    sjt_call14.data._isglobal = true;
    sjt_call14.data.count = 8;
    sjf_array_char(&sjt_call14.data);
    sjf_string(&sjt_call14);
    sjt_functionParam77 = &sjt_call14;
    sjf_glgetuniformlocation(sjt_functionParam76, sjt_functionParam77, &sjt_functionParam75);
    sjt_functionParam78 = 0;
    sjf_gluniformi32(sjt_functionParam75, sjt_functionParam78);
    sjt_functionParam80 = &sjv_textshader;
    sjt_call15._refCount = 1;
    sjt_call15.count = 5;
    sjt_call15.data._refCount = 1;
    sjt_call15.data.datasize = 6;
    sjt_call15.data.data = (void*)sjg_string22;
    sjt_call15.data._isglobal = true;
    sjt_call15.data.count = 6;
    sjf_array_char(&sjt_call15.data);
    sjf_string(&sjt_call15);
    sjt_functionParam81 = &sjt_call15;
    sjf_glgetuniformlocation(sjt_functionParam80, sjt_functionParam81, &sjt_functionParam79);
    sjt_dot185 = scene;
    sjt_functionParam82 = &(sjt_dot185)->model;
    sjf_gluniformmat4(sjt_functionParam79, sjt_functionParam82);
    sjt_functionParam84 = &sjv_textshader;
    sjt_call16._refCount = 1;
    sjt_call16.count = 4;
    sjt_call16.data._refCount = 1;
    sjt_call16.data.datasize = 5;
    sjt_call16.data.data = (void*)sjg_string23;
    sjt_call16.data._isglobal = true;
    sjt_call16.data.count = 5;
    sjf_array_char(&sjt_call16.data);
    sjf_string(&sjt_call16);
    sjt_functionParam85 = &sjt_call16;
    sjf_glgetuniformlocation(sjt_functionParam84, sjt_functionParam85, &sjt_functionParam83);
    sjt_dot186 = scene;
    sjt_functionParam86 = &(sjt_dot186)->view;
    sjf_gluniformmat4(sjt_functionParam83, sjt_functionParam86);
    sjt_functionParam88 = &sjv_textshader;
    sjt_call17._refCount = 1;
    sjt_call17.count = 10;
    sjt_call17.data._refCount = 1;
    sjt_call17.data.datasize = 11;
    sjt_call17.data.data = (void*)sjg_string24;
    sjt_call17.data._isglobal = true;
    sjt_call17.data.count = 11;
    sjf_array_char(&sjt_call17.data);
    sjf_string(&sjt_call17);
    sjt_functionParam89 = &sjt_call17;
    sjf_glgetuniformlocation(sjt_functionParam88, sjt_functionParam89, &sjt_functionParam87);
    sjt_dot187 = scene;
    sjt_functionParam90 = &(sjt_dot187)->projection;
    sjf_gluniformmat4(sjt_functionParam87, sjt_functionParam90);
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);

    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
    if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
}

void sjf_texture(sjs_texture* _this) {
}

void sjf_texture_copy(sjs_texture* _this, sjs_texture* _from) {
    _this->size._refCount = 1;
    sjf_size_copy(&_this->size, &_from->size);
    _this->id = _from->id;
    glid_retain(_this->id);
}

void sjf_texture_destroy(sjs_texture* _this) {
    if (glid_release(_this->id)) {
        glDeleteTextures(1, &_this->id);
    }
}

void sjf_texture_frompng(sjs_string* filename, sjs_texture* _return) {
    int32_t sjv_h;
    uint32_t sjv_id;
    int32_t sjv_w;

    sjv_id = (uint32_t)0u;
    sjv_w = 0;
    sjv_h = 0;
    sjv_id = png_texture_load((char*)filename->data.data, &sjv_w, &sjv_h);
    _return->_refCount = 1;
    _return->size._refCount = 1;
    _return->size.w = sjv_w;
    _return->size.h = sjv_h;
    sjf_size(&_return->size);
    _return->id = sjv_id;
    sjf_texture(_return);
}

void sjf_texture_frompng_heap(sjs_string* filename, sjs_texture** _return) {
    int32_t sjv_h;
    uint32_t sjv_id;
    int32_t sjv_w;

    sjv_id = (uint32_t)0u;
    sjv_w = 0;
    sjv_h = 0;
    sjv_id = png_texture_load((char*)filename->data.data, &sjv_w, &sjv_h);
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
    (*_return)->_refCount = 1;
    (*_return)->size._refCount = 1;
    (*_return)->size.w = sjv_w;
    (*_return)->size.h = sjv_h;
    sjf_size(&(*_return)->size);
    (*_return)->id = sjv_id;
    sjf_texture_heap((*_return));
}

void sjf_texture_getsize(sjs_texture* _parent, sjs_size* _return) {
    sjs_size* sjt_dot87 = 0;
    sjs_texture* sjt_dot88 = 0;
    sjs_size* sjt_dot89 = 0;
    sjs_texture* sjt_dot90 = 0;

    _return->_refCount = 1;
    sjt_dot88 = _parent;
    sjt_dot87 = &(sjt_dot88)->size;
    _return->w = (sjt_dot87)->w;
    sjt_dot90 = _parent;
    sjt_dot89 = &(sjt_dot90)->size;
    _return->h = (sjt_dot89)->h;
    sjf_size(_return);
}

void sjf_texture_getsize_heap(sjs_texture* _parent, sjs_size** _return) {
    sjs_size* sjt_dot91 = 0;
    sjs_texture* sjt_dot92 = 0;
    sjs_size* sjt_dot93 = 0;
    sjs_texture* sjt_dot94 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot92 = _parent;
    sjt_dot91 = &(sjt_dot92)->size;
    (*_return)->w = (sjt_dot91)->w;
    sjt_dot94 = _parent;
    sjt_dot93 = &(sjt_dot94)->size;
    (*_return)->h = (sjt_dot93)->h;
    sjf_size_heap((*_return));
}

void sjf_texture_heap(sjs_texture* _this) {
}

void sjf_vec3(sjs_vec3* _this) {
}

void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
    _this->z = _from->z;
}

void sjf_vec3_destroy(sjs_vec3* _this) {
}

void sjf_vec3_heap(sjs_vec3* _this) {
}

void sjf_windowrenderer(sjs_windowrenderer* _this) {
    sjs_color sjt_call1 = { -1 };
    sjs_color* sjt_functionParam1 = 0;
    int32_t sjt_functionParam2;
    int32_t sjt_functionParam3;
    int32_t sjt_functionParam4;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        halt("SDL_Init Error: %s\n", SDL_GetError());
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
    _this->win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (_this->win == 0) {
        halt("SDL_CreateWindow Error: %s\n", SDL_GetError());
    }
    SDL_GL_CreateContext((SDL_Window*)_this->win);
    #ifdef WIN32
    GLint GlewInitResult = glewInit();
    if (GLEW_OK != GlewInitResult) 
    {
        halt("ERROR: %s\n", glewGetErrorString(GlewInitResult));
    }
    #endif
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_this->ren == 0) {
        halt("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    }
    sjt_call1._refCount = 1;
    sjt_call1.r = 0.0f;
    sjt_call1.g = 0.0f;
    sjt_call1.b = 0.0f;
    sjt_call1.a = 0.0f;
    sjf_color(&sjt_call1);
    sjt_functionParam1 = &sjt_call1;
    sjf_glclearcolor(sjt_functionParam1);
    sjt_functionParam2 = sjv_glblendfunctype_gl_src_alpha;
    sjt_functionParam3 = sjv_glblendfunctype_gl_one_minus_src_alpha;
    sjf_glblendfunc(sjt_functionParam2, sjt_functionParam3);
    sjt_functionParam4 = sjv_glfeature_gl_blend;
    sjf_glenable(sjt_functionParam4);

    if (sjt_call1._refCount == 1) { sjf_color_destroy(&sjt_call1); }
}

void sjf_windowrenderer_copy(sjs_windowrenderer* _this, sjs_windowrenderer* _from) {
    _this->ren = _from->ren;
    ptr_retain(_this->ren);
    _this->win = _from->win;
    ptr_retain(_this->win);
}

void sjf_windowrenderer_destroy(sjs_windowrenderer* _this) {
    if (ptr_release(_this->ren)) {
        SDL_DestroyRenderer(_this->ren);
    }
    if (ptr_release(_this->win)) {
        SDL_DestroyWindow(_this->win);
    }
}

void sjf_windowrenderer_getsize(sjs_windowrenderer* _parent, sjs_size* _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    SDL_GetRendererOutputSize(_parent->ren, &sjv_w, &sjv_h);
    _return->_refCount = 1;
    _return->w = sjv_w;
    _return->h = sjv_h;
    sjf_size(_return);
}

void sjf_windowrenderer_getsize_heap(sjs_windowrenderer* _parent, sjs_size** _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    SDL_GetRendererOutputSize(_parent->ren, &sjv_w, &sjv_h);
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    (*_return)->w = sjv_w;
    (*_return)->h = sjv_h;
    sjf_size_heap((*_return));
}

void sjf_windowrenderer_heap(sjs_windowrenderer* _this) {
    sjs_color sjt_call2 = { -1 };
    sjs_color* sjt_functionParam5 = 0;
    int32_t sjt_functionParam6;
    int32_t sjt_functionParam7;
    int32_t sjt_functionParam8;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        halt("SDL_Init Error: %s\n", SDL_GetError());
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
    _this->win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (_this->win == 0) {
        halt("SDL_CreateWindow Error: %s\n", SDL_GetError());
    }
    SDL_GL_CreateContext((SDL_Window*)_this->win);
    #ifdef WIN32
    GLint GlewInitResult = glewInit();
    if (GLEW_OK != GlewInitResult) 
    {
        halt("ERROR: %s\n", glewGetErrorString(GlewInitResult));
    }
    #endif
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_this->ren == 0) {
        halt("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    }
    sjt_call2._refCount = 1;
    sjt_call2.r = 0.0f;
    sjt_call2.g = 0.0f;
    sjt_call2.b = 0.0f;
    sjt_call2.a = 0.0f;
    sjf_color(&sjt_call2);
    sjt_functionParam5 = &sjt_call2;
    sjf_glclearcolor(sjt_functionParam5);
    sjt_functionParam6 = sjv_glblendfunctype_gl_src_alpha;
    sjt_functionParam7 = sjv_glblendfunctype_gl_one_minus_src_alpha;
    sjf_glblendfunc(sjt_functionParam6, sjt_functionParam7);
    sjt_functionParam8 = sjv_glfeature_gl_blend;
    sjf_glenable(sjt_functionParam8);

    if (sjt_call2._refCount == 1) { sjf_color_destroy(&sjt_call2); }
}

void sjf_windowrenderer_present(sjs_windowrenderer* _parent) {
    SDL_GL_SwapWindow((SDL_Window*)_parent->win);
}

int main(int argc, char** argv) {
    sjs_buttonelement_clickable_vtbl.destroy = (void(*)(void*))sjf_buttonelement_destroy;
    sjs_buttonelement_clickable_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_buttonelement_asinterface;
    sjs_buttonelement_clickable_vtbl.onclickgestureenter = (void(*)(sjs_object*,sji_element))sjf_buttonelement_onclickgestureenter;
    sjs_buttonelement_clickable_vtbl.onclickgestureleave = (void(*)(sjs_object*,sji_element))sjf_buttonelement_onclickgestureleave;
    sjs_buttonelement_clickable_vtbl.onclickgesturepress = (void(*)(sjs_object*,sji_element))sjf_buttonelement_onclickgesturepress;
    sjs_buttonelement_clickable_vtbl.onclickgestureclick = (void(*)(sjs_object*,sji_element))sjf_buttonelement_onclickgestureclick;
    sjs_buttonelement_element_vtbl.destroy = (void(*)(void*))sjf_buttonelement_destroy;
    sjs_buttonelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_buttonelement_asinterface;
    sjs_buttonelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_buttonelement_getsize;
    sjs_buttonelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_buttonelement_getsize_heap;
    sjs_buttonelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_buttonelement_getrect;
    sjs_buttonelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_buttonelement_getrect_heap;
    sjs_buttonelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_buttonelement_setrect;
    sjs_buttonelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_buttonelement_render;
    sjs_buttonelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_buttonelement_firemouseevent;
    sjs_gridlayout_element_vtbl.destroy = (void(*)(void*))sjf_gridlayout_destroy;
    sjs_gridlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_gridlayout_asinterface;
    sjs_gridlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_gridlayout_getsize;
    sjs_gridlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_gridlayout_getsize_heap;
    sjs_gridlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_gridlayout_getrect;
    sjs_gridlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_gridlayout_getrect_heap;
    sjs_gridlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_gridlayout_setrect;
    sjs_gridlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_gridlayout_render;
    sjs_gridlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_gridlayout_firemouseevent;
    sjs_textelement_element_vtbl.destroy = (void(*)(void*))sjf_textelement_destroy;
    sjs_textelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_textelement_asinterface;
    sjs_textelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_textelement_getsize;
    sjs_textelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_textelement_getsize_heap;
    sjs_textelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_textelement_getrect;
    sjs_textelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_textelement_getrect_heap;
    sjs_textelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_textelement_setrect;
    sjs_textelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_textelement_render;
    sjs_textelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_textelement_firemouseevent;
    sjs_textelement_textelement_vtbl.destroy = (void(*)(void*))sjf_textelement_destroy;
    sjs_textelement_textelement_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_textelement_asinterface;
    sjs_textelement_textelement_vtbl.gettext = (void(*)(sjs_object*, sjs_string*))sjf_textelement_gettext;
    sjs_textelement_textelement_vtbl.gettext_heap = (void(*)(sjs_object*, sjs_string**))sjf_textelement_gettext_heap;
    sjs_textelement_textelement_vtbl.settext = (void(*)(sjs_object*,sjs_string*))sjf_textelement_settext;
    sjv_borderposition_fill = 0;
    sjv_borderposition_left = 1;
    sjv_borderposition_right = 2;
    sjv_borderposition_top = 3;
    sjv_borderposition_bottom = 4;
    sjv_clickstate_none = 0;
    sjv_clickstate_entered = 1;
    sjv_clickstate_pressed = 2;
    sjv_flowlayoutorientation_topbottom = 0;
    sjv_flowlayoutorientation_leftright = 1;
    sjv_flowlayoutorientation_bottomtop = 2;
    sjv_flowlayoutorientation_rightleft = 3;
    sjv_glfeature_gl_blend = 0x0BE2;
    sjv_glfeature_gl_cull_face = 0x0B44;
    sjv_glfeature_gl_depth_test = 0x0B71;
    sjv_glfeature_gl_dither = 0x0BD0;
    sjv_glfeature_gl_polygon_offset_fill = 0x8037;
    sjv_glfeature_gl_sample_alpha_to_coverage = 0x809E;
    sjv_glfeature_gl_sample_coverage = 0x80A0;
    sjv_glfeature_gl_scissor_test = 0x0C11;
    sjv_glfeature_gl_stencil_test = 0x0B90;
    sjv_gltexture_gl_texture_2d = 0x0DE1;
    sjv_gltexture_gl_texture_cube_map = 0x8513;
    sjv_gltextureattribute_gl_texture_min_filter = 0x2801;
    sjv_gltextureattribute_gl_texture_mag_filter = 0x2800;
    sjv_gltextureattribute_gl_texture_wrap_s = 0x2802;
    sjv_gltextureattribute_gl_texture_wrap_t = 0x2803;
    sjv_gltexturevalue_gl_clamp_to_edge = 0x812F;
    sjv_gltexturevalue_gl_mirrored_repeat = 0x8370;
    sjv_gltexturevalue_gl_repeat = 0x2901;
    sjv_gltexturevalue_gl_nearest = 0x2600;
    sjv_gltexturevalue_gl_linear = 0x2601;
    sjv_gltexturevalue_gl_nearest_mipmap_nearest = 0x2700;
    sjv_gltexturevalue_gl_linear_mipmap_nearest = 0x2701;
    sjv_gltexturevalue_gl_nearest_mipmap_linear = 0x2702;
    sjv_gltexturevalue_gl_linear_mipmap_linear = 0x2703;
    sjv_gltextureformat_gl_alpha = 0x1906;
    sjv_gltextureformat_gl_luminance = 0x1909;
    sjv_gltextureformat_gl_luminance_alpha = 0x190A;
    sjv_gltextureformat_gl_rgb = 0x1907;
    sjv_gltextureformat_gl_rgba = 0x1908;
    sjv_gltexturetype_gl_unsigned_byte = 0x1401;
    sjv_gltexturetype_gl_unsigned_short_5_6_5 = 0x8363;
    sjv_gltexturetype_gl_unsigned_short_4_4_4_4 = 0x8033;
    sjv_gltexturetype_gl_unsigned_short_5_5_5_1 = 0x8034;
    sjv_glframebufferattachment_gl_color_attachment0 = 0x8CE0;
    sjv_glframebufferattachment_gl_depth_attachment = 0x8D00;
    sjv_glframebufferattachment_gl_stencil_attachment = 0x8D20;
    sjv_glframebuffertexture_gl_texture_2d = 0x0DE1;
    sjv_glframebuffertexture_gl_texture_cube_map_positive_x = 0x8515;
    sjv_glframebuffertexture_gl_texture_cube_map_negative_x = 0x8516;
    sjv_glframebuffertexture_gl_texture_cube_map_positive_y = 0x8517;
    sjv_glframebuffertexture_gl_texture_cube_map_negative_y = 0x8518;
    sjv_glframebuffertexture_gl_texture_cube_map_positive_z = 0x8519;
    sjv_glframebuffertexture_gl_texture_cube_map_negative_z = 0x851A;
    sjv_glrenderbufferformat_gl_rgba4 = 0x8056;
    sjv_glrenderbufferformat_gl_rgb565 = 0x8D62;
    sjv_glrenderbufferformat_gl_rgb5_a1 = 0x8057;
    sjv_glrenderbufferformat_gl_depth_component16 = 0x81A5;
    sjv_glrenderbufferformat_gl_stencil_index8 = 0x8D48;
    sjv_glframebufferstatus_gl_framebuffer_complete = 0x8CD5;
    sjv_glframebufferstatus_gl_framebuffer_incomplete_attachment = 0x8CD6;
    sjv_glframebufferstatus_gl_framebuffer_incomplete_missing_attachment = 0x8CD7;
    sjv_glframebufferstatus_gl_framebuffer_unsupported = 0x8CDD;
    sjv_glblendfunctype_gl_zero = 0;
    sjv_glblendfunctype_gl_one = 1;
    sjv_glblendfunctype_gl_src_color = 0x0300;
    sjv_glblendfunctype_gl_one_minus_src_color = 0x0301;
    sjv_glblendfunctype_gl_dst_color = 0x0306;
    sjv_glblendfunctype_gl_one_minus_dst_color = 0x0307;
    sjv_glblendfunctype_gl_src_alpha = 0x0302;
    sjv_glblendfunctype_gl_one_minus_src_alpha = 0x0303;
    sjv_glblendfunctype_gl_dst_alpha = 0x0304;
    sjv_glblendfunctype_gl_one_minus_dst_alpha = 0x0305;
    sjv_glblendfunctype_gl_constant_color = 0x8001;
    sjv_glblendfunctype_gl_one_minus_constant_color = 0x8002;
    sjv_glblendfunctype_gl_constant_alpha = 0x8003;
    sjv_glblendfunctype_gl_one_minus_constant_alpha = 0x8004;
    sjv_glblendfunctype_gl_src_alpha_saturate = 0x0308;
    sjv_gridunittype_fixed = 0;
    sjv_gridunittype_star = 1;
    sjv_imagestretch_fill = 0;
    sjv_imagestretch_center = 1;
    sjv_imagestretch_aspectratio = 2;
    sjv_listlayoutorientation_topbottom = 0;
    sjv_listlayoutorientation_leftright = 1;
    sjv_listlayoutorientation_bottomtop = 2;
    sjv_listlayoutorientation_rightleft = 3;
    sjv_mouseeventtype_move = 0;
    sjv_mouseeventtype_up = 1;
    sjv_mouseeventtype_down = 2;
    sjv_texthorizontal_left = 0;
    sjv_texthorizontal_right = 1;
    sjv_texthorizontal_center = 2;
    sjv_textvertical_top = 0;
    sjv_textvertical_bottom = 1;
    sjv_textvertical_center = 2;
    sjv_f32_pi = 3.14159265358979323846f;
    sjv_u32_maxvalue = (uint32_t)4294967295u;
    sjt_negate1 = 1;
    result1 = -sjt_negate1;
    sjt_math1 = result1;
    sjt_math2 = 2147483647;
    sjv_i32_maxvalue = sjt_math1 - sjt_math2;
    sjv_i32_minvalue = 2147483647;
    sjv_emptystringdata = 0;
    sjv_emptystringdata = "";
    ptr_init();
    weakptr_init();
    sjv_rootwindowrenderer._refCount = 1;
    sjf_windowrenderer(&sjv_rootwindowrenderer);
    sjv_rootscene._refCount = 1;
    sjv_rootscene._size._refCount = 1;
    sjv_rootscene._size.w = 0;
    sjv_rootscene._size.h = 0;
    sjf_size(&sjv_rootscene._size);
    sjv_rootscene.model._refCount = 1;
    sjv_rootscene.model.m00 = 0.0f;
    sjv_rootscene.model.m01 = 0.0f;
    sjv_rootscene.model.m02 = 0.0f;
    sjv_rootscene.model.m03 = 0.0f;
    sjv_rootscene.model.m10 = 0.0f;
    sjv_rootscene.model.m11 = 0.0f;
    sjv_rootscene.model.m12 = 0.0f;
    sjv_rootscene.model.m13 = 0.0f;
    sjv_rootscene.model.m20 = 0.0f;
    sjv_rootscene.model.m21 = 0.0f;
    sjv_rootscene.model.m22 = 0.0f;
    sjv_rootscene.model.m23 = 0.0f;
    sjv_rootscene.model.m30 = 0.0f;
    sjv_rootscene.model.m31 = 0.0f;
    sjv_rootscene.model.m32 = 0.0f;
    sjv_rootscene.model.m33 = 0.0f;
    sjf_mat4(&sjv_rootscene.model);
    sjv_rootscene.view._refCount = 1;
    sjv_rootscene.view.m00 = 0.0f;
    sjv_rootscene.view.m01 = 0.0f;
    sjv_rootscene.view.m02 = 0.0f;
    sjv_rootscene.view.m03 = 0.0f;
    sjv_rootscene.view.m10 = 0.0f;
    sjv_rootscene.view.m11 = 0.0f;
    sjv_rootscene.view.m12 = 0.0f;
    sjv_rootscene.view.m13 = 0.0f;
    sjv_rootscene.view.m20 = 0.0f;
    sjv_rootscene.view.m21 = 0.0f;
    sjv_rootscene.view.m22 = 0.0f;
    sjv_rootscene.view.m23 = 0.0f;
    sjv_rootscene.view.m30 = 0.0f;
    sjv_rootscene.view.m31 = 0.0f;
    sjv_rootscene.view.m32 = 0.0f;
    sjv_rootscene.view.m33 = 0.0f;
    sjf_mat4(&sjv_rootscene.view);
    sjv_rootscene.projection._refCount = 1;
    sjv_rootscene.projection.m00 = 0.0f;
    sjv_rootscene.projection.m01 = 0.0f;
    sjv_rootscene.projection.m02 = 0.0f;
    sjv_rootscene.projection.m03 = 0.0f;
    sjv_rootscene.projection.m10 = 0.0f;
    sjv_rootscene.projection.m11 = 0.0f;
    sjv_rootscene.projection.m12 = 0.0f;
    sjv_rootscene.projection.m13 = 0.0f;
    sjv_rootscene.projection.m20 = 0.0f;
    sjv_rootscene.projection.m21 = 0.0f;
    sjv_rootscene.projection.m22 = 0.0f;
    sjv_rootscene.projection.m23 = 0.0f;
    sjv_rootscene.projection.m30 = 0.0f;
    sjv_rootscene.projection.m31 = 0.0f;
    sjv_rootscene.projection.m32 = 0.0f;
    sjv_rootscene.projection.m33 = 0.0f;
    sjf_mat4(&sjv_rootscene.projection);
    sjv_rootscene.windowrect._refCount = 1;
    sjv_rootscene.windowrect.x = 0;
    sjv_rootscene.windowrect.y = 0;
    sjv_rootscene.windowrect.w = 0;
    sjv_rootscene.windowrect.h = 0;
    sjf_rect(&sjv_rootscene.windowrect);
    sjf_scene2d(&sjv_rootscene);
    sjv_modelsbyid._refCount = 1;
    sjf_hash_string_weak_iface_model(&sjv_modelsbyid);
    sjv_elementsbyid._refCount = 1;
    sjf_hash_string_weak_iface_element(&sjv_elementsbyid);
    sjv_animator._refCount = 1;
    sjv_animator.animations._refCount = 1;
    sjv_animator.animations.array._refCount = 1;
    sjv_animator.animations.array.datasize = 0;
    sjv_animator.animations.array.data = 0;
    sjv_animator.animations.array._isglobal = false;
    sjv_animator.animations.array.count = 0;
    sjf_array_heap_iface_animation(&sjv_animator.animations.array);
    sjf_list_heap_iface_animation(&sjv_animator.animations);
    sjv_animator.current = 0;
    sjf_anon1(&sjv_animator);
    sjv_blurhorizontalshader._refCount = 1;
    sjv_blurhorizontalshader.vertex._refCount = 1;
    sjv_blurhorizontalshader.vertex.count = 20;
    sjv_blurhorizontalshader.vertex.data._refCount = 1;
    sjv_blurhorizontalshader.vertex.data.datasize = 21;
    sjv_blurhorizontalshader.vertex.data.data = (void*)sjg_string1;
    sjv_blurhorizontalshader.vertex.data._isglobal = true;
    sjv_blurhorizontalshader.vertex.data.count = 21;
    sjf_array_char(&sjv_blurhorizontalshader.vertex.data);
    sjf_string(&sjv_blurhorizontalshader.vertex);
    sjv_blurhorizontalshader.pixel._refCount = 1;
    sjv_blurhorizontalshader.pixel.count = 28;
    sjv_blurhorizontalshader.pixel.data._refCount = 1;
    sjv_blurhorizontalshader.pixel.data.datasize = 29;
    sjv_blurhorizontalshader.pixel.data.data = (void*)sjg_string2;
    sjv_blurhorizontalshader.pixel.data._isglobal = true;
    sjv_blurhorizontalshader.pixel.data.count = 29;
    sjf_array_char(&sjv_blurhorizontalshader.pixel.data);
    sjf_string(&sjv_blurhorizontalshader.pixel);
    sjf_shader(&sjv_blurhorizontalshader);
    sjv_blurverticalshader._refCount = 1;
    sjv_blurverticalshader.vertex._refCount = 1;
    sjv_blurverticalshader.vertex.count = 20;
    sjv_blurverticalshader.vertex.data._refCount = 1;
    sjv_blurverticalshader.vertex.data.datasize = 21;
    sjv_blurverticalshader.vertex.data.data = (void*)sjg_string1;
    sjv_blurverticalshader.vertex.data._isglobal = true;
    sjv_blurverticalshader.vertex.data.count = 21;
    sjf_array_char(&sjv_blurverticalshader.vertex.data);
    sjf_string(&sjv_blurverticalshader.vertex);
    sjv_blurverticalshader.pixel._refCount = 1;
    sjv_blurverticalshader.pixel.count = 26;
    sjv_blurverticalshader.pixel.data._refCount = 1;
    sjv_blurverticalshader.pixel.data.datasize = 27;
    sjv_blurverticalshader.pixel.data.data = (void*)sjg_string3;
    sjv_blurverticalshader.pixel.data._isglobal = true;
    sjv_blurverticalshader.pixel.data.count = 27;
    sjf_array_char(&sjv_blurverticalshader.pixel.data);
    sjf_string(&sjv_blurverticalshader.pixel);
    sjf_shader(&sjv_blurverticalshader);
    sjv_colors_red._refCount = 1;
    sjv_colors_red.r = 1.0f;
    sjv_colors_red.g = 0.0f;
    sjv_colors_red.b = 0.0f;
    sjv_colors_red.a = 1.0f;
    sjf_color(&sjv_colors_red);
    sjv_colors_green._refCount = 1;
    sjv_colors_green.r = 0.0f;
    sjv_colors_green.g = 1.0f;
    sjv_colors_green.b = 0.0f;
    sjv_colors_green.a = 1.0f;
    sjf_color(&sjv_colors_green);
    sjv_colors_blue._refCount = 1;
    sjv_colors_blue.r = 0.0f;
    sjv_colors_blue.g = 0.0f;
    sjv_colors_blue.b = 1.0f;
    sjv_colors_blue.a = 1.0f;
    sjf_color(&sjv_colors_blue);
    sjv_colors_black._refCount = 1;
    sjv_colors_black.r = 0.0f;
    sjv_colors_black.g = 0.0f;
    sjv_colors_black.b = 0.0f;
    sjv_colors_black.a = 1.0f;
    sjf_color(&sjv_colors_black);
    sjv_colors_white._refCount = 1;
    sjv_colors_white.r = 1.0f;
    sjv_colors_white.g = 1.0f;
    sjv_colors_white.b = 1.0f;
    sjv_colors_white.a = 1.0f;
    sjf_color(&sjv_colors_white);
    sjv_colors_gray._refCount = 1;
    sjv_colors_gray.r = 0.5f;
    sjv_colors_gray.g = 0.5f;
    sjv_colors_gray.b = 0.5f;
    sjv_colors_gray.a = 1.0f;
    sjf_color(&sjv_colors_gray);
    sjv_fadeshader._refCount = 1;
    sjv_fadeshader.vertex._refCount = 1;
    sjv_fadeshader.vertex.count = 20;
    sjv_fadeshader.vertex.data._refCount = 1;
    sjv_fadeshader.vertex.data.datasize = 21;
    sjv_fadeshader.vertex.data.data = (void*)sjg_string1;
    sjv_fadeshader.vertex.data._isglobal = true;
    sjv_fadeshader.vertex.data.count = 21;
    sjf_array_char(&sjv_fadeshader.vertex.data);
    sjf_string(&sjv_fadeshader.vertex);
    sjv_fadeshader.pixel._refCount = 1;
    sjv_fadeshader.pixel.count = 17;
    sjv_fadeshader.pixel.data._refCount = 1;
    sjv_fadeshader.pixel.data.datasize = 18;
    sjv_fadeshader.pixel.data.data = (void*)sjg_string4;
    sjv_fadeshader.pixel.data._isglobal = true;
    sjv_fadeshader.pixel.data.count = 18;
    sjf_array_char(&sjv_fadeshader.pixel.data);
    sjf_string(&sjv_fadeshader.pixel);
    sjf_shader(&sjv_fadeshader);
    sjv_fonthash._refCount = 1;
    sjf_hash_fontkey_weak_font(&sjv_fonthash);
    sjv_glviewports._refCount = 1;
    sjv_glviewports.array._refCount = 1;
    sjv_glviewports.array.datasize = 0;
    sjv_glviewports.array.data = 0;
    sjv_glviewports.array._isglobal = false;
    sjv_glviewports.array.count = 0;
    sjf_array_rect(&sjv_glviewports.array);
    sjf_list_rect(&sjv_glviewports);
    sjv_glframebuffers._refCount = 1;
    sjv_glframebuffers.array._refCount = 1;
    sjv_glframebuffers.array.datasize = 0;
    sjv_glframebuffers.array.data = 0;
    sjv_glframebuffers.array._isglobal = false;
    sjv_glframebuffers.array.count = 0;
    sjf_array_u32(&sjv_glframebuffers.array);
    sjf_list_u32(&sjv_glframebuffers);
    glid_init();
    sjv_looplastrect._refCount = 1;
    sjv_looplastrect.x = 0;
    sjv_looplastrect.y = 0;
    sjv_looplastrect.w = 0;
    sjv_looplastrect.h = 0;
    sjf_rect(&sjv_looplastrect);
    sjv_mouse_captureelement._parent = 0;
    sjv_boxshader._refCount = 1;
    sjv_boxshader.vertex._refCount = 1;
    sjv_boxshader.vertex.count = 20;
    sjv_boxshader.vertex.data._refCount = 1;
    sjv_boxshader.vertex.data.datasize = 21;
    sjv_boxshader.vertex.data.data = (void*)sjg_string5;
    sjv_boxshader.vertex.data._isglobal = true;
    sjv_boxshader.vertex.data.count = 21;
    sjf_array_char(&sjv_boxshader.vertex.data);
    sjf_string(&sjv_boxshader.vertex);
    sjv_boxshader.pixel._refCount = 1;
    sjv_boxshader.pixel.count = 20;
    sjv_boxshader.pixel.data._refCount = 1;
    sjv_boxshader.pixel.data.datasize = 21;
    sjv_boxshader.pixel.data.data = (void*)sjg_string6;
    sjv_boxshader.pixel.data._isglobal = true;
    sjv_boxshader.pixel.data.count = 21;
    sjf_array_char(&sjv_boxshader.pixel.data);
    sjf_string(&sjv_boxshader.pixel);
    sjf_shader(&sjv_boxshader);
    sjv_imageshader._refCount = 1;
    sjv_imageshader.vertex._refCount = 1;
    sjv_imageshader.vertex.count = 20;
    sjv_imageshader.vertex.data._refCount = 1;
    sjv_imageshader.vertex.data.datasize = 21;
    sjv_imageshader.vertex.data.data = (void*)sjg_string1;
    sjv_imageshader.vertex.data._isglobal = true;
    sjv_imageshader.vertex.data.count = 21;
    sjf_array_char(&sjv_imageshader.vertex.data);
    sjf_string(&sjv_imageshader.vertex);
    sjv_imageshader.pixel._refCount = 1;
    sjv_imageshader.pixel.count = 20;
    sjv_imageshader.pixel.data._refCount = 1;
    sjv_imageshader.pixel.data.datasize = 21;
    sjv_imageshader.pixel.data.data = (void*)sjg_string7;
    sjv_imageshader.pixel.data._isglobal = true;
    sjv_imageshader.pixel.data.count = 21;
    sjf_array_char(&sjv_imageshader.pixel.data);
    sjf_string(&sjv_imageshader.pixel);
    sjf_shader(&sjv_imageshader);
    sjv_phongcolorshader._refCount = 1;
    sjv_phongcolorshader.vertex._refCount = 1;
    sjv_phongcolorshader.vertex.count = 26;
    sjv_phongcolorshader.vertex.data._refCount = 1;
    sjv_phongcolorshader.vertex.data.datasize = 27;
    sjv_phongcolorshader.vertex.data.data = (void*)sjg_string8;
    sjv_phongcolorshader.vertex.data._isglobal = true;
    sjv_phongcolorshader.vertex.data.count = 27;
    sjf_array_char(&sjv_phongcolorshader.vertex.data);
    sjf_string(&sjv_phongcolorshader.vertex);
    sjv_phongcolorshader.pixel._refCount = 1;
    sjv_phongcolorshader.pixel.count = 26;
    sjv_phongcolorshader.pixel.data._refCount = 1;
    sjv_phongcolorshader.pixel.data.datasize = 27;
    sjv_phongcolorshader.pixel.data.data = (void*)sjg_string9;
    sjv_phongcolorshader.pixel.data._isglobal = true;
    sjv_phongcolorshader.pixel.data.count = 27;
    sjf_array_char(&sjv_phongcolorshader.pixel.data);
    sjf_string(&sjv_phongcolorshader.pixel);
    sjf_shader(&sjv_phongcolorshader);
    sjv_phongtextureshader._refCount = 1;
    sjv_phongtextureshader.vertex._refCount = 1;
    sjv_phongtextureshader.vertex.count = 30;
    sjv_phongtextureshader.vertex.data._refCount = 1;
    sjv_phongtextureshader.vertex.data.datasize = 31;
    sjv_phongtextureshader.vertex.data.data = (void*)sjg_string10;
    sjv_phongtextureshader.vertex.data._isglobal = true;
    sjv_phongtextureshader.vertex.data.count = 31;
    sjf_array_char(&sjv_phongtextureshader.vertex.data);
    sjf_string(&sjv_phongtextureshader.vertex);
    sjv_phongtextureshader.pixel._refCount = 1;
    sjv_phongtextureshader.pixel.count = 30;
    sjv_phongtextureshader.pixel.data._refCount = 1;
    sjv_phongtextureshader.pixel.data.datasize = 31;
    sjv_phongtextureshader.pixel.data.data = (void*)sjg_string11;
    sjv_phongtextureshader.pixel.data._isglobal = true;
    sjv_phongtextureshader.pixel.data.count = 31;
    sjf_array_char(&sjv_phongtextureshader.pixel.data);
    sjf_string(&sjv_phongtextureshader.pixel);
    sjf_shader(&sjv_phongtextureshader);
    sjv_textshader._refCount = 1;
    sjv_textshader.vertex._refCount = 1;
    sjv_textshader.vertex.count = 24;
    sjv_textshader.vertex.data._refCount = 1;
    sjv_textshader.vertex.data.datasize = 25;
    sjv_textshader.vertex.data.data = (void*)sjg_string12;
    sjv_textshader.vertex.data._isglobal = true;
    sjv_textshader.vertex.data.count = 25;
    sjf_array_char(&sjv_textshader.vertex.data);
    sjf_string(&sjv_textshader.vertex);
    sjv_textshader.pixel._refCount = 1;
    sjv_textshader.pixel.count = 24;
    sjv_textshader.pixel.data._refCount = 1;
    sjv_textshader.pixel.data.datasize = 25;
    sjv_textshader.pixel.data.data = (void*)sjg_string13;
    sjv_textshader.pixel.data._isglobal = true;
    sjv_textshader.pixel.data.count = 25;
    sjf_array_char(&sjv_textshader.pixel.data);
    sjf_string(&sjv_textshader.pixel);
    sjf_shader(&sjv_textshader);
    sjv_style._refCount = 1;
    sjf_anon2(&sjv_style);
    sjv_vertex_location_texture_normal_format._refCount = 1;
    sjv_vertex_location_texture_normal_format.count = 32;
    sjv_vertex_location_texture_normal_format.data._refCount = 1;
    sjv_vertex_location_texture_normal_format.data.datasize = 33;
    sjv_vertex_location_texture_normal_format.data.data = (void*)sjg_string14;
    sjv_vertex_location_texture_normal_format.data._isglobal = true;
    sjv_vertex_location_texture_normal_format.data.count = 33;
    sjf_array_char(&sjv_vertex_location_texture_normal_format.data);
    sjf_string(&sjv_vertex_location_texture_normal_format);
    sjv_saturateshader._refCount = 1;
    sjv_saturateshader.vertex._refCount = 1;
    sjv_saturateshader.vertex.count = 20;
    sjv_saturateshader.vertex.data._refCount = 1;
    sjv_saturateshader.vertex.data.datasize = 21;
    sjv_saturateshader.vertex.data.data = (void*)sjg_string1;
    sjv_saturateshader.vertex.data._isglobal = true;
    sjv_saturateshader.vertex.data.count = 21;
    sjf_array_char(&sjv_saturateshader.vertex.data);
    sjf_string(&sjv_saturateshader.vertex);
    sjv_saturateshader.pixel._refCount = 1;
    sjv_saturateshader.pixel.count = 21;
    sjv_saturateshader.pixel.data._refCount = 1;
    sjv_saturateshader.pixel.data.datasize = 22;
    sjv_saturateshader.pixel.data.data = (void*)sjg_string15;
    sjv_saturateshader.pixel.data._isglobal = true;
    sjv_saturateshader.pixel.data.count = 22;
    sjf_array_char(&sjv_saturateshader.pixel.data);
    sjf_string(&sjv_saturateshader.pixel);
    sjf_shader(&sjv_saturateshader);
    sjv_rootcontroller = (sjs_controller*)malloc(sizeof(sjs_controller));
    sjv_rootcontroller->_refCount = 1;
    sjv_rootcontroller->_button1count = 0;
    sjf_controller_heap(sjv_rootcontroller);
    sjt_call3 = (sjs_gridlayout*)malloc(sizeof(sjs_gridlayout));
    sjt_call3->_refCount = 1;
    sjt_call3->children._refCount = 1;
    sjt_call3->children.datasize = 2;
    sjt_call3->children.data = 0;
    sjt_call3->children._isglobal = false;
    sjt_call3->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call3->children);
    sjs_array_heap_iface_element* array3;
    array3 = &sjt_call3->children;
    sjt_parent28 = array3;
    sjt_functionParam39 = 0;
    sjt_call5 = (sjs_buttonelement*)malloc(sizeof(sjs_buttonelement));
    sjt_call5->_refCount = 1;
    sjt_call5->text._refCount = 1;
    sjt_call5->text.count = 7;
    sjt_call5->text.data._refCount = 1;
    sjt_call5->text.data.datasize = 8;
    sjt_call5->text.data.data = (void*)sjg_string27;
    sjt_call5->text.data._isglobal = true;
    sjt_call5->text.data.count = 8;
    sjf_array_char(&sjt_call5->text.data);
    sjf_string(&sjt_call5->text);
    sjt_copy18 = &sjv_colors_black;
    sjt_call5->textcolor._refCount = 1;
    sjf_color_copy(&sjt_call5->textcolor, sjt_copy18);
    sjt_parent51 = &sjv_style;
    sjf_anon2_getfont_heap(sjt_parent51, &sjt_call5->font);
    sjt_call5->normalimage._refCount = 1;
    sjt_call21._refCount = 1;
    sjt_call21.count = 23;
    sjt_call21.data._refCount = 1;
    sjt_call21.data.datasize = 24;
    sjt_call21.data.data = (void*)sjg_string18;
    sjt_call21.data._isglobal = true;
    sjt_call21.data.count = 24;
    sjf_array_char(&sjt_call21.data);
    sjf_string(&sjt_call21);
    sjt_functionParam107 = &sjt_call21;
    sjf_texture_frompng(sjt_functionParam107, &sjt_call5->normalimage.texture);
    sjt_call5->normalimage.rect._refCount = 1;
    sjt_call5->normalimage.rect.x = 0;
    sjt_call5->normalimage.rect.y = 0;
    sjt_call5->normalimage.rect.w = 0;
    sjt_call5->normalimage.rect.h = 0;
    sjf_rect(&sjt_call5->normalimage.rect);
    sjt_call5->normalimage.margin._refCount = 1;
    sjt_call5->normalimage.margin.l = 2;
    sjt_call5->normalimage.margin.t = 2;
    sjt_call5->normalimage.margin.r = 2;
    sjt_call5->normalimage.margin.b = 2;
    sjf_margin(&sjt_call5->normalimage.margin);
    sjf_image(&sjt_call5->normalimage);
    sjt_call5->hotimage._refCount = 1;
    sjt_call22._refCount = 1;
    sjt_call22.count = 20;
    sjt_call22.data._refCount = 1;
    sjt_call22.data.datasize = 21;
    sjt_call22.data.data = (void*)sjg_string19;
    sjt_call22.data._isglobal = true;
    sjt_call22.data.count = 21;
    sjf_array_char(&sjt_call22.data);
    sjf_string(&sjt_call22);
    sjt_functionParam108 = &sjt_call22;
    sjf_texture_frompng(sjt_functionParam108, &sjt_call5->hotimage.texture);
    sjt_call5->hotimage.rect._refCount = 1;
    sjt_call5->hotimage.rect.x = 0;
    sjt_call5->hotimage.rect.y = 0;
    sjt_call5->hotimage.rect.w = 0;
    sjt_call5->hotimage.rect.h = 0;
    sjf_rect(&sjt_call5->hotimage.rect);
    sjt_call5->hotimage.margin._refCount = 1;
    sjt_call5->hotimage.margin.l = 2;
    sjt_call5->hotimage.margin.t = 2;
    sjt_call5->hotimage.margin.r = 2;
    sjt_call5->hotimage.margin.b = 2;
    sjf_margin(&sjt_call5->hotimage.margin);
    sjf_image(&sjt_call5->hotimage);
    sjt_call5->pressedimage._refCount = 1;
    sjt_call23._refCount = 1;
    sjt_call23.count = 24;
    sjt_call23.data._refCount = 1;
    sjt_call23.data.datasize = 25;
    sjt_call23.data.data = (void*)sjg_string20;
    sjt_call23.data._isglobal = true;
    sjt_call23.data.count = 25;
    sjf_array_char(&sjt_call23.data);
    sjf_string(&sjt_call23);
    sjt_functionParam109 = &sjt_call23;
    sjf_texture_frompng(sjt_functionParam109, &sjt_call5->pressedimage.texture);
    sjt_call5->pressedimage.rect._refCount = 1;
    sjt_call5->pressedimage.rect.x = 0;
    sjt_call5->pressedimage.rect.y = 0;
    sjt_call5->pressedimage.rect.w = 0;
    sjt_call5->pressedimage.rect.h = 0;
    sjf_rect(&sjt_call5->pressedimage.rect);
    sjt_call5->pressedimage.margin._refCount = 1;
    sjt_call5->pressedimage.margin.l = 2;
    sjt_call5->pressedimage.margin.t = 2;
    sjt_call5->pressedimage.margin.r = 2;
    sjt_call5->pressedimage.margin.b = 2;
    sjf_margin(&sjt_call5->pressedimage.margin);
    sjf_image(&sjt_call5->pressedimage);
    sjt_call5->margin._refCount = 1;
    sjt_call5->margin.l = 10;
    sjt_call5->margin.t = 10;
    sjt_call5->margin.r = 10;
    sjt_call5->margin.b = 10;
    sjf_margin(&sjt_call5->margin);
    sjt_call5->onclick.inner._parent = (sjs_object*)sjv_rootcontroller;
    sjt_call5->onclick.inner._parent->_refCount++;
    sjt_call5->onclick._destroy = (void(*)(sjs_object*))sjf_controller_destroy;
    sjt_call5->onclick.inner._cb = (void(*)(sjs_object*))sjf_controller_button1clicked;
    sjt_call5->_rect._refCount = 1;
    sjt_call5->_rect.x = 0;
    sjt_call5->_rect.y = 0;
    sjt_call5->_rect.w = 0;
    sjt_call5->_rect.h = 0;
    sjf_rect(&sjt_call5->_rect);
    sjt_call5->_textrenderer._refCount = -1;
    sjt_call5->_imagerenderer._refCount = -1;
    sjt_call5->_clickgesture._refCount = 1;
    sjt_call5->_clickgesture.element._parent = 0;
    sjt_call5->_clickgesture.clickable._parent = 0;
    sjt_call5->_clickgesture.rect._refCount = 1;
    sjt_call5->_clickgesture.rect.x = 0;
    sjt_call5->_clickgesture.rect.y = 0;
    sjt_call5->_clickgesture.rect.w = 0;
    sjt_call5->_clickgesture.rect.h = 0;
    sjf_rect(&sjt_call5->_clickgesture.rect);
    sjt_call5->_clickgesture._state = sjv_clickstate_none;
    sjf_clickgesture(&sjt_call5->_clickgesture);
    sjf_buttonelement_heap(sjt_call5);
    sjt_cast3 = sjt_call5;
    sjf_buttonelement_as_sji_element(sjt_cast3, &sjt_functionParam40);
    if (sjt_functionParam40._parent != 0) {
        sjt_functionParam40._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent28, sjt_functionParam39, sjt_functionParam40);
    sjt_parent69 = array3;
    sjt_functionParam134 = 1;
    sjt_call32 = (sjs_textelement*)malloc(sizeof(sjs_textelement));
    sjt_call32->_refCount = 1;
    sjt_call32->id._refCount = 1;
    sjt_call32->id.count = 11;
    sjt_call32->id.data._refCount = 1;
    sjt_call32->id.data.datasize = 12;
    sjt_call32->id.data.data = (void*)sjg_string28;
    sjt_call32->id.data._isglobal = true;
    sjt_call32->id.data.count = 12;
    sjf_array_char(&sjt_call32->id.data);
    sjf_string(&sjt_call32->id);
    sjt_parent81 = &sjv_style;
    sjf_anon2_getfont_heap(sjt_parent81, &sjt_call32->font);
    sjt_call32->text._refCount = 1;
    sjt_call32->text.count = 3;
    sjt_call32->text.data._refCount = 1;
    sjt_call32->text.data.datasize = 4;
    sjt_call32->text.data.data = (void*)sjg_string30;
    sjt_call32->text.data._isglobal = true;
    sjt_call32->text.data.count = 4;
    sjf_array_char(&sjt_call32->text.data);
    sjf_string(&sjt_call32->text);
    sjt_copy34 = &sjv_colors_white;
    sjt_call32->color._refCount = 1;
    sjf_color_copy(&sjt_call32->color, sjt_copy34);
    sjt_call32->margin._refCount = 1;
    sjt_call32->margin.l = 0;
    sjt_call32->margin.t = 0;
    sjt_call32->margin.r = 0;
    sjt_call32->margin.b = 0;
    sjf_margin(&sjt_call32->margin);
    sjt_call32->halign = sjv_texthorizontal_left;
    sjt_call32->valign = sjv_textvertical_center;
    sjt_call32->_rect._refCount = 1;
    sjt_call32->_rect.x = 0;
    sjt_call32->_rect.y = 0;
    sjt_call32->_rect.w = 0;
    sjt_call32->_rect.h = 0;
    sjf_rect(&sjt_call32->_rect);
    sjt_call32->_textrenderer._refCount = -1;
    sjf_textelement_heap(sjt_call32);
    sjt_cast10 = sjt_call32;
    sjf_textelement_as_sji_element(sjt_cast10, &sjt_functionParam135);
    if (sjt_functionParam135._parent != 0) {
        sjt_functionParam135._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent69, sjt_functionParam134, sjt_functionParam135);
    sjt_functionParam148 = 10;
    sjf_i32_asmargin(sjt_functionParam148, &sjt_call3->margin);
    sjt_call3->cols._refCount = 1;
    sjt_call3->cols.datasize = 2;
    sjt_call3->cols.data = 0;
    sjt_call3->cols._isglobal = false;
    sjt_call3->cols.count = 0;
    sjf_array_gridunit(&sjt_call3->cols);
    sjs_array_gridunit* array1;
    array1 = &sjt_call3->cols;
    sjt_parent82 = array1;
    sjt_functionParam149 = 0;
    sjt_call35._refCount = 1;
    sjt_call35.amount = 100;
    sjt_call35.type = sjv_gridunittype_fixed;
    sjf_gridunit(&sjt_call35);
    sjt_functionParam150 = &sjt_call35;
    sjf_array_gridunit_initat(sjt_parent82, sjt_functionParam149, sjt_functionParam150);
    sjt_parent83 = array1;
    sjt_functionParam151 = 1;
    sjt_call36._refCount = 1;
    sjt_call36.amount = 1;
    sjt_call36.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call36);
    sjt_functionParam152 = &sjt_call36;
    sjf_array_gridunit_initat(sjt_parent83, sjt_functionParam151, sjt_functionParam152);
    sjt_call3->rows._refCount = 1;
    sjt_call3->rows.datasize = 4;
    sjt_call3->rows.data = 0;
    sjt_call3->rows._isglobal = false;
    sjt_call3->rows.count = 0;
    sjf_array_gridunit(&sjt_call3->rows);
    sjs_array_gridunit* array2;
    array2 = &sjt_call3->rows;
    sjt_parent84 = array2;
    sjt_functionParam153 = 0;
    sjt_call37._refCount = 1;
    sjt_call37.amount = 1;
    sjt_call37.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call37);
    sjt_functionParam154 = &sjt_call37;
    sjf_array_gridunit_initat(sjt_parent84, sjt_functionParam153, sjt_functionParam154);
    sjt_parent85 = array2;
    sjt_functionParam155 = 1;
    sjt_call38._refCount = 1;
    sjt_call38.amount = 1;
    sjt_call38.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call38);
    sjt_functionParam156 = &sjt_call38;
    sjf_array_gridunit_initat(sjt_parent85, sjt_functionParam155, sjt_functionParam156);
    sjt_parent86 = array2;
    sjt_functionParam157 = 2;
    sjt_call39._refCount = 1;
    sjt_call39.amount = 1;
    sjt_call39.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call39);
    sjt_functionParam158 = &sjt_call39;
    sjf_array_gridunit_initat(sjt_parent86, sjt_functionParam157, sjt_functionParam158);
    sjt_parent87 = array2;
    sjt_functionParam159 = 3;
    sjt_call40._refCount = 1;
    sjt_call40.amount = 1;
    sjt_call40.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call40);
    sjt_functionParam160 = &sjt_call40;
    sjf_array_gridunit_initat(sjt_parent87, sjt_functionParam159, sjt_functionParam160);
    sjt_call3->_rect._refCount = 1;
    sjt_call3->_rect.x = 0;
    sjt_call3->_rect.y = 0;
    sjt_call3->_rect.w = 0;
    sjt_call3->_rect.h = 0;
    sjf_rect(&sjt_call3->_rect);
    sjf_gridlayout_heap(sjt_call3);
    sjt_cast1 = sjt_call3;
    sjf_gridlayout_as_sji_element(sjt_cast1, &sjv_root);
    if (sjv_root._parent != 0) {
        sjv_root._parent->_refCount++;
    }

    sjf_runloop();
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjt_call3->_refCount--;
    if (sjt_call3->_refCount <= 0) {
        weakptr_release(sjt_call3);
        sjf_gridlayout_destroy(sjt_call3);
        free(sjt_call3);
    }
    sjt_call32->_refCount--;
    if (sjt_call32->_refCount <= 0) {
        weakptr_release(sjt_call32);
        sjf_textelement_destroy(sjt_call32);
        free(sjt_call32);
    }
    sjt_call5->_refCount--;
    if (sjt_call5->_refCount <= 0) {
        weakptr_release(sjt_call5);
        sjf_buttonelement_destroy(sjt_call5);
        free(sjt_call5);
    }
    if (sjt_functionParam135._parent != 0) {
        sjt_functionParam135._parent->_refCount--;
        if (sjt_functionParam135._parent->_refCount <= 0) {
            sjt_functionParam135._vtbl->destroy(sjt_functionParam135._parent);
            free(sjt_functionParam135._parent);
        }
    }
    if (sjt_functionParam40._parent != 0) {
        sjt_functionParam40._parent->_refCount--;
        if (sjt_functionParam40._parent->_refCount <= 0) {
            sjt_functionParam40._vtbl->destroy(sjt_functionParam40._parent);
            free(sjt_functionParam40._parent);
        }
    }
    if (sjv_mouse_captureelement._parent != 0) {
        sjv_mouse_captureelement._parent->_refCount--;
        if (sjv_mouse_captureelement._parent->_refCount <= 0) {
            sjv_mouse_captureelement._vtbl->destroy(sjv_mouse_captureelement._parent);
            free(sjv_mouse_captureelement._parent);
        }
    }
    if (sjv_root._parent != 0) {
        sjv_root._parent->_refCount--;
        if (sjv_root._parent->_refCount <= 0) {
            sjv_root._vtbl->destroy(sjv_root._parent);
            free(sjv_root._parent);
        }
    }
    sjv_rootcontroller->_refCount--;
    if (sjv_rootcontroller->_refCount <= 0) {
        weakptr_release(sjv_rootcontroller);
        sjf_controller_destroy(sjv_rootcontroller);
        free(sjv_rootcontroller);
    }
    if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
    if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
    if (sjt_call23._refCount == 1) { sjf_string_destroy(&sjt_call23); }
    if (sjt_call35._refCount == 1) { sjf_gridunit_destroy(&sjt_call35); }
    if (sjt_call36._refCount == 1) { sjf_gridunit_destroy(&sjt_call36); }
    if (sjt_call37._refCount == 1) { sjf_gridunit_destroy(&sjt_call37); }
    if (sjt_call38._refCount == 1) { sjf_gridunit_destroy(&sjt_call38); }
    if (sjt_call39._refCount == 1) { sjf_gridunit_destroy(&sjt_call39); }
    if (sjt_call40._refCount == 1) { sjf_gridunit_destroy(&sjt_call40); }
    if (sjv_animator._refCount == 1) { sjf_anon1_destroy(&sjv_animator); }
    if (sjv_blurhorizontalshader._refCount == 1) { sjf_shader_destroy(&sjv_blurhorizontalshader); }
    if (sjv_blurverticalshader._refCount == 1) { sjf_shader_destroy(&sjv_blurverticalshader); }
    if (sjv_boxshader._refCount == 1) { sjf_shader_destroy(&sjv_boxshader); }
    if (sjv_colors_black._refCount == 1) { sjf_color_destroy(&sjv_colors_black); }
    if (sjv_colors_blue._refCount == 1) { sjf_color_destroy(&sjv_colors_blue); }
    if (sjv_colors_gray._refCount == 1) { sjf_color_destroy(&sjv_colors_gray); }
    if (sjv_colors_green._refCount == 1) { sjf_color_destroy(&sjv_colors_green); }
    if (sjv_colors_red._refCount == 1) { sjf_color_destroy(&sjv_colors_red); }
    if (sjv_colors_white._refCount == 1) { sjf_color_destroy(&sjv_colors_white); }
    if (sjv_elementsbyid._refCount == 1) { sjf_hash_string_weak_iface_element_destroy(&sjv_elementsbyid); }
    if (sjv_fadeshader._refCount == 1) { sjf_shader_destroy(&sjv_fadeshader); }
    if (sjv_fonthash._refCount == 1) { sjf_hash_fontkey_weak_font_destroy(&sjv_fonthash); }
    if (sjv_glframebuffers._refCount == 1) { sjf_list_u32_destroy(&sjv_glframebuffers); }
    if (sjv_glviewports._refCount == 1) { sjf_list_rect_destroy(&sjv_glviewports); }
    if (sjv_imageshader._refCount == 1) { sjf_shader_destroy(&sjv_imageshader); }
    if (sjv_looplastrect._refCount == 1) { sjf_rect_destroy(&sjv_looplastrect); }
    if (sjv_modelsbyid._refCount == 1) { sjf_hash_string_weak_iface_model_destroy(&sjv_modelsbyid); }
    if (sjv_phongcolorshader._refCount == 1) { sjf_shader_destroy(&sjv_phongcolorshader); }
    if (sjv_phongtextureshader._refCount == 1) { sjf_shader_destroy(&sjv_phongtextureshader); }
    if (sjv_rootscene._refCount == 1) { sjf_scene2d_destroy(&sjv_rootscene); }
    if (sjv_rootwindowrenderer._refCount == 1) { sjf_windowrenderer_destroy(&sjv_rootwindowrenderer); }
    if (sjv_saturateshader._refCount == 1) { sjf_shader_destroy(&sjv_saturateshader); }
    if (sjv_style._refCount == 1) { sjf_anon2_destroy(&sjv_style); }
    if (sjv_textshader._refCount == 1) { sjf_shader_destroy(&sjv_textshader); }
    if (sjv_vertex_location_texture_normal_format._refCount == 1) { sjf_string_destroy(&sjv_vertex_location_texture_normal_format); }
}
