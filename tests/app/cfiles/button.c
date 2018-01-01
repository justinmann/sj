#include <lib/common/common.h>
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
#include <SDL2/SDL.h>
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
#include <lib/ui/obj_parser.h>
#include <limits.h>
#include <math.h>
#include <png.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include FT_FREETYPE_H
#include FT_LCD_FILTER_H
#include FT_STROKER_H

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
const char* sjg_string31 = "FPS: ";
const char* sjg_string32 = "viewport being pop'ed is wrong";
const char* sjg_string4 = "shaders/fade.frag";
const char* sjg_string5 = "shaders/v3f-c4f.vert";
const char* sjg_string6 = "shaders/v3f-c4f.frag";
const char* sjg_string7 = "shaders/v3f-t2f.frag";
const char* sjg_string8 = "shaders/v3f-n3f-phong.vert";
const char* sjg_string9 = "shaders/v3f-n3f-phong.frag";

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
#define sjs_hash_type_bool_typeId 36
#define sjs_log_typeId 41
#define sjs_windowrenderer_typeId 42
#define sjs_color_typeId 44
#define sjs_size_typeId 48
#define sjs_mat4_typeId 49
#define sjs_rect_typeId 50
#define sjs_scene2d_typeId 47
#define sjs_array_char_typeId 60
#define sjs_string_typeId 51
#define sjs_vec3_typeId 53
#define sjs_light_typeId 52
#define sji_model_typeId 54
#define sjs_array_heap_iface_model_typeId 198
#define sjs_list_heap_iface_model_typeId 55
#define sjs_point_typeId 106
#define sjs_mouseevent_typeId 56
#define sjs_hash_string_weak_iface_model_typeId 57
#define sji_element_typeId 64
#define sjs_hash_string_weak_iface_element_typeId 65
#define sjs_array_heap_iface_animation_typeId 71
#define sjs_list_heap_iface_animation_typeId 70
#define sjs_animator_typeId 68
#define sji_animation_typeId 69
#define sjs_shader_typeId 72
#define sjs_fontkey_typeId 73
#define sjs_font_typeId 74
#define sjs_hash_fontkey_weak_font_typeId 75
#define sjs_array_rect_typeId 82
#define sjs_list_rect_typeId 81
#define sjs_array_u32_typeId 84
#define sjs_list_u32_typeId 83
#define sjs_style_typeId 85
#define sjs_controller_typeId 86
#define sjs_array_heap_iface_element_typeId 90
#define sjs_margin_typeId 91
#define sjs_array_gridunit_typeId 93
#define sjs_gridlayout_typeId 89
#define sjs_gridunit_typeId 92
#define sjs_array_i32_typeId 97
#define sji_gridchild_typeId 101
#define sjs_texture_typeId 116
#define sjs_image_typeId 115
#define cb_void_typeId 119
#define cb_void_heap_typeId 119
#define sjs_textrenderer_typeId 120
#define sjs_imagerenderer_typeId 121
#define sji_clickable_typeId 123
#define sjs_clickgesture_typeId 122
#define sjs_buttonelement_typeId 110
#define sji_textelement_typeId 156
#define sjs_textelement_typeId 163

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
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
typedef struct td_sjs_animator sjs_animator;
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
typedef struct td_sjs_style sjs_style;
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

struct td_sjs_hash_type_bool {
    int _refCount;
    void* _hash;
};

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
    sjs_hash_type_bool traceincludes;
    sjs_hash_type_bool debugincludes;
    sjs_hash_type_bool infoincludes;
    sjs_hash_type_bool warnincludes;
    sjs_hash_type_bool errorincludes;
    sjs_hash_type_bool fatalincludes;
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
    bool isglobal;
    int32_t count;
};

struct td_sjs_string {
    int _refCount;
    int32_t count;
    sjs_array_char data;
    bool _isnullterminated;
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
    bool isglobal;
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
    int32_t eventtype;
    sjs_point point;
    bool iscaptured;
    bool isleftdown;
};

struct td_sji_model_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
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
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
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
    bool isglobal;
    int32_t count;
};

struct td_sjs_list_heap_iface_animation {
    int _refCount;
    sjs_array_heap_iface_animation array;
};

struct td_sjs_animator {
    int _refCount;
    sjs_list_heap_iface_animation animations;
    int32_t current;
};

struct td_sji_animation_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
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
    bool isglobal;
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
    bool isglobal;
    int32_t count;
};

struct td_sjs_list_u32 {
    int _refCount;
    sjs_array_u32 array;
};

struct td_sjs_style {
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
    bool isglobal;
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
    bool isglobal;
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
    int32_t unittype;
};

struct td_sjs_array_i32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sji_gridchild_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
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
    sjs_font* font;
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
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
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
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
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
    sjs_size idealsize;
    sjs_rect _rect;
    sjs_textrenderer _textrenderer;
};

sji_clickable_vtbl sjs_buttonelement_clickable_vtbl;
sji_element_vtbl sjs_buttonelement_element_vtbl;
sji_element_vtbl sjs_gridlayout_element_vtbl;
sji_element_vtbl sjs_textelement_element_vtbl;
sji_textelement_vtbl sjs_textelement_textelement_vtbl;
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
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
void add_text(vertex_buffer_t * buffer, texture_font_t * font, char *text, int textlen, vec4 * color, vec2 * pen);   
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
const char * codepoints );
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
int32_t sjv_gldrawmode_gl_line_loop;
int32_t sjv_gldrawmode_gl_line_strip;
int32_t sjv_gldrawmode_gl_lines;
int32_t sjv_gldrawmode_gl_points;
int32_t sjv_gldrawmode_gl_triangle_fan;
int32_t sjv_gldrawmode_gl_triangle_strip;
int32_t sjv_gldrawmode_gl_triangles;
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
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;
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
sjs_string sjt_call19 = { -1 };
sjs_string sjt_call20 = { -1 };
sjs_string sjt_call21 = { -1 };
sjs_gridlayout* sjt_call3 = 0;
sjs_textelement* sjt_call30 = 0;
sjs_gridunit sjt_call33 = { -1 };
sjs_gridunit sjt_call34 = { -1 };
sjs_gridunit sjt_call35 = { -1 };
sjs_gridunit sjt_call36 = { -1 };
sjs_gridunit sjt_call37 = { -1 };
sjs_gridunit sjt_call38 = { -1 };
sjs_buttonelement* sjt_call5 = 0;
sjs_gridlayout* sjt_cast2 = 0;
sjs_buttonelement* sjt_cast4 = 0;
sjs_textelement* sjt_cast9 = 0;
sjs_string* sjt_functionParam110 = 0;
sjs_string* sjt_functionParam111 = 0;
sjs_string* sjt_functionParam112 = 0;
int32_t sjt_functionParam128;
sji_element sjt_functionParam129 = { 0 };
int32_t sjt_functionParam144;
int32_t sjt_functionParam145;
sjs_gridunit* sjt_functionParam146 = 0;
int32_t sjt_functionParam147;
sjs_gridunit* sjt_functionParam148 = 0;
int32_t sjt_functionParam149;
sjs_gridunit* sjt_functionParam150 = 0;
int32_t sjt_functionParam151;
sjs_gridunit* sjt_functionParam152 = 0;
int32_t sjt_functionParam153;
sjs_gridunit* sjt_functionParam154 = 0;
int32_t sjt_functionParam155;
sjs_gridunit* sjt_functionParam156 = 0;
int32_t sjt_functionParam39;
sji_element sjt_functionParam40 = { 0 };
sjs_array_heap_iface_element* sjt_parent28 = 0;
sjs_style* sjt_parent54 = 0;
sjs_array_heap_iface_element* sjt_parent67 = 0;
sjs_style* sjt_parent81 = 0;
sjs_array_gridunit* sjt_parent82 = 0;
sjs_array_gridunit* sjt_parent83 = 0;
sjs_array_gridunit* sjt_parent84 = 0;
sjs_array_gridunit* sjt_parent85 = 0;
sjs_array_gridunit* sjt_parent86 = 0;
sjs_array_gridunit* sjt_parent87 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };
sjs_image sjt_value5 = { -1 };
sjs_image sjt_value6 = { -1 };
sjs_image sjt_value7 = { -1 };
sjs_string sjt_value9 = { -1 };
sjs_animator sjv_animator = { -1 };
sjs_shader sjv_blurhorizontalshader = { -1 };
sjs_shader sjv_blurverticalshader = { -1 };
sjs_shader sjv_boxshader = { -1 };
int32_t sjv_clocks_per_sec;
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
sjs_log sjv_log = { -1 };
sjs_hash_type_bool sjv_log_excludeall = { -1 };
sjs_hash_type_bool sjv_log_includeall = { -1 };
sjs_rect sjv_looplastrect = { -1 };
int32_t sjv_mainloop_frames;
int32_t sjv_mainloop_lasttick;
bool sjv_mainloop_shouldcontinue;
bool sjv_mainloop_showfps;
sjs_hash_string_weak_iface_model sjv_modelsbyid = { -1 };
sji_element sjv_mouse_captureelement = { 0 };
sjs_shader sjv_phongcolorshader = { -1 };
sjs_shader sjv_phongtextureshader = { -1 };
sji_element sjv_root = { 0 };
sjs_controller* sjv_rootcontroller = 0;
sjs_scene2d sjv_rootscene = { -1 };
sjs_windowrenderer sjv_rootwindowrenderer = { -1 };
sjs_shader sjv_saturateshader = { -1 };
sjs_style sjv_style = { -1 };
sjs_shader sjv_textshader = { -1 };
uint32_t sjv_u32_maxvalue;
sjs_string sjv_vertex_location_texture_normal_format = { -1 };

