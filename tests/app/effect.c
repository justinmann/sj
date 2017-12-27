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
const char* sjg_string38 = "FPS: ";
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
#define sjs_log_typeId 1
#define sjs_windowrenderer_typeId 2
#define sjs_color_typeId 3
#define sjs_size_typeId 4
#define sjs_mat4_typeId 5
#define sjs_rect_typeId 6
#define sjs_scene2d_typeId 7
#define sjs_array_char_typeId 8
#define sjs_string_typeId 9
#define sjs_vec3_typeId 10
#define sjs_light_typeId 11
#define sji_model_typeId 12
#define sjs_array_heap_iface_model_typeId 13
#define sjs_list_heap_iface_model_typeId 14
#define sjs_point_typeId 15
#define sjs_mouseevent_typeId 16
#define sji_model_vtbl_typeId 17
#define sjs_hash_string_weak_iface_model_typeId 18
#define sji_element_vtbl_typeId 19
#define sji_element_typeId 20
#define sjs_hash_string_weak_iface_element_typeId 21
#define sjs_array_heap_iface_animation_typeId 22
#define sjs_list_heap_iface_animation_typeId 23
#define sjs_animator_typeId 24
#define sji_animation_vtbl_typeId 25
#define sji_animation_typeId 26
#define sjs_shader_typeId 27
#define sjs_fontkey_typeId 28
#define sjs_font_typeId 29
#define sjs_hash_fontkey_weak_font_typeId 30
#define sjs_array_rect_typeId 31
#define sjs_list_rect_typeId 32
#define sjs_array_u32_typeId 33
#define sjs_list_u32_typeId 34
#define sjs_style_typeId 35
#define sjs_array_heap_iface_element_typeId 36
#define sjs_margin_typeId 37
#define sjs_array_gridunit_typeId 38
#define sjs_gridlayout_typeId 39
#define sjs_gridunit_typeId 40
#define sjs_array_i32_typeId 41
#define sji_gridchild_vtbl_typeId 42
#define sji_gridchild_typeId 43
#define sji_effect_vtbl_typeId 44
#define sji_effect_typeId 45
#define sjs_filllayout_typeId 46
#define cb_rect_void_typeId 47
#define cb_rect_void_heap_typeId 48
#define cb_scene2d_void_typeId 49
#define cb_scene2d_void_heap_typeId 50
#define sjs_boxrenderer_typeId 51
#define sjs_boxelement_typeId 52
#define sjs_scene3delement_typeId 53
#define cb_heap_iface_model_heap_iface_model_i32_typeId 54
#define cb_heap_iface_model_heap_iface_model_i32_heap_typeId 55
#define cb_local_iface_model_local_iface_model_i32_typeId 56
#define cb_local_iface_model_local_iface_model_i32_heap_typeId 57
#define sjs_array_vertex_location_texture_normal_typeId 58
#define sjs_vertexbuffer_vertex_location_texture_normal_typeId 59
#define sjs_texture_typeId 60
#define sjs_model_typeId 61
#define sjs_vec2_typeId 62
#define sjs_vertex_location_texture_normal_typeId 63
#define sjs_vec4_typeId 64
#define sjs_list_i32_typeId 65
#define sjs_list_vertex_location_texture_normal_typeId 66
#define sjs_array_vec3_typeId 67
#define sjs_textrenderer_typeId 68
#define sjs_textelement_typeId 69
#define sji_textelement_vtbl_typeId 70
#define sji_textelement_typeId 71
#define sjs_boxvertexbuffer_typeId 72
#define sjs_framebuffer_typeId 73
#define sjs_renderbuffer_typeId 74
#define sjs_scenebuffer_typeId 75
#define sjs_blureffect_typeId 76
#define sjs_fadeeffect_typeId 77
#define sjs_saturateeffect_typeId 78

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

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
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
sjs_log sjv_log = { -1 };
sjs_rect sjv_looplastrect = { -1 };
int32_t sjv_mainloop_frames;
int32_t sjv_mainloop_lasttick;
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
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
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
    int32_t sjt_capture50;
    sjs_list_heap_iface_animation* sjt_parent306 = 0;

    _parent->current = time;
    sjt_parent306 = &_parent->animations;
    sjf_list_heap_iface_animation_getcount(sjt_parent306, &sjt_capture50);
    if ((sjt_capture50 > 0)) {
        int32_t i;
        int32_t sjt_forEnd28;
        int32_t sjt_forStart28;
        sjs_list_heap_iface_animation* sjt_parent307 = 0;

        sjt_forStart28 = 0;
        sjt_parent307 = &_parent->animations;
        sjf_list_heap_iface_animation_getcount(sjt_parent307, &sjt_forEnd28);
        i = sjt_forEnd28 - 1;
        while (i >= sjt_forStart28) {
            bool sjt_capture51;
            int32_t sjt_functionParam647;
            int32_t sjt_interfaceParam19;
            sjs_list_heap_iface_animation* sjt_parent309 = 0;
            sji_animation sjt_parent310 = { 0 };
            sji_animation sjv_a = { 0 };

            sjt_parent309 = &_parent->animations;
            sjt_functionParam647 = i;
            sjf_list_heap_iface_animation_getat_heap(sjt_parent309, sjt_functionParam647, &sjv_a);
            sjt_parent310 = sjv_a;
            sjt_interfaceParam19 = time;
            sjt_parent310._vtbl->nextframe(sjt_parent310._parent, sjt_interfaceParam19, &sjt_capture51);
            if (sjt_capture51) {
                int32_t sjt_functionParam648;
                sjs_list_heap_iface_animation* sjt_parent311 = 0;

                sjt_parent311 = &_parent->animations;
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
    (*_return)->count = _parent->count;
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
    int32_t sjt_functionParam100;
    bool sjt_while1;
    int32_t sjv_i;
    int32_t sjv_j;
    sji_model sjv_pivot = { 0 };

    sjv_i = left;
    sjv_j = right;
    sjt_functionParam100 = (left + right) / 2;
    sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam100, &sjv_pivot);
    sjt_while1 = sjv_i <= sjv_j;
    while (sjt_while1) {
        bool sjt_while2;
        bool sjt_while3;
        bool sjv_continue;

        sjv_continue = true;
        sjt_while2 = (sjv_i < _parent->count) && sjv_continue;
        while (sjt_while2) {
            int32_t sjt_capture20;
            sji_model sjt_functionParam101 = { 0 };
            int32_t sjt_functionParam102;
            sji_model sjt_functionParam103 = { 0 };

            sjt_functionParam102 = sjv_i;
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam102, &sjt_functionParam101);
            sjt_functionParam103 = sjv_pivot;
            if (sjt_functionParam103._parent != 0) {
                sjt_functionParam103._parent->_refCount++;
            }

            cb._cb(cb._parent, sjt_functionParam101, sjt_functionParam103, &sjt_capture20);
            sjv_continue = sjt_capture20 < 0;
            if (sjv_continue) {
                sjv_i = sjv_i + 1;
            }

            sjt_while2 = (sjv_i < _parent->count) && sjv_continue;

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
        sjt_while3 = (sjv_j >= 0) && sjv_continue;
        while (sjt_while3) {
            int32_t sjt_capture21;
            sji_model sjt_functionParam104 = { 0 };
            int32_t sjt_functionParam105;
            sji_model sjt_functionParam106 = { 0 };

            sjt_functionParam105 = sjv_j;
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam105, &sjt_functionParam104);
            sjt_functionParam106 = sjv_pivot;
            if (sjt_functionParam106._parent != 0) {
                sjt_functionParam106._parent->_refCount++;
            }

            cb._cb(cb._parent, sjt_functionParam104, sjt_functionParam106, &sjt_capture21);
            sjv_continue = sjt_capture21 > 0;
            if (sjv_continue) {
                sjv_j = sjv_j - 1;
            }

            sjt_while3 = (sjv_j >= 0) && sjv_continue;

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

        if ((sjv_i <= sjv_j)) {
            int32_t sjt_functionParam107;
            int32_t sjt_functionParam108;
            sji_model sjt_functionParam109 = { 0 };
            int32_t sjt_functionParam110;
            int32_t sjt_functionParam111;
            sji_model sjt_functionParam112 = { 0 };
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
            sjv_i = sjv_i + 1;
            sjv_j = sjv_j - 1;

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

        sjt_while1 = sjv_i <= sjv_j;
    }

    if ((left < sjv_j)) {
        int32_t sjt_functionParam113;
        int32_t sjt_functionParam114;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam115;

        sjt_functionParam113 = left;
        sjt_functionParam114 = sjv_j;
        sjt_functionParam115 = cb;
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam113, sjt_functionParam114, sjt_functionParam115);
    }

    if ((sjv_i < right)) {
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
    _return->count = _parent->count;
    sjf_array_heap_iface_model(_return);
}

void sjf_array_heap_iface_model_grow_heap(sjs_array_heap_iface_model* _parent, int32_t newsize, sjs_array_heap_iface_model** _return) {
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
    (*_return)->count = _parent->count;
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
    if ((_parent->count > 1)) {
        int32_t sjt_functionParam119;
        int32_t sjt_functionParam120;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam121;

        sjt_functionParam119 = 0;
        sjt_functionParam120 = _parent->count - 1;
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
    _return->count = _parent->count;
    sjf_array_i32(_return);
}

void sjf_array_i32_grow_heap(sjs_array_i32* _parent, int32_t newsize, sjs_array_i32** _return) {
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
    (*_return)->count = _parent->count;
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
    (*_return)->count = _parent->count;
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
    _return->count = _parent->count;
    sjf_array_u32(_return);
}

void sjf_array_u32_grow_heap(sjs_array_u32* _parent, int32_t newsize, sjs_array_u32** _return) {
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
    (*_return)->count = _parent->count;
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
    _return->count = _parent->count;
    sjf_array_vertex_location_texture_normal(_return);
}

void sjf_array_vertex_location_texture_normal_grow_heap(sjs_array_vertex_location_texture_normal* _parent, int32_t newsize, sjs_array_vertex_location_texture_normal** _return) {
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
    (*_return)->count = _parent->count;
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
    _return->_refCount = 1;
    sjf_rect_copy(_return, (&_parent->_rect));
}

void sjf_blureffect_getrect_heap(sjs_blureffect* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), (&_parent->_rect));
}

void sjf_blureffect_heap(sjs_blureffect* _this) {
}

void sjf_blureffect_render(sjs_blureffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb) {
    sjs_boxvertexbuffer sjt_call154 = { -1 };
    sjs_boxvertexbuffer sjt_call155 = { -1 };
    sjs_scenebuffer sjt_call156 = { -1 };
    sjs_scenebuffer sjt_call157 = { -1 };

    if ((_parent->radius == 0.0f)) {
        sjs_scene2d* sjt_functionParam482 = 0;

        sjt_functionParam482 = scene;
        cb._cb(cb._parent, sjt_functionParam482);
    } else {
        if (((_parent->_vertexbuffer1._refCount != -1 ? &_parent->_vertexbuffer1 : 0) == 0)) {
            sjt_call154._refCount = 1;
            sjt_call154.rect._refCount = 1;
            sjt_call154.rect.x = 0;
            sjt_call154.rect.y = 0;
            sjt_call154.rect.w = (&_parent->_rect)->w;
            sjt_call154.rect.h = (&_parent->_rect)->h;
            sjf_rect(&sjt_call154.rect);
            sjf_boxvertexbuffer(&sjt_call154);
            if (_parent->_vertexbuffer1._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer1); }
;
            _parent->_vertexbuffer1._refCount = 1;
            sjf_boxvertexbuffer_copy(&_parent->_vertexbuffer1, (&sjt_call154));
        }

        if (((_parent->_vertexbuffer2._refCount != -1 ? &_parent->_vertexbuffer2 : 0) == 0)) {
            sjt_call155._refCount = 1;
            sjt_call155.rect._refCount = 1;
            sjf_rect_copy(&sjt_call155.rect, (&_parent->_rect));
            sjf_boxvertexbuffer(&sjt_call155);
            if (_parent->_vertexbuffer2._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer2); }
;
            _parent->_vertexbuffer2._refCount = 1;
            sjf_boxvertexbuffer_copy(&_parent->_vertexbuffer2, (&sjt_call155));
        }

        if (((_parent->_scenebuffer1._refCount != -1 ? &_parent->_scenebuffer1 : 0) == 0)) {
            sjt_call156._refCount = 1;
            sjt_call156.size._refCount = 1;
            sjt_call156.size.w = (&_parent->_rect)->w;
            sjt_call156.size.h = (&_parent->_rect)->h;
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
            if (_parent->_scenebuffer1._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer1); }
;
            _parent->_scenebuffer1._refCount = 1;
            sjf_scenebuffer_copy(&_parent->_scenebuffer1, (&sjt_call156));
        }

        if (((_parent->_scenebuffer2._refCount != -1 ? &_parent->_scenebuffer2 : 0) == 0)) {
            sjt_call157._refCount = 1;
            sjt_call157.size._refCount = 1;
            sjt_call157.size.w = (&_parent->_rect)->w;
            sjt_call157.size.h = (&_parent->_rect)->h;
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
            if (_parent->_scenebuffer2._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer2); }
;
            _parent->_scenebuffer2._refCount = 1;
            sjf_scenebuffer_copy(&_parent->_scenebuffer2, (&sjt_call157));
        }

        if (((_parent->_scenebuffer1._refCount != -1 ? &_parent->_scenebuffer1 : 0) != 0) && ((_parent->_scenebuffer2._refCount != -1 ? &_parent->_scenebuffer2 : 0) != 0) && ((_parent->_vertexbuffer1._refCount != -1 ? &_parent->_vertexbuffer1 : 0) != 0) && ((_parent->_vertexbuffer2._refCount != -1 ? &_parent->_vertexbuffer2 : 0) != 0)) {
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
            int32_t sjt_cast20;
            int32_t sjt_cast21;
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
            sjs_scene2d* sjt_parent278 = 0;
            sjs_scene2d* sjt_parent279 = 0;
            sjs_scene2d* sjt_parent280 = 0;
            sjs_scene2d* sjt_parent281 = 0;
            sjs_scene2d* sjt_parent282 = 0;
            sjs_boxvertexbuffer* sjt_parent283 = 0;
            sjs_scene2d* sjt_parent284 = 0;
            sjs_boxvertexbuffer* sjt_parent285 = 0;

            ifValue19 = (_parent->_scenebuffer1._refCount != -1 ? &_parent->_scenebuffer1 : 0);
            ifValue20 = (_parent->_scenebuffer2._refCount != -1 ? &_parent->_scenebuffer2 : 0);
            ifValue21 = (_parent->_vertexbuffer1._refCount != -1 ? &_parent->_vertexbuffer1 : 0);
            ifValue22 = (_parent->_vertexbuffer2._refCount != -1 ? &_parent->_vertexbuffer2 : 0);
            sjt_functionParam483 = &ifValue19->framebuffer;
            sjf_glpushframebuffer(sjt_functionParam483);
            sjt_parent278 = &_parent->_innerscene;
            sjt_functionParam494 = &ifValue19->size;
            sjf_scene2d_setsize(sjt_parent278, sjt_functionParam494);
            sjt_parent279 = &_parent->_innerscene;
            sjf_scene2d_start(sjt_parent279);
            sjt_functionParam497 = &_parent->_innerscene;
            cb._cb(cb._parent, sjt_functionParam497);
            sjt_parent280 = &_parent->_innerscene;
            sjf_scene2d_end(sjt_parent280);
            sjt_functionParam500 = &ifValue19->framebuffer;
            sjf_glpopframebuffer(sjt_functionParam500);
            sjt_functionParam501 = &ifValue20->framebuffer;
            sjf_glpushframebuffer(sjt_functionParam501);
            sjt_parent281 = &_parent->_innerscene;
            sjt_functionParam502 = &ifValue20->size;
            sjf_scene2d_setsize(sjt_parent281, sjt_functionParam502);
            sjt_parent282 = &_parent->_innerscene;
            sjf_scene2d_start(sjt_parent282);
            sjt_functionParam503 = sjv_gltexture_gl_texture_2d;
            sjt_functionParam504 = &ifValue19->texture;
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
            sjt_functionParam515 = _parent->radius;
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
            sjt_cast20 = (&ifValue19->size)->h;
            sjt_functionParam519 = 1.0f / (float)sjt_cast20;
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
            sjt_functionParam523 = &(&_parent->_innerscene)->model;
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
            sjt_functionParam527 = &(&_parent->_innerscene)->view;
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
            sjt_functionParam531 = &(&_parent->_innerscene)->projection;
            sjf_gluniformmat4(sjt_functionParam528, sjt_functionParam531);
            sjt_parent283 = ifValue21;
            sjt_functionParam532 = &_parent->_innerscene;
            sjf_boxvertexbuffer_render(sjt_parent283, sjt_functionParam532);
            sjt_parent284 = &_parent->_innerscene;
            sjf_scene2d_end(sjt_parent284);
            sjt_functionParam533 = &ifValue20->framebuffer;
            sjf_glpopframebuffer(sjt_functionParam533);
            sjt_functionParam534 = sjv_gltexture_gl_texture_2d;
            sjt_functionParam535 = &ifValue20->texture;
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
            sjt_functionParam546 = _parent->radius;
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
            sjt_cast21 = (&ifValue20->size)->w;
            sjt_functionParam550 = 1.0f / (float)sjt_cast21;
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
            sjt_functionParam554 = &scene->model;
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
            sjt_functionParam558 = &scene->view;
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
            sjt_functionParam562 = &scene->projection;
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
    bool sjt_capture42;
    sjs_rect* sjt_functionParam477 = 0;
    sjs_rect* sjt_parent274 = 0;

    sjt_parent274 = &_parent->_rect;
    sjt_functionParam477 = rect_;
    sjf_rect_isequal(sjt_parent274, sjt_functionParam477, &sjt_capture42);
    result12 = !sjt_capture42;
    if (result12) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
        _parent->_rect._refCount = 1;
        sjf_rect_copy(&_parent->_rect, rect_);
        if (((_parent->_scenebuffer1._refCount != -1 ? &_parent->_scenebuffer1 : 0) != 0)) {
            sjs_scenebuffer* ifValue15 = 0;
            bool result13;
            sjs_size sjt_call151 = { -1 };
            bool sjt_capture43;
            sjs_size* sjt_functionParam478 = 0;
            sjs_size* sjt_parent275 = 0;

            ifValue15 = (_parent->_scenebuffer1._refCount != -1 ? &_parent->_scenebuffer1 : 0);
            sjt_parent275 = &ifValue15->size;
            sjt_call151._refCount = 1;
            sjt_call151.w = (&_parent->_rect)->w;
            sjt_call151.h = (&_parent->_rect)->h;
            sjf_size(&sjt_call151);
            sjt_functionParam478 = &sjt_call151;
            sjf_size_isequal(sjt_parent275, sjt_functionParam478, &sjt_capture43);
            result13 = !sjt_capture43;
            if (result13) {
                if (_parent->_scenebuffer1._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer1); }
;
                _parent->_scenebuffer1._refCount = -1;
                if (_parent->_vertexbuffer1._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer1); }
;
                _parent->_vertexbuffer1._refCount = -1;
            }

            if (sjt_call151._refCount == 1) { sjf_size_destroy(&sjt_call151); }
