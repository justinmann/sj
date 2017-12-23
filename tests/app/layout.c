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
const char* sjg_string10 = "shaders/v3f-t2f.frag";
const char* sjg_string11 = "shaders/v3f-n3f-phong.vert";
const char* sjg_string12 = "shaders/v3f-n3f-phong.frag";
const char* sjg_string13 = "shaders/v3f-t2f-n3f-phong.vert";
const char* sjg_string14 = "shaders/v3f-t2f-n3f-phong.frag";
const char* sjg_string15 = "shaders/v3f-t2f-c4f.vert";
const char* sjg_string16 = "shaders/v3f-t2f-c4f.frag";
const char* sjg_string17 = "vertex:3f,tex_coord:2f,normal:3f";
const char* sjg_string18 = "shaders/v3f-t2f.vert";
const char* sjg_string19 = "shaders/saturate.frag";
const char* sjg_string2 = "shaders/blur-horizontal.frag";
const char* sjg_string21 = "assets/arial.ttf";
const char* sjg_string22 = "texture";
const char* sjg_string23 = "model";
const char* sjg_string24 = "view";
const char* sjg_string25 = "projection";
const char* sjg_string3 = "shaders/v3f-t2f.vert";
const char* sjg_string30 = "1";
const char* sjg_string31 = "2";
const char* sjg_string32 = "3";
const char* sjg_string33 = "4";
const char* sjg_string34 = "left";
const char* sjg_string35 = "bottom";
const char* sjg_string36 = "top";
const char* sjg_string37 = "right";
const char* sjg_string38 = "fill";
const char* sjg_string39 = "1";
const char* sjg_string4 = "shaders/blur-vertical.frag";
const char* sjg_string40 = "2";
const char* sjg_string41 = "3";
const char* sjg_string42 = "4";
const char* sjg_string43 = "1";
const char* sjg_string44 = "2";
const char* sjg_string45 = "3";
const char* sjg_string46 = "4";
const char* sjg_string47 = "1";
const char* sjg_string48 = "2";
const char* sjg_string49 = "3";
const char* sjg_string5 = "shaders/v3f-t2f.vert";
const char* sjg_string50 = "4";
const char* sjg_string51 = "1";
const char* sjg_string52 = "2";
const char* sjg_string53 = "3";
const char* sjg_string54 = "4";
const char* sjg_string55 = "1";
const char* sjg_string56 = "2";
const char* sjg_string57 = "3";
const char* sjg_string58 = "4";
const char* sjg_string59 = "1";
const char* sjg_string6 = "shaders/fade.frag";
const char* sjg_string60 = "2";
const char* sjg_string61 = "3";
const char* sjg_string62 = "4";
const char* sjg_string63 = "1";
const char* sjg_string64 = "viewport being pop'ed is wrong";
const char* sjg_string7 = "shaders/v3f-c4f.vert";
const char* sjg_string8 = "shaders/v3f-c4f.frag";
const char* sjg_string9 = "shaders/v3f-t2f.vert";

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
#define sjs_array_heap_iface_element_typeId 37
#define sjs_margin_typeId 38
#define sjs_array_gridunit_typeId 39
#define sjs_gridlayout_typeId 40
#define sjs_gridunit_typeId 41
#define sjs_array_i32_typeId 42
#define sji_gridchild_vtbl_typeId 43
#define sji_gridchild_typeId 44
#define sji_effect_vtbl_typeId 45
#define sji_effect_typeId 46
#define sjs_filllayout_typeId 47
#define cb_rect_void_typeId 48
#define cb_rect_void_heap_typeId 49
#define cb_scene2d_void_typeId 50
#define cb_scene2d_void_heap_typeId 51
#define sjs_boxrenderer_typeId 52
#define sjs_boxelement_typeId 53
#define sjs_textrenderer_typeId 54
#define sjs_textelement_typeId 55
#define sjs_borderlayout_typeId 56
#define sji_borderchild_vtbl_typeId 57
#define sji_borderchild_typeId 58
#define sjs_borderchild_typeId 59
#define sjs_listlayout_typeId 60
#define sjs_flowlayout_typeId 61
#define sjs_centerlayout_typeId 62

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
typedef struct td_sjs_array_heap_iface_element sjs_array_heap_iface_element;
typedef struct td_sjs_margin sjs_margin;
typedef struct td_sjs_array_gridunit sjs_array_gridunit;
typedef struct td_sjs_gridlayout sjs_gridlayout;
typedef struct td_sjs_gridunit sjs_gridunit;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sji_gridchild_vtbl sji_gridchild_vtbl;
typedef struct td_sji_gridchild sji_gridchild;
typedef struct td_sji_effect_vtbl sji_effect_vtbl;
typedef struct td_sji_effect sji_effect;
typedef struct td_sjs_filllayout sjs_filllayout;
typedef struct td_cb_rect_void cb_rect_void;
typedef struct td_cb_rect_void_heap cb_rect_void_heap;
typedef struct td_cb_scene2d_void cb_scene2d_void;
typedef struct td_cb_scene2d_void_heap cb_scene2d_void_heap;
typedef struct td_sjs_boxrenderer sjs_boxrenderer;
typedef struct td_sjs_boxelement sjs_boxelement;
typedef struct td_sjs_textrenderer sjs_textrenderer;
typedef struct td_sjs_textelement sjs_textelement;
typedef struct td_sjs_borderlayout sjs_borderlayout;
typedef struct td_sji_borderchild_vtbl sji_borderchild_vtbl;
typedef struct td_sji_borderchild sji_borderchild;
typedef struct td_sjs_borderchild sjs_borderchild;
typedef struct td_sjs_listlayout sjs_listlayout;
typedef struct td_sjs_flowlayout sjs_flowlayout;
typedef struct td_sjs_centerlayout sjs_centerlayout;

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

struct td_sji_effect_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getrect)(sjs_object* _parent, sjs_rect* _return);
    void (*getrect_heap)(sjs_object* _parent, sjs_rect** _return);
    void (*setrect)(sjs_object* _parent, sjs_rect* rect, cb_rect_void cb);
    void (*render)(sjs_object* _parent, sjs_scene2d* scene, cb_scene2d_void cb);
};

struct td_sji_effect {
    sjs_object* _parent;
    sji_effect_vtbl* _vtbl;
};

struct td_sjs_filllayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    sji_effect effect;
    sjs_rect _rect;
};

struct td_cb_rect_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_rect*);
};

struct td_cb_rect_void_heap {
    cb_rect_void inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_scene2d_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_scene2d*);
};

struct td_cb_scene2d_void_heap {
    cb_scene2d_void inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_boxrenderer {
    int _refCount;
    sjs_rect rect;
    sjs_color color;
    vertex_buffer_t* buffer;
};

struct td_sjs_boxelement {
    int _refCount;
    sjs_color color;
    sjs_size idealsize;
    sjs_rect rect;
    sjs_boxrenderer boxrenderer;
};

struct td_sjs_textrenderer {
    int _refCount;
    sjs_string text;
    sjs_point point;
    sjs_color color;
    sjs_font font;
    vertex_buffer_t* buffer;
};

struct td_sjs_textelement {
    int _refCount;
    sjs_font* font;
    sjs_string text;
    sjs_color color;
    sjs_margin margin;
    int32_t halign;
    int32_t valign;
    sjs_rect _rect;
    sjs_textrenderer _textrenderer;
};

struct td_sjs_borderlayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    sjs_rect _rect;
};

struct td_sji_borderchild_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getposition)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_borderchild {
    sjs_object* _parent;
    sji_borderchild_vtbl* _vtbl;
};

struct td_sjs_borderchild {
    int _refCount;
    sji_element child;
    int32_t position;
    sjs_rect _rect;
};

struct td_sjs_listlayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    int32_t orientation;
    sjs_rect _rect;
};

struct td_sjs_flowlayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    int32_t orientation;
    sjs_rect _rect;
};

struct td_sjs_centerlayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    float_option centerx;
    float_option centery;
    sjs_rect _rect;
};