void sjf_animator(sjs_animator* _this);
void sjf_animator_copy(sjs_animator* _this, sjs_animator* _from);
void sjf_animator_destroy(sjs_animator* _this);
void sjf_animator_heap(sjs_animator* _this);
void sjf_animator_nextframe(sjs_animator* _parent, int32_t time);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_array_gridunit(sjs_array_gridunit* _this);
void sjf_array_gridunit_copy(sjs_array_gridunit* _this, sjs_array_gridunit* _from);
void sjf_array_gridunit_destroy(sjs_array_gridunit* _this);
void sjf_array_gridunit_getat(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit* _return);
void sjf_array_gridunit_getat_heap(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit** _return);
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
void sjf_array_rect_getat_heap(sjs_array_rect* _parent, int32_t index, sjs_rect** _return);
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
void sjf_buttonelement_getclasstype(sjs_object* _this, int* _return);
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
void sjf_f32_asstring(float val, sjs_string* _return);
void sjf_f32_asstring_heap(float val, sjs_string** _return);
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
void sjf_glbindtexture(int32_t t, sjs_texture* texture);
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
void sjf_gridlayout_getclasstype(sjs_object* _this, int* _return);
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
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_i32_asmargin(int32_t x, sjs_margin* _return);
void sjf_i32_asmargin_heap(int32_t x, sjs_margin** _return);
void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return);
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
void sjf_list_rect_getat_heap(sjs_list_rect* _parent, int32_t index, sjs_rect** _return);
void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return);
void sjf_list_rect_heap(sjs_list_rect* _this);
void sjf_list_rect_removeat(sjs_list_rect* _parent, int32_t index);
void sjf_list_u32(sjs_list_u32* _this);
void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from);
void sjf_list_u32_destroy(sjs_list_u32* _this);
void sjf_list_u32_heap(sjs_list_u32* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
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
void sjf_string_nullterminate(sjs_string* _parent);
void sjf_style(sjs_style* _this);
void sjf_style_copy(sjs_style* _this, sjs_style* _from);
void sjf_style_destroy(sjs_style* _this);
void sjf_style_getfont_heap(sjs_style* _parent, sjs_font** _return);
void sjf_style_heap(sjs_style* _this);
void sjf_textelement_as_sji_element(sjs_textelement* _this, sji_element* _return);
void sjf_textelement_as_sji_textelement(sjs_textelement* _this, sji_textelement* _return);
void sjf_textelement_asinterface(sjs_textelement* _this, int typeId, sjs_interface* _return);
void sjf_textelement_copy(sjs_textelement* _this, sjs_textelement* _from);
void sjf_textelement_destroy(sjs_textelement* _this);
void sjf_textelement_firemouseevent(sjs_textelement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_textelement_getclasstype(sjs_object* _this, int* _return);
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
void sjf_type_hash(int32_t val, uint32_t* _return);
void sjf_type_isequal(int32_t l, int32_t r, bool* _return);
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

#ifndef type_bool_hash_function
#define type_bool_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#else
KHASH_INIT_FUNCTION(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#endif
#endif
#ifndef type_bool_hash_function
#define type_bool_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#else
KHASH_INIT_FUNCTION(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#endif
#endif
#include <lib/common/common.c>
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
    *result = (id1 == id2);
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
    void add_text(vertex_buffer_t * buffer, texture_font_t * font, char *text, int textlen, vec4 * color, vec2 * pen) {
        pen->y += (float)(int)font->ascender;
        size_t i;
        float r = color->red, g = color->green, b = color->blue, a = color->alpha;
        for (i = 0; i < (size_t)textlen; ++i) {
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
        int rowbytes = (int)png_get_rowbytes(png_ptr, info_ptr);
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
        ivec3 node = {{1,1, (int)width-2}};
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
        width_left = (int)width;
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
        ivec4 region = {{0,0,(int)width,(int)height}};
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
                    best_index = (int)i;
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
        node->y = (int)(region.y + height);
        node->z = (int)width;
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
        node.z = (int)(self->width-2);
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
            node.x = (int)(width_old - 1);
            node.y = 1;
            node.z = (int)(width_new - width_old);
            vector_push_back(ta->nodes, &node);
        }
        //over data from the old buffer, skipping first row and column because of the margin
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
            self->attributes[i]->stride = (GLsizei)stride;
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
            glDrawElements( self->mode, (GLint)count, GL_UNSIGNED_INT, (void *)(start*sizeof(GLuint)) );
        }
        else if( self->vertices->size )
        {
            size_t start = item->vstart;
            size_t count = item->vcount;
            glDrawArrays( self->mode, (GLint)(start*self->vertices->item_size), (GLint)count);
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
            glDrawElements( mode, (GLint)icount, GL_UNSIGNED_INT, 0 );
        }
        else
        {
            glDrawArrays( mode, 0, (GLint)vcount );
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
        item.x = (int)vstart;
        item.y = (int)vcount;
        item.z = (int)istart;
        item.w = (int)icount;
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
void sjf_animator(sjs_animator* _this) {
}

void sjf_animator_copy(sjs_animator* _this, sjs_animator* _from) {
    _this->animations._refCount = 1;
#line 27 "lib/ui/animation.sj"
    sjf_list_heap_iface_animation_copy(&_this->animations, &_from->animations);
#line 27
    _this->current = _from->current;
}

void sjf_animator_destroy(sjs_animator* _this) {
    if (_this->animations._refCount == 1) { sjf_list_heap_iface_animation_destroy(&_this->animations); }
;
}

void sjf_animator_heap(sjs_animator* _this) {
}

void sjf_animator_nextframe(sjs_animator* _parent, int32_t time) {
    int32_t sjt_capture17;
    sjs_list_heap_iface_animation* sjt_parent88 = 0;

#line 31 "lib/ui/animation.sj"
    _parent->current = time;
#line 4 "lib/common/list.sj"
    sjt_parent88 = &_parent->animations;
#line 4
    sjf_list_heap_iface_animation_getcount(sjt_parent88, &sjt_capture17);
    if (sjt_capture17 > 0) {
        int32_t i;
        int32_t sjt_forEnd10;
        int32_t sjt_forStart10;
        sjs_list_heap_iface_animation* sjt_parent89 = 0;

#line 35 "lib/ui/animation.sj"
        sjt_forStart10 = 0;
#line 4 "lib/common/list.sj"
        sjt_parent89 = &_parent->animations;
#line 4
        sjf_list_heap_iface_animation_getcount(sjt_parent89, &sjt_forEnd10);
#line 35 "lib/ui/animation.sj"
        i = sjt_forEnd10 - 1;
        while (i >= sjt_forStart10) {
            bool sjt_capture18;
            int32_t sjt_functionParam158;
            int32_t sjt_interfaceParam9;
            sjs_list_heap_iface_animation* sjt_parent91 = 0;
            sji_animation sjt_parent92 = { 0 };
            sji_animation sjv_a = { 0 };

#line 8 "lib/common/list.sj"
            sjt_parent91 = &_parent->animations;
#line 35 "lib/ui/animation.sj"
            sjt_functionParam158 = i;
#line 35
            sjf_list_heap_iface_animation_getat_heap(sjt_parent91, sjt_functionParam158, &sjv_a);
#line 2
            sjt_parent92 = sjv_a;
#line 31
            sjt_interfaceParam9 = time;
#line 37
            sjt_parent92._vtbl->nextframe(sjt_parent92._parent, sjt_interfaceParam9, &sjt_capture18);
            if (sjt_capture18) {
                int32_t sjt_functionParam159;
                sjs_list_heap_iface_animation* sjt_parent93 = 0;

#line 53 "lib/common/list.sj"
                sjt_parent93 = &_parent->animations;
#line 35 "lib/ui/animation.sj"
                sjt_functionParam159 = i;
#line 35
                sjf_list_heap_iface_animation_removeat(sjt_parent93, sjt_functionParam159);
            }

#line 35
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

void sjf_array_char(sjs_array_char* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 333 "lib/common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !true && !false
#line 338
            char* p = (char*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    char* p = (char*)_parent->data;
#line 14
    #line 8 "lib/common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    void* sjv_newdata;

#line 135 "lib/common/array.sj"
    sjv_newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
#line 143
        int* refcount = (int*)sjv_newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        char* p = (char*)_parent->data;
#line 151
        char* newp = (char*)sjv_newdata;
#line 153
        int count = _parent->count;
#line 155
        #if true
#line 156
        memcpy(newp, p, sizeof(char) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            #line 136 "lib/common/array.sj"
newp[i] = p[i];
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    _return->_refCount = 1;
#line 134
    _return->datasize = newsize;
#line 164
    _return->data = sjv_newdata;
#line 4
    _return->isglobal = false;
#line 164
    _return->count = _parent->count;
#line 164
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    void* sjv_newdata;

#line 135 "lib/common/array.sj"
    sjv_newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
#line 143
        int* refcount = (int*)sjv_newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        char* p = (char*)_parent->data;
#line 151
        char* newp = (char*)sjv_newdata;
#line 153
        int count = _parent->count;
#line 155
        #if true
#line 156
        memcpy(newp, p, sizeof(char) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            #line 136 "lib/common/array.sj"
newp[i] = p[i];
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
#line 162
    (*_return)->_refCount = 1;
#line 134
    (*_return)->datasize = newsize;
#line 164
    (*_return)->data = sjv_newdata;
#line 4
    (*_return)->isglobal = false;
#line 164
    (*_return)->count = _parent->count;
#line 164
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
#line 36 "lib/common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    char* p = (char*)_parent->data;
#line 44
    #line 34 "lib/common/array.sj"
p[index] = item;
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
#line 271 "lib/common/array.sj"
    if (_parent->count != test->count) {
#line 272
        *_return = false;
#line 273
    }
#line 275
    bool result = memcmp(_parent->data, test->data, _parent->count * sizeof(char)) == 0;
#line 276
    #line 270 "lib/common/array.sj"
(*_return) = result;
return;;      
}

void sjf_array_gridunit(sjs_array_gridunit* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_gridunit) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_gridunit_copy(sjs_array_gridunit* _this, sjs_array_gridunit* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_gridunit_destroy(sjs_array_gridunit* _this) {
#line 333 "lib/common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !false && !true
#line 338
            sjs_gridunit* p = (sjs_gridunit*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_gridunit_getat(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sjs_gridunit* p = (sjs_gridunit*)_parent->data;
#line 14
    _return->_refCount = 1;
#line 8 "lib/common/array.sj"
sjf_gridunit_copy(_return, &p[index]);
return;;       
}

void sjf_array_gridunit_getat_heap(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit** _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sjs_gridunit* p = (sjs_gridunit*)_parent->data;
#line 14
    (*_return) = (sjs_gridunit*)malloc(sizeof(sjs_gridunit));
(*_return)->_refCount = 1;
#line 8 "lib/common/array.sj"
sjf_gridunit_copy((*_return), &p[index]);
return;;       
}

void sjf_array_gridunit_heap(sjs_array_gridunit* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_gridunit) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_gridunit_initat(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit* item) {
#line 36 "lib/common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    sjs_gridunit* p = (sjs_gridunit*)_parent->data;
#line 44
    p[index]._refCount = 1;
#line 34 "lib/common/array.sj"
sjf_gridunit_copy(&p[index], item);
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_heap_iface_animation(sjs_array_heap_iface_animation* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_animation) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_heap_iface_animation_copy(sjs_array_heap_iface_animation* _this, sjs_array_heap_iface_animation* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_heap_iface_animation_destroy(sjs_array_heap_iface_animation* _this) {
#line 333 "lib/common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !false && !false
#line 338
            sji_animation* p = (sji_animation*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_heap_iface_animation_getat_heap(sjs_array_heap_iface_animation* _parent, int32_t index, sji_animation* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sji_animation* p = (sji_animation*)_parent->data;
#line 14
    #line 8 "lib/common/array.sj"
(*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_animation_heap(sjs_array_heap_iface_animation* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_animation) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_heap_iface_element(sjs_array_heap_iface_element* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_element) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_heap_iface_element_copy(sjs_array_heap_iface_element* _this, sjs_array_heap_iface_element* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_heap_iface_element_destroy(sjs_array_heap_iface_element* _this) {
#line 333 "lib/common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !false && !false
#line 338
            sji_element* p = (sji_element*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_heap_iface_element_getat_heap(sjs_array_heap_iface_element* _parent, int32_t index, sji_element* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sji_element* p = (sji_element*)_parent->data;
#line 14
    #line 8 "lib/common/array.sj"
(*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_element_heap(sjs_array_heap_iface_element* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_element) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_heap_iface_element_initat(sjs_array_heap_iface_element* _parent, int32_t index, sji_element item) {
#line 36 "lib/common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    sji_element* p = (sji_element*)_parent->data;
#line 44
    #line 34 "lib/common/array.sj"
p[index] = item;
if (p[index]._parent != 0) {
    p[index]._parent->_refCount++;
}
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_heap_iface_model(sjs_array_heap_iface_model* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_model) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this) {
#line 333 "lib/common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !false && !false
#line 338
            sji_model* p = (sji_model*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_model) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_i32(sjs_array_i32* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(int32_t) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
#line 333 "lib/common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !true && !false
#line 338
            int32_t* p = (int32_t*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    int32_t* p = (int32_t*)_parent->data;
#line 14
    #line 8 "lib/common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_i32_heap(sjs_array_i32* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(int32_t) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item) {
#line 36 "lib/common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    int32_t* p = (int32_t*)_parent->data;
#line 44
    #line 34 "lib/common/array.sj"
p[index] = item;
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_rect(sjs_array_rect* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_rect) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_rect_copy(sjs_array_rect* _this, sjs_array_rect* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_rect_destroy(sjs_array_rect* _this) {
#line 333 "lib/common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !false && !true
#line 338
            sjs_rect* p = (sjs_rect*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_rect_getat(sjs_array_rect* _parent, int32_t index, sjs_rect* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sjs_rect* p = (sjs_rect*)_parent->data;
#line 14
    _return->_refCount = 1;
#line 8 "lib/common/array.sj"
sjf_rect_copy(_return, &p[index]);
return;;       
}

void sjf_array_rect_getat_heap(sjs_array_rect* _parent, int32_t index, sjs_rect** _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sjs_rect* p = (sjs_rect*)_parent->data;
#line 14
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
(*_return)->_refCount = 1;
#line 8 "lib/common/array.sj"
sjf_rect_copy((*_return), &p[index]);
return;;       
}

void sjf_array_rect_grow(sjs_array_rect* _parent, int32_t newsize, sjs_array_rect* _return) {
    void* sjv_newdata;

#line 135 "lib/common/array.sj"
    sjv_newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(sjs_rect))) + 1;
#line 143
        int* refcount = (int*)sjv_newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        sjs_rect* p = (sjs_rect*)_parent->data;
#line 151
        sjs_rect* newp = (sjs_rect*)sjv_newdata;
#line 153
        int count = _parent->count;
#line 155
        #if false
#line 156
        memcpy(newp, p, sizeof(sjs_rect) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            newp[i]._refCount = 1;
#line 136 "lib/common/array.sj"
sjf_rect_copy(&newp[i], &p[i]);
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    _return->_refCount = 1;
#line 134
    _return->datasize = newsize;
#line 164
    _return->data = sjv_newdata;
#line 4
    _return->isglobal = false;
#line 164
    _return->count = _parent->count;
#line 164
    sjf_array_rect(_return);
}

void sjf_array_rect_grow_heap(sjs_array_rect* _parent, int32_t newsize, sjs_array_rect** _return) {
    void* sjv_newdata;

#line 135 "lib/common/array.sj"
    sjv_newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(sjs_rect))) + 1;
#line 143
        int* refcount = (int*)sjv_newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        sjs_rect* p = (sjs_rect*)_parent->data;
#line 151
        sjs_rect* newp = (sjs_rect*)sjv_newdata;
#line 153
        int count = _parent->count;
#line 155
        #if false
#line 156
        memcpy(newp, p, sizeof(sjs_rect) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            newp[i]._refCount = 1;
#line 136 "lib/common/array.sj"
sjf_rect_copy(&newp[i], &p[i]);
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    (*_return) = (sjs_array_rect*)malloc(sizeof(sjs_array_rect));
#line 162
    (*_return)->_refCount = 1;
#line 134
    (*_return)->datasize = newsize;
#line 164
    (*_return)->data = sjv_newdata;
#line 4
    (*_return)->isglobal = false;
#line 164
    (*_return)->count = _parent->count;
#line 164
    sjf_array_rect_heap((*_return));
}

void sjf_array_rect_heap(sjs_array_rect* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_rect) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_rect_initat(sjs_array_rect* _parent, int32_t index, sjs_rect* item) {
#line 36 "lib/common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    sjs_rect* p = (sjs_rect*)_parent->data;
#line 44
    p[index]._refCount = 1;
#line 34 "lib/common/array.sj"
sjf_rect_copy(&p[index], item);
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_u32(sjs_array_u32* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(uint32_t) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_u32_copy(sjs_array_u32* _this, sjs_array_u32* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_u32_destroy(sjs_array_u32* _this) {
#line 333 "lib/common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !true && !false
#line 338
            uint32_t* p = (uint32_t*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_u32_heap(sjs_array_u32* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(uint32_t) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
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
#line 1 "lib/ui/buttonElement.sj"
    sjf_string_copy(&_this->text, &_from->text);
#line 1
    _this->textcolor._refCount = 1;
#line 1
    sjf_color_copy(&_this->textcolor, &_from->textcolor);
#line 1
    _this->font = _from->font;
#line 1
    _this->font->_refCount++;
#line 1
    sjs_image* copyoption14 = (_from->normalimage._refCount != -1 ? &_from->normalimage : 0);
    if (copyoption14 != 0) {
        _this->normalimage._refCount = 1;
#line 1 "lib/ui/buttonElement.sj"
        sjf_image_copy(&_this->normalimage, copyoption14);
    } else {
        _this->normalimage._refCount = -1;
    }

#line 1
    sjs_image* copyoption15 = (_from->hotimage._refCount != -1 ? &_from->hotimage : 0);
    if (copyoption15 != 0) {
        _this->hotimage._refCount = 1;
#line 1 "lib/ui/buttonElement.sj"
        sjf_image_copy(&_this->hotimage, copyoption15);
    } else {
        _this->hotimage._refCount = -1;
    }

#line 1
    sjs_image* copyoption16 = (_from->pressedimage._refCount != -1 ? &_from->pressedimage : 0);
    if (copyoption16 != 0) {
        _this->pressedimage._refCount = 1;
#line 1 "lib/ui/buttonElement.sj"
        sjf_image_copy(&_this->pressedimage, copyoption16);
    } else {
        _this->pressedimage._refCount = -1;
    }

#line 1
    _this->margin._refCount = 1;
#line 1
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 1
    _this->onclick = _from->onclick;
    if ((uintptr_t)_this->onclick.inner._parent > 1) {
        _this->onclick.inner._parent->_refCount++;
    }

#line 1
    _this->_rect._refCount = 1;
#line 1
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 1
    sjs_textrenderer* copyoption17 = (_from->_textrenderer._refCount != -1 ? &_from->_textrenderer : 0);
    if (copyoption17 != 0) {
        _this->_textrenderer._refCount = 1;
#line 1 "lib/ui/buttonElement.sj"
        sjf_textrenderer_copy(&_this->_textrenderer, copyoption17);
    } else {
        _this->_textrenderer._refCount = -1;
    }

#line 1
    sjs_imagerenderer* copyoption18 = (_from->_imagerenderer._refCount != -1 ? &_from->_imagerenderer : 0);
    if (copyoption18 != 0) {
        _this->_imagerenderer._refCount = 1;
#line 1 "lib/ui/buttonElement.sj"
        sjf_imagerenderer_copy(&_this->_imagerenderer, copyoption18);
    } else {
        _this->_imagerenderer._refCount = -1;
    }

#line 1
    _this->_clickgesture._refCount = 1;
#line 1
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

    if (_this->text._refCount == 1) { sjf_string_destroy(&_this->text); }
;
    if (_this->textcolor._refCount == 1) { sjf_color_destroy(&_this->textcolor); }
;
    if (_this->normalimage._refCount == 1) { sjf_image_destroy(&_this->normalimage); }
;
    if (_this->hotimage._refCount == 1) { sjf_image_destroy(&_this->hotimage); }
;
    if (_this->pressedimage._refCount == 1) { sjf_image_destroy(&_this->pressedimage); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
    if (_this->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_this->_textrenderer); }
;
    if (_this->_imagerenderer._refCount == 1) { sjf_imagerenderer_destroy(&_this->_imagerenderer); }
;
    if (_this->_clickgesture._refCount == 1) { sjf_clickgesture_destroy(&_this->_clickgesture); }
;
}

void sjf_buttonelement_firemouseevent(sjs_buttonelement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_mouseevent* sjt_functionParam104 = 0;
    sjs_clickgesture* sjt_parent51 = 0;

#line 22 "lib/ui/clickGesture.sj"
    sjt_parent51 = &_parent->_clickgesture;
#line 88 "lib/ui/buttonElement.sj"
    sjt_functionParam104 = mouseevent;
#line 88
    sjf_clickgesture_firemouseevent(sjt_parent51, sjt_functionParam104, _return);
}

void sjf_buttonelement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 110;
}

void sjf_buttonelement_getrect(sjs_buttonelement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 21 "lib/ui/buttonElement.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_buttonelement_getrect_heap(sjs_buttonelement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 21 "lib/ui/buttonElement.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_buttonelement_getsize(sjs_buttonelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size sjt_call6 = { -1 };
    sjs_string* sjt_functionParam41 = 0;
    sjs_margin* sjt_functionParam42 = 0;
    sjs_size* sjt_functionParam43 = 0;
    sjs_size* sjt_parent31 = 0;
    sjs_font* sjt_parent32 = 0;
    sjs_size* sjt_parent33 = 0;
    sjs_size sjv_textsize = { -1 };

#line 53 "lib/ui/font.sj"
    sjt_parent32 = _parent->font;
#line 17 "lib/ui/buttonElement.sj"
    sjt_functionParam41 = &_parent->text;
#line 17
    sjf_font_gettextsize(sjt_parent32, sjt_functionParam41, &sjt_call6);
#line 17
    sjt_parent31 = &sjt_call6;
#line 17
    sjt_functionParam42 = &_parent->margin;
#line 17
    sjf_size_addmargin(sjt_parent31, sjt_functionParam42, &sjv_textsize);
#line 5 "lib/ui/size.sj"
    sjt_parent33 = &sjv_textsize;
#line 16 "lib/ui/buttonElement.sj"
    sjt_functionParam43 = maxsize;
#line 16
    sjf_size_min(sjt_parent33, sjt_functionParam43, _return);

    if (sjt_call6._refCount == 1) { sjf_size_destroy(&sjt_call6); }
;
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
}

void sjf_buttonelement_getsize_heap(sjs_buttonelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size sjt_call7 = { -1 };
    sjs_string* sjt_functionParam44 = 0;
    sjs_margin* sjt_functionParam45 = 0;
    sjs_size* sjt_functionParam46 = 0;
    sjs_size* sjt_parent34 = 0;
    sjs_font* sjt_parent35 = 0;
    sjs_size* sjt_parent36 = 0;
    sjs_size sjv_textsize = { -1 };

#line 53 "lib/ui/font.sj"
    sjt_parent35 = _parent->font;
#line 17 "lib/ui/buttonElement.sj"
    sjt_functionParam44 = &_parent->text;
#line 17
    sjf_font_gettextsize(sjt_parent35, sjt_functionParam44, &sjt_call7);
#line 17
    sjt_parent34 = &sjt_call7;
#line 17
    sjt_functionParam45 = &_parent->margin;
#line 17
    sjf_size_addmargin(sjt_parent34, sjt_functionParam45, &sjv_textsize);
#line 5 "lib/ui/size.sj"
    sjt_parent36 = &sjv_textsize;
#line 16 "lib/ui/buttonElement.sj"
    sjt_functionParam46 = maxsize;
#line 16
    sjf_size_min_heap(sjt_parent36, sjt_functionParam46, _return);

    if (sjt_call7._refCount == 1) { sjf_size_destroy(&sjt_call7); }
;
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
}

void sjf_buttonelement_heap(sjs_buttonelement* _this) {
    sjs_buttonelement* sjt_cast5 = 0;
    sjs_buttonelement* sjt_cast6 = 0;
    sjs_clickgesture sjt_funcold1 = { -1 };

    sjt_funcold1._refCount = 1;
#line 14 "lib/ui/clickGesture.sj"
    sjf_clickgesture_copy(&sjt_funcold1, &_this->_clickgesture);
#line 14
    sjt_funcold1._refCount = 1;
#line 1 "lib/ui/buttonElement.sj"
    sjt_cast5 = _this;
#line 1 "lib/ui/element.sj"
    sjf_buttonelement_as_sji_element(sjt_cast5, &sjt_funcold1.element);
#line 1
    delete_cb weakptrcb18 = { &sjt_funcold1.element._parent, weakptr_clear };
#line 1
    if (sjt_funcold1.element._parent != 0) { weakptr_cb_add(sjt_funcold1.element._parent, weakptrcb18); }
#line 1 "lib/ui/buttonElement.sj"
    sjt_cast6 = _this;
#line 7 "lib/ui/clickGesture.sj"
    sjf_buttonelement_as_sji_clickable(sjt_cast6, &sjt_funcold1.clickable);
#line 7
    delete_cb weakptrcb19 = { &sjt_funcold1.clickable._parent, weakptr_clear };
#line 7
    if (sjt_funcold1.clickable._parent != 0) { weakptr_cb_add(sjt_funcold1.clickable._parent, weakptrcb19); }
#line 7
    sjt_funcold1.rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_funcold1.rect.x = 0;
#line 3
    sjt_funcold1.rect.y = 0;
#line 4
    sjt_funcold1.rect.w = 0;
#line 5
    sjt_funcold1.rect.h = 0;
#line 5
    sjf_rect(&sjt_funcold1.rect);
#line 14 "lib/ui/clickGesture.sj"
    sjt_funcold1._state = sjv_clickstate_none;
#line 14
    sjf_clickgesture(&sjt_funcold1);
#line 14
    if (_this->_clickgesture._refCount == 1) { sjf_clickgesture_destroy(&_this->_clickgesture); }
;
#line 14
    sjf_clickgesture_copy(&_this->_clickgesture, &sjt_funcold1);

    if (sjt_funcold1._refCount == 1) { sjf_clickgesture_destroy(&sjt_funcold1); }
;
}

void sjf_buttonelement_onclickgestureclick(sjs_buttonelement* _parent, sji_element element) {
    if (_parent->_imagerenderer._refCount == 1) { sjf_imagerenderer_destroy(&_parent->_imagerenderer); }
;
#line 81 "lib/ui/buttonElement.sj"
    _parent->_imagerenderer._refCount = -1;
    if ((_parent->onclick.inner._parent != 0)) {
        cb_void_heap ifValue13;
        cb_void_heap sjt_getValue1;

#line 82 "lib/ui/buttonElement.sj"
        sjt_getValue1 = _parent->onclick;
        if ((uintptr_t)sjt_getValue1.inner._parent > 1) {
            sjt_getValue1.inner._parent->_refCount++;
        }

#line 82
        ifValue13 = sjt_getValue1;
        if ((uintptr_t)ifValue13.inner._parent > 1) {
            ifValue13.inner._parent->_refCount++;
        }

#line 82
        ifValue13.inner._cb(ifValue13.inner._parent);

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
    if (_parent->_imagerenderer._refCount == 1) { sjf_imagerenderer_destroy(&_parent->_imagerenderer); }
;
#line 66 "lib/ui/buttonElement.sj"
    _parent->_imagerenderer._refCount = -1;
}

void sjf_buttonelement_onclickgestureleave(sjs_buttonelement* _parent, sji_element element) {
    if (_parent->_imagerenderer._refCount == 1) { sjf_imagerenderer_destroy(&_parent->_imagerenderer); }
;
#line 71 "lib/ui/buttonElement.sj"
    _parent->_imagerenderer._refCount = -1;
}

void sjf_buttonelement_onclickgesturepress(sjs_buttonelement* _parent, sji_element element) {
    if (_parent->_imagerenderer._refCount == 1) { sjf_imagerenderer_destroy(&_parent->_imagerenderer); }
;
#line 76 "lib/ui/buttonElement.sj"
    _parent->_imagerenderer._refCount = -1;
}

void sjf_buttonelement_render(sjs_buttonelement* _parent, sjs_scene2d* scene) {
    sjs_textrenderer sjt_value3 = { -1 };
    sjs_image sjv_image = { -1 };
    sjs_rect sjv_innerrect = { -1 };
    sjs_size sjv_textsize = { -1 };

    if ((_parent->_imagerenderer._refCount != -1 ? &_parent->_imagerenderer : 0) == 0) {
        sjs_clickgesture* sjt_parent38 = 0;
        int32_t underscore1;

#line 20 "lib/ui/clickGesture.sj"
        sjt_parent38 = &_parent->_clickgesture;
#line 20
        sjf_clickgesture_getstate(sjt_parent38, &underscore1);
        if (underscore1 == sjv_clickstate_entered) {
#line 34 "lib/ui/buttonElement.sj"
            sjs_image* copyoption19 = (_parent->hotimage._refCount != -1 ? &_parent->hotimage : 0);
            if (copyoption19 != 0) {
                sjv_image._refCount = 1;
#line 34 "lib/ui/buttonElement.sj"
                sjf_image_copy(&sjv_image, copyoption19);
            } else {
                sjv_image._refCount = -1;
            }
        } else {
            if (underscore1 == sjv_clickstate_pressed) {
#line 34 "lib/ui/buttonElement.sj"
                sjs_image* copyoption20 = (_parent->pressedimage._refCount != -1 ? &_parent->pressedimage : 0);
                if (copyoption20 != 0) {
                    sjv_image._refCount = 1;
#line 34 "lib/ui/buttonElement.sj"
                    sjf_image_copy(&sjv_image, copyoption20);
                } else {
                    sjv_image._refCount = -1;
                }
            } else {
#line 34 "lib/ui/buttonElement.sj"
                sjs_image* copyoption21 = (_parent->normalimage._refCount != -1 ? &_parent->normalimage : 0);
                if (copyoption21 != 0) {
                    sjv_image._refCount = 1;
#line 34 "lib/ui/buttonElement.sj"
                    sjf_image_copy(&sjv_image, copyoption21);
                } else {
                    sjv_image._refCount = -1;
                }
            }
        }

        if (((sjv_image._refCount != -1 ? &sjv_image : 0) != 0)) {
            sjs_image* ifValue5 = 0;
            sjs_imagerenderer sjt_value2 = { -1 };

#line 40 "lib/ui/buttonElement.sj"
            ifValue5 = (sjv_image._refCount != -1 ? &sjv_image : 0);
#line 40
            sjt_value2._refCount = 1;
#line 40
            sjt_value2.rect._refCount = 1;
#line 41
            sjf_rect_copy(&sjt_value2.rect, &_parent->_rect);
#line 41
            sjt_value2.image._refCount = 1;
#line 41
            sjf_image_copy(&sjt_value2.image, ifValue5);
#line 41
            sjf_imagerenderer(&sjt_value2);
#line 41
            if (_parent->_imagerenderer._refCount == 1) { sjf_imagerenderer_destroy(&_parent->_imagerenderer); }
;
#line 41
            sjs_imagerenderer* copyoption22 = &sjt_value2;
            if (copyoption22 != 0) {
                _parent->_imagerenderer._refCount = 1;
#line 41 "lib/ui/buttonElement.sj"
                sjf_imagerenderer_copy(&_parent->_imagerenderer, copyoption22);
            } else {
                _parent->_imagerenderer._refCount = -1;
            }

            if (sjt_value2._refCount == 1) { sjf_imagerenderer_destroy(&sjt_value2); }
;
        }
    }

    if ((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) == 0) {
        sjs_margin* sjt_functionParam48 = 0;
        sjs_string* sjt_functionParam49 = 0;
        sjs_rect* sjt_parent39 = 0;
        sjs_font* sjt_parent40 = 0;

#line 7 "lib/ui/rect.sj"
        sjt_parent39 = &_parent->_rect;
#line 49 "lib/ui/buttonElement.sj"
        sjt_functionParam48 = &_parent->margin;
#line 49
        sjf_rect_subtractmargin(sjt_parent39, sjt_functionParam48, &sjv_innerrect);
#line 53 "lib/ui/font.sj"
        sjt_parent40 = _parent->font;
#line 51 "lib/ui/buttonElement.sj"
        sjt_functionParam49 = &_parent->text;
#line 51
        sjf_font_gettextsize(sjt_parent40, sjt_functionParam49, &sjv_textsize);
#line 51
        sjt_value3._refCount = 1;
#line 51
        sjt_value3.text._refCount = 1;
#line 53
        sjf_string_copy(&sjt_value3.text, &_parent->text);
#line 53
        sjt_value3.point._refCount = 1;
#line 55
        sjt_value3.point.x = (&sjv_innerrect)->x + (((&sjv_innerrect)->w - (&sjv_textsize)->w) / 2);
#line 55
        sjt_value3.point.y = (&sjv_innerrect)->y + (((&sjv_innerrect)->h - (&sjv_textsize)->h) / 2);
#line 55
        sjf_point(&sjt_value3.point);
#line 55
        sjt_value3.color._refCount = 1;
#line 53
        sjf_color_copy(&sjt_value3.color, &_parent->textcolor);
#line 53
        sjt_value3.font = _parent->font;
#line 53
        sjt_value3.font->_refCount++;
#line 53
        sjf_textrenderer(&sjt_value3);
#line 53
        if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
#line 53
        sjs_textrenderer* copyoption23 = &sjt_value3;
        if (copyoption23 != 0) {
            _parent->_textrenderer._refCount = 1;
#line 53 "lib/ui/buttonElement.sj"
            sjf_textrenderer_copy(&_parent->_textrenderer, copyoption23);
        } else {
            _parent->_textrenderer._refCount = -1;
        }
    }

    if ((_parent->_imagerenderer._refCount != -1 ? &_parent->_imagerenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam71 = 0;
        sjs_imagerenderer* sjt_parent41 = 0;

#line 8 "lib/ui/imageRenderer.sj"
        sjt_parent41 = (_parent->_imagerenderer._refCount != -1 ? &_parent->_imagerenderer : 0);
#line 32 "lib/ui/buttonElement.sj"
        sjt_functionParam71 = scene;
#line 32
        sjf_imagerenderer_render(sjt_parent41, sjt_functionParam71);
    }

    if ((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam91 = 0;
        sjs_textrenderer* sjt_parent42 = 0;

#line 10 "lib/ui/textRenderer.sj"
        sjt_parent42 = (_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0);
#line 32 "lib/ui/buttonElement.sj"
        sjt_functionParam91 = scene;
#line 32
        sjf_textrenderer_render(sjt_parent42, sjt_functionParam91);
    }

    if (sjt_value3._refCount == 1) { sjf_textrenderer_destroy(&sjt_value3); }
;
    if (sjv_image._refCount == 1) { sjf_image_destroy(&sjv_image); }
;
    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
;
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
}

void sjf_buttonelement_setrect(sjs_buttonelement* _parent, sjs_rect* rect_) {
    bool result2;
    bool sjt_capture10;
    sjs_rect* sjt_functionParam47 = 0;
    sjs_rect* sjt_parent37 = 0;

#line 15 "lib/ui/rect.sj"
    sjt_parent37 = &_parent->_rect;
#line 22 "lib/ui/buttonElement.sj"
    sjt_functionParam47 = rect_;
#line 22
    sjf_rect_isequal(sjt_parent37, sjt_functionParam47, &sjt_capture10);
#line 23
    result2 = !sjt_capture10;
    if (result2) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 22 "lib/ui/buttonElement.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
#line 22
        if ((&_parent->_clickgesture)->rect._refCount == 1) { sjf_rect_destroy(&(&_parent->_clickgesture)->rect); }
;
#line 22
        sjf_rect_copy(&(&_parent->_clickgesture)->rect, rect_);
#line 22
        if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
#line 26
        _parent->_textrenderer._refCount = -1;
#line 26
        if (_parent->_imagerenderer._refCount == 1) { sjf_imagerenderer_destroy(&_parent->_imagerenderer); }
;
#line 27
        _parent->_imagerenderer._refCount = -1;
    }
}

void sjf_clickgesture(sjs_clickgesture* _this) {
}

void sjf_clickgesture_copy(sjs_clickgesture* _this, sjs_clickgesture* _from) {
#line 14 "lib/ui/clickGesture.sj"
    _this->element = _from->element;
#line 14
    delete_cb weakptrcb14 = { &_this->element._parent, weakptr_clear };
#line 14
    if (_this->element._parent != 0) { weakptr_cb_add(_this->element._parent, weakptrcb14); }
#line 14
    _this->clickable = _from->clickable;
#line 14
    delete_cb weakptrcb15 = { &_this->clickable._parent, weakptr_clear };
#line 14
    if (_this->clickable._parent != 0) { weakptr_cb_add(_this->clickable._parent, weakptrcb15); }
#line 14
    _this->rect._refCount = 1;
#line 14
    sjf_rect_copy(&_this->rect, &_from->rect);
#line 14
    _this->_state = _from->_state;
}

void sjf_clickgesture_destroy(sjs_clickgesture* _this) {
    delete_cb weakptrcb16 = { &_this->element._parent, weakptr_clear };
    if (_this->element._parent != 0) { weakptr_cb_remove(_this->element._parent, weakptrcb16); }
    delete_cb weakptrcb17 = { &_this->clickable._parent, weakptr_clear };
    if (_this->clickable._parent != 0) { weakptr_cb_remove(_this->clickable._parent, weakptrcb17); }
    if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
}

void sjf_clickgesture_firemouseevent(sjs_clickgesture* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    if ((_parent->element._parent != 0)) {
        sji_element ifValue7 = { 0 };
        bool sjt_capture11;
        sjs_point* sjt_functionParam92 = 0;
        sjs_rect* sjt_parent43 = 0;

#line 23 "lib/ui/clickGesture.sj"
        ifValue7 = _parent->element;
        if (ifValue7._parent != 0) {
            ifValue7._parent->_refCount++;
        }

#line 11 "lib/ui/rect.sj"
        sjt_parent43 = &_parent->rect;
#line 24 "lib/ui/clickGesture.sj"
        sjt_functionParam92 = &mouseevent->point;
#line 24
        sjf_rect_containspoint(sjt_parent43, sjt_functionParam92, &sjt_capture11);
        if (sjt_capture11) {
            int32_t underscore3;

#line 25 "lib/ui/clickGesture.sj"
            underscore3 = mouseevent->eventtype;
            if (underscore3 == sjv_mouseeventtype_up) {
                sji_element sjt_functionParam98 = { 0 };

#line 27 "lib/ui/clickGesture.sj"
                _parent->_state = sjv_clickstate_none;
#line 28
                sjt_functionParam98 = ifValue7;
                if (sjt_functionParam98._parent != 0) {
                    sjt_functionParam98._parent->_refCount++;
                }

#line 28
                sjf_mouse_release(sjt_functionParam98);
                if (_parent->clickable._parent != 0) {
                    sji_element sjt_interfaceParam4 = { 0 };
                    sji_clickable sjt_parent47 = { 0 };

#line 11 "lib/ui/clickGesture.sj"
                    sjt_parent47 = _parent->clickable;
#line 29
                    sjt_interfaceParam4 = ifValue7;
#line 29
                    sjt_parent47._vtbl->onclickgestureclick(sjt_parent47._parent, sjt_interfaceParam4);
                }

#line 30
                (*_return) = false;

                if (sjt_functionParam98._parent != 0) {
                    sjt_functionParam98._parent->_refCount--;
                    if (sjt_functionParam98._parent->_refCount <= 0) {
                        sjt_functionParam98._vtbl->destroy(sjt_functionParam98._parent);
                        free(sjt_functionParam98._parent);
                    }
                }
            } else {
                if (underscore3 == sjv_mouseeventtype_down) {
                    sji_element sjt_functionParam99 = { 0 };

#line 33 "lib/ui/clickGesture.sj"
                    _parent->_state = sjv_clickstate_pressed;
#line 34
                    sjt_functionParam99 = ifValue7;
                    if (sjt_functionParam99._parent != 0) {
                        sjt_functionParam99._parent->_refCount++;
                    }

#line 34
                    sjf_mouse_capture(sjt_functionParam99);
                    if (_parent->clickable._parent != 0) {
                        sji_element sjt_interfaceParam5 = { 0 };
                        sji_clickable sjt_parent48 = { 0 };

#line 10 "lib/ui/clickGesture.sj"
                        sjt_parent48 = _parent->clickable;
#line 35
                        sjt_interfaceParam5 = ifValue7;
#line 35
                        sjt_parent48._vtbl->onclickgesturepress(sjt_parent48._parent, sjt_interfaceParam5);
                    }

#line 36
                    (*_return) = false;

                    if (sjt_functionParam99._parent != 0) {
                        sjt_functionParam99._parent->_refCount--;
                        if (sjt_functionParam99._parent->_refCount <= 0) {
                            sjt_functionParam99._vtbl->destroy(sjt_functionParam99._parent);
                            free(sjt_functionParam99._parent);
                        }
                    }
                } else {
                    if (underscore3 == sjv_mouseeventtype_move) {
                        bool result5;
                        bool sjt_capture12;
                        sji_element sjt_functionParam100 = { 0 };

                        if (_parent->_state == sjv_clickstate_none) {
                            if (mouseevent->isleftdown) {
#line 41 "lib/ui/clickGesture.sj"
                                _parent->_state = sjv_clickstate_pressed;
                            } else {
#line 43 "lib/ui/clickGesture.sj"
                                _parent->_state = sjv_clickstate_entered;
                            }

                            if (_parent->clickable._parent != 0) {
                                sji_element sjt_interfaceParam6 = { 0 };
                                sji_clickable sjt_parent49 = { 0 };

#line 8 "lib/ui/clickGesture.sj"
                                sjt_parent49 = _parent->clickable;
#line 45
                                sjt_interfaceParam6 = ifValue7;
#line 45
                                sjt_parent49._vtbl->onclickgestureenter(sjt_parent49._parent, sjt_interfaceParam6);
                            }
                        }

#line 47 "lib/ui/clickGesture.sj"
                        sjt_functionParam100 = ifValue7;
                        if (sjt_functionParam100._parent != 0) {
                            sjt_functionParam100._parent->_refCount++;
                        }

#line 47
                        sjf_mouse_hascapture(sjt_functionParam100, &sjt_capture12);
#line 47
                        result5 = !sjt_capture12;
#line 47
                        (*_return) = result5;

                        if (sjt_functionParam100._parent != 0) {
                            sjt_functionParam100._parent->_refCount--;
                            if (sjt_functionParam100._parent->_refCount <= 0) {
                                sjt_functionParam100._vtbl->destroy(sjt_functionParam100._parent);
                                free(sjt_functionParam100._parent);
                            }
                        }
                    } else {
#line 50 "lib/ui/clickGesture.sj"
                        (*_return) = true;
                    }
                }
            }
        } else {
            bool sjt_capture13;
            sji_element sjt_functionParam101 = { 0 };

            if ((_parent->_state == sjv_clickstate_entered) || (_parent->_state == sjv_clickstate_pressed)) {
                if (_parent->clickable._parent != 0) {
                    sji_element sjt_interfaceParam7 = { 0 };
                    sji_clickable sjt_parent50 = { 0 };

#line 9 "lib/ui/clickGesture.sj"
                    sjt_parent50 = _parent->clickable;
#line 55
                    sjt_interfaceParam7 = ifValue7;
#line 55
                    sjt_parent50._vtbl->onclickgestureleave(sjt_parent50._parent, sjt_interfaceParam7);
                }

#line 56 "lib/ui/clickGesture.sj"
                _parent->_state = sjv_clickstate_none;
            }

#line 59 "lib/ui/clickGesture.sj"
            sjt_functionParam101 = ifValue7;
            if (sjt_functionParam101._parent != 0) {
                sjt_functionParam101._parent->_refCount++;
            }

#line 59
            sjf_mouse_hascapture(sjt_functionParam101, &sjt_capture13);
            if ((mouseevent->eventtype == sjv_mouseeventtype_up) && sjt_capture13) {
                sji_element sjt_functionParam102 = { 0 };

#line 60 "lib/ui/clickGesture.sj"
                sjt_functionParam102 = ifValue7;
                if (sjt_functionParam102._parent != 0) {
                    sjt_functionParam102._parent->_refCount++;
                }

#line 60
                sjf_mouse_release(sjt_functionParam102);
#line 61
                (*_return) = false;

                if (sjt_functionParam102._parent != 0) {
                    sjt_functionParam102._parent->_refCount--;
                    if (sjt_functionParam102._parent->_refCount <= 0) {
                        sjt_functionParam102._vtbl->destroy(sjt_functionParam102._parent);
                        free(sjt_functionParam102._parent);
                    }
                }
            } else {
                bool result6;
                bool sjt_capture14;
                sji_element sjt_functionParam103 = { 0 };

#line 63 "lib/ui/clickGesture.sj"
                sjt_functionParam103 = ifValue7;
                if (sjt_functionParam103._parent != 0) {
                    sjt_functionParam103._parent->_refCount++;
                }

#line 63
                sjf_mouse_hascapture(sjt_functionParam103, &sjt_capture14);
#line 63
                result6 = !sjt_capture14;
#line 63
                (*_return) = result6;

                if (sjt_functionParam103._parent != 0) {
                    sjt_functionParam103._parent->_refCount--;
                    if (sjt_functionParam103._parent->_refCount <= 0) {
                        sjt_functionParam103._vtbl->destroy(sjt_functionParam103._parent);
                        free(sjt_functionParam103._parent);
                    }
                }
            }

            if (sjt_functionParam101._parent != 0) {
                sjt_functionParam101._parent->_refCount--;
                if (sjt_functionParam101._parent->_refCount <= 0) {
                    sjt_functionParam101._vtbl->destroy(sjt_functionParam101._parent);
                    free(sjt_functionParam101._parent);
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
#line 67 "lib/ui/clickGesture.sj"
        (*_return) = true;
    }
}

void sjf_clickgesture_getstate(sjs_clickgesture* _parent, int32_t* _return) {
#line 20 "lib/ui/clickGesture.sj"
    (*_return) = _parent->_state;
}

void sjf_clickgesture_heap(sjs_clickgesture* _this) {
}

void sjf_color(sjs_color* _this) {
}

void sjf_color_copy(sjs_color* _this, sjs_color* _from) {
#line 10 "lib/ui/color.sj"
    _this->r = _from->r;
#line 10
    _this->g = _from->g;
#line 10
    _this->b = _from->b;
#line 10
    _this->a = _from->a;
}

void sjf_color_destroy(sjs_color* _this) {
}

void sjf_color_heap(sjs_color* _this) {
}

void sjf_console_writeline(sjs_string* data) {
    sjs_string* sjt_parent46 = 0;

#line 9 "lib/common/console.sj"
    sjt_parent46 = data;
#line 9
    sjf_string_nullterminate(sjt_parent46);
#line 12
    printf("%s\n", (char*)data->data.data);
}

void sjf_controller(sjs_controller* _this) {
}

void sjf_controller_button1clicked(sjs_controller* _parent) {
    sjs_string sjt_call22 = { -1 };
    sji_element sjt_call23 = { 0 };
    sjs_string sjt_call24 = { -1 };
    sjs_string* sjt_functionParam113 = 0;
    sjs_string* sjt_functionParam114 = 0;
    sjs_hash_string_weak_iface_element* sjt_parent56 = 0;

#line 7 "button.sj"
    _parent->_button1count = _parent->_button1count + 1;
#line 7
    sjt_call22._refCount = 1;
#line 8
    sjt_call22.count = 7;
#line 8
    sjt_call22.data._refCount = 1;
#line 8
    sjt_call22.data.datasize = 7;
#line 8
    sjt_call22.data.data = (void*)sjg_string27;
#line 8
    sjt_call22.data.isglobal = true;
#line 8
    sjt_call22.data.count = 7;
#line 8
    sjf_array_char(&sjt_call22.data);
#line 14 "lib/common/string.sj"
    sjt_call22._isnullterminated = false;
#line 14
    sjf_string(&sjt_call22);
#line 8 "button.sj"
    sjt_functionParam113 = &sjt_call22;
#line 8
    sjf_debug_writeline(sjt_functionParam113);
#line 21 "lib/common/hash.sj"
    sjt_parent56 = &sjv_elementsbyid;
#line 21
    sjt_call24._refCount = 1;
#line 10 "button.sj"
    sjt_call24.count = 11;
#line 10
    sjt_call24.data._refCount = 1;
#line 10
    sjt_call24.data.datasize = 11;
#line 10
    sjt_call24.data.data = (void*)sjg_string28;
#line 10
    sjt_call24.data.isglobal = true;
#line 10
    sjt_call24.data.count = 11;
#line 10
    sjf_array_char(&sjt_call24.data);
#line 14 "lib/common/string.sj"
    sjt_call24._isnullterminated = false;
#line 14
    sjf_string(&sjt_call24);
#line 10 "button.sj"
    sjt_functionParam114 = &sjt_call24;
#line 10
    sjf_hash_string_weak_iface_element_getat(sjt_parent56, sjt_functionParam114, &sjt_call23);
    if ((sjt_call23._parent != 0)) {
        sji_element ifValue15 = { 0 };
        sji_element sjt_call25 = { 0 };
        sjs_string sjt_call26 = { -1 };
        sji_textelement sjt_capture15 = { 0 };
        sji_element sjt_cast7 = { 0 };
        sjs_string* sjt_functionParam115 = 0;
        sjs_hash_string_weak_iface_element* sjt_parent57 = 0;

#line 21 "lib/common/hash.sj"
        sjt_parent57 = &sjv_elementsbyid;
#line 21
        sjt_call26._refCount = 1;
#line 10 "button.sj"
        sjt_call26.count = 11;
#line 10
        sjt_call26.data._refCount = 1;
#line 10
        sjt_call26.data.datasize = 11;
#line 10
        sjt_call26.data.data = (void*)sjg_string28;
#line 10
        sjt_call26.data.isglobal = true;
#line 10
        sjt_call26.data.count = 11;
#line 10
        sjf_array_char(&sjt_call26.data);
#line 14 "lib/common/string.sj"
        sjt_call26._isnullterminated = false;
#line 14
        sjf_string(&sjt_call26);
#line 10 "button.sj"
        sjt_functionParam115 = &sjt_call26;
#line 10
        sjf_hash_string_weak_iface_element_getat(sjt_parent57, sjt_functionParam115, &sjt_call25);
#line 10
        ifValue15 = sjt_call25;
#line 11
        sjt_cast7 = ifValue15;
#line 13 "lib/ui/textElement.sj"
        sjt_cast7._vtbl->asinterface(sjt_cast7._parent, sji_textelement_typeId, (sjs_interface*)&sjt_capture15);
        if ((sjt_capture15._parent != 0)) {
            sji_textelement ifValue16 = { 0 };
            sjs_string sjt_call27 = { -1 };
            sjs_string sjt_call28 = { -1 };
            sjs_string sjt_call29 = { -1 };
            sji_element sjt_cast8 = { 0 };
            sjs_string* sjt_functionParam125 = 0;
            int32_t sjt_functionParam126;
            int32_t sjt_functionParam127;
            sjs_string* sjt_interfaceParam8 = 0;
            sji_textelement sjt_parent58 = { 0 };
            sjs_string* sjt_parent66 = 0;

#line 11 "button.sj"
            sjt_cast8 = ifValue15;
#line 13 "lib/ui/textElement.sj"
            sjt_cast8._vtbl->asinterface(sjt_cast8._parent, sji_textelement_typeId, (sjs_interface*)&ifValue16);
#line 15
            sjt_parent58 = ifValue16;
#line 15
            sjt_call28._refCount = 1;
#line 12 "button.sj"
            sjt_call28.count = 8;
#line 12
            sjt_call28.data._refCount = 1;
#line 12
            sjt_call28.data.datasize = 8;
#line 12
            sjt_call28.data.data = (void*)sjg_string29;
#line 12
            sjt_call28.data.isglobal = true;
#line 12
            sjt_call28.data.count = 8;
#line 12
            sjf_array_char(&sjt_call28.data);
#line 14 "lib/common/string.sj"
            sjt_call28._isnullterminated = false;
#line 14
            sjf_string(&sjt_call28);
#line 12 "button.sj"
            sjt_parent66 = &sjt_call28;
#line 12
            sjt_functionParam126 = _parent->_button1count;
#line 22 "lib/common/i32.sj"
            sjt_functionParam127 = 10;
#line 22
            sjf_i32_asstring(sjt_functionParam126, sjt_functionParam127, &sjt_call29);
#line 12 "button.sj"
            sjt_functionParam125 = &sjt_call29;
#line 12
            sjf_string_add(sjt_parent66, sjt_functionParam125, &sjt_call27);
#line 12
            sjt_interfaceParam8 = &sjt_call27;
#line 12
            sjt_parent58._vtbl->settext(sjt_parent58._parent, sjt_interfaceParam8);

            if (sjt_call27._refCount == 1) { sjf_string_destroy(&sjt_call27); }
;
            if (sjt_call28._refCount == 1) { sjf_string_destroy(&sjt_call28); }
;
            if (sjt_call29._refCount == 1) { sjf_string_destroy(&sjt_call29); }
;
        }

        delete_cb weakptrcb29 = { &sjt_call25._parent, weakptr_clear };
        if (sjt_call25._parent != 0) { weakptr_cb_remove(sjt_call25._parent, weakptrcb29); }
        if (sjt_call26._refCount == 1) { sjf_string_destroy(&sjt_call26); }
;
    }

    delete_cb weakptrcb30 = { &sjt_call23._parent, weakptr_clear };
    if (sjt_call23._parent != 0) { weakptr_cb_remove(sjt_call23._parent, weakptrcb30); }
    if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
;
    if (sjt_call24._refCount == 1) { sjf_string_destroy(&sjt_call24); }
;
}

void sjf_controller_copy(sjs_controller* _this, sjs_controller* _from) {
#line 3 "button.sj"
    _this->_button1count = _from->_button1count;
}

void sjf_controller_destroy(sjs_controller* _this) {
}

void sjf_controller_heap(sjs_controller* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent55 = 0;

#line 9 "lib/common/debug.sj"
    sjt_parent55 = data;
#line 9
    sjf_string_nullterminate(sjt_parent55);
#line 12
    debugout("%s\n", (char*)data->data.data);
}

void sjf_f32_asstring(float val, sjs_string* _return) {
    int32_t sjv_count;
    void* sjv_data;

#line 94 "lib/common/f32.sj"
    sjv_count = 0;
#line 95
    sjv_data = 0;
#line 97
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 98
    int* refcount = (int*)sjv_data - 1;
#line 99
    *refcount = 1;
#line 100
    snprintf((char*)sjv_data, 256, "%f", val);
#line 101
    sjv_count = (int)strlen((char*)sjv_data);
#line 101
    _return->_refCount = 1;
#line 103
    _return->count = sjv_count;
#line 103
    _return->data._refCount = 1;
#line 103
    _return->data.datasize = sjv_count;
#line 103
    _return->data.data = sjv_data;
#line 4 "lib/common/array.sj"
    _return->data.isglobal = false;
#line 103 "lib/common/f32.sj"
    _return->data.count = sjv_count;
#line 103
    sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_f32_asstring_heap(float val, sjs_string** _return) {
    int32_t sjv_count;
    void* sjv_data;

#line 94 "lib/common/f32.sj"
    sjv_count = 0;
#line 95
    sjv_data = 0;
#line 97
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 98
    int* refcount = (int*)sjv_data - 1;
#line 99
    *refcount = 1;
#line 100
    snprintf((char*)sjv_data, 256, "%f", val);
#line 101
    sjv_count = (int)strlen((char*)sjv_data);
#line 101
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 101
    (*_return)->_refCount = 1;
#line 103
    (*_return)->count = sjv_count;
#line 103
    (*_return)->data._refCount = 1;
#line 103
    (*_return)->data.datasize = sjv_count;
#line 103
    (*_return)->data.data = sjv_data;
#line 4 "lib/common/array.sj"
    (*_return)->data.isglobal = false;
#line 103 "lib/common/f32.sj"
    (*_return)->data.count = sjv_count;
#line 103
    sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));
}

void sjf_f32_hash(float val, uint32_t* _return) {
    uint32_t sjv_result;

#line 107 "lib/common/f32.sj"
    sjv_result = (uint32_t)0u;
#line 109
    int32_t* p = (int32_t*)&val;
#line 110
    sjv_result = *p;
#line 106
    (*_return) = sjv_result;
}

void sjf_font(sjs_font* _this) {
#line 65 "lib/ui/font.sj"
    _this->atlas = texture_atlas_new( 512, 512, 3 );
#line 66
    _this->font = texture_font_new_from_file(_this->atlas, _this->size, (char*)_this->src.data.data);
#line 67
    if (_this->font == 0) {
#line 68
        printf("texture_font_new_from_file Error\n");
#line 69
    }   
#line 71
    glGenTextures( 1, &_this->atlas->id );
#line 72
    glBindTexture( GL_TEXTURE_2D, _this->atlas->id );
#line 73
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#line 74
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
#line 75
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
#line 76
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
#line 77
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
#line 78
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, (int)_this->atlas->width, (int)_this->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->atlas->data );
}

void sjf_font_copy(sjs_font* _this, sjs_font* _from) {
    _this->src._refCount = 1;
#line 33 "lib/ui/font.sj"
    sjf_string_copy(&_this->src, &_from->src);
#line 33
    _this->size = _from->size;
#line 83
    _this->atlas = _from->atlas;
#line 84
    ptr_retain(_this->atlas);
#line 86
    _this->font = _from->font;
#line 87
    ptr_retain(_this->font);
}

void sjf_font_destroy(sjs_font* _this) {
#line 91 "lib/ui/font.sj"
    if (ptr_release(_this->atlas)) {
#line 92
        texture_atlas_delete(_this->atlas);
#line 93
    }
#line 95
    if (ptr_release(_this->font)) {
#line 96
        texture_font_delete(_this->font);
#line 97
    }
#line 97
    if (_this->src._refCount == 1) { sjf_string_destroy(&_this->src); }
;
}

void sjf_font_gettextsize(sjs_font* _parent, sjs_string* str, sjs_size* _return) {
    int32_t sjv_h;
    int32_t sjv_w;

#line 54 "lib/ui/font.sj"
    sjv_w = 0;
#line 55
    sjv_h = 0;
#line 57
    vec2 size = get_text_size(_parent->font, (char*)str->data.data);
#line 58
    sjv_w = (int)size.x;
#line 59
    sjv_h = (int)size.y;
#line 59
    _return->_refCount = 1;
#line 61
    _return->w = sjv_w;
#line 61
    _return->h = sjv_h;
#line 61
    sjf_size(_return);
}

void sjf_font_gettextsize_heap(sjs_font* _parent, sjs_string* str, sjs_size** _return) {
    int32_t sjv_h;
    int32_t sjv_w;

#line 54 "lib/ui/font.sj"
    sjv_w = 0;
#line 55
    sjv_h = 0;
#line 57
    vec2 size = get_text_size(_parent->font, (char*)str->data.data);
#line 58
    sjv_w = (int)size.x;
#line 59
    sjv_h = (int)size.y;
#line 59
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
#line 59
    (*_return)->_refCount = 1;
#line 61
    (*_return)->w = sjv_w;
#line 61
    (*_return)->h = sjv_h;
#line 61
    sjf_size_heap((*_return));
}

void sjf_font_heap(sjs_font* _this) {
#line 65 "lib/ui/font.sj"
    _this->atlas = texture_atlas_new( 512, 512, 3 );
#line 66
    _this->font = texture_font_new_from_file(_this->atlas, _this->size, (char*)_this->src.data.data);
#line 67
    if (_this->font == 0) {
#line 68
        printf("texture_font_new_from_file Error\n");
#line 69
    }   
#line 71
    glGenTextures( 1, &_this->atlas->id );
#line 72
    glBindTexture( GL_TEXTURE_2D, _this->atlas->id );
#line 73
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#line 74
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
#line 75
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
#line 76
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
#line 77
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
#line 78
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, (int)_this->atlas->width, (int)_this->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->atlas->data );
}

void sjf_font_load_heap(sjs_string* src, float size, sjs_font** _return) {
    sjs_fontkey* sjt_functionParam105 = 0;
    sjs_hash_fontkey_weak_font* sjt_parent52 = 0;
    sjs_font* sjv_h = 0;
    sjs_fontkey sjv_k = { -1 };
    sjs_font* sjv_w = 0;

    sjv_k._refCount = 1;
    sjv_k.src._refCount = 1;
#line 3 "lib/ui/font.sj"
    sjf_string_copy(&sjv_k.src, src);
#line 3
    sjv_k.size = size;
#line 3
    sjf_fontkey(&sjv_k);
#line 21 "lib/common/hash.sj"
    sjt_parent52 = &sjv_fonthash;
#line 7 "lib/ui/font.sj"
    sjt_functionParam105 = &sjv_k;
#line 7
    sjf_hash_fontkey_weak_font_getat(sjt_parent52, sjt_functionParam105, &sjv_w);
#line 8
    sjv_h = sjv_w;
    if (sjv_h != 0) {
        sjv_h->_refCount++;
    }

    if ((sjv_h != 0)) {
        sjs_font* ifValue4 = 0;

#line 9 "lib/ui/font.sj"
        ifValue4 = sjv_h;
        if (ifValue4 != 0) {
            ifValue4->_refCount++;
        }

#line 3
        (*_return) = ifValue4;
#line 3
        (*_return)->_refCount++;

        ifValue4->_refCount--;
        if (ifValue4->_refCount <= 0) {
            weakptr_release(ifValue4);
            sjf_font_destroy(ifValue4);
            free(ifValue4);
        }
    } else {
        sjs_fontkey* sjt_functionParam106 = 0;
        sjs_font* sjt_functionParam107 = 0;
        sjs_hash_fontkey_weak_font* sjt_parent53 = 0;
        sjs_font* sjv_result = 0;

        sjv_result = (sjs_font*)malloc(sizeof(sjs_font));
        sjv_result->_refCount = 1;
        sjv_result->src._refCount = 1;
#line 3 "lib/ui/font.sj"
        sjf_string_copy(&sjv_result->src, src);
#line 3
        sjv_result->size = size;
#line 3
        sjf_font_heap(sjv_result);
#line 38 "lib/common/hash.sj"
        sjt_parent53 = &sjv_fonthash;
#line 15 "lib/ui/font.sj"
        sjt_functionParam106 = &sjv_k;
#line 15
        sjt_functionParam107 = sjv_result;
#line 15
        delete_cb weakptrcb24 = { &sjt_functionParam107, weakptr_clear };
#line 15
        if (sjt_functionParam107 != 0) { weakptr_cb_add(sjt_functionParam107, weakptrcb24); }
#line 15
        sjf_hash_fontkey_weak_font_setat(sjt_parent53, sjt_functionParam106, sjt_functionParam107);
#line 3
        (*_return) = sjv_result;
#line 3
        (*_return)->_refCount++;

        delete_cb weakptrcb31 = { &sjt_functionParam107, weakptr_clear };
        if (sjt_functionParam107 != 0) { weakptr_cb_remove(sjt_functionParam107, weakptrcb31); }
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
;
}

void sjf_fontkey(sjs_fontkey* _this) {
}

void sjf_fontkey_copy(sjs_fontkey* _this, sjs_fontkey* _from) {
    _this->src._refCount = 1;
#line 20 "lib/ui/font.sj"
    sjf_string_copy(&_this->src, &_from->src);
#line 20
    _this->size = _from->size;
}

void sjf_fontkey_destroy(sjs_fontkey* _this) {
    if (_this->src._refCount == 1) { sjf_string_destroy(&_this->src); }
;
}

void sjf_fontkey_hash(sjs_fontkey* _parent, uint32_t* _return) {
    uint32_t sjt_capture1;
    uint32_t sjt_capture2;
    float sjt_functionParam10;
    sjs_string* sjt_parent2 = 0;

#line 83 "lib/common/string.sj"
    sjt_parent2 = &_parent->src;
#line 83
    sjf_string_hash(sjt_parent2, &sjt_capture1);
#line 25 "lib/ui/font.sj"
    sjt_functionParam10 = _parent->size;
#line 25
    sjf_f32_hash(sjt_functionParam10, &sjt_capture2);
#line 25
    (*_return) = sjt_capture1 ^ sjt_capture2;
}

void sjf_fontkey_heap(sjs_fontkey* _this) {
}

void sjf_fontkey_isequal(sjs_fontkey* _parent, sjs_fontkey* x, bool* _return) {
    bool sjt_capture3;
    sjs_string* sjt_functionParam11 = 0;
    sjs_string* sjt_parent3 = 0;

#line 44 "lib/common/string.sj"
    sjt_parent3 = &_parent->src;
#line 29 "lib/ui/font.sj"
    sjt_functionParam11 = &x->src;
#line 29
    sjf_string_isequal(sjt_parent3, sjt_functionParam11, &sjt_capture3);
#line 29
    (*_return) = sjt_capture3 && (_parent->size == x->size);
}

void sjf_glbindtexture(int32_t t, sjs_texture* texture) {
#line 173 "lib/ui/gl.sj"
    glBindTexture(t, texture->id);
}

void sjf_glblendfunc(int32_t sfactor, int32_t dfactor) {
#line 285 "lib/ui/gl.sj"
    glBlendFunc(sfactor, dfactor);
}

void sjf_glclearcolor(sjs_color* color) {
#line 279 "lib/ui/gl.sj"
    glClearColor(color->r, color->g, color->b, color->a);
}

void sjf_glenable(int32_t feature) {
#line 113 "lib/ui/gl.sj"
    glEnable(feature);
}

void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return) {
#line 179 "lib/ui/gl.sj"
    int result = glGetUniformLocation(shader->id, (char*)name->data.data);
#line 180
    #line 178 "lib/ui/gl.sj"
(*_return) = result;
return;;
}

void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect) {
    bool result14;
    sjs_rect sjt_call42 = { -1 };
    sjs_string sjt_call43 = { -1 };
    int32_t sjt_capture21;
    bool sjt_capture22;
    int32_t sjt_capture23;
    int32_t sjt_capture24;
    int32_t sjt_functionParam186;
    sjs_rect* sjt_functionParam187 = 0;
    int32_t sjt_functionParam189;
    sjs_rect* sjt_parent106 = 0;
    sjs_list_rect* sjt_parent109 = 0;
    sjs_list_rect* sjt_parent110 = 0;
    sjs_list_rect* sjt_parent112 = 0;
    sjs_list_rect* sjt_parent113 = 0;
    sjs_list_rect* sjt_parent114 = 0;
    sjs_rect sjv_newrect = { -1 };
    sjs_rect sjv_oldrect = { -1 };

    sjv_oldrect._refCount = 1;
#line 134 "lib/ui/gl.sj"
    sjv_oldrect.x = rect->x;
#line 134
    sjv_oldrect.y = scenerect->h - (rect->y + rect->h);
#line 134
    sjv_oldrect.w = rect->w;
#line 134
    sjv_oldrect.h = rect->h;
#line 134
    sjf_rect(&sjv_oldrect);
#line 8 "lib/common/list.sj"
    sjt_parent109 = &sjv_glviewports;
#line 4
    sjt_parent110 = &sjv_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent110, &sjt_capture21);
#line 135 "lib/ui/gl.sj"
    sjt_functionParam186 = sjt_capture21 - 1;
#line 135
    sjf_list_rect_getat(sjt_parent109, sjt_functionParam186, &sjt_call42);
#line 135
    sjt_parent106 = &sjt_call42;
#line 135
    sjt_functionParam187 = &sjv_oldrect;
#line 135
    sjf_rect_isequal(sjt_parent106, sjt_functionParam187, &sjt_capture22);
#line 135
    result14 = !sjt_capture22;
    if (result14) {
        sjs_string* sjt_functionParam188 = 0;

        sjt_call43._refCount = 1;
#line 136 "lib/ui/gl.sj"
        sjt_call43.count = 30;
#line 136
        sjt_call43.data._refCount = 1;
#line 136
        sjt_call43.data.datasize = 30;
#line 136
        sjt_call43.data.data = (void*)sjg_string32;
#line 136
        sjt_call43.data.isglobal = true;
#line 136
        sjt_call43.data.count = 30;
#line 136
        sjf_array_char(&sjt_call43.data);
#line 14 "lib/common/string.sj"
        sjt_call43._isnullterminated = false;
#line 14
        sjf_string(&sjt_call43);
#line 136 "lib/ui/gl.sj"
        sjt_functionParam188 = &sjt_call43;
#line 136
        sjf_halt(sjt_functionParam188);
    }

#line 53 "lib/common/list.sj"
    sjt_parent112 = &sjv_glviewports;
#line 4
    sjt_parent113 = &sjv_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent113, &sjt_capture23);
#line 138 "lib/ui/gl.sj"
    sjt_functionParam189 = sjt_capture23 - 1;
#line 138
    sjf_list_rect_removeat(sjt_parent112, sjt_functionParam189);
#line 4 "lib/common/list.sj"
    sjt_parent114 = &sjv_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent114, &sjt_capture24);
    if (sjt_capture24 > 0) {
        int32_t sjt_capture25;
        int32_t sjt_functionParam190;
        sjs_list_rect* sjt_parent115 = 0;
        sjs_list_rect* sjt_parent116 = 0;

#line 8 "lib/common/list.sj"
        sjt_parent115 = &sjv_glviewports;
#line 4
        sjt_parent116 = &sjv_glviewports;
#line 4
        sjf_list_rect_getcount(sjt_parent116, &sjt_capture25);
#line 139 "lib/ui/gl.sj"
        sjt_functionParam190 = sjt_capture25 - 1;
#line 139
        sjf_list_rect_getat(sjt_parent115, sjt_functionParam190, &sjv_newrect);
    } else {
        sjv_newrect._refCount = 1;
#line 2 "lib/ui/rect.sj"
        sjv_newrect.x = 0;
#line 3
        sjv_newrect.y = 0;
#line 4
        sjv_newrect.w = 0;
#line 5
        sjv_newrect.h = 0;
#line 5
        sjf_rect(&sjv_newrect);
    }

#line 141 "lib/ui/gl.sj"
    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjt_call42._refCount == 1) { sjf_rect_destroy(&sjt_call42); }
;
    if (sjt_call43._refCount == 1) { sjf_string_destroy(&sjt_call43); }
;
    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
;
    if (sjv_oldrect._refCount == 1) { sjf_rect_destroy(&sjv_oldrect); }
;
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect* sjt_functionParam180 = 0;
    sjs_list_rect* sjt_parent101 = 0;
    sjs_rect sjv_newrect = { -1 };

    sjv_newrect._refCount = 1;
#line 126 "lib/ui/gl.sj"
    sjv_newrect.x = rect->x;
#line 126
    sjv_newrect.y = scenerect->h - (rect->y + rect->h);
#line 126
    sjv_newrect.w = rect->w;
#line 126
    sjv_newrect.h = rect->h;
#line 126
    sjf_rect(&sjv_newrect);
#line 44 "lib/common/list.sj"
    sjt_parent101 = &sjv_glviewports;
#line 127 "lib/ui/gl.sj"
    sjt_functionParam180 = &sjv_newrect;
#line 127
    sjf_list_rect_add(sjt_parent101, sjt_functionParam180);
#line 129
    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
;
}

void sjf_gluniformi32(int32_t loc, int32_t v) {
#line 198 "lib/ui/gl.sj"
    glUniform1i(loc, v);
}

void sjf_gluniformmat4(int32_t loc, sjs_mat4* m) {
#line 186 "lib/ui/gl.sj"
    glUniformMatrix4fv(loc, 1, 0, (GLfloat*)&m->m00);
}

void sjf_gluseprogram(sjs_shader* shader) {
#line 167 "lib/ui/gl.sj"
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
#line 46 "lib/ui/gridLayout.sj"
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
#line 46
    _this->margin._refCount = 1;
#line 46
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 46
    _this->cols._refCount = 1;
#line 46
    sjf_array_gridunit_copy(&_this->cols, &_from->cols);
#line 46
    _this->rows._refCount = 1;
#line 46
    sjf_array_gridunit_copy(&_this->rows, &_from->rows);
#line 46
    _this->_rect._refCount = 1;
#line 46
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_gridlayout_destroy(sjs_gridlayout* _this) {
    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->cols._refCount == 1) { sjf_array_gridunit_destroy(&_this->cols); }
;
    if (_this->rows._refCount == 1) { sjf_array_gridunit_destroy(&_this->rows); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_gridlayout_firemouseevent(sjs_gridlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam38 = 0;
    sjs_mouseevent* sjt_parent27 = 0;

#line 164 "lib/ui/gridLayout.sj"
    sjt_parent27 = mouseevent;
#line 165
    sjt_functionParam38 = &_parent->children;
#line 165
    sjf_mouseevent_firechildren(sjt_parent27, sjt_functionParam38, _return);
}

void sjf_gridlayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 89;
}

void sjf_gridlayout_getrect(sjs_gridlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 57 "lib/ui/gridLayout.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_gridlayout_getrect_heap(sjs_gridlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 57 "lib/ui/gridLayout.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_gridlayout_getsize(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 54 "lib/ui/gridLayout.sj"
    _return->w = maxsize->w;
#line 54
    _return->h = maxsize->h;
#line 54
    sjf_size(_return);
}

void sjf_gridlayout_getsize_heap(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 54 "lib/ui/gridLayout.sj"
    (*_return)->w = maxsize->w;
#line 54
    (*_return)->h = maxsize->h;
#line 54
    sjf_size_heap((*_return));
}

void sjf_gridlayout_heap(sjs_gridlayout* _this) {
}

void sjf_gridlayout_render(sjs_gridlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;

#line 158 "lib/ui/gridLayout.sj"
    sjt_forStart6 = 0;
#line 158
    sjt_forEnd6 = (&_parent->children)->count;
#line 158
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        int32_t sjt_functionParam36;
        sjs_scene2d* sjt_interfaceParam2 = 0;
        sjs_array_heap_iface_element* sjt_parent23 = 0;
        sji_element sjt_parent24 = { 0 };
        sji_element sjv_child = { 0 };

#line 7 "lib/common/array.sj"
        sjt_parent23 = &_parent->children;
#line 158 "lib/ui/gridLayout.sj"
        sjt_functionParam36 = i;
#line 158
        sjf_array_heap_iface_element_getat_heap(sjt_parent23, sjt_functionParam36, &sjv_child);
#line 5 "lib/ui/element.sj"
        sjt_parent24 = sjv_child;
#line 157 "lib/ui/gridLayout.sj"
        sjt_interfaceParam2 = scene;
#line 160
        sjt_parent24._vtbl->render(sjt_parent24._parent, sjt_interfaceParam2);
#line 158
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

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 59 "lib/ui/gridLayout.sj"
    sjf_rect_copy(&_parent->_rect, rect_);
#line 59
    sjt_parent4 = rect_;
#line 61
    sjt_functionParam12 = &_parent->margin;
#line 61
    sjf_rect_subtractmargin(sjt_parent4, sjt_functionParam12, &sjv_innerrect);
#line 63
    sjv_rowfixed = 0;
#line 64
    sjv_rowstars = 0;
#line 65
    sjt_forStart1 = 0;
#line 65
    sjt_forEnd1 = (&_parent->rows)->count;
#line 65
    r = sjt_forStart1;
    while (r < sjt_forEnd1) {
        int32_t sjt_functionParam13;
        sjs_array_gridunit* sjt_parent5 = 0;
        sjs_gridunit sjv_row = { -1 };

#line 7 "lib/common/array.sj"
        sjt_parent5 = &_parent->rows;
#line 65 "lib/ui/gridLayout.sj"
        sjt_functionParam13 = r;
#line 65
        sjf_array_gridunit_getat(sjt_parent5, sjt_functionParam13, &sjv_row);
        if ((&sjv_row)->unittype == sjv_gridunittype_star) {
#line 68 "lib/ui/gridLayout.sj"
            sjv_rowstars = sjv_rowstars + (&sjv_row)->amount;
        } else {
#line 70 "lib/ui/gridLayout.sj"
            sjv_rowfixed = sjv_rowfixed + (&sjv_row)->amount;
        }

#line 65
        r++;

        if (sjv_row._refCount == 1) { sjf_gridunit_destroy(&sjv_row); }
;
    }

    if (sjv_rowstars > 0) {
#line 74 "lib/ui/gridLayout.sj"
        sjv_rowstarunit = ((&sjv_innerrect)->h - sjv_rowfixed) / sjv_rowstars;
    } else {
#line 74 "lib/ui/gridLayout.sj"
        sjv_rowstarunit = 0;
    }

    if (sjv_rowstars > 0) {
#line 75 "lib/ui/gridLayout.sj"
        sjv_rowstarremainder = ((&sjv_innerrect)->h - sjv_rowfixed) % sjv_rowstars;
    } else {
#line 75 "lib/ui/gridLayout.sj"
        sjv_rowstarremainder = 0;
    }

#line 65
    sjv_ypos._refCount = 1;
#line 77
    sjv_ypos.datasize = (&_parent->rows)->count + 1;
#line 3 "lib/common/array.sj"
    sjv_ypos.data = 0;
#line 4
    sjv_ypos.isglobal = false;
#line 5
    sjv_ypos.count = 0;
#line 5
    sjf_array_i32(&sjv_ypos);
#line 78 "lib/ui/gridLayout.sj"
    sjv_y = (&sjv_innerrect)->y;
#line 34 "lib/common/array.sj"
    sjt_parent6 = &sjv_ypos;
#line 79 "lib/ui/gridLayout.sj"
    sjt_functionParam14 = 0;
#line 79
    sjt_functionParam15 = sjv_y;
#line 79
    sjf_array_i32_initat(sjt_parent6, sjt_functionParam14, sjt_functionParam15);
#line 80
    sjt_forStart2 = 0;
#line 80
    sjt_forEnd2 = (&_parent->rows)->count;
#line 80
    r = sjt_forStart2;
    while (r < sjt_forEnd2) {
        int32_t sjt_functionParam16;
        int32_t sjt_functionParam19;
        int32_t sjt_functionParam20;
        sjs_array_gridunit* sjt_parent7 = 0;
        sjs_array_i32* sjt_parent8 = 0;
        sjs_gridunit sjv_row = { -1 };

#line 7 "lib/common/array.sj"
        sjt_parent7 = &_parent->rows;
#line 80 "lib/ui/gridLayout.sj"
        sjt_functionParam16 = r;
#line 80
        sjf_array_gridunit_getat(sjt_parent7, sjt_functionParam16, &sjv_row);
        if ((&sjv_row)->unittype == sjv_gridunittype_star) {
            int32_t sjt_capture4;
            int32_t sjt_functionParam17;
            int32_t sjt_functionParam18;

#line 83 "lib/ui/gridLayout.sj"
            sjv_y = sjv_y + (sjv_rowstarunit * (&sjv_row)->amount);
#line 84
            sjt_functionParam17 = 0;
#line 84
            sjt_functionParam18 = sjv_rowstarremainder;
#line 84
            sjf_i32_max(sjt_functionParam17, sjt_functionParam18, &sjt_capture4);
#line 84
            sjv_y = sjv_y + sjt_capture4;
#line 85
            sjv_rowstarremainder = sjv_rowstarremainder - (&sjv_row)->amount;
        } else {
#line 87 "lib/ui/gridLayout.sj"
            sjv_y = sjv_y + (&sjv_row)->amount;
        }

#line 34 "lib/common/array.sj"
        sjt_parent8 = &sjv_ypos;
#line 89 "lib/ui/gridLayout.sj"
        sjt_functionParam19 = r + 1;
#line 89
        sjt_functionParam20 = sjv_y;
#line 89
        sjf_array_i32_initat(sjt_parent8, sjt_functionParam19, sjt_functionParam20);
#line 80
        r++;

        if (sjv_row._refCount == 1) { sjf_gridunit_destroy(&sjv_row); }
;
    }

#line 92
    sjv_colfixed = 0;
#line 93
    sjv_colstars = 0;
#line 94
    sjt_forStart3 = 0;
#line 94
    sjt_forEnd3 = (&_parent->cols)->count;
#line 94
    c = sjt_forStart3;
    while (c < sjt_forEnd3) {
        int32_t sjt_functionParam21;
        sjs_array_gridunit* sjt_parent9 = 0;
        sjs_gridunit sjv_col = { -1 };

#line 7 "lib/common/array.sj"
        sjt_parent9 = &_parent->cols;
#line 94 "lib/ui/gridLayout.sj"
        sjt_functionParam21 = c;
#line 94
        sjf_array_gridunit_getat(sjt_parent9, sjt_functionParam21, &sjv_col);
        if ((&sjv_col)->unittype == sjv_gridunittype_star) {
#line 97 "lib/ui/gridLayout.sj"
            sjv_colstars = sjv_colstars + (&sjv_col)->amount;
        } else {
#line 99 "lib/ui/gridLayout.sj"
            sjv_colfixed = sjv_colfixed + (&sjv_col)->amount;
        }

#line 94
        c++;

        if (sjv_col._refCount == 1) { sjf_gridunit_destroy(&sjv_col); }
;
    }

    if (sjv_colstars > 0) {
#line 103 "lib/ui/gridLayout.sj"
        sjv_colstarunit = ((&sjv_innerrect)->w - sjv_colfixed) / sjv_colstars;
    } else {
#line 103 "lib/ui/gridLayout.sj"
        sjv_colstarunit = 0;
    }

    if (sjv_colstars > 0) {
#line 104 "lib/ui/gridLayout.sj"
        sjv_colstarremainder = ((&sjv_innerrect)->w - sjv_colfixed) % sjv_colstars;
    } else {
#line 104 "lib/ui/gridLayout.sj"
        sjv_colstarremainder = 0;
    }

#line 94
    sjv_xpos._refCount = 1;
#line 106
    sjv_xpos.datasize = (&_parent->cols)->count + 1;
#line 3 "lib/common/array.sj"
    sjv_xpos.data = 0;
#line 4
    sjv_xpos.isglobal = false;
#line 5
    sjv_xpos.count = 0;
#line 5
    sjf_array_i32(&sjv_xpos);
#line 107 "lib/ui/gridLayout.sj"
    sjv_x = (&sjv_innerrect)->x;
#line 34 "lib/common/array.sj"
    sjt_parent10 = &sjv_xpos;
#line 108 "lib/ui/gridLayout.sj"
    sjt_functionParam22 = 0;
#line 108
    sjt_functionParam23 = sjv_x;
#line 108
    sjf_array_i32_initat(sjt_parent10, sjt_functionParam22, sjt_functionParam23);
#line 109
    sjt_forStart4 = 0;
#line 109
    sjt_forEnd4 = (&_parent->cols)->count;
#line 109
    c = sjt_forStart4;
    while (c < sjt_forEnd4) {
        int32_t sjt_functionParam24;
        int32_t sjt_functionParam27;
        int32_t sjt_functionParam28;
        sjs_array_gridunit* sjt_parent11 = 0;
        sjs_array_i32* sjt_parent12 = 0;
        sjs_gridunit sjv_col = { -1 };

#line 7 "lib/common/array.sj"
        sjt_parent11 = &_parent->cols;
#line 109 "lib/ui/gridLayout.sj"
        sjt_functionParam24 = c;
#line 109
        sjf_array_gridunit_getat(sjt_parent11, sjt_functionParam24, &sjv_col);
        if ((&sjv_col)->unittype == sjv_gridunittype_star) {
            int32_t sjt_capture5;
            int32_t sjt_functionParam25;
            int32_t sjt_functionParam26;

#line 112 "lib/ui/gridLayout.sj"
            sjv_x = sjv_x + (sjv_colstarunit * (&sjv_col)->amount);
#line 113
            sjt_functionParam25 = 0;
#line 113
            sjt_functionParam26 = sjv_colstarremainder;
#line 113
            sjf_i32_max(sjt_functionParam25, sjt_functionParam26, &sjt_capture5);
#line 113
            sjv_x = sjv_x + sjt_capture5;
#line 114
            sjv_colstarremainder = sjv_colstarremainder - (&sjv_col)->amount;
        } else {
#line 116 "lib/ui/gridLayout.sj"
            sjv_x = sjv_x + (&sjv_col)->amount;
        }

#line 34 "lib/common/array.sj"
        sjt_parent12 = &sjv_xpos;
#line 118 "lib/ui/gridLayout.sj"
        sjt_functionParam27 = c + 1;
#line 118
        sjt_functionParam28 = sjv_x;
#line 118
        sjf_array_i32_initat(sjt_parent12, sjt_functionParam27, sjt_functionParam28);
#line 109
        c++;

        if (sjv_col._refCount == 1) { sjf_gridunit_destroy(&sjv_col); }
;
    }

#line 121
    sjv_rnext = 0;
#line 122
    sjv_cnext = 0;
#line 123
    sjt_forStart5 = 0;
#line 123
    sjt_forEnd5 = (&_parent->children)->count;
#line 123
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        sjs_rect sjt_call4 = { -1 };
        int32_t sjt_capture6;
        int32_t sjt_capture7;
        int32_t sjt_capture8;
        int32_t sjt_capture9;
        sji_element sjt_cast3 = { 0 };
        int32_t sjt_functionParam29;
        int32_t sjt_functionParam30;
        int32_t sjt_functionParam31;
        int32_t sjt_functionParam32;
        int32_t sjt_functionParam33;
        int32_t sjt_functionParam34;
        int32_t sjt_functionParam35;
        sjs_rect* sjt_interfaceParam1 = 0;
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

#line 124 "lib/ui/gridLayout.sj"
        sjv_r = 0;
#line 125
        sjv_c = 0;
#line 7 "lib/common/array.sj"
        sjt_parent13 = &_parent->children;
#line 123 "lib/ui/gridLayout.sj"
        sjt_functionParam29 = i;
#line 123
        sjf_array_heap_iface_element_getat_heap(sjt_parent13, sjt_functionParam29, &sjv_child);
#line 127
        sjt_cast3 = sjv_child;
#line 1
        sjt_cast3._vtbl->asinterface(sjt_cast3._parent, sji_gridchild_typeId, (sjs_interface*)&sjv_gridchild);
        if (sjv_gridchild._parent != 0) {
            sjv_gridchild._parent->_refCount++;
        }

        if ((sjv_gridchild._parent != 0)) {
            sji_gridchild ifValue1 = { 0 };
            sji_gridchild sjt_parent14 = { 0 };
            sji_gridchild sjt_parent15 = { 0 };

#line 128 "lib/ui/gridLayout.sj"
            ifValue1 = sjv_gridchild;
            if (ifValue1._parent != 0) {
                ifValue1._parent->_refCount++;
            }

#line 2
            sjt_parent14 = ifValue1;
#line 129
            sjt_parent14._vtbl->getrow(sjt_parent14._parent, &sjv_r);
#line 3
            sjt_parent15 = ifValue1;
#line 130
            sjt_parent15._vtbl->getcol(sjt_parent15._parent, &sjv_c);

            if (ifValue1._parent != 0) {
                ifValue1._parent->_refCount--;
                if (ifValue1._parent->_refCount <= 0) {
                    ifValue1._vtbl->destroy(ifValue1._parent);
                    free(ifValue1._parent);
                }
            }
        } else {
#line 133 "lib/ui/gridLayout.sj"
            sjv_r = sjv_rnext;
#line 134
            sjv_c = sjv_cnext;
#line 135
            sjv_cnext = sjv_cnext + 1;
            if (sjv_cnext >= (&_parent->cols)->count) {
#line 137 "lib/ui/gridLayout.sj"
                sjv_cnext = 0;
#line 138
                sjv_rnext = sjv_rnext + 1;
                if (sjv_rnext >= (&_parent->rows)->count) {
#line 140 "lib/ui/gridLayout.sj"
                    sjv_rnext = 0;
                }
            }
        }

#line 4 "lib/ui/element.sj"
        sjt_parent16 = sjv_child;
#line 4
        sjt_call4._refCount = 1;
#line 7 "lib/common/array.sj"
        sjt_parent17 = &sjv_xpos;
#line 147 "lib/ui/gridLayout.sj"
        sjt_functionParam30 = sjv_c;
#line 147
        sjf_array_i32_getat(sjt_parent17, sjt_functionParam30, &sjt_call4.x);
#line 7 "lib/common/array.sj"
        sjt_parent18 = &sjv_ypos;
#line 148 "lib/ui/gridLayout.sj"
        sjt_functionParam31 = sjv_r;
#line 148
        sjf_array_i32_getat(sjt_parent18, sjt_functionParam31, &sjt_call4.y);
#line 7 "lib/common/array.sj"
        sjt_parent19 = &sjv_xpos;
#line 149 "lib/ui/gridLayout.sj"
        sjt_functionParam32 = sjv_c + 1;
#line 149
        sjf_array_i32_getat(sjt_parent19, sjt_functionParam32, &sjt_capture6);
#line 7 "lib/common/array.sj"
        sjt_parent20 = &sjv_xpos;
#line 149 "lib/ui/gridLayout.sj"
        sjt_functionParam33 = sjv_c;
#line 149
        sjf_array_i32_getat(sjt_parent20, sjt_functionParam33, &sjt_capture7);
#line 149
        sjt_call4.w = sjt_capture6 - sjt_capture7;
#line 7 "lib/common/array.sj"
        sjt_parent21 = &sjv_ypos;
#line 150 "lib/ui/gridLayout.sj"
        sjt_functionParam34 = sjv_r + 1;
#line 150
        sjf_array_i32_getat(sjt_parent21, sjt_functionParam34, &sjt_capture8);
#line 7 "lib/common/array.sj"
        sjt_parent22 = &sjv_ypos;
#line 150 "lib/ui/gridLayout.sj"
        sjt_functionParam35 = sjv_r;
#line 150
        sjf_array_i32_getat(sjt_parent22, sjt_functionParam35, &sjt_capture9);
#line 150
        sjt_call4.h = sjt_capture8 - sjt_capture9;
#line 150
        sjf_rect(&sjt_call4);
#line 146
        sjt_interfaceParam1 = &sjt_call4;
#line 146
        sjt_parent16._vtbl->setrect(sjt_parent16._parent, sjt_interfaceParam1);
#line 123
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
;
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
;
    if (sjv_xpos._refCount == 1) { sjf_array_i32_destroy(&sjv_xpos); }
;
    if (sjv_ypos._refCount == 1) { sjf_array_i32_destroy(&sjv_ypos); }
;
}

void sjf_gridunit(sjs_gridunit* _this) {
}

void sjf_gridunit_copy(sjs_gridunit* _this, sjs_gridunit* _from) {
#line 41 "lib/ui/gridLayout.sj"
    _this->amount = _from->amount;
#line 41
    _this->unittype = _from->unittype;
}

void sjf_gridunit_destroy(sjs_gridunit* _this) {
}

void sjf_gridunit_heap(sjs_gridunit* _this) {
}

void sjf_halt(sjs_string* reason) {
    sjs_string* sjt_parent111 = 0;

#line 1 "lib/common/halt.sj"
    sjt_parent111 = reason;
#line 1
    sjf_string_nullterminate(sjt_parent111);
#line 4
    halt("%s\n", (char*)reason->data.data);
}

void sjf_hash_fontkey_weak_font(sjs_hash_fontkey_weak_font* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(fontkey_weak_font_hash_type);
}

void sjf_hash_fontkey_weak_font__weakptrremovekey(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key) {
#line 180 "lib/common/hash.sj"
    #if false
#line 181
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;    
#line 182
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, key);
#line 183
    if (k != kh_end(p)) {
#line 184
        kh_del(fontkey_weak_font_hash_type, p, k);
#line 185
    }
#line 186
    #endif
}

void sjf_hash_fontkey_weak_font__weakptrremovevalue(sjs_hash_fontkey_weak_font* _parent, sjs_font* val) {
#line 192 "lib/common/hash.sj"
    #if true
#line 193
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;
#line 194
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 195
        if (kh_exist(p, k)) {
#line 196
            sjs_font* t = kh_value(p, k);
#line 197
            if (t == val) {
#line 198
                kh_del(fontkey_weak_font_hash_type, p, k);
#line 199
            }
#line 200
        }
#line 201
    }
#line 202
    #endif
}

void sjf_hash_fontkey_weak_font_copy(sjs_hash_fontkey_weak_font* _this, sjs_hash_fontkey_weak_font* _from) {
#line 230 "lib/common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_fontkey_weak_font_destroy(sjs_hash_fontkey_weak_font* _this) {
#line 236 "lib/common/hash.sj"
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_this->_hash;
#line 237
    p->refcount--;
#line 238
    if (p->refcount == 0) {
#line 239
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 240
            if (kh_exist(p, k)) {
#line 242
                #if false
#line 243
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovekey };
#line 244
                weakptr_cb_remove(kh_key(p, k), cb);
#line 245
                #else
#line 246
                ;
#line 247
                #endif
#line 249
                #if true
#line 250
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovevalue };
#line 251
                weakptr_cb_remove(kh_value(p, k), cb);
#line 252
                #else
#line 253
                delete_cb weakptrcb13 = { &kh_value(p, k), weakptr_clear };
if (kh_value(p, k) != 0) { weakptr_cb_remove(kh_value(p, k), weakptrcb13); }
;
#line 254
                #endif
#line 255
            }
#line 256
        }
#line 257
        kh_destroy(fontkey_weak_font_hash_type, _this->_hash);
#line 258
    }
}

void sjf_hash_fontkey_weak_font_getat(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font** _return) {
#line 23 "lib/common/hash.sj"
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;
#line 25
    #if true
#line 26
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, *key);
#line 27
    #else
#line 28
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, key);
#line 29
    #endif
#line 31
    if (k == kh_end(p)) {
#line 32
        #line 22 "lib/common/hash.sj"
(*_return) = 0;
#line 22
delete_cb weakptrcb20 = { &(*_return), weakptr_clear };
#line 22
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb20); }
return;
#line 33
    }
#line 34
    #line 22 "lib/common/hash.sj"
(*_return) = kh_val(p, k);
#line 22
delete_cb weakptrcb21 = { &(*_return), weakptr_clear };
#line 22
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb21); }
return;;
}

void sjf_hash_fontkey_weak_font_heap(sjs_hash_fontkey_weak_font* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(fontkey_weak_font_hash_type);
}

void sjf_hash_fontkey_weak_font_setat(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font* val) {
#line 40 "lib/common/hash.sj"
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;
#line 42
    #if true
#line 43
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, *key);
#line 44
    #else
#line 45
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, key);
#line 46
    #endif
#line 48
    if (k != kh_end(p)) {            
#line 49
    delete_cb weakptrcb22 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_remove(kh_val(p, k), weakptrcb22); }
;
#line 50
}
#line 52
int ret;
#line 53
#if true
#line 54
k = kh_put(fontkey_weak_font_hash_type, _parent->_hash, *key, &ret);
#line 55
#else
#line 56
k = kh_put(fontkey_weak_font_hash_type, _parent->_hash, key, &ret);
#line 57
#endif
#line 59
if (!ret) kh_del(fontkey_weak_font_hash_type, p, k);
#line 61
#if false
#line 62
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovekey };
#line 63
weakptr_cb_add(key, cb);
#line 64
#else
#line 65
sjs_fontkey t;
#line 66
t._refCount = 1;
#line 38 "lib/common/hash.sj"
sjf_fontkey_copy(&t, key);
;
#line 67
#endif
#line 69
#if true
#line 70
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovevalue };
#line 71
weakptr_cb_add(val, cb);
#line 72
kh_val(p, k) = val;
#line 73
#else
#line 74
#line 38 "lib/common/hash.sj"
kh_val(p, k) = val;
#line 38
delete_cb weakptrcb23 = { &kh_val(p, k), weakptr_clear };
#line 38
if (kh_val(p, k) != 0) { weakptr_cb_add(kh_val(p, k), weakptrcb23); }
;
#line 75
#endif
}

void sjf_hash_string_weak_iface_element(sjs_hash_string_weak_iface_element* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_element_hash_type);
}

void sjf_hash_string_weak_iface_element__weakptrremovekey(sjs_hash_string_weak_iface_element* _parent, sjs_string* key) {
#line 180 "lib/common/hash.sj"
    #if false
#line 181
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;    
#line 182
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, key);
#line 183
    if (k != kh_end(p)) {
#line 184
        kh_del(string_weak_iface_element_hash_type, p, k);
#line 185
    }
#line 186
    #endif
}

void sjf_hash_string_weak_iface_element__weakptrremovevalue(sjs_hash_string_weak_iface_element* _parent, sji_element val) {
#line 192 "lib/common/hash.sj"
    #if true
#line 193
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;
#line 194
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 195
        if (kh_exist(p, k)) {
#line 196
            sji_element t = kh_value(p, k);
#line 197
            if (t._parent == val._parent) {
#line 198
                kh_del(string_weak_iface_element_hash_type, p, k);
#line 199
            }
#line 200
        }
#line 201
    }
#line 202
    #endif
}

void sjf_hash_string_weak_iface_element_copy(sjs_hash_string_weak_iface_element* _this, sjs_hash_string_weak_iface_element* _from) {
#line 230 "lib/common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_string_weak_iface_element_destroy(sjs_hash_string_weak_iface_element* _this) {
#line 236 "lib/common/hash.sj"
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_this->_hash;
#line 237
    p->refcount--;
#line 238
    if (p->refcount == 0) {
#line 239
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 240
            if (kh_exist(p, k)) {
#line 242
                #if false
#line 243
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovekey };
#line 244
                weakptr_cb_remove(kh_key(p, k), cb);
#line 245
                #else
#line 246
                ;
#line 247
                #endif
#line 249
                #if true
#line 250
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovevalue };
#line 251
                weakptr_cb_remove(kh_value(p, k)._parent, cb);
#line 252
                #else
#line 253
                delete_cb weakptrcb12 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb12); }
;
#line 254
                #endif
#line 255
            }
#line 256
        }
#line 257
        kh_destroy(string_weak_iface_element_hash_type, _this->_hash);
#line 258
    }
}

void sjf_hash_string_weak_iface_element_getat(sjs_hash_string_weak_iface_element* _parent, sjs_string* key, sji_element* _return) {
#line 23 "lib/common/hash.sj"
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;
#line 25
    #if true
#line 26
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, *key);
#line 27
    #else
#line 28
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, key);
#line 29
    #endif
#line 31
    if (k == kh_end(p)) {
#line 32
        #line 22 "lib/common/hash.sj"
(*_return)._parent = 0;
return;
#line 33
    }
#line 34
    #line 22 "lib/common/hash.sj"
(*_return) = kh_val(p, k);
#line 22
delete_cb weakptrcb25 = { &(*_return)._parent, weakptr_clear };
#line 22
if ((*_return)._parent != 0) { weakptr_cb_add((*_return)._parent, weakptrcb25); }
return;;
}

void sjf_hash_string_weak_iface_element_heap(sjs_hash_string_weak_iface_element* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_element_hash_type);
}

void sjf_hash_string_weak_iface_element_setat(sjs_hash_string_weak_iface_element* _parent, sjs_string* key, sji_element val) {
#line 40 "lib/common/hash.sj"
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;
#line 42
    #if true
#line 43
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, *key);
#line 44
    #else
#line 45
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, key);
#line 46
    #endif
#line 48
    if (k != kh_end(p)) {            
#line 49
    delete_cb weakptrcb26 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_remove(kh_val(p, k)._parent, weakptrcb26); }
;
#line 50
}
#line 52
int ret;
#line 53
#if true
#line 54
k = kh_put(string_weak_iface_element_hash_type, _parent->_hash, *key, &ret);
#line 55
#else
#line 56
k = kh_put(string_weak_iface_element_hash_type, _parent->_hash, key, &ret);
#line 57
#endif
#line 59
if (!ret) kh_del(string_weak_iface_element_hash_type, p, k);
#line 61
#if false
#line 62
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovekey };
#line 63
weakptr_cb_add(key, cb);
#line 64
#else
#line 65
sjs_string t;
#line 66
t._refCount = 1;
#line 38 "lib/common/hash.sj"
sjf_string_copy(&t, key);
;
#line 67
#endif
#line 69
#if true
#line 70
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovevalue };
#line 71
weakptr_cb_add(val._parent, cb);
#line 72
kh_val(p, k) = val;
#line 73
#else
#line 74
#line 38 "lib/common/hash.sj"
kh_val(p, k) = val;
#line 38
delete_cb weakptrcb27 = { &kh_val(p, k)._parent, weakptr_clear };
#line 38
if (kh_val(p, k)._parent != 0) { weakptr_cb_add(kh_val(p, k)._parent, weakptrcb27); }
;
#line 75
#endif
}

void sjf_hash_string_weak_iface_model(sjs_hash_string_weak_iface_model* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_model_hash_type);
}