;
        }

        if (((_parent->_scenebuffer2._refCount != -1 ? &_parent->_scenebuffer2 : 0) != 0)) {
            sjs_scenebuffer* ifValue16 = 0;
            bool result14;
            sjs_size sjt_call152 = { -1 };
            bool sjt_capture44;
            sjs_size* sjt_functionParam479 = 0;
            sjs_size* sjt_parent276 = 0;

            ifValue16 = (_parent->_scenebuffer2._refCount != -1 ? &_parent->_scenebuffer2 : 0);
            sjt_parent276 = &ifValue16->size;
            sjt_call152._refCount = 1;
            sjt_call152.w = (&_parent->_rect)->w;
            sjt_call152.h = (&_parent->_rect)->h;
            sjf_size(&sjt_call152);
            sjt_functionParam479 = &sjt_call152;
            sjf_size_isequal(sjt_parent276, sjt_functionParam479, &sjt_capture44);
            result14 = !sjt_capture44;
            if (result14) {
                if (_parent->_scenebuffer2._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer2); }
;
                _parent->_scenebuffer2._refCount = -1;
            }

            if (sjt_call152._refCount == 1) { sjf_size_destroy(&sjt_call152); }
;
        }

        if (_parent->_vertexbuffer2._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer2); }
;
        _parent->_vertexbuffer2._refCount = -1;
    }

    if ((_parent->radius == 0.0f)) {
        sjs_rect* sjt_functionParam480 = 0;

        sjt_functionParam480 = &_parent->_rect;
        cb._cb(cb._parent, sjt_functionParam480);
    } else {
        sjs_rect* sjt_functionParam481 = 0;

        sjt_call153._refCount = 1;
        sjt_call153.x = 0;
        sjt_call153.y = 0;
        sjt_call153.w = (&_parent->_rect)->w;
        sjt_call153.h = (&_parent->_rect)->h;
        sjf_rect(&sjt_call153);
        sjt_functionParam481 = &sjt_call153;
        cb._cb(cb._parent, sjt_functionParam481);
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
    _return->_refCount = 1;
    sjf_rect_copy(_return, (&_parent->rect));
}

void sjf_boxelement_getrect_heap(sjs_boxelement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), (&_parent->rect));
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
    sjs_boxrenderer sjt_call12 = { -1 };

    if (((_parent->boxrenderer._refCount != -1 ? &_parent->boxrenderer : 0) == 0)) {
        sjt_call12._refCount = 1;
        sjt_call12.rect._refCount = 1;
        sjf_rect_copy(&sjt_call12.rect, (&_parent->rect));
        sjt_call12.color._refCount = 1;
        sjf_color_copy(&sjt_call12.color, (&_parent->color));
        sjf_boxrenderer(&sjt_call12);
        if (_parent->boxrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_parent->boxrenderer); }
;
        _parent->boxrenderer._refCount = 1;
        sjf_boxrenderer_copy(&_parent->boxrenderer, (&sjt_call12));
    }

    if (((_parent->boxrenderer._refCount != -1 ? &_parent->boxrenderer : 0) != 0)) {
        sjs_scene2d* sjt_functionParam62 = 0;
        sjs_boxrenderer* sjt_parent52 = 0;

        sjt_parent52 = (_parent->boxrenderer._refCount != -1 ? &_parent->boxrenderer : 0);
        sjt_functionParam62 = scene;
        sjf_boxrenderer_render(sjt_parent52, sjt_functionParam62);
    }

    if (sjt_call12._refCount == 1) { sjf_boxrenderer_destroy(&sjt_call12); }
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
        _parent->rect._refCount = 1;
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
    _return->_refCount = 1;
    _return->x = _parent->r;
    _return->y = _parent->g;
    _return->z = _parent->b;
    sjf_vec3(_return);
}

void sjf_color_asvec3_heap(sjs_color* _parent, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    (*_return)->x = _parent->r;
    (*_return)->y = _parent->g;
    (*_return)->z = _parent->b;
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
    _return->data.datasize = sjv_count + 1;
    _return->data.data = sjv_data;
    _return->data._isglobal = false;
    _return->data.count = sjv_count + 1;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_f32_asstring_heap(float val, sjs_string** _return) {
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
    (*_return)->data.datasize = sjv_count + 1;
    (*_return)->data.data = sjv_data;
    (*_return)->data._isglobal = false;
    (*_return)->data.count = sjv_count + 1;
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
    if ((l == r)) {
        (*_return) = 0;
    } else {
        if ((l < r)) {
            int32_t result4;

            result4 = -1;
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
    if ((a < b)) {
        (*_return) = b;
    } else {
        (*_return) = a;
    }
}

void sjf_f32_min(float a, float b, float* _return) {
    if ((a < b)) {
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
    _return->_refCount = 1;
    sjf_rect_copy(_return, (&_parent->_rect));
}

void sjf_fadeeffect_getrect_heap(sjs_fadeeffect* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), (&_parent->_rect));
}

void sjf_fadeeffect_heap(sjs_fadeeffect* _this) {
}

void sjf_fadeeffect_render(sjs_fadeeffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb) {
    sjs_boxvertexbuffer sjt_call178 = { -1 };
    sjs_scenebuffer sjt_call179 = { -1 };

    if (((_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0) == 0)) {
        sjt_call178._refCount = 1;
        sjt_call178.rect._refCount = 1;
        sjf_rect_copy(&sjt_call178.rect, (&_parent->_rect));
        sjf_boxvertexbuffer(&sjt_call178);
        if (_parent->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer); }
;
        _parent->_vertexbuffer._refCount = 1;
        sjf_boxvertexbuffer_copy(&_parent->_vertexbuffer, (&sjt_call178));
    }

    if (((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) == 0)) {
        sjt_call179._refCount = 1;
        sjt_call179.size._refCount = 1;
        sjt_call179.size.w = (&_parent->_rect)->w;
        sjt_call179.size.h = (&_parent->_rect)->h;
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
        if (_parent->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer); }
;
        _parent->_scenebuffer._refCount = 1;
        sjf_scenebuffer_copy(&_parent->_scenebuffer, (&sjt_call179));
    }

    if (((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) != 0) && ((_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0) != 0)) {
        sjs_scenebuffer* ifValue29 = 0;
        sjs_boxvertexbuffer* ifValue30 = 0;
        sjs_string sjt_call180 = { -1 };
        sjs_string sjt_call181 = { -1 };
        sjs_string sjt_call182 = { -1 };
        sjs_string sjt_call183 = { -1 };
        sjs_string sjt_call184 = { -1 };
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

        ifValue29 = (_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0);
        ifValue30 = (_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0);
        sjt_functionParam571 = &ifValue29->framebuffer;
        sjf_glpushframebuffer(sjt_functionParam571);
        sjt_parent290 = &_parent->_innerscene;
        sjt_functionParam572 = &ifValue29->size;
        sjf_scene2d_setsize(sjt_parent290, sjt_functionParam572);
        sjt_parent291 = &_parent->_innerscene;
        sjf_scene2d_start(sjt_parent291);
        sjt_functionParam573 = &_parent->_innerscene;
        cb._cb(cb._parent, sjt_functionParam573);
        sjt_parent292 = &_parent->_innerscene;
        sjf_scene2d_end(sjt_parent292);
        sjt_functionParam574 = &ifValue29->framebuffer;
        sjf_glpopframebuffer(sjt_functionParam574);
        sjt_functionParam575 = sjv_gltexture_gl_texture_2d;
        sjt_functionParam576 = &ifValue29->texture;
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
        sjt_functionParam587 = _parent->alpha;
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
        sjt_functionParam591 = &scene->model;
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
        sjt_functionParam595 = &scene->view;
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
        sjt_functionParam599 = &scene->projection;
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
    bool sjt_capture46;
    sjs_rect* sjt_functionParam568 = 0;
    sjs_rect* sjt_functionParam570 = 0;
    sjs_rect* sjt_parent288 = 0;

    sjt_parent288 = &_parent->_rect;
    sjt_functionParam568 = rect_;
    sjf_rect_isequal(sjt_parent288, sjt_functionParam568, &sjt_capture46);
    result20 = !sjt_capture46;
    if (result20) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
        _parent->_rect._refCount = 1;
        sjf_rect_copy(&_parent->_rect, rect_);
        if (((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) != 0)) {
            sjs_scenebuffer* ifValue27 = 0;
            bool result21;
            sjs_size sjt_call176 = { -1 };
            bool sjt_capture47;
            sjs_size* sjt_functionParam569 = 0;
            sjs_size* sjt_parent289 = 0;

            ifValue27 = (_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0);
            sjt_parent289 = &ifValue27->size;
            sjt_call176._refCount = 1;
            sjt_call176.w = (&_parent->_rect)->w;
            sjt_call176.h = (&_parent->_rect)->h;
            sjf_size(&sjt_call176);
            sjt_functionParam569 = &sjt_call176;
            sjf_size_isequal(sjt_parent289, sjt_functionParam569, &sjt_capture47);
            result21 = !sjt_capture47;
            if (result21) {
                if (_parent->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer); }
;
                _parent->_scenebuffer._refCount = -1;
            }

            if (sjt_call176._refCount == 1) { sjf_size_destroy(&sjt_call176); }
;
        }

        if (_parent->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer); }
;
        _parent->_vertexbuffer._refCount = -1;
    }

    sjt_call177._refCount = 1;
    sjt_call177.x = 0;
    sjt_call177.y = 0;
    sjt_call177.w = (&_parent->_rect)->w;
    sjt_call177.h = (&_parent->_rect)->h;
    sjf_rect(&sjt_call177);
    sjt_functionParam570 = &sjt_call177;
    cb._cb(cb._parent, sjt_functionParam570);

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
    sjs_array_heap_iface_element* sjt_functionParam54 = 0;
    sjs_mouseevent* sjt_parent46 = 0;

    sjt_parent46 = mouseevent;
    sjt_functionParam54 = &_parent->children;
    sjf_mouseevent_firechildren(sjt_parent46, sjt_functionParam54, _return);
}

void sjf_filllayout_getrect(sjs_filllayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, (&_parent->_rect));
}

void sjf_filllayout_getrect_heap(sjs_filllayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), (&_parent->_rect));
}

void sjf_filllayout_getsize(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t i;
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
    sjt_functionParam41 = &_parent->margin;
    sjf_size_subtractmargin(sjt_parent29, sjt_functionParam41, &sjv_innersize);
    sjt_forStart8 = 0;
    sjt_forEnd8 = (&_parent->children)->count;
    i = sjt_forStart8;
    while (i < sjt_forEnd8) {
        sjs_size sjt_call6 = { -1 };
        sjs_size sjt_call7 = { -1 };
        int32_t sjt_functionParam42;
        sjs_size* sjt_functionParam43 = 0;
        sjs_size* sjt_interfaceParam4 = 0;
        sjs_array_heap_iface_element* sjt_parent30 = 0;
        sjs_size* sjt_parent31 = 0;
        sji_element sjt_parent32 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent30 = &_parent->children;
        sjt_functionParam42 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent30, sjt_functionParam42, &sjv_child);
        sjt_parent31 = &sjv_size;
        sjt_parent32 = sjv_child;
        sjt_interfaceParam4 = &sjv_innersize;
        sjt_call7._refCount = 1;
        sjt_parent32._vtbl->getsize(sjt_parent32._parent, sjt_interfaceParam4, &sjt_call7);
        sjt_functionParam43 = &sjt_call7;
        sjf_size_max(sjt_parent31, sjt_functionParam43, &sjt_call6);
        if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
        sjv_size._refCount = 1;
        sjf_size_copy(&sjv_size, (&sjt_call6));
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
    sjt_functionParam44 = &_parent->margin;
    sjf_size_addmargin(sjt_parent33, sjt_functionParam44, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_filllayout_getsize_heap(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t i;
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
    sjt_functionParam45 = &_parent->margin;
    sjf_size_subtractmargin(sjt_parent34, sjt_functionParam45, &sjv_innersize);
    sjt_forStart9 = 0;
    sjt_forEnd9 = (&_parent->children)->count;
    i = sjt_forStart9;
    while (i < sjt_forEnd9) {
        sjs_size sjt_call8 = { -1 };
        sjs_size sjt_call9 = { -1 };
        int32_t sjt_functionParam46;
        sjs_size* sjt_functionParam47 = 0;
        sjs_size* sjt_interfaceParam5 = 0;
        sjs_array_heap_iface_element* sjt_parent35 = 0;
        sjs_size* sjt_parent36 = 0;
        sji_element sjt_parent37 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent35 = &_parent->children;
        sjt_functionParam46 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent35, sjt_functionParam46, &sjv_child);
        sjt_parent36 = &sjv_size;
        sjt_parent37 = sjv_child;
        sjt_interfaceParam5 = &sjv_innersize;
        sjt_call9._refCount = 1;
        sjt_parent37._vtbl->getsize(sjt_parent37._parent, sjt_interfaceParam5, &sjt_call9);
        sjt_functionParam47 = &sjt_call9;
        sjf_size_max(sjt_parent36, sjt_functionParam47, &sjt_call8);
        if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
        sjv_size._refCount = 1;
        sjf_size_copy(&sjv_size, (&sjt_call8));
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
    sjt_functionParam48 = &_parent->margin;
    sjf_size_addmargin_heap(sjt_parent38, sjt_functionParam48, _return);

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
        sji_effect sjt_parent43 = { 0 };

        ifValue5 = _parent->effect;
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
    int32_t sjt_forEnd11;
    int32_t sjt_forStart11;

    sjt_forStart11 = 0;
    sjt_forEnd11 = (&_parent->children)->count;
    i = sjt_forStart11;
    while (i < sjt_forEnd11) {
        int32_t sjt_functionParam52;
        sjs_scene2d* sjt_interfaceParam11 = 0;
        sjs_array_heap_iface_element* sjt_parent44 = 0;
        sji_element sjt_parent45 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent44 = &_parent->children;
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
    sjs_margin* sjt_functionParam49 = 0;
    sjs_rect* sjt_parent39 = 0;
    sjs_rect sjv_innerrect = { -1 };

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
    _parent->_rect._refCount = 1;
    sjf_rect_copy(&_parent->_rect, rect_);
    sjt_parent39 = &_parent->_rect;
    sjt_functionParam49 = &_parent->margin;
    sjf_rect_subtractmargin(sjt_parent39, sjt_functionParam49, &sjv_innerrect);
    if ((_parent->effect._parent != 0)) {
        sji_effect ifValue3 = { 0 };
        sjs_rect* sjt_interfaceParam6 = 0;
        cb_rect_void sjt_interfaceParam7;
        sji_effect sjt_parent40 = { 0 };

        ifValue3 = _parent->effect;
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
    int32_t sjt_forEnd10;
    int32_t sjt_forStart10;

    sjt_forStart10 = 0;
    sjt_forEnd10 = (&_parent->children)->count;
    i = sjt_forStart10;
    while (i < sjt_forEnd10) {
        int32_t sjt_functionParam50;
        sjs_rect* sjt_interfaceParam8 = 0;
        sjs_array_heap_iface_element* sjt_parent41 = 0;
        sji_element sjt_parent42 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent41 = &_parent->children;
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
    sjs_fontkey* sjt_functionParam387 = 0;
    sjs_hash_fontkey_weak_font* sjt_parent258 = 0;
    sjs_font* sjv_h = 0;
    sjs_fontkey sjv_k = { -1 };
    sjs_font* sjv_w = 0;

    sjv_k._refCount = 1;
    sjv_k.src._refCount = 1;
    sjf_string_copy(&sjv_k.src, src);
    sjv_k.size = size;
    sjf_fontkey(&sjv_k);
    sjt_parent258 = &sjv_fonthash;
    sjt_functionParam387 = &sjv_k;
    sjf_hash_fontkey_weak_font_getat(sjt_parent258, sjt_functionParam387, &sjv_w);
    sjv_h = sjv_w;
    if (sjv_h != 0) {
        sjv_h->_refCount++;
    }

    if ((sjv_h != 0)) {
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
        sjs_fontkey* sjt_functionParam388 = 0;
        sjs_font* sjt_functionParam389 = 0;
        sjs_hash_fontkey_weak_font* sjt_parent259 = 0;
        sjs_font* sjv_result = 0;

        sjv_result = (sjs_font*)malloc(sizeof(sjs_font));
        sjv_result->_refCount = 1;
        sjv_result->src._refCount = 1;
        sjf_string_copy(&sjv_result->src, src);
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
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenFramebuffers(1, &sjv_id);
    _return->_refCount = 1;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, size);
    _return->id = sjv_id;
    sjf_framebuffer(_return);
}

void sjf_glgenframebuffer_heap(sjs_size* size, sjs_framebuffer** _return) {
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenFramebuffers(1, &sjv_id);
    (*_return) = (sjs_framebuffer*)malloc(sizeof(sjs_framebuffer));
    (*_return)->_refCount = 1;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, size);
    (*_return)->id = sjv_id;
    sjf_framebuffer_heap((*_return));
}

void sjf_glgenrenderbuffer(sjs_size* size, sjs_renderbuffer* _return) {
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenRenderbuffers(1, &sjv_id); 
    _return->_refCount = 1;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, size);
    _return->id = sjv_id;
    sjf_renderbuffer(_return);
}

void sjf_glgenrenderbuffer_heap(sjs_size* size, sjs_renderbuffer** _return) {
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenRenderbuffers(1, &sjv_id); 
    (*_return) = (sjs_renderbuffer*)malloc(sizeof(sjs_renderbuffer));
    (*_return)->_refCount = 1;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, size);
    (*_return)->id = sjv_id;
    sjf_renderbuffer_heap((*_return));
}

void sjf_glgentexture(sjs_size* size, sjs_texture* _return) {
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenTextures(1, &sjv_id);
    _return->_refCount = 1;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, size);
    _return->id = sjv_id;
    sjf_texture(_return);
}

void sjf_glgentexture_heap(sjs_size* size, sjs_texture** _return) {
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenTextures(1, &sjv_id);
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
    (*_return)->_refCount = 1;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, size);
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
    int32_t sjt_capture37;
    uint32_t sjt_capture38;
    int32_t sjt_capture39;
    int32_t sjt_capture40;
    int32_t sjt_functionParam437;
    int32_t sjt_functionParam439;
    sjs_list_u32* sjt_parent267 = 0;
    sjs_list_u32* sjt_parent268 = 0;
    sjs_list_u32* sjt_parent269 = 0;
    sjs_list_u32* sjt_parent270 = 0;
    sjs_list_u32* sjt_parent271 = 0;
    uint32_t sjv_id;

    sjt_parent267 = &sjv_glframebuffers;
    sjt_parent268 = &sjv_glframebuffers;
    sjf_list_u32_getcount(sjt_parent268, &sjt_capture37);
    sjt_functionParam437 = sjt_capture37 - 1;
    sjf_list_u32_getat(sjt_parent267, sjt_functionParam437, &sjt_capture38);
    if ((sjt_capture38 != framebuffer->id)) {
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
    sjf_list_u32_getcount(sjt_parent270, &sjt_capture39);
    sjt_functionParam439 = sjt_capture39 - 1;
    sjf_list_u32_removeat(sjt_parent269, sjt_functionParam439);
    sjt_parent271 = &sjv_glframebuffers;
    sjf_list_u32_getcount(sjt_parent271, &sjt_capture40);
    if ((sjt_capture40 > 0)) {
        int32_t sjt_capture41;
        int32_t sjt_functionParam440;
        sjs_list_u32* sjt_parent272 = 0;
        sjs_list_u32* sjt_parent273 = 0;

        sjt_parent272 = &sjv_glframebuffers;
        sjt_parent273 = &sjv_glframebuffers;
        sjf_list_u32_getcount(sjt_parent273, &sjt_capture41);
        sjt_functionParam440 = sjt_capture41 - 1;
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
    int32_t sjt_capture22;
    bool sjt_capture23;
    int32_t sjt_capture24;
    int32_t sjt_capture25;
    int32_t sjt_functionParam129;
    sjs_rect* sjt_functionParam130 = 0;
    int32_t sjt_functionParam132;
    sjs_rect* sjt_parent86 = 0;
    sjs_list_rect* sjt_parent88 = 0;
    sjs_list_rect* sjt_parent89 = 0;
    sjs_list_rect* sjt_parent90 = 0;
    sjs_list_rect* sjt_parent91 = 0;
    sjs_list_rect* sjt_parent92 = 0;
    sjs_rect sjv_newrect = { -1 };
    sjs_rect sjv_oldrect = { -1 };

    sjv_oldrect._refCount = 1;
    sjv_oldrect.x = rect->x;
    sjv_oldrect.y = scenerect->h - (rect->y + rect->h);
    sjv_oldrect.w = rect->w;
    sjv_oldrect.h = rect->h;
    sjf_rect(&sjv_oldrect);
    sjt_parent88 = &sjv_glviewports;
    sjt_parent89 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent89, &sjt_capture22);
    sjt_functionParam129 = sjt_capture22 - 1;
    sjf_list_rect_getat(sjt_parent88, sjt_functionParam129, &sjt_call19);
    sjt_parent86 = &sjt_call19;
    sjt_functionParam130 = &sjv_oldrect;
    sjf_rect_isequal(sjt_parent86, sjt_functionParam130, &sjt_capture23);
    result5 = !sjt_capture23;
    if (result5) {
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
    sjf_list_rect_getcount(sjt_parent91, &sjt_capture24);
    sjt_functionParam132 = sjt_capture24 - 1;
    sjf_list_rect_removeat(sjt_parent90, sjt_functionParam132);
    sjt_parent92 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent92, &sjt_capture25);
    if ((sjt_capture25 > 0)) {
        int32_t sjt_capture26;
        int32_t sjt_functionParam133;
        sjs_list_rect* sjt_parent93 = 0;
        sjs_list_rect* sjt_parent94 = 0;

        sjt_parent93 = &sjv_glviewports;
        sjt_parent94 = &sjv_glviewports;
        sjf_list_rect_getcount(sjt_parent94, &sjt_capture26);
        sjt_functionParam133 = sjt_capture26 - 1;
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
    uint32_t sjt_functionParam404;
    sjs_list_u32* sjt_parent265 = 0;

    sjt_parent265 = &sjv_glframebuffers;
    sjt_functionParam404 = framebuffer->id;
    sjf_list_u32_add(sjt_parent265, sjt_functionParam404);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->id);
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect* sjt_functionParam96 = 0;
    sjs_list_rect* sjt_parent75 = 0;
    sjs_rect sjv_newrect = { -1 };

    sjv_newrect._refCount = 1;
    sjv_newrect.x = rect->x;
    sjv_newrect.y = scenerect->h - (rect->y + rect->h);
    sjv_newrect.w = rect->w;
    sjv_newrect.h = rect->h;
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
    sjs_array_heap_iface_element* sjt_functionParam38 = 0;
    sjs_mouseevent* sjt_parent27 = 0;

    sjt_parent27 = mouseevent;
    sjt_functionParam38 = &_parent->children;
    sjf_mouseevent_firechildren(sjt_parent27, sjt_functionParam38, _return);
}

void sjf_gridlayout_getrect(sjs_gridlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, (&_parent->_rect));
}

