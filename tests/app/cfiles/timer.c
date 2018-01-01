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
const char* sjg_string100 = "bool_asstring";
const char* sjg_string101 = "boxrenderer";
const char* sjg_string102 = "render";
const char* sjg_string103 = "char_touppercase";
const char* sjg_string104 = "color";
const char* sjg_string105 = "asvec3";
const char* sjg_string106 = "crosshairselement";
const char* sjg_string107 = "firemouseevent";
const char* sjg_string108 = "getrect";
const char* sjg_string109 = "getsize";
const char* sjg_string11 = "shaders/v3f-t2f-n3f-phong.frag";
const char* sjg_string110 = "setrect";
const char* sjg_string111 = "writeline";
const char* sjg_string112 = "f32_asstring";
const char* sjg_string113 = "f32_compare";
const char* sjg_string114 = "f32_cos";
const char* sjg_string115 = "f32_hash";
const char* sjg_string116 = "f32_sin";
const char* sjg_string117 = "f32_sqrt";
const char* sjg_string118 = "f32_tan";
const char* sjg_string119 = "filllayout";
const char* sjg_string12 = "shaders/v3f-t2f-c4f.vert";
const char* sjg_string120 = "renderinner";
const char* sjg_string121 = "setrectinner";
const char* sjg_string122 = "font";
const char* sjg_string123 = "fontkey";
const char* sjg_string124 = "hash";
const char* sjg_string125 = "framebuffer";
const char* sjg_string126 = "glbindrenderbuffer";
const char* sjg_string127 = "glbindtexture";
const char* sjg_string128 = "glblendfunc";
const char* sjg_string129 = "glcheckframebufferstatus";
const char* sjg_string13 = "shaders/v3f-t2f-c4f.frag";
const char* sjg_string130 = "glclearcolor";
const char* sjg_string131 = "gldisable";
const char* sjg_string132 = "glenable";
const char* sjg_string133 = "glframebufferrenderbuffer";
const char* sjg_string134 = "glframebuffertexture2d";
const char* sjg_string135 = "glgenframebuffer";
const char* sjg_string136 = "glgenrenderbuffer";
const char* sjg_string137 = "glgentexture";
const char* sjg_string138 = "glgetuniformlocation";
const char* sjg_string139 = "global";
const char* sjg_string14 = "vertex:3f,tex_coord:2f,normal:3f";
const char* sjg_string140 = "glpopframebuffer";
const char* sjg_string141 = "glpopviewport";
const char* sjg_string142 = "glpushframebuffer";
const char* sjg_string143 = "glpushviewport";
const char* sjg_string144 = "glrenderbufferstorage";
const char* sjg_string145 = "glteximage2d";
const char* sjg_string146 = "gltexparameteri";
const char* sjg_string147 = "gluniformi32";
const char* sjg_string148 = "gluniformmat4";
const char* sjg_string149 = "gluniformvec3";
const char* sjg_string15 = "shaders/saturate.frag";
const char* sjg_string150 = "gluseprogram";
const char* sjg_string151 = "halt";
const char* sjg_string152 = "hash![fontkey, font?]";
const char* sjg_string153 = "_weakptrremovekey";
const char* sjg_string154 = "_weakptrremovevalue";
const char* sjg_string155 = "hash![string, #element?]";
const char* sjg_string156 = "hash![string, #model?]";
const char* sjg_string157 = "hash![type, bool]";
const char* sjg_string158 = "i32_asstring";
const char* sjg_string159 = "i32_max";
const char* sjg_string16 = "viewport being pop'ed is wrong";
const char* sjg_string160 = "image";
const char* sjg_string161 = "imageelement";
const char* sjg_string162 = "imagerenderer";
const char* sjg_string163 = "intersecttriangle";
const char* sjg_string164 = "lambda1";
const char* sjg_string165 = "invoke";
const char* sjg_string166 = "lambda2";
const char* sjg_string167 = "light";
const char* sjg_string168 = "list!#animation";
const char* sjg_string169 = "getcount";
const char* sjg_string17 = "framebuffer being pop'ed is wrong";
const char* sjg_string170 = "removeat";
const char* sjg_string171 = "list!#model";
const char* sjg_string172 = "add";
const char* sjg_string173 = "list!rect";
const char* sjg_string174 = "list!u32";
const char* sjg_string175 = "log";
const char* sjg_string176 = "_write";
const char* sjg_string177 = "loglevel_asstring";
const char* sjg_string178 = "mainloop";
const char* sjg_string179 = "margin";
const char* sjg_string18 = "viewModel";
const char* sjg_string180 = "mat4";
const char* sjg_string181 = "determinant";
const char* sjg_string182 = "mat4_identity";
const char* sjg_string183 = "invert";
const char* sjg_string184 = "mat4_lookatlh";
const char* sjg_string185 = "multiply";
const char* sjg_string186 = "multiplyf32";
const char* sjg_string187 = "multiplyvec4";
const char* sjg_string188 = "mat4_orthographic";
const char* sjg_string189 = "mat4_perspective";
const char* sjg_string19 = "normalMat";
const char* sjg_string190 = "mat4_scale";
const char* sjg_string191 = "transpose";
const char* sjg_string192 = "model_zsort";
const char* sjg_string193 = "mouseevent";
const char* sjg_string194 = "asstring";
const char* sjg_string195 = "firechildren";
const char* sjg_string196 = "point";
const char* sjg_string197 = "rect";
const char* sjg_string198 = "containspoint";
const char* sjg_string199 = "subtractmargin";
const char* sjg_string2 = "shaders/blur-horizontal.frag";
const char* sjg_string20 = "projection";
const char* sjg_string200 = "renderbuffer";
const char* sjg_string201 = "runloop";
const char* sjg_string202 = "scene2d";
const char* sjg_string203 = "end";
const char* sjg_string204 = "setsize";
const char* sjg_string205 = "start";
const char* sjg_string206 = "scene2dmodel";
const char* sjg_string207 = "getcenter";
const char* sjg_string208 = "getworld";
const char* sjg_string209 = "getz";
const char* sjg_string21 = "lightPos";
const char* sjg_string210 = "renderorqueue";
const char* sjg_string211 = "update";
const char* sjg_string212 = "scene3delement";
const char* sjg_string213 = "shader";
const char* sjg_string214 = "size";
const char* sjg_string215 = "addmargin";
const char* sjg_string216 = "max";
const char* sjg_string217 = "min";
const char* sjg_string218 = "spherevertexbuffer";
const char* sjg_string219 = "string";
const char* sjg_string22 = "diffuseColor";
const char* sjg_string220 = "nullterminate";
const char* sjg_string221 = "touppercase";
const char* sjg_string222 = "style";
const char* sjg_string223 = "texture_frompng";
const char* sjg_string224 = "type_asstring";
const char* sjg_string225 = "type_hash";
const char* sjg_string226 = "type_isequal";
const char* sjg_string227 = "vec2";
const char* sjg_string228 = "vec2_getrawsize";
const char* sjg_string229 = "vec2_rawcopy";
const char* sjg_string23 = "specColor";
const char* sjg_string230 = "vec3";
const char* sjg_string231 = "cross";
const char* sjg_string232 = "dot";
const char* sjg_string233 = "vec3_getrawsize";
const char* sjg_string234 = "normalize";
const char* sjg_string235 = "vec3_rawcopy";
const char* sjg_string236 = "subtract";
const char* sjg_string237 = "vec4";
const char* sjg_string238 = "vertex_location_texture_normal";
const char* sjg_string239 = "vertex_location_texture_normal_getrawsize";
const char* sjg_string24 = "trace";
const char* sjg_string240 = "vertex_location_texture_normal_rawcopy";
const char* sjg_string241 = "vertexbuffer!vertex_location_texture_normal";
const char* sjg_string242 = "translatescreentotexture";
const char* sjg_string243 = "windowrenderer";
const char* sjg_string244 = "present";
const char* sjg_string245 = "texthorizontal";
const char* sjg_string246 = "textvertical";
const char* sjg_string247 = "type";
const char* sjg_string248 = "u32";
const char* sjg_string249 = "u64";
const char* sjg_string25 = "debug";
const char* sjg_string250 = "void";
const char* sjg_string26 = "info";
const char* sjg_string27 = "warn";
const char* sjg_string28 = "error";
const char* sjg_string29 = "fatal";
const char* sjg_string3 = "shaders/blur-vertical.frag";
const char* sjg_string30 = "";
const char* sjg_string31 = " [";
const char* sjg_string32 = "] ";
const char* sjg_string33 = "point : ";
const char* sjg_string34 = ", ";
const char* sjg_string35 = " isCaptured : ";
const char* sjg_string36 = "false";
const char* sjg_string37 = "true";
const char* sjg_string38 = " isLeftDown : ";
const char* sjg_string39 = " -> does not map";
const char* sjg_string4 = "shaders/fade.frag";
const char* sjg_string40 = " -> ";
const char* sjg_string41 = "Framebuffer failed";
const char* sjg_string42 = "texture";
const char* sjg_string43 = "model";
const char* sjg_string44 = "view";
const char* sjg_string45 = "assets/test.png";
const char* sjg_string46 = "FPS: ";
const char* sjg_string47 = "bool";
const char* sjg_string48 = "borderposition";
const char* sjg_string49 = "(:heap #model, :heap #model)i32";
const char* sjg_string5 = "shaders/v3f-c4f.vert";
const char* sjg_string50 = "(:local #model, :local #model)i32";
const char* sjg_string51 = "(:stack rect)void";
const char* sjg_string52 = "(:stack scene2d)void";
const char* sjg_string53 = "()stack string";
const char* sjg_string54 = "char";
const char* sjg_string55 = "clickstate";
const char* sjg_string56 = "f32";
const char* sjg_string57 = "f64";
const char* sjg_string58 = "flowlayoutorientation";
const char* sjg_string59 = "glblendfunctype";
const char* sjg_string6 = "shaders/v3f-c4f.frag";
const char* sjg_string60 = "gldrawmode";
const char* sjg_string61 = "glfeature";
const char* sjg_string62 = "glframebufferattachment";
const char* sjg_string63 = "glframebufferstatus";
const char* sjg_string64 = "glframebuffertexture";
const char* sjg_string65 = "glrenderbufferformat";
const char* sjg_string66 = "gltexture";
const char* sjg_string67 = "gltextureattribute";
const char* sjg_string68 = "gltextureformat";
const char* sjg_string69 = "gltexturetype";
const char* sjg_string7 = "shaders/v3f-t2f.frag";
const char* sjg_string70 = "gltexturevalue";
const char* sjg_string71 = "gridunittype";
const char* sjg_string72 = "i32";
const char* sjg_string73 = "i64";
const char* sjg_string74 = "imagestretch";
const char* sjg_string75 = "listlayoutorientation";
const char* sjg_string76 = "loglevel";
const char* sjg_string77 = "mouseeventtype";
const char* sjg_string78 = "ptr";
const char* sjg_string79 = "#animation";
const char* sjg_string8 = "shaders/v3f-n3f-phong.vert";
const char* sjg_string80 = "#effect";
const char* sjg_string81 = "#element";
const char* sjg_string82 = "#model";
const char* sjg_string83 = "animator";
const char* sjg_string84 = "nextframe";
const char* sjg_string85 = "array!char";
const char* sjg_string86 = "getat";
const char* sjg_string87 = "grow";
const char* sjg_string88 = "initat";
const char* sjg_string89 = "isequal";
const char* sjg_string9 = "shaders/v3f-n3f-phong.frag";
const char* sjg_string90 = "array!#animation";
const char* sjg_string91 = "array!#element";
const char* sjg_string92 = "array!#model";
const char* sjg_string93 = "_quicksortcallback";
const char* sjg_string94 = "setat";
const char* sjg_string95 = "sortcb";
const char* sjg_string96 = "array!i32";
const char* sjg_string97 = "array!rect";
const char* sjg_string98 = "array!u32";
const char* sjg_string99 = "array!vertex_location_texture_normal";

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
#define sjs_array_heap_iface_model_typeId 109
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
#define sjs_array_heap_iface_element_typeId 88
#define sjs_margin_typeId 89
#define sji_effect_typeId 92
#define sjs_filllayout_typeId 87
#define cb_rect_void_typeId 90
#define cb_rect_void_heap_typeId 90
#define cb_scene2d_void_typeId 91
#define cb_scene2d_void_heap_typeId 91
#define sjs_scene3delement_typeId 108
#define cb_heap_iface_model_heap_iface_model_i32_typeId 129
#define cb_heap_iface_model_heap_iface_model_i32_heap_typeId 129
#define cb_local_iface_model_local_iface_model_i32_typeId 135
#define cb_local_iface_model_local_iface_model_i32_heap_typeId 135
#define sjs_array_i32_typeId 198
#define sjs_array_vertex_location_texture_normal_typeId 199
#define sjs_vertexbuffer_vertex_location_texture_normal_typeId 152
#define sjs_vec4_typeId 160
#define sjs_framebuffer_typeId 161
#define sjs_texture_typeId 162
#define sjs_renderbuffer_typeId 163
#define sjs_scene2dmodel_typeId 150
#define sjs_vec2_typeId 157
#define sjs_vertex_location_texture_normal_typeId 151
#define cb_string_heap_string_typeId 205
#define cb_string_heap_string_heap_typeId 205
#define sjs_lambda2_typeId 221
#define sjs_lambda1_typeId 215
#define sjs_image_typeId 248
#define sjs_imagerenderer_typeId 250
#define sjs_imageelement_typeId 247
#define sjs_boxrenderer_typeId 262
#define sjs_crosshairselement_typeId 261

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
typedef struct td_sji_effect_vtbl sji_effect_vtbl;
typedef struct td_sji_effect sji_effect;
typedef struct td_sjs_filllayout sjs_filllayout;
typedef struct td_cb_rect_void cb_rect_void;
typedef struct td_cb_rect_void_heap cb_rect_void_heap;
typedef struct td_cb_scene2d_void cb_scene2d_void;
typedef struct td_cb_scene2d_void_heap cb_scene2d_void_heap;
typedef struct td_sjs_scene3delement sjs_scene3delement;
typedef struct td_cb_heap_iface_model_heap_iface_model_i32 cb_heap_iface_model_heap_iface_model_i32;
typedef struct td_cb_heap_iface_model_heap_iface_model_i32_heap cb_heap_iface_model_heap_iface_model_i32_heap;
typedef struct td_cb_local_iface_model_local_iface_model_i32 cb_local_iface_model_local_iface_model_i32;
typedef struct td_cb_local_iface_model_local_iface_model_i32_heap cb_local_iface_model_local_iface_model_i32_heap;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sjs_array_vertex_location_texture_normal sjs_array_vertex_location_texture_normal;
typedef struct td_sjs_vertexbuffer_vertex_location_texture_normal sjs_vertexbuffer_vertex_location_texture_normal;
typedef struct td_sjs_vec4 sjs_vec4;
typedef struct td_sjs_framebuffer sjs_framebuffer;
typedef struct td_sjs_texture sjs_texture;
typedef struct td_sjs_renderbuffer sjs_renderbuffer;
typedef struct td_sjs_scene2dmodel sjs_scene2dmodel;
typedef struct td_sjs_vec2 sjs_vec2;
typedef struct td_sjs_vertex_location_texture_normal sjs_vertex_location_texture_normal;
typedef struct td_cb_string_heap_string cb_string_heap_string;
typedef struct td_cb_string_heap_string_heap cb_string_heap_string_heap;
typedef struct td_sjs_lambda2 sjs_lambda2;
typedef struct td_sjs_lambda1 sjs_lambda1;
typedef struct td_sjs_image sjs_image;
typedef struct td_sjs_imagerenderer sjs_imagerenderer;
typedef struct td_sjs_imageelement sjs_imageelement;
typedef struct td_sjs_boxrenderer sjs_boxrenderer;
typedef struct td_sjs_crosshairselement sjs_crosshairselement;

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

struct td_sjs_array_i32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_array_vertex_location_texture_normal {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_vertexbuffer_vertex_location_texture_normal {
    int _refCount;
    sjs_string format;
    sjs_array_i32 indices;
    sjs_array_vertex_location_texture_normal vertices;
    vertex_buffer_t* buffer;
};

struct td_sjs_vec4 {
    int _refCount;
    float x;
    float y;
    float z;
    float w;
};

struct td_sjs_framebuffer {
    int _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_texture {
    int _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_renderbuffer {
    int _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_scene2dmodel {
    int _refCount;
    sjs_string id;
    sjs_vertexbuffer_vertex_location_texture_normal vertexbuffer;
    sjs_shader shader;
    sjs_size texturesize;
    sjs_array_heap_iface_element children;
    bool hasalpha;
    sjs_vec3 center;
    sjs_mat4 model;
    sjs_scene2d _innerscene;
    sjs_rect _scenerect;
    sjs_mat4 _projection;
    sjs_mat4 _world;
    sjs_mat4 _view;
    sjs_light _light;
    sjs_vec4 _projectedcenter;
    sjs_framebuffer _framebuffer;
    sjs_texture _texture;
    sjs_renderbuffer _renderbuffer;
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

struct td_cb_string_heap_string {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_string* _return);
    void (*_cb_heap)(sjs_object* _parent, sjs_string** _return);
};

struct td_cb_string_heap_string_heap {
    cb_string_heap_string inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_lambda2 {
    int _refCount;
    sjs_mouseevent* lambdaparam3;
    sjs_vec2* lambdaparam4;
    sjs_mouseevent* lambdaparam5;
};

struct td_sjs_lambda1 {
    int _refCount;
    sjs_mouseevent* lambdaparam1;
    sjs_mouseevent* lambdaparam2;
};

struct td_sjs_image {
    int _refCount;
    sjs_texture texture;
    sjs_rect rect;
    sjs_margin margin;
};

struct td_sjs_imagerenderer {
    int _refCount;
    sjs_rect rect;
    sjs_image image;
    vertex_buffer_t* buffer;
};

struct td_sjs_imageelement {
    int _refCount;
    sjs_image image;
    sjs_margin margin;
    int32_t stretch;
    sjs_rect _rect;
    sjs_imagerenderer _imagerenderer;
};

struct td_sjs_boxrenderer {
    int _refCount;
    sjs_rect rect;
    sjs_color color;
    vertex_buffer_t* buffer;
};

struct td_sjs_crosshairselement {
    int _refCount;
    sjs_color color;
    sjs_rect _rect;
    sjs_boxrenderer _topdownrenderer;
    sjs_boxrenderer _leftrightrenderer;
    sjs_point _point;
};

sji_element_vtbl sjs_crosshairselement_element_vtbl;
sji_element_vtbl sjs_filllayout_element_vtbl;
sji_element_vtbl sjs_imageelement_element_vtbl;
sji_model_vtbl sjs_scene2dmodel_model_vtbl;
sji_element_vtbl sjs_scene3delement_element_vtbl;
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
float result14;
sjs_vec3 sjt_call108 = { -1 };
sjs_vec3 sjt_call109 = { -1 };
sjs_scene2dmodel* sjt_call11 = 0;
sjs_imageelement* sjt_call110 = 0;
sjs_string sjt_call118 = { -1 };
sjs_crosshairselement* sjt_call119 = 0;
sjs_crosshairselement* sjt_call120 = 0;
sjs_filllayout* sjt_call3 = 0;
sjs_scene3delement* sjt_call6 = 0;
sjs_filllayout* sjt_cast2 = 0;
sjs_scene3delement* sjt_cast3 = 0;
sjs_imageelement* sjt_cast39 = 0;
sjs_crosshairselement* sjt_cast48 = 0;
sjs_crosshairselement* sjt_cast49 = 0;
sjs_scene2dmodel* sjt_cast6 = 0;
int32_t sjt_functionParam106;
sji_model sjt_functionParam107 = { 0 };
int32_t sjt_functionParam27;
sji_element sjt_functionParam28 = { 0 };
int32_t sjt_functionParam410;
int32_t sjt_functionParam411;
sjs_vec3* sjt_functionParam412 = 0;
sjs_vec3* sjt_functionParam413 = 0;
int32_t sjt_functionParam414;
sji_element sjt_functionParam415 = { 0 };
sjs_string* sjt_functionParam441 = 0;
int32_t sjt_functionParam442;
sji_element sjt_functionParam443 = { 0 };
int32_t sjt_functionParam448;
sji_element sjt_functionParam449 = { 0 };
sjs_array_heap_iface_element* sjt_parent24 = 0;
sjs_array_heap_iface_element* sjt_parent240 = 0;
sjs_array_heap_iface_element* sjt_parent250 = 0;
sjs_array_heap_iface_element* sjt_parent255 = 0;
sjs_array_heap_iface_model* sjt_parent72 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };
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
void sjf_array_u32_getat(sjs_array_u32* _parent, int32_t index, uint32_t* _return);
void sjf_array_u32_grow(sjs_array_u32* _parent, int32_t newsize, sjs_array_u32* _return);
void sjf_array_u32_grow_heap(sjs_array_u32* _parent, int32_t newsize, sjs_array_u32** _return);
void sjf_array_u32_heap(sjs_array_u32* _this);
void sjf_array_u32_initat(sjs_array_u32* _parent, int32_t index, uint32_t item);
void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from);
void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_getat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return);
void sjf_array_vertex_location_texture_normal_getat_heap(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal** _return);
void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_initat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
void sjf_bool_asstring(bool val, sjs_string* _return);
void sjf_bool_asstring_heap(bool val, sjs_string** _return);
void sjf_boxrenderer(sjs_boxrenderer* _this);
void sjf_boxrenderer_copy(sjs_boxrenderer* _this, sjs_boxrenderer* _from);
void sjf_boxrenderer_destroy(sjs_boxrenderer* _this);
void sjf_boxrenderer_heap(sjs_boxrenderer* _this);
void sjf_boxrenderer_render(sjs_boxrenderer* _parent, sjs_scene2d* scene);
void sjf_char_touppercase(char x, char* _return);
void sjf_color(sjs_color* _this);
void sjf_color_asvec3(sjs_color* _parent, sjs_vec3* _return);
void sjf_color_asvec3_heap(sjs_color* _parent, sjs_vec3** _return);
void sjf_color_copy(sjs_color* _this, sjs_color* _from);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color* _this);
void sjf_crosshairselement(sjs_crosshairselement* _this);
void sjf_crosshairselement_as_sji_element(sjs_crosshairselement* _this, sji_element* _return);
void sjf_crosshairselement_asinterface(sjs_crosshairselement* _this, int typeId, sjs_interface* _return);
void sjf_crosshairselement_copy(sjs_crosshairselement* _this, sjs_crosshairselement* _from);
void sjf_crosshairselement_destroy(sjs_crosshairselement* _this);
void sjf_crosshairselement_firemouseevent(sjs_crosshairselement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_crosshairselement_getclasstype(sjs_object* _this, int* _return);
void sjf_crosshairselement_getrect(sjs_crosshairselement* _parent, sjs_rect* _return);
void sjf_crosshairselement_getrect_heap(sjs_crosshairselement* _parent, sjs_rect** _return);
void sjf_crosshairselement_getsize(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_crosshairselement_getsize_heap(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_crosshairselement_heap(sjs_crosshairselement* _this);
void sjf_crosshairselement_render(sjs_crosshairselement* _parent, sjs_scene2d* scene);
void sjf_crosshairselement_setrect(sjs_crosshairselement* _parent, sjs_rect* rect_);
void sjf_debug_writeline(sjs_string* data);
void sjf_f32_asstring(float val, sjs_string* _return);
void sjf_f32_asstring_heap(float val, sjs_string** _return);
void sjf_f32_compare(float l, float r, int32_t* _return);
void sjf_f32_cos(float v, float* _return);
void sjf_f32_hash(float val, uint32_t* _return);
void sjf_f32_sin(float v, float* _return);
void sjf_f32_sqrt(float v, float* _return);
void sjf_f32_tan(float v, float* _return);
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
void sjf_framebuffer(sjs_framebuffer* _this);
void sjf_framebuffer_copy(sjs_framebuffer* _this, sjs_framebuffer* _from);
void sjf_framebuffer_destroy(sjs_framebuffer* _this);
void sjf_framebuffer_heap(sjs_framebuffer* _this);
void sjf_glbindrenderbuffer(sjs_renderbuffer* renderbuffer);
void sjf_glbindtexture(int32_t t, sjs_texture* texture);
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
void sjf_glteximage2d(int32_t t, int32_t level, int32_t format, sjs_size* size, int32_t datatype, void* data);
void sjf_gltexparameteri(int32_t t, int32_t attribute, int32_t val);
void sjf_gluniformi32(int32_t loc, int32_t v);
void sjf_gluniformmat4(int32_t loc, sjs_mat4* m);
void sjf_gluniformvec3(int32_t loc, sjs_vec3* v);
void sjf_gluseprogram(sjs_shader* shader);
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
void sjf_hash_string_weak_iface_model_setat(sjs_hash_string_weak_iface_model* _parent, sjs_string* key, sji_model val);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_getat(sjs_hash_type_bool* _parent, int32_t key, bool_option* _return);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return);
void sjf_i32_max(int32_t a, int32_t b, int32_t* _return);
void sjf_image(sjs_image* _this);
void sjf_image_copy(sjs_image* _this, sjs_image* _from);
void sjf_image_destroy(sjs_image* _this);
void sjf_image_heap(sjs_image* _this);
void sjf_imageelement(sjs_imageelement* _this);
void sjf_imageelement_as_sji_element(sjs_imageelement* _this, sji_element* _return);
void sjf_imageelement_asinterface(sjs_imageelement* _this, int typeId, sjs_interface* _return);
void sjf_imageelement_copy(sjs_imageelement* _this, sjs_imageelement* _from);
void sjf_imageelement_destroy(sjs_imageelement* _this);
void sjf_imageelement_firemouseevent(sjs_imageelement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_imageelement_getclasstype(sjs_object* _this, int* _return);
void sjf_imageelement_getrect(sjs_imageelement* _parent, sjs_rect* _return);
void sjf_imageelement_getrect_heap(sjs_imageelement* _parent, sjs_rect** _return);
void sjf_imageelement_getsize(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_imageelement_getsize_heap(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_imageelement_heap(sjs_imageelement* _this);
void sjf_imageelement_render(sjs_imageelement* _parent, sjs_scene2d* scene);
void sjf_imageelement_setrect(sjs_imageelement* _parent, sjs_rect* rect_);
void sjf_imagerenderer(sjs_imagerenderer* _this);
void sjf_imagerenderer_copy(sjs_imagerenderer* _this, sjs_imagerenderer* _from);
void sjf_imagerenderer_destroy(sjs_imagerenderer* _this);
void sjf_imagerenderer_heap(sjs_imagerenderer* _this);
void sjf_imagerenderer_render(sjs_imagerenderer* _parent, sjs_scene2d* scene);
void sjf_intersecttriangle(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3* _return);
void sjf_intersecttriangle_heap(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3** _return);
void sjf_lambda1(sjs_lambda1* _this);
void sjf_lambda1_copy(sjs_lambda1* _this, sjs_lambda1* _from);
void sjf_lambda1_destroy(sjs_lambda1* _this);
void sjf_lambda1_heap(sjs_lambda1* _this);
void sjf_lambda1_invoke(sjs_lambda1* _parent, sjs_string* _return);
void sjf_lambda1_invoke_heap(sjs_lambda1* _parent, sjs_string** _return);
void sjf_lambda2(sjs_lambda2* _this);
void sjf_lambda2_copy(sjs_lambda2* _this, sjs_lambda2* _from);
void sjf_lambda2_destroy(sjs_lambda2* _this);
void sjf_lambda2_heap(sjs_lambda2* _this);
void sjf_lambda2_invoke(sjs_lambda2* _parent, sjs_string* _return);
void sjf_lambda2_invoke_heap(sjs_lambda2* _parent, sjs_string** _return);
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
void sjf_list_u32_add(sjs_list_u32* _parent, uint32_t item);
void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from);
void sjf_list_u32_destroy(sjs_list_u32* _this);
void sjf_list_u32_getat(sjs_list_u32* _parent, int32_t index, uint32_t* _return);
void sjf_list_u32_getcount(sjs_list_u32* _parent, int32_t* _return);
void sjf_list_u32_heap(sjs_list_u32* _this);
void sjf_list_u32_removeat(sjs_list_u32* _parent, int32_t index);
void sjf_log(sjs_log* _this);
void sjf_log__write(sjs_log* _parent, int32_t level, sjs_hash_type_bool* includes, int32_t t, cb_string_heap_string cb);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_log_trace(sjs_log* _parent, int32_t t, cb_string_heap_string cb);
void sjf_loglevel_asstring(int32_t e, sjs_string* _return);
void sjf_loglevel_asstring_heap(int32_t e, sjs_string** _return);
void sjf_mainloop(void);
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
void sjf_model_zsort(sji_model l, sji_model r, int32_t* _return);
void sjf_model_zsort_callback(void * _parent, sji_model l, sji_model r, int32_t* _return);
void sjf_mouseevent(sjs_mouseevent* _this);
void sjf_mouseevent_asstring(sjs_mouseevent* _parent, sjs_string* _return);
void sjf_mouseevent_asstring_heap(sjs_mouseevent* _parent, sjs_string** _return);
void sjf_mouseevent_copy(sjs_mouseevent* _this, sjs_mouseevent* _from);
void sjf_mouseevent_destroy(sjs_mouseevent* _this);
void sjf_mouseevent_firechildren(sjs_mouseevent* _parent, sjs_array_heap_iface_element* children, bool* _return);
void sjf_mouseevent_heap(sjs_mouseevent* _this);
void sjf_point(sjs_point* _this);
void sjf_point_asstring(sjs_point* _parent, sjs_string* _return);
void sjf_point_asstring_heap(sjs_point* _parent, sjs_string** _return);
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
void sjf_renderbuffer(sjs_renderbuffer* _this);
void sjf_renderbuffer_copy(sjs_renderbuffer* _this, sjs_renderbuffer* _from);
void sjf_renderbuffer_destroy(sjs_renderbuffer* _this);
void sjf_renderbuffer_heap(sjs_renderbuffer* _this);
void sjf_runloop(void);
void sjf_scene2d(sjs_scene2d* _this);
void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from);
void sjf_scene2d_destroy(sjs_scene2d* _this);
void sjf_scene2d_end(sjs_scene2d* _parent);
void sjf_scene2d_heap(sjs_scene2d* _this);
void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size);
void sjf_scene2d_start(sjs_scene2d* _parent);
void sjf_scene2dmodel_as_sji_model(sjs_scene2dmodel* _this, sji_model* _return);
void sjf_scene2dmodel_asinterface(sjs_scene2dmodel* _this, int typeId, sjs_interface* _return);
void sjf_scene2dmodel_copy(sjs_scene2dmodel* _this, sjs_scene2dmodel* _from);
void sjf_scene2dmodel_destroy(sjs_scene2dmodel* _this);
void sjf_scene2dmodel_firemouseevent(sjs_scene2dmodel* _parent, sjs_mouseevent* mouseevent);
void sjf_scene2dmodel_getcenter(sjs_scene2dmodel* _parent, sjs_vec3* _return);
void sjf_scene2dmodel_getcenter_heap(sjs_scene2dmodel* _parent, sjs_vec3** _return);
void sjf_scene2dmodel_getclasstype(sjs_object* _this, int* _return);
void sjf_scene2dmodel_getworld(sjs_scene2dmodel* _parent, sjs_mat4* _return);
void sjf_scene2dmodel_getworld_heap(sjs_scene2dmodel* _parent, sjs_mat4** _return);
void sjf_scene2dmodel_getz(sjs_scene2dmodel* _parent, float* _return);
void sjf_scene2dmodel_heap(sjs_scene2dmodel* _this);
void sjf_scene2dmodel_render(sjs_scene2dmodel* _parent);
void sjf_scene2dmodel_renderorqueue(sjs_scene2dmodel* _parent, sjs_list_heap_iface_model* alphamodels);
void sjf_scene2dmodel_update(sjs_scene2dmodel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
void sjf_scene3delement(sjs_scene3delement* _this);
void sjf_scene3delement_as_sji_element(sjs_scene3delement* _this, sji_element* _return);
void sjf_scene3delement_asinterface(sjs_scene3delement* _this, int typeId, sjs_interface* _return);
void sjf_scene3delement_copy(sjs_scene3delement* _this, sjs_scene3delement* _from);
void sjf_scene3delement_destroy(sjs_scene3delement* _this);
void sjf_scene3delement_firemouseevent(sjs_scene3delement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_scene3delement_getclasstype(sjs_object* _this, int* _return);
void sjf_scene3delement_getrect(sjs_scene3delement* _parent, sjs_rect* _return);
void sjf_scene3delement_getrect_heap(sjs_scene3delement* _parent, sjs_rect** _return);
void sjf_scene3delement_getsize(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_scene3delement_getsize_heap(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_scene3delement_heap(sjs_scene3delement* _this);
void sjf_scene3delement_render(sjs_scene3delement* _parent, sjs_scene2d* scene);
void sjf_scene3delement_setrect(sjs_scene3delement* _parent, sjs_rect* rect_);
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
void sjf_spherevertexbuffer(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexbuffer_vertex_location_texture_normal* _return);
void sjf_spherevertexbuffer_heap(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexbuffer_vertex_location_texture_normal** _return);
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
void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return);
void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return);
void sjf_style(sjs_style* _this);
void sjf_style_copy(sjs_style* _this, sjs_style* _from);
void sjf_style_destroy(sjs_style* _this);
void sjf_style_heap(sjs_style* _this);
void sjf_texture(sjs_texture* _this);
void sjf_texture_copy(sjs_texture* _this, sjs_texture* _from);
void sjf_texture_destroy(sjs_texture* _this);
void sjf_texture_frompng(sjs_string* filename, sjs_texture* _return);
void sjf_texture_frompng_heap(sjs_string* filename, sjs_texture** _return);
void sjf_texture_getsize(sjs_texture* _parent, sjs_size* _return);
void sjf_texture_getsize_heap(sjs_texture* _parent, sjs_size** _return);
void sjf_texture_heap(sjs_texture* _this);
void sjf_type_asstring(int32_t t, sjs_string* _return);
void sjf_type_asstring_heap(int32_t t, sjs_string** _return);
void sjf_type_hash(int32_t val, uint32_t* _return);
void sjf_type_isequal(int32_t l, int32_t r, bool* _return);
void sjf_vec2(sjs_vec2* _this);
void sjf_vec2_asstring(sjs_vec2* _parent, sjs_string* _return);
void sjf_vec2_asstring_heap(sjs_vec2* _parent, sjs_string** _return);
void sjf_vec2_copy(sjs_vec2* _this, sjs_vec2* _from);
void sjf_vec2_destroy(sjs_vec2* _this);
void sjf_vec2_getrawsize(int32_t* _return);
void sjf_vec2_heap(sjs_vec2* _this);
void sjf_vec2_rawcopy(sjs_vec2* v, void* p, void** _return);
void sjf_vec3(sjs_vec3* _this);
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
void sjf_vertexbuffer_vertex_location_texture_normal(sjs_vertexbuffer_vertex_location_texture_normal* _this);
void sjf_vertexbuffer_vertex_location_texture_normal_copy(sjs_vertexbuffer_vertex_location_texture_normal* _this, sjs_vertexbuffer_vertex_location_texture_normal* _from);
void sjf_vertexbuffer_vertex_location_texture_normal_destroy(sjs_vertexbuffer_vertex_location_texture_normal* _this);
void sjf_vertexbuffer_vertex_location_texture_normal_heap(sjs_vertexbuffer_vertex_location_texture_normal* _this);
void sjf_vertexbuffer_vertex_location_texture_normal_render(sjs_vertexbuffer_vertex_location_texture_normal* _parent, int32_t gldrawmode);
void sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture(sjs_vertexbuffer_vertex_location_texture_normal* _parent, sjs_point* screen, sjs_rect* viewport, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_vec2* _return);
void sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture_heap(sjs_vertexbuffer_vertex_location_texture_normal* _parent, sjs_point* screen, sjs_rect* viewport, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_vec2** _return);
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
    int32_t sjt_capture56;
    sjs_list_heap_iface_animation* sjt_parent256 = 0;

#line 31 "lib/ui/animation.sj"
    _parent->current = time;
#line 4 "lib/common/list.sj"
    sjt_parent256 = &_parent->animations;
#line 4
    sjf_list_heap_iface_animation_getcount(sjt_parent256, &sjt_capture56);
    if (sjt_capture56 > 0) {
        int32_t i;
        int32_t sjt_forEnd26;
        int32_t sjt_forStart26;
        sjs_list_heap_iface_animation* sjt_parent257 = 0;

#line 35 "lib/ui/animation.sj"
        sjt_forStart26 = 0;
#line 4 "lib/common/list.sj"
        sjt_parent257 = &_parent->animations;
#line 4
        sjf_list_heap_iface_animation_getcount(sjt_parent257, &sjt_forEnd26);
#line 35 "lib/ui/animation.sj"
        i = sjt_forEnd26 - 1;
        while (i >= sjt_forStart26) {
            bool sjt_capture57;
            int32_t sjt_functionParam451;
            int32_t sjt_interfaceParam19;
            sjs_list_heap_iface_animation* sjt_parent259 = 0;
            sji_animation sjt_parent260 = { 0 };
            sji_animation sjv_a = { 0 };

#line 8 "lib/common/list.sj"
            sjt_parent259 = &_parent->animations;
#line 35 "lib/ui/animation.sj"
            sjt_functionParam451 = i;
#line 35
            sjf_list_heap_iface_animation_getat_heap(sjt_parent259, sjt_functionParam451, &sjv_a);
#line 2
            sjt_parent260 = sjv_a;
#line 31
            sjt_interfaceParam19 = time;
#line 37
            sjt_parent260._vtbl->nextframe(sjt_parent260._parent, sjt_interfaceParam19, &sjt_capture57);
            if (sjt_capture57) {
                int32_t sjt_functionParam452;
                sjs_list_heap_iface_animation* sjt_parent261 = 0;

#line 53 "lib/common/list.sj"
                sjt_parent261 = &_parent->animations;
#line 35 "lib/ui/animation.sj"
                sjt_functionParam452 = i;
#line 35
                sjf_list_heap_iface_animation_removeat(sjt_parent261, sjt_functionParam452);
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

void sjf_array_heap_iface_model__quicksortcallback(sjs_array_heap_iface_model* _parent, int32_t left, int32_t right, cb_heap_iface_model_heap_iface_model_i32 cb) {
    int32_t sjt_functionParam64;
    bool sjt_while1;
    int32_t sjv_i;
    int32_t sjv_j;
    sji_model sjv_pivot = { 0 };

#line 198 "lib/common/array.sj"
    sjv_i = left;
#line 198
    sjv_j = right;
#line 202
    sjt_functionParam64 = (left + right) / 2;
#line 202
    sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam64, &sjv_pivot);
#line 203
    sjt_while1 = sjv_i <= sjv_j;
    while (sjt_while1) {
        bool sjt_while2;
        bool sjt_while3;
        bool sjv_continue;

#line 204 "lib/common/array.sj"
        sjv_continue = true;
        if (sjv_i < _parent->count) {
#line 205 "lib/common/array.sj"
            sjt_while2 = sjv_continue;
        } else {
#line 205 "lib/common/array.sj"
            sjt_while2 = false;
        }

        while (sjt_while2) {
            int32_t sjt_capture15;
            sji_model sjt_functionParam65 = { 0 };
            int32_t sjt_functionParam66;
            sji_model sjt_functionParam67 = { 0 };

#line 206 "lib/common/array.sj"
            sjt_functionParam66 = sjv_i;
#line 206
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam66, &sjt_functionParam65);
#line 206
            sjt_functionParam67 = sjv_pivot;
            if (sjt_functionParam67._parent != 0) {
                sjt_functionParam67._parent->_refCount++;
            }

#line 206
            cb._cb(cb._parent, sjt_functionParam65, sjt_functionParam67, &sjt_capture15);
#line 206
            sjv_continue = sjt_capture15 < 0;
            if (sjv_continue) {
#line 208 "lib/common/array.sj"
                sjv_i = sjv_i + 1;
            }

            if (sjv_i < _parent->count) {
#line 205 "lib/common/array.sj"
                sjt_while2 = sjv_continue;
            } else {
#line 205 "lib/common/array.sj"
                sjt_while2 = false;
            }

            if (sjt_functionParam65._parent != 0) {
                sjt_functionParam65._parent->_refCount--;
                if (sjt_functionParam65._parent->_refCount <= 0) {
                    sjt_functionParam65._vtbl->destroy(sjt_functionParam65._parent);
                    free(sjt_functionParam65._parent);
                }
            }
            if (sjt_functionParam67._parent != 0) {
                sjt_functionParam67._parent->_refCount--;
                if (sjt_functionParam67._parent->_refCount <= 0) {
                    sjt_functionParam67._vtbl->destroy(sjt_functionParam67._parent);
                    free(sjt_functionParam67._parent);
                }
            }
        }

#line 212
        sjv_continue = true;
        if (sjv_j >= 0) {
#line 213 "lib/common/array.sj"
            sjt_while3 = sjv_continue;
        } else {
#line 213 "lib/common/array.sj"
            sjt_while3 = false;
        }

        while (sjt_while3) {
            int32_t sjt_capture16;
            sji_model sjt_functionParam68 = { 0 };
            int32_t sjt_functionParam69;
            sji_model sjt_functionParam70 = { 0 };

#line 214 "lib/common/array.sj"
            sjt_functionParam69 = sjv_j;
#line 214
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam69, &sjt_functionParam68);
#line 214
            sjt_functionParam70 = sjv_pivot;
            if (sjt_functionParam70._parent != 0) {
                sjt_functionParam70._parent->_refCount++;
            }

#line 214
            cb._cb(cb._parent, sjt_functionParam68, sjt_functionParam70, &sjt_capture16);
#line 214
            sjv_continue = sjt_capture16 > 0;
            if (sjv_continue) {
#line 216 "lib/common/array.sj"
                sjv_j = sjv_j - 1;
            }

            if (sjv_j >= 0) {
#line 213 "lib/common/array.sj"
                sjt_while3 = sjv_continue;
            } else {
#line 213 "lib/common/array.sj"
                sjt_while3 = false;
            }

            if (sjt_functionParam68._parent != 0) {
                sjt_functionParam68._parent->_refCount--;
                if (sjt_functionParam68._parent->_refCount <= 0) {
                    sjt_functionParam68._vtbl->destroy(sjt_functionParam68._parent);
                    free(sjt_functionParam68._parent);
                }
            }
            if (sjt_functionParam70._parent != 0) {
                sjt_functionParam70._parent->_refCount--;
                if (sjt_functionParam70._parent->_refCount <= 0) {
                    sjt_functionParam70._vtbl->destroy(sjt_functionParam70._parent);
                    free(sjt_functionParam70._parent);
                }
            }
        }

        if (sjv_i <= sjv_j) {
            int32_t sjt_functionParam71;
            int32_t sjt_functionParam72;
            sji_model sjt_functionParam73 = { 0 };
            int32_t sjt_functionParam74;
            int32_t sjt_functionParam75;
            sji_model sjt_functionParam76 = { 0 };
            sji_model sjv_tmp = { 0 };

#line 221 "lib/common/array.sj"
            sjt_functionParam71 = sjv_i;
#line 221
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam71, &sjv_tmp);
#line 222
            sjt_functionParam72 = sjv_i;
#line 222
            sjt_functionParam74 = sjv_j;
#line 222
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam74, &sjt_functionParam73);
#line 222
            sjf_array_heap_iface_model_setat(_parent, sjt_functionParam72, sjt_functionParam73);
#line 223
            sjt_functionParam75 = sjv_j;
#line 223
            sjt_functionParam76 = sjv_tmp;
            if (sjt_functionParam76._parent != 0) {
                sjt_functionParam76._parent->_refCount++;
            }

#line 223
            sjf_array_heap_iface_model_setat(_parent, sjt_functionParam75, sjt_functionParam76);
#line 224
            sjv_i = sjv_i + 1;
#line 225
            sjv_j = sjv_j - 1;

            if (sjt_functionParam73._parent != 0) {
                sjt_functionParam73._parent->_refCount--;
                if (sjt_functionParam73._parent->_refCount <= 0) {
                    sjt_functionParam73._vtbl->destroy(sjt_functionParam73._parent);
                    free(sjt_functionParam73._parent);
                }
            }
            if (sjt_functionParam76._parent != 0) {
                sjt_functionParam76._parent->_refCount--;
                if (sjt_functionParam76._parent->_refCount <= 0) {
                    sjt_functionParam76._vtbl->destroy(sjt_functionParam76._parent);
                    free(sjt_functionParam76._parent);
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

#line 203
        sjt_while1 = sjv_i <= sjv_j;
    }

    if (left < sjv_j) {
        int32_t sjt_functionParam77;
        int32_t sjt_functionParam78;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam79;

#line 198 "lib/common/array.sj"
        sjt_functionParam77 = left;
#line 230
        sjt_functionParam78 = sjv_j;
#line 198
        sjt_functionParam79 = cb;
#line 198
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam77, sjt_functionParam78, sjt_functionParam79);
    }

    if (sjv_i < right) {
        int32_t sjt_functionParam80;
        int32_t sjt_functionParam81;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam82;

#line 233 "lib/common/array.sj"
        sjt_functionParam80 = sjv_i;
#line 198
        sjt_functionParam81 = right;
#line 198
        sjt_functionParam82 = cb;
#line 198
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam80, sjt_functionParam81, sjt_functionParam82);
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

void sjf_array_heap_iface_model_getat_heap(sjs_array_heap_iface_model* _parent, int32_t index, sji_model* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sji_model* p = (sji_model*)_parent->data;
#line 14
    #line 8 "lib/common/array.sj"
(*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_model_grow(sjs_array_heap_iface_model* _parent, int32_t newsize, sjs_array_heap_iface_model* _return) {
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
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(sji_model))) + 1;
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
        sji_model* p = (sji_model*)_parent->data;
#line 151
        sji_model* newp = (sji_model*)sjv_newdata;
#line 153
        int count = _parent->count;
#line 155
        #if false
#line 156
        memcpy(newp, p, sizeof(sji_model) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            #line 136 "lib/common/array.sj"
newp[i] = p[i];
if (newp[i]._parent != 0) {
    newp[i]._parent->_refCount++;
}
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
    sjf_array_heap_iface_model(_return);
}

void sjf_array_heap_iface_model_grow_heap(sjs_array_heap_iface_model* _parent, int32_t newsize, sjs_array_heap_iface_model** _return) {
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
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(sji_model))) + 1;
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
        sji_model* p = (sji_model*)_parent->data;
#line 151
        sji_model* newp = (sji_model*)sjv_newdata;
#line 153
        int count = _parent->count;
#line 155
        #if false
#line 156
        memcpy(newp, p, sizeof(sji_model) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            #line 136 "lib/common/array.sj"
newp[i] = p[i];
if (newp[i]._parent != 0) {
    newp[i]._parent->_refCount++;
}
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    (*_return) = (sjs_array_heap_iface_model*)malloc(sizeof(sjs_array_heap_iface_model));
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
    sjf_array_heap_iface_model_heap((*_return));
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

void sjf_array_heap_iface_model_initat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item) {
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
    sji_model* p = (sji_model*)_parent->data;
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

void sjf_array_heap_iface_model_setat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item) {
#line 51 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 52
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
#line 53
    }
#line 55
    sji_model* p = (sji_model*)_parent->data;
#line 56
    if (p[index]._parent != 0) {
    p[index]._parent->_refCount--;
    if (p[index]._parent->_refCount <= 0) {
        p[index]._vtbl->destroy(p[index]._parent);
        free(p[index]._parent);
    }
}
;
#line 57
    #line 49 "lib/common/array.sj"
p[index] = item;
if (p[index]._parent != 0) {
    p[index]._parent->_refCount++;
}
;
}

void sjf_array_heap_iface_model_sortcb(sjs_array_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb) {
    if (_parent->count > 1) {
        int32_t sjt_functionParam83;
        int32_t sjt_functionParam84;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam85;

#line 245 "lib/common/array.sj"
        sjt_functionParam83 = 0;
#line 245
        sjt_functionParam84 = _parent->count - 1;
#line 243
        sjt_functionParam85 = cb;
#line 243
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam83, sjt_functionParam84, sjt_functionParam85);
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

void sjf_array_u32_getat(sjs_array_u32* _parent, int32_t index, uint32_t* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    uint32_t* p = (uint32_t*)_parent->data;
#line 14
    #line 8 "lib/common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_u32_grow(sjs_array_u32* _parent, int32_t newsize, sjs_array_u32* _return) {
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
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(uint32_t))) + 1;
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
        uint32_t* p = (uint32_t*)_parent->data;
#line 151
        uint32_t* newp = (uint32_t*)sjv_newdata;
#line 153
        int count = _parent->count;
#line 155
        #if true
#line 156
        memcpy(newp, p, sizeof(uint32_t) * count);
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
    sjf_array_u32(_return);
}

void sjf_array_u32_grow_heap(sjs_array_u32* _parent, int32_t newsize, sjs_array_u32** _return) {
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
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(uint32_t))) + 1;
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
        uint32_t* p = (uint32_t*)_parent->data;
#line 151
        uint32_t* newp = (uint32_t*)sjv_newdata;
#line 153
        int count = _parent->count;
#line 155
        #if true
#line 156
        memcpy(newp, p, sizeof(uint32_t) * count);
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
    (*_return) = (sjs_array_u32*)malloc(sizeof(sjs_array_u32));
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
    sjf_array_u32_heap((*_return));
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

void sjf_array_u32_initat(sjs_array_u32* _parent, int32_t index, uint32_t item) {
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
    uint32_t* p = (uint32_t*)_parent->data;
#line 44
    #line 34 "lib/common/array.sj"
p[index] = item;
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_vertex_location_texture_normal) + sizeof(int)) + 1;
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

void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from) {
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

void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this) {
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
            sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_this->data;
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

void sjf_array_vertex_location_texture_normal_getat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_parent->data;
#line 14
    _return->_refCount = 1;
#line 8 "lib/common/array.sj"
sjf_vertex_location_texture_normal_copy(_return, &p[index]);
return;;       
}

void sjf_array_vertex_location_texture_normal_getat_heap(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal** _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_parent->data;
#line 14
    (*_return) = (sjs_vertex_location_texture_normal*)malloc(sizeof(sjs_vertex_location_texture_normal));
(*_return)->_refCount = 1;
#line 8 "lib/common/array.sj"
sjf_vertex_location_texture_normal_copy((*_return), &p[index]);
return;;       
}

void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_vertex_location_texture_normal) + sizeof(int)) + 1;
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

void sjf_array_vertex_location_texture_normal_initat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item) {
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
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_parent->data;
#line 44
    p[index]._refCount = 1;
#line 34 "lib/common/array.sj"
sjf_vertex_location_texture_normal_copy(&p[index], item);
;
#line 45
    _parent->count = index + 1;
}

void sjf_bool_asstring(bool val, sjs_string* _return) {
    if (val) {
        _return->_refCount = 1;
#line 3 "lib/common/bool.sj"
        _return->count = 4;
#line 3
        _return->data._refCount = 1;
#line 3
        _return->data.datasize = 4;
#line 3
        _return->data.data = (void*)sjg_string37;
#line 3
        _return->data.isglobal = true;
#line 3
        _return->data.count = 4;
#line 3
        sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    } else {
        _return->_refCount = 1;
#line 5 "lib/common/bool.sj"
        _return->count = 5;
#line 5
        _return->data._refCount = 1;
#line 5
        _return->data.datasize = 5;
#line 5
        _return->data.data = (void*)sjg_string36;
#line 5
        _return->data.isglobal = true;
#line 5
        _return->data.count = 5;
#line 5
        sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    }
}

void sjf_bool_asstring_heap(bool val, sjs_string** _return) {
    if (val) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 3 "lib/common/bool.sj"
        (*_return)->count = 4;
#line 3
        (*_return)->data._refCount = 1;
#line 3
        (*_return)->data.datasize = 4;
#line 3
        (*_return)->data.data = (void*)sjg_string37;
#line 3
        (*_return)->data.isglobal = true;
#line 3
        (*_return)->data.count = 4;
#line 3
        sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    } else {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 5 "lib/common/bool.sj"
        (*_return)->count = 5;
#line 5
        (*_return)->data._refCount = 1;
#line 5
        (*_return)->data.datasize = 5;
#line 5
        (*_return)->data.data = (void*)sjg_string36;
#line 5
        (*_return)->data.isglobal = true;
#line 5
        (*_return)->data.count = 5;
#line 5
        sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    }
}

void sjf_boxrenderer(sjs_boxrenderer* _this) {
#line 20 "lib/ui/boxRenderer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,color:4f");
#line 21
    float x0 = (float)_this->rect.x;
#line 22
    float y0 = (float)(_this->rect.y + _this->rect.h);
#line 23
    float x1 = (float)(_this->rect.x + _this->rect.w);
#line 24
    float y1 = (float)_this->rect.y;
#line 25
    GLuint index = (GLuint)_this->buffer->vertices->size;
#line 26
    GLuint indices[] = { //
#line 27
    index, index+1, index+2,
#line 28
    index, index+2, index+3 };
#line 29
    vertex3_color4_t vertices[] = { //
#line 30
    { x0, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 31
    { x0, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 32
    { x1, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 33
    { x1, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a } };
#line 34
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 35
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
}

void sjf_boxrenderer_copy(sjs_boxrenderer* _this, sjs_boxrenderer* _from) {
    _this->rect._refCount = 1;
#line 1 "lib/ui/boxRenderer.sj"
    sjf_rect_copy(&_this->rect, &_from->rect);
#line 1
    _this->color._refCount = 1;
#line 1
    sjf_color_copy(&_this->color, &_from->color);
#line 40
    _this->buffer = _from->buffer;
#line 41
    ptr_retain(_this->buffer);
}

void sjf_boxrenderer_destroy(sjs_boxrenderer* _this) {
#line 45 "lib/ui/boxRenderer.sj"
    if (ptr_release(_this->buffer)) {
#line 46
        vertex_buffer_delete(_this->buffer);
#line 47
    }  
#line 47
    if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
#line 47
    if (_this->color._refCount == 1) { sjf_color_destroy(&_this->color); }
;
}

void sjf_boxrenderer_heap(sjs_boxrenderer* _this) {
#line 20 "lib/ui/boxRenderer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,color:4f");
#line 21
    float x0 = (float)_this->rect.x;
#line 22
    float y0 = (float)(_this->rect.y + _this->rect.h);
#line 23
    float x1 = (float)(_this->rect.x + _this->rect.w);
#line 24
    float y1 = (float)_this->rect.y;
#line 25
    GLuint index = (GLuint)_this->buffer->vertices->size;
#line 26
    GLuint indices[] = { //
#line 27
    index, index+1, index+2,
#line 28
    index, index+2, index+3 };
#line 29
    vertex3_color4_t vertices[] = { //
#line 30
    { x0, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 31
    { x0, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 32
    { x1, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 33
    { x1, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a } };
#line 34
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 35
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
}

void sjf_boxrenderer_render(sjs_boxrenderer* _parent, sjs_scene2d* scene) {
#line 10 "lib/ui/boxRenderer.sj"
    glUseProgram(sjv_boxshader.id);
#line 11
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxshader.id, "model" ), 1, 0, (GLfloat*)&scene->model.m00);
#line 12
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxshader.id, "view" ), 1, 0, (GLfloat*)&scene->view.m00);
#line 13
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxshader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection.m00);
#line 14
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_char_touppercase(char x, char* _return) {
#line 3 "lib/common/char.sj"
    #line 2 "lib/common/char.sj"
(*_return) = toupper(x);
return;
}

void sjf_color(sjs_color* _this) {
}

void sjf_color_asvec3(sjs_color* _parent, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 21 "lib/ui/color.sj"
    _return->x = _parent->r;
#line 21
    _return->y = _parent->g;
#line 21
    _return->z = _parent->b;
#line 21
    sjf_vec3(_return);
}

void sjf_color_asvec3_heap(sjs_color* _parent, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
#line 21 "lib/ui/color.sj"
    (*_return)->x = _parent->r;
#line 21
    (*_return)->y = _parent->g;
#line 21
    (*_return)->z = _parent->b;
#line 21
    sjf_vec3_heap((*_return));
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

void sjf_crosshairselement(sjs_crosshairselement* _this) {
}

void sjf_crosshairselement_as_sji_element(sjs_crosshairselement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_crosshairselement_element_vtbl;
}

void sjf_crosshairselement_asinterface(sjs_crosshairselement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_crosshairselement_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_crosshairselement_copy(sjs_crosshairselement* _this, sjs_crosshairselement* _from) {
    _this->color._refCount = 1;
#line 1 "lib/ui/crossHairsElement.sj"
    sjf_color_copy(&_this->color, &_from->color);
#line 1
    _this->_rect._refCount = 1;
#line 1
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 1
    sjs_boxrenderer* copyoption24 = (_from->_topdownrenderer._refCount != -1 ? &_from->_topdownrenderer : 0);
    if (copyoption24 != 0) {
        _this->_topdownrenderer._refCount = 1;
#line 1 "lib/ui/crossHairsElement.sj"
        sjf_boxrenderer_copy(&_this->_topdownrenderer, copyoption24);
    } else {
        _this->_topdownrenderer._refCount = -1;
    }

#line 1
    sjs_boxrenderer* copyoption25 = (_from->_leftrightrenderer._refCount != -1 ? &_from->_leftrightrenderer : 0);
    if (copyoption25 != 0) {
        _this->_leftrightrenderer._refCount = 1;
#line 1 "lib/ui/crossHairsElement.sj"
        sjf_boxrenderer_copy(&_this->_leftrightrenderer, copyoption25);
    } else {
        _this->_leftrightrenderer._refCount = -1;
    }

#line 1
    _this->_point._refCount = 1;
#line 1
    sjf_point_copy(&_this->_point, &_from->_point);
}

void sjf_crosshairselement_destroy(sjs_crosshairselement* _this) {
    if (_this->color._refCount == 1) { sjf_color_destroy(&_this->color); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
    if (_this->_topdownrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_this->_topdownrenderer); }
;
    if (_this->_leftrightrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_this->_leftrightrenderer); }
;
    if (_this->_point._refCount == 1) { sjf_point_destroy(&_this->_point); }
;
}

void sjf_crosshairselement_firemouseevent(sjs_crosshairselement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    bool sjt_capture55;
    sjs_point* sjt_functionParam447 = 0;
    sjs_rect* sjt_parent254 = 0;

#line 11 "lib/ui/rect.sj"
    sjt_parent254 = &_parent->_rect;
#line 41 "lib/ui/crossHairsElement.sj"
    sjt_functionParam447 = &mouseevent->point;
#line 41
    sjf_rect_containspoint(sjt_parent254, sjt_functionParam447, &sjt_capture55);
    if (sjt_capture55) {
        if (mouseevent->eventtype == sjv_mouseeventtype_move) {
            if (_parent->_point._refCount == 1) { sjf_point_destroy(&_parent->_point); }
;
#line 43 "lib/ui/crossHairsElement.sj"
            sjf_point_copy(&_parent->_point, &mouseevent->point);
#line 43
            if (_parent->_topdownrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_parent->_topdownrenderer); }
;
#line 44
            _parent->_topdownrenderer._refCount = -1;
#line 44
            if (_parent->_leftrightrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_parent->_leftrightrenderer); }
;
#line 45
            _parent->_leftrightrenderer._refCount = -1;
        }
    }

#line 48
    (*_return) = true;
}

void sjf_crosshairselement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 261;
}

void sjf_crosshairselement_getrect(sjs_crosshairselement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 12 "lib/ui/crossHairsElement.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_crosshairselement_getrect_heap(sjs_crosshairselement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 12 "lib/ui/crossHairsElement.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_crosshairselement_getsize(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 9 "lib/ui/crossHairsElement.sj"
    _return->w = maxsize->w;
#line 9
    _return->h = maxsize->h;
#line 9
    sjf_size(_return);
}

void sjf_crosshairselement_getsize_heap(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 9 "lib/ui/crossHairsElement.sj"
    (*_return)->w = maxsize->w;
#line 9
    (*_return)->h = maxsize->h;
#line 9
    sjf_size_heap((*_return));
}

void sjf_crosshairselement_heap(sjs_crosshairselement* _this) {
}

void sjf_crosshairselement_render(sjs_crosshairselement* _parent, sjs_scene2d* scene) {
    sjs_boxrenderer sjt_value13 = { -1 };
    sjs_boxrenderer sjt_value14 = { -1 };

    if ((_parent->_topdownrenderer._refCount != -1 ? &_parent->_topdownrenderer : 0) == 0) {
        sjt_value13._refCount = 1;
        sjt_value13.rect._refCount = 1;
#line 26 "lib/ui/crossHairsElement.sj"
        sjt_value13.rect.x = (&_parent->_point)->x;
#line 26
        sjt_value13.rect.y = (&_parent->_rect)->y;
#line 26
        sjt_value13.rect.w = 1;
#line 26
        sjt_value13.rect.h = (&_parent->_rect)->h;
#line 26
        sjf_rect(&sjt_value13.rect);
#line 26
        sjt_value13.color._refCount = 1;
#line 25
        sjf_color_copy(&sjt_value13.color, &_parent->color);
#line 25
        sjf_boxrenderer(&sjt_value13);
#line 25
        if (_parent->_topdownrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_parent->_topdownrenderer); }
;
#line 25
        sjs_boxrenderer* copyoption26 = &sjt_value13;
        if (copyoption26 != 0) {
            _parent->_topdownrenderer._refCount = 1;
#line 25 "lib/ui/crossHairsElement.sj"
            sjf_boxrenderer_copy(&_parent->_topdownrenderer, copyoption26);
        } else {
            _parent->_topdownrenderer._refCount = -1;
        }
    }

    if ((_parent->_leftrightrenderer._refCount != -1 ? &_parent->_leftrightrenderer : 0) == 0) {
        sjt_value14._refCount = 1;
        sjt_value14.rect._refCount = 1;
#line 32 "lib/ui/crossHairsElement.sj"
        sjt_value14.rect.x = (&_parent->_rect)->x;
#line 32
        sjt_value14.rect.y = (&_parent->_point)->y;
#line 32
        sjt_value14.rect.w = (&_parent->_rect)->w;
#line 32
        sjt_value14.rect.h = 1;
#line 32
        sjf_rect(&sjt_value14.rect);
#line 32
        sjt_value14.color._refCount = 1;
#line 31
        sjf_color_copy(&sjt_value14.color, &_parent->color);
#line 31
        sjf_boxrenderer(&sjt_value14);
#line 31
        if (_parent->_leftrightrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_parent->_leftrightrenderer); }
;
#line 31
        sjs_boxrenderer* copyoption27 = &sjt_value14;
        if (copyoption27 != 0) {
            _parent->_leftrightrenderer._refCount = 1;
#line 31 "lib/ui/crossHairsElement.sj"
            sjf_boxrenderer_copy(&_parent->_leftrightrenderer, copyoption27);
        } else {
            _parent->_leftrightrenderer._refCount = -1;
        }
    }

    if ((_parent->_topdownrenderer._refCount != -1 ? &_parent->_topdownrenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam445 = 0;
        sjs_boxrenderer* sjt_parent252 = 0;

#line 8 "lib/ui/boxRenderer.sj"
        sjt_parent252 = (_parent->_topdownrenderer._refCount != -1 ? &_parent->_topdownrenderer : 0);
#line 23 "lib/ui/crossHairsElement.sj"
        sjt_functionParam445 = scene;
#line 23
        sjf_boxrenderer_render(sjt_parent252, sjt_functionParam445);
    }

    if ((_parent->_leftrightrenderer._refCount != -1 ? &_parent->_leftrightrenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam446 = 0;
        sjs_boxrenderer* sjt_parent253 = 0;

#line 8 "lib/ui/boxRenderer.sj"
        sjt_parent253 = (_parent->_leftrightrenderer._refCount != -1 ? &_parent->_leftrightrenderer : 0);
#line 23 "lib/ui/crossHairsElement.sj"
        sjt_functionParam446 = scene;
#line 23
        sjf_boxrenderer_render(sjt_parent253, sjt_functionParam446);
    }

    if (sjt_value13._refCount == 1) { sjf_boxrenderer_destroy(&sjt_value13); }
;
    if (sjt_value14._refCount == 1) { sjf_boxrenderer_destroy(&sjt_value14); }
;
}

void sjf_crosshairselement_setrect(sjs_crosshairselement* _parent, sjs_rect* rect_) {
    bool result13;
    bool sjt_capture52;
    sjs_rect* sjt_functionParam444 = 0;
    sjs_rect* sjt_parent251 = 0;

#line 15 "lib/ui/rect.sj"
    sjt_parent251 = &_parent->_rect;
#line 14 "lib/ui/crossHairsElement.sj"
    sjt_functionParam444 = rect_;
#line 14
    sjf_rect_isequal(sjt_parent251, sjt_functionParam444, &sjt_capture52);
#line 15
    result13 = !sjt_capture52;
    if (result13) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 14 "lib/ui/crossHairsElement.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
#line 14
        if (_parent->_topdownrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_parent->_topdownrenderer); }
;
#line 17
        _parent->_topdownrenderer._refCount = -1;
#line 17
        if (_parent->_leftrightrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_parent->_leftrightrenderer); }
;
#line 18
        _parent->_leftrightrenderer._refCount = -1;
    }
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent167 = 0;

#line 9 "lib/common/debug.sj"
    sjt_parent167 = data;
#line 9
    sjf_string_nullterminate(sjt_parent167);
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

void sjf_f32_compare(float l, float r, int32_t* _return) {
    if (l == r) {
#line 117 "lib/common/f32.sj"
        (*_return) = 0;
    } else {
        if (l < r) {
            int32_t result3;

#line 119 "lib/common/f32.sj"
            result3 = -1;
#line 119
            (*_return) = result3;
        } else {
#line 121 "lib/common/f32.sj"
            (*_return) = 1;
        }
    }
}

void sjf_f32_cos(float v, float* _return) {
    float sjv_result;

#line 12 "lib/common/f32.sj"
    sjv_result = 0.0f;
#line 14
    sjv_result = cosf(v);
#line 11
    (*_return) = sjv_result;
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

void sjf_f32_sin(float v, float* _return) {
    float sjv_result;

#line 20 "lib/common/f32.sj"
    sjv_result = 0.0f;
#line 22
    sjv_result = sinf(v);
#line 19
    (*_return) = sjv_result;
}

void sjf_f32_sqrt(float v, float* _return) {
    float sjv_result;

#line 4 "lib/common/f32.sj"
    sjv_result = 0.0f;
#line 6
    sjv_result = sqrtf(v);
#line 3
    (*_return) = sjv_result;
}

void sjf_f32_tan(float v, float* _return) {
    float sjv_result;

#line 28 "lib/common/f32.sj"
    sjv_result = 0.0f;
#line 30
    sjv_result = tanf(v);
#line 27
    (*_return) = sjv_result;
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
#line 1 "lib/ui/fillLayout.sj"
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
#line 1
    _this->margin._refCount = 1;
#line 1
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 1
    _this->effect = _from->effect;
    if (_this->effect._parent != 0) {
        _this->effect._parent->_refCount++;
    }

#line 1
    _this->_rect._refCount = 1;
#line 1
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
    sjs_array_heap_iface_element* sjt_functionParam26 = 0;
    sjs_mouseevent* sjt_parent23 = 0;

#line 55 "lib/ui/fillLayout.sj"
    sjt_parent23 = mouseevent;
#line 56
    sjt_functionParam26 = &_parent->children;
#line 56
    sjf_mouseevent_firechildren(sjt_parent23, sjt_functionParam26, _return);
}

void sjf_filllayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 87;
}

void sjf_filllayout_getrect(sjs_filllayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 17 "lib/ui/fillLayout.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_filllayout_getrect_heap(sjs_filllayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 17 "lib/ui/fillLayout.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_filllayout_getsize(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t i;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    sjs_margin* sjt_functionParam12 = 0;
    sjs_margin* sjt_functionParam15 = 0;
    sjs_size* sjt_parent4 = 0;
    sjs_size* sjt_parent8 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
#line 2 "lib/ui/size.sj"
    sjv_size.w = 0;
#line 3
    sjv_size.h = 0;
#line 3
    sjf_size(&sjv_size);
#line 7 "lib/ui/fillLayout.sj"
    sjt_parent4 = maxsize;
#line 9
    sjt_functionParam12 = &_parent->margin;
#line 9
    sjf_size_subtractmargin(sjt_parent4, sjt_functionParam12, &sjv_innersize);
#line 10
    sjt_forStart1 = 0;
#line 10
    sjt_forEnd1 = (&_parent->children)->count;
#line 10
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_size sjt_call4 = { -1 };
        sjs_size sjt_funcold1 = { -1 };
        int32_t sjt_functionParam13;
        sjs_size* sjt_functionParam14 = 0;
        sjs_size* sjt_interfaceParam1 = 0;
        sjs_array_heap_iface_element* sjt_parent5 = 0;
        sjs_size* sjt_parent6 = 0;
        sji_element sjt_parent7 = { 0 };
        sji_element sjv_child = { 0 };

#line 7 "lib/common/array.sj"
        sjt_parent5 = &_parent->children;
#line 10 "lib/ui/fillLayout.sj"
        sjt_functionParam13 = i;
#line 10
        sjf_array_heap_iface_element_getat_heap(sjt_parent5, sjt_functionParam13, &sjv_child);
#line 10
        sjt_funcold1._refCount = 1;
#line 12 "lib/ui/size.sj"
        sjf_size_copy(&sjt_funcold1, &sjv_size);
#line 12
        sjt_parent6 = &sjv_size;
#line 2 "lib/ui/element.sj"
        sjt_parent7 = sjv_child;
#line 12 "lib/ui/fillLayout.sj"
        sjt_interfaceParam1 = &sjv_innersize;
#line 12
        sjt_parent7._vtbl->getsize(sjt_parent7._parent, sjt_interfaceParam1, &sjt_call4);
#line 12
        sjt_functionParam14 = &sjt_call4;
#line 12
        sjf_size_max(sjt_parent6, sjt_functionParam14, &sjt_funcold1);
#line 12
        if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
#line 12 "lib/ui/size.sj"
        sjf_size_copy(&sjv_size, &sjt_funcold1);
#line 10 "lib/ui/fillLayout.sj"
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call4._refCount == 1) { sjf_size_destroy(&sjt_call4); }
;
        if (sjt_funcold1._refCount == 1) { sjf_size_destroy(&sjt_funcold1); }
;
    }

#line 19 "lib/ui/size.sj"
    sjt_parent8 = &sjv_size;
#line 14 "lib/ui/fillLayout.sj"
    sjt_functionParam15 = &_parent->margin;
#line 14
    sjf_size_addmargin(sjt_parent8, sjt_functionParam15, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_filllayout_getsize_heap(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t i;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;
    sjs_margin* sjt_functionParam16 = 0;
    sjs_margin* sjt_functionParam19 = 0;
    sjs_size* sjt_parent13 = 0;
    sjs_size* sjt_parent9 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
#line 2 "lib/ui/size.sj"
    sjv_size.w = 0;
#line 3
    sjv_size.h = 0;
#line 3
    sjf_size(&sjv_size);
#line 7 "lib/ui/fillLayout.sj"
    sjt_parent9 = maxsize;
#line 9
    sjt_functionParam16 = &_parent->margin;
#line 9
    sjf_size_subtractmargin(sjt_parent9, sjt_functionParam16, &sjv_innersize);
#line 10
    sjt_forStart2 = 0;
#line 10
    sjt_forEnd2 = (&_parent->children)->count;
#line 10
    i = sjt_forStart2;
    while (i < sjt_forEnd2) {
        sjs_size sjt_call5 = { -1 };
        sjs_size sjt_funcold2 = { -1 };
        int32_t sjt_functionParam17;
        sjs_size* sjt_functionParam18 = 0;
        sjs_size* sjt_interfaceParam2 = 0;
        sjs_array_heap_iface_element* sjt_parent10 = 0;
        sjs_size* sjt_parent11 = 0;
        sji_element sjt_parent12 = { 0 };
        sji_element sjv_child = { 0 };

#line 7 "lib/common/array.sj"
        sjt_parent10 = &_parent->children;
#line 10 "lib/ui/fillLayout.sj"
        sjt_functionParam17 = i;
#line 10
        sjf_array_heap_iface_element_getat_heap(sjt_parent10, sjt_functionParam17, &sjv_child);
#line 10
        sjt_funcold2._refCount = 1;
#line 12 "lib/ui/size.sj"
        sjf_size_copy(&sjt_funcold2, &sjv_size);
#line 12
        sjt_parent11 = &sjv_size;
#line 2 "lib/ui/element.sj"
        sjt_parent12 = sjv_child;
#line 12 "lib/ui/fillLayout.sj"
        sjt_interfaceParam2 = &sjv_innersize;
#line 12
        sjt_parent12._vtbl->getsize(sjt_parent12._parent, sjt_interfaceParam2, &sjt_call5);
#line 12
        sjt_functionParam18 = &sjt_call5;
#line 12
        sjf_size_max(sjt_parent11, sjt_functionParam18, &sjt_funcold2);
#line 12
        if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
#line 12 "lib/ui/size.sj"
        sjf_size_copy(&sjv_size, &sjt_funcold2);
#line 10 "lib/ui/fillLayout.sj"
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call5._refCount == 1) { sjf_size_destroy(&sjt_call5); }
;
        if (sjt_funcold2._refCount == 1) { sjf_size_destroy(&sjt_funcold2); }
;
    }

#line 19 "lib/ui/size.sj"
    sjt_parent13 = &sjv_size;
#line 14 "lib/ui/fillLayout.sj"
    sjt_functionParam19 = &_parent->margin;
#line 14
    sjf_size_addmargin_heap(sjt_parent13, sjt_functionParam19, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_filllayout_heap(sjs_filllayout* _this) {
}

void sjf_filllayout_render(sjs_filllayout* _parent, sjs_scene2d* scene) {
    if ((_parent->effect._parent != 0)) {
        sji_effect ifValue3 = { 0 };
        sjs_scene2d* sjt_interfaceParam6 = 0;
        cb_scene2d_void sjt_interfaceParam7;
        sji_effect sjt_parent18 = { 0 };

#line 41 "lib/ui/fillLayout.sj"
        ifValue3 = _parent->effect;
        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount++;
        }

#line 4 "lib/ui/effect.sj"
        sjt_parent18 = ifValue3;
#line 40 "lib/ui/fillLayout.sj"
        sjt_interfaceParam6 = scene;
#line 42
        sjt_interfaceParam7._parent = (sjs_object*)_parent;
#line 42
        sjt_interfaceParam7._cb = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_renderinner;
#line 42
        sjt_parent18._vtbl->render(sjt_parent18._parent, sjt_interfaceParam6, sjt_interfaceParam7);

        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount--;
            if (ifValue3._parent->_refCount <= 0) {
                ifValue3._vtbl->destroy(ifValue3._parent);
                free(ifValue3._parent);
            }
        }
    } else {
        sjs_scene2d* sjt_functionParam24 = 0;

#line 40 "lib/ui/fillLayout.sj"
        sjt_functionParam24 = scene;
#line 40
        sjf_filllayout_renderinner(_parent, sjt_functionParam24);
    }
}

void sjf_filllayout_renderinner(sjs_filllayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;

#line 49 "lib/ui/fillLayout.sj"
    sjt_forStart4 = 0;
#line 49
    sjt_forEnd4 = (&_parent->children)->count;
#line 49
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        int32_t sjt_functionParam23;
        sjs_scene2d* sjt_interfaceParam8 = 0;
        sjs_array_heap_iface_element* sjt_parent19 = 0;
        sji_element sjt_parent20 = { 0 };
        sji_element sjv_child = { 0 };

#line 7 "lib/common/array.sj"
        sjt_parent19 = &_parent->children;
#line 49 "lib/ui/fillLayout.sj"
        sjt_functionParam23 = i;
#line 49
        sjf_array_heap_iface_element_getat_heap(sjt_parent19, sjt_functionParam23, &sjv_child);
#line 5 "lib/ui/element.sj"
        sjt_parent20 = sjv_child;
#line 48 "lib/ui/fillLayout.sj"
        sjt_interfaceParam8 = scene;
#line 51
        sjt_parent20._vtbl->render(sjt_parent20._parent, sjt_interfaceParam8);
#line 49
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
    sjs_margin* sjt_functionParam20 = 0;
    sjs_rect* sjt_parent14 = 0;
    sjs_rect sjv_innerrect = { -1 };

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 19 "lib/ui/fillLayout.sj"
    sjf_rect_copy(&_parent->_rect, rect_);
#line 7 "lib/ui/rect.sj"
    sjt_parent14 = &_parent->_rect;
#line 21 "lib/ui/fillLayout.sj"
    sjt_functionParam20 = &_parent->margin;
#line 21
    sjf_rect_subtractmargin(sjt_parent14, sjt_functionParam20, &sjv_innerrect);
    if ((_parent->effect._parent != 0)) {
        sji_effect ifValue1 = { 0 };
        sjs_rect* sjt_interfaceParam3 = 0;
        cb_rect_void sjt_interfaceParam4;
        sji_effect sjt_parent15 = { 0 };

#line 23 "lib/ui/fillLayout.sj"
        ifValue1 = _parent->effect;
        if (ifValue1._parent != 0) {
            ifValue1._parent->_refCount++;
        }

#line 3 "lib/ui/effect.sj"
        sjt_parent15 = ifValue1;
#line 24 "lib/ui/fillLayout.sj"
        sjt_interfaceParam3 = &sjv_innerrect;
#line 24
        sjt_interfaceParam4._parent = (sjs_object*)_parent;
#line 24
        sjt_interfaceParam4._cb = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrectinner;
#line 24
        sjt_parent15._vtbl->setrect(sjt_parent15._parent, sjt_interfaceParam3, sjt_interfaceParam4);

        if (ifValue1._parent != 0) {
            ifValue1._parent->_refCount--;
            if (ifValue1._parent->_refCount <= 0) {
                ifValue1._vtbl->destroy(ifValue1._parent);
                free(ifValue1._parent);
            }
        }
    } else {
        sjs_rect* sjt_functionParam22 = 0;

#line 26 "lib/ui/fillLayout.sj"
        sjt_functionParam22 = &sjv_innerrect;
#line 26
        sjf_filllayout_setrectinner(_parent, sjt_functionParam22);
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
;
}

void sjf_filllayout_setrectinner(sjs_filllayout* _parent, sjs_rect* innerrect) {
    int32_t i;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;

#line 33 "lib/ui/fillLayout.sj"
    sjt_forStart3 = 0;
#line 33
    sjt_forEnd3 = (&_parent->children)->count;
#line 33
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        int32_t sjt_functionParam21;
        sjs_rect* sjt_interfaceParam5 = 0;
        sjs_array_heap_iface_element* sjt_parent16 = 0;
        sji_element sjt_parent17 = { 0 };
        sji_element sjv_child = { 0 };

#line 7 "lib/common/array.sj"
        sjt_parent16 = &_parent->children;
#line 33 "lib/ui/fillLayout.sj"
        sjt_functionParam21 = i;
#line 33
        sjf_array_heap_iface_element_getat_heap(sjt_parent16, sjt_functionParam21, &sjv_child);
#line 4 "lib/ui/element.sj"
        sjt_parent17 = sjv_child;
#line 32 "lib/ui/fillLayout.sj"
        sjt_interfaceParam5 = innerrect;
#line 35
        sjt_parent17._vtbl->setrect(sjt_parent17._parent, sjt_interfaceParam5);
#line 33
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
    if (sjt_capture3) {
#line 29 "lib/ui/font.sj"
        (*_return) = (_parent->size == x->size);
    } else {
#line 29 "lib/ui/font.sj"
        (*_return) = false;
    }
}

void sjf_framebuffer(sjs_framebuffer* _this) {
}

void sjf_framebuffer_copy(sjs_framebuffer* _this, sjs_framebuffer* _from) {
    _this->size._refCount = 1;
#line 1 "lib/ui/framebuffer.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 1
    _this->id = _from->id;
#line 8
    _this->id = _from->id;
#line 9
    glid_retain(_this->id);
}

void sjf_framebuffer_destroy(sjs_framebuffer* _this) {
#line 13 "lib/ui/framebuffer.sj"
    if (glid_release(_this->id)) {
#line 14
        glDeleteFramebuffers(1, &_this->id);
#line 15
    }
#line 15
    if (_this->size._refCount == 1) { sjf_size_destroy(&_this->size); }
;
}

void sjf_framebuffer_heap(sjs_framebuffer* _this) {
}

void sjf_glbindrenderbuffer(sjs_renderbuffer* renderbuffer) {
#line 272 "lib/ui/gl.sj"
    glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer->id);
}

void sjf_glbindtexture(int32_t t, sjs_texture* texture) {
#line 173 "lib/ui/gl.sj"
    glBindTexture(t, texture->id);
}

void sjf_glblendfunc(int32_t sfactor, int32_t dfactor) {
#line 285 "lib/ui/gl.sj"
    glBlendFunc(sfactor, dfactor);
}

void sjf_glcheckframebufferstatus(int32_t* _return) {
    int32_t sjv_status;

#line 263 "lib/ui/gl.sj"
    sjv_status = sjv_glframebufferstatus_gl_framebuffer_unsupported;
#line 265
    sjv_status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
#line 262
    (*_return) = sjv_status;
}

void sjf_glclearcolor(sjs_color* color) {
#line 279 "lib/ui/gl.sj"
    glClearColor(color->r, color->g, color->b, color->a);
}

void sjf_gldisable(int32_t feature) {
#line 119 "lib/ui/gl.sj"
    glDisable(feature);
}

void sjf_glenable(int32_t feature) {
#line 113 "lib/ui/gl.sj"
    glEnable(feature);
}

void sjf_glframebufferrenderbuffer(int32_t attachment, sjs_renderbuffer* renderbuffer) {
#line 258 "lib/ui/gl.sj"
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, renderbuffer->id);
}

void sjf_glframebuffertexture2d(int32_t attachment, int32_t target, sjs_texture* texture, int32_t level) {
#line 238 "lib/ui/gl.sj"
    glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, target, texture->id, level);
}

void sjf_glgenframebuffer(sjs_size* size, sjs_framebuffer* _return) {
    uint32_t sjv_id;

#line 209 "lib/ui/gl.sj"
    sjv_id = (uint32_t)0u;
#line 211
    glGenFramebuffers(1, &sjv_id);
#line 211
    _return->_refCount = 1;
#line 211
    _return->size._refCount = 1;
#line 208
    sjf_size_copy(&_return->size, size);
#line 213
    _return->id = sjv_id;
#line 213
    sjf_framebuffer(_return);
}

void sjf_glgenframebuffer_heap(sjs_size* size, sjs_framebuffer** _return) {
    uint32_t sjv_id;

#line 209 "lib/ui/gl.sj"
    sjv_id = (uint32_t)0u;
#line 211
    glGenFramebuffers(1, &sjv_id);
#line 211
    (*_return) = (sjs_framebuffer*)malloc(sizeof(sjs_framebuffer));
#line 211
    (*_return)->_refCount = 1;
#line 211
    (*_return)->size._refCount = 1;
#line 208
    sjf_size_copy(&(*_return)->size, size);
#line 213
    (*_return)->id = sjv_id;
#line 213
    sjf_framebuffer_heap((*_return));
}

void sjf_glgenrenderbuffer(sjs_size* size, sjs_renderbuffer* _return) {
    uint32_t sjv_id;

#line 243 "lib/ui/gl.sj"
    sjv_id = (uint32_t)0u;
#line 245
    glGenRenderbuffers(1, &sjv_id); 
#line 245
    _return->_refCount = 1;
#line 245
    _return->size._refCount = 1;
#line 242
    sjf_size_copy(&_return->size, size);
#line 247
    _return->id = sjv_id;
#line 247
    sjf_renderbuffer(_return);
}

void sjf_glgenrenderbuffer_heap(sjs_size* size, sjs_renderbuffer** _return) {
    uint32_t sjv_id;

#line 243 "lib/ui/gl.sj"
    sjv_id = (uint32_t)0u;
#line 245
    glGenRenderbuffers(1, &sjv_id); 
#line 245
    (*_return) = (sjs_renderbuffer*)malloc(sizeof(sjs_renderbuffer));
#line 245
    (*_return)->_refCount = 1;
#line 245
    (*_return)->size._refCount = 1;
#line 242
    sjf_size_copy(&(*_return)->size, size);
#line 247
    (*_return)->id = sjv_id;
#line 247
    sjf_renderbuffer_heap((*_return));
}

void sjf_glgentexture(sjs_size* size, sjs_texture* _return) {
    uint32_t sjv_id;

#line 217 "lib/ui/gl.sj"
    sjv_id = (uint32_t)0u;
#line 219
    glGenTextures(1, &sjv_id);
#line 219
    _return->_refCount = 1;
#line 219
    _return->size._refCount = 1;
#line 216
    sjf_size_copy(&_return->size, size);
#line 221
    _return->id = sjv_id;
#line 221
    sjf_texture(_return);
}

void sjf_glgentexture_heap(sjs_size* size, sjs_texture** _return) {
    uint32_t sjv_id;

#line 217 "lib/ui/gl.sj"
    sjv_id = (uint32_t)0u;
#line 219
    glGenTextures(1, &sjv_id);
#line 219
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
#line 219
    (*_return)->_refCount = 1;
#line 219
    (*_return)->size._refCount = 1;
#line 216
    sjf_size_copy(&(*_return)->size, size);
#line 221
    (*_return)->id = sjv_id;
#line 221
    sjf_texture_heap((*_return));
}

void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return) {
#line 179 "lib/ui/gl.sj"
    int result = glGetUniformLocation(shader->id, (char*)name->data.data);
#line 180
    #line 178 "lib/ui/gl.sj"
(*_return) = result;
return;;
}

void sjf_glpopframebuffer(sjs_framebuffer* framebuffer) {
    sjs_string sjt_call13 = { -1 };
    int32_t sjt_capture22;
    uint32_t sjt_capture23;
    int32_t sjt_capture24;
    int32_t sjt_capture25;
    int32_t sjt_functionParam151;
    int32_t sjt_functionParam153;
    sjs_list_u32* sjt_parent78 = 0;
    sjs_list_u32* sjt_parent79 = 0;
    sjs_list_u32* sjt_parent80 = 0;
    sjs_list_u32* sjt_parent81 = 0;
    sjs_list_u32* sjt_parent82 = 0;
    uint32_t sjv_id;

#line 8 "lib/common/list.sj"
    sjt_parent78 = &sjv_glframebuffers;
#line 4
    sjt_parent79 = &sjv_glframebuffers;
#line 4
    sjf_list_u32_getcount(sjt_parent79, &sjt_capture22);
#line 155 "lib/ui/gl.sj"
    sjt_functionParam151 = sjt_capture22 - 1;
#line 155
    sjf_list_u32_getat(sjt_parent78, sjt_functionParam151, &sjt_capture23);
    if (sjt_capture23 != framebuffer->id) {
        sjs_string* sjt_functionParam152 = 0;

        sjt_call13._refCount = 1;
#line 156 "lib/ui/gl.sj"
        sjt_call13.count = 33;
#line 156
        sjt_call13.data._refCount = 1;
#line 156
        sjt_call13.data.datasize = 33;
#line 156
        sjt_call13.data.data = (void*)sjg_string17;
#line 156
        sjt_call13.data.isglobal = true;
#line 156
        sjt_call13.data.count = 33;
#line 156
        sjf_array_char(&sjt_call13.data);
#line 14 "lib/common/string.sj"
        sjt_call13._isnullterminated = false;
#line 14
        sjf_string(&sjt_call13);
#line 156 "lib/ui/gl.sj"
        sjt_functionParam152 = &sjt_call13;
#line 156
        sjf_halt(sjt_functionParam152);
    }

#line 53 "lib/common/list.sj"
    sjt_parent80 = &sjv_glframebuffers;
#line 4
    sjt_parent81 = &sjv_glframebuffers;
#line 4
    sjf_list_u32_getcount(sjt_parent81, &sjt_capture24);
#line 158 "lib/ui/gl.sj"
    sjt_functionParam153 = sjt_capture24 - 1;
#line 158
    sjf_list_u32_removeat(sjt_parent80, sjt_functionParam153);
#line 4 "lib/common/list.sj"
    sjt_parent82 = &sjv_glframebuffers;
#line 4
    sjf_list_u32_getcount(sjt_parent82, &sjt_capture25);
    if (sjt_capture25 > 0) {
        int32_t sjt_capture26;
        int32_t sjt_functionParam154;
        sjs_list_u32* sjt_parent83 = 0;
        sjs_list_u32* sjt_parent84 = 0;

#line 8 "lib/common/list.sj"
        sjt_parent83 = &sjv_glframebuffers;
#line 4
        sjt_parent84 = &sjv_glframebuffers;
#line 4
        sjf_list_u32_getcount(sjt_parent84, &sjt_capture26);
#line 159 "lib/ui/gl.sj"
        sjt_functionParam154 = sjt_capture26 - 1;
#line 159
        sjf_list_u32_getat(sjt_parent83, sjt_functionParam154, &sjv_id);
    } else {
#line 159 "lib/ui/gl.sj"
        sjv_id = (uint32_t)0u;
    }

#line 161 "lib/ui/gl.sj"
    glBindFramebuffer(GL_FRAMEBUFFER, sjv_id);

    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
}

void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect) {
    bool result4;
    sjs_string sjt_call10 = { -1 };
    sjs_rect sjt_call9 = { -1 };
    int32_t sjt_capture17;
    bool sjt_capture18;
    int32_t sjt_capture19;
    int32_t sjt_capture20;
    int32_t sjt_functionParam100;
    int32_t sjt_functionParam94;
    sjs_rect* sjt_functionParam95 = 0;
    sjs_rect* sjt_parent57 = 0;
    sjs_list_rect* sjt_parent60 = 0;
    sjs_list_rect* sjt_parent61 = 0;
    sjs_list_rect* sjt_parent65 = 0;
    sjs_list_rect* sjt_parent66 = 0;
    sjs_list_rect* sjt_parent67 = 0;
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
    sjt_parent60 = &sjv_glviewports;
#line 4
    sjt_parent61 = &sjv_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent61, &sjt_capture17);
#line 135 "lib/ui/gl.sj"
    sjt_functionParam94 = sjt_capture17 - 1;
#line 135
    sjf_list_rect_getat(sjt_parent60, sjt_functionParam94, &sjt_call9);
#line 135
    sjt_parent57 = &sjt_call9;
#line 135
    sjt_functionParam95 = &sjv_oldrect;
#line 135
    sjf_rect_isequal(sjt_parent57, sjt_functionParam95, &sjt_capture18);
#line 135
    result4 = !sjt_capture18;
    if (result4) {
        sjs_string* sjt_functionParam99 = 0;

        sjt_call10._refCount = 1;
#line 136 "lib/ui/gl.sj"
        sjt_call10.count = 30;
#line 136
        sjt_call10.data._refCount = 1;
#line 136
        sjt_call10.data.datasize = 30;
#line 136
        sjt_call10.data.data = (void*)sjg_string16;
#line 136
        sjt_call10.data.isglobal = true;
#line 136
        sjt_call10.data.count = 30;
#line 136
        sjf_array_char(&sjt_call10.data);
#line 14 "lib/common/string.sj"
        sjt_call10._isnullterminated = false;
#line 14
        sjf_string(&sjt_call10);
#line 136 "lib/ui/gl.sj"
        sjt_functionParam99 = &sjt_call10;
#line 136
        sjf_halt(sjt_functionParam99);
    }

#line 53 "lib/common/list.sj"
    sjt_parent65 = &sjv_glviewports;
#line 4
    sjt_parent66 = &sjv_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent66, &sjt_capture19);
#line 138 "lib/ui/gl.sj"
    sjt_functionParam100 = sjt_capture19 - 1;
#line 138
    sjf_list_rect_removeat(sjt_parent65, sjt_functionParam100);
#line 4 "lib/common/list.sj"
    sjt_parent67 = &sjv_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent67, &sjt_capture20);
    if (sjt_capture20 > 0) {
        int32_t sjt_capture21;
        int32_t sjt_functionParam101;
        sjs_list_rect* sjt_parent68 = 0;
        sjs_list_rect* sjt_parent69 = 0;

#line 8 "lib/common/list.sj"
        sjt_parent68 = &sjv_glviewports;
#line 4
        sjt_parent69 = &sjv_glviewports;
#line 4
        sjf_list_rect_getcount(sjt_parent69, &sjt_capture21);
#line 139 "lib/ui/gl.sj"
        sjt_functionParam101 = sjt_capture21 - 1;
#line 139
        sjf_list_rect_getat(sjt_parent68, sjt_functionParam101, &sjv_newrect);
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

    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
;
    if (sjt_call9._refCount == 1) { sjf_rect_destroy(&sjt_call9); }
;
    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
;
    if (sjv_oldrect._refCount == 1) { sjf_rect_destroy(&sjv_oldrect); }
;
}

void sjf_glpushframebuffer(sjs_framebuffer* framebuffer) {
    uint32_t sjt_functionParam118;
    sjs_list_u32* sjt_parent76 = 0;

#line 44 "lib/common/list.sj"
    sjt_parent76 = &sjv_glframebuffers;
#line 148 "lib/ui/gl.sj"
    sjt_functionParam118 = framebuffer->id;
#line 148
    sjf_list_u32_add(sjt_parent76, sjt_functionParam118);
#line 150
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->id);
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect* sjt_functionParam60 = 0;
    sjs_list_rect* sjt_parent46 = 0;
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
    sjt_parent46 = &sjv_glviewports;
#line 127 "lib/ui/gl.sj"
    sjt_functionParam60 = &sjv_newrect;
#line 127
    sjf_list_rect_add(sjt_parent46, sjt_functionParam60);
#line 129
    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
;
}

void sjf_glrenderbufferstorage(int32_t format, sjs_size* size) {
#line 252 "lib/ui/gl.sj"
    glRenderbufferStorage(GL_RENDERBUFFER, format, size->w, size->h);
}

void sjf_glteximage2d(int32_t t, int32_t level, int32_t format, sjs_size* size, int32_t datatype, void* data) {
#line 232 "lib/ui/gl.sj"
    glTexImage2D(t, level, format, size->w, size->h, 0, format, datatype, data);
}

void sjf_gltexparameteri(int32_t t, int32_t attribute, int32_t val) {
#line 226 "lib/ui/gl.sj"
    glTexParameteri(t, attribute, val);
}

void sjf_gluniformi32(int32_t loc, int32_t v) {
#line 198 "lib/ui/gl.sj"
    glUniform1i(loc, v);
}

void sjf_gluniformmat4(int32_t loc, sjs_mat4* m) {
#line 186 "lib/ui/gl.sj"
    glUniformMatrix4fv(loc, 1, 0, (GLfloat*)&m->m00);
}

void sjf_gluniformvec3(int32_t loc, sjs_vec3* v) {
#line 192 "lib/ui/gl.sj"
    glUniform3fv(loc, 1, (GLfloat*)&v->x);
}

void sjf_gluseprogram(sjs_shader* shader) {
#line 167 "lib/ui/gl.sj"
    glUseProgram(shader->id);
}

void sjf_halt(sjs_string* reason) {
    sjs_string* sjt_parent64 = 0;

#line 1 "lib/common/halt.sj"
    sjt_parent64 = reason;
#line 1
    sjf_string_nullterminate(sjt_parent64);
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
                delete_cb weakptrcb11 = { &kh_value(p, k), weakptr_clear };
if (kh_value(p, k) != 0) { weakptr_cb_remove(kh_value(p, k), weakptrcb11); }
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

void sjf_hash_fontkey_weak_font_heap(sjs_hash_fontkey_weak_font* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(fontkey_weak_font_hash_type);
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
                delete_cb weakptrcb10 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb10); }
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

void sjf_hash_string_weak_iface_element_heap(sjs_hash_string_weak_iface_element* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_element_hash_type);
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
                delete_cb weakptrcb9 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb9); }
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

void sjf_hash_string_weak_iface_model_setat(sjs_hash_string_weak_iface_model* _parent, sjs_string* key, sji_model val) {
#line 40 "lib/common/hash.sj"
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;
#line 42
    #if true
#line 43
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, *key);
#line 44
    #else
#line 45
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, key);
#line 46
    #endif
#line 48
    if (k != kh_end(p)) {            
#line 49
    delete_cb weakptrcb12 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_remove(kh_val(p, k)._parent, weakptrcb12); }
;
#line 50
}
#line 52
int ret;
#line 53
#if true
#line 54
k = kh_put(string_weak_iface_model_hash_type, _parent->_hash, *key, &ret);
#line 55
#else
#line 56
k = kh_put(string_weak_iface_model_hash_type, _parent->_hash, key, &ret);
#line 57
#endif
#line 59
if (!ret) kh_del(string_weak_iface_model_hash_type, p, k);
#line 61
#if false
#line 62
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovekey };
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
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovevalue };
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
delete_cb weakptrcb13 = { &kh_val(p, k)._parent, weakptr_clear };
#line 38
if (kh_val(p, k)._parent != 0) { weakptr_cb_add(kh_val(p, k)._parent, weakptrcb13); }
;
#line 75
#endif
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

void sjf_hash_type_bool_getat(sjs_hash_type_bool* _parent, int32_t key, bool_option* _return) {
#line 23 "lib/common/hash.sj"
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
#line 25
    #if false
#line 26
    khiter_t k = kh_get(type_bool_hash_type, p, *key);
#line 27
    #else
#line 28
    khiter_t k = kh_get(type_bool_hash_type, p, key);
#line 29
    #endif
#line 31
    if (k == kh_end(p)) {
#line 32
        #line 22 "lib/common/hash.sj"
(*_return) = bool_empty;
return;
#line 33
    }
#line 34
    #line 22 "lib/common/hash.sj"
_return->isvalid = true;
#line 22
_return->value = kh_val(p, k);
return;;
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
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
    bool sjt_capture49;
    sjs_rect sjt_funcold21 = { -1 };
    sjs_size sjv_size = { -1 };

    if ((&_this->rect)->w == 0) {
#line 6 "lib/ui/image.sj"
        sjt_capture49 = ((&_this->rect)->h == 0);
    } else {
#line 6 "lib/ui/image.sj"
        sjt_capture49 = false;
    }

    if (sjt_capture49) {
        sjs_texture* sjt_parent241 = 0;

#line 1 "lib/ui/image.sj"
        sjt_parent241 = &_this->texture;
#line 1
        sjf_texture_getsize(sjt_parent241, &sjv_size);
#line 1
        sjt_funcold21._refCount = 1;
#line 1 "lib/ui/rect.sj"
        sjf_rect_copy(&sjt_funcold21, &_this->rect);
#line 1
        sjt_funcold21._refCount = 1;
#line 8 "lib/ui/image.sj"
        sjt_funcold21.x = 0;
#line 8
        sjt_funcold21.y = 0;
#line 8
        sjt_funcold21.w = (&sjv_size)->w;
#line 8
        sjt_funcold21.h = (&sjv_size)->h;
#line 8
        sjf_rect(&sjt_funcold21);
#line 8
        if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
#line 1 "lib/ui/rect.sj"
        sjf_rect_copy(&_this->rect, &sjt_funcold21);
    }

    if (sjt_funcold21._refCount == 1) { sjf_rect_destroy(&sjt_funcold21); }
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
    bool sjt_capture50;
    sjs_rect sjt_funcold22 = { -1 };
    sjs_size sjv_size = { -1 };

    if ((&_this->rect)->w == 0) {
#line 6 "lib/ui/image.sj"
        sjt_capture50 = ((&_this->rect)->h == 0);
    } else {
#line 6 "lib/ui/image.sj"
        sjt_capture50 = false;
    }

    if (sjt_capture50) {
        sjs_texture* sjt_parent242 = 0;

#line 5 "lib/ui/texture.sj"
        sjt_parent242 = &_this->texture;
#line 5
        sjf_texture_getsize(sjt_parent242, &sjv_size);
#line 5
        sjt_funcold22._refCount = 1;
#line 1 "lib/ui/rect.sj"
        sjf_rect_copy(&sjt_funcold22, &_this->rect);
#line 1
        sjt_funcold22._refCount = 1;
#line 8 "lib/ui/image.sj"
        sjt_funcold22.x = 0;
#line 8
        sjt_funcold22.y = 0;
#line 8
        sjt_funcold22.w = (&sjv_size)->w;
#line 8
        sjt_funcold22.h = (&sjv_size)->h;
#line 8
        sjf_rect(&sjt_funcold22);
#line 8
        if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
#line 1 "lib/ui/rect.sj"
        sjf_rect_copy(&_this->rect, &sjt_funcold22);
    }

    if (sjt_funcold22._refCount == 1) { sjf_rect_destroy(&sjt_funcold22); }
;
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
;
}

void sjf_imageelement(sjs_imageelement* _this) {
}

void sjf_imageelement_as_sji_element(sjs_imageelement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_imageelement_element_vtbl;
}

void sjf_imageelement_asinterface(sjs_imageelement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_imageelement_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_imageelement_copy(sjs_imageelement* _this, sjs_imageelement* _from) {
    _this->image._refCount = 1;
#line 7 "lib/ui/imageElement.sj"
    sjf_image_copy(&_this->image, &_from->image);
#line 7
    _this->margin._refCount = 1;
#line 7
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 7
    _this->stretch = _from->stretch;
#line 7
    _this->_rect._refCount = 1;
#line 7
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 7
    sjs_imagerenderer* copyoption22 = (_from->_imagerenderer._refCount != -1 ? &_from->_imagerenderer : 0);
    if (copyoption22 != 0) {
        _this->_imagerenderer._refCount = 1;
#line 7 "lib/ui/imageElement.sj"
        sjf_imagerenderer_copy(&_this->_imagerenderer, copyoption22);
    } else {
        _this->_imagerenderer._refCount = -1;
    }
}

void sjf_imageelement_destroy(sjs_imageelement* _this) {
    if (_this->image._refCount == 1) { sjf_image_destroy(&_this->image); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
    if (_this->_imagerenderer._refCount == 1) { sjf_imagerenderer_destroy(&_this->_imagerenderer); }
;
}

void sjf_imageelement_firemouseevent(sjs_imageelement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
#line 74 "lib/ui/imageElement.sj"
    (*_return) = true;
}

void sjf_imageelement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 247;
}

void sjf_imageelement_getrect(sjs_imageelement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 18 "lib/ui/imageElement.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_imageelement_getrect_heap(sjs_imageelement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 18 "lib/ui/imageElement.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_imageelement_getsize(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 15 "lib/ui/imageElement.sj"
    _return->w = maxsize->w;
#line 15
    _return->h = maxsize->h;
#line 15
    sjf_size(_return);
}

void sjf_imageelement_getsize_heap(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 15 "lib/ui/imageElement.sj"
    (*_return)->w = maxsize->w;
#line 15
    (*_return)->h = maxsize->h;
#line 15
    sjf_size_heap((*_return));
}

void sjf_imageelement_heap(sjs_imageelement* _this) {
}

void sjf_imageelement_render(sjs_imageelement* _parent, sjs_scene2d* scene) {
    sjs_imagerenderer sjt_value12 = { -1 };
    sjs_rect sjv_r = { -1 };

    if ((_parent->_imagerenderer._refCount != -1 ? &_parent->_imagerenderer : 0) == 0) {
        sjs_margin* sjt_functionParam417 = 0;
        sjs_rect* sjt_parent244 = 0;
        int32_t underscore3;

#line 7 "lib/ui/rect.sj"
        sjt_parent244 = &_parent->_rect;
#line 30 "lib/ui/imageElement.sj"
        sjt_functionParam417 = &_parent->margin;
#line 30
        sjf_rect_subtractmargin(sjt_parent244, sjt_functionParam417, &sjv_r);
#line 31
        underscore3 = _parent->stretch;
        if (underscore3 == sjv_imagestretch_fill) {
        } else {
            if (underscore3 == sjv_imagestretch_center) {
                sjs_size sjt_call111 = { -1 };
                sjs_rect sjt_funcold23 = { -1 };
                sjs_size* sjt_functionParam418 = 0;
                sjs_size* sjt_parent245 = 0;
                sjs_texture* sjt_parent246 = 0;
                sjs_size sjv_finalsize = { -1 };
                sjs_size sjv_s = { -1 };

                sjv_s._refCount = 1;
#line 34 "lib/ui/imageElement.sj"
                sjv_s.w = (&sjv_r)->w;
#line 34
                sjv_s.h = (&sjv_r)->h;
#line 34
                sjf_size(&sjv_s);
#line 5 "lib/ui/size.sj"
                sjt_parent245 = &sjv_s;
#line 5 "lib/ui/texture.sj"
                sjt_parent246 = &(&_parent->image)->texture;
#line 5
                sjf_texture_getsize(sjt_parent246, &sjt_call111);
#line 35 "lib/ui/imageElement.sj"
                sjt_functionParam418 = &sjt_call111;
#line 35
                sjf_size_min(sjt_parent245, sjt_functionParam418, &sjv_finalsize);
#line 35
                sjt_funcold23._refCount = 1;
#line 1 "lib/ui/rect.sj"
                sjf_rect_copy(&sjt_funcold23, &sjv_r);
#line 1
                sjt_funcold23._refCount = 1;
#line 37 "lib/ui/imageElement.sj"
                sjt_funcold23.x = ((&sjv_r)->w - (&sjv_finalsize)->w) / 2;
#line 38
                sjt_funcold23.y = ((&sjv_r)->h - (&sjv_finalsize)->h) / 2;
#line 36
                sjt_funcold23.w = (&sjv_finalsize)->w;
#line 36
                sjt_funcold23.h = (&sjv_finalsize)->h;
#line 36
                sjf_rect(&sjt_funcold23);
#line 36
                if (sjv_r._refCount == 1) { sjf_rect_destroy(&sjv_r); }
;
#line 1 "lib/ui/rect.sj"
                sjf_rect_copy(&sjv_r, &sjt_funcold23);

                if (sjt_call111._refCount == 1) { sjf_size_destroy(&sjt_call111); }
;
                if (sjt_funcold23._refCount == 1) { sjf_rect_destroy(&sjt_funcold23); }
;
                if (sjv_finalsize._refCount == 1) { sjf_size_destroy(&sjv_finalsize); }
;
                if (sjv_s._refCount == 1) { sjf_size_destroy(&sjv_s); }
;
            } else {
                if (underscore3 == sjv_imagestretch_aspectratio) {
                    sjs_size sjt_call112 = { -1 };
                    sjs_size sjt_call113 = { -1 };
                    int32_t sjt_cast40;
                    int32_t sjt_cast41;
                    int32_t sjt_cast42;
                    int32_t sjt_cast43;
                    sjs_rect sjt_funcold24 = { -1 };
                    sjs_texture* sjt_parent247 = 0;
                    sjs_texture* sjt_parent248 = 0;
                    sjs_size sjv_finalsize = { -1 };
                    float sjv_imageaspectratio;
                    float sjv_rectaspectratio;

#line 5 "lib/ui/texture.sj"
                    sjt_parent247 = &(&_parent->image)->texture;
#line 5
                    sjf_texture_getsize(sjt_parent247, &sjt_call112);
#line 45 "lib/ui/imageElement.sj"
                    sjt_cast40 = (&sjt_call112)->w;
#line 5 "lib/ui/texture.sj"
                    sjt_parent248 = &(&_parent->image)->texture;
#line 5
                    sjf_texture_getsize(sjt_parent248, &sjt_call113);
#line 45 "lib/ui/imageElement.sj"
                    sjt_cast41 = (&sjt_call113)->h;
#line 45
                    sjv_imageaspectratio = (float)sjt_cast40 / (float)sjt_cast41;
#line 46
                    sjt_cast42 = (&sjv_r)->w;
#line 46
                    sjt_cast43 = (&sjv_r)->h;
#line 46
                    sjv_rectaspectratio = (float)sjt_cast42 / (float)sjt_cast43;
                    if (sjv_imageaspectratio > sjv_rectaspectratio) {
                        float sjt_cast44;
                        int32_t sjt_cast45;

                        sjv_finalsize._refCount = 1;
#line 48 "lib/ui/imageElement.sj"
                        sjv_finalsize.w = (&sjv_r)->w;
#line 48
                        sjt_cast45 = (&sjv_r)->h;
#line 48
                        sjt_cast44 = (float)sjt_cast45 / sjv_imageaspectratio;
#line 48
                        sjv_finalsize.h = (int32_t)sjt_cast44;
#line 48
                        sjf_size(&sjv_finalsize);
                    } else {
                        float sjt_cast46;
                        int32_t sjt_cast47;

                        sjv_finalsize._refCount = 1;
#line 50 "lib/ui/imageElement.sj"
                        sjt_cast47 = (&sjv_r)->w;
#line 50
                        sjt_cast46 = (float)sjt_cast47 * sjv_imageaspectratio;
#line 50
                        sjv_finalsize.w = (int32_t)sjt_cast46;
#line 50
                        sjv_finalsize.h = (&sjv_r)->h;
#line 50
                        sjf_size(&sjv_finalsize);
                    }

#line 46
                    sjt_funcold24._refCount = 1;
#line 1 "lib/ui/rect.sj"
                    sjf_rect_copy(&sjt_funcold24, &sjv_r);
#line 1
                    sjt_funcold24._refCount = 1;
#line 53 "lib/ui/imageElement.sj"
                    sjt_funcold24.x = ((&sjv_r)->w - (&sjv_finalsize)->w) / 2;
#line 54
                    sjt_funcold24.y = ((&sjv_r)->h - (&sjv_finalsize)->h) / 2;
#line 52
                    sjt_funcold24.w = (&sjv_finalsize)->w;
#line 52
                    sjt_funcold24.h = (&sjv_finalsize)->h;
#line 52
                    sjf_rect(&sjt_funcold24);
#line 52
                    if (sjv_r._refCount == 1) { sjf_rect_destroy(&sjv_r); }
;
#line 1 "lib/ui/rect.sj"
                    sjf_rect_copy(&sjv_r, &sjt_funcold24);

                    if (sjt_call112._refCount == 1) { sjf_size_destroy(&sjt_call112); }
;
                    if (sjt_call113._refCount == 1) { sjf_size_destroy(&sjt_call113); }
;
                    if (sjt_funcold24._refCount == 1) { sjf_rect_destroy(&sjt_funcold24); }
;
                    if (sjv_finalsize._refCount == 1) { sjf_size_destroy(&sjv_finalsize); }
;
                }
            }
        }

#line 31
        sjt_value12._refCount = 1;
#line 31
        sjt_value12.rect._refCount = 1;
#line 62
        sjf_rect_copy(&sjt_value12.rect, &sjv_r);
#line 62
        sjt_value12.image._refCount = 1;
#line 62
        sjf_image_copy(&sjt_value12.image, &_parent->image);
#line 62
        sjf_imagerenderer(&sjt_value12);
#line 62
        if (_parent->_imagerenderer._refCount == 1) { sjf_imagerenderer_destroy(&_parent->_imagerenderer); }
;
#line 62
        sjs_imagerenderer* copyoption23 = &sjt_value12;
        if (copyoption23 != 0) {
            _parent->_imagerenderer._refCount = 1;
#line 62 "lib/ui/imageElement.sj"
            sjf_imagerenderer_copy(&_parent->_imagerenderer, copyoption23);
        } else {
            _parent->_imagerenderer._refCount = -1;
        }
    }

    if ((_parent->_imagerenderer._refCount != -1 ? &_parent->_imagerenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam440 = 0;
        sjs_imagerenderer* sjt_parent249 = 0;

#line 8 "lib/ui/imageRenderer.sj"
        sjt_parent249 = (_parent->_imagerenderer._refCount != -1 ? &_parent->_imagerenderer : 0);
#line 28 "lib/ui/imageElement.sj"
        sjt_functionParam440 = scene;
#line 28
        sjf_imagerenderer_render(sjt_parent249, sjt_functionParam440);
    }

    if (sjt_value12._refCount == 1) { sjf_imagerenderer_destroy(&sjt_value12); }
;
    if (sjv_r._refCount == 1) { sjf_rect_destroy(&sjv_r); }
;
}

void sjf_imageelement_setrect(sjs_imageelement* _parent, sjs_rect* rect_) {
    bool result12;
    bool sjt_capture51;
    sjs_rect* sjt_functionParam416 = 0;
    sjs_rect* sjt_parent243 = 0;

#line 15 "lib/ui/rect.sj"
    sjt_parent243 = &_parent->_rect;
#line 20 "lib/ui/imageElement.sj"
    sjt_functionParam416 = rect_;
#line 20
    sjf_rect_isequal(sjt_parent243, sjt_functionParam416, &sjt_capture51);
#line 21
    result12 = !sjt_capture51;
    if (result12) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 20 "lib/ui/imageElement.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
#line 20
        if (_parent->_imagerenderer._refCount == 1) { sjf_imagerenderer_destroy(&_parent->_imagerenderer); }
;
#line 23
        _parent->_imagerenderer._refCount = -1;
    }
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
    sjs_string sjt_call114 = { -1 };
    sjs_string sjt_call115 = { -1 };
    sjs_string sjt_call116 = { -1 };
    sjs_string sjt_call117 = { -1 };
    int32_t sjt_functionParam419;
    sjs_texture* sjt_functionParam420 = 0;
    sjs_shader* sjt_functionParam421 = 0;
    int32_t sjt_functionParam422;
    int32_t sjt_functionParam423;
    int32_t sjt_functionParam424;
    sjs_shader* sjt_functionParam425 = 0;
    sjs_string* sjt_functionParam426 = 0;
    int32_t sjt_functionParam427;
    int32_t sjt_functionParam428;
    sjs_shader* sjt_functionParam429 = 0;
    sjs_string* sjt_functionParam430 = 0;
    sjs_mat4* sjt_functionParam431 = 0;
    int32_t sjt_functionParam432;
    sjs_shader* sjt_functionParam433 = 0;
    sjs_string* sjt_functionParam434 = 0;
    sjs_mat4* sjt_functionParam435 = 0;
    int32_t sjt_functionParam436;
    sjs_shader* sjt_functionParam437 = 0;
    sjs_string* sjt_functionParam438 = 0;
    sjs_mat4* sjt_functionParam439 = 0;

#line 9 "lib/ui/imageRenderer.sj"
    sjt_functionParam419 = sjv_gltexture_gl_texture_2d;
#line 9
    sjt_functionParam420 = &(&_parent->image)->texture;
#line 9
    sjf_glbindtexture(sjt_functionParam419, sjt_functionParam420);
#line 10
    sjt_functionParam421 = &sjv_imageshader;
#line 10
    sjf_gluseprogram(sjt_functionParam421);
#line 11
    sjt_functionParam422 = sjv_glblendfunctype_gl_src_alpha;
#line 11
    sjt_functionParam423 = sjv_glblendfunctype_gl_one_minus_src_alpha;
#line 11
    sjf_glblendfunc(sjt_functionParam422, sjt_functionParam423);
#line 12
    sjt_functionParam425 = &sjv_imageshader;
#line 12
    sjt_call114._refCount = 1;
#line 12
    sjt_call114.count = 7;
#line 12
    sjt_call114.data._refCount = 1;
#line 12
    sjt_call114.data.datasize = 7;
#line 12
    sjt_call114.data.data = (void*)sjg_string42;
#line 12
    sjt_call114.data.isglobal = true;
#line 12
    sjt_call114.data.count = 7;
#line 12
    sjf_array_char(&sjt_call114.data);
#line 14 "lib/common/string.sj"
    sjt_call114._isnullterminated = false;
#line 14
    sjf_string(&sjt_call114);
#line 12 "lib/ui/imageRenderer.sj"
    sjt_functionParam426 = &sjt_call114;
#line 12
    sjf_glgetuniformlocation(sjt_functionParam425, sjt_functionParam426, &sjt_functionParam424);
#line 12
    sjt_functionParam427 = 0;
#line 12
    sjf_gluniformi32(sjt_functionParam424, sjt_functionParam427);
#line 13
    sjt_functionParam429 = &sjv_imageshader;
#line 13
    sjt_call115._refCount = 1;
#line 13
    sjt_call115.count = 5;
#line 13
    sjt_call115.data._refCount = 1;
#line 13
    sjt_call115.data.datasize = 5;
#line 13
    sjt_call115.data.data = (void*)sjg_string43;
#line 13
    sjt_call115.data.isglobal = true;
#line 13
    sjt_call115.data.count = 5;
#line 13
    sjf_array_char(&sjt_call115.data);
#line 14 "lib/common/string.sj"
    sjt_call115._isnullterminated = false;
#line 14
    sjf_string(&sjt_call115);
#line 13 "lib/ui/imageRenderer.sj"
    sjt_functionParam430 = &sjt_call115;
#line 13
    sjf_glgetuniformlocation(sjt_functionParam429, sjt_functionParam430, &sjt_functionParam428);
#line 13
    sjt_functionParam431 = &scene->model;
#line 13
    sjf_gluniformmat4(sjt_functionParam428, sjt_functionParam431);
#line 14
    sjt_functionParam433 = &sjv_imageshader;
#line 14
    sjt_call116._refCount = 1;
#line 14
    sjt_call116.count = 4;
#line 14
    sjt_call116.data._refCount = 1;
#line 14
    sjt_call116.data.datasize = 4;
#line 14
    sjt_call116.data.data = (void*)sjg_string44;
#line 14
    sjt_call116.data.isglobal = true;
#line 14
    sjt_call116.data.count = 4;
#line 14
    sjf_array_char(&sjt_call116.data);
#line 14 "lib/common/string.sj"
    sjt_call116._isnullterminated = false;
#line 14
    sjf_string(&sjt_call116);
#line 14 "lib/ui/imageRenderer.sj"
    sjt_functionParam434 = &sjt_call116;
#line 14
    sjf_glgetuniformlocation(sjt_functionParam433, sjt_functionParam434, &sjt_functionParam432);
#line 14
    sjt_functionParam435 = &scene->view;
#line 14
    sjf_gluniformmat4(sjt_functionParam432, sjt_functionParam435);
#line 15
    sjt_functionParam437 = &sjv_imageshader;
#line 15
    sjt_call117._refCount = 1;
#line 15
    sjt_call117.count = 10;
#line 15
    sjt_call117.data._refCount = 1;
#line 15
    sjt_call117.data.datasize = 10;
#line 15
    sjt_call117.data.data = (void*)sjg_string20;
#line 15
    sjt_call117.data.isglobal = true;
#line 15
    sjt_call117.data.count = 10;
#line 15
    sjf_array_char(&sjt_call117.data);
#line 14 "lib/common/string.sj"
    sjt_call117._isnullterminated = false;
#line 14
    sjf_string(&sjt_call117);
#line 15 "lib/ui/imageRenderer.sj"
    sjt_functionParam438 = &sjt_call117;
#line 15
    sjf_glgetuniformlocation(sjt_functionParam437, sjt_functionParam438, &sjt_functionParam436);
#line 15
    sjt_functionParam439 = &scene->projection;
#line 15
    sjf_gluniformmat4(sjt_functionParam436, sjt_functionParam439);
#line 17
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);

    if (sjt_call114._refCount == 1) { sjf_string_destroy(&sjt_call114); }
;
    if (sjt_call115._refCount == 1) { sjf_string_destroy(&sjt_call115); }
;
    if (sjt_call116._refCount == 1) { sjf_string_destroy(&sjt_call116); }
;
    if (sjt_call117._refCount == 1) { sjf_string_destroy(&sjt_call117); }
;
}

void sjf_intersecttriangle(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3* _return) {
    sjs_vec3* sjt_functionParam242 = 0;
    sjs_vec3* sjt_functionParam243 = 0;
    sjs_vec3* sjt_functionParam244 = 0;
    sjs_vec3* sjt_functionParam245 = 0;
    sjs_vec3* sjt_parent127 = 0;
    sjs_vec3* sjt_parent128 = 0;
    sjs_vec3* sjt_parent129 = 0;
    sjs_vec3* sjt_parent130 = 0;
    sjs_vec3 sjt_value2 = { -1 };
    float sjv_det;
    sjs_vec3 sjv_edge1 = { -1 };
    sjs_vec3 sjv_edge2 = { -1 };
    sjs_vec3 sjv_pvec = { -1 };
    sjs_vec3 sjv_qvec = { -1 };
    sjs_vec3 sjv_tvec = { -1 };

#line 135 "lib/ui/vertexBuffer.sj"
    sjt_parent127 = v1;
#line 135
    sjt_functionParam242 = v0;
#line 135
    sjf_vec3_subtract(sjt_parent127, sjt_functionParam242, &sjv_edge1);
#line 135
    sjt_parent128 = v2;
#line 135
    sjt_functionParam243 = v0;
#line 135
    sjf_vec3_subtract(sjt_parent128, sjt_functionParam243, &sjv_edge2);
#line 135
    sjt_parent129 = dir;
#line 139
    sjt_functionParam244 = &sjv_edge2;
#line 139
    sjf_vec3_cross(sjt_parent129, sjt_functionParam244, &sjv_pvec);
#line 55 "lib/ui/vec3.sj"
    sjt_parent130 = &sjv_edge1;
#line 140 "lib/ui/vertexBuffer.sj"
    sjt_functionParam245 = &sjv_pvec;
#line 140
    sjf_vec3_dot(sjt_parent130, sjt_functionParam245, &sjv_det);
    if (sjv_det > 0.0f) {
        sjs_vec3* sjt_functionParam246 = 0;
        sjs_vec3* sjt_parent131 = 0;

#line 135 "lib/ui/vertexBuffer.sj"
        sjt_parent131 = orig;
#line 135
        sjt_functionParam246 = v0;
#line 135
        sjf_vec3_subtract(sjt_parent131, sjt_functionParam246, &sjv_tvec);
    } else {
        sjs_vec3* sjt_functionParam247 = 0;
        sjs_vec3* sjt_parent132 = 0;

#line 144 "lib/ui/vertexBuffer.sj"
        sjv_det = 0.0f - sjv_det;
#line 135
        sjt_parent132 = v0;
#line 135
        sjt_functionParam247 = orig;
#line 135
        sjf_vec3_subtract(sjt_parent132, sjt_functionParam247, &sjv_tvec);
    }

    if (sjv_det < 0.0001f) {
#line 149 "lib/ui/vertexBuffer.sj"
        _return->_refCount = -1;
    } else {
        sjs_vec3* sjt_functionParam248 = 0;
        sjs_vec3* sjt_parent133 = 0;
        float sjv_u;

#line 55 "lib/ui/vec3.sj"
        sjt_parent133 = &sjv_tvec;
#line 151 "lib/ui/vertexBuffer.sj"
        sjt_functionParam248 = &sjv_pvec;
#line 151
        sjf_vec3_dot(sjt_parent133, sjt_functionParam248, &sjv_u);
        if ((sjv_u < 0.0f) || (sjv_u > sjv_det)) {
#line 153 "lib/ui/vertexBuffer.sj"
            _return->_refCount = -1;
        } else {
            sjs_vec3* sjt_functionParam249 = 0;
            sjs_vec3* sjt_functionParam250 = 0;
            sjs_vec3* sjt_parent134 = 0;
            sjs_vec3* sjt_parent135 = 0;
            float sjv_v;

#line 47 "lib/ui/vec3.sj"
            sjt_parent134 = &sjv_tvec;
#line 155 "lib/ui/vertexBuffer.sj"
            sjt_functionParam249 = &sjv_edge1;
#line 155
            sjf_vec3_cross(sjt_parent134, sjt_functionParam249, &sjv_qvec);
#line 135
            sjt_parent135 = dir;
#line 156
            sjt_functionParam250 = &sjv_qvec;
#line 156
            sjf_vec3_dot(sjt_parent135, sjt_functionParam250, &sjv_v);
            if ((sjv_v < 0.0f) || ((sjv_u + sjv_v) > sjv_det)) {
#line 158 "lib/ui/vertexBuffer.sj"
                _return->_refCount = -1;
            } else {
                sjs_vec3* sjt_functionParam251 = 0;
                sjs_vec3* sjt_parent136 = 0;
                float sjv_finvdet;
                float sjv_t;

#line 55 "lib/ui/vec3.sj"
                sjt_parent136 = &sjv_edge2;
#line 161 "lib/ui/vertexBuffer.sj"
                sjt_functionParam251 = &sjv_qvec;
#line 161
                sjf_vec3_dot(sjt_parent136, sjt_functionParam251, &sjv_t);
#line 162
                sjv_finvdet = 1.0f / sjv_det;
#line 162
                sjt_value2._refCount = 1;
#line 163
                sjt_value2.x = sjv_u * sjv_finvdet;
#line 163
                sjt_value2.y = sjv_v * sjv_finvdet;
#line 163
                sjt_value2.z = sjv_t * sjv_finvdet;
#line 163
                sjf_vec3(&sjt_value2);
#line 163
                sjs_vec3* copyoption15 = &sjt_value2;
                if (copyoption15 != 0) {
                    _return->_refCount = 1;
#line 163 "lib/ui/vertexBuffer.sj"
                    sjf_vec3_copy(_return, copyoption15);
                } else {
                    _return->_refCount = -1;
                }
            }
        }
    }

    if (sjt_value2._refCount == 1) { sjf_vec3_destroy(&sjt_value2); }
;
    if (sjv_edge1._refCount == 1) { sjf_vec3_destroy(&sjv_edge1); }
;
    if (sjv_edge2._refCount == 1) { sjf_vec3_destroy(&sjv_edge2); }
;
    if (sjv_pvec._refCount == 1) { sjf_vec3_destroy(&sjv_pvec); }
;
    if (sjv_qvec._refCount == 1) { sjf_vec3_destroy(&sjv_qvec); }
;
    if (sjv_tvec._refCount == 1) { sjf_vec3_destroy(&sjv_tvec); }
;
}

void sjf_intersecttriangle_heap(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3** _return) {
    sjs_vec3* sjt_functionParam252 = 0;
    sjs_vec3* sjt_functionParam253 = 0;
    sjs_vec3* sjt_functionParam254 = 0;
    sjs_vec3* sjt_functionParam255 = 0;
    sjs_vec3* sjt_parent137 = 0;
    sjs_vec3* sjt_parent138 = 0;
    sjs_vec3* sjt_parent139 = 0;
    sjs_vec3* sjt_parent140 = 0;
    float sjv_det;
    sjs_vec3 sjv_edge1 = { -1 };
    sjs_vec3 sjv_edge2 = { -1 };
    sjs_vec3 sjv_pvec = { -1 };
    sjs_vec3 sjv_qvec = { -1 };
    sjs_vec3 sjv_tvec = { -1 };

#line 135 "lib/ui/vertexBuffer.sj"
    sjt_parent137 = v1;
#line 135
    sjt_functionParam252 = v0;
#line 135
    sjf_vec3_subtract(sjt_parent137, sjt_functionParam252, &sjv_edge1);
#line 135
    sjt_parent138 = v2;
#line 135
    sjt_functionParam253 = v0;
#line 135
    sjf_vec3_subtract(sjt_parent138, sjt_functionParam253, &sjv_edge2);
#line 135
    sjt_parent139 = dir;
#line 139
    sjt_functionParam254 = &sjv_edge2;
#line 139
    sjf_vec3_cross(sjt_parent139, sjt_functionParam254, &sjv_pvec);
#line 55 "lib/ui/vec3.sj"
    sjt_parent140 = &sjv_edge1;
#line 140 "lib/ui/vertexBuffer.sj"
    sjt_functionParam255 = &sjv_pvec;
#line 140
    sjf_vec3_dot(sjt_parent140, sjt_functionParam255, &sjv_det);
    if (sjv_det > 0.0f) {
        sjs_vec3* sjt_functionParam256 = 0;
        sjs_vec3* sjt_parent141 = 0;

#line 135 "lib/ui/vertexBuffer.sj"
        sjt_parent141 = orig;
#line 135
        sjt_functionParam256 = v0;
#line 135
        sjf_vec3_subtract(sjt_parent141, sjt_functionParam256, &sjv_tvec);
    } else {
        sjs_vec3* sjt_functionParam257 = 0;
        sjs_vec3* sjt_parent142 = 0;

#line 144 "lib/ui/vertexBuffer.sj"
        sjv_det = 0.0f - sjv_det;
#line 135
        sjt_parent142 = v0;
#line 135
        sjt_functionParam257 = orig;
#line 135
        sjf_vec3_subtract(sjt_parent142, sjt_functionParam257, &sjv_tvec);
    }

    if (sjv_det < 0.0001f) {
#line 149 "lib/ui/vertexBuffer.sj"
        (*_return) = 0;
        if ((*_return) != 0) {
            (*_return)->_refCount++;
        }
    } else {
        sjs_vec3* sjt_functionParam258 = 0;
        sjs_vec3* sjt_parent143 = 0;
        float sjv_u;

#line 55 "lib/ui/vec3.sj"
        sjt_parent143 = &sjv_tvec;
#line 151 "lib/ui/vertexBuffer.sj"
        sjt_functionParam258 = &sjv_pvec;
#line 151
        sjf_vec3_dot(sjt_parent143, sjt_functionParam258, &sjv_u);
        if ((sjv_u < 0.0f) || (sjv_u > sjv_det)) {
#line 153 "lib/ui/vertexBuffer.sj"
            (*_return) = 0;
            if ((*_return) != 0) {
                (*_return)->_refCount++;
            }
        } else {
            sjs_vec3* sjt_functionParam259 = 0;
            sjs_vec3* sjt_functionParam260 = 0;
            sjs_vec3* sjt_parent144 = 0;
            sjs_vec3* sjt_parent145 = 0;
            float sjv_v;

#line 47 "lib/ui/vec3.sj"
            sjt_parent144 = &sjv_tvec;
#line 155 "lib/ui/vertexBuffer.sj"
            sjt_functionParam259 = &sjv_edge1;
#line 155
            sjf_vec3_cross(sjt_parent144, sjt_functionParam259, &sjv_qvec);
#line 135
            sjt_parent145 = dir;
#line 156
            sjt_functionParam260 = &sjv_qvec;
#line 156
            sjf_vec3_dot(sjt_parent145, sjt_functionParam260, &sjv_v);
            if ((sjv_v < 0.0f) || ((sjv_u + sjv_v) > sjv_det)) {
#line 158 "lib/ui/vertexBuffer.sj"
                (*_return) = 0;
                if ((*_return) != 0) {
                    (*_return)->_refCount++;
                }
            } else {
                sjs_vec3* sjt_functionParam261 = 0;
                sjs_vec3* sjt_parent146 = 0;
                sjs_vec3* sjt_value3 = 0;
                float sjv_finvdet;
                float sjv_t;

#line 55 "lib/ui/vec3.sj"
                sjt_parent146 = &sjv_edge2;
#line 161 "lib/ui/vertexBuffer.sj"
                sjt_functionParam261 = &sjv_qvec;
#line 161
                sjf_vec3_dot(sjt_parent146, sjt_functionParam261, &sjv_t);
#line 162
                sjv_finvdet = 1.0f / sjv_det;
#line 162
                sjt_value3 = (sjs_vec3*)malloc(sizeof(sjs_vec3));
#line 162
                sjt_value3->_refCount = 1;
#line 163
                sjt_value3->x = sjv_u * sjv_finvdet;
#line 163
                sjt_value3->y = sjv_v * sjv_finvdet;
#line 163
                sjt_value3->z = sjv_t * sjv_finvdet;
#line 163
                sjf_vec3_heap(sjt_value3);
#line 163
                (*_return) = sjt_value3;
                if ((*_return) != 0) {
                    (*_return)->_refCount++;
                }

                sjt_value3->_refCount--;
                if (sjt_value3->_refCount <= 0) {
                    weakptr_release(sjt_value3);
                    sjf_vec3_destroy(sjt_value3);
                    free(sjt_value3);
                }
            }
        }
    }

    if (sjv_edge1._refCount == 1) { sjf_vec3_destroy(&sjv_edge1); }
;
    if (sjv_edge2._refCount == 1) { sjf_vec3_destroy(&sjv_edge2); }
;
    if (sjv_pvec._refCount == 1) { sjf_vec3_destroy(&sjv_pvec); }
;
    if (sjv_qvec._refCount == 1) { sjf_vec3_destroy(&sjv_qvec); }
;
    if (sjv_tvec._refCount == 1) { sjf_vec3_destroy(&sjv_tvec); }
;
}

void sjf_lambda1(sjs_lambda1* _this) {
}

void sjf_lambda1_copy(sjs_lambda1* _this, sjs_lambda1* _from) {
#line 88 "lib/ui/scene2dModel.sj"
    _this->lambdaparam1 = _from->lambdaparam1;
#line 88
    _this->lambdaparam2 = _from->lambdaparam2;
}

void sjf_lambda1_destroy(sjs_lambda1* _this) {
}

void sjf_lambda1_heap(sjs_lambda1* _this) {
}

void sjf_lambda1_invoke(sjs_lambda1* _parent, sjs_string* _return) {
    sjs_string sjt_call104 = { -1 };
    sjs_string sjt_call105 = { -1 };
    sjs_string* sjt_functionParam372 = 0;
    sjs_string* sjt_parent220 = 0;
    sjs_mouseevent* sjt_parent221 = 0;

#line 55 "lib/ui/mouse.sj"
    sjt_parent221 = _parent->lambdaparam1;
#line 55
    sjf_mouseevent_asstring(sjt_parent221, &sjt_call104);
#line 88 "lib/ui/scene2dModel.sj"
    sjt_parent220 = &sjt_call104;
#line 88
    sjt_call105._refCount = 1;
#line 88
    sjt_call105.count = 16;
#line 88
    sjt_call105.data._refCount = 1;
#line 88
    sjt_call105.data.datasize = 16;
#line 88
    sjt_call105.data.data = (void*)sjg_string39;
#line 88
    sjt_call105.data.isglobal = true;
#line 88
    sjt_call105.data.count = 16;
#line 88
    sjf_array_char(&sjt_call105.data);
#line 14 "lib/common/string.sj"
    sjt_call105._isnullterminated = false;
#line 14
    sjf_string(&sjt_call105);
#line 88 "lib/ui/scene2dModel.sj"
    sjt_functionParam372 = &sjt_call105;
#line 88
    sjf_string_add(sjt_parent220, sjt_functionParam372, _return);

    if (sjt_call104._refCount == 1) { sjf_string_destroy(&sjt_call104); }
;
    if (sjt_call105._refCount == 1) { sjf_string_destroy(&sjt_call105); }
;
}

void sjf_lambda1_invoke_heap(sjs_lambda1* _parent, sjs_string** _return) {
    sjs_string sjt_call106 = { -1 };
    sjs_string sjt_call107 = { -1 };
    sjs_string* sjt_functionParam373 = 0;
    sjs_string* sjt_parent222 = 0;
    sjs_mouseevent* sjt_parent223 = 0;

#line 55 "lib/ui/mouse.sj"
    sjt_parent223 = _parent->lambdaparam2;
#line 55
    sjf_mouseevent_asstring(sjt_parent223, &sjt_call106);
#line 88 "lib/ui/scene2dModel.sj"
    sjt_parent222 = &sjt_call106;
#line 88
    sjt_call107._refCount = 1;
#line 88
    sjt_call107.count = 16;
#line 88
    sjt_call107.data._refCount = 1;
#line 88
    sjt_call107.data.datasize = 16;
#line 88
    sjt_call107.data.data = (void*)sjg_string39;
#line 88
    sjt_call107.data.isglobal = true;
#line 88
    sjt_call107.data.count = 16;
#line 88
    sjf_array_char(&sjt_call107.data);
#line 14 "lib/common/string.sj"
    sjt_call107._isnullterminated = false;
#line 14
    sjf_string(&sjt_call107);
#line 88 "lib/ui/scene2dModel.sj"
    sjt_functionParam373 = &sjt_call107;
#line 88
    sjf_string_add_heap(sjt_parent222, sjt_functionParam373, _return);

    if (sjt_call106._refCount == 1) { sjf_string_destroy(&sjt_call106); }
;
    if (sjt_call107._refCount == 1) { sjf_string_destroy(&sjt_call107); }
;
}

void sjf_lambda2(sjs_lambda2* _this) {
}

void sjf_lambda2_copy(sjs_lambda2* _this, sjs_lambda2* _from) {
#line 74 "lib/ui/scene2dModel.sj"
    _this->lambdaparam3 = _from->lambdaparam3;
#line 74
    _this->lambdaparam4 = _from->lambdaparam4;
#line 74
    _this->lambdaparam5 = _from->lambdaparam5;
}

void sjf_lambda2_destroy(sjs_lambda2* _this) {
}

void sjf_lambda2_heap(sjs_lambda2* _this) {
}

void sjf_lambda2_invoke(sjs_lambda2* _parent, sjs_string* _return) {
    sjs_string sjt_call59 = { -1 };
    sjs_string sjt_call60 = { -1 };
    sjs_string sjt_call89 = { -1 };
    sjs_string sjt_call90 = { -1 };
    sjs_string* sjt_functionParam357 = 0;
    sjs_string* sjt_functionParam358 = 0;
    sjs_string* sjt_parent190 = 0;
    sjs_string* sjt_parent191 = 0;
    sjs_mouseevent* sjt_parent208 = 0;
    sjs_vec2* sjt_parent213 = 0;

#line 55 "lib/ui/mouse.sj"
    sjt_parent208 = _parent->lambdaparam3;
#line 55
    sjf_mouseevent_asstring(sjt_parent208, &sjt_call60);
#line 74 "lib/ui/scene2dModel.sj"
    sjt_parent191 = &sjt_call60;
#line 74
    sjt_call89._refCount = 1;
#line 74
    sjt_call89.count = 4;
#line 74
    sjt_call89.data._refCount = 1;
#line 74
    sjt_call89.data.datasize = 4;
#line 74
    sjt_call89.data.data = (void*)sjg_string40;
#line 74
    sjt_call89.data.isglobal = true;
#line 74
    sjt_call89.data.count = 4;
#line 74
    sjf_array_char(&sjt_call89.data);
#line 14 "lib/common/string.sj"
    sjt_call89._isnullterminated = false;
#line 14
    sjf_string(&sjt_call89);
#line 74 "lib/ui/scene2dModel.sj"
    sjt_functionParam357 = &sjt_call89;
#line 74
    sjf_string_add(sjt_parent191, sjt_functionParam357, &sjt_call59);
#line 74
    sjt_parent190 = &sjt_call59;
#line 5 "lib/ui/vec2.sj"
    sjt_parent213 = _parent->lambdaparam4;
#line 5
    sjf_vec2_asstring(sjt_parent213, &sjt_call90);
#line 74 "lib/ui/scene2dModel.sj"
    sjt_functionParam358 = &sjt_call90;
#line 74
    sjf_string_add(sjt_parent190, sjt_functionParam358, _return);

    if (sjt_call59._refCount == 1) { sjf_string_destroy(&sjt_call59); }
;
    if (sjt_call60._refCount == 1) { sjf_string_destroy(&sjt_call60); }
;
    if (sjt_call89._refCount == 1) { sjf_string_destroy(&sjt_call89); }
;
    if (sjt_call90._refCount == 1) { sjf_string_destroy(&sjt_call90); }
;
}

void sjf_lambda2_invoke_heap(sjs_lambda2* _parent, sjs_string** _return) {
    sjs_string sjt_call100 = { -1 };
    sjs_string sjt_call101 = { -1 };
    sjs_string sjt_call102 = { -1 };
    sjs_string sjt_call99 = { -1 };
    sjs_string* sjt_functionParam367 = 0;
    sjs_string* sjt_functionParam368 = 0;
    sjs_string* sjt_parent214 = 0;
    sjs_string* sjt_parent215 = 0;
    sjs_mouseevent* sjt_parent216 = 0;
    sjs_vec2* sjt_parent217 = 0;

#line 55 "lib/ui/mouse.sj"
    sjt_parent216 = _parent->lambdaparam5;
#line 55
    sjf_mouseevent_asstring(sjt_parent216, &sjt_call100);
#line 74 "lib/ui/scene2dModel.sj"
    sjt_parent215 = &sjt_call100;
#line 74
    sjt_call101._refCount = 1;
#line 74
    sjt_call101.count = 4;
#line 74
    sjt_call101.data._refCount = 1;
#line 74
    sjt_call101.data.datasize = 4;
#line 74
    sjt_call101.data.data = (void*)sjg_string40;
#line 74
    sjt_call101.data.isglobal = true;
#line 74
    sjt_call101.data.count = 4;
#line 74
    sjf_array_char(&sjt_call101.data);
#line 14 "lib/common/string.sj"
    sjt_call101._isnullterminated = false;
#line 14
    sjf_string(&sjt_call101);
#line 74 "lib/ui/scene2dModel.sj"
    sjt_functionParam367 = &sjt_call101;
#line 74
    sjf_string_add(sjt_parent215, sjt_functionParam367, &sjt_call99);
#line 74
    sjt_parent214 = &sjt_call99;
#line 5 "lib/ui/vec2.sj"
    sjt_parent217 = _parent->lambdaparam4;
#line 5
    sjf_vec2_asstring(sjt_parent217, &sjt_call102);
#line 74 "lib/ui/scene2dModel.sj"
    sjt_functionParam368 = &sjt_call102;
#line 74
    sjf_string_add_heap(sjt_parent214, sjt_functionParam368, _return);

    if (sjt_call100._refCount == 1) { sjf_string_destroy(&sjt_call100); }
;
    if (sjt_call101._refCount == 1) { sjf_string_destroy(&sjt_call101); }
;
    if (sjt_call102._refCount == 1) { sjf_string_destroy(&sjt_call102); }
;
    if (sjt_call99._refCount == 1) { sjf_string_destroy(&sjt_call99); }
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
    int32_t sjt_functionParam450;
    sjs_array_heap_iface_animation* sjt_parent258 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent258 = &_parent->array;
#line 8 "lib/common/list.sj"
    sjt_functionParam450 = index;
#line 8
    sjf_array_heap_iface_animation_getat_heap(sjt_parent258, sjt_functionParam450, _return);
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

void sjf_list_heap_iface_model_add(sjs_list_heap_iface_model* _parent, sji_model item) {
    sjs_array_heap_iface_model sjt_funcold19 = { -1 };
    int32_t sjt_functionParam183;
    sji_model sjt_functionParam184 = { 0 };
    sjs_array_heap_iface_model* sjt_parent96 = 0;

    if ((&_parent->array)->count >= (&_parent->array)->datasize) {
        int32_t sjt_functionParam180;
        int32_t sjt_functionParam181;
        int32_t sjt_functionParam182;
        sjs_array_heap_iface_model* sjt_parent95 = 0;

        sjt_funcold19._refCount = 1;
#line 134 "lib/common/array.sj"
        sjf_array_heap_iface_model_copy(&sjt_funcold19, &_parent->array);
#line 134
        sjt_parent95 = &_parent->array;
#line 46 "lib/common/list.sj"
        sjt_functionParam181 = 10;
#line 46
        sjt_functionParam182 = (&_parent->array)->datasize * 2;
#line 46
        sjf_i32_max(sjt_functionParam181, sjt_functionParam182, &sjt_functionParam180);
#line 46
        sjf_array_heap_iface_model_grow(sjt_parent95, sjt_functionParam180, &sjt_funcold19);
#line 46
        if (_parent->array._refCount == 1) { sjf_array_heap_iface_model_destroy(&_parent->array); }
;
#line 134 "lib/common/array.sj"
        sjf_array_heap_iface_model_copy(&_parent->array, &sjt_funcold19);
    }

#line 34 "lib/common/array.sj"
    sjt_parent96 = &_parent->array;
#line 50 "lib/common/list.sj"
    sjt_functionParam183 = (&_parent->array)->count;
#line 44
    sjt_functionParam184 = item;
    if (sjt_functionParam184._parent != 0) {
        sjt_functionParam184._parent->_refCount++;
    }

#line 44
    sjf_array_heap_iface_model_initat(sjt_parent96, sjt_functionParam183, sjt_functionParam184);

    if (sjt_functionParam184._parent != 0) {
        sjt_functionParam184._parent->_refCount--;
        if (sjt_functionParam184._parent->_refCount <= 0) {
            sjt_functionParam184._vtbl->destroy(sjt_functionParam184._parent);
            free(sjt_functionParam184._parent);
        }
    }
    if (sjt_funcold19._refCount == 1) { sjf_array_heap_iface_model_destroy(&sjt_funcold19); }
;
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

void sjf_list_heap_iface_model_getat_heap(sjs_list_heap_iface_model* _parent, int32_t index, sji_model* _return) {
    int32_t sjt_functionParam90;
    sjs_array_heap_iface_model* sjt_parent54 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent54 = &_parent->array;
#line 8 "lib/common/list.sj"
    sjt_functionParam90 = index;
#line 8
    sjf_array_heap_iface_model_getat_heap(sjt_parent54, sjt_functionParam90, _return);
}

void sjf_list_heap_iface_model_getcount(sjs_list_heap_iface_model* _parent, int32_t* _return) {
#line 4 "lib/common/list.sj"
    (*_return) = (&_parent->array)->count;
}

void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this) {
}

void sjf_list_heap_iface_model_sortcb(sjs_list_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb) {
    cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam86;
    sjs_array_heap_iface_model* sjt_parent49 = 0;

#line 243 "lib/common/array.sj"
    sjt_parent49 = &_parent->array;
#line 28 "lib/common/list.sj"
    sjt_functionParam86 = cb;
#line 28
    sjf_array_heap_iface_model_sortcb(sjt_parent49, sjt_functionParam86);
}

void sjf_list_rect(sjs_list_rect* _this) {
}

void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item) {
    sjs_array_rect sjt_funcold6 = { -1 };
    int32_t sjt_functionParam58;
    sjs_rect* sjt_functionParam59 = 0;
    sjs_array_rect* sjt_parent45 = 0;

    if ((&_parent->array)->count >= (&_parent->array)->datasize) {
        int32_t sjt_functionParam55;
        int32_t sjt_functionParam56;
        int32_t sjt_functionParam57;
        sjs_array_rect* sjt_parent44 = 0;

        sjt_funcold6._refCount = 1;
#line 134 "lib/common/array.sj"
        sjf_array_rect_copy(&sjt_funcold6, &_parent->array);
#line 134
        sjt_parent44 = &_parent->array;
#line 46 "lib/common/list.sj"
        sjt_functionParam56 = 10;
#line 46
        sjt_functionParam57 = (&_parent->array)->datasize * 2;
#line 46
        sjf_i32_max(sjt_functionParam56, sjt_functionParam57, &sjt_functionParam55);
#line 46
        sjf_array_rect_grow(sjt_parent44, sjt_functionParam55, &sjt_funcold6);
#line 46
        if (_parent->array._refCount == 1) { sjf_array_rect_destroy(&_parent->array); }
;
#line 134 "lib/common/array.sj"
        sjf_array_rect_copy(&_parent->array, &sjt_funcold6);
    }

#line 34 "lib/common/array.sj"
    sjt_parent45 = &_parent->array;
#line 50 "lib/common/list.sj"
    sjt_functionParam58 = (&_parent->array)->count;
#line 44
    sjt_functionParam59 = item;
#line 44
    sjf_array_rect_initat(sjt_parent45, sjt_functionParam58, sjt_functionParam59);

    if (sjt_funcold6._refCount == 1) { sjf_array_rect_destroy(&sjt_funcold6); }
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
    int32_t sjt_functionParam92;
    sjs_array_rect* sjt_parent58 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent58 = &_parent->array;
#line 8 "lib/common/list.sj"
    sjt_functionParam92 = index;
#line 8
    sjf_array_rect_getat(sjt_parent58, sjt_functionParam92, _return);
}

void sjf_list_rect_getat_heap(sjs_list_rect* _parent, int32_t index, sjs_rect** _return) {
    int32_t sjt_functionParam93;
    sjs_array_rect* sjt_parent59 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent59 = &_parent->array;
#line 8 "lib/common/list.sj"
    sjt_functionParam93 = index;
#line 8
    sjf_array_rect_getat_heap(sjt_parent59, sjt_functionParam93, _return);
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

void sjf_list_u32_add(sjs_list_u32* _parent, uint32_t item) {
    sjs_array_u32 sjt_funcold11 = { -1 };
    int32_t sjt_functionParam116;
    uint32_t sjt_functionParam117;
    sjs_array_u32* sjt_parent75 = 0;

    if ((&_parent->array)->count >= (&_parent->array)->datasize) {
        int32_t sjt_functionParam113;
        int32_t sjt_functionParam114;
        int32_t sjt_functionParam115;
        sjs_array_u32* sjt_parent74 = 0;

        sjt_funcold11._refCount = 1;
#line 134 "lib/common/array.sj"
        sjf_array_u32_copy(&sjt_funcold11, &_parent->array);
#line 134
        sjt_parent74 = &_parent->array;
#line 46 "lib/common/list.sj"
        sjt_functionParam114 = 10;
#line 46
        sjt_functionParam115 = (&_parent->array)->datasize * 2;
#line 46
        sjf_i32_max(sjt_functionParam114, sjt_functionParam115, &sjt_functionParam113);
#line 46
        sjf_array_u32_grow(sjt_parent74, sjt_functionParam113, &sjt_funcold11);
#line 46
        if (_parent->array._refCount == 1) { sjf_array_u32_destroy(&_parent->array); }
;
#line 134 "lib/common/array.sj"
        sjf_array_u32_copy(&_parent->array, &sjt_funcold11);
    }

#line 34 "lib/common/array.sj"
    sjt_parent75 = &_parent->array;
#line 50 "lib/common/list.sj"
    sjt_functionParam116 = (&_parent->array)->count;
#line 44
    sjt_functionParam117 = item;
#line 44
    sjf_array_u32_initat(sjt_parent75, sjt_functionParam116, sjt_functionParam117);

    if (sjt_funcold11._refCount == 1) { sjf_array_u32_destroy(&sjt_funcold11); }
;
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

void sjf_list_u32_getat(sjs_list_u32* _parent, int32_t index, uint32_t* _return) {
    int32_t sjt_functionParam150;
    sjs_array_u32* sjt_parent77 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent77 = &_parent->array;
#line 8 "lib/common/list.sj"
    sjt_functionParam150 = index;
#line 8
    sjf_array_u32_getat(sjt_parent77, sjt_functionParam150, _return);
}

void sjf_list_u32_getcount(sjs_list_u32* _parent, int32_t* _return) {
#line 4 "lib/common/list.sj"
    (*_return) = (&_parent->array)->count;
}

void sjf_list_u32_heap(sjs_list_u32* _this) {
}

void sjf_list_u32_removeat(sjs_list_u32* _parent, int32_t index) {
#line 55 "lib/common/list.sj"
    if (index < 0 || index >= _parent->array.count) {
#line 56
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
#line 57
    }
#line 58
    uint32_t* p = (uint32_t*)_parent->array.data;
#line 59
    ;
#line 60
    if (index != _parent->array.count - 1) {
#line 61
        memcpy(p + index, p + index + 1, (_parent->array.count - index - 1) * sizeof(uint32_t));
#line 62
    }
#line 63
    _parent->array.count--;
}

void sjf_log(sjs_log* _this) {
}

void sjf_log__write(sjs_log* _parent, int32_t level, sjs_hash_type_bool* includes, int32_t t, cb_string_heap_string cb) {
    if (level >= _parent->minlevel) {
        if ((includes != 0)) {
            sjs_hash_type_bool* ifValue8 = 0;
            sjs_string sjt_call31 = { -1 };
            sjs_string sjt_call32 = { -1 };
            sjs_string sjt_call33 = { -1 };
            sjs_string sjt_call34 = { -1 };
            sjs_string sjt_call35 = { -1 };
            sjs_string sjt_call36 = { -1 };
            sjs_string sjt_call44 = { -1 };
            sjs_string sjt_call45 = { -1 };
            sjs_string sjt_call46 = { -1 };
            sjs_string sjt_call47 = { -1 };
            bool sjt_capture41;
            bool_option sjt_capture42;
            int32_t sjt_functionParam292;
            sjs_hash_type_bool* sjt_parent165 = 0;

#line 46 "lib/common/log.sj"
            ifValue8 = includes;
#line 21 "lib/common/hash.sj"
            sjt_parent165 = ifValue8;
#line 46 "lib/common/log.sj"
            sjt_functionParam292 = t;
#line 46
            sjf_hash_type_bool_getat(sjt_parent165, sjt_functionParam292, &sjt_capture42);
            if (sjt_capture42.isvalid) {
                int32_t sjt_functionParam293;
                bool_option sjt_getValue3;
                sjs_hash_type_bool* sjt_parent166 = 0;

#line 21 "lib/common/hash.sj"
                sjt_parent166 = ifValue8;
#line 46 "lib/common/log.sj"
                sjt_functionParam293 = t;
#line 46
                sjf_hash_type_bool_getat(sjt_parent166, sjt_functionParam293, &sjt_getValue3);
#line 49
                sjt_capture41 = sjt_getValue3.value;
            } else {
#line 49 "lib/common/log.sj"
                sjt_capture41 = false;
            }

            if (sjt_capture41) {
                sjs_string* sjt_functionParam294 = 0;
                int32_t sjt_functionParam312;
                sjs_string* sjt_functionParam313 = 0;
                sjs_string* sjt_functionParam314 = 0;
                int32_t sjt_functionParam315;
                sjs_string* sjt_functionParam316 = 0;
                sjs_string* sjt_functionParam317 = 0;
                sjs_string* sjt_parent175 = 0;
                sjs_string* sjt_parent176 = 0;
                sjs_string* sjt_parent177 = 0;
                sjs_string* sjt_parent178 = 0;
                sjs_string* sjt_parent183 = 0;

#line 46 "lib/common/log.sj"
                sjt_functionParam312 = level;
#line 46
                sjf_loglevel_asstring(sjt_functionParam312, &sjt_call36);
#line 50
                sjt_parent183 = &sjt_call36;
#line 50
                sjf_string_touppercase(sjt_parent183, &sjt_call35);
#line 50
                sjt_parent178 = &sjt_call35;
#line 50
                sjt_call44._refCount = 1;
#line 50
                sjt_call44.count = 2;
#line 50
                sjt_call44.data._refCount = 1;
#line 50
                sjt_call44.data.datasize = 2;
#line 50
                sjt_call44.data.data = (void*)sjg_string31;
#line 50
                sjt_call44.data.isglobal = true;
#line 50
                sjt_call44.data.count = 2;
#line 50
                sjf_array_char(&sjt_call44.data);
#line 14 "lib/common/string.sj"
                sjt_call44._isnullterminated = false;
#line 14
                sjf_string(&sjt_call44);
#line 50 "lib/common/log.sj"
                sjt_functionParam313 = &sjt_call44;
#line 50
                sjf_string_add(sjt_parent178, sjt_functionParam313, &sjt_call34);
#line 50
                sjt_parent177 = &sjt_call34;
#line 46
                sjt_functionParam315 = t;
#line 46
                sjf_type_asstring(sjt_functionParam315, &sjt_call45);
#line 50
                sjt_functionParam314 = &sjt_call45;
#line 50
                sjf_string_add(sjt_parent177, sjt_functionParam314, &sjt_call33);
#line 50
                sjt_parent176 = &sjt_call33;
#line 50
                sjt_call46._refCount = 1;
#line 50
                sjt_call46.count = 2;
#line 50
                sjt_call46.data._refCount = 1;
#line 50
                sjt_call46.data.datasize = 2;
#line 50
                sjt_call46.data.data = (void*)sjg_string32;
#line 50
                sjt_call46.data.isglobal = true;
#line 50
                sjt_call46.data.count = 2;
#line 50
                sjf_array_char(&sjt_call46.data);
#line 14 "lib/common/string.sj"
                sjt_call46._isnullterminated = false;
#line 14
                sjf_string(&sjt_call46);
#line 50 "lib/common/log.sj"
                sjt_functionParam316 = &sjt_call46;
#line 50
                sjf_string_add(sjt_parent176, sjt_functionParam316, &sjt_call32);
#line 50
                sjt_parent175 = &sjt_call32;
#line 50
                cb._cb(cb._parent, &sjt_call47);
#line 50
                sjt_functionParam317 = &sjt_call47;
#line 50
                sjf_string_add(sjt_parent175, sjt_functionParam317, &sjt_call31);
#line 50
                sjt_functionParam294 = &sjt_call31;
#line 50
                sjf_debug_writeline(sjt_functionParam294);
            }

            if (sjt_call31._refCount == 1) { sjf_string_destroy(&sjt_call31); }
;
            if (sjt_call32._refCount == 1) { sjf_string_destroy(&sjt_call32); }
;
            if (sjt_call33._refCount == 1) { sjf_string_destroy(&sjt_call33); }
;
            if (sjt_call34._refCount == 1) { sjf_string_destroy(&sjt_call34); }
;
            if (sjt_call35._refCount == 1) { sjf_string_destroy(&sjt_call35); }
;
            if (sjt_call36._refCount == 1) { sjf_string_destroy(&sjt_call36); }
;
            if (sjt_call44._refCount == 1) { sjf_string_destroy(&sjt_call44); }
;
            if (sjt_call45._refCount == 1) { sjf_string_destroy(&sjt_call45); }
;
            if (sjt_call46._refCount == 1) { sjf_string_destroy(&sjt_call46); }
;
            if (sjt_call47._refCount == 1) { sjf_string_destroy(&sjt_call47); }
;
        } else {
            sjs_string sjt_call48 = { -1 };
            sjs_string sjt_call49 = { -1 };
            sjs_string sjt_call50 = { -1 };
            sjs_string sjt_call51 = { -1 };
            sjs_string sjt_call52 = { -1 };
            sjs_string sjt_call53 = { -1 };
            sjs_string sjt_call54 = { -1 };
            sjs_string sjt_call55 = { -1 };
            sjs_string sjt_call56 = { -1 };
            sjs_string sjt_call57 = { -1 };
            sjs_string* sjt_functionParam318 = 0;
            int32_t sjt_functionParam319;
            sjs_string* sjt_functionParam320 = 0;
            sjs_string* sjt_functionParam321 = 0;
            int32_t sjt_functionParam322;
            sjs_string* sjt_functionParam323 = 0;
            sjs_string* sjt_functionParam324 = 0;
            sjs_string* sjt_parent184 = 0;
            sjs_string* sjt_parent185 = 0;
            sjs_string* sjt_parent186 = 0;
            sjs_string* sjt_parent187 = 0;
            sjs_string* sjt_parent188 = 0;

#line 46 "lib/common/log.sj"
            sjt_functionParam319 = level;
#line 46
            sjf_loglevel_asstring(sjt_functionParam319, &sjt_call53);
#line 53
            sjt_parent188 = &sjt_call53;
#line 53
            sjf_string_touppercase(sjt_parent188, &sjt_call52);
#line 53
            sjt_parent187 = &sjt_call52;
#line 53
            sjt_call54._refCount = 1;
#line 53
            sjt_call54.count = 2;
#line 53
            sjt_call54.data._refCount = 1;
#line 53
            sjt_call54.data.datasize = 2;
#line 53
            sjt_call54.data.data = (void*)sjg_string31;
#line 53
            sjt_call54.data.isglobal = true;
#line 53
            sjt_call54.data.count = 2;
#line 53
            sjf_array_char(&sjt_call54.data);
#line 14 "lib/common/string.sj"
            sjt_call54._isnullterminated = false;
#line 14
            sjf_string(&sjt_call54);
#line 53 "lib/common/log.sj"
            sjt_functionParam320 = &sjt_call54;
#line 53
            sjf_string_add(sjt_parent187, sjt_functionParam320, &sjt_call51);
#line 53
            sjt_parent186 = &sjt_call51;
#line 46
            sjt_functionParam322 = t;
#line 46
            sjf_type_asstring(sjt_functionParam322, &sjt_call55);
#line 53
            sjt_functionParam321 = &sjt_call55;
#line 53
            sjf_string_add(sjt_parent186, sjt_functionParam321, &sjt_call50);
#line 53
            sjt_parent185 = &sjt_call50;
#line 53
            sjt_call56._refCount = 1;
#line 53
            sjt_call56.count = 2;
#line 53
            sjt_call56.data._refCount = 1;
#line 53
            sjt_call56.data.datasize = 2;
#line 53
            sjt_call56.data.data = (void*)sjg_string32;
#line 53
            sjt_call56.data.isglobal = true;
#line 53
            sjt_call56.data.count = 2;
#line 53
            sjf_array_char(&sjt_call56.data);
#line 14 "lib/common/string.sj"
            sjt_call56._isnullterminated = false;
#line 14
            sjf_string(&sjt_call56);
#line 53 "lib/common/log.sj"
            sjt_functionParam323 = &sjt_call56;
#line 53
            sjf_string_add(sjt_parent185, sjt_functionParam323, &sjt_call49);
#line 53
            sjt_parent184 = &sjt_call49;
#line 53
            cb._cb(cb._parent, &sjt_call57);
#line 53
            sjt_functionParam324 = &sjt_call57;
#line 53
            sjf_string_add(sjt_parent184, sjt_functionParam324, &sjt_call48);
#line 53
            sjt_functionParam318 = &sjt_call48;
#line 53
            sjf_debug_writeline(sjt_functionParam318);

            if (sjt_call48._refCount == 1) { sjf_string_destroy(&sjt_call48); }
;
            if (sjt_call49._refCount == 1) { sjf_string_destroy(&sjt_call49); }
;
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
    }
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

void sjf_log_trace(sjs_log* _parent, int32_t t, cb_string_heap_string cb) {
    int32_t sjt_functionParam325;
    sjs_hash_type_bool* sjt_functionParam326 = 0;
    int32_t sjt_functionParam327;
    cb_string_heap_string sjt_functionParam328;

#line 23 "lib/common/log.sj"
    sjt_functionParam325 = sjv_loglevel_trace;
#line 23
    sjt_functionParam326 = (_parent->traceincludes._refCount != -1 ? &_parent->traceincludes : 0);
#line 22
    sjt_functionParam327 = t;
#line 22
    sjt_functionParam328 = cb;
#line 22
    sjf_log__write(_parent, sjt_functionParam325, sjt_functionParam326, sjt_functionParam327, sjt_functionParam328);
}

void sjf_loglevel_asstring(int32_t e, sjs_string* _return) {
    int32_t underscore1;

#line 1 "lib/common/log.sj"
    underscore1 = e;
    if (underscore1 == 0) {
        _return->_refCount = 1;
#line 1 "lib/common/log.sj"
        _return->count = 5;
#line 1
        _return->data._refCount = 1;
#line 1
        _return->data.datasize = 5;
#line 1
        _return->data.data = (void*)sjg_string24;
#line 1
        _return->data.isglobal = true;
#line 1
        _return->data.count = 5;
#line 1
        sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    } else {
        if (underscore1 == 1) {
            _return->_refCount = 1;
#line 1 "lib/common/log.sj"
            _return->count = 5;
#line 1
            _return->data._refCount = 1;
#line 1
            _return->data.datasize = 5;
#line 1
            _return->data.data = (void*)sjg_string25;
#line 1
            _return->data.isglobal = true;
#line 1
            _return->data.count = 5;
#line 1
            sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
            _return->_isnullterminated = false;
#line 14
            sjf_string(_return);
        } else {
            if (underscore1 == 2) {
                _return->_refCount = 1;
#line 1 "lib/common/log.sj"
                _return->count = 4;
#line 1
                _return->data._refCount = 1;
#line 1
                _return->data.datasize = 4;
#line 1
                _return->data.data = (void*)sjg_string26;
#line 1
                _return->data.isglobal = true;
#line 1
                _return->data.count = 4;
#line 1
                sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
                _return->_isnullterminated = false;
#line 14
                sjf_string(_return);
            } else {
                if (underscore1 == 3) {
                    _return->_refCount = 1;
#line 1 "lib/common/log.sj"
                    _return->count = 4;
#line 1
                    _return->data._refCount = 1;
#line 1
                    _return->data.datasize = 4;
#line 1
                    _return->data.data = (void*)sjg_string27;
#line 1
                    _return->data.isglobal = true;
#line 1
                    _return->data.count = 4;
#line 1
                    sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
                    _return->_isnullterminated = false;
#line 14
                    sjf_string(_return);
                } else {
                    if (underscore1 == 4) {
                        _return->_refCount = 1;
#line 1 "lib/common/log.sj"
                        _return->count = 5;
#line 1
                        _return->data._refCount = 1;
#line 1
                        _return->data.datasize = 5;
#line 1
                        _return->data.data = (void*)sjg_string28;
#line 1
                        _return->data.isglobal = true;
#line 1
                        _return->data.count = 5;
#line 1
                        sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
                        _return->_isnullterminated = false;
#line 14
                        sjf_string(_return);
                    } else {
                        if (underscore1 == 5) {
                            _return->_refCount = 1;
#line 1 "lib/common/log.sj"
                            _return->count = 5;
#line 1
                            _return->data._refCount = 1;
#line 1
                            _return->data.datasize = 5;
#line 1
                            _return->data.data = (void*)sjg_string29;
#line 1
                            _return->data.isglobal = true;
#line 1
                            _return->data.count = 5;
#line 1
                            sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
                            _return->_isnullterminated = false;
#line 14
                            sjf_string(_return);
                        } else {
                            _return->_refCount = 1;
#line 1 "lib/common/log.sj"
                            _return->count = 0;
#line 1
                            _return->data._refCount = 1;
#line 1
                            _return->data.datasize = 0;
#line 1
                            _return->data.data = (void*)sjg_string30;
#line 1
                            _return->data.isglobal = true;
#line 1
                            _return->data.count = 0;
#line 1
                            sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
                            _return->_isnullterminated = false;
#line 14
                            sjf_string(_return);
                        }
                    }
                }
            }
        }
    }
}

void sjf_loglevel_asstring_heap(int32_t e, sjs_string** _return) {
    int32_t underscore2;

#line 1 "lib/common/log.sj"
    underscore2 = e;
    if (underscore2 == 0) {
        sjs_string sjt_call37 = { -1 };

        sjt_call37._refCount = 1;
#line 1 "lib/common/log.sj"
        sjt_call37.count = 5;
#line 1
        sjt_call37.data._refCount = 1;
#line 1
        sjt_call37.data.datasize = 5;
#line 1
        sjt_call37.data.data = (void*)sjg_string24;
#line 1
        sjt_call37.data.isglobal = true;
#line 1
        sjt_call37.data.count = 5;
#line 1
        sjf_array_char(&sjt_call37.data);
#line 14 "lib/common/string.sj"
        sjt_call37._isnullterminated = false;
#line 14
        sjf_string(&sjt_call37);
#line 14
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
        (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
        sjf_string_copy((*_return), &sjt_call37);

        if (sjt_call37._refCount == 1) { sjf_string_destroy(&sjt_call37); }
;
    } else {
        if (underscore2 == 1) {
            sjs_string sjt_call38 = { -1 };

            sjt_call38._refCount = 1;
#line 1 "lib/common/log.sj"
            sjt_call38.count = 5;
#line 1
            sjt_call38.data._refCount = 1;
#line 1
            sjt_call38.data.datasize = 5;
#line 1
            sjt_call38.data.data = (void*)sjg_string25;
#line 1
            sjt_call38.data.isglobal = true;
#line 1
            sjt_call38.data.count = 5;
#line 1
            sjf_array_char(&sjt_call38.data);
#line 14 "lib/common/string.sj"
            sjt_call38._isnullterminated = false;
#line 14
            sjf_string(&sjt_call38);
#line 14
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
            (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
            sjf_string_copy((*_return), &sjt_call38);

            if (sjt_call38._refCount == 1) { sjf_string_destroy(&sjt_call38); }
;
        } else {
            if (underscore2 == 2) {
                sjs_string sjt_call39 = { -1 };

                sjt_call39._refCount = 1;
#line 1 "lib/common/log.sj"
                sjt_call39.count = 4;
#line 1
                sjt_call39.data._refCount = 1;
#line 1
                sjt_call39.data.datasize = 4;
#line 1
                sjt_call39.data.data = (void*)sjg_string26;
#line 1
                sjt_call39.data.isglobal = true;
#line 1
                sjt_call39.data.count = 4;
#line 1
                sjf_array_char(&sjt_call39.data);
#line 14 "lib/common/string.sj"
                sjt_call39._isnullterminated = false;
#line 14
                sjf_string(&sjt_call39);
#line 14
                (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
                (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
                sjf_string_copy((*_return), &sjt_call39);

                if (sjt_call39._refCount == 1) { sjf_string_destroy(&sjt_call39); }
;
            } else {
                if (underscore2 == 3) {
                    sjs_string sjt_call40 = { -1 };

                    sjt_call40._refCount = 1;
#line 1 "lib/common/log.sj"
                    sjt_call40.count = 4;
#line 1
                    sjt_call40.data._refCount = 1;
#line 1
                    sjt_call40.data.datasize = 4;
#line 1
                    sjt_call40.data.data = (void*)sjg_string27;
#line 1
                    sjt_call40.data.isglobal = true;
#line 1
                    sjt_call40.data.count = 4;
#line 1
                    sjf_array_char(&sjt_call40.data);
#line 14 "lib/common/string.sj"
                    sjt_call40._isnullterminated = false;
#line 14
                    sjf_string(&sjt_call40);
#line 14
                    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
                    (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
                    sjf_string_copy((*_return), &sjt_call40);

                    if (sjt_call40._refCount == 1) { sjf_string_destroy(&sjt_call40); }
;
                } else {
                    if (underscore2 == 4) {
                        sjs_string sjt_call41 = { -1 };

                        sjt_call41._refCount = 1;
#line 1 "lib/common/log.sj"
                        sjt_call41.count = 5;
#line 1
                        sjt_call41.data._refCount = 1;
#line 1
                        sjt_call41.data.datasize = 5;
#line 1
                        sjt_call41.data.data = (void*)sjg_string28;
#line 1
                        sjt_call41.data.isglobal = true;
#line 1
                        sjt_call41.data.count = 5;
#line 1
                        sjf_array_char(&sjt_call41.data);
#line 14 "lib/common/string.sj"
                        sjt_call41._isnullterminated = false;
#line 14
                        sjf_string(&sjt_call41);
#line 14
                        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
                        (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
                        sjf_string_copy((*_return), &sjt_call41);

                        if (sjt_call41._refCount == 1) { sjf_string_destroy(&sjt_call41); }
;
                    } else {
                        if (underscore2 == 5) {
                            sjs_string sjt_call42 = { -1 };

                            sjt_call42._refCount = 1;
#line 1 "lib/common/log.sj"
                            sjt_call42.count = 5;
#line 1
                            sjt_call42.data._refCount = 1;
#line 1
                            sjt_call42.data.datasize = 5;
#line 1
                            sjt_call42.data.data = (void*)sjg_string29;
#line 1
                            sjt_call42.data.isglobal = true;
#line 1
                            sjt_call42.data.count = 5;
#line 1
                            sjf_array_char(&sjt_call42.data);
#line 14 "lib/common/string.sj"
                            sjt_call42._isnullterminated = false;
#line 14
                            sjf_string(&sjt_call42);
#line 14
                            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
                            (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
                            sjf_string_copy((*_return), &sjt_call42);

                            if (sjt_call42._refCount == 1) { sjf_string_destroy(&sjt_call42); }
;
                        } else {
                            sjs_string sjt_call43 = { -1 };

                            sjt_call43._refCount = 1;
#line 1 "lib/common/log.sj"
                            sjt_call43.count = 0;
#line 1
                            sjt_call43.data._refCount = 1;
#line 1
                            sjt_call43.data.datasize = 0;
#line 1
                            sjt_call43.data.data = (void*)sjg_string30;
#line 1
                            sjt_call43.data.isglobal = true;
#line 1
                            sjt_call43.data.count = 0;
#line 1
                            sjf_array_char(&sjt_call43.data);
#line 14 "lib/common/string.sj"
                            sjt_call43._isnullterminated = false;
#line 14
                            sjf_string(&sjt_call43);
#line 14
                            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 14
                            (*_return)->_refCount = 1;
#line 1 "lib/common/log.sj"
                            sjf_string_copy((*_return), &sjt_call43);

                            if (sjt_call43._refCount == 1) { sjf_string_destroy(&sjt_call43); }
;
                        }
                    }
                }
            }
        }
    }
}

void sjf_mainloop(void) {
    bool result15;
    sjs_string sjt_call121 = { -1 };
    sjs_string sjt_call122 = { -1 };
    sjs_string sjt_call123 = { -1 };
    bool sjt_capture58;
    int32_t sjt_functionParam453;
    sjs_size* sjt_functionParam457 = 0;
    sjs_rect* sjt_functionParam458 = 0;
    sjs_scene2d* sjt_interfaceParam21 = 0;
    sjs_animator* sjt_parent262 = 0;
    sjs_windowrenderer* sjt_parent264 = 0;
    sjs_scene2d* sjt_parent265 = 0;
    sjs_scene2d* sjt_parent266 = 0;
    sjs_rect* sjt_parent267 = 0;
    sji_element sjt_parent269 = { 0 };
    sjs_scene2d* sjt_parent270 = 0;
    sjs_windowrenderer* sjt_parent271 = 0;
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
    sjt_parent262 = &sjv_animator;
#line 14 "lib/ui/loop.sj"
    sjt_functionParam453 = sjv_ticks;
#line 14
    sjf_animator_nextframe(sjt_parent262, sjt_functionParam453);
    if (sjv_mainloop_showfps) {
#line 17 "lib/ui/loop.sj"
        sjv_mainloop_frames = sjv_mainloop_frames + 1;
        if ((sjv_mainloop_lasttick + 1000) < sjv_ticks) {
            int32_t sjt_cast50;
            int32_t sjt_cast51;
            sjs_string* sjt_functionParam454 = 0;
            sjs_string* sjt_functionParam455 = 0;
            float sjt_functionParam456;
            sjs_string* sjt_parent263 = 0;
            float sjv_fps;

#line 19 "lib/ui/loop.sj"
            sjt_cast50 = sjv_mainloop_frames;
#line 19
            sjt_cast51 = sjv_ticks - sjv_mainloop_lasttick;
#line 19
            sjv_fps = ((float)sjt_cast50 * 1000.0f) / (float)sjt_cast51;
#line 19
            sjt_call122._refCount = 1;
#line 20
            sjt_call122.count = 5;
#line 20
            sjt_call122.data._refCount = 1;
#line 20
            sjt_call122.data.datasize = 5;
#line 20
            sjt_call122.data.data = (void*)sjg_string46;
#line 20
            sjt_call122.data.isglobal = true;
#line 20
            sjt_call122.data.count = 5;
#line 20
            sjf_array_char(&sjt_call122.data);
#line 14 "lib/common/string.sj"
            sjt_call122._isnullterminated = false;
#line 14
            sjf_string(&sjt_call122);
#line 20 "lib/ui/loop.sj"
            sjt_parent263 = &sjt_call122;
#line 20
            sjt_functionParam456 = sjv_fps;
#line 20
            sjf_f32_asstring(sjt_functionParam456, &sjt_call123);
#line 20
            sjt_functionParam455 = &sjt_call123;
#line 20
            sjf_string_add(sjt_parent263, sjt_functionParam455, &sjt_call121);
#line 20
            sjt_functionParam454 = &sjt_call121;
#line 20
            sjf_debug_writeline(sjt_functionParam454);
#line 21
            sjv_mainloop_lasttick = sjv_ticks;
#line 22
            sjv_mainloop_frames = 0;
        }
    }

#line 7 "lib/ui/windowRenderer.sj"
    sjt_parent264 = &sjv_rootwindowrenderer;
#line 7
    sjf_windowrenderer_getsize(sjt_parent264, &sjv_size);
#line 27 "lib/ui/scene2d.sj"
    sjt_parent265 = &sjv_rootscene;
#line 27 "lib/ui/loop.sj"
    sjt_functionParam457 = &sjv_size;
#line 27
    sjf_scene2d_setsize(sjt_parent265, sjt_functionParam457);
#line 8 "lib/ui/scene2d.sj"
    sjt_parent266 = &sjv_rootscene;
#line 8
    sjf_scene2d_start(sjt_parent266);
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
    sjt_parent267 = &sjv_looplastrect;
#line 30 "lib/ui/loop.sj"
    sjt_functionParam458 = &sjv_rect;
#line 30
    sjf_rect_isequal(sjt_parent267, sjt_functionParam458, &sjt_capture58);
#line 30
    result15 = !sjt_capture58;
    if (result15) {
        sjs_rect* sjt_interfaceParam20 = 0;
        sji_element sjt_parent268 = { 0 };

#line 4 "lib/ui/element.sj"
        sjt_parent268 = sjv_root;
#line 31 "lib/ui/loop.sj"
        sjt_interfaceParam20 = &sjv_rect;
#line 31
        sjt_parent268._vtbl->setrect(sjt_parent268._parent, sjt_interfaceParam20);
    }

#line 5 "lib/ui/element.sj"
    sjt_parent269 = sjv_root;
#line 33 "lib/ui/loop.sj"
    sjt_interfaceParam21 = &sjv_rootscene;
#line 33
    sjt_parent269._vtbl->render(sjt_parent269._parent, sjt_interfaceParam21);
#line 19 "lib/ui/scene2d.sj"
    sjt_parent270 = &sjv_rootscene;
#line 19
    sjf_scene2d_end(sjt_parent270);
#line 22 "lib/ui/windowRenderer.sj"
    sjt_parent271 = &sjv_rootwindowrenderer;
#line 22
    sjf_windowrenderer_present(sjt_parent271);
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
            int32_t ifValue13;
            int32_option sjt_getValue4;

#line 76 "lib/ui/loop.sj"
            sjt_getValue4 = sjv_mouse_eventtype;
#line 76
            ifValue13 = sjt_getValue4.value;
            if ((sjv_mouse_captureelement._parent != 0)) {
                sji_element ifValue14 = { 0 };
                sjs_mouseevent sjt_call124 = { -1 };
                bool sjt_funcold25;
                sjs_mouseevent* sjt_interfaceParam22 = 0;
                sji_element sjt_parent272 = { 0 };

#line 77 "lib/ui/loop.sj"
                ifValue14 = sjv_mouse_captureelement;
                if (ifValue14._parent != 0) {
                    ifValue14._parent->_refCount++;
                }

#line 6 "lib/ui/element.sj"
                sjt_parent272 = ifValue14;
#line 6
                sjt_funcold25 = sjv_shouldcontinue;
#line 6
                sjt_call124._refCount = 1;
#line 78 "lib/ui/loop.sj"
                sjt_call124.eventtype = ifValue13;
#line 78
                sjt_call124.point._refCount = 1;
#line 80
                sjt_call124.point.x = sjv_mouse_x;
#line 80
                sjt_call124.point.y = sjv_mouse_y;
#line 80
                sjf_point(&sjt_call124.point);
#line 81
                sjt_call124.iscaptured = true;
#line 78
                sjt_call124.isleftdown = sjv_mouse_isleftdown;
#line 78
                sjf_mouseevent(&sjt_call124);
#line 78
                sjt_interfaceParam22 = &sjt_call124;
#line 78
                sjt_parent272._vtbl->firemouseevent(sjt_parent272._parent, sjt_interfaceParam22, &sjt_funcold25);
#line 6 "lib/ui/element.sj"
                sjv_shouldcontinue = sjt_funcold25;

                if (ifValue14._parent != 0) {
                    ifValue14._parent->_refCount--;
                    if (ifValue14._parent->_refCount <= 0) {
                        ifValue14._vtbl->destroy(ifValue14._parent);
                        free(ifValue14._parent);
                    }
                }
                if (sjt_call124._refCount == 1) { sjf_mouseevent_destroy(&sjt_call124); }
;
            } else {
                sjs_mouseevent sjt_call125 = { -1 };
                bool sjt_funcold26;
                sjs_mouseevent* sjt_interfaceParam23 = 0;
                sji_element sjt_parent273 = { 0 };

#line 6 "lib/ui/element.sj"
                sjt_parent273 = sjv_root;
#line 6
                sjt_funcold26 = sjv_shouldcontinue;
#line 6
                sjt_call125._refCount = 1;
#line 86 "lib/ui/loop.sj"
                sjt_call125.eventtype = ifValue13;
#line 86
                sjt_call125.point._refCount = 1;
#line 88
                sjt_call125.point.x = sjv_mouse_x;
#line 88
                sjt_call125.point.y = sjv_mouse_y;
#line 88
                sjf_point(&sjt_call125.point);
#line 89
                sjt_call125.iscaptured = false;
#line 86
                sjt_call125.isleftdown = sjv_mouse_isleftdown;
#line 86
                sjf_mouseevent(&sjt_call125);
#line 86
                sjt_interfaceParam23 = &sjt_call125;
#line 86
                sjt_parent273._vtbl->firemouseevent(sjt_parent273._parent, sjt_interfaceParam23, &sjt_funcold26);
#line 6 "lib/ui/element.sj"
                sjv_shouldcontinue = sjt_funcold26;

                if (sjt_call125._refCount == 1) { sjf_mouseevent_destroy(&sjt_call125); }
;
            }
        }

#line 96
    }
#line 99
    sjv_mainloop_shouldcontinue = sjv_shouldappcontinue;

    if (sjt_call121._refCount == 1) { sjf_string_destroy(&sjt_call121); }
;
    if (sjt_call122._refCount == 1) { sjf_string_destroy(&sjt_call122); }
;
    if (sjt_call123._refCount == 1) { sjf_string_destroy(&sjt_call123); }
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

void sjf_mat4_determinant(sjs_mat4* _parent, float* _return) {
#line 95 "lib/ui/mat4.sj"
    (*_return) = (((((((((((((((((((((((((_parent->m03 * _parent->m12) * _parent->m21) * _parent->m30) - (((_parent->m02 * _parent->m13) * _parent->m21) * _parent->m30)) - (((_parent->m03 * _parent->m11) * _parent->m22) * _parent->m30)) + (((_parent->m01 * _parent->m13) * _parent->m22) * _parent->m30)) + (((_parent->m02 * _parent->m11) * _parent->m23) * _parent->m30)) - (((_parent->m01 * _parent->m12) * _parent->m23) * _parent->m30)) - (((_parent->m03 * _parent->m12) * _parent->m20) * _parent->m31)) + (((_parent->m02 * _parent->m13) * _parent->m20) * _parent->m31)) + (((_parent->m03 * _parent->m10) * _parent->m22) * _parent->m31)) - (((_parent->m00 * _parent->m13) * _parent->m22) * _parent->m31)) - (((_parent->m02 * _parent->m10) * _parent->m23) * _parent->m31)) + (((_parent->m00 * _parent->m12) * _parent->m23) * _parent->m31)) + (((_parent->m03 * _parent->m11) * _parent->m20) * _parent->m32)) - (((_parent->m01 * _parent->m13) * _parent->m20) * _parent->m32)) - (((_parent->m03 * _parent->m10) * _parent->m21) * _parent->m32)) + (((_parent->m00 * _parent->m13) * _parent->m21) * _parent->m32)) + (((_parent->m01 * _parent->m10) * _parent->m23) * _parent->m32)) - (((_parent->m00 * _parent->m11) * _parent->m23) * _parent->m32)) - (((_parent->m02 * _parent->m11) * _parent->m20) * _parent->m33)) + (((_parent->m01 * _parent->m12) * _parent->m20) * _parent->m33)) + (((_parent->m02 * _parent->m10) * _parent->m21) * _parent->m33)) - (((_parent->m00 * _parent->m12) * _parent->m21) * _parent->m33)) - (((_parent->m01 * _parent->m10) * _parent->m22) * _parent->m33)) + (((_parent->m00 * _parent->m11) * _parent->m22) * _parent->m33);
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

void sjf_mat4_invert(sjs_mat4* _parent, sjs_mat4* _return) {
    float sjt_capture31;
    float sjt_functionParam196;
    sjs_mat4* sjt_parent105 = 0;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
#line 73 "lib/ui/mat4.sj"
    sjv_t.m00 = ((((((_parent->m12 * _parent->m23) * _parent->m31) - ((_parent->m13 * _parent->m22) * _parent->m31)) + ((_parent->m13 * _parent->m21) * _parent->m32)) - ((_parent->m11 * _parent->m23) * _parent->m32)) - ((_parent->m12 * _parent->m21) * _parent->m33)) + ((_parent->m11 * _parent->m22) * _parent->m33);
#line 74
    sjv_t.m01 = ((((((_parent->m03 * _parent->m22) * _parent->m31) - ((_parent->m02 * _parent->m23) * _parent->m31)) - ((_parent->m03 * _parent->m21) * _parent->m32)) + ((_parent->m01 * _parent->m23) * _parent->m32)) + ((_parent->m02 * _parent->m21) * _parent->m33)) - ((_parent->m01 * _parent->m22) * _parent->m33);
#line 75
    sjv_t.m02 = ((((((_parent->m02 * _parent->m13) * _parent->m31) - ((_parent->m03 * _parent->m12) * _parent->m31)) + ((_parent->m03 * _parent->m11) * _parent->m32)) - ((_parent->m01 * _parent->m13) * _parent->m32)) - ((_parent->m02 * _parent->m11) * _parent->m33)) + ((_parent->m01 * _parent->m12) * _parent->m33);
#line 76
    sjv_t.m03 = ((((((_parent->m03 * _parent->m12) * _parent->m21) - ((_parent->m02 * _parent->m13) * _parent->m21)) - ((_parent->m03 * _parent->m11) * _parent->m22)) + ((_parent->m01 * _parent->m13) * _parent->m22)) + ((_parent->m02 * _parent->m11) * _parent->m23)) - ((_parent->m01 * _parent->m12) * _parent->m23);
#line 77
    sjv_t.m10 = ((((((_parent->m13 * _parent->m22) * _parent->m30) - ((_parent->m12 * _parent->m23) * _parent->m30)) - ((_parent->m13 * _parent->m20) * _parent->m32)) + ((_parent->m10 * _parent->m23) * _parent->m32)) + ((_parent->m12 * _parent->m20) * _parent->m33)) - ((_parent->m10 * _parent->m22) * _parent->m33);
#line 78
    sjv_t.m11 = ((((((_parent->m02 * _parent->m23) * _parent->m30) - ((_parent->m03 * _parent->m22) * _parent->m30)) + ((_parent->m03 * _parent->m20) * _parent->m32)) - ((_parent->m00 * _parent->m23) * _parent->m32)) - ((_parent->m02 * _parent->m20) * _parent->m33)) + ((_parent->m00 * _parent->m22) * _parent->m33);
#line 79
    sjv_t.m12 = ((((((_parent->m03 * _parent->m12) * _parent->m30) - ((_parent->m02 * _parent->m13) * _parent->m30)) - ((_parent->m03 * _parent->m10) * _parent->m32)) + ((_parent->m00 * _parent->m13) * _parent->m32)) + ((_parent->m02 * _parent->m10) * _parent->m33)) - ((_parent->m00 * _parent->m12) * _parent->m33);
#line 80
    sjv_t.m13 = ((((((_parent->m02 * _parent->m13) * _parent->m20) - ((_parent->m03 * _parent->m12) * _parent->m20)) + ((_parent->m03 * _parent->m10) * _parent->m22)) - ((_parent->m00 * _parent->m13) * _parent->m22)) - ((_parent->m02 * _parent->m10) * _parent->m23)) + ((_parent->m00 * _parent->m12) * _parent->m23);
#line 81
    sjv_t.m20 = ((((((_parent->m11 * _parent->m23) * _parent->m30) - ((_parent->m13 * _parent->m21) * _parent->m30)) + ((_parent->m13 * _parent->m20) * _parent->m31)) - ((_parent->m10 * _parent->m23) * _parent->m31)) - ((_parent->m11 * _parent->m20) * _parent->m33)) + ((_parent->m10 * _parent->m21) * _parent->m33);
#line 82
    sjv_t.m21 = ((((((_parent->m03 * _parent->m21) * _parent->m30) - ((_parent->m01 * _parent->m23) * _parent->m30)) - ((_parent->m03 * _parent->m20) * _parent->m31)) + ((_parent->m00 * _parent->m23) * _parent->m31)) + ((_parent->m01 * _parent->m20) * _parent->m33)) - ((_parent->m00 * _parent->m21) * _parent->m33);
#line 83
    sjv_t.m22 = ((((((_parent->m01 * _parent->m13) * _parent->m30) - ((_parent->m03 * _parent->m11) * _parent->m30)) + ((_parent->m03 * _parent->m10) * _parent->m31)) - ((_parent->m00 * _parent->m13) * _parent->m31)) - ((_parent->m01 * _parent->m10) * _parent->m33)) + ((_parent->m00 * _parent->m11) * _parent->m33);
#line 84
    sjv_t.m23 = ((((((_parent->m03 * _parent->m11) * _parent->m20) - ((_parent->m01 * _parent->m13) * _parent->m20)) - ((_parent->m03 * _parent->m10) * _parent->m21)) + ((_parent->m00 * _parent->m13) * _parent->m21)) + ((_parent->m01 * _parent->m10) * _parent->m23)) - ((_parent->m00 * _parent->m11) * _parent->m23);
#line 85
    sjv_t.m30 = ((((((_parent->m12 * _parent->m21) * _parent->m30) - ((_parent->m11 * _parent->m22) * _parent->m30)) - ((_parent->m12 * _parent->m20) * _parent->m31)) + ((_parent->m10 * _parent->m22) * _parent->m31)) + ((_parent->m11 * _parent->m20) * _parent->m32)) - ((_parent->m10 * _parent->m21) * _parent->m32);
#line 86
    sjv_t.m31 = ((((((_parent->m01 * _parent->m22) * _parent->m30) - ((_parent->m02 * _parent->m21) * _parent->m30)) + ((_parent->m02 * _parent->m20) * _parent->m31)) - ((_parent->m00 * _parent->m22) * _parent->m31)) - ((_parent->m01 * _parent->m20) * _parent->m32)) + ((_parent->m00 * _parent->m21) * _parent->m32);
#line 87
    sjv_t.m32 = ((((((_parent->m02 * _parent->m11) * _parent->m30) - ((_parent->m01 * _parent->m12) * _parent->m30)) - ((_parent->m02 * _parent->m10) * _parent->m31)) + ((_parent->m00 * _parent->m12) * _parent->m31)) + ((_parent->m01 * _parent->m10) * _parent->m32)) - ((_parent->m00 * _parent->m11) * _parent->m32);
#line 88
    sjv_t.m33 = ((((((_parent->m01 * _parent->m12) * _parent->m20) - ((_parent->m02 * _parent->m11) * _parent->m20)) + ((_parent->m02 * _parent->m10) * _parent->m21)) - ((_parent->m00 * _parent->m12) * _parent->m21)) - ((_parent->m01 * _parent->m10) * _parent->m22)) + ((_parent->m00 * _parent->m11) * _parent->m22);
#line 88
    sjf_mat4(&sjv_t);
#line 40
    sjt_parent105 = &sjv_t;
#line 40
    sjf_mat4_determinant(_parent, &sjt_capture31);
#line 91
    sjt_functionParam196 = 1.0f / sjt_capture31;
#line 91
    sjf_mat4_multiplyf32(sjt_parent105, sjt_functionParam196, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
;
}

void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4** _return) {
    float sjt_capture32;
    float sjt_functionParam197;
    sjs_mat4* sjt_parent106 = 0;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
#line 73 "lib/ui/mat4.sj"
    sjv_t.m00 = ((((((_parent->m12 * _parent->m23) * _parent->m31) - ((_parent->m13 * _parent->m22) * _parent->m31)) + ((_parent->m13 * _parent->m21) * _parent->m32)) - ((_parent->m11 * _parent->m23) * _parent->m32)) - ((_parent->m12 * _parent->m21) * _parent->m33)) + ((_parent->m11 * _parent->m22) * _parent->m33);
#line 74
    sjv_t.m01 = ((((((_parent->m03 * _parent->m22) * _parent->m31) - ((_parent->m02 * _parent->m23) * _parent->m31)) - ((_parent->m03 * _parent->m21) * _parent->m32)) + ((_parent->m01 * _parent->m23) * _parent->m32)) + ((_parent->m02 * _parent->m21) * _parent->m33)) - ((_parent->m01 * _parent->m22) * _parent->m33);
#line 75
    sjv_t.m02 = ((((((_parent->m02 * _parent->m13) * _parent->m31) - ((_parent->m03 * _parent->m12) * _parent->m31)) + ((_parent->m03 * _parent->m11) * _parent->m32)) - ((_parent->m01 * _parent->m13) * _parent->m32)) - ((_parent->m02 * _parent->m11) * _parent->m33)) + ((_parent->m01 * _parent->m12) * _parent->m33);
#line 76
    sjv_t.m03 = ((((((_parent->m03 * _parent->m12) * _parent->m21) - ((_parent->m02 * _parent->m13) * _parent->m21)) - ((_parent->m03 * _parent->m11) * _parent->m22)) + ((_parent->m01 * _parent->m13) * _parent->m22)) + ((_parent->m02 * _parent->m11) * _parent->m23)) - ((_parent->m01 * _parent->m12) * _parent->m23);
#line 77
    sjv_t.m10 = ((((((_parent->m13 * _parent->m22) * _parent->m30) - ((_parent->m12 * _parent->m23) * _parent->m30)) - ((_parent->m13 * _parent->m20) * _parent->m32)) + ((_parent->m10 * _parent->m23) * _parent->m32)) + ((_parent->m12 * _parent->m20) * _parent->m33)) - ((_parent->m10 * _parent->m22) * _parent->m33);
#line 78
    sjv_t.m11 = ((((((_parent->m02 * _parent->m23) * _parent->m30) - ((_parent->m03 * _parent->m22) * _parent->m30)) + ((_parent->m03 * _parent->m20) * _parent->m32)) - ((_parent->m00 * _parent->m23) * _parent->m32)) - ((_parent->m02 * _parent->m20) * _parent->m33)) + ((_parent->m00 * _parent->m22) * _parent->m33);
#line 79
    sjv_t.m12 = ((((((_parent->m03 * _parent->m12) * _parent->m30) - ((_parent->m02 * _parent->m13) * _parent->m30)) - ((_parent->m03 * _parent->m10) * _parent->m32)) + ((_parent->m00 * _parent->m13) * _parent->m32)) + ((_parent->m02 * _parent->m10) * _parent->m33)) - ((_parent->m00 * _parent->m12) * _parent->m33);
#line 80
    sjv_t.m13 = ((((((_parent->m02 * _parent->m13) * _parent->m20) - ((_parent->m03 * _parent->m12) * _parent->m20)) + ((_parent->m03 * _parent->m10) * _parent->m22)) - ((_parent->m00 * _parent->m13) * _parent->m22)) - ((_parent->m02 * _parent->m10) * _parent->m23)) + ((_parent->m00 * _parent->m12) * _parent->m23);
#line 81
    sjv_t.m20 = ((((((_parent->m11 * _parent->m23) * _parent->m30) - ((_parent->m13 * _parent->m21) * _parent->m30)) + ((_parent->m13 * _parent->m20) * _parent->m31)) - ((_parent->m10 * _parent->m23) * _parent->m31)) - ((_parent->m11 * _parent->m20) * _parent->m33)) + ((_parent->m10 * _parent->m21) * _parent->m33);
#line 82
    sjv_t.m21 = ((((((_parent->m03 * _parent->m21) * _parent->m30) - ((_parent->m01 * _parent->m23) * _parent->m30)) - ((_parent->m03 * _parent->m20) * _parent->m31)) + ((_parent->m00 * _parent->m23) * _parent->m31)) + ((_parent->m01 * _parent->m20) * _parent->m33)) - ((_parent->m00 * _parent->m21) * _parent->m33);
#line 83
    sjv_t.m22 = ((((((_parent->m01 * _parent->m13) * _parent->m30) - ((_parent->m03 * _parent->m11) * _parent->m30)) + ((_parent->m03 * _parent->m10) * _parent->m31)) - ((_parent->m00 * _parent->m13) * _parent->m31)) - ((_parent->m01 * _parent->m10) * _parent->m33)) + ((_parent->m00 * _parent->m11) * _parent->m33);
#line 84
    sjv_t.m23 = ((((((_parent->m03 * _parent->m11) * _parent->m20) - ((_parent->m01 * _parent->m13) * _parent->m20)) - ((_parent->m03 * _parent->m10) * _parent->m21)) + ((_parent->m00 * _parent->m13) * _parent->m21)) + ((_parent->m01 * _parent->m10) * _parent->m23)) - ((_parent->m00 * _parent->m11) * _parent->m23);
#line 85
    sjv_t.m30 = ((((((_parent->m12 * _parent->m21) * _parent->m30) - ((_parent->m11 * _parent->m22) * _parent->m30)) - ((_parent->m12 * _parent->m20) * _parent->m31)) + ((_parent->m10 * _parent->m22) * _parent->m31)) + ((_parent->m11 * _parent->m20) * _parent->m32)) - ((_parent->m10 * _parent->m21) * _parent->m32);
#line 86
    sjv_t.m31 = ((((((_parent->m01 * _parent->m22) * _parent->m30) - ((_parent->m02 * _parent->m21) * _parent->m30)) + ((_parent->m02 * _parent->m20) * _parent->m31)) - ((_parent->m00 * _parent->m22) * _parent->m31)) - ((_parent->m01 * _parent->m20) * _parent->m32)) + ((_parent->m00 * _parent->m21) * _parent->m32);
#line 87
    sjv_t.m32 = ((((((_parent->m02 * _parent->m11) * _parent->m30) - ((_parent->m01 * _parent->m12) * _parent->m30)) - ((_parent->m02 * _parent->m10) * _parent->m31)) + ((_parent->m00 * _parent->m12) * _parent->m31)) + ((_parent->m01 * _parent->m10) * _parent->m32)) - ((_parent->m00 * _parent->m11) * _parent->m32);
#line 88
    sjv_t.m33 = ((((((_parent->m01 * _parent->m12) * _parent->m20) - ((_parent->m02 * _parent->m11) * _parent->m20)) + ((_parent->m02 * _parent->m10) * _parent->m21)) - ((_parent->m00 * _parent->m12) * _parent->m21)) - ((_parent->m01 * _parent->m10) * _parent->m22)) + ((_parent->m00 * _parent->m11) * _parent->m22);
#line 88
    sjf_mat4(&sjv_t);
#line 40
    sjt_parent106 = &sjv_t;
#line 40
    sjf_mat4_determinant(_parent, &sjt_capture32);
#line 91
    sjt_functionParam197 = 1.0f / sjt_capture32;
#line 91
    sjf_mat4_multiplyf32_heap(sjt_parent106, sjt_functionParam197, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
;
}

void sjf_mat4_lookatlh(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return) {
    sjs_vec3 sjt_call7 = { -1 };
    float sjt_capture10;
    float sjt_capture11;
    float sjt_capture9;
    sjs_vec3* sjt_functionParam36 = 0;
    sjs_vec3* sjt_functionParam39 = 0;
    sjs_vec3* sjt_functionParam40 = 0;
    sjs_vec3* sjt_functionParam41 = 0;
    sjs_vec3* sjt_functionParam42 = 0;
    sjs_vec3* sjt_functionParam43 = 0;
    sjs_vec3* sjt_parent26 = 0;
    sjs_vec3* sjt_parent27 = 0;
    sjs_vec3* sjt_parent28 = 0;
    sjs_vec3* sjt_parent29 = 0;
    sjs_vec3* sjt_parent30 = 0;
    sjs_vec3* sjt_parent31 = 0;
    sjs_vec3* sjt_parent32 = 0;
    sjs_vec3* sjt_parent33 = 0;
    sjs_vec3 sjv_temp = { -1 };
    sjs_vec3 sjv_xaxis = { -1 };
    sjs_vec3 sjv_yaxis = { -1 };
    sjs_vec3 sjv_zaxis = { -1 };

#line 133 "lib/ui/mat4.sj"
    sjt_parent26 = target;
#line 133
    sjt_functionParam36 = camera;
#line 133
    sjf_vec3_subtract(sjt_parent26, sjt_functionParam36, &sjv_temp);
#line 38 "lib/ui/vec3.sj"
    sjt_parent27 = &sjv_temp;
#line 38
    sjf_vec3_normalize(sjt_parent27, &sjv_zaxis);
#line 133 "lib/ui/mat4.sj"
    sjt_parent29 = up;
#line 136
    sjt_functionParam39 = &sjv_zaxis;
#line 136
    sjf_vec3_cross(sjt_parent29, sjt_functionParam39, &sjt_call7);
#line 136
    sjt_parent28 = &sjt_call7;
#line 136
    sjf_vec3_normalize(sjt_parent28, &sjv_xaxis);
#line 47 "lib/ui/vec3.sj"
    sjt_parent30 = &sjv_zaxis;
#line 137 "lib/ui/mat4.sj"
    sjt_functionParam40 = &sjv_xaxis;
#line 137
    sjf_vec3_cross(sjt_parent30, sjt_functionParam40, &sjv_yaxis);
#line 137
    _return->_refCount = 1;
#line 138
    _return->m00 = (&sjv_xaxis)->x;
#line 138
    _return->m01 = (&sjv_yaxis)->x;
#line 138
    _return->m02 = (&sjv_zaxis)->x;
#line 142
    _return->m03 = 0.0f;
#line 138
    _return->m10 = (&sjv_xaxis)->y;
#line 138
    _return->m11 = (&sjv_yaxis)->y;
#line 138
    _return->m12 = (&sjv_zaxis)->y;
#line 146
    _return->m13 = 0.0f;
#line 138
    _return->m20 = (&sjv_xaxis)->z;
#line 138
    _return->m21 = (&sjv_yaxis)->z;
#line 138
    _return->m22 = (&sjv_zaxis)->z;
#line 150
    _return->m23 = 0.0f;
#line 55 "lib/ui/vec3.sj"
    sjt_parent31 = &sjv_xaxis;
#line 133 "lib/ui/mat4.sj"
    sjt_functionParam41 = camera;
#line 133
    sjf_vec3_dot(sjt_parent31, sjt_functionParam41, &sjt_capture9);
#line 151
    _return->m30 = 0.0f - sjt_capture9;
#line 55 "lib/ui/vec3.sj"
    sjt_parent32 = &sjv_yaxis;
#line 133 "lib/ui/mat4.sj"
    sjt_functionParam42 = camera;
#line 133
    sjf_vec3_dot(sjt_parent32, sjt_functionParam42, &sjt_capture10);
#line 152
    _return->m31 = 0.0f - sjt_capture10;
#line 55 "lib/ui/vec3.sj"
    sjt_parent33 = &sjv_zaxis;
#line 133 "lib/ui/mat4.sj"
    sjt_functionParam43 = camera;
#line 133
    sjf_vec3_dot(sjt_parent33, sjt_functionParam43, &sjt_capture11);
#line 153
    _return->m32 = 0.0f - sjt_capture11;
#line 154
    _return->m33 = 1.0f;
#line 154
    sjf_mat4(_return);

    if (sjt_call7._refCount == 1) { sjf_vec3_destroy(&sjt_call7); }
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
    sjs_vec3 sjt_call8 = { -1 };
    float sjt_capture12;
    float sjt_capture13;
    float sjt_capture14;
    sjs_vec3* sjt_functionParam44 = 0;
    sjs_vec3* sjt_functionParam45 = 0;
    sjs_vec3* sjt_functionParam46 = 0;
    sjs_vec3* sjt_functionParam47 = 0;
    sjs_vec3* sjt_functionParam48 = 0;
    sjs_vec3* sjt_functionParam49 = 0;
    sjs_vec3* sjt_parent34 = 0;
    sjs_vec3* sjt_parent35 = 0;
    sjs_vec3* sjt_parent36 = 0;
    sjs_vec3* sjt_parent37 = 0;
    sjs_vec3* sjt_parent38 = 0;
    sjs_vec3* sjt_parent39 = 0;
    sjs_vec3* sjt_parent40 = 0;
    sjs_vec3* sjt_parent41 = 0;
    sjs_vec3 sjv_temp = { -1 };
    sjs_vec3 sjv_xaxis = { -1 };
    sjs_vec3 sjv_yaxis = { -1 };
    sjs_vec3 sjv_zaxis = { -1 };

#line 133 "lib/ui/mat4.sj"
    sjt_parent34 = target;
#line 133
    sjt_functionParam44 = camera;
#line 133
    sjf_vec3_subtract(sjt_parent34, sjt_functionParam44, &sjv_temp);
#line 38 "lib/ui/vec3.sj"
    sjt_parent35 = &sjv_temp;
#line 38
    sjf_vec3_normalize(sjt_parent35, &sjv_zaxis);
#line 133 "lib/ui/mat4.sj"
    sjt_parent37 = up;
#line 136
    sjt_functionParam45 = &sjv_zaxis;
#line 136
    sjf_vec3_cross(sjt_parent37, sjt_functionParam45, &sjt_call8);
#line 136
    sjt_parent36 = &sjt_call8;
#line 136
    sjf_vec3_normalize(sjt_parent36, &sjv_xaxis);
#line 47 "lib/ui/vec3.sj"
    sjt_parent38 = &sjv_zaxis;
#line 137 "lib/ui/mat4.sj"
    sjt_functionParam46 = &sjv_xaxis;
#line 137
    sjf_vec3_cross(sjt_parent38, sjt_functionParam46, &sjv_yaxis);
#line 137
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
#line 137
    (*_return)->_refCount = 1;
#line 138
    (*_return)->m00 = (&sjv_xaxis)->x;
#line 138
    (*_return)->m01 = (&sjv_yaxis)->x;
#line 138
    (*_return)->m02 = (&sjv_zaxis)->x;
#line 142
    (*_return)->m03 = 0.0f;
#line 138
    (*_return)->m10 = (&sjv_xaxis)->y;
#line 138
    (*_return)->m11 = (&sjv_yaxis)->y;
#line 138
    (*_return)->m12 = (&sjv_zaxis)->y;
#line 146
    (*_return)->m13 = 0.0f;
#line 138
    (*_return)->m20 = (&sjv_xaxis)->z;
#line 138
    (*_return)->m21 = (&sjv_yaxis)->z;
#line 138
    (*_return)->m22 = (&sjv_zaxis)->z;
#line 150
    (*_return)->m23 = 0.0f;
#line 55 "lib/ui/vec3.sj"
    sjt_parent39 = &sjv_xaxis;
#line 133 "lib/ui/mat4.sj"
    sjt_functionParam47 = camera;
#line 133
    sjf_vec3_dot(sjt_parent39, sjt_functionParam47, &sjt_capture12);
#line 151
    (*_return)->m30 = 0.0f - sjt_capture12;
#line 55 "lib/ui/vec3.sj"
    sjt_parent40 = &sjv_yaxis;
#line 133 "lib/ui/mat4.sj"
    sjt_functionParam48 = camera;
#line 133
    sjf_vec3_dot(sjt_parent40, sjt_functionParam48, &sjt_capture13);
#line 152
    (*_return)->m31 = 0.0f - sjt_capture13;
#line 55 "lib/ui/vec3.sj"
    sjt_parent41 = &sjv_zaxis;
#line 133 "lib/ui/mat4.sj"
    sjt_functionParam49 = camera;
#line 133
    sjf_vec3_dot(sjt_parent41, sjt_functionParam49, &sjt_capture14);
#line 153
    (*_return)->m32 = 0.0f - sjt_capture14;
#line 154
    (*_return)->m33 = 1.0f;
#line 154
    sjf_mat4_heap((*_return));

    if (sjt_call8._refCount == 1) { sjf_vec3_destroy(&sjt_call8); }
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
#line 21 "lib/ui/mat4.sj"
    _return->m00 = (((m->m00 * _parent->m00) + (m->m01 * _parent->m10)) + (m->m02 * _parent->m20)) + (m->m03 * _parent->m30);
#line 22
    _return->m01 = (((m->m00 * _parent->m01) + (m->m01 * _parent->m11)) + (m->m02 * _parent->m21)) + (m->m03 * _parent->m31);
#line 23
    _return->m02 = (((m->m00 * _parent->m02) + (m->m01 * _parent->m12)) + (m->m02 * _parent->m22)) + (m->m03 * _parent->m32);
#line 24
    _return->m03 = (((m->m00 * _parent->m03) + (m->m01 * _parent->m13)) + (m->m02 * _parent->m23)) + (m->m03 * _parent->m33);
#line 25
    _return->m10 = (((m->m10 * _parent->m00) + (m->m11 * _parent->m10)) + (m->m12 * _parent->m20)) + (m->m13 * _parent->m30);
#line 26
    _return->m11 = (((m->m10 * _parent->m01) + (m->m11 * _parent->m11)) + (m->m12 * _parent->m21)) + (m->m13 * _parent->m31);
#line 27
    _return->m12 = (((m->m10 * _parent->m02) + (m->m11 * _parent->m12)) + (m->m12 * _parent->m22)) + (m->m13 * _parent->m32);
#line 28
    _return->m13 = (((m->m10 * _parent->m03) + (m->m11 * _parent->m13)) + (m->m12 * _parent->m23)) + (m->m13 * _parent->m33);
#line 29
    _return->m20 = (((m->m20 * _parent->m00) + (m->m21 * _parent->m10)) + (m->m22 * _parent->m20)) + (m->m23 * _parent->m30);
#line 30
    _return->m21 = (((m->m20 * _parent->m01) + (m->m21 * _parent->m11)) + (m->m22 * _parent->m21)) + (m->m23 * _parent->m31);
#line 31
    _return->m22 = (((m->m20 * _parent->m02) + (m->m21 * _parent->m12)) + (m->m22 * _parent->m22)) + (m->m23 * _parent->m32);
#line 32
    _return->m23 = (((m->m20 * _parent->m03) + (m->m21 * _parent->m13)) + (m->m22 * _parent->m23)) + (m->m23 * _parent->m33);
#line 33
    _return->m30 = (((m->m30 * _parent->m00) + (m->m31 * _parent->m10)) + (m->m32 * _parent->m20)) + (m->m33 * _parent->m30);
#line 34
    _return->m31 = (((m->m30 * _parent->m01) + (m->m31 * _parent->m11)) + (m->m32 * _parent->m21)) + (m->m33 * _parent->m31);
#line 35
    _return->m32 = (((m->m30 * _parent->m02) + (m->m31 * _parent->m12)) + (m->m32 * _parent->m22)) + (m->m33 * _parent->m32);
#line 36
    _return->m33 = (((m->m30 * _parent->m03) + (m->m31 * _parent->m13)) + (m->m32 * _parent->m23)) + (m->m33 * _parent->m33);
#line 36
    sjf_mat4(_return);
}

void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 21 "lib/ui/mat4.sj"
    (*_return)->m00 = (((m->m00 * _parent->m00) + (m->m01 * _parent->m10)) + (m->m02 * _parent->m20)) + (m->m03 * _parent->m30);
#line 22
    (*_return)->m01 = (((m->m00 * _parent->m01) + (m->m01 * _parent->m11)) + (m->m02 * _parent->m21)) + (m->m03 * _parent->m31);
#line 23
    (*_return)->m02 = (((m->m00 * _parent->m02) + (m->m01 * _parent->m12)) + (m->m02 * _parent->m22)) + (m->m03 * _parent->m32);
#line 24
    (*_return)->m03 = (((m->m00 * _parent->m03) + (m->m01 * _parent->m13)) + (m->m02 * _parent->m23)) + (m->m03 * _parent->m33);
#line 25
    (*_return)->m10 = (((m->m10 * _parent->m00) + (m->m11 * _parent->m10)) + (m->m12 * _parent->m20)) + (m->m13 * _parent->m30);
#line 26
    (*_return)->m11 = (((m->m10 * _parent->m01) + (m->m11 * _parent->m11)) + (m->m12 * _parent->m21)) + (m->m13 * _parent->m31);
#line 27
    (*_return)->m12 = (((m->m10 * _parent->m02) + (m->m11 * _parent->m12)) + (m->m12 * _parent->m22)) + (m->m13 * _parent->m32);
#line 28
    (*_return)->m13 = (((m->m10 * _parent->m03) + (m->m11 * _parent->m13)) + (m->m12 * _parent->m23)) + (m->m13 * _parent->m33);
#line 29
    (*_return)->m20 = (((m->m20 * _parent->m00) + (m->m21 * _parent->m10)) + (m->m22 * _parent->m20)) + (m->m23 * _parent->m30);
#line 30
    (*_return)->m21 = (((m->m20 * _parent->m01) + (m->m21 * _parent->m11)) + (m->m22 * _parent->m21)) + (m->m23 * _parent->m31);
#line 31
    (*_return)->m22 = (((m->m20 * _parent->m02) + (m->m21 * _parent->m12)) + (m->m22 * _parent->m22)) + (m->m23 * _parent->m32);
#line 32
    (*_return)->m23 = (((m->m20 * _parent->m03) + (m->m21 * _parent->m13)) + (m->m22 * _parent->m23)) + (m->m23 * _parent->m33);
#line 33
    (*_return)->m30 = (((m->m30 * _parent->m00) + (m->m31 * _parent->m10)) + (m->m32 * _parent->m20)) + (m->m33 * _parent->m30);
#line 34
    (*_return)->m31 = (((m->m30 * _parent->m01) + (m->m31 * _parent->m11)) + (m->m32 * _parent->m21)) + (m->m33 * _parent->m31);
#line 35
    (*_return)->m32 = (((m->m30 * _parent->m02) + (m->m31 * _parent->m12)) + (m->m32 * _parent->m22)) + (m->m33 * _parent->m32);
#line 36
    (*_return)->m33 = (((m->m30 * _parent->m03) + (m->m31 * _parent->m13)) + (m->m32 * _parent->m23)) + (m->m33 * _parent->m33);
#line 36
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyf32(sjs_mat4* _parent, float x, sjs_mat4* _return) {
    _return->_refCount = 1;
#line 42 "lib/ui/mat4.sj"
    _return->m00 = _parent->m00 * x;
#line 43
    _return->m01 = _parent->m01 * x;
#line 44
    _return->m02 = _parent->m02 * x;
#line 45
    _return->m03 = _parent->m03 * x;
#line 46
    _return->m10 = _parent->m10 * x;
#line 47
    _return->m11 = _parent->m11 * x;
#line 48
    _return->m12 = _parent->m12 * x;
#line 49
    _return->m13 = _parent->m13 * x;
#line 50
    _return->m20 = _parent->m20 * x;
#line 51
    _return->m21 = _parent->m21 * x;
#line 52
    _return->m22 = _parent->m22 * x;
#line 53
    _return->m23 = _parent->m23 * x;
#line 54
    _return->m30 = _parent->m30 * x;
#line 55
    _return->m31 = _parent->m31 * x;
#line 56
    _return->m32 = _parent->m32 * x;
#line 57
    _return->m33 = _parent->m33 * x;
#line 57
    sjf_mat4(_return);
}

void sjf_mat4_multiplyf32_heap(sjs_mat4* _parent, float x, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 42 "lib/ui/mat4.sj"
    (*_return)->m00 = _parent->m00 * x;
#line 43
    (*_return)->m01 = _parent->m01 * x;
#line 44
    (*_return)->m02 = _parent->m02 * x;
#line 45
    (*_return)->m03 = _parent->m03 * x;
#line 46
    (*_return)->m10 = _parent->m10 * x;
#line 47
    (*_return)->m11 = _parent->m11 * x;
#line 48
    (*_return)->m12 = _parent->m12 * x;
#line 49
    (*_return)->m13 = _parent->m13 * x;
#line 50
    (*_return)->m20 = _parent->m20 * x;
#line 51
    (*_return)->m21 = _parent->m21 * x;
#line 52
    (*_return)->m22 = _parent->m22 * x;
#line 53
    (*_return)->m23 = _parent->m23 * x;
#line 54
    (*_return)->m30 = _parent->m30 * x;
#line 55
    (*_return)->m31 = _parent->m31 * x;
#line 56
    (*_return)->m32 = _parent->m32 * x;
#line 57
    (*_return)->m33 = _parent->m33 * x;
#line 57
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyvec4(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4* _return) {
    _return->_refCount = 1;
#line 64 "lib/ui/mat4.sj"
    _return->x = (((_parent->m00 * v->x) + (_parent->m10 * v->y)) + (_parent->m20 * v->z)) + (_parent->m30 * v->w);
#line 65
    _return->y = (((_parent->m01 * v->x) + (_parent->m11 * v->y)) + (_parent->m21 * v->z)) + (_parent->m31 * v->w);
#line 66
    _return->z = (((_parent->m02 * v->x) + (_parent->m12 * v->y)) + (_parent->m22 * v->z)) + (_parent->m32 * v->w);
#line 67
    _return->w = (((_parent->m03 * v->x) + (_parent->m13 * v->y)) + (_parent->m23 * v->z)) + (_parent->m33 * v->w);
#line 67
    sjf_vec4(_return);
}

void sjf_mat4_multiplyvec4_heap(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4** _return) {
    (*_return) = (sjs_vec4*)malloc(sizeof(sjs_vec4));
    (*_return)->_refCount = 1;
#line 64 "lib/ui/mat4.sj"
    (*_return)->x = (((_parent->m00 * v->x) + (_parent->m10 * v->y)) + (_parent->m20 * v->z)) + (_parent->m30 * v->w);
#line 65
    (*_return)->y = (((_parent->m01 * v->x) + (_parent->m11 * v->y)) + (_parent->m21 * v->z)) + (_parent->m31 * v->w);
#line 66
    (*_return)->z = (((_parent->m02 * v->x) + (_parent->m12 * v->y)) + (_parent->m22 * v->z)) + (_parent->m32 * v->w);
#line 67
    (*_return)->w = (((_parent->m03 * v->x) + (_parent->m13 * v->y)) + (_parent->m23 * v->z)) + (_parent->m33 * v->w);
#line 67
    sjf_vec4_heap((*_return));
}

void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return) {
    float result8;

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
    result8 = -2.0f;
#line 176
    _return->m22 = result8 / (zfar - znear);
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
    float result9;

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
    result9 = -2.0f;
#line 176
    (*_return)->m22 = result9 / (zfar - znear);
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

void sjf_mat4_perspective(float fovy, float aspect, float znear, float zfar, sjs_mat4* _return) {
    float sjt_capture7;
    float sjt_functionParam30;
    float sjv_xscale;
    float sjv_yscale;

#line 159 "lib/ui/mat4.sj"
    sjt_functionParam30 = (fovy / 180.0f) / 2.0f;
#line 159
    sjf_f32_tan(sjt_functionParam30, &sjt_capture7);
#line 159
    sjv_yscale = 1.0f / sjt_capture7;
#line 160
    sjv_xscale = sjv_yscale * aspect;
#line 160
    _return->_refCount = 1;
#line 161
    _return->m00 = sjv_xscale;
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 161
    _return->m11 = sjv_yscale;
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 164
    _return->m22 = zfar / (zfar - znear);
#line 165
    _return->m23 = 1.0f;
#line 14
    _return->m30 = 0.0f;
#line 15
    _return->m31 = 0.0f;
#line 166
    _return->m32 = 0.0f - ((znear * zfar) / (zfar - znear));
#line 17
    _return->m33 = 0.0f;
#line 17
    sjf_mat4(_return);
}

void sjf_mat4_perspective_heap(float fovy, float aspect, float znear, float zfar, sjs_mat4** _return) {
    float sjt_capture8;
    float sjt_functionParam31;
    float sjv_xscale;
    float sjv_yscale;

#line 159 "lib/ui/mat4.sj"
    sjt_functionParam31 = (fovy / 180.0f) / 2.0f;
#line 159
    sjf_f32_tan(sjt_functionParam31, &sjt_capture8);
#line 159
    sjv_yscale = 1.0f / sjt_capture8;
#line 160
    sjv_xscale = sjv_yscale * aspect;
#line 160
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
#line 160
    (*_return)->_refCount = 1;
#line 161
    (*_return)->m00 = sjv_xscale;
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 161
    (*_return)->m11 = sjv_yscale;
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 164
    (*_return)->m22 = zfar / (zfar - znear);
#line 165
    (*_return)->m23 = 1.0f;
#line 14
    (*_return)->m30 = 0.0f;
#line 15
    (*_return)->m31 = 0.0f;
#line 166
    (*_return)->m32 = 0.0f - ((znear * zfar) / (zfar - znear));
#line 17
    (*_return)->m33 = 0.0f;
#line 17
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

void sjf_mat4_transpose(sjs_mat4* _parent, sjs_mat4* _return) {
    _return->_refCount = 1;
#line 99 "lib/ui/mat4.sj"
    _return->m00 = _parent->m00;
#line 99
    _return->m01 = _parent->m10;
#line 99
    _return->m02 = _parent->m20;
#line 99
    _return->m03 = _parent->m30;
#line 99
    _return->m10 = _parent->m01;
#line 99
    _return->m11 = _parent->m11;
#line 99
    _return->m12 = _parent->m21;
#line 99
    _return->m13 = _parent->m31;
#line 99
    _return->m20 = _parent->m02;
#line 99
    _return->m21 = _parent->m12;
#line 99
    _return->m22 = _parent->m22;
#line 99
    _return->m23 = _parent->m32;
#line 99
    _return->m30 = _parent->m03;
#line 99
    _return->m31 = _parent->m13;
#line 99
    _return->m32 = _parent->m23;
#line 99
    _return->m33 = _parent->m33;
#line 99
    sjf_mat4(_return);
}

void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 99 "lib/ui/mat4.sj"
    (*_return)->m00 = _parent->m00;
#line 99
    (*_return)->m01 = _parent->m10;
#line 99
    (*_return)->m02 = _parent->m20;
#line 99
    (*_return)->m03 = _parent->m30;
#line 99
    (*_return)->m10 = _parent->m01;
#line 99
    (*_return)->m11 = _parent->m11;
#line 99
    (*_return)->m12 = _parent->m21;
#line 99
    (*_return)->m13 = _parent->m31;
#line 99
    (*_return)->m20 = _parent->m02;
#line 99
    (*_return)->m21 = _parent->m12;
#line 99
    (*_return)->m22 = _parent->m22;
#line 99
    (*_return)->m23 = _parent->m32;
#line 99
    (*_return)->m30 = _parent->m03;
#line 99
    (*_return)->m31 = _parent->m13;
#line 99
    (*_return)->m32 = _parent->m23;
#line 99
    (*_return)->m33 = _parent->m33;
#line 99
    sjf_mat4_heap((*_return));
}

void sjf_model_zsort(sji_model l, sji_model r, int32_t* _return) {
    float sjt_functionParam88;
    float sjt_functionParam89;
    sji_model sjt_parent51 = { 0 };
    sji_model sjt_parent52 = { 0 };

#line 11 "lib/ui/model.sj"
    sjt_parent51 = l;
#line 12
    sjt_parent51._vtbl->getz(sjt_parent51._parent, &sjt_functionParam88);
#line 11
    sjt_parent52 = r;
#line 12
    sjt_parent52._vtbl->getz(sjt_parent52._parent, &sjt_functionParam89);
#line 12
    sjf_f32_compare(sjt_functionParam88, sjt_functionParam89, _return);
}

void sjf_model_zsort_callback(void * _parent, sji_model l, sji_model r, int32_t* _return) {
    sjf_model_zsort(l, r, _return);
}

void sjf_mouseevent(sjs_mouseevent* _this) {
}

void sjf_mouseevent_asstring(sjs_mouseevent* _parent, sjs_string* _return) {
    sjs_string sjt_call61 = { -1 };
    sjs_string sjt_call62 = { -1 };
    sjs_string sjt_call63 = { -1 };
    sjs_string sjt_call64 = { -1 };
    sjs_string sjt_call65 = { -1 };
    sjs_string sjt_call66 = { -1 };
    sjs_string sjt_call75 = { -1 };
    sjs_string sjt_call76 = { -1 };
    sjs_string sjt_call77 = { -1 };
    sjs_string sjt_call78 = { -1 };
    sjs_string* sjt_functionParam331 = 0;
    sjs_string* sjt_functionParam344 = 0;
    sjs_string* sjt_functionParam345 = 0;
    bool sjt_functionParam346;
    sjs_string* sjt_functionParam347 = 0;
    sjs_string* sjt_functionParam348 = 0;
    bool sjt_functionParam349;
    sjs_string* sjt_parent192 = 0;
    sjs_string* sjt_parent193 = 0;
    sjs_string* sjt_parent194 = 0;
    sjs_string* sjt_parent195 = 0;
    sjs_string* sjt_parent196 = 0;
    sjs_point* sjt_parent201 = 0;

    sjt_call65._refCount = 1;
#line 56 "lib/ui/mouse.sj"
    sjt_call65.count = 8;
#line 56
    sjt_call65.data._refCount = 1;
#line 56
    sjt_call65.data.datasize = 8;
#line 56
    sjt_call65.data.data = (void*)sjg_string33;
#line 56
    sjt_call65.data.isglobal = true;
#line 56
    sjt_call65.data.count = 8;
#line 56
    sjf_array_char(&sjt_call65.data);
#line 14 "lib/common/string.sj"
    sjt_call65._isnullterminated = false;
#line 14
    sjf_string(&sjt_call65);
#line 56 "lib/ui/mouse.sj"
    sjt_parent196 = &sjt_call65;
#line 5 "lib/ui/point.sj"
    sjt_parent201 = &_parent->point;
#line 5
    sjf_point_asstring(sjt_parent201, &sjt_call66);
#line 56 "lib/ui/mouse.sj"
    sjt_functionParam331 = &sjt_call66;
#line 56
    sjf_string_add(sjt_parent196, sjt_functionParam331, &sjt_call64);
#line 56
    sjt_parent195 = &sjt_call64;
#line 56
    sjt_call75._refCount = 1;
#line 56
    sjt_call75.count = 14;
#line 56
    sjt_call75.data._refCount = 1;
#line 56
    sjt_call75.data.datasize = 14;
#line 56
    sjt_call75.data.data = (void*)sjg_string35;
#line 56
    sjt_call75.data.isglobal = true;
#line 56
    sjt_call75.data.count = 14;
#line 56
    sjf_array_char(&sjt_call75.data);
#line 14 "lib/common/string.sj"
    sjt_call75._isnullterminated = false;
#line 14
    sjf_string(&sjt_call75);
#line 56 "lib/ui/mouse.sj"
    sjt_functionParam344 = &sjt_call75;
#line 56
    sjf_string_add(sjt_parent195, sjt_functionParam344, &sjt_call63);
#line 56
    sjt_parent194 = &sjt_call63;
#line 56
    sjt_functionParam346 = _parent->iscaptured;
#line 56
    sjf_bool_asstring(sjt_functionParam346, &sjt_call76);
#line 56
    sjt_functionParam345 = &sjt_call76;
#line 56
    sjf_string_add(sjt_parent194, sjt_functionParam345, &sjt_call62);
#line 56
    sjt_parent193 = &sjt_call62;
#line 56
    sjt_call77._refCount = 1;
#line 56
    sjt_call77.count = 14;
#line 56
    sjt_call77.data._refCount = 1;
#line 56
    sjt_call77.data.datasize = 14;
#line 56
    sjt_call77.data.data = (void*)sjg_string38;
#line 56
    sjt_call77.data.isglobal = true;
#line 56
    sjt_call77.data.count = 14;
#line 56
    sjf_array_char(&sjt_call77.data);
#line 14 "lib/common/string.sj"
    sjt_call77._isnullterminated = false;
#line 14
    sjf_string(&sjt_call77);
#line 56 "lib/ui/mouse.sj"
    sjt_functionParam347 = &sjt_call77;
#line 56
    sjf_string_add(sjt_parent193, sjt_functionParam347, &sjt_call61);
#line 56
    sjt_parent192 = &sjt_call61;
#line 56
    sjt_functionParam349 = _parent->isleftdown;
#line 56
    sjf_bool_asstring(sjt_functionParam349, &sjt_call78);
#line 56
    sjt_functionParam348 = &sjt_call78;
#line 56
    sjf_string_add(sjt_parent192, sjt_functionParam348, _return);

    if (sjt_call61._refCount == 1) { sjf_string_destroy(&sjt_call61); }
;
    if (sjt_call62._refCount == 1) { sjf_string_destroy(&sjt_call62); }
;
    if (sjt_call63._refCount == 1) { sjf_string_destroy(&sjt_call63); }
;
    if (sjt_call64._refCount == 1) { sjf_string_destroy(&sjt_call64); }
;
    if (sjt_call65._refCount == 1) { sjf_string_destroy(&sjt_call65); }
;
    if (sjt_call66._refCount == 1) { sjf_string_destroy(&sjt_call66); }
;
    if (sjt_call75._refCount == 1) { sjf_string_destroy(&sjt_call75); }
;
    if (sjt_call76._refCount == 1) { sjf_string_destroy(&sjt_call76); }
;
    if (sjt_call77._refCount == 1) { sjf_string_destroy(&sjt_call77); }
;
    if (sjt_call78._refCount == 1) { sjf_string_destroy(&sjt_call78); }
;
}

void sjf_mouseevent_asstring_heap(sjs_mouseevent* _parent, sjs_string** _return) {
    sjs_string sjt_call79 = { -1 };
    sjs_string sjt_call80 = { -1 };
    sjs_string sjt_call81 = { -1 };
    sjs_string sjt_call82 = { -1 };
    sjs_string sjt_call83 = { -1 };
    sjs_string sjt_call84 = { -1 };
    sjs_string sjt_call85 = { -1 };
    sjs_string sjt_call86 = { -1 };
    sjs_string sjt_call87 = { -1 };
    sjs_string sjt_call88 = { -1 };
    sjs_string* sjt_functionParam350 = 0;
    sjs_string* sjt_functionParam351 = 0;
    sjs_string* sjt_functionParam352 = 0;
    bool sjt_functionParam353;
    sjs_string* sjt_functionParam354 = 0;
    sjs_string* sjt_functionParam355 = 0;
    bool sjt_functionParam356;
    sjs_string* sjt_parent202 = 0;
    sjs_string* sjt_parent203 = 0;
    sjs_string* sjt_parent204 = 0;
    sjs_string* sjt_parent205 = 0;
    sjs_string* sjt_parent206 = 0;
    sjs_point* sjt_parent207 = 0;

    sjt_call83._refCount = 1;
#line 56 "lib/ui/mouse.sj"
    sjt_call83.count = 8;
#line 56
    sjt_call83.data._refCount = 1;
#line 56
    sjt_call83.data.datasize = 8;
#line 56
    sjt_call83.data.data = (void*)sjg_string33;
#line 56
    sjt_call83.data.isglobal = true;
#line 56
    sjt_call83.data.count = 8;
#line 56
    sjf_array_char(&sjt_call83.data);
#line 14 "lib/common/string.sj"
    sjt_call83._isnullterminated = false;
#line 14
    sjf_string(&sjt_call83);
#line 56 "lib/ui/mouse.sj"
    sjt_parent206 = &sjt_call83;
#line 5 "lib/ui/point.sj"
    sjt_parent207 = &_parent->point;
#line 5
    sjf_point_asstring(sjt_parent207, &sjt_call84);
#line 56 "lib/ui/mouse.sj"
    sjt_functionParam350 = &sjt_call84;
#line 56
    sjf_string_add(sjt_parent206, sjt_functionParam350, &sjt_call82);
#line 56
    sjt_parent205 = &sjt_call82;
#line 56
    sjt_call85._refCount = 1;
#line 56
    sjt_call85.count = 14;
#line 56
    sjt_call85.data._refCount = 1;
#line 56
    sjt_call85.data.datasize = 14;
#line 56
    sjt_call85.data.data = (void*)sjg_string35;
#line 56
    sjt_call85.data.isglobal = true;
#line 56
    sjt_call85.data.count = 14;
#line 56
    sjf_array_char(&sjt_call85.data);
#line 14 "lib/common/string.sj"
    sjt_call85._isnullterminated = false;
#line 14
    sjf_string(&sjt_call85);
#line 56 "lib/ui/mouse.sj"
    sjt_functionParam351 = &sjt_call85;
#line 56
    sjf_string_add(sjt_parent205, sjt_functionParam351, &sjt_call81);
#line 56
    sjt_parent204 = &sjt_call81;
#line 56
    sjt_functionParam353 = _parent->iscaptured;
#line 56
    sjf_bool_asstring(sjt_functionParam353, &sjt_call86);
#line 56
    sjt_functionParam352 = &sjt_call86;
#line 56
    sjf_string_add(sjt_parent204, sjt_functionParam352, &sjt_call80);
#line 56
    sjt_parent203 = &sjt_call80;
#line 56
    sjt_call87._refCount = 1;
#line 56
    sjt_call87.count = 14;
#line 56
    sjt_call87.data._refCount = 1;
#line 56
    sjt_call87.data.datasize = 14;
#line 56
    sjt_call87.data.data = (void*)sjg_string38;
#line 56
    sjt_call87.data.isglobal = true;
#line 56
    sjt_call87.data.count = 14;
#line 56
    sjf_array_char(&sjt_call87.data);
#line 14 "lib/common/string.sj"
    sjt_call87._isnullterminated = false;
#line 14
    sjf_string(&sjt_call87);
#line 56 "lib/ui/mouse.sj"
    sjt_functionParam354 = &sjt_call87;
#line 56
    sjf_string_add(sjt_parent203, sjt_functionParam354, &sjt_call79);
#line 56
    sjt_parent202 = &sjt_call79;
#line 56
    sjt_functionParam356 = _parent->isleftdown;
#line 56
    sjf_bool_asstring(sjt_functionParam356, &sjt_call88);
#line 56
    sjt_functionParam355 = &sjt_call88;
#line 56
    sjf_string_add_heap(sjt_parent202, sjt_functionParam355, _return);

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
    if (sjt_call86._refCount == 1) { sjf_string_destroy(&sjt_call86); }
;
    if (sjt_call87._refCount == 1) { sjf_string_destroy(&sjt_call87); }
;
    if (sjt_call88._refCount == 1) { sjf_string_destroy(&sjt_call88); }
;
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
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;
    bool sjv_shouldcontinue;

#line 45 "lib/ui/mouse.sj"
    sjv_shouldcontinue = true;
#line 46
    sjt_forStart5 = 0;
#line 46
    sjt_forEnd5 = children->count;
#line 46
    i = sjt_forEnd5 - 1;
    while (i >= sjt_forStart5) {
        if (sjv_shouldcontinue) {
            bool sjt_funcold3;
            int32_t sjt_functionParam25;
            sjs_mouseevent* sjt_interfaceParam9 = 0;
            sjs_array_heap_iface_element* sjt_parent21 = 0;
            sji_element sjt_parent22 = { 0 };
            sji_element sjv_child = { 0 };

#line 44 "lib/ui/mouse.sj"
            sjt_parent21 = children;
#line 46
            sjt_functionParam25 = i;
#line 46
            sjf_array_heap_iface_element_getat_heap(sjt_parent21, sjt_functionParam25, &sjv_child);
#line 6 "lib/ui/element.sj"
            sjt_parent22 = sjv_child;
#line 6
            sjt_funcold3 = sjv_shouldcontinue;
#line 49 "lib/ui/mouse.sj"
            sjt_interfaceParam9 = _parent;
#line 49
            sjt_parent22._vtbl->firemouseevent(sjt_parent22._parent, sjt_interfaceParam9, &sjt_funcold3);
#line 6 "lib/ui/element.sj"
            sjv_shouldcontinue = sjt_funcold3;

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

void sjf_point_asstring(sjs_point* _parent, sjs_string* _return) {
    sjs_string sjt_call67 = { -1 };
    sjs_string sjt_call68 = { -1 };
    sjs_string sjt_call69 = { -1 };
    sjs_string sjt_call70 = { -1 };
    int32_t sjt_functionParam332;
    int32_t sjt_functionParam333;
    sjs_string* sjt_functionParam334 = 0;
    sjs_string* sjt_functionParam335 = 0;
    int32_t sjt_functionParam336;
    int32_t sjt_functionParam337;
    sjs_string* sjt_parent197 = 0;
    sjs_string* sjt_parent198 = 0;

#line 5 "lib/ui/point.sj"
    sjt_functionParam332 = _parent->x;
#line 22 "lib/common/i32.sj"
    sjt_functionParam333 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam332, sjt_functionParam333, &sjt_call68);
#line 5 "lib/ui/point.sj"
    sjt_parent198 = &sjt_call68;
#line 5
    sjt_call69._refCount = 1;
#line 5
    sjt_call69.count = 2;
#line 5
    sjt_call69.data._refCount = 1;
#line 5
    sjt_call69.data.datasize = 2;
#line 5
    sjt_call69.data.data = (void*)sjg_string34;
#line 5
    sjt_call69.data.isglobal = true;
#line 5
    sjt_call69.data.count = 2;
#line 5
    sjf_array_char(&sjt_call69.data);
#line 14 "lib/common/string.sj"
    sjt_call69._isnullterminated = false;
#line 14
    sjf_string(&sjt_call69);
#line 5 "lib/ui/point.sj"
    sjt_functionParam334 = &sjt_call69;
#line 5
    sjf_string_add(sjt_parent198, sjt_functionParam334, &sjt_call67);
#line 5
    sjt_parent197 = &sjt_call67;
#line 5
    sjt_functionParam336 = _parent->y;
#line 22 "lib/common/i32.sj"
    sjt_functionParam337 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam336, sjt_functionParam337, &sjt_call70);
#line 5 "lib/ui/point.sj"
    sjt_functionParam335 = &sjt_call70;
#line 5
    sjf_string_add(sjt_parent197, sjt_functionParam335, _return);

    if (sjt_call67._refCount == 1) { sjf_string_destroy(&sjt_call67); }
;
    if (sjt_call68._refCount == 1) { sjf_string_destroy(&sjt_call68); }
;
    if (sjt_call69._refCount == 1) { sjf_string_destroy(&sjt_call69); }
;
    if (sjt_call70._refCount == 1) { sjf_string_destroy(&sjt_call70); }
;
}

void sjf_point_asstring_heap(sjs_point* _parent, sjs_string** _return) {
    sjs_string sjt_call71 = { -1 };
    sjs_string sjt_call72 = { -1 };
    sjs_string sjt_call73 = { -1 };
    sjs_string sjt_call74 = { -1 };
    int32_t sjt_functionParam338;
    int32_t sjt_functionParam339;
    sjs_string* sjt_functionParam340 = 0;
    sjs_string* sjt_functionParam341 = 0;
    int32_t sjt_functionParam342;
    int32_t sjt_functionParam343;
    sjs_string* sjt_parent199 = 0;
    sjs_string* sjt_parent200 = 0;

#line 5 "lib/ui/point.sj"
    sjt_functionParam338 = _parent->x;
#line 22 "lib/common/i32.sj"
    sjt_functionParam339 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam338, sjt_functionParam339, &sjt_call72);
#line 5 "lib/ui/point.sj"
    sjt_parent200 = &sjt_call72;
#line 5
    sjt_call73._refCount = 1;
#line 5
    sjt_call73.count = 2;
#line 5
    sjt_call73.data._refCount = 1;
#line 5
    sjt_call73.data.datasize = 2;
#line 5
    sjt_call73.data.data = (void*)sjg_string34;
#line 5
    sjt_call73.data.isglobal = true;
#line 5
    sjt_call73.data.count = 2;
#line 5
    sjf_array_char(&sjt_call73.data);
#line 14 "lib/common/string.sj"
    sjt_call73._isnullterminated = false;
#line 14
    sjf_string(&sjt_call73);
#line 5 "lib/ui/point.sj"
    sjt_functionParam340 = &sjt_call73;
#line 5
    sjf_string_add(sjt_parent200, sjt_functionParam340, &sjt_call71);
#line 5
    sjt_parent199 = &sjt_call71;
#line 5
    sjt_functionParam342 = _parent->y;
#line 22 "lib/common/i32.sj"
    sjt_functionParam343 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam342, sjt_functionParam343, &sjt_call74);
#line 5 "lib/ui/point.sj"
    sjt_functionParam341 = &sjt_call74;
#line 5
    sjf_string_add_heap(sjt_parent199, sjt_functionParam341, _return);

    if (sjt_call71._refCount == 1) { sjf_string_destroy(&sjt_call71); }
;
    if (sjt_call72._refCount == 1) { sjf_string_destroy(&sjt_call72); }
;
    if (sjt_call73._refCount == 1) { sjf_string_destroy(&sjt_call73); }
;
    if (sjt_call74._refCount == 1) { sjf_string_destroy(&sjt_call74); }
;
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
    if (_parent->x <= point->x) {
        bool sjt_capture53;

        if (_parent->y <= point->y) {
            bool sjt_capture54;

            if (point->x < (_parent->x + _parent->w)) {
#line 12 "lib/ui/rect.sj"
                sjt_capture54 = (point->y < (_parent->y + _parent->h));
            } else {
#line 12 "lib/ui/rect.sj"
                sjt_capture54 = false;
            }

#line 12 "lib/ui/rect.sj"
            sjt_capture53 = sjt_capture54;
        } else {
#line 12 "lib/ui/rect.sj"
            sjt_capture53 = false;
        }

#line 12 "lib/ui/rect.sj"
        (*_return) = sjt_capture53;
    } else {
#line 12 "lib/ui/rect.sj"
        (*_return) = false;
    }
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
    if (_parent->x == rect->x) {
        bool sjt_capture4;

        if (_parent->y == rect->y) {
            bool sjt_capture5;

            if (_parent->w == rect->w) {
#line 16 "lib/ui/rect.sj"
                sjt_capture5 = (_parent->h == rect->h);
            } else {
#line 16 "lib/ui/rect.sj"
                sjt_capture5 = false;
            }

#line 16 "lib/ui/rect.sj"
            sjt_capture4 = sjt_capture5;
        } else {
#line 16 "lib/ui/rect.sj"
            sjt_capture4 = false;
        }

#line 16 "lib/ui/rect.sj"
        (*_return) = sjt_capture4;
    } else {
#line 16 "lib/ui/rect.sj"
        (*_return) = false;
    }
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

void sjf_renderbuffer(sjs_renderbuffer* _this) {
}

void sjf_renderbuffer_copy(sjs_renderbuffer* _this, sjs_renderbuffer* _from) {
    _this->size._refCount = 1;
#line 1 "lib/ui/renderbuffer.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 1
    _this->id = _from->id;
#line 8
    _this->id = _from->id;
#line 9
    glid_retain(_this->id);
}

void sjf_renderbuffer_destroy(sjs_renderbuffer* _this) {
#line 13 "lib/ui/renderbuffer.sj"
    if (glid_release(_this->id)) {
#line 14
        glDeleteRenderbuffers(1, &_this->id);
#line 15
    }
#line 15
    if (_this->size._refCount == 1) { sjf_size_destroy(&_this->size); }
;
}

void sjf_renderbuffer_heap(sjs_renderbuffer* _this) {
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
    sjs_rect* sjt_functionParam190 = 0;
    sjs_rect* sjt_functionParam191 = 0;

#line 20 "lib/ui/scene2d.sj"
    sjt_functionParam190 = &_parent->windowrect;
#line 20
    sjt_functionParam191 = &_parent->windowrect;
#line 20
    sjf_glpopviewport(sjt_functionParam190, sjt_functionParam191);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result7;
    bool sjt_capture27;
    sjs_mat4 sjt_funcold12 = { -1 };
    sjs_mat4 sjt_funcold13 = { -1 };
    sjs_mat4 sjt_funcold14 = { -1 };
    sjs_size* sjt_functionParam156 = 0;
    sjs_size* sjt_parent85 = 0;

#line 27 "lib/ui/size.sj"
    sjt_parent85 = &_parent->_size;
#line 27 "lib/ui/scene2d.sj"
    sjt_functionParam156 = size;
#line 27
    sjf_size_isequal(sjt_parent85, sjt_functionParam156, &sjt_capture27);
#line 28
    result7 = !sjt_capture27;
    if (result7) {
        float result10;
        float result11;
        int32_t sjt_cast8;
        int32_t sjt_cast9;
        float sjt_functionParam157;
        float sjt_functionParam158;
        float sjt_functionParam159;
        float sjt_functionParam160;
        float sjt_functionParam161;
        float sjt_functionParam162;
        float sjt_functionParam163;
        float sjt_functionParam164;
        float sjt_functionParam165;

        if (_parent->_size._refCount == 1) { sjf_size_destroy(&_parent->_size); }
;
#line 27 "lib/ui/scene2d.sj"
        sjf_size_copy(&_parent->_size, size);
#line 27
        sjt_funcold12._refCount = 1;
#line 170 "lib/ui/mat4.sj"
        sjf_mat4_copy(&sjt_funcold12, &_parent->projection);
#line 30 "lib/ui/scene2d.sj"
        sjt_functionParam157 = 0.0f;
#line 30
        sjt_cast8 = (&_parent->_size)->w;
#line 30
        sjt_functionParam158 = (float)sjt_cast8;
#line 30
        sjt_cast9 = 0 - (&_parent->_size)->h;
#line 30
        sjt_functionParam159 = (float)sjt_cast9;
#line 30
        sjt_functionParam160 = 0.0f;
#line 30
        result10 = -1.0f;
#line 30
        sjt_functionParam161 = result10;
#line 30
        sjt_functionParam162 = 1.0f;
#line 30
        sjf_mat4_orthographic(sjt_functionParam157, sjt_functionParam158, sjt_functionParam159, sjt_functionParam160, sjt_functionParam161, sjt_functionParam162, &sjt_funcold12);
#line 30
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
#line 170 "lib/ui/mat4.sj"
        sjf_mat4_copy(&_parent->projection, &sjt_funcold12);
#line 170
        sjt_funcold13._refCount = 1;
#line 213
        sjf_mat4_copy(&sjt_funcold13, &_parent->model);
#line 31 "lib/ui/scene2d.sj"
        sjt_functionParam163 = 1.0f;
#line 31
        result11 = -1.0f;
#line 31
        sjt_functionParam164 = result11;
#line 31
        sjt_functionParam165 = 1.0f;
#line 31
        sjf_mat4_scale(sjt_functionParam163, sjt_functionParam164, sjt_functionParam165, &sjt_funcold13);
#line 31
        if (_parent->model._refCount == 1) { sjf_mat4_destroy(&_parent->model); }
;
#line 213 "lib/ui/mat4.sj"
        sjf_mat4_copy(&_parent->model, &sjt_funcold13);
#line 213
        sjt_funcold14._refCount = 1;
#line 124
        sjf_mat4_copy(&sjt_funcold14, &_parent->view);
#line 124
        sjf_mat4_identity(&sjt_funcold14);
#line 124
        if (_parent->view._refCount == 1) { sjf_mat4_destroy(&_parent->view); }
;
#line 124
        sjf_mat4_copy(&_parent->view, &sjt_funcold14);
    }

    if (sjt_funcold12._refCount == 1) { sjf_mat4_destroy(&sjt_funcold12); }
;
    if (sjt_funcold13._refCount == 1) { sjf_mat4_destroy(&sjt_funcold13); }
;
    if (sjt_funcold14._refCount == 1) { sjf_mat4_destroy(&sjt_funcold14); }
;
}

void sjf_scene2d_start(sjs_scene2d* _parent) {
    sjs_rect sjt_funcold20 = { -1 };
    sjs_rect* sjt_functionParam187 = 0;
    sjs_rect* sjt_functionParam188 = 0;

    sjt_funcold20._refCount = 1;
#line 1 "lib/ui/rect.sj"
    sjf_rect_copy(&sjt_funcold20, &_parent->windowrect);
#line 1
    sjt_funcold20._refCount = 1;
#line 9 "lib/ui/scene2d.sj"
    sjt_funcold20.x = 0;
#line 9
    sjt_funcold20.y = 0;
#line 9
    sjt_funcold20.w = (&_parent->_size)->w;
#line 9
    sjt_funcold20.h = (&_parent->_size)->h;
#line 9
    sjf_rect(&sjt_funcold20);
#line 9
    if (_parent->windowrect._refCount == 1) { sjf_rect_destroy(&_parent->windowrect); }
;
#line 1 "lib/ui/rect.sj"
    sjf_rect_copy(&_parent->windowrect, &sjt_funcold20);
#line 10 "lib/ui/scene2d.sj"
    sjt_functionParam187 = &_parent->windowrect;
#line 10
    sjt_functionParam188 = &_parent->windowrect;
#line 10
    sjf_glpushviewport(sjt_functionParam187, sjt_functionParam188);
#line 12
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
#line 13
    glEnable( GL_TEXTURE_2D );
#line 14
    glDisable( GL_DEPTH_TEST );

    if (sjt_funcold20._refCount == 1) { sjf_rect_destroy(&sjt_funcold20); }
;
}

void sjf_scene2dmodel_as_sji_model(sjs_scene2dmodel* _this, sji_model* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_scene2dmodel_model_vtbl;
}

void sjf_scene2dmodel_asinterface(sjs_scene2dmodel* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_model_typeId:  {
            sjf_scene2dmodel_as_sji_model(_this, (sji_model*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_scene2dmodel_copy(sjs_scene2dmodel* _this, sjs_scene2dmodel* _from) {
#line 1 "lib/ui/scene2dModel.sj"
    sjs_string* copyoption14 = (_from->id._refCount != -1 ? &_from->id : 0);
    if (copyoption14 != 0) {
        _this->id._refCount = 1;
#line 1 "lib/ui/scene2dModel.sj"
        sjf_string_copy(&_this->id, copyoption14);
    } else {
        _this->id._refCount = -1;
    }

#line 1
    _this->vertexbuffer._refCount = 1;
#line 1
    sjf_vertexbuffer_vertex_location_texture_normal_copy(&_this->vertexbuffer, &_from->vertexbuffer);
#line 1
    _this->shader._refCount = 1;
#line 1
    sjf_shader_copy(&_this->shader, &_from->shader);
#line 1
    _this->texturesize._refCount = 1;
#line 1
    sjf_size_copy(&_this->texturesize, &_from->texturesize);
#line 1
    _this->children._refCount = 1;
#line 1
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
#line 1
    _this->hasalpha = _from->hasalpha;
#line 1
    _this->center._refCount = 1;
#line 1
    sjf_vec3_copy(&_this->center, &_from->center);
#line 1
    _this->model._refCount = 1;
#line 1
    sjf_mat4_copy(&_this->model, &_from->model);
#line 1
    _this->_innerscene._refCount = 1;
#line 1
    sjf_scene2d_copy(&_this->_innerscene, &_from->_innerscene);
#line 1
    _this->_scenerect._refCount = 1;
#line 1
    sjf_rect_copy(&_this->_scenerect, &_from->_scenerect);
#line 1
    _this->_projection._refCount = 1;
#line 1
    sjf_mat4_copy(&_this->_projection, &_from->_projection);
#line 1
    _this->_world._refCount = 1;
#line 1
    sjf_mat4_copy(&_this->_world, &_from->_world);
#line 1
    _this->_view._refCount = 1;
#line 1
    sjf_mat4_copy(&_this->_view, &_from->_view);
#line 1
    _this->_light._refCount = 1;
#line 1
    sjf_light_copy(&_this->_light, &_from->_light);
#line 1
    _this->_projectedcenter._refCount = 1;
#line 1
    sjf_vec4_copy(&_this->_projectedcenter, &_from->_projectedcenter);
#line 1
    _this->_framebuffer._refCount = 1;
#line 1
    sjf_framebuffer_copy(&_this->_framebuffer, &_from->_framebuffer);
#line 1
    _this->_texture._refCount = 1;
#line 1
    sjf_texture_copy(&_this->_texture, &_from->_texture);
#line 1
    _this->_renderbuffer._refCount = 1;
#line 1
    sjf_renderbuffer_copy(&_this->_renderbuffer, &_from->_renderbuffer);
}

void sjf_scene2dmodel_destroy(sjs_scene2dmodel* _this) {
    if (_this->id._refCount == 1) { sjf_string_destroy(&_this->id); }
;
    if (_this->vertexbuffer._refCount == 1) { sjf_vertexbuffer_vertex_location_texture_normal_destroy(&_this->vertexbuffer); }
;
    if (_this->shader._refCount == 1) { sjf_shader_destroy(&_this->shader); }
;
    if (_this->texturesize._refCount == 1) { sjf_size_destroy(&_this->texturesize); }
;
    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->center._refCount == 1) { sjf_vec3_destroy(&_this->center); }
;
    if (_this->model._refCount == 1) { sjf_mat4_destroy(&_this->model); }
;
    if (_this->_innerscene._refCount == 1) { sjf_scene2d_destroy(&_this->_innerscene); }
;
    if (_this->_scenerect._refCount == 1) { sjf_rect_destroy(&_this->_scenerect); }
;
    if (_this->_projection._refCount == 1) { sjf_mat4_destroy(&_this->_projection); }
;
    if (_this->_world._refCount == 1) { sjf_mat4_destroy(&_this->_world); }
;
    if (_this->_view._refCount == 1) { sjf_mat4_destroy(&_this->_view); }
;
    if (_this->_light._refCount == 1) { sjf_light_destroy(&_this->_light); }
;
    if (_this->_projectedcenter._refCount == 1) { sjf_vec4_destroy(&_this->_projectedcenter); }
;
    if (_this->_framebuffer._refCount == 1) { sjf_framebuffer_destroy(&_this->_framebuffer); }
;
    if (_this->_texture._refCount == 1) { sjf_texture_destroy(&_this->_texture); }
;
    if (_this->_renderbuffer._refCount == 1) { sjf_renderbuffer_destroy(&_this->_renderbuffer); }
;
}

void sjf_scene2dmodel_firemouseevent(sjs_scene2dmodel* _parent, sjs_mouseevent* mouseevent) {
    sjs_mat4 sjt_call30 = { -1 };
    sjs_point* sjt_functionParam286 = 0;
    sjs_rect* sjt_functionParam287 = 0;
    sjs_mat4* sjt_functionParam288 = 0;
    sjs_mat4* sjt_functionParam289 = 0;
    sjs_mat4* sjt_functionParam290 = 0;
    sjs_mat4* sjt_functionParam291 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent163 = 0;
    sjs_mat4* sjt_parent164 = 0;
    sjs_vec2 sjv_texture = { -1 };

#line 43 "lib/ui/vertexBuffer.sj"
    sjt_parent163 = &_parent->vertexbuffer;
#line 72 "lib/ui/scene2dModel.sj"
    sjt_functionParam286 = &mouseevent->point;
#line 72
    sjt_functionParam287 = &_parent->_scenerect;
#line 72
    sjt_functionParam288 = &_parent->_projection;
#line 72
    sjt_functionParam289 = &_parent->_view;
#line 19 "lib/ui/mat4.sj"
    sjt_parent164 = &_parent->_world;
#line 72 "lib/ui/scene2dModel.sj"
    sjt_functionParam291 = &_parent->model;
#line 72
    sjf_mat4_multiply(sjt_parent164, sjt_functionParam291, &sjt_call30);
#line 72
    sjt_functionParam290 = &sjt_call30;
#line 72
    sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture(sjt_parent163, sjt_functionParam286, sjt_functionParam287, sjt_functionParam288, sjt_functionParam289, sjt_functionParam290, &sjv_texture);
    if (((sjv_texture._refCount != -1 ? &sjv_texture : 0) != 0)) {
        sjs_vec2* ifValue7 = 0;
        sjs_lambda2 sjt_call58 = { -1 };
        float sjt_cast19;
        int32_t sjt_cast20;
        float sjt_cast21;
        int32_t sjt_cast22;
        int32_t sjt_functionParam329;
        cb_string_heap_string sjt_functionParam330;
        sjs_array_heap_iface_element* sjt_functionParam369 = 0;
        sjs_log* sjt_parent189 = 0;
        sjs_mouseevent* sjt_parent218 = 0;
        bool sjt_void1;
        sjs_mouseevent sjv_newmouseevent = { -1 };
        sjs_point sjv_scenepoint = { -1 };

#line 73 "lib/ui/scene2dModel.sj"
        ifValue7 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
#line 22 "lib/common/log.sj"
        sjt_parent189 = &sjv_log;
#line 74 "lib/ui/scene2dModel.sj"
        sjt_functionParam329 = 150;
#line 74
        sjs_lambda2* lambainit2;
#line 74
        sjt_call58._refCount = 1;
#line 71
        sjt_call58.lambdaparam3 = mouseevent;
#line 74
        sjt_call58.lambdaparam4 = ifValue7;
#line 71
        sjt_call58.lambdaparam5 = mouseevent;
#line 71
        sjf_lambda2(&sjt_call58);
#line 74
        lambainit2 = &sjt_call58;
#line 74
        sjt_functionParam330._parent = (sjs_object*)lambainit2;
#line 74
        sjt_functionParam330._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda2_invoke;
#line 74
        sjt_functionParam330._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda2_invoke_heap;
#line 74
        sjf_log_trace(sjt_parent189, sjt_functionParam329, sjt_functionParam330);
#line 74
        sjv_scenepoint._refCount = 1;
#line 76
        sjt_cast20 = (&_parent->texturesize)->w;
#line 76
        sjt_cast19 = ifValue7->x * (float)sjt_cast20;
#line 76
        sjv_scenepoint.x = (int32_t)sjt_cast19;
#line 77
        sjt_cast22 = (&_parent->texturesize)->h;
#line 77
        sjt_cast21 = ifValue7->y * (float)sjt_cast22;
#line 77
        sjv_scenepoint.y = ((&_parent->texturesize)->h - 1) - (int32_t)sjt_cast21;
#line 77
        sjf_point(&sjv_scenepoint);
#line 77
        sjv_newmouseevent._refCount = 1;
#line 79
        sjv_newmouseevent.eventtype = mouseevent->eventtype;
#line 79
        sjv_newmouseevent.point._refCount = 1;
#line 79
        sjf_point_copy(&sjv_newmouseevent.point, &sjv_scenepoint);
#line 79
        sjv_newmouseevent.iscaptured = mouseevent->iscaptured;
#line 79
        sjv_newmouseevent.isleftdown = mouseevent->isleftdown;
#line 79
        sjf_mouseevent(&sjv_newmouseevent);
#line 44 "lib/ui/mouse.sj"
        sjt_parent218 = &sjv_newmouseevent;
#line 86 "lib/ui/scene2dModel.sj"
        sjt_functionParam369 = &_parent->children;
#line 86
        sjf_mouseevent_firechildren(sjt_parent218, sjt_functionParam369, &sjt_void1);

        if (sjt_call58._refCount == 1) { sjf_lambda2_destroy(&sjt_call58); }
;
        if (sjv_newmouseevent._refCount == 1) { sjf_mouseevent_destroy(&sjv_newmouseevent); }
;
        if (sjv_scenepoint._refCount == 1) { sjf_point_destroy(&sjv_scenepoint); }
;
    } else {
        sjs_lambda1 sjt_call103 = { -1 };
        int32_t sjt_functionParam370;
        cb_string_heap_string sjt_functionParam371;
        sjs_log* sjt_parent219 = 0;

#line 22 "lib/common/log.sj"
        sjt_parent219 = &sjv_log;
#line 88 "lib/ui/scene2dModel.sj"
        sjt_functionParam370 = 150;
#line 88
        sjs_lambda1* lambainit1;
#line 88
        sjt_call103._refCount = 1;
#line 71
        sjt_call103.lambdaparam1 = mouseevent;
#line 71
        sjt_call103.lambdaparam2 = mouseevent;
#line 71
        sjf_lambda1(&sjt_call103);
#line 88
        lambainit1 = &sjt_call103;
#line 88
        sjt_functionParam371._parent = (sjs_object*)lambainit1;
#line 88
        sjt_functionParam371._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda1_invoke;
#line 88
        sjt_functionParam371._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda1_invoke_heap;
#line 88
        sjf_log_trace(sjt_parent219, sjt_functionParam370, sjt_functionParam371);

        if (sjt_call103._refCount == 1) { sjf_lambda1_destroy(&sjt_call103); }
;
    }

    if (sjt_call30._refCount == 1) { sjf_mat4_destroy(&sjt_call30); }
;
    if (sjv_texture._refCount == 1) { sjf_vec2_destroy(&sjv_texture); }
;
}

void sjf_scene2dmodel_getcenter(sjs_scene2dmodel* _parent, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 33 "lib/ui/scene2dModel.sj"
    sjf_vec3_copy(_return, &_parent->center);
}

void sjf_scene2dmodel_getcenter_heap(sjs_scene2dmodel* _parent, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
#line 33 "lib/ui/scene2dModel.sj"
    sjf_vec3_copy((*_return), &_parent->center);
}

void sjf_scene2dmodel_getclasstype(sjs_object* _this, int* _return) {
    *_return = 150;
}

void sjf_scene2dmodel_getworld(sjs_scene2dmodel* _parent, sjs_mat4* _return) {
    sjs_mat4* sjt_functionParam178 = 0;
    sjs_mat4* sjt_parent93 = 0;

#line 19 "lib/ui/mat4.sj"
    sjt_parent93 = &_parent->_world;
#line 34 "lib/ui/scene2dModel.sj"
    sjt_functionParam178 = &_parent->model;
#line 34
    sjf_mat4_multiply(sjt_parent93, sjt_functionParam178, _return);
}

void sjf_scene2dmodel_getworld_heap(sjs_scene2dmodel* _parent, sjs_mat4** _return) {
    sjs_mat4* sjt_functionParam179 = 0;
    sjs_mat4* sjt_parent94 = 0;

#line 19 "lib/ui/mat4.sj"
    sjt_parent94 = &_parent->_world;
#line 34 "lib/ui/scene2dModel.sj"
    sjt_functionParam179 = &_parent->model;
#line 34
    sjf_mat4_multiply_heap(sjt_parent94, sjt_functionParam179, _return);
}

void sjf_scene2dmodel_getz(sjs_scene2dmodel* _parent, float* _return) {
#line 32 "lib/ui/scene2dModel.sj"
    (*_return) = (&_parent->_projectedcenter)->z;
}

void sjf_scene2dmodel_heap(sjs_scene2dmodel* _this) {
    int32_t i;
    sjs_string sjt_call12 = { -1 };
    int32_t sjt_forEnd10;
    int32_t sjt_forStart10;
    sjs_renderbuffer sjt_funcold10 = { -1 };
    sjs_framebuffer sjt_funcold8 = { -1 };
    sjs_texture sjt_funcold9 = { -1 };
    sjs_size* sjt_functionParam110 = 0;
    sjs_size* sjt_functionParam111 = 0;
    sjs_size* sjt_functionParam112 = 0;
    sjs_framebuffer* sjt_functionParam119 = 0;
    int32_t sjt_functionParam120;
    sjs_texture* sjt_functionParam121 = 0;
    int32_t sjt_functionParam122;
    int32_t sjt_functionParam123;
    int32_t sjt_functionParam124;
    int32_t sjt_functionParam125;
    int32_t sjt_functionParam126;
    int32_t sjt_functionParam127;
    int32_t sjt_functionParam128;
    int32_t sjt_functionParam129;
    int32_t sjt_functionParam130;
    int32_t sjt_functionParam131;
    int32_t sjt_functionParam132;
    int32_t sjt_functionParam133;
    int32_t sjt_functionParam134;
    int32_t sjt_functionParam135;
    int32_t sjt_functionParam136;
    sjs_size* sjt_functionParam137 = 0;
    int32_t sjt_functionParam138;
    void* sjt_functionParam139;
    int32_t sjt_functionParam140;
    int32_t sjt_functionParam141;
    sjs_texture* sjt_functionParam142 = 0;
    int32_t sjt_functionParam143;
    sjs_renderbuffer* sjt_functionParam144 = 0;
    int32_t sjt_functionParam145;
    sjs_size* sjt_functionParam146 = 0;
    int32_t sjt_functionParam147;
    sjs_renderbuffer* sjt_functionParam148 = 0;
    sjs_framebuffer* sjt_functionParam155 = 0;
    sjs_size* sjt_functionParam166 = 0;
    sjs_scene2d* sjt_parent86 = 0;
    sjs_rect sjv_rect = { -1 };
    int32_t sjv_status;

    if (((_this->id._refCount != -1 ? &_this->id : 0) != 0)) {
        sjs_string* ifValue12 = 0;
        sjs_scene2dmodel* sjt_cast7 = 0;
        sjs_string* sjt_functionParam108 = 0;
        sji_model sjt_functionParam109 = { 0 };
        sjs_hash_string_weak_iface_model* sjt_parent73 = 0;

#line 92 "lib/ui/scene2dModel.sj"
        ifValue12 = (_this->id._refCount != -1 ? &_this->id : 0);
#line 38 "lib/common/hash.sj"
        sjt_parent73 = &sjv_modelsbyid;
#line 93 "lib/ui/scene2dModel.sj"
        sjt_functionParam108 = ifValue12;
#line 1
        sjt_cast7 = _this;
#line 1 "lib/ui/model.sj"
        sjf_scene2dmodel_as_sji_model(sjt_cast7, &sjt_functionParam109);
#line 1
        delete_cb weakptrcb14 = { &sjt_functionParam109._parent, weakptr_clear };
#line 1
        if (sjt_functionParam109._parent != 0) { weakptr_cb_add(sjt_functionParam109._parent, weakptrcb14); }
#line 1
        sjf_hash_string_weak_iface_model_setat(sjt_parent73, sjt_functionParam108, sjt_functionParam109);

        delete_cb weakptrcb15 = { &sjt_functionParam109._parent, weakptr_clear };
        if (sjt_functionParam109._parent != 0) { weakptr_cb_remove(sjt_functionParam109._parent, weakptrcb15); }
    }

    sjt_funcold8._refCount = 1;
#line 208 "lib/ui/gl.sj"
    sjf_framebuffer_copy(&sjt_funcold8, &_this->_framebuffer);
#line 96 "lib/ui/scene2dModel.sj"
    sjt_functionParam110 = &_this->texturesize;
#line 96
    sjf_glgenframebuffer(sjt_functionParam110, &sjt_funcold8);
#line 96
    if (_this->_framebuffer._refCount == 1) { sjf_framebuffer_destroy(&_this->_framebuffer); }
;
#line 208 "lib/ui/gl.sj"
    sjf_framebuffer_copy(&_this->_framebuffer, &sjt_funcold8);
#line 208
    sjt_funcold9._refCount = 1;
#line 216
    sjf_texture_copy(&sjt_funcold9, &_this->_texture);
#line 97 "lib/ui/scene2dModel.sj"
    sjt_functionParam111 = &_this->texturesize;
#line 97
    sjf_glgentexture(sjt_functionParam111, &sjt_funcold9);
#line 97
    if (_this->_texture._refCount == 1) { sjf_texture_destroy(&_this->_texture); }
;
#line 216 "lib/ui/gl.sj"
    sjf_texture_copy(&_this->_texture, &sjt_funcold9);
#line 216
    sjt_funcold10._refCount = 1;
#line 242
    sjf_renderbuffer_copy(&sjt_funcold10, &_this->_renderbuffer);
#line 98 "lib/ui/scene2dModel.sj"
    sjt_functionParam112 = &_this->texturesize;
#line 98
    sjf_glgenrenderbuffer(sjt_functionParam112, &sjt_funcold10);
#line 98
    if (_this->_renderbuffer._refCount == 1) { sjf_renderbuffer_destroy(&_this->_renderbuffer); }
;
#line 242 "lib/ui/gl.sj"
    sjf_renderbuffer_copy(&_this->_renderbuffer, &sjt_funcold10);
#line 100 "lib/ui/scene2dModel.sj"
    sjt_functionParam119 = &_this->_framebuffer;
#line 100
    sjf_glpushframebuffer(sjt_functionParam119);
#line 101
    sjt_functionParam120 = sjv_gltexture_gl_texture_2d;
#line 101
    sjt_functionParam121 = &_this->_texture;
#line 101
    sjf_glbindtexture(sjt_functionParam120, sjt_functionParam121);
#line 102
    sjt_functionParam122 = sjv_gltexture_gl_texture_2d;
#line 102
    sjt_functionParam123 = sjv_gltextureattribute_gl_texture_wrap_s;
#line 102
    sjt_functionParam124 = sjv_gltexturevalue_gl_clamp_to_edge;
#line 102
    sjf_gltexparameteri(sjt_functionParam122, sjt_functionParam123, sjt_functionParam124);
#line 103
    sjt_functionParam125 = sjv_gltexture_gl_texture_2d;
#line 103
    sjt_functionParam126 = sjv_gltextureattribute_gl_texture_wrap_t;
#line 103
    sjt_functionParam127 = sjv_gltexturevalue_gl_clamp_to_edge;
#line 103
    sjf_gltexparameteri(sjt_functionParam125, sjt_functionParam126, sjt_functionParam127);
#line 104
    sjt_functionParam128 = sjv_gltexture_gl_texture_2d;
#line 104
    sjt_functionParam129 = sjv_gltextureattribute_gl_texture_min_filter;
#line 104
    sjt_functionParam130 = sjv_gltexturevalue_gl_linear;
#line 104
    sjf_gltexparameteri(sjt_functionParam128, sjt_functionParam129, sjt_functionParam130);
#line 105
    sjt_functionParam131 = sjv_gltexture_gl_texture_2d;
#line 105
    sjt_functionParam132 = sjv_gltextureattribute_gl_texture_mag_filter;
#line 105
    sjt_functionParam133 = sjv_gltexturevalue_gl_linear;
#line 105
    sjf_gltexparameteri(sjt_functionParam131, sjt_functionParam132, sjt_functionParam133);
#line 106
    sjt_functionParam134 = sjv_gltexture_gl_texture_2d;
#line 106
    sjt_functionParam135 = 0;
#line 106
    sjt_functionParam136 = sjv_gltextureformat_gl_rgba;
#line 106
    sjt_functionParam137 = &_this->texturesize;
#line 106
    sjt_functionParam138 = sjv_gltexturetype_gl_unsigned_byte;
#line 230 "lib/ui/gl.sj"
    sjt_functionParam139 = 0;
#line 230
    sjf_glteximage2d(sjt_functionParam134, sjt_functionParam135, sjt_functionParam136, sjt_functionParam137, sjt_functionParam138, sjt_functionParam139);
#line 107 "lib/ui/scene2dModel.sj"
    sjt_functionParam140 = sjv_glframebufferattachment_gl_color_attachment0;
#line 107
    sjt_functionParam141 = sjv_glframebuffertexture_gl_texture_2d;
#line 107
    sjt_functionParam142 = &_this->_texture;
#line 107
    sjt_functionParam143 = 0;
#line 107
    sjf_glframebuffertexture2d(sjt_functionParam140, sjt_functionParam141, sjt_functionParam142, sjt_functionParam143);
#line 109
    sjt_functionParam144 = &_this->_renderbuffer;
#line 109
    sjf_glbindrenderbuffer(sjt_functionParam144);
#line 110
    sjt_functionParam145 = sjv_glrenderbufferformat_gl_depth_component16;
#line 110
    sjt_functionParam146 = &_this->texturesize;
#line 110
    sjf_glrenderbufferstorage(sjt_functionParam145, sjt_functionParam146);
#line 111
    sjt_functionParam147 = sjv_glframebufferattachment_gl_depth_attachment;
#line 111
    sjt_functionParam148 = &_this->_renderbuffer;
#line 111
    sjf_glframebufferrenderbuffer(sjt_functionParam147, sjt_functionParam148);
#line 111
    sjf_glcheckframebufferstatus(&sjv_status);
    if (sjv_status != sjv_glframebufferstatus_gl_framebuffer_complete) {
        sjs_string* sjt_functionParam149 = 0;

        sjt_call12._refCount = 1;
#line 115 "lib/ui/scene2dModel.sj"
        sjt_call12.count = 18;
#line 115
        sjt_call12.data._refCount = 1;
#line 115
        sjt_call12.data.datasize = 18;
#line 115
        sjt_call12.data.data = (void*)sjg_string41;
#line 115
        sjt_call12.data.isglobal = true;
#line 115
        sjt_call12.data.count = 18;
#line 115
        sjf_array_char(&sjt_call12.data);
#line 14 "lib/common/string.sj"
        sjt_call12._isnullterminated = false;
#line 14
        sjf_string(&sjt_call12);
#line 115 "lib/ui/scene2dModel.sj"
        sjt_functionParam149 = &sjt_call12;
#line 115
        sjf_halt(sjt_functionParam149);
    }

#line 117
    sjt_functionParam155 = &_this->_framebuffer;
#line 117
    sjf_glpopframebuffer(sjt_functionParam155);
#line 27 "lib/ui/scene2d.sj"
    sjt_parent86 = &_this->_innerscene;
#line 119 "lib/ui/scene2dModel.sj"
    sjt_functionParam166 = &_this->texturesize;
#line 119
    sjf_scene2d_setsize(sjt_parent86, sjt_functionParam166);
#line 119
    sjv_rect._refCount = 1;
#line 120
    sjv_rect.x = 0;
#line 120
    sjv_rect.y = 0;
#line 120
    sjv_rect.w = (&_this->texturesize)->w;
#line 120
    sjv_rect.h = (&_this->texturesize)->h;
#line 120
    sjf_rect(&sjv_rect);
#line 121
    sjt_forStart10 = 0;
#line 121
    sjt_forEnd10 = (&_this->children)->count;
#line 121
    i = sjt_forStart10;
    while (i < sjt_forEnd10) {
        int32_t sjt_functionParam167;
        sjs_rect* sjt_interfaceParam17 = 0;
        sjs_array_heap_iface_element* sjt_parent87 = 0;
        sji_element sjt_parent88 = { 0 };
        sji_element sjv_child = { 0 };

#line 7 "lib/common/array.sj"
        sjt_parent87 = &_this->children;
#line 121 "lib/ui/scene2dModel.sj"
        sjt_functionParam167 = i;
#line 121
        sjf_array_heap_iface_element_getat_heap(sjt_parent87, sjt_functionParam167, &sjv_child);
#line 4 "lib/ui/element.sj"
        sjt_parent88 = sjv_child;
#line 123 "lib/ui/scene2dModel.sj"
        sjt_interfaceParam17 = &sjv_rect;
#line 123
        sjt_parent88._vtbl->setrect(sjt_parent88._parent, sjt_interfaceParam17);
#line 121
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
;
    if (sjt_funcold10._refCount == 1) { sjf_renderbuffer_destroy(&sjt_funcold10); }
;
    if (sjt_funcold8._refCount == 1) { sjf_framebuffer_destroy(&sjt_funcold8); }
;
    if (sjt_funcold9._refCount == 1) { sjf_texture_destroy(&sjt_funcold9); }
;
    if (sjv_rect._refCount == 1) { sjf_rect_destroy(&sjv_rect); }
;
}

void sjf_scene2dmodel_render(sjs_scene2dmodel* _parent) {
    int32_t i;
    sjs_mat4 sjt_call18 = { -1 };
    sjs_mat4 sjt_call19 = { -1 };
    sjs_string sjt_call20 = { -1 };
    sjs_string sjt_call21 = { -1 };
    sjs_string sjt_call22 = { -1 };
    sjs_string sjt_call23 = { -1 };
    sjs_string sjt_call24 = { -1 };
    sjs_vec3 sjt_call25 = { -1 };
    sjs_string sjt_call26 = { -1 };
    sjs_vec3 sjt_call27 = { -1 };
    int32_t sjt_forEnd11;
    int32_t sjt_forStart11;
    sjs_framebuffer* sjt_functionParam186 = 0;
    sjs_framebuffer* sjt_functionParam192 = 0;
    int32_t sjt_functionParam193;
    sjs_mat4* sjt_functionParam194 = 0;
    sjs_mat4* sjt_functionParam195 = 0;
    sjs_shader* sjt_functionParam198 = 0;
    int32_t sjt_functionParam199;
    int32_t sjt_functionParam200;
    int32_t sjt_functionParam201;
    sjs_texture* sjt_functionParam202 = 0;
    int32_t sjt_functionParam203;
    sjs_shader* sjt_functionParam204 = 0;
    sjs_string* sjt_functionParam205 = 0;
    sjs_mat4* sjt_functionParam206 = 0;
    int32_t sjt_functionParam207;
    sjs_shader* sjt_functionParam208 = 0;
    sjs_string* sjt_functionParam209 = 0;
    sjs_mat4* sjt_functionParam210 = 0;
    int32_t sjt_functionParam211;
    sjs_shader* sjt_functionParam212 = 0;
    sjs_string* sjt_functionParam213 = 0;
    sjs_mat4* sjt_functionParam214 = 0;
    int32_t sjt_functionParam215;
    sjs_shader* sjt_functionParam216 = 0;
    sjs_string* sjt_functionParam217 = 0;
    sjs_vec3* sjt_functionParam218 = 0;
    int32_t sjt_functionParam219;
    sjs_shader* sjt_functionParam220 = 0;
    sjs_string* sjt_functionParam221 = 0;
    sjs_vec3* sjt_functionParam222 = 0;
    int32_t sjt_functionParam223;
    sjs_shader* sjt_functionParam224 = 0;
    sjs_string* sjt_functionParam225 = 0;
    sjs_vec3* sjt_functionParam226 = 0;
    int32_t sjt_functionParam227;
    sjs_scene2d* sjt_parent101 = 0;
    sjs_mat4* sjt_parent102 = 0;
    sjs_mat4* sjt_parent103 = 0;
    sjs_mat4* sjt_parent104 = 0;
    sjs_mat4* sjt_parent107 = 0;
    sjs_color* sjt_parent108 = 0;
    sjs_color* sjt_parent109 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent110 = 0;
    sjs_scene2d* sjt_parent98 = 0;
    sjs_mat4 sjv_normalmat = { -1 };
    sjs_mat4 sjv_viewworld = { -1 };

#line 45 "lib/ui/scene2dModel.sj"
    sjt_functionParam186 = &_parent->_framebuffer;
#line 45
    sjf_glpushframebuffer(sjt_functionParam186);
#line 8 "lib/ui/scene2d.sj"
    sjt_parent98 = &_parent->_innerscene;
#line 8
    sjf_scene2d_start(sjt_parent98);
#line 48 "lib/ui/scene2dModel.sj"
    sjt_forStart11 = 0;
#line 48
    sjt_forEnd11 = (&_parent->children)->count;
#line 48
    i = sjt_forStart11;
    while (i < sjt_forEnd11) {
        int32_t sjt_functionParam189;
        sjs_scene2d* sjt_interfaceParam18 = 0;
        sji_element sjt_parent100 = { 0 };
        sjs_array_heap_iface_element* sjt_parent99 = 0;
        sji_element sjv_child = { 0 };

#line 7 "lib/common/array.sj"
        sjt_parent99 = &_parent->children;
#line 48 "lib/ui/scene2dModel.sj"
        sjt_functionParam189 = i;
#line 48
        sjf_array_heap_iface_element_getat_heap(sjt_parent99, sjt_functionParam189, &sjv_child);
#line 5 "lib/ui/element.sj"
        sjt_parent100 = sjv_child;
#line 50 "lib/ui/scene2dModel.sj"
        sjt_interfaceParam18 = &_parent->_innerscene;
#line 50
        sjt_parent100._vtbl->render(sjt_parent100._parent, sjt_interfaceParam18);
#line 48
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

#line 19 "lib/ui/scene2d.sj"
    sjt_parent101 = &_parent->_innerscene;
#line 19
    sjf_scene2d_end(sjt_parent101);
#line 54 "lib/ui/scene2dModel.sj"
    sjt_functionParam192 = &_parent->_framebuffer;
#line 54
    sjf_glpopframebuffer(sjt_functionParam192);
#line 56
    sjt_functionParam193 = sjv_glfeature_gl_depth_test;
#line 56
    sjf_glenable(sjt_functionParam193);
#line 19 "lib/ui/mat4.sj"
    sjt_parent103 = &_parent->_view;
#line 57 "lib/ui/scene2dModel.sj"
    sjt_functionParam194 = &_parent->_world;
#line 57
    sjf_mat4_multiply(sjt_parent103, sjt_functionParam194, &sjt_call18);
#line 57
    sjt_parent102 = &sjt_call18;
#line 57
    sjt_functionParam195 = &_parent->model;
#line 57
    sjf_mat4_multiply(sjt_parent102, sjt_functionParam195, &sjv_viewworld);
#line 71 "lib/ui/mat4.sj"
    sjt_parent107 = &sjv_viewworld;
#line 71
    sjf_mat4_invert(sjt_parent107, &sjt_call19);
#line 58 "lib/ui/scene2dModel.sj"
    sjt_parent104 = &sjt_call19;
#line 58
    sjf_mat4_transpose(sjt_parent104, &sjv_normalmat);
#line 59
    sjt_functionParam198 = &_parent->shader;
#line 59
    sjf_gluseprogram(sjt_functionParam198);
#line 60
    sjt_functionParam199 = sjv_glblendfunctype_gl_src_alpha;
#line 60
    sjt_functionParam200 = sjv_glblendfunctype_gl_one_minus_src_alpha;
#line 60
    sjf_glblendfunc(sjt_functionParam199, sjt_functionParam200);
#line 61
    sjt_functionParam201 = sjv_gltexture_gl_texture_2d;
#line 61
    sjt_functionParam202 = &_parent->_texture;
#line 61
    sjf_glbindtexture(sjt_functionParam201, sjt_functionParam202);
#line 62
    sjt_functionParam204 = &_parent->shader;
#line 62
    sjt_call20._refCount = 1;
#line 62
    sjt_call20.count = 9;
#line 62
    sjt_call20.data._refCount = 1;
#line 62
    sjt_call20.data.datasize = 9;
#line 62
    sjt_call20.data.data = (void*)sjg_string18;
#line 62
    sjt_call20.data.isglobal = true;
#line 62
    sjt_call20.data.count = 9;
#line 62
    sjf_array_char(&sjt_call20.data);
#line 14 "lib/common/string.sj"
    sjt_call20._isnullterminated = false;
#line 14
    sjf_string(&sjt_call20);
#line 62 "lib/ui/scene2dModel.sj"
    sjt_functionParam205 = &sjt_call20;
#line 62
    sjf_glgetuniformlocation(sjt_functionParam204, sjt_functionParam205, &sjt_functionParam203);
#line 62
    sjt_functionParam206 = &sjv_viewworld;
#line 62
    sjf_gluniformmat4(sjt_functionParam203, sjt_functionParam206);
#line 63
    sjt_functionParam208 = &_parent->shader;
#line 63
    sjt_call21._refCount = 1;
#line 63
    sjt_call21.count = 9;
#line 63
    sjt_call21.data._refCount = 1;
#line 63
    sjt_call21.data.datasize = 9;
#line 63
    sjt_call21.data.data = (void*)sjg_string19;
#line 63
    sjt_call21.data.isglobal = true;
#line 63
    sjt_call21.data.count = 9;
#line 63
    sjf_array_char(&sjt_call21.data);
#line 14 "lib/common/string.sj"
    sjt_call21._isnullterminated = false;
#line 14
    sjf_string(&sjt_call21);
#line 63 "lib/ui/scene2dModel.sj"
    sjt_functionParam209 = &sjt_call21;
#line 63
    sjf_glgetuniformlocation(sjt_functionParam208, sjt_functionParam209, &sjt_functionParam207);
#line 63
    sjt_functionParam210 = &sjv_normalmat;
#line 63
    sjf_gluniformmat4(sjt_functionParam207, sjt_functionParam210);
#line 64
    sjt_functionParam212 = &_parent->shader;
#line 64
    sjt_call22._refCount = 1;
#line 64
    sjt_call22.count = 10;
#line 64
    sjt_call22.data._refCount = 1;
#line 64
    sjt_call22.data.datasize = 10;
#line 64
    sjt_call22.data.data = (void*)sjg_string20;
#line 64
    sjt_call22.data.isglobal = true;
#line 64
    sjt_call22.data.count = 10;
#line 64
    sjf_array_char(&sjt_call22.data);
#line 14 "lib/common/string.sj"
    sjt_call22._isnullterminated = false;
#line 14
    sjf_string(&sjt_call22);
#line 64 "lib/ui/scene2dModel.sj"
    sjt_functionParam213 = &sjt_call22;
#line 64
    sjf_glgetuniformlocation(sjt_functionParam212, sjt_functionParam213, &sjt_functionParam211);
#line 64
    sjt_functionParam214 = &_parent->_projection;
#line 64
    sjf_gluniformmat4(sjt_functionParam211, sjt_functionParam214);
#line 65
    sjt_functionParam216 = &_parent->shader;
#line 65
    sjt_call23._refCount = 1;
#line 65
    sjt_call23.count = 8;
#line 65
    sjt_call23.data._refCount = 1;
#line 65
    sjt_call23.data.datasize = 8;
#line 65
    sjt_call23.data.data = (void*)sjg_string21;
#line 65
    sjt_call23.data.isglobal = true;
#line 65
    sjt_call23.data.count = 8;
#line 65
    sjf_array_char(&sjt_call23.data);
#line 14 "lib/common/string.sj"
    sjt_call23._isnullterminated = false;
#line 14
    sjf_string(&sjt_call23);
#line 65 "lib/ui/scene2dModel.sj"
    sjt_functionParam217 = &sjt_call23;
#line 65
    sjf_glgetuniformlocation(sjt_functionParam216, sjt_functionParam217, &sjt_functionParam215);
#line 65
    sjt_functionParam218 = &(&_parent->_light)->pos;
#line 65
    sjf_gluniformvec3(sjt_functionParam215, sjt_functionParam218);
#line 66
    sjt_functionParam220 = &_parent->shader;
#line 66
    sjt_call24._refCount = 1;
#line 66
    sjt_call24.count = 12;
#line 66
    sjt_call24.data._refCount = 1;
#line 66
    sjt_call24.data.datasize = 12;
#line 66
    sjt_call24.data.data = (void*)sjg_string22;
#line 66
    sjt_call24.data.isglobal = true;
#line 66
    sjt_call24.data.count = 12;
#line 66
    sjf_array_char(&sjt_call24.data);
#line 14 "lib/common/string.sj"
    sjt_call24._isnullterminated = false;
#line 14
    sjf_string(&sjt_call24);
#line 66 "lib/ui/scene2dModel.sj"
    sjt_functionParam221 = &sjt_call24;
#line 66
    sjf_glgetuniformlocation(sjt_functionParam220, sjt_functionParam221, &sjt_functionParam219);
#line 20 "lib/ui/color.sj"
    sjt_parent108 = &(&_parent->_light)->diffusecolor;
#line 20
    sjf_color_asvec3(sjt_parent108, &sjt_call25);
#line 66 "lib/ui/scene2dModel.sj"
    sjt_functionParam222 = &sjt_call25;
#line 66
    sjf_gluniformvec3(sjt_functionParam219, sjt_functionParam222);
#line 67
    sjt_functionParam224 = &_parent->shader;
#line 67
    sjt_call26._refCount = 1;
#line 67
    sjt_call26.count = 9;
#line 67
    sjt_call26.data._refCount = 1;
#line 67
    sjt_call26.data.datasize = 9;
#line 67
    sjt_call26.data.data = (void*)sjg_string23;
#line 67
    sjt_call26.data.isglobal = true;
#line 67
    sjt_call26.data.count = 9;
#line 67
    sjf_array_char(&sjt_call26.data);
#line 14 "lib/common/string.sj"
    sjt_call26._isnullterminated = false;
#line 14
    sjf_string(&sjt_call26);
#line 67 "lib/ui/scene2dModel.sj"
    sjt_functionParam225 = &sjt_call26;
#line 67
    sjf_glgetuniformlocation(sjt_functionParam224, sjt_functionParam225, &sjt_functionParam223);
#line 20 "lib/ui/color.sj"
    sjt_parent109 = &(&_parent->_light)->speccolor;
#line 20
    sjf_color_asvec3(sjt_parent109, &sjt_call27);
#line 67 "lib/ui/scene2dModel.sj"
    sjt_functionParam226 = &sjt_call27;
#line 67
    sjf_gluniformvec3(sjt_functionParam223, sjt_functionParam226);
#line 94 "lib/ui/vertexBuffer.sj"
    sjt_parent110 = &_parent->vertexbuffer;
#line 68 "lib/ui/scene2dModel.sj"
    sjt_functionParam227 = sjv_gldrawmode_gl_triangles;
#line 68
    sjf_vertexbuffer_vertex_location_texture_normal_render(sjt_parent110, sjt_functionParam227);

    if (sjt_call18._refCount == 1) { sjf_mat4_destroy(&sjt_call18); }
;
    if (sjt_call19._refCount == 1) { sjf_mat4_destroy(&sjt_call19); }
;
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
;
    if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
;
    if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
;
    if (sjt_call23._refCount == 1) { sjf_string_destroy(&sjt_call23); }
;
    if (sjt_call24._refCount == 1) { sjf_string_destroy(&sjt_call24); }
;
    if (sjt_call25._refCount == 1) { sjf_vec3_destroy(&sjt_call25); }
;
    if (sjt_call26._refCount == 1) { sjf_string_destroy(&sjt_call26); }
;
    if (sjt_call27._refCount == 1) { sjf_vec3_destroy(&sjt_call27); }
;
    if (sjv_normalmat._refCount == 1) { sjf_mat4_destroy(&sjv_normalmat); }
;
    if (sjv_viewworld._refCount == 1) { sjf_mat4_destroy(&sjv_viewworld); }
;
}

void sjf_scene2dmodel_renderorqueue(sjs_scene2dmodel* _parent, sjs_list_heap_iface_model* alphamodels) {
    if (_parent->hasalpha) {
        sjs_scene2dmodel* sjt_cast10 = 0;
        sji_model sjt_functionParam185 = { 0 };
        sjs_list_heap_iface_model* sjt_parent97 = 0;

#line 36 "lib/ui/scene2dModel.sj"
        sjt_parent97 = alphamodels;
#line 38
        sjt_cast10 = _parent;
#line 1 "lib/ui/model.sj"
        sjf_scene2dmodel_as_sji_model(sjt_cast10, &sjt_functionParam185);
        if (sjt_functionParam185._parent != 0) {
            sjt_functionParam185._parent->_refCount++;
        }

#line 1
        sjf_list_heap_iface_model_add(sjt_parent97, sjt_functionParam185);

        if (sjt_functionParam185._parent != 0) {
            sjt_functionParam185._parent->_refCount--;
            if (sjt_functionParam185._parent->_refCount <= 0) {
                sjt_functionParam185._vtbl->destroy(sjt_functionParam185._parent);
                free(sjt_functionParam185._parent);
            }
        }
    } else {
        sjf_scene2dmodel_render(_parent);
    }
}

void sjf_scene2dmodel_update(sjs_scene2dmodel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    sjs_mat4 sjt_call14 = { -1 };
    sjs_mat4 sjt_call15 = { -1 };
    sjs_mat4 sjt_call16 = { -1 };
    sjs_vec4 sjt_call17 = { -1 };
    sjs_vec4 sjt_funcold18 = { -1 };
    sjs_mat4* sjt_functionParam174 = 0;
    sjs_mat4* sjt_functionParam175 = 0;
    sjs_mat4* sjt_functionParam176 = 0;
    sjs_vec4* sjt_functionParam177 = 0;
    sjs_mat4* sjt_parent89 = 0;
    sjs_mat4* sjt_parent90 = 0;
    sjs_mat4* sjt_parent91 = 0;
    sjs_mat4* sjt_parent92 = 0;

    if (_parent->_scenerect._refCount == 1) { sjf_rect_destroy(&_parent->_scenerect); }
;
#line 22 "lib/ui/scene2dModel.sj"
    sjf_rect_copy(&_parent->_scenerect, scenerect);
#line 22
    if (_parent->_projection._refCount == 1) { sjf_mat4_destroy(&_parent->_projection); }
;
#line 22
    sjf_mat4_copy(&_parent->_projection, projection);
#line 22
    if (_parent->_view._refCount == 1) { sjf_mat4_destroy(&_parent->_view); }
;
#line 22
    sjf_mat4_copy(&_parent->_view, view);
#line 22
    if (_parent->_world._refCount == 1) { sjf_mat4_destroy(&_parent->_world); }
;
#line 22
    sjf_mat4_copy(&_parent->_world, world);
#line 22
    if (_parent->_light._refCount == 1) { sjf_light_destroy(&_parent->_light); }
;
#line 22
    sjf_light_copy(&_parent->_light, light);
#line 22
    sjt_funcold18._refCount = 1;
#line 62 "lib/ui/mat4.sj"
    sjf_vec4_copy(&sjt_funcold18, &_parent->_projectedcenter);
#line 19
    sjt_parent92 = &_parent->_projection;
#line 28 "lib/ui/scene2dModel.sj"
    sjt_functionParam174 = &_parent->_view;
#line 28
    sjf_mat4_multiply(sjt_parent92, sjt_functionParam174, &sjt_call16);
#line 28
    sjt_parent91 = &sjt_call16;
#line 28
    sjt_functionParam175 = &_parent->_world;
#line 28
    sjf_mat4_multiply(sjt_parent91, sjt_functionParam175, &sjt_call15);
#line 28
    sjt_parent90 = &sjt_call15;
#line 28
    sjt_functionParam176 = &_parent->model;
#line 28
    sjf_mat4_multiply(sjt_parent90, sjt_functionParam176, &sjt_call14);
#line 28
    sjt_parent89 = &sjt_call14;
#line 28
    sjt_call17._refCount = 1;
#line 28
    sjt_call17.x = (&_parent->center)->x;
#line 28
    sjt_call17.y = (&_parent->center)->y;
#line 28
    sjt_call17.z = (&_parent->center)->z;
#line 28
    sjt_call17.w = 1.0f;
#line 28
    sjf_vec4(&sjt_call17);
#line 28
    sjt_functionParam177 = &sjt_call17;
#line 28
    sjf_mat4_multiplyvec4(sjt_parent89, sjt_functionParam177, &sjt_funcold18);
#line 28
    if (_parent->_projectedcenter._refCount == 1) { sjf_vec4_destroy(&_parent->_projectedcenter); }
;
#line 62 "lib/ui/mat4.sj"
    sjf_vec4_copy(&_parent->_projectedcenter, &sjt_funcold18);

    if (sjt_call14._refCount == 1) { sjf_mat4_destroy(&sjt_call14); }
;
    if (sjt_call15._refCount == 1) { sjf_mat4_destroy(&sjt_call15); }
;
    if (sjt_call16._refCount == 1) { sjf_mat4_destroy(&sjt_call16); }
;
    if (sjt_call17._refCount == 1) { sjf_vec4_destroy(&sjt_call17); }
;
    if (sjt_funcold18._refCount == 1) { sjf_vec4_destroy(&sjt_funcold18); }
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
#line 11 "lib/ui/scene3dElement.sj"
    sjf_array_heap_iface_model_copy(&_this->children, &_from->children);
#line 11
    _this->camera._refCount = 1;
#line 11
    sjf_vec3_copy(&_this->camera, &_from->camera);
#line 11
    _this->lookat._refCount = 1;
#line 11
    sjf_vec3_copy(&_this->lookat, &_from->lookat);
#line 11
    _this->up._refCount = 1;
#line 11
    sjf_vec3_copy(&_this->up, &_from->up);
#line 11
    _this->fieldofview = _from->fieldofview;
#line 11
    _this->znear = _from->znear;
#line 11
    _this->zfar = _from->zfar;
#line 11
    _this->light._refCount = 1;
#line 11
    sjf_light_copy(&_this->light, &_from->light);
#line 11
    _this->projection._refCount = 1;
#line 11
    sjf_mat4_copy(&_this->projection, &_from->projection);
#line 11
    _this->view._refCount = 1;
#line 11
    sjf_mat4_copy(&_this->view, &_from->view);
#line 11
    _this->world._refCount = 1;
#line 11
    sjf_mat4_copy(&_this->world, &_from->world);
#line 11
    _this->_rect._refCount = 1;
#line 11
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
    int32_t sjt_forEnd9;
    int32_t sjt_forStart9;

#line 67 "lib/ui/scene3dElement.sj"
    sjt_forStart9 = 0;
#line 67
    sjt_forEnd9 = (&_parent->children)->count;
#line 67
    i = sjt_forStart9;
    while (i < sjt_forEnd9) {
        int32_t sjt_functionParam105;
        sjs_mouseevent* sjt_interfaceParam16 = 0;
        sjs_array_heap_iface_model* sjt_parent70 = 0;
        sji_model sjt_parent71 = { 0 };
        sji_model sjv_child = { 0 };

#line 7 "lib/common/array.sj"
        sjt_parent70 = &_parent->children;
#line 67 "lib/ui/scene3dElement.sj"
        sjt_functionParam105 = i;
#line 67
        sjf_array_heap_iface_model_getat_heap(sjt_parent70, sjt_functionParam105, &sjv_child);
#line 8 "lib/ui/model.sj"
        sjt_parent71 = sjv_child;
#line 66 "lib/ui/scene3dElement.sj"
        sjt_interfaceParam16 = mouseevent;
#line 69
        sjt_parent71._vtbl->firemouseevent(sjt_parent71._parent, sjt_interfaceParam16);
#line 67
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

#line 71
    (*_return) = true;
}

void sjf_scene3delement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 108;
}

void sjf_scene3delement_getrect(sjs_scene3delement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 29 "lib/ui/scene3dElement.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_scene3delement_getrect_heap(sjs_scene3delement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 29 "lib/ui/scene3dElement.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_scene3delement_getsize(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 26 "lib/ui/scene3dElement.sj"
    _return->w = maxsize->w;
#line 26
    _return->h = maxsize->h;
#line 26
    sjf_size(_return);
}

void sjf_scene3delement_getsize_heap(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 26 "lib/ui/scene3dElement.sj"
    (*_return)->w = maxsize->w;
#line 26
    (*_return)->h = maxsize->h;
#line 26
    sjf_size_heap((*_return));
}

void sjf_scene3delement_heap(sjs_scene3delement* _this) {
}

void sjf_scene3delement_render(sjs_scene3delement* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd6;
    int32_t sjt_forEnd7;
    int32_t sjt_forEnd8;
    int32_t sjt_forStart6;
    int32_t sjt_forStart7;
    int32_t sjt_forStart8;
    sjs_rect* sjt_functionParam102 = 0;
    sjs_rect* sjt_functionParam103 = 0;
    int32_t sjt_functionParam104;
    int32_t sjt_functionParam54;
    sjs_rect* sjt_functionParam61 = 0;
    sjs_rect* sjt_functionParam62 = 0;
    cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam87;
    sjs_list_heap_iface_model* sjt_parent50 = 0;
    sjs_list_heap_iface_model* sjt_parent53 = 0;
    sjs_list_heap_iface_model sjv_a = { -1 };

#line 41 "lib/ui/scene3dElement.sj"
    sjt_forStart6 = 0;
#line 41
    sjt_forEnd6 = (&_parent->children)->count;
#line 41
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        int32_t sjt_functionParam53;
        sjs_rect* sjt_interfaceParam10 = 0;
        sjs_mat4* sjt_interfaceParam11 = 0;
        sjs_mat4* sjt_interfaceParam12 = 0;
        sjs_mat4* sjt_interfaceParam13 = 0;
        sjs_light* sjt_interfaceParam14 = 0;
        sjs_array_heap_iface_model* sjt_parent42 = 0;
        sji_model sjt_parent43 = { 0 };
        sji_model sjv_child = { 0 };

#line 7 "lib/common/array.sj"
        sjt_parent42 = &_parent->children;
#line 41 "lib/ui/scene3dElement.sj"
        sjt_functionParam53 = i;
#line 41
        sjf_array_heap_iface_model_getat_heap(sjt_parent42, sjt_functionParam53, &sjv_child);
#line 2 "lib/ui/model.sj"
        sjt_parent43 = sjv_child;
#line 43 "lib/ui/scene3dElement.sj"
        sjt_interfaceParam10 = &_parent->_rect;
#line 43
        sjt_interfaceParam11 = &_parent->projection;
#line 43
        sjt_interfaceParam12 = &_parent->view;
#line 43
        sjt_interfaceParam13 = &_parent->world;
#line 43
        sjt_interfaceParam14 = &_parent->light;
#line 43
        sjt_parent43._vtbl->update(sjt_parent43._parent, sjt_interfaceParam10, sjt_interfaceParam11, sjt_interfaceParam12, sjt_interfaceParam13, sjt_interfaceParam14);
#line 41
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

#line 46
    sjt_functionParam54 = sjv_glfeature_gl_depth_test;
#line 46
    sjf_glenable(sjt_functionParam54);
#line 47
    sjt_functionParam61 = &_parent->_rect;
#line 47
    sjt_functionParam62 = &scene->windowrect;
#line 47
    sjf_glpushviewport(sjt_functionParam61, sjt_functionParam62);
#line 47
    sjv_a._refCount = 1;
#line 47
    sjv_a.array._refCount = 1;
#line 2 "lib/common/list.sj"
    sjv_a.array.datasize = 0;
#line 3 "lib/common/array.sj"
    sjv_a.array.data = 0;
#line 4
    sjv_a.array.isglobal = false;
#line 5
    sjv_a.array.count = 0;
#line 5
    sjf_array_heap_iface_model(&sjv_a.array);
#line 5
    sjf_list_heap_iface_model(&sjv_a);
#line 51 "lib/ui/scene3dElement.sj"
    sjt_forStart7 = 0;
#line 51
    sjt_forEnd7 = (&_parent->children)->count;
#line 51
    i = sjt_forStart7;
    while (i < sjt_forEnd7) {
        int32_t sjt_functionParam63;
        sjs_list_heap_iface_model* sjt_interfaceParam15 = 0;
        sjs_array_heap_iface_model* sjt_parent47 = 0;
        sji_model sjt_parent48 = { 0 };
        sji_model sjv_child = { 0 };

#line 7 "lib/common/array.sj"
        sjt_parent47 = &_parent->children;
#line 51 "lib/ui/scene3dElement.sj"
        sjt_functionParam63 = i;
#line 51
        sjf_array_heap_iface_model_getat_heap(sjt_parent47, sjt_functionParam63, &sjv_child);
#line 6 "lib/ui/model.sj"
        sjt_parent48 = sjv_child;
#line 53 "lib/ui/scene3dElement.sj"
        sjt_interfaceParam15 = &sjv_a;
#line 53
        sjt_parent48._vtbl->renderorqueue(sjt_parent48._parent, sjt_interfaceParam15);
#line 51
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

#line 28 "lib/common/list.sj"
    sjt_parent50 = &sjv_a;
#line 56 "lib/ui/scene3dElement.sj"
    sjt_functionParam87._parent = (sjs_object*)1;
#line 56
    sjt_functionParam87._cb = (void(*)(sjs_object*,sji_model,sji_model, int32_t*))sjf_model_zsort_callback;
#line 56
    sjf_list_heap_iface_model_sortcb(sjt_parent50, sjt_functionParam87);
#line 57
    sjt_forStart8 = 0;
#line 4 "lib/common/list.sj"
    sjt_parent53 = &sjv_a;
#line 4
    sjf_list_heap_iface_model_getcount(sjt_parent53, &sjt_forEnd8);
#line 57 "lib/ui/scene3dElement.sj"
    i = sjt_forEnd8 - 1;
    while (i >= sjt_forStart8) {
        int32_t sjt_functionParam91;
        sjs_list_heap_iface_model* sjt_parent55 = 0;
        sji_model sjt_parent56 = { 0 };
        sji_model sjv_child = { 0 };

#line 8 "lib/common/list.sj"
        sjt_parent55 = &sjv_a;
#line 57 "lib/ui/scene3dElement.sj"
        sjt_functionParam91 = i;
#line 57
        sjf_list_heap_iface_model_getat_heap(sjt_parent55, sjt_functionParam91, &sjv_child);
#line 7 "lib/ui/model.sj"
        sjt_parent56 = sjv_child;
#line 59 "lib/ui/scene3dElement.sj"
        sjt_parent56._vtbl->render(sjt_parent56._parent);
#line 57
        i--;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

#line 62
    sjt_functionParam102 = &_parent->_rect;
#line 62
    sjt_functionParam103 = &scene->windowrect;
#line 62
    sjf_glpopviewport(sjt_functionParam102, sjt_functionParam103);
#line 63
    sjt_functionParam104 = sjv_glfeature_gl_depth_test;
#line 63
    sjf_gldisable(sjt_functionParam104);

    if (sjv_a._refCount == 1) { sjf_list_heap_iface_model_destroy(&sjv_a); }
;
}

void sjf_scene3delement_setrect(sjs_scene3delement* _parent, sjs_rect* rect_) {
    bool result2;
    bool sjt_capture6;
    sjs_mat4 sjt_funcold4 = { -1 };
    sjs_mat4 sjt_funcold5 = { -1 };
    sjs_rect* sjt_functionParam29 = 0;
    sjs_rect* sjt_parent25 = 0;

#line 15 "lib/ui/rect.sj"
    sjt_parent25 = &_parent->_rect;
#line 31 "lib/ui/scene3dElement.sj"
    sjt_functionParam29 = rect_;
#line 31
    sjf_rect_isequal(sjt_parent25, sjt_functionParam29, &sjt_capture6);
#line 32
    result2 = !sjt_capture6;
    if (result2) {
        int32_t sjt_cast4;
        int32_t sjt_cast5;
        float sjt_functionParam32;
        float sjt_functionParam33;
        float sjt_functionParam34;
        float sjt_functionParam35;
        sjs_vec3* sjt_functionParam50 = 0;
        sjs_vec3* sjt_functionParam51 = 0;
        sjs_vec3* sjt_functionParam52 = 0;

        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 31 "lib/ui/scene3dElement.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
#line 31
        sjt_funcold4._refCount = 1;
#line 158 "lib/ui/mat4.sj"
        sjf_mat4_copy(&sjt_funcold4, &_parent->projection);
#line 34 "lib/ui/scene3dElement.sj"
        sjt_functionParam32 = _parent->fieldofview;
#line 34
        sjt_cast4 = (&_parent->_rect)->h;
#line 34
        sjt_cast5 = (&_parent->_rect)->w;
#line 34
        sjt_functionParam33 = (float)sjt_cast4 / (float)sjt_cast5;
#line 34
        sjt_functionParam34 = _parent->znear;
#line 34
        sjt_functionParam35 = _parent->zfar;
#line 34
        sjf_mat4_perspective(sjt_functionParam32, sjt_functionParam33, sjt_functionParam34, sjt_functionParam35, &sjt_funcold4);
#line 34
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
#line 158 "lib/ui/mat4.sj"
        sjf_mat4_copy(&_parent->projection, &sjt_funcold4);
#line 158
        sjt_funcold5._refCount = 1;
#line 133
        sjf_mat4_copy(&sjt_funcold5, &_parent->view);
#line 35 "lib/ui/scene3dElement.sj"
        sjt_functionParam50 = &_parent->camera;
#line 35
        sjt_functionParam51 = &_parent->lookat;
#line 35
        sjt_functionParam52 = &_parent->up;
#line 35
        sjf_mat4_lookatlh(sjt_functionParam50, sjt_functionParam51, sjt_functionParam52, &sjt_funcold5);
#line 35
        if (_parent->view._refCount == 1) { sjf_mat4_destroy(&_parent->view); }
;
#line 133 "lib/ui/mat4.sj"
        sjf_mat4_copy(&_parent->view, &sjt_funcold5);
    }

    if (sjt_funcold4._refCount == 1) { sjf_mat4_destroy(&sjt_funcold4); }
;
    if (sjt_funcold5._refCount == 1) { sjf_mat4_destroy(&sjt_funcold5); }
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
    if (_parent->w == size->w) {
#line 28 "lib/ui/size.sj"
        (*_return) = (_parent->h == size->h);
    } else {
#line 28 "lib/ui/size.sj"
        (*_return) = false;
    }
}

void sjf_size_max(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    if (_parent->w > maxsize->w) {
#line 13 "lib/ui/size.sj"
        _return->w = _parent->w;
    } else {
#line 13 "lib/ui/size.sj"
        _return->w = maxsize->w;
    }

    if (_parent->h > maxsize->h) {
#line 13 "lib/ui/size.sj"
        _return->h = _parent->h;
    } else {
#line 13 "lib/ui/size.sj"
        _return->h = maxsize->h;
    }

    sjf_size(_return);
}

void sjf_size_max_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    if (_parent->w > maxsize->w) {
#line 13 "lib/ui/size.sj"
        (*_return)->w = _parent->w;
    } else {
#line 13 "lib/ui/size.sj"
        (*_return)->w = maxsize->w;
    }

    if (_parent->h > maxsize->h) {
#line 13 "lib/ui/size.sj"
        (*_return)->h = _parent->h;
    } else {
#line 13 "lib/ui/size.sj"
        (*_return)->h = maxsize->h;
    }

    sjf_size_heap((*_return));
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

void sjf_size_subtractmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    _return->_refCount = 1;
#line 24 "lib/ui/size.sj"
    _return->w = (_parent->w - margin->l) - margin->r;
#line 24
    _return->h = (_parent->h - margin->t) - margin->b;
#line 24
    sjf_size(_return);
}

void sjf_size_subtractmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 24 "lib/ui/size.sj"
    (*_return)->w = (_parent->w - margin->l) - margin->r;
#line 24
    (*_return)->h = (_parent->h - margin->t) - margin->b;
#line 24
    sjf_size_heap((*_return));
}

void sjf_spherevertexbuffer(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexbuffer_vertex_location_texture_normal* _return) {
    int32_t sjt_forEnd18;
    int32_t sjt_forEnd20;
    int32_t sjt_forStart18;
    int32_t sjt_forStart20;
    sjs_array_i32 sjv_indices = { -1 };
    sjs_array_vertex_location_texture_normal sjv_vertices = { -1 };
    int32_t slice;

    sjv_vertices._refCount = 1;
#line 108 "lib/ui/vertexBufferBuilders.sj"
    sjv_vertices.datasize = (slices + 1) * (wedges + 1);
#line 3 "lib/common/array.sj"
    sjv_vertices.data = 0;
#line 4
    sjv_vertices.isglobal = false;
#line 5
    sjv_vertices.count = 0;
#line 5
    sjf_array_vertex_location_texture_normal(&sjv_vertices);
#line 109 "lib/ui/vertexBufferBuilders.sj"
    sjt_forStart18 = 0;
#line 109
    sjt_forEnd18 = slices + 1;
#line 109
    slice = sjt_forStart18;
    while (slice < sjt_forEnd18) {
        float sjt_capture43;
        int32_t sjt_cast23;
        int32_t sjt_cast24;
        int32_t sjt_cast25;
        int32_t sjt_cast26;
        int32_t sjt_forEnd19;
        int32_t sjt_forStart19;
        float sjt_functionParam374;
        float sjt_functionParam375;
        float sjv_r0;
        float sjv_theta;
        float sjv_tv;
        float sjv_y0;
        int32_t wedge;

#line 109 "lib/ui/vertexBufferBuilders.sj"
        sjt_cast23 = slice;
#line 102
        sjt_cast24 = slices;
#line 110
        sjv_tv = (float)sjt_cast23 / (float)sjt_cast24;
#line 109
        sjt_cast25 = slice;
#line 102
        sjt_cast26 = slices;
#line 111
        sjv_theta = ((sjv_f32_pi * (float)sjt_cast25) / (float)sjt_cast26) + sjv_f32_pi;
#line 112
        sjt_functionParam374 = sjv_theta;
#line 112
        sjf_f32_cos(sjt_functionParam374, &sjt_capture43);
#line 112
        sjv_y0 = sjt_capture43 * radius->y;
#line 113
        sjt_functionParam375 = sjv_theta;
#line 113
        sjf_f32_sin(sjt_functionParam375, &sjv_r0);
#line 114
        sjt_forStart19 = 0;
#line 114
        sjt_forEnd19 = wedges + 1;
#line 114
        wedge = sjt_forStart19;
        while (wedge < sjt_forEnd19) {
            float sjt_capture44;
            float sjt_capture45;
            int32_t sjt_cast27;
            int32_t sjt_cast28;
            int32_t sjt_cast29;
            int32_t sjt_cast30;
            float sjt_functionParam376;
            float sjt_functionParam377;
            int32_t sjt_functionParam378;
            sjs_vertex_location_texture_normal* sjt_functionParam379 = 0;
            sjs_vec3* sjt_parent224 = 0;
            sjs_array_vertex_location_texture_normal* sjt_parent225 = 0;
            float sjv_angle;
            sjs_vec3 sjv_normal = { -1 };
            float sjv_tu;
            sjs_vertex_location_texture_normal sjv_v = { -1 };
            float sjv_x0;
            float sjv_z0;

#line 114 "lib/ui/vertexBufferBuilders.sj"
            sjt_cast27 = wedge;
#line 102
            sjt_cast28 = wedges;
#line 115
            sjv_tu = (float)sjt_cast27 / (float)sjt_cast28;
#line 114
            sjt_cast29 = wedge;
#line 102
            sjt_cast30 = wedges;
#line 116
            sjv_angle = (((2.0f * sjv_f32_pi) * (float)sjt_cast29) / (float)sjt_cast30) - (1.5f * sjv_f32_pi);
#line 117
            sjt_functionParam376 = sjv_angle;
#line 117
            sjf_f32_sin(sjt_functionParam376, &sjt_capture44);
#line 117
            sjv_x0 = (sjt_capture44 * sjv_r0) * radius->x;
#line 118
            sjt_functionParam377 = sjv_angle;
#line 118
            sjf_f32_cos(sjt_functionParam377, &sjt_capture45);
#line 118
            sjv_z0 = (sjt_capture45 * sjv_r0) * radius->y;
#line 118
            sjv_normal._refCount = 1;
#line 119
            sjv_normal.x = sjv_x0;
#line 119
            sjv_normal.y = sjv_y0;
#line 119
            sjv_normal.z = sjv_z0;
#line 119
            sjf_vec3(&sjv_normal);
#line 119
            sjv_v._refCount = 1;
#line 119
            sjv_v.location._refCount = 1;
#line 122
            sjv_v.location.x = sjv_x0 + origin->x;
#line 122
            sjv_v.location.y = sjv_y0 + origin->y;
#line 122
            sjv_v.location.z = sjv_z0 + origin->z;
#line 122
            sjf_vec3(&sjv_v.location);
#line 122
            sjv_v.texture._refCount = 1;
#line 123
            sjv_v.texture.x = sjv_tu;
#line 123
            sjv_v.texture.y = sjv_tv;
#line 123
            sjf_vec2(&sjv_v.texture);
#line 38 "lib/ui/vec3.sj"
            sjt_parent224 = &sjv_normal;
#line 38
            sjf_vec3_normalize(sjt_parent224, &sjv_v.normal);
#line 38
            sjf_vertex_location_texture_normal(&sjv_v);
#line 34 "lib/common/array.sj"
            sjt_parent225 = &sjv_vertices;
#line 126 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam378 = (slice * (wedges + 1)) + wedge;
#line 126
            sjt_functionParam379 = &sjv_v;
#line 126
            sjf_array_vertex_location_texture_normal_initat(sjt_parent225, sjt_functionParam378, sjt_functionParam379);
#line 114
            wedge++;

            if (sjv_normal._refCount == 1) { sjf_vec3_destroy(&sjv_normal); }
;
            if (sjv_v._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_v); }
;
        }

#line 109
        slice++;
    }

#line 109
    sjv_indices._refCount = 1;
#line 130
    sjv_indices.datasize = (slices * wedges) * 6;
#line 3 "lib/common/array.sj"
    sjv_indices.data = 0;
#line 4
    sjv_indices.isglobal = false;
#line 5
    sjv_indices.count = 0;
#line 5
    sjf_array_i32(&sjv_indices);
#line 131 "lib/ui/vertexBufferBuilders.sj"
    sjt_forStart20 = 0;
#line 102
    sjt_forEnd20 = slices;
#line 131
    slice = sjt_forStart20;
    while (slice < sjt_forEnd20) {
        int32_t sjt_forEnd21;
        int32_t sjt_forStart21;
        int32_t wedge;

#line 132 "lib/ui/vertexBufferBuilders.sj"
        sjt_forStart21 = 0;
#line 102
        sjt_forEnd21 = wedges;
#line 132
        wedge = sjt_forStart21;
        while (wedge < sjt_forEnd21) {
            int32_t sjt_functionParam380;
            int32_t sjt_functionParam381;
            int32_t sjt_functionParam382;
            int32_t sjt_functionParam383;
            int32_t sjt_functionParam384;
            int32_t sjt_functionParam385;
            int32_t sjt_functionParam386;
            int32_t sjt_functionParam387;
            int32_t sjt_functionParam388;
            int32_t sjt_functionParam389;
            int32_t sjt_functionParam390;
            int32_t sjt_functionParam391;
            sjs_array_i32* sjt_parent226 = 0;
            sjs_array_i32* sjt_parent227 = 0;
            sjs_array_i32* sjt_parent228 = 0;
            sjs_array_i32* sjt_parent229 = 0;
            sjs_array_i32* sjt_parent230 = 0;
            sjs_array_i32* sjt_parent231 = 0;
            int32_t sjv_index0;
            int32_t sjv_index1;
            int32_t sjv_index2;
            int32_t sjv_index3;
            int32_t sjv_wedge0;
            int32_t sjv_wedge1;

#line 132 "lib/ui/vertexBufferBuilders.sj"
            sjv_wedge0 = wedge;
#line 134
            sjv_wedge1 = wedge + 1;
#line 136
            sjv_index0 = (slice * (wedges + 1)) + sjv_wedge0;
#line 137
            sjv_index1 = (slice * (wedges + 1)) + sjv_wedge1;
#line 138
            sjv_index2 = ((slice + 1) * (wedges + 1)) + sjv_wedge1;
#line 139
            sjv_index3 = ((slice + 1) * (wedges + 1)) + sjv_wedge0;
#line 34 "lib/common/array.sj"
            sjt_parent226 = &sjv_indices;
#line 141 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam380 = (((slice * wedges) + wedge) * 6) + 0;
#line 141
            sjt_functionParam381 = sjv_index0;
#line 141
            sjf_array_i32_initat(sjt_parent226, sjt_functionParam380, sjt_functionParam381);
#line 34 "lib/common/array.sj"
            sjt_parent227 = &sjv_indices;
#line 142 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam382 = (((slice * wedges) + wedge) * 6) + 1;
#line 142
            sjt_functionParam383 = sjv_index1;
#line 142
            sjf_array_i32_initat(sjt_parent227, sjt_functionParam382, sjt_functionParam383);
#line 34 "lib/common/array.sj"
            sjt_parent228 = &sjv_indices;
#line 143 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam384 = (((slice * wedges) + wedge) * 6) + 2;
#line 143
            sjt_functionParam385 = sjv_index2;
#line 143
            sjf_array_i32_initat(sjt_parent228, sjt_functionParam384, sjt_functionParam385);
#line 34 "lib/common/array.sj"
            sjt_parent229 = &sjv_indices;
#line 144 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam386 = (((slice * wedges) + wedge) * 6) + 3;
#line 144
            sjt_functionParam387 = sjv_index2;
#line 144
            sjf_array_i32_initat(sjt_parent229, sjt_functionParam386, sjt_functionParam387);
#line 34 "lib/common/array.sj"
            sjt_parent230 = &sjv_indices;
#line 145 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam388 = (((slice * wedges) + wedge) * 6) + 4;
#line 145
            sjt_functionParam389 = sjv_index3;
#line 145
            sjf_array_i32_initat(sjt_parent230, sjt_functionParam388, sjt_functionParam389);
#line 34 "lib/common/array.sj"
            sjt_parent231 = &sjv_indices;
#line 146 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam390 = (((slice * wedges) + wedge) * 6) + 5;
#line 146
            sjt_functionParam391 = sjv_index0;
#line 146
            sjf_array_i32_initat(sjt_parent231, sjt_functionParam390, sjt_functionParam391);
#line 132
            wedge++;
        }

#line 131
        slice++;
    }

#line 131
    _return->_refCount = 1;
#line 131
    _return->format._refCount = 1;
#line 150
    sjf_string_copy(&_return->format, &sjv_vertex_location_texture_normal_format);
#line 150
    _return->indices._refCount = 1;
#line 150
    sjf_array_i32_copy(&_return->indices, &sjv_indices);
#line 150
    _return->vertices._refCount = 1;
#line 150
    sjf_array_vertex_location_texture_normal_copy(&_return->vertices, &sjv_vertices);
#line 150
    sjf_vertexbuffer_vertex_location_texture_normal(_return);

    if (sjv_indices._refCount == 1) { sjf_array_i32_destroy(&sjv_indices); }
;
    if (sjv_vertices._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&sjv_vertices); }
;
}

void sjf_spherevertexbuffer_heap(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexbuffer_vertex_location_texture_normal** _return) {
    int32_t sjt_forEnd22;
    int32_t sjt_forEnd24;
    int32_t sjt_forStart22;
    int32_t sjt_forStart24;
    sjs_array_i32 sjv_indices = { -1 };
    sjs_array_vertex_location_texture_normal sjv_vertices = { -1 };
    int32_t slice;

    sjv_vertices._refCount = 1;
#line 108 "lib/ui/vertexBufferBuilders.sj"
    sjv_vertices.datasize = (slices + 1) * (wedges + 1);
#line 3 "lib/common/array.sj"
    sjv_vertices.data = 0;
#line 4
    sjv_vertices.isglobal = false;
#line 5
    sjv_vertices.count = 0;
#line 5
    sjf_array_vertex_location_texture_normal(&sjv_vertices);
#line 109 "lib/ui/vertexBufferBuilders.sj"
    sjt_forStart22 = 0;
#line 109
    sjt_forEnd22 = slices + 1;
#line 109
    slice = sjt_forStart22;
    while (slice < sjt_forEnd22) {
        float sjt_capture46;
        int32_t sjt_cast31;
        int32_t sjt_cast32;
        int32_t sjt_cast33;
        int32_t sjt_cast34;
        int32_t sjt_forEnd23;
        int32_t sjt_forStart23;
        float sjt_functionParam392;
        float sjt_functionParam393;
        float sjv_r0;
        float sjv_theta;
        float sjv_tv;
        float sjv_y0;
        int32_t wedge;

#line 109 "lib/ui/vertexBufferBuilders.sj"
        sjt_cast31 = slice;
#line 102
        sjt_cast32 = slices;
#line 110
        sjv_tv = (float)sjt_cast31 / (float)sjt_cast32;
#line 109
        sjt_cast33 = slice;
#line 102
        sjt_cast34 = slices;
#line 111
        sjv_theta = ((sjv_f32_pi * (float)sjt_cast33) / (float)sjt_cast34) + sjv_f32_pi;
#line 112
        sjt_functionParam392 = sjv_theta;
#line 112
        sjf_f32_cos(sjt_functionParam392, &sjt_capture46);
#line 112
        sjv_y0 = sjt_capture46 * radius->y;
#line 113
        sjt_functionParam393 = sjv_theta;
#line 113
        sjf_f32_sin(sjt_functionParam393, &sjv_r0);
#line 114
        sjt_forStart23 = 0;
#line 114
        sjt_forEnd23 = wedges + 1;
#line 114
        wedge = sjt_forStart23;
        while (wedge < sjt_forEnd23) {
            float sjt_capture47;
            float sjt_capture48;
            int32_t sjt_cast35;
            int32_t sjt_cast36;
            int32_t sjt_cast37;
            int32_t sjt_cast38;
            float sjt_functionParam394;
            float sjt_functionParam395;
            int32_t sjt_functionParam396;
            sjs_vertex_location_texture_normal* sjt_functionParam397 = 0;
            sjs_vec3* sjt_parent232 = 0;
            sjs_array_vertex_location_texture_normal* sjt_parent233 = 0;
            float sjv_angle;
            sjs_vec3 sjv_normal = { -1 };
            float sjv_tu;
            sjs_vertex_location_texture_normal sjv_v = { -1 };
            float sjv_x0;
            float sjv_z0;

#line 114 "lib/ui/vertexBufferBuilders.sj"
            sjt_cast35 = wedge;
#line 102
            sjt_cast36 = wedges;
#line 115
            sjv_tu = (float)sjt_cast35 / (float)sjt_cast36;
#line 114
            sjt_cast37 = wedge;
#line 102
            sjt_cast38 = wedges;
#line 116
            sjv_angle = (((2.0f * sjv_f32_pi) * (float)sjt_cast37) / (float)sjt_cast38) - (1.5f * sjv_f32_pi);
#line 117
            sjt_functionParam394 = sjv_angle;
#line 117
            sjf_f32_sin(sjt_functionParam394, &sjt_capture47);
#line 117
            sjv_x0 = (sjt_capture47 * sjv_r0) * radius->x;
#line 118
            sjt_functionParam395 = sjv_angle;
#line 118
            sjf_f32_cos(sjt_functionParam395, &sjt_capture48);
#line 118
            sjv_z0 = (sjt_capture48 * sjv_r0) * radius->y;
#line 118
            sjv_normal._refCount = 1;
#line 119
            sjv_normal.x = sjv_x0;
#line 119
            sjv_normal.y = sjv_y0;
#line 119
            sjv_normal.z = sjv_z0;
#line 119
            sjf_vec3(&sjv_normal);
#line 119
            sjv_v._refCount = 1;
#line 119
            sjv_v.location._refCount = 1;
#line 122
            sjv_v.location.x = sjv_x0 + origin->x;
#line 122
            sjv_v.location.y = sjv_y0 + origin->y;
#line 122
            sjv_v.location.z = sjv_z0 + origin->z;
#line 122
            sjf_vec3(&sjv_v.location);
#line 122
            sjv_v.texture._refCount = 1;
#line 123
            sjv_v.texture.x = sjv_tu;
#line 123
            sjv_v.texture.y = sjv_tv;
#line 123
            sjf_vec2(&sjv_v.texture);
#line 38 "lib/ui/vec3.sj"
            sjt_parent232 = &sjv_normal;
#line 38
            sjf_vec3_normalize(sjt_parent232, &sjv_v.normal);
#line 38
            sjf_vertex_location_texture_normal(&sjv_v);
#line 34 "lib/common/array.sj"
            sjt_parent233 = &sjv_vertices;
#line 126 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam396 = (slice * (wedges + 1)) + wedge;
#line 126
            sjt_functionParam397 = &sjv_v;
#line 126
            sjf_array_vertex_location_texture_normal_initat(sjt_parent233, sjt_functionParam396, sjt_functionParam397);
#line 114
            wedge++;

            if (sjv_normal._refCount == 1) { sjf_vec3_destroy(&sjv_normal); }
;
            if (sjv_v._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_v); }
;
        }

#line 109
        slice++;
    }

#line 109
    sjv_indices._refCount = 1;
#line 130
    sjv_indices.datasize = (slices * wedges) * 6;
#line 3 "lib/common/array.sj"
    sjv_indices.data = 0;
#line 4
    sjv_indices.isglobal = false;
#line 5
    sjv_indices.count = 0;
#line 5
    sjf_array_i32(&sjv_indices);
#line 131 "lib/ui/vertexBufferBuilders.sj"
    sjt_forStart24 = 0;
#line 102
    sjt_forEnd24 = slices;
#line 131
    slice = sjt_forStart24;
    while (slice < sjt_forEnd24) {
        int32_t sjt_forEnd25;
        int32_t sjt_forStart25;
        int32_t wedge;

#line 132 "lib/ui/vertexBufferBuilders.sj"
        sjt_forStart25 = 0;
#line 102
        sjt_forEnd25 = wedges;
#line 132
        wedge = sjt_forStart25;
        while (wedge < sjt_forEnd25) {
            int32_t sjt_functionParam398;
            int32_t sjt_functionParam399;
            int32_t sjt_functionParam400;
            int32_t sjt_functionParam401;
            int32_t sjt_functionParam402;
            int32_t sjt_functionParam403;
            int32_t sjt_functionParam404;
            int32_t sjt_functionParam405;
            int32_t sjt_functionParam406;
            int32_t sjt_functionParam407;
            int32_t sjt_functionParam408;
            int32_t sjt_functionParam409;
            sjs_array_i32* sjt_parent234 = 0;
            sjs_array_i32* sjt_parent235 = 0;
            sjs_array_i32* sjt_parent236 = 0;
            sjs_array_i32* sjt_parent237 = 0;
            sjs_array_i32* sjt_parent238 = 0;
            sjs_array_i32* sjt_parent239 = 0;
            int32_t sjv_index0;
            int32_t sjv_index1;
            int32_t sjv_index2;
            int32_t sjv_index3;
            int32_t sjv_wedge0;
            int32_t sjv_wedge1;

#line 132 "lib/ui/vertexBufferBuilders.sj"
            sjv_wedge0 = wedge;
#line 134
            sjv_wedge1 = wedge + 1;
#line 136
            sjv_index0 = (slice * (wedges + 1)) + sjv_wedge0;
#line 137
            sjv_index1 = (slice * (wedges + 1)) + sjv_wedge1;
#line 138
            sjv_index2 = ((slice + 1) * (wedges + 1)) + sjv_wedge1;
#line 139
            sjv_index3 = ((slice + 1) * (wedges + 1)) + sjv_wedge0;
#line 34 "lib/common/array.sj"
            sjt_parent234 = &sjv_indices;
#line 141 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam398 = (((slice * wedges) + wedge) * 6) + 0;
#line 141
            sjt_functionParam399 = sjv_index0;
#line 141
            sjf_array_i32_initat(sjt_parent234, sjt_functionParam398, sjt_functionParam399);
#line 34 "lib/common/array.sj"
            sjt_parent235 = &sjv_indices;
#line 142 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam400 = (((slice * wedges) + wedge) * 6) + 1;
#line 142
            sjt_functionParam401 = sjv_index1;
#line 142
            sjf_array_i32_initat(sjt_parent235, sjt_functionParam400, sjt_functionParam401);
#line 34 "lib/common/array.sj"
            sjt_parent236 = &sjv_indices;
#line 143 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam402 = (((slice * wedges) + wedge) * 6) + 2;
#line 143
            sjt_functionParam403 = sjv_index2;
#line 143
            sjf_array_i32_initat(sjt_parent236, sjt_functionParam402, sjt_functionParam403);
#line 34 "lib/common/array.sj"
            sjt_parent237 = &sjv_indices;
#line 144 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam404 = (((slice * wedges) + wedge) * 6) + 3;
#line 144
            sjt_functionParam405 = sjv_index2;
#line 144
            sjf_array_i32_initat(sjt_parent237, sjt_functionParam404, sjt_functionParam405);
#line 34 "lib/common/array.sj"
            sjt_parent238 = &sjv_indices;
#line 145 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam406 = (((slice * wedges) + wedge) * 6) + 4;
#line 145
            sjt_functionParam407 = sjv_index3;
#line 145
            sjf_array_i32_initat(sjt_parent238, sjt_functionParam406, sjt_functionParam407);
#line 34 "lib/common/array.sj"
            sjt_parent239 = &sjv_indices;
#line 146 "lib/ui/vertexBufferBuilders.sj"
            sjt_functionParam408 = (((slice * wedges) + wedge) * 6) + 5;
#line 146
            sjt_functionParam409 = sjv_index0;
#line 146
            sjf_array_i32_initat(sjt_parent239, sjt_functionParam408, sjt_functionParam409);
#line 132
            wedge++;
        }

#line 131
        slice++;
    }

#line 131
    (*_return) = (sjs_vertexbuffer_vertex_location_texture_normal*)malloc(sizeof(sjs_vertexbuffer_vertex_location_texture_normal));
#line 131
    (*_return)->_refCount = 1;
#line 131
    (*_return)->format._refCount = 1;
#line 150
    sjf_string_copy(&(*_return)->format, &sjv_vertex_location_texture_normal_format);
#line 150
    (*_return)->indices._refCount = 1;
#line 150
    sjf_array_i32_copy(&(*_return)->indices, &sjv_indices);
#line 150
    (*_return)->vertices._refCount = 1;
#line 150
    sjf_array_vertex_location_texture_normal_copy(&(*_return)->vertices, &sjv_vertices);
#line 150
    sjf_vertexbuffer_vertex_location_texture_normal_heap((*_return));

    if (sjv_indices._refCount == 1) { sjf_array_i32_destroy(&sjv_indices); }
;
    if (sjv_vertices._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&sjv_vertices); }
;
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
        int32_t sjt_forEnd14;
        int32_t sjt_forStart14;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam295;
            sjs_array_char* sjt_parent168 = 0;

#line 134 "lib/common/array.sj"
            sjt_parent168 = &_parent->data;
#line 21 "lib/common/string.sj"
            sjt_functionParam295 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent168, sjt_functionParam295, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
#line 20 "lib/common/string.sj"
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

#line 25 "lib/common/string.sj"
        sjv_newcount = _parent->count;
#line 27
        sjt_forStart14 = 0;
#line 27
        sjt_forEnd14 = item->count;
#line 27
        i = sjt_forStart14;
        while (i < sjt_forEnd14) {
            int32_t sjt_functionParam296;
            char sjt_functionParam297;
            int32_t sjt_functionParam299;
            sjs_array_char* sjt_parent169 = 0;
            sjs_string* sjt_parent171 = 0;

#line 34 "lib/common/array.sj"
            sjt_parent169 = &sjv_newdata;
#line 28 "lib/common/string.sj"
            sjt_functionParam296 = sjv_newcount;
#line 16
            sjt_parent171 = item;
#line 27
            sjt_functionParam299 = i;
#line 27
            sjf_string_getat(sjt_parent171, sjt_functionParam299, &sjt_functionParam297);
#line 27
            sjf_array_char_initat(sjt_parent169, sjt_functionParam296, sjt_functionParam297);
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
        int32_t sjt_forEnd15;
        int32_t sjt_forStart15;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam300;
            sjs_array_char* sjt_parent172 = 0;

#line 134 "lib/common/array.sj"
            sjt_parent172 = &_parent->data;
#line 21 "lib/common/string.sj"
            sjt_functionParam300 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent172, sjt_functionParam300, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
#line 20 "lib/common/string.sj"
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

#line 25 "lib/common/string.sj"
        sjv_newcount = _parent->count;
#line 27
        sjt_forStart15 = 0;
#line 27
        sjt_forEnd15 = item->count;
#line 27
        i = sjt_forStart15;
        while (i < sjt_forEnd15) {
            int32_t sjt_functionParam301;
            char sjt_functionParam302;
            int32_t sjt_functionParam303;
            sjs_array_char* sjt_parent173 = 0;
            sjs_string* sjt_parent174 = 0;

#line 34 "lib/common/array.sj"
            sjt_parent173 = &sjv_newdata;
#line 28 "lib/common/string.sj"
            sjt_functionParam301 = sjv_newcount;
#line 16
            sjt_parent174 = item;
#line 27
            sjt_functionParam303 = i;
#line 27
            sjf_string_getat(sjt_parent174, sjt_functionParam303, &sjt_functionParam302);
#line 27
            sjf_array_char_initat(sjt_parent173, sjt_functionParam301, sjt_functionParam302);
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
    int32_t sjt_functionParam298;
    sjs_array_char* sjt_parent170 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent170 = &_parent->data;
#line 36 "lib/common/string.sj"
    sjt_functionParam298 = index;
#line 36
    sjf_array_char_getat(sjt_parent170, sjt_functionParam298, _return);
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
    bool result5;
    bool result6;
    sjs_array_char sjt_funcold7 = { -1 };

#line 73 "lib/common/string.sj"
    result5 = !(&_parent->data)->isglobal;
#line 73
    result6 = !_parent->_isnullterminated;
    if (result5 || result6) {
        int32_t sjt_functionParam97;
        char sjt_functionParam98;
        sjs_array_char* sjt_parent63 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam96;
            sjs_array_char* sjt_parent62 = 0;

            sjt_funcold7._refCount = 1;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&sjt_funcold7, &_parent->data);
#line 134
            sjt_parent62 = &_parent->data;
#line 75 "lib/common/string.sj"
            sjt_functionParam96 = _parent->count + 1;
#line 75
            sjf_array_char_grow(sjt_parent62, sjt_functionParam96, &sjt_funcold7);
#line 75
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold7);
        }

#line 34 "lib/common/array.sj"
        sjt_parent63 = &_parent->data;
#line 77 "lib/common/string.sj"
        sjt_functionParam97 = _parent->count;
#line 77
        sjt_functionParam98 = '\0';
#line 77
        sjf_array_char_initat(sjt_parent63, sjt_functionParam97, sjt_functionParam98);
#line 78
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold7._refCount == 1) { sjf_array_char_destroy(&sjt_funcold7); }
;
}

void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return) {
    int32_t i;
    int32_t sjt_forEnd16;
    int32_t sjt_forStart16;
    sjs_array_char sjv_a = { -1 };

    sjv_a._refCount = 1;
#line 65 "lib/common/string.sj"
    sjv_a.datasize = (((_parent->count - 1) / 256) + 1) * 256;
#line 3 "lib/common/array.sj"
    sjv_a.data = 0;
#line 4
    sjv_a.isglobal = false;
#line 5
    sjv_a.count = 0;
#line 5
    sjf_array_char(&sjv_a);
#line 66 "lib/common/string.sj"
    sjt_forStart16 = 0;
#line 66
    sjt_forEnd16 = _parent->count;
#line 66
    i = sjt_forStart16;
    while (i < sjt_forEnd16) {
        int32_t sjt_functionParam304;
        char sjt_functionParam305;
        char sjt_functionParam306;
        int32_t sjt_functionParam307;
        sjs_array_char* sjt_parent179 = 0;
        sjs_array_char* sjt_parent180 = 0;

#line 34 "lib/common/array.sj"
        sjt_parent179 = &sjv_a;
#line 66 "lib/common/string.sj"
        sjt_functionParam304 = i;
#line 7 "lib/common/array.sj"
        sjt_parent180 = &_parent->data;
#line 66 "lib/common/string.sj"
        sjt_functionParam307 = i;
#line 66
        sjf_array_char_getat(sjt_parent180, sjt_functionParam307, &sjt_functionParam306);
#line 66
        sjf_char_touppercase(sjt_functionParam306, &sjt_functionParam305);
#line 66
        sjf_array_char_initat(sjt_parent179, sjt_functionParam304, sjt_functionParam305);
#line 66
        i++;
    }

#line 66
    _return->_refCount = 1;
#line 69
    _return->count = _parent->count;
#line 69
    _return->data._refCount = 1;
#line 69
    sjf_array_char_copy(&_return->data, &sjv_a);
#line 14
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);

    if (sjv_a._refCount == 1) { sjf_array_char_destroy(&sjv_a); }
;
}

void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return) {
    int32_t i;
    int32_t sjt_forEnd17;
    int32_t sjt_forStart17;
    sjs_array_char sjv_a = { -1 };

    sjv_a._refCount = 1;
#line 65 "lib/common/string.sj"
    sjv_a.datasize = (((_parent->count - 1) / 256) + 1) * 256;
#line 3 "lib/common/array.sj"
    sjv_a.data = 0;
#line 4
    sjv_a.isglobal = false;
#line 5
    sjv_a.count = 0;
#line 5
    sjf_array_char(&sjv_a);
#line 66 "lib/common/string.sj"
    sjt_forStart17 = 0;
#line 66
    sjt_forEnd17 = _parent->count;
#line 66
    i = sjt_forStart17;
    while (i < sjt_forEnd17) {
        int32_t sjt_functionParam308;
        char sjt_functionParam309;
        char sjt_functionParam310;
        int32_t sjt_functionParam311;
        sjs_array_char* sjt_parent181 = 0;
        sjs_array_char* sjt_parent182 = 0;

#line 34 "lib/common/array.sj"
        sjt_parent181 = &sjv_a;
#line 66 "lib/common/string.sj"
        sjt_functionParam308 = i;
#line 7 "lib/common/array.sj"
        sjt_parent182 = &_parent->data;
#line 66 "lib/common/string.sj"
        sjt_functionParam311 = i;
#line 66
        sjf_array_char_getat(sjt_parent182, sjt_functionParam311, &sjt_functionParam310);
#line 66
        sjf_char_touppercase(sjt_functionParam310, &sjt_functionParam309);
#line 66
        sjf_array_char_initat(sjt_parent181, sjt_functionParam308, sjt_functionParam309);
#line 66
        i++;
    }

#line 66
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 66
    (*_return)->_refCount = 1;
#line 69
    (*_return)->count = _parent->count;
#line 69
    (*_return)->data._refCount = 1;
#line 69
    sjf_array_char_copy(&(*_return)->data, &sjv_a);
#line 14
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));

    if (sjv_a._refCount == 1) { sjf_array_char_destroy(&sjv_a); }
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

void sjf_type_asstring(int32_t t, sjs_string* _return) {
    switch (t) {
        case 8:
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 4;
        _return->data.data = (void*)sjg_string47;
        _return->data.isglobal = true;
        _return->data.count = 4;
        sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 13:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string48;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 129:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 31;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 31;
#line 14
        _return->data.data = (void*)sjg_string49;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 31;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 135:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 33;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 33;
#line 14
        _return->data.data = (void*)sjg_string50;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 33;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 90:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string51;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 91:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 20;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 20;
#line 14
        _return->data.data = (void*)sjg_string52;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 20;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 205:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string53;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 9:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string54;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 14:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 10;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 10;
#line 14
        _return->data.data = (void*)sjg_string55;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 10;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 6:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string56;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 7:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string57;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 15:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 21;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 21;
#line 14
        _return->data.data = (void*)sjg_string58;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 21;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 26:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 15;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 15;
#line 14
        _return->data.data = (void*)sjg_string59;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 15;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 27:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 10;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 10;
#line 14
        _return->data.data = (void*)sjg_string60;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 10;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 16:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string61;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 22:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 23;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 23;
#line 14
        _return->data.data = (void*)sjg_string62;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 23;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 25:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 19;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 19;
#line 14
        _return->data.data = (void*)sjg_string63;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 19;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 23:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 20;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 20;
#line 14
        _return->data.data = (void*)sjg_string64;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 20;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 24:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 20;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 20;
#line 14
        _return->data.data = (void*)sjg_string65;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 20;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 17:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string66;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 18:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 18;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 18;
#line 14
        _return->data.data = (void*)sjg_string67;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 18;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 20:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 15;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 15;
#line 14
        _return->data.data = (void*)sjg_string68;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 15;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 21:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string69;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 19:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string70;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 28:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string71;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 1:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string72;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 2:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string73;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 29:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string74;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 30:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 21;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 21;
#line 14
        _return->data.data = (void*)sjg_string75;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 21;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 12:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string76;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 31:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string77;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 5:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string78;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 69:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 10;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 10;
#line 14
        _return->data.data = (void*)sjg_string79;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 10;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 92:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string80;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 64:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string81;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 54:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string82;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 34:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 0;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 0;
#line 14
        _return->data.data = (void*)sjg_string30;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 0;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 68:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string83;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 270:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string84;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 60:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 10;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 10;
#line 14
        _return->data.data = (void*)sjg_string85;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 10;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 209:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 144:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string87;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 145:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string88;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 61:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string89;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 71:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 16;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 16;
#line 14
        _return->data.data = (void*)sjg_string90;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 16;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 273:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 88:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string91;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 94:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 258:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string88;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 109:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string92;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 131:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 18;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 18;
#line 14
        _return->data.data = (void*)sjg_string93;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 18;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 122:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 194:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string87;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 195:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string88;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 132:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string94;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 130:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string95;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 198:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string96;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 201:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 244:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string88;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 82:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 10;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 10;
#line 14
        _return->data.data = (void*)sjg_string97;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 10;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 140:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 125:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string87;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 127:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string88;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 84:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string98;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 179:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 173:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string87;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 174:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string88;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 199:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 36;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 36;
#line 14
        _return->data.data = (void*)sjg_string99;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 36;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 200:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 243:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string88;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 220:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string100;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 262:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 11;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 11;
#line 14
        _return->data.data = (void*)sjg_string101;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 11;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 265:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string102;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 210:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 16;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 16;
#line 14
        _return->data.data = (void*)sjg_string103;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 16;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 44:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string104;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 191:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string105;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 261:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string106;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 266:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string107;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 260:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string108;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 259:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string109;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 264:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string102;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 263:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string110;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 206:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string111;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 224:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string112;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 134:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 11;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 11;
#line 14
        _return->data.data = (void*)sjg_string113;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 11;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 241:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string114;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 77:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string115;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 242:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string116;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 118:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string117;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 114:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string118;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 87:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 10;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 10;
#line 14
        _return->data.data = (void*)sjg_string119;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 10;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 103:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string107;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 97:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string108;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 86:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string109;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 101:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string102;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 102:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 11;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 11;
#line 14
        _return->data.data = (void*)sjg_string120;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 11;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 98:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string110;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 100:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string121;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 74:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string122;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 73:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string123;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 76:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string124;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 78:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string89;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 161:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 11;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 11;
#line 14
        _return->data.data = (void*)sjg_string125;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 11;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 232:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 18;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 18;
#line 14
        _return->data.data = (void*)sjg_string126;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 18;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 187:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string127;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 45:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 11;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 11;
#line 14
        _return->data.data = (void*)sjg_string128;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 11;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 235:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 24;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 24;
#line 14
        _return->data.data = (void*)sjg_string129;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 24;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 43:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string130;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 147:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string131;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 46:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string132;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 234:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 25;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 25;
#line 14
        _return->data.data = (void*)sjg_string133;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 25;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 231:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 22;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 22;
#line 14
        _return->data.data = (void*)sjg_string134;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 22;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 226:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 16;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 16;
#line 14
        _return->data.data = (void*)sjg_string135;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 16;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 228:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string136;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 227:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string137;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 189:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 20;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 20;
#line 14
        _return->data.data = (void*)sjg_string138;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 20;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 35:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string139;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 177:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 16;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 16;
#line 14
        _return->data.data = (void*)sjg_string140;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 16;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 138:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string141;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 171:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string142;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 123:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string143;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 233:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 21;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 21;
#line 14
        _return->data.data = (void*)sjg_string144;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 21;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 230:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string145;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 229:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 15;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 15;
#line 14
        _return->data.data = (void*)sjg_string146;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 15;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 255:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string147;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 188:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string148;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 190:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string149;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 186:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string150;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 142:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string151;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 75:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 21;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 21;
#line 14
        _return->data.data = (void*)sjg_string152;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 21;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 79:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string153;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 80:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 19;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 19;
#line 14
        _return->data.data = (void*)sjg_string154;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 19;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 65:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 24;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 24;
#line 14
        _return->data.data = (void*)sjg_string155;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 24;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 66:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string153;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 67:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 19;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 19;
#line 14
        _return->data.data = (void*)sjg_string154;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 19;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 57:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 22;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 22;
#line 14
        _return->data.data = (void*)sjg_string156;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 22;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 62:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string153;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 63:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 19;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 19;
#line 14
        _return->data.data = (void*)sjg_string154;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 19;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 225:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string94;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 36:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string157;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 39:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string153;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 40:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 19;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 19;
#line 14
        _return->data.data = (void*)sjg_string154;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 19;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 214:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 219:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string158;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 126:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string159;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 248:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string160;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 247:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string161;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 256:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string107;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 246:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string108;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 245:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string109;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 252:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string102;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 251:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string110;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 250:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string162;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 254:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string102;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 202:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string163;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 215:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string164;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 216:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string165;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 221:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string166;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 222:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string165;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 52:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string167;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 70:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 15;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 15;
#line 14
        _return->data.data = (void*)sjg_string168;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 15;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 272:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 271:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string169;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 274:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string170;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 55:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 11;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 11;
#line 14
        _return->data.data = (void*)sjg_string171;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 11;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 193:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string172;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 137:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 136:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string169;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 128:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string95;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 81:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string173;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 124:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string172;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 139:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 141:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string169;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 146:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string170;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 83:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string174;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 172:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string172;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 178:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 180:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string169;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 181:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string170;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 41:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string175;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 204:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string176;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 203:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string24;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 207:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string177;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 269:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string178;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 89:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string179;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 49:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string180;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 183:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 11;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 11;
#line 14
        _return->data.data = (void*)sjg_string181;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 11;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 110:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string182;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 182:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string183;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 115:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string184;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 164:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string185;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 184:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 11;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 11;
#line 14
        _return->data.data = (void*)sjg_string186;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 11;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 165:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string187;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 238:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 17;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 17;
#line 14
        _return->data.data = (void*)sjg_string188;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 17;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 113:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 16;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 16;
#line 14
        _return->data.data = (void*)sjg_string189;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 16;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 239:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 10;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 10;
#line 14
        _return->data.data = (void*)sjg_string190;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 10;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 185:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string191;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 133:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 11;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 11;
#line 14
        _return->data.data = (void*)sjg_string192;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 11;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 56:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 10;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 10;
#line 14
        _return->data.data = (void*)sjg_string193;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 10;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 217:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string194;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 104:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string195;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 105:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string196;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 218:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string194;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 50:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string197;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 267:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string198;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 112:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string89;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 99:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string199;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 163:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string200;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 268:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string201;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 47:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string202;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 176:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string203;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 236:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string204;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 175:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string205;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 150:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string206;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 196:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string107;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 167:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string207;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 168:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string208;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 166:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string209;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 170:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string102;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 169:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string210;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 149:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string211;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 108:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string212;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 148:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string107;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 107:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string108;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 106:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string109;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 121:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string102;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 111:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string110;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 72:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string213;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 48:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string214;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 96:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string215;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 237:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string89;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 95:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string216;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 253:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string217;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 93:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string199;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 240:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 18;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 18;
#line 14
        _return->data.data = (void*)sjg_string218;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 18;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 51:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string219;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 211:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string172;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 212:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string86;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 58:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string124;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 59:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string89;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 143:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string220;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 208:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 11;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 11;
#line 14
        _return->data.data = (void*)sjg_string221;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 11;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 85:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string222;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 162:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string42;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 257:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 15;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 15;
#line 14
        _return->data.data = (void*)sjg_string223;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 15;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 249:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string109;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 213:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 13;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 13;
#line 14
        _return->data.data = (void*)sjg_string224;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 13;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 37:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string225;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 38:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string226;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 157:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string227;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 223:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string194;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 155:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 15;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 15;
#line 14
        _return->data.data = (void*)sjg_string228;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 15;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 159:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string229;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 53:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string230;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 119:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 5;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 5;
#line 14
        _return->data.data = (void*)sjg_string231;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 5;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 120:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string232;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 154:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 15;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 15;
#line 14
        _return->data.data = (void*)sjg_string233;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 15;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 117:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 9;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 9;
#line 14
        _return->data.data = (void*)sjg_string234;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 9;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 158:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string235;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 116:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 8;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 8;
#line 14
        _return->data.data = (void*)sjg_string236;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 8;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 160:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string237;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 151:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 30;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 30;
#line 14
        _return->data.data = (void*)sjg_string238;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 30;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 153:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 41;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 41;
#line 14
        _return->data.data = (void*)sjg_string239;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 41;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 156:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 38;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 38;
#line 14
        _return->data.data = (void*)sjg_string240;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 38;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 152:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 43;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 43;
#line 14
        _return->data.data = (void*)sjg_string241;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 43;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 192:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 6;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 6;
#line 14
        _return->data.data = (void*)sjg_string102;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 6;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 197:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 24;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 24;
#line 14
        _return->data.data = (void*)sjg_string242;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 24;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 42:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string243;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 275:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string109;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 276:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 7;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 7;
#line 14
        _return->data.data = (void*)sjg_string244;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 7;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 32:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 14;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 14;
#line 14
        _return->data.data = (void*)sjg_string245;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 14;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 33:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 12;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 12;
#line 14
        _return->data.data = (void*)sjg_string246;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 12;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 11:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string247;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 3:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string248;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 4:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 3;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 3;
#line 14
        _return->data.data = (void*)sjg_string249;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 3;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        case 10:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 4;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 4;
#line 14
        _return->data.data = (void*)sjg_string250;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 4;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
        default:
#line 14
        _return->_refCount = 1;
#line 14
        _return->count = 0;
#line 14
        _return->data._refCount = 1;
#line 14
        _return->data.datasize = 0;
#line 14
        _return->data.data = (void*)sjg_string30;
#line 14
        _return->data.isglobal = true;
#line 14
        _return->data.count = 0;
#line 14
        sjf_array_char(&_return->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
#line 14
        break;
#line 14
    }
}

void sjf_type_asstring_heap(int32_t t, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 2 "lib/common/type.sj"
    (*_return)->count = 0;
#line 2
    (*_return)->data._refCount = 1;
#line 2
    (*_return)->data.datasize = 0;
#line 2
    (*_return)->data.data = (void*)sjg_string30;
#line 2
    (*_return)->data.isglobal = true;
#line 2
    (*_return)->data.count = 0;
#line 2
    sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));
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

void sjf_vec2(sjs_vec2* _this) {
}

void sjf_vec2_asstring(sjs_vec2* _parent, sjs_string* _return) {
    sjs_string sjt_call91 = { -1 };
    sjs_string sjt_call92 = { -1 };
    sjs_string sjt_call93 = { -1 };
    sjs_string sjt_call94 = { -1 };
    float sjt_functionParam359;
    sjs_string* sjt_functionParam360 = 0;
    sjs_string* sjt_functionParam361 = 0;
    float sjt_functionParam362;
    sjs_string* sjt_parent209 = 0;
    sjs_string* sjt_parent210 = 0;

#line 6 "lib/ui/vec2.sj"
    sjt_functionParam359 = _parent->x;
#line 6
    sjf_f32_asstring(sjt_functionParam359, &sjt_call92);
#line 6
    sjt_parent210 = &sjt_call92;
#line 6
    sjt_call93._refCount = 1;
#line 6
    sjt_call93.count = 2;
#line 6
    sjt_call93.data._refCount = 1;
#line 6
    sjt_call93.data.datasize = 2;
#line 6
    sjt_call93.data.data = (void*)sjg_string34;
#line 6
    sjt_call93.data.isglobal = true;
#line 6
    sjt_call93.data.count = 2;
#line 6
    sjf_array_char(&sjt_call93.data);
#line 14 "lib/common/string.sj"
    sjt_call93._isnullterminated = false;
#line 14
    sjf_string(&sjt_call93);
#line 6 "lib/ui/vec2.sj"
    sjt_functionParam360 = &sjt_call93;
#line 6
    sjf_string_add(sjt_parent210, sjt_functionParam360, &sjt_call91);
#line 6
    sjt_parent209 = &sjt_call91;
#line 6
    sjt_functionParam362 = _parent->y;
#line 6
    sjf_f32_asstring(sjt_functionParam362, &sjt_call94);
#line 6
    sjt_functionParam361 = &sjt_call94;
#line 6
    sjf_string_add(sjt_parent209, sjt_functionParam361, _return);

    if (sjt_call91._refCount == 1) { sjf_string_destroy(&sjt_call91); }
;
    if (sjt_call92._refCount == 1) { sjf_string_destroy(&sjt_call92); }
;
    if (sjt_call93._refCount == 1) { sjf_string_destroy(&sjt_call93); }
;
    if (sjt_call94._refCount == 1) { sjf_string_destroy(&sjt_call94); }
;
}

void sjf_vec2_asstring_heap(sjs_vec2* _parent, sjs_string** _return) {
    sjs_string sjt_call95 = { -1 };
    sjs_string sjt_call96 = { -1 };
    sjs_string sjt_call97 = { -1 };
    sjs_string sjt_call98 = { -1 };
    float sjt_functionParam363;
    sjs_string* sjt_functionParam364 = 0;
    sjs_string* sjt_functionParam365 = 0;
    float sjt_functionParam366;
    sjs_string* sjt_parent211 = 0;
    sjs_string* sjt_parent212 = 0;

#line 6 "lib/ui/vec2.sj"
    sjt_functionParam363 = _parent->x;
#line 6
    sjf_f32_asstring(sjt_functionParam363, &sjt_call96);
#line 6
    sjt_parent212 = &sjt_call96;
#line 6
    sjt_call97._refCount = 1;
#line 6
    sjt_call97.count = 2;
#line 6
    sjt_call97.data._refCount = 1;
#line 6
    sjt_call97.data.datasize = 2;
#line 6
    sjt_call97.data.data = (void*)sjg_string34;
#line 6
    sjt_call97.data.isglobal = true;
#line 6
    sjt_call97.data.count = 2;
#line 6
    sjf_array_char(&sjt_call97.data);
#line 14 "lib/common/string.sj"
    sjt_call97._isnullterminated = false;
#line 14
    sjf_string(&sjt_call97);
#line 6 "lib/ui/vec2.sj"
    sjt_functionParam364 = &sjt_call97;
#line 6
    sjf_string_add(sjt_parent212, sjt_functionParam364, &sjt_call95);
#line 6
    sjt_parent211 = &sjt_call95;
#line 6
    sjt_functionParam366 = _parent->y;
#line 6
    sjf_f32_asstring(sjt_functionParam366, &sjt_call98);
#line 6
    sjt_functionParam365 = &sjt_call98;
#line 6
    sjf_string_add_heap(sjt_parent211, sjt_functionParam365, _return);

    if (sjt_call95._refCount == 1) { sjf_string_destroy(&sjt_call95); }
;
    if (sjt_call96._refCount == 1) { sjf_string_destroy(&sjt_call96); }
;
    if (sjt_call97._refCount == 1) { sjf_string_destroy(&sjt_call97); }
;
    if (sjt_call98._refCount == 1) { sjf_string_destroy(&sjt_call98); }
;
}

void sjf_vec2_copy(sjs_vec2* _this, sjs_vec2* _from) {
#line 1 "lib/ui/vec2.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
}

void sjf_vec2_destroy(sjs_vec2* _this) {
}

void sjf_vec2_getrawsize(int32_t* _return) {
#line 12 "lib/ui/vec2.sj"
    int x = sizeof(float) * 2;
#line 13
    #line 11 "lib/ui/vec2.sj"
(*_return) = x;
return;;
}

void sjf_vec2_heap(sjs_vec2* _this) {
}

void sjf_vec2_rawcopy(sjs_vec2* v, void* p, void** _return) {
#line 19 "lib/ui/vec2.sj"
    float* f = (float*)p;
#line 20
    *f = v->x;
#line 21
    f++;
#line 22
    *f = v->y;
#line 23
    f++;
#line 24
    #line 18 "lib/ui/vec2.sj"
(*_return) = (void*)f;
return;;
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

void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 49 "lib/ui/vec3.sj"
    _return->x = (_parent->y * v->z) - (_parent->z * v->y);
#line 50
    _return->y = (_parent->z * v->x) - (_parent->x * v->z);
#line 51
    _return->z = (_parent->x * v->y) - (_parent->y * v->x);
#line 51
    sjf_vec3(_return);
}

void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
#line 49 "lib/ui/vec3.sj"
    (*_return)->x = (_parent->y * v->z) - (_parent->z * v->y);
#line 50
    (*_return)->y = (_parent->z * v->x) - (_parent->x * v->z);
#line 51
    (*_return)->z = (_parent->x * v->y) - (_parent->y * v->x);
#line 51
    sjf_vec3_heap((*_return));
}

void sjf_vec3_destroy(sjs_vec3* _this) {
}

void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return) {
#line 56 "lib/ui/vec3.sj"
    (*_return) = ((_parent->x * v->x) + (_parent->y * v->y)) + (_parent->z * v->z);
}

void sjf_vec3_getrawsize(int32_t* _return) {
#line 82 "lib/ui/vec3.sj"
    int x = sizeof(float) * 3;
#line 83
    #line 81 "lib/ui/vec3.sj"
(*_return) = x;
return;;
}

void sjf_vec3_heap(sjs_vec3* _this) {
}

void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return) {
    float sjt_functionParam37;
    float sjv_t;

#line 39 "lib/ui/vec3.sj"
    sjt_functionParam37 = ((_parent->x * _parent->x) + (_parent->y * _parent->y)) + (_parent->z * _parent->z);
#line 39
    sjf_f32_sqrt(sjt_functionParam37, &sjv_t);
#line 39
    _return->_refCount = 1;
#line 41
    _return->x = _parent->x / sjv_t;
#line 42
    _return->y = _parent->y / sjv_t;
#line 43
    _return->z = _parent->z / sjv_t;
#line 43
    sjf_vec3(_return);
}

void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3** _return) {
    float sjt_functionParam38;
    float sjv_t;

#line 39 "lib/ui/vec3.sj"
    sjt_functionParam38 = ((_parent->x * _parent->x) + (_parent->y * _parent->y)) + (_parent->z * _parent->z);
#line 39
    sjf_f32_sqrt(sjt_functionParam38, &sjv_t);
#line 39
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
#line 39
    (*_return)->_refCount = 1;
#line 41
    (*_return)->x = _parent->x / sjv_t;
#line 42
    (*_return)->y = _parent->y / sjv_t;
#line 43
    (*_return)->z = _parent->z / sjv_t;
#line 43
    sjf_vec3_heap((*_return));
}

void sjf_vec3_rawcopy(sjs_vec3* v, void* p, void** _return) {
#line 89 "lib/ui/vec3.sj"
    float* f = (float*)p;
#line 90
    *f = v->x;
#line 91
    f++;
#line 92
    *f = v->y;
#line 93
    f++;
#line 94
    *f = v->z;
#line 95
    f++;
#line 96
    #line 88 "lib/ui/vec3.sj"
(*_return) = (void*)f;
return;;
}

void sjf_vec3_subtract(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 32 "lib/ui/vec3.sj"
    _return->x = _parent->x - v->x;
#line 33
    _return->y = _parent->y - v->y;
#line 34
    _return->z = _parent->z - v->z;
#line 34
    sjf_vec3(_return);
}

void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
#line 32 "lib/ui/vec3.sj"
    (*_return)->x = _parent->x - v->x;
#line 33
    (*_return)->y = _parent->y - v->y;
#line 34
    (*_return)->z = _parent->z - v->z;
#line 34
    sjf_vec3_heap((*_return));
}

void sjf_vec4(sjs_vec4* _this) {
}

void sjf_vec4_copy(sjs_vec4* _this, sjs_vec4* _from) {
#line 1 "lib/ui/vec4.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
#line 1
    _this->z = _from->z;
#line 1
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
#line 2 "lib/ui/vertexBufferBuilders.sj"
    sjf_vec3_copy(&_this->location, &_from->location);
#line 2
    _this->texture._refCount = 1;
#line 2
    sjf_vec2_copy(&_this->texture, &_from->texture);
#line 2
    _this->normal._refCount = 1;
#line 2
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
    int32_t sjt_capture28;
    int32_t sjt_capture29;
    int32_t sjt_capture30;

    sjf_vec3_getrawsize(&sjt_capture28);
    sjf_vec2_getrawsize(&sjt_capture29);
    sjf_vec3_getrawsize(&sjt_capture30);
#line 9 "lib/ui/vertexBufferBuilders.sj"
    (*_return) = (sjt_capture28 + sjt_capture29) + sjt_capture30;
}

void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_rawcopy(sjs_vertex_location_texture_normal* v, void* p, void** _return) {
    void* sjt_funcold15;
    void* sjt_funcold16;
    void* sjt_funcold17;
    sjs_vec3* sjt_functionParam168 = 0;
    void* sjt_functionParam169;
    sjs_vec2* sjt_functionParam170 = 0;
    void* sjt_functionParam171;
    sjs_vec3* sjt_functionParam172 = 0;
    void* sjt_functionParam173;

#line 87 "lib/ui/vec3.sj"
    sjt_funcold15 = p;
#line 13 "lib/ui/vertexBufferBuilders.sj"
    sjt_functionParam168 = &v->location;
#line 12
    sjt_functionParam169 = p;
#line 12
    sjf_vec3_rawcopy(sjt_functionParam168, sjt_functionParam169, &sjt_funcold15);
#line 87 "lib/ui/vec3.sj"
    p = sjt_funcold15;
#line 17 "lib/ui/vec2.sj"
    sjt_funcold16 = p;
#line 14 "lib/ui/vertexBufferBuilders.sj"
    sjt_functionParam170 = &v->texture;
#line 12
    sjt_functionParam171 = p;
#line 12
    sjf_vec2_rawcopy(sjt_functionParam170, sjt_functionParam171, &sjt_funcold16);
#line 17 "lib/ui/vec2.sj"
    p = sjt_funcold16;
#line 87 "lib/ui/vec3.sj"
    sjt_funcold17 = p;
#line 15 "lib/ui/vertexBufferBuilders.sj"
    sjt_functionParam172 = &v->normal;
#line 12
    sjt_functionParam173 = p;
#line 12
    sjf_vec3_rawcopy(sjt_functionParam172, sjt_functionParam173, &sjt_funcold17);
#line 87 "lib/ui/vec3.sj"
    p = sjt_funcold17;
#line 12 "lib/ui/vertexBufferBuilders.sj"
    (*_return) = p;
}

void sjf_vertexbuffer_vertex_location_texture_normal(sjs_vertexbuffer_vertex_location_texture_normal* _this) {
#line 102 "lib/ui/vertexBuffer.sj"
    _this->buffer = vertex_buffer_new((char*)_this->format.data.data);
#line 103
    if (_this->indices.count > 0) {
#line 104
        vertex_buffer_push_back_indices(_this->buffer, (GLuint*)_this->indices.data, _this->indices.count);
#line 105
    }
#line 107
    if (_this->vertices.count > 0) {
#line 108
        int vertexSize;
#line 109
        sjf_vertex_location_texture_normal_getrawsize(&vertexSize);
#line 110
        int verticesSize = _this->vertices.count * vertexSize;
#line 111
        char* t = malloc(verticesSize);
#line 112
        char* buffer = t;
#line 113
        sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_this->vertices.data;
#line 114
        for (int i = 0; i < _this->vertices.count; i++) {
#line 115
            sjf_vertex_location_texture_normal_rawcopy(&p[i], buffer, &buffer);
#line 116
        }
#line 117
        vertex_buffer_push_back_vertices(_this->buffer, t, _this->vertices.count);
#line 118
        free(t);
#line 119
    }
}

void sjf_vertexbuffer_vertex_location_texture_normal_copy(sjs_vertexbuffer_vertex_location_texture_normal* _this, sjs_vertexbuffer_vertex_location_texture_normal* _from) {
    _this->format._refCount = 1;
#line 7 "lib/ui/vertexBuffer.sj"
    sjf_string_copy(&_this->format, &_from->format);
#line 7
    _this->indices._refCount = 1;
#line 7
    sjf_array_i32_copy(&_this->indices, &_from->indices);
#line 7
    _this->vertices._refCount = 1;
#line 7
    sjf_array_vertex_location_texture_normal_copy(&_this->vertices, &_from->vertices);
#line 124
    _this->buffer = _from->buffer;
#line 125
    ptr_retain(_this->buffer);
}

void sjf_vertexbuffer_vertex_location_texture_normal_destroy(sjs_vertexbuffer_vertex_location_texture_normal* _this) {
#line 129 "lib/ui/vertexBuffer.sj"
    if (ptr_release(_this->buffer)) {
#line 130
        vertex_buffer_delete(_this->buffer);  
#line 131
    }
#line 131
    if (_this->format._refCount == 1) { sjf_string_destroy(&_this->format); }
;
#line 131
    if (_this->indices._refCount == 1) { sjf_array_i32_destroy(&_this->indices); }
;
#line 131
    if (_this->vertices._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&_this->vertices); }
;
}

void sjf_vertexbuffer_vertex_location_texture_normal_heap(sjs_vertexbuffer_vertex_location_texture_normal* _this) {
#line 102 "lib/ui/vertexBuffer.sj"
    _this->buffer = vertex_buffer_new((char*)_this->format.data.data);
#line 103
    if (_this->indices.count > 0) {
#line 104
        vertex_buffer_push_back_indices(_this->buffer, (GLuint*)_this->indices.data, _this->indices.count);
#line 105
    }
#line 107
    if (_this->vertices.count > 0) {
#line 108
        int vertexSize;
#line 109
        sjf_vertex_location_texture_normal_getrawsize(&vertexSize);
#line 110
        int verticesSize = _this->vertices.count * vertexSize;
#line 111
        char* t = malloc(verticesSize);
#line 112
        char* buffer = t;
#line 113
        sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_this->vertices.data;
#line 114
        for (int i = 0; i < _this->vertices.count; i++) {
#line 115
            sjf_vertex_location_texture_normal_rawcopy(&p[i], buffer, &buffer);
#line 116
        }
#line 117
        vertex_buffer_push_back_vertices(_this->buffer, t, _this->vertices.count);
#line 118
        free(t);
#line 119
    }
}

void sjf_vertexbuffer_vertex_location_texture_normal_render(sjs_vertexbuffer_vertex_location_texture_normal* _parent, int32_t gldrawmode) {
#line 96 "lib/ui/vertexBuffer.sj"
    vertex_buffer_render(_parent->buffer, gldrawmode);
}

void sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture(sjs_vertexbuffer_vertex_location_texture_normal* _parent, sjs_point* screen, sjs_rect* viewport, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_vec2* _return) {
    int32_t i;
    sjs_mat4 sjt_call28 = { -1 };
    int32_t sjt_cast11;
    int32_t sjt_cast12;
    int32_t sjt_cast13;
    int32_t sjt_cast14;
    int32_t sjt_forEnd12;
    int32_t sjt_forStart12;
    sjs_mat4* sjt_functionParam228 = 0;
    sjs_mat4* sjt_functionParam229 = 0;
    sjs_vec4* sjt_functionParam230 = 0;
    sjs_vec4* sjt_functionParam231 = 0;
    sjs_vec3* sjt_functionParam232 = 0;
    sjs_mat4* sjt_parent111 = 0;
    sjs_mat4* sjt_parent112 = 0;
    sjs_mat4* sjt_parent113 = 0;
    sjs_mat4* sjt_parent114 = 0;
    sjs_mat4* sjt_parent115 = 0;
    sjs_vec3* sjt_parent116 = 0;
    sjs_vec3* sjt_parent117 = 0;
    sjs_mat4 sjv_all = { -1 };
    sjs_mat4 sjv_allinverse = { -1 };
    int32_t sjv_ctriangles;
    sjs_vec3 sjv_intersection = { -1 };
    sjs_vec2 sjv_start = { -1 };
    sjs_vec2 sjv_texture = { -1 };
    sjs_vec3 sjv_vflatteneddir = { -1 };
    sjs_vec3 sjv_vflattenedorigin1 = { -1 };
    sjs_vec3 sjv_vflattenedorigin2 = { -1 };
    sjs_vec3 sjv_vpickraydir = { -1 };
    sjs_vec3 sjv_vpickrayorig = { -1 };
    sjs_vec4 sjv_vprojectedorigin1 = { -1 };
    sjs_vec4 sjv_vprojectedorigin2 = { -1 };
    sjs_vec4 sjv_vscreenorigin1 = { -1 };
    sjs_vec4 sjv_vscreenorigin2 = { -1 };

#line 44 "lib/ui/vertexBuffer.sj"
    sjv_intersection._refCount = -1;
#line 45
    sjv_texture._refCount = -1;
#line 45
    sjv_start._refCount = 1;
#line 49
    sjt_cast11 = screen->x - viewport->x;
#line 49
    sjt_cast12 = viewport->w;
#line 49
    sjv_start.x = (((float)sjt_cast11 / (float)sjt_cast12) * 2.0f) - 1.0f;
#line 50
    sjt_cast13 = screen->y - viewport->y;
#line 50
    sjt_cast14 = viewport->h;
#line 50
    sjv_start.y = 1.0f - (((float)sjt_cast13 / (float)sjt_cast14) * 2.0f);
#line 50
    sjf_vec2(&sjv_start);
#line 50
    sjv_vscreenorigin1._refCount = 1;
#line 52
    sjv_vscreenorigin1.x = (&sjv_start)->x;
#line 52
    sjv_vscreenorigin1.y = (&sjv_start)->y;
#line 52
    sjv_vscreenorigin1.z = 0.0f;
#line 52
    sjv_vscreenorigin1.w = 1.0f;
#line 52
    sjf_vec4(&sjv_vscreenorigin1);
#line 52
    sjv_vscreenorigin2._refCount = 1;
#line 53
    sjv_vscreenorigin2.x = (&sjv_start)->x;
#line 53
    sjv_vscreenorigin2.y = (&sjv_start)->y;
#line 53
    sjv_vscreenorigin2.z = 1.0f;
#line 53
    sjv_vscreenorigin2.w = 1.0f;
#line 53
    sjf_vec4(&sjv_vscreenorigin2);
#line 43
    sjt_parent112 = projection;
#line 43
    sjt_functionParam228 = view;
#line 43
    sjf_mat4_multiply(sjt_parent112, sjt_functionParam228, &sjt_call28);
#line 54
    sjt_parent111 = &sjt_call28;
#line 43
    sjt_functionParam229 = world;
#line 43
    sjf_mat4_multiply(sjt_parent111, sjt_functionParam229, &sjv_all);
#line 71 "lib/ui/mat4.sj"
    sjt_parent113 = &sjv_all;
#line 71
    sjf_mat4_invert(sjt_parent113, &sjv_allinverse);
#line 62
    sjt_parent114 = &sjv_allinverse;
#line 56 "lib/ui/vertexBuffer.sj"
    sjt_functionParam230 = &sjv_vscreenorigin1;
#line 56
    sjf_mat4_multiplyvec4(sjt_parent114, sjt_functionParam230, &sjv_vprojectedorigin1);
#line 62 "lib/ui/mat4.sj"
    sjt_parent115 = &sjv_allinverse;
#line 57 "lib/ui/vertexBuffer.sj"
    sjt_functionParam231 = &sjv_vscreenorigin2;
#line 57
    sjf_mat4_multiplyvec4(sjt_parent115, sjt_functionParam231, &sjv_vprojectedorigin2);
#line 57
    sjv_vflattenedorigin1._refCount = 1;
#line 58
    sjv_vflattenedorigin1.x = (&sjv_vprojectedorigin1)->x / (&sjv_vprojectedorigin1)->w;
#line 58
    sjv_vflattenedorigin1.y = (&sjv_vprojectedorigin1)->y / (&sjv_vprojectedorigin1)->w;
#line 58
    sjv_vflattenedorigin1.z = (&sjv_vprojectedorigin1)->z / (&sjv_vprojectedorigin1)->w;
#line 58
    sjf_vec3(&sjv_vflattenedorigin1);
#line 58
    sjv_vflattenedorigin2._refCount = 1;
#line 59
    sjv_vflattenedorigin2.x = (&sjv_vprojectedorigin2)->x / (&sjv_vprojectedorigin2)->w;
#line 59
    sjv_vflattenedorigin2.y = (&sjv_vprojectedorigin2)->y / (&sjv_vprojectedorigin2)->w;
#line 59
    sjv_vflattenedorigin2.z = (&sjv_vprojectedorigin2)->z / (&sjv_vprojectedorigin2)->w;
#line 59
    sjf_vec3(&sjv_vflattenedorigin2);
#line 30 "lib/ui/vec3.sj"
    sjt_parent116 = &sjv_vflattenedorigin2;
#line 60 "lib/ui/vertexBuffer.sj"
    sjt_functionParam232 = &sjv_vflattenedorigin1;
#line 60
    sjf_vec3_subtract(sjt_parent116, sjt_functionParam232, &sjv_vflatteneddir);
#line 60
    sjv_vpickrayorig._refCount = 1;
#line 62
    sjf_vec3_copy(&sjv_vpickrayorig, &sjv_vflattenedorigin1);
#line 38 "lib/ui/vec3.sj"
    sjt_parent117 = &sjv_vflatteneddir;
#line 38
    sjf_vec3_normalize(sjt_parent117, &sjv_vpickraydir);
    if ((&_parent->indices)->count > 0) {
#line 65 "lib/ui/vertexBuffer.sj"
        sjv_ctriangles = (&_parent->indices)->count / 3;
    } else {
#line 65 "lib/ui/vertexBuffer.sj"
        sjv_ctriangles = (&_parent->vertices)->count / 3;
    }

#line 66 "lib/ui/vertexBuffer.sj"
    sjt_forStart12 = 0;
#line 66
    sjt_forEnd12 = sjv_ctriangles;
#line 66
    i = sjt_forStart12;
    while (i < sjt_forEnd12) {
        sjs_vec3* sjt_functionParam262 = 0;
        sjs_vec3* sjt_functionParam263 = 0;
        sjs_vec3* sjt_functionParam264 = 0;
        sjs_vec3* sjt_functionParam265 = 0;
        sjs_vec3* sjt_functionParam266 = 0;
        sjs_vec3 sjv_result = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex0 = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex1 = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex2 = { -1 };

        if ((&_parent->indices)->count > 0) {
            int32_t sjt_functionParam233;
            int32_t sjt_functionParam234;
            sjs_array_vertex_location_texture_normal* sjt_parent118 = 0;
            sjs_array_i32* sjt_parent119 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent118 = &_parent->vertices;
#line 7
            sjt_parent119 = &_parent->indices;
#line 67 "lib/ui/vertexBuffer.sj"
            sjt_functionParam234 = (i * 3) + 0;
#line 67
            sjf_array_i32_getat(sjt_parent119, sjt_functionParam234, &sjt_functionParam233);
#line 67
            sjf_array_vertex_location_texture_normal_getat(sjt_parent118, sjt_functionParam233, &sjv_vertex0);
        } else {
            int32_t sjt_functionParam235;
            sjs_array_vertex_location_texture_normal* sjt_parent120 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent120 = &_parent->vertices;
#line 67 "lib/ui/vertexBuffer.sj"
            sjt_functionParam235 = (i * 3) + 0;
#line 67
            sjf_array_vertex_location_texture_normal_getat(sjt_parent120, sjt_functionParam235, &sjv_vertex0);
        }

        if ((&_parent->indices)->count > 0) {
            int32_t sjt_functionParam236;
            int32_t sjt_functionParam237;
            sjs_array_vertex_location_texture_normal* sjt_parent121 = 0;
            sjs_array_i32* sjt_parent122 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent121 = &_parent->vertices;
#line 7
            sjt_parent122 = &_parent->indices;
#line 68 "lib/ui/vertexBuffer.sj"
            sjt_functionParam237 = (i * 3) + 1;
#line 68
            sjf_array_i32_getat(sjt_parent122, sjt_functionParam237, &sjt_functionParam236);
#line 68
            sjf_array_vertex_location_texture_normal_getat(sjt_parent121, sjt_functionParam236, &sjv_vertex1);
        } else {
            int32_t sjt_functionParam238;
            sjs_array_vertex_location_texture_normal* sjt_parent123 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent123 = &_parent->vertices;
#line 68 "lib/ui/vertexBuffer.sj"
            sjt_functionParam238 = (i * 3) + 1;
#line 68
            sjf_array_vertex_location_texture_normal_getat(sjt_parent123, sjt_functionParam238, &sjv_vertex1);
        }

        if ((&_parent->indices)->count > 0) {
            int32_t sjt_functionParam239;
            int32_t sjt_functionParam240;
            sjs_array_vertex_location_texture_normal* sjt_parent124 = 0;
            sjs_array_i32* sjt_parent125 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent124 = &_parent->vertices;
#line 7
            sjt_parent125 = &_parent->indices;
#line 69 "lib/ui/vertexBuffer.sj"
            sjt_functionParam240 = (i * 3) + 2;
#line 69
            sjf_array_i32_getat(sjt_parent125, sjt_functionParam240, &sjt_functionParam239);
#line 69
            sjf_array_vertex_location_texture_normal_getat(sjt_parent124, sjt_functionParam239, &sjv_vertex2);
        } else {
            int32_t sjt_functionParam241;
            sjs_array_vertex_location_texture_normal* sjt_parent126 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent126 = &_parent->vertices;
#line 69 "lib/ui/vertexBuffer.sj"
            sjt_functionParam241 = (i * 3) + 2;
#line 69
            sjf_array_vertex_location_texture_normal_getat(sjt_parent126, sjt_functionParam241, &sjv_vertex2);
        }

#line 72 "lib/ui/vertexBuffer.sj"
        sjt_functionParam262 = &sjv_vpickrayorig;
#line 72
        sjt_functionParam263 = &sjv_vpickraydir;
#line 72
        sjt_functionParam264 = &(&sjv_vertex0)->location;
#line 72
        sjt_functionParam265 = &(&sjv_vertex1)->location;
#line 72
        sjt_functionParam266 = &(&sjv_vertex2)->location;
#line 72
        sjf_intersecttriangle(sjt_functionParam262, sjt_functionParam263, sjt_functionParam264, sjt_functionParam265, sjt_functionParam266, &sjv_result);
        if (((sjv_result._refCount != -1 ? &sjv_result : 0) != 0)) {
            sjs_vec3* ifValue5 = 0;
            float sjt_capture33;
            float_option sjt_capture34;
            sjs_vec3 sjt_value6 = { -1 };
            sjs_vec2 sjt_value7 = { -1 };

#line 73 "lib/ui/vertexBuffer.sj"
            ifValue5 = (sjv_result._refCount != -1 ? &sjv_result : 0);
            if ((sjv_intersection._refCount != -1 ? &sjv_intersection : 0) != 0) {
                sjs_vec3* sjt_capture35 = 0;
                float sjt_value4;

#line 1 "lib/ui/vec3.sj"
                sjt_capture35 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
#line 74 "lib/ui/vertexBuffer.sj"
                sjt_value4 = sjt_capture35->z;
#line 74
                sjt_capture34.isvalid = true;
#line 74
                sjt_capture34.value = sjt_value4;
            } else {
#line 74 "lib/ui/vertexBuffer.sj"
                sjt_capture34 = float_empty;
            }

            if (sjt_capture34.isvalid) {
                float_option sjt_getValue1;

                if ((sjv_intersection._refCount != -1 ? &sjv_intersection : 0) != 0) {
                    sjs_vec3* sjt_capture36 = 0;
                    float sjt_value5;

#line 1 "lib/ui/vec3.sj"
                    sjt_capture36 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
#line 74 "lib/ui/vertexBuffer.sj"
                    sjt_value5 = sjt_capture36->z;
#line 74
                    sjt_getValue1.isvalid = true;
#line 74
                    sjt_getValue1.value = sjt_value5;
                } else {
#line 74 "lib/ui/vertexBuffer.sj"
                    sjt_getValue1 = float_empty;
                }

#line 74 "lib/ui/vertexBuffer.sj"
                sjt_capture33 = sjt_getValue1.value;
            } else {
#line 74 "lib/ui/vertexBuffer.sj"
                sjt_capture33 = 0.0f;
            }

            if (((sjv_intersection._refCount != -1 ? &sjv_intersection : 0) == 0) || (ifValue5->z < sjt_capture33)) {
                float sjv_dtu1;
                float sjv_dtu2;
                float sjv_dtv1;
                float sjv_dtv2;

                sjt_value6._refCount = 1;
#line 75 "lib/ui/vertexBuffer.sj"
                sjf_vec3_copy(&sjt_value6, ifValue5);
#line 75
                if (sjv_intersection._refCount == 1) { sjf_vec3_destroy(&sjv_intersection); }
;
#line 75
                sjs_vec3* copyoption16 = &sjt_value6;
                if (copyoption16 != 0) {
                    sjv_intersection._refCount = 1;
#line 75 "lib/ui/vertexBuffer.sj"
                    sjf_vec3_copy(&sjv_intersection, copyoption16);
                } else {
                    sjv_intersection._refCount = -1;
                }

#line 80
                sjv_dtu1 = (&(&sjv_vertex1)->texture)->x - (&(&sjv_vertex0)->texture)->x;
#line 81
                sjv_dtu2 = (&(&sjv_vertex2)->texture)->x - (&(&sjv_vertex0)->texture)->x;
#line 82
                sjv_dtv1 = (&(&sjv_vertex1)->texture)->y - (&(&sjv_vertex0)->texture)->y;
#line 83
                sjv_dtv2 = (&(&sjv_vertex2)->texture)->y - (&(&sjv_vertex0)->texture)->y;
#line 83
                sjt_value7._refCount = 1;
#line 85
                sjt_value7.x = ((&(&sjv_vertex0)->texture)->x + (ifValue5->x * sjv_dtu1)) + (ifValue5->y * sjv_dtu2);
#line 86
                sjt_value7.y = ((&(&sjv_vertex0)->texture)->y + (ifValue5->x * sjv_dtv1)) + (ifValue5->y * sjv_dtv2);
#line 86
                sjf_vec2(&sjt_value7);
#line 86
                if (sjv_texture._refCount == 1) { sjf_vec2_destroy(&sjv_texture); }
;
#line 84
                sjs_vec2* copyoption17 = &sjt_value7;
                if (copyoption17 != 0) {
                    sjv_texture._refCount = 1;
#line 84 "lib/ui/vertexBuffer.sj"
                    sjf_vec2_copy(&sjv_texture, copyoption17);
                } else {
                    sjv_texture._refCount = -1;
                }
            }

            if (sjt_value6._refCount == 1) { sjf_vec3_destroy(&sjt_value6); }
;
            if (sjt_value7._refCount == 1) { sjf_vec2_destroy(&sjt_value7); }
;
        }

#line 66
        i++;

        if (sjv_result._refCount == 1) { sjf_vec3_destroy(&sjv_result); }
;
        if (sjv_vertex0._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex0); }
;
        if (sjv_vertex1._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex1); }
;
        if (sjv_vertex2._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex2); }
;
    }

#line 43
    sjs_vec2* copyoption18 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
    if (copyoption18 != 0) {
        _return->_refCount = 1;
#line 43 "lib/ui/vertexBuffer.sj"
        sjf_vec2_copy(_return, copyoption18);
    } else {
        _return->_refCount = -1;
    }

    if (sjt_call28._refCount == 1) { sjf_mat4_destroy(&sjt_call28); }
;
    if (sjv_all._refCount == 1) { sjf_mat4_destroy(&sjv_all); }
;
    if (sjv_allinverse._refCount == 1) { sjf_mat4_destroy(&sjv_allinverse); }
;
    if (sjv_intersection._refCount == 1) { sjf_vec3_destroy(&sjv_intersection); }
;
    if (sjv_start._refCount == 1) { sjf_vec2_destroy(&sjv_start); }
;
    if (sjv_texture._refCount == 1) { sjf_vec2_destroy(&sjv_texture); }
;
    if (sjv_vflatteneddir._refCount == 1) { sjf_vec3_destroy(&sjv_vflatteneddir); }
;
    if (sjv_vflattenedorigin1._refCount == 1) { sjf_vec3_destroy(&sjv_vflattenedorigin1); }
;
    if (sjv_vflattenedorigin2._refCount == 1) { sjf_vec3_destroy(&sjv_vflattenedorigin2); }
;
    if (sjv_vpickraydir._refCount == 1) { sjf_vec3_destroy(&sjv_vpickraydir); }
;
    if (sjv_vpickrayorig._refCount == 1) { sjf_vec3_destroy(&sjv_vpickrayorig); }
;
    if (sjv_vprojectedorigin1._refCount == 1) { sjf_vec4_destroy(&sjv_vprojectedorigin1); }
;
    if (sjv_vprojectedorigin2._refCount == 1) { sjf_vec4_destroy(&sjv_vprojectedorigin2); }
;
    if (sjv_vscreenorigin1._refCount == 1) { sjf_vec4_destroy(&sjv_vscreenorigin1); }
;
    if (sjv_vscreenorigin2._refCount == 1) { sjf_vec4_destroy(&sjv_vscreenorigin2); }
;
}

void sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture_heap(sjs_vertexbuffer_vertex_location_texture_normal* _parent, sjs_point* screen, sjs_rect* viewport, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_vec2** _return) {
    int32_t i;
    sjs_mat4 sjt_call29 = { -1 };
    int32_t sjt_cast15;
    int32_t sjt_cast16;
    int32_t sjt_cast17;
    int32_t sjt_cast18;
    int32_t sjt_forEnd13;
    int32_t sjt_forStart13;
    sjs_mat4* sjt_functionParam267 = 0;
    sjs_mat4* sjt_functionParam268 = 0;
    sjs_vec4* sjt_functionParam269 = 0;
    sjs_vec4* sjt_functionParam270 = 0;
    sjs_vec3* sjt_functionParam271 = 0;
    sjs_mat4* sjt_parent147 = 0;
    sjs_mat4* sjt_parent148 = 0;
    sjs_mat4* sjt_parent149 = 0;
    sjs_mat4* sjt_parent150 = 0;
    sjs_mat4* sjt_parent151 = 0;
    sjs_vec3* sjt_parent152 = 0;
    sjs_vec3* sjt_parent153 = 0;
    sjs_mat4 sjv_all = { -1 };
    sjs_mat4 sjv_allinverse = { -1 };
    int32_t sjv_ctriangles;
    sjs_vec3 sjv_intersection = { -1 };
    sjs_vec2 sjv_start = { -1 };
    sjs_vec2 sjv_texture = { -1 };
    sjs_vec3 sjv_vflatteneddir = { -1 };
    sjs_vec3 sjv_vflattenedorigin1 = { -1 };
    sjs_vec3 sjv_vflattenedorigin2 = { -1 };
    sjs_vec3 sjv_vpickraydir = { -1 };
    sjs_vec3 sjv_vpickrayorig = { -1 };
    sjs_vec4 sjv_vprojectedorigin1 = { -1 };
    sjs_vec4 sjv_vprojectedorigin2 = { -1 };
    sjs_vec4 sjv_vscreenorigin1 = { -1 };
    sjs_vec4 sjv_vscreenorigin2 = { -1 };

#line 44 "lib/ui/vertexBuffer.sj"
    sjv_intersection._refCount = -1;
#line 45
    sjv_texture._refCount = -1;
#line 45
    sjv_start._refCount = 1;
#line 49
    sjt_cast15 = screen->x - viewport->x;
#line 49
    sjt_cast16 = viewport->w;
#line 49
    sjv_start.x = (((float)sjt_cast15 / (float)sjt_cast16) * 2.0f) - 1.0f;
#line 50
    sjt_cast17 = screen->y - viewport->y;
#line 50
    sjt_cast18 = viewport->h;
#line 50
    sjv_start.y = 1.0f - (((float)sjt_cast17 / (float)sjt_cast18) * 2.0f);
#line 50
    sjf_vec2(&sjv_start);
#line 50
    sjv_vscreenorigin1._refCount = 1;
#line 52
    sjv_vscreenorigin1.x = (&sjv_start)->x;
#line 52
    sjv_vscreenorigin1.y = (&sjv_start)->y;
#line 52
    sjv_vscreenorigin1.z = 0.0f;
#line 52
    sjv_vscreenorigin1.w = 1.0f;
#line 52
    sjf_vec4(&sjv_vscreenorigin1);
#line 52
    sjv_vscreenorigin2._refCount = 1;
#line 53
    sjv_vscreenorigin2.x = (&sjv_start)->x;
#line 53
    sjv_vscreenorigin2.y = (&sjv_start)->y;
#line 53
    sjv_vscreenorigin2.z = 1.0f;
#line 53
    sjv_vscreenorigin2.w = 1.0f;
#line 53
    sjf_vec4(&sjv_vscreenorigin2);
#line 43
    sjt_parent148 = projection;
#line 43
    sjt_functionParam267 = view;
#line 43
    sjf_mat4_multiply(sjt_parent148, sjt_functionParam267, &sjt_call29);
#line 54
    sjt_parent147 = &sjt_call29;
#line 43
    sjt_functionParam268 = world;
#line 43
    sjf_mat4_multiply(sjt_parent147, sjt_functionParam268, &sjv_all);
#line 71 "lib/ui/mat4.sj"
    sjt_parent149 = &sjv_all;
#line 71
    sjf_mat4_invert(sjt_parent149, &sjv_allinverse);
#line 62
    sjt_parent150 = &sjv_allinverse;
#line 56 "lib/ui/vertexBuffer.sj"
    sjt_functionParam269 = &sjv_vscreenorigin1;
#line 56
    sjf_mat4_multiplyvec4(sjt_parent150, sjt_functionParam269, &sjv_vprojectedorigin1);
#line 62 "lib/ui/mat4.sj"
    sjt_parent151 = &sjv_allinverse;
#line 57 "lib/ui/vertexBuffer.sj"
    sjt_functionParam270 = &sjv_vscreenorigin2;
#line 57
    sjf_mat4_multiplyvec4(sjt_parent151, sjt_functionParam270, &sjv_vprojectedorigin2);
#line 57
    sjv_vflattenedorigin1._refCount = 1;
#line 58
    sjv_vflattenedorigin1.x = (&sjv_vprojectedorigin1)->x / (&sjv_vprojectedorigin1)->w;
#line 58
    sjv_vflattenedorigin1.y = (&sjv_vprojectedorigin1)->y / (&sjv_vprojectedorigin1)->w;
#line 58
    sjv_vflattenedorigin1.z = (&sjv_vprojectedorigin1)->z / (&sjv_vprojectedorigin1)->w;
#line 58
    sjf_vec3(&sjv_vflattenedorigin1);
#line 58
    sjv_vflattenedorigin2._refCount = 1;
#line 59
    sjv_vflattenedorigin2.x = (&sjv_vprojectedorigin2)->x / (&sjv_vprojectedorigin2)->w;
#line 59
    sjv_vflattenedorigin2.y = (&sjv_vprojectedorigin2)->y / (&sjv_vprojectedorigin2)->w;
#line 59
    sjv_vflattenedorigin2.z = (&sjv_vprojectedorigin2)->z / (&sjv_vprojectedorigin2)->w;
#line 59
    sjf_vec3(&sjv_vflattenedorigin2);
#line 30 "lib/ui/vec3.sj"
    sjt_parent152 = &sjv_vflattenedorigin2;
#line 60 "lib/ui/vertexBuffer.sj"
    sjt_functionParam271 = &sjv_vflattenedorigin1;
#line 60
    sjf_vec3_subtract(sjt_parent152, sjt_functionParam271, &sjv_vflatteneddir);
#line 60
    sjv_vpickrayorig._refCount = 1;
#line 62
    sjf_vec3_copy(&sjv_vpickrayorig, &sjv_vflattenedorigin1);
#line 38 "lib/ui/vec3.sj"
    sjt_parent153 = &sjv_vflatteneddir;
#line 38
    sjf_vec3_normalize(sjt_parent153, &sjv_vpickraydir);
    if ((&_parent->indices)->count > 0) {
#line 65 "lib/ui/vertexBuffer.sj"
        sjv_ctriangles = (&_parent->indices)->count / 3;
    } else {
#line 65 "lib/ui/vertexBuffer.sj"
        sjv_ctriangles = (&_parent->vertices)->count / 3;
    }

#line 66 "lib/ui/vertexBuffer.sj"
    sjt_forStart13 = 0;
#line 66
    sjt_forEnd13 = sjv_ctriangles;
#line 66
    i = sjt_forStart13;
    while (i < sjt_forEnd13) {
        sjs_vec3* sjt_functionParam281 = 0;
        sjs_vec3* sjt_functionParam282 = 0;
        sjs_vec3* sjt_functionParam283 = 0;
        sjs_vec3* sjt_functionParam284 = 0;
        sjs_vec3* sjt_functionParam285 = 0;
        sjs_vec3 sjv_result = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex0 = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex1 = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex2 = { -1 };

        if ((&_parent->indices)->count > 0) {
            int32_t sjt_functionParam272;
            int32_t sjt_functionParam273;
            sjs_array_vertex_location_texture_normal* sjt_parent154 = 0;
            sjs_array_i32* sjt_parent155 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent154 = &_parent->vertices;
#line 7
            sjt_parent155 = &_parent->indices;
#line 67 "lib/ui/vertexBuffer.sj"
            sjt_functionParam273 = (i * 3) + 0;
#line 67
            sjf_array_i32_getat(sjt_parent155, sjt_functionParam273, &sjt_functionParam272);
#line 67
            sjf_array_vertex_location_texture_normal_getat(sjt_parent154, sjt_functionParam272, &sjv_vertex0);
        } else {
            int32_t sjt_functionParam274;
            sjs_array_vertex_location_texture_normal* sjt_parent156 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent156 = &_parent->vertices;
#line 67 "lib/ui/vertexBuffer.sj"
            sjt_functionParam274 = (i * 3) + 0;
#line 67
            sjf_array_vertex_location_texture_normal_getat(sjt_parent156, sjt_functionParam274, &sjv_vertex0);
        }

        if ((&_parent->indices)->count > 0) {
            int32_t sjt_functionParam275;
            int32_t sjt_functionParam276;
            sjs_array_vertex_location_texture_normal* sjt_parent157 = 0;
            sjs_array_i32* sjt_parent158 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent157 = &_parent->vertices;
#line 7
            sjt_parent158 = &_parent->indices;
#line 68 "lib/ui/vertexBuffer.sj"
            sjt_functionParam276 = (i * 3) + 1;
#line 68
            sjf_array_i32_getat(sjt_parent158, sjt_functionParam276, &sjt_functionParam275);
#line 68
            sjf_array_vertex_location_texture_normal_getat(sjt_parent157, sjt_functionParam275, &sjv_vertex1);
        } else {
            int32_t sjt_functionParam277;
            sjs_array_vertex_location_texture_normal* sjt_parent159 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent159 = &_parent->vertices;
#line 68 "lib/ui/vertexBuffer.sj"
            sjt_functionParam277 = (i * 3) + 1;
#line 68
            sjf_array_vertex_location_texture_normal_getat(sjt_parent159, sjt_functionParam277, &sjv_vertex1);
        }

        if ((&_parent->indices)->count > 0) {
            int32_t sjt_functionParam278;
            int32_t sjt_functionParam279;
            sjs_array_vertex_location_texture_normal* sjt_parent160 = 0;
            sjs_array_i32* sjt_parent161 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent160 = &_parent->vertices;
#line 7
            sjt_parent161 = &_parent->indices;
#line 69 "lib/ui/vertexBuffer.sj"
            sjt_functionParam279 = (i * 3) + 2;
#line 69
            sjf_array_i32_getat(sjt_parent161, sjt_functionParam279, &sjt_functionParam278);
#line 69
            sjf_array_vertex_location_texture_normal_getat(sjt_parent160, sjt_functionParam278, &sjv_vertex2);
        } else {
            int32_t sjt_functionParam280;
            sjs_array_vertex_location_texture_normal* sjt_parent162 = 0;

#line 7 "lib/common/array.sj"
            sjt_parent162 = &_parent->vertices;
#line 69 "lib/ui/vertexBuffer.sj"
            sjt_functionParam280 = (i * 3) + 2;
#line 69
            sjf_array_vertex_location_texture_normal_getat(sjt_parent162, sjt_functionParam280, &sjv_vertex2);
        }

#line 72 "lib/ui/vertexBuffer.sj"
        sjt_functionParam281 = &sjv_vpickrayorig;
#line 72
        sjt_functionParam282 = &sjv_vpickraydir;
#line 72
        sjt_functionParam283 = &(&sjv_vertex0)->location;
#line 72
        sjt_functionParam284 = &(&sjv_vertex1)->location;
#line 72
        sjt_functionParam285 = &(&sjv_vertex2)->location;
#line 72
        sjf_intersecttriangle(sjt_functionParam281, sjt_functionParam282, sjt_functionParam283, sjt_functionParam284, sjt_functionParam285, &sjv_result);
        if (((sjv_result._refCount != -1 ? &sjv_result : 0) != 0)) {
            sjs_vec3* ifValue6 = 0;
            float sjt_capture37;
            float_option sjt_capture38;
            sjs_vec3 sjt_value10 = { -1 };
            sjs_vec2 sjt_value11 = { -1 };

#line 73 "lib/ui/vertexBuffer.sj"
            ifValue6 = (sjv_result._refCount != -1 ? &sjv_result : 0);
            if ((sjv_intersection._refCount != -1 ? &sjv_intersection : 0) != 0) {
                sjs_vec3* sjt_capture39 = 0;
                float sjt_value8;

#line 1 "lib/ui/vec3.sj"
                sjt_capture39 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
#line 74 "lib/ui/vertexBuffer.sj"
                sjt_value8 = sjt_capture39->z;
#line 74
                sjt_capture38.isvalid = true;
#line 74
                sjt_capture38.value = sjt_value8;
            } else {
#line 74 "lib/ui/vertexBuffer.sj"
                sjt_capture38 = float_empty;
            }

            if (sjt_capture38.isvalid) {
                float_option sjt_getValue2;

                if ((sjv_intersection._refCount != -1 ? &sjv_intersection : 0) != 0) {
                    sjs_vec3* sjt_capture40 = 0;
                    float sjt_value9;

#line 1 "lib/ui/vec3.sj"
                    sjt_capture40 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
#line 74 "lib/ui/vertexBuffer.sj"
                    sjt_value9 = sjt_capture40->z;
#line 74
                    sjt_getValue2.isvalid = true;
#line 74
                    sjt_getValue2.value = sjt_value9;
                } else {
#line 74 "lib/ui/vertexBuffer.sj"
                    sjt_getValue2 = float_empty;
                }

#line 74 "lib/ui/vertexBuffer.sj"
                sjt_capture37 = sjt_getValue2.value;
            } else {
#line 74 "lib/ui/vertexBuffer.sj"
                sjt_capture37 = 0.0f;
            }

            if (((sjv_intersection._refCount != -1 ? &sjv_intersection : 0) == 0) || (ifValue6->z < sjt_capture37)) {
                float sjv_dtu1;
                float sjv_dtu2;
                float sjv_dtv1;
                float sjv_dtv2;

                sjt_value10._refCount = 1;
#line 75 "lib/ui/vertexBuffer.sj"
                sjf_vec3_copy(&sjt_value10, ifValue6);
#line 75
                if (sjv_intersection._refCount == 1) { sjf_vec3_destroy(&sjv_intersection); }
;
#line 75
                sjs_vec3* copyoption19 = &sjt_value10;
                if (copyoption19 != 0) {
                    sjv_intersection._refCount = 1;
#line 75 "lib/ui/vertexBuffer.sj"
                    sjf_vec3_copy(&sjv_intersection, copyoption19);
                } else {
                    sjv_intersection._refCount = -1;
                }

#line 80
                sjv_dtu1 = (&(&sjv_vertex1)->texture)->x - (&(&sjv_vertex0)->texture)->x;
#line 81
                sjv_dtu2 = (&(&sjv_vertex2)->texture)->x - (&(&sjv_vertex0)->texture)->x;
#line 82
                sjv_dtv1 = (&(&sjv_vertex1)->texture)->y - (&(&sjv_vertex0)->texture)->y;
#line 83
                sjv_dtv2 = (&(&sjv_vertex2)->texture)->y - (&(&sjv_vertex0)->texture)->y;
#line 83
                sjt_value11._refCount = 1;
#line 85
                sjt_value11.x = ((&(&sjv_vertex0)->texture)->x + (ifValue6->x * sjv_dtu1)) + (ifValue6->y * sjv_dtu2);
#line 86
                sjt_value11.y = ((&(&sjv_vertex0)->texture)->y + (ifValue6->x * sjv_dtv1)) + (ifValue6->y * sjv_dtv2);
#line 86
                sjf_vec2(&sjt_value11);
#line 86
                if (sjv_texture._refCount == 1) { sjf_vec2_destroy(&sjv_texture); }
;
#line 84
                sjs_vec2* copyoption20 = &sjt_value11;
                if (copyoption20 != 0) {
                    sjv_texture._refCount = 1;
#line 84 "lib/ui/vertexBuffer.sj"
                    sjf_vec2_copy(&sjv_texture, copyoption20);
                } else {
                    sjv_texture._refCount = -1;
                }
            }

            if (sjt_value10._refCount == 1) { sjf_vec3_destroy(&sjt_value10); }
;
            if (sjt_value11._refCount == 1) { sjf_vec2_destroy(&sjt_value11); }
;
        }

#line 66
        i++;

        if (sjv_result._refCount == 1) { sjf_vec3_destroy(&sjv_result); }
;
        if (sjv_vertex0._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex0); }
;
        if (sjv_vertex1._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex1); }
;
        if (sjv_vertex2._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex2); }
;
    }

#line 43
    sjs_vec2* copyoption21 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
    if (copyoption21 != 0) {
        (*_return) = 0;
#line 43 "lib/ui/vertexBuffer.sj"
        sjf_vec2_copy((*_return), copyoption21);
    } else {
        (*_return) = 0;
    }

    if (sjt_call29._refCount == 1) { sjf_mat4_destroy(&sjt_call29); }
;
    if (sjv_all._refCount == 1) { sjf_mat4_destroy(&sjv_all); }
;
    if (sjv_allinverse._refCount == 1) { sjf_mat4_destroy(&sjv_allinverse); }
;
    if (sjv_intersection._refCount == 1) { sjf_vec3_destroy(&sjv_intersection); }
;
    if (sjv_start._refCount == 1) { sjf_vec2_destroy(&sjv_start); }
;
    if (sjv_texture._refCount == 1) { sjf_vec2_destroy(&sjv_texture); }
;
    if (sjv_vflatteneddir._refCount == 1) { sjf_vec3_destroy(&sjv_vflatteneddir); }
;
    if (sjv_vflattenedorigin1._refCount == 1) { sjf_vec3_destroy(&sjv_vflattenedorigin1); }
;
    if (sjv_vflattenedorigin2._refCount == 1) { sjf_vec3_destroy(&sjv_vflattenedorigin2); }
;
    if (sjv_vpickraydir._refCount == 1) { sjf_vec3_destroy(&sjv_vpickraydir); }
;
    if (sjv_vpickrayorig._refCount == 1) { sjf_vec3_destroy(&sjv_vpickrayorig); }
;
    if (sjv_vprojectedorigin1._refCount == 1) { sjf_vec4_destroy(&sjv_vprojectedorigin1); }
;
    if (sjv_vprojectedorigin2._refCount == 1) { sjf_vec4_destroy(&sjv_vprojectedorigin2); }
;
    if (sjv_vscreenorigin1._refCount == 1) { sjf_vec4_destroy(&sjv_vscreenorigin1); }
;
    if (sjv_vscreenorigin2._refCount == 1) { sjf_vec4_destroy(&sjv_vscreenorigin2); }
;
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
    sjs_crosshairselement_element_vtbl.destroy = (void(*)(void*))sjf_crosshairselement_destroy;
    sjs_crosshairselement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_crosshairselement_asinterface;
    sjs_crosshairselement_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_crosshairselement_getclasstype;
    sjs_crosshairselement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_crosshairselement_getsize;
    sjs_crosshairselement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_crosshairselement_getsize_heap;
    sjs_crosshairselement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_crosshairselement_getrect;
    sjs_crosshairselement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_crosshairselement_getrect_heap;
    sjs_crosshairselement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_crosshairselement_setrect;
    sjs_crosshairselement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_crosshairselement_render;
    sjs_crosshairselement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_crosshairselement_firemouseevent;
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
    sjs_imageelement_element_vtbl.destroy = (void(*)(void*))sjf_imageelement_destroy;
    sjs_imageelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_imageelement_asinterface;
    sjs_imageelement_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_imageelement_getclasstype;
    sjs_imageelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_imageelement_getsize;
    sjs_imageelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_imageelement_getsize_heap;
    sjs_imageelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_imageelement_getrect;
    sjs_imageelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_imageelement_getrect_heap;
    sjs_imageelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_imageelement_setrect;
    sjs_imageelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_imageelement_render;
    sjs_imageelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_imageelement_firemouseevent;
    sjs_scene2dmodel_model_vtbl.destroy = (void(*)(void*))sjf_scene2dmodel_destroy;
    sjs_scene2dmodel_model_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_scene2dmodel_asinterface;
    sjs_scene2dmodel_model_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_scene2dmodel_getclasstype;
    sjs_scene2dmodel_model_vtbl.update = (void(*)(sjs_object*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_scene2dmodel_update;
    sjs_scene2dmodel_model_vtbl.getz = (void(*)(sjs_object*, float*))sjf_scene2dmodel_getz;
    sjs_scene2dmodel_model_vtbl.getcenter = (void(*)(sjs_object*, sjs_vec3*))sjf_scene2dmodel_getcenter;
    sjs_scene2dmodel_model_vtbl.getcenter_heap = (void(*)(sjs_object*, sjs_vec3**))sjf_scene2dmodel_getcenter_heap;
    sjs_scene2dmodel_model_vtbl.getworld = (void(*)(sjs_object*, sjs_mat4*))sjf_scene2dmodel_getworld;
    sjs_scene2dmodel_model_vtbl.getworld_heap = (void(*)(sjs_object*, sjs_mat4**))sjf_scene2dmodel_getworld_heap;
    sjs_scene2dmodel_model_vtbl.renderorqueue = (void(*)(sjs_object*,sjs_list_heap_iface_model*))sjf_scene2dmodel_renderorqueue;
    sjs_scene2dmodel_model_vtbl.render = (void(*)(sjs_object*))sjf_scene2dmodel_render;
    sjs_scene2dmodel_model_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_scene2dmodel_firemouseevent;
    sjs_scene3delement_element_vtbl.destroy = (void(*)(void*))sjf_scene3delement_destroy;
    sjs_scene3delement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_scene3delement_asinterface;
    sjs_scene3delement_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_scene3delement_getclasstype;
    sjs_scene3delement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_scene3delement_getsize;
    sjs_scene3delement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_scene3delement_getsize_heap;
    sjs_scene3delement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_scene3delement_getrect;
    sjs_scene3delement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_scene3delement_getrect_heap;
    sjs_scene3delement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_scene3delement_setrect;
    sjs_scene3delement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_scene3delement_render;
    sjs_scene3delement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_scene3delement_firemouseevent;
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
    sjt_call3 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
#line 14
    sjt_call3->_refCount = 1;
#line 14
    sjt_call3->children._refCount = 1;
#line 4 "timer.sj"
    sjt_call3->children.datasize = 2;
#line 3 "lib/common/array.sj"
    sjt_call3->children.data = 0;
#line 4
    sjt_call3->children.isglobal = false;
#line 5
    sjt_call3->children.count = 0;
#line 5
    sjf_array_heap_iface_element(&sjt_call3->children);
#line 4 "timer.sj"
    sjs_array_heap_iface_element* array3;
#line 4
    array3 = &sjt_call3->children;
#line 4
    sjt_parent24 = array3;
#line 4
    sjt_functionParam27 = 0;
#line 4
    sjt_call6 = (sjs_scene3delement*)malloc(sizeof(sjs_scene3delement));
#line 4
    sjt_call6->_refCount = 1;
#line 4
    sjt_call6->children._refCount = 1;
#line 6
    sjt_call6->children.datasize = 1;
#line 3 "lib/common/array.sj"
    sjt_call6->children.data = 0;
#line 4
    sjt_call6->children.isglobal = false;
#line 5
    sjt_call6->children.count = 0;
#line 5
    sjf_array_heap_iface_model(&sjt_call6->children);
#line 6 "timer.sj"
    sjs_array_heap_iface_model* array2;
#line 6
    array2 = &sjt_call6->children;
#line 6
    sjt_parent72 = array2;
#line 6
    sjt_functionParam106 = 0;
#line 6
    sjt_call11 = (sjs_scene2dmodel*)malloc(sizeof(sjs_scene2dmodel));
#line 6
    sjt_call11->_refCount = 1;
#line 3 "lib/ui/scene2dModel.sj"
    sjt_call11->id._refCount = -1;
#line 103 "lib/ui/vertexBufferBuilders.sj"
    sjt_functionParam410 = 20;
#line 104
    sjt_functionParam411 = 40;
#line 104
    sjt_call108._refCount = 1;
#line 105
    sjt_call108.x = 0.0f;
#line 105
    sjt_call108.y = 0.0f;
#line 105
    sjt_call108.z = 0.0f;
#line 105
    sjf_vec3(&sjt_call108);
#line 105
    sjt_functionParam412 = &sjt_call108;
#line 105
    sjt_call109._refCount = 1;
#line 106
    sjt_call109.x = 1.0f;
#line 106
    sjt_call109.y = 1.0f;
#line 106
    sjt_call109.z = 1.0f;
#line 106
    sjf_vec3(&sjt_call109);
#line 106
    sjt_functionParam413 = &sjt_call109;
#line 106
    sjf_spherevertexbuffer(sjt_functionParam410, sjt_functionParam411, sjt_functionParam412, sjt_functionParam413, &sjt_call11->vertexbuffer);
#line 106
    sjt_call11->shader._refCount = 1;
#line 7 "timer.sj"
    sjf_shader_copy(&sjt_call11->shader, &sjv_phongtextureshader);
#line 7
    sjt_call11->texturesize._refCount = 1;
#line 6 "lib/ui/scene2dModel.sj"
    sjt_call11->texturesize.w = 512;
#line 6
    sjt_call11->texturesize.h = 512;
#line 6
    sjf_size(&sjt_call11->texturesize);
#line 6
    sjt_call11->children._refCount = 1;
#line 10 "timer.sj"
    sjt_call11->children.datasize = 2;
#line 3 "lib/common/array.sj"
    sjt_call11->children.data = 0;
#line 4
    sjt_call11->children.isglobal = false;
#line 5
    sjt_call11->children.count = 0;
#line 5
    sjf_array_heap_iface_element(&sjt_call11->children);
#line 10 "timer.sj"
    sjs_array_heap_iface_element* array1;
#line 10
    array1 = &sjt_call11->children;
#line 10
    sjt_parent240 = array1;
#line 10
    sjt_functionParam414 = 0;
#line 10
    sjt_call110 = (sjs_imageelement*)malloc(sizeof(sjs_imageelement));
#line 10
    sjt_call110->_refCount = 1;
#line 10
    sjt_call110->image._refCount = 1;
#line 10
    sjt_call118._refCount = 1;
#line 12
    sjt_call118.count = 15;
#line 12
    sjt_call118.data._refCount = 1;
#line 12
    sjt_call118.data.datasize = 15;
#line 12
    sjt_call118.data.data = (void*)sjg_string45;
#line 12
    sjt_call118.data.isglobal = true;
#line 12
    sjt_call118.data.count = 15;
#line 12
    sjf_array_char(&sjt_call118.data);
#line 14 "lib/common/string.sj"
    sjt_call118._isnullterminated = false;
#line 14
    sjf_string(&sjt_call118);
#line 12 "timer.sj"
    sjt_functionParam441 = &sjt_call118;
#line 12
    sjf_texture_frompng(sjt_functionParam441, &sjt_call110->image.texture);
#line 12
    sjt_call110->image.rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_call110->image.rect.x = 0;
#line 3
    sjt_call110->image.rect.y = 0;
#line 4
    sjt_call110->image.rect.w = 0;
#line 5
    sjt_call110->image.rect.h = 0;
#line 5
    sjf_rect(&sjt_call110->image.rect);
#line 5
    sjt_call110->image.margin._refCount = 1;
#line 12 "timer.sj"
    sjt_call110->image.margin.l = 150;
#line 12
    sjt_call110->image.margin.t = 50;
#line 12
    sjt_call110->image.margin.r = 150;
#line 12
    sjt_call110->image.margin.b = 150;
#line 12
    sjf_margin(&sjt_call110->image.margin);
#line 12
    sjf_image(&sjt_call110->image);
#line 12
    sjt_call110->margin._refCount = 1;
#line 2 "lib/ui/margin.sj"
    sjt_call110->margin.l = 0;
#line 3
    sjt_call110->margin.t = 0;
#line 4
    sjt_call110->margin.r = 0;
#line 5
    sjt_call110->margin.b = 0;
#line 5
    sjf_margin(&sjt_call110->margin);
#line 7 "lib/ui/imageElement.sj"
    sjt_call110->stretch = sjv_imagestretch_fill;
#line 7
    sjt_call110->_rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_call110->_rect.x = 0;
#line 3
    sjt_call110->_rect.y = 0;
#line 4
    sjt_call110->_rect.w = 0;
#line 5
    sjt_call110->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call110->_rect);
#line 12 "lib/ui/imageElement.sj"
    sjt_call110->_imagerenderer._refCount = -1;
#line 12
    sjf_imageelement_heap(sjt_call110);
#line 11 "timer.sj"
    sjt_cast39 = sjt_call110;
#line 1 "lib/ui/element.sj"
    sjf_imageelement_as_sji_element(sjt_cast39, &sjt_functionParam415);
    if (sjt_functionParam415._parent != 0) {
        sjt_functionParam415._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent240, sjt_functionParam414, sjt_functionParam415);
#line 10 "timer.sj"
    sjt_parent250 = array1;
#line 10
    sjt_functionParam442 = 1;
#line 10
    sjt_call119 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
#line 10
    sjt_call119->_refCount = 1;
#line 10
    sjt_call119->color._refCount = 1;
#line 14
    sjf_color_copy(&sjt_call119->color, &sjv_colors_blue);
#line 14
    sjt_call119->_rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_call119->_rect.x = 0;
#line 3
    sjt_call119->_rect.y = 0;
#line 4
    sjt_call119->_rect.w = 0;
#line 5
    sjt_call119->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call119->_rect);
#line 4 "lib/ui/crossHairsElement.sj"
    sjt_call119->_topdownrenderer._refCount = -1;
#line 5
    sjt_call119->_leftrightrenderer._refCount = -1;
#line 5
    sjt_call119->_point._refCount = 1;
#line 2 "lib/ui/point.sj"
    sjt_call119->_point.x = 0;
#line 3
    sjt_call119->_point.y = 0;
#line 3
    sjf_point(&sjt_call119->_point);
#line 3
    sjf_crosshairselement_heap(sjt_call119);
#line 14 "timer.sj"
    sjt_cast48 = sjt_call119;
#line 1 "lib/ui/element.sj"
    sjf_crosshairselement_as_sji_element(sjt_cast48, &sjt_functionParam443);
    if (sjt_functionParam443._parent != 0) {
        sjt_functionParam443._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent250, sjt_functionParam442, sjt_functionParam443);
#line 8 "lib/ui/scene2dModel.sj"
    sjt_call11->hasalpha = false;
#line 8
    sjt_call11->center._refCount = 1;
#line 2 "lib/ui/vec3.sj"
    sjt_call11->center.x = 0.0f;
#line 3
    sjt_call11->center.y = 0.0f;
#line 4
    sjt_call11->center.z = 0.0f;
#line 4
    sjf_vec3(&sjt_call11->center);
#line 4
    sjf_mat4_identity(&sjt_call11->model);
#line 4
    sjt_call11->_innerscene._refCount = 1;
#line 4
    sjt_call11->_innerscene._size._refCount = 1;
#line 2 "lib/ui/size.sj"
    sjt_call11->_innerscene._size.w = 0;
#line 3
    sjt_call11->_innerscene._size.h = 0;
#line 3
    sjf_size(&sjt_call11->_innerscene._size);
#line 3
    sjt_call11->_innerscene.model._refCount = 1;
#line 2 "lib/ui/mat4.sj"
    sjt_call11->_innerscene.model.m00 = 0.0f;
#line 3
    sjt_call11->_innerscene.model.m01 = 0.0f;
#line 4
    sjt_call11->_innerscene.model.m02 = 0.0f;
#line 5
    sjt_call11->_innerscene.model.m03 = 0.0f;
#line 6
    sjt_call11->_innerscene.model.m10 = 0.0f;
#line 7
    sjt_call11->_innerscene.model.m11 = 0.0f;
#line 8
    sjt_call11->_innerscene.model.m12 = 0.0f;
#line 9
    sjt_call11->_innerscene.model.m13 = 0.0f;
#line 10
    sjt_call11->_innerscene.model.m20 = 0.0f;
#line 11
    sjt_call11->_innerscene.model.m21 = 0.0f;
#line 12
    sjt_call11->_innerscene.model.m22 = 0.0f;
#line 13
    sjt_call11->_innerscene.model.m23 = 0.0f;
#line 14
    sjt_call11->_innerscene.model.m30 = 0.0f;
#line 15
    sjt_call11->_innerscene.model.m31 = 0.0f;
#line 16
    sjt_call11->_innerscene.model.m32 = 0.0f;
#line 17
    sjt_call11->_innerscene.model.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call11->_innerscene.model);
#line 17
    sjt_call11->_innerscene.view._refCount = 1;
#line 2
    sjt_call11->_innerscene.view.m00 = 0.0f;
#line 3
    sjt_call11->_innerscene.view.m01 = 0.0f;
#line 4
    sjt_call11->_innerscene.view.m02 = 0.0f;
#line 5
    sjt_call11->_innerscene.view.m03 = 0.0f;
#line 6
    sjt_call11->_innerscene.view.m10 = 0.0f;
#line 7
    sjt_call11->_innerscene.view.m11 = 0.0f;
#line 8
    sjt_call11->_innerscene.view.m12 = 0.0f;
#line 9
    sjt_call11->_innerscene.view.m13 = 0.0f;
#line 10
    sjt_call11->_innerscene.view.m20 = 0.0f;
#line 11
    sjt_call11->_innerscene.view.m21 = 0.0f;
#line 12
    sjt_call11->_innerscene.view.m22 = 0.0f;
#line 13
    sjt_call11->_innerscene.view.m23 = 0.0f;
#line 14
    sjt_call11->_innerscene.view.m30 = 0.0f;
#line 15
    sjt_call11->_innerscene.view.m31 = 0.0f;
#line 16
    sjt_call11->_innerscene.view.m32 = 0.0f;
#line 17
    sjt_call11->_innerscene.view.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call11->_innerscene.view);
#line 17
    sjt_call11->_innerscene.projection._refCount = 1;
#line 2
    sjt_call11->_innerscene.projection.m00 = 0.0f;
#line 3
    sjt_call11->_innerscene.projection.m01 = 0.0f;
#line 4
    sjt_call11->_innerscene.projection.m02 = 0.0f;
#line 5
    sjt_call11->_innerscene.projection.m03 = 0.0f;
#line 6
    sjt_call11->_innerscene.projection.m10 = 0.0f;
#line 7
    sjt_call11->_innerscene.projection.m11 = 0.0f;
#line 8
    sjt_call11->_innerscene.projection.m12 = 0.0f;
#line 9
    sjt_call11->_innerscene.projection.m13 = 0.0f;
#line 10
    sjt_call11->_innerscene.projection.m20 = 0.0f;
#line 11
    sjt_call11->_innerscene.projection.m21 = 0.0f;
#line 12
    sjt_call11->_innerscene.projection.m22 = 0.0f;
#line 13
    sjt_call11->_innerscene.projection.m23 = 0.0f;
#line 14
    sjt_call11->_innerscene.projection.m30 = 0.0f;
#line 15
    sjt_call11->_innerscene.projection.m31 = 0.0f;
#line 16
    sjt_call11->_innerscene.projection.m32 = 0.0f;
#line 17
    sjt_call11->_innerscene.projection.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call11->_innerscene.projection);
#line 17
    sjt_call11->_innerscene.windowrect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_call11->_innerscene.windowrect.x = 0;
#line 3
    sjt_call11->_innerscene.windowrect.y = 0;
#line 4
    sjt_call11->_innerscene.windowrect.w = 0;
#line 5
    sjt_call11->_innerscene.windowrect.h = 0;
#line 5
    sjf_rect(&sjt_call11->_innerscene.windowrect);
#line 5
    sjf_scene2d(&sjt_call11->_innerscene);
#line 5
    sjt_call11->_scenerect._refCount = 1;
#line 2
    sjt_call11->_scenerect.x = 0;
#line 3
    sjt_call11->_scenerect.y = 0;
#line 4
    sjt_call11->_scenerect.w = 0;
#line 5
    sjt_call11->_scenerect.h = 0;
#line 5
    sjf_rect(&sjt_call11->_scenerect);
#line 5
    sjt_call11->_projection._refCount = 1;
#line 2 "lib/ui/mat4.sj"
    sjt_call11->_projection.m00 = 0.0f;
#line 3
    sjt_call11->_projection.m01 = 0.0f;
#line 4
    sjt_call11->_projection.m02 = 0.0f;
#line 5
    sjt_call11->_projection.m03 = 0.0f;
#line 6
    sjt_call11->_projection.m10 = 0.0f;
#line 7
    sjt_call11->_projection.m11 = 0.0f;
#line 8
    sjt_call11->_projection.m12 = 0.0f;
#line 9
    sjt_call11->_projection.m13 = 0.0f;
#line 10
    sjt_call11->_projection.m20 = 0.0f;
#line 11
    sjt_call11->_projection.m21 = 0.0f;
#line 12
    sjt_call11->_projection.m22 = 0.0f;
#line 13
    sjt_call11->_projection.m23 = 0.0f;
#line 14
    sjt_call11->_projection.m30 = 0.0f;
#line 15
    sjt_call11->_projection.m31 = 0.0f;
#line 16
    sjt_call11->_projection.m32 = 0.0f;
#line 17
    sjt_call11->_projection.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call11->_projection);
#line 17
    sjt_call11->_world._refCount = 1;
#line 2
    sjt_call11->_world.m00 = 0.0f;
#line 3
    sjt_call11->_world.m01 = 0.0f;
#line 4
    sjt_call11->_world.m02 = 0.0f;
#line 5
    sjt_call11->_world.m03 = 0.0f;
#line 6
    sjt_call11->_world.m10 = 0.0f;
#line 7
    sjt_call11->_world.m11 = 0.0f;
#line 8
    sjt_call11->_world.m12 = 0.0f;
#line 9
    sjt_call11->_world.m13 = 0.0f;
#line 10
    sjt_call11->_world.m20 = 0.0f;
#line 11
    sjt_call11->_world.m21 = 0.0f;
#line 12
    sjt_call11->_world.m22 = 0.0f;
#line 13
    sjt_call11->_world.m23 = 0.0f;
#line 14
    sjt_call11->_world.m30 = 0.0f;
#line 15
    sjt_call11->_world.m31 = 0.0f;
#line 16
    sjt_call11->_world.m32 = 0.0f;
#line 17
    sjt_call11->_world.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call11->_world);
#line 17
    sjt_call11->_view._refCount = 1;
#line 2
    sjt_call11->_view.m00 = 0.0f;
#line 3
    sjt_call11->_view.m01 = 0.0f;
#line 4
    sjt_call11->_view.m02 = 0.0f;
#line 5
    sjt_call11->_view.m03 = 0.0f;
#line 6
    sjt_call11->_view.m10 = 0.0f;
#line 7
    sjt_call11->_view.m11 = 0.0f;
#line 8
    sjt_call11->_view.m12 = 0.0f;
#line 9
    sjt_call11->_view.m13 = 0.0f;
#line 10
    sjt_call11->_view.m20 = 0.0f;
#line 11
    sjt_call11->_view.m21 = 0.0f;
#line 12
    sjt_call11->_view.m22 = 0.0f;
#line 13
    sjt_call11->_view.m23 = 0.0f;
#line 14
    sjt_call11->_view.m30 = 0.0f;
#line 15
    sjt_call11->_view.m31 = 0.0f;
#line 16
    sjt_call11->_view.m32 = 0.0f;
#line 17
    sjt_call11->_view.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call11->_view);
#line 17
    sjt_call11->_light._refCount = 1;
#line 17
    sjt_call11->_light.pos._refCount = 1;
#line 2 "lib/ui/scene3dElement.sj"
    sjt_call11->_light.pos.x = 1.0f;
#line 2
    sjt_call11->_light.pos.y = 1.0f;
#line 2
    sjt_call11->_light.pos.z = 1.0f;
#line 2
    sjf_vec3(&sjt_call11->_light.pos);
#line 2
    sjt_call11->_light.diffusecolor._refCount = 1;
#line 3
    sjt_call11->_light.diffusecolor.r = 0.5f;
#line 3
    sjt_call11->_light.diffusecolor.g = 0.5f;
#line 3
    sjt_call11->_light.diffusecolor.b = 0.0f;
#line 3
    sjt_call11->_light.diffusecolor.a = 1.0f;
#line 3
    sjf_color(&sjt_call11->_light.diffusecolor);
#line 3
    sjt_call11->_light.speccolor._refCount = 1;
#line 4
    sjt_call11->_light.speccolor.r = 1.0f;
#line 4
    sjt_call11->_light.speccolor.g = 1.0f;
#line 4
    sjt_call11->_light.speccolor.b = 1.0f;
#line 4
    sjt_call11->_light.speccolor.a = 1.0f;
#line 4
    sjf_color(&sjt_call11->_light.speccolor);
#line 4
    sjf_light(&sjt_call11->_light);
#line 4
    sjt_call11->_projectedcenter._refCount = 1;
#line 2 "lib/ui/vec4.sj"
    sjt_call11->_projectedcenter.x = 0.0f;
#line 3
    sjt_call11->_projectedcenter.y = 0.0f;
#line 4
    sjt_call11->_projectedcenter.z = 0.0f;
#line 5
    sjt_call11->_projectedcenter.w = 0.0f;
#line 5
    sjf_vec4(&sjt_call11->_projectedcenter);
#line 5
    sjt_call11->_framebuffer._refCount = 1;
#line 5
    sjt_call11->_framebuffer.size._refCount = 1;
#line 2 "lib/ui/size.sj"
    sjt_call11->_framebuffer.size.w = 0;
#line 3
    sjt_call11->_framebuffer.size.h = 0;
#line 3
    sjf_size(&sjt_call11->_framebuffer.size);
#line 3 "lib/ui/framebuffer.sj"
    sjt_call11->_framebuffer.id = (uint32_t)0u;
#line 3
    sjf_framebuffer(&sjt_call11->_framebuffer);
#line 3
    sjt_call11->_texture._refCount = 1;
#line 3
    sjt_call11->_texture.size._refCount = 1;
#line 2 "lib/ui/size.sj"
    sjt_call11->_texture.size.w = 0;
#line 3
    sjt_call11->_texture.size.h = 0;
#line 3
    sjf_size(&sjt_call11->_texture.size);
#line 3 "lib/ui/texture.sj"
    sjt_call11->_texture.id = (uint32_t)0u;
#line 3
    sjf_texture(&sjt_call11->_texture);
#line 3
    sjt_call11->_renderbuffer._refCount = 1;
#line 3
    sjt_call11->_renderbuffer.size._refCount = 1;
#line 2 "lib/ui/size.sj"
    sjt_call11->_renderbuffer.size.w = 0;
#line 3
    sjt_call11->_renderbuffer.size.h = 0;
#line 3
    sjf_size(&sjt_call11->_renderbuffer.size);
#line 3 "lib/ui/renderbuffer.sj"
    sjt_call11->_renderbuffer.id = (uint32_t)0u;
#line 3
    sjf_renderbuffer(&sjt_call11->_renderbuffer);
#line 3
    sjf_scene2dmodel_heap(sjt_call11);
#line 7 "timer.sj"
    sjt_cast6 = sjt_call11;
#line 1 "lib/ui/model.sj"
    sjf_scene2dmodel_as_sji_model(sjt_cast6, &sjt_functionParam107);
    if (sjt_functionParam107._parent != 0) {
        sjt_functionParam107._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_model_initat(sjt_parent72, sjt_functionParam106, sjt_functionParam107);
#line 1
    sjt_call6->camera._refCount = 1;
#line 13 "lib/ui/scene3dElement.sj"
    sjt_call6->camera.x = 0.0f;
#line 13
    sjt_call6->camera.y = 0.0f;
#line 13
    result14 = -5.0f;
#line 13
    sjt_call6->camera.z = result14;
#line 13
    sjf_vec3(&sjt_call6->camera);
#line 13
    sjt_call6->lookat._refCount = 1;
#line 14
    sjt_call6->lookat.x = 0.0f;
#line 14
    sjt_call6->lookat.y = 0.0f;
#line 14
    sjt_call6->lookat.z = 0.0f;
#line 14
    sjf_vec3(&sjt_call6->lookat);
#line 14
    sjt_call6->up._refCount = 1;
#line 15
    sjt_call6->up.x = 0.0f;
#line 15
    sjt_call6->up.y = 1.0f;
#line 15
    sjt_call6->up.z = 0.0f;
#line 15
    sjf_vec3(&sjt_call6->up);
#line 16
    sjt_call6->fieldofview = 90.0f;
#line 17
    sjt_call6->znear = 1.0f;
#line 18
    sjt_call6->zfar = 100.0f;
#line 18
    sjt_call6->light._refCount = 1;
#line 18
    sjt_call6->light.pos._refCount = 1;
#line 2
    sjt_call6->light.pos.x = 1.0f;
#line 2
    sjt_call6->light.pos.y = 1.0f;
#line 2
    sjt_call6->light.pos.z = 1.0f;
#line 2
    sjf_vec3(&sjt_call6->light.pos);
#line 2
    sjt_call6->light.diffusecolor._refCount = 1;
#line 3
    sjt_call6->light.diffusecolor.r = 0.5f;
#line 3
    sjt_call6->light.diffusecolor.g = 0.5f;
#line 3
    sjt_call6->light.diffusecolor.b = 0.0f;
#line 3
    sjt_call6->light.diffusecolor.a = 1.0f;
#line 3
    sjf_color(&sjt_call6->light.diffusecolor);
#line 3
    sjt_call6->light.speccolor._refCount = 1;
#line 4
    sjt_call6->light.speccolor.r = 1.0f;
#line 4
    sjt_call6->light.speccolor.g = 1.0f;
#line 4
    sjt_call6->light.speccolor.b = 1.0f;
#line 4
    sjt_call6->light.speccolor.a = 1.0f;
#line 4
    sjf_color(&sjt_call6->light.speccolor);
#line 4
    sjf_light(&sjt_call6->light);
#line 4
    sjt_call6->projection._refCount = 1;
#line 2 "lib/ui/mat4.sj"
    sjt_call6->projection.m00 = 0.0f;
#line 3
    sjt_call6->projection.m01 = 0.0f;
#line 4
    sjt_call6->projection.m02 = 0.0f;
#line 5
    sjt_call6->projection.m03 = 0.0f;
#line 6
    sjt_call6->projection.m10 = 0.0f;
#line 7
    sjt_call6->projection.m11 = 0.0f;
#line 8
    sjt_call6->projection.m12 = 0.0f;
#line 9
    sjt_call6->projection.m13 = 0.0f;
#line 10
    sjt_call6->projection.m20 = 0.0f;
#line 11
    sjt_call6->projection.m21 = 0.0f;
#line 12
    sjt_call6->projection.m22 = 0.0f;
#line 13
    sjt_call6->projection.m23 = 0.0f;
#line 14
    sjt_call6->projection.m30 = 0.0f;
#line 15
    sjt_call6->projection.m31 = 0.0f;
#line 16
    sjt_call6->projection.m32 = 0.0f;
#line 17
    sjt_call6->projection.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call6->projection);
#line 17
    sjt_call6->view._refCount = 1;
#line 2
    sjt_call6->view.m00 = 0.0f;
#line 3
    sjt_call6->view.m01 = 0.0f;
#line 4
    sjt_call6->view.m02 = 0.0f;
#line 5
    sjt_call6->view.m03 = 0.0f;
#line 6
    sjt_call6->view.m10 = 0.0f;
#line 7
    sjt_call6->view.m11 = 0.0f;
#line 8
    sjt_call6->view.m12 = 0.0f;
#line 9
    sjt_call6->view.m13 = 0.0f;
#line 10
    sjt_call6->view.m20 = 0.0f;
#line 11
    sjt_call6->view.m21 = 0.0f;
#line 12
    sjt_call6->view.m22 = 0.0f;
#line 13
    sjt_call6->view.m23 = 0.0f;
#line 14
    sjt_call6->view.m30 = 0.0f;
#line 15
    sjt_call6->view.m31 = 0.0f;
#line 16
    sjt_call6->view.m32 = 0.0f;
#line 17
    sjt_call6->view.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call6->view);
#line 17
    sjf_mat4_identity(&sjt_call6->world);
#line 17
    sjt_call6->_rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_call6->_rect.x = 0;
#line 3
    sjt_call6->_rect.y = 0;
#line 4
    sjt_call6->_rect.w = 0;
#line 5
    sjt_call6->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call6->_rect);
#line 5
    sjf_scene3delement_heap(sjt_call6);
#line 5 "timer.sj"
    sjt_cast3 = sjt_call6;
#line 1 "lib/ui/element.sj"
    sjf_scene3delement_as_sji_element(sjt_cast3, &sjt_functionParam28);
    if (sjt_functionParam28._parent != 0) {
        sjt_functionParam28._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent24, sjt_functionParam27, sjt_functionParam28);
#line 4 "timer.sj"
    sjt_parent255 = array3;
#line 4
    sjt_functionParam448 = 1;
#line 4
    sjt_call120 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
#line 4
    sjt_call120->_refCount = 1;
#line 4
    sjt_call120->color._refCount = 1;
#line 21
    sjf_color_copy(&sjt_call120->color, &sjv_colors_red);
#line 21
    sjt_call120->_rect._refCount = 1;
#line 2 "lib/ui/rect.sj"
    sjt_call120->_rect.x = 0;
#line 3
    sjt_call120->_rect.y = 0;
#line 4
    sjt_call120->_rect.w = 0;
#line 5
    sjt_call120->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call120->_rect);
#line 4 "lib/ui/crossHairsElement.sj"
    sjt_call120->_topdownrenderer._refCount = -1;
#line 5
    sjt_call120->_leftrightrenderer._refCount = -1;
#line 5
    sjt_call120->_point._refCount = 1;
#line 2 "lib/ui/point.sj"
    sjt_call120->_point.x = 0;
#line 3
    sjt_call120->_point.y = 0;
#line 3
    sjf_point(&sjt_call120->_point);
#line 3
    sjf_crosshairselement_heap(sjt_call120);
#line 21 "timer.sj"
    sjt_cast49 = sjt_call120;
#line 1 "lib/ui/element.sj"
    sjf_crosshairselement_as_sji_element(sjt_cast49, &sjt_functionParam449);
    if (sjt_functionParam449._parent != 0) {
        sjt_functionParam449._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent255, sjt_functionParam448, sjt_functionParam449);
#line 1
    sjt_call3->margin._refCount = 1;
#line 2 "lib/ui/margin.sj"
    sjt_call3->margin.l = 0;
#line 3
    sjt_call3->margin.t = 0;
#line 4
    sjt_call3->margin.r = 0;
#line 5
    sjt_call3->margin.b = 0;
#line 5
    sjf_margin(&sjt_call3->margin);
#line 4 "lib/ui/fillLayout.sj"
    sjt_call3->effect._parent = 0;
#line 4
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
    sjf_filllayout_heap(sjt_call3);
#line 3 "timer.sj"
    sjt_cast2 = sjt_call3;
#line 1 "lib/ui/element.sj"
    sjf_filllayout_as_sji_element(sjt_cast2, &sjv_root);
    if (sjv_root._parent != 0) {
        sjv_root._parent->_refCount++;
    }

#line 1
    sjf_runloop();
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_call11->_refCount--;
    if (sjt_call11->_refCount <= 0) {
        weakptr_release(sjt_call11);
        sjf_scene2dmodel_destroy(sjt_call11);
        free(sjt_call11);
    }
    sjt_call110->_refCount--;
    if (sjt_call110->_refCount <= 0) {
        weakptr_release(sjt_call110);
        sjf_imageelement_destroy(sjt_call110);
        free(sjt_call110);
    }
    sjt_call119->_refCount--;
    if (sjt_call119->_refCount <= 0) {
        weakptr_release(sjt_call119);
        sjf_crosshairselement_destroy(sjt_call119);
        free(sjt_call119);
    }
    sjt_call120->_refCount--;
    if (sjt_call120->_refCount <= 0) {
        weakptr_release(sjt_call120);
        sjf_crosshairselement_destroy(sjt_call120);
        free(sjt_call120);
    }
    sjt_call3->_refCount--;
    if (sjt_call3->_refCount <= 0) {
        weakptr_release(sjt_call3);
        sjf_filllayout_destroy(sjt_call3);
        free(sjt_call3);
    }
    sjt_call6->_refCount--;
    if (sjt_call6->_refCount <= 0) {
        weakptr_release(sjt_call6);
        sjf_scene3delement_destroy(sjt_call6);
        free(sjt_call6);
    }
    if (sjt_functionParam107._parent != 0) {
        sjt_functionParam107._parent->_refCount--;
        if (sjt_functionParam107._parent->_refCount <= 0) {
            sjt_functionParam107._vtbl->destroy(sjt_functionParam107._parent);
            free(sjt_functionParam107._parent);
        }
    }
    if (sjt_functionParam28._parent != 0) {
        sjt_functionParam28._parent->_refCount--;
        if (sjt_functionParam28._parent->_refCount <= 0) {
            sjt_functionParam28._vtbl->destroy(sjt_functionParam28._parent);
            free(sjt_functionParam28._parent);
        }
    }
    if (sjt_functionParam415._parent != 0) {
        sjt_functionParam415._parent->_refCount--;
        if (sjt_functionParam415._parent->_refCount <= 0) {
            sjt_functionParam415._vtbl->destroy(sjt_functionParam415._parent);
            free(sjt_functionParam415._parent);
        }
    }
    if (sjt_functionParam443._parent != 0) {
        sjt_functionParam443._parent->_refCount--;
        if (sjt_functionParam443._parent->_refCount <= 0) {
            sjt_functionParam443._vtbl->destroy(sjt_functionParam443._parent);
            free(sjt_functionParam443._parent);
        }
    }
    if (sjt_functionParam449._parent != 0) {
        sjt_functionParam449._parent->_refCount--;
        if (sjt_functionParam449._parent->_refCount <= 0) {
            sjt_functionParam449._vtbl->destroy(sjt_functionParam449._parent);
            free(sjt_functionParam449._parent);
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
    if (sjt_call108._refCount == 1) { sjf_vec3_destroy(&sjt_call108); }
;
    if (sjt_call109._refCount == 1) { sjf_vec3_destroy(&sjt_call109); }
;
    if (sjt_call118._refCount == 1) { sjf_string_destroy(&sjt_call118); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
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
