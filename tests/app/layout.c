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
const char* sjg_string16 = "assets/arial.ttf";
const char* sjg_string17 = "texture";
const char* sjg_string18 = "model";
const char* sjg_string19 = "view";
const char* sjg_string2 = "shaders/blur-horizontal.frag";
const char* sjg_string20 = "projection";
const char* sjg_string21 = "1";
const char* sjg_string22 = "2";
const char* sjg_string23 = "3";
const char* sjg_string24 = "4";
const char* sjg_string25 = "left";
const char* sjg_string26 = "bottom";
const char* sjg_string27 = "top";
const char* sjg_string28 = "right";
const char* sjg_string29 = "fill";
const char* sjg_string3 = "shaders/blur-vertical.frag";
const char* sjg_string30 = "FPS: ";
const char* sjg_string31 = "viewport being pop'ed is wrong";
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
#define sjs_array_heap_iface_model_typeId 221
#define sjs_list_heap_iface_model_typeId 55
#define sjs_point_typeId 105
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
#define sjs_array_heap_iface_element_typeId 89
#define sjs_margin_typeId 90
#define sjs_array_gridunit_typeId 92
#define sjs_gridlayout_typeId 88
#define sjs_gridunit_typeId 91
#define sjs_array_i32_typeId 96
#define sji_gridchild_typeId 100
#define sji_effect_typeId 112
#define sjs_filllayout_typeId 109
#define cb_rect_void_typeId 110
#define cb_rect_void_heap_typeId 110
#define cb_scene2d_void_typeId 111
#define cb_scene2d_void_heap_typeId 111
#define sjs_boxrenderer_typeId 124
#define sjs_boxelement_typeId 123
#define sjs_textrenderer_typeId 141
#define sjs_textelement_typeId 136
#define sji_textelement_typeId 222
#define sjs_borderlayout_typeId 157
#define sji_borderchild_typeId 159
#define sjs_borderchild_typeId 163
#define sjs_listlayout_typeId 171
#define sjs_flowlayout_typeId 177
#define sjs_centerlayout_typeId 182

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
typedef struct td_sji_textelement_vtbl sji_textelement_vtbl;
typedef struct td_sji_textelement sji_textelement;
typedef struct td_sjs_borderlayout sjs_borderlayout;
typedef struct td_sji_borderchild_vtbl sji_borderchild_vtbl;
typedef struct td_sji_borderchild sji_borderchild;
typedef struct td_sjs_borderchild sjs_borderchild;
typedef struct td_sjs_listlayout sjs_listlayout;
typedef struct td_sjs_flowlayout sjs_flowlayout;
typedef struct td_sjs_centerlayout sjs_centerlayout;

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

struct td_sji_effect_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
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
    sjs_string id;
    sjs_font font;
    sjs_string text;
    sjs_color color;
    sjs_margin margin;
    int32_t halign;
    int32_t valign;
    sjs_size idealsize;
    sjs_rect _rect;
    sjs_textrenderer _textrenderer;
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

struct td_sjs_borderlayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    sjs_rect _rect;
};