void sjf_gridlayout_getrect_heap(sjs_gridlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), (&_parent->_rect));
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
    _parent->_rect._refCount = 1;
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
        if (((&sjv_row)->type == sjv_gridunittype_star)) {
            sjv_rowstars = sjv_rowstars + (&sjv_row)->amount;
        } else {
            sjv_rowfixed = sjv_rowfixed + (&sjv_row)->amount;
        }

        r++;

        if (sjv_row._refCount == 1) { sjf_gridunit_destroy(&sjv_row); }
;
    }

    if ((sjv_rowstars > 0)) {
        sjv_rowstarunit = ((&sjv_innerrect)->h - sjv_rowfixed) / sjv_rowstars;
    } else {
        sjv_rowstarunit = 0;
    }

    if ((sjv_rowstars > 0)) {
        sjv_rowstarremainder = ((&sjv_innerrect)->h - sjv_rowfixed) % sjv_rowstars;
    } else {
        sjv_rowstarremainder = 0;
    }

    sjv_ypos._refCount = 1;
    sjv_ypos.datasize = (&_parent->rows)->count + 1;
    sjv_ypos.data = 0;
    sjv_ypos._isglobal = false;
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
        if (((&sjv_row)->type == sjv_gridunittype_star)) {
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
        if (((&sjv_col)->type == sjv_gridunittype_star)) {
            sjv_colstars = sjv_colstars + (&sjv_col)->amount;
        } else {
            sjv_colfixed = sjv_colfixed + (&sjv_col)->amount;
        }

        c++;

        if (sjv_col._refCount == 1) { sjf_gridunit_destroy(&sjv_col); }
;
    }

    if ((sjv_colstars > 0)) {
        sjv_colstarunit = ((&sjv_innerrect)->w - sjv_colfixed) / sjv_colstars;
    } else {
        sjv_colstarunit = 0;
    }

    if ((sjv_colstars > 0)) {
        sjv_colstarremainder = ((&sjv_innerrect)->w - sjv_colfixed) % sjv_colstars;
    } else {
        sjv_colstarremainder = 0;
    }

    sjv_xpos._refCount = 1;
    sjv_xpos.datasize = (&_parent->cols)->count + 1;
    sjv_xpos.data = 0;
    sjv_xpos._isglobal = false;
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
        if (((&sjv_col)->type == sjv_gridunittype_star)) {
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
        sji_element sjt_cast2 = { 0 };
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
        sjt_cast2 = sjv_child;
        sjt_cast2._vtbl->asinterface(sjt_cast2._parent, sji_gridchild_typeId, (sjs_interface*)&sjv_gridchild);
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
            if ((sjv_cnext >= (&_parent->cols)->count)) {
                sjv_cnext = 0;
                sjv_rnext = sjv_rnext + 1;
                if ((sjv_rnext >= (&_parent->rows)->count)) {
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
    if ((a < b)) {
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
    int32_t sjt_functionParam646;
    sjs_array_heap_iface_animation* sjt_parent308 = 0;

    sjt_parent308 = &_parent->array;
    sjt_functionParam646 = index;
    sjf_array_heap_iface_animation_getat_heap(sjt_parent308, sjt_functionParam646, _return);
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

void sjf_list_heap_iface_model_add(sjs_list_heap_iface_model* _parent, sji_model item) {
    sjs_array_heap_iface_model sjt_call26 = { -1 };
    int32_t sjt_functionParam156;
    sji_model sjt_functionParam157 = { 0 };
    sjs_array_heap_iface_model* sjt_parent105 = 0;

    if (((&_parent->array)->count >= (&_parent->array)->datasize)) {
        int32_t sjt_functionParam153;
        int32_t sjt_functionParam154;
        int32_t sjt_functionParam155;
        sjs_array_heap_iface_model* sjt_parent104 = 0;

        sjt_parent104 = &_parent->array;
        sjt_functionParam154 = 10;
        sjt_functionParam155 = (&_parent->array)->datasize * 2;
        sjf_i32_max(sjt_functionParam154, sjt_functionParam155, &sjt_functionParam153);
        sjf_array_heap_iface_model_grow(sjt_parent104, sjt_functionParam153, &sjt_call26);
        if (_parent->array._refCount == 1) { sjf_array_heap_iface_model_destroy(&_parent->array); }
;
        _parent->array._refCount = 1;
        sjf_array_heap_iface_model_copy(&_parent->array, (&sjt_call26));
    }

    sjt_parent105 = &_parent->array;
    sjt_functionParam156 = (&_parent->array)->count;
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
    int32_t sjt_functionParam126;
    sjs_array_heap_iface_model* sjt_parent83 = 0;

    sjt_parent83 = &_parent->array;
    sjt_functionParam126 = index;
    sjf_array_heap_iface_model_getat_heap(sjt_parent83, sjt_functionParam126, _return);
}

void sjf_list_heap_iface_model_getcount(sjs_list_heap_iface_model* _parent, int32_t* _return) {
    (*_return) = (&_parent->array)->count;
}

void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this) {
}

void sjf_list_heap_iface_model_sortcb(sjs_list_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb) {
    cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam122;
    sjs_array_heap_iface_model* sjt_parent78 = 0;

    sjt_parent78 = &_parent->array;
    sjt_functionParam122 = cb;
    sjf_array_heap_iface_model_sortcb(sjt_parent78, sjt_functionParam122);
}

void sjf_list_i32(sjs_list_i32* _this) {
}

void sjf_list_i32_add(sjs_list_i32* _parent, int32_t item) {
    sjs_array_i32 sjt_call36 = { -1 };
    int32_t sjt_functionParam195;
    int32_t sjt_functionParam196;
    sjs_array_i32* sjt_parent117 = 0;

    if (((&_parent->array)->count >= (&_parent->array)->datasize)) {
        int32_t sjt_functionParam192;
        int32_t sjt_functionParam193;
        int32_t sjt_functionParam194;
        sjs_array_i32* sjt_parent116 = 0;

        sjt_parent116 = &_parent->array;
        sjt_functionParam193 = 10;
        sjt_functionParam194 = (&_parent->array)->datasize * 2;
        sjf_i32_max(sjt_functionParam193, sjt_functionParam194, &sjt_functionParam192);
        sjf_array_i32_grow(sjt_parent116, sjt_functionParam192, &sjt_call36);
        if (_parent->array._refCount == 1) { sjf_array_i32_destroy(&_parent->array); }
;
        _parent->array._refCount = 1;
        sjf_array_i32_copy(&_parent->array, (&sjt_call36));
    }

    sjt_parent117 = &_parent->array;
    sjt_functionParam195 = (&_parent->array)->count;
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
    int32_t sjt_functionParam252;
    sjs_array_i32* sjt_parent158 = 0;

    sjt_parent158 = &_parent->array;
    sjt_functionParam252 = index;
    sjf_array_i32_getat(sjt_parent158, sjt_functionParam252, _return);
}

void sjf_list_i32_getcount(sjs_list_i32* _parent, int32_t* _return) {
    (*_return) = (&_parent->array)->count;
}

void sjf_list_i32_heap(sjs_list_i32* _this) {
}

void sjf_list_rect(sjs_list_rect* _this) {
}

void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item) {
    sjs_array_rect sjt_call18 = { -1 };
    int32_t sjt_functionParam94;
    sjs_rect* sjt_functionParam95 = 0;
    sjs_array_rect* sjt_parent74 = 0;

    if (((&_parent->array)->count >= (&_parent->array)->datasize)) {
        int32_t sjt_functionParam91;
        int32_t sjt_functionParam92;
        int32_t sjt_functionParam93;
        sjs_array_rect* sjt_parent73 = 0;

        sjt_parent73 = &_parent->array;
        sjt_functionParam92 = 10;
        sjt_functionParam93 = (&_parent->array)->datasize * 2;
        sjf_i32_max(sjt_functionParam92, sjt_functionParam93, &sjt_functionParam91);
        sjf_array_rect_grow(sjt_parent73, sjt_functionParam91, &sjt_call18);
        if (_parent->array._refCount == 1) { sjf_array_rect_destroy(&_parent->array); }
;
        _parent->array._refCount = 1;
        sjf_array_rect_copy(&_parent->array, (&sjt_call18));
    }

    sjt_parent74 = &_parent->array;
    sjt_functionParam94 = (&_parent->array)->count;
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
    int32_t sjt_functionParam128;
    sjs_array_rect* sjt_parent87 = 0;

    sjt_parent87 = &_parent->array;
    sjt_functionParam128 = index;
    sjf_array_rect_getat(sjt_parent87, sjt_functionParam128, _return);
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

void sjf_list_u32_add(sjs_list_u32* _parent, uint32_t item) {
    sjs_array_u32 sjt_call144 = { -1 };
    int32_t sjt_functionParam402;
    uint32_t sjt_functionParam403;
    sjs_array_u32* sjt_parent264 = 0;

    if (((&_parent->array)->count >= (&_parent->array)->datasize)) {
        int32_t sjt_functionParam399;
        int32_t sjt_functionParam400;
        int32_t sjt_functionParam401;
        sjs_array_u32* sjt_parent263 = 0;

        sjt_parent263 = &_parent->array;
        sjt_functionParam400 = 10;
        sjt_functionParam401 = (&_parent->array)->datasize * 2;
        sjf_i32_max(sjt_functionParam400, sjt_functionParam401, &sjt_functionParam399);
        sjf_array_u32_grow(sjt_parent263, sjt_functionParam399, &sjt_call144);
        if (_parent->array._refCount == 1) { sjf_array_u32_destroy(&_parent->array); }
;
        _parent->array._refCount = 1;
        sjf_array_u32_copy(&_parent->array, (&sjt_call144));
    }

    sjt_parent264 = &_parent->array;
    sjt_functionParam402 = (&_parent->array)->count;
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
    int32_t sjt_functionParam436;
    sjs_array_u32* sjt_parent266 = 0;

    sjt_parent266 = &_parent->array;
    sjt_functionParam436 = index;
    sjf_array_u32_getat(sjt_parent266, sjt_functionParam436, _return);
}

void sjf_list_u32_getcount(sjs_list_u32* _parent, int32_t* _return) {
    (*_return) = (&_parent->array)->count;
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
    int32_t sjt_functionParam247;
    sjs_vertex_location_texture_normal* sjt_functionParam248 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent152 = 0;

    if (((&_parent->array)->count >= (&_parent->array)->datasize)) {
        int32_t sjt_functionParam244;
        int32_t sjt_functionParam245;
        int32_t sjt_functionParam246;
        sjs_array_vertex_location_texture_normal* sjt_parent151 = 0;

        sjt_parent151 = &_parent->array;
        sjt_functionParam245 = 10;
        sjt_functionParam246 = (&_parent->array)->datasize * 2;
        sjf_i32_max(sjt_functionParam245, sjt_functionParam246, &sjt_functionParam244);
        sjf_array_vertex_location_texture_normal_grow(sjt_parent151, sjt_functionParam244, &sjt_call70);
        if (_parent->array._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&_parent->array); }
;
        _parent->array._refCount = 1;
        sjf_array_vertex_location_texture_normal_copy(&_parent->array, (&sjt_call70));
    }

    sjt_parent152 = &_parent->array;
    sjt_functionParam247 = (&_parent->array)->count;
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
    int32_t sjt_functionParam256;
    sjs_array_vertex_location_texture_normal* sjt_parent162 = 0;

    sjt_parent162 = &_parent->array;
    sjt_functionParam256 = index;
    sjf_array_vertex_location_texture_normal_getat(sjt_parent162, sjt_functionParam256, _return);
}

void sjf_list_vertex_location_texture_normal_getcount(sjs_list_vertex_location_texture_normal* _parent, int32_t* _return) {
    (*_return) = (&_parent->array)->count;
}

void sjf_list_vertex_location_texture_normal_heap(sjs_list_vertex_location_texture_normal* _this) {
}

void sjf_list_vertex_location_texture_normal_setat(sjs_list_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item) {
    int32_t sjt_functionParam276;
    sjs_vertex_location_texture_normal* sjt_functionParam277 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent182 = 0;

    sjt_parent182 = &_parent->array;
    sjt_functionParam276 = index;
    sjt_functionParam277 = item;
    sjf_array_vertex_location_texture_normal_setat(sjt_parent182, sjt_functionParam276, sjt_functionParam277);
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
    _this->minlevel = _from->minlevel;
}

void sjf_log_destroy(sjs_log* _this) {
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_mainloop(bool* _return) {
    bool result24;
    sjs_string sjt_call200 = { -1 };
    sjs_string sjt_call201 = { -1 };
    sjs_string sjt_call202 = { -1 };
    bool sjt_capture52;
    int32_t sjt_functionParam649;
    sjs_size* sjt_functionParam653 = 0;
    sjs_rect* sjt_functionParam654 = 0;
    sjs_scene2d* sjt_interfaceParam21 = 0;
    sjs_animator* sjt_parent312 = 0;
    sjs_windowrenderer* sjt_parent314 = 0;
    sjs_scene2d* sjt_parent315 = 0;
    sjs_scene2d* sjt_parent316 = 0;
    sjs_rect* sjt_parent317 = 0;
    sji_element sjt_parent319 = { 0 };
    sjs_scene2d* sjt_parent320 = 0;
    sjs_windowrenderer* sjt_parent321 = 0;
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
    if (sjv_mainloop_showfps) {
        sjv_mainloop_frames = sjv_mainloop_frames + 1;
        if (((sjv_mainloop_lasttick + 2000) < sjv_ticks)) {
            int32_t sjt_cast26;
            int32_t sjt_cast27;
            sjs_string* sjt_functionParam650 = 0;
            sjs_string* sjt_functionParam651 = 0;
            float sjt_functionParam652;
            sjs_string* sjt_parent313 = 0;
            float sjv_fps;

            sjt_cast26 = sjv_mainloop_frames;
            sjt_cast27 = sjv_ticks - sjv_mainloop_lasttick;
            sjv_fps = ((float)sjt_cast26 * 1000.0f) / (float)sjt_cast27;
            sjt_call201._refCount = 1;
            sjt_call201.count = 5;
            sjt_call201.data._refCount = 1;
            sjt_call201.data.datasize = 6;
            sjt_call201.data.data = (void*)sjg_string38;
            sjt_call201.data._isglobal = true;
            sjt_call201.data.count = 6;
            sjf_array_char(&sjt_call201.data);
            sjf_string(&sjt_call201);
            sjt_parent313 = &sjt_call201;
            sjt_functionParam652 = sjv_fps;
            sjf_f32_asstring(sjt_functionParam652, &sjt_call202);
            sjt_functionParam651 = &sjt_call202;
            sjf_string_add(sjt_parent313, sjt_functionParam651, &sjt_call200);
            sjt_functionParam650 = &sjt_call200;
            sjf_debug_writeline(sjt_functionParam650);
            sjv_mainloop_lasttick = sjv_ticks;
            sjv_mainloop_frames = 0;
        }
    }

    sjt_parent314 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_getsize(sjt_parent314, &sjv_size);
    sjt_parent315 = &sjv_rootscene;
    sjt_functionParam653 = &sjv_size;
    sjf_scene2d_setsize(sjt_parent315, sjt_functionParam653);
    sjt_parent316 = &sjv_rootscene;
    sjf_scene2d_start(sjt_parent316);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjv_rect.w = (&sjv_size)->w;
    sjv_rect.h = (&sjv_size)->h;
    sjf_rect(&sjv_rect);
    sjt_parent317 = &sjv_looplastrect;
    sjt_functionParam654 = &sjv_rect;
    sjf_rect_isequal(sjt_parent317, sjt_functionParam654, &sjt_capture52);
    result24 = !sjt_capture52;
    if (result24) {
        sjs_rect* sjt_interfaceParam20 = 0;
        sji_element sjt_parent318 = { 0 };

        sjt_parent318 = sjv_root;
        sjt_interfaceParam20 = &sjv_rect;
        sjt_parent318._vtbl->setrect(sjt_parent318._parent, sjt_interfaceParam20);
    }

    sjt_parent319 = sjv_root;
    sjt_interfaceParam21 = &sjv_rootscene;
    sjt_parent319._vtbl->render(sjt_parent319._parent, sjt_interfaceParam21);
    sjt_parent320 = &sjv_rootscene;
    sjf_scene2d_end(sjt_parent320);
    sjt_parent321 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_present(sjt_parent321);
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
            int32_t ifValue39;
            int32_option sjt_getValue1;

            sjt_getValue1 = sjv_mouse_eventtype;
            ifValue39 = sjt_getValue1.value;
            if ((sjv_mouse_captureelement._parent != 0)) {
                sji_element ifValue40 = { 0 };
                sjs_mouseevent sjt_call203 = { -1 };
                sjs_mouseevent* sjt_interfaceParam22 = 0;
                sji_element sjt_parent322 = { 0 };

                ifValue40 = sjv_mouse_captureelement;
                if (ifValue40._parent != 0) {
                    ifValue40._parent->_refCount++;
                }

                sjt_parent322 = ifValue40;
                sjt_call203._refCount = 1;
                sjt_call203.type = ifValue39;
                sjt_call203.point._refCount = 1;
                sjt_call203.point.x = sjv_mouse_x;
                sjt_call203.point.y = sjv_mouse_y;
                sjf_point(&sjt_call203.point);
                sjt_call203.iscaptured = true;
                sjt_call203.isleftdown = sjv_mouse_isleftdown;
                sjf_mouseevent(&sjt_call203);
                sjt_interfaceParam22 = &sjt_call203;
                sjt_parent322._vtbl->firemouseevent(sjt_parent322._parent, sjt_interfaceParam22, &sjv_shouldcontinue);

                if (ifValue40._parent != 0) {
                    ifValue40._parent->_refCount--;
                    if (ifValue40._parent->_refCount <= 0) {
                        ifValue40._vtbl->destroy(ifValue40._parent);
                        free(ifValue40._parent);
                    }
                }
                if (sjt_call203._refCount == 1) { sjf_mouseevent_destroy(&sjt_call203); }
;
            } else {
                sjs_mouseevent sjt_call204 = { -1 };
                sjs_mouseevent* sjt_interfaceParam23 = 0;
                sji_element sjt_parent323 = { 0 };

                sjt_parent323 = sjv_root;
                sjt_call204._refCount = 1;
                sjt_call204.type = ifValue39;
                sjt_call204.point._refCount = 1;
                sjt_call204.point.x = sjv_mouse_x;
                sjt_call204.point.y = sjv_mouse_y;
                sjf_point(&sjt_call204.point);
                sjt_call204.iscaptured = false;
                sjt_call204.isleftdown = sjv_mouse_isleftdown;
                sjf_mouseevent(&sjt_call204);
                sjt_interfaceParam23 = &sjt_call204;
                sjt_parent323._vtbl->firemouseevent(sjt_parent323._parent, sjt_interfaceParam23, &sjv_shouldcontinue);

                if (sjt_call204._refCount == 1) { sjf_mouseevent_destroy(&sjt_call204); }
;
            }
        }

    }
    (*_return) = sjv_shouldappcontinue;

    if (sjt_call200._refCount == 1) { sjf_string_destroy(&sjt_call200); }
;
    if (sjt_call201._refCount == 1) { sjf_string_destroy(&sjt_call201); }
;
    if (sjt_call202._refCount == 1) { sjf_string_destroy(&sjt_call202); }
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

void sjf_mat4_determinant(sjs_mat4* _parent, float* _return) {
    (*_return) = (((_parent->m03 * _parent->m12) * _parent->m21) * _parent->m30) - (((_parent->m02 * _parent->m13) * _parent->m21) * _parent->m30) - (((_parent->m03 * _parent->m11) * _parent->m22) * _parent->m30) + (((_parent->m01 * _parent->m13) * _parent->m22) * _parent->m30) + (((_parent->m02 * _parent->m11) * _parent->m23) * _parent->m30) - (((_parent->m01 * _parent->m12) * _parent->m23) * _parent->m30) - (((_parent->m03 * _parent->m12) * _parent->m20) * _parent->m31) + (((_parent->m02 * _parent->m13) * _parent->m20) * _parent->m31) + (((_parent->m03 * _parent->m10) * _parent->m22) * _parent->m31) - (((_parent->m00 * _parent->m13) * _parent->m22) * _parent->m31) - (((_parent->m02 * _parent->m10) * _parent->m23) * _parent->m31) + (((_parent->m00 * _parent->m12) * _parent->m23) * _parent->m31) + (((_parent->m03 * _parent->m11) * _parent->m20) * _parent->m32) - (((_parent->m01 * _parent->m13) * _parent->m20) * _parent->m32) - (((_parent->m03 * _parent->m10) * _parent->m21) * _parent->m32) + (((_parent->m00 * _parent->m13) * _parent->m21) * _parent->m32) + (((_parent->m01 * _parent->m10) * _parent->m23) * _parent->m32) - (((_parent->m00 * _parent->m11) * _parent->m23) * _parent->m32) - (((_parent->m02 * _parent->m11) * _parent->m20) * _parent->m33) + (((_parent->m01 * _parent->m12) * _parent->m20) * _parent->m33) + (((_parent->m02 * _parent->m10) * _parent->m21) * _parent->m33) - (((_parent->m00 * _parent->m12) * _parent->m21) * _parent->m33) - (((_parent->m01 * _parent->m10) * _parent->m22) * _parent->m33) + (((_parent->m00 * _parent->m11) * _parent->m22) * _parent->m33);
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
    float sjt_capture30;
    float sjt_functionParam161;
    sjs_mat4* sjt_parent110 = 0;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
    sjv_t.m00 = ((_parent->m12 * _parent->m23) * _parent->m31) - ((_parent->m13 * _parent->m22) * _parent->m31) + ((_parent->m13 * _parent->m21) * _parent->m32) - ((_parent->m11 * _parent->m23) * _parent->m32) - ((_parent->m12 * _parent->m21) * _parent->m33) + ((_parent->m11 * _parent->m22) * _parent->m33);
    sjv_t.m01 = ((_parent->m03 * _parent->m22) * _parent->m31) - ((_parent->m02 * _parent->m23) * _parent->m31) - ((_parent->m03 * _parent->m21) * _parent->m32) + ((_parent->m01 * _parent->m23) * _parent->m32) + ((_parent->m02 * _parent->m21) * _parent->m33) - ((_parent->m01 * _parent->m22) * _parent->m33);
    sjv_t.m02 = ((_parent->m02 * _parent->m13) * _parent->m31) - ((_parent->m03 * _parent->m12) * _parent->m31) + ((_parent->m03 * _parent->m11) * _parent->m32) - ((_parent->m01 * _parent->m13) * _parent->m32) - ((_parent->m02 * _parent->m11) * _parent->m33) + ((_parent->m01 * _parent->m12) * _parent->m33);
    sjv_t.m03 = ((_parent->m03 * _parent->m12) * _parent->m21) - ((_parent->m02 * _parent->m13) * _parent->m21) - ((_parent->m03 * _parent->m11) * _parent->m22) + ((_parent->m01 * _parent->m13) * _parent->m22) + ((_parent->m02 * _parent->m11) * _parent->m23) - ((_parent->m01 * _parent->m12) * _parent->m23);
    sjv_t.m10 = ((_parent->m13 * _parent->m22) * _parent->m30) - ((_parent->m12 * _parent->m23) * _parent->m30) - ((_parent->m13 * _parent->m20) * _parent->m32) + ((_parent->m10 * _parent->m23) * _parent->m32) + ((_parent->m12 * _parent->m20) * _parent->m33) - ((_parent->m10 * _parent->m22) * _parent->m33);
    sjv_t.m11 = ((_parent->m02 * _parent->m23) * _parent->m30) - ((_parent->m03 * _parent->m22) * _parent->m30) + ((_parent->m03 * _parent->m20) * _parent->m32) - ((_parent->m00 * _parent->m23) * _parent->m32) - ((_parent->m02 * _parent->m20) * _parent->m33) + ((_parent->m00 * _parent->m22) * _parent->m33);
    sjv_t.m12 = ((_parent->m03 * _parent->m12) * _parent->m30) - ((_parent->m02 * _parent->m13) * _parent->m30) - ((_parent->m03 * _parent->m10) * _parent->m32) + ((_parent->m00 * _parent->m13) * _parent->m32) + ((_parent->m02 * _parent->m10) * _parent->m33) - ((_parent->m00 * _parent->m12) * _parent->m33);
    sjv_t.m13 = ((_parent->m02 * _parent->m13) * _parent->m20) - ((_parent->m03 * _parent->m12) * _parent->m20) + ((_parent->m03 * _parent->m10) * _parent->m22) - ((_parent->m00 * _parent->m13) * _parent->m22) - ((_parent->m02 * _parent->m10) * _parent->m23) + ((_parent->m00 * _parent->m12) * _parent->m23);
    sjv_t.m20 = ((_parent->m11 * _parent->m23) * _parent->m30) - ((_parent->m13 * _parent->m21) * _parent->m30) + ((_parent->m13 * _parent->m20) * _parent->m31) - ((_parent->m10 * _parent->m23) * _parent->m31) - ((_parent->m11 * _parent->m20) * _parent->m33) + ((_parent->m10 * _parent->m21) * _parent->m33);
    sjv_t.m21 = ((_parent->m03 * _parent->m21) * _parent->m30) - ((_parent->m01 * _parent->m23) * _parent->m30) - ((_parent->m03 * _parent->m20) * _parent->m31) + ((_parent->m00 * _parent->m23) * _parent->m31) + ((_parent->m01 * _parent->m20) * _parent->m33) - ((_parent->m00 * _parent->m21) * _parent->m33);
    sjv_t.m22 = ((_parent->m01 * _parent->m13) * _parent->m30) - ((_parent->m03 * _parent->m11) * _parent->m30) + ((_parent->m03 * _parent->m10) * _parent->m31) - ((_parent->m00 * _parent->m13) * _parent->m31) - ((_parent->m01 * _parent->m10) * _parent->m33) + ((_parent->m00 * _parent->m11) * _parent->m33);
    sjv_t.m23 = ((_parent->m03 * _parent->m11) * _parent->m20) - ((_parent->m01 * _parent->m13) * _parent->m20) - ((_parent->m03 * _parent->m10) * _parent->m21) + ((_parent->m00 * _parent->m13) * _parent->m21) + ((_parent->m01 * _parent->m10) * _parent->m23) - ((_parent->m00 * _parent->m11) * _parent->m23);
    sjv_t.m30 = ((_parent->m12 * _parent->m21) * _parent->m30) - ((_parent->m11 * _parent->m22) * _parent->m30) - ((_parent->m12 * _parent->m20) * _parent->m31) + ((_parent->m10 * _parent->m22) * _parent->m31) + ((_parent->m11 * _parent->m20) * _parent->m32) - ((_parent->m10 * _parent->m21) * _parent->m32);
    sjv_t.m31 = ((_parent->m01 * _parent->m22) * _parent->m30) - ((_parent->m02 * _parent->m21) * _parent->m30) + ((_parent->m02 * _parent->m20) * _parent->m31) - ((_parent->m00 * _parent->m22) * _parent->m31) - ((_parent->m01 * _parent->m20) * _parent->m32) + ((_parent->m00 * _parent->m21) * _parent->m32);
    sjv_t.m32 = ((_parent->m02 * _parent->m11) * _parent->m30) - ((_parent->m01 * _parent->m12) * _parent->m30) - ((_parent->m02 * _parent->m10) * _parent->m31) + ((_parent->m00 * _parent->m12) * _parent->m31) + ((_parent->m01 * _parent->m10) * _parent->m32) - ((_parent->m00 * _parent->m11) * _parent->m32);
    sjv_t.m33 = ((_parent->m01 * _parent->m12) * _parent->m20) - ((_parent->m02 * _parent->m11) * _parent->m20) + ((_parent->m02 * _parent->m10) * _parent->m21) - ((_parent->m00 * _parent->m12) * _parent->m21) - ((_parent->m01 * _parent->m10) * _parent->m22) + ((_parent->m00 * _parent->m11) * _parent->m22);
    sjf_mat4(&sjv_t);
    sjt_parent110 = &sjv_t;
    sjf_mat4_determinant(_parent, &sjt_capture30);
    sjt_functionParam161 = 1.0f / sjt_capture30;
    sjf_mat4_multiplyf32(sjt_parent110, sjt_functionParam161, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
;
}

void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4** _return) {
    float sjt_capture31;
    float sjt_functionParam162;
    sjs_mat4* sjt_parent111 = 0;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
    sjv_t.m00 = ((_parent->m12 * _parent->m23) * _parent->m31) - ((_parent->m13 * _parent->m22) * _parent->m31) + ((_parent->m13 * _parent->m21) * _parent->m32) - ((_parent->m11 * _parent->m23) * _parent->m32) - ((_parent->m12 * _parent->m21) * _parent->m33) + ((_parent->m11 * _parent->m22) * _parent->m33);
    sjv_t.m01 = ((_parent->m03 * _parent->m22) * _parent->m31) - ((_parent->m02 * _parent->m23) * _parent->m31) - ((_parent->m03 * _parent->m21) * _parent->m32) + ((_parent->m01 * _parent->m23) * _parent->m32) + ((_parent->m02 * _parent->m21) * _parent->m33) - ((_parent->m01 * _parent->m22) * _parent->m33);
    sjv_t.m02 = ((_parent->m02 * _parent->m13) * _parent->m31) - ((_parent->m03 * _parent->m12) * _parent->m31) + ((_parent->m03 * _parent->m11) * _parent->m32) - ((_parent->m01 * _parent->m13) * _parent->m32) - ((_parent->m02 * _parent->m11) * _parent->m33) + ((_parent->m01 * _parent->m12) * _parent->m33);
    sjv_t.m03 = ((_parent->m03 * _parent->m12) * _parent->m21) - ((_parent->m02 * _parent->m13) * _parent->m21) - ((_parent->m03 * _parent->m11) * _parent->m22) + ((_parent->m01 * _parent->m13) * _parent->m22) + ((_parent->m02 * _parent->m11) * _parent->m23) - ((_parent->m01 * _parent->m12) * _parent->m23);
    sjv_t.m10 = ((_parent->m13 * _parent->m22) * _parent->m30) - ((_parent->m12 * _parent->m23) * _parent->m30) - ((_parent->m13 * _parent->m20) * _parent->m32) + ((_parent->m10 * _parent->m23) * _parent->m32) + ((_parent->m12 * _parent->m20) * _parent->m33) - ((_parent->m10 * _parent->m22) * _parent->m33);
    sjv_t.m11 = ((_parent->m02 * _parent->m23) * _parent->m30) - ((_parent->m03 * _parent->m22) * _parent->m30) + ((_parent->m03 * _parent->m20) * _parent->m32) - ((_parent->m00 * _parent->m23) * _parent->m32) - ((_parent->m02 * _parent->m20) * _parent->m33) + ((_parent->m00 * _parent->m22) * _parent->m33);
    sjv_t.m12 = ((_parent->m03 * _parent->m12) * _parent->m30) - ((_parent->m02 * _parent->m13) * _parent->m30) - ((_parent->m03 * _parent->m10) * _parent->m32) + ((_parent->m00 * _parent->m13) * _parent->m32) + ((_parent->m02 * _parent->m10) * _parent->m33) - ((_parent->m00 * _parent->m12) * _parent->m33);
    sjv_t.m13 = ((_parent->m02 * _parent->m13) * _parent->m20) - ((_parent->m03 * _parent->m12) * _parent->m20) + ((_parent->m03 * _parent->m10) * _parent->m22) - ((_parent->m00 * _parent->m13) * _parent->m22) - ((_parent->m02 * _parent->m10) * _parent->m23) + ((_parent->m00 * _parent->m12) * _parent->m23);
    sjv_t.m20 = ((_parent->m11 * _parent->m23) * _parent->m30) - ((_parent->m13 * _parent->m21) * _parent->m30) + ((_parent->m13 * _parent->m20) * _parent->m31) - ((_parent->m10 * _parent->m23) * _parent->m31) - ((_parent->m11 * _parent->m20) * _parent->m33) + ((_parent->m10 * _parent->m21) * _parent->m33);
    sjv_t.m21 = ((_parent->m03 * _parent->m21) * _parent->m30) - ((_parent->m01 * _parent->m23) * _parent->m30) - ((_parent->m03 * _parent->m20) * _parent->m31) + ((_parent->m00 * _parent->m23) * _parent->m31) + ((_parent->m01 * _parent->m20) * _parent->m33) - ((_parent->m00 * _parent->m21) * _parent->m33);
    sjv_t.m22 = ((_parent->m01 * _parent->m13) * _parent->m30) - ((_parent->m03 * _parent->m11) * _parent->m30) + ((_parent->m03 * _parent->m10) * _parent->m31) - ((_parent->m00 * _parent->m13) * _parent->m31) - ((_parent->m01 * _parent->m10) * _parent->m33) + ((_parent->m00 * _parent->m11) * _parent->m33);
    sjv_t.m23 = ((_parent->m03 * _parent->m11) * _parent->m20) - ((_parent->m01 * _parent->m13) * _parent->m20) - ((_parent->m03 * _parent->m10) * _parent->m21) + ((_parent->m00 * _parent->m13) * _parent->m21) + ((_parent->m01 * _parent->m10) * _parent->m23) - ((_parent->m00 * _parent->m11) * _parent->m23);
    sjv_t.m30 = ((_parent->m12 * _parent->m21) * _parent->m30) - ((_parent->m11 * _parent->m22) * _parent->m30) - ((_parent->m12 * _parent->m20) * _parent->m31) + ((_parent->m10 * _parent->m22) * _parent->m31) + ((_parent->m11 * _parent->m20) * _parent->m32) - ((_parent->m10 * _parent->m21) * _parent->m32);
    sjv_t.m31 = ((_parent->m01 * _parent->m22) * _parent->m30) - ((_parent->m02 * _parent->m21) * _parent->m30) + ((_parent->m02 * _parent->m20) * _parent->m31) - ((_parent->m00 * _parent->m22) * _parent->m31) - ((_parent->m01 * _parent->m20) * _parent->m32) + ((_parent->m00 * _parent->m21) * _parent->m32);
    sjv_t.m32 = ((_parent->m02 * _parent->m11) * _parent->m30) - ((_parent->m01 * _parent->m12) * _parent->m30) - ((_parent->m02 * _parent->m10) * _parent->m31) + ((_parent->m00 * _parent->m12) * _parent->m31) + ((_parent->m01 * _parent->m10) * _parent->m32) - ((_parent->m00 * _parent->m11) * _parent->m32);
    sjv_t.m33 = ((_parent->m01 * _parent->m12) * _parent->m20) - ((_parent->m02 * _parent->m11) * _parent->m20) + ((_parent->m02 * _parent->m10) * _parent->m21) - ((_parent->m00 * _parent->m12) * _parent->m21) - ((_parent->m01 * _parent->m10) * _parent->m22) + ((_parent->m00 * _parent->m11) * _parent->m22);
    sjf_mat4(&sjv_t);
    sjt_parent111 = &sjv_t;
    sjf_mat4_determinant(_parent, &sjt_capture31);
    sjt_functionParam162 = 1.0f / sjt_capture31;
    sjf_mat4_multiplyf32_heap(sjt_parent111, sjt_functionParam162, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
;
}

void sjf_mat4_lookatlh(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return) {
    sjs_vec3 sjt_call16 = { -1 };
    float sjt_capture14;
    float sjt_capture15;
    float sjt_capture16;
    sjs_vec3* sjt_functionParam72 = 0;
    sjs_vec3* sjt_functionParam75 = 0;
    sjs_vec3* sjt_functionParam76 = 0;
    sjs_vec3* sjt_functionParam77 = 0;
    sjs_vec3* sjt_functionParam78 = 0;
    sjs_vec3* sjt_functionParam79 = 0;
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
    _return->m00 = (&sjv_xaxis)->x;
    _return->m01 = (&sjv_yaxis)->x;
    _return->m02 = (&sjv_zaxis)->x;
    _return->m03 = 0.0f;
    _return->m10 = (&sjv_xaxis)->y;
    _return->m11 = (&sjv_yaxis)->y;
    _return->m12 = (&sjv_zaxis)->y;
    _return->m13 = 0.0f;
    _return->m20 = (&sjv_xaxis)->z;
    _return->m21 = (&sjv_yaxis)->z;
    _return->m22 = (&sjv_zaxis)->z;
    _return->m23 = 0.0f;
    sjt_parent60 = &sjv_xaxis;
    sjt_functionParam77 = camera;
    sjf_vec3_dot(sjt_parent60, sjt_functionParam77, &sjt_capture14);
    _return->m30 = 0.0f - sjt_capture14;
    sjt_parent61 = &sjv_yaxis;
    sjt_functionParam78 = camera;
    sjf_vec3_dot(sjt_parent61, sjt_functionParam78, &sjt_capture15);
    _return->m31 = 0.0f - sjt_capture15;
    sjt_parent62 = &sjv_zaxis;
    sjt_functionParam79 = camera;
    sjf_vec3_dot(sjt_parent62, sjt_functionParam79, &sjt_capture16);
    _return->m32 = 0.0f - sjt_capture16;
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
    float sjt_capture17;
    float sjt_capture18;
    float sjt_capture19;
    sjs_vec3* sjt_functionParam80 = 0;
    sjs_vec3* sjt_functionParam81 = 0;
    sjs_vec3* sjt_functionParam82 = 0;
    sjs_vec3* sjt_functionParam83 = 0;
    sjs_vec3* sjt_functionParam84 = 0;
    sjs_vec3* sjt_functionParam85 = 0;
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
    (*_return)->m00 = (&sjv_xaxis)->x;
    (*_return)->m01 = (&sjv_yaxis)->x;
    (*_return)->m02 = (&sjv_zaxis)->x;
    (*_return)->m03 = 0.0f;
    (*_return)->m10 = (&sjv_xaxis)->y;
    (*_return)->m11 = (&sjv_yaxis)->y;
    (*_return)->m12 = (&sjv_zaxis)->y;
    (*_return)->m13 = 0.0f;
    (*_return)->m20 = (&sjv_xaxis)->z;
    (*_return)->m21 = (&sjv_yaxis)->z;
    (*_return)->m22 = (&sjv_zaxis)->z;
    (*_return)->m23 = 0.0f;
    sjt_parent68 = &sjv_xaxis;
    sjt_functionParam83 = camera;
    sjf_vec3_dot(sjt_parent68, sjt_functionParam83, &sjt_capture17);
    (*_return)->m30 = 0.0f - sjt_capture17;
    sjt_parent69 = &sjv_yaxis;
    sjt_functionParam84 = camera;
    sjf_vec3_dot(sjt_parent69, sjt_functionParam84, &sjt_capture18);
    (*_return)->m31 = 0.0f - sjt_capture18;
    sjt_parent70 = &sjv_zaxis;
    sjt_functionParam85 = camera;
    sjf_vec3_dot(sjt_parent70, sjt_functionParam85, &sjt_capture19);
    (*_return)->m32 = 0.0f - sjt_capture19;
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
    _return->_refCount = 1;
    _return->m00 = (m->m00 * _parent->m00) + (m->m01 * _parent->m10) + (m->m02 * _parent->m20) + (m->m03 * _parent->m30);
    _return->m01 = (m->m00 * _parent->m01) + (m->m01 * _parent->m11) + (m->m02 * _parent->m21) + (m->m03 * _parent->m31);
    _return->m02 = (m->m00 * _parent->m02) + (m->m01 * _parent->m12) + (m->m02 * _parent->m22) + (m->m03 * _parent->m32);
    _return->m03 = (m->m00 * _parent->m03) + (m->m01 * _parent->m13) + (m->m02 * _parent->m23) + (m->m03 * _parent->m33);
    _return->m10 = (m->m10 * _parent->m00) + (m->m11 * _parent->m10) + (m->m12 * _parent->m20) + (m->m13 * _parent->m30);
    _return->m11 = (m->m10 * _parent->m01) + (m->m11 * _parent->m11) + (m->m12 * _parent->m21) + (m->m13 * _parent->m31);
    _return->m12 = (m->m10 * _parent->m02) + (m->m11 * _parent->m12) + (m->m12 * _parent->m22) + (m->m13 * _parent->m32);
    _return->m13 = (m->m10 * _parent->m03) + (m->m11 * _parent->m13) + (m->m12 * _parent->m23) + (m->m13 * _parent->m33);
    _return->m20 = (m->m20 * _parent->m00) + (m->m21 * _parent->m10) + (m->m22 * _parent->m20) + (m->m23 * _parent->m30);
    _return->m21 = (m->m20 * _parent->m01) + (m->m21 * _parent->m11) + (m->m22 * _parent->m21) + (m->m23 * _parent->m31);
    _return->m22 = (m->m20 * _parent->m02) + (m->m21 * _parent->m12) + (m->m22 * _parent->m22) + (m->m23 * _parent->m32);
    _return->m23 = (m->m20 * _parent->m03) + (m->m21 * _parent->m13) + (m->m22 * _parent->m23) + (m->m23 * _parent->m33);
    _return->m30 = (m->m30 * _parent->m00) + (m->m31 * _parent->m10) + (m->m32 * _parent->m20) + (m->m33 * _parent->m30);
    _return->m31 = (m->m30 * _parent->m01) + (m->m31 * _parent->m11) + (m->m32 * _parent->m21) + (m->m33 * _parent->m31);
    _return->m32 = (m->m30 * _parent->m02) + (m->m31 * _parent->m12) + (m->m32 * _parent->m22) + (m->m33 * _parent->m32);
    _return->m33 = (m->m30 * _parent->m03) + (m->m31 * _parent->m13) + (m->m32 * _parent->m23) + (m->m33 * _parent->m33);
    sjf_mat4(_return);
}

void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    (*_return)->m00 = (m->m00 * _parent->m00) + (m->m01 * _parent->m10) + (m->m02 * _parent->m20) + (m->m03 * _parent->m30);
    (*_return)->m01 = (m->m00 * _parent->m01) + (m->m01 * _parent->m11) + (m->m02 * _parent->m21) + (m->m03 * _parent->m31);
    (*_return)->m02 = (m->m00 * _parent->m02) + (m->m01 * _parent->m12) + (m->m02 * _parent->m22) + (m->m03 * _parent->m32);
    (*_return)->m03 = (m->m00 * _parent->m03) + (m->m01 * _parent->m13) + (m->m02 * _parent->m23) + (m->m03 * _parent->m33);
    (*_return)->m10 = (m->m10 * _parent->m00) + (m->m11 * _parent->m10) + (m->m12 * _parent->m20) + (m->m13 * _parent->m30);
    (*_return)->m11 = (m->m10 * _parent->m01) + (m->m11 * _parent->m11) + (m->m12 * _parent->m21) + (m->m13 * _parent->m31);
    (*_return)->m12 = (m->m10 * _parent->m02) + (m->m11 * _parent->m12) + (m->m12 * _parent->m22) + (m->m13 * _parent->m32);
    (*_return)->m13 = (m->m10 * _parent->m03) + (m->m11 * _parent->m13) + (m->m12 * _parent->m23) + (m->m13 * _parent->m33);
    (*_return)->m20 = (m->m20 * _parent->m00) + (m->m21 * _parent->m10) + (m->m22 * _parent->m20) + (m->m23 * _parent->m30);
    (*_return)->m21 = (m->m20 * _parent->m01) + (m->m21 * _parent->m11) + (m->m22 * _parent->m21) + (m->m23 * _parent->m31);
    (*_return)->m22 = (m->m20 * _parent->m02) + (m->m21 * _parent->m12) + (m->m22 * _parent->m22) + (m->m23 * _parent->m32);
    (*_return)->m23 = (m->m20 * _parent->m03) + (m->m21 * _parent->m13) + (m->m22 * _parent->m23) + (m->m23 * _parent->m33);
    (*_return)->m30 = (m->m30 * _parent->m00) + (m->m31 * _parent->m10) + (m->m32 * _parent->m20) + (m->m33 * _parent->m30);
    (*_return)->m31 = (m->m30 * _parent->m01) + (m->m31 * _parent->m11) + (m->m32 * _parent->m21) + (m->m33 * _parent->m31);
    (*_return)->m32 = (m->m30 * _parent->m02) + (m->m31 * _parent->m12) + (m->m32 * _parent->m22) + (m->m33 * _parent->m32);
    (*_return)->m33 = (m->m30 * _parent->m03) + (m->m31 * _parent->m13) + (m->m32 * _parent->m23) + (m->m33 * _parent->m33);
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyf32(sjs_mat4* _parent, float x, sjs_mat4* _return) {
    _return->_refCount = 1;
    _return->m00 = _parent->m00 * x;
    _return->m01 = _parent->m01 * x;
    _return->m02 = _parent->m02 * x;
    _return->m03 = _parent->m03 * x;
    _return->m10 = _parent->m10 * x;
    _return->m11 = _parent->m11 * x;
    _return->m12 = _parent->m12 * x;
    _return->m13 = _parent->m13 * x;
    _return->m20 = _parent->m20 * x;
    _return->m21 = _parent->m21 * x;
    _return->m22 = _parent->m22 * x;
    _return->m23 = _parent->m23 * x;
    _return->m30 = _parent->m30 * x;
    _return->m31 = _parent->m31 * x;
    _return->m32 = _parent->m32 * x;
    _return->m33 = _parent->m33 * x;
    sjf_mat4(_return);
}

void sjf_mat4_multiplyf32_heap(sjs_mat4* _parent, float x, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    (*_return)->m00 = _parent->m00 * x;
    (*_return)->m01 = _parent->m01 * x;
    (*_return)->m02 = _parent->m02 * x;
    (*_return)->m03 = _parent->m03 * x;
    (*_return)->m10 = _parent->m10 * x;
    (*_return)->m11 = _parent->m11 * x;
    (*_return)->m12 = _parent->m12 * x;
    (*_return)->m13 = _parent->m13 * x;
    (*_return)->m20 = _parent->m20 * x;
    (*_return)->m21 = _parent->m21 * x;
    (*_return)->m22 = _parent->m22 * x;
    (*_return)->m23 = _parent->m23 * x;
    (*_return)->m30 = _parent->m30 * x;
    (*_return)->m31 = _parent->m31 * x;
    (*_return)->m32 = _parent->m32 * x;
    (*_return)->m33 = _parent->m33 * x;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyvec4(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4* _return) {
    _return->_refCount = 1;
    _return->x = (_parent->m00 * v->x) + (_parent->m10 * v->y) + (_parent->m20 * v->z) + (_parent->m30 * v->w);
    _return->y = (_parent->m01 * v->x) + (_parent->m11 * v->y) + (_parent->m21 * v->z) + (_parent->m31 * v->w);
    _return->z = (_parent->m02 * v->x) + (_parent->m12 * v->y) + (_parent->m22 * v->z) + (_parent->m32 * v->w);
    _return->w = (_parent->m03 * v->x) + (_parent->m13 * v->y) + (_parent->m23 * v->z) + (_parent->m33 * v->w);
    sjf_vec4(_return);
}

void sjf_mat4_multiplyvec4_heap(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4** _return) {
    (*_return) = (sjs_vec4*)malloc(sizeof(sjs_vec4));
    (*_return)->_refCount = 1;
    (*_return)->x = (_parent->m00 * v->x) + (_parent->m10 * v->y) + (_parent->m20 * v->z) + (_parent->m30 * v->w);
    (*_return)->y = (_parent->m01 * v->x) + (_parent->m11 * v->y) + (_parent->m21 * v->z) + (_parent->m31 * v->w);
    (*_return)->z = (_parent->m02 * v->x) + (_parent->m12 * v->y) + (_parent->m22 * v->z) + (_parent->m32 * v->w);
    (*_return)->w = (_parent->m03 * v->x) + (_parent->m13 * v->y) + (_parent->m23 * v->z) + (_parent->m33 * v->w);
    sjf_vec4_heap((*_return));
}

void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return) {
    float result16;

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
    result16 = -2.0f;
    _return->m22 = result16 / (zfar - znear);
    _return->m23 = 0.0f;
    _return->m30 = 0.0f - (right + left) / (right - left);
    _return->m31 = 0.0f - (top + bottom) / (top - bottom);
    _return->m32 = 0.0f - (zfar + znear) / (zfar - znear);
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return) {
    float result17;

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
    result17 = -2.0f;
    (*_return)->m22 = result17 / (zfar - znear);
    (*_return)->m23 = 0.0f;
    (*_return)->m30 = 0.0f - (right + left) / (right - left);
    (*_return)->m31 = 0.0f - (top + bottom) / (top - bottom);
    (*_return)->m32 = 0.0f - (zfar + znear) / (zfar - znear);
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_perspective(float fovy, float aspect, float znear, float zfar, sjs_mat4* _return) {
    float sjt_capture12;
    float sjt_functionParam66;
    float sjv_xscale;
    float sjv_yscale;

    sjt_functionParam66 = (fovy / 180.0f) / 2.0f;
    sjf_f32_tan(sjt_functionParam66, &sjt_capture12);
    sjv_yscale = 1.0f / sjt_capture12;
    sjv_xscale = sjv_yscale * aspect;
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
    _return->m22 = zfar / (zfar - znear);
    _return->m23 = 1.0f;
    _return->m30 = 0.0f;
    _return->m31 = 0.0f;
    _return->m32 = 0.0f - (znear * zfar) / (zfar - znear);
    _return->m33 = 0.0f;
    sjf_mat4(_return);
}

void sjf_mat4_perspective_heap(float fovy, float aspect, float znear, float zfar, sjs_mat4** _return) {
    float sjt_capture13;
    float sjt_functionParam67;
    float sjv_xscale;
    float sjv_yscale;

    sjt_functionParam67 = (fovy / 180.0f) / 2.0f;
    sjf_f32_tan(sjt_functionParam67, &sjt_capture13);
    sjv_yscale = 1.0f / sjt_capture13;
    sjv_xscale = sjv_yscale * aspect;
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
    (*_return)->m22 = zfar / (zfar - znear);
    (*_return)->m23 = 1.0f;
    (*_return)->m30 = 0.0f;
    (*_return)->m31 = 0.0f;
    (*_return)->m32 = 0.0f - (znear * zfar) / (zfar - znear);
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
    _return->_refCount = 1;
    _return->m00 = _parent->m00;
    _return->m01 = _parent->m10;
    _return->m02 = _parent->m20;
    _return->m03 = _parent->m30;
    _return->m10 = _parent->m01;
    _return->m11 = _parent->m11;
    _return->m12 = _parent->m21;
    _return->m13 = _parent->m31;
    _return->m20 = _parent->m02;
    _return->m21 = _parent->m12;
    _return->m22 = _parent->m22;
    _return->m23 = _parent->m32;
    _return->m30 = _parent->m03;
    _return->m31 = _parent->m13;
    _return->m32 = _parent->m23;
    _return->m33 = _parent->m33;
    sjf_mat4(_return);
}

void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    (*_return)->m00 = _parent->m00;
    (*_return)->m01 = _parent->m10;
    (*_return)->m02 = _parent->m20;
    (*_return)->m03 = _parent->m30;
    (*_return)->m10 = _parent->m01;
    (*_return)->m11 = _parent->m11;
    (*_return)->m12 = _parent->m21;
    (*_return)->m13 = _parent->m31;
    (*_return)->m20 = _parent->m02;
    (*_return)->m21 = _parent->m12;
    (*_return)->m22 = _parent->m22;
    (*_return)->m23 = _parent->m32;
    (*_return)->m30 = _parent->m03;
    (*_return)->m31 = _parent->m13;
    (*_return)->m32 = _parent->m23;
    (*_return)->m33 = _parent->m33;
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
    _return->_refCount = 1;
    sjf_vec3_copy(_return, (&_parent->center));
}

void sjf_model_getcenter_heap(sjs_model* _parent, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjf_vec3_copy((*_return), (&_parent->center));
}

void sjf_model_getworld(sjs_model* _parent, sjs_mat4* _return) {
    sjs_mat4* sjt_functionParam151 = 0;
    sjs_mat4* sjt_parent102 = 0;

    sjt_parent102 = &_parent->_world;
    sjt_functionParam151 = &_parent->model;
    sjf_mat4_multiply(sjt_parent102, sjt_functionParam151, _return);
}

void sjf_model_getworld_heap(sjs_model* _parent, sjs_mat4** _return) {
    sjs_mat4* sjt_functionParam152 = 0;
    sjs_mat4* sjt_parent103 = 0;

    sjt_parent103 = &_parent->_world;
    sjt_functionParam152 = &_parent->model;
    sjf_mat4_multiply_heap(sjt_parent103, sjt_functionParam152, _return);
}

void sjf_model_getz(sjs_model* _parent, float* _return) {
    (*_return) = (&_parent->_projectedcenter)->z;
}

void sjf_model_heap(sjs_model* _this, sjs_model** _return) {
    if (((_this->id._refCount != -1 ? &_this->id : 0) != 0)) {
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

    sjt_parent107 = &_parent->_world;
    sjt_functionParam159 = &_parent->model;
    sjf_mat4_multiply(sjt_parent107, sjt_functionParam159, &sjv_world);
    sjt_parent108 = &_parent->_view;
    sjt_functionParam160 = &sjv_world;
    sjf_mat4_multiply(sjt_parent108, sjt_functionParam160, &sjv_viewworld);
    sjt_parent112 = &sjv_viewworld;
    sjf_mat4_invert(sjt_parent112, &sjt_call27);
    sjt_parent109 = &sjt_call27;
    sjf_mat4_transpose(sjt_parent109, &sjv_normalmat);
    sjt_functionParam163 = &_parent->shader;
    sjf_gluseprogram(sjt_functionParam163);
    sjt_functionParam164 = sjv_glblendfunctype_gl_src_alpha;
    sjt_functionParam165 = sjv_glblendfunctype_gl_one_minus_src_alpha;
    sjf_glblendfunc(sjt_functionParam164, sjt_functionParam165);
    sjt_functionParam166 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam167 = &_parent->texture;
    sjf_glbindtexture(sjt_functionParam166, sjt_functionParam167);
    sjt_functionParam169 = &_parent->shader;
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
    sjt_functionParam173 = &_parent->shader;
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
    sjt_functionParam177 = &_parent->shader;
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
    sjt_functionParam179 = &_parent->_projection;
    sjf_gluniformmat4(sjt_functionParam176, sjt_functionParam179);
    sjt_functionParam181 = &_parent->shader;
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
    sjt_functionParam183 = &(&_parent->_light)->pos;
    sjf_gluniformvec3(sjt_functionParam180, sjt_functionParam183);
    sjt_functionParam185 = &_parent->shader;
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
    sjt_parent113 = &(&_parent->_light)->diffusecolor;
    sjf_color_asvec3(sjt_parent113, &sjt_call33);
    sjt_functionParam187 = &sjt_call33;
    sjf_gluniformvec3(sjt_functionParam184, sjt_functionParam187);
    sjt_functionParam189 = &_parent->shader;
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
    sjt_parent114 = &(&_parent->_light)->speccolor;
    sjf_color_asvec3(sjt_parent114, &sjt_call35);
    sjt_functionParam191 = &sjt_call35;
    sjf_gluniformvec3(sjt_functionParam188, sjt_functionParam191);
    sjt_parent115 = &_parent->vertexbuffer;
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
    if (_parent->hasalpha) {
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
    sjs_mat4* sjt_functionParam148 = 0;
    sjs_mat4* sjt_functionParam149 = 0;
    sjs_vec4* sjt_functionParam150 = 0;
    sjs_mat4* sjt_parent100 = 0;
    sjs_mat4* sjt_parent101 = 0;
    sjs_mat4* sjt_parent99 = 0;
    sjs_vec4 sjv_t2 = { -1 };

    if (_parent->_projection._refCount == 1) { sjf_mat4_destroy(&_parent->_projection); }
;
    _parent->_projection._refCount = 1;
    sjf_mat4_copy(&_parent->_projection, projection);
    if (_parent->_view._refCount == 1) { sjf_mat4_destroy(&_parent->_view); }
;
    _parent->_view._refCount = 1;
    sjf_mat4_copy(&_parent->_view, view);
    if (_parent->_world._refCount == 1) { sjf_mat4_destroy(&_parent->_world); }
;
    _parent->_world._refCount = 1;
    sjf_mat4_copy(&_parent->_world, world);
    sjt_parent101 = &_parent->_view;
    sjt_functionParam148 = &_parent->_world;
    sjf_mat4_multiply(sjt_parent101, sjt_functionParam148, &sjt_call23);
    sjt_parent100 = &sjt_call23;
    sjt_functionParam149 = &_parent->model;
    sjf_mat4_multiply(sjt_parent100, sjt_functionParam149, &sjt_call22);
    sjt_parent99 = &sjt_call22;
    sjt_call24._refCount = 1;
    sjt_call24.x = (&_parent->center)->x;
    sjt_call24.y = (&_parent->center)->y;
    sjt_call24.z = (&_parent->center)->z;
    sjt_call24.w = 1.0f;
    sjf_vec4(&sjt_call24);
    sjt_functionParam150 = &sjt_call24;
    sjf_mat4_multiplyvec4(sjt_parent99, sjt_functionParam150, &sjv_t2);
    sjt_call25._refCount = 1;
    sjt_call25.x = (&sjv_t2)->x / (&sjv_t2)->w;
    sjt_call25.y = (&sjv_t2)->y / (&sjv_t2)->w;
    sjt_call25.z = (&sjv_t2)->z / (&sjv_t2)->w;
    sjf_vec3(&sjt_call25);
    if (_parent->_projectedcenter._refCount == 1) { sjf_vec3_destroy(&_parent->_projectedcenter); }
;
    _parent->_projectedcenter._refCount = 1;
    sjf_vec3_copy(&_parent->_projectedcenter, (&sjt_call25));
    if (_parent->_light._refCount == 1) { sjf_light_destroy(&_parent->_light); }
;
    _parent->_light._refCount = 1;
    sjf_light_copy(&_parent->_light, light);

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
    (*_return) = (_parent->x == rect->x) && (_parent->y == rect->y) && (_parent->w == rect->w) && (_parent->h == rect->h);
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
    _return->_refCount = 1;
    sjf_rect_copy(_return, (&_parent->_rect));
}

void sjf_saturateeffect_getrect_heap(sjs_saturateeffect* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), (&_parent->_rect));
}

void sjf_saturateeffect_heap(sjs_saturateeffect* _this) {
}

void sjf_saturateeffect_render(sjs_saturateeffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb) {
    sjs_boxvertexbuffer sjt_call189 = { -1 };
    sjs_scenebuffer sjt_call190 = { -1 };

    if (((_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0) == 0)) {
        sjt_call189._refCount = 1;
        sjt_call189.rect._refCount = 1;
        sjf_rect_copy(&sjt_call189.rect, (&_parent->_rect));
        sjf_boxvertexbuffer(&sjt_call189);
        if (_parent->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer); }
;
        _parent->_vertexbuffer._refCount = 1;
        sjf_boxvertexbuffer_copy(&_parent->_vertexbuffer, (&sjt_call189));
    }

    if (((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) == 0)) {
        sjt_call190._refCount = 1;
        sjt_call190.size._refCount = 1;
        sjt_call190.size.w = (&_parent->_rect)->w;
        sjt_call190.size.h = (&_parent->_rect)->h;
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
        if (_parent->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer); }
;
        _parent->_scenebuffer._refCount = 1;
        sjf_scenebuffer_copy(&_parent->_scenebuffer, (&sjt_call190));
    }

    if (((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) != 0) && ((_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0) != 0)) {
        sjs_scenebuffer* ifValue35 = 0;
        sjs_boxvertexbuffer* ifValue36 = 0;
        sjs_string sjt_call191 = { -1 };
        sjs_string sjt_call192 = { -1 };
        sjs_string sjt_call193 = { -1 };
        sjs_string sjt_call194 = { -1 };
        sjs_string sjt_call195 = { -1 };
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

        ifValue35 = (_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0);
        ifValue36 = (_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0);
        sjt_functionParam608 = &ifValue35->framebuffer;
        sjf_glpushframebuffer(sjt_functionParam608);
        sjt_parent298 = &_parent->_innerscene;
        sjt_functionParam609 = &ifValue35->size;
        sjf_scene2d_setsize(sjt_parent298, sjt_functionParam609);
        sjt_parent299 = &_parent->_innerscene;
        sjf_scene2d_start(sjt_parent299);
        sjt_functionParam610 = &_parent->_innerscene;
        cb._cb(cb._parent, sjt_functionParam610);
        sjt_parent300 = &_parent->_innerscene;
        sjf_scene2d_end(sjt_parent300);
        sjt_functionParam611 = &ifValue35->framebuffer;
        sjf_glpopframebuffer(sjt_functionParam611);
        sjt_functionParam612 = sjv_gltexture_gl_texture_2d;
        sjt_functionParam613 = &ifValue35->texture;
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
        sjt_functionParam624 = _parent->amount;
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
        sjt_functionParam628 = &scene->model;
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
        sjt_functionParam632 = &scene->view;
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
        sjt_functionParam636 = &scene->projection;
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
    bool sjt_capture48;
    sjs_rect* sjt_functionParam605 = 0;
    sjs_rect* sjt_functionParam607 = 0;
    sjs_rect* sjt_parent296 = 0;

    sjt_parent296 = &_parent->_rect;
    sjt_functionParam605 = rect_;
    sjf_rect_isequal(sjt_parent296, sjt_functionParam605, &sjt_capture48);
    result22 = !sjt_capture48;
    if (result22) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
        _parent->_rect._refCount = 1;
        sjf_rect_copy(&_parent->_rect, rect_);
        if (((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) != 0)) {
            sjs_scenebuffer* ifValue33 = 0;
            bool result23;
            sjs_size sjt_call187 = { -1 };
            bool sjt_capture49;
            sjs_size* sjt_functionParam606 = 0;
            sjs_size* sjt_parent297 = 0;

            ifValue33 = (_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0);
            sjt_parent297 = &ifValue33->size;
            sjt_call187._refCount = 1;
            sjt_call187.w = (&_parent->_rect)->w;
            sjt_call187.h = (&_parent->_rect)->h;
            sjf_size(&sjt_call187);
            sjt_functionParam606 = &sjt_call187;
            sjf_size_isequal(sjt_parent297, sjt_functionParam606, &sjt_capture49);
            result23 = !sjt_capture49;
            if (result23) {
                if (_parent->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer); }
;
                _parent->_scenebuffer._refCount = -1;
            }

            if (sjt_call187._refCount == 1) { sjf_size_destroy(&sjt_call187); }
;
        }

        if (_parent->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer); }
;
        _parent->_vertexbuffer._refCount = -1;
    }

    sjt_call188._refCount = 1;
    sjt_call188.x = 0;
    sjt_call188.y = 0;
    sjt_call188.w = (&_parent->_rect)->w;
    sjt_call188.h = (&_parent->_rect)->h;
    sjf_rect(&sjt_call188);
    sjt_functionParam607 = &sjt_call188;
    cb._cb(cb._parent, sjt_functionParam607);

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
    sjs_rect* sjt_functionParam498 = 0;
    sjs_rect* sjt_functionParam499 = 0;

    sjt_functionParam498 = &_parent->windowrect;
    sjt_functionParam499 = &_parent->windowrect;
    sjf_glpopviewport(sjt_functionParam498, sjt_functionParam499);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result15;
    sjs_mat4 sjt_call158 = { -1 };
    sjs_mat4 sjt_call159 = { -1 };
    sjs_mat4 sjt_call160 = { -1 };
    bool sjt_capture45;
    sjs_size* sjt_functionParam484 = 0;
    sjs_size* sjt_parent277 = 0;

    sjt_parent277 = &_parent->_size;
    sjt_functionParam484 = size;
    sjf_size_isequal(sjt_parent277, sjt_functionParam484, &sjt_capture45);
    result15 = !sjt_capture45;
    if (result15) {
        float result18;
        float result19;
        int32_t sjt_cast18;
        int32_t sjt_cast19;
        float sjt_functionParam485;
        float sjt_functionParam486;
        float sjt_functionParam487;
        float sjt_functionParam488;
        float sjt_functionParam489;
        float sjt_functionParam490;
        float sjt_functionParam491;
        float sjt_functionParam492;
        float sjt_functionParam493;

        if (_parent->_size._refCount == 1) { sjf_size_destroy(&_parent->_size); }
;
        _parent->_size._refCount = 1;
        sjf_size_copy(&_parent->_size, size);
        sjt_functionParam485 = 0.0f;
        sjt_cast18 = (&_parent->_size)->w;
        sjt_functionParam486 = (float)sjt_cast18;
        sjt_cast19 = 0 - (&_parent->_size)->h;
        sjt_functionParam487 = (float)sjt_cast19;
        sjt_functionParam488 = 0.0f;
        result18 = -1.0f;
        sjt_functionParam489 = result18;
        sjt_functionParam490 = 1.0f;
        sjf_mat4_orthographic(sjt_functionParam485, sjt_functionParam486, sjt_functionParam487, sjt_functionParam488, sjt_functionParam489, sjt_functionParam490, &sjt_call158);
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
        _parent->projection._refCount = 1;
        sjf_mat4_copy(&_parent->projection, (&sjt_call158));
        sjt_functionParam491 = 1.0f;
        result19 = -1.0f;
        sjt_functionParam492 = result19;
        sjt_functionParam493 = 1.0f;
        sjf_mat4_scale(sjt_functionParam491, sjt_functionParam492, sjt_functionParam493, &sjt_call159);
        if (_parent->model._refCount == 1) { sjf_mat4_destroy(&_parent->model); }
;
        _parent->model._refCount = 1;
        sjf_mat4_copy(&_parent->model, (&sjt_call159));
        sjf_mat4_identity(&sjt_call160);
        if (_parent->view._refCount == 1) { sjf_mat4_destroy(&_parent->view); }
;
        _parent->view._refCount = 1;
        sjf_mat4_copy(&_parent->view, (&sjt_call160));
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
    sjs_rect* sjt_functionParam495 = 0;
    sjs_rect* sjt_functionParam496 = 0;

    sjt_call161._refCount = 1;
    sjt_call161.x = 0;
    sjt_call161.y = 0;
    sjt_call161.w = (&_parent->_size)->w;
    sjt_call161.h = (&_parent->_size)->h;
    sjf_rect(&sjt_call161);
    if (_parent->windowrect._refCount == 1) { sjf_rect_destroy(&_parent->windowrect); }
;
    _parent->windowrect._refCount = 1;
    sjf_rect_copy(&_parent->windowrect, (&sjt_call161));
    sjt_functionParam495 = &_parent->windowrect;
    sjt_functionParam496 = &_parent->windowrect;
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
    int32_t sjt_forEnd15;
    int32_t sjt_forStart15;

    sjt_forStart15 = 0;
    sjt_forEnd15 = (&_parent->children)->count;
    i = sjt_forStart15;
    while (i < sjt_forEnd15) {
        int32_t sjt_functionParam137;
        sjs_mouseevent* sjt_interfaceParam18 = 0;
        sjs_array_heap_iface_model* sjt_parent95 = 0;
        sji_model sjt_parent96 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_parent95 = &_parent->children;
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
    _return->_refCount = 1;
    sjf_rect_copy(_return, (&_parent->_rect));
}

void sjf_scene3delement_getrect_heap(sjs_scene3delement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), (&_parent->_rect));
}

