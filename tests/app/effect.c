#ifdef __GNUC__
#if __x86_64__ 
#define __LINUX__
#define __64__
#elif __i386__ 
#define __LINUX__
#define __32__
#else
#define __LINUX__
#define __32__
#endif
#elif _MSC_VER
#if _WIN64 
#define __WINDOWS__
#define __64__
#elif _WIN32 
#define __WINDOWS__
#define __32__
#else
#error "WINDOWS UNSUPPORTED BITS"
#endif
#else
#error "UNKNOWN PLATFORM"
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
const char* sjg_string16 = "viewport being pop'ed is wrong";
const char* sjg_string17 = "viewModel";
const char* sjg_string18 = "normalMat";
const char* sjg_string19 = "projection";
const char* sjg_string2 = "shaders/blur-horizontal.frag";
const char* sjg_string20 = "lightPos";
const char* sjg_string21 = "diffuseColor";
const char* sjg_string22 = "specColor";
const char* sjg_string23 = ", ";
const char* sjg_string24 = " ";
const char* sjg_string25 = "assets/teapot.obj";
const char* sjg_string26 = "assets/cat.png";
const char* sjg_string27 = "assets/arial.ttf";
const char* sjg_string28 = "texture";
const char* sjg_string29 = "model";
const char* sjg_string3 = "shaders/blur-vertical.frag";
const char* sjg_string30 = "view";
const char* sjg_string31 = "Hello";
const char* sjg_string32 = "Framebuffer failed";
const char* sjg_string33 = "framebuffer being pop'ed is wrong";
const char* sjg_string34 = "sigma";
const char* sjg_string35 = "blurSize";
const char* sjg_string36 = "alpha";
const char* sjg_string37 = "amount";
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
#define sjs_animator_typeId 25
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
#define sjs_style_typeId 36
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
#define sjs_scene3delement_typeId 54
#define cb_heap_iface_model_heap_iface_model_i32_typeId 55
#define cb_heap_iface_model_heap_iface_model_i32_heap_typeId 56
#define cb_local_iface_model_local_iface_model_i32_typeId 57
#define cb_local_iface_model_local_iface_model_i32_heap_typeId 58
#define sjs_array_vertex_location_texture_normal_typeId 59
#define sjs_vertexbuffer_vertex_location_texture_normal_typeId 60
#define sjs_texture_typeId 61
#define sjs_model_typeId 62
#define sjs_vec2_typeId 63
#define sjs_vertex_location_texture_normal_typeId 64
#define sjs_vec4_typeId 65
#define sjs_list_i32_typeId 66
#define sjs_list_vertex_location_texture_normal_typeId 67
#define sjs_array_vec3_typeId 68
#define sjs_textrenderer_typeId 69
#define sjs_textelement_typeId 70
#define sji_textelement_vtbl_typeId 71
#define sji_textelement_typeId 72
#define sjs_boxvertexbuffer_typeId 73
#define sjs_framebuffer_typeId 74
#define sjs_renderbuffer_typeId 75
#define sjs_scenebuffer_typeId 76
#define sjs_blureffect_typeId 77
#define sjs_fadeeffect_typeId 78
#define sjs_saturateeffect_typeId 79

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
typedef struct td_sjs_scene3delement sjs_scene3delement;
typedef struct td_cb_heap_iface_model_heap_iface_model_i32 cb_heap_iface_model_heap_iface_model_i32;
typedef struct td_cb_heap_iface_model_heap_iface_model_i32_heap cb_heap_iface_model_heap_iface_model_i32_heap;
typedef struct td_cb_local_iface_model_local_iface_model_i32 cb_local_iface_model_local_iface_model_i32;
typedef struct td_cb_local_iface_model_local_iface_model_i32_heap cb_local_iface_model_local_iface_model_i32_heap;
typedef struct td_sjs_array_vertex_location_texture_normal sjs_array_vertex_location_texture_normal;
typedef struct td_sjs_vertexbuffer_vertex_location_texture_normal sjs_vertexbuffer_vertex_location_texture_normal;
typedef struct td_sjs_texture sjs_texture;
typedef struct td_sjs_model sjs_model;
typedef struct td_sjs_vec2 sjs_vec2;
typedef struct td_sjs_vertex_location_texture_normal sjs_vertex_location_texture_normal;
typedef struct td_sjs_vec4 sjs_vec4;
typedef struct td_sjs_list_i32 sjs_list_i32;
typedef struct td_sjs_list_vertex_location_texture_normal sjs_list_vertex_location_texture_normal;
typedef struct td_sjs_array_vec3 sjs_array_vec3;
typedef struct td_sjs_textrenderer sjs_textrenderer;
typedef struct td_sjs_textelement sjs_textelement;
typedef struct td_sji_textelement_vtbl sji_textelement_vtbl;
typedef struct td_sji_textelement sji_textelement;
typedef struct td_sjs_boxvertexbuffer sjs_boxvertexbuffer;
typedef struct td_sjs_framebuffer sjs_framebuffer;
typedef struct td_sjs_renderbuffer sjs_renderbuffer;
typedef struct td_sjs_scenebuffer sjs_scenebuffer;
typedef struct td_sjs_blureffect sjs_blureffect;
typedef struct td_sjs_fadeeffect sjs_fadeeffect;
typedef struct td_sjs_saturateeffect sjs_saturateeffect;

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

struct td_sjs_animator {
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

struct td_sjs_style {
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

struct td_sjs_scene3delement {
    int _refCount;
    sjs_array_heap_iface_model children;
    sjs_vec3 camera;
    sjs_vec3 lookat;
    sjs_vec3 up;
    float fieldofview;
    float znear;
    float zfar;
    sjs_light light;
    sjs_mat4 projection;
    sjs_mat4 view;
    sjs_mat4 world;
    sjs_rect _rect;
};

struct td_cb_heap_iface_model_heap_iface_model_i32 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sji_model, sji_model, int32_t* _return);
};

struct td_cb_heap_iface_model_heap_iface_model_i32_heap {
    cb_heap_iface_model_heap_iface_model_i32 inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_local_iface_model_local_iface_model_i32 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sji_model, sji_model, int32_t* _return);
};

struct td_cb_local_iface_model_local_iface_model_i32_heap {
    cb_local_iface_model_local_iface_model_i32 inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_array_vertex_location_texture_normal {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_vertexbuffer_vertex_location_texture_normal {
    int _refCount;
    sjs_string format;
    sjs_array_i32 indices;
    sjs_array_vertex_location_texture_normal vertices;
    vertex_buffer_t* buffer;
};

struct td_sjs_texture {
    int _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_model {
    int _refCount;
    sjs_vertexbuffer_vertex_location_texture_normal vertexbuffer;
    sjs_shader shader;
    sjs_texture texture;
    sjs_mat4 model;
    sjs_vec3 center;
    bool hasalpha;
    sjs_string id;
    sjs_mat4 _projection;
    sjs_mat4 _view;
    sjs_mat4 _world;
    sjs_light _light;
    sjs_vec3 _projectedcenter;
};

struct td_sjs_vec2 {
    int _refCount;
    float x;
    float y;
};

struct td_sjs_vertex_location_texture_normal {
    int _refCount;
    sjs_vec3 location;
    sjs_vec2 texture;
    sjs_vec3 normal;
};

struct td_sjs_vec4 {
    int _refCount;
    float x;
    float y;
    float z;
    float w;
};

struct td_sjs_list_i32 {
    int _refCount;
    sjs_array_i32 array;
};

struct td_sjs_list_vertex_location_texture_normal {
    int _refCount;
    sjs_array_vertex_location_texture_normal array;
};

struct td_sjs_array_vec3 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
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

struct td_sjs_boxvertexbuffer {
    int _refCount;
    sjs_rect rect;
    vertex_buffer_t* buffer;
};

struct td_sjs_framebuffer {
    int _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_renderbuffer {
    int _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_scenebuffer {
    int _refCount;
    sjs_size size;
    sjs_framebuffer framebuffer;
    sjs_texture texture;
    sjs_renderbuffer renderbuffer;
};

struct td_sjs_blureffect {
    int _refCount;
    float radius;
    sjs_rect _rect;
    sjs_boxvertexbuffer _vertexbuffer1;
    sjs_boxvertexbuffer _vertexbuffer2;
    sjs_scenebuffer _scenebuffer1;
    sjs_scenebuffer _scenebuffer2;
    sjs_scene2d _innerscene;
};

struct td_sjs_fadeeffect {
    int _refCount;
    float alpha;
    sjs_rect _rect;
    sjs_boxvertexbuffer _vertexbuffer;
    sjs_scenebuffer _scenebuffer;
    sjs_scene2d _innerscene;
};

struct td_sjs_saturateeffect {
    int _refCount;
    float amount;
    sjs_rect _rect;
    sjs_boxvertexbuffer _vertexbuffer;
    sjs_scenebuffer _scenebuffer;
    sjs_scene2d _innerscene;
};

sji_effect_vtbl sjs_blureffect_effect_vtbl;
sji_element_vtbl sjs_boxelement_element_vtbl;
sji_effect_vtbl sjs_fadeeffect_effect_vtbl;
sji_element_vtbl sjs_filllayout_element_vtbl;
sji_element_vtbl sjs_gridlayout_element_vtbl;
sji_model_vtbl sjs_model_model_vtbl;
sji_effect_vtbl sjs_saturateeffect_effect_vtbl;
sji_element_vtbl sjs_scene3delement_element_vtbl;
sji_element_vtbl sjs_textelement_element_vtbl;
sji_textelement_vtbl sjs_textelement_textelement_vtbl;
void debugout(const char * format, ...);
void debugoutv(const char * format, va_list args);
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
#include <lib/common/object.h>
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
sjs_filllayout* sjt_call139 = 0;
sjs_blureffect* sjt_call140 = 0;
sjs_filllayout* sjt_call174 = 0;
sjs_fadeeffect* sjt_call175 = 0;
sjs_filllayout* sjt_call185 = 0;
sjs_saturateeffect* sjt_call186 = 0;
sjs_gridunit sjt_call196 = { -1 };
sjs_gridunit sjt_call197 = { -1 };
sjs_gridunit sjt_call198 = { -1 };
sjs_gridunit sjt_call199 = { -1 };
sjs_gridlayout* sjt_call3 = 0;
sjs_filllayout* sjt_call5 = 0;
sjs_gridlayout* sjt_cast1 = 0;
sjs_filllayout* sjt_cast16 = 0;
sjs_blureffect* sjt_cast17 = 0;
sjs_filllayout* sjt_cast22 = 0;
sjs_fadeeffect* sjt_cast23 = 0;
sjs_filllayout* sjt_cast24 = 0;
sjs_saturateeffect* sjt_cast25 = 0;
sjs_filllayout* sjt_cast3 = 0;
int32_t sjt_functionParam39;
int32_t sjt_functionParam392;
sji_element sjt_functionParam393 = { 0 };
int32_t sjt_functionParam394;
sji_element sjt_functionParam395 = { 0 };
sji_element sjt_functionParam40 = { 0 };
int32_t sjt_functionParam55;
sji_element sjt_functionParam56 = { 0 };
int32_t sjt_functionParam564;
sji_element sjt_functionParam565 = { 0 };
int32_t sjt_functionParam566;
sji_element sjt_functionParam567 = { 0 };
int32_t sjt_functionParam601;
sji_element sjt_functionParam602 = { 0 };
int32_t sjt_functionParam603;
sji_element sjt_functionParam604 = { 0 };
int32_t sjt_functionParam638;
sjs_gridunit* sjt_functionParam639 = 0;
int32_t sjt_functionParam640;
sjs_gridunit* sjt_functionParam641 = 0;
int32_t sjt_functionParam642;
sjs_gridunit* sjt_functionParam643 = 0;
int32_t sjt_functionParam644;
sjs_gridunit* sjt_functionParam645 = 0;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_array_heap_iface_element* sjt_parent261 = 0;
sjs_array_heap_iface_element* sjt_parent262 = 0;
sjs_array_heap_iface_element* sjt_parent28 = 0;
sjs_array_heap_iface_element* sjt_parent286 = 0;
sjs_array_heap_iface_element* sjt_parent287 = 0;
sjs_array_heap_iface_element* sjt_parent294 = 0;
sjs_array_heap_iface_element* sjt_parent295 = 0;
sjs_array_gridunit* sjt_parent302 = 0;
sjs_array_gridunit* sjt_parent303 = 0;
sjs_array_gridunit* sjt_parent304 = 0;
sjs_array_gridunit* sjt_parent305 = 0;
sjs_array_heap_iface_element* sjt_parent47 = 0;
sji_effect sjt_value1 = { 0 };
sji_effect sjt_value2 = { 0 };
sji_effect sjt_value3 = { 0 };
sjs_animator sjv_animator = { -1 };
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
void sjf_array_heap_iface_model__quicksortcallback(sjs_array_heap_iface_model* _parent, int32_t left, int32_t right, cb_heap_iface_model_heap_iface_model_i32 cb);
void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from);
void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_getat_heap(sjs_array_heap_iface_model* _parent, int32_t index, sji_model* _return);
void sjf_array_heap_iface_model_grow(sjs_array_heap_iface_model* _parent, int32_t newsize, sjs_array_heap_iface_model* _return);
void sjf_array_heap_iface_model_grow_heap(sjs_array_heap_iface_model* _parent, int32_t newsize, sjs_array_heap_iface_model** _return);
void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_initat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item);
void sjf_array_heap_iface_model_setat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item);
void sjf_array_heap_iface_model_sortcb(sjs_array_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_grow(sjs_array_i32* _parent, int32_t newsize, sjs_array_i32* _return);
void sjf_array_i32_grow_heap(sjs_array_i32* _parent, int32_t newsize, sjs_array_i32** _return);
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
void sjf_array_u32_getat(sjs_array_u32* _parent, int32_t index, uint32_t* _return);
void sjf_array_u32_grow(sjs_array_u32* _parent, int32_t newsize, sjs_array_u32* _return);
void sjf_array_u32_grow_heap(sjs_array_u32* _parent, int32_t newsize, sjs_array_u32** _return);
void sjf_array_u32_heap(sjs_array_u32* _this);
void sjf_array_u32_initat(sjs_array_u32* _parent, int32_t index, uint32_t item);
void sjf_array_vec3(sjs_array_vec3* _this);
void sjf_array_vec3_copy(sjs_array_vec3* _this, sjs_array_vec3* _from);
void sjf_array_vec3_destroy(sjs_array_vec3* _this);
void sjf_array_vec3_getat(sjs_array_vec3* _parent, int32_t index, sjs_vec3* _return);
void sjf_array_vec3_heap(sjs_array_vec3* _this);
void sjf_array_vec3_initat(sjs_array_vec3* _parent, int32_t index, sjs_vec3* item);
void sjf_array_vec3_setat(sjs_array_vec3* _parent, int32_t index, sjs_vec3* item);
void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from);
void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_getat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return);
void sjf_array_vertex_location_texture_normal_grow(sjs_array_vertex_location_texture_normal* _parent, int32_t newsize, sjs_array_vertex_location_texture_normal* _return);
void sjf_array_vertex_location_texture_normal_grow_heap(sjs_array_vertex_location_texture_normal* _parent, int32_t newsize, sjs_array_vertex_location_texture_normal** _return);
void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_initat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
void sjf_array_vertex_location_texture_normal_setat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
void sjf_blureffect(sjs_blureffect* _this);
void sjf_blureffect_as_sji_effect(sjs_blureffect* _this, sji_effect* _return);
void sjf_blureffect_asinterface(sjs_blureffect* _this, int typeId, sjs_interface* _return);
void sjf_blureffect_copy(sjs_blureffect* _this, sjs_blureffect* _from);
void sjf_blureffect_destroy(sjs_blureffect* _this);
void sjf_blureffect_getrect(sjs_blureffect* _parent, sjs_rect* _return);
void sjf_blureffect_getrect_heap(sjs_blureffect* _parent, sjs_rect** _return);
void sjf_blureffect_heap(sjs_blureffect* _this);
void sjf_blureffect_render(sjs_blureffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb);
void sjf_blureffect_setrect(sjs_blureffect* _parent, sjs_rect* rect_, cb_rect_void cb);
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
void sjf_boxvertexbuffer(sjs_boxvertexbuffer* _this);
void sjf_boxvertexbuffer_copy(sjs_boxvertexbuffer* _this, sjs_boxvertexbuffer* _from);
void sjf_boxvertexbuffer_destroy(sjs_boxvertexbuffer* _this);
void sjf_boxvertexbuffer_heap(sjs_boxvertexbuffer* _this);
void sjf_boxvertexbuffer_render(sjs_boxvertexbuffer* _parent, sjs_scene2d* scene);
void sjf_color(sjs_color* _this);
void sjf_color_asvec3(sjs_color* _parent, sjs_vec3* _return);
void sjf_color_asvec3_heap(sjs_color* _parent, sjs_vec3** _return);
void sjf_color_copy(sjs_color* _this, sjs_color* _from);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_f32_asstring(float val, sjs_string* _return);
void sjf_f32_asstring_heap(float val, sjs_string** _return);
void sjf_f32_atan2(float y, float x, float* _return);
void sjf_f32_compare(float l, float r, int32_t* _return);
void sjf_f32_hash(float val, uint32_t* _return);
void sjf_f32_max(float a, float b, float* _return);
void sjf_f32_min(float a, float b, float* _return);
void sjf_f32_random(float* _return);
void sjf_f32_sqrt(float v, float* _return);
void sjf_f32_tan(float v, float* _return);
void sjf_fadeeffect_as_sji_effect(sjs_fadeeffect* _this, sji_effect* _return);
void sjf_fadeeffect_asinterface(sjs_fadeeffect* _this, int typeId, sjs_interface* _return);
void sjf_fadeeffect_copy(sjs_fadeeffect* _this, sjs_fadeeffect* _from);
void sjf_fadeeffect_destroy(sjs_fadeeffect* _this);
void sjf_fadeeffect_getrect(sjs_fadeeffect* _parent, sjs_rect* _return);
void sjf_fadeeffect_getrect_heap(sjs_fadeeffect* _parent, sjs_rect** _return);
void sjf_fadeeffect_heap(sjs_fadeeffect* _this);
void sjf_fadeeffect_render(sjs_fadeeffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb);
void sjf_fadeeffect_setrect(sjs_fadeeffect* _parent, sjs_rect* rect_, cb_rect_void cb);
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
void sjf_framebuffer(sjs_framebuffer* _this);
void sjf_framebuffer_copy(sjs_framebuffer* _this, sjs_framebuffer* _from);
void sjf_framebuffer_destroy(sjs_framebuffer* _this);
void sjf_framebuffer_heap(sjs_framebuffer* _this);
void sjf_glbindrenderbuffer(sjs_renderbuffer* renderbuffer);
void sjf_glbindtexture(int32_t type, sjs_texture* texture);
void sjf_glblendfunc(int32_t sfactor, int32_t dfactor);
void sjf_glcheckframebufferstatus(int32_t* _return);
void sjf_glclearcolor(sjs_color* color);
void sjf_gldisable(int32_t feature);
void sjf_glenable(int32_t feature);
void sjf_glframebufferrenderbuffer(int32_t attachment, sjs_renderbuffer* renderbuffer);
void sjf_glframebuffertexture2d(int32_t attachment, int32_t target, sjs_texture* texture, int32_t level);
void sjf_glgenframebuffer(sjs_size* size, sjs_framebuffer* _return);
void sjf_glgenframebuffer_heap(sjs_size* size, sjs_framebuffer** _return);
void sjf_glgenrenderbuffer(sjs_size* size, sjs_renderbuffer* _return);
void sjf_glgenrenderbuffer_heap(sjs_size* size, sjs_renderbuffer** _return);
void sjf_glgentexture(sjs_size* size, sjs_texture* _return);
void sjf_glgentexture_heap(sjs_size* size, sjs_texture** _return);
void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return);
void sjf_glpopframebuffer(sjs_framebuffer* framebuffer);
void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect);
void sjf_glpushframebuffer(sjs_framebuffer* framebuffer);
void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect);
void sjf_glrenderbufferstorage(int32_t format, sjs_size* size);
void sjf_glteximage2d(int32_t type, int32_t level, int32_t format, sjs_size* size, int32_t datatype, void* data);
void sjf_gltexparameteri(int32_t type, int32_t attribute, int32_t val);
void sjf_gluniformf32(int32_t loc, float v);
void sjf_gluniformi32(int32_t loc, int32_t v);
void sjf_gluniformmat4(int32_t loc, sjs_mat4* m);
void sjf_gluniformvec3(int32_t loc, sjs_vec3* v);
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
void sjf_hash_string_weak_iface_element_setat(sjs_hash_string_weak_iface_element* _parent, sjs_string* key, sji_element val);
void sjf_hash_string_weak_iface_model(sjs_hash_string_weak_iface_model* _this);
void sjf_hash_string_weak_iface_model__weakptrremovekey(sjs_hash_string_weak_iface_model* _parent, sjs_string* key);
void sjf_hash_string_weak_iface_model__weakptrremovevalue(sjs_hash_string_weak_iface_model* _parent, sji_model val);
void sjf_hash_string_weak_iface_model_copy(sjs_hash_string_weak_iface_model* _this, sjs_hash_string_weak_iface_model* _from);
void sjf_hash_string_weak_iface_model_destroy(sjs_hash_string_weak_iface_model* _this);
void sjf_hash_string_weak_iface_model_heap(sjs_hash_string_weak_iface_model* _this);
void sjf_hash_string_weak_iface_model_setat(sjs_hash_string_weak_iface_model* _parent, sjs_string* key, sji_model val);
void sjf_i32_max(int32_t a, int32_t b, int32_t* _return);
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
void sjf_list_heap_iface_model_add(sjs_list_heap_iface_model* _parent, sji_model item);
void sjf_list_heap_iface_model_copy(sjs_list_heap_iface_model* _this, sjs_list_heap_iface_model* _from);
void sjf_list_heap_iface_model_destroy(sjs_list_heap_iface_model* _this);
void sjf_list_heap_iface_model_getat_heap(sjs_list_heap_iface_model* _parent, int32_t index, sji_model* _return);
void sjf_list_heap_iface_model_getcount(sjs_list_heap_iface_model* _parent, int32_t* _return);
void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this);
void sjf_list_heap_iface_model_sortcb(sjs_list_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb);
void sjf_list_i32(sjs_list_i32* _this);
void sjf_list_i32_add(sjs_list_i32* _parent, int32_t item);
void sjf_list_i32_copy(sjs_list_i32* _this, sjs_list_i32* _from);
void sjf_list_i32_destroy(sjs_list_i32* _this);
void sjf_list_i32_getat(sjs_list_i32* _parent, int32_t index, int32_t* _return);
void sjf_list_i32_getcount(sjs_list_i32* _parent, int32_t* _return);
void sjf_list_i32_heap(sjs_list_i32* _this);
void sjf_list_rect(sjs_list_rect* _this);
void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item);
void sjf_list_rect_copy(sjs_list_rect* _this, sjs_list_rect* _from);
void sjf_list_rect_destroy(sjs_list_rect* _this);
void sjf_list_rect_getat(sjs_list_rect* _parent, int32_t index, sjs_rect* _return);
void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return);
void sjf_list_rect_heap(sjs_list_rect* _this);
void sjf_list_rect_removeat(sjs_list_rect* _parent, int32_t index);
void sjf_list_u32(sjs_list_u32* _this);
void sjf_list_u32_add(sjs_list_u32* _parent, uint32_t item);
void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from);
void sjf_list_u32_destroy(sjs_list_u32* _this);
void sjf_list_u32_getat(sjs_list_u32* _parent, int32_t index, uint32_t* _return);
void sjf_list_u32_getcount(sjs_list_u32* _parent, int32_t* _return);
void sjf_list_u32_heap(sjs_list_u32* _this);
void sjf_list_u32_removeat(sjs_list_u32* _parent, int32_t index);
void sjf_list_vertex_location_texture_normal(sjs_list_vertex_location_texture_normal* _this);
void sjf_list_vertex_location_texture_normal_add(sjs_list_vertex_location_texture_normal* _parent, sjs_vertex_location_texture_normal* item);
void sjf_list_vertex_location_texture_normal_copy(sjs_list_vertex_location_texture_normal* _this, sjs_list_vertex_location_texture_normal* _from);
void sjf_list_vertex_location_texture_normal_destroy(sjs_list_vertex_location_texture_normal* _this);
void sjf_list_vertex_location_texture_normal_getat(sjs_list_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return);
void sjf_list_vertex_location_texture_normal_getcount(sjs_list_vertex_location_texture_normal* _parent, int32_t* _return);
void sjf_list_vertex_location_texture_normal_heap(sjs_list_vertex_location_texture_normal* _this);
void sjf_list_vertex_location_texture_normal_setat(sjs_list_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
void sjf_mainloop(bool* _return);
void sjf_margin(sjs_margin* _this);
void sjf_margin_copy(sjs_margin* _this, sjs_margin* _from);
void sjf_margin_destroy(sjs_margin* _this);
void sjf_margin_heap(sjs_margin* _this);
void sjf_mat4(sjs_mat4* _this);
void sjf_mat4_copy(sjs_mat4* _this, sjs_mat4* _from);
void sjf_mat4_destroy(sjs_mat4* _this);
void sjf_mat4_determinant(sjs_mat4* _parent, float* _return);
void sjf_mat4_heap(sjs_mat4* _this);
void sjf_mat4_identity(sjs_mat4* _return);
void sjf_mat4_identity_heap(sjs_mat4** _return);
void sjf_mat4_invert(sjs_mat4* _parent, sjs_mat4* _return);
void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4** _return);
void sjf_mat4_lookatlh(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return);
void sjf_mat4_lookatlh_heap(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4** _return);
void sjf_mat4_multiply(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4* _return);
void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4** _return);
void sjf_mat4_multiplyf32(sjs_mat4* _parent, float x, sjs_mat4* _return);
void sjf_mat4_multiplyf32_heap(sjs_mat4* _parent, float x, sjs_mat4** _return);
void sjf_mat4_multiplyvec4(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4* _return);
void sjf_mat4_multiplyvec4_heap(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4** _return);
void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return);
void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return);
void sjf_mat4_perspective(float fovy, float aspect, float znear, float zfar, sjs_mat4* _return);
void sjf_mat4_perspective_heap(float fovy, float aspect, float znear, float zfar, sjs_mat4** _return);
void sjf_mat4_scale(float x, float y, float z, sjs_mat4* _return);
void sjf_mat4_scale_heap(float x, float y, float z, sjs_mat4** _return);
void sjf_mat4_transpose(sjs_mat4* _parent, sjs_mat4* _return);
void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4** _return);
void sjf_model_as_sji_model(sjs_model* _this, sji_model* _return);
void sjf_model_asinterface(sjs_model* _this, int typeId, sjs_interface* _return);
void sjf_model_copy(sjs_model* _this, sjs_model* _from);
void sjf_model_destroy(sjs_model* _this);
void sjf_model_firemouseevent(sjs_model* _parent, sjs_mouseevent* mouseevent);
void sjf_model_getcenter(sjs_model* _parent, sjs_vec3* _return);
void sjf_model_getcenter_heap(sjs_model* _parent, sjs_vec3** _return);
void sjf_model_getworld(sjs_model* _parent, sjs_mat4* _return);
void sjf_model_getworld_heap(sjs_model* _parent, sjs_mat4** _return);
void sjf_model_getz(sjs_model* _parent, float* _return);
void sjf_model_heap(sjs_model* _this, sjs_model** _return);
void sjf_model_render(sjs_model* _parent);
void sjf_model_renderorqueue(sjs_model* _parent, sjs_list_heap_iface_model* zqueue);
void sjf_model_update(sjs_model* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
void sjf_model_zsort(sji_model l, sji_model r, int32_t* _return);
void sjf_model_zsort_callback(void * _parent, sji_model l, sji_model r, int32_t* _return);
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
void sjf_renderbuffer(sjs_renderbuffer* _this);
void sjf_renderbuffer_copy(sjs_renderbuffer* _this, sjs_renderbuffer* _from);
void sjf_renderbuffer_destroy(sjs_renderbuffer* _this);
void sjf_renderbuffer_heap(sjs_renderbuffer* _this);
void sjf_runloop(void);
void sjf_saturateeffect(sjs_saturateeffect* _this);
void sjf_saturateeffect_as_sji_effect(sjs_saturateeffect* _this, sji_effect* _return);
void sjf_saturateeffect_asinterface(sjs_saturateeffect* _this, int typeId, sjs_interface* _return);
void sjf_saturateeffect_copy(sjs_saturateeffect* _this, sjs_saturateeffect* _from);
void sjf_saturateeffect_destroy(sjs_saturateeffect* _this);
void sjf_saturateeffect_getrect(sjs_saturateeffect* _parent, sjs_rect* _return);
void sjf_saturateeffect_getrect_heap(sjs_saturateeffect* _parent, sjs_rect** _return);
void sjf_saturateeffect_heap(sjs_saturateeffect* _this);
void sjf_saturateeffect_render(sjs_saturateeffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb);
void sjf_saturateeffect_setrect(sjs_saturateeffect* _parent, sjs_rect* rect_, cb_rect_void cb);
void sjf_scene2d(sjs_scene2d* _this);
void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from);
void sjf_scene2d_destroy(sjs_scene2d* _this);
void sjf_scene2d_end(sjs_scene2d* _parent);
void sjf_scene2d_heap(sjs_scene2d* _this);
void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size);
void sjf_scene2d_start(sjs_scene2d* _parent);
void sjf_scene3delement(sjs_scene3delement* _this);
void sjf_scene3delement_as_sji_element(sjs_scene3delement* _this, sji_element* _return);
void sjf_scene3delement_asinterface(sjs_scene3delement* _this, int typeId, sjs_interface* _return);
void sjf_scene3delement_copy(sjs_scene3delement* _this, sjs_scene3delement* _from);
void sjf_scene3delement_destroy(sjs_scene3delement* _this);
void sjf_scene3delement_firemouseevent(sjs_scene3delement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_scene3delement_getrect(sjs_scene3delement* _parent, sjs_rect* _return);
void sjf_scene3delement_getrect_heap(sjs_scene3delement* _parent, sjs_rect** _return);
void sjf_scene3delement_getsize(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_scene3delement_getsize_heap(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_scene3delement_heap(sjs_scene3delement* _this);
void sjf_scene3delement_render(sjs_scene3delement* _parent, sjs_scene2d* scene);
void sjf_scene3delement_setrect(sjs_scene3delement* _parent, sjs_rect* rect_);
void sjf_scenebuffer(sjs_scenebuffer* _this);
void sjf_scenebuffer_copy(sjs_scenebuffer* _this, sjs_scenebuffer* _from);
void sjf_scenebuffer_destroy(sjs_scenebuffer* _this);
void sjf_scenebuffer_heap(sjs_scenebuffer* _this);
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
void sjf_style(sjs_style* _this);
void sjf_style_copy(sjs_style* _this, sjs_style* _from);
void sjf_style_destroy(sjs_style* _this);
void sjf_style_getfont_heap(sjs_style* _parent, sjs_font** _return);
void sjf_style_heap(sjs_style* _this);
void sjf_testscene_heap(sji_element* _return);
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
void sjf_texture_heap(sjs_texture* _this);
void sjf_vec2(sjs_vec2* _this);
void sjf_vec2_asstring(sjs_vec2* _parent, sjs_string* _return);
void sjf_vec2_asstring_heap(sjs_vec2* _parent, sjs_string** _return);
void sjf_vec2_copy(sjs_vec2* _this, sjs_vec2* _from);
void sjf_vec2_destroy(sjs_vec2* _this);
void sjf_vec2_getrawsize(int32_t* _return);
void sjf_vec2_heap(sjs_vec2* _this);
void sjf_vec2_rawcopy(sjs_vec2* v, void* p, void** _return);
void sjf_vec3(sjs_vec3* _this);
void sjf_vec3_add(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return);
void sjf_vec3_add_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return);
void sjf_vec3_asstring(sjs_vec3* _parent, sjs_string* _return);
void sjf_vec3_asstring_heap(sjs_vec3* _parent, sjs_string** _return);
void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from);
void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return);
void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return);
void sjf_vec3_destroy(sjs_vec3* _this);
void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return);
void sjf_vec3_getrawsize(int32_t* _return);
void sjf_vec3_heap(sjs_vec3* _this);
void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return);
void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3** _return);
void sjf_vec3_rawcopy(sjs_vec3* v, void* p, void** _return);
void sjf_vec3_subtract(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return);
void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return);
void sjf_vec4(sjs_vec4* _this);
void sjf_vec4_copy(sjs_vec4* _this, sjs_vec4* _from);
void sjf_vec4_destroy(sjs_vec4* _this);
void sjf_vec4_heap(sjs_vec4* _this);
void sjf_vertex_location_texture_normal(sjs_vertex_location_texture_normal* _this);
void sjf_vertex_location_texture_normal_copy(sjs_vertex_location_texture_normal* _this, sjs_vertex_location_texture_normal* _from);
void sjf_vertex_location_texture_normal_destroy(sjs_vertex_location_texture_normal* _this);
void sjf_vertex_location_texture_normal_getrawsize(int32_t* _return);
void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal* _this);
void sjf_vertex_location_texture_normal_rawcopy(sjs_vertex_location_texture_normal* v, void* p, void** _return);
void sjf_vertexbuffer_loadobj(sjs_string* filename, sjs_vertexbuffer_vertex_location_texture_normal* _return);
void sjf_vertexbuffer_loadobj_heap(sjs_string* filename, sjs_vertexbuffer_vertex_location_texture_normal** _return);
void sjf_vertexbuffer_vertex_location_texture_normal(sjs_vertexbuffer_vertex_location_texture_normal* _this);
void sjf_vertexbuffer_vertex_location_texture_normal_copy(sjs_vertexbuffer_vertex_location_texture_normal* _this, sjs_vertexbuffer_vertex_location_texture_normal* _from);
void sjf_vertexbuffer_vertex_location_texture_normal_destroy(sjs_vertexbuffer_vertex_location_texture_normal* _this);
void sjf_vertexbuffer_vertex_location_texture_normal_heap(sjs_vertexbuffer_vertex_location_texture_normal* _this);
void sjf_vertexbuffer_vertex_location_texture_normal_render(sjs_vertexbuffer_vertex_location_texture_normal* _parent);
void sjf_windowrenderer(sjs_windowrenderer* _this);
void sjf_windowrenderer_copy(sjs_windowrenderer* _this, sjs_windowrenderer* _from);
void sjf_windowrenderer_destroy(sjs_windowrenderer* _this);
void sjf_windowrenderer_getsize(sjs_windowrenderer* _parent, sjs_size* _return);
void sjf_windowrenderer_getsize_heap(sjs_windowrenderer* _parent, sjs_size** _return);
void sjf_windowrenderer_heap(sjs_windowrenderer* _this);
void sjf_windowrenderer_present(sjs_windowrenderer* _parent);
void main_destroy(void);

void debugout(const char * format, ...) {
    va_list args;
    va_start(args, format);
    debugoutv(format, args);
    va_end(args);
}
void debugoutv(const char * format, va_list args) {
    #ifdef _WINDOWS
    char text[1024];
    vsnprintf(text, sizeof(text), format, args);
    OutputDebugStringA(text);
    #else
    vfprintf(stderr, format, args);
    #endif
}
void halt(const char * format, ...) {
    va_list args;
    va_start(args, format);
    debugoutv(format, args);
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
#include <lib/common/object.c>
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
    int32_t sjt_compare125;
    int32_t sjt_compare126;
    sjs_animator* sjt_dot1840 = 0;
    sjs_animator* sjt_dot1843 = 0;
    bool sjt_ifElse74;
    sjs_list_heap_iface_animation* sjt_parent306 = 0;

    sjt_dot1840 = _parent;
    sjt_dot1840->current = time;
    sjt_dot1843 = _parent;
    sjt_parent306 = &sjt_dot1843->animations;
    sjf_list_heap_iface_animation_getcount(sjt_parent306, &sjt_compare125);
    sjt_compare126 = 0;
    sjt_ifElse74 = sjt_compare125 > sjt_compare126;
    if (sjt_ifElse74) {
        int32_t i;
        sjs_animator* sjt_dot1844 = 0;
        int32_t sjt_forEnd28;
        int32_t sjt_forStart28;
        sjs_list_heap_iface_animation* sjt_parent307 = 0;

        sjt_forStart28 = 0;
        sjt_dot1844 = _parent;
        sjt_parent307 = &sjt_dot1844->animations;
        sjf_list_heap_iface_animation_getcount(sjt_parent307, &sjt_forEnd28);
        i = sjt_forEnd28 - 1;
        while (i >= sjt_forStart28) {
            sjs_animator* sjt_dot1846 = 0;
            int32_t sjt_functionParam647;
            bool sjt_ifElse75;
            int32_t sjt_interfaceParam19;
            sjs_list_heap_iface_animation* sjt_parent309 = 0;
            sji_animation sjt_parent310 = { 0 };
            sji_animation sjv_a = { 0 };

            sjt_dot1846 = _parent;
            sjt_parent309 = &sjt_dot1846->animations;
            sjt_functionParam647 = i;
            sjf_list_heap_iface_animation_getat_heap(sjt_parent309, sjt_functionParam647, &sjv_a);
            sjt_parent310 = sjv_a;
            sjt_interfaceParam19 = time;
            sjt_parent310._vtbl->nextframe(sjt_parent310._parent, sjt_interfaceParam19, &sjt_ifElse75);
            if (sjt_ifElse75) {
                sjs_animator* sjt_dot1847 = 0;
                int32_t sjt_functionParam648;
                sjs_list_heap_iface_animation* sjt_parent311 = 0;

                sjt_dot1847 = _parent;
                sjt_parent311 = &sjt_dot1847->animations;
                sjt_functionParam648 = i;
                sjf_list_heap_iface_animation_removeat(sjt_parent311, sjt_functionParam648);
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
    sjs_array_char* sjt_dot1482 = 0;
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
    sjt_dot1482 = _parent;
    _return->count = sjt_dot1482->count;
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    sjs_array_char* sjt_dot1483 = 0;
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
    sjt_dot1483 = _parent;
    (*_return)->count = sjt_dot1483->count;
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

void sjf_array_heap_iface_model__quicksortcallback(sjs_array_heap_iface_model* _parent, int32_t left, int32_t right, cb_heap_iface_model_heap_iface_model_i32 cb) {
    int32_t sjt_compare53;
    int32_t sjt_compare54;
    int32_t sjt_compare71;
    int32_t sjt_compare72;
    int32_t sjt_compare73;
    int32_t sjt_compare74;
    int32_t sjt_functionParam100;
    bool sjt_ifElse30;
    bool sjt_ifElse31;
    int32_t sjt_math275;
    int32_t sjt_math276;
    int32_t sjt_math277;
    int32_t sjt_math278;
    bool sjt_while1;
    int32_t sjv_i;
    int32_t sjv_j;
    sji_model sjv_pivot = { 0 };

    sjv_i = left;
    sjv_j = right;
    sjt_math277 = left;
    sjt_math278 = right;
    sjt_math275 = sjt_math277 + sjt_math278;
    sjt_math276 = 2;
    sjt_functionParam100 = sjt_math275 / sjt_math276;
    sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam100, &sjv_pivot);
    sjt_compare53 = sjv_i;
    sjt_compare54 = sjv_j;
    sjt_while1 = sjt_compare53 <= sjt_compare54;
    while (sjt_while1) {
        bool sjt_and10;
        bool sjt_and13;
        bool sjt_and14;
        bool sjt_and9;
        int32_t sjt_compare55;
        int32_t sjt_compare56;
        int32_t sjt_compare61;
        int32_t sjt_compare62;
        int32_t sjt_compare67;
        int32_t sjt_compare68;
        int32_t sjt_compare69;
        int32_t sjt_compare70;
        sjs_array_heap_iface_model* sjt_dot319 = 0;
        bool sjt_ifElse29;
        bool sjt_while2;
        bool sjt_while3;
        bool sjv_continue;

        sjv_continue = true;
        sjt_compare55 = sjv_i;
        sjt_dot319 = _parent;
        sjt_compare56 = sjt_dot319->count;
        sjt_and9 = sjt_compare55 < sjt_compare56;
        sjt_and10 = sjv_continue;
        sjt_while2 = sjt_and9 && sjt_and10;
        while (sjt_while2) {
            bool sjt_and11;
            bool sjt_and12;
            cb_heap_iface_model_heap_iface_model_i32 sjt_callback1;
            int32_t sjt_compare57;
            int32_t sjt_compare58;
            int32_t sjt_compare59;
            int32_t sjt_compare60;
            sjs_array_heap_iface_model* sjt_dot320 = 0;
            sji_model sjt_functionParam101 = { 0 };
            int32_t sjt_functionParam102;
            sji_model sjt_functionParam103 = { 0 };
            bool sjt_ifElse27;

            sjt_callback1 = cb;
            sjt_functionParam102 = sjv_i;
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam102, &sjt_functionParam101);
            sjt_functionParam103 = sjv_pivot;
            if (sjt_functionParam103._parent != 0) {
                sjt_functionParam103._parent->_refCount++;
            }

            sjt_callback1._cb(sjt_callback1._parent, sjt_functionParam101, sjt_functionParam103, &sjt_compare57);
            sjt_compare58 = 0;
            sjv_continue = sjt_compare57 < sjt_compare58;
            sjt_ifElse27 = sjv_continue;
            if (sjt_ifElse27) {
                int32_t sjt_math279;
                int32_t sjt_math280;

                sjt_math279 = sjv_i;
                sjt_math280 = 1;
                sjv_i = sjt_math279 + sjt_math280;
            }

            sjt_compare59 = sjv_i;
            sjt_dot320 = _parent;
            sjt_compare60 = sjt_dot320->count;
            sjt_and11 = sjt_compare59 < sjt_compare60;
            sjt_and12 = sjv_continue;
            sjt_while2 = sjt_and11 && sjt_and12;

            if (sjt_functionParam101._parent != 0) {
                sjt_functionParam101._parent->_refCount--;
                if (sjt_functionParam101._parent->_refCount <= 0) {
                    sjt_functionParam101._vtbl->destroy(sjt_functionParam101._parent);
                    free(sjt_functionParam101._parent);
                }
            }
            if (sjt_functionParam103._parent != 0) {
                sjt_functionParam103._parent->_refCount--;
                if (sjt_functionParam103._parent->_refCount <= 0) {
                    sjt_functionParam103._vtbl->destroy(sjt_functionParam103._parent);
                    free(sjt_functionParam103._parent);
                }
            }
        }

        sjv_continue = true;
        sjt_compare61 = sjv_j;
        sjt_compare62 = 0;
        sjt_and13 = sjt_compare61 >= sjt_compare62;
        sjt_and14 = sjv_continue;
        sjt_while3 = sjt_and13 && sjt_and14;
        while (sjt_while3) {
            bool sjt_and15;
            bool sjt_and16;
            cb_heap_iface_model_heap_iface_model_i32 sjt_callback2;
            int32_t sjt_compare63;
            int32_t sjt_compare64;
            int32_t sjt_compare65;
            int32_t sjt_compare66;
            sji_model sjt_functionParam104 = { 0 };
            int32_t sjt_functionParam105;
            sji_model sjt_functionParam106 = { 0 };
            bool sjt_ifElse28;

            sjt_callback2 = cb;
            sjt_functionParam105 = sjv_j;
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam105, &sjt_functionParam104);
            sjt_functionParam106 = sjv_pivot;
            if (sjt_functionParam106._parent != 0) {
                sjt_functionParam106._parent->_refCount++;
            }

            sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam104, sjt_functionParam106, &sjt_compare63);
            sjt_compare64 = 0;
            sjv_continue = sjt_compare63 > sjt_compare64;
            sjt_ifElse28 = sjv_continue;
            if (sjt_ifElse28) {
                int32_t sjt_math281;
                int32_t sjt_math282;

                sjt_math281 = sjv_j;
                sjt_math282 = 1;
                sjv_j = sjt_math281 - sjt_math282;
            }

            sjt_compare65 = sjv_j;
            sjt_compare66 = 0;
            sjt_and15 = sjt_compare65 >= sjt_compare66;
            sjt_and16 = sjv_continue;
            sjt_while3 = sjt_and15 && sjt_and16;

            if (sjt_functionParam104._parent != 0) {
                sjt_functionParam104._parent->_refCount--;
                if (sjt_functionParam104._parent->_refCount <= 0) {
                    sjt_functionParam104._vtbl->destroy(sjt_functionParam104._parent);
                    free(sjt_functionParam104._parent);
                }
            }
            if (sjt_functionParam106._parent != 0) {
                sjt_functionParam106._parent->_refCount--;
                if (sjt_functionParam106._parent->_refCount <= 0) {
                    sjt_functionParam106._vtbl->destroy(sjt_functionParam106._parent);
                    free(sjt_functionParam106._parent);
                }
            }
        }

        sjt_compare67 = sjv_i;
        sjt_compare68 = sjv_j;
        sjt_ifElse29 = sjt_compare67 <= sjt_compare68;
        if (sjt_ifElse29) {
            int32_t sjt_functionParam107;
            int32_t sjt_functionParam108;
            sji_model sjt_functionParam109 = { 0 };
            int32_t sjt_functionParam110;
            int32_t sjt_functionParam111;
            sji_model sjt_functionParam112 = { 0 };
            int32_t sjt_math283;
            int32_t sjt_math284;
            int32_t sjt_math285;
            int32_t sjt_math286;
            sji_model sjv_tmp = { 0 };

            sjt_functionParam107 = sjv_i;
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam107, &sjv_tmp);
            sjt_functionParam108 = sjv_i;
            sjt_functionParam110 = sjv_j;
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam110, &sjt_functionParam109);
            sjf_array_heap_iface_model_setat(_parent, sjt_functionParam108, sjt_functionParam109);
            sjt_functionParam111 = sjv_j;
            sjt_functionParam112 = sjv_tmp;
            if (sjt_functionParam112._parent != 0) {
                sjt_functionParam112._parent->_refCount++;
            }

            sjf_array_heap_iface_model_setat(_parent, sjt_functionParam111, sjt_functionParam112);
            sjt_math283 = sjv_i;
            sjt_math284 = 1;
            sjv_i = sjt_math283 + sjt_math284;
            sjt_math285 = sjv_j;
            sjt_math286 = 1;
            sjv_j = sjt_math285 - sjt_math286;

            if (sjt_functionParam109._parent != 0) {
                sjt_functionParam109._parent->_refCount--;
                if (sjt_functionParam109._parent->_refCount <= 0) {
                    sjt_functionParam109._vtbl->destroy(sjt_functionParam109._parent);
                    free(sjt_functionParam109._parent);
                }
            }
            if (sjt_functionParam112._parent != 0) {
                sjt_functionParam112._parent->_refCount--;
                if (sjt_functionParam112._parent->_refCount <= 0) {
                    sjt_functionParam112._vtbl->destroy(sjt_functionParam112._parent);
                    free(sjt_functionParam112._parent);
                }
            }
            if (sjv_tmp._parent != 0) {
                sjv_tmp._parent->_refCount--;
                if (sjv_tmp._parent->_refCount <= 0) {
                    sjv_tmp._vtbl->destroy(sjv_tmp._parent);
                    free(sjv_tmp._parent);
                }
            }
        }

        sjt_compare69 = sjv_i;
        sjt_compare70 = sjv_j;
        sjt_while1 = sjt_compare69 <= sjt_compare70;
    }

    sjt_compare71 = left;
    sjt_compare72 = sjv_j;
    sjt_ifElse30 = sjt_compare71 < sjt_compare72;
    if (sjt_ifElse30) {
        int32_t sjt_functionParam113;
        int32_t sjt_functionParam114;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam115;

        sjt_functionParam113 = left;
        sjt_functionParam114 = sjv_j;
        sjt_functionParam115 = cb;
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam113, sjt_functionParam114, sjt_functionParam115);
    }

    sjt_compare73 = sjv_i;
    sjt_compare74 = right;
    sjt_ifElse31 = sjt_compare73 < sjt_compare74;
    if (sjt_ifElse31) {
        int32_t sjt_functionParam116;
        int32_t sjt_functionParam117;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam118;

        sjt_functionParam116 = sjv_i;
        sjt_functionParam117 = right;
        sjt_functionParam118 = cb;
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam116, sjt_functionParam117, sjt_functionParam118);
    }

    if (sjv_pivot._parent != 0) {
        sjv_pivot._parent->_refCount--;
        if (sjv_pivot._parent->_refCount <= 0) {
            sjv_pivot._vtbl->destroy(sjv_pivot._parent);
            free(sjv_pivot._parent);
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

void sjf_array_heap_iface_model_getat_heap(sjs_array_heap_iface_model* _parent, int32_t index, sji_model* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sji_model* p = (sji_model*)_parent->data;
    (*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_model_grow(sjs_array_heap_iface_model* _parent, int32_t newsize, sjs_array_heap_iface_model* _return) {
    sjs_array_heap_iface_model* sjt_dot697 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(sji_model));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sji_model* p = (sji_model*)_parent->data;
        sji_model* newp = (sji_model*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
if (newp[i]._parent != 0) {
    newp[i]._parent->_refCount++;
}
;
        }
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot697 = _parent;
    _return->count = sjt_dot697->count;
    sjf_array_heap_iface_model(_return);
}

void sjf_array_heap_iface_model_grow_heap(sjs_array_heap_iface_model* _parent, int32_t newsize, sjs_array_heap_iface_model** _return) {
    sjs_array_heap_iface_model* sjt_dot698 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(sji_model));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sji_model* p = (sji_model*)_parent->data;
        sji_model* newp = (sji_model*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
if (newp[i]._parent != 0) {
    newp[i]._parent->_refCount++;
}
;
        }
    }
    (*_return) = (sjs_array_heap_iface_model*)malloc(sizeof(sjs_array_heap_iface_model));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot698 = _parent;
    (*_return)->count = sjt_dot698->count;
    sjf_array_heap_iface_model_heap((*_return));
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

void sjf_array_heap_iface_model_initat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sji_model* p = (sji_model*)_parent->data;
    p[index] = item;
if (p[index]._parent != 0) {
    p[index]._parent->_refCount++;
}
;
    _parent->count = index + 1;
}

void sjf_array_heap_iface_model_setat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    sji_model* p = (sji_model*)_parent->data;
    if (p[index]._parent != 0) {
    p[index]._parent->_refCount--;
    if (p[index]._parent->_refCount <= 0) {
        p[index]._vtbl->destroy(p[index]._parent);
        free(p[index]._parent);
    }
}
;
    p[index] = item;
if (p[index]._parent != 0) {
    p[index]._parent->_refCount++;
}
;
}

void sjf_array_heap_iface_model_sortcb(sjs_array_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb) {
    int32_t sjt_compare51;
    int32_t sjt_compare52;
    sjs_array_heap_iface_model* sjt_dot318 = 0;
    bool sjt_ifElse26;

    sjt_dot318 = _parent;
    sjt_compare51 = sjt_dot318->count;
    sjt_compare52 = 1;
    sjt_ifElse26 = sjt_compare51 > sjt_compare52;
    if (sjt_ifElse26) {
        sjs_array_heap_iface_model* sjt_dot321 = 0;
        int32_t sjt_functionParam119;
        int32_t sjt_functionParam120;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam121;
        int32_t sjt_math287;
        int32_t sjt_math288;

        sjt_functionParam119 = 0;
        sjt_dot321 = _parent;
        sjt_math287 = sjt_dot321->count;
        sjt_math288 = 1;
        sjt_functionParam120 = sjt_math287 - sjt_math288;
        sjt_functionParam121 = cb;
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam119, sjt_functionParam120, sjt_functionParam121);
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

void sjf_array_i32_grow(sjs_array_i32* _parent, int32_t newsize, sjs_array_i32* _return) {
    sjs_array_i32* sjt_dot1471 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(int32_t));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        int32_t* p = (int32_t*)_parent->data;
        int32_t* newp = (int32_t*)sjv_newdata;
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
    sjt_dot1471 = _parent;
    _return->count = sjt_dot1471->count;
    sjf_array_i32(_return);
}

void sjf_array_i32_grow_heap(sjs_array_i32* _parent, int32_t newsize, sjs_array_i32** _return) {
    sjs_array_i32* sjt_dot1472 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(int32_t));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        int32_t* p = (int32_t*)_parent->data;
        int32_t* newp = (int32_t*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
    }
    (*_return) = (sjs_array_i32*)malloc(sizeof(sjs_array_i32));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot1472 = _parent;
    (*_return)->count = sjt_dot1472->count;
    sjf_array_i32_heap((*_return));
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
    sjs_array_rect* sjt_dot305 = 0;
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
    sjt_dot305 = _parent;
    _return->count = sjt_dot305->count;
    sjf_array_rect(_return);
}

void sjf_array_rect_grow_heap(sjs_array_rect* _parent, int32_t newsize, sjs_array_rect** _return) {
    sjs_array_rect* sjt_dot306 = 0;
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
    sjt_dot306 = _parent;
    (*_return)->count = sjt_dot306->count;
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

void sjf_array_u32_getat(sjs_array_u32* _parent, int32_t index, uint32_t* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    uint32_t* p = (uint32_t*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_u32_grow(sjs_array_u32* _parent, int32_t newsize, sjs_array_u32* _return) {
    sjs_array_u32* sjt_dot1632 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(uint32_t));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        uint32_t* p = (uint32_t*)_parent->data;
        uint32_t* newp = (uint32_t*)sjv_newdata;
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
    sjt_dot1632 = _parent;
    _return->count = sjt_dot1632->count;
    sjf_array_u32(_return);
}

void sjf_array_u32_grow_heap(sjs_array_u32* _parent, int32_t newsize, sjs_array_u32** _return) {
    sjs_array_u32* sjt_dot1633 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(uint32_t));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        uint32_t* p = (uint32_t*)_parent->data;
        uint32_t* newp = (uint32_t*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
    }
    (*_return) = (sjs_array_u32*)malloc(sizeof(sjs_array_u32));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot1633 = _parent;
    (*_return)->count = sjt_dot1633->count;
    sjf_array_u32_heap((*_return));
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

void sjf_array_u32_initat(sjs_array_u32* _parent, int32_t index, uint32_t item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    uint32_t* p = (uint32_t*)_parent->data;
    p[index] = item;
;
    _parent->count = index + 1;
}

void sjf_array_vec3(sjs_array_vec3* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_vec3));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_vec3_copy(sjs_array_vec3* _this, sjs_array_vec3* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_vec3_destroy(sjs_array_vec3* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sjs_vec3* p = (sjs_vec3*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_vec3_getat(sjs_array_vec3* _parent, int32_t index, sjs_vec3* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_vec3* p = (sjs_vec3*)_parent->data;
    _return->_refCount = 1;
sjf_vec3_copy(_return, &p[index]);
return;;       
}

void sjf_array_vec3_heap(sjs_array_vec3* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_vec3));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_vec3_initat(sjs_array_vec3* _parent, int32_t index, sjs_vec3* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sjs_vec3* p = (sjs_vec3*)_parent->data;
    p[index]._refCount = 1;
sjf_vec3_copy(&p[index], item);
;
    _parent->count = index + 1;
}

void sjf_array_vec3_setat(sjs_array_vec3* _parent, int32_t index, sjs_vec3* item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    sjs_vec3* p = (sjs_vec3*)_parent->data;
    ;
    p[index]._refCount = 1;
sjf_vec3_copy(&p[index], item);
;
}

void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_vertex_location_texture_normal));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_vertex_location_texture_normal_getat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_parent->data;
    _return->_refCount = 1;
sjf_vertex_location_texture_normal_copy(_return, &p[index]);
return;;       
}

void sjf_array_vertex_location_texture_normal_grow(sjs_array_vertex_location_texture_normal* _parent, int32_t newsize, sjs_array_vertex_location_texture_normal* _return) {
    sjs_array_vertex_location_texture_normal* sjt_dot1513 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(sjs_vertex_location_texture_normal));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_parent->data;
        sjs_vertex_location_texture_normal* newp = (sjs_vertex_location_texture_normal*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i]._refCount = 1;
sjf_vertex_location_texture_normal_copy(&newp[i], &p[i]);
;
        }
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot1513 = _parent;
    _return->count = sjt_dot1513->count;
    sjf_array_vertex_location_texture_normal(_return);
}

void sjf_array_vertex_location_texture_normal_grow_heap(sjs_array_vertex_location_texture_normal* _parent, int32_t newsize, sjs_array_vertex_location_texture_normal** _return) {
    sjs_array_vertex_location_texture_normal* sjt_dot1514 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(sjs_vertex_location_texture_normal));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_parent->data;
        sjs_vertex_location_texture_normal* newp = (sjs_vertex_location_texture_normal*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i]._refCount = 1;
sjf_vertex_location_texture_normal_copy(&newp[i], &p[i]);
;
        }
    }
    (*_return) = (sjs_array_vertex_location_texture_normal*)malloc(sizeof(sjs_array_vertex_location_texture_normal));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot1514 = _parent;
    (*_return)->count = sjt_dot1514->count;
    sjf_array_vertex_location_texture_normal_heap((*_return));
}

void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_vertex_location_texture_normal));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_vertex_location_texture_normal_initat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_parent->data;
    p[index]._refCount = 1;
sjf_vertex_location_texture_normal_copy(&p[index], item);
;
    _parent->count = index + 1;
}

void sjf_array_vertex_location_texture_normal_setat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_parent->data;
    ;
    p[index]._refCount = 1;
sjf_vertex_location_texture_normal_copy(&p[index], item);
;
}

void sjf_blureffect(sjs_blureffect* _this) {
}

void sjf_blureffect_as_sji_effect(sjs_blureffect* _this, sji_effect* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_blureffect_effect_vtbl;
}

void sjf_blureffect_asinterface(sjs_blureffect* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_effect_typeId:  {
            sjf_blureffect_as_sji_effect(_this, (sji_effect*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_blureffect_copy(sjs_blureffect* _this, sjs_blureffect* _from) {
    _this->radius = _from->radius;
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    _this->_vertexbuffer1._refCount = 1;
    sjf_boxvertexbuffer_copy((_this->_vertexbuffer1._refCount != -1 ? &_this->_vertexbuffer1 : 0), (_from->_vertexbuffer1._refCount != -1 ? &_from->_vertexbuffer1 : 0));
    _this->_vertexbuffer2._refCount = 1;
    sjf_boxvertexbuffer_copy((_this->_vertexbuffer2._refCount != -1 ? &_this->_vertexbuffer2 : 0), (_from->_vertexbuffer2._refCount != -1 ? &_from->_vertexbuffer2 : 0));
    _this->_scenebuffer1._refCount = 1;
    sjf_scenebuffer_copy((_this->_scenebuffer1._refCount != -1 ? &_this->_scenebuffer1 : 0), (_from->_scenebuffer1._refCount != -1 ? &_from->_scenebuffer1 : 0));
    _this->_scenebuffer2._refCount = 1;
    sjf_scenebuffer_copy((_this->_scenebuffer2._refCount != -1 ? &_this->_scenebuffer2 : 0), (_from->_scenebuffer2._refCount != -1 ? &_from->_scenebuffer2 : 0));
    _this->_innerscene._refCount = 1;
    sjf_scene2d_copy(&_this->_innerscene, &_from->_innerscene);
}

void sjf_blureffect_destroy(sjs_blureffect* _this) {
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
    if (_this->_vertexbuffer1._refCount == 1) { sjf_boxvertexbuffer_destroy(&_this->_vertexbuffer1); }
;
    if (_this->_vertexbuffer2._refCount == 1) { sjf_boxvertexbuffer_destroy(&_this->_vertexbuffer2); }
;
    if (_this->_scenebuffer1._refCount == 1) { sjf_scenebuffer_destroy(&_this->_scenebuffer1); }
;
    if (_this->_scenebuffer2._refCount == 1) { sjf_scenebuffer_destroy(&_this->_scenebuffer2); }
;
    if (_this->_innerscene._refCount == 1) { sjf_scene2d_destroy(&_this->_innerscene); }
;
}

void sjf_blureffect_getrect(sjs_blureffect* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy90 = 0;
    sjs_blureffect* sjt_dot1645 = 0;

    sjt_dot1645 = _parent;
    sjt_copy90 = &sjt_dot1645->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy90);
}

void sjf_blureffect_getrect_heap(sjs_blureffect* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy91 = 0;
    sjs_blureffect* sjt_dot1646 = 0;

    sjt_dot1646 = _parent;
    sjt_copy91 = &sjt_dot1646->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy91);
}

void sjf_blureffect_heap(sjs_blureffect* _this) {
}

void sjf_blureffect_render(sjs_blureffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb) {
    sjs_boxvertexbuffer sjt_call154 = { -1 };
    sjs_boxvertexbuffer sjt_call155 = { -1 };
    sjs_scenebuffer sjt_call156 = { -1 };
    sjs_scenebuffer sjt_call157 = { -1 };
    float sjt_compare123;
    float sjt_compare124;
    sjs_blureffect* sjt_dot1677 = 0;
    bool sjt_ifElse60;

    sjt_dot1677 = _parent;
    sjt_compare123 = sjt_dot1677->radius;
    sjt_compare124 = 0.0f;
    sjt_ifElse60 = sjt_compare123 == sjt_compare124;
    if (sjt_ifElse60) {
        cb_scene2d_void sjt_callback5;
        sjs_scene2d* sjt_functionParam482 = 0;

        sjt_callback5 = cb;
        sjt_functionParam482 = scene;
        sjt_callback5._cb(sjt_callback5._parent, sjt_functionParam482);
    } else {
        sjs_blureffect* sjt_dot1678 = 0;
        sjs_blureffect* sjt_dot1684 = 0;
        sjs_blureffect* sjt_dot1687 = 0;
        sjs_blureffect* sjt_dot1693 = 0;
        sjs_blureffect* sjt_dot1699 = 0;
        sjs_blureffect* sjt_dot1700 = 0;
        sjs_blureffect* sjt_dot1701 = 0;
        sjs_blureffect* sjt_dot1702 = 0;
        bool sjt_ifElse61;
        bool sjt_ifElse62;
        bool sjt_ifElse63;
        bool sjt_ifElse64;
        sjs_boxvertexbuffer* sjt_isEmpty25 = 0;
        sjs_boxvertexbuffer* sjt_isEmpty26 = 0;
        sjs_scenebuffer* sjt_isEmpty27 = 0;
        sjs_scenebuffer* sjt_isEmpty28 = 0;
        bool sjt_isEmpty29;
        sjs_scenebuffer* sjt_isEmpty30 = 0;
        bool sjt_isEmpty31;
        sjs_scenebuffer* sjt_isEmpty32 = 0;
        bool sjt_isEmpty33;
        sjs_boxvertexbuffer* sjt_isEmpty34 = 0;
        bool sjt_isEmpty35;
        sjs_boxvertexbuffer* sjt_isEmpty36 = 0;

        sjt_dot1678 = _parent;
        sjt_isEmpty25 = (sjt_dot1678->_vertexbuffer1._refCount != -1 ? &sjt_dot1678->_vertexbuffer1 : 0);
        sjt_ifElse61 = (sjt_isEmpty25 == 0);
        if (sjt_ifElse61) {
            sjs_boxvertexbuffer* sjt_copy93 = 0;
            sjs_blureffect* sjt_dot1679 = 0;
            sjs_rect* sjt_dot1680 = 0;
            sjs_blureffect* sjt_dot1681 = 0;
            sjs_rect* sjt_dot1682 = 0;
            sjs_blureffect* sjt_dot1683 = 0;

            sjt_dot1679 = _parent;
            sjt_call154._refCount = 1;
            sjt_call154.rect._refCount = 1;
            sjt_call154.rect.x = 0;
            sjt_call154.rect.y = 0;
            sjt_dot1681 = _parent;
            sjt_dot1680 = &sjt_dot1681->_rect;
            sjt_call154.rect.w = sjt_dot1680->w;
            sjt_dot1683 = _parent;
            sjt_dot1682 = &sjt_dot1683->_rect;
            sjt_call154.rect.h = sjt_dot1682->h;
            sjf_rect(&sjt_call154.rect);
            sjf_boxvertexbuffer(&sjt_call154);
            sjt_copy93 = &sjt_call154;
            if (sjt_dot1679->_vertexbuffer1._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_dot1679->_vertexbuffer1); }
;
            sjt_dot1679->_vertexbuffer1._refCount = 1;
            sjf_boxvertexbuffer_copy(&sjt_dot1679->_vertexbuffer1, sjt_copy93);
        }

        sjt_dot1684 = _parent;
        sjt_isEmpty26 = (sjt_dot1684->_vertexbuffer2._refCount != -1 ? &sjt_dot1684->_vertexbuffer2 : 0);
        sjt_ifElse62 = (sjt_isEmpty26 == 0);
        if (sjt_ifElse62) {
            sjs_boxvertexbuffer* sjt_copy94 = 0;
            sjs_rect* sjt_copy95 = 0;
            sjs_blureffect* sjt_dot1685 = 0;
            sjs_blureffect* sjt_dot1686 = 0;

            sjt_dot1685 = _parent;
            sjt_call155._refCount = 1;
            sjt_dot1686 = _parent;
            sjt_copy95 = &sjt_dot1686->_rect;
            sjt_call155.rect._refCount = 1;
            sjf_rect_copy(&sjt_call155.rect, sjt_copy95);
            sjf_boxvertexbuffer(&sjt_call155);
            sjt_copy94 = &sjt_call155;
            if (sjt_dot1685->_vertexbuffer2._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_dot1685->_vertexbuffer2); }
;
            sjt_dot1685->_vertexbuffer2._refCount = 1;
            sjf_boxvertexbuffer_copy(&sjt_dot1685->_vertexbuffer2, sjt_copy94);
        }

        sjt_dot1687 = _parent;
        sjt_isEmpty27 = (sjt_dot1687->_scenebuffer1._refCount != -1 ? &sjt_dot1687->_scenebuffer1 : 0);
        sjt_ifElse63 = (sjt_isEmpty27 == 0);
        if (sjt_ifElse63) {
            sjs_scenebuffer* sjt_copy96 = 0;
            sjs_blureffect* sjt_dot1688 = 0;
            sjs_rect* sjt_dot1689 = 0;
            sjs_blureffect* sjt_dot1690 = 0;
            sjs_rect* sjt_dot1691 = 0;
            sjs_blureffect* sjt_dot1692 = 0;

            sjt_dot1688 = _parent;
            sjt_call156._refCount = 1;
            sjt_call156.size._refCount = 1;
            sjt_dot1690 = _parent;
            sjt_dot1689 = &sjt_dot1690->_rect;
            sjt_call156.size.w = sjt_dot1689->w;
            sjt_dot1692 = _parent;
            sjt_dot1691 = &sjt_dot1692->_rect;
            sjt_call156.size.h = sjt_dot1691->h;
            sjf_size(&sjt_call156.size);
            sjt_call156.framebuffer._refCount = 1;
            sjt_call156.framebuffer.size._refCount = 1;
            sjt_call156.framebuffer.size.w = 0;
            sjt_call156.framebuffer.size.h = 0;
            sjf_size(&sjt_call156.framebuffer.size);
            sjt_call156.framebuffer.id = (uint32_t)0u;
            sjf_framebuffer(&sjt_call156.framebuffer);
            sjt_call156.texture._refCount = 1;
            sjt_call156.texture.size._refCount = 1;
            sjt_call156.texture.size.w = 0;
            sjt_call156.texture.size.h = 0;
            sjf_size(&sjt_call156.texture.size);
            sjt_call156.texture.id = (uint32_t)0u;
            sjf_texture(&sjt_call156.texture);
            sjt_call156.renderbuffer._refCount = 1;
            sjt_call156.renderbuffer.size._refCount = 1;
            sjt_call156.renderbuffer.size.w = 0;
            sjt_call156.renderbuffer.size.h = 0;
            sjf_size(&sjt_call156.renderbuffer.size);
            sjt_call156.renderbuffer.id = (uint32_t)0u;
            sjf_renderbuffer(&sjt_call156.renderbuffer);
            sjf_scenebuffer(&sjt_call156);
            sjt_copy96 = &sjt_call156;
            if (sjt_dot1688->_scenebuffer1._refCount == 1) { sjf_scenebuffer_destroy(&sjt_dot1688->_scenebuffer1); }
;
            sjt_dot1688->_scenebuffer1._refCount = 1;
            sjf_scenebuffer_copy(&sjt_dot1688->_scenebuffer1, sjt_copy96);
        }

        sjt_dot1693 = _parent;
        sjt_isEmpty28 = (sjt_dot1693->_scenebuffer2._refCount != -1 ? &sjt_dot1693->_scenebuffer2 : 0);
        sjt_ifElse64 = (sjt_isEmpty28 == 0);
        if (sjt_ifElse64) {
            sjs_scenebuffer* sjt_copy97 = 0;
            sjs_blureffect* sjt_dot1694 = 0;
            sjs_rect* sjt_dot1695 = 0;
            sjs_blureffect* sjt_dot1696 = 0;
            sjs_rect* sjt_dot1697 = 0;
            sjs_blureffect* sjt_dot1698 = 0;

            sjt_dot1694 = _parent;
            sjt_call157._refCount = 1;
            sjt_call157.size._refCount = 1;
            sjt_dot1696 = _parent;
            sjt_dot1695 = &sjt_dot1696->_rect;
            sjt_call157.size.w = sjt_dot1695->w;
            sjt_dot1698 = _parent;
            sjt_dot1697 = &sjt_dot1698->_rect;
            sjt_call157.size.h = sjt_dot1697->h;
            sjf_size(&sjt_call157.size);
            sjt_call157.framebuffer._refCount = 1;
            sjt_call157.framebuffer.size._refCount = 1;
            sjt_call157.framebuffer.size.w = 0;
            sjt_call157.framebuffer.size.h = 0;
            sjf_size(&sjt_call157.framebuffer.size);
            sjt_call157.framebuffer.id = (uint32_t)0u;
            sjf_framebuffer(&sjt_call157.framebuffer);
            sjt_call157.texture._refCount = 1;
            sjt_call157.texture.size._refCount = 1;
            sjt_call157.texture.size.w = 0;
            sjt_call157.texture.size.h = 0;
            sjf_size(&sjt_call157.texture.size);
            sjt_call157.texture.id = (uint32_t)0u;
            sjf_texture(&sjt_call157.texture);
            sjt_call157.renderbuffer._refCount = 1;
            sjt_call157.renderbuffer.size._refCount = 1;
            sjt_call157.renderbuffer.size.w = 0;
            sjt_call157.renderbuffer.size.h = 0;
            sjf_size(&sjt_call157.renderbuffer.size);
            sjt_call157.renderbuffer.id = (uint32_t)0u;
            sjf_renderbuffer(&sjt_call157.renderbuffer);
            sjf_scenebuffer(&sjt_call157);
            sjt_copy97 = &sjt_call157;
            if (sjt_dot1694->_scenebuffer2._refCount == 1) { sjf_scenebuffer_destroy(&sjt_dot1694->_scenebuffer2); }
;
            sjt_dot1694->_scenebuffer2._refCount = 1;
            sjf_scenebuffer_copy(&sjt_dot1694->_scenebuffer2, sjt_copy97);
        }

        sjt_dot1699 = _parent;
        sjt_isEmpty30 = (sjt_dot1699->_scenebuffer1._refCount != -1 ? &sjt_dot1699->_scenebuffer1 : 0);
        sjt_isEmpty29 = (sjt_isEmpty30 != 0);
        sjt_dot1700 = _parent;
        sjt_isEmpty32 = (sjt_dot1700->_scenebuffer2._refCount != -1 ? &sjt_dot1700->_scenebuffer2 : 0);
        sjt_isEmpty31 = (sjt_isEmpty32 != 0);
        sjt_dot1701 = _parent;
        sjt_isEmpty34 = (sjt_dot1701->_vertexbuffer1._refCount != -1 ? &sjt_dot1701->_vertexbuffer1 : 0);
        sjt_isEmpty33 = (sjt_isEmpty34 != 0);
        sjt_dot1702 = _parent;
        sjt_isEmpty36 = (sjt_dot1702->_vertexbuffer2._refCount != -1 ? &sjt_dot1702->_vertexbuffer2 : 0);
        sjt_isEmpty35 = (sjt_isEmpty36 != 0);
        if (sjt_isEmpty29 && sjt_isEmpty31 && sjt_isEmpty33 && sjt_isEmpty35) {
            sjs_scenebuffer* ifValue19 = 0;
            sjs_scenebuffer* ifValue20 = 0;
            sjs_boxvertexbuffer* ifValue21 = 0;
            sjs_boxvertexbuffer* ifValue22 = 0;
            sjs_string sjt_call162 = { -1 };
            sjs_string sjt_call163 = { -1 };
            sjs_string sjt_call164 = { -1 };
            sjs_string sjt_call165 = { -1 };
            sjs_string sjt_call166 = { -1 };
            sjs_string sjt_call167 = { -1 };
            sjs_string sjt_call168 = { -1 };
            sjs_string sjt_call169 = { -1 };
            sjs_string sjt_call170 = { -1 };
            sjs_string sjt_call171 = { -1 };
            sjs_string sjt_call172 = { -1 };
            sjs_string sjt_call173 = { -1 };
            cb_scene2d_void sjt_callback6;
            int32_t sjt_cast20;
            int32_t sjt_cast21;
            sjs_blureffect* sjt_dot1703 = 0;
            sjs_blureffect* sjt_dot1704 = 0;
            sjs_blureffect* sjt_dot1705 = 0;
            sjs_blureffect* sjt_dot1706 = 0;
            sjs_scenebuffer* sjt_dot1707 = 0;
            sjs_blureffect* sjt_dot1717 = 0;
            sjs_scenebuffer* sjt_dot1718 = 0;
            sjs_blureffect* sjt_dot1726 = 0;
            sjs_blureffect* sjt_dot1727 = 0;
            sjs_blureffect* sjt_dot1730 = 0;
            sjs_scenebuffer* sjt_dot1731 = 0;
            sjs_scenebuffer* sjt_dot1732 = 0;
            sjs_blureffect* sjt_dot1733 = 0;
            sjs_scenebuffer* sjt_dot1734 = 0;
            sjs_blureffect* sjt_dot1735 = 0;
            sjs_scenebuffer* sjt_dot1736 = 0;
            sjs_blureffect* sjt_dot1737 = 0;
            sjs_size* sjt_dot1738 = 0;
            sjs_scenebuffer* sjt_dot1739 = 0;
            sjs_scene2d* sjt_dot1740 = 0;
            sjs_blureffect* sjt_dot1741 = 0;
            sjs_scene2d* sjt_dot1742 = 0;
            sjs_blureffect* sjt_dot1743 = 0;
            sjs_scene2d* sjt_dot1744 = 0;
            sjs_blureffect* sjt_dot1745 = 0;
            sjs_blureffect* sjt_dot1746 = 0;
            sjs_blureffect* sjt_dot1747 = 0;
            sjs_scenebuffer* sjt_dot1748 = 0;
            sjs_scenebuffer* sjt_dot1749 = 0;
            sjs_blureffect* sjt_dot1750 = 0;
            sjs_size* sjt_dot1751 = 0;
            sjs_scenebuffer* sjt_dot1752 = 0;
            sjs_scene2d* sjt_dot1753 = 0;
            sjs_scene2d* sjt_dot1754 = 0;
            sjs_scene2d* sjt_dot1755 = 0;
            sjs_framebuffer* sjt_functionParam483 = 0;
            sjs_size* sjt_functionParam494 = 0;
            sjs_scene2d* sjt_functionParam497 = 0;
            sjs_framebuffer* sjt_functionParam500 = 0;
            sjs_framebuffer* sjt_functionParam501 = 0;
            sjs_size* sjt_functionParam502 = 0;
            int32_t sjt_functionParam503;
            sjs_texture* sjt_functionParam504 = 0;
            sjs_shader* sjt_functionParam505 = 0;
            int32_t sjt_functionParam506;
            int32_t sjt_functionParam507;
            int32_t sjt_functionParam508;
            sjs_shader* sjt_functionParam509 = 0;
            sjs_string* sjt_functionParam510 = 0;
            int32_t sjt_functionParam511;
            int32_t sjt_functionParam512;
            sjs_shader* sjt_functionParam513 = 0;
            sjs_string* sjt_functionParam514 = 0;
            float sjt_functionParam515;
            int32_t sjt_functionParam516;
            sjs_shader* sjt_functionParam517 = 0;
            sjs_string* sjt_functionParam518 = 0;
            float sjt_functionParam519;
            int32_t sjt_functionParam520;
            sjs_shader* sjt_functionParam521 = 0;
            sjs_string* sjt_functionParam522 = 0;
            sjs_mat4* sjt_functionParam523 = 0;
            int32_t sjt_functionParam524;
            sjs_shader* sjt_functionParam525 = 0;
            sjs_string* sjt_functionParam526 = 0;
            sjs_mat4* sjt_functionParam527 = 0;
            int32_t sjt_functionParam528;
            sjs_shader* sjt_functionParam529 = 0;
            sjs_string* sjt_functionParam530 = 0;
            sjs_mat4* sjt_functionParam531 = 0;
            sjs_scene2d* sjt_functionParam532 = 0;
            sjs_framebuffer* sjt_functionParam533 = 0;
            int32_t sjt_functionParam534;
            sjs_texture* sjt_functionParam535 = 0;
            sjs_shader* sjt_functionParam536 = 0;
            int32_t sjt_functionParam537;
            int32_t sjt_functionParam538;
            int32_t sjt_functionParam539;
            sjs_shader* sjt_functionParam540 = 0;
            sjs_string* sjt_functionParam541 = 0;
            int32_t sjt_functionParam542;
            int32_t sjt_functionParam543;
            sjs_shader* sjt_functionParam544 = 0;
            sjs_string* sjt_functionParam545 = 0;
            float sjt_functionParam546;
            int32_t sjt_functionParam547;
            sjs_shader* sjt_functionParam548 = 0;
            sjs_string* sjt_functionParam549 = 0;
            float sjt_functionParam550;
            int32_t sjt_functionParam551;
            sjs_shader* sjt_functionParam552 = 0;
            sjs_string* sjt_functionParam553 = 0;
            sjs_mat4* sjt_functionParam554 = 0;
            int32_t sjt_functionParam555;
            sjs_shader* sjt_functionParam556 = 0;
            sjs_string* sjt_functionParam557 = 0;
            sjs_mat4* sjt_functionParam558 = 0;
            int32_t sjt_functionParam559;
            sjs_shader* sjt_functionParam560 = 0;
            sjs_string* sjt_functionParam561 = 0;
            sjs_mat4* sjt_functionParam562 = 0;
            sjs_scene2d* sjt_functionParam563 = 0;
            float sjt_math2411;
            float sjt_math2412;
            float sjt_math2413;
            float sjt_math2414;
            sjs_scene2d* sjt_parent278 = 0;
            sjs_scene2d* sjt_parent279 = 0;
            sjs_scene2d* sjt_parent280 = 0;
            sjs_scene2d* sjt_parent281 = 0;
            sjs_scene2d* sjt_parent282 = 0;
            sjs_boxvertexbuffer* sjt_parent283 = 0;
            sjs_scene2d* sjt_parent284 = 0;
            sjs_boxvertexbuffer* sjt_parent285 = 0;

            sjt_dot1703 = _parent;
            ifValue19 = (sjt_dot1703->_scenebuffer1._refCount != -1 ? &sjt_dot1703->_scenebuffer1 : 0);
            sjt_dot1704 = _parent;
            ifValue20 = (sjt_dot1704->_scenebuffer2._refCount != -1 ? &sjt_dot1704->_scenebuffer2 : 0);
            sjt_dot1705 = _parent;
            ifValue21 = (sjt_dot1705->_vertexbuffer1._refCount != -1 ? &sjt_dot1705->_vertexbuffer1 : 0);
            sjt_dot1706 = _parent;
            ifValue22 = (sjt_dot1706->_vertexbuffer2._refCount != -1 ? &sjt_dot1706->_vertexbuffer2 : 0);
            sjt_dot1707 = ifValue19;
            sjt_functionParam483 = &sjt_dot1707->framebuffer;
            sjf_glpushframebuffer(sjt_functionParam483);
            sjt_dot1717 = _parent;
            sjt_parent278 = &sjt_dot1717->_innerscene;
            sjt_dot1718 = ifValue19;
            sjt_functionParam494 = &sjt_dot1718->size;
            sjf_scene2d_setsize(sjt_parent278, sjt_functionParam494);
            sjt_dot1726 = _parent;
            sjt_parent279 = &sjt_dot1726->_innerscene;
            sjf_scene2d_start(sjt_parent279);
            sjt_callback6 = cb;
            sjt_dot1727 = _parent;
            sjt_functionParam497 = &sjt_dot1727->_innerscene;
            sjt_callback6._cb(sjt_callback6._parent, sjt_functionParam497);
            sjt_dot1730 = _parent;
            sjt_parent280 = &sjt_dot1730->_innerscene;
            sjf_scene2d_end(sjt_parent280);
            sjt_dot1731 = ifValue19;
            sjt_functionParam500 = &sjt_dot1731->framebuffer;
            sjf_glpopframebuffer(sjt_functionParam500);
            sjt_dot1732 = ifValue20;
            sjt_functionParam501 = &sjt_dot1732->framebuffer;
            sjf_glpushframebuffer(sjt_functionParam501);
            sjt_dot1733 = _parent;
            sjt_parent281 = &sjt_dot1733->_innerscene;
            sjt_dot1734 = ifValue20;
            sjt_functionParam502 = &sjt_dot1734->size;
            sjf_scene2d_setsize(sjt_parent281, sjt_functionParam502);
            sjt_dot1735 = _parent;
            sjt_parent282 = &sjt_dot1735->_innerscene;
            sjf_scene2d_start(sjt_parent282);
            sjt_functionParam503 = sjv_gltexture_gl_texture_2d;
            sjt_dot1736 = ifValue19;
            sjt_functionParam504 = &sjt_dot1736->texture;
            sjf_glbindtexture(sjt_functionParam503, sjt_functionParam504);
            sjt_functionParam505 = &sjv_blurverticalshader;
            sjf_gluseprogram(sjt_functionParam505);
            sjt_functionParam506 = sjv_glblendfunctype_gl_one;
            sjt_functionParam507 = sjv_glblendfunctype_gl_one_minus_src_alpha;
            sjf_glblendfunc(sjt_functionParam506, sjt_functionParam507);
            sjt_functionParam509 = &sjv_blurverticalshader;
            sjt_call162._refCount = 1;
            sjt_call162.count = 7;
            sjt_call162.data._refCount = 1;
            sjt_call162.data.datasize = 8;
            sjt_call162.data.data = (void*)sjg_string28;
            sjt_call162.data._isglobal = true;
            sjt_call162.data.count = 8;
            sjf_array_char(&sjt_call162.data);
            sjf_string(&sjt_call162);
            sjt_functionParam510 = &sjt_call162;
            sjf_glgetuniformlocation(sjt_functionParam509, sjt_functionParam510, &sjt_functionParam508);
            sjt_functionParam511 = 0;
            sjf_gluniformi32(sjt_functionParam508, sjt_functionParam511);
            sjt_functionParam513 = &sjv_blurverticalshader;
            sjt_call163._refCount = 1;
            sjt_call163.count = 5;
            sjt_call163.data._refCount = 1;
            sjt_call163.data.datasize = 6;
            sjt_call163.data.data = (void*)sjg_string34;
            sjt_call163.data._isglobal = true;
            sjt_call163.data.count = 6;
            sjf_array_char(&sjt_call163.data);
            sjf_string(&sjt_call163);
            sjt_functionParam514 = &sjt_call163;
            sjf_glgetuniformlocation(sjt_functionParam513, sjt_functionParam514, &sjt_functionParam512);
            sjt_dot1737 = _parent;
            sjt_functionParam515 = sjt_dot1737->radius;
            sjf_gluniformf32(sjt_functionParam512, sjt_functionParam515);
            sjt_functionParam517 = &sjv_blurverticalshader;
            sjt_call164._refCount = 1;
            sjt_call164.count = 8;
            sjt_call164.data._refCount = 1;
            sjt_call164.data.datasize = 9;
            sjt_call164.data.data = (void*)sjg_string35;
            sjt_call164.data._isglobal = true;
            sjt_call164.data.count = 9;
            sjf_array_char(&sjt_call164.data);
            sjf_string(&sjt_call164);
            sjt_functionParam518 = &sjt_call164;
            sjf_glgetuniformlocation(sjt_functionParam517, sjt_functionParam518, &sjt_functionParam516);
            sjt_math2411 = 1.0f;
            sjt_dot1739 = ifValue19;
            sjt_dot1738 = &sjt_dot1739->size;
            sjt_cast20 = sjt_dot1738->h;
            sjt_math2412 = (float)sjt_cast20;
            sjt_functionParam519 = sjt_math2411 / sjt_math2412;
            sjf_gluniformf32(sjt_functionParam516, sjt_functionParam519);
            sjt_functionParam521 = &sjv_blurverticalshader;
            sjt_call165._refCount = 1;
            sjt_call165.count = 5;
            sjt_call165.data._refCount = 1;
            sjt_call165.data.datasize = 6;
            sjt_call165.data.data = (void*)sjg_string29;
            sjt_call165.data._isglobal = true;
            sjt_call165.data.count = 6;
            sjf_array_char(&sjt_call165.data);
            sjf_string(&sjt_call165);
            sjt_functionParam522 = &sjt_call165;
            sjf_glgetuniformlocation(sjt_functionParam521, sjt_functionParam522, &sjt_functionParam520);
            sjt_dot1741 = _parent;
            sjt_dot1740 = &sjt_dot1741->_innerscene;
            sjt_functionParam523 = &sjt_dot1740->model;
            sjf_gluniformmat4(sjt_functionParam520, sjt_functionParam523);
            sjt_functionParam525 = &sjv_blurverticalshader;
            sjt_call166._refCount = 1;
            sjt_call166.count = 4;
            sjt_call166.data._refCount = 1;
            sjt_call166.data.datasize = 5;
            sjt_call166.data.data = (void*)sjg_string30;
            sjt_call166.data._isglobal = true;
            sjt_call166.data.count = 5;
            sjf_array_char(&sjt_call166.data);
            sjf_string(&sjt_call166);
            sjt_functionParam526 = &sjt_call166;
            sjf_glgetuniformlocation(sjt_functionParam525, sjt_functionParam526, &sjt_functionParam524);
            sjt_dot1743 = _parent;
            sjt_dot1742 = &sjt_dot1743->_innerscene;
            sjt_functionParam527 = &sjt_dot1742->view;
            sjf_gluniformmat4(sjt_functionParam524, sjt_functionParam527);
            sjt_functionParam529 = &sjv_blurverticalshader;
            sjt_call167._refCount = 1;
            sjt_call167.count = 10;
            sjt_call167.data._refCount = 1;
            sjt_call167.data.datasize = 11;
            sjt_call167.data.data = (void*)sjg_string19;
            sjt_call167.data._isglobal = true;
            sjt_call167.data.count = 11;
            sjf_array_char(&sjt_call167.data);
            sjf_string(&sjt_call167);
            sjt_functionParam530 = &sjt_call167;
            sjf_glgetuniformlocation(sjt_functionParam529, sjt_functionParam530, &sjt_functionParam528);
            sjt_dot1745 = _parent;
            sjt_dot1744 = &sjt_dot1745->_innerscene;
            sjt_functionParam531 = &sjt_dot1744->projection;
            sjf_gluniformmat4(sjt_functionParam528, sjt_functionParam531);
            sjt_parent283 = ifValue21;
            sjt_dot1746 = _parent;
            sjt_functionParam532 = &sjt_dot1746->_innerscene;
            sjf_boxvertexbuffer_render(sjt_parent283, sjt_functionParam532);
            sjt_dot1747 = _parent;
            sjt_parent284 = &sjt_dot1747->_innerscene;
            sjf_scene2d_end(sjt_parent284);
            sjt_dot1748 = ifValue20;
            sjt_functionParam533 = &sjt_dot1748->framebuffer;
            sjf_glpopframebuffer(sjt_functionParam533);
            sjt_functionParam534 = sjv_gltexture_gl_texture_2d;
            sjt_dot1749 = ifValue20;
            sjt_functionParam535 = &sjt_dot1749->texture;
            sjf_glbindtexture(sjt_functionParam534, sjt_functionParam535);
            sjt_functionParam536 = &sjv_blurhorizontalshader;
            sjf_gluseprogram(sjt_functionParam536);
            sjt_functionParam537 = sjv_glblendfunctype_gl_one;
            sjt_functionParam538 = sjv_glblendfunctype_gl_one_minus_src_alpha;
            sjf_glblendfunc(sjt_functionParam537, sjt_functionParam538);
            sjt_functionParam540 = &sjv_blurhorizontalshader;
            sjt_call168._refCount = 1;
            sjt_call168.count = 7;
            sjt_call168.data._refCount = 1;
            sjt_call168.data.datasize = 8;
            sjt_call168.data.data = (void*)sjg_string28;
            sjt_call168.data._isglobal = true;
            sjt_call168.data.count = 8;
            sjf_array_char(&sjt_call168.data);
            sjf_string(&sjt_call168);
            sjt_functionParam541 = &sjt_call168;
            sjf_glgetuniformlocation(sjt_functionParam540, sjt_functionParam541, &sjt_functionParam539);
            sjt_functionParam542 = 0;
            sjf_gluniformi32(sjt_functionParam539, sjt_functionParam542);
            sjt_functionParam544 = &sjv_blurhorizontalshader;
            sjt_call169._refCount = 1;
            sjt_call169.count = 5;
            sjt_call169.data._refCount = 1;
            sjt_call169.data.datasize = 6;
            sjt_call169.data.data = (void*)sjg_string34;
            sjt_call169.data._isglobal = true;
            sjt_call169.data.count = 6;
            sjf_array_char(&sjt_call169.data);
            sjf_string(&sjt_call169);
            sjt_functionParam545 = &sjt_call169;
            sjf_glgetuniformlocation(sjt_functionParam544, sjt_functionParam545, &sjt_functionParam543);
            sjt_dot1750 = _parent;
            sjt_functionParam546 = sjt_dot1750->radius;
            sjf_gluniformf32(sjt_functionParam543, sjt_functionParam546);
            sjt_functionParam548 = &sjv_blurhorizontalshader;
            sjt_call170._refCount = 1;
            sjt_call170.count = 8;
            sjt_call170.data._refCount = 1;
            sjt_call170.data.datasize = 9;
            sjt_call170.data.data = (void*)sjg_string35;
            sjt_call170.data._isglobal = true;
            sjt_call170.data.count = 9;
            sjf_array_char(&sjt_call170.data);
            sjf_string(&sjt_call170);
            sjt_functionParam549 = &sjt_call170;
            sjf_glgetuniformlocation(sjt_functionParam548, sjt_functionParam549, &sjt_functionParam547);
            sjt_math2413 = 1.0f;
            sjt_dot1752 = ifValue20;
            sjt_dot1751 = &sjt_dot1752->size;
            sjt_cast21 = sjt_dot1751->w;
            sjt_math2414 = (float)sjt_cast21;
            sjt_functionParam550 = sjt_math2413 / sjt_math2414;
            sjf_gluniformf32(sjt_functionParam547, sjt_functionParam550);
            sjt_functionParam552 = &sjv_blurhorizontalshader;
            sjt_call171._refCount = 1;
            sjt_call171.count = 5;
            sjt_call171.data._refCount = 1;
            sjt_call171.data.datasize = 6;
            sjt_call171.data.data = (void*)sjg_string29;
            sjt_call171.data._isglobal = true;
            sjt_call171.data.count = 6;
            sjf_array_char(&sjt_call171.data);
            sjf_string(&sjt_call171);
            sjt_functionParam553 = &sjt_call171;
            sjf_glgetuniformlocation(sjt_functionParam552, sjt_functionParam553, &sjt_functionParam551);
            sjt_dot1753 = scene;
            sjt_functionParam554 = &sjt_dot1753->model;
            sjf_gluniformmat4(sjt_functionParam551, sjt_functionParam554);
            sjt_functionParam556 = &sjv_blurhorizontalshader;
            sjt_call172._refCount = 1;
            sjt_call172.count = 4;
            sjt_call172.data._refCount = 1;
            sjt_call172.data.datasize = 5;
            sjt_call172.data.data = (void*)sjg_string30;
            sjt_call172.data._isglobal = true;
            sjt_call172.data.count = 5;
            sjf_array_char(&sjt_call172.data);
            sjf_string(&sjt_call172);
            sjt_functionParam557 = &sjt_call172;
            sjf_glgetuniformlocation(sjt_functionParam556, sjt_functionParam557, &sjt_functionParam555);
            sjt_dot1754 = scene;
            sjt_functionParam558 = &sjt_dot1754->view;
            sjf_gluniformmat4(sjt_functionParam555, sjt_functionParam558);
            sjt_functionParam560 = &sjv_blurhorizontalshader;
            sjt_call173._refCount = 1;
            sjt_call173.count = 10;
            sjt_call173.data._refCount = 1;
            sjt_call173.data.datasize = 11;
            sjt_call173.data.data = (void*)sjg_string19;
            sjt_call173.data._isglobal = true;
            sjt_call173.data.count = 11;
            sjf_array_char(&sjt_call173.data);
            sjf_string(&sjt_call173);
            sjt_functionParam561 = &sjt_call173;
            sjf_glgetuniformlocation(sjt_functionParam560, sjt_functionParam561, &sjt_functionParam559);
            sjt_dot1755 = scene;
            sjt_functionParam562 = &sjt_dot1755->projection;
            sjf_gluniformmat4(sjt_functionParam559, sjt_functionParam562);
            sjt_parent285 = ifValue22;
            sjt_functionParam563 = scene;
            sjf_boxvertexbuffer_render(sjt_parent285, sjt_functionParam563);

            if (sjt_call162._refCount == 1) { sjf_string_destroy(&sjt_call162); }
;
            if (sjt_call163._refCount == 1) { sjf_string_destroy(&sjt_call163); }
;
            if (sjt_call164._refCount == 1) { sjf_string_destroy(&sjt_call164); }
;
            if (sjt_call165._refCount == 1) { sjf_string_destroy(&sjt_call165); }
;
            if (sjt_call166._refCount == 1) { sjf_string_destroy(&sjt_call166); }
;
            if (sjt_call167._refCount == 1) { sjf_string_destroy(&sjt_call167); }
;
            if (sjt_call168._refCount == 1) { sjf_string_destroy(&sjt_call168); }
;
            if (sjt_call169._refCount == 1) { sjf_string_destroy(&sjt_call169); }
;
            if (sjt_call170._refCount == 1) { sjf_string_destroy(&sjt_call170); }
;
            if (sjt_call171._refCount == 1) { sjf_string_destroy(&sjt_call171); }
;
            if (sjt_call172._refCount == 1) { sjf_string_destroy(&sjt_call172); }
;
            if (sjt_call173._refCount == 1) { sjf_string_destroy(&sjt_call173); }
;
        }
    }

    if (sjt_call154._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_call154); }
;
    if (sjt_call155._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_call155); }
;
    if (sjt_call156._refCount == 1) { sjf_scenebuffer_destroy(&sjt_call156); }
;
    if (sjt_call157._refCount == 1) { sjf_scenebuffer_destroy(&sjt_call157); }
;
}

void sjf_blureffect_setrect(sjs_blureffect* _parent, sjs_rect* rect_, cb_rect_void cb) {
    bool result12;
    sjs_rect sjt_call153 = { -1 };
    float sjt_compare121;
    float sjt_compare122;
    sjs_blureffect* sjt_dot1647 = 0;
    sjs_blureffect* sjt_dot1671 = 0;
    sjs_rect* sjt_functionParam477 = 0;
    bool sjt_ifElse56;
    bool sjt_ifElse59;
    bool sjt_not9;
    sjs_rect* sjt_parent274 = 0;

    sjt_dot1647 = _parent;
    sjt_parent274 = &sjt_dot1647->_rect;
    sjt_functionParam477 = rect_;
    sjf_rect_isequal(sjt_parent274, sjt_functionParam477, &sjt_not9);
    result12 = !sjt_not9;
    sjt_ifElse56 = result12;
    if (sjt_ifElse56) {
        sjs_rect* sjt_copy92 = 0;
        sjs_blureffect* sjt_dot1648 = 0;
        sjs_blureffect* sjt_dot1649 = 0;
        sjs_blureffect* sjt_dot1662 = 0;
        sjs_blureffect* sjt_dot1670 = 0;
        bool sjt_isEmpty21;
        sjs_scenebuffer* sjt_isEmpty22 = 0;
        bool sjt_isEmpty23;
        sjs_scenebuffer* sjt_isEmpty24 = 0;

        sjt_dot1648 = _parent;
        sjt_copy92 = rect_;
        if (sjt_dot1648->_rect._refCount == 1) { sjf_rect_destroy(&sjt_dot1648->_rect); }
;
        sjt_dot1648->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1648->_rect, sjt_copy92);
        sjt_dot1649 = _parent;
        sjt_isEmpty22 = (sjt_dot1649->_scenebuffer1._refCount != -1 ? &sjt_dot1649->_scenebuffer1 : 0);
        sjt_isEmpty21 = (sjt_isEmpty22 != 0);
        if (sjt_isEmpty21) {
            sjs_scenebuffer* ifValue15 = 0;
            bool result13;
            sjs_size sjt_call151 = { -1 };
            sjs_blureffect* sjt_dot1650 = 0;
            sjs_scenebuffer* sjt_dot1655 = 0;
            sjs_rect* sjt_dot1656 = 0;
            sjs_blureffect* sjt_dot1657 = 0;
            sjs_rect* sjt_dot1658 = 0;
            sjs_blureffect* sjt_dot1659 = 0;
            sjs_size* sjt_functionParam478 = 0;
            bool sjt_ifElse57;
            bool sjt_not10;
            sjs_size* sjt_parent275 = 0;

            sjt_dot1650 = _parent;
            ifValue15 = (sjt_dot1650->_scenebuffer1._refCount != -1 ? &sjt_dot1650->_scenebuffer1 : 0);
            sjt_dot1655 = ifValue15;
            sjt_parent275 = &sjt_dot1655->size;
            sjt_call151._refCount = 1;
            sjt_dot1657 = _parent;
            sjt_dot1656 = &sjt_dot1657->_rect;
            sjt_call151.w = sjt_dot1656->w;
            sjt_dot1659 = _parent;
            sjt_dot1658 = &sjt_dot1659->_rect;
            sjt_call151.h = sjt_dot1658->h;
            sjf_size(&sjt_call151);
            sjt_functionParam478 = &sjt_call151;
            sjf_size_isequal(sjt_parent275, sjt_functionParam478, &sjt_not10);
            result13 = !sjt_not10;
            sjt_ifElse57 = result13;
            if (sjt_ifElse57) {
                sjs_blureffect* sjt_dot1660 = 0;
                sjs_blureffect* sjt_dot1661 = 0;

                sjt_dot1660 = _parent;
                if (sjt_dot1660->_scenebuffer1._refCount == 1) { sjf_scenebuffer_destroy(&sjt_dot1660->_scenebuffer1); }
;
                sjt_dot1660->_scenebuffer1._refCount = -1;
                sjt_dot1661 = _parent;
                if (sjt_dot1661->_vertexbuffer1._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_dot1661->_vertexbuffer1); }
;
                sjt_dot1661->_vertexbuffer1._refCount = -1;
            }

            if (sjt_call151._refCount == 1) { sjf_size_destroy(&sjt_call151); }
;
        }

        sjt_dot1662 = _parent;
        sjt_isEmpty24 = (sjt_dot1662->_scenebuffer2._refCount != -1 ? &sjt_dot1662->_scenebuffer2 : 0);
        sjt_isEmpty23 = (sjt_isEmpty24 != 0);
        if (sjt_isEmpty23) {
            sjs_scenebuffer* ifValue16 = 0;
            bool result14;
            sjs_size sjt_call152 = { -1 };
            sjs_blureffect* sjt_dot1663 = 0;
            sjs_scenebuffer* sjt_dot1664 = 0;
            sjs_rect* sjt_dot1665 = 0;
            sjs_blureffect* sjt_dot1666 = 0;
            sjs_rect* sjt_dot1667 = 0;
            sjs_blureffect* sjt_dot1668 = 0;
            sjs_size* sjt_functionParam479 = 0;
            bool sjt_ifElse58;
            bool sjt_not11;
            sjs_size* sjt_parent276 = 0;

            sjt_dot1663 = _parent;
            ifValue16 = (sjt_dot1663->_scenebuffer2._refCount != -1 ? &sjt_dot1663->_scenebuffer2 : 0);
            sjt_dot1664 = ifValue16;
            sjt_parent276 = &sjt_dot1664->size;
            sjt_call152._refCount = 1;
            sjt_dot1666 = _parent;
            sjt_dot1665 = &sjt_dot1666->_rect;
            sjt_call152.w = sjt_dot1665->w;
            sjt_dot1668 = _parent;
            sjt_dot1667 = &sjt_dot1668->_rect;
            sjt_call152.h = sjt_dot1667->h;
            sjf_size(&sjt_call152);
            sjt_functionParam479 = &sjt_call152;
            sjf_size_isequal(sjt_parent276, sjt_functionParam479, &sjt_not11);
            result14 = !sjt_not11;
            sjt_ifElse58 = result14;
            if (sjt_ifElse58) {
                sjs_blureffect* sjt_dot1669 = 0;

                sjt_dot1669 = _parent;
                if (sjt_dot1669->_scenebuffer2._refCount == 1) { sjf_scenebuffer_destroy(&sjt_dot1669->_scenebuffer2); }
;
                sjt_dot1669->_scenebuffer2._refCount = -1;
            }

            if (sjt_call152._refCount == 1) { sjf_size_destroy(&sjt_call152); }
;
        }

        sjt_dot1670 = _parent;
        if (sjt_dot1670->_vertexbuffer2._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_dot1670->_vertexbuffer2); }
;
        sjt_dot1670->_vertexbuffer2._refCount = -1;
    }

    sjt_dot1671 = _parent;
    sjt_compare121 = sjt_dot1671->radius;
    sjt_compare122 = 0.0f;
    sjt_ifElse59 = sjt_compare121 == sjt_compare122;
    if (sjt_ifElse59) {
        cb_rect_void sjt_callback3;
        sjs_blureffect* sjt_dot1672 = 0;
        sjs_rect* sjt_functionParam480 = 0;

        sjt_callback3 = cb;
        sjt_dot1672 = _parent;
        sjt_functionParam480 = &sjt_dot1672->_rect;
        sjt_callback3._cb(sjt_callback3._parent, sjt_functionParam480);
    } else {
        cb_rect_void sjt_callback4;
        sjs_rect* sjt_dot1673 = 0;
        sjs_blureffect* sjt_dot1674 = 0;
        sjs_rect* sjt_dot1675 = 0;
        sjs_blureffect* sjt_dot1676 = 0;
        sjs_rect* sjt_functionParam481 = 0;

        sjt_callback4 = cb;
        sjt_call153._refCount = 1;
        sjt_call153.x = 0;
        sjt_call153.y = 0;
        sjt_dot1674 = _parent;
        sjt_dot1673 = &sjt_dot1674->_rect;
        sjt_call153.w = sjt_dot1673->w;
        sjt_dot1676 = _parent;
        sjt_dot1675 = &sjt_dot1676->_rect;
        sjt_call153.h = sjt_dot1675->h;
        sjf_rect(&sjt_call153);
        sjt_functionParam481 = &sjt_call153;
        sjt_callback4._cb(sjt_callback4._parent, sjt_functionParam481);
    }

    if (sjt_call153._refCount == 1) { sjf_rect_destroy(&sjt_call153); }
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
    _this->boxrenderer._refCount = 1;
    sjf_boxrenderer_copy((_this->boxrenderer._refCount != -1 ? &_this->boxrenderer : 0), (_from->boxrenderer._refCount != -1 ? &_from->boxrenderer : 0));
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

void sjf_boxelement_getrect(sjs_boxelement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy9 = 0;
    sjs_boxelement* sjt_dot169 = 0;

    sjt_dot169 = _parent;
    sjt_copy9 = &sjt_dot169->rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy9);
}

void sjf_boxelement_getrect_heap(sjs_boxelement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy10 = 0;
    sjs_boxelement* sjt_dot170 = 0;

    sjt_dot170 = _parent;
    sjt_copy10 = &sjt_dot170->rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy10);
}

void sjf_boxelement_getsize(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_boxelement* sjt_dot167 = 0;
    sjs_size* sjt_functionParam59 = 0;
    sjs_size* sjt_parent49 = 0;

    sjt_dot167 = _parent;
    sjt_parent49 = &sjt_dot167->idealsize;
    sjt_functionParam59 = maxsize;
    sjf_size_min(sjt_parent49, sjt_functionParam59, _return);
}

void sjf_boxelement_getsize_heap(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_boxelement* sjt_dot168 = 0;
    sjs_size* sjt_functionParam60 = 0;
    sjs_size* sjt_parent50 = 0;

    sjt_dot168 = _parent;
    sjt_parent50 = &sjt_dot168->idealsize;
    sjt_functionParam60 = maxsize;
    sjf_size_min_heap(sjt_parent50, sjt_functionParam60, _return);
}

void sjf_boxelement_heap(sjs_boxelement* _this) {
}

void sjf_boxelement_render(sjs_boxelement* _parent, sjs_scene2d* scene) {
    sjs_boxrenderer sjt_call12 = { -1 };
    sjs_boxelement* sjt_dot182 = 0;
    sjs_boxelement* sjt_dot186 = 0;
    bool sjt_ifElse22;
    bool sjt_ifElse23;
    sjs_boxrenderer* sjt_isEmpty7 = 0;
    sjs_boxrenderer* sjt_isEmpty8 = 0;

    sjt_dot182 = _parent;
    sjt_isEmpty7 = (sjt_dot182->boxrenderer._refCount != -1 ? &sjt_dot182->boxrenderer : 0);
    sjt_ifElse22 = (sjt_isEmpty7 == 0);
    if (sjt_ifElse22) {
        sjs_boxrenderer* sjt_copy12 = 0;
        sjs_rect* sjt_copy13 = 0;
        sjs_color* sjt_copy14 = 0;
        sjs_boxelement* sjt_dot183 = 0;
        sjs_boxelement* sjt_dot184 = 0;
        sjs_boxelement* sjt_dot185 = 0;

        sjt_dot183 = _parent;
        sjt_call12._refCount = 1;
        sjt_dot184 = _parent;
        sjt_copy13 = &sjt_dot184->rect;
        sjt_call12.rect._refCount = 1;
        sjf_rect_copy(&sjt_call12.rect, sjt_copy13);
        sjt_dot185 = _parent;
        sjt_copy14 = &sjt_dot185->color;
        sjt_call12.color._refCount = 1;
        sjf_color_copy(&sjt_call12.color, sjt_copy14);
        sjf_boxrenderer(&sjt_call12);
        sjt_copy12 = &sjt_call12;
        if (sjt_dot183->boxrenderer._refCount == 1) { sjf_boxrenderer_destroy(&sjt_dot183->boxrenderer); }
;
        sjt_dot183->boxrenderer._refCount = 1;
        sjf_boxrenderer_copy(&sjt_dot183->boxrenderer, sjt_copy12);
    }

    sjt_dot186 = _parent;
    sjt_isEmpty8 = (sjt_dot186->boxrenderer._refCount != -1 ? &sjt_dot186->boxrenderer : 0);
    sjt_ifElse23 = (sjt_isEmpty8 != 0);
    if (sjt_ifElse23) {
        sjs_boxelement* sjt_dot187 = 0;
        sjs_scene2d* sjt_functionParam62 = 0;
        sjs_boxrenderer* sjt_parent52 = 0;

        sjt_dot187 = _parent;
        sjt_parent52 = (sjt_dot187->boxrenderer._refCount != -1 ? &sjt_dot187->boxrenderer : 0);
        sjt_functionParam62 = scene;
        sjf_boxrenderer_render(sjt_parent52, sjt_functionParam62);
    }

    if (sjt_call12._refCount == 1) { sjf_boxrenderer_destroy(&sjt_call12); }
;
}

void sjf_boxelement_setrect(sjs_boxelement* _parent, sjs_rect* rect_) {
    bool result2;
    sjs_boxelement* sjt_dot179 = 0;
    sjs_rect* sjt_functionParam61 = 0;
    bool sjt_ifElse21;
    bool sjt_not1;
    sjs_rect* sjt_parent51 = 0;

    sjt_dot179 = _parent;
    sjt_parent51 = &sjt_dot179->rect;
    sjt_functionParam61 = rect_;
    sjf_rect_isequal(sjt_parent51, sjt_functionParam61, &sjt_not1);
    result2 = !sjt_not1;
    sjt_ifElse21 = result2;
    if (sjt_ifElse21) {
        sjs_rect* sjt_copy11 = 0;
        sjs_boxelement* sjt_dot180 = 0;
        sjs_boxelement* sjt_dot181 = 0;

        sjt_dot180 = _parent;
        sjt_copy11 = rect_;
        if (sjt_dot180->rect._refCount == 1) { sjf_rect_destroy(&sjt_dot180->rect); }
;
        sjt_dot180->rect._refCount = 1;
        sjf_rect_copy(&sjt_dot180->rect, sjt_copy11);
        sjt_dot181 = _parent;
        if (sjt_dot181->boxrenderer._refCount == 1) { sjf_boxrenderer_destroy(&sjt_dot181->boxrenderer); }
;
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

void sjf_boxvertexbuffer(sjs_boxvertexbuffer* _this) {
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
    float x0 = (float)_this->rect.x;
    float x1 = (float)(_this->rect.x + _this->rect.w);
    float y0 = (float)_this->rect.y;
    float y1 = (float)(_this->rect.y + _this->rect.h);
    float s0 = 0.0f;
    float s1 = 1.0f;
    float t1 = 0.0f;
    float t0 = 1.0f;
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

void sjf_boxvertexbuffer_copy(sjs_boxvertexbuffer* _this, sjs_boxvertexbuffer* _from) {
    _this->rect._refCount = 1;
    sjf_rect_copy(&_this->rect, &_from->rect);
    _this->buffer = _from->buffer;
    ptr_retain(_this->buffer);
}

void sjf_boxvertexbuffer_destroy(sjs_boxvertexbuffer* _this) {
    if (ptr_release(_this->buffer)) {
        vertex_buffer_delete(_this->buffer);
    }  
    if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
}

void sjf_boxvertexbuffer_heap(sjs_boxvertexbuffer* _this) {
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
    float x0 = (float)_this->rect.x;
    float x1 = (float)(_this->rect.x + _this->rect.w);
    float y0 = (float)_this->rect.y;
    float y1 = (float)(_this->rect.y + _this->rect.h);
    float s0 = 0.0f;
    float s1 = 1.0f;
    float t1 = 0.0f;
    float t0 = 1.0f;
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

void sjf_boxvertexbuffer_render(sjs_boxvertexbuffer* _parent, sjs_scene2d* scene) {
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_color(sjs_color* _this) {
}

void sjf_color_asvec3(sjs_color* _parent, sjs_vec3* _return) {
    sjs_color* sjt_dot1454 = 0;
    sjs_color* sjt_dot1455 = 0;
    sjs_color* sjt_dot1456 = 0;

    _return->_refCount = 1;
    sjt_dot1454 = _parent;
    _return->x = sjt_dot1454->r;
    sjt_dot1455 = _parent;
    _return->y = sjt_dot1455->g;
    sjt_dot1456 = _parent;
    _return->z = sjt_dot1456->b;
    sjf_vec3(_return);
}

void sjf_color_asvec3_heap(sjs_color* _parent, sjs_vec3** _return) {
    sjs_color* sjt_dot1457 = 0;
    sjs_color* sjt_dot1458 = 0;
    sjs_color* sjt_dot1459 = 0;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot1457 = _parent;
    (*_return)->x = sjt_dot1457->r;
    sjt_dot1458 = _parent;
    (*_return)->y = sjt_dot1458->g;
    sjt_dot1459 = _parent;
    (*_return)->z = sjt_dot1459->b;
    sjf_vec3_heap((*_return));
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
    debugout("%s\n", (char*)data->data.data);
}

void sjf_f32_asstring(float val, sjs_string* _return) {
    int32_t sjt_math2235;
    int32_t sjt_math2236;
    int32_t sjt_math2237;
    int32_t sjt_math2238;
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = malloc(sizeof(char) * 50);
    snprintf((char*)sjv_data, 50, "%f", val);
    sjv_count = strlen((char*)sjv_data);
    _return->_refCount = 1;
    _return->count = sjv_count;
    _return->data._refCount = 1;
    sjt_math2235 = sjv_count;
    sjt_math2236 = 1;
    _return->data.datasize = sjt_math2235 + sjt_math2236;
    _return->data.data = sjv_data;
    _return->data._isglobal = false;
    sjt_math2237 = sjv_count;
    sjt_math2238 = 1;
    _return->data.count = sjt_math2237 + sjt_math2238;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_f32_asstring_heap(float val, sjs_string** _return) {
    int32_t sjt_math2239;
    int32_t sjt_math2240;
    int32_t sjt_math2241;
    int32_t sjt_math2242;
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = malloc(sizeof(char) * 50);
    snprintf((char*)sjv_data, 50, "%f", val);
    sjv_count = strlen((char*)sjv_data);
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = sjv_count;
    (*_return)->data._refCount = 1;
    sjt_math2239 = sjv_count;
    sjt_math2240 = 1;
    (*_return)->data.datasize = sjt_math2239 + sjt_math2240;
    (*_return)->data.data = sjv_data;
    (*_return)->data._isglobal = false;
    sjt_math2241 = sjv_count;
    sjt_math2242 = 1;
    (*_return)->data.count = sjt_math2241 + sjt_math2242;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_f32_atan2(float y, float x, float* _return) {
    float sjv_result;

    sjv_result = 0.0f;
    sjv_result = atan2f(y, x);
    (*_return) = sjv_result;
}

void sjf_f32_compare(float l, float r, int32_t* _return) {
    float sjt_compare75;
    float sjt_compare76;
    bool sjt_ifElse32;

    sjt_compare75 = l;
    sjt_compare76 = r;
    sjt_ifElse32 = sjt_compare75 == sjt_compare76;
    if (sjt_ifElse32) {
        (*_return) = 0;
    } else {
        float sjt_compare77;
        float sjt_compare78;
        bool sjt_ifElse33;

        sjt_compare77 = l;
        sjt_compare78 = r;
        sjt_ifElse33 = sjt_compare77 < sjt_compare78;
        if (sjt_ifElse33) {
            int32_t result4;
            int32_t sjt_negate2;

            sjt_negate2 = 1;
            result4 = -sjt_negate2;
            (*_return) = result4;
        } else {
            (*_return) = 1;
        }
    }
}

void sjf_f32_hash(float val, uint32_t* _return) {
    uint32_t sjv_result;

    sjv_result = (uint32_t)0u;
    int32_t* p = (int32_t*)&val;
    sjv_result = *p;
    (*_return) = sjv_result;
}

void sjf_f32_max(float a, float b, float* _return) {
    float sjt_compare93;
    float sjt_compare94;
    bool sjt_ifElse45;

    sjt_compare93 = a;
    sjt_compare94 = b;
    sjt_ifElse45 = sjt_compare93 < sjt_compare94;
    if (sjt_ifElse45) {
        (*_return) = b;
    } else {
        (*_return) = a;
    }
}

void sjf_f32_min(float a, float b, float* _return) {
    float sjt_compare91;
    float sjt_compare92;
    bool sjt_ifElse44;

    sjt_compare91 = a;
    sjt_compare92 = b;
    sjt_ifElse44 = sjt_compare91 < sjt_compare92;
    if (sjt_ifElse44) {
        (*_return) = a;
    } else {
        (*_return) = b;
    }
}

void sjf_f32_random(float* _return) {
    float sjv_x;

    sjv_x = 0.0f;
    sjv_x = (float)rand() / (float)RAND_MAX;
    (*_return) = sjv_x;
}

void sjf_f32_sqrt(float v, float* _return) {
    float sjv_result;

    sjv_result = 0.0f;
    sjv_result = sqrtf(v);
    (*_return) = sjv_result;
}

void sjf_f32_tan(float v, float* _return) {
    float sjv_result;

    sjv_result = 0.0f;
    sjv_result = tanf(v);
    (*_return) = sjv_result;
}

void sjf_fadeeffect_as_sji_effect(sjs_fadeeffect* _this, sji_effect* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_fadeeffect_effect_vtbl;
}

void sjf_fadeeffect_asinterface(sjs_fadeeffect* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_effect_typeId:  {
            sjf_fadeeffect_as_sji_effect(_this, (sji_effect*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_fadeeffect_copy(sjs_fadeeffect* _this, sjs_fadeeffect* _from) {
    _this->alpha = _from->alpha;
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    _this->_vertexbuffer._refCount = 1;
    sjf_boxvertexbuffer_copy((_this->_vertexbuffer._refCount != -1 ? &_this->_vertexbuffer : 0), (_from->_vertexbuffer._refCount != -1 ? &_from->_vertexbuffer : 0));
    _this->_scenebuffer._refCount = 1;
    sjf_scenebuffer_copy((_this->_scenebuffer._refCount != -1 ? &_this->_scenebuffer : 0), (_from->_scenebuffer._refCount != -1 ? &_from->_scenebuffer : 0));
    _this->_innerscene._refCount = 1;
    sjf_scene2d_copy(&_this->_innerscene, &_from->_innerscene);
}

void sjf_fadeeffect_destroy(sjs_fadeeffect* _this) {
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
    if (_this->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_this->_vertexbuffer); }
;
    if (_this->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_this->_scenebuffer); }
;
    if (_this->_innerscene._refCount == 1) { sjf_scene2d_destroy(&_this->_innerscene); }
;
}

void sjf_fadeeffect_getrect(sjs_fadeeffect* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy103 = 0;
    sjs_fadeeffect* sjt_dot1756 = 0;

    sjt_dot1756 = _parent;
    sjt_copy103 = &sjt_dot1756->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy103);
}

void sjf_fadeeffect_getrect_heap(sjs_fadeeffect* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy104 = 0;
    sjs_fadeeffect* sjt_dot1757 = 0;

    sjt_dot1757 = _parent;
    sjt_copy104 = &sjt_dot1757->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy104);
}

void sjf_fadeeffect_heap(sjs_fadeeffect* _this) {
}

void sjf_fadeeffect_render(sjs_fadeeffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb) {
    sjs_boxvertexbuffer sjt_call178 = { -1 };
    sjs_scenebuffer sjt_call179 = { -1 };
    sjs_fadeeffect* sjt_dot1773 = 0;
    sjs_fadeeffect* sjt_dot1776 = 0;
    sjs_fadeeffect* sjt_dot1782 = 0;
    sjs_fadeeffect* sjt_dot1783 = 0;
    bool sjt_ifElse68;
    bool sjt_ifElse69;
    sjs_boxvertexbuffer* sjt_isEmpty39 = 0;
    sjs_scenebuffer* sjt_isEmpty40 = 0;
    bool sjt_isEmpty41;
    sjs_scenebuffer* sjt_isEmpty42 = 0;
    bool sjt_isEmpty43;
    sjs_boxvertexbuffer* sjt_isEmpty44 = 0;

    sjt_dot1773 = _parent;
    sjt_isEmpty39 = (sjt_dot1773->_vertexbuffer._refCount != -1 ? &sjt_dot1773->_vertexbuffer : 0);
    sjt_ifElse68 = (sjt_isEmpty39 == 0);
    if (sjt_ifElse68) {
        sjs_boxvertexbuffer* sjt_copy106 = 0;
        sjs_rect* sjt_copy107 = 0;
        sjs_fadeeffect* sjt_dot1774 = 0;
        sjs_fadeeffect* sjt_dot1775 = 0;

        sjt_dot1774 = _parent;
        sjt_call178._refCount = 1;
        sjt_dot1775 = _parent;
        sjt_copy107 = &sjt_dot1775->_rect;
        sjt_call178.rect._refCount = 1;
        sjf_rect_copy(&sjt_call178.rect, sjt_copy107);
        sjf_boxvertexbuffer(&sjt_call178);
        sjt_copy106 = &sjt_call178;
        if (sjt_dot1774->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_dot1774->_vertexbuffer); }
;
        sjt_dot1774->_vertexbuffer._refCount = 1;
        sjf_boxvertexbuffer_copy(&sjt_dot1774->_vertexbuffer, sjt_copy106);
    }

    sjt_dot1776 = _parent;
    sjt_isEmpty40 = (sjt_dot1776->_scenebuffer._refCount != -1 ? &sjt_dot1776->_scenebuffer : 0);
    sjt_ifElse69 = (sjt_isEmpty40 == 0);
    if (sjt_ifElse69) {
        sjs_scenebuffer* sjt_copy108 = 0;
        sjs_fadeeffect* sjt_dot1777 = 0;
        sjs_rect* sjt_dot1778 = 0;
        sjs_fadeeffect* sjt_dot1779 = 0;
        sjs_rect* sjt_dot1780 = 0;
        sjs_fadeeffect* sjt_dot1781 = 0;

        sjt_dot1777 = _parent;
        sjt_call179._refCount = 1;
        sjt_call179.size._refCount = 1;
        sjt_dot1779 = _parent;
        sjt_dot1778 = &sjt_dot1779->_rect;
        sjt_call179.size.w = sjt_dot1778->w;
        sjt_dot1781 = _parent;
        sjt_dot1780 = &sjt_dot1781->_rect;
        sjt_call179.size.h = sjt_dot1780->h;
        sjf_size(&sjt_call179.size);
        sjt_call179.framebuffer._refCount = 1;
        sjt_call179.framebuffer.size._refCount = 1;
        sjt_call179.framebuffer.size.w = 0;
        sjt_call179.framebuffer.size.h = 0;
        sjf_size(&sjt_call179.framebuffer.size);
        sjt_call179.framebuffer.id = (uint32_t)0u;
        sjf_framebuffer(&sjt_call179.framebuffer);
        sjt_call179.texture._refCount = 1;
        sjt_call179.texture.size._refCount = 1;
        sjt_call179.texture.size.w = 0;
        sjt_call179.texture.size.h = 0;
        sjf_size(&sjt_call179.texture.size);
        sjt_call179.texture.id = (uint32_t)0u;
        sjf_texture(&sjt_call179.texture);
        sjt_call179.renderbuffer._refCount = 1;
        sjt_call179.renderbuffer.size._refCount = 1;
        sjt_call179.renderbuffer.size.w = 0;
        sjt_call179.renderbuffer.size.h = 0;
        sjf_size(&sjt_call179.renderbuffer.size);
        sjt_call179.renderbuffer.id = (uint32_t)0u;
        sjf_renderbuffer(&sjt_call179.renderbuffer);
        sjf_scenebuffer(&sjt_call179);
        sjt_copy108 = &sjt_call179;
        if (sjt_dot1777->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&sjt_dot1777->_scenebuffer); }
;
        sjt_dot1777->_scenebuffer._refCount = 1;
        sjf_scenebuffer_copy(&sjt_dot1777->_scenebuffer, sjt_copy108);
    }

    sjt_dot1782 = _parent;
    sjt_isEmpty42 = (sjt_dot1782->_scenebuffer._refCount != -1 ? &sjt_dot1782->_scenebuffer : 0);
    sjt_isEmpty41 = (sjt_isEmpty42 != 0);
    sjt_dot1783 = _parent;
    sjt_isEmpty44 = (sjt_dot1783->_vertexbuffer._refCount != -1 ? &sjt_dot1783->_vertexbuffer : 0);
    sjt_isEmpty43 = (sjt_isEmpty44 != 0);
    if (sjt_isEmpty41 && sjt_isEmpty43) {
        sjs_scenebuffer* ifValue29 = 0;
        sjs_boxvertexbuffer* ifValue30 = 0;
        sjs_string sjt_call180 = { -1 };
        sjs_string sjt_call181 = { -1 };
        sjs_string sjt_call182 = { -1 };
        sjs_string sjt_call183 = { -1 };
        sjs_string sjt_call184 = { -1 };
        cb_scene2d_void sjt_callback8;
        sjs_fadeeffect* sjt_dot1784 = 0;
        sjs_fadeeffect* sjt_dot1785 = 0;
        sjs_scenebuffer* sjt_dot1786 = 0;
        sjs_fadeeffect* sjt_dot1787 = 0;
        sjs_scenebuffer* sjt_dot1788 = 0;
        sjs_fadeeffect* sjt_dot1789 = 0;
        sjs_fadeeffect* sjt_dot1790 = 0;
        sjs_fadeeffect* sjt_dot1791 = 0;
        sjs_scenebuffer* sjt_dot1792 = 0;
        sjs_scenebuffer* sjt_dot1793 = 0;
        sjs_fadeeffect* sjt_dot1794 = 0;
        sjs_scene2d* sjt_dot1795 = 0;
        sjs_scene2d* sjt_dot1796 = 0;
        sjs_scene2d* sjt_dot1797 = 0;
        sjs_framebuffer* sjt_functionParam571 = 0;
        sjs_size* sjt_functionParam572 = 0;
        sjs_scene2d* sjt_functionParam573 = 0;
        sjs_framebuffer* sjt_functionParam574 = 0;
        int32_t sjt_functionParam575;
        sjs_texture* sjt_functionParam576 = 0;
        sjs_shader* sjt_functionParam577 = 0;
        int32_t sjt_functionParam578;
        int32_t sjt_functionParam579;
        int32_t sjt_functionParam580;
        sjs_shader* sjt_functionParam581 = 0;
        sjs_string* sjt_functionParam582 = 0;
        int32_t sjt_functionParam583;
        int32_t sjt_functionParam584;
        sjs_shader* sjt_functionParam585 = 0;
        sjs_string* sjt_functionParam586 = 0;
        float sjt_functionParam587;
        int32_t sjt_functionParam588;
        sjs_shader* sjt_functionParam589 = 0;
        sjs_string* sjt_functionParam590 = 0;
        sjs_mat4* sjt_functionParam591 = 0;
        int32_t sjt_functionParam592;
        sjs_shader* sjt_functionParam593 = 0;
        sjs_string* sjt_functionParam594 = 0;
        sjs_mat4* sjt_functionParam595 = 0;
        int32_t sjt_functionParam596;
        sjs_shader* sjt_functionParam597 = 0;
        sjs_string* sjt_functionParam598 = 0;
        sjs_mat4* sjt_functionParam599 = 0;
        sjs_scene2d* sjt_functionParam600 = 0;
        sjs_scene2d* sjt_parent290 = 0;
        sjs_scene2d* sjt_parent291 = 0;
        sjs_scene2d* sjt_parent292 = 0;
        sjs_boxvertexbuffer* sjt_parent293 = 0;

        sjt_dot1784 = _parent;
        ifValue29 = (sjt_dot1784->_scenebuffer._refCount != -1 ? &sjt_dot1784->_scenebuffer : 0);
        sjt_dot1785 = _parent;
        ifValue30 = (sjt_dot1785->_vertexbuffer._refCount != -1 ? &sjt_dot1785->_vertexbuffer : 0);
        sjt_dot1786 = ifValue29;
        sjt_functionParam571 = &sjt_dot1786->framebuffer;
        sjf_glpushframebuffer(sjt_functionParam571);
        sjt_dot1787 = _parent;
        sjt_parent290 = &sjt_dot1787->_innerscene;
        sjt_dot1788 = ifValue29;
        sjt_functionParam572 = &sjt_dot1788->size;
        sjf_scene2d_setsize(sjt_parent290, sjt_functionParam572);
        sjt_dot1789 = _parent;
        sjt_parent291 = &sjt_dot1789->_innerscene;
        sjf_scene2d_start(sjt_parent291);
        sjt_callback8 = cb;
        sjt_dot1790 = _parent;
        sjt_functionParam573 = &sjt_dot1790->_innerscene;
        sjt_callback8._cb(sjt_callback8._parent, sjt_functionParam573);
        sjt_dot1791 = _parent;
        sjt_parent292 = &sjt_dot1791->_innerscene;
        sjf_scene2d_end(sjt_parent292);
        sjt_dot1792 = ifValue29;
        sjt_functionParam574 = &sjt_dot1792->framebuffer;
        sjf_glpopframebuffer(sjt_functionParam574);
        sjt_functionParam575 = sjv_gltexture_gl_texture_2d;
        sjt_dot1793 = ifValue29;
        sjt_functionParam576 = &sjt_dot1793->texture;
        sjf_glbindtexture(sjt_functionParam575, sjt_functionParam576);
        sjt_functionParam577 = &sjv_fadeshader;
        sjf_gluseprogram(sjt_functionParam577);
        sjt_functionParam578 = sjv_glblendfunctype_gl_src_alpha;
        sjt_functionParam579 = sjv_glblendfunctype_gl_one_minus_src_alpha;
        sjf_glblendfunc(sjt_functionParam578, sjt_functionParam579);
        sjt_functionParam581 = &sjv_fadeshader;
        sjt_call180._refCount = 1;
        sjt_call180.count = 7;
        sjt_call180.data._refCount = 1;
        sjt_call180.data.datasize = 8;
        sjt_call180.data.data = (void*)sjg_string28;
        sjt_call180.data._isglobal = true;
        sjt_call180.data.count = 8;
        sjf_array_char(&sjt_call180.data);
        sjf_string(&sjt_call180);
        sjt_functionParam582 = &sjt_call180;
        sjf_glgetuniformlocation(sjt_functionParam581, sjt_functionParam582, &sjt_functionParam580);
        sjt_functionParam583 = 0;
        sjf_gluniformi32(sjt_functionParam580, sjt_functionParam583);
        sjt_functionParam585 = &sjv_fadeshader;
        sjt_call181._refCount = 1;
        sjt_call181.count = 5;
        sjt_call181.data._refCount = 1;
        sjt_call181.data.datasize = 6;
        sjt_call181.data.data = (void*)sjg_string36;
        sjt_call181.data._isglobal = true;
        sjt_call181.data.count = 6;
        sjf_array_char(&sjt_call181.data);
        sjf_string(&sjt_call181);
        sjt_functionParam586 = &sjt_call181;
        sjf_glgetuniformlocation(sjt_functionParam585, sjt_functionParam586, &sjt_functionParam584);
        sjt_dot1794 = _parent;
        sjt_functionParam587 = sjt_dot1794->alpha;
        sjf_gluniformf32(sjt_functionParam584, sjt_functionParam587);
        sjt_functionParam589 = &sjv_fadeshader;
        sjt_call182._refCount = 1;
        sjt_call182.count = 5;
        sjt_call182.data._refCount = 1;
        sjt_call182.data.datasize = 6;
        sjt_call182.data.data = (void*)sjg_string29;
        sjt_call182.data._isglobal = true;
        sjt_call182.data.count = 6;
        sjf_array_char(&sjt_call182.data);
        sjf_string(&sjt_call182);
        sjt_functionParam590 = &sjt_call182;
        sjf_glgetuniformlocation(sjt_functionParam589, sjt_functionParam590, &sjt_functionParam588);
        sjt_dot1795 = scene;
        sjt_functionParam591 = &sjt_dot1795->model;
        sjf_gluniformmat4(sjt_functionParam588, sjt_functionParam591);
        sjt_functionParam593 = &sjv_fadeshader;
        sjt_call183._refCount = 1;
        sjt_call183.count = 4;
        sjt_call183.data._refCount = 1;
        sjt_call183.data.datasize = 5;
        sjt_call183.data.data = (void*)sjg_string30;
        sjt_call183.data._isglobal = true;
        sjt_call183.data.count = 5;
        sjf_array_char(&sjt_call183.data);
        sjf_string(&sjt_call183);
        sjt_functionParam594 = &sjt_call183;
        sjf_glgetuniformlocation(sjt_functionParam593, sjt_functionParam594, &sjt_functionParam592);
        sjt_dot1796 = scene;
        sjt_functionParam595 = &sjt_dot1796->view;
        sjf_gluniformmat4(sjt_functionParam592, sjt_functionParam595);
        sjt_functionParam597 = &sjv_fadeshader;
        sjt_call184._refCount = 1;
        sjt_call184.count = 10;
        sjt_call184.data._refCount = 1;
        sjt_call184.data.datasize = 11;
        sjt_call184.data.data = (void*)sjg_string19;
        sjt_call184.data._isglobal = true;
        sjt_call184.data.count = 11;
        sjf_array_char(&sjt_call184.data);
        sjf_string(&sjt_call184);
        sjt_functionParam598 = &sjt_call184;
        sjf_glgetuniformlocation(sjt_functionParam597, sjt_functionParam598, &sjt_functionParam596);
        sjt_dot1797 = scene;
        sjt_functionParam599 = &sjt_dot1797->projection;
        sjf_gluniformmat4(sjt_functionParam596, sjt_functionParam599);
        sjt_parent293 = ifValue30;
        sjt_functionParam600 = scene;
        sjf_boxvertexbuffer_render(sjt_parent293, sjt_functionParam600);

        if (sjt_call180._refCount == 1) { sjf_string_destroy(&sjt_call180); }
;
        if (sjt_call181._refCount == 1) { sjf_string_destroy(&sjt_call181); }
;
        if (sjt_call182._refCount == 1) { sjf_string_destroy(&sjt_call182); }
;
        if (sjt_call183._refCount == 1) { sjf_string_destroy(&sjt_call183); }
;
        if (sjt_call184._refCount == 1) { sjf_string_destroy(&sjt_call184); }
;
    }

    if (sjt_call178._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_call178); }
;
    if (sjt_call179._refCount == 1) { sjf_scenebuffer_destroy(&sjt_call179); }
;
}

void sjf_fadeeffect_setrect(sjs_fadeeffect* _parent, sjs_rect* rect_, cb_rect_void cb) {
    bool result20;
    sjs_rect sjt_call177 = { -1 };
    cb_rect_void sjt_callback7;
    sjs_fadeeffect* sjt_dot1758 = 0;
    sjs_rect* sjt_dot1769 = 0;
    sjs_fadeeffect* sjt_dot1770 = 0;
    sjs_rect* sjt_dot1771 = 0;
    sjs_fadeeffect* sjt_dot1772 = 0;
    sjs_rect* sjt_functionParam568 = 0;
    sjs_rect* sjt_functionParam570 = 0;
    bool sjt_ifElse66;
    bool sjt_not13;
    sjs_rect* sjt_parent288 = 0;

    sjt_dot1758 = _parent;
    sjt_parent288 = &sjt_dot1758->_rect;
    sjt_functionParam568 = rect_;
    sjf_rect_isequal(sjt_parent288, sjt_functionParam568, &sjt_not13);
    result20 = !sjt_not13;
    sjt_ifElse66 = result20;
    if (sjt_ifElse66) {
        sjs_rect* sjt_copy105 = 0;
        sjs_fadeeffect* sjt_dot1759 = 0;
        sjs_fadeeffect* sjt_dot1760 = 0;
        sjs_fadeeffect* sjt_dot1768 = 0;
        bool sjt_isEmpty37;
        sjs_scenebuffer* sjt_isEmpty38 = 0;

        sjt_dot1759 = _parent;
        sjt_copy105 = rect_;
        if (sjt_dot1759->_rect._refCount == 1) { sjf_rect_destroy(&sjt_dot1759->_rect); }
;
        sjt_dot1759->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1759->_rect, sjt_copy105);
        sjt_dot1760 = _parent;
        sjt_isEmpty38 = (sjt_dot1760->_scenebuffer._refCount != -1 ? &sjt_dot1760->_scenebuffer : 0);
        sjt_isEmpty37 = (sjt_isEmpty38 != 0);
        if (sjt_isEmpty37) {
            sjs_scenebuffer* ifValue27 = 0;
            bool result21;
            sjs_size sjt_call176 = { -1 };
            sjs_fadeeffect* sjt_dot1761 = 0;
            sjs_scenebuffer* sjt_dot1762 = 0;
            sjs_rect* sjt_dot1763 = 0;
            sjs_fadeeffect* sjt_dot1764 = 0;
            sjs_rect* sjt_dot1765 = 0;
            sjs_fadeeffect* sjt_dot1766 = 0;
            sjs_size* sjt_functionParam569 = 0;
            bool sjt_ifElse67;
            bool sjt_not14;
            sjs_size* sjt_parent289 = 0;

            sjt_dot1761 = _parent;
            ifValue27 = (sjt_dot1761->_scenebuffer._refCount != -1 ? &sjt_dot1761->_scenebuffer : 0);
            sjt_dot1762 = ifValue27;
            sjt_parent289 = &sjt_dot1762->size;
            sjt_call176._refCount = 1;
            sjt_dot1764 = _parent;
            sjt_dot1763 = &sjt_dot1764->_rect;
            sjt_call176.w = sjt_dot1763->w;
            sjt_dot1766 = _parent;
            sjt_dot1765 = &sjt_dot1766->_rect;
            sjt_call176.h = sjt_dot1765->h;
            sjf_size(&sjt_call176);
            sjt_functionParam569 = &sjt_call176;
            sjf_size_isequal(sjt_parent289, sjt_functionParam569, &sjt_not14);
            result21 = !sjt_not14;
            sjt_ifElse67 = result21;
            if (sjt_ifElse67) {
                sjs_fadeeffect* sjt_dot1767 = 0;

                sjt_dot1767 = _parent;
                if (sjt_dot1767->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&sjt_dot1767->_scenebuffer); }
;
                sjt_dot1767->_scenebuffer._refCount = -1;
            }

            if (sjt_call176._refCount == 1) { sjf_size_destroy(&sjt_call176); }
;
        }

        sjt_dot1768 = _parent;
        if (sjt_dot1768->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_dot1768->_vertexbuffer); }
;
        sjt_dot1768->_vertexbuffer._refCount = -1;
    }

    sjt_callback7 = cb;
    sjt_call177._refCount = 1;
    sjt_call177.x = 0;
    sjt_call177.y = 0;
    sjt_dot1770 = _parent;
    sjt_dot1769 = &sjt_dot1770->_rect;
    sjt_call177.w = sjt_dot1769->w;
    sjt_dot1772 = _parent;
    sjt_dot1771 = &sjt_dot1772->_rect;
    sjt_call177.h = sjt_dot1771->h;
    sjf_rect(&sjt_call177);
    sjt_functionParam570 = &sjt_call177;
    sjt_callback7._cb(sjt_callback7._parent, sjt_functionParam570);

    if (sjt_call177._refCount == 1) { sjf_rect_destroy(&sjt_call177); }
;
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
    sjs_filllayout* sjt_dot150 = 0;
    sjs_array_heap_iface_element* sjt_functionParam54 = 0;
    sjs_mouseevent* sjt_parent46 = 0;

    sjt_parent46 = mouseevent;
    sjt_dot150 = _parent;
    sjt_functionParam54 = &sjt_dot150->children;
    sjf_mouseevent_firechildren(sjt_parent46, sjt_functionParam54, _return);
}

void sjf_filllayout_getrect(sjs_filllayout* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy6 = 0;
    sjs_filllayout* sjt_dot135 = 0;

    sjt_dot135 = _parent;
    sjt_copy6 = &sjt_dot135->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy6);
}

void sjf_filllayout_getrect_heap(sjs_filllayout* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy7 = 0;
    sjs_filllayout* sjt_dot136 = 0;

    sjt_dot136 = _parent;
    sjt_copy7 = &sjt_dot136->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy7);
}

void sjf_filllayout_getsize(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t i;
    sjs_filllayout* sjt_dot129 = 0;
    sjs_filllayout* sjt_dot97 = 0;
    sjs_array_heap_iface_element* sjt_dot98 = 0;
    sjs_filllayout* sjt_dot99 = 0;
    int32_t sjt_forEnd8;
    int32_t sjt_forStart8;
    sjs_margin* sjt_functionParam41 = 0;
    sjs_margin* sjt_functionParam44 = 0;
    sjs_size* sjt_parent29 = 0;
    sjs_size* sjt_parent33 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
    sjv_size.w = 0;
    sjv_size.h = 0;
    sjf_size(&sjv_size);
    sjt_parent29 = maxsize;
    sjt_dot97 = _parent;
    sjt_functionParam41 = &sjt_dot97->margin;
    sjf_size_subtractmargin(sjt_parent29, sjt_functionParam41, &sjv_innersize);
    sjt_forStart8 = 0;
    sjt_dot99 = _parent;
    sjt_dot98 = &sjt_dot99->children;
    sjt_forEnd8 = sjt_dot98->count;
    i = sjt_forStart8;
    while (i < sjt_forEnd8) {
        sjs_size sjt_call6 = { -1 };
        sjs_size sjt_call7 = { -1 };
        sjs_size* sjt_copy4 = 0;
        sjs_filllayout* sjt_dot100 = 0;
        int32_t sjt_functionParam42;
        sjs_size* sjt_functionParam43 = 0;
        sjs_size* sjt_interfaceParam4 = 0;
        sjs_array_heap_iface_element* sjt_parent30 = 0;
        sjs_size* sjt_parent31 = 0;
        sji_element sjt_parent32 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot100 = _parent;
        sjt_parent30 = &sjt_dot100->children;
        sjt_functionParam42 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent30, sjt_functionParam42, &sjv_child);
        sjt_parent31 = &sjv_size;
        sjt_parent32 = sjv_child;
        sjt_interfaceParam4 = &sjv_innersize;
        sjt_call7._refCount = 1;
        sjt_parent32._vtbl->getsize(sjt_parent32._parent, sjt_interfaceParam4, &sjt_call7);
        sjt_functionParam43 = &sjt_call7;
        sjf_size_max(sjt_parent31, sjt_functionParam43, &sjt_call6);
        sjt_copy4 = &sjt_call6;
        if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
        sjv_size._refCount = 1;
        sjf_size_copy(&sjv_size, sjt_copy4);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call6._refCount == 1) { sjf_size_destroy(&sjt_call6); }
;
        if (sjt_call7._refCount == 1) { sjf_size_destroy(&sjt_call7); }
;
    }

    sjt_parent33 = &sjv_size;
    sjt_dot129 = _parent;
    sjt_functionParam44 = &sjt_dot129->margin;
    sjf_size_addmargin(sjt_parent33, sjt_functionParam44, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_filllayout_getsize_heap(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t i;
    sjs_filllayout* sjt_dot130 = 0;
    sjs_array_heap_iface_element* sjt_dot131 = 0;
    sjs_filllayout* sjt_dot132 = 0;
    sjs_filllayout* sjt_dot134 = 0;
    int32_t sjt_forEnd9;
    int32_t sjt_forStart9;
    sjs_margin* sjt_functionParam45 = 0;
    sjs_margin* sjt_functionParam48 = 0;
    sjs_size* sjt_parent34 = 0;
    sjs_size* sjt_parent38 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
    sjv_size.w = 0;
    sjv_size.h = 0;
    sjf_size(&sjv_size);
    sjt_parent34 = maxsize;
    sjt_dot130 = _parent;
    sjt_functionParam45 = &sjt_dot130->margin;
    sjf_size_subtractmargin(sjt_parent34, sjt_functionParam45, &sjv_innersize);
    sjt_forStart9 = 0;
    sjt_dot132 = _parent;
    sjt_dot131 = &sjt_dot132->children;
    sjt_forEnd9 = sjt_dot131->count;
    i = sjt_forStart9;
    while (i < sjt_forEnd9) {
        sjs_size sjt_call8 = { -1 };
        sjs_size sjt_call9 = { -1 };
        sjs_size* sjt_copy5 = 0;
        sjs_filllayout* sjt_dot133 = 0;
        int32_t sjt_functionParam46;
        sjs_size* sjt_functionParam47 = 0;
        sjs_size* sjt_interfaceParam5 = 0;
        sjs_array_heap_iface_element* sjt_parent35 = 0;
        sjs_size* sjt_parent36 = 0;
        sji_element sjt_parent37 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot133 = _parent;
        sjt_parent35 = &sjt_dot133->children;
        sjt_functionParam46 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent35, sjt_functionParam46, &sjv_child);
        sjt_parent36 = &sjv_size;
        sjt_parent37 = sjv_child;
        sjt_interfaceParam5 = &sjv_innersize;
        sjt_call9._refCount = 1;
        sjt_parent37._vtbl->getsize(sjt_parent37._parent, sjt_interfaceParam5, &sjt_call9);
        sjt_functionParam47 = &sjt_call9;
        sjf_size_max(sjt_parent36, sjt_functionParam47, &sjt_call8);
        sjt_copy5 = &sjt_call8;
        if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
        sjv_size._refCount = 1;
        sjf_size_copy(&sjv_size, sjt_copy5);
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
        if (sjt_call9._refCount == 1) { sjf_size_destroy(&sjt_call9); }
;
    }

    sjt_parent38 = &sjv_size;
    sjt_dot134 = _parent;
    sjt_functionParam48 = &sjt_dot134->margin;
    sjf_size_addmargin_heap(sjt_parent38, sjt_functionParam48, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_filllayout_heap(sjs_filllayout* _this) {
}

void sjf_filllayout_render(sjs_filllayout* _parent, sjs_scene2d* scene) {
    sjs_filllayout* sjt_dot145 = 0;
    bool sjt_isEmpty5;
    sji_effect sjt_isEmpty6 = { 0 };

    sjt_dot145 = _parent;
    sjt_isEmpty6 = sjt_dot145->effect;
    sjt_isEmpty5 = (sjt_isEmpty6._parent != 0);
    if (sjt_isEmpty5) {
        sji_effect ifValue5 = { 0 };
        sjs_filllayout* sjt_dot146 = 0;
        cb_scene2d_void sjt_interfaceParam10;
        sjs_scene2d* sjt_interfaceParam9 = 0;
        sji_effect sjt_parent43 = { 0 };

        sjt_dot146 = _parent;
        ifValue5 = sjt_dot146->effect;
        if (ifValue5._parent != 0) {
            ifValue5._parent->_refCount++;
        }

        sjt_parent43 = ifValue5;
        sjt_interfaceParam9 = scene;
        sjt_interfaceParam10._parent = (sjs_object*)_parent;
        sjt_interfaceParam10._cb = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_renderinner;
        sjt_parent43._vtbl->render(sjt_parent43._parent, sjt_interfaceParam9, sjt_interfaceParam10);

        if (ifValue5._parent != 0) {
            ifValue5._parent->_refCount--;
            if (ifValue5._parent->_refCount <= 0) {
                ifValue5._vtbl->destroy(ifValue5._parent);
                free(ifValue5._parent);
            }
        }
    } else {
        sjs_scene2d* sjt_functionParam53 = 0;

        sjt_functionParam53 = scene;
        sjf_filllayout_renderinner(_parent, sjt_functionParam53);
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
    sjt_dot147 = &sjt_dot148->children;
    sjt_forEnd11 = sjt_dot147->count;
    i = sjt_forStart11;
    while (i < sjt_forEnd11) {
        sjs_filllayout* sjt_dot149 = 0;
        int32_t sjt_functionParam52;
        sjs_scene2d* sjt_interfaceParam11 = 0;
        sjs_array_heap_iface_element* sjt_parent44 = 0;
        sji_element sjt_parent45 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot149 = _parent;
        sjt_parent44 = &sjt_dot149->children;
        sjt_functionParam52 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent44, sjt_functionParam52, &sjv_child);
        sjt_parent45 = sjv_child;
        sjt_interfaceParam11 = scene;
        sjt_parent45._vtbl->render(sjt_parent45._parent, sjt_interfaceParam11);
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
    sjs_rect* sjt_copy8 = 0;
    sjs_filllayout* sjt_dot137 = 0;
    sjs_filllayout* sjt_dot138 = 0;
    sjs_filllayout* sjt_dot139 = 0;
    sjs_filllayout* sjt_dot140 = 0;
    sjs_margin* sjt_functionParam49 = 0;
    bool sjt_isEmpty3;
    sji_effect sjt_isEmpty4 = { 0 };
    sjs_rect* sjt_parent39 = 0;
    sjs_rect sjv_innerrect = { -1 };

    sjt_dot137 = _parent;
    sjt_copy8 = rect_;
    if (sjt_dot137->_rect._refCount == 1) { sjf_rect_destroy(&sjt_dot137->_rect); }
;
    sjt_dot137->_rect._refCount = 1;
    sjf_rect_copy(&sjt_dot137->_rect, sjt_copy8);
    sjt_dot138 = _parent;
    sjt_parent39 = &sjt_dot138->_rect;
    sjt_dot139 = _parent;
    sjt_functionParam49 = &sjt_dot139->margin;
    sjf_rect_subtractmargin(sjt_parent39, sjt_functionParam49, &sjv_innerrect);
    sjt_dot140 = _parent;
    sjt_isEmpty4 = sjt_dot140->effect;
    sjt_isEmpty3 = (sjt_isEmpty4._parent != 0);
    if (sjt_isEmpty3) {
        sji_effect ifValue3 = { 0 };
        sjs_filllayout* sjt_dot141 = 0;
        sjs_rect* sjt_interfaceParam6 = 0;
        cb_rect_void sjt_interfaceParam7;
        sji_effect sjt_parent40 = { 0 };

        sjt_dot141 = _parent;
        ifValue3 = sjt_dot141->effect;
        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount++;
        }

        sjt_parent40 = ifValue3;
        sjt_interfaceParam6 = &sjv_innerrect;
        sjt_interfaceParam7._parent = (sjs_object*)_parent;
        sjt_interfaceParam7._cb = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrectinner;
        sjt_parent40._vtbl->setrect(sjt_parent40._parent, sjt_interfaceParam6, sjt_interfaceParam7);

        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount--;
            if (ifValue3._parent->_refCount <= 0) {
                ifValue3._vtbl->destroy(ifValue3._parent);
                free(ifValue3._parent);
            }
        }
    } else {
        sjs_rect* sjt_functionParam51 = 0;

        sjt_functionParam51 = &sjv_innerrect;
        sjf_filllayout_setrectinner(_parent, sjt_functionParam51);
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
;
}

void sjf_filllayout_setrectinner(sjs_filllayout* _parent, sjs_rect* innerrect) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot142 = 0;
    sjs_filllayout* sjt_dot143 = 0;
    int32_t sjt_forEnd10;
    int32_t sjt_forStart10;

    sjt_forStart10 = 0;
    sjt_dot143 = _parent;
    sjt_dot142 = &sjt_dot143->children;
    sjt_forEnd10 = sjt_dot142->count;
    i = sjt_forStart10;
    while (i < sjt_forEnd10) {
        sjs_filllayout* sjt_dot144 = 0;
        int32_t sjt_functionParam50;
        sjs_rect* sjt_interfaceParam8 = 0;
        sjs_array_heap_iface_element* sjt_parent41 = 0;
        sji_element sjt_parent42 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot144 = _parent;
        sjt_parent41 = &sjt_dot144->children;
        sjt_functionParam50 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent41, sjt_functionParam50, &sjv_child);
        sjt_parent42 = sjv_child;
        sjt_interfaceParam8 = innerrect;
        sjt_parent42._vtbl->setrect(sjt_parent42._parent, sjt_interfaceParam8);
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
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, (int)_this->atlas->width, (int)_this->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->atlas->data );
}

void sjf_font_load_heap(sjs_string* src, float size, sjs_font** _return) {
    sjs_string* sjt_copy74 = 0;
    sjs_fontkey* sjt_functionParam387 = 0;
    bool sjt_isEmpty19;
    sjs_font* sjt_isEmpty20 = 0;
    sjs_hash_fontkey_weak_font* sjt_parent258 = 0;
    sjs_font* sjv_h = 0;
    sjs_fontkey sjv_k = { -1 };
    sjs_font* sjv_w = 0;

    sjv_k._refCount = 1;
    sjt_copy74 = src;
    sjv_k.src._refCount = 1;
    sjf_string_copy(&sjv_k.src, sjt_copy74);
    sjv_k.size = size;
    sjf_fontkey(&sjv_k);
    sjt_parent258 = &sjv_fonthash;
    sjt_functionParam387 = &sjv_k;
    sjf_hash_fontkey_weak_font_getat(sjt_parent258, sjt_functionParam387, &sjv_w);
    sjv_h = sjv_w;
    if (sjv_h != 0) {
        sjv_h->_refCount++;
    }

    sjt_isEmpty20 = sjv_h;
    sjt_isEmpty19 = (sjt_isEmpty20 != 0);
    if (sjt_isEmpty19) {
        sjs_font* ifValue11 = 0;

        ifValue11 = sjv_h;
        if (ifValue11 != 0) {
            ifValue11->_refCount++;
        }

        (*_return) = ifValue11;
        (*_return)->_refCount++;

        ifValue11->_refCount--;
        if (ifValue11->_refCount <= 0) {
            weakptr_release(ifValue11);
            sjf_font_destroy(ifValue11);
            free(ifValue11);
        }
    } else {
        sjs_string* sjt_copy75 = 0;
        sjs_fontkey* sjt_functionParam388 = 0;
        sjs_font* sjt_functionParam389 = 0;
        sjs_hash_fontkey_weak_font* sjt_parent259 = 0;
        sjs_font* sjv_result = 0;

        sjv_result = (sjs_font*)malloc(sizeof(sjs_font));
        sjv_result->_refCount = 1;
        sjt_copy75 = src;
        sjv_result->src._refCount = 1;
        sjf_string_copy(&sjv_result->src, sjt_copy75);
        sjv_result->size = size;
        sjf_font_heap(sjv_result);
        sjt_parent259 = &sjv_fonthash;
        sjt_functionParam388 = &sjv_k;
        sjt_functionParam389 = sjv_result;
        delete_cb weakptrcb26 = { &sjt_functionParam389, weakptr_clear };
        if (sjt_functionParam389 != 0) { weakptr_cb_add(sjt_functionParam389, weakptrcb26); }
        sjf_hash_fontkey_weak_font_setat(sjt_parent259, sjt_functionParam388, sjt_functionParam389);
        (*_return) = sjv_result;
        (*_return)->_refCount++;

        delete_cb weakptrcb27 = { &sjt_functionParam389, weakptr_clear };
        if (sjt_functionParam389 != 0) { weakptr_cb_remove(sjt_functionParam389, weakptrcb27); }
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
    delete_cb weakptrcb28 = { &sjv_w, weakptr_clear };
    if (sjv_w != 0) { weakptr_cb_remove(sjv_w, weakptrcb28); }
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
    sjs_fontkey* sjt_dot3 = 0;
    sjs_fontkey* sjt_dot4 = 0;
    float sjt_functionParam10;
    uint32_t sjt_math3;
    uint32_t sjt_math4;
    sjs_string* sjt_parent2 = 0;

    sjt_dot3 = _parent;
    sjt_parent2 = &sjt_dot3->src;
    sjf_string_hash(sjt_parent2, &sjt_math3);
    sjt_dot4 = _parent;
    sjt_functionParam10 = sjt_dot4->size;
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
    sjt_parent3 = &sjt_dot5->src;
    sjt_dot6 = x;
    sjt_functionParam11 = &sjt_dot6->src;
    sjf_string_isequal(sjt_parent3, sjt_functionParam11, &sjt_and1);
    sjt_dot7 = _parent;
    sjt_compare1 = sjt_dot7->size;
    sjt_dot8 = x;
    sjt_compare2 = sjt_dot8->size;
    sjt_and2 = sjt_compare1 == sjt_compare2;
    (*_return) = sjt_and1 && sjt_and2;
}

void sjf_framebuffer(sjs_framebuffer* _this) {
}

void sjf_framebuffer_copy(sjs_framebuffer* _this, sjs_framebuffer* _from) {
    _this->size._refCount = 1;
    sjf_size_copy(&_this->size, &_from->size);
    _this->id = _from->id;
    _this->id = _from->id;
    glid_retain(_this->id);
}

void sjf_framebuffer_destroy(sjs_framebuffer* _this) {
    if (glid_release(_this->id)) {
        glDeleteFramebuffers(1, &_this->id);
    }
    if (_this->size._refCount == 1) { sjf_size_destroy(&_this->size); }
;
}

void sjf_framebuffer_heap(sjs_framebuffer* _this) {
}

void sjf_glbindrenderbuffer(sjs_renderbuffer* renderbuffer) {
    glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer->id);
}

void sjf_glbindtexture(int32_t type, sjs_texture* texture) {
    glBindTexture(type, texture->id);
}

void sjf_glblendfunc(int32_t sfactor, int32_t dfactor) {
    glBlendFunc(sfactor, dfactor);
}

void sjf_glcheckframebufferstatus(int32_t* _return) {
    int32_t sjv_status;

    sjv_status = sjv_glframebufferstatus_gl_framebuffer_unsupported;
    sjv_status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    (*_return) = sjv_status;
}

void sjf_glclearcolor(sjs_color* color) {
    glClearColor(color->r, color->g, color->b, color->a);
}

void sjf_gldisable(int32_t feature) {
    glDisable(feature);
}

void sjf_glenable(int32_t feature) {
    glEnable(feature);
}

void sjf_glframebufferrenderbuffer(int32_t attachment, sjs_renderbuffer* renderbuffer) {
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, renderbuffer->id);
}

void sjf_glframebuffertexture2d(int32_t attachment, int32_t target, sjs_texture* texture, int32_t level) {
    glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, target, texture->id, level);
}

void sjf_glgenframebuffer(sjs_size* size, sjs_framebuffer* _return) {
    sjs_size* sjt_copy78 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenFramebuffers(1, &sjv_id);
    _return->_refCount = 1;
    sjt_copy78 = size;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, sjt_copy78);
    _return->id = sjv_id;
    sjf_framebuffer(_return);
}

void sjf_glgenframebuffer_heap(sjs_size* size, sjs_framebuffer** _return) {
    sjs_size* sjt_copy79 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenFramebuffers(1, &sjv_id);
    (*_return) = (sjs_framebuffer*)malloc(sizeof(sjs_framebuffer));
    (*_return)->_refCount = 1;
    sjt_copy79 = size;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, sjt_copy79);
    (*_return)->id = sjv_id;
    sjf_framebuffer_heap((*_return));
}

void sjf_glgenrenderbuffer(sjs_size* size, sjs_renderbuffer* _return) {
    sjs_size* sjt_copy84 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenRenderbuffers(1, &sjv_id); 
    _return->_refCount = 1;
    sjt_copy84 = size;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, sjt_copy84);
    _return->id = sjv_id;
    sjf_renderbuffer(_return);
}

void sjf_glgenrenderbuffer_heap(sjs_size* size, sjs_renderbuffer** _return) {
    sjs_size* sjt_copy85 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenRenderbuffers(1, &sjv_id); 
    (*_return) = (sjs_renderbuffer*)malloc(sizeof(sjs_renderbuffer));
    (*_return)->_refCount = 1;
    sjt_copy85 = size;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, sjt_copy85);
    (*_return)->id = sjv_id;
    sjf_renderbuffer_heap((*_return));
}

void sjf_glgentexture(sjs_size* size, sjs_texture* _return) {
    sjs_size* sjt_copy81 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenTextures(1, &sjv_id);
    _return->_refCount = 1;
    sjt_copy81 = size;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, sjt_copy81);
    _return->id = sjv_id;
    sjf_texture(_return);
}

void sjf_glgentexture_heap(sjs_size* size, sjs_texture** _return) {
    sjs_size* sjt_copy82 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenTextures(1, &sjv_id);
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
    (*_return)->_refCount = 1;
    sjt_copy82 = size;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, sjt_copy82);
    (*_return)->id = sjv_id;
    sjf_texture_heap((*_return));
}

void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return) {
    int result = glGetUniformLocation(shader->id, (char*)name->data.data);
    (*_return) = result;
return;;
}

void sjf_glpopframebuffer(sjs_framebuffer* framebuffer) {
    sjs_string sjt_call146 = { -1 };
    uint32_t sjt_compare111;
    uint32_t sjt_compare112;
    int32_t sjt_compare113;
    int32_t sjt_compare114;
    sjs_framebuffer* sjt_dot1644 = 0;
    int32_t sjt_functionParam437;
    int32_t sjt_functionParam439;
    bool sjt_ifElse53;
    bool sjt_ifElse54;
    int32_t sjt_math2331;
    int32_t sjt_math2332;
    int32_t sjt_math2333;
    int32_t sjt_math2334;
    sjs_list_u32* sjt_parent267 = 0;
    sjs_list_u32* sjt_parent268 = 0;
    sjs_list_u32* sjt_parent269 = 0;
    sjs_list_u32* sjt_parent270 = 0;
    sjs_list_u32* sjt_parent271 = 0;
    uint32_t sjv_id;

    sjt_parent267 = &sjv_glframebuffers;
    sjt_parent268 = &sjv_glframebuffers;
    sjf_list_u32_getcount(sjt_parent268, &sjt_math2331);
    sjt_math2332 = 1;
    sjt_functionParam437 = sjt_math2331 - sjt_math2332;
    sjf_list_u32_getat(sjt_parent267, sjt_functionParam437, &sjt_compare111);
    sjt_dot1644 = framebuffer;
    sjt_compare112 = sjt_dot1644->id;
    sjt_ifElse53 = sjt_compare111 != sjt_compare112;
    if (sjt_ifElse53) {
        sjs_string* sjt_functionParam438 = 0;

        sjt_call146._refCount = 1;
        sjt_call146.count = 33;
        sjt_call146.data._refCount = 1;
        sjt_call146.data.datasize = 34;
        sjt_call146.data.data = (void*)sjg_string33;
        sjt_call146.data._isglobal = true;
        sjt_call146.data.count = 34;
        sjf_array_char(&sjt_call146.data);
        sjf_string(&sjt_call146);
        sjt_functionParam438 = &sjt_call146;
        sjf_halt(sjt_functionParam438);
    }

    sjt_parent269 = &sjv_glframebuffers;
    sjt_parent270 = &sjv_glframebuffers;
    sjf_list_u32_getcount(sjt_parent270, &sjt_math2333);
    sjt_math2334 = 1;
    sjt_functionParam439 = sjt_math2333 - sjt_math2334;
    sjf_list_u32_removeat(sjt_parent269, sjt_functionParam439);
    sjt_parent271 = &sjv_glframebuffers;
    sjf_list_u32_getcount(sjt_parent271, &sjt_compare113);
    sjt_compare114 = 0;
    sjt_ifElse54 = sjt_compare113 > sjt_compare114;
    if (sjt_ifElse54) {
        int32_t sjt_functionParam440;
        int32_t sjt_math2335;
        int32_t sjt_math2336;
        sjs_list_u32* sjt_parent272 = 0;
        sjs_list_u32* sjt_parent273 = 0;

        sjt_parent272 = &sjv_glframebuffers;
        sjt_parent273 = &sjv_glframebuffers;
        sjf_list_u32_getcount(sjt_parent273, &sjt_math2335);
        sjt_math2336 = 1;
        sjt_functionParam440 = sjt_math2335 - sjt_math2336;
        sjf_list_u32_getat(sjt_parent272, sjt_functionParam440, &sjv_id);
    } else {
        sjv_id = (uint32_t)0u;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, sjv_id);

    if (sjt_call146._refCount == 1) { sjf_string_destroy(&sjt_call146); }
;
}

void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect) {
    bool result5;
    sjs_rect sjt_call19 = { -1 };
    sjs_string sjt_call20 = { -1 };
    int32_t sjt_compare79;
    int32_t sjt_compare80;
    sjs_rect* sjt_dot326 = 0;
    sjs_rect* sjt_dot327 = 0;
    sjs_rect* sjt_dot328 = 0;
    sjs_rect* sjt_dot329 = 0;
    sjs_rect* sjt_dot330 = 0;
    sjs_rect* sjt_dot331 = 0;
    int32_t sjt_functionParam129;
    sjs_rect* sjt_functionParam130 = 0;
    int32_t sjt_functionParam132;
    bool sjt_ifElse34;
    bool sjt_ifElse35;
    int32_t sjt_math289;
    int32_t sjt_math290;
    int32_t sjt_math291;
    int32_t sjt_math292;
    int32_t sjt_math293;
    int32_t sjt_math294;
    int32_t sjt_math295;
    int32_t sjt_math296;
    bool sjt_not3;
    sjs_rect* sjt_parent86 = 0;
    sjs_list_rect* sjt_parent88 = 0;
    sjs_list_rect* sjt_parent89 = 0;
    sjs_list_rect* sjt_parent90 = 0;
    sjs_list_rect* sjt_parent91 = 0;
    sjs_list_rect* sjt_parent92 = 0;
    sjs_rect sjv_newrect = { -1 };
    sjs_rect sjv_oldrect = { -1 };

    sjv_oldrect._refCount = 1;
    sjt_dot326 = rect;
    sjv_oldrect.x = sjt_dot326->x;
    sjt_dot327 = scenerect;
    sjt_math289 = sjt_dot327->h;
    sjt_dot328 = rect;
    sjt_math291 = sjt_dot328->y;
    sjt_dot329 = rect;
    sjt_math292 = sjt_dot329->h;
    sjt_math290 = sjt_math291 + sjt_math292;
    sjv_oldrect.y = sjt_math289 - sjt_math290;
    sjt_dot330 = rect;
    sjv_oldrect.w = sjt_dot330->w;
    sjt_dot331 = rect;
    sjv_oldrect.h = sjt_dot331->h;
    sjf_rect(&sjv_oldrect);
    sjt_parent88 = &sjv_glviewports;
    sjt_parent89 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent89, &sjt_math293);
    sjt_math294 = 1;
    sjt_functionParam129 = sjt_math293 - sjt_math294;
    sjf_list_rect_getat(sjt_parent88, sjt_functionParam129, &sjt_call19);
    sjt_parent86 = &sjt_call19;
    sjt_functionParam130 = &sjv_oldrect;
    sjf_rect_isequal(sjt_parent86, sjt_functionParam130, &sjt_not3);
    result5 = !sjt_not3;
    sjt_ifElse34 = result5;
    if (sjt_ifElse34) {
        sjs_string* sjt_functionParam131 = 0;

        sjt_call20._refCount = 1;
        sjt_call20.count = 30;
        sjt_call20.data._refCount = 1;
        sjt_call20.data.datasize = 31;
        sjt_call20.data.data = (void*)sjg_string16;
        sjt_call20.data._isglobal = true;
        sjt_call20.data.count = 31;
        sjf_array_char(&sjt_call20.data);
        sjf_string(&sjt_call20);
        sjt_functionParam131 = &sjt_call20;
        sjf_halt(sjt_functionParam131);
    }

    sjt_parent90 = &sjv_glviewports;
    sjt_parent91 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent91, &sjt_math295);
    sjt_math296 = 1;
    sjt_functionParam132 = sjt_math295 - sjt_math296;
    sjf_list_rect_removeat(sjt_parent90, sjt_functionParam132);
    sjt_parent92 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent92, &sjt_compare79);
    sjt_compare80 = 0;
    sjt_ifElse35 = sjt_compare79 > sjt_compare80;
    if (sjt_ifElse35) {
        int32_t sjt_functionParam133;
        int32_t sjt_math297;
        int32_t sjt_math298;
        sjs_list_rect* sjt_parent93 = 0;
        sjs_list_rect* sjt_parent94 = 0;

        sjt_parent93 = &sjv_glviewports;
        sjt_parent94 = &sjv_glviewports;
        sjf_list_rect_getcount(sjt_parent94, &sjt_math297);
        sjt_math298 = 1;
        sjt_functionParam133 = sjt_math297 - sjt_math298;
        sjf_list_rect_getat(sjt_parent93, sjt_functionParam133, &sjv_newrect);
    } else {
        sjv_newrect._refCount = 1;
        sjv_newrect.x = 0;
        sjv_newrect.y = 0;
        sjv_newrect.w = 0;
        sjv_newrect.h = 0;
        sjf_rect(&sjv_newrect);
    }

    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjt_call19._refCount == 1) { sjf_rect_destroy(&sjt_call19); }
;
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
;
    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
;
    if (sjv_oldrect._refCount == 1) { sjf_rect_destroy(&sjv_oldrect); }
;
}

void sjf_glpushframebuffer(sjs_framebuffer* framebuffer) {
    sjs_framebuffer* sjt_dot1640 = 0;
    uint32_t sjt_functionParam404;
    sjs_list_u32* sjt_parent265 = 0;

    sjt_parent265 = &sjv_glframebuffers;
    sjt_dot1640 = framebuffer;
    sjt_functionParam404 = sjt_dot1640->id;
    sjf_list_u32_add(sjt_parent265, sjt_functionParam404);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->id);
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect* sjt_dot294 = 0;
    sjs_rect* sjt_dot295 = 0;
    sjs_rect* sjt_dot296 = 0;
    sjs_rect* sjt_dot297 = 0;
    sjs_rect* sjt_dot298 = 0;
    sjs_rect* sjt_dot299 = 0;
    sjs_rect* sjt_functionParam96 = 0;
    int32_t sjt_math269;
    int32_t sjt_math270;
    int32_t sjt_math271;
    int32_t sjt_math272;
    sjs_list_rect* sjt_parent75 = 0;
    sjs_rect sjv_newrect = { -1 };

    sjv_newrect._refCount = 1;
    sjt_dot294 = rect;
    sjv_newrect.x = sjt_dot294->x;
    sjt_dot295 = scenerect;
    sjt_math269 = sjt_dot295->h;
    sjt_dot296 = rect;
    sjt_math271 = sjt_dot296->y;
    sjt_dot297 = rect;
    sjt_math272 = sjt_dot297->h;
    sjt_math270 = sjt_math271 + sjt_math272;
    sjv_newrect.y = sjt_math269 - sjt_math270;
    sjt_dot298 = rect;
    sjv_newrect.w = sjt_dot298->w;
    sjt_dot299 = rect;
    sjv_newrect.h = sjt_dot299->h;
    sjf_rect(&sjv_newrect);
    sjt_parent75 = &sjv_glviewports;
    sjt_functionParam96 = &sjv_newrect;
    sjf_list_rect_add(sjt_parent75, sjt_functionParam96);
    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
;
}

void sjf_glrenderbufferstorage(int32_t format, sjs_size* size) {
    glRenderbufferStorage(GL_RENDERBUFFER, format, size->w, size->h);
}

void sjf_glteximage2d(int32_t type, int32_t level, int32_t format, sjs_size* size, int32_t datatype, void* data) {
    glTexImage2D(type, level, format, size->w, size->h, 0, format, datatype, data);
}

void sjf_gltexparameteri(int32_t type, int32_t attribute, int32_t val) {
    glTexParameteri(type, attribute, val);
}

void sjf_gluniformf32(int32_t loc, float v) {
    glUniform1f(loc, v);
}

void sjf_gluniformi32(int32_t loc, int32_t v) {
    glUniform1i(loc, v);
}

void sjf_gluniformmat4(int32_t loc, sjs_mat4* m) {
    glUniformMatrix4fv(loc, 1, 0, (GLfloat*)&m->m00);
}

void sjf_gluniformvec3(int32_t loc, sjs_vec3* v) {
    glUniform3fv(loc, 1, (GLfloat*)&v->x);
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
    sjs_gridlayout* sjt_dot84 = 0;
    sjs_array_heap_iface_element* sjt_functionParam38 = 0;
    sjs_mouseevent* sjt_parent27 = 0;

    sjt_parent27 = mouseevent;
    sjt_dot84 = _parent;
    sjt_functionParam38 = &sjt_dot84->children;
    sjf_mouseevent_firechildren(sjt_parent27, sjt_functionParam38, _return);
}

void sjf_gridlayout_getrect(sjs_gridlayout* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy1 = 0;
    sjs_gridlayout* sjt_dot13 = 0;

    sjt_dot13 = _parent;
    sjt_copy1 = &sjt_dot13->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy1);
}

void sjf_gridlayout_getrect_heap(sjs_gridlayout* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy2 = 0;
    sjs_gridlayout* sjt_dot14 = 0;

    sjt_dot14 = _parent;
    sjt_copy2 = &sjt_dot14->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy2);
}

void sjf_gridlayout_getsize(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot10 = 0;
    sjs_size* sjt_dot9 = 0;

    _return->_refCount = 1;
    sjt_dot9 = maxsize;
    _return->w = sjt_dot9->w;
    sjt_dot10 = maxsize;
    _return->h = sjt_dot10->h;
    sjf_size(_return);
}

void sjf_gridlayout_getsize_heap(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot11 = 0;
    sjs_size* sjt_dot12 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot11 = maxsize;
    (*_return)->w = sjt_dot11->w;
    sjt_dot12 = maxsize;
    (*_return)->h = sjt_dot12->h;
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
    sjt_dot80 = &sjt_dot81->children;
    sjt_forEnd6 = sjt_dot80->count;
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        sjs_gridlayout* sjt_dot82 = 0;
        int32_t sjt_functionParam36;
        sjs_scene2d* sjt_interfaceParam2 = 0;
        sjs_array_heap_iface_element* sjt_parent23 = 0;
        sji_element sjt_parent24 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot82 = _parent;
        sjt_parent23 = &sjt_dot82->children;
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
    if (sjt_dot15->_rect._refCount == 1) { sjf_rect_destroy(&sjt_dot15->_rect); }
;
    sjt_dot15->_rect._refCount = 1;
    sjf_rect_copy(&sjt_dot15->_rect, sjt_copy3);
    sjt_parent4 = rect_;
    sjt_dot36 = _parent;
    sjt_functionParam12 = &sjt_dot36->margin;
    sjf_rect_subtractmargin(sjt_parent4, sjt_functionParam12, &sjv_innerrect);
    sjv_rowfixed = 0;
    sjv_rowstars = 0;
    sjt_forStart1 = 0;
    sjt_dot38 = _parent;
    sjt_dot37 = &sjt_dot38->rows;
    sjt_forEnd1 = sjt_dot37->count;
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
        sjt_parent5 = &sjt_dot39->rows;
        sjt_functionParam13 = r;
        sjf_array_gridunit_getat(sjt_parent5, sjt_functionParam13, &sjv_row);
        sjt_dot40 = &sjv_row;
        sjt_compare3 = sjt_dot40->type;
        sjt_compare4 = sjv_gridunittype_star;
        sjt_ifElse1 = sjt_compare3 == sjt_compare4;
        if (sjt_ifElse1) {
            sjs_gridunit* sjt_dot41 = 0;
            int32_t sjt_math29;
            int32_t sjt_math30;

            sjt_math29 = sjv_rowstars;
            sjt_dot41 = &sjv_row;
            sjt_math30 = sjt_dot41->amount;
            sjv_rowstars = sjt_math29 + sjt_math30;
        } else {
            sjs_gridunit* sjt_dot42 = 0;
            int32_t sjt_math31;
            int32_t sjt_math32;

            sjt_math31 = sjv_rowfixed;
            sjt_dot42 = &sjv_row;
            sjt_math32 = sjt_dot42->amount;
            sjv_rowfixed = sjt_math31 + sjt_math32;
        }

        r++;

        if (sjv_row._refCount == 1) { sjf_gridunit_destroy(&sjv_row); }
;
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
        sjt_math35 = sjt_dot43->h;
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
        sjt_math39 = sjt_dot44->h;
        sjt_math40 = sjv_rowfixed;
        sjt_math37 = sjt_math39 - sjt_math40;
        sjt_math38 = sjv_rowstars;
        sjv_rowstarremainder = sjt_math37 % sjt_math38;
    } else {
        sjv_rowstarremainder = 0;
    }

    sjv_ypos._refCount = 1;
    sjt_dot46 = _parent;
    sjt_dot45 = &sjt_dot46->rows;
    sjt_math41 = sjt_dot45->count;
    sjt_math42 = 1;
    sjv_ypos.datasize = sjt_math41 + sjt_math42;
    sjv_ypos.data = 0;
    sjv_ypos._isglobal = false;
    sjv_ypos.count = 0;
    sjf_array_i32(&sjv_ypos);
    sjt_dot47 = &sjv_innerrect;
    sjv_y = sjt_dot47->y;
    sjt_parent6 = &sjv_ypos;
    sjt_functionParam14 = 0;
    sjt_functionParam15 = sjv_y;
    sjf_array_i32_initat(sjt_parent6, sjt_functionParam14, sjt_functionParam15);
    sjt_forStart2 = 0;
    sjt_dot49 = _parent;
    sjt_dot48 = &sjt_dot49->rows;
    sjt_forEnd2 = sjt_dot48->count;
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
        sjt_parent7 = &sjt_dot50->rows;
        sjt_functionParam16 = r;
        sjf_array_gridunit_getat(sjt_parent7, sjt_functionParam16, &sjv_row);
        sjt_dot51 = &sjv_row;
        sjt_compare9 = sjt_dot51->type;
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
            sjt_math46 = sjt_dot52->amount;
            sjt_math44 = sjt_math45 * sjt_math46;
            sjv_y = sjt_math43 + sjt_math44;
            sjt_math47 = sjv_y;
            sjt_functionParam17 = 0;
            sjt_functionParam18 = sjv_rowstarremainder;
            sjf_i32_max(sjt_functionParam17, sjt_functionParam18, &sjt_math48);
            sjv_y = sjt_math47 + sjt_math48;
            sjt_math49 = sjv_rowstarremainder;
            sjt_dot53 = &sjv_row;
            sjt_math50 = sjt_dot53->amount;
            sjv_rowstarremainder = sjt_math49 - sjt_math50;
        } else {
            sjs_gridunit* sjt_dot54 = 0;
            int32_t sjt_math51;
            int32_t sjt_math52;

            sjt_math51 = sjv_y;
            sjt_dot54 = &sjv_row;
            sjt_math52 = sjt_dot54->amount;
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
;
    }

    sjv_colfixed = 0;
    sjv_colstars = 0;
    sjt_forStart3 = 0;
    sjt_dot56 = _parent;
    sjt_dot55 = &sjt_dot56->cols;
    sjt_forEnd3 = sjt_dot55->count;
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
        sjt_parent9 = &sjt_dot57->cols;
        sjt_functionParam21 = c;
        sjf_array_gridunit_getat(sjt_parent9, sjt_functionParam21, &sjv_col);
        sjt_dot58 = &sjv_col;
        sjt_compare13 = sjt_dot58->type;
        sjt_compare14 = sjv_gridunittype_star;
        sjt_ifElse6 = sjt_compare13 == sjt_compare14;
        if (sjt_ifElse6) {
            sjs_gridunit* sjt_dot59 = 0;
            int32_t sjt_math55;
            int32_t sjt_math56;

            sjt_math55 = sjv_colstars;
            sjt_dot59 = &sjv_col;
            sjt_math56 = sjt_dot59->amount;
            sjv_colstars = sjt_math55 + sjt_math56;
        } else {
            sjs_gridunit* sjt_dot60 = 0;
            int32_t sjt_math57;
            int32_t sjt_math58;

            sjt_math57 = sjv_colfixed;
            sjt_dot60 = &sjv_col;
            sjt_math58 = sjt_dot60->amount;
            sjv_colfixed = sjt_math57 + sjt_math58;
        }

        c++;

        if (sjv_col._refCount == 1) { sjf_gridunit_destroy(&sjv_col); }
;
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
        sjt_math61 = sjt_dot61->w;
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
        sjt_math65 = sjt_dot62->w;
        sjt_math66 = sjv_colfixed;
        sjt_math63 = sjt_math65 - sjt_math66;
        sjt_math64 = sjv_colstars;
        sjv_colstarremainder = sjt_math63 % sjt_math64;
    } else {
        sjv_colstarremainder = 0;
    }

    sjv_xpos._refCount = 1;
    sjt_dot64 = _parent;
    sjt_dot63 = &sjt_dot64->cols;
    sjt_math67 = sjt_dot63->count;
    sjt_math68 = 1;
    sjv_xpos.datasize = sjt_math67 + sjt_math68;
    sjv_xpos.data = 0;
    sjv_xpos._isglobal = false;
    sjv_xpos.count = 0;
    sjf_array_i32(&sjv_xpos);
    sjt_dot65 = &sjv_innerrect;
    sjv_x = sjt_dot65->x;
    sjt_parent10 = &sjv_xpos;
    sjt_functionParam22 = 0;
    sjt_functionParam23 = sjv_x;
    sjf_array_i32_initat(sjt_parent10, sjt_functionParam22, sjt_functionParam23);
    sjt_forStart4 = 0;
    sjt_dot67 = _parent;
    sjt_dot66 = &sjt_dot67->cols;
    sjt_forEnd4 = sjt_dot66->count;
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
        sjt_parent11 = &sjt_dot68->cols;
        sjt_functionParam24 = c;
        sjf_array_gridunit_getat(sjt_parent11, sjt_functionParam24, &sjv_col);
        sjt_dot69 = &sjv_col;
        sjt_compare19 = sjt_dot69->type;
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
            sjt_math72 = sjt_dot70->amount;
            sjt_math70 = sjt_math71 * sjt_math72;
            sjv_x = sjt_math69 + sjt_math70;
            sjt_math73 = sjv_x;
            sjt_functionParam25 = 0;
            sjt_functionParam26 = sjv_colstarremainder;
            sjf_i32_max(sjt_functionParam25, sjt_functionParam26, &sjt_math74);
            sjv_x = sjt_math73 + sjt_math74;
            sjt_math75 = sjv_colstarremainder;
            sjt_dot71 = &sjv_col;
            sjt_math76 = sjt_dot71->amount;
            sjv_colstarremainder = sjt_math75 - sjt_math76;
        } else {
            sjs_gridunit* sjt_dot72 = 0;
            int32_t sjt_math77;
            int32_t sjt_math78;

            sjt_math77 = sjv_x;
            sjt_dot72 = &sjv_col;
            sjt_math78 = sjt_dot72->amount;
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
;
    }

    sjv_rnext = 0;
    sjv_cnext = 0;
    sjt_forStart5 = 0;
    sjt_dot74 = _parent;
    sjt_dot73 = &sjt_dot74->children;
    sjt_forEnd5 = sjt_dot73->count;
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
        sjt_parent13 = &sjt_dot75->children;
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
            sjt_dot76 = &sjt_dot77->cols;
            sjt_compare22 = sjt_dot76->count;
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
                sjt_dot78 = &sjt_dot79->rows;
                sjt_compare24 = sjt_dot78->count;
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
                delete_cb weakptrcb15 = { &kh_value(p, k), weakptr_clear };
if (kh_value(p, k) != 0) { weakptr_cb_remove(kh_value(p, k), weakptrcb15); }
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
delete_cb weakptrcb22 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb22); }
return;
    }
    (*_return) = kh_val(p, k);
delete_cb weakptrcb23 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb23); }
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
    delete_cb weakptrcb24 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_remove(kh_val(p, k), weakptrcb24); }
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
delete_cb weakptrcb25 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_add(kh_val(p, k), weakptrcb25); }
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
                delete_cb weakptrcb14 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb14); }
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
    delete_cb weakptrcb19 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_remove(kh_val(p, k)._parent, weakptrcb19); }
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
delete_cb weakptrcb20 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_add(kh_val(p, k)._parent, weakptrcb20); }
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
                delete_cb weakptrcb13 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb13); }
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

void sjf_hash_string_weak_iface_model_setat(sjs_hash_string_weak_iface_model* _parent, sjs_string* key, sji_model val) {
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    delete_cb weakptrcb16 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_remove(kh_val(p, k)._parent, weakptrcb16); }
;
}
int ret;
#if true
k = kh_put(string_weak_iface_model_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(string_weak_iface_model_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(string_weak_iface_model_hash_type, p, k);
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovekey };
weakptr_cb_add(key, cb);
#else
sjs_string t;
t._refCount = 1;
sjf_string_copy(&t, key);
;
#endif
#if true
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovevalue };
weakptr_cb_add(val._parent, cb);
kh_val(p, k) = val;
#else
kh_val(p, k) = val;
delete_cb weakptrcb17 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_add(kh_val(p, k)._parent, weakptrcb17); }
;
#endif
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
    sjs_list_heap_iface_animation* sjt_dot1845 = 0;
    int32_t sjt_functionParam646;
    sjs_array_heap_iface_animation* sjt_parent308 = 0;

    sjt_dot1845 = _parent;
    sjt_parent308 = &sjt_dot1845->array;
    sjt_functionParam646 = index;
    sjf_array_heap_iface_animation_getat_heap(sjt_parent308, sjt_functionParam646, _return);
}

void sjf_list_heap_iface_animation_getcount(sjs_list_heap_iface_animation* _parent, int32_t* _return) {
    sjs_array_heap_iface_animation* sjt_dot1841 = 0;
    sjs_list_heap_iface_animation* sjt_dot1842 = 0;

    sjt_dot1842 = _parent;
    sjt_dot1841 = &sjt_dot1842->array;
    (*_return) = sjt_dot1841->count;
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

void sjf_list_heap_iface_model_add(sjs_list_heap_iface_model* _parent, sji_model item) {
    sjs_array_heap_iface_model sjt_call26 = { -1 };
    int32_t sjt_compare81;
    int32_t sjt_compare82;
    sjs_array_heap_iface_model* sjt_dot692 = 0;
    sjs_list_heap_iface_model* sjt_dot693 = 0;
    sjs_array_heap_iface_model* sjt_dot694 = 0;
    sjs_list_heap_iface_model* sjt_dot695 = 0;
    sjs_list_heap_iface_model* sjt_dot702 = 0;
    sjs_array_heap_iface_model* sjt_dot703 = 0;
    sjs_list_heap_iface_model* sjt_dot704 = 0;
    int32_t sjt_functionParam156;
    sji_model sjt_functionParam157 = { 0 };
    bool sjt_ifElse37;
    sjs_array_heap_iface_model* sjt_parent105 = 0;

    sjt_dot693 = _parent;
    sjt_dot692 = &sjt_dot693->array;
    sjt_compare81 = sjt_dot692->count;
    sjt_dot695 = _parent;
    sjt_dot694 = &sjt_dot695->array;
    sjt_compare82 = sjt_dot694->datasize;
    sjt_ifElse37 = sjt_compare81 >= sjt_compare82;
    if (sjt_ifElse37) {
        sjs_array_heap_iface_model* sjt_copy28 = 0;
        sjs_list_heap_iface_model* sjt_dot696 = 0;
        sjs_list_heap_iface_model* sjt_dot699 = 0;
        sjs_array_heap_iface_model* sjt_dot700 = 0;
        sjs_list_heap_iface_model* sjt_dot701 = 0;
        int32_t sjt_functionParam153;
        int32_t sjt_functionParam154;
        int32_t sjt_functionParam155;
        int32_t sjt_math869;
        int32_t sjt_math870;
        sjs_array_heap_iface_model* sjt_parent104 = 0;

        sjt_dot696 = _parent;
        sjt_dot699 = _parent;
        sjt_parent104 = &sjt_dot699->array;
        sjt_functionParam154 = 10;
        sjt_dot701 = _parent;
        sjt_dot700 = &sjt_dot701->array;
        sjt_math869 = sjt_dot700->datasize;
        sjt_math870 = 2;
        sjt_functionParam155 = sjt_math869 * sjt_math870;
        sjf_i32_max(sjt_functionParam154, sjt_functionParam155, &sjt_functionParam153);
        sjf_array_heap_iface_model_grow(sjt_parent104, sjt_functionParam153, &sjt_call26);
        sjt_copy28 = &sjt_call26;
        if (sjt_dot696->array._refCount == 1) { sjf_array_heap_iface_model_destroy(&sjt_dot696->array); }
;
        sjt_dot696->array._refCount = 1;
        sjf_array_heap_iface_model_copy(&sjt_dot696->array, sjt_copy28);
    }

    sjt_dot702 = _parent;
    sjt_parent105 = &sjt_dot702->array;
    sjt_dot704 = _parent;
    sjt_dot703 = &sjt_dot704->array;
    sjt_functionParam156 = sjt_dot703->count;
    sjt_functionParam157 = item;
    if (sjt_functionParam157._parent != 0) {
        sjt_functionParam157._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent105, sjt_functionParam156, sjt_functionParam157);

    if (sjt_functionParam157._parent != 0) {
        sjt_functionParam157._parent->_refCount--;
        if (sjt_functionParam157._parent->_refCount <= 0) {
            sjt_functionParam157._vtbl->destroy(sjt_functionParam157._parent);
            free(sjt_functionParam157._parent);
        }
    }
    if (sjt_call26._refCount == 1) { sjf_array_heap_iface_model_destroy(&sjt_call26); }
;
}

void sjf_list_heap_iface_model_copy(sjs_list_heap_iface_model* _this, sjs_list_heap_iface_model* _from) {
    _this->array._refCount = 1;
    sjf_array_heap_iface_model_copy(&_this->array, &_from->array);
}

void sjf_list_heap_iface_model_destroy(sjs_list_heap_iface_model* _this) {
    if (_this->array._refCount == 1) { sjf_array_heap_iface_model_destroy(&_this->array); }
;
}

void sjf_list_heap_iface_model_getat_heap(sjs_list_heap_iface_model* _parent, int32_t index, sji_model* _return) {
    sjs_list_heap_iface_model* sjt_dot325 = 0;
    int32_t sjt_functionParam126;
    sjs_array_heap_iface_model* sjt_parent83 = 0;

    sjt_dot325 = _parent;
    sjt_parent83 = &sjt_dot325->array;
    sjt_functionParam126 = index;
    sjf_array_heap_iface_model_getat_heap(sjt_parent83, sjt_functionParam126, _return);
}

void sjf_list_heap_iface_model_getcount(sjs_list_heap_iface_model* _parent, int32_t* _return) {
    sjs_array_heap_iface_model* sjt_dot323 = 0;
    sjs_list_heap_iface_model* sjt_dot324 = 0;

    sjt_dot324 = _parent;
    sjt_dot323 = &sjt_dot324->array;
    (*_return) = sjt_dot323->count;
}

void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this) {
}

void sjf_list_heap_iface_model_sortcb(sjs_list_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb) {
    sjs_list_heap_iface_model* sjt_dot322 = 0;
    cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam122;
    sjs_array_heap_iface_model* sjt_parent78 = 0;

    sjt_dot322 = _parent;
    sjt_parent78 = &sjt_dot322->array;
    sjt_functionParam122 = cb;
    sjf_array_heap_iface_model_sortcb(sjt_parent78, sjt_functionParam122);
}

void sjf_list_i32(sjs_list_i32* _this) {
}

void sjf_list_i32_add(sjs_list_i32* _parent, int32_t item) {
    sjs_array_i32 sjt_call36 = { -1 };
    int32_t sjt_compare83;
    int32_t sjt_compare84;
    sjs_array_i32* sjt_dot1466 = 0;
    sjs_list_i32* sjt_dot1467 = 0;
    sjs_array_i32* sjt_dot1468 = 0;
    sjs_list_i32* sjt_dot1469 = 0;
    sjs_list_i32* sjt_dot1476 = 0;
    sjs_array_i32* sjt_dot1477 = 0;
    sjs_list_i32* sjt_dot1478 = 0;
    int32_t sjt_functionParam195;
    int32_t sjt_functionParam196;
    bool sjt_ifElse38;
    sjs_array_i32* sjt_parent117 = 0;

    sjt_dot1467 = _parent;
    sjt_dot1466 = &sjt_dot1467->array;
    sjt_compare83 = sjt_dot1466->count;
    sjt_dot1469 = _parent;
    sjt_dot1468 = &sjt_dot1469->array;
    sjt_compare84 = sjt_dot1468->datasize;
    sjt_ifElse38 = sjt_compare83 >= sjt_compare84;
    if (sjt_ifElse38) {
        sjs_array_i32* sjt_copy29 = 0;
        sjs_list_i32* sjt_dot1470 = 0;
        sjs_list_i32* sjt_dot1473 = 0;
        sjs_array_i32* sjt_dot1474 = 0;
        sjs_list_i32* sjt_dot1475 = 0;
        int32_t sjt_functionParam192;
        int32_t sjt_functionParam193;
        int32_t sjt_functionParam194;
        int32_t sjt_math2217;
        int32_t sjt_math2218;
        sjs_array_i32* sjt_parent116 = 0;

        sjt_dot1470 = _parent;
        sjt_dot1473 = _parent;
        sjt_parent116 = &sjt_dot1473->array;
        sjt_functionParam193 = 10;
        sjt_dot1475 = _parent;
        sjt_dot1474 = &sjt_dot1475->array;
        sjt_math2217 = sjt_dot1474->datasize;
        sjt_math2218 = 2;
        sjt_functionParam194 = sjt_math2217 * sjt_math2218;
        sjf_i32_max(sjt_functionParam193, sjt_functionParam194, &sjt_functionParam192);
        sjf_array_i32_grow(sjt_parent116, sjt_functionParam192, &sjt_call36);
        sjt_copy29 = &sjt_call36;
        if (sjt_dot1470->array._refCount == 1) { sjf_array_i32_destroy(&sjt_dot1470->array); }
;
        sjt_dot1470->array._refCount = 1;
        sjf_array_i32_copy(&sjt_dot1470->array, sjt_copy29);
    }

    sjt_dot1476 = _parent;
    sjt_parent117 = &sjt_dot1476->array;
    sjt_dot1478 = _parent;
    sjt_dot1477 = &sjt_dot1478->array;
    sjt_functionParam195 = sjt_dot1477->count;
    sjt_functionParam196 = item;
    sjf_array_i32_initat(sjt_parent117, sjt_functionParam195, sjt_functionParam196);

    if (sjt_call36._refCount == 1) { sjf_array_i32_destroy(&sjt_call36); }
;
}

void sjf_list_i32_copy(sjs_list_i32* _this, sjs_list_i32* _from) {
    _this->array._refCount = 1;
    sjf_array_i32_copy(&_this->array, &_from->array);
}

void sjf_list_i32_destroy(sjs_list_i32* _this) {
    if (_this->array._refCount == 1) { sjf_array_i32_destroy(&_this->array); }
;
}

void sjf_list_i32_getat(sjs_list_i32* _parent, int32_t index, int32_t* _return) {
    sjs_list_i32* sjt_dot1525 = 0;
    int32_t sjt_functionParam252;
    sjs_array_i32* sjt_parent158 = 0;

    sjt_dot1525 = _parent;
    sjt_parent158 = &sjt_dot1525->array;
    sjt_functionParam252 = index;
    sjf_array_i32_getat(sjt_parent158, sjt_functionParam252, _return);
}

void sjf_list_i32_getcount(sjs_list_i32* _parent, int32_t* _return) {
    sjs_array_i32* sjt_dot1523 = 0;
    sjs_list_i32* sjt_dot1524 = 0;

    sjt_dot1524 = _parent;
    sjt_dot1523 = &sjt_dot1524->array;
    (*_return) = sjt_dot1523->count;
}

void sjf_list_i32_heap(sjs_list_i32* _this) {
}

void sjf_list_rect(sjs_list_rect* _this) {
}

void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item) {
    sjs_array_rect sjt_call18 = { -1 };
    int32_t sjt_compare49;
    int32_t sjt_compare50;
    sjs_array_rect* sjt_dot300 = 0;
    sjs_list_rect* sjt_dot301 = 0;
    sjs_array_rect* sjt_dot302 = 0;
    sjs_list_rect* sjt_dot303 = 0;
    sjs_list_rect* sjt_dot310 = 0;
    sjs_array_rect* sjt_dot311 = 0;
    sjs_list_rect* sjt_dot312 = 0;
    int32_t sjt_functionParam94;
    sjs_rect* sjt_functionParam95 = 0;
    bool sjt_ifElse25;
    sjs_array_rect* sjt_parent74 = 0;

    sjt_dot301 = _parent;
    sjt_dot300 = &sjt_dot301->array;
    sjt_compare49 = sjt_dot300->count;
    sjt_dot303 = _parent;
    sjt_dot302 = &sjt_dot303->array;
    sjt_compare50 = sjt_dot302->datasize;
    sjt_ifElse25 = sjt_compare49 >= sjt_compare50;
    if (sjt_ifElse25) {
        sjs_array_rect* sjt_copy20 = 0;
        sjs_list_rect* sjt_dot304 = 0;
        sjs_list_rect* sjt_dot307 = 0;
        sjs_array_rect* sjt_dot308 = 0;
        sjs_list_rect* sjt_dot309 = 0;
        int32_t sjt_functionParam91;
        int32_t sjt_functionParam92;
        int32_t sjt_functionParam93;
        int32_t sjt_math273;
        int32_t sjt_math274;
        sjs_array_rect* sjt_parent73 = 0;

        sjt_dot304 = _parent;
        sjt_dot307 = _parent;
        sjt_parent73 = &sjt_dot307->array;
        sjt_functionParam92 = 10;
        sjt_dot309 = _parent;
        sjt_dot308 = &sjt_dot309->array;
        sjt_math273 = sjt_dot308->datasize;
        sjt_math274 = 2;
        sjt_functionParam93 = sjt_math273 * sjt_math274;
        sjf_i32_max(sjt_functionParam92, sjt_functionParam93, &sjt_functionParam91);
        sjf_array_rect_grow(sjt_parent73, sjt_functionParam91, &sjt_call18);
        sjt_copy20 = &sjt_call18;
        if (sjt_dot304->array._refCount == 1) { sjf_array_rect_destroy(&sjt_dot304->array); }
;
        sjt_dot304->array._refCount = 1;
        sjf_array_rect_copy(&sjt_dot304->array, sjt_copy20);
    }

    sjt_dot310 = _parent;
    sjt_parent74 = &sjt_dot310->array;
    sjt_dot312 = _parent;
    sjt_dot311 = &sjt_dot312->array;
    sjt_functionParam94 = sjt_dot311->count;
    sjt_functionParam95 = item;
    sjf_array_rect_initat(sjt_parent74, sjt_functionParam94, sjt_functionParam95);

    if (sjt_call18._refCount == 1) { sjf_array_rect_destroy(&sjt_call18); }
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
    sjs_list_rect* sjt_dot332 = 0;
    int32_t sjt_functionParam128;
    sjs_array_rect* sjt_parent87 = 0;

    sjt_dot332 = _parent;
    sjt_parent87 = &sjt_dot332->array;
    sjt_functionParam128 = index;
    sjf_array_rect_getat(sjt_parent87, sjt_functionParam128, _return);
}

void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return) {
    sjs_array_rect* sjt_dot333 = 0;
    sjs_list_rect* sjt_dot334 = 0;

    sjt_dot334 = _parent;
    sjt_dot333 = &sjt_dot334->array;
    (*_return) = sjt_dot333->count;
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

void sjf_list_u32_add(sjs_list_u32* _parent, uint32_t item) {
    sjs_array_u32 sjt_call144 = { -1 };
    int32_t sjt_compare107;
    int32_t sjt_compare108;
    sjs_array_u32* sjt_dot1627 = 0;
    sjs_list_u32* sjt_dot1628 = 0;
    sjs_array_u32* sjt_dot1629 = 0;
    sjs_list_u32* sjt_dot1630 = 0;
    sjs_list_u32* sjt_dot1637 = 0;
    sjs_array_u32* sjt_dot1638 = 0;
    sjs_list_u32* sjt_dot1639 = 0;
    int32_t sjt_functionParam402;
    uint32_t sjt_functionParam403;
    bool sjt_ifElse51;
    sjs_array_u32* sjt_parent264 = 0;

    sjt_dot1628 = _parent;
    sjt_dot1627 = &sjt_dot1628->array;
    sjt_compare107 = sjt_dot1627->count;
    sjt_dot1630 = _parent;
    sjt_dot1629 = &sjt_dot1630->array;
    sjt_compare108 = sjt_dot1629->datasize;
    sjt_ifElse51 = sjt_compare107 >= sjt_compare108;
    if (sjt_ifElse51) {
        sjs_array_u32* sjt_copy86 = 0;
        sjs_list_u32* sjt_dot1631 = 0;
        sjs_list_u32* sjt_dot1634 = 0;
        sjs_array_u32* sjt_dot1635 = 0;
        sjs_list_u32* sjt_dot1636 = 0;
        int32_t sjt_functionParam399;
        int32_t sjt_functionParam400;
        int32_t sjt_functionParam401;
        int32_t sjt_math2329;
        int32_t sjt_math2330;
        sjs_array_u32* sjt_parent263 = 0;

        sjt_dot1631 = _parent;
        sjt_dot1634 = _parent;
        sjt_parent263 = &sjt_dot1634->array;
        sjt_functionParam400 = 10;
        sjt_dot1636 = _parent;
        sjt_dot1635 = &sjt_dot1636->array;
        sjt_math2329 = sjt_dot1635->datasize;
        sjt_math2330 = 2;
        sjt_functionParam401 = sjt_math2329 * sjt_math2330;
        sjf_i32_max(sjt_functionParam400, sjt_functionParam401, &sjt_functionParam399);
        sjf_array_u32_grow(sjt_parent263, sjt_functionParam399, &sjt_call144);
        sjt_copy86 = &sjt_call144;
        if (sjt_dot1631->array._refCount == 1) { sjf_array_u32_destroy(&sjt_dot1631->array); }
;
        sjt_dot1631->array._refCount = 1;
        sjf_array_u32_copy(&sjt_dot1631->array, sjt_copy86);
    }

    sjt_dot1637 = _parent;
    sjt_parent264 = &sjt_dot1637->array;
    sjt_dot1639 = _parent;
    sjt_dot1638 = &sjt_dot1639->array;
    sjt_functionParam402 = sjt_dot1638->count;
    sjt_functionParam403 = item;
    sjf_array_u32_initat(sjt_parent264, sjt_functionParam402, sjt_functionParam403);

    if (sjt_call144._refCount == 1) { sjf_array_u32_destroy(&sjt_call144); }
;
}

void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from) {
    _this->array._refCount = 1;
    sjf_array_u32_copy(&_this->array, &_from->array);
}

void sjf_list_u32_destroy(sjs_list_u32* _this) {
    if (_this->array._refCount == 1) { sjf_array_u32_destroy(&_this->array); }
;
}

void sjf_list_u32_getat(sjs_list_u32* _parent, int32_t index, uint32_t* _return) {
    sjs_list_u32* sjt_dot1641 = 0;
    int32_t sjt_functionParam436;
    sjs_array_u32* sjt_parent266 = 0;

    sjt_dot1641 = _parent;
    sjt_parent266 = &sjt_dot1641->array;
    sjt_functionParam436 = index;
    sjf_array_u32_getat(sjt_parent266, sjt_functionParam436, _return);
}

void sjf_list_u32_getcount(sjs_list_u32* _parent, int32_t* _return) {
    sjs_array_u32* sjt_dot1642 = 0;
    sjs_list_u32* sjt_dot1643 = 0;

    sjt_dot1643 = _parent;
    sjt_dot1642 = &sjt_dot1643->array;
    (*_return) = sjt_dot1642->count;
}

void sjf_list_u32_heap(sjs_list_u32* _this) {
}

void sjf_list_u32_removeat(sjs_list_u32* _parent, int32_t index) {
    if (index < 0 || index >= _parent->array.count) {
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
    }
    uint32_t* p = (uint32_t*)_parent->array.data;
    ;
    if (index != _parent->array.count - 1) {
        memcpy(p + index, p + index + 1, (_parent->array.count - index - 1) * sizeof(uint32_t));
    }
    _parent->array.count--;
}

void sjf_list_vertex_location_texture_normal(sjs_list_vertex_location_texture_normal* _this) {
}

void sjf_list_vertex_location_texture_normal_add(sjs_list_vertex_location_texture_normal* _parent, sjs_vertex_location_texture_normal* item) {
    sjs_array_vertex_location_texture_normal sjt_call70 = { -1 };
    int32_t sjt_compare89;
    int32_t sjt_compare90;
    sjs_array_vertex_location_texture_normal* sjt_dot1508 = 0;
    sjs_list_vertex_location_texture_normal* sjt_dot1509 = 0;
    sjs_array_vertex_location_texture_normal* sjt_dot1510 = 0;
    sjs_list_vertex_location_texture_normal* sjt_dot1511 = 0;
    sjs_list_vertex_location_texture_normal* sjt_dot1518 = 0;
    sjs_array_vertex_location_texture_normal* sjt_dot1519 = 0;
    sjs_list_vertex_location_texture_normal* sjt_dot1520 = 0;
    int32_t sjt_functionParam247;
    sjs_vertex_location_texture_normal* sjt_functionParam248 = 0;
    bool sjt_ifElse41;
    sjs_array_vertex_location_texture_normal* sjt_parent152 = 0;

    sjt_dot1509 = _parent;
    sjt_dot1508 = &sjt_dot1509->array;
    sjt_compare89 = sjt_dot1508->count;
    sjt_dot1511 = _parent;
    sjt_dot1510 = &sjt_dot1511->array;
    sjt_compare90 = sjt_dot1510->datasize;
    sjt_ifElse41 = sjt_compare89 >= sjt_compare90;
    if (sjt_ifElse41) {
        sjs_array_vertex_location_texture_normal* sjt_copy34 = 0;
        sjs_list_vertex_location_texture_normal* sjt_dot1512 = 0;
        sjs_list_vertex_location_texture_normal* sjt_dot1515 = 0;
        sjs_array_vertex_location_texture_normal* sjt_dot1516 = 0;
        sjs_list_vertex_location_texture_normal* sjt_dot1517 = 0;
        int32_t sjt_functionParam244;
        int32_t sjt_functionParam245;
        int32_t sjt_functionParam246;
        int32_t sjt_math2243;
        int32_t sjt_math2244;
        sjs_array_vertex_location_texture_normal* sjt_parent151 = 0;

        sjt_dot1512 = _parent;
        sjt_dot1515 = _parent;
        sjt_parent151 = &sjt_dot1515->array;
        sjt_functionParam245 = 10;
        sjt_dot1517 = _parent;
        sjt_dot1516 = &sjt_dot1517->array;
        sjt_math2243 = sjt_dot1516->datasize;
        sjt_math2244 = 2;
        sjt_functionParam246 = sjt_math2243 * sjt_math2244;
        sjf_i32_max(sjt_functionParam245, sjt_functionParam246, &sjt_functionParam244);
        sjf_array_vertex_location_texture_normal_grow(sjt_parent151, sjt_functionParam244, &sjt_call70);
        sjt_copy34 = &sjt_call70;
        if (sjt_dot1512->array._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&sjt_dot1512->array); }
;
        sjt_dot1512->array._refCount = 1;
        sjf_array_vertex_location_texture_normal_copy(&sjt_dot1512->array, sjt_copy34);
    }

    sjt_dot1518 = _parent;
    sjt_parent152 = &sjt_dot1518->array;
    sjt_dot1520 = _parent;
    sjt_dot1519 = &sjt_dot1520->array;
    sjt_functionParam247 = sjt_dot1519->count;
    sjt_functionParam248 = item;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent152, sjt_functionParam247, sjt_functionParam248);

    if (sjt_call70._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&sjt_call70); }
;
}

void sjf_list_vertex_location_texture_normal_copy(sjs_list_vertex_location_texture_normal* _this, sjs_list_vertex_location_texture_normal* _from) {
    _this->array._refCount = 1;
    sjf_array_vertex_location_texture_normal_copy(&_this->array, &_from->array);
}

void sjf_list_vertex_location_texture_normal_destroy(sjs_list_vertex_location_texture_normal* _this) {
    if (_this->array._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&_this->array); }
;
}

void sjf_list_vertex_location_texture_normal_getat(sjs_list_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return) {
    sjs_list_vertex_location_texture_normal* sjt_dot1527 = 0;
    int32_t sjt_functionParam256;
    sjs_array_vertex_location_texture_normal* sjt_parent162 = 0;

    sjt_dot1527 = _parent;
    sjt_parent162 = &sjt_dot1527->array;
    sjt_functionParam256 = index;
    sjf_array_vertex_location_texture_normal_getat(sjt_parent162, sjt_functionParam256, _return);
}

void sjf_list_vertex_location_texture_normal_getcount(sjs_list_vertex_location_texture_normal* _parent, int32_t* _return) {
    sjs_array_vertex_location_texture_normal* sjt_dot1521 = 0;
    sjs_list_vertex_location_texture_normal* sjt_dot1522 = 0;

    sjt_dot1522 = _parent;
    sjt_dot1521 = &sjt_dot1522->array;
    (*_return) = sjt_dot1521->count;
}

void sjf_list_vertex_location_texture_normal_heap(sjs_list_vertex_location_texture_normal* _this) {
}

void sjf_list_vertex_location_texture_normal_setat(sjs_list_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item) {
    sjs_list_vertex_location_texture_normal* sjt_dot1542 = 0;
    int32_t sjt_functionParam276;
    sjs_vertex_location_texture_normal* sjt_functionParam277 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent182 = 0;

    sjt_dot1542 = _parent;
    sjt_parent182 = &sjt_dot1542->array;
    sjt_functionParam276 = index;
    sjt_functionParam277 = item;
    sjf_array_vertex_location_texture_normal_setat(sjt_parent182, sjt_functionParam276, sjt_functionParam277);
}

void sjf_mainloop(bool* _return) {
    bool result24;
    sjs_size* sjt_dot1848 = 0;
    sjs_size* sjt_dot1849 = 0;
    int32_t sjt_functionParam649;
    sjs_size* sjt_functionParam650 = 0;
    sjs_rect* sjt_functionParam651 = 0;
    bool sjt_ifElse76;
    sjs_scene2d* sjt_interfaceParam21 = 0;
    bool sjt_isEmpty53;
    int32_option sjt_isEmpty54;
    bool sjt_not17;
    sjs_animator* sjt_parent312 = 0;
    sjs_windowrenderer* sjt_parent313 = 0;
    sjs_scene2d* sjt_parent314 = 0;
    sjs_scene2d* sjt_parent315 = 0;
    sjs_rect* sjt_parent316 = 0;
    sji_element sjt_parent318 = { 0 };
    sjs_scene2d* sjt_parent319 = 0;
    sjs_windowrenderer* sjt_parent320 = 0;
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
    sjt_parent312 = &sjv_animator;
    sjt_functionParam649 = sjv_ticks;
    sjf_animator_nextframe(sjt_parent312, sjt_functionParam649);
    sjt_parent313 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_getsize(sjt_parent313, &sjv_size);
    sjt_parent314 = &sjv_rootscene;
    sjt_functionParam650 = &sjv_size;
    sjf_scene2d_setsize(sjt_parent314, sjt_functionParam650);
    sjt_parent315 = &sjv_rootscene;
    sjf_scene2d_start(sjt_parent315);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot1848 = &sjv_size;
    sjv_rect.w = sjt_dot1848->w;
    sjt_dot1849 = &sjv_size;
    sjv_rect.h = sjt_dot1849->h;
    sjf_rect(&sjv_rect);
    sjt_parent316 = &sjv_looplastrect;
    sjt_functionParam651 = &sjv_rect;
    sjf_rect_isequal(sjt_parent316, sjt_functionParam651, &sjt_not17);
    result24 = !sjt_not17;
    sjt_ifElse76 = result24;
    if (sjt_ifElse76) {
        sjs_rect* sjt_interfaceParam20 = 0;
        sji_element sjt_parent317 = { 0 };

        sjt_parent317 = sjv_root;
        sjt_interfaceParam20 = &sjv_rect;
        sjt_parent317._vtbl->setrect(sjt_parent317._parent, sjt_interfaceParam20);
    }

    sjt_parent318 = sjv_root;
    sjt_interfaceParam21 = &sjv_rootscene;
    sjt_parent318._vtbl->render(sjt_parent318._parent, sjt_interfaceParam21);
    sjt_parent319 = &sjv_rootscene;
    sjf_scene2d_end(sjt_parent319);
    sjt_parent320 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_present(sjt_parent320);
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
        sjt_isEmpty54 = sjv_mouse_eventtype;
        sjt_isEmpty53 = sjt_isEmpty54.isvalid;
        if (sjt_isEmpty53) {
            int32_t ifValue39;
            int32_option sjt_getValue1;
            bool sjt_isEmpty55;
            sji_element sjt_isEmpty56 = { 0 };

            sjt_getValue1 = sjv_mouse_eventtype;
            ifValue39 = sjt_getValue1.value;
            sjt_isEmpty56 = sjv_mouse_captureelement;
            sjt_isEmpty55 = (sjt_isEmpty56._parent != 0);
            if (sjt_isEmpty55) {
                sji_element ifValue40 = { 0 };
                sjs_mouseevent sjt_call200 = { -1 };
                sjs_mouseevent* sjt_interfaceParam22 = 0;
                sji_element sjt_parent321 = { 0 };

                ifValue40 = sjv_mouse_captureelement;
                if (ifValue40._parent != 0) {
                    ifValue40._parent->_refCount++;
                }

                sjt_parent321 = ifValue40;
                sjt_call200._refCount = 1;
                sjt_call200.type = ifValue39;
                sjt_call200.point._refCount = 1;
                sjt_call200.point.x = sjv_mouse_x;
                sjt_call200.point.y = sjv_mouse_y;
                sjf_point(&sjt_call200.point);
                sjt_call200.iscaptured = true;
                sjt_call200.isleftdown = sjv_mouse_isleftdown;
                sjf_mouseevent(&sjt_call200);
                sjt_interfaceParam22 = &sjt_call200;
                sjt_parent321._vtbl->firemouseevent(sjt_parent321._parent, sjt_interfaceParam22, &sjv_shouldcontinue);

                if (ifValue40._parent != 0) {
                    ifValue40._parent->_refCount--;
                    if (ifValue40._parent->_refCount <= 0) {
                        ifValue40._vtbl->destroy(ifValue40._parent);
                        free(ifValue40._parent);
                    }
                }
                if (sjt_call200._refCount == 1) { sjf_mouseevent_destroy(&sjt_call200); }
;
            } else {
                sjs_mouseevent sjt_call201 = { -1 };
                sjs_mouseevent* sjt_interfaceParam23 = 0;
                sji_element sjt_parent322 = { 0 };

                sjt_parent322 = sjv_root;
                sjt_call201._refCount = 1;
                sjt_call201.type = ifValue39;
                sjt_call201.point._refCount = 1;
                sjt_call201.point.x = sjv_mouse_x;
                sjt_call201.point.y = sjv_mouse_y;
                sjf_point(&sjt_call201.point);
                sjt_call201.iscaptured = false;
                sjt_call201.isleftdown = sjv_mouse_isleftdown;
                sjf_mouseevent(&sjt_call201);
                sjt_interfaceParam23 = &sjt_call201;
                sjt_parent322._vtbl->firemouseevent(sjt_parent322._parent, sjt_interfaceParam23, &sjv_shouldcontinue);

                if (sjt_call201._refCount == 1) { sjf_mouseevent_destroy(&sjt_call201); }
;
            }
        }

    }
    (*_return) = sjv_shouldappcontinue;

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

void sjf_mat4_determinant(sjs_mat4* _parent, float* _return) {
    sjs_mat4* sjt_dot1060 = 0;
    sjs_mat4* sjt_dot1061 = 0;
    sjs_mat4* sjt_dot1062 = 0;
    sjs_mat4* sjt_dot1063 = 0;
    sjs_mat4* sjt_dot1064 = 0;
    sjs_mat4* sjt_dot1065 = 0;
    sjs_mat4* sjt_dot1066 = 0;
    sjs_mat4* sjt_dot1067 = 0;
    sjs_mat4* sjt_dot1068 = 0;
    sjs_mat4* sjt_dot1069 = 0;
    sjs_mat4* sjt_dot1070 = 0;
    sjs_mat4* sjt_dot1071 = 0;
    sjs_mat4* sjt_dot1072 = 0;
    sjs_mat4* sjt_dot1073 = 0;
    sjs_mat4* sjt_dot1074 = 0;
    sjs_mat4* sjt_dot1075 = 0;
    sjs_mat4* sjt_dot1076 = 0;
    sjs_mat4* sjt_dot1077 = 0;
    sjs_mat4* sjt_dot1078 = 0;
    sjs_mat4* sjt_dot1079 = 0;
    sjs_mat4* sjt_dot1080 = 0;
    sjs_mat4* sjt_dot1081 = 0;
    sjs_mat4* sjt_dot1082 = 0;
    sjs_mat4* sjt_dot1083 = 0;
    sjs_mat4* sjt_dot1084 = 0;
    sjs_mat4* sjt_dot1085 = 0;
    sjs_mat4* sjt_dot1086 = 0;
    sjs_mat4* sjt_dot1087 = 0;
    sjs_mat4* sjt_dot1088 = 0;
    sjs_mat4* sjt_dot1089 = 0;
    sjs_mat4* sjt_dot1090 = 0;
    sjs_mat4* sjt_dot1091 = 0;
    sjs_mat4* sjt_dot1092 = 0;
    sjs_mat4* sjt_dot1093 = 0;
    sjs_mat4* sjt_dot1094 = 0;
    sjs_mat4* sjt_dot1095 = 0;
    sjs_mat4* sjt_dot1096 = 0;
    sjs_mat4* sjt_dot1097 = 0;
    sjs_mat4* sjt_dot1098 = 0;
    sjs_mat4* sjt_dot1099 = 0;
    sjs_mat4* sjt_dot1100 = 0;
    sjs_mat4* sjt_dot1101 = 0;
    sjs_mat4* sjt_dot1102 = 0;
    sjs_mat4* sjt_dot1103 = 0;
    sjs_mat4* sjt_dot1104 = 0;
    sjs_mat4* sjt_dot1105 = 0;
    sjs_mat4* sjt_dot1106 = 0;
    sjs_mat4* sjt_dot1107 = 0;
    sjs_mat4* sjt_dot1108 = 0;
    sjs_mat4* sjt_dot1109 = 0;
    sjs_mat4* sjt_dot1110 = 0;
    sjs_mat4* sjt_dot1111 = 0;
    sjs_mat4* sjt_dot1112 = 0;
    sjs_mat4* sjt_dot1113 = 0;
    sjs_mat4* sjt_dot1114 = 0;
    sjs_mat4* sjt_dot1115 = 0;
    sjs_mat4* sjt_dot1116 = 0;
    sjs_mat4* sjt_dot1117 = 0;
    sjs_mat4* sjt_dot1118 = 0;
    sjs_mat4* sjt_dot1119 = 0;
    sjs_mat4* sjt_dot1120 = 0;
    sjs_mat4* sjt_dot1121 = 0;
    sjs_mat4* sjt_dot1122 = 0;
    sjs_mat4* sjt_dot1123 = 0;
    sjs_mat4* sjt_dot1124 = 0;
    sjs_mat4* sjt_dot1125 = 0;
    sjs_mat4* sjt_dot1126 = 0;
    sjs_mat4* sjt_dot1127 = 0;
    sjs_mat4* sjt_dot1128 = 0;
    sjs_mat4* sjt_dot1129 = 0;
    sjs_mat4* sjt_dot1130 = 0;
    sjs_mat4* sjt_dot1131 = 0;
    sjs_mat4* sjt_dot1132 = 0;
    sjs_mat4* sjt_dot1133 = 0;
    sjs_mat4* sjt_dot1134 = 0;
    sjs_mat4* sjt_dot1135 = 0;
    sjs_mat4* sjt_dot1136 = 0;
    sjs_mat4* sjt_dot1137 = 0;
    sjs_mat4* sjt_dot1138 = 0;
    sjs_mat4* sjt_dot1139 = 0;
    sjs_mat4* sjt_dot1140 = 0;
    sjs_mat4* sjt_dot1141 = 0;
    sjs_mat4* sjt_dot1142 = 0;
    sjs_mat4* sjt_dot1143 = 0;
    sjs_mat4* sjt_dot1144 = 0;
    sjs_mat4* sjt_dot1145 = 0;
    sjs_mat4* sjt_dot1146 = 0;
    sjs_mat4* sjt_dot1147 = 0;
    sjs_mat4* sjt_dot1148 = 0;
    sjs_mat4* sjt_dot1149 = 0;
    sjs_mat4* sjt_dot1150 = 0;
    sjs_mat4* sjt_dot1151 = 0;
    sjs_mat4* sjt_dot1152 = 0;
    sjs_mat4* sjt_dot1153 = 0;
    sjs_mat4* sjt_dot1154 = 0;
    sjs_mat4* sjt_dot1155 = 0;
    float sjt_math1481;
    float sjt_math1482;
    float sjt_math1483;
    float sjt_math1484;
    float sjt_math1485;
    float sjt_math1486;
    float sjt_math1487;
    float sjt_math1488;
    float sjt_math1489;
    float sjt_math1490;
    float sjt_math1491;
    float sjt_math1492;
    float sjt_math1493;
    float sjt_math1494;
    float sjt_math1495;
    float sjt_math1496;
    float sjt_math1497;
    float sjt_math1498;
    float sjt_math1499;
    float sjt_math1500;
    float sjt_math1501;
    float sjt_math1502;
    float sjt_math1503;
    float sjt_math1504;
    float sjt_math1505;
    float sjt_math1506;
    float sjt_math1507;
    float sjt_math1508;
    float sjt_math1509;
    float sjt_math1510;
    float sjt_math1511;
    float sjt_math1512;
    float sjt_math1513;
    float sjt_math1514;
    float sjt_math1515;
    float sjt_math1516;
    float sjt_math1517;
    float sjt_math1518;
    float sjt_math1519;
    float sjt_math1520;
    float sjt_math1521;
    float sjt_math1522;
    float sjt_math1523;
    float sjt_math1524;
    float sjt_math1525;
    float sjt_math1526;
    float sjt_math1527;
    float sjt_math1528;
    float sjt_math1529;
    float sjt_math1530;
    float sjt_math1531;
    float sjt_math1532;
    float sjt_math1533;
    float sjt_math1534;
    float sjt_math1535;
    float sjt_math1536;
    float sjt_math1537;
    float sjt_math1538;
    float sjt_math1539;
    float sjt_math1540;
    float sjt_math1541;
    float sjt_math1542;
    float sjt_math1543;
    float sjt_math1544;
    float sjt_math1545;
    float sjt_math1546;
    float sjt_math1547;
    float sjt_math1548;
    float sjt_math1549;
    float sjt_math1550;
    float sjt_math1551;
    float sjt_math1552;
    float sjt_math1553;
    float sjt_math1554;
    float sjt_math1555;
    float sjt_math1556;
    float sjt_math1557;
    float sjt_math1558;
    float sjt_math1559;
    float sjt_math1560;
    float sjt_math1561;
    float sjt_math1562;
    float sjt_math1563;
    float sjt_math1564;
    float sjt_math1565;
    float sjt_math1566;
    float sjt_math1567;
    float sjt_math1568;
    float sjt_math1569;
    float sjt_math1570;
    float sjt_math1571;
    float sjt_math1572;
    float sjt_math1573;
    float sjt_math1574;
    float sjt_math1575;
    float sjt_math1576;
    float sjt_math1577;
    float sjt_math1578;
    float sjt_math1579;
    float sjt_math1580;
    float sjt_math1581;
    float sjt_math1582;
    float sjt_math1583;
    float sjt_math1584;
    float sjt_math1585;
    float sjt_math1586;
    float sjt_math1587;
    float sjt_math1588;
    float sjt_math1589;
    float sjt_math1590;
    float sjt_math1591;
    float sjt_math1592;
    float sjt_math1593;
    float sjt_math1594;
    float sjt_math1595;
    float sjt_math1596;
    float sjt_math1597;
    float sjt_math1598;
    float sjt_math1599;
    float sjt_math1600;
    float sjt_math1601;
    float sjt_math1602;
    float sjt_math1603;
    float sjt_math1604;
    float sjt_math1605;
    float sjt_math1606;
    float sjt_math1607;
    float sjt_math1608;
    float sjt_math1609;
    float sjt_math1610;
    float sjt_math1611;
    float sjt_math1612;
    float sjt_math1613;
    float sjt_math1614;
    float sjt_math1615;
    float sjt_math1616;
    float sjt_math1617;
    float sjt_math1618;
    float sjt_math1619;
    float sjt_math1620;
    float sjt_math1621;
    float sjt_math1622;
    float sjt_math1623;
    float sjt_math1624;
    float sjt_math1625;
    float sjt_math1626;
    float sjt_math1627;
    float sjt_math1628;
    float sjt_math1629;
    float sjt_math1630;
    float sjt_math1631;
    float sjt_math1632;
    float sjt_math1633;
    float sjt_math1634;
    float sjt_math1635;
    float sjt_math1636;
    float sjt_math1637;
    float sjt_math1638;
    float sjt_math1639;
    float sjt_math1640;
    float sjt_math1641;
    float sjt_math1642;
    float sjt_math1643;
    float sjt_math1644;
    float sjt_math1645;
    float sjt_math1646;
    float sjt_math1647;
    float sjt_math1648;
    float sjt_math1649;
    float sjt_math1650;
    float sjt_math1651;
    float sjt_math1652;
    float sjt_math1653;
    float sjt_math1654;
    float sjt_math1655;
    float sjt_math1656;
    float sjt_math1657;
    float sjt_math1658;
    float sjt_math1659;
    float sjt_math1660;
    float sjt_math1661;
    float sjt_math1662;
    float sjt_math1663;
    float sjt_math1664;
    float sjt_math1665;
    float sjt_math1666;
    float sjt_math1667;
    float sjt_math1668;
    float sjt_math1669;
    float sjt_math1670;

    sjt_dot1060 = _parent;
    sjt_math1531 = sjt_dot1060->m03;
    sjt_dot1061 = _parent;
    sjt_math1532 = sjt_dot1061->m12;
    sjt_math1529 = sjt_math1531 * sjt_math1532;
    sjt_dot1062 = _parent;
    sjt_math1530 = sjt_dot1062->m21;
    sjt_math1527 = sjt_math1529 * sjt_math1530;
    sjt_dot1063 = _parent;
    sjt_math1528 = sjt_dot1063->m30;
    sjt_math1525 = sjt_math1527 * sjt_math1528;
    sjt_dot1064 = _parent;
    sjt_math1537 = sjt_dot1064->m02;
    sjt_dot1065 = _parent;
    sjt_math1538 = sjt_dot1065->m13;
    sjt_math1535 = sjt_math1537 * sjt_math1538;
    sjt_dot1066 = _parent;
    sjt_math1536 = sjt_dot1066->m21;
    sjt_math1533 = sjt_math1535 * sjt_math1536;
    sjt_dot1067 = _parent;
    sjt_math1534 = sjt_dot1067->m30;
    sjt_math1526 = sjt_math1533 * sjt_math1534;
    sjt_math1523 = sjt_math1525 - sjt_math1526;
    sjt_dot1068 = _parent;
    sjt_math1543 = sjt_dot1068->m03;
    sjt_dot1069 = _parent;
    sjt_math1544 = sjt_dot1069->m11;
    sjt_math1541 = sjt_math1543 * sjt_math1544;
    sjt_dot1070 = _parent;
    sjt_math1542 = sjt_dot1070->m22;
    sjt_math1539 = sjt_math1541 * sjt_math1542;
    sjt_dot1071 = _parent;
    sjt_math1540 = sjt_dot1071->m30;
    sjt_math1524 = sjt_math1539 * sjt_math1540;
    sjt_math1521 = sjt_math1523 - sjt_math1524;
    sjt_dot1072 = _parent;
    sjt_math1549 = sjt_dot1072->m01;
    sjt_dot1073 = _parent;
    sjt_math1550 = sjt_dot1073->m13;
    sjt_math1547 = sjt_math1549 * sjt_math1550;
    sjt_dot1074 = _parent;
    sjt_math1548 = sjt_dot1074->m22;
    sjt_math1545 = sjt_math1547 * sjt_math1548;
    sjt_dot1075 = _parent;
    sjt_math1546 = sjt_dot1075->m30;
    sjt_math1522 = sjt_math1545 * sjt_math1546;
    sjt_math1519 = sjt_math1521 + sjt_math1522;
    sjt_dot1076 = _parent;
    sjt_math1555 = sjt_dot1076->m02;
    sjt_dot1077 = _parent;
    sjt_math1556 = sjt_dot1077->m11;
    sjt_math1553 = sjt_math1555 * sjt_math1556;
    sjt_dot1078 = _parent;
    sjt_math1554 = sjt_dot1078->m23;
    sjt_math1551 = sjt_math1553 * sjt_math1554;
    sjt_dot1079 = _parent;
    sjt_math1552 = sjt_dot1079->m30;
    sjt_math1520 = sjt_math1551 * sjt_math1552;
    sjt_math1517 = sjt_math1519 + sjt_math1520;
    sjt_dot1080 = _parent;
    sjt_math1561 = sjt_dot1080->m01;
    sjt_dot1081 = _parent;
    sjt_math1562 = sjt_dot1081->m12;
    sjt_math1559 = sjt_math1561 * sjt_math1562;
    sjt_dot1082 = _parent;
    sjt_math1560 = sjt_dot1082->m23;
    sjt_math1557 = sjt_math1559 * sjt_math1560;
    sjt_dot1083 = _parent;
    sjt_math1558 = sjt_dot1083->m30;
    sjt_math1518 = sjt_math1557 * sjt_math1558;
    sjt_math1515 = sjt_math1517 - sjt_math1518;
    sjt_dot1084 = _parent;
    sjt_math1567 = sjt_dot1084->m03;
    sjt_dot1085 = _parent;
    sjt_math1568 = sjt_dot1085->m12;
    sjt_math1565 = sjt_math1567 * sjt_math1568;
    sjt_dot1086 = _parent;
    sjt_math1566 = sjt_dot1086->m20;
    sjt_math1563 = sjt_math1565 * sjt_math1566;
    sjt_dot1087 = _parent;
    sjt_math1564 = sjt_dot1087->m31;
    sjt_math1516 = sjt_math1563 * sjt_math1564;
    sjt_math1513 = sjt_math1515 - sjt_math1516;
    sjt_dot1088 = _parent;
    sjt_math1573 = sjt_dot1088->m02;
    sjt_dot1089 = _parent;
    sjt_math1574 = sjt_dot1089->m13;
    sjt_math1571 = sjt_math1573 * sjt_math1574;
    sjt_dot1090 = _parent;
    sjt_math1572 = sjt_dot1090->m20;
    sjt_math1569 = sjt_math1571 * sjt_math1572;
    sjt_dot1091 = _parent;
    sjt_math1570 = sjt_dot1091->m31;
    sjt_math1514 = sjt_math1569 * sjt_math1570;
    sjt_math1511 = sjt_math1513 + sjt_math1514;
    sjt_dot1092 = _parent;
    sjt_math1579 = sjt_dot1092->m03;
    sjt_dot1093 = _parent;
    sjt_math1580 = sjt_dot1093->m10;
    sjt_math1577 = sjt_math1579 * sjt_math1580;
    sjt_dot1094 = _parent;
    sjt_math1578 = sjt_dot1094->m22;
    sjt_math1575 = sjt_math1577 * sjt_math1578;
    sjt_dot1095 = _parent;
    sjt_math1576 = sjt_dot1095->m31;
    sjt_math1512 = sjt_math1575 * sjt_math1576;
    sjt_math1509 = sjt_math1511 + sjt_math1512;
    sjt_dot1096 = _parent;
    sjt_math1585 = sjt_dot1096->m00;
    sjt_dot1097 = _parent;
    sjt_math1586 = sjt_dot1097->m13;
    sjt_math1583 = sjt_math1585 * sjt_math1586;
    sjt_dot1098 = _parent;
    sjt_math1584 = sjt_dot1098->m22;
    sjt_math1581 = sjt_math1583 * sjt_math1584;
    sjt_dot1099 = _parent;
    sjt_math1582 = sjt_dot1099->m31;
    sjt_math1510 = sjt_math1581 * sjt_math1582;
    sjt_math1507 = sjt_math1509 - sjt_math1510;
    sjt_dot1100 = _parent;
    sjt_math1591 = sjt_dot1100->m02;
    sjt_dot1101 = _parent;
    sjt_math1592 = sjt_dot1101->m10;
    sjt_math1589 = sjt_math1591 * sjt_math1592;
    sjt_dot1102 = _parent;
    sjt_math1590 = sjt_dot1102->m23;
    sjt_math1587 = sjt_math1589 * sjt_math1590;
    sjt_dot1103 = _parent;
    sjt_math1588 = sjt_dot1103->m31;
    sjt_math1508 = sjt_math1587 * sjt_math1588;
    sjt_math1505 = sjt_math1507 - sjt_math1508;
    sjt_dot1104 = _parent;
    sjt_math1597 = sjt_dot1104->m00;
    sjt_dot1105 = _parent;
    sjt_math1598 = sjt_dot1105->m12;
    sjt_math1595 = sjt_math1597 * sjt_math1598;
    sjt_dot1106 = _parent;
    sjt_math1596 = sjt_dot1106->m23;
    sjt_math1593 = sjt_math1595 * sjt_math1596;
    sjt_dot1107 = _parent;
    sjt_math1594 = sjt_dot1107->m31;
    sjt_math1506 = sjt_math1593 * sjt_math1594;
    sjt_math1503 = sjt_math1505 + sjt_math1506;
    sjt_dot1108 = _parent;
    sjt_math1603 = sjt_dot1108->m03;
    sjt_dot1109 = _parent;
    sjt_math1604 = sjt_dot1109->m11;
    sjt_math1601 = sjt_math1603 * sjt_math1604;
    sjt_dot1110 = _parent;
    sjt_math1602 = sjt_dot1110->m20;
    sjt_math1599 = sjt_math1601 * sjt_math1602;
    sjt_dot1111 = _parent;
    sjt_math1600 = sjt_dot1111->m32;
    sjt_math1504 = sjt_math1599 * sjt_math1600;
    sjt_math1501 = sjt_math1503 + sjt_math1504;
    sjt_dot1112 = _parent;
    sjt_math1609 = sjt_dot1112->m01;
    sjt_dot1113 = _parent;
    sjt_math1610 = sjt_dot1113->m13;
    sjt_math1607 = sjt_math1609 * sjt_math1610;
    sjt_dot1114 = _parent;
    sjt_math1608 = sjt_dot1114->m20;
    sjt_math1605 = sjt_math1607 * sjt_math1608;
    sjt_dot1115 = _parent;
    sjt_math1606 = sjt_dot1115->m32;
    sjt_math1502 = sjt_math1605 * sjt_math1606;
    sjt_math1499 = sjt_math1501 - sjt_math1502;
    sjt_dot1116 = _parent;
    sjt_math1615 = sjt_dot1116->m03;
    sjt_dot1117 = _parent;
    sjt_math1616 = sjt_dot1117->m10;
    sjt_math1613 = sjt_math1615 * sjt_math1616;
    sjt_dot1118 = _parent;
    sjt_math1614 = sjt_dot1118->m21;
    sjt_math1611 = sjt_math1613 * sjt_math1614;
    sjt_dot1119 = _parent;
    sjt_math1612 = sjt_dot1119->m32;
    sjt_math1500 = sjt_math1611 * sjt_math1612;
    sjt_math1497 = sjt_math1499 - sjt_math1500;
    sjt_dot1120 = _parent;
    sjt_math1621 = sjt_dot1120->m00;
    sjt_dot1121 = _parent;
    sjt_math1622 = sjt_dot1121->m13;
    sjt_math1619 = sjt_math1621 * sjt_math1622;
    sjt_dot1122 = _parent;
    sjt_math1620 = sjt_dot1122->m21;
    sjt_math1617 = sjt_math1619 * sjt_math1620;
    sjt_dot1123 = _parent;
    sjt_math1618 = sjt_dot1123->m32;
    sjt_math1498 = sjt_math1617 * sjt_math1618;
    sjt_math1495 = sjt_math1497 + sjt_math1498;
    sjt_dot1124 = _parent;
    sjt_math1627 = sjt_dot1124->m01;
    sjt_dot1125 = _parent;
    sjt_math1628 = sjt_dot1125->m10;
    sjt_math1625 = sjt_math1627 * sjt_math1628;
    sjt_dot1126 = _parent;
    sjt_math1626 = sjt_dot1126->m23;
    sjt_math1623 = sjt_math1625 * sjt_math1626;
    sjt_dot1127 = _parent;
    sjt_math1624 = sjt_dot1127->m32;
    sjt_math1496 = sjt_math1623 * sjt_math1624;
    sjt_math1493 = sjt_math1495 + sjt_math1496;
    sjt_dot1128 = _parent;
    sjt_math1633 = sjt_dot1128->m00;
    sjt_dot1129 = _parent;
    sjt_math1634 = sjt_dot1129->m11;
    sjt_math1631 = sjt_math1633 * sjt_math1634;
    sjt_dot1130 = _parent;
    sjt_math1632 = sjt_dot1130->m23;
    sjt_math1629 = sjt_math1631 * sjt_math1632;
    sjt_dot1131 = _parent;
    sjt_math1630 = sjt_dot1131->m32;
    sjt_math1494 = sjt_math1629 * sjt_math1630;
    sjt_math1491 = sjt_math1493 - sjt_math1494;
    sjt_dot1132 = _parent;
    sjt_math1639 = sjt_dot1132->m02;
    sjt_dot1133 = _parent;
    sjt_math1640 = sjt_dot1133->m11;
    sjt_math1637 = sjt_math1639 * sjt_math1640;
    sjt_dot1134 = _parent;
    sjt_math1638 = sjt_dot1134->m20;
    sjt_math1635 = sjt_math1637 * sjt_math1638;
    sjt_dot1135 = _parent;
    sjt_math1636 = sjt_dot1135->m33;
    sjt_math1492 = sjt_math1635 * sjt_math1636;
    sjt_math1489 = sjt_math1491 - sjt_math1492;
    sjt_dot1136 = _parent;
    sjt_math1645 = sjt_dot1136->m01;
    sjt_dot1137 = _parent;
    sjt_math1646 = sjt_dot1137->m12;
    sjt_math1643 = sjt_math1645 * sjt_math1646;
    sjt_dot1138 = _parent;
    sjt_math1644 = sjt_dot1138->m20;
    sjt_math1641 = sjt_math1643 * sjt_math1644;
    sjt_dot1139 = _parent;
    sjt_math1642 = sjt_dot1139->m33;
    sjt_math1490 = sjt_math1641 * sjt_math1642;
    sjt_math1487 = sjt_math1489 + sjt_math1490;
    sjt_dot1140 = _parent;
    sjt_math1651 = sjt_dot1140->m02;
    sjt_dot1141 = _parent;
    sjt_math1652 = sjt_dot1141->m10;
    sjt_math1649 = sjt_math1651 * sjt_math1652;
    sjt_dot1142 = _parent;
    sjt_math1650 = sjt_dot1142->m21;
    sjt_math1647 = sjt_math1649 * sjt_math1650;
    sjt_dot1143 = _parent;
    sjt_math1648 = sjt_dot1143->m33;
    sjt_math1488 = sjt_math1647 * sjt_math1648;
    sjt_math1485 = sjt_math1487 + sjt_math1488;
    sjt_dot1144 = _parent;
    sjt_math1657 = sjt_dot1144->m00;
    sjt_dot1145 = _parent;
    sjt_math1658 = sjt_dot1145->m12;
    sjt_math1655 = sjt_math1657 * sjt_math1658;
    sjt_dot1146 = _parent;
    sjt_math1656 = sjt_dot1146->m21;
    sjt_math1653 = sjt_math1655 * sjt_math1656;
    sjt_dot1147 = _parent;
    sjt_math1654 = sjt_dot1147->m33;
    sjt_math1486 = sjt_math1653 * sjt_math1654;
    sjt_math1483 = sjt_math1485 - sjt_math1486;
    sjt_dot1148 = _parent;
    sjt_math1663 = sjt_dot1148->m01;
    sjt_dot1149 = _parent;
    sjt_math1664 = sjt_dot1149->m10;
    sjt_math1661 = sjt_math1663 * sjt_math1664;
    sjt_dot1150 = _parent;
    sjt_math1662 = sjt_dot1150->m22;
    sjt_math1659 = sjt_math1661 * sjt_math1662;
    sjt_dot1151 = _parent;
    sjt_math1660 = sjt_dot1151->m33;
    sjt_math1484 = sjt_math1659 * sjt_math1660;
    sjt_math1481 = sjt_math1483 - sjt_math1484;
    sjt_dot1152 = _parent;
    sjt_math1669 = sjt_dot1152->m00;
    sjt_dot1153 = _parent;
    sjt_math1670 = sjt_dot1153->m11;
    sjt_math1667 = sjt_math1669 * sjt_math1670;
    sjt_dot1154 = _parent;
    sjt_math1668 = sjt_dot1154->m22;
    sjt_math1665 = sjt_math1667 * sjt_math1668;
    sjt_dot1155 = _parent;
    sjt_math1666 = sjt_dot1155->m33;
    sjt_math1482 = sjt_math1665 * sjt_math1666;
    (*_return) = sjt_math1481 + sjt_math1482;
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

void sjf_mat4_invert(sjs_mat4* _parent, sjs_mat4* _return) {
    sjs_mat4* sjt_dot1000 = 0;
    sjs_mat4* sjt_dot1001 = 0;
    sjs_mat4* sjt_dot1002 = 0;
    sjs_mat4* sjt_dot1003 = 0;
    sjs_mat4* sjt_dot1004 = 0;
    sjs_mat4* sjt_dot1005 = 0;
    sjs_mat4* sjt_dot1006 = 0;
    sjs_mat4* sjt_dot1007 = 0;
    sjs_mat4* sjt_dot1008 = 0;
    sjs_mat4* sjt_dot1009 = 0;
    sjs_mat4* sjt_dot1010 = 0;
    sjs_mat4* sjt_dot1011 = 0;
    sjs_mat4* sjt_dot1012 = 0;
    sjs_mat4* sjt_dot1013 = 0;
    sjs_mat4* sjt_dot1014 = 0;
    sjs_mat4* sjt_dot1015 = 0;
    sjs_mat4* sjt_dot1016 = 0;
    sjs_mat4* sjt_dot1017 = 0;
    sjs_mat4* sjt_dot1018 = 0;
    sjs_mat4* sjt_dot1019 = 0;
    sjs_mat4* sjt_dot1020 = 0;
    sjs_mat4* sjt_dot1021 = 0;
    sjs_mat4* sjt_dot1022 = 0;
    sjs_mat4* sjt_dot1023 = 0;
    sjs_mat4* sjt_dot1024 = 0;
    sjs_mat4* sjt_dot1025 = 0;
    sjs_mat4* sjt_dot1026 = 0;
    sjs_mat4* sjt_dot1027 = 0;
    sjs_mat4* sjt_dot740 = 0;
    sjs_mat4* sjt_dot741 = 0;
    sjs_mat4* sjt_dot742 = 0;
    sjs_mat4* sjt_dot743 = 0;
    sjs_mat4* sjt_dot744 = 0;
    sjs_mat4* sjt_dot745 = 0;
    sjs_mat4* sjt_dot746 = 0;
    sjs_mat4* sjt_dot747 = 0;
    sjs_mat4* sjt_dot748 = 0;
    sjs_mat4* sjt_dot749 = 0;
    sjs_mat4* sjt_dot750 = 0;
    sjs_mat4* sjt_dot751 = 0;
    sjs_mat4* sjt_dot752 = 0;
    sjs_mat4* sjt_dot753 = 0;
    sjs_mat4* sjt_dot754 = 0;
    sjs_mat4* sjt_dot755 = 0;
    sjs_mat4* sjt_dot756 = 0;
    sjs_mat4* sjt_dot757 = 0;
    sjs_mat4* sjt_dot758 = 0;
    sjs_mat4* sjt_dot759 = 0;
    sjs_mat4* sjt_dot760 = 0;
    sjs_mat4* sjt_dot761 = 0;
    sjs_mat4* sjt_dot762 = 0;
    sjs_mat4* sjt_dot763 = 0;
    sjs_mat4* sjt_dot764 = 0;
    sjs_mat4* sjt_dot765 = 0;
    sjs_mat4* sjt_dot766 = 0;
    sjs_mat4* sjt_dot767 = 0;
    sjs_mat4* sjt_dot768 = 0;
    sjs_mat4* sjt_dot769 = 0;
    sjs_mat4* sjt_dot770 = 0;
    sjs_mat4* sjt_dot771 = 0;
    sjs_mat4* sjt_dot772 = 0;
    sjs_mat4* sjt_dot773 = 0;
    sjs_mat4* sjt_dot774 = 0;
    sjs_mat4* sjt_dot775 = 0;
    sjs_mat4* sjt_dot776 = 0;
    sjs_mat4* sjt_dot777 = 0;
    sjs_mat4* sjt_dot778 = 0;
    sjs_mat4* sjt_dot779 = 0;
    sjs_mat4* sjt_dot780 = 0;
    sjs_mat4* sjt_dot781 = 0;
    sjs_mat4* sjt_dot782 = 0;
    sjs_mat4* sjt_dot783 = 0;
    sjs_mat4* sjt_dot784 = 0;
    sjs_mat4* sjt_dot785 = 0;
    sjs_mat4* sjt_dot786 = 0;
    sjs_mat4* sjt_dot787 = 0;
    sjs_mat4* sjt_dot788 = 0;
    sjs_mat4* sjt_dot789 = 0;
    sjs_mat4* sjt_dot790 = 0;
    sjs_mat4* sjt_dot791 = 0;
    sjs_mat4* sjt_dot792 = 0;
    sjs_mat4* sjt_dot793 = 0;
    sjs_mat4* sjt_dot794 = 0;
    sjs_mat4* sjt_dot795 = 0;
    sjs_mat4* sjt_dot796 = 0;
    sjs_mat4* sjt_dot797 = 0;
    sjs_mat4* sjt_dot798 = 0;
    sjs_mat4* sjt_dot799 = 0;
    sjs_mat4* sjt_dot800 = 0;
    sjs_mat4* sjt_dot801 = 0;
    sjs_mat4* sjt_dot802 = 0;
    sjs_mat4* sjt_dot803 = 0;
    sjs_mat4* sjt_dot804 = 0;
    sjs_mat4* sjt_dot805 = 0;
    sjs_mat4* sjt_dot806 = 0;
    sjs_mat4* sjt_dot807 = 0;
    sjs_mat4* sjt_dot808 = 0;
    sjs_mat4* sjt_dot809 = 0;
    sjs_mat4* sjt_dot810 = 0;
    sjs_mat4* sjt_dot811 = 0;
    sjs_mat4* sjt_dot812 = 0;
    sjs_mat4* sjt_dot813 = 0;
    sjs_mat4* sjt_dot814 = 0;
    sjs_mat4* sjt_dot815 = 0;
    sjs_mat4* sjt_dot816 = 0;
    sjs_mat4* sjt_dot817 = 0;
    sjs_mat4* sjt_dot818 = 0;
    sjs_mat4* sjt_dot819 = 0;
    sjs_mat4* sjt_dot820 = 0;
    sjs_mat4* sjt_dot821 = 0;
    sjs_mat4* sjt_dot822 = 0;
    sjs_mat4* sjt_dot823 = 0;
    sjs_mat4* sjt_dot824 = 0;
    sjs_mat4* sjt_dot825 = 0;
    sjs_mat4* sjt_dot826 = 0;
    sjs_mat4* sjt_dot827 = 0;
    sjs_mat4* sjt_dot828 = 0;
    sjs_mat4* sjt_dot829 = 0;
    sjs_mat4* sjt_dot830 = 0;
    sjs_mat4* sjt_dot831 = 0;
    sjs_mat4* sjt_dot832 = 0;
    sjs_mat4* sjt_dot833 = 0;
    sjs_mat4* sjt_dot834 = 0;
    sjs_mat4* sjt_dot835 = 0;
    sjs_mat4* sjt_dot836 = 0;
    sjs_mat4* sjt_dot837 = 0;
    sjs_mat4* sjt_dot838 = 0;
    sjs_mat4* sjt_dot839 = 0;
    sjs_mat4* sjt_dot840 = 0;
    sjs_mat4* sjt_dot841 = 0;
    sjs_mat4* sjt_dot842 = 0;
    sjs_mat4* sjt_dot843 = 0;
    sjs_mat4* sjt_dot844 = 0;
    sjs_mat4* sjt_dot845 = 0;
    sjs_mat4* sjt_dot846 = 0;
    sjs_mat4* sjt_dot847 = 0;
    sjs_mat4* sjt_dot848 = 0;
    sjs_mat4* sjt_dot849 = 0;
    sjs_mat4* sjt_dot850 = 0;
    sjs_mat4* sjt_dot851 = 0;
    sjs_mat4* sjt_dot852 = 0;
    sjs_mat4* sjt_dot853 = 0;
    sjs_mat4* sjt_dot854 = 0;
    sjs_mat4* sjt_dot855 = 0;
    sjs_mat4* sjt_dot856 = 0;
    sjs_mat4* sjt_dot857 = 0;
    sjs_mat4* sjt_dot858 = 0;
    sjs_mat4* sjt_dot859 = 0;
    sjs_mat4* sjt_dot860 = 0;
    sjs_mat4* sjt_dot861 = 0;
    sjs_mat4* sjt_dot862 = 0;
    sjs_mat4* sjt_dot863 = 0;
    sjs_mat4* sjt_dot864 = 0;
    sjs_mat4* sjt_dot865 = 0;
    sjs_mat4* sjt_dot866 = 0;
    sjs_mat4* sjt_dot867 = 0;
    sjs_mat4* sjt_dot868 = 0;
    sjs_mat4* sjt_dot869 = 0;
    sjs_mat4* sjt_dot870 = 0;
    sjs_mat4* sjt_dot871 = 0;
    sjs_mat4* sjt_dot872 = 0;
    sjs_mat4* sjt_dot873 = 0;
    sjs_mat4* sjt_dot874 = 0;
    sjs_mat4* sjt_dot875 = 0;
    sjs_mat4* sjt_dot876 = 0;
    sjs_mat4* sjt_dot877 = 0;
    sjs_mat4* sjt_dot878 = 0;
    sjs_mat4* sjt_dot879 = 0;
    sjs_mat4* sjt_dot880 = 0;
    sjs_mat4* sjt_dot881 = 0;
    sjs_mat4* sjt_dot882 = 0;
    sjs_mat4* sjt_dot883 = 0;
    sjs_mat4* sjt_dot884 = 0;
    sjs_mat4* sjt_dot885 = 0;
    sjs_mat4* sjt_dot886 = 0;
    sjs_mat4* sjt_dot887 = 0;
    sjs_mat4* sjt_dot888 = 0;
    sjs_mat4* sjt_dot889 = 0;
    sjs_mat4* sjt_dot890 = 0;
    sjs_mat4* sjt_dot891 = 0;
    sjs_mat4* sjt_dot892 = 0;
    sjs_mat4* sjt_dot893 = 0;
    sjs_mat4* sjt_dot894 = 0;
    sjs_mat4* sjt_dot895 = 0;
    sjs_mat4* sjt_dot896 = 0;
    sjs_mat4* sjt_dot897 = 0;
    sjs_mat4* sjt_dot898 = 0;
    sjs_mat4* sjt_dot899 = 0;
    sjs_mat4* sjt_dot900 = 0;
    sjs_mat4* sjt_dot901 = 0;
    sjs_mat4* sjt_dot902 = 0;
    sjs_mat4* sjt_dot903 = 0;
    sjs_mat4* sjt_dot904 = 0;
    sjs_mat4* sjt_dot905 = 0;
    sjs_mat4* sjt_dot906 = 0;
    sjs_mat4* sjt_dot907 = 0;
    sjs_mat4* sjt_dot908 = 0;
    sjs_mat4* sjt_dot909 = 0;
    sjs_mat4* sjt_dot910 = 0;
    sjs_mat4* sjt_dot911 = 0;
    sjs_mat4* sjt_dot912 = 0;
    sjs_mat4* sjt_dot913 = 0;
    sjs_mat4* sjt_dot914 = 0;
    sjs_mat4* sjt_dot915 = 0;
    sjs_mat4* sjt_dot916 = 0;
    sjs_mat4* sjt_dot917 = 0;
    sjs_mat4* sjt_dot918 = 0;
    sjs_mat4* sjt_dot919 = 0;
    sjs_mat4* sjt_dot920 = 0;
    sjs_mat4* sjt_dot921 = 0;
    sjs_mat4* sjt_dot922 = 0;
    sjs_mat4* sjt_dot923 = 0;
    sjs_mat4* sjt_dot924 = 0;
    sjs_mat4* sjt_dot925 = 0;
    sjs_mat4* sjt_dot926 = 0;
    sjs_mat4* sjt_dot927 = 0;
    sjs_mat4* sjt_dot928 = 0;
    sjs_mat4* sjt_dot929 = 0;
    sjs_mat4* sjt_dot930 = 0;
    sjs_mat4* sjt_dot931 = 0;
    sjs_mat4* sjt_dot932 = 0;
    sjs_mat4* sjt_dot933 = 0;
    sjs_mat4* sjt_dot934 = 0;
    sjs_mat4* sjt_dot935 = 0;
    sjs_mat4* sjt_dot936 = 0;
    sjs_mat4* sjt_dot937 = 0;
    sjs_mat4* sjt_dot938 = 0;
    sjs_mat4* sjt_dot939 = 0;
    sjs_mat4* sjt_dot940 = 0;
    sjs_mat4* sjt_dot941 = 0;
    sjs_mat4* sjt_dot942 = 0;
    sjs_mat4* sjt_dot943 = 0;
    sjs_mat4* sjt_dot944 = 0;
    sjs_mat4* sjt_dot945 = 0;
    sjs_mat4* sjt_dot946 = 0;
    sjs_mat4* sjt_dot947 = 0;
    sjs_mat4* sjt_dot948 = 0;
    sjs_mat4* sjt_dot949 = 0;
    sjs_mat4* sjt_dot950 = 0;
    sjs_mat4* sjt_dot951 = 0;
    sjs_mat4* sjt_dot952 = 0;
    sjs_mat4* sjt_dot953 = 0;
    sjs_mat4* sjt_dot954 = 0;
    sjs_mat4* sjt_dot955 = 0;
    sjs_mat4* sjt_dot956 = 0;
    sjs_mat4* sjt_dot957 = 0;
    sjs_mat4* sjt_dot958 = 0;
    sjs_mat4* sjt_dot959 = 0;
    sjs_mat4* sjt_dot960 = 0;
    sjs_mat4* sjt_dot961 = 0;
    sjs_mat4* sjt_dot962 = 0;
    sjs_mat4* sjt_dot963 = 0;
    sjs_mat4* sjt_dot964 = 0;
    sjs_mat4* sjt_dot965 = 0;
    sjs_mat4* sjt_dot966 = 0;
    sjs_mat4* sjt_dot967 = 0;
    sjs_mat4* sjt_dot968 = 0;
    sjs_mat4* sjt_dot969 = 0;
    sjs_mat4* sjt_dot970 = 0;
    sjs_mat4* sjt_dot971 = 0;
    sjs_mat4* sjt_dot972 = 0;
    sjs_mat4* sjt_dot973 = 0;
    sjs_mat4* sjt_dot974 = 0;
    sjs_mat4* sjt_dot975 = 0;
    sjs_mat4* sjt_dot976 = 0;
    sjs_mat4* sjt_dot977 = 0;
    sjs_mat4* sjt_dot978 = 0;
    sjs_mat4* sjt_dot979 = 0;
    sjs_mat4* sjt_dot980 = 0;
    sjs_mat4* sjt_dot981 = 0;
    sjs_mat4* sjt_dot982 = 0;
    sjs_mat4* sjt_dot983 = 0;
    sjs_mat4* sjt_dot984 = 0;
    sjs_mat4* sjt_dot985 = 0;
    sjs_mat4* sjt_dot986 = 0;
    sjs_mat4* sjt_dot987 = 0;
    sjs_mat4* sjt_dot988 = 0;
    sjs_mat4* sjt_dot989 = 0;
    sjs_mat4* sjt_dot990 = 0;
    sjs_mat4* sjt_dot991 = 0;
    sjs_mat4* sjt_dot992 = 0;
    sjs_mat4* sjt_dot993 = 0;
    sjs_mat4* sjt_dot994 = 0;
    sjs_mat4* sjt_dot995 = 0;
    sjs_mat4* sjt_dot996 = 0;
    sjs_mat4* sjt_dot997 = 0;
    sjs_mat4* sjt_dot998 = 0;
    sjs_mat4* sjt_dot999 = 0;
    float sjt_functionParam161;
    float sjt_math1000;
    float sjt_math1001;
    float sjt_math1002;
    float sjt_math1003;
    float sjt_math1004;
    float sjt_math1005;
    float sjt_math1006;
    float sjt_math1007;
    float sjt_math1008;
    float sjt_math1009;
    float sjt_math1010;
    float sjt_math1011;
    float sjt_math1012;
    float sjt_math1013;
    float sjt_math1014;
    float sjt_math1015;
    float sjt_math1016;
    float sjt_math1017;
    float sjt_math1018;
    float sjt_math1019;
    float sjt_math1020;
    float sjt_math1021;
    float sjt_math1022;
    float sjt_math1023;
    float sjt_math1024;
    float sjt_math1025;
    float sjt_math1026;
    float sjt_math1027;
    float sjt_math1028;
    float sjt_math1029;
    float sjt_math1030;
    float sjt_math1031;
    float sjt_math1032;
    float sjt_math1033;
    float sjt_math1034;
    float sjt_math1035;
    float sjt_math1036;
    float sjt_math1037;
    float sjt_math1038;
    float sjt_math1039;
    float sjt_math1040;
    float sjt_math1041;
    float sjt_math1042;
    float sjt_math1043;
    float sjt_math1044;
    float sjt_math1045;
    float sjt_math1046;
    float sjt_math1047;
    float sjt_math1048;
    float sjt_math1049;
    float sjt_math1050;
    float sjt_math1051;
    float sjt_math1052;
    float sjt_math1053;
    float sjt_math1054;
    float sjt_math1055;
    float sjt_math1056;
    float sjt_math1057;
    float sjt_math1058;
    float sjt_math1059;
    float sjt_math1060;
    float sjt_math1061;
    float sjt_math1062;
    float sjt_math1063;
    float sjt_math1064;
    float sjt_math1065;
    float sjt_math1066;
    float sjt_math1067;
    float sjt_math1068;
    float sjt_math1069;
    float sjt_math1070;
    float sjt_math1071;
    float sjt_math1072;
    float sjt_math1073;
    float sjt_math1074;
    float sjt_math1075;
    float sjt_math1076;
    float sjt_math1077;
    float sjt_math1078;
    float sjt_math1079;
    float sjt_math1080;
    float sjt_math1081;
    float sjt_math1082;
    float sjt_math1083;
    float sjt_math1084;
    float sjt_math1085;
    float sjt_math1086;
    float sjt_math1087;
    float sjt_math1088;
    float sjt_math1089;
    float sjt_math1090;
    float sjt_math1091;
    float sjt_math1092;
    float sjt_math1093;
    float sjt_math1094;
    float sjt_math1095;
    float sjt_math1096;
    float sjt_math1097;
    float sjt_math1098;
    float sjt_math1099;
    float sjt_math1100;
    float sjt_math1101;
    float sjt_math1102;
    float sjt_math1103;
    float sjt_math1104;
    float sjt_math1105;
    float sjt_math1106;
    float sjt_math1107;
    float sjt_math1108;
    float sjt_math1109;
    float sjt_math1110;
    float sjt_math1111;
    float sjt_math1112;
    float sjt_math1113;
    float sjt_math1114;
    float sjt_math1115;
    float sjt_math1116;
    float sjt_math1117;
    float sjt_math1118;
    float sjt_math1119;
    float sjt_math1120;
    float sjt_math1121;
    float sjt_math1122;
    float sjt_math1123;
    float sjt_math1124;
    float sjt_math1125;
    float sjt_math1126;
    float sjt_math1127;
    float sjt_math1128;
    float sjt_math1129;
    float sjt_math1130;
    float sjt_math1131;
    float sjt_math1132;
    float sjt_math1133;
    float sjt_math1134;
    float sjt_math1135;
    float sjt_math1136;
    float sjt_math1137;
    float sjt_math1138;
    float sjt_math1139;
    float sjt_math1140;
    float sjt_math1141;
    float sjt_math1142;
    float sjt_math1143;
    float sjt_math1144;
    float sjt_math1145;
    float sjt_math1146;
    float sjt_math1147;
    float sjt_math1148;
    float sjt_math1149;
    float sjt_math1150;
    float sjt_math1151;
    float sjt_math1152;
    float sjt_math1153;
    float sjt_math1154;
    float sjt_math1155;
    float sjt_math1156;
    float sjt_math1157;
    float sjt_math1158;
    float sjt_math1159;
    float sjt_math1160;
    float sjt_math1161;
    float sjt_math1162;
    float sjt_math1163;
    float sjt_math1164;
    float sjt_math1165;
    float sjt_math1166;
    float sjt_math1167;
    float sjt_math1168;
    float sjt_math1169;
    float sjt_math1170;
    float sjt_math1171;
    float sjt_math1172;
    float sjt_math1173;
    float sjt_math1174;
    float sjt_math1175;
    float sjt_math1176;
    float sjt_math1177;
    float sjt_math1178;
    float sjt_math1179;
    float sjt_math1180;
    float sjt_math1181;
    float sjt_math1182;
    float sjt_math1183;
    float sjt_math1184;
    float sjt_math1185;
    float sjt_math1186;
    float sjt_math1187;
    float sjt_math1188;
    float sjt_math1189;
    float sjt_math1190;
    float sjt_math1191;
    float sjt_math1192;
    float sjt_math1193;
    float sjt_math1194;
    float sjt_math1195;
    float sjt_math1196;
    float sjt_math1197;
    float sjt_math1198;
    float sjt_math1199;
    float sjt_math1200;
    float sjt_math1201;
    float sjt_math1202;
    float sjt_math1203;
    float sjt_math1204;
    float sjt_math1205;
    float sjt_math1206;
    float sjt_math1207;
    float sjt_math1208;
    float sjt_math1209;
    float sjt_math1210;
    float sjt_math1211;
    float sjt_math1212;
    float sjt_math1213;
    float sjt_math1214;
    float sjt_math1215;
    float sjt_math1216;
    float sjt_math1217;
    float sjt_math1218;
    float sjt_math1219;
    float sjt_math1220;
    float sjt_math1221;
    float sjt_math1222;
    float sjt_math1223;
    float sjt_math1224;
    float sjt_math1225;
    float sjt_math1226;
    float sjt_math1227;
    float sjt_math1228;
    float sjt_math1229;
    float sjt_math1230;
    float sjt_math1231;
    float sjt_math1232;
    float sjt_math1233;
    float sjt_math1234;
    float sjt_math1235;
    float sjt_math1236;
    float sjt_math1237;
    float sjt_math1238;
    float sjt_math1239;
    float sjt_math1240;
    float sjt_math1241;
    float sjt_math1242;
    float sjt_math1243;
    float sjt_math1244;
    float sjt_math1245;
    float sjt_math1246;
    float sjt_math1247;
    float sjt_math1248;
    float sjt_math1249;
    float sjt_math1250;
    float sjt_math1251;
    float sjt_math1252;
    float sjt_math1253;
    float sjt_math1254;
    float sjt_math1255;
    float sjt_math1256;
    float sjt_math1257;
    float sjt_math1258;
    float sjt_math1259;
    float sjt_math1260;
    float sjt_math1261;
    float sjt_math1262;
    float sjt_math1263;
    float sjt_math1264;
    float sjt_math1265;
    float sjt_math1266;
    float sjt_math1267;
    float sjt_math1268;
    float sjt_math1269;
    float sjt_math1270;
    float sjt_math1271;
    float sjt_math1272;
    float sjt_math1273;
    float sjt_math1274;
    float sjt_math1275;
    float sjt_math1276;
    float sjt_math1277;
    float sjt_math1278;
    float sjt_math1279;
    float sjt_math1280;
    float sjt_math1281;
    float sjt_math1282;
    float sjt_math1283;
    float sjt_math1284;
    float sjt_math1285;
    float sjt_math1286;
    float sjt_math1287;
    float sjt_math1288;
    float sjt_math1289;
    float sjt_math1290;
    float sjt_math1291;
    float sjt_math1292;
    float sjt_math1293;
    float sjt_math1294;
    float sjt_math1295;
    float sjt_math1296;
    float sjt_math1297;
    float sjt_math1298;
    float sjt_math1299;
    float sjt_math1300;
    float sjt_math1301;
    float sjt_math1302;
    float sjt_math1303;
    float sjt_math1304;
    float sjt_math1305;
    float sjt_math1306;
    float sjt_math1307;
    float sjt_math1308;
    float sjt_math1309;
    float sjt_math1310;
    float sjt_math1311;
    float sjt_math1312;
    float sjt_math1313;
    float sjt_math1314;
    float sjt_math1315;
    float sjt_math1316;
    float sjt_math1317;
    float sjt_math1318;
    float sjt_math1319;
    float sjt_math1320;
    float sjt_math1321;
    float sjt_math1322;
    float sjt_math1323;
    float sjt_math1324;
    float sjt_math1325;
    float sjt_math1326;
    float sjt_math1327;
    float sjt_math1328;
    float sjt_math1329;
    float sjt_math1330;
    float sjt_math1331;
    float sjt_math1332;
    float sjt_math1333;
    float sjt_math1334;
    float sjt_math1335;
    float sjt_math1336;
    float sjt_math1337;
    float sjt_math1338;
    float sjt_math1339;
    float sjt_math1340;
    float sjt_math1341;
    float sjt_math1342;
    float sjt_math1343;
    float sjt_math1344;
    float sjt_math1345;
    float sjt_math1346;
    float sjt_math1347;
    float sjt_math1348;
    float sjt_math1349;
    float sjt_math1350;
    float sjt_math1351;
    float sjt_math1352;
    float sjt_math1353;
    float sjt_math1354;
    float sjt_math1355;
    float sjt_math1356;
    float sjt_math1357;
    float sjt_math1358;
    float sjt_math1359;
    float sjt_math1360;
    float sjt_math1361;
    float sjt_math1362;
    float sjt_math1363;
    float sjt_math1364;
    float sjt_math1365;
    float sjt_math1366;
    float sjt_math1367;
    float sjt_math1368;
    float sjt_math1369;
    float sjt_math1370;
    float sjt_math1371;
    float sjt_math1372;
    float sjt_math1373;
    float sjt_math1374;
    float sjt_math1375;
    float sjt_math1376;
    float sjt_math1377;
    float sjt_math1378;
    float sjt_math1379;
    float sjt_math1380;
    float sjt_math1381;
    float sjt_math1382;
    float sjt_math1383;
    float sjt_math1384;
    float sjt_math1385;
    float sjt_math1386;
    float sjt_math1387;
    float sjt_math1388;
    float sjt_math1389;
    float sjt_math1390;
    float sjt_math1391;
    float sjt_math1392;
    float sjt_math1393;
    float sjt_math1394;
    float sjt_math1395;
    float sjt_math1396;
    float sjt_math1397;
    float sjt_math1398;
    float sjt_math1399;
    float sjt_math1400;
    float sjt_math1401;
    float sjt_math1402;
    float sjt_math1403;
    float sjt_math1404;
    float sjt_math1405;
    float sjt_math1406;
    float sjt_math1407;
    float sjt_math1408;
    float sjt_math1409;
    float sjt_math1410;
    float sjt_math1411;
    float sjt_math1412;
    float sjt_math1413;
    float sjt_math1414;
    float sjt_math1479;
    float sjt_math1480;
    float sjt_math871;
    float sjt_math872;
    float sjt_math873;
    float sjt_math874;
    float sjt_math875;
    float sjt_math876;
    float sjt_math877;
    float sjt_math878;
    float sjt_math879;
    float sjt_math880;
    float sjt_math881;
    float sjt_math882;
    float sjt_math883;
    float sjt_math884;
    float sjt_math885;
    float sjt_math886;
    float sjt_math887;
    float sjt_math888;
    float sjt_math889;
    float sjt_math890;
    float sjt_math891;
    float sjt_math892;
    float sjt_math893;
    float sjt_math894;
    float sjt_math895;
    float sjt_math896;
    float sjt_math897;
    float sjt_math898;
    float sjt_math899;
    float sjt_math900;
    float sjt_math901;
    float sjt_math902;
    float sjt_math903;
    float sjt_math904;
    float sjt_math905;
    float sjt_math906;
    float sjt_math907;
    float sjt_math908;
    float sjt_math909;
    float sjt_math910;
    float sjt_math911;
    float sjt_math912;
    float sjt_math913;
    float sjt_math914;
    float sjt_math915;
    float sjt_math916;
    float sjt_math917;
    float sjt_math918;
    float sjt_math919;
    float sjt_math920;
    float sjt_math921;
    float sjt_math922;
    float sjt_math923;
    float sjt_math924;
    float sjt_math925;
    float sjt_math926;
    float sjt_math927;
    float sjt_math928;
    float sjt_math929;
    float sjt_math930;
    float sjt_math931;
    float sjt_math932;
    float sjt_math933;
    float sjt_math934;
    float sjt_math935;
    float sjt_math936;
    float sjt_math937;
    float sjt_math938;
    float sjt_math939;
    float sjt_math940;
    float sjt_math941;
    float sjt_math942;
    float sjt_math943;
    float sjt_math944;
    float sjt_math945;
    float sjt_math946;
    float sjt_math947;
    float sjt_math948;
    float sjt_math949;
    float sjt_math950;
    float sjt_math951;
    float sjt_math952;
    float sjt_math953;
    float sjt_math954;
    float sjt_math955;
    float sjt_math956;
    float sjt_math957;
    float sjt_math958;
    float sjt_math959;
    float sjt_math960;
    float sjt_math961;
    float sjt_math962;
    float sjt_math963;
    float sjt_math964;
    float sjt_math965;
    float sjt_math966;
    float sjt_math967;
    float sjt_math968;
    float sjt_math969;
    float sjt_math970;
    float sjt_math971;
    float sjt_math972;
    float sjt_math973;
    float sjt_math974;
    float sjt_math975;
    float sjt_math976;
    float sjt_math977;
    float sjt_math978;
    float sjt_math979;
    float sjt_math980;
    float sjt_math981;
    float sjt_math982;
    float sjt_math983;
    float sjt_math984;
    float sjt_math985;
    float sjt_math986;
    float sjt_math987;
    float sjt_math988;
    float sjt_math989;
    float sjt_math990;
    float sjt_math991;
    float sjt_math992;
    float sjt_math993;
    float sjt_math994;
    float sjt_math995;
    float sjt_math996;
    float sjt_math997;
    float sjt_math998;
    float sjt_math999;
    sjs_mat4* sjt_parent110 = 0;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
    sjt_dot740 = _parent;
    sjt_math883 = sjt_dot740->m12;
    sjt_dot741 = _parent;
    sjt_math884 = sjt_dot741->m23;
    sjt_math881 = sjt_math883 * sjt_math884;
    sjt_dot742 = _parent;
    sjt_math882 = sjt_dot742->m31;
    sjt_math879 = sjt_math881 * sjt_math882;
    sjt_dot743 = _parent;
    sjt_math887 = sjt_dot743->m13;
    sjt_dot744 = _parent;
    sjt_math888 = sjt_dot744->m22;
    sjt_math885 = sjt_math887 * sjt_math888;
    sjt_dot745 = _parent;
    sjt_math886 = sjt_dot745->m31;
    sjt_math880 = sjt_math885 * sjt_math886;
    sjt_math877 = sjt_math879 - sjt_math880;
    sjt_dot746 = _parent;
    sjt_math891 = sjt_dot746->m13;
    sjt_dot747 = _parent;
    sjt_math892 = sjt_dot747->m21;
    sjt_math889 = sjt_math891 * sjt_math892;
    sjt_dot748 = _parent;
    sjt_math890 = sjt_dot748->m32;
    sjt_math878 = sjt_math889 * sjt_math890;
    sjt_math875 = sjt_math877 + sjt_math878;
    sjt_dot749 = _parent;
    sjt_math895 = sjt_dot749->m11;
    sjt_dot750 = _parent;
    sjt_math896 = sjt_dot750->m23;
    sjt_math893 = sjt_math895 * sjt_math896;
    sjt_dot751 = _parent;
    sjt_math894 = sjt_dot751->m32;
    sjt_math876 = sjt_math893 * sjt_math894;
    sjt_math873 = sjt_math875 - sjt_math876;
    sjt_dot752 = _parent;
    sjt_math899 = sjt_dot752->m12;
    sjt_dot753 = _parent;
    sjt_math900 = sjt_dot753->m21;
    sjt_math897 = sjt_math899 * sjt_math900;
    sjt_dot754 = _parent;
    sjt_math898 = sjt_dot754->m33;
    sjt_math874 = sjt_math897 * sjt_math898;
    sjt_math871 = sjt_math873 - sjt_math874;
    sjt_dot755 = _parent;
    sjt_math903 = sjt_dot755->m11;
    sjt_dot756 = _parent;
    sjt_math904 = sjt_dot756->m22;
    sjt_math901 = sjt_math903 * sjt_math904;
    sjt_dot757 = _parent;
    sjt_math902 = sjt_dot757->m33;
    sjt_math872 = sjt_math901 * sjt_math902;
    sjv_t.m00 = sjt_math871 + sjt_math872;
    sjt_dot758 = _parent;
    sjt_math917 = sjt_dot758->m03;
    sjt_dot759 = _parent;
    sjt_math918 = sjt_dot759->m22;
    sjt_math915 = sjt_math917 * sjt_math918;
    sjt_dot760 = _parent;
    sjt_math916 = sjt_dot760->m31;
    sjt_math913 = sjt_math915 * sjt_math916;
    sjt_dot761 = _parent;
    sjt_math921 = sjt_dot761->m02;
    sjt_dot762 = _parent;
    sjt_math922 = sjt_dot762->m23;
    sjt_math919 = sjt_math921 * sjt_math922;
    sjt_dot763 = _parent;
    sjt_math920 = sjt_dot763->m31;
    sjt_math914 = sjt_math919 * sjt_math920;
    sjt_math911 = sjt_math913 - sjt_math914;
    sjt_dot764 = _parent;
    sjt_math925 = sjt_dot764->m03;
    sjt_dot765 = _parent;
    sjt_math926 = sjt_dot765->m21;
    sjt_math923 = sjt_math925 * sjt_math926;
    sjt_dot766 = _parent;
    sjt_math924 = sjt_dot766->m32;
    sjt_math912 = sjt_math923 * sjt_math924;
    sjt_math909 = sjt_math911 - sjt_math912;
    sjt_dot767 = _parent;
    sjt_math929 = sjt_dot767->m01;
    sjt_dot768 = _parent;
    sjt_math930 = sjt_dot768->m23;
    sjt_math927 = sjt_math929 * sjt_math930;
    sjt_dot769 = _parent;
    sjt_math928 = sjt_dot769->m32;
    sjt_math910 = sjt_math927 * sjt_math928;
    sjt_math907 = sjt_math909 + sjt_math910;
    sjt_dot770 = _parent;
    sjt_math933 = sjt_dot770->m02;
    sjt_dot771 = _parent;
    sjt_math934 = sjt_dot771->m21;
    sjt_math931 = sjt_math933 * sjt_math934;
    sjt_dot772 = _parent;
    sjt_math932 = sjt_dot772->m33;
    sjt_math908 = sjt_math931 * sjt_math932;
    sjt_math905 = sjt_math907 + sjt_math908;
    sjt_dot773 = _parent;
    sjt_math937 = sjt_dot773->m01;
    sjt_dot774 = _parent;
    sjt_math938 = sjt_dot774->m22;
    sjt_math935 = sjt_math937 * sjt_math938;
    sjt_dot775 = _parent;
    sjt_math936 = sjt_dot775->m33;
    sjt_math906 = sjt_math935 * sjt_math936;
    sjv_t.m01 = sjt_math905 - sjt_math906;
    sjt_dot776 = _parent;
    sjt_math951 = sjt_dot776->m02;
    sjt_dot777 = _parent;
    sjt_math952 = sjt_dot777->m13;
    sjt_math949 = sjt_math951 * sjt_math952;
    sjt_dot778 = _parent;
    sjt_math950 = sjt_dot778->m31;
    sjt_math947 = sjt_math949 * sjt_math950;
    sjt_dot779 = _parent;
    sjt_math955 = sjt_dot779->m03;
    sjt_dot780 = _parent;
    sjt_math956 = sjt_dot780->m12;
    sjt_math953 = sjt_math955 * sjt_math956;
    sjt_dot781 = _parent;
    sjt_math954 = sjt_dot781->m31;
    sjt_math948 = sjt_math953 * sjt_math954;
    sjt_math945 = sjt_math947 - sjt_math948;
    sjt_dot782 = _parent;
    sjt_math959 = sjt_dot782->m03;
    sjt_dot783 = _parent;
    sjt_math960 = sjt_dot783->m11;
    sjt_math957 = sjt_math959 * sjt_math960;
    sjt_dot784 = _parent;
    sjt_math958 = sjt_dot784->m32;
    sjt_math946 = sjt_math957 * sjt_math958;
    sjt_math943 = sjt_math945 + sjt_math946;
    sjt_dot785 = _parent;
    sjt_math963 = sjt_dot785->m01;
    sjt_dot786 = _parent;
    sjt_math964 = sjt_dot786->m13;
    sjt_math961 = sjt_math963 * sjt_math964;
    sjt_dot787 = _parent;
    sjt_math962 = sjt_dot787->m32;
    sjt_math944 = sjt_math961 * sjt_math962;
    sjt_math941 = sjt_math943 - sjt_math944;
    sjt_dot788 = _parent;
    sjt_math967 = sjt_dot788->m02;
    sjt_dot789 = _parent;
    sjt_math968 = sjt_dot789->m11;
    sjt_math965 = sjt_math967 * sjt_math968;
    sjt_dot790 = _parent;
    sjt_math966 = sjt_dot790->m33;
    sjt_math942 = sjt_math965 * sjt_math966;
    sjt_math939 = sjt_math941 - sjt_math942;
    sjt_dot791 = _parent;
    sjt_math971 = sjt_dot791->m01;
    sjt_dot792 = _parent;
    sjt_math972 = sjt_dot792->m12;
    sjt_math969 = sjt_math971 * sjt_math972;
    sjt_dot793 = _parent;
    sjt_math970 = sjt_dot793->m33;
    sjt_math940 = sjt_math969 * sjt_math970;
    sjv_t.m02 = sjt_math939 + sjt_math940;
    sjt_dot794 = _parent;
    sjt_math985 = sjt_dot794->m03;
    sjt_dot795 = _parent;
    sjt_math986 = sjt_dot795->m12;
    sjt_math983 = sjt_math985 * sjt_math986;
    sjt_dot796 = _parent;
    sjt_math984 = sjt_dot796->m21;
    sjt_math981 = sjt_math983 * sjt_math984;
    sjt_dot797 = _parent;
    sjt_math989 = sjt_dot797->m02;
    sjt_dot798 = _parent;
    sjt_math990 = sjt_dot798->m13;
    sjt_math987 = sjt_math989 * sjt_math990;
    sjt_dot799 = _parent;
    sjt_math988 = sjt_dot799->m21;
    sjt_math982 = sjt_math987 * sjt_math988;
    sjt_math979 = sjt_math981 - sjt_math982;
    sjt_dot800 = _parent;
    sjt_math993 = sjt_dot800->m03;
    sjt_dot801 = _parent;
    sjt_math994 = sjt_dot801->m11;
    sjt_math991 = sjt_math993 * sjt_math994;
    sjt_dot802 = _parent;
    sjt_math992 = sjt_dot802->m22;
    sjt_math980 = sjt_math991 * sjt_math992;
    sjt_math977 = sjt_math979 - sjt_math980;
    sjt_dot803 = _parent;
    sjt_math997 = sjt_dot803->m01;
    sjt_dot804 = _parent;
    sjt_math998 = sjt_dot804->m13;
    sjt_math995 = sjt_math997 * sjt_math998;
    sjt_dot805 = _parent;
    sjt_math996 = sjt_dot805->m22;
    sjt_math978 = sjt_math995 * sjt_math996;
    sjt_math975 = sjt_math977 + sjt_math978;
    sjt_dot806 = _parent;
    sjt_math1001 = sjt_dot806->m02;
    sjt_dot807 = _parent;
    sjt_math1002 = sjt_dot807->m11;
    sjt_math999 = sjt_math1001 * sjt_math1002;
    sjt_dot808 = _parent;
    sjt_math1000 = sjt_dot808->m23;
    sjt_math976 = sjt_math999 * sjt_math1000;
    sjt_math973 = sjt_math975 + sjt_math976;
    sjt_dot809 = _parent;
    sjt_math1005 = sjt_dot809->m01;
    sjt_dot810 = _parent;
    sjt_math1006 = sjt_dot810->m12;
    sjt_math1003 = sjt_math1005 * sjt_math1006;
    sjt_dot811 = _parent;
    sjt_math1004 = sjt_dot811->m23;
    sjt_math974 = sjt_math1003 * sjt_math1004;
    sjv_t.m03 = sjt_math973 - sjt_math974;
    sjt_dot812 = _parent;
    sjt_math1019 = sjt_dot812->m13;
    sjt_dot813 = _parent;
    sjt_math1020 = sjt_dot813->m22;
    sjt_math1017 = sjt_math1019 * sjt_math1020;
    sjt_dot814 = _parent;
    sjt_math1018 = sjt_dot814->m30;
    sjt_math1015 = sjt_math1017 * sjt_math1018;
    sjt_dot815 = _parent;
    sjt_math1023 = sjt_dot815->m12;
    sjt_dot816 = _parent;
    sjt_math1024 = sjt_dot816->m23;
    sjt_math1021 = sjt_math1023 * sjt_math1024;
    sjt_dot817 = _parent;
    sjt_math1022 = sjt_dot817->m30;
    sjt_math1016 = sjt_math1021 * sjt_math1022;
    sjt_math1013 = sjt_math1015 - sjt_math1016;
    sjt_dot818 = _parent;
    sjt_math1027 = sjt_dot818->m13;
    sjt_dot819 = _parent;
    sjt_math1028 = sjt_dot819->m20;
    sjt_math1025 = sjt_math1027 * sjt_math1028;
    sjt_dot820 = _parent;
    sjt_math1026 = sjt_dot820->m32;
    sjt_math1014 = sjt_math1025 * sjt_math1026;
    sjt_math1011 = sjt_math1013 - sjt_math1014;
    sjt_dot821 = _parent;
    sjt_math1031 = sjt_dot821->m10;
    sjt_dot822 = _parent;
    sjt_math1032 = sjt_dot822->m23;
    sjt_math1029 = sjt_math1031 * sjt_math1032;
    sjt_dot823 = _parent;
    sjt_math1030 = sjt_dot823->m32;
    sjt_math1012 = sjt_math1029 * sjt_math1030;
    sjt_math1009 = sjt_math1011 + sjt_math1012;
    sjt_dot824 = _parent;
    sjt_math1035 = sjt_dot824->m12;
    sjt_dot825 = _parent;
    sjt_math1036 = sjt_dot825->m20;
    sjt_math1033 = sjt_math1035 * sjt_math1036;
    sjt_dot826 = _parent;
    sjt_math1034 = sjt_dot826->m33;
    sjt_math1010 = sjt_math1033 * sjt_math1034;
    sjt_math1007 = sjt_math1009 + sjt_math1010;
    sjt_dot827 = _parent;
    sjt_math1039 = sjt_dot827->m10;
    sjt_dot828 = _parent;
    sjt_math1040 = sjt_dot828->m22;
    sjt_math1037 = sjt_math1039 * sjt_math1040;
    sjt_dot829 = _parent;
    sjt_math1038 = sjt_dot829->m33;
    sjt_math1008 = sjt_math1037 * sjt_math1038;
    sjv_t.m10 = sjt_math1007 - sjt_math1008;
    sjt_dot830 = _parent;
    sjt_math1053 = sjt_dot830->m02;
    sjt_dot831 = _parent;
    sjt_math1054 = sjt_dot831->m23;
    sjt_math1051 = sjt_math1053 * sjt_math1054;
    sjt_dot832 = _parent;
    sjt_math1052 = sjt_dot832->m30;
    sjt_math1049 = sjt_math1051 * sjt_math1052;
    sjt_dot833 = _parent;
    sjt_math1057 = sjt_dot833->m03;
    sjt_dot834 = _parent;
    sjt_math1058 = sjt_dot834->m22;
    sjt_math1055 = sjt_math1057 * sjt_math1058;
    sjt_dot835 = _parent;
    sjt_math1056 = sjt_dot835->m30;
    sjt_math1050 = sjt_math1055 * sjt_math1056;
    sjt_math1047 = sjt_math1049 - sjt_math1050;
    sjt_dot836 = _parent;
    sjt_math1061 = sjt_dot836->m03;
    sjt_dot837 = _parent;
    sjt_math1062 = sjt_dot837->m20;
    sjt_math1059 = sjt_math1061 * sjt_math1062;
    sjt_dot838 = _parent;
    sjt_math1060 = sjt_dot838->m32;
    sjt_math1048 = sjt_math1059 * sjt_math1060;
    sjt_math1045 = sjt_math1047 + sjt_math1048;
    sjt_dot839 = _parent;
    sjt_math1065 = sjt_dot839->m00;
    sjt_dot840 = _parent;
    sjt_math1066 = sjt_dot840->m23;
    sjt_math1063 = sjt_math1065 * sjt_math1066;
    sjt_dot841 = _parent;
    sjt_math1064 = sjt_dot841->m32;
    sjt_math1046 = sjt_math1063 * sjt_math1064;
    sjt_math1043 = sjt_math1045 - sjt_math1046;
    sjt_dot842 = _parent;
    sjt_math1069 = sjt_dot842->m02;
    sjt_dot843 = _parent;
    sjt_math1070 = sjt_dot843->m20;
    sjt_math1067 = sjt_math1069 * sjt_math1070;
    sjt_dot844 = _parent;
    sjt_math1068 = sjt_dot844->m33;
    sjt_math1044 = sjt_math1067 * sjt_math1068;
    sjt_math1041 = sjt_math1043 - sjt_math1044;
    sjt_dot845 = _parent;
    sjt_math1073 = sjt_dot845->m00;
    sjt_dot846 = _parent;
    sjt_math1074 = sjt_dot846->m22;
    sjt_math1071 = sjt_math1073 * sjt_math1074;
    sjt_dot847 = _parent;
    sjt_math1072 = sjt_dot847->m33;
    sjt_math1042 = sjt_math1071 * sjt_math1072;
    sjv_t.m11 = sjt_math1041 + sjt_math1042;
    sjt_dot848 = _parent;
    sjt_math1087 = sjt_dot848->m03;
    sjt_dot849 = _parent;
    sjt_math1088 = sjt_dot849->m12;
    sjt_math1085 = sjt_math1087 * sjt_math1088;
    sjt_dot850 = _parent;
    sjt_math1086 = sjt_dot850->m30;
    sjt_math1083 = sjt_math1085 * sjt_math1086;
    sjt_dot851 = _parent;
    sjt_math1091 = sjt_dot851->m02;
    sjt_dot852 = _parent;
    sjt_math1092 = sjt_dot852->m13;
    sjt_math1089 = sjt_math1091 * sjt_math1092;
    sjt_dot853 = _parent;
    sjt_math1090 = sjt_dot853->m30;
    sjt_math1084 = sjt_math1089 * sjt_math1090;
    sjt_math1081 = sjt_math1083 - sjt_math1084;
    sjt_dot854 = _parent;
    sjt_math1095 = sjt_dot854->m03;
    sjt_dot855 = _parent;
    sjt_math1096 = sjt_dot855->m10;
    sjt_math1093 = sjt_math1095 * sjt_math1096;
    sjt_dot856 = _parent;
    sjt_math1094 = sjt_dot856->m32;
    sjt_math1082 = sjt_math1093 * sjt_math1094;
    sjt_math1079 = sjt_math1081 - sjt_math1082;
    sjt_dot857 = _parent;
    sjt_math1099 = sjt_dot857->m00;
    sjt_dot858 = _parent;
    sjt_math1100 = sjt_dot858->m13;
    sjt_math1097 = sjt_math1099 * sjt_math1100;
    sjt_dot859 = _parent;
    sjt_math1098 = sjt_dot859->m32;
    sjt_math1080 = sjt_math1097 * sjt_math1098;
    sjt_math1077 = sjt_math1079 + sjt_math1080;
    sjt_dot860 = _parent;
    sjt_math1103 = sjt_dot860->m02;
    sjt_dot861 = _parent;
    sjt_math1104 = sjt_dot861->m10;
    sjt_math1101 = sjt_math1103 * sjt_math1104;
    sjt_dot862 = _parent;
    sjt_math1102 = sjt_dot862->m33;
    sjt_math1078 = sjt_math1101 * sjt_math1102;
    sjt_math1075 = sjt_math1077 + sjt_math1078;
    sjt_dot863 = _parent;
    sjt_math1107 = sjt_dot863->m00;
    sjt_dot864 = _parent;
    sjt_math1108 = sjt_dot864->m12;
    sjt_math1105 = sjt_math1107 * sjt_math1108;
    sjt_dot865 = _parent;
    sjt_math1106 = sjt_dot865->m33;
    sjt_math1076 = sjt_math1105 * sjt_math1106;
    sjv_t.m12 = sjt_math1075 - sjt_math1076;
    sjt_dot866 = _parent;
    sjt_math1121 = sjt_dot866->m02;
    sjt_dot867 = _parent;
    sjt_math1122 = sjt_dot867->m13;
    sjt_math1119 = sjt_math1121 * sjt_math1122;
    sjt_dot868 = _parent;
    sjt_math1120 = sjt_dot868->m20;
    sjt_math1117 = sjt_math1119 * sjt_math1120;
    sjt_dot869 = _parent;
    sjt_math1125 = sjt_dot869->m03;
    sjt_dot870 = _parent;
    sjt_math1126 = sjt_dot870->m12;
    sjt_math1123 = sjt_math1125 * sjt_math1126;
    sjt_dot871 = _parent;
    sjt_math1124 = sjt_dot871->m20;
    sjt_math1118 = sjt_math1123 * sjt_math1124;
    sjt_math1115 = sjt_math1117 - sjt_math1118;
    sjt_dot872 = _parent;
    sjt_math1129 = sjt_dot872->m03;
    sjt_dot873 = _parent;
    sjt_math1130 = sjt_dot873->m10;
    sjt_math1127 = sjt_math1129 * sjt_math1130;
    sjt_dot874 = _parent;
    sjt_math1128 = sjt_dot874->m22;
    sjt_math1116 = sjt_math1127 * sjt_math1128;
    sjt_math1113 = sjt_math1115 + sjt_math1116;
    sjt_dot875 = _parent;
    sjt_math1133 = sjt_dot875->m00;
    sjt_dot876 = _parent;
    sjt_math1134 = sjt_dot876->m13;
    sjt_math1131 = sjt_math1133 * sjt_math1134;
    sjt_dot877 = _parent;
    sjt_math1132 = sjt_dot877->m22;
    sjt_math1114 = sjt_math1131 * sjt_math1132;
    sjt_math1111 = sjt_math1113 - sjt_math1114;
    sjt_dot878 = _parent;
    sjt_math1137 = sjt_dot878->m02;
    sjt_dot879 = _parent;
    sjt_math1138 = sjt_dot879->m10;
    sjt_math1135 = sjt_math1137 * sjt_math1138;
    sjt_dot880 = _parent;
    sjt_math1136 = sjt_dot880->m23;
    sjt_math1112 = sjt_math1135 * sjt_math1136;
    sjt_math1109 = sjt_math1111 - sjt_math1112;
    sjt_dot881 = _parent;
    sjt_math1141 = sjt_dot881->m00;
    sjt_dot882 = _parent;
    sjt_math1142 = sjt_dot882->m12;
    sjt_math1139 = sjt_math1141 * sjt_math1142;
    sjt_dot883 = _parent;
    sjt_math1140 = sjt_dot883->m23;
    sjt_math1110 = sjt_math1139 * sjt_math1140;
    sjv_t.m13 = sjt_math1109 + sjt_math1110;
    sjt_dot884 = _parent;
    sjt_math1155 = sjt_dot884->m11;
    sjt_dot885 = _parent;
    sjt_math1156 = sjt_dot885->m23;
    sjt_math1153 = sjt_math1155 * sjt_math1156;
    sjt_dot886 = _parent;
    sjt_math1154 = sjt_dot886->m30;
    sjt_math1151 = sjt_math1153 * sjt_math1154;
    sjt_dot887 = _parent;
    sjt_math1159 = sjt_dot887->m13;
    sjt_dot888 = _parent;
    sjt_math1160 = sjt_dot888->m21;
    sjt_math1157 = sjt_math1159 * sjt_math1160;
    sjt_dot889 = _parent;
    sjt_math1158 = sjt_dot889->m30;
    sjt_math1152 = sjt_math1157 * sjt_math1158;
    sjt_math1149 = sjt_math1151 - sjt_math1152;
    sjt_dot890 = _parent;
    sjt_math1163 = sjt_dot890->m13;
    sjt_dot891 = _parent;
    sjt_math1164 = sjt_dot891->m20;
    sjt_math1161 = sjt_math1163 * sjt_math1164;
    sjt_dot892 = _parent;
    sjt_math1162 = sjt_dot892->m31;
    sjt_math1150 = sjt_math1161 * sjt_math1162;
    sjt_math1147 = sjt_math1149 + sjt_math1150;
    sjt_dot893 = _parent;
    sjt_math1167 = sjt_dot893->m10;
    sjt_dot894 = _parent;
    sjt_math1168 = sjt_dot894->m23;
    sjt_math1165 = sjt_math1167 * sjt_math1168;
    sjt_dot895 = _parent;
    sjt_math1166 = sjt_dot895->m31;
    sjt_math1148 = sjt_math1165 * sjt_math1166;
    sjt_math1145 = sjt_math1147 - sjt_math1148;
    sjt_dot896 = _parent;
    sjt_math1171 = sjt_dot896->m11;
    sjt_dot897 = _parent;
    sjt_math1172 = sjt_dot897->m20;
    sjt_math1169 = sjt_math1171 * sjt_math1172;
    sjt_dot898 = _parent;
    sjt_math1170 = sjt_dot898->m33;
    sjt_math1146 = sjt_math1169 * sjt_math1170;
    sjt_math1143 = sjt_math1145 - sjt_math1146;
    sjt_dot899 = _parent;
    sjt_math1175 = sjt_dot899->m10;
    sjt_dot900 = _parent;
    sjt_math1176 = sjt_dot900->m21;
    sjt_math1173 = sjt_math1175 * sjt_math1176;
    sjt_dot901 = _parent;
    sjt_math1174 = sjt_dot901->m33;
    sjt_math1144 = sjt_math1173 * sjt_math1174;
    sjv_t.m20 = sjt_math1143 + sjt_math1144;
    sjt_dot902 = _parent;
    sjt_math1189 = sjt_dot902->m03;
    sjt_dot903 = _parent;
    sjt_math1190 = sjt_dot903->m21;
    sjt_math1187 = sjt_math1189 * sjt_math1190;
    sjt_dot904 = _parent;
    sjt_math1188 = sjt_dot904->m30;
    sjt_math1185 = sjt_math1187 * sjt_math1188;
    sjt_dot905 = _parent;
    sjt_math1193 = sjt_dot905->m01;
    sjt_dot906 = _parent;
    sjt_math1194 = sjt_dot906->m23;
    sjt_math1191 = sjt_math1193 * sjt_math1194;
    sjt_dot907 = _parent;
    sjt_math1192 = sjt_dot907->m30;
    sjt_math1186 = sjt_math1191 * sjt_math1192;
    sjt_math1183 = sjt_math1185 - sjt_math1186;
    sjt_dot908 = _parent;
    sjt_math1197 = sjt_dot908->m03;
    sjt_dot909 = _parent;
    sjt_math1198 = sjt_dot909->m20;
    sjt_math1195 = sjt_math1197 * sjt_math1198;
    sjt_dot910 = _parent;
    sjt_math1196 = sjt_dot910->m31;
    sjt_math1184 = sjt_math1195 * sjt_math1196;
    sjt_math1181 = sjt_math1183 - sjt_math1184;
    sjt_dot911 = _parent;
    sjt_math1201 = sjt_dot911->m00;
    sjt_dot912 = _parent;
    sjt_math1202 = sjt_dot912->m23;
    sjt_math1199 = sjt_math1201 * sjt_math1202;
    sjt_dot913 = _parent;
    sjt_math1200 = sjt_dot913->m31;
    sjt_math1182 = sjt_math1199 * sjt_math1200;
    sjt_math1179 = sjt_math1181 + sjt_math1182;
    sjt_dot914 = _parent;
    sjt_math1205 = sjt_dot914->m01;
    sjt_dot915 = _parent;
    sjt_math1206 = sjt_dot915->m20;
    sjt_math1203 = sjt_math1205 * sjt_math1206;
    sjt_dot916 = _parent;
    sjt_math1204 = sjt_dot916->m33;
    sjt_math1180 = sjt_math1203 * sjt_math1204;
    sjt_math1177 = sjt_math1179 + sjt_math1180;
    sjt_dot917 = _parent;
    sjt_math1209 = sjt_dot917->m00;
    sjt_dot918 = _parent;
    sjt_math1210 = sjt_dot918->m21;
    sjt_math1207 = sjt_math1209 * sjt_math1210;
    sjt_dot919 = _parent;
    sjt_math1208 = sjt_dot919->m33;
    sjt_math1178 = sjt_math1207 * sjt_math1208;
    sjv_t.m21 = sjt_math1177 - sjt_math1178;
    sjt_dot920 = _parent;
    sjt_math1223 = sjt_dot920->m01;
    sjt_dot921 = _parent;
    sjt_math1224 = sjt_dot921->m13;
    sjt_math1221 = sjt_math1223 * sjt_math1224;
    sjt_dot922 = _parent;
    sjt_math1222 = sjt_dot922->m30;
    sjt_math1219 = sjt_math1221 * sjt_math1222;
    sjt_dot923 = _parent;
    sjt_math1227 = sjt_dot923->m03;
    sjt_dot924 = _parent;
    sjt_math1228 = sjt_dot924->m11;
    sjt_math1225 = sjt_math1227 * sjt_math1228;
    sjt_dot925 = _parent;
    sjt_math1226 = sjt_dot925->m30;
    sjt_math1220 = sjt_math1225 * sjt_math1226;
    sjt_math1217 = sjt_math1219 - sjt_math1220;
    sjt_dot926 = _parent;
    sjt_math1231 = sjt_dot926->m03;
    sjt_dot927 = _parent;
    sjt_math1232 = sjt_dot927->m10;
    sjt_math1229 = sjt_math1231 * sjt_math1232;
    sjt_dot928 = _parent;
    sjt_math1230 = sjt_dot928->m31;
    sjt_math1218 = sjt_math1229 * sjt_math1230;
    sjt_math1215 = sjt_math1217 + sjt_math1218;
    sjt_dot929 = _parent;
    sjt_math1235 = sjt_dot929->m00;
    sjt_dot930 = _parent;
    sjt_math1236 = sjt_dot930->m13;
    sjt_math1233 = sjt_math1235 * sjt_math1236;
    sjt_dot931 = _parent;
    sjt_math1234 = sjt_dot931->m31;
    sjt_math1216 = sjt_math1233 * sjt_math1234;
    sjt_math1213 = sjt_math1215 - sjt_math1216;
    sjt_dot932 = _parent;
    sjt_math1239 = sjt_dot932->m01;
    sjt_dot933 = _parent;
    sjt_math1240 = sjt_dot933->m10;
    sjt_math1237 = sjt_math1239 * sjt_math1240;
    sjt_dot934 = _parent;
    sjt_math1238 = sjt_dot934->m33;
    sjt_math1214 = sjt_math1237 * sjt_math1238;
    sjt_math1211 = sjt_math1213 - sjt_math1214;
    sjt_dot935 = _parent;
    sjt_math1243 = sjt_dot935->m00;
    sjt_dot936 = _parent;
    sjt_math1244 = sjt_dot936->m11;
    sjt_math1241 = sjt_math1243 * sjt_math1244;
    sjt_dot937 = _parent;
    sjt_math1242 = sjt_dot937->m33;
    sjt_math1212 = sjt_math1241 * sjt_math1242;
    sjv_t.m22 = sjt_math1211 + sjt_math1212;
    sjt_dot938 = _parent;
    sjt_math1257 = sjt_dot938->m03;
    sjt_dot939 = _parent;
    sjt_math1258 = sjt_dot939->m11;
    sjt_math1255 = sjt_math1257 * sjt_math1258;
    sjt_dot940 = _parent;
    sjt_math1256 = sjt_dot940->m20;
    sjt_math1253 = sjt_math1255 * sjt_math1256;
    sjt_dot941 = _parent;
    sjt_math1261 = sjt_dot941->m01;
    sjt_dot942 = _parent;
    sjt_math1262 = sjt_dot942->m13;
    sjt_math1259 = sjt_math1261 * sjt_math1262;
    sjt_dot943 = _parent;
    sjt_math1260 = sjt_dot943->m20;
    sjt_math1254 = sjt_math1259 * sjt_math1260;
    sjt_math1251 = sjt_math1253 - sjt_math1254;
    sjt_dot944 = _parent;
    sjt_math1265 = sjt_dot944->m03;
    sjt_dot945 = _parent;
    sjt_math1266 = sjt_dot945->m10;
    sjt_math1263 = sjt_math1265 * sjt_math1266;
    sjt_dot946 = _parent;
    sjt_math1264 = sjt_dot946->m21;
    sjt_math1252 = sjt_math1263 * sjt_math1264;
    sjt_math1249 = sjt_math1251 - sjt_math1252;
    sjt_dot947 = _parent;
    sjt_math1269 = sjt_dot947->m00;
    sjt_dot948 = _parent;
    sjt_math1270 = sjt_dot948->m13;
    sjt_math1267 = sjt_math1269 * sjt_math1270;
    sjt_dot949 = _parent;
    sjt_math1268 = sjt_dot949->m21;
    sjt_math1250 = sjt_math1267 * sjt_math1268;
    sjt_math1247 = sjt_math1249 + sjt_math1250;
    sjt_dot950 = _parent;
    sjt_math1273 = sjt_dot950->m01;
    sjt_dot951 = _parent;
    sjt_math1274 = sjt_dot951->m10;
    sjt_math1271 = sjt_math1273 * sjt_math1274;
    sjt_dot952 = _parent;
    sjt_math1272 = sjt_dot952->m23;
    sjt_math1248 = sjt_math1271 * sjt_math1272;
    sjt_math1245 = sjt_math1247 + sjt_math1248;
    sjt_dot953 = _parent;
    sjt_math1277 = sjt_dot953->m00;
    sjt_dot954 = _parent;
    sjt_math1278 = sjt_dot954->m11;
    sjt_math1275 = sjt_math1277 * sjt_math1278;
    sjt_dot955 = _parent;
    sjt_math1276 = sjt_dot955->m23;
    sjt_math1246 = sjt_math1275 * sjt_math1276;
    sjv_t.m23 = sjt_math1245 - sjt_math1246;
    sjt_dot956 = _parent;
    sjt_math1291 = sjt_dot956->m12;
    sjt_dot957 = _parent;
    sjt_math1292 = sjt_dot957->m21;
    sjt_math1289 = sjt_math1291 * sjt_math1292;
    sjt_dot958 = _parent;
    sjt_math1290 = sjt_dot958->m30;
    sjt_math1287 = sjt_math1289 * sjt_math1290;
    sjt_dot959 = _parent;
    sjt_math1295 = sjt_dot959->m11;
    sjt_dot960 = _parent;
    sjt_math1296 = sjt_dot960->m22;
    sjt_math1293 = sjt_math1295 * sjt_math1296;
    sjt_dot961 = _parent;
    sjt_math1294 = sjt_dot961->m30;
    sjt_math1288 = sjt_math1293 * sjt_math1294;
    sjt_math1285 = sjt_math1287 - sjt_math1288;
    sjt_dot962 = _parent;
    sjt_math1299 = sjt_dot962->m12;
    sjt_dot963 = _parent;
    sjt_math1300 = sjt_dot963->m20;
    sjt_math1297 = sjt_math1299 * sjt_math1300;
    sjt_dot964 = _parent;
    sjt_math1298 = sjt_dot964->m31;
    sjt_math1286 = sjt_math1297 * sjt_math1298;
    sjt_math1283 = sjt_math1285 - sjt_math1286;
    sjt_dot965 = _parent;
    sjt_math1303 = sjt_dot965->m10;
    sjt_dot966 = _parent;
    sjt_math1304 = sjt_dot966->m22;
    sjt_math1301 = sjt_math1303 * sjt_math1304;
    sjt_dot967 = _parent;
    sjt_math1302 = sjt_dot967->m31;
    sjt_math1284 = sjt_math1301 * sjt_math1302;
    sjt_math1281 = sjt_math1283 + sjt_math1284;
    sjt_dot968 = _parent;
    sjt_math1307 = sjt_dot968->m11;
    sjt_dot969 = _parent;
    sjt_math1308 = sjt_dot969->m20;
    sjt_math1305 = sjt_math1307 * sjt_math1308;
    sjt_dot970 = _parent;
    sjt_math1306 = sjt_dot970->m32;
    sjt_math1282 = sjt_math1305 * sjt_math1306;
    sjt_math1279 = sjt_math1281 + sjt_math1282;
    sjt_dot971 = _parent;
    sjt_math1311 = sjt_dot971->m10;
    sjt_dot972 = _parent;
    sjt_math1312 = sjt_dot972->m21;
    sjt_math1309 = sjt_math1311 * sjt_math1312;
    sjt_dot973 = _parent;
    sjt_math1310 = sjt_dot973->m32;
    sjt_math1280 = sjt_math1309 * sjt_math1310;
    sjv_t.m30 = sjt_math1279 - sjt_math1280;
    sjt_dot974 = _parent;
    sjt_math1325 = sjt_dot974->m01;
    sjt_dot975 = _parent;
    sjt_math1326 = sjt_dot975->m22;
    sjt_math1323 = sjt_math1325 * sjt_math1326;
    sjt_dot976 = _parent;
    sjt_math1324 = sjt_dot976->m30;
    sjt_math1321 = sjt_math1323 * sjt_math1324;
    sjt_dot977 = _parent;
    sjt_math1329 = sjt_dot977->m02;
    sjt_dot978 = _parent;
    sjt_math1330 = sjt_dot978->m21;
    sjt_math1327 = sjt_math1329 * sjt_math1330;
    sjt_dot979 = _parent;
    sjt_math1328 = sjt_dot979->m30;
    sjt_math1322 = sjt_math1327 * sjt_math1328;
    sjt_math1319 = sjt_math1321 - sjt_math1322;
    sjt_dot980 = _parent;
    sjt_math1333 = sjt_dot980->m02;
    sjt_dot981 = _parent;
    sjt_math1334 = sjt_dot981->m20;
    sjt_math1331 = sjt_math1333 * sjt_math1334;
    sjt_dot982 = _parent;
    sjt_math1332 = sjt_dot982->m31;
    sjt_math1320 = sjt_math1331 * sjt_math1332;
    sjt_math1317 = sjt_math1319 + sjt_math1320;
    sjt_dot983 = _parent;
    sjt_math1337 = sjt_dot983->m00;
    sjt_dot984 = _parent;
    sjt_math1338 = sjt_dot984->m22;
    sjt_math1335 = sjt_math1337 * sjt_math1338;
    sjt_dot985 = _parent;
    sjt_math1336 = sjt_dot985->m31;
    sjt_math1318 = sjt_math1335 * sjt_math1336;
    sjt_math1315 = sjt_math1317 - sjt_math1318;
    sjt_dot986 = _parent;
    sjt_math1341 = sjt_dot986->m01;
    sjt_dot987 = _parent;
    sjt_math1342 = sjt_dot987->m20;
    sjt_math1339 = sjt_math1341 * sjt_math1342;
    sjt_dot988 = _parent;
    sjt_math1340 = sjt_dot988->m32;
    sjt_math1316 = sjt_math1339 * sjt_math1340;
    sjt_math1313 = sjt_math1315 - sjt_math1316;
    sjt_dot989 = _parent;
    sjt_math1345 = sjt_dot989->m00;
    sjt_dot990 = _parent;
    sjt_math1346 = sjt_dot990->m21;
    sjt_math1343 = sjt_math1345 * sjt_math1346;
    sjt_dot991 = _parent;
    sjt_math1344 = sjt_dot991->m32;
    sjt_math1314 = sjt_math1343 * sjt_math1344;
    sjv_t.m31 = sjt_math1313 + sjt_math1314;
    sjt_dot992 = _parent;
    sjt_math1359 = sjt_dot992->m02;
    sjt_dot993 = _parent;
    sjt_math1360 = sjt_dot993->m11;
    sjt_math1357 = sjt_math1359 * sjt_math1360;
    sjt_dot994 = _parent;
    sjt_math1358 = sjt_dot994->m30;
    sjt_math1355 = sjt_math1357 * sjt_math1358;
    sjt_dot995 = _parent;
    sjt_math1363 = sjt_dot995->m01;
    sjt_dot996 = _parent;
    sjt_math1364 = sjt_dot996->m12;
    sjt_math1361 = sjt_math1363 * sjt_math1364;
    sjt_dot997 = _parent;
    sjt_math1362 = sjt_dot997->m30;
    sjt_math1356 = sjt_math1361 * sjt_math1362;
    sjt_math1353 = sjt_math1355 - sjt_math1356;
    sjt_dot998 = _parent;
    sjt_math1367 = sjt_dot998->m02;
    sjt_dot999 = _parent;
    sjt_math1368 = sjt_dot999->m10;
    sjt_math1365 = sjt_math1367 * sjt_math1368;
    sjt_dot1000 = _parent;
    sjt_math1366 = sjt_dot1000->m31;
    sjt_math1354 = sjt_math1365 * sjt_math1366;
    sjt_math1351 = sjt_math1353 - sjt_math1354;
    sjt_dot1001 = _parent;
    sjt_math1371 = sjt_dot1001->m00;
    sjt_dot1002 = _parent;
    sjt_math1372 = sjt_dot1002->m12;
    sjt_math1369 = sjt_math1371 * sjt_math1372;
    sjt_dot1003 = _parent;
    sjt_math1370 = sjt_dot1003->m31;
    sjt_math1352 = sjt_math1369 * sjt_math1370;
    sjt_math1349 = sjt_math1351 + sjt_math1352;
    sjt_dot1004 = _parent;
    sjt_math1375 = sjt_dot1004->m01;
    sjt_dot1005 = _parent;
    sjt_math1376 = sjt_dot1005->m10;
    sjt_math1373 = sjt_math1375 * sjt_math1376;
    sjt_dot1006 = _parent;
    sjt_math1374 = sjt_dot1006->m32;
    sjt_math1350 = sjt_math1373 * sjt_math1374;
    sjt_math1347 = sjt_math1349 + sjt_math1350;
    sjt_dot1007 = _parent;
    sjt_math1379 = sjt_dot1007->m00;
    sjt_dot1008 = _parent;
    sjt_math1380 = sjt_dot1008->m11;
    sjt_math1377 = sjt_math1379 * sjt_math1380;
    sjt_dot1009 = _parent;
    sjt_math1378 = sjt_dot1009->m32;
    sjt_math1348 = sjt_math1377 * sjt_math1378;
    sjv_t.m32 = sjt_math1347 - sjt_math1348;
    sjt_dot1010 = _parent;
    sjt_math1393 = sjt_dot1010->m01;
    sjt_dot1011 = _parent;
    sjt_math1394 = sjt_dot1011->m12;
    sjt_math1391 = sjt_math1393 * sjt_math1394;
    sjt_dot1012 = _parent;
    sjt_math1392 = sjt_dot1012->m20;
    sjt_math1389 = sjt_math1391 * sjt_math1392;
    sjt_dot1013 = _parent;
    sjt_math1397 = sjt_dot1013->m02;
    sjt_dot1014 = _parent;
    sjt_math1398 = sjt_dot1014->m11;
    sjt_math1395 = sjt_math1397 * sjt_math1398;
    sjt_dot1015 = _parent;
    sjt_math1396 = sjt_dot1015->m20;
    sjt_math1390 = sjt_math1395 * sjt_math1396;
    sjt_math1387 = sjt_math1389 - sjt_math1390;
    sjt_dot1016 = _parent;
    sjt_math1401 = sjt_dot1016->m02;
    sjt_dot1017 = _parent;
    sjt_math1402 = sjt_dot1017->m10;
    sjt_math1399 = sjt_math1401 * sjt_math1402;
    sjt_dot1018 = _parent;
    sjt_math1400 = sjt_dot1018->m21;
    sjt_math1388 = sjt_math1399 * sjt_math1400;
    sjt_math1385 = sjt_math1387 + sjt_math1388;
    sjt_dot1019 = _parent;
    sjt_math1405 = sjt_dot1019->m00;
    sjt_dot1020 = _parent;
    sjt_math1406 = sjt_dot1020->m12;
    sjt_math1403 = sjt_math1405 * sjt_math1406;
    sjt_dot1021 = _parent;
    sjt_math1404 = sjt_dot1021->m21;
    sjt_math1386 = sjt_math1403 * sjt_math1404;
    sjt_math1383 = sjt_math1385 - sjt_math1386;
    sjt_dot1022 = _parent;
    sjt_math1409 = sjt_dot1022->m01;
    sjt_dot1023 = _parent;
    sjt_math1410 = sjt_dot1023->m10;
    sjt_math1407 = sjt_math1409 * sjt_math1410;
    sjt_dot1024 = _parent;
    sjt_math1408 = sjt_dot1024->m22;
    sjt_math1384 = sjt_math1407 * sjt_math1408;
    sjt_math1381 = sjt_math1383 - sjt_math1384;
    sjt_dot1025 = _parent;
    sjt_math1413 = sjt_dot1025->m00;
    sjt_dot1026 = _parent;
    sjt_math1414 = sjt_dot1026->m11;
    sjt_math1411 = sjt_math1413 * sjt_math1414;
    sjt_dot1027 = _parent;
    sjt_math1412 = sjt_dot1027->m22;
    sjt_math1382 = sjt_math1411 * sjt_math1412;
    sjv_t.m33 = sjt_math1381 + sjt_math1382;
    sjf_mat4(&sjv_t);
    sjt_parent110 = &sjv_t;
    sjt_math1479 = 1.0f;
    sjf_mat4_determinant(_parent, &sjt_math1480);
    sjt_functionParam161 = sjt_math1479 / sjt_math1480;
    sjf_mat4_multiplyf32(sjt_parent110, sjt_functionParam161, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
;
}

void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4** _return) {
    sjs_mat4* sjt_dot1156 = 0;
    sjs_mat4* sjt_dot1157 = 0;
    sjs_mat4* sjt_dot1158 = 0;
    sjs_mat4* sjt_dot1159 = 0;
    sjs_mat4* sjt_dot1160 = 0;
    sjs_mat4* sjt_dot1161 = 0;
    sjs_mat4* sjt_dot1162 = 0;
    sjs_mat4* sjt_dot1163 = 0;
    sjs_mat4* sjt_dot1164 = 0;
    sjs_mat4* sjt_dot1165 = 0;
    sjs_mat4* sjt_dot1166 = 0;
    sjs_mat4* sjt_dot1167 = 0;
    sjs_mat4* sjt_dot1168 = 0;
    sjs_mat4* sjt_dot1169 = 0;
    sjs_mat4* sjt_dot1170 = 0;
    sjs_mat4* sjt_dot1171 = 0;
    sjs_mat4* sjt_dot1172 = 0;
    sjs_mat4* sjt_dot1173 = 0;
    sjs_mat4* sjt_dot1174 = 0;
    sjs_mat4* sjt_dot1175 = 0;
    sjs_mat4* sjt_dot1176 = 0;
    sjs_mat4* sjt_dot1177 = 0;
    sjs_mat4* sjt_dot1178 = 0;
    sjs_mat4* sjt_dot1179 = 0;
    sjs_mat4* sjt_dot1180 = 0;
    sjs_mat4* sjt_dot1181 = 0;
    sjs_mat4* sjt_dot1182 = 0;
    sjs_mat4* sjt_dot1183 = 0;
    sjs_mat4* sjt_dot1184 = 0;
    sjs_mat4* sjt_dot1185 = 0;
    sjs_mat4* sjt_dot1186 = 0;
    sjs_mat4* sjt_dot1187 = 0;
    sjs_mat4* sjt_dot1188 = 0;
    sjs_mat4* sjt_dot1189 = 0;
    sjs_mat4* sjt_dot1190 = 0;
    sjs_mat4* sjt_dot1191 = 0;
    sjs_mat4* sjt_dot1192 = 0;
    sjs_mat4* sjt_dot1193 = 0;
    sjs_mat4* sjt_dot1194 = 0;
    sjs_mat4* sjt_dot1195 = 0;
    sjs_mat4* sjt_dot1196 = 0;
    sjs_mat4* sjt_dot1197 = 0;
    sjs_mat4* sjt_dot1198 = 0;
    sjs_mat4* sjt_dot1199 = 0;
    sjs_mat4* sjt_dot1200 = 0;
    sjs_mat4* sjt_dot1201 = 0;
    sjs_mat4* sjt_dot1202 = 0;
    sjs_mat4* sjt_dot1203 = 0;
    sjs_mat4* sjt_dot1204 = 0;
    sjs_mat4* sjt_dot1205 = 0;
    sjs_mat4* sjt_dot1206 = 0;
    sjs_mat4* sjt_dot1207 = 0;
    sjs_mat4* sjt_dot1208 = 0;
    sjs_mat4* sjt_dot1209 = 0;
    sjs_mat4* sjt_dot1210 = 0;
    sjs_mat4* sjt_dot1211 = 0;
    sjs_mat4* sjt_dot1212 = 0;
    sjs_mat4* sjt_dot1213 = 0;
    sjs_mat4* sjt_dot1214 = 0;
    sjs_mat4* sjt_dot1215 = 0;
    sjs_mat4* sjt_dot1216 = 0;
    sjs_mat4* sjt_dot1217 = 0;
    sjs_mat4* sjt_dot1218 = 0;
    sjs_mat4* sjt_dot1219 = 0;
    sjs_mat4* sjt_dot1220 = 0;
    sjs_mat4* sjt_dot1221 = 0;
    sjs_mat4* sjt_dot1222 = 0;
    sjs_mat4* sjt_dot1223 = 0;
    sjs_mat4* sjt_dot1224 = 0;
    sjs_mat4* sjt_dot1225 = 0;
    sjs_mat4* sjt_dot1226 = 0;
    sjs_mat4* sjt_dot1227 = 0;
    sjs_mat4* sjt_dot1228 = 0;
    sjs_mat4* sjt_dot1229 = 0;
    sjs_mat4* sjt_dot1230 = 0;
    sjs_mat4* sjt_dot1231 = 0;
    sjs_mat4* sjt_dot1232 = 0;
    sjs_mat4* sjt_dot1233 = 0;
    sjs_mat4* sjt_dot1234 = 0;
    sjs_mat4* sjt_dot1235 = 0;
    sjs_mat4* sjt_dot1236 = 0;
    sjs_mat4* sjt_dot1237 = 0;
    sjs_mat4* sjt_dot1238 = 0;
    sjs_mat4* sjt_dot1239 = 0;
    sjs_mat4* sjt_dot1240 = 0;
    sjs_mat4* sjt_dot1241 = 0;
    sjs_mat4* sjt_dot1242 = 0;
    sjs_mat4* sjt_dot1243 = 0;
    sjs_mat4* sjt_dot1244 = 0;
    sjs_mat4* sjt_dot1245 = 0;
    sjs_mat4* sjt_dot1246 = 0;
    sjs_mat4* sjt_dot1247 = 0;
    sjs_mat4* sjt_dot1248 = 0;
    sjs_mat4* sjt_dot1249 = 0;
    sjs_mat4* sjt_dot1250 = 0;
    sjs_mat4* sjt_dot1251 = 0;
    sjs_mat4* sjt_dot1252 = 0;
    sjs_mat4* sjt_dot1253 = 0;
    sjs_mat4* sjt_dot1254 = 0;
    sjs_mat4* sjt_dot1255 = 0;
    sjs_mat4* sjt_dot1256 = 0;
    sjs_mat4* sjt_dot1257 = 0;
    sjs_mat4* sjt_dot1258 = 0;
    sjs_mat4* sjt_dot1259 = 0;
    sjs_mat4* sjt_dot1260 = 0;
    sjs_mat4* sjt_dot1261 = 0;
    sjs_mat4* sjt_dot1262 = 0;
    sjs_mat4* sjt_dot1263 = 0;
    sjs_mat4* sjt_dot1264 = 0;
    sjs_mat4* sjt_dot1265 = 0;
    sjs_mat4* sjt_dot1266 = 0;
    sjs_mat4* sjt_dot1267 = 0;
    sjs_mat4* sjt_dot1268 = 0;
    sjs_mat4* sjt_dot1269 = 0;
    sjs_mat4* sjt_dot1270 = 0;
    sjs_mat4* sjt_dot1271 = 0;
    sjs_mat4* sjt_dot1272 = 0;
    sjs_mat4* sjt_dot1273 = 0;
    sjs_mat4* sjt_dot1274 = 0;
    sjs_mat4* sjt_dot1275 = 0;
    sjs_mat4* sjt_dot1276 = 0;
    sjs_mat4* sjt_dot1277 = 0;
    sjs_mat4* sjt_dot1278 = 0;
    sjs_mat4* sjt_dot1279 = 0;
    sjs_mat4* sjt_dot1280 = 0;
    sjs_mat4* sjt_dot1281 = 0;
    sjs_mat4* sjt_dot1282 = 0;
    sjs_mat4* sjt_dot1283 = 0;
    sjs_mat4* sjt_dot1284 = 0;
    sjs_mat4* sjt_dot1285 = 0;
    sjs_mat4* sjt_dot1286 = 0;
    sjs_mat4* sjt_dot1287 = 0;
    sjs_mat4* sjt_dot1288 = 0;
    sjs_mat4* sjt_dot1289 = 0;
    sjs_mat4* sjt_dot1290 = 0;
    sjs_mat4* sjt_dot1291 = 0;
    sjs_mat4* sjt_dot1292 = 0;
    sjs_mat4* sjt_dot1293 = 0;
    sjs_mat4* sjt_dot1294 = 0;
    sjs_mat4* sjt_dot1295 = 0;
    sjs_mat4* sjt_dot1296 = 0;
    sjs_mat4* sjt_dot1297 = 0;
    sjs_mat4* sjt_dot1298 = 0;
    sjs_mat4* sjt_dot1299 = 0;
    sjs_mat4* sjt_dot1300 = 0;
    sjs_mat4* sjt_dot1301 = 0;
    sjs_mat4* sjt_dot1302 = 0;
    sjs_mat4* sjt_dot1303 = 0;
    sjs_mat4* sjt_dot1304 = 0;
    sjs_mat4* sjt_dot1305 = 0;
    sjs_mat4* sjt_dot1306 = 0;
    sjs_mat4* sjt_dot1307 = 0;
    sjs_mat4* sjt_dot1308 = 0;
    sjs_mat4* sjt_dot1309 = 0;
    sjs_mat4* sjt_dot1310 = 0;
    sjs_mat4* sjt_dot1311 = 0;
    sjs_mat4* sjt_dot1312 = 0;
    sjs_mat4* sjt_dot1313 = 0;
    sjs_mat4* sjt_dot1314 = 0;
    sjs_mat4* sjt_dot1315 = 0;
    sjs_mat4* sjt_dot1316 = 0;
    sjs_mat4* sjt_dot1317 = 0;
    sjs_mat4* sjt_dot1318 = 0;
    sjs_mat4* sjt_dot1319 = 0;
    sjs_mat4* sjt_dot1320 = 0;
    sjs_mat4* sjt_dot1321 = 0;
    sjs_mat4* sjt_dot1322 = 0;
    sjs_mat4* sjt_dot1323 = 0;
    sjs_mat4* sjt_dot1324 = 0;
    sjs_mat4* sjt_dot1325 = 0;
    sjs_mat4* sjt_dot1326 = 0;
    sjs_mat4* sjt_dot1327 = 0;
    sjs_mat4* sjt_dot1328 = 0;
    sjs_mat4* sjt_dot1329 = 0;
    sjs_mat4* sjt_dot1330 = 0;
    sjs_mat4* sjt_dot1331 = 0;
    sjs_mat4* sjt_dot1332 = 0;
    sjs_mat4* sjt_dot1333 = 0;
    sjs_mat4* sjt_dot1334 = 0;
    sjs_mat4* sjt_dot1335 = 0;
    sjs_mat4* sjt_dot1336 = 0;
    sjs_mat4* sjt_dot1337 = 0;
    sjs_mat4* sjt_dot1338 = 0;
    sjs_mat4* sjt_dot1339 = 0;
    sjs_mat4* sjt_dot1340 = 0;
    sjs_mat4* sjt_dot1341 = 0;
    sjs_mat4* sjt_dot1342 = 0;
    sjs_mat4* sjt_dot1343 = 0;
    sjs_mat4* sjt_dot1344 = 0;
    sjs_mat4* sjt_dot1345 = 0;
    sjs_mat4* sjt_dot1346 = 0;
    sjs_mat4* sjt_dot1347 = 0;
    sjs_mat4* sjt_dot1348 = 0;
    sjs_mat4* sjt_dot1349 = 0;
    sjs_mat4* sjt_dot1350 = 0;
    sjs_mat4* sjt_dot1351 = 0;
    sjs_mat4* sjt_dot1352 = 0;
    sjs_mat4* sjt_dot1353 = 0;
    sjs_mat4* sjt_dot1354 = 0;
    sjs_mat4* sjt_dot1355 = 0;
    sjs_mat4* sjt_dot1356 = 0;
    sjs_mat4* sjt_dot1357 = 0;
    sjs_mat4* sjt_dot1358 = 0;
    sjs_mat4* sjt_dot1359 = 0;
    sjs_mat4* sjt_dot1360 = 0;
    sjs_mat4* sjt_dot1361 = 0;
    sjs_mat4* sjt_dot1362 = 0;
    sjs_mat4* sjt_dot1363 = 0;
    sjs_mat4* sjt_dot1364 = 0;
    sjs_mat4* sjt_dot1365 = 0;
    sjs_mat4* sjt_dot1366 = 0;
    sjs_mat4* sjt_dot1367 = 0;
    sjs_mat4* sjt_dot1368 = 0;
    sjs_mat4* sjt_dot1369 = 0;
    sjs_mat4* sjt_dot1370 = 0;
    sjs_mat4* sjt_dot1371 = 0;
    sjs_mat4* sjt_dot1372 = 0;
    sjs_mat4* sjt_dot1373 = 0;
    sjs_mat4* sjt_dot1374 = 0;
    sjs_mat4* sjt_dot1375 = 0;
    sjs_mat4* sjt_dot1376 = 0;
    sjs_mat4* sjt_dot1377 = 0;
    sjs_mat4* sjt_dot1378 = 0;
    sjs_mat4* sjt_dot1379 = 0;
    sjs_mat4* sjt_dot1380 = 0;
    sjs_mat4* sjt_dot1381 = 0;
    sjs_mat4* sjt_dot1382 = 0;
    sjs_mat4* sjt_dot1383 = 0;
    sjs_mat4* sjt_dot1384 = 0;
    sjs_mat4* sjt_dot1385 = 0;
    sjs_mat4* sjt_dot1386 = 0;
    sjs_mat4* sjt_dot1387 = 0;
    sjs_mat4* sjt_dot1388 = 0;
    sjs_mat4* sjt_dot1389 = 0;
    sjs_mat4* sjt_dot1390 = 0;
    sjs_mat4* sjt_dot1391 = 0;
    sjs_mat4* sjt_dot1392 = 0;
    sjs_mat4* sjt_dot1393 = 0;
    sjs_mat4* sjt_dot1394 = 0;
    sjs_mat4* sjt_dot1395 = 0;
    sjs_mat4* sjt_dot1396 = 0;
    sjs_mat4* sjt_dot1397 = 0;
    sjs_mat4* sjt_dot1398 = 0;
    sjs_mat4* sjt_dot1399 = 0;
    sjs_mat4* sjt_dot1400 = 0;
    sjs_mat4* sjt_dot1401 = 0;
    sjs_mat4* sjt_dot1402 = 0;
    sjs_mat4* sjt_dot1403 = 0;
    sjs_mat4* sjt_dot1404 = 0;
    sjs_mat4* sjt_dot1405 = 0;
    sjs_mat4* sjt_dot1406 = 0;
    sjs_mat4* sjt_dot1407 = 0;
    sjs_mat4* sjt_dot1408 = 0;
    sjs_mat4* sjt_dot1409 = 0;
    sjs_mat4* sjt_dot1410 = 0;
    sjs_mat4* sjt_dot1411 = 0;
    sjs_mat4* sjt_dot1412 = 0;
    sjs_mat4* sjt_dot1413 = 0;
    sjs_mat4* sjt_dot1414 = 0;
    sjs_mat4* sjt_dot1415 = 0;
    sjs_mat4* sjt_dot1416 = 0;
    sjs_mat4* sjt_dot1417 = 0;
    sjs_mat4* sjt_dot1418 = 0;
    sjs_mat4* sjt_dot1419 = 0;
    sjs_mat4* sjt_dot1420 = 0;
    sjs_mat4* sjt_dot1421 = 0;
    sjs_mat4* sjt_dot1422 = 0;
    sjs_mat4* sjt_dot1423 = 0;
    sjs_mat4* sjt_dot1424 = 0;
    sjs_mat4* sjt_dot1425 = 0;
    sjs_mat4* sjt_dot1426 = 0;
    sjs_mat4* sjt_dot1427 = 0;
    sjs_mat4* sjt_dot1428 = 0;
    sjs_mat4* sjt_dot1429 = 0;
    sjs_mat4* sjt_dot1430 = 0;
    sjs_mat4* sjt_dot1431 = 0;
    sjs_mat4* sjt_dot1432 = 0;
    sjs_mat4* sjt_dot1433 = 0;
    sjs_mat4* sjt_dot1434 = 0;
    sjs_mat4* sjt_dot1435 = 0;
    sjs_mat4* sjt_dot1436 = 0;
    sjs_mat4* sjt_dot1437 = 0;
    sjs_mat4* sjt_dot1438 = 0;
    sjs_mat4* sjt_dot1439 = 0;
    sjs_mat4* sjt_dot1440 = 0;
    sjs_mat4* sjt_dot1441 = 0;
    sjs_mat4* sjt_dot1442 = 0;
    sjs_mat4* sjt_dot1443 = 0;
    float sjt_functionParam162;
    float sjt_math1671;
    float sjt_math1672;
    float sjt_math1673;
    float sjt_math1674;
    float sjt_math1675;
    float sjt_math1676;
    float sjt_math1677;
    float sjt_math1678;
    float sjt_math1679;
    float sjt_math1680;
    float sjt_math1681;
    float sjt_math1682;
    float sjt_math1683;
    float sjt_math1684;
    float sjt_math1685;
    float sjt_math1686;
    float sjt_math1687;
    float sjt_math1688;
    float sjt_math1689;
    float sjt_math1690;
    float sjt_math1691;
    float sjt_math1692;
    float sjt_math1693;
    float sjt_math1694;
    float sjt_math1695;
    float sjt_math1696;
    float sjt_math1697;
    float sjt_math1698;
    float sjt_math1699;
    float sjt_math1700;
    float sjt_math1701;
    float sjt_math1702;
    float sjt_math1703;
    float sjt_math1704;
    float sjt_math1705;
    float sjt_math1706;
    float sjt_math1707;
    float sjt_math1708;
    float sjt_math1709;
    float sjt_math1710;
    float sjt_math1711;
    float sjt_math1712;
    float sjt_math1713;
    float sjt_math1714;
    float sjt_math1715;
    float sjt_math1716;
    float sjt_math1717;
    float sjt_math1718;
    float sjt_math1719;
    float sjt_math1720;
    float sjt_math1721;
    float sjt_math1722;
    float sjt_math1723;
    float sjt_math1724;
    float sjt_math1725;
    float sjt_math1726;
    float sjt_math1727;
    float sjt_math1728;
    float sjt_math1729;
    float sjt_math1730;
    float sjt_math1731;
    float sjt_math1732;
    float sjt_math1733;
    float sjt_math1734;
    float sjt_math1735;
    float sjt_math1736;
    float sjt_math1737;
    float sjt_math1738;
    float sjt_math1739;
    float sjt_math1740;
    float sjt_math1741;
    float sjt_math1742;
    float sjt_math1743;
    float sjt_math1744;
    float sjt_math1745;
    float sjt_math1746;
    float sjt_math1747;
    float sjt_math1748;
    float sjt_math1749;
    float sjt_math1750;
    float sjt_math1751;
    float sjt_math1752;
    float sjt_math1753;
    float sjt_math1754;
    float sjt_math1755;
    float sjt_math1756;
    float sjt_math1757;
    float sjt_math1758;
    float sjt_math1759;
    float sjt_math1760;
    float sjt_math1761;
    float sjt_math1762;
    float sjt_math1763;
    float sjt_math1764;
    float sjt_math1765;
    float sjt_math1766;
    float sjt_math1767;
    float sjt_math1768;
    float sjt_math1769;
    float sjt_math1770;
    float sjt_math1771;
    float sjt_math1772;
    float sjt_math1773;
    float sjt_math1774;
    float sjt_math1775;
    float sjt_math1776;
    float sjt_math1777;
    float sjt_math1778;
    float sjt_math1779;
    float sjt_math1780;
    float sjt_math1781;
    float sjt_math1782;
    float sjt_math1783;
    float sjt_math1784;
    float sjt_math1785;
    float sjt_math1786;
    float sjt_math1787;
    float sjt_math1788;
    float sjt_math1789;
    float sjt_math1790;
    float sjt_math1791;
    float sjt_math1792;
    float sjt_math1793;
    float sjt_math1794;
    float sjt_math1795;
    float sjt_math1796;
    float sjt_math1797;
    float sjt_math1798;
    float sjt_math1799;
    float sjt_math1800;
    float sjt_math1801;
    float sjt_math1802;
    float sjt_math1803;
    float sjt_math1804;
    float sjt_math1805;
    float sjt_math1806;
    float sjt_math1807;
    float sjt_math1808;
    float sjt_math1809;
    float sjt_math1810;
    float sjt_math1811;
    float sjt_math1812;
    float sjt_math1813;
    float sjt_math1814;
    float sjt_math1815;
    float sjt_math1816;
    float sjt_math1817;
    float sjt_math1818;
    float sjt_math1819;
    float sjt_math1820;
    float sjt_math1821;
    float sjt_math1822;
    float sjt_math1823;
    float sjt_math1824;
    float sjt_math1825;
    float sjt_math1826;
    float sjt_math1827;
    float sjt_math1828;
    float sjt_math1829;
    float sjt_math1830;
    float sjt_math1831;
    float sjt_math1832;
    float sjt_math1833;
    float sjt_math1834;
    float sjt_math1835;
    float sjt_math1836;
    float sjt_math1837;
    float sjt_math1838;
    float sjt_math1839;
    float sjt_math1840;
    float sjt_math1841;
    float sjt_math1842;
    float sjt_math1843;
    float sjt_math1844;
    float sjt_math1845;
    float sjt_math1846;
    float sjt_math1847;
    float sjt_math1848;
    float sjt_math1849;
    float sjt_math1850;
    float sjt_math1851;
    float sjt_math1852;
    float sjt_math1853;
    float sjt_math1854;
    float sjt_math1855;
    float sjt_math1856;
    float sjt_math1857;
    float sjt_math1858;
    float sjt_math1859;
    float sjt_math1860;
    float sjt_math1861;
    float sjt_math1862;
    float sjt_math1863;
    float sjt_math1864;
    float sjt_math1865;
    float sjt_math1866;
    float sjt_math1867;
    float sjt_math1868;
    float sjt_math1869;
    float sjt_math1870;
    float sjt_math1871;
    float sjt_math1872;
    float sjt_math1873;
    float sjt_math1874;
    float sjt_math1875;
    float sjt_math1876;
    float sjt_math1877;
    float sjt_math1878;
    float sjt_math1879;
    float sjt_math1880;
    float sjt_math1881;
    float sjt_math1882;
    float sjt_math1883;
    float sjt_math1884;
    float sjt_math1885;
    float sjt_math1886;
    float sjt_math1887;
    float sjt_math1888;
    float sjt_math1889;
    float sjt_math1890;
    float sjt_math1891;
    float sjt_math1892;
    float sjt_math1893;
    float sjt_math1894;
    float sjt_math1895;
    float sjt_math1896;
    float sjt_math1897;
    float sjt_math1898;
    float sjt_math1899;
    float sjt_math1900;
    float sjt_math1901;
    float sjt_math1902;
    float sjt_math1903;
    float sjt_math1904;
    float sjt_math1905;
    float sjt_math1906;
    float sjt_math1907;
    float sjt_math1908;
    float sjt_math1909;
    float sjt_math1910;
    float sjt_math1911;
    float sjt_math1912;
    float sjt_math1913;
    float sjt_math1914;
    float sjt_math1915;
    float sjt_math1916;
    float sjt_math1917;
    float sjt_math1918;
    float sjt_math1919;
    float sjt_math1920;
    float sjt_math1921;
    float sjt_math1922;
    float sjt_math1923;
    float sjt_math1924;
    float sjt_math1925;
    float sjt_math1926;
    float sjt_math1927;
    float sjt_math1928;
    float sjt_math1929;
    float sjt_math1930;
    float sjt_math1931;
    float sjt_math1932;
    float sjt_math1933;
    float sjt_math1934;
    float sjt_math1935;
    float sjt_math1936;
    float sjt_math1937;
    float sjt_math1938;
    float sjt_math1939;
    float sjt_math1940;
    float sjt_math1941;
    float sjt_math1942;
    float sjt_math1943;
    float sjt_math1944;
    float sjt_math1945;
    float sjt_math1946;
    float sjt_math1947;
    float sjt_math1948;
    float sjt_math1949;
    float sjt_math1950;
    float sjt_math1951;
    float sjt_math1952;
    float sjt_math1953;
    float sjt_math1954;
    float sjt_math1955;
    float sjt_math1956;
    float sjt_math1957;
    float sjt_math1958;
    float sjt_math1959;
    float sjt_math1960;
    float sjt_math1961;
    float sjt_math1962;
    float sjt_math1963;
    float sjt_math1964;
    float sjt_math1965;
    float sjt_math1966;
    float sjt_math1967;
    float sjt_math1968;
    float sjt_math1969;
    float sjt_math1970;
    float sjt_math1971;
    float sjt_math1972;
    float sjt_math1973;
    float sjt_math1974;
    float sjt_math1975;
    float sjt_math1976;
    float sjt_math1977;
    float sjt_math1978;
    float sjt_math1979;
    float sjt_math1980;
    float sjt_math1981;
    float sjt_math1982;
    float sjt_math1983;
    float sjt_math1984;
    float sjt_math1985;
    float sjt_math1986;
    float sjt_math1987;
    float sjt_math1988;
    float sjt_math1989;
    float sjt_math1990;
    float sjt_math1991;
    float sjt_math1992;
    float sjt_math1993;
    float sjt_math1994;
    float sjt_math1995;
    float sjt_math1996;
    float sjt_math1997;
    float sjt_math1998;
    float sjt_math1999;
    float sjt_math2000;
    float sjt_math2001;
    float sjt_math2002;
    float sjt_math2003;
    float sjt_math2004;
    float sjt_math2005;
    float sjt_math2006;
    float sjt_math2007;
    float sjt_math2008;
    float sjt_math2009;
    float sjt_math2010;
    float sjt_math2011;
    float sjt_math2012;
    float sjt_math2013;
    float sjt_math2014;
    float sjt_math2015;
    float sjt_math2016;
    float sjt_math2017;
    float sjt_math2018;
    float sjt_math2019;
    float sjt_math2020;
    float sjt_math2021;
    float sjt_math2022;
    float sjt_math2023;
    float sjt_math2024;
    float sjt_math2025;
    float sjt_math2026;
    float sjt_math2027;
    float sjt_math2028;
    float sjt_math2029;
    float sjt_math2030;
    float sjt_math2031;
    float sjt_math2032;
    float sjt_math2033;
    float sjt_math2034;
    float sjt_math2035;
    float sjt_math2036;
    float sjt_math2037;
    float sjt_math2038;
    float sjt_math2039;
    float sjt_math2040;
    float sjt_math2041;
    float sjt_math2042;
    float sjt_math2043;
    float sjt_math2044;
    float sjt_math2045;
    float sjt_math2046;
    float sjt_math2047;
    float sjt_math2048;
    float sjt_math2049;
    float sjt_math2050;
    float sjt_math2051;
    float sjt_math2052;
    float sjt_math2053;
    float sjt_math2054;
    float sjt_math2055;
    float sjt_math2056;
    float sjt_math2057;
    float sjt_math2058;
    float sjt_math2059;
    float sjt_math2060;
    float sjt_math2061;
    float sjt_math2062;
    float sjt_math2063;
    float sjt_math2064;
    float sjt_math2065;
    float sjt_math2066;
    float sjt_math2067;
    float sjt_math2068;
    float sjt_math2069;
    float sjt_math2070;
    float sjt_math2071;
    float sjt_math2072;
    float sjt_math2073;
    float sjt_math2074;
    float sjt_math2075;
    float sjt_math2076;
    float sjt_math2077;
    float sjt_math2078;
    float sjt_math2079;
    float sjt_math2080;
    float sjt_math2081;
    float sjt_math2082;
    float sjt_math2083;
    float sjt_math2084;
    float sjt_math2085;
    float sjt_math2086;
    float sjt_math2087;
    float sjt_math2088;
    float sjt_math2089;
    float sjt_math2090;
    float sjt_math2091;
    float sjt_math2092;
    float sjt_math2093;
    float sjt_math2094;
    float sjt_math2095;
    float sjt_math2096;
    float sjt_math2097;
    float sjt_math2098;
    float sjt_math2099;
    float sjt_math2100;
    float sjt_math2101;
    float sjt_math2102;
    float sjt_math2103;
    float sjt_math2104;
    float sjt_math2105;
    float sjt_math2106;
    float sjt_math2107;
    float sjt_math2108;
    float sjt_math2109;
    float sjt_math2110;
    float sjt_math2111;
    float sjt_math2112;
    float sjt_math2113;
    float sjt_math2114;
    float sjt_math2115;
    float sjt_math2116;
    float sjt_math2117;
    float sjt_math2118;
    float sjt_math2119;
    float sjt_math2120;
    float sjt_math2121;
    float sjt_math2122;
    float sjt_math2123;
    float sjt_math2124;
    float sjt_math2125;
    float sjt_math2126;
    float sjt_math2127;
    float sjt_math2128;
    float sjt_math2129;
    float sjt_math2130;
    float sjt_math2131;
    float sjt_math2132;
    float sjt_math2133;
    float sjt_math2134;
    float sjt_math2135;
    float sjt_math2136;
    float sjt_math2137;
    float sjt_math2138;
    float sjt_math2139;
    float sjt_math2140;
    float sjt_math2141;
    float sjt_math2142;
    float sjt_math2143;
    float sjt_math2144;
    float sjt_math2145;
    float sjt_math2146;
    float sjt_math2147;
    float sjt_math2148;
    float sjt_math2149;
    float sjt_math2150;
    float sjt_math2151;
    float sjt_math2152;
    float sjt_math2153;
    float sjt_math2154;
    float sjt_math2155;
    float sjt_math2156;
    float sjt_math2157;
    float sjt_math2158;
    float sjt_math2159;
    float sjt_math2160;
    float sjt_math2161;
    float sjt_math2162;
    float sjt_math2163;
    float sjt_math2164;
    float sjt_math2165;
    float sjt_math2166;
    float sjt_math2167;
    float sjt_math2168;
    float sjt_math2169;
    float sjt_math2170;
    float sjt_math2171;
    float sjt_math2172;
    float sjt_math2173;
    float sjt_math2174;
    float sjt_math2175;
    float sjt_math2176;
    float sjt_math2177;
    float sjt_math2178;
    float sjt_math2179;
    float sjt_math2180;
    float sjt_math2181;
    float sjt_math2182;
    float sjt_math2183;
    float sjt_math2184;
    float sjt_math2185;
    float sjt_math2186;
    float sjt_math2187;
    float sjt_math2188;
    float sjt_math2189;
    float sjt_math2190;
    float sjt_math2191;
    float sjt_math2192;
    float sjt_math2193;
    float sjt_math2194;
    float sjt_math2195;
    float sjt_math2196;
    float sjt_math2197;
    float sjt_math2198;
    float sjt_math2199;
    float sjt_math2200;
    float sjt_math2201;
    float sjt_math2202;
    float sjt_math2203;
    float sjt_math2204;
    float sjt_math2205;
    float sjt_math2206;
    float sjt_math2207;
    float sjt_math2208;
    float sjt_math2209;
    float sjt_math2210;
    float sjt_math2211;
    float sjt_math2212;
    float sjt_math2213;
    float sjt_math2214;
    float sjt_math2215;
    float sjt_math2216;
    sjs_mat4* sjt_parent111 = 0;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
    sjt_dot1156 = _parent;
    sjt_math1683 = sjt_dot1156->m12;
    sjt_dot1157 = _parent;
    sjt_math1684 = sjt_dot1157->m23;
    sjt_math1681 = sjt_math1683 * sjt_math1684;
    sjt_dot1158 = _parent;
    sjt_math1682 = sjt_dot1158->m31;
    sjt_math1679 = sjt_math1681 * sjt_math1682;
    sjt_dot1159 = _parent;
    sjt_math1687 = sjt_dot1159->m13;
    sjt_dot1160 = _parent;
    sjt_math1688 = sjt_dot1160->m22;
    sjt_math1685 = sjt_math1687 * sjt_math1688;
    sjt_dot1161 = _parent;
    sjt_math1686 = sjt_dot1161->m31;
    sjt_math1680 = sjt_math1685 * sjt_math1686;
    sjt_math1677 = sjt_math1679 - sjt_math1680;
    sjt_dot1162 = _parent;
    sjt_math1691 = sjt_dot1162->m13;
    sjt_dot1163 = _parent;
    sjt_math1692 = sjt_dot1163->m21;
    sjt_math1689 = sjt_math1691 * sjt_math1692;
    sjt_dot1164 = _parent;
    sjt_math1690 = sjt_dot1164->m32;
    sjt_math1678 = sjt_math1689 * sjt_math1690;
    sjt_math1675 = sjt_math1677 + sjt_math1678;
    sjt_dot1165 = _parent;
    sjt_math1695 = sjt_dot1165->m11;
    sjt_dot1166 = _parent;
    sjt_math1696 = sjt_dot1166->m23;
    sjt_math1693 = sjt_math1695 * sjt_math1696;
    sjt_dot1167 = _parent;
    sjt_math1694 = sjt_dot1167->m32;
    sjt_math1676 = sjt_math1693 * sjt_math1694;
    sjt_math1673 = sjt_math1675 - sjt_math1676;
    sjt_dot1168 = _parent;
    sjt_math1699 = sjt_dot1168->m12;
    sjt_dot1169 = _parent;
    sjt_math1700 = sjt_dot1169->m21;
    sjt_math1697 = sjt_math1699 * sjt_math1700;
    sjt_dot1170 = _parent;
    sjt_math1698 = sjt_dot1170->m33;
    sjt_math1674 = sjt_math1697 * sjt_math1698;
    sjt_math1671 = sjt_math1673 - sjt_math1674;
    sjt_dot1171 = _parent;
    sjt_math1703 = sjt_dot1171->m11;
    sjt_dot1172 = _parent;
    sjt_math1704 = sjt_dot1172->m22;
    sjt_math1701 = sjt_math1703 * sjt_math1704;
    sjt_dot1173 = _parent;
    sjt_math1702 = sjt_dot1173->m33;
    sjt_math1672 = sjt_math1701 * sjt_math1702;
    sjv_t.m00 = sjt_math1671 + sjt_math1672;
    sjt_dot1174 = _parent;
    sjt_math1717 = sjt_dot1174->m03;
    sjt_dot1175 = _parent;
    sjt_math1718 = sjt_dot1175->m22;
    sjt_math1715 = sjt_math1717 * sjt_math1718;
    sjt_dot1176 = _parent;
    sjt_math1716 = sjt_dot1176->m31;
    sjt_math1713 = sjt_math1715 * sjt_math1716;
    sjt_dot1177 = _parent;
    sjt_math1721 = sjt_dot1177->m02;
    sjt_dot1178 = _parent;
    sjt_math1722 = sjt_dot1178->m23;
    sjt_math1719 = sjt_math1721 * sjt_math1722;
    sjt_dot1179 = _parent;
    sjt_math1720 = sjt_dot1179->m31;
    sjt_math1714 = sjt_math1719 * sjt_math1720;
    sjt_math1711 = sjt_math1713 - sjt_math1714;
    sjt_dot1180 = _parent;
    sjt_math1725 = sjt_dot1180->m03;
    sjt_dot1181 = _parent;
    sjt_math1726 = sjt_dot1181->m21;
    sjt_math1723 = sjt_math1725 * sjt_math1726;
    sjt_dot1182 = _parent;
    sjt_math1724 = sjt_dot1182->m32;
    sjt_math1712 = sjt_math1723 * sjt_math1724;
    sjt_math1709 = sjt_math1711 - sjt_math1712;
    sjt_dot1183 = _parent;
    sjt_math1729 = sjt_dot1183->m01;
    sjt_dot1184 = _parent;
    sjt_math1730 = sjt_dot1184->m23;
    sjt_math1727 = sjt_math1729 * sjt_math1730;
    sjt_dot1185 = _parent;
    sjt_math1728 = sjt_dot1185->m32;
    sjt_math1710 = sjt_math1727 * sjt_math1728;
    sjt_math1707 = sjt_math1709 + sjt_math1710;
    sjt_dot1186 = _parent;
    sjt_math1733 = sjt_dot1186->m02;
    sjt_dot1187 = _parent;
    sjt_math1734 = sjt_dot1187->m21;
    sjt_math1731 = sjt_math1733 * sjt_math1734;
    sjt_dot1188 = _parent;
    sjt_math1732 = sjt_dot1188->m33;
    sjt_math1708 = sjt_math1731 * sjt_math1732;
    sjt_math1705 = sjt_math1707 + sjt_math1708;
    sjt_dot1189 = _parent;
    sjt_math1737 = sjt_dot1189->m01;
    sjt_dot1190 = _parent;
    sjt_math1738 = sjt_dot1190->m22;
    sjt_math1735 = sjt_math1737 * sjt_math1738;
    sjt_dot1191 = _parent;
    sjt_math1736 = sjt_dot1191->m33;
    sjt_math1706 = sjt_math1735 * sjt_math1736;
    sjv_t.m01 = sjt_math1705 - sjt_math1706;
    sjt_dot1192 = _parent;
    sjt_math1751 = sjt_dot1192->m02;
    sjt_dot1193 = _parent;
    sjt_math1752 = sjt_dot1193->m13;
    sjt_math1749 = sjt_math1751 * sjt_math1752;
    sjt_dot1194 = _parent;
    sjt_math1750 = sjt_dot1194->m31;
    sjt_math1747 = sjt_math1749 * sjt_math1750;
    sjt_dot1195 = _parent;
    sjt_math1755 = sjt_dot1195->m03;
    sjt_dot1196 = _parent;
    sjt_math1756 = sjt_dot1196->m12;
    sjt_math1753 = sjt_math1755 * sjt_math1756;
    sjt_dot1197 = _parent;
    sjt_math1754 = sjt_dot1197->m31;
    sjt_math1748 = sjt_math1753 * sjt_math1754;
    sjt_math1745 = sjt_math1747 - sjt_math1748;
    sjt_dot1198 = _parent;
    sjt_math1759 = sjt_dot1198->m03;
    sjt_dot1199 = _parent;
    sjt_math1760 = sjt_dot1199->m11;
    sjt_math1757 = sjt_math1759 * sjt_math1760;
    sjt_dot1200 = _parent;
    sjt_math1758 = sjt_dot1200->m32;
    sjt_math1746 = sjt_math1757 * sjt_math1758;
    sjt_math1743 = sjt_math1745 + sjt_math1746;
    sjt_dot1201 = _parent;
    sjt_math1763 = sjt_dot1201->m01;
    sjt_dot1202 = _parent;
    sjt_math1764 = sjt_dot1202->m13;
    sjt_math1761 = sjt_math1763 * sjt_math1764;
    sjt_dot1203 = _parent;
    sjt_math1762 = sjt_dot1203->m32;
    sjt_math1744 = sjt_math1761 * sjt_math1762;
    sjt_math1741 = sjt_math1743 - sjt_math1744;
    sjt_dot1204 = _parent;
    sjt_math1767 = sjt_dot1204->m02;
    sjt_dot1205 = _parent;
    sjt_math1768 = sjt_dot1205->m11;
    sjt_math1765 = sjt_math1767 * sjt_math1768;
    sjt_dot1206 = _parent;
    sjt_math1766 = sjt_dot1206->m33;
    sjt_math1742 = sjt_math1765 * sjt_math1766;
    sjt_math1739 = sjt_math1741 - sjt_math1742;
    sjt_dot1207 = _parent;
    sjt_math1771 = sjt_dot1207->m01;
    sjt_dot1208 = _parent;
    sjt_math1772 = sjt_dot1208->m12;
    sjt_math1769 = sjt_math1771 * sjt_math1772;
    sjt_dot1209 = _parent;
    sjt_math1770 = sjt_dot1209->m33;
    sjt_math1740 = sjt_math1769 * sjt_math1770;
    sjv_t.m02 = sjt_math1739 + sjt_math1740;
    sjt_dot1210 = _parent;
    sjt_math1785 = sjt_dot1210->m03;
    sjt_dot1211 = _parent;
    sjt_math1786 = sjt_dot1211->m12;
    sjt_math1783 = sjt_math1785 * sjt_math1786;
    sjt_dot1212 = _parent;
    sjt_math1784 = sjt_dot1212->m21;
    sjt_math1781 = sjt_math1783 * sjt_math1784;
    sjt_dot1213 = _parent;
    sjt_math1789 = sjt_dot1213->m02;
    sjt_dot1214 = _parent;
    sjt_math1790 = sjt_dot1214->m13;
    sjt_math1787 = sjt_math1789 * sjt_math1790;
    sjt_dot1215 = _parent;
    sjt_math1788 = sjt_dot1215->m21;
    sjt_math1782 = sjt_math1787 * sjt_math1788;
    sjt_math1779 = sjt_math1781 - sjt_math1782;
    sjt_dot1216 = _parent;
    sjt_math1793 = sjt_dot1216->m03;
    sjt_dot1217 = _parent;
    sjt_math1794 = sjt_dot1217->m11;
    sjt_math1791 = sjt_math1793 * sjt_math1794;
    sjt_dot1218 = _parent;
    sjt_math1792 = sjt_dot1218->m22;
    sjt_math1780 = sjt_math1791 * sjt_math1792;
    sjt_math1777 = sjt_math1779 - sjt_math1780;
    sjt_dot1219 = _parent;
    sjt_math1797 = sjt_dot1219->m01;
    sjt_dot1220 = _parent;
    sjt_math1798 = sjt_dot1220->m13;
    sjt_math1795 = sjt_math1797 * sjt_math1798;
    sjt_dot1221 = _parent;
    sjt_math1796 = sjt_dot1221->m22;
    sjt_math1778 = sjt_math1795 * sjt_math1796;
    sjt_math1775 = sjt_math1777 + sjt_math1778;
    sjt_dot1222 = _parent;
    sjt_math1801 = sjt_dot1222->m02;
    sjt_dot1223 = _parent;
    sjt_math1802 = sjt_dot1223->m11;
    sjt_math1799 = sjt_math1801 * sjt_math1802;
    sjt_dot1224 = _parent;
    sjt_math1800 = sjt_dot1224->m23;
    sjt_math1776 = sjt_math1799 * sjt_math1800;
    sjt_math1773 = sjt_math1775 + sjt_math1776;
    sjt_dot1225 = _parent;
    sjt_math1805 = sjt_dot1225->m01;
    sjt_dot1226 = _parent;
    sjt_math1806 = sjt_dot1226->m12;
    sjt_math1803 = sjt_math1805 * sjt_math1806;
    sjt_dot1227 = _parent;
    sjt_math1804 = sjt_dot1227->m23;
    sjt_math1774 = sjt_math1803 * sjt_math1804;
    sjv_t.m03 = sjt_math1773 - sjt_math1774;
    sjt_dot1228 = _parent;
    sjt_math1819 = sjt_dot1228->m13;
    sjt_dot1229 = _parent;
    sjt_math1820 = sjt_dot1229->m22;
    sjt_math1817 = sjt_math1819 * sjt_math1820;
    sjt_dot1230 = _parent;
    sjt_math1818 = sjt_dot1230->m30;
    sjt_math1815 = sjt_math1817 * sjt_math1818;
    sjt_dot1231 = _parent;
    sjt_math1823 = sjt_dot1231->m12;
    sjt_dot1232 = _parent;
    sjt_math1824 = sjt_dot1232->m23;
    sjt_math1821 = sjt_math1823 * sjt_math1824;
    sjt_dot1233 = _parent;
    sjt_math1822 = sjt_dot1233->m30;
    sjt_math1816 = sjt_math1821 * sjt_math1822;
    sjt_math1813 = sjt_math1815 - sjt_math1816;
    sjt_dot1234 = _parent;
    sjt_math1827 = sjt_dot1234->m13;
    sjt_dot1235 = _parent;
    sjt_math1828 = sjt_dot1235->m20;
    sjt_math1825 = sjt_math1827 * sjt_math1828;
    sjt_dot1236 = _parent;
    sjt_math1826 = sjt_dot1236->m32;
    sjt_math1814 = sjt_math1825 * sjt_math1826;
    sjt_math1811 = sjt_math1813 - sjt_math1814;
    sjt_dot1237 = _parent;
    sjt_math1831 = sjt_dot1237->m10;
    sjt_dot1238 = _parent;
    sjt_math1832 = sjt_dot1238->m23;
    sjt_math1829 = sjt_math1831 * sjt_math1832;
    sjt_dot1239 = _parent;
    sjt_math1830 = sjt_dot1239->m32;
    sjt_math1812 = sjt_math1829 * sjt_math1830;
    sjt_math1809 = sjt_math1811 + sjt_math1812;
    sjt_dot1240 = _parent;
    sjt_math1835 = sjt_dot1240->m12;
    sjt_dot1241 = _parent;
    sjt_math1836 = sjt_dot1241->m20;
    sjt_math1833 = sjt_math1835 * sjt_math1836;
    sjt_dot1242 = _parent;
    sjt_math1834 = sjt_dot1242->m33;
    sjt_math1810 = sjt_math1833 * sjt_math1834;
    sjt_math1807 = sjt_math1809 + sjt_math1810;
    sjt_dot1243 = _parent;
    sjt_math1839 = sjt_dot1243->m10;
    sjt_dot1244 = _parent;
    sjt_math1840 = sjt_dot1244->m22;
    sjt_math1837 = sjt_math1839 * sjt_math1840;
    sjt_dot1245 = _parent;
    sjt_math1838 = sjt_dot1245->m33;
    sjt_math1808 = sjt_math1837 * sjt_math1838;
    sjv_t.m10 = sjt_math1807 - sjt_math1808;
    sjt_dot1246 = _parent;
    sjt_math1853 = sjt_dot1246->m02;
    sjt_dot1247 = _parent;
    sjt_math1854 = sjt_dot1247->m23;
    sjt_math1851 = sjt_math1853 * sjt_math1854;
    sjt_dot1248 = _parent;
    sjt_math1852 = sjt_dot1248->m30;
    sjt_math1849 = sjt_math1851 * sjt_math1852;
    sjt_dot1249 = _parent;
    sjt_math1857 = sjt_dot1249->m03;
    sjt_dot1250 = _parent;
    sjt_math1858 = sjt_dot1250->m22;
    sjt_math1855 = sjt_math1857 * sjt_math1858;
    sjt_dot1251 = _parent;
    sjt_math1856 = sjt_dot1251->m30;
    sjt_math1850 = sjt_math1855 * sjt_math1856;
    sjt_math1847 = sjt_math1849 - sjt_math1850;
    sjt_dot1252 = _parent;
    sjt_math1861 = sjt_dot1252->m03;
    sjt_dot1253 = _parent;
    sjt_math1862 = sjt_dot1253->m20;
    sjt_math1859 = sjt_math1861 * sjt_math1862;
    sjt_dot1254 = _parent;
    sjt_math1860 = sjt_dot1254->m32;
    sjt_math1848 = sjt_math1859 * sjt_math1860;
    sjt_math1845 = sjt_math1847 + sjt_math1848;
    sjt_dot1255 = _parent;
    sjt_math1865 = sjt_dot1255->m00;
    sjt_dot1256 = _parent;
    sjt_math1866 = sjt_dot1256->m23;
    sjt_math1863 = sjt_math1865 * sjt_math1866;
    sjt_dot1257 = _parent;
    sjt_math1864 = sjt_dot1257->m32;
    sjt_math1846 = sjt_math1863 * sjt_math1864;
    sjt_math1843 = sjt_math1845 - sjt_math1846;
    sjt_dot1258 = _parent;
    sjt_math1869 = sjt_dot1258->m02;
    sjt_dot1259 = _parent;
    sjt_math1870 = sjt_dot1259->m20;
    sjt_math1867 = sjt_math1869 * sjt_math1870;
    sjt_dot1260 = _parent;
    sjt_math1868 = sjt_dot1260->m33;
    sjt_math1844 = sjt_math1867 * sjt_math1868;
    sjt_math1841 = sjt_math1843 - sjt_math1844;
    sjt_dot1261 = _parent;
    sjt_math1873 = sjt_dot1261->m00;
    sjt_dot1262 = _parent;
    sjt_math1874 = sjt_dot1262->m22;
    sjt_math1871 = sjt_math1873 * sjt_math1874;
    sjt_dot1263 = _parent;
    sjt_math1872 = sjt_dot1263->m33;
    sjt_math1842 = sjt_math1871 * sjt_math1872;
    sjv_t.m11 = sjt_math1841 + sjt_math1842;
    sjt_dot1264 = _parent;
    sjt_math1887 = sjt_dot1264->m03;
    sjt_dot1265 = _parent;
    sjt_math1888 = sjt_dot1265->m12;
    sjt_math1885 = sjt_math1887 * sjt_math1888;
    sjt_dot1266 = _parent;
    sjt_math1886 = sjt_dot1266->m30;
    sjt_math1883 = sjt_math1885 * sjt_math1886;
    sjt_dot1267 = _parent;
    sjt_math1891 = sjt_dot1267->m02;
    sjt_dot1268 = _parent;
    sjt_math1892 = sjt_dot1268->m13;
    sjt_math1889 = sjt_math1891 * sjt_math1892;
    sjt_dot1269 = _parent;
    sjt_math1890 = sjt_dot1269->m30;
    sjt_math1884 = sjt_math1889 * sjt_math1890;
    sjt_math1881 = sjt_math1883 - sjt_math1884;
    sjt_dot1270 = _parent;
    sjt_math1895 = sjt_dot1270->m03;
    sjt_dot1271 = _parent;
    sjt_math1896 = sjt_dot1271->m10;
    sjt_math1893 = sjt_math1895 * sjt_math1896;
    sjt_dot1272 = _parent;
    sjt_math1894 = sjt_dot1272->m32;
    sjt_math1882 = sjt_math1893 * sjt_math1894;
    sjt_math1879 = sjt_math1881 - sjt_math1882;
    sjt_dot1273 = _parent;
    sjt_math1899 = sjt_dot1273->m00;
    sjt_dot1274 = _parent;
    sjt_math1900 = sjt_dot1274->m13;
    sjt_math1897 = sjt_math1899 * sjt_math1900;
    sjt_dot1275 = _parent;
    sjt_math1898 = sjt_dot1275->m32;
    sjt_math1880 = sjt_math1897 * sjt_math1898;
    sjt_math1877 = sjt_math1879 + sjt_math1880;
    sjt_dot1276 = _parent;
    sjt_math1903 = sjt_dot1276->m02;
    sjt_dot1277 = _parent;
    sjt_math1904 = sjt_dot1277->m10;
    sjt_math1901 = sjt_math1903 * sjt_math1904;
    sjt_dot1278 = _parent;
    sjt_math1902 = sjt_dot1278->m33;
    sjt_math1878 = sjt_math1901 * sjt_math1902;
    sjt_math1875 = sjt_math1877 + sjt_math1878;
    sjt_dot1279 = _parent;
    sjt_math1907 = sjt_dot1279->m00;
    sjt_dot1280 = _parent;
    sjt_math1908 = sjt_dot1280->m12;
    sjt_math1905 = sjt_math1907 * sjt_math1908;
    sjt_dot1281 = _parent;
    sjt_math1906 = sjt_dot1281->m33;
    sjt_math1876 = sjt_math1905 * sjt_math1906;
    sjv_t.m12 = sjt_math1875 - sjt_math1876;
    sjt_dot1282 = _parent;
    sjt_math1921 = sjt_dot1282->m02;
    sjt_dot1283 = _parent;
    sjt_math1922 = sjt_dot1283->m13;
    sjt_math1919 = sjt_math1921 * sjt_math1922;
    sjt_dot1284 = _parent;
    sjt_math1920 = sjt_dot1284->m20;
    sjt_math1917 = sjt_math1919 * sjt_math1920;
    sjt_dot1285 = _parent;
    sjt_math1925 = sjt_dot1285->m03;
    sjt_dot1286 = _parent;
    sjt_math1926 = sjt_dot1286->m12;
    sjt_math1923 = sjt_math1925 * sjt_math1926;
    sjt_dot1287 = _parent;
    sjt_math1924 = sjt_dot1287->m20;
    sjt_math1918 = sjt_math1923 * sjt_math1924;
    sjt_math1915 = sjt_math1917 - sjt_math1918;
    sjt_dot1288 = _parent;
    sjt_math1929 = sjt_dot1288->m03;
    sjt_dot1289 = _parent;
    sjt_math1930 = sjt_dot1289->m10;
    sjt_math1927 = sjt_math1929 * sjt_math1930;
    sjt_dot1290 = _parent;
    sjt_math1928 = sjt_dot1290->m22;
    sjt_math1916 = sjt_math1927 * sjt_math1928;
    sjt_math1913 = sjt_math1915 + sjt_math1916;
    sjt_dot1291 = _parent;
    sjt_math1933 = sjt_dot1291->m00;
    sjt_dot1292 = _parent;
    sjt_math1934 = sjt_dot1292->m13;
    sjt_math1931 = sjt_math1933 * sjt_math1934;
    sjt_dot1293 = _parent;
    sjt_math1932 = sjt_dot1293->m22;
    sjt_math1914 = sjt_math1931 * sjt_math1932;
    sjt_math1911 = sjt_math1913 - sjt_math1914;
    sjt_dot1294 = _parent;
    sjt_math1937 = sjt_dot1294->m02;
    sjt_dot1295 = _parent;
    sjt_math1938 = sjt_dot1295->m10;
    sjt_math1935 = sjt_math1937 * sjt_math1938;
    sjt_dot1296 = _parent;
    sjt_math1936 = sjt_dot1296->m23;
    sjt_math1912 = sjt_math1935 * sjt_math1936;
    sjt_math1909 = sjt_math1911 - sjt_math1912;
    sjt_dot1297 = _parent;
    sjt_math1941 = sjt_dot1297->m00;
    sjt_dot1298 = _parent;
    sjt_math1942 = sjt_dot1298->m12;
    sjt_math1939 = sjt_math1941 * sjt_math1942;
    sjt_dot1299 = _parent;
    sjt_math1940 = sjt_dot1299->m23;
    sjt_math1910 = sjt_math1939 * sjt_math1940;
    sjv_t.m13 = sjt_math1909 + sjt_math1910;
    sjt_dot1300 = _parent;
    sjt_math1955 = sjt_dot1300->m11;
    sjt_dot1301 = _parent;
    sjt_math1956 = sjt_dot1301->m23;
    sjt_math1953 = sjt_math1955 * sjt_math1956;
    sjt_dot1302 = _parent;
    sjt_math1954 = sjt_dot1302->m30;
    sjt_math1951 = sjt_math1953 * sjt_math1954;
    sjt_dot1303 = _parent;
    sjt_math1959 = sjt_dot1303->m13;
    sjt_dot1304 = _parent;
    sjt_math1960 = sjt_dot1304->m21;
    sjt_math1957 = sjt_math1959 * sjt_math1960;
    sjt_dot1305 = _parent;
    sjt_math1958 = sjt_dot1305->m30;
    sjt_math1952 = sjt_math1957 * sjt_math1958;
    sjt_math1949 = sjt_math1951 - sjt_math1952;
    sjt_dot1306 = _parent;
    sjt_math1963 = sjt_dot1306->m13;
    sjt_dot1307 = _parent;
    sjt_math1964 = sjt_dot1307->m20;
    sjt_math1961 = sjt_math1963 * sjt_math1964;
    sjt_dot1308 = _parent;
    sjt_math1962 = sjt_dot1308->m31;
    sjt_math1950 = sjt_math1961 * sjt_math1962;
    sjt_math1947 = sjt_math1949 + sjt_math1950;
    sjt_dot1309 = _parent;
    sjt_math1967 = sjt_dot1309->m10;
    sjt_dot1310 = _parent;
    sjt_math1968 = sjt_dot1310->m23;
    sjt_math1965 = sjt_math1967 * sjt_math1968;
    sjt_dot1311 = _parent;
    sjt_math1966 = sjt_dot1311->m31;
    sjt_math1948 = sjt_math1965 * sjt_math1966;
    sjt_math1945 = sjt_math1947 - sjt_math1948;
    sjt_dot1312 = _parent;
    sjt_math1971 = sjt_dot1312->m11;
    sjt_dot1313 = _parent;
    sjt_math1972 = sjt_dot1313->m20;
    sjt_math1969 = sjt_math1971 * sjt_math1972;
    sjt_dot1314 = _parent;
    sjt_math1970 = sjt_dot1314->m33;
    sjt_math1946 = sjt_math1969 * sjt_math1970;
    sjt_math1943 = sjt_math1945 - sjt_math1946;
    sjt_dot1315 = _parent;
    sjt_math1975 = sjt_dot1315->m10;
    sjt_dot1316 = _parent;
    sjt_math1976 = sjt_dot1316->m21;
    sjt_math1973 = sjt_math1975 * sjt_math1976;
    sjt_dot1317 = _parent;
    sjt_math1974 = sjt_dot1317->m33;
    sjt_math1944 = sjt_math1973 * sjt_math1974;
    sjv_t.m20 = sjt_math1943 + sjt_math1944;
    sjt_dot1318 = _parent;
    sjt_math1989 = sjt_dot1318->m03;
    sjt_dot1319 = _parent;
    sjt_math1990 = sjt_dot1319->m21;
    sjt_math1987 = sjt_math1989 * sjt_math1990;
    sjt_dot1320 = _parent;
    sjt_math1988 = sjt_dot1320->m30;
    sjt_math1985 = sjt_math1987 * sjt_math1988;
    sjt_dot1321 = _parent;
    sjt_math1993 = sjt_dot1321->m01;
    sjt_dot1322 = _parent;
    sjt_math1994 = sjt_dot1322->m23;
    sjt_math1991 = sjt_math1993 * sjt_math1994;
    sjt_dot1323 = _parent;
    sjt_math1992 = sjt_dot1323->m30;
    sjt_math1986 = sjt_math1991 * sjt_math1992;
    sjt_math1983 = sjt_math1985 - sjt_math1986;
    sjt_dot1324 = _parent;
    sjt_math1997 = sjt_dot1324->m03;
    sjt_dot1325 = _parent;
    sjt_math1998 = sjt_dot1325->m20;
    sjt_math1995 = sjt_math1997 * sjt_math1998;
    sjt_dot1326 = _parent;
    sjt_math1996 = sjt_dot1326->m31;
    sjt_math1984 = sjt_math1995 * sjt_math1996;
    sjt_math1981 = sjt_math1983 - sjt_math1984;
    sjt_dot1327 = _parent;
    sjt_math2001 = sjt_dot1327->m00;
    sjt_dot1328 = _parent;
    sjt_math2002 = sjt_dot1328->m23;
    sjt_math1999 = sjt_math2001 * sjt_math2002;
    sjt_dot1329 = _parent;
    sjt_math2000 = sjt_dot1329->m31;
    sjt_math1982 = sjt_math1999 * sjt_math2000;
    sjt_math1979 = sjt_math1981 + sjt_math1982;
    sjt_dot1330 = _parent;
    sjt_math2005 = sjt_dot1330->m01;
    sjt_dot1331 = _parent;
    sjt_math2006 = sjt_dot1331->m20;
    sjt_math2003 = sjt_math2005 * sjt_math2006;
    sjt_dot1332 = _parent;
    sjt_math2004 = sjt_dot1332->m33;
    sjt_math1980 = sjt_math2003 * sjt_math2004;
    sjt_math1977 = sjt_math1979 + sjt_math1980;
    sjt_dot1333 = _parent;
    sjt_math2009 = sjt_dot1333->m00;
    sjt_dot1334 = _parent;
    sjt_math2010 = sjt_dot1334->m21;
    sjt_math2007 = sjt_math2009 * sjt_math2010;
    sjt_dot1335 = _parent;
    sjt_math2008 = sjt_dot1335->m33;
    sjt_math1978 = sjt_math2007 * sjt_math2008;
    sjv_t.m21 = sjt_math1977 - sjt_math1978;
    sjt_dot1336 = _parent;
    sjt_math2023 = sjt_dot1336->m01;
    sjt_dot1337 = _parent;
    sjt_math2024 = sjt_dot1337->m13;
    sjt_math2021 = sjt_math2023 * sjt_math2024;
    sjt_dot1338 = _parent;
    sjt_math2022 = sjt_dot1338->m30;
    sjt_math2019 = sjt_math2021 * sjt_math2022;
    sjt_dot1339 = _parent;
    sjt_math2027 = sjt_dot1339->m03;
    sjt_dot1340 = _parent;
    sjt_math2028 = sjt_dot1340->m11;
    sjt_math2025 = sjt_math2027 * sjt_math2028;
    sjt_dot1341 = _parent;
    sjt_math2026 = sjt_dot1341->m30;
    sjt_math2020 = sjt_math2025 * sjt_math2026;
    sjt_math2017 = sjt_math2019 - sjt_math2020;
    sjt_dot1342 = _parent;
    sjt_math2031 = sjt_dot1342->m03;
    sjt_dot1343 = _parent;
    sjt_math2032 = sjt_dot1343->m10;
    sjt_math2029 = sjt_math2031 * sjt_math2032;
    sjt_dot1344 = _parent;
    sjt_math2030 = sjt_dot1344->m31;
    sjt_math2018 = sjt_math2029 * sjt_math2030;
    sjt_math2015 = sjt_math2017 + sjt_math2018;
    sjt_dot1345 = _parent;
    sjt_math2035 = sjt_dot1345->m00;
    sjt_dot1346 = _parent;
    sjt_math2036 = sjt_dot1346->m13;
    sjt_math2033 = sjt_math2035 * sjt_math2036;
    sjt_dot1347 = _parent;
    sjt_math2034 = sjt_dot1347->m31;
    sjt_math2016 = sjt_math2033 * sjt_math2034;
    sjt_math2013 = sjt_math2015 - sjt_math2016;
    sjt_dot1348 = _parent;
    sjt_math2039 = sjt_dot1348->m01;
    sjt_dot1349 = _parent;
    sjt_math2040 = sjt_dot1349->m10;
    sjt_math2037 = sjt_math2039 * sjt_math2040;
    sjt_dot1350 = _parent;
    sjt_math2038 = sjt_dot1350->m33;
    sjt_math2014 = sjt_math2037 * sjt_math2038;
    sjt_math2011 = sjt_math2013 - sjt_math2014;
    sjt_dot1351 = _parent;
    sjt_math2043 = sjt_dot1351->m00;
    sjt_dot1352 = _parent;
    sjt_math2044 = sjt_dot1352->m11;
    sjt_math2041 = sjt_math2043 * sjt_math2044;
    sjt_dot1353 = _parent;
    sjt_math2042 = sjt_dot1353->m33;
    sjt_math2012 = sjt_math2041 * sjt_math2042;
    sjv_t.m22 = sjt_math2011 + sjt_math2012;
    sjt_dot1354 = _parent;
    sjt_math2057 = sjt_dot1354->m03;
    sjt_dot1355 = _parent;
    sjt_math2058 = sjt_dot1355->m11;
    sjt_math2055 = sjt_math2057 * sjt_math2058;
    sjt_dot1356 = _parent;
    sjt_math2056 = sjt_dot1356->m20;
    sjt_math2053 = sjt_math2055 * sjt_math2056;
    sjt_dot1357 = _parent;
    sjt_math2061 = sjt_dot1357->m01;
    sjt_dot1358 = _parent;
    sjt_math2062 = sjt_dot1358->m13;
    sjt_math2059 = sjt_math2061 * sjt_math2062;
    sjt_dot1359 = _parent;
    sjt_math2060 = sjt_dot1359->m20;
    sjt_math2054 = sjt_math2059 * sjt_math2060;
    sjt_math2051 = sjt_math2053 - sjt_math2054;
    sjt_dot1360 = _parent;
    sjt_math2065 = sjt_dot1360->m03;
    sjt_dot1361 = _parent;
    sjt_math2066 = sjt_dot1361->m10;
    sjt_math2063 = sjt_math2065 * sjt_math2066;
    sjt_dot1362 = _parent;
    sjt_math2064 = sjt_dot1362->m21;
    sjt_math2052 = sjt_math2063 * sjt_math2064;
    sjt_math2049 = sjt_math2051 - sjt_math2052;
    sjt_dot1363 = _parent;
    sjt_math2069 = sjt_dot1363->m00;
    sjt_dot1364 = _parent;
    sjt_math2070 = sjt_dot1364->m13;
    sjt_math2067 = sjt_math2069 * sjt_math2070;
    sjt_dot1365 = _parent;
    sjt_math2068 = sjt_dot1365->m21;
    sjt_math2050 = sjt_math2067 * sjt_math2068;
    sjt_math2047 = sjt_math2049 + sjt_math2050;
    sjt_dot1366 = _parent;
    sjt_math2073 = sjt_dot1366->m01;
    sjt_dot1367 = _parent;
    sjt_math2074 = sjt_dot1367->m10;
    sjt_math2071 = sjt_math2073 * sjt_math2074;
    sjt_dot1368 = _parent;
    sjt_math2072 = sjt_dot1368->m23;
    sjt_math2048 = sjt_math2071 * sjt_math2072;
    sjt_math2045 = sjt_math2047 + sjt_math2048;
    sjt_dot1369 = _parent;
    sjt_math2077 = sjt_dot1369->m00;
    sjt_dot1370 = _parent;
    sjt_math2078 = sjt_dot1370->m11;
    sjt_math2075 = sjt_math2077 * sjt_math2078;
    sjt_dot1371 = _parent;
    sjt_math2076 = sjt_dot1371->m23;
    sjt_math2046 = sjt_math2075 * sjt_math2076;
    sjv_t.m23 = sjt_math2045 - sjt_math2046;
    sjt_dot1372 = _parent;
    sjt_math2091 = sjt_dot1372->m12;
    sjt_dot1373 = _parent;
    sjt_math2092 = sjt_dot1373->m21;
    sjt_math2089 = sjt_math2091 * sjt_math2092;
    sjt_dot1374 = _parent;
    sjt_math2090 = sjt_dot1374->m30;
    sjt_math2087 = sjt_math2089 * sjt_math2090;
    sjt_dot1375 = _parent;
    sjt_math2095 = sjt_dot1375->m11;
    sjt_dot1376 = _parent;
    sjt_math2096 = sjt_dot1376->m22;
    sjt_math2093 = sjt_math2095 * sjt_math2096;
    sjt_dot1377 = _parent;
    sjt_math2094 = sjt_dot1377->m30;
    sjt_math2088 = sjt_math2093 * sjt_math2094;
    sjt_math2085 = sjt_math2087 - sjt_math2088;
    sjt_dot1378 = _parent;
    sjt_math2099 = sjt_dot1378->m12;
    sjt_dot1379 = _parent;
    sjt_math2100 = sjt_dot1379->m20;
    sjt_math2097 = sjt_math2099 * sjt_math2100;
    sjt_dot1380 = _parent;
    sjt_math2098 = sjt_dot1380->m31;
    sjt_math2086 = sjt_math2097 * sjt_math2098;
    sjt_math2083 = sjt_math2085 - sjt_math2086;
    sjt_dot1381 = _parent;
    sjt_math2103 = sjt_dot1381->m10;
    sjt_dot1382 = _parent;
    sjt_math2104 = sjt_dot1382->m22;
    sjt_math2101 = sjt_math2103 * sjt_math2104;
    sjt_dot1383 = _parent;
    sjt_math2102 = sjt_dot1383->m31;
    sjt_math2084 = sjt_math2101 * sjt_math2102;
    sjt_math2081 = sjt_math2083 + sjt_math2084;
    sjt_dot1384 = _parent;
    sjt_math2107 = sjt_dot1384->m11;
    sjt_dot1385 = _parent;
    sjt_math2108 = sjt_dot1385->m20;
    sjt_math2105 = sjt_math2107 * sjt_math2108;
    sjt_dot1386 = _parent;
    sjt_math2106 = sjt_dot1386->m32;
    sjt_math2082 = sjt_math2105 * sjt_math2106;
    sjt_math2079 = sjt_math2081 + sjt_math2082;
    sjt_dot1387 = _parent;
    sjt_math2111 = sjt_dot1387->m10;
    sjt_dot1388 = _parent;
    sjt_math2112 = sjt_dot1388->m21;
    sjt_math2109 = sjt_math2111 * sjt_math2112;
    sjt_dot1389 = _parent;
    sjt_math2110 = sjt_dot1389->m32;
    sjt_math2080 = sjt_math2109 * sjt_math2110;
    sjv_t.m30 = sjt_math2079 - sjt_math2080;
    sjt_dot1390 = _parent;
    sjt_math2125 = sjt_dot1390->m01;
    sjt_dot1391 = _parent;
    sjt_math2126 = sjt_dot1391->m22;
    sjt_math2123 = sjt_math2125 * sjt_math2126;
    sjt_dot1392 = _parent;
    sjt_math2124 = sjt_dot1392->m30;
    sjt_math2121 = sjt_math2123 * sjt_math2124;
    sjt_dot1393 = _parent;
    sjt_math2129 = sjt_dot1393->m02;
    sjt_dot1394 = _parent;
    sjt_math2130 = sjt_dot1394->m21;
    sjt_math2127 = sjt_math2129 * sjt_math2130;
    sjt_dot1395 = _parent;
    sjt_math2128 = sjt_dot1395->m30;
    sjt_math2122 = sjt_math2127 * sjt_math2128;
    sjt_math2119 = sjt_math2121 - sjt_math2122;
    sjt_dot1396 = _parent;
    sjt_math2133 = sjt_dot1396->m02;
    sjt_dot1397 = _parent;
    sjt_math2134 = sjt_dot1397->m20;
    sjt_math2131 = sjt_math2133 * sjt_math2134;
    sjt_dot1398 = _parent;
    sjt_math2132 = sjt_dot1398->m31;
    sjt_math2120 = sjt_math2131 * sjt_math2132;
    sjt_math2117 = sjt_math2119 + sjt_math2120;
    sjt_dot1399 = _parent;
    sjt_math2137 = sjt_dot1399->m00;
    sjt_dot1400 = _parent;
    sjt_math2138 = sjt_dot1400->m22;
    sjt_math2135 = sjt_math2137 * sjt_math2138;
    sjt_dot1401 = _parent;
    sjt_math2136 = sjt_dot1401->m31;
    sjt_math2118 = sjt_math2135 * sjt_math2136;
    sjt_math2115 = sjt_math2117 - sjt_math2118;
    sjt_dot1402 = _parent;
    sjt_math2141 = sjt_dot1402->m01;
    sjt_dot1403 = _parent;
    sjt_math2142 = sjt_dot1403->m20;
    sjt_math2139 = sjt_math2141 * sjt_math2142;
    sjt_dot1404 = _parent;
    sjt_math2140 = sjt_dot1404->m32;
    sjt_math2116 = sjt_math2139 * sjt_math2140;
    sjt_math2113 = sjt_math2115 - sjt_math2116;
    sjt_dot1405 = _parent;
    sjt_math2145 = sjt_dot1405->m00;
    sjt_dot1406 = _parent;
    sjt_math2146 = sjt_dot1406->m21;
    sjt_math2143 = sjt_math2145 * sjt_math2146;
    sjt_dot1407 = _parent;
    sjt_math2144 = sjt_dot1407->m32;
    sjt_math2114 = sjt_math2143 * sjt_math2144;
    sjv_t.m31 = sjt_math2113 + sjt_math2114;
    sjt_dot1408 = _parent;
    sjt_math2159 = sjt_dot1408->m02;
    sjt_dot1409 = _parent;
    sjt_math2160 = sjt_dot1409->m11;
    sjt_math2157 = sjt_math2159 * sjt_math2160;
    sjt_dot1410 = _parent;
    sjt_math2158 = sjt_dot1410->m30;
    sjt_math2155 = sjt_math2157 * sjt_math2158;
    sjt_dot1411 = _parent;
    sjt_math2163 = sjt_dot1411->m01;
    sjt_dot1412 = _parent;
    sjt_math2164 = sjt_dot1412->m12;
    sjt_math2161 = sjt_math2163 * sjt_math2164;
    sjt_dot1413 = _parent;
    sjt_math2162 = sjt_dot1413->m30;
    sjt_math2156 = sjt_math2161 * sjt_math2162;
    sjt_math2153 = sjt_math2155 - sjt_math2156;
    sjt_dot1414 = _parent;
    sjt_math2167 = sjt_dot1414->m02;
    sjt_dot1415 = _parent;
    sjt_math2168 = sjt_dot1415->m10;
    sjt_math2165 = sjt_math2167 * sjt_math2168;
    sjt_dot1416 = _parent;
    sjt_math2166 = sjt_dot1416->m31;
    sjt_math2154 = sjt_math2165 * sjt_math2166;
    sjt_math2151 = sjt_math2153 - sjt_math2154;
    sjt_dot1417 = _parent;
    sjt_math2171 = sjt_dot1417->m00;
    sjt_dot1418 = _parent;
    sjt_math2172 = sjt_dot1418->m12;
    sjt_math2169 = sjt_math2171 * sjt_math2172;
    sjt_dot1419 = _parent;
    sjt_math2170 = sjt_dot1419->m31;
    sjt_math2152 = sjt_math2169 * sjt_math2170;
    sjt_math2149 = sjt_math2151 + sjt_math2152;
    sjt_dot1420 = _parent;
    sjt_math2175 = sjt_dot1420->m01;
    sjt_dot1421 = _parent;
    sjt_math2176 = sjt_dot1421->m10;
    sjt_math2173 = sjt_math2175 * sjt_math2176;
    sjt_dot1422 = _parent;
    sjt_math2174 = sjt_dot1422->m32;
    sjt_math2150 = sjt_math2173 * sjt_math2174;
    sjt_math2147 = sjt_math2149 + sjt_math2150;
    sjt_dot1423 = _parent;
    sjt_math2179 = sjt_dot1423->m00;
    sjt_dot1424 = _parent;
    sjt_math2180 = sjt_dot1424->m11;
    sjt_math2177 = sjt_math2179 * sjt_math2180;
    sjt_dot1425 = _parent;
    sjt_math2178 = sjt_dot1425->m32;
    sjt_math2148 = sjt_math2177 * sjt_math2178;
    sjv_t.m32 = sjt_math2147 - sjt_math2148;
    sjt_dot1426 = _parent;
    sjt_math2193 = sjt_dot1426->m01;
    sjt_dot1427 = _parent;
    sjt_math2194 = sjt_dot1427->m12;
    sjt_math2191 = sjt_math2193 * sjt_math2194;
    sjt_dot1428 = _parent;
    sjt_math2192 = sjt_dot1428->m20;
    sjt_math2189 = sjt_math2191 * sjt_math2192;
    sjt_dot1429 = _parent;
    sjt_math2197 = sjt_dot1429->m02;
    sjt_dot1430 = _parent;
    sjt_math2198 = sjt_dot1430->m11;
    sjt_math2195 = sjt_math2197 * sjt_math2198;
    sjt_dot1431 = _parent;
    sjt_math2196 = sjt_dot1431->m20;
    sjt_math2190 = sjt_math2195 * sjt_math2196;
    sjt_math2187 = sjt_math2189 - sjt_math2190;
    sjt_dot1432 = _parent;
    sjt_math2201 = sjt_dot1432->m02;
    sjt_dot1433 = _parent;
    sjt_math2202 = sjt_dot1433->m10;
    sjt_math2199 = sjt_math2201 * sjt_math2202;
    sjt_dot1434 = _parent;
    sjt_math2200 = sjt_dot1434->m21;
    sjt_math2188 = sjt_math2199 * sjt_math2200;
    sjt_math2185 = sjt_math2187 + sjt_math2188;
    sjt_dot1435 = _parent;
    sjt_math2205 = sjt_dot1435->m00;
    sjt_dot1436 = _parent;
    sjt_math2206 = sjt_dot1436->m12;
    sjt_math2203 = sjt_math2205 * sjt_math2206;
    sjt_dot1437 = _parent;
    sjt_math2204 = sjt_dot1437->m21;
    sjt_math2186 = sjt_math2203 * sjt_math2204;
    sjt_math2183 = sjt_math2185 - sjt_math2186;
    sjt_dot1438 = _parent;
    sjt_math2209 = sjt_dot1438->m01;
    sjt_dot1439 = _parent;
    sjt_math2210 = sjt_dot1439->m10;
    sjt_math2207 = sjt_math2209 * sjt_math2210;
    sjt_dot1440 = _parent;
    sjt_math2208 = sjt_dot1440->m22;
    sjt_math2184 = sjt_math2207 * sjt_math2208;
    sjt_math2181 = sjt_math2183 - sjt_math2184;
    sjt_dot1441 = _parent;
    sjt_math2213 = sjt_dot1441->m00;
    sjt_dot1442 = _parent;
    sjt_math2214 = sjt_dot1442->m11;
    sjt_math2211 = sjt_math2213 * sjt_math2214;
    sjt_dot1443 = _parent;
    sjt_math2212 = sjt_dot1443->m22;
    sjt_math2182 = sjt_math2211 * sjt_math2212;
    sjv_t.m33 = sjt_math2181 + sjt_math2182;
    sjf_mat4(&sjv_t);
    sjt_parent111 = &sjv_t;
    sjt_math2215 = 1.0f;
    sjf_mat4_determinant(_parent, &sjt_math2216);
    sjt_functionParam162 = sjt_math2215 / sjt_math2216;
    sjf_mat4_multiplyf32_heap(sjt_parent111, sjt_functionParam162, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
;
}

void sjf_mat4_lookatlh(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return) {
    sjs_vec3 sjt_call16 = { -1 };
    sjs_vec3* sjt_dot259 = 0;
    sjs_vec3* sjt_dot260 = 0;
    sjs_vec3* sjt_dot261 = 0;
    sjs_vec3* sjt_dot262 = 0;
    sjs_vec3* sjt_dot263 = 0;
    sjs_vec3* sjt_dot264 = 0;
    sjs_vec3* sjt_dot265 = 0;
    sjs_vec3* sjt_dot266 = 0;
    sjs_vec3* sjt_dot267 = 0;
    sjs_vec3* sjt_functionParam72 = 0;
    sjs_vec3* sjt_functionParam75 = 0;
    sjs_vec3* sjt_functionParam76 = 0;
    sjs_vec3* sjt_functionParam77 = 0;
    sjs_vec3* sjt_functionParam78 = 0;
    sjs_vec3* sjt_functionParam79 = 0;
    float sjt_math247;
    float sjt_math248;
    float sjt_math259;
    float sjt_math260;
    float sjt_math261;
    float sjt_math262;
    sjs_vec3* sjt_parent55 = 0;
    sjs_vec3* sjt_parent56 = 0;
    sjs_vec3* sjt_parent57 = 0;
    sjs_vec3* sjt_parent58 = 0;
    sjs_vec3* sjt_parent59 = 0;
    sjs_vec3* sjt_parent60 = 0;
    sjs_vec3* sjt_parent61 = 0;
    sjs_vec3* sjt_parent62 = 0;
    sjs_vec3 sjv_temp = { -1 };
    sjs_vec3 sjv_xaxis = { -1 };
    sjs_vec3 sjv_yaxis = { -1 };
    sjs_vec3 sjv_zaxis = { -1 };

    sjt_parent55 = target;
    sjt_functionParam72 = camera;
    sjf_vec3_subtract(sjt_parent55, sjt_functionParam72, &sjv_temp);
    sjt_parent56 = &sjv_temp;
    sjf_vec3_normalize(sjt_parent56, &sjv_zaxis);
    sjt_parent58 = up;
    sjt_functionParam75 = &sjv_zaxis;
    sjf_vec3_cross(sjt_parent58, sjt_functionParam75, &sjt_call16);
    sjt_parent57 = &sjt_call16;
    sjf_vec3_normalize(sjt_parent57, &sjv_xaxis);
    sjt_parent59 = &sjv_zaxis;
    sjt_functionParam76 = &sjv_xaxis;
    sjf_vec3_cross(sjt_parent59, sjt_functionParam76, &sjv_yaxis);
    _return->_refCount = 1;
    sjt_dot259 = &sjv_xaxis;
    _return->m00 = sjt_dot259->x;
    sjt_dot260 = &sjv_yaxis;
    _return->m01 = sjt_dot260->x;
    sjt_dot261 = &sjv_zaxis;
    _return->m02 = sjt_dot261->x;
    _return->m03 = 0.0f;
    sjt_dot262 = &sjv_xaxis;
    _return->m10 = sjt_dot262->y;
    sjt_dot263 = &sjv_yaxis;
    _return->m11 = sjt_dot263->y;
    sjt_dot264 = &sjv_zaxis;
    _return->m12 = sjt_dot264->y;
    _return->m13 = 0.0f;
    sjt_dot265 = &sjv_xaxis;
    _return->m20 = sjt_dot265->z;
    sjt_dot266 = &sjv_yaxis;
    _return->m21 = sjt_dot266->z;
    sjt_dot267 = &sjv_zaxis;
    _return->m22 = sjt_dot267->z;
    _return->m23 = 0.0f;
    sjt_math247 = 0.0f;
    sjt_parent60 = &sjv_xaxis;
    sjt_functionParam77 = camera;
    sjf_vec3_dot(sjt_parent60, sjt_functionParam77, &sjt_math248);
    _return->m30 = sjt_math247 - sjt_math248;
    sjt_math259 = 0.0f;
    sjt_parent61 = &sjv_yaxis;
    sjt_functionParam78 = camera;
    sjf_vec3_dot(sjt_parent61, sjt_functionParam78, &sjt_math260);
    _return->m31 = sjt_math259 - sjt_math260;
    sjt_math261 = 0.0f;
    sjt_parent62 = &sjv_zaxis;
    sjt_functionParam79 = camera;
    sjf_vec3_dot(sjt_parent62, sjt_functionParam79, &sjt_math262);
    _return->m32 = sjt_math261 - sjt_math262;
    _return->m33 = 1.0f;
    sjf_mat4(_return);

    if (sjt_call16._refCount == 1) { sjf_vec3_destroy(&sjt_call16); }
;
    if (sjv_temp._refCount == 1) { sjf_vec3_destroy(&sjv_temp); }
;
    if (sjv_xaxis._refCount == 1) { sjf_vec3_destroy(&sjv_xaxis); }
;
    if (sjv_yaxis._refCount == 1) { sjf_vec3_destroy(&sjv_yaxis); }
;
    if (sjv_zaxis._refCount == 1) { sjf_vec3_destroy(&sjv_zaxis); }
;
}

void sjf_mat4_lookatlh_heap(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4** _return) {
    sjs_vec3 sjt_call17 = { -1 };
    sjs_vec3* sjt_dot274 = 0;
    sjs_vec3* sjt_dot275 = 0;
    sjs_vec3* sjt_dot276 = 0;
    sjs_vec3* sjt_dot277 = 0;
    sjs_vec3* sjt_dot278 = 0;
    sjs_vec3* sjt_dot279 = 0;
    sjs_vec3* sjt_dot280 = 0;
    sjs_vec3* sjt_dot281 = 0;
    sjs_vec3* sjt_dot282 = 0;
    sjs_vec3* sjt_functionParam80 = 0;
    sjs_vec3* sjt_functionParam81 = 0;
    sjs_vec3* sjt_functionParam82 = 0;
    sjs_vec3* sjt_functionParam83 = 0;
    sjs_vec3* sjt_functionParam84 = 0;
    sjs_vec3* sjt_functionParam85 = 0;
    float sjt_math263;
    float sjt_math264;
    float sjt_math265;
    float sjt_math266;
    float sjt_math267;
    float sjt_math268;
    sjs_vec3* sjt_parent63 = 0;
    sjs_vec3* sjt_parent64 = 0;
    sjs_vec3* sjt_parent65 = 0;
    sjs_vec3* sjt_parent66 = 0;
    sjs_vec3* sjt_parent67 = 0;
    sjs_vec3* sjt_parent68 = 0;
    sjs_vec3* sjt_parent69 = 0;
    sjs_vec3* sjt_parent70 = 0;
    sjs_vec3 sjv_temp = { -1 };
    sjs_vec3 sjv_xaxis = { -1 };
    sjs_vec3 sjv_yaxis = { -1 };
    sjs_vec3 sjv_zaxis = { -1 };

    sjt_parent63 = target;
    sjt_functionParam80 = camera;
    sjf_vec3_subtract(sjt_parent63, sjt_functionParam80, &sjv_temp);
    sjt_parent64 = &sjv_temp;
    sjf_vec3_normalize(sjt_parent64, &sjv_zaxis);
    sjt_parent66 = up;
    sjt_functionParam81 = &sjv_zaxis;
    sjf_vec3_cross(sjt_parent66, sjt_functionParam81, &sjt_call17);
    sjt_parent65 = &sjt_call17;
    sjf_vec3_normalize(sjt_parent65, &sjv_xaxis);
    sjt_parent67 = &sjv_zaxis;
    sjt_functionParam82 = &sjv_xaxis;
    sjf_vec3_cross(sjt_parent67, sjt_functionParam82, &sjv_yaxis);
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot274 = &sjv_xaxis;
    (*_return)->m00 = sjt_dot274->x;
    sjt_dot275 = &sjv_yaxis;
    (*_return)->m01 = sjt_dot275->x;
    sjt_dot276 = &sjv_zaxis;
    (*_return)->m02 = sjt_dot276->x;
    (*_return)->m03 = 0.0f;
    sjt_dot277 = &sjv_xaxis;
    (*_return)->m10 = sjt_dot277->y;
    sjt_dot278 = &sjv_yaxis;
    (*_return)->m11 = sjt_dot278->y;
    sjt_dot279 = &sjv_zaxis;
    (*_return)->m12 = sjt_dot279->y;
    (*_return)->m13 = 0.0f;
    sjt_dot280 = &sjv_xaxis;
    (*_return)->m20 = sjt_dot280->z;
    sjt_dot281 = &sjv_yaxis;
    (*_return)->m21 = sjt_dot281->z;
    sjt_dot282 = &sjv_zaxis;
    (*_return)->m22 = sjt_dot282->z;
    (*_return)->m23 = 0.0f;
    sjt_math263 = 0.0f;
    sjt_parent68 = &sjv_xaxis;
    sjt_functionParam83 = camera;
    sjf_vec3_dot(sjt_parent68, sjt_functionParam83, &sjt_math264);
    (*_return)->m30 = sjt_math263 - sjt_math264;
    sjt_math265 = 0.0f;
    sjt_parent69 = &sjv_yaxis;
    sjt_functionParam84 = camera;
    sjf_vec3_dot(sjt_parent69, sjt_functionParam84, &sjt_math266);
    (*_return)->m31 = sjt_math265 - sjt_math266;
    sjt_math267 = 0.0f;
    sjt_parent70 = &sjv_zaxis;
    sjt_functionParam85 = camera;
    sjf_vec3_dot(sjt_parent70, sjt_functionParam85, &sjt_math268);
    (*_return)->m32 = sjt_math267 - sjt_math268;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));

    if (sjt_call17._refCount == 1) { sjf_vec3_destroy(&sjt_call17); }
;
    if (sjv_temp._refCount == 1) { sjf_vec3_destroy(&sjv_temp); }
;
    if (sjv_xaxis._refCount == 1) { sjf_vec3_destroy(&sjv_xaxis); }
;
    if (sjv_yaxis._refCount == 1) { sjf_vec3_destroy(&sjv_yaxis); }
;
    if (sjv_zaxis._refCount == 1) { sjf_vec3_destroy(&sjv_zaxis); }
;
}

void sjf_mat4_multiply(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4* _return) {
    sjs_mat4* sjt_dot410 = 0;
    sjs_mat4* sjt_dot411 = 0;
    sjs_mat4* sjt_dot412 = 0;
    sjs_mat4* sjt_dot413 = 0;
    sjs_mat4* sjt_dot414 = 0;
    sjs_mat4* sjt_dot415 = 0;
    sjs_mat4* sjt_dot416 = 0;
    sjs_mat4* sjt_dot417 = 0;
    sjs_mat4* sjt_dot418 = 0;
    sjs_mat4* sjt_dot419 = 0;
    sjs_mat4* sjt_dot420 = 0;
    sjs_mat4* sjt_dot421 = 0;
    sjs_mat4* sjt_dot422 = 0;
    sjs_mat4* sjt_dot423 = 0;
    sjs_mat4* sjt_dot424 = 0;
    sjs_mat4* sjt_dot425 = 0;
    sjs_mat4* sjt_dot426 = 0;
    sjs_mat4* sjt_dot427 = 0;
    sjs_mat4* sjt_dot428 = 0;
    sjs_mat4* sjt_dot429 = 0;
    sjs_mat4* sjt_dot430 = 0;
    sjs_mat4* sjt_dot431 = 0;
    sjs_mat4* sjt_dot432 = 0;
    sjs_mat4* sjt_dot433 = 0;
    sjs_mat4* sjt_dot434 = 0;
    sjs_mat4* sjt_dot435 = 0;
    sjs_mat4* sjt_dot436 = 0;
    sjs_mat4* sjt_dot437 = 0;
    sjs_mat4* sjt_dot438 = 0;
    sjs_mat4* sjt_dot439 = 0;
    sjs_mat4* sjt_dot440 = 0;
    sjs_mat4* sjt_dot441 = 0;
    sjs_mat4* sjt_dot442 = 0;
    sjs_mat4* sjt_dot443 = 0;
    sjs_mat4* sjt_dot444 = 0;
    sjs_mat4* sjt_dot445 = 0;
    sjs_mat4* sjt_dot446 = 0;
    sjs_mat4* sjt_dot447 = 0;
    sjs_mat4* sjt_dot448 = 0;
    sjs_mat4* sjt_dot449 = 0;
    sjs_mat4* sjt_dot450 = 0;
    sjs_mat4* sjt_dot451 = 0;
    sjs_mat4* sjt_dot452 = 0;
    sjs_mat4* sjt_dot453 = 0;
    sjs_mat4* sjt_dot454 = 0;
    sjs_mat4* sjt_dot455 = 0;
    sjs_mat4* sjt_dot456 = 0;
    sjs_mat4* sjt_dot457 = 0;
    sjs_mat4* sjt_dot458 = 0;
    sjs_mat4* sjt_dot459 = 0;
    sjs_mat4* sjt_dot460 = 0;
    sjs_mat4* sjt_dot461 = 0;
    sjs_mat4* sjt_dot462 = 0;
    sjs_mat4* sjt_dot463 = 0;
    sjs_mat4* sjt_dot464 = 0;
    sjs_mat4* sjt_dot465 = 0;
    sjs_mat4* sjt_dot466 = 0;
    sjs_mat4* sjt_dot467 = 0;
    sjs_mat4* sjt_dot468 = 0;
    sjs_mat4* sjt_dot469 = 0;
    sjs_mat4* sjt_dot470 = 0;
    sjs_mat4* sjt_dot471 = 0;
    sjs_mat4* sjt_dot472 = 0;
    sjs_mat4* sjt_dot473 = 0;
    sjs_mat4* sjt_dot474 = 0;
    sjs_mat4* sjt_dot475 = 0;
    sjs_mat4* sjt_dot476 = 0;
    sjs_mat4* sjt_dot477 = 0;
    sjs_mat4* sjt_dot478 = 0;
    sjs_mat4* sjt_dot479 = 0;
    sjs_mat4* sjt_dot480 = 0;
    sjs_mat4* sjt_dot481 = 0;
    sjs_mat4* sjt_dot482 = 0;
    sjs_mat4* sjt_dot483 = 0;
    sjs_mat4* sjt_dot484 = 0;
    sjs_mat4* sjt_dot485 = 0;
    sjs_mat4* sjt_dot486 = 0;
    sjs_mat4* sjt_dot487 = 0;
    sjs_mat4* sjt_dot488 = 0;
    sjs_mat4* sjt_dot489 = 0;
    sjs_mat4* sjt_dot490 = 0;
    sjs_mat4* sjt_dot491 = 0;
    sjs_mat4* sjt_dot492 = 0;
    sjs_mat4* sjt_dot493 = 0;
    sjs_mat4* sjt_dot494 = 0;
    sjs_mat4* sjt_dot495 = 0;
    sjs_mat4* sjt_dot496 = 0;
    sjs_mat4* sjt_dot497 = 0;
    sjs_mat4* sjt_dot498 = 0;
    sjs_mat4* sjt_dot499 = 0;
    sjs_mat4* sjt_dot500 = 0;
    sjs_mat4* sjt_dot501 = 0;
    sjs_mat4* sjt_dot502 = 0;
    sjs_mat4* sjt_dot503 = 0;
    sjs_mat4* sjt_dot504 = 0;
    sjs_mat4* sjt_dot505 = 0;
    sjs_mat4* sjt_dot506 = 0;
    sjs_mat4* sjt_dot507 = 0;
    sjs_mat4* sjt_dot508 = 0;
    sjs_mat4* sjt_dot509 = 0;
    sjs_mat4* sjt_dot510 = 0;
    sjs_mat4* sjt_dot511 = 0;
    sjs_mat4* sjt_dot512 = 0;
    sjs_mat4* sjt_dot513 = 0;
    sjs_mat4* sjt_dot514 = 0;
    sjs_mat4* sjt_dot515 = 0;
    sjs_mat4* sjt_dot516 = 0;
    sjs_mat4* sjt_dot517 = 0;
    sjs_mat4* sjt_dot518 = 0;
    sjs_mat4* sjt_dot519 = 0;
    sjs_mat4* sjt_dot520 = 0;
    sjs_mat4* sjt_dot521 = 0;
    sjs_mat4* sjt_dot522 = 0;
    sjs_mat4* sjt_dot523 = 0;
    sjs_mat4* sjt_dot524 = 0;
    sjs_mat4* sjt_dot525 = 0;
    sjs_mat4* sjt_dot526 = 0;
    sjs_mat4* sjt_dot527 = 0;
    sjs_mat4* sjt_dot528 = 0;
    sjs_mat4* sjt_dot529 = 0;
    sjs_mat4* sjt_dot530 = 0;
    sjs_mat4* sjt_dot531 = 0;
    sjs_mat4* sjt_dot532 = 0;
    sjs_mat4* sjt_dot533 = 0;
    sjs_mat4* sjt_dot534 = 0;
    sjs_mat4* sjt_dot535 = 0;
    sjs_mat4* sjt_dot536 = 0;
    sjs_mat4* sjt_dot537 = 0;
    float sjt_math415;
    float sjt_math416;
    float sjt_math417;
    float sjt_math418;
    float sjt_math419;
    float sjt_math420;
    float sjt_math421;
    float sjt_math422;
    float sjt_math423;
    float sjt_math424;
    float sjt_math425;
    float sjt_math426;
    float sjt_math427;
    float sjt_math428;
    float sjt_math429;
    float sjt_math430;
    float sjt_math431;
    float sjt_math432;
    float sjt_math433;
    float sjt_math434;
    float sjt_math435;
    float sjt_math436;
    float sjt_math437;
    float sjt_math438;
    float sjt_math439;
    float sjt_math440;
    float sjt_math441;
    float sjt_math442;
    float sjt_math443;
    float sjt_math444;
    float sjt_math445;
    float sjt_math446;
    float sjt_math447;
    float sjt_math448;
    float sjt_math449;
    float sjt_math450;
    float sjt_math451;
    float sjt_math452;
    float sjt_math453;
    float sjt_math454;
    float sjt_math455;
    float sjt_math456;
    float sjt_math457;
    float sjt_math458;
    float sjt_math459;
    float sjt_math460;
    float sjt_math461;
    float sjt_math462;
    float sjt_math463;
    float sjt_math464;
    float sjt_math465;
    float sjt_math466;
    float sjt_math467;
    float sjt_math468;
    float sjt_math469;
    float sjt_math470;
    float sjt_math471;
    float sjt_math472;
    float sjt_math473;
    float sjt_math474;
    float sjt_math475;
    float sjt_math476;
    float sjt_math477;
    float sjt_math478;
    float sjt_math479;
    float sjt_math480;
    float sjt_math481;
    float sjt_math482;
    float sjt_math483;
    float sjt_math484;
    float sjt_math485;
    float sjt_math486;
    float sjt_math487;
    float sjt_math488;
    float sjt_math489;
    float sjt_math490;
    float sjt_math491;
    float sjt_math492;
    float sjt_math493;
    float sjt_math494;
    float sjt_math495;
    float sjt_math496;
    float sjt_math497;
    float sjt_math498;
    float sjt_math499;
    float sjt_math500;
    float sjt_math501;
    float sjt_math502;
    float sjt_math503;
    float sjt_math504;
    float sjt_math505;
    float sjt_math506;
    float sjt_math507;
    float sjt_math508;
    float sjt_math509;
    float sjt_math510;
    float sjt_math511;
    float sjt_math512;
    float sjt_math513;
    float sjt_math514;
    float sjt_math515;
    float sjt_math516;
    float sjt_math517;
    float sjt_math518;
    float sjt_math519;
    float sjt_math520;
    float sjt_math521;
    float sjt_math522;
    float sjt_math523;
    float sjt_math524;
    float sjt_math525;
    float sjt_math526;
    float sjt_math527;
    float sjt_math528;
    float sjt_math529;
    float sjt_math530;
    float sjt_math531;
    float sjt_math532;
    float sjt_math533;
    float sjt_math534;
    float sjt_math535;
    float sjt_math536;
    float sjt_math537;
    float sjt_math538;
    float sjt_math539;
    float sjt_math540;
    float sjt_math541;
    float sjt_math542;
    float sjt_math543;
    float sjt_math544;
    float sjt_math545;
    float sjt_math546;
    float sjt_math547;
    float sjt_math548;
    float sjt_math549;
    float sjt_math550;
    float sjt_math551;
    float sjt_math552;
    float sjt_math553;
    float sjt_math554;
    float sjt_math555;
    float sjt_math556;
    float sjt_math557;
    float sjt_math558;
    float sjt_math559;
    float sjt_math560;
    float sjt_math561;
    float sjt_math562;
    float sjt_math563;
    float sjt_math564;
    float sjt_math565;
    float sjt_math566;
    float sjt_math567;
    float sjt_math568;
    float sjt_math569;
    float sjt_math570;
    float sjt_math571;
    float sjt_math572;
    float sjt_math573;
    float sjt_math574;
    float sjt_math575;
    float sjt_math576;
    float sjt_math577;
    float sjt_math578;
    float sjt_math579;
    float sjt_math580;
    float sjt_math581;
    float sjt_math582;
    float sjt_math583;
    float sjt_math584;
    float sjt_math585;
    float sjt_math586;
    float sjt_math587;
    float sjt_math588;
    float sjt_math589;
    float sjt_math590;
    float sjt_math591;
    float sjt_math592;
    float sjt_math593;
    float sjt_math594;
    float sjt_math595;
    float sjt_math596;
    float sjt_math597;
    float sjt_math598;
    float sjt_math599;
    float sjt_math600;
    float sjt_math601;
    float sjt_math602;
    float sjt_math603;
    float sjt_math604;
    float sjt_math605;
    float sjt_math606;
    float sjt_math607;
    float sjt_math608;
    float sjt_math609;
    float sjt_math610;
    float sjt_math611;
    float sjt_math612;
    float sjt_math613;
    float sjt_math614;
    float sjt_math615;
    float sjt_math616;
    float sjt_math617;
    float sjt_math618;
    float sjt_math619;
    float sjt_math620;
    float sjt_math621;
    float sjt_math622;
    float sjt_math623;
    float sjt_math624;
    float sjt_math625;
    float sjt_math626;
    float sjt_math627;
    float sjt_math628;
    float sjt_math629;
    float sjt_math630;
    float sjt_math631;
    float sjt_math632;
    float sjt_math633;
    float sjt_math634;
    float sjt_math635;
    float sjt_math636;
    float sjt_math637;
    float sjt_math638;

    _return->_refCount = 1;
    sjt_dot410 = m;
    sjt_math421 = sjt_dot410->m00;
    sjt_dot411 = _parent;
    sjt_math422 = sjt_dot411->m00;
    sjt_math419 = sjt_math421 * sjt_math422;
    sjt_dot412 = m;
    sjt_math423 = sjt_dot412->m01;
    sjt_dot413 = _parent;
    sjt_math424 = sjt_dot413->m10;
    sjt_math420 = sjt_math423 * sjt_math424;
    sjt_math417 = sjt_math419 + sjt_math420;
    sjt_dot414 = m;
    sjt_math425 = sjt_dot414->m02;
    sjt_dot415 = _parent;
    sjt_math426 = sjt_dot415->m20;
    sjt_math418 = sjt_math425 * sjt_math426;
    sjt_math415 = sjt_math417 + sjt_math418;
    sjt_dot416 = m;
    sjt_math427 = sjt_dot416->m03;
    sjt_dot417 = _parent;
    sjt_math428 = sjt_dot417->m30;
    sjt_math416 = sjt_math427 * sjt_math428;
    _return->m00 = sjt_math415 + sjt_math416;
    sjt_dot418 = m;
    sjt_math435 = sjt_dot418->m00;
    sjt_dot419 = _parent;
    sjt_math436 = sjt_dot419->m01;
    sjt_math433 = sjt_math435 * sjt_math436;
    sjt_dot420 = m;
    sjt_math437 = sjt_dot420->m01;
    sjt_dot421 = _parent;
    sjt_math438 = sjt_dot421->m11;
    sjt_math434 = sjt_math437 * sjt_math438;
    sjt_math431 = sjt_math433 + sjt_math434;
    sjt_dot422 = m;
    sjt_math439 = sjt_dot422->m02;
    sjt_dot423 = _parent;
    sjt_math440 = sjt_dot423->m21;
    sjt_math432 = sjt_math439 * sjt_math440;
    sjt_math429 = sjt_math431 + sjt_math432;
    sjt_dot424 = m;
    sjt_math441 = sjt_dot424->m03;
    sjt_dot425 = _parent;
    sjt_math442 = sjt_dot425->m31;
    sjt_math430 = sjt_math441 * sjt_math442;
    _return->m01 = sjt_math429 + sjt_math430;
    sjt_dot426 = m;
    sjt_math449 = sjt_dot426->m00;
    sjt_dot427 = _parent;
    sjt_math450 = sjt_dot427->m02;
    sjt_math447 = sjt_math449 * sjt_math450;
    sjt_dot428 = m;
    sjt_math451 = sjt_dot428->m01;
    sjt_dot429 = _parent;
    sjt_math452 = sjt_dot429->m12;
    sjt_math448 = sjt_math451 * sjt_math452;
    sjt_math445 = sjt_math447 + sjt_math448;
    sjt_dot430 = m;
    sjt_math453 = sjt_dot430->m02;
    sjt_dot431 = _parent;
    sjt_math454 = sjt_dot431->m22;
    sjt_math446 = sjt_math453 * sjt_math454;
    sjt_math443 = sjt_math445 + sjt_math446;
    sjt_dot432 = m;
    sjt_math455 = sjt_dot432->m03;
    sjt_dot433 = _parent;
    sjt_math456 = sjt_dot433->m32;
    sjt_math444 = sjt_math455 * sjt_math456;
    _return->m02 = sjt_math443 + sjt_math444;
    sjt_dot434 = m;
    sjt_math463 = sjt_dot434->m00;
    sjt_dot435 = _parent;
    sjt_math464 = sjt_dot435->m03;
    sjt_math461 = sjt_math463 * sjt_math464;
    sjt_dot436 = m;
    sjt_math465 = sjt_dot436->m01;
    sjt_dot437 = _parent;
    sjt_math466 = sjt_dot437->m13;
    sjt_math462 = sjt_math465 * sjt_math466;
    sjt_math459 = sjt_math461 + sjt_math462;
    sjt_dot438 = m;
    sjt_math467 = sjt_dot438->m02;
    sjt_dot439 = _parent;
    sjt_math468 = sjt_dot439->m23;
    sjt_math460 = sjt_math467 * sjt_math468;
    sjt_math457 = sjt_math459 + sjt_math460;
    sjt_dot440 = m;
    sjt_math469 = sjt_dot440->m03;
    sjt_dot441 = _parent;
    sjt_math470 = sjt_dot441->m33;
    sjt_math458 = sjt_math469 * sjt_math470;
    _return->m03 = sjt_math457 + sjt_math458;
    sjt_dot442 = m;
    sjt_math477 = sjt_dot442->m10;
    sjt_dot443 = _parent;
    sjt_math478 = sjt_dot443->m00;
    sjt_math475 = sjt_math477 * sjt_math478;
    sjt_dot444 = m;
    sjt_math479 = sjt_dot444->m11;
    sjt_dot445 = _parent;
    sjt_math480 = sjt_dot445->m10;
    sjt_math476 = sjt_math479 * sjt_math480;
    sjt_math473 = sjt_math475 + sjt_math476;
    sjt_dot446 = m;
    sjt_math481 = sjt_dot446->m12;
    sjt_dot447 = _parent;
    sjt_math482 = sjt_dot447->m20;
    sjt_math474 = sjt_math481 * sjt_math482;
    sjt_math471 = sjt_math473 + sjt_math474;
    sjt_dot448 = m;
    sjt_math483 = sjt_dot448->m13;
    sjt_dot449 = _parent;
    sjt_math484 = sjt_dot449->m30;
    sjt_math472 = sjt_math483 * sjt_math484;
    _return->m10 = sjt_math471 + sjt_math472;
    sjt_dot450 = m;
    sjt_math491 = sjt_dot450->m10;
    sjt_dot451 = _parent;
    sjt_math492 = sjt_dot451->m01;
    sjt_math489 = sjt_math491 * sjt_math492;
    sjt_dot452 = m;
    sjt_math493 = sjt_dot452->m11;
    sjt_dot453 = _parent;
    sjt_math494 = sjt_dot453->m11;
    sjt_math490 = sjt_math493 * sjt_math494;
    sjt_math487 = sjt_math489 + sjt_math490;
    sjt_dot454 = m;
    sjt_math495 = sjt_dot454->m12;
    sjt_dot455 = _parent;
    sjt_math496 = sjt_dot455->m21;
    sjt_math488 = sjt_math495 * sjt_math496;
    sjt_math485 = sjt_math487 + sjt_math488;
    sjt_dot456 = m;
    sjt_math497 = sjt_dot456->m13;
    sjt_dot457 = _parent;
    sjt_math498 = sjt_dot457->m31;
    sjt_math486 = sjt_math497 * sjt_math498;
    _return->m11 = sjt_math485 + sjt_math486;
    sjt_dot458 = m;
    sjt_math505 = sjt_dot458->m10;
    sjt_dot459 = _parent;
    sjt_math506 = sjt_dot459->m02;
    sjt_math503 = sjt_math505 * sjt_math506;
    sjt_dot460 = m;
    sjt_math507 = sjt_dot460->m11;
    sjt_dot461 = _parent;
    sjt_math508 = sjt_dot461->m12;
    sjt_math504 = sjt_math507 * sjt_math508;
    sjt_math501 = sjt_math503 + sjt_math504;
    sjt_dot462 = m;
    sjt_math509 = sjt_dot462->m12;
    sjt_dot463 = _parent;
    sjt_math510 = sjt_dot463->m22;
    sjt_math502 = sjt_math509 * sjt_math510;
    sjt_math499 = sjt_math501 + sjt_math502;
    sjt_dot464 = m;
    sjt_math511 = sjt_dot464->m13;
    sjt_dot465 = _parent;
    sjt_math512 = sjt_dot465->m32;
    sjt_math500 = sjt_math511 * sjt_math512;
    _return->m12 = sjt_math499 + sjt_math500;
    sjt_dot466 = m;
    sjt_math519 = sjt_dot466->m10;
    sjt_dot467 = _parent;
    sjt_math520 = sjt_dot467->m03;
    sjt_math517 = sjt_math519 * sjt_math520;
    sjt_dot468 = m;
    sjt_math521 = sjt_dot468->m11;
    sjt_dot469 = _parent;
    sjt_math522 = sjt_dot469->m13;
    sjt_math518 = sjt_math521 * sjt_math522;
    sjt_math515 = sjt_math517 + sjt_math518;
    sjt_dot470 = m;
    sjt_math523 = sjt_dot470->m12;
    sjt_dot471 = _parent;
    sjt_math524 = sjt_dot471->m23;
    sjt_math516 = sjt_math523 * sjt_math524;
    sjt_math513 = sjt_math515 + sjt_math516;
    sjt_dot472 = m;
    sjt_math525 = sjt_dot472->m13;
    sjt_dot473 = _parent;
    sjt_math526 = sjt_dot473->m33;
    sjt_math514 = sjt_math525 * sjt_math526;
    _return->m13 = sjt_math513 + sjt_math514;
    sjt_dot474 = m;
    sjt_math533 = sjt_dot474->m20;
    sjt_dot475 = _parent;
    sjt_math534 = sjt_dot475->m00;
    sjt_math531 = sjt_math533 * sjt_math534;
    sjt_dot476 = m;
    sjt_math535 = sjt_dot476->m21;
    sjt_dot477 = _parent;
    sjt_math536 = sjt_dot477->m10;
    sjt_math532 = sjt_math535 * sjt_math536;
    sjt_math529 = sjt_math531 + sjt_math532;
    sjt_dot478 = m;
    sjt_math537 = sjt_dot478->m22;
    sjt_dot479 = _parent;
    sjt_math538 = sjt_dot479->m20;
    sjt_math530 = sjt_math537 * sjt_math538;
    sjt_math527 = sjt_math529 + sjt_math530;
    sjt_dot480 = m;
    sjt_math539 = sjt_dot480->m23;
    sjt_dot481 = _parent;
    sjt_math540 = sjt_dot481->m30;
    sjt_math528 = sjt_math539 * sjt_math540;
    _return->m20 = sjt_math527 + sjt_math528;
    sjt_dot482 = m;
    sjt_math547 = sjt_dot482->m20;
    sjt_dot483 = _parent;
    sjt_math548 = sjt_dot483->m01;
    sjt_math545 = sjt_math547 * sjt_math548;
    sjt_dot484 = m;
    sjt_math549 = sjt_dot484->m21;
    sjt_dot485 = _parent;
    sjt_math550 = sjt_dot485->m11;
    sjt_math546 = sjt_math549 * sjt_math550;
    sjt_math543 = sjt_math545 + sjt_math546;
    sjt_dot486 = m;
    sjt_math551 = sjt_dot486->m22;
    sjt_dot487 = _parent;
    sjt_math552 = sjt_dot487->m21;
    sjt_math544 = sjt_math551 * sjt_math552;
    sjt_math541 = sjt_math543 + sjt_math544;
    sjt_dot488 = m;
    sjt_math553 = sjt_dot488->m23;
    sjt_dot489 = _parent;
    sjt_math554 = sjt_dot489->m31;
    sjt_math542 = sjt_math553 * sjt_math554;
    _return->m21 = sjt_math541 + sjt_math542;
    sjt_dot490 = m;
    sjt_math561 = sjt_dot490->m20;
    sjt_dot491 = _parent;
    sjt_math562 = sjt_dot491->m02;
    sjt_math559 = sjt_math561 * sjt_math562;
    sjt_dot492 = m;
    sjt_math563 = sjt_dot492->m21;
    sjt_dot493 = _parent;
    sjt_math564 = sjt_dot493->m12;
    sjt_math560 = sjt_math563 * sjt_math564;
    sjt_math557 = sjt_math559 + sjt_math560;
    sjt_dot494 = m;
    sjt_math565 = sjt_dot494->m22;
    sjt_dot495 = _parent;
    sjt_math566 = sjt_dot495->m22;
    sjt_math558 = sjt_math565 * sjt_math566;
    sjt_math555 = sjt_math557 + sjt_math558;
    sjt_dot496 = m;
    sjt_math567 = sjt_dot496->m23;
    sjt_dot497 = _parent;
    sjt_math568 = sjt_dot497->m32;
    sjt_math556 = sjt_math567 * sjt_math568;
    _return->m22 = sjt_math555 + sjt_math556;
    sjt_dot498 = m;
    sjt_math575 = sjt_dot498->m20;
    sjt_dot499 = _parent;
    sjt_math576 = sjt_dot499->m03;
    sjt_math573 = sjt_math575 * sjt_math576;
    sjt_dot500 = m;
    sjt_math577 = sjt_dot500->m21;
    sjt_dot501 = _parent;
    sjt_math578 = sjt_dot501->m13;
    sjt_math574 = sjt_math577 * sjt_math578;
    sjt_math571 = sjt_math573 + sjt_math574;
    sjt_dot502 = m;
    sjt_math579 = sjt_dot502->m22;
    sjt_dot503 = _parent;
    sjt_math580 = sjt_dot503->m23;
    sjt_math572 = sjt_math579 * sjt_math580;
    sjt_math569 = sjt_math571 + sjt_math572;
    sjt_dot504 = m;
    sjt_math581 = sjt_dot504->m23;
    sjt_dot505 = _parent;
    sjt_math582 = sjt_dot505->m33;
    sjt_math570 = sjt_math581 * sjt_math582;
    _return->m23 = sjt_math569 + sjt_math570;
    sjt_dot506 = m;
    sjt_math589 = sjt_dot506->m30;
    sjt_dot507 = _parent;
    sjt_math590 = sjt_dot507->m00;
    sjt_math587 = sjt_math589 * sjt_math590;
    sjt_dot508 = m;
    sjt_math591 = sjt_dot508->m31;
    sjt_dot509 = _parent;
    sjt_math592 = sjt_dot509->m10;
    sjt_math588 = sjt_math591 * sjt_math592;
    sjt_math585 = sjt_math587 + sjt_math588;
    sjt_dot510 = m;
    sjt_math593 = sjt_dot510->m32;
    sjt_dot511 = _parent;
    sjt_math594 = sjt_dot511->m20;
    sjt_math586 = sjt_math593 * sjt_math594;
    sjt_math583 = sjt_math585 + sjt_math586;
    sjt_dot512 = m;
    sjt_math595 = sjt_dot512->m33;
    sjt_dot513 = _parent;
    sjt_math596 = sjt_dot513->m30;
    sjt_math584 = sjt_math595 * sjt_math596;
    _return->m30 = sjt_math583 + sjt_math584;
    sjt_dot514 = m;
    sjt_math603 = sjt_dot514->m30;
    sjt_dot515 = _parent;
    sjt_math604 = sjt_dot515->m01;
    sjt_math601 = sjt_math603 * sjt_math604;
    sjt_dot516 = m;
    sjt_math605 = sjt_dot516->m31;
    sjt_dot517 = _parent;
    sjt_math606 = sjt_dot517->m11;
    sjt_math602 = sjt_math605 * sjt_math606;
    sjt_math599 = sjt_math601 + sjt_math602;
    sjt_dot518 = m;
    sjt_math607 = sjt_dot518->m32;
    sjt_dot519 = _parent;
    sjt_math608 = sjt_dot519->m21;
    sjt_math600 = sjt_math607 * sjt_math608;
    sjt_math597 = sjt_math599 + sjt_math600;
    sjt_dot520 = m;
    sjt_math609 = sjt_dot520->m33;
    sjt_dot521 = _parent;
    sjt_math610 = sjt_dot521->m31;
    sjt_math598 = sjt_math609 * sjt_math610;
    _return->m31 = sjt_math597 + sjt_math598;
    sjt_dot522 = m;
    sjt_math617 = sjt_dot522->m30;
    sjt_dot523 = _parent;
    sjt_math618 = sjt_dot523->m02;
    sjt_math615 = sjt_math617 * sjt_math618;
    sjt_dot524 = m;
    sjt_math619 = sjt_dot524->m31;
    sjt_dot525 = _parent;
    sjt_math620 = sjt_dot525->m12;
    sjt_math616 = sjt_math619 * sjt_math620;
    sjt_math613 = sjt_math615 + sjt_math616;
    sjt_dot526 = m;
    sjt_math621 = sjt_dot526->m32;
    sjt_dot527 = _parent;
    sjt_math622 = sjt_dot527->m22;
    sjt_math614 = sjt_math621 * sjt_math622;
    sjt_math611 = sjt_math613 + sjt_math614;
    sjt_dot528 = m;
    sjt_math623 = sjt_dot528->m33;
    sjt_dot529 = _parent;
    sjt_math624 = sjt_dot529->m32;
    sjt_math612 = sjt_math623 * sjt_math624;
    _return->m32 = sjt_math611 + sjt_math612;
    sjt_dot530 = m;
    sjt_math631 = sjt_dot530->m30;
    sjt_dot531 = _parent;
    sjt_math632 = sjt_dot531->m03;
    sjt_math629 = sjt_math631 * sjt_math632;
    sjt_dot532 = m;
    sjt_math633 = sjt_dot532->m31;
    sjt_dot533 = _parent;
    sjt_math634 = sjt_dot533->m13;
    sjt_math630 = sjt_math633 * sjt_math634;
    sjt_math627 = sjt_math629 + sjt_math630;
    sjt_dot534 = m;
    sjt_math635 = sjt_dot534->m32;
    sjt_dot535 = _parent;
    sjt_math636 = sjt_dot535->m23;
    sjt_math628 = sjt_math635 * sjt_math636;
    sjt_math625 = sjt_math627 + sjt_math628;
    sjt_dot536 = m;
    sjt_math637 = sjt_dot536->m33;
    sjt_dot537 = _parent;
    sjt_math638 = sjt_dot537->m33;
    sjt_math626 = sjt_math637 * sjt_math638;
    _return->m33 = sjt_math625 + sjt_math626;
    sjf_mat4(_return);
}

void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4** _return) {
    sjs_mat4* sjt_dot538 = 0;
    sjs_mat4* sjt_dot539 = 0;
    sjs_mat4* sjt_dot540 = 0;
    sjs_mat4* sjt_dot541 = 0;
    sjs_mat4* sjt_dot542 = 0;
    sjs_mat4* sjt_dot543 = 0;
    sjs_mat4* sjt_dot544 = 0;
    sjs_mat4* sjt_dot545 = 0;
    sjs_mat4* sjt_dot546 = 0;
    sjs_mat4* sjt_dot547 = 0;
    sjs_mat4* sjt_dot548 = 0;
    sjs_mat4* sjt_dot549 = 0;
    sjs_mat4* sjt_dot550 = 0;
    sjs_mat4* sjt_dot551 = 0;
    sjs_mat4* sjt_dot552 = 0;
    sjs_mat4* sjt_dot553 = 0;
    sjs_mat4* sjt_dot554 = 0;
    sjs_mat4* sjt_dot555 = 0;
    sjs_mat4* sjt_dot556 = 0;
    sjs_mat4* sjt_dot557 = 0;
    sjs_mat4* sjt_dot558 = 0;
    sjs_mat4* sjt_dot559 = 0;
    sjs_mat4* sjt_dot560 = 0;
    sjs_mat4* sjt_dot561 = 0;
    sjs_mat4* sjt_dot562 = 0;
    sjs_mat4* sjt_dot563 = 0;
    sjs_mat4* sjt_dot564 = 0;
    sjs_mat4* sjt_dot565 = 0;
    sjs_mat4* sjt_dot566 = 0;
    sjs_mat4* sjt_dot567 = 0;
    sjs_mat4* sjt_dot568 = 0;
    sjs_mat4* sjt_dot569 = 0;
    sjs_mat4* sjt_dot570 = 0;
    sjs_mat4* sjt_dot571 = 0;
    sjs_mat4* sjt_dot572 = 0;
    sjs_mat4* sjt_dot573 = 0;
    sjs_mat4* sjt_dot574 = 0;
    sjs_mat4* sjt_dot575 = 0;
    sjs_mat4* sjt_dot576 = 0;
    sjs_mat4* sjt_dot577 = 0;
    sjs_mat4* sjt_dot578 = 0;
    sjs_mat4* sjt_dot579 = 0;
    sjs_mat4* sjt_dot580 = 0;
    sjs_mat4* sjt_dot581 = 0;
    sjs_mat4* sjt_dot582 = 0;
    sjs_mat4* sjt_dot583 = 0;
    sjs_mat4* sjt_dot584 = 0;
    sjs_mat4* sjt_dot585 = 0;
    sjs_mat4* sjt_dot586 = 0;
    sjs_mat4* sjt_dot587 = 0;
    sjs_mat4* sjt_dot588 = 0;
    sjs_mat4* sjt_dot589 = 0;
    sjs_mat4* sjt_dot590 = 0;
    sjs_mat4* sjt_dot591 = 0;
    sjs_mat4* sjt_dot592 = 0;
    sjs_mat4* sjt_dot593 = 0;
    sjs_mat4* sjt_dot594 = 0;
    sjs_mat4* sjt_dot595 = 0;
    sjs_mat4* sjt_dot596 = 0;
    sjs_mat4* sjt_dot597 = 0;
    sjs_mat4* sjt_dot598 = 0;
    sjs_mat4* sjt_dot599 = 0;
    sjs_mat4* sjt_dot600 = 0;
    sjs_mat4* sjt_dot601 = 0;
    sjs_mat4* sjt_dot602 = 0;
    sjs_mat4* sjt_dot603 = 0;
    sjs_mat4* sjt_dot604 = 0;
    sjs_mat4* sjt_dot605 = 0;
    sjs_mat4* sjt_dot606 = 0;
    sjs_mat4* sjt_dot607 = 0;
    sjs_mat4* sjt_dot608 = 0;
    sjs_mat4* sjt_dot609 = 0;
    sjs_mat4* sjt_dot610 = 0;
    sjs_mat4* sjt_dot611 = 0;
    sjs_mat4* sjt_dot612 = 0;
    sjs_mat4* sjt_dot613 = 0;
    sjs_mat4* sjt_dot614 = 0;
    sjs_mat4* sjt_dot615 = 0;
    sjs_mat4* sjt_dot616 = 0;
    sjs_mat4* sjt_dot617 = 0;
    sjs_mat4* sjt_dot618 = 0;
    sjs_mat4* sjt_dot619 = 0;
    sjs_mat4* sjt_dot620 = 0;
    sjs_mat4* sjt_dot621 = 0;
    sjs_mat4* sjt_dot622 = 0;
    sjs_mat4* sjt_dot623 = 0;
    sjs_mat4* sjt_dot624 = 0;
    sjs_mat4* sjt_dot625 = 0;
    sjs_mat4* sjt_dot626 = 0;
    sjs_mat4* sjt_dot627 = 0;
    sjs_mat4* sjt_dot628 = 0;
    sjs_mat4* sjt_dot629 = 0;
    sjs_mat4* sjt_dot630 = 0;
    sjs_mat4* sjt_dot631 = 0;
    sjs_mat4* sjt_dot632 = 0;
    sjs_mat4* sjt_dot633 = 0;
    sjs_mat4* sjt_dot634 = 0;
    sjs_mat4* sjt_dot635 = 0;
    sjs_mat4* sjt_dot636 = 0;
    sjs_mat4* sjt_dot637 = 0;
    sjs_mat4* sjt_dot638 = 0;
    sjs_mat4* sjt_dot639 = 0;
    sjs_mat4* sjt_dot640 = 0;
    sjs_mat4* sjt_dot641 = 0;
    sjs_mat4* sjt_dot642 = 0;
    sjs_mat4* sjt_dot643 = 0;
    sjs_mat4* sjt_dot644 = 0;
    sjs_mat4* sjt_dot645 = 0;
    sjs_mat4* sjt_dot646 = 0;
    sjs_mat4* sjt_dot647 = 0;
    sjs_mat4* sjt_dot648 = 0;
    sjs_mat4* sjt_dot649 = 0;
    sjs_mat4* sjt_dot650 = 0;
    sjs_mat4* sjt_dot651 = 0;
    sjs_mat4* sjt_dot652 = 0;
    sjs_mat4* sjt_dot653 = 0;
    sjs_mat4* sjt_dot654 = 0;
    sjs_mat4* sjt_dot655 = 0;
    sjs_mat4* sjt_dot656 = 0;
    sjs_mat4* sjt_dot657 = 0;
    sjs_mat4* sjt_dot658 = 0;
    sjs_mat4* sjt_dot659 = 0;
    sjs_mat4* sjt_dot660 = 0;
    sjs_mat4* sjt_dot661 = 0;
    sjs_mat4* sjt_dot662 = 0;
    sjs_mat4* sjt_dot663 = 0;
    sjs_mat4* sjt_dot664 = 0;
    sjs_mat4* sjt_dot665 = 0;
    float sjt_math639;
    float sjt_math640;
    float sjt_math641;
    float sjt_math642;
    float sjt_math643;
    float sjt_math644;
    float sjt_math645;
    float sjt_math646;
    float sjt_math647;
    float sjt_math648;
    float sjt_math649;
    float sjt_math650;
    float sjt_math651;
    float sjt_math652;
    float sjt_math653;
    float sjt_math654;
    float sjt_math655;
    float sjt_math656;
    float sjt_math657;
    float sjt_math658;
    float sjt_math659;
    float sjt_math660;
    float sjt_math661;
    float sjt_math662;
    float sjt_math663;
    float sjt_math664;
    float sjt_math665;
    float sjt_math666;
    float sjt_math667;
    float sjt_math668;
    float sjt_math669;
    float sjt_math670;
    float sjt_math671;
    float sjt_math672;
    float sjt_math673;
    float sjt_math674;
    float sjt_math675;
    float sjt_math676;
    float sjt_math677;
    float sjt_math678;
    float sjt_math679;
    float sjt_math680;
    float sjt_math681;
    float sjt_math682;
    float sjt_math683;
    float sjt_math684;
    float sjt_math685;
    float sjt_math686;
    float sjt_math687;
    float sjt_math688;
    float sjt_math689;
    float sjt_math690;
    float sjt_math691;
    float sjt_math692;
    float sjt_math693;
    float sjt_math694;
    float sjt_math695;
    float sjt_math696;
    float sjt_math697;
    float sjt_math698;
    float sjt_math699;
    float sjt_math700;
    float sjt_math701;
    float sjt_math702;
    float sjt_math703;
    float sjt_math704;
    float sjt_math705;
    float sjt_math706;
    float sjt_math707;
    float sjt_math708;
    float sjt_math709;
    float sjt_math710;
    float sjt_math711;
    float sjt_math712;
    float sjt_math713;
    float sjt_math714;
    float sjt_math715;
    float sjt_math716;
    float sjt_math717;
    float sjt_math718;
    float sjt_math719;
    float sjt_math720;
    float sjt_math721;
    float sjt_math722;
    float sjt_math723;
    float sjt_math724;
    float sjt_math725;
    float sjt_math726;
    float sjt_math727;
    float sjt_math728;
    float sjt_math729;
    float sjt_math730;
    float sjt_math731;
    float sjt_math732;
    float sjt_math733;
    float sjt_math734;
    float sjt_math735;
    float sjt_math736;
    float sjt_math737;
    float sjt_math738;
    float sjt_math739;
    float sjt_math740;
    float sjt_math741;
    float sjt_math742;
    float sjt_math743;
    float sjt_math744;
    float sjt_math745;
    float sjt_math746;
    float sjt_math747;
    float sjt_math748;
    float sjt_math749;
    float sjt_math750;
    float sjt_math751;
    float sjt_math752;
    float sjt_math753;
    float sjt_math754;
    float sjt_math755;
    float sjt_math756;
    float sjt_math757;
    float sjt_math758;
    float sjt_math759;
    float sjt_math760;
    float sjt_math761;
    float sjt_math762;
    float sjt_math763;
    float sjt_math764;
    float sjt_math765;
    float sjt_math766;
    float sjt_math767;
    float sjt_math768;
    float sjt_math769;
    float sjt_math770;
    float sjt_math771;
    float sjt_math772;
    float sjt_math773;
    float sjt_math774;
    float sjt_math775;
    float sjt_math776;
    float sjt_math777;
    float sjt_math778;
    float sjt_math779;
    float sjt_math780;
    float sjt_math781;
    float sjt_math782;
    float sjt_math783;
    float sjt_math784;
    float sjt_math785;
    float sjt_math786;
    float sjt_math787;
    float sjt_math788;
    float sjt_math789;
    float sjt_math790;
    float sjt_math791;
    float sjt_math792;
    float sjt_math793;
    float sjt_math794;
    float sjt_math795;
    float sjt_math796;
    float sjt_math797;
    float sjt_math798;
    float sjt_math799;
    float sjt_math800;
    float sjt_math801;
    float sjt_math802;
    float sjt_math803;
    float sjt_math804;
    float sjt_math805;
    float sjt_math806;
    float sjt_math807;
    float sjt_math808;
    float sjt_math809;
    float sjt_math810;
    float sjt_math811;
    float sjt_math812;
    float sjt_math813;
    float sjt_math814;
    float sjt_math815;
    float sjt_math816;
    float sjt_math817;
    float sjt_math818;
    float sjt_math819;
    float sjt_math820;
    float sjt_math821;
    float sjt_math822;
    float sjt_math823;
    float sjt_math824;
    float sjt_math825;
    float sjt_math826;
    float sjt_math827;
    float sjt_math828;
    float sjt_math829;
    float sjt_math830;
    float sjt_math831;
    float sjt_math832;
    float sjt_math833;
    float sjt_math834;
    float sjt_math835;
    float sjt_math836;
    float sjt_math837;
    float sjt_math838;
    float sjt_math839;
    float sjt_math840;
    float sjt_math841;
    float sjt_math842;
    float sjt_math843;
    float sjt_math844;
    float sjt_math845;
    float sjt_math846;
    float sjt_math847;
    float sjt_math848;
    float sjt_math849;
    float sjt_math850;
    float sjt_math851;
    float sjt_math852;
    float sjt_math853;
    float sjt_math854;
    float sjt_math855;
    float sjt_math856;
    float sjt_math857;
    float sjt_math858;
    float sjt_math859;
    float sjt_math860;
    float sjt_math861;
    float sjt_math862;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot538 = m;
    sjt_math645 = sjt_dot538->m00;
    sjt_dot539 = _parent;
    sjt_math646 = sjt_dot539->m00;
    sjt_math643 = sjt_math645 * sjt_math646;
    sjt_dot540 = m;
    sjt_math647 = sjt_dot540->m01;
    sjt_dot541 = _parent;
    sjt_math648 = sjt_dot541->m10;
    sjt_math644 = sjt_math647 * sjt_math648;
    sjt_math641 = sjt_math643 + sjt_math644;
    sjt_dot542 = m;
    sjt_math649 = sjt_dot542->m02;
    sjt_dot543 = _parent;
    sjt_math650 = sjt_dot543->m20;
    sjt_math642 = sjt_math649 * sjt_math650;
    sjt_math639 = sjt_math641 + sjt_math642;
    sjt_dot544 = m;
    sjt_math651 = sjt_dot544->m03;
    sjt_dot545 = _parent;
    sjt_math652 = sjt_dot545->m30;
    sjt_math640 = sjt_math651 * sjt_math652;
    (*_return)->m00 = sjt_math639 + sjt_math640;
    sjt_dot546 = m;
    sjt_math659 = sjt_dot546->m00;
    sjt_dot547 = _parent;
    sjt_math660 = sjt_dot547->m01;
    sjt_math657 = sjt_math659 * sjt_math660;
    sjt_dot548 = m;
    sjt_math661 = sjt_dot548->m01;
    sjt_dot549 = _parent;
    sjt_math662 = sjt_dot549->m11;
    sjt_math658 = sjt_math661 * sjt_math662;
    sjt_math655 = sjt_math657 + sjt_math658;
    sjt_dot550 = m;
    sjt_math663 = sjt_dot550->m02;
    sjt_dot551 = _parent;
    sjt_math664 = sjt_dot551->m21;
    sjt_math656 = sjt_math663 * sjt_math664;
    sjt_math653 = sjt_math655 + sjt_math656;
    sjt_dot552 = m;
    sjt_math665 = sjt_dot552->m03;
    sjt_dot553 = _parent;
    sjt_math666 = sjt_dot553->m31;
    sjt_math654 = sjt_math665 * sjt_math666;
    (*_return)->m01 = sjt_math653 + sjt_math654;
    sjt_dot554 = m;
    sjt_math673 = sjt_dot554->m00;
    sjt_dot555 = _parent;
    sjt_math674 = sjt_dot555->m02;
    sjt_math671 = sjt_math673 * sjt_math674;
    sjt_dot556 = m;
    sjt_math675 = sjt_dot556->m01;
    sjt_dot557 = _parent;
    sjt_math676 = sjt_dot557->m12;
    sjt_math672 = sjt_math675 * sjt_math676;
    sjt_math669 = sjt_math671 + sjt_math672;
    sjt_dot558 = m;
    sjt_math677 = sjt_dot558->m02;
    sjt_dot559 = _parent;
    sjt_math678 = sjt_dot559->m22;
    sjt_math670 = sjt_math677 * sjt_math678;
    sjt_math667 = sjt_math669 + sjt_math670;
    sjt_dot560 = m;
    sjt_math679 = sjt_dot560->m03;
    sjt_dot561 = _parent;
    sjt_math680 = sjt_dot561->m32;
    sjt_math668 = sjt_math679 * sjt_math680;
    (*_return)->m02 = sjt_math667 + sjt_math668;
    sjt_dot562 = m;
    sjt_math687 = sjt_dot562->m00;
    sjt_dot563 = _parent;
    sjt_math688 = sjt_dot563->m03;
    sjt_math685 = sjt_math687 * sjt_math688;
    sjt_dot564 = m;
    sjt_math689 = sjt_dot564->m01;
    sjt_dot565 = _parent;
    sjt_math690 = sjt_dot565->m13;
    sjt_math686 = sjt_math689 * sjt_math690;
    sjt_math683 = sjt_math685 + sjt_math686;
    sjt_dot566 = m;
    sjt_math691 = sjt_dot566->m02;
    sjt_dot567 = _parent;
    sjt_math692 = sjt_dot567->m23;
    sjt_math684 = sjt_math691 * sjt_math692;
    sjt_math681 = sjt_math683 + sjt_math684;
    sjt_dot568 = m;
    sjt_math693 = sjt_dot568->m03;
    sjt_dot569 = _parent;
    sjt_math694 = sjt_dot569->m33;
    sjt_math682 = sjt_math693 * sjt_math694;
    (*_return)->m03 = sjt_math681 + sjt_math682;
    sjt_dot570 = m;
    sjt_math701 = sjt_dot570->m10;
    sjt_dot571 = _parent;
    sjt_math702 = sjt_dot571->m00;
    sjt_math699 = sjt_math701 * sjt_math702;
    sjt_dot572 = m;
    sjt_math703 = sjt_dot572->m11;
    sjt_dot573 = _parent;
    sjt_math704 = sjt_dot573->m10;
    sjt_math700 = sjt_math703 * sjt_math704;
    sjt_math697 = sjt_math699 + sjt_math700;
    sjt_dot574 = m;
    sjt_math705 = sjt_dot574->m12;
    sjt_dot575 = _parent;
    sjt_math706 = sjt_dot575->m20;
    sjt_math698 = sjt_math705 * sjt_math706;
    sjt_math695 = sjt_math697 + sjt_math698;
    sjt_dot576 = m;
    sjt_math707 = sjt_dot576->m13;
    sjt_dot577 = _parent;
    sjt_math708 = sjt_dot577->m30;
    sjt_math696 = sjt_math707 * sjt_math708;
    (*_return)->m10 = sjt_math695 + sjt_math696;
    sjt_dot578 = m;
    sjt_math715 = sjt_dot578->m10;
    sjt_dot579 = _parent;
    sjt_math716 = sjt_dot579->m01;
    sjt_math713 = sjt_math715 * sjt_math716;
    sjt_dot580 = m;
    sjt_math717 = sjt_dot580->m11;
    sjt_dot581 = _parent;
    sjt_math718 = sjt_dot581->m11;
    sjt_math714 = sjt_math717 * sjt_math718;
    sjt_math711 = sjt_math713 + sjt_math714;
    sjt_dot582 = m;
    sjt_math719 = sjt_dot582->m12;
    sjt_dot583 = _parent;
    sjt_math720 = sjt_dot583->m21;
    sjt_math712 = sjt_math719 * sjt_math720;
    sjt_math709 = sjt_math711 + sjt_math712;
    sjt_dot584 = m;
    sjt_math721 = sjt_dot584->m13;
    sjt_dot585 = _parent;
    sjt_math722 = sjt_dot585->m31;
    sjt_math710 = sjt_math721 * sjt_math722;
    (*_return)->m11 = sjt_math709 + sjt_math710;
    sjt_dot586 = m;
    sjt_math729 = sjt_dot586->m10;
    sjt_dot587 = _parent;
    sjt_math730 = sjt_dot587->m02;
    sjt_math727 = sjt_math729 * sjt_math730;
    sjt_dot588 = m;
    sjt_math731 = sjt_dot588->m11;
    sjt_dot589 = _parent;
    sjt_math732 = sjt_dot589->m12;
    sjt_math728 = sjt_math731 * sjt_math732;
    sjt_math725 = sjt_math727 + sjt_math728;
    sjt_dot590 = m;
    sjt_math733 = sjt_dot590->m12;
    sjt_dot591 = _parent;
    sjt_math734 = sjt_dot591->m22;
    sjt_math726 = sjt_math733 * sjt_math734;
    sjt_math723 = sjt_math725 + sjt_math726;
    sjt_dot592 = m;
    sjt_math735 = sjt_dot592->m13;
    sjt_dot593 = _parent;
    sjt_math736 = sjt_dot593->m32;
    sjt_math724 = sjt_math735 * sjt_math736;
    (*_return)->m12 = sjt_math723 + sjt_math724;
    sjt_dot594 = m;
    sjt_math743 = sjt_dot594->m10;
    sjt_dot595 = _parent;
    sjt_math744 = sjt_dot595->m03;
    sjt_math741 = sjt_math743 * sjt_math744;
    sjt_dot596 = m;
    sjt_math745 = sjt_dot596->m11;
    sjt_dot597 = _parent;
    sjt_math746 = sjt_dot597->m13;
    sjt_math742 = sjt_math745 * sjt_math746;
    sjt_math739 = sjt_math741 + sjt_math742;
    sjt_dot598 = m;
    sjt_math747 = sjt_dot598->m12;
    sjt_dot599 = _parent;
    sjt_math748 = sjt_dot599->m23;
    sjt_math740 = sjt_math747 * sjt_math748;
    sjt_math737 = sjt_math739 + sjt_math740;
    sjt_dot600 = m;
    sjt_math749 = sjt_dot600->m13;
    sjt_dot601 = _parent;
    sjt_math750 = sjt_dot601->m33;
    sjt_math738 = sjt_math749 * sjt_math750;
    (*_return)->m13 = sjt_math737 + sjt_math738;
    sjt_dot602 = m;
    sjt_math757 = sjt_dot602->m20;
    sjt_dot603 = _parent;
    sjt_math758 = sjt_dot603->m00;
    sjt_math755 = sjt_math757 * sjt_math758;
    sjt_dot604 = m;
    sjt_math759 = sjt_dot604->m21;
    sjt_dot605 = _parent;
    sjt_math760 = sjt_dot605->m10;
    sjt_math756 = sjt_math759 * sjt_math760;
    sjt_math753 = sjt_math755 + sjt_math756;
    sjt_dot606 = m;
    sjt_math761 = sjt_dot606->m22;
    sjt_dot607 = _parent;
    sjt_math762 = sjt_dot607->m20;
    sjt_math754 = sjt_math761 * sjt_math762;
    sjt_math751 = sjt_math753 + sjt_math754;
    sjt_dot608 = m;
    sjt_math763 = sjt_dot608->m23;
    sjt_dot609 = _parent;
    sjt_math764 = sjt_dot609->m30;
    sjt_math752 = sjt_math763 * sjt_math764;
    (*_return)->m20 = sjt_math751 + sjt_math752;
    sjt_dot610 = m;
    sjt_math771 = sjt_dot610->m20;
    sjt_dot611 = _parent;
    sjt_math772 = sjt_dot611->m01;
    sjt_math769 = sjt_math771 * sjt_math772;
    sjt_dot612 = m;
    sjt_math773 = sjt_dot612->m21;
    sjt_dot613 = _parent;
    sjt_math774 = sjt_dot613->m11;
    sjt_math770 = sjt_math773 * sjt_math774;
    sjt_math767 = sjt_math769 + sjt_math770;
    sjt_dot614 = m;
    sjt_math775 = sjt_dot614->m22;
    sjt_dot615 = _parent;
    sjt_math776 = sjt_dot615->m21;
    sjt_math768 = sjt_math775 * sjt_math776;
    sjt_math765 = sjt_math767 + sjt_math768;
    sjt_dot616 = m;
    sjt_math777 = sjt_dot616->m23;
    sjt_dot617 = _parent;
    sjt_math778 = sjt_dot617->m31;
    sjt_math766 = sjt_math777 * sjt_math778;
    (*_return)->m21 = sjt_math765 + sjt_math766;
    sjt_dot618 = m;
    sjt_math785 = sjt_dot618->m20;
    sjt_dot619 = _parent;
    sjt_math786 = sjt_dot619->m02;
    sjt_math783 = sjt_math785 * sjt_math786;
    sjt_dot620 = m;
    sjt_math787 = sjt_dot620->m21;
    sjt_dot621 = _parent;
    sjt_math788 = sjt_dot621->m12;
    sjt_math784 = sjt_math787 * sjt_math788;
    sjt_math781 = sjt_math783 + sjt_math784;
    sjt_dot622 = m;
    sjt_math789 = sjt_dot622->m22;
    sjt_dot623 = _parent;
    sjt_math790 = sjt_dot623->m22;
    sjt_math782 = sjt_math789 * sjt_math790;
    sjt_math779 = sjt_math781 + sjt_math782;
    sjt_dot624 = m;
    sjt_math791 = sjt_dot624->m23;
    sjt_dot625 = _parent;
    sjt_math792 = sjt_dot625->m32;
    sjt_math780 = sjt_math791 * sjt_math792;
    (*_return)->m22 = sjt_math779 + sjt_math780;
    sjt_dot626 = m;
    sjt_math799 = sjt_dot626->m20;
    sjt_dot627 = _parent;
    sjt_math800 = sjt_dot627->m03;
    sjt_math797 = sjt_math799 * sjt_math800;
    sjt_dot628 = m;
    sjt_math801 = sjt_dot628->m21;
    sjt_dot629 = _parent;
    sjt_math802 = sjt_dot629->m13;
    sjt_math798 = sjt_math801 * sjt_math802;
    sjt_math795 = sjt_math797 + sjt_math798;
    sjt_dot630 = m;
    sjt_math803 = sjt_dot630->m22;
    sjt_dot631 = _parent;
    sjt_math804 = sjt_dot631->m23;
    sjt_math796 = sjt_math803 * sjt_math804;
    sjt_math793 = sjt_math795 + sjt_math796;
    sjt_dot632 = m;
    sjt_math805 = sjt_dot632->m23;
    sjt_dot633 = _parent;
    sjt_math806 = sjt_dot633->m33;
    sjt_math794 = sjt_math805 * sjt_math806;
    (*_return)->m23 = sjt_math793 + sjt_math794;
    sjt_dot634 = m;
    sjt_math813 = sjt_dot634->m30;
    sjt_dot635 = _parent;
    sjt_math814 = sjt_dot635->m00;
    sjt_math811 = sjt_math813 * sjt_math814;
    sjt_dot636 = m;
    sjt_math815 = sjt_dot636->m31;
    sjt_dot637 = _parent;
    sjt_math816 = sjt_dot637->m10;
    sjt_math812 = sjt_math815 * sjt_math816;
    sjt_math809 = sjt_math811 + sjt_math812;
    sjt_dot638 = m;
    sjt_math817 = sjt_dot638->m32;
    sjt_dot639 = _parent;
    sjt_math818 = sjt_dot639->m20;
    sjt_math810 = sjt_math817 * sjt_math818;
    sjt_math807 = sjt_math809 + sjt_math810;
    sjt_dot640 = m;
    sjt_math819 = sjt_dot640->m33;
    sjt_dot641 = _parent;
    sjt_math820 = sjt_dot641->m30;
    sjt_math808 = sjt_math819 * sjt_math820;
    (*_return)->m30 = sjt_math807 + sjt_math808;
    sjt_dot642 = m;
    sjt_math827 = sjt_dot642->m30;
    sjt_dot643 = _parent;
    sjt_math828 = sjt_dot643->m01;
    sjt_math825 = sjt_math827 * sjt_math828;
    sjt_dot644 = m;
    sjt_math829 = sjt_dot644->m31;
    sjt_dot645 = _parent;
    sjt_math830 = sjt_dot645->m11;
    sjt_math826 = sjt_math829 * sjt_math830;
    sjt_math823 = sjt_math825 + sjt_math826;
    sjt_dot646 = m;
    sjt_math831 = sjt_dot646->m32;
    sjt_dot647 = _parent;
    sjt_math832 = sjt_dot647->m21;
    sjt_math824 = sjt_math831 * sjt_math832;
    sjt_math821 = sjt_math823 + sjt_math824;
    sjt_dot648 = m;
    sjt_math833 = sjt_dot648->m33;
    sjt_dot649 = _parent;
    sjt_math834 = sjt_dot649->m31;
    sjt_math822 = sjt_math833 * sjt_math834;
    (*_return)->m31 = sjt_math821 + sjt_math822;
    sjt_dot650 = m;
    sjt_math841 = sjt_dot650->m30;
    sjt_dot651 = _parent;
    sjt_math842 = sjt_dot651->m02;
    sjt_math839 = sjt_math841 * sjt_math842;
    sjt_dot652 = m;
    sjt_math843 = sjt_dot652->m31;
    sjt_dot653 = _parent;
    sjt_math844 = sjt_dot653->m12;
    sjt_math840 = sjt_math843 * sjt_math844;
    sjt_math837 = sjt_math839 + sjt_math840;
    sjt_dot654 = m;
    sjt_math845 = sjt_dot654->m32;
    sjt_dot655 = _parent;
    sjt_math846 = sjt_dot655->m22;
    sjt_math838 = sjt_math845 * sjt_math846;
    sjt_math835 = sjt_math837 + sjt_math838;
    sjt_dot656 = m;
    sjt_math847 = sjt_dot656->m33;
    sjt_dot657 = _parent;
    sjt_math848 = sjt_dot657->m32;
    sjt_math836 = sjt_math847 * sjt_math848;
    (*_return)->m32 = sjt_math835 + sjt_math836;
    sjt_dot658 = m;
    sjt_math855 = sjt_dot658->m30;
    sjt_dot659 = _parent;
    sjt_math856 = sjt_dot659->m03;
    sjt_math853 = sjt_math855 * sjt_math856;
    sjt_dot660 = m;
    sjt_math857 = sjt_dot660->m31;
    sjt_dot661 = _parent;
    sjt_math858 = sjt_dot661->m13;
    sjt_math854 = sjt_math857 * sjt_math858;
    sjt_math851 = sjt_math853 + sjt_math854;
    sjt_dot662 = m;
    sjt_math859 = sjt_dot662->m32;
    sjt_dot663 = _parent;
    sjt_math860 = sjt_dot663->m23;
    sjt_math852 = sjt_math859 * sjt_math860;
    sjt_math849 = sjt_math851 + sjt_math852;
    sjt_dot664 = m;
    sjt_math861 = sjt_dot664->m33;
    sjt_dot665 = _parent;
    sjt_math862 = sjt_dot665->m33;
    sjt_math850 = sjt_math861 * sjt_math862;
    (*_return)->m33 = sjt_math849 + sjt_math850;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyf32(sjs_mat4* _parent, float x, sjs_mat4* _return) {
    sjs_mat4* sjt_dot1028 = 0;
    sjs_mat4* sjt_dot1029 = 0;
    sjs_mat4* sjt_dot1030 = 0;
    sjs_mat4* sjt_dot1031 = 0;
    sjs_mat4* sjt_dot1032 = 0;
    sjs_mat4* sjt_dot1033 = 0;
    sjs_mat4* sjt_dot1034 = 0;
    sjs_mat4* sjt_dot1035 = 0;
    sjs_mat4* sjt_dot1036 = 0;
    sjs_mat4* sjt_dot1037 = 0;
    sjs_mat4* sjt_dot1038 = 0;
    sjs_mat4* sjt_dot1039 = 0;
    sjs_mat4* sjt_dot1040 = 0;
    sjs_mat4* sjt_dot1041 = 0;
    sjs_mat4* sjt_dot1042 = 0;
    sjs_mat4* sjt_dot1043 = 0;
    float sjt_math1415;
    float sjt_math1416;
    float sjt_math1417;
    float sjt_math1418;
    float sjt_math1419;
    float sjt_math1420;
    float sjt_math1421;
    float sjt_math1422;
    float sjt_math1423;
    float sjt_math1424;
    float sjt_math1425;
    float sjt_math1426;
    float sjt_math1427;
    float sjt_math1428;
    float sjt_math1429;
    float sjt_math1430;
    float sjt_math1431;
    float sjt_math1432;
    float sjt_math1433;
    float sjt_math1434;
    float sjt_math1435;
    float sjt_math1436;
    float sjt_math1437;
    float sjt_math1438;
    float sjt_math1439;
    float sjt_math1440;
    float sjt_math1441;
    float sjt_math1442;
    float sjt_math1443;
    float sjt_math1444;
    float sjt_math1445;
    float sjt_math1446;

    _return->_refCount = 1;
    sjt_dot1028 = _parent;
    sjt_math1415 = sjt_dot1028->m00;
    sjt_math1416 = x;
    _return->m00 = sjt_math1415 * sjt_math1416;
    sjt_dot1029 = _parent;
    sjt_math1417 = sjt_dot1029->m01;
    sjt_math1418 = x;
    _return->m01 = sjt_math1417 * sjt_math1418;
    sjt_dot1030 = _parent;
    sjt_math1419 = sjt_dot1030->m02;
    sjt_math1420 = x;
    _return->m02 = sjt_math1419 * sjt_math1420;
    sjt_dot1031 = _parent;
    sjt_math1421 = sjt_dot1031->m03;
    sjt_math1422 = x;
    _return->m03 = sjt_math1421 * sjt_math1422;
    sjt_dot1032 = _parent;
    sjt_math1423 = sjt_dot1032->m10;
    sjt_math1424 = x;
    _return->m10 = sjt_math1423 * sjt_math1424;
    sjt_dot1033 = _parent;
    sjt_math1425 = sjt_dot1033->m11;
    sjt_math1426 = x;
    _return->m11 = sjt_math1425 * sjt_math1426;
    sjt_dot1034 = _parent;
    sjt_math1427 = sjt_dot1034->m12;
    sjt_math1428 = x;
    _return->m12 = sjt_math1427 * sjt_math1428;
    sjt_dot1035 = _parent;
    sjt_math1429 = sjt_dot1035->m13;
    sjt_math1430 = x;
    _return->m13 = sjt_math1429 * sjt_math1430;
    sjt_dot1036 = _parent;
    sjt_math1431 = sjt_dot1036->m20;
    sjt_math1432 = x;
    _return->m20 = sjt_math1431 * sjt_math1432;
    sjt_dot1037 = _parent;
    sjt_math1433 = sjt_dot1037->m21;
    sjt_math1434 = x;
    _return->m21 = sjt_math1433 * sjt_math1434;
    sjt_dot1038 = _parent;
    sjt_math1435 = sjt_dot1038->m22;
    sjt_math1436 = x;
    _return->m22 = sjt_math1435 * sjt_math1436;
    sjt_dot1039 = _parent;
    sjt_math1437 = sjt_dot1039->m23;
    sjt_math1438 = x;
    _return->m23 = sjt_math1437 * sjt_math1438;
    sjt_dot1040 = _parent;
    sjt_math1439 = sjt_dot1040->m30;
    sjt_math1440 = x;
    _return->m30 = sjt_math1439 * sjt_math1440;
    sjt_dot1041 = _parent;
    sjt_math1441 = sjt_dot1041->m31;
    sjt_math1442 = x;
    _return->m31 = sjt_math1441 * sjt_math1442;
    sjt_dot1042 = _parent;
    sjt_math1443 = sjt_dot1042->m32;
    sjt_math1444 = x;
    _return->m32 = sjt_math1443 * sjt_math1444;
    sjt_dot1043 = _parent;
    sjt_math1445 = sjt_dot1043->m33;
    sjt_math1446 = x;
    _return->m33 = sjt_math1445 * sjt_math1446;
    sjf_mat4(_return);
}

void sjf_mat4_multiplyf32_heap(sjs_mat4* _parent, float x, sjs_mat4** _return) {
    sjs_mat4* sjt_dot1044 = 0;
    sjs_mat4* sjt_dot1045 = 0;
    sjs_mat4* sjt_dot1046 = 0;
    sjs_mat4* sjt_dot1047 = 0;
    sjs_mat4* sjt_dot1048 = 0;
    sjs_mat4* sjt_dot1049 = 0;
    sjs_mat4* sjt_dot1050 = 0;
    sjs_mat4* sjt_dot1051 = 0;
    sjs_mat4* sjt_dot1052 = 0;
    sjs_mat4* sjt_dot1053 = 0;
    sjs_mat4* sjt_dot1054 = 0;
    sjs_mat4* sjt_dot1055 = 0;
    sjs_mat4* sjt_dot1056 = 0;
    sjs_mat4* sjt_dot1057 = 0;
    sjs_mat4* sjt_dot1058 = 0;
    sjs_mat4* sjt_dot1059 = 0;
    float sjt_math1447;
    float sjt_math1448;
    float sjt_math1449;
    float sjt_math1450;
    float sjt_math1451;
    float sjt_math1452;
    float sjt_math1453;
    float sjt_math1454;
    float sjt_math1455;
    float sjt_math1456;
    float sjt_math1457;
    float sjt_math1458;
    float sjt_math1459;
    float sjt_math1460;
    float sjt_math1461;
    float sjt_math1462;
    float sjt_math1463;
    float sjt_math1464;
    float sjt_math1465;
    float sjt_math1466;
    float sjt_math1467;
    float sjt_math1468;
    float sjt_math1469;
    float sjt_math1470;
    float sjt_math1471;
    float sjt_math1472;
    float sjt_math1473;
    float sjt_math1474;
    float sjt_math1475;
    float sjt_math1476;
    float sjt_math1477;
    float sjt_math1478;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot1044 = _parent;
    sjt_math1447 = sjt_dot1044->m00;
    sjt_math1448 = x;
    (*_return)->m00 = sjt_math1447 * sjt_math1448;
    sjt_dot1045 = _parent;
    sjt_math1449 = sjt_dot1045->m01;
    sjt_math1450 = x;
    (*_return)->m01 = sjt_math1449 * sjt_math1450;
    sjt_dot1046 = _parent;
    sjt_math1451 = sjt_dot1046->m02;
    sjt_math1452 = x;
    (*_return)->m02 = sjt_math1451 * sjt_math1452;
    sjt_dot1047 = _parent;
    sjt_math1453 = sjt_dot1047->m03;
    sjt_math1454 = x;
    (*_return)->m03 = sjt_math1453 * sjt_math1454;
    sjt_dot1048 = _parent;
    sjt_math1455 = sjt_dot1048->m10;
    sjt_math1456 = x;
    (*_return)->m10 = sjt_math1455 * sjt_math1456;
    sjt_dot1049 = _parent;
    sjt_math1457 = sjt_dot1049->m11;
    sjt_math1458 = x;
    (*_return)->m11 = sjt_math1457 * sjt_math1458;
    sjt_dot1050 = _parent;
    sjt_math1459 = sjt_dot1050->m12;
    sjt_math1460 = x;
    (*_return)->m12 = sjt_math1459 * sjt_math1460;
    sjt_dot1051 = _parent;
    sjt_math1461 = sjt_dot1051->m13;
    sjt_math1462 = x;
    (*_return)->m13 = sjt_math1461 * sjt_math1462;
    sjt_dot1052 = _parent;
    sjt_math1463 = sjt_dot1052->m20;
    sjt_math1464 = x;
    (*_return)->m20 = sjt_math1463 * sjt_math1464;
    sjt_dot1053 = _parent;
    sjt_math1465 = sjt_dot1053->m21;
    sjt_math1466 = x;
    (*_return)->m21 = sjt_math1465 * sjt_math1466;
    sjt_dot1054 = _parent;
    sjt_math1467 = sjt_dot1054->m22;
    sjt_math1468 = x;
    (*_return)->m22 = sjt_math1467 * sjt_math1468;
    sjt_dot1055 = _parent;
    sjt_math1469 = sjt_dot1055->m23;
    sjt_math1470 = x;
    (*_return)->m23 = sjt_math1469 * sjt_math1470;
    sjt_dot1056 = _parent;
    sjt_math1471 = sjt_dot1056->m30;
    sjt_math1472 = x;
    (*_return)->m30 = sjt_math1471 * sjt_math1472;
    sjt_dot1057 = _parent;
    sjt_math1473 = sjt_dot1057->m31;
    sjt_math1474 = x;
    (*_return)->m31 = sjt_math1473 * sjt_math1474;
    sjt_dot1058 = _parent;
    sjt_math1475 = sjt_dot1058->m32;
    sjt_math1476 = x;
    (*_return)->m32 = sjt_math1475 * sjt_math1476;
    sjt_dot1059 = _parent;
    sjt_math1477 = sjt_dot1059->m33;
    sjt_math1478 = x;
    (*_return)->m33 = sjt_math1477 * sjt_math1478;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyvec4(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4* _return) {
    sjs_mat4* sjt_dot346 = 0;
    sjs_vec4* sjt_dot347 = 0;
    sjs_mat4* sjt_dot348 = 0;
    sjs_vec4* sjt_dot349 = 0;
    sjs_mat4* sjt_dot350 = 0;
    sjs_vec4* sjt_dot351 = 0;
    sjs_mat4* sjt_dot352 = 0;
    sjs_vec4* sjt_dot353 = 0;
    sjs_mat4* sjt_dot354 = 0;
    sjs_vec4* sjt_dot355 = 0;
    sjs_mat4* sjt_dot356 = 0;
    sjs_vec4* sjt_dot357 = 0;
    sjs_mat4* sjt_dot358 = 0;
    sjs_vec4* sjt_dot359 = 0;
    sjs_mat4* sjt_dot360 = 0;
    sjs_vec4* sjt_dot361 = 0;
    sjs_mat4* sjt_dot362 = 0;
    sjs_vec4* sjt_dot363 = 0;
    sjs_mat4* sjt_dot364 = 0;
    sjs_vec4* sjt_dot365 = 0;
    sjs_mat4* sjt_dot366 = 0;
    sjs_vec4* sjt_dot367 = 0;
    sjs_mat4* sjt_dot368 = 0;
    sjs_vec4* sjt_dot369 = 0;
    sjs_mat4* sjt_dot370 = 0;
    sjs_vec4* sjt_dot371 = 0;
    sjs_mat4* sjt_dot372 = 0;
    sjs_vec4* sjt_dot373 = 0;
    sjs_mat4* sjt_dot374 = 0;
    sjs_vec4* sjt_dot375 = 0;
    sjs_mat4* sjt_dot376 = 0;
    sjs_vec4* sjt_dot377 = 0;
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
    float sjt_math337;
    float sjt_math338;
    float sjt_math339;
    float sjt_math340;
    float sjt_math341;
    float sjt_math342;
    float sjt_math343;
    float sjt_math344;
    float sjt_math345;
    float sjt_math346;
    float sjt_math347;
    float sjt_math348;
    float sjt_math349;
    float sjt_math350;
    float sjt_math351;
    float sjt_math352;
    float sjt_math353;
    float sjt_math354;
    float sjt_math355;
    float sjt_math356;
    float sjt_math357;
    float sjt_math358;

    _return->_refCount = 1;
    sjt_dot346 = _parent;
    sjt_math309 = sjt_dot346->m00;
    sjt_dot347 = v;
    sjt_math310 = sjt_dot347->x;
    sjt_math307 = sjt_math309 * sjt_math310;
    sjt_dot348 = _parent;
    sjt_math311 = sjt_dot348->m10;
    sjt_dot349 = v;
    sjt_math312 = sjt_dot349->y;
    sjt_math308 = sjt_math311 * sjt_math312;
    sjt_math305 = sjt_math307 + sjt_math308;
    sjt_dot350 = _parent;
    sjt_math313 = sjt_dot350->m20;
    sjt_dot351 = v;
    sjt_math314 = sjt_dot351->z;
    sjt_math306 = sjt_math313 * sjt_math314;
    sjt_math303 = sjt_math305 + sjt_math306;
    sjt_dot352 = _parent;
    sjt_math315 = sjt_dot352->m30;
    sjt_dot353 = v;
    sjt_math316 = sjt_dot353->w;
    sjt_math304 = sjt_math315 * sjt_math316;
    _return->x = sjt_math303 + sjt_math304;
    sjt_dot354 = _parent;
    sjt_math323 = sjt_dot354->m01;
    sjt_dot355 = v;
    sjt_math324 = sjt_dot355->x;
    sjt_math321 = sjt_math323 * sjt_math324;
    sjt_dot356 = _parent;
    sjt_math325 = sjt_dot356->m11;
    sjt_dot357 = v;
    sjt_math326 = sjt_dot357->y;
    sjt_math322 = sjt_math325 * sjt_math326;
    sjt_math319 = sjt_math321 + sjt_math322;
    sjt_dot358 = _parent;
    sjt_math327 = sjt_dot358->m21;
    sjt_dot359 = v;
    sjt_math328 = sjt_dot359->z;
    sjt_math320 = sjt_math327 * sjt_math328;
    sjt_math317 = sjt_math319 + sjt_math320;
    sjt_dot360 = _parent;
    sjt_math329 = sjt_dot360->m31;
    sjt_dot361 = v;
    sjt_math330 = sjt_dot361->w;
    sjt_math318 = sjt_math329 * sjt_math330;
    _return->y = sjt_math317 + sjt_math318;
    sjt_dot362 = _parent;
    sjt_math337 = sjt_dot362->m02;
    sjt_dot363 = v;
    sjt_math338 = sjt_dot363->x;
    sjt_math335 = sjt_math337 * sjt_math338;
    sjt_dot364 = _parent;
    sjt_math339 = sjt_dot364->m12;
    sjt_dot365 = v;
    sjt_math340 = sjt_dot365->y;
    sjt_math336 = sjt_math339 * sjt_math340;
    sjt_math333 = sjt_math335 + sjt_math336;
    sjt_dot366 = _parent;
    sjt_math341 = sjt_dot366->m22;
    sjt_dot367 = v;
    sjt_math342 = sjt_dot367->z;
    sjt_math334 = sjt_math341 * sjt_math342;
    sjt_math331 = sjt_math333 + sjt_math334;
    sjt_dot368 = _parent;
    sjt_math343 = sjt_dot368->m32;
    sjt_dot369 = v;
    sjt_math344 = sjt_dot369->w;
    sjt_math332 = sjt_math343 * sjt_math344;
    _return->z = sjt_math331 + sjt_math332;
    sjt_dot370 = _parent;
    sjt_math351 = sjt_dot370->m03;
    sjt_dot371 = v;
    sjt_math352 = sjt_dot371->x;
    sjt_math349 = sjt_math351 * sjt_math352;
    sjt_dot372 = _parent;
    sjt_math353 = sjt_dot372->m13;
    sjt_dot373 = v;
    sjt_math354 = sjt_dot373->y;
    sjt_math350 = sjt_math353 * sjt_math354;
    sjt_math347 = sjt_math349 + sjt_math350;
    sjt_dot374 = _parent;
    sjt_math355 = sjt_dot374->m23;
    sjt_dot375 = v;
    sjt_math356 = sjt_dot375->z;
    sjt_math348 = sjt_math355 * sjt_math356;
    sjt_math345 = sjt_math347 + sjt_math348;
    sjt_dot376 = _parent;
    sjt_math357 = sjt_dot376->m33;
    sjt_dot377 = v;
    sjt_math358 = sjt_dot377->w;
    sjt_math346 = sjt_math357 * sjt_math358;
    _return->w = sjt_math345 + sjt_math346;
    sjf_vec4(_return);
}

void sjf_mat4_multiplyvec4_heap(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4** _return) {
    sjs_mat4* sjt_dot378 = 0;
    sjs_vec4* sjt_dot379 = 0;
    sjs_mat4* sjt_dot380 = 0;
    sjs_vec4* sjt_dot381 = 0;
    sjs_mat4* sjt_dot382 = 0;
    sjs_vec4* sjt_dot383 = 0;
    sjs_mat4* sjt_dot384 = 0;
    sjs_vec4* sjt_dot385 = 0;
    sjs_mat4* sjt_dot386 = 0;
    sjs_vec4* sjt_dot387 = 0;
    sjs_mat4* sjt_dot388 = 0;
    sjs_vec4* sjt_dot389 = 0;
    sjs_mat4* sjt_dot390 = 0;
    sjs_vec4* sjt_dot391 = 0;
    sjs_mat4* sjt_dot392 = 0;
    sjs_vec4* sjt_dot393 = 0;
    sjs_mat4* sjt_dot394 = 0;
    sjs_vec4* sjt_dot395 = 0;
    sjs_mat4* sjt_dot396 = 0;
    sjs_vec4* sjt_dot397 = 0;
    sjs_mat4* sjt_dot398 = 0;
    sjs_vec4* sjt_dot399 = 0;
    sjs_mat4* sjt_dot400 = 0;
    sjs_vec4* sjt_dot401 = 0;
    sjs_mat4* sjt_dot402 = 0;
    sjs_vec4* sjt_dot403 = 0;
    sjs_mat4* sjt_dot404 = 0;
    sjs_vec4* sjt_dot405 = 0;
    sjs_mat4* sjt_dot406 = 0;
    sjs_vec4* sjt_dot407 = 0;
    sjs_mat4* sjt_dot408 = 0;
    sjs_vec4* sjt_dot409 = 0;
    float sjt_math359;
    float sjt_math360;
    float sjt_math361;
    float sjt_math362;
    float sjt_math363;
    float sjt_math364;
    float sjt_math365;
    float sjt_math366;
    float sjt_math367;
    float sjt_math368;
    float sjt_math369;
    float sjt_math370;
    float sjt_math371;
    float sjt_math372;
    float sjt_math373;
    float sjt_math374;
    float sjt_math375;
    float sjt_math376;
    float sjt_math377;
    float sjt_math378;
    float sjt_math379;
    float sjt_math380;
    float sjt_math381;
    float sjt_math382;
    float sjt_math383;
    float sjt_math384;
    float sjt_math385;
    float sjt_math386;
    float sjt_math387;
    float sjt_math388;
    float sjt_math389;
    float sjt_math390;
    float sjt_math391;
    float sjt_math392;
    float sjt_math393;
    float sjt_math394;
    float sjt_math395;
    float sjt_math396;
    float sjt_math397;
    float sjt_math398;
    float sjt_math399;
    float sjt_math400;
    float sjt_math401;
    float sjt_math402;
    float sjt_math403;
    float sjt_math404;
    float sjt_math405;
    float sjt_math406;
    float sjt_math407;
    float sjt_math408;
    float sjt_math409;
    float sjt_math410;
    float sjt_math411;
    float sjt_math412;
    float sjt_math413;
    float sjt_math414;

    (*_return) = (sjs_vec4*)malloc(sizeof(sjs_vec4));
    (*_return)->_refCount = 1;
    sjt_dot378 = _parent;
    sjt_math365 = sjt_dot378->m00;
    sjt_dot379 = v;
    sjt_math366 = sjt_dot379->x;
    sjt_math363 = sjt_math365 * sjt_math366;
    sjt_dot380 = _parent;
    sjt_math367 = sjt_dot380->m10;
    sjt_dot381 = v;
    sjt_math368 = sjt_dot381->y;
    sjt_math364 = sjt_math367 * sjt_math368;
    sjt_math361 = sjt_math363 + sjt_math364;
    sjt_dot382 = _parent;
    sjt_math369 = sjt_dot382->m20;
    sjt_dot383 = v;
    sjt_math370 = sjt_dot383->z;
    sjt_math362 = sjt_math369 * sjt_math370;
    sjt_math359 = sjt_math361 + sjt_math362;
    sjt_dot384 = _parent;
    sjt_math371 = sjt_dot384->m30;
    sjt_dot385 = v;
    sjt_math372 = sjt_dot385->w;
    sjt_math360 = sjt_math371 * sjt_math372;
    (*_return)->x = sjt_math359 + sjt_math360;
    sjt_dot386 = _parent;
    sjt_math379 = sjt_dot386->m01;
    sjt_dot387 = v;
    sjt_math380 = sjt_dot387->x;
    sjt_math377 = sjt_math379 * sjt_math380;
    sjt_dot388 = _parent;
    sjt_math381 = sjt_dot388->m11;
    sjt_dot389 = v;
    sjt_math382 = sjt_dot389->y;
    sjt_math378 = sjt_math381 * sjt_math382;
    sjt_math375 = sjt_math377 + sjt_math378;
    sjt_dot390 = _parent;
    sjt_math383 = sjt_dot390->m21;
    sjt_dot391 = v;
    sjt_math384 = sjt_dot391->z;
    sjt_math376 = sjt_math383 * sjt_math384;
    sjt_math373 = sjt_math375 + sjt_math376;
    sjt_dot392 = _parent;
    sjt_math385 = sjt_dot392->m31;
    sjt_dot393 = v;
    sjt_math386 = sjt_dot393->w;
    sjt_math374 = sjt_math385 * sjt_math386;
    (*_return)->y = sjt_math373 + sjt_math374;
    sjt_dot394 = _parent;
    sjt_math393 = sjt_dot394->m02;
    sjt_dot395 = v;
    sjt_math394 = sjt_dot395->x;
    sjt_math391 = sjt_math393 * sjt_math394;
    sjt_dot396 = _parent;
    sjt_math395 = sjt_dot396->m12;
    sjt_dot397 = v;
    sjt_math396 = sjt_dot397->y;
    sjt_math392 = sjt_math395 * sjt_math396;
    sjt_math389 = sjt_math391 + sjt_math392;
    sjt_dot398 = _parent;
    sjt_math397 = sjt_dot398->m22;
    sjt_dot399 = v;
    sjt_math398 = sjt_dot399->z;
    sjt_math390 = sjt_math397 * sjt_math398;
    sjt_math387 = sjt_math389 + sjt_math390;
    sjt_dot400 = _parent;
    sjt_math399 = sjt_dot400->m32;
    sjt_dot401 = v;
    sjt_math400 = sjt_dot401->w;
    sjt_math388 = sjt_math399 * sjt_math400;
    (*_return)->z = sjt_math387 + sjt_math388;
    sjt_dot402 = _parent;
    sjt_math407 = sjt_dot402->m03;
    sjt_dot403 = v;
    sjt_math408 = sjt_dot403->x;
    sjt_math405 = sjt_math407 * sjt_math408;
    sjt_dot404 = _parent;
    sjt_math409 = sjt_dot404->m13;
    sjt_dot405 = v;
    sjt_math410 = sjt_dot405->y;
    sjt_math406 = sjt_math409 * sjt_math410;
    sjt_math403 = sjt_math405 + sjt_math406;
    sjt_dot406 = _parent;
    sjt_math411 = sjt_dot406->m23;
    sjt_dot407 = v;
    sjt_math412 = sjt_dot407->z;
    sjt_math404 = sjt_math411 * sjt_math412;
    sjt_math401 = sjt_math403 + sjt_math404;
    sjt_dot408 = _parent;
    sjt_math413 = sjt_dot408->m33;
    sjt_dot409 = v;
    sjt_math414 = sjt_dot409->w;
    sjt_math402 = sjt_math413 * sjt_math414;
    (*_return)->w = sjt_math401 + sjt_math402;
    sjf_vec4_heap((*_return));
}

void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return) {
    float result16;
    float sjt_math2337;
    float sjt_math2338;
    float sjt_math2339;
    float sjt_math2340;
    float sjt_math2341;
    float sjt_math2342;
    float sjt_math2343;
    float sjt_math2344;
    float sjt_math2345;
    float sjt_math2346;
    float sjt_math2347;
    float sjt_math2348;
    float sjt_math2349;
    float sjt_math2350;
    float sjt_math2351;
    float sjt_math2352;
    float sjt_math2353;
    float sjt_math2354;
    float sjt_math2355;
    float sjt_math2356;
    float sjt_math2357;
    float sjt_math2358;
    float sjt_math2359;
    float sjt_math2360;
    float sjt_math2361;
    float sjt_math2362;
    float sjt_math2363;
    float sjt_math2364;
    float sjt_math2365;
    float sjt_math2366;
    float sjt_math2367;
    float sjt_math2368;
    float sjt_math2369;
    float sjt_math2370;
    float sjt_math2371;
    float sjt_math2372;
    float sjt_negate4;

    _return->_refCount = 1;
    sjt_math2337 = 2.0f;
    sjt_math2339 = right;
    sjt_math2340 = left;
    sjt_math2338 = sjt_math2339 - sjt_math2340;
    _return->m00 = sjt_math2337 / sjt_math2338;
    _return->m01 = 0.0f;
    _return->m02 = 0.0f;
    _return->m03 = 0.0f;
    _return->m10 = 0.0f;
    sjt_math2341 = 2.0f;
    sjt_math2343 = top;
    sjt_math2344 = bottom;
    sjt_math2342 = sjt_math2343 - sjt_math2344;
    _return->m11 = sjt_math2341 / sjt_math2342;
    _return->m12 = 0.0f;
    _return->m13 = 0.0f;
    _return->m20 = 0.0f;
    _return->m21 = 0.0f;
    sjt_negate4 = 2.0f;
    result16 = -sjt_negate4;
    sjt_math2345 = result16;
    sjt_math2347 = zfar;
    sjt_math2348 = znear;
    sjt_math2346 = sjt_math2347 - sjt_math2348;
    _return->m22 = sjt_math2345 / sjt_math2346;
    _return->m23 = 0.0f;
    sjt_math2349 = 0.0f;
    sjt_math2353 = right;
    sjt_math2354 = left;
    sjt_math2351 = sjt_math2353 + sjt_math2354;
    sjt_math2355 = right;
    sjt_math2356 = left;
    sjt_math2352 = sjt_math2355 - sjt_math2356;
    sjt_math2350 = sjt_math2351 / sjt_math2352;
    _return->m30 = sjt_math2349 - sjt_math2350;
    sjt_math2357 = 0.0f;
    sjt_math2361 = top;
    sjt_math2362 = bottom;
    sjt_math2359 = sjt_math2361 + sjt_math2362;
    sjt_math2363 = top;
    sjt_math2364 = bottom;
    sjt_math2360 = sjt_math2363 - sjt_math2364;
    sjt_math2358 = sjt_math2359 / sjt_math2360;
    _return->m31 = sjt_math2357 - sjt_math2358;
    sjt_math2365 = 0.0f;
    sjt_math2369 = zfar;
    sjt_math2370 = znear;
    sjt_math2367 = sjt_math2369 + sjt_math2370;
    sjt_math2371 = zfar;
    sjt_math2372 = znear;
    sjt_math2368 = sjt_math2371 - sjt_math2372;
    sjt_math2366 = sjt_math2367 / sjt_math2368;
    _return->m32 = sjt_math2365 - sjt_math2366;
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return) {
    float result17;
    float sjt_math2373;
    float sjt_math2374;
    float sjt_math2375;
    float sjt_math2376;
    float sjt_math2377;
    float sjt_math2378;
    float sjt_math2379;
    float sjt_math2380;
    float sjt_math2381;
    float sjt_math2382;
    float sjt_math2383;
    float sjt_math2384;
    float sjt_math2385;
    float sjt_math2386;
    float sjt_math2387;
    float sjt_math2388;
    float sjt_math2389;
    float sjt_math2390;
    float sjt_math2391;
    float sjt_math2392;
    float sjt_math2393;
    float sjt_math2394;
    float sjt_math2395;
    float sjt_math2396;
    float sjt_math2397;
    float sjt_math2398;
    float sjt_math2399;
    float sjt_math2400;
    float sjt_math2401;
    float sjt_math2402;
    float sjt_math2403;
    float sjt_math2404;
    float sjt_math2405;
    float sjt_math2406;
    float sjt_math2407;
    float sjt_math2408;
    float sjt_negate5;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_math2373 = 2.0f;
    sjt_math2375 = right;
    sjt_math2376 = left;
    sjt_math2374 = sjt_math2375 - sjt_math2376;
    (*_return)->m00 = sjt_math2373 / sjt_math2374;
    (*_return)->m01 = 0.0f;
    (*_return)->m02 = 0.0f;
    (*_return)->m03 = 0.0f;
    (*_return)->m10 = 0.0f;
    sjt_math2377 = 2.0f;
    sjt_math2379 = top;
    sjt_math2380 = bottom;
    sjt_math2378 = sjt_math2379 - sjt_math2380;
    (*_return)->m11 = sjt_math2377 / sjt_math2378;
    (*_return)->m12 = 0.0f;
    (*_return)->m13 = 0.0f;
    (*_return)->m20 = 0.0f;
    (*_return)->m21 = 0.0f;
    sjt_negate5 = 2.0f;
    result17 = -sjt_negate5;
    sjt_math2381 = result17;
    sjt_math2383 = zfar;
    sjt_math2384 = znear;
    sjt_math2382 = sjt_math2383 - sjt_math2384;
    (*_return)->m22 = sjt_math2381 / sjt_math2382;
    (*_return)->m23 = 0.0f;
    sjt_math2385 = 0.0f;
    sjt_math2389 = right;
    sjt_math2390 = left;
    sjt_math2387 = sjt_math2389 + sjt_math2390;
    sjt_math2391 = right;
    sjt_math2392 = left;
    sjt_math2388 = sjt_math2391 - sjt_math2392;
    sjt_math2386 = sjt_math2387 / sjt_math2388;
    (*_return)->m30 = sjt_math2385 - sjt_math2386;
    sjt_math2393 = 0.0f;
    sjt_math2397 = top;
    sjt_math2398 = bottom;
    sjt_math2395 = sjt_math2397 + sjt_math2398;
    sjt_math2399 = top;
    sjt_math2400 = bottom;
    sjt_math2396 = sjt_math2399 - sjt_math2400;
    sjt_math2394 = sjt_math2395 / sjt_math2396;
    (*_return)->m31 = sjt_math2393 - sjt_math2394;
    sjt_math2401 = 0.0f;
    sjt_math2405 = zfar;
    sjt_math2406 = znear;
    sjt_math2403 = sjt_math2405 + sjt_math2406;
    sjt_math2407 = zfar;
    sjt_math2408 = znear;
    sjt_math2404 = sjt_math2407 - sjt_math2408;
    sjt_math2402 = sjt_math2403 / sjt_math2404;
    (*_return)->m32 = sjt_math2401 - sjt_math2402;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_perspective(float fovy, float aspect, float znear, float zfar, sjs_mat4* _return) {
    float sjt_functionParam66;
    float sjt_math125;
    float sjt_math126;
    float sjt_math127;
    float sjt_math128;
    float sjt_math129;
    float sjt_math130;
    float sjt_math131;
    float sjt_math132;
    float sjt_math133;
    float sjt_math134;
    float sjt_math135;
    float sjt_math136;
    float sjt_math137;
    float sjt_math138;
    float sjt_math139;
    float sjt_math140;
    float sjt_math141;
    float sjt_math142;
    float sjt_math143;
    float sjt_math144;
    float sjv_xscale;
    float sjv_yscale;

    sjt_math125 = 1.0f;
    sjt_math129 = fovy;
    sjt_math130 = 180.0f;
    sjt_math127 = sjt_math129 / sjt_math130;
    sjt_math128 = 2.0f;
    sjt_functionParam66 = sjt_math127 / sjt_math128;
    sjf_f32_tan(sjt_functionParam66, &sjt_math126);
    sjv_yscale = sjt_math125 / sjt_math126;
    sjt_math131 = sjv_yscale;
    sjt_math132 = aspect;
    sjv_xscale = sjt_math131 * sjt_math132;
    _return->_refCount = 1;
    _return->m00 = sjv_xscale;
    _return->m01 = 0.0f;
    _return->m02 = 0.0f;
    _return->m03 = 0.0f;
    _return->m10 = 0.0f;
    _return->m11 = sjv_yscale;
    _return->m12 = 0.0f;
    _return->m13 = 0.0f;
    _return->m20 = 0.0f;
    _return->m21 = 0.0f;
    sjt_math133 = zfar;
    sjt_math135 = zfar;
    sjt_math136 = znear;
    sjt_math134 = sjt_math135 - sjt_math136;
    _return->m22 = sjt_math133 / sjt_math134;
    _return->m23 = 1.0f;
    _return->m30 = 0.0f;
    _return->m31 = 0.0f;
    sjt_math137 = 0.0f;
    sjt_math141 = znear;
    sjt_math142 = zfar;
    sjt_math139 = sjt_math141 * sjt_math142;
    sjt_math143 = zfar;
    sjt_math144 = znear;
    sjt_math140 = sjt_math143 - sjt_math144;
    sjt_math138 = sjt_math139 / sjt_math140;
    _return->m32 = sjt_math137 - sjt_math138;
    _return->m33 = 0.0f;
    sjf_mat4(_return);
}

void sjf_mat4_perspective_heap(float fovy, float aspect, float znear, float zfar, sjs_mat4** _return) {
    float sjt_functionParam67;
    float sjt_math145;
    float sjt_math146;
    float sjt_math147;
    float sjt_math148;
    float sjt_math149;
    float sjt_math150;
    float sjt_math151;
    float sjt_math152;
    float sjt_math153;
    float sjt_math154;
    float sjt_math155;
    float sjt_math156;
    float sjt_math157;
    float sjt_math158;
    float sjt_math159;
    float sjt_math160;
    float sjt_math161;
    float sjt_math162;
    float sjt_math163;
    float sjt_math164;
    float sjv_xscale;
    float sjv_yscale;

    sjt_math145 = 1.0f;
    sjt_math149 = fovy;
    sjt_math150 = 180.0f;
    sjt_math147 = sjt_math149 / sjt_math150;
    sjt_math148 = 2.0f;
    sjt_functionParam67 = sjt_math147 / sjt_math148;
    sjf_f32_tan(sjt_functionParam67, &sjt_math146);
    sjv_yscale = sjt_math145 / sjt_math146;
    sjt_math151 = sjv_yscale;
    sjt_math152 = aspect;
    sjv_xscale = sjt_math151 * sjt_math152;
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    (*_return)->m00 = sjv_xscale;
    (*_return)->m01 = 0.0f;
    (*_return)->m02 = 0.0f;
    (*_return)->m03 = 0.0f;
    (*_return)->m10 = 0.0f;
    (*_return)->m11 = sjv_yscale;
    (*_return)->m12 = 0.0f;
    (*_return)->m13 = 0.0f;
    (*_return)->m20 = 0.0f;
    (*_return)->m21 = 0.0f;
    sjt_math153 = zfar;
    sjt_math155 = zfar;
    sjt_math156 = znear;
    sjt_math154 = sjt_math155 - sjt_math156;
    (*_return)->m22 = sjt_math153 / sjt_math154;
    (*_return)->m23 = 1.0f;
    (*_return)->m30 = 0.0f;
    (*_return)->m31 = 0.0f;
    sjt_math157 = 0.0f;
    sjt_math161 = znear;
    sjt_math162 = zfar;
    sjt_math159 = sjt_math161 * sjt_math162;
    sjt_math163 = zfar;
    sjt_math164 = znear;
    sjt_math160 = sjt_math163 - sjt_math164;
    sjt_math158 = sjt_math159 / sjt_math160;
    (*_return)->m32 = sjt_math157 - sjt_math158;
    (*_return)->m33 = 0.0f;
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

void sjf_mat4_transpose(sjs_mat4* _parent, sjs_mat4* _return) {
    sjs_mat4* sjt_dot708 = 0;
    sjs_mat4* sjt_dot709 = 0;
    sjs_mat4* sjt_dot710 = 0;
    sjs_mat4* sjt_dot711 = 0;
    sjs_mat4* sjt_dot712 = 0;
    sjs_mat4* sjt_dot713 = 0;
    sjs_mat4* sjt_dot714 = 0;
    sjs_mat4* sjt_dot715 = 0;
    sjs_mat4* sjt_dot716 = 0;
    sjs_mat4* sjt_dot717 = 0;
    sjs_mat4* sjt_dot718 = 0;
    sjs_mat4* sjt_dot719 = 0;
    sjs_mat4* sjt_dot720 = 0;
    sjs_mat4* sjt_dot721 = 0;
    sjs_mat4* sjt_dot722 = 0;
    sjs_mat4* sjt_dot723 = 0;

    _return->_refCount = 1;
    sjt_dot708 = _parent;
    _return->m00 = sjt_dot708->m00;
    sjt_dot709 = _parent;
    _return->m01 = sjt_dot709->m10;
    sjt_dot710 = _parent;
    _return->m02 = sjt_dot710->m20;
    sjt_dot711 = _parent;
    _return->m03 = sjt_dot711->m30;
    sjt_dot712 = _parent;
    _return->m10 = sjt_dot712->m01;
    sjt_dot713 = _parent;
    _return->m11 = sjt_dot713->m11;
    sjt_dot714 = _parent;
    _return->m12 = sjt_dot714->m21;
    sjt_dot715 = _parent;
    _return->m13 = sjt_dot715->m31;
    sjt_dot716 = _parent;
    _return->m20 = sjt_dot716->m02;
    sjt_dot717 = _parent;
    _return->m21 = sjt_dot717->m12;
    sjt_dot718 = _parent;
    _return->m22 = sjt_dot718->m22;
    sjt_dot719 = _parent;
    _return->m23 = sjt_dot719->m32;
    sjt_dot720 = _parent;
    _return->m30 = sjt_dot720->m03;
    sjt_dot721 = _parent;
    _return->m31 = sjt_dot721->m13;
    sjt_dot722 = _parent;
    _return->m32 = sjt_dot722->m23;
    sjt_dot723 = _parent;
    _return->m33 = sjt_dot723->m33;
    sjf_mat4(_return);
}

void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4** _return) {
    sjs_mat4* sjt_dot724 = 0;
    sjs_mat4* sjt_dot725 = 0;
    sjs_mat4* sjt_dot726 = 0;
    sjs_mat4* sjt_dot727 = 0;
    sjs_mat4* sjt_dot728 = 0;
    sjs_mat4* sjt_dot729 = 0;
    sjs_mat4* sjt_dot730 = 0;
    sjs_mat4* sjt_dot731 = 0;
    sjs_mat4* sjt_dot732 = 0;
    sjs_mat4* sjt_dot733 = 0;
    sjs_mat4* sjt_dot734 = 0;
    sjs_mat4* sjt_dot735 = 0;
    sjs_mat4* sjt_dot736 = 0;
    sjs_mat4* sjt_dot737 = 0;
    sjs_mat4* sjt_dot738 = 0;
    sjs_mat4* sjt_dot739 = 0;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot724 = _parent;
    (*_return)->m00 = sjt_dot724->m00;
    sjt_dot725 = _parent;
    (*_return)->m01 = sjt_dot725->m10;
    sjt_dot726 = _parent;
    (*_return)->m02 = sjt_dot726->m20;
    sjt_dot727 = _parent;
    (*_return)->m03 = sjt_dot727->m30;
    sjt_dot728 = _parent;
    (*_return)->m10 = sjt_dot728->m01;
    sjt_dot729 = _parent;
    (*_return)->m11 = sjt_dot729->m11;
    sjt_dot730 = _parent;
    (*_return)->m12 = sjt_dot730->m21;
    sjt_dot731 = _parent;
    (*_return)->m13 = sjt_dot731->m31;
    sjt_dot732 = _parent;
    (*_return)->m20 = sjt_dot732->m02;
    sjt_dot733 = _parent;
    (*_return)->m21 = sjt_dot733->m12;
    sjt_dot734 = _parent;
    (*_return)->m22 = sjt_dot734->m22;
    sjt_dot735 = _parent;
    (*_return)->m23 = sjt_dot735->m32;
    sjt_dot736 = _parent;
    (*_return)->m30 = sjt_dot736->m03;
    sjt_dot737 = _parent;
    (*_return)->m31 = sjt_dot737->m13;
    sjt_dot738 = _parent;
    (*_return)->m32 = sjt_dot738->m23;
    sjt_dot739 = _parent;
    (*_return)->m33 = sjt_dot739->m33;
    sjf_mat4_heap((*_return));
}

void sjf_model_as_sji_model(sjs_model* _this, sji_model* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_model_model_vtbl;
}

void sjf_model_asinterface(sjs_model* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_model_typeId:  {
            sjf_model_as_sji_model(_this, (sji_model*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_model_copy(sjs_model* _this, sjs_model* _from) {
    _this->vertexbuffer._refCount = 1;
    sjf_vertexbuffer_vertex_location_texture_normal_copy(&_this->vertexbuffer, &_from->vertexbuffer);
    _this->shader._refCount = 1;
    sjf_shader_copy(&_this->shader, &_from->shader);
    _this->texture._refCount = 1;
    sjf_texture_copy(&_this->texture, &_from->texture);
    _this->model._refCount = 1;
    sjf_mat4_copy(&_this->model, &_from->model);
    _this->center._refCount = 1;
    sjf_vec3_copy(&_this->center, &_from->center);
    _this->hasalpha = _from->hasalpha;
    _this->id._refCount = 1;
    sjf_string_copy((_this->id._refCount != -1 ? &_this->id : 0), (_from->id._refCount != -1 ? &_from->id : 0));
    _this->_projection._refCount = 1;
    sjf_mat4_copy(&_this->_projection, &_from->_projection);
    _this->_view._refCount = 1;
    sjf_mat4_copy(&_this->_view, &_from->_view);
    _this->_world._refCount = 1;
    sjf_mat4_copy(&_this->_world, &_from->_world);
    _this->_light._refCount = 1;
    sjf_light_copy(&_this->_light, &_from->_light);
    _this->_projectedcenter._refCount = 1;
    sjf_vec3_copy(&_this->_projectedcenter, &_from->_projectedcenter);
}

void sjf_model_destroy(sjs_model* _this) {
    if (_this->vertexbuffer._refCount == 1) { sjf_vertexbuffer_vertex_location_texture_normal_destroy(&_this->vertexbuffer); }
;
    if (_this->shader._refCount == 1) { sjf_shader_destroy(&_this->shader); }
;
    if (_this->texture._refCount == 1) { sjf_texture_destroy(&_this->texture); }
;
    if (_this->model._refCount == 1) { sjf_mat4_destroy(&_this->model); }
;
    if (_this->center._refCount == 1) { sjf_vec3_destroy(&_this->center); }
;
    if (_this->id._refCount == 1) { sjf_string_destroy(&_this->id); }
;
    if (_this->_projection._refCount == 1) { sjf_mat4_destroy(&_this->_projection); }
;
    if (_this->_view._refCount == 1) { sjf_mat4_destroy(&_this->_view); }
;
    if (_this->_world._refCount == 1) { sjf_mat4_destroy(&_this->_world); }
;
    if (_this->_light._refCount == 1) { sjf_light_destroy(&_this->_light); }
;
    if (_this->_projectedcenter._refCount == 1) { sjf_vec3_destroy(&_this->_projectedcenter); }
;
}

void sjf_model_firemouseevent(sjs_model* _parent, sjs_mouseevent* mouseevent) {
}

void sjf_model_getcenter(sjs_model* _parent, sjs_vec3* _return) {
    sjs_vec3* sjt_copy26 = 0;
    sjs_model* sjt_dot685 = 0;

    sjt_dot685 = _parent;
    sjt_copy26 = &sjt_dot685->center;
    _return->_refCount = 1;
    sjf_vec3_copy(_return, sjt_copy26);
}

void sjf_model_getcenter_heap(sjs_model* _parent, sjs_vec3** _return) {
    sjs_vec3* sjt_copy27 = 0;
    sjs_model* sjt_dot686 = 0;

    sjt_dot686 = _parent;
    sjt_copy27 = &sjt_dot686->center;
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjf_vec3_copy((*_return), sjt_copy27);
}

void sjf_model_getworld(sjs_model* _parent, sjs_mat4* _return) {
    sjs_model* sjt_dot687 = 0;
    sjs_model* sjt_dot688 = 0;
    sjs_mat4* sjt_functionParam151 = 0;
    sjs_mat4* sjt_parent102 = 0;

    sjt_dot687 = _parent;
    sjt_parent102 = &sjt_dot687->_world;
    sjt_dot688 = _parent;
    sjt_functionParam151 = &sjt_dot688->model;
    sjf_mat4_multiply(sjt_parent102, sjt_functionParam151, _return);
}

void sjf_model_getworld_heap(sjs_model* _parent, sjs_mat4** _return) {
    sjs_model* sjt_dot689 = 0;
    sjs_model* sjt_dot690 = 0;
    sjs_mat4* sjt_functionParam152 = 0;
    sjs_mat4* sjt_parent103 = 0;

    sjt_dot689 = _parent;
    sjt_parent103 = &sjt_dot689->_world;
    sjt_dot690 = _parent;
    sjt_functionParam152 = &sjt_dot690->model;
    sjf_mat4_multiply_heap(sjt_parent103, sjt_functionParam152, _return);
}

void sjf_model_getz(sjs_model* _parent, float* _return) {
    sjs_vec3* sjt_dot683 = 0;
    sjs_model* sjt_dot684 = 0;

    sjt_dot684 = _parent;
    sjt_dot683 = &sjt_dot684->_projectedcenter;
    (*_return) = sjt_dot683->z;
}

void sjf_model_heap(sjs_model* _this, sjs_model** _return) {
    sjs_string* sjt_isEmpty10 = 0;
    bool sjt_isEmpty9;

    sjt_isEmpty10 = (_this->id._refCount != -1 ? &_this->id : 0);
    sjt_isEmpty9 = (sjt_isEmpty10 != 0);
    if (sjt_isEmpty9) {
        sjs_string* ifValue8 = 0;
        sjs_model* sjt_cast10 = 0;
        sjs_string* sjt_functionParam140 = 0;
        sji_model sjt_functionParam141 = { 0 };
        sjs_hash_string_weak_iface_model* sjt_parent98 = 0;

        ifValue8 = (_this->id._refCount != -1 ? &_this->id : 0);
        sjt_parent98 = &sjv_modelsbyid;
        sjt_functionParam140 = ifValue8;
        sjt_cast10 = _this;
        sjf_model_as_sji_model(sjt_cast10, &sjt_functionParam141);
        delete_cb weakptrcb18 = { &sjt_functionParam141._parent, weakptr_clear };
        if (sjt_functionParam141._parent != 0) { weakptr_cb_add(sjt_functionParam141._parent, weakptrcb18); }
        sjf_hash_string_weak_iface_model_setat(sjt_parent98, sjt_functionParam140, sjt_functionParam141);

        delete_cb weakptrcb29 = { &sjt_functionParam141._parent, weakptr_clear };
        if (sjt_functionParam141._parent != 0) { weakptr_cb_remove(sjt_functionParam141._parent, weakptrcb29); }
    }

    (*_return) = _this;
    (*_return)->_refCount++;
}

void sjf_model_render(sjs_model* _parent) {
    sjs_mat4 sjt_call27 = { -1 };
    sjs_string sjt_call28 = { -1 };
    sjs_string sjt_call29 = { -1 };
    sjs_string sjt_call30 = { -1 };
    sjs_string sjt_call31 = { -1 };
    sjs_string sjt_call32 = { -1 };
    sjs_vec3 sjt_call33 = { -1 };
    sjs_string sjt_call34 = { -1 };
    sjs_vec3 sjt_call35 = { -1 };
    sjs_model* sjt_dot1444 = 0;
    sjs_model* sjt_dot1445 = 0;
    sjs_model* sjt_dot1446 = 0;
    sjs_model* sjt_dot1447 = 0;
    sjs_model* sjt_dot1448 = 0;
    sjs_model* sjt_dot1449 = 0;
    sjs_model* sjt_dot1450 = 0;
    sjs_light* sjt_dot1451 = 0;
    sjs_model* sjt_dot1452 = 0;
    sjs_model* sjt_dot1453 = 0;
    sjs_light* sjt_dot1460 = 0;
    sjs_model* sjt_dot1461 = 0;
    sjs_model* sjt_dot1462 = 0;
    sjs_light* sjt_dot1463 = 0;
    sjs_model* sjt_dot1464 = 0;
    sjs_model* sjt_dot1465 = 0;
    sjs_model* sjt_dot705 = 0;
    sjs_model* sjt_dot706 = 0;
    sjs_model* sjt_dot707 = 0;
    sjs_mat4* sjt_functionParam159 = 0;
    sjs_mat4* sjt_functionParam160 = 0;
    sjs_shader* sjt_functionParam163 = 0;
    int32_t sjt_functionParam164;
    int32_t sjt_functionParam165;
    int32_t sjt_functionParam166;
    sjs_texture* sjt_functionParam167 = 0;
    int32_t sjt_functionParam168;
    sjs_shader* sjt_functionParam169 = 0;
    sjs_string* sjt_functionParam170 = 0;
    sjs_mat4* sjt_functionParam171 = 0;
    int32_t sjt_functionParam172;
    sjs_shader* sjt_functionParam173 = 0;
    sjs_string* sjt_functionParam174 = 0;
    sjs_mat4* sjt_functionParam175 = 0;
    int32_t sjt_functionParam176;
    sjs_shader* sjt_functionParam177 = 0;
    sjs_string* sjt_functionParam178 = 0;
    sjs_mat4* sjt_functionParam179 = 0;
    int32_t sjt_functionParam180;
    sjs_shader* sjt_functionParam181 = 0;
    sjs_string* sjt_functionParam182 = 0;
    sjs_vec3* sjt_functionParam183 = 0;
    int32_t sjt_functionParam184;
    sjs_shader* sjt_functionParam185 = 0;
    sjs_string* sjt_functionParam186 = 0;
    sjs_vec3* sjt_functionParam187 = 0;
    int32_t sjt_functionParam188;
    sjs_shader* sjt_functionParam189 = 0;
    sjs_string* sjt_functionParam190 = 0;
    sjs_vec3* sjt_functionParam191 = 0;
    sjs_mat4* sjt_parent107 = 0;
    sjs_mat4* sjt_parent108 = 0;
    sjs_mat4* sjt_parent109 = 0;
    sjs_mat4* sjt_parent112 = 0;
    sjs_color* sjt_parent113 = 0;
    sjs_color* sjt_parent114 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent115 = 0;
    sjs_mat4 sjv_normalmat = { -1 };
    sjs_mat4 sjv_viewworld = { -1 };
    sjs_mat4 sjv_world = { -1 };

    sjt_dot705 = _parent;
    sjt_parent107 = &sjt_dot705->_world;
    sjt_dot706 = _parent;
    sjt_functionParam159 = &sjt_dot706->model;
    sjf_mat4_multiply(sjt_parent107, sjt_functionParam159, &sjv_world);
    sjt_dot707 = _parent;
    sjt_parent108 = &sjt_dot707->_view;
    sjt_functionParam160 = &sjv_world;
    sjf_mat4_multiply(sjt_parent108, sjt_functionParam160, &sjv_viewworld);
    sjt_parent112 = &sjv_viewworld;
    sjf_mat4_invert(sjt_parent112, &sjt_call27);
    sjt_parent109 = &sjt_call27;
    sjf_mat4_transpose(sjt_parent109, &sjv_normalmat);
    sjt_dot1444 = _parent;
    sjt_functionParam163 = &sjt_dot1444->shader;
    sjf_gluseprogram(sjt_functionParam163);
    sjt_functionParam164 = sjv_glblendfunctype_gl_src_alpha;
    sjt_functionParam165 = sjv_glblendfunctype_gl_one_minus_src_alpha;
    sjf_glblendfunc(sjt_functionParam164, sjt_functionParam165);
    sjt_functionParam166 = sjv_gltexture_gl_texture_2d;
    sjt_dot1445 = _parent;
    sjt_functionParam167 = &sjt_dot1445->texture;
    sjf_glbindtexture(sjt_functionParam166, sjt_functionParam167);
    sjt_dot1446 = _parent;
    sjt_functionParam169 = &sjt_dot1446->shader;
    sjt_call28._refCount = 1;
    sjt_call28.count = 9;
    sjt_call28.data._refCount = 1;
    sjt_call28.data.datasize = 10;
    sjt_call28.data.data = (void*)sjg_string17;
    sjt_call28.data._isglobal = true;
    sjt_call28.data.count = 10;
    sjf_array_char(&sjt_call28.data);
    sjf_string(&sjt_call28);
    sjt_functionParam170 = &sjt_call28;
    sjf_glgetuniformlocation(sjt_functionParam169, sjt_functionParam170, &sjt_functionParam168);
    sjt_functionParam171 = &sjv_viewworld;
    sjf_gluniformmat4(sjt_functionParam168, sjt_functionParam171);
    sjt_dot1447 = _parent;
    sjt_functionParam173 = &sjt_dot1447->shader;
    sjt_call29._refCount = 1;
    sjt_call29.count = 9;
    sjt_call29.data._refCount = 1;
    sjt_call29.data.datasize = 10;
    sjt_call29.data.data = (void*)sjg_string18;
    sjt_call29.data._isglobal = true;
    sjt_call29.data.count = 10;
    sjf_array_char(&sjt_call29.data);
    sjf_string(&sjt_call29);
    sjt_functionParam174 = &sjt_call29;
    sjf_glgetuniformlocation(sjt_functionParam173, sjt_functionParam174, &sjt_functionParam172);
    sjt_functionParam175 = &sjv_normalmat;
    sjf_gluniformmat4(sjt_functionParam172, sjt_functionParam175);
    sjt_dot1448 = _parent;
    sjt_functionParam177 = &sjt_dot1448->shader;
    sjt_call30._refCount = 1;
    sjt_call30.count = 10;
    sjt_call30.data._refCount = 1;
    sjt_call30.data.datasize = 11;
    sjt_call30.data.data = (void*)sjg_string19;
    sjt_call30.data._isglobal = true;
    sjt_call30.data.count = 11;
    sjf_array_char(&sjt_call30.data);
    sjf_string(&sjt_call30);
    sjt_functionParam178 = &sjt_call30;
    sjf_glgetuniformlocation(sjt_functionParam177, sjt_functionParam178, &sjt_functionParam176);
    sjt_dot1449 = _parent;
    sjt_functionParam179 = &sjt_dot1449->_projection;
    sjf_gluniformmat4(sjt_functionParam176, sjt_functionParam179);
    sjt_dot1450 = _parent;
    sjt_functionParam181 = &sjt_dot1450->shader;
    sjt_call31._refCount = 1;
    sjt_call31.count = 8;
    sjt_call31.data._refCount = 1;
    sjt_call31.data.datasize = 9;
    sjt_call31.data.data = (void*)sjg_string20;
    sjt_call31.data._isglobal = true;
    sjt_call31.data.count = 9;
    sjf_array_char(&sjt_call31.data);
    sjf_string(&sjt_call31);
    sjt_functionParam182 = &sjt_call31;
    sjf_glgetuniformlocation(sjt_functionParam181, sjt_functionParam182, &sjt_functionParam180);
    sjt_dot1452 = _parent;
    sjt_dot1451 = &sjt_dot1452->_light;
    sjt_functionParam183 = &sjt_dot1451->pos;
    sjf_gluniformvec3(sjt_functionParam180, sjt_functionParam183);
    sjt_dot1453 = _parent;
    sjt_functionParam185 = &sjt_dot1453->shader;
    sjt_call32._refCount = 1;
    sjt_call32.count = 12;
    sjt_call32.data._refCount = 1;
    sjt_call32.data.datasize = 13;
    sjt_call32.data.data = (void*)sjg_string21;
    sjt_call32.data._isglobal = true;
    sjt_call32.data.count = 13;
    sjf_array_char(&sjt_call32.data);
    sjf_string(&sjt_call32);
    sjt_functionParam186 = &sjt_call32;
    sjf_glgetuniformlocation(sjt_functionParam185, sjt_functionParam186, &sjt_functionParam184);
    sjt_dot1461 = _parent;
    sjt_dot1460 = &sjt_dot1461->_light;
    sjt_parent113 = &sjt_dot1460->diffusecolor;
    sjf_color_asvec3(sjt_parent113, &sjt_call33);
    sjt_functionParam187 = &sjt_call33;
    sjf_gluniformvec3(sjt_functionParam184, sjt_functionParam187);
    sjt_dot1462 = _parent;
    sjt_functionParam189 = &sjt_dot1462->shader;
    sjt_call34._refCount = 1;
    sjt_call34.count = 9;
    sjt_call34.data._refCount = 1;
    sjt_call34.data.datasize = 10;
    sjt_call34.data.data = (void*)sjg_string22;
    sjt_call34.data._isglobal = true;
    sjt_call34.data.count = 10;
    sjf_array_char(&sjt_call34.data);
    sjf_string(&sjt_call34);
    sjt_functionParam190 = &sjt_call34;
    sjf_glgetuniformlocation(sjt_functionParam189, sjt_functionParam190, &sjt_functionParam188);
    sjt_dot1464 = _parent;
    sjt_dot1463 = &sjt_dot1464->_light;
    sjt_parent114 = &sjt_dot1463->speccolor;
    sjf_color_asvec3(sjt_parent114, &sjt_call35);
    sjt_functionParam191 = &sjt_call35;
    sjf_gluniformvec3(sjt_functionParam188, sjt_functionParam191);
    sjt_dot1465 = _parent;
    sjt_parent115 = &sjt_dot1465->vertexbuffer;
    sjf_vertexbuffer_vertex_location_texture_normal_render(sjt_parent115);

    if (sjt_call27._refCount == 1) { sjf_mat4_destroy(&sjt_call27); }
;
    if (sjt_call28._refCount == 1) { sjf_string_destroy(&sjt_call28); }
;
    if (sjt_call29._refCount == 1) { sjf_string_destroy(&sjt_call29); }
;
    if (sjt_call30._refCount == 1) { sjf_string_destroy(&sjt_call30); }
;
    if (sjt_call31._refCount == 1) { sjf_string_destroy(&sjt_call31); }
;
    if (sjt_call32._refCount == 1) { sjf_string_destroy(&sjt_call32); }
;
    if (sjt_call33._refCount == 1) { sjf_vec3_destroy(&sjt_call33); }
;
    if (sjt_call34._refCount == 1) { sjf_string_destroy(&sjt_call34); }
;
    if (sjt_call35._refCount == 1) { sjf_vec3_destroy(&sjt_call35); }
;
    if (sjv_normalmat._refCount == 1) { sjf_mat4_destroy(&sjv_normalmat); }
;
    if (sjv_viewworld._refCount == 1) { sjf_mat4_destroy(&sjv_viewworld); }
;
    if (sjv_world._refCount == 1) { sjf_mat4_destroy(&sjv_world); }
;
}

void sjf_model_renderorqueue(sjs_model* _parent, sjs_list_heap_iface_model* zqueue) {
    sjs_model* sjt_dot691 = 0;
    bool sjt_ifElse36;

    sjt_dot691 = _parent;
    sjt_ifElse36 = sjt_dot691->hasalpha;
    if (sjt_ifElse36) {
        sjs_model* sjt_cast11 = 0;
        sji_model sjt_functionParam158 = { 0 };
        sjs_list_heap_iface_model* sjt_parent106 = 0;

        sjt_parent106 = zqueue;
        sjt_cast11 = _parent;
        sjf_model_as_sji_model(sjt_cast11, &sjt_functionParam158);
        if (sjt_functionParam158._parent != 0) {
            sjt_functionParam158._parent->_refCount++;
        }

        sjf_list_heap_iface_model_add(sjt_parent106, sjt_functionParam158);

        if (sjt_functionParam158._parent != 0) {
            sjt_functionParam158._parent->_refCount--;
            if (sjt_functionParam158._parent->_refCount <= 0) {
                sjt_functionParam158._vtbl->destroy(sjt_functionParam158._parent);
                free(sjt_functionParam158._parent);
            }
        }
    } else {
        sjf_model_render(_parent);
    }
}

void sjf_model_update(sjs_model* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    sjs_mat4 sjt_call22 = { -1 };
    sjs_mat4 sjt_call23 = { -1 };
    sjs_vec4 sjt_call24 = { -1 };
    sjs_vec3 sjt_call25 = { -1 };
    sjs_mat4* sjt_copy21 = 0;
    sjs_mat4* sjt_copy22 = 0;
    sjs_mat4* sjt_copy23 = 0;
    sjs_vec3* sjt_copy24 = 0;
    sjs_light* sjt_copy25 = 0;
    sjs_model* sjt_dot343 = 0;
    sjs_model* sjt_dot344 = 0;
    sjs_model* sjt_dot345 = 0;
    sjs_model* sjt_dot666 = 0;
    sjs_model* sjt_dot667 = 0;
    sjs_model* sjt_dot668 = 0;
    sjs_vec3* sjt_dot669 = 0;
    sjs_model* sjt_dot670 = 0;
    sjs_vec3* sjt_dot671 = 0;
    sjs_model* sjt_dot672 = 0;
    sjs_vec3* sjt_dot673 = 0;
    sjs_model* sjt_dot674 = 0;
    sjs_model* sjt_dot675 = 0;
    sjs_vec4* sjt_dot676 = 0;
    sjs_vec4* sjt_dot677 = 0;
    sjs_vec4* sjt_dot678 = 0;
    sjs_vec4* sjt_dot679 = 0;
    sjs_vec4* sjt_dot680 = 0;
    sjs_vec4* sjt_dot681 = 0;
    sjs_model* sjt_dot682 = 0;
    sjs_mat4* sjt_functionParam148 = 0;
    sjs_mat4* sjt_functionParam149 = 0;
    sjs_vec4* sjt_functionParam150 = 0;
    float sjt_math863;
    float sjt_math864;
    float sjt_math865;
    float sjt_math866;
    float sjt_math867;
    float sjt_math868;
    sjs_mat4* sjt_parent100 = 0;
    sjs_mat4* sjt_parent101 = 0;
    sjs_mat4* sjt_parent99 = 0;
    sjs_vec4 sjv_t2 = { -1 };

    sjt_dot343 = _parent;
    sjt_copy21 = projection;
    if (sjt_dot343->_projection._refCount == 1) { sjf_mat4_destroy(&sjt_dot343->_projection); }
;
    sjt_dot343->_projection._refCount = 1;
    sjf_mat4_copy(&sjt_dot343->_projection, sjt_copy21);
    sjt_dot344 = _parent;
    sjt_copy22 = view;
    if (sjt_dot344->_view._refCount == 1) { sjf_mat4_destroy(&sjt_dot344->_view); }
;
    sjt_dot344->_view._refCount = 1;
    sjf_mat4_copy(&sjt_dot344->_view, sjt_copy22);
    sjt_dot345 = _parent;
    sjt_copy23 = world;
    if (sjt_dot345->_world._refCount == 1) { sjf_mat4_destroy(&sjt_dot345->_world); }
;
    sjt_dot345->_world._refCount = 1;
    sjf_mat4_copy(&sjt_dot345->_world, sjt_copy23);
    sjt_dot666 = _parent;
    sjt_parent101 = &sjt_dot666->_view;
    sjt_dot667 = _parent;
    sjt_functionParam148 = &sjt_dot667->_world;
    sjf_mat4_multiply(sjt_parent101, sjt_functionParam148, &sjt_call23);
    sjt_parent100 = &sjt_call23;
    sjt_dot668 = _parent;
    sjt_functionParam149 = &sjt_dot668->model;
    sjf_mat4_multiply(sjt_parent100, sjt_functionParam149, &sjt_call22);
    sjt_parent99 = &sjt_call22;
    sjt_call24._refCount = 1;
    sjt_dot670 = _parent;
    sjt_dot669 = &sjt_dot670->center;
    sjt_call24.x = sjt_dot669->x;
    sjt_dot672 = _parent;
    sjt_dot671 = &sjt_dot672->center;
    sjt_call24.y = sjt_dot671->y;
    sjt_dot674 = _parent;
    sjt_dot673 = &sjt_dot674->center;
    sjt_call24.z = sjt_dot673->z;
    sjt_call24.w = 1.0f;
    sjf_vec4(&sjt_call24);
    sjt_functionParam150 = &sjt_call24;
    sjf_mat4_multiplyvec4(sjt_parent99, sjt_functionParam150, &sjv_t2);
    sjt_dot675 = _parent;
    sjt_call25._refCount = 1;
    sjt_dot676 = &sjv_t2;
    sjt_math863 = sjt_dot676->x;
    sjt_dot677 = &sjv_t2;
    sjt_math864 = sjt_dot677->w;
    sjt_call25.x = sjt_math863 / sjt_math864;
    sjt_dot678 = &sjv_t2;
    sjt_math865 = sjt_dot678->y;
    sjt_dot679 = &sjv_t2;
    sjt_math866 = sjt_dot679->w;
    sjt_call25.y = sjt_math865 / sjt_math866;
    sjt_dot680 = &sjv_t2;
    sjt_math867 = sjt_dot680->z;
    sjt_dot681 = &sjv_t2;
    sjt_math868 = sjt_dot681->w;
    sjt_call25.z = sjt_math867 / sjt_math868;
    sjf_vec3(&sjt_call25);
    sjt_copy24 = &sjt_call25;
    if (sjt_dot675->_projectedcenter._refCount == 1) { sjf_vec3_destroy(&sjt_dot675->_projectedcenter); }
;
    sjt_dot675->_projectedcenter._refCount = 1;
    sjf_vec3_copy(&sjt_dot675->_projectedcenter, sjt_copy24);
    sjt_dot682 = _parent;
    sjt_copy25 = light;
    if (sjt_dot682->_light._refCount == 1) { sjf_light_destroy(&sjt_dot682->_light); }
;
    sjt_dot682->_light._refCount = 1;
    sjf_light_copy(&sjt_dot682->_light, sjt_copy25);

    if (sjt_call22._refCount == 1) { sjf_mat4_destroy(&sjt_call22); }
;
    if (sjt_call23._refCount == 1) { sjf_mat4_destroy(&sjt_call23); }
;
    if (sjt_call24._refCount == 1) { sjf_vec4_destroy(&sjt_call24); }
;
    if (sjt_call25._refCount == 1) { sjf_vec3_destroy(&sjt_call25); }
;
    if (sjv_t2._refCount == 1) { sjf_vec4_destroy(&sjv_t2); }
;
}

void sjf_model_zsort(sji_model l, sji_model r, int32_t* _return) {
    float sjt_functionParam124;
    float sjt_functionParam125;
    sji_model sjt_parent80 = { 0 };
    sji_model sjt_parent81 = { 0 };

    sjt_parent80 = l;
    sjt_parent80._vtbl->getz(sjt_parent80._parent, &sjt_functionParam124);
    sjt_parent81 = r;
    sjt_parent81._vtbl->getz(sjt_parent81._parent, &sjt_functionParam125);
    sjf_f32_compare(sjt_functionParam124, sjt_functionParam125, _return);
}

void sjf_model_zsort_callback(void * _parent, sji_model l, sji_model r, int32_t* _return) {
    sjf_model_zsort(l, r, _return);
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
    if (_this->point._refCount == 1) { sjf_point_destroy(&_this->point); }
;
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
    sjt_forEnd7 = sjt_dot83->count;
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
    sjt_compare41 = sjt_dot171->x;
    sjt_dot172 = rect;
    sjt_compare42 = sjt_dot172->x;
    sjt_and3 = sjt_compare41 == sjt_compare42;
    sjt_dot173 = _parent;
    sjt_compare43 = sjt_dot173->y;
    sjt_dot174 = rect;
    sjt_compare44 = sjt_dot174->y;
    sjt_and5 = sjt_compare43 == sjt_compare44;
    sjt_dot175 = _parent;
    sjt_compare45 = sjt_dot175->w;
    sjt_dot176 = rect;
    sjt_compare46 = sjt_dot176->w;
    sjt_and7 = sjt_compare45 == sjt_compare46;
    sjt_dot177 = _parent;
    sjt_compare47 = sjt_dot177->h;
    sjt_dot178 = rect;
    sjt_compare48 = sjt_dot178->h;
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
    sjt_math5 = sjt_dot16->x;
    sjt_dot17 = margin;
    sjt_math6 = sjt_dot17->l;
    _return->x = sjt_math5 + sjt_math6;
    sjt_dot18 = _parent;
    sjt_math7 = sjt_dot18->y;
    sjt_dot19 = margin;
    sjt_math8 = sjt_dot19->t;
    _return->y = sjt_math7 + sjt_math8;
    sjt_dot20 = _parent;
    sjt_math11 = sjt_dot20->w;
    sjt_dot21 = margin;
    sjt_math12 = sjt_dot21->l;
    sjt_math9 = sjt_math11 - sjt_math12;
    sjt_dot22 = margin;
    sjt_math10 = sjt_dot22->r;
    _return->w = sjt_math9 - sjt_math10;
    sjt_dot23 = _parent;
    sjt_math15 = sjt_dot23->h;
    sjt_dot24 = margin;
    sjt_math16 = sjt_dot24->t;
    sjt_math13 = sjt_math15 - sjt_math16;
    sjt_dot25 = margin;
    sjt_math14 = sjt_dot25->b;
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
    sjt_math17 = sjt_dot26->x;
    sjt_dot27 = margin;
    sjt_math18 = sjt_dot27->l;
    (*_return)->x = sjt_math17 + sjt_math18;
    sjt_dot28 = _parent;
    sjt_math19 = sjt_dot28->y;
    sjt_dot29 = margin;
    sjt_math20 = sjt_dot29->t;
    (*_return)->y = sjt_math19 + sjt_math20;
    sjt_dot30 = _parent;
    sjt_math23 = sjt_dot30->w;
    sjt_dot31 = margin;
    sjt_math24 = sjt_dot31->l;
    sjt_math21 = sjt_math23 - sjt_math24;
    sjt_dot32 = margin;
    sjt_math22 = sjt_dot32->r;
    (*_return)->w = sjt_math21 - sjt_math22;
    sjt_dot33 = _parent;
    sjt_math27 = sjt_dot33->h;
    sjt_dot34 = margin;
    sjt_math28 = sjt_dot34->t;
    sjt_math25 = sjt_math27 - sjt_math28;
    sjt_dot35 = margin;
    sjt_math26 = sjt_dot35->b;
    (*_return)->h = sjt_math25 - sjt_math26;
    sjf_rect_heap((*_return));
}

void sjf_renderbuffer(sjs_renderbuffer* _this) {
}

void sjf_renderbuffer_copy(sjs_renderbuffer* _this, sjs_renderbuffer* _from) {
    _this->size._refCount = 1;
    sjf_size_copy(&_this->size, &_from->size);
    _this->id = _from->id;
    _this->id = _from->id;
    glid_retain(_this->id);
}

void sjf_renderbuffer_destroy(sjs_renderbuffer* _this) {
    if (glid_release(_this->id)) {
        glDeleteRenderbuffers(1, &_this->id);
    }
    if (_this->size._refCount == 1) { sjf_size_destroy(&_this->size); }
;
}

void sjf_renderbuffer_heap(sjs_renderbuffer* _this) {
}

void sjf_runloop(void) {
    #ifdef EMSCRIPTEN
    emscripten_set_main_loop((em_callback_func)sjf_mainloop, 0, 0);
    exit(0);
    #else
    bool shouldappcontinue = true;
    while (shouldappcontinue) {
        sjf_mainloop(&shouldappcontinue);
    }
    #endif 
}

void sjf_saturateeffect(sjs_saturateeffect* _this) {
}

void sjf_saturateeffect_as_sji_effect(sjs_saturateeffect* _this, sji_effect* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_saturateeffect_effect_vtbl;
}

void sjf_saturateeffect_asinterface(sjs_saturateeffect* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_effect_typeId:  {
            sjf_saturateeffect_as_sji_effect(_this, (sji_effect*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_saturateeffect_copy(sjs_saturateeffect* _this, sjs_saturateeffect* _from) {
    _this->amount = _from->amount;
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    _this->_vertexbuffer._refCount = 1;
    sjf_boxvertexbuffer_copy((_this->_vertexbuffer._refCount != -1 ? &_this->_vertexbuffer : 0), (_from->_vertexbuffer._refCount != -1 ? &_from->_vertexbuffer : 0));
    _this->_scenebuffer._refCount = 1;
    sjf_scenebuffer_copy((_this->_scenebuffer._refCount != -1 ? &_this->_scenebuffer : 0), (_from->_scenebuffer._refCount != -1 ? &_from->_scenebuffer : 0));
    _this->_innerscene._refCount = 1;
    sjf_scene2d_copy(&_this->_innerscene, &_from->_innerscene);
}

void sjf_saturateeffect_destroy(sjs_saturateeffect* _this) {
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
    if (_this->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_this->_vertexbuffer); }
;
    if (_this->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_this->_scenebuffer); }
;
    if (_this->_innerscene._refCount == 1) { sjf_scene2d_destroy(&_this->_innerscene); }
;
}

void sjf_saturateeffect_getrect(sjs_saturateeffect* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy109 = 0;
    sjs_saturateeffect* sjt_dot1798 = 0;

    sjt_dot1798 = _parent;
    sjt_copy109 = &sjt_dot1798->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy109);
}

void sjf_saturateeffect_getrect_heap(sjs_saturateeffect* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy110 = 0;
    sjs_saturateeffect* sjt_dot1799 = 0;

    sjt_dot1799 = _parent;
    sjt_copy110 = &sjt_dot1799->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy110);
}

void sjf_saturateeffect_heap(sjs_saturateeffect* _this) {
}

void sjf_saturateeffect_render(sjs_saturateeffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb) {
    sjs_boxvertexbuffer sjt_call189 = { -1 };
    sjs_scenebuffer sjt_call190 = { -1 };
    sjs_saturateeffect* sjt_dot1815 = 0;
    sjs_saturateeffect* sjt_dot1818 = 0;
    sjs_saturateeffect* sjt_dot1824 = 0;
    sjs_saturateeffect* sjt_dot1825 = 0;
    bool sjt_ifElse72;
    bool sjt_ifElse73;
    sjs_boxvertexbuffer* sjt_isEmpty47 = 0;
    sjs_scenebuffer* sjt_isEmpty48 = 0;
    bool sjt_isEmpty49;
    sjs_scenebuffer* sjt_isEmpty50 = 0;
    bool sjt_isEmpty51;
    sjs_boxvertexbuffer* sjt_isEmpty52 = 0;

    sjt_dot1815 = _parent;
    sjt_isEmpty47 = (sjt_dot1815->_vertexbuffer._refCount != -1 ? &sjt_dot1815->_vertexbuffer : 0);
    sjt_ifElse72 = (sjt_isEmpty47 == 0);
    if (sjt_ifElse72) {
        sjs_boxvertexbuffer* sjt_copy112 = 0;
        sjs_rect* sjt_copy113 = 0;
        sjs_saturateeffect* sjt_dot1816 = 0;
        sjs_saturateeffect* sjt_dot1817 = 0;

        sjt_dot1816 = _parent;
        sjt_call189._refCount = 1;
        sjt_dot1817 = _parent;
        sjt_copy113 = &sjt_dot1817->_rect;
        sjt_call189.rect._refCount = 1;
        sjf_rect_copy(&sjt_call189.rect, sjt_copy113);
        sjf_boxvertexbuffer(&sjt_call189);
        sjt_copy112 = &sjt_call189;
        if (sjt_dot1816->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_dot1816->_vertexbuffer); }
;
        sjt_dot1816->_vertexbuffer._refCount = 1;
        sjf_boxvertexbuffer_copy(&sjt_dot1816->_vertexbuffer, sjt_copy112);
    }

    sjt_dot1818 = _parent;
    sjt_isEmpty48 = (sjt_dot1818->_scenebuffer._refCount != -1 ? &sjt_dot1818->_scenebuffer : 0);
    sjt_ifElse73 = (sjt_isEmpty48 == 0);
    if (sjt_ifElse73) {
        sjs_scenebuffer* sjt_copy114 = 0;
        sjs_saturateeffect* sjt_dot1819 = 0;
        sjs_rect* sjt_dot1820 = 0;
        sjs_saturateeffect* sjt_dot1821 = 0;
        sjs_rect* sjt_dot1822 = 0;
        sjs_saturateeffect* sjt_dot1823 = 0;

        sjt_dot1819 = _parent;
        sjt_call190._refCount = 1;
        sjt_call190.size._refCount = 1;
        sjt_dot1821 = _parent;
        sjt_dot1820 = &sjt_dot1821->_rect;
        sjt_call190.size.w = sjt_dot1820->w;
        sjt_dot1823 = _parent;
        sjt_dot1822 = &sjt_dot1823->_rect;
        sjt_call190.size.h = sjt_dot1822->h;
        sjf_size(&sjt_call190.size);
        sjt_call190.framebuffer._refCount = 1;
        sjt_call190.framebuffer.size._refCount = 1;
        sjt_call190.framebuffer.size.w = 0;
        sjt_call190.framebuffer.size.h = 0;
        sjf_size(&sjt_call190.framebuffer.size);
        sjt_call190.framebuffer.id = (uint32_t)0u;
        sjf_framebuffer(&sjt_call190.framebuffer);
        sjt_call190.texture._refCount = 1;
        sjt_call190.texture.size._refCount = 1;
        sjt_call190.texture.size.w = 0;
        sjt_call190.texture.size.h = 0;
        sjf_size(&sjt_call190.texture.size);
        sjt_call190.texture.id = (uint32_t)0u;
        sjf_texture(&sjt_call190.texture);
        sjt_call190.renderbuffer._refCount = 1;
        sjt_call190.renderbuffer.size._refCount = 1;
        sjt_call190.renderbuffer.size.w = 0;
        sjt_call190.renderbuffer.size.h = 0;
        sjf_size(&sjt_call190.renderbuffer.size);
        sjt_call190.renderbuffer.id = (uint32_t)0u;
        sjf_renderbuffer(&sjt_call190.renderbuffer);
        sjf_scenebuffer(&sjt_call190);
        sjt_copy114 = &sjt_call190;
        if (sjt_dot1819->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&sjt_dot1819->_scenebuffer); }
;
        sjt_dot1819->_scenebuffer._refCount = 1;
        sjf_scenebuffer_copy(&sjt_dot1819->_scenebuffer, sjt_copy114);
    }

    sjt_dot1824 = _parent;
    sjt_isEmpty50 = (sjt_dot1824->_scenebuffer._refCount != -1 ? &sjt_dot1824->_scenebuffer : 0);
    sjt_isEmpty49 = (sjt_isEmpty50 != 0);
    sjt_dot1825 = _parent;
    sjt_isEmpty52 = (sjt_dot1825->_vertexbuffer._refCount != -1 ? &sjt_dot1825->_vertexbuffer : 0);
    sjt_isEmpty51 = (sjt_isEmpty52 != 0);
    if (sjt_isEmpty49 && sjt_isEmpty51) {
        sjs_scenebuffer* ifValue35 = 0;
        sjs_boxvertexbuffer* ifValue36 = 0;
        sjs_string sjt_call191 = { -1 };
        sjs_string sjt_call192 = { -1 };
        sjs_string sjt_call193 = { -1 };
        sjs_string sjt_call194 = { -1 };
        sjs_string sjt_call195 = { -1 };
        cb_scene2d_void sjt_callback10;
        sjs_saturateeffect* sjt_dot1826 = 0;
        sjs_saturateeffect* sjt_dot1827 = 0;
        sjs_scenebuffer* sjt_dot1828 = 0;
        sjs_saturateeffect* sjt_dot1829 = 0;
        sjs_scenebuffer* sjt_dot1830 = 0;
        sjs_saturateeffect* sjt_dot1831 = 0;
        sjs_saturateeffect* sjt_dot1832 = 0;
        sjs_saturateeffect* sjt_dot1833 = 0;
        sjs_scenebuffer* sjt_dot1834 = 0;
        sjs_scenebuffer* sjt_dot1835 = 0;
        sjs_saturateeffect* sjt_dot1836 = 0;
        sjs_scene2d* sjt_dot1837 = 0;
        sjs_scene2d* sjt_dot1838 = 0;
        sjs_scene2d* sjt_dot1839 = 0;
        sjs_framebuffer* sjt_functionParam608 = 0;
        sjs_size* sjt_functionParam609 = 0;
        sjs_scene2d* sjt_functionParam610 = 0;
        sjs_framebuffer* sjt_functionParam611 = 0;
        int32_t sjt_functionParam612;
        sjs_texture* sjt_functionParam613 = 0;
        sjs_shader* sjt_functionParam614 = 0;
        int32_t sjt_functionParam615;
        int32_t sjt_functionParam616;
        int32_t sjt_functionParam617;
        sjs_shader* sjt_functionParam618 = 0;
        sjs_string* sjt_functionParam619 = 0;
        int32_t sjt_functionParam620;
        int32_t sjt_functionParam621;
        sjs_shader* sjt_functionParam622 = 0;
        sjs_string* sjt_functionParam623 = 0;
        float sjt_functionParam624;
        int32_t sjt_functionParam625;
        sjs_shader* sjt_functionParam626 = 0;
        sjs_string* sjt_functionParam627 = 0;
        sjs_mat4* sjt_functionParam628 = 0;
        int32_t sjt_functionParam629;
        sjs_shader* sjt_functionParam630 = 0;
        sjs_string* sjt_functionParam631 = 0;
        sjs_mat4* sjt_functionParam632 = 0;
        int32_t sjt_functionParam633;
        sjs_shader* sjt_functionParam634 = 0;
        sjs_string* sjt_functionParam635 = 0;
        sjs_mat4* sjt_functionParam636 = 0;
        sjs_scene2d* sjt_functionParam637 = 0;
        sjs_scene2d* sjt_parent298 = 0;
        sjs_scene2d* sjt_parent299 = 0;
        sjs_scene2d* sjt_parent300 = 0;
        sjs_boxvertexbuffer* sjt_parent301 = 0;

        sjt_dot1826 = _parent;
        ifValue35 = (sjt_dot1826->_scenebuffer._refCount != -1 ? &sjt_dot1826->_scenebuffer : 0);
        sjt_dot1827 = _parent;
        ifValue36 = (sjt_dot1827->_vertexbuffer._refCount != -1 ? &sjt_dot1827->_vertexbuffer : 0);
        sjt_dot1828 = ifValue35;
        sjt_functionParam608 = &sjt_dot1828->framebuffer;
        sjf_glpushframebuffer(sjt_functionParam608);
        sjt_dot1829 = _parent;
        sjt_parent298 = &sjt_dot1829->_innerscene;
        sjt_dot1830 = ifValue35;
        sjt_functionParam609 = &sjt_dot1830->size;
        sjf_scene2d_setsize(sjt_parent298, sjt_functionParam609);
        sjt_dot1831 = _parent;
        sjt_parent299 = &sjt_dot1831->_innerscene;
        sjf_scene2d_start(sjt_parent299);
        sjt_callback10 = cb;
        sjt_dot1832 = _parent;
        sjt_functionParam610 = &sjt_dot1832->_innerscene;
        sjt_callback10._cb(sjt_callback10._parent, sjt_functionParam610);
        sjt_dot1833 = _parent;
        sjt_parent300 = &sjt_dot1833->_innerscene;
        sjf_scene2d_end(sjt_parent300);
        sjt_dot1834 = ifValue35;
        sjt_functionParam611 = &sjt_dot1834->framebuffer;
        sjf_glpopframebuffer(sjt_functionParam611);
        sjt_functionParam612 = sjv_gltexture_gl_texture_2d;
        sjt_dot1835 = ifValue35;
        sjt_functionParam613 = &sjt_dot1835->texture;
        sjf_glbindtexture(sjt_functionParam612, sjt_functionParam613);
        sjt_functionParam614 = &sjv_saturateshader;
        sjf_gluseprogram(sjt_functionParam614);
        sjt_functionParam615 = sjv_glblendfunctype_gl_src_alpha;
        sjt_functionParam616 = sjv_glblendfunctype_gl_one_minus_src_alpha;
        sjf_glblendfunc(sjt_functionParam615, sjt_functionParam616);
        sjt_functionParam618 = &sjv_saturateshader;
        sjt_call191._refCount = 1;
        sjt_call191.count = 7;
        sjt_call191.data._refCount = 1;
        sjt_call191.data.datasize = 8;
        sjt_call191.data.data = (void*)sjg_string28;
        sjt_call191.data._isglobal = true;
        sjt_call191.data.count = 8;
        sjf_array_char(&sjt_call191.data);
        sjf_string(&sjt_call191);
        sjt_functionParam619 = &sjt_call191;
        sjf_glgetuniformlocation(sjt_functionParam618, sjt_functionParam619, &sjt_functionParam617);
        sjt_functionParam620 = 0;
        sjf_gluniformi32(sjt_functionParam617, sjt_functionParam620);
        sjt_functionParam622 = &sjv_saturateshader;
        sjt_call192._refCount = 1;
        sjt_call192.count = 6;
        sjt_call192.data._refCount = 1;
        sjt_call192.data.datasize = 7;
        sjt_call192.data.data = (void*)sjg_string37;
        sjt_call192.data._isglobal = true;
        sjt_call192.data.count = 7;
        sjf_array_char(&sjt_call192.data);
        sjf_string(&sjt_call192);
        sjt_functionParam623 = &sjt_call192;
        sjf_glgetuniformlocation(sjt_functionParam622, sjt_functionParam623, &sjt_functionParam621);
        sjt_dot1836 = _parent;
        sjt_functionParam624 = sjt_dot1836->amount;
        sjf_gluniformf32(sjt_functionParam621, sjt_functionParam624);
        sjt_functionParam626 = &sjv_saturateshader;
        sjt_call193._refCount = 1;
        sjt_call193.count = 5;
        sjt_call193.data._refCount = 1;
        sjt_call193.data.datasize = 6;
        sjt_call193.data.data = (void*)sjg_string29;
        sjt_call193.data._isglobal = true;
        sjt_call193.data.count = 6;
        sjf_array_char(&sjt_call193.data);
        sjf_string(&sjt_call193);
        sjt_functionParam627 = &sjt_call193;
        sjf_glgetuniformlocation(sjt_functionParam626, sjt_functionParam627, &sjt_functionParam625);
        sjt_dot1837 = scene;
        sjt_functionParam628 = &sjt_dot1837->model;
        sjf_gluniformmat4(sjt_functionParam625, sjt_functionParam628);
        sjt_functionParam630 = &sjv_saturateshader;
        sjt_call194._refCount = 1;
        sjt_call194.count = 4;
        sjt_call194.data._refCount = 1;
        sjt_call194.data.datasize = 5;
        sjt_call194.data.data = (void*)sjg_string30;
        sjt_call194.data._isglobal = true;
        sjt_call194.data.count = 5;
        sjf_array_char(&sjt_call194.data);
        sjf_string(&sjt_call194);
        sjt_functionParam631 = &sjt_call194;
        sjf_glgetuniformlocation(sjt_functionParam630, sjt_functionParam631, &sjt_functionParam629);
        sjt_dot1838 = scene;
        sjt_functionParam632 = &sjt_dot1838->view;
        sjf_gluniformmat4(sjt_functionParam629, sjt_functionParam632);
        sjt_functionParam634 = &sjv_saturateshader;
        sjt_call195._refCount = 1;
        sjt_call195.count = 10;
        sjt_call195.data._refCount = 1;
        sjt_call195.data.datasize = 11;
        sjt_call195.data.data = (void*)sjg_string19;
        sjt_call195.data._isglobal = true;
        sjt_call195.data.count = 11;
        sjf_array_char(&sjt_call195.data);
        sjf_string(&sjt_call195);
        sjt_functionParam635 = &sjt_call195;
        sjf_glgetuniformlocation(sjt_functionParam634, sjt_functionParam635, &sjt_functionParam633);
        sjt_dot1839 = scene;
        sjt_functionParam636 = &sjt_dot1839->projection;
        sjf_gluniformmat4(sjt_functionParam633, sjt_functionParam636);
        sjt_parent301 = ifValue36;
        sjt_functionParam637 = scene;
        sjf_boxvertexbuffer_render(sjt_parent301, sjt_functionParam637);

        if (sjt_call191._refCount == 1) { sjf_string_destroy(&sjt_call191); }
;
        if (sjt_call192._refCount == 1) { sjf_string_destroy(&sjt_call192); }
;
        if (sjt_call193._refCount == 1) { sjf_string_destroy(&sjt_call193); }
;
        if (sjt_call194._refCount == 1) { sjf_string_destroy(&sjt_call194); }
;
        if (sjt_call195._refCount == 1) { sjf_string_destroy(&sjt_call195); }
;
    }

    if (sjt_call189._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_call189); }
;
    if (sjt_call190._refCount == 1) { sjf_scenebuffer_destroy(&sjt_call190); }
;
}

void sjf_saturateeffect_setrect(sjs_saturateeffect* _parent, sjs_rect* rect_, cb_rect_void cb) {
    bool result22;
    sjs_rect sjt_call188 = { -1 };
    cb_rect_void sjt_callback9;
    sjs_saturateeffect* sjt_dot1800 = 0;
    sjs_rect* sjt_dot1811 = 0;
    sjs_saturateeffect* sjt_dot1812 = 0;
    sjs_rect* sjt_dot1813 = 0;
    sjs_saturateeffect* sjt_dot1814 = 0;
    sjs_rect* sjt_functionParam605 = 0;
    sjs_rect* sjt_functionParam607 = 0;
    bool sjt_ifElse70;
    bool sjt_not15;
    sjs_rect* sjt_parent296 = 0;

    sjt_dot1800 = _parent;
    sjt_parent296 = &sjt_dot1800->_rect;
    sjt_functionParam605 = rect_;
    sjf_rect_isequal(sjt_parent296, sjt_functionParam605, &sjt_not15);
    result22 = !sjt_not15;
    sjt_ifElse70 = result22;
    if (sjt_ifElse70) {
        sjs_rect* sjt_copy111 = 0;
        sjs_saturateeffect* sjt_dot1801 = 0;
        sjs_saturateeffect* sjt_dot1802 = 0;
        sjs_saturateeffect* sjt_dot1810 = 0;
        bool sjt_isEmpty45;
        sjs_scenebuffer* sjt_isEmpty46 = 0;

        sjt_dot1801 = _parent;
        sjt_copy111 = rect_;
        if (sjt_dot1801->_rect._refCount == 1) { sjf_rect_destroy(&sjt_dot1801->_rect); }
;
        sjt_dot1801->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1801->_rect, sjt_copy111);
        sjt_dot1802 = _parent;
        sjt_isEmpty46 = (sjt_dot1802->_scenebuffer._refCount != -1 ? &sjt_dot1802->_scenebuffer : 0);
        sjt_isEmpty45 = (sjt_isEmpty46 != 0);
        if (sjt_isEmpty45) {
            sjs_scenebuffer* ifValue33 = 0;
            bool result23;
            sjs_size sjt_call187 = { -1 };
            sjs_saturateeffect* sjt_dot1803 = 0;
            sjs_scenebuffer* sjt_dot1804 = 0;
            sjs_rect* sjt_dot1805 = 0;
            sjs_saturateeffect* sjt_dot1806 = 0;
            sjs_rect* sjt_dot1807 = 0;
            sjs_saturateeffect* sjt_dot1808 = 0;
            sjs_size* sjt_functionParam606 = 0;
            bool sjt_ifElse71;
            bool sjt_not16;
            sjs_size* sjt_parent297 = 0;

            sjt_dot1803 = _parent;
            ifValue33 = (sjt_dot1803->_scenebuffer._refCount != -1 ? &sjt_dot1803->_scenebuffer : 0);
            sjt_dot1804 = ifValue33;
            sjt_parent297 = &sjt_dot1804->size;
            sjt_call187._refCount = 1;
            sjt_dot1806 = _parent;
            sjt_dot1805 = &sjt_dot1806->_rect;
            sjt_call187.w = sjt_dot1805->w;
            sjt_dot1808 = _parent;
            sjt_dot1807 = &sjt_dot1808->_rect;
            sjt_call187.h = sjt_dot1807->h;
            sjf_size(&sjt_call187);
            sjt_functionParam606 = &sjt_call187;
            sjf_size_isequal(sjt_parent297, sjt_functionParam606, &sjt_not16);
            result23 = !sjt_not16;
            sjt_ifElse71 = result23;
            if (sjt_ifElse71) {
                sjs_saturateeffect* sjt_dot1809 = 0;

                sjt_dot1809 = _parent;
                if (sjt_dot1809->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&sjt_dot1809->_scenebuffer); }
;
                sjt_dot1809->_scenebuffer._refCount = -1;
            }

            if (sjt_call187._refCount == 1) { sjf_size_destroy(&sjt_call187); }
;
        }

        sjt_dot1810 = _parent;
        if (sjt_dot1810->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_dot1810->_vertexbuffer); }
;
        sjt_dot1810->_vertexbuffer._refCount = -1;
    }

    sjt_callback9 = cb;
    sjt_call188._refCount = 1;
    sjt_call188.x = 0;
    sjt_call188.y = 0;
    sjt_dot1812 = _parent;
    sjt_dot1811 = &sjt_dot1812->_rect;
    sjt_call188.w = sjt_dot1811->w;
    sjt_dot1814 = _parent;
    sjt_dot1813 = &sjt_dot1814->_rect;
    sjt_call188.h = sjt_dot1813->h;
    sjf_rect(&sjt_call188);
    sjt_functionParam607 = &sjt_call188;
    sjt_callback9._cb(sjt_callback9._parent, sjt_functionParam607);

    if (sjt_call188._refCount == 1) { sjf_rect_destroy(&sjt_call188); }
;
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
    sjs_scene2d* sjt_dot1728 = 0;
    sjs_scene2d* sjt_dot1729 = 0;
    sjs_rect* sjt_functionParam498 = 0;
    sjs_rect* sjt_functionParam499 = 0;

    sjt_dot1728 = _parent;
    sjt_functionParam498 = &sjt_dot1728->windowrect;
    sjt_dot1729 = _parent;
    sjt_functionParam499 = &sjt_dot1729->windowrect;
    sjf_glpopviewport(sjt_functionParam498, sjt_functionParam499);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result15;
    sjs_mat4 sjt_call158 = { -1 };
    sjs_mat4 sjt_call159 = { -1 };
    sjs_mat4 sjt_call160 = { -1 };
    sjs_scene2d* sjt_dot1708 = 0;
    sjs_size* sjt_functionParam484 = 0;
    bool sjt_ifElse65;
    bool sjt_not12;
    sjs_size* sjt_parent277 = 0;

    sjt_dot1708 = _parent;
    sjt_parent277 = &sjt_dot1708->_size;
    sjt_functionParam484 = size;
    sjf_size_isequal(sjt_parent277, sjt_functionParam484, &sjt_not12);
    result15 = !sjt_not12;
    sjt_ifElse65 = result15;
    if (sjt_ifElse65) {
        float result18;
        float result19;
        int32_t sjt_cast18;
        int32_t sjt_cast19;
        sjs_mat4* sjt_copy100 = 0;
        sjs_mat4* sjt_copy101 = 0;
        sjs_size* sjt_copy98 = 0;
        sjs_mat4* sjt_copy99 = 0;
        sjs_scene2d* sjt_dot1709 = 0;
        sjs_scene2d* sjt_dot1710 = 0;
        sjs_size* sjt_dot1711 = 0;
        sjs_scene2d* sjt_dot1712 = 0;
        sjs_size* sjt_dot1713 = 0;
        sjs_scene2d* sjt_dot1714 = 0;
        sjs_scene2d* sjt_dot1715 = 0;
        sjs_scene2d* sjt_dot1716 = 0;
        float sjt_functionParam485;
        float sjt_functionParam486;
        float sjt_functionParam487;
        float sjt_functionParam488;
        float sjt_functionParam489;
        float sjt_functionParam490;
        float sjt_functionParam491;
        float sjt_functionParam492;
        float sjt_functionParam493;
        int32_t sjt_math2409;
        int32_t sjt_math2410;
        float sjt_negate6;
        float sjt_negate7;

        sjt_dot1709 = _parent;
        sjt_copy98 = size;
        if (sjt_dot1709->_size._refCount == 1) { sjf_size_destroy(&sjt_dot1709->_size); }
;
        sjt_dot1709->_size._refCount = 1;
        sjf_size_copy(&sjt_dot1709->_size, sjt_copy98);
        sjt_dot1710 = _parent;
        sjt_functionParam485 = 0.0f;
        sjt_dot1712 = _parent;
        sjt_dot1711 = &sjt_dot1712->_size;
        sjt_cast18 = sjt_dot1711->w;
        sjt_functionParam486 = (float)sjt_cast18;
        sjt_math2409 = 0;
        sjt_dot1714 = _parent;
        sjt_dot1713 = &sjt_dot1714->_size;
        sjt_math2410 = sjt_dot1713->h;
        sjt_cast19 = sjt_math2409 - sjt_math2410;
        sjt_functionParam487 = (float)sjt_cast19;
        sjt_functionParam488 = 0.0f;
        sjt_negate6 = 1.0f;
        result18 = -sjt_negate6;
        sjt_functionParam489 = result18;
        sjt_functionParam490 = 1.0f;
        sjf_mat4_orthographic(sjt_functionParam485, sjt_functionParam486, sjt_functionParam487, sjt_functionParam488, sjt_functionParam489, sjt_functionParam490, &sjt_call158);
        sjt_copy99 = &sjt_call158;
        if (sjt_dot1710->projection._refCount == 1) { sjf_mat4_destroy(&sjt_dot1710->projection); }
;
        sjt_dot1710->projection._refCount = 1;
        sjf_mat4_copy(&sjt_dot1710->projection, sjt_copy99);
        sjt_dot1715 = _parent;
        sjt_functionParam491 = 1.0f;
        sjt_negate7 = 1.0f;
        result19 = -sjt_negate7;
        sjt_functionParam492 = result19;
        sjt_functionParam493 = 1.0f;
        sjf_mat4_scale(sjt_functionParam491, sjt_functionParam492, sjt_functionParam493, &sjt_call159);
        sjt_copy100 = &sjt_call159;
        if (sjt_dot1715->model._refCount == 1) { sjf_mat4_destroy(&sjt_dot1715->model); }
;
        sjt_dot1715->model._refCount = 1;
        sjf_mat4_copy(&sjt_dot1715->model, sjt_copy100);
        sjt_dot1716 = _parent;
        sjf_mat4_identity(&sjt_call160);
        sjt_copy101 = &sjt_call160;
        if (sjt_dot1716->view._refCount == 1) { sjf_mat4_destroy(&sjt_dot1716->view); }
;
        sjt_dot1716->view._refCount = 1;
        sjf_mat4_copy(&sjt_dot1716->view, sjt_copy101);
    }

    if (sjt_call158._refCount == 1) { sjf_mat4_destroy(&sjt_call158); }
;
    if (sjt_call159._refCount == 1) { sjf_mat4_destroy(&sjt_call159); }
;
    if (sjt_call160._refCount == 1) { sjf_mat4_destroy(&sjt_call160); }
;
}

void sjf_scene2d_start(sjs_scene2d* _parent) {
    sjs_rect sjt_call161 = { -1 };
    sjs_rect* sjt_copy102 = 0;
    sjs_scene2d* sjt_dot1719 = 0;
    sjs_size* sjt_dot1720 = 0;
    sjs_scene2d* sjt_dot1721 = 0;
    sjs_size* sjt_dot1722 = 0;
    sjs_scene2d* sjt_dot1723 = 0;
    sjs_scene2d* sjt_dot1724 = 0;
    sjs_scene2d* sjt_dot1725 = 0;
    sjs_rect* sjt_functionParam495 = 0;
    sjs_rect* sjt_functionParam496 = 0;

    sjt_dot1719 = _parent;
    sjt_call161._refCount = 1;
    sjt_call161.x = 0;
    sjt_call161.y = 0;
    sjt_dot1721 = _parent;
    sjt_dot1720 = &sjt_dot1721->_size;
    sjt_call161.w = sjt_dot1720->w;
    sjt_dot1723 = _parent;
    sjt_dot1722 = &sjt_dot1723->_size;
    sjt_call161.h = sjt_dot1722->h;
    sjf_rect(&sjt_call161);
    sjt_copy102 = &sjt_call161;
    if (sjt_dot1719->windowrect._refCount == 1) { sjf_rect_destroy(&sjt_dot1719->windowrect); }
;
    sjt_dot1719->windowrect._refCount = 1;
    sjf_rect_copy(&sjt_dot1719->windowrect, sjt_copy102);
    sjt_dot1724 = _parent;
    sjt_functionParam495 = &sjt_dot1724->windowrect;
    sjt_dot1725 = _parent;
    sjt_functionParam496 = &sjt_dot1725->windowrect;
    sjf_glpushviewport(sjt_functionParam495, sjt_functionParam496);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_DEPTH_TEST );

    if (sjt_call161._refCount == 1) { sjf_rect_destroy(&sjt_call161); }
;
}

void sjf_scene3delement(sjs_scene3delement* _this) {
}

void sjf_scene3delement_as_sji_element(sjs_scene3delement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_scene3delement_element_vtbl;
}

void sjf_scene3delement_asinterface(sjs_scene3delement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_scene3delement_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_scene3delement_copy(sjs_scene3delement* _this, sjs_scene3delement* _from) {
    _this->children._refCount = 1;
    sjf_array_heap_iface_model_copy(&_this->children, &_from->children);
    _this->camera._refCount = 1;
    sjf_vec3_copy(&_this->camera, &_from->camera);
    _this->lookat._refCount = 1;
    sjf_vec3_copy(&_this->lookat, &_from->lookat);
    _this->up._refCount = 1;
    sjf_vec3_copy(&_this->up, &_from->up);
    _this->fieldofview = _from->fieldofview;
    _this->znear = _from->znear;
    _this->zfar = _from->zfar;
    _this->light._refCount = 1;
    sjf_light_copy(&_this->light, &_from->light);
    _this->projection._refCount = 1;
    sjf_mat4_copy(&_this->projection, &_from->projection);
    _this->view._refCount = 1;
    sjf_mat4_copy(&_this->view, &_from->view);
    _this->world._refCount = 1;
    sjf_mat4_copy(&_this->world, &_from->world);
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_scene3delement_destroy(sjs_scene3delement* _this) {
    if (_this->children._refCount == 1) { sjf_array_heap_iface_model_destroy(&_this->children); }
;
    if (_this->camera._refCount == 1) { sjf_vec3_destroy(&_this->camera); }
;
    if (_this->lookat._refCount == 1) { sjf_vec3_destroy(&_this->lookat); }
;
    if (_this->up._refCount == 1) { sjf_vec3_destroy(&_this->up); }
;
    if (_this->light._refCount == 1) { sjf_light_destroy(&_this->light); }
;
    if (_this->projection._refCount == 1) { sjf_mat4_destroy(&_this->projection); }
;
    if (_this->view._refCount == 1) { sjf_mat4_destroy(&_this->view); }
;
    if (_this->world._refCount == 1) { sjf_mat4_destroy(&_this->world); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_scene3delement_firemouseevent(sjs_scene3delement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot337 = 0;
    sjs_scene3delement* sjt_dot338 = 0;
    int32_t sjt_forEnd15;
    int32_t sjt_forStart15;

    sjt_forStart15 = 0;
    sjt_dot338 = _parent;
    sjt_dot337 = &sjt_dot338->children;
    sjt_forEnd15 = sjt_dot337->count;
    i = sjt_forStart15;
    while (i < sjt_forEnd15) {
        sjs_scene3delement* sjt_dot339 = 0;
        int32_t sjt_functionParam137;
        sjs_mouseevent* sjt_interfaceParam18 = 0;
        sjs_array_heap_iface_model* sjt_parent95 = 0;
        sji_model sjt_parent96 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_dot339 = _parent;
        sjt_parent95 = &sjt_dot339->children;
        sjt_functionParam137 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent95, sjt_functionParam137, &sjv_child);
        sjt_parent96 = sjv_child;
        sjt_interfaceParam18 = mouseevent;
        sjt_parent96._vtbl->firemouseevent(sjt_parent96._parent, sjt_interfaceParam18);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    (*_return) = true;
}

void sjf_scene3delement_getrect(sjs_scene3delement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy15 = 0;
    sjs_scene3delement* sjt_dot192 = 0;

    sjt_dot192 = _parent;
    sjt_copy15 = &sjt_dot192->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy15);
}

void sjf_scene3delement_getrect_heap(sjs_scene3delement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy16 = 0;
    sjs_scene3delement* sjt_dot193 = 0;

    sjt_dot193 = _parent;
    sjt_copy16 = &sjt_dot193->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy16);
}

void sjf_scene3delement_getsize(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot188 = 0;
    sjs_size* sjt_dot189 = 0;

    _return->_refCount = 1;
    sjt_dot188 = maxsize;
    _return->w = sjt_dot188->w;
    sjt_dot189 = maxsize;
    _return->h = sjt_dot189->h;
    sjf_size(_return);
}

void sjf_scene3delement_getsize_heap(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot190 = 0;
    sjs_size* sjt_dot191 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot190 = maxsize;
    (*_return)->w = sjt_dot190->w;
    sjt_dot191 = maxsize;
    (*_return)->h = sjt_dot191->h;
    sjf_size_heap((*_return));
}

void sjf_scene3delement_heap(sjs_scene3delement* _this) {
}

void sjf_scene3delement_render(sjs_scene3delement* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot286 = 0;
    sjs_scene3delement* sjt_dot287 = 0;
    sjs_scene3delement* sjt_dot313 = 0;
    sjs_scene2d* sjt_dot314 = 0;
    sjs_array_heap_iface_model* sjt_dot315 = 0;
    sjs_scene3delement* sjt_dot316 = 0;
    sjs_scene3delement* sjt_dot335 = 0;
    sjs_scene2d* sjt_dot336 = 0;
    int32_t sjt_forEnd12;
    int32_t sjt_forEnd13;
    int32_t sjt_forEnd14;
    int32_t sjt_forStart12;
    int32_t sjt_forStart13;
    int32_t sjt_forStart14;
    cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam123;
    sjs_rect* sjt_functionParam134 = 0;
    sjs_rect* sjt_functionParam135 = 0;
    int32_t sjt_functionParam136;
    int32_t sjt_functionParam90;
    sjs_rect* sjt_functionParam97 = 0;
    sjs_rect* sjt_functionParam98 = 0;
    sjs_list_heap_iface_model* sjt_parent79 = 0;
    sjs_list_heap_iface_model* sjt_parent82 = 0;
    sjs_list_heap_iface_model sjv_a = { -1 };

    sjt_forStart12 = 0;
    sjt_dot287 = _parent;
    sjt_dot286 = &sjt_dot287->children;
    sjt_forEnd12 = sjt_dot286->count;
    i = sjt_forStart12;
    while (i < sjt_forEnd12) {
        sjs_scene3delement* sjt_dot288 = 0;
        sjs_scene3delement* sjt_dot289 = 0;
        sjs_scene3delement* sjt_dot290 = 0;
        sjs_scene3delement* sjt_dot291 = 0;
        sjs_scene3delement* sjt_dot292 = 0;
        sjs_scene3delement* sjt_dot293 = 0;
        int32_t sjt_functionParam89;
        sjs_rect* sjt_interfaceParam12 = 0;
        sjs_mat4* sjt_interfaceParam13 = 0;
        sjs_mat4* sjt_interfaceParam14 = 0;
        sjs_mat4* sjt_interfaceParam15 = 0;
        sjs_light* sjt_interfaceParam16 = 0;
        sjs_array_heap_iface_model* sjt_parent71 = 0;
        sji_model sjt_parent72 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_dot288 = _parent;
        sjt_parent71 = &sjt_dot288->children;
        sjt_functionParam89 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent71, sjt_functionParam89, &sjv_child);
        sjt_parent72 = sjv_child;
        sjt_dot289 = _parent;
        sjt_interfaceParam12 = &sjt_dot289->_rect;
        sjt_dot290 = _parent;
        sjt_interfaceParam13 = &sjt_dot290->projection;
        sjt_dot291 = _parent;
        sjt_interfaceParam14 = &sjt_dot291->view;
        sjt_dot292 = _parent;
        sjt_interfaceParam15 = &sjt_dot292->world;
        sjt_dot293 = _parent;
        sjt_interfaceParam16 = &sjt_dot293->light;
        sjt_parent72._vtbl->update(sjt_parent72._parent, sjt_interfaceParam12, sjt_interfaceParam13, sjt_interfaceParam14, sjt_interfaceParam15, sjt_interfaceParam16);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    sjt_functionParam90 = sjv_glfeature_gl_depth_test;
    sjf_glenable(sjt_functionParam90);
    sjt_dot313 = _parent;
    sjt_functionParam97 = &sjt_dot313->_rect;
    sjt_dot314 = scene;
    sjt_functionParam98 = &sjt_dot314->windowrect;
    sjf_glpushviewport(sjt_functionParam97, sjt_functionParam98);
    sjv_a._refCount = 1;
    sjv_a.array._refCount = 1;
    sjv_a.array.datasize = 0;
    sjv_a.array.data = 0;
    sjv_a.array._isglobal = false;
    sjv_a.array.count = 0;
    sjf_array_heap_iface_model(&sjv_a.array);
    sjf_list_heap_iface_model(&sjv_a);
    sjt_forStart13 = 0;
    sjt_dot316 = _parent;
    sjt_dot315 = &sjt_dot316->children;
    sjt_forEnd13 = sjt_dot315->count;
    i = sjt_forStart13;
    while (i < sjt_forEnd13) {
        sjs_scene3delement* sjt_dot317 = 0;
        int32_t sjt_functionParam99;
        sjs_list_heap_iface_model* sjt_interfaceParam17 = 0;
        sjs_array_heap_iface_model* sjt_parent76 = 0;
        sji_model sjt_parent77 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_dot317 = _parent;
        sjt_parent76 = &sjt_dot317->children;
        sjt_functionParam99 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent76, sjt_functionParam99, &sjv_child);
        sjt_parent77 = sjv_child;
        sjt_interfaceParam17 = &sjv_a;
        sjt_parent77._vtbl->renderorqueue(sjt_parent77._parent, sjt_interfaceParam17);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    sjt_parent79 = &sjv_a;
    sjt_functionParam123._parent = (sjs_object*)1;
    sjt_functionParam123._cb = (void(*)(sjs_object*,sji_model,sji_model, int32_t*))sjf_model_zsort_callback;
    sjf_list_heap_iface_model_sortcb(sjt_parent79, sjt_functionParam123);
    sjt_forStart14 = 0;
    sjt_parent82 = &sjv_a;
    sjf_list_heap_iface_model_getcount(sjt_parent82, &sjt_forEnd14);
    i = sjt_forEnd14 - 1;
    while (i >= sjt_forStart14) {
        int32_t sjt_functionParam127;
        sjs_list_heap_iface_model* sjt_parent84 = 0;
        sji_model sjt_parent85 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_parent84 = &sjv_a;
        sjt_functionParam127 = i;
        sjf_list_heap_iface_model_getat_heap(sjt_parent84, sjt_functionParam127, &sjv_child);
        sjt_parent85 = sjv_child;
        sjt_parent85._vtbl->render(sjt_parent85._parent);
        i--;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    sjt_dot335 = _parent;
    sjt_functionParam134 = &sjt_dot335->_rect;
    sjt_dot336 = scene;
    sjt_functionParam135 = &sjt_dot336->windowrect;
    sjf_glpopviewport(sjt_functionParam134, sjt_functionParam135);
    sjt_functionParam136 = sjv_glfeature_gl_depth_test;
    sjf_gldisable(sjt_functionParam136);

    if (sjv_a._refCount == 1) { sjf_list_heap_iface_model_destroy(&sjv_a); }
;
}

void sjf_scene3delement_setrect(sjs_scene3delement* _parent, sjs_rect* rect_) {
    bool result3;
    sjs_mat4 sjt_call14 = { -1 };
    sjs_mat4 sjt_call15 = { -1 };
    sjs_scene3delement* sjt_dot194 = 0;
    sjs_rect* sjt_functionParam65 = 0;
    bool sjt_ifElse24;
    bool sjt_not2;
    sjs_rect* sjt_parent54 = 0;

    sjt_dot194 = _parent;
    sjt_parent54 = &sjt_dot194->_rect;
    sjt_functionParam65 = rect_;
    sjf_rect_isequal(sjt_parent54, sjt_functionParam65, &sjt_not2);
    result3 = !sjt_not2;
    sjt_ifElse24 = result3;
    if (sjt_ifElse24) {
        int32_t sjt_cast7;
        int32_t sjt_cast8;
        sjs_rect* sjt_copy17 = 0;
        sjs_mat4* sjt_copy18 = 0;
        sjs_mat4* sjt_copy19 = 0;
        sjs_scene3delement* sjt_dot195 = 0;
        sjs_scene3delement* sjt_dot196 = 0;
        sjs_scene3delement* sjt_dot197 = 0;
        sjs_rect* sjt_dot198 = 0;
        sjs_scene3delement* sjt_dot199 = 0;
        sjs_rect* sjt_dot200 = 0;
        sjs_scene3delement* sjt_dot201 = 0;
        sjs_scene3delement* sjt_dot202 = 0;
        sjs_scene3delement* sjt_dot203 = 0;
        sjs_scene3delement* sjt_dot204 = 0;
        sjs_scene3delement* sjt_dot283 = 0;
        sjs_scene3delement* sjt_dot284 = 0;
        sjs_scene3delement* sjt_dot285 = 0;
        float sjt_functionParam68;
        float sjt_functionParam69;
        float sjt_functionParam70;
        float sjt_functionParam71;
        sjs_vec3* sjt_functionParam86 = 0;
        sjs_vec3* sjt_functionParam87 = 0;
        sjs_vec3* sjt_functionParam88 = 0;
        float sjt_math165;
        float sjt_math166;

        sjt_dot195 = _parent;
        sjt_copy17 = rect_;
        if (sjt_dot195->_rect._refCount == 1) { sjf_rect_destroy(&sjt_dot195->_rect); }
;
        sjt_dot195->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot195->_rect, sjt_copy17);
        sjt_dot196 = _parent;
        sjt_dot197 = _parent;
        sjt_functionParam68 = sjt_dot197->fieldofview;
        sjt_dot199 = _parent;
        sjt_dot198 = &sjt_dot199->_rect;
        sjt_cast7 = sjt_dot198->h;
        sjt_math165 = (float)sjt_cast7;
        sjt_dot201 = _parent;
        sjt_dot200 = &sjt_dot201->_rect;
        sjt_cast8 = sjt_dot200->w;
        sjt_math166 = (float)sjt_cast8;
        sjt_functionParam69 = sjt_math165 / sjt_math166;
        sjt_dot202 = _parent;
        sjt_functionParam70 = sjt_dot202->znear;
        sjt_dot203 = _parent;
        sjt_functionParam71 = sjt_dot203->zfar;
        sjf_mat4_perspective(sjt_functionParam68, sjt_functionParam69, sjt_functionParam70, sjt_functionParam71, &sjt_call14);
        sjt_copy18 = &sjt_call14;
        if (sjt_dot196->projection._refCount == 1) { sjf_mat4_destroy(&sjt_dot196->projection); }
;
        sjt_dot196->projection._refCount = 1;
        sjf_mat4_copy(&sjt_dot196->projection, sjt_copy18);
        sjt_dot204 = _parent;
        sjt_dot283 = _parent;
        sjt_functionParam86 = &sjt_dot283->camera;
        sjt_dot284 = _parent;
        sjt_functionParam87 = &sjt_dot284->lookat;
        sjt_dot285 = _parent;
        sjt_functionParam88 = &sjt_dot285->up;
        sjf_mat4_lookatlh(sjt_functionParam86, sjt_functionParam87, sjt_functionParam88, &sjt_call15);
        sjt_copy19 = &sjt_call15;
        if (sjt_dot204->view._refCount == 1) { sjf_mat4_destroy(&sjt_dot204->view); }
;
        sjt_dot204->view._refCount = 1;
        sjf_mat4_copy(&sjt_dot204->view, sjt_copy19);
    }

    if (sjt_call14._refCount == 1) { sjf_mat4_destroy(&sjt_call14); }
;
    if (sjt_call15._refCount == 1) { sjf_mat4_destroy(&sjt_call15); }
;
}

void sjf_scenebuffer(sjs_scenebuffer* _this) {
    sjs_framebuffer sjt_call141 = { -1 };
    sjs_texture sjt_call142 = { -1 };
    sjs_renderbuffer sjt_call143 = { -1 };
    sjs_string sjt_call145 = { -1 };
    int32_t sjt_compare109;
    int32_t sjt_compare110;
    sjs_framebuffer* sjt_copy77 = 0;
    sjs_texture* sjt_copy80 = 0;
    sjs_renderbuffer* sjt_copy83 = 0;
    sjs_size* sjt_functionParam396 = 0;
    sjs_size* sjt_functionParam397 = 0;
    sjs_size* sjt_functionParam398 = 0;
    sjs_framebuffer* sjt_functionParam405 = 0;
    int32_t sjt_functionParam406;
    sjs_texture* sjt_functionParam407 = 0;
    int32_t sjt_functionParam408;
    int32_t sjt_functionParam409;
    int32_t sjt_functionParam410;
    int32_t sjt_functionParam411;
    int32_t sjt_functionParam412;
    int32_t sjt_functionParam413;
    int32_t sjt_functionParam414;
    int32_t sjt_functionParam415;
    int32_t sjt_functionParam416;
    int32_t sjt_functionParam417;
    int32_t sjt_functionParam418;
    int32_t sjt_functionParam419;
    int32_t sjt_functionParam420;
    int32_t sjt_functionParam421;
    int32_t sjt_functionParam422;
    sjs_size* sjt_functionParam423 = 0;
    int32_t sjt_functionParam424;
    void* sjt_functionParam425;
    int32_t sjt_functionParam426;
    int32_t sjt_functionParam427;
    sjs_texture* sjt_functionParam428 = 0;
    int32_t sjt_functionParam429;
    sjs_renderbuffer* sjt_functionParam430 = 0;
    int32_t sjt_functionParam431;
    sjs_size* sjt_functionParam432 = 0;
    int32_t sjt_functionParam433;
    sjs_renderbuffer* sjt_functionParam434 = 0;
    sjs_framebuffer* sjt_functionParam441 = 0;
    bool sjt_ifElse52;
    int32_t sjv_status;

    sjt_functionParam396 = &_this->size;
    sjf_glgenframebuffer(sjt_functionParam396, &sjt_call141);
    sjt_copy77 = &sjt_call141;
    if (_this->framebuffer._refCount == 1) { sjf_framebuffer_destroy(&_this->framebuffer); }
;
    _this->framebuffer._refCount = 1;
    sjf_framebuffer_copy(&_this->framebuffer, sjt_copy77);
    sjt_functionParam397 = &_this->size;
    sjf_glgentexture(sjt_functionParam397, &sjt_call142);
    sjt_copy80 = &sjt_call142;
    if (_this->texture._refCount == 1) { sjf_texture_destroy(&_this->texture); }
;
    _this->texture._refCount = 1;
    sjf_texture_copy(&_this->texture, sjt_copy80);
    sjt_functionParam398 = &_this->size;
    sjf_glgenrenderbuffer(sjt_functionParam398, &sjt_call143);
    sjt_copy83 = &sjt_call143;
    if (_this->renderbuffer._refCount == 1) { sjf_renderbuffer_destroy(&_this->renderbuffer); }
;
    _this->renderbuffer._refCount = 1;
    sjf_renderbuffer_copy(&_this->renderbuffer, sjt_copy83);
    sjt_functionParam405 = &_this->framebuffer;
    sjf_glpushframebuffer(sjt_functionParam405);
    sjt_functionParam406 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam407 = &_this->texture;
    sjf_glbindtexture(sjt_functionParam406, sjt_functionParam407);
    sjt_functionParam408 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam409 = sjv_gltextureattribute_gl_texture_wrap_s;
    sjt_functionParam410 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam408, sjt_functionParam409, sjt_functionParam410);
    sjt_functionParam411 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam412 = sjv_gltextureattribute_gl_texture_wrap_t;
    sjt_functionParam413 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam411, sjt_functionParam412, sjt_functionParam413);
    sjt_functionParam414 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam415 = sjv_gltextureattribute_gl_texture_min_filter;
    sjt_functionParam416 = sjv_gltexturevalue_gl_linear;
    sjf_gltexparameteri(sjt_functionParam414, sjt_functionParam415, sjt_functionParam416);
    sjt_functionParam417 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam418 = sjv_gltextureattribute_gl_texture_mag_filter;
    sjt_functionParam419 = sjv_gltexturevalue_gl_linear;
    sjf_gltexparameteri(sjt_functionParam417, sjt_functionParam418, sjt_functionParam419);
    sjt_functionParam420 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam421 = 0;
    sjt_functionParam422 = sjv_gltextureformat_gl_rgba;
    sjt_functionParam423 = &_this->size;
    sjt_functionParam424 = sjv_gltexturetype_gl_unsigned_byte;
    sjt_functionParam425 = 0;
    sjf_glteximage2d(sjt_functionParam420, sjt_functionParam421, sjt_functionParam422, sjt_functionParam423, sjt_functionParam424, sjt_functionParam425);
    sjt_functionParam426 = sjv_glframebufferattachment_gl_color_attachment0;
    sjt_functionParam427 = sjv_glframebuffertexture_gl_texture_2d;
    sjt_functionParam428 = &_this->texture;
    sjt_functionParam429 = 0;
    sjf_glframebuffertexture2d(sjt_functionParam426, sjt_functionParam427, sjt_functionParam428, sjt_functionParam429);
    sjt_functionParam430 = &_this->renderbuffer;
    sjf_glbindrenderbuffer(sjt_functionParam430);
    sjt_functionParam431 = sjv_glrenderbufferformat_gl_depth_component16;
    sjt_functionParam432 = &_this->size;
    sjf_glrenderbufferstorage(sjt_functionParam431, sjt_functionParam432);
    sjt_functionParam433 = sjv_glframebufferattachment_gl_depth_attachment;
    sjt_functionParam434 = &_this->renderbuffer;
    sjf_glframebufferrenderbuffer(sjt_functionParam433, sjt_functionParam434);
    sjf_glcheckframebufferstatus(&sjv_status);
    sjt_compare109 = sjv_status;
    sjt_compare110 = sjv_glframebufferstatus_gl_framebuffer_complete;
    sjt_ifElse52 = sjt_compare109 != sjt_compare110;
    if (sjt_ifElse52) {
        sjs_string* sjt_functionParam435 = 0;

        sjt_call145._refCount = 1;
        sjt_call145.count = 18;
        sjt_call145.data._refCount = 1;
        sjt_call145.data.datasize = 19;
        sjt_call145.data.data = (void*)sjg_string32;
        sjt_call145.data._isglobal = true;
        sjt_call145.data.count = 19;
        sjf_array_char(&sjt_call145.data);
        sjf_string(&sjt_call145);
        sjt_functionParam435 = &sjt_call145;
        sjf_halt(sjt_functionParam435);
    }

    sjt_functionParam441 = &_this->framebuffer;
    sjf_glpopframebuffer(sjt_functionParam441);

    if (sjt_call141._refCount == 1) { sjf_framebuffer_destroy(&sjt_call141); }
;
    if (sjt_call142._refCount == 1) { sjf_texture_destroy(&sjt_call142); }
;
    if (sjt_call143._refCount == 1) { sjf_renderbuffer_destroy(&sjt_call143); }
;
    if (sjt_call145._refCount == 1) { sjf_string_destroy(&sjt_call145); }
;
}

void sjf_scenebuffer_copy(sjs_scenebuffer* _this, sjs_scenebuffer* _from) {
    _this->size._refCount = 1;
    sjf_size_copy(&_this->size, &_from->size);
    _this->framebuffer._refCount = 1;
    sjf_framebuffer_copy(&_this->framebuffer, &_from->framebuffer);
    _this->texture._refCount = 1;
    sjf_texture_copy(&_this->texture, &_from->texture);
    _this->renderbuffer._refCount = 1;
    sjf_renderbuffer_copy(&_this->renderbuffer, &_from->renderbuffer);
}

void sjf_scenebuffer_destroy(sjs_scenebuffer* _this) {
    if (_this->size._refCount == 1) { sjf_size_destroy(&_this->size); }
;
    if (_this->framebuffer._refCount == 1) { sjf_framebuffer_destroy(&_this->framebuffer); }
;
    if (_this->texture._refCount == 1) { sjf_texture_destroy(&_this->texture); }
;
    if (_this->renderbuffer._refCount == 1) { sjf_renderbuffer_destroy(&_this->renderbuffer); }
;
}

void sjf_scenebuffer_heap(sjs_scenebuffer* _this) {
    sjs_framebuffer sjt_call147 = { -1 };
    sjs_texture sjt_call148 = { -1 };
    sjs_renderbuffer sjt_call149 = { -1 };
    sjs_string sjt_call150 = { -1 };
    int32_t sjt_compare115;
    int32_t sjt_compare116;
    sjs_framebuffer* sjt_copy87 = 0;
    sjs_texture* sjt_copy88 = 0;
    sjs_renderbuffer* sjt_copy89 = 0;
    sjs_size* sjt_functionParam442 = 0;
    sjs_size* sjt_functionParam443 = 0;
    sjs_size* sjt_functionParam444 = 0;
    sjs_framebuffer* sjt_functionParam445 = 0;
    int32_t sjt_functionParam446;
    sjs_texture* sjt_functionParam447 = 0;
    int32_t sjt_functionParam448;
    int32_t sjt_functionParam449;
    int32_t sjt_functionParam450;
    int32_t sjt_functionParam451;
    int32_t sjt_functionParam452;
    int32_t sjt_functionParam453;
    int32_t sjt_functionParam454;
    int32_t sjt_functionParam455;
    int32_t sjt_functionParam456;
    int32_t sjt_functionParam457;
    int32_t sjt_functionParam458;
    int32_t sjt_functionParam459;
    int32_t sjt_functionParam460;
    int32_t sjt_functionParam461;
    int32_t sjt_functionParam462;
    sjs_size* sjt_functionParam463 = 0;
    int32_t sjt_functionParam464;
    void* sjt_functionParam465;
    int32_t sjt_functionParam466;
    int32_t sjt_functionParam467;
    sjs_texture* sjt_functionParam468 = 0;
    int32_t sjt_functionParam469;
    sjs_renderbuffer* sjt_functionParam470 = 0;
    int32_t sjt_functionParam471;
    sjs_size* sjt_functionParam472 = 0;
    int32_t sjt_functionParam473;
    sjs_renderbuffer* sjt_functionParam474 = 0;
    sjs_framebuffer* sjt_functionParam476 = 0;
    bool sjt_ifElse55;
    int32_t sjv_status;

    sjt_functionParam442 = &_this->size;
    sjf_glgenframebuffer(sjt_functionParam442, &sjt_call147);
    sjt_copy87 = &sjt_call147;
    if (_this->framebuffer._refCount == 1) { sjf_framebuffer_destroy(&_this->framebuffer); }
;
    _this->framebuffer._refCount = 1;
    sjf_framebuffer_copy(&_this->framebuffer, sjt_copy87);
    sjt_functionParam443 = &_this->size;
    sjf_glgentexture(sjt_functionParam443, &sjt_call148);
    sjt_copy88 = &sjt_call148;
    if (_this->texture._refCount == 1) { sjf_texture_destroy(&_this->texture); }
;
    _this->texture._refCount = 1;
    sjf_texture_copy(&_this->texture, sjt_copy88);
    sjt_functionParam444 = &_this->size;
    sjf_glgenrenderbuffer(sjt_functionParam444, &sjt_call149);
    sjt_copy89 = &sjt_call149;
    if (_this->renderbuffer._refCount == 1) { sjf_renderbuffer_destroy(&_this->renderbuffer); }
;
    _this->renderbuffer._refCount = 1;
    sjf_renderbuffer_copy(&_this->renderbuffer, sjt_copy89);
    sjt_functionParam445 = &_this->framebuffer;
    sjf_glpushframebuffer(sjt_functionParam445);
    sjt_functionParam446 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam447 = &_this->texture;
    sjf_glbindtexture(sjt_functionParam446, sjt_functionParam447);
    sjt_functionParam448 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam449 = sjv_gltextureattribute_gl_texture_wrap_s;
    sjt_functionParam450 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam448, sjt_functionParam449, sjt_functionParam450);
    sjt_functionParam451 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam452 = sjv_gltextureattribute_gl_texture_wrap_t;
    sjt_functionParam453 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam451, sjt_functionParam452, sjt_functionParam453);
    sjt_functionParam454 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam455 = sjv_gltextureattribute_gl_texture_min_filter;
    sjt_functionParam456 = sjv_gltexturevalue_gl_linear;
    sjf_gltexparameteri(sjt_functionParam454, sjt_functionParam455, sjt_functionParam456);
    sjt_functionParam457 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam458 = sjv_gltextureattribute_gl_texture_mag_filter;
    sjt_functionParam459 = sjv_gltexturevalue_gl_linear;
    sjf_gltexparameteri(sjt_functionParam457, sjt_functionParam458, sjt_functionParam459);
    sjt_functionParam460 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam461 = 0;
    sjt_functionParam462 = sjv_gltextureformat_gl_rgba;
    sjt_functionParam463 = &_this->size;
    sjt_functionParam464 = sjv_gltexturetype_gl_unsigned_byte;
    sjt_functionParam465 = 0;
    sjf_glteximage2d(sjt_functionParam460, sjt_functionParam461, sjt_functionParam462, sjt_functionParam463, sjt_functionParam464, sjt_functionParam465);
    sjt_functionParam466 = sjv_glframebufferattachment_gl_color_attachment0;
    sjt_functionParam467 = sjv_glframebuffertexture_gl_texture_2d;
    sjt_functionParam468 = &_this->texture;
    sjt_functionParam469 = 0;
    sjf_glframebuffertexture2d(sjt_functionParam466, sjt_functionParam467, sjt_functionParam468, sjt_functionParam469);
    sjt_functionParam470 = &_this->renderbuffer;
    sjf_glbindrenderbuffer(sjt_functionParam470);
    sjt_functionParam471 = sjv_glrenderbufferformat_gl_depth_component16;
    sjt_functionParam472 = &_this->size;
    sjf_glrenderbufferstorage(sjt_functionParam471, sjt_functionParam472);
    sjt_functionParam473 = sjv_glframebufferattachment_gl_depth_attachment;
    sjt_functionParam474 = &_this->renderbuffer;
    sjf_glframebufferrenderbuffer(sjt_functionParam473, sjt_functionParam474);
    sjf_glcheckframebufferstatus(&sjv_status);
    sjt_compare115 = sjv_status;
    sjt_compare116 = sjv_glframebufferstatus_gl_framebuffer_complete;
    sjt_ifElse55 = sjt_compare115 != sjt_compare116;
    if (sjt_ifElse55) {
        sjs_string* sjt_functionParam475 = 0;

        sjt_call150._refCount = 1;
        sjt_call150.count = 18;
        sjt_call150.data._refCount = 1;
        sjt_call150.data.datasize = 19;
        sjt_call150.data.data = (void*)sjg_string32;
        sjt_call150.data._isglobal = true;
        sjt_call150.data.count = 19;
        sjf_array_char(&sjt_call150.data);
        sjf_string(&sjt_call150);
        sjt_functionParam475 = &sjt_call150;
        sjf_halt(sjt_functionParam475);
    }

    sjt_functionParam476 = &_this->framebuffer;
    sjf_glpopframebuffer(sjt_functionParam476);

    if (sjt_call147._refCount == 1) { sjf_framebuffer_destroy(&sjt_call147); }
;
    if (sjt_call148._refCount == 1) { sjf_texture_destroy(&sjt_call148); }
;
    if (sjt_call149._refCount == 1) { sjf_renderbuffer_destroy(&sjt_call149); }
;
    if (sjt_call150._refCount == 1) { sjf_string_destroy(&sjt_call150); }
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
    sjt_math111 = sjt_dot117->w;
    sjt_dot118 = margin;
    sjt_math112 = sjt_dot118->l;
    sjt_math109 = sjt_math111 + sjt_math112;
    sjt_dot119 = margin;
    sjt_math110 = sjt_dot119->r;
    _return->w = sjt_math109 + sjt_math110;
    sjt_dot120 = _parent;
    sjt_math115 = sjt_dot120->h;
    sjt_dot121 = margin;
    sjt_math116 = sjt_dot121->t;
    sjt_math113 = sjt_math115 + sjt_math116;
    sjt_dot122 = margin;
    sjt_math114 = sjt_dot122->b;
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
    sjt_math119 = sjt_dot123->w;
    sjt_dot124 = margin;
    sjt_math120 = sjt_dot124->l;
    sjt_math117 = sjt_math119 + sjt_math120;
    sjt_dot125 = margin;
    sjt_math118 = sjt_dot125->r;
    (*_return)->w = sjt_math117 + sjt_math118;
    sjt_dot126 = _parent;
    sjt_math123 = sjt_dot126->h;
    sjt_dot127 = margin;
    sjt_math124 = sjt_dot127->t;
    sjt_math121 = sjt_math123 + sjt_math124;
    sjt_dot128 = margin;
    sjt_math122 = sjt_dot128->b;
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
    bool sjt_and17;
    bool sjt_and18;
    int32_t sjt_compare117;
    int32_t sjt_compare118;
    int32_t sjt_compare119;
    int32_t sjt_compare120;
    sjs_size* sjt_dot1651 = 0;
    sjs_size* sjt_dot1652 = 0;
    sjs_size* sjt_dot1653 = 0;
    sjs_size* sjt_dot1654 = 0;

    sjt_dot1651 = _parent;
    sjt_compare117 = sjt_dot1651->w;
    sjt_dot1652 = size;
    sjt_compare118 = sjt_dot1652->w;
    sjt_and17 = sjt_compare117 == sjt_compare118;
    sjt_dot1653 = _parent;
    sjt_compare119 = sjt_dot1653->h;
    sjt_dot1654 = size;
    sjt_compare120 = sjt_dot1654->h;
    sjt_and18 = sjt_compare119 == sjt_compare120;
    (*_return) = sjt_and17 && sjt_and18;
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
    sjt_compare25 = sjt_dot101->w;
    sjt_dot102 = maxsize;
    sjt_compare26 = sjt_dot102->w;
    sjt_ifElse13 = sjt_compare25 > sjt_compare26;
    if (sjt_ifElse13) {
        sjs_size* sjt_dot103 = 0;

        sjt_dot103 = _parent;
        _return->w = sjt_dot103->w;
    } else {
        sjs_size* sjt_dot104 = 0;

        sjt_dot104 = maxsize;
        _return->w = sjt_dot104->w;
    }

    sjt_dot105 = _parent;
    sjt_compare27 = sjt_dot105->h;
    sjt_dot106 = maxsize;
    sjt_compare28 = sjt_dot106->h;
    sjt_ifElse14 = sjt_compare27 > sjt_compare28;
    if (sjt_ifElse14) {
        sjs_size* sjt_dot107 = 0;

        sjt_dot107 = _parent;
        _return->h = sjt_dot107->h;
    } else {
        sjs_size* sjt_dot108 = 0;

        sjt_dot108 = maxsize;
        _return->h = sjt_dot108->h;
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
    sjt_compare29 = sjt_dot109->w;
    sjt_dot110 = maxsize;
    sjt_compare30 = sjt_dot110->w;
    sjt_ifElse15 = sjt_compare29 > sjt_compare30;
    if (sjt_ifElse15) {
        sjs_size* sjt_dot111 = 0;

        sjt_dot111 = _parent;
        (*_return)->w = sjt_dot111->w;
    } else {
        sjs_size* sjt_dot112 = 0;

        sjt_dot112 = maxsize;
        (*_return)->w = sjt_dot112->w;
    }

    sjt_dot113 = _parent;
    sjt_compare31 = sjt_dot113->h;
    sjt_dot114 = maxsize;
    sjt_compare32 = sjt_dot114->h;
    sjt_ifElse16 = sjt_compare31 > sjt_compare32;
    if (sjt_ifElse16) {
        sjs_size* sjt_dot115 = 0;

        sjt_dot115 = _parent;
        (*_return)->h = sjt_dot115->h;
    } else {
        sjs_size* sjt_dot116 = 0;

        sjt_dot116 = maxsize;
        (*_return)->h = sjt_dot116->h;
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
    sjt_compare33 = sjt_dot151->w;
    sjt_dot152 = maxsize;
    sjt_compare34 = sjt_dot152->w;
    sjt_ifElse17 = sjt_compare33 < sjt_compare34;
    if (sjt_ifElse17) {
        sjs_size* sjt_dot153 = 0;

        sjt_dot153 = _parent;
        _return->w = sjt_dot153->w;
    } else {
        sjs_size* sjt_dot154 = 0;

        sjt_dot154 = maxsize;
        _return->w = sjt_dot154->w;
    }

    sjt_dot155 = _parent;
    sjt_compare35 = sjt_dot155->h;
    sjt_dot156 = maxsize;
    sjt_compare36 = sjt_dot156->h;
    sjt_ifElse18 = sjt_compare35 < sjt_compare36;
    if (sjt_ifElse18) {
        sjs_size* sjt_dot157 = 0;

        sjt_dot157 = _parent;
        _return->h = sjt_dot157->h;
    } else {
        sjs_size* sjt_dot158 = 0;

        sjt_dot158 = maxsize;
        _return->h = sjt_dot158->h;
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
    sjt_compare37 = sjt_dot159->w;
    sjt_dot160 = maxsize;
    sjt_compare38 = sjt_dot160->w;
    sjt_ifElse19 = sjt_compare37 < sjt_compare38;
    if (sjt_ifElse19) {
        sjs_size* sjt_dot161 = 0;

        sjt_dot161 = _parent;
        (*_return)->w = sjt_dot161->w;
    } else {
        sjs_size* sjt_dot162 = 0;

        sjt_dot162 = maxsize;
        (*_return)->w = sjt_dot162->w;
    }

    sjt_dot163 = _parent;
    sjt_compare39 = sjt_dot163->h;
    sjt_dot164 = maxsize;
    sjt_compare40 = sjt_dot164->h;
    sjt_ifElse20 = sjt_compare39 < sjt_compare40;
    if (sjt_ifElse20) {
        sjs_size* sjt_dot165 = 0;

        sjt_dot165 = _parent;
        (*_return)->h = sjt_dot165->h;
    } else {
        sjs_size* sjt_dot166 = 0;

        sjt_dot166 = maxsize;
        (*_return)->h = sjt_dot166->h;
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
    sjt_math95 = sjt_dot85->w;
    sjt_dot86 = margin;
    sjt_math96 = sjt_dot86->l;
    sjt_math93 = sjt_math95 - sjt_math96;
    sjt_dot87 = margin;
    sjt_math94 = sjt_dot87->r;
    _return->w = sjt_math93 - sjt_math94;
    sjt_dot88 = _parent;
    sjt_math99 = sjt_dot88->h;
    sjt_dot89 = margin;
    sjt_math100 = sjt_dot89->t;
    sjt_math97 = sjt_math99 - sjt_math100;
    sjt_dot90 = margin;
    sjt_math98 = sjt_dot90->b;
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
    sjt_math103 = sjt_dot91->w;
    sjt_dot92 = margin;
    sjt_math104 = sjt_dot92->l;
    sjt_math101 = sjt_math103 - sjt_math104;
    sjt_dot93 = margin;
    sjt_math102 = sjt_dot93->r;
    (*_return)->w = sjt_math101 - sjt_math102;
    sjt_dot94 = _parent;
    sjt_math107 = sjt_dot94->h;
    sjt_dot95 = margin;
    sjt_math108 = sjt_dot95->t;
    sjt_math105 = sjt_math107 - sjt_math108;
    sjt_dot96 = margin;
    sjt_math106 = sjt_dot96->b;
    (*_return)->h = sjt_math105 - sjt_math106;
    sjf_size_heap((*_return));
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    int32_t sjt_compare85;
    int32_t sjt_compare86;
    sjs_string* sjt_dot1479 = 0;
    bool sjt_ifElse39;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot1479 = item;
    sjt_compare85 = sjt_dot1479->count;
    sjt_compare86 = 0;
    sjt_ifElse39 = sjt_compare85 == sjt_compare86;
    if (sjt_ifElse39) {
        sjs_array_char* sjt_copy30 = 0;
        sjs_string* sjt_dot1480 = 0;
        sjs_string* sjt_dot1481 = 0;

        _return->_refCount = 1;
        sjt_dot1480 = _parent;
        _return->count = sjt_dot1480->count;
        sjt_dot1481 = _parent;
        sjt_copy30 = &sjt_dot1481->data;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy30);
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_cast12;
        sjs_array_char* sjt_copy31 = 0;
        sjs_string* sjt_dot1484 = 0;
        sjs_string* sjt_dot1485 = 0;
        sjs_string* sjt_dot1486 = 0;
        sjs_string* sjt_dot1487 = 0;
        sjs_string* sjt_dot1489 = 0;
        int32_t sjt_forEnd16;
        int32_t sjt_forStart16;
        int32_t sjt_functionParam199;
        int32_t sjt_functionParam200;
        char sjt_functionParam201;
        int32_t sjt_functionParam203;
        int32_t sjt_functionParam207;
        char sjt_functionParam208;
        int32_t sjt_math2219;
        int32_t sjt_math2220;
        int32_t sjt_math2221;
        int32_t sjt_math2222;
        int32_t sjt_math2223;
        int32_t sjt_math2224;
        sjs_array_char* sjt_parent119 = 0;
        sjs_array_char* sjt_parent120 = 0;
        sjs_string* sjt_parent122 = 0;
        sjs_array_char* sjt_parent125 = 0;
        int32_t sjv_newcount;

        sjt_dot1484 = _parent;
        sjt_parent119 = &sjt_dot1484->data;
        sjt_dot1485 = _parent;
        sjt_math2221 = sjt_dot1485->count;
        sjt_dot1486 = item;
        sjt_math2222 = sjt_dot1486->count;
        sjt_math2219 = sjt_math2221 + sjt_math2222;
        sjt_math2220 = 1;
        sjt_functionParam199 = sjt_math2219 + sjt_math2220;
        sjf_array_char_grow(sjt_parent119, sjt_functionParam199, &sjv_newdata);
        sjt_dot1487 = _parent;
        sjv_newcount = sjt_dot1487->count;
        sjt_parent120 = &sjv_newdata;
        sjt_functionParam200 = sjv_newcount;
        sjt_parent122 = item;
        sjt_functionParam203 = 0;
        sjf_string_getat(sjt_parent122, sjt_functionParam203, &sjt_functionParam201);
        sjf_array_char_setat(sjt_parent120, sjt_functionParam200, sjt_functionParam201);
        sjt_math2223 = sjv_newcount;
        sjt_math2224 = 1;
        sjv_newcount = sjt_math2223 + sjt_math2224;
        sjt_forStart16 = 1;
        sjt_dot1489 = item;
        sjt_forEnd16 = sjt_dot1489->count;
        i = sjt_forStart16;
        while (i < sjt_forEnd16) {
            int32_t sjt_functionParam204;
            char sjt_functionParam205;
            int32_t sjt_functionParam206;
            int32_t sjt_math2225;
            int32_t sjt_math2226;
            sjs_array_char* sjt_parent123 = 0;
            sjs_string* sjt_parent124 = 0;

            sjt_parent123 = &sjv_newdata;
            sjt_functionParam204 = sjv_newcount;
            sjt_parent124 = item;
            sjt_functionParam206 = i;
            sjf_string_getat(sjt_parent124, sjt_functionParam206, &sjt_functionParam205);
            sjf_array_char_initat(sjt_parent123, sjt_functionParam204, sjt_functionParam205);
            sjt_math2225 = sjv_newcount;
            sjt_math2226 = 1;
            sjv_newcount = sjt_math2225 + sjt_math2226;
            i++;
        }

        sjt_parent125 = &sjv_newdata;
        sjt_functionParam207 = sjv_newcount;
        sjt_cast12 = 0;
        sjt_functionParam208 = (char)sjt_cast12;
        sjf_array_char_initat(sjt_parent125, sjt_functionParam207, sjt_functionParam208);
        _return->_refCount = 1;
        _return->count = sjv_newcount;
        sjt_copy31 = &sjv_newdata;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy31);
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t sjt_compare87;
    int32_t sjt_compare88;
    sjs_string* sjt_dot1490 = 0;
    bool sjt_ifElse40;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot1490 = item;
    sjt_compare87 = sjt_dot1490->count;
    sjt_compare88 = 0;
    sjt_ifElse40 = sjt_compare87 == sjt_compare88;
    if (sjt_ifElse40) {
        sjs_array_char* sjt_copy32 = 0;
        sjs_string* sjt_dot1491 = 0;
        sjs_string* sjt_dot1492 = 0;

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        sjt_dot1491 = _parent;
        (*_return)->count = sjt_dot1491->count;
        sjt_dot1492 = _parent;
        sjt_copy32 = &sjt_dot1492->data;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy32);
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_cast13;
        sjs_array_char* sjt_copy33 = 0;
        sjs_string* sjt_dot1493 = 0;
        sjs_string* sjt_dot1494 = 0;
        sjs_string* sjt_dot1495 = 0;
        sjs_string* sjt_dot1496 = 0;
        sjs_string* sjt_dot1497 = 0;
        int32_t sjt_forEnd17;
        int32_t sjt_forStart17;
        int32_t sjt_functionParam209;
        int32_t sjt_functionParam210;
        char sjt_functionParam211;
        int32_t sjt_functionParam212;
        int32_t sjt_functionParam216;
        char sjt_functionParam217;
        int32_t sjt_math2227;
        int32_t sjt_math2228;
        int32_t sjt_math2229;
        int32_t sjt_math2230;
        int32_t sjt_math2231;
        int32_t sjt_math2232;
        sjs_array_char* sjt_parent126 = 0;
        sjs_array_char* sjt_parent127 = 0;
        sjs_string* sjt_parent128 = 0;
        sjs_array_char* sjt_parent131 = 0;
        int32_t sjv_newcount;

        sjt_dot1493 = _parent;
        sjt_parent126 = &sjt_dot1493->data;
        sjt_dot1494 = _parent;
        sjt_math2229 = sjt_dot1494->count;
        sjt_dot1495 = item;
        sjt_math2230 = sjt_dot1495->count;
        sjt_math2227 = sjt_math2229 + sjt_math2230;
        sjt_math2228 = 1;
        sjt_functionParam209 = sjt_math2227 + sjt_math2228;
        sjf_array_char_grow(sjt_parent126, sjt_functionParam209, &sjv_newdata);
        sjt_dot1496 = _parent;
        sjv_newcount = sjt_dot1496->count;
        sjt_parent127 = &sjv_newdata;
        sjt_functionParam210 = sjv_newcount;
        sjt_parent128 = item;
        sjt_functionParam212 = 0;
        sjf_string_getat(sjt_parent128, sjt_functionParam212, &sjt_functionParam211);
        sjf_array_char_setat(sjt_parent127, sjt_functionParam210, sjt_functionParam211);
        sjt_math2231 = sjv_newcount;
        sjt_math2232 = 1;
        sjv_newcount = sjt_math2231 + sjt_math2232;
        sjt_forStart17 = 1;
        sjt_dot1497 = item;
        sjt_forEnd17 = sjt_dot1497->count;
        i = sjt_forStart17;
        while (i < sjt_forEnd17) {
            int32_t sjt_functionParam213;
            char sjt_functionParam214;
            int32_t sjt_functionParam215;
            int32_t sjt_math2233;
            int32_t sjt_math2234;
            sjs_array_char* sjt_parent129 = 0;
            sjs_string* sjt_parent130 = 0;

            sjt_parent129 = &sjv_newdata;
            sjt_functionParam213 = sjv_newcount;
            sjt_parent130 = item;
            sjt_functionParam215 = i;
            sjf_string_getat(sjt_parent130, sjt_functionParam215, &sjt_functionParam214);
            sjf_array_char_initat(sjt_parent129, sjt_functionParam213, sjt_functionParam214);
            sjt_math2233 = sjv_newcount;
            sjt_math2234 = 1;
            sjv_newcount = sjt_math2233 + sjt_math2234;
            i++;
        }

        sjt_parent131 = &sjv_newdata;
        sjt_functionParam216 = sjv_newcount;
        sjt_cast13 = 0;
        sjt_functionParam217 = (char)sjt_cast13;
        sjf_array_char_initat(sjt_parent131, sjt_functionParam216, sjt_functionParam217);
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        sjt_copy33 = &sjv_newdata;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy33);
        sjf_string_heap((*_return));
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    sjs_string* sjt_dot1488 = 0;
    int32_t sjt_functionParam202;
    sjs_array_char* sjt_parent121 = 0;

    sjt_dot1488 = _parent;
    sjt_parent121 = &sjt_dot1488->data;
    sjt_functionParam202 = index;
    sjf_array_char_getat(sjt_parent121, sjt_functionParam202, _return);
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
    sjt_parent1 = &sjt_dot1->data;
    sjt_dot2 = test;
    sjt_functionParam9 = &sjt_dot2->data;
    sjf_array_char_isequal(sjt_parent1, sjt_functionParam9, _return);
}

void sjf_style(sjs_style* _this) {
}

void sjf_style_copy(sjs_style* _this, sjs_style* _from) {
}

void sjf_style_destroy(sjs_style* _this) {
}

void sjf_style_getfont_heap(sjs_style* _parent, sjs_font** _return) {
    sjs_string sjt_call138 = { -1 };
    sjs_string* sjt_functionParam390 = 0;
    float sjt_functionParam391;

    sjt_call138._refCount = 1;
    sjt_call138.count = 16;
    sjt_call138.data._refCount = 1;
    sjt_call138.data.datasize = 17;
    sjt_call138.data.data = (void*)sjg_string27;
    sjt_call138.data._isglobal = true;
    sjt_call138.data.count = 17;
    sjf_array_char(&sjt_call138.data);
    sjf_string(&sjt_call138);
    sjt_functionParam390 = &sjt_call138;
    sjt_functionParam391 = 24.0f;
    sjf_font_load_heap(sjt_functionParam390, sjt_functionParam391, _return);

    if (sjt_call138._refCount == 1) { sjf_string_destroy(&sjt_call138); }
;
}

void sjf_style_heap(sjs_style* _this) {
}

void sjf_testscene_heap(sji_element* _return) {
    sjs_model* object1 = 0;
    float result10;
    sjs_filllayout* sjt_call10 = 0;
    sjs_boxelement* sjt_call11 = 0;
    sjs_string sjt_call128 = { -1 };
    sjs_string sjt_call129 = { -1 };
    sjs_scene3delement* sjt_call13 = 0;
    sjs_textelement* sjt_call130 = 0;
    sjs_model* sjt_call21 = 0;
    sjs_textelement* sjt_cast14 = 0;
    sjs_filllayout* sjt_cast4 = 0;
    sjs_boxelement* sjt_cast5 = 0;
    sjs_scene3delement* sjt_cast6 = 0;
    sjs_model* sjt_cast9 = 0;
    sjs_shader* sjt_copy63 = 0;
    sjs_color* sjt_copy76 = 0;
    int32_t sjt_functionParam138;
    sji_model sjt_functionParam139 = { 0 };
    sjs_string* sjt_functionParam347 = 0;
    sjs_string* sjt_functionParam348 = 0;
    float sjt_functionParam349;
    float sjt_functionParam350;
    float sjt_functionParam351;
    int32_t sjt_functionParam352;
    sji_element sjt_functionParam353 = { 0 };
    int32_t sjt_functionParam57;
    sji_element sjt_functionParam58 = { 0 };
    int32_t sjt_functionParam63;
    sji_element sjt_functionParam64 = { 0 };
    float sjt_negate3;
    sjs_array_heap_iface_element* sjt_parent244 = 0;
    sjs_style* sjt_parent260 = 0;
    sjs_array_heap_iface_element* sjt_parent48 = 0;
    sjs_array_heap_iface_element* sjt_parent53 = 0;
    sjs_array_heap_iface_model* sjt_parent97 = 0;

    sjt_call10 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
    sjt_call10->_refCount = 1;
    sjt_call10->children._refCount = 1;
    sjt_call10->children.datasize = 3;
    sjt_call10->children.data = 0;
    sjt_call10->children._isglobal = false;
    sjt_call10->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call10->children);
    sjs_array_heap_iface_element* array5;
    array5 = &sjt_call10->children;
    sjt_parent48 = array5;
    sjt_functionParam57 = 0;
    sjt_call11 = (sjs_boxelement*)malloc(sizeof(sjs_boxelement));
    sjt_call11->_refCount = 1;
    sjt_call11->color._refCount = 1;
    sjf_f32_random(&sjt_call11->color.r);
    sjf_f32_random(&sjt_call11->color.g);
    sjf_f32_random(&sjt_call11->color.b);
    sjt_call11->color.a = 1.0f;
    sjf_color(&sjt_call11->color);
    sjt_call11->idealsize._refCount = 1;
    sjt_call11->idealsize.w = 0;
    sjt_call11->idealsize.h = 0;
    sjf_size(&sjt_call11->idealsize);
    sjt_call11->rect._refCount = 1;
    sjt_call11->rect.x = 0;
    sjt_call11->rect.y = 0;
    sjt_call11->rect.w = 0;
    sjt_call11->rect.h = 0;
    sjf_rect(&sjt_call11->rect);
    sjt_call11->boxrenderer._refCount = -1;
    sjf_boxelement_heap(sjt_call11);
    sjt_cast5 = sjt_call11;
    sjf_boxelement_as_sji_element(sjt_cast5, &sjt_functionParam58);
    if (sjt_functionParam58._parent != 0) {
        sjt_functionParam58._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent48, sjt_functionParam57, sjt_functionParam58);
    sjt_parent53 = array5;
    sjt_functionParam63 = 1;
    sjt_call13 = (sjs_scene3delement*)malloc(sizeof(sjs_scene3delement));
    sjt_call13->_refCount = 1;
    sjt_call13->children._refCount = 1;
    sjt_call13->children.datasize = 1;
    sjt_call13->children.data = 0;
    sjt_call13->children._isglobal = false;
    sjt_call13->children.count = 0;
    sjf_array_heap_iface_model(&sjt_call13->children);
    sjs_array_heap_iface_model* array6;
    array6 = &sjt_call13->children;
    sjt_parent97 = array6;
    sjt_functionParam138 = 0;
    object1 = (sjs_model*)malloc(sizeof(sjs_model));
    object1->_refCount = 1;
    sjt_call128._refCount = 1;
    sjt_call128.count = 17;
    sjt_call128.data._refCount = 1;
    sjt_call128.data.datasize = 18;
    sjt_call128.data.data = (void*)sjg_string25;
    sjt_call128.data._isglobal = true;
    sjt_call128.data.count = 18;
    sjf_array_char(&sjt_call128.data);
    sjf_string(&sjt_call128);
    sjt_functionParam347 = &sjt_call128;
    sjf_vertexbuffer_loadobj(sjt_functionParam347, &object1->vertexbuffer);
    sjt_copy63 = &sjv_phongtextureshader;
    object1->shader._refCount = 1;
    sjf_shader_copy(&object1->shader, sjt_copy63);
    sjt_call129._refCount = 1;
    sjt_call129.count = 14;
    sjt_call129.data._refCount = 1;
    sjt_call129.data.datasize = 15;
    sjt_call129.data.data = (void*)sjg_string26;
    sjt_call129.data._isglobal = true;
    sjt_call129.data.count = 15;
    sjf_array_char(&sjt_call129.data);
    sjf_string(&sjt_call129);
    sjt_functionParam348 = &sjt_call129;
    sjf_texture_frompng(sjt_functionParam348, &object1->texture);
    sjt_functionParam349 = 0.02f;
    sjt_functionParam350 = 0.02f;
    sjt_functionParam351 = 0.02f;
    sjf_mat4_scale(sjt_functionParam349, sjt_functionParam350, sjt_functionParam351, &object1->model);
    object1->center._refCount = 1;
    object1->center.x = 0.0f;
    object1->center.y = 0.0f;
    object1->center.z = 0.0f;
    sjf_vec3(&object1->center);
    object1->hasalpha = false;
    object1->id._refCount = -1;
    object1->_projection._refCount = 1;
    object1->_projection.m00 = 0.0f;
    object1->_projection.m01 = 0.0f;
    object1->_projection.m02 = 0.0f;
    object1->_projection.m03 = 0.0f;
    object1->_projection.m10 = 0.0f;
    object1->_projection.m11 = 0.0f;
    object1->_projection.m12 = 0.0f;
    object1->_projection.m13 = 0.0f;
    object1->_projection.m20 = 0.0f;
    object1->_projection.m21 = 0.0f;
    object1->_projection.m22 = 0.0f;
    object1->_projection.m23 = 0.0f;
    object1->_projection.m30 = 0.0f;
    object1->_projection.m31 = 0.0f;
    object1->_projection.m32 = 0.0f;
    object1->_projection.m33 = 0.0f;
    sjf_mat4(&object1->_projection);
    object1->_view._refCount = 1;
    object1->_view.m00 = 0.0f;
    object1->_view.m01 = 0.0f;
    object1->_view.m02 = 0.0f;
    object1->_view.m03 = 0.0f;
    object1->_view.m10 = 0.0f;
    object1->_view.m11 = 0.0f;
    object1->_view.m12 = 0.0f;
    object1->_view.m13 = 0.0f;
    object1->_view.m20 = 0.0f;
    object1->_view.m21 = 0.0f;
    object1->_view.m22 = 0.0f;
    object1->_view.m23 = 0.0f;
    object1->_view.m30 = 0.0f;
    object1->_view.m31 = 0.0f;
    object1->_view.m32 = 0.0f;
    object1->_view.m33 = 0.0f;
    sjf_mat4(&object1->_view);
    object1->_world._refCount = 1;
    object1->_world.m00 = 0.0f;
    object1->_world.m01 = 0.0f;
    object1->_world.m02 = 0.0f;
    object1->_world.m03 = 0.0f;
    object1->_world.m10 = 0.0f;
    object1->_world.m11 = 0.0f;
    object1->_world.m12 = 0.0f;
    object1->_world.m13 = 0.0f;
    object1->_world.m20 = 0.0f;
    object1->_world.m21 = 0.0f;
    object1->_world.m22 = 0.0f;
    object1->_world.m23 = 0.0f;
    object1->_world.m30 = 0.0f;
    object1->_world.m31 = 0.0f;
    object1->_world.m32 = 0.0f;
    object1->_world.m33 = 0.0f;
    sjf_mat4(&object1->_world);
    object1->_light._refCount = 1;
    object1->_light.pos._refCount = 1;
    object1->_light.pos.x = 1.0f;
    object1->_light.pos.y = 1.0f;
    object1->_light.pos.z = 1.0f;
    sjf_vec3(&object1->_light.pos);
    object1->_light.diffusecolor._refCount = 1;
    object1->_light.diffusecolor.r = 0.5f;
    object1->_light.diffusecolor.g = 0.5f;
    object1->_light.diffusecolor.b = 0.0f;
    object1->_light.diffusecolor.a = 1.0f;
    sjf_color(&object1->_light.diffusecolor);
    object1->_light.speccolor._refCount = 1;
    object1->_light.speccolor.r = 1.0f;
    object1->_light.speccolor.g = 1.0f;
    object1->_light.speccolor.b = 1.0f;
    object1->_light.speccolor.a = 1.0f;
    sjf_color(&object1->_light.speccolor);
    sjf_light(&object1->_light);
    object1->_projectedcenter._refCount = 1;
    object1->_projectedcenter.x = 0.0f;
    object1->_projectedcenter.y = 0.0f;
    object1->_projectedcenter.z = 0.0f;
    sjf_vec3(&object1->_projectedcenter);
    sjf_model_heap(object1, &sjt_call21);
    sjt_cast9 = sjt_call21;
    sjf_model_as_sji_model(sjt_cast9, &sjt_functionParam139);
    if (sjt_functionParam139._parent != 0) {
        sjt_functionParam139._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent97, sjt_functionParam138, sjt_functionParam139);
    sjt_call13->camera._refCount = 1;
    sjt_call13->camera.x = 0.0f;
    sjt_call13->camera.y = 0.0f;
    sjt_negate3 = 5.0f;
    result10 = -sjt_negate3;
    sjt_call13->camera.z = result10;
    sjf_vec3(&sjt_call13->camera);
    sjt_call13->lookat._refCount = 1;
    sjt_call13->lookat.x = 0.0f;
    sjt_call13->lookat.y = 0.0f;
    sjt_call13->lookat.z = 0.0f;
    sjf_vec3(&sjt_call13->lookat);
    sjt_call13->up._refCount = 1;
    sjt_call13->up.x = 0.0f;
    sjt_call13->up.y = 1.0f;
    sjt_call13->up.z = 0.0f;
    sjf_vec3(&sjt_call13->up);
    sjt_call13->fieldofview = 90.0f;
    sjt_call13->znear = 1.0f;
    sjt_call13->zfar = 100.0f;
    sjt_call13->light._refCount = 1;
    sjt_call13->light.pos._refCount = 1;
    sjt_call13->light.pos.x = 1.0f;
    sjt_call13->light.pos.y = 1.0f;
    sjt_call13->light.pos.z = 1.0f;
    sjf_vec3(&sjt_call13->light.pos);
    sjt_call13->light.diffusecolor._refCount = 1;
    sjt_call13->light.diffusecolor.r = 0.5f;
    sjt_call13->light.diffusecolor.g = 0.5f;
    sjt_call13->light.diffusecolor.b = 0.0f;
    sjt_call13->light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call13->light.diffusecolor);
    sjt_call13->light.speccolor._refCount = 1;
    sjt_call13->light.speccolor.r = 1.0f;
    sjt_call13->light.speccolor.g = 1.0f;
    sjt_call13->light.speccolor.b = 1.0f;
    sjt_call13->light.speccolor.a = 1.0f;
    sjf_color(&sjt_call13->light.speccolor);
    sjf_light(&sjt_call13->light);
    sjt_call13->projection._refCount = 1;
    sjt_call13->projection.m00 = 0.0f;
    sjt_call13->projection.m01 = 0.0f;
    sjt_call13->projection.m02 = 0.0f;
    sjt_call13->projection.m03 = 0.0f;
    sjt_call13->projection.m10 = 0.0f;
    sjt_call13->projection.m11 = 0.0f;
    sjt_call13->projection.m12 = 0.0f;
    sjt_call13->projection.m13 = 0.0f;
    sjt_call13->projection.m20 = 0.0f;
    sjt_call13->projection.m21 = 0.0f;
    sjt_call13->projection.m22 = 0.0f;
    sjt_call13->projection.m23 = 0.0f;
    sjt_call13->projection.m30 = 0.0f;
    sjt_call13->projection.m31 = 0.0f;
    sjt_call13->projection.m32 = 0.0f;
    sjt_call13->projection.m33 = 0.0f;
    sjf_mat4(&sjt_call13->projection);
    sjt_call13->view._refCount = 1;
    sjt_call13->view.m00 = 0.0f;
    sjt_call13->view.m01 = 0.0f;
    sjt_call13->view.m02 = 0.0f;
    sjt_call13->view.m03 = 0.0f;
    sjt_call13->view.m10 = 0.0f;
    sjt_call13->view.m11 = 0.0f;
    sjt_call13->view.m12 = 0.0f;
    sjt_call13->view.m13 = 0.0f;
    sjt_call13->view.m20 = 0.0f;
    sjt_call13->view.m21 = 0.0f;
    sjt_call13->view.m22 = 0.0f;
    sjt_call13->view.m23 = 0.0f;
    sjt_call13->view.m30 = 0.0f;
    sjt_call13->view.m31 = 0.0f;
    sjt_call13->view.m32 = 0.0f;
    sjt_call13->view.m33 = 0.0f;
    sjf_mat4(&sjt_call13->view);
    sjf_mat4_identity(&sjt_call13->world);
    sjt_call13->_rect._refCount = 1;
    sjt_call13->_rect.x = 0;
    sjt_call13->_rect.y = 0;
    sjt_call13->_rect.w = 0;
    sjt_call13->_rect.h = 0;
    sjf_rect(&sjt_call13->_rect);
    sjf_scene3delement_heap(sjt_call13);
    sjt_cast6 = sjt_call13;
    sjf_scene3delement_as_sji_element(sjt_cast6, &sjt_functionParam64);
    if (sjt_functionParam64._parent != 0) {
        sjt_functionParam64._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent53, sjt_functionParam63, sjt_functionParam64);
    sjt_parent244 = array5;
    sjt_functionParam352 = 2;
    sjt_call130 = (sjs_textelement*)malloc(sizeof(sjs_textelement));
    sjt_call130->_refCount = 1;
    sjt_call130->id._refCount = -1;
    sjt_parent260 = &sjv_style;
    sjf_style_getfont_heap(sjt_parent260, &sjt_call130->font);
    sjt_call130->text._refCount = 1;
    sjt_call130->text.count = 5;
    sjt_call130->text.data._refCount = 1;
    sjt_call130->text.data.datasize = 6;
    sjt_call130->text.data.data = (void*)sjg_string31;
    sjt_call130->text.data._isglobal = true;
    sjt_call130->text.data.count = 6;
    sjf_array_char(&sjt_call130->text.data);
    sjf_string(&sjt_call130->text);
    sjt_copy76 = &sjv_colors_white;
    sjt_call130->color._refCount = 1;
    sjf_color_copy(&sjt_call130->color, sjt_copy76);
    sjt_call130->margin._refCount = 1;
    sjt_call130->margin.l = 0;
    sjt_call130->margin.t = 0;
    sjt_call130->margin.r = 0;
    sjt_call130->margin.b = 0;
    sjf_margin(&sjt_call130->margin);
    sjt_call130->halign = sjv_texthorizontal_center;
    sjt_call130->valign = sjv_textvertical_center;
    sjt_call130->idealsize._refCount = -1;
    sjt_call130->_rect._refCount = 1;
    sjt_call130->_rect.x = 0;
    sjt_call130->_rect.y = 0;
    sjt_call130->_rect.w = 0;
    sjt_call130->_rect.h = 0;
    sjf_rect(&sjt_call130->_rect);
    sjt_call130->_textrenderer._refCount = -1;
    sjf_textelement_heap(sjt_call130);
    sjt_cast14 = sjt_call130;
    sjf_textelement_as_sji_element(sjt_cast14, &sjt_functionParam353);
    if (sjt_functionParam353._parent != 0) {
        sjt_functionParam353._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent244, sjt_functionParam352, sjt_functionParam353);
    sjt_call10->margin._refCount = 1;
    sjt_call10->margin.l = 0;
    sjt_call10->margin.t = 0;
    sjt_call10->margin.r = 0;
    sjt_call10->margin.b = 0;
    sjf_margin(&sjt_call10->margin);
    sjt_call10->effect._parent = 0;
    sjt_call10->_rect._refCount = 1;
    sjt_call10->_rect.x = 0;
    sjt_call10->_rect.y = 0;
    sjt_call10->_rect.w = 0;
    sjt_call10->_rect.h = 0;
    sjf_rect(&sjt_call10->_rect);
    sjf_filllayout_heap(sjt_call10);
    sjt_cast4 = sjt_call10;
    sjf_filllayout_as_sji_element(sjt_cast4, &(*_return));
    if ((*_return)._parent != 0) {
        (*_return)._parent->_refCount++;
    }

    object1->_refCount--;
    if (object1->_refCount <= 0) {
        weakptr_release(object1);
        sjf_model_destroy(object1);
        free(object1);
    }
    sjt_call10->_refCount--;
    if (sjt_call10->_refCount <= 0) {
        weakptr_release(sjt_call10);
        sjf_filllayout_destroy(sjt_call10);
        free(sjt_call10);
    }
    sjt_call11->_refCount--;
    if (sjt_call11->_refCount <= 0) {
        weakptr_release(sjt_call11);
        sjf_boxelement_destroy(sjt_call11);
        free(sjt_call11);
    }
    sjt_call13->_refCount--;
    if (sjt_call13->_refCount <= 0) {
        weakptr_release(sjt_call13);
        sjf_scene3delement_destroy(sjt_call13);
        free(sjt_call13);
    }
    sjt_call130->_refCount--;
    if (sjt_call130->_refCount <= 0) {
        weakptr_release(sjt_call130);
        sjf_textelement_destroy(sjt_call130);
        free(sjt_call130);
    }
    sjt_call21->_refCount--;
    if (sjt_call21->_refCount <= 0) {
        weakptr_release(sjt_call21);
        sjf_model_destroy(sjt_call21);
        free(sjt_call21);
    }
    if (sjt_functionParam139._parent != 0) {
        sjt_functionParam139._parent->_refCount--;
        if (sjt_functionParam139._parent->_refCount <= 0) {
            sjt_functionParam139._vtbl->destroy(sjt_functionParam139._parent);
            free(sjt_functionParam139._parent);
        }
    }
    if (sjt_functionParam353._parent != 0) {
        sjt_functionParam353._parent->_refCount--;
        if (sjt_functionParam353._parent->_refCount <= 0) {
            sjt_functionParam353._vtbl->destroy(sjt_functionParam353._parent);
            free(sjt_functionParam353._parent);
        }
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
    if (sjt_call128._refCount == 1) { sjf_string_destroy(&sjt_call128); }
;
    if (sjt_call129._refCount == 1) { sjf_string_destroy(&sjt_call129); }
;
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
    _this->idealsize._refCount = 1;
    sjf_size_copy((_this->idealsize._refCount != -1 ? &_this->idealsize : 0), (_from->idealsize._refCount != -1 ? &_from->idealsize : 0));
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
    (*_return) = true;
}

void sjf_textelement_getrect(sjs_textelement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy64 = 0;
    sjs_textelement* sjt_dot1588 = 0;

    sjt_dot1588 = _parent;
    sjt_copy64 = &sjt_dot1588->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy64);
}

void sjf_textelement_getrect_heap(sjs_textelement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy65 = 0;
    sjs_textelement* sjt_dot1589 = 0;

    sjt_dot1589 = _parent;
    sjt_copy65 = &sjt_dot1589->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy65);
}

void sjf_textelement_getsize(sjs_textelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_textelement* sjt_dot1578 = 0;
    bool sjt_isEmpty13;
    sjs_size* sjt_isEmpty14 = 0;

    sjt_dot1578 = _parent;
    sjt_isEmpty14 = (sjt_dot1578->idealsize._refCount != -1 ? &sjt_dot1578->idealsize : 0);
    sjt_isEmpty13 = (sjt_isEmpty14 != 0);
    if (sjt_isEmpty13) {
        sjs_size* ifValue9 = 0;
        sjs_textelement* sjt_dot1579 = 0;
        sjs_size* sjt_functionParam356 = 0;
        sjs_size* sjt_parent246 = 0;

        sjt_dot1579 = _parent;
        ifValue9 = (sjt_dot1579->idealsize._refCount != -1 ? &sjt_dot1579->idealsize : 0);
        sjt_parent246 = ifValue9;
        sjt_functionParam356 = maxsize;
        sjf_size_min(sjt_parent246, sjt_functionParam356, _return);
    } else {
        sjs_size sjt_call131 = { -1 };
        sjs_textelement* sjt_dot1580 = 0;
        sjs_textelement* sjt_dot1581 = 0;
        sjs_textelement* sjt_dot1582 = 0;
        sjs_string* sjt_functionParam357 = 0;
        sjs_margin* sjt_functionParam358 = 0;
        sjs_size* sjt_functionParam359 = 0;
        sjs_size* sjt_parent247 = 0;
        sjs_font* sjt_parent248 = 0;
        sjs_size* sjt_parent249 = 0;
        sjs_size sjv_textsize = { -1 };

        sjt_dot1580 = _parent;
        sjt_parent248 = sjt_dot1580->font;
        sjt_dot1581 = _parent;
        sjt_functionParam357 = &sjt_dot1581->text;
        sjf_font_gettextsize(sjt_parent248, sjt_functionParam357, &sjt_call131);
        sjt_parent247 = &sjt_call131;
        sjt_dot1582 = _parent;
        sjt_functionParam358 = &sjt_dot1582->margin;
        sjf_size_addmargin(sjt_parent247, sjt_functionParam358, &sjv_textsize);
        sjt_parent249 = &sjv_textsize;
        sjt_functionParam359 = maxsize;
        sjf_size_min(sjt_parent249, sjt_functionParam359, _return);

        if (sjt_call131._refCount == 1) { sjf_size_destroy(&sjt_call131); }
;
        if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
    }
}

void sjf_textelement_getsize_heap(sjs_textelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_textelement* sjt_dot1583 = 0;
    bool sjt_isEmpty15;
    sjs_size* sjt_isEmpty16 = 0;

    sjt_dot1583 = _parent;
    sjt_isEmpty16 = (sjt_dot1583->idealsize._refCount != -1 ? &sjt_dot1583->idealsize : 0);
    sjt_isEmpty15 = (sjt_isEmpty16 != 0);
    if (sjt_isEmpty15) {
        sjs_size* ifValue12 = 0;
        sjs_textelement* sjt_dot1584 = 0;
        sjs_size* sjt_functionParam360 = 0;
        sjs_size* sjt_parent250 = 0;

        sjt_dot1584 = _parent;
        ifValue12 = (sjt_dot1584->idealsize._refCount != -1 ? &sjt_dot1584->idealsize : 0);
        sjt_parent250 = ifValue12;
        sjt_functionParam360 = maxsize;
        sjf_size_min_heap(sjt_parent250, sjt_functionParam360, _return);
    } else {
        sjs_size sjt_call132 = { -1 };
        sjs_textelement* sjt_dot1585 = 0;
        sjs_textelement* sjt_dot1586 = 0;
        sjs_textelement* sjt_dot1587 = 0;
        sjs_string* sjt_functionParam361 = 0;
        sjs_margin* sjt_functionParam362 = 0;
        sjs_size* sjt_functionParam363 = 0;
        sjs_size* sjt_parent251 = 0;
        sjs_font* sjt_parent252 = 0;
        sjs_size* sjt_parent253 = 0;
        sjs_size sjv_textsize = { -1 };

        sjt_dot1585 = _parent;
        sjt_parent252 = sjt_dot1585->font;
        sjt_dot1586 = _parent;
        sjt_functionParam361 = &sjt_dot1586->text;
        sjf_font_gettextsize(sjt_parent252, sjt_functionParam361, &sjt_call132);
        sjt_parent251 = &sjt_call132;
        sjt_dot1587 = _parent;
        sjt_functionParam362 = &sjt_dot1587->margin;
        sjf_size_addmargin(sjt_parent251, sjt_functionParam362, &sjv_textsize);
        sjt_parent253 = &sjv_textsize;
        sjt_functionParam363 = maxsize;
        sjf_size_min_heap(sjt_parent253, sjt_functionParam363, _return);

        if (sjt_call132._refCount == 1) { sjf_size_destroy(&sjt_call132); }
;
        if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
    }
}

void sjf_textelement_gettext(sjs_textelement* _parent, sjs_string* _return) {
    sjs_string* sjt_copy71 = 0;
    sjs_textelement* sjt_dot1623 = 0;

    sjt_dot1623 = _parent;
    sjt_copy71 = &sjt_dot1623->text;
    _return->_refCount = 1;
    sjf_string_copy(_return, sjt_copy71);
}

void sjf_textelement_gettext_heap(sjs_textelement* _parent, sjs_string** _return) {
    sjs_string* sjt_copy72 = 0;
    sjs_textelement* sjt_dot1624 = 0;

    sjt_dot1624 = _parent;
    sjt_copy72 = &sjt_dot1624->text;
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    sjf_string_copy((*_return), sjt_copy72);
}

void sjf_textelement_heap(sjs_textelement* _this) {
    bool sjt_isEmpty11;
    sjs_string* sjt_isEmpty12 = 0;

    sjt_isEmpty12 = (_this->id._refCount != -1 ? &_this->id : 0);
    sjt_isEmpty11 = (sjt_isEmpty12 != 0);
    if (sjt_isEmpty11) {
        sjs_string* ifValue14 = 0;
        sjs_textelement* sjt_cast15 = 0;
        sjs_string* sjt_functionParam354 = 0;
        sji_element sjt_functionParam355 = { 0 };
        sjs_hash_string_weak_iface_element* sjt_parent245 = 0;

        ifValue14 = (_this->id._refCount != -1 ? &_this->id : 0);
        sjt_parent245 = &sjv_elementsbyid;
        sjt_functionParam354 = ifValue14;
        sjt_cast15 = _this;
        sjf_textelement_as_sji_element(sjt_cast15, &sjt_functionParam355);
        delete_cb weakptrcb21 = { &sjt_functionParam355._parent, weakptr_clear };
        if (sjt_functionParam355._parent != 0) { weakptr_cb_add(sjt_functionParam355._parent, weakptrcb21); }
        sjf_hash_string_weak_iface_element_setat(sjt_parent245, sjt_functionParam354, sjt_functionParam355);

        delete_cb weakptrcb30 = { &sjt_functionParam355._parent, weakptr_clear };
        if (sjt_functionParam355._parent != 0) { weakptr_cb_remove(sjt_functionParam355._parent, weakptrcb30); }
    }
}

void sjf_textelement_render(sjs_textelement* _parent, sjs_scene2d* scene) {
    sjs_textrenderer sjt_call133 = { -1 };
    sjs_textelement* sjt_dot1593 = 0;
    sjs_textelement* sjt_dot1618 = 0;
    bool sjt_ifElse49;
    bool sjt_ifElse50;
    sjs_textrenderer* sjt_isEmpty17 = 0;
    sjs_textrenderer* sjt_isEmpty18 = 0;
    sjs_rect sjv_innerrect = { -1 };
    sjs_size sjv_textsize = { -1 };

    sjt_dot1593 = _parent;
    sjt_isEmpty17 = (sjt_dot1593->_textrenderer._refCount != -1 ? &sjt_dot1593->_textrenderer : 0);
    sjt_ifElse49 = (sjt_isEmpty17 == 0);
    if (sjt_ifElse49) {
        int32_t sjt_compare101;
        int32_t sjt_compare102;
        int32_t sjt_compare95;
        int32_t sjt_compare96;
        sjs_textrenderer* sjt_copy67 = 0;
        sjs_string* sjt_copy68 = 0;
        sjs_color* sjt_copy69 = 0;
        sjs_font* sjt_copy70 = 0;
        sjs_textelement* sjt_dot1594 = 0;
        sjs_textelement* sjt_dot1595 = 0;
        sjs_textelement* sjt_dot1596 = 0;
        sjs_textelement* sjt_dot1597 = 0;
        sjs_textelement* sjt_dot1598 = 0;
        sjs_textelement* sjt_dot1606 = 0;
        sjs_textelement* sjt_dot1614 = 0;
        sjs_textelement* sjt_dot1615 = 0;
        sjs_textelement* sjt_dot1616 = 0;
        sjs_textelement* sjt_dot1617 = 0;
        sjs_string* sjt_functionParam365 = 0;
        sjs_margin* sjt_functionParam366 = 0;
        sjs_font* sjt_parent255 = 0;
        sjs_rect* sjt_parent256 = 0;
        bool sjt_switch1;
        bool sjt_switch4;
        int32_t sjv_x;
        int32_t sjv_y;
        int32_t underscore1;
        int32_t underscore2;

        sjt_dot1594 = _parent;
        sjt_parent255 = sjt_dot1594->font;
        sjt_dot1595 = _parent;
        sjt_functionParam365 = &sjt_dot1595->text;
        sjf_font_gettextsize(sjt_parent255, sjt_functionParam365, &sjv_textsize);
        sjt_dot1596 = _parent;
        sjt_parent256 = &sjt_dot1596->_rect;
        sjt_dot1597 = _parent;
        sjt_functionParam366 = &sjt_dot1597->margin;
        sjf_rect_subtractmargin(sjt_parent256, sjt_functionParam366, &sjv_innerrect);
        sjt_dot1598 = _parent;
        underscore1 = sjt_dot1598->halign;
        sjt_compare95 = underscore1;
        sjt_compare96 = sjv_texthorizontal_left;
        sjt_switch1 = sjt_compare95 == sjt_compare96;
        if (sjt_switch1) {
            sjs_rect* sjt_dot1599 = 0;

            sjt_dot1599 = &sjv_innerrect;
            sjv_x = sjt_dot1599->x;
        } else {
            int32_t sjt_compare97;
            int32_t sjt_compare98;
            bool sjt_switch2;

            sjt_compare97 = underscore1;
            sjt_compare98 = sjv_texthorizontal_right;
            sjt_switch2 = sjt_compare97 == sjt_compare98;
            if (sjt_switch2) {
                sjs_rect* sjt_dot1600 = 0;
                sjs_rect* sjt_dot1601 = 0;
                sjs_size* sjt_dot1602 = 0;
                int32_t sjt_math2309;
                int32_t sjt_math2310;
                int32_t sjt_math2311;
                int32_t sjt_math2312;

                sjt_dot1600 = &sjv_innerrect;
                sjt_math2311 = sjt_dot1600->x;
                sjt_dot1601 = &sjv_innerrect;
                sjt_math2312 = sjt_dot1601->w;
                sjt_math2309 = sjt_math2311 + sjt_math2312;
                sjt_dot1602 = &sjv_textsize;
                sjt_math2310 = sjt_dot1602->w;
                sjv_x = sjt_math2309 - sjt_math2310;
            } else {
                int32_t sjt_compare100;
                int32_t sjt_compare99;
                bool sjt_switch3;

                sjt_compare99 = underscore1;
                sjt_compare100 = sjv_texthorizontal_center;
                sjt_switch3 = sjt_compare99 == sjt_compare100;
                if (sjt_switch3) {
                    sjs_rect* sjt_dot1603 = 0;
                    sjs_rect* sjt_dot1604 = 0;
                    sjs_size* sjt_dot1605 = 0;
                    int32_t sjt_math2313;
                    int32_t sjt_math2314;
                    int32_t sjt_math2315;
                    int32_t sjt_math2316;
                    int32_t sjt_math2317;
                    int32_t sjt_math2318;

                    sjt_dot1603 = &sjv_innerrect;
                    sjt_math2313 = sjt_dot1603->x;
                    sjt_dot1604 = &sjv_innerrect;
                    sjt_math2317 = sjt_dot1604->w;
                    sjt_dot1605 = &sjv_textsize;
                    sjt_math2318 = sjt_dot1605->w;
                    sjt_math2315 = sjt_math2317 - sjt_math2318;
                    sjt_math2316 = 2;
                    sjt_math2314 = sjt_math2315 / sjt_math2316;
                    sjv_x = sjt_math2313 + sjt_math2314;
                } else {
                    sjv_x = 0;
                }
            }
        }

        sjt_dot1606 = _parent;
        underscore2 = sjt_dot1606->valign;
        sjt_compare101 = underscore2;
        sjt_compare102 = sjv_textvertical_top;
        sjt_switch4 = sjt_compare101 == sjt_compare102;
        if (sjt_switch4) {
            sjs_rect* sjt_dot1607 = 0;

            sjt_dot1607 = &sjv_innerrect;
            sjv_y = sjt_dot1607->y;
        } else {
            int32_t sjt_compare103;
            int32_t sjt_compare104;
            bool sjt_switch5;

            sjt_compare103 = underscore2;
            sjt_compare104 = sjv_textvertical_bottom;
            sjt_switch5 = sjt_compare103 == sjt_compare104;
            if (sjt_switch5) {
                sjs_rect* sjt_dot1608 = 0;
                sjs_rect* sjt_dot1609 = 0;
                sjs_size* sjt_dot1610 = 0;
                int32_t sjt_math2319;
                int32_t sjt_math2320;
                int32_t sjt_math2321;
                int32_t sjt_math2322;

                sjt_dot1608 = &sjv_innerrect;
                sjt_math2321 = sjt_dot1608->y;
                sjt_dot1609 = &sjv_innerrect;
                sjt_math2322 = sjt_dot1609->h;
                sjt_math2319 = sjt_math2321 + sjt_math2322;
                sjt_dot1610 = &sjv_textsize;
                sjt_math2320 = sjt_dot1610->h;
                sjv_y = sjt_math2319 - sjt_math2320;
            } else {
                int32_t sjt_compare105;
                int32_t sjt_compare106;
                bool sjt_switch6;

                sjt_compare105 = underscore2;
                sjt_compare106 = sjv_textvertical_center;
                sjt_switch6 = sjt_compare105 == sjt_compare106;
                if (sjt_switch6) {
                    sjs_rect* sjt_dot1611 = 0;
                    sjs_rect* sjt_dot1612 = 0;
                    sjs_size* sjt_dot1613 = 0;
                    int32_t sjt_math2323;
                    int32_t sjt_math2324;
                    int32_t sjt_math2325;
                    int32_t sjt_math2326;
                    int32_t sjt_math2327;
                    int32_t sjt_math2328;

                    sjt_dot1611 = &sjv_innerrect;
                    sjt_math2323 = sjt_dot1611->y;
                    sjt_dot1612 = &sjv_innerrect;
                    sjt_math2327 = sjt_dot1612->h;
                    sjt_dot1613 = &sjv_textsize;
                    sjt_math2328 = sjt_dot1613->h;
                    sjt_math2325 = sjt_math2327 - sjt_math2328;
                    sjt_math2326 = 2;
                    sjt_math2324 = sjt_math2325 / sjt_math2326;
                    sjv_y = sjt_math2323 + sjt_math2324;
                } else {
                    sjv_y = 0;
                }
            }
        }

        sjt_dot1614 = _parent;
        sjt_call133._refCount = 1;
        sjt_dot1615 = _parent;
        sjt_copy68 = &sjt_dot1615->text;
        sjt_call133.text._refCount = 1;
        sjf_string_copy(&sjt_call133.text, sjt_copy68);
        sjt_call133.point._refCount = 1;
        sjt_call133.point.x = sjv_x;
        sjt_call133.point.y = sjv_y;
        sjf_point(&sjt_call133.point);
        sjt_dot1616 = _parent;
        sjt_copy69 = &sjt_dot1616->color;
        sjt_call133.color._refCount = 1;
        sjf_color_copy(&sjt_call133.color, sjt_copy69);
        sjt_dot1617 = _parent;
        sjt_copy70 = sjt_dot1617->font;
        sjt_call133.font._refCount = 1;
        sjf_font_copy(&sjt_call133.font, sjt_copy70);
        sjf_textrenderer(&sjt_call133);
        sjt_copy67 = &sjt_call133;
        if (sjt_dot1614->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&sjt_dot1614->_textrenderer); }
;
        sjt_dot1614->_textrenderer._refCount = 1;
        sjf_textrenderer_copy(&sjt_dot1614->_textrenderer, sjt_copy67);
    }

    sjt_dot1618 = _parent;
    sjt_isEmpty18 = (sjt_dot1618->_textrenderer._refCount != -1 ? &sjt_dot1618->_textrenderer : 0);
    sjt_ifElse50 = (sjt_isEmpty18 != 0);
    if (sjt_ifElse50) {
        sjs_textelement* sjt_dot1622 = 0;
        sjs_scene2d* sjt_functionParam386 = 0;
        sjs_textrenderer* sjt_parent257 = 0;

        sjt_dot1622 = _parent;
        sjt_parent257 = (sjt_dot1622->_textrenderer._refCount != -1 ? &sjt_dot1622->_textrenderer : 0);
        sjt_functionParam386 = scene;
        sjf_textrenderer_render(sjt_parent257, sjt_functionParam386);
    }

    if (sjt_call133._refCount == 1) { sjf_textrenderer_destroy(&sjt_call133); }
;
    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
;
    if (sjv_textsize._refCount == 1) { sjf_size_destroy(&sjv_textsize); }
;
}

void sjf_textelement_setrect(sjs_textelement* _parent, sjs_rect* rect_) {
    bool result11;
    sjs_textelement* sjt_dot1590 = 0;
    sjs_rect* sjt_functionParam364 = 0;
    bool sjt_ifElse48;
    bool sjt_not8;
    sjs_rect* sjt_parent254 = 0;

    sjt_dot1590 = _parent;
    sjt_parent254 = &sjt_dot1590->_rect;
    sjt_functionParam364 = rect_;
    sjf_rect_isequal(sjt_parent254, sjt_functionParam364, &sjt_not8);
    result11 = !sjt_not8;
    sjt_ifElse48 = result11;
    if (sjt_ifElse48) {
        sjs_rect* sjt_copy66 = 0;
        sjs_textelement* sjt_dot1591 = 0;
        sjs_textelement* sjt_dot1592 = 0;

        sjt_dot1591 = _parent;
        sjt_copy66 = rect_;
        if (sjt_dot1591->_rect._refCount == 1) { sjf_rect_destroy(&sjt_dot1591->_rect); }
;
        sjt_dot1591->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1591->_rect, sjt_copy66);
        sjt_dot1592 = _parent;
        if (sjt_dot1592->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&sjt_dot1592->_textrenderer); }
;
        sjt_dot1592->_textrenderer._refCount = -1;
    }
}

void sjf_textelement_settext(sjs_textelement* _parent, sjs_string* text_) {
    sjs_string* sjt_copy73 = 0;
    sjs_textelement* sjt_dot1625 = 0;
    sjs_textelement* sjt_dot1626 = 0;

    sjt_dot1625 = _parent;
    sjt_copy73 = text_;
    if (sjt_dot1625->text._refCount == 1) { sjf_string_destroy(&sjt_dot1625->text); }
;
    sjt_dot1625->text._refCount = 1;
    sjf_string_copy(&sjt_dot1625->text, sjt_copy73);
    sjt_dot1626 = _parent;
    if (sjt_dot1626->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&sjt_dot1626->_textrenderer); }
;
    sjt_dot1626->_textrenderer._refCount = -1;
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
    add_text(_this->buffer, _this->font.font, (char*)_this->text.data.data, &color, &pen);
    glBindTexture(GL_TEXTURE_2D, _this->font.font->atlas->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)_this->font.font->atlas->width, (int)_this->font.font->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->font.font->atlas->data );
}

void sjf_textrenderer_render(sjs_textrenderer* _parent, sjs_scene2d* scene) {
    sjs_string sjt_call134 = { -1 };
    sjs_string sjt_call135 = { -1 };
    sjs_string sjt_call136 = { -1 };
    sjs_string sjt_call137 = { -1 };
    sjs_scene2d* sjt_dot1619 = 0;
    sjs_scene2d* sjt_dot1620 = 0;
    sjs_scene2d* sjt_dot1621 = 0;
    sjs_shader* sjt_functionParam367 = 0;
    int32_t sjt_functionParam368;
    int32_t sjt_functionParam369;
    int32_t sjt_functionParam370;
    sjs_shader* sjt_functionParam371 = 0;
    sjs_string* sjt_functionParam372 = 0;
    int32_t sjt_functionParam373;
    int32_t sjt_functionParam374;
    sjs_shader* sjt_functionParam375 = 0;
    sjs_string* sjt_functionParam376 = 0;
    sjs_mat4* sjt_functionParam377 = 0;
    int32_t sjt_functionParam378;
    sjs_shader* sjt_functionParam379 = 0;
    sjs_string* sjt_functionParam380 = 0;
    sjs_mat4* sjt_functionParam381 = 0;
    int32_t sjt_functionParam382;
    sjs_shader* sjt_functionParam383 = 0;
    sjs_string* sjt_functionParam384 = 0;
    sjs_mat4* sjt_functionParam385 = 0;

    glBindTexture(GL_TEXTURE_2D, _parent->font.atlas->id);
    sjt_functionParam367 = &sjv_textshader;
    sjf_gluseprogram(sjt_functionParam367);
    sjt_functionParam368 = sjv_glblendfunctype_gl_src_alpha;
    sjt_functionParam369 = sjv_glblendfunctype_gl_one_minus_src_alpha;
    sjf_glblendfunc(sjt_functionParam368, sjt_functionParam369);
    sjt_functionParam371 = &sjv_textshader;
    sjt_call134._refCount = 1;
    sjt_call134.count = 7;
    sjt_call134.data._refCount = 1;
    sjt_call134.data.datasize = 8;
    sjt_call134.data.data = (void*)sjg_string28;
    sjt_call134.data._isglobal = true;
    sjt_call134.data.count = 8;
    sjf_array_char(&sjt_call134.data);
    sjf_string(&sjt_call134);
    sjt_functionParam372 = &sjt_call134;
    sjf_glgetuniformlocation(sjt_functionParam371, sjt_functionParam372, &sjt_functionParam370);
    sjt_functionParam373 = 0;
    sjf_gluniformi32(sjt_functionParam370, sjt_functionParam373);
    sjt_functionParam375 = &sjv_textshader;
    sjt_call135._refCount = 1;
    sjt_call135.count = 5;
    sjt_call135.data._refCount = 1;
    sjt_call135.data.datasize = 6;
    sjt_call135.data.data = (void*)sjg_string29;
    sjt_call135.data._isglobal = true;
    sjt_call135.data.count = 6;
    sjf_array_char(&sjt_call135.data);
    sjf_string(&sjt_call135);
    sjt_functionParam376 = &sjt_call135;
    sjf_glgetuniformlocation(sjt_functionParam375, sjt_functionParam376, &sjt_functionParam374);
    sjt_dot1619 = scene;
    sjt_functionParam377 = &sjt_dot1619->model;
    sjf_gluniformmat4(sjt_functionParam374, sjt_functionParam377);
    sjt_functionParam379 = &sjv_textshader;
    sjt_call136._refCount = 1;
    sjt_call136.count = 4;
    sjt_call136.data._refCount = 1;
    sjt_call136.data.datasize = 5;
    sjt_call136.data.data = (void*)sjg_string30;
    sjt_call136.data._isglobal = true;
    sjt_call136.data.count = 5;
    sjf_array_char(&sjt_call136.data);
    sjf_string(&sjt_call136);
    sjt_functionParam380 = &sjt_call136;
    sjf_glgetuniformlocation(sjt_functionParam379, sjt_functionParam380, &sjt_functionParam378);
    sjt_dot1620 = scene;
    sjt_functionParam381 = &sjt_dot1620->view;
    sjf_gluniformmat4(sjt_functionParam378, sjt_functionParam381);
    sjt_functionParam383 = &sjv_textshader;
    sjt_call137._refCount = 1;
    sjt_call137.count = 10;
    sjt_call137.data._refCount = 1;
    sjt_call137.data.datasize = 11;
    sjt_call137.data.data = (void*)sjg_string19;
    sjt_call137.data._isglobal = true;
    sjt_call137.data.count = 11;
    sjf_array_char(&sjt_call137.data);
    sjf_string(&sjt_call137);
    sjt_functionParam384 = &sjt_call137;
    sjf_glgetuniformlocation(sjt_functionParam383, sjt_functionParam384, &sjt_functionParam382);
    sjt_dot1621 = scene;
    sjt_functionParam385 = &sjt_dot1621->projection;
    sjf_gluniformmat4(sjt_functionParam382, sjt_functionParam385);
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);

    if (sjt_call134._refCount == 1) { sjf_string_destroy(&sjt_call134); }
;
    if (sjt_call135._refCount == 1) { sjf_string_destroy(&sjt_call135); }
;
    if (sjt_call136._refCount == 1) { sjf_string_destroy(&sjt_call136); }
;
    if (sjt_call137._refCount == 1) { sjf_string_destroy(&sjt_call137); }
;
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
    if (_this->size._refCount == 1) { sjf_size_destroy(&_this->size); }
;
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

void sjf_texture_heap(sjs_texture* _this) {
}

void sjf_vec2(sjs_vec2* _this) {
}

void sjf_vec2_asstring(sjs_vec2* _parent, sjs_string* _return) {
    sjs_string sjt_call62 = { -1 };
    sjs_string sjt_call63 = { -1 };
    sjs_string sjt_call64 = { -1 };
    sjs_string sjt_call65 = { -1 };
    sjs_vec2* sjt_dot1504 = 0;
    sjs_vec2* sjt_dot1505 = 0;
    float sjt_functionParam236;
    sjs_string* sjt_functionParam237 = 0;
    sjs_string* sjt_functionParam238 = 0;
    float sjt_functionParam239;
    sjs_string* sjt_parent146 = 0;
    sjs_string* sjt_parent147 = 0;

    sjt_dot1504 = _parent;
    sjt_functionParam236 = sjt_dot1504->x;
    sjf_f32_asstring(sjt_functionParam236, &sjt_call63);
    sjt_parent147 = &sjt_call63;
    sjt_call64._refCount = 1;
    sjt_call64.count = 2;
    sjt_call64.data._refCount = 1;
    sjt_call64.data.datasize = 3;
    sjt_call64.data.data = (void*)sjg_string23;
    sjt_call64.data._isglobal = true;
    sjt_call64.data.count = 3;
    sjf_array_char(&sjt_call64.data);
    sjf_string(&sjt_call64);
    sjt_functionParam237 = &sjt_call64;
    sjf_string_add(sjt_parent147, sjt_functionParam237, &sjt_call62);
    sjt_parent146 = &sjt_call62;
    sjt_dot1505 = _parent;
    sjt_functionParam239 = sjt_dot1505->y;
    sjf_f32_asstring(sjt_functionParam239, &sjt_call65);
    sjt_functionParam238 = &sjt_call65;
    sjf_string_add(sjt_parent146, sjt_functionParam238, _return);

    if (sjt_call62._refCount == 1) { sjf_string_destroy(&sjt_call62); }
;
    if (sjt_call63._refCount == 1) { sjf_string_destroy(&sjt_call63); }
;
    if (sjt_call64._refCount == 1) { sjf_string_destroy(&sjt_call64); }
;
    if (sjt_call65._refCount == 1) { sjf_string_destroy(&sjt_call65); }
;
}

void sjf_vec2_asstring_heap(sjs_vec2* _parent, sjs_string** _return) {
    sjs_string sjt_call66 = { -1 };
    sjs_string sjt_call67 = { -1 };
    sjs_string sjt_call68 = { -1 };
    sjs_string sjt_call69 = { -1 };
    sjs_vec2* sjt_dot1506 = 0;
    sjs_vec2* sjt_dot1507 = 0;
    float sjt_functionParam240;
    sjs_string* sjt_functionParam241 = 0;
    sjs_string* sjt_functionParam242 = 0;
    float sjt_functionParam243;
    sjs_string* sjt_parent148 = 0;
    sjs_string* sjt_parent149 = 0;

    sjt_dot1506 = _parent;
    sjt_functionParam240 = sjt_dot1506->x;
    sjf_f32_asstring(sjt_functionParam240, &sjt_call67);
    sjt_parent149 = &sjt_call67;
    sjt_call68._refCount = 1;
    sjt_call68.count = 2;
    sjt_call68.data._refCount = 1;
    sjt_call68.data.datasize = 3;
    sjt_call68.data.data = (void*)sjg_string23;
    sjt_call68.data._isglobal = true;
    sjt_call68.data.count = 3;
    sjf_array_char(&sjt_call68.data);
    sjf_string(&sjt_call68);
    sjt_functionParam241 = &sjt_call68;
    sjf_string_add(sjt_parent149, sjt_functionParam241, &sjt_call66);
    sjt_parent148 = &sjt_call66;
    sjt_dot1507 = _parent;
    sjt_functionParam243 = sjt_dot1507->y;
    sjf_f32_asstring(sjt_functionParam243, &sjt_call69);
    sjt_functionParam242 = &sjt_call69;
    sjf_string_add_heap(sjt_parent148, sjt_functionParam242, _return);

    if (sjt_call66._refCount == 1) { sjf_string_destroy(&sjt_call66); }
;
    if (sjt_call67._refCount == 1) { sjf_string_destroy(&sjt_call67); }
;
    if (sjt_call68._refCount == 1) { sjf_string_destroy(&sjt_call68); }
;
    if (sjt_call69._refCount == 1) { sjf_string_destroy(&sjt_call69); }
;
}

void sjf_vec2_copy(sjs_vec2* _this, sjs_vec2* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
}

void sjf_vec2_destroy(sjs_vec2* _this) {
}

void sjf_vec2_getrawsize(int32_t* _return) {
    int x = sizeof(float) * 2;
    (*_return) = x;
return;;
}

void sjf_vec2_heap(sjs_vec2* _this) {
}

void sjf_vec2_rawcopy(sjs_vec2* v, void* p, void** _return) {
    float* f = (float*)p;
    *f = v->x;
    f++;
    *f = v->y;
    f++;
    (*_return) = (void*)f;
return;;
}

void sjf_vec3(sjs_vec3* _this) {
}

void sjf_vec3_add(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    sjs_vec3* sjt_dot1530 = 0;
    sjs_vec3* sjt_dot1531 = 0;
    sjs_vec3* sjt_dot1532 = 0;
    sjs_vec3* sjt_dot1533 = 0;
    sjs_vec3* sjt_dot1534 = 0;
    sjs_vec3* sjt_dot1535 = 0;
    float sjt_math2259;
    float sjt_math2260;
    float sjt_math2261;
    float sjt_math2262;
    float sjt_math2263;
    float sjt_math2264;

    _return->_refCount = 1;
    sjt_dot1530 = _parent;
    sjt_math2259 = sjt_dot1530->x;
    sjt_dot1531 = v;
    sjt_math2260 = sjt_dot1531->x;
    _return->x = sjt_math2259 + sjt_math2260;
    sjt_dot1532 = _parent;
    sjt_math2261 = sjt_dot1532->y;
    sjt_dot1533 = v;
    sjt_math2262 = sjt_dot1533->y;
    _return->y = sjt_math2261 + sjt_math2262;
    sjt_dot1534 = _parent;
    sjt_math2263 = sjt_dot1534->z;
    sjt_dot1535 = v;
    sjt_math2264 = sjt_dot1535->z;
    _return->z = sjt_math2263 + sjt_math2264;
    sjf_vec3(_return);
}

void sjf_vec3_add_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    sjs_vec3* sjt_dot1536 = 0;
    sjs_vec3* sjt_dot1537 = 0;
    sjs_vec3* sjt_dot1538 = 0;
    sjs_vec3* sjt_dot1539 = 0;
    sjs_vec3* sjt_dot1540 = 0;
    sjs_vec3* sjt_dot1541 = 0;
    float sjt_math2265;
    float sjt_math2266;
    float sjt_math2267;
    float sjt_math2268;
    float sjt_math2269;
    float sjt_math2270;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot1536 = _parent;
    sjt_math2265 = sjt_dot1536->x;
    sjt_dot1537 = v;
    sjt_math2266 = sjt_dot1537->x;
    (*_return)->x = sjt_math2265 + sjt_math2266;
    sjt_dot1538 = _parent;
    sjt_math2267 = sjt_dot1538->y;
    sjt_dot1539 = v;
    sjt_math2268 = sjt_dot1539->y;
    (*_return)->y = sjt_math2267 + sjt_math2268;
    sjt_dot1540 = _parent;
    sjt_math2269 = sjt_dot1540->z;
    sjt_dot1541 = v;
    sjt_math2270 = sjt_dot1541->z;
    (*_return)->z = sjt_math2269 + sjt_math2270;
    sjf_vec3_heap((*_return));
}

void sjf_vec3_asstring(sjs_vec3* _parent, sjs_string* _return) {
    sjs_string sjt_call42 = { -1 };
    sjs_string sjt_call43 = { -1 };
    sjs_string sjt_call44 = { -1 };
    sjs_string sjt_call45 = { -1 };
    sjs_string sjt_call46 = { -1 };
    sjs_string sjt_call47 = { -1 };
    sjs_string sjt_call48 = { -1 };
    sjs_string sjt_call49 = { -1 };
    sjs_vec3* sjt_dot1498 = 0;
    sjs_vec3* sjt_dot1499 = 0;
    sjs_vec3* sjt_dot1500 = 0;
    float sjt_functionParam218;
    sjs_string* sjt_functionParam219 = 0;
    sjs_string* sjt_functionParam220 = 0;
    float sjt_functionParam221;
    sjs_string* sjt_functionParam222 = 0;
    sjs_string* sjt_functionParam223 = 0;
    float sjt_functionParam224;
    sjs_string* sjt_parent136 = 0;
    sjs_string* sjt_parent137 = 0;
    sjs_string* sjt_parent138 = 0;
    sjs_string* sjt_parent139 = 0;

    sjt_dot1498 = _parent;
    sjt_functionParam218 = sjt_dot1498->x;
    sjf_f32_asstring(sjt_functionParam218, &sjt_call45);
    sjt_parent139 = &sjt_call45;
    sjt_call46._refCount = 1;
    sjt_call46.count = 2;
    sjt_call46.data._refCount = 1;
    sjt_call46.data.datasize = 3;
    sjt_call46.data.data = (void*)sjg_string23;
    sjt_call46.data._isglobal = true;
    sjt_call46.data.count = 3;
    sjf_array_char(&sjt_call46.data);
    sjf_string(&sjt_call46);
    sjt_functionParam219 = &sjt_call46;
    sjf_string_add(sjt_parent139, sjt_functionParam219, &sjt_call44);
    sjt_parent138 = &sjt_call44;
    sjt_dot1499 = _parent;
    sjt_functionParam221 = sjt_dot1499->y;
    sjf_f32_asstring(sjt_functionParam221, &sjt_call47);
    sjt_functionParam220 = &sjt_call47;
    sjf_string_add(sjt_parent138, sjt_functionParam220, &sjt_call43);
    sjt_parent137 = &sjt_call43;
    sjt_call48._refCount = 1;
    sjt_call48.count = 2;
    sjt_call48.data._refCount = 1;
    sjt_call48.data.datasize = 3;
    sjt_call48.data.data = (void*)sjg_string23;
    sjt_call48.data._isglobal = true;
    sjt_call48.data.count = 3;
    sjf_array_char(&sjt_call48.data);
    sjf_string(&sjt_call48);
    sjt_functionParam222 = &sjt_call48;
    sjf_string_add(sjt_parent137, sjt_functionParam222, &sjt_call42);
    sjt_parent136 = &sjt_call42;
    sjt_dot1500 = _parent;
    sjt_functionParam224 = sjt_dot1500->z;
    sjf_f32_asstring(sjt_functionParam224, &sjt_call49);
    sjt_functionParam223 = &sjt_call49;
    sjf_string_add(sjt_parent136, sjt_functionParam223, _return);

    if (sjt_call42._refCount == 1) { sjf_string_destroy(&sjt_call42); }
;
    if (sjt_call43._refCount == 1) { sjf_string_destroy(&sjt_call43); }
;
    if (sjt_call44._refCount == 1) { sjf_string_destroy(&sjt_call44); }
;
    if (sjt_call45._refCount == 1) { sjf_string_destroy(&sjt_call45); }
;
    if (sjt_call46._refCount == 1) { sjf_string_destroy(&sjt_call46); }
;
    if (sjt_call47._refCount == 1) { sjf_string_destroy(&sjt_call47); }
;
    if (sjt_call48._refCount == 1) { sjf_string_destroy(&sjt_call48); }
;
    if (sjt_call49._refCount == 1) { sjf_string_destroy(&sjt_call49); }
;
}

void sjf_vec3_asstring_heap(sjs_vec3* _parent, sjs_string** _return) {
    sjs_string sjt_call50 = { -1 };
    sjs_string sjt_call51 = { -1 };
    sjs_string sjt_call52 = { -1 };
    sjs_string sjt_call53 = { -1 };
    sjs_string sjt_call54 = { -1 };
    sjs_string sjt_call55 = { -1 };
    sjs_string sjt_call56 = { -1 };
    sjs_string sjt_call57 = { -1 };
    sjs_vec3* sjt_dot1501 = 0;
    sjs_vec3* sjt_dot1502 = 0;
    sjs_vec3* sjt_dot1503 = 0;
    float sjt_functionParam225;
    sjs_string* sjt_functionParam226 = 0;
    sjs_string* sjt_functionParam227 = 0;
    float sjt_functionParam228;
    sjs_string* sjt_functionParam229 = 0;
    sjs_string* sjt_functionParam230 = 0;
    float sjt_functionParam231;
    sjs_string* sjt_parent140 = 0;
    sjs_string* sjt_parent141 = 0;
    sjs_string* sjt_parent142 = 0;
    sjs_string* sjt_parent143 = 0;

    sjt_dot1501 = _parent;
    sjt_functionParam225 = sjt_dot1501->x;
    sjf_f32_asstring(sjt_functionParam225, &sjt_call53);
    sjt_parent143 = &sjt_call53;
    sjt_call54._refCount = 1;
    sjt_call54.count = 2;
    sjt_call54.data._refCount = 1;
    sjt_call54.data.datasize = 3;
    sjt_call54.data.data = (void*)sjg_string23;
    sjt_call54.data._isglobal = true;
    sjt_call54.data.count = 3;
    sjf_array_char(&sjt_call54.data);
    sjf_string(&sjt_call54);
    sjt_functionParam226 = &sjt_call54;
    sjf_string_add(sjt_parent143, sjt_functionParam226, &sjt_call52);
    sjt_parent142 = &sjt_call52;
    sjt_dot1502 = _parent;
    sjt_functionParam228 = sjt_dot1502->y;
    sjf_f32_asstring(sjt_functionParam228, &sjt_call55);
    sjt_functionParam227 = &sjt_call55;
    sjf_string_add(sjt_parent142, sjt_functionParam227, &sjt_call51);
    sjt_parent141 = &sjt_call51;
    sjt_call56._refCount = 1;
    sjt_call56.count = 2;
    sjt_call56.data._refCount = 1;
    sjt_call56.data.datasize = 3;
    sjt_call56.data.data = (void*)sjg_string23;
    sjt_call56.data._isglobal = true;
    sjt_call56.data.count = 3;
    sjf_array_char(&sjt_call56.data);
    sjf_string(&sjt_call56);
    sjt_functionParam229 = &sjt_call56;
    sjf_string_add(sjt_parent141, sjt_functionParam229, &sjt_call50);
    sjt_parent140 = &sjt_call50;
    sjt_dot1503 = _parent;
    sjt_functionParam231 = sjt_dot1503->z;
    sjf_f32_asstring(sjt_functionParam231, &sjt_call57);
    sjt_functionParam230 = &sjt_call57;
    sjf_string_add_heap(sjt_parent140, sjt_functionParam230, _return);

    if (sjt_call50._refCount == 1) { sjf_string_destroy(&sjt_call50); }
;
    if (sjt_call51._refCount == 1) { sjf_string_destroy(&sjt_call51); }
;
    if (sjt_call52._refCount == 1) { sjf_string_destroy(&sjt_call52); }
;
    if (sjt_call53._refCount == 1) { sjf_string_destroy(&sjt_call53); }
;
    if (sjt_call54._refCount == 1) { sjf_string_destroy(&sjt_call54); }
;
    if (sjt_call55._refCount == 1) { sjf_string_destroy(&sjt_call55); }
;
    if (sjt_call56._refCount == 1) { sjf_string_destroy(&sjt_call56); }
;
    if (sjt_call57._refCount == 1) { sjf_string_destroy(&sjt_call57); }
;
}

void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
    _this->z = _from->z;
}

void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    sjs_vec3* sjt_dot235 = 0;
    sjs_vec3* sjt_dot236 = 0;
    sjs_vec3* sjt_dot237 = 0;
    sjs_vec3* sjt_dot238 = 0;
    sjs_vec3* sjt_dot239 = 0;
    sjs_vec3* sjt_dot240 = 0;
    sjs_vec3* sjt_dot241 = 0;
    sjs_vec3* sjt_dot242 = 0;
    sjs_vec3* sjt_dot243 = 0;
    sjs_vec3* sjt_dot244 = 0;
    sjs_vec3* sjt_dot245 = 0;
    sjs_vec3* sjt_dot246 = 0;
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

    _return->_refCount = 1;
    sjt_dot235 = _parent;
    sjt_math213 = sjt_dot235->y;
    sjt_dot236 = v;
    sjt_math214 = sjt_dot236->z;
    sjt_math211 = sjt_math213 * sjt_math214;
    sjt_dot237 = _parent;
    sjt_math215 = sjt_dot237->z;
    sjt_dot238 = v;
    sjt_math216 = sjt_dot238->y;
    sjt_math212 = sjt_math215 * sjt_math216;
    _return->x = sjt_math211 - sjt_math212;
    sjt_dot239 = _parent;
    sjt_math219 = sjt_dot239->z;
    sjt_dot240 = v;
    sjt_math220 = sjt_dot240->x;
    sjt_math217 = sjt_math219 * sjt_math220;
    sjt_dot241 = _parent;
    sjt_math221 = sjt_dot241->x;
    sjt_dot242 = v;
    sjt_math222 = sjt_dot242->z;
    sjt_math218 = sjt_math221 * sjt_math222;
    _return->y = sjt_math217 - sjt_math218;
    sjt_dot243 = _parent;
    sjt_math225 = sjt_dot243->x;
    sjt_dot244 = v;
    sjt_math226 = sjt_dot244->y;
    sjt_math223 = sjt_math225 * sjt_math226;
    sjt_dot245 = _parent;
    sjt_math227 = sjt_dot245->y;
    sjt_dot246 = v;
    sjt_math228 = sjt_dot246->x;
    sjt_math224 = sjt_math227 * sjt_math228;
    _return->z = sjt_math223 - sjt_math224;
    sjf_vec3(_return);
}

void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    sjs_vec3* sjt_dot247 = 0;
    sjs_vec3* sjt_dot248 = 0;
    sjs_vec3* sjt_dot249 = 0;
    sjs_vec3* sjt_dot250 = 0;
    sjs_vec3* sjt_dot251 = 0;
    sjs_vec3* sjt_dot252 = 0;
    sjs_vec3* sjt_dot253 = 0;
    sjs_vec3* sjt_dot254 = 0;
    sjs_vec3* sjt_dot255 = 0;
    sjs_vec3* sjt_dot256 = 0;
    sjs_vec3* sjt_dot257 = 0;
    sjs_vec3* sjt_dot258 = 0;
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
    float sjt_math243;
    float sjt_math244;
    float sjt_math245;
    float sjt_math246;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot247 = _parent;
    sjt_math231 = sjt_dot247->y;
    sjt_dot248 = v;
    sjt_math232 = sjt_dot248->z;
    sjt_math229 = sjt_math231 * sjt_math232;
    sjt_dot249 = _parent;
    sjt_math233 = sjt_dot249->z;
    sjt_dot250 = v;
    sjt_math234 = sjt_dot250->y;
    sjt_math230 = sjt_math233 * sjt_math234;
    (*_return)->x = sjt_math229 - sjt_math230;
    sjt_dot251 = _parent;
    sjt_math237 = sjt_dot251->z;
    sjt_dot252 = v;
    sjt_math238 = sjt_dot252->x;
    sjt_math235 = sjt_math237 * sjt_math238;
    sjt_dot253 = _parent;
    sjt_math239 = sjt_dot253->x;
    sjt_dot254 = v;
    sjt_math240 = sjt_dot254->z;
    sjt_math236 = sjt_math239 * sjt_math240;
    (*_return)->y = sjt_math235 - sjt_math236;
    sjt_dot255 = _parent;
    sjt_math243 = sjt_dot255->x;
    sjt_dot256 = v;
    sjt_math244 = sjt_dot256->y;
    sjt_math241 = sjt_math243 * sjt_math244;
    sjt_dot257 = _parent;
    sjt_math245 = sjt_dot257->y;
    sjt_dot258 = v;
    sjt_math246 = sjt_dot258->x;
    sjt_math242 = sjt_math245 * sjt_math246;
    (*_return)->z = sjt_math241 - sjt_math242;
    sjf_vec3_heap((*_return));
}

void sjf_vec3_destroy(sjs_vec3* _this) {
}

void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return) {
    sjs_vec3* sjt_dot268 = 0;
    sjs_vec3* sjt_dot269 = 0;
    sjs_vec3* sjt_dot270 = 0;
    sjs_vec3* sjt_dot271 = 0;
    sjs_vec3* sjt_dot272 = 0;
    sjs_vec3* sjt_dot273 = 0;
    float sjt_math249;
    float sjt_math250;
    float sjt_math251;
    float sjt_math252;
    float sjt_math253;
    float sjt_math254;
    float sjt_math255;
    float sjt_math256;
    float sjt_math257;
    float sjt_math258;

    sjt_dot268 = _parent;
    sjt_math253 = sjt_dot268->x;
    sjt_dot269 = v;
    sjt_math254 = sjt_dot269->x;
    sjt_math251 = sjt_math253 * sjt_math254;
    sjt_dot270 = _parent;
    sjt_math255 = sjt_dot270->y;
    sjt_dot271 = v;
    sjt_math256 = sjt_dot271->y;
    sjt_math252 = sjt_math255 * sjt_math256;
    sjt_math249 = sjt_math251 + sjt_math252;
    sjt_dot272 = _parent;
    sjt_math257 = sjt_dot272->z;
    sjt_dot273 = v;
    sjt_math258 = sjt_dot273->z;
    sjt_math250 = sjt_math257 * sjt_math258;
    (*_return) = sjt_math249 + sjt_math250;
}

void sjf_vec3_getrawsize(int32_t* _return) {
    int x = sizeof(float) * 3;
    (*_return) = x;
return;;
}

void sjf_vec3_heap(sjs_vec3* _this) {
}

void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return) {
    sjs_vec3* sjt_dot217 = 0;
    sjs_vec3* sjt_dot218 = 0;
    sjs_vec3* sjt_dot219 = 0;
    sjs_vec3* sjt_dot220 = 0;
    sjs_vec3* sjt_dot221 = 0;
    sjs_vec3* sjt_dot222 = 0;
    sjs_vec3* sjt_dot223 = 0;
    sjs_vec3* sjt_dot224 = 0;
    sjs_vec3* sjt_dot225 = 0;
    float sjt_functionParam73;
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
    float sjv_t;

    sjt_dot217 = _parent;
    sjt_math183 = sjt_dot217->x;
    sjt_dot218 = _parent;
    sjt_math184 = sjt_dot218->x;
    sjt_math181 = sjt_math183 * sjt_math184;
    sjt_dot219 = _parent;
    sjt_math185 = sjt_dot219->y;
    sjt_dot220 = _parent;
    sjt_math186 = sjt_dot220->y;
    sjt_math182 = sjt_math185 * sjt_math186;
    sjt_math179 = sjt_math181 + sjt_math182;
    sjt_dot221 = _parent;
    sjt_math187 = sjt_dot221->z;
    sjt_dot222 = _parent;
    sjt_math188 = sjt_dot222->z;
    sjt_math180 = sjt_math187 * sjt_math188;
    sjt_functionParam73 = sjt_math179 + sjt_math180;
    sjf_f32_sqrt(sjt_functionParam73, &sjv_t);
    _return->_refCount = 1;
    sjt_dot223 = _parent;
    sjt_math189 = sjt_dot223->x;
    sjt_math190 = sjv_t;
    _return->x = sjt_math189 / sjt_math190;
    sjt_dot224 = _parent;
    sjt_math191 = sjt_dot224->y;
    sjt_math192 = sjv_t;
    _return->y = sjt_math191 / sjt_math192;
    sjt_dot225 = _parent;
    sjt_math193 = sjt_dot225->z;
    sjt_math194 = sjv_t;
    _return->z = sjt_math193 / sjt_math194;
    sjf_vec3(_return);
}

void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3** _return) {
    sjs_vec3* sjt_dot226 = 0;
    sjs_vec3* sjt_dot227 = 0;
    sjs_vec3* sjt_dot228 = 0;
    sjs_vec3* sjt_dot229 = 0;
    sjs_vec3* sjt_dot230 = 0;
    sjs_vec3* sjt_dot231 = 0;
    sjs_vec3* sjt_dot232 = 0;
    sjs_vec3* sjt_dot233 = 0;
    sjs_vec3* sjt_dot234 = 0;
    float sjt_functionParam74;
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
    float sjt_math207;
    float sjt_math208;
    float sjt_math209;
    float sjt_math210;
    float sjv_t;

    sjt_dot226 = _parent;
    sjt_math199 = sjt_dot226->x;
    sjt_dot227 = _parent;
    sjt_math200 = sjt_dot227->x;
    sjt_math197 = sjt_math199 * sjt_math200;
    sjt_dot228 = _parent;
    sjt_math201 = sjt_dot228->y;
    sjt_dot229 = _parent;
    sjt_math202 = sjt_dot229->y;
    sjt_math198 = sjt_math201 * sjt_math202;
    sjt_math195 = sjt_math197 + sjt_math198;
    sjt_dot230 = _parent;
    sjt_math203 = sjt_dot230->z;
    sjt_dot231 = _parent;
    sjt_math204 = sjt_dot231->z;
    sjt_math196 = sjt_math203 * sjt_math204;
    sjt_functionParam74 = sjt_math195 + sjt_math196;
    sjf_f32_sqrt(sjt_functionParam74, &sjv_t);
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot232 = _parent;
    sjt_math205 = sjt_dot232->x;
    sjt_math206 = sjv_t;
    (*_return)->x = sjt_math205 / sjt_math206;
    sjt_dot233 = _parent;
    sjt_math207 = sjt_dot233->y;
    sjt_math208 = sjv_t;
    (*_return)->y = sjt_math207 / sjt_math208;
    sjt_dot234 = _parent;
    sjt_math209 = sjt_dot234->z;
    sjt_math210 = sjv_t;
    (*_return)->z = sjt_math209 / sjt_math210;
    sjf_vec3_heap((*_return));
}

void sjf_vec3_rawcopy(sjs_vec3* v, void* p, void** _return) {
    float* f = (float*)p;
    *f = v->x;
    f++;
    *f = v->y;
    f++;
    *f = v->z;
    f++;
    (*_return) = (void*)f;
return;;
}

void sjf_vec3_subtract(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    sjs_vec3* sjt_dot205 = 0;
    sjs_vec3* sjt_dot206 = 0;
    sjs_vec3* sjt_dot207 = 0;
    sjs_vec3* sjt_dot208 = 0;
    sjs_vec3* sjt_dot209 = 0;
    sjs_vec3* sjt_dot210 = 0;
    float sjt_math167;
    float sjt_math168;
    float sjt_math169;
    float sjt_math170;
    float sjt_math171;
    float sjt_math172;

    _return->_refCount = 1;
    sjt_dot205 = _parent;
    sjt_math167 = sjt_dot205->x;
    sjt_dot206 = v;
    sjt_math168 = sjt_dot206->x;
    _return->x = sjt_math167 - sjt_math168;
    sjt_dot207 = _parent;
    sjt_math169 = sjt_dot207->y;
    sjt_dot208 = v;
    sjt_math170 = sjt_dot208->y;
    _return->y = sjt_math169 - sjt_math170;
    sjt_dot209 = _parent;
    sjt_math171 = sjt_dot209->z;
    sjt_dot210 = v;
    sjt_math172 = sjt_dot210->z;
    _return->z = sjt_math171 - sjt_math172;
    sjf_vec3(_return);
}

void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    sjs_vec3* sjt_dot211 = 0;
    sjs_vec3* sjt_dot212 = 0;
    sjs_vec3* sjt_dot213 = 0;
    sjs_vec3* sjt_dot214 = 0;
    sjs_vec3* sjt_dot215 = 0;
    sjs_vec3* sjt_dot216 = 0;
    float sjt_math173;
    float sjt_math174;
    float sjt_math175;
    float sjt_math176;
    float sjt_math177;
    float sjt_math178;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot211 = _parent;
    sjt_math173 = sjt_dot211->x;
    sjt_dot212 = v;
    sjt_math174 = sjt_dot212->x;
    (*_return)->x = sjt_math173 - sjt_math174;
    sjt_dot213 = _parent;
    sjt_math175 = sjt_dot213->y;
    sjt_dot214 = v;
    sjt_math176 = sjt_dot214->y;
    (*_return)->y = sjt_math175 - sjt_math176;
    sjt_dot215 = _parent;
    sjt_math177 = sjt_dot215->z;
    sjt_dot216 = v;
    sjt_math178 = sjt_dot216->z;
    (*_return)->z = sjt_math177 - sjt_math178;
    sjf_vec3_heap((*_return));
}

void sjf_vec4(sjs_vec4* _this) {
}

void sjf_vec4_copy(sjs_vec4* _this, sjs_vec4* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
    _this->z = _from->z;
    _this->w = _from->w;
}

void sjf_vec4_destroy(sjs_vec4* _this) {
}

void sjf_vec4_heap(sjs_vec4* _this) {
}

void sjf_vertex_location_texture_normal(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_copy(sjs_vertex_location_texture_normal* _this, sjs_vertex_location_texture_normal* _from) {
    _this->location._refCount = 1;
    sjf_vec3_copy(&_this->location, &_from->location);
    _this->texture._refCount = 1;
    sjf_vec2_copy(&_this->texture, &_from->texture);
    _this->normal._refCount = 1;
    sjf_vec3_copy(&_this->normal, &_from->normal);
}

void sjf_vertex_location_texture_normal_destroy(sjs_vertex_location_texture_normal* _this) {
    if (_this->location._refCount == 1) { sjf_vec3_destroy(&_this->location); }
;
    if (_this->texture._refCount == 1) { sjf_vec2_destroy(&_this->texture); }
;
    if (_this->normal._refCount == 1) { sjf_vec3_destroy(&_this->normal); }
;
}

void sjf_vertex_location_texture_normal_getrawsize(int32_t* _return) {
    int32_t sjt_math299;
    int32_t sjt_math300;
    int32_t sjt_math301;
    int32_t sjt_math302;

    sjf_vec3_getrawsize(&sjt_math301);
    sjf_vec2_getrawsize(&sjt_math302);
    sjt_math299 = sjt_math301 + sjt_math302;
    sjf_vec3_getrawsize(&sjt_math300);
    (*_return) = sjt_math299 + sjt_math300;
}

void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_rawcopy(sjs_vertex_location_texture_normal* v, void* p, void** _return) {
    sjs_vertex_location_texture_normal* sjt_dot340 = 0;
    sjs_vertex_location_texture_normal* sjt_dot341 = 0;
    sjs_vertex_location_texture_normal* sjt_dot342 = 0;
    void* sjt_funcold1;
    void* sjt_funcold2;
    void* sjt_funcold3;
    sjs_vec3* sjt_functionParam142 = 0;
    void* sjt_functionParam143;
    sjs_vec2* sjt_functionParam144 = 0;
    void* sjt_functionParam145;
    sjs_vec3* sjt_functionParam146 = 0;
    void* sjt_functionParam147;

    sjt_funcold1 = p;
    sjt_dot340 = v;
    sjt_functionParam142 = &sjt_dot340->location;
    sjt_functionParam143 = p;
    sjf_vec3_rawcopy(sjt_functionParam142, sjt_functionParam143, &p);
    sjt_funcold2 = p;
    sjt_dot341 = v;
    sjt_functionParam144 = &sjt_dot341->texture;
    sjt_functionParam145 = p;
    sjf_vec2_rawcopy(sjt_functionParam144, sjt_functionParam145, &p);
    sjt_funcold3 = p;
    sjt_dot342 = v;
    sjt_functionParam146 = &sjt_dot342->normal;
    sjt_functionParam147 = p;
    sjf_vec3_rawcopy(sjt_functionParam146, sjt_functionParam147, &p);
    (*_return) = p;
}

void sjf_vertexbuffer_loadobj(sjs_string* filename, sjs_vertexbuffer_vertex_location_texture_normal* _return) {
    bool result6;
    bool result7;
    sjs_string sjt_call37 = { -1 };
    sjs_string sjt_call38 = { -1 };
    sjs_string sjt_call39 = { -1 };
    sjs_string sjt_call40 = { -1 };
    sjs_string sjt_call41 = { -1 };
    sjs_string sjt_call58 = { -1 };
    sjs_string sjt_call59 = { -1 };
    sjs_string sjt_call60 = { -1 };
    sjs_string sjt_call61 = { -1 };
    sjs_vertex_location_texture_normal sjt_call71 = { -1 };
    sjs_vec3* sjt_copy35 = 0;
    sjs_vec2* sjt_copy36 = 0;
    sjs_vec3* sjt_copy37 = 0;
    sjs_string* sjt_copy46 = 0;
    sjs_array_i32* sjt_copy47 = 0;
    sjs_array_vertex_location_texture_normal* sjt_copy48 = 0;
    sjs_list_i32* sjt_dot1557 = 0;
    sjs_list_vertex_location_texture_normal* sjt_dot1558 = 0;
    int32_t sjt_functionParam197;
    sjs_string* sjt_functionParam198 = 0;
    sjs_string* sjt_functionParam232 = 0;
    sjs_string* sjt_functionParam233 = 0;
    sjs_string* sjt_functionParam234 = 0;
    sjs_string* sjt_functionParam235 = 0;
    sjs_vertex_location_texture_normal* sjt_functionParam249 = 0;
    bool sjt_ifElse42;
    bool sjt_ifElse43;
    bool sjt_not4;
    bool sjt_not5;
    sjs_list_i32* sjt_parent118 = 0;
    sjs_string* sjt_parent132 = 0;
    sjs_string* sjt_parent133 = 0;
    sjs_string* sjt_parent134 = 0;
    sjs_string* sjt_parent135 = 0;
    sjs_vec3* sjt_parent144 = 0;
    sjs_vec3* sjt_parent145 = 0;
    sjs_vec2* sjt_parent150 = 0;
    sjs_list_vertex_location_texture_normal* sjt_parent153 = 0;
    bool sjv_includenormals;
    bool sjv_includetextures;
    int32_t sjv_index;
    sjs_list_i32 sjv_indices = { -1 };
    sjs_vec3 sjv_location = { -1 };
    sjs_vec3 sjv_normal = { -1 };
    sjs_array_vec3 sjv_normals = { -1 };
    sjs_vec2 sjv_texture = { -1 };
    sjs_list_vertex_location_texture_normal sjv_vertices = { -1 };

    sjv_indices._refCount = 1;
    sjv_indices.array._refCount = 1;
    sjv_indices.array.datasize = 0;
    sjv_indices.array.data = 0;
    sjv_indices.array._isglobal = false;
    sjv_indices.array.count = 0;
    sjf_array_i32(&sjv_indices.array);
    sjf_list_i32(&sjv_indices);
    sjv_vertices._refCount = 1;
    sjv_vertices.array._refCount = 1;
    sjv_vertices.array.datasize = 0;
    sjv_vertices.array.data = 0;
    sjv_vertices.array._isglobal = false;
    sjv_vertices.array.count = 0;
    sjf_array_vertex_location_texture_normal(&sjv_vertices.array);
    sjf_list_vertex_location_texture_normal(&sjv_vertices);
    sjv_location._refCount = 1;
    sjv_location.x = 0.0f;
    sjv_location.y = 0.0f;
    sjv_location.z = 0.0f;
    sjf_vec3(&sjv_location);
    sjv_texture._refCount = 1;
    sjv_texture.x = 0.0f;
    sjv_texture.y = 0.0f;
    sjf_vec2(&sjv_texture);
    sjv_normal._refCount = 1;
    sjv_normal.x = 0.0f;
    sjv_normal.y = 0.0f;
    sjv_normal.z = 0.0f;
    sjf_vec3(&sjv_normal);
    sjv_index = 0;
    sjv_includenormals = true;
    sjv_includetextures = true;
    obj_scene_data data = { 0 };
    if (parse_obj_scene(&data, (char*)filename->data.data)) {
        for (int i = 0; i < data.face_count; i++) {
            if (data.face_list[i]->vertex_count != 3) {
                printf("warn: do not support obj with non-triangles\n");
            }
            for (int j = 0; j < 3; j++) {
                sjv_index = data.face_list[i]->vertex_index[j];
                if (data.face_list[i]->vertex_index[j] != data.face_list[i]->normal_index[j]) {
                    sjv_includenormals = false;
                }
                if (data.face_list[i]->vertex_index[j] != data.face_list[i]->texture_index[j]) {
                    sjv_includetextures = false;
                }
                sjt_parent118 = &sjv_indices;
                sjt_functionParam197 = sjv_index;
                sjf_list_i32_add(sjt_parent118, sjt_functionParam197);
            }
        }
        if (data.vertex_count != data.vertex_normal_count) {
            sjv_includenormals = false;
        }
        if (data.vertex_count != data.vertex_texture_count) {
            sjv_includetextures = false;
        }
        for (int i = 0; i < data.vertex_count; i++) {
            sjv_location.x = (float)data.vertex_list[i]->e[0];
            sjv_location.y = (float)data.vertex_list[i]->e[1];
            sjv_location.z = (float)data.vertex_list[i]->e[2];
            if (sjv_includenormals) {
                sjv_normal.x = (float)data.vertex_normal_list[i]->e[0];
                sjv_normal.y = (float)data.vertex_normal_list[i]->e[1];
                sjv_normal.z = (float)data.vertex_normal_list[i]->e[2];            
            }
            if (sjv_includetextures) {
                sjv_texture.x = (float)data.vertex_texture_list[i]->e[0];
                sjv_texture.y = (float)data.vertex_texture_list[i]->e[1];
            }
            sjt_parent144 = &sjv_location;
            sjf_vec3_asstring(sjt_parent144, &sjt_call41);
            sjt_parent135 = &sjt_call41;
            sjt_call58._refCount = 1;
            sjt_call58.count = 1;
            sjt_call58.data._refCount = 1;
            sjt_call58.data.datasize = 2;
            sjt_call58.data.data = (void*)sjg_string24;
            sjt_call58.data._isglobal = true;
            sjt_call58.data.count = 2;
            sjf_array_char(&sjt_call58.data);
            sjf_string(&sjt_call58);
            sjt_functionParam232 = &sjt_call58;
            sjf_string_add(sjt_parent135, sjt_functionParam232, &sjt_call40);
            sjt_parent134 = &sjt_call40;
            sjt_parent145 = &sjv_normal;
            sjf_vec3_asstring(sjt_parent145, &sjt_call59);
            sjt_functionParam233 = &sjt_call59;
            sjf_string_add(sjt_parent134, sjt_functionParam233, &sjt_call39);
            sjt_parent133 = &sjt_call39;
            sjt_call60._refCount = 1;
            sjt_call60.count = 1;
            sjt_call60.data._refCount = 1;
            sjt_call60.data.datasize = 2;
            sjt_call60.data.data = (void*)sjg_string24;
            sjt_call60.data._isglobal = true;
            sjt_call60.data.count = 2;
            sjf_array_char(&sjt_call60.data);
            sjf_string(&sjt_call60);
            sjt_functionParam234 = &sjt_call60;
            sjf_string_add(sjt_parent133, sjt_functionParam234, &sjt_call38);
            sjt_parent132 = &sjt_call38;
            sjt_parent150 = &sjv_texture;
            sjf_vec2_asstring(sjt_parent150, &sjt_call61);
            sjt_functionParam235 = &sjt_call61;
            sjf_string_add(sjt_parent132, sjt_functionParam235, &sjt_call37);
            sjt_functionParam198 = &sjt_call37;
            sjf_debug_writeline(sjt_functionParam198);
            sjt_parent153 = &sjv_vertices;
            sjt_call71._refCount = 1;
            sjt_copy35 = &sjv_location;
            sjt_call71.location._refCount = 1;
            sjf_vec3_copy(&sjt_call71.location, sjt_copy35);
            sjt_copy36 = &sjv_texture;
            sjt_call71.texture._refCount = 1;
            sjf_vec2_copy(&sjt_call71.texture, sjt_copy36);
            sjt_copy37 = &sjv_normal;
            sjt_call71.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call71.normal, sjt_copy37);
            sjf_vertex_location_texture_normal(&sjt_call71);
            sjt_functionParam249 = &sjt_call71;
            sjf_list_vertex_location_texture_normal_add(sjt_parent153, sjt_functionParam249);
        }
    }
    delete_obj_data(&data);
    sjt_not4 = sjv_includenormals;
    result6 = !sjt_not4;
    sjt_ifElse42 = result6;
    if (sjt_ifElse42) {
        int32_t i;
        int32_t sjt_forEnd18;
        int32_t sjt_forEnd19;
        int32_t sjt_forEnd20;
        int32_t sjt_forStart18;
        int32_t sjt_forStart19;
        int32_t sjt_forStart20;
        int32_t sjt_math2245;
        int32_t sjt_math2246;
        sjs_list_vertex_location_texture_normal* sjt_parent154 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent155 = 0;
        sjs_list_i32* sjt_parent157 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent179 = 0;

        sjv_normals._refCount = 1;
        sjt_parent154 = &sjv_vertices;
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent154, &sjv_normals.datasize);
        sjv_normals.data = 0;
        sjv_normals._isglobal = false;
        sjv_normals.count = 0;
        sjf_array_vec3(&sjv_normals);
        sjt_forStart18 = 0;
        sjt_parent155 = &sjv_vertices;
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent155, &sjt_forEnd18);
        i = sjt_forStart18;
        while (i < sjt_forEnd18) {
            sjs_vec3 sjt_call72 = { -1 };
            int32_t sjt_functionParam250;
            sjs_vec3* sjt_functionParam251 = 0;
            sjs_array_vec3* sjt_parent156 = 0;

            sjt_parent156 = &sjv_normals;
            sjt_functionParam250 = i;
            sjt_call72._refCount = 1;
            sjt_call72.x = 0.0f;
            sjt_call72.y = 0.0f;
            sjt_call72.z = 0.0f;
            sjf_vec3(&sjt_call72);
            sjt_functionParam251 = &sjt_call72;
            sjf_array_vec3_initat(sjt_parent156, sjt_functionParam250, sjt_functionParam251);
            i++;

            if (sjt_call72._refCount == 1) { sjf_vec3_destroy(&sjt_call72); }
;
        }

        sjt_forStart19 = 0;
        sjt_parent157 = &sjv_indices;
        sjf_list_i32_getcount(sjt_parent157, &sjt_math2245);
        sjt_math2246 = 3;
        sjt_forEnd19 = sjt_math2245 / sjt_math2246;
        i = sjt_forStart19;
        while (i < sjt_forEnd19) {
            sjs_vertex_location_texture_normal sjt_call73 = { -1 };
            sjs_vertex_location_texture_normal sjt_call74 = { -1 };
            sjs_vertex_location_texture_normal sjt_call75 = { -1 };
            sjs_vec3 sjt_call76 = { -1 };
            sjs_vec3 sjt_call77 = { -1 };
            sjs_vec3 sjt_call78 = { -1 };
            sjs_vec3 sjt_call79 = { -1 };
            sjs_vec3 sjt_call80 = { -1 };
            sjs_vec3 sjt_call81 = { -1 };
            sjs_vec3 sjt_call82 = { -1 };
            sjs_vec3* sjt_copy38 = 0;
            sjs_vec3* sjt_copy39 = 0;
            sjs_vec3* sjt_copy40 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1526 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1528 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1529 = 0;
            int32_t sjt_functionParam253;
            int32_t sjt_functionParam254;
            int32_t sjt_functionParam255;
            int32_t sjt_functionParam257;
            int32_t sjt_functionParam258;
            int32_t sjt_functionParam259;
            sjs_vec3* sjt_functionParam260 = 0;
            sjs_vec3* sjt_functionParam261 = 0;
            sjs_vec3* sjt_functionParam262 = 0;
            int32_t sjt_functionParam263;
            sjs_vec3* sjt_functionParam264 = 0;
            int32_t sjt_functionParam265;
            sjs_vec3* sjt_functionParam266 = 0;
            int32_t sjt_functionParam267;
            sjs_vec3* sjt_functionParam268 = 0;
            int32_t sjt_functionParam269;
            sjs_vec3* sjt_functionParam270 = 0;
            int32_t sjt_functionParam271;
            sjs_vec3* sjt_functionParam272 = 0;
            int32_t sjt_functionParam273;
            sjs_vec3* sjt_functionParam274 = 0;
            int32_t sjt_math2247;
            int32_t sjt_math2248;
            int32_t sjt_math2249;
            int32_t sjt_math2250;
            int32_t sjt_math2251;
            int32_t sjt_math2252;
            int32_t sjt_math2253;
            int32_t sjt_math2254;
            int32_t sjt_math2255;
            int32_t sjt_math2256;
            int32_t sjt_math2257;
            int32_t sjt_math2258;
            sjs_list_i32* sjt_parent159 = 0;
            sjs_list_i32* sjt_parent160 = 0;
            sjs_list_i32* sjt_parent161 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent163 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent164 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent165 = 0;
            sjs_vec3* sjt_parent166 = 0;
            sjs_vec3* sjt_parent167 = 0;
            sjs_vec3* sjt_parent168 = 0;
            sjs_vec3* sjt_parent169 = 0;
            sjs_array_vec3* sjt_parent170 = 0;
            sjs_vec3* sjt_parent171 = 0;
            sjs_array_vec3* sjt_parent172 = 0;
            sjs_array_vec3* sjt_parent173 = 0;
            sjs_vec3* sjt_parent174 = 0;
            sjs_array_vec3* sjt_parent175 = 0;
            sjs_array_vec3* sjt_parent176 = 0;
            sjs_vec3* sjt_parent177 = 0;
            sjs_array_vec3* sjt_parent178 = 0;
            int32_t sjv_i1;
            int32_t sjv_i2;
            int32_t sjv_i3;
            sjs_vec3 sjv_newnormal = { -1 };
            sjs_vec3 sjv_side1 = { -1 };
            sjs_vec3 sjv_side2 = { -1 };
            sjs_vec3 sjv_v1 = { -1 };
            sjs_vec3 sjv_v2 = { -1 };
            sjs_vec3 sjv_v3 = { -1 };

            sjt_parent159 = &sjv_indices;
            sjt_math2249 = i;
            sjt_math2250 = 3;
            sjt_math2247 = sjt_math2249 * sjt_math2250;
            sjt_math2248 = 0;
            sjt_functionParam253 = sjt_math2247 + sjt_math2248;
            sjf_list_i32_getat(sjt_parent159, sjt_functionParam253, &sjv_i1);
            sjt_parent160 = &sjv_indices;
            sjt_math2253 = i;
            sjt_math2254 = 3;
            sjt_math2251 = sjt_math2253 * sjt_math2254;
            sjt_math2252 = 1;
            sjt_functionParam254 = sjt_math2251 + sjt_math2252;
            sjf_list_i32_getat(sjt_parent160, sjt_functionParam254, &sjv_i2);
            sjt_parent161 = &sjv_indices;
            sjt_math2257 = i;
            sjt_math2258 = 3;
            sjt_math2255 = sjt_math2257 * sjt_math2258;
            sjt_math2256 = 2;
            sjt_functionParam255 = sjt_math2255 + sjt_math2256;
            sjf_list_i32_getat(sjt_parent161, sjt_functionParam255, &sjv_i3);
            sjt_parent163 = &sjv_vertices;
            sjt_functionParam257 = sjv_i1;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent163, sjt_functionParam257, &sjt_call73);
            sjt_dot1526 = &sjt_call73;
            sjt_copy38 = &sjt_dot1526->location;
            sjv_v1._refCount = 1;
            sjf_vec3_copy(&sjv_v1, sjt_copy38);
            sjt_parent164 = &sjv_vertices;
            sjt_functionParam258 = sjv_i2;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent164, sjt_functionParam258, &sjt_call74);
            sjt_dot1528 = &sjt_call74;
            sjt_copy39 = &sjt_dot1528->location;
            sjv_v2._refCount = 1;
            sjf_vec3_copy(&sjv_v2, sjt_copy39);
            sjt_parent165 = &sjv_vertices;
            sjt_functionParam259 = sjv_i3;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent165, sjt_functionParam259, &sjt_call75);
            sjt_dot1529 = &sjt_call75;
            sjt_copy40 = &sjt_dot1529->location;
            sjv_v3._refCount = 1;
            sjf_vec3_copy(&sjv_v3, sjt_copy40);
            sjt_parent166 = &sjv_v2;
            sjt_functionParam260 = &sjv_v1;
            sjf_vec3_subtract(sjt_parent166, sjt_functionParam260, &sjv_side1);
            sjt_parent167 = &sjv_v3;
            sjt_functionParam261 = &sjv_v1;
            sjf_vec3_subtract(sjt_parent167, sjt_functionParam261, &sjv_side2);
            sjt_parent169 = &sjv_side2;
            sjt_functionParam262 = &sjv_side1;
            sjf_vec3_cross(sjt_parent169, sjt_functionParam262, &sjt_call76);
            sjt_parent168 = &sjt_call76;
            sjf_vec3_normalize(sjt_parent168, &sjv_newnormal);
            sjt_parent170 = &sjv_normals;
            sjt_functionParam263 = sjv_i1;
            sjt_parent172 = &sjv_normals;
            sjt_functionParam265 = sjv_i1;
            sjf_array_vec3_getat(sjt_parent172, sjt_functionParam265, &sjt_call78);
            sjt_parent171 = &sjt_call78;
            sjt_functionParam266 = &sjv_newnormal;
            sjf_vec3_add(sjt_parent171, sjt_functionParam266, &sjt_call77);
            sjt_functionParam264 = &sjt_call77;
            sjf_array_vec3_setat(sjt_parent170, sjt_functionParam263, sjt_functionParam264);
            sjt_parent173 = &sjv_normals;
            sjt_functionParam267 = sjv_i2;
            sjt_parent175 = &sjv_normals;
            sjt_functionParam269 = sjv_i2;
            sjf_array_vec3_getat(sjt_parent175, sjt_functionParam269, &sjt_call80);
            sjt_parent174 = &sjt_call80;
            sjt_functionParam270 = &sjv_newnormal;
            sjf_vec3_add(sjt_parent174, sjt_functionParam270, &sjt_call79);
            sjt_functionParam268 = &sjt_call79;
            sjf_array_vec3_setat(sjt_parent173, sjt_functionParam267, sjt_functionParam268);
            sjt_parent176 = &sjv_normals;
            sjt_functionParam271 = sjv_i3;
            sjt_parent178 = &sjv_normals;
            sjt_functionParam273 = sjv_i3;
            sjf_array_vec3_getat(sjt_parent178, sjt_functionParam273, &sjt_call82);
            sjt_parent177 = &sjt_call82;
            sjt_functionParam274 = &sjv_newnormal;
            sjf_vec3_add(sjt_parent177, sjt_functionParam274, &sjt_call81);
            sjt_functionParam272 = &sjt_call81;
            sjf_array_vec3_setat(sjt_parent176, sjt_functionParam271, sjt_functionParam272);
            i++;

            if (sjt_call73._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call73); }
;
            if (sjt_call74._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call74); }
;
            if (sjt_call75._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call75); }
;
            if (sjt_call76._refCount == 1) { sjf_vec3_destroy(&sjt_call76); }
;
            if (sjt_call77._refCount == 1) { sjf_vec3_destroy(&sjt_call77); }
;
            if (sjt_call78._refCount == 1) { sjf_vec3_destroy(&sjt_call78); }
;
            if (sjt_call79._refCount == 1) { sjf_vec3_destroy(&sjt_call79); }
;
            if (sjt_call80._refCount == 1) { sjf_vec3_destroy(&sjt_call80); }
;
            if (sjt_call81._refCount == 1) { sjf_vec3_destroy(&sjt_call81); }
;
            if (sjt_call82._refCount == 1) { sjf_vec3_destroy(&sjt_call82); }
;
            if (sjv_newnormal._refCount == 1) { sjf_vec3_destroy(&sjv_newnormal); }
;
            if (sjv_side1._refCount == 1) { sjf_vec3_destroy(&sjv_side1); }
;
            if (sjv_side2._refCount == 1) { sjf_vec3_destroy(&sjv_side2); }
;
            if (sjv_v1._refCount == 1) { sjf_vec3_destroy(&sjv_v1); }
;
            if (sjv_v2._refCount == 1) { sjf_vec3_destroy(&sjv_v2); }
;
            if (sjv_v3._refCount == 1) { sjf_vec3_destroy(&sjv_v3); }
;
        }

        sjt_forStart20 = 0;
        sjt_parent179 = &sjv_vertices;
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent179, &sjt_forEnd20);
        i = sjt_forStart20;
        while (i < sjt_forEnd20) {
            sjs_vec3 sjt_call83 = { -1 };
            sjs_vertex_location_texture_normal sjt_call84 = { -1 };
            sjs_vertex_location_texture_normal sjt_call85 = { -1 };
            sjs_vertex_location_texture_normal sjt_call86 = { -1 };
            sjs_vec3* sjt_copy41 = 0;
            sjs_vec2* sjt_copy42 = 0;
            sjs_vec3* sjt_copy43 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1543 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1544 = 0;
            int32_t sjt_functionParam275;
            int32_t sjt_functionParam278;
            sjs_vertex_location_texture_normal* sjt_functionParam279 = 0;
            int32_t sjt_functionParam280;
            int32_t sjt_functionParam281;
            sjs_vec3* sjt_parent180 = 0;
            sjs_array_vec3* sjt_parent181 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent183 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent184 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent185 = 0;
            sjs_vec3 sjv_newnormal = { -1 };

            sjt_parent181 = &sjv_normals;
            sjt_functionParam275 = i;
            sjf_array_vec3_getat(sjt_parent181, sjt_functionParam275, &sjt_call83);
            sjt_parent180 = &sjt_call83;
            sjf_vec3_normalize(sjt_parent180, &sjv_newnormal);
            sjt_parent183 = &sjv_vertices;
            sjt_functionParam278 = i;
            sjt_call84._refCount = 1;
            sjt_parent184 = &sjv_vertices;
            sjt_functionParam280 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent184, sjt_functionParam280, &sjt_call85);
            sjt_dot1543 = &sjt_call85;
            sjt_copy41 = &sjt_dot1543->location;
            sjt_call84.location._refCount = 1;
            sjf_vec3_copy(&sjt_call84.location, sjt_copy41);
            sjt_parent185 = &sjv_vertices;
            sjt_functionParam281 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent185, sjt_functionParam281, &sjt_call86);
            sjt_dot1544 = &sjt_call86;
            sjt_copy42 = &sjt_dot1544->texture;
            sjt_call84.texture._refCount = 1;
            sjf_vec2_copy(&sjt_call84.texture, sjt_copy42);
            sjt_copy43 = &sjv_newnormal;
            sjt_call84.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call84.normal, sjt_copy43);
            sjf_vertex_location_texture_normal(&sjt_call84);
            sjt_functionParam279 = &sjt_call84;
            sjf_list_vertex_location_texture_normal_setat(sjt_parent183, sjt_functionParam278, sjt_functionParam279);
            i++;

            if (sjt_call83._refCount == 1) { sjf_vec3_destroy(&sjt_call83); }
;
            if (sjt_call84._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call84); }
;
            if (sjt_call85._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call85); }
;
            if (sjt_call86._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call86); }
;
            if (sjv_newnormal._refCount == 1) { sjf_vec3_destroy(&sjv_newnormal); }
;
        }
    }

    sjt_not5 = sjv_includetextures;
    result7 = !sjt_not5;
    sjt_ifElse43 = result7;
    if (sjt_ifElse43) {
        int32_t i;
        int32_t sjt_forEnd21;
        int32_t sjt_forEnd22;
        int32_t sjt_forStart21;
        int32_t sjt_forStart22;
        sjs_list_vertex_location_texture_normal* sjt_parent186 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent189 = 0;
        float sjv_ymax;
        float sjv_ymin;

        sjv_ymin = 0.0f;
        sjv_ymax = 0.0f;
        sjt_forStart21 = 0;
        sjt_parent186 = &sjv_vertices;
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent186, &sjt_forEnd21);
        i = sjt_forStart21;
        while (i < sjt_forEnd21) {
            sjs_vertex_location_texture_normal sjt_call87 = { -1 };
            sjs_vertex_location_texture_normal sjt_call88 = { -1 };
            sjs_vec3* sjt_dot1545 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1546 = 0;
            sjs_vec3* sjt_dot1547 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1548 = 0;
            float sjt_funcold4;
            float sjt_funcold5;
            float sjt_functionParam282;
            float sjt_functionParam283;
            int32_t sjt_functionParam284;
            float sjt_functionParam285;
            float sjt_functionParam286;
            int32_t sjt_functionParam287;
            sjs_list_vertex_location_texture_normal* sjt_parent187 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent188 = 0;

            sjt_funcold4 = sjv_ymin;
            sjt_functionParam282 = sjv_ymin;
            sjt_parent187 = &sjv_vertices;
            sjt_functionParam284 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent187, sjt_functionParam284, &sjt_call87);
            sjt_dot1546 = &sjt_call87;
            sjt_dot1545 = &sjt_dot1546->location;
            sjt_functionParam283 = sjt_dot1545->y;
            sjf_f32_min(sjt_functionParam282, sjt_functionParam283, &sjv_ymin);
            sjt_funcold5 = sjv_ymax;
            sjt_functionParam285 = sjv_ymax;
            sjt_parent188 = &sjv_vertices;
            sjt_functionParam287 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent188, sjt_functionParam287, &sjt_call88);
            sjt_dot1548 = &sjt_call88;
            sjt_dot1547 = &sjt_dot1548->location;
            sjt_functionParam286 = sjt_dot1547->y;
            sjf_f32_max(sjt_functionParam285, sjt_functionParam286, &sjv_ymax);
            i++;

            if (sjt_call87._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call87); }
;
            if (sjt_call88._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call88); }
;
        }

        sjt_forStart22 = 0;
        sjt_parent189 = &sjv_vertices;
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent189, &sjt_forEnd22);
        i = sjt_forStart22;
        while (i < sjt_forEnd22) {
            sjs_vertex_location_texture_normal sjt_call89 = { -1 };
            sjs_vertex_location_texture_normal sjt_call90 = { -1 };
            sjs_vertex_location_texture_normal sjt_call91 = { -1 };
            sjs_vertex_location_texture_normal sjt_call92 = { -1 };
            sjs_vertex_location_texture_normal sjt_call93 = { -1 };
            sjs_vertex_location_texture_normal sjt_call94 = { -1 };
            sjs_vec3* sjt_copy44 = 0;
            sjs_vec3* sjt_copy45 = 0;
            sjs_vec3* sjt_dot1549 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1550 = 0;
            sjs_vec3* sjt_dot1551 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1552 = 0;
            sjs_vec3* sjt_dot1553 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1554 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1555 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1556 = 0;
            float sjt_functionParam288;
            int32_t sjt_functionParam289;
            float sjt_functionParam290;
            int32_t sjt_functionParam291;
            int32_t sjt_functionParam292;
            int32_t sjt_functionParam293;
            sjs_vertex_location_texture_normal* sjt_functionParam294 = 0;
            int32_t sjt_functionParam295;
            int32_t sjt_functionParam296;
            float sjt_math2271;
            float sjt_math2272;
            float sjt_math2273;
            float sjt_math2274;
            float sjt_math2275;
            float sjt_math2276;
            float sjt_math2277;
            float sjt_math2278;
            float sjt_math2279;
            float sjt_math2280;
            float sjt_math2281;
            float sjt_math2282;
            sjs_list_vertex_location_texture_normal* sjt_parent190 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent191 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent192 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent193 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent194 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent195 = 0;
            float sjv_s;
            float sjv_t;

            sjt_parent190 = &sjv_vertices;
            sjt_functionParam289 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent190, sjt_functionParam289, &sjt_call89);
            sjt_dot1550 = &sjt_call89;
            sjt_dot1549 = &sjt_dot1550->location;
            sjt_functionParam288 = sjt_dot1549->x;
            sjt_parent191 = &sjv_vertices;
            sjt_functionParam291 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent191, sjt_functionParam291, &sjt_call90);
            sjt_dot1552 = &sjt_call90;
            sjt_dot1551 = &sjt_dot1552->location;
            sjt_functionParam290 = sjt_dot1551->z;
            sjf_f32_atan2(sjt_functionParam288, sjt_functionParam290, &sjt_math2273);
            sjt_math2274 = sjv_f32_pi;
            sjt_math2271 = sjt_math2273 + sjt_math2274;
            sjt_math2275 = 2.0f;
            sjt_math2276 = sjv_f32_pi;
            sjt_math2272 = sjt_math2275 * sjt_math2276;
            sjv_s = sjt_math2271 / sjt_math2272;
            sjt_parent192 = &sjv_vertices;
            sjt_functionParam292 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent192, sjt_functionParam292, &sjt_call91);
            sjt_dot1554 = &sjt_call91;
            sjt_dot1553 = &sjt_dot1554->location;
            sjt_math2279 = sjt_dot1553->y;
            sjt_math2280 = sjv_ymin;
            sjt_math2277 = sjt_math2279 - sjt_math2280;
            sjt_math2281 = sjv_ymax;
            sjt_math2282 = sjv_ymin;
            sjt_math2278 = sjt_math2281 - sjt_math2282;
            sjv_t = sjt_math2277 / sjt_math2278;
            sjt_parent193 = &sjv_vertices;
            sjt_functionParam293 = i;
            sjt_call92._refCount = 1;
            sjt_parent194 = &sjv_vertices;
            sjt_functionParam295 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent194, sjt_functionParam295, &sjt_call93);
            sjt_dot1555 = &sjt_call93;
            sjt_copy44 = &sjt_dot1555->location;
            sjt_call92.location._refCount = 1;
            sjf_vec3_copy(&sjt_call92.location, sjt_copy44);
            sjt_call92.texture._refCount = 1;
            sjt_call92.texture.x = sjv_s;
            sjt_call92.texture.y = sjv_t;
            sjf_vec2(&sjt_call92.texture);
            sjt_parent195 = &sjv_vertices;
            sjt_functionParam296 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent195, sjt_functionParam296, &sjt_call94);
            sjt_dot1556 = &sjt_call94;
            sjt_copy45 = &sjt_dot1556->normal;
            sjt_call92.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call92.normal, sjt_copy45);
            sjf_vertex_location_texture_normal(&sjt_call92);
            sjt_functionParam294 = &sjt_call92;
            sjf_list_vertex_location_texture_normal_setat(sjt_parent193, sjt_functionParam293, sjt_functionParam294);
            i++;

            if (sjt_call89._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call89); }
;
            if (sjt_call90._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call90); }
;
            if (sjt_call91._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call91); }
;
            if (sjt_call92._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call92); }
;
            if (sjt_call93._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call93); }
;
            if (sjt_call94._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call94); }
;
        }
    }

    _return->_refCount = 1;
    sjt_copy46 = &sjv_vertex_location_texture_normal_format;
    _return->format._refCount = 1;
    sjf_string_copy(&_return->format, sjt_copy46);
    sjt_dot1557 = &sjv_indices;
    sjt_copy47 = &sjt_dot1557->array;
    _return->indices._refCount = 1;
    sjf_array_i32_copy(&_return->indices, sjt_copy47);
    sjt_dot1558 = &sjv_vertices;
    sjt_copy48 = &sjt_dot1558->array;
    _return->vertices._refCount = 1;
    sjf_array_vertex_location_texture_normal_copy(&_return->vertices, sjt_copy48);
    sjf_vertexbuffer_vertex_location_texture_normal(_return);

    if (sjt_call37._refCount == 1) { sjf_string_destroy(&sjt_call37); }
;
    if (sjt_call38._refCount == 1) { sjf_string_destroy(&sjt_call38); }
;
    if (sjt_call39._refCount == 1) { sjf_string_destroy(&sjt_call39); }
;
    if (sjt_call40._refCount == 1) { sjf_string_destroy(&sjt_call40); }
;
    if (sjt_call41._refCount == 1) { sjf_string_destroy(&sjt_call41); }
;
    if (sjt_call58._refCount == 1) { sjf_string_destroy(&sjt_call58); }
;
    if (sjt_call59._refCount == 1) { sjf_string_destroy(&sjt_call59); }
;
    if (sjt_call60._refCount == 1) { sjf_string_destroy(&sjt_call60); }
;
    if (sjt_call61._refCount == 1) { sjf_string_destroy(&sjt_call61); }
;
    if (sjt_call71._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call71); }
;
    if (sjv_indices._refCount == 1) { sjf_list_i32_destroy(&sjv_indices); }
;
    if (sjv_location._refCount == 1) { sjf_vec3_destroy(&sjv_location); }
;
    if (sjv_normal._refCount == 1) { sjf_vec3_destroy(&sjv_normal); }
;
    if (sjv_normals._refCount == 1) { sjf_array_vec3_destroy(&sjv_normals); }
;
    if (sjv_texture._refCount == 1) { sjf_vec2_destroy(&sjv_texture); }
;
    if (sjv_vertices._refCount == 1) { sjf_list_vertex_location_texture_normal_destroy(&sjv_vertices); }
;
}

void sjf_vertexbuffer_loadobj_heap(sjs_string* filename, sjs_vertexbuffer_vertex_location_texture_normal** _return) {
    bool result8;
    bool result9;
    sjs_string sjt_call100 = { -1 };
    sjs_string sjt_call101 = { -1 };
    sjs_string sjt_call102 = { -1 };
    sjs_string sjt_call103 = { -1 };
    sjs_vertex_location_texture_normal sjt_call104 = { -1 };
    sjs_string sjt_call95 = { -1 };
    sjs_string sjt_call96 = { -1 };
    sjs_string sjt_call97 = { -1 };
    sjs_string sjt_call98 = { -1 };
    sjs_string sjt_call99 = { -1 };
    sjs_vec3* sjt_copy49 = 0;
    sjs_vec2* sjt_copy50 = 0;
    sjs_vec3* sjt_copy51 = 0;
    sjs_string* sjt_copy60 = 0;
    sjs_array_i32* sjt_copy61 = 0;
    sjs_array_vertex_location_texture_normal* sjt_copy62 = 0;
    sjs_list_i32* sjt_dot1576 = 0;
    sjs_list_vertex_location_texture_normal* sjt_dot1577 = 0;
    int32_t sjt_functionParam297;
    sjs_string* sjt_functionParam298 = 0;
    sjs_string* sjt_functionParam299 = 0;
    sjs_string* sjt_functionParam300 = 0;
    sjs_string* sjt_functionParam301 = 0;
    sjs_string* sjt_functionParam302 = 0;
    sjs_vertex_location_texture_normal* sjt_functionParam303 = 0;
    bool sjt_ifElse46;
    bool sjt_ifElse47;
    bool sjt_not6;
    bool sjt_not7;
    sjs_list_i32* sjt_parent196 = 0;
    sjs_string* sjt_parent197 = 0;
    sjs_string* sjt_parent198 = 0;
    sjs_string* sjt_parent199 = 0;
    sjs_string* sjt_parent200 = 0;
    sjs_vec3* sjt_parent201 = 0;
    sjs_vec3* sjt_parent202 = 0;
    sjs_vec2* sjt_parent203 = 0;
    sjs_list_vertex_location_texture_normal* sjt_parent204 = 0;
    bool sjv_includenormals;
    bool sjv_includetextures;
    int32_t sjv_index;
    sjs_list_i32 sjv_indices = { -1 };
    sjs_vec3 sjv_location = { -1 };
    sjs_vec3 sjv_normal = { -1 };
    sjs_array_vec3 sjv_normals = { -1 };
    sjs_vec2 sjv_texture = { -1 };
    sjs_list_vertex_location_texture_normal sjv_vertices = { -1 };

    sjv_indices._refCount = 1;
    sjv_indices.array._refCount = 1;
    sjv_indices.array.datasize = 0;
    sjv_indices.array.data = 0;
    sjv_indices.array._isglobal = false;
    sjv_indices.array.count = 0;
    sjf_array_i32(&sjv_indices.array);
    sjf_list_i32(&sjv_indices);
    sjv_vertices._refCount = 1;
    sjv_vertices.array._refCount = 1;
    sjv_vertices.array.datasize = 0;
    sjv_vertices.array.data = 0;
    sjv_vertices.array._isglobal = false;
    sjv_vertices.array.count = 0;
    sjf_array_vertex_location_texture_normal(&sjv_vertices.array);
    sjf_list_vertex_location_texture_normal(&sjv_vertices);
    sjv_location._refCount = 1;
    sjv_location.x = 0.0f;
    sjv_location.y = 0.0f;
    sjv_location.z = 0.0f;
    sjf_vec3(&sjv_location);
    sjv_texture._refCount = 1;
    sjv_texture.x = 0.0f;
    sjv_texture.y = 0.0f;
    sjf_vec2(&sjv_texture);
    sjv_normal._refCount = 1;
    sjv_normal.x = 0.0f;
    sjv_normal.y = 0.0f;
    sjv_normal.z = 0.0f;
    sjf_vec3(&sjv_normal);
    sjv_index = 0;
    sjv_includenormals = true;
    sjv_includetextures = true;
    obj_scene_data data = { 0 };
    if (parse_obj_scene(&data, (char*)filename->data.data)) {
        for (int i = 0; i < data.face_count; i++) {
            if (data.face_list[i]->vertex_count != 3) {
                printf("warn: do not support obj with non-triangles\n");
            }
            for (int j = 0; j < 3; j++) {
                sjv_index = data.face_list[i]->vertex_index[j];
                if (data.face_list[i]->vertex_index[j] != data.face_list[i]->normal_index[j]) {
                    sjv_includenormals = false;
                }
                if (data.face_list[i]->vertex_index[j] != data.face_list[i]->texture_index[j]) {
                    sjv_includetextures = false;
                }
                sjt_parent196 = &sjv_indices;
                sjt_functionParam297 = sjv_index;
                sjf_list_i32_add(sjt_parent196, sjt_functionParam297);
            }
        }
        if (data.vertex_count != data.vertex_normal_count) {
            sjv_includenormals = false;
        }
        if (data.vertex_count != data.vertex_texture_count) {
            sjv_includetextures = false;
        }
        for (int i = 0; i < data.vertex_count; i++) {
            sjv_location.x = (float)data.vertex_list[i]->e[0];
            sjv_location.y = (float)data.vertex_list[i]->e[1];
            sjv_location.z = (float)data.vertex_list[i]->e[2];
            if (sjv_includenormals) {
                sjv_normal.x = (float)data.vertex_normal_list[i]->e[0];
                sjv_normal.y = (float)data.vertex_normal_list[i]->e[1];
                sjv_normal.z = (float)data.vertex_normal_list[i]->e[2];            
            }
            if (sjv_includetextures) {
                sjv_texture.x = (float)data.vertex_texture_list[i]->e[0];
                sjv_texture.y = (float)data.vertex_texture_list[i]->e[1];
            }
            sjt_parent201 = &sjv_location;
            sjf_vec3_asstring(sjt_parent201, &sjt_call99);
            sjt_parent200 = &sjt_call99;
            sjt_call100._refCount = 1;
            sjt_call100.count = 1;
            sjt_call100.data._refCount = 1;
            sjt_call100.data.datasize = 2;
            sjt_call100.data.data = (void*)sjg_string24;
            sjt_call100.data._isglobal = true;
            sjt_call100.data.count = 2;
            sjf_array_char(&sjt_call100.data);
            sjf_string(&sjt_call100);
            sjt_functionParam299 = &sjt_call100;
            sjf_string_add(sjt_parent200, sjt_functionParam299, &sjt_call98);
            sjt_parent199 = &sjt_call98;
            sjt_parent202 = &sjv_normal;
            sjf_vec3_asstring(sjt_parent202, &sjt_call101);
            sjt_functionParam300 = &sjt_call101;
            sjf_string_add(sjt_parent199, sjt_functionParam300, &sjt_call97);
            sjt_parent198 = &sjt_call97;
            sjt_call102._refCount = 1;
            sjt_call102.count = 1;
            sjt_call102.data._refCount = 1;
            sjt_call102.data.datasize = 2;
            sjt_call102.data.data = (void*)sjg_string24;
            sjt_call102.data._isglobal = true;
            sjt_call102.data.count = 2;
            sjf_array_char(&sjt_call102.data);
            sjf_string(&sjt_call102);
            sjt_functionParam301 = &sjt_call102;
            sjf_string_add(sjt_parent198, sjt_functionParam301, &sjt_call96);
            sjt_parent197 = &sjt_call96;
            sjt_parent203 = &sjv_texture;
            sjf_vec2_asstring(sjt_parent203, &sjt_call103);
            sjt_functionParam302 = &sjt_call103;
            sjf_string_add(sjt_parent197, sjt_functionParam302, &sjt_call95);
            sjt_functionParam298 = &sjt_call95;
            sjf_debug_writeline(sjt_functionParam298);
            sjt_parent204 = &sjv_vertices;
            sjt_call104._refCount = 1;
            sjt_copy49 = &sjv_location;
            sjt_call104.location._refCount = 1;
            sjf_vec3_copy(&sjt_call104.location, sjt_copy49);
            sjt_copy50 = &sjv_texture;
            sjt_call104.texture._refCount = 1;
            sjf_vec2_copy(&sjt_call104.texture, sjt_copy50);
            sjt_copy51 = &sjv_normal;
            sjt_call104.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call104.normal, sjt_copy51);
            sjf_vertex_location_texture_normal(&sjt_call104);
            sjt_functionParam303 = &sjt_call104;
            sjf_list_vertex_location_texture_normal_add(sjt_parent204, sjt_functionParam303);
        }
    }
    delete_obj_data(&data);
    sjt_not6 = sjv_includenormals;
    result8 = !sjt_not6;
    sjt_ifElse46 = result8;
    if (sjt_ifElse46) {
        int32_t i;
        int32_t sjt_forEnd23;
        int32_t sjt_forEnd24;
        int32_t sjt_forEnd25;
        int32_t sjt_forStart23;
        int32_t sjt_forStart24;
        int32_t sjt_forStart25;
        int32_t sjt_math2283;
        int32_t sjt_math2284;
        sjs_list_vertex_location_texture_normal* sjt_parent205 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent206 = 0;
        sjs_list_i32* sjt_parent208 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent228 = 0;

        sjv_normals._refCount = 1;
        sjt_parent205 = &sjv_vertices;
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent205, &sjv_normals.datasize);
        sjv_normals.data = 0;
        sjv_normals._isglobal = false;
        sjv_normals.count = 0;
        sjf_array_vec3(&sjv_normals);
        sjt_forStart23 = 0;
        sjt_parent206 = &sjv_vertices;
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent206, &sjt_forEnd23);
        i = sjt_forStart23;
        while (i < sjt_forEnd23) {
            sjs_vec3 sjt_call105 = { -1 };
            int32_t sjt_functionParam304;
            sjs_vec3* sjt_functionParam305 = 0;
            sjs_array_vec3* sjt_parent207 = 0;

            sjt_parent207 = &sjv_normals;
            sjt_functionParam304 = i;
            sjt_call105._refCount = 1;
            sjt_call105.x = 0.0f;
            sjt_call105.y = 0.0f;
            sjt_call105.z = 0.0f;
            sjf_vec3(&sjt_call105);
            sjt_functionParam305 = &sjt_call105;
            sjf_array_vec3_initat(sjt_parent207, sjt_functionParam304, sjt_functionParam305);
            i++;

            if (sjt_call105._refCount == 1) { sjf_vec3_destroy(&sjt_call105); }
;
        }

        sjt_forStart24 = 0;
        sjt_parent208 = &sjv_indices;
        sjf_list_i32_getcount(sjt_parent208, &sjt_math2283);
        sjt_math2284 = 3;
        sjt_forEnd24 = sjt_math2283 / sjt_math2284;
        i = sjt_forStart24;
        while (i < sjt_forEnd24) {
            sjs_vertex_location_texture_normal sjt_call106 = { -1 };
            sjs_vertex_location_texture_normal sjt_call107 = { -1 };
            sjs_vertex_location_texture_normal sjt_call108 = { -1 };
            sjs_vec3 sjt_call109 = { -1 };
            sjs_vec3 sjt_call110 = { -1 };
            sjs_vec3 sjt_call111 = { -1 };
            sjs_vec3 sjt_call112 = { -1 };
            sjs_vec3 sjt_call113 = { -1 };
            sjs_vec3 sjt_call114 = { -1 };
            sjs_vec3 sjt_call115 = { -1 };
            sjs_vec3* sjt_copy52 = 0;
            sjs_vec3* sjt_copy53 = 0;
            sjs_vec3* sjt_copy54 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1559 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1560 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1561 = 0;
            int32_t sjt_functionParam306;
            int32_t sjt_functionParam307;
            int32_t sjt_functionParam308;
            int32_t sjt_functionParam309;
            int32_t sjt_functionParam310;
            int32_t sjt_functionParam311;
            sjs_vec3* sjt_functionParam312 = 0;
            sjs_vec3* sjt_functionParam313 = 0;
            sjs_vec3* sjt_functionParam314 = 0;
            int32_t sjt_functionParam315;
            sjs_vec3* sjt_functionParam316 = 0;
            int32_t sjt_functionParam317;
            sjs_vec3* sjt_functionParam318 = 0;
            int32_t sjt_functionParam319;
            sjs_vec3* sjt_functionParam320 = 0;
            int32_t sjt_functionParam321;
            sjs_vec3* sjt_functionParam322 = 0;
            int32_t sjt_functionParam323;
            sjs_vec3* sjt_functionParam324 = 0;
            int32_t sjt_functionParam325;
            sjs_vec3* sjt_functionParam326 = 0;
            int32_t sjt_math2285;
            int32_t sjt_math2286;
            int32_t sjt_math2287;
            int32_t sjt_math2288;
            int32_t sjt_math2289;
            int32_t sjt_math2290;
            int32_t sjt_math2291;
            int32_t sjt_math2292;
            int32_t sjt_math2293;
            int32_t sjt_math2294;
            int32_t sjt_math2295;
            int32_t sjt_math2296;
            sjs_list_i32* sjt_parent209 = 0;
            sjs_list_i32* sjt_parent210 = 0;
            sjs_list_i32* sjt_parent211 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent212 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent213 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent214 = 0;
            sjs_vec3* sjt_parent215 = 0;
            sjs_vec3* sjt_parent216 = 0;
            sjs_vec3* sjt_parent217 = 0;
            sjs_vec3* sjt_parent218 = 0;
            sjs_array_vec3* sjt_parent219 = 0;
            sjs_vec3* sjt_parent220 = 0;
            sjs_array_vec3* sjt_parent221 = 0;
            sjs_array_vec3* sjt_parent222 = 0;
            sjs_vec3* sjt_parent223 = 0;
            sjs_array_vec3* sjt_parent224 = 0;
            sjs_array_vec3* sjt_parent225 = 0;
            sjs_vec3* sjt_parent226 = 0;
            sjs_array_vec3* sjt_parent227 = 0;
            int32_t sjv_i1;
            int32_t sjv_i2;
            int32_t sjv_i3;
            sjs_vec3 sjv_newnormal = { -1 };
            sjs_vec3 sjv_side1 = { -1 };
            sjs_vec3 sjv_side2 = { -1 };
            sjs_vec3 sjv_v1 = { -1 };
            sjs_vec3 sjv_v2 = { -1 };
            sjs_vec3 sjv_v3 = { -1 };

            sjt_parent209 = &sjv_indices;
            sjt_math2287 = i;
            sjt_math2288 = 3;
            sjt_math2285 = sjt_math2287 * sjt_math2288;
            sjt_math2286 = 0;
            sjt_functionParam306 = sjt_math2285 + sjt_math2286;
            sjf_list_i32_getat(sjt_parent209, sjt_functionParam306, &sjv_i1);
            sjt_parent210 = &sjv_indices;
            sjt_math2291 = i;
            sjt_math2292 = 3;
            sjt_math2289 = sjt_math2291 * sjt_math2292;
            sjt_math2290 = 1;
            sjt_functionParam307 = sjt_math2289 + sjt_math2290;
            sjf_list_i32_getat(sjt_parent210, sjt_functionParam307, &sjv_i2);
            sjt_parent211 = &sjv_indices;
            sjt_math2295 = i;
            sjt_math2296 = 3;
            sjt_math2293 = sjt_math2295 * sjt_math2296;
            sjt_math2294 = 2;
            sjt_functionParam308 = sjt_math2293 + sjt_math2294;
            sjf_list_i32_getat(sjt_parent211, sjt_functionParam308, &sjv_i3);
            sjt_parent212 = &sjv_vertices;
            sjt_functionParam309 = sjv_i1;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent212, sjt_functionParam309, &sjt_call106);
            sjt_dot1559 = &sjt_call106;
            sjt_copy52 = &sjt_dot1559->location;
            sjv_v1._refCount = 1;
            sjf_vec3_copy(&sjv_v1, sjt_copy52);
            sjt_parent213 = &sjv_vertices;
            sjt_functionParam310 = sjv_i2;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent213, sjt_functionParam310, &sjt_call107);
            sjt_dot1560 = &sjt_call107;
            sjt_copy53 = &sjt_dot1560->location;
            sjv_v2._refCount = 1;
            sjf_vec3_copy(&sjv_v2, sjt_copy53);
            sjt_parent214 = &sjv_vertices;
            sjt_functionParam311 = sjv_i3;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent214, sjt_functionParam311, &sjt_call108);
            sjt_dot1561 = &sjt_call108;
            sjt_copy54 = &sjt_dot1561->location;
            sjv_v3._refCount = 1;
            sjf_vec3_copy(&sjv_v3, sjt_copy54);
            sjt_parent215 = &sjv_v2;
            sjt_functionParam312 = &sjv_v1;
            sjf_vec3_subtract(sjt_parent215, sjt_functionParam312, &sjv_side1);
            sjt_parent216 = &sjv_v3;
            sjt_functionParam313 = &sjv_v1;
            sjf_vec3_subtract(sjt_parent216, sjt_functionParam313, &sjv_side2);
            sjt_parent218 = &sjv_side2;
            sjt_functionParam314 = &sjv_side1;
            sjf_vec3_cross(sjt_parent218, sjt_functionParam314, &sjt_call109);
            sjt_parent217 = &sjt_call109;
            sjf_vec3_normalize(sjt_parent217, &sjv_newnormal);
            sjt_parent219 = &sjv_normals;
            sjt_functionParam315 = sjv_i1;
            sjt_parent221 = &sjv_normals;
            sjt_functionParam317 = sjv_i1;
            sjf_array_vec3_getat(sjt_parent221, sjt_functionParam317, &sjt_call111);
            sjt_parent220 = &sjt_call111;
            sjt_functionParam318 = &sjv_newnormal;
            sjf_vec3_add(sjt_parent220, sjt_functionParam318, &sjt_call110);
            sjt_functionParam316 = &sjt_call110;
            sjf_array_vec3_setat(sjt_parent219, sjt_functionParam315, sjt_functionParam316);
            sjt_parent222 = &sjv_normals;
            sjt_functionParam319 = sjv_i2;
            sjt_parent224 = &sjv_normals;
            sjt_functionParam321 = sjv_i2;
            sjf_array_vec3_getat(sjt_parent224, sjt_functionParam321, &sjt_call113);
            sjt_parent223 = &sjt_call113;
            sjt_functionParam322 = &sjv_newnormal;
            sjf_vec3_add(sjt_parent223, sjt_functionParam322, &sjt_call112);
            sjt_functionParam320 = &sjt_call112;
            sjf_array_vec3_setat(sjt_parent222, sjt_functionParam319, sjt_functionParam320);
            sjt_parent225 = &sjv_normals;
            sjt_functionParam323 = sjv_i3;
            sjt_parent227 = &sjv_normals;
            sjt_functionParam325 = sjv_i3;
            sjf_array_vec3_getat(sjt_parent227, sjt_functionParam325, &sjt_call115);
            sjt_parent226 = &sjt_call115;
            sjt_functionParam326 = &sjv_newnormal;
            sjf_vec3_add(sjt_parent226, sjt_functionParam326, &sjt_call114);
            sjt_functionParam324 = &sjt_call114;
            sjf_array_vec3_setat(sjt_parent225, sjt_functionParam323, sjt_functionParam324);
            i++;

            if (sjt_call106._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call106); }
;
            if (sjt_call107._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call107); }
;
            if (sjt_call108._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call108); }
;
            if (sjt_call109._refCount == 1) { sjf_vec3_destroy(&sjt_call109); }
;
            if (sjt_call110._refCount == 1) { sjf_vec3_destroy(&sjt_call110); }
;
            if (sjt_call111._refCount == 1) { sjf_vec3_destroy(&sjt_call111); }
;
            if (sjt_call112._refCount == 1) { sjf_vec3_destroy(&sjt_call112); }
;
            if (sjt_call113._refCount == 1) { sjf_vec3_destroy(&sjt_call113); }
;
            if (sjt_call114._refCount == 1) { sjf_vec3_destroy(&sjt_call114); }
;
            if (sjt_call115._refCount == 1) { sjf_vec3_destroy(&sjt_call115); }
;
            if (sjv_newnormal._refCount == 1) { sjf_vec3_destroy(&sjv_newnormal); }
;
            if (sjv_side1._refCount == 1) { sjf_vec3_destroy(&sjv_side1); }
;
            if (sjv_side2._refCount == 1) { sjf_vec3_destroy(&sjv_side2); }
;
            if (sjv_v1._refCount == 1) { sjf_vec3_destroy(&sjv_v1); }
;
            if (sjv_v2._refCount == 1) { sjf_vec3_destroy(&sjv_v2); }
;
            if (sjv_v3._refCount == 1) { sjf_vec3_destroy(&sjv_v3); }
;
        }

        sjt_forStart25 = 0;
        sjt_parent228 = &sjv_vertices;
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent228, &sjt_forEnd25);
        i = sjt_forStart25;
        while (i < sjt_forEnd25) {
            sjs_vec3 sjt_call116 = { -1 };
            sjs_vertex_location_texture_normal sjt_call117 = { -1 };
            sjs_vertex_location_texture_normal sjt_call118 = { -1 };
            sjs_vertex_location_texture_normal sjt_call119 = { -1 };
            sjs_vec3* sjt_copy55 = 0;
            sjs_vec2* sjt_copy56 = 0;
            sjs_vec3* sjt_copy57 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1562 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1563 = 0;
            int32_t sjt_functionParam327;
            int32_t sjt_functionParam328;
            sjs_vertex_location_texture_normal* sjt_functionParam329 = 0;
            int32_t sjt_functionParam330;
            int32_t sjt_functionParam331;
            sjs_vec3* sjt_parent229 = 0;
            sjs_array_vec3* sjt_parent230 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent231 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent232 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent233 = 0;
            sjs_vec3 sjv_newnormal = { -1 };

            sjt_parent230 = &sjv_normals;
            sjt_functionParam327 = i;
            sjf_array_vec3_getat(sjt_parent230, sjt_functionParam327, &sjt_call116);
            sjt_parent229 = &sjt_call116;
            sjf_vec3_normalize(sjt_parent229, &sjv_newnormal);
            sjt_parent231 = &sjv_vertices;
            sjt_functionParam328 = i;
            sjt_call117._refCount = 1;
            sjt_parent232 = &sjv_vertices;
            sjt_functionParam330 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent232, sjt_functionParam330, &sjt_call118);
            sjt_dot1562 = &sjt_call118;
            sjt_copy55 = &sjt_dot1562->location;
            sjt_call117.location._refCount = 1;
            sjf_vec3_copy(&sjt_call117.location, sjt_copy55);
            sjt_parent233 = &sjv_vertices;
            sjt_functionParam331 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent233, sjt_functionParam331, &sjt_call119);
            sjt_dot1563 = &sjt_call119;
            sjt_copy56 = &sjt_dot1563->texture;
            sjt_call117.texture._refCount = 1;
            sjf_vec2_copy(&sjt_call117.texture, sjt_copy56);
            sjt_copy57 = &sjv_newnormal;
            sjt_call117.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call117.normal, sjt_copy57);
            sjf_vertex_location_texture_normal(&sjt_call117);
            sjt_functionParam329 = &sjt_call117;
            sjf_list_vertex_location_texture_normal_setat(sjt_parent231, sjt_functionParam328, sjt_functionParam329);
            i++;

            if (sjt_call116._refCount == 1) { sjf_vec3_destroy(&sjt_call116); }
;
            if (sjt_call117._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call117); }
;
            if (sjt_call118._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call118); }
;
            if (sjt_call119._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call119); }
;
            if (sjv_newnormal._refCount == 1) { sjf_vec3_destroy(&sjv_newnormal); }
;
        }
    }

    sjt_not7 = sjv_includetextures;
    result9 = !sjt_not7;
    sjt_ifElse47 = result9;
    if (sjt_ifElse47) {
        int32_t i;
        int32_t sjt_forEnd26;
        int32_t sjt_forEnd27;
        int32_t sjt_forStart26;
        int32_t sjt_forStart27;
        sjs_list_vertex_location_texture_normal* sjt_parent234 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent237 = 0;
        float sjv_ymax;
        float sjv_ymin;

        sjv_ymin = 0.0f;
        sjv_ymax = 0.0f;
        sjt_forStart26 = 0;
        sjt_parent234 = &sjv_vertices;
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent234, &sjt_forEnd26);
        i = sjt_forStart26;
        while (i < sjt_forEnd26) {
            sjs_vertex_location_texture_normal sjt_call120 = { -1 };
            sjs_vertex_location_texture_normal sjt_call121 = { -1 };
            sjs_vec3* sjt_dot1564 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1565 = 0;
            sjs_vec3* sjt_dot1566 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1567 = 0;
            float sjt_funcold6;
            float sjt_funcold7;
            float sjt_functionParam332;
            float sjt_functionParam333;
            int32_t sjt_functionParam334;
            float sjt_functionParam335;
            float sjt_functionParam336;
            int32_t sjt_functionParam337;
            sjs_list_vertex_location_texture_normal* sjt_parent235 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent236 = 0;

            sjt_funcold6 = sjv_ymin;
            sjt_functionParam332 = sjv_ymin;
            sjt_parent235 = &sjv_vertices;
            sjt_functionParam334 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent235, sjt_functionParam334, &sjt_call120);
            sjt_dot1565 = &sjt_call120;
            sjt_dot1564 = &sjt_dot1565->location;
            sjt_functionParam333 = sjt_dot1564->y;
            sjf_f32_min(sjt_functionParam332, sjt_functionParam333, &sjv_ymin);
            sjt_funcold7 = sjv_ymax;
            sjt_functionParam335 = sjv_ymax;
            sjt_parent236 = &sjv_vertices;
            sjt_functionParam337 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent236, sjt_functionParam337, &sjt_call121);
            sjt_dot1567 = &sjt_call121;
            sjt_dot1566 = &sjt_dot1567->location;
            sjt_functionParam336 = sjt_dot1566->y;
            sjf_f32_max(sjt_functionParam335, sjt_functionParam336, &sjv_ymax);
            i++;

            if (sjt_call120._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call120); }
;
            if (sjt_call121._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call121); }
;
        }

        sjt_forStart27 = 0;
        sjt_parent237 = &sjv_vertices;
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent237, &sjt_forEnd27);
        i = sjt_forStart27;
        while (i < sjt_forEnd27) {
            sjs_vertex_location_texture_normal sjt_call122 = { -1 };
            sjs_vertex_location_texture_normal sjt_call123 = { -1 };
            sjs_vertex_location_texture_normal sjt_call124 = { -1 };
            sjs_vertex_location_texture_normal sjt_call125 = { -1 };
            sjs_vertex_location_texture_normal sjt_call126 = { -1 };
            sjs_vertex_location_texture_normal sjt_call127 = { -1 };
            sjs_vec3* sjt_copy58 = 0;
            sjs_vec3* sjt_copy59 = 0;
            sjs_vec3* sjt_dot1568 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1569 = 0;
            sjs_vec3* sjt_dot1570 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1571 = 0;
            sjs_vec3* sjt_dot1572 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1573 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1574 = 0;
            sjs_vertex_location_texture_normal* sjt_dot1575 = 0;
            float sjt_functionParam338;
            int32_t sjt_functionParam339;
            float sjt_functionParam340;
            int32_t sjt_functionParam341;
            int32_t sjt_functionParam342;
            int32_t sjt_functionParam343;
            sjs_vertex_location_texture_normal* sjt_functionParam344 = 0;
            int32_t sjt_functionParam345;
            int32_t sjt_functionParam346;
            float sjt_math2297;
            float sjt_math2298;
            float sjt_math2299;
            float sjt_math2300;
            float sjt_math2301;
            float sjt_math2302;
            float sjt_math2303;
            float sjt_math2304;
            float sjt_math2305;
            float sjt_math2306;
            float sjt_math2307;
            float sjt_math2308;
            sjs_list_vertex_location_texture_normal* sjt_parent238 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent239 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent240 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent241 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent242 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent243 = 0;
            float sjv_s;
            float sjv_t;

            sjt_parent238 = &sjv_vertices;
            sjt_functionParam339 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent238, sjt_functionParam339, &sjt_call122);
            sjt_dot1569 = &sjt_call122;
            sjt_dot1568 = &sjt_dot1569->location;
            sjt_functionParam338 = sjt_dot1568->x;
            sjt_parent239 = &sjv_vertices;
            sjt_functionParam341 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent239, sjt_functionParam341, &sjt_call123);
            sjt_dot1571 = &sjt_call123;
            sjt_dot1570 = &sjt_dot1571->location;
            sjt_functionParam340 = sjt_dot1570->z;
            sjf_f32_atan2(sjt_functionParam338, sjt_functionParam340, &sjt_math2299);
            sjt_math2300 = sjv_f32_pi;
            sjt_math2297 = sjt_math2299 + sjt_math2300;
            sjt_math2301 = 2.0f;
            sjt_math2302 = sjv_f32_pi;
            sjt_math2298 = sjt_math2301 * sjt_math2302;
            sjv_s = sjt_math2297 / sjt_math2298;
            sjt_parent240 = &sjv_vertices;
            sjt_functionParam342 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent240, sjt_functionParam342, &sjt_call124);
            sjt_dot1573 = &sjt_call124;
            sjt_dot1572 = &sjt_dot1573->location;
            sjt_math2305 = sjt_dot1572->y;
            sjt_math2306 = sjv_ymin;
            sjt_math2303 = sjt_math2305 - sjt_math2306;
            sjt_math2307 = sjv_ymax;
            sjt_math2308 = sjv_ymin;
            sjt_math2304 = sjt_math2307 - sjt_math2308;
            sjv_t = sjt_math2303 / sjt_math2304;
            sjt_parent241 = &sjv_vertices;
            sjt_functionParam343 = i;
            sjt_call125._refCount = 1;
            sjt_parent242 = &sjv_vertices;
            sjt_functionParam345 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent242, sjt_functionParam345, &sjt_call126);
            sjt_dot1574 = &sjt_call126;
            sjt_copy58 = &sjt_dot1574->location;
            sjt_call125.location._refCount = 1;
            sjf_vec3_copy(&sjt_call125.location, sjt_copy58);
            sjt_call125.texture._refCount = 1;
            sjt_call125.texture.x = sjv_s;
            sjt_call125.texture.y = sjv_t;
            sjf_vec2(&sjt_call125.texture);
            sjt_parent243 = &sjv_vertices;
            sjt_functionParam346 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent243, sjt_functionParam346, &sjt_call127);
            sjt_dot1575 = &sjt_call127;
            sjt_copy59 = &sjt_dot1575->normal;
            sjt_call125.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call125.normal, sjt_copy59);
            sjf_vertex_location_texture_normal(&sjt_call125);
            sjt_functionParam344 = &sjt_call125;
            sjf_list_vertex_location_texture_normal_setat(sjt_parent241, sjt_functionParam343, sjt_functionParam344);
            i++;

            if (sjt_call122._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call122); }
;
            if (sjt_call123._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call123); }
;
            if (sjt_call124._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call124); }
;
            if (sjt_call125._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call125); }
;
            if (sjt_call126._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call126); }
;
            if (sjt_call127._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call127); }
;
        }
    }

    (*_return) = (sjs_vertexbuffer_vertex_location_texture_normal*)malloc(sizeof(sjs_vertexbuffer_vertex_location_texture_normal));
    (*_return)->_refCount = 1;
    sjt_copy60 = &sjv_vertex_location_texture_normal_format;
    (*_return)->format._refCount = 1;
    sjf_string_copy(&(*_return)->format, sjt_copy60);
    sjt_dot1576 = &sjv_indices;
    sjt_copy61 = &sjt_dot1576->array;
    (*_return)->indices._refCount = 1;
    sjf_array_i32_copy(&(*_return)->indices, sjt_copy61);
    sjt_dot1577 = &sjv_vertices;
    sjt_copy62 = &sjt_dot1577->array;
    (*_return)->vertices._refCount = 1;
    sjf_array_vertex_location_texture_normal_copy(&(*_return)->vertices, sjt_copy62);
    sjf_vertexbuffer_vertex_location_texture_normal_heap((*_return));

    if (sjt_call100._refCount == 1) { sjf_string_destroy(&sjt_call100); }
;
    if (sjt_call101._refCount == 1) { sjf_string_destroy(&sjt_call101); }
;
    if (sjt_call102._refCount == 1) { sjf_string_destroy(&sjt_call102); }
;
    if (sjt_call103._refCount == 1) { sjf_string_destroy(&sjt_call103); }
;
    if (sjt_call104._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call104); }
;
    if (sjt_call95._refCount == 1) { sjf_string_destroy(&sjt_call95); }
;
    if (sjt_call96._refCount == 1) { sjf_string_destroy(&sjt_call96); }
;
    if (sjt_call97._refCount == 1) { sjf_string_destroy(&sjt_call97); }
;
    if (sjt_call98._refCount == 1) { sjf_string_destroy(&sjt_call98); }
;
    if (sjt_call99._refCount == 1) { sjf_string_destroy(&sjt_call99); }
;
    if (sjv_indices._refCount == 1) { sjf_list_i32_destroy(&sjv_indices); }
;
    if (sjv_location._refCount == 1) { sjf_vec3_destroy(&sjv_location); }
;
    if (sjv_normal._refCount == 1) { sjf_vec3_destroy(&sjv_normal); }
;
    if (sjv_normals._refCount == 1) { sjf_array_vec3_destroy(&sjv_normals); }
;
    if (sjv_texture._refCount == 1) { sjf_vec2_destroy(&sjv_texture); }
;
    if (sjv_vertices._refCount == 1) { sjf_list_vertex_location_texture_normal_destroy(&sjv_vertices); }
;
}

void sjf_vertexbuffer_vertex_location_texture_normal(sjs_vertexbuffer_vertex_location_texture_normal* _this) {
    _this->buffer = vertex_buffer_new((char*)_this->format.data.data);
    vertex_buffer_push_back_indices(_this->buffer, (GLuint*)_this->indices.data, _this->indices.count);
    int vertexSize;
    sjf_vertex_location_texture_normal_getrawsize(&vertexSize);
    int verticesSize = _this->vertices.count * vertexSize;
    char* t = malloc(verticesSize);
    char* buffer = t;
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_this->vertices.data;
    for (int i = 0; i < _this->vertices.count; i++) {
        sjf_vertex_location_texture_normal_rawcopy(&p[i], buffer, &buffer);
    }
    vertex_buffer_push_back_vertices(_this->buffer, t, _this->vertices.count);
    free(t);
}

void sjf_vertexbuffer_vertex_location_texture_normal_copy(sjs_vertexbuffer_vertex_location_texture_normal* _this, sjs_vertexbuffer_vertex_location_texture_normal* _from) {
    _this->format._refCount = 1;
    sjf_string_copy(&_this->format, &_from->format);
    _this->indices._refCount = 1;
    sjf_array_i32_copy(&_this->indices, &_from->indices);
    _this->vertices._refCount = 1;
    sjf_array_vertex_location_texture_normal_copy(&_this->vertices, &_from->vertices);
    _this->buffer = _from->buffer;
    ptr_retain(_this->buffer);
}

void sjf_vertexbuffer_vertex_location_texture_normal_destroy(sjs_vertexbuffer_vertex_location_texture_normal* _this) {
    if (ptr_release(_this->buffer)) {
        vertex_buffer_delete(_this->buffer);  
    }
    if (_this->format._refCount == 1) { sjf_string_destroy(&_this->format); }
;
    if (_this->indices._refCount == 1) { sjf_array_i32_destroy(&_this->indices); }
;
    if (_this->vertices._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&_this->vertices); }
;
}

void sjf_vertexbuffer_vertex_location_texture_normal_heap(sjs_vertexbuffer_vertex_location_texture_normal* _this) {
    _this->buffer = vertex_buffer_new((char*)_this->format.data.data);
    vertex_buffer_push_back_indices(_this->buffer, (GLuint*)_this->indices.data, _this->indices.count);
    int vertexSize;
    sjf_vertex_location_texture_normal_getrawsize(&vertexSize);
    int verticesSize = _this->vertices.count * vertexSize;
    char* t = malloc(verticesSize);
    char* buffer = t;
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_this->vertices.data;
    for (int i = 0; i < _this->vertices.count; i++) {
        sjf_vertex_location_texture_normal_rawcopy(&p[i], buffer, &buffer);
    }
    vertex_buffer_push_back_vertices(_this->buffer, t, _this->vertices.count);
    free(t);
}

void sjf_vertexbuffer_vertex_location_texture_normal_render(sjs_vertexbuffer_vertex_location_texture_normal* _parent) {
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
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
;
}

void sjf_windowrenderer_present(sjs_windowrenderer* _parent) {
    SDL_GL_SwapWindow((SDL_Window*)_parent->win);
}

int main(int argc, char** argv) {
    sjs_blureffect_effect_vtbl.destroy = (void(*)(void*))sjf_blureffect_destroy;
    sjs_blureffect_effect_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_blureffect_asinterface;
    sjs_blureffect_effect_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_blureffect_getrect;
    sjs_blureffect_effect_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_blureffect_getrect_heap;
    sjs_blureffect_effect_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*,cb_rect_void))sjf_blureffect_setrect;
    sjs_blureffect_effect_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*,cb_scene2d_void))sjf_blureffect_render;
    sjs_boxelement_element_vtbl.destroy = (void(*)(void*))sjf_boxelement_destroy;
    sjs_boxelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_boxelement_asinterface;
    sjs_boxelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_boxelement_getsize;
    sjs_boxelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_boxelement_getsize_heap;
    sjs_boxelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_boxelement_getrect;
    sjs_boxelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_boxelement_getrect_heap;
    sjs_boxelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_boxelement_setrect;
    sjs_boxelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_boxelement_render;
    sjs_boxelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_boxelement_firemouseevent;
    sjs_fadeeffect_effect_vtbl.destroy = (void(*)(void*))sjf_fadeeffect_destroy;
    sjs_fadeeffect_effect_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_fadeeffect_asinterface;
    sjs_fadeeffect_effect_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_fadeeffect_getrect;
    sjs_fadeeffect_effect_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_fadeeffect_getrect_heap;
    sjs_fadeeffect_effect_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*,cb_rect_void))sjf_fadeeffect_setrect;
    sjs_fadeeffect_effect_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*,cb_scene2d_void))sjf_fadeeffect_render;
    sjs_filllayout_element_vtbl.destroy = (void(*)(void*))sjf_filllayout_destroy;
    sjs_filllayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_filllayout_asinterface;
    sjs_filllayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_filllayout_getsize;
    sjs_filllayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_filllayout_getsize_heap;
    sjs_filllayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_filllayout_getrect;
    sjs_filllayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_filllayout_getrect_heap;
    sjs_filllayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrect;
    sjs_filllayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_render;
    sjs_filllayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_filllayout_firemouseevent;
    sjs_gridlayout_element_vtbl.destroy = (void(*)(void*))sjf_gridlayout_destroy;
    sjs_gridlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_gridlayout_asinterface;
    sjs_gridlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_gridlayout_getsize;
    sjs_gridlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_gridlayout_getsize_heap;
    sjs_gridlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_gridlayout_getrect;
    sjs_gridlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_gridlayout_getrect_heap;
    sjs_gridlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_gridlayout_setrect;
    sjs_gridlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_gridlayout_render;
    sjs_gridlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_gridlayout_firemouseevent;
    sjs_model_model_vtbl.destroy = (void(*)(void*))sjf_model_destroy;
    sjs_model_model_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_model_asinterface;
    sjs_model_model_vtbl.update = (void(*)(sjs_object*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_model_update;
    sjs_model_model_vtbl.getz = (void(*)(sjs_object*, float*))sjf_model_getz;
    sjs_model_model_vtbl.getcenter = (void(*)(sjs_object*, sjs_vec3*))sjf_model_getcenter;
    sjs_model_model_vtbl.getcenter_heap = (void(*)(sjs_object*, sjs_vec3**))sjf_model_getcenter_heap;
    sjs_model_model_vtbl.getworld = (void(*)(sjs_object*, sjs_mat4*))sjf_model_getworld;
    sjs_model_model_vtbl.getworld_heap = (void(*)(sjs_object*, sjs_mat4**))sjf_model_getworld_heap;
    sjs_model_model_vtbl.renderorqueue = (void(*)(sjs_object*,sjs_list_heap_iface_model*))sjf_model_renderorqueue;
    sjs_model_model_vtbl.render = (void(*)(sjs_object*))sjf_model_render;
    sjs_model_model_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_model_firemouseevent;
    sjs_saturateeffect_effect_vtbl.destroy = (void(*)(void*))sjf_saturateeffect_destroy;
    sjs_saturateeffect_effect_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_saturateeffect_asinterface;
    sjs_saturateeffect_effect_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_saturateeffect_getrect;
    sjs_saturateeffect_effect_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_saturateeffect_getrect_heap;
    sjs_saturateeffect_effect_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*,cb_rect_void))sjf_saturateeffect_setrect;
    sjs_saturateeffect_effect_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*,cb_scene2d_void))sjf_saturateeffect_render;
    sjs_scene3delement_element_vtbl.destroy = (void(*)(void*))sjf_scene3delement_destroy;
    sjs_scene3delement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_scene3delement_asinterface;
    sjs_scene3delement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_scene3delement_getsize;
    sjs_scene3delement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_scene3delement_getsize_heap;
    sjs_scene3delement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_scene3delement_getrect;
    sjs_scene3delement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_scene3delement_getrect_heap;
    sjs_scene3delement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_scene3delement_setrect;
    sjs_scene3delement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_scene3delement_render;
    sjs_scene3delement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_scene3delement_firemouseevent;
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
    sjf_animator(&sjv_animator);
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
    sjf_style(&sjv_style);
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
    sjt_call3 = (sjs_gridlayout*)malloc(sizeof(sjs_gridlayout));
    sjt_call3->_refCount = 1;
    sjt_call3->children._refCount = 1;
    sjt_call3->children.datasize = 4;
    sjt_call3->children.data = 0;
    sjt_call3->children._isglobal = false;
    sjt_call3->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call3->children);
    sjs_array_heap_iface_element* array8;
    array8 = &sjt_call3->children;
    sjt_parent28 = array8;
    sjt_functionParam39 = 0;
    sjt_call5 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
    sjt_call5->_refCount = 1;
    sjt_call5->children._refCount = 1;
    sjt_call5->children.datasize = 1;
    sjt_call5->children.data = 0;
    sjt_call5->children._isglobal = false;
    sjt_call5->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call5->children);
    sjs_array_heap_iface_element* array7;
    array7 = &sjt_call5->children;
    sjt_parent47 = array7;
    sjt_functionParam55 = 0;
    sjf_testscene_heap(&sjt_functionParam56);
    sjf_array_heap_iface_element_initat(sjt_parent47, sjt_functionParam55, sjt_functionParam56);
    sjt_call5->margin._refCount = 1;
    sjt_call5->margin.l = 10;
    sjt_call5->margin.t = 10;
    sjt_call5->margin.r = 10;
    sjt_call5->margin.b = 10;
    sjf_margin(&sjt_call5->margin);
    sjt_call5->effect._parent = 0;
    sjt_call5->_rect._refCount = 1;
    sjt_call5->_rect.x = 0;
    sjt_call5->_rect.y = 0;
    sjt_call5->_rect.w = 0;
    sjt_call5->_rect.h = 0;
    sjf_rect(&sjt_call5->_rect);
    sjf_filllayout_heap(sjt_call5);
    sjt_cast3 = sjt_call5;
    sjf_filllayout_as_sji_element(sjt_cast3, &sjt_functionParam40);
    if (sjt_functionParam40._parent != 0) {
        sjt_functionParam40._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent28, sjt_functionParam39, sjt_functionParam40);
    sjt_parent261 = array8;
    sjt_functionParam392 = 1;
    sjt_call139 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
    sjt_call139->_refCount = 1;
    sjt_call139->children._refCount = 1;
    sjt_call139->children.datasize = 1;
    sjt_call139->children.data = 0;
    sjt_call139->children._isglobal = false;
    sjt_call139->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call139->children);
    sjs_array_heap_iface_element* array9;
    array9 = &sjt_call139->children;
    sjt_parent262 = array9;
    sjt_functionParam394 = 0;
    sjf_testscene_heap(&sjt_functionParam395);
    sjf_array_heap_iface_element_initat(sjt_parent262, sjt_functionParam394, sjt_functionParam395);
    sjt_call139->margin._refCount = 1;
    sjt_call139->margin.l = 10;
    sjt_call139->margin.t = 10;
    sjt_call139->margin.r = 10;
    sjt_call139->margin.b = 10;
    sjf_margin(&sjt_call139->margin);
    sjt_call140 = (sjs_blureffect*)malloc(sizeof(sjs_blureffect));
    sjt_call140->_refCount = 1;
    sjt_call140->radius = 5.0f;
    sjt_call140->_rect._refCount = 1;
    sjt_call140->_rect.x = 0;
    sjt_call140->_rect.y = 0;
    sjt_call140->_rect.w = 0;
    sjt_call140->_rect.h = 0;
    sjf_rect(&sjt_call140->_rect);
    sjt_call140->_vertexbuffer1._refCount = -1;
    sjt_call140->_vertexbuffer2._refCount = -1;
    sjt_call140->_scenebuffer1._refCount = -1;
    sjt_call140->_scenebuffer2._refCount = -1;
    sjt_call140->_innerscene._refCount = 1;
    sjt_call140->_innerscene._size._refCount = 1;
    sjt_call140->_innerscene._size.w = 0;
    sjt_call140->_innerscene._size.h = 0;
    sjf_size(&sjt_call140->_innerscene._size);
    sjt_call140->_innerscene.model._refCount = 1;
    sjt_call140->_innerscene.model.m00 = 0.0f;
    sjt_call140->_innerscene.model.m01 = 0.0f;
    sjt_call140->_innerscene.model.m02 = 0.0f;
    sjt_call140->_innerscene.model.m03 = 0.0f;
    sjt_call140->_innerscene.model.m10 = 0.0f;
    sjt_call140->_innerscene.model.m11 = 0.0f;
    sjt_call140->_innerscene.model.m12 = 0.0f;
    sjt_call140->_innerscene.model.m13 = 0.0f;
    sjt_call140->_innerscene.model.m20 = 0.0f;
    sjt_call140->_innerscene.model.m21 = 0.0f;
    sjt_call140->_innerscene.model.m22 = 0.0f;
    sjt_call140->_innerscene.model.m23 = 0.0f;
    sjt_call140->_innerscene.model.m30 = 0.0f;
    sjt_call140->_innerscene.model.m31 = 0.0f;
    sjt_call140->_innerscene.model.m32 = 0.0f;
    sjt_call140->_innerscene.model.m33 = 0.0f;
    sjf_mat4(&sjt_call140->_innerscene.model);
    sjt_call140->_innerscene.view._refCount = 1;
    sjt_call140->_innerscene.view.m00 = 0.0f;
    sjt_call140->_innerscene.view.m01 = 0.0f;
    sjt_call140->_innerscene.view.m02 = 0.0f;
    sjt_call140->_innerscene.view.m03 = 0.0f;
    sjt_call140->_innerscene.view.m10 = 0.0f;
    sjt_call140->_innerscene.view.m11 = 0.0f;
    sjt_call140->_innerscene.view.m12 = 0.0f;
    sjt_call140->_innerscene.view.m13 = 0.0f;
    sjt_call140->_innerscene.view.m20 = 0.0f;
    sjt_call140->_innerscene.view.m21 = 0.0f;
    sjt_call140->_innerscene.view.m22 = 0.0f;
    sjt_call140->_innerscene.view.m23 = 0.0f;
    sjt_call140->_innerscene.view.m30 = 0.0f;
    sjt_call140->_innerscene.view.m31 = 0.0f;
    sjt_call140->_innerscene.view.m32 = 0.0f;
    sjt_call140->_innerscene.view.m33 = 0.0f;
    sjf_mat4(&sjt_call140->_innerscene.view);
    sjt_call140->_innerscene.projection._refCount = 1;
    sjt_call140->_innerscene.projection.m00 = 0.0f;
    sjt_call140->_innerscene.projection.m01 = 0.0f;
    sjt_call140->_innerscene.projection.m02 = 0.0f;
    sjt_call140->_innerscene.projection.m03 = 0.0f;
    sjt_call140->_innerscene.projection.m10 = 0.0f;
    sjt_call140->_innerscene.projection.m11 = 0.0f;
    sjt_call140->_innerscene.projection.m12 = 0.0f;
    sjt_call140->_innerscene.projection.m13 = 0.0f;
    sjt_call140->_innerscene.projection.m20 = 0.0f;
    sjt_call140->_innerscene.projection.m21 = 0.0f;
    sjt_call140->_innerscene.projection.m22 = 0.0f;
    sjt_call140->_innerscene.projection.m23 = 0.0f;
    sjt_call140->_innerscene.projection.m30 = 0.0f;
    sjt_call140->_innerscene.projection.m31 = 0.0f;
    sjt_call140->_innerscene.projection.m32 = 0.0f;
    sjt_call140->_innerscene.projection.m33 = 0.0f;
    sjf_mat4(&sjt_call140->_innerscene.projection);
    sjt_call140->_innerscene.windowrect._refCount = 1;
    sjt_call140->_innerscene.windowrect.x = 0;
    sjt_call140->_innerscene.windowrect.y = 0;
    sjt_call140->_innerscene.windowrect.w = 0;
    sjt_call140->_innerscene.windowrect.h = 0;
    sjf_rect(&sjt_call140->_innerscene.windowrect);
    sjf_scene2d(&sjt_call140->_innerscene);
    sjf_blureffect_heap(sjt_call140);
    sjt_cast17 = sjt_call140;
    sjf_blureffect_as_sji_effect(sjt_cast17, &sjt_value1);
    if (sjt_value1._parent != 0) {
        sjt_value1._parent->_refCount++;
    }

    sjt_call139->effect = sjt_value1;
    if (sjt_call139->effect._parent != 0) {
        sjt_call139->effect._parent->_refCount++;
    }

    sjt_call139->_rect._refCount = 1;
    sjt_call139->_rect.x = 0;
    sjt_call139->_rect.y = 0;
    sjt_call139->_rect.w = 0;
    sjt_call139->_rect.h = 0;
    sjf_rect(&sjt_call139->_rect);
    sjf_filllayout_heap(sjt_call139);
    sjt_cast16 = sjt_call139;
    sjf_filllayout_as_sji_element(sjt_cast16, &sjt_functionParam393);
    if (sjt_functionParam393._parent != 0) {
        sjt_functionParam393._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent261, sjt_functionParam392, sjt_functionParam393);
    sjt_parent286 = array8;
    sjt_functionParam564 = 2;
    sjt_call174 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
    sjt_call174->_refCount = 1;
    sjt_call174->children._refCount = 1;
    sjt_call174->children.datasize = 1;
    sjt_call174->children.data = 0;
    sjt_call174->children._isglobal = false;
    sjt_call174->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call174->children);
    sjs_array_heap_iface_element* array10;
    array10 = &sjt_call174->children;
    sjt_parent287 = array10;
    sjt_functionParam566 = 0;
    sjf_testscene_heap(&sjt_functionParam567);
    sjf_array_heap_iface_element_initat(sjt_parent287, sjt_functionParam566, sjt_functionParam567);
    sjt_call174->margin._refCount = 1;
    sjt_call174->margin.l = 10;
    sjt_call174->margin.t = 10;
    sjt_call174->margin.r = 10;
    sjt_call174->margin.b = 10;
    sjf_margin(&sjt_call174->margin);
    sjt_call175 = (sjs_fadeeffect*)malloc(sizeof(sjs_fadeeffect));
    sjt_call175->_refCount = 1;
    sjt_call175->alpha = 0.5f;
    sjt_call175->_rect._refCount = 1;
    sjt_call175->_rect.x = 0;
    sjt_call175->_rect.y = 0;
    sjt_call175->_rect.w = 0;
    sjt_call175->_rect.h = 0;
    sjf_rect(&sjt_call175->_rect);
    sjt_call175->_vertexbuffer._refCount = -1;
    sjt_call175->_scenebuffer._refCount = -1;
    sjt_call175->_innerscene._refCount = 1;
    sjt_call175->_innerscene._size._refCount = 1;
    sjt_call175->_innerscene._size.w = 0;
    sjt_call175->_innerscene._size.h = 0;
    sjf_size(&sjt_call175->_innerscene._size);
    sjt_call175->_innerscene.model._refCount = 1;
    sjt_call175->_innerscene.model.m00 = 0.0f;
    sjt_call175->_innerscene.model.m01 = 0.0f;
    sjt_call175->_innerscene.model.m02 = 0.0f;
    sjt_call175->_innerscene.model.m03 = 0.0f;
    sjt_call175->_innerscene.model.m10 = 0.0f;
    sjt_call175->_innerscene.model.m11 = 0.0f;
    sjt_call175->_innerscene.model.m12 = 0.0f;
    sjt_call175->_innerscene.model.m13 = 0.0f;
    sjt_call175->_innerscene.model.m20 = 0.0f;
    sjt_call175->_innerscene.model.m21 = 0.0f;
    sjt_call175->_innerscene.model.m22 = 0.0f;
    sjt_call175->_innerscene.model.m23 = 0.0f;
    sjt_call175->_innerscene.model.m30 = 0.0f;
    sjt_call175->_innerscene.model.m31 = 0.0f;
    sjt_call175->_innerscene.model.m32 = 0.0f;
    sjt_call175->_innerscene.model.m33 = 0.0f;
    sjf_mat4(&sjt_call175->_innerscene.model);
    sjt_call175->_innerscene.view._refCount = 1;
    sjt_call175->_innerscene.view.m00 = 0.0f;
    sjt_call175->_innerscene.view.m01 = 0.0f;
    sjt_call175->_innerscene.view.m02 = 0.0f;
    sjt_call175->_innerscene.view.m03 = 0.0f;
    sjt_call175->_innerscene.view.m10 = 0.0f;
    sjt_call175->_innerscene.view.m11 = 0.0f;
    sjt_call175->_innerscene.view.m12 = 0.0f;
    sjt_call175->_innerscene.view.m13 = 0.0f;
    sjt_call175->_innerscene.view.m20 = 0.0f;
    sjt_call175->_innerscene.view.m21 = 0.0f;
    sjt_call175->_innerscene.view.m22 = 0.0f;
    sjt_call175->_innerscene.view.m23 = 0.0f;
    sjt_call175->_innerscene.view.m30 = 0.0f;
    sjt_call175->_innerscene.view.m31 = 0.0f;
    sjt_call175->_innerscene.view.m32 = 0.0f;
    sjt_call175->_innerscene.view.m33 = 0.0f;
    sjf_mat4(&sjt_call175->_innerscene.view);
    sjt_call175->_innerscene.projection._refCount = 1;
    sjt_call175->_innerscene.projection.m00 = 0.0f;
    sjt_call175->_innerscene.projection.m01 = 0.0f;
    sjt_call175->_innerscene.projection.m02 = 0.0f;
    sjt_call175->_innerscene.projection.m03 = 0.0f;
    sjt_call175->_innerscene.projection.m10 = 0.0f;
    sjt_call175->_innerscene.projection.m11 = 0.0f;
    sjt_call175->_innerscene.projection.m12 = 0.0f;
    sjt_call175->_innerscene.projection.m13 = 0.0f;
    sjt_call175->_innerscene.projection.m20 = 0.0f;
    sjt_call175->_innerscene.projection.m21 = 0.0f;
    sjt_call175->_innerscene.projection.m22 = 0.0f;
    sjt_call175->_innerscene.projection.m23 = 0.0f;
    sjt_call175->_innerscene.projection.m30 = 0.0f;
    sjt_call175->_innerscene.projection.m31 = 0.0f;
    sjt_call175->_innerscene.projection.m32 = 0.0f;
    sjt_call175->_innerscene.projection.m33 = 0.0f;
    sjf_mat4(&sjt_call175->_innerscene.projection);
    sjt_call175->_innerscene.windowrect._refCount = 1;
    sjt_call175->_innerscene.windowrect.x = 0;
    sjt_call175->_innerscene.windowrect.y = 0;
    sjt_call175->_innerscene.windowrect.w = 0;
    sjt_call175->_innerscene.windowrect.h = 0;
    sjf_rect(&sjt_call175->_innerscene.windowrect);
    sjf_scene2d(&sjt_call175->_innerscene);
    sjf_fadeeffect_heap(sjt_call175);
    sjt_cast23 = sjt_call175;
    sjf_fadeeffect_as_sji_effect(sjt_cast23, &sjt_value2);
    if (sjt_value2._parent != 0) {
        sjt_value2._parent->_refCount++;
    }

    sjt_call174->effect = sjt_value2;
    if (sjt_call174->effect._parent != 0) {
        sjt_call174->effect._parent->_refCount++;
    }

    sjt_call174->_rect._refCount = 1;
    sjt_call174->_rect.x = 0;
    sjt_call174->_rect.y = 0;
    sjt_call174->_rect.w = 0;
    sjt_call174->_rect.h = 0;
    sjf_rect(&sjt_call174->_rect);
    sjf_filllayout_heap(sjt_call174);
    sjt_cast22 = sjt_call174;
    sjf_filllayout_as_sji_element(sjt_cast22, &sjt_functionParam565);
    if (sjt_functionParam565._parent != 0) {
        sjt_functionParam565._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent286, sjt_functionParam564, sjt_functionParam565);
    sjt_parent294 = array8;
    sjt_functionParam601 = 3;
    sjt_call185 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
    sjt_call185->_refCount = 1;
    sjt_call185->children._refCount = 1;
    sjt_call185->children.datasize = 1;
    sjt_call185->children.data = 0;
    sjt_call185->children._isglobal = false;
    sjt_call185->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call185->children);
    sjs_array_heap_iface_element* array11;
    array11 = &sjt_call185->children;
    sjt_parent295 = array11;
    sjt_functionParam603 = 0;
    sjf_testscene_heap(&sjt_functionParam604);
    sjf_array_heap_iface_element_initat(sjt_parent295, sjt_functionParam603, sjt_functionParam604);
    sjt_call185->margin._refCount = 1;
    sjt_call185->margin.l = 10;
    sjt_call185->margin.t = 10;
    sjt_call185->margin.r = 10;
    sjt_call185->margin.b = 10;
    sjf_margin(&sjt_call185->margin);
    sjt_call186 = (sjs_saturateeffect*)malloc(sizeof(sjs_saturateeffect));
    sjt_call186->_refCount = 1;
    sjt_call186->amount = 0.2f;
    sjt_call186->_rect._refCount = 1;
    sjt_call186->_rect.x = 0;
    sjt_call186->_rect.y = 0;
    sjt_call186->_rect.w = 0;
    sjt_call186->_rect.h = 0;
    sjf_rect(&sjt_call186->_rect);
    sjt_call186->_vertexbuffer._refCount = -1;
    sjt_call186->_scenebuffer._refCount = -1;
    sjt_call186->_innerscene._refCount = 1;
    sjt_call186->_innerscene._size._refCount = 1;
    sjt_call186->_innerscene._size.w = 0;
    sjt_call186->_innerscene._size.h = 0;
    sjf_size(&sjt_call186->_innerscene._size);
    sjt_call186->_innerscene.model._refCount = 1;
    sjt_call186->_innerscene.model.m00 = 0.0f;
    sjt_call186->_innerscene.model.m01 = 0.0f;
    sjt_call186->_innerscene.model.m02 = 0.0f;
    sjt_call186->_innerscene.model.m03 = 0.0f;
    sjt_call186->_innerscene.model.m10 = 0.0f;
    sjt_call186->_innerscene.model.m11 = 0.0f;
    sjt_call186->_innerscene.model.m12 = 0.0f;
    sjt_call186->_innerscene.model.m13 = 0.0f;
    sjt_call186->_innerscene.model.m20 = 0.0f;
    sjt_call186->_innerscene.model.m21 = 0.0f;
    sjt_call186->_innerscene.model.m22 = 0.0f;
    sjt_call186->_innerscene.model.m23 = 0.0f;
    sjt_call186->_innerscene.model.m30 = 0.0f;
    sjt_call186->_innerscene.model.m31 = 0.0f;
    sjt_call186->_innerscene.model.m32 = 0.0f;
    sjt_call186->_innerscene.model.m33 = 0.0f;
    sjf_mat4(&sjt_call186->_innerscene.model);
    sjt_call186->_innerscene.view._refCount = 1;
    sjt_call186->_innerscene.view.m00 = 0.0f;
    sjt_call186->_innerscene.view.m01 = 0.0f;
    sjt_call186->_innerscene.view.m02 = 0.0f;
    sjt_call186->_innerscene.view.m03 = 0.0f;
    sjt_call186->_innerscene.view.m10 = 0.0f;
    sjt_call186->_innerscene.view.m11 = 0.0f;
    sjt_call186->_innerscene.view.m12 = 0.0f;
    sjt_call186->_innerscene.view.m13 = 0.0f;
    sjt_call186->_innerscene.view.m20 = 0.0f;
    sjt_call186->_innerscene.view.m21 = 0.0f;
    sjt_call186->_innerscene.view.m22 = 0.0f;
    sjt_call186->_innerscene.view.m23 = 0.0f;
    sjt_call186->_innerscene.view.m30 = 0.0f;
    sjt_call186->_innerscene.view.m31 = 0.0f;
    sjt_call186->_innerscene.view.m32 = 0.0f;
    sjt_call186->_innerscene.view.m33 = 0.0f;
    sjf_mat4(&sjt_call186->_innerscene.view);
    sjt_call186->_innerscene.projection._refCount = 1;
    sjt_call186->_innerscene.projection.m00 = 0.0f;
    sjt_call186->_innerscene.projection.m01 = 0.0f;
    sjt_call186->_innerscene.projection.m02 = 0.0f;
    sjt_call186->_innerscene.projection.m03 = 0.0f;
    sjt_call186->_innerscene.projection.m10 = 0.0f;
    sjt_call186->_innerscene.projection.m11 = 0.0f;
    sjt_call186->_innerscene.projection.m12 = 0.0f;
    sjt_call186->_innerscene.projection.m13 = 0.0f;
    sjt_call186->_innerscene.projection.m20 = 0.0f;
    sjt_call186->_innerscene.projection.m21 = 0.0f;
    sjt_call186->_innerscene.projection.m22 = 0.0f;
    sjt_call186->_innerscene.projection.m23 = 0.0f;
    sjt_call186->_innerscene.projection.m30 = 0.0f;
    sjt_call186->_innerscene.projection.m31 = 0.0f;
    sjt_call186->_innerscene.projection.m32 = 0.0f;
    sjt_call186->_innerscene.projection.m33 = 0.0f;
    sjf_mat4(&sjt_call186->_innerscene.projection);
    sjt_call186->_innerscene.windowrect._refCount = 1;
    sjt_call186->_innerscene.windowrect.x = 0;
    sjt_call186->_innerscene.windowrect.y = 0;
    sjt_call186->_innerscene.windowrect.w = 0;
    sjt_call186->_innerscene.windowrect.h = 0;
    sjf_rect(&sjt_call186->_innerscene.windowrect);
    sjf_scene2d(&sjt_call186->_innerscene);
    sjf_saturateeffect_heap(sjt_call186);
    sjt_cast25 = sjt_call186;
    sjf_saturateeffect_as_sji_effect(sjt_cast25, &sjt_value3);
    if (sjt_value3._parent != 0) {
        sjt_value3._parent->_refCount++;
    }

    sjt_call185->effect = sjt_value3;
    if (sjt_call185->effect._parent != 0) {
        sjt_call185->effect._parent->_refCount++;
    }

    sjt_call185->_rect._refCount = 1;
    sjt_call185->_rect.x = 0;
    sjt_call185->_rect.y = 0;
    sjt_call185->_rect.w = 0;
    sjt_call185->_rect.h = 0;
    sjf_rect(&sjt_call185->_rect);
    sjf_filllayout_heap(sjt_call185);
    sjt_cast24 = sjt_call185;
    sjf_filllayout_as_sji_element(sjt_cast24, &sjt_functionParam602);
    if (sjt_functionParam602._parent != 0) {
        sjt_functionParam602._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent294, sjt_functionParam601, sjt_functionParam602);
    sjt_call3->margin._refCount = 1;
    sjt_call3->margin.l = 0;
    sjt_call3->margin.t = 0;
    sjt_call3->margin.r = 0;
    sjt_call3->margin.b = 0;
    sjf_margin(&sjt_call3->margin);
    sjt_call3->cols._refCount = 1;
    sjt_call3->cols.datasize = 2;
    sjt_call3->cols.data = 0;
    sjt_call3->cols._isglobal = false;
    sjt_call3->cols.count = 0;
    sjf_array_gridunit(&sjt_call3->cols);
    sjs_array_gridunit* array1;
    array1 = &sjt_call3->cols;
    sjt_parent302 = array1;
    sjt_functionParam638 = 0;
    sjt_call196._refCount = 1;
    sjt_call196.amount = 1;
    sjt_call196.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call196);
    sjt_functionParam639 = &sjt_call196;
    sjf_array_gridunit_initat(sjt_parent302, sjt_functionParam638, sjt_functionParam639);
    sjt_parent303 = array1;
    sjt_functionParam640 = 1;
    sjt_call197._refCount = 1;
    sjt_call197.amount = 1;
    sjt_call197.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call197);
    sjt_functionParam641 = &sjt_call197;
    sjf_array_gridunit_initat(sjt_parent303, sjt_functionParam640, sjt_functionParam641);
    sjt_call3->rows._refCount = 1;
    sjt_call3->rows.datasize = 2;
    sjt_call3->rows.data = 0;
    sjt_call3->rows._isglobal = false;
    sjt_call3->rows.count = 0;
    sjf_array_gridunit(&sjt_call3->rows);
    sjs_array_gridunit* array2;
    array2 = &sjt_call3->rows;
    sjt_parent304 = array2;
    sjt_functionParam642 = 0;
    sjt_call198._refCount = 1;
    sjt_call198.amount = 1;
    sjt_call198.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call198);
    sjt_functionParam643 = &sjt_call198;
    sjf_array_gridunit_initat(sjt_parent304, sjt_functionParam642, sjt_functionParam643);
    sjt_parent305 = array2;
    sjt_functionParam644 = 1;
    sjt_call199._refCount = 1;
    sjt_call199.amount = 1;
    sjt_call199.type = sjv_gridunittype_star;
    sjf_gridunit(&sjt_call199);
    sjt_functionParam645 = &sjt_call199;
    sjf_array_gridunit_initat(sjt_parent305, sjt_functionParam644, sjt_functionParam645);
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

    sjt_call139->_refCount--;
    if (sjt_call139->_refCount <= 0) {
        weakptr_release(sjt_call139);
        sjf_filllayout_destroy(sjt_call139);
        free(sjt_call139);
    }
    sjt_call140->_refCount--;
    if (sjt_call140->_refCount <= 0) {
        weakptr_release(sjt_call140);
        sjf_blureffect_destroy(sjt_call140);
        free(sjt_call140);
    }
    sjt_call174->_refCount--;
    if (sjt_call174->_refCount <= 0) {
        weakptr_release(sjt_call174);
        sjf_filllayout_destroy(sjt_call174);
        free(sjt_call174);
    }
    sjt_call175->_refCount--;
    if (sjt_call175->_refCount <= 0) {
        weakptr_release(sjt_call175);
        sjf_fadeeffect_destroy(sjt_call175);
        free(sjt_call175);
    }
    sjt_call185->_refCount--;
    if (sjt_call185->_refCount <= 0) {
        weakptr_release(sjt_call185);
        sjf_filllayout_destroy(sjt_call185);
        free(sjt_call185);
    }
    sjt_call186->_refCount--;
    if (sjt_call186->_refCount <= 0) {
        weakptr_release(sjt_call186);
        sjf_saturateeffect_destroy(sjt_call186);
        free(sjt_call186);
    }
    sjt_call3->_refCount--;
    if (sjt_call3->_refCount <= 0) {
        weakptr_release(sjt_call3);
        sjf_gridlayout_destroy(sjt_call3);
        free(sjt_call3);
    }
    sjt_call5->_refCount--;
    if (sjt_call5->_refCount <= 0) {
        weakptr_release(sjt_call5);
        sjf_filllayout_destroy(sjt_call5);
        free(sjt_call5);
    }
    if (sjt_functionParam393._parent != 0) {
        sjt_functionParam393._parent->_refCount--;
        if (sjt_functionParam393._parent->_refCount <= 0) {
            sjt_functionParam393._vtbl->destroy(sjt_functionParam393._parent);
            free(sjt_functionParam393._parent);
        }
    }
    if (sjt_functionParam395._parent != 0) {
        sjt_functionParam395._parent->_refCount--;
        if (sjt_functionParam395._parent->_refCount <= 0) {
            sjt_functionParam395._vtbl->destroy(sjt_functionParam395._parent);
            free(sjt_functionParam395._parent);
        }
    }
    if (sjt_functionParam40._parent != 0) {
        sjt_functionParam40._parent->_refCount--;
        if (sjt_functionParam40._parent->_refCount <= 0) {
            sjt_functionParam40._vtbl->destroy(sjt_functionParam40._parent);
            free(sjt_functionParam40._parent);
        }
    }
    if (sjt_functionParam56._parent != 0) {
        sjt_functionParam56._parent->_refCount--;
        if (sjt_functionParam56._parent->_refCount <= 0) {
            sjt_functionParam56._vtbl->destroy(sjt_functionParam56._parent);
            free(sjt_functionParam56._parent);
        }
    }
    if (sjt_functionParam565._parent != 0) {
        sjt_functionParam565._parent->_refCount--;
        if (sjt_functionParam565._parent->_refCount <= 0) {
            sjt_functionParam565._vtbl->destroy(sjt_functionParam565._parent);
            free(sjt_functionParam565._parent);
        }
    }
    if (sjt_functionParam567._parent != 0) {
        sjt_functionParam567._parent->_refCount--;
        if (sjt_functionParam567._parent->_refCount <= 0) {
            sjt_functionParam567._vtbl->destroy(sjt_functionParam567._parent);
            free(sjt_functionParam567._parent);
        }
    }
    if (sjt_functionParam602._parent != 0) {
        sjt_functionParam602._parent->_refCount--;
        if (sjt_functionParam602._parent->_refCount <= 0) {
            sjt_functionParam602._vtbl->destroy(sjt_functionParam602._parent);
            free(sjt_functionParam602._parent);
        }
    }
    if (sjt_functionParam604._parent != 0) {
        sjt_functionParam604._parent->_refCount--;
        if (sjt_functionParam604._parent->_refCount <= 0) {
            sjt_functionParam604._vtbl->destroy(sjt_functionParam604._parent);
            free(sjt_functionParam604._parent);
        }
    }
    if (sjt_value1._parent != 0) {
        sjt_value1._parent->_refCount--;
        if (sjt_value1._parent->_refCount <= 0) {
            sjt_value1._vtbl->destroy(sjt_value1._parent);
            free(sjt_value1._parent);
        }
    }
    if (sjt_value2._parent != 0) {
        sjt_value2._parent->_refCount--;
        if (sjt_value2._parent->_refCount <= 0) {
            sjt_value2._vtbl->destroy(sjt_value2._parent);
            free(sjt_value2._parent);
        }
    }
    if (sjt_value3._parent != 0) {
        sjt_value3._parent->_refCount--;
        if (sjt_value3._parent->_refCount <= 0) {
            sjt_value3._vtbl->destroy(sjt_value3._parent);
            free(sjt_value3._parent);
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
    if (sjt_call196._refCount == 1) { sjf_gridunit_destroy(&sjt_call196); }
;
    if (sjt_call197._refCount == 1) { sjf_gridunit_destroy(&sjt_call197); }
;
    if (sjt_call198._refCount == 1) { sjf_gridunit_destroy(&sjt_call198); }
;
    if (sjt_call199._refCount == 1) { sjf_gridunit_destroy(&sjt_call199); }
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