struct td_sji_borderchild_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
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
sjs_string sjt_call20 = { -1 };
sjs_string sjt_call21 = { -1 };
sjs_string sjt_call22 = { -1 };
sjs_string sjt_call23 = { -1 };
sjs_gridunit sjt_call24 = { -1 };
sjs_gridunit sjt_call25 = { -1 };
sjs_gridunit sjt_call26 = { -1 };
sjs_gridunit sjt_call27 = { -1 };
sjs_borderlayout* sjt_call28 = 0;
sjs_gridlayout* sjt_call3 = 0;
sjs_borderchild* sjt_call34 = 0;
sjs_string sjt_call35 = { -1 };
sjs_borderchild* sjt_call36 = 0;
sjs_string sjt_call37 = { -1 };
sjs_borderchild* sjt_call38 = 0;
sjs_string sjt_call39 = { -1 };
sjs_borderchild* sjt_call40 = 0;
sjs_string sjt_call41 = { -1 };
sjs_borderchild* sjt_call42 = 0;
sjs_string sjt_call43 = { -1 };
sjs_listlayout* sjt_call44 = 0;
sjs_gridlayout* sjt_call5 = 0;
sjs_string sjt_call53 = { -1 };
sjs_string sjt_call54 = { -1 };
sjs_string sjt_call55 = { -1 };
sjs_string sjt_call56 = { -1 };
sjs_flowlayout* sjt_call57 = 0;
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
sjs_string sjt_call84 = { -1 };
sjs_string sjt_call85 = { -1 };
sjs_centerlayout* sjt_call86 = 0;
sjs_string sjt_call91 = { -1 };
sjs_gridunit sjt_call92 = { -1 };
sjs_gridunit sjt_call93 = { -1 };
sjs_gridunit sjt_call94 = { -1 };
sjs_gridunit sjt_call95 = { -1 };
sjs_gridunit sjt_call96 = { -1 };
sjs_borderchild* sjt_cast12 = 0;
sjs_borderchild* sjt_cast13 = 0;
sjs_borderchild* sjt_cast14 = 0;
sjs_borderchild* sjt_cast15 = 0;
sjs_borderchild* sjt_cast16 = 0;
sjs_listlayout* sjt_cast17 = 0;
sjs_flowlayout* sjt_cast18 = 0;
sjs_centerlayout* sjt_cast19 = 0;
sjs_gridlayout* sjt_cast2 = 0;
sjs_gridlayout* sjt_cast4 = 0;
sjs_borderlayout* sjt_cast9 = 0;
sjs_string* sjt_functionParam105 = 0;
int32_t sjt_functionParam106;
sji_element sjt_functionParam107 = { 0 };
sjs_string* sjt_functionParam108 = 0;
int32_t sjt_functionParam109;
sji_element sjt_functionParam110 = { 0 };
sjs_string* sjt_functionParam111 = 0;
int32_t sjt_functionParam112;
sji_element sjt_functionParam113 = { 0 };
sjs_string* sjt_functionParam114 = 0;
int32_t sjt_functionParam115;
sjs_gridunit* sjt_functionParam116 = 0;
int32_t sjt_functionParam117;
sjs_gridunit* sjt_functionParam118 = 0;
int32_t sjt_functionParam119;
sjs_gridunit* sjt_functionParam120 = 0;
int32_t sjt_functionParam121;
sjs_gridunit* sjt_functionParam122 = 0;
int32_t sjt_functionParam123;
sji_element sjt_functionParam124 = { 0 };
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
sjs_string* sjt_functionParam141 = 0;
int32_t sjt_functionParam142;
sji_element sjt_functionParam143 = { 0 };
sjs_string* sjt_functionParam144 = 0;
int32_t sjt_functionParam145;
sji_element sjt_functionParam146 = { 0 };
int32_t sjt_functionParam151;
sji_element sjt_functionParam152 = { 0 };
sjs_string* sjt_functionParam153 = 0;
int32_t sjt_functionParam154;
sji_element sjt_functionParam155 = { 0 };
sjs_string* sjt_functionParam156 = 0;
int32_t sjt_functionParam157;
sji_element sjt_functionParam158 = { 0 };
sjs_string* sjt_functionParam159 = 0;
int32_t sjt_functionParam160;
sji_element sjt_functionParam161 = { 0 };
sjs_string* sjt_functionParam162 = 0;
int32_t sjt_functionParam163;
sji_element sjt_functionParam164 = { 0 };
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
sjs_string* sjt_functionParam233 = 0;
int32_t sjt_functionParam234;
sji_element sjt_functionParam235 = { 0 };
sjs_string* sjt_functionParam236 = 0;
int32_t sjt_functionParam237;
sji_element sjt_functionParam238 = { 0 };
int32_t sjt_functionParam251;
sji_element sjt_functionParam252 = { 0 };
sjs_string* sjt_functionParam253 = 0;
int32_t sjt_functionParam254;
sjs_gridunit* sjt_functionParam255 = 0;
int32_t sjt_functionParam256;
sjs_gridunit* sjt_functionParam257 = 0;
int32_t sjt_functionParam258;
sjs_gridunit* sjt_functionParam259 = 0;
int32_t sjt_functionParam260;
sjs_gridunit* sjt_functionParam261 = 0;
int32_t sjt_functionParam262;
sjs_gridunit* sjt_functionParam263 = 0;
int32_t sjt_functionParam39;
sji_element sjt_functionParam40 = { 0 };
int32_t sjt_functionParam41;
sji_element sjt_functionParam42 = { 0 };
sjs_array_heap_iface_element* sjt_parent100 = 0;
sjs_array_heap_iface_element* sjt_parent101 = 0;
sjs_array_heap_iface_element* sjt_parent102 = 0;
sjs_array_heap_iface_element* sjt_parent103 = 0;
sjs_array_heap_iface_element* sjt_parent104 = 0;
sjs_array_heap_iface_element* sjt_parent118 = 0;
sjs_array_heap_iface_element* sjt_parent119 = 0;
sjs_array_heap_iface_element* sjt_parent120 = 0;
sjs_array_heap_iface_element* sjt_parent121 = 0;
sjs_array_heap_iface_element* sjt_parent122 = 0;
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
sjs_array_heap_iface_element* sjt_parent154 = 0;
sjs_array_heap_iface_element* sjt_parent155 = 0;
sjs_array_heap_iface_element* sjt_parent156 = 0;
sjs_array_heap_iface_element* sjt_parent174 = 0;
sjs_array_gridunit* sjt_parent175 = 0;
sjs_array_gridunit* sjt_parent176 = 0;
sjs_array_gridunit* sjt_parent177 = 0;
sjs_array_gridunit* sjt_parent178 = 0;
sjs_array_gridunit* sjt_parent179 = 0;
sjs_array_heap_iface_element* sjt_parent28 = 0;
sjs_array_heap_iface_element* sjt_parent29 = 0;
sjs_array_heap_iface_element* sjt_parent70 = 0;
sjs_array_heap_iface_element* sjt_parent71 = 0;
sjs_array_heap_iface_element* sjt_parent72 = 0;
sjs_array_gridunit* sjt_parent73 = 0;
sjs_array_gridunit* sjt_parent74 = 0;
sjs_array_gridunit* sjt_parent75 = 0;
sjs_array_gridunit* sjt_parent76 = 0;
sjs_array_heap_iface_element* sjt_parent77 = 0;
sjs_array_heap_iface_element* sjt_parent94 = 0;
float sjt_value5;
float sjt_value6;
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
sjs_scene2d sjv_rootscene = { -1 };
sjs_windowrenderer sjv_rootwindowrenderer = { -1 };
sjs_shader sjv_saturateshader = { -1 };
sjs_style sjv_style = { -1 };
sjs_shader sjv_textshader = { -1 };
uint32_t sjv_u32_maxvalue;
sjs_string sjv_vertex_location_texture_normal_format = { -1 };
float_option value5;
float_option value6;

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
void sjf_borderchild(sjs_borderchild* _this);
void sjf_borderchild_as_sji_borderchild(sjs_borderchild* _this, sji_borderchild* _return);
void sjf_borderchild_as_sji_element(sjs_borderchild* _this, sji_element* _return);
void sjf_borderchild_asinterface(sjs_borderchild* _this, int typeId, sjs_interface* _return);
void sjf_borderchild_copy(sjs_borderchild* _this, sjs_borderchild* _from);
void sjf_borderchild_destroy(sjs_borderchild* _this);
void sjf_borderchild_firemouseevent(sjs_borderchild* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_borderchild_getclasstype(sjs_object* _this, int* _return);
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
void sjf_borderlayout_getclasstype(sjs_object* _this, int* _return);
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
void sjf_boxelement_getclasstype(sjs_object* _this, int* _return);
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
void sjf_centerlayout_getclasstype(sjs_object* _this, int* _return);
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
void sjf_debug_writeline(sjs_string* data);
void sjf_f32_asstring(float val, sjs_string* _return);
void sjf_f32_asstring_heap(float val, sjs_string** _return);
void sjf_f32_hash(float val, uint32_t* _return);
void sjf_f32_random(float* _return);
void sjf_filllayout(sjs_filllayout* _this);
void sjf_filllayout_as_sji_element(sjs_filllayout* _this, sji_element* _return);
void sjf_filllayout_asinterface(sjs_filllayout* _this, int typeId, sjs_interface* _return);
void sjf_filllayout_copy(sjs_filllayout* _this, sjs_filllayout* _from);
void sjf_filllayout_destroy(sjs_filllayout* _this);
void sjf_filllayout_firemouseevent(sjs_filllayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_filllayout_getclasstype(sjs_object* _this, int* _return);
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
void sjf_flowlayout_getclasstype(sjs_object* _this, int* _return);
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
void sjf_list_rect_getat_heap(sjs_list_rect* _parent, int32_t index, sjs_rect** _return);
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
void sjf_listlayout_getclasstype(sjs_object* _this, int* _return);
void sjf_listlayout_getrect(sjs_listlayout* _parent, sjs_rect* _return);
void sjf_listlayout_getrect_heap(sjs_listlayout* _parent, sjs_rect** _return);
void sjf_listlayout_getsize(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_listlayout_getsize_heap(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_listlayout_heap(sjs_listlayout* _this);
void sjf_listlayout_render(sjs_listlayout* _parent, sjs_scene2d* scene);
void sjf_listlayout_setrect(sjs_listlayout* _parent, sjs_rect* rect_);
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
void sjf_style_getfont(sjs_style* _parent, sjs_font* _return);
void sjf_style_getfont_heap(sjs_style* _parent, sjs_font** _return);
void sjf_style_heap(sjs_style* _this);
void sjf_testelement_heap(sjs_string* text, sji_element* _return);
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
    sjf_list_heap_iface_animation_copy(&_this->animations, &_from->animations);
    _this->current = _from->current;
}

void sjf_animator_destroy(sjs_animator* _this) {
    if (_this->animations._refCount == 1) { sjf_list_heap_iface_animation_destroy(&_this->animations); }
;
}

void sjf_animator_heap(sjs_animator* _this) {
}

void sjf_animator_nextframe(sjs_animator* _parent, int32_t time) {
    int32_t sjt_capture16;
    sjs_list_heap_iface_animation* sjt_parent180 = 0;

    _parent->current = time;
    sjt_parent180 = &_parent->animations;
    sjf_list_heap_iface_animation_getcount(sjt_parent180, &sjt_capture16);
    if (sjt_capture16 > 0) {
        int32_t i;
        int32_t sjt_forEnd23;
        int32_t sjt_forStart23;
        sjs_list_heap_iface_animation* sjt_parent181 = 0;

        sjt_forStart23 = 0;
        sjt_parent181 = &_parent->animations;
        sjf_list_heap_iface_animation_getcount(sjt_parent181, &sjt_forEnd23);
        i = sjt_forEnd23 - 1;
        while (i >= sjt_forStart23) {
            bool sjt_capture17;
            int32_t sjt_functionParam265;
            int32_t sjt_interfaceParam47;
            sjs_list_heap_iface_animation* sjt_parent183 = 0;
            sji_animation sjt_parent184 = { 0 };
            sji_animation sjv_a = { 0 };

            sjt_parent183 = &_parent->animations;
            sjt_functionParam265 = i;
            sjf_list_heap_iface_animation_getat_heap(sjt_parent183, sjt_functionParam265, &sjv_a);
            sjt_parent184 = sjv_a;
            sjt_interfaceParam47 = time;
            sjt_parent184._vtbl->nextframe(sjt_parent184._parent, sjt_interfaceParam47, &sjt_capture17);
            if (sjt_capture17) {
                int32_t sjt_functionParam266;
                sjs_list_heap_iface_animation* sjt_parent185 = 0;

                sjt_parent185 = &_parent->animations;
                sjt_functionParam266 = i;
                sjf_list_heap_iface_animation_removeat(sjt_parent185, sjt_functionParam266);
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

void sjf_array_char(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !true && !false
            char* p = (char*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
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
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        #if true
        memcpy(newp, p, sizeof(char) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
        #endif
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->isglobal = false;
    _return->count = _parent->count;
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        #if true
        memcpy(newp, p, sizeof(char) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
        #endif
    }
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->isglobal = false;
    (*_return)->count = _parent->count;
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
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

void sjf_array_gridunit(sjs_array_gridunit* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_gridunit) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_gridunit_copy(sjs_array_gridunit* _this, sjs_array_gridunit* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_gridunit_destroy(sjs_array_gridunit* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !false && !true
            sjs_gridunit* p = (sjs_gridunit*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
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

void sjf_array_gridunit_getat_heap(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit** _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_gridunit* p = (sjs_gridunit*)_parent->data;
    (*_return) = (sjs_gridunit*)malloc(sizeof(sjs_gridunit));
(*_return)->_refCount = 1;
sjf_gridunit_copy((*_return), &p[index]);
return;;       
}

void sjf_array_gridunit_heap(sjs_array_gridunit* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_gridunit) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
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
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_animation) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_iface_animation_copy(sjs_array_heap_iface_animation* _this, sjs_array_heap_iface_animation* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_heap_iface_animation_destroy(sjs_array_heap_iface_animation* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !false && !false
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
            #endif
            free(refcount);
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
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_animation) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
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
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_element) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_iface_element_copy(sjs_array_heap_iface_element* _this, sjs_array_heap_iface_element* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_heap_iface_element_destroy(sjs_array_heap_iface_element* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !false && !false
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
            #endif
            free(refcount);
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
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_element) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
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
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_model) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !false && !false
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
            #endif
            free(refcount);
        }
    }
}

void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sji_model) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
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
        _this->data = (int*)malloc(_this->datasize * sizeof(int32_t) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !true && !false
            int32_t* p = (int32_t*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
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
        _this->data = (int*)malloc(_this->datasize * sizeof(int32_t) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
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
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_rect) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_rect_copy(sjs_array_rect* _this, sjs_array_rect* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_rect_destroy(sjs_array_rect* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !false && !true
            sjs_rect* p = (sjs_rect*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
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

void sjf_array_rect_getat_heap(sjs_array_rect* _parent, int32_t index, sjs_rect** _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_rect* p = (sjs_rect*)_parent->data;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
(*_return)->_refCount = 1;
sjf_rect_copy((*_return), &p[index]);
return;;       
}

void sjf_array_rect_grow(sjs_array_rect* _parent, int32_t newsize, sjs_array_rect* _return) {
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(sjs_rect))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sjs_rect* p = (sjs_rect*)_parent->data;
        sjs_rect* newp = (sjs_rect*)sjv_newdata;
        int count = _parent->count;
        #if false
        memcpy(newp, p, sizeof(sjs_rect) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i]._refCount = 1;
sjf_rect_copy(&newp[i], &p[i]);
;
        }
        #endif
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->isglobal = false;
    _return->count = _parent->count;
    sjf_array_rect(_return);
}

void sjf_array_rect_grow_heap(sjs_array_rect* _parent, int32_t newsize, sjs_array_rect** _return) {
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(sjs_rect))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sjs_rect* p = (sjs_rect*)_parent->data;
        sjs_rect* newp = (sjs_rect*)sjv_newdata;
        int count = _parent->count;
        #if false
        memcpy(newp, p, sizeof(sjs_rect) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i]._refCount = 1;
sjf_rect_copy(&newp[i], &p[i]);
;
        }
        #endif
    }
    (*_return) = (sjs_array_rect*)malloc(sizeof(sjs_array_rect));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->isglobal = false;
    (*_return)->count = _parent->count;
    sjf_array_rect_heap((*_return));
}

void sjf_array_rect_heap(sjs_array_rect* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_rect) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
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
        _this->data = (int*)malloc(_this->datasize * sizeof(uint32_t) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_u32_copy(sjs_array_u32* _this, sjs_array_u32* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_u32_destroy(sjs_array_u32* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !true && !false
            uint32_t* p = (uint32_t*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
        }
    }
}

void sjf_array_u32_heap(sjs_array_u32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(uint32_t) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
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

    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_borderchild_firemouseevent(sjs_borderchild* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_mouseevent* sjt_interfaceParam23 = 0;
    sji_element sjt_parent99 = { 0 };

    sjt_parent99 = _parent->child;
    sjt_interfaceParam23 = mouseevent;
    sjt_parent99._vtbl->firemouseevent(sjt_parent99._parent, sjt_interfaceParam23, _return);
}

void sjf_borderchild_getclasstype(sjs_object* _this, int* _return) {
    *_return = 163;
}

void sjf_borderchild_getposition(sjs_borderchild* _parent, int32_t* _return) {
    (*_return) = _parent->position;
}

void sjf_borderchild_getrect(sjs_borderchild* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_borderchild_getrect_heap(sjs_borderchild* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_borderchild_getsize(sjs_borderchild* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_interfaceParam19 = 0;
    sji_element sjt_parent95 = { 0 };

    sjt_parent95 = _parent->child;
    sjt_interfaceParam19 = maxsize;
    sjt_parent95._vtbl->getsize(sjt_parent95._parent, sjt_interfaceParam19, _return);
}

void sjf_borderchild_getsize_heap(sjs_borderchild* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_interfaceParam20 = 0;
    sji_element sjt_parent96 = { 0 };

    sjt_parent96 = _parent->child;
    sjt_interfaceParam20 = maxsize;
    sjt_parent96._vtbl->getsize_heap(sjt_parent96._parent, sjt_interfaceParam20, _return);
}

void sjf_borderchild_heap(sjs_borderchild* _this) {
}

void sjf_borderchild_render(sjs_borderchild* _parent, sjs_scene2d* scene) {
    sjs_scene2d* sjt_interfaceParam22 = 0;
    sji_element sjt_parent98 = { 0 };

    sjt_parent98 = _parent->child;
    sjt_interfaceParam22 = scene;
    sjt_parent98._vtbl->render(sjt_parent98._parent, sjt_interfaceParam22);
}

void sjf_borderchild_setrect(sjs_borderchild* _parent, sjs_rect* rect_) {
    sjs_rect* sjt_interfaceParam21 = 0;
    sji_element sjt_parent97 = { 0 };

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
    sjf_rect_copy(&_parent->_rect, rect_);
    sjt_parent97 = _parent->child;
    sjt_interfaceParam21 = &_parent->_rect;
    sjt_parent97._vtbl->setrect(sjt_parent97._parent, sjt_interfaceParam21);
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
    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_borderlayout_firemouseevent(sjs_borderlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam129 = 0;
    sjs_mouseevent* sjt_parent93 = 0;

    sjt_parent93 = mouseevent;
    sjt_functionParam129 = &_parent->children;
    sjf_mouseevent_firechildren(sjt_parent93, sjt_functionParam129, _return);
}

void sjf_borderlayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 157;
}

void sjf_borderlayout_getrect(sjs_borderlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_borderlayout_getrect_heap(sjs_borderlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_borderlayout_getsize(sjs_borderlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    _return->w = maxsize->w;
    _return->h = maxsize->h;
    sjf_size(_return);
}

void sjf_borderlayout_getsize_heap(sjs_borderlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    (*_return)->w = maxsize->w;
    (*_return)->h = maxsize->h;
    sjf_size_heap((*_return));
}

void sjf_borderlayout_heap(sjs_borderlayout* _this) {
}

void sjf_borderlayout_render(sjs_borderlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd14;
    int32_t sjt_forStart14;

    sjt_forStart14 = 0;
    sjt_forEnd14 = (&_parent->children)->count;
    i = sjt_forStart14;
    while (i < sjt_forEnd14) {
        int32_t sjt_functionParam128;
        sjs_scene2d* sjt_interfaceParam18 = 0;
        sjs_array_heap_iface_element* sjt_parent91 = 0;
        sji_element sjt_parent92 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent91 = &_parent->children;
        sjt_functionParam128 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent91, sjt_functionParam128, &sjv_child);
        sjt_parent92 = sjv_child;
        sjt_interfaceParam18 = scene;
        sjt_parent92._vtbl->render(sjt_parent92._parent, sjt_interfaceParam18);
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
    int32_t sjt_forEnd12;
    int32_t sjt_forEnd13;
    int32_t sjt_forStart12;
    int32_t sjt_forStart13;
    sjs_margin* sjt_functionParam125 = 0;
    sjs_rect* sjt_parent78 = 0;
    sjs_rect sjv_remaining = { -1 };

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
    sjf_rect_copy(&_parent->_rect, rect_);
    sjt_parent78 = rect_;
    sjt_functionParam125 = &_parent->margin;
    sjf_rect_subtractmargin(sjt_parent78, sjt_functionParam125, &sjv_remaining);
    sjt_forStart12 = 0;
    sjt_forEnd12 = (&_parent->children)->count;
    i = sjt_forStart12;
    while (i < sjt_forEnd12) {
        sjs_size sjt_call29 = { -1 };
        sjs_rect sjt_call30 = { -1 };
        sjs_rect sjt_call31 = { -1 };
        sjs_rect sjt_call32 = { -1 };
        sjs_rect sjt_call33 = { -1 };
        int32_option sjt_capture14;
        sji_element sjt_cast10 = { 0 };
        sjs_rect sjt_funcold5 = { -1 };
        sjs_rect sjt_funcold6 = { -1 };
        sjs_rect sjt_funcold7 = { -1 };
        sjs_rect sjt_funcold8 = { -1 };
        int32_t sjt_functionParam126;
        sjs_array_heap_iface_element* sjt_parent79 = 0;
        sji_borderchild sjv_borderchild = { 0 };
        sji_element sjv_child = { 0 };
        sjs_size sjv_childsize = { -1 };
        int32_t sjv_position;

        sjt_parent79 = &_parent->children;
        sjt_functionParam126 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent79, sjt_functionParam126, &sjv_child);
        sjt_cast10 = sjv_child;
        sjt_cast10._vtbl->asinterface(sjt_cast10._parent, sji_borderchild_typeId, (sjs_interface*)&sjv_borderchild);
        if (sjv_borderchild._parent != 0) {
            sjv_borderchild._parent->_refCount++;
        }

        if (sjv_borderchild._parent != 0) {
            sji_borderchild sjt_parent80 = { 0 };
            int32_t sjt_value1;
            int32_option value1;

            sjt_parent80 = sjv_borderchild;
            sjt_parent80._vtbl->getposition(sjt_parent80._parent, &sjt_value1);
            value1.isvalid = true;
            value1.value = sjt_value1;
            sjt_capture14 = value1;
        } else {
            sjt_capture14 = int32_empty;
        }

        if (sjt_capture14.isvalid) {
            int32_option sjt_getValue1;

            if (sjv_borderchild._parent != 0) {
                sji_borderchild sjt_parent81 = { 0 };
                int32_t sjt_value2;
                int32_option value2;

                sjt_parent81 = sjv_borderchild;
                sjt_parent81._vtbl->getposition(sjt_parent81._parent, &sjt_value2);
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

        if (sjv_position != sjv_borderposition_fill) {
            sjs_size* sjt_interfaceParam12 = 0;
            sji_element sjt_parent82 = { 0 };

            sjt_parent82 = sjv_child;
            sjt_call29._refCount = 1;
            sjt_call29.w = (&sjv_remaining)->w;
            sjt_call29.h = (&sjv_remaining)->h;
            sjf_size(&sjt_call29);
            sjt_interfaceParam12 = &sjt_call29;
            sjt_parent82._vtbl->getsize(sjt_parent82._parent, sjt_interfaceParam12, &sjv_childsize);
            if (sjv_position == sjv_borderposition_left) {
                sjs_rect* sjt_interfaceParam13 = 0;
                sji_element sjt_parent83 = { 0 };

                sjt_parent83 = sjv_child;
                sjt_call30._refCount = 1;
                sjt_call30.x = (&sjv_remaining)->x;
                sjt_call30.y = (&sjv_remaining)->y;
                sjt_call30.w = (&sjv_childsize)->w;
                sjt_call30.h = (&sjv_remaining)->h;
                sjf_rect(&sjt_call30);
                sjt_interfaceParam13 = &sjt_call30;
                sjt_parent83._vtbl->setrect(sjt_parent83._parent, sjt_interfaceParam13);
                sjt_funcold5._refCount = 1;
                sjf_rect_copy(&sjt_funcold5, &sjv_remaining);
                sjt_funcold5._refCount = 1;
                sjt_funcold5.x = (&sjv_remaining)->x + (&sjv_childsize)->w;
                sjt_funcold5.y = (&sjv_remaining)->y;
                sjt_funcold5.w = (&sjv_remaining)->w - (&sjv_childsize)->w;
                sjt_funcold5.h = (&sjv_remaining)->h;
                sjf_rect(&sjt_funcold5);
                if (sjv_remaining._refCount == 1) { sjf_rect_destroy(&sjv_remaining); }
;
                sjf_rect_copy(&sjv_remaining, &sjt_funcold5);
            } else {
                if (sjv_position == sjv_borderposition_right) {
                    sjs_rect* sjt_interfaceParam14 = 0;
                    sji_element sjt_parent84 = { 0 };

                    sjt_parent84 = sjv_child;
                    sjt_call31._refCount = 1;
                    sjt_call31.x = ((&sjv_remaining)->x + (&sjv_remaining)->w) - (&sjv_childsize)->w;
                    sjt_call31.y = (&sjv_remaining)->y;
                    sjt_call31.w = (&sjv_childsize)->w;
                    sjt_call31.h = (&sjv_remaining)->h;
                    sjf_rect(&sjt_call31);
                    sjt_interfaceParam14 = &sjt_call31;
                    sjt_parent84._vtbl->setrect(sjt_parent84._parent, sjt_interfaceParam14);
                    sjt_funcold6._refCount = 1;
                    sjf_rect_copy(&sjt_funcold6, &sjv_remaining);
                    sjt_funcold6._refCount = 1;
                    sjt_funcold6.x = (&sjv_remaining)->x;
                    sjt_funcold6.y = (&sjv_remaining)->y;
                    sjt_funcold6.w = (&sjv_remaining)->w - (&sjv_childsize)->w;
                    sjt_funcold6.h = (&sjv_remaining)->h;
                    sjf_rect(&sjt_funcold6);
                    if (sjv_remaining._refCount == 1) { sjf_rect_destroy(&sjv_remaining); }
;
                    sjf_rect_copy(&sjv_remaining, &sjt_funcold6);
                } else {
                    if (sjv_position == sjv_borderposition_top) {
                        sjs_rect* sjt_interfaceParam15 = 0;
                        sji_element sjt_parent85 = { 0 };

                        sjt_parent85 = sjv_child;
                        sjt_call32._refCount = 1;
                        sjt_call32.x = (&sjv_remaining)->x;
                        sjt_call32.y = (&sjv_remaining)->y;
                        sjt_call32.w = (&sjv_remaining)->w;
                        sjt_call32.h = (&sjv_childsize)->h;
                        sjf_rect(&sjt_call32);
                        sjt_interfaceParam15 = &sjt_call32;
                        sjt_parent85._vtbl->setrect(sjt_parent85._parent, sjt_interfaceParam15);
                        sjt_funcold7._refCount = 1;
                        sjf_rect_copy(&sjt_funcold7, &sjv_remaining);
                        sjt_funcold7._refCount = 1;
                        sjt_funcold7.x = (&sjv_remaining)->x;
                        sjt_funcold7.y = (&sjv_remaining)->y + (&sjv_childsize)->h;
                        sjt_funcold7.w = (&sjv_remaining)->w;
                        sjt_funcold7.h = (&sjv_remaining)->h - (&sjv_childsize)->h;
                        sjf_rect(&sjt_funcold7);
                        if (sjv_remaining._refCount == 1) { sjf_rect_destroy(&sjv_remaining); }
;
                        sjf_rect_copy(&sjv_remaining, &sjt_funcold7);
                    } else {
                        if (sjv_position == sjv_borderposition_bottom) {
                            sjs_rect* sjt_interfaceParam16 = 0;
                            sji_element sjt_parent86 = { 0 };

                            sjt_parent86 = sjv_child;
                            sjt_call33._refCount = 1;
                            sjt_call33.x = (&sjv_remaining)->x;
                            sjt_call33.y = ((&sjv_remaining)->y + (&sjv_remaining)->h) - (&sjv_childsize)->h;
                            sjt_call33.w = (&sjv_remaining)->w;
                            sjt_call33.h = (&sjv_childsize)->h;
                            sjf_rect(&sjt_call33);
                            sjt_interfaceParam16 = &sjt_call33;
                            sjt_parent86._vtbl->setrect(sjt_parent86._parent, sjt_interfaceParam16);
                            sjt_funcold8._refCount = 1;
                            sjf_rect_copy(&sjt_funcold8, &sjv_remaining);
                            sjt_funcold8._refCount = 1;
                            sjt_funcold8.x = (&sjv_remaining)->x;
                            sjt_funcold8.y = (&sjv_remaining)->y;
                            sjt_funcold8.w = (&sjv_remaining)->w;
                            sjt_funcold8.h = (&sjv_remaining)->h - (&sjv_childsize)->h;
                            sjf_rect(&sjt_funcold8);
                            if (sjv_remaining._refCount == 1) { sjf_rect_destroy(&sjv_remaining); }
;
                            sjf_rect_copy(&sjv_remaining, &sjt_funcold8);
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
        if (sjt_call29._refCount == 1) { sjf_size_destroy(&sjt_call29); }
;
        if (sjt_call30._refCount == 1) { sjf_rect_destroy(&sjt_call30); }
;
        if (sjt_call31._refCount == 1) { sjf_rect_destroy(&sjt_call31); }
;
        if (sjt_call32._refCount == 1) { sjf_rect_destroy(&sjt_call32); }
;
        if (sjt_call33._refCount == 1) { sjf_rect_destroy(&sjt_call33); }
;
        if (sjt_funcold5._refCount == 1) { sjf_rect_destroy(&sjt_funcold5); }
;
        if (sjt_funcold6._refCount == 1) { sjf_rect_destroy(&sjt_funcold6); }
;
        if (sjt_funcold7._refCount == 1) { sjf_rect_destroy(&sjt_funcold7); }
;
        if (sjt_funcold8._refCount == 1) { sjf_rect_destroy(&sjt_funcold8); }
;
        if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
;
    }

    sjt_forStart13 = 0;
    sjt_forEnd13 = (&_parent->children)->count;
    i = sjt_forStart13;
    while (i < sjt_forEnd13) {
        int32_option sjt_capture15;
        sji_element sjt_cast11 = { 0 };
        int32_t sjt_functionParam127;
        sjs_array_heap_iface_element* sjt_parent87 = 0;
        sji_borderchild sjv_borderchild2 = { 0 };
        sji_element sjv_child2 = { 0 };
        int32_t sjv_position2;

        sjt_parent87 = &_parent->children;
        sjt_functionParam127 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent87, sjt_functionParam127, &sjv_child2);
        sjt_cast11 = sjv_child2;
        sjt_cast11._vtbl->asinterface(sjt_cast11._parent, sji_borderchild_typeId, (sjs_interface*)&sjv_borderchild2);
        if (sjv_borderchild2._parent != 0) {
            sjv_borderchild2._parent->_refCount++;
        }

        if (sjv_borderchild2._parent != 0) {
            sji_borderchild sjt_parent88 = { 0 };
            int32_t sjt_value3;
            int32_option value3;

            sjt_parent88 = sjv_borderchild2;
            sjt_parent88._vtbl->getposition(sjt_parent88._parent, &sjt_value3);
            value3.isvalid = true;
            value3.value = sjt_value3;
            sjt_capture15 = value3;
        } else {
            sjt_capture15 = int32_empty;
        }

        if (sjt_capture15.isvalid) {
            int32_option sjt_getValue2;

            if (sjv_borderchild2._parent != 0) {
                sji_borderchild sjt_parent89 = { 0 };
                int32_t sjt_value4;
                int32_option value4;

                sjt_parent89 = sjv_borderchild2;
                sjt_parent89._vtbl->getposition(sjt_parent89._parent, &sjt_value4);
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

        if (sjv_position2 == sjv_borderposition_fill) {
            sjs_rect* sjt_interfaceParam17 = 0;
            sji_element sjt_parent90 = { 0 };

            sjt_parent90 = sjv_child2;
            sjt_interfaceParam17 = &sjv_remaining;
            sjt_parent90._vtbl->setrect(sjt_parent90._parent, sjt_interfaceParam17);
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
;
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
    sjs_boxrenderer* copyoption13 = (_from->boxrenderer._refCount != -1 ? &_from->boxrenderer : 0);
    if (copyoption13 != 0) {
        _this->boxrenderer._refCount = 1;
        sjf_boxrenderer_copy(&_this->boxrenderer, copyoption13);
    } else {
        _this->boxrenderer._refCount = -1;
    }
}

void sjf_boxelement_destroy(sjs_boxelement* _this) {
    if (_this->color._refCount == 1) { sjf_color_destroy(&_this->color); }
;
    if (_this->idealsize._refCount == 1) { sjf_size_destroy(&_this->idealsize); }
;
    if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
    if (_this->boxrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_this->boxrenderer); }
;
}

void sjf_boxelement_firemouseevent(sjs_boxelement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
}

void sjf_boxelement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 123;
}

void sjf_boxelement_getrect(sjs_boxelement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, &_parent->rect);
}

void sjf_boxelement_getrect_heap(sjs_boxelement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), &_parent->rect);
}

void sjf_boxelement_getsize(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_functionParam59 = 0;
    sjs_size* sjt_parent49 = 0;

    sjt_parent49 = &_parent->idealsize;
    sjt_functionParam59 = maxsize;
    sjf_size_min(sjt_parent49, sjt_functionParam59, _return);
}

void sjf_boxelement_getsize_heap(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_functionParam60 = 0;
    sjs_size* sjt_parent50 = 0;

    sjt_parent50 = &_parent->idealsize;
    sjt_functionParam60 = maxsize;
    sjf_size_min_heap(sjt_parent50, sjt_functionParam60, _return);
}

void sjf_boxelement_heap(sjs_boxelement* _this) {
}

void sjf_boxelement_render(sjs_boxelement* _parent, sjs_scene2d* scene) {
    sjs_boxrenderer sjt_funcold3 = { -1 };

    if ((_parent->boxrenderer._refCount != -1 ? &_parent->boxrenderer : 0) == 0) {
        _parent->boxrenderer._refCount = 1;
        sjt_funcold3._refCount = 1;
        sjf_boxrenderer_copy(&sjt_funcold3, &_parent->boxrenderer);
        sjt_funcold3._refCount = 1;
        sjt_funcold3.rect._refCount = 1;
        sjf_rect_copy(&sjt_funcold3.rect, &_parent->rect);
        sjt_funcold3.color._refCount = 1;
        sjf_color_copy(&sjt_funcold3.color, &_parent->color);
        sjf_boxrenderer(&sjt_funcold3);
        if (_parent->boxrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_parent->boxrenderer); }
;
        sjf_boxrenderer_copy(&_parent->boxrenderer, &sjt_funcold3);
    }

    if ((_parent->boxrenderer._refCount != -1 ? &_parent->boxrenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam62 = 0;
        sjs_boxrenderer* sjt_parent52 = 0;

        sjt_parent52 = (_parent->boxrenderer._refCount != -1 ? &_parent->boxrenderer : 0);
        sjt_functionParam62 = scene;
        sjf_boxrenderer_render(sjt_parent52, sjt_functionParam62);
    }

    if (sjt_funcold3._refCount == 1) { sjf_boxrenderer_destroy(&sjt_funcold3); }
;
}

void sjf_boxelement_setrect(sjs_boxelement* _parent, sjs_rect* rect_) {
    bool result2;
    bool sjt_capture10;
    sjs_rect* sjt_functionParam61 = 0;
    sjs_rect* sjt_parent51 = 0;

    sjt_parent51 = &_parent->rect;
    sjt_functionParam61 = rect_;
    sjf_rect_isequal(sjt_parent51, sjt_functionParam61, &sjt_capture10);
    result2 = !sjt_capture10;
    if (result2) {
        if (_parent->rect._refCount == 1) { sjf_rect_destroy(&_parent->rect); }
;
        sjf_rect_copy(&_parent->rect, rect_);
        if (_parent->boxrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_parent->boxrenderer); }
;
        _parent->boxrenderer._refCount = -1;
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
    if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
    if (_this->color._refCount == 1) { sjf_color_destroy(&_this->color); }
;
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
    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_centerlayout_firemouseevent(sjs_centerlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam250 = 0;
    sjs_mouseevent* sjt_parent173 = 0;

    sjt_parent173 = mouseevent;
    sjt_functionParam250 = &_parent->children;
    sjf_mouseevent_firechildren(sjt_parent173, sjt_functionParam250, _return);
}

void sjf_centerlayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 182;
}

void sjf_centerlayout_getrect(sjs_centerlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_centerlayout_getrect_heap(sjs_centerlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_centerlayout_getsize(sjs_centerlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t i;
    int32_t sjt_forEnd19;
    int32_t sjt_forStart19;
    sjs_margin* sjt_functionParam239 = 0;
    sjs_margin* sjt_functionParam242 = 0;
    sjs_size* sjt_parent157 = 0;
    sjs_size* sjt_parent161 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
    sjv_size.w = 0;
    sjv_size.h = 0;
    sjf_size(&sjv_size);
    sjt_parent157 = maxsize;
    sjt_functionParam239 = &_parent->margin;
    sjf_size_subtractmargin(sjt_parent157, sjt_functionParam239, &sjv_innersize);
    sjt_forStart19 = 0;
    sjt_forEnd19 = (&_parent->children)->count;
    i = sjt_forStart19;
    while (i < sjt_forEnd19) {
        sjs_size sjt_call87 = { -1 };
        sjs_size sjt_funcold13 = { -1 };
        int32_t sjt_functionParam240;
        sjs_size* sjt_functionParam241 = 0;
        sjs_size* sjt_interfaceParam42 = 0;
        sjs_array_heap_iface_element* sjt_parent158 = 0;
        sjs_size* sjt_parent159 = 0;
        sji_element sjt_parent160 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent158 = &_parent->children;
        sjt_functionParam240 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent158, sjt_functionParam240, &sjv_child);
        sjt_funcold13._refCount = 1;
        sjf_size_copy(&sjt_funcold13, &sjv_size);
        sjt_parent159 = &sjv_size;
        sjt_parent160 = sjv_child;
        sjt_interfaceParam42 = &sjv_innersize;
        sjt_parent160._vtbl->getsize(sjt_parent160._parent, sjt_interfaceParam42, &sjt_call87);
        sjt_functionParam241 = &sjt_call87;
        sjf_size_max(sjt_parent159, sjt_functionParam241, &sjt_funcold13);
        if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
        sjf_size_copy(&sjv_size, &sjt_funcold13);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call87._refCount == 1) { sjf_size_destroy(&sjt_call87); }
;
        if (sjt_funcold13._refCount == 1) { sjf_size_destroy(&sjt_funcold13); }
;
    }

    sjt_parent161 = &sjv_size;
    sjt_functionParam242 = &_parent->margin;
    sjf_size_addmargin(sjt_parent161, sjt_functionParam242, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_centerlayout_getsize_heap(sjs_centerlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t i;
    int32_t sjt_forEnd20;
    int32_t sjt_forStart20;
    sjs_margin* sjt_functionParam243 = 0;
    sjs_margin* sjt_functionParam246 = 0;
    sjs_size* sjt_parent162 = 0;
    sjs_size* sjt_parent166 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
    sjv_size.w = 0;
    sjv_size.h = 0;
    sjf_size(&sjv_size);
    sjt_parent162 = maxsize;
    sjt_functionParam243 = &_parent->margin;
    sjf_size_subtractmargin(sjt_parent162, sjt_functionParam243, &sjv_innersize);
    sjt_forStart20 = 0;
    sjt_forEnd20 = (&_parent->children)->count;
    i = sjt_forStart20;
    while (i < sjt_forEnd20) {
        sjs_size sjt_call88 = { -1 };
        sjs_size sjt_funcold14 = { -1 };
        int32_t sjt_functionParam244;
        sjs_size* sjt_functionParam245 = 0;
        sjs_size* sjt_interfaceParam43 = 0;
        sjs_array_heap_iface_element* sjt_parent163 = 0;
        sjs_size* sjt_parent164 = 0;
        sji_element sjt_parent165 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent163 = &_parent->children;
        sjt_functionParam244 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent163, sjt_functionParam244, &sjv_child);
        sjt_funcold14._refCount = 1;
        sjf_size_copy(&sjt_funcold14, &sjv_size);
        sjt_parent164 = &sjv_size;
        sjt_parent165 = sjv_child;
        sjt_interfaceParam43 = &sjv_innersize;
        sjt_parent165._vtbl->getsize(sjt_parent165._parent, sjt_interfaceParam43, &sjt_call88);
        sjt_functionParam245 = &sjt_call88;
        sjf_size_max(sjt_parent164, sjt_functionParam245, &sjt_funcold14);
        if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
        sjf_size_copy(&sjv_size, &sjt_funcold14);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call88._refCount == 1) { sjf_size_destroy(&sjt_call88); }
;
        if (sjt_funcold14._refCount == 1) { sjf_size_destroy(&sjt_funcold14); }
;
    }

    sjt_parent166 = &sjv_size;
    sjt_functionParam246 = &_parent->margin;
    sjf_size_addmargin_heap(sjt_parent166, sjt_functionParam246, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_centerlayout_heap(sjs_centerlayout* _this) {
}

void sjf_centerlayout_render(sjs_centerlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd22;
    int32_t sjt_forStart22;

    sjt_forStart22 = 0;
    sjt_forEnd22 = (&_parent->children)->count;
    i = sjt_forStart22;
    while (i < sjt_forEnd22) {
        int32_t sjt_functionParam249;
        sjs_scene2d* sjt_interfaceParam46 = 0;
        sjs_array_heap_iface_element* sjt_parent171 = 0;
        sji_element sjt_parent172 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent171 = &_parent->children;
        sjt_functionParam249 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent171, sjt_functionParam249, &sjv_child);
        sjt_parent172 = sjv_child;
        sjt_interfaceParam46 = scene;
        sjt_parent172._vtbl->render(sjt_parent172._parent, sjt_interfaceParam46);
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
    int32_t sjt_forEnd21;
    int32_t sjt_forStart21;
    sjs_margin* sjt_functionParam247 = 0;
    sjs_rect* sjt_parent167 = 0;
    sjs_rect sjv_innerrect = { -1 };

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
    sjf_rect_copy(&_parent->_rect, rect_);
    sjt_parent167 = &_parent->_rect;
    sjt_functionParam247 = &_parent->margin;
    sjf_rect_subtractmargin(sjt_parent167, sjt_functionParam247, &sjv_innerrect);
    sjt_forStart21 = 0;
    sjt_forEnd21 = (&_parent->children)->count;
    i = sjt_forStart21;
    while (i < sjt_forEnd21) {
        sjs_size sjt_call89 = { -1 };
        sjs_rect sjt_call90 = { -1 };
        int32_t sjt_functionParam248;
        sjs_size* sjt_interfaceParam44 = 0;
        sjs_rect* sjt_interfaceParam45 = 0;
        sjs_array_heap_iface_element* sjt_parent168 = 0;
        sji_element sjt_parent169 = { 0 };
        sji_element sjt_parent170 = { 0 };
        sji_element sjv_child = { 0 };
        sjs_size sjv_childsize = { -1 };
        int32_t sjv_h;
        int32_t sjv_w;
        int32_t sjv_x;
        int32_t sjv_y;

        sjt_parent168 = &_parent->children;
        sjt_functionParam248 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent168, sjt_functionParam248, &sjv_child);
        sjt_parent169 = sjv_child;
        sjt_call89._refCount = 1;
        sjt_call89.w = (&sjv_innerrect)->w;
        sjt_call89.h = (&sjv_innerrect)->h;
        sjf_size(&sjt_call89);
        sjt_interfaceParam44 = &sjt_call89;
        sjt_parent169._vtbl->getsize(sjt_parent169._parent, sjt_interfaceParam44, &sjv_childsize);
        sjv_x = (&sjv_innerrect)->x;
        sjv_w = (&sjv_innerrect)->w;
        if (_parent->centerx.isvalid) {
            float ifValue13;
            float sjt_cast20;
            int32_t sjt_cast21;
            float_option sjt_getValue3;

            sjt_getValue3 = _parent->centerx;
            ifValue13 = sjt_getValue3.value;
            sjt_cast21 = (&sjv_innerrect)->w - (&sjv_childsize)->w;
            sjt_cast20 = (float)sjt_cast21 * ifValue13;
            sjv_x = (&sjv_innerrect)->x + (int32_t)sjt_cast20;
            sjv_w = (&sjv_childsize)->w;
        }

        sjv_y = (&sjv_innerrect)->y;
        sjv_h = (&sjv_innerrect)->h;
        if (_parent->centery.isvalid) {
            float ifValue14;
            float sjt_cast22;
            int32_t sjt_cast23;
            float_option sjt_getValue4;

            sjt_getValue4 = _parent->centery;
            ifValue14 = sjt_getValue4.value;
            sjt_cast23 = (&sjv_innerrect)->h - (&sjv_childsize)->h;
            sjt_cast22 = (float)sjt_cast23 * ifValue14;
            sjv_y = (&sjv_innerrect)->y + (int32_t)sjt_cast22;
            sjv_h = (&sjv_childsize)->h;
        }

        sjt_parent170 = sjv_child;
        sjt_call90._refCount = 1;
        sjt_call90.x = sjv_x;
        sjt_call90.y = sjv_y;
        sjt_call90.w = sjv_w;
        sjt_call90.h = sjv_h;
        sjf_rect(&sjt_call90);
        sjt_interfaceParam45 = &sjt_call90;
        sjt_parent170._vtbl->setrect(sjt_parent170._parent, sjt_interfaceParam45);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call89._refCount == 1) { sjf_size_destroy(&sjt_call89); }
;
        if (sjt_call90._refCount == 1) { sjf_rect_destroy(&sjt_call90); }
;
        if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
;
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
;
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

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent189 = 0;

    sjt_parent189 = data;
    sjf_string_nullterminate(sjt_parent189);
    debugout("%s\n", (char*)data->data.data);
}

void sjf_f32_asstring(float val, sjs_string* _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    *refcount = 1;
    snprintf((char*)sjv_data, 256, "%f", val);
    sjv_count = (int)strlen((char*)sjv_data);
    _return->_refCount = 1;
    _return->count = sjv_count;
    _return->data._refCount = 1;
    _return->data.datasize = sjv_count;
    _return->data.data = sjv_data;
    _return->data.isglobal = false;
    _return->data.count = sjv_count;
    sjf_array_char(&_return->data);
    _return->_isnullterminated = false;
    sjf_string(_return);
}

void sjf_f32_asstring_heap(float val, sjs_string** _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    *refcount = 1;
    snprintf((char*)sjv_data, 256, "%f", val);
    sjv_count = (int)strlen((char*)sjv_data);
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = sjv_count;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = sjv_count;
    (*_return)->data.data = sjv_data;
    (*_return)->data.isglobal = false;
    (*_return)->data.count = sjv_count;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
    sjf_string_heap((*_return));
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

    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_filllayout_firemouseevent(sjs_filllayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam56 = 0;
    sjs_mouseevent* sjt_parent47 = 0;

    sjt_parent47 = mouseevent;
    sjt_functionParam56 = &_parent->children;
    sjf_mouseevent_firechildren(sjt_parent47, sjt_functionParam56, _return);
}

void sjf_filllayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 109;
}

void sjf_filllayout_getrect(sjs_filllayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_filllayout_getrect_heap(sjs_filllayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_filllayout_getsize(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t i;
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
    sjt_functionParam43 = &_parent->margin;
    sjf_size_subtractmargin(sjt_parent30, sjt_functionParam43, &sjv_innersize);
    sjt_forStart8 = 0;
    sjt_forEnd8 = (&_parent->children)->count;
    i = sjt_forStart8;
    while (i < sjt_forEnd8) {
        sjs_size sjt_call7 = { -1 };
        sjs_size sjt_funcold1 = { -1 };
        int32_t sjt_functionParam44;
        sjs_size* sjt_functionParam45 = 0;
        sjs_size* sjt_interfaceParam4 = 0;
        sjs_array_heap_iface_element* sjt_parent31 = 0;
        sjs_size* sjt_parent32 = 0;
        sji_element sjt_parent33 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent31 = &_parent->children;
        sjt_functionParam44 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent31, sjt_functionParam44, &sjv_child);
        sjt_funcold1._refCount = 1;
        sjf_size_copy(&sjt_funcold1, &sjv_size);
        sjt_parent32 = &sjv_size;
        sjt_parent33 = sjv_child;
        sjt_interfaceParam4 = &sjv_innersize;
        sjt_parent33._vtbl->getsize(sjt_parent33._parent, sjt_interfaceParam4, &sjt_call7);
        sjt_functionParam45 = &sjt_call7;
        sjf_size_max(sjt_parent32, sjt_functionParam45, &sjt_funcold1);
        if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
        sjf_size_copy(&sjv_size, &sjt_funcold1);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call7._refCount == 1) { sjf_size_destroy(&sjt_call7); }
;
        if (sjt_funcold1._refCount == 1) { sjf_size_destroy(&sjt_funcold1); }
;
    }

    sjt_parent34 = &sjv_size;
    sjt_functionParam46 = &_parent->margin;
    sjf_size_addmargin(sjt_parent34, sjt_functionParam46, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_filllayout_getsize_heap(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t i;
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
    sjt_functionParam47 = &_parent->margin;
    sjf_size_subtractmargin(sjt_parent35, sjt_functionParam47, &sjv_innersize);
    sjt_forStart9 = 0;
    sjt_forEnd9 = (&_parent->children)->count;
    i = sjt_forStart9;
    while (i < sjt_forEnd9) {
        sjs_size sjt_call8 = { -1 };
        sjs_size sjt_funcold2 = { -1 };
        int32_t sjt_functionParam48;
        sjs_size* sjt_functionParam49 = 0;
        sjs_size* sjt_interfaceParam5 = 0;
        sjs_array_heap_iface_element* sjt_parent36 = 0;
        sjs_size* sjt_parent37 = 0;
        sji_element sjt_parent38 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent36 = &_parent->children;
        sjt_functionParam48 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent36, sjt_functionParam48, &sjv_child);
        sjt_funcold2._refCount = 1;
        sjf_size_copy(&sjt_funcold2, &sjv_size);
        sjt_parent37 = &sjv_size;
        sjt_parent38 = sjv_child;
        sjt_interfaceParam5 = &sjv_innersize;
        sjt_parent38._vtbl->getsize(sjt_parent38._parent, sjt_interfaceParam5, &sjt_call8);
        sjt_functionParam49 = &sjt_call8;
        sjf_size_max(sjt_parent37, sjt_functionParam49, &sjt_funcold2);
        if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
        sjf_size_copy(&sjv_size, &sjt_funcold2);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call8._refCount == 1) { sjf_size_destroy(&sjt_call8); }
;
        if (sjt_funcold2._refCount == 1) { sjf_size_destroy(&sjt_funcold2); }
;
    }

    sjt_parent39 = &sjv_size;
    sjt_functionParam50 = &_parent->margin;
    sjf_size_addmargin_heap(sjt_parent39, sjt_functionParam50, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_filllayout_heap(sjs_filllayout* _this) {
}

void sjf_filllayout_render(sjs_filllayout* _parent, sjs_scene2d* scene) {
    if ((_parent->effect._parent != 0)) {
        sji_effect ifValue5 = { 0 };
        cb_scene2d_void sjt_interfaceParam10;
        sjs_scene2d* sjt_interfaceParam9 = 0;
        sji_effect sjt_parent44 = { 0 };

        ifValue5 = _parent->effect;
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
    int32_t sjt_forEnd11;
    int32_t sjt_forStart11;

    sjt_forStart11 = 0;
    sjt_forEnd11 = (&_parent->children)->count;
    i = sjt_forStart11;
    while (i < sjt_forEnd11) {
        int32_t sjt_functionParam54;
        sjs_scene2d* sjt_interfaceParam11 = 0;
        sjs_array_heap_iface_element* sjt_parent45 = 0;
        sji_element sjt_parent46 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent45 = &_parent->children;
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
    sjs_margin* sjt_functionParam51 = 0;
    sjs_rect* sjt_parent40 = 0;
    sjs_rect sjv_innerrect = { -1 };

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
    sjf_rect_copy(&_parent->_rect, rect_);
    sjt_parent40 = &_parent->_rect;
    sjt_functionParam51 = &_parent->margin;
    sjf_rect_subtractmargin(sjt_parent40, sjt_functionParam51, &sjv_innerrect);
    if ((_parent->effect._parent != 0)) {
        sji_effect ifValue3 = { 0 };
        sjs_rect* sjt_interfaceParam6 = 0;
        cb_rect_void sjt_interfaceParam7;
        sji_effect sjt_parent41 = { 0 };

        ifValue3 = _parent->effect;
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
;
}

void sjf_filllayout_setrectinner(sjs_filllayout* _parent, sjs_rect* innerrect) {
    int32_t i;
    int32_t sjt_forEnd10;
    int32_t sjt_forStart10;

    sjt_forStart10 = 0;
    sjt_forEnd10 = (&_parent->children)->count;
    i = sjt_forStart10;
    while (i < sjt_forEnd10) {
        int32_t sjt_functionParam52;
        sjs_rect* sjt_interfaceParam8 = 0;
        sjs_array_heap_iface_element* sjt_parent42 = 0;
        sji_element sjt_parent43 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent42 = &_parent->children;
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
    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_flowlayout_firemouseevent(sjs_flowlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam176 = 0;
    sjs_mouseevent* sjt_parent135 = 0;

    sjt_parent135 = mouseevent;
    sjt_functionParam176 = &_parent->children;
    sjf_mouseevent_firechildren(sjt_parent135, sjt_functionParam176, _return);
}

void sjf_flowlayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 177;
}

void sjf_flowlayout_getrect(sjs_flowlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_flowlayout_getrect_heap(sjs_flowlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_flowlayout_getsize(sjs_flowlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    _return->w = maxsize->w;
    _return->h = maxsize->h;
    sjf_size(_return);
}

void sjf_flowlayout_getsize_heap(sjs_flowlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    (*_return)->w = maxsize->w;
    (*_return)->h = maxsize->h;
    sjf_size_heap((*_return));
}

void sjf_flowlayout_heap(sjs_flowlayout* _this) {
}

void sjf_flowlayout_render(sjs_flowlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd18;
    int32_t sjt_forStart18;

    sjt_forStart18 = 0;
    sjt_forEnd18 = (&_parent->children)->count;
    i = sjt_forStart18;
    while (i < sjt_forEnd18) {
        int32_t sjt_functionParam175;
        sjs_scene2d* sjt_interfaceParam41 = 0;
        sjs_array_heap_iface_element* sjt_parent133 = 0;
        sji_element sjt_parent134 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent133 = &_parent->children;
        sjt_functionParam175 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent133, sjt_functionParam175, &sjv_child);
        sjt_parent134 = sjv_child;
        sjt_interfaceParam41 = scene;
        sjt_parent134._vtbl->render(sjt_parent134._parent, sjt_interfaceParam41);
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
    int32_t sjt_forEnd17;
    int32_t sjt_forStart17;
    sjs_margin* sjt_functionParam165 = 0;
    sjs_rect* sjt_parent123 = 0;
    sjs_rect sjv_innerrect = { -1 };
    int32_t sjv_val1;
    int32_t sjv_val2;
    int32_t sjv_valmax;

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
    sjf_rect_copy(&_parent->_rect, rect_);
    sjt_parent123 = rect_;
    sjt_functionParam165 = &_parent->margin;
    sjf_rect_subtractmargin(sjt_parent123, sjt_functionParam165, &sjv_innerrect);
    sjv_val1 = 0;
    sjv_val2 = 0;
    sjv_valmax = 0;
    sjt_forStart17 = 0;
    sjt_forEnd17 = (&_parent->children)->count;
    i = sjt_forStart17;
    while (i < sjt_forEnd17) {
        int32_t sjt_functionParam166;
        sjs_array_heap_iface_element* sjt_parent124 = 0;
        sji_element sjv_child = { 0 };
        int32_t underscore7;

        sjt_parent124 = &_parent->children;
        sjt_functionParam166 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent124, sjt_functionParam166, &sjv_child);
        underscore7 = _parent->orientation;
        if (underscore7 == sjv_flowlayoutorientation_topbottom) {
            sjs_size sjt_call58 = { -1 };
            sjs_rect sjt_call59 = { -1 };
            int32_t sjt_funcold9;
            int32_t sjt_functionParam167;
            int32_t sjt_functionParam168;
            sjs_size* sjt_interfaceParam33 = 0;
            sjs_rect* sjt_interfaceParam34 = 0;
            sji_element sjt_parent125 = { 0 };
            sji_element sjt_parent126 = { 0 };
            sjs_size sjv_childsize = { -1 };

            sjt_parent125 = sjv_child;
            sjt_call58._refCount = 1;
            sjt_call58.w = (&sjv_innerrect)->w;
            sjt_call58.h = (&sjv_innerrect)->h;
            sjf_size(&sjt_call58);
            sjt_interfaceParam33 = &sjt_call58;
            sjt_parent125._vtbl->getsize(sjt_parent125._parent, sjt_interfaceParam33, &sjv_childsize);
            sjt_funcold9 = sjv_valmax;
            sjt_functionParam167 = sjv_valmax;
            sjt_functionParam168 = (&sjv_childsize)->w;
            sjf_i32_max(sjt_functionParam167, sjt_functionParam168, &sjt_funcold9);
            sjv_valmax = sjt_funcold9;
            if ((sjv_val1 + (&sjv_childsize)->h) > (&sjv_innerrect)->h) {
                sjv_val1 = 0;
                sjv_val2 = sjv_val2 + sjv_valmax;
                sjv_valmax = 0;
            }

            sjt_parent126 = sjv_child;
            sjt_call59._refCount = 1;
            sjt_call59.x = (&sjv_innerrect)->x + sjv_val2;
            sjt_call59.y = (&sjv_innerrect)->y + sjv_val1;
            sjt_call59.w = (&sjv_childsize)->w;
            sjt_call59.h = (&sjv_childsize)->h;
            sjf_rect(&sjt_call59);
            sjt_interfaceParam34 = &sjt_call59;
            sjt_parent126._vtbl->setrect(sjt_parent126._parent, sjt_interfaceParam34);
            sjv_val1 = sjv_val1 + (&sjv_childsize)->h;

            if (sjt_call58._refCount == 1) { sjf_size_destroy(&sjt_call58); }
;
            if (sjt_call59._refCount == 1) { sjf_rect_destroy(&sjt_call59); }
;
            if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
;
        } else {
            if (underscore7 == sjv_flowlayoutorientation_bottomtop) {
                sjs_size sjt_call60 = { -1 };
                sjs_rect sjt_call61 = { -1 };
                int32_t sjt_funcold10;
                int32_t sjt_functionParam169;
                int32_t sjt_functionParam170;
                sjs_size* sjt_interfaceParam35 = 0;
                sjs_rect* sjt_interfaceParam36 = 0;
                sji_element sjt_parent127 = { 0 };
                sji_element sjt_parent128 = { 0 };
                sjs_size sjv_childsize = { -1 };

                sjt_parent127 = sjv_child;
                sjt_call60._refCount = 1;
                sjt_call60.w = (&sjv_innerrect)->w;
                sjt_call60.h = (&sjv_innerrect)->h;
                sjf_size(&sjt_call60);
                sjt_interfaceParam35 = &sjt_call60;
                sjt_parent127._vtbl->getsize(sjt_parent127._parent, sjt_interfaceParam35, &sjv_childsize);
                sjt_funcold10 = sjv_valmax;
                sjt_functionParam169 = sjv_valmax;
                sjt_functionParam170 = (&sjv_childsize)->w;
                sjf_i32_max(sjt_functionParam169, sjt_functionParam170, &sjt_funcold10);
                sjv_valmax = sjt_funcold10;
                if ((sjv_val1 + (&sjv_childsize)->h) >= (&sjv_innerrect)->h) {
                    sjv_val1 = 0;
                    sjv_val2 = sjv_val2 + sjv_valmax;
                    sjv_valmax = 0;
                }

                sjt_parent128 = sjv_child;
                sjt_call61._refCount = 1;
                sjt_call61.x = (&sjv_innerrect)->x + sjv_val2;
                sjt_call61.y = (((&sjv_innerrect)->y + (&sjv_innerrect)->h) - sjv_val1) - (&sjv_childsize)->h;
                sjt_call61.w = (&sjv_childsize)->w;
                sjt_call61.h = (&sjv_childsize)->h;
                sjf_rect(&sjt_call61);
                sjt_interfaceParam36 = &sjt_call61;
                sjt_parent128._vtbl->setrect(sjt_parent128._parent, sjt_interfaceParam36);
                sjv_val1 = sjv_val1 + (&sjv_childsize)->h;

                if (sjt_call60._refCount == 1) { sjf_size_destroy(&sjt_call60); }
;
                if (sjt_call61._refCount == 1) { sjf_rect_destroy(&sjt_call61); }
;
                if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
;
            } else {
                if (underscore7 == sjv_flowlayoutorientation_leftright) {
                    sjs_size sjt_call62 = { -1 };
                    sjs_rect sjt_call63 = { -1 };
                    int32_t sjt_funcold11;
                    int32_t sjt_functionParam171;
                    int32_t sjt_functionParam172;
                    sjs_size* sjt_interfaceParam37 = 0;
                    sjs_rect* sjt_interfaceParam38 = 0;
                    sji_element sjt_parent129 = { 0 };
                    sji_element sjt_parent130 = { 0 };
                    sjs_size sjv_childsize = { -1 };

                    sjt_parent129 = sjv_child;
                    sjt_call62._refCount = 1;
                    sjt_call62.w = (&sjv_innerrect)->w;
                    sjt_call62.h = (&sjv_innerrect)->h;
                    sjf_size(&sjt_call62);
                    sjt_interfaceParam37 = &sjt_call62;
                    sjt_parent129._vtbl->getsize(sjt_parent129._parent, sjt_interfaceParam37, &sjv_childsize);
                    sjt_funcold11 = sjv_valmax;
                    sjt_functionParam171 = sjv_valmax;
                    sjt_functionParam172 = (&sjv_childsize)->h;
                    sjf_i32_max(sjt_functionParam171, sjt_functionParam172, &sjt_funcold11);
                    sjv_valmax = sjt_funcold11;
                    if ((sjv_val1 + (&sjv_childsize)->w) > (&sjv_innerrect)->w) {
                        sjv_val1 = 0;
                        sjv_val2 = sjv_val2 + sjv_valmax;
                        sjv_valmax = 0;
                    }

                    sjt_parent130 = sjv_child;
                    sjt_call63._refCount = 1;
                    sjt_call63.x = (&sjv_innerrect)->x + sjv_val1;
                    sjt_call63.y = (&sjv_innerrect)->y + sjv_val2;
                    sjt_call63.w = (&sjv_childsize)->w;
                    sjt_call63.h = (&sjv_childsize)->h;
                    sjf_rect(&sjt_call63);
                    sjt_interfaceParam38 = &sjt_call63;
                    sjt_parent130._vtbl->setrect(sjt_parent130._parent, sjt_interfaceParam38);
                    sjv_val1 = sjv_val1 + (&sjv_childsize)->w;

                    if (sjt_call62._refCount == 1) { sjf_size_destroy(&sjt_call62); }
;
                    if (sjt_call63._refCount == 1) { sjf_rect_destroy(&sjt_call63); }
;
                    if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
;
                } else {
                    if (underscore7 == sjv_flowlayoutorientation_rightleft) {
                        sjs_size sjt_call64 = { -1 };
                        sjs_rect sjt_call65 = { -1 };
                        int32_t sjt_funcold12;
                        int32_t sjt_functionParam173;
                        int32_t sjt_functionParam174;
                        sjs_size* sjt_interfaceParam39 = 0;
                        sjs_rect* sjt_interfaceParam40 = 0;
                        sji_element sjt_parent131 = { 0 };
                        sji_element sjt_parent132 = { 0 };
                        sjs_size sjv_childsize = { -1 };

                        sjt_parent131 = sjv_child;
                        sjt_call64._refCount = 1;
                        sjt_call64.w = (&sjv_innerrect)->w;
                        sjt_call64.h = (&sjv_innerrect)->h;
                        sjf_size(&sjt_call64);
                        sjt_interfaceParam39 = &sjt_call64;
                        sjt_parent131._vtbl->getsize(sjt_parent131._parent, sjt_interfaceParam39, &sjv_childsize);
                        sjt_funcold12 = sjv_valmax;
                        sjt_functionParam173 = sjv_valmax;
                        sjt_functionParam174 = (&sjv_childsize)->h;
                        sjf_i32_max(sjt_functionParam173, sjt_functionParam174, &sjt_funcold12);
                        sjv_valmax = sjt_funcold12;
                        if ((sjv_val1 + (&sjv_childsize)->w) > (&sjv_innerrect)->w) {
                            sjv_val1 = 0;
                            sjv_val2 = sjv_val2 + sjv_valmax;
                            sjv_valmax = 0;
                        }

                        sjt_parent132 = sjv_child;
                        sjt_call65._refCount = 1;
                        sjt_call65.x = (((&sjv_innerrect)->x + (&sjv_innerrect)->w) - sjv_val1) - (&sjv_childsize)->w;
                        sjt_call65.y = (&sjv_innerrect)->y + sjv_val2;
                        sjt_call65.w = (&sjv_childsize)->w;
                        sjt_call65.h = (&sjv_childsize)->h;
                        sjf_rect(&sjt_call65);
                        sjt_interfaceParam40 = &sjt_call65;
                        sjt_parent132._vtbl->setrect(sjt_parent132._parent, sjt_interfaceParam40);
                        sjv_val1 = sjv_val1 + (&sjv_childsize)->w;

                        if (sjt_call64._refCount == 1) { sjf_size_destroy(&sjt_call64); }
;
                        if (sjt_call65._refCount == 1) { sjf_rect_destroy(&sjt_call65); }
;
                        if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
;
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
;
}

void sjf_font(sjs_font* _this) {
    _this->atlas = texture_atlas_new( 512, 512, 3 );
    _this->font = texture_font_new_from_file(_this->atlas, _this->size, (char*)_this->src.data.data);
    if (_this->font == 0) {
        printf("texture_font_new_from_file Error\n");
    }   
    glGenTextures( 1, &_this->atlas->id );
    glBindTexture( GL_TEXTURE_2D, _this->atlas->id );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
    if (_this->src._refCount == 1) { sjf_string_destroy(&_this->src); }
;
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
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, (int)_this->atlas->width, (int)_this->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->atlas->data );
}

void sjf_font_load_heap(sjs_string* src, float size, sjs_font** _return) {
    sjs_fontkey* sjt_functionParam98 = 0;
    sjs_hash_fontkey_weak_font* sjt_parent67 = 0;
    sjs_font* sjv_h = 0;
    sjs_fontkey sjv_k = { -1 };
    sjs_font* sjv_w = 0;

    sjv_k._refCount = 1;
    sjv_k.src._refCount = 1;
    sjf_string_copy(&sjv_k.src, src);
    sjv_k.size = size;
    sjf_fontkey(&sjv_k);
    sjt_parent67 = &sjv_fonthash;
    sjt_functionParam98 = &sjv_k;
    sjf_hash_fontkey_weak_font_getat(sjt_parent67, sjt_functionParam98, &sjv_w);
    sjv_h = sjv_w;
    if (sjv_h != 0) {
        sjv_h->_refCount++;
    }

    if ((sjv_h != 0)) {
        sjs_font* ifValue9 = 0;

        ifValue9 = sjv_h;
        if (ifValue9 != 0) {
            ifValue9->_refCount++;
        }

        (*_return) = ifValue9;
        (*_return)->_refCount++;

        ifValue9->_refCount--;
        if (ifValue9->_refCount <= 0) {
            weakptr_release(ifValue9);
            sjf_font_destroy(ifValue9);
            free(ifValue9);
        }
    } else {
        sjs_font* sjt_functionParam100 = 0;
        sjs_fontkey* sjt_functionParam99 = 0;
        sjs_hash_fontkey_weak_font* sjt_parent68 = 0;
        sjs_font* sjv_result = 0;

        sjv_result = (sjs_font*)malloc(sizeof(sjs_font));
        sjv_result->_refCount = 1;
        sjv_result->src._refCount = 1;
        sjf_string_copy(&sjv_result->src, src);
        sjv_result->size = size;
        sjf_font_heap(sjv_result);
        sjt_parent68 = &sjv_fonthash;
        sjt_functionParam99 = &sjv_k;
        sjt_functionParam100 = sjv_result;
        delete_cb weakptrcb21 = { &sjt_functionParam100, weakptr_clear };
        if (sjt_functionParam100 != 0) { weakptr_cb_add(sjt_functionParam100, weakptrcb21); }
        sjf_hash_fontkey_weak_font_setat(sjt_parent68, sjt_functionParam99, sjt_functionParam100);
        (*_return) = sjv_result;
        (*_return)->_refCount++;

        delete_cb weakptrcb22 = { &sjt_functionParam100, weakptr_clear };
        if (sjt_functionParam100 != 0) { weakptr_cb_remove(sjt_functionParam100, weakptrcb22); }
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
    delete_cb weakptrcb23 = { &sjv_w, weakptr_clear };
    if (sjv_w != 0) { weakptr_cb_remove(sjv_w, weakptrcb23); }
    if (sjv_k._refCount == 1) { sjf_fontkey_destroy(&sjv_k); }
;
}

void sjf_fontkey(sjs_fontkey* _this) {
}

void sjf_fontkey_copy(sjs_fontkey* _this, sjs_fontkey* _from) {
    _this->src._refCount = 1;
    sjf_string_copy(&_this->src, &_from->src);
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

    sjt_parent2 = &_parent->src;
    sjf_string_hash(sjt_parent2, &sjt_capture1);
    sjt_functionParam10 = _parent->size;
    sjf_f32_hash(sjt_functionParam10, &sjt_capture2);
    (*_return) = sjt_capture1 ^ sjt_capture2;
}

void sjf_fontkey_heap(sjs_fontkey* _this) {
}

void sjf_fontkey_isequal(sjs_fontkey* _parent, sjs_fontkey* x, bool* _return) {
    bool sjt_capture3;
    sjs_string* sjt_functionParam11 = 0;
    sjs_string* sjt_parent3 = 0;

    sjt_parent3 = &_parent->src;
    sjt_functionParam11 = &x->src;
    sjf_string_isequal(sjt_parent3, sjt_functionParam11, &sjt_capture3);
    (*_return) = sjt_capture3 && (_parent->size == x->size);
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
    bool result12;
    sjs_rect sjt_call100 = { -1 };
    sjs_string sjt_call101 = { -1 };
    int32_t sjt_capture20;
    bool sjt_capture21;
    int32_t sjt_capture22;
    int32_t sjt_capture23;
    int32_t sjt_functionParam305;
    sjs_rect* sjt_functionParam306 = 0;
    int32_t sjt_functionParam308;
    sjs_rect* sjt_parent208 = 0;
    sjs_list_rect* sjt_parent211 = 0;
    sjs_list_rect* sjt_parent212 = 0;
    sjs_list_rect* sjt_parent214 = 0;
    sjs_list_rect* sjt_parent215 = 0;
    sjs_list_rect* sjt_parent216 = 0;
    sjs_rect sjv_newrect = { -1 };
    sjs_rect sjv_oldrect = { -1 };

    sjv_oldrect._refCount = 1;
    sjv_oldrect.x = rect->x;
    sjv_oldrect.y = scenerect->h - (rect->y + rect->h);
    sjv_oldrect.w = rect->w;
    sjv_oldrect.h = rect->h;
    sjf_rect(&sjv_oldrect);
    sjt_parent211 = &sjv_glviewports;
    sjt_parent212 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent212, &sjt_capture20);
    sjt_functionParam305 = sjt_capture20 - 1;
    sjf_list_rect_getat(sjt_parent211, sjt_functionParam305, &sjt_call100);
    sjt_parent208 = &sjt_call100;
    sjt_functionParam306 = &sjv_oldrect;
    sjf_rect_isequal(sjt_parent208, sjt_functionParam306, &sjt_capture21);
    result12 = !sjt_capture21;
    if (result12) {
        sjs_string* sjt_functionParam307 = 0;

        sjt_call101._refCount = 1;
        sjt_call101.count = 30;
        sjt_call101.data._refCount = 1;
        sjt_call101.data.datasize = 30;
        sjt_call101.data.data = (void*)sjg_string31;
        sjt_call101.data.isglobal = true;
        sjt_call101.data.count = 30;
        sjf_array_char(&sjt_call101.data);
        sjt_call101._isnullterminated = false;
        sjf_string(&sjt_call101);
        sjt_functionParam307 = &sjt_call101;
        sjf_halt(sjt_functionParam307);
    }

    sjt_parent214 = &sjv_glviewports;
    sjt_parent215 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent215, &sjt_capture22);
    sjt_functionParam308 = sjt_capture22 - 1;
    sjf_list_rect_removeat(sjt_parent214, sjt_functionParam308);
    sjt_parent216 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent216, &sjt_capture23);
    if (sjt_capture23 > 0) {
        int32_t sjt_capture24;
        int32_t sjt_functionParam309;
        sjs_list_rect* sjt_parent217 = 0;
        sjs_list_rect* sjt_parent218 = 0;

        sjt_parent217 = &sjv_glviewports;
        sjt_parent218 = &sjv_glviewports;
        sjf_list_rect_getcount(sjt_parent218, &sjt_capture24);
        sjt_functionParam309 = sjt_capture24 - 1;
        sjf_list_rect_getat(sjt_parent217, sjt_functionParam309, &sjv_newrect);
    } else {
        sjv_newrect._refCount = 1;
        sjv_newrect.x = 0;
        sjv_newrect.y = 0;
        sjv_newrect.w = 0;
        sjv_newrect.h = 0;
        sjf_rect(&sjv_newrect);
    }

    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjt_call100._refCount == 1) { sjf_rect_destroy(&sjt_call100); }
;
    if (sjt_call101._refCount == 1) { sjf_string_destroy(&sjt_call101); }
;
    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
;
    if (sjv_oldrect._refCount == 1) { sjf_rect_destroy(&sjv_oldrect); }
;
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect* sjt_functionParam299 = 0;
    sjs_list_rect* sjt_parent203 = 0;
    sjs_rect sjv_newrect = { -1 };

    sjv_newrect._refCount = 1;
    sjv_newrect.x = rect->x;
    sjv_newrect.y = scenerect->h - (rect->y + rect->h);
    sjv_newrect.w = rect->w;
    sjv_newrect.h = rect->h;
    sjf_rect(&sjv_newrect);
    sjt_parent203 = &sjv_glviewports;
    sjt_functionParam299 = &sjv_newrect;
    sjf_list_rect_add(sjt_parent203, sjt_functionParam299);
    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
;
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

    sjt_parent27 = mouseevent;
    sjt_functionParam38 = &_parent->children;
    sjf_mouseevent_firechildren(sjt_parent27, sjt_functionParam38, _return);
}

void sjf_gridlayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 88;
}

void sjf_gridlayout_getrect(sjs_gridlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_gridlayout_getrect_heap(sjs_gridlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_gridlayout_getsize(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    _return->w = maxsize->w;
    _return->h = maxsize->h;
    sjf_size(_return);
}

void sjf_gridlayout_getsize_heap(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    (*_return)->w = maxsize->w;
    (*_return)->h = maxsize->h;
    sjf_size_heap((*_return));
}

void sjf_gridlayout_heap(sjs_gridlayout* _this) {
}

void sjf_gridlayout_render(sjs_gridlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;

    sjt_forStart6 = 0;
    sjt_forEnd6 = (&_parent->children)->count;
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        int32_t sjt_functionParam36;
        sjs_scene2d* sjt_interfaceParam2 = 0;
        sjs_array_heap_iface_element* sjt_parent23 = 0;
        sji_element sjt_parent24 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent23 = &_parent->children;
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
    sjf_rect_copy(&_parent->_rect, rect_);
    sjt_parent4 = rect_;
    sjt_functionParam12 = &_parent->margin;
    sjf_rect_subtractmargin(sjt_parent4, sjt_functionParam12, &sjv_innerrect);
    sjv_rowfixed = 0;
    sjv_rowstars = 0;
    sjt_forStart1 = 0;
    sjt_forEnd1 = (&_parent->rows)->count;
    r = sjt_forStart1;
    while (r < sjt_forEnd1) {
        int32_t sjt_functionParam13;
        sjs_array_gridunit* sjt_parent5 = 0;
        sjs_gridunit sjv_row = { -1 };

        sjt_parent5 = &_parent->rows;
        sjt_functionParam13 = r;
        sjf_array_gridunit_getat(sjt_parent5, sjt_functionParam13, &sjv_row);
        if ((&sjv_row)->unittype == sjv_gridunittype_star) {
            sjv_rowstars = sjv_rowstars + (&sjv_row)->amount;
        } else {
            sjv_rowfixed = sjv_rowfixed + (&sjv_row)->amount;
        }

        r++;

        if (sjv_row._refCount == 1) { sjf_gridunit_destroy(&sjv_row); }
;
    }

    if (sjv_rowstars > 0) {
        sjv_rowstarunit = ((&sjv_innerrect)->h - sjv_rowfixed) / sjv_rowstars;
    } else {
        sjv_rowstarunit = 0;
    }

    if (sjv_rowstars > 0) {
        sjv_rowstarremainder = ((&sjv_innerrect)->h - sjv_rowfixed) % sjv_rowstars;
    } else {
        sjv_rowstarremainder = 0;
    }

    sjv_ypos._refCount = 1;
    sjv_ypos.datasize = (&_parent->rows)->count + 1;
    sjv_ypos.data = 0;
    sjv_ypos.isglobal = false;
    sjv_ypos.count = 0;
    sjf_array_i32(&sjv_ypos);
    sjv_y = (&sjv_innerrect)->y;
    sjt_parent6 = &sjv_ypos;
    sjt_functionParam14 = 0;
    sjt_functionParam15 = sjv_y;
    sjf_array_i32_initat(sjt_parent6, sjt_functionParam14, sjt_functionParam15);
    sjt_forStart2 = 0;
    sjt_forEnd2 = (&_parent->rows)->count;
    r = sjt_forStart2;
    while (r < sjt_forEnd2) {
        int32_t sjt_functionParam16;
        int32_t sjt_functionParam19;
        int32_t sjt_functionParam20;
        sjs_array_gridunit* sjt_parent7 = 0;
        sjs_array_i32* sjt_parent8 = 0;
        sjs_gridunit sjv_row = { -1 };

        sjt_parent7 = &_parent->rows;
        sjt_functionParam16 = r;
        sjf_array_gridunit_getat(sjt_parent7, sjt_functionParam16, &sjv_row);
        if ((&sjv_row)->unittype == sjv_gridunittype_star) {
            int32_t sjt_capture4;
            int32_t sjt_functionParam17;
            int32_t sjt_functionParam18;

            sjv_y = sjv_y + (sjv_rowstarunit * (&sjv_row)->amount);
            sjt_functionParam17 = 0;
            sjt_functionParam18 = sjv_rowstarremainder;
            sjf_i32_max(sjt_functionParam17, sjt_functionParam18, &sjt_capture4);
            sjv_y = sjv_y + sjt_capture4;
            sjv_rowstarremainder = sjv_rowstarremainder - (&sjv_row)->amount;
        } else {
            sjv_y = sjv_y + (&sjv_row)->amount;
        }

        sjt_parent8 = &sjv_ypos;
        sjt_functionParam19 = r + 1;
        sjt_functionParam20 = sjv_y;
        sjf_array_i32_initat(sjt_parent8, sjt_functionParam19, sjt_functionParam20);
        r++;

        if (sjv_row._refCount == 1) { sjf_gridunit_destroy(&sjv_row); }
;
    }

    sjv_colfixed = 0;
    sjv_colstars = 0;
    sjt_forStart3 = 0;
    sjt_forEnd3 = (&_parent->cols)->count;
    c = sjt_forStart3;
    while (c < sjt_forEnd3) {
        int32_t sjt_functionParam21;
        sjs_array_gridunit* sjt_parent9 = 0;
        sjs_gridunit sjv_col = { -1 };

        sjt_parent9 = &_parent->cols;
        sjt_functionParam21 = c;
        sjf_array_gridunit_getat(sjt_parent9, sjt_functionParam21, &sjv_col);
        if ((&sjv_col)->unittype == sjv_gridunittype_star) {
            sjv_colstars = sjv_colstars + (&sjv_col)->amount;
        } else {
            sjv_colfixed = sjv_colfixed + (&sjv_col)->amount;
        }

        c++;

        if (sjv_col._refCount == 1) { sjf_gridunit_destroy(&sjv_col); }
;
    }

    if (sjv_colstars > 0) {
        sjv_colstarunit = ((&sjv_innerrect)->w - sjv_colfixed) / sjv_colstars;
    } else {
        sjv_colstarunit = 0;
    }

    if (sjv_colstars > 0) {
        sjv_colstarremainder = ((&sjv_innerrect)->w - sjv_colfixed) % sjv_colstars;
    } else {
        sjv_colstarremainder = 0;
    }

    sjv_xpos._refCount = 1;
    sjv_xpos.datasize = (&_parent->cols)->count + 1;
    sjv_xpos.data = 0;
    sjv_xpos.isglobal = false;
    sjv_xpos.count = 0;
    sjf_array_i32(&sjv_xpos);
    sjv_x = (&sjv_innerrect)->x;
    sjt_parent10 = &sjv_xpos;
    sjt_functionParam22 = 0;
    sjt_functionParam23 = sjv_x;
    sjf_array_i32_initat(sjt_parent10, sjt_functionParam22, sjt_functionParam23);
    sjt_forStart4 = 0;
    sjt_forEnd4 = (&_parent->cols)->count;
    c = sjt_forStart4;
    while (c < sjt_forEnd4) {
        int32_t sjt_functionParam24;
        int32_t sjt_functionParam27;
        int32_t sjt_functionParam28;
        sjs_array_gridunit* sjt_parent11 = 0;
        sjs_array_i32* sjt_parent12 = 0;
        sjs_gridunit sjv_col = { -1 };

        sjt_parent11 = &_parent->cols;
        sjt_functionParam24 = c;
        sjf_array_gridunit_getat(sjt_parent11, sjt_functionParam24, &sjv_col);
        if ((&sjv_col)->unittype == sjv_gridunittype_star) {
            int32_t sjt_capture5;
            int32_t sjt_functionParam25;
            int32_t sjt_functionParam26;

            sjv_x = sjv_x + (sjv_colstarunit * (&sjv_col)->amount);
            sjt_functionParam25 = 0;
            sjt_functionParam26 = sjv_colstarremainder;
            sjf_i32_max(sjt_functionParam25, sjt_functionParam26, &sjt_capture5);
            sjv_x = sjv_x + sjt_capture5;
            sjv_colstarremainder = sjv_colstarremainder - (&sjv_col)->amount;
        } else {
            sjv_x = sjv_x + (&sjv_col)->amount;
        }

        sjt_parent12 = &sjv_xpos;
        sjt_functionParam27 = c + 1;
        sjt_functionParam28 = sjv_x;
        sjf_array_i32_initat(sjt_parent12, sjt_functionParam27, sjt_functionParam28);
        c++;

        if (sjv_col._refCount == 1) { sjf_gridunit_destroy(&sjv_col); }
;
    }

    sjv_rnext = 0;
    sjv_cnext = 0;
    sjt_forStart5 = 0;
    sjt_forEnd5 = (&_parent->children)->count;
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

        sjv_r = 0;
        sjv_c = 0;
        sjt_parent13 = &_parent->children;
        sjt_functionParam29 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent13, sjt_functionParam29, &sjv_child);
        sjt_cast3 = sjv_child;
        sjt_cast3._vtbl->asinterface(sjt_cast3._parent, sji_gridchild_typeId, (sjs_interface*)&sjv_gridchild);
        if (sjv_gridchild._parent != 0) {
            sjv_gridchild._parent->_refCount++;
        }

        if ((sjv_gridchild._parent != 0)) {
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
            sjv_r = sjv_rnext;
            sjv_c = sjv_cnext;
            sjv_cnext = sjv_cnext + 1;
            if (sjv_cnext >= (&_parent->cols)->count) {
                sjv_cnext = 0;
                sjv_rnext = sjv_rnext + 1;
                if (sjv_rnext >= (&_parent->rows)->count) {
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
        sjt_functionParam32 = sjv_c + 1;
        sjf_array_i32_getat(sjt_parent19, sjt_functionParam32, &sjt_capture6);
        sjt_parent20 = &sjv_xpos;
        sjt_functionParam33 = sjv_c;
        sjf_array_i32_getat(sjt_parent20, sjt_functionParam33, &sjt_capture7);
        sjt_call4.w = sjt_capture6 - sjt_capture7;
        sjt_parent21 = &sjv_ypos;
        sjt_functionParam34 = sjv_r + 1;
        sjf_array_i32_getat(sjt_parent21, sjt_functionParam34, &sjt_capture8);
        sjt_parent22 = &sjv_ypos;
        sjt_functionParam35 = sjv_r;
        sjf_array_i32_getat(sjt_parent22, sjt_functionParam35, &sjt_capture9);
        sjt_call4.h = sjt_capture8 - sjt_capture9;
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
    _this->amount = _from->amount;
    _this->unittype = _from->unittype;
}

void sjf_gridunit_destroy(sjs_gridunit* _this) {
}

void sjf_gridunit_heap(sjs_gridunit* _this) {
}

void sjf_halt(sjs_string* reason) {
    sjs_string* sjt_parent213 = 0;

    sjt_parent213 = reason;
    sjf_string_nullterminate(sjt_parent213);
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
            if (t == val) {
                kh_del(fontkey_weak_font_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_fontkey_weak_font_copy(sjs_hash_fontkey_weak_font* _this, sjs_hash_fontkey_weak_font* _from) {
    _this->_hash = _from->_hash;
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_this->_hash;
    p->refcount++;
}

void sjf_hash_fontkey_weak_font_destroy(sjs_hash_fontkey_weak_font* _this) {
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_this->_hash;
    p->refcount--;
    if (p->refcount == 0) {
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
delete_cb weakptrcb17 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb17); }
return;
    }
    (*_return) = kh_val(p, k);
delete_cb weakptrcb18 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb18); }
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
    delete_cb weakptrcb19 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_remove(kh_val(p, k), weakptrcb19); }
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
delete_cb weakptrcb20 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_add(kh_val(p, k), weakptrcb20); }
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
            if (t._parent == val._parent) {
                kh_del(string_weak_iface_element_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_string_weak_iface_element_copy(sjs_hash_string_weak_iface_element* _this, sjs_hash_string_weak_iface_element* _from) {
    _this->_hash = _from->_hash;
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_this->_hash;
    p->refcount++;
}

void sjf_hash_string_weak_iface_element_destroy(sjs_hash_string_weak_iface_element* _this) {
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_this->_hash;
    p->refcount--;
    if (p->refcount == 0) {
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
    delete_cb weakptrcb14 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_remove(kh_val(p, k)._parent, weakptrcb14); }
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
delete_cb weakptrcb15 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_add(kh_val(p, k)._parent, weakptrcb15); }
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
            if (t._parent == val._parent) {
                kh_del(string_weak_iface_model_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_string_weak_iface_model_copy(sjs_hash_string_weak_iface_model* _this, sjs_hash_string_weak_iface_model* _from) {
    _this->_hash = _from->_hash;
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_this->_hash;
    p->refcount++;
}

void sjf_hash_string_weak_iface_model_destroy(sjs_hash_string_weak_iface_model* _this) {
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_this->_hash;
    p->refcount--;
    if (p->refcount == 0) {
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

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
    #if false
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(type_bool_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(type_bool_hash_type, p, k);
    }
    #endif
}

void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val) {
    #if false
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            bool t = kh_value(p, k);
            if (t == val) {
                kh_del(type_bool_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from) {
    _this->_hash = _from->_hash;
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
    p->refcount--;
    if (p->refcount == 0) {
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k), cb);
                #else
                ;
                #endif
            }
        }
        kh_destroy(type_bool_hash_type, _this->_hash);
    }
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    if (a < b) {
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
    sjf_array_heap_iface_animation_copy(&_this->array, &_from->array);
}

void sjf_list_heap_iface_animation_destroy(sjs_list_heap_iface_animation* _this) {
    if (_this->array._refCount == 1) { sjf_array_heap_iface_animation_destroy(&_this->array); }
;
}

void sjf_list_heap_iface_animation_getat_heap(sjs_list_heap_iface_animation* _parent, int32_t index, sji_animation* _return) {
    int32_t sjt_functionParam264;
    sjs_array_heap_iface_animation* sjt_parent182 = 0;

    sjt_parent182 = &_parent->array;
    sjt_functionParam264 = index;
    sjf_array_heap_iface_animation_getat_heap(sjt_parent182, sjt_functionParam264, _return);
}

void sjf_list_heap_iface_animation_getcount(sjs_list_heap_iface_animation* _parent, int32_t* _return) {
    (*_return) = (&_parent->array)->count;
}

void sjf_list_heap_iface_animation_heap(sjs_list_heap_iface_animation* _this) {
}

void sjf_list_heap_iface_animation_removeat(sjs_list_heap_iface_animation* _parent, int32_t index) {
    if (index < 0 || index >= _parent->array.count) {
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
    }
    sji_animation* p = (sji_animation*)_parent->array.data;
    if (p[index]._parent != 0) {
    p[index]._parent->_refCount--;
    if (p[index]._parent->_refCount <= 0) {
        p[index]._vtbl->destroy(p[index]._parent);
        free(p[index]._parent);
    }
}
;
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
    if (_this->array._refCount == 1) { sjf_array_heap_iface_model_destroy(&_this->array); }
;
}

void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this) {
}

void sjf_list_rect(sjs_list_rect* _this) {
}

void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item) {
    sjs_array_rect sjt_funcold20 = { -1 };
    int32_t sjt_functionParam297;
    sjs_rect* sjt_functionParam298 = 0;
    sjs_array_rect* sjt_parent202 = 0;

    if ((&_parent->array)->count >= (&_parent->array)->datasize) {
        int32_t sjt_functionParam294;
        int32_t sjt_functionParam295;
        int32_t sjt_functionParam296;
        sjs_array_rect* sjt_parent201 = 0;

        sjt_funcold20._refCount = 1;
        sjf_array_rect_copy(&sjt_funcold20, &_parent->array);
        sjt_parent201 = &_parent->array;
        sjt_functionParam295 = 10;
        sjt_functionParam296 = (&_parent->array)->datasize * 2;
        sjf_i32_max(sjt_functionParam295, sjt_functionParam296, &sjt_functionParam294);
        sjf_array_rect_grow(sjt_parent201, sjt_functionParam294, &sjt_funcold20);
        if (_parent->array._refCount == 1) { sjf_array_rect_destroy(&_parent->array); }
;
        sjf_array_rect_copy(&_parent->array, &sjt_funcold20);
    }

    sjt_parent202 = &_parent->array;
    sjt_functionParam297 = (&_parent->array)->count;
    sjt_functionParam298 = item;
    sjf_array_rect_initat(sjt_parent202, sjt_functionParam297, sjt_functionParam298);

    if (sjt_funcold20._refCount == 1) { sjf_array_rect_destroy(&sjt_funcold20); }
;
}

void sjf_list_rect_copy(sjs_list_rect* _this, sjs_list_rect* _from) {
    _this->array._refCount = 1;
    sjf_array_rect_copy(&_this->array, &_from->array);
}

void sjf_list_rect_destroy(sjs_list_rect* _this) {
    if (_this->array._refCount == 1) { sjf_array_rect_destroy(&_this->array); }
;
}

void sjf_list_rect_getat(sjs_list_rect* _parent, int32_t index, sjs_rect* _return) {
    int32_t sjt_functionParam303;
    sjs_array_rect* sjt_parent209 = 0;

    sjt_parent209 = &_parent->array;
    sjt_functionParam303 = index;
    sjf_array_rect_getat(sjt_parent209, sjt_functionParam303, _return);
}

void sjf_list_rect_getat_heap(sjs_list_rect* _parent, int32_t index, sjs_rect** _return) {
    int32_t sjt_functionParam304;
    sjs_array_rect* sjt_parent210 = 0;

    sjt_parent210 = &_parent->array;
    sjt_functionParam304 = index;
    sjf_array_rect_getat_heap(sjt_parent210, sjt_functionParam304, _return);
}

void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return) {
    (*_return) = (&_parent->array)->count;
}

void sjf_list_rect_heap(sjs_list_rect* _this) {
}

void sjf_list_rect_removeat(sjs_list_rect* _parent, int32_t index) {
    if (index < 0 || index >= _parent->array.count) {
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
    }
    sjs_rect* p = (sjs_rect*)_parent->array.data;
    ;
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
    if (_this->array._refCount == 1) { sjf_array_u32_destroy(&_this->array); }
;
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
    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_listlayout_firemouseevent(sjs_listlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam150 = 0;
    sjs_mouseevent* sjt_parent117 = 0;

    sjt_parent117 = mouseevent;
    sjt_functionParam150 = &_parent->children;
    sjf_mouseevent_firechildren(sjt_parent117, sjt_functionParam150, _return);
}

void sjf_listlayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 171;
}

void sjf_listlayout_getrect(sjs_listlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_listlayout_getrect_heap(sjs_listlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_listlayout_getsize(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    _return->w = maxsize->w;
    _return->h = maxsize->h;
    sjf_size(_return);
}

void sjf_listlayout_getsize_heap(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    (*_return)->w = maxsize->w;
    (*_return)->h = maxsize->h;
    sjf_size_heap((*_return));
}

void sjf_listlayout_heap(sjs_listlayout* _this) {
}

void sjf_listlayout_render(sjs_listlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd16;
    int32_t sjt_forStart16;

    sjt_forStart16 = 0;
    sjt_forEnd16 = (&_parent->children)->count;
    i = sjt_forStart16;
    while (i < sjt_forEnd16) {
        int32_t sjt_functionParam149;
        sjs_scene2d* sjt_interfaceParam32 = 0;
        sjs_array_heap_iface_element* sjt_parent115 = 0;
        sji_element sjt_parent116 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent115 = &_parent->children;
        sjt_functionParam149 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent115, sjt_functionParam149, &sjv_child);
        sjt_parent116 = sjv_child;
        sjt_interfaceParam32 = scene;
        sjt_parent116._vtbl->render(sjt_parent116._parent, sjt_interfaceParam32);
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
    int32_t sjt_forEnd15;
    int32_t sjt_forStart15;
    sjs_margin* sjt_functionParam147 = 0;
    sjs_rect* sjt_parent105 = 0;
    sjs_rect sjv_innerrect = { -1 };
    int32_t sjv_val;

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
    sjf_rect_copy(&_parent->_rect, rect_);
    sjt_parent105 = rect_;
    sjt_functionParam147 = &_parent->margin;
    sjf_rect_subtractmargin(sjt_parent105, sjt_functionParam147, &sjv_innerrect);
    sjv_val = 0;
    sjt_forStart15 = 0;
    sjt_forEnd15 = (&_parent->children)->count;
    i = sjt_forStart15;
    while (i < sjt_forEnd15) {
        int32_t sjt_functionParam148;
        sjs_array_heap_iface_element* sjt_parent106 = 0;
        sji_element sjv_child = { 0 };
        int32_t underscore5;

        sjt_parent106 = &_parent->children;
        sjt_functionParam148 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent106, sjt_functionParam148, &sjv_child);
        underscore5 = _parent->orientation;
        if (underscore5 == sjv_listlayoutorientation_topbottom) {
            sjs_size sjt_call45 = { -1 };
            sjs_rect sjt_call46 = { -1 };
            sjs_size* sjt_interfaceParam24 = 0;
            sjs_rect* sjt_interfaceParam25 = 0;
            sji_element sjt_parent107 = { 0 };
            sji_element sjt_parent108 = { 0 };
            sjs_size sjv_childsize = { -1 };

            sjt_parent107 = sjv_child;
            sjt_call45._refCount = 1;
            sjt_call45.w = (&sjv_innerrect)->w;
            sjt_call45.h = (&sjv_innerrect)->h - sjv_val;
            sjf_size(&sjt_call45);
            sjt_interfaceParam24 = &sjt_call45;
            sjt_parent107._vtbl->getsize(sjt_parent107._parent, sjt_interfaceParam24, &sjv_childsize);
            sjt_parent108 = sjv_child;
            sjt_call46._refCount = 1;
            sjt_call46.x = (&sjv_innerrect)->x;
            sjt_call46.y = (&sjv_innerrect)->y + sjv_val;
            sjt_call46.w = (&sjv_innerrect)->w;
            sjt_call46.h = (&sjv_childsize)->h;
            sjf_rect(&sjt_call46);
            sjt_interfaceParam25 = &sjt_call46;
            sjt_parent108._vtbl->setrect(sjt_parent108._parent, sjt_interfaceParam25);
            sjv_val = sjv_val + (&sjv_childsize)->h;

            if (sjt_call45._refCount == 1) { sjf_size_destroy(&sjt_call45); }
;
            if (sjt_call46._refCount == 1) { sjf_rect_destroy(&sjt_call46); }
;
            if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
;
        } else {
            if (underscore5 == sjv_listlayoutorientation_bottomtop) {
                sjs_size sjt_call47 = { -1 };
                sjs_rect sjt_call48 = { -1 };
                sjs_size* sjt_interfaceParam26 = 0;
                sjs_rect* sjt_interfaceParam27 = 0;
                sji_element sjt_parent109 = { 0 };
                sji_element sjt_parent110 = { 0 };
                sjs_size sjv_childsize = { -1 };

                sjt_parent109 = sjv_child;
                sjt_call47._refCount = 1;
                sjt_call47.w = (&sjv_innerrect)->w;
                sjt_call47.h = (&sjv_innerrect)->h - sjv_val;
                sjf_size(&sjt_call47);
                sjt_interfaceParam26 = &sjt_call47;
                sjt_parent109._vtbl->getsize(sjt_parent109._parent, sjt_interfaceParam26, &sjv_childsize);
                sjt_parent110 = sjv_child;
                sjt_call48._refCount = 1;
                sjt_call48.x = (&sjv_innerrect)->x;
                sjt_call48.y = (((&sjv_innerrect)->y + (&sjv_innerrect)->h) - sjv_val) - (&sjv_childsize)->h;
                sjt_call48.w = (&sjv_innerrect)->w;
                sjt_call48.h = (&sjv_childsize)->h;
                sjf_rect(&sjt_call48);
                sjt_interfaceParam27 = &sjt_call48;
                sjt_parent110._vtbl->setrect(sjt_parent110._parent, sjt_interfaceParam27);
                sjv_val = sjv_val + (&sjv_childsize)->h;

                if (sjt_call47._refCount == 1) { sjf_size_destroy(&sjt_call47); }
;
                if (sjt_call48._refCount == 1) { sjf_rect_destroy(&sjt_call48); }
;
                if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
;
            } else {
                if (underscore5 == sjv_listlayoutorientation_leftright) {
                    sjs_size sjt_call49 = { -1 };
                    sjs_rect sjt_call50 = { -1 };
                    sjs_size* sjt_interfaceParam28 = 0;
                    sjs_rect* sjt_interfaceParam29 = 0;
                    sji_element sjt_parent111 = { 0 };
                    sji_element sjt_parent112 = { 0 };
                    sjs_size sjv_childsize = { -1 };

                    sjt_parent111 = sjv_child;
                    sjt_call49._refCount = 1;
                    sjt_call49.w = (&sjv_innerrect)->w - sjv_val;
                    sjt_call49.h = (&sjv_innerrect)->h;
                    sjf_size(&sjt_call49);
                    sjt_interfaceParam28 = &sjt_call49;
                    sjt_parent111._vtbl->getsize(sjt_parent111._parent, sjt_interfaceParam28, &sjv_childsize);
                    sjt_parent112 = sjv_child;
                    sjt_call50._refCount = 1;
                    sjt_call50.x = (&sjv_innerrect)->x + sjv_val;
                    sjt_call50.y = (&sjv_innerrect)->y;
                    sjt_call50.w = (&sjv_childsize)->w;
                    sjt_call50.h = (&sjv_innerrect)->h;
                    sjf_rect(&sjt_call50);
                    sjt_interfaceParam29 = &sjt_call50;
                    sjt_parent112._vtbl->setrect(sjt_parent112._parent, sjt_interfaceParam29);
                    sjv_val = sjv_val + (&sjv_childsize)->w;

                    if (sjt_call49._refCount == 1) { sjf_size_destroy(&sjt_call49); }
;
                    if (sjt_call50._refCount == 1) { sjf_rect_destroy(&sjt_call50); }
;
                    if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
;
                } else {
                    if (underscore5 == sjv_listlayoutorientation_rightleft) {
                        sjs_size sjt_call51 = { -1 };
                        sjs_rect sjt_call52 = { -1 };
                        sjs_size* sjt_interfaceParam30 = 0;
                        sjs_rect* sjt_interfaceParam31 = 0;
                        sji_element sjt_parent113 = { 0 };
                        sji_element sjt_parent114 = { 0 };
                        sjs_size sjv_childsize = { -1 };

                        sjt_parent113 = sjv_child;
                        sjt_call51._refCount = 1;
                        sjt_call51.w = (&sjv_innerrect)->w - sjv_val;
                        sjt_call51.h = (&sjv_innerrect)->h;
                        sjf_size(&sjt_call51);
                        sjt_interfaceParam30 = &sjt_call51;
                        sjt_parent113._vtbl->getsize(sjt_parent113._parent, sjt_interfaceParam30, &sjv_childsize);
                        sjt_parent114 = sjv_child;
                        sjt_call52._refCount = 1;
                        sjt_call52.x = (((&sjv_innerrect)->x + (&sjv_innerrect)->w) - sjv_val) - (&sjv_childsize)->w;
                        sjt_call52.y = (&sjv_innerrect)->y;
                        sjt_call52.w = (&sjv_childsize)->w;
                        sjt_call52.h = (&sjv_innerrect)->h;
                        sjf_rect(&sjt_call52);
                        sjt_interfaceParam31 = &sjt_call52;
                        sjt_parent114._vtbl->setrect(sjt_parent114._parent, sjt_interfaceParam31);
                        sjv_val = sjv_val + (&sjv_childsize)->w;

                        if (sjt_call51._refCount == 1) { sjf_size_destroy(&sjt_call51); }
;
                        if (sjt_call52._refCount == 1) { sjf_rect_destroy(&sjt_call52); }
;
                        if (sjv_childsize._refCount == 1) { sjf_size_destroy(&sjv_childsize); }
;
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
;
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
    _this->minlevel = _from->minlevel;
    sjs_hash_type_bool* copyoption1 = (_from->traceincludes._refCount != -1 ? &_from->traceincludes : 0);
    if (copyoption1 != 0) {
        _this->traceincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->traceincludes, copyoption1);
    } else {
        _this->traceincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption2 = (_from->debugincludes._refCount != -1 ? &_from->debugincludes : 0);
    if (copyoption2 != 0) {
        _this->debugincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->debugincludes, copyoption2);
    } else {
        _this->debugincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption3 = (_from->infoincludes._refCount != -1 ? &_from->infoincludes : 0);
    if (copyoption3 != 0) {
        _this->infoincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->infoincludes, copyoption3);
    } else {
        _this->infoincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption4 = (_from->warnincludes._refCount != -1 ? &_from->warnincludes : 0);
    if (copyoption4 != 0) {
        _this->warnincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->warnincludes, copyoption4);
    } else {
        _this->warnincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption5 = (_from->errorincludes._refCount != -1 ? &_from->errorincludes : 0);
    if (copyoption5 != 0) {
        _this->errorincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->errorincludes, copyoption5);
    } else {
        _this->errorincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption6 = (_from->fatalincludes._refCount != -1 ? &_from->fatalincludes : 0);
    if (copyoption6 != 0) {
        _this->fatalincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->fatalincludes, copyoption6);
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
    bool result11;
    sjs_string sjt_call97 = { -1 };
    sjs_string sjt_call98 = { -1 };
    sjs_string sjt_call99 = { -1 };
    bool sjt_capture19;
    int32_t sjt_functionParam267;
    sjs_size* sjt_functionParam293 = 0;
    sjs_rect* sjt_functionParam302 = 0;
    sjs_scene2d* sjt_interfaceParam49 = 0;
    sjs_animator* sjt_parent186 = 0;
    sjs_windowrenderer* sjt_parent198 = 0;
    sjs_scene2d* sjt_parent200 = 0;
    sjs_scene2d* sjt_parent204 = 0;
    sjs_rect* sjt_parent205 = 0;
    sji_element sjt_parent207 = { 0 };
    sjs_scene2d* sjt_parent219 = 0;
    sjs_windowrenderer* sjt_parent220 = 0;
    int32_option sjv_mouse_eventtype;
    bool sjv_mouse_isleftdown;
    int32_t sjv_mouse_x;
    int32_t sjv_mouse_y;
    sjs_rect sjv_rect = { -1 };
    bool sjv_shouldappcontinue;
    bool sjv_shouldcontinue;
    sjs_size sjv_size = { -1 };
    int32_t sjv_ticks;

    sjv_shouldappcontinue = true;
    sjv_ticks = 0;
    sjv_ticks = SDL_GetTicks();
    sjt_parent186 = &sjv_animator;
    sjt_functionParam267 = sjv_ticks;
    sjf_animator_nextframe(sjt_parent186, sjt_functionParam267);
    if (sjv_mainloop_showfps) {
        sjv_mainloop_frames = sjv_mainloop_frames + 1;
        if ((sjv_mainloop_lasttick + 1000) < sjv_ticks) {
            int32_t sjt_cast24;
            int32_t sjt_cast25;
            sjs_string* sjt_functionParam271 = 0;
            sjs_string* sjt_functionParam281 = 0;
            float sjt_functionParam282;
            sjs_string* sjt_parent197 = 0;
            float sjv_fps;

            sjt_cast24 = sjv_mainloop_frames;
            sjt_cast25 = sjv_ticks - sjv_mainloop_lasttick;
            sjv_fps = ((float)sjt_cast24 * 1000.0f) / (float)sjt_cast25;
            sjt_call98._refCount = 1;
            sjt_call98.count = 5;
            sjt_call98.data._refCount = 1;
            sjt_call98.data.datasize = 5;
            sjt_call98.data.data = (void*)sjg_string30;
            sjt_call98.data.isglobal = true;
            sjt_call98.data.count = 5;
            sjf_array_char(&sjt_call98.data);
            sjt_call98._isnullterminated = false;
            sjf_string(&sjt_call98);
            sjt_parent197 = &sjt_call98;
            sjt_functionParam282 = sjv_fps;
            sjf_f32_asstring(sjt_functionParam282, &sjt_call99);
            sjt_functionParam281 = &sjt_call99;
            sjf_string_add(sjt_parent197, sjt_functionParam281, &sjt_call97);
            sjt_functionParam271 = &sjt_call97;
            sjf_debug_writeline(sjt_functionParam271);
            sjv_mainloop_lasttick = sjv_ticks;
            sjv_mainloop_frames = 0;
        }
    }

    sjt_parent198 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_getsize(sjt_parent198, &sjv_size);
    sjt_parent200 = &sjv_rootscene;
    sjt_functionParam293 = &sjv_size;
    sjf_scene2d_setsize(sjt_parent200, sjt_functionParam293);
    sjt_parent204 = &sjv_rootscene;
    sjf_scene2d_start(sjt_parent204);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjv_rect.w = (&sjv_size)->w;
    sjv_rect.h = (&sjv_size)->h;
    sjf_rect(&sjv_rect);
    sjt_parent205 = &sjv_looplastrect;
    sjt_functionParam302 = &sjv_rect;
    sjf_rect_isequal(sjt_parent205, sjt_functionParam302, &sjt_capture19);
    result11 = !sjt_capture19;
    if (result11) {
        sjs_rect* sjt_interfaceParam48 = 0;
        sji_element sjt_parent206 = { 0 };

        sjt_parent206 = sjv_root;
        sjt_interfaceParam48 = &sjv_rect;
        sjt_parent206._vtbl->setrect(sjt_parent206._parent, sjt_interfaceParam48);
    }

    sjt_parent207 = sjv_root;
    sjt_interfaceParam49 = &sjv_rootscene;
    sjt_parent207._vtbl->render(sjt_parent207._parent, sjt_interfaceParam49);
    sjt_parent219 = &sjv_rootscene;
    sjf_scene2d_end(sjt_parent219);
    sjt_parent220 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_present(sjt_parent220);
    SDL_Event e;
    while(SDL_PollEvent( &e ) != 0) {
        sjv_mouse_eventtype = int32_empty;
        sjv_mouse_x = 0;
        sjv_mouse_y = 0;
        sjv_mouse_isleftdown = false;
        switch (e.type) {
            case SDL_QUIT:
            sjv_shouldappcontinue = false;
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
        if (sjv_mouse_eventtype.isvalid) {
            int32_t ifValue17;
            int32_option sjt_getValue5;

            sjt_getValue5 = sjv_mouse_eventtype;
            ifValue17 = sjt_getValue5.value;
            if ((sjv_mouse_captureelement._parent != 0)) {
                sji_element ifValue18 = { 0 };
                sjs_mouseevent sjt_call102 = { -1 };
                sjs_mouseevent* sjt_interfaceParam50 = 0;
                sji_element sjt_parent221 = { 0 };

                ifValue18 = sjv_mouse_captureelement;
                if (ifValue18._parent != 0) {
                    ifValue18._parent->_refCount++;
                }

                sjt_parent221 = ifValue18;
                sjt_call102._refCount = 1;
                sjt_call102.eventtype = ifValue17;
                sjt_call102.point._refCount = 1;
                sjt_call102.point.x = sjv_mouse_x;
                sjt_call102.point.y = sjv_mouse_y;
                sjf_point(&sjt_call102.point);
                sjt_call102.iscaptured = true;
                sjt_call102.isleftdown = sjv_mouse_isleftdown;
                sjf_mouseevent(&sjt_call102);
                sjt_interfaceParam50 = &sjt_call102;
                sjt_parent221._vtbl->firemouseevent(sjt_parent221._parent, sjt_interfaceParam50, &sjv_shouldcontinue);

                if (ifValue18._parent != 0) {
                    ifValue18._parent->_refCount--;
                    if (ifValue18._parent->_refCount <= 0) {
                        ifValue18._vtbl->destroy(ifValue18._parent);
                        free(ifValue18._parent);
                    }
                }
                if (sjt_call102._refCount == 1) { sjf_mouseevent_destroy(&sjt_call102); }
;
            } else {
                sjs_mouseevent sjt_call103 = { -1 };
                sjs_mouseevent* sjt_interfaceParam51 = 0;
                sji_element sjt_parent222 = { 0 };

                sjt_parent222 = sjv_root;
                sjt_call103._refCount = 1;
                sjt_call103.eventtype = ifValue17;
                sjt_call103.point._refCount = 1;
                sjt_call103.point.x = sjv_mouse_x;
                sjt_call103.point.y = sjv_mouse_y;
                sjf_point(&sjt_call103.point);
                sjt_call103.iscaptured = false;
                sjt_call103.isleftdown = sjv_mouse_isleftdown;
                sjf_mouseevent(&sjt_call103);
                sjt_interfaceParam51 = &sjt_call103;
                sjt_parent222._vtbl->firemouseevent(sjt_parent222._parent, sjt_interfaceParam51, &sjv_shouldcontinue);

                if (sjt_call103._refCount == 1) { sjf_mouseevent_destroy(&sjt_call103); }
;
            }
        }

    }
    sjv_mainloop_shouldcontinue = sjv_shouldappcontinue;

    if (sjt_call97._refCount == 1) { sjf_string_destroy(&sjt_call97); }
;
    if (sjt_call98._refCount == 1) { sjf_string_destroy(&sjt_call98); }
;
    if (sjt_call99._refCount == 1) { sjf_string_destroy(&sjt_call99); }
;
    if (sjv_rect._refCount == 1) { sjf_rect_destroy(&sjv_rect); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
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
    float result7;

    _return->_refCount = 1;
    _return->m00 = 2.0f / (right - left);
    _return->m01 = 0.0f;
    _return->m02 = 0.0f;
    _return->m03 = 0.0f;
    _return->m10 = 0.0f;
    _return->m11 = 2.0f / (top - bottom);
    _return->m12 = 0.0f;
    _return->m13 = 0.0f;
    _return->m20 = 0.0f;
    _return->m21 = 0.0f;
    result7 = -2.0f;
    _return->m22 = result7 / (zfar - znear);
    _return->m23 = 0.0f;
    _return->m30 = 0.0f - ((right + left) / (right - left));
    _return->m31 = 0.0f - ((top + bottom) / (top - bottom));
    _return->m32 = 0.0f - ((zfar + znear) / (zfar - znear));
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return) {
    float result8;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    (*_return)->m00 = 2.0f / (right - left);
    (*_return)->m01 = 0.0f;
    (*_return)->m02 = 0.0f;
    (*_return)->m03 = 0.0f;
    (*_return)->m10 = 0.0f;
    (*_return)->m11 = 2.0f / (top - bottom);
    (*_return)->m12 = 0.0f;
    (*_return)->m13 = 0.0f;
    (*_return)->m20 = 0.0f;
    (*_return)->m21 = 0.0f;
    result8 = -2.0f;
    (*_return)->m22 = result8 / (zfar - znear);
    (*_return)->m23 = 0.0f;
    (*_return)->m30 = 0.0f - ((right + left) / (right - left));
    (*_return)->m31 = 0.0f - ((top + bottom) / (top - bottom));
    (*_return)->m32 = 0.0f - ((zfar + znear) / (zfar - znear));
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
    _this->eventtype = _from->eventtype;
    _this->point._refCount = 1;
    sjf_point_copy(&_this->point, &_from->point);
    _this->iscaptured = _from->iscaptured;
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

    sjv_shouldcontinue = true;
    sjt_forStart7 = 0;
    sjt_forEnd7 = children->count;
    i = sjt_forEnd7 - 1;
    while (i >= sjt_forStart7) {
        if (sjv_shouldcontinue) {
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
    (*_return) = (_parent->x == rect->x) && ((_parent->y == rect->y) && ((_parent->w == rect->w) && (_parent->h == rect->h)));
}

void sjf_rect_subtractmargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    _return->_refCount = 1;
    _return->x = _parent->x + margin->l;
    _return->y = _parent->y + margin->t;
    _return->w = (_parent->w - margin->l) - margin->r;
    _return->h = (_parent->h - margin->t) - margin->b;
    sjf_rect(_return);
}

void sjf_rect_subtractmargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    (*_return)->x = _parent->x + margin->l;
    (*_return)->y = _parent->y + margin->t;
    (*_return)->w = (_parent->w - margin->l) - margin->r;
    (*_return)->h = (_parent->h - margin->t) - margin->b;
    sjf_rect_heap((*_return));
}

void sjf_runloop(void) {
    #ifdef EMSCRIPTEN
    emscripten_set_main_loop((em_callback_func)sjf_mainloop, 0, 0);
    exit(0);
    #else
    while (sjv_mainloop_shouldcontinue) {
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
    sjs_rect* sjt_functionParam310 = 0;
    sjs_rect* sjt_functionParam311 = 0;

    sjt_functionParam310 = &_parent->windowrect;
    sjt_functionParam311 = &_parent->windowrect;
    sjf_glpopviewport(sjt_functionParam310, sjt_functionParam311);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result6;
    bool sjt_capture18;
    sjs_mat4 sjt_funcold16 = { -1 };
    sjs_mat4 sjt_funcold17 = { -1 };
    sjs_mat4 sjt_funcold18 = { -1 };
    sjs_size* sjt_functionParam283 = 0;
    sjs_size* sjt_parent199 = 0;

    sjt_parent199 = &_parent->_size;
    sjt_functionParam283 = size;
    sjf_size_isequal(sjt_parent199, sjt_functionParam283, &sjt_capture18);
    result6 = !sjt_capture18;
    if (result6) {
        float result10;
        float result9;
        int32_t sjt_cast26;
        int32_t sjt_cast27;
        float sjt_functionParam284;
        float sjt_functionParam285;
        float sjt_functionParam286;
        float sjt_functionParam287;
        float sjt_functionParam288;
        float sjt_functionParam289;
        float sjt_functionParam290;
        float sjt_functionParam291;
        float sjt_functionParam292;

        if (_parent->_size._refCount == 1) { sjf_size_destroy(&_parent->_size); }
;
        sjf_size_copy(&_parent->_size, size);
        sjt_funcold16._refCount = 1;
        sjf_mat4_copy(&sjt_funcold16, &_parent->projection);
        sjt_functionParam284 = 0.0f;
        sjt_cast26 = (&_parent->_size)->w;
        sjt_functionParam285 = (float)sjt_cast26;
        sjt_cast27 = 0 - (&_parent->_size)->h;
        sjt_functionParam286 = (float)sjt_cast27;
        sjt_functionParam287 = 0.0f;
        result9 = -1.0f;
        sjt_functionParam288 = result9;
        sjt_functionParam289 = 1.0f;
        sjf_mat4_orthographic(sjt_functionParam284, sjt_functionParam285, sjt_functionParam286, sjt_functionParam287, sjt_functionParam288, sjt_functionParam289, &sjt_funcold16);
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
        sjf_mat4_copy(&_parent->projection, &sjt_funcold16);
        sjt_funcold17._refCount = 1;
        sjf_mat4_copy(&sjt_funcold17, &_parent->model);
        sjt_functionParam290 = 1.0f;
        result10 = -1.0f;
        sjt_functionParam291 = result10;
        sjt_functionParam292 = 1.0f;
        sjf_mat4_scale(sjt_functionParam290, sjt_functionParam291, sjt_functionParam292, &sjt_funcold17);
        if (_parent->model._refCount == 1) { sjf_mat4_destroy(&_parent->model); }
;
        sjf_mat4_copy(&_parent->model, &sjt_funcold17);
        sjt_funcold18._refCount = 1;
        sjf_mat4_copy(&sjt_funcold18, &_parent->view);
        sjf_mat4_identity(&sjt_funcold18);
        if (_parent->view._refCount == 1) { sjf_mat4_destroy(&_parent->view); }
;
        sjf_mat4_copy(&_parent->view, &sjt_funcold18);
    }

    if (sjt_funcold16._refCount == 1) { sjf_mat4_destroy(&sjt_funcold16); }
;
    if (sjt_funcold17._refCount == 1) { sjf_mat4_destroy(&sjt_funcold17); }
;
    if (sjt_funcold18._refCount == 1) { sjf_mat4_destroy(&sjt_funcold18); }
;
}

void sjf_scene2d_start(sjs_scene2d* _parent) {
    sjs_rect sjt_funcold19 = { -1 };
    sjs_rect* sjt_functionParam300 = 0;
    sjs_rect* sjt_functionParam301 = 0;

    sjt_funcold19._refCount = 1;
    sjf_rect_copy(&sjt_funcold19, &_parent->windowrect);
    sjt_funcold19._refCount = 1;
    sjt_funcold19.x = 0;
    sjt_funcold19.y = 0;
    sjt_funcold19.w = (&_parent->_size)->w;
    sjt_funcold19.h = (&_parent->_size)->h;
    sjf_rect(&sjt_funcold19);
    if (_parent->windowrect._refCount == 1) { sjf_rect_destroy(&_parent->windowrect); }
;
    sjf_rect_copy(&_parent->windowrect, &sjt_funcold19);
    sjt_functionParam300 = &_parent->windowrect;
    sjt_functionParam301 = &_parent->windowrect;
    sjf_glpushviewport(sjt_functionParam300, sjt_functionParam301);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_DEPTH_TEST );

    if (sjt_funcold19._refCount == 1) { sjf_rect_destroy(&sjt_funcold19); }
;
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
    if (_this->vertex._refCount == 1) { sjf_string_destroy(&_this->vertex); }
;
    if (_this->pixel._refCount == 1) { sjf_string_destroy(&_this->pixel); }
;
}

void sjf_shader_heap(sjs_shader* _this) {
    _this->id = shader_load((char*)_this->vertex.data.data, (char*)_this->pixel.data.data);
}

void sjf_size(sjs_size* _this) {
}

void sjf_size_addmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    _return->_refCount = 1;
    _return->w = (_parent->w + margin->l) + margin->r;
    _return->h = (_parent->h + margin->t) + margin->b;
    sjf_size(_return);
}

void sjf_size_addmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    (*_return)->w = (_parent->w + margin->l) + margin->r;
    (*_return)->h = (_parent->h + margin->t) + margin->b;
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
    (*_return) = (_parent->w == size->w) && (_parent->h == size->h);
}

void sjf_size_max(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    if (_parent->w > maxsize->w) {
        _return->w = _parent->w;
    } else {
        _return->w = maxsize->w;
    }

    if (_parent->h > maxsize->h) {
        _return->h = _parent->h;
    } else {
        _return->h = maxsize->h;
    }

    sjf_size(_return);
}

void sjf_size_max_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    if (_parent->w > maxsize->w) {
        (*_return)->w = _parent->w;
    } else {
        (*_return)->w = maxsize->w;
    }

    if (_parent->h > maxsize->h) {
        (*_return)->h = _parent->h;
    } else {
        (*_return)->h = maxsize->h;
    }

    sjf_size_heap((*_return));
}

void sjf_size_min(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    if (_parent->w < maxsize->w) {
        _return->w = _parent->w;
    } else {
        _return->w = maxsize->w;
    }

    if (_parent->h < maxsize->h) {
        _return->h = _parent->h;
    } else {
        _return->h = maxsize->h;
    }

    sjf_size(_return);
}

void sjf_size_min_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    if (_parent->w < maxsize->w) {
        (*_return)->w = _parent->w;
    } else {
        (*_return)->w = maxsize->w;
    }

    if (_parent->h < maxsize->h) {
        (*_return)->h = _parent->h;
    } else {
        (*_return)->h = maxsize->h;
    }

    sjf_size_heap((*_return));
}

void sjf_size_subtractmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    _return->_refCount = 1;
    _return->w = (_parent->w - margin->l) - margin->r;
    _return->h = (_parent->h - margin->t) - margin->b;
    sjf_size(_return);
}

void sjf_size_subtractmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    (*_return)->w = (_parent->w - margin->l) - margin->r;
    (*_return)->h = (_parent->h - margin->t) - margin->b;
    sjf_size_heap((*_return));
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
        _return->count = _parent->count;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, &_parent->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_forEnd24;
        int32_t sjt_forStart24;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam272;
            sjs_array_char* sjt_parent190 = 0;

            sjt_parent190 = &_parent->data;
            sjt_functionParam272 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent190, sjt_functionParam272, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart24 = 0;
        sjt_forEnd24 = item->count;
        i = sjt_forStart24;
        while (i < sjt_forEnd24) {
            int32_t sjt_functionParam273;
            char sjt_functionParam274;
            int32_t sjt_functionParam276;
            sjs_array_char* sjt_parent191 = 0;
            sjs_string* sjt_parent193 = 0;

            sjt_parent191 = &sjv_newdata;
            sjt_functionParam273 = sjv_newcount;
            sjt_parent193 = item;
            sjt_functionParam276 = i;
            sjf_string_getat(sjt_parent193, sjt_functionParam276, &sjt_functionParam274);
            sjf_array_char_initat(sjt_parent191, sjt_functionParam273, sjt_functionParam274);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        _return->_refCount = 1;
        _return->count = sjv_newcount;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, &sjv_newdata);
        _return->_isnullterminated = false;
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
        (*_return)->count = _parent->count;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, &_parent->data);
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_forEnd25;
        int32_t sjt_forStart25;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam277;
            sjs_array_char* sjt_parent194 = 0;

            sjt_parent194 = &_parent->data;
            sjt_functionParam277 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent194, sjt_functionParam277, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart25 = 0;
        sjt_forEnd25 = item->count;
        i = sjt_forStart25;
        while (i < sjt_forEnd25) {
            int32_t sjt_functionParam278;
            char sjt_functionParam279;
            int32_t sjt_functionParam280;
            sjs_array_char* sjt_parent195 = 0;
            sjs_string* sjt_parent196 = 0;

            sjt_parent195 = &sjv_newdata;
            sjt_functionParam278 = sjv_newcount;
            sjt_parent196 = item;
            sjt_functionParam280 = i;
            sjf_string_getat(sjt_parent196, sjt_functionParam280, &sjt_functionParam279);
            sjf_array_char_initat(sjt_parent195, sjt_functionParam278, sjt_functionParam279);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, &sjv_newdata);
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam275;
    sjs_array_char* sjt_parent192 = 0;

    sjt_parent192 = &_parent->data;
    sjt_functionParam275 = index;
    sjf_array_char_getat(sjt_parent192, sjt_functionParam275, _return);
}

void sjf_string_hash(sjs_string* _parent, uint32_t* _return) {
    (*_return) = kh_str_hash_func((char*)_parent->data.data);
return;;
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_array_char* sjt_functionParam9 = 0;
    sjs_array_char* sjt_parent1 = 0;

    sjt_parent1 = &_parent->data;
    sjt_functionParam9 = &test->data;
    sjf_array_char_isequal(sjt_parent1, sjt_functionParam9, _return);
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result4;
    bool result5;
    sjs_array_char sjt_funcold15 = { -1 };

    result4 = !(&_parent->data)->isglobal;
    result5 = !_parent->_isnullterminated;
    if (result4 || result5) {
        int32_t sjt_functionParam269;
        char sjt_functionParam270;
        sjs_array_char* sjt_parent188 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam268;
            sjs_array_char* sjt_parent187 = 0;

            sjt_funcold15._refCount = 1;
            sjf_array_char_copy(&sjt_funcold15, &_parent->data);
            sjt_parent187 = &_parent->data;
            sjt_functionParam268 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent187, sjt_functionParam268, &sjt_funcold15);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            sjf_array_char_copy(&_parent->data, &sjt_funcold15);
        }

        sjt_parent188 = &_parent->data;
        sjt_functionParam269 = _parent->count;
        sjt_functionParam270 = '\0';
        sjf_array_char_initat(sjt_parent188, sjt_functionParam269, sjt_functionParam270);
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold15._refCount == 1) { sjf_array_char_destroy(&sjt_funcold15); }
;
}

void sjf_style(sjs_style* _this) {
}

void sjf_style_copy(sjs_style* _this, sjs_style* _from) {
}

void sjf_style_destroy(sjs_style* _this) {
}

void sjf_style_getfont(sjs_style* _parent, sjs_font* _return) {
    sjs_font* sjt_call17 = 0;
    sjs_string sjt_call18 = { -1 };
    sjs_string* sjt_functionParam101 = 0;
    float sjt_functionParam102;

    sjt_call18._refCount = 1;
    sjt_call18.count = 16;
    sjt_call18.data._refCount = 1;
    sjt_call18.data.datasize = 16;
    sjt_call18.data.data = (void*)sjg_string16;
    sjt_call18.data.isglobal = true;
    sjt_call18.data.count = 16;
    sjf_array_char(&sjt_call18.data);
    sjt_call18._isnullterminated = false;
    sjf_string(&sjt_call18);
    sjt_functionParam101 = &sjt_call18;
    sjt_functionParam102 = 24.0f;
    sjf_font_load_heap(sjt_functionParam101, sjt_functionParam102, &sjt_call17);
    _return->_refCount = 1;
    sjf_font_copy(_return, sjt_call17);

    sjt_call17->_refCount--;
    if (sjt_call17->_refCount <= 0) {
        weakptr_release(sjt_call17);
        sjf_font_destroy(sjt_call17);
        free(sjt_call17);
    }
    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
;
}

void sjf_style_getfont_heap(sjs_style* _parent, sjs_font** _return) {
    sjs_string sjt_call19 = { -1 };
    sjs_string* sjt_functionParam103 = 0;
    float sjt_functionParam104;

    sjt_call19._refCount = 1;
    sjt_call19.count = 16;
    sjt_call19.data._refCount = 1;
    sjt_call19.data.datasize = 16;
    sjt_call19.data.data = (void*)sjg_string16;
    sjt_call19.data.isglobal = true;
    sjt_call19.data.count = 16;
    sjf_array_char(&sjt_call19.data);
    sjt_call19._isnullterminated = false;
    sjf_string(&sjt_call19);
    sjt_functionParam103 = &sjt_call19;
    sjt_functionParam104 = 24.0f;
    sjf_font_load_heap(sjt_functionParam103, sjt_functionParam104, _return);

    if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
;
}

void sjf_style_heap(sjs_style* _this) {
}

void sjf_testelement_heap(sjs_string* text, sji_element* _return) {
    sjs_textelement* sjt_call10 = 0;
    sjs_filllayout* sjt_call6 = 0;
    sjs_boxelement* sjt_call9 = 0;
    int32_t sjt_capture11;
    int32_t sjt_capture12;
    sjs_filllayout* sjt_cast5 = 0;
    sjs_boxelement* sjt_cast6 = 0;
    sjs_textelement* sjt_cast7 = 0;
    int32_t sjt_functionParam57;
    sji_element sjt_functionParam58 = { 0 };
    int32_t sjt_functionParam63;
    sji_element sjt_functionParam64 = { 0 };
    sjs_array_heap_iface_element* sjt_parent48 = 0;
    sjs_array_heap_iface_element* sjt_parent53 = 0;
    sjs_style* sjt_parent69 = 0;

    sjt_call6 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
    sjt_call6->_refCount = 1;
    sjt_call6->children._refCount = 1;
    sjt_call6->children.datasize = 2;
    sjt_call6->children.data = 0;
    sjt_call6->children.isglobal = false;
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
    sjf_i32_random(&sjt_capture11);
    sjt_call9->idealsize.w = (sjt_capture11 % 20) + 30;
    sjf_i32_random(&sjt_capture12);
    sjt_call9->idealsize.h = (sjt_capture12 % 20) + 30;
    sjf_size(&sjt_call9->idealsize);
    sjt_call9->rect._refCount = 1;
    sjt_call9->rect.x = 0;
    sjt_call9->rect.y = 0;
    sjt_call9->rect.w = 0;
    sjt_call9->rect.h = 0;
    sjf_rect(&sjt_call9->rect);
    sjt_call9->boxrenderer._refCount = -1;
    sjf_boxelement_heap(sjt_call9);
    sjt_cast6 = sjt_call9;
    sjf_boxelement_as_sji_element(sjt_cast6, &sjt_functionParam58);
    if (sjt_functionParam58._parent != 0) {
        sjt_functionParam58._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent48, sjt_functionParam57, sjt_functionParam58);
    sjt_parent53 = array6;
    sjt_functionParam63 = 1;
    sjt_call10 = (sjs_textelement*)malloc(sizeof(sjs_textelement));
    sjt_call10->_refCount = 1;
    sjt_call10->id._refCount = -1;
    sjt_parent69 = &sjv_style;
    sjf_style_getfont(sjt_parent69, &sjt_call10->font);
    sjt_call10->text._refCount = 1;
    sjf_string_copy(&sjt_call10->text, text);
    sjt_call10->color._refCount = 1;
    sjf_color_copy(&sjt_call10->color, &sjv_colors_white);
    sjt_call10->margin._refCount = 1;
    sjt_call10->margin.l = 4;
    sjt_call10->margin.t = 4;
    sjt_call10->margin.r = 4;
    sjt_call10->margin.b = 4;
    sjf_margin(&sjt_call10->margin);
    sjt_call10->halign = sjv_texthorizontal_center;
    sjt_call10->valign = sjv_textvertical_center;
    sjt_call10->idealsize._refCount = -1;
    sjt_call10->_rect._refCount = 1;
    sjt_call10->_rect.x = 0;
    sjt_call10->_rect.y = 0;
    sjt_call10->_rect.w = 0;
    sjt_call10->_rect.h = 0;
    sjf_rect(&sjt_call10->_rect);
    sjt_call10->_textrenderer._refCount = -1;
    sjf_textelement_heap(sjt_call10);
    sjt_cast7 = sjt_call10;
    sjf_textelement_as_sji_element(sjt_cast7, &sjt_functionParam64);
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
    sjt_cast5 = sjt_call6;
    sjf_filllayout_as_sji_element(sjt_cast5, &(*_return));
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
    sjs_string* copyoption14 = (_from->id._refCount != -1 ? &_from->id : 0);
    if (copyoption14 != 0) {
        _this->id._refCount = 1;
        sjf_string_copy(&_this->id, copyoption14);
    } else {
        _this->id._refCount = -1;
    }

    _this->font._refCount = 1;
    sjf_font_copy(&_this->font, &_from->font);
    _this->text._refCount = 1;
    sjf_string_copy(&_this->text, &_from->text);
    _this->color._refCount = 1;
    sjf_color_copy(&_this->color, &_from->color);
    _this->margin._refCount = 1;
    sjf_margin_copy(&_this->margin, &_from->margin);
    _this->halign = _from->halign;
    _this->valign = _from->valign;
    sjs_size* copyoption15 = (_from->idealsize._refCount != -1 ? &_from->idealsize : 0);
    if (copyoption15 != 0) {
        _this->idealsize._refCount = 1;
        sjf_size_copy(&_this->idealsize, copyoption15);
    } else {
        _this->idealsize._refCount = -1;
    }

    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    sjs_textrenderer* copyoption16 = (_from->_textrenderer._refCount != -1 ? &_from->_textrenderer : 0);
    if (copyoption16 != 0) {
        _this->_textrenderer._refCount = 1;
        sjf_textrenderer_copy(&_this->_textrenderer, copyoption16);
    } else {
        _this->_textrenderer._refCount = -1;
    }
}

void sjf_textelement_destroy(sjs_textelement* _this) {
    if (_this->id._refCount == 1) { sjf_string_destroy(&_this->id); }
;
    if (_this->font._refCount == 1) { sjf_font_destroy(&_this->font); }
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
    (*_return) = true;
}

void sjf_textelement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 136;
}

void sjf_textelement_getrect(sjs_textelement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_textelement_getrect_heap(sjs_textelement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_textelement_getsize(sjs_textelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    if (((_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0) != 0)) {
        sjs_size* ifValue7 = 0;
        sjs_size* sjt_functionParam67 = 0;
        sjs_size* sjt_parent55 = 0;

        ifValue7 = (_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0);
        sjt_parent55 = ifValue7;
        sjt_functionParam67 = maxsize;
        sjf_size_min(sjt_parent55, sjt_functionParam67, _return);
    } else {
        sjs_size sjt_call11 = { -1 };
        sjs_string* sjt_functionParam68 = 0;
        sjs_margin* sjt_functionParam69 = 0;
        sjs_size* sjt_functionParam70 = 0;
        sjs_size* sjt_parent56 = 0;
        sjs_font* sjt_parent57 = 0;
        sjs_size* sjt_parent58 = 0;
        sjs_size sjv_textsize = { -1 };

        sjt_parent57 = &_parent->font;
        sjt_functionParam68 = &_parent->text;
        sjf_font_gettextsize(sjt_parent57, sjt_functionParam68, &sjt_call11);
        sjt_parent56 = &sjt_call11;
        sjt_functionParam69 = &_parent->margin;
        sjf_size_addmargin(sjt_parent56, sjt_functionParam69, &sjv_textsize);
        sjt_parent58 = &sjv_textsize;
        sjt_functionParam70 = maxsize;
        sjf_size_min(sjt_parent58, sjt_functionParam70, _return);

        if (sjt_call11._refCount == 1) { sjf_size_destroy(&sjt_call11); }
;
        if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
    }
}

void sjf_textelement_getsize_heap(sjs_textelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    if (((_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0) != 0)) {
        sjs_size* ifValue10 = 0;
        sjs_size* sjt_functionParam71 = 0;
        sjs_size* sjt_parent59 = 0;

        ifValue10 = (_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0);
        sjt_parent59 = ifValue10;
        sjt_functionParam71 = maxsize;
        sjf_size_min_heap(sjt_parent59, sjt_functionParam71, _return);
    } else {
        sjs_size sjt_call12 = { -1 };
        sjs_string* sjt_functionParam72 = 0;
        sjs_margin* sjt_functionParam73 = 0;
        sjs_size* sjt_functionParam74 = 0;
        sjs_size* sjt_parent60 = 0;
        sjs_font* sjt_parent61 = 0;
        sjs_size* sjt_parent62 = 0;
        sjs_size sjv_textsize = { -1 };

        sjt_parent61 = &_parent->font;
        sjt_functionParam72 = &_parent->text;
        sjf_font_gettextsize(sjt_parent61, sjt_functionParam72, &sjt_call12);
        sjt_parent60 = &sjt_call12;
        sjt_functionParam73 = &_parent->margin;
        sjf_size_addmargin(sjt_parent60, sjt_functionParam73, &sjv_textsize);
        sjt_parent62 = &sjv_textsize;
        sjt_functionParam74 = maxsize;
        sjf_size_min_heap(sjt_parent62, sjt_functionParam74, _return);

        if (sjt_call12._refCount == 1) { sjf_size_destroy(&sjt_call12); }
;
        if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
    }
}

void sjf_textelement_gettext(sjs_textelement* _parent, sjs_string* _return) {
    _return->_refCount = 1;
    sjf_string_copy(_return, &_parent->text);
}

void sjf_textelement_gettext_heap(sjs_textelement* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    sjf_string_copy((*_return), &_parent->text);
}

void sjf_textelement_heap(sjs_textelement* _this) {
    if (((_this->id._refCount != -1 ? &_this->id : 0) != 0)) {
        sjs_string* ifValue12 = 0;
        sjs_textelement* sjt_cast8 = 0;
        sjs_string* sjt_functionParam65 = 0;
        sji_element sjt_functionParam66 = { 0 };
        sjs_hash_string_weak_iface_element* sjt_parent54 = 0;

        ifValue12 = (_this->id._refCount != -1 ? &_this->id : 0);
        sjt_parent54 = &sjv_elementsbyid;
        sjt_functionParam65 = ifValue12;
        sjt_cast8 = _this;
        sjf_textelement_as_sji_element(sjt_cast8, &sjt_functionParam66);
        delete_cb weakptrcb16 = { &sjt_functionParam66._parent, weakptr_clear };
        if (sjt_functionParam66._parent != 0) { weakptr_cb_add(sjt_functionParam66._parent, weakptrcb16); }
        sjf_hash_string_weak_iface_element_setat(sjt_parent54, sjt_functionParam65, sjt_functionParam66);

        delete_cb weakptrcb24 = { &sjt_functionParam66._parent, weakptr_clear };
        if (sjt_functionParam66._parent != 0) { weakptr_cb_remove(sjt_functionParam66._parent, weakptrcb24); }
    }
}

void sjf_textelement_render(sjs_textelement* _parent, sjs_scene2d* scene) {
    sjs_textrenderer sjt_funcold4 = { -1 };
    sjs_rect sjv_innerrect = { -1 };
    sjs_size sjv_textsize = { -1 };

    if ((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) == 0) {
        sjs_string* sjt_functionParam76 = 0;
        sjs_margin* sjt_functionParam77 = 0;
        sjs_font* sjt_parent64 = 0;
        sjs_rect* sjt_parent65 = 0;
        int32_t sjv_x;
        int32_t sjv_y;
        int32_t underscore1;
        int32_t underscore2;

        sjt_parent64 = &_parent->font;
        sjt_functionParam76 = &_parent->text;
        sjf_font_gettextsize(sjt_parent64, sjt_functionParam76, &sjv_textsize);
        sjt_parent65 = &_parent->_rect;
        sjt_functionParam77 = &_parent->margin;
        sjf_rect_subtractmargin(sjt_parent65, sjt_functionParam77, &sjv_innerrect);
        underscore1 = _parent->halign;
        if (underscore1 == sjv_texthorizontal_left) {
            sjv_x = (&sjv_innerrect)->x;
        } else {
            if (underscore1 == sjv_texthorizontal_right) {
                sjv_x = ((&sjv_innerrect)->x + (&sjv_innerrect)->w) - (&sjv_textsize)->w;
            } else {
                if (underscore1 == sjv_texthorizontal_center) {
                    sjv_x = (&sjv_innerrect)->x + (((&sjv_innerrect)->w - (&sjv_textsize)->w) / 2);
                } else {
                    sjv_x = 0;
                }
            }
        }

        underscore2 = _parent->valign;
        if (underscore2 == sjv_textvertical_top) {
            sjv_y = (&sjv_innerrect)->y;
        } else {
            if (underscore2 == sjv_textvertical_bottom) {
                sjv_y = ((&sjv_innerrect)->y + (&sjv_innerrect)->h) - (&sjv_textsize)->h;
            } else {
                if (underscore2 == sjv_textvertical_center) {
                    sjv_y = (&sjv_innerrect)->y + (((&sjv_innerrect)->h - (&sjv_textsize)->h) / 2);
                } else {
                    sjv_y = 0;
                }
            }
        }

        _parent->_textrenderer._refCount = 1;
        sjt_funcold4._refCount = 1;
        sjf_textrenderer_copy(&sjt_funcold4, &_parent->_textrenderer);
        sjt_funcold4._refCount = 1;
        sjt_funcold4.text._refCount = 1;
        sjf_string_copy(&sjt_funcold4.text, &_parent->text);
        sjt_funcold4.point._refCount = 1;
        sjt_funcold4.point.x = sjv_x;
        sjt_funcold4.point.y = sjv_y;
        sjf_point(&sjt_funcold4.point);
        sjt_funcold4.color._refCount = 1;
        sjf_color_copy(&sjt_funcold4.color, &_parent->color);
        sjt_funcold4.font._refCount = 1;
        sjf_font_copy(&sjt_funcold4.font, &_parent->font);
        sjf_textrenderer(&sjt_funcold4);
        if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
        sjf_textrenderer_copy(&_parent->_textrenderer, &sjt_funcold4);
    }

    if ((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam97 = 0;
        sjs_textrenderer* sjt_parent66 = 0;

        sjt_parent66 = (_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0);
        sjt_functionParam97 = scene;
        sjf_textrenderer_render(sjt_parent66, sjt_functionParam97);
    }

    if (sjt_funcold4._refCount == 1) { sjf_textrenderer_destroy(&sjt_funcold4); }
;
    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
;
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
}

void sjf_textelement_setrect(sjs_textelement* _parent, sjs_rect* rect_) {
    bool result3;
    bool sjt_capture13;
    sjs_rect* sjt_functionParam75 = 0;
    sjs_rect* sjt_parent63 = 0;

    sjt_parent63 = &_parent->_rect;
    sjt_functionParam75 = rect_;
    sjf_rect_isequal(sjt_parent63, sjt_functionParam75, &sjt_capture13);
    result3 = !sjt_capture13;
    if (result3) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
        sjf_rect_copy(&_parent->_rect, rect_);
        if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
        _parent->_textrenderer._refCount = -1;
    }
}

void sjf_textelement_settext(sjs_textelement* _parent, sjs_string* text_) {
    if (_parent->text._refCount == 1) { sjf_string_destroy(&_parent->text); }
;
    sjf_string_copy(&_parent->text, text_);
    if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
    _parent->_textrenderer._refCount = -1;
}

void sjf_textrenderer(sjs_textrenderer* _this) {
    vec2 pen = {{ (float)_this->point.x, (float)_this->point.y }};
    vec4 color = {{ _this->color.r, _this->color.g, _this->color.b, _this->color.a }};
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f,color:4f");
    add_text(_this->buffer, _this->font.font, (char*)_this->text.data.data, _this->text.count, &color, &pen);
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
    if (_this->text._refCount == 1) { sjf_string_destroy(&_this->text); }
;
    if (_this->point._refCount == 1) { sjf_point_destroy(&_this->point); }
;
    if (_this->color._refCount == 1) { sjf_color_destroy(&_this->color); }
;
    if (_this->font._refCount == 1) { sjf_font_destroy(&_this->font); }
;
}

void sjf_textrenderer_heap(sjs_textrenderer* _this) {
    vec2 pen = {{ (float)_this->point.x, (float)_this->point.y }};
    vec4 color = {{ _this->color.r, _this->color.g, _this->color.b, _this->color.a }};
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f,color:4f");
    add_text(_this->buffer, _this->font.font, (char*)_this->text.data.data, _this->text.count, &color, &pen);
    glBindTexture(GL_TEXTURE_2D, _this->font.font->atlas->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)_this->font.font->atlas->width, (int)_this->font.font->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->font.font->atlas->data );
}

void sjf_textrenderer_render(sjs_textrenderer* _parent, sjs_scene2d* scene) {
    sjs_string sjt_call13 = { -1 };
    sjs_string sjt_call14 = { -1 };
    sjs_string sjt_call15 = { -1 };
    sjs_string sjt_call16 = { -1 };
    sjs_shader* sjt_functionParam78 = 0;
    int32_t sjt_functionParam79;
    int32_t sjt_functionParam80;
    int32_t sjt_functionParam81;
    sjs_shader* sjt_functionParam82 = 0;
    sjs_string* sjt_functionParam83 = 0;
    int32_t sjt_functionParam84;
    int32_t sjt_functionParam85;
    sjs_shader* sjt_functionParam86 = 0;
    sjs_string* sjt_functionParam87 = 0;
    sjs_mat4* sjt_functionParam88 = 0;
    int32_t sjt_functionParam89;
    sjs_shader* sjt_functionParam90 = 0;
    sjs_string* sjt_functionParam91 = 0;
    sjs_mat4* sjt_functionParam92 = 0;
    int32_t sjt_functionParam93;
    sjs_shader* sjt_functionParam94 = 0;
    sjs_string* sjt_functionParam95 = 0;
    sjs_mat4* sjt_functionParam96 = 0;

    glBindTexture(GL_TEXTURE_2D, _parent->font.atlas->id);
    sjt_functionParam78 = &sjv_textshader;
    sjf_gluseprogram(sjt_functionParam78);
    sjt_functionParam79 = sjv_glblendfunctype_gl_src_alpha;
    sjt_functionParam80 = sjv_glblendfunctype_gl_one_minus_src_alpha;
    sjf_glblendfunc(sjt_functionParam79, sjt_functionParam80);
    sjt_functionParam82 = &sjv_textshader;
    sjt_call13._refCount = 1;
    sjt_call13.count = 7;
    sjt_call13.data._refCount = 1;
    sjt_call13.data.datasize = 7;
    sjt_call13.data.data = (void*)sjg_string17;
    sjt_call13.data.isglobal = true;
    sjt_call13.data.count = 7;
    sjf_array_char(&sjt_call13.data);
    sjt_call13._isnullterminated = false;
    sjf_string(&sjt_call13);
    sjt_functionParam83 = &sjt_call13;
    sjf_glgetuniformlocation(sjt_functionParam82, sjt_functionParam83, &sjt_functionParam81);
    sjt_functionParam84 = 0;
    sjf_gluniformi32(sjt_functionParam81, sjt_functionParam84);
    sjt_functionParam86 = &sjv_textshader;
    sjt_call14._refCount = 1;
    sjt_call14.count = 5;
    sjt_call14.data._refCount = 1;
    sjt_call14.data.datasize = 5;
    sjt_call14.data.data = (void*)sjg_string18;
    sjt_call14.data.isglobal = true;
    sjt_call14.data.count = 5;
    sjf_array_char(&sjt_call14.data);
    sjt_call14._isnullterminated = false;
    sjf_string(&sjt_call14);
    sjt_functionParam87 = &sjt_call14;
    sjf_glgetuniformlocation(sjt_functionParam86, sjt_functionParam87, &sjt_functionParam85);
    sjt_functionParam88 = &scene->model;
    sjf_gluniformmat4(sjt_functionParam85, sjt_functionParam88);
    sjt_functionParam90 = &sjv_textshader;
    sjt_call15._refCount = 1;
    sjt_call15.count = 4;
    sjt_call15.data._refCount = 1;
    sjt_call15.data.datasize = 4;
    sjt_call15.data.data = (void*)sjg_string19;
    sjt_call15.data.isglobal = true;
    sjt_call15.data.count = 4;
    sjf_array_char(&sjt_call15.data);
    sjt_call15._isnullterminated = false;
    sjf_string(&sjt_call15);
    sjt_functionParam91 = &sjt_call15;
    sjf_glgetuniformlocation(sjt_functionParam90, sjt_functionParam91, &sjt_functionParam89);
    sjt_functionParam92 = &scene->view;
    sjf_gluniformmat4(sjt_functionParam89, sjt_functionParam92);
    sjt_functionParam94 = &sjv_textshader;
    sjt_call16._refCount = 1;
    sjt_call16.count = 10;
    sjt_call16.data._refCount = 1;
    sjt_call16.data.datasize = 10;
    sjt_call16.data.data = (void*)sjg_string20;
    sjt_call16.data.isglobal = true;
    sjt_call16.data.count = 10;
    sjf_array_char(&sjt_call16.data);
    sjt_call16._isnullterminated = false;
    sjf_string(&sjt_call16);
    sjt_functionParam95 = &sjt_call16;
    sjf_glgetuniformlocation(sjt_functionParam94, sjt_functionParam95, &sjt_functionParam93);
    sjt_functionParam96 = &scene->projection;
    sjf_gluniformmat4(sjt_functionParam93, sjt_functionParam96);
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);

    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
;
    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
;
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
;
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

    sjt_cast1 = val;
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
    (*_return) = l == r;
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
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED);
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
;
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
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED);
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
;
}

void sjf_windowrenderer_present(sjs_windowrenderer* _parent) {
    SDL_GL_SwapWindow((SDL_Window*)_parent->win);
}

int main(int argc, char** argv) {
    sjs_borderchild_borderchild_vtbl.destroy = (void(*)(void*))sjf_borderchild_destroy;
    sjs_borderchild_borderchild_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_borderchild_asinterface;
    sjs_borderchild_borderchild_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_borderchild_getclasstype;
    sjs_borderchild_borderchild_vtbl.getposition = (void(*)(sjs_object*, int32_t*))sjf_borderchild_getposition;
    sjs_borderchild_element_vtbl.destroy = (void(*)(void*))sjf_borderchild_destroy;
    sjs_borderchild_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_borderchild_asinterface;
    sjs_borderchild_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_borderchild_getclasstype;
    sjs_borderchild_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_borderchild_getsize;
    sjs_borderchild_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_borderchild_getsize_heap;
    sjs_borderchild_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_borderchild_getrect;
    sjs_borderchild_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_borderchild_getrect_heap;
    sjs_borderchild_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_borderchild_setrect;
    sjs_borderchild_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_borderchild_render;
    sjs_borderchild_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_borderchild_firemouseevent;
    sjs_borderlayout_element_vtbl.destroy = (void(*)(void*))sjf_borderlayout_destroy;
    sjs_borderlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_borderlayout_asinterface;
    sjs_borderlayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_borderlayout_getclasstype;
    sjs_borderlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_borderlayout_getsize;
    sjs_borderlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_borderlayout_getsize_heap;
    sjs_borderlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_borderlayout_getrect;
    sjs_borderlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_borderlayout_getrect_heap;
    sjs_borderlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_borderlayout_setrect;
    sjs_borderlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_borderlayout_render;
    sjs_borderlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_borderlayout_firemouseevent;
    sjs_boxelement_element_vtbl.destroy = (void(*)(void*))sjf_boxelement_destroy;
    sjs_boxelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_boxelement_asinterface;
    sjs_boxelement_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_boxelement_getclasstype;
    sjs_boxelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_boxelement_getsize;
    sjs_boxelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_boxelement_getsize_heap;
    sjs_boxelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_boxelement_getrect;
    sjs_boxelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_boxelement_getrect_heap;
    sjs_boxelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_boxelement_setrect;
    sjs_boxelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_boxelement_render;
    sjs_boxelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_boxelement_firemouseevent;
    sjs_centerlayout_element_vtbl.destroy = (void(*)(void*))sjf_centerlayout_destroy;
    sjs_centerlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_centerlayout_asinterface;
    sjs_centerlayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_centerlayout_getclasstype;
    sjs_centerlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_centerlayout_getsize;
    sjs_centerlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_centerlayout_getsize_heap;
    sjs_centerlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_centerlayout_getrect;
    sjs_centerlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_centerlayout_getrect_heap;
    sjs_centerlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_centerlayout_setrect;
    sjs_centerlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_centerlayout_render;
    sjs_centerlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_centerlayout_firemouseevent;
    sjs_filllayout_element_vtbl.destroy = (void(*)(void*))sjf_filllayout_destroy;
    sjs_filllayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_filllayout_asinterface;
    sjs_filllayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_filllayout_getclasstype;
    sjs_filllayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_filllayout_getsize;
    sjs_filllayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_filllayout_getsize_heap;
    sjs_filllayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_filllayout_getrect;
    sjs_filllayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_filllayout_getrect_heap;
    sjs_filllayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrect;
    sjs_filllayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_render;
    sjs_filllayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_filllayout_firemouseevent;
    sjs_flowlayout_element_vtbl.destroy = (void(*)(void*))sjf_flowlayout_destroy;
    sjs_flowlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_flowlayout_asinterface;
    sjs_flowlayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_flowlayout_getclasstype;
    sjs_flowlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_flowlayout_getsize;
    sjs_flowlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_flowlayout_getsize_heap;
    sjs_flowlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_flowlayout_getrect;
    sjs_flowlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_flowlayout_getrect_heap;
    sjs_flowlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_flowlayout_setrect;
    sjs_flowlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_flowlayout_render;
    sjs_flowlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_flowlayout_firemouseevent;
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
    sjs_listlayout_element_vtbl.destroy = (void(*)(void*))sjf_listlayout_destroy;
    sjs_listlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_listlayout_asinterface;
    sjs_listlayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_listlayout_getclasstype;
    sjs_listlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_listlayout_getsize;
    sjs_listlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_listlayout_getsize_heap;
    sjs_listlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_listlayout_getrect;
    sjs_listlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_listlayout_getrect_heap;
    sjs_listlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_listlayout_setrect;
    sjs_listlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_listlayout_render;
    sjs_listlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_listlayout_firemouseevent;
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
    sjv_loglevel_trace = 0;
    sjv_loglevel_debug = 1;
    sjv_loglevel_info = 2;
    sjv_loglevel_warn = 3;
    sjv_loglevel_error = 4;
    sjv_loglevel_fatal = 5;
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
    sjv_gldrawmode_gl_points = 0x0000;
    sjv_gldrawmode_gl_line_strip = 0x0003;
    sjv_gldrawmode_gl_line_loop = 0x0002;
    sjv_gldrawmode_gl_lines = 0x0001;
    sjv_gldrawmode_gl_triangle_strip = 0x0005;
    sjv_gldrawmode_gl_triangle_fan = 0x0006;
    sjv_gldrawmode_gl_triangles = 0x0004;
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
    result1 = -1;
    sjv_i32_maxvalue = result1 - 2147483647;
    sjv_i32_minvalue = 2147483647;
    sjv_log_includeall._refCount = -1;
    sjv_log_excludeall._refCount = 1;
    sjv_log_excludeall._refCount = 1;
    sjf_hash_type_bool(&sjv_log_excludeall);
    sjv_log._refCount = 1;
    sjv_log.minlevel = sjv_loglevel_warn;
    sjs_hash_type_bool* copyoption7 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption7 != 0) {
        sjv_log.traceincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.traceincludes, copyoption7);
    } else {
        sjv_log.traceincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption8 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption8 != 0) {
        sjv_log.debugincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.debugincludes, copyoption8);
    } else {
        sjv_log.debugincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption9 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption9 != 0) {
        sjv_log.infoincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.infoincludes, copyoption9);
    } else {
        sjv_log.infoincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption10 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption10 != 0) {
        sjv_log.warnincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.warnincludes, copyoption10);
    } else {
        sjv_log.warnincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption11 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption11 != 0) {
        sjv_log.errorincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.errorincludes, copyoption11);
    } else {
        sjv_log.errorincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption12 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption12 != 0) {
        sjv_log.fatalincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.fatalincludes, copyoption12);
    } else {
        sjv_log.fatalincludes._refCount = -1;
    }

    sjf_log(&sjv_log);
    sjv_emptystringdata = 0;
    sjv_emptystringdata = "";
    ptr_init();
    weakptr_init();
    sjv_clocks_per_sec = 0;
    sjv_clocks_per_sec = CLOCKS_PER_SEC;
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
    sjv_animator.animations.array.isglobal = false;
    sjv_animator.animations.array.count = 0;
    sjf_array_heap_iface_animation(&sjv_animator.animations.array);
    sjf_list_heap_iface_animation(&sjv_animator.animations);
    sjv_animator.current = 0;
    sjf_animator(&sjv_animator);
    sjv_blurhorizontalshader._refCount = 1;
    sjv_blurhorizontalshader.vertex._refCount = 1;
    sjv_blurhorizontalshader.vertex.count = 20;
    sjv_blurhorizontalshader.vertex.data._refCount = 1;
    sjv_blurhorizontalshader.vertex.data.datasize = 20;
    sjv_blurhorizontalshader.vertex.data.data = (void*)sjg_string1;
    sjv_blurhorizontalshader.vertex.data.isglobal = true;
    sjv_blurhorizontalshader.vertex.data.count = 20;
    sjf_array_char(&sjv_blurhorizontalshader.vertex.data);
    sjv_blurhorizontalshader.vertex._isnullterminated = false;
    sjf_string(&sjv_blurhorizontalshader.vertex);
    sjv_blurhorizontalshader.pixel._refCount = 1;
    sjv_blurhorizontalshader.pixel.count = 28;
    sjv_blurhorizontalshader.pixel.data._refCount = 1;
    sjv_blurhorizontalshader.pixel.data.datasize = 28;
    sjv_blurhorizontalshader.pixel.data.data = (void*)sjg_string2;
    sjv_blurhorizontalshader.pixel.data.isglobal = true;
    sjv_blurhorizontalshader.pixel.data.count = 28;
    sjf_array_char(&sjv_blurhorizontalshader.pixel.data);
    sjv_blurhorizontalshader.pixel._isnullterminated = false;
    sjf_string(&sjv_blurhorizontalshader.pixel);
    sjf_shader(&sjv_blurhorizontalshader);
    sjv_blurverticalshader._refCount = 1;
    sjv_blurverticalshader.vertex._refCount = 1;
    sjv_blurverticalshader.vertex.count = 20;
    sjv_blurverticalshader.vertex.data._refCount = 1;
    sjv_blurverticalshader.vertex.data.datasize = 20;
    sjv_blurverticalshader.vertex.data.data = (void*)sjg_string1;
    sjv_blurverticalshader.vertex.data.isglobal = true;
    sjv_blurverticalshader.vertex.data.count = 20;
    sjf_array_char(&sjv_blurverticalshader.vertex.data);
    sjv_blurverticalshader.vertex._isnullterminated = false;
    sjf_string(&sjv_blurverticalshader.vertex);
    sjv_blurverticalshader.pixel._refCount = 1;
    sjv_blurverticalshader.pixel.count = 26;
    sjv_blurverticalshader.pixel.data._refCount = 1;
    sjv_blurverticalshader.pixel.data.datasize = 26;
    sjv_blurverticalshader.pixel.data.data = (void*)sjg_string3;
    sjv_blurverticalshader.pixel.data.isglobal = true;
    sjv_blurverticalshader.pixel.data.count = 26;
    sjf_array_char(&sjv_blurverticalshader.pixel.data);
    sjv_blurverticalshader.pixel._isnullterminated = false;
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
    sjv_fadeshader.vertex.data.datasize = 20;
    sjv_fadeshader.vertex.data.data = (void*)sjg_string1;
    sjv_fadeshader.vertex.data.isglobal = true;
    sjv_fadeshader.vertex.data.count = 20;
    sjf_array_char(&sjv_fadeshader.vertex.data);
    sjv_fadeshader.vertex._isnullterminated = false;
    sjf_string(&sjv_fadeshader.vertex);
    sjv_fadeshader.pixel._refCount = 1;
    sjv_fadeshader.pixel.count = 17;
    sjv_fadeshader.pixel.data._refCount = 1;
    sjv_fadeshader.pixel.data.datasize = 17;
    sjv_fadeshader.pixel.data.data = (void*)sjg_string4;
    sjv_fadeshader.pixel.data.isglobal = true;
    sjv_fadeshader.pixel.data.count = 17;
    sjf_array_char(&sjv_fadeshader.pixel.data);
    sjv_fadeshader.pixel._isnullterminated = false;
    sjf_string(&sjv_fadeshader.pixel);
    sjf_shader(&sjv_fadeshader);
    sjv_fonthash._refCount = 1;
    sjf_hash_fontkey_weak_font(&sjv_fonthash);
    sjv_glviewports._refCount = 1;
    sjv_glviewports.array._refCount = 1;
    sjv_glviewports.array.datasize = 0;
    sjv_glviewports.array.data = 0;
    sjv_glviewports.array.isglobal = false;
    sjv_glviewports.array.count = 0;
    sjf_array_rect(&sjv_glviewports.array);
    sjf_list_rect(&sjv_glviewports);
    sjv_glframebuffers._refCount = 1;
    sjv_glframebuffers.array._refCount = 1;
    sjv_glframebuffers.array.datasize = 0;
    sjv_glframebuffers.array.data = 0;
    sjv_glframebuffers.array.isglobal = false;
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
    sjv_mainloop_lasttick = 0;
    sjv_mainloop_frames = 0;
    sjv_mainloop_showfps = false;
    sjv_mainloop_shouldcontinue = true;
    sjv_mouse_captureelement._parent = 0;
    sjv_boxshader._refCount = 1;
    sjv_boxshader.vertex._refCount = 1;
    sjv_boxshader.vertex.count = 20;
    sjv_boxshader.vertex.data._refCount = 1;
    sjv_boxshader.vertex.data.datasize = 20;
    sjv_boxshader.vertex.data.data = (void*)sjg_string5;
    sjv_boxshader.vertex.data.isglobal = true;
    sjv_boxshader.vertex.data.count = 20;
    sjf_array_char(&sjv_boxshader.vertex.data);
    sjv_boxshader.vertex._isnullterminated = false;
    sjf_string(&sjv_boxshader.vertex);
    sjv_boxshader.pixel._refCount = 1;
    sjv_boxshader.pixel.count = 20;
    sjv_boxshader.pixel.data._refCount = 1;
    sjv_boxshader.pixel.data.datasize = 20;
    sjv_boxshader.pixel.data.data = (void*)sjg_string6;
    sjv_boxshader.pixel.data.isglobal = true;
    sjv_boxshader.pixel.data.count = 20;
    sjf_array_char(&sjv_boxshader.pixel.data);
    sjv_boxshader.pixel._isnullterminated = false;
    sjf_string(&sjv_boxshader.pixel);
    sjf_shader(&sjv_boxshader);
    sjv_imageshader._refCount = 1;
    sjv_imageshader.vertex._refCount = 1;
    sjv_imageshader.vertex.count = 20;
    sjv_imageshader.vertex.data._refCount = 1;
    sjv_imageshader.vertex.data.datasize = 20;
    sjv_imageshader.vertex.data.data = (void*)sjg_string1;
    sjv_imageshader.vertex.data.isglobal = true;
    sjv_imageshader.vertex.data.count = 20;
    sjf_array_char(&sjv_imageshader.vertex.data);
    sjv_imageshader.vertex._isnullterminated = false;
    sjf_string(&sjv_imageshader.vertex);
    sjv_imageshader.pixel._refCount = 1;
    sjv_imageshader.pixel.count = 20;
    sjv_imageshader.pixel.data._refCount = 1;
    sjv_imageshader.pixel.data.datasize = 20;
    sjv_imageshader.pixel.data.data = (void*)sjg_string7;
    sjv_imageshader.pixel.data.isglobal = true;
    sjv_imageshader.pixel.data.count = 20;
    sjf_array_char(&sjv_imageshader.pixel.data);
    sjv_imageshader.pixel._isnullterminated = false;
    sjf_string(&sjv_imageshader.pixel);
    sjf_shader(&sjv_imageshader);
    sjv_phongcolorshader._refCount = 1;
    sjv_phongcolorshader.vertex._refCount = 1;
    sjv_phongcolorshader.vertex.count = 26;
    sjv_phongcolorshader.vertex.data._refCount = 1;
    sjv_phongcolorshader.vertex.data.datasize = 26;
    sjv_phongcolorshader.vertex.data.data = (void*)sjg_string8;
    sjv_phongcolorshader.vertex.data.isglobal = true;
    sjv_phongcolorshader.vertex.data.count = 26;
    sjf_array_char(&sjv_phongcolorshader.vertex.data);
    sjv_phongcolorshader.vertex._isnullterminated = false;
    sjf_string(&sjv_phongcolorshader.vertex);
    sjv_phongcolorshader.pixel._refCount = 1;
    sjv_phongcolorshader.pixel.count = 26;
    sjv_phongcolorshader.pixel.data._refCount = 1;
    sjv_phongcolorshader.pixel.data.datasize = 26;
    sjv_phongcolorshader.pixel.data.data = (void*)sjg_string9;
    sjv_phongcolorshader.pixel.data.isglobal = true;
    sjv_phongcolorshader.pixel.data.count = 26;
    sjf_array_char(&sjv_phongcolorshader.pixel.data);
    sjv_phongcolorshader.pixel._isnullterminated = false;
    sjf_string(&sjv_phongcolorshader.pixel);
    sjf_shader(&sjv_phongcolorshader);
    sjv_phongtextureshader._refCount = 1;
    sjv_phongtextureshader.vertex._refCount = 1;
    sjv_phongtextureshader.vertex.count = 30;
    sjv_phongtextureshader.vertex.data._refCount = 1;
    sjv_phongtextureshader.vertex.data.datasize = 30;
    sjv_phongtextureshader.vertex.data.data = (void*)sjg_string10;
    sjv_phongtextureshader.vertex.data.isglobal = true;
    sjv_phongtextureshader.vertex.data.count = 30;
    sjf_array_char(&sjv_phongtextureshader.vertex.data);
    sjv_phongtextureshader.vertex._isnullterminated = false;
    sjf_string(&sjv_phongtextureshader.vertex);
    sjv_phongtextureshader.pixel._refCount = 1;
    sjv_phongtextureshader.pixel.count = 30;
    sjv_phongtextureshader.pixel.data._refCount = 1;
    sjv_phongtextureshader.pixel.data.datasize = 30;
    sjv_phongtextureshader.pixel.data.data = (void*)sjg_string11;
    sjv_phongtextureshader.pixel.data.isglobal = true;
    sjv_phongtextureshader.pixel.data.count = 30;
    sjf_array_char(&sjv_phongtextureshader.pixel.data);
    sjv_phongtextureshader.pixel._isnullterminated = false;
    sjf_string(&sjv_phongtextureshader.pixel);
    sjf_shader(&sjv_phongtextureshader);
    sjv_textshader._refCount = 1;
    sjv_textshader.vertex._refCount = 1;
    sjv_textshader.vertex.count = 24;
    sjv_textshader.vertex.data._refCount = 1;
    sjv_textshader.vertex.data.datasize = 24;
    sjv_textshader.vertex.data.data = (void*)sjg_string12;
    sjv_textshader.vertex.data.isglobal = true;
    sjv_textshader.vertex.data.count = 24;
    sjf_array_char(&sjv_textshader.vertex.data);
    sjv_textshader.vertex._isnullterminated = false;
    sjf_string(&sjv_textshader.vertex);
    sjv_textshader.pixel._refCount = 1;
    sjv_textshader.pixel.count = 24;
    sjv_textshader.pixel.data._refCount = 1;
    sjv_textshader.pixel.data.datasize = 24;
    sjv_textshader.pixel.data.data = (void*)sjg_string13;
    sjv_textshader.pixel.data.isglobal = true;
    sjv_textshader.pixel.data.count = 24;
    sjf_array_char(&sjv_textshader.pixel.data);
    sjv_textshader.pixel._isnullterminated = false;
    sjf_string(&sjv_textshader.pixel);
    sjf_shader(&sjv_textshader);
    sjv_style._refCount = 1;
    sjf_style(&sjv_style);
    sjv_vertex_location_texture_normal_format._refCount = 1;
    sjv_vertex_location_texture_normal_format.count = 32;
    sjv_vertex_location_texture_normal_format.data._refCount = 1;
    sjv_vertex_location_texture_normal_format.data.datasize = 32;
    sjv_vertex_location_texture_normal_format.data.data = (void*)sjg_string14;
    sjv_vertex_location_texture_normal_format.data.isglobal = true;
    sjv_vertex_location_texture_normal_format.data.count = 32;
    sjf_array_char(&sjv_vertex_location_texture_normal_format.data);
    sjv_vertex_location_texture_normal_format._isnullterminated = false;
    sjf_string(&sjv_vertex_location_texture_normal_format);
    sjv_saturateshader._refCount = 1;
    sjv_saturateshader.vertex._refCount = 1;
    sjv_saturateshader.vertex.count = 20;
    sjv_saturateshader.vertex.data._refCount = 1;
    sjv_saturateshader.vertex.data.datasize = 20;
    sjv_saturateshader.vertex.data.data = (void*)sjg_string1;
    sjv_saturateshader.vertex.data.isglobal = true;
    sjv_saturateshader.vertex.data.count = 20;
    sjf_array_char(&sjv_saturateshader.vertex.data);
    sjv_saturateshader.vertex._isnullterminated = false;
    sjf_string(&sjv_saturateshader.vertex);
    sjv_saturateshader.pixel._refCount = 1;
    sjv_saturateshader.pixel.count = 21;
    sjv_saturateshader.pixel.data._refCount = 1;
    sjv_saturateshader.pixel.data.datasize = 21;
    sjv_saturateshader.pixel.data.data = (void*)sjg_string15;
    sjv_saturateshader.pixel.data.isglobal = true;
    sjv_saturateshader.pixel.data.count = 21;
    sjf_array_char(&sjv_saturateshader.pixel.data);
    sjv_saturateshader.pixel._isnullterminated = false;
    sjf_string(&sjv_saturateshader.pixel);
    sjf_shader(&sjv_saturateshader);
    sjt_call3 = (sjs_gridlayout*)malloc(sizeof(sjs_gridlayout));
    sjt_call3->_refCount = 1;
    sjt_call3->children._refCount = 1;
    sjt_call3->children.datasize = 5;
    sjt_call3->children.data = 0;
    sjt_call3->children.isglobal = false;
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
    sjt_call5->children.isglobal = false;
    sjt_call5->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call5->children);
    sjs_array_heap_iface_element* array7;
    array7 = &sjt_call5->children;
    sjt_parent29 = array7;
    sjt_functionParam41 = 0;
    sjt_call20._refCount = 1;
    sjt_call20.count = 1;
    sjt_call20.data._refCount = 1;
    sjt_call20.data.datasize = 1;
    sjt_call20.data.data = (void*)sjg_string21;
    sjt_call20.data.isglobal = true;
    sjt_call20.data.count = 1;
    sjf_array_char(&sjt_call20.data);
    sjt_call20._isnullterminated = false;
    sjf_string(&sjt_call20);
    sjt_functionParam105 = &sjt_call20;
    sjf_testelement_heap(sjt_functionParam105, &sjt_functionParam42);
    sjf_array_heap_iface_element_initat(sjt_parent29, sjt_functionParam41, sjt_functionParam42);
    sjt_parent70 = array7;
    sjt_functionParam106 = 1;
    sjt_call21._refCount = 1;
    sjt_call21.count = 1;
    sjt_call21.data._refCount = 1;
    sjt_call21.data.datasize = 1;
    sjt_call21.data.data = (void*)sjg_string22;
    sjt_call21.data.isglobal = true;
    sjt_call21.data.count = 1;
    sjf_array_char(&sjt_call21.data);
    sjt_call21._isnullterminated = false;
    sjf_string(&sjt_call21);
    sjt_functionParam108 = &sjt_call21;
    sjf_testelement_heap(sjt_functionParam108, &sjt_functionParam107);
    sjf_array_heap_iface_element_initat(sjt_parent70, sjt_functionParam106, sjt_functionParam107);
    sjt_parent71 = array7;
    sjt_functionParam109 = 2;
    sjt_call22._refCount = 1;
    sjt_call22.count = 1;
    sjt_call22.data._refCount = 1;
    sjt_call22.data.datasize = 1;
    sjt_call22.data.data = (void*)sjg_string23;
    sjt_call22.data.isglobal = true;
    sjt_call22.data.count = 1;
    sjf_array_char(&sjt_call22.data);
    sjt_call22._isnullterminated = false;
    sjf_string(&sjt_call22);
    sjt_functionParam111 = &sjt_call22;
    sjf_testelement_heap(sjt_functionParam111, &sjt_functionParam110);
    sjf_array_heap_iface_element_initat(sjt_parent71, sjt_functionParam109, sjt_functionParam110);
    sjt_parent72 = array7;
    sjt_functionParam112 = 3;
    sjt_call23._refCount = 1;
    sjt_call23.count = 1;
    sjt_call23.data._refCount = 1;
    sjt_call23.data.datasize = 1;
    sjt_call23.data.data = (void*)sjg_string24;
    sjt_call23.data.isglobal = true;
    sjt_call23.data.count = 1;
    sjf_array_char(&sjt_call23.data);
    sjt_call23._isnullterminated = false;
    sjf_string(&sjt_call23);
    sjt_functionParam114 = &sjt_call23;
    sjf_testelement_heap(sjt_functionParam114, &sjt_functionParam113);
    sjf_array_heap_iface_element_initat(sjt_parent72, sjt_functionParam112, sjt_functionParam113);
    sjt_call5->margin._refCount = 1;
    sjt_call5->margin.l = 10;
    sjt_call5->margin.t = 10;
    sjt_call5->margin.r = 10;
    sjt_call5->margin.b = 10;
    sjf_margin(&sjt_call5->margin);
    sjt_call5->cols._refCount = 1;
    sjt_call5->cols.datasize = 2;
    sjt_call5->cols.data = 0;
    sjt_call5->cols.isglobal = false;
    sjt_call5->cols.count = 0;
    sjf_array_gridunit(&sjt_call5->cols);
    sjs_array_gridunit* array4;
    array4 = &sjt_call5->cols;
    sjt_parent73 = array4;
    sjt_functionParam115 = 0;
    sjt_call24._refCount = 1;
    sjt_call24.amount = 1;
    sjt_call24.unittype = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call24);
    sjt_functionParam116 = &sjt_call24;
    sjf_array_gridunit_initat(sjt_parent73, sjt_functionParam115, sjt_functionParam116);
    sjt_parent74 = array4;
    sjt_functionParam117 = 1;
    sjt_call25._refCount = 1;
    sjt_call25.amount = 50;
    sjt_call25.unittype = sjv_gridunittype_fixed;
    sjf_gridunit(&sjt_call25);
    sjt_functionParam118 = &sjt_call25;
    sjf_array_gridunit_initat(sjt_parent74, sjt_functionParam117, sjt_functionParam118);
    sjt_call5->rows._refCount = 1;
    sjt_call5->rows.datasize = 2;
    sjt_call5->rows.data = 0;
    sjt_call5->rows.isglobal = false;
    sjt_call5->rows.count = 0;
    sjf_array_gridunit(&sjt_call5->rows);
    sjs_array_gridunit* array3;
    array3 = &sjt_call5->rows;
    sjt_parent75 = array3;
    sjt_functionParam119 = 0;
    sjt_call26._refCount = 1;
    sjt_call26.amount = 50;
    sjt_call26.unittype = sjv_gridunittype_fixed;
    sjf_gridunit(&sjt_call26);
    sjt_functionParam120 = &sjt_call26;
    sjf_array_gridunit_initat(sjt_parent75, sjt_functionParam119, sjt_functionParam120);
    sjt_parent76 = array3;
    sjt_functionParam121 = 1;
    sjt_call27._refCount = 1;
    sjt_call27.amount = 1;
    sjt_call27.unittype = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call27);
    sjt_functionParam122 = &sjt_call27;
    sjf_array_gridunit_initat(sjt_parent76, sjt_functionParam121, sjt_functionParam122);
    sjt_call5->_rect._refCount = 1;
    sjt_call5->_rect.x = 0;
    sjt_call5->_rect.y = 0;
    sjt_call5->_rect.w = 0;
    sjt_call5->_rect.h = 0;
    sjf_rect(&sjt_call5->_rect);
    sjf_gridlayout_heap(sjt_call5);
    sjt_cast4 = sjt_call5;
    sjf_gridlayout_as_sji_element(sjt_cast4, &sjt_functionParam40);
    if (sjt_functionParam40._parent != 0) {
        sjt_functionParam40._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent28, sjt_functionParam39, sjt_functionParam40);
    sjt_parent77 = array8;
    sjt_functionParam123 = 1;
    sjt_call28 = (sjs_borderlayout*)malloc(sizeof(sjs_borderlayout));
    sjt_call28->_refCount = 1;
    sjt_call28->children._refCount = 1;
    sjt_call28->children.datasize = 5;
    sjt_call28->children.data = 0;
    sjt_call28->children.isglobal = false;
    sjt_call28->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call28->children);
    sjs_array_heap_iface_element* array9;
    array9 = &sjt_call28->children;
    sjt_parent94 = array9;
    sjt_functionParam130 = 0;
    sjt_call34 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
    sjt_call34->_refCount = 1;
    sjt_call35._refCount = 1;
    sjt_call35.count = 4;
    sjt_call35.data._refCount = 1;
    sjt_call35.data.datasize = 4;
    sjt_call35.data.data = (void*)sjg_string25;
    sjt_call35.data.isglobal = true;
    sjt_call35.data.count = 4;
    sjf_array_char(&sjt_call35.data);
    sjt_call35._isnullterminated = false;
    sjf_string(&sjt_call35);
    sjt_functionParam132 = &sjt_call35;
    sjf_testelement_heap(sjt_functionParam132, &sjt_call34->child);
    sjt_call34->position = sjv_borderposition_left;
    sjt_call34->_rect._refCount = 1;
    sjt_call34->_rect.x = 0;
    sjt_call34->_rect.y = 0;
    sjt_call34->_rect.w = 0;
    sjt_call34->_rect.h = 0;
    sjf_rect(&sjt_call34->_rect);
    sjf_borderchild_heap(sjt_call34);
    sjt_cast12 = sjt_call34;
    sjf_borderchild_as_sji_element(sjt_cast12, &sjt_functionParam131);
    if (sjt_functionParam131._parent != 0) {
        sjt_functionParam131._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent94, sjt_functionParam130, sjt_functionParam131);
    sjt_parent100 = array9;
    sjt_functionParam133 = 1;
    sjt_call36 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
    sjt_call36->_refCount = 1;
    sjt_call37._refCount = 1;
    sjt_call37.count = 6;
    sjt_call37.data._refCount = 1;
    sjt_call37.data.datasize = 6;
    sjt_call37.data.data = (void*)sjg_string26;
    sjt_call37.data.isglobal = true;
    sjt_call37.data.count = 6;
    sjf_array_char(&sjt_call37.data);
    sjt_call37._isnullterminated = false;
    sjf_string(&sjt_call37);
    sjt_functionParam135 = &sjt_call37;
    sjf_testelement_heap(sjt_functionParam135, &sjt_call36->child);
    sjt_call36->position = sjv_borderposition_bottom;
    sjt_call36->_rect._refCount = 1;
    sjt_call36->_rect.x = 0;
    sjt_call36->_rect.y = 0;
    sjt_call36->_rect.w = 0;
    sjt_call36->_rect.h = 0;
    sjf_rect(&sjt_call36->_rect);
    sjf_borderchild_heap(sjt_call36);
    sjt_cast13 = sjt_call36;
    sjf_borderchild_as_sji_element(sjt_cast13, &sjt_functionParam134);
    if (sjt_functionParam134._parent != 0) {
        sjt_functionParam134._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent100, sjt_functionParam133, sjt_functionParam134);
    sjt_parent101 = array9;
    sjt_functionParam136 = 2;
    sjt_call38 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
    sjt_call38->_refCount = 1;
    sjt_call39._refCount = 1;
    sjt_call39.count = 3;
    sjt_call39.data._refCount = 1;
    sjt_call39.data.datasize = 3;
    sjt_call39.data.data = (void*)sjg_string27;
    sjt_call39.data.isglobal = true;
    sjt_call39.data.count = 3;
    sjf_array_char(&sjt_call39.data);
    sjt_call39._isnullterminated = false;
    sjf_string(&sjt_call39);
    sjt_functionParam138 = &sjt_call39;
    sjf_testelement_heap(sjt_functionParam138, &sjt_call38->child);
    sjt_call38->position = sjv_borderposition_top;
    sjt_call38->_rect._refCount = 1;
    sjt_call38->_rect.x = 0;
    sjt_call38->_rect.y = 0;
    sjt_call38->_rect.w = 0;
    sjt_call38->_rect.h = 0;
    sjf_rect(&sjt_call38->_rect);
    sjf_borderchild_heap(sjt_call38);
    sjt_cast14 = sjt_call38;
    sjf_borderchild_as_sji_element(sjt_cast14, &sjt_functionParam137);
    if (sjt_functionParam137._parent != 0) {
        sjt_functionParam137._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent101, sjt_functionParam136, sjt_functionParam137);
    sjt_parent102 = array9;
    sjt_functionParam139 = 3;
    sjt_call40 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
    sjt_call40->_refCount = 1;
    sjt_call41._refCount = 1;
    sjt_call41.count = 5;
    sjt_call41.data._refCount = 1;
    sjt_call41.data.datasize = 5;
    sjt_call41.data.data = (void*)sjg_string28;
    sjt_call41.data.isglobal = true;
    sjt_call41.data.count = 5;
    sjf_array_char(&sjt_call41.data);
    sjt_call41._isnullterminated = false;
    sjf_string(&sjt_call41);
    sjt_functionParam141 = &sjt_call41;
    sjf_testelement_heap(sjt_functionParam141, &sjt_call40->child);
    sjt_call40->position = sjv_borderposition_right;
    sjt_call40->_rect._refCount = 1;
    sjt_call40->_rect.x = 0;
    sjt_call40->_rect.y = 0;
    sjt_call40->_rect.w = 0;
    sjt_call40->_rect.h = 0;
    sjf_rect(&sjt_call40->_rect);
    sjf_borderchild_heap(sjt_call40);
    sjt_cast15 = sjt_call40;
    sjf_borderchild_as_sji_element(sjt_cast15, &sjt_functionParam140);
    if (sjt_functionParam140._parent != 0) {
        sjt_functionParam140._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent102, sjt_functionParam139, sjt_functionParam140);
    sjt_parent103 = array9;
    sjt_functionParam142 = 4;
    sjt_call42 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
    sjt_call42->_refCount = 1;
    sjt_call43._refCount = 1;
    sjt_call43.count = 4;
    sjt_call43.data._refCount = 1;
    sjt_call43.data.datasize = 4;
    sjt_call43.data.data = (void*)sjg_string29;
    sjt_call43.data.isglobal = true;
    sjt_call43.data.count = 4;
    sjf_array_char(&sjt_call43.data);
    sjt_call43._isnullterminated = false;
    sjf_string(&sjt_call43);
    sjt_functionParam144 = &sjt_call43;
    sjf_testelement_heap(sjt_functionParam144, &sjt_call42->child);
    sjt_call42->position = sjv_borderposition_fill;
    sjt_call42->_rect._refCount = 1;
    sjt_call42->_rect.x = 0;
    sjt_call42->_rect.y = 0;
    sjt_call42->_rect.w = 0;
    sjt_call42->_rect.h = 0;
    sjf_rect(&sjt_call42->_rect);
    sjf_borderchild_heap(sjt_call42);
    sjt_cast16 = sjt_call42;
    sjf_borderchild_as_sji_element(sjt_cast16, &sjt_functionParam143);
    if (sjt_functionParam143._parent != 0) {
        sjt_functionParam143._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent103, sjt_functionParam142, sjt_functionParam143);
    sjt_call28->margin._refCount = 1;
    sjt_call28->margin.l = 10;
    sjt_call28->margin.t = 10;
    sjt_call28->margin.r = 10;
    sjt_call28->margin.b = 10;
    sjf_margin(&sjt_call28->margin);
    sjt_call28->_rect._refCount = 1;
    sjt_call28->_rect.x = 0;
    sjt_call28->_rect.y = 0;
    sjt_call28->_rect.w = 0;
    sjt_call28->_rect.h = 0;
    sjf_rect(&sjt_call28->_rect);
    sjf_borderlayout_heap(sjt_call28);
    sjt_cast9 = sjt_call28;
    sjf_borderlayout_as_sji_element(sjt_cast9, &sjt_functionParam124);
    if (sjt_functionParam124._parent != 0) {
        sjt_functionParam124._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent77, sjt_functionParam123, sjt_functionParam124);
    sjt_parent104 = array8;
    sjt_functionParam145 = 2;
    sjt_call44 = (sjs_listlayout*)malloc(sizeof(sjs_listlayout));
    sjt_call44->_refCount = 1;
    sjt_call44->children._refCount = 1;
    sjt_call44->children.datasize = 4;
    sjt_call44->children.data = 0;
    sjt_call44->children.isglobal = false;
    sjt_call44->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call44->children);
    sjs_array_heap_iface_element* array10;
    array10 = &sjt_call44->children;
    sjt_parent118 = array10;
    sjt_functionParam151 = 0;
    sjt_call53._refCount = 1;
    sjt_call53.count = 1;
    sjt_call53.data._refCount = 1;
    sjt_call53.data.datasize = 1;
    sjt_call53.data.data = (void*)sjg_string21;
    sjt_call53.data.isglobal = true;
    sjt_call53.data.count = 1;
    sjf_array_char(&sjt_call53.data);
    sjt_call53._isnullterminated = false;
    sjf_string(&sjt_call53);
    sjt_functionParam153 = &sjt_call53;
    sjf_testelement_heap(sjt_functionParam153, &sjt_functionParam152);
    sjf_array_heap_iface_element_initat(sjt_parent118, sjt_functionParam151, sjt_functionParam152);
    sjt_parent119 = array10;
    sjt_functionParam154 = 1;
    sjt_call54._refCount = 1;
    sjt_call54.count = 1;
    sjt_call54.data._refCount = 1;
    sjt_call54.data.datasize = 1;
    sjt_call54.data.data = (void*)sjg_string22;
    sjt_call54.data.isglobal = true;
    sjt_call54.data.count = 1;
    sjf_array_char(&sjt_call54.data);
    sjt_call54._isnullterminated = false;
    sjf_string(&sjt_call54);
    sjt_functionParam156 = &sjt_call54;
    sjf_testelement_heap(sjt_functionParam156, &sjt_functionParam155);
    sjf_array_heap_iface_element_initat(sjt_parent119, sjt_functionParam154, sjt_functionParam155);
    sjt_parent120 = array10;
    sjt_functionParam157 = 2;
    sjt_call55._refCount = 1;
    sjt_call55.count = 1;
    sjt_call55.data._refCount = 1;
    sjt_call55.data.datasize = 1;
    sjt_call55.data.data = (void*)sjg_string23;
    sjt_call55.data.isglobal = true;
    sjt_call55.data.count = 1;
    sjf_array_char(&sjt_call55.data);
    sjt_call55._isnullterminated = false;
    sjf_string(&sjt_call55);
    sjt_functionParam159 = &sjt_call55;
    sjf_testelement_heap(sjt_functionParam159, &sjt_functionParam158);
    sjf_array_heap_iface_element_initat(sjt_parent120, sjt_functionParam157, sjt_functionParam158);
    sjt_parent121 = array10;
    sjt_functionParam160 = 3;
    sjt_call56._refCount = 1;
    sjt_call56.count = 1;
    sjt_call56.data._refCount = 1;
    sjt_call56.data.datasize = 1;
    sjt_call56.data.data = (void*)sjg_string24;
    sjt_call56.data.isglobal = true;
    sjt_call56.data.count = 1;
    sjf_array_char(&sjt_call56.data);
    sjt_call56._isnullterminated = false;
    sjf_string(&sjt_call56);
    sjt_functionParam162 = &sjt_call56;
    sjf_testelement_heap(sjt_functionParam162, &sjt_functionParam161);
    sjf_array_heap_iface_element_initat(sjt_parent121, sjt_functionParam160, sjt_functionParam161);
    sjt_call44->margin._refCount = 1;
    sjt_call44->margin.l = 10;
    sjt_call44->margin.t = 10;
    sjt_call44->margin.r = 10;
    sjt_call44->margin.b = 10;
    sjf_margin(&sjt_call44->margin);
    sjt_call44->orientation = sjv_listlayoutorientation_leftright;
    sjt_call44->_rect._refCount = 1;
    sjt_call44->_rect.x = 0;
    sjt_call44->_rect.y = 0;
    sjt_call44->_rect.w = 0;
    sjt_call44->_rect.h = 0;
    sjf_rect(&sjt_call44->_rect);
    sjf_listlayout_heap(sjt_call44);
    sjt_cast17 = sjt_call44;
    sjf_listlayout_as_sji_element(sjt_cast17, &sjt_functionParam146);
    if (sjt_functionParam146._parent != 0) {
        sjt_functionParam146._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent104, sjt_functionParam145, sjt_functionParam146);
    sjt_parent122 = array8;
    sjt_functionParam163 = 3;
    sjt_call57 = (sjs_flowlayout*)malloc(sizeof(sjs_flowlayout));
    sjt_call57->_refCount = 1;
    sjt_call57->children._refCount = 1;
    sjt_call57->children.datasize = 20;
    sjt_call57->children.data = 0;
    sjt_call57->children.isglobal = false;
    sjt_call57->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call57->children);
    sjs_array_heap_iface_element* array11;
    array11 = &sjt_call57->children;
    sjt_parent136 = array11;
    sjt_functionParam177 = 0;
    sjt_call66._refCount = 1;
    sjt_call66.count = 1;
    sjt_call66.data._refCount = 1;
    sjt_call66.data.datasize = 1;
    sjt_call66.data.data = (void*)sjg_string21;
    sjt_call66.data.isglobal = true;
    sjt_call66.data.count = 1;
    sjf_array_char(&sjt_call66.data);
    sjt_call66._isnullterminated = false;
    sjf_string(&sjt_call66);
    sjt_functionParam179 = &sjt_call66;
    sjf_testelement_heap(sjt_functionParam179, &sjt_functionParam178);
    sjf_array_heap_iface_element_initat(sjt_parent136, sjt_functionParam177, sjt_functionParam178);
    sjt_parent137 = array11;
    sjt_functionParam180 = 1;
    sjt_call67._refCount = 1;
    sjt_call67.count = 1;
    sjt_call67.data._refCount = 1;
    sjt_call67.data.datasize = 1;
    sjt_call67.data.data = (void*)sjg_string22;
    sjt_call67.data.isglobal = true;
    sjt_call67.data.count = 1;
    sjf_array_char(&sjt_call67.data);
    sjt_call67._isnullterminated = false;
    sjf_string(&sjt_call67);
    sjt_functionParam182 = &sjt_call67;
    sjf_testelement_heap(sjt_functionParam182, &sjt_functionParam181);
    sjf_array_heap_iface_element_initat(sjt_parent137, sjt_functionParam180, sjt_functionParam181);
    sjt_parent138 = array11;
    sjt_functionParam183 = 2;
    sjt_call68._refCount = 1;
    sjt_call68.count = 1;
    sjt_call68.data._refCount = 1;
    sjt_call68.data.datasize = 1;
    sjt_call68.data.data = (void*)sjg_string23;
    sjt_call68.data.isglobal = true;
    sjt_call68.data.count = 1;
    sjf_array_char(&sjt_call68.data);
    sjt_call68._isnullterminated = false;
    sjf_string(&sjt_call68);
    sjt_functionParam185 = &sjt_call68;
    sjf_testelement_heap(sjt_functionParam185, &sjt_functionParam184);
    sjf_array_heap_iface_element_initat(sjt_parent138, sjt_functionParam183, sjt_functionParam184);
    sjt_parent139 = array11;
    sjt_functionParam186 = 3;
    sjt_call69._refCount = 1;
    sjt_call69.count = 1;
    sjt_call69.data._refCount = 1;
    sjt_call69.data.datasize = 1;
    sjt_call69.data.data = (void*)sjg_string24;
    sjt_call69.data.isglobal = true;
    sjt_call69.data.count = 1;
    sjf_array_char(&sjt_call69.data);
    sjt_call69._isnullterminated = false;
    sjf_string(&sjt_call69);
    sjt_functionParam188 = &sjt_call69;
    sjf_testelement_heap(sjt_functionParam188, &sjt_functionParam187);
    sjf_array_heap_iface_element_initat(sjt_parent139, sjt_functionParam186, sjt_functionParam187);
    sjt_parent140 = array11;
    sjt_functionParam189 = 4;
    sjt_call70._refCount = 1;
    sjt_call70.count = 1;
    sjt_call70.data._refCount = 1;
    sjt_call70.data.datasize = 1;
    sjt_call70.data.data = (void*)sjg_string21;
    sjt_call70.data.isglobal = true;
    sjt_call70.data.count = 1;
    sjf_array_char(&sjt_call70.data);
    sjt_call70._isnullterminated = false;
    sjf_string(&sjt_call70);
    sjt_functionParam191 = &sjt_call70;
    sjf_testelement_heap(sjt_functionParam191, &sjt_functionParam190);
    sjf_array_heap_iface_element_initat(sjt_parent140, sjt_functionParam189, sjt_functionParam190);
    sjt_parent141 = array11;
    sjt_functionParam192 = 5;
    sjt_call71._refCount = 1;
    sjt_call71.count = 1;
    sjt_call71.data._refCount = 1;
    sjt_call71.data.datasize = 1;
    sjt_call71.data.data = (void*)sjg_string22;
    sjt_call71.data.isglobal = true;
    sjt_call71.data.count = 1;
    sjf_array_char(&sjt_call71.data);
    sjt_call71._isnullterminated = false;
    sjf_string(&sjt_call71);
    sjt_functionParam194 = &sjt_call71;
    sjf_testelement_heap(sjt_functionParam194, &sjt_functionParam193);
    sjf_array_heap_iface_element_initat(sjt_parent141, sjt_functionParam192, sjt_functionParam193);
    sjt_parent142 = array11;
    sjt_functionParam195 = 6;
    sjt_call72._refCount = 1;
    sjt_call72.count = 1;
    sjt_call72.data._refCount = 1;
    sjt_call72.data.datasize = 1;
    sjt_call72.data.data = (void*)sjg_string23;
    sjt_call72.data.isglobal = true;
    sjt_call72.data.count = 1;
    sjf_array_char(&sjt_call72.data);
    sjt_call72._isnullterminated = false;
    sjf_string(&sjt_call72);
    sjt_functionParam197 = &sjt_call72;
    sjf_testelement_heap(sjt_functionParam197, &sjt_functionParam196);
    sjf_array_heap_iface_element_initat(sjt_parent142, sjt_functionParam195, sjt_functionParam196);
    sjt_parent143 = array11;
    sjt_functionParam198 = 7;
    sjt_call73._refCount = 1;
    sjt_call73.count = 1;
    sjt_call73.data._refCount = 1;
    sjt_call73.data.datasize = 1;
    sjt_call73.data.data = (void*)sjg_string24;
    sjt_call73.data.isglobal = true;
    sjt_call73.data.count = 1;
    sjf_array_char(&sjt_call73.data);
    sjt_call73._isnullterminated = false;
    sjf_string(&sjt_call73);
    sjt_functionParam200 = &sjt_call73;
    sjf_testelement_heap(sjt_functionParam200, &sjt_functionParam199);
    sjf_array_heap_iface_element_initat(sjt_parent143, sjt_functionParam198, sjt_functionParam199);
    sjt_parent144 = array11;
    sjt_functionParam201 = 8;
    sjt_call74._refCount = 1;
    sjt_call74.count = 1;
    sjt_call74.data._refCount = 1;
    sjt_call74.data.datasize = 1;
    sjt_call74.data.data = (void*)sjg_string21;
    sjt_call74.data.isglobal = true;
    sjt_call74.data.count = 1;
    sjf_array_char(&sjt_call74.data);
    sjt_call74._isnullterminated = false;
    sjf_string(&sjt_call74);
    sjt_functionParam203 = &sjt_call74;
    sjf_testelement_heap(sjt_functionParam203, &sjt_functionParam202);
    sjf_array_heap_iface_element_initat(sjt_parent144, sjt_functionParam201, sjt_functionParam202);
    sjt_parent145 = array11;
    sjt_functionParam204 = 9;
    sjt_call75._refCount = 1;
    sjt_call75.count = 1;
    sjt_call75.data._refCount = 1;
    sjt_call75.data.datasize = 1;
    sjt_call75.data.data = (void*)sjg_string22;
    sjt_call75.data.isglobal = true;
    sjt_call75.data.count = 1;
    sjf_array_char(&sjt_call75.data);
    sjt_call75._isnullterminated = false;
    sjf_string(&sjt_call75);
    sjt_functionParam206 = &sjt_call75;
    sjf_testelement_heap(sjt_functionParam206, &sjt_functionParam205);
    sjf_array_heap_iface_element_initat(sjt_parent145, sjt_functionParam204, sjt_functionParam205);
    sjt_parent146 = array11;
    sjt_functionParam207 = 10;
    sjt_call76._refCount = 1;
    sjt_call76.count = 1;
    sjt_call76.data._refCount = 1;
    sjt_call76.data.datasize = 1;
    sjt_call76.data.data = (void*)sjg_string23;
    sjt_call76.data.isglobal = true;
    sjt_call76.data.count = 1;
    sjf_array_char(&sjt_call76.data);
    sjt_call76._isnullterminated = false;
    sjf_string(&sjt_call76);
    sjt_functionParam209 = &sjt_call76;
    sjf_testelement_heap(sjt_functionParam209, &sjt_functionParam208);
    sjf_array_heap_iface_element_initat(sjt_parent146, sjt_functionParam207, sjt_functionParam208);
    sjt_parent147 = array11;
    sjt_functionParam210 = 11;
    sjt_call77._refCount = 1;
    sjt_call77.count = 1;
    sjt_call77.data._refCount = 1;
    sjt_call77.data.datasize = 1;
    sjt_call77.data.data = (void*)sjg_string24;
    sjt_call77.data.isglobal = true;
    sjt_call77.data.count = 1;
    sjf_array_char(&sjt_call77.data);
    sjt_call77._isnullterminated = false;
    sjf_string(&sjt_call77);
    sjt_functionParam212 = &sjt_call77;
    sjf_testelement_heap(sjt_functionParam212, &sjt_functionParam211);
    sjf_array_heap_iface_element_initat(sjt_parent147, sjt_functionParam210, sjt_functionParam211);
    sjt_parent148 = array11;
    sjt_functionParam213 = 12;
    sjt_call78._refCount = 1;
    sjt_call78.count = 1;
    sjt_call78.data._refCount = 1;
    sjt_call78.data.datasize = 1;
    sjt_call78.data.data = (void*)sjg_string21;
    sjt_call78.data.isglobal = true;
    sjt_call78.data.count = 1;
    sjf_array_char(&sjt_call78.data);
    sjt_call78._isnullterminated = false;
    sjf_string(&sjt_call78);
    sjt_functionParam215 = &sjt_call78;
    sjf_testelement_heap(sjt_functionParam215, &sjt_functionParam214);
    sjf_array_heap_iface_element_initat(sjt_parent148, sjt_functionParam213, sjt_functionParam214);
    sjt_parent149 = array11;
    sjt_functionParam216 = 13;
    sjt_call79._refCount = 1;
    sjt_call79.count = 1;
    sjt_call79.data._refCount = 1;
    sjt_call79.data.datasize = 1;
    sjt_call79.data.data = (void*)sjg_string22;
    sjt_call79.data.isglobal = true;
    sjt_call79.data.count = 1;
    sjf_array_char(&sjt_call79.data);
    sjt_call79._isnullterminated = false;
    sjf_string(&sjt_call79);
    sjt_functionParam218 = &sjt_call79;
    sjf_testelement_heap(sjt_functionParam218, &sjt_functionParam217);
    sjf_array_heap_iface_element_initat(sjt_parent149, sjt_functionParam216, sjt_functionParam217);
    sjt_parent150 = array11;
    sjt_functionParam219 = 14;
    sjt_call80._refCount = 1;
    sjt_call80.count = 1;
    sjt_call80.data._refCount = 1;
    sjt_call80.data.datasize = 1;
    sjt_call80.data.data = (void*)sjg_string23;
    sjt_call80.data.isglobal = true;
    sjt_call80.data.count = 1;
    sjf_array_char(&sjt_call80.data);
    sjt_call80._isnullterminated = false;
    sjf_string(&sjt_call80);
    sjt_functionParam221 = &sjt_call80;
    sjf_testelement_heap(sjt_functionParam221, &sjt_functionParam220);
    sjf_array_heap_iface_element_initat(sjt_parent150, sjt_functionParam219, sjt_functionParam220);
    sjt_parent151 = array11;
    sjt_functionParam222 = 15;
    sjt_call81._refCount = 1;
    sjt_call81.count = 1;
    sjt_call81.data._refCount = 1;
    sjt_call81.data.datasize = 1;
    sjt_call81.data.data = (void*)sjg_string24;
    sjt_call81.data.isglobal = true;
    sjt_call81.data.count = 1;
    sjf_array_char(&sjt_call81.data);
    sjt_call81._isnullterminated = false;
    sjf_string(&sjt_call81);
    sjt_functionParam224 = &sjt_call81;
    sjf_testelement_heap(sjt_functionParam224, &sjt_functionParam223);
    sjf_array_heap_iface_element_initat(sjt_parent151, sjt_functionParam222, sjt_functionParam223);
    sjt_parent152 = array11;
    sjt_functionParam225 = 16;
    sjt_call82._refCount = 1;
    sjt_call82.count = 1;
    sjt_call82.data._refCount = 1;
    sjt_call82.data.datasize = 1;
    sjt_call82.data.data = (void*)sjg_string21;
    sjt_call82.data.isglobal = true;
    sjt_call82.data.count = 1;
    sjf_array_char(&sjt_call82.data);
    sjt_call82._isnullterminated = false;
    sjf_string(&sjt_call82);
    sjt_functionParam227 = &sjt_call82;
    sjf_testelement_heap(sjt_functionParam227, &sjt_functionParam226);
    sjf_array_heap_iface_element_initat(sjt_parent152, sjt_functionParam225, sjt_functionParam226);
    sjt_parent153 = array11;
    sjt_functionParam228 = 17;
    sjt_call83._refCount = 1;
    sjt_call83.count = 1;
    sjt_call83.data._refCount = 1;
    sjt_call83.data.datasize = 1;
    sjt_call83.data.data = (void*)sjg_string22;
    sjt_call83.data.isglobal = true;
    sjt_call83.data.count = 1;
    sjf_array_char(&sjt_call83.data);
    sjt_call83._isnullterminated = false;
    sjf_string(&sjt_call83);
    sjt_functionParam230 = &sjt_call83;
    sjf_testelement_heap(sjt_functionParam230, &sjt_functionParam229);
    sjf_array_heap_iface_element_initat(sjt_parent153, sjt_functionParam228, sjt_functionParam229);
    sjt_parent154 = array11;
    sjt_functionParam231 = 18;
    sjt_call84._refCount = 1;
    sjt_call84.count = 1;
    sjt_call84.data._refCount = 1;
    sjt_call84.data.datasize = 1;
    sjt_call84.data.data = (void*)sjg_string23;
    sjt_call84.data.isglobal = true;
    sjt_call84.data.count = 1;
    sjf_array_char(&sjt_call84.data);
    sjt_call84._isnullterminated = false;
    sjf_string(&sjt_call84);
    sjt_functionParam233 = &sjt_call84;
    sjf_testelement_heap(sjt_functionParam233, &sjt_functionParam232);
    sjf_array_heap_iface_element_initat(sjt_parent154, sjt_functionParam231, sjt_functionParam232);
    sjt_parent155 = array11;
    sjt_functionParam234 = 19;
    sjt_call85._refCount = 1;
    sjt_call85.count = 1;
    sjt_call85.data._refCount = 1;
    sjt_call85.data.datasize = 1;
    sjt_call85.data.data = (void*)sjg_string24;
    sjt_call85.data.isglobal = true;
    sjt_call85.data.count = 1;
    sjf_array_char(&sjt_call85.data);
    sjt_call85._isnullterminated = false;
    sjf_string(&sjt_call85);
    sjt_functionParam236 = &sjt_call85;
    sjf_testelement_heap(sjt_functionParam236, &sjt_functionParam235);
    sjf_array_heap_iface_element_initat(sjt_parent155, sjt_functionParam234, sjt_functionParam235);
    sjt_call57->margin._refCount = 1;
    sjt_call57->margin.l = 10;
    sjt_call57->margin.t = 10;
    sjt_call57->margin.r = 10;
    sjt_call57->margin.b = 10;
    sjf_margin(&sjt_call57->margin);
    sjt_call57->orientation = sjv_flowlayoutorientation_leftright;
    sjt_call57->_rect._refCount = 1;
    sjt_call57->_rect.x = 0;
    sjt_call57->_rect.y = 0;
    sjt_call57->_rect.w = 0;
    sjt_call57->_rect.h = 0;
    sjf_rect(&sjt_call57->_rect);
    sjf_flowlayout_heap(sjt_call57);
    sjt_cast18 = sjt_call57;
    sjf_flowlayout_as_sji_element(sjt_cast18, &sjt_functionParam164);
    if (sjt_functionParam164._parent != 0) {
        sjt_functionParam164._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent122, sjt_functionParam163, sjt_functionParam164);
    sjt_parent156 = array8;
    sjt_functionParam237 = 4;
    sjt_call86 = (sjs_centerlayout*)malloc(sizeof(sjs_centerlayout));
    sjt_call86->_refCount = 1;
    sjt_call86->children._refCount = 1;
    sjt_call86->children.datasize = 1;
    sjt_call86->children.data = 0;
    sjt_call86->children.isglobal = false;
    sjt_call86->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call86->children);
    sjs_array_heap_iface_element* array12;
    array12 = &sjt_call86->children;
    sjt_parent174 = array12;
    sjt_functionParam251 = 0;
    sjt_call91._refCount = 1;
    sjt_call91.count = 1;
    sjt_call91.data._refCount = 1;
    sjt_call91.data.datasize = 1;
    sjt_call91.data.data = (void*)sjg_string21;
    sjt_call91.data.isglobal = true;
    sjt_call91.data.count = 1;
    sjf_array_char(&sjt_call91.data);
    sjt_call91._isnullterminated = false;
    sjf_string(&sjt_call91);
    sjt_functionParam253 = &sjt_call91;
    sjf_testelement_heap(sjt_functionParam253, &sjt_functionParam252);
    sjf_array_heap_iface_element_initat(sjt_parent174, sjt_functionParam251, sjt_functionParam252);
    sjt_call86->margin._refCount = 1;
    sjt_call86->margin.l = 10;
    sjt_call86->margin.t = 10;
    sjt_call86->margin.r = 10;
    sjt_call86->margin.b = 10;
    sjf_margin(&sjt_call86->margin);
    sjt_value5 = 0.2f;
    value5.isvalid = true;
    value5.value = sjt_value5;
    sjt_call86->centerx = value5;
    sjt_value6 = 0.8f;
    value6.isvalid = true;
    value6.value = sjt_value6;
    sjt_call86->centery = value6;
    sjt_call86->_rect._refCount = 1;
    sjt_call86->_rect.x = 0;
    sjt_call86->_rect.y = 0;
    sjt_call86->_rect.w = 0;
    sjt_call86->_rect.h = 0;
    sjf_rect(&sjt_call86->_rect);
    sjf_centerlayout_heap(sjt_call86);
    sjt_cast19 = sjt_call86;
    sjf_centerlayout_as_sji_element(sjt_cast19, &sjt_functionParam238);
    if (sjt_functionParam238._parent != 0) {
        sjt_functionParam238._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent156, sjt_functionParam237, sjt_functionParam238);
    sjt_call3->margin._refCount = 1;
    sjt_call3->margin.l = 0;
    sjt_call3->margin.t = 0;
    sjt_call3->margin.r = 0;
    sjt_call3->margin.b = 0;
    sjf_margin(&sjt_call3->margin);
    sjt_call3->cols._refCount = 1;
    sjt_call3->cols.datasize = 3;
    sjt_call3->cols.data = 0;
    sjt_call3->cols.isglobal = false;
    sjt_call3->cols.count = 0;
    sjf_array_gridunit(&sjt_call3->cols);
    sjs_array_gridunit* array1;
    array1 = &sjt_call3->cols;
    sjt_parent175 = array1;
    sjt_functionParam254 = 0;
    sjt_call92._refCount = 1;
    sjt_call92.amount = 1;
    sjt_call92.unittype = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call92);
    sjt_functionParam255 = &sjt_call92;
    sjf_array_gridunit_initat(sjt_parent175, sjt_functionParam254, sjt_functionParam255);
    sjt_parent176 = array1;
    sjt_functionParam256 = 1;
    sjt_call93._refCount = 1;
    sjt_call93.amount = 1;
    sjt_call93.unittype = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call93);
    sjt_functionParam257 = &sjt_call93;
    sjf_array_gridunit_initat(sjt_parent176, sjt_functionParam256, sjt_functionParam257);
    sjt_parent177 = array1;
    sjt_functionParam258 = 2;
    sjt_call94._refCount = 1;
    sjt_call94.amount = 1;
    sjt_call94.unittype = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call94);
    sjt_functionParam259 = &sjt_call94;
    sjf_array_gridunit_initat(sjt_parent177, sjt_functionParam258, sjt_functionParam259);
    sjt_call3->rows._refCount = 1;
    sjt_call3->rows.datasize = 2;
    sjt_call3->rows.data = 0;
    sjt_call3->rows.isglobal = false;
    sjt_call3->rows.count = 0;
    sjf_array_gridunit(&sjt_call3->rows);
    sjs_array_gridunit* array2;
    array2 = &sjt_call3->rows;
    sjt_parent178 = array2;
    sjt_functionParam260 = 0;
    sjt_call95._refCount = 1;
    sjt_call95.amount = 1;
    sjt_call95.unittype = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call95);
    sjt_functionParam261 = &sjt_call95;
    sjf_array_gridunit_initat(sjt_parent178, sjt_functionParam260, sjt_functionParam261);
    sjt_parent179 = array2;
    sjt_functionParam262 = 1;
    sjt_call96._refCount = 1;
    sjt_call96.amount = 1;
    sjt_call96.unittype = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call96);
    sjt_functionParam263 = &sjt_call96;
    sjf_array_gridunit_initat(sjt_parent179, sjt_functionParam262, sjt_functionParam263);
    sjt_call3->_rect._refCount = 1;
    sjt_call3->_rect.x = 0;
    sjt_call3->_rect.y = 0;
    sjt_call3->_rect.w = 0;
    sjt_call3->_rect.h = 0;
    sjf_rect(&sjt_call3->_rect);
    sjf_gridlayout_heap(sjt_call3);
    sjt_cast2 = sjt_call3;
    sjf_gridlayout_as_sji_element(sjt_cast2, &sjv_root);
    if (sjv_root._parent != 0) {
        sjv_root._parent->_refCount++;
    }

    sjf_runloop();
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_call28->_refCount--;
    if (sjt_call28->_refCount <= 0) {
        weakptr_release(sjt_call28);
        sjf_borderlayout_destroy(sjt_call28);
        free(sjt_call28);
    }
    sjt_call3->_refCount--;
    if (sjt_call3->_refCount <= 0) {
        weakptr_release(sjt_call3);
        sjf_gridlayout_destroy(sjt_call3);
        free(sjt_call3);
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
        sjf_borderchild_destroy(sjt_call42);
        free(sjt_call42);
    }
    sjt_call44->_refCount--;
    if (sjt_call44->_refCount <= 0) {
        weakptr_release(sjt_call44);
        sjf_listlayout_destroy(sjt_call44);
        free(sjt_call44);
    }
    sjt_call5->_refCount--;
    if (sjt_call5->_refCount <= 0) {
        weakptr_release(sjt_call5);
        sjf_gridlayout_destroy(sjt_call5);
        free(sjt_call5);
    }
    sjt_call57->_refCount--;
    if (sjt_call57->_refCount <= 0) {
        weakptr_release(sjt_call57);
        sjf_flowlayout_destroy(sjt_call57);
        free(sjt_call57);
    }
    sjt_call86->_refCount--;
    if (sjt_call86->_refCount <= 0) {
        weakptr_release(sjt_call86);
        sjf_centerlayout_destroy(sjt_call86);
        free(sjt_call86);
    }
    if (sjt_functionParam107._parent != 0) {
        sjt_functionParam107._parent->_refCount--;
        if (sjt_functionParam107._parent->_refCount <= 0) {
            sjt_functionParam107._vtbl->destroy(sjt_functionParam107._parent);
            free(sjt_functionParam107._parent);
        }
    }
    if (sjt_functionParam110._parent != 0) {
        sjt_functionParam110._parent->_refCount--;
        if (sjt_functionParam110._parent->_refCount <= 0) {
            sjt_functionParam110._vtbl->destroy(sjt_functionParam110._parent);
            free(sjt_functionParam110._parent);
        }
    }
    if (sjt_functionParam113._parent != 0) {
        sjt_functionParam113._parent->_refCount--;
        if (sjt_functionParam113._parent->_refCount <= 0) {
            sjt_functionParam113._vtbl->destroy(sjt_functionParam113._parent);
            free(sjt_functionParam113._parent);
        }
    }
    if (sjt_functionParam124._parent != 0) {
        sjt_functionParam124._parent->_refCount--;
        if (sjt_functionParam124._parent->_refCount <= 0) {
            sjt_functionParam124._vtbl->destroy(sjt_functionParam124._parent);
            free(sjt_functionParam124._parent);
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
    if (sjt_functionParam143._parent != 0) {
        sjt_functionParam143._parent->_refCount--;
        if (sjt_functionParam143._parent->_refCount <= 0) {
            sjt_functionParam143._vtbl->destroy(sjt_functionParam143._parent);
            free(sjt_functionParam143._parent);
        }
    }
    if (sjt_functionParam146._parent != 0) {
        sjt_functionParam146._parent->_refCount--;
        if (sjt_functionParam146._parent->_refCount <= 0) {
            sjt_functionParam146._vtbl->destroy(sjt_functionParam146._parent);
            free(sjt_functionParam146._parent);
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
    if (sjt_functionParam161._parent != 0) {
        sjt_functionParam161._parent->_refCount--;
        if (sjt_functionParam161._parent->_refCount <= 0) {
            sjt_functionParam161._vtbl->destroy(sjt_functionParam161._parent);
            free(sjt_functionParam161._parent);
        }
    }
    if (sjt_functionParam164._parent != 0) {
        sjt_functionParam164._parent->_refCount--;
        if (sjt_functionParam164._parent->_refCount <= 0) {
            sjt_functionParam164._vtbl->destroy(sjt_functionParam164._parent);
            free(sjt_functionParam164._parent);
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
    if (sjt_functionParam235._parent != 0) {
        sjt_functionParam235._parent->_refCount--;
        if (sjt_functionParam235._parent->_refCount <= 0) {
            sjt_functionParam235._vtbl->destroy(sjt_functionParam235._parent);
            free(sjt_functionParam235._parent);
        }
    }
    if (sjt_functionParam238._parent != 0) {
        sjt_functionParam238._parent->_refCount--;
        if (sjt_functionParam238._parent->_refCount <= 0) {
            sjt_functionParam238._vtbl->destroy(sjt_functionParam238._parent);
            free(sjt_functionParam238._parent);
        }
    }
    if (sjt_functionParam252._parent != 0) {
        sjt_functionParam252._parent->_refCount--;
        if (sjt_functionParam252._parent->_refCount <= 0) {
            sjt_functionParam252._vtbl->destroy(sjt_functionParam252._parent);
            free(sjt_functionParam252._parent);
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
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
;
    if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
;
    if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
;
    if (sjt_call23._refCount == 1) { sjf_string_destroy(&sjt_call23); }
;
    if (sjt_call24._refCount == 1) { sjf_gridunit_destroy(&sjt_call24); }
;
    if (sjt_call25._refCount == 1) { sjf_gridunit_destroy(&sjt_call25); }
;
    if (sjt_call26._refCount == 1) { sjf_gridunit_destroy(&sjt_call26); }
;
    if (sjt_call27._refCount == 1) { sjf_gridunit_destroy(&sjt_call27); }
;
    if (sjt_call35._refCount == 1) { sjf_string_destroy(&sjt_call35); }
;
    if (sjt_call37._refCount == 1) { sjf_string_destroy(&sjt_call37); }
;
    if (sjt_call39._refCount == 1) { sjf_string_destroy(&sjt_call39); }
;
    if (sjt_call41._refCount == 1) { sjf_string_destroy(&sjt_call41); }
;
    if (sjt_call43._refCount == 1) { sjf_string_destroy(&sjt_call43); }
;
    if (sjt_call53._refCount == 1) { sjf_string_destroy(&sjt_call53); }
;
    if (sjt_call54._refCount == 1) { sjf_string_destroy(&sjt_call54); }
;
    if (sjt_call55._refCount == 1) { sjf_string_destroy(&sjt_call55); }
;
    if (sjt_call56._refCount == 1) { sjf_string_destroy(&sjt_call56); }
;
    if (sjt_call66._refCount == 1) { sjf_string_destroy(&sjt_call66); }
;
    if (sjt_call67._refCount == 1) { sjf_string_destroy(&sjt_call67); }
;
    if (sjt_call68._refCount == 1) { sjf_string_destroy(&sjt_call68); }
;
    if (sjt_call69._refCount == 1) { sjf_string_destroy(&sjt_call69); }
;
    if (sjt_call70._refCount == 1) { sjf_string_destroy(&sjt_call70); }
;
    if (sjt_call71._refCount == 1) { sjf_string_destroy(&sjt_call71); }
;
    if (sjt_call72._refCount == 1) { sjf_string_destroy(&sjt_call72); }
;
    if (sjt_call73._refCount == 1) { sjf_string_destroy(&sjt_call73); }
;
    if (sjt_call74._refCount == 1) { sjf_string_destroy(&sjt_call74); }
;
    if (sjt_call75._refCount == 1) { sjf_string_destroy(&sjt_call75); }
;
    if (sjt_call76._refCount == 1) { sjf_string_destroy(&sjt_call76); }
;
    if (sjt_call77._refCount == 1) { sjf_string_destroy(&sjt_call77); }
;
    if (sjt_call78._refCount == 1) { sjf_string_destroy(&sjt_call78); }
;
    if (sjt_call79._refCount == 1) { sjf_string_destroy(&sjt_call79); }
;
    if (sjt_call80._refCount == 1) { sjf_string_destroy(&sjt_call80); }
;
    if (sjt_call81._refCount == 1) { sjf_string_destroy(&sjt_call81); }
;
    if (sjt_call82._refCount == 1) { sjf_string_destroy(&sjt_call82); }
;
    if (sjt_call83._refCount == 1) { sjf_string_destroy(&sjt_call83); }
;
    if (sjt_call84._refCount == 1) { sjf_string_destroy(&sjt_call84); }
;
    if (sjt_call85._refCount == 1) { sjf_string_destroy(&sjt_call85); }
;
    if (sjt_call91._refCount == 1) { sjf_string_destroy(&sjt_call91); }
;
    if (sjt_call92._refCount == 1) { sjf_gridunit_destroy(&sjt_call92); }
;
    if (sjt_call93._refCount == 1) { sjf_gridunit_destroy(&sjt_call93); }
;
    if (sjt_call94._refCount == 1) { sjf_gridunit_destroy(&sjt_call94); }
;
    if (sjt_call95._refCount == 1) { sjf_gridunit_destroy(&sjt_call95); }
;
    if (sjt_call96._refCount == 1) { sjf_gridunit_destroy(&sjt_call96); }
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