void sjf_scene3delement_getsize(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    _return->w = maxsize->w;
    _return->h = maxsize->h;
    sjf_size(_return);
}

void sjf_scene3delement_getsize_heap(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    (*_return)->w = maxsize->w;
    (*_return)->h = maxsize->h;
    sjf_size_heap((*_return));
}

void sjf_scene3delement_heap(sjs_scene3delement* _this) {
}

void sjf_scene3delement_render(sjs_scene3delement* _parent, sjs_scene2d* scene) {
    int32_t i;
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
    sjt_forEnd12 = (&_parent->children)->count;
    i = sjt_forStart12;
    while (i < sjt_forEnd12) {
        int32_t sjt_functionParam89;
        sjs_rect* sjt_interfaceParam12 = 0;
        sjs_mat4* sjt_interfaceParam13 = 0;
        sjs_mat4* sjt_interfaceParam14 = 0;
        sjs_mat4* sjt_interfaceParam15 = 0;
        sjs_light* sjt_interfaceParam16 = 0;
        sjs_array_heap_iface_model* sjt_parent71 = 0;
        sji_model sjt_parent72 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_parent71 = &_parent->children;
        sjt_functionParam89 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent71, sjt_functionParam89, &sjv_child);
        sjt_parent72 = sjv_child;
        sjt_interfaceParam12 = &_parent->_rect;
        sjt_interfaceParam13 = &_parent->projection;
        sjt_interfaceParam14 = &_parent->view;
        sjt_interfaceParam15 = &_parent->world;
        sjt_interfaceParam16 = &_parent->light;
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
    sjt_functionParam97 = &_parent->_rect;
    sjt_functionParam98 = &scene->windowrect;
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
    sjt_forEnd13 = (&_parent->children)->count;
    i = sjt_forStart13;
    while (i < sjt_forEnd13) {
        int32_t sjt_functionParam99;
        sjs_list_heap_iface_model* sjt_interfaceParam17 = 0;
        sjs_array_heap_iface_model* sjt_parent76 = 0;
        sji_model sjt_parent77 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_parent76 = &_parent->children;
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

    sjt_functionParam134 = &_parent->_rect;
    sjt_functionParam135 = &scene->windowrect;
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
    bool sjt_capture11;
    sjs_rect* sjt_functionParam65 = 0;
    sjs_rect* sjt_parent54 = 0;

    sjt_parent54 = &_parent->_rect;
    sjt_functionParam65 = rect_;
    sjf_rect_isequal(sjt_parent54, sjt_functionParam65, &sjt_capture11);
    result3 = !sjt_capture11;
    if (result3) {
        int32_t sjt_cast7;
        int32_t sjt_cast8;
        float sjt_functionParam68;
        float sjt_functionParam69;
        float sjt_functionParam70;
        float sjt_functionParam71;
        sjs_vec3* sjt_functionParam86 = 0;
        sjs_vec3* sjt_functionParam87 = 0;
        sjs_vec3* sjt_functionParam88 = 0;

        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
        _parent->_rect._refCount = 1;
        sjf_rect_copy(&_parent->_rect, rect_);
        sjt_functionParam68 = _parent->fieldofview;
        sjt_cast7 = (&_parent->_rect)->h;
        sjt_cast8 = (&_parent->_rect)->w;
        sjt_functionParam69 = (float)sjt_cast7 / (float)sjt_cast8;
        sjt_functionParam70 = _parent->znear;
        sjt_functionParam71 = _parent->zfar;
        sjf_mat4_perspective(sjt_functionParam68, sjt_functionParam69, sjt_functionParam70, sjt_functionParam71, &sjt_call14);
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
        _parent->projection._refCount = 1;
        sjf_mat4_copy(&_parent->projection, (&sjt_call14));
        sjt_functionParam86 = &_parent->camera;
        sjt_functionParam87 = &_parent->lookat;
        sjt_functionParam88 = &_parent->up;
        sjf_mat4_lookatlh(sjt_functionParam86, sjt_functionParam87, sjt_functionParam88, &sjt_call15);
        if (_parent->view._refCount == 1) { sjf_mat4_destroy(&_parent->view); }
;
        _parent->view._refCount = 1;
        sjf_mat4_copy(&_parent->view, (&sjt_call15));
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
    int32_t sjv_status;

    sjt_functionParam396 = &_this->size;
    sjf_glgenframebuffer(sjt_functionParam396, &sjt_call141);
    if (_this->framebuffer._refCount == 1) { sjf_framebuffer_destroy(&_this->framebuffer); }
;
    _this->framebuffer._refCount = 1;
    sjf_framebuffer_copy(&_this->framebuffer, (&sjt_call141));
    sjt_functionParam397 = &_this->size;
    sjf_glgentexture(sjt_functionParam397, &sjt_call142);
    if (_this->texture._refCount == 1) { sjf_texture_destroy(&_this->texture); }
;
    _this->texture._refCount = 1;
    sjf_texture_copy(&_this->texture, (&sjt_call142));
    sjt_functionParam398 = &_this->size;
    sjf_glgenrenderbuffer(sjt_functionParam398, &sjt_call143);
    if (_this->renderbuffer._refCount == 1) { sjf_renderbuffer_destroy(&_this->renderbuffer); }
;
    _this->renderbuffer._refCount = 1;
    sjf_renderbuffer_copy(&_this->renderbuffer, (&sjt_call143));
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
    if ((sjv_status != sjv_glframebufferstatus_gl_framebuffer_complete)) {
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
    int32_t sjv_status;

    sjt_functionParam442 = &_this->size;
    sjf_glgenframebuffer(sjt_functionParam442, &sjt_call147);
    if (_this->framebuffer._refCount == 1) { sjf_framebuffer_destroy(&_this->framebuffer); }
;
    _this->framebuffer._refCount = 1;
    sjf_framebuffer_copy(&_this->framebuffer, (&sjt_call147));
    sjt_functionParam443 = &_this->size;
    sjf_glgentexture(sjt_functionParam443, &sjt_call148);
    if (_this->texture._refCount == 1) { sjf_texture_destroy(&_this->texture); }
;
    _this->texture._refCount = 1;
    sjf_texture_copy(&_this->texture, (&sjt_call148));
    sjt_functionParam444 = &_this->size;
    sjf_glgenrenderbuffer(sjt_functionParam444, &sjt_call149);
    if (_this->renderbuffer._refCount == 1) { sjf_renderbuffer_destroy(&_this->renderbuffer); }
;
    _this->renderbuffer._refCount = 1;
    sjf_renderbuffer_copy(&_this->renderbuffer, (&sjt_call149));
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
    if ((sjv_status != sjv_glframebufferstatus_gl_framebuffer_complete)) {
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
    if ((_parent->w > maxsize->w)) {
        _return->w = _parent->w;
    } else {
        _return->w = maxsize->w;
    }

    if ((_parent->h > maxsize->h)) {
        _return->h = _parent->h;
    } else {
        _return->h = maxsize->h;
    }

    sjf_size(_return);
}

void sjf_size_max_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    if ((_parent->w > maxsize->w)) {
        (*_return)->w = _parent->w;
    } else {
        (*_return)->w = maxsize->w;
    }

    if ((_parent->h > maxsize->h)) {
        (*_return)->h = _parent->h;
    } else {
        (*_return)->h = maxsize->h;
    }

    sjf_size_heap((*_return));
}

void sjf_size_min(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    if ((_parent->w < maxsize->w)) {
        _return->w = _parent->w;
    } else {
        _return->w = maxsize->w;
    }

    if ((_parent->h < maxsize->h)) {
        _return->h = _parent->h;
    } else {
        _return->h = maxsize->h;
    }

    sjf_size(_return);
}

void sjf_size_min_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    if ((_parent->w < maxsize->w)) {
        (*_return)->w = _parent->w;
    } else {
        (*_return)->w = maxsize->w;
    }

    if ((_parent->h < maxsize->h)) {
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

    if ((item->count == 0)) {
        _return->_refCount = 1;
        _return->count = _parent->count;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&_parent->data));
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_cast12;
        int32_t sjt_forEnd16;
        int32_t sjt_forStart16;
        int32_t sjt_functionParam199;
        int32_t sjt_functionParam200;
        char sjt_functionParam201;
        int32_t sjt_functionParam203;
        int32_t sjt_functionParam207;
        char sjt_functionParam208;
        sjs_array_char* sjt_parent119 = 0;
        sjs_array_char* sjt_parent120 = 0;
        sjs_string* sjt_parent122 = 0;
        sjs_array_char* sjt_parent125 = 0;
        int32_t sjv_newcount;

        sjt_parent119 = &_parent->data;
        sjt_functionParam199 = (_parent->count + item->count) + 1;
        sjf_array_char_grow(sjt_parent119, sjt_functionParam199, &sjv_newdata);
        sjv_newcount = _parent->count;
        sjt_parent120 = &sjv_newdata;
        sjt_functionParam200 = sjv_newcount;
        sjt_parent122 = item;
        sjt_functionParam203 = 0;
        sjf_string_getat(sjt_parent122, sjt_functionParam203, &sjt_functionParam201);
        sjf_array_char_setat(sjt_parent120, sjt_functionParam200, sjt_functionParam201);
        sjv_newcount = sjv_newcount + 1;
        sjt_forStart16 = 1;
        sjt_forEnd16 = item->count;
        i = sjt_forStart16;
        while (i < sjt_forEnd16) {
            int32_t sjt_functionParam204;
            char sjt_functionParam205;
            int32_t sjt_functionParam206;
            sjs_array_char* sjt_parent123 = 0;
            sjs_string* sjt_parent124 = 0;

            sjt_parent123 = &sjv_newdata;
            sjt_functionParam204 = sjv_newcount;
            sjt_parent124 = item;
            sjt_functionParam206 = i;
            sjf_string_getat(sjt_parent124, sjt_functionParam206, &sjt_functionParam205);
            sjf_array_char_initat(sjt_parent123, sjt_functionParam204, sjt_functionParam205);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        sjt_parent125 = &sjv_newdata;
        sjt_functionParam207 = sjv_newcount;
        sjt_cast12 = 0;
        sjt_functionParam208 = (char)sjt_cast12;
        sjf_array_char_initat(sjt_parent125, sjt_functionParam207, sjt_functionParam208);
        _return->_refCount = 1;
        _return->count = sjv_newcount;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&sjv_newdata));
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char sjv_newdata = { -1 };

    if ((item->count == 0)) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = _parent->count;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, (&_parent->data));
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_cast13;
        int32_t sjt_forEnd17;
        int32_t sjt_forStart17;
        int32_t sjt_functionParam209;
        int32_t sjt_functionParam210;
        char sjt_functionParam211;
        int32_t sjt_functionParam212;
        int32_t sjt_functionParam216;
        char sjt_functionParam217;
        sjs_array_char* sjt_parent126 = 0;
        sjs_array_char* sjt_parent127 = 0;
        sjs_string* sjt_parent128 = 0;
        sjs_array_char* sjt_parent131 = 0;
        int32_t sjv_newcount;

        sjt_parent126 = &_parent->data;
        sjt_functionParam209 = (_parent->count + item->count) + 1;
        sjf_array_char_grow(sjt_parent126, sjt_functionParam209, &sjv_newdata);
        sjv_newcount = _parent->count;
        sjt_parent127 = &sjv_newdata;
        sjt_functionParam210 = sjv_newcount;
        sjt_parent128 = item;
        sjt_functionParam212 = 0;
        sjf_string_getat(sjt_parent128, sjt_functionParam212, &sjt_functionParam211);
        sjf_array_char_setat(sjt_parent127, sjt_functionParam210, sjt_functionParam211);
        sjv_newcount = sjv_newcount + 1;
        sjt_forStart17 = 1;
        sjt_forEnd17 = item->count;
        i = sjt_forStart17;
        while (i < sjt_forEnd17) {
            int32_t sjt_functionParam213;
            char sjt_functionParam214;
            int32_t sjt_functionParam215;
            sjs_array_char* sjt_parent129 = 0;
            sjs_string* sjt_parent130 = 0;

            sjt_parent129 = &sjv_newdata;
            sjt_functionParam213 = sjv_newcount;
            sjt_parent130 = item;
            sjt_functionParam215 = i;
            sjf_string_getat(sjt_parent130, sjt_functionParam215, &sjt_functionParam214);
            sjf_array_char_initat(sjt_parent129, sjt_functionParam213, sjt_functionParam214);
            sjv_newcount = sjv_newcount + 1;
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
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, (&sjv_newdata));
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
    int32_t sjt_functionParam202;
    sjs_array_char* sjt_parent121 = 0;

    sjt_parent121 = &_parent->data;
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
    sjs_array_char* sjt_functionParam9 = 0;
    sjs_array_char* sjt_parent1 = 0;

    sjt_parent1 = &_parent->data;
    sjt_functionParam9 = &test->data;
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
    object1->shader._refCount = 1;
    sjf_shader_copy(&object1->shader, (&sjv_phongtextureshader));
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
    result10 = -5.0f;
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
    sjt_call130->color._refCount = 1;
    sjf_color_copy(&sjt_call130->color, (&sjv_colors_white));
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
    _return->_refCount = 1;
    sjf_rect_copy(_return, (&_parent->_rect));
}