sji_borderchild_vtbl sjs_borderchild_borderchild_vtbl;
sji_element_vtbl sjs_borderchild_element_vtbl;
sji_element_vtbl sjs_borderlayout_element_vtbl;
sji_element_vtbl sjs_boxelement_element_vtbl;
sji_element_vtbl sjs_centerlayout_element_vtbl;
sji_element_vtbl sjs_filllayout_element_vtbl;
sji_element_vtbl sjs_flowlayout_element_vtbl;
sji_element_vtbl sjs_gridlayout_element_vtbl;
sji_element_vtbl sjs_listlayout_element_vtbl;
sji_element_vtbl sjs_textelement_element_vtbl;
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
int32_t sjv_buttonstate_hot;
int32_t sjv_buttonstate_normal;
int32_t sjv_buttonstate_pressed;
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
sjs_string sjt_call18 = { -1 };
sjs_string sjt_call19 = { -1 };
sjs_string sjt_call20 = { -1 };
sjs_string sjt_call21 = { -1 };
sjs_gridunit sjt_call22 = { -1 };
sjs_gridunit sjt_call23 = { -1 };
sjs_gridunit sjt_call24 = { -1 };
sjs_gridunit sjt_call25 = { -1 };
sjs_borderlayout* sjt_call26 = 0;
sjs_gridlayout* sjt_call3 = 0;
sjs_borderchild* sjt_call32 = 0;
sjs_string sjt_call33 = { -1 };
sjs_borderchild* sjt_call34 = 0;
sjs_string sjt_call35 = { -1 };
sjs_borderchild* sjt_call36 = 0;
sjs_string sjt_call37 = { -1 };
sjs_borderchild* sjt_call38 = 0;
sjs_string sjt_call39 = { -1 };
sjs_borderchild* sjt_call40 = 0;
sjs_string sjt_call41 = { -1 };
sjs_listlayout* sjt_call42 = 0;
sjs_gridlayout* sjt_call5 = 0;
sjs_string sjt_call51 = { -1 };
sjs_string sjt_call52 = { -1 };
sjs_string sjt_call53 = { -1 };
sjs_string sjt_call54 = { -1 };
sjs_flowlayout* sjt_call55 = 0;
sjs_string sjt_call64 = { -1 };
sjs_string sjt_call65 = { -1 };
sjs_string sjt_call66 = { -1 };
sjs_string sjt_call67 = { -1 };
sjs_string sjt_call68 = { -1 };
sjs_string sjt_call69 = { -1 };
sjs_string sjt_call70 = { -1 };
sjs_string sjt_call71 = { -1 };
sjs_string sjt_call72 = { -1 };
sjs_string sjt_call73 = { -1 };
sjs_string sjt_call74 = { -1 };
sjs_string sjt_call75 = { -1 };
sjs_string sjt_call76 = { -1 };
sjs_string sjt_call77 = { -1 };
sjs_string sjt_call78 = { -1 };
sjs_string sjt_call79 = { -1 };
sjs_string sjt_call80 = { -1 };
sjs_string sjt_call81 = { -1 };
sjs_string sjt_call82 = { -1 };
sjs_string sjt_call83 = { -1 };
sjs_centerlayout* sjt_call84 = 0;
sjs_string sjt_call89 = { -1 };
sjs_gridunit sjt_call90 = { -1 };
sjs_gridunit sjt_call91 = { -1 };
sjs_gridunit sjt_call92 = { -1 };
sjs_gridunit sjt_call93 = { -1 };
sjs_gridunit sjt_call94 = { -1 };
sjs_gridlayout* sjt_cast1 = 0;
sjs_borderchild* sjt_cast10 = 0;
sjs_borderchild* sjt_cast11 = 0;
sjs_borderchild* sjt_cast12 = 0;
sjs_borderchild* sjt_cast13 = 0;
sjs_borderchild* sjt_cast14 = 0;
sjs_listlayout* sjt_cast15 = 0;
sjs_flowlayout* sjt_cast16 = 0;
sjs_centerlayout* sjt_cast17 = 0;
sjs_gridlayout* sjt_cast3 = 0;
sjs_borderlayout* sjt_cast7 = 0;
int32_t sjt_functionParam100;
sji_element sjt_functionParam101 = { 0 };
sjs_string* sjt_functionParam102 = 0;
int32_t sjt_functionParam103;
sji_element sjt_functionParam104 = { 0 };
sjs_string* sjt_functionParam105 = 0;
int32_t sjt_functionParam106;
sji_element sjt_functionParam107 = { 0 };
sjs_string* sjt_functionParam108 = 0;
int32_t sjt_functionParam109;
sjs_gridunit* sjt_functionParam110 = 0;
int32_t sjt_functionParam111;
sjs_gridunit* sjt_functionParam112 = 0;
int32_t sjt_functionParam113;
sjs_gridunit* sjt_functionParam114 = 0;
int32_t sjt_functionParam115;
sjs_gridunit* sjt_functionParam116 = 0;
int32_t sjt_functionParam117;
sji_element sjt_functionParam118 = { 0 };
int32_t sjt_functionParam124;
sji_element sjt_functionParam125 = { 0 };
sjs_string* sjt_functionParam126 = 0;
int32_t sjt_functionParam127;
sji_element sjt_functionParam128 = { 0 };
sjs_string* sjt_functionParam129 = 0;
int32_t sjt_functionParam130;
sji_element sjt_functionParam131 = { 0 };
sjs_string* sjt_functionParam132 = 0;
int32_t sjt_functionParam133;
sji_element sjt_functionParam134 = { 0 };
sjs_string* sjt_functionParam135 = 0;
int32_t sjt_functionParam136;
sji_element sjt_functionParam137 = { 0 };
sjs_string* sjt_functionParam138 = 0;
int32_t sjt_functionParam139;
sji_element sjt_functionParam140 = { 0 };
int32_t sjt_functionParam145;
sji_element sjt_functionParam146 = { 0 };
sjs_string* sjt_functionParam147 = 0;
int32_t sjt_functionParam148;
sji_element sjt_functionParam149 = { 0 };
sjs_string* sjt_functionParam150 = 0;
int32_t sjt_functionParam151;
sji_element sjt_functionParam152 = { 0 };
sjs_string* sjt_functionParam153 = 0;
int32_t sjt_functionParam154;
sji_element sjt_functionParam155 = { 0 };
sjs_string* sjt_functionParam156 = 0;
int32_t sjt_functionParam157;
sji_element sjt_functionParam158 = { 0 };
int32_t sjt_functionParam171;
sji_element sjt_functionParam172 = { 0 };
sjs_string* sjt_functionParam173 = 0;
int32_t sjt_functionParam174;
sji_element sjt_functionParam175 = { 0 };
sjs_string* sjt_functionParam176 = 0;
int32_t sjt_functionParam177;
sji_element sjt_functionParam178 = { 0 };
sjs_string* sjt_functionParam179 = 0;
int32_t sjt_functionParam180;
sji_element sjt_functionParam181 = { 0 };
sjs_string* sjt_functionParam182 = 0;
int32_t sjt_functionParam183;
sji_element sjt_functionParam184 = { 0 };
sjs_string* sjt_functionParam185 = 0;
int32_t sjt_functionParam186;
sji_element sjt_functionParam187 = { 0 };
sjs_string* sjt_functionParam188 = 0;
int32_t sjt_functionParam189;
sji_element sjt_functionParam190 = { 0 };
sjs_string* sjt_functionParam191 = 0;
int32_t sjt_functionParam192;
sji_element sjt_functionParam193 = { 0 };
sjs_string* sjt_functionParam194 = 0;
int32_t sjt_functionParam195;
sji_element sjt_functionParam196 = { 0 };
sjs_string* sjt_functionParam197 = 0;
int32_t sjt_functionParam198;
sji_element sjt_functionParam199 = { 0 };
sjs_string* sjt_functionParam200 = 0;
int32_t sjt_functionParam201;
sji_element sjt_functionParam202 = { 0 };
sjs_string* sjt_functionParam203 = 0;
int32_t sjt_functionParam204;
sji_element sjt_functionParam205 = { 0 };
sjs_string* sjt_functionParam206 = 0;
int32_t sjt_functionParam207;
sji_element sjt_functionParam208 = { 0 };
sjs_string* sjt_functionParam209 = 0;
int32_t sjt_functionParam210;
sji_element sjt_functionParam211 = { 0 };
sjs_string* sjt_functionParam212 = 0;
int32_t sjt_functionParam213;
sji_element sjt_functionParam214 = { 0 };
sjs_string* sjt_functionParam215 = 0;
int32_t sjt_functionParam216;
sji_element sjt_functionParam217 = { 0 };
sjs_string* sjt_functionParam218 = 0;
int32_t sjt_functionParam219;
sji_element sjt_functionParam220 = { 0 };
sjs_string* sjt_functionParam221 = 0;
int32_t sjt_functionParam222;
sji_element sjt_functionParam223 = { 0 };
sjs_string* sjt_functionParam224 = 0;
int32_t sjt_functionParam225;
sji_element sjt_functionParam226 = { 0 };
sjs_string* sjt_functionParam227 = 0;
int32_t sjt_functionParam228;
sji_element sjt_functionParam229 = { 0 };
sjs_string* sjt_functionParam230 = 0;
int32_t sjt_functionParam231;
sji_element sjt_functionParam232 = { 0 };
int32_t sjt_functionParam245;
sji_element sjt_functionParam246 = { 0 };
sjs_string* sjt_functionParam247 = 0;
int32_t sjt_functionParam248;
sjs_gridunit* sjt_functionParam249 = 0;
int32_t sjt_functionParam250;
sjs_gridunit* sjt_functionParam251 = 0;
int32_t sjt_functionParam252;
sjs_gridunit* sjt_functionParam253 = 0;
int32_t sjt_functionParam254;
sjs_gridunit* sjt_functionParam255 = 0;
int32_t sjt_functionParam256;
sjs_gridunit* sjt_functionParam257 = 0;
int32_t sjt_functionParam39;
sji_element sjt_functionParam40 = { 0 };
int32_t sjt_functionParam41;
sji_element sjt_functionParam42 = { 0 };
sjs_string* sjt_functionParam99 = 0;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_array_heap_iface_element* sjt_parent100 = 0;
sjs_array_heap_iface_element* sjt_parent101 = 0;
sjs_array_heap_iface_element* sjt_parent115 = 0;
sjs_array_heap_iface_element* sjt_parent116 = 0;
sjs_array_heap_iface_element* sjt_parent117 = 0;
sjs_array_heap_iface_element* sjt_parent118 = 0;
sjs_array_heap_iface_element* sjt_parent119 = 0;
sjs_array_heap_iface_element* sjt_parent133 = 0;
sjs_array_heap_iface_element* sjt_parent134 = 0;
sjs_array_heap_iface_element* sjt_parent135 = 0;
sjs_array_heap_iface_element* sjt_parent136 = 0;
sjs_array_heap_iface_element* sjt_parent137 = 0;
sjs_array_heap_iface_element* sjt_parent138 = 0;
sjs_array_heap_iface_element* sjt_parent139 = 0;
sjs_array_heap_iface_element* sjt_parent140 = 0;
sjs_array_heap_iface_element* sjt_parent141 = 0;
sjs_array_heap_iface_element* sjt_parent142 = 0;
sjs_array_heap_iface_element* sjt_parent143 = 0;
sjs_array_heap_iface_element* sjt_parent144 = 0;
sjs_array_heap_iface_element* sjt_parent145 = 0;
sjs_array_heap_iface_element* sjt_parent146 = 0;
sjs_array_heap_iface_element* sjt_parent147 = 0;
sjs_array_heap_iface_element* sjt_parent148 = 0;
sjs_array_heap_iface_element* sjt_parent149 = 0;
sjs_array_heap_iface_element* sjt_parent150 = 0;
sjs_array_heap_iface_element* sjt_parent151 = 0;
sjs_array_heap_iface_element* sjt_parent152 = 0;
sjs_array_heap_iface_element* sjt_parent153 = 0;
sjs_array_heap_iface_element* sjt_parent171 = 0;
sjs_array_gridunit* sjt_parent172 = 0;
sjs_array_gridunit* sjt_parent173 = 0;
sjs_array_gridunit* sjt_parent174 = 0;
sjs_array_gridunit* sjt_parent175 = 0;
sjs_array_gridunit* sjt_parent176 = 0;
sjs_array_heap_iface_element* sjt_parent28 = 0;
sjs_array_heap_iface_element* sjt_parent29 = 0;
sjs_array_heap_iface_element* sjt_parent67 = 0;
sjs_array_heap_iface_element* sjt_parent68 = 0;
sjs_array_heap_iface_element* sjt_parent69 = 0;
sjs_array_gridunit* sjt_parent70 = 0;
sjs_array_gridunit* sjt_parent71 = 0;
sjs_array_gridunit* sjt_parent72 = 0;
sjs_array_gridunit* sjt_parent73 = 0;
sjs_array_heap_iface_element* sjt_parent74 = 0;
sjs_array_heap_iface_element* sjt_parent91 = 0;
sjs_array_heap_iface_element* sjt_parent97 = 0;
sjs_array_heap_iface_element* sjt_parent98 = 0;
sjs_array_heap_iface_element* sjt_parent99 = 0;
float sjt_value5;
float sjt_value6;
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
sjs_scene2d sjv_rootscene = { -1 };
sjs_windowrenderer sjv_rootwindowrenderer = { -1 };
sjs_shader sjv_saturateshader = { -1 };
sjs_anon2 sjv_style = { -1 };
sjs_shader sjv_textshader = { -1 };
uint32_t sjv_u32_maxvalue;
sjs_string sjv_vertex_location_texture_normal_format = { -1 };
float_option value5;
float_option value6;

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
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
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
void sjf_borderchild(sjs_borderchild* _this);
void sjf_borderchild_as_sji_borderchild(sjs_borderchild* _this, sji_borderchild* _return);
void sjf_borderchild_as_sji_element(sjs_borderchild* _this, sji_element* _return);
void sjf_borderchild_asinterface(sjs_borderchild* _this, int typeId, sjs_interface* _return);
void sjf_borderchild_copy(sjs_borderchild* _this, sjs_borderchild* _from);
void sjf_borderchild_destroy(sjs_borderchild* _this);
void sjf_borderchild_firemouseevent(sjs_borderchild* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_borderchild_getposition(sjs_borderchild* _parent, int32_t* _return);
void sjf_borderchild_getrect(sjs_borderchild* _parent, sjs_rect* _return);
void sjf_borderchild_getrect_heap(sjs_borderchild* _parent, sjs_rect** _return);
void sjf_borderchild_getsize(sjs_borderchild* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_borderchild_getsize_heap(sjs_borderchild* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_borderchild_heap(sjs_borderchild* _this);
void sjf_borderchild_render(sjs_borderchild* _parent, sjs_scene2d* scene);
void sjf_borderchild_setrect(sjs_borderchild* _parent, sjs_rect* rect_);
void sjf_borderlayout(sjs_borderlayout* _this);
void sjf_borderlayout_as_sji_element(sjs_borderlayout* _this, sji_element* _return);
void sjf_borderlayout_asinterface(sjs_borderlayout* _this, int typeId, sjs_interface* _return);
void sjf_borderlayout_copy(sjs_borderlayout* _this, sjs_borderlayout* _from);
void sjf_borderlayout_destroy(sjs_borderlayout* _this);
void sjf_borderlayout_firemouseevent(sjs_borderlayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_borderlayout_getrect(sjs_borderlayout* _parent, sjs_rect* _return);
void sjf_borderlayout_getrect_heap(sjs_borderlayout* _parent, sjs_rect** _return);
void sjf_borderlayout_getsize(sjs_borderlayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_borderlayout_getsize_heap(sjs_borderlayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_borderlayout_heap(sjs_borderlayout* _this);
void sjf_borderlayout_render(sjs_borderlayout* _parent, sjs_scene2d* scene);
void sjf_borderlayout_setrect(sjs_borderlayout* _parent, sjs_rect* rect_);
void sjf_boxelement(sjs_boxelement* _this);
void sjf_boxelement_as_sji_element(sjs_boxelement* _this, sji_element* _return);
void sjf_boxelement_asinterface(sjs_boxelement* _this, int typeId, sjs_interface* _return);
void sjf_boxelement_copy(sjs_boxelement* _this, sjs_boxelement* _from);
void sjf_boxelement_destroy(sjs_boxelement* _this);
void sjf_boxelement_firemouseevent(sjs_boxelement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_boxelement_getrect(sjs_boxelement* _parent, sjs_rect* _return);
void sjf_boxelement_getrect_heap(sjs_boxelement* _parent, sjs_rect** _return);
void sjf_boxelement_getsize(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_boxelement_getsize_heap(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_boxelement_heap(sjs_boxelement* _this);
void sjf_boxelement_render(sjs_boxelement* _parent, sjs_scene2d* scene);
void sjf_boxelement_setrect(sjs_boxelement* _parent, sjs_rect* rect_);
void sjf_boxrenderer(sjs_boxrenderer* _this);
void sjf_boxrenderer_copy(sjs_boxrenderer* _this, sjs_boxrenderer* _from);
void sjf_boxrenderer_destroy(sjs_boxrenderer* _this);
void sjf_boxrenderer_heap(sjs_boxrenderer* _this);
void sjf_boxrenderer_render(sjs_boxrenderer* _parent, sjs_scene2d* scene);
void sjf_centerlayout(sjs_centerlayout* _this);
void sjf_centerlayout_as_sji_element(sjs_centerlayout* _this, sji_element* _return);
void sjf_centerlayout_asinterface(sjs_centerlayout* _this, int typeId, sjs_interface* _return);
void sjf_centerlayout_copy(sjs_centerlayout* _this, sjs_centerlayout* _from);
void sjf_centerlayout_destroy(sjs_centerlayout* _this);
void sjf_centerlayout_firemouseevent(sjs_centerlayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_centerlayout_getrect(sjs_centerlayout* _parent, sjs_rect* _return);
void sjf_centerlayout_getrect_heap(sjs_centerlayout* _parent, sjs_rect** _return);
void sjf_centerlayout_getsize(sjs_centerlayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_centerlayout_getsize_heap(sjs_centerlayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_centerlayout_heap(sjs_centerlayout* _this);
void sjf_centerlayout_render(sjs_centerlayout* _parent, sjs_scene2d* scene);
void sjf_centerlayout_setrect(sjs_centerlayout* _parent, sjs_rect* rect_);
void sjf_color(sjs_color* _this);
void sjf_color_copy(sjs_color* _this, sjs_color* _from);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color* _this);
void sjf_f32_hash(float val, uint32_t* _return);
void sjf_f32_random(float* _return);
void sjf_filllayout(sjs_filllayout* _this);
void sjf_filllayout_as_sji_element(sjs_filllayout* _this, sji_element* _return);
void sjf_filllayout_asinterface(sjs_filllayout* _this, int typeId, sjs_interface* _return);
void sjf_filllayout_copy(sjs_filllayout* _this, sjs_filllayout* _from);
void sjf_filllayout_destroy(sjs_filllayout* _this);
void sjf_filllayout_firemouseevent(sjs_filllayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_filllayout_getrect(sjs_filllayout* _parent, sjs_rect* _return);
void sjf_filllayout_getrect_heap(sjs_filllayout* _parent, sjs_rect** _return);
void sjf_filllayout_getsize(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_filllayout_getsize_heap(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_filllayout_heap(sjs_filllayout* _this);
void sjf_filllayout_render(sjs_filllayout* _parent, sjs_scene2d* scene);
void sjf_filllayout_renderinner(sjs_filllayout* _parent, sjs_scene2d* scene);
void sjf_filllayout_setrect(sjs_filllayout* _parent, sjs_rect* rect_);
void sjf_filllayout_setrectinner(sjs_filllayout* _parent, sjs_rect* innerrect);
void sjf_flowlayout(sjs_flowlayout* _this);
void sjf_flowlayout_as_sji_element(sjs_flowlayout* _this, sji_element* _return);
void sjf_flowlayout_asinterface(sjs_flowlayout* _this, int typeId, sjs_interface* _return);
void sjf_flowlayout_copy(sjs_flowlayout* _this, sjs_flowlayout* _from);
void sjf_flowlayout_destroy(sjs_flowlayout* _this);
void sjf_flowlayout_firemouseevent(sjs_flowlayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_flowlayout_getrect(sjs_flowlayout* _parent, sjs_rect* _return);
void sjf_flowlayout_getrect_heap(sjs_flowlayout* _parent, sjs_rect** _return);
void sjf_flowlayout_getsize(sjs_flowlayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_flowlayout_getsize_heap(sjs_flowlayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_flowlayout_heap(sjs_flowlayout* _this);
void sjf_flowlayout_render(sjs_flowlayout* _parent, sjs_scene2d* scene);
void sjf_flowlayout_setrect(sjs_flowlayout* _parent, sjs_rect* rect_);
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
void sjf_hash_string_weak_iface_element_heap(sjs_hash_string_weak_iface_element* _this);
void sjf_hash_string_weak_iface_model(sjs_hash_string_weak_iface_model* _this);
void sjf_hash_string_weak_iface_model__weakptrremovekey(sjs_hash_string_weak_iface_model* _parent, sjs_string* key);
void sjf_hash_string_weak_iface_model__weakptrremovevalue(sjs_hash_string_weak_iface_model* _parent, sji_model val);
void sjf_hash_string_weak_iface_model_copy(sjs_hash_string_weak_iface_model* _this, sjs_hash_string_weak_iface_model* _from);
void sjf_hash_string_weak_iface_model_destroy(sjs_hash_string_weak_iface_model* _this);
void sjf_hash_string_weak_iface_model_heap(sjs_hash_string_weak_iface_model* _this);
void sjf_i32_max(int32_t a, int32_t b, int32_t* _return);
void sjf_i32_random(int32_t* _return);
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
void sjf_listlayout(sjs_listlayout* _this);
void sjf_listlayout_as_sji_element(sjs_listlayout* _this, sji_element* _return);
void sjf_listlayout_asinterface(sjs_listlayout* _this, int typeId, sjs_interface* _return);
void sjf_listlayout_copy(sjs_listlayout* _this, sjs_listlayout* _from);
void sjf_listlayout_destroy(sjs_listlayout* _this);
void sjf_listlayout_firemouseevent(sjs_listlayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_listlayout_getrect(sjs_listlayout* _parent, sjs_rect* _return);
void sjf_listlayout_getrect_heap(sjs_listlayout* _parent, sjs_rect** _return);
void sjf_listlayout_getsize(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_listlayout_getsize_heap(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_listlayout_heap(sjs_listlayout* _this);
void sjf_listlayout_render(sjs_listlayout* _parent, sjs_scene2d* scene);
void sjf_listlayout_setrect(sjs_listlayout* _parent, sjs_rect* rect_);
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
void sjf_size_max(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_size_max_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_size_min(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_size_min_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_size_subtractmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return);
void sjf_size_subtractmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_hash(sjs_string* _parent, uint32_t* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return);
void sjf_testelement_heap(sjs_string* text, sji_element* _return);
void sjf_textelement(sjs_textelement* _this);
void sjf_textelement_as_sji_element(sjs_textelement* _this, sji_element* _return);
void sjf_textelement_asinterface(sjs_textelement* _this, int typeId, sjs_interface* _return);
void sjf_textelement_copy(sjs_textelement* _this, sjs_textelement* _from);
void sjf_textelement_destroy(sjs_textelement* _this);
void sjf_textelement_firemouseevent(sjs_textelement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_textelement_getrect(sjs_textelement* _parent, sjs_rect* _return);
void sjf_textelement_getrect_heap(sjs_textelement* _parent, sjs_rect** _return);
void sjf_textelement_getsize(sjs_textelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_textelement_getsize_heap(sjs_textelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_textelement_heap(sjs_textelement* _this);
void sjf_textelement_render(sjs_textelement* _parent, sjs_scene2d* scene);
void sjf_textelement_setrect(sjs_textelement* _parent, sjs_rect* rect_);
void sjf_textrenderer(sjs_textrenderer* _this);
void sjf_textrenderer_copy(sjs_textrenderer* _this, sjs_textrenderer* _from);
void sjf_textrenderer_destroy(sjs_textrenderer* _this);
void sjf_textrenderer_heap(sjs_textrenderer* _this);
void sjf_textrenderer_render(sjs_textrenderer* _parent, sjs_scene2d* scene);
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
    int32_t sjt_compare97;
    int32_t sjt_compare98;
    sjs_anon1* sjt_dot449 = 0;
    sjs_anon1* sjt_dot452 = 0;
    bool sjt_ifElse43;
    sjs_list_heap_iface_animation* sjt_parent177 = 0;

    sjt_dot449 = _parent;
    sjt_dot449->current = time;
    sjt_dot452 = _parent;
    sjt_parent177 = &(sjt_dot452)->animations;
    sjf_list_heap_iface_animation_getcount(sjt_parent177, &sjt_compare97);
    sjt_compare98 = 0;
    sjt_ifElse43 = sjt_compare97 > sjt_compare98;
    if (sjt_ifElse43) {
        int32_t i;
        sjs_anon1* sjt_dot453 = 0;
        int32_t sjt_forEnd23;
        int32_t sjt_forStart23;
        sjs_list_heap_iface_animation* sjt_parent178 = 0;

        sjt_forStart23 = 0;
        sjt_dot453 = _parent;
        sjt_parent178 = &(sjt_dot453)->animations;
        sjf_list_heap_iface_animation_getcount(sjt_parent178, &sjt_forEnd23);
        i = sjt_forEnd23 - 1;
        while (i >= sjt_forStart23) {
            sjs_anon1* sjt_dot455 = 0;
            int32_t sjt_functionParam259;
            bool sjt_ifElse44;
            int32_t sjt_interfaceParam47;
            sjs_list_heap_iface_animation* sjt_parent180 = 0;
            sji_animation sjt_parent181 = { 0 };
            sji_animation sjv_a = { 0 };

            sjt_dot455 = _parent;
            sjt_parent180 = &(sjt_dot455)->animations;
            sjt_functionParam259 = i;
            sjf_list_heap_iface_animation_getat_heap(sjt_parent180, sjt_functionParam259, &sjv_a);
            sjt_parent181 = sjv_a;
            sjt_interfaceParam47 = time;
            sjt_parent181._vtbl->nextframe(sjt_parent181._parent, sjt_interfaceParam47, &sjt_ifElse44);
            if (sjt_ifElse44) {
                sjs_anon1* sjt_dot456 = 0;
                int32_t sjt_functionParam260;
                sjs_list_heap_iface_animation* sjt_parent182 = 0;

                sjt_dot456 = _parent;
                sjt_parent182 = &(sjt_dot456)->animations;
                sjt_functionParam260 = i;
                sjf_list_heap_iface_animation_removeat(sjt_parent182, sjt_functionParam260);
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
    sjs_string sjt_call17 = { -1 };
    sjs_string* sjt_functionParam97 = 0;
    float sjt_functionParam98;

    sjt_call17._refCount = 1;
    sjt_call17.count = 16;
    sjt_call17.data._refCount = 1;
    sjt_call17.data.datasize = 17;
    sjt_call17.data.data = (void*)sjg_string21;
    sjt_call17.data._isglobal = true;
    sjt_call17.data.count = 17;
    sjf_array_char(&sjt_call17.data);
    sjf_string(&sjt_call17);
    sjt_functionParam97 = &sjt_call17;
    sjt_functionParam98 = 24.0f;
    sjf_font_load_heap(sjt_functionParam97, sjt_functionParam98, _return);

    if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
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

void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
    if (_parent->count != test->count) {
        *_return = false;
    }
    bool result = memcmp(_parent->data, test->data, _parent->count * sizeof(char)) == 0;
    (*_return) = result;
return;;		
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
    sjs_array_rect* sjt_dot486 = 0;
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
    sjt_dot486 = _parent;
    _return->count = (sjt_dot486)->count;
    sjf_array_rect(_return);
}

void sjf_array_rect_grow_heap(sjs_array_rect* _parent, int32_t newsize, sjs_array_rect** _return) {
    sjs_array_rect* sjt_dot487 = 0;
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
    sjt_dot487 = _parent;
    (*_return)->count = (sjt_dot487)->count;
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

void sjf_borderchild(sjs_borderchild* _this) {
}

void sjf_borderchild_as_sji_borderchild(sjs_borderchild* _this, sji_borderchild* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_borderchild_borderchild_vtbl;
}

void sjf_borderchild_as_sji_element(sjs_borderchild* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_borderchild_element_vtbl;
}

void sjf_borderchild_asinterface(sjs_borderchild* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_borderchild_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        case sji_borderchild_typeId:  {
            sjf_borderchild_as_sji_borderchild(_this, (sji_borderchild*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_borderchild_copy(sjs_borderchild* _this, sjs_borderchild* _from) {
    _this->child = _from->child;
    if (_this->child._parent != 0) {
        _this->child._parent->_refCount++;
    }

    _this->position = _from->position;
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_borderchild_destroy(sjs_borderchild* _this) {
    if (_this->child._parent != 0) {
        _this->child._parent->_refCount--;
        if (_this->child._parent->_refCount <= 0) {
            _this->child._vtbl->destroy(_this->child._parent);
            free(_this->child._parent);
        }
    }
}

void sjf_borderchild_firemouseevent(sjs_borderchild* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_borderchild* sjt_dot299 = 0;
    sjs_mouseevent* sjt_interfaceParam23 = 0;
    sji_element sjt_parent96 = { 0 };

    sjt_dot299 = _parent;
    sjt_parent96 = (sjt_dot299)->child;
    sjt_interfaceParam23 = mouseevent;
    sjt_parent96._vtbl->firemouseevent(sjt_parent96._parent, sjt_interfaceParam23, _return);
}

void sjf_borderchild_getposition(sjs_borderchild* _parent, int32_t* _return) {
    sjs_borderchild* sjt_dot300 = 0;

    sjt_dot300 = _parent;
    (*_return) = (sjt_dot300)->position;
}

void sjf_borderchild_getrect(sjs_borderchild* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy25 = 0;
    sjs_borderchild* sjt_dot293 = 0;

    sjt_dot293 = _parent;
    sjt_copy25 = &(sjt_dot293)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy25);
}

void sjf_borderchild_getrect_heap(sjs_borderchild* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy26 = 0;
    sjs_borderchild* sjt_dot294 = 0;

    sjt_dot294 = _parent;
    sjt_copy26 = &(sjt_dot294)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy26);
}

void sjf_borderchild_getsize(sjs_borderchild* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_borderchild* sjt_dot291 = 0;
    sjs_size* sjt_interfaceParam19 = 0;
    sji_element sjt_parent92 = { 0 };

    sjt_dot291 = _parent;
    sjt_parent92 = (sjt_dot291)->child;
    sjt_interfaceParam19 = maxsize;
    _return->_refCount = 1;
    sjt_parent92._vtbl->getsize(sjt_parent92._parent, sjt_interfaceParam19, _return);
}

void sjf_borderchild_getsize_heap(sjs_borderchild* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_borderchild* sjt_dot292 = 0;
    sjs_size* sjt_interfaceParam20 = 0;
    sji_element sjt_parent93 = { 0 };

    sjt_dot292 = _parent;
    sjt_parent93 = (sjt_dot292)->child;
    sjt_interfaceParam20 = maxsize;
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_parent93._vtbl->getsize_heap(sjt_parent93._parent, sjt_interfaceParam20, _return);
}

void sjf_borderchild_heap(sjs_borderchild* _this) {
}

void sjf_borderchild_render(sjs_borderchild* _parent, sjs_scene2d* scene) {
    sjs_borderchild* sjt_dot298 = 0;
    sjs_scene2d* sjt_interfaceParam22 = 0;
    sji_element sjt_parent95 = { 0 };

    sjt_dot298 = _parent;
    sjt_parent95 = (sjt_dot298)->child;
    sjt_interfaceParam22 = scene;
    sjt_parent95._vtbl->render(sjt_parent95._parent, sjt_interfaceParam22);
}

void sjf_borderchild_setrect(sjs_borderchild* _parent, sjs_rect* rect_) {
    sjs_rect* sjt_copy27 = 0;
    sjs_borderchild* sjt_dot295 = 0;
    sjs_borderchild* sjt_dot296 = 0;
    sjs_borderchild* sjt_dot297 = 0;
    sjs_rect* sjt_interfaceParam21 = 0;
    sji_element sjt_parent94 = { 0 };

    sjt_dot295 = _parent;
    sjt_copy27 = rect_;
    sjt_dot295->_rect._refCount = 1;
    sjf_rect_copy(&sjt_dot295->_rect, sjt_copy27);
    sjt_dot296 = _parent;
    sjt_parent94 = (sjt_dot296)->child;
    sjt_dot297 = _parent;
    sjt_interfaceParam21 = &(sjt_dot297)->_rect;
    sjt_parent94._vtbl->setrect(sjt_parent94._parent, sjt_interfaceParam21);
}

void sjf_borderlayout(sjs_borderlayout* _this) {
}

void sjf_borderlayout_as_sji_element(sjs_borderlayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_borderlayout_element_vtbl;
}

void sjf_borderlayout_asinterface(sjs_borderlayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_borderlayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_borderlayout_copy(sjs_borderlayout* _this, sjs_borderlayout* _from) {
    _this->children._refCount = 1;
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
    _this->margin._refCount = 1;
    sjf_margin_copy(&_this->margin, &_from->margin);
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_borderlayout_destroy(sjs_borderlayout* _this) {
}

void sjf_borderlayout_firemouseevent(sjs_borderlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_borderlayout* sjt_dot290 = 0;
    sjs_array_heap_iface_element* sjt_functionParam123 = 0;
    sjs_mouseevent* sjt_parent90 = 0;

    sjt_parent90 = mouseevent;
    sjt_dot290 = _parent;
    sjt_functionParam123 = &(sjt_dot290)->children;
    sjf_mouseevent_firechildren(sjt_parent90, sjt_functionParam123, _return);
}

void sjf_borderlayout_getrect(sjs_borderlayout* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy22 = 0;
    sjs_borderlayout* sjt_dot233 = 0;

    sjt_dot233 = _parent;
    sjt_copy22 = &(sjt_dot233)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy22);
}

void sjf_borderlayout_getrect_heap(sjs_borderlayout* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy23 = 0;
    sjs_borderlayout* sjt_dot234 = 0;

    sjt_dot234 = _parent;
    sjt_copy23 = &(sjt_dot234)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy23);
}

void sjf_borderlayout_getsize(sjs_borderlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot229 = 0;
    sjs_size* sjt_dot230 = 0;

    _return->_refCount = 1;
    sjt_dot229 = maxsize;
    _return->w = (sjt_dot229)->w;
    sjt_dot230 = maxsize;
    _return->h = (sjt_dot230)->h;
    sjf_size(_return);
}

void sjf_borderlayout_getsize_heap(sjs_borderlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot231 = 0;
    sjs_size* sjt_dot232 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot231 = maxsize;
    (*_return)->w = (sjt_dot231)->w;
    sjt_dot232 = maxsize;
    (*_return)->h = (sjt_dot232)->h;
    sjf_size_heap((*_return));
}

void sjf_borderlayout_heap(sjs_borderlayout* _this) {
}

void sjf_borderlayout_render(sjs_borderlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot287 = 0;
    sjs_borderlayout* sjt_dot288 = 0;
    int32_t sjt_forEnd14;
    int32_t sjt_forStart14;

    sjt_forStart14 = 0;
    sjt_dot288 = _parent;
    sjt_dot287 = &(sjt_dot288)->children;
    sjt_forEnd14 = (sjt_dot287)->count;
    i = sjt_forStart14;
    while (i < sjt_forEnd14) {
        sjs_borderlayout* sjt_dot289 = 0;
        int32_t sjt_functionParam122;
        sjs_scene2d* sjt_interfaceParam18 = 0;
        sjs_array_heap_iface_element* sjt_parent88 = 0;
        sji_element sjt_parent89 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot289 = _parent;
        sjt_parent88 = &(sjt_dot289)->children;
        sjt_functionParam122 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent88, sjt_functionParam122, &sjv_child);
        sjt_parent89 = sjv_child;
        sjt_interfaceParam18 = scene;
        sjt_parent89._vtbl->render(sjt_parent89._parent, sjt_interfaceParam18);
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

void sjf_borderlayout_setrect(sjs_borderlayout* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_rect* sjt_copy24 = 0;
    sjs_borderlayout* sjt_dot235 = 0;
    sjs_borderlayout* sjt_dot236 = 0;
    sjs_array_heap_iface_element* sjt_dot237 = 0;
    sjs_borderlayout* sjt_dot238 = 0;
    sjs_array_heap_iface_element* sjt_dot284 = 0;
    sjs_borderlayout* sjt_dot285 = 0;
    int32_t sjt_forEnd12;
    int32_t sjt_forEnd13;
    int32_t sjt_forStart12;
    int32_t sjt_forStart13;
    sjs_margin* sjt_functionParam119 = 0;
    sjs_rect* sjt_parent75 = 0;
    sjs_rect sjv_remaining = { -1 };

    sjt_dot235 = _parent;
    sjt_copy24 = rect_;
    sjt_dot235->_rect._refCount = 1;
    sjf_rect_copy(&sjt_dot235->_rect, sjt_copy24);
    sjt_parent75 = rect_;
    sjt_dot236 = _parent;
    sjt_functionParam119 = &(sjt_dot236)->margin;
    sjf_rect_subtractmargin(sjt_parent75, sjt_functionParam119, &sjv_remaining);
    sjt_forStart12 = 0;
    sjt_dot238 = _parent;
    sjt_dot237 = &(sjt_dot238)->children;
    sjt_forEnd12 = (sjt_dot237)->count;
    i = sjt_forStart12;
    while (i < sjt_forEnd12) {
        sjs_size sjt_call27 = { -1 };
        sjs_rect sjt_call28 = { -1 };
        sjs_rect sjt_call29 = { -1 };
        sjs_rect sjt_call30 = { -1 };
        sjs_rect sjt_call31 = { -1 };
        sji_element sjt_cast8 = { 0 };
        int32_t sjt_compare61;
        int32_t sjt_compare62;
        sjs_borderlayout* sjt_dot239 = 0;
        int32_t sjt_functionParam120;
        bool sjt_ifElse27;
        bool sjt_ifElse28;
        bool sjt_ifElse30;
        int32_option sjt_isEmpty13;
        sji_borderchild sjt_isEmpty14 = { 0 };
        sjs_array_heap_iface_element* sjt_parent76 = 0;
        sji_borderchild sjv_borderchild = { 0 };
        sji_element sjv_child = { 0 };
        sjs_size sjv_childsize = { -1 };
        int32_t sjv_position;

        sjt_dot239 = _parent;
        sjt_parent76 = &(sjt_dot239)->children;
        sjt_functionParam120 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent76, sjt_functionParam120, &sjv_child);
        sjt_cast8 = sjv_child;
        sjt_cast8._vtbl->asinterface(sjt_cast8._parent, sji_borderchild_typeId, (sjs_interface*)&sjv_borderchild);
        if (sjv_borderchild._parent != 0) {
            sjv_borderchild._parent->_refCount++;
        }

        sjt_isEmpty14 = sjv_borderchild;
        sjt_ifElse28 = (sjt_isEmpty14._parent != 0);
        if (sjt_ifElse28) {
            sji_borderchild sjt_parent77 = { 0 };
            int32_t sjt_value1;
            int32_option value1;

            sjt_parent77 = sjv_borderchild;
            sjt_parent77._vtbl->getposition(sjt_parent77._parent, &sjt_value1);
            value1.isvalid = true;
            value1.value = sjt_value1;
            sjt_isEmpty13 = value1;
        } else {
            sjt_isEmpty13 = int32_empty;
        }

        sjt_ifElse27 = sjt_isEmpty13.isvalid;
        if (sjt_ifElse27) {
            int32_option sjt_getValue1;
            bool sjt_ifElse29;
            sji_borderchild sjt_isEmpty15 = { 0 };

            sjt_isEmpty15 = sjv_borderchild;
            sjt_ifElse29 = (sjt_isEmpty15._parent != 0);
            if (sjt_ifElse29) {
                sji_borderchild sjt_parent78 = { 0 };
                int32_t sjt_value2;
                int32_option value2;

                sjt_parent78 = sjv_borderchild;
                sjt_parent78._vtbl->getposition(sjt_parent78._parent, &sjt_value2);
                value2.isvalid = true;
                value2.value = sjt_value2;
                sjt_getValue1 = value2;
            } else {
                sjt_getValue1 = int32_empty;
            }

            sjv_position = sjt_getValue1.value;
        } else {
            sjv_position = sjv_borderposition_fill;
        }

        sjt_compare61 = sjv_position;
        sjt_compare62 = sjv_borderposition_fill;
        sjt_ifElse30 = sjt_compare61 != sjt_compare62;
        if (sjt_ifElse30) {
            int32_t sjt_compare63;
            int32_t sjt_compare64;
            sjs_rect* sjt_dot240 = 0;
            sjs_rect* sjt_dot241 = 0;
            bool sjt_ifElse31;
            sjs_size* sjt_interfaceParam12 = 0;
            sji_element sjt_parent79 = { 0 };

            sjt_parent79 = sjv_child;
            sjt_call27._refCount = 1;
            sjt_dot240 = &sjv_remaining;
            sjt_call27.w = (sjt_dot240)->w;
            sjt_dot241 = &sjv_remaining;
            sjt_call27.h = (sjt_dot241)->h;
            sjf_size(&sjt_call27);
            sjt_interfaceParam12 = &sjt_call27;
            sjv_childsize._refCount = 1;
            sjt_parent79._vtbl->getsize(sjt_parent79._parent, sjt_interfaceParam12, &sjv_childsize);
            sjt_compare63 = sjv_position;
            sjt_compare64 = sjv_borderposition_left;
            sjt_ifElse31 = sjt_compare63 == sjt_compare64;
            if (sjt_ifElse31) {
                sjs_rect* sjt_dot242 = 0;
                sjs_rect* sjt_dot243 = 0;
                sjs_size* sjt_dot244 = 0;
                sjs_rect* sjt_dot245 = 0;
                sjs_rect* sjt_dot246 = 0;
                sjs_size* sjt_dot247 = 0;
                sjs_rect* sjt_dot248 = 0;
                sjs_rect* sjt_dot249 = 0;
                sjs_size* sjt_dot250 = 0;
                sjs_rect* sjt_dot251 = 0;
                sjs_rect* sjt_interfaceParam13 = 0;
                int32_t sjt_math153;
                int32_t sjt_math154;
                int32_t sjt_math155;
                int32_t sjt_math156;
                sji_element sjt_parent80 = { 0 };

                sjt_parent80 = sjv_child;
                sjt_call28._refCount = 1;
                sjt_dot242 = &sjv_remaining;
                sjt_call28.x = (sjt_dot242)->x;
                sjt_dot243 = &sjv_remaining;
                sjt_call28.y = (sjt_dot243)->y;
                sjt_dot244 = &sjv_childsize;
                sjt_call28.w = (sjt_dot244)->w;
                sjt_dot245 = &sjv_remaining;
                sjt_call28.h = (sjt_dot245)->h;
                sjf_rect(&sjt_call28);
                sjt_interfaceParam13 = &sjt_call28;
                sjt_parent80._vtbl->setrect(sjt_parent80._parent, sjt_interfaceParam13);
                sjv_remaining._refCount = 1;
                sjt_dot246 = &sjv_remaining;
                sjt_math153 = (sjt_dot246)->x;
                sjt_dot247 = &sjv_childsize;
                sjt_math154 = (sjt_dot247)->w;
                sjv_remaining.x = sjt_math153 + sjt_math154;
                sjt_dot248 = &sjv_remaining;
                sjv_remaining.y = (sjt_dot248)->y;
                sjt_dot249 = &sjv_remaining;
                sjt_math155 = (sjt_dot249)->w;
                sjt_dot250 = &sjv_childsize;
                sjt_math156 = (sjt_dot250)->w;
                sjv_remaining.w = sjt_math155 - sjt_math156;
                sjt_dot251 = &sjv_remaining;
                sjv_remaining.h = (sjt_dot251)->h;
                sjf_rect(&sjv_remaining);
            } else {
                int32_t sjt_compare65;
                int32_t sjt_compare66;
                bool sjt_ifElse32;

                sjt_compare65 = sjv_position;
                sjt_compare66 = sjv_borderposition_right;
                sjt_ifElse32 = sjt_compare65 == sjt_compare66;
                if (sjt_ifElse32) {
                    sjs_rect* sjt_dot252 = 0;
                    sjs_rect* sjt_dot253 = 0;
                    sjs_size* sjt_dot254 = 0;
                    sjs_rect* sjt_dot255 = 0;
                    sjs_size* sjt_dot256 = 0;
                    sjs_rect* sjt_dot257 = 0;
                    sjs_rect* sjt_dot258 = 0;
                    sjs_rect* sjt_dot259 = 0;
                    sjs_rect* sjt_dot260 = 0;
                    sjs_size* sjt_dot261 = 0;
                    sjs_rect* sjt_dot262 = 0;
                    sjs_rect* sjt_interfaceParam14 = 0;
                    int32_t sjt_math157;
                    int32_t sjt_math158;
                    int32_t sjt_math159;
                    int32_t sjt_math160;
                    int32_t sjt_math161;
                    int32_t sjt_math162;
                    sji_element sjt_parent81 = { 0 };

                    sjt_parent81 = sjv_child;
                    sjt_call29._refCount = 1;
                    sjt_dot252 = &sjv_remaining;
                    sjt_math159 = (sjt_dot252)->x;
                    sjt_dot253 = &sjv_remaining;
                    sjt_math160 = (sjt_dot253)->w;
                    sjt_math157 = sjt_math159 + sjt_math160;
                    sjt_dot254 = &sjv_childsize;
                    sjt_math158 = (sjt_dot254)->w;
                    sjt_call29.x = sjt_math157 - sjt_math158;
                    sjt_dot255 = &sjv_remaining;
                    sjt_call29.y = (sjt_dot255)->y;
                    sjt_dot256 = &sjv_childsize;
                    sjt_call29.w = (sjt_dot256)->w;
                    sjt_dot257 = &sjv_remaining;
                    sjt_call29.h = (sjt_dot257)->h;
                    sjf_rect(&sjt_call29);
                    sjt_interfaceParam14 = &sjt_call29;
                    sjt_parent81._vtbl->setrect(sjt_parent81._parent, sjt_interfaceParam14);
                    sjv_remaining._refCount = 1;
                    sjt_dot258 = &sjv_remaining;
                    sjv_remaining.x = (sjt_dot258)->x;
                    sjt_dot259 = &sjv_remaining;
                    sjv_remaining.y = (sjt_dot259)->y;
                    sjt_dot260 = &sjv_remaining;
                    sjt_math161 = (sjt_dot260)->w;
                    sjt_dot261 = &sjv_childsize;
                    sjt_math162 = (sjt_dot261)->w;
                    sjv_remaining.w = sjt_math161 - sjt_math162;
                    sjt_dot262 = &sjv_remaining;
                    sjv_remaining.h = (sjt_dot262)->h;
                    sjf_rect(&sjv_remaining);
                } else {
                    int32_t sjt_compare67;
                    int32_t sjt_compare68;
                    bool sjt_ifElse33;

                    sjt_compare67 = sjv_position;
                    sjt_compare68 = sjv_borderposition_top;
                    sjt_ifElse33 = sjt_compare67 == sjt_compare68;
                    if (sjt_ifElse33) {
                        sjs_rect* sjt_dot263 = 0;
                        sjs_rect* sjt_dot264 = 0;
                        sjs_rect* sjt_dot265 = 0;
                        sjs_size* sjt_dot266 = 0;
                        sjs_rect* sjt_dot267 = 0;
                        sjs_rect* sjt_dot268 = 0;
                        sjs_size* sjt_dot269 = 0;
                        sjs_rect* sjt_dot270 = 0;
                        sjs_rect* sjt_dot271 = 0;
                        sjs_size* sjt_dot272 = 0;
                        sjs_rect* sjt_interfaceParam15 = 0;
                        int32_t sjt_math163;
                        int32_t sjt_math164;
                        int32_t sjt_math165;
                        int32_t sjt_math166;
                        sji_element sjt_parent82 = { 0 };

                        sjt_parent82 = sjv_child;
                        sjt_call30._refCount = 1;
                        sjt_dot263 = &sjv_remaining;
                        sjt_call30.x = (sjt_dot263)->x;
                        sjt_dot264 = &sjv_remaining;
                        sjt_call30.y = (sjt_dot264)->y;
                        sjt_dot265 = &sjv_remaining;
                        sjt_call30.w = (sjt_dot265)->w;
                        sjt_dot266 = &sjv_childsize;
                        sjt_call30.h = (sjt_dot266)->h;
                        sjf_rect(&sjt_call30);
                        sjt_interfaceParam15 = &sjt_call30;
                        sjt_parent82._vtbl->setrect(sjt_parent82._parent, sjt_interfaceParam15);
                        sjv_remaining._refCount = 1;
                        sjt_dot267 = &sjv_remaining;
                        sjv_remaining.x = (sjt_dot267)->x;
                        sjt_dot268 = &sjv_remaining;
                        sjt_math163 = (sjt_dot268)->y;
                        sjt_dot269 = &sjv_childsize;
                        sjt_math164 = (sjt_dot269)->h;
                        sjv_remaining.y = sjt_math163 + sjt_math164;
                        sjt_dot270 = &sjv_remaining;
                        sjv_remaining.w = (sjt_dot270)->w;
                        sjt_dot271 = &sjv_remaining;
                        sjt_math165 = (sjt_dot271)->h;
                        sjt_dot272 = &sjv_childsize;
                        sjt_math166 = (sjt_dot272)->h;
                        sjv_remaining.h = sjt_math165 - sjt_math166;
                        sjf_rect(&sjv_remaining);
                    } else {
                        int32_t sjt_compare69;
                        int32_t sjt_compare70;
                        bool sjt_ifElse34;

                        sjt_compare69 = sjv_position;
                        sjt_compare70 = sjv_borderposition_bottom;
                        sjt_ifElse34 = sjt_compare69 == sjt_compare70;
                        if (sjt_ifElse34) {
                            sjs_rect* sjt_dot273 = 0;
                            sjs_rect* sjt_dot274 = 0;
                            sjs_rect* sjt_dot275 = 0;
                            sjs_size* sjt_dot276 = 0;
                            sjs_rect* sjt_dot277 = 0;
                            sjs_size* sjt_dot278 = 0;
                            sjs_rect* sjt_dot279 = 0;
                            sjs_rect* sjt_dot280 = 0;
                            sjs_rect* sjt_dot281 = 0;
                            sjs_rect* sjt_dot282 = 0;
                            sjs_size* sjt_dot283 = 0;
                            sjs_rect* sjt_interfaceParam16 = 0;
                            int32_t sjt_math167;
                            int32_t sjt_math168;
                            int32_t sjt_math169;
                            int32_t sjt_math170;
                            int32_t sjt_math171;
                            int32_t sjt_math172;
                            sji_element sjt_parent83 = { 0 };

                            sjt_parent83 = sjv_child;
                            sjt_call31._refCount = 1;
                            sjt_dot273 = &sjv_remaining;
                            sjt_call31.x = (sjt_dot273)->x;
                            sjt_dot274 = &sjv_remaining;
                            sjt_math169 = (sjt_dot274)->y;
                            sjt_dot275 = &sjv_remaining;
                            sjt_math170 = (sjt_dot275)->h;
                            sjt_math167 = sjt_math169 + sjt_math170;
                            sjt_dot276 = &sjv_childsize;
                            sjt_math168 = (sjt_dot276)->h;
                            sjt_call31.y = sjt_math167 - sjt_math168;
                            sjt_dot277 = &sjv_remaining;
                            sjt_call31.w = (sjt_dot277)->w;
                            sjt_dot278 = &sjv_childsize;
                            sjt_call31.h = (sjt_dot278)->h;
                            sjf_rect(&sjt_call31);
                            sjt_interfaceParam16 = &sjt_call31;
                            sjt_parent83._vtbl->setrect(sjt_parent83._parent, sjt_interfaceParam16);
                            sjv_remaining._refCount = 1;
                            sjt_dot279 = &sjv_remaining;
                            sjv_remaining.x = (sjt_dot279)->x;
                            sjt_dot280 = &sjv_remaining;
                            sjv_remaining.y = (sjt_dot280)->y;
                            sjt_dot281 = &sjv_remaining;
                            sjv_remaining.w = (sjt_dot281)->w;
                            sjt_dot282 = &sjv_remaining;
                            sjt_math171 = (sjt_dot282)->h;
                            sjt_dot283 = &sjv_childsize;
                            sjt_math172 = (sjt_dot283)->h;
                            sjv_remaining.h = sjt_math171 - sjt_math172;
                            sjf_rect(&sjv_remaining);
                        }
                    }
                }
            }
        }

        i++;

        if (sjv_borderchild._parent != 0) {
            sjv_borderchild._parent->_refCount--;
            if (sjv_borderchild._parent->_refCount <= 0) {
                sjv_borderchild._vtbl->destroy(sjv_borderchild._parent);
                free(sjv_borderchild._parent);
            }
        }
        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call27._refCount == 1) { sjf_size_destroy(&sjt_call27); }
        if (sjt_call28._refCount == 1) { sjf_rect_destroy(&sjt_call28); }
        if (sjt_call29._refCount == 1) { sjf_rect_destroy(&sjt_call29); }
        if (sjt_call30._refCount == 1) { sjf_rect_destroy(&sjt_call30); }
        if (sjt_call31._refCount == 1) { sjf_rect_destroy(&sjt_call31); }
        if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
    }

    sjt_forStart13 = 0;
    sjt_dot285 = _parent;
    sjt_dot284 = &(sjt_dot285)->children;
    sjt_forEnd13 = (sjt_dot284)->count;
    i = sjt_forStart13;
    while (i < sjt_forEnd13) {
        sji_element sjt_cast9 = { 0 };
        int32_t sjt_compare71;
        int32_t sjt_compare72;
        sjs_borderlayout* sjt_dot286 = 0;
        int32_t sjt_functionParam121;
        bool sjt_ifElse35;
        bool sjt_ifElse36;
        bool sjt_ifElse38;
        int32_option sjt_isEmpty16;
        sji_borderchild sjt_isEmpty17 = { 0 };
        sjs_array_heap_iface_element* sjt_parent84 = 0;
        sji_borderchild sjv_borderchild2 = { 0 };
        sji_element sjv_child2 = { 0 };
        int32_t sjv_position2;

        sjt_dot286 = _parent;
        sjt_parent84 = &(sjt_dot286)->children;
        sjt_functionParam121 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent84, sjt_functionParam121, &sjv_child2);
        sjt_cast9 = sjv_child2;
        sjt_cast9._vtbl->asinterface(sjt_cast9._parent, sji_borderchild_typeId, (sjs_interface*)&sjv_borderchild2);
        if (sjv_borderchild2._parent != 0) {
            sjv_borderchild2._parent->_refCount++;
        }

        sjt_isEmpty17 = sjv_borderchild2;
        sjt_ifElse36 = (sjt_isEmpty17._parent != 0);
        if (sjt_ifElse36) {
            sji_borderchild sjt_parent85 = { 0 };
            int32_t sjt_value3;
            int32_option value3;

            sjt_parent85 = sjv_borderchild2;
            sjt_parent85._vtbl->getposition(sjt_parent85._parent, &sjt_value3);
            value3.isvalid = true;
            value3.value = sjt_value3;
            sjt_isEmpty16 = value3;
        } else {
            sjt_isEmpty16 = int32_empty;
        }

        sjt_ifElse35 = sjt_isEmpty16.isvalid;
        if (sjt_ifElse35) {
            int32_option sjt_getValue2;
            bool sjt_ifElse37;
            sji_borderchild sjt_isEmpty18 = { 0 };

            sjt_isEmpty18 = sjv_borderchild2;
            sjt_ifElse37 = (sjt_isEmpty18._parent != 0);
            if (sjt_ifElse37) {
                sji_borderchild sjt_parent86 = { 0 };
                int32_t sjt_value4;
                int32_option value4;

                sjt_parent86 = sjv_borderchild2;
                sjt_parent86._vtbl->getposition(sjt_parent86._parent, &sjt_value4);
                value4.isvalid = true;
                value4.value = sjt_value4;
                sjt_getValue2 = value4;
            } else {
                sjt_getValue2 = int32_empty;
            }

            sjv_position2 = sjt_getValue2.value;
        } else {
            sjv_position2 = sjv_borderposition_fill;
        }

        sjt_compare71 = sjv_position2;
        sjt_compare72 = sjv_borderposition_fill;
        sjt_ifElse38 = sjt_compare71 == sjt_compare72;
        if (sjt_ifElse38) {
            sjs_rect* sjt_interfaceParam17 = 0;
            sji_element sjt_parent87 = { 0 };

            sjt_parent87 = sjv_child2;
            sjt_interfaceParam17 = &sjv_remaining;
            sjt_parent87._vtbl->setrect(sjt_parent87._parent, sjt_interfaceParam17);
        }

        i++;

        if (sjv_borderchild2._parent != 0) {
            sjv_borderchild2._parent->_refCount--;
            if (sjv_borderchild2._parent->_refCount <= 0) {
                sjv_borderchild2._vtbl->destroy(sjv_borderchild2._parent);
                free(sjv_borderchild2._parent);
            }
        }
        if (sjv_child2._parent != 0) {
            sjv_child2._parent->_refCount--;
            if (sjv_child2._parent->_refCount <= 0) {
                sjv_child2._vtbl->destroy(sjv_child2._parent);
                free(sjv_child2._parent);
            }
        }
    }

    if (sjv_remaining._refCount == 1) { sjf_rect_destroy(&sjv_remaining); }
}

void sjf_boxelement(sjs_boxelement* _this) {
}

void sjf_boxelement_as_sji_element(sjs_boxelement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_boxelement_element_vtbl;
}

void sjf_boxelement_asinterface(sjs_boxelement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_boxelement_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_boxelement_copy(sjs_boxelement* _this, sjs_boxelement* _from) {
    _this->color._refCount = 1;
    sjf_color_copy(&_this->color, &_from->color);
    _this->idealsize._refCount = 1;
    sjf_size_copy(&_this->idealsize, &_from->idealsize);
    _this->rect._refCount = 1;
    sjf_rect_copy(&_this->rect, &_from->rect);
    _this->boxrenderer._refCount = 1;
    sjf_boxrenderer_copy((_this->boxrenderer._refCount != -1 ? &_this->boxrenderer : 0), (_from->boxrenderer._refCount != -1 ? &_from->boxrenderer : 0));
}

void sjf_boxelement_destroy(sjs_boxelement* _this) {
}

void sjf_boxelement_firemouseevent(sjs_boxelement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
}

void sjf_boxelement_getrect(sjs_boxelement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy7 = 0;
    sjs_boxelement* sjt_dot169 = 0;

    sjt_dot169 = _parent;
    sjt_copy7 = &(sjt_dot169)->rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy7);
}

void sjf_boxelement_getrect_heap(sjs_boxelement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy8 = 0;
    sjs_boxelement* sjt_dot170 = 0;

    sjt_dot170 = _parent;
    sjt_copy8 = &(sjt_dot170)->rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy8);
}

void sjf_boxelement_getsize(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_boxelement* sjt_dot167 = 0;
    sjs_size* sjt_functionParam59 = 0;
    sjs_size* sjt_parent49 = 0;

    sjt_dot167 = _parent;
    sjt_parent49 = &(sjt_dot167)->idealsize;
    sjt_functionParam59 = maxsize;
    sjf_size_min(sjt_parent49, sjt_functionParam59, _return);
}

void sjf_boxelement_getsize_heap(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_boxelement* sjt_dot168 = 0;
    sjs_size* sjt_functionParam60 = 0;
    sjs_size* sjt_parent50 = 0;

    sjt_dot168 = _parent;
    sjt_parent50 = &(sjt_dot168)->idealsize;
    sjt_functionParam60 = maxsize;
    sjf_size_min_heap(sjt_parent50, sjt_functionParam60, _return);
}

void sjf_boxelement_heap(sjs_boxelement* _this) {
}

void sjf_boxelement_render(sjs_boxelement* _parent, sjs_scene2d* scene) {
    sjs_boxelement* sjt_dot182 = 0;
    sjs_boxelement* sjt_dot186 = 0;
    bool sjt_ifElse22;
    bool sjt_ifElse23;
    sjs_boxrenderer* sjt_isEmpty7 = 0;
    sjs_boxrenderer* sjt_isEmpty8 = 0;

    sjt_dot182 = _parent;
    sjt_isEmpty7 = ((sjt_dot182)->boxrenderer._refCount != -1 ? &(sjt_dot182)->boxrenderer : 0);
    sjt_ifElse22 = (sjt_isEmpty7 == 0);
    if (sjt_ifElse22) {
        sjs_rect* sjt_copy10 = 0;
        sjs_color* sjt_copy11 = 0;
        sjs_boxelement* sjt_dot183 = 0;
        sjs_boxelement* sjt_dot184 = 0;
        sjs_boxelement* sjt_dot185 = 0;

        sjt_dot183 = _parent;
        sjt_dot183->boxrenderer._refCount = 1;
        sjt_dot184 = _parent;
        sjt_copy10 = &(sjt_dot184)->rect;
        sjt_dot183->boxrenderer.rect._refCount = 1;
        sjf_rect_copy(&sjt_dot183->boxrenderer.rect, sjt_copy10);
        sjt_dot185 = _parent;
        sjt_copy11 = &(sjt_dot185)->color;
        sjt_dot183->boxrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot183->boxrenderer.color, sjt_copy11);
        sjf_boxrenderer(&sjt_dot183->boxrenderer);
    }

    sjt_dot186 = _parent;
    sjt_isEmpty8 = ((sjt_dot186)->boxrenderer._refCount != -1 ? &(sjt_dot186)->boxrenderer : 0);
    sjt_ifElse23 = (sjt_isEmpty8 != 0);
    if (sjt_ifElse23) {
        sjs_boxelement* sjt_dot187 = 0;
        sjs_scene2d* sjt_functionParam62 = 0;
        sjs_boxrenderer* sjt_parent52 = 0;

        sjt_dot187 = _parent;
        sjt_parent52 = ((sjt_dot187)->boxrenderer._refCount != -1 ? &(sjt_dot187)->boxrenderer : 0);
        sjt_functionParam62 = scene;
        sjf_boxrenderer_render(sjt_parent52, sjt_functionParam62);
    }
}

void sjf_boxelement_setrect(sjs_boxelement* _parent, sjs_rect* rect_) {
    bool result2;
    sjs_boxelement* sjt_dot179 = 0;
    sjs_rect* sjt_functionParam61 = 0;
    bool sjt_ifElse21;
    bool sjt_not1;
    sjs_rect* sjt_parent51 = 0;

    sjt_dot179 = _parent;
    sjt_parent51 = &(sjt_dot179)->rect;
    sjt_functionParam61 = rect_;
    sjf_rect_isequal(sjt_parent51, sjt_functionParam61, &sjt_not1);
    result2 = !sjt_not1;
    sjt_ifElse21 = result2;
    if (sjt_ifElse21) {
        sjs_rect* sjt_copy9 = 0;
        sjs_boxelement* sjt_dot180 = 0;
        sjs_boxelement* sjt_dot181 = 0;

        sjt_dot180 = _parent;
        sjt_copy9 = rect_;
        sjt_dot180->rect._refCount = 1;
        sjf_rect_copy(&sjt_dot180->rect, sjt_copy9);
        sjt_dot181 = _parent;
        sjt_dot181->boxrenderer._refCount = -1;
    }
}

void sjf_boxrenderer(sjs_boxrenderer* _this) {
    _this->buffer = vertex_buffer_new("vertex:3f,color:4f");
    float x0 = (float)_this->rect.x;
    float y0 = (float)(_this->rect.y + _this->rect.h);
    float x1 = (float)(_this->rect.x + _this->rect.w);
    float y1 = (float)_this->rect.y;
    GLuint index = (GLuint)_this->buffer->vertices->size;
    GLuint indices[] = { //
    index, index+1, index+2,
    index, index+2, index+3 };
    vertex3_color4_t vertices[] = { //
    { x0, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
    { x0, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
    { x1, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
    { x1, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a } };
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
}

void sjf_boxrenderer_copy(sjs_boxrenderer* _this, sjs_boxrenderer* _from) {
    _this->rect._refCount = 1;
    sjf_rect_copy(&_this->rect, &_from->rect);
    _this->color._refCount = 1;
    sjf_color_copy(&_this->color, &_from->color);
    _this->buffer = _from->buffer;
    ptr_retain(_this->buffer);
}

void sjf_boxrenderer_destroy(sjs_boxrenderer* _this) {
    if (ptr_release(_this->buffer)) {
        vertex_buffer_delete(_this->buffer);
    }  
}

void sjf_boxrenderer_heap(sjs_boxrenderer* _this) {
    _this->buffer = vertex_buffer_new("vertex:3f,color:4f");
    float x0 = (float)_this->rect.x;
    float y0 = (float)(_this->rect.y + _this->rect.h);
    float x1 = (float)(_this->rect.x + _this->rect.w);
    float y1 = (float)_this->rect.y;
    GLuint index = (GLuint)_this->buffer->vertices->size;
    GLuint indices[] = { //
    index, index+1, index+2,
    index, index+2, index+3 };
    vertex3_color4_t vertices[] = { //
    { x0, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
    { x0, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
    { x1, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
    { x1, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a } };
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
}

void sjf_boxrenderer_render(sjs_boxrenderer* _parent, sjs_scene2d* scene) {
    glUseProgram(sjv_boxshader.id);
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxshader.id, "model" ), 1, 0, (GLfloat*)&scene->model.m00);
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxshader.id, "view" ), 1, 0, (GLfloat*)&scene->view.m00);
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxshader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection.m00);
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_centerlayout(sjs_centerlayout* _this) {
}

void sjf_centerlayout_as_sji_element(sjs_centerlayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_centerlayout_element_vtbl;
}

void sjf_centerlayout_asinterface(sjs_centerlayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_centerlayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_centerlayout_copy(sjs_centerlayout* _this, sjs_centerlayout* _from) {
    _this->children._refCount = 1;
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
    _this->margin._refCount = 1;
    sjf_margin_copy(&_this->margin, &_from->margin);
    _this->centerx = _from->centerx;
    _this->centery = _from->centery;
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_centerlayout_destroy(sjs_centerlayout* _this) {
}

void sjf_centerlayout_firemouseevent(sjs_centerlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_centerlayout* sjt_dot448 = 0;
    sjs_array_heap_iface_element* sjt_functionParam244 = 0;
    sjs_mouseevent* sjt_parent170 = 0;

    sjt_parent170 = mouseevent;
    sjt_dot448 = _parent;
    sjt_functionParam244 = &(sjt_dot448)->children;
    sjf_mouseevent_firechildren(sjt_parent170, sjt_functionParam244, _return);
}

void sjf_centerlayout_getrect(sjs_centerlayout* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy34 = 0;
    sjs_centerlayout* sjt_dot419 = 0;

    sjt_dot419 = _parent;
    sjt_copy34 = &(sjt_dot419)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy34);
}

void sjf_centerlayout_getrect_heap(sjs_centerlayout* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy35 = 0;
    sjs_centerlayout* sjt_dot420 = 0;

    sjt_dot420 = _parent;
    sjt_copy35 = &(sjt_dot420)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy35);
}

void sjf_centerlayout_getsize(sjs_centerlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t i;
    sjs_centerlayout* sjt_dot409 = 0;
    sjs_array_heap_iface_element* sjt_dot410 = 0;
    sjs_centerlayout* sjt_dot411 = 0;
    sjs_centerlayout* sjt_dot413 = 0;
    int32_t sjt_forEnd19;
    int32_t sjt_forStart19;
    sjs_margin* sjt_functionParam233 = 0;
    sjs_margin* sjt_functionParam236 = 0;
    sjs_size* sjt_parent154 = 0;
    sjs_size* sjt_parent158 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
    sjv_size.w = 0;
    sjv_size.h = 0;
    sjf_size(&sjv_size);
    sjt_parent154 = maxsize;
    sjt_dot409 = _parent;
    sjt_functionParam233 = &(sjt_dot409)->margin;
    sjf_size_subtractmargin(sjt_parent154, sjt_functionParam233, &sjv_innersize);
    sjt_forStart19 = 0;
    sjt_dot411 = _parent;
    sjt_dot410 = &(sjt_dot411)->children;
    sjt_forEnd19 = (sjt_dot410)->count;
    i = sjt_forStart19;
    while (i < sjt_forEnd19) {
        sjs_size sjt_call85 = { -1 };
        sjs_centerlayout* sjt_dot412 = 0;
        int32_t sjt_functionParam234;
        sjs_size* sjt_functionParam235 = 0;
        sjs_size* sjt_interfaceParam42 = 0;
        sjs_array_heap_iface_element* sjt_parent155 = 0;
        sjs_size* sjt_parent156 = 0;
        sji_element sjt_parent157 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot412 = _parent;
        sjt_parent155 = &(sjt_dot412)->children;
        sjt_functionParam234 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent155, sjt_functionParam234, &sjv_child);
        sjt_parent156 = &sjv_size;
        sjt_parent157 = sjv_child;
        sjt_interfaceParam42 = &sjv_innersize;
        sjt_call85._refCount = 1;
        sjt_parent157._vtbl->getsize(sjt_parent157._parent, sjt_interfaceParam42, &sjt_call85);
        sjt_functionParam235 = &sjt_call85;
        sjf_size_max(sjt_parent156, sjt_functionParam235, &sjv_size);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call85._refCount == 1) { sjf_size_destroy(&sjt_call85); }
    }

    sjt_parent158 = &sjv_size;
    sjt_dot413 = _parent;
    sjt_functionParam236 = &(sjt_dot413)->margin;
    sjf_size_addmargin(sjt_parent158, sjt_functionParam236, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
}

void sjf_centerlayout_getsize_heap(sjs_centerlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t i;
    sjs_centerlayout* sjt_dot414 = 0;
    sjs_array_heap_iface_element* sjt_dot415 = 0;
    sjs_centerlayout* sjt_dot416 = 0;
    sjs_centerlayout* sjt_dot418 = 0;
    int32_t sjt_forEnd20;
    int32_t sjt_forStart20;
    sjs_margin* sjt_functionParam237 = 0;
    sjs_margin* sjt_functionParam240 = 0;
    sjs_size* sjt_parent159 = 0;
    sjs_size* sjt_parent163 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
    sjv_size.w = 0;
    sjv_size.h = 0;
    sjf_size(&sjv_size);
    sjt_parent159 = maxsize;
    sjt_dot414 = _parent;
    sjt_functionParam237 = &(sjt_dot414)->margin;
    sjf_size_subtractmargin(sjt_parent159, sjt_functionParam237, &sjv_innersize);
    sjt_forStart20 = 0;
    sjt_dot416 = _parent;
    sjt_dot415 = &(sjt_dot416)->children;
    sjt_forEnd20 = (sjt_dot415)->count;
    i = sjt_forStart20;
    while (i < sjt_forEnd20) {
        sjs_size sjt_call86 = { -1 };
        sjs_centerlayout* sjt_dot417 = 0;
        int32_t sjt_functionParam238;
        sjs_size* sjt_functionParam239 = 0;
        sjs_size* sjt_interfaceParam43 = 0;
        sjs_array_heap_iface_element* sjt_parent160 = 0;
        sjs_size* sjt_parent161 = 0;
        sji_element sjt_parent162 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot417 = _parent;
        sjt_parent160 = &(sjt_dot417)->children;
        sjt_functionParam238 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent160, sjt_functionParam238, &sjv_child);
        sjt_parent161 = &sjv_size;
        sjt_parent162 = sjv_child;
        sjt_interfaceParam43 = &sjv_innersize;
        sjt_call86._refCount = 1;
        sjt_parent162._vtbl->getsize(sjt_parent162._parent, sjt_interfaceParam43, &sjt_call86);
        sjt_functionParam239 = &sjt_call86;
        sjf_size_max(sjt_parent161, sjt_functionParam239, &sjv_size);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call86._refCount == 1) { sjf_size_destroy(&sjt_call86); }
    }

    sjt_parent163 = &sjv_size;
    sjt_dot418 = _parent;
    sjt_functionParam240 = &(sjt_dot418)->margin;
    sjf_size_addmargin_heap(sjt_parent163, sjt_functionParam240, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
}

void sjf_centerlayout_heap(sjs_centerlayout* _this) {
}

void sjf_centerlayout_render(sjs_centerlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot445 = 0;
    sjs_centerlayout* sjt_dot446 = 0;
    int32_t sjt_forEnd22;
    int32_t sjt_forStart22;

    sjt_forStart22 = 0;
    sjt_dot446 = _parent;
    sjt_dot445 = &(sjt_dot446)->children;
    sjt_forEnd22 = (sjt_dot445)->count;
    i = sjt_forStart22;
    while (i < sjt_forEnd22) {
        sjs_centerlayout* sjt_dot447 = 0;
        int32_t sjt_functionParam243;
        sjs_scene2d* sjt_interfaceParam46 = 0;
        sjs_array_heap_iface_element* sjt_parent168 = 0;
        sji_element sjt_parent169 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot447 = _parent;
        sjt_parent168 = &(sjt_dot447)->children;
        sjt_functionParam243 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent168, sjt_functionParam243, &sjv_child);
        sjt_parent169 = sjv_child;
        sjt_interfaceParam46 = scene;
        sjt_parent169._vtbl->render(sjt_parent169._parent, sjt_interfaceParam46);
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

void sjf_centerlayout_setrect(sjs_centerlayout* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_rect* sjt_copy36 = 0;
    sjs_centerlayout* sjt_dot421 = 0;
    sjs_centerlayout* sjt_dot422 = 0;
    sjs_centerlayout* sjt_dot423 = 0;
    sjs_array_heap_iface_element* sjt_dot424 = 0;
    sjs_centerlayout* sjt_dot425 = 0;
    int32_t sjt_forEnd21;
    int32_t sjt_forStart21;
    sjs_margin* sjt_functionParam241 = 0;
    sjs_rect* sjt_parent164 = 0;
    sjs_rect sjv_innerrect = { -1 };

    sjt_dot421 = _parent;
    sjt_copy36 = rect_;
    sjt_dot421->_rect._refCount = 1;
    sjf_rect_copy(&sjt_dot421->_rect, sjt_copy36);
    sjt_dot422 = _parent;
    sjt_parent164 = &(sjt_dot422)->_rect;
    sjt_dot423 = _parent;
    sjt_functionParam241 = &(sjt_dot423)->margin;
    sjf_rect_subtractmargin(sjt_parent164, sjt_functionParam241, &sjv_innerrect);
    sjt_forStart21 = 0;
    sjt_dot425 = _parent;
    sjt_dot424 = &(sjt_dot425)->children;
    sjt_forEnd21 = (sjt_dot424)->count;
    i = sjt_forStart21;
    while (i < sjt_forEnd21) {
        sjs_size sjt_call87 = { -1 };
        sjs_rect sjt_call88 = { -1 };
        sjs_centerlayout* sjt_dot426 = 0;
        sjs_rect* sjt_dot427 = 0;
        sjs_rect* sjt_dot428 = 0;
        sjs_rect* sjt_dot429 = 0;
        sjs_rect* sjt_dot430 = 0;
        sjs_centerlayout* sjt_dot431 = 0;
        sjs_rect* sjt_dot437 = 0;
        sjs_rect* sjt_dot438 = 0;
        sjs_centerlayout* sjt_dot439 = 0;
        int32_t sjt_functionParam242;
        sjs_size* sjt_interfaceParam44 = 0;
        sjs_rect* sjt_interfaceParam45 = 0;
        bool sjt_isEmpty19;
        float_option sjt_isEmpty20;
        bool sjt_isEmpty21;
        float_option sjt_isEmpty22;
        sjs_array_heap_iface_element* sjt_parent165 = 0;
        sji_element sjt_parent166 = { 0 };
        sji_element sjt_parent167 = { 0 };
        sji_element sjv_child = { 0 };
        sjs_size sjv_childsize = { -1 };
        int32_t sjv_h;
        int32_t sjv_w;
        int32_t sjv_x;
        int32_t sjv_y;

        sjt_dot426 = _parent;
        sjt_parent165 = &(sjt_dot426)->children;
        sjt_functionParam242 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent165, sjt_functionParam242, &sjv_child);
        sjt_parent166 = sjv_child;
        sjt_call87._refCount = 1;
        sjt_dot427 = &sjv_innerrect;
        sjt_call87.w = (sjt_dot427)->w;
        sjt_dot428 = &sjv_innerrect;
        sjt_call87.h = (sjt_dot428)->h;
        sjf_size(&sjt_call87);
        sjt_interfaceParam44 = &sjt_call87;
        sjv_childsize._refCount = 1;
        sjt_parent166._vtbl->getsize(sjt_parent166._parent, sjt_interfaceParam44, &sjv_childsize);
        sjt_dot429 = &sjv_innerrect;
        sjv_x = (sjt_dot429)->x;
        sjt_dot430 = &sjv_innerrect;
        sjv_w = (sjt_dot430)->w;
        sjt_dot431 = _parent;
        sjt_isEmpty20 = (sjt_dot431)->centerx;
        sjt_isEmpty19 = sjt_isEmpty20.isvalid;
        if (sjt_isEmpty19) {
            float ifValue9;
            float sjt_cast18;
            int32_t sjt_cast19;
            sjs_centerlayout* sjt_dot432 = 0;
            sjs_rect* sjt_dot433 = 0;
            sjs_rect* sjt_dot434 = 0;
            sjs_size* sjt_dot435 = 0;
            sjs_size* sjt_dot436 = 0;
            float_option sjt_getValue3;
            int32_t sjt_math253;
            int32_t sjt_math254;
            float sjt_math255;
            float sjt_math256;
            int32_t sjt_math257;
            int32_t sjt_math258;

            sjt_dot432 = _parent;
            sjt_getValue3 = (sjt_dot432)->centerx;
            ifValue9 = sjt_getValue3.value;
            sjt_dot433 = &sjv_innerrect;
            sjt_math253 = (sjt_dot433)->x;
            sjt_dot434 = &sjv_innerrect;
            sjt_math257 = (sjt_dot434)->w;
            sjt_dot435 = &sjv_childsize;
            sjt_math258 = (sjt_dot435)->w;
            sjt_cast19 = sjt_math257 - sjt_math258;
            sjt_math255 = (float)sjt_cast19;
            sjt_math256 = ifValue9;
            sjt_cast18 = sjt_math255 * sjt_math256;
            sjt_math254 = (int32_t)sjt_cast18;
            sjv_x = sjt_math253 + sjt_math254;
            sjt_dot436 = &sjv_childsize;
            sjv_w = (sjt_dot436)->w;
        }

        sjt_dot437 = &sjv_innerrect;
        sjv_y = (sjt_dot437)->y;
        sjt_dot438 = &sjv_innerrect;
        sjv_h = (sjt_dot438)->h;
        sjt_dot439 = _parent;
        sjt_isEmpty22 = (sjt_dot439)->centery;
        sjt_isEmpty21 = sjt_isEmpty22.isvalid;
        if (sjt_isEmpty21) {
            float ifValue10;
            float sjt_cast20;
            int32_t sjt_cast21;
            sjs_centerlayout* sjt_dot440 = 0;
            sjs_rect* sjt_dot441 = 0;
            sjs_rect* sjt_dot442 = 0;
            sjs_size* sjt_dot443 = 0;
            sjs_size* sjt_dot444 = 0;
            float_option sjt_getValue4;
            int32_t sjt_math259;
            int32_t sjt_math260;
            float sjt_math261;
            float sjt_math262;
            int32_t sjt_math263;
            int32_t sjt_math264;

            sjt_dot440 = _parent;
            sjt_getValue4 = (sjt_dot440)->centery;
            ifValue10 = sjt_getValue4.value;
            sjt_dot441 = &sjv_innerrect;
            sjt_math259 = (sjt_dot441)->y;
            sjt_dot442 = &sjv_innerrect;
            sjt_math263 = (sjt_dot442)->h;
            sjt_dot443 = &sjv_childsize;
            sjt_math264 = (sjt_dot443)->h;
            sjt_cast21 = sjt_math263 - sjt_math264;
            sjt_math261 = (float)sjt_cast21;
            sjt_math262 = ifValue10;
            sjt_cast20 = sjt_math261 * sjt_math262;
            sjt_math260 = (int32_t)sjt_cast20;
            sjv_y = sjt_math259 + sjt_math260;
            sjt_dot444 = &sjv_childsize;
            sjv_h = (sjt_dot444)->h;
        }

        sjt_parent167 = sjv_child;
        sjt_call88._refCount = 1;
        sjt_call88.x = sjv_x;
        sjt_call88.y = sjv_y;
        sjt_call88.w = sjv_w;
        sjt_call88.h = sjv_h;
        sjf_rect(&sjt_call88);
        sjt_interfaceParam45 = &sjt_call88;
        sjt_parent167._vtbl->setrect(sjt_parent167._parent, sjt_interfaceParam45);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call87._refCount == 1) { sjf_size_destroy(&sjt_call87); }
        if (sjt_call88._refCount == 1) { sjf_rect_destroy(&sjt_call88); }
        if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
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

void sjf_f32_hash(float val, uint32_t* _return) {
    uint32_t sjv_result;

    sjv_result = (uint32_t)0u;
    int32_t* p = (int32_t*)&val;
    sjv_result = *p;
    (*_return) = sjv_result;
}

void sjf_f32_random(float* _return) {
    float sjv_x;

    sjv_x = 0.0f;
    sjv_x = (float)rand() / (float)RAND_MAX;
    (*_return) = sjv_x;
}

void sjf_filllayout(sjs_filllayout* _this) {
}

void sjf_filllayout_as_sji_element(sjs_filllayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_filllayout_element_vtbl;
}

void sjf_filllayout_asinterface(sjs_filllayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_filllayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_filllayout_copy(sjs_filllayout* _this, sjs_filllayout* _from) {
    _this->children._refCount = 1;
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
    _this->margin._refCount = 1;
    sjf_margin_copy(&_this->margin, &_from->margin);
    _this->effect = _from->effect;
    if (_this->effect._parent != 0) {
        _this->effect._parent->_refCount++;
    }

    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_filllayout_destroy(sjs_filllayout* _this) {
    if (_this->effect._parent != 0) {
        _this->effect._parent->_refCount--;
        if (_this->effect._parent->_refCount <= 0) {
            _this->effect._vtbl->destroy(_this->effect._parent);
            free(_this->effect._parent);
        }
    }
}

void sjf_filllayout_firemouseevent(sjs_filllayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_filllayout* sjt_dot150 = 0;
    sjs_array_heap_iface_element* sjt_functionParam56 = 0;
    sjs_mouseevent* sjt_parent47 = 0;

    sjt_parent47 = mouseevent;
    sjt_dot150 = _parent;
    sjt_functionParam56 = &(sjt_dot150)->children;
    sjf_mouseevent_firechildren(sjt_parent47, sjt_functionParam56, _return);
}

void sjf_filllayout_getrect(sjs_filllayout* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy4 = 0;
    sjs_filllayout* sjt_dot135 = 0;

    sjt_dot135 = _parent;
    sjt_copy4 = &(sjt_dot135)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy4);
}

void sjf_filllayout_getrect_heap(sjs_filllayout* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy5 = 0;
    sjs_filllayout* sjt_dot136 = 0;

    sjt_dot136 = _parent;
    sjt_copy5 = &(sjt_dot136)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy5);
}

void sjf_filllayout_getsize(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t i;
    sjs_filllayout* sjt_dot129 = 0;
    sjs_filllayout* sjt_dot97 = 0;
    sjs_array_heap_iface_element* sjt_dot98 = 0;
    sjs_filllayout* sjt_dot99 = 0;
    int32_t sjt_forEnd8;
    int32_t sjt_forStart8;
    sjs_margin* sjt_functionParam43 = 0;
    sjs_margin* sjt_functionParam46 = 0;
    sjs_size* sjt_parent30 = 0;
    sjs_size* sjt_parent34 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
    sjv_size.w = 0;
    sjv_size.h = 0;
    sjf_size(&sjv_size);
    sjt_parent30 = maxsize;
    sjt_dot97 = _parent;
    sjt_functionParam43 = &(sjt_dot97)->margin;
    sjf_size_subtractmargin(sjt_parent30, sjt_functionParam43, &sjv_innersize);
    sjt_forStart8 = 0;
    sjt_dot99 = _parent;
    sjt_dot98 = &(sjt_dot99)->children;
    sjt_forEnd8 = (sjt_dot98)->count;
    i = sjt_forStart8;
    while (i < sjt_forEnd8) {
        sjs_size sjt_call7 = { -1 };
        sjs_filllayout* sjt_dot100 = 0;
        int32_t sjt_functionParam44;
        sjs_size* sjt_functionParam45 = 0;
        sjs_size* sjt_interfaceParam4 = 0;
        sjs_array_heap_iface_element* sjt_parent31 = 0;
        sjs_size* sjt_parent32 = 0;
        sji_element sjt_parent33 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot100 = _parent;
        sjt_parent31 = &(sjt_dot100)->children;
        sjt_functionParam44 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent31, sjt_functionParam44, &sjv_child);
        sjt_parent32 = &sjv_size;
        sjt_parent33 = sjv_child;
        sjt_interfaceParam4 = &sjv_innersize;
        sjt_call7._refCount = 1;
        sjt_parent33._vtbl->getsize(sjt_parent33._parent, sjt_interfaceParam4, &sjt_call7);
        sjt_functionParam45 = &sjt_call7;
        sjf_size_max(sjt_parent32, sjt_functionParam45, &sjv_size);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call7._refCount == 1) { sjf_size_destroy(&sjt_call7); }
    }

    sjt_parent34 = &sjv_size;
    sjt_dot129 = _parent;
    sjt_functionParam46 = &(sjt_dot129)->margin;
    sjf_size_addmargin(sjt_parent34, sjt_functionParam46, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
}

void sjf_filllayout_getsize_heap(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t i;
    sjs_filllayout* sjt_dot130 = 0;
    sjs_array_heap_iface_element* sjt_dot131 = 0;
    sjs_filllayout* sjt_dot132 = 0;
    sjs_filllayout* sjt_dot134 = 0;
    int32_t sjt_forEnd9;
    int32_t sjt_forStart9;
    sjs_margin* sjt_functionParam47 = 0;
    sjs_margin* sjt_functionParam50 = 0;
    sjs_size* sjt_parent35 = 0;
    sjs_size* sjt_parent39 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
    sjv_size.w = 0;
    sjv_size.h = 0;
    sjf_size(&sjv_size);
    sjt_parent35 = maxsize;
    sjt_dot130 = _parent;
    sjt_functionParam47 = &(sjt_dot130)->margin;
    sjf_size_subtractmargin(sjt_parent35, sjt_functionParam47, &sjv_innersize);
    sjt_forStart9 = 0;
    sjt_dot132 = _parent;
    sjt_dot131 = &(sjt_dot132)->children;
    sjt_forEnd9 = (sjt_dot131)->count;
    i = sjt_forStart9;
    while (i < sjt_forEnd9) {
        sjs_size sjt_call8 = { -1 };
        sjs_filllayout* sjt_dot133 = 0;
        int32_t sjt_functionParam48;
        sjs_size* sjt_functionParam49 = 0;
        sjs_size* sjt_interfaceParam5 = 0;
        sjs_array_heap_iface_element* sjt_parent36 = 0;
        sjs_size* sjt_parent37 = 0;
        sji_element sjt_parent38 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot133 = _parent;
        sjt_parent36 = &(sjt_dot133)->children;
        sjt_functionParam48 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent36, sjt_functionParam48, &sjv_child);
        sjt_parent37 = &sjv_size;
        sjt_parent38 = sjv_child;
        sjt_interfaceParam5 = &sjv_innersize;
        sjt_call8._refCount = 1;
        sjt_parent38._vtbl->getsize(sjt_parent38._parent, sjt_interfaceParam5, &sjt_call8);
        sjt_functionParam49 = &sjt_call8;
        sjf_size_max(sjt_parent37, sjt_functionParam49, &sjv_size);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call8._refCount == 1) { sjf_size_destroy(&sjt_call8); }
    }

    sjt_parent39 = &sjv_size;
    sjt_dot134 = _parent;
    sjt_functionParam50 = &(sjt_dot134)->margin;
    sjf_size_addmargin_heap(sjt_parent39, sjt_functionParam50, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
}

void sjf_filllayout_heap(sjs_filllayout* _this) {
}

void sjf_filllayout_render(sjs_filllayout* _parent, sjs_scene2d* scene) {
    sjs_filllayout* sjt_dot145 = 0;
    bool sjt_isEmpty5;
    sji_effect sjt_isEmpty6 = { 0 };

    sjt_dot145 = _parent;
    sjt_isEmpty6 = (sjt_dot145)->effect;
    sjt_isEmpty5 = (sjt_isEmpty6._parent != 0);
    if (sjt_isEmpty5) {
        sji_effect ifValue5 = { 0 };
        sjs_filllayout* sjt_dot146 = 0;
        cb_scene2d_void sjt_interfaceParam10;
        sjs_scene2d* sjt_interfaceParam9 = 0;
        sji_effect sjt_parent44 = { 0 };

        sjt_dot146 = _parent;
        ifValue5 = (sjt_dot146)->effect;
        if (ifValue5._parent != 0) {
            ifValue5._parent->_refCount++;
        }

        sjt_parent44 = ifValue5;
        sjt_interfaceParam9 = scene;
        sjt_interfaceParam10._parent = (sjs_object*)_parent;
        sjt_interfaceParam10._cb = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_renderinner;
        sjt_parent44._vtbl->render(sjt_parent44._parent, sjt_interfaceParam9, sjt_interfaceParam10);

        if (ifValue5._parent != 0) {
            ifValue5._parent->_refCount--;
            if (ifValue5._parent->_refCount <= 0) {
                ifValue5._vtbl->destroy(ifValue5._parent);
                free(ifValue5._parent);
            }
        }
    } else {
        sjs_scene2d* sjt_functionParam55 = 0;

        sjt_functionParam55 = scene;
        sjf_filllayout_renderinner(_parent, sjt_functionParam55);
    }
}

void sjf_filllayout_renderinner(sjs_filllayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot147 = 0;
    sjs_filllayout* sjt_dot148 = 0;
    int32_t sjt_forEnd11;
    int32_t sjt_forStart11;

    sjt_forStart11 = 0;
    sjt_dot148 = _parent;
    sjt_dot147 = &(sjt_dot148)->children;
    sjt_forEnd11 = (sjt_dot147)->count;
    i = sjt_forStart11;
    while (i < sjt_forEnd11) {
        sjs_filllayout* sjt_dot149 = 0;
        int32_t sjt_functionParam54;
        sjs_scene2d* sjt_interfaceParam11 = 0;
        sjs_array_heap_iface_element* sjt_parent45 = 0;
        sji_element sjt_parent46 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot149 = _parent;
        sjt_parent45 = &(sjt_dot149)->children;
        sjt_functionParam54 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent45, sjt_functionParam54, &sjv_child);
        sjt_parent46 = sjv_child;
        sjt_interfaceParam11 = scene;
        sjt_parent46._vtbl->render(sjt_parent46._parent, sjt_interfaceParam11);
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

void sjf_filllayout_setrect(sjs_filllayout* _parent, sjs_rect* rect_) {
    sjs_rect* sjt_copy6 = 0;
    sjs_filllayout* sjt_dot137 = 0;
    sjs_filllayout* sjt_dot138 = 0;
    sjs_filllayout* sjt_dot139 = 0;
    sjs_filllayout* sjt_dot140 = 0;
    sjs_margin* sjt_functionParam51 = 0;
    bool sjt_isEmpty3;
    sji_effect sjt_isEmpty4 = { 0 };
    sjs_rect* sjt_parent40 = 0;
    sjs_rect sjv_innerrect = { -1 };

    sjt_dot137 = _parent;
    sjt_copy6 = rect_;
    sjt_dot137->_rect._refCount = 1;
    sjf_rect_copy(&sjt_dot137->_rect, sjt_copy6);
    sjt_dot138 = _parent;
    sjt_parent40 = &(sjt_dot138)->_rect;
    sjt_dot139 = _parent;
    sjt_functionParam51 = &(sjt_dot139)->margin;
    sjf_rect_subtractmargin(sjt_parent40, sjt_functionParam51, &sjv_innerrect);
    sjt_dot140 = _parent;
    sjt_isEmpty4 = (sjt_dot140)->effect;
    sjt_isEmpty3 = (sjt_isEmpty4._parent != 0);
    if (sjt_isEmpty3) {
        sji_effect ifValue3 = { 0 };
        sjs_filllayout* sjt_dot141 = 0;
        sjs_rect* sjt_interfaceParam6 = 0;
        cb_rect_void sjt_interfaceParam7;
        sji_effect sjt_parent41 = { 0 };

        sjt_dot141 = _parent;
        ifValue3 = (sjt_dot141)->effect;
        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount++;
        }

        sjt_parent41 = ifValue3;
        sjt_interfaceParam6 = &sjv_innerrect;
        sjt_interfaceParam7._parent = (sjs_object*)_parent;
        sjt_interfaceParam7._cb = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrectinner;
        sjt_parent41._vtbl->setrect(sjt_parent41._parent, sjt_interfaceParam6, sjt_interfaceParam7);

        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount--;
            if (ifValue3._parent->_refCount <= 0) {
                ifValue3._vtbl->destroy(ifValue3._parent);
                free(ifValue3._parent);
            }
        }
    } else {
        sjs_rect* sjt_functionParam53 = 0;

        sjt_functionParam53 = &sjv_innerrect;
        sjf_filllayout_setrectinner(_parent, sjt_functionParam53);
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
}

void sjf_filllayout_setrectinner(sjs_filllayout* _parent, sjs_rect* innerrect) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot142 = 0;
    sjs_filllayout* sjt_dot143 = 0;
    int32_t sjt_forEnd10;
    int32_t sjt_forStart10;

    sjt_forStart10 = 0;
    sjt_dot143 = _parent;
    sjt_dot142 = &(sjt_dot143)->children;
    sjt_forEnd10 = (sjt_dot142)->count;
    i = sjt_forStart10;
    while (i < sjt_forEnd10) {
        sjs_filllayout* sjt_dot144 = 0;
        int32_t sjt_functionParam52;
        sjs_rect* sjt_interfaceParam8 = 0;
        sjs_array_heap_iface_element* sjt_parent42 = 0;
        sji_element sjt_parent43 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot144 = _parent;
        sjt_parent42 = &(sjt_dot144)->children;
        sjt_functionParam52 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent42, sjt_functionParam52, &sjv_child);
        sjt_parent43 = sjv_child;
        sjt_interfaceParam8 = innerrect;
        sjt_parent43._vtbl->setrect(sjt_parent43._parent, sjt_interfaceParam8);
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

void sjf_flowlayout(sjs_flowlayout* _this) {
}

void sjf_flowlayout_as_sji_element(sjs_flowlayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_flowlayout_element_vtbl;
}

void sjf_flowlayout_asinterface(sjs_flowlayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_flowlayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_flowlayout_copy(sjs_flowlayout* _this, sjs_flowlayout* _from) {
    _this->children._refCount = 1;
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
    _this->margin._refCount = 1;
    sjf_margin_copy(&_this->margin, &_from->margin);
    _this->orientation = _from->orientation;
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_flowlayout_destroy(sjs_flowlayout* _this) {
}

void sjf_flowlayout_firemouseevent(sjs_flowlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_flowlayout* sjt_dot408 = 0;
    sjs_array_heap_iface_element* sjt_functionParam170 = 0;
    sjs_mouseevent* sjt_parent132 = 0;

    sjt_parent132 = mouseevent;
    sjt_dot408 = _parent;
    sjt_functionParam170 = &(sjt_dot408)->children;
    sjf_mouseevent_firechildren(sjt_parent132, sjt_functionParam170, _return);
}

void sjf_flowlayout_getrect(sjs_flowlayout* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy31 = 0;
    sjs_flowlayout* sjt_dot353 = 0;

    sjt_dot353 = _parent;
    sjt_copy31 = &(sjt_dot353)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy31);
}

void sjf_flowlayout_getrect_heap(sjs_flowlayout* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy32 = 0;
    sjs_flowlayout* sjt_dot354 = 0;

    sjt_dot354 = _parent;
    sjt_copy32 = &(sjt_dot354)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy32);
}

void sjf_flowlayout_getsize(sjs_flowlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot349 = 0;
    sjs_size* sjt_dot350 = 0;

    _return->_refCount = 1;
    sjt_dot349 = maxsize;
    _return->w = (sjt_dot349)->w;
    sjt_dot350 = maxsize;
    _return->h = (sjt_dot350)->h;
    sjf_size(_return);
}

void sjf_flowlayout_getsize_heap(sjs_flowlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot351 = 0;
    sjs_size* sjt_dot352 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot351 = maxsize;
    (*_return)->w = (sjt_dot351)->w;
    sjt_dot352 = maxsize;
    (*_return)->h = (sjt_dot352)->h;
    sjf_size_heap((*_return));
}

void sjf_flowlayout_heap(sjs_flowlayout* _this) {
}

void sjf_flowlayout_render(sjs_flowlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot405 = 0;
    sjs_flowlayout* sjt_dot406 = 0;
    int32_t sjt_forEnd18;
    int32_t sjt_forStart18;

    sjt_forStart18 = 0;
    sjt_dot406 = _parent;
    sjt_dot405 = &(sjt_dot406)->children;
    sjt_forEnd18 = (sjt_dot405)->count;
    i = sjt_forStart18;
    while (i < sjt_forEnd18) {
        sjs_flowlayout* sjt_dot407 = 0;
        int32_t sjt_functionParam169;
        sjs_scene2d* sjt_interfaceParam41 = 0;
        sjs_array_heap_iface_element* sjt_parent130 = 0;
        sji_element sjt_parent131 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot407 = _parent;
        sjt_parent130 = &(sjt_dot407)->children;
        sjt_functionParam169 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent130, sjt_functionParam169, &sjv_child);
        sjt_parent131 = sjv_child;
        sjt_interfaceParam41 = scene;
        sjt_parent131._vtbl->render(sjt_parent131._parent, sjt_interfaceParam41);
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

void sjf_flowlayout_setrect(sjs_flowlayout* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_rect* sjt_copy33 = 0;
    sjs_flowlayout* sjt_dot355 = 0;
    sjs_flowlayout* sjt_dot356 = 0;
    sjs_array_heap_iface_element* sjt_dot357 = 0;
    sjs_flowlayout* sjt_dot358 = 0;
    int32_t sjt_forEnd17;
    int32_t sjt_forStart17;
    sjs_margin* sjt_functionParam159 = 0;
    sjs_rect* sjt_parent120 = 0;
    sjs_rect sjv_innerrect = { -1 };
    int32_t sjv_val1;
    int32_t sjv_val2;
    int32_t sjv_valmax;

    sjt_dot355 = _parent;
    sjt_copy33 = rect_;
    sjt_dot355->_rect._refCount = 1;
    sjf_rect_copy(&sjt_dot355->_rect, sjt_copy33);
    sjt_parent120 = rect_;
    sjt_dot356 = _parent;
    sjt_functionParam159 = &(sjt_dot356)->margin;
    sjf_rect_subtractmargin(sjt_parent120, sjt_functionParam159, &sjv_innerrect);
    sjv_val1 = 0;
    sjv_val2 = 0;
    sjv_valmax = 0;
    sjt_forStart17 = 0;
    sjt_dot358 = _parent;
    sjt_dot357 = &(sjt_dot358)->children;
    sjt_forEnd17 = (sjt_dot357)->count;
    i = sjt_forStart17;
    while (i < sjt_forEnd17) {
        int32_t sjt_compare81;
        int32_t sjt_compare82;
        sjs_flowlayout* sjt_dot359 = 0;
        sjs_flowlayout* sjt_dot360 = 0;
        int32_t sjt_functionParam160;
        sjs_array_heap_iface_element* sjt_parent121 = 0;
        bool sjt_switch11;
        sji_element sjv_child = { 0 };
        int32_t underscore7;

        sjt_dot359 = _parent;
        sjt_parent121 = &(sjt_dot359)->children;
        sjt_functionParam160 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent121, sjt_functionParam160, &sjv_child);
        sjt_dot360 = _parent;
        underscore7 = (sjt_dot360)->orientation;
        sjt_compare81 = underscore7;
        sjt_compare82 = sjv_flowlayoutorientation_topbottom;
        sjt_switch11 = sjt_compare81 == sjt_compare82;
        if (sjt_switch11) {
            sjs_size sjt_call56 = { -1 };
            sjs_rect sjt_call57 = { -1 };
            int32_t sjt_compare83;
            int32_t sjt_compare84;
            sjs_rect* sjt_dot361 = 0;
            sjs_rect* sjt_dot362 = 0;
            sjs_size* sjt_dot363 = 0;
            sjs_size* sjt_dot364 = 0;
            sjs_rect* sjt_dot365 = 0;
            sjs_rect* sjt_dot366 = 0;
            sjs_rect* sjt_dot367 = 0;
            sjs_size* sjt_dot368 = 0;
            sjs_size* sjt_dot369 = 0;
            sjs_size* sjt_dot370 = 0;
            int32_t sjt_functionParam161;
            int32_t sjt_functionParam162;
            bool sjt_ifElse39;
            sjs_size* sjt_interfaceParam33 = 0;
            sjs_rect* sjt_interfaceParam34 = 0;
            int32_t sjt_math205;
            int32_t sjt_math206;
            int32_t sjt_math209;
            int32_t sjt_math210;
            int32_t sjt_math211;
            int32_t sjt_math212;
            int32_t sjt_math213;
            int32_t sjt_math214;
            sji_element sjt_parent122 = { 0 };
            sji_element sjt_parent123 = { 0 };
            sjs_size sjv_childsize = { -1 };

            sjt_parent122 = sjv_child;
            sjt_call56._refCount = 1;
            sjt_dot361 = &sjv_innerrect;
            sjt_call56.w = (sjt_dot361)->w;
            sjt_dot362 = &sjv_innerrect;
            sjt_call56.h = (sjt_dot362)->h;
            sjf_size(&sjt_call56);
            sjt_interfaceParam33 = &sjt_call56;
            sjv_childsize._refCount = 1;
            sjt_parent122._vtbl->getsize(sjt_parent122._parent, sjt_interfaceParam33, &sjv_childsize);
            sjt_functionParam161 = sjv_valmax;
            sjt_dot363 = &sjv_childsize;
            sjt_functionParam162 = (sjt_dot363)->w;
            sjf_i32_max(sjt_functionParam161, sjt_functionParam162, &sjv_valmax);
            sjt_math205 = sjv_val1;
            sjt_dot364 = &sjv_childsize;
            sjt_math206 = (sjt_dot364)->h;
            sjt_compare83 = sjt_math205 + sjt_math206;
            sjt_dot365 = &sjv_innerrect;
            sjt_compare84 = (sjt_dot365)->h;
            sjt_ifElse39 = sjt_compare83 > sjt_compare84;
            if (sjt_ifElse39) {
                int32_t sjt_math207;
                int32_t sjt_math208;

                sjv_val1 = 0;
                sjt_math207 = sjv_val2;
                sjt_math208 = sjv_valmax;
                sjv_val2 = sjt_math207 + sjt_math208;
                sjv_valmax = 0;
            }

            sjt_parent123 = sjv_child;
            sjt_call57._refCount = 1;
            sjt_dot366 = &sjv_innerrect;
            sjt_math209 = (sjt_dot366)->x;
            sjt_math210 = sjv_val2;
            sjt_call57.x = sjt_math209 + sjt_math210;
            sjt_dot367 = &sjv_innerrect;
            sjt_math211 = (sjt_dot367)->y;
            sjt_math212 = sjv_val1;
            sjt_call57.y = sjt_math211 + sjt_math212;
            sjt_dot368 = &sjv_childsize;
            sjt_call57.w = (sjt_dot368)->w;
            sjt_dot369 = &sjv_childsize;
            sjt_call57.h = (sjt_dot369)->h;
            sjf_rect(&sjt_call57);
            sjt_interfaceParam34 = &sjt_call57;
            sjt_parent123._vtbl->setrect(sjt_parent123._parent, sjt_interfaceParam34);
            sjt_math213 = sjv_val1;
            sjt_dot370 = &sjv_childsize;
            sjt_math214 = (sjt_dot370)->h;
            sjv_val1 = sjt_math213 + sjt_math214;

            if (sjt_call56._refCount == 1) { sjf_size_destroy(&sjt_call56); }
            if (sjt_call57._refCount == 1) { sjf_rect_destroy(&sjt_call57); }
            if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
        } else {
            int32_t sjt_compare85;
            int32_t sjt_compare86;
            bool sjt_switch12;

            sjt_compare85 = underscore7;
            sjt_compare86 = sjv_flowlayoutorientation_bottomtop;
            sjt_switch12 = sjt_compare85 == sjt_compare86;
            if (sjt_switch12) {
                sjs_size sjt_call58 = { -1 };
                sjs_rect sjt_call59 = { -1 };
                int32_t sjt_compare87;
                int32_t sjt_compare88;
                sjs_rect* sjt_dot371 = 0;
                sjs_rect* sjt_dot372 = 0;
                sjs_size* sjt_dot373 = 0;
                sjs_size* sjt_dot374 = 0;
                sjs_rect* sjt_dot375 = 0;
                sjs_rect* sjt_dot376 = 0;
                sjs_rect* sjt_dot377 = 0;
                sjs_rect* sjt_dot378 = 0;
                sjs_size* sjt_dot379 = 0;
                sjs_size* sjt_dot380 = 0;
                sjs_size* sjt_dot381 = 0;
                sjs_size* sjt_dot382 = 0;
                int32_t sjt_functionParam163;
                int32_t sjt_functionParam164;
                bool sjt_ifElse40;
                sjs_size* sjt_interfaceParam35 = 0;
                sjs_rect* sjt_interfaceParam36 = 0;
                int32_t sjt_math215;
                int32_t sjt_math216;
                int32_t sjt_math219;
                int32_t sjt_math220;
                int32_t sjt_math221;
                int32_t sjt_math222;
                int32_t sjt_math223;
                int32_t sjt_math224;
                int32_t sjt_math225;
                int32_t sjt_math226;
                int32_t sjt_math227;
                int32_t sjt_math228;
                sji_element sjt_parent124 = { 0 };
                sji_element sjt_parent125 = { 0 };
                sjs_size sjv_childsize = { -1 };

                sjt_parent124 = sjv_child;
                sjt_call58._refCount = 1;
                sjt_dot371 = &sjv_innerrect;
                sjt_call58.w = (sjt_dot371)->w;
                sjt_dot372 = &sjv_innerrect;
                sjt_call58.h = (sjt_dot372)->h;
                sjf_size(&sjt_call58);
                sjt_interfaceParam35 = &sjt_call58;
                sjv_childsize._refCount = 1;
                sjt_parent124._vtbl->getsize(sjt_parent124._parent, sjt_interfaceParam35, &sjv_childsize);
                sjt_functionParam163 = sjv_valmax;
                sjt_dot373 = &sjv_childsize;
                sjt_functionParam164 = (sjt_dot373)->w;
                sjf_i32_max(sjt_functionParam163, sjt_functionParam164, &sjv_valmax);
                sjt_math215 = sjv_val1;
                sjt_dot374 = &sjv_childsize;
                sjt_math216 = (sjt_dot374)->h;
                sjt_compare87 = sjt_math215 + sjt_math216;
                sjt_dot375 = &sjv_innerrect;
                sjt_compare88 = (sjt_dot375)->h;
                sjt_ifElse40 = sjt_compare87 >= sjt_compare88;
                if (sjt_ifElse40) {
                    int32_t sjt_math217;
                    int32_t sjt_math218;

                    sjv_val1 = 0;
                    sjt_math217 = sjv_val2;
                    sjt_math218 = sjv_valmax;
                    sjv_val2 = sjt_math217 + sjt_math218;
                    sjv_valmax = 0;
                }

                sjt_parent125 = sjv_child;
                sjt_call59._refCount = 1;
                sjt_dot376 = &sjv_innerrect;
                sjt_math219 = (sjt_dot376)->x;
                sjt_math220 = sjv_val2;
                sjt_call59.x = sjt_math219 + sjt_math220;
                sjt_dot377 = &sjv_innerrect;
                sjt_math225 = (sjt_dot377)->y;
                sjt_dot378 = &sjv_innerrect;
                sjt_math226 = (sjt_dot378)->h;
                sjt_math223 = sjt_math225 + sjt_math226;
                sjt_math224 = sjv_val1;
                sjt_math221 = sjt_math223 - sjt_math224;
                sjt_dot379 = &sjv_childsize;
                sjt_math222 = (sjt_dot379)->h;
                sjt_call59.y = sjt_math221 - sjt_math222;
                sjt_dot380 = &sjv_childsize;
                sjt_call59.w = (sjt_dot380)->w;
                sjt_dot381 = &sjv_childsize;
                sjt_call59.h = (sjt_dot381)->h;
                sjf_rect(&sjt_call59);
                sjt_interfaceParam36 = &sjt_call59;
                sjt_parent125._vtbl->setrect(sjt_parent125._parent, sjt_interfaceParam36);
                sjt_math227 = sjv_val1;
                sjt_dot382 = &sjv_childsize;
                sjt_math228 = (sjt_dot382)->h;
                sjv_val1 = sjt_math227 + sjt_math228;

                if (sjt_call58._refCount == 1) { sjf_size_destroy(&sjt_call58); }
                if (sjt_call59._refCount == 1) { sjf_rect_destroy(&sjt_call59); }
                if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
            } else {
                int32_t sjt_compare89;
                int32_t sjt_compare90;
                bool sjt_switch13;

                sjt_compare89 = underscore7;
                sjt_compare90 = sjv_flowlayoutorientation_leftright;
                sjt_switch13 = sjt_compare89 == sjt_compare90;
                if (sjt_switch13) {
                    sjs_size sjt_call60 = { -1 };
                    sjs_rect sjt_call61 = { -1 };
                    int32_t sjt_compare91;
                    int32_t sjt_compare92;
                    sjs_rect* sjt_dot383 = 0;
                    sjs_rect* sjt_dot384 = 0;
                    sjs_size* sjt_dot385 = 0;
                    sjs_size* sjt_dot386 = 0;
                    sjs_rect* sjt_dot387 = 0;
                    sjs_rect* sjt_dot388 = 0;
                    sjs_rect* sjt_dot389 = 0;
                    sjs_size* sjt_dot390 = 0;
                    sjs_size* sjt_dot391 = 0;
                    sjs_size* sjt_dot392 = 0;
                    int32_t sjt_functionParam165;
                    int32_t sjt_functionParam166;
                    bool sjt_ifElse41;
                    sjs_size* sjt_interfaceParam37 = 0;
                    sjs_rect* sjt_interfaceParam38 = 0;
                    int32_t sjt_math229;
                    int32_t sjt_math230;
                    int32_t sjt_math233;
                    int32_t sjt_math234;
                    int32_t sjt_math235;
                    int32_t sjt_math236;
                    int32_t sjt_math237;
                    int32_t sjt_math238;
                    sji_element sjt_parent126 = { 0 };
                    sji_element sjt_parent127 = { 0 };
                    sjs_size sjv_childsize = { -1 };

                    sjt_parent126 = sjv_child;
                    sjt_call60._refCount = 1;
                    sjt_dot383 = &sjv_innerrect;
                    sjt_call60.w = (sjt_dot383)->w;
                    sjt_dot384 = &sjv_innerrect;
                    sjt_call60.h = (sjt_dot384)->h;
                    sjf_size(&sjt_call60);
                    sjt_interfaceParam37 = &sjt_call60;
                    sjv_childsize._refCount = 1;
                    sjt_parent126._vtbl->getsize(sjt_parent126._parent, sjt_interfaceParam37, &sjv_childsize);
                    sjt_functionParam165 = sjv_valmax;
                    sjt_dot385 = &sjv_childsize;
                    sjt_functionParam166 = (sjt_dot385)->h;
                    sjf_i32_max(sjt_functionParam165, sjt_functionParam166, &sjv_valmax);
                    sjt_math229 = sjv_val1;
                    sjt_dot386 = &sjv_childsize;
                    sjt_math230 = (sjt_dot386)->w;
                    sjt_compare91 = sjt_math229 + sjt_math230;
                    sjt_dot387 = &sjv_innerrect;
                    sjt_compare92 = (sjt_dot387)->w;
                    sjt_ifElse41 = sjt_compare91 > sjt_compare92;
                    if (sjt_ifElse41) {
                        int32_t sjt_math231;
                        int32_t sjt_math232;

                        sjv_val1 = 0;
                        sjt_math231 = sjv_val2;
                        sjt_math232 = sjv_valmax;
                        sjv_val2 = sjt_math231 + sjt_math232;
                        sjv_valmax = 0;
                    }

                    sjt_parent127 = sjv_child;
                    sjt_call61._refCount = 1;
                    sjt_dot388 = &sjv_innerrect;
                    sjt_math233 = (sjt_dot388)->x;
                    sjt_math234 = sjv_val1;
                    sjt_call61.x = sjt_math233 + sjt_math234;
                    sjt_dot389 = &sjv_innerrect;
                    sjt_math235 = (sjt_dot389)->y;
                    sjt_math236 = sjv_val2;
                    sjt_call61.y = sjt_math235 + sjt_math236;
                    sjt_dot390 = &sjv_childsize;
                    sjt_call61.w = (sjt_dot390)->w;
                    sjt_dot391 = &sjv_childsize;
                    sjt_call61.h = (sjt_dot391)->h;
                    sjf_rect(&sjt_call61);
                    sjt_interfaceParam38 = &sjt_call61;
                    sjt_parent127._vtbl->setrect(sjt_parent127._parent, sjt_interfaceParam38);
                    sjt_math237 = sjv_val1;
                    sjt_dot392 = &sjv_childsize;
                    sjt_math238 = (sjt_dot392)->w;
                    sjv_val1 = sjt_math237 + sjt_math238;

                    if (sjt_call60._refCount == 1) { sjf_size_destroy(&sjt_call60); }
                    if (sjt_call61._refCount == 1) { sjf_rect_destroy(&sjt_call61); }
                    if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
                } else {
                    int32_t sjt_compare93;
                    int32_t sjt_compare94;
                    bool sjt_switch14;

                    sjt_compare93 = underscore7;
                    sjt_compare94 = sjv_flowlayoutorientation_rightleft;
                    sjt_switch14 = sjt_compare93 == sjt_compare94;
                    if (sjt_switch14) {
                        sjs_size sjt_call62 = { -1 };
                        sjs_rect sjt_call63 = { -1 };
                        int32_t sjt_compare95;
                        int32_t sjt_compare96;
                        sjs_rect* sjt_dot393 = 0;
                        sjs_rect* sjt_dot394 = 0;
                        sjs_size* sjt_dot395 = 0;
                        sjs_size* sjt_dot396 = 0;
                        sjs_rect* sjt_dot397 = 0;
                        sjs_rect* sjt_dot398 = 0;
                        sjs_rect* sjt_dot399 = 0;
                        sjs_size* sjt_dot400 = 0;
                        sjs_rect* sjt_dot401 = 0;
                        sjs_size* sjt_dot402 = 0;
                        sjs_size* sjt_dot403 = 0;
                        sjs_size* sjt_dot404 = 0;
                        int32_t sjt_functionParam167;
                        int32_t sjt_functionParam168;
                        bool sjt_ifElse42;
                        sjs_size* sjt_interfaceParam39 = 0;
                        sjs_rect* sjt_interfaceParam40 = 0;
                        int32_t sjt_math239;
                        int32_t sjt_math240;
                        int32_t sjt_math243;
                        int32_t sjt_math244;
                        int32_t sjt_math245;
                        int32_t sjt_math246;
                        int32_t sjt_math247;
                        int32_t sjt_math248;
                        int32_t sjt_math249;
                        int32_t sjt_math250;
                        int32_t sjt_math251;
                        int32_t sjt_math252;
                        sji_element sjt_parent128 = { 0 };
                        sji_element sjt_parent129 = { 0 };
                        sjs_size sjv_childsize = { -1 };

                        sjt_parent128 = sjv_child;
                        sjt_call62._refCount = 1;
                        sjt_dot393 = &sjv_innerrect;
                        sjt_call62.w = (sjt_dot393)->w;
                        sjt_dot394 = &sjv_innerrect;
                        sjt_call62.h = (sjt_dot394)->h;
                        sjf_size(&sjt_call62);
                        sjt_interfaceParam39 = &sjt_call62;
                        sjv_childsize._refCount = 1;
                        sjt_parent128._vtbl->getsize(sjt_parent128._parent, sjt_interfaceParam39, &sjv_childsize);
                        sjt_functionParam167 = sjv_valmax;
                        sjt_dot395 = &sjv_childsize;
                        sjt_functionParam168 = (sjt_dot395)->h;
                        sjf_i32_max(sjt_functionParam167, sjt_functionParam168, &sjv_valmax);
                        sjt_math239 = sjv_val1;
                        sjt_dot396 = &sjv_childsize;
                        sjt_math240 = (sjt_dot396)->w;
                        sjt_compare95 = sjt_math239 + sjt_math240;
                        sjt_dot397 = &sjv_innerrect;
                        sjt_compare96 = (sjt_dot397)->w;
                        sjt_ifElse42 = sjt_compare95 > sjt_compare96;
                        if (sjt_ifElse42) {
                            int32_t sjt_math241;
                            int32_t sjt_math242;

                            sjv_val1 = 0;
                            sjt_math241 = sjv_val2;
                            sjt_math242 = sjv_valmax;
                            sjv_val2 = sjt_math241 + sjt_math242;
                            sjv_valmax = 0;
                        }

                        sjt_parent129 = sjv_child;
                        sjt_call63._refCount = 1;
                        sjt_dot398 = &sjv_innerrect;
                        sjt_math247 = (sjt_dot398)->x;
                        sjt_dot399 = &sjv_innerrect;
                        sjt_math248 = (sjt_dot399)->w;
                        sjt_math245 = sjt_math247 + sjt_math248;
                        sjt_math246 = sjv_val1;
                        sjt_math243 = sjt_math245 - sjt_math246;
                        sjt_dot400 = &sjv_childsize;
                        sjt_math244 = (sjt_dot400)->w;
                        sjt_call63.x = sjt_math243 - sjt_math244;
                        sjt_dot401 = &sjv_innerrect;
                        sjt_math249 = (sjt_dot401)->y;
                        sjt_math250 = sjv_val2;
                        sjt_call63.y = sjt_math249 + sjt_math250;
                        sjt_dot402 = &sjv_childsize;
                        sjt_call63.w = (sjt_dot402)->w;
                        sjt_dot403 = &sjv_childsize;
                        sjt_call63.h = (sjt_dot403)->h;
                        sjf_rect(&sjt_call63);
                        sjt_interfaceParam40 = &sjt_call63;
                        sjt_parent129._vtbl->setrect(sjt_parent129._parent, sjt_interfaceParam40);
                        sjt_math251 = sjv_val1;
                        sjt_dot404 = &sjv_childsize;
                        sjt_math252 = (sjt_dot404)->w;
                        sjv_val1 = sjt_math251 + sjt_math252;

                        if (sjt_call62._refCount == 1) { sjf_size_destroy(&sjt_call62); }
                        if (sjt_call63._refCount == 1) { sjf_rect_destroy(&sjt_call63); }
                        if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
                    }
                }
            }
        }

        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
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
    sjs_string* sjt_copy18 = 0;
    sjs_fontkey* sjt_functionParam94 = 0;
    bool sjt_isEmpty11;
    sjs_font* sjt_isEmpty12 = 0;
    sjs_hash_fontkey_weak_font* sjt_parent64 = 0;
    sjs_font* sjv_h = 0;
    sjs_fontkey sjv_k = { -1 };
    sjs_font* sjv_w = 0;

    sjv_k._refCount = 1;
    sjt_copy18 = src;
    sjv_k.src._refCount = 1;
    sjf_string_copy(&sjv_k.src, sjt_copy18);
    sjv_k.size = size;
    sjf_fontkey(&sjv_k);
    sjt_parent64 = &sjv_fonthash;
    sjt_functionParam94 = &sjv_k;
    sjf_hash_fontkey_weak_font_getat(sjt_parent64, sjt_functionParam94, &sjv_w);
    sjv_h = sjv_w;
    if (sjv_h != 0) {
        sjv_h->_refCount++;
    }

    sjt_isEmpty12 = sjv_h;
    sjt_isEmpty11 = (sjt_isEmpty12 != 0);
    if (sjt_isEmpty11) {
        sjs_font* ifValue8 = 0;

        ifValue8 = sjv_h;
        if (ifValue8 != 0) {
            ifValue8->_refCount++;
        }

        (*_return) = ifValue8;
        (*_return)->_refCount++;

        ifValue8->_refCount--;
        if (ifValue8->_refCount <= 0) {
            weakptr_release(ifValue8);
            sjf_font_destroy(ifValue8);
            free(ifValue8);
        }
    } else {
        sjs_string* sjt_copy19 = 0;
        sjs_fontkey* sjt_functionParam95 = 0;
        sjs_font* sjt_functionParam96 = 0;
        sjs_hash_fontkey_weak_font* sjt_parent65 = 0;
        sjs_font* sjv_result = 0;

        sjv_result = (sjs_font*)malloc(sizeof(sjs_font));
        sjv_result->_refCount = 1;
        sjt_copy19 = src;
        sjv_result->src._refCount = 1;
        sjf_string_copy(&sjv_result->src, sjt_copy19);
        sjv_result->size = size;
        sjf_font_heap(sjv_result);
        sjt_parent65 = &sjv_fonthash;
        sjt_functionParam95 = &sjv_k;
        sjt_functionParam96 = sjv_result;
        delete_cb weakptrcb16 = { &sjt_functionParam96, weakptr_clear };
        if (sjt_functionParam96 != 0) { weakptr_cb_add(sjt_functionParam96, weakptrcb16); }
        sjf_hash_fontkey_weak_font_setat(sjt_parent65, sjt_functionParam95, sjt_functionParam96);
        (*_return) = sjv_result;
        (*_return)->_refCount++;

        delete_cb weakptrcb17 = { &sjt_functionParam96, weakptr_clear };
        if (sjt_functionParam96 != 0) { weakptr_cb_remove(sjt_functionParam96, weakptrcb17); }
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
    delete_cb weakptrcb18 = { &sjv_w, weakptr_clear };
    if (sjv_w != 0) { weakptr_cb_remove(sjv_w, weakptrcb18); }
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
    sjs_rect sjt_call95 = { -1 };
    sjs_string sjt_call96 = { -1 };
    int32_t sjt_compare105;
    int32_t sjt_compare106;
    sjs_rect* sjt_dot498 = 0;
    sjs_rect* sjt_dot499 = 0;
    sjs_rect* sjt_dot500 = 0;
    sjs_rect* sjt_dot501 = 0;
    sjs_rect* sjt_dot502 = 0;
    sjs_rect* sjt_dot503 = 0;
    int32_t sjt_functionParam283;
    sjs_rect* sjt_functionParam284 = 0;
    int32_t sjt_functionParam286;
    bool sjt_ifElse48;
    bool sjt_ifElse49;
    int32_t sjt_math345;
    int32_t sjt_math346;
    int32_t sjt_math347;
    int32_t sjt_math348;
    int32_t sjt_math349;
    int32_t sjt_math350;
    int32_t sjt_math351;
    int32_t sjt_math352;
    bool sjt_not5;
    sjs_rect* sjt_parent194 = 0;
    sjs_list_rect* sjt_parent196 = 0;
    sjs_list_rect* sjt_parent197 = 0;
    sjs_list_rect* sjt_parent198 = 0;
    sjs_list_rect* sjt_parent199 = 0;
    sjs_list_rect* sjt_parent200 = 0;
    sjs_rect sjv_newrect = { -1 };
    sjs_rect sjv_oldrect = { -1 };

    sjv_oldrect._refCount = 1;
    sjt_dot498 = rect;
    sjv_oldrect.x = (sjt_dot498)->x;
    sjt_dot499 = scenerect;
    sjt_math345 = (sjt_dot499)->h;
    sjt_dot500 = rect;
    sjt_math347 = (sjt_dot500)->y;
    sjt_dot501 = rect;
    sjt_math348 = (sjt_dot501)->h;
    sjt_math346 = sjt_math347 + sjt_math348;
    sjv_oldrect.y = sjt_math345 - sjt_math346;
    sjt_dot502 = rect;
    sjv_oldrect.w = (sjt_dot502)->w;
    sjt_dot503 = rect;
    sjv_oldrect.h = (sjt_dot503)->h;
    sjf_rect(&sjv_oldrect);
    sjt_parent196 = &sjv_glviewports;
    sjt_parent197 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent197, &sjt_math349);
    sjt_math350 = 1;
    sjt_functionParam283 = sjt_math349 - sjt_math350;
    sjf_list_rect_getat(sjt_parent196, sjt_functionParam283, &sjt_call95);
    sjt_parent194 = &sjt_call95;
    sjt_functionParam284 = &sjv_oldrect;
    sjf_rect_isequal(sjt_parent194, sjt_functionParam284, &sjt_not5);
    result10 = !sjt_not5;
    sjt_ifElse48 = result10;
    if (sjt_ifElse48) {
        sjs_string* sjt_functionParam285 = 0;

        sjt_call96._refCount = 1;
        sjt_call96.count = 30;
        sjt_call96.data._refCount = 1;
        sjt_call96.data.datasize = 31;
        sjt_call96.data.data = (void*)sjg_string64;
        sjt_call96.data._isglobal = true;
        sjt_call96.data.count = 31;
        sjf_array_char(&sjt_call96.data);
        sjf_string(&sjt_call96);
        sjt_functionParam285 = &sjt_call96;
        sjf_halt(sjt_functionParam285);
    }

    sjt_parent198 = &sjv_glviewports;
    sjt_parent199 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent199, &sjt_math351);
    sjt_math352 = 1;
    sjt_functionParam286 = sjt_math351 - sjt_math352;
    sjf_list_rect_removeat(sjt_parent198, sjt_functionParam286);
    sjt_parent200 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent200, &sjt_compare105);
    sjt_compare106 = 0;
    sjt_ifElse49 = sjt_compare105 > sjt_compare106;
    if (sjt_ifElse49) {
        int32_t sjt_functionParam287;
        int32_t sjt_math353;
        int32_t sjt_math354;
        sjs_list_rect* sjt_parent201 = 0;
        sjs_list_rect* sjt_parent202 = 0;

        sjt_parent201 = &sjv_glviewports;
        sjt_parent202 = &sjv_glviewports;
        sjf_list_rect_getcount(sjt_parent202, &sjt_math353);
        sjt_math354 = 1;
        sjt_functionParam287 = sjt_math353 - sjt_math354;
        sjf_list_rect_getat(sjt_parent201, sjt_functionParam287, &sjv_newrect);
    } else {
        sjv_newrect._refCount = 1;
        sjv_newrect.x = 0;
        sjv_newrect.y = 0;
        sjv_newrect.w = 0;
        sjv_newrect.h = 0;
        sjf_rect(&sjv_newrect);
    }

    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjt_call95._refCount == 1) { sjf_rect_destroy(&sjt_call95); }
    if (sjt_call96._refCount == 1) { sjf_string_destroy(&sjt_call96); }
    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
    if (sjv_oldrect._refCount == 1) { sjf_rect_destroy(&sjv_oldrect); }
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect* sjt_dot475 = 0;
    sjs_rect* sjt_dot476 = 0;
    sjs_rect* sjt_dot477 = 0;
    sjs_rect* sjt_dot478 = 0;
    sjs_rect* sjt_dot479 = 0;
    sjs_rect* sjt_dot480 = 0;
    sjs_rect* sjt_functionParam278 = 0;
    int32_t sjt_math339;
    int32_t sjt_math340;
    int32_t sjt_math341;
    int32_t sjt_math342;
    sjs_list_rect* sjt_parent189 = 0;
    sjs_rect sjv_newrect = { -1 };

    sjv_newrect._refCount = 1;
    sjt_dot475 = rect;
    sjv_newrect.x = (sjt_dot475)->x;
    sjt_dot476 = scenerect;
    sjt_math339 = (sjt_dot476)->h;
    sjt_dot477 = rect;
    sjt_math341 = (sjt_dot477)->y;
    sjt_dot478 = rect;
    sjt_math342 = (sjt_dot478)->h;
    sjt_math340 = sjt_math341 + sjt_math342;
    sjv_newrect.y = sjt_math339 - sjt_math340;
    sjt_dot479 = rect;
    sjv_newrect.w = (sjt_dot479)->w;
    sjt_dot480 = rect;
    sjv_newrect.h = (sjt_dot480)->h;
    sjf_rect(&sjv_newrect);
    sjt_parent189 = &sjv_glviewports;
    sjt_functionParam278 = &sjv_newrect;
    sjf_list_rect_add(sjt_parent189, sjt_functionParam278);
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
                delete_cb weakptrcb11 = { &kh_value(p, k), weakptr_clear };
if (kh_value(p, k) != 0) { weakptr_cb_remove(kh_value(p, k), weakptrcb11); }
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
delete_cb weakptrcb12 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb12); }
return;
    }
    (*_return) = kh_val(p, k);
delete_cb weakptrcb13 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb13); }
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
    delete_cb weakptrcb14 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_remove(kh_val(p, k), weakptrcb14); }
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
delete_cb weakptrcb15 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_add(kh_val(p, k), weakptrcb15); }
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
                delete_cb weakptrcb10 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb10); }
;
                #endif
            }
        }
        kh_destroy(string_weak_iface_element_hash_type, _this->_hash);
    }
}

void sjf_hash_string_weak_iface_element_heap(sjs_hash_string_weak_iface_element* _this) {
    _this->_hash = kh_init(string_weak_iface_element_hash_type);
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
                delete_cb weakptrcb9 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb9); }
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

void sjf_i32_random(int32_t* _return) {
    int32_t sjv_x;

    sjv_x = 0;
    sjv_x = rand();
    (*_return) = sjv_x;
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
    sjs_list_heap_iface_animation* sjt_dot454 = 0;
    int32_t sjt_functionParam258;
    sjs_array_heap_iface_animation* sjt_parent179 = 0;

    sjt_dot454 = _parent;
    sjt_parent179 = &(sjt_dot454)->array;
    sjt_functionParam258 = index;
    sjf_array_heap_iface_animation_getat_heap(sjt_parent179, sjt_functionParam258, _return);
}

void sjf_list_heap_iface_animation_getcount(sjs_list_heap_iface_animation* _parent, int32_t* _return) {
    sjs_array_heap_iface_animation* sjt_dot450 = 0;
    sjs_list_heap_iface_animation* sjt_dot451 = 0;

    sjt_dot451 = _parent;
    sjt_dot450 = &(sjt_dot451)->array;
    (*_return) = (sjt_dot450)->count;
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
    int32_t sjt_compare103;
    int32_t sjt_compare104;
    sjs_array_rect* sjt_dot481 = 0;
    sjs_list_rect* sjt_dot482 = 0;
    sjs_array_rect* sjt_dot483 = 0;
    sjs_list_rect* sjt_dot484 = 0;
    sjs_list_rect* sjt_dot491 = 0;
    sjs_array_rect* sjt_dot492 = 0;
    sjs_list_rect* sjt_dot493 = 0;
    int32_t sjt_functionParam276;
    sjs_rect* sjt_functionParam277 = 0;
    bool sjt_ifElse46;
    sjs_array_rect* sjt_parent188 = 0;

    sjt_dot482 = _parent;
    sjt_dot481 = &(sjt_dot482)->array;
    sjt_compare103 = (sjt_dot481)->count;
    sjt_dot484 = _parent;
    sjt_dot483 = &(sjt_dot484)->array;
    sjt_compare104 = (sjt_dot483)->datasize;
    sjt_ifElse46 = sjt_compare103 >= sjt_compare104;
    if (sjt_ifElse46) {
        sjs_list_rect* sjt_dot485 = 0;
        sjs_list_rect* sjt_dot488 = 0;
        sjs_array_rect* sjt_dot489 = 0;
        sjs_list_rect* sjt_dot490 = 0;
        int32_t sjt_functionParam273;
        int32_t sjt_functionParam274;
        int32_t sjt_functionParam275;
        int32_t sjt_math343;
        int32_t sjt_math344;
        sjs_array_rect* sjt_parent187 = 0;

        sjt_dot485 = _parent;
        sjt_dot488 = _parent;
        sjt_parent187 = &(sjt_dot488)->array;
        sjt_functionParam274 = 10;
        sjt_dot490 = _parent;
        sjt_dot489 = &(sjt_dot490)->array;
        sjt_math343 = (sjt_dot489)->datasize;
        sjt_math344 = 2;
        sjt_functionParam275 = sjt_math343 * sjt_math344;
        sjf_i32_max(sjt_functionParam274, sjt_functionParam275, &sjt_functionParam273);
        sjf_array_rect_grow(sjt_parent187, sjt_functionParam273, &sjt_dot485->array);
    }

    sjt_dot491 = _parent;
    sjt_parent188 = &(sjt_dot491)->array;
    sjt_dot493 = _parent;
    sjt_dot492 = &(sjt_dot493)->array;
    sjt_functionParam276 = (sjt_dot492)->count;
    sjt_functionParam277 = item;
    sjf_array_rect_initat(sjt_parent188, sjt_functionParam276, sjt_functionParam277);
}

void sjf_list_rect_copy(sjs_list_rect* _this, sjs_list_rect* _from) {
    _this->array._refCount = 1;
    sjf_array_rect_copy(&_this->array, &_from->array);
}

void sjf_list_rect_destroy(sjs_list_rect* _this) {
}

void sjf_list_rect_getat(sjs_list_rect* _parent, int32_t index, sjs_rect* _return) {
    sjs_list_rect* sjt_dot504 = 0;
    int32_t sjt_functionParam282;
    sjs_array_rect* sjt_parent195 = 0;

    sjt_dot504 = _parent;
    sjt_parent195 = &(sjt_dot504)->array;
    sjt_functionParam282 = index;
    sjf_array_rect_getat(sjt_parent195, sjt_functionParam282, _return);
}

void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return) {
    sjs_array_rect* sjt_dot505 = 0;
    sjs_list_rect* sjt_dot506 = 0;

    sjt_dot506 = _parent;
    sjt_dot505 = &(sjt_dot506)->array;
    (*_return) = (sjt_dot505)->count;
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

void sjf_listlayout(sjs_listlayout* _this) {
}

void sjf_listlayout_as_sji_element(sjs_listlayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_listlayout_element_vtbl;
}

void sjf_listlayout_asinterface(sjs_listlayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_listlayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_listlayout_copy(sjs_listlayout* _this, sjs_listlayout* _from) {
    _this->children._refCount = 1;
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
    _this->margin._refCount = 1;
    sjf_margin_copy(&_this->margin, &_from->margin);
    _this->orientation = _from->orientation;
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_listlayout_destroy(sjs_listlayout* _this) {
}

void sjf_listlayout_firemouseevent(sjs_listlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_listlayout* sjt_dot348 = 0;
    sjs_array_heap_iface_element* sjt_functionParam144 = 0;
    sjs_mouseevent* sjt_parent114 = 0;

    sjt_parent114 = mouseevent;
    sjt_dot348 = _parent;
    sjt_functionParam144 = &(sjt_dot348)->children;
    sjf_mouseevent_firechildren(sjt_parent114, sjt_functionParam144, _return);
}

void sjf_listlayout_getrect(sjs_listlayout* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy28 = 0;
    sjs_listlayout* sjt_dot305 = 0;

    sjt_dot305 = _parent;
    sjt_copy28 = &(sjt_dot305)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy28);
}

void sjf_listlayout_getrect_heap(sjs_listlayout* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy29 = 0;
    sjs_listlayout* sjt_dot306 = 0;

    sjt_dot306 = _parent;
    sjt_copy29 = &(sjt_dot306)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy29);
}

void sjf_listlayout_getsize(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot301 = 0;
    sjs_size* sjt_dot302 = 0;

    _return->_refCount = 1;
    sjt_dot301 = maxsize;
    _return->w = (sjt_dot301)->w;
    sjt_dot302 = maxsize;
    _return->h = (sjt_dot302)->h;
    sjf_size(_return);
}

void sjf_listlayout_getsize_heap(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot303 = 0;
    sjs_size* sjt_dot304 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot303 = maxsize;
    (*_return)->w = (sjt_dot303)->w;
    sjt_dot304 = maxsize;
    (*_return)->h = (sjt_dot304)->h;
    sjf_size_heap((*_return));
}

void sjf_listlayout_heap(sjs_listlayout* _this) {
}

void sjf_listlayout_render(sjs_listlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot345 = 0;
    sjs_listlayout* sjt_dot346 = 0;
    int32_t sjt_forEnd16;
    int32_t sjt_forStart16;

    sjt_forStart16 = 0;
    sjt_dot346 = _parent;
    sjt_dot345 = &(sjt_dot346)->children;
    sjt_forEnd16 = (sjt_dot345)->count;
    i = sjt_forStart16;
    while (i < sjt_forEnd16) {
        sjs_listlayout* sjt_dot347 = 0;
        int32_t sjt_functionParam143;
        sjs_scene2d* sjt_interfaceParam32 = 0;
        sjs_array_heap_iface_element* sjt_parent112 = 0;
        sji_element sjt_parent113 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot347 = _parent;
        sjt_parent112 = &(sjt_dot347)->children;
        sjt_functionParam143 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent112, sjt_functionParam143, &sjv_child);
        sjt_parent113 = sjv_child;
        sjt_interfaceParam32 = scene;
        sjt_parent113._vtbl->render(sjt_parent113._parent, sjt_interfaceParam32);
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

void sjf_listlayout_setrect(sjs_listlayout* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_rect* sjt_copy30 = 0;
    sjs_listlayout* sjt_dot307 = 0;
    sjs_listlayout* sjt_dot308 = 0;
    sjs_array_heap_iface_element* sjt_dot309 = 0;
    sjs_listlayout* sjt_dot310 = 0;
    int32_t sjt_forEnd15;
    int32_t sjt_forStart15;
    sjs_margin* sjt_functionParam141 = 0;
    sjs_rect* sjt_parent102 = 0;
    sjs_rect sjv_innerrect = { -1 };
    int32_t sjv_val;

    sjt_dot307 = _parent;
    sjt_copy30 = rect_;
    sjt_dot307->_rect._refCount = 1;
    sjf_rect_copy(&sjt_dot307->_rect, sjt_copy30);
    sjt_parent102 = rect_;
    sjt_dot308 = _parent;
    sjt_functionParam141 = &(sjt_dot308)->margin;
    sjf_rect_subtractmargin(sjt_parent102, sjt_functionParam141, &sjv_innerrect);
    sjv_val = 0;
    sjt_forStart15 = 0;
    sjt_dot310 = _parent;
    sjt_dot309 = &(sjt_dot310)->children;
    sjt_forEnd15 = (sjt_dot309)->count;
    i = sjt_forStart15;
    while (i < sjt_forEnd15) {
        int32_t sjt_compare73;
        int32_t sjt_compare74;
        sjs_listlayout* sjt_dot311 = 0;
        sjs_listlayout* sjt_dot312 = 0;
        int32_t sjt_functionParam142;
        sjs_array_heap_iface_element* sjt_parent103 = 0;
        bool sjt_switch7;
        sji_element sjv_child = { 0 };
        int32_t underscore5;

        sjt_dot311 = _parent;
        sjt_parent103 = &(sjt_dot311)->children;
        sjt_functionParam142 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent103, sjt_functionParam142, &sjv_child);
        sjt_dot312 = _parent;
        underscore5 = (sjt_dot312)->orientation;
        sjt_compare73 = underscore5;
        sjt_compare74 = sjv_listlayoutorientation_topbottom;
        sjt_switch7 = sjt_compare73 == sjt_compare74;
        if (sjt_switch7) {
            sjs_size sjt_call43 = { -1 };
            sjs_rect sjt_call44 = { -1 };
            sjs_rect* sjt_dot313 = 0;
            sjs_rect* sjt_dot314 = 0;
            sjs_rect* sjt_dot315 = 0;
            sjs_rect* sjt_dot316 = 0;
            sjs_rect* sjt_dot317 = 0;
            sjs_size* sjt_dot318 = 0;
            sjs_size* sjt_dot319 = 0;
            sjs_size* sjt_interfaceParam24 = 0;
            sjs_rect* sjt_interfaceParam25 = 0;
            int32_t sjt_math173;
            int32_t sjt_math174;
            int32_t sjt_math175;
            int32_t sjt_math176;
            int32_t sjt_math177;
            int32_t sjt_math178;
            sji_element sjt_parent104 = { 0 };
            sji_element sjt_parent105 = { 0 };
            sjs_size sjv_childsize = { -1 };

            sjt_parent104 = sjv_child;
            sjt_call43._refCount = 1;
            sjt_dot313 = &sjv_innerrect;
            sjt_call43.w = (sjt_dot313)->w;
            sjt_dot314 = &sjv_innerrect;
            sjt_math173 = (sjt_dot314)->h;
            sjt_math174 = sjv_val;
            sjt_call43.h = sjt_math173 - sjt_math174;
            sjf_size(&sjt_call43);
            sjt_interfaceParam24 = &sjt_call43;
            sjv_childsize._refCount = 1;
            sjt_parent104._vtbl->getsize(sjt_parent104._parent, sjt_interfaceParam24, &sjv_childsize);
            sjt_parent105 = sjv_child;
            sjt_call44._refCount = 1;
            sjt_dot315 = &sjv_innerrect;
            sjt_call44.x = (sjt_dot315)->x;
            sjt_dot316 = &sjv_innerrect;
            sjt_math175 = (sjt_dot316)->y;
            sjt_math176 = sjv_val;
            sjt_call44.y = sjt_math175 + sjt_math176;
            sjt_dot317 = &sjv_innerrect;
            sjt_call44.w = (sjt_dot317)->w;
            sjt_dot318 = &sjv_childsize;
            sjt_call44.h = (sjt_dot318)->h;
            sjf_rect(&sjt_call44);
            sjt_interfaceParam25 = &sjt_call44;
            sjt_parent105._vtbl->setrect(sjt_parent105._parent, sjt_interfaceParam25);
            sjt_math177 = sjv_val;
            sjt_dot319 = &sjv_childsize;
            sjt_math178 = (sjt_dot319)->h;
            sjv_val = sjt_math177 + sjt_math178;

            if (sjt_call43._refCount == 1) { sjf_size_destroy(&sjt_call43); }
            if (sjt_call44._refCount == 1) { sjf_rect_destroy(&sjt_call44); }
            if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
        } else {
            int32_t sjt_compare75;
            int32_t sjt_compare76;
            bool sjt_switch8;

            sjt_compare75 = underscore5;
            sjt_compare76 = sjv_listlayoutorientation_bottomtop;
            sjt_switch8 = sjt_compare75 == sjt_compare76;
            if (sjt_switch8) {
                sjs_size sjt_call45 = { -1 };
                sjs_rect sjt_call46 = { -1 };
                sjs_rect* sjt_dot320 = 0;
                sjs_rect* sjt_dot321 = 0;
                sjs_rect* sjt_dot322 = 0;
                sjs_rect* sjt_dot323 = 0;
                sjs_rect* sjt_dot324 = 0;
                sjs_size* sjt_dot325 = 0;
                sjs_rect* sjt_dot326 = 0;
                sjs_size* sjt_dot327 = 0;
                sjs_size* sjt_dot328 = 0;
                sjs_size* sjt_interfaceParam26 = 0;
                sjs_rect* sjt_interfaceParam27 = 0;
                int32_t sjt_math179;
                int32_t sjt_math180;
                int32_t sjt_math181;
                int32_t sjt_math182;
                int32_t sjt_math183;
                int32_t sjt_math184;
                int32_t sjt_math185;
                int32_t sjt_math186;
                int32_t sjt_math187;
                int32_t sjt_math188;
                sji_element sjt_parent106 = { 0 };
                sji_element sjt_parent107 = { 0 };
                sjs_size sjv_childsize = { -1 };

                sjt_parent106 = sjv_child;
                sjt_call45._refCount = 1;
                sjt_dot320 = &sjv_innerrect;
                sjt_call45.w = (sjt_dot320)->w;
                sjt_dot321 = &sjv_innerrect;
                sjt_math179 = (sjt_dot321)->h;
                sjt_math180 = sjv_val;
                sjt_call45.h = sjt_math179 - sjt_math180;
                sjf_size(&sjt_call45);
                sjt_interfaceParam26 = &sjt_call45;
                sjv_childsize._refCount = 1;
                sjt_parent106._vtbl->getsize(sjt_parent106._parent, sjt_interfaceParam26, &sjv_childsize);
                sjt_parent107 = sjv_child;
                sjt_call46._refCount = 1;
                sjt_dot322 = &sjv_innerrect;
                sjt_call46.x = (sjt_dot322)->x;
                sjt_dot323 = &sjv_innerrect;
                sjt_math185 = (sjt_dot323)->y;
                sjt_dot324 = &sjv_innerrect;
                sjt_math186 = (sjt_dot324)->h;
                sjt_math183 = sjt_math185 + sjt_math186;
                sjt_math184 = sjv_val;
                sjt_math181 = sjt_math183 - sjt_math184;
                sjt_dot325 = &sjv_childsize;
                sjt_math182 = (sjt_dot325)->h;
                sjt_call46.y = sjt_math181 - sjt_math182;
                sjt_dot326 = &sjv_innerrect;
                sjt_call46.w = (sjt_dot326)->w;
                sjt_dot327 = &sjv_childsize;
                sjt_call46.h = (sjt_dot327)->h;
                sjf_rect(&sjt_call46);
                sjt_interfaceParam27 = &sjt_call46;
                sjt_parent107._vtbl->setrect(sjt_parent107._parent, sjt_interfaceParam27);
                sjt_math187 = sjv_val;
                sjt_dot328 = &sjv_childsize;
                sjt_math188 = (sjt_dot328)->h;
                sjv_val = sjt_math187 + sjt_math188;

                if (sjt_call45._refCount == 1) { sjf_size_destroy(&sjt_call45); }
                if (sjt_call46._refCount == 1) { sjf_rect_destroy(&sjt_call46); }
                if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
            } else {
                int32_t sjt_compare77;
                int32_t sjt_compare78;
                bool sjt_switch9;

                sjt_compare77 = underscore5;
                sjt_compare78 = sjv_listlayoutorientation_leftright;
                sjt_switch9 = sjt_compare77 == sjt_compare78;
                if (sjt_switch9) {
                    sjs_size sjt_call47 = { -1 };
                    sjs_rect sjt_call48 = { -1 };
                    sjs_rect* sjt_dot329 = 0;
                    sjs_rect* sjt_dot330 = 0;
                    sjs_rect* sjt_dot331 = 0;
                    sjs_rect* sjt_dot332 = 0;
                    sjs_size* sjt_dot333 = 0;
                    sjs_rect* sjt_dot334 = 0;
                    sjs_size* sjt_dot335 = 0;
                    sjs_size* sjt_interfaceParam28 = 0;
                    sjs_rect* sjt_interfaceParam29 = 0;
                    int32_t sjt_math189;
                    int32_t sjt_math190;
                    int32_t sjt_math191;
                    int32_t sjt_math192;
                    int32_t sjt_math193;
                    int32_t sjt_math194;
                    sji_element sjt_parent108 = { 0 };
                    sji_element sjt_parent109 = { 0 };
                    sjs_size sjv_childsize = { -1 };

                    sjt_parent108 = sjv_child;
                    sjt_call47._refCount = 1;
                    sjt_dot329 = &sjv_innerrect;
                    sjt_math189 = (sjt_dot329)->w;
                    sjt_math190 = sjv_val;
                    sjt_call47.w = sjt_math189 - sjt_math190;
                    sjt_dot330 = &sjv_innerrect;
                    sjt_call47.h = (sjt_dot330)->h;
                    sjf_size(&sjt_call47);
                    sjt_interfaceParam28 = &sjt_call47;
                    sjv_childsize._refCount = 1;
                    sjt_parent108._vtbl->getsize(sjt_parent108._parent, sjt_interfaceParam28, &sjv_childsize);
                    sjt_parent109 = sjv_child;
                    sjt_call48._refCount = 1;
                    sjt_dot331 = &sjv_innerrect;
                    sjt_math191 = (sjt_dot331)->x;
                    sjt_math192 = sjv_val;
                    sjt_call48.x = sjt_math191 + sjt_math192;
                    sjt_dot332 = &sjv_innerrect;
                    sjt_call48.y = (sjt_dot332)->y;
                    sjt_dot333 = &sjv_childsize;
                    sjt_call48.w = (sjt_dot333)->w;
                    sjt_dot334 = &sjv_innerrect;
                    sjt_call48.h = (sjt_dot334)->h;
                    sjf_rect(&sjt_call48);
                    sjt_interfaceParam29 = &sjt_call48;
                    sjt_parent109._vtbl->setrect(sjt_parent109._parent, sjt_interfaceParam29);
                    sjt_math193 = sjv_val;
                    sjt_dot335 = &sjv_childsize;
                    sjt_math194 = (sjt_dot335)->w;
                    sjv_val = sjt_math193 + sjt_math194;

                    if (sjt_call47._refCount == 1) { sjf_size_destroy(&sjt_call47); }
                    if (sjt_call48._refCount == 1) { sjf_rect_destroy(&sjt_call48); }
                    if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
                } else {
                    int32_t sjt_compare79;
                    int32_t sjt_compare80;
                    bool sjt_switch10;

                    sjt_compare79 = underscore5;
                    sjt_compare80 = sjv_listlayoutorientation_rightleft;
                    sjt_switch10 = sjt_compare79 == sjt_compare80;
                    if (sjt_switch10) {
                        sjs_size sjt_call49 = { -1 };
                        sjs_rect sjt_call50 = { -1 };
                        sjs_rect* sjt_dot336 = 0;
                        sjs_rect* sjt_dot337 = 0;
                        sjs_rect* sjt_dot338 = 0;
                        sjs_rect* sjt_dot339 = 0;
                        sjs_size* sjt_dot340 = 0;
                        sjs_rect* sjt_dot341 = 0;
                        sjs_size* sjt_dot342 = 0;
                        sjs_rect* sjt_dot343 = 0;
                        sjs_size* sjt_dot344 = 0;
                        sjs_size* sjt_interfaceParam30 = 0;
                        sjs_rect* sjt_interfaceParam31 = 0;
                        int32_t sjt_math195;
                        int32_t sjt_math196;
                        int32_t sjt_math197;
                        int32_t sjt_math198;
                        int32_t sjt_math199;
                        int32_t sjt_math200;
                        int32_t sjt_math201;
                        int32_t sjt_math202;
                        int32_t sjt_math203;
                        int32_t sjt_math204;
                        sji_element sjt_parent110 = { 0 };
                        sji_element sjt_parent111 = { 0 };
                        sjs_size sjv_childsize = { -1 };

                        sjt_parent110 = sjv_child;
                        sjt_call49._refCount = 1;
                        sjt_dot336 = &sjv_innerrect;
                        sjt_math195 = (sjt_dot336)->w;
                        sjt_math196 = sjv_val;
                        sjt_call49.w = sjt_math195 - sjt_math196;
                        sjt_dot337 = &sjv_innerrect;
                        sjt_call49.h = (sjt_dot337)->h;
                        sjf_size(&sjt_call49);
                        sjt_interfaceParam30 = &sjt_call49;
                        sjv_childsize._refCount = 1;
                        sjt_parent110._vtbl->getsize(sjt_parent110._parent, sjt_interfaceParam30, &sjv_childsize);
                        sjt_parent111 = sjv_child;
                        sjt_call50._refCount = 1;
                        sjt_dot338 = &sjv_innerrect;
                        sjt_math201 = (sjt_dot338)->x;
                        sjt_dot339 = &sjv_innerrect;
                        sjt_math202 = (sjt_dot339)->w;
                        sjt_math199 = sjt_math201 + sjt_math202;
                        sjt_math200 = sjv_val;
                        sjt_math197 = sjt_math199 - sjt_math200;
                        sjt_dot340 = &sjv_childsize;
                        sjt_math198 = (sjt_dot340)->w;
                        sjt_call50.x = sjt_math197 - sjt_math198;
                        sjt_dot341 = &sjv_innerrect;
                        sjt_call50.y = (sjt_dot341)->y;
                        sjt_dot342 = &sjv_childsize;
                        sjt_call50.w = (sjt_dot342)->w;
                        sjt_dot343 = &sjv_innerrect;
                        sjt_call50.h = (sjt_dot343)->h;
                        sjf_rect(&sjt_call50);
                        sjt_interfaceParam31 = &sjt_call50;
                        sjt_parent111._vtbl->setrect(sjt_parent111._parent, sjt_interfaceParam31);
                        sjt_math203 = sjv_val;
                        sjt_dot344 = &sjv_childsize;
                        sjt_math204 = (sjt_dot344)->w;
                        sjv_val = sjt_math203 + sjt_math204;

                        if (sjt_call49._refCount == 1) { sjf_size_destroy(&sjt_call49); }
                        if (sjt_call50._refCount == 1) { sjf_rect_destroy(&sjt_call50); }
                        if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
                    }
                }
            }
        }

        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
}

void sjf_mainloop(void) {
    bool result9;
    sjs_size* sjt_dot496 = 0;
    sjs_size* sjt_dot497 = 0;
    int32_t sjt_functionParam261;
    sjs_size* sjt_functionParam272 = 0;
    sjs_rect* sjt_functionParam281 = 0;
    bool sjt_ifElse47;
    sjs_scene2d* sjt_interfaceParam49 = 0;
    bool sjt_isEmpty23;
    int32_option sjt_isEmpty24;
    bool sjt_not4;
    sjs_anon1* sjt_parent183 = 0;
    sjs_windowrenderer* sjt_parent184 = 0;
    sjs_scene2d* sjt_parent186 = 0;
    sjs_scene2d* sjt_parent190 = 0;
    sjs_rect* sjt_parent191 = 0;
    sji_element sjt_parent193 = { 0 };
    sjs_scene2d* sjt_parent203 = 0;
    sjs_windowrenderer* sjt_parent204 = 0;
    int32_option sjv_mouseeventtype;
    sjs_rect sjv_rect = { -1 };
    bool sjv_shouldcontinue;
    sjs_size sjv_size = { -1 };
    int32_t sjv_ticks;
    int32_t sjv_x;
    int32_t sjv_y;

    sjv_ticks = 0;
    sjv_ticks = SDL_GetTicks();
    sjt_parent183 = &sjv_animator;
    sjt_functionParam261 = sjv_ticks;
    sjf_anon1_nextframe(sjt_parent183, sjt_functionParam261);
    sjt_parent184 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_getsize(sjt_parent184, &sjv_size);
    sjt_parent186 = &sjv_rootscene;
    sjt_functionParam272 = &sjv_size;
    sjf_scene2d_setsize(sjt_parent186, sjt_functionParam272);
    sjt_parent190 = &sjv_rootscene;
    sjf_scene2d_start(sjt_parent190);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot496 = &sjv_size;
    sjv_rect.w = (sjt_dot496)->w;
    sjt_dot497 = &sjv_size;
    sjv_rect.h = (sjt_dot497)->h;
    sjf_rect(&sjv_rect);
    sjt_parent191 = &sjv_looplastrect;
    sjt_functionParam281 = &sjv_rect;
    sjf_rect_isequal(sjt_parent191, sjt_functionParam281, &sjt_not4);
    result9 = !sjt_not4;
    sjt_ifElse47 = result9;
    if (sjt_ifElse47) {
        sjs_rect* sjt_interfaceParam48 = 0;
        sji_element sjt_parent192 = { 0 };

        sjt_parent192 = sjv_root;
        sjt_interfaceParam48 = &sjv_rect;
        sjt_parent192._vtbl->setrect(sjt_parent192._parent, sjt_interfaceParam48);
    }

    sjt_parent193 = sjv_root;
    sjt_interfaceParam49 = &sjv_rootscene;
    sjt_parent193._vtbl->render(sjt_parent193._parent, sjt_interfaceParam49);
    sjt_parent203 = &sjv_rootscene;
    sjf_scene2d_end(sjt_parent203);
    sjt_parent204 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_present(sjt_parent204);
    sjv_mouseeventtype = int32_empty;
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
            sjv_mouseeventtype.isvalid = true;
            sjv_mouseeventtype.value = sjv_mouseeventtype_down;
            sjv_x = e.button.x;
            sjv_y = e.button.y;
            break;
            case SDL_MOUSEBUTTONUP:
            printf("SDL_MOUSEBUTTONUP\n");
            sjv_mouseeventtype.isvalid = true;
            sjv_mouseeventtype.value = sjv_mouseeventtype_up;
            sjv_x = e.button.x;
            sjv_y = e.button.y;
            break;
            case SDL_MOUSEMOTION:
            sjv_mouseeventtype.isvalid = true;
            sjv_mouseeventtype.value = sjv_mouseeventtype_move;
            sjv_x = e.motion.x;
            sjv_y = e.motion.y;
            break;
        }
    }
    sjv_shouldcontinue = true;
    sjt_isEmpty24 = sjv_mouseeventtype;
    sjt_isEmpty23 = sjt_isEmpty24.isvalid;
    if (sjt_isEmpty23) {
        int32_t ifValue13;
        int32_option sjt_getValue5;
        bool sjt_isEmpty25;
        sji_element sjt_isEmpty26 = { 0 };

        sjt_getValue5 = sjv_mouseeventtype;
        ifValue13 = sjt_getValue5.value;
        sjt_isEmpty26 = sjv_mouse_captureelement;
        sjt_isEmpty25 = (sjt_isEmpty26._parent != 0);
        if (sjt_isEmpty25) {
            sji_element ifValue14 = { 0 };
            sjs_mouseevent sjt_call97 = { -1 };
            sjs_mouseevent* sjt_interfaceParam50 = 0;
            sji_element sjt_parent205 = { 0 };

            ifValue14 = sjv_mouse_captureelement;
            if (ifValue14._parent != 0) {
                ifValue14._parent->_refCount++;
            }

            sjt_parent205 = ifValue14;
            sjt_call97._refCount = 1;
            sjt_call97.type = ifValue13;
            sjt_call97.point._refCount = 1;
            sjt_call97.point.x = sjv_x;
            sjt_call97.point.y = sjv_y;
            sjf_point(&sjt_call97.point);
            sjt_call97.iscaptured = true;
            sjf_mouseevent(&sjt_call97);
            sjt_interfaceParam50 = &sjt_call97;
            sjt_parent205._vtbl->firemouseevent(sjt_parent205._parent, sjt_interfaceParam50, &sjv_shouldcontinue);

            if (ifValue14._parent != 0) {
                ifValue14._parent->_refCount--;
                if (ifValue14._parent->_refCount <= 0) {
                    ifValue14._vtbl->destroy(ifValue14._parent);
                    free(ifValue14._parent);
                }
            }
            if (sjt_call97._refCount == 1) { sjf_mouseevent_destroy(&sjt_call97); }
        } else {
            sjs_mouseevent sjt_call98 = { -1 };
            sjs_mouseevent* sjt_interfaceParam51 = 0;
            sji_element sjt_parent206 = { 0 };

            sjt_parent206 = sjv_root;
            sjt_call98._refCount = 1;
            sjt_call98.type = ifValue13;
            sjt_call98.point._refCount = 1;
            sjt_call98.point.x = sjv_x;
            sjt_call98.point.y = sjv_y;
            sjf_point(&sjt_call98.point);
            sjt_call98.iscaptured = false;
            sjf_mouseevent(&sjt_call98);
            sjt_interfaceParam51 = &sjt_call98;
            sjt_parent206._vtbl->firemouseevent(sjt_parent206._parent, sjt_interfaceParam51, &sjv_shouldcontinue);

            if (sjt_call98._refCount == 1) { sjf_mouseevent_destroy(&sjt_call98); }
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
    float sjt_math265;
    float sjt_math266;
    float sjt_math267;
    float sjt_math268;
    float sjt_math269;
    float sjt_math270;
    float sjt_math271;
    float sjt_math272;
    float sjt_math273;
    float sjt_math274;
    float sjt_math275;
    float sjt_math276;
    float sjt_math277;
    float sjt_math278;
    float sjt_math279;
    float sjt_math280;
    float sjt_math281;
    float sjt_math282;
    float sjt_math283;
    float sjt_math284;
    float sjt_math285;
    float sjt_math286;
    float sjt_math287;
    float sjt_math288;
    float sjt_math289;
    float sjt_math290;
    float sjt_math291;
    float sjt_math292;
    float sjt_math293;
    float sjt_math294;
    float sjt_math295;
    float sjt_math296;
    float sjt_math297;
    float sjt_math298;
    float sjt_math299;
    float sjt_math300;
    float sjt_negate2;

    _return->_refCount = 1;
    sjt_math265 = 2.0f;
    sjt_math267 = right;
    sjt_math268 = left;
    sjt_math266 = sjt_math267 - sjt_math268;
    _return->m00 = sjt_math265 / sjt_math266;
    _return->m01 = 0.0f;
    _return->m02 = 0.0f;
    _return->m03 = 0.0f;
    _return->m10 = 0.0f;
    sjt_math269 = 2.0f;
    sjt_math271 = top;
    sjt_math272 = bottom;
    sjt_math270 = sjt_math271 - sjt_math272;
    _return->m11 = sjt_math269 / sjt_math270;
    _return->m12 = 0.0f;
    _return->m13 = 0.0f;
    _return->m20 = 0.0f;
    _return->m21 = 0.0f;
    sjt_negate2 = 2.0f;
    result5 = -sjt_negate2;
    sjt_math273 = result5;
    sjt_math275 = zfar;
    sjt_math276 = znear;
    sjt_math274 = sjt_math275 - sjt_math276;
    _return->m22 = sjt_math273 / sjt_math274;
    _return->m23 = 0.0f;
    sjt_math277 = 0.0f;
    sjt_math281 = right;
    sjt_math282 = left;
    sjt_math279 = sjt_math281 + sjt_math282;
    sjt_math283 = right;
    sjt_math284 = left;
    sjt_math280 = sjt_math283 - sjt_math284;
    sjt_math278 = sjt_math279 / sjt_math280;
    _return->m30 = sjt_math277 - sjt_math278;
    sjt_math285 = 0.0f;
    sjt_math289 = top;
    sjt_math290 = bottom;
    sjt_math287 = sjt_math289 + sjt_math290;
    sjt_math291 = top;
    sjt_math292 = bottom;
    sjt_math288 = sjt_math291 - sjt_math292;
    sjt_math286 = sjt_math287 / sjt_math288;
    _return->m31 = sjt_math285 - sjt_math286;
    sjt_math293 = 0.0f;
    sjt_math297 = zfar;
    sjt_math298 = znear;
    sjt_math295 = sjt_math297 + sjt_math298;
    sjt_math299 = zfar;
    sjt_math300 = znear;
    sjt_math296 = sjt_math299 - sjt_math300;
    sjt_math294 = sjt_math295 / sjt_math296;
    _return->m32 = sjt_math293 - sjt_math294;
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return) {
    float result6;
    float sjt_math301;
    float sjt_math302;
    float sjt_math303;
    float sjt_math304;
    float sjt_math305;
    float sjt_math306;
    float sjt_math307;
    float sjt_math308;
    float sjt_math309;
    float sjt_math310;
    float sjt_math311;
    float sjt_math312;
    float sjt_math313;
    float sjt_math314;
    float sjt_math315;
    float sjt_math316;
    float sjt_math317;
    float sjt_math318;
    float sjt_math319;
    float sjt_math320;
    float sjt_math321;
    float sjt_math322;
    float sjt_math323;
    float sjt_math324;
    float sjt_math325;
    float sjt_math326;
    float sjt_math327;
    float sjt_math328;
    float sjt_math329;
    float sjt_math330;
    float sjt_math331;
    float sjt_math332;
    float sjt_math333;
    float sjt_math334;
    float sjt_math335;
    float sjt_math336;
    float sjt_negate3;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_math301 = 2.0f;
    sjt_math303 = right;
    sjt_math304 = left;
    sjt_math302 = sjt_math303 - sjt_math304;
    (*_return)->m00 = sjt_math301 / sjt_math302;
    (*_return)->m01 = 0.0f;
    (*_return)->m02 = 0.0f;
    (*_return)->m03 = 0.0f;
    (*_return)->m10 = 0.0f;
    sjt_math305 = 2.0f;
    sjt_math307 = top;
    sjt_math308 = bottom;
    sjt_math306 = sjt_math307 - sjt_math308;
    (*_return)->m11 = sjt_math305 / sjt_math306;
    (*_return)->m12 = 0.0f;
    (*_return)->m13 = 0.0f;
    (*_return)->m20 = 0.0f;
    (*_return)->m21 = 0.0f;
    sjt_negate3 = 2.0f;
    result6 = -sjt_negate3;
    sjt_math309 = result6;
    sjt_math311 = zfar;
    sjt_math312 = znear;
    sjt_math310 = sjt_math311 - sjt_math312;
    (*_return)->m22 = sjt_math309 / sjt_math310;
    (*_return)->m23 = 0.0f;
    sjt_math313 = 0.0f;
    sjt_math317 = right;
    sjt_math318 = left;
    sjt_math315 = sjt_math317 + sjt_math318;
    sjt_math319 = right;
    sjt_math320 = left;
    sjt_math316 = sjt_math319 - sjt_math320;
    sjt_math314 = sjt_math315 / sjt_math316;
    (*_return)->m30 = sjt_math313 - sjt_math314;
    sjt_math321 = 0.0f;
    sjt_math325 = top;
    sjt_math326 = bottom;
    sjt_math323 = sjt_math325 + sjt_math326;
    sjt_math327 = top;
    sjt_math328 = bottom;
    sjt_math324 = sjt_math327 - sjt_math328;
    sjt_math322 = sjt_math323 / sjt_math324;
    (*_return)->m31 = sjt_math321 - sjt_math322;
    sjt_math329 = 0.0f;
    sjt_math333 = zfar;
    sjt_math334 = znear;
    sjt_math331 = sjt_math333 + sjt_math334;
    sjt_math335 = zfar;
    sjt_math336 = znear;
    sjt_math332 = sjt_math335 - sjt_math336;
    sjt_math330 = sjt_math331 / sjt_math332;
    (*_return)->m32 = sjt_math329 - sjt_math330;
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

void sjf_mouseevent(sjs_mouseevent* _this) {
}

void sjf_mouseevent_copy(sjs_mouseevent* _this, sjs_mouseevent* _from) {
    _this->type = _from->type;
    _this->point._refCount = 1;
    sjf_point_copy(&_this->point, &_from->point);
    _this->iscaptured = _from->iscaptured;
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
    bool sjt_and3;
    bool sjt_and4;
    bool sjt_and5;
    bool sjt_and6;
    bool sjt_and7;
    bool sjt_and8;
    int32_t sjt_compare41;
    int32_t sjt_compare42;
    int32_t sjt_compare43;
    int32_t sjt_compare44;
    int32_t sjt_compare45;
    int32_t sjt_compare46;
    int32_t sjt_compare47;
    int32_t sjt_compare48;
    sjs_rect* sjt_dot171 = 0;
    sjs_rect* sjt_dot172 = 0;
    sjs_rect* sjt_dot173 = 0;
    sjs_rect* sjt_dot174 = 0;
    sjs_rect* sjt_dot175 = 0;
    sjs_rect* sjt_dot176 = 0;
    sjs_rect* sjt_dot177 = 0;
    sjs_rect* sjt_dot178 = 0;

    sjt_dot171 = _parent;
    sjt_compare41 = (sjt_dot171)->x;
    sjt_dot172 = rect;
    sjt_compare42 = (sjt_dot172)->x;
    sjt_and3 = sjt_compare41 == sjt_compare42;
    sjt_dot173 = _parent;
    sjt_compare43 = (sjt_dot173)->y;
    sjt_dot174 = rect;
    sjt_compare44 = (sjt_dot174)->y;
    sjt_and5 = sjt_compare43 == sjt_compare44;
    sjt_dot175 = _parent;
    sjt_compare45 = (sjt_dot175)->w;
    sjt_dot176 = rect;
    sjt_compare46 = (sjt_dot176)->w;
    sjt_and7 = sjt_compare45 == sjt_compare46;
    sjt_dot177 = _parent;
    sjt_compare47 = (sjt_dot177)->h;
    sjt_dot178 = rect;
    sjt_compare48 = (sjt_dot178)->h;
    sjt_and8 = sjt_compare47 == sjt_compare48;
    sjt_and6 = sjt_and7 && sjt_and8;
    sjt_and4 = sjt_and5 && sjt_and6;
    (*_return) = sjt_and3 && sjt_and4;
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
    sjs_scene2d* sjt_dot507 = 0;
    sjs_scene2d* sjt_dot508 = 0;
    sjs_rect* sjt_functionParam288 = 0;
    sjs_rect* sjt_functionParam289 = 0;

    sjt_dot507 = _parent;
    sjt_functionParam288 = &(sjt_dot507)->windowrect;
    sjt_dot508 = _parent;
    sjt_functionParam289 = &(sjt_dot508)->windowrect;
    sjf_glpopviewport(sjt_functionParam288, sjt_functionParam289);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result4;
    sjs_scene2d* sjt_dot461 = 0;
    sjs_size* sjt_functionParam262 = 0;
    bool sjt_ifElse45;
    bool sjt_not3;
    sjs_size* sjt_parent185 = 0;

    sjt_dot461 = _parent;
    sjt_parent185 = &(sjt_dot461)->_size;
    sjt_functionParam262 = size;
    sjf_size_isequal(sjt_parent185, sjt_functionParam262, &sjt_not3);
    result4 = !sjt_not3;
    sjt_ifElse45 = result4;
    if (sjt_ifElse45) {
        float result7;
        float result8;
        int32_t sjt_cast22;
        int32_t sjt_cast23;
        sjs_size* sjt_copy37 = 0;
        sjs_scene2d* sjt_dot462 = 0;
        sjs_scene2d* sjt_dot463 = 0;
        sjs_size* sjt_dot464 = 0;
        sjs_scene2d* sjt_dot465 = 0;
        sjs_size* sjt_dot466 = 0;
        sjs_scene2d* sjt_dot467 = 0;
        sjs_scene2d* sjt_dot468 = 0;
        sjs_scene2d* sjt_dot469 = 0;
        float sjt_functionParam263;
        float sjt_functionParam264;
        float sjt_functionParam265;
        float sjt_functionParam266;
        float sjt_functionParam267;
        float sjt_functionParam268;
        float sjt_functionParam269;
        float sjt_functionParam270;
        float sjt_functionParam271;
        int32_t sjt_math337;
        int32_t sjt_math338;
        float sjt_negate4;
        float sjt_negate5;

        sjt_dot462 = _parent;
        sjt_copy37 = size;
        sjt_dot462->_size._refCount = 1;
        sjf_size_copy(&sjt_dot462->_size, sjt_copy37);
        sjt_dot463 = _parent;
        sjt_functionParam263 = 0.0f;
        sjt_dot465 = _parent;
        sjt_dot464 = &(sjt_dot465)->_size;
        sjt_cast22 = (sjt_dot464)->w;
        sjt_functionParam264 = (float)sjt_cast22;
        sjt_math337 = 0;
        sjt_dot467 = _parent;
        sjt_dot466 = &(sjt_dot467)->_size;
        sjt_math338 = (sjt_dot466)->h;
        sjt_cast23 = sjt_math337 - sjt_math338;
        sjt_functionParam265 = (float)sjt_cast23;
        sjt_functionParam266 = 0.0f;
        sjt_negate4 = 1.0f;
        result7 = -sjt_negate4;
        sjt_functionParam267 = result7;
        sjt_functionParam268 = 1.0f;
        sjf_mat4_orthographic(sjt_functionParam263, sjt_functionParam264, sjt_functionParam265, sjt_functionParam266, sjt_functionParam267, sjt_functionParam268, &sjt_dot463->projection);
        sjt_dot468 = _parent;
        sjt_functionParam269 = 1.0f;
        sjt_negate5 = 1.0f;
        result8 = -sjt_negate5;
        sjt_functionParam270 = result8;
        sjt_functionParam271 = 1.0f;
        sjf_mat4_scale(sjt_functionParam269, sjt_functionParam270, sjt_functionParam271, &sjt_dot468->model);
        sjt_dot469 = _parent;
        sjf_mat4_identity(&sjt_dot469->view);
    }
}

void sjf_scene2d_start(sjs_scene2d* _parent) {
    sjs_scene2d* sjt_dot470 = 0;
    sjs_size* sjt_dot471 = 0;
    sjs_scene2d* sjt_dot472 = 0;
    sjs_size* sjt_dot473 = 0;
    sjs_scene2d* sjt_dot474 = 0;
    sjs_scene2d* sjt_dot494 = 0;
    sjs_scene2d* sjt_dot495 = 0;
    sjs_rect* sjt_functionParam279 = 0;
    sjs_rect* sjt_functionParam280 = 0;

    sjt_dot470 = _parent;
    sjt_dot470->windowrect._refCount = 1;
    sjt_dot470->windowrect.x = 0;
    sjt_dot470->windowrect.y = 0;
    sjt_dot472 = _parent;
    sjt_dot471 = &(sjt_dot472)->_size;
    sjt_dot470->windowrect.w = (sjt_dot471)->w;
    sjt_dot474 = _parent;
    sjt_dot473 = &(sjt_dot474)->_size;
    sjt_dot470->windowrect.h = (sjt_dot473)->h;
    sjf_rect(&sjt_dot470->windowrect);
    sjt_dot494 = _parent;
    sjt_functionParam279 = &(sjt_dot494)->windowrect;
    sjt_dot495 = _parent;
    sjt_functionParam280 = &(sjt_dot495)->windowrect;
    sjf_glpushviewport(sjt_functionParam279, sjt_functionParam280);
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
    sjs_size* sjt_dot117 = 0;
    sjs_margin* sjt_dot118 = 0;
    sjs_margin* sjt_dot119 = 0;
    sjs_size* sjt_dot120 = 0;
    sjs_margin* sjt_dot121 = 0;
    sjs_margin* sjt_dot122 = 0;
    int32_t sjt_math109;
    int32_t sjt_math110;
    int32_t sjt_math111;
    int32_t sjt_math112;
    int32_t sjt_math113;
    int32_t sjt_math114;
    int32_t sjt_math115;
    int32_t sjt_math116;

    _return->_refCount = 1;
    sjt_dot117 = _parent;
    sjt_math111 = (sjt_dot117)->w;
    sjt_dot118 = margin;
    sjt_math112 = (sjt_dot118)->l;
    sjt_math109 = sjt_math111 + sjt_math112;
    sjt_dot119 = margin;
    sjt_math110 = (sjt_dot119)->r;
    _return->w = sjt_math109 + sjt_math110;
    sjt_dot120 = _parent;
    sjt_math115 = (sjt_dot120)->h;
    sjt_dot121 = margin;
    sjt_math116 = (sjt_dot121)->t;
    sjt_math113 = sjt_math115 + sjt_math116;
    sjt_dot122 = margin;
    sjt_math114 = (sjt_dot122)->b;
    _return->h = sjt_math113 + sjt_math114;
    sjf_size(_return);
}

void sjf_size_addmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    sjs_size* sjt_dot123 = 0;
    sjs_margin* sjt_dot124 = 0;
    sjs_margin* sjt_dot125 = 0;
    sjs_size* sjt_dot126 = 0;
    sjs_margin* sjt_dot127 = 0;
    sjs_margin* sjt_dot128 = 0;
    int32_t sjt_math117;
    int32_t sjt_math118;
    int32_t sjt_math119;
    int32_t sjt_math120;
    int32_t sjt_math121;
    int32_t sjt_math122;
    int32_t sjt_math123;
    int32_t sjt_math124;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot123 = _parent;
    sjt_math119 = (sjt_dot123)->w;
    sjt_dot124 = margin;
    sjt_math120 = (sjt_dot124)->l;
    sjt_math117 = sjt_math119 + sjt_math120;
    sjt_dot125 = margin;
    sjt_math118 = (sjt_dot125)->r;
    (*_return)->w = sjt_math117 + sjt_math118;
    sjt_dot126 = _parent;
    sjt_math123 = (sjt_dot126)->h;
    sjt_dot127 = margin;
    sjt_math124 = (sjt_dot127)->t;
    sjt_math121 = sjt_math123 + sjt_math124;
    sjt_dot128 = margin;
    sjt_math122 = (sjt_dot128)->b;
    (*_return)->h = sjt_math121 + sjt_math122;
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
    bool sjt_and10;
    bool sjt_and9;
    int32_t sjt_compare100;
    int32_t sjt_compare101;
    int32_t sjt_compare102;
    int32_t sjt_compare99;
    sjs_size* sjt_dot457 = 0;
    sjs_size* sjt_dot458 = 0;
    sjs_size* sjt_dot459 = 0;
    sjs_size* sjt_dot460 = 0;

    sjt_dot457 = _parent;
    sjt_compare99 = (sjt_dot457)->w;
    sjt_dot458 = size;
    sjt_compare100 = (sjt_dot458)->w;
    sjt_and9 = sjt_compare99 == sjt_compare100;
    sjt_dot459 = _parent;
    sjt_compare101 = (sjt_dot459)->h;
    sjt_dot460 = size;
    sjt_compare102 = (sjt_dot460)->h;
    sjt_and10 = sjt_compare101 == sjt_compare102;
    (*_return) = sjt_and9 && sjt_and10;
}

void sjf_size_max(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t sjt_compare25;
    int32_t sjt_compare26;
    int32_t sjt_compare27;
    int32_t sjt_compare28;
    sjs_size* sjt_dot101 = 0;
    sjs_size* sjt_dot102 = 0;
    sjs_size* sjt_dot105 = 0;
    sjs_size* sjt_dot106 = 0;
    bool sjt_ifElse13;
    bool sjt_ifElse14;

    _return->_refCount = 1;
    sjt_dot101 = _parent;
    sjt_compare25 = (sjt_dot101)->w;
    sjt_dot102 = maxsize;
    sjt_compare26 = (sjt_dot102)->w;
    sjt_ifElse13 = sjt_compare25 > sjt_compare26;
    if (sjt_ifElse13) {
        sjs_size* sjt_dot103 = 0;

        sjt_dot103 = _parent;
        _return->w = (sjt_dot103)->w;
    } else {
        sjs_size* sjt_dot104 = 0;

        sjt_dot104 = maxsize;
        _return->w = (sjt_dot104)->w;
    }

    sjt_dot105 = _parent;
    sjt_compare27 = (sjt_dot105)->h;
    sjt_dot106 = maxsize;
    sjt_compare28 = (sjt_dot106)->h;
    sjt_ifElse14 = sjt_compare27 > sjt_compare28;
    if (sjt_ifElse14) {
        sjs_size* sjt_dot107 = 0;

        sjt_dot107 = _parent;
        _return->h = (sjt_dot107)->h;
    } else {
        sjs_size* sjt_dot108 = 0;

        sjt_dot108 = maxsize;
        _return->h = (sjt_dot108)->h;
    }

    sjf_size(_return);
}

void sjf_size_max_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t sjt_compare29;
    int32_t sjt_compare30;
    int32_t sjt_compare31;
    int32_t sjt_compare32;
    sjs_size* sjt_dot109 = 0;
    sjs_size* sjt_dot110 = 0;
    sjs_size* sjt_dot113 = 0;
    sjs_size* sjt_dot114 = 0;
    bool sjt_ifElse15;
    bool sjt_ifElse16;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot109 = _parent;
    sjt_compare29 = (sjt_dot109)->w;
    sjt_dot110 = maxsize;
    sjt_compare30 = (sjt_dot110)->w;
    sjt_ifElse15 = sjt_compare29 > sjt_compare30;
    if (sjt_ifElse15) {
        sjs_size* sjt_dot111 = 0;

        sjt_dot111 = _parent;
        (*_return)->w = (sjt_dot111)->w;
    } else {
        sjs_size* sjt_dot112 = 0;

        sjt_dot112 = maxsize;
        (*_return)->w = (sjt_dot112)->w;
    }

    sjt_dot113 = _parent;
    sjt_compare31 = (sjt_dot113)->h;
    sjt_dot114 = maxsize;
    sjt_compare32 = (sjt_dot114)->h;
    sjt_ifElse16 = sjt_compare31 > sjt_compare32;
    if (sjt_ifElse16) {
        sjs_size* sjt_dot115 = 0;

        sjt_dot115 = _parent;
        (*_return)->h = (sjt_dot115)->h;
    } else {
        sjs_size* sjt_dot116 = 0;

        sjt_dot116 = maxsize;
        (*_return)->h = (sjt_dot116)->h;
    }

    sjf_size_heap((*_return));
}

void sjf_size_min(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t sjt_compare33;
    int32_t sjt_compare34;
    int32_t sjt_compare35;
    int32_t sjt_compare36;
    sjs_size* sjt_dot151 = 0;
    sjs_size* sjt_dot152 = 0;
    sjs_size* sjt_dot155 = 0;
    sjs_size* sjt_dot156 = 0;
    bool sjt_ifElse17;
    bool sjt_ifElse18;

    _return->_refCount = 1;
    sjt_dot151 = _parent;
    sjt_compare33 = (sjt_dot151)->w;
    sjt_dot152 = maxsize;
    sjt_compare34 = (sjt_dot152)->w;
    sjt_ifElse17 = sjt_compare33 < sjt_compare34;
    if (sjt_ifElse17) {
        sjs_size* sjt_dot153 = 0;

        sjt_dot153 = _parent;
        _return->w = (sjt_dot153)->w;
    } else {
        sjs_size* sjt_dot154 = 0;

        sjt_dot154 = maxsize;
        _return->w = (sjt_dot154)->w;
    }

    sjt_dot155 = _parent;
    sjt_compare35 = (sjt_dot155)->h;
    sjt_dot156 = maxsize;
    sjt_compare36 = (sjt_dot156)->h;
    sjt_ifElse18 = sjt_compare35 < sjt_compare36;
    if (sjt_ifElse18) {
        sjs_size* sjt_dot157 = 0;

        sjt_dot157 = _parent;
        _return->h = (sjt_dot157)->h;
    } else {
        sjs_size* sjt_dot158 = 0;

        sjt_dot158 = maxsize;
        _return->h = (sjt_dot158)->h;
    }

    sjf_size(_return);
}

void sjf_size_min_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t sjt_compare37;
    int32_t sjt_compare38;
    int32_t sjt_compare39;
    int32_t sjt_compare40;
    sjs_size* sjt_dot159 = 0;
    sjs_size* sjt_dot160 = 0;
    sjs_size* sjt_dot163 = 0;
    sjs_size* sjt_dot164 = 0;
    bool sjt_ifElse19;
    bool sjt_ifElse20;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot159 = _parent;
    sjt_compare37 = (sjt_dot159)->w;
    sjt_dot160 = maxsize;
    sjt_compare38 = (sjt_dot160)->w;
    sjt_ifElse19 = sjt_compare37 < sjt_compare38;
    if (sjt_ifElse19) {
        sjs_size* sjt_dot161 = 0;

        sjt_dot161 = _parent;
        (*_return)->w = (sjt_dot161)->w;
    } else {
        sjs_size* sjt_dot162 = 0;

        sjt_dot162 = maxsize;
        (*_return)->w = (sjt_dot162)->w;
    }

    sjt_dot163 = _parent;
    sjt_compare39 = (sjt_dot163)->h;
    sjt_dot164 = maxsize;
    sjt_compare40 = (sjt_dot164)->h;
    sjt_ifElse20 = sjt_compare39 < sjt_compare40;
    if (sjt_ifElse20) {
        sjs_size* sjt_dot165 = 0;

        sjt_dot165 = _parent;
        (*_return)->h = (sjt_dot165)->h;
    } else {
        sjs_size* sjt_dot166 = 0;

        sjt_dot166 = maxsize;
        (*_return)->h = (sjt_dot166)->h;
    }

    sjf_size_heap((*_return));
}

void sjf_size_subtractmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    sjs_size* sjt_dot85 = 0;
    sjs_margin* sjt_dot86 = 0;
    sjs_margin* sjt_dot87 = 0;
    sjs_size* sjt_dot88 = 0;
    sjs_margin* sjt_dot89 = 0;
    sjs_margin* sjt_dot90 = 0;
    int32_t sjt_math100;
    int32_t sjt_math93;
    int32_t sjt_math94;
    int32_t sjt_math95;
    int32_t sjt_math96;
    int32_t sjt_math97;
    int32_t sjt_math98;
    int32_t sjt_math99;

    _return->_refCount = 1;
    sjt_dot85 = _parent;
    sjt_math95 = (sjt_dot85)->w;
    sjt_dot86 = margin;
    sjt_math96 = (sjt_dot86)->l;
    sjt_math93 = sjt_math95 - sjt_math96;
    sjt_dot87 = margin;
    sjt_math94 = (sjt_dot87)->r;
    _return->w = sjt_math93 - sjt_math94;
    sjt_dot88 = _parent;
    sjt_math99 = (sjt_dot88)->h;
    sjt_dot89 = margin;
    sjt_math100 = (sjt_dot89)->t;
    sjt_math97 = sjt_math99 - sjt_math100;
    sjt_dot90 = margin;
    sjt_math98 = (sjt_dot90)->b;
    _return->h = sjt_math97 - sjt_math98;
    sjf_size(_return);
}

void sjf_size_subtractmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    sjs_size* sjt_dot91 = 0;
    sjs_margin* sjt_dot92 = 0;
    sjs_margin* sjt_dot93 = 0;
    sjs_size* sjt_dot94 = 0;
    sjs_margin* sjt_dot95 = 0;
    sjs_margin* sjt_dot96 = 0;
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
    sjt_dot91 = _parent;
    sjt_math103 = (sjt_dot91)->w;
    sjt_dot92 = margin;
    sjt_math104 = (sjt_dot92)->l;
    sjt_math101 = sjt_math103 - sjt_math104;
    sjt_dot93 = margin;
    sjt_math102 = (sjt_dot93)->r;
    (*_return)->w = sjt_math101 - sjt_math102;
    sjt_dot94 = _parent;
    sjt_math107 = (sjt_dot94)->h;
    sjt_dot95 = margin;
    sjt_math108 = (sjt_dot95)->t;
    sjt_math105 = sjt_math107 - sjt_math108;
    sjt_dot96 = margin;
    sjt_math106 = (sjt_dot96)->b;
    (*_return)->h = sjt_math105 - sjt_math106;
    sjf_size_heap((*_return));
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
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

void sjf_testelement_heap(sjs_string* text, sji_element* _return) {
    sjs_textelement* sjt_call10 = 0;
    sjs_filllayout* sjt_call6 = 0;
    sjs_boxelement* sjt_call9 = 0;
    sjs_filllayout* sjt_cast4 = 0;
    sjs_boxelement* sjt_cast5 = 0;
    sjs_textelement* sjt_cast6 = 0;
    sjs_string* sjt_copy20 = 0;
    sjs_color* sjt_copy21 = 0;
    int32_t sjt_functionParam57;
    sji_element sjt_functionParam58 = { 0 };
    int32_t sjt_functionParam63;
    sji_element sjt_functionParam64 = { 0 };
    int32_t sjt_math125;
    int32_t sjt_math126;
    int32_t sjt_math127;
    int32_t sjt_math128;
    int32_t sjt_math129;
    int32_t sjt_math130;
    int32_t sjt_math131;
    int32_t sjt_math132;
    sjs_array_heap_iface_element* sjt_parent48 = 0;
    sjs_array_heap_iface_element* sjt_parent53 = 0;
    sjs_anon2* sjt_parent66 = 0;

    sjt_call6 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
    sjt_call6->_refCount = 1;
    sjt_call6->children._refCount = 1;
    sjt_call6->children.datasize = 2;
    sjt_call6->children.data = 0;
    sjt_call6->children._isglobal = false;
    sjt_call6->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call6->children);
    sjs_array_heap_iface_element* array6;
    array6 = &sjt_call6->children;
    sjt_parent48 = array6;
    sjt_functionParam57 = 0;
    sjt_call9 = (sjs_boxelement*)malloc(sizeof(sjs_boxelement));
    sjt_call9->_refCount = 1;
    sjt_call9->color._refCount = 1;
    sjf_f32_random(&sjt_call9->color.r);
    sjf_f32_random(&sjt_call9->color.g);
    sjf_f32_random(&sjt_call9->color.b);
    sjt_call9->color.a = 1.0f;
    sjf_color(&sjt_call9->color);
    sjt_call9->idealsize._refCount = 1;
    sjf_i32_random(&sjt_math127);
    sjt_math128 = 20;
    sjt_math125 = sjt_math127 % sjt_math128;
    sjt_math126 = 30;
    sjt_call9->idealsize.w = sjt_math125 + sjt_math126;
    sjf_i32_random(&sjt_math131);
    sjt_math132 = 20;
    sjt_math129 = sjt_math131 % sjt_math132;
    sjt_math130 = 30;
    sjt_call9->idealsize.h = sjt_math129 + sjt_math130;
    sjf_size(&sjt_call9->idealsize);
    sjt_call9->rect._refCount = 1;
    sjt_call9->rect.x = 0;
    sjt_call9->rect.y = 0;
    sjt_call9->rect.w = 0;
    sjt_call9->rect.h = 0;
    sjf_rect(&sjt_call9->rect);
    sjt_call9->boxrenderer._refCount = -1;
    sjf_boxelement_heap(sjt_call9);
    sjt_cast5 = sjt_call9;
    sjf_boxelement_as_sji_element(sjt_cast5, &sjt_functionParam58);
    if (sjt_functionParam58._parent != 0) {
        sjt_functionParam58._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent48, sjt_functionParam57, sjt_functionParam58);
    sjt_parent53 = array6;
    sjt_functionParam63 = 1;
    sjt_call10 = (sjs_textelement*)malloc(sizeof(sjs_textelement));
    sjt_call10->_refCount = 1;
    sjt_parent66 = &sjv_style;
    sjf_anon2_getfont_heap(sjt_parent66, &sjt_call10->font);
    sjt_copy20 = text;
    sjt_call10->text._refCount = 1;
    sjf_string_copy(&sjt_call10->text, sjt_copy20);
    sjt_copy21 = &sjv_colors_white;
    sjt_call10->color._refCount = 1;
    sjf_color_copy(&sjt_call10->color, sjt_copy21);
    sjt_call10->margin._refCount = 1;
    sjt_call10->margin.l = 4;
    sjt_call10->margin.t = 4;
    sjt_call10->margin.r = 4;
    sjt_call10->margin.b = 4;
    sjf_margin(&sjt_call10->margin);
    sjt_call10->halign = sjv_texthorizontal_center;
    sjt_call10->valign = sjv_textvertical_center;
    sjt_call10->_rect._refCount = 1;
    sjt_call10->_rect.x = 0;
    sjt_call10->_rect.y = 0;
    sjt_call10->_rect.w = 0;
    sjt_call10->_rect.h = 0;
    sjf_rect(&sjt_call10->_rect);
    sjt_call10->_textrenderer._refCount = -1;
    sjf_textelement_heap(sjt_call10);
    sjt_cast6 = sjt_call10;
    sjf_textelement_as_sji_element(sjt_cast6, &sjt_functionParam64);
    if (sjt_functionParam64._parent != 0) {
        sjt_functionParam64._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent53, sjt_functionParam63, sjt_functionParam64);
    sjt_call6->margin._refCount = 1;
    sjt_call6->margin.l = 0;
    sjt_call6->margin.t = 0;
    sjt_call6->margin.r = 0;
    sjt_call6->margin.b = 0;
    sjf_margin(&sjt_call6->margin);
    sjt_call6->effect._parent = 0;
    sjt_call6->_rect._refCount = 1;
    sjt_call6->_rect.x = 0;
    sjt_call6->_rect.y = 0;
    sjt_call6->_rect.w = 0;
    sjt_call6->_rect.h = 0;
    sjf_rect(&sjt_call6->_rect);
    sjf_filllayout_heap(sjt_call6);
    sjt_cast4 = sjt_call6;
    sjf_filllayout_as_sji_element(sjt_cast4, &(*_return));
    if ((*_return)._parent != 0) {
        (*_return)._parent->_refCount++;
    }

    sjt_call10->_refCount--;
    if (sjt_call10->_refCount <= 0) {
        weakptr_release(sjt_call10);
        sjf_textelement_destroy(sjt_call10);
        free(sjt_call10);
    }
    sjt_call6->_refCount--;
    if (sjt_call6->_refCount <= 0) {
        weakptr_release(sjt_call6);
        sjf_filllayout_destroy(sjt_call6);
        free(sjt_call6);
    }
    sjt_call9->_refCount--;
    if (sjt_call9->_refCount <= 0) {
        weakptr_release(sjt_call9);
        sjf_boxelement_destroy(sjt_call9);
        free(sjt_call9);
    }
    if (sjt_functionParam58._parent != 0) {
        sjt_functionParam58._parent->_refCount--;
        if (sjt_functionParam58._parent->_refCount <= 0) {
            sjt_functionParam58._vtbl->destroy(sjt_functionParam58._parent);
            free(sjt_functionParam58._parent);
        }
    }
    if (sjt_functionParam64._parent != 0) {
        sjt_functionParam64._parent->_refCount--;
        if (sjt_functionParam64._parent->_refCount <= 0) {
            sjt_functionParam64._vtbl->destroy(sjt_functionParam64._parent);
            free(sjt_functionParam64._parent);
        }
    }
}

void sjf_textelement(sjs_textelement* _this) {
}

void sjf_textelement_as_sji_element(sjs_textelement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_textelement_element_vtbl;
}

void sjf_textelement_asinterface(sjs_textelement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_textelement_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_textelement_copy(sjs_textelement* _this, sjs_textelement* _from) {
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
    sjs_rect* sjt_copy12 = 0;
    sjs_textelement* sjt_dot194 = 0;

    sjt_dot194 = _parent;
    sjt_copy12 = &(sjt_dot194)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy12);
}

void sjf_textelement_getrect_heap(sjs_textelement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy13 = 0;
    sjs_textelement* sjt_dot195 = 0;

    sjt_dot195 = _parent;
    sjt_copy13 = &(sjt_dot195)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy13);
}

void sjf_textelement_getsize(sjs_textelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size sjt_call11 = { -1 };
    sjs_textelement* sjt_dot188 = 0;
    sjs_textelement* sjt_dot189 = 0;
    sjs_textelement* sjt_dot190 = 0;
    sjs_string* sjt_functionParam65 = 0;
    sjs_margin* sjt_functionParam66 = 0;
    sjs_size* sjt_functionParam67 = 0;
    sjs_size* sjt_parent54 = 0;
    sjs_font* sjt_parent55 = 0;
    sjs_size* sjt_parent56 = 0;
    sjs_size sjv_textsize = { -1 };

    sjt_dot188 = _parent;
    sjt_parent55 = (sjt_dot188)->font;
    sjt_dot189 = _parent;
    sjt_functionParam65 = &(sjt_dot189)->text;
    sjf_font_gettextsize(sjt_parent55, sjt_functionParam65, &sjt_call11);
    sjt_parent54 = &sjt_call11;
    sjt_dot190 = _parent;
    sjt_functionParam66 = &(sjt_dot190)->margin;
    sjf_size_addmargin(sjt_parent54, sjt_functionParam66, &sjv_textsize);
    sjt_parent56 = &sjv_textsize;
    sjt_functionParam67 = maxsize;
    sjf_size_min(sjt_parent56, sjt_functionParam67, _return);

    if (sjt_call11._refCount == 1) { sjf_size_destroy(&sjt_call11); }
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
}

void sjf_textelement_getsize_heap(sjs_textelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size sjt_call12 = { -1 };
    sjs_textelement* sjt_dot191 = 0;
    sjs_textelement* sjt_dot192 = 0;
    sjs_textelement* sjt_dot193 = 0;
    sjs_string* sjt_functionParam68 = 0;
    sjs_margin* sjt_functionParam69 = 0;
    sjs_size* sjt_functionParam70 = 0;
    sjs_size* sjt_parent57 = 0;
    sjs_font* sjt_parent58 = 0;
    sjs_size* sjt_parent59 = 0;
    sjs_size sjv_textsize = { -1 };

    sjt_dot191 = _parent;
    sjt_parent58 = (sjt_dot191)->font;
    sjt_dot192 = _parent;
    sjt_functionParam68 = &(sjt_dot192)->text;
    sjf_font_gettextsize(sjt_parent58, sjt_functionParam68, &sjt_call12);
    sjt_parent57 = &sjt_call12;
    sjt_dot193 = _parent;
    sjt_functionParam69 = &(sjt_dot193)->margin;
    sjf_size_addmargin(sjt_parent57, sjt_functionParam69, &sjv_textsize);
    sjt_parent59 = &sjv_textsize;
    sjt_functionParam70 = maxsize;
    sjf_size_min_heap(sjt_parent59, sjt_functionParam70, _return);

    if (sjt_call12._refCount == 1) { sjf_size_destroy(&sjt_call12); }
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
}

void sjf_textelement_heap(sjs_textelement* _this) {
}

void sjf_textelement_render(sjs_textelement* _parent, sjs_scene2d* scene) {
    sjs_textelement* sjt_dot199 = 0;
    sjs_textelement* sjt_dot224 = 0;
    bool sjt_ifElse25;
    bool sjt_ifElse26;
    sjs_textrenderer* sjt_isEmpty10 = 0;
    sjs_textrenderer* sjt_isEmpty9 = 0;
    sjs_rect sjv_innerrect = { -1 };
    sjs_size sjv_textsize = { -1 };

    sjt_dot199 = _parent;
    sjt_isEmpty9 = ((sjt_dot199)->_textrenderer._refCount != -1 ? &(sjt_dot199)->_textrenderer : 0);
    sjt_ifElse25 = (sjt_isEmpty9 == 0);
    if (sjt_ifElse25) {
        int32_t sjt_compare49;
        int32_t sjt_compare50;
        int32_t sjt_compare55;
        int32_t sjt_compare56;
        sjs_string* sjt_copy15 = 0;
        sjs_color* sjt_copy16 = 0;
        sjs_font* sjt_copy17 = 0;
        sjs_textelement* sjt_dot200 = 0;
        sjs_textelement* sjt_dot201 = 0;
        sjs_textelement* sjt_dot202 = 0;
        sjs_textelement* sjt_dot203 = 0;
        sjs_textelement* sjt_dot204 = 0;
        sjs_textelement* sjt_dot212 = 0;
        sjs_textelement* sjt_dot220 = 0;
        sjs_textelement* sjt_dot221 = 0;
        sjs_textelement* sjt_dot222 = 0;
        sjs_textelement* sjt_dot223 = 0;
        sjs_string* sjt_functionParam72 = 0;
        sjs_margin* sjt_functionParam73 = 0;
        sjs_font* sjt_parent61 = 0;
        sjs_rect* sjt_parent62 = 0;
        bool sjt_switch1;
        bool sjt_switch4;
        int32_t sjv_x;
        int32_t sjv_y;
        int32_t underscore1;
        int32_t underscore2;

        sjt_dot200 = _parent;
        sjt_parent61 = (sjt_dot200)->font;
        sjt_dot201 = _parent;
        sjt_functionParam72 = &(sjt_dot201)->text;
        sjf_font_gettextsize(sjt_parent61, sjt_functionParam72, &sjv_textsize);
        sjt_dot202 = _parent;
        sjt_parent62 = &(sjt_dot202)->_rect;
        sjt_dot203 = _parent;
        sjt_functionParam73 = &(sjt_dot203)->margin;
        sjf_rect_subtractmargin(sjt_parent62, sjt_functionParam73, &sjv_innerrect);
        sjt_dot204 = _parent;
        underscore1 = (sjt_dot204)->halign;
        sjt_compare49 = underscore1;
        sjt_compare50 = sjv_texthorizontal_left;
        sjt_switch1 = sjt_compare49 == sjt_compare50;
        if (sjt_switch1) {
            sjs_rect* sjt_dot205 = 0;

            sjt_dot205 = &sjv_innerrect;
            sjv_x = (sjt_dot205)->x;
        } else {
            int32_t sjt_compare51;
            int32_t sjt_compare52;
            bool sjt_switch2;

            sjt_compare51 = underscore1;
            sjt_compare52 = sjv_texthorizontal_right;
            sjt_switch2 = sjt_compare51 == sjt_compare52;
            if (sjt_switch2) {
                sjs_rect* sjt_dot206 = 0;
                sjs_rect* sjt_dot207 = 0;
                sjs_size* sjt_dot208 = 0;
                int32_t sjt_math133;
                int32_t sjt_math134;
                int32_t sjt_math135;
                int32_t sjt_math136;

                sjt_dot206 = &sjv_innerrect;
                sjt_math135 = (sjt_dot206)->x;
                sjt_dot207 = &sjv_innerrect;
                sjt_math136 = (sjt_dot207)->w;
                sjt_math133 = sjt_math135 + sjt_math136;
                sjt_dot208 = &sjv_textsize;
                sjt_math134 = (sjt_dot208)->w;
                sjv_x = sjt_math133 - sjt_math134;
            } else {
                int32_t sjt_compare53;
                int32_t sjt_compare54;
                bool sjt_switch3;

                sjt_compare53 = underscore1;
                sjt_compare54 = sjv_texthorizontal_center;
                sjt_switch3 = sjt_compare53 == sjt_compare54;
                if (sjt_switch3) {
                    sjs_rect* sjt_dot209 = 0;
                    sjs_rect* sjt_dot210 = 0;
                    sjs_size* sjt_dot211 = 0;
                    int32_t sjt_math137;
                    int32_t sjt_math138;
                    int32_t sjt_math139;
                    int32_t sjt_math140;
                    int32_t sjt_math141;
                    int32_t sjt_math142;

                    sjt_dot209 = &sjv_innerrect;
                    sjt_math137 = (sjt_dot209)->x;
                    sjt_dot210 = &sjv_innerrect;
                    sjt_math141 = (sjt_dot210)->w;
                    sjt_dot211 = &sjv_textsize;
                    sjt_math142 = (sjt_dot211)->w;
                    sjt_math139 = sjt_math141 - sjt_math142;
                    sjt_math140 = 2;
                    sjt_math138 = sjt_math139 / sjt_math140;
                    sjv_x = sjt_math137 + sjt_math138;
                } else {
                    sjv_x = 0;
                }
            }
        }

        sjt_dot212 = _parent;
        underscore2 = (sjt_dot212)->valign;
        sjt_compare55 = underscore2;
        sjt_compare56 = sjv_textvertical_top;
        sjt_switch4 = sjt_compare55 == sjt_compare56;
        if (sjt_switch4) {
            sjs_rect* sjt_dot213 = 0;

            sjt_dot213 = &sjv_innerrect;
            sjv_y = (sjt_dot213)->y;
        } else {
            int32_t sjt_compare57;
            int32_t sjt_compare58;
            bool sjt_switch5;

            sjt_compare57 = underscore2;
            sjt_compare58 = sjv_textvertical_bottom;
            sjt_switch5 = sjt_compare57 == sjt_compare58;
            if (sjt_switch5) {
                sjs_rect* sjt_dot214 = 0;
                sjs_rect* sjt_dot215 = 0;
                sjs_size* sjt_dot216 = 0;
                int32_t sjt_math143;
                int32_t sjt_math144;
                int32_t sjt_math145;
                int32_t sjt_math146;

                sjt_dot214 = &sjv_innerrect;
                sjt_math145 = (sjt_dot214)->y;
                sjt_dot215 = &sjv_innerrect;
                sjt_math146 = (sjt_dot215)->h;
                sjt_math143 = sjt_math145 + sjt_math146;
                sjt_dot216 = &sjv_textsize;
                sjt_math144 = (sjt_dot216)->h;
                sjv_y = sjt_math143 - sjt_math144;
            } else {
                int32_t sjt_compare59;
                int32_t sjt_compare60;
                bool sjt_switch6;

                sjt_compare59 = underscore2;
                sjt_compare60 = sjv_textvertical_center;
                sjt_switch6 = sjt_compare59 == sjt_compare60;
                if (sjt_switch6) {
                    sjs_rect* sjt_dot217 = 0;
                    sjs_rect* sjt_dot218 = 0;
                    sjs_size* sjt_dot219 = 0;
                    int32_t sjt_math147;
                    int32_t sjt_math148;
                    int32_t sjt_math149;
                    int32_t sjt_math150;
                    int32_t sjt_math151;
                    int32_t sjt_math152;

                    sjt_dot217 = &sjv_innerrect;
                    sjt_math147 = (sjt_dot217)->y;
                    sjt_dot218 = &sjv_innerrect;
                    sjt_math151 = (sjt_dot218)->h;
                    sjt_dot219 = &sjv_textsize;
                    sjt_math152 = (sjt_dot219)->h;
                    sjt_math149 = sjt_math151 - sjt_math152;
                    sjt_math150 = 2;
                    sjt_math148 = sjt_math149 / sjt_math150;
                    sjv_y = sjt_math147 + sjt_math148;
                } else {
                    sjv_y = 0;
                }
            }
        }

        sjt_dot220 = _parent;
        sjt_dot220->_textrenderer._refCount = 1;
        sjt_dot221 = _parent;
        sjt_copy15 = &(sjt_dot221)->text;
        sjt_dot220->_textrenderer.text._refCount = 1;
        sjf_string_copy(&sjt_dot220->_textrenderer.text, sjt_copy15);
        sjt_dot220->_textrenderer.point._refCount = 1;
        sjt_dot220->_textrenderer.point.x = sjv_x;
        sjt_dot220->_textrenderer.point.y = sjv_y;
        sjf_point(&sjt_dot220->_textrenderer.point);
        sjt_dot222 = _parent;
        sjt_copy16 = &(sjt_dot222)->color;
        sjt_dot220->_textrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot220->_textrenderer.color, sjt_copy16);
        sjt_dot223 = _parent;
        sjt_copy17 = (sjt_dot223)->font;
        sjt_dot220->_textrenderer.font._refCount = 1;
        sjf_font_copy(&sjt_dot220->_textrenderer.font, sjt_copy17);
        sjf_textrenderer(&sjt_dot220->_textrenderer);
    }

    sjt_dot224 = _parent;
    sjt_isEmpty10 = ((sjt_dot224)->_textrenderer._refCount != -1 ? &(sjt_dot224)->_textrenderer : 0);
    sjt_ifElse26 = (sjt_isEmpty10 != 0);
    if (sjt_ifElse26) {
        sjs_textelement* sjt_dot228 = 0;
        sjs_scene2d* sjt_functionParam93 = 0;
        sjs_textrenderer* sjt_parent63 = 0;

        sjt_dot228 = _parent;
        sjt_parent63 = ((sjt_dot228)->_textrenderer._refCount != -1 ? &(sjt_dot228)->_textrenderer : 0);
        sjt_functionParam93 = scene;
        sjf_textrenderer_render(sjt_parent63, sjt_functionParam93);
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
}

void sjf_textelement_setrect(sjs_textelement* _parent, sjs_rect* rect_) {
    bool result3;
    sjs_textelement* sjt_dot196 = 0;
    sjs_rect* sjt_functionParam71 = 0;
    bool sjt_ifElse24;
    bool sjt_not2;
    sjs_rect* sjt_parent60 = 0;

    sjt_dot196 = _parent;
    sjt_parent60 = &(sjt_dot196)->_rect;
    sjt_functionParam71 = rect_;
    sjf_rect_isequal(sjt_parent60, sjt_functionParam71, &sjt_not2);
    result3 = !sjt_not2;
    sjt_ifElse24 = result3;
    if (sjt_ifElse24) {
        sjs_rect* sjt_copy14 = 0;
        sjs_textelement* sjt_dot197 = 0;
        sjs_textelement* sjt_dot198 = 0;

        sjt_dot197 = _parent;
        sjt_copy14 = rect_;
        sjt_dot197->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot197->_rect, sjt_copy14);
        sjt_dot198 = _parent;
        sjt_dot198->_textrenderer._refCount = -1;
    }
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
    sjs_string sjt_call13 = { -1 };
    sjs_string sjt_call14 = { -1 };
    sjs_string sjt_call15 = { -1 };
    sjs_string sjt_call16 = { -1 };
    sjs_scene2d* sjt_dot225 = 0;
    sjs_scene2d* sjt_dot226 = 0;
    sjs_scene2d* sjt_dot227 = 0;
    sjs_shader* sjt_functionParam74 = 0;
    int32_t sjt_functionParam75;
    int32_t sjt_functionParam76;
    int32_t sjt_functionParam77;
    sjs_shader* sjt_functionParam78 = 0;
    sjs_string* sjt_functionParam79 = 0;
    int32_t sjt_functionParam80;
    int32_t sjt_functionParam81;
    sjs_shader* sjt_functionParam82 = 0;
    sjs_string* sjt_functionParam83 = 0;
    sjs_mat4* sjt_functionParam84 = 0;
    int32_t sjt_functionParam85;
    sjs_shader* sjt_functionParam86 = 0;
    sjs_string* sjt_functionParam87 = 0;
    sjs_mat4* sjt_functionParam88 = 0;
    int32_t sjt_functionParam89;
    sjs_shader* sjt_functionParam90 = 0;
    sjs_string* sjt_functionParam91 = 0;
    sjs_mat4* sjt_functionParam92 = 0;

    glBindTexture(GL_TEXTURE_2D, _parent->font.atlas->id);
    sjt_functionParam74 = &sjv_textshader;
    sjf_gluseprogram(sjt_functionParam74);
    sjt_functionParam75 = sjv_glblendfunctype_gl_src_alpha;
    sjt_functionParam76 = sjv_glblendfunctype_gl_one_minus_src_alpha;
    sjf_glblendfunc(sjt_functionParam75, sjt_functionParam76);
    sjt_functionParam78 = &sjv_textshader;
    sjt_call13._refCount = 1;
    sjt_call13.count = 7;
    sjt_call13.data._refCount = 1;
    sjt_call13.data.datasize = 8;
    sjt_call13.data.data = (void*)sjg_string22;
    sjt_call13.data._isglobal = true;
    sjt_call13.data.count = 8;
    sjf_array_char(&sjt_call13.data);
    sjf_string(&sjt_call13);
    sjt_functionParam79 = &sjt_call13;
    sjf_glgetuniformlocation(sjt_functionParam78, sjt_functionParam79, &sjt_functionParam77);
    sjt_functionParam80 = 0;
    sjf_gluniformi32(sjt_functionParam77, sjt_functionParam80);
    sjt_functionParam82 = &sjv_textshader;
    sjt_call14._refCount = 1;
    sjt_call14.count = 5;
    sjt_call14.data._refCount = 1;
    sjt_call14.data.datasize = 6;
    sjt_call14.data.data = (void*)sjg_string23;
    sjt_call14.data._isglobal = true;
    sjt_call14.data.count = 6;
    sjf_array_char(&sjt_call14.data);
    sjf_string(&sjt_call14);
    sjt_functionParam83 = &sjt_call14;
    sjf_glgetuniformlocation(sjt_functionParam82, sjt_functionParam83, &sjt_functionParam81);
    sjt_dot225 = scene;
    sjt_functionParam84 = &(sjt_dot225)->model;
    sjf_gluniformmat4(sjt_functionParam81, sjt_functionParam84);
    sjt_functionParam86 = &sjv_textshader;
    sjt_call15._refCount = 1;
    sjt_call15.count = 4;
    sjt_call15.data._refCount = 1;
    sjt_call15.data.datasize = 5;
    sjt_call15.data.data = (void*)sjg_string24;
    sjt_call15.data._isglobal = true;
    sjt_call15.data.count = 5;
    sjf_array_char(&sjt_call15.data);
    sjf_string(&sjt_call15);
    sjt_functionParam87 = &sjt_call15;
    sjf_glgetuniformlocation(sjt_functionParam86, sjt_functionParam87, &sjt_functionParam85);
    sjt_dot226 = scene;
    sjt_functionParam88 = &(sjt_dot226)->view;
    sjf_gluniformmat4(sjt_functionParam85, sjt_functionParam88);
    sjt_functionParam90 = &sjv_textshader;
    sjt_call16._refCount = 1;
    sjt_call16.count = 10;
    sjt_call16.data._refCount = 1;
    sjt_call16.data.datasize = 11;
    sjt_call16.data.data = (void*)sjg_string25;
    sjt_call16.data._isglobal = true;
    sjt_call16.data.count = 11;
    sjf_array_char(&sjt_call16.data);
    sjf_string(&sjt_call16);
    sjt_functionParam91 = &sjt_call16;
    sjf_glgetuniformlocation(sjt_functionParam90, sjt_functionParam91, &sjt_functionParam89);
    sjt_dot227 = scene;
    sjt_functionParam92 = &(sjt_dot227)->projection;
    sjf_gluniformmat4(sjt_functionParam89, sjt_functionParam92);
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);

    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
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
    sjs_borderchild_borderchild_vtbl.destroy = (void(*)(void*))sjf_borderchild_destroy;
    sjs_borderchild_borderchild_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_borderchild_asinterface;
    sjs_borderchild_borderchild_vtbl.getposition = (void(*)(sjs_object*, int32_t*))sjf_borderchild_getposition;
    sjs_borderchild_element_vtbl.destroy = (void(*)(void*))sjf_borderchild_destroy;
    sjs_borderchild_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_borderchild_asinterface;
    sjs_borderchild_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_borderchild_getsize;
    sjs_borderchild_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_borderchild_getsize_heap;
    sjs_borderchild_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_borderchild_getrect;
    sjs_borderchild_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_borderchild_getrect_heap;
    sjs_borderchild_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_borderchild_setrect;
    sjs_borderchild_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_borderchild_render;
    sjs_borderchild_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_borderchild_firemouseevent;
    sjs_borderlayout_element_vtbl.destroy = (void(*)(void*))sjf_borderlayout_destroy;
    sjs_borderlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_borderlayout_asinterface;
    sjs_borderlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_borderlayout_getsize;
    sjs_borderlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_borderlayout_getsize_heap;
    sjs_borderlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_borderlayout_getrect;
    sjs_borderlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_borderlayout_getrect_heap;
    sjs_borderlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_borderlayout_setrect;
    sjs_borderlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_borderlayout_render;
    sjs_borderlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_borderlayout_firemouseevent;
    sjs_boxelement_element_vtbl.destroy = (void(*)(void*))sjf_boxelement_destroy;
    sjs_boxelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_boxelement_asinterface;
    sjs_boxelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_boxelement_getsize;
    sjs_boxelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_boxelement_getsize_heap;
    sjs_boxelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_boxelement_getrect;
    sjs_boxelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_boxelement_getrect_heap;
    sjs_boxelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_boxelement_setrect;
    sjs_boxelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_boxelement_render;
    sjs_boxelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_boxelement_firemouseevent;
    sjs_centerlayout_element_vtbl.destroy = (void(*)(void*))sjf_centerlayout_destroy;
    sjs_centerlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_centerlayout_asinterface;
    sjs_centerlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_centerlayout_getsize;
    sjs_centerlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_centerlayout_getsize_heap;
    sjs_centerlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_centerlayout_getrect;
    sjs_centerlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_centerlayout_getrect_heap;
    sjs_centerlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_centerlayout_setrect;
    sjs_centerlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_centerlayout_render;
    sjs_centerlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_centerlayout_firemouseevent;
    sjs_filllayout_element_vtbl.destroy = (void(*)(void*))sjf_filllayout_destroy;
    sjs_filllayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_filllayout_asinterface;
    sjs_filllayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_filllayout_getsize;
    sjs_filllayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_filllayout_getsize_heap;
    sjs_filllayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_filllayout_getrect;
    sjs_filllayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_filllayout_getrect_heap;
    sjs_filllayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrect;
    sjs_filllayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_render;
    sjs_filllayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_filllayout_firemouseevent;
    sjs_flowlayout_element_vtbl.destroy = (void(*)(void*))sjf_flowlayout_destroy;
    sjs_flowlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_flowlayout_asinterface;
    sjs_flowlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_flowlayout_getsize;
    sjs_flowlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_flowlayout_getsize_heap;
    sjs_flowlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_flowlayout_getrect;
    sjs_flowlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_flowlayout_getrect_heap;
    sjs_flowlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_flowlayout_setrect;
    sjs_flowlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_flowlayout_render;
    sjs_flowlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_flowlayout_firemouseevent;
    sjs_gridlayout_element_vtbl.destroy = (void(*)(void*))sjf_gridlayout_destroy;
    sjs_gridlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_gridlayout_asinterface;
    sjs_gridlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_gridlayout_getsize;
    sjs_gridlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_gridlayout_getsize_heap;
    sjs_gridlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_gridlayout_getrect;
    sjs_gridlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_gridlayout_getrect_heap;
    sjs_gridlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_gridlayout_setrect;
    sjs_gridlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_gridlayout_render;
    sjs_gridlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_gridlayout_firemouseevent;
    sjs_listlayout_element_vtbl.destroy = (void(*)(void*))sjf_listlayout_destroy;
    sjs_listlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_listlayout_asinterface;
    sjs_listlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_listlayout_getsize;
    sjs_listlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_listlayout_getsize_heap;
    sjs_listlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_listlayout_getrect;
    sjs_listlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_listlayout_getrect_heap;
    sjs_listlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_listlayout_setrect;
    sjs_listlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_listlayout_render;
    sjs_listlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_listlayout_firemouseevent;
    sjs_textelement_element_vtbl.destroy = (void(*)(void*))sjf_textelement_destroy;
    sjs_textelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_textelement_asinterface;
    sjs_textelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_textelement_getsize;
    sjs_textelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_textelement_getsize_heap;
    sjs_textelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_textelement_getrect;
    sjs_textelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_textelement_getrect_heap;
    sjs_textelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_textelement_setrect;
    sjs_textelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_textelement_render;
    sjs_textelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_textelement_firemouseevent;
    sjv_borderposition_fill = 0;
    sjv_borderposition_left = 1;
    sjv_borderposition_right = 2;
    sjv_borderposition_top = 3;
    sjv_borderposition_bottom = 4;
    sjv_buttonstate_normal = 0;
    sjv_buttonstate_hot = 1;
    sjv_buttonstate_pressed = 2;
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
    sjv_blurverticalshader.vertex.data.data = (void*)sjg_string3;
    sjv_blurverticalshader.vertex.data._isglobal = true;
    sjv_blurverticalshader.vertex.data.count = 21;
    sjf_array_char(&sjv_blurverticalshader.vertex.data);
    sjf_string(&sjv_blurverticalshader.vertex);
    sjv_blurverticalshader.pixel._refCount = 1;
    sjv_blurverticalshader.pixel.count = 26;
    sjv_blurverticalshader.pixel.data._refCount = 1;
    sjv_blurverticalshader.pixel.data.datasize = 27;
    sjv_blurverticalshader.pixel.data.data = (void*)sjg_string4;
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
    sjv_fadeshader.vertex.data.data = (void*)sjg_string5;
    sjv_fadeshader.vertex.data._isglobal = true;
    sjv_fadeshader.vertex.data.count = 21;
    sjf_array_char(&sjv_fadeshader.vertex.data);
    sjf_string(&sjv_fadeshader.vertex);
    sjv_fadeshader.pixel._refCount = 1;
    sjv_fadeshader.pixel.count = 17;
    sjv_fadeshader.pixel.data._refCount = 1;
    sjv_fadeshader.pixel.data.datasize = 18;
    sjv_fadeshader.pixel.data.data = (void*)sjg_string6;
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
    sjv_boxshader.vertex.data.data = (void*)sjg_string7;
    sjv_boxshader.vertex.data._isglobal = true;
    sjv_boxshader.vertex.data.count = 21;
    sjf_array_char(&sjv_boxshader.vertex.data);
    sjf_string(&sjv_boxshader.vertex);
    sjv_boxshader.pixel._refCount = 1;
    sjv_boxshader.pixel.count = 20;
    sjv_boxshader.pixel.data._refCount = 1;
    sjv_boxshader.pixel.data.datasize = 21;
    sjv_boxshader.pixel.data.data = (void*)sjg_string8;
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
    sjv_imageshader.vertex.data.data = (void*)sjg_string9;
    sjv_imageshader.vertex.data._isglobal = true;
    sjv_imageshader.vertex.data.count = 21;
    sjf_array_char(&sjv_imageshader.vertex.data);
    sjf_string(&sjv_imageshader.vertex);
    sjv_imageshader.pixel._refCount = 1;
    sjv_imageshader.pixel.count = 20;
    sjv_imageshader.pixel.data._refCount = 1;
    sjv_imageshader.pixel.data.datasize = 21;
    sjv_imageshader.pixel.data.data = (void*)sjg_string10;
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
    sjv_phongcolorshader.vertex.data.data = (void*)sjg_string11;
    sjv_phongcolorshader.vertex.data._isglobal = true;
    sjv_phongcolorshader.vertex.data.count = 27;
    sjf_array_char(&sjv_phongcolorshader.vertex.data);
    sjf_string(&sjv_phongcolorshader.vertex);
    sjv_phongcolorshader.pixel._refCount = 1;
    sjv_phongcolorshader.pixel.count = 26;
    sjv_phongcolorshader.pixel.data._refCount = 1;
    sjv_phongcolorshader.pixel.data.datasize = 27;
    sjv_phongcolorshader.pixel.data.data = (void*)sjg_string12;
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
    sjv_phongtextureshader.vertex.data.data = (void*)sjg_string13;
    sjv_phongtextureshader.vertex.data._isglobal = true;
    sjv_phongtextureshader.vertex.data.count = 31;
    sjf_array_char(&sjv_phongtextureshader.vertex.data);
    sjf_string(&sjv_phongtextureshader.vertex);
    sjv_phongtextureshader.pixel._refCount = 1;
    sjv_phongtextureshader.pixel.count = 30;
    sjv_phongtextureshader.pixel.data._refCount = 1;
    sjv_phongtextureshader.pixel.data.datasize = 31;
    sjv_phongtextureshader.pixel.data.data = (void*)sjg_string14;
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
    sjv_textshader.vertex.data.data = (void*)sjg_string15;
    sjv_textshader.vertex.data._isglobal = true;
    sjv_textshader.vertex.data.count = 25;
    sjf_array_char(&sjv_textshader.vertex.data);
    sjf_string(&sjv_textshader.vertex);
    sjv_textshader.pixel._refCount = 1;
    sjv_textshader.pixel.count = 24;
    sjv_textshader.pixel.data._refCount = 1;
    sjv_textshader.pixel.data.datasize = 25;
    sjv_textshader.pixel.data.data = (void*)sjg_string16;
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
    sjv_vertex_location_texture_normal_format.data.data = (void*)sjg_string17;
    sjv_vertex_location_texture_normal_format.data._isglobal = true;
    sjv_vertex_location_texture_normal_format.data.count = 33;
    sjf_array_char(&sjv_vertex_location_texture_normal_format.data);
    sjf_string(&sjv_vertex_location_texture_normal_format);
    sjv_saturateshader._refCount = 1;
    sjv_saturateshader.vertex._refCount = 1;
    sjv_saturateshader.vertex.count = 20;
    sjv_saturateshader.vertex.data._refCount = 1;
    sjv_saturateshader.vertex.data.datasize = 21;
    sjv_saturateshader.vertex.data.data = (void*)sjg_string18;
    sjv_saturateshader.vertex.data._isglobal = true;
    sjv_saturateshader.vertex.data.count = 21;
    sjf_array_char(&sjv_saturateshader.vertex.data);
    sjf_string(&sjv_saturateshader.vertex);
    sjv_saturateshader.pixel._refCount = 1;
    sjv_saturateshader.pixel.count = 21;
    sjv_saturateshader.pixel.data._refCount = 1;
    sjv_saturateshader.pixel.data.datasize = 22;
    sjv_saturateshader.pixel.data.data = (void*)sjg_string19;
    sjv_saturateshader.pixel.data._isglobal = true;
    sjv_saturateshader.pixel.data.count = 22;
    sjf_array_char(&sjv_saturateshader.pixel.data);
    sjf_string(&sjv_saturateshader.pixel);
    sjf_shader(&sjv_saturateshader);
    sjt_call3 = (sjs_gridlayout*)malloc(sizeof(sjs_gridlayout));
    sjt_call3->_refCount = 1;
    sjt_call3->children._refCount = 1;
    sjt_call3->children.datasize = 5;
    sjt_call3->children.data = 0;
    sjt_call3->children._isglobal = false;
    sjt_call3->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call3->children);
    sjs_array_heap_iface_element* array8;
    array8 = &sjt_call3->children;
    sjt_parent28 = array8;
    sjt_functionParam39 = 0;
    sjt_call5 = (sjs_gridlayout*)malloc(sizeof(sjs_gridlayout));
    sjt_call5->_refCount = 1;
    sjt_call5->children._refCount = 1;
    sjt_call5->children.datasize = 4;
    sjt_call5->children.data = 0;
    sjt_call5->children._isglobal = false;
    sjt_call5->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call5->children);
    sjs_array_heap_iface_element* array7;
    array7 = &sjt_call5->children;
    sjt_parent29 = array7;
    sjt_functionParam41 = 0;
    sjt_call18._refCount = 1;
    sjt_call18.count = 1;
    sjt_call18.data._refCount = 1;
    sjt_call18.data.datasize = 2;
    sjt_call18.data.data = (void*)sjg_string30;
    sjt_call18.data._isglobal = true;
    sjt_call18.data.count = 2;
    sjf_array_char(&sjt_call18.data);
    sjf_string(&sjt_call18);
    sjt_functionParam99 = &sjt_call18;
    sjf_testelement_heap(sjt_functionParam99, &sjt_functionParam42);
    sjf_array_heap_iface_element_initat(sjt_parent29, sjt_functionParam41, sjt_functionParam42);
    sjt_parent67 = array7;
    sjt_functionParam100 = 1;
    sjt_call19._refCount = 1;
    sjt_call19.count = 1;
    sjt_call19.data._refCount = 1;
    sjt_call19.data.datasize = 2;
    sjt_call19.data.data = (void*)sjg_string31;
    sjt_call19.data._isglobal = true;
    sjt_call19.data.count = 2;
    sjf_array_char(&sjt_call19.data);
    sjf_string(&sjt_call19);
    sjt_functionParam102 = &sjt_call19;
    sjf_testelement_heap(sjt_functionParam102, &sjt_functionParam101);
    sjf_array_heap_iface_element_initat(sjt_parent67, sjt_functionParam100, sjt_functionParam101);
    sjt_parent68 = array7;
    sjt_functionParam103 = 2;
    sjt_call20._refCount = 1;
    sjt_call20.count = 1;
    sjt_call20.data._refCount = 1;
    sjt_call20.data.datasize = 2;
    sjt_call20.data.data = (void*)sjg_string32;
    sjt_call20.data._isglobal = true;
    sjt_call20.data.count = 2;
    sjf_array_char(&sjt_call20.data);
    sjf_string(&sjt_call20);
    sjt_functionParam105 = &sjt_call20;
    sjf_testelement_heap(sjt_functionParam105, &sjt_functionParam104);
    sjf_array_heap_iface_element_initat(sjt_parent68, sjt_functionParam103, sjt_functionParam104);
    sjt_parent69 = array7;
    sjt_functionParam106 = 3;
    sjt_call21._refCount = 1;
    sjt_call21.count = 1;
    sjt_call21.data._refCount = 1;
    sjt_call21.data.datasize = 2;
    sjt_call21.data.data = (void*)sjg_string33;
    sjt_call21.data._isglobal = true;
    sjt_call21.data.count = 2;
    sjf_array_char(&sjt_call21.data);
    sjf_string(&sjt_call21);
    sjt_functionParam108 = &sjt_call21;
    sjf_testelement_heap(sjt_functionParam108, &sjt_functionParam107);
    sjf_array_heap_iface_element_initat(sjt_parent69, sjt_functionParam106, sjt_functionParam107);
    sjt_call5->margin._refCount = 1;
    sjt_call5->margin.l = 10;
    sjt_call5->margin.t = 10;
    sjt_call5->margin.r = 10;
    sjt_call5->margin.b = 10;
    sjf_margin(&sjt_call5->margin);
    sjt_call5->cols._refCount = 1;
    sjt_call5->cols.datasize = 2;
    sjt_call5->cols.data = 0;
    sjt_call5->cols._isglobal = false;
    sjt_call5->cols.count = 0;
    sjf_array_gridunit(&sjt_call5->cols);
    sjs_array_gridunit* array4;
    array4 = &sjt_call5->cols;
    sjt_parent70 = array4;
    sjt_functionParam109 = 0;
    sjt_call22._refCount = 1;
    sjt_call22.amount = 1;
    sjt_call22.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call22);
    sjt_functionParam110 = &sjt_call22;
    sjf_array_gridunit_initat(sjt_parent70, sjt_functionParam109, sjt_functionParam110);
    sjt_parent71 = array4;
    sjt_functionParam111 = 1;
    sjt_call23._refCount = 1;
    sjt_call23.amount = 50;
    sjt_call23.type = sjv_gridunittype_fixed;
    sjf_gridunit(&sjt_call23);
    sjt_functionParam112 = &sjt_call23;
    sjf_array_gridunit_initat(sjt_parent71, sjt_functionParam111, sjt_functionParam112);
    sjt_call5->rows._refCount = 1;
    sjt_call5->rows.datasize = 2;
    sjt_call5->rows.data = 0;
    sjt_call5->rows._isglobal = false;
    sjt_call5->rows.count = 0;
    sjf_array_gridunit(&sjt_call5->rows);
    sjs_array_gridunit* array3;
    array3 = &sjt_call5->rows;
    sjt_parent72 = array3;
    sjt_functionParam113 = 0;
    sjt_call24._refCount = 1;
    sjt_call24.amount = 50;
    sjt_call24.type = sjv_gridunittype_fixed;
    sjf_gridunit(&sjt_call24);
    sjt_functionParam114 = &sjt_call24;
    sjf_array_gridunit_initat(sjt_parent72, sjt_functionParam113, sjt_functionParam114);
    sjt_parent73 = array3;
    sjt_functionParam115 = 1;
    sjt_call25._refCount = 1;
    sjt_call25.amount = 1;
    sjt_call25.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call25);
    sjt_functionParam116 = &sjt_call25;
    sjf_array_gridunit_initat(sjt_parent73, sjt_functionParam115, sjt_functionParam116);
    sjt_call5->_rect._refCount = 1;
    sjt_call5->_rect.x = 0;
    sjt_call5->_rect.y = 0;
    sjt_call5->_rect.w = 0;
    sjt_call5->_rect.h = 0;
    sjf_rect(&sjt_call5->_rect);
    sjf_gridlayout_heap(sjt_call5);
    sjt_cast3 = sjt_call5;
    sjf_gridlayout_as_sji_element(sjt_cast3, &sjt_functionParam40);
    if (sjt_functionParam40._parent != 0) {
        sjt_functionParam40._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent28, sjt_functionParam39, sjt_functionParam40);
    sjt_parent74 = array8;
    sjt_functionParam117 = 1;
    sjt_call26 = (sjs_borderlayout*)malloc(sizeof(sjs_borderlayout));
    sjt_call26->_refCount = 1;
    sjt_call26->children._refCount = 1;
    sjt_call26->children.datasize = 5;
    sjt_call26->children.data = 0;
    sjt_call26->children._isglobal = false;
    sjt_call26->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call26->children);
    sjs_array_heap_iface_element* array9;
    array9 = &sjt_call26->children;
    sjt_parent91 = array9;
    sjt_functionParam124 = 0;
    sjt_call32 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
    sjt_call32->_refCount = 1;
    sjt_call33._refCount = 1;
    sjt_call33.count = 4;
    sjt_call33.data._refCount = 1;
    sjt_call33.data.datasize = 5;
    sjt_call33.data.data = (void*)sjg_string34;
    sjt_call33.data._isglobal = true;
    sjt_call33.data.count = 5;
    sjf_array_char(&sjt_call33.data);
    sjf_string(&sjt_call33);
    sjt_functionParam126 = &sjt_call33;
    sjf_testelement_heap(sjt_functionParam126, &sjt_call32->child);
    sjt_call32->position = sjv_borderposition_left;
    sjt_call32->_rect._refCount = 1;
    sjt_call32->_rect.x = 0;
    sjt_call32->_rect.y = 0;
    sjt_call32->_rect.w = 0;
    sjt_call32->_rect.h = 0;
    sjf_rect(&sjt_call32->_rect);
    sjf_borderchild_heap(sjt_call32);
    sjt_cast10 = sjt_call32;
    sjf_borderchild_as_sji_element(sjt_cast10, &sjt_functionParam125);
    if (sjt_functionParam125._parent != 0) {
        sjt_functionParam125._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent91, sjt_functionParam124, sjt_functionParam125);
    sjt_parent97 = array9;
    sjt_functionParam127 = 1;
    sjt_call34 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
    sjt_call34->_refCount = 1;
    sjt_call35._refCount = 1;
    sjt_call35.count = 6;
    sjt_call35.data._refCount = 1;
    sjt_call35.data.datasize = 7;
    sjt_call35.data.data = (void*)sjg_string35;
    sjt_call35.data._isglobal = true;
    sjt_call35.data.count = 7;
    sjf_array_char(&sjt_call35.data);
    sjf_string(&sjt_call35);
    sjt_functionParam129 = &sjt_call35;
    sjf_testelement_heap(sjt_functionParam129, &sjt_call34->child);
    sjt_call34->position = sjv_borderposition_bottom;
    sjt_call34->_rect._refCount = 1;
    sjt_call34->_rect.x = 0;
    sjt_call34->_rect.y = 0;
    sjt_call34->_rect.w = 0;
    sjt_call34->_rect.h = 0;
    sjf_rect(&sjt_call34->_rect);
    sjf_borderchild_heap(sjt_call34);
    sjt_cast11 = sjt_call34;
    sjf_borderchild_as_sji_element(sjt_cast11, &sjt_functionParam128);
    if (sjt_functionParam128._parent != 0) {
        sjt_functionParam128._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent97, sjt_functionParam127, sjt_functionParam128);
    sjt_parent98 = array9;
    sjt_functionParam130 = 2;
    sjt_call36 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
    sjt_call36->_refCount = 1;
    sjt_call37._refCount = 1;
    sjt_call37.count = 3;
    sjt_call37.data._refCount = 1;
    sjt_call37.data.datasize = 4;
    sjt_call37.data.data = (void*)sjg_string36;
    sjt_call37.data._isglobal = true;
    sjt_call37.data.count = 4;
    sjf_array_char(&sjt_call37.data);
    sjf_string(&sjt_call37);
    sjt_functionParam132 = &sjt_call37;
    sjf_testelement_heap(sjt_functionParam132, &sjt_call36->child);
    sjt_call36->position = sjv_borderposition_top;
    sjt_call36->_rect._refCount = 1;
    sjt_call36->_rect.x = 0;
    sjt_call36->_rect.y = 0;
    sjt_call36->_rect.w = 0;
    sjt_call36->_rect.h = 0;
    sjf_rect(&sjt_call36->_rect);
    sjf_borderchild_heap(sjt_call36);
    sjt_cast12 = sjt_call36;
    sjf_borderchild_as_sji_element(sjt_cast12, &sjt_functionParam131);
    if (sjt_functionParam131._parent != 0) {
        sjt_functionParam131._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent98, sjt_functionParam130, sjt_functionParam131);
    sjt_parent99 = array9;
    sjt_functionParam133 = 3;
    sjt_call38 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
    sjt_call38->_refCount = 1;
    sjt_call39._refCount = 1;
    sjt_call39.count = 5;
    sjt_call39.data._refCount = 1;
    sjt_call39.data.datasize = 6;
    sjt_call39.data.data = (void*)sjg_string37;
    sjt_call39.data._isglobal = true;
    sjt_call39.data.count = 6;
    sjf_array_char(&sjt_call39.data);
    sjf_string(&sjt_call39);
    sjt_functionParam135 = &sjt_call39;
    sjf_testelement_heap(sjt_functionParam135, &sjt_call38->child);
    sjt_call38->position = sjv_borderposition_right;
    sjt_call38->_rect._refCount = 1;
    sjt_call38->_rect.x = 0;
    sjt_call38->_rect.y = 0;
    sjt_call38->_rect.w = 0;
    sjt_call38->_rect.h = 0;
    sjf_rect(&sjt_call38->_rect);
    sjf_borderchild_heap(sjt_call38);
    sjt_cast13 = sjt_call38;
    sjf_borderchild_as_sji_element(sjt_cast13, &sjt_functionParam134);
    if (sjt_functionParam134._parent != 0) {
        sjt_functionParam134._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent99, sjt_functionParam133, sjt_functionParam134);
    sjt_parent100 = array9;
    sjt_functionParam136 = 4;
    sjt_call40 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
    sjt_call40->_refCount = 1;
    sjt_call41._refCount = 1;
    sjt_call41.count = 4;
    sjt_call41.data._refCount = 1;
    sjt_call41.data.datasize = 5;
    sjt_call41.data.data = (void*)sjg_string38;
    sjt_call41.data._isglobal = true;
    sjt_call41.data.count = 5;
    sjf_array_char(&sjt_call41.data);
    sjf_string(&sjt_call41);
    sjt_functionParam138 = &sjt_call41;
    sjf_testelement_heap(sjt_functionParam138, &sjt_call40->child);
    sjt_call40->position = sjv_borderposition_fill;
    sjt_call40->_rect._refCount = 1;
    sjt_call40->_rect.x = 0;
    sjt_call40->_rect.y = 0;
    sjt_call40->_rect.w = 0;
    sjt_call40->_rect.h = 0;
    sjf_rect(&sjt_call40->_rect);
    sjf_borderchild_heap(sjt_call40);
    sjt_cast14 = sjt_call40;
    sjf_borderchild_as_sji_element(sjt_cast14, &sjt_functionParam137);
    if (sjt_functionParam137._parent != 0) {
        sjt_functionParam137._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent100, sjt_functionParam136, sjt_functionParam137);
    sjt_call26->margin._refCount = 1;
    sjt_call26->margin.l = 10;
    sjt_call26->margin.t = 10;
    sjt_call26->margin.r = 10;
    sjt_call26->margin.b = 10;
    sjf_margin(&sjt_call26->margin);
    sjt_call26->_rect._refCount = 1;
    sjt_call26->_rect.x = 0;
    sjt_call26->_rect.y = 0;
    sjt_call26->_rect.w = 0;
    sjt_call26->_rect.h = 0;
    sjf_rect(&sjt_call26->_rect);
    sjf_borderlayout_heap(sjt_call26);
    sjt_cast7 = sjt_call26;
    sjf_borderlayout_as_sji_element(sjt_cast7, &sjt_functionParam118);
    if (sjt_functionParam118._parent != 0) {
        sjt_functionParam118._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent74, sjt_functionParam117, sjt_functionParam118);
    sjt_parent101 = array8;
    sjt_functionParam139 = 2;
    sjt_call42 = (sjs_listlayout*)malloc(sizeof(sjs_listlayout));
    sjt_call42->_refCount = 1;
    sjt_call42->children._refCount = 1;
    sjt_call42->children.datasize = 4;
    sjt_call42->children.data = 0;
    sjt_call42->children._isglobal = false;
    sjt_call42->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call42->children);
    sjs_array_heap_iface_element* array10;
    array10 = &sjt_call42->children;
    sjt_parent115 = array10;
    sjt_functionParam145 = 0;
    sjt_call51._refCount = 1;
    sjt_call51.count = 1;
    sjt_call51.data._refCount = 1;
    sjt_call51.data.datasize = 2;
    sjt_call51.data.data = (void*)sjg_string39;
    sjt_call51.data._isglobal = true;
    sjt_call51.data.count = 2;
    sjf_array_char(&sjt_call51.data);
    sjf_string(&sjt_call51);
    sjt_functionParam147 = &sjt_call51;
    sjf_testelement_heap(sjt_functionParam147, &sjt_functionParam146);
    sjf_array_heap_iface_element_initat(sjt_parent115, sjt_functionParam145, sjt_functionParam146);
    sjt_parent116 = array10;
    sjt_functionParam148 = 1;
    sjt_call52._refCount = 1;
    sjt_call52.count = 1;
    sjt_call52.data._refCount = 1;
    sjt_call52.data.datasize = 2;
    sjt_call52.data.data = (void*)sjg_string40;
    sjt_call52.data._isglobal = true;
    sjt_call52.data.count = 2;
    sjf_array_char(&sjt_call52.data);
    sjf_string(&sjt_call52);
    sjt_functionParam150 = &sjt_call52;
    sjf_testelement_heap(sjt_functionParam150, &sjt_functionParam149);
    sjf_array_heap_iface_element_initat(sjt_parent116, sjt_functionParam148, sjt_functionParam149);
    sjt_parent117 = array10;
    sjt_functionParam151 = 2;
    sjt_call53._refCount = 1;
    sjt_call53.count = 1;
    sjt_call53.data._refCount = 1;
    sjt_call53.data.datasize = 2;
    sjt_call53.data.data = (void*)sjg_string41;
    sjt_call53.data._isglobal = true;
    sjt_call53.data.count = 2;
    sjf_array_char(&sjt_call53.data);
    sjf_string(&sjt_call53);
    sjt_functionParam153 = &sjt_call53;
    sjf_testelement_heap(sjt_functionParam153, &sjt_functionParam152);
    sjf_array_heap_iface_element_initat(sjt_parent117, sjt_functionParam151, sjt_functionParam152);
    sjt_parent118 = array10;
    sjt_functionParam154 = 3;
    sjt_call54._refCount = 1;
    sjt_call54.count = 1;
    sjt_call54.data._refCount = 1;
    sjt_call54.data.datasize = 2;
    sjt_call54.data.data = (void*)sjg_string42;
    sjt_call54.data._isglobal = true;
    sjt_call54.data.count = 2;
    sjf_array_char(&sjt_call54.data);
    sjf_string(&sjt_call54);
    sjt_functionParam156 = &sjt_call54;
    sjf_testelement_heap(sjt_functionParam156, &sjt_functionParam155);
    sjf_array_heap_iface_element_initat(sjt_parent118, sjt_functionParam154, sjt_functionParam155);
    sjt_call42->margin._refCount = 1;
    sjt_call42->margin.l = 10;
    sjt_call42->margin.t = 10;
    sjt_call42->margin.r = 10;
    sjt_call42->margin.b = 10;
    sjf_margin(&sjt_call42->margin);
    sjt_call42->orientation = sjv_listlayoutorientation_leftright;
    sjt_call42->_rect._refCount = 1;
    sjt_call42->_rect.x = 0;
    sjt_call42->_rect.y = 0;
    sjt_call42->_rect.w = 0;
    sjt_call42->_rect.h = 0;
    sjf_rect(&sjt_call42->_rect);
    sjf_listlayout_heap(sjt_call42);
    sjt_cast15 = sjt_call42;
    sjf_listlayout_as_sji_element(sjt_cast15, &sjt_functionParam140);
    if (sjt_functionParam140._parent != 0) {
        sjt_functionParam140._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent101, sjt_functionParam139, sjt_functionParam140);
    sjt_parent119 = array8;
    sjt_functionParam157 = 3;
    sjt_call55 = (sjs_flowlayout*)malloc(sizeof(sjs_flowlayout));
    sjt_call55->_refCount = 1;
    sjt_call55->children._refCount = 1;
    sjt_call55->children.datasize = 20;
    sjt_call55->children.data = 0;
    sjt_call55->children._isglobal = false;
    sjt_call55->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call55->children);
    sjs_array_heap_iface_element* array11;
    array11 = &sjt_call55->children;
    sjt_parent133 = array11;
    sjt_functionParam171 = 0;
    sjt_call64._refCount = 1;
    sjt_call64.count = 1;
    sjt_call64.data._refCount = 1;
    sjt_call64.data.datasize = 2;
    sjt_call64.data.data = (void*)sjg_string43;
    sjt_call64.data._isglobal = true;
    sjt_call64.data.count = 2;
    sjf_array_char(&sjt_call64.data);
    sjf_string(&sjt_call64);
    sjt_functionParam173 = &sjt_call64;
    sjf_testelement_heap(sjt_functionParam173, &sjt_functionParam172);
    sjf_array_heap_iface_element_initat(sjt_parent133, sjt_functionParam171, sjt_functionParam172);
    sjt_parent134 = array11;
    sjt_functionParam174 = 1;
    sjt_call65._refCount = 1;
    sjt_call65.count = 1;
    sjt_call65.data._refCount = 1;
    sjt_call65.data.datasize = 2;
    sjt_call65.data.data = (void*)sjg_string44;
    sjt_call65.data._isglobal = true;
    sjt_call65.data.count = 2;
    sjf_array_char(&sjt_call65.data);
    sjf_string(&sjt_call65);
    sjt_functionParam176 = &sjt_call65;
    sjf_testelement_heap(sjt_functionParam176, &sjt_functionParam175);
    sjf_array_heap_iface_element_initat(sjt_parent134, sjt_functionParam174, sjt_functionParam175);
    sjt_parent135 = array11;
    sjt_functionParam177 = 2;
    sjt_call66._refCount = 1;
    sjt_call66.count = 1;
    sjt_call66.data._refCount = 1;
    sjt_call66.data.datasize = 2;
    sjt_call66.data.data = (void*)sjg_string45;
    sjt_call66.data._isglobal = true;
    sjt_call66.data.count = 2;
    sjf_array_char(&sjt_call66.data);
    sjf_string(&sjt_call66);
    sjt_functionParam179 = &sjt_call66;
    sjf_testelement_heap(sjt_functionParam179, &sjt_functionParam178);
    sjf_array_heap_iface_element_initat(sjt_parent135, sjt_functionParam177, sjt_functionParam178);
    sjt_parent136 = array11;
    sjt_functionParam180 = 3;
    sjt_call67._refCount = 1;
    sjt_call67.count = 1;
    sjt_call67.data._refCount = 1;
    sjt_call67.data.datasize = 2;
    sjt_call67.data.data = (void*)sjg_string46;
    sjt_call67.data._isglobal = true;
    sjt_call67.data.count = 2;
    sjf_array_char(&sjt_call67.data);
    sjf_string(&sjt_call67);
    sjt_functionParam182 = &sjt_call67;
    sjf_testelement_heap(sjt_functionParam182, &sjt_functionParam181);
    sjf_array_heap_iface_element_initat(sjt_parent136, sjt_functionParam180, sjt_functionParam181);
    sjt_parent137 = array11;
    sjt_functionParam183 = 4;
    sjt_call68._refCount = 1;
    sjt_call68.count = 1;
    sjt_call68.data._refCount = 1;
    sjt_call68.data.datasize = 2;
    sjt_call68.data.data = (void*)sjg_string47;
    sjt_call68.data._isglobal = true;
    sjt_call68.data.count = 2;
    sjf_array_char(&sjt_call68.data);
    sjf_string(&sjt_call68);
    sjt_functionParam185 = &sjt_call68;
    sjf_testelement_heap(sjt_functionParam185, &sjt_functionParam184);
    sjf_array_heap_iface_element_initat(sjt_parent137, sjt_functionParam183, sjt_functionParam184);
    sjt_parent138 = array11;
    sjt_functionParam186 = 5;
    sjt_call69._refCount = 1;
    sjt_call69.count = 1;
    sjt_call69.data._refCount = 1;
    sjt_call69.data.datasize = 2;
    sjt_call69.data.data = (void*)sjg_string48;
    sjt_call69.data._isglobal = true;
    sjt_call69.data.count = 2;
    sjf_array_char(&sjt_call69.data);
    sjf_string(&sjt_call69);
    sjt_functionParam188 = &sjt_call69;
    sjf_testelement_heap(sjt_functionParam188, &sjt_functionParam187);
    sjf_array_heap_iface_element_initat(sjt_parent138, sjt_functionParam186, sjt_functionParam187);
    sjt_parent139 = array11;
    sjt_functionParam189 = 6;
    sjt_call70._refCount = 1;
    sjt_call70.count = 1;
    sjt_call70.data._refCount = 1;
    sjt_call70.data.datasize = 2;
    sjt_call70.data.data = (void*)sjg_string49;
    sjt_call70.data._isglobal = true;
    sjt_call70.data.count = 2;
    sjf_array_char(&sjt_call70.data);
    sjf_string(&sjt_call70);
    sjt_functionParam191 = &sjt_call70;
    sjf_testelement_heap(sjt_functionParam191, &sjt_functionParam190);
    sjf_array_heap_iface_element_initat(sjt_parent139, sjt_functionParam189, sjt_functionParam190);
    sjt_parent140 = array11;
    sjt_functionParam192 = 7;
    sjt_call71._refCount = 1;
    sjt_call71.count = 1;
    sjt_call71.data._refCount = 1;
    sjt_call71.data.datasize = 2;
    sjt_call71.data.data = (void*)sjg_string50;
    sjt_call71.data._isglobal = true;
    sjt_call71.data.count = 2;
    sjf_array_char(&sjt_call71.data);
    sjf_string(&sjt_call71);
    sjt_functionParam194 = &sjt_call71;
    sjf_testelement_heap(sjt_functionParam194, &sjt_functionParam193);
    sjf_array_heap_iface_element_initat(sjt_parent140, sjt_functionParam192, sjt_functionParam193);
    sjt_parent141 = array11;
    sjt_functionParam195 = 8;
    sjt_call72._refCount = 1;
    sjt_call72.count = 1;
    sjt_call72.data._refCount = 1;
    sjt_call72.data.datasize = 2;
    sjt_call72.data.data = (void*)sjg_string51;
    sjt_call72.data._isglobal = true;
    sjt_call72.data.count = 2;
    sjf_array_char(&sjt_call72.data);
    sjf_string(&sjt_call72);
    sjt_functionParam197 = &sjt_call72;
    sjf_testelement_heap(sjt_functionParam197, &sjt_functionParam196);
    sjf_array_heap_iface_element_initat(sjt_parent141, sjt_functionParam195, sjt_functionParam196);
    sjt_parent142 = array11;
    sjt_functionParam198 = 9;
    sjt_call73._refCount = 1;
    sjt_call73.count = 1;
    sjt_call73.data._refCount = 1;
    sjt_call73.data.datasize = 2;
    sjt_call73.data.data = (void*)sjg_string52;
    sjt_call73.data._isglobal = true;
    sjt_call73.data.count = 2;
    sjf_array_char(&sjt_call73.data);
    sjf_string(&sjt_call73);
    sjt_functionParam200 = &sjt_call73;
    sjf_testelement_heap(sjt_functionParam200, &sjt_functionParam199);
    sjf_array_heap_iface_element_initat(sjt_parent142, sjt_functionParam198, sjt_functionParam199);
    sjt_parent143 = array11;
    sjt_functionParam201 = 10;
    sjt_call74._refCount = 1;
    sjt_call74.count = 1;
    sjt_call74.data._refCount = 1;
    sjt_call74.data.datasize = 2;
    sjt_call74.data.data = (void*)sjg_string53;
    sjt_call74.data._isglobal = true;
    sjt_call74.data.count = 2;
    sjf_array_char(&sjt_call74.data);
    sjf_string(&sjt_call74);
    sjt_functionParam203 = &sjt_call74;
    sjf_testelement_heap(sjt_functionParam203, &sjt_functionParam202);
    sjf_array_heap_iface_element_initat(sjt_parent143, sjt_functionParam201, sjt_functionParam202);
    sjt_parent144 = array11;
    sjt_functionParam204 = 11;
    sjt_call75._refCount = 1;
    sjt_call75.count = 1;
    sjt_call75.data._refCount = 1;
    sjt_call75.data.datasize = 2;
    sjt_call75.data.data = (void*)sjg_string54;
    sjt_call75.data._isglobal = true;
    sjt_call75.data.count = 2;
    sjf_array_char(&sjt_call75.data);
    sjf_string(&sjt_call75);
    sjt_functionParam206 = &sjt_call75;
    sjf_testelement_heap(sjt_functionParam206, &sjt_functionParam205);
    sjf_array_heap_iface_element_initat(sjt_parent144, sjt_functionParam204, sjt_functionParam205);
    sjt_parent145 = array11;
    sjt_functionParam207 = 12;
    sjt_call76._refCount = 1;
    sjt_call76.count = 1;
    sjt_call76.data._refCount = 1;
    sjt_call76.data.datasize = 2;
    sjt_call76.data.data = (void*)sjg_string55;
    sjt_call76.data._isglobal = true;
    sjt_call76.data.count = 2;
    sjf_array_char(&sjt_call76.data);
    sjf_string(&sjt_call76);
    sjt_functionParam209 = &sjt_call76;
    sjf_testelement_heap(sjt_functionParam209, &sjt_functionParam208);
    sjf_array_heap_iface_element_initat(sjt_parent145, sjt_functionParam207, sjt_functionParam208);
    sjt_parent146 = array11;
    sjt_functionParam210 = 13;
    sjt_call77._refCount = 1;
    sjt_call77.count = 1;
    sjt_call77.data._refCount = 1;
    sjt_call77.data.datasize = 2;
    sjt_call77.data.data = (void*)sjg_string56;
    sjt_call77.data._isglobal = true;
    sjt_call77.data.count = 2;
    sjf_array_char(&sjt_call77.data);
    sjf_string(&sjt_call77);
    sjt_functionParam212 = &sjt_call77;
    sjf_testelement_heap(sjt_functionParam212, &sjt_functionParam211);
    sjf_array_heap_iface_element_initat(sjt_parent146, sjt_functionParam210, sjt_functionParam211);
    sjt_parent147 = array11;
    sjt_functionParam213 = 14;
    sjt_call78._refCount = 1;
    sjt_call78.count = 1;
    sjt_call78.data._refCount = 1;
    sjt_call78.data.datasize = 2;
    sjt_call78.data.data = (void*)sjg_string57;
    sjt_call78.data._isglobal = true;
    sjt_call78.data.count = 2;
    sjf_array_char(&sjt_call78.data);
    sjf_string(&sjt_call78);
    sjt_functionParam215 = &sjt_call78;
    sjf_testelement_heap(sjt_functionParam215, &sjt_functionParam214);
    sjf_array_heap_iface_element_initat(sjt_parent147, sjt_functionParam213, sjt_functionParam214);
    sjt_parent148 = array11;
    sjt_functionParam216 = 15;
    sjt_call79._refCount = 1;
    sjt_call79.count = 1;
    sjt_call79.data._refCount = 1;
    sjt_call79.data.datasize = 2;
    sjt_call79.data.data = (void*)sjg_string58;
    sjt_call79.data._isglobal = true;
    sjt_call79.data.count = 2;
    sjf_array_char(&sjt_call79.data);
    sjf_string(&sjt_call79);
    sjt_functionParam218 = &sjt_call79;
    sjf_testelement_heap(sjt_functionParam218, &sjt_functionParam217);
    sjf_array_heap_iface_element_initat(sjt_parent148, sjt_functionParam216, sjt_functionParam217);
    sjt_parent149 = array11;
    sjt_functionParam219 = 16;
    sjt_call80._refCount = 1;
    sjt_call80.count = 1;
    sjt_call80.data._refCount = 1;
    sjt_call80.data.datasize = 2;
    sjt_call80.data.data = (void*)sjg_string59;
    sjt_call80.data._isglobal = true;
    sjt_call80.data.count = 2;
    sjf_array_char(&sjt_call80.data);
    sjf_string(&sjt_call80);
    sjt_functionParam221 = &sjt_call80;
    sjf_testelement_heap(sjt_functionParam221, &sjt_functionParam220);
    sjf_array_heap_iface_element_initat(sjt_parent149, sjt_functionParam219, sjt_functionParam220);
    sjt_parent150 = array11;
    sjt_functionParam222 = 17;
    sjt_call81._refCount = 1;
    sjt_call81.count = 1;
    sjt_call81.data._refCount = 1;
    sjt_call81.data.datasize = 2;
    sjt_call81.data.data = (void*)sjg_string60;
    sjt_call81.data._isglobal = true;
    sjt_call81.data.count = 2;
    sjf_array_char(&sjt_call81.data);
    sjf_string(&sjt_call81);
    sjt_functionParam224 = &sjt_call81;
    sjf_testelement_heap(sjt_functionParam224, &sjt_functionParam223);
    sjf_array_heap_iface_element_initat(sjt_parent150, sjt_functionParam222, sjt_functionParam223);
    sjt_parent151 = array11;
    sjt_functionParam225 = 18;
    sjt_call82._refCount = 1;
    sjt_call82.count = 1;
    sjt_call82.data._refCount = 1;
    sjt_call82.data.datasize = 2;
    sjt_call82.data.data = (void*)sjg_string61;
    sjt_call82.data._isglobal = true;
    sjt_call82.data.count = 2;
    sjf_array_char(&sjt_call82.data);
    sjf_string(&sjt_call82);
    sjt_functionParam227 = &sjt_call82;
    sjf_testelement_heap(sjt_functionParam227, &sjt_functionParam226);
    sjf_array_heap_iface_element_initat(sjt_parent151, sjt_functionParam225, sjt_functionParam226);
    sjt_parent152 = array11;
    sjt_functionParam228 = 19;
    sjt_call83._refCount = 1;
    sjt_call83.count = 1;
    sjt_call83.data._refCount = 1;
    sjt_call83.data.datasize = 2;
    sjt_call83.data.data = (void*)sjg_string62;
    sjt_call83.data._isglobal = true;
    sjt_call83.data.count = 2;
    sjf_array_char(&sjt_call83.data);
    sjf_string(&sjt_call83);
    sjt_functionParam230 = &sjt_call83;
    sjf_testelement_heap(sjt_functionParam230, &sjt_functionParam229);
    sjf_array_heap_iface_element_initat(sjt_parent152, sjt_functionParam228, sjt_functionParam229);
    sjt_call55->margin._refCount = 1;
    sjt_call55->margin.l = 10;
    sjt_call55->margin.t = 10;
    sjt_call55->margin.r = 10;
    sjt_call55->margin.b = 10;
    sjf_margin(&sjt_call55->margin);
    sjt_call55->orientation = sjv_flowlayoutorientation_leftright;
    sjt_call55->_rect._refCount = 1;
    sjt_call55->_rect.x = 0;
    sjt_call55->_rect.y = 0;
    sjt_call55->_rect.w = 0;
    sjt_call55->_rect.h = 0;
    sjf_rect(&sjt_call55->_rect);
    sjf_flowlayout_heap(sjt_call55);
    sjt_cast16 = sjt_call55;
    sjf_flowlayout_as_sji_element(sjt_cast16, &sjt_functionParam158);
    if (sjt_functionParam158._parent != 0) {
        sjt_functionParam158._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent119, sjt_functionParam157, sjt_functionParam158);
    sjt_parent153 = array8;
    sjt_functionParam231 = 4;
    sjt_call84 = (sjs_centerlayout*)malloc(sizeof(sjs_centerlayout));
    sjt_call84->_refCount = 1;
    sjt_call84->children._refCount = 1;
    sjt_call84->children.datasize = 1;
    sjt_call84->children.data = 0;
    sjt_call84->children._isglobal = false;
    sjt_call84->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call84->children);
    sjs_array_heap_iface_element* array12;
    array12 = &sjt_call84->children;
    sjt_parent171 = array12;
    sjt_functionParam245 = 0;
    sjt_call89._refCount = 1;
    sjt_call89.count = 1;
    sjt_call89.data._refCount = 1;
    sjt_call89.data.datasize = 2;
    sjt_call89.data.data = (void*)sjg_string63;
    sjt_call89.data._isglobal = true;
    sjt_call89.data.count = 2;
    sjf_array_char(&sjt_call89.data);
    sjf_string(&sjt_call89);
    sjt_functionParam247 = &sjt_call89;
    sjf_testelement_heap(sjt_functionParam247, &sjt_functionParam246);
    sjf_array_heap_iface_element_initat(sjt_parent171, sjt_functionParam245, sjt_functionParam246);
    sjt_call84->margin._refCount = 1;
    sjt_call84->margin.l = 10;
    sjt_call84->margin.t = 10;
    sjt_call84->margin.r = 10;
    sjt_call84->margin.b = 10;
    sjf_margin(&sjt_call84->margin);
    sjt_value5 = 0.2f;
    value5.isvalid = true;
    value5.value = sjt_value5;
    sjt_call84->centerx = value5;
    sjt_value6 = 0.8f;
    value6.isvalid = true;
    value6.value = sjt_value6;
    sjt_call84->centery = value6;
    sjt_call84->_rect._refCount = 1;
    sjt_call84->_rect.x = 0;
    sjt_call84->_rect.y = 0;
    sjt_call84->_rect.w = 0;
    sjt_call84->_rect.h = 0;
    sjf_rect(&sjt_call84->_rect);
    sjf_centerlayout_heap(sjt_call84);
    sjt_cast17 = sjt_call84;
    sjf_centerlayout_as_sji_element(sjt_cast17, &sjt_functionParam232);
    if (sjt_functionParam232._parent != 0) {
        sjt_functionParam232._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent153, sjt_functionParam231, sjt_functionParam232);
    sjt_call3->margin._refCount = 1;
    sjt_call3->margin.l = 0;
    sjt_call3->margin.t = 0;
    sjt_call3->margin.r = 0;
    sjt_call3->margin.b = 0;
    sjf_margin(&sjt_call3->margin);
    sjt_call3->cols._refCount = 1;
    sjt_call3->cols.datasize = 3;
    sjt_call3->cols.data = 0;
    sjt_call3->cols._isglobal = false;
    sjt_call3->cols.count = 0;
    sjf_array_gridunit(&sjt_call3->cols);
    sjs_array_gridunit* array1;
    array1 = &sjt_call3->cols;
    sjt_parent172 = array1;
    sjt_functionParam248 = 0;
    sjt_call90._refCount = 1;
    sjt_call90.amount = 1;
    sjt_call90.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call90);
    sjt_functionParam249 = &sjt_call90;
    sjf_array_gridunit_initat(sjt_parent172, sjt_functionParam248, sjt_functionParam249);
    sjt_parent173 = array1;
    sjt_functionParam250 = 1;
    sjt_call91._refCount = 1;
    sjt_call91.amount = 1;
    sjt_call91.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call91);
    sjt_functionParam251 = &sjt_call91;
    sjf_array_gridunit_initat(sjt_parent173, sjt_functionParam250, sjt_functionParam251);
    sjt_parent174 = array1;
    sjt_functionParam252 = 2;
    sjt_call92._refCount = 1;
    sjt_call92.amount = 1;
    sjt_call92.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call92);
    sjt_functionParam253 = &sjt_call92;
    sjf_array_gridunit_initat(sjt_parent174, sjt_functionParam252, sjt_functionParam253);
    sjt_call3->rows._refCount = 1;
    sjt_call3->rows.datasize = 2;
    sjt_call3->rows.data = 0;
    sjt_call3->rows._isglobal = false;
    sjt_call3->rows.count = 0;
    sjf_array_gridunit(&sjt_call3->rows);
    sjs_array_gridunit* array2;
    array2 = &sjt_call3->rows;
    sjt_parent175 = array2;
    sjt_functionParam254 = 0;
    sjt_call93._refCount = 1;
    sjt_call93.amount = 1;
    sjt_call93.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call93);
    sjt_functionParam255 = &sjt_call93;
    sjf_array_gridunit_initat(sjt_parent175, sjt_functionParam254, sjt_functionParam255);
    sjt_parent176 = array2;
    sjt_functionParam256 = 1;
    sjt_call94._refCount = 1;
    sjt_call94.amount = 1;
    sjt_call94.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call94);
    sjt_functionParam257 = &sjt_call94;
    sjf_array_gridunit_initat(sjt_parent176, sjt_functionParam256, sjt_functionParam257);
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

    sjt_call26->_refCount--;
    if (sjt_call26->_refCount <= 0) {
        weakptr_release(sjt_call26);
        sjf_borderlayout_destroy(sjt_call26);
        free(sjt_call26);
    }
    sjt_call3->_refCount--;
    if (sjt_call3->_refCount <= 0) {
        weakptr_release(sjt_call3);
        sjf_gridlayout_destroy(sjt_call3);
        free(sjt_call3);
    }
    sjt_call32->_refCount--;
    if (sjt_call32->_refCount <= 0) {
        weakptr_release(sjt_call32);
        sjf_borderchild_destroy(sjt_call32);
        free(sjt_call32);
    }
    sjt_call34->_refCount--;
    if (sjt_call34->_refCount <= 0) {
        weakptr_release(sjt_call34);
        sjf_borderchild_destroy(sjt_call34);
        free(sjt_call34);
    }
    sjt_call36->_refCount--;
    if (sjt_call36->_refCount <= 0) {
        weakptr_release(sjt_call36);
        sjf_borderchild_destroy(sjt_call36);
        free(sjt_call36);
    }
    sjt_call38->_refCount--;
    if (sjt_call38->_refCount <= 0) {
        weakptr_release(sjt_call38);
        sjf_borderchild_destroy(sjt_call38);
        free(sjt_call38);
    }
    sjt_call40->_refCount--;
    if (sjt_call40->_refCount <= 0) {
        weakptr_release(sjt_call40);
        sjf_borderchild_destroy(sjt_call40);
        free(sjt_call40);
    }
    sjt_call42->_refCount--;
    if (sjt_call42->_refCount <= 0) {
        weakptr_release(sjt_call42);
        sjf_listlayout_destroy(sjt_call42);
        free(sjt_call42);
    }
    sjt_call5->_refCount--;
    if (sjt_call5->_refCount <= 0) {
        weakptr_release(sjt_call5);
        sjf_gridlayout_destroy(sjt_call5);
        free(sjt_call5);
    }
    sjt_call55->_refCount--;
    if (sjt_call55->_refCount <= 0) {
        weakptr_release(sjt_call55);
        sjf_flowlayout_destroy(sjt_call55);
        free(sjt_call55);
    }
    sjt_call84->_refCount--;
    if (sjt_call84->_refCount <= 0) {
        weakptr_release(sjt_call84);
        sjf_centerlayout_destroy(sjt_call84);
        free(sjt_call84);
    }
    if (sjt_functionParam101._parent != 0) {
        sjt_functionParam101._parent->_refCount--;
        if (sjt_functionParam101._parent->_refCount <= 0) {
            sjt_functionParam101._vtbl->destroy(sjt_functionParam101._parent);
            free(sjt_functionParam101._parent);
        }
    }
    if (sjt_functionParam104._parent != 0) {
        sjt_functionParam104._parent->_refCount--;
        if (sjt_functionParam104._parent->_refCount <= 0) {
            sjt_functionParam104._vtbl->destroy(sjt_functionParam104._parent);
            free(sjt_functionParam104._parent);
        }
    }
    if (sjt_functionParam107._parent != 0) {
        sjt_functionParam107._parent->_refCount--;
        if (sjt_functionParam107._parent->_refCount <= 0) {
            sjt_functionParam107._vtbl->destroy(sjt_functionParam107._parent);
            free(sjt_functionParam107._parent);
        }
    }
    if (sjt_functionParam118._parent != 0) {
        sjt_functionParam118._parent->_refCount--;
        if (sjt_functionParam118._parent->_refCount <= 0) {
            sjt_functionParam118._vtbl->destroy(sjt_functionParam118._parent);
            free(sjt_functionParam118._parent);
        }
    }
    if (sjt_functionParam125._parent != 0) {
        sjt_functionParam125._parent->_refCount--;
        if (sjt_functionParam125._parent->_refCount <= 0) {
            sjt_functionParam125._vtbl->destroy(sjt_functionParam125._parent);
            free(sjt_functionParam125._parent);
        }
    }
    if (sjt_functionParam128._parent != 0) {
        sjt_functionParam128._parent->_refCount--;
        if (sjt_functionParam128._parent->_refCount <= 0) {
            sjt_functionParam128._vtbl->destroy(sjt_functionParam128._parent);
            free(sjt_functionParam128._parent);
        }
    }
    if (sjt_functionParam131._parent != 0) {
        sjt_functionParam131._parent->_refCount--;
        if (sjt_functionParam131._parent->_refCount <= 0) {
            sjt_functionParam131._vtbl->destroy(sjt_functionParam131._parent);
            free(sjt_functionParam131._parent);
        }
    }
    if (sjt_functionParam134._parent != 0) {
        sjt_functionParam134._parent->_refCount--;
        if (sjt_functionParam134._parent->_refCount <= 0) {
            sjt_functionParam134._vtbl->destroy(sjt_functionParam134._parent);
            free(sjt_functionParam134._parent);
        }
    }
    if (sjt_functionParam137._parent != 0) {
        sjt_functionParam137._parent->_refCount--;
        if (sjt_functionParam137._parent->_refCount <= 0) {
            sjt_functionParam137._vtbl->destroy(sjt_functionParam137._parent);
            free(sjt_functionParam137._parent);
        }
    }
    if (sjt_functionParam140._parent != 0) {
        sjt_functionParam140._parent->_refCount--;
        if (sjt_functionParam140._parent->_refCount <= 0) {
            sjt_functionParam140._vtbl->destroy(sjt_functionParam140._parent);
            free(sjt_functionParam140._parent);
        }
    }
    if (sjt_functionParam146._parent != 0) {
        sjt_functionParam146._parent->_refCount--;
        if (sjt_functionParam146._parent->_refCount <= 0) {
            sjt_functionParam146._vtbl->destroy(sjt_functionParam146._parent);
            free(sjt_functionParam146._parent);
        }
    }
    if (sjt_functionParam149._parent != 0) {
        sjt_functionParam149._parent->_refCount--;
        if (sjt_functionParam149._parent->_refCount <= 0) {
            sjt_functionParam149._vtbl->destroy(sjt_functionParam149._parent);
            free(sjt_functionParam149._parent);
        }
    }
    if (sjt_functionParam152._parent != 0) {
        sjt_functionParam152._parent->_refCount--;
        if (sjt_functionParam152._parent->_refCount <= 0) {
            sjt_functionParam152._vtbl->destroy(sjt_functionParam152._parent);
            free(sjt_functionParam152._parent);
        }
    }
    if (sjt_functionParam155._parent != 0) {
        sjt_functionParam155._parent->_refCount--;
        if (sjt_functionParam155._parent->_refCount <= 0) {
            sjt_functionParam155._vtbl->destroy(sjt_functionParam155._parent);
            free(sjt_functionParam155._parent);
        }
    }
    if (sjt_functionParam158._parent != 0) {
        sjt_functionParam158._parent->_refCount--;
        if (sjt_functionParam158._parent->_refCount <= 0) {
            sjt_functionParam158._vtbl->destroy(sjt_functionParam158._parent);
            free(sjt_functionParam158._parent);
        }
    }
    if (sjt_functionParam172._parent != 0) {
        sjt_functionParam172._parent->_refCount--;
        if (sjt_functionParam172._parent->_refCount <= 0) {
            sjt_functionParam172._vtbl->destroy(sjt_functionParam172._parent);
            free(sjt_functionParam172._parent);
        }
    }
    if (sjt_functionParam175._parent != 0) {
        sjt_functionParam175._parent->_refCount--;
        if (sjt_functionParam175._parent->_refCount <= 0) {
            sjt_functionParam175._vtbl->destroy(sjt_functionParam175._parent);
            free(sjt_functionParam175._parent);
        }
    }
    if (sjt_functionParam178._parent != 0) {
        sjt_functionParam178._parent->_refCount--;
        if (sjt_functionParam178._parent->_refCount <= 0) {
            sjt_functionParam178._vtbl->destroy(sjt_functionParam178._parent);
            free(sjt_functionParam178._parent);
        }
    }
    if (sjt_functionParam181._parent != 0) {
        sjt_functionParam181._parent->_refCount--;
        if (sjt_functionParam181._parent->_refCount <= 0) {
            sjt_functionParam181._vtbl->destroy(sjt_functionParam181._parent);
            free(sjt_functionParam181._parent);
        }
    }
    if (sjt_functionParam184._parent != 0) {
        sjt_functionParam184._parent->_refCount--;
        if (sjt_functionParam184._parent->_refCount <= 0) {
            sjt_functionParam184._vtbl->destroy(sjt_functionParam184._parent);
            free(sjt_functionParam184._parent);
        }
    }
    if (sjt_functionParam187._parent != 0) {
        sjt_functionParam187._parent->_refCount--;
        if (sjt_functionParam187._parent->_refCount <= 0) {
            sjt_functionParam187._vtbl->destroy(sjt_functionParam187._parent);
            free(sjt_functionParam187._parent);
        }
    }
    if (sjt_functionParam190._parent != 0) {
        sjt_functionParam190._parent->_refCount--;
        if (sjt_functionParam190._parent->_refCount <= 0) {
            sjt_functionParam190._vtbl->destroy(sjt_functionParam190._parent);
            free(sjt_functionParam190._parent);
        }
    }
    if (sjt_functionParam193._parent != 0) {
        sjt_functionParam193._parent->_refCount--;
        if (sjt_functionParam193._parent->_refCount <= 0) {
            sjt_functionParam193._vtbl->destroy(sjt_functionParam193._parent);
            free(sjt_functionParam193._parent);
        }
    }
    if (sjt_functionParam196._parent != 0) {
        sjt_functionParam196._parent->_refCount--;
        if (sjt_functionParam196._parent->_refCount <= 0) {
            sjt_functionParam196._vtbl->destroy(sjt_functionParam196._parent);
            free(sjt_functionParam196._parent);
        }
    }
    if (sjt_functionParam199._parent != 0) {
        sjt_functionParam199._parent->_refCount--;
        if (sjt_functionParam199._parent->_refCount <= 0) {
            sjt_functionParam199._vtbl->destroy(sjt_functionParam199._parent);
            free(sjt_functionParam199._parent);
        }
    }
    if (sjt_functionParam202._parent != 0) {
        sjt_functionParam202._parent->_refCount--;
        if (sjt_functionParam202._parent->_refCount <= 0) {
            sjt_functionParam202._vtbl->destroy(sjt_functionParam202._parent);
            free(sjt_functionParam202._parent);
        }
    }
    if (sjt_functionParam205._parent != 0) {
        sjt_functionParam205._parent->_refCount--;
        if (sjt_functionParam205._parent->_refCount <= 0) {
            sjt_functionParam205._vtbl->destroy(sjt_functionParam205._parent);
            free(sjt_functionParam205._parent);
        }
    }
    if (sjt_functionParam208._parent != 0) {
        sjt_functionParam208._parent->_refCount--;
        if (sjt_functionParam208._parent->_refCount <= 0) {
            sjt_functionParam208._vtbl->destroy(sjt_functionParam208._parent);
            free(sjt_functionParam208._parent);
        }
    }
    if (sjt_functionParam211._parent != 0) {
        sjt_functionParam211._parent->_refCount--;
        if (sjt_functionParam211._parent->_refCount <= 0) {
            sjt_functionParam211._vtbl->destroy(sjt_functionParam211._parent);
            free(sjt_functionParam211._parent);
        }
    }
    if (sjt_functionParam214._parent != 0) {
        sjt_functionParam214._parent->_refCount--;
        if (sjt_functionParam214._parent->_refCount <= 0) {
            sjt_functionParam214._vtbl->destroy(sjt_functionParam214._parent);
            free(sjt_functionParam214._parent);
        }
    }
    if (sjt_functionParam217._parent != 0) {
        sjt_functionParam217._parent->_refCount--;
        if (sjt_functionParam217._parent->_refCount <= 0) {
            sjt_functionParam217._vtbl->destroy(sjt_functionParam217._parent);
            free(sjt_functionParam217._parent);
        }
    }
    if (sjt_functionParam220._parent != 0) {
        sjt_functionParam220._parent->_refCount--;
        if (sjt_functionParam220._parent->_refCount <= 0) {
            sjt_functionParam220._vtbl->destroy(sjt_functionParam220._parent);
            free(sjt_functionParam220._parent);
        }
    }
    if (sjt_functionParam223._parent != 0) {
        sjt_functionParam223._parent->_refCount--;
        if (sjt_functionParam223._parent->_refCount <= 0) {
            sjt_functionParam223._vtbl->destroy(sjt_functionParam223._parent);
            free(sjt_functionParam223._parent);
        }
    }
    if (sjt_functionParam226._parent != 0) {
        sjt_functionParam226._parent->_refCount--;
        if (sjt_functionParam226._parent->_refCount <= 0) {
            sjt_functionParam226._vtbl->destroy(sjt_functionParam226._parent);
            free(sjt_functionParam226._parent);
        }
    }
    if (sjt_functionParam229._parent != 0) {
        sjt_functionParam229._parent->_refCount--;
        if (sjt_functionParam229._parent->_refCount <= 0) {
            sjt_functionParam229._vtbl->destroy(sjt_functionParam229._parent);
            free(sjt_functionParam229._parent);
        }
    }
    if (sjt_functionParam232._parent != 0) {
        sjt_functionParam232._parent->_refCount--;
        if (sjt_functionParam232._parent->_refCount <= 0) {
            sjt_functionParam232._vtbl->destroy(sjt_functionParam232._parent);
            free(sjt_functionParam232._parent);
        }
    }
    if (sjt_functionParam246._parent != 0) {
        sjt_functionParam246._parent->_refCount--;
        if (sjt_functionParam246._parent->_refCount <= 0) {
            sjt_functionParam246._vtbl->destroy(sjt_functionParam246._parent);
            free(sjt_functionParam246._parent);
        }
    }
    if (sjt_functionParam40._parent != 0) {
        sjt_functionParam40._parent->_refCount--;
        if (sjt_functionParam40._parent->_refCount <= 0) {
            sjt_functionParam40._vtbl->destroy(sjt_functionParam40._parent);
            free(sjt_functionParam40._parent);
        }
    }
    if (sjt_functionParam42._parent != 0) {
        sjt_functionParam42._parent->_refCount--;
        if (sjt_functionParam42._parent->_refCount <= 0) {
            sjt_functionParam42._vtbl->destroy(sjt_functionParam42._parent);
            free(sjt_functionParam42._parent);
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
    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
    if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
    if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
    if (sjt_call22._refCount == 1) { sjf_gridunit_destroy(&sjt_call22); }
    if (sjt_call23._refCount == 1) { sjf_gridunit_destroy(&sjt_call23); }
    if (sjt_call24._refCount == 1) { sjf_gridunit_destroy(&sjt_call24); }
    if (sjt_call25._refCount == 1) { sjf_gridunit_destroy(&sjt_call25); }
    if (sjt_call33._refCount == 1) { sjf_string_destroy(&sjt_call33); }
    if (sjt_call35._refCount == 1) { sjf_string_destroy(&sjt_call35); }
    if (sjt_call37._refCount == 1) { sjf_string_destroy(&sjt_call37); }
    if (sjt_call39._refCount == 1) { sjf_string_destroy(&sjt_call39); }
    if (sjt_call41._refCount == 1) { sjf_string_destroy(&sjt_call41); }
    if (sjt_call51._refCount == 1) { sjf_string_destroy(&sjt_call51); }
    if (sjt_call52._refCount == 1) { sjf_string_destroy(&sjt_call52); }
    if (sjt_call53._refCount == 1) { sjf_string_destroy(&sjt_call53); }
    if (sjt_call54._refCount == 1) { sjf_string_destroy(&sjt_call54); }
    if (sjt_call64._refCount == 1) { sjf_string_destroy(&sjt_call64); }
    if (sjt_call65._refCount == 1) { sjf_string_destroy(&sjt_call65); }
    if (sjt_call66._refCount == 1) { sjf_string_destroy(&sjt_call66); }
    if (sjt_call67._refCount == 1) { sjf_string_destroy(&sjt_call67); }
    if (sjt_call68._refCount == 1) { sjf_string_destroy(&sjt_call68); }
    if (sjt_call69._refCount == 1) { sjf_string_destroy(&sjt_call69); }
    if (sjt_call70._refCount == 1) { sjf_string_destroy(&sjt_call70); }
    if (sjt_call71._refCount == 1) { sjf_string_destroy(&sjt_call71); }
    if (sjt_call72._refCount == 1) { sjf_string_destroy(&sjt_call72); }
    if (sjt_call73._refCount == 1) { sjf_string_destroy(&sjt_call73); }
    if (sjt_call74._refCount == 1) { sjf_string_destroy(&sjt_call74); }
    if (sjt_call75._refCount == 1) { sjf_string_destroy(&sjt_call75); }
    if (sjt_call76._refCount == 1) { sjf_string_destroy(&sjt_call76); }
    if (sjt_call77._refCount == 1) { sjf_string_destroy(&sjt_call77); }
    if (sjt_call78._refCount == 1) { sjf_string_destroy(&sjt_call78); }
    if (sjt_call79._refCount == 1) { sjf_string_destroy(&sjt_call79); }
    if (sjt_call80._refCount == 1) { sjf_string_destroy(&sjt_call80); }
    if (sjt_call81._refCount == 1) { sjf_string_destroy(&sjt_call81); }
    if (sjt_call82._refCount == 1) { sjf_string_destroy(&sjt_call82); }
    if (sjt_call83._refCount == 1) { sjf_string_destroy(&sjt_call83); }
    if (sjt_call89._refCount == 1) { sjf_string_destroy(&sjt_call89); }
    if (sjt_call90._refCount == 1) { sjf_gridunit_destroy(&sjt_call90); }
    if (sjt_call91._refCount == 1) { sjf_gridunit_destroy(&sjt_call91); }
    if (sjt_call92._refCount == 1) { sjf_gridunit_destroy(&sjt_call92); }
    if (sjt_call93._refCount == 1) { sjf_gridunit_destroy(&sjt_call93); }
    if (sjt_call94._refCount == 1) { sjf_gridunit_destroy(&sjt_call94); }
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
