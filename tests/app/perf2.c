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
#include <gl/glu.h>
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
const char* sjg_string16 = "FPS: ";
const char* sjg_string17 = "viewport being pop'ed is wrong";
const char* sjg_string2 = "shaders/blur-horizontal.frag";
const char* sjg_string3 = "shaders/blur-vertical.frag";
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
#define sjs_log_typeId 36
#define sjs_windowrenderer_typeId 37
#define sjs_color_typeId 39
#define sjs_size_typeId 43
#define sjs_mat4_typeId 44
#define sjs_rect_typeId 45
#define sjs_scene2d_typeId 42
#define sjs_array_char_typeId 55
#define sjs_string_typeId 46
#define sjs_vec3_typeId 48
#define sjs_light_typeId 47
#define sji_model_typeId 49
#define sjs_array_heap_iface_model_typeId 153
#define sjs_list_heap_iface_model_typeId 50
#define sjs_point_typeId 152
#define sjs_mouseevent_typeId 51
#define sjs_hash_string_weak_iface_model_typeId 52
#define sji_element_typeId 59
#define sjs_hash_string_weak_iface_element_typeId 60
#define sjs_array_heap_iface_animation_typeId 66
#define sjs_list_heap_iface_animation_typeId 65
#define sjs_animator_typeId 63
#define sji_animation_typeId 64
#define sjs_shader_typeId 67
#define sjs_fontkey_typeId 68
#define sjs_font_typeId 69
#define sjs_hash_fontkey_weak_font_typeId 70
#define sjs_array_rect_typeId 77
#define sjs_list_rect_typeId 76
#define sjs_array_u32_typeId 79
#define sjs_list_u32_typeId 78
#define sjs_style_typeId 80
#define sjs_vec4_typeId 81
#define sjs_array_bool_typeId 82
#define sjs_array_f32_typeId 87
#define sjs_test_typeId 86

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
typedef struct td_sjs_vec4 sjs_vec4;
typedef struct td_sjs_array_bool sjs_array_bool;
typedef struct td_sjs_array_f32 sjs_array_f32;
typedef struct td_sjs_test sjs_test;

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

struct td_sjs_vec4 {
    int _refCount;
    float x;
    float y;
    float z;
    float w;
};