void sjf_hash_string_weak_iface_model__weakptrremovekey(sjs_hash_string_weak_iface_model* _parent, sjs_string* key) {
#line 180 "lib/common/hash.sj"
    #if false
#line 181
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;    
#line 182
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, key);
#line 183
    if (k != kh_end(p)) {
#line 184
        kh_del(string_weak_iface_model_hash_type, p, k);
#line 185
    }
#line 186
    #endif
}

void sjf_hash_string_weak_iface_model__weakptrremovevalue(sjs_hash_string_weak_iface_model* _parent, sji_model val) {
#line 192 "lib/common/hash.sj"
    #if true
#line 193
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;
#line 194
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 195
        if (kh_exist(p, k)) {
#line 196
            sji_model t = kh_value(p, k);
#line 197
            if (t._parent == val._parent) {
#line 198
                kh_del(string_weak_iface_model_hash_type, p, k);
#line 199
            }
#line 200
        }
#line 201
    }
#line 202
    #endif
}

void sjf_hash_string_weak_iface_model_copy(sjs_hash_string_weak_iface_model* _this, sjs_hash_string_weak_iface_model* _from) {
#line 230 "lib/common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_string_weak_iface_model_destroy(sjs_hash_string_weak_iface_model* _this) {
#line 236 "lib/common/hash.sj"
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_this->_hash;
#line 237
    p->refcount--;
#line 238
    if (p->refcount == 0) {
#line 239
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 240
            if (kh_exist(p, k)) {
#line 242
                #if false
#line 243
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovekey };
#line 244
                weakptr_cb_remove(kh_key(p, k), cb);
#line 245
                #else
#line 246
                ;
#line 247
                #endif
#line 249
                #if true
#line 250
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovevalue };
#line 251
                weakptr_cb_remove(kh_value(p, k)._parent, cb);
#line 252
                #else
#line 253
                delete_cb weakptrcb11 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb11); }