void sjf_textelement_getrect_heap(sjs_textelement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), (&_parent->_rect));
}

void sjf_textelement_getsize(sjs_textelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    if (((_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0) != 0)) {
        sjs_size* ifValue9 = 0;
        sjs_size* sjt_functionParam356 = 0;
        sjs_size* sjt_parent246 = 0;

        ifValue9 = (_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0);
        sjt_parent246 = ifValue9;
        sjt_functionParam356 = maxsize;
        sjf_size_min(sjt_parent246, sjt_functionParam356, _return);
    } else {
        sjs_size sjt_call131 = { -1 };
        sjs_string* sjt_functionParam357 = 0;
        sjs_margin* sjt_functionParam358 = 0;
        sjs_size* sjt_functionParam359 = 0;
        sjs_size* sjt_parent247 = 0;
        sjs_font* sjt_parent248 = 0;
        sjs_size* sjt_parent249 = 0;
        sjs_size sjv_textsize = { -1 };

        sjt_parent248 = _parent->font;
        sjt_functionParam357 = &_parent->text;
        sjf_font_gettextsize(sjt_parent248, sjt_functionParam357, &sjt_call131);
        sjt_parent247 = &sjt_call131;
        sjt_functionParam358 = &_parent->margin;
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
    if (((_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0) != 0)) {
        sjs_size* ifValue12 = 0;
        sjs_size* sjt_functionParam360 = 0;
        sjs_size* sjt_parent250 = 0;

        ifValue12 = (_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0);
        sjt_parent250 = ifValue12;
        sjt_functionParam360 = maxsize;
        sjf_size_min_heap(sjt_parent250, sjt_functionParam360, _return);
    } else {
        sjs_size sjt_call132 = { -1 };
        sjs_string* sjt_functionParam361 = 0;
        sjs_margin* sjt_functionParam362 = 0;
        sjs_size* sjt_functionParam363 = 0;
        sjs_size* sjt_parent251 = 0;
        sjs_font* sjt_parent252 = 0;
        sjs_size* sjt_parent253 = 0;
        sjs_size sjv_textsize = { -1 };

        sjt_parent252 = _parent->font;
        sjt_functionParam361 = &_parent->text;
        sjf_font_gettextsize(sjt_parent252, sjt_functionParam361, &sjt_call132);
        sjt_parent251 = &sjt_call132;
        sjt_functionParam362 = &_parent->margin;
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
    _return->_refCount = 1;
    sjf_string_copy(_return, (&_parent->text));
}

void sjf_textelement_gettext_heap(sjs_textelement* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    sjf_string_copy((*_return), (&_parent->text));
}

void sjf_textelement_heap(sjs_textelement* _this) {
    if (((_this->id._refCount != -1 ? &_this->id : 0) != 0)) {
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
    sjs_rect sjv_innerrect = { -1 };
    sjs_size sjv_textsize = { -1 };

    if (((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) == 0)) {
        sjs_string* sjt_functionParam365 = 0;
        sjs_margin* sjt_functionParam366 = 0;
        sjs_font* sjt_parent255 = 0;
        sjs_rect* sjt_parent256 = 0;
        int32_t sjv_x;
        int32_t sjv_y;
        int32_t underscore1;
        int32_t underscore2;

        sjt_parent255 = _parent->font;
        sjt_functionParam365 = &_parent->text;
        sjf_font_gettextsize(sjt_parent255, sjt_functionParam365, &sjv_textsize);
        sjt_parent256 = &_parent->_rect;
        sjt_functionParam366 = &_parent->margin;
        sjf_rect_subtractmargin(sjt_parent256, sjt_functionParam366, &sjv_innerrect);
        underscore1 = _parent->halign;
        if ((underscore1 == sjv_texthorizontal_left)) {
            sjv_x = (&sjv_innerrect)->x;
        } else {
            if ((underscore1 == sjv_texthorizontal_right)) {
                sjv_x = ((&sjv_innerrect)->x + (&sjv_innerrect)->w) - (&sjv_textsize)->w;
            } else {
                if ((underscore1 == sjv_texthorizontal_center)) {
                    sjv_x = (&sjv_innerrect)->x + (((&sjv_innerrect)->w - (&sjv_textsize)->w) / 2);
                } else {
                    sjv_x = 0;
                }
            }
        }

        underscore2 = _parent->valign;
        if ((underscore2 == sjv_textvertical_top)) {
            sjv_y = (&sjv_innerrect)->y;
        } else {
            if ((underscore2 == sjv_textvertical_bottom)) {
                sjv_y = ((&sjv_innerrect)->y + (&sjv_innerrect)->h) - (&sjv_textsize)->h;
            } else {
                if ((underscore2 == sjv_textvertical_center)) {
                    sjv_y = (&sjv_innerrect)->y + (((&sjv_innerrect)->h - (&sjv_textsize)->h) / 2);
                } else {
                    sjv_y = 0;
                }
            }
        }

        sjt_call133._refCount = 1;
        sjt_call133.text._refCount = 1;
        sjf_string_copy(&sjt_call133.text, (&_parent->text));
        sjt_call133.point._refCount = 1;
        sjt_call133.point.x = sjv_x;
        sjt_call133.point.y = sjv_y;
        sjf_point(&sjt_call133.point);
        sjt_call133.color._refCount = 1;
        sjf_color_copy(&sjt_call133.color, (&_parent->color));
        sjt_call133.font._refCount = 1;
        sjf_font_copy(&sjt_call133.font, _parent->font);
        sjf_textrenderer(&sjt_call133);
        if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
        _parent->_textrenderer._refCount = 1;
        sjf_textrenderer_copy(&_parent->_textrenderer, (&sjt_call133));
    }

    if (((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) != 0)) {
        sjs_scene2d* sjt_functionParam386 = 0;
        sjs_textrenderer* sjt_parent257 = 0;

        sjt_parent257 = (_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0);
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
    bool sjt_capture36;
    sjs_rect* sjt_functionParam364 = 0;
    sjs_rect* sjt_parent254 = 0;

    sjt_parent254 = &_parent->_rect;
    sjt_functionParam364 = rect_;
    sjf_rect_isequal(sjt_parent254, sjt_functionParam364, &sjt_capture36);
    result11 = !sjt_capture36;
    if (result11) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
        _parent->_rect._refCount = 1;
        sjf_rect_copy(&_parent->_rect, rect_);
        if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
        _parent->_textrenderer._refCount = -1;
    }
}

void sjf_textelement_settext(sjs_textelement* _parent, sjs_string* text_) {
    if (_parent->text._refCount == 1) { sjf_string_destroy(&_parent->text); }
;
    _parent->text._refCount = 1;
    sjf_string_copy(&_parent->text, text_);
    if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
    _parent->_textrenderer._refCount = -1;
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
    sjt_functionParam377 = &scene->model;
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
    sjt_functionParam381 = &scene->view;
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
    sjt_functionParam385 = &scene->projection;
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
    float sjt_functionParam236;
    sjs_string* sjt_functionParam237 = 0;
    sjs_string* sjt_functionParam238 = 0;
    float sjt_functionParam239;
    sjs_string* sjt_parent146 = 0;
    sjs_string* sjt_parent147 = 0;

    sjt_functionParam236 = _parent->x;
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
    sjt_functionParam239 = _parent->y;
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
    float sjt_functionParam240;
    sjs_string* sjt_functionParam241 = 0;
    sjs_string* sjt_functionParam242 = 0;
    float sjt_functionParam243;
    sjs_string* sjt_parent148 = 0;
    sjs_string* sjt_parent149 = 0;

    sjt_functionParam240 = _parent->x;
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
    sjt_functionParam243 = _parent->y;
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
    _return->_refCount = 1;
    _return->x = _parent->x + v->x;
    _return->y = _parent->y + v->y;
    _return->z = _parent->z + v->z;
    sjf_vec3(_return);
}

void sjf_vec3_add_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    (*_return)->x = _parent->x + v->x;
    (*_return)->y = _parent->y + v->y;
    (*_return)->z = _parent->z + v->z;
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

    sjt_functionParam218 = _parent->x;
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
    sjt_functionParam221 = _parent->y;
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
    sjt_functionParam224 = _parent->z;
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

    sjt_functionParam225 = _parent->x;
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
    sjt_functionParam228 = _parent->y;
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
    sjt_functionParam231 = _parent->z;
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
    _return->_refCount = 1;
    _return->x = (_parent->y * v->z) - (_parent->z * v->y);
    _return->y = (_parent->z * v->x) - (_parent->x * v->z);
    _return->z = (_parent->x * v->y) - (_parent->y * v->x);
    sjf_vec3(_return);
}

void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    (*_return)->x = (_parent->y * v->z) - (_parent->z * v->y);
    (*_return)->y = (_parent->z * v->x) - (_parent->x * v->z);
    (*_return)->z = (_parent->x * v->y) - (_parent->y * v->x);
    sjf_vec3_heap((*_return));
}

void sjf_vec3_destroy(sjs_vec3* _this) {
}

void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return) {
    (*_return) = (_parent->x * v->x) + (_parent->y * v->y) + (_parent->z * v->z);
}