struct td_sjs_array_bool {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_array_f32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_test {
    int _refCount;
    int32_t funcid;
    int32_t lastfuncid;
    sjs_array_f32 datax;
    sjs_array_f32 datay;
    float rotatex;
    float rotatey;
    float rotatez;
    sjs_array_f32 datavert1x;
    sjs_array_f32 datavert1y;
    sjs_array_f32 datavert2x;
    sjs_array_f32 datavert2y;
    sjs_array_f32 datavert3x;
    sjs_array_f32 datavert3y;
    sjs_array_f32 datavert4x;
    sjs_array_f32 datavert4y;
    sjs_array_f32 datavert5x;
    sjs_array_f32 datavert5y;
    sjs_array_f32 datahotizont1x;
    sjs_array_f32 datahotizont1y;
    sjs_array_f32 datahotizont2x;
    sjs_array_f32 datahotizont2y;
    sjs_array_f32 datahotizont3x;
    sjs_array_f32 datahotizont3y;
    sjs_array_f32 datahotizont4x;
    sjs_array_f32 datahotizont4y;
    sjs_array_f32 datahotizont5x;
    sjs_array_f32 datahotizont5y;
    sjs_rect _rect;
};

sji_element_vtbl sjs_test_element_vtbl;
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
float result2;
sjs_array_f32 sjt_call10 = { -1 };
sjs_array_f32 sjt_call11 = { -1 };
sjs_array_f32 sjt_call12 = { -1 };
sjs_array_f32 sjt_call13 = { -1 };
sjs_array_f32 sjt_call14 = { -1 };
sjs_array_f32 sjt_call15 = { -1 };
sjs_array_f32 sjt_call16 = { -1 };
sjs_array_f32 sjt_call17 = { -1 };
sjs_array_f32 sjt_call18 = { -1 };
sjs_array_f32 sjt_call19 = { -1 };
sjs_array_f32 sjt_call20 = { -1 };
sjs_array_f32 sjt_call21 = { -1 };
sjs_array_f32 sjt_call22 = { -1 };
sjs_array_f32 sjt_call23 = { -1 };
sjs_array_f32 sjt_call24 = { -1 };
sjs_array_f32 sjt_call25 = { -1 };
sjs_size sjt_call26 = { -1 };
sjs_test sjt_call3 = { -1 };
sjs_array_f32 sjt_call4 = { -1 };
sjs_array_f32 sjt_call5 = { -1 };
sjs_array_f32 sjt_call6 = { -1 };
sjs_array_f32 sjt_call7 = { -1 };
sjs_array_f32 sjt_call8 = { -1 };
sjs_array_f32 sjt_call9 = { -1 };
float sjt_cast1;
int32_t sjt_cast2;
float sjt_cast3;
int32_t sjt_cast4;
sjs_test* sjt_cast5 = 0;
int32_t sjt_functionParam12;
bool sjt_functionParam13;
int32_t sjt_functionParam14;
bool sjt_functionParam15;
int32_t sjt_functionParam16;
bool sjt_functionParam17;
int32_t sjt_functionParam18;
bool sjt_functionParam19;
int32_t sjt_functionParam20;
bool sjt_functionParam21;
int32_t sjt_functionParam22;
bool sjt_functionParam23;
int32_t sjt_functionParam24;
bool sjt_functionParam25;
int32_t sjt_functionParam26;
bool sjt_functionParam27;
float sjt_functionParam460;
float sjt_functionParam461;
float sjt_functionParam462;
float sjt_functionParam463;
float sjt_functionParam464;
float sjt_functionParam465;
float sjt_functionParam466;
float sjt_functionParam467;
float sjt_functionParam468;
float sjt_functionParam469;
float sjt_functionParam470;
float sjt_functionParam471;
float sjt_functionParam472;
float sjt_functionParam473;
float sjt_functionParam474;
float sjt_functionParam475;
float sjt_functionParam476;
float sjt_functionParam477;
float sjt_functionParam478;
float sjt_functionParam479;
float sjt_functionParam480;
float sjt_functionParam481;
sjs_size* sjt_functionParam482 = 0;
sjs_array_bool* sjt_parent10 = 0;
sjs_array_bool* sjt_parent11 = 0;
sjs_array_f32* sjt_parent163 = 0;
sjs_array_f32* sjt_parent164 = 0;
sjs_array_f32* sjt_parent165 = 0;
sjs_array_f32* sjt_parent166 = 0;
sjs_array_f32* sjt_parent167 = 0;
sjs_array_f32* sjt_parent168 = 0;
sjs_array_f32* sjt_parent169 = 0;
sjs_array_f32* sjt_parent170 = 0;
sjs_array_f32* sjt_parent171 = 0;
sjs_array_f32* sjt_parent172 = 0;
sjs_array_f32* sjt_parent173 = 0;
sjs_array_f32* sjt_parent174 = 0;
sjs_array_f32* sjt_parent175 = 0;
sjs_array_f32* sjt_parent176 = 0;
sjs_array_f32* sjt_parent177 = 0;
sjs_array_f32* sjt_parent178 = 0;
sjs_array_f32* sjt_parent179 = 0;
sjs_array_f32* sjt_parent180 = 0;
sjs_array_f32* sjt_parent181 = 0;
sjs_array_f32* sjt_parent182 = 0;
sjs_array_f32* sjt_parent183 = 0;
sjs_array_f32* sjt_parent184 = 0;
sjs_windowrenderer* sjt_parent185 = 0;
sjs_array_bool* sjt_parent4 = 0;
sjs_array_bool* sjt_parent5 = 0;
sjs_array_bool* sjt_parent6 = 0;
sjs_array_bool* sjt_parent7 = 0;
sjs_array_bool* sjt_parent8 = 0;
sjs_array_bool* sjt_parent9 = 0;
sjs_vec4 sjv_a_light = { -1 };
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
int32_t sjv_dots;
int32_t sjv_dotsscale;
sjs_hash_string_weak_iface_element sjv_elementsbyid = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
sjs_shader sjv_fadeshader = { -1 };
sjs_hash_fontkey_weak_font sjv_fonthash = { -1 };
sjs_list_u32 sjv_glframebuffers = { -1 };
sjs_list_rect sjv_glviewports = { -1 };
int32_t sjv_height;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_shader sjv_imageshader = { -1 };
int32_t sjv_img_dots;
int32_t sjv_img_dotsscale;
sjs_vec4 sjv_l_pos = { -1 };
sjs_log sjv_log = { -1 };
sjs_rect sjv_looplastrect = { -1 };
int32_t sjv_mainloop_frames;
int32_t sjv_mainloop_lasttick;
bool sjv_mainloop_shouldcontinue;
bool sjv_mainloop_showfps;
sjs_array_bool sjv_mainrot = { -1 };
sjs_hash_string_weak_iface_model sjv_modelsbyid = { -1 };
sji_element sjv_mouse_captureelement = { 0 };
int32_t sjv_oncept;
float sjv_persp;
sjs_shader sjv_phongcolorshader = { -1 };
sjs_shader sjv_phongtextureshader = { -1 };
sji_element sjv_root = { 0 };
sjs_scene2d sjv_rootscene = { -1 };
sjs_windowrenderer sjv_rootwindowrenderer = { -1 };
float sjv_rotateradius;
sjs_vec4 sjv_s_light = { -1 };
sjs_shader sjv_saturateshader = { -1 };
float sjv_scale;
sjs_array_bool sjv_stateof = { -1 };
sjs_array_bool sjv_stateofdir = { -1 };
sjs_style sjv_style = { -1 };
sjs_shader sjv_textshader = { -1 };
uint32_t sjv_u32_maxvalue;
sjs_string sjv_vertex_location_texture_normal_format = { -1 };
int32_t sjv_width;

void sjf_animator(sjs_animator* _this);
void sjf_animator_copy(sjs_animator* _this, sjs_animator* _from);
void sjf_animator_destroy(sjs_animator* _this);
void sjf_animator_heap(sjs_animator* _this);
void sjf_animator_nextframe(sjs_animator* _parent, int32_t time);
void sjf_array_bool(sjs_array_bool* _this);
void sjf_array_bool_copy(sjs_array_bool* _this, sjs_array_bool* _from);
void sjf_array_bool_destroy(sjs_array_bool* _this);
void sjf_array_bool_getat(sjs_array_bool* _parent, int32_t index, bool* _return);
void sjf_array_bool_heap(sjs_array_bool* _this);
void sjf_array_bool_initat(sjs_array_bool* _parent, int32_t index, bool item);
void sjf_array_bool_setat(sjs_array_bool* _parent, int32_t index, bool item);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_array_f32(sjs_array_f32* _this);
void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from);
void sjf_array_f32_destroy(sjs_array_f32* _this);
void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return);
void sjf_array_f32_heap(sjs_array_f32* _this);
void sjf_array_f32_init(sjs_array_f32* _parent, float item, sjs_array_f32* _return);
void sjf_array_f32_init_heap(sjs_array_f32* _parent, float item, sjs_array_f32** _return);
void sjf_array_f32_setat(sjs_array_f32* _parent, int32_t index, float item);
void sjf_array_heap_iface_animation(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_animation_copy(sjs_array_heap_iface_animation* _this, sjs_array_heap_iface_animation* _from);
void sjf_array_heap_iface_animation_destroy(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_animation_getat_heap(sjs_array_heap_iface_animation* _parent, int32_t index, sji_animation* _return);
void sjf_array_heap_iface_animation_heap(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_model(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from);
void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this);
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
void sjf_color(sjs_color* _this);
void sjf_color_copy(sjs_color* _this, sjs_color* _from);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_f32_abs(float v, float* _return);
void sjf_f32_asstring(float val, sjs_string* _return);
void sjf_f32_asstring_heap(float val, sjs_string** _return);
void sjf_f32_cos(float v, float* _return);
void sjf_f32_exp(float v, float* _return);
void sjf_f32_hash(float val, uint32_t* _return);
void sjf_f32_pow(float x, float y, float* _return);
void sjf_f32_sin(float v, float* _return);
void sjf_f32_sqrt(float v, float* _return);
void sjf_f32_tan(float v, float* _return);
void sjf_font(sjs_font* _this);
void sjf_font_copy(sjs_font* _this, sjs_font* _from);
void sjf_font_destroy(sjs_font* _this);
void sjf_font_heap(sjs_font* _this);
void sjf_fontkey(sjs_fontkey* _this);
void sjf_fontkey_copy(sjs_fontkey* _this, sjs_fontkey* _from);
void sjf_fontkey_destroy(sjs_fontkey* _this);
void sjf_fontkey_hash(sjs_fontkey* _parent, uint32_t* _return);
void sjf_fontkey_heap(sjs_fontkey* _this);
void sjf_fontkey_isequal(sjs_fontkey* _parent, sjs_fontkey* x, bool* _return);
void sjf_glbeginpoints(void);
void sjf_glblendfunc(int32_t sfactor, int32_t dfactor);
void sjf_glclearcolor(sjs_color* color);
void sjf_glcolor3f(float r, float g, float b);
void sjf_glenable(int32_t feature);
void sjf_glend(void);
void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect);
void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect);
void sjf_glrotated(float r, float x, float y, float z);
void sjf_glvertex3f(float x, float y, float z);
void sjf_halt(sjs_string* reason);
void sjf_hash_fontkey_weak_font(sjs_hash_fontkey_weak_font* _this);
void sjf_hash_fontkey_weak_font__weakptrremovekey(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key);
void sjf_hash_fontkey_weak_font__weakptrremovevalue(sjs_hash_fontkey_weak_font* _parent, sjs_font* val);
void sjf_hash_fontkey_weak_font_copy(sjs_hash_fontkey_weak_font* _this, sjs_hash_fontkey_weak_font* _from);
void sjf_hash_fontkey_weak_font_destroy(sjs_hash_fontkey_weak_font* _this);
void sjf_hash_fontkey_weak_font_heap(sjs_hash_fontkey_weak_font* _this);
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
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_mainloop(void);
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
void sjf_size_copy(sjs_size* _this, sjs_size* _from);
void sjf_size_destroy(sjs_size* _this);
void sjf_size_heap(sjs_size* _this);
void sjf_size_isequal(sjs_size* _parent, sjs_size* size, bool* _return);
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
void sjf_style_heap(sjs_style* _this);
void sjf_test(sjs_test* _this);
void sjf_test_as_sji_element(sjs_test* _this, sji_element* _return);
void sjf_test_asinterface(sjs_test* _this, int typeId, sjs_interface* _return);
void sjf_test_calculate(sjs_test* _parent);
void sjf_test_copy(sjs_test* _this, sjs_test* _from);
void sjf_test_destroy(sjs_test* _this);
void sjf_test_findaxis(sjs_test* _parent);
void sjf_test_firemouseevent(sjs_test* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_test_getclasstype(sjs_object* _this, int* _return);
void sjf_test_getrect(sjs_test* _parent, sjs_rect* _return);
void sjf_test_getrect_heap(sjs_test* _parent, sjs_rect** _return);
void sjf_test_getsize(sjs_test* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_test_getsize_heap(sjs_test* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_test_gett(sjs_test* _parent, int32_t xpi, int32_t n, float* _return);
void sjf_test_gettm(sjs_test* _parent, int32_t xpi, int32_t n, float* _return);
void sjf_test_heap(sjs_test* _this);
void sjf_test_img_gettm(sjs_test* _parent, int32_t xpi, int32_t n, float* _return);
void sjf_test_imgdata_functionlist(sjs_test* _parent);
void sjf_test_render(sjs_test* _parent, sjs_scene2d* scene);
void sjf_test_setrect(sjs_test* _parent, sjs_rect* rect_);
void sjf_vec3(sjs_vec3* _this);
void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from);
void sjf_vec3_destroy(sjs_vec3* _this);
void sjf_vec3_heap(sjs_vec3* _this);
void sjf_vec4(sjs_vec4* _this);
void sjf_vec4_copy(sjs_vec4* _this, sjs_vec4* _from);
void sjf_vec4_destroy(sjs_vec4* _this);
void sjf_vec4_heap(sjs_vec4* _this);
void sjf_windowrender_disablevsync(void);
void sjf_windowrenderer(sjs_windowrenderer* _this);
void sjf_windowrenderer_copy(sjs_windowrenderer* _this, sjs_windowrenderer* _from);
void sjf_windowrenderer_destroy(sjs_windowrenderer* _this);
void sjf_windowrenderer_getsize(sjs_windowrenderer* _parent, sjs_size* _return);
void sjf_windowrenderer_getsize_heap(sjs_windowrenderer* _parent, sjs_size** _return);
void sjf_windowrenderer_heap(sjs_windowrenderer* _this);
void sjf_windowrenderer_present(sjs_windowrenderer* _parent);
void sjf_windowrenderer_setsize(sjs_windowrenderer* _parent, sjs_size* s);
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
    int32_t sjt_capture128;
    sjs_list_heap_iface_animation* sjt_parent186 = 0;

    _parent->current = time;
    sjt_parent186 = &_parent->animations;
    sjf_list_heap_iface_animation_getcount(sjt_parent186, &sjt_capture128);
    if (sjt_capture128 > 0) {
        int32_t i;
        int32_t sjt_forEnd21;
        int32_t sjt_forStart21;
        sjs_list_heap_iface_animation* sjt_parent187 = 0;

        sjt_forStart21 = 0;
        sjt_parent187 = &_parent->animations;
        sjf_list_heap_iface_animation_getcount(sjt_parent187, &sjt_forEnd21);
        i = sjt_forEnd21 - 1;
        while (i >= sjt_forStart21) {
            bool sjt_capture129;
            int32_t sjt_functionParam484;
            int32_t sjt_interfaceParam1;
            sjs_list_heap_iface_animation* sjt_parent189 = 0;
            sji_animation sjt_parent190 = { 0 };
            sji_animation sjv_a = { 0 };

            sjt_parent189 = &_parent->animations;
            sjt_functionParam484 = i;
            sjf_list_heap_iface_animation_getat_heap(sjt_parent189, sjt_functionParam484, &sjv_a);
            sjt_parent190 = sjv_a;
            sjt_interfaceParam1 = time;
            sjt_parent190._vtbl->nextframe(sjt_parent190._parent, sjt_interfaceParam1, &sjt_capture129);
            if (sjt_capture129) {
                int32_t sjt_functionParam485;
                sjs_list_heap_iface_animation* sjt_parent191 = 0;

                sjt_parent191 = &_parent->animations;
                sjt_functionParam485 = i;
                sjf_list_heap_iface_animation_removeat(sjt_parent191, sjt_functionParam485);
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

void sjf_array_bool(sjs_array_bool* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(bool) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_bool_copy(sjs_array_bool* _this, sjs_array_bool* _from) {
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

void sjf_array_bool_destroy(sjs_array_bool* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !true && !false
            bool* p = (bool*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
        }
    }
}

void sjf_array_bool_getat(sjs_array_bool* _parent, int32_t index, bool* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    bool* p = (bool*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_bool_heap(sjs_array_bool* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(bool) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_bool_initat(sjs_array_bool* _parent, int32_t index, bool item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    bool* p = (bool*)_parent->data;
    p[index] = item;
;
    _parent->count = index + 1;
}

void sjf_array_bool_setat(sjs_array_bool* _parent, int32_t index, bool item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    bool* p = (bool*)_parent->data;
    ;
    p[index] = item;
;
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

void sjf_array_f32(sjs_array_f32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(float) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from) {
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

void sjf_array_f32_destroy(sjs_array_f32* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !true && !false
            float* p = (float*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
        }
    }
}

void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    float* p = (float*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_f32_heap(sjs_array_f32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(float) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_f32_init(sjs_array_f32* _parent, float item, sjs_array_f32* _return) {
    if (0 != _parent->count) {
        halt("init: can only initialize a completely uninitialized list\n");     
    }
    float* p = (float*)_parent->data;
    int count = _parent->datasize;
    for (int i = 0; i < count; i++) {
        p[i] = item;
;
    }
    _parent->count = _parent->datasize;  
    _return->_refCount = 1;
    sjf_array_f32_copy(_return, _parent);
}

void sjf_array_f32_init_heap(sjs_array_f32* _parent, float item, sjs_array_f32** _return) {
    if (0 != _parent->count) {
        halt("init: can only initialize a completely uninitialized list\n");     
    }
    float* p = (float*)_parent->data;
    int count = _parent->datasize;
    for (int i = 0; i < count; i++) {
        p[i] = item;
;
    }
    _parent->count = _parent->datasize;  
    (*_return) = (sjs_array_f32*)malloc(sizeof(sjs_array_f32));
    (*_return)->_refCount = 1;
    sjf_array_f32_copy((*_return), _parent);
}

void sjf_array_f32_setat(sjs_array_f32* _parent, int32_t index, float item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    float* p = (float*)_parent->data;
    ;
    p[index] = item;
;
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
    sjs_string* sjt_parent195 = 0;

    sjt_parent195 = data;
    sjf_string_nullterminate(sjt_parent195);
    debugout("%s\n", (char*)data->data.data);
}

void sjf_f32_abs(float v, float* _return) {
    (*_return) = fabsf(v);
return;
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

void sjf_f32_cos(float v, float* _return) {
    float sjv_result;

    sjv_result = 0.0f;
    sjv_result = cosf(v);
    (*_return) = sjv_result;
}

void sjf_f32_exp(float v, float* _return) {
    (*_return) = expf(v);
return;
}

void sjf_f32_hash(float val, uint32_t* _return) {
    uint32_t sjv_result;

    sjv_result = (uint32_t)0u;
    int32_t* p = (int32_t*)&val;
    sjv_result = *p;
    (*_return) = sjv_result;
}

void sjf_f32_pow(float x, float y, float* _return) {
    (*_return) = powf(x, y);
return;;
}

void sjf_f32_sin(float v, float* _return) {
    float sjv_result;

    sjv_result = 0.0f;
    sjv_result = sinf(v);
    (*_return) = sjv_result;
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

void sjf_glbeginpoints(void) {
    glBegin(GL_POINTS);
}

void sjf_glblendfunc(int32_t sfactor, int32_t dfactor) {
    glBlendFunc(sfactor, dfactor);
}

void sjf_glclearcolor(sjs_color* color) {
    glClearColor(color->r, color->g, color->b, color->a);
}

void sjf_glcolor3f(float r, float g, float b) {
    glColor3f(r, g, b);
}

void sjf_glenable(int32_t feature) {
    glEnable(feature);
}

void sjf_glend(void) {
    glEnd();
}

void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect) {
    bool result40;
    sjs_rect sjt_call36 = { -1 };
    sjs_string sjt_call37 = { -1 };
    int32_t sjt_capture132;
    bool sjt_capture133;
    int32_t sjt_capture134;
    int32_t sjt_capture135;
    int32_t sjt_functionParam523;
    sjs_rect* sjt_functionParam524 = 0;
    int32_t sjt_functionParam526;
    sjs_rect* sjt_parent214 = 0;
    sjs_list_rect* sjt_parent216 = 0;
    sjs_list_rect* sjt_parent217 = 0;
    sjs_list_rect* sjt_parent219 = 0;
    sjs_list_rect* sjt_parent220 = 0;
    sjs_list_rect* sjt_parent221 = 0;
    sjs_rect sjv_newrect = { -1 };
    sjs_rect sjv_oldrect = { -1 };

    sjv_oldrect._refCount = 1;
    sjv_oldrect.x = rect->x;
    sjv_oldrect.y = scenerect->h - (rect->y + rect->h);
    sjv_oldrect.w = rect->w;
    sjv_oldrect.h = rect->h;
    sjf_rect(&sjv_oldrect);
    sjt_parent216 = &sjv_glviewports;
    sjt_parent217 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent217, &sjt_capture132);
    sjt_functionParam523 = sjt_capture132 - 1;
    sjf_list_rect_getat(sjt_parent216, sjt_functionParam523, &sjt_call36);
    sjt_parent214 = &sjt_call36;
    sjt_functionParam524 = &sjv_oldrect;
    sjf_rect_isequal(sjt_parent214, sjt_functionParam524, &sjt_capture133);
    result40 = !sjt_capture133;
    if (result40) {
        sjs_string* sjt_functionParam525 = 0;

        sjt_call37._refCount = 1;
        sjt_call37.count = 30;
        sjt_call37.data._refCount = 1;
        sjt_call37.data.datasize = 30;
        sjt_call37.data.data = (void*)sjg_string17;
        sjt_call37.data.isglobal = true;
        sjt_call37.data.count = 30;
        sjf_array_char(&sjt_call37.data);
        sjt_call37._isnullterminated = false;
        sjf_string(&sjt_call37);
        sjt_functionParam525 = &sjt_call37;
        sjf_halt(sjt_functionParam525);
    }

    sjt_parent219 = &sjv_glviewports;
    sjt_parent220 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent220, &sjt_capture134);
    sjt_functionParam526 = sjt_capture134 - 1;
    sjf_list_rect_removeat(sjt_parent219, sjt_functionParam526);
    sjt_parent221 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent221, &sjt_capture135);
    if (sjt_capture135 > 0) {
        int32_t sjt_capture136;
        int32_t sjt_functionParam527;
        sjs_list_rect* sjt_parent222 = 0;
        sjs_list_rect* sjt_parent223 = 0;

        sjt_parent222 = &sjv_glviewports;
        sjt_parent223 = &sjv_glviewports;
        sjf_list_rect_getcount(sjt_parent223, &sjt_capture136);
        sjt_functionParam527 = sjt_capture136 - 1;
        sjf_list_rect_getat(sjt_parent222, sjt_functionParam527, &sjv_newrect);
    } else {
        sjv_newrect._refCount = 1;
        sjv_newrect.x = 0;
        sjv_newrect.y = 0;
        sjv_newrect.w = 0;
        sjv_newrect.h = 0;
        sjf_rect(&sjv_newrect);
    }

    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjt_call36._refCount == 1) { sjf_rect_destroy(&sjt_call36); }
;
    if (sjt_call37._refCount == 1) { sjf_string_destroy(&sjt_call37); }
;
    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
;
    if (sjv_oldrect._refCount == 1) { sjf_rect_destroy(&sjv_oldrect); }
;
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect* sjt_functionParam518 = 0;
    sjs_list_rect* sjt_parent209 = 0;
    sjs_rect sjv_newrect = { -1 };

    sjv_newrect._refCount = 1;
    sjv_newrect.x = rect->x;
    sjv_newrect.y = scenerect->h - (rect->y + rect->h);
    sjv_newrect.w = rect->w;
    sjv_newrect.h = rect->h;
    sjf_rect(&sjv_newrect);
    sjt_parent209 = &sjv_glviewports;
    sjt_functionParam518 = &sjv_newrect;
    sjf_list_rect_add(sjt_parent209, sjt_functionParam518);
    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
;
}

void sjf_glrotated(float r, float x, float y, float z) {
    glRotated(r, x, y, z);
}

void sjf_glvertex3f(float x, float y, float z) {
    glVertex3f(x, y, z);
}

void sjf_halt(sjs_string* reason) {
    sjs_string* sjt_parent218 = 0;

    sjt_parent218 = reason;
    sjf_string_nullterminate(sjt_parent218);
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
                delete_cb weakptrcb9 = { &kh_value(p, k), weakptr_clear };
if (kh_value(p, k) != 0) { weakptr_cb_remove(kh_value(p, k), weakptrcb9); }
;
                #endif
            }
        }
        kh_destroy(fontkey_weak_font_hash_type, _this->_hash);
    }
}

void sjf_hash_fontkey_weak_font_heap(sjs_hash_fontkey_weak_font* _this) {
    _this->_hash = kh_init(fontkey_weak_font_hash_type);
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
                delete_cb weakptrcb8 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb8); }
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
                delete_cb weakptrcb7 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb7); }
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
    if (a < b) {
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
    int32_t sjt_functionParam483;
    sjs_array_heap_iface_animation* sjt_parent188 = 0;

    sjt_parent188 = &_parent->array;
    sjt_functionParam483 = index;
    sjf_array_heap_iface_animation_getat_heap(sjt_parent188, sjt_functionParam483, _return);
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
    sjs_array_rect sjt_call35 = { -1 };
    int32_t sjt_functionParam516;
    sjs_rect* sjt_functionParam517 = 0;
    sjs_array_rect* sjt_parent208 = 0;

    if ((&_parent->array)->count >= (&_parent->array)->datasize) {
        int32_t sjt_functionParam513;
        int32_t sjt_functionParam514;
        int32_t sjt_functionParam515;
        sjs_array_rect* sjt_parent207 = 0;

        sjt_parent207 = &_parent->array;
        sjt_functionParam514 = 10;
        sjt_functionParam515 = (&_parent->array)->datasize * 2;
        sjf_i32_max(sjt_functionParam514, sjt_functionParam515, &sjt_functionParam513);
        sjf_array_rect_grow(sjt_parent207, sjt_functionParam513, &sjt_call35);
        if (_parent->array._refCount == 1) { sjf_array_rect_destroy(&_parent->array); }
;
        _parent->array._refCount = 1;
        sjf_array_rect_copy(&_parent->array, (&sjt_call35));
    }

    sjt_parent208 = &_parent->array;
    sjt_functionParam516 = (&_parent->array)->count;
    sjt_functionParam517 = item;
    sjf_array_rect_initat(sjt_parent208, sjt_functionParam516, sjt_functionParam517);

    if (sjt_call35._refCount == 1) { sjf_array_rect_destroy(&sjt_call35); }
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
    int32_t sjt_functionParam522;
    sjs_array_rect* sjt_parent215 = 0;

    sjt_parent215 = &_parent->array;
    sjt_functionParam522 = index;
    sjf_array_rect_getat(sjt_parent215, sjt_functionParam522, _return);
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

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
    _this->minlevel = _from->minlevel;
}

void sjf_log_destroy(sjs_log* _this) {
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_mainloop(void) {
    bool result39;
    sjs_string sjt_call28 = { -1 };
    sjs_string sjt_call29 = { -1 };
    sjs_string sjt_call30 = { -1 };
    bool sjt_capture131;
    int32_t sjt_functionParam486;
    sjs_size* sjt_functionParam512 = 0;
    sjs_rect* sjt_functionParam521 = 0;
    sjs_scene2d* sjt_interfaceParam3 = 0;
    sjs_animator* sjt_parent192 = 0;
    sjs_windowrenderer* sjt_parent204 = 0;
    sjs_scene2d* sjt_parent206 = 0;
    sjs_scene2d* sjt_parent210 = 0;
    sjs_rect* sjt_parent211 = 0;
    sji_element sjt_parent213 = { 0 };
    sjs_scene2d* sjt_parent224 = 0;
    sjs_windowrenderer* sjt_parent225 = 0;
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
    sjt_parent192 = &sjv_animator;
    sjt_functionParam486 = sjv_ticks;
    sjf_animator_nextframe(sjt_parent192, sjt_functionParam486);
    if (sjv_mainloop_showfps) {
        sjv_mainloop_frames = sjv_mainloop_frames + 1;
        if ((sjv_mainloop_lasttick + 1000) < sjv_ticks) {
            int32_t sjt_cast17;
            int32_t sjt_cast18;
            sjs_string* sjt_functionParam490 = 0;
            sjs_string* sjt_functionParam500 = 0;
            float sjt_functionParam501;
            sjs_string* sjt_parent203 = 0;
            float sjv_fps;

            sjt_cast17 = sjv_mainloop_frames;
            sjt_cast18 = sjv_ticks - sjv_mainloop_lasttick;
            sjv_fps = ((float)sjt_cast17 * 1000.0f) / (float)sjt_cast18;
            sjt_call29._refCount = 1;
            sjt_call29.count = 5;
            sjt_call29.data._refCount = 1;
            sjt_call29.data.datasize = 5;
            sjt_call29.data.data = (void*)sjg_string16;
            sjt_call29.data.isglobal = true;
            sjt_call29.data.count = 5;
            sjf_array_char(&sjt_call29.data);
            sjt_call29._isnullterminated = false;
            sjf_string(&sjt_call29);
            sjt_parent203 = &sjt_call29;
            sjt_functionParam501 = sjv_fps;
            sjf_f32_asstring(sjt_functionParam501, &sjt_call30);
            sjt_functionParam500 = &sjt_call30;
            sjf_string_add(sjt_parent203, sjt_functionParam500, &sjt_call28);
            sjt_functionParam490 = &sjt_call28;
            sjf_debug_writeline(sjt_functionParam490);
            sjv_mainloop_lasttick = sjv_ticks;
            sjv_mainloop_frames = 0;
        }
    }

    sjt_parent204 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_getsize(sjt_parent204, &sjv_size);
    sjt_parent206 = &sjv_rootscene;
    sjt_functionParam512 = &sjv_size;
    sjf_scene2d_setsize(sjt_parent206, sjt_functionParam512);
    sjt_parent210 = &sjv_rootscene;
    sjf_scene2d_start(sjt_parent210);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjv_rect.w = (&sjv_size)->w;
    sjv_rect.h = (&sjv_size)->h;
    sjf_rect(&sjv_rect);
    sjt_parent211 = &sjv_looplastrect;
    sjt_functionParam521 = &sjv_rect;
    sjf_rect_isequal(sjt_parent211, sjt_functionParam521, &sjt_capture131);
    result39 = !sjt_capture131;
    if (result39) {
        sjs_rect* sjt_interfaceParam2 = 0;
        sji_element sjt_parent212 = { 0 };

        sjt_parent212 = sjv_root;
        sjt_interfaceParam2 = &sjv_rect;
        sjt_parent212._vtbl->setrect(sjt_parent212._parent, sjt_interfaceParam2);
    }

    sjt_parent213 = sjv_root;
    sjt_interfaceParam3 = &sjv_rootscene;
    sjt_parent213._vtbl->render(sjt_parent213._parent, sjt_interfaceParam3);
    sjt_parent224 = &sjv_rootscene;
    sjf_scene2d_end(sjt_parent224);
    sjt_parent225 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_present(sjt_parent225);
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
            int32_t ifValue1;
            int32_option sjt_getValue1;

            sjt_getValue1 = sjv_mouse_eventtype;
            ifValue1 = sjt_getValue1.value;
            if ((sjv_mouse_captureelement._parent != 0)) {
                sji_element ifValue2 = { 0 };
                sjs_mouseevent sjt_call38 = { -1 };
                sjs_mouseevent* sjt_interfaceParam4 = 0;
                sji_element sjt_parent226 = { 0 };

                ifValue2 = sjv_mouse_captureelement;
                if (ifValue2._parent != 0) {
                    ifValue2._parent->_refCount++;
                }

                sjt_parent226 = ifValue2;
                sjt_call38._refCount = 1;
                sjt_call38.eventtype = ifValue1;
                sjt_call38.point._refCount = 1;
                sjt_call38.point.x = sjv_mouse_x;
                sjt_call38.point.y = sjv_mouse_y;
                sjf_point(&sjt_call38.point);
                sjt_call38.iscaptured = true;
                sjt_call38.isleftdown = sjv_mouse_isleftdown;
                sjf_mouseevent(&sjt_call38);
                sjt_interfaceParam4 = &sjt_call38;
                sjt_parent226._vtbl->firemouseevent(sjt_parent226._parent, sjt_interfaceParam4, &sjv_shouldcontinue);

                if (ifValue2._parent != 0) {
                    ifValue2._parent->_refCount--;
                    if (ifValue2._parent->_refCount <= 0) {
                        ifValue2._vtbl->destroy(ifValue2._parent);
                        free(ifValue2._parent);
                    }
                }
                if (sjt_call38._refCount == 1) { sjf_mouseevent_destroy(&sjt_call38); }
;
            } else {
                sjs_mouseevent sjt_call39 = { -1 };
                sjs_mouseevent* sjt_interfaceParam5 = 0;
                sji_element sjt_parent227 = { 0 };

                sjt_parent227 = sjv_root;
                sjt_call39._refCount = 1;
                sjt_call39.eventtype = ifValue1;
                sjt_call39.point._refCount = 1;
                sjt_call39.point.x = sjv_mouse_x;
                sjt_call39.point.y = sjv_mouse_y;
                sjf_point(&sjt_call39.point);
                sjt_call39.iscaptured = false;
                sjt_call39.isleftdown = sjv_mouse_isleftdown;
                sjf_mouseevent(&sjt_call39);
                sjt_interfaceParam5 = &sjt_call39;
                sjt_parent227._vtbl->firemouseevent(sjt_parent227._parent, sjt_interfaceParam5, &sjv_shouldcontinue);

                if (sjt_call39._refCount == 1) { sjf_mouseevent_destroy(&sjt_call39); }
;
            }
        }

    }
    sjv_mainloop_shouldcontinue = sjv_shouldappcontinue;

    if (sjt_call28._refCount == 1) { sjf_string_destroy(&sjt_call28); }
;
    if (sjt_call29._refCount == 1) { sjf_string_destroy(&sjt_call29); }
;
    if (sjt_call30._refCount == 1) { sjf_string_destroy(&sjt_call30); }
;
    if (sjv_rect._refCount == 1) { sjf_rect_destroy(&sjv_rect); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
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
    float result35;

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
    result35 = -2.0f;
    _return->m22 = result35 / (zfar - znear);
    _return->m23 = 0.0f;
    _return->m30 = 0.0f - ((right + left) / (right - left));
    _return->m31 = 0.0f - ((top + bottom) / (top - bottom));
    _return->m32 = 0.0f - ((zfar + znear) / (zfar - znear));
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return) {
    float result36;

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
    result36 = -2.0f;
    (*_return)->m22 = result36 / (zfar - znear);
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
    sjs_rect* sjt_functionParam528 = 0;
    sjs_rect* sjt_functionParam529 = 0;

    sjt_functionParam528 = &_parent->windowrect;
    sjt_functionParam529 = &_parent->windowrect;
    sjf_glpopviewport(sjt_functionParam528, sjt_functionParam529);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result34;
    sjs_mat4 sjt_call31 = { -1 };
    sjs_mat4 sjt_call32 = { -1 };
    sjs_mat4 sjt_call33 = { -1 };
    bool sjt_capture130;
    sjs_size* sjt_functionParam502 = 0;
    sjs_size* sjt_parent205 = 0;

    sjt_parent205 = &_parent->_size;
    sjt_functionParam502 = size;
    sjf_size_isequal(sjt_parent205, sjt_functionParam502, &sjt_capture130);
    result34 = !sjt_capture130;
    if (result34) {
        float result37;
        float result38;
        int32_t sjt_cast19;
        int32_t sjt_cast20;
        float sjt_functionParam503;
        float sjt_functionParam504;
        float sjt_functionParam505;
        float sjt_functionParam506;
        float sjt_functionParam507;
        float sjt_functionParam508;
        float sjt_functionParam509;
        float sjt_functionParam510;
        float sjt_functionParam511;

        if (_parent->_size._refCount == 1) { sjf_size_destroy(&_parent->_size); }
;
        _parent->_size._refCount = 1;
        sjf_size_copy(&_parent->_size, size);
        sjt_functionParam503 = 0.0f;
        sjt_cast19 = (&_parent->_size)->w;
        sjt_functionParam504 = (float)sjt_cast19;
        sjt_cast20 = 0 - (&_parent->_size)->h;
        sjt_functionParam505 = (float)sjt_cast20;
        sjt_functionParam506 = 0.0f;
        result37 = -1.0f;
        sjt_functionParam507 = result37;
        sjt_functionParam508 = 1.0f;
        sjf_mat4_orthographic(sjt_functionParam503, sjt_functionParam504, sjt_functionParam505, sjt_functionParam506, sjt_functionParam507, sjt_functionParam508, &sjt_call31);
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
        _parent->projection._refCount = 1;
        sjf_mat4_copy(&_parent->projection, (&sjt_call31));
        sjt_functionParam509 = 1.0f;
        result38 = -1.0f;
        sjt_functionParam510 = result38;
        sjt_functionParam511 = 1.0f;
        sjf_mat4_scale(sjt_functionParam509, sjt_functionParam510, sjt_functionParam511, &sjt_call32);
        if (_parent->model._refCount == 1) { sjf_mat4_destroy(&_parent->model); }
;
        _parent->model._refCount = 1;
        sjf_mat4_copy(&_parent->model, (&sjt_call32));
        sjf_mat4_identity(&sjt_call33);
        if (_parent->view._refCount == 1) { sjf_mat4_destroy(&_parent->view); }
;
        _parent->view._refCount = 1;
        sjf_mat4_copy(&_parent->view, (&sjt_call33));
    }

    if (sjt_call31._refCount == 1) { sjf_mat4_destroy(&sjt_call31); }
;
    if (sjt_call32._refCount == 1) { sjf_mat4_destroy(&sjt_call32); }
;
    if (sjt_call33._refCount == 1) { sjf_mat4_destroy(&sjt_call33); }
;
}

void sjf_scene2d_start(sjs_scene2d* _parent) {
    sjs_rect sjt_call34 = { -1 };
    sjs_rect* sjt_functionParam519 = 0;
    sjs_rect* sjt_functionParam520 = 0;

    sjt_call34._refCount = 1;
    sjt_call34.x = 0;
    sjt_call34.y = 0;
    sjt_call34.w = (&_parent->_size)->w;
    sjt_call34.h = (&_parent->_size)->h;
    sjf_rect(&sjt_call34);
    if (_parent->windowrect._refCount == 1) { sjf_rect_destroy(&_parent->windowrect); }
;
    _parent->windowrect._refCount = 1;
    sjf_rect_copy(&_parent->windowrect, (&sjt_call34));
    sjt_functionParam519 = &_parent->windowrect;
    sjt_functionParam520 = &_parent->windowrect;
    sjf_glpushviewport(sjt_functionParam519, sjt_functionParam520);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_DEPTH_TEST );

    if (sjt_call34._refCount == 1) { sjf_rect_destroy(&sjt_call34); }
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

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
        _return->count = _parent->count;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&_parent->data));
        _return->_isnullterminated = false;
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_forEnd22;
        int32_t sjt_forStart22;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam491;
            sjs_array_char* sjt_parent196 = 0;

            sjt_parent196 = &_parent->data;
            sjt_functionParam491 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent196, sjt_functionParam491, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, (&_parent->data));
        }

        sjv_newcount = _parent->count;
        sjt_forStart22 = 0;
        sjt_forEnd22 = item->count;
        i = sjt_forStart22;
        while (i < sjt_forEnd22) {
            int32_t sjt_functionParam492;
            char sjt_functionParam493;
            int32_t sjt_functionParam495;
            sjs_array_char* sjt_parent197 = 0;
            sjs_string* sjt_parent199 = 0;

            sjt_parent197 = &sjv_newdata;
            sjt_functionParam492 = sjv_newcount;
            sjt_parent199 = item;
            sjt_functionParam495 = i;
            sjf_string_getat(sjt_parent199, sjt_functionParam495, &sjt_functionParam493);
            sjf_array_char_initat(sjt_parent197, sjt_functionParam492, sjt_functionParam493);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        _return->_refCount = 1;
        _return->count = sjv_newcount;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&sjv_newdata));
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
        sjf_array_char_copy(&(*_return)->data, (&_parent->data));
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_forEnd23;
        int32_t sjt_forStart23;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam496;
            sjs_array_char* sjt_parent200 = 0;

            sjt_parent200 = &_parent->data;
            sjt_functionParam496 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent200, sjt_functionParam496, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, (&_parent->data));
        }

        sjv_newcount = _parent->count;
        sjt_forStart23 = 0;
        sjt_forEnd23 = item->count;
        i = sjt_forStart23;
        while (i < sjt_forEnd23) {
            int32_t sjt_functionParam497;
            char sjt_functionParam498;
            int32_t sjt_functionParam499;
            sjs_array_char* sjt_parent201 = 0;
            sjs_string* sjt_parent202 = 0;

            sjt_parent201 = &sjv_newdata;
            sjt_functionParam497 = sjv_newcount;
            sjt_parent202 = item;
            sjt_functionParam499 = i;
            sjf_string_getat(sjt_parent202, sjt_functionParam499, &sjt_functionParam498);
            sjf_array_char_initat(sjt_parent201, sjt_functionParam497, sjt_functionParam498);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, (&sjv_newdata));
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
    int32_t sjt_functionParam494;
    sjs_array_char* sjt_parent198 = 0;

    sjt_parent198 = &_parent->data;
    sjt_functionParam494 = index;
    sjf_array_char_getat(sjt_parent198, sjt_functionParam494, _return);
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
    bool result32;
    bool result33;
    sjs_array_char sjt_call27 = { -1 };

    result32 = !(&_parent->data)->isglobal;
    result33 = !_parent->_isnullterminated;
    if (result32 || result33) {
        int32_t sjt_functionParam488;
        char sjt_functionParam489;
        sjs_array_char* sjt_parent194 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam487;
            sjs_array_char* sjt_parent193 = 0;

            sjt_parent193 = &_parent->data;
            sjt_functionParam487 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent193, sjt_functionParam487, &sjt_call27);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            _parent->data._refCount = 1;
            sjf_array_char_copy(&_parent->data, (&sjt_call27));
        }

        sjt_parent194 = &_parent->data;
        sjt_functionParam488 = _parent->count;
        sjt_functionParam489 = '\0';
        sjf_array_char_initat(sjt_parent194, sjt_functionParam488, sjt_functionParam489);
        _parent->_isnullterminated = true;
    }

    if (sjt_call27._refCount == 1) { sjf_array_char_destroy(&sjt_call27); }