;
#line 254
                #endif
#line 255
            }
#line 256
        }
#line 257
        kh_destroy(string_weak_iface_model_hash_type, _this->_hash);
#line 258
    }
}

void sjf_hash_string_weak_iface_model_heap(sjs_hash_string_weak_iface_model* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_model_hash_type);
}

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
#line 180 "lib/common/hash.sj"
    #if false
#line 181
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;    
#line 182
    khiter_t k = kh_get(type_bool_hash_type, p, key);
#line 183
    if (k != kh_end(p)) {
#line 184
        kh_del(type_bool_hash_type, p, k);
#line 185
    }
#line 186
    #endif
}

void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val) {
#line 192 "lib/common/hash.sj"
    #if false
#line 193
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
#line 194
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 195
        if (kh_exist(p, k)) {
#line 196
            bool t = kh_value(p, k);
#line 197
            if (t == val) {
#line 198
                kh_del(type_bool_hash_type, p, k);
#line 199
            }
#line 200
        }
#line 201
    }
#line 202
    #endif
}

void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from) {
#line 230 "lib/common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
#line 236 "lib/common/hash.sj"
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 237
    p->refcount--;
#line 238
    if (p->refcount == 0) {
#line 239
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 240
            if (kh_exist(p, k)) {
#line 242
                #if false
#line 243
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovekey };
#line 244
                weakptr_cb_remove(kh_key(p, k), cb);
#line 245
                #else
#line 246
                ;
#line 247
                #endif
#line 249
                #if false
#line 250
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovevalue };
#line 251
                weakptr_cb_remove(kh_value(p, k), cb);
#line 252
                #else
#line 253
                ;
#line 254
                #endif
#line 255
            }
#line 256
        }
#line 257
        kh_destroy(type_bool_hash_type, _this->_hash);
#line 258
    }
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_i32_asmargin(int32_t x, sjs_margin* _return) {
    _return->_refCount = 1;
#line 8 "lib/ui/margin.sj"
    _return->l = x;
#line 8
    _return->t = x;
#line 8
    _return->r = x;
#line 8
    _return->b = x;
#line 8
    sjf_margin(_return);
}

void sjf_i32_asmargin_heap(int32_t x, sjs_margin** _return) {
    (*_return) = (sjs_margin*)malloc(sizeof(sjs_margin));
    (*_return)->_refCount = 1;
#line 8 "lib/ui/margin.sj"
    (*_return)->l = x;
#line 8
    (*_return)->t = x;
#line 8
    (*_return)->r = x;
#line 8
    (*_return)->b = x;
#line 8
    sjf_margin_heap((*_return));
}

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t sjv_count;
    void* sjv_data;

#line 23 "lib/common/i32.sj"
    sjv_count = 0;
#line 24
    sjv_data = 0;
#line 26
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 27
    int* refcount = (int*)sjv_data - 1;
#line 28
    *refcount = 1;
#line 30
    char *tmp = (char*)sjv_data + 128;
#line 31
    char *tp = (char*)sjv_data + 128;
#line 32
    int i;
#line 33
    unsigned v;
#line 35
    int sign = (base == 10 && val < 0);    
#line 36
    if (sign)
#line 37
    v = -val;
#line 38
    else
#line 39
    v = (unsigned)val;
#line 41
    while (v || tp == tmp)
#line 42
    {
#line 43
        i = v % base;
#line 44
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 45
        if (i < 10)
#line 46
        *tp++ = i + '0';
#line 47
        else
#line 48
        *tp++ = i + 'a' - 10;
#line 49
    }
#line 51
    int len = tp - tmp;
#line 53
    char* sp = (char*)sjv_data;
#line 54
    if (sign) 
#line 55
    {
#line 56
        *sp++ = '-';
#line 57
        len++;
#line 58
    }
#line 60
    while (tp > tmp)
#line 61
    *sp++ = *--tp;
#line 63
    sjv_count = len;
#line 63
    _return->_refCount = 1;
#line 65
    _return->count = sjv_count;
#line 65
    _return->data._refCount = 1;
#line 65
    _return->data.datasize = 256;
#line 65
    _return->data.data = sjv_data;
#line 4 "lib/common/array.sj"
    _return->data.isglobal = false;
#line 65 "lib/common/i32.sj"
    _return->data.count = sjv_count;
#line 65
    sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t sjv_count;
    void* sjv_data;

#line 23 "lib/common/i32.sj"
    sjv_count = 0;
#line 24
    sjv_data = 0;
#line 26
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 27
    int* refcount = (int*)sjv_data - 1;
#line 28
    *refcount = 1;
#line 30
    char *tmp = (char*)sjv_data + 128;
#line 31
    char *tp = (char*)sjv_data + 128;
#line 32
    int i;
#line 33
    unsigned v;
#line 35
    int sign = (base == 10 && val < 0);    
#line 36
    if (sign)
#line 37
    v = -val;
#line 38
    else
#line 39
    v = (unsigned)val;
#line 41
    while (v || tp == tmp)
#line 42
    {
#line 43
        i = v % base;
#line 44
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 45
        if (i < 10)
#line 46
        *tp++ = i + '0';
#line 47
        else
#line 48
        *tp++ = i + 'a' - 10;
#line 49
    }
#line 51
    int len = tp - tmp;
#line 53
    char* sp = (char*)sjv_data;
#line 54
    if (sign) 
#line 55
    {
#line 56
        *sp++ = '-';
#line 57
        len++;
#line 58
    }
#line 60
    while (tp > tmp)
#line 61
    *sp++ = *--tp;
#line 63
    sjv_count = len;
#line 63
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 63
    (*_return)->_refCount = 1;
#line 65
    (*_return)->count = sjv_count;
#line 65
    (*_return)->data._refCount = 1;
#line 65
    (*_return)->data.datasize = 256;
#line 65
    (*_return)->data.data = sjv_data;
#line 4 "lib/common/array.sj"
    (*_return)->data.isglobal = false;
#line 65 "lib/common/i32.sj"
    (*_return)->data.count = sjv_count;
#line 65
    sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));
}

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    if (a < b) {
#line 6 "lib/common/i32.sj"
        (*_return) = b;
    } else {
#line 6 "lib/common/i32.sj"
        (*_return) = a;
    }
}

void sjf_image(sjs_image* _this) {
    sjs_rect sjt_funcold2 = { -1 };
    sjs_size sjv_size = { -1 };

    if (((&_this->rect)->w == 0) && ((&_this->rect)->h == 0)) {
        sjs_texture* sjt_parent29 = 0;

#line 1 "lib/ui/image.sj"
        sjt_parent29 = &_this->texture;
#line 1
        sjf_texture_getsize(sjt_parent29, &sjv_size);
#line 1
        sjt_funcold2._refCount = 1;
#line 1 "lib/ui/rect.sj"
        sjf_rect_copy(&sjt_funcold2, &_this->rect);
#line 1
        sjt_funcold2._refCount = 1;
#line 8 "lib/ui/image.sj"
        sjt_funcold2.x = 0;
#line 8
        sjt_funcold2.y = 0;
#line 8
        sjt_funcold2.w = (&sjv_size)->w;
#line 8
        sjt_funcold2.h = (&sjv_size)->h;
#line 8
        sjf_rect(&sjt_funcold2);
#line 8
        if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
#line 1 "lib/ui/rect.sj"
        sjf_rect_copy(&_this->rect, &sjt_funcold2);
    }

    if (sjt_funcold2._refCount == 1) { sjf_rect_destroy(&sjt_funcold2); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_image_copy(sjs_image* _this, sjs_image* _from) {
    _this->texture._refCount = 1;
#line 1 "lib/ui/image.sj"
    sjf_texture_copy(&_this->texture, &_from->texture);
#line 1
    _this->rect._refCount = 1;
#line 1
    sjf_rect_copy(&_this->rect, &_from->rect);
#line 1
    _this->margin._refCount = 1;
#line 1
    sjf_margin_copy(&_this->margin, &_from->margin);
}

void sjf_image_destroy(sjs_image* _this) {
    if (_this->texture._refCount == 1) { sjf_texture_destroy(&_this->texture); }
;
    if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
}

void sjf_image_heap(sjs_image* _this) {
    sjs_rect sjt_funcold3 = { -1 };
    sjs_size sjv_size = { -1 };

    if (((&_this->rect)->w == 0) && ((&_this->rect)->h == 0)) {
        sjs_texture* sjt_parent30 = 0;

#line 5 "lib/ui/texture.sj"
        sjt_parent30 = &_this->texture;
#line 5
        sjf_texture_getsize(sjt_parent30, &sjv_size);
#line 5
        sjt_funcold3._refCount = 1;
#line 1 "lib/ui/rect.sj"
        sjf_rect_copy(&sjt_funcold3, &_this->rect);
#line 1
        sjt_funcold3._refCount = 1;
#line 8 "lib/ui/image.sj"
        sjt_funcold3.x = 0;
#line 8
        sjt_funcold3.y = 0;
#line 8
        sjt_funcold3.w = (&sjv_size)->w;
#line 8
        sjt_funcold3.h = (&sjv_size)->h;
#line 8
        sjf_rect(&sjt_funcold3);
#line 8
        if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
#line 1 "lib/ui/rect.sj"
        sjf_rect_copy(&_this->rect, &sjt_funcold3);
    }

    if (sjt_funcold3._refCount == 1) { sjf_rect_destroy(&sjt_funcold3); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_imagerenderer(sjs_imagerenderer* _this) {
#line 23 "lib/ui/imageRenderer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
#line 24
    float x0 = (float)_this->rect.x;
#line 25
    float x1 = (float)(_this->rect.x + _this->image.margin.l);
#line 26
    float x2 = (float)(_this->rect.x + _this->rect.w - _this->image.margin.r);
#line 27
    float x3 = (float)(_this->rect.x + _this->rect.w);
#line 29
    float y0 = (float)_this->rect.y;
#line 30
    float y1 = (float)(_this->rect.y + _this->image.margin.t);
#line 31
    float y2 = (float)(_this->rect.y + _this->rect.h - _this->image.margin.b);
#line 32
    float y3 = (float)(_this->rect.y + _this->rect.h);
#line 34
    float s0 = (float)_this->image.rect.x / (float)_this->image.texture.size.w;
#line 35
    float s1 = (float)(_this->image.rect.x + _this->image.margin.l) / (float)_this->image.texture.size.w;
#line 36
    float s2 = (float)(_this->image.rect.x + _this->image.rect.w - _this->image.margin.r) / (float)_this->image.texture.size.w;
#line 37
    float s3 = (float)(_this->image.rect.x + _this->image.rect.w) / (float)_this->image.texture.size.w;
#line 39
    float t3 = (float)_this->image.rect.y / (float)_this->image.texture.size.h;
#line 40
    float t2 = (float)(_this->image.rect.y + _this->image.margin.b) / (float)_this->image.texture.size.h;
#line 41
    float t1 = (float)(_this->image.rect.y + _this->image.rect.h - _this->image.margin.t) / (float)_this->image.texture.size.h;
#line 42
    float t0 = (float)(_this->image.rect.y + _this->image.rect.h) / (float)_this->image.texture.size.h;
#line 44
    if (_this->image.margin.t > 0) {
#line 45
        if (_this->image.margin.l > 0) {
#line 46
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 47
            GLuint indices[] = { //
#line 48
            index, index+1, index+2,
#line 49
            index, index+2, index+3 };
#line 50
            vertex3_texture2_t vertices[] = { //
#line 51
            { x0, y0, 0.0f,  s0, t0 },
#line 52
            { x0, y1, 0.0f,  s0, t1 },
#line 53
            { x1, y1, 0.0f,  s1, t1 },
#line 54
            { x1, y0, 0.0f,  s1, t0 } };        
#line 55
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 56
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 57
        }
#line 59
        {
#line 60
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 61
            GLuint indices[] = { //
#line 62
            index, index+1, index+2,
#line 63
            index, index+2, index+3 };
#line 64
            vertex3_texture2_t vertices[] = { //
#line 65
            { x1, y0, 0.0f,  s1, t0 },
#line 66
            { x1, y1, 0.0f,  s1, t1 },
#line 67
            { x2, y1, 0.0f,  s2, t1 },
#line 68
            { x2, y0, 0.0f,  s2, t0 } };        
#line 69
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 70
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 71
        }
#line 73
        if (_this->image.margin.r > 0) {
#line 74
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 75
            GLuint indices[] = { //
#line 76
            index, index+1, index+2,
#line 77
            index, index+2, index+3 };
#line 78
            vertex3_texture2_t vertices[] = { //
#line 79
            { x2, y0, 0.0f,  s2, t0 },
#line 80
            { x2, y1, 0.0f,  s2, t1 },
#line 81
            { x3, y1, 0.0f,  s3, t1 },
#line 82
            { x3, y0, 0.0f,  s3, t0 } };        
#line 83
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 84
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 85
        }
#line 86
    }
#line 88
    {
#line 89
        if (_this->image.margin.l > 0) {
#line 90
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 91
            GLuint indices[] = { //
#line 92
            index, index+1, index+2,
#line 93
            index, index+2, index+3 };
#line 94
            vertex3_texture2_t vertices[] = { //
#line 95
            { x0, y1, 0.0f,  s0, t1 },
#line 96
            { x0, y2, 0.0f,  s0, t2 },
#line 97
            { x1, y2, 0.0f,  s1, t2 },
#line 98
            { x1, y1, 0.0f,  s1, t1 } };        
#line 99
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 100
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 101
        }
#line 103
        {
#line 104
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 105
            GLuint indices[] = { //
#line 106
            index, index+1, index+2,
#line 107
            index, index+2, index+3 };
#line 108
            vertex3_texture2_t vertices[] = { //
#line 109
            { x1, y1, 0.0f,  s1, t1 },
#line 110
            { x1, y2, 0.0f,  s1, t2 },
#line 111
            { x2, y2, 0.0f,  s2, t2 },
#line 112
            { x2, y1, 0.0f,  s2, t1 } };        
#line 113
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 114
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 115
        }
#line 117
        if (_this->image.margin.r > 0) {
#line 118
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 119
            GLuint indices[] = { //
#line 120
            index, index+1, index+2,
#line 121
            index, index+2, index+3 };
#line 122
            vertex3_texture2_t vertices[] = { //
#line 123
            { x2, y1, 0.0f,  s2, t1 },
#line 124
            { x2, y2, 0.0f,  s2, t2 },
#line 125
            { x3, y2, 0.0f,  s3, t2 },
#line 126
            { x3, y1, 0.0f,  s3, t1 } };        
#line 127
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 128
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 129
        }
#line 130
    }
#line 132
    if (_this->image.margin.b > 0) {
#line 133
        if (_this->image.margin.l > 0) {
#line 134
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 135
            GLuint indices[] = { //
#line 136
            index, index+1, index+2,
#line 137
            index, index+2, index+3 };
#line 138
            vertex3_texture2_t vertices[] = { //
#line 139
            { x0, y2, 0.0f,  s0, t2 },
#line 140
            { x0, y3, 0.0f,  s0, t3 },
#line 141
            { x1, y3, 0.0f,  s1, t3 },
#line 142
            { x1, y2, 0.0f,  s1, t2 } };        
#line 143
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 144
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 145
        }
#line 147
        {
#line 148
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 149
            GLuint indices[] = { //
#line 150
            index, index+1, index+2,
#line 151
            index, index+2, index+3 };
#line 152
            vertex3_texture2_t vertices[] = { //
#line 153
            { x1, y2, 0.0f,  s1, t2 },
#line 154
            { x1, y3, 0.0f,  s1, t3 },
#line 155
            { x2, y3, 0.0f,  s2, t3 },
#line 156
            { x2, y2, 0.0f,  s2, t2 } };        
#line 157
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 158
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 159
        }
#line 161
        if (_this->image.margin.r > 0) {
#line 162
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 163
            GLuint indices[] = { //
#line 164
            index, index+1, index+2,
#line 165
            index, index+2, index+3 };
#line 166
            vertex3_texture2_t vertices[] = { //
#line 167
            { x2, y2, 0.0f,  s2, t2 },
#line 168
            { x2, y3, 0.0f,  s2, t3 },
#line 169
            { x3, y3, 0.0f,  s3, t3 },
#line 170
            { x3, y2, 0.0f,  s3, t2 } };        
#line 171
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 172
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 173
        }
#line 174
    }
}

void sjf_imagerenderer_copy(sjs_imagerenderer* _this, sjs_imagerenderer* _from) {
    _this->rect._refCount = 1;
#line 1 "lib/ui/imageRenderer.sj"
    sjf_rect_copy(&_this->rect, &_from->rect);
#line 1
    _this->image._refCount = 1;
#line 1
    sjf_image_copy(&_this->image, &_from->image);
#line 180
    _this->buffer = _from->buffer;
#line 181
    ptr_retain(_this->buffer);
}

void sjf_imagerenderer_destroy(sjs_imagerenderer* _this) {
#line 185 "lib/ui/imageRenderer.sj"
    if (ptr_release(_this->buffer)) {
#line 186
        vertex_buffer_delete(_this->buffer);
#line 187
    }  
#line 187
    if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
#line 187
    if (_this->image._refCount == 1) { sjf_image_destroy(&_this->image); }
;
}

void sjf_imagerenderer_heap(sjs_imagerenderer* _this) {
#line 23 "lib/ui/imageRenderer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
#line 24
    float x0 = (float)_this->rect.x;
#line 25
    float x1 = (float)(_this->rect.x + _this->image.margin.l);
#line 26
    float x2 = (float)(_this->rect.x + _this->rect.w - _this->image.margin.r);
#line 27
    float x3 = (float)(_this->rect.x + _this->rect.w);
#line 29
    float y0 = (float)_this->rect.y;
#line 30
    float y1 = (float)(_this->rect.y + _this->image.margin.t);
#line 31
    float y2 = (float)(_this->rect.y + _this->rect.h - _this->image.margin.b);
#line 32
    float y3 = (float)(_this->rect.y + _this->rect.h);
#line 34
    float s0 = (float)_this->image.rect.x / (float)_this->image.texture.size.w;
#line 35
    float s1 = (float)(_this->image.rect.x + _this->image.margin.l) / (float)_this->image.texture.size.w;
#line 36
    float s2 = (float)(_this->image.rect.x + _this->image.rect.w - _this->image.margin.r) / (float)_this->image.texture.size.w;
#line 37
    float s3 = (float)(_this->image.rect.x + _this->image.rect.w) / (float)_this->image.texture.size.w;
#line 39
    float t3 = (float)_this->image.rect.y / (float)_this->image.texture.size.h;
#line 40
    float t2 = (float)(_this->image.rect.y + _this->image.margin.b) / (float)_this->image.texture.size.h;
#line 41
    float t1 = (float)(_this->image.rect.y + _this->image.rect.h - _this->image.margin.t) / (float)_this->image.texture.size.h;
#line 42
    float t0 = (float)(_this->image.rect.y + _this->image.rect.h) / (float)_this->image.texture.size.h;
#line 44
    if (_this->image.margin.t > 0) {
#line 45
        if (_this->image.margin.l > 0) {
#line 46
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 47
            GLuint indices[] = { //
#line 48
            index, index+1, index+2,
#line 49
            index, index+2, index+3 };
#line 50
            vertex3_texture2_t vertices[] = { //
#line 51
            { x0, y0, 0.0f,  s0, t0 },
#line 52
            { x0, y1, 0.0f,  s0, t1 },
#line 53
            { x1, y1, 0.0f,  s1, t1 },
#line 54
            { x1, y0, 0.0f,  s1, t0 } };        
#line 55
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 56
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 57
        }
#line 59
        {
#line 60
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 61
            GLuint indices[] = { //
#line 62
            index, index+1, index+2,
#line 63
            index, index+2, index+3 };
#line 64
            vertex3_texture2_t vertices[] = { //
#line 65
            { x1, y0, 0.0f,  s1, t0 },
#line 66
            { x1, y1, 0.0f,  s1, t1 },
#line 67
            { x2, y1, 0.0f,  s2, t1 },
#line 68
            { x2, y0, 0.0f,  s2, t0 } };        
#line 69
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 70
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 71
        }
#line 73
        if (_this->image.margin.r > 0) {
#line 74
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 75
            GLuint indices[] = { //
#line 76
            index, index+1, index+2,
#line 77
            index, index+2, index+3 };
#line 78
            vertex3_texture2_t vertices[] = { //
#line 79
            { x2, y0, 0.0f,  s2, t0 },
#line 80
            { x2, y1, 0.0f,  s2, t1 },
#line 81
            { x3, y1, 0.0f,  s3, t1 },
#line 82
            { x3, y0, 0.0f,  s3, t0 } };        
#line 83
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 84
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 85
        }
#line 86
    }
#line 88
    {
#line 89
        if (_this->image.margin.l > 0) {
#line 90
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 91
            GLuint indices[] = { //
#line 92
            index, index+1, index+2,
#line 93
            index, index+2, index+3 };
#line 94
            vertex3_texture2_t vertices[] = { //
#line 95
            { x0, y1, 0.0f,  s0, t1 },
#line 96
            { x0, y2, 0.0f,  s0, t2 },
#line 97
            { x1, y2, 0.0f,  s1, t2 },
#line 98
            { x1, y1, 0.0f,  s1, t1 } };        
#line 99
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 100
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 101
        }
#line 103
        {
#line 104
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 105
            GLuint indices[] = { //
#line 106
            index, index+1, index+2,
#line 107
            index, index+2, index+3 };
#line 108
            vertex3_texture2_t vertices[] = { //
#line 109
            { x1, y1, 0.0f,  s1, t1 },
#line 110
            { x1, y2, 0.0f,  s1, t2 },
#line 111
            { x2, y2, 0.0f,  s2, t2 },
#line 112
            { x2, y1, 0.0f,  s2, t1 } };        
#line 113
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 114
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 115
        }
#line 117
        if (_this->image.margin.r > 0) {
#line 118
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 119
            GLuint indices[] = { //
#line 120
            index, index+1, index+2,
#line 121
            index, index+2, index+3 };
#line 122
            vertex3_texture2_t vertices[] = { //
#line 123
            { x2, y1, 0.0f,  s2, t1 },
#line 124
            { x2, y2, 0.0f,  s2, t2 },
#line 125
            { x3, y2, 0.0f,  s3, t2 },
#line 126
            { x3, y1, 0.0f,  s3, t1 } };        
#line 127
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 128
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 129
        }
#line 130
    }
#line 132
    if (_this->image.margin.b > 0) {
#line 133
        if (_this->image.margin.l > 0) {
#line 134
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 135
            GLuint indices[] = { //
#line 136
            index, index+1, index+2,
#line 137
            index, index+2, index+3 };
#line 138
            vertex3_texture2_t vertices[] = { //
#line 139
            { x0, y2, 0.0f,  s0, t2 },
#line 140
            { x0, y3, 0.0f,  s0, t3 },
#line 141
            { x1, y3, 0.0f,  s1, t3 },
#line 142
            { x1, y2, 0.0f,  s1, t2 } };        
#line 143
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 144
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 145
        }
#line 147
        {
#line 148
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 149
            GLuint indices[] = { //
#line 150
            index, index+1, index+2,
#line 151
            index, index+2, index+3 };
#line 152
            vertex3_texture2_t vertices[] = { //
#line 153
            { x1, y2, 0.0f,  s1, t2 },
#line 154
            { x1, y3, 0.0f,  s1, t3 },
#line 155
            { x2, y3, 0.0f,  s2, t3 },
#line 156
            { x2, y2, 0.0f,  s2, t2 } };        
#line 157
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 158
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 159
        }
#line 161
        if (_this->image.margin.r > 0) {
#line 162
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 163
            GLuint indices[] = { //
#line 164
            index, index+1, index+2,
#line 165
            index, index+2, index+3 };
#line 166
            vertex3_texture2_t vertices[] = { //
#line 167
            { x2, y2, 0.0f,  s2, t2 },
#line 168
            { x2, y3, 0.0f,  s2, t3 },
#line 169
            { x3, y3, 0.0f,  s3, t3 },
#line 170
            { x3, y2, 0.0f,  s3, t2 } };        
#line 171
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 172
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 173
        }
#line 174
    }
}

void sjf_imagerenderer_render(sjs_imagerenderer* _parent, sjs_scene2d* scene) {
    sjs_string sjt_call10 = { -1 };
    sjs_string sjt_call11 = { -1 };
    sjs_string sjt_call8 = { -1 };
    sjs_string sjt_call9 = { -1 };
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

#line 9 "lib/ui/imageRenderer.sj"
    sjt_functionParam50 = sjv_gltexture_gl_texture_2d;
#line 9
    sjt_functionParam51 = &(&_parent->image)->texture;
#line 9
    sjf_glbindtexture(sjt_functionParam50, sjt_functionParam51);
#line 10
    sjt_functionParam52 = &sjv_imageshader;
#line 10
    sjf_gluseprogram(sjt_functionParam52);
#line 11
    sjt_functionParam53 = sjv_glblendfunctype_gl_src_alpha;
#line 11
    sjt_functionParam54 = sjv_glblendfunctype_gl_one_minus_src_alpha;
#line 11
    sjf_glblendfunc(sjt_functionParam53, sjt_functionParam54);
#line 12
    sjt_functionParam56 = &sjv_imageshader;
#line 12
    sjt_call8._refCount = 1;
#line 12
    sjt_call8.count = 7;
#line 12
    sjt_call8.data._refCount = 1;
#line 12
    sjt_call8.data.datasize = 7;
#line 12
    sjt_call8.data.data = (void*)sjg_string21;
#line 12
    sjt_call8.data.isglobal = true;
#line 12
    sjt_call8.data.count = 7;
#line 12
    sjf_array_char(&sjt_call8.data);
#line 14 "lib/common/string.sj"
    sjt_call8._isnullterminated = false;
#line 14
    sjf_string(&sjt_call8);
#line 12 "lib/ui/imageRenderer.sj"
    sjt_functionParam57 = &sjt_call8;
#line 12
    sjf_glgetuniformlocation(sjt_functionParam56, sjt_functionParam57, &sjt_functionParam55);
#line 12
    sjt_functionParam58 = 0;
#line 12
    sjf_gluniformi32(sjt_functionParam55, sjt_functionParam58);
#line 13
    sjt_functionParam60 = &sjv_imageshader;
#line 13
    sjt_call9._refCount = 1;
#line 13
    sjt_call9.count = 5;
#line 13
    sjt_call9.data._refCount = 1;
#line 13
    sjt_call9.data.datasize = 5;
#line 13
    sjt_call9.data.data = (void*)sjg_string22;
#line 13
    sjt_call9.data.isglobal = true;
#line 13
    sjt_call9.data.count = 5;
#line 13
    sjf_array_char(&sjt_call9.data);
#line 14 "lib/common/string.sj"
    sjt_call9._isnullterminated = false;
#line 14
    sjf_string(&sjt_call9);
#line 13 "lib/ui/imageRenderer.sj"
    sjt_functionParam61 = &sjt_call9;
#line 13
    sjf_glgetuniformlocation(sjt_functionParam60, sjt_functionParam61, &sjt_functionParam59);
#line 13
    sjt_functionParam62 = &scene->model;
#line 13
    sjf_gluniformmat4(sjt_functionParam59, sjt_functionParam62);
#line 14
    sjt_functionParam64 = &sjv_imageshader;
#line 14
    sjt_call10._refCount = 1;
#line 14
    sjt_call10.count = 4;
#line 14
    sjt_call10.data._refCount = 1;
#line 14
    sjt_call10.data.datasize = 4;
#line 14
    sjt_call10.data.data = (void*)sjg_string23;
#line 14
    sjt_call10.data.isglobal = true;
#line 14
    sjt_call10.data.count = 4;
#line 14
    sjf_array_char(&sjt_call10.data);
#line 14 "lib/common/string.sj"
    sjt_call10._isnullterminated = false;
#line 14
    sjf_string(&sjt_call10);
#line 14 "lib/ui/imageRenderer.sj"
    sjt_functionParam65 = &sjt_call10;
#line 14
    sjf_glgetuniformlocation(sjt_functionParam64, sjt_functionParam65, &sjt_functionParam63);
#line 14
    sjt_functionParam66 = &scene->view;
#line 14
    sjf_gluniformmat4(sjt_functionParam63, sjt_functionParam66);
#line 15
    sjt_functionParam68 = &sjv_imageshader;
#line 15
    sjt_call11._refCount = 1;
#line 15
    sjt_call11.count = 10;
#line 15
    sjt_call11.data._refCount = 1;
#line 15
    sjt_call11.data.datasize = 10;
#line 15
    sjt_call11.data.data = (void*)sjg_string24;
#line 15
    sjt_call11.data.isglobal = true;
#line 15
    sjt_call11.data.count = 10;
#line 15
    sjf_array_char(&sjt_call11.data);
#line 14 "lib/common/string.sj"
    sjt_call11._isnullterminated = false;
#line 14
    sjf_string(&sjt_call11);
#line 15 "lib/ui/imageRenderer.sj"
    sjt_functionParam69 = &sjt_call11;
#line 15
    sjf_glgetuniformlocation(sjt_functionParam68, sjt_functionParam69, &sjt_functionParam67);
#line 15
    sjt_functionParam70 = &scene->projection;
#line 15
    sjf_gluniformmat4(sjt_functionParam67, sjt_functionParam70);
#line 17
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);

    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
;
    if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
;
    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
    if (sjt_call9._refCount == 1) { sjf_string_destroy(&sjt_call9); }
;
}

void sjf_light(sjs_light* _this) {
}

void sjf_light_copy(sjs_light* _this, sjs_light* _from) {
    _this->pos._refCount = 1;
#line 1 "lib/ui/scene3dElement.sj"
    sjf_vec3_copy(&_this->pos, &_from->pos);
#line 1
    _this->diffusecolor._refCount = 1;
#line 1
    sjf_color_copy(&_this->diffusecolor, &_from->diffusecolor);
#line 1
    _this->speccolor._refCount = 1;
#line 1
    sjf_color_copy(&_this->speccolor, &_from->speccolor);
}

void sjf_light_destroy(sjs_light* _this) {
    if (_this->pos._refCount == 1) { sjf_vec3_destroy(&_this->pos); }
;
    if (_this->diffusecolor._refCount == 1) { sjf_color_destroy(&_this->diffusecolor); }
;
    if (_this->speccolor._refCount == 1) { sjf_color_destroy(&_this->speccolor); }
;
}

void sjf_light_heap(sjs_light* _this) {
}

void sjf_list_heap_iface_animation(sjs_list_heap_iface_animation* _this) {
}

void sjf_list_heap_iface_animation_copy(sjs_list_heap_iface_animation* _this, sjs_list_heap_iface_animation* _from) {
    _this->array._refCount = 1;
#line 1 "lib/common/list.sj"
    sjf_array_heap_iface_animation_copy(&_this->array, &_from->array);
}

void sjf_list_heap_iface_animation_destroy(sjs_list_heap_iface_animation* _this) {
    if (_this->array._refCount == 1) { sjf_array_heap_iface_animation_destroy(&_this->array); }
;
}

void sjf_list_heap_iface_animation_getat_heap(sjs_list_heap_iface_animation* _parent, int32_t index, sji_animation* _return) {
    int32_t sjt_functionParam157;
    sjs_array_heap_iface_animation* sjt_parent90 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent90 = &_parent->array;
#line 8 "lib/common/list.sj"
    sjt_functionParam157 = index;
#line 8
    sjf_array_heap_iface_animation_getat_heap(sjt_parent90, sjt_functionParam157, _return);
}

void sjf_list_heap_iface_animation_getcount(sjs_list_heap_iface_animation* _parent, int32_t* _return) {
#line 4 "lib/common/list.sj"
    (*_return) = (&_parent->array)->count;
}

void sjf_list_heap_iface_animation_heap(sjs_list_heap_iface_animation* _this) {
}

void sjf_list_heap_iface_animation_removeat(sjs_list_heap_iface_animation* _parent, int32_t index) {
#line 55 "lib/common/list.sj"
    if (index < 0 || index >= _parent->array.count) {
#line 56
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
#line 57
    }
#line 58
    sji_animation* p = (sji_animation*)_parent->array.data;
#line 59
    if (p[index]._parent != 0) {
    p[index]._parent->_refCount--;
    if (p[index]._parent->_refCount <= 0) {
        p[index]._vtbl->destroy(p[index]._parent);
        free(p[index]._parent);
    }
}
;
#line 60
    if (index != _parent->array.count - 1) {
#line 61
        memcpy(p + index, p + index + 1, (_parent->array.count - index - 1) * sizeof(sji_animation));
#line 62
    }
#line 63
    _parent->array.count--;
}

void sjf_list_heap_iface_model(sjs_list_heap_iface_model* _this) {
}

void sjf_list_heap_iface_model_copy(sjs_list_heap_iface_model* _this, sjs_list_heap_iface_model* _from) {
    _this->array._refCount = 1;
#line 1 "lib/common/list.sj"
    sjf_array_heap_iface_model_copy(&_this->array, &_from->array);
}

void sjf_list_heap_iface_model_destroy(sjs_list_heap_iface_model* _this) {
    if (_this->array._refCount == 1) { sjf_array_heap_iface_model_destroy(&_this->array); }
;
}

void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this) {
}

void sjf_list_rect(sjs_list_rect* _this) {
}

void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item) {
    sjs_array_rect sjt_funcold9 = { -1 };
    int32_t sjt_functionParam178;
    sjs_rect* sjt_functionParam179 = 0;
    sjs_array_rect* sjt_parent100 = 0;

    if ((&_parent->array)->count >= (&_parent->array)->datasize) {
        int32_t sjt_functionParam175;
        int32_t sjt_functionParam176;
        int32_t sjt_functionParam177;
        sjs_array_rect* sjt_parent99 = 0;

        sjt_funcold9._refCount = 1;
#line 134 "lib/common/array.sj"
        sjf_array_rect_copy(&sjt_funcold9, &_parent->array);
#line 134
        sjt_parent99 = &_parent->array;
#line 46 "lib/common/list.sj"
        sjt_functionParam176 = 10;
#line 46
        sjt_functionParam177 = (&_parent->array)->datasize * 2;
#line 46
        sjf_i32_max(sjt_functionParam176, sjt_functionParam177, &sjt_functionParam175);
#line 46
        sjf_array_rect_grow(sjt_parent99, sjt_functionParam175, &sjt_funcold9);
#line 46
        if (_parent->array._refCount == 1) { sjf_array_rect_destroy(&_parent->array); }
;
#line 134 "lib/common/array.sj"
        sjf_array_rect_copy(&_parent->array, &sjt_funcold9);
    }

#line 34 "lib/common/array.sj"
    sjt_parent100 = &_parent->array;
#line 50 "lib/common/list.sj"
    sjt_functionParam178 = (&_parent->array)->count;
#line 44
    sjt_functionParam179 = item;
#line 44
    sjf_array_rect_initat(sjt_parent100, sjt_functionParam178, sjt_functionParam179);

    if (sjt_funcold9._refCount == 1) { sjf_array_rect_destroy(&sjt_funcold9); }
;
}

void sjf_list_rect_copy(sjs_list_rect* _this, sjs_list_rect* _from) {
    _this->array._refCount = 1;
#line 1 "lib/common/list.sj"
    sjf_array_rect_copy(&_this->array, &_from->array);
}

void sjf_list_rect_destroy(sjs_list_rect* _this) {
    if (_this->array._refCount == 1) { sjf_array_rect_destroy(&_this->array); }
;
}

void sjf_list_rect_getat(sjs_list_rect* _parent, int32_t index, sjs_rect* _return) {
    int32_t sjt_functionParam184;
    sjs_array_rect* sjt_parent107 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent107 = &_parent->array;
#line 8 "lib/common/list.sj"
    sjt_functionParam184 = index;
#line 8
    sjf_array_rect_getat(sjt_parent107, sjt_functionParam184, _return);
}

void sjf_list_rect_getat_heap(sjs_list_rect* _parent, int32_t index, sjs_rect** _return) {
    int32_t sjt_functionParam185;
    sjs_array_rect* sjt_parent108 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent108 = &_parent->array;
#line 8 "lib/common/list.sj"
    sjt_functionParam185 = index;
#line 8
    sjf_array_rect_getat_heap(sjt_parent108, sjt_functionParam185, _return);
}

void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return) {
#line 4 "lib/common/list.sj"
    (*_return) = (&_parent->array)->count;
}