void sjf_vec3_getrawsize(int32_t* _return) {
    int x = sizeof(float) * 3;
    (*_return) = x;
return;;
}

void sjf_vec3_heap(sjs_vec3* _this) {
}

void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return) {
    float sjt_functionParam73;
    float sjv_t;

    sjt_functionParam73 = (_parent->x * _parent->x) + (_parent->y * _parent->y) + (_parent->z * _parent->z);
    sjf_f32_sqrt(sjt_functionParam73, &sjv_t);
    _return->_refCount = 1;
    _return->x = _parent->x / sjv_t;
    _return->y = _parent->y / sjv_t;
    _return->z = _parent->z / sjv_t;
    sjf_vec3(_return);
}

void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3** _return) {
    float sjt_functionParam74;
    float sjv_t;

    sjt_functionParam74 = (_parent->x * _parent->x) + (_parent->y * _parent->y) + (_parent->z * _parent->z);
    sjf_f32_sqrt(sjt_functionParam74, &sjv_t);
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    (*_return)->x = _parent->x / sjv_t;
    (*_return)->y = _parent->y / sjv_t;
    (*_return)->z = _parent->z / sjv_t;
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
    _return->_refCount = 1;
    _return->x = _parent->x - v->x;
    _return->y = _parent->y - v->y;
    _return->z = _parent->z - v->z;
    sjf_vec3(_return);
}