;
}

void sjf_style(sjs_style* _this) {
}

void sjf_style_copy(sjs_style* _this, sjs_style* _from) {
}

void sjf_style_destroy(sjs_style* _this) {
}

void sjf_style_heap(sjs_style* _this) {
}

void sjf_test(sjs_test* _this) {
}

void sjf_test_as_sji_element(sjs_test* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_test_element_vtbl;
}

void sjf_test_asinterface(sjs_test* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_test_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_test_calculate(sjs_test* _parent) {
    int32_t underscore1;

    underscore1 = _parent->funcid;
    if (underscore1 == 0) {
        int32_t n;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;

        sjt_forStart1 = 0;
        sjt_forEnd1 = sjv_dots;
        n = sjt_forStart1;
        while (n < sjt_forEnd1) {
            int32_t sjt_functionParam29;
            int32_t sjt_functionParam30;
            int32_t sjt_functionParam31;
            float sjt_functionParam32;
            int32_t sjt_functionParam33;
            float sjt_functionParam34;
            float sjt_functionParam35;
            sjs_array_f32* sjt_parent13 = 0;
            sjs_array_f32* sjt_parent14 = 0;
            float sjv_t;

            sjt_functionParam29 = 1;
            sjt_functionParam30 = n;
            sjf_test_gettm(_parent, sjt_functionParam29, sjt_functionParam30, &sjv_t);
            sjt_parent13 = &_parent->datax;
            sjt_functionParam31 = n;
            sjt_functionParam32 = sjv_t;
            sjf_array_f32_setat(sjt_parent13, sjt_functionParam31, sjt_functionParam32);
            sjt_parent14 = &_parent->datay;
            sjt_functionParam33 = n;
            sjt_functionParam35 = sjv_t;
            sjf_f32_tan(sjt_functionParam35, &sjt_functionParam34);
            sjf_array_f32_setat(sjt_parent14, sjt_functionParam33, sjt_functionParam34);
            n++;
        }
    } else {
        if (underscore1 == 1) {
            int32_t n;
            int32_t sjt_forEnd2;
            int32_t sjt_forStart2;

            sjt_forStart2 = 0;
            sjt_forEnd2 = sjv_dots;
            n = sjt_forStart2;
            while (n < sjt_forEnd2) {
                int32_t sjt_functionParam36;
                int32_t sjt_functionParam37;
                int32_t sjt_functionParam38;
                float sjt_functionParam39;
                int32_t sjt_functionParam40;
                float sjt_functionParam41;
                sjs_array_f32* sjt_parent15 = 0;
                sjs_array_f32* sjt_parent16 = 0;
                float sjv_t;

                sjt_functionParam36 = 1;
                sjt_functionParam37 = n;
                sjf_test_gettm(_parent, sjt_functionParam36, sjt_functionParam37, &sjv_t);
                sjt_parent15 = &_parent->datax;
                sjt_functionParam38 = n;
                sjt_functionParam39 = sjv_t;
                sjf_array_f32_setat(sjt_parent15, sjt_functionParam38, sjt_functionParam39);
                sjt_parent16 = &_parent->datay;
                sjt_functionParam40 = n;
                sjt_functionParam41 = (sjv_t * sjv_t) * sjv_t;
                sjf_array_f32_setat(sjt_parent16, sjt_functionParam40, sjt_functionParam41);
                n++;
            }
        } else {
            if (underscore1 == 2) {
                int32_t n;
                int32_t sjt_forEnd3;
                int32_t sjt_forStart3;

                sjt_forStart3 = 0;
                sjt_forEnd3 = sjv_dots;
                n = sjt_forStart3;
                while (n < sjt_forEnd3) {
                    float sjt_capture5;
                    int32_t sjt_functionParam42;
                    int32_t sjt_functionParam43;
                    int32_t sjt_functionParam44;
                    float sjt_functionParam45;
                    int32_t sjt_functionParam46;
                    float sjt_functionParam47;
                    float sjt_functionParam48;
                    sjs_array_f32* sjt_parent17 = 0;
                    sjs_array_f32* sjt_parent18 = 0;
                    float sjv_t;

                    sjt_functionParam42 = 2;
                    sjt_functionParam43 = n;
                    sjf_test_gettm(_parent, sjt_functionParam42, sjt_functionParam43, &sjv_t);
                    sjt_parent17 = &_parent->datax;
                    sjt_functionParam44 = n;
                    sjt_functionParam45 = sjv_t;
                    sjf_array_f32_setat(sjt_parent17, sjt_functionParam44, sjt_functionParam45);
                    sjt_parent18 = &_parent->datay;
                    sjt_functionParam46 = n;
                    sjt_functionParam48 = sjv_t;
                    sjf_f32_sin(sjt_functionParam48, &sjt_capture5);
                    sjt_functionParam47 = (6.0f * sjt_capture5) / 2.0f;
                    sjf_array_f32_setat(sjt_parent18, sjt_functionParam46, sjt_functionParam47);
                    n++;
                }
            } else {
                if (underscore1 == 3) {
                    int32_t n;
                    int32_t sjt_forEnd4;
                    int32_t sjt_forStart4;

                    sjt_forStart4 = 0;
                    sjt_forEnd4 = sjv_dots;
                    n = sjt_forStart4;
                    while (n < sjt_forEnd4) {
                        float sjt_capture6;
                        int32_t sjt_functionParam49;
                        int32_t sjt_functionParam50;
                        int32_t sjt_functionParam51;
                        float sjt_functionParam52;
                        int32_t sjt_functionParam53;
                        float sjt_functionParam54;
                        float sjt_functionParam55;
                        sjs_array_f32* sjt_parent19 = 0;
                        sjs_array_f32* sjt_parent20 = 0;
                        float sjv_t;

                        sjt_functionParam49 = 1;
                        sjt_functionParam50 = n;
                        sjf_test_gettm(_parent, sjt_functionParam49, sjt_functionParam50, &sjv_t);
                        sjt_parent19 = &_parent->datax;
                        sjt_functionParam51 = n;
                        sjt_functionParam52 = sjv_t;
                        sjf_array_f32_setat(sjt_parent19, sjt_functionParam51, sjt_functionParam52);
                        sjt_parent20 = &_parent->datay;
                        sjt_functionParam53 = n;
                        sjt_functionParam55 = sjv_t;
                        sjf_f32_tan(sjt_functionParam55, &sjt_capture6);
                        sjt_functionParam54 = 1.0f / sjt_capture6;
                        sjf_array_f32_setat(sjt_parent20, sjt_functionParam53, sjt_functionParam54);
                        n++;
                    }
                } else {
                    if (underscore1 == 4) {
                        int32_t n;
                        int32_t sjt_forEnd5;
                        int32_t sjt_forStart5;

                        sjt_forStart5 = 0;
                        sjt_forEnd5 = sjv_dots;
                        n = sjt_forStart5;
                        while (n < sjt_forEnd5) {
                            float sjt_capture7;
                            float sjt_capture8;
                            int32_t sjt_functionParam56;
                            int32_t sjt_functionParam57;
                            int32_t sjt_functionParam58;
                            float sjt_functionParam59;
                            int32_t sjt_functionParam60;
                            float sjt_functionParam61;
                            float sjt_functionParam62;
                            float sjt_functionParam63;
                            sjs_array_f32* sjt_parent21 = 0;
                            sjs_array_f32* sjt_parent22 = 0;
                            float sjv_t;

                            sjt_functionParam56 = 2;
                            sjt_functionParam57 = n;
                            sjf_test_gettm(_parent, sjt_functionParam56, sjt_functionParam57, &sjv_t);
                            sjt_parent21 = &_parent->datax;
                            sjt_functionParam58 = n;
                            sjt_functionParam59 = sjv_t;
                            sjf_array_f32_setat(sjt_parent21, sjt_functionParam58, sjt_functionParam59);
                            sjt_parent22 = &_parent->datay;
                            sjt_functionParam60 = n;
                            sjt_functionParam62 = sjv_t;
                            sjf_f32_abs(sjt_functionParam62, &sjt_capture7);
                            sjt_functionParam63 = sjv_t;
                            sjf_f32_sin(sjt_functionParam63, &sjt_capture8);
                            sjt_functionParam61 = sjt_capture7 * sjt_capture8;
                            sjf_array_f32_setat(sjt_parent22, sjt_functionParam60, sjt_functionParam61);
                            n++;
                        }
                    } else {
                        if (underscore1 == 5) {
                            int32_t n;
                            int32_t sjt_forEnd6;
                            int32_t sjt_forStart6;

                            sjt_forStart6 = 0;
                            sjt_forEnd6 = sjv_dots;
                            n = sjt_forStart6;
                            while (n < sjt_forEnd6) {
                                int32_t sjt_functionParam64;
                                int32_t sjt_functionParam65;
                                int32_t sjt_functionParam66;
                                float sjt_functionParam67;
                                int32_t sjt_functionParam68;
                                float sjt_functionParam69;
                                sjs_array_f32* sjt_parent23 = 0;
                                sjs_array_f32* sjt_parent24 = 0;
                                float sjv_t;

                                sjt_functionParam64 = 2;
                                sjt_functionParam65 = n;
                                sjf_test_gettm(_parent, sjt_functionParam64, sjt_functionParam65, &sjv_t);
                                sjt_parent23 = &_parent->datax;
                                sjt_functionParam66 = n;
                                sjt_functionParam67 = sjv_t;
                                sjf_array_f32_setat(sjt_parent23, sjt_functionParam66, sjt_functionParam67);
                                sjt_parent24 = &_parent->datay;
                                sjt_functionParam68 = n;
                                sjt_functionParam69 = sjv_t / (sjv_t * sjv_t);
                                sjf_array_f32_setat(sjt_parent24, sjt_functionParam68, sjt_functionParam69);
                                n++;
                            }
                        } else {
                            if (underscore1 == 6) {
                                int32_t n;
                                int32_t sjt_forEnd7;
                                int32_t sjt_forStart7;

                                sjt_forStart7 = 0;
                                sjt_forEnd7 = sjv_dots;
                                n = sjt_forStart7;
                                while (n < sjt_forEnd7) {
                                    float sjt_capture9;
                                    int32_t sjt_functionParam70;
                                    int32_t sjt_functionParam71;
                                    int32_t sjt_functionParam72;
                                    float sjt_functionParam73;
                                    int32_t sjt_functionParam74;
                                    float sjt_functionParam75;
                                    float sjt_functionParam76;
                                    sjs_array_f32* sjt_parent25 = 0;
                                    sjs_array_f32* sjt_parent26 = 0;
                                    float sjv_t;

                                    sjt_functionParam70 = 2;
                                    sjt_functionParam71 = n;
                                    sjf_test_gettm(_parent, sjt_functionParam70, sjt_functionParam71, &sjv_t);
                                    sjt_parent25 = &_parent->datax;
                                    sjt_functionParam72 = n;
                                    sjt_functionParam73 = sjv_t;
                                    sjf_array_f32_setat(sjt_parent25, sjt_functionParam72, sjt_functionParam73);
                                    sjt_parent26 = &_parent->datay;
                                    sjt_functionParam74 = n;
                                    sjt_functionParam76 = sjv_t;
                                    sjf_f32_sin(sjt_functionParam76, &sjt_capture9);
                                    sjt_functionParam75 = sjv_t * sjt_capture9;
                                    sjf_array_f32_setat(sjt_parent26, sjt_functionParam74, sjt_functionParam75);
                                    n++;
                                }
                            } else {
                                if (underscore1 == 7) {
                                    int32_t n;
                                    int32_t sjt_forEnd8;
                                    int32_t sjt_forStart8;

                                    sjt_forStart8 = 0;
                                    sjt_forEnd8 = sjv_dots;
                                    n = sjt_forStart8;
                                    while (n < sjt_forEnd8) {
                                        float sjt_capture10;
                                        float sjt_capture11;
                                        float sjt_capture12;
                                        float sjt_capture13;
                                        int32_t sjt_functionParam77;
                                        int32_t sjt_functionParam78;
                                        int32_t sjt_functionParam79;
                                        float sjt_functionParam80;
                                        float sjt_functionParam81;
                                        float sjt_functionParam82;
                                        int32_t sjt_functionParam83;
                                        float sjt_functionParam84;
                                        float sjt_functionParam85;
                                        float sjt_functionParam86;
                                        sjs_array_f32* sjt_parent27 = 0;
                                        sjs_array_f32* sjt_parent28 = 0;
                                        float sjv_t;

                                        sjt_functionParam77 = 2;
                                        sjt_functionParam78 = n;
                                        sjf_test_gett(_parent, sjt_functionParam77, sjt_functionParam78, &sjv_t);
                                        sjt_parent27 = &_parent->datax;
                                        sjt_functionParam79 = n;
                                        sjt_functionParam81 = sjv_t;
                                        sjf_f32_cos(sjt_functionParam81, &sjt_capture10);
                                        sjt_functionParam82 = 2.0f * sjv_t;
                                        sjf_f32_cos(sjt_functionParam82, &sjt_capture11);
                                        sjt_functionParam80 = (2.0f * sjt_capture10) + sjt_capture11;
                                        sjf_array_f32_setat(sjt_parent27, sjt_functionParam79, sjt_functionParam80);
                                        sjt_parent28 = &_parent->datay;
                                        sjt_functionParam83 = n;
                                        sjt_functionParam85 = sjv_t;
                                        sjf_f32_sin(sjt_functionParam85, &sjt_capture12);
                                        sjt_functionParam86 = 2.0f * sjv_t;
                                        sjf_f32_sin(sjt_functionParam86, &sjt_capture13);
                                        sjt_functionParam84 = (2.0f * sjt_capture12) - sjt_capture13;
                                        sjf_array_f32_setat(sjt_parent28, sjt_functionParam83, sjt_functionParam84);
                                        n++;
                                    }
                                } else {
                                    if (underscore1 == 8) {
                                        int32_t n;
                                        int32_t sjt_forEnd9;
                                        int32_t sjt_forStart9;

                                        sjt_forStart9 = 0;
                                        sjt_forEnd9 = sjv_dots;
                                        n = sjt_forStart9;
                                        while (n < sjt_forEnd9) {
                                            float sjt_capture14;
                                            float sjt_capture15;
                                            float sjt_capture16;
                                            float sjt_capture17;
                                            int32_t sjt_functionParam87;
                                            int32_t sjt_functionParam88;
                                            int32_t sjt_functionParam89;
                                            float sjt_functionParam90;
                                            float sjt_functionParam91;
                                            float sjt_functionParam92;
                                            int32_t sjt_functionParam93;
                                            float sjt_functionParam94;
                                            float sjt_functionParam95;
                                            float sjt_functionParam96;
                                            sjs_array_f32* sjt_parent29 = 0;
                                            sjs_array_f32* sjt_parent30 = 0;
                                            float sjv_t;

                                            sjt_functionParam87 = 2;
                                            sjt_functionParam88 = n;
                                            sjf_test_gett(_parent, sjt_functionParam87, sjt_functionParam88, &sjv_t);
                                            sjt_parent29 = &_parent->datax;
                                            sjt_functionParam89 = n;
                                            sjt_functionParam91 = sjv_t;
                                            sjf_f32_cos(sjt_functionParam91, &sjt_capture14);
                                            sjt_functionParam92 = 5.0f * sjv_t;
                                            sjf_f32_cos(sjt_functionParam92, &sjt_capture15);
                                            sjt_functionParam90 = 4.0f * (sjt_capture14 + (sjt_capture15 / 5.0f));
                                            sjf_array_f32_setat(sjt_parent29, sjt_functionParam89, sjt_functionParam90);
                                            sjt_parent30 = &_parent->datay;
                                            sjt_functionParam93 = n;
                                            sjt_functionParam95 = sjv_t;
                                            sjf_f32_sin(sjt_functionParam95, &sjt_capture16);
                                            sjt_functionParam96 = 5.0f * sjv_t;
                                            sjf_f32_sin(sjt_functionParam96, &sjt_capture17);
                                            sjt_functionParam94 = 4.0f * (sjt_capture16 - (sjt_capture17 / 5.0f));
                                            sjf_array_f32_setat(sjt_parent30, sjt_functionParam93, sjt_functionParam94);
                                            n++;
                                        }
                                    } else {
                                        if (underscore1 == 9) {
                                            int32_t n;
                                            int32_t sjt_forEnd10;
                                            int32_t sjt_forStart10;

                                            sjt_forStart10 = 0;
                                            sjt_forEnd10 = sjv_dots;
                                            n = sjt_forStart10;
                                            while (n < sjt_forEnd10) {
                                                float sjt_capture18;
                                                float sjt_capture19;
                                                float sjt_capture20;
                                                float sjt_capture21;
                                                float sjt_functionParam100;
                                                float sjt_functionParam101;
                                                float sjt_functionParam102;
                                                int32_t sjt_functionParam103;
                                                float sjt_functionParam104;
                                                float sjt_functionParam105;
                                                float sjt_functionParam106;
                                                int32_t sjt_functionParam97;
                                                int32_t sjt_functionParam98;
                                                int32_t sjt_functionParam99;
                                                sjs_array_f32* sjt_parent31 = 0;
                                                sjs_array_f32* sjt_parent32 = 0;
                                                float sjv_t;

                                                sjt_functionParam97 = 20;
                                                sjt_functionParam98 = n;
                                                sjf_test_gett(_parent, sjt_functionParam97, sjt_functionParam98, &sjv_t);
                                                sjt_parent31 = &_parent->datax;
                                                sjt_functionParam99 = n;
                                                sjt_functionParam101 = sjv_t;
                                                sjf_f32_cos(sjt_functionParam101, &sjt_capture18);
                                                sjt_functionParam102 = 1.1f * sjv_t;
                                                sjf_f32_cos(sjt_functionParam102, &sjt_capture19);
                                                sjt_functionParam100 = 2.8f * (sjt_capture18 + (sjt_capture19 / 1.1f));
                                                sjf_array_f32_setat(sjt_parent31, sjt_functionParam99, sjt_functionParam100);
                                                sjt_parent32 = &_parent->datay;
                                                sjt_functionParam103 = n;
                                                sjt_functionParam105 = sjv_t;
                                                sjf_f32_sin(sjt_functionParam105, &sjt_capture20);
                                                sjt_functionParam106 = 1.1f * sjv_t;
                                                sjf_f32_sin(sjt_functionParam106, &sjt_capture21);
                                                sjt_functionParam104 = 2.8f * (sjt_capture20 - (sjt_capture21 / 1.1f));
                                                sjf_array_f32_setat(sjt_parent32, sjt_functionParam103, sjt_functionParam104);
                                                n++;
                                            }
                                        } else {
                                            if (underscore1 == 10) {
                                                int32_t n;
                                                int32_t sjt_forEnd11;
                                                int32_t sjt_forStart11;

                                                sjt_forStart11 = 0;
                                                sjt_forEnd11 = sjv_dots;
                                                n = sjt_forStart11;
                                                while (n < sjt_forEnd11) {
                                                    float sjt_capture22;
                                                    float sjt_capture23;
                                                    float sjt_capture24;
                                                    float sjt_capture25;
                                                    int32_t sjt_functionParam107;
                                                    int32_t sjt_functionParam108;
                                                    int32_t sjt_functionParam109;
                                                    float sjt_functionParam110;
                                                    float sjt_functionParam111;
                                                    float sjt_functionParam112;
                                                    int32_t sjt_functionParam113;
                                                    float sjt_functionParam114;
                                                    float sjt_functionParam115;
                                                    float sjt_functionParam116;
                                                    sjs_array_f32* sjt_parent33 = 0;
                                                    sjs_array_f32* sjt_parent34 = 0;
                                                    float sjv_t;

                                                    sjt_functionParam107 = 2;
                                                    sjt_functionParam108 = n;
                                                    sjf_test_gett(_parent, sjt_functionParam107, sjt_functionParam108, &sjv_t);
                                                    sjt_parent33 = &_parent->datax;
                                                    sjt_functionParam109 = n;
                                                    sjt_functionParam111 = sjv_t;
                                                    sjf_f32_cos(sjt_functionParam111, &sjt_capture22);
                                                    sjt_functionParam112 = sjv_t;
                                                    sjf_f32_cos(sjt_functionParam112, &sjt_capture23);
                                                    sjt_functionParam110 = (3.0f * (1.0f + sjt_capture22)) * sjt_capture23;
                                                    sjf_array_f32_setat(sjt_parent33, sjt_functionParam109, sjt_functionParam110);
                                                    sjt_parent34 = &_parent->datay;
                                                    sjt_functionParam113 = n;
                                                    sjt_functionParam115 = sjv_t;
                                                    sjf_f32_cos(sjt_functionParam115, &sjt_capture24);
                                                    sjt_functionParam116 = sjv_t;
                                                    sjf_f32_sin(sjt_functionParam116, &sjt_capture25);
                                                    sjt_functionParam114 = (3.0f * (1.0f + sjt_capture24)) * sjt_capture25;
                                                    sjf_array_f32_setat(sjt_parent34, sjt_functionParam113, sjt_functionParam114);
                                                    n++;
                                                }
                                            } else {
                                                if (underscore1 == 11) {
                                                    int32_t n;
                                                    int32_t sjt_forEnd12;
                                                    int32_t sjt_forStart12;

                                                    sjt_forStart12 = 0;
                                                    sjt_forEnd12 = sjv_dots;
                                                    n = sjt_forStart12;
                                                    while (n < sjt_forEnd12) {
                                                        float sjt_capture26;
                                                        float sjt_capture27;
                                                        int32_t sjt_functionParam117;
                                                        int32_t sjt_functionParam118;
                                                        int32_t sjt_functionParam119;
                                                        float sjt_functionParam120;
                                                        float sjt_functionParam121;
                                                        int32_t sjt_functionParam122;
                                                        float sjt_functionParam123;
                                                        float sjt_functionParam124;
                                                        sjs_array_f32* sjt_parent35 = 0;
                                                        sjs_array_f32* sjt_parent36 = 0;
                                                        float sjv_t;

                                                        sjt_functionParam117 = 2;
                                                        sjt_functionParam118 = n;
                                                        sjf_test_gett(_parent, sjt_functionParam117, sjt_functionParam118, &sjv_t);
                                                        sjt_parent35 = &_parent->datax;
                                                        sjt_functionParam119 = n;
                                                        sjt_functionParam121 = sjv_t + (sjv_f32_pi / 2.0f);
                                                        sjf_f32_sin(sjt_functionParam121, &sjt_capture26);
                                                        sjt_functionParam120 = 3.0f * sjt_capture26;
                                                        sjf_array_f32_setat(sjt_parent35, sjt_functionParam119, sjt_functionParam120);
                                                        sjt_parent36 = &_parent->datay;
                                                        sjt_functionParam122 = n;
                                                        sjt_functionParam124 = 2.0f * sjv_t;
                                                        sjf_f32_sin(sjt_functionParam124, &sjt_capture27);
                                                        sjt_functionParam123 = 3.0f * sjt_capture27;
                                                        sjf_array_f32_setat(sjt_parent36, sjt_functionParam122, sjt_functionParam123);
                                                        n++;
                                                    }
                                                } else {
                                                    if (underscore1 == 12) {
                                                        int32_t n;
                                                        int32_t sjt_forEnd13;
                                                        int32_t sjt_forStart13;

                                                        sjt_forStart13 = 0;
                                                        sjt_forEnd13 = sjv_dots;
                                                        n = sjt_forStart13;
                                                        while (n < sjt_forEnd13) {
                                                            float sjt_capture28;
                                                            float sjt_capture29;
                                                            float sjt_capture30;
                                                            float sjt_capture31;
                                                            float sjt_capture32;
                                                            float sjt_capture33;
                                                            float sjt_capture34;
                                                            float sjt_capture35;
                                                            int32_t sjt_functionParam125;
                                                            int32_t sjt_functionParam126;
                                                            int32_t sjt_functionParam127;
                                                            float sjt_functionParam128;
                                                            float sjt_functionParam129;
                                                            float sjt_functionParam130;
                                                            float sjt_functionParam131;
                                                            float sjt_functionParam132;
                                                            float sjt_functionParam133;
                                                            float sjt_functionParam134;
                                                            float sjt_functionParam135;
                                                            int32_t sjt_functionParam136;
                                                            float sjt_functionParam137;
                                                            float sjt_functionParam138;
                                                            float sjt_functionParam139;
                                                            float sjt_functionParam140;
                                                            float sjt_functionParam141;
                                                            float sjt_functionParam142;
                                                            float sjt_functionParam143;
                                                            float sjt_functionParam144;
                                                            sjs_array_f32* sjt_parent37 = 0;
                                                            sjs_array_f32* sjt_parent38 = 0;
                                                            float sjv_t;

                                                            sjt_functionParam125 = 12;
                                                            sjt_functionParam126 = n;
                                                            sjf_test_gett(_parent, sjt_functionParam125, sjt_functionParam126, &sjv_t);
                                                            sjt_parent37 = &_parent->datax;
                                                            sjt_functionParam127 = n;
                                                            sjt_functionParam129 = sjv_t;
                                                            sjf_f32_sin(sjt_functionParam129, &sjt_capture28);
                                                            sjt_functionParam131 = sjv_t;
                                                            sjf_f32_cos(sjt_functionParam131, &sjt_functionParam130);
                                                            sjf_f32_exp(sjt_functionParam130, &sjt_capture29);
                                                            sjt_functionParam132 = 4.0f * sjv_t;
                                                            sjf_f32_cos(sjt_functionParam132, &sjt_capture30);
                                                            sjt_functionParam134 = sjv_t / 12.0f;
                                                            sjf_f32_sin(sjt_functionParam134, &sjt_functionParam133);
                                                            sjt_functionParam135 = 5.0f;
                                                            sjf_f32_pow(sjt_functionParam133, sjt_functionParam135, &sjt_capture31);
                                                            sjt_functionParam128 = sjt_capture28 * ((sjt_capture29 - (2.0f * sjt_capture30)) + sjt_capture31);
                                                            sjf_array_f32_setat(sjt_parent37, sjt_functionParam127, sjt_functionParam128);
                                                            sjt_parent38 = &_parent->datay;
                                                            sjt_functionParam136 = n;
                                                            sjt_functionParam138 = sjv_t;
                                                            sjf_f32_cos(sjt_functionParam138, &sjt_capture32);
                                                            sjt_functionParam140 = sjv_t;
                                                            sjf_f32_cos(sjt_functionParam140, &sjt_functionParam139);
                                                            sjf_f32_exp(sjt_functionParam139, &sjt_capture33);
                                                            sjt_functionParam141 = 4.0f * sjv_t;
                                                            sjf_f32_cos(sjt_functionParam141, &sjt_capture34);
                                                            sjt_functionParam143 = sjv_t / 12.0f;
                                                            sjf_f32_sin(sjt_functionParam143, &sjt_functionParam142);
                                                            sjt_functionParam144 = 5.0f;
                                                            sjf_f32_pow(sjt_functionParam142, sjt_functionParam144, &sjt_capture35);
                                                            sjt_functionParam137 = sjt_capture32 * ((sjt_capture33 - (2.0f * sjt_capture34)) + sjt_capture35);
                                                            sjf_array_f32_setat(sjt_parent38, sjt_functionParam136, sjt_functionParam137);
                                                            n++;
                                                        }
                                                    } else {
                                                        if (underscore1 == 13) {
                                                            int32_t n;
                                                            int32_t sjt_forEnd14;
                                                            int32_t sjt_forStart14;

                                                            sjt_forStart14 = 0;
                                                            sjt_forEnd14 = sjv_dots;
                                                            n = sjt_forStart14;
                                                            while (n < sjt_forEnd14) {
                                                                float sjt_capture36;
                                                                float sjt_capture37;
                                                                float sjt_capture38;
                                                                float sjt_capture39;
                                                                float sjt_capture40;
                                                                int32_t sjt_functionParam145;
                                                                int32_t sjt_functionParam146;
                                                                int32_t sjt_functionParam147;
                                                                float sjt_functionParam148;
                                                                float sjt_functionParam149;
                                                                float sjt_functionParam150;
                                                                float sjt_functionParam151;
                                                                int32_t sjt_functionParam152;
                                                                float sjt_functionParam153;
                                                                float sjt_functionParam154;
                                                                float sjt_functionParam155;
                                                                float sjt_functionParam156;
                                                                float sjt_functionParam157;
                                                                sjs_array_f32* sjt_parent39 = 0;
                                                                sjs_array_f32* sjt_parent40 = 0;
                                                                float sjv_t;

                                                                sjt_functionParam145 = 2;
                                                                sjt_functionParam146 = n;
                                                                sjf_test_gett(_parent, sjt_functionParam145, sjt_functionParam146, &sjv_t);
                                                                sjt_parent39 = &_parent->datax;
                                                                sjt_functionParam147 = n;
                                                                sjt_functionParam150 = sjv_t;
                                                                sjf_f32_sin(sjt_functionParam150, &sjt_functionParam149);
                                                                sjt_functionParam151 = 3.0f;
                                                                sjf_f32_pow(sjt_functionParam149, sjt_functionParam151, &sjt_capture36);
                                                                sjt_functionParam148 = (16.0f * sjt_capture36) / 4.0f;
                                                                sjf_array_f32_setat(sjt_parent39, sjt_functionParam147, sjt_functionParam148);
                                                                sjt_parent40 = &_parent->datay;
                                                                sjt_functionParam152 = n;
                                                                sjt_functionParam154 = sjv_t;
                                                                sjf_f32_cos(sjt_functionParam154, &sjt_capture37);
                                                                sjt_functionParam155 = 2.0f * sjv_t;
                                                                sjf_f32_cos(sjt_functionParam155, &sjt_capture38);
                                                                sjt_functionParam156 = 3.0f * sjv_t;
                                                                sjf_f32_cos(sjt_functionParam156, &sjt_capture39);
                                                                sjt_functionParam157 = 4.0f * sjv_t;
                                                                sjf_f32_cos(sjt_functionParam157, &sjt_capture40);
                                                                sjt_functionParam153 = ((((13.0f * sjt_capture37) - (5.0f * sjt_capture38)) - (2.0f * sjt_capture39)) - sjt_capture40) / 4.0f;
                                                                sjf_array_f32_setat(sjt_parent40, sjt_functionParam152, sjt_functionParam153);
                                                                n++;
                                                            }
                                                        } else {
                                                            if (underscore1 == 14) {
                                                                int32_t n;
                                                                int32_t sjt_forEnd15;
                                                                int32_t sjt_forStart15;

                                                                sjt_forStart15 = 0;
                                                                sjt_forEnd15 = sjv_dots;
                                                                n = sjt_forStart15;
                                                                while (n < sjt_forEnd15) {
                                                                    float sjt_capture41;
                                                                    float sjt_capture42;
                                                                    int32_t sjt_functionParam158;
                                                                    int32_t sjt_functionParam159;
                                                                    int32_t sjt_functionParam160;
                                                                    float sjt_functionParam161;
                                                                    float sjt_functionParam162;
                                                                    int32_t sjt_functionParam163;
                                                                    float sjt_functionParam164;
                                                                    float sjt_functionParam165;
                                                                    sjs_array_f32* sjt_parent41 = 0;
                                                                    sjs_array_f32* sjt_parent42 = 0;
                                                                    float sjv_t;

                                                                    sjt_functionParam158 = 1;
                                                                    sjt_functionParam159 = n;
                                                                    sjf_test_gettm(_parent, sjt_functionParam158, sjt_functionParam159, &sjv_t);
                                                                    sjt_parent41 = &_parent->datax;
                                                                    sjt_functionParam160 = n;
                                                                    sjt_functionParam162 = sjv_t;
                                                                    sjf_f32_sin(sjt_functionParam162, &sjt_capture41);
                                                                    sjt_functionParam161 = 5.0f * sjt_capture41;
                                                                    sjf_array_f32_setat(sjt_parent41, sjt_functionParam160, sjt_functionParam161);
                                                                    sjt_parent42 = &_parent->datay;
                                                                    sjt_functionParam163 = n;
                                                                    sjt_functionParam165 = sjv_t;
                                                                    sjf_f32_cos(sjt_functionParam165, &sjt_capture42);
                                                                    sjt_functionParam164 = 5.0f * sjt_capture42;
                                                                    sjf_array_f32_setat(sjt_parent42, sjt_functionParam163, sjt_functionParam164);
                                                                    n++;
                                                                }
                                                            } else {
                                                                if (underscore1 == 15) {
                                                                    int32_t n;
                                                                    int32_t sjt_forEnd16;
                                                                    int32_t sjt_forStart16;

                                                                    sjt_forStart16 = 0;
                                                                    sjt_forEnd16 = sjv_dots;
                                                                    n = sjt_forStart16;
                                                                    while (n < sjt_forEnd16) {
                                                                        float sjt_capture43;
                                                                        float sjt_capture44;
                                                                        float sjt_capture45;
                                                                        float sjt_capture46;
                                                                        int32_t sjt_functionParam166;
                                                                        int32_t sjt_functionParam167;
                                                                        int32_t sjt_functionParam168;
                                                                        float sjt_functionParam169;
                                                                        float sjt_functionParam170;
                                                                        float sjt_functionParam171;
                                                                        float sjt_functionParam172;
                                                                        float sjt_functionParam173;
                                                                        int32_t sjt_functionParam174;
                                                                        float sjt_functionParam175;
                                                                        float sjt_functionParam176;
                                                                        float sjt_functionParam177;
                                                                        float sjt_functionParam178;
                                                                        float sjt_functionParam179;
                                                                        sjs_array_f32* sjt_parent43 = 0;
                                                                        sjs_array_f32* sjt_parent44 = 0;
                                                                        float sjv_t;

                                                                        sjt_functionParam166 = 1;
                                                                        sjt_functionParam167 = n;
                                                                        sjf_test_gettm(_parent, sjt_functionParam166, sjt_functionParam167, &sjv_t);
                                                                        sjt_parent43 = &_parent->datax;
                                                                        sjt_functionParam168 = n;
                                                                        sjt_functionParam170 = sjv_t;
                                                                        sjf_f32_cos(sjt_functionParam170, &sjt_capture43);
                                                                        sjt_functionParam172 = 80.0f * sjv_t;
                                                                        sjf_f32_cos(sjt_functionParam172, &sjt_functionParam171);
                                                                        sjt_functionParam173 = 3.0f;
                                                                        sjf_f32_pow(sjt_functionParam171, sjt_functionParam173, &sjt_capture44);
                                                                        sjt_functionParam169 = (sjt_capture43 + sjt_capture44) * 3.0f;
                                                                        sjf_array_f32_setat(sjt_parent43, sjt_functionParam168, sjt_functionParam169);
                                                                        sjt_parent44 = &_parent->datay;
                                                                        sjt_functionParam174 = n;
                                                                        sjt_functionParam176 = 80.0f * sjv_t;
                                                                        sjf_f32_sin(sjt_functionParam176, &sjt_capture45);
                                                                        sjt_functionParam178 = sjv_t;
                                                                        sjf_f32_sin(sjt_functionParam178, &sjt_functionParam177);
                                                                        sjt_functionParam179 = 4.0f;
                                                                        sjf_f32_pow(sjt_functionParam177, sjt_functionParam179, &sjt_capture46);
                                                                        sjt_functionParam175 = (sjt_capture45 + sjt_capture46) * 2.5f;
                                                                        sjf_array_f32_setat(sjt_parent44, sjt_functionParam174, sjt_functionParam175);
                                                                        n++;
                                                                    }
                                                                } else {
                                                                    if (underscore1 == 16) {
                                                                        int32_t n;
                                                                        int32_t sjt_forEnd17;
                                                                        int32_t sjt_forStart17;

                                                                        sjt_forStart17 = 0;
                                                                        sjt_forEnd17 = sjv_dots;
                                                                        n = sjt_forStart17;
                                                                        while (n < sjt_forEnd17) {
                                                                            float sjt_capture47;
                                                                            float sjt_capture48;
                                                                            float sjt_capture49;
                                                                            float sjt_capture50;
                                                                            float sjt_capture51;
                                                                            float sjt_capture52;
                                                                            float sjt_capture53;
                                                                            float sjt_capture54;
                                                                            float sjt_capture55;
                                                                            float sjt_capture56;
                                                                            float sjt_capture57;
                                                                            float sjt_capture58;
                                                                            int32_t sjt_functionParam180;
                                                                            int32_t sjt_functionParam181;
                                                                            int32_t sjt_functionParam182;
                                                                            float sjt_functionParam183;
                                                                            float sjt_functionParam184;
                                                                            float sjt_functionParam185;
                                                                            float sjt_functionParam186;
                                                                            float sjt_functionParam187;
                                                                            float sjt_functionParam188;
                                                                            float sjt_functionParam189;
                                                                            float sjt_functionParam190;
                                                                            float sjt_functionParam191;
                                                                            float sjt_functionParam192;
                                                                            float sjt_functionParam193;
                                                                            float sjt_functionParam194;
                                                                            float sjt_functionParam195;
                                                                            float sjt_functionParam196;
                                                                            float sjt_functionParam197;
                                                                            int32_t sjt_functionParam198;
                                                                            float sjt_functionParam199;
                                                                            float sjt_functionParam200;
                                                                            float sjt_functionParam201;
                                                                            float sjt_functionParam202;
                                                                            float sjt_functionParam203;
                                                                            float sjt_functionParam204;
                                                                            float sjt_functionParam205;
                                                                            float sjt_functionParam206;
                                                                            float sjt_functionParam207;
                                                                            float sjt_functionParam208;
                                                                            float sjt_functionParam209;
                                                                            float sjt_functionParam210;
                                                                            float sjt_functionParam211;
                                                                            float sjt_functionParam212;
                                                                            float sjt_functionParam213;
                                                                            sjs_array_f32* sjt_parent45 = 0;
                                                                            sjs_array_f32* sjt_parent46 = 0;
                                                                            float sjv_t;

                                                                            sjt_functionParam180 = 1;
                                                                            sjt_functionParam181 = n;
                                                                            sjf_test_gettm(_parent, sjt_functionParam180, sjt_functionParam181, &sjv_t);
                                                                            sjt_parent45 = &_parent->datax;
                                                                            sjt_functionParam182 = n;
                                                                            sjt_functionParam184 = sjv_t;
                                                                            sjf_f32_cos(sjt_functionParam184, &sjt_capture47);
                                                                            sjt_functionParam187 = sjv_t;
                                                                            sjf_f32_sin(sjt_functionParam187, &sjt_functionParam186);
                                                                            sjt_functionParam188 = 2.0f;
                                                                            sjf_f32_pow(sjt_functionParam186, sjt_functionParam188, &sjt_capture48);
                                                                            sjt_functionParam190 = sjv_t;
                                                                            sjf_f32_cos(sjt_functionParam190, &sjt_functionParam189);
                                                                            sjt_functionParam191 = 2.0f;
                                                                            sjf_f32_pow(sjt_functionParam189, sjt_functionParam191, &sjt_capture49);
                                                                            sjt_functionParam193 = sjv_t;
                                                                            sjf_f32_sin(sjt_functionParam193, &sjt_functionParam192);
                                                                            sjt_functionParam194 = 2.0f;
                                                                            sjf_f32_pow(sjt_functionParam192, sjt_functionParam194, &sjt_capture50);
                                                                            sjt_functionParam196 = sjv_t;
                                                                            sjf_f32_cos(sjt_functionParam196, &sjt_functionParam195);
                                                                            sjt_functionParam197 = 2.0f;
                                                                            sjf_f32_pow(sjt_functionParam195, sjt_functionParam197, &sjt_capture51);
                                                                            sjt_functionParam185 = (((2.0f * 2.0f) * sjt_capture48) - ((5.0f * 5.0f) * sjt_capture49)) / (sjt_capture50 - sjt_capture51);
                                                                            sjf_f32_sqrt(sjt_functionParam185, &sjt_capture52);
                                                                            sjt_functionParam183 = sjt_capture47 * sjt_capture52;
                                                                            sjf_array_f32_setat(sjt_parent45, sjt_functionParam182, sjt_functionParam183);
                                                                            sjt_parent46 = &_parent->datay;
                                                                            sjt_functionParam198 = n;
                                                                            sjt_functionParam200 = sjv_t;
                                                                            sjf_f32_sin(sjt_functionParam200, &sjt_capture53);
                                                                            sjt_functionParam203 = sjv_t;
                                                                            sjf_f32_sin(sjt_functionParam203, &sjt_functionParam202);
                                                                            sjt_functionParam204 = 2.0f;
                                                                            sjf_f32_pow(sjt_functionParam202, sjt_functionParam204, &sjt_capture54);
                                                                            sjt_functionParam206 = sjv_t;
                                                                            sjf_f32_cos(sjt_functionParam206, &sjt_functionParam205);
                                                                            sjt_functionParam207 = 2.0f;
                                                                            sjf_f32_pow(sjt_functionParam205, sjt_functionParam207, &sjt_capture55);
                                                                            sjt_functionParam209 = sjv_t;
                                                                            sjf_f32_sin(sjt_functionParam209, &sjt_functionParam208);
                                                                            sjt_functionParam210 = 2.0f;
                                                                            sjf_f32_pow(sjt_functionParam208, sjt_functionParam210, &sjt_capture56);
                                                                            sjt_functionParam212 = sjv_t;
                                                                            sjf_f32_cos(sjt_functionParam212, &sjt_functionParam211);
                                                                            sjt_functionParam213 = 2.0f;
                                                                            sjf_f32_pow(sjt_functionParam211, sjt_functionParam213, &sjt_capture57);
                                                                            sjt_functionParam201 = (((2.0f * 2.0f) * sjt_capture54) - ((5.0f * 5.0f) * sjt_capture55)) / (sjt_capture56 - sjt_capture57);
                                                                            sjf_f32_sqrt(sjt_functionParam201, &sjt_capture58);
                                                                            sjt_functionParam199 = sjt_capture53 * sjt_capture58;
                                                                            sjf_array_f32_setat(sjt_parent46, sjt_functionParam198, sjt_functionParam199);
                                                                            n++;
                                                                        }
                                                                    } else {
                                                                        if (underscore1 == 17) {
                                                                            int32_t n;
                                                                            int32_t sjt_forEnd18;
                                                                            int32_t sjt_forStart18;

                                                                            sjt_forStart18 = 0;
                                                                            sjt_forEnd18 = sjv_dots;
                                                                            n = sjt_forStart18;
                                                                            while (n < sjt_forEnd18) {
                                                                                float sjt_capture59;
                                                                                float sjt_capture60;
                                                                                float sjt_capture61;
                                                                                float sjt_capture62;
                                                                                int32_t sjt_functionParam214;
                                                                                int32_t sjt_functionParam215;
                                                                                int32_t sjt_functionParam216;
                                                                                float sjt_functionParam217;
                                                                                float sjt_functionParam218;
                                                                                float sjt_functionParam219;
                                                                                float sjt_functionParam220;
                                                                                float sjt_functionParam221;
                                                                                int32_t sjt_functionParam222;
                                                                                float sjt_functionParam223;
                                                                                float sjt_functionParam224;
                                                                                float sjt_functionParam225;
                                                                                float sjt_functionParam226;
                                                                                float sjt_functionParam227;
                                                                                sjs_array_f32* sjt_parent47 = 0;
                                                                                sjs_array_f32* sjt_parent48 = 0;
                                                                                float sjv_t;

                                                                                sjt_functionParam214 = 1;
                                                                                sjt_functionParam215 = n;
                                                                                sjf_test_gettm(_parent, sjt_functionParam214, sjt_functionParam215, &sjv_t);
                                                                                sjt_parent47 = &_parent->datax;
                                                                                sjt_functionParam216 = n;
                                                                                sjt_functionParam218 = sjv_t;
                                                                                sjf_f32_cos(sjt_functionParam218, &sjt_capture59);
                                                                                sjt_functionParam220 = sjv_t;
                                                                                sjf_f32_sin(sjt_functionParam220, &sjt_functionParam219);
                                                                                sjt_functionParam221 = 2.0f;
                                                                                sjf_f32_pow(sjt_functionParam219, sjt_functionParam221, &sjt_capture60);
                                                                                sjt_functionParam217 = (3.0f * sjt_capture59) * (1.0f - (2.0f * sjt_capture60));
                                                                                sjf_array_f32_setat(sjt_parent47, sjt_functionParam216, sjt_functionParam217);
                                                                                sjt_parent48 = &_parent->datay;
                                                                                sjt_functionParam222 = n;
                                                                                sjt_functionParam224 = sjv_t;
                                                                                sjf_f32_sin(sjt_functionParam224, &sjt_capture61);
                                                                                sjt_functionParam226 = sjv_t;
                                                                                sjf_f32_cos(sjt_functionParam226, &sjt_functionParam225);
                                                                                sjt_functionParam227 = 2.0f;
                                                                                sjf_f32_pow(sjt_functionParam225, sjt_functionParam227, &sjt_capture62);
                                                                                sjt_functionParam223 = (3.0f * sjt_capture61) * (1.0f - (2.0f * sjt_capture62));
                                                                                sjf_array_f32_setat(sjt_parent48, sjt_functionParam222, sjt_functionParam223);
                                                                                n++;
                                                                            }
                                                                        } else {
                                                                            _parent->funcid = 18;
                                                                            sjv_persp = 50.0f;
                                                                            sjf_test_imgdata_functionlist(_parent);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void sjf_test_copy(sjs_test* _this, sjs_test* _from) {
    _this->funcid = _from->funcid;
    _this->lastfuncid = _from->lastfuncid;
    _this->datax._refCount = 1;
    sjf_array_f32_copy(&_this->datax, &_from->datax);
    _this->datay._refCount = 1;
    sjf_array_f32_copy(&_this->datay, &_from->datay);
    _this->rotatex = _from->rotatex;
    _this->rotatey = _from->rotatey;
    _this->rotatez = _from->rotatez;
    _this->datavert1x._refCount = 1;
    sjf_array_f32_copy(&_this->datavert1x, &_from->datavert1x);
    _this->datavert1y._refCount = 1;
    sjf_array_f32_copy(&_this->datavert1y, &_from->datavert1y);
    _this->datavert2x._refCount = 1;
    sjf_array_f32_copy(&_this->datavert2x, &_from->datavert2x);
    _this->datavert2y._refCount = 1;
    sjf_array_f32_copy(&_this->datavert2y, &_from->datavert2y);
    _this->datavert3x._refCount = 1;
    sjf_array_f32_copy(&_this->datavert3x, &_from->datavert3x);
    _this->datavert3y._refCount = 1;
    sjf_array_f32_copy(&_this->datavert3y, &_from->datavert3y);
    _this->datavert4x._refCount = 1;
    sjf_array_f32_copy(&_this->datavert4x, &_from->datavert4x);
    _this->datavert4y._refCount = 1;
    sjf_array_f32_copy(&_this->datavert4y, &_from->datavert4y);
    _this->datavert5x._refCount = 1;
    sjf_array_f32_copy(&_this->datavert5x, &_from->datavert5x);
    _this->datavert5y._refCount = 1;
    sjf_array_f32_copy(&_this->datavert5y, &_from->datavert5y);
    _this->datahotizont1x._refCount = 1;
    sjf_array_f32_copy(&_this->datahotizont1x, &_from->datahotizont1x);
    _this->datahotizont1y._refCount = 1;
    sjf_array_f32_copy(&_this->datahotizont1y, &_from->datahotizont1y);
    _this->datahotizont2x._refCount = 1;
    sjf_array_f32_copy(&_this->datahotizont2x, &_from->datahotizont2x);
    _this->datahotizont2y._refCount = 1;
    sjf_array_f32_copy(&_this->datahotizont2y, &_from->datahotizont2y);
    _this->datahotizont3x._refCount = 1;
    sjf_array_f32_copy(&_this->datahotizont3x, &_from->datahotizont3x);
    _this->datahotizont3y._refCount = 1;
    sjf_array_f32_copy(&_this->datahotizont3y, &_from->datahotizont3y);
    _this->datahotizont4x._refCount = 1;
    sjf_array_f32_copy(&_this->datahotizont4x, &_from->datahotizont4x);
    _this->datahotizont4y._refCount = 1;
    sjf_array_f32_copy(&_this->datahotizont4y, &_from->datahotizont4y);
    _this->datahotizont5x._refCount = 1;
    sjf_array_f32_copy(&_this->datahotizont5x, &_from->datahotizont5x);
    _this->datahotizont5y._refCount = 1;
    sjf_array_f32_copy(&_this->datahotizont5y, &_from->datahotizont5y);
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_test_destroy(sjs_test* _this) {
    if (_this->datax._refCount == 1) { sjf_array_f32_destroy(&_this->datax); }
;
    if (_this->datay._refCount == 1) { sjf_array_f32_destroy(&_this->datay); }
;
    if (_this->datavert1x._refCount == 1) { sjf_array_f32_destroy(&_this->datavert1x); }
;
    if (_this->datavert1y._refCount == 1) { sjf_array_f32_destroy(&_this->datavert1y); }
;
    if (_this->datavert2x._refCount == 1) { sjf_array_f32_destroy(&_this->datavert2x); }
;
    if (_this->datavert2y._refCount == 1) { sjf_array_f32_destroy(&_this->datavert2y); }
;
    if (_this->datavert3x._refCount == 1) { sjf_array_f32_destroy(&_this->datavert3x); }
;
    if (_this->datavert3y._refCount == 1) { sjf_array_f32_destroy(&_this->datavert3y); }
;
    if (_this->datavert4x._refCount == 1) { sjf_array_f32_destroy(&_this->datavert4x); }
;
    if (_this->datavert4y._refCount == 1) { sjf_array_f32_destroy(&_this->datavert4y); }
;
    if (_this->datavert5x._refCount == 1) { sjf_array_f32_destroy(&_this->datavert5x); }
;
    if (_this->datavert5y._refCount == 1) { sjf_array_f32_destroy(&_this->datavert5y); }
;
    if (_this->datahotizont1x._refCount == 1) { sjf_array_f32_destroy(&_this->datahotizont1x); }
;
    if (_this->datahotizont1y._refCount == 1) { sjf_array_f32_destroy(&_this->datahotizont1y); }
;
    if (_this->datahotizont2x._refCount == 1) { sjf_array_f32_destroy(&_this->datahotizont2x); }
;
    if (_this->datahotizont2y._refCount == 1) { sjf_array_f32_destroy(&_this->datahotizont2y); }
;
    if (_this->datahotizont3x._refCount == 1) { sjf_array_f32_destroy(&_this->datahotizont3x); }
;
    if (_this->datahotizont3y._refCount == 1) { sjf_array_f32_destroy(&_this->datahotizont3y); }
;
    if (_this->datahotizont4x._refCount == 1) { sjf_array_f32_destroy(&_this->datahotizont4x); }
;
    if (_this->datahotizont4y._refCount == 1) { sjf_array_f32_destroy(&_this->datahotizont4y); }
;
    if (_this->datahotizont5x._refCount == 1) { sjf_array_f32_destroy(&_this->datahotizont5x); }
;
    if (_this->datahotizont5y._refCount == 1) { sjf_array_f32_destroy(&_this->datahotizont5y); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_test_findaxis(sjs_test* _parent) {
    bool result17;
    bool sjt_capture63;
    bool sjt_capture84;
    bool sjt_capture85;
    int32_t sjt_functionParam270;
    int32_t sjt_functionParam330;
    int32_t sjt_functionParam331;
    sjs_array_bool* sjt_parent111 = 0;
    sjs_array_bool* sjt_parent112 = 0;
    sjs_array_bool* sjt_parent69 = 0;

    sjt_parent69 = &sjv_mainrot;
    sjt_functionParam270 = 0;
    sjf_array_bool_getat(sjt_parent69, sjt_functionParam270, &sjt_capture63);
    result17 = !sjt_capture63;
    if (result17) {
        bool result19;
        bool result20;
        bool sjt_capture64;
        bool sjt_capture65;
        bool sjt_capture66;
        bool sjt_capture72;
        bool sjt_capture73;
        bool sjt_capture74;
        int32_t sjt_functionParam271;
        int32_t sjt_functionParam272;
        int32_t sjt_functionParam273;
        int32_t sjt_functionParam289;
        int32_t sjt_functionParam290;
        int32_t sjt_functionParam291;
        sjs_array_bool* sjt_parent70 = 0;
        sjs_array_bool* sjt_parent71 = 0;
        sjs_array_bool* sjt_parent72 = 0;
        sjs_array_bool* sjt_parent84 = 0;
        sjs_array_bool* sjt_parent85 = 0;
        sjs_array_bool* sjt_parent86 = 0;

        sjt_parent70 = &sjv_stateof;
        sjt_functionParam271 = 0;
        sjf_array_bool_getat(sjt_parent70, sjt_functionParam271, &sjt_capture64);
        sjt_parent71 = &sjv_stateof;
        sjt_functionParam272 = 1;
        sjf_array_bool_getat(sjt_parent71, sjt_functionParam272, &sjt_capture65);
        sjt_parent72 = &sjv_stateof;
        sjt_functionParam273 = 2;
        sjf_array_bool_getat(sjt_parent72, sjt_functionParam273, &sjt_capture66);
        if (sjt_capture64 && (sjt_capture65 && sjt_capture66)) {
            bool sjt_capture67;
            int32_t sjt_functionParam274;
            sjs_array_bool* sjt_parent73 = 0;

            sjt_parent73 = &sjv_stateofdir;
            sjt_functionParam274 = 0;
            sjf_array_bool_getat(sjt_parent73, sjt_functionParam274, &sjt_capture67);
            if (sjt_capture67) {
                int32_t sjt_functionParam275;
                bool sjt_functionParam276;
                sjs_array_bool* sjt_parent74 = 0;

                _parent->rotatey = _parent->rotatey + 0.05f;
                sjt_parent74 = &sjv_stateofdir;
                sjt_functionParam275 = 0;
                sjt_functionParam276 = _parent->rotatey < 7.0f;
                sjf_array_bool_setat(sjt_parent74, sjt_functionParam275, sjt_functionParam276);
            } else {
                int32_t sjt_functionParam277;
                bool sjt_functionParam278;
                int32_t sjt_functionParam279;
                sjs_array_bool* sjt_parent75 = 0;
                sjs_array_bool* sjt_parent76 = 0;

                sjt_parent75 = &sjv_stateof;
                sjt_functionParam277 = 0;
                sjt_parent76 = &sjv_stateofdir;
                sjt_functionParam279 = 0;
                sjf_array_bool_getat(sjt_parent76, sjt_functionParam279, &sjt_functionParam278);
                sjf_array_bool_setat(sjt_parent75, sjt_functionParam277, sjt_functionParam278);
            }
        } else {
            bool result18;
            bool sjt_capture68;
            bool sjt_capture69;
            bool sjt_capture70;
            int32_t sjt_functionParam280;
            int32_t sjt_functionParam281;
            int32_t sjt_functionParam282;
            sjs_array_bool* sjt_parent77 = 0;
            sjs_array_bool* sjt_parent78 = 0;
            sjs_array_bool* sjt_parent79 = 0;

            sjt_parent77 = &sjv_stateof;
            sjt_functionParam280 = 1;
            sjf_array_bool_getat(sjt_parent77, sjt_functionParam280, &sjt_capture68);
            sjt_parent78 = &sjv_stateof;
            sjt_functionParam281 = 0;
            sjf_array_bool_getat(sjt_parent78, sjt_functionParam281, &sjt_capture69);
            result18 = !sjt_capture69;
            sjt_parent79 = &sjv_stateof;
            sjt_functionParam282 = 2;
            sjf_array_bool_getat(sjt_parent79, sjt_functionParam282, &sjt_capture70);
            if (sjt_capture68 && (result18 && sjt_capture70)) {
                bool sjt_capture71;
                int32_t sjt_functionParam283;
                sjs_array_bool* sjt_parent80 = 0;

                if (_parent->rotatey > 0.0f) {
                    _parent->rotatey = _parent->rotatey - 0.05f;
                }

                sjt_parent80 = &sjv_stateofdir;
                sjt_functionParam283 = 1;
                sjf_array_bool_getat(sjt_parent80, sjt_functionParam283, &sjt_capture71);
                if (sjt_capture71) {
                    int32_t sjt_functionParam284;
                    bool sjt_functionParam285;
                    sjs_array_bool* sjt_parent81 = 0;

                    _parent->rotatex = _parent->rotatex + 0.05f;
                    sjt_parent81 = &sjv_stateofdir;
                    sjt_functionParam284 = 1;
                    sjt_functionParam285 = _parent->rotatex < 7.0f;
                    sjf_array_bool_setat(sjt_parent81, sjt_functionParam284, sjt_functionParam285);
                } else {
                    int32_t sjt_functionParam286;
                    bool sjt_functionParam287;
                    int32_t sjt_functionParam288;
                    sjs_array_bool* sjt_parent82 = 0;
                    sjs_array_bool* sjt_parent83 = 0;

                    sjt_parent82 = &sjv_stateof;
                    sjt_functionParam286 = 1;
                    sjt_parent83 = &sjv_stateofdir;
                    sjt_functionParam288 = 1;
                    sjf_array_bool_getat(sjt_parent83, sjt_functionParam288, &sjt_functionParam287);
                    sjf_array_bool_setat(sjt_parent82, sjt_functionParam286, sjt_functionParam287);
                }
            }
        }

        sjt_parent84 = &sjv_stateof;
        sjt_functionParam289 = 1;
        sjf_array_bool_getat(sjt_parent84, sjt_functionParam289, &sjt_capture72);
        result19 = !sjt_capture72;
        sjt_parent85 = &sjv_stateof;
        sjt_functionParam290 = 0;
        sjf_array_bool_getat(sjt_parent85, sjt_functionParam290, &sjt_capture73);
        result20 = !sjt_capture73;
        sjt_parent86 = &sjv_stateof;
        sjt_functionParam291 = 2;
        sjf_array_bool_getat(sjt_parent86, sjt_functionParam291, &sjt_capture74);
        if (result19 && (result20 && sjt_capture74)) {
            bool sjt_capture75;
            int32_t sjt_functionParam292;
            sjs_array_bool* sjt_parent87 = 0;

            if (_parent->rotatex > 0.0f) {
                _parent->rotatex = _parent->rotatex - 0.05f;
            }

            sjt_parent87 = &sjv_stateofdir;
            sjt_functionParam292 = 2;
            sjf_array_bool_getat(sjt_parent87, sjt_functionParam292, &sjt_capture75);
            if (sjt_capture75) {
                int32_t sjt_functionParam293;
                bool sjt_functionParam294;
                sjs_array_bool* sjt_parent88 = 0;

                _parent->rotatez = _parent->rotatez + 0.05f;
                sjt_parent88 = &sjv_stateofdir;
                sjt_functionParam293 = 2;
                sjt_functionParam294 = _parent->rotatez < 7.0f;
                sjf_array_bool_setat(sjt_parent88, sjt_functionParam293, sjt_functionParam294);
            } else {
                bool result21;
                bool sjt_capture76;
                int32_t sjt_functionParam295;
                bool sjt_functionParam296;
                int32_t sjt_functionParam297;
                int32_t sjt_functionParam298;
                bool sjt_functionParam299;
                int32_t sjt_functionParam300;
                sjs_array_bool* sjt_parent89 = 0;
                sjs_array_bool* sjt_parent90 = 0;
                sjs_array_bool* sjt_parent91 = 0;
                sjs_array_bool* sjt_parent92 = 0;

                sjt_parent89 = &sjv_stateof;
                sjt_functionParam295 = 2;
                sjt_parent90 = &sjv_stateofdir;
                sjt_functionParam297 = 2;
                sjf_array_bool_getat(sjt_parent90, sjt_functionParam297, &sjt_functionParam296);
                sjf_array_bool_setat(sjt_parent89, sjt_functionParam295, sjt_functionParam296);
                sjt_parent91 = &sjv_mainrot;
                sjt_functionParam298 = 0;
                sjt_parent92 = &sjv_stateofdir;
                sjt_functionParam300 = 2;
                sjf_array_bool_getat(sjt_parent92, sjt_functionParam300, &sjt_capture76);
                result21 = !sjt_capture76;
                sjt_functionParam299 = result21;
                sjf_array_bool_setat(sjt_parent91, sjt_functionParam298, sjt_functionParam299);
            }
        }
    } else {
        bool result22;
        bool sjt_capture77;
        int32_t sjt_functionParam301;
        sjs_array_bool* sjt_parent93 = 0;

        sjt_parent93 = &sjv_mainrot;
        sjt_functionParam301 = 1;
        sjf_array_bool_getat(sjt_parent93, sjt_functionParam301, &sjt_capture77);
        result22 = !sjt_capture77;
        if (result22) {
            bool sjt_capture78;
            int32_t sjt_functionParam302;
            sjs_array_bool* sjt_parent94 = 0;

            sjt_parent94 = &sjv_stateofdir;
            sjt_functionParam302 = 0;
            sjf_array_bool_getat(sjt_parent94, sjt_functionParam302, &sjt_capture78);
            if (sjt_capture78) {
                bool sjt_capture79;
                int32_t sjt_functionParam303;
                bool sjt_functionParam304;
                int32_t sjt_functionParam305;
                sjs_array_bool* sjt_parent95 = 0;
                sjs_array_bool* sjt_parent96 = 0;

                _parent->rotatey = _parent->rotatey + 0.05f;
                sjt_parent95 = &sjv_stateofdir;
                sjt_functionParam303 = 0;
                sjt_functionParam304 = _parent->rotatey < 7.0f;
                sjf_array_bool_setat(sjt_parent95, sjt_functionParam303, sjt_functionParam304);
                sjt_parent96 = &sjv_stateofdir;
                sjt_functionParam305 = 2;
                sjf_array_bool_getat(sjt_parent96, sjt_functionParam305, &sjt_capture79);
                if (sjt_capture79) {
                    int32_t sjt_functionParam306;
                    bool sjt_functionParam307;
                    sjs_array_bool* sjt_parent97 = 0;

                    _parent->rotatez = _parent->rotatez + 0.05f;
                    sjt_parent97 = &sjv_stateofdir;
                    sjt_functionParam306 = 2;
                    sjt_functionParam307 = _parent->rotatez < 7.0f;
                    sjf_array_bool_setat(sjt_parent97, sjt_functionParam306, sjt_functionParam307);
                } else {
                    float result23;
                    int32_t sjt_functionParam308;
                    bool sjt_functionParam309;
                    sjs_array_bool* sjt_parent98 = 0;

                    _parent->rotatez = _parent->rotatez - 0.05f;
                    sjt_parent98 = &sjv_stateofdir;
                    sjt_functionParam308 = 2;
                    result23 = -7.0f;
                    sjt_functionParam309 = _parent->rotatez < result23;
                    sjf_array_bool_setat(sjt_parent98, sjt_functionParam308, sjt_functionParam309);
                }
            } else {
                float result28;
                bool sjt_capture80;
                int32_t sjt_functionParam310;
                int32_t sjt_functionParam328;
                bool sjt_functionParam329;
                sjs_array_bool* sjt_parent110 = 0;
                sjs_array_bool* sjt_parent99 = 0;

                sjt_parent99 = &sjv_stateofdir;
                sjt_functionParam310 = 1;
                sjf_array_bool_getat(sjt_parent99, sjt_functionParam310, &sjt_capture80);
                if (sjt_capture80) {
                    bool sjt_capture81;
                    int32_t sjt_functionParam311;
                    bool sjt_functionParam312;
                    int32_t sjt_functionParam313;
                    sjs_array_bool* sjt_parent100 = 0;
                    sjs_array_bool* sjt_parent101 = 0;

                    _parent->rotatex = _parent->rotatex + 0.05f;
                    sjt_parent100 = &sjv_stateofdir;
                    sjt_functionParam311 = 1;
                    sjt_functionParam312 = _parent->rotatex < 7.0f;
                    sjf_array_bool_setat(sjt_parent100, sjt_functionParam311, sjt_functionParam312);
                    sjt_parent101 = &sjv_stateofdir;
                    sjt_functionParam313 = 2;
                    sjf_array_bool_getat(sjt_parent101, sjt_functionParam313, &sjt_capture81);
                    if (sjt_capture81) {
                        int32_t sjt_functionParam314;
                        bool sjt_functionParam315;
                        sjs_array_bool* sjt_parent102 = 0;

                        _parent->rotatez = _parent->rotatez + 0.05f;
                        sjt_parent102 = &sjv_stateofdir;
                        sjt_functionParam314 = 2;
                        sjt_functionParam315 = _parent->rotatez < 7.0f;
                        sjf_array_bool_setat(sjt_parent102, sjt_functionParam314, sjt_functionParam315);
                    } else {
                        float result24;
                        int32_t sjt_functionParam316;
                        bool sjt_functionParam317;
                        sjs_array_bool* sjt_parent103 = 0;

                        _parent->rotatez = _parent->rotatez - 0.05f;
                        sjt_parent103 = &sjv_stateofdir;
                        sjt_functionParam316 = 2;
                        result24 = -7.0f;
                        sjt_functionParam317 = _parent->rotatez < result24;
                        sjf_array_bool_setat(sjt_parent103, sjt_functionParam316, sjt_functionParam317);
                    }
                } else {
                    float result25;
                    bool sjt_capture82;
                    int32_t sjt_functionParam318;
                    bool sjt_functionParam319;
                    int32_t sjt_functionParam320;
                    sjs_array_bool* sjt_parent104 = 0;
                    sjs_array_bool* sjt_parent105 = 0;

                    _parent->rotatex = _parent->rotatex - 0.05f;
                    sjt_parent104 = &sjv_stateofdir;
                    sjt_functionParam318 = 1;
                    result25 = -7.0f;
                    sjt_functionParam319 = _parent->rotatex < result25;
                    sjf_array_bool_setat(sjt_parent104, sjt_functionParam318, sjt_functionParam319);
                    sjt_parent105 = &sjv_stateofdir;
                    sjt_functionParam320 = 2;
                    sjf_array_bool_getat(sjt_parent105, sjt_functionParam320, &sjt_capture82);
                    if (sjt_capture82) {
                        int32_t sjt_functionParam321;
                        bool sjt_functionParam322;
                        sjs_array_bool* sjt_parent106 = 0;

                        _parent->rotatez = _parent->rotatez + 0.05f;
                        sjt_parent106 = &sjv_stateofdir;
                        sjt_functionParam321 = 2;
                        sjt_functionParam322 = _parent->rotatez < 7.0f;
                        sjf_array_bool_setat(sjt_parent106, sjt_functionParam321, sjt_functionParam322);
                        if (_parent->funcid != 18) {
                            bool result26;
                            bool sjt_capture83;
                            int32_t sjt_functionParam323;
                            bool sjt_functionParam324;
                            int32_t sjt_functionParam325;
                            sjs_array_bool* sjt_parent107 = 0;
                            sjs_array_bool* sjt_parent108 = 0;

                            sjt_parent107 = &sjv_mainrot;
                            sjt_functionParam323 = 1;
                            sjt_parent108 = &sjv_stateofdir;
                            sjt_functionParam325 = 2;
                            sjf_array_bool_getat(sjt_parent108, sjt_functionParam325, &sjt_capture83);
                            result26 = !sjt_capture83;
                            sjt_functionParam324 = result26;
                            sjf_array_bool_setat(sjt_parent107, sjt_functionParam323, sjt_functionParam324);
                        }
                    } else {
                        float result27;
                        int32_t sjt_functionParam326;
                        bool sjt_functionParam327;
                        sjs_array_bool* sjt_parent109 = 0;

                        _parent->rotatez = _parent->rotatez - 0.05f;
                        sjt_parent109 = &sjv_stateofdir;
                        sjt_functionParam326 = 2;
                        result27 = -7.0f;
                        sjt_functionParam327 = _parent->rotatez < result27;
                        sjf_array_bool_setat(sjt_parent109, sjt_functionParam326, sjt_functionParam327);
                    }
                }

                _parent->rotatey = _parent->rotatey - 0.05f;
                sjt_parent110 = &sjv_stateofdir;
                sjt_functionParam328 = 0;
                result28 = -7.0f;
                sjt_functionParam329 = _parent->rotatey < result28;
                sjf_array_bool_setat(sjt_parent110, sjt_functionParam328, sjt_functionParam329);
            }
        }
    }

    sjt_parent111 = &sjv_mainrot;
    sjt_functionParam330 = 0;
    sjf_array_bool_getat(sjt_parent111, sjt_functionParam330, &sjt_capture84);
    sjt_parent112 = &sjv_mainrot;
    sjt_functionParam331 = 1;
    sjf_array_bool_getat(sjt_parent112, sjt_functionParam331, &sjt_capture85);
    if (sjt_capture84 && sjt_capture85) {
        if (_parent->rotatez > 0.0f) {
            _parent->rotatez = _parent->rotatez - 0.1f;
        } else {
            int32_t sjt_functionParam332;
            bool sjt_functionParam333;
            int32_t sjt_functionParam334;
            bool sjt_functionParam335;
            int32_t sjt_functionParam336;
            bool sjt_functionParam337;
            int32_t sjt_functionParam338;
            bool sjt_functionParam339;
            int32_t sjt_functionParam340;
            bool sjt_functionParam341;
            int32_t sjt_functionParam342;
            bool sjt_functionParam343;
            int32_t sjt_functionParam344;
            bool sjt_functionParam345;
            int32_t sjt_functionParam346;
            bool sjt_functionParam347;
            sjs_array_bool* sjt_parent113 = 0;
            sjs_array_bool* sjt_parent114 = 0;
            sjs_array_bool* sjt_parent115 = 0;
            sjs_array_bool* sjt_parent116 = 0;
            sjs_array_bool* sjt_parent117 = 0;
            sjs_array_bool* sjt_parent118 = 0;
            sjs_array_bool* sjt_parent119 = 0;
            sjs_array_bool* sjt_parent120 = 0;

            _parent->rotatez = 0.0f;
            _parent->rotatex = 0.0f;
            _parent->rotatey = 0.0f;
            sjt_parent113 = &sjv_stateof;
            sjt_functionParam332 = 0;
            sjt_functionParam333 = true;
            sjf_array_bool_setat(sjt_parent113, sjt_functionParam332, sjt_functionParam333);
            sjt_parent114 = &sjv_stateof;
            sjt_functionParam334 = 1;
            sjt_functionParam335 = true;
            sjf_array_bool_setat(sjt_parent114, sjt_functionParam334, sjt_functionParam335);
            sjt_parent115 = &sjv_stateof;
            sjt_functionParam336 = 2;
            sjt_functionParam337 = true;
            sjf_array_bool_setat(sjt_parent115, sjt_functionParam336, sjt_functionParam337);
            sjt_parent116 = &sjv_stateofdir;
            sjt_functionParam338 = 0;
            sjt_functionParam339 = true;
            sjf_array_bool_setat(sjt_parent116, sjt_functionParam338, sjt_functionParam339);
            sjt_parent117 = &sjv_stateofdir;
            sjt_functionParam340 = 1;
            sjt_functionParam341 = true;
            sjf_array_bool_setat(sjt_parent117, sjt_functionParam340, sjt_functionParam341);
            sjt_parent118 = &sjv_stateofdir;
            sjt_functionParam342 = 2;
            sjt_functionParam343 = true;
            sjf_array_bool_setat(sjt_parent118, sjt_functionParam342, sjt_functionParam343);
            sjt_parent119 = &sjv_mainrot;
            sjt_functionParam344 = 0;
            sjt_functionParam345 = false;
            sjf_array_bool_setat(sjt_parent119, sjt_functionParam344, sjt_functionParam345);
            sjt_parent120 = &sjv_mainrot;
            sjt_functionParam346 = 1;
            sjt_functionParam347 = false;
            sjf_array_bool_setat(sjt_parent120, sjt_functionParam346, sjt_functionParam347);
            _parent->funcid = _parent->funcid + 1;
        }
    }
}

void sjf_test_firemouseevent(sjs_test* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    (*_return) = true;
}

void sjf_test_getclasstype(sjs_object* _this, int* _return) {
    *_return = 86;
}

void sjf_test_getrect(sjs_test* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
    sjf_rect_copy(_return, (&_parent->_rect));
}

void sjf_test_getrect_heap(sjs_test* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), (&_parent->_rect));
}

void sjf_test_getsize(sjs_test* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    _return->w = maxsize->w;
    _return->h = maxsize->h;
    sjf_size(_return);
}

void sjf_test_getsize_heap(sjs_test* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    (*_return)->w = maxsize->w;
    (*_return)->h = maxsize->h;
    sjf_size_heap((*_return));
}

void sjf_test_gett(sjs_test* _parent, int32_t xpi, int32_t n, float* _return) {
    int32_t sjt_cast10;
    int32_t sjt_cast11;
    int32_t sjt_cast12;

    sjt_cast10 = xpi;
    sjt_cast11 = n;
    sjt_cast12 = sjv_dotsscale;
    (*_return) = (float)sjt_cast10 * ((float)sjt_cast11 / (float)sjt_cast12);
}

void sjf_test_gettm(sjs_test* _parent, int32_t xpi, int32_t n, float* _return) {
    float result4;
    int32_t sjt_cast6;
    int32_t sjt_cast7;
    int32_t sjt_cast8;
    int32_t sjt_cast9;

    sjt_cast6 = xpi;
    result4 = -1.0f;
    sjt_cast7 = xpi;
    sjt_cast8 = n;
    sjt_cast9 = sjv_dotsscale;
    (*_return) = ((float)sjt_cast6 * (result4 * sjv_f32_pi)) + (((float)sjt_cast7 * 2.0f) * ((float)sjt_cast8 / (float)sjt_cast9));
}

void sjf_test_heap(sjs_test* _this) {
}

void sjf_test_img_gettm(sjs_test* _parent, int32_t xpi, int32_t n, float* _return) {
    float result5;
    int32_t sjt_cast13;
    int32_t sjt_cast14;
    int32_t sjt_cast15;
    int32_t sjt_cast16;

    sjt_cast13 = xpi;
    result5 = -1.0f;
    sjt_cast14 = xpi;
    sjt_cast15 = n;
    sjt_cast16 = sjv_img_dotsscale;
    (*_return) = ((float)sjt_cast13 * (result5 * sjv_f32_pi)) + (((float)sjt_cast14 * 2.0f) * ((float)sjt_cast15 / (float)sjt_cast16));
}

void sjf_test_imgdata_functionlist(sjs_test* _parent) {
    int32_t n;
    int32_t sjt_forEnd19;
    int32_t sjt_forStart19;

    sjt_forStart19 = 0;
    sjt_forEnd19 = sjv_img_dots;
    n = sjt_forStart19;
    while (n < sjt_forEnd19) {
        float result10;
        float result11;
        float result12;
        float result13;
        float result14;
        float result15;
        float result16;
        float result6;
        float result7;
        float result8;
        float result9;
        int32_t sjt_functionParam228;
        int32_t sjt_functionParam229;
        int32_t sjt_functionParam230;
        float sjt_functionParam231;
        int32_t sjt_functionParam232;
        float sjt_functionParam233;
        int32_t sjt_functionParam234;
        float sjt_functionParam235;
        int32_t sjt_functionParam236;
        float sjt_functionParam237;
        int32_t sjt_functionParam238;
        float sjt_functionParam239;
        int32_t sjt_functionParam240;
        float sjt_functionParam241;
        int32_t sjt_functionParam242;
        float sjt_functionParam243;
        int32_t sjt_functionParam244;
        float sjt_functionParam245;
        int32_t sjt_functionParam246;
        float sjt_functionParam247;
        int32_t sjt_functionParam248;
        float sjt_functionParam249;
        int32_t sjt_functionParam250;
        float sjt_functionParam251;
        int32_t sjt_functionParam252;
        float sjt_functionParam253;
        int32_t sjt_functionParam254;
        float sjt_functionParam255;
        int32_t sjt_functionParam256;
        float sjt_functionParam257;
        int32_t sjt_functionParam258;
        float sjt_functionParam259;
        int32_t sjt_functionParam260;
        float sjt_functionParam261;
        int32_t sjt_functionParam262;
        float sjt_functionParam263;
        int32_t sjt_functionParam264;
        float sjt_functionParam265;
        int32_t sjt_functionParam266;
        float sjt_functionParam267;
        int32_t sjt_functionParam268;
        float sjt_functionParam269;
        sjs_array_f32* sjt_parent49 = 0;
        sjs_array_f32* sjt_parent50 = 0;
        sjs_array_f32* sjt_parent51 = 0;
        sjs_array_f32* sjt_parent52 = 0;
        sjs_array_f32* sjt_parent53 = 0;
        sjs_array_f32* sjt_parent54 = 0;
        sjs_array_f32* sjt_parent55 = 0;
        sjs_array_f32* sjt_parent56 = 0;
        sjs_array_f32* sjt_parent57 = 0;
        sjs_array_f32* sjt_parent58 = 0;
        sjs_array_f32* sjt_parent59 = 0;
        sjs_array_f32* sjt_parent60 = 0;
        sjs_array_f32* sjt_parent61 = 0;
        sjs_array_f32* sjt_parent62 = 0;
        sjs_array_f32* sjt_parent63 = 0;
        sjs_array_f32* sjt_parent64 = 0;
        sjs_array_f32* sjt_parent65 = 0;
        sjs_array_f32* sjt_parent66 = 0;
        sjs_array_f32* sjt_parent67 = 0;
        sjs_array_f32* sjt_parent68 = 0;
        float sjv_t;

        sjt_functionParam228 = 1;
        sjt_functionParam229 = n;
        sjf_test_img_gettm(_parent, sjt_functionParam228, sjt_functionParam229, &sjv_t);
        sjt_parent49 = &_parent->datavert1x;
        sjt_functionParam230 = n;
        result6 = -3.0f;
        sjt_functionParam231 = result6 + ((sjv_t * 0.98f) / 3.0f);
        sjf_array_f32_setat(sjt_parent49, sjt_functionParam230, sjt_functionParam231);
        sjt_parent50 = &_parent->datavert1y;
        sjt_functionParam232 = n;
        sjt_functionParam233 = sjv_t * 0.98f;
        sjf_array_f32_setat(sjt_parent50, sjt_functionParam232, sjt_functionParam233);
        sjt_parent51 = &_parent->datavert2x;
        sjt_functionParam234 = n;
        result7 = -2.0f;
        sjt_functionParam235 = (result7 - (2.0f / 3.0f)) + ((sjv_t / sjv_f32_pi) / 3.0f);
        sjf_array_f32_setat(sjt_parent51, sjt_functionParam234, sjt_functionParam235);
        sjt_parent52 = &_parent->datavert2y;
        sjt_functionParam236 = n;
        sjt_functionParam237 = (sjv_t / sjv_f32_pi) - 2.0f;
        sjf_array_f32_setat(sjt_parent52, sjt_functionParam236, sjt_functionParam237);
        sjt_parent53 = &_parent->datavert3x;
        sjt_functionParam238 = n;
        result8 = -1.0f;
        sjt_functionParam239 = (result8 - (2.0f / 3.0f)) + ((sjv_t / sjv_f32_pi) / 3.0f);
        sjf_array_f32_setat(sjt_parent53, sjt_functionParam238, sjt_functionParam239);
        sjt_parent54 = &_parent->datavert3y;
        sjt_functionParam240 = n;
        sjt_functionParam241 = (sjv_t / sjv_f32_pi) + 1.0f;
        sjf_array_f32_setat(sjt_parent54, sjt_functionParam240, sjt_functionParam241);
        sjt_parent55 = &_parent->datavert4x;
        sjt_functionParam242 = n;
        result9 = -2.0f;
        sjt_functionParam243 = (result9 / 3.0f) + ((sjv_t / sjv_f32_pi) / 3.0f);
        sjf_array_f32_setat(sjt_parent55, sjt_functionParam242, sjt_functionParam243);
        sjt_parent56 = &_parent->datavert4y;
        sjt_functionParam244 = n;
        sjt_functionParam245 = 1.0f + (sjv_t / sjv_f32_pi);
        sjf_array_f32_setat(sjt_parent56, sjt_functionParam244, sjt_functionParam245);
        sjt_parent57 = &_parent->datavert5x;
        sjt_functionParam246 = n;
        sjt_functionParam247 = (1.0f / 3.0f) + (((sjv_t / sjv_f32_pi) * 2.0f) / 3.0f);
        sjf_array_f32_setat(sjt_parent57, sjt_functionParam246, sjt_functionParam247);
        sjt_parent58 = &_parent->datavert5y;
        sjt_functionParam248 = n;
        sjt_functionParam249 = 1.0f + ((sjv_t / sjv_f32_pi) * 2.0f);
        sjf_array_f32_setat(sjt_parent58, sjt_functionParam248, sjt_functionParam249);
        sjt_parent59 = &_parent->datahotizont1x;
        sjt_functionParam250 = n;
        result10 = -3.5f;
        sjt_functionParam251 = result10 + (sjv_t / 7.0f);
        sjf_array_f32_setat(sjt_parent59, sjt_functionParam250, sjt_functionParam251);
        sjt_parent60 = &_parent->datahotizont1y;
        sjt_functionParam252 = n;
        result11 = -3.0f;
        sjt_functionParam253 = result11;
        sjf_array_f32_setat(sjt_parent60, sjt_functionParam252, sjt_functionParam253);
        sjt_parent61 = &_parent->datahotizont2x;
        sjt_functionParam254 = n;
        result12 = -1.0f;
        sjt_functionParam255 = (result12 - (1.0f / 3.0f)) + (sjv_t / sjv_f32_pi);
        sjf_array_f32_setat(sjt_parent61, sjt_functionParam254, sjt_functionParam255);
        sjt_parent62 = &_parent->datahotizont2y;
        sjt_functionParam256 = n;
        result13 = -1.0f;
        sjt_functionParam257 = result13;
        sjf_array_f32_setat(sjt_parent62, sjt_functionParam256, sjt_functionParam257);
        sjt_parent63 = &_parent->datahotizont3x;
        sjt_functionParam258 = n;
        result14 = -1.5f;
        sjt_functionParam259 = result14 + ((sjv_t / sjv_f32_pi) / 2.0f);
        sjf_array_f32_setat(sjt_parent63, sjt_functionParam258, sjt_functionParam259);
        sjt_parent64 = &_parent->datahotizont3y;
        sjt_functionParam260 = n;
        sjt_functionParam261 = 0.0f;
        sjf_array_f32_setat(sjt_parent64, sjt_functionParam260, sjt_functionParam261);
        sjt_parent65 = &_parent->datahotizont4x;
        sjt_functionParam262 = n;
        result15 = -0.8f;
        sjt_functionParam263 = result15 + ((sjv_t / sjv_f32_pi) / 2.0f);
        sjf_array_f32_setat(sjt_parent65, sjt_functionParam262, sjt_functionParam263);
        sjt_parent66 = &_parent->datahotizont4y;
        sjt_functionParam264 = n;
        sjt_functionParam265 = 2.0f;
        sjf_array_f32_setat(sjt_parent66, sjt_functionParam264, sjt_functionParam265);
        sjt_parent67 = &_parent->datahotizont5x;
        sjt_functionParam266 = n;
        result16 = -1.0f;
        sjt_functionParam267 = (result16 / 2.0f) + ((sjv_t / sjv_f32_pi) * (2.0f - (1.0f / 2.0f)));
        sjf_array_f32_setat(sjt_parent67, sjt_functionParam266, sjt_functionParam267);
        sjt_parent68 = &_parent->datahotizont5y;
        sjt_functionParam268 = n;
        sjt_functionParam269 = 3.0f;
        sjf_array_f32_setat(sjt_parent68, sjt_functionParam268, sjt_functionParam269);
        n++;
    }
}

void sjf_test_render(sjs_test* _parent, sjs_scene2d* scene) {
    bool sjt_while1;
    float sjv_r;

    sjf_test_calculate(_parent);
    sjf_test_findaxis(_parent);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -7.0f);
    sjv_r = 0.0f;
    sjt_while1 = sjv_r < 360.0f;
    while (sjt_while1) {
        int32_t n;
        int32_t sjt_forEnd20;
        int32_t sjt_forStart20;
        float sjt_functionParam348;
        float sjt_functionParam349;
        float sjt_functionParam350;
        float sjt_functionParam351;
        float sjt_functionParam352;
        float sjt_functionParam353;
        float sjt_functionParam354;

        if (_parent->rotatex > 0.0f) {
            sjt_functionParam348 = _parent->rotatex;
        } else {
            float result29;

            result29 = -1.0f;
            sjt_functionParam348 = (result29 * _parent->rotatex) / 14.0f;
        }

        if (_parent->rotatey > 0.0f) {
            sjt_functionParam349 = _parent->rotatey;
        } else {
            float result30;

            result30 = -1.0f;
            sjt_functionParam349 = (result30 * _parent->rotatey) / 14.0f;
        }

        if (_parent->rotatez > 0.0f) {
            sjt_functionParam350 = _parent->rotatez;
        } else {
            float result31;

            result31 = -1.0f;
            sjt_functionParam350 = (result31 * _parent->rotatez) / 14.0f;
        }

        sjf_glcolor3f(sjt_functionParam348, sjt_functionParam349, sjt_functionParam350);
        sjt_functionParam351 = sjv_r / (100.0f / sjv_rotateradius);
        sjt_functionParam352 = _parent->rotatex;
        sjt_functionParam353 = _parent->rotatey;
        sjt_functionParam354 = _parent->rotatez;
        sjf_glrotated(sjt_functionParam351, sjt_functionParam352, sjt_functionParam353, sjt_functionParam354);
        sjf_glbeginpoints();
        sjt_forStart20 = 0;
        sjt_forEnd20 = sjv_dots;
        n = sjt_forStart20;
        while (n < sjt_forEnd20) {
            if (_parent->funcid == 18) {
                if (n < sjv_img_dots) {
                    float sjt_capture100;
                    float sjt_capture101;
                    float sjt_capture102;
                    float sjt_capture103;
                    float sjt_capture104;
                    float sjt_capture105;
                    float sjt_capture106;
                    float sjt_capture107;
                    float sjt_capture108;
                    float sjt_capture109;
                    float sjt_capture110;
                    float sjt_capture111;
                    float sjt_capture112;
                    float sjt_capture113;
                    float sjt_capture114;
                    float sjt_capture115;
                    float sjt_capture116;
                    float sjt_capture117;
                    float sjt_capture118;
                    float sjt_capture119;
                    float sjt_capture120;
                    float sjt_capture121;
                    float sjt_capture122;
                    float sjt_capture123;
                    float sjt_capture124;
                    float sjt_capture125;
                    float sjt_capture86;
                    float sjt_capture87;
                    float sjt_capture88;
                    float sjt_capture89;
                    float sjt_capture90;
                    float sjt_capture91;
                    float sjt_capture92;
                    float sjt_capture93;
                    float sjt_capture94;
                    float sjt_capture95;
                    float sjt_capture96;
                    float sjt_capture97;
                    float sjt_capture98;
                    float sjt_capture99;
                    float sjt_functionParam355;
                    int32_t sjt_functionParam356;
                    float sjt_functionParam357;
                    int32_t sjt_functionParam358;
                    float sjt_functionParam359;
                    float sjt_functionParam360;
                    int32_t sjt_functionParam361;
                    float sjt_functionParam362;
                    int32_t sjt_functionParam363;
                    float sjt_functionParam364;
                    float sjt_functionParam365;
                    int32_t sjt_functionParam366;
                    float sjt_functionParam367;
                    int32_t sjt_functionParam368;
                    float sjt_functionParam369;
                    float sjt_functionParam370;
                    int32_t sjt_functionParam371;
                    float sjt_functionParam372;
                    int32_t sjt_functionParam373;
                    float sjt_functionParam374;
                    float sjt_functionParam375;
                    int32_t sjt_functionParam376;
                    float sjt_functionParam377;
                    int32_t sjt_functionParam378;
                    float sjt_functionParam379;
                    float sjt_functionParam380;
                    int32_t sjt_functionParam381;
                    float sjt_functionParam382;
                    int32_t sjt_functionParam383;
                    float sjt_functionParam384;
                    float sjt_functionParam385;
                    int32_t sjt_functionParam386;
                    float sjt_functionParam387;
                    int32_t sjt_functionParam388;
                    float sjt_functionParam389;
                    float sjt_functionParam390;
                    int32_t sjt_functionParam391;
                    float sjt_functionParam392;
                    int32_t sjt_functionParam393;
                    float sjt_functionParam394;
                    float sjt_functionParam395;
                    int32_t sjt_functionParam396;
                    float sjt_functionParam397;
                    int32_t sjt_functionParam398;
                    float sjt_functionParam399;
                    float sjt_functionParam400;
                    int32_t sjt_functionParam401;
                    float sjt_functionParam402;
                    int32_t sjt_functionParam403;
                    float sjt_functionParam404;
                    float sjt_functionParam405;
                    int32_t sjt_functionParam406;
                    float sjt_functionParam407;
                    int32_t sjt_functionParam408;
                    float sjt_functionParam409;
                    float sjt_functionParam410;
                    int32_t sjt_functionParam411;
                    float sjt_functionParam412;
                    int32_t sjt_functionParam413;
                    float sjt_functionParam414;
                    float sjt_functionParam415;
                    int32_t sjt_functionParam416;
                    float sjt_functionParam417;
                    int32_t sjt_functionParam418;
                    float sjt_functionParam419;
                    float sjt_functionParam420;
                    int32_t sjt_functionParam421;
                    float sjt_functionParam422;
                    int32_t sjt_functionParam423;
                    float sjt_functionParam424;
                    float sjt_functionParam425;
                    int32_t sjt_functionParam426;
                    float sjt_functionParam427;
                    int32_t sjt_functionParam428;
                    float sjt_functionParam429;
                    float sjt_functionParam430;
                    int32_t sjt_functionParam431;
                    float sjt_functionParam432;
                    int32_t sjt_functionParam433;
                    float sjt_functionParam434;
                    float sjt_functionParam435;
                    int32_t sjt_functionParam436;
                    float sjt_functionParam437;
                    int32_t sjt_functionParam438;
                    float sjt_functionParam439;
                    float sjt_functionParam440;
                    int32_t sjt_functionParam441;
                    float sjt_functionParam442;
                    int32_t sjt_functionParam443;
                    float sjt_functionParam444;
                    float sjt_functionParam445;
                    int32_t sjt_functionParam446;
                    float sjt_functionParam447;
                    int32_t sjt_functionParam448;
                    float sjt_functionParam449;
                    float sjt_functionParam450;
                    int32_t sjt_functionParam451;
                    float sjt_functionParam452;
                    int32_t sjt_functionParam453;
                    float sjt_functionParam454;
                    sjs_array_f32* sjt_parent121 = 0;
                    sjs_array_f32* sjt_parent122 = 0;
                    sjs_array_f32* sjt_parent123 = 0;
                    sjs_array_f32* sjt_parent124 = 0;
                    sjs_array_f32* sjt_parent125 = 0;
                    sjs_array_f32* sjt_parent126 = 0;
                    sjs_array_f32* sjt_parent127 = 0;
                    sjs_array_f32* sjt_parent128 = 0;
                    sjs_array_f32* sjt_parent129 = 0;
                    sjs_array_f32* sjt_parent130 = 0;
                    sjs_array_f32* sjt_parent131 = 0;
                    sjs_array_f32* sjt_parent132 = 0;
                    sjs_array_f32* sjt_parent133 = 0;
                    sjs_array_f32* sjt_parent134 = 0;
                    sjs_array_f32* sjt_parent135 = 0;
                    sjs_array_f32* sjt_parent136 = 0;
                    sjs_array_f32* sjt_parent137 = 0;
                    sjs_array_f32* sjt_parent138 = 0;
                    sjs_array_f32* sjt_parent139 = 0;
                    sjs_array_f32* sjt_parent140 = 0;
                    sjs_array_f32* sjt_parent141 = 0;
                    sjs_array_f32* sjt_parent142 = 0;
                    sjs_array_f32* sjt_parent143 = 0;
                    sjs_array_f32* sjt_parent144 = 0;
                    sjs_array_f32* sjt_parent145 = 0;
                    sjs_array_f32* sjt_parent146 = 0;
                    sjs_array_f32* sjt_parent147 = 0;
                    sjs_array_f32* sjt_parent148 = 0;
                    sjs_array_f32* sjt_parent149 = 0;
                    sjs_array_f32* sjt_parent150 = 0;
                    sjs_array_f32* sjt_parent151 = 0;
                    sjs_array_f32* sjt_parent152 = 0;
                    sjs_array_f32* sjt_parent153 = 0;
                    sjs_array_f32* sjt_parent154 = 0;
                    sjs_array_f32* sjt_parent155 = 0;
                    sjs_array_f32* sjt_parent156 = 0;
                    sjs_array_f32* sjt_parent157 = 0;
                    sjs_array_f32* sjt_parent158 = 0;
                    sjs_array_f32* sjt_parent159 = 0;
                    sjs_array_f32* sjt_parent160 = 0;

                    sjt_parent121 = &_parent->datahotizont1x;
                    sjt_functionParam356 = n;
                    sjf_array_f32_getat(sjt_parent121, sjt_functionParam356, &sjt_capture86);
                    sjt_functionParam355 = sjt_capture86 * sjv_scale;
                    sjt_parent122 = &_parent->datahotizont1y;
                    sjt_functionParam358 = n;
                    sjf_array_f32_getat(sjt_parent122, sjt_functionParam358, &sjt_capture87);
                    sjt_functionParam357 = sjt_capture87 * sjv_scale;
                    sjt_functionParam359 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam355, sjt_functionParam357, sjt_functionParam359);
                    sjt_parent123 = &_parent->datahotizont2x;
                    sjt_functionParam361 = n;
                    sjf_array_f32_getat(sjt_parent123, sjt_functionParam361, &sjt_capture88);
                    sjt_functionParam360 = sjt_capture88 * sjv_scale;
                    sjt_parent124 = &_parent->datahotizont2y;
                    sjt_functionParam363 = n;
                    sjf_array_f32_getat(sjt_parent124, sjt_functionParam363, &sjt_capture89);
                    sjt_functionParam362 = sjt_capture89 * sjv_scale;
                    sjt_functionParam364 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam360, sjt_functionParam362, sjt_functionParam364);
                    sjt_parent125 = &_parent->datahotizont3x;
                    sjt_functionParam366 = n;
                    sjf_array_f32_getat(sjt_parent125, sjt_functionParam366, &sjt_capture90);
                    sjt_functionParam365 = sjt_capture90 * sjv_scale;
                    sjt_parent126 = &_parent->datahotizont3y;
                    sjt_functionParam368 = n;
                    sjf_array_f32_getat(sjt_parent126, sjt_functionParam368, &sjt_capture91);
                    sjt_functionParam367 = sjt_capture91 * sjv_scale;
                    sjt_functionParam369 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam365, sjt_functionParam367, sjt_functionParam369);
                    sjt_parent127 = &_parent->datahotizont4x;
                    sjt_functionParam371 = n;
                    sjf_array_f32_getat(sjt_parent127, sjt_functionParam371, &sjt_capture92);
                    sjt_functionParam370 = sjt_capture92 * sjv_scale;
                    sjt_parent128 = &_parent->datahotizont4y;
                    sjt_functionParam373 = n;
                    sjf_array_f32_getat(sjt_parent128, sjt_functionParam373, &sjt_capture93);
                    sjt_functionParam372 = sjt_capture93 * sjv_scale;
                    sjt_functionParam374 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam370, sjt_functionParam372, sjt_functionParam374);
                    sjt_parent129 = &_parent->datahotizont5x;
                    sjt_functionParam376 = n;
                    sjf_array_f32_getat(sjt_parent129, sjt_functionParam376, &sjt_capture94);
                    sjt_functionParam375 = sjt_capture94 * sjv_scale;
                    sjt_parent130 = &_parent->datahotizont5y;
                    sjt_functionParam378 = n;
                    sjf_array_f32_getat(sjt_parent130, sjt_functionParam378, &sjt_capture95);
                    sjt_functionParam377 = sjt_capture95 * sjv_scale;
                    sjt_functionParam379 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam375, sjt_functionParam377, sjt_functionParam379);
                    sjt_parent131 = &_parent->datavert1x;
                    sjt_functionParam381 = n;
                    sjf_array_f32_getat(sjt_parent131, sjt_functionParam381, &sjt_capture96);
                    sjt_functionParam380 = sjt_capture96 * sjv_scale;
                    sjt_parent132 = &_parent->datavert1y;
                    sjt_functionParam383 = n;
                    sjf_array_f32_getat(sjt_parent132, sjt_functionParam383, &sjt_capture97);
                    sjt_functionParam382 = sjt_capture97 * sjv_scale;
                    sjt_functionParam384 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam380, sjt_functionParam382, sjt_functionParam384);
                    sjt_parent133 = &_parent->datavert2x;
                    sjt_functionParam386 = n;
                    sjf_array_f32_getat(sjt_parent133, sjt_functionParam386, &sjt_capture98);
                    sjt_functionParam385 = sjt_capture98 * sjv_scale;
                    sjt_parent134 = &_parent->datavert2y;
                    sjt_functionParam388 = n;
                    sjf_array_f32_getat(sjt_parent134, sjt_functionParam388, &sjt_capture99);
                    sjt_functionParam387 = sjt_capture99 * sjv_scale;
                    sjt_functionParam389 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam385, sjt_functionParam387, sjt_functionParam389);
                    sjt_parent135 = &_parent->datavert3x;
                    sjt_functionParam391 = n;
                    sjf_array_f32_getat(sjt_parent135, sjt_functionParam391, &sjt_capture100);
                    sjt_functionParam390 = sjt_capture100 * sjv_scale;
                    sjt_parent136 = &_parent->datavert3y;
                    sjt_functionParam393 = n;
                    sjf_array_f32_getat(sjt_parent136, sjt_functionParam393, &sjt_capture101);
                    sjt_functionParam392 = sjt_capture101 * sjv_scale;
                    sjt_functionParam394 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam390, sjt_functionParam392, sjt_functionParam394);
                    sjt_parent137 = &_parent->datavert4x;
                    sjt_functionParam396 = n;
                    sjf_array_f32_getat(sjt_parent137, sjt_functionParam396, &sjt_capture102);
                    sjt_functionParam395 = sjt_capture102 * sjv_scale;
                    sjt_parent138 = &_parent->datavert4y;
                    sjt_functionParam398 = n;
                    sjf_array_f32_getat(sjt_parent138, sjt_functionParam398, &sjt_capture103);
                    sjt_functionParam397 = sjt_capture103 * sjv_scale;
                    sjt_functionParam399 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam395, sjt_functionParam397, sjt_functionParam399);
                    sjt_parent139 = &_parent->datavert5x;
                    sjt_functionParam401 = n;
                    sjf_array_f32_getat(sjt_parent139, sjt_functionParam401, &sjt_capture104);
                    sjt_functionParam400 = sjt_capture104 * sjv_scale;
                    sjt_parent140 = &_parent->datavert5y;
                    sjt_functionParam403 = n;
                    sjf_array_f32_getat(sjt_parent140, sjt_functionParam403, &sjt_capture105);
                    sjt_functionParam402 = sjt_capture105 * sjv_scale;
                    sjt_functionParam404 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam400, sjt_functionParam402, sjt_functionParam404);
                    sjt_parent141 = &_parent->datahotizont1x;
                    sjt_functionParam406 = n;
                    sjf_array_f32_getat(sjt_parent141, sjt_functionParam406, &sjt_capture106);
                    sjt_functionParam405 = ((sjt_capture106 * sjv_scale) + 4.35f) + (1.0f / 3.0f);
                    sjt_parent142 = &_parent->datahotizont1y;
                    sjt_functionParam408 = n;
                    sjf_array_f32_getat(sjt_parent142, sjt_functionParam408, &sjt_capture107);
                    sjt_functionParam407 = (sjt_capture107 * sjv_scale) + 3.8f;
                    sjt_functionParam409 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam405, sjt_functionParam407, sjt_functionParam409);
                    sjt_parent143 = &_parent->datahotizont2x;
                    sjt_functionParam411 = n;
                    sjf_array_f32_getat(sjt_parent143, sjt_functionParam411, &sjt_capture108);
                    sjt_functionParam410 = ((sjt_capture108 * sjv_scale) + 2.18f) + (1.0f / 3.0f);
                    sjt_parent144 = &_parent->datahotizont2y;
                    sjt_functionParam413 = n;
                    sjf_array_f32_getat(sjt_parent144, sjt_functionParam413, &sjt_capture109);
                    sjt_functionParam412 = (sjt_capture109 * sjv_scale) + 1.8f;
                    sjt_functionParam414 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam410, sjt_functionParam412, sjt_functionParam414);
                    sjt_parent145 = &_parent->datahotizont3x;
                    sjt_functionParam416 = n;
                    sjf_array_f32_getat(sjt_parent145, sjt_functionParam416, &sjt_capture110);
                    sjt_functionParam415 = ((sjt_capture110 * sjv_scale) + 2.34f) + (1.0f / 3.0f);
                    sjt_parent146 = &_parent->datahotizont3y;
                    sjt_functionParam418 = n;
                    sjf_array_f32_getat(sjt_parent146, sjt_functionParam418, &sjt_capture111);
                    sjt_functionParam417 = (sjt_capture111 * sjv_scale) + 0.8f;
                    sjt_functionParam419 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam415, sjt_functionParam417, sjt_functionParam419);
                    sjt_parent147 = &_parent->datahotizont4x;
                    sjt_functionParam421 = n;
                    sjf_array_f32_getat(sjt_parent147, sjt_functionParam421, &sjt_capture112);
                    sjt_functionParam420 = ((sjt_capture112 * sjv_scale) + 1.65f) + (1.0f / 3.0f);
                    sjt_parent148 = &_parent->datahotizont4y;
                    sjt_functionParam423 = n;
                    sjf_array_f32_getat(sjt_parent148, sjt_functionParam423, &sjt_capture113);
                    sjt_functionParam422 = (sjt_capture113 * sjv_scale) - 1.2f;
                    sjt_functionParam424 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam420, sjt_functionParam422, sjt_functionParam424);
                    sjt_parent149 = &_parent->datahotizont5x;
                    sjt_functionParam426 = n;
                    sjf_array_f32_getat(sjt_parent149, sjt_functionParam426, &sjt_capture114);
                    sjt_functionParam425 = ((sjt_capture114 * sjv_scale) + 1.35f) + (1.0f / 3.0f);
                    sjt_parent150 = &_parent->datahotizont5y;
                    sjt_functionParam428 = n;
                    sjf_array_f32_getat(sjt_parent150, sjt_functionParam428, &sjt_capture115);
                    sjt_functionParam427 = (sjt_capture115 * sjv_scale) - 2.2f;
                    sjt_functionParam429 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam425, sjt_functionParam427, sjt_functionParam429);
                    sjt_parent151 = &_parent->datavert1x;
                    sjt_functionParam431 = n;
                    sjf_array_f32_getat(sjt_parent151, sjt_functionParam431, &sjt_capture116);
                    sjt_functionParam430 = ((sjt_capture116 * sjv_scale) + 4.005f) + (1.0f / 6.0f);
                    sjt_parent152 = &_parent->datavert1y;
                    sjt_functionParam433 = n;
                    sjf_array_f32_getat(sjt_parent152, sjt_functionParam433, &sjt_capture117);
                    sjt_functionParam432 = (sjt_capture117 * sjv_scale) + 0.8f;
                    sjt_functionParam434 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam430, sjt_functionParam432, sjt_functionParam434);
                    sjt_parent153 = &_parent->datavert2x;
                    sjt_functionParam436 = n;
                    sjf_array_f32_getat(sjt_parent153, sjt_functionParam436, &sjt_capture118);
                    sjt_functionParam435 = ((sjt_capture118 * sjv_scale) + 4.05f) - (1.0f / 6.0f);
                    sjt_parent154 = &_parent->datavert2y;
                    sjt_functionParam438 = n;
                    sjf_array_f32_getat(sjt_parent154, sjt_functionParam438, &sjt_capture119);
                    sjt_functionParam437 = (sjt_capture119 * sjv_scale) + 2.8f;
                    sjt_functionParam439 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam435, sjt_functionParam437, sjt_functionParam439);
                    sjt_parent155 = &_parent->datavert3x;
                    sjt_functionParam441 = n;
                    sjf_array_f32_getat(sjt_parent155, sjt_functionParam441, &sjt_capture120);
                    sjt_functionParam440 = ((sjt_capture120 * sjv_scale) + 3.0f) - (1.0f / 6.0f);
                    sjt_parent156 = &_parent->datavert3y;
                    sjt_functionParam443 = n;
                    sjf_array_f32_getat(sjt_parent156, sjt_functionParam443, &sjt_capture121);
                    sjt_functionParam442 = (sjt_capture121 * sjv_scale) - 0.2f;
                    sjt_functionParam444 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam440, sjt_functionParam442, sjt_functionParam444);
                    sjt_parent157 = &_parent->datavert4x;
                    sjt_functionParam446 = n;
                    sjf_array_f32_getat(sjt_parent157, sjt_functionParam446, &sjt_capture122);
                    sjt_functionParam445 = ((sjt_capture122 * sjv_scale) + 2.0f) - (1.0f / 6.0f);
                    sjt_parent158 = &_parent->datavert4y;
                    sjt_functionParam448 = n;
                    sjf_array_f32_getat(sjt_parent158, sjt_functionParam448, &sjt_capture123);
                    sjt_functionParam447 = (sjt_capture123 * sjv_scale) - 0.2f;
                    sjt_functionParam449 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam445, sjt_functionParam447, sjt_functionParam449);
                    sjt_parent159 = &_parent->datavert5x;
                    sjt_functionParam451 = n;
                    sjf_array_f32_getat(sjt_parent159, sjt_functionParam451, &sjt_capture124);
                    sjt_functionParam450 = ((sjt_capture124 * sjv_scale) + 1.0f) - (1.0f / 6.0f);
                    sjt_parent160 = &_parent->datavert5y;
                    sjt_functionParam453 = n;
                    sjf_array_f32_getat(sjt_parent160, sjt_functionParam453, &sjt_capture125);
                    sjt_functionParam452 = (sjt_capture125 * sjv_scale) - 0.2f;
                    sjt_functionParam454 = 0.0f;
                    sjf_glvertex3f(sjt_functionParam450, sjt_functionParam452, sjt_functionParam454);
                }
            } else {
                float sjt_capture126;
                float sjt_capture127;
                float sjt_functionParam455;
                int32_t sjt_functionParam456;
                float sjt_functionParam457;
                int32_t sjt_functionParam458;
                float sjt_functionParam459;
                sjs_array_f32* sjt_parent161 = 0;
                sjs_array_f32* sjt_parent162 = 0;

                sjt_parent161 = &_parent->datax;
                sjt_functionParam456 = n;
                sjf_array_f32_getat(sjt_parent161, sjt_functionParam456, &sjt_capture126);
                sjt_functionParam455 = sjt_capture126 * sjv_scale;
                sjt_parent162 = &_parent->datay;
                sjt_functionParam458 = n;
                sjf_array_f32_getat(sjt_parent162, sjt_functionParam458, &sjt_capture127);
                sjt_functionParam457 = sjt_capture127 * sjv_scale;
                sjt_functionParam459 = 0.0f;
                sjf_glvertex3f(sjt_functionParam455, sjt_functionParam457, sjt_functionParam459);
            }

            n++;
        }

        sjf_glend();
        sjv_r = sjv_r + sjv_rotateradius;
        sjt_while1 = sjv_r < 360.0f;
    }
}

void sjf_test_setrect(sjs_test* _parent, sjs_rect* rect_) {
    bool result3;
    bool sjt_capture4;
    sjs_rect* sjt_functionParam28 = 0;
    sjs_rect* sjt_parent12 = 0;

    sjt_parent12 = &_parent->_rect;
    sjt_functionParam28 = rect_;
    sjf_rect_isequal(sjt_parent12, sjt_functionParam28, &sjt_capture4);
    result3 = !sjt_capture4;
    if (result3) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
        _parent->_rect._refCount = 1;
        sjf_rect_copy(&_parent->_rect, rect_);
        glEnable(GL_LIGHTING);
        // glLightModelfv(GL_LIGHT_MODEL_AMBIENT, &sjv_a_light.x);
        // glLightfv(GL_LIGHT0, GL_DIFFUSE, &sjv_s_light.x);
        // glLightfv(GL_LIGHT0, GL_POSITION, &sjv_l_pos.x);
        glEnable(GL_LIGHT0);
        glEnable(GL_COLOR_MATERIAL);
        //glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
        glEnable(GL_BLEND);
        glEnable(GL_CULL_FACE);    
        glBlendFunc(GL_ONE, GL_ONE);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();        
        gluPerspective(sjv_persp, (GLfloat) 1920 / (GLfloat) 1080, 0.1f, 100.0f);
        glMatrixMode(GL_MODELVIEW);
    }
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

void sjf_windowrender_disablevsync(void) {
    SDL_GL_SetSwapInterval(0);
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

void sjf_windowrenderer_setsize(sjs_windowrenderer* _parent, sjs_size* s) {
    SDL_SetWindowSize(_parent->win, s->w, s->h);
}

int main(int argc, char** argv) {
    sjs_test_element_vtbl.destroy = (void(*)(void*))sjf_test_destroy;
    sjs_test_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_test_asinterface;
    sjs_test_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_test_getclasstype;
    sjs_test_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_test_getsize;
    sjs_test_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_test_getsize_heap;
    sjs_test_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_test_getrect;
    sjs_test_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_test_getrect_heap;
    sjs_test_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_test_setrect;
    sjs_test_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_test_render;
    sjs_test_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_test_firemouseevent;
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
    sjv_log._refCount = 1;
    sjv_log.minlevel = sjv_loglevel_warn;
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
    sjv_a_light._refCount = 1;
    sjv_a_light.x = 0.2f;
    sjv_a_light.y = 0.2f;
    sjv_a_light.z = 0.2f;
    sjv_a_light.w = 1.0f;
    sjf_vec4(&sjv_a_light);
    sjv_s_light._refCount = 1;
    sjv_s_light.x = 0.9f;
    sjv_s_light.y = 0.8f;
    sjv_s_light.z = 0.8f;
    sjv_s_light.w = 1.0f;
    sjf_vec4(&sjv_s_light);
    sjv_l_pos._refCount = 1;
    result2 = -0.005f;
    sjv_l_pos.x = result2;
    sjv_l_pos.y = 0.0005f;
    sjv_l_pos.z = 0.0f;
    sjv_l_pos.w = 0.0f;
    sjf_vec4(&sjv_l_pos);
    sjv_width = 1920;
    sjv_height = 1080;
    sjv_oncept = 0;
    sjv_dotsscale = 4000;
    sjt_cast2 = sjv_dotsscale;
    sjt_cast1 = sjv_f32_pi * (float)sjt_cast2;
    sjv_dots = (int32_t)sjt_cast1;
    sjv_rotateradius = 1.0f;
    sjv_persp = 45.0f;
    sjv_stateof._refCount = 1;
    sjv_stateof.datasize = 3;
    sjv_stateof.data = 0;
    sjv_stateof.isglobal = false;
    sjv_stateof.count = 0;
    sjf_array_bool(&sjv_stateof);
    sjs_array_bool* array1;
    array1 = &sjv_stateof;
    sjt_parent4 = array1;
    sjt_functionParam12 = 0;
    sjt_functionParam13 = true;
    sjf_array_bool_initat(sjt_parent4, sjt_functionParam12, sjt_functionParam13);
    sjt_parent5 = array1;
    sjt_functionParam14 = 1;
    sjt_functionParam15 = true;
    sjf_array_bool_initat(sjt_parent5, sjt_functionParam14, sjt_functionParam15);
    sjt_parent6 = array1;
    sjt_functionParam16 = 2;
    sjt_functionParam17 = true;
    sjf_array_bool_initat(sjt_parent6, sjt_functionParam16, sjt_functionParam17);
    sjv_stateofdir._refCount = 1;
    sjv_stateofdir.datasize = 3;
    sjv_stateofdir.data = 0;
    sjv_stateofdir.isglobal = false;
    sjv_stateofdir.count = 0;
    sjf_array_bool(&sjv_stateofdir);
    sjs_array_bool* array2;
    array2 = &sjv_stateofdir;
    sjt_parent7 = array2;
    sjt_functionParam18 = 0;
    sjt_functionParam19 = true;
    sjf_array_bool_initat(sjt_parent7, sjt_functionParam18, sjt_functionParam19);
    sjt_parent8 = array2;
    sjt_functionParam20 = 1;
    sjt_functionParam21 = true;
    sjf_array_bool_initat(sjt_parent8, sjt_functionParam20, sjt_functionParam21);
    sjt_parent9 = array2;
    sjt_functionParam22 = 2;
    sjt_functionParam23 = true;
    sjf_array_bool_initat(sjt_parent9, sjt_functionParam22, sjt_functionParam23);
    sjv_mainrot._refCount = 1;
    sjv_mainrot.datasize = 2;
    sjv_mainrot.data = 0;
    sjv_mainrot.isglobal = false;
    sjv_mainrot.count = 0;
    sjf_array_bool(&sjv_mainrot);
    sjs_array_bool* array3;
    array3 = &sjv_mainrot;
    sjt_parent10 = array3;
    sjt_functionParam24 = 0;
    sjt_functionParam25 = false;
    sjf_array_bool_initat(sjt_parent10, sjt_functionParam24, sjt_functionParam25);
    sjt_parent11 = array3;
    sjt_functionParam26 = 1;
    sjt_functionParam27 = false;
    sjf_array_bool_initat(sjt_parent11, sjt_functionParam26, sjt_functionParam27);
    sjv_scale = 0.5f;
    sjv_img_dotsscale = 100;
    sjt_cast4 = sjv_img_dotsscale;
    sjt_cast3 = sjv_f32_pi * (float)sjt_cast4;
    sjv_img_dots = (int32_t)sjt_cast3;
    sjt_call3._refCount = 1;
    sjt_call3.funcid = 0;
    sjt_call3.lastfuncid = 0;
    sjt_call4._refCount = 1;
    sjt_call4.datasize = sjv_dots;
    sjt_call4.data = 0;
    sjt_call4.isglobal = false;
    sjt_call4.count = 0;
    sjf_array_f32(&sjt_call4);
    sjt_parent163 = &sjt_call4;
    sjt_functionParam460 = 0.0f;
    sjf_array_f32_init(sjt_parent163, sjt_functionParam460, &sjt_call3.datax);
    sjt_call5._refCount = 1;
    sjt_call5.datasize = sjv_dots;
    sjt_call5.data = 0;
    sjt_call5.isglobal = false;
    sjt_call5.count = 0;
    sjf_array_f32(&sjt_call5);
    sjt_parent164 = &sjt_call5;
    sjt_functionParam461 = 0.0f;
    sjf_array_f32_init(sjt_parent164, sjt_functionParam461, &sjt_call3.datay);
    sjt_call3.rotatex = 0.0f;
    sjt_call3.rotatey = 0.0f;
    sjt_call3.rotatez = 0.0f;
    sjt_call6._refCount = 1;
    sjt_call6.datasize = sjv_img_dots;
    sjt_call6.data = 0;
    sjt_call6.isglobal = false;
    sjt_call6.count = 0;
    sjf_array_f32(&sjt_call6);
    sjt_parent165 = &sjt_call6;
    sjt_functionParam462 = 0.0f;
    sjf_array_f32_init(sjt_parent165, sjt_functionParam462, &sjt_call3.datavert1x);
    sjt_call7._refCount = 1;
    sjt_call7.datasize = sjv_img_dots;
    sjt_call7.data = 0;
    sjt_call7.isglobal = false;
    sjt_call7.count = 0;
    sjf_array_f32(&sjt_call7);
    sjt_parent166 = &sjt_call7;
    sjt_functionParam463 = 0.0f;
    sjf_array_f32_init(sjt_parent166, sjt_functionParam463, &sjt_call3.datavert1y);
    sjt_call8._refCount = 1;
    sjt_call8.datasize = sjv_img_dots;
    sjt_call8.data = 0;
    sjt_call8.isglobal = false;
    sjt_call8.count = 0;
    sjf_array_f32(&sjt_call8);
    sjt_parent167 = &sjt_call8;
    sjt_functionParam464 = 0.0f;
    sjf_array_f32_init(sjt_parent167, sjt_functionParam464, &sjt_call3.datavert2x);
    sjt_call9._refCount = 1;
    sjt_call9.datasize = sjv_img_dots;
    sjt_call9.data = 0;
    sjt_call9.isglobal = false;
    sjt_call9.count = 0;
    sjf_array_f32(&sjt_call9);
    sjt_parent168 = &sjt_call9;
    sjt_functionParam465 = 0.0f;
    sjf_array_f32_init(sjt_parent168, sjt_functionParam465, &sjt_call3.datavert2y);
    sjt_call10._refCount = 1;
    sjt_call10.datasize = sjv_img_dots;
    sjt_call10.data = 0;
    sjt_call10.isglobal = false;
    sjt_call10.count = 0;
    sjf_array_f32(&sjt_call10);
    sjt_parent169 = &sjt_call10;
    sjt_functionParam466 = 0.0f;
    sjf_array_f32_init(sjt_parent169, sjt_functionParam466, &sjt_call3.datavert3x);
    sjt_call11._refCount = 1;
    sjt_call11.datasize = sjv_img_dots;
    sjt_call11.data = 0;
    sjt_call11.isglobal = false;
    sjt_call11.count = 0;
    sjf_array_f32(&sjt_call11);
    sjt_parent170 = &sjt_call11;
    sjt_functionParam467 = 0.0f;
    sjf_array_f32_init(sjt_parent170, sjt_functionParam467, &sjt_call3.datavert3y);
    sjt_call12._refCount = 1;
    sjt_call12.datasize = sjv_img_dots;
    sjt_call12.data = 0;
    sjt_call12.isglobal = false;
    sjt_call12.count = 0;
    sjf_array_f32(&sjt_call12);
    sjt_parent171 = &sjt_call12;
    sjt_functionParam468 = 0.0f;
    sjf_array_f32_init(sjt_parent171, sjt_functionParam468, &sjt_call3.datavert4x);
    sjt_call13._refCount = 1;
    sjt_call13.datasize = sjv_img_dots;
    sjt_call13.data = 0;
    sjt_call13.isglobal = false;
    sjt_call13.count = 0;
    sjf_array_f32(&sjt_call13);
    sjt_parent172 = &sjt_call13;
    sjt_functionParam469 = 0.0f;
    sjf_array_f32_init(sjt_parent172, sjt_functionParam469, &sjt_call3.datavert4y);
    sjt_call14._refCount = 1;
    sjt_call14.datasize = sjv_img_dots;
    sjt_call14.data = 0;
    sjt_call14.isglobal = false;
    sjt_call14.count = 0;
    sjf_array_f32(&sjt_call14);
    sjt_parent173 = &sjt_call14;
    sjt_functionParam470 = 0.0f;
    sjf_array_f32_init(sjt_parent173, sjt_functionParam470, &sjt_call3.datavert5x);
    sjt_call15._refCount = 1;
    sjt_call15.datasize = sjv_img_dots;
    sjt_call15.data = 0;
    sjt_call15.isglobal = false;
    sjt_call15.count = 0;
    sjf_array_f32(&sjt_call15);
    sjt_parent174 = &sjt_call15;
    sjt_functionParam471 = 0.0f;
    sjf_array_f32_init(sjt_parent174, sjt_functionParam471, &sjt_call3.datavert5y);
    sjt_call16._refCount = 1;
    sjt_call16.datasize = sjv_img_dots;
    sjt_call16.data = 0;
    sjt_call16.isglobal = false;
    sjt_call16.count = 0;
    sjf_array_f32(&sjt_call16);
    sjt_parent175 = &sjt_call16;
    sjt_functionParam472 = 0.0f;
    sjf_array_f32_init(sjt_parent175, sjt_functionParam472, &sjt_call3.datahotizont1x);
    sjt_call17._refCount = 1;
    sjt_call17.datasize = sjv_img_dots;
    sjt_call17.data = 0;
    sjt_call17.isglobal = false;
    sjt_call17.count = 0;
    sjf_array_f32(&sjt_call17);
    sjt_parent176 = &sjt_call17;
    sjt_functionParam473 = 0.0f;
    sjf_array_f32_init(sjt_parent176, sjt_functionParam473, &sjt_call3.datahotizont1y);
    sjt_call18._refCount = 1;
    sjt_call18.datasize = sjv_img_dots;
    sjt_call18.data = 0;
    sjt_call18.isglobal = false;
    sjt_call18.count = 0;
    sjf_array_f32(&sjt_call18);
    sjt_parent177 = &sjt_call18;
    sjt_functionParam474 = 0.0f;
    sjf_array_f32_init(sjt_parent177, sjt_functionParam474, &sjt_call3.datahotizont2x);
    sjt_call19._refCount = 1;
    sjt_call19.datasize = sjv_img_dots;
    sjt_call19.data = 0;
    sjt_call19.isglobal = false;
    sjt_call19.count = 0;
    sjf_array_f32(&sjt_call19);
    sjt_parent178 = &sjt_call19;
    sjt_functionParam475 = 0.0f;
    sjf_array_f32_init(sjt_parent178, sjt_functionParam475, &sjt_call3.datahotizont2y);
    sjt_call20._refCount = 1;
    sjt_call20.datasize = sjv_img_dots;
    sjt_call20.data = 0;
    sjt_call20.isglobal = false;
    sjt_call20.count = 0;
    sjf_array_f32(&sjt_call20);
    sjt_parent179 = &sjt_call20;
    sjt_functionParam476 = 0.0f;
    sjf_array_f32_init(sjt_parent179, sjt_functionParam476, &sjt_call3.datahotizont3x);
    sjt_call21._refCount = 1;
    sjt_call21.datasize = sjv_img_dots;
    sjt_call21.data = 0;
    sjt_call21.isglobal = false;
    sjt_call21.count = 0;
    sjf_array_f32(&sjt_call21);
    sjt_parent180 = &sjt_call21;
    sjt_functionParam477 = 0.0f;
    sjf_array_f32_init(sjt_parent180, sjt_functionParam477, &sjt_call3.datahotizont3y);
    sjt_call22._refCount = 1;
    sjt_call22.datasize = sjv_img_dots;
    sjt_call22.data = 0;
    sjt_call22.isglobal = false;
    sjt_call22.count = 0;
    sjf_array_f32(&sjt_call22);
    sjt_parent181 = &sjt_call22;
    sjt_functionParam478 = 0.0f;
    sjf_array_f32_init(sjt_parent181, sjt_functionParam478, &sjt_call3.datahotizont4x);
    sjt_call23._refCount = 1;
    sjt_call23.datasize = sjv_img_dots;
    sjt_call23.data = 0;
    sjt_call23.isglobal = false;
    sjt_call23.count = 0;
    sjf_array_f32(&sjt_call23);
    sjt_parent182 = &sjt_call23;
    sjt_functionParam479 = 0.0f;
    sjf_array_f32_init(sjt_parent182, sjt_functionParam479, &sjt_call3.datahotizont4y);
    sjt_call24._refCount = 1;
    sjt_call24.datasize = sjv_img_dots;
    sjt_call24.data = 0;
    sjt_call24.isglobal = false;
    sjt_call24.count = 0;
    sjf_array_f32(&sjt_call24);
    sjt_parent183 = &sjt_call24;
    sjt_functionParam480 = 0.0f;
    sjf_array_f32_init(sjt_parent183, sjt_functionParam480, &sjt_call3.datahotizont5x);
    sjt_call25._refCount = 1;
    sjt_call25.datasize = sjv_img_dots;
    sjt_call25.data = 0;
    sjt_call25.isglobal = false;
    sjt_call25.count = 0;
    sjf_array_f32(&sjt_call25);
    sjt_parent184 = &sjt_call25;
    sjt_functionParam481 = 0.0f;
    sjf_array_f32_init(sjt_parent184, sjt_functionParam481, &sjt_call3.datahotizont5y);
    sjt_call3._rect._refCount = 1;
    sjt_call3._rect.x = 0;
    sjt_call3._rect.y = 0;
    sjt_call3._rect.w = 0;
    sjt_call3._rect.h = 0;
    sjf_rect(&sjt_call3._rect);
    sjf_test(&sjt_call3);
    sjt_cast5 = &sjt_call3;
    sjf_test_as_sji_element(sjt_cast5, &sjv_root);
    sjv_mainloop_showfps = true;
    sjf_windowrender_disablevsync();
    sjt_parent185 = &sjv_rootwindowrenderer;
    sjt_call26._refCount = 1;
    sjt_call26.w = 1920;
    sjt_call26.h = 1080;
    sjf_size(&sjt_call26);
    sjt_functionParam482 = &sjt_call26;
    sjf_windowrenderer_setsize(sjt_parent185, sjt_functionParam482);
    sjf_runloop();
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjv_mouse_captureelement._parent != 0) {
        sjv_mouse_captureelement._parent->_refCount--;
        if (sjv_mouse_captureelement._parent->_refCount <= 0) {
            sjv_mouse_captureelement._vtbl->destroy(sjv_mouse_captureelement._parent);
            free(sjv_mouse_captureelement._parent);
        }
    }
    if (sjt_call10._refCount == 1) { sjf_array_f32_destroy(&sjt_call10); }
;
    if (sjt_call11._refCount == 1) { sjf_array_f32_destroy(&sjt_call11); }
;
    if (sjt_call12._refCount == 1) { sjf_array_f32_destroy(&sjt_call12); }
;
    if (sjt_call13._refCount == 1) { sjf_array_f32_destroy(&sjt_call13); }
;
    if (sjt_call14._refCount == 1) { sjf_array_f32_destroy(&sjt_call14); }
;
    if (sjt_call15._refCount == 1) { sjf_array_f32_destroy(&sjt_call15); }
;
    if (sjt_call16._refCount == 1) { sjf_array_f32_destroy(&sjt_call16); }
;
    if (sjt_call17._refCount == 1) { sjf_array_f32_destroy(&sjt_call17); }
;
    if (sjt_call18._refCount == 1) { sjf_array_f32_destroy(&sjt_call18); }
;
    if (sjt_call19._refCount == 1) { sjf_array_f32_destroy(&sjt_call19); }
;
    if (sjt_call20._refCount == 1) { sjf_array_f32_destroy(&sjt_call20); }
;
    if (sjt_call21._refCount == 1) { sjf_array_f32_destroy(&sjt_call21); }
;
    if (sjt_call22._refCount == 1) { sjf_array_f32_destroy(&sjt_call22); }
;
    if (sjt_call23._refCount == 1) { sjf_array_f32_destroy(&sjt_call23); }
;
    if (sjt_call24._refCount == 1) { sjf_array_f32_destroy(&sjt_call24); }
;
    if (sjt_call25._refCount == 1) { sjf_array_f32_destroy(&sjt_call25); }
;
    if (sjt_call26._refCount == 1) { sjf_size_destroy(&sjt_call26); }
;
    if (sjt_call3._refCount == 1) { sjf_test_destroy(&sjt_call3); }
;
    if (sjt_call4._refCount == 1) { sjf_array_f32_destroy(&sjt_call4); }
;
    if (sjt_call5._refCount == 1) { sjf_array_f32_destroy(&sjt_call5); }
;
    if (sjt_call6._refCount == 1) { sjf_array_f32_destroy(&sjt_call6); }
;
    if (sjt_call7._refCount == 1) { sjf_array_f32_destroy(&sjt_call7); }
;
    if (sjt_call8._refCount == 1) { sjf_array_f32_destroy(&sjt_call8); }
;
    if (sjt_call9._refCount == 1) { sjf_array_f32_destroy(&sjt_call9); }
;
    if (sjv_a_light._refCount == 1) { sjf_vec4_destroy(&sjv_a_light); }
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
    if (sjv_l_pos._refCount == 1) { sjf_vec4_destroy(&sjv_l_pos); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_looplastrect._refCount == 1) { sjf_rect_destroy(&sjv_looplastrect); }
;
    if (sjv_mainrot._refCount == 1) { sjf_array_bool_destroy(&sjv_mainrot); }
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
    if (sjv_s_light._refCount == 1) { sjf_vec4_destroy(&sjv_s_light); }
;
    if (sjv_saturateshader._refCount == 1) { sjf_shader_destroy(&sjv_saturateshader); }
;
    if (sjv_stateof._refCount == 1) { sjf_array_bool_destroy(&sjv_stateof); }
;
    if (sjv_stateofdir._refCount == 1) { sjf_array_bool_destroy(&sjv_stateofdir); }
;
    if (sjv_style._refCount == 1) { sjf_style_destroy(&sjv_style); }
;
    if (sjv_textshader._refCount == 1) { sjf_shader_destroy(&sjv_textshader); }
;
    if (sjv_vertex_location_texture_normal_format._refCount == 1) { sjf_string_destroy(&sjv_vertex_location_texture_normal_format); }
;
}