void sjf_list_rect_heap(sjs_list_rect* _this) {
}

void sjf_list_rect_removeat(sjs_list_rect* _parent, int32_t index) {
#line 55 "lib/common/list.sj"
    if (index < 0 || index >= _parent->array.count) {
#line 56
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
#line 57
    }
#line 58
    sjs_rect* p = (sjs_rect*)_parent->array.data;
#line 59
    ;
#line 60
    if (index != _parent->array.count - 1) {
#line 61
        memcpy(p + index, p + index + 1, (_parent->array.count - index - 1) * sizeof(sjs_rect));
#line 62
    }
#line 63
    _parent->array.count--;
}

void sjf_list_u32(sjs_list_u32* _this) {
}

void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from) {
    _this->array._refCount = 1;
#line 1 "lib/common/list.sj"
    sjf_array_u32_copy(&_this->array, &_from->array);
}

void sjf_list_u32_destroy(sjs_list_u32* _this) {
    if (_this->array._refCount == 1) { sjf_array_u32_destroy(&_this->array); }
;
}

void sjf_list_u32_heap(sjs_list_u32* _this) {
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
#line 13 "lib/common/log.sj"
    _this->minlevel = _from->minlevel;
#line 13
    sjs_hash_type_bool* copyoption2 = (_from->traceincludes._refCount != -1 ? &_from->traceincludes : 0);
    if (copyoption2 != 0) {
        _this->traceincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->traceincludes, copyoption2);
    } else {
        _this->traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption3 = (_from->debugincludes._refCount != -1 ? &_from->debugincludes : 0);
    if (copyoption3 != 0) {
        _this->debugincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->debugincludes, copyoption3);
    } else {
        _this->debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption4 = (_from->infoincludes._refCount != -1 ? &_from->infoincludes : 0);
    if (copyoption4 != 0) {
        _this->infoincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->infoincludes, copyoption4);
    } else {
        _this->infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption5 = (_from->warnincludes._refCount != -1 ? &_from->warnincludes : 0);
    if (copyoption5 != 0) {
        _this->warnincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->warnincludes, copyoption5);
    } else {
        _this->warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption6 = (_from->errorincludes._refCount != -1 ? &_from->errorincludes : 0);
    if (copyoption6 != 0) {
        _this->errorincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->errorincludes, copyoption6);
    } else {
        _this->errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption7 = (_from->fatalincludes._refCount != -1 ? &_from->fatalincludes : 0);
    if (copyoption7 != 0) {
        _this->fatalincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->fatalincludes, copyoption7);
    } else {
        _this->fatalincludes._refCount = -1;
    }
}

void sjf_log_destroy(sjs_log* _this) {
    if (_this->traceincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->traceincludes); }
;
    if (_this->debugincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->debugincludes); }
;
    if (_this->infoincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->infoincludes); }
;
    if (_this->warnincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->warnincludes); }
;
    if (_this->errorincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->errorincludes); }
;
    if (_this->fatalincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->fatalincludes); }
;
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_mainloop(void) {
    bool result13;
    sjs_string sjt_call39 = { -1 };
    sjs_string sjt_call40 = { -1 };
    sjs_string sjt_call41 = { -1 };
    bool sjt_capture20;
    int32_t sjt_functionParam160;
    sjs_size* sjt_functionParam174 = 0;
    sjs_rect* sjt_functionParam183 = 0;
    sjs_scene2d* sjt_interfaceParam11 = 0;
    sjs_scene2d* sjt_parent102 = 0;
    sjs_rect* sjt_parent103 = 0;
    sji_element sjt_parent105 = { 0 };
    sjs_scene2d* sjt_parent117 = 0;
    sjs_windowrenderer* sjt_parent118 = 0;
    sjs_animator* sjt_parent94 = 0;
    sjs_windowrenderer* sjt_parent96 = 0;
    sjs_scene2d* sjt_parent98 = 0;
    int32_option sjv_mouse_eventtype;
    bool sjv_mouse_isleftdown;
    int32_t sjv_mouse_x;
    int32_t sjv_mouse_y;
    sjs_rect sjv_rect = { -1 };
    bool sjv_shouldappcontinue;
    bool sjv_shouldcontinue;
    sjs_size sjv_size = { -1 };
    int32_t sjv_ticks;

#line 9 "lib/ui/loop.sj"
    sjv_shouldappcontinue = true;
#line 10
    sjv_ticks = 0;
#line 12
    sjv_ticks = SDL_GetTicks();
#line 31 "lib/ui/animation.sj"
    sjt_parent94 = &sjv_animator;
#line 14 "lib/ui/loop.sj"
    sjt_functionParam160 = sjv_ticks;
#line 14
    sjf_animator_nextframe(sjt_parent94, sjt_functionParam160);
    if (sjv_mainloop_showfps) {
#line 17 "lib/ui/loop.sj"
        sjv_mainloop_frames = sjv_mainloop_frames + 1;
        if ((sjv_mainloop_lasttick + 1000) < sjv_ticks) {
            int32_t sjt_cast11;
            int32_t sjt_cast12;
            sjs_string* sjt_functionParam161 = 0;
            sjs_string* sjt_functionParam162 = 0;
            float sjt_functionParam163;
            sjs_string* sjt_parent95 = 0;
            float sjv_fps;

#line 19 "lib/ui/loop.sj"
            sjt_cast11 = sjv_mainloop_frames;
#line 19
            sjt_cast12 = sjv_ticks - sjv_mainloop_lasttick;
#line 19
            sjv_fps = ((float)sjt_cast11 * 1000.0f) / (float)sjt_cast12;
#line 19
            sjt_call40._refCount = 1;
#line 20
            sjt_call40.count = 5;
#line 20
            sjt_call40.data._refCount = 1;
#line 20
            sjt_call40.data.datasize = 5;
#line 20
            sjt_call40.data.data = (void*)sjg_string31;
#line 20
            sjt_call40.data.isglobal = true;
#line 20
            sjt_call40.data.count = 5;
#line 20
            sjf_array_char(&sjt_call40.data);
#line 14 "lib/common/string.sj"
            sjt_call40._isnullterminated = false;
#line 14
            sjf_string(&sjt_call40);
#line 20 "lib/ui/loop.sj"
            sjt_parent95 = &sjt_call40;
#line 20
            sjt_functionParam163 = sjv_fps;
#line 20
            sjf_f32_asstring(sjt_functionParam163, &sjt_call41);
#line 20
            sjt_functionParam162 = &sjt_call41;
#line 20
            sjf_string_add(sjt_parent95, sjt_functionParam162, &sjt_call39);
#line 20
            sjt_functionParam161 = &sjt_call39;
#line 20
            sjf_debug_writeline(sjt_functionParam161);
#line 21
            sjv_mainloop_lasttick = sjv_ticks;
#line 22
            sjv_mainloop_frames = 0;
        }
    }

#line 7 "lib/ui/windowRenderer.sj"
    sjt_parent96 = &sjv_rootwindowrenderer;
#line 7
    sjf_windowrenderer_getsize(sjt_parent96, &sjv_size);
#line 27 "lib/ui/scene2d.sj"
    sjt_parent98 = &sjv_rootscene;
#line 27 "lib/ui/loop.sj"
    sjt_functionParam174 = &sjv_size;
#line 27
    sjf_scene2d_setsize(sjt_parent98, sjt_functionParam174);
#line 8 "lib/ui/scene2d.sj"
    sjt_parent102 = &sjv_rootscene;
#line 8
    sjf_scene2d_start(sjt_parent102);
#line 8
    sjv_rect._refCount = 1;
#line 29 "lib/ui/loop.sj"
    sjv_rect.x = 0;
#line 29
    sjv_rect.y = 0;
#line 29
    sjv_rect.w = (&sjv_size)->w;
#line 29
    sjv_rect.h = (&sjv_size)->h;
#line 29
    sjf_rect(&sjv_rect);
#line 15 "lib/ui/rect.sj"
    sjt_parent103 = &sjv_looplastrect;
#line 30 "lib/ui/loop.sj"
    sjt_functionParam183 = &sjv_rect;
#line 30
    sjf_rect_isequal(sjt_parent103, sjt_functionParam183, &sjt_capture20);
#line 30
    result13 = !sjt_capture20;
    if (result13) {
        sjs_rect* sjt_interfaceParam10 = 0;
        sji_element sjt_parent104 = { 0 };

#line 4 "lib/ui/element.sj"
        sjt_parent104 = sjv_root;
#line 31 "lib/ui/loop.sj"
        sjt_interfaceParam10 = &sjv_rect;
#line 31
        sjt_parent104._vtbl->setrect(sjt_parent104._parent, sjt_interfaceParam10);
    }

#line 5 "lib/ui/element.sj"
    sjt_parent105 = sjv_root;
#line 33 "lib/ui/loop.sj"
    sjt_interfaceParam11 = &sjv_rootscene;
#line 33
    sjt_parent105._vtbl->render(sjt_parent105._parent, sjt_interfaceParam11);
#line 19 "lib/ui/scene2d.sj"
    sjt_parent117 = &sjv_rootscene;
#line 19
    sjf_scene2d_end(sjt_parent117);
#line 22 "lib/ui/windowRenderer.sj"
    sjt_parent118 = &sjv_rootwindowrenderer;
#line 22
    sjf_windowrenderer_present(sjt_parent118);
#line 38 "lib/ui/loop.sj"
    SDL_Event e;
#line 39
    while(SDL_PollEvent( &e ) != 0) {
#line 41
        sjv_mouse_eventtype = int32_empty;
#line 42
        sjv_mouse_x = 0;
#line 43
        sjv_mouse_y = 0;
#line 44
        sjv_mouse_isleftdown = false;
#line 47
        switch (e.type) {
#line 48
            case SDL_QUIT:
#line 49
            sjv_shouldappcontinue = false;
#line 50
            break;
#line 51
            case SDL_MOUSEBUTTONDOWN:
#line 52
            sjv_mouse_eventtype.isvalid = true;
#line 53
            sjv_mouse_eventtype.value = sjv_mouseeventtype_down;
#line 54
            sjv_mouse_x = e.button.x;
#line 55
            sjv_mouse_y = e.button.y;
#line 56
            sjv_mouse_isleftdown = e.button.state & SDL_BUTTON(SDL_BUTTON_LEFT);
#line 57
            break;
#line 58
            case SDL_MOUSEBUTTONUP:
#line 59
            sjv_mouse_eventtype.isvalid = true;
#line 60
            sjv_mouse_eventtype.value = sjv_mouseeventtype_up;
#line 61
            sjv_mouse_x = e.button.x;
#line 62
            sjv_mouse_y = e.button.y;
#line 63
            sjv_mouse_isleftdown = e.button.state & SDL_BUTTON(SDL_BUTTON_LEFT);
#line 64
            break;
#line 65
            case SDL_MOUSEMOTION:
#line 66
            sjv_mouse_eventtype.isvalid = true;
#line 67
            sjv_mouse_eventtype.value = sjv_mouseeventtype_move;
#line 68
            sjv_mouse_x = e.motion.x;
#line 69
            sjv_mouse_y = e.motion.y;
#line 70
            sjv_mouse_isleftdown = SDL_GetGlobalMouseState(0, 0) & SDL_BUTTON(SDL_BUTTON_LEFT);
#line 71
            break;
#line 72
        }
#line 75
        sjv_shouldcontinue = true;
        if (sjv_mouse_eventtype.isvalid) {
            int32_t ifValue23;
            int32_option sjt_getValue2;

#line 76 "lib/ui/loop.sj"
            sjt_getValue2 = sjv_mouse_eventtype;
#line 76
            ifValue23 = sjt_getValue2.value;
            if ((sjv_mouse_captureelement._parent != 0)) {
                sji_element ifValue24 = { 0 };
                sjs_mouseevent sjt_call44 = { -1 };
                sjs_mouseevent* sjt_interfaceParam12 = 0;
                sji_element sjt_parent119 = { 0 };

#line 77 "lib/ui/loop.sj"
                ifValue24 = sjv_mouse_captureelement;
                if (ifValue24._parent != 0) {
                    ifValue24._parent->_refCount++;
                }

#line 6 "lib/ui/element.sj"
                sjt_parent119 = ifValue24;
#line 6
                sjt_call44._refCount = 1;
#line 78 "lib/ui/loop.sj"
                sjt_call44.eventtype = ifValue23;
#line 78
                sjt_call44.point._refCount = 1;
#line 80
                sjt_call44.point.x = sjv_mouse_x;
#line 80
                sjt_call44.point.y = sjv_mouse_y;
#line 80
                sjf_point(&sjt_call44.point);
#line 81
                sjt_call44.iscaptured = true;
#line 78
                sjt_call44.isleftdown = sjv_mouse_isleftdown;
#line 78
                sjf_mouseevent(&sjt_call44);
#line 78
                sjt_interfaceParam12 = &sjt_call44;
#line 78
                sjt_parent119._vtbl->firemouseevent(sjt_parent119._parent, sjt_interfaceParam12, &sjv_shouldcontinue);

                if (ifValue24._parent != 0) {
                    ifValue24._parent->_refCount--;
                    if (ifValue24._parent->_refCount <= 0) {
                        ifValue24._vtbl->destroy(ifValue24._parent);
                        free(ifValue24._parent);
                    }
                }
                if (sjt_call44._refCount == 1) { sjf_mouseevent_destroy(&sjt_call44); }
;
            } else {
                sjs_mouseevent sjt_call45 = { -1 };
                sjs_mouseevent* sjt_interfaceParam13 = 0;
                sji_element sjt_parent120 = { 0 };

#line 6 "lib/ui/element.sj"
                sjt_parent120 = sjv_root;
#line 6
                sjt_call45._refCount = 1;
#line 86 "lib/ui/loop.sj"
                sjt_call45.eventtype = ifValue23;
#line 86
                sjt_call45.point._refCount = 1;
#line 88
                sjt_call45.point.x = sjv_mouse_x;
#line 88
                sjt_call45.point.y = sjv_mouse_y;
#line 88
                sjf_point(&sjt_call45.point);
#line 89
                sjt_call45.iscaptured = false;
#line 86
                sjt_call45.isleftdown = sjv_mouse_isleftdown;
#line 86
                sjf_mouseevent(&sjt_call45);
#line 86
                sjt_interfaceParam13 = &sjt_call45;
#line 86
                sjt_parent120._vtbl->firemouseevent(sjt_parent120._parent, sjt_interfaceParam13, &sjv_shouldcontinue);

                if (sjt_call45._refCount == 1) { sjf_mouseevent_destroy(&sjt_call45); }
;
            }
        }

#line 96
    }
#line 99
    sjv_mainloop_shouldcontinue = sjv_shouldappcontinue;

    if (sjt_call39._refCount == 1) { sjf_string_destroy(&sjt_call39); }
;
    if (sjt_call40._refCount == 1) { sjf_string_destroy(&sjt_call40); }
;
    if (sjt_call41._refCount == 1) { sjf_string_destroy(&sjt_call41); }
;
    if (sjv_rect._refCount == 1) { sjf_rect_destroy(&sjv_rect); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_margin(sjs_margin* _this) {
}

void sjf_margin_copy(sjs_margin* _this, sjs_margin* _from) {
#line 1 "lib/ui/margin.sj"
    _this->l = _from->l;
#line 1
    _this->t = _from->t;
#line 1
    _this->r = _from->r;
#line 1
    _this->b = _from->b;
}

void sjf_margin_destroy(sjs_margin* _this) {
}

void sjf_margin_heap(sjs_margin* _this) {
}

void sjf_mat4(sjs_mat4* _this) {
}

void sjf_mat4_copy(sjs_mat4* _this, sjs_mat4* _from) {
#line 1 "lib/ui/mat4.sj"
    _this->m00 = _from->m00;
#line 1
    _this->m01 = _from->m01;
#line 1
    _this->m02 = _from->m02;
#line 1
    _this->m03 = _from->m03;
#line 1
    _this->m10 = _from->m10;
#line 1
    _this->m11 = _from->m11;
#line 1
    _this->m12 = _from->m12;
#line 1
    _this->m13 = _from->m13;
#line 1
    _this->m20 = _from->m20;
#line 1
    _this->m21 = _from->m21;
#line 1
    _this->m22 = _from->m22;
#line 1
    _this->m23 = _from->m23;
#line 1
    _this->m30 = _from->m30;
#line 1
    _this->m31 = _from->m31;
#line 1
    _this->m32 = _from->m32;
#line 1
    _this->m33 = _from->m33;
}

void sjf_mat4_destroy(sjs_mat4* _this) {
}

void sjf_mat4_heap(sjs_mat4* _this) {
}

void sjf_mat4_identity(sjs_mat4* _return) {
    _return->_refCount = 1;
#line 126 "lib/ui/mat4.sj"
    _return->m00 = 1.0f;
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 127
    _return->m11 = 1.0f;
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 128
    _return->m22 = 1.0f;
#line 13
    _return->m23 = 0.0f;
#line 14
    _return->m30 = 0.0f;
#line 15
    _return->m31 = 0.0f;
#line 16
    _return->m32 = 0.0f;
#line 129
    _return->m33 = 1.0f;
#line 129
    sjf_mat4(_return);
}

void sjf_mat4_identity_heap(sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 126 "lib/ui/mat4.sj"
    (*_return)->m00 = 1.0f;
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 127
    (*_return)->m11 = 1.0f;
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 128
    (*_return)->m22 = 1.0f;
#line 13
    (*_return)->m23 = 0.0f;
#line 14
    (*_return)->m30 = 0.0f;
#line 15
    (*_return)->m31 = 0.0f;
#line 16
    (*_return)->m32 = 0.0f;
#line 129
    (*_return)->m33 = 1.0f;
#line 129
    sjf_mat4_heap((*_return));
}

void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return) {
    float result9;

    _return->_refCount = 1;
#line 172 "lib/ui/mat4.sj"
    _return->m00 = 2.0f / (right - left);
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 174
    _return->m11 = 2.0f / (top - bottom);
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 176
    result9 = -2.0f;
#line 176
    _return->m22 = result9 / (zfar - znear);
#line 13
    _return->m23 = 0.0f;
#line 173
    _return->m30 = 0.0f - ((right + left) / (right - left));
#line 175
    _return->m31 = 0.0f - ((top + bottom) / (top - bottom));
#line 177
    _return->m32 = 0.0f - ((zfar + znear) / (zfar - znear));
#line 178
    _return->m33 = 1.0f;
#line 178
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return) {
    float result10;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 172 "lib/ui/mat4.sj"
    (*_return)->m00 = 2.0f / (right - left);
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 174
    (*_return)->m11 = 2.0f / (top - bottom);
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 176
    result10 = -2.0f;
#line 176
    (*_return)->m22 = result10 / (zfar - znear);
#line 13
    (*_return)->m23 = 0.0f;
#line 173
    (*_return)->m30 = 0.0f - ((right + left) / (right - left));
#line 175
    (*_return)->m31 = 0.0f - ((top + bottom) / (top - bottom));
#line 177
    (*_return)->m32 = 0.0f - ((zfar + znear) / (zfar - znear));
#line 178
    (*_return)->m33 = 1.0f;
#line 178
    sjf_mat4_heap((*_return));
}

void sjf_mat4_scale(float x, float y, float z, sjs_mat4* _return) {
    _return->_refCount = 1;
#line 213 "lib/ui/mat4.sj"
    _return->m00 = x;
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 213
    _return->m11 = y;
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 213
    _return->m22 = z;
#line 13
    _return->m23 = 0.0f;
#line 14
    _return->m30 = 0.0f;
#line 15
    _return->m31 = 0.0f;
#line 16
    _return->m32 = 0.0f;
#line 218
    _return->m33 = 1.0f;
#line 218
    sjf_mat4(_return);
}

void sjf_mat4_scale_heap(float x, float y, float z, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 213 "lib/ui/mat4.sj"
    (*_return)->m00 = x;
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 213
    (*_return)->m11 = y;
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 213
    (*_return)->m22 = z;
#line 13
    (*_return)->m23 = 0.0f;
#line 14
    (*_return)->m30 = 0.0f;
#line 15
    (*_return)->m31 = 0.0f;
#line 16
    (*_return)->m32 = 0.0f;
#line 218
    (*_return)->m33 = 1.0f;
#line 218
    sjf_mat4_heap((*_return));
}

void sjf_mouse_capture(sji_element element) {
    sji_element sjt_value4 = { 0 };

#line 3 "lib/ui/mouse.sj"
    sjt_value4 = element;
    if (sjt_value4._parent != 0) {
        sjt_value4._parent->_refCount++;
    }

    if (sjv_mouse_captureelement._parent != 0) {
        sjv_mouse_captureelement._parent->_refCount--;
        if (sjv_mouse_captureelement._parent->_refCount <= 0) {
            sjv_mouse_captureelement._vtbl->destroy(sjv_mouse_captureelement._parent);
            free(sjv_mouse_captureelement._parent);
        }
    }

#line 4
    sjv_mouse_captureelement = sjt_value4;
    if (sjv_mouse_captureelement._parent != 0) {
        sjv_mouse_captureelement._parent->_refCount++;
    }

#line 6
    SDL_CaptureMouse(true);

    if (sjt_value4._parent != 0) {
        sjt_value4._parent->_refCount--;
        if (sjt_value4._parent->_refCount <= 0) {
            sjt_value4._vtbl->destroy(sjt_value4._parent);
            free(sjt_value4._parent);
        }
    }
}

void sjf_mouse_hascapture(sji_element element, bool* _return) {
    if ((sjv_mouse_captureelement._parent != 0)) {
        sji_element ifValue8 = { 0 };

#line 11 "lib/ui/mouse.sj"
        ifValue8 = sjv_mouse_captureelement;
        if (ifValue8._parent != 0) {
            ifValue8._parent->_refCount++;
        }

#line 12
        (*_return) = ifValue8._parent == element._parent;

        if (ifValue8._parent != 0) {
            ifValue8._parent->_refCount--;
            if (ifValue8._parent->_refCount <= 0) {
                ifValue8._vtbl->destroy(ifValue8._parent);
                free(ifValue8._parent);
            }
        }
    } else {
#line 14 "lib/ui/mouse.sj"
        (*_return) = false;
    }
}

void sjf_mouse_release(sji_element element) {
    sjs_string sjt_call16 = { -1 };
    sjs_string* sjt_functionParam96 = 0;

    sjt_call16._refCount = 1;
#line 19 "lib/ui/mouse.sj"
    sjt_call16.count = 7;
#line 19
    sjt_call16.data._refCount = 1;
#line 19
    sjt_call16.data.datasize = 7;
#line 19
    sjt_call16.data.data = (void*)sjg_string25;
#line 19
    sjt_call16.data.isglobal = true;
#line 19
    sjt_call16.data.count = 7;
#line 19
    sjf_array_char(&sjt_call16.data);
#line 14 "lib/common/string.sj"
    sjt_call16._isnullterminated = false;
#line 14
    sjf_string(&sjt_call16);
#line 19 "lib/ui/mouse.sj"
    sjt_functionParam96 = &sjt_call16;
#line 19
    sjf_console_writeline(sjt_functionParam96);
    if ((sjv_mouse_captureelement._parent != 0)) {
        sji_element ifValue10 = { 0 };
        sjs_string sjt_call17 = { -1 };

#line 20 "lib/ui/mouse.sj"
        ifValue10 = sjv_mouse_captureelement;
        if (ifValue10._parent != 0) {
            ifValue10._parent->_refCount++;
        }

        if (ifValue10._parent == element._parent) {
            sjs_string* sjt_functionParam97 = 0;

            sjt_call17._refCount = 1;
#line 22 "lib/ui/mouse.sj"
            sjt_call17.count = 12;
#line 22
            sjt_call17.data._refCount = 1;
#line 22
            sjt_call17.data.datasize = 12;
#line 22
            sjt_call17.data.data = (void*)sjg_string26;
#line 22
            sjt_call17.data.isglobal = true;
#line 22
            sjt_call17.data.count = 12;
#line 22
            sjf_array_char(&sjt_call17.data);
#line 14 "lib/common/string.sj"
            sjt_call17._isnullterminated = false;
#line 14
            sjf_string(&sjt_call17);
#line 22 "lib/ui/mouse.sj"
            sjt_functionParam97 = &sjt_call17;
#line 22
            sjf_console_writeline(sjt_functionParam97);
            if (sjv_mouse_captureelement._parent != 0) {
                sjv_mouse_captureelement._parent->_refCount--;
                if (sjv_mouse_captureelement._parent->_refCount <= 0) {
                    sjv_mouse_captureelement._vtbl->destroy(sjv_mouse_captureelement._parent);
                    free(sjv_mouse_captureelement._parent);
                }
            }

#line 23
            sjv_mouse_captureelement._parent = 0;
#line 25
            SDL_CaptureMouse(false);
        }

        if (ifValue10._parent != 0) {
            ifValue10._parent->_refCount--;
            if (ifValue10._parent->_refCount <= 0) {
                ifValue10._vtbl->destroy(ifValue10._parent);
                free(ifValue10._parent);
            }
        }
        if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
;
    }

    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
;
}

void sjf_mouseevent(sjs_mouseevent* _this) {
}

void sjf_mouseevent_copy(sjs_mouseevent* _this, sjs_mouseevent* _from) {
#line 38 "lib/ui/mouse.sj"
    _this->eventtype = _from->eventtype;
#line 38
    _this->point._refCount = 1;
#line 38
    sjf_point_copy(&_this->point, &_from->point);
#line 38
    _this->iscaptured = _from->iscaptured;
#line 38
    _this->isleftdown = _from->isleftdown;
}

void sjf_mouseevent_destroy(sjs_mouseevent* _this) {
    if (_this->point._refCount == 1) { sjf_point_destroy(&_this->point); }
;
}

void sjf_mouseevent_firechildren(sjs_mouseevent* _parent, sjs_array_heap_iface_element* children, bool* _return) {
    int32_t i;
    int32_t sjt_forEnd7;
    int32_t sjt_forStart7;
    bool sjv_shouldcontinue;

#line 45 "lib/ui/mouse.sj"
    sjv_shouldcontinue = true;
#line 46
    sjt_forStart7 = 0;
#line 46
    sjt_forEnd7 = children->count;
#line 46
    i = sjt_forEnd7 - 1;
    while (i >= sjt_forStart7) {
        if (sjv_shouldcontinue) {
            int32_t sjt_functionParam37;
            sjs_mouseevent* sjt_interfaceParam3 = 0;
            sjs_array_heap_iface_element* sjt_parent25 = 0;
            sji_element sjt_parent26 = { 0 };
            sji_element sjv_child = { 0 };

#line 44 "lib/ui/mouse.sj"
            sjt_parent25 = children;
#line 46
            sjt_functionParam37 = i;
#line 46
            sjf_array_heap_iface_element_getat_heap(sjt_parent25, sjt_functionParam37, &sjv_child);
#line 6 "lib/ui/element.sj"
            sjt_parent26 = sjv_child;
#line 49 "lib/ui/mouse.sj"
            sjt_interfaceParam3 = _parent;
#line 49
            sjt_parent26._vtbl->firemouseevent(sjt_parent26._parent, sjt_interfaceParam3, &sjv_shouldcontinue);

            if (sjv_child._parent != 0) {
                sjv_child._parent->_refCount--;
                if (sjv_child._parent->_refCount <= 0) {
                    sjv_child._vtbl->destroy(sjv_child._parent);
                    free(sjv_child._parent);
                }
            }
        }

#line 46 "lib/ui/mouse.sj"
        i--;
    }

#line 44
    (*_return) = sjv_shouldcontinue;
}

void sjf_mouseevent_heap(sjs_mouseevent* _this) {
}

void sjf_point(sjs_point* _this) {
}

void sjf_point_copy(sjs_point* _this, sjs_point* _from) {
#line 1 "lib/ui/point.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
}

void sjf_point_destroy(sjs_point* _this) {
}

void sjf_point_heap(sjs_point* _this) {
}

void sjf_rect(sjs_rect* _this) {
}

void sjf_rect_containspoint(sjs_rect* _parent, sjs_point* point, bool* _return) {
#line 12 "lib/ui/rect.sj"
    (*_return) = (_parent->x <= point->x) && ((_parent->y <= point->y) && ((point->x < (_parent->x + _parent->w)) && (point->y < (_parent->y + _parent->h))));
}

void sjf_rect_copy(sjs_rect* _this, sjs_rect* _from) {
#line 1 "lib/ui/rect.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
#line 1
    _this->w = _from->w;
#line 1
    _this->h = _from->h;
}

void sjf_rect_destroy(sjs_rect* _this) {
}

void sjf_rect_heap(sjs_rect* _this) {
}

void sjf_rect_isequal(sjs_rect* _parent, sjs_rect* rect, bool* _return) {
#line 16 "lib/ui/rect.sj"
    (*_return) = (_parent->x == rect->x) && ((_parent->y == rect->y) && ((_parent->w == rect->w) && (_parent->h == rect->h)));
}

void sjf_rect_subtractmargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    _return->_refCount = 1;
#line 8 "lib/ui/rect.sj"
    _return->x = _parent->x + margin->l;
#line 8
    _return->y = _parent->y + margin->t;
#line 8
    _return->w = (_parent->w - margin->l) - margin->r;
#line 8
    _return->h = (_parent->h - margin->t) - margin->b;
#line 8
    sjf_rect(_return);
}

void sjf_rect_subtractmargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 8 "lib/ui/rect.sj"
    (*_return)->x = _parent->x + margin->l;
#line 8
    (*_return)->y = _parent->y + margin->t;
#line 8
    (*_return)->w = (_parent->w - margin->l) - margin->r;
#line 8
    (*_return)->h = (_parent->h - margin->t) - margin->b;
#line 8
    sjf_rect_heap((*_return));
}

void sjf_runloop(void) {
#line 105 "lib/ui/loop.sj"
    #ifdef EMSCRIPTEN
#line 106
    emscripten_set_main_loop((em_callback_func)sjf_mainloop, 0, 0);
#line 107
    exit(0);
#line 108
    #else
#line 109
    while (sjv_mainloop_shouldcontinue) {
#line 110
        sjf_mainloop();
#line 111
    }
#line 112
    #endif 
}

void sjf_scene2d(sjs_scene2d* _this) {
}

void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from) {
    _this->_size._refCount = 1;
#line 1 "lib/ui/scene2d.sj"
    sjf_size_copy(&_this->_size, &_from->_size);
#line 1
    _this->model._refCount = 1;
#line 1
    sjf_mat4_copy(&_this->model, &_from->model);
#line 1
    _this->view._refCount = 1;
#line 1
    sjf_mat4_copy(&_this->view, &_from->view);
#line 1
    _this->projection._refCount = 1;
#line 1
    sjf_mat4_copy(&_this->projection, &_from->projection);
#line 1
    _this->windowrect._refCount = 1;
#line 1
    sjf_rect_copy(&_this->windowrect, &_from->windowrect);
}

void sjf_scene2d_destroy(sjs_scene2d* _this) {
    if (_this->_size._refCount == 1) { sjf_size_destroy(&_this->_size); }
;
    if (_this->model._refCount == 1) { sjf_mat4_destroy(&_this->model); }
;
    if (_this->view._refCount == 1) { sjf_mat4_destroy(&_this->view); }
;
    if (_this->projection._refCount == 1) { sjf_mat4_destroy(&_this->projection); }
;
    if (_this->windowrect._refCount == 1) { sjf_rect_destroy(&_this->windowrect); }
;
}

void sjf_scene2d_end(sjs_scene2d* _parent) {
    sjs_rect* sjt_functionParam191 = 0;
    sjs_rect* sjt_functionParam192 = 0;

#line 20 "lib/ui/scene2d.sj"
    sjt_functionParam191 = &_parent->windowrect;
#line 20
    sjt_functionParam192 = &_parent->windowrect;
#line 20
    sjf_glpopviewport(sjt_functionParam191, sjt_functionParam192);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result8;
    bool sjt_capture19;
    sjs_mat4 sjt_funcold5 = { -1 };
    sjs_mat4 sjt_funcold6 = { -1 };
    sjs_mat4 sjt_funcold7 = { -1 };
    sjs_size* sjt_functionParam164 = 0;
    sjs_size* sjt_parent97 = 0;

#line 27 "lib/ui/size.sj"
    sjt_parent97 = &_parent->_size;
#line 27 "lib/ui/scene2d.sj"
    sjt_functionParam164 = size;
#line 27
    sjf_size_isequal(sjt_parent97, sjt_functionParam164, &sjt_capture19);
#line 28
    result8 = !sjt_capture19;
    if (result8) {
        float result11;
        float result12;
        int32_t sjt_cast13;
        int32_t sjt_cast14;
        float sjt_functionParam165;
        float sjt_functionParam166;
        float sjt_functionParam167;
        float sjt_functionParam168;
        float sjt_functionParam169;
        float sjt_functionParam170;
        float sjt_functionParam171;
        float sjt_functionParam172;
        float sjt_functionParam173;

        if (_parent->_size._refCount == 1) { sjf_size_destroy(&_parent->_size); }
;
#line 27 "lib/ui/scene2d.sj"
        sjf_size_copy(&_parent->_size, size);
#line 27
        sjt_funcold5._refCount = 1;
#line 170 "lib/ui/mat4.sj"
        sjf_mat4_copy(&sjt_funcold5, &_parent->projection);
#line 30 "lib/ui/scene2d.sj"
        sjt_functionParam165 = 0.0f;
#line 30
        sjt_cast13 = (&_parent->_size)->w;
#line 30
        sjt_functionParam166 = (float)sjt_cast13;
#line 30
        sjt_cast14 = 0 - (&_parent->_size)->h;
#line 30
        sjt_functionParam167 = (float)sjt_cast14;
#line 30
        sjt_functionParam168 = 0.0f;
#line 30
        result11 = -1.0f;
#line 30
        sjt_functionParam169 = result11;
#line 30
        sjt_functionParam170 = 1.0f;
#line 30
        sjf_mat4_orthographic(sjt_functionParam165, sjt_functionParam166, sjt_functionParam167, sjt_functionParam168, sjt_functionParam169, sjt_functionParam170, &sjt_funcold5);
#line 30
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
#line 170 "lib/ui/mat4.sj"
        sjf_mat4_copy(&_parent->projection, &sjt_funcold5);
#line 170
        sjt_funcold6._refCount = 1;
#line 213
        sjf_mat4_copy(&sjt_funcold6, &_parent->model);
#line 31 "lib/ui/scene2d.sj"
        sjt_functionParam171 = 1.0f;
#line 31
        result12 = -1.0f;
#line 31
        sjt_functionParam172 = result12;
#line 31
        sjt_functionParam173 = 1.0f;
#line 31
        sjf_mat4_scale(sjt_functionParam171, sjt_functionParam172, sjt_functionParam173, &sjt_funcold6);
#line 31
        if (_parent->model._refCount == 1) { sjf_mat4_destroy(&_parent->model); }
;
#line 213 "lib/ui/mat4.sj"
        sjf_mat4_copy(&_parent->model, &sjt_funcold6);
#line 213
        sjt_funcold7._refCount = 1;
#line 124
        sjf_mat4_copy(&sjt_funcold7, &_parent->view);
#line 124
        sjf_mat4_identity(&sjt_funcold7);
#line 124
        if (_parent->view._refCount == 1) { sjf_mat4_destroy(&_parent->view); }
;
#line 124
        sjf_mat4_copy(&_parent->view, &sjt_funcold7);
    }

    if (sjt_funcold5._refCount == 1) { sjf_mat4_destroy(&sjt_funcold5); }
;
    if (sjt_funcold6._refCount == 1) { sjf_mat4_destroy(&sjt_funcold6); }
;
    if (sjt_funcold7._refCount == 1) { sjf_mat4_destroy(&sjt_funcold7); }
;
}