void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    (*_return)->x = _parent->x - v->x;
    (*_return)->y = _parent->y - v->y;
    (*_return)->z = _parent->z - v->z;
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
    int32_t sjt_capture27;
    int32_t sjt_capture28;
    int32_t sjt_capture29;

    sjf_vec3_getrawsize(&sjt_capture27);
    sjf_vec2_getrawsize(&sjt_capture28);
    sjf_vec3_getrawsize(&sjt_capture29);
    (*_return) = (sjt_capture27 + sjt_capture28) + sjt_capture29;
}

void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_rawcopy(sjs_vertex_location_texture_normal* v, void* p, void** _return) {
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
    sjt_functionParam142 = &v->location;
    sjt_functionParam143 = p;
    sjf_vec3_rawcopy(sjt_functionParam142, sjt_functionParam143, &p);
    sjt_funcold2 = p;
    sjt_functionParam144 = &v->texture;
    sjt_functionParam145 = p;
    sjf_vec2_rawcopy(sjt_functionParam144, sjt_functionParam145, &p);
    sjt_funcold3 = p;
    sjt_functionParam146 = &v->normal;
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
    int32_t sjt_functionParam197;
    sjs_string* sjt_functionParam198 = 0;
    sjs_string* sjt_functionParam232 = 0;
    sjs_string* sjt_functionParam233 = 0;
    sjs_string* sjt_functionParam234 = 0;
    sjs_string* sjt_functionParam235 = 0;
    sjs_vertex_location_texture_normal* sjt_functionParam249 = 0;
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
            sjt_call71.location._refCount = 1;
            sjf_vec3_copy(&sjt_call71.location, (&sjv_location));
            sjt_call71.texture._refCount = 1;
            sjf_vec2_copy(&sjt_call71.texture, (&sjv_texture));
            sjt_call71.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call71.normal, (&sjv_normal));
            sjf_vertex_location_texture_normal(&sjt_call71);
            sjt_functionParam249 = &sjt_call71;
            sjf_list_vertex_location_texture_normal_add(sjt_parent153, sjt_functionParam249);
        }
    }
    delete_obj_data(&data);
    result6 = !sjv_includenormals;
    if (result6) {
        int32_t i;
        int32_t sjt_capture32;
        int32_t sjt_forEnd18;
        int32_t sjt_forEnd19;
        int32_t sjt_forEnd20;
        int32_t sjt_forStart18;
        int32_t sjt_forStart19;
        int32_t sjt_forStart20;
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
        sjf_list_i32_getcount(sjt_parent157, &sjt_capture32);
        sjt_forEnd19 = sjt_capture32 / 3;
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
            sjt_functionParam253 = (i * 3) + 0;
            sjf_list_i32_getat(sjt_parent159, sjt_functionParam253, &sjv_i1);
            sjt_parent160 = &sjv_indices;
            sjt_functionParam254 = (i * 3) + 1;
            sjf_list_i32_getat(sjt_parent160, sjt_functionParam254, &sjv_i2);
            sjt_parent161 = &sjv_indices;
            sjt_functionParam255 = (i * 3) + 2;
            sjf_list_i32_getat(sjt_parent161, sjt_functionParam255, &sjv_i3);
            sjt_parent163 = &sjv_vertices;
            sjt_functionParam257 = sjv_i1;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent163, sjt_functionParam257, &sjt_call73);
            sjv_v1._refCount = 1;
            sjf_vec3_copy(&sjv_v1, (&(&sjt_call73)->location));
            sjt_parent164 = &sjv_vertices;
            sjt_functionParam258 = sjv_i2;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent164, sjt_functionParam258, &sjt_call74);
            sjv_v2._refCount = 1;
            sjf_vec3_copy(&sjv_v2, (&(&sjt_call74)->location));
            sjt_parent165 = &sjv_vertices;
            sjt_functionParam259 = sjv_i3;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent165, sjt_functionParam259, &sjt_call75);
            sjv_v3._refCount = 1;
            sjf_vec3_copy(&sjv_v3, (&(&sjt_call75)->location));
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
            sjt_call84.location._refCount = 1;
            sjf_vec3_copy(&sjt_call84.location, (&(&sjt_call85)->location));
            sjt_parent185 = &sjv_vertices;
            sjt_functionParam281 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent185, sjt_functionParam281, &sjt_call86);
            sjt_call84.texture._refCount = 1;
            sjf_vec2_copy(&sjt_call84.texture, (&(&sjt_call86)->texture));
            sjt_call84.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call84.normal, (&sjv_newnormal));
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

    result7 = !sjv_includetextures;
    if (result7) {
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
            sjt_functionParam283 = (&(&sjt_call87)->location)->y;
            sjf_f32_min(sjt_functionParam282, sjt_functionParam283, &sjv_ymin);
            sjt_funcold5 = sjv_ymax;
            sjt_functionParam285 = sjv_ymax;
            sjt_parent188 = &sjv_vertices;
            sjt_functionParam287 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent188, sjt_functionParam287, &sjt_call88);
            sjt_functionParam286 = (&(&sjt_call88)->location)->y;
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
            float sjt_capture33;
            float sjt_functionParam288;
            int32_t sjt_functionParam289;
            float sjt_functionParam290;
            int32_t sjt_functionParam291;
            int32_t sjt_functionParam292;
            int32_t sjt_functionParam293;
            sjs_vertex_location_texture_normal* sjt_functionParam294 = 0;
            int32_t sjt_functionParam295;
            int32_t sjt_functionParam296;
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
            sjt_functionParam288 = (&(&sjt_call89)->location)->x;
            sjt_parent191 = &sjv_vertices;
            sjt_functionParam291 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent191, sjt_functionParam291, &sjt_call90);
            sjt_functionParam290 = (&(&sjt_call90)->location)->z;
            sjf_f32_atan2(sjt_functionParam288, sjt_functionParam290, &sjt_capture33);
            sjv_s = (sjt_capture33 + sjv_f32_pi) / (2.0f * sjv_f32_pi);
            sjt_parent192 = &sjv_vertices;
            sjt_functionParam292 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent192, sjt_functionParam292, &sjt_call91);
            sjv_t = ((&(&sjt_call91)->location)->y - sjv_ymin) / (sjv_ymax - sjv_ymin);
            sjt_parent193 = &sjv_vertices;
            sjt_functionParam293 = i;
            sjt_call92._refCount = 1;
            sjt_parent194 = &sjv_vertices;
            sjt_functionParam295 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent194, sjt_functionParam295, &sjt_call93);
            sjt_call92.location._refCount = 1;
            sjf_vec3_copy(&sjt_call92.location, (&(&sjt_call93)->location));
            sjt_call92.texture._refCount = 1;
            sjt_call92.texture.x = sjv_s;
            sjt_call92.texture.y = sjv_t;
            sjf_vec2(&sjt_call92.texture);
            sjt_parent195 = &sjv_vertices;
            sjt_functionParam296 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent195, sjt_functionParam296, &sjt_call94);
            sjt_call92.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call92.normal, (&(&sjt_call94)->normal));
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
    _return->format._refCount = 1;
    sjf_string_copy(&_return->format, (&sjv_vertex_location_texture_normal_format));
    _return->indices._refCount = 1;
    sjf_array_i32_copy(&_return->indices, (&(&sjv_indices)->array));
    _return->vertices._refCount = 1;
    sjf_array_vertex_location_texture_normal_copy(&_return->vertices, (&(&sjv_vertices)->array));
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
    int32_t sjt_functionParam297;
    sjs_string* sjt_functionParam298 = 0;
    sjs_string* sjt_functionParam299 = 0;
    sjs_string* sjt_functionParam300 = 0;
    sjs_string* sjt_functionParam301 = 0;
    sjs_string* sjt_functionParam302 = 0;
    sjs_vertex_location_texture_normal* sjt_functionParam303 = 0;
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
            sjt_call104.location._refCount = 1;
            sjf_vec3_copy(&sjt_call104.location, (&sjv_location));
            sjt_call104.texture._refCount = 1;
            sjf_vec2_copy(&sjt_call104.texture, (&sjv_texture));
            sjt_call104.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call104.normal, (&sjv_normal));
            sjf_vertex_location_texture_normal(&sjt_call104);
            sjt_functionParam303 = &sjt_call104;
            sjf_list_vertex_location_texture_normal_add(sjt_parent204, sjt_functionParam303);
        }
    }
    delete_obj_data(&data);
    result8 = !sjv_includenormals;
    if (result8) {
        int32_t i;
        int32_t sjt_capture34;
        int32_t sjt_forEnd23;
        int32_t sjt_forEnd24;
        int32_t sjt_forEnd25;
        int32_t sjt_forStart23;
        int32_t sjt_forStart24;
        int32_t sjt_forStart25;
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
        sjf_list_i32_getcount(sjt_parent208, &sjt_capture34);
        sjt_forEnd24 = sjt_capture34 / 3;
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
            sjt_functionParam306 = (i * 3) + 0;
            sjf_list_i32_getat(sjt_parent209, sjt_functionParam306, &sjv_i1);
            sjt_parent210 = &sjv_indices;
            sjt_functionParam307 = (i * 3) + 1;
            sjf_list_i32_getat(sjt_parent210, sjt_functionParam307, &sjv_i2);
            sjt_parent211 = &sjv_indices;
            sjt_functionParam308 = (i * 3) + 2;
            sjf_list_i32_getat(sjt_parent211, sjt_functionParam308, &sjv_i3);
            sjt_parent212 = &sjv_vertices;
            sjt_functionParam309 = sjv_i1;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent212, sjt_functionParam309, &sjt_call106);
            sjv_v1._refCount = 1;
            sjf_vec3_copy(&sjv_v1, (&(&sjt_call106)->location));
            sjt_parent213 = &sjv_vertices;
            sjt_functionParam310 = sjv_i2;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent213, sjt_functionParam310, &sjt_call107);
            sjv_v2._refCount = 1;
            sjf_vec3_copy(&sjv_v2, (&(&sjt_call107)->location));
            sjt_parent214 = &sjv_vertices;
            sjt_functionParam311 = sjv_i3;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent214, sjt_functionParam311, &sjt_call108);
            sjv_v3._refCount = 1;
            sjf_vec3_copy(&sjv_v3, (&(&sjt_call108)->location));
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
            sjt_call117.location._refCount = 1;
            sjf_vec3_copy(&sjt_call117.location, (&(&sjt_call118)->location));
            sjt_parent233 = &sjv_vertices;
            sjt_functionParam331 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent233, sjt_functionParam331, &sjt_call119);
            sjt_call117.texture._refCount = 1;
            sjf_vec2_copy(&sjt_call117.texture, (&(&sjt_call119)->texture));
            sjt_call117.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call117.normal, (&sjv_newnormal));
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

    result9 = !sjv_includetextures;
    if (result9) {
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
            sjt_functionParam333 = (&(&sjt_call120)->location)->y;
            sjf_f32_min(sjt_functionParam332, sjt_functionParam333, &sjv_ymin);
            sjt_funcold7 = sjv_ymax;
            sjt_functionParam335 = sjv_ymax;
            sjt_parent236 = &sjv_vertices;
            sjt_functionParam337 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent236, sjt_functionParam337, &sjt_call121);
            sjt_functionParam336 = (&(&sjt_call121)->location)->y;
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
            float sjt_capture35;
            float sjt_functionParam338;
            int32_t sjt_functionParam339;
            float sjt_functionParam340;
            int32_t sjt_functionParam341;
            int32_t sjt_functionParam342;
            int32_t sjt_functionParam343;
            sjs_vertex_location_texture_normal* sjt_functionParam344 = 0;
            int32_t sjt_functionParam345;
            int32_t sjt_functionParam346;
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
            sjt_functionParam338 = (&(&sjt_call122)->location)->x;
            sjt_parent239 = &sjv_vertices;
            sjt_functionParam341 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent239, sjt_functionParam341, &sjt_call123);
            sjt_functionParam340 = (&(&sjt_call123)->location)->z;
            sjf_f32_atan2(sjt_functionParam338, sjt_functionParam340, &sjt_capture35);
            sjv_s = (sjt_capture35 + sjv_f32_pi) / (2.0f * sjv_f32_pi);
            sjt_parent240 = &sjv_vertices;
            sjt_functionParam342 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent240, sjt_functionParam342, &sjt_call124);
            sjv_t = ((&(&sjt_call124)->location)->y - sjv_ymin) / (sjv_ymax - sjv_ymin);
            sjt_parent241 = &sjv_vertices;
            sjt_functionParam343 = i;
            sjt_call125._refCount = 1;
            sjt_parent242 = &sjv_vertices;
            sjt_functionParam345 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent242, sjt_functionParam345, &sjt_call126);
            sjt_call125.location._refCount = 1;
            sjf_vec3_copy(&sjt_call125.location, (&(&sjt_call126)->location));
            sjt_call125.texture._refCount = 1;
            sjt_call125.texture.x = sjv_s;
            sjt_call125.texture.y = sjv_t;
            sjf_vec2(&sjt_call125.texture);
            sjt_parent243 = &sjv_vertices;
            sjt_functionParam346 = i;
            sjf_list_vertex_location_texture_normal_getat(sjt_parent243, sjt_functionParam346, &sjt_call127);
            sjt_call125.normal._refCount = 1;
            sjf_vec3_copy(&sjt_call125.normal, (&(&sjt_call127)->normal));
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
    (*_return)->format._refCount = 1;
    sjf_string_copy(&(*_return)->format, (&sjv_vertex_location_texture_normal_format));
    (*_return)->indices._refCount = 1;
    sjf_array_i32_copy(&(*_return)->indices, (&(&sjv_indices)->array));
    (*_return)->vertices._refCount = 1;
    sjf_array_vertex_location_texture_normal_copy(&(*_return)->vertices, (&(&sjv_vertices)->array));
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
    sjv_log._refCount = 1;
    sjv_log.minlevel = sjv_loglevel_warn;
    sjf_log(&sjv_log);
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
    sjv_mainloop_lasttick = 0;
    sjv_mainloop_frames = 0;
    sjv_mainloop_showfps = false;
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
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
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