void sjf_scene2d_start(sjs_scene2d* _parent) {
    sjs_rect sjt_funcold8 = { -1 };
    sjs_rect* sjt_functionParam181 = 0;
    sjs_rect* sjt_functionParam182 = 0;

    sjt_funcold8._refCount = 1;
#line 1 "lib/ui/rect.sj"
    sjf_rect_copy(&sjt_funcold8, &_parent->windowrect);
#line 1
    sjt_funcold8._refCount = 1;
#line 9 "lib/ui/scene2d.sj"
    sjt_funcold8.x = 0;
#line 9
    sjt_funcold8.y = 0;
#line 9
    sjt_funcold8.w = (&_parent->_size)->w;
#line 9
    sjt_funcold8.h = (&_parent->_size)->h;
#line 9
    sjf_rect(&sjt_funcold8);
#line 9
    if (_parent->windowrect._refCount == 1) { sjf_rect_destroy(&_parent->windowrect); }
;
#line 1 "lib/ui/rect.sj"
    sjf_rect_copy(&_parent->windowrect, &sjt_funcold8);
#line 10 "lib/ui/scene2d.sj"
    sjt_functionParam181 = &_parent->windowrect;
#line 10
    sjt_functionParam182 = &_parent->windowrect;
#line 10
    sjf_glpushviewport(sjt_functionParam181, sjt_functionParam182);
#line 12
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
#line 13
    glEnable( GL_TEXTURE_2D );
#line 14
    glDisable( GL_DEPTH_TEST );

    if (sjt_funcold8._refCount == 1) { sjf_rect_destroy(&sjt_funcold8); }
;
}

void sjf_shader(sjs_shader* _this) {
#line 15 "lib/ui/shader.sj"
    _this->id = shader_load((char*)_this->vertex.data.data, (char*)_this->pixel.data.data);
}

void sjf_shader_copy(sjs_shader* _this, sjs_shader* _from) {
    _this->vertex._refCount = 1;
#line 7 "lib/ui/shader.sj"
    sjf_string_copy(&_this->vertex, &_from->vertex);
#line 7
    _this->pixel._refCount = 1;
#line 7
    sjf_string_copy(&_this->pixel, &_from->pixel);
#line 20
    _this->id = _from->id;
#line 21
    glid_retain(_this->id);
}

void sjf_shader_destroy(sjs_shader* _this) {
#line 25 "lib/ui/shader.sj"
    if (glid_release(_this->id)) {
#line 26
        glDeleteShader(_this->id);
#line 27
    }
#line 27
    if (_this->vertex._refCount == 1) { sjf_string_destroy(&_this->vertex); }
;
#line 27
    if (_this->pixel._refCount == 1) { sjf_string_destroy(&_this->pixel); }
;
}

void sjf_shader_heap(sjs_shader* _this) {
#line 15 "lib/ui/shader.sj"
    _this->id = shader_load((char*)_this->vertex.data.data, (char*)_this->pixel.data.data);
}

void sjf_size(sjs_size* _this) {
}

void sjf_size_addmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    _return->_refCount = 1;
#line 20 "lib/ui/size.sj"
    _return->w = (_parent->w + margin->l) + margin->r;
#line 20
    _return->h = (_parent->h + margin->t) + margin->b;
#line 20
    sjf_size(_return);
}

void sjf_size_addmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 20 "lib/ui/size.sj"
    (*_return)->w = (_parent->w + margin->l) + margin->r;
#line 20
    (*_return)->h = (_parent->h + margin->t) + margin->b;
#line 20
    sjf_size_heap((*_return));
}

void sjf_size_copy(sjs_size* _this, sjs_size* _from) {
#line 1 "lib/ui/size.sj"
    _this->w = _from->w;
#line 1
    _this->h = _from->h;
}

void sjf_size_destroy(sjs_size* _this) {
}

void sjf_size_heap(sjs_size* _this) {
}

void sjf_size_isequal(sjs_size* _parent, sjs_size* size, bool* _return) {
#line 28 "lib/ui/size.sj"
    (*_return) = (_parent->w == size->w) && (_parent->h == size->h);
}

void sjf_size_min(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    if (_parent->w < maxsize->w) {
#line 6 "lib/ui/size.sj"
        _return->w = _parent->w;
    } else {
#line 6 "lib/ui/size.sj"
        _return->w = maxsize->w;
    }

    if (_parent->h < maxsize->h) {
#line 6 "lib/ui/size.sj"
        _return->h = _parent->h;
    } else {
#line 6 "lib/ui/size.sj"
        _return->h = maxsize->h;
    }

    sjf_size(_return);
}

void sjf_size_min_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    if (_parent->w < maxsize->w) {
#line 6 "lib/ui/size.sj"
        (*_return)->w = _parent->w;
    } else {
#line 6 "lib/ui/size.sj"
        (*_return)->w = maxsize->w;
    }

    if (_parent->h < maxsize->h) {
#line 6 "lib/ui/size.sj"
        (*_return)->h = _parent->h;
    } else {
#line 6 "lib/ui/size.sj"
        (*_return)->h = maxsize->h;
    }

    sjf_size_heap((*_return));
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
#line 18 "lib/common/string.sj"
        _return->count = _parent->count;
#line 18
        _return->data._refCount = 1;
#line 18
        sjf_array_char_copy(&_return->data, &_parent->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_forEnd8;
        int32_t sjt_forStart8;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam116;
            sjs_array_char* sjt_parent59 = 0;

#line 134 "lib/common/array.sj"
            sjt_parent59 = &_parent->data;
#line 21 "lib/common/string.sj"
            sjt_functionParam116 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent59, sjt_functionParam116, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
#line 20 "lib/common/string.sj"
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

#line 25 "lib/common/string.sj"
        sjv_newcount = _parent->count;
#line 27
        sjt_forStart8 = 0;
#line 27
        sjt_forEnd8 = item->count;
#line 27
        i = sjt_forStart8;
        while (i < sjt_forEnd8) {
            int32_t sjt_functionParam117;
            char sjt_functionParam118;
            int32_t sjt_functionParam120;
            sjs_array_char* sjt_parent60 = 0;
            sjs_string* sjt_parent62 = 0;

#line 34 "lib/common/array.sj"
            sjt_parent60 = &sjv_newdata;
#line 28 "lib/common/string.sj"
            sjt_functionParam117 = sjv_newcount;
#line 16
            sjt_parent62 = item;
#line 27
            sjt_functionParam120 = i;
#line 27
            sjf_string_getat(sjt_parent62, sjt_functionParam120, &sjt_functionParam118);
#line 27
            sjf_array_char_initat(sjt_parent60, sjt_functionParam117, sjt_functionParam118);
#line 29
            sjv_newcount = sjv_newcount + 1;
#line 27
            i++;
        }

#line 27
        _return->_refCount = 1;
#line 32
        _return->count = sjv_newcount;
#line 32
        _return->data._refCount = 1;
#line 32
        sjf_array_char_copy(&_return->data, &sjv_newdata);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 18 "lib/common/string.sj"
        (*_return)->count = _parent->count;
#line 18
        (*_return)->data._refCount = 1;
#line 18
        sjf_array_char_copy(&(*_return)->data, &_parent->data);
#line 14
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_forEnd9;
        int32_t sjt_forStart9;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam121;
            sjs_array_char* sjt_parent63 = 0;

#line 134 "lib/common/array.sj"
            sjt_parent63 = &_parent->data;
#line 21 "lib/common/string.sj"
            sjt_functionParam121 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent63, sjt_functionParam121, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
#line 20 "lib/common/string.sj"
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

#line 25 "lib/common/string.sj"
        sjv_newcount = _parent->count;
#line 27
        sjt_forStart9 = 0;
#line 27
        sjt_forEnd9 = item->count;
#line 27
        i = sjt_forStart9;
        while (i < sjt_forEnd9) {
            int32_t sjt_functionParam122;
            char sjt_functionParam123;
            int32_t sjt_functionParam124;
            sjs_array_char* sjt_parent64 = 0;
            sjs_string* sjt_parent65 = 0;

#line 34 "lib/common/array.sj"
            sjt_parent64 = &sjv_newdata;
#line 28 "lib/common/string.sj"
            sjt_functionParam122 = sjv_newcount;
#line 16
            sjt_parent65 = item;
#line 27
            sjt_functionParam124 = i;
#line 27
            sjf_string_getat(sjt_parent65, sjt_functionParam124, &sjt_functionParam123);
#line 27
            sjf_array_char_initat(sjt_parent64, sjt_functionParam122, sjt_functionParam123);
#line 29
            sjv_newcount = sjv_newcount + 1;
#line 27
            i++;
        }

#line 27
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 27
        (*_return)->_refCount = 1;
#line 32
        (*_return)->count = sjv_newcount;
#line 32
        (*_return)->data._refCount = 1;
#line 32
        sjf_array_char_copy(&(*_return)->data, &sjv_newdata);
#line 14
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 6 "lib/common/string.sj"
    _this->count = _from->count;
#line 6
    _this->data._refCount = 1;
#line 6
    sjf_array_char_copy(&_this->data, &_from->data);
#line 6
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam119;
    sjs_array_char* sjt_parent61 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent61 = &_parent->data;
#line 36 "lib/common/string.sj"
    sjt_functionParam119 = index;
#line 36
    sjf_array_char_getat(sjt_parent61, sjt_functionParam119, _return);
}

void sjf_string_hash(sjs_string* _parent, uint32_t* _return) {
#line 85 "lib/common/string.sj"
    #line 84 "lib/common/string.sj"
(*_return) = kh_str_hash_func((char*)_parent->data.data);
return;;
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_array_char* sjt_functionParam9 = 0;
    sjs_array_char* sjt_parent1 = 0;

#line 269 "lib/common/array.sj"
    sjt_parent1 = &_parent->data;
#line 45 "lib/common/string.sj"
    sjt_functionParam9 = &test->data;
#line 45
    sjf_array_char_isequal(sjt_parent1, sjt_functionParam9, _return);
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result3;
    bool result4;
    sjs_array_char sjt_funcold4 = { -1 };

#line 73 "lib/common/string.sj"
    result3 = !(&_parent->data)->isglobal;
#line 73
    result4 = !_parent->_isnullterminated;
    if (result3 || result4) {
        int32_t sjt_functionParam94;
        char sjt_functionParam95;
        sjs_array_char* sjt_parent45 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam93;
            sjs_array_char* sjt_parent44 = 0;

            sjt_funcold4._refCount = 1;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&sjt_funcold4, &_parent->data);
#line 134
            sjt_parent44 = &_parent->data;
#line 75 "lib/common/string.sj"
            sjt_functionParam93 = _parent->count + 1;
#line 75
            sjf_array_char_grow(sjt_parent44, sjt_functionParam93, &sjt_funcold4);
#line 75
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold4);
        }

#line 34 "lib/common/array.sj"
        sjt_parent45 = &_parent->data;
#line 77 "lib/common/string.sj"
        sjt_functionParam94 = _parent->count;
#line 77
        sjt_functionParam95 = '\0';
#line 77
        sjf_array_char_initat(sjt_parent45, sjt_functionParam94, sjt_functionParam95);
#line 78
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold4._refCount == 1) { sjf_array_char_destroy(&sjt_funcold4); }
;
}

void sjf_style(sjs_style* _this) {
}

void sjf_style_copy(sjs_style* _this, sjs_style* _from) {
}

void sjf_style_destroy(sjs_style* _this) {
}

void sjf_style_getfont_heap(sjs_style* _parent, sjs_font** _return) {
    sjs_string sjt_call18 = { -1 };
    sjs_string* sjt_functionParam108 = 0;
    float sjt_functionParam109;

    sjt_call18._refCount = 1;
#line 3 "lib/ui/style.sj"
    sjt_call18.count = 16;
#line 3
    sjt_call18.data._refCount = 1;
#line 3
    sjt_call18.data.datasize = 16;
#line 3
    sjt_call18.data.data = (void*)sjg_string17;
#line 3
    sjt_call18.data.isglobal = true;
#line 3
    sjt_call18.data.count = 16;
#line 3
    sjf_array_char(&sjt_call18.data);
#line 14 "lib/common/string.sj"
    sjt_call18._isnullterminated = false;
#line 14
    sjf_string(&sjt_call18);
#line 3 "lib/ui/style.sj"
    sjt_functionParam108 = &sjt_call18;
#line 3
    sjt_functionParam109 = 24.0f;
#line 3
    sjf_font_load_heap(sjt_functionParam108, sjt_functionParam109, _return);

    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
;
}

void sjf_style_heap(sjs_style* _this) {
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
#line 18 "lib/ui/textElement.sj"
    sjs_string* copyoption27 = (_from->id._refCount != -1 ? &_from->id : 0);
    if (copyoption27 != 0) {
        _this->id._refCount = 1;
#line 18 "lib/ui/textElement.sj"
        sjf_string_copy(&_this->id, copyoption27);
    } else {
        _this->id._refCount = -1;
    }

#line 18
    _this->font = _from->font;
#line 18
    _this->font->_refCount++;
#line 18
    _this->text._refCount = 1;
#line 18
    sjf_string_copy(&_this->text, &_from->text);
#line 18
    _this->color._refCount = 1;
#line 18
    sjf_color_copy(&_this->color, &_from->color);
#line 18
    _this->margin._refCount = 1;
#line 18
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 18
    _this->halign = _from->halign;
#line 18
    _this->valign = _from->valign;
#line 18
    sjs_size* copyoption28 = (_from->idealsize._refCount != -1 ? &_from->idealsize : 0);
    if (copyoption28 != 0) {
        _this->idealsize._refCount = 1;
#line 18 "lib/ui/textElement.sj"
        sjf_size_copy(&_this->idealsize, copyoption28);
    } else {
        _this->idealsize._refCount = -1;
    }

#line 18
    _this->_rect._refCount = 1;
#line 18
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 18
    sjs_textrenderer* copyoption29 = (_from->_textrenderer._refCount != -1 ? &_from->_textrenderer : 0);
    if (copyoption29 != 0) {
        _this->_textrenderer._refCount = 1;
#line 18 "lib/ui/textElement.sj"
        sjf_textrenderer_copy(&_this->_textrenderer, copyoption29);
    } else {
        _this->_textrenderer._refCount = -1;
    }
}

void sjf_textelement_destroy(sjs_textelement* _this) {
    _this->font->_refCount--;
    if (_this->font->_refCount <= 0) {
        weakptr_release(_this->font);
        sjf_font_destroy(_this->font);
        free(_this->font);
    }

    if (_this->id._refCount == 1) { sjf_string_destroy(&_this->id); }
;
    if (_this->text._refCount == 1) { sjf_string_destroy(&_this->text); }
;
    if (_this->color._refCount == 1) { sjf_color_destroy(&_this->color); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->idealsize._refCount == 1) { sjf_size_destroy(&_this->idealsize); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
    if (_this->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_this->_textrenderer); }
;
}

void sjf_textelement_firemouseevent(sjs_textelement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
#line 87 "lib/ui/textElement.sj"
    (*_return) = true;
}

void sjf_textelement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 163;
}

void sjf_textelement_getrect(sjs_textelement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 40 "lib/ui/textElement.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_textelement_getrect_heap(sjs_textelement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 40 "lib/ui/textElement.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_textelement_getsize(sjs_textelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    if (((_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0) != 0)) {
        sjs_size* ifValue19 = 0;
        sjs_size* sjt_functionParam132 = 0;
        sjs_size* sjt_parent69 = 0;

#line 32 "lib/ui/textElement.sj"
        ifValue19 = (_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0);
#line 5 "lib/ui/size.sj"
        sjt_parent69 = ifValue19;
#line 31 "lib/ui/textElement.sj"
        sjt_functionParam132 = maxsize;
#line 31
        sjf_size_min(sjt_parent69, sjt_functionParam132, _return);
    } else {
        sjs_size sjt_call31 = { -1 };
        sjs_string* sjt_functionParam133 = 0;
        sjs_margin* sjt_functionParam134 = 0;
        sjs_size* sjt_functionParam135 = 0;
        sjs_size* sjt_parent70 = 0;
        sjs_font* sjt_parent71 = 0;
        sjs_size* sjt_parent72 = 0;
        sjs_size sjv_textsize = { -1 };

#line 53 "lib/ui/font.sj"
        sjt_parent71 = _parent->font;
#line 35 "lib/ui/textElement.sj"
        sjt_functionParam133 = &_parent->text;
#line 35
        sjf_font_gettextsize(sjt_parent71, sjt_functionParam133, &sjt_call31);
#line 35
        sjt_parent70 = &sjt_call31;
#line 35
        sjt_functionParam134 = &_parent->margin;
#line 35
        sjf_size_addmargin(sjt_parent70, sjt_functionParam134, &sjv_textsize);
#line 5 "lib/ui/size.sj"
        sjt_parent72 = &sjv_textsize;
#line 31 "lib/ui/textElement.sj"
        sjt_functionParam135 = maxsize;
#line 31
        sjf_size_min(sjt_parent72, sjt_functionParam135, _return);

        if (sjt_call31._refCount == 1) { sjf_size_destroy(&sjt_call31); }
;
        if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
    }
}

void sjf_textelement_getsize_heap(sjs_textelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    if (((_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0) != 0)) {
        sjs_size* ifValue20 = 0;
        sjs_size* sjt_functionParam136 = 0;
        sjs_size* sjt_parent73 = 0;

#line 32 "lib/ui/textElement.sj"
        ifValue20 = (_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0);
#line 5 "lib/ui/size.sj"
        sjt_parent73 = ifValue20;
#line 31 "lib/ui/textElement.sj"
        sjt_functionParam136 = maxsize;
#line 31
        sjf_size_min_heap(sjt_parent73, sjt_functionParam136, _return);
    } else {
        sjs_size sjt_call32 = { -1 };
        sjs_string* sjt_functionParam137 = 0;
        sjs_margin* sjt_functionParam138 = 0;
        sjs_size* sjt_functionParam139 = 0;
        sjs_size* sjt_parent74 = 0;
        sjs_font* sjt_parent75 = 0;
        sjs_size* sjt_parent76 = 0;
        sjs_size sjv_textsize = { -1 };

#line 53 "lib/ui/font.sj"
        sjt_parent75 = _parent->font;
#line 35 "lib/ui/textElement.sj"
        sjt_functionParam137 = &_parent->text;
#line 35
        sjf_font_gettextsize(sjt_parent75, sjt_functionParam137, &sjt_call32);
#line 35
        sjt_parent74 = &sjt_call32;
#line 35
        sjt_functionParam138 = &_parent->margin;
#line 35
        sjf_size_addmargin(sjt_parent74, sjt_functionParam138, &sjv_textsize);
#line 5 "lib/ui/size.sj"
        sjt_parent76 = &sjv_textsize;
#line 31 "lib/ui/textElement.sj"
        sjt_functionParam139 = maxsize;
#line 31
        sjf_size_min_heap(sjt_parent76, sjt_functionParam139, _return);

        if (sjt_call32._refCount == 1) { sjf_size_destroy(&sjt_call32); }
;
        if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
    }
}

void sjf_textelement_gettext(sjs_textelement* _parent, sjs_string* _return) {
    _return->_refCount = 1;
#line 49 "lib/ui/textElement.sj"
    sjf_string_copy(_return, &_parent->text);
}

void sjf_textelement_gettext_heap(sjs_textelement* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 49 "lib/ui/textElement.sj"
    sjf_string_copy((*_return), &_parent->text);
}

void sjf_textelement_heap(sjs_textelement* _this) {
    if (((_this->id._refCount != -1 ? &_this->id : 0) != 0)) {
        sjs_string* ifValue22 = 0;
        sjs_textelement* sjt_cast10 = 0;
        sjs_string* sjt_functionParam130 = 0;
        sji_element sjt_functionParam131 = { 0 };
        sjs_hash_string_weak_iface_element* sjt_parent68 = 0;

#line 90 "lib/ui/textElement.sj"
        ifValue22 = (_this->id._refCount != -1 ? &_this->id : 0);
#line 38 "lib/common/hash.sj"
        sjt_parent68 = &sjv_elementsbyid;
#line 91 "lib/ui/textElement.sj"
        sjt_functionParam130 = ifValue22;
#line 18
        sjt_cast10 = _this;
#line 1 "lib/ui/element.sj"
        sjf_textelement_as_sji_element(sjt_cast10, &sjt_functionParam131);
#line 1
        delete_cb weakptrcb28 = { &sjt_functionParam131._parent, weakptr_clear };
#line 1
        if (sjt_functionParam131._parent != 0) { weakptr_cb_add(sjt_functionParam131._parent, weakptrcb28); }
#line 1
        sjf_hash_string_weak_iface_element_setat(sjt_parent68, sjt_functionParam130, sjt_functionParam131);

        delete_cb weakptrcb33 = { &sjt_functionParam131._parent, weakptr_clear };
        if (sjt_functionParam131._parent != 0) { weakptr_cb_remove(sjt_functionParam131._parent, weakptrcb33); }
    }
}

void sjf_textelement_render(sjs_textelement* _parent, sjs_scene2d* scene) {
    sjs_textrenderer sjt_value8 = { -1 };
    sjs_rect sjv_innerrect = { -1 };
    sjs_size sjv_textsize = { -1 };

    if ((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) == 0) {
        sjs_string* sjt_functionParam141 = 0;
        sjs_margin* sjt_functionParam142 = 0;
        sjs_font* sjt_parent78 = 0;
        sjs_rect* sjt_parent79 = 0;
        int32_t sjv_x;
        int32_t sjv_y;
        int32_t underscore5;
        int32_t underscore6;

#line 53 "lib/ui/font.sj"
        sjt_parent78 = _parent->font;
#line 58 "lib/ui/textElement.sj"
        sjt_functionParam141 = &_parent->text;
#line 58
        sjf_font_gettextsize(sjt_parent78, sjt_functionParam141, &sjv_textsize);
#line 7 "lib/ui/rect.sj"
        sjt_parent79 = &_parent->_rect;
#line 59 "lib/ui/textElement.sj"
        sjt_functionParam142 = &_parent->margin;
#line 59
        sjf_rect_subtractmargin(sjt_parent79, sjt_functionParam142, &sjv_innerrect);
#line 60
        underscore5 = _parent->halign;
        if (underscore5 == sjv_texthorizontal_left) {
#line 60 "lib/ui/textElement.sj"
            sjv_x = (&sjv_innerrect)->x;
        } else {
            if (underscore5 == sjv_texthorizontal_right) {
#line 62 "lib/ui/textElement.sj"
                sjv_x = ((&sjv_innerrect)->x + (&sjv_innerrect)->w) - (&sjv_textsize)->w;
            } else {
                if (underscore5 == sjv_texthorizontal_center) {
#line 63 "lib/ui/textElement.sj"
                    sjv_x = (&sjv_innerrect)->x + (((&sjv_innerrect)->w - (&sjv_textsize)->w) / 2);
                } else {
#line 64 "lib/ui/textElement.sj"
                    sjv_x = 0;
                }
            }
        }

#line 67
        underscore6 = _parent->valign;
        if (underscore6 == sjv_textvertical_top) {
#line 67 "lib/ui/textElement.sj"
            sjv_y = (&sjv_innerrect)->y;
        } else {
            if (underscore6 == sjv_textvertical_bottom) {
#line 69 "lib/ui/textElement.sj"
                sjv_y = ((&sjv_innerrect)->y + (&sjv_innerrect)->h) - (&sjv_textsize)->h;
            } else {
                if (underscore6 == sjv_textvertical_center) {
#line 70 "lib/ui/textElement.sj"
                    sjv_y = (&sjv_innerrect)->y + (((&sjv_innerrect)->h - (&sjv_textsize)->h) / 2);
                } else {
#line 71 "lib/ui/textElement.sj"
                    sjv_y = 0;
                }
            }
        }

#line 67
        sjt_value8._refCount = 1;
#line 67
        sjt_value8.text._refCount = 1;
#line 74
        sjf_string_copy(&sjt_value8.text, &_parent->text);
#line 74
        sjt_value8.point._refCount = 1;
#line 76
        sjt_value8.point.x = sjv_x;
#line 76
        sjt_value8.point.y = sjv_y;
#line 76
        sjf_point(&sjt_value8.point);
#line 76
        sjt_value8.color._refCount = 1;
#line 74
        sjf_color_copy(&sjt_value8.color, &_parent->color);
#line 74
        sjt_value8.font = _parent->font;
#line 74
        sjt_value8.font->_refCount++;
#line 74
        sjf_textrenderer(&sjt_value8);
#line 74
        if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
#line 74
        sjs_textrenderer* copyoption30 = &sjt_value8;
        if (copyoption30 != 0) {
            _parent->_textrenderer._refCount = 1;
#line 74 "lib/ui/textElement.sj"
            sjf_textrenderer_copy(&_parent->_textrenderer, copyoption30);
        } else {
            _parent->_textrenderer._refCount = -1;
        }
    }

    if ((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam143 = 0;
        sjs_textrenderer* sjt_parent80 = 0;

#line 10 "lib/ui/textRenderer.sj"
        sjt_parent80 = (_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0);
#line 56 "lib/ui/textElement.sj"
        sjt_functionParam143 = scene;
#line 56
        sjf_textrenderer_render(sjt_parent80, sjt_functionParam143);
    }

    if (sjt_value8._refCount == 1) { sjf_textrenderer_destroy(&sjt_value8); }
;
    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
;
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
}

void sjf_textelement_setrect(sjs_textelement* _parent, sjs_rect* rect_) {
    bool result7;
    bool sjt_capture16;
    sjs_rect* sjt_functionParam140 = 0;
    sjs_rect* sjt_parent77 = 0;

#line 15 "lib/ui/rect.sj"
    sjt_parent77 = &_parent->_rect;
#line 41 "lib/ui/textElement.sj"
    sjt_functionParam140 = rect_;
#line 41
    sjf_rect_isequal(sjt_parent77, sjt_functionParam140, &sjt_capture16);
#line 42
    result7 = !sjt_capture16;
    if (result7) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 41 "lib/ui/textElement.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
#line 41
        if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
#line 44
        _parent->_textrenderer._refCount = -1;
    }
}

void sjf_textelement_settext(sjs_textelement* _parent, sjs_string* text_) {
    if (_parent->text._refCount == 1) { sjf_string_destroy(&_parent->text); }
;
#line 50 "lib/ui/textElement.sj"
    sjf_string_copy(&_parent->text, text_);
#line 50
    if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
#line 52
    _parent->_textrenderer._refCount = -1;
}

void sjf_textrenderer(sjs_textrenderer* _this) {
#line 27 "lib/ui/textRenderer.sj"
    vec2 pen = {{ (float)_this->point.x, (float)_this->point.y }};
#line 28
    vec4 color = {{ _this->color.r, _this->color.g, _this->color.b, _this->color.a }};
#line 30
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f,color:4f");
#line 31
    add_text(_this->buffer, _this->font->font, (char*)_this->text.data.data, _this->text.count, &color, &pen);
#line 33
    glBindTexture(GL_TEXTURE_2D, _this->font->font->atlas->id);
#line 34
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)_this->font->font->atlas->width, (int)_this->font->font->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->font->font->atlas->data );
}

void sjf_textrenderer_copy(sjs_textrenderer* _this, sjs_textrenderer* _from) {
    _this->text._refCount = 1;
#line 1 "lib/ui/textRenderer.sj"
    sjf_string_copy(&_this->text, &_from->text);
#line 1
    _this->point._refCount = 1;
#line 1
    sjf_point_copy(&_this->point, &_from->point);
#line 1
    _this->color._refCount = 1;
#line 1
    sjf_color_copy(&_this->color, &_from->color);
#line 1
    _this->font = _from->font;
#line 1
    _this->font->_refCount++;
#line 39
    _this->buffer = _from->buffer;
#line 40
    ptr_retain(_this->buffer);
}

void sjf_textrenderer_destroy(sjs_textrenderer* _this) {
#line 44 "lib/ui/textRenderer.sj"
    if (ptr_release(_this->buffer)) {
#line 45
        vertex_buffer_delete(_this->buffer);
#line 46
    }  
#line 46
    _this->font->_refCount--;
    if (_this->font->_refCount <= 0) {
        weakptr_release(_this->font);
        sjf_font_destroy(_this->font);
        free(_this->font);
    }

#line 46
    if (_this->text._refCount == 1) { sjf_string_destroy(&_this->text); }
;
#line 46
    if (_this->point._refCount == 1) { sjf_point_destroy(&_this->point); }
;
#line 46
    if (_this->color._refCount == 1) { sjf_color_destroy(&_this->color); }
;
}

void sjf_textrenderer_heap(sjs_textrenderer* _this) {
#line 27 "lib/ui/textRenderer.sj"
    vec2 pen = {{ (float)_this->point.x, (float)_this->point.y }};
#line 28
    vec4 color = {{ _this->color.r, _this->color.g, _this->color.b, _this->color.a }};
#line 30
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f,color:4f");
#line 31
    add_text(_this->buffer, _this->font->font, (char*)_this->text.data.data, _this->text.count, &color, &pen);
#line 33
    glBindTexture(GL_TEXTURE_2D, _this->font->font->atlas->id);
#line 34
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)_this->font->font->atlas->width, (int)_this->font->font->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->font->font->atlas->data );
}

void sjf_textrenderer_render(sjs_textrenderer* _parent, sjs_scene2d* scene) {
    sjs_string sjt_call12 = { -1 };
    sjs_string sjt_call13 = { -1 };
    sjs_string sjt_call14 = { -1 };
    sjs_string sjt_call15 = { -1 };
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

#line 12 "lib/ui/textRenderer.sj"
    glBindTexture(GL_TEXTURE_2D, _parent->font->atlas->id);
#line 14
    sjt_functionParam72 = &sjv_textshader;
#line 14
    sjf_gluseprogram(sjt_functionParam72);
#line 15
    sjt_functionParam73 = sjv_glblendfunctype_gl_src_alpha;
#line 15
    sjt_functionParam74 = sjv_glblendfunctype_gl_one_minus_src_alpha;
#line 15
    sjf_glblendfunc(sjt_functionParam73, sjt_functionParam74);
#line 16
    sjt_functionParam76 = &sjv_textshader;
#line 16
    sjt_call12._refCount = 1;
#line 16
    sjt_call12.count = 7;
#line 16
    sjt_call12.data._refCount = 1;
#line 16
    sjt_call12.data.datasize = 7;
#line 16
    sjt_call12.data.data = (void*)sjg_string21;
#line 16
    sjt_call12.data.isglobal = true;
#line 16
    sjt_call12.data.count = 7;
#line 16
    sjf_array_char(&sjt_call12.data);
#line 14 "lib/common/string.sj"
    sjt_call12._isnullterminated = false;
#line 14
    sjf_string(&sjt_call12);
#line 16 "lib/ui/textRenderer.sj"
    sjt_functionParam77 = &sjt_call12;
#line 16
    sjf_glgetuniformlocation(sjt_functionParam76, sjt_functionParam77, &sjt_functionParam75);
#line 16
    sjt_functionParam78 = 0;
#line 16
    sjf_gluniformi32(sjt_functionParam75, sjt_functionParam78);
#line 17
    sjt_functionParam80 = &sjv_textshader;
#line 17
    sjt_call13._refCount = 1;
#line 17
    sjt_call13.count = 5;
#line 17
    sjt_call13.data._refCount = 1;
#line 17
    sjt_call13.data.datasize = 5;
#line 17
    sjt_call13.data.data = (void*)sjg_string22;
#line 17
    sjt_call13.data.isglobal = true;
#line 17
    sjt_call13.data.count = 5;
#line 17
    sjf_array_char(&sjt_call13.data);
#line 14 "lib/common/string.sj"
    sjt_call13._isnullterminated = false;
#line 14
    sjf_string(&sjt_call13);
#line 17 "lib/ui/textRenderer.sj"
    sjt_functionParam81 = &sjt_call13;
#line 17
    sjf_glgetuniformlocation(sjt_functionParam80, sjt_functionParam81, &sjt_functionParam79);
#line 17
    sjt_functionParam82 = &scene->model;
#line 17
    sjf_gluniformmat4(sjt_functionParam79, sjt_functionParam82);
#line 18
    sjt_functionParam84 = &sjv_textshader;
#line 18
    sjt_call14._refCount = 1;
#line 18
    sjt_call14.count = 4;
#line 18
    sjt_call14.data._refCount = 1;
#line 18
    sjt_call14.data.datasize = 4;
#line 18
    sjt_call14.data.data = (void*)sjg_string23;
#line 18
    sjt_call14.data.isglobal = true;
#line 18
    sjt_call14.data.count = 4;
#line 18
    sjf_array_char(&sjt_call14.data);
#line 14 "lib/common/string.sj"
    sjt_call14._isnullterminated = false;
#line 14
    sjf_string(&sjt_call14);
#line 18 "lib/ui/textRenderer.sj"
    sjt_functionParam85 = &sjt_call14;
#line 18
    sjf_glgetuniformlocation(sjt_functionParam84, sjt_functionParam85, &sjt_functionParam83);
#line 18
    sjt_functionParam86 = &scene->view;
#line 18
    sjf_gluniformmat4(sjt_functionParam83, sjt_functionParam86);
#line 19
    sjt_functionParam88 = &sjv_textshader;
#line 19
    sjt_call15._refCount = 1;
#line 19
    sjt_call15.count = 10;
#line 19
    sjt_call15.data._refCount = 1;
#line 19
    sjt_call15.data.datasize = 10;
#line 19
    sjt_call15.data.data = (void*)sjg_string24;
#line 19
    sjt_call15.data.isglobal = true;
#line 19
    sjt_call15.data.count = 10;
#line 19
    sjf_array_char(&sjt_call15.data);
#line 14 "lib/common/string.sj"
    sjt_call15._isnullterminated = false;
#line 14
    sjf_string(&sjt_call15);
#line 19 "lib/ui/textRenderer.sj"
    sjt_functionParam89 = &sjt_call15;
#line 19
    sjf_glgetuniformlocation(sjt_functionParam88, sjt_functionParam89, &sjt_functionParam87);
#line 19
    sjt_functionParam90 = &scene->projection;
#line 19
    sjf_gluniformmat4(sjt_functionParam87, sjt_functionParam90);
#line 21
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);

    if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
;
    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
;
    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
;
}

void sjf_texture(sjs_texture* _this) {
}

void sjf_texture_copy(sjs_texture* _this, sjs_texture* _from) {
    _this->size._refCount = 1;
#line 1 "lib/ui/texture.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 1
    _this->id = _from->id;
#line 10
    glid_retain(_this->id);
}

void sjf_texture_destroy(sjs_texture* _this) {
#line 14 "lib/ui/texture.sj"
    if (glid_release(_this->id)) {
#line 15
        glDeleteTextures(1, &_this->id);
#line 16
    }
#line 16
    if (_this->size._refCount == 1) { sjf_size_destroy(&_this->size); }
;
}

void sjf_texture_frompng(sjs_string* filename, sjs_texture* _return) {
    int32_t sjv_h;
    uint32_t sjv_id;
    int32_t sjv_w;

#line 37 "lib/ui/texture.sj"
    sjv_id = (uint32_t)0u;
#line 38
    sjv_w = 0;
#line 39
    sjv_h = 0;
#line 41
    sjv_id = png_texture_load((char*)filename->data.data, &sjv_w, &sjv_h);
#line 41
    _return->_refCount = 1;
#line 41
    _return->size._refCount = 1;
#line 43
    _return->size.w = sjv_w;
#line 43
    _return->size.h = sjv_h;
#line 43
    sjf_size(&_return->size);
#line 43
    _return->id = sjv_id;
#line 43
    sjf_texture(_return);
}

void sjf_texture_frompng_heap(sjs_string* filename, sjs_texture** _return) {
    int32_t sjv_h;
    uint32_t sjv_id;
    int32_t sjv_w;

#line 37 "lib/ui/texture.sj"
    sjv_id = (uint32_t)0u;
#line 38
    sjv_w = 0;
#line 39
    sjv_h = 0;
#line 41
    sjv_id = png_texture_load((char*)filename->data.data, &sjv_w, &sjv_h);
#line 41
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
#line 41
    (*_return)->_refCount = 1;
#line 41
    (*_return)->size._refCount = 1;
#line 43
    (*_return)->size.w = sjv_w;
#line 43
    (*_return)->size.h = sjv_h;
#line 43
    sjf_size(&(*_return)->size);
#line 43
    (*_return)->id = sjv_id;
#line 43
    sjf_texture_heap((*_return));
}

void sjf_texture_getsize(sjs_texture* _parent, sjs_size* _return) {
    _return->_refCount = 1;
#line 5 "lib/ui/texture.sj"
    _return->w = (&_parent->size)->w;
#line 5
    _return->h = (&_parent->size)->h;
#line 5
    sjf_size(_return);
}

void sjf_texture_getsize_heap(sjs_texture* _parent, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 5 "lib/ui/texture.sj"
    (*_return)->w = (&_parent->size)->w;
#line 5
    (*_return)->h = (&_parent->size)->h;
#line 5
    sjf_size_heap((*_return));
}

void sjf_texture_heap(sjs_texture* _this) {
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

#line 5 "lib/common/type.sj"
    sjt_cast1 = val;
#line 6
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
#line 10 "lib/common/type.sj"
    (*_return) = l == r;
}

void sjf_vec3(sjs_vec3* _this) {
}

void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from) {
#line 1 "lib/ui/vec3.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
#line 1
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

#line 30 "lib/ui/windowRenderer.sj"
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
#line 31
        halt("SDL_Init Error: %s\n", SDL_GetError());
#line 32
    }
#line 34
    #ifdef __APPLE__
#line 35
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 36
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#line 37
    #else
#line 38
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
#line 39
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 40
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#line 41
    #endif
#line 42
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
#line 43
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
#line 45
    _this->win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
#line 46
    if (_this->win == 0) {
#line 47
        halt("SDL_CreateWindow Error: %s\n", SDL_GetError());
#line 48
    }
#line 50
    SDL_GL_CreateContext((SDL_Window*)_this->win);
#line 51
    #ifdef WIN32
#line 52
    GLint GlewInitResult = glewInit();
#line 53
    if (GLEW_OK != GlewInitResult) 
#line 54
    {
#line 55
        halt("ERROR: %s\n", glewGetErrorString(GlewInitResult));
#line 56
    }
#line 57
    #endif
#line 59
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED);
#line 60
    if (_this->ren == 0) {
#line 61
        halt("SDL_CreateRenderer Error: %s\n", SDL_GetError());
#line 62
    }
#line 62
    sjt_call1._refCount = 1;
#line 65
    sjt_call1.r = 0.0f;
#line 65
    sjt_call1.g = 0.0f;
#line 65
    sjt_call1.b = 0.0f;
#line 65
    sjt_call1.a = 0.0f;
#line 65
    sjf_color(&sjt_call1);
#line 65
    sjt_functionParam1 = &sjt_call1;
#line 65
    sjf_glclearcolor(sjt_functionParam1);
#line 66
    sjt_functionParam2 = sjv_glblendfunctype_gl_src_alpha;
#line 66
    sjt_functionParam3 = sjv_glblendfunctype_gl_one_minus_src_alpha;
#line 66
    sjf_glblendfunc(sjt_functionParam2, sjt_functionParam3);
#line 67
    sjt_functionParam4 = sjv_glfeature_gl_blend;
#line 67
    sjf_glenable(sjt_functionParam4);

    if (sjt_call1._refCount == 1) { sjf_color_destroy(&sjt_call1); }
;
}

void sjf_windowrenderer_copy(sjs_windowrenderer* _this, sjs_windowrenderer* _from) {
#line 71 "lib/ui/windowRenderer.sj"
    _this->ren = _from->ren;
#line 72
    ptr_retain(_this->ren);
#line 73
    _this->win = _from->win;
#line 74
    ptr_retain(_this->win);
}

void sjf_windowrenderer_destroy(sjs_windowrenderer* _this) {
#line 78 "lib/ui/windowRenderer.sj"
    if (ptr_release(_this->ren)) {
#line 79
        SDL_DestroyRenderer(_this->ren);
#line 80
    }
#line 81
    if (ptr_release(_this->win)) {
#line 82
        SDL_DestroyWindow(_this->win);
#line 83
    }
}

void sjf_windowrenderer_getsize(sjs_windowrenderer* _parent, sjs_size* _return) {
    int32_t sjv_h;
    int32_t sjv_w;

#line 8 "lib/ui/windowRenderer.sj"
    sjv_w = 0;
#line 9
    sjv_h = 0;
#line 11
    SDL_GetRendererOutputSize(_parent->ren, &sjv_w, &sjv_h);
#line 11
    _return->_refCount = 1;
#line 13
    _return->w = sjv_w;
#line 13
    _return->h = sjv_h;
#line 13
    sjf_size(_return);
}

void sjf_windowrenderer_getsize_heap(sjs_windowrenderer* _parent, sjs_size** _return) {
    int32_t sjv_h;
    int32_t sjv_w;

#line 8 "lib/ui/windowRenderer.sj"
    sjv_w = 0;
#line 9
    sjv_h = 0;
#line 11
    SDL_GetRendererOutputSize(_parent->ren, &sjv_w, &sjv_h);
#line 11
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
#line 11
    (*_return)->_refCount = 1;
#line 13
    (*_return)->w = sjv_w;
#line 13
    (*_return)->h = sjv_h;
#line 13
    sjf_size_heap((*_return));
}

void sjf_windowrenderer_heap(sjs_windowrenderer* _this) {
    sjs_color sjt_call2 = { -1 };
    sjs_color* sjt_functionParam5 = 0;
    int32_t sjt_functionParam6;
    int32_t sjt_functionParam7;
    int32_t sjt_functionParam8;

#line 30 "lib/ui/windowRenderer.sj"
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
#line 31
        halt("SDL_Init Error: %s\n", SDL_GetError());
#line 32
    }
#line 34
    #ifdef __APPLE__
#line 35
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 36
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#line 37
    #else
#line 38
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
#line 39
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 40
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#line 41
    #endif
#line 42
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
#line 43
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
#line 45
    _this->win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
#line 46
    if (_this->win == 0) {
#line 47
        halt("SDL_CreateWindow Error: %s\n", SDL_GetError());
#line 48
    }
#line 50
    SDL_GL_CreateContext((SDL_Window*)_this->win);
#line 51
    #ifdef WIN32
#line 52
    GLint GlewInitResult = glewInit();
#line 53
    if (GLEW_OK != GlewInitResult) 
#line 54
    {
#line 55
        halt("ERROR: %s\n", glewGetErrorString(GlewInitResult));
#line 56
    }
#line 57
    #endif
#line 59
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED);
#line 60
    if (_this->ren == 0) {
#line 61
        halt("SDL_CreateRenderer Error: %s\n", SDL_GetError());
#line 62
    }
#line 62
    sjt_call2._refCount = 1;
#line 65
    sjt_call2.r = 0.0f;
#line 65
    sjt_call2.g = 0.0f;
#line 65
    sjt_call2.b = 0.0f;
#line 65
    sjt_call2.a = 0.0f;
#line 65
    sjf_color(&sjt_call2);
#line 65
    sjt_functionParam5 = &sjt_call2;
#line 65
    sjf_glclearcolor(sjt_functionParam5);
#line 66
    sjt_functionParam6 = sjv_glblendfunctype_gl_src_alpha;
#line 66
    sjt_functionParam7 = sjv_glblendfunctype_gl_one_minus_src_alpha;
#line 66
    sjf_glblendfunc(sjt_functionParam6, sjt_functionParam7);
#line 67
    sjt_functionParam8 = sjv_glfeature_gl_blend;
#line 67
    sjf_glenable(sjt_functionParam8);

    if (sjt_call2._refCount == 1) { sjf_color_destroy(&sjt_call2); }
;
}

void sjf_windowrenderer_present(sjs_windowrenderer* _parent) {
#line 24 "lib/ui/windowRenderer.sj"
    SDL_GL_SwapWindow((SDL_Window*)_parent->win);
}

int main(int argc, char** argv) {
    sjs_buttonelement_clickable_vtbl.destroy = (void(*)(void*))sjf_buttonelement_destroy;
    sjs_buttonelement_clickable_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_buttonelement_asinterface;
    sjs_buttonelement_clickable_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_buttonelement_getclasstype;
    sjs_buttonelement_clickable_vtbl.onclickgestureenter = (void(*)(sjs_object*,sji_element))sjf_buttonelement_onclickgestureenter;
    sjs_buttonelement_clickable_vtbl.onclickgestureleave = (void(*)(sjs_object*,sji_element))sjf_buttonelement_onclickgestureleave;
    sjs_buttonelement_clickable_vtbl.onclickgesturepress = (void(*)(sjs_object*,sji_element))sjf_buttonelement_onclickgesturepress;
    sjs_buttonelement_clickable_vtbl.onclickgestureclick = (void(*)(sjs_object*,sji_element))sjf_buttonelement_onclickgestureclick;
    sjs_buttonelement_element_vtbl.destroy = (void(*)(void*))sjf_buttonelement_destroy;
    sjs_buttonelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_buttonelement_asinterface;
    sjs_buttonelement_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_buttonelement_getclasstype;
    sjs_buttonelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_buttonelement_getsize;
    sjs_buttonelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_buttonelement_getsize_heap;
    sjs_buttonelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_buttonelement_getrect;
    sjs_buttonelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_buttonelement_getrect_heap;
    sjs_buttonelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_buttonelement_setrect;
    sjs_buttonelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_buttonelement_render;
    sjs_buttonelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_buttonelement_firemouseevent;
    sjs_gridlayout_element_vtbl.destroy = (void(*)(void*))sjf_gridlayout_destroy;
    sjs_gridlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_gridlayout_asinterface;
    sjs_gridlayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_gridlayout_getclasstype;
    sjs_gridlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_gridlayout_getsize;
    sjs_gridlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_gridlayout_getsize_heap;
    sjs_gridlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_gridlayout_getrect;
    sjs_gridlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_gridlayout_getrect_heap;
    sjs_gridlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_gridlayout_setrect;
    sjs_gridlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_gridlayout_render;
    sjs_gridlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_gridlayout_firemouseevent;
    sjs_textelement_element_vtbl.destroy = (void(*)(void*))sjf_textelement_destroy;
    sjs_textelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_textelement_asinterface;
    sjs_textelement_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_textelement_getclasstype;
    sjs_textelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_textelement_getsize;
    sjs_textelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_textelement_getsize_heap;
    sjs_textelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_textelement_getrect;
    sjs_textelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_textelement_getrect_heap;
    sjs_textelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_textelement_setrect;
    sjs_textelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_textelement_render;
    sjs_textelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_textelement_firemouseevent;
    sjs_textelement_textelement_vtbl.destroy = (void(*)(void*))sjf_textelement_destroy;
    sjs_textelement_textelement_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_textelement_asinterface;
    sjs_textelement_textelement_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_textelement_getclasstype;
    sjs_textelement_textelement_vtbl.gettext = (void(*)(sjs_object*, sjs_string*))sjf_textelement_gettext;
    sjs_textelement_textelement_vtbl.gettext_heap = (void(*)(sjs_object*, sjs_string**))sjf_textelement_gettext_heap;
    sjs_textelement_textelement_vtbl.settext = (void(*)(sjs_object*,sjs_string*))sjf_textelement_settext;
#line 1 "lib/common/log.sj"
    sjv_loglevel_trace = 0;
#line 1
    sjv_loglevel_debug = 1;
#line 1
    sjv_loglevel_info = 2;
#line 1
    sjv_loglevel_warn = 3;
#line 1
    sjv_loglevel_error = 4;
#line 1
    sjv_loglevel_fatal = 5;
#line 1 "lib/ui/borderLayout.sj"
    sjv_borderposition_fill = 0;
#line 1
    sjv_borderposition_left = 1;
#line 1
    sjv_borderposition_right = 2;
#line 1
    sjv_borderposition_top = 3;
#line 1
    sjv_borderposition_bottom = 4;
#line 1 "lib/ui/clickGesture.sj"
    sjv_clickstate_none = 0;
#line 1
    sjv_clickstate_entered = 1;
#line 1
    sjv_clickstate_pressed = 2;
#line 1 "lib/ui/flowLayout.sj"
    sjv_flowlayoutorientation_topbottom = 0;
#line 1
    sjv_flowlayoutorientation_leftright = 1;
#line 1
    sjv_flowlayoutorientation_bottomtop = 2;
#line 1
    sjv_flowlayoutorientation_rightleft = 3;
#line 1 "lib/ui/gl.sj"
    sjv_glfeature_gl_blend = 0x0BE2;
#line 1
    sjv_glfeature_gl_cull_face = 0x0B44;
#line 1
    sjv_glfeature_gl_depth_test = 0x0B71;
#line 1
    sjv_glfeature_gl_dither = 0x0BD0;
#line 1
    sjv_glfeature_gl_polygon_offset_fill = 0x8037;
#line 1
    sjv_glfeature_gl_sample_alpha_to_coverage = 0x809E;
#line 1
    sjv_glfeature_gl_sample_coverage = 0x80A0;
#line 1
    sjv_glfeature_gl_scissor_test = 0x0C11;
#line 1
    sjv_glfeature_gl_stencil_test = 0x0B90;
#line 13
    sjv_gltexture_gl_texture_2d = 0x0DE1;
#line 13
    sjv_gltexture_gl_texture_cube_map = 0x8513;
#line 18
    sjv_gltextureattribute_gl_texture_min_filter = 0x2801;
#line 18
    sjv_gltextureattribute_gl_texture_mag_filter = 0x2800;
#line 18
    sjv_gltextureattribute_gl_texture_wrap_s = 0x2802;
#line 18
    sjv_gltextureattribute_gl_texture_wrap_t = 0x2803;
#line 25
    sjv_gltexturevalue_gl_clamp_to_edge = 0x812F;
#line 25
    sjv_gltexturevalue_gl_mirrored_repeat = 0x8370;
#line 25
    sjv_gltexturevalue_gl_repeat = 0x2901;
#line 25
    sjv_gltexturevalue_gl_nearest = 0x2600;
#line 25
    sjv_gltexturevalue_gl_linear = 0x2601;
#line 25
    sjv_gltexturevalue_gl_nearest_mipmap_nearest = 0x2700;
#line 25
    sjv_gltexturevalue_gl_linear_mipmap_nearest = 0x2701;
#line 25
    sjv_gltexturevalue_gl_nearest_mipmap_linear = 0x2702;
#line 25
    sjv_gltexturevalue_gl_linear_mipmap_linear = 0x2703;
#line 37
    sjv_gltextureformat_gl_alpha = 0x1906;
#line 37
    sjv_gltextureformat_gl_luminance = 0x1909;
#line 37
    sjv_gltextureformat_gl_luminance_alpha = 0x190A;
#line 37
    sjv_gltextureformat_gl_rgb = 0x1907;
#line 37
    sjv_gltextureformat_gl_rgba = 0x1908;
#line 45
    sjv_gltexturetype_gl_unsigned_byte = 0x1401;
#line 45
    sjv_gltexturetype_gl_unsigned_short_5_6_5 = 0x8363;
#line 45
    sjv_gltexturetype_gl_unsigned_short_4_4_4_4 = 0x8033;
#line 45
    sjv_gltexturetype_gl_unsigned_short_5_5_5_1 = 0x8034;
#line 52
    sjv_glframebufferattachment_gl_color_attachment0 = 0x8CE0;
#line 52
    sjv_glframebufferattachment_gl_depth_attachment = 0x8D00;
#line 52
    sjv_glframebufferattachment_gl_stencil_attachment = 0x8D20;
#line 58
    sjv_glframebuffertexture_gl_texture_2d = 0x0DE1;
#line 58
    sjv_glframebuffertexture_gl_texture_cube_map_positive_x = 0x8515;
#line 58
    sjv_glframebuffertexture_gl_texture_cube_map_negative_x = 0x8516;
#line 58
    sjv_glframebuffertexture_gl_texture_cube_map_positive_y = 0x8517;
#line 58
    sjv_glframebuffertexture_gl_texture_cube_map_negative_y = 0x8518;
#line 58
    sjv_glframebuffertexture_gl_texture_cube_map_positive_z = 0x8519;
#line 58
    sjv_glframebuffertexture_gl_texture_cube_map_negative_z = 0x851A;
#line 68
    sjv_glrenderbufferformat_gl_rgba4 = 0x8056;
#line 68
    sjv_glrenderbufferformat_gl_rgb565 = 0x8D62;
#line 68
    sjv_glrenderbufferformat_gl_rgb5_a1 = 0x8057;
#line 68
    sjv_glrenderbufferformat_gl_depth_component16 = 0x81A5;
#line 68
    sjv_glrenderbufferformat_gl_stencil_index8 = 0x8D48;
#line 76
    sjv_glframebufferstatus_gl_framebuffer_complete = 0x8CD5;
#line 76
    sjv_glframebufferstatus_gl_framebuffer_incomplete_attachment = 0x8CD6;
#line 76
    sjv_glframebufferstatus_gl_framebuffer_incomplete_missing_attachment = 0x8CD7;
#line 76
    sjv_glframebufferstatus_gl_framebuffer_unsupported = 0x8CDD;
#line 83
    sjv_glblendfunctype_gl_zero = 0;
#line 83
    sjv_glblendfunctype_gl_one = 1;
#line 83
    sjv_glblendfunctype_gl_src_color = 0x0300;
#line 83
    sjv_glblendfunctype_gl_one_minus_src_color = 0x0301;
#line 83
    sjv_glblendfunctype_gl_dst_color = 0x0306;
#line 83
    sjv_glblendfunctype_gl_one_minus_dst_color = 0x0307;
#line 83
    sjv_glblendfunctype_gl_src_alpha = 0x0302;
#line 83
    sjv_glblendfunctype_gl_one_minus_src_alpha = 0x0303;
#line 83
    sjv_glblendfunctype_gl_dst_alpha = 0x0304;
#line 83
    sjv_glblendfunctype_gl_one_minus_dst_alpha = 0x0305;
#line 83
    sjv_glblendfunctype_gl_constant_color = 0x8001;
#line 83
    sjv_glblendfunctype_gl_one_minus_constant_color = 0x8002;
#line 83
    sjv_glblendfunctype_gl_constant_alpha = 0x8003;
#line 83
    sjv_glblendfunctype_gl_one_minus_constant_alpha = 0x8004;
#line 83
    sjv_glblendfunctype_gl_src_alpha_saturate = 0x0308;
#line 101
    sjv_gldrawmode_gl_points = 0x0000;
#line 101
    sjv_gldrawmode_gl_line_strip = 0x0003;
#line 101
    sjv_gldrawmode_gl_line_loop = 0x0002;
#line 101
    sjv_gldrawmode_gl_lines = 0x0001;
#line 101
    sjv_gldrawmode_gl_triangle_strip = 0x0005;
#line 101
    sjv_gldrawmode_gl_triangle_fan = 0x0006;
#line 101
    sjv_gldrawmode_gl_triangles = 0x0004;
#line 36 "lib/ui/gridLayout.sj"
    sjv_gridunittype_fixed = 0;
#line 36
    sjv_gridunittype_star = 1;
#line 1 "lib/ui/imageElement.sj"
    sjv_imagestretch_fill = 0;
#line 1
    sjv_imagestretch_center = 1;
#line 1
    sjv_imagestretch_aspectratio = 2;
#line 1 "lib/ui/listLayout.sj"
    sjv_listlayoutorientation_topbottom = 0;
#line 1
    sjv_listlayoutorientation_leftright = 1;
#line 1
    sjv_listlayoutorientation_bottomtop = 2;
#line 1
    sjv_listlayoutorientation_rightleft = 3;
#line 32 "lib/ui/mouse.sj"
    sjv_mouseeventtype_move = 0;
#line 32
    sjv_mouseeventtype_up = 1;
#line 32
    sjv_mouseeventtype_down = 2;
#line 1 "lib/ui/textElement.sj"
    sjv_texthorizontal_left = 0;
#line 1
    sjv_texthorizontal_right = 1;
#line 1
    sjv_texthorizontal_center = 2;
#line 7
    sjv_textvertical_top = 0;
#line 7
    sjv_textvertical_bottom = 1;
#line 7
    sjv_textvertical_center = 2;
#line 1 "lib/common/f32.sj"
    sjv_f32_pi = 3.14159265358979323846f;
#line 1 "lib/common/i32.sj"
    sjv_u32_maxvalue = (uint32_t)4294967295u;
#line 3
    result1 = -1;
#line 3
    sjv_i32_maxvalue = result1 - 2147483647;
#line 4
    sjv_i32_minvalue = 2147483647;
#line 10 "lib/common/log.sj"
    sjv_log_includeall._refCount = -1;
#line 10
    sjt_value1._refCount = 1;
#line 10
    sjf_hash_type_bool(&sjt_value1);
#line 11
    sjs_hash_type_bool* copyoption1 = &sjt_value1;
    if (copyoption1 != 0) {
        sjv_log_excludeall._refCount = 1;
#line 11 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log_excludeall, copyoption1);
    } else {
        sjv_log_excludeall._refCount = -1;
    }

#line 11
    sjv_log._refCount = 1;
#line 13
    sjv_log.minlevel = sjv_loglevel_warn;
#line 13
    sjs_hash_type_bool* copyoption8 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption8 != 0) {
        sjv_log.traceincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.traceincludes, copyoption8);
    } else {
        sjv_log.traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption9 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption9 != 0) {
        sjv_log.debugincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.debugincludes, copyoption9);
    } else {
        sjv_log.debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption10 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption10 != 0) {
        sjv_log.infoincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.infoincludes, copyoption10);
    } else {
        sjv_log.infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption11 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption11 != 0) {
        sjv_log.warnincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.warnincludes, copyoption11);
    } else {
        sjv_log.warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption12 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption12 != 0) {
        sjv_log.errorincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.errorincludes, copyoption12);
    } else {
        sjv_log.errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption13 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption13 != 0) {
        sjv_log.fatalincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&sjv_log.fatalincludes, copyoption13);
    } else {
        sjv_log.fatalincludes._refCount = -1;
    }

#line 13
    sjf_log(&sjv_log);
#line 1 "lib/common/string.sj"
    sjv_emptystringdata = 0;
#line 3
    sjv_emptystringdata = "";
#line 2 "lib/common/weakptr.sj"
    ptr_init();
#line 3
    weakptr_init();
#line 7 "lib/common/clock.sj"
    sjv_clocks_per_sec = 0;
#line 9
    sjv_clocks_per_sec = CLOCKS_PER_SEC;
#line 9
    sjv_rootwindowrenderer._refCount = 1;
#line 9
    sjf_windowrenderer(&sjv_rootwindowrenderer);
#line 9
    sjv_rootscene._refCount = 1;
#line 9
    sjv_rootscene._size._refCount = 1;
#line 2 "lib/ui/size.sj"
    sjv_rootscene._size.w = 0;
#line 3
    sjv_rootscene._size.h = 0;
#line 3
    sjf_size(&sjv_rootscene._size);
#line 3
    sjv_rootscene.model._refCount = 1;
#line 2 "lib/ui/mat4.sj"
    sjv_rootscene.model.m00 = 0.0f;
#line 3
    sjv_rootscene.model.m01 = 0.0f;
#line 4
    sjv_rootscene.model.m02 = 0.0f;
#line 5
    sjv_rootscene.model.m03 = 0.0f;
#line 6
    sjv_rootscene.model.m10 = 0.0f;
#line 7
    sjv_rootscene.model.m11 = 0.0f;
#line 8
    sjv_rootscene.model.m12 = 0.0f;
#line 9
    sjv_rootscene.model.m13 = 0.0f;
#line 10
    sjv_rootscene.model.m20 = 0.0f;
#line 11
    sjv_rootscene.model.m21 = 0.0f;
#line 12
    sjv_rootscene.model.m22 = 0.0f;
#line 13
    sjv_rootscene.model.m23 = 0.0f;
#line 14
    sjv_rootscene.model.m30 = 0.0f;
#line 15
    sjv_rootscene.model.m31 = 0.0f;
#line 16
    sjv_rootscene.model.m32 = 0.0f;
#line 17
    sjv_rootscene.model.m33 = 0.0f;
#line 17
    sjf_mat4(&sjv_rootscene.model);
#line 17
    sjv_rootscene.view._refCount = 1;
#line 2
    sjv_rootscene.view.m00 = 0.0f;
#line 3
    sjv_rootscene.view.m01 = 0.0f;
#line 4
    sjv_rootscene.view.m02 = 0.0f;
#line 5
    sjv_rootscene.view.m03 = 0.0f;
#line 6
    sjv_rootscene.view.m10 = 0.0f;
#line 7
    sjv_rootscene.view.m11 = 0.0f;
#line 8
    sjv_rootscene.view.m12 = 0.0f;
#line 9
    sjv_rootscene.view.m13 = 0.0f;
#line 10
    sjv_rootscene.view.m20 = 0.0f;
#line 11
    sjv_rootscene.view.m21 = 0.0f;
#line 12
    sjv_rootscene.view.m22 = 0.0f;
#line 13
    sjv_rootscene.view.m23 = 0.0f;
#line 14
    sjv_rootscene.view.m30 = 0.0f;
#line 15
    sjv_rootscene.view.m31 = 0.0f;
#line 16
    sjv_rootscene.view.m32 = 0.0f;
#line 17
    sjv_rootscene.view.m33 = 0.0f;
#line 17
    sjf_mat4(&sjv_rootscene.view);
#line 17
    sjv_rootscene.projection._refCount = 1;
#line 2
    sjv_rootscene.projection.m00 = 0.0f;
#line 3
    sjv_rootscene.projection.m01 = 0.0f;
#line 4
    sjv_rootscene.projection.m02 = 0.0f;
#line 5
    sjv_rootscene.projection.m03 = 0.0f;
#line 6
    sjv_rootscene.projection.m10 = 0.0f;
#line 7
    sjv_rootscene.projection.m11 = 0.0f;
#line 8
    sjv_rootscene.projection.m12 = 0.0f;
#line 9
    sjv_rootscene.projection.m13 = 0.0f;
#line 10
    sjv_rootscene.projection.m20 = 0.0f;
#line 11
    sjv_rootscene.projection.m21 = 0.0f;
#line 12
    sjv_rootscene.projection.m22 = 0.0f;
#line 13
    sjv_rootscene.projection.m23 = 0.0f;
#line 14
    sjv_rootscene.projection.m30 = 0.0f;
#line 15
    sjv_rootscene.projection.m31 = 0.0f;
#line 16
    sjv_rootscene.projection.m32 = 0.0f;
#line 17
    sjv_rootscene.projection.m33 = 0.0f;
#line 17
    sjf_mat4(&sjv_rootscene.projection);
#line 17
    sjv_rootscene.windowrect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjv_rootscene.windowrect.x = 0;
#line 3
    sjv_rootscene.windowrect.y = 0;
#line 4
    sjv_rootscene.windowrect.w = 0;
#line 5
    sjv_rootscene.windowrect.h = 0;
#line 5
    sjf_rect(&sjv_rootscene.windowrect);
#line 5
    sjf_scene2d(&sjv_rootscene);
#line 5
    sjv_modelsbyid._refCount = 1;
#line 5
    sjf_hash_string_weak_iface_model(&sjv_modelsbyid);
#line 5
    sjv_elementsbyid._refCount = 1;
#line 5
    sjf_hash_string_weak_iface_element(&sjv_elementsbyid);
#line 5
    sjv_animator._refCount = 1;
#line 5
    sjv_animator.animations._refCount = 1;
#line 5
    sjv_animator.animations.array._refCount = 1;
#line 2 "lib/common/list.sj"
    sjv_animator.animations.array.datasize = 0;
#line 3 "lib/common/array.sj"
    sjv_animator.animations.array.data = 0;
#line 4
    sjv_animator.animations.array.isglobal = false;
#line 5
    sjv_animator.animations.array.count = 0;
#line 5
    sjf_array_heap_iface_animation(&sjv_animator.animations.array);
#line 5
    sjf_list_heap_iface_animation(&sjv_animator.animations);
#line 29 "lib/ui/animation.sj"
    sjv_animator.current = 0;
#line 29
    sjf_animator(&sjv_animator);
#line 29
    sjv_blurhorizontalshader._refCount = 1;
#line 29
    sjv_blurhorizontalshader.vertex._refCount = 1;
#line 1 "lib/ui/blurEffect.sj"
    sjv_blurhorizontalshader.vertex.count = 20;
#line 1
    sjv_blurhorizontalshader.vertex.data._refCount = 1;
#line 1
    sjv_blurhorizontalshader.vertex.data.datasize = 20;
#line 1
    sjv_blurhorizontalshader.vertex.data.data = (void*)sjg_string1;
#line 1
    sjv_blurhorizontalshader.vertex.data.isglobal = true;
#line 1
    sjv_blurhorizontalshader.vertex.data.count = 20;
#line 1
    sjf_array_char(&sjv_blurhorizontalshader.vertex.data);
#line 14 "lib/common/string.sj"
    sjv_blurhorizontalshader.vertex._isnullterminated = false;
#line 14
    sjf_string(&sjv_blurhorizontalshader.vertex);
#line 14
    sjv_blurhorizontalshader.pixel._refCount = 1;
#line 1 "lib/ui/blurEffect.sj"
    sjv_blurhorizontalshader.pixel.count = 28;
#line 1
    sjv_blurhorizontalshader.pixel.data._refCount = 1;
#line 1
    sjv_blurhorizontalshader.pixel.data.datasize = 28;
#line 1
    sjv_blurhorizontalshader.pixel.data.data = (void*)sjg_string2;
#line 1
    sjv_blurhorizontalshader.pixel.data.isglobal = true;
#line 1
    sjv_blurhorizontalshader.pixel.data.count = 28;
#line 1
    sjf_array_char(&sjv_blurhorizontalshader.pixel.data);
#line 14 "lib/common/string.sj"
    sjv_blurhorizontalshader.pixel._isnullterminated = false;
#line 14
    sjf_string(&sjv_blurhorizontalshader.pixel);
#line 14
    sjf_shader(&sjv_blurhorizontalshader);
#line 14
    sjv_blurverticalshader._refCount = 1;
#line 14
    sjv_blurverticalshader.vertex._refCount = 1;
#line 2 "lib/ui/blurEffect.sj"
    sjv_blurverticalshader.vertex.count = 20;
#line 2
    sjv_blurverticalshader.vertex.data._refCount = 1;
#line 2
    sjv_blurverticalshader.vertex.data.datasize = 20;
#line 2
    sjv_blurverticalshader.vertex.data.data = (void*)sjg_string1;
#line 2
    sjv_blurverticalshader.vertex.data.isglobal = true;
#line 2
    sjv_blurverticalshader.vertex.data.count = 20;
#line 2
    sjf_array_char(&sjv_blurverticalshader.vertex.data);
#line 14 "lib/common/string.sj"
    sjv_blurverticalshader.vertex._isnullterminated = false;
#line 14
    sjf_string(&sjv_blurverticalshader.vertex);
#line 14
    sjv_blurverticalshader.pixel._refCount = 1;
#line 2 "lib/ui/blurEffect.sj"
    sjv_blurverticalshader.pixel.count = 26;
#line 2
    sjv_blurverticalshader.pixel.data._refCount = 1;
#line 2
    sjv_blurverticalshader.pixel.data.datasize = 26;
#line 2
    sjv_blurverticalshader.pixel.data.data = (void*)sjg_string3;
#line 2
    sjv_blurverticalshader.pixel.data.isglobal = true;
#line 2
    sjv_blurverticalshader.pixel.data.count = 26;
#line 2
    sjf_array_char(&sjv_blurverticalshader.pixel.data);
#line 14 "lib/common/string.sj"
    sjv_blurverticalshader.pixel._isnullterminated = false;
#line 14
    sjf_string(&sjv_blurverticalshader.pixel);
#line 14
    sjf_shader(&sjv_blurverticalshader);
#line 14
    sjv_colors_red._refCount = 1;
#line 2 "lib/ui/color.sj"
    sjv_colors_red.r = 1.0f;
#line 2
    sjv_colors_red.g = 0.0f;
#line 2
    sjv_colors_red.b = 0.0f;
#line 14
    sjv_colors_red.a = 1.0f;
#line 14
    sjf_color(&sjv_colors_red);
#line 14
    sjv_colors_green._refCount = 1;
#line 3
    sjv_colors_green.r = 0.0f;
#line 3
    sjv_colors_green.g = 1.0f;
#line 3
    sjv_colors_green.b = 0.0f;
#line 14
    sjv_colors_green.a = 1.0f;
#line 14
    sjf_color(&sjv_colors_green);
#line 14
    sjv_colors_blue._refCount = 1;
#line 4
    sjv_colors_blue.r = 0.0f;
#line 4
    sjv_colors_blue.g = 0.0f;
#line 4
    sjv_colors_blue.b = 1.0f;
#line 14
    sjv_colors_blue.a = 1.0f;
#line 14
    sjf_color(&sjv_colors_blue);
#line 14
    sjv_colors_black._refCount = 1;
#line 5
    sjv_colors_black.r = 0.0f;
#line 5
    sjv_colors_black.g = 0.0f;
#line 5
    sjv_colors_black.b = 0.0f;
#line 14
    sjv_colors_black.a = 1.0f;
#line 14
    sjf_color(&sjv_colors_black);
#line 14
    sjv_colors_white._refCount = 1;
#line 6
    sjv_colors_white.r = 1.0f;
#line 6
    sjv_colors_white.g = 1.0f;
#line 6
    sjv_colors_white.b = 1.0f;
#line 14
    sjv_colors_white.a = 1.0f;
#line 14
    sjf_color(&sjv_colors_white);
#line 14
    sjv_colors_gray._refCount = 1;
#line 7
    sjv_colors_gray.r = 0.5f;
#line 7
    sjv_colors_gray.g = 0.5f;
#line 7
    sjv_colors_gray.b = 0.5f;
#line 14
    sjv_colors_gray.a = 1.0f;
#line 14
    sjf_color(&sjv_colors_gray);
#line 14
    sjv_fadeshader._refCount = 1;
#line 14
    sjv_fadeshader.vertex._refCount = 1;
#line 1 "lib/ui/fadeEffect.sj"
    sjv_fadeshader.vertex.count = 20;
#line 1
    sjv_fadeshader.vertex.data._refCount = 1;
#line 1
    sjv_fadeshader.vertex.data.datasize = 20;
#line 1
    sjv_fadeshader.vertex.data.data = (void*)sjg_string1;
#line 1
    sjv_fadeshader.vertex.data.isglobal = true;
#line 1
    sjv_fadeshader.vertex.data.count = 20;
#line 1
    sjf_array_char(&sjv_fadeshader.vertex.data);
#line 14 "lib/common/string.sj"
    sjv_fadeshader.vertex._isnullterminated = false;
#line 14
    sjf_string(&sjv_fadeshader.vertex);
#line 14
    sjv_fadeshader.pixel._refCount = 1;
#line 1 "lib/ui/fadeEffect.sj"
    sjv_fadeshader.pixel.count = 17;
#line 1
    sjv_fadeshader.pixel.data._refCount = 1;
#line 1
    sjv_fadeshader.pixel.data.datasize = 17;
#line 1
    sjv_fadeshader.pixel.data.data = (void*)sjg_string4;
#line 1
    sjv_fadeshader.pixel.data.isglobal = true;
#line 1
    sjv_fadeshader.pixel.data.count = 17;
#line 1
    sjf_array_char(&sjv_fadeshader.pixel.data);
#line 14 "lib/common/string.sj"
    sjv_fadeshader.pixel._isnullterminated = false;
#line 14
    sjf_string(&sjv_fadeshader.pixel);
#line 14
    sjf_shader(&sjv_fadeshader);
#line 14
    sjv_fonthash._refCount = 1;
#line 14
    sjf_hash_fontkey_weak_font(&sjv_fonthash);
#line 14
    sjv_glviewports._refCount = 1;
#line 14
    sjv_glviewports.array._refCount = 1;
#line 2 "lib/common/list.sj"
    sjv_glviewports.array.datasize = 0;
#line 3 "lib/common/array.sj"
    sjv_glviewports.array.data = 0;
#line 4
    sjv_glviewports.array.isglobal = false;
#line 5
    sjv_glviewports.array.count = 0;
#line 5
    sjf_array_rect(&sjv_glviewports.array);
#line 5
    sjf_list_rect(&sjv_glviewports);
#line 5
    sjv_glframebuffers._refCount = 1;
#line 5
    sjv_glframebuffers.array._refCount = 1;
#line 2 "lib/common/list.sj"
    sjv_glframebuffers.array.datasize = 0;
#line 3 "lib/common/array.sj"
    sjv_glframebuffers.array.data = 0;
#line 4
    sjv_glframebuffers.array.isglobal = false;
#line 5
    sjv_glframebuffers.array.count = 0;
#line 5
    sjf_array_u32(&sjv_glframebuffers.array);
#line 5
    sjf_list_u32(&sjv_glframebuffers);
#line 340 "lib/ui/gl.sj"
    glid_init();
#line 340
    sjv_looplastrect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjv_looplastrect.x = 0;
#line 3
    sjv_looplastrect.y = 0;
#line 4
    sjv_looplastrect.w = 0;
#line 5
    sjv_looplastrect.h = 0;
#line 5
    sjf_rect(&sjv_looplastrect);
#line 3 "lib/ui/loop.sj"
    sjv_mainloop_lasttick = 0;
#line 4
    sjv_mainloop_frames = 0;
#line 5
    sjv_mainloop_showfps = false;
#line 6
    sjv_mainloop_shouldcontinue = true;
#line 1 "lib/ui/mouse.sj"
    sjv_mouse_captureelement._parent = 0;
#line 1
    sjv_boxshader._refCount = 1;
#line 1
    sjv_boxshader.vertex._refCount = 1;
#line 1 "lib/ui/shader.sj"
    sjv_boxshader.vertex.count = 20;
#line 1
    sjv_boxshader.vertex.data._refCount = 1;
#line 1
    sjv_boxshader.vertex.data.datasize = 20;
#line 1
    sjv_boxshader.vertex.data.data = (void*)sjg_string5;
#line 1
    sjv_boxshader.vertex.data.isglobal = true;
#line 1
    sjv_boxshader.vertex.data.count = 20;
#line 1
    sjf_array_char(&sjv_boxshader.vertex.data);
#line 14 "lib/common/string.sj"
    sjv_boxshader.vertex._isnullterminated = false;
#line 14
    sjf_string(&sjv_boxshader.vertex);
#line 14
    sjv_boxshader.pixel._refCount = 1;
#line 1 "lib/ui/shader.sj"
    sjv_boxshader.pixel.count = 20;
#line 1
    sjv_boxshader.pixel.data._refCount = 1;
#line 1
    sjv_boxshader.pixel.data.datasize = 20;
#line 1
    sjv_boxshader.pixel.data.data = (void*)sjg_string6;
#line 1
    sjv_boxshader.pixel.data.isglobal = true;
#line 1
    sjv_boxshader.pixel.data.count = 20;
#line 1
    sjf_array_char(&sjv_boxshader.pixel.data);
#line 14 "lib/common/string.sj"
    sjv_boxshader.pixel._isnullterminated = false;
#line 14
    sjf_string(&sjv_boxshader.pixel);
#line 14
    sjf_shader(&sjv_boxshader);
#line 14
    sjv_imageshader._refCount = 1;
#line 14
    sjv_imageshader.vertex._refCount = 1;
#line 2 "lib/ui/shader.sj"
    sjv_imageshader.vertex.count = 20;
#line 2
    sjv_imageshader.vertex.data._refCount = 1;
#line 2
    sjv_imageshader.vertex.data.datasize = 20;
#line 2
    sjv_imageshader.vertex.data.data = (void*)sjg_string1;
#line 2
    sjv_imageshader.vertex.data.isglobal = true;
#line 2
    sjv_imageshader.vertex.data.count = 20;
#line 2
    sjf_array_char(&sjv_imageshader.vertex.data);
#line 14 "lib/common/string.sj"
    sjv_imageshader.vertex._isnullterminated = false;
#line 14
    sjf_string(&sjv_imageshader.vertex);
#line 14
    sjv_imageshader.pixel._refCount = 1;
#line 2 "lib/ui/shader.sj"
    sjv_imageshader.pixel.count = 20;
#line 2
    sjv_imageshader.pixel.data._refCount = 1;
#line 2
    sjv_imageshader.pixel.data.datasize = 20;
#line 2
    sjv_imageshader.pixel.data.data = (void*)sjg_string7;
#line 2
    sjv_imageshader.pixel.data.isglobal = true;
#line 2
    sjv_imageshader.pixel.data.count = 20;
#line 2
    sjf_array_char(&sjv_imageshader.pixel.data);
#line 14 "lib/common/string.sj"
    sjv_imageshader.pixel._isnullterminated = false;
#line 14
    sjf_string(&sjv_imageshader.pixel);
#line 14
    sjf_shader(&sjv_imageshader);
#line 14
    sjv_phongcolorshader._refCount = 1;
#line 14
    sjv_phongcolorshader.vertex._refCount = 1;
#line 3 "lib/ui/shader.sj"
    sjv_phongcolorshader.vertex.count = 26;
#line 3
    sjv_phongcolorshader.vertex.data._refCount = 1;
#line 3
    sjv_phongcolorshader.vertex.data.datasize = 26;
#line 3
    sjv_phongcolorshader.vertex.data.data = (void*)sjg_string8;
#line 3
    sjv_phongcolorshader.vertex.data.isglobal = true;
#line 3
    sjv_phongcolorshader.vertex.data.count = 26;
#line 3
    sjf_array_char(&sjv_phongcolorshader.vertex.data);
#line 14 "lib/common/string.sj"
    sjv_phongcolorshader.vertex._isnullterminated = false;
#line 14
    sjf_string(&sjv_phongcolorshader.vertex);
#line 14
    sjv_phongcolorshader.pixel._refCount = 1;
#line 3 "lib/ui/shader.sj"
    sjv_phongcolorshader.pixel.count = 26;
#line 3
    sjv_phongcolorshader.pixel.data._refCount = 1;
#line 3
    sjv_phongcolorshader.pixel.data.datasize = 26;
#line 3
    sjv_phongcolorshader.pixel.data.data = (void*)sjg_string9;
#line 3
    sjv_phongcolorshader.pixel.data.isglobal = true;
#line 3
    sjv_phongcolorshader.pixel.data.count = 26;
#line 3
    sjf_array_char(&sjv_phongcolorshader.pixel.data);
#line 14 "lib/common/string.sj"
    sjv_phongcolorshader.pixel._isnullterminated = false;
#line 14
    sjf_string(&sjv_phongcolorshader.pixel);
#line 14
    sjf_shader(&sjv_phongcolorshader);
#line 14
    sjv_phongtextureshader._refCount = 1;
#line 14
    sjv_phongtextureshader.vertex._refCount = 1;
#line 4 "lib/ui/shader.sj"
    sjv_phongtextureshader.vertex.count = 30;
#line 4
    sjv_phongtextureshader.vertex.data._refCount = 1;
#line 4
    sjv_phongtextureshader.vertex.data.datasize = 30;
#line 4
    sjv_phongtextureshader.vertex.data.data = (void*)sjg_string10;
#line 4
    sjv_phongtextureshader.vertex.data.isglobal = true;
#line 4
    sjv_phongtextureshader.vertex.data.count = 30;
#line 4
    sjf_array_char(&sjv_phongtextureshader.vertex.data);
#line 14 "lib/common/string.sj"
    sjv_phongtextureshader.vertex._isnullterminated = false;
#line 14
    sjf_string(&sjv_phongtextureshader.vertex);
#line 14
    sjv_phongtextureshader.pixel._refCount = 1;
#line 4 "lib/ui/shader.sj"
    sjv_phongtextureshader.pixel.count = 30;
#line 4
    sjv_phongtextureshader.pixel.data._refCount = 1;
#line 4
    sjv_phongtextureshader.pixel.data.datasize = 30;
#line 4
    sjv_phongtextureshader.pixel.data.data = (void*)sjg_string11;
#line 4
    sjv_phongtextureshader.pixel.data.isglobal = true;
#line 4
    sjv_phongtextureshader.pixel.data.count = 30;
#line 4
    sjf_array_char(&sjv_phongtextureshader.pixel.data);
#line 14 "lib/common/string.sj"
    sjv_phongtextureshader.pixel._isnullterminated = false;
#line 14
    sjf_string(&sjv_phongtextureshader.pixel);
#line 14
    sjf_shader(&sjv_phongtextureshader);
#line 14
    sjv_textshader._refCount = 1;
#line 14
    sjv_textshader.vertex._refCount = 1;
#line 5 "lib/ui/shader.sj"
    sjv_textshader.vertex.count = 24;
#line 5
    sjv_textshader.vertex.data._refCount = 1;
#line 5
    sjv_textshader.vertex.data.datasize = 24;
#line 5
    sjv_textshader.vertex.data.data = (void*)sjg_string12;
#line 5
    sjv_textshader.vertex.data.isglobal = true;
#line 5
    sjv_textshader.vertex.data.count = 24;
#line 5
    sjf_array_char(&sjv_textshader.vertex.data);
#line 14 "lib/common/string.sj"
    sjv_textshader.vertex._isnullterminated = false;
#line 14
    sjf_string(&sjv_textshader.vertex);
#line 14
    sjv_textshader.pixel._refCount = 1;
#line 5 "lib/ui/shader.sj"
    sjv_textshader.pixel.count = 24;
#line 5
    sjv_textshader.pixel.data._refCount = 1;
#line 5
    sjv_textshader.pixel.data.datasize = 24;
#line 5
    sjv_textshader.pixel.data.data = (void*)sjg_string13;
#line 5
    sjv_textshader.pixel.data.isglobal = true;
#line 5
    sjv_textshader.pixel.data.count = 24;
#line 5
    sjf_array_char(&sjv_textshader.pixel.data);
#line 14 "lib/common/string.sj"
    sjv_textshader.pixel._isnullterminated = false;
#line 14
    sjf_string(&sjv_textshader.pixel);
#line 14
    sjf_shader(&sjv_textshader);
#line 14
    sjv_style._refCount = 1;
#line 14
    sjf_style(&sjv_style);
#line 14
    sjv_vertex_location_texture_normal_format._refCount = 1;
#line 1 "lib/ui/vertexBufferBuilders.sj"
    sjv_vertex_location_texture_normal_format.count = 32;
#line 1
    sjv_vertex_location_texture_normal_format.data._refCount = 1;
#line 1
    sjv_vertex_location_texture_normal_format.data.datasize = 32;
#line 1
    sjv_vertex_location_texture_normal_format.data.data = (void*)sjg_string14;
#line 1
    sjv_vertex_location_texture_normal_format.data.isglobal = true;
#line 1
    sjv_vertex_location_texture_normal_format.data.count = 32;
#line 1
    sjf_array_char(&sjv_vertex_location_texture_normal_format.data);
#line 14 "lib/common/string.sj"
    sjv_vertex_location_texture_normal_format._isnullterminated = false;
#line 14
    sjf_string(&sjv_vertex_location_texture_normal_format);
#line 14
    sjv_saturateshader._refCount = 1;
#line 14
    sjv_saturateshader.vertex._refCount = 1;
#line 1 "lib/ui/saturateEffect.sj"
    sjv_saturateshader.vertex.count = 20;
#line 1
    sjv_saturateshader.vertex.data._refCount = 1;
#line 1
    sjv_saturateshader.vertex.data.datasize = 20;
#line 1
    sjv_saturateshader.vertex.data.data = (void*)sjg_string1;
#line 1
    sjv_saturateshader.vertex.data.isglobal = true;
#line 1
    sjv_saturateshader.vertex.data.count = 20;
#line 1
    sjf_array_char(&sjv_saturateshader.vertex.data);
#line 14 "lib/common/string.sj"
    sjv_saturateshader.vertex._isnullterminated = false;
#line 14
    sjf_string(&sjv_saturateshader.vertex);
#line 14
    sjv_saturateshader.pixel._refCount = 1;
#line 1 "lib/ui/saturateEffect.sj"
    sjv_saturateshader.pixel.count = 21;
#line 1
    sjv_saturateshader.pixel.data._refCount = 1;
#line 1
    sjv_saturateshader.pixel.data.datasize = 21;
#line 1
    sjv_saturateshader.pixel.data.data = (void*)sjg_string15;
#line 1
    sjv_saturateshader.pixel.data.isglobal = true;
#line 1
    sjv_saturateshader.pixel.data.count = 21;
#line 1
    sjf_array_char(&sjv_saturateshader.pixel.data);
#line 14 "lib/common/string.sj"
    sjv_saturateshader.pixel._isnullterminated = false;
#line 14
    sjf_string(&sjv_saturateshader.pixel);
#line 14
    sjf_shader(&sjv_saturateshader);
#line 14
    sjv_rootcontroller = (sjs_controller*)malloc(sizeof(sjs_controller));
#line 14
    sjv_rootcontroller->_refCount = 1;
#line 4 "button.sj"
    sjv_rootcontroller->_button1count = 0;
#line 4
    sjf_controller_heap(sjv_rootcontroller);
#line 4
    sjt_call3 = (sjs_gridlayout*)malloc(sizeof(sjs_gridlayout));
#line 4
    sjt_call3->_refCount = 1;
#line 4
    sjt_call3->children._refCount = 1;
#line 33
    sjt_call3->children.datasize = 2;
#line 3 "lib/common/array.sj"
    sjt_call3->children.data = 0;
#line 4
    sjt_call3->children.isglobal = false;
#line 5
    sjt_call3->children.count = 0;
#line 5
    sjf_array_heap_iface_element(&sjt_call3->children);
#line 33 "button.sj"
    sjs_array_heap_iface_element* array3;
#line 33
    array3 = &sjt_call3->children;
#line 33
    sjt_parent28 = array3;
#line 33
    sjt_functionParam39 = 0;
#line 33
    sjt_call5 = (sjs_buttonelement*)malloc(sizeof(sjs_buttonelement));
#line 33
    sjt_call5->_refCount = 1;
#line 33
    sjt_call5->text._refCount = 1;
#line 35
    sjt_call5->text.count = 7;
#line 35
    sjt_call5->text.data._refCount = 1;
#line 35
    sjt_call5->text.data.datasize = 7;
#line 35
    sjt_call5->text.data.data = (void*)sjg_string27;
#line 35
    sjt_call5->text.data.isglobal = true;
#line 35
    sjt_call5->text.data.count = 7;
#line 35
    sjf_array_char(&sjt_call5->text.data);
#line 14 "lib/common/string.sj"
    sjt_call5->text._isnullterminated = false;
#line 14
    sjf_string(&sjt_call5->text);
#line 14
    sjt_call5->textcolor._refCount = 1;
#line 1 "lib/ui/buttonElement.sj"
    sjf_color_copy(&sjt_call5->textcolor, &sjv_colors_black);
#line 2 "lib/ui/style.sj"
    sjt_parent54 = &sjv_style;
#line 2
    sjf_style_getfont_heap(sjt_parent54, &sjt_call5->font);
#line 2
    sjt_value5._refCount = 1;
#line 2
    sjt_call19._refCount = 1;
#line 6 "lib/ui/buttonElement.sj"
    sjt_call19.count = 23;
#line 6
    sjt_call19.data._refCount = 1;
#line 6
    sjt_call19.data.datasize = 23;
#line 6
    sjt_call19.data.data = (void*)sjg_string18;
#line 6
    sjt_call19.data.isglobal = true;
#line 6
    sjt_call19.data.count = 23;
#line 6
    sjf_array_char(&sjt_call19.data);
#line 14 "lib/common/string.sj"
    sjt_call19._isnullterminated = false;
#line 14
    sjf_string(&sjt_call19);
#line 6 "lib/ui/buttonElement.sj"
    sjt_functionParam110 = &sjt_call19;
#line 6
    sjf_texture_frompng(sjt_functionParam110, &sjt_value5.texture);
#line 6
    sjt_value5.rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_value5.rect.x = 0;
#line 3
    sjt_value5.rect.y = 0;
#line 4
    sjt_value5.rect.w = 0;
#line 5
    sjt_value5.rect.h = 0;
#line 5
    sjf_rect(&sjt_value5.rect);
#line 5
    sjt_value5.margin._refCount = 1;
#line 6 "lib/ui/buttonElement.sj"
    sjt_value5.margin.l = 2;
#line 6
    sjt_value5.margin.t = 2;
#line 6
    sjt_value5.margin.r = 2;
#line 6
    sjt_value5.margin.b = 2;
#line 6
    sjf_margin(&sjt_value5.margin);
#line 6
    sjf_image(&sjt_value5);
#line 6
    sjs_image* copyoption24 = &sjt_value5;
    if (copyoption24 != 0) {
        sjt_call5->normalimage._refCount = 1;
#line 6 "lib/ui/buttonElement.sj"
        sjf_image_copy(&sjt_call5->normalimage, copyoption24);
    } else {
        sjt_call5->normalimage._refCount = -1;
    }

#line 6
    sjt_value6._refCount = 1;
#line 6
    sjt_call20._refCount = 1;
#line 7
    sjt_call20.count = 20;
#line 7
    sjt_call20.data._refCount = 1;
#line 7
    sjt_call20.data.datasize = 20;
#line 7
    sjt_call20.data.data = (void*)sjg_string19;
#line 7
    sjt_call20.data.isglobal = true;
#line 7
    sjt_call20.data.count = 20;
#line 7
    sjf_array_char(&sjt_call20.data);
#line 14 "lib/common/string.sj"
    sjt_call20._isnullterminated = false;
#line 14
    sjf_string(&sjt_call20);
#line 7 "lib/ui/buttonElement.sj"
    sjt_functionParam111 = &sjt_call20;
#line 7
    sjf_texture_frompng(sjt_functionParam111, &sjt_value6.texture);
#line 7
    sjt_value6.rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_value6.rect.x = 0;
#line 3
    sjt_value6.rect.y = 0;
#line 4
    sjt_value6.rect.w = 0;
#line 5
    sjt_value6.rect.h = 0;
#line 5
    sjf_rect(&sjt_value6.rect);
#line 5
    sjt_value6.margin._refCount = 1;
#line 7 "lib/ui/buttonElement.sj"
    sjt_value6.margin.l = 2;
#line 7
    sjt_value6.margin.t = 2;
#line 7
    sjt_value6.margin.r = 2;
#line 7
    sjt_value6.margin.b = 2;
#line 7
    sjf_margin(&sjt_value6.margin);
#line 7
    sjf_image(&sjt_value6);
#line 7
    sjs_image* copyoption25 = &sjt_value6;
    if (copyoption25 != 0) {
        sjt_call5->hotimage._refCount = 1;
#line 7 "lib/ui/buttonElement.sj"
        sjf_image_copy(&sjt_call5->hotimage, copyoption25);
    } else {
        sjt_call5->hotimage._refCount = -1;
    }

#line 7
    sjt_value7._refCount = 1;
#line 7
    sjt_call21._refCount = 1;
#line 8
    sjt_call21.count = 24;
#line 8
    sjt_call21.data._refCount = 1;
#line 8
    sjt_call21.data.datasize = 24;
#line 8
    sjt_call21.data.data = (void*)sjg_string20;
#line 8
    sjt_call21.data.isglobal = true;
#line 8
    sjt_call21.data.count = 24;
#line 8
    sjf_array_char(&sjt_call21.data);
#line 14 "lib/common/string.sj"
    sjt_call21._isnullterminated = false;
#line 14
    sjf_string(&sjt_call21);
#line 8 "lib/ui/buttonElement.sj"
    sjt_functionParam112 = &sjt_call21;
#line 8
    sjf_texture_frompng(sjt_functionParam112, &sjt_value7.texture);
#line 8
    sjt_value7.rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_value7.rect.x = 0;
#line 3
    sjt_value7.rect.y = 0;
#line 4
    sjt_value7.rect.w = 0;
#line 5
    sjt_value7.rect.h = 0;
#line 5
    sjf_rect(&sjt_value7.rect);
#line 5
    sjt_value7.margin._refCount = 1;
#line 8 "lib/ui/buttonElement.sj"
    sjt_value7.margin.l = 2;
#line 8
    sjt_value7.margin.t = 2;
#line 8
    sjt_value7.margin.r = 2;
#line 8
    sjt_value7.margin.b = 2;
#line 8
    sjf_margin(&sjt_value7.margin);
#line 8
    sjf_image(&sjt_value7);
#line 8
    sjs_image* copyoption26 = &sjt_value7;
    if (copyoption26 != 0) {
        sjt_call5->pressedimage._refCount = 1;
#line 8 "lib/ui/buttonElement.sj"
        sjf_image_copy(&sjt_call5->pressedimage, copyoption26);
    } else {
        sjt_call5->pressedimage._refCount = -1;
    }

#line 8
    sjt_call5->margin._refCount = 1;
#line 9
    sjt_call5->margin.l = 10;
#line 9
    sjt_call5->margin.t = 10;
#line 9
    sjt_call5->margin.r = 10;
#line 9
    sjt_call5->margin.b = 10;
#line 9
    sjf_margin(&sjt_call5->margin);
#line 36 "button.sj"
    sjt_call5->onclick.inner._parent = (sjs_object*)sjv_rootcontroller;
#line 36
    sjt_call5->onclick.inner._parent->_refCount++;
#line 36
    sjt_call5->onclick._destroy = (void(*)(sjs_object*))sjf_controller_destroy;
#line 36
    sjt_call5->onclick.inner._cb = (void(*)(sjs_object*))sjf_controller_button1clicked;
#line 36
    sjt_call5->_rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_call5->_rect.x = 0;
#line 3
    sjt_call5->_rect.y = 0;
#line 4
    sjt_call5->_rect.w = 0;
#line 5
    sjt_call5->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call5->_rect);
#line 12 "lib/ui/buttonElement.sj"
    sjt_call5->_textrenderer._refCount = -1;
#line 13
    sjt_call5->_imagerenderer._refCount = -1;
#line 13
    sjt_call5->_clickgesture._refCount = 1;
#line 15 "lib/ui/clickGesture.sj"
    sjt_call5->_clickgesture.element._parent = 0;
#line 16
    sjt_call5->_clickgesture.clickable._parent = 0;
#line 16
    sjt_call5->_clickgesture.rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_call5->_clickgesture.rect.x = 0;
#line 3
    sjt_call5->_clickgesture.rect.y = 0;
#line 4
    sjt_call5->_clickgesture.rect.w = 0;
#line 5
    sjt_call5->_clickgesture.rect.h = 0;
#line 5
    sjf_rect(&sjt_call5->_clickgesture.rect);
#line 14 "lib/ui/clickGesture.sj"
    sjt_call5->_clickgesture._state = sjv_clickstate_none;
#line 14
    sjf_clickgesture(&sjt_call5->_clickgesture);
#line 14
    sjf_buttonelement_heap(sjt_call5);
#line 34 "button.sj"
    sjt_cast4 = sjt_call5;
#line 1 "lib/ui/element.sj"
    sjf_buttonelement_as_sji_element(sjt_cast4, &sjt_functionParam40);
    if (sjt_functionParam40._parent != 0) {
        sjt_functionParam40._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent28, sjt_functionParam39, sjt_functionParam40);
#line 33 "button.sj"
    sjt_parent67 = array3;
#line 33
    sjt_functionParam128 = 1;
#line 33
    sjt_call30 = (sjs_textelement*)malloc(sizeof(sjs_textelement));
#line 33
    sjt_call30->_refCount = 1;
#line 33
    sjt_value9._refCount = 1;
#line 39
    sjt_value9.count = 11;
#line 39
    sjt_value9.data._refCount = 1;
#line 39
    sjt_value9.data.datasize = 11;
#line 39
    sjt_value9.data.data = (void*)sjg_string28;
#line 39
    sjt_value9.data.isglobal = true;
#line 39
    sjt_value9.data.count = 11;
#line 39
    sjf_array_char(&sjt_value9.data);
#line 14 "lib/common/string.sj"
    sjt_value9._isnullterminated = false;
#line 14
    sjf_string(&sjt_value9);
#line 39 "button.sj"
    sjs_string* copyoption31 = &sjt_value9;
    if (copyoption31 != 0) {
        sjt_call30->id._refCount = 1;
#line 39 "button.sj"
        sjf_string_copy(&sjt_call30->id, copyoption31);
    } else {
        sjt_call30->id._refCount = -1;
    }

#line 2 "lib/ui/style.sj"
    sjt_parent81 = &sjv_style;
#line 2
    sjf_style_getfont_heap(sjt_parent81, &sjt_call30->font);
#line 2
    sjt_call30->text._refCount = 1;
#line 40 "button.sj"
    sjt_call30->text.count = 3;
#line 40
    sjt_call30->text.data._refCount = 1;
#line 40
    sjt_call30->text.data.datasize = 3;
#line 40
    sjt_call30->text.data.data = (void*)sjg_string30;
#line 40
    sjt_call30->text.data.isglobal = true;
#line 40
    sjt_call30->text.data.count = 3;
#line 40
    sjf_array_char(&sjt_call30->text.data);
#line 14 "lib/common/string.sj"
    sjt_call30->text._isnullterminated = false;
#line 14
    sjf_string(&sjt_call30->text);
#line 14
    sjt_call30->color._refCount = 1;
#line 18 "lib/ui/textElement.sj"
    sjf_color_copy(&sjt_call30->color, &sjv_colors_white);
#line 18
    sjt_call30->margin._refCount = 1;
#line 2 "lib/ui/margin.sj"
    sjt_call30->margin.l = 0;
#line 3
    sjt_call30->margin.t = 0;
#line 4
    sjt_call30->margin.r = 0;
#line 5
    sjt_call30->margin.b = 0;
#line 5
    sjf_margin(&sjt_call30->margin);
#line 18 "lib/ui/textElement.sj"
    sjt_call30->halign = sjv_texthorizontal_left;
#line 38 "button.sj"
    sjt_call30->valign = sjv_textvertical_center;
#line 27 "lib/ui/textElement.sj"
    sjt_call30->idealsize._refCount = -1;
#line 27
    sjt_call30->_rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_call30->_rect.x = 0;
#line 3
    sjt_call30->_rect.y = 0;
#line 4
    sjt_call30->_rect.w = 0;
#line 5
    sjt_call30->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call30->_rect);
#line 29 "lib/ui/textElement.sj"
    sjt_call30->_textrenderer._refCount = -1;
#line 29
    sjf_textelement_heap(sjt_call30);
#line 38 "button.sj"
    sjt_cast9 = sjt_call30;
#line 1 "lib/ui/element.sj"
    sjf_textelement_as_sji_element(sjt_cast9, &sjt_functionParam129);
    if (sjt_functionParam129._parent != 0) {
        sjt_functionParam129._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent67, sjt_functionParam128, sjt_functionParam129);
#line 22 "button.sj"
    sjt_functionParam144 = 10;
#line 22
    sjf_i32_asmargin(sjt_functionParam144, &sjt_call3->margin);
#line 22
    sjt_call3->cols._refCount = 1;
#line 23
    sjt_call3->cols.datasize = 2;
#line 3 "lib/common/array.sj"
    sjt_call3->cols.data = 0;
#line 4
    sjt_call3->cols.isglobal = false;
#line 5
    sjt_call3->cols.count = 0;
#line 5
    sjf_array_gridunit(&sjt_call3->cols);
#line 23 "button.sj"
    sjs_array_gridunit* array1;
#line 23
    array1 = &sjt_call3->cols;
#line 23
    sjt_parent82 = array1;
#line 23
    sjt_functionParam145 = 0;
#line 23
    sjt_call33._refCount = 1;
#line 24
    sjt_call33.amount = 100;
#line 24
    sjt_call33.unittype = sjv_gridunittype_fixed;
#line 24
    sjf_gridunit(&sjt_call33);
#line 24
    sjt_functionParam146 = &sjt_call33;
#line 24
    sjf_array_gridunit_initat(sjt_parent82, sjt_functionParam145, sjt_functionParam146);
#line 23
    sjt_parent83 = array1;
#line 23
    sjt_functionParam147 = 1;
#line 23
    sjt_call34._refCount = 1;
#line 25
    sjt_call34.amount = 1;
#line 25
    sjt_call34.unittype = sjv_gridunittype_star;
#line 25
    sjf_gridunit(&sjt_call34);
#line 25
    sjt_functionParam148 = &sjt_call34;
#line 25
    sjf_array_gridunit_initat(sjt_parent83, sjt_functionParam147, sjt_functionParam148);
#line 25
    sjt_call3->rows._refCount = 1;
#line 27
    sjt_call3->rows.datasize = 4;
#line 3 "lib/common/array.sj"
    sjt_call3->rows.data = 0;
#line 4
    sjt_call3->rows.isglobal = false;
#line 5
    sjt_call3->rows.count = 0;
#line 5
    sjf_array_gridunit(&sjt_call3->rows);
#line 27 "button.sj"
    sjs_array_gridunit* array2;
#line 27
    array2 = &sjt_call3->rows;
#line 27
    sjt_parent84 = array2;
#line 27
    sjt_functionParam149 = 0;
#line 27
    sjt_call35._refCount = 1;
#line 28
    sjt_call35.amount = 1;
#line 28
    sjt_call35.unittype = sjv_gridunittype_star;
#line 28
    sjf_gridunit(&sjt_call35);
#line 28
    sjt_functionParam150 = &sjt_call35;
#line 28
    sjf_array_gridunit_initat(sjt_parent84, sjt_functionParam149, sjt_functionParam150);
#line 27
    sjt_parent85 = array2;
#line 27
    sjt_functionParam151 = 1;
#line 27
    sjt_call36._refCount = 1;
#line 29
    sjt_call36.amount = 1;
#line 29
    sjt_call36.unittype = sjv_gridunittype_star;
#line 29
    sjf_gridunit(&sjt_call36);
#line 29
    sjt_functionParam152 = &sjt_call36;
#line 29
    sjf_array_gridunit_initat(sjt_parent85, sjt_functionParam151, sjt_functionParam152);
#line 27
    sjt_parent86 = array2;
#line 27
    sjt_functionParam153 = 2;
#line 27
    sjt_call37._refCount = 1;
#line 30
    sjt_call37.amount = 1;
#line 30
    sjt_call37.unittype = sjv_gridunittype_star;
#line 30
    sjf_gridunit(&sjt_call37);
#line 30
    sjt_functionParam154 = &sjt_call37;
#line 30
    sjf_array_gridunit_initat(sjt_parent86, sjt_functionParam153, sjt_functionParam154);
#line 27
    sjt_parent87 = array2;
#line 27
    sjt_functionParam155 = 3;
#line 27
    sjt_call38._refCount = 1;
#line 31
    sjt_call38.amount = 1;
#line 31
    sjt_call38.unittype = sjv_gridunittype_star;
#line 31
    sjf_gridunit(&sjt_call38);
#line 31
    sjt_functionParam156 = &sjt_call38;
#line 31
    sjf_array_gridunit_initat(sjt_parent87, sjt_functionParam155, sjt_functionParam156);
#line 31
    sjt_call3->_rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_call3->_rect.x = 0;
#line 3
    sjt_call3->_rect.y = 0;
#line 4
    sjt_call3->_rect.w = 0;
#line 5
    sjt_call3->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call3->_rect);
#line 5
    sjf_gridlayout_heap(sjt_call3);
#line 21 "button.sj"
    sjt_cast2 = sjt_call3;
#line 1 "lib/ui/element.sj"
    sjf_gridlayout_as_sji_element(sjt_cast2, &sjv_root);
    if (sjv_root._parent != 0) {
        sjv_root._parent->_refCount++;
    }

#line 1
    sjf_runloop();
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_call3->_refCount--;
    if (sjt_call3->_refCount <= 0) {
        weakptr_release(sjt_call3);
        sjf_gridlayout_destroy(sjt_call3);
        free(sjt_call3);
    }
    sjt_call30->_refCount--;
    if (sjt_call30->_refCount <= 0) {
        weakptr_release(sjt_call30);
        sjf_textelement_destroy(sjt_call30);
        free(sjt_call30);
    }
    sjt_call5->_refCount--;
    if (sjt_call5->_refCount <= 0) {
        weakptr_release(sjt_call5);
        sjf_buttonelement_destroy(sjt_call5);
        free(sjt_call5);
    }
    if (sjt_functionParam129._parent != 0) {
        sjt_functionParam129._parent->_refCount--;
        if (sjt_functionParam129._parent->_refCount <= 0) {
            sjt_functionParam129._vtbl->destroy(sjt_functionParam129._parent);
            free(sjt_functionParam129._parent);
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
    if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
;
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
;
    if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
;
    if (sjt_call33._refCount == 1) { sjf_gridunit_destroy(&sjt_call33); }
;
    if (sjt_call34._refCount == 1) { sjf_gridunit_destroy(&sjt_call34); }
;
    if (sjt_call35._refCount == 1) { sjf_gridunit_destroy(&sjt_call35); }
;
    if (sjt_call36._refCount == 1) { sjf_gridunit_destroy(&sjt_call36); }
;
    if (sjt_call37._refCount == 1) { sjf_gridunit_destroy(&sjt_call37); }
;
    if (sjt_call38._refCount == 1) { sjf_gridunit_destroy(&sjt_call38); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
    if (sjt_value5._refCount == 1) { sjf_image_destroy(&sjt_value5); }
;
    if (sjt_value6._refCount == 1) { sjf_image_destroy(&sjt_value6); }
;
    if (sjt_value7._refCount == 1) { sjf_image_destroy(&sjt_value7); }
;
    if (sjt_value9._refCount == 1) { sjf_string_destroy(&sjt_value9); }
;
    if (sjv_animator._refCount == 1) { sjf_animator_destroy(&sjv_animator); }
;
    if (sjv_blurhorizontalshader._refCount == 1) { sjf_shader_destroy(&sjv_blurhorizontalshader); }
;
    if (sjv_blurverticalshader._refCount == 1) { sjf_shader_destroy(&sjv_blurverticalshader); }
;
    if (sjv_boxshader._refCount == 1) { sjf_shader_destroy(&sjv_boxshader); }
;
    if (sjv_colors_black._refCount == 1) { sjf_color_destroy(&sjv_colors_black); }
;
    if (sjv_colors_blue._refCount == 1) { sjf_color_destroy(&sjv_colors_blue); }
;
    if (sjv_colors_gray._refCount == 1) { sjf_color_destroy(&sjv_colors_gray); }
;
    if (sjv_colors_green._refCount == 1) { sjf_color_destroy(&sjv_colors_green); }
;
    if (sjv_colors_red._refCount == 1) { sjf_color_destroy(&sjv_colors_red); }
;
    if (sjv_colors_white._refCount == 1) { sjf_color_destroy(&sjv_colors_white); }
;
    if (sjv_elementsbyid._refCount == 1) { sjf_hash_string_weak_iface_element_destroy(&sjv_elementsbyid); }
;
    if (sjv_fadeshader._refCount == 1) { sjf_shader_destroy(&sjv_fadeshader); }
;
    if (sjv_fonthash._refCount == 1) { sjf_hash_fontkey_weak_font_destroy(&sjv_fonthash); }
;
    if (sjv_glframebuffers._refCount == 1) { sjf_list_u32_destroy(&sjv_glframebuffers); }
;
    if (sjv_glviewports._refCount == 1) { sjf_list_rect_destroy(&sjv_glviewports); }
;
    if (sjv_imageshader._refCount == 1) { sjf_shader_destroy(&sjv_imageshader); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
    if (sjv_looplastrect._refCount == 1) { sjf_rect_destroy(&sjv_looplastrect); }
;
    if (sjv_modelsbyid._refCount == 1) { sjf_hash_string_weak_iface_model_destroy(&sjv_modelsbyid); }
;
    if (sjv_phongcolorshader._refCount == 1) { sjf_shader_destroy(&sjv_phongcolorshader); }
;
    if (sjv_phongtextureshader._refCount == 1) { sjf_shader_destroy(&sjv_phongtextureshader); }
;
    if (sjv_rootscene._refCount == 1) { sjf_scene2d_destroy(&sjv_rootscene); }
;
    if (sjv_rootwindowrenderer._refCount == 1) { sjf_windowrenderer_destroy(&sjv_rootwindowrenderer); }
;
    if (sjv_saturateshader._refCount == 1) { sjf_shader_destroy(&sjv_saturateshader); }
;
    if (sjv_style._refCount == 1) { sjf_style_destroy(&sjv_style); }
;
    if (sjv_textshader._refCount == 1) { sjf_shader_destroy(&sjv_textshader); }
;
    if (sjv_vertex_location_texture_normal_format._refCount == 1) { sjf_string_destroy(&sjv_vertex_location_texture_normal_format); }
;
}
