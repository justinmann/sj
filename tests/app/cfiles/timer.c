#include <lib/sj-lib-common/common.h>
#ifdef WIN32
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
#include <lib/sj-lib-ui/obj_parser.h>
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
struct {
    int refcount;
    int size;
    int count;
    char data[38];
} sjg_string1 = { 1, 38, 37, "assets/sj-lib-ui/shaders/v3f-t2f.vert"};
struct {
    int refcount;
    int size;
    int count;
    char data[48];
} sjg_string10 = { 1, 48, 47, "assets/sj-lib-ui/shaders/v3f-t2f-n3f-phong.vert"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string100 = { 1, 11, 10, "array!rect"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string101 = { 1, 10, 9, "array!u32"};
struct {
    int refcount;
    int size;
    int count;
    char data[37];
} sjg_string102 = { 1, 37, 36, "array!vertex_location_texture_normal"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string103 = { 1, 14, 13, "bool_asstring"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string104 = { 1, 12, 11, "boxrenderer"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string105 = { 1, 7, 6, "render"};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string106 = { 1, 17, 16, "char_touppercase"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string107 = { 1, 6, 5, "color"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string108 = { 1, 7, 6, "asvec3"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string109 = { 1, 18, 17, "crosshairselement"};
struct {
    int refcount;
    int size;
    int count;
    char data[48];
} sjg_string11 = { 1, 48, 47, "assets/sj-lib-ui/shaders/v3f-t2f-n3f-phong.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string110 = { 1, 15, 14, "firemouseevent"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string111 = { 1, 8, 7, "getrect"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string112 = { 1, 8, 7, "getsize"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string113 = { 1, 8, 7, "setrect"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string114 = { 1, 10, 9, "writeline"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string115 = { 1, 13, 12, "f32_asstring"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string116 = { 1, 12, 11, "f32_compare"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string117 = { 1, 8, 7, "f32_cos"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string118 = { 1, 9, 8, "f32_hash"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string119 = { 1, 8, 7, "f32_sin"};
struct {
    int refcount;
    int size;
    int count;
    char data[42];
} sjg_string12 = { 1, 42, 41, "assets/sj-lib-ui/shaders/v3f-t2f-c4f.vert"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string120 = { 1, 9, 8, "f32_sqrt"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string121 = { 1, 8, 7, "f32_tan"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string122 = { 1, 11, 10, "filllayout"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string123 = { 1, 12, 11, "renderinner"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string124 = { 1, 13, 12, "setrectinner"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string125 = { 1, 5, 4, "font"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string126 = { 1, 8, 7, "fontkey"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string127 = { 1, 5, 4, "hash"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string128 = { 1, 8, 7, "isequal"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string129 = { 1, 12, 11, "framebuffer"};
struct {
    int refcount;
    int size;
    int count;
    char data[42];
} sjg_string13 = { 1, 42, 41, "assets/sj-lib-ui/shaders/v3f-t2f-c4f.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[19];
} sjg_string130 = { 1, 19, 18, "glbindrenderbuffer"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string131 = { 1, 14, 13, "glbindtexture"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string132 = { 1, 12, 11, "glblendfunc"};
struct {
    int refcount;
    int size;
    int count;
    char data[25];
} sjg_string133 = { 1, 25, 24, "glcheckframebufferstatus"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string134 = { 1, 13, 12, "glclearcolor"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string135 = { 1, 10, 9, "gldisable"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string136 = { 1, 9, 8, "glenable"};
struct {
    int refcount;
    int size;
    int count;
    char data[26];
} sjg_string137 = { 1, 26, 25, "glframebufferrenderbuffer"};
struct {
    int refcount;
    int size;
    int count;
    char data[23];
} sjg_string138 = { 1, 23, 22, "glframebuffertexture2d"};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string139 = { 1, 17, 16, "glgenframebuffer"};
struct {
    int refcount;
    int size;
    int count;
    char data[33];
} sjg_string14 = { 1, 33, 32, "vertex:3f,tex_coord:2f,normal:3f"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string140 = { 1, 18, 17, "glgenrenderbuffer"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string141 = { 1, 13, 12, "glgentexture"};
struct {
    int refcount;
    int size;
    int count;
    char data[21];
} sjg_string142 = { 1, 21, 20, "glgetuniformlocation"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string143 = { 1, 7, 6, "global"};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string144 = { 1, 17, 16, "glpopframebuffer"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string145 = { 1, 14, 13, "glpopviewport"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string146 = { 1, 18, 17, "glpushframebuffer"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string147 = { 1, 15, 14, "glpushviewport"};
struct {
    int refcount;
    int size;
    int count;
    char data[22];
} sjg_string148 = { 1, 22, 21, "glrenderbufferstorage"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string149 = { 1, 13, 12, "glteximage2d"};
struct {
    int refcount;
    int size;
    int count;
    char data[39];
} sjg_string15 = { 1, 39, 38, "assets/sj-lib-ui/shaders/saturate.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[16];
} sjg_string150 = { 1, 16, 15, "gltexparameteri"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string151 = { 1, 13, 12, "gluniformi32"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string152 = { 1, 14, 13, "gluniformmat4"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string153 = { 1, 14, 13, "gluniformvec3"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string154 = { 1, 13, 12, "gluseprogram"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string155 = { 1, 5, 4, "halt"};
struct {
    int refcount;
    int size;
    int count;
    char data[22];
} sjg_string156 = { 1, 22, 21, "hash![fontkey, font?]"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string157 = { 1, 18, 17, "_weakptrremovekey"};
struct {
    int refcount;
    int size;
    int count;
    char data[20];
} sjg_string158 = { 1, 20, 19, "_weakptrremovevalue"};
struct {
    int refcount;
    int size;
    int count;
    char data[25];
} sjg_string159 = { 1, 25, 24, "hash![string, #element?]"};
struct {
    int refcount;
    int size;
    int count;
    char data[31];
} sjg_string16 = { 1, 31, 30, "viewport being pop'ed is wrong"};
struct {
    int refcount;
    int size;
    int count;
    char data[23];
} sjg_string160 = { 1, 23, 22, "hash![string, #model?]"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string161 = { 1, 18, 17, "hash![type, bool]"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string162 = { 1, 13, 12, "i32_asstring"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string163 = { 1, 8, 7, "i32_max"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string164 = { 1, 6, 5, "image"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string165 = { 1, 13, 12, "imageelement"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string166 = { 1, 14, 13, "imagerenderer"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string167 = { 1, 18, 17, "intersecttriangle"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string168 = { 1, 8, 7, "lambda2"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string169 = { 1, 7, 6, "invoke"};
struct {
    int refcount;
    int size;
    int count;
    char data[34];
} sjg_string17 = { 1, 34, 33, "framebuffer being pop'ed is wrong"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string170 = { 1, 8, 7, "lambda3"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string171 = { 1, 6, 5, "light"};
struct {
    int refcount;
    int size;
    int count;
    char data[16];
} sjg_string172 = { 1, 16, 15, "list!#animation"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string173 = { 1, 9, 8, "removeat"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string174 = { 1, 12, 11, "list!#model"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string175 = { 1, 4, 3, "add"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string176 = { 1, 10, 9, "list!rect"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string177 = { 1, 9, 8, "list!u32"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string178 = { 1, 4, 3, "log"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string179 = { 1, 7, 6, "_write"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string18 = { 1, 10, 9, "viewModel"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string180 = { 1, 18, 17, "loglevel_asstring"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string181 = { 1, 9, 8, "mainloop"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string182 = { 1, 7, 6, "margin"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string183 = { 1, 5, 4, "mat4"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string184 = { 1, 12, 11, "determinant"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string185 = { 1, 14, 13, "mat4_identity"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string186 = { 1, 7, 6, "invert"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string187 = { 1, 14, 13, "mat4_lookatlh"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string188 = { 1, 9, 8, "multiply"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string189 = { 1, 12, 11, "multiplyf32"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string19 = { 1, 10, 9, "normalMat"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string190 = { 1, 13, 12, "multiplyvec4"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string191 = { 1, 18, 17, "mat4_orthographic"};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string192 = { 1, 17, 16, "mat4_perspective"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string193 = { 1, 11, 10, "mat4_scale"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string194 = { 1, 10, 9, "transpose"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string195 = { 1, 12, 11, "model_zsort"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string196 = { 1, 11, 10, "mouseevent"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string197 = { 1, 9, 8, "asstring"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string198 = { 1, 13, 12, "firechildren"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string199 = { 1, 6, 5, "point"};
struct {
    int refcount;
    int size;
    int count;
    char data[46];
} sjg_string2 = { 1, 46, 45, "assets/sj-lib-ui/shaders/blur-horizontal.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string20 = { 1, 11, 10, "projection"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string200 = { 1, 5, 4, "rect"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string201 = { 1, 14, 13, "containspoint"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string202 = { 1, 15, 14, "subtractmargin"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string203 = { 1, 13, 12, "renderbuffer"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string204 = { 1, 8, 7, "runloop"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string205 = { 1, 8, 7, "scene2d"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string206 = { 1, 4, 3, "end"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string207 = { 1, 8, 7, "setsize"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string208 = { 1, 6, 5, "start"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string209 = { 1, 13, 12, "scene2dmodel"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string21 = { 1, 9, 8, "lightPos"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string210 = { 1, 10, 9, "getcenter"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string211 = { 1, 9, 8, "getworld"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string212 = { 1, 5, 4, "getz"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string213 = { 1, 14, 13, "renderorqueue"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string214 = { 1, 7, 6, "update"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string215 = { 1, 15, 14, "scene3delement"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string216 = { 1, 7, 6, "shader"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string217 = { 1, 5, 4, "size"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string218 = { 1, 10, 9, "addmargin"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string219 = { 1, 4, 3, "max"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string22 = { 1, 13, 12, "diffuseColor"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string220 = { 1, 4, 3, "min"};
struct {
    int refcount;
    int size;
    int count;
    char data[19];
} sjg_string221 = { 1, 19, 18, "spherevertexbuffer"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string222 = { 1, 7, 6, "string"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string223 = { 1, 14, 13, "nullterminate"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string224 = { 1, 12, 11, "touppercase"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string225 = { 1, 6, 5, "style"};
struct {
    int refcount;
    int size;
    int count;
    char data[16];
} sjg_string226 = { 1, 16, 15, "texture_frompng"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string227 = { 1, 14, 13, "type_asstring"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string228 = { 1, 10, 9, "type_hash"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string229 = { 1, 13, 12, "type_isequal"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string23 = { 1, 10, 9, "specColor"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string230 = { 1, 5, 4, "vec2"};
struct {
    int refcount;
    int size;
    int count;
    char data[16];
} sjg_string231 = { 1, 16, 15, "vec2_getrawsize"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string232 = { 1, 13, 12, "vec2_rawcopy"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string233 = { 1, 5, 4, "vec3"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string234 = { 1, 6, 5, "cross"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string235 = { 1, 4, 3, "dot"};
struct {
    int refcount;
    int size;
    int count;
    char data[16];
} sjg_string236 = { 1, 16, 15, "vec3_getrawsize"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string237 = { 1, 10, 9, "normalize"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string238 = { 1, 13, 12, "vec3_rawcopy"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string239 = { 1, 9, 8, "subtract"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string24 = { 1, 6, 5, "trace"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string240 = { 1, 5, 4, "vec4"};
struct {
    int refcount;
    int size;
    int count;
    char data[31];
} sjg_string241 = { 1, 31, 30, "vertex_location_texture_normal"};
struct {
    int refcount;
    int size;
    int count;
    char data[42];
} sjg_string242 = { 1, 42, 41, "vertex_location_texture_normal_getrawsize"};
struct {
    int refcount;
    int size;
    int count;
    char data[39];
} sjg_string243 = { 1, 39, 38, "vertex_location_texture_normal_rawcopy"};
struct {
    int refcount;
    int size;
    int count;
    char data[44];
} sjg_string244 = { 1, 44, 43, "vertexbuffer!vertex_location_texture_normal"};
struct {
    int refcount;
    int size;
    int count;
    char data[25];
} sjg_string245 = { 1, 25, 24, "translatescreentotexture"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string246 = { 1, 15, 14, "windowrenderer"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string247 = { 1, 8, 7, "present"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string248 = { 1, 15, 14, "texthorizontal"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string249 = { 1, 13, 12, "textvertical"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string25 = { 1, 6, 5, "debug"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string250 = { 1, 5, 4, "type"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string251 = { 1, 4, 3, "u32"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string252 = { 1, 4, 3, "u64"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string253 = { 1, 5, 4, "void"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string26 = { 1, 5, 4, "info"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string27 = { 1, 5, 4, "warn"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string28 = { 1, 6, 5, "error"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string29 = { 1, 6, 5, "fatal"};
struct {
    int refcount;
    int size;
    int count;
    char data[44];
} sjg_string3 = { 1, 44, 43, "assets/sj-lib-ui/shaders/blur-vertical.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[1];
} sjg_string30 = { 1, 1, 0, ""};
struct {
    int refcount;
    int size;
    int count;
    char data[3];
} sjg_string31 = { 1, 3, 2, " ["};
struct {
    int refcount;
    int size;
    int count;
    char data[3];
} sjg_string32 = { 1, 3, 2, "] "};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string33 = { 1, 9, 8, "point : "};
struct {
    int refcount;
    int size;
    int count;
    char data[3];
} sjg_string34 = { 1, 3, 2, ", "};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string35 = { 1, 15, 14, " isCaptured : "};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string36 = { 1, 6, 5, "false"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string37 = { 1, 5, 4, "true"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string38 = { 1, 15, 14, " isLeftDown : "};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string39 = { 1, 17, 16, " -> does not map"};
struct {
    int refcount;
    int size;
    int count;
    char data[35];
} sjg_string4 = { 1, 35, 34, "assets/sj-lib-ui/shaders/fade.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string40 = { 1, 5, 4, " -> "};
struct {
    int refcount;
    int size;
    int count;
    char data[19];
} sjg_string41 = { 1, 19, 18, "Framebuffer failed"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string42 = { 1, 8, 7, "texture"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string43 = { 1, 6, 5, "model"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string44 = { 1, 5, 4, "view"};
struct {
    int refcount;
    int size;
    int count;
    char data[16];
} sjg_string45 = { 1, 16, 15, "assets/test.png"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string46 = { 1, 6, 5, "FPS: "};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string47 = { 1, 5, 4, "bool"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string48 = { 1, 15, 14, "borderposition"};
struct {
    int refcount;
    int size;
    int count;
    char data[32];
} sjg_string49 = { 1, 32, 31, "(:heap #model, :heap #model)i32"};
struct {
    int refcount;
    int size;
    int count;
    char data[38];
} sjg_string5 = { 1, 38, 37, "assets/sj-lib-ui/shaders/v3f-c4f.vert"};
struct {
    int refcount;
    int size;
    int count;
    char data[34];
} sjg_string50 = { 1, 34, 33, "(:local #model, :local #model)i32"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string51 = { 1, 18, 17, "(:stack rect)void"};
struct {
    int refcount;
    int size;
    int count;
    char data[21];
} sjg_string52 = { 1, 21, 20, "(:stack scene2d)void"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string53 = { 1, 15, 14, "()stack string"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string54 = { 1, 5, 4, "char"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string55 = { 1, 11, 10, "clickstate"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string56 = { 1, 4, 3, "f32"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string57 = { 1, 4, 3, "f64"};
struct {
    int refcount;
    int size;
    int count;
    char data[22];
} sjg_string58 = { 1, 22, 21, "flowlayoutorientation"};
struct {
    int refcount;
    int size;
    int count;
    char data[16];
} sjg_string59 = { 1, 16, 15, "glblendfunctype"};
struct {
    int refcount;
    int size;
    int count;
    char data[38];
} sjg_string6 = { 1, 38, 37, "assets/sj-lib-ui/shaders/v3f-c4f.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string60 = { 1, 11, 10, "gldrawmode"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string61 = { 1, 10, 9, "glfeature"};
struct {
    int refcount;
    int size;
    int count;
    char data[24];
} sjg_string62 = { 1, 24, 23, "glframebufferattachment"};
struct {
    int refcount;
    int size;
    int count;
    char data[20];
} sjg_string63 = { 1, 20, 19, "glframebufferstatus"};
struct {
    int refcount;
    int size;
    int count;
    char data[21];
} sjg_string64 = { 1, 21, 20, "glframebuffertexture"};
struct {
    int refcount;
    int size;
    int count;
    char data[21];
} sjg_string65 = { 1, 21, 20, "glrenderbufferformat"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string66 = { 1, 10, 9, "gltexture"};
struct {
    int refcount;
    int size;
    int count;
    char data[19];
} sjg_string67 = { 1, 19, 18, "gltextureattribute"};
struct {
    int refcount;
    int size;
    int count;
    char data[16];
} sjg_string68 = { 1, 16, 15, "gltextureformat"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string69 = { 1, 14, 13, "gltexturetype"};
struct {
    int refcount;
    int size;
    int count;
    char data[38];
} sjg_string7 = { 1, 38, 37, "assets/sj-lib-ui/shaders/v3f-t2f.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string70 = { 1, 15, 14, "gltexturevalue"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string71 = { 1, 13, 12, "gridunittype"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string72 = { 1, 4, 3, "i32"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string73 = { 1, 4, 3, "i64"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string74 = { 1, 13, 12, "imagestretch"};
struct {
    int refcount;
    int size;
    int count;
    char data[22];
} sjg_string75 = { 1, 22, 21, "listlayoutorientation"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string76 = { 1, 9, 8, "loglevel"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string77 = { 1, 15, 14, "mouseeventtype"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string78 = { 1, 4, 3, "ptr"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string79 = { 1, 11, 10, "#animation"};
struct {
    int refcount;
    int size;
    int count;
    char data[44];
} sjg_string8 = { 1, 44, 43, "assets/sj-lib-ui/shaders/v3f-n3f-phong.vert"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string80 = { 1, 8, 7, "#effect"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string81 = { 1, 9, 8, "#element"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string82 = { 1, 7, 6, "#model"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string83 = { 1, 9, 8, "animator"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string84 = { 1, 10, 9, "nextframe"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string85 = { 1, 11, 10, "array!char"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string86 = { 1, 6, 5, "clone"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string87 = { 1, 6, 5, "getat"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string88 = { 1, 9, 8, "getcount"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string89 = { 1, 14, 13, "gettotalcount"};
struct {
    int refcount;
    int size;
    int count;
    char data[44];
} sjg_string9 = { 1, 44, 43, "assets/sj-lib-ui/shaders/v3f-n3f-phong.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string90 = { 1, 7, 6, "initat"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string91 = { 1, 11, 10, "create!i32"};
struct {
    int refcount;
    int size;
    int count;
    char data[38];
} sjg_string92 = { 1, 38, 37, "create!vertex_location_texture_normal"};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string93 = { 1, 17, 16, "array!#animation"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string94 = { 1, 15, 14, "array!#element"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string95 = { 1, 13, 12, "array!#model"};
struct {
    int refcount;
    int size;
    int count;
    char data[19];
} sjg_string96 = { 1, 19, 18, "_quicksortcallback"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string97 = { 1, 6, 5, "setat"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string98 = { 1, 7, 6, "sortcb"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string99 = { 1, 10, 9, "array!i32"};

struct {
    int refcount;
    int size;
    int count;
    char data[0];
} g_empty = { 1, 0, 0 };
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
#define sjs_array_char_typeId 44
#define sjs_string_typeId 42
#define sjs_windowrenderer_typeId 47
#define sjs_color_typeId 49
#define sjs_size_typeId 53
#define sjs_mat4_typeId 54
#define sjs_rect_typeId 55
#define sjs_scene2d_typeId 52
#define sjs_vec3_typeId 57
#define sjs_light_typeId 56
#define sji_model_typeId 58
#define sjs_array_heap_iface_model_typeId 112
#define sjs_list_heap_iface_model_typeId 59
#define sjs_point_typeId 108
#define sjs_mouseevent_typeId 60
#define sjs_hash_string_weak_iface_model_typeId 61
#define sji_element_typeId 66
#define sjs_hash_string_weak_iface_element_typeId 67
#define sjs_array_heap_iface_animation_typeId 73
#define sjs_list_heap_iface_animation_typeId 72
#define sjs_animator_typeId 70
#define sji_animation_typeId 71
#define sjs_shader_typeId 74
#define sjs_fontkey_typeId 75
#define sjs_font_typeId 76
#define sjs_hash_fontkey_weak_font_typeId 77
#define sjs_array_rect_typeId 84
#define sjs_list_rect_typeId 83
#define sjs_array_u32_typeId 86
#define sjs_list_u32_typeId 85
#define sjs_style_typeId 87
#define sjs_array_heap_iface_element_typeId 90
#define sjs_margin_typeId 91
#define sji_effect_typeId 94
#define sjs_filllayout_typeId 89
#define cb_rect_void_typeId 92
#define cb_rect_void_heap_typeId 92
#define cb_scene2d_void_typeId 93
#define cb_scene2d_void_heap_typeId 93
#define sjs_scene3delement_typeId 111
#define cb_heap_iface_model_heap_iface_model_i32_typeId 135
#define cb_heap_iface_model_heap_iface_model_i32_heap_typeId 135
#define cb_local_iface_model_local_iface_model_i32_typeId 141
#define cb_local_iface_model_local_iface_model_i32_heap_typeId 141
#define sjs_array_i32_typeId 204
#define sjs_array_vertex_location_texture_normal_typeId 205
#define sjs_vertexbuffer_vertex_location_texture_normal_typeId 155
#define sjs_vec4_typeId 163
#define sjs_framebuffer_typeId 164
#define sjs_texture_typeId 165
#define sjs_renderbuffer_typeId 166
#define sjs_scene2dmodel_typeId 153
#define sjs_vec2_typeId 160
#define sjs_vertex_location_texture_normal_typeId 154
#define cb_string_heap_string_typeId 213
#define cb_string_heap_string_heap_typeId 213
#define sjs_lambda3_typeId 231
#define sjs_lambda2_typeId 225
#define sjs_image_typeId 260
#define sjs_imagerenderer_typeId 262
#define sjs_imageelement_typeId 259
#define sjs_boxrenderer_typeId 274
#define sjs_crosshairselement_typeId 273

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_windowrenderer sjs_windowrenderer;
typedef struct td_sjs_color sjs_color;
typedef struct td_sjs_size sjs_size;
typedef struct td_sjs_mat4 sjs_mat4;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_scene2d sjs_scene2d;
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
typedef struct td_sjs_lambda3 sjs_lambda3;
typedef struct td_sjs_lambda2 sjs_lambda2;
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

struct td_sjs_array_char {
    int _refCount;
    void* v;
};

struct td_sjs_string {
    int _refCount;
    int32_t offset;
    int32_t count;
    sjs_array_char data;
    bool _isnullterminated;
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
    void* v;
};

struct td_sjs_list_heap_iface_model {
    int _refCount;
    sjs_array_heap_iface_model arr;
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
    void* v;
};

struct td_sjs_list_heap_iface_animation {
    int _refCount;
    sjs_array_heap_iface_animation arr;
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
    void* v;
};

struct td_sjs_list_rect {
    int _refCount;
    sjs_array_rect arr;
};

struct td_sjs_array_u32 {
    int _refCount;
    void* v;
};

struct td_sjs_list_u32 {
    int _refCount;
    sjs_array_u32 arr;
};

struct td_sjs_style {
    int _refCount;
};

struct td_sjs_array_heap_iface_element {
    int _refCount;
    void* v;
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
    void* v;
};

struct td_sjs_array_vertex_location_texture_normal {
    int _refCount;
    void* v;
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

struct td_sjs_lambda3 {
    int _refCount;
    sjs_mouseevent* lambdaparam3;
    sjs_vec2* lambdaparam4;
    sjs_mouseevent* lambdaparam5;
};

struct td_sjs_lambda2 {
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
char* string_char(sjs_string* str);
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
int32_t g_borderposition_bottom;
int32_t g_borderposition_fill;
int32_t g_borderposition_left;
int32_t g_borderposition_right;
int32_t g_borderposition_top;
int32_t g_clickstate_entered;
int32_t g_clickstate_none;
int32_t g_clickstate_pressed;
int32_t g_flowlayoutorientation_bottomtop;
int32_t g_flowlayoutorientation_leftright;
int32_t g_flowlayoutorientation_rightleft;
int32_t g_flowlayoutorientation_topbottom;
int32_t g_glblendfunctype_gl_constant_alpha;
int32_t g_glblendfunctype_gl_constant_color;
int32_t g_glblendfunctype_gl_dst_alpha;
int32_t g_glblendfunctype_gl_dst_color;
int32_t g_glblendfunctype_gl_one;
int32_t g_glblendfunctype_gl_one_minus_constant_alpha;
int32_t g_glblendfunctype_gl_one_minus_constant_color;
int32_t g_glblendfunctype_gl_one_minus_dst_alpha;
int32_t g_glblendfunctype_gl_one_minus_dst_color;
int32_t g_glblendfunctype_gl_one_minus_src_alpha;
int32_t g_glblendfunctype_gl_one_minus_src_color;
int32_t g_glblendfunctype_gl_src_alpha;
int32_t g_glblendfunctype_gl_src_alpha_saturate;
int32_t g_glblendfunctype_gl_src_color;
int32_t g_glblendfunctype_gl_zero;
int32_t g_gldrawmode_gl_line_loop;
int32_t g_gldrawmode_gl_line_strip;
int32_t g_gldrawmode_gl_lines;
int32_t g_gldrawmode_gl_points;
int32_t g_gldrawmode_gl_triangle_fan;
int32_t g_gldrawmode_gl_triangle_strip;
int32_t g_gldrawmode_gl_triangles;
int32_t g_glfeature_gl_blend;
int32_t g_glfeature_gl_cull_face;
int32_t g_glfeature_gl_depth_test;
int32_t g_glfeature_gl_dither;
int32_t g_glfeature_gl_polygon_offset_fill;
int32_t g_glfeature_gl_sample_alpha_to_coverage;
int32_t g_glfeature_gl_sample_coverage;
int32_t g_glfeature_gl_scissor_test;
int32_t g_glfeature_gl_stencil_test;
int32_t g_glframebufferattachment_gl_color_attachment0;
int32_t g_glframebufferattachment_gl_depth_attachment;
int32_t g_glframebufferattachment_gl_stencil_attachment;
int32_t g_glframebufferstatus_gl_framebuffer_complete;
int32_t g_glframebufferstatus_gl_framebuffer_incomplete_attachment;
int32_t g_glframebufferstatus_gl_framebuffer_incomplete_missing_attachment;
int32_t g_glframebufferstatus_gl_framebuffer_unsupported;
int32_t g_glframebuffertexture_gl_texture_2d;
int32_t g_glframebuffertexture_gl_texture_cube_map_negative_x;
int32_t g_glframebuffertexture_gl_texture_cube_map_negative_y;
int32_t g_glframebuffertexture_gl_texture_cube_map_negative_z;
int32_t g_glframebuffertexture_gl_texture_cube_map_positive_x;
int32_t g_glframebuffertexture_gl_texture_cube_map_positive_y;
int32_t g_glframebuffertexture_gl_texture_cube_map_positive_z;
int32_t g_glrenderbufferformat_gl_depth_component16;
int32_t g_glrenderbufferformat_gl_rgb565;
int32_t g_glrenderbufferformat_gl_rgb5_a1;
int32_t g_glrenderbufferformat_gl_rgba4;
int32_t g_glrenderbufferformat_gl_stencil_index8;
int32_t g_gltexture_gl_texture_2d;
int32_t g_gltexture_gl_texture_cube_map;
int32_t g_gltextureattribute_gl_texture_mag_filter;
int32_t g_gltextureattribute_gl_texture_min_filter;
int32_t g_gltextureattribute_gl_texture_wrap_s;
int32_t g_gltextureattribute_gl_texture_wrap_t;
int32_t g_gltextureformat_gl_alpha;
int32_t g_gltextureformat_gl_luminance;
int32_t g_gltextureformat_gl_luminance_alpha;
int32_t g_gltextureformat_gl_rgb;
int32_t g_gltextureformat_gl_rgba;
int32_t g_gltexturetype_gl_unsigned_byte;
int32_t g_gltexturetype_gl_unsigned_short_4_4_4_4;
int32_t g_gltexturetype_gl_unsigned_short_5_5_5_1;
int32_t g_gltexturetype_gl_unsigned_short_5_6_5;
int32_t g_gltexturevalue_gl_clamp_to_edge;
int32_t g_gltexturevalue_gl_linear;
int32_t g_gltexturevalue_gl_linear_mipmap_linear;
int32_t g_gltexturevalue_gl_linear_mipmap_nearest;
int32_t g_gltexturevalue_gl_mirrored_repeat;
int32_t g_gltexturevalue_gl_nearest;
int32_t g_gltexturevalue_gl_nearest_mipmap_linear;
int32_t g_gltexturevalue_gl_nearest_mipmap_nearest;
int32_t g_gltexturevalue_gl_repeat;
int32_t g_gridunittype_fixed;
int32_t g_gridunittype_star;
int32_t g_imagestretch_aspectratio;
int32_t g_imagestretch_center;
int32_t g_imagestretch_fill;
int32_t g_listlayoutorientation_bottomtop;
int32_t g_listlayoutorientation_leftright;
int32_t g_listlayoutorientation_rightleft;
int32_t g_listlayoutorientation_topbottom;
int32_t g_loglevel_debug;
int32_t g_loglevel_error;
int32_t g_loglevel_fatal;
int32_t g_loglevel_info;
int32_t g_loglevel_trace;
int32_t g_loglevel_warn;
int32_t g_mouseeventtype_down;
int32_t g_mouseeventtype_move;
int32_t g_mouseeventtype_up;
int32_t g_texthorizontal_center;
int32_t g_texthorizontal_left;
int32_t g_texthorizontal_right;
int32_t g_textvertical_bottom;
int32_t g_textvertical_center;
int32_t g_textvertical_top;

sjs_animator g_animator = { -1 };
sjs_shader g_blurhorizontalshader = { -1 };
sjs_shader g_blurverticalshader = { -1 };
sjs_shader g_boxshader = { -1 };
int32_t g_clocks_per_sec;
sjs_color g_colors_black = { -1 };
sjs_color g_colors_blue = { -1 };
sjs_color g_colors_gray = { -1 };
sjs_color g_colors_green = { -1 };
sjs_color g_colors_red = { -1 };
sjs_color g_colors_white = { -1 };
sjs_hash_string_weak_iface_element g_elementsbyid = { -1 };
float g_f32_pi;
sjs_shader g_fadeshader = { -1 };
sjs_hash_fontkey_weak_font g_fonthash = { -1 };
sjs_list_u32 g_glframebuffers = { -1 };
sjs_list_rect g_glviewports = { -1 };
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_shader g_imageshader = { -1 };
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
sjs_rect g_looplastrect = { -1 };
int32_t g_mainloop_frames;
int32_t g_mainloop_lasttick;
bool g_mainloop_shouldcontinue;
bool g_mainloop_showfps;
sjs_hash_string_weak_iface_model g_modelsbyid = { -1 };
sji_element g_mouse_captureelement = { 0 };
sjs_shader g_phongcolorshader = { -1 };
sjs_shader g_phongtextureshader = { -1 };
sji_element g_root = { 0 };
sjs_scene2d g_rootscene = { -1 };
sjs_windowrenderer g_rootwindowrenderer = { -1 };
sjs_shader g_saturateshader = { -1 };
sjs_style g_style = { -1 };
sjs_shader g_textshader = { -1 };
uint32_t g_u32_maxvalue;
sjs_string g_vertex_location_texture_normal_format = { -1 };
int32_t result1;
float result13;
sjs_scene2dmodel* sjt_call11 = 0;
sjs_vec3 sjt_call110 = { -1 };
sjs_vec3 sjt_call111 = { -1 };
sjs_imageelement* sjt_call112 = 0;
sjs_string sjt_call120 = { -1 };
sjs_crosshairselement* sjt_call121 = 0;
sjs_crosshairselement* sjt_call122 = 0;
sjs_filllayout* sjt_call3 = 0;
sjs_scene3delement* sjt_call6 = 0;
sjs_filllayout* sjt_cast2 = 0;
sjs_scene3delement* sjt_cast3 = 0;
sjs_imageelement* sjt_cast39 = 0;
sjs_crosshairselement* sjt_cast48 = 0;
sjs_crosshairselement* sjt_cast49 = 0;
sjs_scene2dmodel* sjt_cast6 = 0;
int32_t sjt_functionParam107;
sji_model sjt_functionParam108 = { 0 };
int32_t sjt_functionParam29;
sji_element sjt_functionParam30 = { 0 };
int32_t sjt_functionParam433;
int32_t sjt_functionParam434;
sjs_vec3* sjt_functionParam435 = 0;
sjs_vec3* sjt_functionParam436 = 0;
int32_t sjt_functionParam437;
sji_element sjt_functionParam438 = { 0 };
sjs_string* sjt_functionParam464 = 0;
int32_t sjt_functionParam465;
sji_element sjt_functionParam466 = { 0 };
int32_t sjt_functionParam471;
sji_element sjt_functionParam472 = { 0 };
sjs_array_heap_iface_element* sjt_parent287 = 0;
sjs_array_heap_iface_element* sjt_parent297 = 0;
sjs_array_heap_iface_element* sjt_parent30 = 0;
sjs_array_heap_iface_element* sjt_parent302 = 0;
sjs_array_heap_iface_model* sjt_parent85 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_animator(sjs_animator* _this);
void sjf_animator_copy(sjs_animator* _this, sjs_animator* _from);
void sjf_animator_destroy(sjs_animator* _this);
void sjf_animator_heap(sjs_animator* _this);
void sjf_animator_nextframe(sjs_animator* _parent, int32_t time);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_gettotalcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_create_i32(int32_t size, int32_t item, sjs_array_i32* _return);
void sjf_array_create_i32_heap(int32_t size, int32_t item, sjs_array_i32** _return);
void sjf_array_create_vertex_location_texture_normal(int32_t size, sjs_vertex_location_texture_normal* item, sjs_array_vertex_location_texture_normal* _return);
void sjf_array_create_vertex_location_texture_normal_heap(int32_t size, sjs_vertex_location_texture_normal* item, sjs_array_vertex_location_texture_normal** _return);
void sjf_array_heap_iface_animation(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_animation_copy(sjs_array_heap_iface_animation* _this, sjs_array_heap_iface_animation* _from);
void sjf_array_heap_iface_animation_destroy(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_animation_getat_heap(sjs_array_heap_iface_animation* _parent, int32_t index, sji_animation* _return);
void sjf_array_heap_iface_animation_getcount(sjs_array_heap_iface_animation* _parent, int32_t* _return);
void sjf_array_heap_iface_animation_heap(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_element(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_copy(sjs_array_heap_iface_element* _this, sjs_array_heap_iface_element* _from);
void sjf_array_heap_iface_element_destroy(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_getat_heap(sjs_array_heap_iface_element* _parent, int32_t index, sji_element* _return);
void sjf_array_heap_iface_element_getcount(sjs_array_heap_iface_element* _parent, int32_t* _return);
void sjf_array_heap_iface_element_heap(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_initat(sjs_array_heap_iface_element* _parent, int32_t index, sji_element item);
void sjf_array_heap_iface_model(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model__quicksortcallback(sjs_array_heap_iface_model* _parent, int32_t left, int32_t right, cb_heap_iface_model_heap_iface_model_i32 cb);
void sjf_array_heap_iface_model_clone(sjs_array_heap_iface_model* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_heap_iface_model* _return);
void sjf_array_heap_iface_model_clone_heap(sjs_array_heap_iface_model* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_heap_iface_model** _return);
void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from);
void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_getat_heap(sjs_array_heap_iface_model* _parent, int32_t index, sji_model* _return);
void sjf_array_heap_iface_model_getcount(sjs_array_heap_iface_model* _parent, int32_t* _return);
void sjf_array_heap_iface_model_gettotalcount(sjs_array_heap_iface_model* _parent, int32_t* _return);
void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_initat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item);
void sjf_array_heap_iface_model_setat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item);
void sjf_array_heap_iface_model_sortcb(sjs_array_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_getcount(sjs_array_i32* _parent, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_setat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_rect(sjs_array_rect* _this);
void sjf_array_rect_clone(sjs_array_rect* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_rect* _return);
void sjf_array_rect_clone_heap(sjs_array_rect* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_rect** _return);
void sjf_array_rect_copy(sjs_array_rect* _this, sjs_array_rect* _from);
void sjf_array_rect_destroy(sjs_array_rect* _this);
void sjf_array_rect_getat(sjs_array_rect* _parent, int32_t index, sjs_rect* _return);
void sjf_array_rect_getat_heap(sjs_array_rect* _parent, int32_t index, sjs_rect** _return);
void sjf_array_rect_getcount(sjs_array_rect* _parent, int32_t* _return);
void sjf_array_rect_gettotalcount(sjs_array_rect* _parent, int32_t* _return);
void sjf_array_rect_heap(sjs_array_rect* _this);
void sjf_array_rect_initat(sjs_array_rect* _parent, int32_t index, sjs_rect* item);
void sjf_array_u32(sjs_array_u32* _this);
void sjf_array_u32_clone(sjs_array_u32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_u32* _return);
void sjf_array_u32_clone_heap(sjs_array_u32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_u32** _return);
void sjf_array_u32_copy(sjs_array_u32* _this, sjs_array_u32* _from);
void sjf_array_u32_destroy(sjs_array_u32* _this);
void sjf_array_u32_getat(sjs_array_u32* _parent, int32_t index, uint32_t* _return);
void sjf_array_u32_getcount(sjs_array_u32* _parent, int32_t* _return);
void sjf_array_u32_gettotalcount(sjs_array_u32* _parent, int32_t* _return);
void sjf_array_u32_heap(sjs_array_u32* _this);
void sjf_array_u32_initat(sjs_array_u32* _parent, int32_t index, uint32_t item);
void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from);
void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_getat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return);
void sjf_array_vertex_location_texture_normal_getat_heap(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal** _return);
void sjf_array_vertex_location_texture_normal_getcount(sjs_array_vertex_location_texture_normal* _parent, int32_t* _return);
void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_setat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
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
void sjf_lambda2(sjs_lambda2* _this);
void sjf_lambda2_copy(sjs_lambda2* _this, sjs_lambda2* _from);
void sjf_lambda2_destroy(sjs_lambda2* _this);
void sjf_lambda2_heap(sjs_lambda2* _this);
void sjf_lambda2_invoke(sjs_lambda2* _parent, sjs_string* _return);
void sjf_lambda2_invoke_heap(sjs_lambda2* _parent, sjs_string** _return);
void sjf_lambda3(sjs_lambda3* _this);
void sjf_lambda3_copy(sjs_lambda3* _this, sjs_lambda3* _from);
void sjf_lambda3_destroy(sjs_lambda3* _this);
void sjf_lambda3_heap(sjs_lambda3* _this);
void sjf_lambda3_invoke(sjs_lambda3* _parent, sjs_string* _return);
void sjf_lambda3_invoke_heap(sjs_lambda3* _parent, sjs_string** _return);
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
char* string_char(sjs_string* str) {
    sjf_string_nullterminate(str);
    return ((sjs_array*)str->data.v)->data + str->offset;
}
#include <lib/sj-lib-common/common.cpp>
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
        fprintf( stderr, "%d vertices, %d indices\n",
        (int)vector_size( self->vertices ), (int)vector_size( self->indices ) );
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
    #include <lib/sj-lib-ui/obj_parser.c>
void sjf_animator(sjs_animator* _this) {
}

void sjf_animator_copy(sjs_animator* _this, sjs_animator* _from) {
    _this->animations._refCount = 1;
#line 27 "lib/sj-lib-ui/animation.sj"
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
    int32_t sjt_capture88;
    sjs_list_heap_iface_animation* sjt_parent304 = 0;

#line 31 "lib/sj-lib-ui/animation.sj"
    _parent->current = time;
#line 4 "lib/sj-lib-common/list.sj"
    sjt_parent304 = &_parent->animations;
#line 4
    sjf_list_heap_iface_animation_getcount(sjt_parent304, &sjt_capture88);
    if (sjt_capture88 > 0) {
        int32_t i;
        int32_t sjt_forEnd28;
        int32_t sjt_forStart28;
        sjs_list_heap_iface_animation* sjt_parent305 = 0;

#line 35 "lib/sj-lib-ui/animation.sj"
        sjt_forStart28 = 0;
#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent305 = &_parent->animations;
#line 4
        sjf_list_heap_iface_animation_getcount(sjt_parent305, &sjt_forEnd28);
#line 35 "lib/sj-lib-ui/animation.sj"
        i = sjt_forEnd28 - 1;
        while (i >= sjt_forStart28) {
            sji_animation a = { 0 };
            bool sjt_capture89;
            int32_t sjt_functionParam474;
            int32_t sjt_interfaceParam19;
            sjs_list_heap_iface_animation* sjt_parent307 = 0;
            sji_animation sjt_parent308 = { 0 };

#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent307 = &_parent->animations;
#line 35 "lib/sj-lib-ui/animation.sj"
            sjt_functionParam474 = i;
#line 35
            sjf_list_heap_iface_animation_getat_heap(sjt_parent307, sjt_functionParam474, &a);
#line 2
            sjt_parent308 = a;
#line 31
            sjt_interfaceParam19 = time;
#line 37
            sjt_parent308._vtbl->nextframe(sjt_parent308._parent, sjt_interfaceParam19, &sjt_capture89);
            if (sjt_capture89) {
                int32_t sjt_functionParam475;
                sjs_list_heap_iface_animation* sjt_parent309 = 0;

#line 53 "lib/sj-lib-common/list.sj"
                sjt_parent309 = &_parent->animations;
#line 35 "lib/sj-lib-ui/animation.sj"
                sjt_functionParam475 = i;
#line 35
                sjf_list_heap_iface_animation_removeat(sjt_parent309, sjt_functionParam475);
            }

#line 35
            i--;

            if (a._parent != 0) {
                a._parent->_refCount--;
                if (a._parent->_refCount <= 0) {
                    a._vtbl->destroy(a._parent);
                    free(a._parent);
                }
            }
        }
    }
}

void sjf_array_char(sjs_array_char* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(char), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    char* p = (char*)arr->data + offset;
#line 187
    char* newp = (char*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(char) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_char(_return);
}

void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(char), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    char* p = (char*)arr->data + offset;
#line 187
    char* newp = (char*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(char) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_char_heap((*_return));
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !true && !false
#line 381
        char* p = (char*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    char* p = (char*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_char_gettotalcount(sjs_array_char* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    char* p = (char*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 64
    arr->count = index + 1;
}

void sjf_array_create_i32(int32_t size, int32_t item, sjs_array_i32* _return) {
    void* v;

#line 3 "lib/sj-lib-common/array.sj"
    v = 0;
#line 5
    sjs_array* arr = createarray(sizeof(int32_t), size);
#line 6
    int32_t* p = (int32_t*)arr->data;
#line 7
    for (int i = 0; i < size; i++) {
#line 8
        #line 2 "lib/sj-lib-common/array.sj"
p[i] = item;
;
#line 9
    }
#line 10
    arr->count = size;  
#line 11
    v = arr;
#line 11
    _return->_refCount = 1;
#line 13
    _return->v = v;
#line 13
    sjf_array_i32(_return);
}

void sjf_array_create_i32_heap(int32_t size, int32_t item, sjs_array_i32** _return) {
    void* v;

#line 3 "lib/sj-lib-common/array.sj"
    v = 0;
#line 5
    sjs_array* arr = createarray(sizeof(int32_t), size);
#line 6
    int32_t* p = (int32_t*)arr->data;
#line 7
    for (int i = 0; i < size; i++) {
#line 8
        #line 2 "lib/sj-lib-common/array.sj"
p[i] = item;
;
#line 9
    }
#line 10
    arr->count = size;  
#line 11
    v = arr;
#line 11
    (*_return) = (sjs_array_i32*)malloc(sizeof(sjs_array_i32));
#line 11
    (*_return)->_refCount = 1;
#line 13
    (*_return)->v = v;
#line 13
    sjf_array_i32_heap((*_return));
}

void sjf_array_create_vertex_location_texture_normal(int32_t size, sjs_vertex_location_texture_normal* item, sjs_array_vertex_location_texture_normal* _return) {
    void* v;

#line 3 "lib/sj-lib-common/array.sj"
    v = 0;
#line 5
    sjs_array* arr = createarray(sizeof(sjs_vertex_location_texture_normal), size);
#line 6
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data;
#line 7
    for (int i = 0; i < size; i++) {
#line 8
        p[i]._refCount = 1;
#line 2 "lib/sj-lib-common/array.sj"
sjf_vertex_location_texture_normal_copy(&p[i], item);
;
#line 9
    }
#line 10
    arr->count = size;  
#line 11
    v = arr;
#line 11
    _return->_refCount = 1;
#line 13
    _return->v = v;
#line 13
    sjf_array_vertex_location_texture_normal(_return);
}

void sjf_array_create_vertex_location_texture_normal_heap(int32_t size, sjs_vertex_location_texture_normal* item, sjs_array_vertex_location_texture_normal** _return) {
    void* v;

#line 3 "lib/sj-lib-common/array.sj"
    v = 0;
#line 5
    sjs_array* arr = createarray(sizeof(sjs_vertex_location_texture_normal), size);
#line 6
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data;
#line 7
    for (int i = 0; i < size; i++) {
#line 8
        p[i]._refCount = 1;
#line 2 "lib/sj-lib-common/array.sj"
sjf_vertex_location_texture_normal_copy(&p[i], item);
;
#line 9
    }
#line 10
    arr->count = size;  
#line 11
    v = arr;
#line 11
    (*_return) = (sjs_array_vertex_location_texture_normal*)malloc(sizeof(sjs_array_vertex_location_texture_normal));
#line 11
    (*_return)->_refCount = 1;
#line 13
    (*_return)->v = v;
#line 13
    sjf_array_vertex_location_texture_normal_heap((*_return));
}

void sjf_array_heap_iface_animation(sjs_array_heap_iface_animation* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_animation_copy(sjs_array_heap_iface_animation* _this, sjs_array_heap_iface_animation* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_heap_iface_animation_destroy(sjs_array_heap_iface_animation* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !false
#line 381
        sji_animation* p = (sji_animation*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_heap_iface_animation_getat_heap(sjs_array_heap_iface_animation* _parent, int32_t index, sji_animation* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sji_animation* p = (sji_animation*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_animation_getcount(sjs_array_heap_iface_animation* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_heap_iface_animation_heap(sjs_array_heap_iface_animation* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_element(sjs_array_heap_iface_element* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_element_copy(sjs_array_heap_iface_element* _this, sjs_array_heap_iface_element* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_heap_iface_element_destroy(sjs_array_heap_iface_element* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !false
#line 381
        sji_element* p = (sji_element*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_heap_iface_element_getat_heap(sjs_array_heap_iface_element* _parent, int32_t index, sji_element* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sji_element* p = (sji_element*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_element_getcount(sjs_array_heap_iface_element* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_heap_iface_element_heap(sjs_array_heap_iface_element* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_element_initat(sjs_array_heap_iface_element* _parent, int32_t index, sji_element item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    sji_element* p = (sji_element*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
if (p[index]._parent != 0) {
    p[index]._parent->_refCount++;
}
;
#line 64
    arr->count = index + 1;
}

void sjf_array_heap_iface_model(sjs_array_heap_iface_model* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_model__quicksortcallback(sjs_array_heap_iface_model* _parent, int32_t left, int32_t right, cb_heap_iface_model_heap_iface_model_i32 cb) {
    int32_t i;
    int32_t j;
    sji_model pivot = { 0 };
    int32_t sjt_functionParam68;
    bool sjt_while1;

#line 234 "lib/sj-lib-common/array.sj"
    i = left;
#line 234
    j = right;
#line 238
    sjt_functionParam68 = (left + right) / 2;
#line 238
    sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam68, &pivot);
#line 239
    sjt_while1 = i <= j;
    while (sjt_while1) {
        bool shouldcontinue;
        int32_t sjt_capture20;
        bool sjt_while2;
        bool sjt_while3;

#line 240 "lib/sj-lib-common/array.sj"
        shouldcontinue = true;
#line 240
        sjf_array_heap_iface_model_getcount(_parent, &sjt_capture20);
        if (i < sjt_capture20) {
#line 241 "lib/sj-lib-common/array.sj"
            sjt_while2 = shouldcontinue;
        } else {
#line 241 "lib/sj-lib-common/array.sj"
            sjt_while2 = false;
        }

        while (sjt_while2) {
            int32_t sjt_capture21;
            int32_t sjt_capture22;
            sji_model sjt_functionParam69 = { 0 };
            int32_t sjt_functionParam70;
            sji_model sjt_functionParam71 = { 0 };

#line 242 "lib/sj-lib-common/array.sj"
            sjt_functionParam70 = i;
#line 242
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam70, &sjt_functionParam69);
#line 242
            sjt_functionParam71 = pivot;
            if (sjt_functionParam71._parent != 0) {
                sjt_functionParam71._parent->_refCount++;
            }

#line 242
            cb._cb(cb._parent, sjt_functionParam69, sjt_functionParam71, &sjt_capture21);
#line 242
            shouldcontinue = sjt_capture21 < 0;
            if (shouldcontinue) {
#line 244 "lib/sj-lib-common/array.sj"
                i = i + 1;
            }

#line 242
            sjf_array_heap_iface_model_getcount(_parent, &sjt_capture22);
            if (i < sjt_capture22) {
#line 241 "lib/sj-lib-common/array.sj"
                sjt_while2 = shouldcontinue;
            } else {
#line 241 "lib/sj-lib-common/array.sj"
                sjt_while2 = false;
            }

            if (sjt_functionParam69._parent != 0) {
                sjt_functionParam69._parent->_refCount--;
                if (sjt_functionParam69._parent->_refCount <= 0) {
                    sjt_functionParam69._vtbl->destroy(sjt_functionParam69._parent);
                    free(sjt_functionParam69._parent);
                }
            }
            if (sjt_functionParam71._parent != 0) {
                sjt_functionParam71._parent->_refCount--;
                if (sjt_functionParam71._parent->_refCount <= 0) {
                    sjt_functionParam71._vtbl->destroy(sjt_functionParam71._parent);
                    free(sjt_functionParam71._parent);
                }
            }
        }

#line 248
        shouldcontinue = true;
        if (j >= 0) {
#line 249 "lib/sj-lib-common/array.sj"
            sjt_while3 = shouldcontinue;
        } else {
#line 249 "lib/sj-lib-common/array.sj"
            sjt_while3 = false;
        }

        while (sjt_while3) {
            int32_t sjt_capture23;
            sji_model sjt_functionParam72 = { 0 };
            int32_t sjt_functionParam73;
            sji_model sjt_functionParam74 = { 0 };

#line 250 "lib/sj-lib-common/array.sj"
            sjt_functionParam73 = j;
#line 250
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam73, &sjt_functionParam72);
#line 250
            sjt_functionParam74 = pivot;
            if (sjt_functionParam74._parent != 0) {
                sjt_functionParam74._parent->_refCount++;
            }

#line 250
            cb._cb(cb._parent, sjt_functionParam72, sjt_functionParam74, &sjt_capture23);
#line 250
            shouldcontinue = sjt_capture23 > 0;
            if (shouldcontinue) {
#line 252 "lib/sj-lib-common/array.sj"
                j = j - 1;
            }

            if (j >= 0) {
#line 249 "lib/sj-lib-common/array.sj"
                sjt_while3 = shouldcontinue;
            } else {
#line 249 "lib/sj-lib-common/array.sj"
                sjt_while3 = false;
            }

            if (sjt_functionParam72._parent != 0) {
                sjt_functionParam72._parent->_refCount--;
                if (sjt_functionParam72._parent->_refCount <= 0) {
                    sjt_functionParam72._vtbl->destroy(sjt_functionParam72._parent);
                    free(sjt_functionParam72._parent);
                }
            }
            if (sjt_functionParam74._parent != 0) {
                sjt_functionParam74._parent->_refCount--;
                if (sjt_functionParam74._parent->_refCount <= 0) {
                    sjt_functionParam74._vtbl->destroy(sjt_functionParam74._parent);
                    free(sjt_functionParam74._parent);
                }
            }
        }

        if (i <= j) {
            int32_t sjt_functionParam75;
            int32_t sjt_functionParam76;
            sji_model sjt_functionParam77 = { 0 };
            int32_t sjt_functionParam78;
            int32_t sjt_functionParam79;
            sji_model sjt_functionParam80 = { 0 };
            sji_model tmp = { 0 };

#line 257 "lib/sj-lib-common/array.sj"
            sjt_functionParam75 = i;
#line 257
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam75, &tmp);
#line 258
            sjt_functionParam76 = i;
#line 258
            sjt_functionParam78 = j;
#line 258
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam78, &sjt_functionParam77);
#line 258
            sjf_array_heap_iface_model_setat(_parent, sjt_functionParam76, sjt_functionParam77);
#line 259
            sjt_functionParam79 = j;
#line 259
            sjt_functionParam80 = tmp;
            if (sjt_functionParam80._parent != 0) {
                sjt_functionParam80._parent->_refCount++;
            }

#line 259
            sjf_array_heap_iface_model_setat(_parent, sjt_functionParam79, sjt_functionParam80);
#line 260
            i = i + 1;
#line 261
            j = j - 1;

            if (sjt_functionParam77._parent != 0) {
                sjt_functionParam77._parent->_refCount--;
                if (sjt_functionParam77._parent->_refCount <= 0) {
                    sjt_functionParam77._vtbl->destroy(sjt_functionParam77._parent);
                    free(sjt_functionParam77._parent);
                }
            }
            if (sjt_functionParam80._parent != 0) {
                sjt_functionParam80._parent->_refCount--;
                if (sjt_functionParam80._parent->_refCount <= 0) {
                    sjt_functionParam80._vtbl->destroy(sjt_functionParam80._parent);
                    free(sjt_functionParam80._parent);
                }
            }
            if (tmp._parent != 0) {
                tmp._parent->_refCount--;
                if (tmp._parent->_refCount <= 0) {
                    tmp._vtbl->destroy(tmp._parent);
                    free(tmp._parent);
                }
            }
        }

#line 239
        sjt_while1 = i <= j;
    }

    if (left < j) {
        int32_t sjt_functionParam81;
        int32_t sjt_functionParam82;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam83;

#line 234 "lib/sj-lib-common/array.sj"
        sjt_functionParam81 = left;
#line 266
        sjt_functionParam82 = j;
#line 234
        sjt_functionParam83 = cb;
#line 234
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam81, sjt_functionParam82, sjt_functionParam83);
    }

    if (i < right) {
        int32_t sjt_functionParam84;
        int32_t sjt_functionParam85;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam86;

#line 269 "lib/sj-lib-common/array.sj"
        sjt_functionParam84 = i;
#line 234
        sjt_functionParam85 = right;
#line 234
        sjt_functionParam86 = cb;
#line 234
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam84, sjt_functionParam85, sjt_functionParam86);
    }

    if (pivot._parent != 0) {
        pivot._parent->_refCount--;
        if (pivot._parent->_refCount <= 0) {
            pivot._vtbl->destroy(pivot._parent);
            free(pivot._parent);
        }
    }
}

void sjf_array_heap_iface_model_clone(sjs_array_heap_iface_model* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_heap_iface_model* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(sji_model), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    sji_model* p = (sji_model*)arr->data + offset;
#line 187
    sji_model* newp = (sji_model*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if false
#line 193
    memcpy(newp, p, sizeof(sji_model) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
if (newp[i]._parent != 0) {
    newp[i]._parent->_refCount++;
}
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_heap_iface_model(_return);
}

void sjf_array_heap_iface_model_clone_heap(sjs_array_heap_iface_model* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_heap_iface_model** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(sji_model), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    sji_model* p = (sji_model*)arr->data + offset;
#line 187
    sji_model* newp = (sji_model*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if false
#line 193
    memcpy(newp, p, sizeof(sji_model) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
if (newp[i]._parent != 0) {
    newp[i]._parent->_refCount++;
}
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_heap_iface_model*)malloc(sizeof(sjs_array_heap_iface_model));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_heap_iface_model_heap((*_return));
}

void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !false
#line 381
        sji_model* p = (sji_model*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_heap_iface_model_getat_heap(sjs_array_heap_iface_model* _parent, int32_t index, sji_model* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sji_model* p = (sji_model*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_model_getcount(sjs_array_heap_iface_model* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_heap_iface_model_gettotalcount(sjs_array_heap_iface_model* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_model_initat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    sji_model* p = (sji_model*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
if (p[index]._parent != 0) {
    p[index]._parent->_refCount++;
}
;
#line 64
    arr->count = index + 1;
}

void sjf_array_heap_iface_model_setat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item) {
#line 70 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 71
    if (index >= arr->count || index < 0) {
#line 72
        halt("setAt: out of bounds %d:%d\n", index, arr->count);
#line 73
    }
#line 75
    sji_model* p = (sji_model*)arr->data;
#line 76
    if (p[index]._parent != 0) {
    p[index]._parent->_refCount--;
    if (p[index]._parent->_refCount <= 0) {
        p[index]._vtbl->destroy(p[index]._parent);
        free(p[index]._parent);
    }
}
;
#line 77
    #line 68 "lib/sj-lib-common/array.sj"
p[index] = item;
if (p[index]._parent != 0) {
    p[index]._parent->_refCount++;
}
;
}

void sjf_array_heap_iface_model_sortcb(sjs_array_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb) {
    int32_t sjt_capture19;

    sjf_array_heap_iface_model_getcount(_parent, &sjt_capture19);
    if (sjt_capture19 > 1) {
        int32_t sjt_capture24;
        int32_t sjt_functionParam87;
        int32_t sjt_functionParam88;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam89;

#line 281 "lib/sj-lib-common/array.sj"
        sjt_functionParam87 = 0;
#line 281
        sjf_array_heap_iface_model_getcount(_parent, &sjt_capture24);
#line 281
        sjt_functionParam88 = sjt_capture24 - 1;
#line 279
        sjt_functionParam89 = cb;
#line 279
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam87, sjt_functionParam88, sjt_functionParam89);
    }
}

void sjf_array_i32(sjs_array_i32* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !true && !false
#line 381
        int32_t* p = (int32_t*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    int32_t* p = (int32_t*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_i32_getcount(sjs_array_i32* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_i32_heap(sjs_array_i32* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_i32_setat(sjs_array_i32* _parent, int32_t index, int32_t item) {
#line 70 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 71
    if (index >= arr->count || index < 0) {
#line 72
        halt("setAt: out of bounds %d:%d\n", index, arr->count);
#line 73
    }
#line 75
    int32_t* p = (int32_t*)arr->data;
#line 76
    ;
#line 77
    #line 68 "lib/sj-lib-common/array.sj"
p[index] = item;
;
}

void sjf_array_rect(sjs_array_rect* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_rect_clone(sjs_array_rect* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_rect* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(sjs_rect), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    sjs_rect* p = (sjs_rect*)arr->data + offset;
#line 187
    sjs_rect* newp = (sjs_rect*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if false
#line 193
    memcpy(newp, p, sizeof(sjs_rect) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        newp[i]._refCount = 1;
#line 170 "lib/sj-lib-common/array.sj"
sjf_rect_copy(&newp[i], &p[i]);
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_rect(_return);
}

void sjf_array_rect_clone_heap(sjs_array_rect* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_rect** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(sjs_rect), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    sjs_rect* p = (sjs_rect*)arr->data + offset;
#line 187
    sjs_rect* newp = (sjs_rect*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if false
#line 193
    memcpy(newp, p, sizeof(sjs_rect) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        newp[i]._refCount = 1;
#line 170 "lib/sj-lib-common/array.sj"
sjf_rect_copy(&newp[i], &p[i]);
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_rect*)malloc(sizeof(sjs_array_rect));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_rect_heap((*_return));
}

void sjf_array_rect_copy(sjs_array_rect* _this, sjs_array_rect* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_rect_destroy(sjs_array_rect* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !true
#line 381
        sjs_rect* p = (sjs_rect*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_rect_getat(sjs_array_rect* _parent, int32_t index, sjs_rect* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_rect* p = (sjs_rect*)arr->data;
#line 48
    _return->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_rect_copy(_return, &p[index]);
return;;       
}

void sjf_array_rect_getat_heap(sjs_array_rect* _parent, int32_t index, sjs_rect** _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_rect* p = (sjs_rect*)arr->data;
#line 48
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
(*_return)->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_rect_copy((*_return), &p[index]);
return;;       
}

void sjf_array_rect_getcount(sjs_array_rect* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_rect_gettotalcount(sjs_array_rect* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_rect_heap(sjs_array_rect* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_rect_initat(sjs_array_rect* _parent, int32_t index, sjs_rect* item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    sjs_rect* p = (sjs_rect*)arr->data;
#line 63
    p[index]._refCount = 1;
#line 52 "lib/sj-lib-common/array.sj"
sjf_rect_copy(&p[index], item);
;
#line 64
    arr->count = index + 1;
}

void sjf_array_u32(sjs_array_u32* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_u32_clone(sjs_array_u32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_u32* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(uint32_t), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    uint32_t* p = (uint32_t*)arr->data + offset;
#line 187
    uint32_t* newp = (uint32_t*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(uint32_t) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_u32(_return);
}

void sjf_array_u32_clone_heap(sjs_array_u32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_u32** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(uint32_t), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    uint32_t* p = (uint32_t*)arr->data + offset;
#line 187
    uint32_t* newp = (uint32_t*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(uint32_t) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_u32*)malloc(sizeof(sjs_array_u32));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_u32_heap((*_return));
}

void sjf_array_u32_copy(sjs_array_u32* _this, sjs_array_u32* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_u32_destroy(sjs_array_u32* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !true && !false
#line 381
        uint32_t* p = (uint32_t*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_u32_getat(sjs_array_u32* _parent, int32_t index, uint32_t* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    uint32_t* p = (uint32_t*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_u32_getcount(sjs_array_u32* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_u32_gettotalcount(sjs_array_u32* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_u32_heap(sjs_array_u32* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_u32_initat(sjs_array_u32* _parent, int32_t index, uint32_t item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    uint32_t* p = (uint32_t*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 64
    arr->count = index + 1;
}

void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !true
#line 381
        sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_vertex_location_texture_normal_getat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data;
#line 48
    _return->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_vertex_location_texture_normal_copy(_return, &p[index]);
return;;       
}

void sjf_array_vertex_location_texture_normal_getat_heap(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal** _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data;
#line 48
    (*_return) = (sjs_vertex_location_texture_normal*)malloc(sizeof(sjs_vertex_location_texture_normal));
(*_return)->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_vertex_location_texture_normal_copy((*_return), &p[index]);
return;;       
}

void sjf_array_vertex_location_texture_normal_getcount(sjs_array_vertex_location_texture_normal* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_vertex_location_texture_normal_setat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item) {
#line 70 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 71
    if (index >= arr->count || index < 0) {
#line 72
        halt("setAt: out of bounds %d:%d\n", index, arr->count);
#line 73
    }
#line 75
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data;
#line 76
    ;
#line 77
    p[index]._refCount = 1;
#line 68 "lib/sj-lib-common/array.sj"
sjf_vertex_location_texture_normal_copy(&p[index], item);
;
}

void sjf_bool_asstring(bool val, sjs_string* _return) {
    if (val) {
        _return->_refCount = 1;
#line 3 "lib/sj-lib-common/bool.sj"
        _return->offset = 0;
#line 3
        _return->count = 4;
#line 3
        _return->data._refCount = 1;
#line 3
        _return->data.v = &sjg_string37;
#line 3
        sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
    } else {
        _return->_refCount = 1;
#line 5 "lib/sj-lib-common/bool.sj"
        _return->offset = 0;
#line 5
        _return->count = 5;
#line 5
        _return->data._refCount = 1;
#line 5
        _return->data.v = &sjg_string36;
#line 5
        sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
    }
}

void sjf_bool_asstring_heap(bool val, sjs_string** _return) {
    if (val) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 3 "lib/sj-lib-common/bool.sj"
        (*_return)->offset = 0;
#line 3
        (*_return)->count = 4;
#line 3
        (*_return)->data._refCount = 1;
#line 3
        (*_return)->data.v = &sjg_string37;
#line 3
        sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
        (*_return)->_isnullterminated = false;
#line 16
        sjf_string_heap((*_return));
    } else {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 5 "lib/sj-lib-common/bool.sj"
        (*_return)->offset = 0;
#line 5
        (*_return)->count = 5;
#line 5
        (*_return)->data._refCount = 1;
#line 5
        (*_return)->data.v = &sjg_string36;
#line 5
        sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
        (*_return)->_isnullterminated = false;
#line 16
        sjf_string_heap((*_return));
    }
}

void sjf_boxrenderer(sjs_boxrenderer* _this) {
#line 20 "lib/sj-lib-ui/boxRenderer.sj"
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
#line 1 "lib/sj-lib-ui/boxRenderer.sj"
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
#line 45 "lib/sj-lib-ui/boxRenderer.sj"
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
#line 20 "lib/sj-lib-ui/boxRenderer.sj"
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
#line 10 "lib/sj-lib-ui/boxRenderer.sj"
    glUseProgram(g_boxshader.id);
#line 11
    glUniformMatrix4fv(glGetUniformLocation(g_boxshader.id, "model" ), 1, 0, (GLfloat*)&scene->model.m00);
#line 12
    glUniformMatrix4fv(glGetUniformLocation(g_boxshader.id, "view" ), 1, 0, (GLfloat*)&scene->view.m00);
#line 13
    glUniformMatrix4fv(glGetUniformLocation(g_boxshader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection.m00);
#line 14
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_char_touppercase(char x, char* _return) {
#line 3 "lib/sj-lib-common/char.sj"
    #line 2 "lib/sj-lib-common/char.sj"
(*_return) = toupper(x);
return;
}

void sjf_color(sjs_color* _this) {
}

void sjf_color_asvec3(sjs_color* _parent, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 21 "lib/sj-lib-ui/color.sj"
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
#line 21 "lib/sj-lib-ui/color.sj"
    (*_return)->x = _parent->r;
#line 21
    (*_return)->y = _parent->g;
#line 21
    (*_return)->z = _parent->b;
#line 21
    sjf_vec3_heap((*_return));
}

void sjf_color_copy(sjs_color* _this, sjs_color* _from) {
#line 10 "lib/sj-lib-ui/color.sj"
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
#line 1 "lib/sj-lib-ui/crossHairsElement.sj"
    sjf_color_copy(&_this->color, &_from->color);
#line 1
    _this->_rect._refCount = 1;
#line 1
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 1
    sjs_boxrenderer* copyoption24 = (_from->_topdownrenderer._refCount != -1 ? &_from->_topdownrenderer : 0);
    if (copyoption24 != 0) {
        _this->_topdownrenderer._refCount = 1;
#line 1 "lib/sj-lib-ui/crossHairsElement.sj"
        sjf_boxrenderer_copy(&_this->_topdownrenderer, copyoption24);
    } else {
        _this->_topdownrenderer._refCount = -1;
    }

#line 1
    sjs_boxrenderer* copyoption25 = (_from->_leftrightrenderer._refCount != -1 ? &_from->_leftrightrenderer : 0);
    if (copyoption25 != 0) {
        _this->_leftrightrenderer._refCount = 1;
#line 1 "lib/sj-lib-ui/crossHairsElement.sj"
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
    bool sjt_capture87;
    sjs_point* sjt_functionParam470 = 0;
    sjs_rect* sjt_parent301 = 0;

#line 11 "lib/sj-lib-ui/rect.sj"
    sjt_parent301 = &_parent->_rect;
#line 41 "lib/sj-lib-ui/crossHairsElement.sj"
    sjt_functionParam470 = &mouseevent->point;
#line 41
    sjf_rect_containspoint(sjt_parent301, sjt_functionParam470, &sjt_capture87);
    if (sjt_capture87) {
        if (mouseevent->eventtype == g_mouseeventtype_move) {
            if (_parent->_point._refCount == 1) { sjf_point_destroy(&_parent->_point); }
;
#line 43 "lib/sj-lib-ui/crossHairsElement.sj"
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
    *_return = 273;
}

void sjf_crosshairselement_getrect(sjs_crosshairselement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 12 "lib/sj-lib-ui/crossHairsElement.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_crosshairselement_getrect_heap(sjs_crosshairselement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 12 "lib/sj-lib-ui/crossHairsElement.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_crosshairselement_getsize(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 9 "lib/sj-lib-ui/crossHairsElement.sj"
    _return->w = maxsize->w;
#line 9
    _return->h = maxsize->h;
#line 9
    sjf_size(_return);
}

void sjf_crosshairselement_getsize_heap(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 9 "lib/sj-lib-ui/crossHairsElement.sj"
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
#line 26 "lib/sj-lib-ui/crossHairsElement.sj"
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
#line 25 "lib/sj-lib-ui/crossHairsElement.sj"
            sjf_boxrenderer_copy(&_parent->_topdownrenderer, copyoption26);
        } else {
            _parent->_topdownrenderer._refCount = -1;
        }
    }

    if ((_parent->_leftrightrenderer._refCount != -1 ? &_parent->_leftrightrenderer : 0) == 0) {
        sjt_value14._refCount = 1;
        sjt_value14.rect._refCount = 1;
#line 32 "lib/sj-lib-ui/crossHairsElement.sj"
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
#line 31 "lib/sj-lib-ui/crossHairsElement.sj"
            sjf_boxrenderer_copy(&_parent->_leftrightrenderer, copyoption27);
        } else {
            _parent->_leftrightrenderer._refCount = -1;
        }
    }

    if ((_parent->_topdownrenderer._refCount != -1 ? &_parent->_topdownrenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam468 = 0;
        sjs_boxrenderer* sjt_parent299 = 0;

#line 8 "lib/sj-lib-ui/boxRenderer.sj"
        sjt_parent299 = (_parent->_topdownrenderer._refCount != -1 ? &_parent->_topdownrenderer : 0);
#line 23 "lib/sj-lib-ui/crossHairsElement.sj"
        sjt_functionParam468 = scene;
#line 23
        sjf_boxrenderer_render(sjt_parent299, sjt_functionParam468);
    }

    if ((_parent->_leftrightrenderer._refCount != -1 ? &_parent->_leftrightrenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam469 = 0;
        sjs_boxrenderer* sjt_parent300 = 0;

#line 8 "lib/sj-lib-ui/boxRenderer.sj"
        sjt_parent300 = (_parent->_leftrightrenderer._refCount != -1 ? &_parent->_leftrightrenderer : 0);
#line 23 "lib/sj-lib-ui/crossHairsElement.sj"
        sjt_functionParam469 = scene;
#line 23
        sjf_boxrenderer_render(sjt_parent300, sjt_functionParam469);
    }

    if (sjt_value13._refCount == 1) { sjf_boxrenderer_destroy(&sjt_value13); }
;
    if (sjt_value14._refCount == 1) { sjf_boxrenderer_destroy(&sjt_value14); }
;
}

void sjf_crosshairselement_setrect(sjs_crosshairselement* _parent, sjs_rect* rect_) {
    bool result12;
    bool sjt_capture84;
    sjs_rect* sjt_functionParam467 = 0;
    sjs_rect* sjt_parent298 = 0;

#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent298 = &_parent->_rect;
#line 14 "lib/sj-lib-ui/crossHairsElement.sj"
    sjt_functionParam467 = rect_;
#line 14
    sjf_rect_isequal(sjt_parent298, sjt_functionParam467, &sjt_capture84);
#line 15
    result12 = !sjt_capture84;
    if (result12) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 14 "lib/sj-lib-ui/crossHairsElement.sj"
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
#line 10 "lib/sj-lib-common/debug.sj"
    debugout("%s\n", string_char(data));
}

void sjf_f32_asstring(float val, sjs_string* _return) {
    int32_t count;
    void* v;

#line 94 "lib/sj-lib-common/f32.sj"
    v = 0;
#line 95
    count = 0;
#line 97
    sjs_array* arr = createarray(1, 256);
#line 98
    snprintf(arr->data, 256, "%f", val);
#line 99
    arr->count = (int)strlen(arr->data);
#line 100
    count = arr->count;
#line 101
    v = arr;
#line 101
    _return->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    _return->offset = 0;
#line 103 "lib/sj-lib-common/f32.sj"
    _return->count = count;
#line 103
    _return->data._refCount = 1;
#line 103
    _return->data.v = v;
#line 103
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_f32_asstring_heap(float val, sjs_string** _return) {
    int32_t count;
    void* v;

#line 94 "lib/sj-lib-common/f32.sj"
    v = 0;
#line 95
    count = 0;
#line 97
    sjs_array* arr = createarray(1, 256);
#line 98
    snprintf(arr->data, 256, "%f", val);
#line 99
    arr->count = (int)strlen(arr->data);
#line 100
    count = arr->count;
#line 101
    v = arr;
#line 101
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 101
    (*_return)->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    (*_return)->offset = 0;
#line 103 "lib/sj-lib-common/f32.sj"
    (*_return)->count = count;
#line 103
    (*_return)->data._refCount = 1;
#line 103
    (*_return)->data.v = v;
#line 103
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_f32_compare(float l, float r, int32_t* _return) {
    if (l == r) {
#line 133 "lib/sj-lib-common/f32.sj"
        (*_return) = 0;
    } else {
        if (l < r) {
            int32_t result4;

#line 135 "lib/sj-lib-common/f32.sj"
            result4 = -1;
#line 135
            (*_return) = result4;
        } else {
#line 137 "lib/sj-lib-common/f32.sj"
            (*_return) = 1;
        }
    }
}

void sjf_f32_cos(float v, float* _return) {
    float result;

#line 12 "lib/sj-lib-common/f32.sj"
    result = 0.0f;
#line 14
    result = cosf(v);
#line 11
    (*_return) = result;
}

void sjf_f32_hash(float val, uint32_t* _return) {
    uint32_t result;

#line 123 "lib/sj-lib-common/f32.sj"
    result = (uint32_t)0u;
#line 125
    int32_t* p = (int32_t*)&val;
#line 126
    result = *p;
#line 122
    (*_return) = result;
}

void sjf_f32_sin(float v, float* _return) {
    float result;

#line 20 "lib/sj-lib-common/f32.sj"
    result = 0.0f;
#line 22
    result = sinf(v);
#line 19
    (*_return) = result;
}

void sjf_f32_sqrt(float v, float* _return) {
    float result;

#line 4 "lib/sj-lib-common/f32.sj"
    result = 0.0f;
#line 6
    result = sqrtf(v);
#line 3
    (*_return) = result;
}

void sjf_f32_tan(float v, float* _return) {
    float result;

#line 28 "lib/sj-lib-common/f32.sj"
    result = 0.0f;
#line 30
    result = tanf(v);
#line 27
    (*_return) = result;
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
#line 1 "lib/sj-lib-ui/fillLayout.sj"
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
    sjs_array_heap_iface_element* sjt_functionParam28 = 0;
    sjs_mouseevent* sjt_parent29 = 0;

#line 55 "lib/sj-lib-ui/fillLayout.sj"
    sjt_parent29 = mouseevent;
#line 56
    sjt_functionParam28 = &_parent->children;
#line 56
    sjf_mouseevent_firechildren(sjt_parent29, sjt_functionParam28, _return);
}

void sjf_filllayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 89;
}

void sjf_filllayout_getrect(sjs_filllayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 17 "lib/sj-lib-ui/fillLayout.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_filllayout_getrect_heap(sjs_filllayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 17 "lib/sj-lib-ui/fillLayout.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_filllayout_getsize(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t i;
    sjs_size innersize = { -1 };
    sjs_size size = { -1 };
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    sjs_margin* sjt_functionParam14 = 0;
    sjs_margin* sjt_functionParam17 = 0;
    sjs_size* sjt_parent10 = 0;
    sjs_size* sjt_parent5 = 0;
    sjs_array_heap_iface_element* sjt_parent6 = 0;

    size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    size.w = 0;
#line 3
    size.h = 0;
#line 3
    sjf_size(&size);
#line 7 "lib/sj-lib-ui/fillLayout.sj"
    sjt_parent5 = maxsize;
#line 9
    sjt_functionParam14 = &_parent->margin;
#line 9
    sjf_size_subtractmargin(sjt_parent5, sjt_functionParam14, &innersize);
#line 10
    sjt_forStart1 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent6 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent6, &sjt_forEnd1);
#line 10 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sji_element child = { 0 };
        sjs_size sjt_call4 = { -1 };
        sjs_size sjt_funcold2 = { -1 };
        int32_t sjt_functionParam15;
        sjs_size* sjt_functionParam16 = 0;
        sjs_size* sjt_interfaceParam1 = 0;
        sjs_array_heap_iface_element* sjt_parent7 = 0;
        sjs_size* sjt_parent8 = 0;
        sji_element sjt_parent9 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent7 = &_parent->children;
#line 10 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam15 = i;
#line 10
        sjf_array_heap_iface_element_getat_heap(sjt_parent7, sjt_functionParam15, &child);
#line 12 "lib/sj-lib-ui/size.sj"
        sjt_parent8 = &size;
#line 2 "lib/sj-lib-ui/element.sj"
        sjt_parent9 = child;
#line 12 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam1 = &innersize;
#line 12
        sjt_parent9._vtbl->getsize(sjt_parent9._parent, sjt_interfaceParam1, &sjt_call4);
#line 12
        sjt_functionParam16 = &sjt_call4;
#line 12
        sjf_size_max(sjt_parent8, sjt_functionParam16, &sjt_funcold2);
#line 12
        if (size._refCount == 1) { sjf_size_destroy(&size); }
;
#line 12 "lib/sj-lib-ui/size.sj"
        sjf_size_copy(&size, &sjt_funcold2);
#line 10 "lib/sj-lib-ui/fillLayout.sj"
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
        if (sjt_call4._refCount == 1) { sjf_size_destroy(&sjt_call4); }
;
        if (sjt_funcold2._refCount == 1) { sjf_size_destroy(&sjt_funcold2); }
;
    }

#line 19 "lib/sj-lib-ui/size.sj"
    sjt_parent10 = &size;
#line 14 "lib/sj-lib-ui/fillLayout.sj"
    sjt_functionParam17 = &_parent->margin;
#line 14
    sjf_size_addmargin(sjt_parent10, sjt_functionParam17, _return);

    if (innersize._refCount == 1) { sjf_size_destroy(&innersize); }
;
    if (size._refCount == 1) { sjf_size_destroy(&size); }
;
}

void sjf_filllayout_getsize_heap(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t i;
    sjs_size innersize = { -1 };
    sjs_size size = { -1 };
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;
    sjs_margin* sjt_functionParam18 = 0;
    sjs_margin* sjt_functionParam21 = 0;
    sjs_size* sjt_parent11 = 0;
    sjs_array_heap_iface_element* sjt_parent12 = 0;
    sjs_size* sjt_parent16 = 0;

    size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    size.w = 0;
#line 3
    size.h = 0;
#line 3
    sjf_size(&size);
#line 7 "lib/sj-lib-ui/fillLayout.sj"
    sjt_parent11 = maxsize;
#line 9
    sjt_functionParam18 = &_parent->margin;
#line 9
    sjf_size_subtractmargin(sjt_parent11, sjt_functionParam18, &innersize);
#line 10
    sjt_forStart2 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent12 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent12, &sjt_forEnd2);
#line 10 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart2;
    while (i < sjt_forEnd2) {
        sji_element child = { 0 };
        sjs_size sjt_call5 = { -1 };
        sjs_size sjt_funcold3 = { -1 };
        int32_t sjt_functionParam19;
        sjs_size* sjt_functionParam20 = 0;
        sjs_size* sjt_interfaceParam2 = 0;
        sjs_array_heap_iface_element* sjt_parent13 = 0;
        sjs_size* sjt_parent14 = 0;
        sji_element sjt_parent15 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent13 = &_parent->children;
#line 10 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam19 = i;
#line 10
        sjf_array_heap_iface_element_getat_heap(sjt_parent13, sjt_functionParam19, &child);
#line 12 "lib/sj-lib-ui/size.sj"
        sjt_parent14 = &size;
#line 2 "lib/sj-lib-ui/element.sj"
        sjt_parent15 = child;
#line 12 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam2 = &innersize;
#line 12
        sjt_parent15._vtbl->getsize(sjt_parent15._parent, sjt_interfaceParam2, &sjt_call5);
#line 12
        sjt_functionParam20 = &sjt_call5;
#line 12
        sjf_size_max(sjt_parent14, sjt_functionParam20, &sjt_funcold3);
#line 12
        if (size._refCount == 1) { sjf_size_destroy(&size); }
;
#line 12 "lib/sj-lib-ui/size.sj"
        sjf_size_copy(&size, &sjt_funcold3);
#line 10 "lib/sj-lib-ui/fillLayout.sj"
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
        if (sjt_call5._refCount == 1) { sjf_size_destroy(&sjt_call5); }
;
        if (sjt_funcold3._refCount == 1) { sjf_size_destroy(&sjt_funcold3); }
;
    }

#line 19 "lib/sj-lib-ui/size.sj"
    sjt_parent16 = &size;
#line 14 "lib/sj-lib-ui/fillLayout.sj"
    sjt_functionParam21 = &_parent->margin;
#line 14
    sjf_size_addmargin_heap(sjt_parent16, sjt_functionParam21, _return);

    if (innersize._refCount == 1) { sjf_size_destroy(&innersize); }
;
    if (size._refCount == 1) { sjf_size_destroy(&size); }
;
}

void sjf_filllayout_heap(sjs_filllayout* _this) {
}

void sjf_filllayout_render(sjs_filllayout* _parent, sjs_scene2d* scene) {
    if ((_parent->effect._parent != 0)) {
        sji_effect ifValue3 = { 0 };
        sjs_scene2d* sjt_interfaceParam6 = 0;
        cb_scene2d_void sjt_interfaceParam7;
        sji_effect sjt_parent22 = { 0 };

#line 41 "lib/sj-lib-ui/fillLayout.sj"
        ifValue3 = _parent->effect;
        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount++;
        }

#line 4 "lib/sj-lib-ui/effect.sj"
        sjt_parent22 = ifValue3;
#line 40 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam6 = scene;
#line 42
        sjt_interfaceParam7._parent = (sjs_object*)_parent;
#line 42
        sjt_interfaceParam7._cb = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_renderinner;
#line 42
        sjt_parent22._vtbl->render(sjt_parent22._parent, sjt_interfaceParam6, sjt_interfaceParam7);

        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount--;
            if (ifValue3._parent->_refCount <= 0) {
                ifValue3._vtbl->destroy(ifValue3._parent);
                free(ifValue3._parent);
            }
        }
    } else {
        sjs_scene2d* sjt_functionParam26 = 0;

#line 40 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam26 = scene;
#line 40
        sjf_filllayout_renderinner(_parent, sjt_functionParam26);
    }
}

void sjf_filllayout_renderinner(sjs_filllayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    sjs_array_heap_iface_element* sjt_parent23 = 0;

#line 49 "lib/sj-lib-ui/fillLayout.sj"
    sjt_forStart4 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent23 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent23, &sjt_forEnd4);
#line 49 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        sji_element child = { 0 };
        int32_t sjt_functionParam25;
        sjs_scene2d* sjt_interfaceParam8 = 0;
        sjs_array_heap_iface_element* sjt_parent24 = 0;
        sji_element sjt_parent25 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent24 = &_parent->children;
#line 49 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam25 = i;
#line 49
        sjf_array_heap_iface_element_getat_heap(sjt_parent24, sjt_functionParam25, &child);
#line 5 "lib/sj-lib-ui/element.sj"
        sjt_parent25 = child;
#line 48 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam8 = scene;
#line 51
        sjt_parent25._vtbl->render(sjt_parent25._parent, sjt_interfaceParam8);
#line 49
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }
}

void sjf_filllayout_setrect(sjs_filllayout* _parent, sjs_rect* rect_) {
    sjs_rect innerrect = { -1 };
    sjs_margin* sjt_functionParam22 = 0;
    sjs_rect* sjt_parent17 = 0;

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 19 "lib/sj-lib-ui/fillLayout.sj"
    sjf_rect_copy(&_parent->_rect, rect_);
#line 7 "lib/sj-lib-ui/rect.sj"
    sjt_parent17 = &_parent->_rect;
#line 21 "lib/sj-lib-ui/fillLayout.sj"
    sjt_functionParam22 = &_parent->margin;
#line 21
    sjf_rect_subtractmargin(sjt_parent17, sjt_functionParam22, &innerrect);
    if ((_parent->effect._parent != 0)) {
        sji_effect ifValue1 = { 0 };
        sjs_rect* sjt_interfaceParam3 = 0;
        cb_rect_void sjt_interfaceParam4;
        sji_effect sjt_parent18 = { 0 };

#line 23 "lib/sj-lib-ui/fillLayout.sj"
        ifValue1 = _parent->effect;
        if (ifValue1._parent != 0) {
            ifValue1._parent->_refCount++;
        }

#line 3 "lib/sj-lib-ui/effect.sj"
        sjt_parent18 = ifValue1;
#line 24 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam3 = &innerrect;
#line 24
        sjt_interfaceParam4._parent = (sjs_object*)_parent;
#line 24
        sjt_interfaceParam4._cb = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrectinner;
#line 24
        sjt_parent18._vtbl->setrect(sjt_parent18._parent, sjt_interfaceParam3, sjt_interfaceParam4);

        if (ifValue1._parent != 0) {
            ifValue1._parent->_refCount--;
            if (ifValue1._parent->_refCount <= 0) {
                ifValue1._vtbl->destroy(ifValue1._parent);
                free(ifValue1._parent);
            }
        }
    } else {
        sjs_rect* sjt_functionParam24 = 0;

#line 26 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam24 = &innerrect;
#line 26
        sjf_filllayout_setrectinner(_parent, sjt_functionParam24);
    }

    if (innerrect._refCount == 1) { sjf_rect_destroy(&innerrect); }
;
}

void sjf_filllayout_setrectinner(sjs_filllayout* _parent, sjs_rect* innerrect) {
    int32_t i;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;
    sjs_array_heap_iface_element* sjt_parent19 = 0;

#line 33 "lib/sj-lib-ui/fillLayout.sj"
    sjt_forStart3 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent19 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent19, &sjt_forEnd3);
#line 33 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        sji_element child = { 0 };
        int32_t sjt_functionParam23;
        sjs_rect* sjt_interfaceParam5 = 0;
        sjs_array_heap_iface_element* sjt_parent20 = 0;
        sji_element sjt_parent21 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent20 = &_parent->children;
#line 33 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam23 = i;
#line 33
        sjf_array_heap_iface_element_getat_heap(sjt_parent20, sjt_functionParam23, &child);
#line 4 "lib/sj-lib-ui/element.sj"
        sjt_parent21 = child;
#line 32 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam5 = innerrect;
#line 35
        sjt_parent21._vtbl->setrect(sjt_parent21._parent, sjt_interfaceParam5);
#line 33
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }
}

void sjf_font(sjs_font* _this) {
#line 65 "lib/sj-lib-ui/font.sj"
    _this->atlas = texture_atlas_new( 512, 512, 3 );
#line 66
    _this->font = texture_font_new_from_file(_this->atlas, _this->size, string_char(&_this->src));
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
#line 33 "lib/sj-lib-ui/font.sj"
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
#line 91 "lib/sj-lib-ui/font.sj"
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
#line 65 "lib/sj-lib-ui/font.sj"
    _this->atlas = texture_atlas_new( 512, 512, 3 );
#line 66
    _this->font = texture_font_new_from_file(_this->atlas, _this->size, string_char(&_this->src));
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
#line 20 "lib/sj-lib-ui/font.sj"
    sjf_string_copy(&_this->src, &_from->src);
#line 20
    _this->size = _from->size;
}

void sjf_fontkey_destroy(sjs_fontkey* _this) {
    if (_this->src._refCount == 1) { sjf_string_destroy(&_this->src); }
;
}

void sjf_fontkey_hash(sjs_fontkey* _parent, uint32_t* _return) {
    uint32_t sjt_capture2;
    uint32_t sjt_capture3;
    float sjt_functionParam12;
    sjs_string* sjt_parent3 = 0;

#line 146 "lib/sj-lib-common/string.sj"
    sjt_parent3 = &_parent->src;
#line 146
    sjf_string_hash(sjt_parent3, &sjt_capture2);
#line 25 "lib/sj-lib-ui/font.sj"
    sjt_functionParam12 = _parent->size;
#line 25
    sjf_f32_hash(sjt_functionParam12, &sjt_capture3);
#line 25
    (*_return) = sjt_capture2 ^ sjt_capture3;
}

void sjf_fontkey_heap(sjs_fontkey* _this) {
}

void sjf_fontkey_isequal(sjs_fontkey* _parent, sjs_fontkey* x, bool* _return) {
    bool sjt_capture4;
    sjs_string* sjt_functionParam13 = 0;
    sjs_string* sjt_parent4 = 0;

#line 71 "lib/sj-lib-common/string.sj"
    sjt_parent4 = &_parent->src;
#line 29 "lib/sj-lib-ui/font.sj"
    sjt_functionParam13 = &x->src;
#line 29
    sjf_string_isequal(sjt_parent4, sjt_functionParam13, &sjt_capture4);
    if (sjt_capture4) {
#line 29 "lib/sj-lib-ui/font.sj"
        (*_return) = (_parent->size == x->size);
    } else {
#line 29 "lib/sj-lib-ui/font.sj"
        (*_return) = false;
    }
}

void sjf_framebuffer(sjs_framebuffer* _this) {
}

void sjf_framebuffer_copy(sjs_framebuffer* _this, sjs_framebuffer* _from) {
    _this->size._refCount = 1;
#line 1 "lib/sj-lib-ui/framebuffer.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 1
    _this->id = _from->id;
#line 8
    _this->id = _from->id;
#line 9
    glid_retain(_this->id);
}

void sjf_framebuffer_destroy(sjs_framebuffer* _this) {
#line 13 "lib/sj-lib-ui/framebuffer.sj"
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
#line 272 "lib/sj-lib-ui/gl.sj"
    glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer->id);
}

void sjf_glbindtexture(int32_t t, sjs_texture* texture) {
#line 173 "lib/sj-lib-ui/gl.sj"
    glBindTexture(t, texture->id);
}

void sjf_glblendfunc(int32_t sfactor, int32_t dfactor) {
#line 285 "lib/sj-lib-ui/gl.sj"
    glBlendFunc(sfactor, dfactor);
}

void sjf_glcheckframebufferstatus(int32_t* _return) {
    int32_t status;

#line 263 "lib/sj-lib-ui/gl.sj"
    status = g_glframebufferstatus_gl_framebuffer_unsupported;
#line 265
    status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
#line 262
    (*_return) = status;
}

void sjf_glclearcolor(sjs_color* color) {
#line 279 "lib/sj-lib-ui/gl.sj"
    glClearColor(color->r, color->g, color->b, color->a);
}

void sjf_gldisable(int32_t feature) {
#line 119 "lib/sj-lib-ui/gl.sj"
    glDisable(feature);
}

void sjf_glenable(int32_t feature) {
#line 113 "lib/sj-lib-ui/gl.sj"
    glEnable(feature);
}

void sjf_glframebufferrenderbuffer(int32_t attachment, sjs_renderbuffer* renderbuffer) {
#line 258 "lib/sj-lib-ui/gl.sj"
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, renderbuffer->id);
}

void sjf_glframebuffertexture2d(int32_t attachment, int32_t target, sjs_texture* texture, int32_t level) {
#line 238 "lib/sj-lib-ui/gl.sj"
    glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, target, texture->id, level);
}

void sjf_glgenframebuffer(sjs_size* size, sjs_framebuffer* _return) {
    uint32_t id;

#line 209 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 211
    glGenFramebuffers(1, &id);
#line 211
    _return->_refCount = 1;
#line 211
    _return->size._refCount = 1;
#line 208
    sjf_size_copy(&_return->size, size);
#line 213
    _return->id = id;
#line 213
    sjf_framebuffer(_return);
}

void sjf_glgenframebuffer_heap(sjs_size* size, sjs_framebuffer** _return) {
    uint32_t id;

#line 209 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 211
    glGenFramebuffers(1, &id);
#line 211
    (*_return) = (sjs_framebuffer*)malloc(sizeof(sjs_framebuffer));
#line 211
    (*_return)->_refCount = 1;
#line 211
    (*_return)->size._refCount = 1;
#line 208
    sjf_size_copy(&(*_return)->size, size);
#line 213
    (*_return)->id = id;
#line 213
    sjf_framebuffer_heap((*_return));
}

void sjf_glgenrenderbuffer(sjs_size* size, sjs_renderbuffer* _return) {
    uint32_t id;

#line 243 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 245
    glGenRenderbuffers(1, &id); 
#line 245
    _return->_refCount = 1;
#line 245
    _return->size._refCount = 1;
#line 242
    sjf_size_copy(&_return->size, size);
#line 247
    _return->id = id;
#line 247
    sjf_renderbuffer(_return);
}

void sjf_glgenrenderbuffer_heap(sjs_size* size, sjs_renderbuffer** _return) {
    uint32_t id;

#line 243 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 245
    glGenRenderbuffers(1, &id); 
#line 245
    (*_return) = (sjs_renderbuffer*)malloc(sizeof(sjs_renderbuffer));
#line 245
    (*_return)->_refCount = 1;
#line 245
    (*_return)->size._refCount = 1;
#line 242
    sjf_size_copy(&(*_return)->size, size);
#line 247
    (*_return)->id = id;
#line 247
    sjf_renderbuffer_heap((*_return));
}

void sjf_glgentexture(sjs_size* size, sjs_texture* _return) {
    uint32_t id;

#line 217 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 219
    glGenTextures(1, &id);
#line 219
    _return->_refCount = 1;
#line 219
    _return->size._refCount = 1;
#line 216
    sjf_size_copy(&_return->size, size);
#line 221
    _return->id = id;
#line 221
    sjf_texture(_return);
}

void sjf_glgentexture_heap(sjs_size* size, sjs_texture** _return) {
    uint32_t id;

#line 217 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 219
    glGenTextures(1, &id);
#line 219
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
#line 219
    (*_return)->_refCount = 1;
#line 219
    (*_return)->size._refCount = 1;
#line 216
    sjf_size_copy(&(*_return)->size, size);
#line 221
    (*_return)->id = id;
#line 221
    sjf_texture_heap((*_return));
}

void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return) {
#line 179 "lib/sj-lib-ui/gl.sj"
    int result = glGetUniformLocation(shader->id, string_char(name));
#line 180
    #line 178 "lib/sj-lib-ui/gl.sj"
(*_return) = result;
return;;
}

void sjf_glpopframebuffer(sjs_framebuffer* framebuffer) {
    uint32_t id;
    sjs_string sjt_call13 = { -1 };
    int32_t sjt_capture33;
    uint32_t sjt_capture34;
    int32_t sjt_capture35;
    int32_t sjt_capture36;
    int32_t sjt_functionParam154;
    int32_t sjt_functionParam156;
    sjs_list_u32* sjt_parent100 = 0;
    sjs_list_u32* sjt_parent101 = 0;
    sjs_list_u32* sjt_parent96 = 0;
    sjs_list_u32* sjt_parent98 = 0;
    sjs_list_u32* sjt_parent99 = 0;

#line 8 "lib/sj-lib-common/list.sj"
    sjt_parent96 = &g_glframebuffers;
#line 4
    sjt_parent98 = &g_glframebuffers;
#line 4
    sjf_list_u32_getcount(sjt_parent98, &sjt_capture33);
#line 155 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam154 = sjt_capture33 - 1;
#line 155
    sjf_list_u32_getat(sjt_parent96, sjt_functionParam154, &sjt_capture34);
    if (sjt_capture34 != framebuffer->id) {
        sjs_string* sjt_functionParam155 = 0;

        sjt_call13._refCount = 1;
#line 156 "lib/sj-lib-ui/gl.sj"
        sjt_call13.offset = 0;
#line 156
        sjt_call13.count = 33;
#line 156
        sjt_call13.data._refCount = 1;
#line 156
        sjt_call13.data.v = &sjg_string17;
#line 156
        sjf_array_char(&sjt_call13.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call13._isnullterminated = false;
#line 16
        sjf_string(&sjt_call13);
#line 156 "lib/sj-lib-ui/gl.sj"
        sjt_functionParam155 = &sjt_call13;
#line 156
        sjf_halt(sjt_functionParam155);
    }

#line 53 "lib/sj-lib-common/list.sj"
    sjt_parent99 = &g_glframebuffers;
#line 4
    sjt_parent100 = &g_glframebuffers;
#line 4
    sjf_list_u32_getcount(sjt_parent100, &sjt_capture35);
#line 158 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam156 = sjt_capture35 - 1;
#line 158
    sjf_list_u32_removeat(sjt_parent99, sjt_functionParam156);
#line 4 "lib/sj-lib-common/list.sj"
    sjt_parent101 = &g_glframebuffers;
#line 4
    sjf_list_u32_getcount(sjt_parent101, &sjt_capture36);
    if (sjt_capture36 > 0) {
        int32_t sjt_capture37;
        int32_t sjt_functionParam157;
        sjs_list_u32* sjt_parent102 = 0;
        sjs_list_u32* sjt_parent103 = 0;

#line 8 "lib/sj-lib-common/list.sj"
        sjt_parent102 = &g_glframebuffers;
#line 4
        sjt_parent103 = &g_glframebuffers;
#line 4
        sjf_list_u32_getcount(sjt_parent103, &sjt_capture37);
#line 159 "lib/sj-lib-ui/gl.sj"
        sjt_functionParam157 = sjt_capture37 - 1;
#line 159
        sjf_list_u32_getat(sjt_parent102, sjt_functionParam157, &id);
    } else {
#line 159 "lib/sj-lib-ui/gl.sj"
        id = (uint32_t)0u;
    }

#line 161 "lib/sj-lib-ui/gl.sj"
    glBindFramebuffer(GL_FRAMEBUFFER, id);

    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
}

void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect newrect = { -1 };
    sjs_rect oldrect = { -1 };
    bool result5;
    sjs_string sjt_call10 = { -1 };
    sjs_rect sjt_call9 = { -1 };
    int32_t sjt_capture25;
    bool sjt_capture26;
    int32_t sjt_capture27;
    int32_t sjt_capture28;
    int32_t sjt_functionParam101;
    int32_t sjt_functionParam98;
    sjs_rect* sjt_functionParam99 = 0;
    sjs_rect* sjt_parent71 = 0;
    sjs_list_rect* sjt_parent74 = 0;
    sjs_list_rect* sjt_parent76 = 0;
    sjs_list_rect* sjt_parent77 = 0;
    sjs_list_rect* sjt_parent78 = 0;
    sjs_list_rect* sjt_parent79 = 0;

    oldrect._refCount = 1;
#line 134 "lib/sj-lib-ui/gl.sj"
    oldrect.x = rect->x;
#line 134
    oldrect.y = scenerect->h - (rect->y + rect->h);
#line 134
    oldrect.w = rect->w;
#line 134
    oldrect.h = rect->h;
#line 134
    sjf_rect(&oldrect);
#line 8 "lib/sj-lib-common/list.sj"
    sjt_parent74 = &g_glviewports;
#line 4
    sjt_parent76 = &g_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent76, &sjt_capture25);
#line 135 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam98 = sjt_capture25 - 1;
#line 135
    sjf_list_rect_getat(sjt_parent74, sjt_functionParam98, &sjt_call9);
#line 135
    sjt_parent71 = &sjt_call9;
#line 135
    sjt_functionParam99 = &oldrect;
#line 135
    sjf_rect_isequal(sjt_parent71, sjt_functionParam99, &sjt_capture26);
#line 135
    result5 = !sjt_capture26;
    if (result5) {
        sjs_string* sjt_functionParam100 = 0;

        sjt_call10._refCount = 1;
#line 136 "lib/sj-lib-ui/gl.sj"
        sjt_call10.offset = 0;
#line 136
        sjt_call10.count = 30;
#line 136
        sjt_call10.data._refCount = 1;
#line 136
        sjt_call10.data.v = &sjg_string16;
#line 136
        sjf_array_char(&sjt_call10.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call10._isnullterminated = false;
#line 16
        sjf_string(&sjt_call10);
#line 136 "lib/sj-lib-ui/gl.sj"
        sjt_functionParam100 = &sjt_call10;
#line 136
        sjf_halt(sjt_functionParam100);
    }

#line 53 "lib/sj-lib-common/list.sj"
    sjt_parent77 = &g_glviewports;
#line 4
    sjt_parent78 = &g_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent78, &sjt_capture27);
#line 138 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam101 = sjt_capture27 - 1;
#line 138
    sjf_list_rect_removeat(sjt_parent77, sjt_functionParam101);
#line 4 "lib/sj-lib-common/list.sj"
    sjt_parent79 = &g_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent79, &sjt_capture28);
    if (sjt_capture28 > 0) {
        int32_t sjt_capture29;
        int32_t sjt_functionParam102;
        sjs_list_rect* sjt_parent80 = 0;
        sjs_list_rect* sjt_parent81 = 0;

#line 8 "lib/sj-lib-common/list.sj"
        sjt_parent80 = &g_glviewports;
#line 4
        sjt_parent81 = &g_glviewports;
#line 4
        sjf_list_rect_getcount(sjt_parent81, &sjt_capture29);
#line 139 "lib/sj-lib-ui/gl.sj"
        sjt_functionParam102 = sjt_capture29 - 1;
#line 139
        sjf_list_rect_getat(sjt_parent80, sjt_functionParam102, &newrect);
    } else {
        newrect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
        newrect.x = 0;
#line 3
        newrect.y = 0;
#line 4
        newrect.w = 0;
#line 5
        newrect.h = 0;
#line 5
        sjf_rect(&newrect);
    }

#line 141 "lib/sj-lib-ui/gl.sj"
    glViewport(newrect.x, newrect.y, newrect.w, newrect.h);

    if (newrect._refCount == 1) { sjf_rect_destroy(&newrect); }
;
    if (oldrect._refCount == 1) { sjf_rect_destroy(&oldrect); }
;
    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
;
    if (sjt_call9._refCount == 1) { sjf_rect_destroy(&sjt_call9); }
;
}

void sjf_glpushframebuffer(sjs_framebuffer* framebuffer) {
    uint32_t sjt_functionParam121;
    sjs_list_u32* sjt_parent94 = 0;

#line 44 "lib/sj-lib-common/list.sj"
    sjt_parent94 = &g_glframebuffers;
#line 148 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam121 = framebuffer->id;
#line 148
    sjf_list_u32_add(sjt_parent94, sjt_functionParam121);
#line 150
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->id);
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect newrect = { -1 };
    sjs_rect* sjt_functionParam64 = 0;
    sjs_list_rect* sjt_parent58 = 0;

    newrect._refCount = 1;
#line 126 "lib/sj-lib-ui/gl.sj"
    newrect.x = rect->x;
#line 126
    newrect.y = scenerect->h - (rect->y + rect->h);
#line 126
    newrect.w = rect->w;
#line 126
    newrect.h = rect->h;
#line 126
    sjf_rect(&newrect);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_parent58 = &g_glviewports;
#line 127 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam64 = &newrect;
#line 127
    sjf_list_rect_add(sjt_parent58, sjt_functionParam64);
#line 129
    glViewport(newrect.x, newrect.y, newrect.w, newrect.h);

    if (newrect._refCount == 1) { sjf_rect_destroy(&newrect); }
;
}

void sjf_glrenderbufferstorage(int32_t format, sjs_size* size) {
#line 252 "lib/sj-lib-ui/gl.sj"
    glRenderbufferStorage(GL_RENDERBUFFER, format, size->w, size->h);
}

void sjf_glteximage2d(int32_t t, int32_t level, int32_t format, sjs_size* size, int32_t datatype, void* data) {
#line 232 "lib/sj-lib-ui/gl.sj"
    glTexImage2D(t, level, format, size->w, size->h, 0, format, datatype, data);
}

void sjf_gltexparameteri(int32_t t, int32_t attribute, int32_t val) {
#line 226 "lib/sj-lib-ui/gl.sj"
    glTexParameteri(t, attribute, val);
}

void sjf_gluniformi32(int32_t loc, int32_t v) {
#line 198 "lib/sj-lib-ui/gl.sj"
    glUniform1i(loc, v);
}

void sjf_gluniformmat4(int32_t loc, sjs_mat4* m) {
#line 186 "lib/sj-lib-ui/gl.sj"
    glUniformMatrix4fv(loc, 1, 0, (GLfloat*)&m->m00);
}

void sjf_gluniformvec3(int32_t loc, sjs_vec3* v) {
#line 192 "lib/sj-lib-ui/gl.sj"
    glUniform3fv(loc, 1, (GLfloat*)&v->x);
}

void sjf_gluseprogram(sjs_shader* shader) {
#line 167 "lib/sj-lib-ui/gl.sj"
    glUseProgram(shader->id);
}

void sjf_halt(sjs_string* reason) {
#line 3 "lib/sj-lib-common/halt.sj"
    halt("%s\n", string_char(reason));
}

void sjf_hash_fontkey_weak_font(sjs_hash_fontkey_weak_font* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(fontkey_weak_font_hash_type);
}

void sjf_hash_fontkey_weak_font__weakptrremovekey(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key) {
#line 188 "lib/sj-lib-common/hash.sj"
    #if false
#line 189
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;    
#line 190
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, key);
#line 191
    if (k != kh_end(p)) {
#line 192
        kh_del(fontkey_weak_font_hash_type, p, k);
#line 193
    }
#line 194
    #endif
}

void sjf_hash_fontkey_weak_font__weakptrremovevalue(sjs_hash_fontkey_weak_font* _parent, sjs_font* val) {
#line 200 "lib/sj-lib-common/hash.sj"
    #if true
#line 201
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;
#line 202
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 203
        if (kh_exist(p, k)) {
#line 204
            sjs_font* t = kh_value(p, k);
#line 205
            if (t == val) {
#line 206
                kh_del(fontkey_weak_font_hash_type, p, k);
#line 207
            }
#line 208
        }
#line 209
    }
#line 210
    #endif
}

void sjf_hash_fontkey_weak_font_copy(sjs_hash_fontkey_weak_font* _this, sjs_hash_fontkey_weak_font* _from) {
#line 238 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 239
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_this->_hash;
#line 240
    p->refcount++;
}

void sjf_hash_fontkey_weak_font_destroy(sjs_hash_fontkey_weak_font* _this) {
#line 244 "lib/sj-lib-common/hash.sj"
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_this->_hash;
#line 245
    p->refcount--;
#line 246
    if (p->refcount == 0) {
#line 247
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 248
            if (kh_exist(p, k)) {
#line 250
                #if false
#line 251
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovekey };
#line 252
                weakptr_cb_remove(kh_key(p, k), cb);
#line 253
                #else
#line 254
                ;
#line 255
                #endif
#line 257
                #if true
#line 258
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovevalue };
#line 259
                weakptr_cb_remove(kh_value(p, k), cb);
#line 260
                #else
#line 261
                delete_cb weakptrcb11 = { &kh_value(p, k), weakptr_clear };
if (kh_value(p, k) != 0) { weakptr_cb_remove(kh_value(p, k), weakptrcb11); }
;
#line 262
                #endif
#line 263
            }
#line 264
        }
#line 265
        kh_destroy(fontkey_weak_font_hash_type, (khash_t(fontkey_weak_font_hash_type)*)_this->_hash);
#line 266
    }
}

void sjf_hash_fontkey_weak_font_heap(sjs_hash_fontkey_weak_font* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(fontkey_weak_font_hash_type);
}

void sjf_hash_string_weak_iface_element(sjs_hash_string_weak_iface_element* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_element_hash_type);
}

void sjf_hash_string_weak_iface_element__weakptrremovekey(sjs_hash_string_weak_iface_element* _parent, sjs_string* key) {
#line 188 "lib/sj-lib-common/hash.sj"
    #if false
#line 189
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;    
#line 190
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, key);
#line 191
    if (k != kh_end(p)) {
#line 192
        kh_del(string_weak_iface_element_hash_type, p, k);
#line 193
    }
#line 194
    #endif
}

void sjf_hash_string_weak_iface_element__weakptrremovevalue(sjs_hash_string_weak_iface_element* _parent, sji_element val) {
#line 200 "lib/sj-lib-common/hash.sj"
    #if true
#line 201
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;
#line 202
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 203
        if (kh_exist(p, k)) {
#line 204
            sji_element t = kh_value(p, k);
#line 205
            if (t._parent == val._parent) {
#line 206
                kh_del(string_weak_iface_element_hash_type, p, k);
#line 207
            }
#line 208
        }
#line 209
    }
#line 210
    #endif
}

void sjf_hash_string_weak_iface_element_copy(sjs_hash_string_weak_iface_element* _this, sjs_hash_string_weak_iface_element* _from) {
#line 238 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 239
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_this->_hash;
#line 240
    p->refcount++;
}

void sjf_hash_string_weak_iface_element_destroy(sjs_hash_string_weak_iface_element* _this) {
#line 244 "lib/sj-lib-common/hash.sj"
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_this->_hash;
#line 245
    p->refcount--;
#line 246
    if (p->refcount == 0) {
#line 247
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 248
            if (kh_exist(p, k)) {
#line 250
                #if false
#line 251
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovekey };
#line 252
                weakptr_cb_remove(kh_key(p, k), cb);
#line 253
                #else
#line 254
                ;
#line 255
                #endif
#line 257
                #if true
#line 258
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovevalue };
#line 259
                weakptr_cb_remove(kh_value(p, k)._parent, cb);
#line 260
                #else
#line 261
                delete_cb weakptrcb10 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb10); }
;
#line 262
                #endif
#line 263
            }
#line 264
        }
#line 265
        kh_destroy(string_weak_iface_element_hash_type, (khash_t(string_weak_iface_element_hash_type)*)_this->_hash);
#line 266
    }
}

void sjf_hash_string_weak_iface_element_heap(sjs_hash_string_weak_iface_element* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_element_hash_type);
}

void sjf_hash_string_weak_iface_model(sjs_hash_string_weak_iface_model* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_model_hash_type);
}

void sjf_hash_string_weak_iface_model__weakptrremovekey(sjs_hash_string_weak_iface_model* _parent, sjs_string* key) {
#line 188 "lib/sj-lib-common/hash.sj"
    #if false
#line 189
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;    
#line 190
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, key);
#line 191
    if (k != kh_end(p)) {
#line 192
        kh_del(string_weak_iface_model_hash_type, p, k);
#line 193
    }
#line 194
    #endif
}

void sjf_hash_string_weak_iface_model__weakptrremovevalue(sjs_hash_string_weak_iface_model* _parent, sji_model val) {
#line 200 "lib/sj-lib-common/hash.sj"
    #if true
#line 201
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;
#line 202
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 203
        if (kh_exist(p, k)) {
#line 204
            sji_model t = kh_value(p, k);
#line 205
            if (t._parent == val._parent) {
#line 206
                kh_del(string_weak_iface_model_hash_type, p, k);
#line 207
            }
#line 208
        }
#line 209
    }
#line 210
    #endif
}

void sjf_hash_string_weak_iface_model_copy(sjs_hash_string_weak_iface_model* _this, sjs_hash_string_weak_iface_model* _from) {
#line 238 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 239
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_this->_hash;
#line 240
    p->refcount++;
}

void sjf_hash_string_weak_iface_model_destroy(sjs_hash_string_weak_iface_model* _this) {
#line 244 "lib/sj-lib-common/hash.sj"
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_this->_hash;
#line 245
    p->refcount--;
#line 246
    if (p->refcount == 0) {
#line 247
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 248
            if (kh_exist(p, k)) {
#line 250
                #if false
#line 251
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovekey };
#line 252
                weakptr_cb_remove(kh_key(p, k), cb);
#line 253
                #else
#line 254
                ;
#line 255
                #endif
#line 257
                #if true
#line 258
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovevalue };
#line 259
                weakptr_cb_remove(kh_value(p, k)._parent, cb);
#line 260
                #else
#line 261
                delete_cb weakptrcb9 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb9); }
;
#line 262
                #endif
#line 263
            }
#line 264
        }
#line 265
        kh_destroy(string_weak_iface_model_hash_type, (khash_t(string_weak_iface_model_hash_type)*)_this->_hash);
#line 266
    }
}

void sjf_hash_string_weak_iface_model_heap(sjs_hash_string_weak_iface_model* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_model_hash_type);
}

void sjf_hash_string_weak_iface_model_setat(sjs_hash_string_weak_iface_model* _parent, sjs_string* key, sji_model val) {
#line 40 "lib/sj-lib-common/hash.sj"
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
k = kh_put(string_weak_iface_model_hash_type, p, *key, &ret);
#line 55
#else
#line 56
k = kh_put(string_weak_iface_model_hash_type, p, key, &ret);
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
#line 38 "lib/sj-lib-common/hash.sj"
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
#line 38 "lib/sj-lib-common/hash.sj"
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
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
#line 188 "lib/sj-lib-common/hash.sj"
    #if false
#line 189
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;    
#line 190
    khiter_t k = kh_get(type_bool_hash_type, p, key);
#line 191
    if (k != kh_end(p)) {
#line 192
        kh_del(type_bool_hash_type, p, k);
#line 193
    }
#line 194
    #endif
}

void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val) {
#line 200 "lib/sj-lib-common/hash.sj"
    #if false
#line 201
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
#line 202
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 203
        if (kh_exist(p, k)) {
#line 204
            bool t = kh_value(p, k);
#line 205
            if (t == val) {
#line 206
                kh_del(type_bool_hash_type, p, k);
#line 207
            }
#line 208
        }
#line 209
    }
#line 210
    #endif
}

void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from) {
#line 238 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 239
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 240
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
#line 244 "lib/sj-lib-common/hash.sj"
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 245
    p->refcount--;
#line 246
    if (p->refcount == 0) {
#line 247
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 248
            if (kh_exist(p, k)) {
#line 250
                #if false
#line 251
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovekey };
#line 252
                weakptr_cb_remove(kh_key(p, k), cb);
#line 253
                #else
#line 254
                ;
#line 255
                #endif
#line 257
                #if false
#line 258
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovevalue };
#line 259
                weakptr_cb_remove(kh_value(p, k), cb);
#line 260
                #else
#line 261
                ;
#line 262
                #endif
#line 263
            }
#line 264
        }
#line 265
        kh_destroy(type_bool_hash_type, (khash_t(type_bool_hash_type)*)_this->_hash);
#line 266
    }
}

void sjf_hash_type_bool_getat(sjs_hash_type_bool* _parent, int32_t key, bool_option* _return) {
#line 23 "lib/sj-lib-common/hash.sj"
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
        #line 22 "lib/sj-lib-common/hash.sj"
(*_return) = bool_empty;
return;
#line 33
    }
#line 34
    #line 22 "lib/sj-lib-common/hash.sj"
_return->isvalid = true;
#line 22
_return->value = kh_val(p, k);
return;;
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t count;
    void* vresult;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    vresult = 0;
#line 26
    sjs_array* arr = createarray(1, 256);
#line 27
    vresult = (void*)arr;
#line 28
    char *tmp = (char*)arr->data + 128;
#line 29
    char *tp = (char*)arr->data + 128;
#line 30
    int i;
#line 31
    unsigned v;
#line 33
    int sign = (base == 10 && val < 0);    
#line 34
    if (sign)
#line 35
    v = -val;
#line 36
    else
#line 37
    v = (unsigned)val;
#line 39
    while (v || tp == tmp)
#line 40
    {
#line 41
        i = v % base;
#line 42
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 43
        if (i < 10)
#line 44
        *tp++ = i + '0';
#line 45
        else
#line 46
        *tp++ = i + 'a' - 10;
#line 47
    }
#line 49
    int len = tp - tmp;
#line 51
    char* sp = (char*)arr->data;
#line 52
    if (sign) 
#line 53
    {
#line 54
        *sp++ = '-';
#line 55
        len++;
#line 56
    }
#line 58
    while (tp > tmp)
#line 59
    *sp++ = *--tp;
#line 61
    arr->count = len;
#line 62
    count = len;
#line 62
    _return->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    _return->offset = 0;
#line 64 "lib/sj-lib-common/i32.sj"
    _return->count = count;
#line 64
    _return->data._refCount = 1;
#line 64
    _return->data.v = vresult;
#line 64
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t count;
    void* vresult;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    vresult = 0;
#line 26
    sjs_array* arr = createarray(1, 256);
#line 27
    vresult = (void*)arr;
#line 28
    char *tmp = (char*)arr->data + 128;
#line 29
    char *tp = (char*)arr->data + 128;
#line 30
    int i;
#line 31
    unsigned v;
#line 33
    int sign = (base == 10 && val < 0);    
#line 34
    if (sign)
#line 35
    v = -val;
#line 36
    else
#line 37
    v = (unsigned)val;
#line 39
    while (v || tp == tmp)
#line 40
    {
#line 41
        i = v % base;
#line 42
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 43
        if (i < 10)
#line 44
        *tp++ = i + '0';
#line 45
        else
#line 46
        *tp++ = i + 'a' - 10;
#line 47
    }
#line 49
    int len = tp - tmp;
#line 51
    char* sp = (char*)arr->data;
#line 52
    if (sign) 
#line 53
    {
#line 54
        *sp++ = '-';
#line 55
        len++;
#line 56
    }
#line 58
    while (tp > tmp)
#line 59
    *sp++ = *--tp;
#line 61
    arr->count = len;
#line 62
    count = len;
#line 62
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 62
    (*_return)->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    (*_return)->offset = 0;
#line 64 "lib/sj-lib-common/i32.sj"
    (*_return)->count = count;
#line 64
    (*_return)->data._refCount = 1;
#line 64
    (*_return)->data.v = vresult;
#line 64
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    if (a < b) {
#line 6 "lib/sj-lib-common/i32.sj"
        (*_return) = b;
    } else {
#line 6 "lib/sj-lib-common/i32.sj"
        (*_return) = a;
    }
}

void sjf_image(sjs_image* _this) {
    sjs_size size = { -1 };
    bool sjt_capture81;
    sjs_rect sjt_funcold21 = { -1 };

    if ((&_this->rect)->w == 0) {
#line 6 "lib/sj-lib-ui/image.sj"
        sjt_capture81 = ((&_this->rect)->h == 0);
    } else {
#line 6 "lib/sj-lib-ui/image.sj"
        sjt_capture81 = false;
    }

    if (sjt_capture81) {
        sjs_texture* sjt_parent288 = 0;

#line 1 "lib/sj-lib-ui/image.sj"
        sjt_parent288 = &_this->texture;
#line 1
        sjf_texture_getsize(sjt_parent288, &size);
#line 1
        sjt_funcold21._refCount = 1;
#line 8
        sjt_funcold21.x = 0;
#line 8
        sjt_funcold21.y = 0;
#line 8
        sjt_funcold21.w = (&size)->w;
#line 8
        sjt_funcold21.h = (&size)->h;
#line 8
        sjf_rect(&sjt_funcold21);
#line 8
        if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
#line 1 "lib/sj-lib-ui/rect.sj"
        sjf_rect_copy(&_this->rect, &sjt_funcold21);
    }

    if (size._refCount == 1) { sjf_size_destroy(&size); }
;
    if (sjt_funcold21._refCount == 1) { sjf_rect_destroy(&sjt_funcold21); }
;
}

void sjf_image_copy(sjs_image* _this, sjs_image* _from) {
    _this->texture._refCount = 1;
#line 1 "lib/sj-lib-ui/image.sj"
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
    sjs_size size = { -1 };
    bool sjt_capture82;
    sjs_rect sjt_funcold22 = { -1 };

    if ((&_this->rect)->w == 0) {
#line 6 "lib/sj-lib-ui/image.sj"
        sjt_capture82 = ((&_this->rect)->h == 0);
    } else {
#line 6 "lib/sj-lib-ui/image.sj"
        sjt_capture82 = false;
    }

    if (sjt_capture82) {
        sjs_texture* sjt_parent289 = 0;

#line 5 "lib/sj-lib-ui/texture.sj"
        sjt_parent289 = &_this->texture;
#line 5
        sjf_texture_getsize(sjt_parent289, &size);
#line 5
        sjt_funcold22._refCount = 1;
#line 8 "lib/sj-lib-ui/image.sj"
        sjt_funcold22.x = 0;
#line 8
        sjt_funcold22.y = 0;
#line 8
        sjt_funcold22.w = (&size)->w;
#line 8
        sjt_funcold22.h = (&size)->h;
#line 8
        sjf_rect(&sjt_funcold22);
#line 8
        if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
#line 1 "lib/sj-lib-ui/rect.sj"
        sjf_rect_copy(&_this->rect, &sjt_funcold22);
    }

    if (size._refCount == 1) { sjf_size_destroy(&size); }
;
    if (sjt_funcold22._refCount == 1) { sjf_rect_destroy(&sjt_funcold22); }
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
#line 7 "lib/sj-lib-ui/imageElement.sj"
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
#line 7 "lib/sj-lib-ui/imageElement.sj"
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
#line 74 "lib/sj-lib-ui/imageElement.sj"
    (*_return) = true;
}

void sjf_imageelement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 259;
}

void sjf_imageelement_getrect(sjs_imageelement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 18 "lib/sj-lib-ui/imageElement.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_imageelement_getrect_heap(sjs_imageelement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 18 "lib/sj-lib-ui/imageElement.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_imageelement_getsize(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 15 "lib/sj-lib-ui/imageElement.sj"
    _return->w = maxsize->w;
#line 15
    _return->h = maxsize->h;
#line 15
    sjf_size(_return);
}

void sjf_imageelement_getsize_heap(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 15 "lib/sj-lib-ui/imageElement.sj"
    (*_return)->w = maxsize->w;
#line 15
    (*_return)->h = maxsize->h;
#line 15
    sjf_size_heap((*_return));
}

void sjf_imageelement_heap(sjs_imageelement* _this) {
}

void sjf_imageelement_render(sjs_imageelement* _parent, sjs_scene2d* scene) {
    sjs_rect r = { -1 };
    sjs_imagerenderer sjt_value12 = { -1 };

    if ((_parent->_imagerenderer._refCount != -1 ? &_parent->_imagerenderer : 0) == 0) {
        sjs_margin* sjt_functionParam440 = 0;
        sjs_rect* sjt_parent291 = 0;
        int32_t underscore3;

#line 7 "lib/sj-lib-ui/rect.sj"
        sjt_parent291 = &_parent->_rect;
#line 30 "lib/sj-lib-ui/imageElement.sj"
        sjt_functionParam440 = &_parent->margin;
#line 30
        sjf_rect_subtractmargin(sjt_parent291, sjt_functionParam440, &r);
#line 31
        underscore3 = _parent->stretch;
        if (underscore3 == g_imagestretch_fill) {
        } else {
            if (underscore3 == g_imagestretch_center) {
                sjs_size finalsize = { -1 };
                sjs_size s = { -1 };
                sjs_size sjt_call113 = { -1 };
                sjs_rect sjt_funcold23 = { -1 };
                sjs_size* sjt_functionParam441 = 0;
                sjs_size* sjt_parent292 = 0;
                sjs_texture* sjt_parent293 = 0;

                s._refCount = 1;
#line 34 "lib/sj-lib-ui/imageElement.sj"
                s.w = (&r)->w;
#line 34
                s.h = (&r)->h;
#line 34
                sjf_size(&s);
#line 5 "lib/sj-lib-ui/size.sj"
                sjt_parent292 = &s;
#line 5 "lib/sj-lib-ui/texture.sj"
                sjt_parent293 = &(&_parent->image)->texture;
#line 5
                sjf_texture_getsize(sjt_parent293, &sjt_call113);
#line 35 "lib/sj-lib-ui/imageElement.sj"
                sjt_functionParam441 = &sjt_call113;
#line 35
                sjf_size_min(sjt_parent292, sjt_functionParam441, &finalsize);
#line 35
                sjt_funcold23._refCount = 1;
#line 37
                sjt_funcold23.x = ((&r)->w - (&finalsize)->w) / 2;
#line 38
                sjt_funcold23.y = ((&r)->h - (&finalsize)->h) / 2;
#line 36
                sjt_funcold23.w = (&finalsize)->w;
#line 36
                sjt_funcold23.h = (&finalsize)->h;
#line 36
                sjf_rect(&sjt_funcold23);
#line 36
                if (r._refCount == 1) { sjf_rect_destroy(&r); }
;
#line 1 "lib/sj-lib-ui/rect.sj"
                sjf_rect_copy(&r, &sjt_funcold23);

                if (finalsize._refCount == 1) { sjf_size_destroy(&finalsize); }
;
                if (s._refCount == 1) { sjf_size_destroy(&s); }
;
                if (sjt_call113._refCount == 1) { sjf_size_destroy(&sjt_call113); }
;
                if (sjt_funcold23._refCount == 1) { sjf_rect_destroy(&sjt_funcold23); }
;
            } else {
                if (underscore3 == g_imagestretch_aspectratio) {
                    sjs_size finalsize = { -1 };
                    float imageaspectratio;
                    float rectaspectratio;
                    sjs_size sjt_call114 = { -1 };
                    sjs_size sjt_call115 = { -1 };
                    int32_t sjt_cast40;
                    int32_t sjt_cast41;
                    int32_t sjt_cast42;
                    int32_t sjt_cast43;
                    sjs_rect sjt_funcold24 = { -1 };
                    sjs_texture* sjt_parent294 = 0;
                    sjs_texture* sjt_parent295 = 0;

#line 5 "lib/sj-lib-ui/texture.sj"
                    sjt_parent294 = &(&_parent->image)->texture;
#line 5
                    sjf_texture_getsize(sjt_parent294, &sjt_call114);
#line 45 "lib/sj-lib-ui/imageElement.sj"
                    sjt_cast40 = (&sjt_call114)->w;
#line 5 "lib/sj-lib-ui/texture.sj"
                    sjt_parent295 = &(&_parent->image)->texture;
#line 5
                    sjf_texture_getsize(sjt_parent295, &sjt_call115);
#line 45 "lib/sj-lib-ui/imageElement.sj"
                    sjt_cast41 = (&sjt_call115)->h;
#line 45
                    imageaspectratio = (float)sjt_cast40 / (float)sjt_cast41;
#line 46
                    sjt_cast42 = (&r)->w;
#line 46
                    sjt_cast43 = (&r)->h;
#line 46
                    rectaspectratio = (float)sjt_cast42 / (float)sjt_cast43;
                    if (imageaspectratio > rectaspectratio) {
                        float sjt_cast44;
                        int32_t sjt_cast45;

                        finalsize._refCount = 1;
#line 48 "lib/sj-lib-ui/imageElement.sj"
                        finalsize.w = (&r)->w;
#line 48
                        sjt_cast45 = (&r)->h;
#line 48
                        sjt_cast44 = (float)sjt_cast45 / imageaspectratio;
#line 48
                        finalsize.h = (int32_t)sjt_cast44;
#line 48
                        sjf_size(&finalsize);
                    } else {
                        float sjt_cast46;
                        int32_t sjt_cast47;

                        finalsize._refCount = 1;
#line 50 "lib/sj-lib-ui/imageElement.sj"
                        sjt_cast47 = (&r)->w;
#line 50
                        sjt_cast46 = (float)sjt_cast47 * imageaspectratio;
#line 50
                        finalsize.w = (int32_t)sjt_cast46;
#line 50
                        finalsize.h = (&r)->h;
#line 50
                        sjf_size(&finalsize);
                    }

#line 46
                    sjt_funcold24._refCount = 1;
#line 53
                    sjt_funcold24.x = ((&r)->w - (&finalsize)->w) / 2;
#line 54
                    sjt_funcold24.y = ((&r)->h - (&finalsize)->h) / 2;
#line 52
                    sjt_funcold24.w = (&finalsize)->w;
#line 52
                    sjt_funcold24.h = (&finalsize)->h;
#line 52
                    sjf_rect(&sjt_funcold24);
#line 52
                    if (r._refCount == 1) { sjf_rect_destroy(&r); }
;
#line 1 "lib/sj-lib-ui/rect.sj"
                    sjf_rect_copy(&r, &sjt_funcold24);

                    if (finalsize._refCount == 1) { sjf_size_destroy(&finalsize); }
;
                    if (sjt_call114._refCount == 1) { sjf_size_destroy(&sjt_call114); }
;
                    if (sjt_call115._refCount == 1) { sjf_size_destroy(&sjt_call115); }
;
                    if (sjt_funcold24._refCount == 1) { sjf_rect_destroy(&sjt_funcold24); }
;
                }
            }
        }

#line 31
        sjt_value12._refCount = 1;
#line 31
        sjt_value12.rect._refCount = 1;
#line 62
        sjf_rect_copy(&sjt_value12.rect, &r);
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
#line 62 "lib/sj-lib-ui/imageElement.sj"
            sjf_imagerenderer_copy(&_parent->_imagerenderer, copyoption23);
        } else {
            _parent->_imagerenderer._refCount = -1;
        }
    }

    if ((_parent->_imagerenderer._refCount != -1 ? &_parent->_imagerenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam463 = 0;
        sjs_imagerenderer* sjt_parent296 = 0;

#line 8 "lib/sj-lib-ui/imageRenderer.sj"
        sjt_parent296 = (_parent->_imagerenderer._refCount != -1 ? &_parent->_imagerenderer : 0);
#line 28 "lib/sj-lib-ui/imageElement.sj"
        sjt_functionParam463 = scene;
#line 28
        sjf_imagerenderer_render(sjt_parent296, sjt_functionParam463);
    }

    if (r._refCount == 1) { sjf_rect_destroy(&r); }
;
    if (sjt_value12._refCount == 1) { sjf_imagerenderer_destroy(&sjt_value12); }
;
}

void sjf_imageelement_setrect(sjs_imageelement* _parent, sjs_rect* rect_) {
    bool result11;
    bool sjt_capture83;
    sjs_rect* sjt_functionParam439 = 0;
    sjs_rect* sjt_parent290 = 0;

#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent290 = &_parent->_rect;
#line 20 "lib/sj-lib-ui/imageElement.sj"
    sjt_functionParam439 = rect_;
#line 20
    sjf_rect_isequal(sjt_parent290, sjt_functionParam439, &sjt_capture83);
#line 21
    result11 = !sjt_capture83;
    if (result11) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 20 "lib/sj-lib-ui/imageElement.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
#line 20
        if (_parent->_imagerenderer._refCount == 1) { sjf_imagerenderer_destroy(&_parent->_imagerenderer); }
;
#line 23
        _parent->_imagerenderer._refCount = -1;
    }
}

void sjf_imagerenderer(sjs_imagerenderer* _this) {
#line 23 "lib/sj-lib-ui/imageRenderer.sj"
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
#line 1 "lib/sj-lib-ui/imageRenderer.sj"
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
#line 185 "lib/sj-lib-ui/imageRenderer.sj"
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
#line 23 "lib/sj-lib-ui/imageRenderer.sj"
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
    sjs_string sjt_call116 = { -1 };
    sjs_string sjt_call117 = { -1 };
    sjs_string sjt_call118 = { -1 };
    sjs_string sjt_call119 = { -1 };
    int32_t sjt_functionParam442;
    sjs_texture* sjt_functionParam443 = 0;
    sjs_shader* sjt_functionParam444 = 0;
    int32_t sjt_functionParam445;
    int32_t sjt_functionParam446;
    int32_t sjt_functionParam447;
    sjs_shader* sjt_functionParam448 = 0;
    sjs_string* sjt_functionParam449 = 0;
    int32_t sjt_functionParam450;
    int32_t sjt_functionParam451;
    sjs_shader* sjt_functionParam452 = 0;
    sjs_string* sjt_functionParam453 = 0;
    sjs_mat4* sjt_functionParam454 = 0;
    int32_t sjt_functionParam455;
    sjs_shader* sjt_functionParam456 = 0;
    sjs_string* sjt_functionParam457 = 0;
    sjs_mat4* sjt_functionParam458 = 0;
    int32_t sjt_functionParam459;
    sjs_shader* sjt_functionParam460 = 0;
    sjs_string* sjt_functionParam461 = 0;
    sjs_mat4* sjt_functionParam462 = 0;

#line 9 "lib/sj-lib-ui/imageRenderer.sj"
    sjt_functionParam442 = g_gltexture_gl_texture_2d;
#line 9
    sjt_functionParam443 = &(&_parent->image)->texture;
#line 9
    sjf_glbindtexture(sjt_functionParam442, sjt_functionParam443);
#line 10
    sjt_functionParam444 = &g_imageshader;
#line 10
    sjf_gluseprogram(sjt_functionParam444);
#line 11
    sjt_functionParam445 = g_glblendfunctype_gl_src_alpha;
#line 11
    sjt_functionParam446 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 11
    sjf_glblendfunc(sjt_functionParam445, sjt_functionParam446);
#line 12
    sjt_functionParam448 = &g_imageshader;
#line 12
    sjt_call116._refCount = 1;
#line 12
    sjt_call116.offset = 0;
#line 12
    sjt_call116.count = 7;
#line 12
    sjt_call116.data._refCount = 1;
#line 12
    sjt_call116.data.v = &sjg_string42;
#line 12
    sjf_array_char(&sjt_call116.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call116._isnullterminated = false;
#line 16
    sjf_string(&sjt_call116);
#line 12 "lib/sj-lib-ui/imageRenderer.sj"
    sjt_functionParam449 = &sjt_call116;
#line 12
    sjf_glgetuniformlocation(sjt_functionParam448, sjt_functionParam449, &sjt_functionParam447);
#line 12
    sjt_functionParam450 = 0;
#line 12
    sjf_gluniformi32(sjt_functionParam447, sjt_functionParam450);
#line 13
    sjt_functionParam452 = &g_imageshader;
#line 13
    sjt_call117._refCount = 1;
#line 13
    sjt_call117.offset = 0;
#line 13
    sjt_call117.count = 5;
#line 13
    sjt_call117.data._refCount = 1;
#line 13
    sjt_call117.data.v = &sjg_string43;
#line 13
    sjf_array_char(&sjt_call117.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call117._isnullterminated = false;
#line 16
    sjf_string(&sjt_call117);
#line 13 "lib/sj-lib-ui/imageRenderer.sj"
    sjt_functionParam453 = &sjt_call117;
#line 13
    sjf_glgetuniformlocation(sjt_functionParam452, sjt_functionParam453, &sjt_functionParam451);
#line 13
    sjt_functionParam454 = &scene->model;
#line 13
    sjf_gluniformmat4(sjt_functionParam451, sjt_functionParam454);
#line 14
    sjt_functionParam456 = &g_imageshader;
#line 14
    sjt_call118._refCount = 1;
#line 14
    sjt_call118.offset = 0;
#line 14
    sjt_call118.count = 4;
#line 14
    sjt_call118.data._refCount = 1;
#line 14
    sjt_call118.data.v = &sjg_string44;
#line 14
    sjf_array_char(&sjt_call118.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call118._isnullterminated = false;
#line 16
    sjf_string(&sjt_call118);
#line 14 "lib/sj-lib-ui/imageRenderer.sj"
    sjt_functionParam457 = &sjt_call118;
#line 14
    sjf_glgetuniformlocation(sjt_functionParam456, sjt_functionParam457, &sjt_functionParam455);
#line 14
    sjt_functionParam458 = &scene->view;
#line 14
    sjf_gluniformmat4(sjt_functionParam455, sjt_functionParam458);
#line 15
    sjt_functionParam460 = &g_imageshader;
#line 15
    sjt_call119._refCount = 1;
#line 15
    sjt_call119.offset = 0;
#line 15
    sjt_call119.count = 10;
#line 15
    sjt_call119.data._refCount = 1;
#line 15
    sjt_call119.data.v = &sjg_string20;
#line 15
    sjf_array_char(&sjt_call119.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call119._isnullterminated = false;
#line 16
    sjf_string(&sjt_call119);
#line 15 "lib/sj-lib-ui/imageRenderer.sj"
    sjt_functionParam461 = &sjt_call119;
#line 15
    sjf_glgetuniformlocation(sjt_functionParam460, sjt_functionParam461, &sjt_functionParam459);
#line 15
    sjt_functionParam462 = &scene->projection;
#line 15
    sjf_gluniformmat4(sjt_functionParam459, sjt_functionParam462);
#line 17
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);

    if (sjt_call116._refCount == 1) { sjf_string_destroy(&sjt_call116); }
;
    if (sjt_call117._refCount == 1) { sjf_string_destroy(&sjt_call117); }
;
    if (sjt_call118._refCount == 1) { sjf_string_destroy(&sjt_call118); }
;
    if (sjt_call119._refCount == 1) { sjf_string_destroy(&sjt_call119); }
;
}

void sjf_intersecttriangle(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3* _return) {
    float det;
    sjs_vec3 edge1 = { -1 };
    sjs_vec3 edge2 = { -1 };
    sjs_vec3 pvec = { -1 };
    sjs_vec3 qvec = { -1 };
    sjs_vec3* sjt_functionParam247 = 0;
    sjs_vec3* sjt_functionParam248 = 0;
    sjs_vec3* sjt_functionParam249 = 0;
    sjs_vec3* sjt_functionParam250 = 0;
    sjs_vec3* sjt_parent159 = 0;
    sjs_vec3* sjt_parent160 = 0;
    sjs_vec3* sjt_parent161 = 0;
    sjs_vec3* sjt_parent162 = 0;
    sjs_vec3 sjt_value2 = { -1 };
    sjs_vec3 tvec = { -1 };

#line 135 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_parent159 = v1;
#line 135
    sjt_functionParam247 = v0;
#line 135
    sjf_vec3_subtract(sjt_parent159, sjt_functionParam247, &edge1);
#line 135
    sjt_parent160 = v2;
#line 135
    sjt_functionParam248 = v0;
#line 135
    sjf_vec3_subtract(sjt_parent160, sjt_functionParam248, &edge2);
#line 135
    sjt_parent161 = dir;
#line 139
    sjt_functionParam249 = &edge2;
#line 139
    sjf_vec3_cross(sjt_parent161, sjt_functionParam249, &pvec);
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent162 = &edge1;
#line 140 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_functionParam250 = &pvec;
#line 140
    sjf_vec3_dot(sjt_parent162, sjt_functionParam250, &det);
    if (det > 0.0f) {
        sjs_vec3* sjt_functionParam251 = 0;
        sjs_vec3* sjt_parent163 = 0;

#line 135 "lib/sj-lib-ui/vertexBuffer.sj"
        sjt_parent163 = orig;
#line 135
        sjt_functionParam251 = v0;
#line 135
        sjf_vec3_subtract(sjt_parent163, sjt_functionParam251, &tvec);
    } else {
        sjs_vec3* sjt_functionParam252 = 0;
        sjs_vec3* sjt_parent164 = 0;

#line 144 "lib/sj-lib-ui/vertexBuffer.sj"
        det = 0.0f - det;
#line 135
        sjt_parent164 = v0;
#line 135
        sjt_functionParam252 = orig;
#line 135
        sjf_vec3_subtract(sjt_parent164, sjt_functionParam252, &tvec);
    }

    if (det < 0.0001f) {
#line 149 "lib/sj-lib-ui/vertexBuffer.sj"
        _return->_refCount = -1;
    } else {
        sjs_vec3* sjt_functionParam253 = 0;
        sjs_vec3* sjt_parent165 = 0;
        float u;

#line 55 "lib/sj-lib-ui/vec3.sj"
        sjt_parent165 = &tvec;
#line 151 "lib/sj-lib-ui/vertexBuffer.sj"
        sjt_functionParam253 = &pvec;
#line 151
        sjf_vec3_dot(sjt_parent165, sjt_functionParam253, &u);
        if ((u < 0.0f) || (u > det)) {
#line 153 "lib/sj-lib-ui/vertexBuffer.sj"
            _return->_refCount = -1;
        } else {
            sjs_vec3* sjt_functionParam254 = 0;
            sjs_vec3* sjt_functionParam255 = 0;
            sjs_vec3* sjt_parent166 = 0;
            sjs_vec3* sjt_parent167 = 0;
            float v;

#line 47 "lib/sj-lib-ui/vec3.sj"
            sjt_parent166 = &tvec;
#line 155 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam254 = &edge1;
#line 155
            sjf_vec3_cross(sjt_parent166, sjt_functionParam254, &qvec);
#line 135
            sjt_parent167 = dir;
#line 156
            sjt_functionParam255 = &qvec;
#line 156
            sjf_vec3_dot(sjt_parent167, sjt_functionParam255, &v);
            if ((v < 0.0f) || ((u + v) > det)) {
#line 158 "lib/sj-lib-ui/vertexBuffer.sj"
                _return->_refCount = -1;
            } else {
                float finvdet;
                sjs_vec3* sjt_functionParam256 = 0;
                sjs_vec3* sjt_parent168 = 0;
                float t;

#line 55 "lib/sj-lib-ui/vec3.sj"
                sjt_parent168 = &edge2;
#line 161 "lib/sj-lib-ui/vertexBuffer.sj"
                sjt_functionParam256 = &qvec;
#line 161
                sjf_vec3_dot(sjt_parent168, sjt_functionParam256, &t);
#line 162
                finvdet = 1.0f / det;
#line 162
                sjt_value2._refCount = 1;
#line 163
                sjt_value2.x = u * finvdet;
#line 163
                sjt_value2.y = v * finvdet;
#line 163
                sjt_value2.z = t * finvdet;
#line 163
                sjf_vec3(&sjt_value2);
#line 163
                sjs_vec3* copyoption15 = &sjt_value2;
                if (copyoption15 != 0) {
                    _return->_refCount = 1;
#line 163 "lib/sj-lib-ui/vertexBuffer.sj"
                    sjf_vec3_copy(_return, copyoption15);
                } else {
                    _return->_refCount = -1;
                }
            }
        }
    }

    if (edge1._refCount == 1) { sjf_vec3_destroy(&edge1); }
;
    if (edge2._refCount == 1) { sjf_vec3_destroy(&edge2); }
;
    if (pvec._refCount == 1) { sjf_vec3_destroy(&pvec); }
;
    if (qvec._refCount == 1) { sjf_vec3_destroy(&qvec); }
;
    if (sjt_value2._refCount == 1) { sjf_vec3_destroy(&sjt_value2); }
;
    if (tvec._refCount == 1) { sjf_vec3_destroy(&tvec); }
;
}

void sjf_intersecttriangle_heap(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3** _return) {
    float det;
    sjs_vec3 edge1 = { -1 };
    sjs_vec3 edge2 = { -1 };
    sjs_vec3 pvec = { -1 };
    sjs_vec3 qvec = { -1 };
    sjs_vec3* sjt_functionParam257 = 0;
    sjs_vec3* sjt_functionParam258 = 0;
    sjs_vec3* sjt_functionParam259 = 0;
    sjs_vec3* sjt_functionParam260 = 0;
    sjs_vec3* sjt_parent169 = 0;
    sjs_vec3* sjt_parent170 = 0;
    sjs_vec3* sjt_parent171 = 0;
    sjs_vec3* sjt_parent172 = 0;
    sjs_vec3 tvec = { -1 };

#line 135 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_parent169 = v1;
#line 135
    sjt_functionParam257 = v0;
#line 135
    sjf_vec3_subtract(sjt_parent169, sjt_functionParam257, &edge1);
#line 135
    sjt_parent170 = v2;
#line 135
    sjt_functionParam258 = v0;
#line 135
    sjf_vec3_subtract(sjt_parent170, sjt_functionParam258, &edge2);
#line 135
    sjt_parent171 = dir;
#line 139
    sjt_functionParam259 = &edge2;
#line 139
    sjf_vec3_cross(sjt_parent171, sjt_functionParam259, &pvec);
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent172 = &edge1;
#line 140 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_functionParam260 = &pvec;
#line 140
    sjf_vec3_dot(sjt_parent172, sjt_functionParam260, &det);
    if (det > 0.0f) {
        sjs_vec3* sjt_functionParam261 = 0;
        sjs_vec3* sjt_parent173 = 0;

#line 135 "lib/sj-lib-ui/vertexBuffer.sj"
        sjt_parent173 = orig;
#line 135
        sjt_functionParam261 = v0;
#line 135
        sjf_vec3_subtract(sjt_parent173, sjt_functionParam261, &tvec);
    } else {
        sjs_vec3* sjt_functionParam262 = 0;
        sjs_vec3* sjt_parent174 = 0;

#line 144 "lib/sj-lib-ui/vertexBuffer.sj"
        det = 0.0f - det;
#line 135
        sjt_parent174 = v0;
#line 135
        sjt_functionParam262 = orig;
#line 135
        sjf_vec3_subtract(sjt_parent174, sjt_functionParam262, &tvec);
    }

    if (det < 0.0001f) {
#line 149 "lib/sj-lib-ui/vertexBuffer.sj"
        (*_return) = 0;
        if ((*_return) != 0) {
            (*_return)->_refCount++;
        }
    } else {
        sjs_vec3* sjt_functionParam263 = 0;
        sjs_vec3* sjt_parent175 = 0;
        float u;

#line 55 "lib/sj-lib-ui/vec3.sj"
        sjt_parent175 = &tvec;
#line 151 "lib/sj-lib-ui/vertexBuffer.sj"
        sjt_functionParam263 = &pvec;
#line 151
        sjf_vec3_dot(sjt_parent175, sjt_functionParam263, &u);
        if ((u < 0.0f) || (u > det)) {
#line 153 "lib/sj-lib-ui/vertexBuffer.sj"
            (*_return) = 0;
            if ((*_return) != 0) {
                (*_return)->_refCount++;
            }
        } else {
            sjs_vec3* sjt_functionParam264 = 0;
            sjs_vec3* sjt_functionParam265 = 0;
            sjs_vec3* sjt_parent176 = 0;
            sjs_vec3* sjt_parent177 = 0;
            float v;

#line 47 "lib/sj-lib-ui/vec3.sj"
            sjt_parent176 = &tvec;
#line 155 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam264 = &edge1;
#line 155
            sjf_vec3_cross(sjt_parent176, sjt_functionParam264, &qvec);
#line 135
            sjt_parent177 = dir;
#line 156
            sjt_functionParam265 = &qvec;
#line 156
            sjf_vec3_dot(sjt_parent177, sjt_functionParam265, &v);
            if ((v < 0.0f) || ((u + v) > det)) {
#line 158 "lib/sj-lib-ui/vertexBuffer.sj"
                (*_return) = 0;
                if ((*_return) != 0) {
                    (*_return)->_refCount++;
                }
            } else {
                float finvdet;
                sjs_vec3* sjt_functionParam266 = 0;
                sjs_vec3* sjt_parent178 = 0;
                sjs_vec3* sjt_value3 = 0;
                float t;

#line 55 "lib/sj-lib-ui/vec3.sj"
                sjt_parent178 = &edge2;
#line 161 "lib/sj-lib-ui/vertexBuffer.sj"
                sjt_functionParam266 = &qvec;
#line 161
                sjf_vec3_dot(sjt_parent178, sjt_functionParam266, &t);
#line 162
                finvdet = 1.0f / det;
#line 162
                sjt_value3 = (sjs_vec3*)malloc(sizeof(sjs_vec3));
#line 162
                sjt_value3->_refCount = 1;
#line 163
                sjt_value3->x = u * finvdet;
#line 163
                sjt_value3->y = v * finvdet;
#line 163
                sjt_value3->z = t * finvdet;
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

    if (edge1._refCount == 1) { sjf_vec3_destroy(&edge1); }
;
    if (edge2._refCount == 1) { sjf_vec3_destroy(&edge2); }
;
    if (pvec._refCount == 1) { sjf_vec3_destroy(&pvec); }
;
    if (qvec._refCount == 1) { sjf_vec3_destroy(&qvec); }
;
    if (tvec._refCount == 1) { sjf_vec3_destroy(&tvec); }
;
}

void sjf_lambda2(sjs_lambda2* _this) {
}

void sjf_lambda2_copy(sjs_lambda2* _this, sjs_lambda2* _from) {
#line 88 "lib/sj-lib-ui/scene2dModel.sj"
    _this->lambdaparam1 = _from->lambdaparam1;
#line 88
    _this->lambdaparam2 = _from->lambdaparam2;
}

void sjf_lambda2_destroy(sjs_lambda2* _this) {
}

void sjf_lambda2_heap(sjs_lambda2* _this) {
}

void sjf_lambda2_invoke(sjs_lambda2* _parent, sjs_string* _return) {
    sjs_string sjt_call104 = { -1 };
    sjs_string sjt_call105 = { -1 };
    sjs_string* sjt_functionParam387 = 0;
    sjs_string* sjt_parent267 = 0;
    sjs_mouseevent* sjt_parent268 = 0;

#line 55 "lib/sj-lib-ui/mouse.sj"
    sjt_parent268 = _parent->lambdaparam1;
#line 55
    sjf_mouseevent_asstring(sjt_parent268, &sjt_call104);
#line 88 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_parent267 = &sjt_call104;
#line 88
    sjt_call105._refCount = 1;
#line 88
    sjt_call105.offset = 0;
#line 88
    sjt_call105.count = 16;
#line 88
    sjt_call105.data._refCount = 1;
#line 88
    sjt_call105.data.v = &sjg_string39;
#line 88
    sjf_array_char(&sjt_call105.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call105._isnullterminated = false;
#line 16
    sjf_string(&sjt_call105);
#line 88 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam387 = &sjt_call105;
#line 88
    sjf_string_add(sjt_parent267, sjt_functionParam387, _return);

    if (sjt_call104._refCount == 1) { sjf_string_destroy(&sjt_call104); }
;
    if (sjt_call105._refCount == 1) { sjf_string_destroy(&sjt_call105); }
;
}

void sjf_lambda2_invoke_heap(sjs_lambda2* _parent, sjs_string** _return) {
    sjs_string sjt_call106 = { -1 };
    sjs_string sjt_call107 = { -1 };
    sjs_string* sjt_functionParam388 = 0;
    sjs_string* sjt_parent269 = 0;
    sjs_mouseevent* sjt_parent270 = 0;

#line 55 "lib/sj-lib-ui/mouse.sj"
    sjt_parent270 = _parent->lambdaparam2;
#line 55
    sjf_mouseevent_asstring(sjt_parent270, &sjt_call106);
#line 88 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_parent269 = &sjt_call106;
#line 88
    sjt_call107._refCount = 1;
#line 88
    sjt_call107.offset = 0;
#line 88
    sjt_call107.count = 16;
#line 88
    sjt_call107.data._refCount = 1;
#line 88
    sjt_call107.data.v = &sjg_string39;
#line 88
    sjf_array_char(&sjt_call107.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call107._isnullterminated = false;
#line 16
    sjf_string(&sjt_call107);
#line 88 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam388 = &sjt_call107;
#line 88
    sjf_string_add_heap(sjt_parent269, sjt_functionParam388, _return);

    if (sjt_call106._refCount == 1) { sjf_string_destroy(&sjt_call106); }
;
    if (sjt_call107._refCount == 1) { sjf_string_destroy(&sjt_call107); }
;
}

void sjf_lambda3(sjs_lambda3* _this) {
}

void sjf_lambda3_copy(sjs_lambda3* _this, sjs_lambda3* _from) {
#line 74 "lib/sj-lib-ui/scene2dModel.sj"
    _this->lambdaparam3 = _from->lambdaparam3;
#line 74
    _this->lambdaparam4 = _from->lambdaparam4;
#line 74
    _this->lambdaparam5 = _from->lambdaparam5;
}

void sjf_lambda3_destroy(sjs_lambda3* _this) {
}

void sjf_lambda3_heap(sjs_lambda3* _this) {
}

void sjf_lambda3_invoke(sjs_lambda3* _parent, sjs_string* _return) {
    sjs_string sjt_call59 = { -1 };
    sjs_string sjt_call60 = { -1 };
    sjs_string sjt_call89 = { -1 };
    sjs_string sjt_call90 = { -1 };
    sjs_string* sjt_functionParam372 = 0;
    sjs_string* sjt_functionParam373 = 0;
    sjs_string* sjt_parent237 = 0;
    sjs_string* sjt_parent238 = 0;
    sjs_mouseevent* sjt_parent255 = 0;
    sjs_vec2* sjt_parent260 = 0;

#line 55 "lib/sj-lib-ui/mouse.sj"
    sjt_parent255 = _parent->lambdaparam3;
#line 55
    sjf_mouseevent_asstring(sjt_parent255, &sjt_call60);
#line 74 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_parent238 = &sjt_call60;
#line 74
    sjt_call89._refCount = 1;
#line 74
    sjt_call89.offset = 0;
#line 74
    sjt_call89.count = 4;
#line 74
    sjt_call89.data._refCount = 1;
#line 74
    sjt_call89.data.v = &sjg_string40;
#line 74
    sjf_array_char(&sjt_call89.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call89._isnullterminated = false;
#line 16
    sjf_string(&sjt_call89);
#line 74 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam372 = &sjt_call89;
#line 74
    sjf_string_add(sjt_parent238, sjt_functionParam372, &sjt_call59);
#line 74
    sjt_parent237 = &sjt_call59;
#line 5 "lib/sj-lib-ui/vec2.sj"
    sjt_parent260 = _parent->lambdaparam4;
#line 5
    sjf_vec2_asstring(sjt_parent260, &sjt_call90);
#line 74 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam373 = &sjt_call90;
#line 74
    sjf_string_add(sjt_parent237, sjt_functionParam373, _return);

    if (sjt_call59._refCount == 1) { sjf_string_destroy(&sjt_call59); }
;
    if (sjt_call60._refCount == 1) { sjf_string_destroy(&sjt_call60); }
;
    if (sjt_call89._refCount == 1) { sjf_string_destroy(&sjt_call89); }
;
    if (sjt_call90._refCount == 1) { sjf_string_destroy(&sjt_call90); }
;
}

void sjf_lambda3_invoke_heap(sjs_lambda3* _parent, sjs_string** _return) {
    sjs_string sjt_call100 = { -1 };
    sjs_string sjt_call101 = { -1 };
    sjs_string sjt_call102 = { -1 };
    sjs_string sjt_call99 = { -1 };
    sjs_string* sjt_functionParam382 = 0;
    sjs_string* sjt_functionParam383 = 0;
    sjs_string* sjt_parent261 = 0;
    sjs_string* sjt_parent262 = 0;
    sjs_mouseevent* sjt_parent263 = 0;
    sjs_vec2* sjt_parent264 = 0;

#line 55 "lib/sj-lib-ui/mouse.sj"
    sjt_parent263 = _parent->lambdaparam5;
#line 55
    sjf_mouseevent_asstring(sjt_parent263, &sjt_call100);
#line 74 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_parent262 = &sjt_call100;
#line 74
    sjt_call101._refCount = 1;
#line 74
    sjt_call101.offset = 0;
#line 74
    sjt_call101.count = 4;
#line 74
    sjt_call101.data._refCount = 1;
#line 74
    sjt_call101.data.v = &sjg_string40;
#line 74
    sjf_array_char(&sjt_call101.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call101._isnullterminated = false;
#line 16
    sjf_string(&sjt_call101);
#line 74 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam382 = &sjt_call101;
#line 74
    sjf_string_add(sjt_parent262, sjt_functionParam382, &sjt_call99);
#line 74
    sjt_parent261 = &sjt_call99;
#line 5 "lib/sj-lib-ui/vec2.sj"
    sjt_parent264 = _parent->lambdaparam4;
#line 5
    sjf_vec2_asstring(sjt_parent264, &sjt_call102);
#line 74 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam383 = &sjt_call102;
#line 74
    sjf_string_add_heap(sjt_parent261, sjt_functionParam383, _return);

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
#line 1 "lib/sj-lib-ui/scene3dElement.sj"
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
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_heap_iface_animation_copy(&_this->arr, &_from->arr);
}

void sjf_list_heap_iface_animation_destroy(sjs_list_heap_iface_animation* _this) {
    if (_this->arr._refCount == 1) { sjf_array_heap_iface_animation_destroy(&_this->arr); }
;
}

void sjf_list_heap_iface_animation_getat_heap(sjs_list_heap_iface_animation* _parent, int32_t index, sji_animation* _return) {
    int32_t sjt_functionParam473;
    sjs_array_heap_iface_animation* sjt_parent306 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent306 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam473 = index;
#line 8
    sjf_array_heap_iface_animation_getat_heap(sjt_parent306, sjt_functionParam473, _return);
}

void sjf_list_heap_iface_animation_getcount(sjs_list_heap_iface_animation* _parent, int32_t* _return) {
    sjs_array_heap_iface_animation* sjt_parent303 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent303 = &_parent->arr;
#line 29
    sjf_array_heap_iface_animation_getcount(sjt_parent303, _return);
}

void sjf_list_heap_iface_animation_heap(sjs_list_heap_iface_animation* _this) {
}

void sjf_list_heap_iface_animation_removeat(sjs_list_heap_iface_animation* _parent, int32_t index) {
#line 55 "lib/sj-lib-common/list.sj"
    if (index < 0 || index >= ((sjs_array*)_parent->arr.v)->count) {
#line 56
        halt("removeAt: out of bounds %d:%d\n", index, ((sjs_array*)_parent->arr.v)->count);
#line 57
    }
#line 58
    sji_animation* p = (sji_animation*)((sjs_array*)_parent->arr.v)->data;
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
    if (index != ((sjs_array*)_parent->arr.v)->count - 1) {
#line 61
        memcpy(p + index, p + index + 1, (((sjs_array*)_parent->arr.v)->count - index - 1) * sizeof(sji_animation));
#line 62
    }
#line 63
    ((sjs_array*)_parent->arr.v)->count--;
}

void sjf_list_heap_iface_model(sjs_list_heap_iface_model* _this) {
}

void sjf_list_heap_iface_model_add(sjs_list_heap_iface_model* _parent, sji_model item) {
    int32_t sjt_capture42;
    int32_t sjt_capture43;
    sjs_array_heap_iface_model sjt_funcold19 = { -1 };
    int32_t sjt_functionParam188;
    sji_model sjt_functionParam189 = { 0 };
    sjs_array_heap_iface_model* sjt_parent115 = 0;
    sjs_array_heap_iface_model* sjt_parent116 = 0;
    sjs_array_heap_iface_model* sjt_parent120 = 0;
    sjs_array_heap_iface_model* sjt_parent121 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent115 = &_parent->arr;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent115, &sjt_capture42);
#line 35
    sjt_parent116 = &_parent->arr;
#line 35
    sjf_array_heap_iface_model_gettotalcount(sjt_parent116, &sjt_capture43);
    if (sjt_capture42 == sjt_capture43) {
        int32_t sjt_capture44;
        int32_t sjt_functionParam183;
        int32_t sjt_functionParam184;
        int32_t sjt_functionParam185;
        int32_t sjt_functionParam186;
        int32_t sjt_functionParam187;
        sjs_array_heap_iface_model* sjt_parent117 = 0;
        sjs_array_heap_iface_model* sjt_parent118 = 0;
        sjs_array_heap_iface_model* sjt_parent119 = 0;

#line 168 "lib/sj-lib-common/array.sj"
        sjt_parent117 = &_parent->arr;
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam183 = 0;
#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent118 = &_parent->arr;
#line 29
        sjf_array_heap_iface_model_getcount(sjt_parent118, &sjt_functionParam184);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam186 = 10;
#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent119 = &_parent->arr;
#line 35
        sjf_array_heap_iface_model_gettotalcount(sjt_parent119, &sjt_capture44);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam187 = sjt_capture44 * 2;
#line 46
        sjf_i32_max(sjt_functionParam186, sjt_functionParam187, &sjt_functionParam185);
#line 46
        sjf_array_heap_iface_model_clone(sjt_parent117, sjt_functionParam183, sjt_functionParam184, sjt_functionParam185, &sjt_funcold19);
#line 46
        if (_parent->arr._refCount == 1) { sjf_array_heap_iface_model_destroy(&_parent->arr); }
;
#line 168 "lib/sj-lib-common/array.sj"
        sjf_array_heap_iface_model_copy(&_parent->arr, &sjt_funcold19);
    }

#line 52
    sjt_parent120 = &_parent->arr;
#line 29
    sjt_parent121 = &_parent->arr;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent121, &sjt_functionParam188);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_functionParam189 = item;
    if (sjt_functionParam189._parent != 0) {
        sjt_functionParam189._parent->_refCount++;
    }

#line 44
    sjf_array_heap_iface_model_initat(sjt_parent120, sjt_functionParam188, sjt_functionParam189);

    if (sjt_functionParam189._parent != 0) {
        sjt_functionParam189._parent->_refCount--;
        if (sjt_functionParam189._parent->_refCount <= 0) {
            sjt_functionParam189._vtbl->destroy(sjt_functionParam189._parent);
            free(sjt_functionParam189._parent);
        }
    }
    if (sjt_funcold19._refCount == 1) { sjf_array_heap_iface_model_destroy(&sjt_funcold19); }
;
}

void sjf_list_heap_iface_model_copy(sjs_list_heap_iface_model* _this, sjs_list_heap_iface_model* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_heap_iface_model_copy(&_this->arr, &_from->arr);
}

void sjf_list_heap_iface_model_destroy(sjs_list_heap_iface_model* _this) {
    if (_this->arr._refCount == 1) { sjf_array_heap_iface_model_destroy(&_this->arr); }
;
}

void sjf_list_heap_iface_model_getat_heap(sjs_list_heap_iface_model* _parent, int32_t index, sji_model* _return) {
    int32_t sjt_functionParam94;
    sjs_array_heap_iface_model* sjt_parent68 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent68 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam94 = index;
#line 8
    sjf_array_heap_iface_model_getat_heap(sjt_parent68, sjt_functionParam94, _return);
}

void sjf_list_heap_iface_model_getcount(sjs_list_heap_iface_model* _parent, int32_t* _return) {
    sjs_array_heap_iface_model* sjt_parent66 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent66 = &_parent->arr;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent66, _return);
}

void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this) {
}

void sjf_list_heap_iface_model_sortcb(sjs_list_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb) {
    cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam90;
    sjs_array_heap_iface_model* sjt_parent62 = 0;

#line 279 "lib/sj-lib-common/array.sj"
    sjt_parent62 = &_parent->arr;
#line 28 "lib/sj-lib-common/list.sj"
    sjt_functionParam90 = cb;
#line 28
    sjf_array_heap_iface_model_sortcb(sjt_parent62, sjt_functionParam90);
}

void sjf_list_rect(sjs_list_rect* _this) {
}

void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item) {
    int32_t sjt_capture16;
    int32_t sjt_capture17;
    sjs_array_rect sjt_funcold7 = { -1 };
    int32_t sjt_functionParam62;
    sjs_rect* sjt_functionParam63 = 0;
    sjs_array_rect* sjt_parent51 = 0;
    sjs_array_rect* sjt_parent52 = 0;
    sjs_array_rect* sjt_parent56 = 0;
    sjs_array_rect* sjt_parent57 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent51 = &_parent->arr;
#line 29
    sjf_array_rect_getcount(sjt_parent51, &sjt_capture16);
#line 35
    sjt_parent52 = &_parent->arr;
#line 35
    sjf_array_rect_gettotalcount(sjt_parent52, &sjt_capture17);
    if (sjt_capture16 == sjt_capture17) {
        int32_t sjt_capture18;
        int32_t sjt_functionParam57;
        int32_t sjt_functionParam58;
        int32_t sjt_functionParam59;
        int32_t sjt_functionParam60;
        int32_t sjt_functionParam61;
        sjs_array_rect* sjt_parent53 = 0;
        sjs_array_rect* sjt_parent54 = 0;
        sjs_array_rect* sjt_parent55 = 0;

#line 168 "lib/sj-lib-common/array.sj"
        sjt_parent53 = &_parent->arr;
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam57 = 0;
#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent54 = &_parent->arr;
#line 29
        sjf_array_rect_getcount(sjt_parent54, &sjt_functionParam58);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam60 = 10;
#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent55 = &_parent->arr;
#line 35
        sjf_array_rect_gettotalcount(sjt_parent55, &sjt_capture18);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam61 = sjt_capture18 * 2;
#line 46
        sjf_i32_max(sjt_functionParam60, sjt_functionParam61, &sjt_functionParam59);
#line 46
        sjf_array_rect_clone(sjt_parent53, sjt_functionParam57, sjt_functionParam58, sjt_functionParam59, &sjt_funcold7);
#line 46
        if (_parent->arr._refCount == 1) { sjf_array_rect_destroy(&_parent->arr); }
;
#line 168 "lib/sj-lib-common/array.sj"
        sjf_array_rect_copy(&_parent->arr, &sjt_funcold7);
    }

#line 52
    sjt_parent56 = &_parent->arr;
#line 29
    sjt_parent57 = &_parent->arr;
#line 29
    sjf_array_rect_getcount(sjt_parent57, &sjt_functionParam62);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_functionParam63 = item;
#line 44
    sjf_array_rect_initat(sjt_parent56, sjt_functionParam62, sjt_functionParam63);

    if (sjt_funcold7._refCount == 1) { sjf_array_rect_destroy(&sjt_funcold7); }
;
}

void sjf_list_rect_copy(sjs_list_rect* _this, sjs_list_rect* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_rect_copy(&_this->arr, &_from->arr);
}

void sjf_list_rect_destroy(sjs_list_rect* _this) {
    if (_this->arr._refCount == 1) { sjf_array_rect_destroy(&_this->arr); }
;
}

void sjf_list_rect_getat(sjs_list_rect* _parent, int32_t index, sjs_rect* _return) {
    int32_t sjt_functionParam96;
    sjs_array_rect* sjt_parent72 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent72 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam96 = index;
#line 8
    sjf_array_rect_getat(sjt_parent72, sjt_functionParam96, _return);
}

void sjf_list_rect_getat_heap(sjs_list_rect* _parent, int32_t index, sjs_rect** _return) {
    int32_t sjt_functionParam97;
    sjs_array_rect* sjt_parent73 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent73 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam97 = index;
#line 8
    sjf_array_rect_getat_heap(sjt_parent73, sjt_functionParam97, _return);
}

void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return) {
    sjs_array_rect* sjt_parent75 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent75 = &_parent->arr;
#line 29
    sjf_array_rect_getcount(sjt_parent75, _return);
}

void sjf_list_rect_heap(sjs_list_rect* _this) {
}

void sjf_list_rect_removeat(sjs_list_rect* _parent, int32_t index) {
#line 55 "lib/sj-lib-common/list.sj"
    if (index < 0 || index >= ((sjs_array*)_parent->arr.v)->count) {
#line 56
        halt("removeAt: out of bounds %d:%d\n", index, ((sjs_array*)_parent->arr.v)->count);
#line 57
    }
#line 58
    sjs_rect* p = (sjs_rect*)((sjs_array*)_parent->arr.v)->data;
#line 59
    ;
#line 60
    if (index != ((sjs_array*)_parent->arr.v)->count - 1) {
#line 61
        memcpy(p + index, p + index + 1, (((sjs_array*)_parent->arr.v)->count - index - 1) * sizeof(sjs_rect));
#line 62
    }
#line 63
    ((sjs_array*)_parent->arr.v)->count--;
}

void sjf_list_u32(sjs_list_u32* _this) {
}

void sjf_list_u32_add(sjs_list_u32* _parent, uint32_t item) {
    int32_t sjt_capture30;
    int32_t sjt_capture31;
    sjs_array_u32 sjt_funcold11 = { -1 };
    int32_t sjt_functionParam119;
    uint32_t sjt_functionParam120;
    sjs_array_u32* sjt_parent87 = 0;
    sjs_array_u32* sjt_parent88 = 0;
    sjs_array_u32* sjt_parent92 = 0;
    sjs_array_u32* sjt_parent93 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent87 = &_parent->arr;
#line 29
    sjf_array_u32_getcount(sjt_parent87, &sjt_capture30);
#line 35
    sjt_parent88 = &_parent->arr;
#line 35
    sjf_array_u32_gettotalcount(sjt_parent88, &sjt_capture31);
    if (sjt_capture30 == sjt_capture31) {
        int32_t sjt_capture32;
        int32_t sjt_functionParam114;
        int32_t sjt_functionParam115;
        int32_t sjt_functionParam116;
        int32_t sjt_functionParam117;
        int32_t sjt_functionParam118;
        sjs_array_u32* sjt_parent89 = 0;
        sjs_array_u32* sjt_parent90 = 0;
        sjs_array_u32* sjt_parent91 = 0;

#line 168 "lib/sj-lib-common/array.sj"
        sjt_parent89 = &_parent->arr;
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam114 = 0;
#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent90 = &_parent->arr;
#line 29
        sjf_array_u32_getcount(sjt_parent90, &sjt_functionParam115);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam117 = 10;
#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent91 = &_parent->arr;
#line 35
        sjf_array_u32_gettotalcount(sjt_parent91, &sjt_capture32);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam118 = sjt_capture32 * 2;
#line 46
        sjf_i32_max(sjt_functionParam117, sjt_functionParam118, &sjt_functionParam116);
#line 46
        sjf_array_u32_clone(sjt_parent89, sjt_functionParam114, sjt_functionParam115, sjt_functionParam116, &sjt_funcold11);
#line 46
        if (_parent->arr._refCount == 1) { sjf_array_u32_destroy(&_parent->arr); }
;
#line 168 "lib/sj-lib-common/array.sj"
        sjf_array_u32_copy(&_parent->arr, &sjt_funcold11);
    }

#line 52
    sjt_parent92 = &_parent->arr;
#line 29
    sjt_parent93 = &_parent->arr;
#line 29
    sjf_array_u32_getcount(sjt_parent93, &sjt_functionParam119);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_functionParam120 = item;
#line 44
    sjf_array_u32_initat(sjt_parent92, sjt_functionParam119, sjt_functionParam120);

    if (sjt_funcold11._refCount == 1) { sjf_array_u32_destroy(&sjt_funcold11); }
;
}

void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_u32_copy(&_this->arr, &_from->arr);
}

void sjf_list_u32_destroy(sjs_list_u32* _this) {
    if (_this->arr._refCount == 1) { sjf_array_u32_destroy(&_this->arr); }
;
}

void sjf_list_u32_getat(sjs_list_u32* _parent, int32_t index, uint32_t* _return) {
    int32_t sjt_functionParam153;
    sjs_array_u32* sjt_parent95 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent95 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam153 = index;
#line 8
    sjf_array_u32_getat(sjt_parent95, sjt_functionParam153, _return);
}

void sjf_list_u32_getcount(sjs_list_u32* _parent, int32_t* _return) {
    sjs_array_u32* sjt_parent97 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent97 = &_parent->arr;
#line 29
    sjf_array_u32_getcount(sjt_parent97, _return);
}

void sjf_list_u32_heap(sjs_list_u32* _this) {
}

void sjf_list_u32_removeat(sjs_list_u32* _parent, int32_t index) {
#line 55 "lib/sj-lib-common/list.sj"
    if (index < 0 || index >= ((sjs_array*)_parent->arr.v)->count) {
#line 56
        halt("removeAt: out of bounds %d:%d\n", index, ((sjs_array*)_parent->arr.v)->count);
#line 57
    }
#line 58
    uint32_t* p = (uint32_t*)((sjs_array*)_parent->arr.v)->data;
#line 59
    ;
#line 60
    if (index != ((sjs_array*)_parent->arr.v)->count - 1) {
#line 61
        memcpy(p + index, p + index + 1, (((sjs_array*)_parent->arr.v)->count - index - 1) * sizeof(uint32_t));
#line 62
    }
#line 63
    ((sjs_array*)_parent->arr.v)->count--;
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
            bool sjt_capture67;
            bool_option sjt_capture68;
            int32_t sjt_functionParam297;
            sjs_hash_type_bool* sjt_parent203 = 0;

#line 46 "lib/sj-lib-common/log.sj"
            ifValue8 = includes;
#line 21 "lib/sj-lib-common/hash.sj"
            sjt_parent203 = ifValue8;
#line 46 "lib/sj-lib-common/log.sj"
            sjt_functionParam297 = t;
#line 46
            sjf_hash_type_bool_getat(sjt_parent203, sjt_functionParam297, &sjt_capture68);
            if (sjt_capture68.isvalid) {
                int32_t sjt_functionParam298;
                bool_option sjt_getValue3;
                sjs_hash_type_bool* sjt_parent204 = 0;

#line 21 "lib/sj-lib-common/hash.sj"
                sjt_parent204 = ifValue8;
#line 46 "lib/sj-lib-common/log.sj"
                sjt_functionParam298 = t;
#line 46
                sjf_hash_type_bool_getat(sjt_parent204, sjt_functionParam298, &sjt_getValue3);
#line 49
                sjt_capture67 = sjt_getValue3.value;
            } else {
#line 49 "lib/sj-lib-common/log.sj"
                sjt_capture67 = false;
            }

            if (sjt_capture67) {
                sjs_string* sjt_functionParam299 = 0;
                int32_t sjt_functionParam327;
                sjs_string* sjt_functionParam328 = 0;
                sjs_string* sjt_functionParam329 = 0;
                int32_t sjt_functionParam330;
                sjs_string* sjt_functionParam331 = 0;
                sjs_string* sjt_functionParam332 = 0;
                sjs_string* sjt_parent222 = 0;
                sjs_string* sjt_parent223 = 0;
                sjs_string* sjt_parent224 = 0;
                sjs_string* sjt_parent225 = 0;
                sjs_string* sjt_parent230 = 0;

#line 46 "lib/sj-lib-common/log.sj"
                sjt_functionParam327 = level;
#line 46
                sjf_loglevel_asstring(sjt_functionParam327, &sjt_call36);
#line 50
                sjt_parent230 = &sjt_call36;
#line 50
                sjf_string_touppercase(sjt_parent230, &sjt_call35);
#line 50
                sjt_parent225 = &sjt_call35;
#line 50
                sjt_call44._refCount = 1;
#line 50
                sjt_call44.offset = 0;
#line 50
                sjt_call44.count = 2;
#line 50
                sjt_call44.data._refCount = 1;
#line 50
                sjt_call44.data.v = &sjg_string31;
#line 50
                sjf_array_char(&sjt_call44.data);
#line 16 "lib/sj-lib-common/string.sj"
                sjt_call44._isnullterminated = false;
#line 16
                sjf_string(&sjt_call44);
#line 50 "lib/sj-lib-common/log.sj"
                sjt_functionParam328 = &sjt_call44;
#line 50
                sjf_string_add(sjt_parent225, sjt_functionParam328, &sjt_call34);
#line 50
                sjt_parent224 = &sjt_call34;
#line 46
                sjt_functionParam330 = t;
#line 46
                sjf_type_asstring(sjt_functionParam330, &sjt_call45);
#line 50
                sjt_functionParam329 = &sjt_call45;
#line 50
                sjf_string_add(sjt_parent224, sjt_functionParam329, &sjt_call33);
#line 50
                sjt_parent223 = &sjt_call33;
#line 50
                sjt_call46._refCount = 1;
#line 50
                sjt_call46.offset = 0;
#line 50
                sjt_call46.count = 2;
#line 50
                sjt_call46.data._refCount = 1;
#line 50
                sjt_call46.data.v = &sjg_string32;
#line 50
                sjf_array_char(&sjt_call46.data);
#line 16 "lib/sj-lib-common/string.sj"
                sjt_call46._isnullterminated = false;
#line 16
                sjf_string(&sjt_call46);
#line 50 "lib/sj-lib-common/log.sj"
                sjt_functionParam331 = &sjt_call46;
#line 50
                sjf_string_add(sjt_parent223, sjt_functionParam331, &sjt_call32);
#line 50
                sjt_parent222 = &sjt_call32;
#line 50
                cb._cb(cb._parent, &sjt_call47);
#line 50
                sjt_functionParam332 = &sjt_call47;
#line 50
                sjf_string_add(sjt_parent222, sjt_functionParam332, &sjt_call31);
#line 50
                sjt_functionParam299 = &sjt_call31;
#line 50
                sjf_debug_writeline(sjt_functionParam299);
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
            sjs_string* sjt_functionParam333 = 0;
            int32_t sjt_functionParam334;
            sjs_string* sjt_functionParam335 = 0;
            sjs_string* sjt_functionParam336 = 0;
            int32_t sjt_functionParam337;
            sjs_string* sjt_functionParam338 = 0;
            sjs_string* sjt_functionParam339 = 0;
            sjs_string* sjt_parent231 = 0;
            sjs_string* sjt_parent232 = 0;
            sjs_string* sjt_parent233 = 0;
            sjs_string* sjt_parent234 = 0;
            sjs_string* sjt_parent235 = 0;

#line 46 "lib/sj-lib-common/log.sj"
            sjt_functionParam334 = level;
#line 46
            sjf_loglevel_asstring(sjt_functionParam334, &sjt_call53);
#line 53
            sjt_parent235 = &sjt_call53;
#line 53
            sjf_string_touppercase(sjt_parent235, &sjt_call52);
#line 53
            sjt_parent234 = &sjt_call52;
#line 53
            sjt_call54._refCount = 1;
#line 53
            sjt_call54.offset = 0;
#line 53
            sjt_call54.count = 2;
#line 53
            sjt_call54.data._refCount = 1;
#line 53
            sjt_call54.data.v = &sjg_string31;
#line 53
            sjf_array_char(&sjt_call54.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call54._isnullterminated = false;
#line 16
            sjf_string(&sjt_call54);
#line 53 "lib/sj-lib-common/log.sj"
            sjt_functionParam335 = &sjt_call54;
#line 53
            sjf_string_add(sjt_parent234, sjt_functionParam335, &sjt_call51);
#line 53
            sjt_parent233 = &sjt_call51;
#line 46
            sjt_functionParam337 = t;
#line 46
            sjf_type_asstring(sjt_functionParam337, &sjt_call55);
#line 53
            sjt_functionParam336 = &sjt_call55;
#line 53
            sjf_string_add(sjt_parent233, sjt_functionParam336, &sjt_call50);
#line 53
            sjt_parent232 = &sjt_call50;
#line 53
            sjt_call56._refCount = 1;
#line 53
            sjt_call56.offset = 0;
#line 53
            sjt_call56.count = 2;
#line 53
            sjt_call56.data._refCount = 1;
#line 53
            sjt_call56.data.v = &sjg_string32;
#line 53
            sjf_array_char(&sjt_call56.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call56._isnullterminated = false;
#line 16
            sjf_string(&sjt_call56);
#line 53 "lib/sj-lib-common/log.sj"
            sjt_functionParam338 = &sjt_call56;
#line 53
            sjf_string_add(sjt_parent232, sjt_functionParam338, &sjt_call49);
#line 53
            sjt_parent231 = &sjt_call49;
#line 53
            cb._cb(cb._parent, &sjt_call57);
#line 53
            sjt_functionParam339 = &sjt_call57;
#line 53
            sjf_string_add(sjt_parent231, sjt_functionParam339, &sjt_call48);
#line 53
            sjt_functionParam333 = &sjt_call48;
#line 53
            sjf_debug_writeline(sjt_functionParam333);

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
#line 13 "lib/sj-lib-common/log.sj"
    _this->minlevel = _from->minlevel;
#line 13
    sjs_hash_type_bool* copyoption2 = (_from->traceincludes._refCount != -1 ? &_from->traceincludes : 0);
    if (copyoption2 != 0) {
        _this->traceincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->traceincludes, copyoption2);
    } else {
        _this->traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption3 = (_from->debugincludes._refCount != -1 ? &_from->debugincludes : 0);
    if (copyoption3 != 0) {
        _this->debugincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->debugincludes, copyoption3);
    } else {
        _this->debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption4 = (_from->infoincludes._refCount != -1 ? &_from->infoincludes : 0);
    if (copyoption4 != 0) {
        _this->infoincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->infoincludes, copyoption4);
    } else {
        _this->infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption5 = (_from->warnincludes._refCount != -1 ? &_from->warnincludes : 0);
    if (copyoption5 != 0) {
        _this->warnincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->warnincludes, copyoption5);
    } else {
        _this->warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption6 = (_from->errorincludes._refCount != -1 ? &_from->errorincludes : 0);
    if (copyoption6 != 0) {
        _this->errorincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->errorincludes, copyoption6);
    } else {
        _this->errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption7 = (_from->fatalincludes._refCount != -1 ? &_from->fatalincludes : 0);
    if (copyoption7 != 0) {
        _this->fatalincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
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
    int32_t sjt_functionParam340;
    sjs_hash_type_bool* sjt_functionParam341 = 0;
    int32_t sjt_functionParam342;
    cb_string_heap_string sjt_functionParam343;

#line 23 "lib/sj-lib-common/log.sj"
    sjt_functionParam340 = g_loglevel_trace;
#line 23
    sjt_functionParam341 = (_parent->traceincludes._refCount != -1 ? &_parent->traceincludes : 0);
#line 22
    sjt_functionParam342 = t;
#line 22
    sjt_functionParam343 = cb;
#line 22
    sjf_log__write(_parent, sjt_functionParam340, sjt_functionParam341, sjt_functionParam342, sjt_functionParam343);
}

void sjf_loglevel_asstring(int32_t e, sjs_string* _return) {
    int32_t underscore1;

#line 1 "lib/sj-lib-common/log.sj"
    underscore1 = e;
    if (underscore1 == 0) {
        _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
        _return->offset = 0;
#line 1
        _return->count = 5;
#line 1
        _return->data._refCount = 1;
#line 1
        _return->data.v = &sjg_string24;
#line 1
        sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
    } else {
        if (underscore1 == 1) {
            _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
            _return->offset = 0;
#line 1
            _return->count = 5;
#line 1
            _return->data._refCount = 1;
#line 1
            _return->data.v = &sjg_string25;
#line 1
            sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        } else {
            if (underscore1 == 2) {
                _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                _return->offset = 0;
#line 1
                _return->count = 4;
#line 1
                _return->data._refCount = 1;
#line 1
                _return->data.v = &sjg_string26;
#line 1
                sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
                _return->_isnullterminated = false;
#line 16
                sjf_string(_return);
            } else {
                if (underscore1 == 3) {
                    _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                    _return->offset = 0;
#line 1
                    _return->count = 4;
#line 1
                    _return->data._refCount = 1;
#line 1
                    _return->data.v = &sjg_string27;
#line 1
                    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
                    _return->_isnullterminated = false;
#line 16
                    sjf_string(_return);
                } else {
                    if (underscore1 == 4) {
                        _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                        _return->offset = 0;
#line 1
                        _return->count = 5;
#line 1
                        _return->data._refCount = 1;
#line 1
                        _return->data.v = &sjg_string28;
#line 1
                        sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
                        _return->_isnullterminated = false;
#line 16
                        sjf_string(_return);
                    } else {
                        if (underscore1 == 5) {
                            _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                            _return->offset = 0;
#line 1
                            _return->count = 5;
#line 1
                            _return->data._refCount = 1;
#line 1
                            _return->data.v = &sjg_string29;
#line 1
                            sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
                            _return->_isnullterminated = false;
#line 16
                            sjf_string(_return);
                        } else {
                            _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                            _return->offset = 0;
#line 1
                            _return->count = 0;
#line 1
                            _return->data._refCount = 1;
#line 1
                            _return->data.v = &sjg_string30;
#line 1
                            sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
                            _return->_isnullterminated = false;
#line 16
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

#line 1 "lib/sj-lib-common/log.sj"
    underscore2 = e;
    if (underscore2 == 0) {
        sjs_string sjt_call37 = { -1 };

        sjt_call37._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
        sjt_call37.offset = 0;
#line 1
        sjt_call37.count = 5;
#line 1
        sjt_call37.data._refCount = 1;
#line 1
        sjt_call37.data.v = &sjg_string24;
#line 1
        sjf_array_char(&sjt_call37.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call37._isnullterminated = false;
#line 16
        sjf_string(&sjt_call37);
#line 16
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
        (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
        sjf_string_copy((*_return), &sjt_call37);

        if (sjt_call37._refCount == 1) { sjf_string_destroy(&sjt_call37); }
;
    } else {
        if (underscore2 == 1) {
            sjs_string sjt_call38 = { -1 };

            sjt_call38._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
            sjt_call38.offset = 0;
#line 1
            sjt_call38.count = 5;
#line 1
            sjt_call38.data._refCount = 1;
#line 1
            sjt_call38.data.v = &sjg_string25;
#line 1
            sjf_array_char(&sjt_call38.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call38._isnullterminated = false;
#line 16
            sjf_string(&sjt_call38);
#line 16
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
            (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
            sjf_string_copy((*_return), &sjt_call38);

            if (sjt_call38._refCount == 1) { sjf_string_destroy(&sjt_call38); }
;
        } else {
            if (underscore2 == 2) {
                sjs_string sjt_call39 = { -1 };

                sjt_call39._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                sjt_call39.offset = 0;
#line 1
                sjt_call39.count = 4;
#line 1
                sjt_call39.data._refCount = 1;
#line 1
                sjt_call39.data.v = &sjg_string26;
#line 1
                sjf_array_char(&sjt_call39.data);
#line 16 "lib/sj-lib-common/string.sj"
                sjt_call39._isnullterminated = false;
#line 16
                sjf_string(&sjt_call39);
#line 16
                (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
                (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                sjf_string_copy((*_return), &sjt_call39);

                if (sjt_call39._refCount == 1) { sjf_string_destroy(&sjt_call39); }
;
            } else {
                if (underscore2 == 3) {
                    sjs_string sjt_call40 = { -1 };

                    sjt_call40._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                    sjt_call40.offset = 0;
#line 1
                    sjt_call40.count = 4;
#line 1
                    sjt_call40.data._refCount = 1;
#line 1
                    sjt_call40.data.v = &sjg_string27;
#line 1
                    sjf_array_char(&sjt_call40.data);
#line 16 "lib/sj-lib-common/string.sj"
                    sjt_call40._isnullterminated = false;
#line 16
                    sjf_string(&sjt_call40);
#line 16
                    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
                    (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                    sjf_string_copy((*_return), &sjt_call40);

                    if (sjt_call40._refCount == 1) { sjf_string_destroy(&sjt_call40); }
;
                } else {
                    if (underscore2 == 4) {
                        sjs_string sjt_call41 = { -1 };

                        sjt_call41._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                        sjt_call41.offset = 0;
#line 1
                        sjt_call41.count = 5;
#line 1
                        sjt_call41.data._refCount = 1;
#line 1
                        sjt_call41.data.v = &sjg_string28;
#line 1
                        sjf_array_char(&sjt_call41.data);
#line 16 "lib/sj-lib-common/string.sj"
                        sjt_call41._isnullterminated = false;
#line 16
                        sjf_string(&sjt_call41);
#line 16
                        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
                        (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                        sjf_string_copy((*_return), &sjt_call41);

                        if (sjt_call41._refCount == 1) { sjf_string_destroy(&sjt_call41); }
;
                    } else {
                        if (underscore2 == 5) {
                            sjs_string sjt_call42 = { -1 };

                            sjt_call42._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                            sjt_call42.offset = 0;
#line 1
                            sjt_call42.count = 5;
#line 1
                            sjt_call42.data._refCount = 1;
#line 1
                            sjt_call42.data.v = &sjg_string29;
#line 1
                            sjf_array_char(&sjt_call42.data);
#line 16 "lib/sj-lib-common/string.sj"
                            sjt_call42._isnullterminated = false;
#line 16
                            sjf_string(&sjt_call42);
#line 16
                            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
                            (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                            sjf_string_copy((*_return), &sjt_call42);

                            if (sjt_call42._refCount == 1) { sjf_string_destroy(&sjt_call42); }
;
                        } else {
                            sjs_string sjt_call43 = { -1 };

                            sjt_call43._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                            sjt_call43.offset = 0;
#line 1
                            sjt_call43.count = 0;
#line 1
                            sjt_call43.data._refCount = 1;
#line 1
                            sjt_call43.data.v = &sjg_string30;
#line 1
                            sjf_array_char(&sjt_call43.data);
#line 16 "lib/sj-lib-common/string.sj"
                            sjt_call43._isnullterminated = false;
#line 16
                            sjf_string(&sjt_call43);
#line 16
                            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
                            (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
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
    int32_option mouse_eventtype;
    bool mouse_isleftdown;
    int32_t mouse_x;
    int32_t mouse_y;
    sjs_rect rect = { -1 };
    bool result14;
    bool shouldappcontinue;
    bool shouldcontinue;
    sjs_size size = { -1 };
    sjs_string sjt_call123 = { -1 };
    sjs_string sjt_call124 = { -1 };
    sjs_string sjt_call125 = { -1 };
    bool sjt_capture90;
    int32_t sjt_functionParam476;
    sjs_size* sjt_functionParam480 = 0;
    sjs_rect* sjt_functionParam481 = 0;
    sjs_scene2d* sjt_interfaceParam21 = 0;
    sjs_animator* sjt_parent310 = 0;
    sjs_windowrenderer* sjt_parent312 = 0;
    sjs_scene2d* sjt_parent313 = 0;
    sjs_scene2d* sjt_parent314 = 0;
    sjs_rect* sjt_parent315 = 0;
    sji_element sjt_parent317 = { 0 };
    sjs_scene2d* sjt_parent318 = 0;
    sjs_windowrenderer* sjt_parent319 = 0;
    int32_t ticks;

#line 9 "lib/sj-lib-ui/loop.sj"
    shouldappcontinue = true;
#line 10
    ticks = 0;
#line 12
    ticks = SDL_GetTicks();
#line 31 "lib/sj-lib-ui/animation.sj"
    sjt_parent310 = &g_animator;
#line 14 "lib/sj-lib-ui/loop.sj"
    sjt_functionParam476 = ticks;
#line 14
    sjf_animator_nextframe(sjt_parent310, sjt_functionParam476);
    if (g_mainloop_showfps) {
#line 17 "lib/sj-lib-ui/loop.sj"
        g_mainloop_frames = g_mainloop_frames + 1;
        if ((g_mainloop_lasttick + 1000) < ticks) {
            float fps;
            int32_t sjt_cast50;
            int32_t sjt_cast51;
            sjs_string* sjt_functionParam477 = 0;
            sjs_string* sjt_functionParam478 = 0;
            float sjt_functionParam479;
            sjs_string* sjt_parent311 = 0;

#line 19 "lib/sj-lib-ui/loop.sj"
            sjt_cast50 = g_mainloop_frames;
#line 19
            sjt_cast51 = ticks - g_mainloop_lasttick;
#line 19
            fps = ((float)sjt_cast50 * 1000.0f) / (float)sjt_cast51;
#line 19
            sjt_call124._refCount = 1;
#line 20
            sjt_call124.offset = 0;
#line 20
            sjt_call124.count = 5;
#line 20
            sjt_call124.data._refCount = 1;
#line 20
            sjt_call124.data.v = &sjg_string46;
#line 20
            sjf_array_char(&sjt_call124.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call124._isnullterminated = false;
#line 16
            sjf_string(&sjt_call124);
#line 20 "lib/sj-lib-ui/loop.sj"
            sjt_parent311 = &sjt_call124;
#line 20
            sjt_functionParam479 = fps;
#line 20
            sjf_f32_asstring(sjt_functionParam479, &sjt_call125);
#line 20
            sjt_functionParam478 = &sjt_call125;
#line 20
            sjf_string_add(sjt_parent311, sjt_functionParam478, &sjt_call123);
#line 20
            sjt_functionParam477 = &sjt_call123;
#line 20
            sjf_debug_writeline(sjt_functionParam477);
#line 21
            g_mainloop_lasttick = ticks;
#line 22
            g_mainloop_frames = 0;
        }
    }

#line 7 "lib/sj-lib-ui/windowRenderer.sj"
    sjt_parent312 = &g_rootwindowrenderer;
#line 7
    sjf_windowrenderer_getsize(sjt_parent312, &size);
#line 27 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent313 = &g_rootscene;
#line 27 "lib/sj-lib-ui/loop.sj"
    sjt_functionParam480 = &size;
#line 27
    sjf_scene2d_setsize(sjt_parent313, sjt_functionParam480);
#line 8 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent314 = &g_rootscene;
#line 8
    sjf_scene2d_start(sjt_parent314);
#line 8
    rect._refCount = 1;
#line 29 "lib/sj-lib-ui/loop.sj"
    rect.x = 0;
#line 29
    rect.y = 0;
#line 29
    rect.w = (&size)->w;
#line 29
    rect.h = (&size)->h;
#line 29
    sjf_rect(&rect);
#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent315 = &g_looplastrect;
#line 30 "lib/sj-lib-ui/loop.sj"
    sjt_functionParam481 = &rect;
#line 30
    sjf_rect_isequal(sjt_parent315, sjt_functionParam481, &sjt_capture90);
#line 30
    result14 = !sjt_capture90;
    if (result14) {
        sjs_rect* sjt_interfaceParam20 = 0;
        sji_element sjt_parent316 = { 0 };

#line 4 "lib/sj-lib-ui/element.sj"
        sjt_parent316 = g_root;
#line 31 "lib/sj-lib-ui/loop.sj"
        sjt_interfaceParam20 = &rect;
#line 31
        sjt_parent316._vtbl->setrect(sjt_parent316._parent, sjt_interfaceParam20);
    }

#line 5 "lib/sj-lib-ui/element.sj"
    sjt_parent317 = g_root;
#line 33 "lib/sj-lib-ui/loop.sj"
    sjt_interfaceParam21 = &g_rootscene;
#line 33
    sjt_parent317._vtbl->render(sjt_parent317._parent, sjt_interfaceParam21);
#line 19 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent318 = &g_rootscene;
#line 19
    sjf_scene2d_end(sjt_parent318);
#line 22 "lib/sj-lib-ui/windowRenderer.sj"
    sjt_parent319 = &g_rootwindowrenderer;
#line 22
    sjf_windowrenderer_present(sjt_parent319);
#line 38 "lib/sj-lib-ui/loop.sj"
    SDL_Event e;
#line 39
    while(SDL_PollEvent( &e ) != 0) {
#line 41
        mouse_eventtype = int32_empty;
#line 42
        mouse_x = 0;
#line 43
        mouse_y = 0;
#line 44
        mouse_isleftdown = false;
#line 47
        switch (e.type) {
#line 48
            case SDL_QUIT:
#line 49
            shouldappcontinue = false;
#line 50
            break;
#line 51
            case SDL_MOUSEBUTTONDOWN:
#line 52
            mouse_eventtype.isvalid = true;
#line 53
            mouse_eventtype.value = g_mouseeventtype_down;
#line 54
            mouse_x = e.button.x;
#line 55
            mouse_y = e.button.y;
#line 56
            mouse_isleftdown = e.button.state & SDL_BUTTON(SDL_BUTTON_LEFT);
#line 57
            break;
#line 58
            case SDL_MOUSEBUTTONUP:
#line 59
            mouse_eventtype.isvalid = true;
#line 60
            mouse_eventtype.value = g_mouseeventtype_up;
#line 61
            mouse_x = e.button.x;
#line 62
            mouse_y = e.button.y;
#line 63
            mouse_isleftdown = e.button.state & SDL_BUTTON(SDL_BUTTON_LEFT);
#line 64
            break;
#line 65
            case SDL_MOUSEMOTION:
#line 66
            mouse_eventtype.isvalid = true;
#line 67
            mouse_eventtype.value = g_mouseeventtype_move;
#line 68
            mouse_x = e.motion.x;
#line 69
            mouse_y = e.motion.y;
#line 70
            mouse_isleftdown = SDL_GetGlobalMouseState(0, 0) & SDL_BUTTON(SDL_BUTTON_LEFT);
#line 71
            break;
#line 72
        }
#line 75
        shouldcontinue = true;
        if (mouse_eventtype.isvalid) {
            int32_t ifValue13;
            int32_option sjt_getValue4;

#line 76 "lib/sj-lib-ui/loop.sj"
            sjt_getValue4 = mouse_eventtype;
#line 76
            ifValue13 = sjt_getValue4.value;
            if ((g_mouse_captureelement._parent != 0)) {
                sji_element ifValue14 = { 0 };
                sjs_mouseevent sjt_call126 = { -1 };
                bool sjt_funcold25;
                sjs_mouseevent* sjt_interfaceParam22 = 0;
                sji_element sjt_parent320 = { 0 };

#line 77 "lib/sj-lib-ui/loop.sj"
                ifValue14 = g_mouse_captureelement;
                if (ifValue14._parent != 0) {
                    ifValue14._parent->_refCount++;
                }

#line 6 "lib/sj-lib-ui/element.sj"
                sjt_parent320 = ifValue14;
#line 6
                sjt_funcold25 = shouldcontinue;
#line 6
                sjt_call126._refCount = 1;
#line 78 "lib/sj-lib-ui/loop.sj"
                sjt_call126.eventtype = ifValue13;
#line 78
                sjt_call126.point._refCount = 1;
#line 80
                sjt_call126.point.x = mouse_x;
#line 80
                sjt_call126.point.y = mouse_y;
#line 80
                sjf_point(&sjt_call126.point);
#line 81
                sjt_call126.iscaptured = true;
#line 78
                sjt_call126.isleftdown = mouse_isleftdown;
#line 78
                sjf_mouseevent(&sjt_call126);
#line 78
                sjt_interfaceParam22 = &sjt_call126;
#line 78
                sjt_parent320._vtbl->firemouseevent(sjt_parent320._parent, sjt_interfaceParam22, &sjt_funcold25);
#line 6 "lib/sj-lib-ui/element.sj"
                shouldcontinue = sjt_funcold25;

                if (ifValue14._parent != 0) {
                    ifValue14._parent->_refCount--;
                    if (ifValue14._parent->_refCount <= 0) {
                        ifValue14._vtbl->destroy(ifValue14._parent);
                        free(ifValue14._parent);
                    }
                }
                if (sjt_call126._refCount == 1) { sjf_mouseevent_destroy(&sjt_call126); }
;
            } else {
                sjs_mouseevent sjt_call127 = { -1 };
                bool sjt_funcold26;
                sjs_mouseevent* sjt_interfaceParam23 = 0;
                sji_element sjt_parent321 = { 0 };

#line 6 "lib/sj-lib-ui/element.sj"
                sjt_parent321 = g_root;
#line 6
                sjt_funcold26 = shouldcontinue;
#line 6
                sjt_call127._refCount = 1;
#line 86 "lib/sj-lib-ui/loop.sj"
                sjt_call127.eventtype = ifValue13;
#line 86
                sjt_call127.point._refCount = 1;
#line 88
                sjt_call127.point.x = mouse_x;
#line 88
                sjt_call127.point.y = mouse_y;
#line 88
                sjf_point(&sjt_call127.point);
#line 89
                sjt_call127.iscaptured = false;
#line 86
                sjt_call127.isleftdown = mouse_isleftdown;
#line 86
                sjf_mouseevent(&sjt_call127);
#line 86
                sjt_interfaceParam23 = &sjt_call127;
#line 86
                sjt_parent321._vtbl->firemouseevent(sjt_parent321._parent, sjt_interfaceParam23, &sjt_funcold26);
#line 6 "lib/sj-lib-ui/element.sj"
                shouldcontinue = sjt_funcold26;

                if (sjt_call127._refCount == 1) { sjf_mouseevent_destroy(&sjt_call127); }
;
            }
        }

#line 96
    }
#line 99
    g_mainloop_shouldcontinue = shouldappcontinue;

    if (rect._refCount == 1) { sjf_rect_destroy(&rect); }
;
    if (size._refCount == 1) { sjf_size_destroy(&size); }
;
    if (sjt_call123._refCount == 1) { sjf_string_destroy(&sjt_call123); }
;
    if (sjt_call124._refCount == 1) { sjf_string_destroy(&sjt_call124); }
;
    if (sjt_call125._refCount == 1) { sjf_string_destroy(&sjt_call125); }
;
}

void sjf_margin(sjs_margin* _this) {
}

void sjf_margin_copy(sjs_margin* _this, sjs_margin* _from) {
#line 1 "lib/sj-lib-ui/margin.sj"
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
#line 1 "lib/sj-lib-ui/mat4.sj"
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
#line 95 "lib/sj-lib-ui/mat4.sj"
    (*_return) = (((((((((((((((((((((((((_parent->m03 * _parent->m12) * _parent->m21) * _parent->m30) - (((_parent->m02 * _parent->m13) * _parent->m21) * _parent->m30)) - (((_parent->m03 * _parent->m11) * _parent->m22) * _parent->m30)) + (((_parent->m01 * _parent->m13) * _parent->m22) * _parent->m30)) + (((_parent->m02 * _parent->m11) * _parent->m23) * _parent->m30)) - (((_parent->m01 * _parent->m12) * _parent->m23) * _parent->m30)) - (((_parent->m03 * _parent->m12) * _parent->m20) * _parent->m31)) + (((_parent->m02 * _parent->m13) * _parent->m20) * _parent->m31)) + (((_parent->m03 * _parent->m10) * _parent->m22) * _parent->m31)) - (((_parent->m00 * _parent->m13) * _parent->m22) * _parent->m31)) - (((_parent->m02 * _parent->m10) * _parent->m23) * _parent->m31)) + (((_parent->m00 * _parent->m12) * _parent->m23) * _parent->m31)) + (((_parent->m03 * _parent->m11) * _parent->m20) * _parent->m32)) - (((_parent->m01 * _parent->m13) * _parent->m20) * _parent->m32)) - (((_parent->m03 * _parent->m10) * _parent->m21) * _parent->m32)) + (((_parent->m00 * _parent->m13) * _parent->m21) * _parent->m32)) + (((_parent->m01 * _parent->m10) * _parent->m23) * _parent->m32)) - (((_parent->m00 * _parent->m11) * _parent->m23) * _parent->m32)) - (((_parent->m02 * _parent->m11) * _parent->m20) * _parent->m33)) + (((_parent->m01 * _parent->m12) * _parent->m20) * _parent->m33)) + (((_parent->m02 * _parent->m10) * _parent->m21) * _parent->m33)) - (((_parent->m00 * _parent->m12) * _parent->m21) * _parent->m33)) - (((_parent->m01 * _parent->m10) * _parent->m22) * _parent->m33)) + (((_parent->m00 * _parent->m11) * _parent->m22) * _parent->m33);
}

void sjf_mat4_heap(sjs_mat4* _this) {
}

void sjf_mat4_identity(sjs_mat4* _return) {
    _return->_refCount = 1;
#line 126 "lib/sj-lib-ui/mat4.sj"
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
#line 126 "lib/sj-lib-ui/mat4.sj"
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
    float sjt_capture45;
    float sjt_functionParam201;
    sjs_mat4* sjt_parent131 = 0;
    sjs_mat4 t = { -1 };

    t._refCount = 1;
#line 73 "lib/sj-lib-ui/mat4.sj"
    t.m00 = ((((((_parent->m12 * _parent->m23) * _parent->m31) - ((_parent->m13 * _parent->m22) * _parent->m31)) + ((_parent->m13 * _parent->m21) * _parent->m32)) - ((_parent->m11 * _parent->m23) * _parent->m32)) - ((_parent->m12 * _parent->m21) * _parent->m33)) + ((_parent->m11 * _parent->m22) * _parent->m33);
#line 74
    t.m01 = ((((((_parent->m03 * _parent->m22) * _parent->m31) - ((_parent->m02 * _parent->m23) * _parent->m31)) - ((_parent->m03 * _parent->m21) * _parent->m32)) + ((_parent->m01 * _parent->m23) * _parent->m32)) + ((_parent->m02 * _parent->m21) * _parent->m33)) - ((_parent->m01 * _parent->m22) * _parent->m33);
#line 75
    t.m02 = ((((((_parent->m02 * _parent->m13) * _parent->m31) - ((_parent->m03 * _parent->m12) * _parent->m31)) + ((_parent->m03 * _parent->m11) * _parent->m32)) - ((_parent->m01 * _parent->m13) * _parent->m32)) - ((_parent->m02 * _parent->m11) * _parent->m33)) + ((_parent->m01 * _parent->m12) * _parent->m33);
#line 76
    t.m03 = ((((((_parent->m03 * _parent->m12) * _parent->m21) - ((_parent->m02 * _parent->m13) * _parent->m21)) - ((_parent->m03 * _parent->m11) * _parent->m22)) + ((_parent->m01 * _parent->m13) * _parent->m22)) + ((_parent->m02 * _parent->m11) * _parent->m23)) - ((_parent->m01 * _parent->m12) * _parent->m23);
#line 77
    t.m10 = ((((((_parent->m13 * _parent->m22) * _parent->m30) - ((_parent->m12 * _parent->m23) * _parent->m30)) - ((_parent->m13 * _parent->m20) * _parent->m32)) + ((_parent->m10 * _parent->m23) * _parent->m32)) + ((_parent->m12 * _parent->m20) * _parent->m33)) - ((_parent->m10 * _parent->m22) * _parent->m33);
#line 78
    t.m11 = ((((((_parent->m02 * _parent->m23) * _parent->m30) - ((_parent->m03 * _parent->m22) * _parent->m30)) + ((_parent->m03 * _parent->m20) * _parent->m32)) - ((_parent->m00 * _parent->m23) * _parent->m32)) - ((_parent->m02 * _parent->m20) * _parent->m33)) + ((_parent->m00 * _parent->m22) * _parent->m33);
#line 79
    t.m12 = ((((((_parent->m03 * _parent->m12) * _parent->m30) - ((_parent->m02 * _parent->m13) * _parent->m30)) - ((_parent->m03 * _parent->m10) * _parent->m32)) + ((_parent->m00 * _parent->m13) * _parent->m32)) + ((_parent->m02 * _parent->m10) * _parent->m33)) - ((_parent->m00 * _parent->m12) * _parent->m33);
#line 80
    t.m13 = ((((((_parent->m02 * _parent->m13) * _parent->m20) - ((_parent->m03 * _parent->m12) * _parent->m20)) + ((_parent->m03 * _parent->m10) * _parent->m22)) - ((_parent->m00 * _parent->m13) * _parent->m22)) - ((_parent->m02 * _parent->m10) * _parent->m23)) + ((_parent->m00 * _parent->m12) * _parent->m23);
#line 81
    t.m20 = ((((((_parent->m11 * _parent->m23) * _parent->m30) - ((_parent->m13 * _parent->m21) * _parent->m30)) + ((_parent->m13 * _parent->m20) * _parent->m31)) - ((_parent->m10 * _parent->m23) * _parent->m31)) - ((_parent->m11 * _parent->m20) * _parent->m33)) + ((_parent->m10 * _parent->m21) * _parent->m33);
#line 82
    t.m21 = ((((((_parent->m03 * _parent->m21) * _parent->m30) - ((_parent->m01 * _parent->m23) * _parent->m30)) - ((_parent->m03 * _parent->m20) * _parent->m31)) + ((_parent->m00 * _parent->m23) * _parent->m31)) + ((_parent->m01 * _parent->m20) * _parent->m33)) - ((_parent->m00 * _parent->m21) * _parent->m33);
#line 83
    t.m22 = ((((((_parent->m01 * _parent->m13) * _parent->m30) - ((_parent->m03 * _parent->m11) * _parent->m30)) + ((_parent->m03 * _parent->m10) * _parent->m31)) - ((_parent->m00 * _parent->m13) * _parent->m31)) - ((_parent->m01 * _parent->m10) * _parent->m33)) + ((_parent->m00 * _parent->m11) * _parent->m33);
#line 84
    t.m23 = ((((((_parent->m03 * _parent->m11) * _parent->m20) - ((_parent->m01 * _parent->m13) * _parent->m20)) - ((_parent->m03 * _parent->m10) * _parent->m21)) + ((_parent->m00 * _parent->m13) * _parent->m21)) + ((_parent->m01 * _parent->m10) * _parent->m23)) - ((_parent->m00 * _parent->m11) * _parent->m23);
#line 85
    t.m30 = ((((((_parent->m12 * _parent->m21) * _parent->m30) - ((_parent->m11 * _parent->m22) * _parent->m30)) - ((_parent->m12 * _parent->m20) * _parent->m31)) + ((_parent->m10 * _parent->m22) * _parent->m31)) + ((_parent->m11 * _parent->m20) * _parent->m32)) - ((_parent->m10 * _parent->m21) * _parent->m32);
#line 86
    t.m31 = ((((((_parent->m01 * _parent->m22) * _parent->m30) - ((_parent->m02 * _parent->m21) * _parent->m30)) + ((_parent->m02 * _parent->m20) * _parent->m31)) - ((_parent->m00 * _parent->m22) * _parent->m31)) - ((_parent->m01 * _parent->m20) * _parent->m32)) + ((_parent->m00 * _parent->m21) * _parent->m32);
#line 87
    t.m32 = ((((((_parent->m02 * _parent->m11) * _parent->m30) - ((_parent->m01 * _parent->m12) * _parent->m30)) - ((_parent->m02 * _parent->m10) * _parent->m31)) + ((_parent->m00 * _parent->m12) * _parent->m31)) + ((_parent->m01 * _parent->m10) * _parent->m32)) - ((_parent->m00 * _parent->m11) * _parent->m32);
#line 88
    t.m33 = ((((((_parent->m01 * _parent->m12) * _parent->m20) - ((_parent->m02 * _parent->m11) * _parent->m20)) + ((_parent->m02 * _parent->m10) * _parent->m21)) - ((_parent->m00 * _parent->m12) * _parent->m21)) - ((_parent->m01 * _parent->m10) * _parent->m22)) + ((_parent->m00 * _parent->m11) * _parent->m22);
#line 88
    sjf_mat4(&t);
#line 40
    sjt_parent131 = &t;
#line 40
    sjf_mat4_determinant(_parent, &sjt_capture45);
#line 91
    sjt_functionParam201 = 1.0f / sjt_capture45;
#line 91
    sjf_mat4_multiplyf32(sjt_parent131, sjt_functionParam201, _return);

    if (t._refCount == 1) { sjf_mat4_destroy(&t); }
;
}

void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4** _return) {
    float sjt_capture46;
    float sjt_functionParam202;
    sjs_mat4* sjt_parent132 = 0;
    sjs_mat4 t = { -1 };

    t._refCount = 1;
#line 73 "lib/sj-lib-ui/mat4.sj"
    t.m00 = ((((((_parent->m12 * _parent->m23) * _parent->m31) - ((_parent->m13 * _parent->m22) * _parent->m31)) + ((_parent->m13 * _parent->m21) * _parent->m32)) - ((_parent->m11 * _parent->m23) * _parent->m32)) - ((_parent->m12 * _parent->m21) * _parent->m33)) + ((_parent->m11 * _parent->m22) * _parent->m33);
#line 74
    t.m01 = ((((((_parent->m03 * _parent->m22) * _parent->m31) - ((_parent->m02 * _parent->m23) * _parent->m31)) - ((_parent->m03 * _parent->m21) * _parent->m32)) + ((_parent->m01 * _parent->m23) * _parent->m32)) + ((_parent->m02 * _parent->m21) * _parent->m33)) - ((_parent->m01 * _parent->m22) * _parent->m33);
#line 75
    t.m02 = ((((((_parent->m02 * _parent->m13) * _parent->m31) - ((_parent->m03 * _parent->m12) * _parent->m31)) + ((_parent->m03 * _parent->m11) * _parent->m32)) - ((_parent->m01 * _parent->m13) * _parent->m32)) - ((_parent->m02 * _parent->m11) * _parent->m33)) + ((_parent->m01 * _parent->m12) * _parent->m33);
#line 76
    t.m03 = ((((((_parent->m03 * _parent->m12) * _parent->m21) - ((_parent->m02 * _parent->m13) * _parent->m21)) - ((_parent->m03 * _parent->m11) * _parent->m22)) + ((_parent->m01 * _parent->m13) * _parent->m22)) + ((_parent->m02 * _parent->m11) * _parent->m23)) - ((_parent->m01 * _parent->m12) * _parent->m23);
#line 77
    t.m10 = ((((((_parent->m13 * _parent->m22) * _parent->m30) - ((_parent->m12 * _parent->m23) * _parent->m30)) - ((_parent->m13 * _parent->m20) * _parent->m32)) + ((_parent->m10 * _parent->m23) * _parent->m32)) + ((_parent->m12 * _parent->m20) * _parent->m33)) - ((_parent->m10 * _parent->m22) * _parent->m33);
#line 78
    t.m11 = ((((((_parent->m02 * _parent->m23) * _parent->m30) - ((_parent->m03 * _parent->m22) * _parent->m30)) + ((_parent->m03 * _parent->m20) * _parent->m32)) - ((_parent->m00 * _parent->m23) * _parent->m32)) - ((_parent->m02 * _parent->m20) * _parent->m33)) + ((_parent->m00 * _parent->m22) * _parent->m33);
#line 79
    t.m12 = ((((((_parent->m03 * _parent->m12) * _parent->m30) - ((_parent->m02 * _parent->m13) * _parent->m30)) - ((_parent->m03 * _parent->m10) * _parent->m32)) + ((_parent->m00 * _parent->m13) * _parent->m32)) + ((_parent->m02 * _parent->m10) * _parent->m33)) - ((_parent->m00 * _parent->m12) * _parent->m33);
#line 80
    t.m13 = ((((((_parent->m02 * _parent->m13) * _parent->m20) - ((_parent->m03 * _parent->m12) * _parent->m20)) + ((_parent->m03 * _parent->m10) * _parent->m22)) - ((_parent->m00 * _parent->m13) * _parent->m22)) - ((_parent->m02 * _parent->m10) * _parent->m23)) + ((_parent->m00 * _parent->m12) * _parent->m23);
#line 81
    t.m20 = ((((((_parent->m11 * _parent->m23) * _parent->m30) - ((_parent->m13 * _parent->m21) * _parent->m30)) + ((_parent->m13 * _parent->m20) * _parent->m31)) - ((_parent->m10 * _parent->m23) * _parent->m31)) - ((_parent->m11 * _parent->m20) * _parent->m33)) + ((_parent->m10 * _parent->m21) * _parent->m33);
#line 82
    t.m21 = ((((((_parent->m03 * _parent->m21) * _parent->m30) - ((_parent->m01 * _parent->m23) * _parent->m30)) - ((_parent->m03 * _parent->m20) * _parent->m31)) + ((_parent->m00 * _parent->m23) * _parent->m31)) + ((_parent->m01 * _parent->m20) * _parent->m33)) - ((_parent->m00 * _parent->m21) * _parent->m33);
#line 83
    t.m22 = ((((((_parent->m01 * _parent->m13) * _parent->m30) - ((_parent->m03 * _parent->m11) * _parent->m30)) + ((_parent->m03 * _parent->m10) * _parent->m31)) - ((_parent->m00 * _parent->m13) * _parent->m31)) - ((_parent->m01 * _parent->m10) * _parent->m33)) + ((_parent->m00 * _parent->m11) * _parent->m33);
#line 84
    t.m23 = ((((((_parent->m03 * _parent->m11) * _parent->m20) - ((_parent->m01 * _parent->m13) * _parent->m20)) - ((_parent->m03 * _parent->m10) * _parent->m21)) + ((_parent->m00 * _parent->m13) * _parent->m21)) + ((_parent->m01 * _parent->m10) * _parent->m23)) - ((_parent->m00 * _parent->m11) * _parent->m23);
#line 85
    t.m30 = ((((((_parent->m12 * _parent->m21) * _parent->m30) - ((_parent->m11 * _parent->m22) * _parent->m30)) - ((_parent->m12 * _parent->m20) * _parent->m31)) + ((_parent->m10 * _parent->m22) * _parent->m31)) + ((_parent->m11 * _parent->m20) * _parent->m32)) - ((_parent->m10 * _parent->m21) * _parent->m32);
#line 86
    t.m31 = ((((((_parent->m01 * _parent->m22) * _parent->m30) - ((_parent->m02 * _parent->m21) * _parent->m30)) + ((_parent->m02 * _parent->m20) * _parent->m31)) - ((_parent->m00 * _parent->m22) * _parent->m31)) - ((_parent->m01 * _parent->m20) * _parent->m32)) + ((_parent->m00 * _parent->m21) * _parent->m32);
#line 87
    t.m32 = ((((((_parent->m02 * _parent->m11) * _parent->m30) - ((_parent->m01 * _parent->m12) * _parent->m30)) - ((_parent->m02 * _parent->m10) * _parent->m31)) + ((_parent->m00 * _parent->m12) * _parent->m31)) + ((_parent->m01 * _parent->m10) * _parent->m32)) - ((_parent->m00 * _parent->m11) * _parent->m32);
#line 88
    t.m33 = ((((((_parent->m01 * _parent->m12) * _parent->m20) - ((_parent->m02 * _parent->m11) * _parent->m20)) + ((_parent->m02 * _parent->m10) * _parent->m21)) - ((_parent->m00 * _parent->m12) * _parent->m21)) - ((_parent->m01 * _parent->m10) * _parent->m22)) + ((_parent->m00 * _parent->m11) * _parent->m22);
#line 88
    sjf_mat4(&t);
#line 40
    sjt_parent132 = &t;
#line 40
    sjf_mat4_determinant(_parent, &sjt_capture46);
#line 91
    sjt_functionParam202 = 1.0f / sjt_capture46;
#line 91
    sjf_mat4_multiplyf32_heap(sjt_parent132, sjt_functionParam202, _return);

    if (t._refCount == 1) { sjf_mat4_destroy(&t); }
;
}

void sjf_mat4_lookatlh(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return) {
    sjs_vec3 sjt_call7 = { -1 };
    float sjt_capture10;
    float sjt_capture11;
    float sjt_capture12;
    sjs_vec3* sjt_functionParam38 = 0;
    sjs_vec3* sjt_functionParam41 = 0;
    sjs_vec3* sjt_functionParam42 = 0;
    sjs_vec3* sjt_functionParam43 = 0;
    sjs_vec3* sjt_functionParam44 = 0;
    sjs_vec3* sjt_functionParam45 = 0;
    sjs_vec3* sjt_parent32 = 0;
    sjs_vec3* sjt_parent33 = 0;
    sjs_vec3* sjt_parent34 = 0;
    sjs_vec3* sjt_parent35 = 0;
    sjs_vec3* sjt_parent36 = 0;
    sjs_vec3* sjt_parent37 = 0;
    sjs_vec3* sjt_parent38 = 0;
    sjs_vec3* sjt_parent39 = 0;
    sjs_vec3 temp = { -1 };
    sjs_vec3 xaxis = { -1 };
    sjs_vec3 yaxis = { -1 };
    sjs_vec3 zaxis = { -1 };

#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_parent32 = target;
#line 133
    sjt_functionParam38 = camera;
#line 133
    sjf_vec3_subtract(sjt_parent32, sjt_functionParam38, &temp);
#line 38 "lib/sj-lib-ui/vec3.sj"
    sjt_parent33 = &temp;
#line 38
    sjf_vec3_normalize(sjt_parent33, &zaxis);
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_parent35 = up;
#line 136
    sjt_functionParam41 = &zaxis;
#line 136
    sjf_vec3_cross(sjt_parent35, sjt_functionParam41, &sjt_call7);
#line 136
    sjt_parent34 = &sjt_call7;
#line 136
    sjf_vec3_normalize(sjt_parent34, &xaxis);
#line 47 "lib/sj-lib-ui/vec3.sj"
    sjt_parent36 = &zaxis;
#line 137 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam42 = &xaxis;
#line 137
    sjf_vec3_cross(sjt_parent36, sjt_functionParam42, &yaxis);
#line 137
    _return->_refCount = 1;
#line 138
    _return->m00 = (&xaxis)->x;
#line 138
    _return->m01 = (&yaxis)->x;
#line 138
    _return->m02 = (&zaxis)->x;
#line 142
    _return->m03 = 0.0f;
#line 138
    _return->m10 = (&xaxis)->y;
#line 138
    _return->m11 = (&yaxis)->y;
#line 138
    _return->m12 = (&zaxis)->y;
#line 146
    _return->m13 = 0.0f;
#line 138
    _return->m20 = (&xaxis)->z;
#line 138
    _return->m21 = (&yaxis)->z;
#line 138
    _return->m22 = (&zaxis)->z;
#line 150
    _return->m23 = 0.0f;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent37 = &xaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam43 = camera;
#line 133
    sjf_vec3_dot(sjt_parent37, sjt_functionParam43, &sjt_capture10);
#line 151
    _return->m30 = 0.0f - sjt_capture10;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent38 = &yaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam44 = camera;
#line 133
    sjf_vec3_dot(sjt_parent38, sjt_functionParam44, &sjt_capture11);
#line 152
    _return->m31 = 0.0f - sjt_capture11;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent39 = &zaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam45 = camera;
#line 133
    sjf_vec3_dot(sjt_parent39, sjt_functionParam45, &sjt_capture12);
#line 153
    _return->m32 = 0.0f - sjt_capture12;
#line 154
    _return->m33 = 1.0f;
#line 154
    sjf_mat4(_return);

    if (sjt_call7._refCount == 1) { sjf_vec3_destroy(&sjt_call7); }
;
    if (temp._refCount == 1) { sjf_vec3_destroy(&temp); }
;
    if (xaxis._refCount == 1) { sjf_vec3_destroy(&xaxis); }
;
    if (yaxis._refCount == 1) { sjf_vec3_destroy(&yaxis); }
;
    if (zaxis._refCount == 1) { sjf_vec3_destroy(&zaxis); }
;
}

void sjf_mat4_lookatlh_heap(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4** _return) {
    sjs_vec3 sjt_call8 = { -1 };
    float sjt_capture13;
    float sjt_capture14;
    float sjt_capture15;
    sjs_vec3* sjt_functionParam46 = 0;
    sjs_vec3* sjt_functionParam47 = 0;
    sjs_vec3* sjt_functionParam48 = 0;
    sjs_vec3* sjt_functionParam49 = 0;
    sjs_vec3* sjt_functionParam50 = 0;
    sjs_vec3* sjt_functionParam51 = 0;
    sjs_vec3* sjt_parent40 = 0;
    sjs_vec3* sjt_parent41 = 0;
    sjs_vec3* sjt_parent42 = 0;
    sjs_vec3* sjt_parent43 = 0;
    sjs_vec3* sjt_parent44 = 0;
    sjs_vec3* sjt_parent45 = 0;
    sjs_vec3* sjt_parent46 = 0;
    sjs_vec3* sjt_parent47 = 0;
    sjs_vec3 temp = { -1 };
    sjs_vec3 xaxis = { -1 };
    sjs_vec3 yaxis = { -1 };
    sjs_vec3 zaxis = { -1 };

#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_parent40 = target;
#line 133
    sjt_functionParam46 = camera;
#line 133
    sjf_vec3_subtract(sjt_parent40, sjt_functionParam46, &temp);
#line 38 "lib/sj-lib-ui/vec3.sj"
    sjt_parent41 = &temp;
#line 38
    sjf_vec3_normalize(sjt_parent41, &zaxis);
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_parent43 = up;
#line 136
    sjt_functionParam47 = &zaxis;
#line 136
    sjf_vec3_cross(sjt_parent43, sjt_functionParam47, &sjt_call8);
#line 136
    sjt_parent42 = &sjt_call8;
#line 136
    sjf_vec3_normalize(sjt_parent42, &xaxis);
#line 47 "lib/sj-lib-ui/vec3.sj"
    sjt_parent44 = &zaxis;
#line 137 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam48 = &xaxis;
#line 137
    sjf_vec3_cross(sjt_parent44, sjt_functionParam48, &yaxis);
#line 137
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
#line 137
    (*_return)->_refCount = 1;
#line 138
    (*_return)->m00 = (&xaxis)->x;
#line 138
    (*_return)->m01 = (&yaxis)->x;
#line 138
    (*_return)->m02 = (&zaxis)->x;
#line 142
    (*_return)->m03 = 0.0f;
#line 138
    (*_return)->m10 = (&xaxis)->y;
#line 138
    (*_return)->m11 = (&yaxis)->y;
#line 138
    (*_return)->m12 = (&zaxis)->y;
#line 146
    (*_return)->m13 = 0.0f;
#line 138
    (*_return)->m20 = (&xaxis)->z;
#line 138
    (*_return)->m21 = (&yaxis)->z;
#line 138
    (*_return)->m22 = (&zaxis)->z;
#line 150
    (*_return)->m23 = 0.0f;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent45 = &xaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam49 = camera;
#line 133
    sjf_vec3_dot(sjt_parent45, sjt_functionParam49, &sjt_capture13);
#line 151
    (*_return)->m30 = 0.0f - sjt_capture13;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent46 = &yaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam50 = camera;
#line 133
    sjf_vec3_dot(sjt_parent46, sjt_functionParam50, &sjt_capture14);
#line 152
    (*_return)->m31 = 0.0f - sjt_capture14;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent47 = &zaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam51 = camera;
#line 133
    sjf_vec3_dot(sjt_parent47, sjt_functionParam51, &sjt_capture15);
#line 153
    (*_return)->m32 = 0.0f - sjt_capture15;
#line 154
    (*_return)->m33 = 1.0f;
#line 154
    sjf_mat4_heap((*_return));

    if (sjt_call8._refCount == 1) { sjf_vec3_destroy(&sjt_call8); }
;
    if (temp._refCount == 1) { sjf_vec3_destroy(&temp); }
;
    if (xaxis._refCount == 1) { sjf_vec3_destroy(&xaxis); }
;
    if (yaxis._refCount == 1) { sjf_vec3_destroy(&yaxis); }
;
    if (zaxis._refCount == 1) { sjf_vec3_destroy(&zaxis); }
;
}

void sjf_mat4_multiply(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4* _return) {
    _return->_refCount = 1;
#line 21 "lib/sj-lib-ui/mat4.sj"
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
#line 21 "lib/sj-lib-ui/mat4.sj"
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
#line 42 "lib/sj-lib-ui/mat4.sj"
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
#line 42 "lib/sj-lib-ui/mat4.sj"
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
#line 64 "lib/sj-lib-ui/mat4.sj"
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
#line 64 "lib/sj-lib-ui/mat4.sj"
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
    float result7;

    _return->_refCount = 1;
#line 172 "lib/sj-lib-ui/mat4.sj"
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
    result7 = -2.0f;
#line 176
    _return->m22 = result7 / (zfar - znear);
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
    float result8;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 172 "lib/sj-lib-ui/mat4.sj"
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
    result8 = -2.0f;
#line 176
    (*_return)->m22 = result8 / (zfar - znear);
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
    float sjt_capture8;
    float sjt_functionParam32;
    float xscale;
    float yscale;

#line 159 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam32 = (fovy / 180.0f) / 2.0f;
#line 159
    sjf_f32_tan(sjt_functionParam32, &sjt_capture8);
#line 159
    yscale = 1.0f / sjt_capture8;
#line 160
    xscale = yscale * aspect;
#line 160
    _return->_refCount = 1;
#line 161
    _return->m00 = xscale;
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 161
    _return->m11 = yscale;
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
    float sjt_capture9;
    float sjt_functionParam33;
    float xscale;
    float yscale;

#line 159 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam33 = (fovy / 180.0f) / 2.0f;
#line 159
    sjf_f32_tan(sjt_functionParam33, &sjt_capture9);
#line 159
    yscale = 1.0f / sjt_capture9;
#line 160
    xscale = yscale * aspect;
#line 160
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
#line 160
    (*_return)->_refCount = 1;
#line 161
    (*_return)->m00 = xscale;
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 161
    (*_return)->m11 = yscale;
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
#line 213 "lib/sj-lib-ui/mat4.sj"
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
#line 213 "lib/sj-lib-ui/mat4.sj"
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
#line 99 "lib/sj-lib-ui/mat4.sj"
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
#line 99 "lib/sj-lib-ui/mat4.sj"
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
    float sjt_functionParam92;
    float sjt_functionParam93;
    sji_model sjt_parent64 = { 0 };
    sji_model sjt_parent65 = { 0 };

#line 11 "lib/sj-lib-ui/model.sj"
    sjt_parent64 = l;
#line 12
    sjt_parent64._vtbl->getz(sjt_parent64._parent, &sjt_functionParam92);
#line 11
    sjt_parent65 = r;
#line 12
    sjt_parent65._vtbl->getz(sjt_parent65._parent, &sjt_functionParam93);
#line 12
    sjf_f32_compare(sjt_functionParam92, sjt_functionParam93, _return);
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
    sjs_string* sjt_functionParam346 = 0;
    sjs_string* sjt_functionParam359 = 0;
    sjs_string* sjt_functionParam360 = 0;
    bool sjt_functionParam361;
    sjs_string* sjt_functionParam362 = 0;
    sjs_string* sjt_functionParam363 = 0;
    bool sjt_functionParam364;
    sjs_string* sjt_parent239 = 0;
    sjs_string* sjt_parent240 = 0;
    sjs_string* sjt_parent241 = 0;
    sjs_string* sjt_parent242 = 0;
    sjs_string* sjt_parent243 = 0;
    sjs_point* sjt_parent248 = 0;

    sjt_call65._refCount = 1;
#line 56 "lib/sj-lib-ui/mouse.sj"
    sjt_call65.offset = 0;
#line 56
    sjt_call65.count = 8;
#line 56
    sjt_call65.data._refCount = 1;
#line 56
    sjt_call65.data.v = &sjg_string33;
#line 56
    sjf_array_char(&sjt_call65.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call65._isnullterminated = false;
#line 16
    sjf_string(&sjt_call65);
#line 56 "lib/sj-lib-ui/mouse.sj"
    sjt_parent243 = &sjt_call65;
#line 5 "lib/sj-lib-ui/point.sj"
    sjt_parent248 = &_parent->point;
#line 5
    sjf_point_asstring(sjt_parent248, &sjt_call66);
#line 56 "lib/sj-lib-ui/mouse.sj"
    sjt_functionParam346 = &sjt_call66;
#line 56
    sjf_string_add(sjt_parent243, sjt_functionParam346, &sjt_call64);
#line 56
    sjt_parent242 = &sjt_call64;
#line 56
    sjt_call75._refCount = 1;
#line 56
    sjt_call75.offset = 0;
#line 56
    sjt_call75.count = 14;
#line 56
    sjt_call75.data._refCount = 1;
#line 56
    sjt_call75.data.v = &sjg_string35;
#line 56
    sjf_array_char(&sjt_call75.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call75._isnullterminated = false;
#line 16
    sjf_string(&sjt_call75);
#line 56 "lib/sj-lib-ui/mouse.sj"
    sjt_functionParam359 = &sjt_call75;
#line 56
    sjf_string_add(sjt_parent242, sjt_functionParam359, &sjt_call63);
#line 56
    sjt_parent241 = &sjt_call63;
#line 56
    sjt_functionParam361 = _parent->iscaptured;
#line 56
    sjf_bool_asstring(sjt_functionParam361, &sjt_call76);
#line 56
    sjt_functionParam360 = &sjt_call76;
#line 56
    sjf_string_add(sjt_parent241, sjt_functionParam360, &sjt_call62);
#line 56
    sjt_parent240 = &sjt_call62;
#line 56
    sjt_call77._refCount = 1;
#line 56
    sjt_call77.offset = 0;
#line 56
    sjt_call77.count = 14;
#line 56
    sjt_call77.data._refCount = 1;
#line 56
    sjt_call77.data.v = &sjg_string38;
#line 56
    sjf_array_char(&sjt_call77.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call77._isnullterminated = false;
#line 16
    sjf_string(&sjt_call77);
#line 56 "lib/sj-lib-ui/mouse.sj"
    sjt_functionParam362 = &sjt_call77;
#line 56
    sjf_string_add(sjt_parent240, sjt_functionParam362, &sjt_call61);
#line 56
    sjt_parent239 = &sjt_call61;
#line 56
    sjt_functionParam364 = _parent->isleftdown;
#line 56
    sjf_bool_asstring(sjt_functionParam364, &sjt_call78);
#line 56
    sjt_functionParam363 = &sjt_call78;
#line 56
    sjf_string_add(sjt_parent239, sjt_functionParam363, _return);

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
    sjs_string* sjt_functionParam365 = 0;
    sjs_string* sjt_functionParam366 = 0;
    sjs_string* sjt_functionParam367 = 0;
    bool sjt_functionParam368;
    sjs_string* sjt_functionParam369 = 0;
    sjs_string* sjt_functionParam370 = 0;
    bool sjt_functionParam371;
    sjs_string* sjt_parent249 = 0;
    sjs_string* sjt_parent250 = 0;
    sjs_string* sjt_parent251 = 0;
    sjs_string* sjt_parent252 = 0;
    sjs_string* sjt_parent253 = 0;
    sjs_point* sjt_parent254 = 0;

    sjt_call83._refCount = 1;
#line 56 "lib/sj-lib-ui/mouse.sj"
    sjt_call83.offset = 0;
#line 56
    sjt_call83.count = 8;
#line 56
    sjt_call83.data._refCount = 1;
#line 56
    sjt_call83.data.v = &sjg_string33;
#line 56
    sjf_array_char(&sjt_call83.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call83._isnullterminated = false;
#line 16
    sjf_string(&sjt_call83);
#line 56 "lib/sj-lib-ui/mouse.sj"
    sjt_parent253 = &sjt_call83;
#line 5 "lib/sj-lib-ui/point.sj"
    sjt_parent254 = &_parent->point;
#line 5
    sjf_point_asstring(sjt_parent254, &sjt_call84);
#line 56 "lib/sj-lib-ui/mouse.sj"
    sjt_functionParam365 = &sjt_call84;
#line 56
    sjf_string_add(sjt_parent253, sjt_functionParam365, &sjt_call82);
#line 56
    sjt_parent252 = &sjt_call82;
#line 56
    sjt_call85._refCount = 1;
#line 56
    sjt_call85.offset = 0;
#line 56
    sjt_call85.count = 14;
#line 56
    sjt_call85.data._refCount = 1;
#line 56
    sjt_call85.data.v = &sjg_string35;
#line 56
    sjf_array_char(&sjt_call85.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call85._isnullterminated = false;
#line 16
    sjf_string(&sjt_call85);
#line 56 "lib/sj-lib-ui/mouse.sj"
    sjt_functionParam366 = &sjt_call85;
#line 56
    sjf_string_add(sjt_parent252, sjt_functionParam366, &sjt_call81);
#line 56
    sjt_parent251 = &sjt_call81;
#line 56
    sjt_functionParam368 = _parent->iscaptured;
#line 56
    sjf_bool_asstring(sjt_functionParam368, &sjt_call86);
#line 56
    sjt_functionParam367 = &sjt_call86;
#line 56
    sjf_string_add(sjt_parent251, sjt_functionParam367, &sjt_call80);
#line 56
    sjt_parent250 = &sjt_call80;
#line 56
    sjt_call87._refCount = 1;
#line 56
    sjt_call87.offset = 0;
#line 56
    sjt_call87.count = 14;
#line 56
    sjt_call87.data._refCount = 1;
#line 56
    sjt_call87.data.v = &sjg_string38;
#line 56
    sjf_array_char(&sjt_call87.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call87._isnullterminated = false;
#line 16
    sjf_string(&sjt_call87);
#line 56 "lib/sj-lib-ui/mouse.sj"
    sjt_functionParam369 = &sjt_call87;
#line 56
    sjf_string_add(sjt_parent250, sjt_functionParam369, &sjt_call79);
#line 56
    sjt_parent249 = &sjt_call79;
#line 56
    sjt_functionParam371 = _parent->isleftdown;
#line 56
    sjf_bool_asstring(sjt_functionParam371, &sjt_call88);
#line 56
    sjt_functionParam370 = &sjt_call88;
#line 56
    sjf_string_add_heap(sjt_parent249, sjt_functionParam370, _return);

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
#line 38 "lib/sj-lib-ui/mouse.sj"
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
    bool shouldcontinue;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;
    sjs_array_heap_iface_element* sjt_parent26 = 0;

#line 45 "lib/sj-lib-ui/mouse.sj"
    shouldcontinue = true;
#line 46
    sjt_forStart5 = 0;
#line 44
    sjt_parent26 = children;
#line 44
    sjf_array_heap_iface_element_getcount(sjt_parent26, &sjt_forEnd5);
#line 46
    i = sjt_forEnd5 - 1;
    while (i >= sjt_forStart5) {
        if (shouldcontinue) {
            sji_element child = { 0 };
            bool sjt_funcold4;
            int32_t sjt_functionParam27;
            sjs_mouseevent* sjt_interfaceParam9 = 0;
            sjs_array_heap_iface_element* sjt_parent27 = 0;
            sji_element sjt_parent28 = { 0 };

#line 44 "lib/sj-lib-ui/mouse.sj"
            sjt_parent27 = children;
#line 46
            sjt_functionParam27 = i;
#line 46
            sjf_array_heap_iface_element_getat_heap(sjt_parent27, sjt_functionParam27, &child);
#line 6 "lib/sj-lib-ui/element.sj"
            sjt_parent28 = child;
#line 6
            sjt_funcold4 = shouldcontinue;
#line 49 "lib/sj-lib-ui/mouse.sj"
            sjt_interfaceParam9 = _parent;
#line 49
            sjt_parent28._vtbl->firemouseevent(sjt_parent28._parent, sjt_interfaceParam9, &sjt_funcold4);
#line 6 "lib/sj-lib-ui/element.sj"
            shouldcontinue = sjt_funcold4;

            if (child._parent != 0) {
                child._parent->_refCount--;
                if (child._parent->_refCount <= 0) {
                    child._vtbl->destroy(child._parent);
                    free(child._parent);
                }
            }
        }

#line 46 "lib/sj-lib-ui/mouse.sj"
        i--;
    }

#line 44
    (*_return) = shouldcontinue;
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
    int32_t sjt_functionParam347;
    int32_t sjt_functionParam348;
    sjs_string* sjt_functionParam349 = 0;
    sjs_string* sjt_functionParam350 = 0;
    int32_t sjt_functionParam351;
    int32_t sjt_functionParam352;
    sjs_string* sjt_parent244 = 0;
    sjs_string* sjt_parent245 = 0;

#line 5 "lib/sj-lib-ui/point.sj"
    sjt_functionParam347 = _parent->x;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam348 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam347, sjt_functionParam348, &sjt_call68);
#line 5 "lib/sj-lib-ui/point.sj"
    sjt_parent245 = &sjt_call68;
#line 5
    sjt_call69._refCount = 1;
#line 5
    sjt_call69.offset = 0;
#line 5
    sjt_call69.count = 2;
#line 5
    sjt_call69.data._refCount = 1;
#line 5
    sjt_call69.data.v = &sjg_string34;
#line 5
    sjf_array_char(&sjt_call69.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call69._isnullterminated = false;
#line 16
    sjf_string(&sjt_call69);
#line 5 "lib/sj-lib-ui/point.sj"
    sjt_functionParam349 = &sjt_call69;
#line 5
    sjf_string_add(sjt_parent245, sjt_functionParam349, &sjt_call67);
#line 5
    sjt_parent244 = &sjt_call67;
#line 5
    sjt_functionParam351 = _parent->y;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam352 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam351, sjt_functionParam352, &sjt_call70);
#line 5 "lib/sj-lib-ui/point.sj"
    sjt_functionParam350 = &sjt_call70;
#line 5
    sjf_string_add(sjt_parent244, sjt_functionParam350, _return);

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
    int32_t sjt_functionParam353;
    int32_t sjt_functionParam354;
    sjs_string* sjt_functionParam355 = 0;
    sjs_string* sjt_functionParam356 = 0;
    int32_t sjt_functionParam357;
    int32_t sjt_functionParam358;
    sjs_string* sjt_parent246 = 0;
    sjs_string* sjt_parent247 = 0;

#line 5 "lib/sj-lib-ui/point.sj"
    sjt_functionParam353 = _parent->x;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam354 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam353, sjt_functionParam354, &sjt_call72);
#line 5 "lib/sj-lib-ui/point.sj"
    sjt_parent247 = &sjt_call72;
#line 5
    sjt_call73._refCount = 1;
#line 5
    sjt_call73.offset = 0;
#line 5
    sjt_call73.count = 2;
#line 5
    sjt_call73.data._refCount = 1;
#line 5
    sjt_call73.data.v = &sjg_string34;
#line 5
    sjf_array_char(&sjt_call73.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call73._isnullterminated = false;
#line 16
    sjf_string(&sjt_call73);
#line 5 "lib/sj-lib-ui/point.sj"
    sjt_functionParam355 = &sjt_call73;
#line 5
    sjf_string_add(sjt_parent247, sjt_functionParam355, &sjt_call71);
#line 5
    sjt_parent246 = &sjt_call71;
#line 5
    sjt_functionParam357 = _parent->y;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam358 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam357, sjt_functionParam358, &sjt_call74);
#line 5 "lib/sj-lib-ui/point.sj"
    sjt_functionParam356 = &sjt_call74;
#line 5
    sjf_string_add_heap(sjt_parent246, sjt_functionParam356, _return);

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
#line 1 "lib/sj-lib-ui/point.sj"
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
        bool sjt_capture85;

        if (_parent->y <= point->y) {
            bool sjt_capture86;

            if (point->x < (_parent->x + _parent->w)) {
#line 12 "lib/sj-lib-ui/rect.sj"
                sjt_capture86 = (point->y < (_parent->y + _parent->h));
            } else {
#line 12 "lib/sj-lib-ui/rect.sj"
                sjt_capture86 = false;
            }

#line 12 "lib/sj-lib-ui/rect.sj"
            sjt_capture85 = sjt_capture86;
        } else {
#line 12 "lib/sj-lib-ui/rect.sj"
            sjt_capture85 = false;
        }

#line 12 "lib/sj-lib-ui/rect.sj"
        (*_return) = sjt_capture85;
    } else {
#line 12 "lib/sj-lib-ui/rect.sj"
        (*_return) = false;
    }
}

void sjf_rect_copy(sjs_rect* _this, sjs_rect* _from) {
#line 1 "lib/sj-lib-ui/rect.sj"
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
        bool sjt_capture5;

        if (_parent->y == rect->y) {
            bool sjt_capture6;

            if (_parent->w == rect->w) {
#line 16 "lib/sj-lib-ui/rect.sj"
                sjt_capture6 = (_parent->h == rect->h);
            } else {
#line 16 "lib/sj-lib-ui/rect.sj"
                sjt_capture6 = false;
            }

#line 16 "lib/sj-lib-ui/rect.sj"
            sjt_capture5 = sjt_capture6;
        } else {
#line 16 "lib/sj-lib-ui/rect.sj"
            sjt_capture5 = false;
        }

#line 16 "lib/sj-lib-ui/rect.sj"
        (*_return) = sjt_capture5;
    } else {
#line 16 "lib/sj-lib-ui/rect.sj"
        (*_return) = false;
    }
}

void sjf_rect_subtractmargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    _return->_refCount = 1;
#line 8 "lib/sj-lib-ui/rect.sj"
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
#line 8 "lib/sj-lib-ui/rect.sj"
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
#line 1 "lib/sj-lib-ui/renderbuffer.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 1
    _this->id = _from->id;
#line 8
    _this->id = _from->id;
#line 9
    glid_retain(_this->id);
}

void sjf_renderbuffer_destroy(sjs_renderbuffer* _this) {
#line 13 "lib/sj-lib-ui/renderbuffer.sj"
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
#line 105 "lib/sj-lib-ui/loop.sj"
    #ifdef EMSCRIPTEN
#line 106
    emscripten_set_main_loop((em_callback_func)sjf_mainloop, 0, 0);
#line 107
    exit(0);
#line 108
    #else
#line 109
    while (g_mainloop_shouldcontinue) {
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
#line 1 "lib/sj-lib-ui/scene2d.sj"
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
    sjs_rect* sjt_functionParam195 = 0;
    sjs_rect* sjt_functionParam196 = 0;

#line 20 "lib/sj-lib-ui/scene2d.sj"
    sjt_functionParam195 = &_parent->windowrect;
#line 20
    sjt_functionParam196 = &_parent->windowrect;
#line 20
    sjf_glpopviewport(sjt_functionParam195, sjt_functionParam196);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result6;
    bool sjt_capture38;
    sjs_mat4 sjt_funcold12 = { -1 };
    sjs_mat4 sjt_funcold13 = { -1 };
    sjs_mat4 sjt_funcold14 = { -1 };
    sjs_size* sjt_functionParam159 = 0;
    sjs_size* sjt_parent104 = 0;

#line 27 "lib/sj-lib-ui/size.sj"
    sjt_parent104 = &_parent->_size;
#line 27 "lib/sj-lib-ui/scene2d.sj"
    sjt_functionParam159 = size;
#line 27
    sjf_size_isequal(sjt_parent104, sjt_functionParam159, &sjt_capture38);
#line 28
    result6 = !sjt_capture38;
    if (result6) {
        float result10;
        float result9;
        int32_t sjt_cast8;
        int32_t sjt_cast9;
        float sjt_functionParam160;
        float sjt_functionParam161;
        float sjt_functionParam162;
        float sjt_functionParam163;
        float sjt_functionParam164;
        float sjt_functionParam165;
        float sjt_functionParam166;
        float sjt_functionParam167;
        float sjt_functionParam168;

        if (_parent->_size._refCount == 1) { sjf_size_destroy(&_parent->_size); }
;
#line 27 "lib/sj-lib-ui/scene2d.sj"
        sjf_size_copy(&_parent->_size, size);
#line 30
        sjt_functionParam160 = 0.0f;
#line 30
        sjt_cast8 = (&_parent->_size)->w;
#line 30
        sjt_functionParam161 = (float)sjt_cast8;
#line 30
        sjt_cast9 = 0 - (&_parent->_size)->h;
#line 30
        sjt_functionParam162 = (float)sjt_cast9;
#line 30
        sjt_functionParam163 = 0.0f;
#line 30
        result9 = -1.0f;
#line 30
        sjt_functionParam164 = result9;
#line 30
        sjt_functionParam165 = 1.0f;
#line 30
        sjf_mat4_orthographic(sjt_functionParam160, sjt_functionParam161, sjt_functionParam162, sjt_functionParam163, sjt_functionParam164, sjt_functionParam165, &sjt_funcold12);
#line 30
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
#line 170 "lib/sj-lib-ui/mat4.sj"
        sjf_mat4_copy(&_parent->projection, &sjt_funcold12);
#line 31 "lib/sj-lib-ui/scene2d.sj"
        sjt_functionParam166 = 1.0f;
#line 31
        result10 = -1.0f;
#line 31
        sjt_functionParam167 = result10;
#line 31
        sjt_functionParam168 = 1.0f;
#line 31
        sjf_mat4_scale(sjt_functionParam166, sjt_functionParam167, sjt_functionParam168, &sjt_funcold13);
#line 31
        if (_parent->model._refCount == 1) { sjf_mat4_destroy(&_parent->model); }
;
#line 213 "lib/sj-lib-ui/mat4.sj"
        sjf_mat4_copy(&_parent->model, &sjt_funcold13);
#line 213
        sjf_mat4_identity(&sjt_funcold14);
#line 213
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
    sjs_rect* sjt_functionParam192 = 0;
    sjs_rect* sjt_functionParam193 = 0;

    sjt_funcold20._refCount = 1;
#line 9 "lib/sj-lib-ui/scene2d.sj"
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
#line 1 "lib/sj-lib-ui/rect.sj"
    sjf_rect_copy(&_parent->windowrect, &sjt_funcold20);
#line 10 "lib/sj-lib-ui/scene2d.sj"
    sjt_functionParam192 = &_parent->windowrect;
#line 10
    sjt_functionParam193 = &_parent->windowrect;
#line 10
    sjf_glpushviewport(sjt_functionParam192, sjt_functionParam193);
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
#line 1 "lib/sj-lib-ui/scene2dModel.sj"
    sjs_string* copyoption14 = (_from->id._refCount != -1 ? &_from->id : 0);
    if (copyoption14 != 0) {
        _this->id._refCount = 1;
#line 1 "lib/sj-lib-ui/scene2dModel.sj"
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
    sjs_point* sjt_functionParam291 = 0;
    sjs_rect* sjt_functionParam292 = 0;
    sjs_mat4* sjt_functionParam293 = 0;
    sjs_mat4* sjt_functionParam294 = 0;
    sjs_mat4* sjt_functionParam295 = 0;
    sjs_mat4* sjt_functionParam296 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent201 = 0;
    sjs_mat4* sjt_parent202 = 0;
    sjs_vec2 texture = { -1 };

#line 43 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_parent201 = &_parent->vertexbuffer;
#line 72 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam291 = &mouseevent->point;
#line 72
    sjt_functionParam292 = &_parent->_scenerect;
#line 72
    sjt_functionParam293 = &_parent->_projection;
#line 72
    sjt_functionParam294 = &_parent->_view;
#line 19 "lib/sj-lib-ui/mat4.sj"
    sjt_parent202 = &_parent->_world;
#line 72 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam296 = &_parent->model;
#line 72
    sjf_mat4_multiply(sjt_parent202, sjt_functionParam296, &sjt_call30);
#line 72
    sjt_functionParam295 = &sjt_call30;
#line 72
    sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture(sjt_parent201, sjt_functionParam291, sjt_functionParam292, sjt_functionParam293, sjt_functionParam294, sjt_functionParam295, &texture);
    if (((texture._refCount != -1 ? &texture : 0) != 0)) {
        sjs_vec2* ifValue7 = 0;
        sjs_mouseevent newmouseevent = { -1 };
        sjs_point scenepoint = { -1 };
        sjs_lambda3 sjt_call58 = { -1 };
        float sjt_cast19;
        int32_t sjt_cast20;
        float sjt_cast21;
        int32_t sjt_cast22;
        int32_t sjt_functionParam344;
        cb_string_heap_string sjt_functionParam345;
        sjs_array_heap_iface_element* sjt_functionParam384 = 0;
        sjs_log* sjt_parent236 = 0;
        sjs_mouseevent* sjt_parent265 = 0;
        bool sjt_void1;

#line 73 "lib/sj-lib-ui/scene2dModel.sj"
        ifValue7 = (texture._refCount != -1 ? &texture : 0);
#line 22 "lib/sj-lib-common/log.sj"
        sjt_parent236 = &g_log;
#line 74 "lib/sj-lib-ui/scene2dModel.sj"
        sjt_functionParam344 = 153;
#line 74
        sjs_lambda3* lambainit2;
#line 74
        sjt_call58._refCount = 1;
#line 71
        sjt_call58.lambdaparam3 = mouseevent;
#line 74
        sjt_call58.lambdaparam4 = ifValue7;
#line 71
        sjt_call58.lambdaparam5 = mouseevent;
#line 71
        sjf_lambda3(&sjt_call58);
#line 74
        lambainit2 = &sjt_call58;
#line 74
        sjt_functionParam345._parent = (sjs_object*)lambainit2;
#line 74
        sjt_functionParam345._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda3_invoke;
#line 74
        sjt_functionParam345._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda3_invoke_heap;
#line 74
        sjf_log_trace(sjt_parent236, sjt_functionParam344, sjt_functionParam345);
#line 74
        scenepoint._refCount = 1;
#line 76
        sjt_cast20 = (&_parent->texturesize)->w;
#line 76
        sjt_cast19 = ifValue7->x * (float)sjt_cast20;
#line 76
        scenepoint.x = (int32_t)sjt_cast19;
#line 77
        sjt_cast22 = (&_parent->texturesize)->h;
#line 77
        sjt_cast21 = ifValue7->y * (float)sjt_cast22;
#line 77
        scenepoint.y = ((&_parent->texturesize)->h - 1) - (int32_t)sjt_cast21;
#line 77
        sjf_point(&scenepoint);
#line 77
        newmouseevent._refCount = 1;
#line 79
        newmouseevent.eventtype = mouseevent->eventtype;
#line 79
        newmouseevent.point._refCount = 1;
#line 79
        sjf_point_copy(&newmouseevent.point, &scenepoint);
#line 79
        newmouseevent.iscaptured = mouseevent->iscaptured;
#line 79
        newmouseevent.isleftdown = mouseevent->isleftdown;
#line 79
        sjf_mouseevent(&newmouseevent);
#line 44 "lib/sj-lib-ui/mouse.sj"
        sjt_parent265 = &newmouseevent;
#line 86 "lib/sj-lib-ui/scene2dModel.sj"
        sjt_functionParam384 = &_parent->children;
#line 86
        sjf_mouseevent_firechildren(sjt_parent265, sjt_functionParam384, &sjt_void1);

        if (newmouseevent._refCount == 1) { sjf_mouseevent_destroy(&newmouseevent); }
;
        if (scenepoint._refCount == 1) { sjf_point_destroy(&scenepoint); }
;
        if (sjt_call58._refCount == 1) { sjf_lambda3_destroy(&sjt_call58); }
;
    } else {
        sjs_lambda2 sjt_call103 = { -1 };
        int32_t sjt_functionParam385;
        cb_string_heap_string sjt_functionParam386;
        sjs_log* sjt_parent266 = 0;

#line 22 "lib/sj-lib-common/log.sj"
        sjt_parent266 = &g_log;
#line 88 "lib/sj-lib-ui/scene2dModel.sj"
        sjt_functionParam385 = 153;
#line 88
        sjs_lambda2* lambainit1;
#line 88
        sjt_call103._refCount = 1;
#line 71
        sjt_call103.lambdaparam1 = mouseevent;
#line 71
        sjt_call103.lambdaparam2 = mouseevent;
#line 71
        sjf_lambda2(&sjt_call103);
#line 88
        lambainit1 = &sjt_call103;
#line 88
        sjt_functionParam386._parent = (sjs_object*)lambainit1;
#line 88
        sjt_functionParam386._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda2_invoke;
#line 88
        sjt_functionParam386._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda2_invoke_heap;
#line 88
        sjf_log_trace(sjt_parent266, sjt_functionParam385, sjt_functionParam386);

        if (sjt_call103._refCount == 1) { sjf_lambda2_destroy(&sjt_call103); }
;
    }

    if (sjt_call30._refCount == 1) { sjf_mat4_destroy(&sjt_call30); }
;
    if (texture._refCount == 1) { sjf_vec2_destroy(&texture); }
;
}

void sjf_scene2dmodel_getcenter(sjs_scene2dmodel* _parent, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 33 "lib/sj-lib-ui/scene2dModel.sj"
    sjf_vec3_copy(_return, &_parent->center);
}

void sjf_scene2dmodel_getcenter_heap(sjs_scene2dmodel* _parent, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
#line 33 "lib/sj-lib-ui/scene2dModel.sj"
    sjf_vec3_copy((*_return), &_parent->center);
}

void sjf_scene2dmodel_getclasstype(sjs_object* _this, int* _return) {
    *_return = 153;
}

void sjf_scene2dmodel_getworld(sjs_scene2dmodel* _parent, sjs_mat4* _return) {
    sjs_mat4* sjt_functionParam181 = 0;
    sjs_mat4* sjt_parent113 = 0;

#line 19 "lib/sj-lib-ui/mat4.sj"
    sjt_parent113 = &_parent->_world;
#line 34 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam181 = &_parent->model;
#line 34
    sjf_mat4_multiply(sjt_parent113, sjt_functionParam181, _return);
}

void sjf_scene2dmodel_getworld_heap(sjs_scene2dmodel* _parent, sjs_mat4** _return) {
    sjs_mat4* sjt_functionParam182 = 0;
    sjs_mat4* sjt_parent114 = 0;

#line 19 "lib/sj-lib-ui/mat4.sj"
    sjt_parent114 = &_parent->_world;
#line 34 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam182 = &_parent->model;
#line 34
    sjf_mat4_multiply_heap(sjt_parent114, sjt_functionParam182, _return);
}

void sjf_scene2dmodel_getz(sjs_scene2dmodel* _parent, float* _return) {
#line 32 "lib/sj-lib-ui/scene2dModel.sj"
    (*_return) = (&_parent->_projectedcenter)->z;
}

void sjf_scene2dmodel_heap(sjs_scene2dmodel* _this) {
    int32_t i;
    sjs_rect rect = { -1 };
    sjs_string sjt_call12 = { -1 };
    int32_t sjt_forEnd10;
    int32_t sjt_forStart10;
    sjs_renderbuffer sjt_funcold10 = { -1 };
    sjs_framebuffer sjt_funcold8 = { -1 };
    sjs_texture sjt_funcold9 = { -1 };
    sjs_size* sjt_functionParam111 = 0;
    sjs_size* sjt_functionParam112 = 0;
    sjs_size* sjt_functionParam113 = 0;
    sjs_framebuffer* sjt_functionParam122 = 0;
    int32_t sjt_functionParam123;
    sjs_texture* sjt_functionParam124 = 0;
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
    int32_t sjt_functionParam137;
    int32_t sjt_functionParam138;
    int32_t sjt_functionParam139;
    sjs_size* sjt_functionParam140 = 0;
    int32_t sjt_functionParam141;
    void* sjt_functionParam142;
    int32_t sjt_functionParam143;
    int32_t sjt_functionParam144;
    sjs_texture* sjt_functionParam145 = 0;
    int32_t sjt_functionParam146;
    sjs_renderbuffer* sjt_functionParam147 = 0;
    int32_t sjt_functionParam148;
    sjs_size* sjt_functionParam149 = 0;
    int32_t sjt_functionParam150;
    sjs_renderbuffer* sjt_functionParam151 = 0;
    sjs_framebuffer* sjt_functionParam158 = 0;
    sjs_size* sjt_functionParam169 = 0;
    sjs_scene2d* sjt_parent105 = 0;
    sjs_array_heap_iface_element* sjt_parent106 = 0;
    int32_t status;

    if (((_this->id._refCount != -1 ? &_this->id : 0) != 0)) {
        sjs_string* ifValue12 = 0;
        sjs_scene2dmodel* sjt_cast7 = 0;
        sjs_string* sjt_functionParam109 = 0;
        sji_model sjt_functionParam110 = { 0 };
        sjs_hash_string_weak_iface_model* sjt_parent86 = 0;

#line 92 "lib/sj-lib-ui/scene2dModel.sj"
        ifValue12 = (_this->id._refCount != -1 ? &_this->id : 0);
#line 38 "lib/sj-lib-common/hash.sj"
        sjt_parent86 = &g_modelsbyid;
#line 93 "lib/sj-lib-ui/scene2dModel.sj"
        sjt_functionParam109 = ifValue12;
#line 1
        sjt_cast7 = _this;
#line 1 "lib/sj-lib-ui/model.sj"
        sjf_scene2dmodel_as_sji_model(sjt_cast7, &sjt_functionParam110);
#line 1
        delete_cb weakptrcb14 = { &sjt_functionParam110._parent, weakptr_clear };
#line 1
        if (sjt_functionParam110._parent != 0) { weakptr_cb_add(sjt_functionParam110._parent, weakptrcb14); }
#line 1
        sjf_hash_string_weak_iface_model_setat(sjt_parent86, sjt_functionParam109, sjt_functionParam110);

        delete_cb weakptrcb15 = { &sjt_functionParam110._parent, weakptr_clear };
        if (sjt_functionParam110._parent != 0) { weakptr_cb_remove(sjt_functionParam110._parent, weakptrcb15); }
    }

#line 96 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam111 = &_this->texturesize;
#line 96
    sjf_glgenframebuffer(sjt_functionParam111, &sjt_funcold8);
#line 96
    if (_this->_framebuffer._refCount == 1) { sjf_framebuffer_destroy(&_this->_framebuffer); }
;
#line 208 "lib/sj-lib-ui/gl.sj"
    sjf_framebuffer_copy(&_this->_framebuffer, &sjt_funcold8);
#line 97 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam112 = &_this->texturesize;
#line 97
    sjf_glgentexture(sjt_functionParam112, &sjt_funcold9);
#line 97
    if (_this->_texture._refCount == 1) { sjf_texture_destroy(&_this->_texture); }
;
#line 216 "lib/sj-lib-ui/gl.sj"
    sjf_texture_copy(&_this->_texture, &sjt_funcold9);
#line 98 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam113 = &_this->texturesize;
#line 98
    sjf_glgenrenderbuffer(sjt_functionParam113, &sjt_funcold10);
#line 98
    if (_this->_renderbuffer._refCount == 1) { sjf_renderbuffer_destroy(&_this->_renderbuffer); }
;
#line 242 "lib/sj-lib-ui/gl.sj"
    sjf_renderbuffer_copy(&_this->_renderbuffer, &sjt_funcold10);
#line 100 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam122 = &_this->_framebuffer;
#line 100
    sjf_glpushframebuffer(sjt_functionParam122);
#line 101
    sjt_functionParam123 = g_gltexture_gl_texture_2d;
#line 101
    sjt_functionParam124 = &_this->_texture;
#line 101
    sjf_glbindtexture(sjt_functionParam123, sjt_functionParam124);
#line 102
    sjt_functionParam125 = g_gltexture_gl_texture_2d;
#line 102
    sjt_functionParam126 = g_gltextureattribute_gl_texture_wrap_s;
#line 102
    sjt_functionParam127 = g_gltexturevalue_gl_clamp_to_edge;
#line 102
    sjf_gltexparameteri(sjt_functionParam125, sjt_functionParam126, sjt_functionParam127);
#line 103
    sjt_functionParam128 = g_gltexture_gl_texture_2d;
#line 103
    sjt_functionParam129 = g_gltextureattribute_gl_texture_wrap_t;
#line 103
    sjt_functionParam130 = g_gltexturevalue_gl_clamp_to_edge;
#line 103
    sjf_gltexparameteri(sjt_functionParam128, sjt_functionParam129, sjt_functionParam130);
#line 104
    sjt_functionParam131 = g_gltexture_gl_texture_2d;
#line 104
    sjt_functionParam132 = g_gltextureattribute_gl_texture_min_filter;
#line 104
    sjt_functionParam133 = g_gltexturevalue_gl_linear;
#line 104
    sjf_gltexparameteri(sjt_functionParam131, sjt_functionParam132, sjt_functionParam133);
#line 105
    sjt_functionParam134 = g_gltexture_gl_texture_2d;
#line 105
    sjt_functionParam135 = g_gltextureattribute_gl_texture_mag_filter;
#line 105
    sjt_functionParam136 = g_gltexturevalue_gl_linear;
#line 105
    sjf_gltexparameteri(sjt_functionParam134, sjt_functionParam135, sjt_functionParam136);
#line 106
    sjt_functionParam137 = g_gltexture_gl_texture_2d;
#line 106
    sjt_functionParam138 = 0;
#line 106
    sjt_functionParam139 = g_gltextureformat_gl_rgba;
#line 106
    sjt_functionParam140 = &_this->texturesize;
#line 106
    sjt_functionParam141 = g_gltexturetype_gl_unsigned_byte;
#line 230 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam142 = 0;
#line 230
    sjf_glteximage2d(sjt_functionParam137, sjt_functionParam138, sjt_functionParam139, sjt_functionParam140, sjt_functionParam141, sjt_functionParam142);
#line 107 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam143 = g_glframebufferattachment_gl_color_attachment0;
#line 107
    sjt_functionParam144 = g_glframebuffertexture_gl_texture_2d;
#line 107
    sjt_functionParam145 = &_this->_texture;
#line 107
    sjt_functionParam146 = 0;
#line 107
    sjf_glframebuffertexture2d(sjt_functionParam143, sjt_functionParam144, sjt_functionParam145, sjt_functionParam146);
#line 109
    sjt_functionParam147 = &_this->_renderbuffer;
#line 109
    sjf_glbindrenderbuffer(sjt_functionParam147);
#line 110
    sjt_functionParam148 = g_glrenderbufferformat_gl_depth_component16;
#line 110
    sjt_functionParam149 = &_this->texturesize;
#line 110
    sjf_glrenderbufferstorage(sjt_functionParam148, sjt_functionParam149);
#line 111
    sjt_functionParam150 = g_glframebufferattachment_gl_depth_attachment;
#line 111
    sjt_functionParam151 = &_this->_renderbuffer;
#line 111
    sjf_glframebufferrenderbuffer(sjt_functionParam150, sjt_functionParam151);
#line 111
    sjf_glcheckframebufferstatus(&status);
    if (status != g_glframebufferstatus_gl_framebuffer_complete) {
        sjs_string* sjt_functionParam152 = 0;

        sjt_call12._refCount = 1;
#line 115 "lib/sj-lib-ui/scene2dModel.sj"
        sjt_call12.offset = 0;
#line 115
        sjt_call12.count = 18;
#line 115
        sjt_call12.data._refCount = 1;
#line 115
        sjt_call12.data.v = &sjg_string41;
#line 115
        sjf_array_char(&sjt_call12.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call12._isnullterminated = false;
#line 16
        sjf_string(&sjt_call12);
#line 115 "lib/sj-lib-ui/scene2dModel.sj"
        sjt_functionParam152 = &sjt_call12;
#line 115
        sjf_halt(sjt_functionParam152);
    }

#line 117
    sjt_functionParam158 = &_this->_framebuffer;
#line 117
    sjf_glpopframebuffer(sjt_functionParam158);
#line 27 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent105 = &_this->_innerscene;
#line 119 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam169 = &_this->texturesize;
#line 119
    sjf_scene2d_setsize(sjt_parent105, sjt_functionParam169);
#line 119
    rect._refCount = 1;
#line 120
    rect.x = 0;
#line 120
    rect.y = 0;
#line 120
    rect.w = (&_this->texturesize)->w;
#line 120
    rect.h = (&_this->texturesize)->h;
#line 120
    sjf_rect(&rect);
#line 121
    sjt_forStart10 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent106 = &_this->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent106, &sjt_forEnd10);
#line 121 "lib/sj-lib-ui/scene2dModel.sj"
    i = sjt_forStart10;
    while (i < sjt_forEnd10) {
        sji_element child = { 0 };
        int32_t sjt_functionParam170;
        sjs_rect* sjt_interfaceParam17 = 0;
        sjs_array_heap_iface_element* sjt_parent107 = 0;
        sji_element sjt_parent108 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent107 = &_this->children;
#line 121 "lib/sj-lib-ui/scene2dModel.sj"
        sjt_functionParam170 = i;
#line 121
        sjf_array_heap_iface_element_getat_heap(sjt_parent107, sjt_functionParam170, &child);
#line 4 "lib/sj-lib-ui/element.sj"
        sjt_parent108 = child;
#line 123 "lib/sj-lib-ui/scene2dModel.sj"
        sjt_interfaceParam17 = &rect;
#line 123
        sjt_parent108._vtbl->setrect(sjt_parent108._parent, sjt_interfaceParam17);
#line 121
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

    if (rect._refCount == 1) { sjf_rect_destroy(&rect); }
;
    if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
;
    if (sjt_funcold10._refCount == 1) { sjf_renderbuffer_destroy(&sjt_funcold10); }
;
    if (sjt_funcold8._refCount == 1) { sjf_framebuffer_destroy(&sjt_funcold8); }
;
    if (sjt_funcold9._refCount == 1) { sjf_texture_destroy(&sjt_funcold9); }
;
}

void sjf_scene2dmodel_render(sjs_scene2dmodel* _parent) {
    int32_t i;
    sjs_mat4 normalmat = { -1 };
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
    sjs_framebuffer* sjt_functionParam191 = 0;
    sjs_framebuffer* sjt_functionParam197 = 0;
    int32_t sjt_functionParam198;
    sjs_mat4* sjt_functionParam199 = 0;
    sjs_mat4* sjt_functionParam200 = 0;
    sjs_shader* sjt_functionParam203 = 0;
    int32_t sjt_functionParam204;
    int32_t sjt_functionParam205;
    int32_t sjt_functionParam206;
    sjs_texture* sjt_functionParam207 = 0;
    int32_t sjt_functionParam208;
    sjs_shader* sjt_functionParam209 = 0;
    sjs_string* sjt_functionParam210 = 0;
    sjs_mat4* sjt_functionParam211 = 0;
    int32_t sjt_functionParam212;
    sjs_shader* sjt_functionParam213 = 0;
    sjs_string* sjt_functionParam214 = 0;
    sjs_mat4* sjt_functionParam215 = 0;
    int32_t sjt_functionParam216;
    sjs_shader* sjt_functionParam217 = 0;
    sjs_string* sjt_functionParam218 = 0;
    sjs_mat4* sjt_functionParam219 = 0;
    int32_t sjt_functionParam220;
    sjs_shader* sjt_functionParam221 = 0;
    sjs_string* sjt_functionParam222 = 0;
    sjs_vec3* sjt_functionParam223 = 0;
    int32_t sjt_functionParam224;
    sjs_shader* sjt_functionParam225 = 0;
    sjs_string* sjt_functionParam226 = 0;
    sjs_vec3* sjt_functionParam227 = 0;
    int32_t sjt_functionParam228;
    sjs_shader* sjt_functionParam229 = 0;
    sjs_string* sjt_functionParam230 = 0;
    sjs_vec3* sjt_functionParam231 = 0;
    int32_t sjt_functionParam232;
    sjs_scene2d* sjt_parent123 = 0;
    sjs_array_heap_iface_element* sjt_parent124 = 0;
    sjs_scene2d* sjt_parent127 = 0;
    sjs_mat4* sjt_parent128 = 0;
    sjs_mat4* sjt_parent129 = 0;
    sjs_mat4* sjt_parent130 = 0;
    sjs_mat4* sjt_parent133 = 0;
    sjs_color* sjt_parent134 = 0;
    sjs_color* sjt_parent135 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent136 = 0;
    sjs_mat4 viewworld = { -1 };

#line 45 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam191 = &_parent->_framebuffer;
#line 45
    sjf_glpushframebuffer(sjt_functionParam191);
#line 8 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent123 = &_parent->_innerscene;
#line 8
    sjf_scene2d_start(sjt_parent123);
#line 48 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_forStart11 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent124 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent124, &sjt_forEnd11);
#line 48 "lib/sj-lib-ui/scene2dModel.sj"
    i = sjt_forStart11;
    while (i < sjt_forEnd11) {
        sji_element child = { 0 };
        int32_t sjt_functionParam194;
        sjs_scene2d* sjt_interfaceParam18 = 0;
        sjs_array_heap_iface_element* sjt_parent125 = 0;
        sji_element sjt_parent126 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent125 = &_parent->children;
#line 48 "lib/sj-lib-ui/scene2dModel.sj"
        sjt_functionParam194 = i;
#line 48
        sjf_array_heap_iface_element_getat_heap(sjt_parent125, sjt_functionParam194, &child);
#line 5 "lib/sj-lib-ui/element.sj"
        sjt_parent126 = child;
#line 50 "lib/sj-lib-ui/scene2dModel.sj"
        sjt_interfaceParam18 = &_parent->_innerscene;
#line 50
        sjt_parent126._vtbl->render(sjt_parent126._parent, sjt_interfaceParam18);
#line 48
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

#line 19 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent127 = &_parent->_innerscene;
#line 19
    sjf_scene2d_end(sjt_parent127);
#line 54 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam197 = &_parent->_framebuffer;
#line 54
    sjf_glpopframebuffer(sjt_functionParam197);
#line 56
    sjt_functionParam198 = g_glfeature_gl_depth_test;
#line 56
    sjf_glenable(sjt_functionParam198);
#line 19 "lib/sj-lib-ui/mat4.sj"
    sjt_parent129 = &_parent->_view;
#line 57 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam199 = &_parent->_world;
#line 57
    sjf_mat4_multiply(sjt_parent129, sjt_functionParam199, &sjt_call18);
#line 57
    sjt_parent128 = &sjt_call18;
#line 57
    sjt_functionParam200 = &_parent->model;
#line 57
    sjf_mat4_multiply(sjt_parent128, sjt_functionParam200, &viewworld);
#line 71 "lib/sj-lib-ui/mat4.sj"
    sjt_parent133 = &viewworld;
#line 71
    sjf_mat4_invert(sjt_parent133, &sjt_call19);
#line 58 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_parent130 = &sjt_call19;
#line 58
    sjf_mat4_transpose(sjt_parent130, &normalmat);
#line 59
    sjt_functionParam203 = &_parent->shader;
#line 59
    sjf_gluseprogram(sjt_functionParam203);
#line 60
    sjt_functionParam204 = g_glblendfunctype_gl_src_alpha;
#line 60
    sjt_functionParam205 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 60
    sjf_glblendfunc(sjt_functionParam204, sjt_functionParam205);
#line 61
    sjt_functionParam206 = g_gltexture_gl_texture_2d;
#line 61
    sjt_functionParam207 = &_parent->_texture;
#line 61
    sjf_glbindtexture(sjt_functionParam206, sjt_functionParam207);
#line 62
    sjt_functionParam209 = &_parent->shader;
#line 62
    sjt_call20._refCount = 1;
#line 62
    sjt_call20.offset = 0;
#line 62
    sjt_call20.count = 9;
#line 62
    sjt_call20.data._refCount = 1;
#line 62
    sjt_call20.data.v = &sjg_string18;
#line 62
    sjf_array_char(&sjt_call20.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call20._isnullterminated = false;
#line 16
    sjf_string(&sjt_call20);
#line 62 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam210 = &sjt_call20;
#line 62
    sjf_glgetuniformlocation(sjt_functionParam209, sjt_functionParam210, &sjt_functionParam208);
#line 62
    sjt_functionParam211 = &viewworld;
#line 62
    sjf_gluniformmat4(sjt_functionParam208, sjt_functionParam211);
#line 63
    sjt_functionParam213 = &_parent->shader;
#line 63
    sjt_call21._refCount = 1;
#line 63
    sjt_call21.offset = 0;
#line 63
    sjt_call21.count = 9;
#line 63
    sjt_call21.data._refCount = 1;
#line 63
    sjt_call21.data.v = &sjg_string19;
#line 63
    sjf_array_char(&sjt_call21.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call21._isnullterminated = false;
#line 16
    sjf_string(&sjt_call21);
#line 63 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam214 = &sjt_call21;
#line 63
    sjf_glgetuniformlocation(sjt_functionParam213, sjt_functionParam214, &sjt_functionParam212);
#line 63
    sjt_functionParam215 = &normalmat;
#line 63
    sjf_gluniformmat4(sjt_functionParam212, sjt_functionParam215);
#line 64
    sjt_functionParam217 = &_parent->shader;
#line 64
    sjt_call22._refCount = 1;
#line 64
    sjt_call22.offset = 0;
#line 64
    sjt_call22.count = 10;
#line 64
    sjt_call22.data._refCount = 1;
#line 64
    sjt_call22.data.v = &sjg_string20;
#line 64
    sjf_array_char(&sjt_call22.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call22._isnullterminated = false;
#line 16
    sjf_string(&sjt_call22);
#line 64 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam218 = &sjt_call22;
#line 64
    sjf_glgetuniformlocation(sjt_functionParam217, sjt_functionParam218, &sjt_functionParam216);
#line 64
    sjt_functionParam219 = &_parent->_projection;
#line 64
    sjf_gluniformmat4(sjt_functionParam216, sjt_functionParam219);
#line 65
    sjt_functionParam221 = &_parent->shader;
#line 65
    sjt_call23._refCount = 1;
#line 65
    sjt_call23.offset = 0;
#line 65
    sjt_call23.count = 8;
#line 65
    sjt_call23.data._refCount = 1;
#line 65
    sjt_call23.data.v = &sjg_string21;
#line 65
    sjf_array_char(&sjt_call23.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call23._isnullterminated = false;
#line 16
    sjf_string(&sjt_call23);
#line 65 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam222 = &sjt_call23;
#line 65
    sjf_glgetuniformlocation(sjt_functionParam221, sjt_functionParam222, &sjt_functionParam220);
#line 65
    sjt_functionParam223 = &(&_parent->_light)->pos;
#line 65
    sjf_gluniformvec3(sjt_functionParam220, sjt_functionParam223);
#line 66
    sjt_functionParam225 = &_parent->shader;
#line 66
    sjt_call24._refCount = 1;
#line 66
    sjt_call24.offset = 0;
#line 66
    sjt_call24.count = 12;
#line 66
    sjt_call24.data._refCount = 1;
#line 66
    sjt_call24.data.v = &sjg_string22;
#line 66
    sjf_array_char(&sjt_call24.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call24._isnullterminated = false;
#line 16
    sjf_string(&sjt_call24);
#line 66 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam226 = &sjt_call24;
#line 66
    sjf_glgetuniformlocation(sjt_functionParam225, sjt_functionParam226, &sjt_functionParam224);
#line 20 "lib/sj-lib-ui/color.sj"
    sjt_parent134 = &(&_parent->_light)->diffusecolor;
#line 20
    sjf_color_asvec3(sjt_parent134, &sjt_call25);
#line 66 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam227 = &sjt_call25;
#line 66
    sjf_gluniformvec3(sjt_functionParam224, sjt_functionParam227);
#line 67
    sjt_functionParam229 = &_parent->shader;
#line 67
    sjt_call26._refCount = 1;
#line 67
    sjt_call26.offset = 0;
#line 67
    sjt_call26.count = 9;
#line 67
    sjt_call26.data._refCount = 1;
#line 67
    sjt_call26.data.v = &sjg_string23;
#line 67
    sjf_array_char(&sjt_call26.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call26._isnullterminated = false;
#line 16
    sjf_string(&sjt_call26);
#line 67 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam230 = &sjt_call26;
#line 67
    sjf_glgetuniformlocation(sjt_functionParam229, sjt_functionParam230, &sjt_functionParam228);
#line 20 "lib/sj-lib-ui/color.sj"
    sjt_parent135 = &(&_parent->_light)->speccolor;
#line 20
    sjf_color_asvec3(sjt_parent135, &sjt_call27);
#line 67 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam231 = &sjt_call27;
#line 67
    sjf_gluniformvec3(sjt_functionParam228, sjt_functionParam231);
#line 94 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_parent136 = &_parent->vertexbuffer;
#line 68 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam232 = g_gldrawmode_gl_triangles;
#line 68
    sjf_vertexbuffer_vertex_location_texture_normal_render(sjt_parent136, sjt_functionParam232);

    if (normalmat._refCount == 1) { sjf_mat4_destroy(&normalmat); }
;
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
    if (viewworld._refCount == 1) { sjf_mat4_destroy(&viewworld); }
;
}

void sjf_scene2dmodel_renderorqueue(sjs_scene2dmodel* _parent, sjs_list_heap_iface_model* alphamodels) {
    if (_parent->hasalpha) {
        sjs_scene2dmodel* sjt_cast10 = 0;
        sji_model sjt_functionParam190 = { 0 };
        sjs_list_heap_iface_model* sjt_parent122 = 0;

#line 36 "lib/sj-lib-ui/scene2dModel.sj"
        sjt_parent122 = alphamodels;
#line 38
        sjt_cast10 = _parent;
#line 1 "lib/sj-lib-ui/model.sj"
        sjf_scene2dmodel_as_sji_model(sjt_cast10, &sjt_functionParam190);
        if (sjt_functionParam190._parent != 0) {
            sjt_functionParam190._parent->_refCount++;
        }

#line 1
        sjf_list_heap_iface_model_add(sjt_parent122, sjt_functionParam190);

        if (sjt_functionParam190._parent != 0) {
            sjt_functionParam190._parent->_refCount--;
            if (sjt_functionParam190._parent->_refCount <= 0) {
                sjt_functionParam190._vtbl->destroy(sjt_functionParam190._parent);
                free(sjt_functionParam190._parent);
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
    sjs_mat4* sjt_functionParam177 = 0;
    sjs_mat4* sjt_functionParam178 = 0;
    sjs_mat4* sjt_functionParam179 = 0;
    sjs_vec4* sjt_functionParam180 = 0;
    sjs_mat4* sjt_parent109 = 0;
    sjs_mat4* sjt_parent110 = 0;
    sjs_mat4* sjt_parent111 = 0;
    sjs_mat4* sjt_parent112 = 0;

    if (_parent->_scenerect._refCount == 1) { sjf_rect_destroy(&_parent->_scenerect); }
;
#line 22 "lib/sj-lib-ui/scene2dModel.sj"
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
#line 19 "lib/sj-lib-ui/mat4.sj"
    sjt_parent112 = &_parent->_projection;
#line 28 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_functionParam177 = &_parent->_view;
#line 28
    sjf_mat4_multiply(sjt_parent112, sjt_functionParam177, &sjt_call16);
#line 28
    sjt_parent111 = &sjt_call16;
#line 28
    sjt_functionParam178 = &_parent->_world;
#line 28
    sjf_mat4_multiply(sjt_parent111, sjt_functionParam178, &sjt_call15);
#line 28
    sjt_parent110 = &sjt_call15;
#line 28
    sjt_functionParam179 = &_parent->model;
#line 28
    sjf_mat4_multiply(sjt_parent110, sjt_functionParam179, &sjt_call14);
#line 28
    sjt_parent109 = &sjt_call14;
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
    sjt_functionParam180 = &sjt_call17;
#line 28
    sjf_mat4_multiplyvec4(sjt_parent109, sjt_functionParam180, &sjt_funcold18);
#line 28
    if (_parent->_projectedcenter._refCount == 1) { sjf_vec4_destroy(&_parent->_projectedcenter); }
;
#line 62 "lib/sj-lib-ui/mat4.sj"
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
#line 11 "lib/sj-lib-ui/scene3dElement.sj"
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
    sjs_array_heap_iface_model* sjt_parent82 = 0;

#line 67 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_forStart9 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent82 = &_parent->children;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent82, &sjt_forEnd9);
#line 67 "lib/sj-lib-ui/scene3dElement.sj"
    i = sjt_forStart9;
    while (i < sjt_forEnd9) {
        sji_model child = { 0 };
        int32_t sjt_functionParam106;
        sjs_mouseevent* sjt_interfaceParam16 = 0;
        sjs_array_heap_iface_model* sjt_parent83 = 0;
        sji_model sjt_parent84 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent83 = &_parent->children;
#line 67 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_functionParam106 = i;
#line 67
        sjf_array_heap_iface_model_getat_heap(sjt_parent83, sjt_functionParam106, &child);
#line 8 "lib/sj-lib-ui/model.sj"
        sjt_parent84 = child;
#line 66 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_interfaceParam16 = mouseevent;
#line 69
        sjt_parent84._vtbl->firemouseevent(sjt_parent84._parent, sjt_interfaceParam16);
#line 67
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

#line 71
    (*_return) = true;
}

void sjf_scene3delement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 111;
}

void sjf_scene3delement_getrect(sjs_scene3delement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 29 "lib/sj-lib-ui/scene3dElement.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_scene3delement_getrect_heap(sjs_scene3delement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 29 "lib/sj-lib-ui/scene3dElement.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_scene3delement_getsize(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 26 "lib/sj-lib-ui/scene3dElement.sj"
    _return->w = maxsize->w;
#line 26
    _return->h = maxsize->h;
#line 26
    sjf_size(_return);
}

void sjf_scene3delement_getsize_heap(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 26 "lib/sj-lib-ui/scene3dElement.sj"
    (*_return)->w = maxsize->w;
#line 26
    (*_return)->h = maxsize->h;
#line 26
    sjf_size_heap((*_return));
}

void sjf_scene3delement_heap(sjs_scene3delement* _this) {
}

void sjf_scene3delement_render(sjs_scene3delement* _parent, sjs_scene2d* scene) {
    sjs_list_heap_iface_model a = { -1 };
    int32_t i;
    int32_t sjt_forEnd6;
    int32_t sjt_forEnd7;
    int32_t sjt_forEnd8;
    int32_t sjt_forStart6;
    int32_t sjt_forStart7;
    int32_t sjt_forStart8;
    sjs_rect* sjt_functionParam103 = 0;
    sjs_rect* sjt_functionParam104 = 0;
    int32_t sjt_functionParam105;
    int32_t sjt_functionParam56;
    sjs_rect* sjt_functionParam65 = 0;
    sjs_rect* sjt_functionParam66 = 0;
    cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam91;
    sjs_array_heap_iface_model* sjt_parent48 = 0;
    sjs_array_heap_iface_model* sjt_parent59 = 0;
    sjs_list_heap_iface_model* sjt_parent63 = 0;
    sjs_list_heap_iface_model* sjt_parent67 = 0;

#line 41 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_forStart6 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent48 = &_parent->children;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent48, &sjt_forEnd6);
#line 41 "lib/sj-lib-ui/scene3dElement.sj"
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        sji_model child = { 0 };
        int32_t sjt_functionParam55;
        sjs_rect* sjt_interfaceParam10 = 0;
        sjs_mat4* sjt_interfaceParam11 = 0;
        sjs_mat4* sjt_interfaceParam12 = 0;
        sjs_mat4* sjt_interfaceParam13 = 0;
        sjs_light* sjt_interfaceParam14 = 0;
        sjs_array_heap_iface_model* sjt_parent49 = 0;
        sji_model sjt_parent50 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent49 = &_parent->children;
#line 41 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_functionParam55 = i;
#line 41
        sjf_array_heap_iface_model_getat_heap(sjt_parent49, sjt_functionParam55, &child);
#line 2 "lib/sj-lib-ui/model.sj"
        sjt_parent50 = child;
#line 43 "lib/sj-lib-ui/scene3dElement.sj"
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
        sjt_parent50._vtbl->update(sjt_parent50._parent, sjt_interfaceParam10, sjt_interfaceParam11, sjt_interfaceParam12, sjt_interfaceParam13, sjt_interfaceParam14);
#line 41
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

#line 46
    sjt_functionParam56 = g_glfeature_gl_depth_test;
#line 46
    sjf_glenable(sjt_functionParam56);
#line 47
    sjt_functionParam65 = &_parent->_rect;
#line 47
    sjt_functionParam66 = &scene->windowrect;
#line 47
    sjf_glpushviewport(sjt_functionParam65, sjt_functionParam66);
#line 47
    a._refCount = 1;
#line 47
    a.arr._refCount = 1;
#line 27 "lib/sj-lib-common/array.sj"
    a.arr.v = 0;
#line 27
    sjf_array_heap_iface_model(&a.arr);
#line 27
    sjf_list_heap_iface_model(&a);
#line 51 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_forStart7 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent59 = &_parent->children;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent59, &sjt_forEnd7);
#line 51 "lib/sj-lib-ui/scene3dElement.sj"
    i = sjt_forStart7;
    while (i < sjt_forEnd7) {
        sji_model child = { 0 };
        int32_t sjt_functionParam67;
        sjs_list_heap_iface_model* sjt_interfaceParam15 = 0;
        sjs_array_heap_iface_model* sjt_parent60 = 0;
        sji_model sjt_parent61 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent60 = &_parent->children;
#line 51 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_functionParam67 = i;
#line 51
        sjf_array_heap_iface_model_getat_heap(sjt_parent60, sjt_functionParam67, &child);
#line 6 "lib/sj-lib-ui/model.sj"
        sjt_parent61 = child;
#line 53 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_interfaceParam15 = &a;
#line 53
        sjt_parent61._vtbl->renderorqueue(sjt_parent61._parent, sjt_interfaceParam15);
#line 51
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

#line 28 "lib/sj-lib-common/list.sj"
    sjt_parent63 = &a;
#line 56 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_functionParam91._parent = (sjs_object*)1;
#line 56
    sjt_functionParam91._cb = (void(*)(sjs_object*,sji_model,sji_model, int32_t*))sjf_model_zsort_callback;
#line 56
    sjf_list_heap_iface_model_sortcb(sjt_parent63, sjt_functionParam91);
#line 57
    sjt_forStart8 = 0;
#line 4 "lib/sj-lib-common/list.sj"
    sjt_parent67 = &a;
#line 4
    sjf_list_heap_iface_model_getcount(sjt_parent67, &sjt_forEnd8);
#line 57 "lib/sj-lib-ui/scene3dElement.sj"
    i = sjt_forEnd8 - 1;
    while (i >= sjt_forStart8) {
        sji_model child = { 0 };
        int32_t sjt_functionParam95;
        sjs_list_heap_iface_model* sjt_parent69 = 0;
        sji_model sjt_parent70 = { 0 };

#line 8 "lib/sj-lib-common/list.sj"
        sjt_parent69 = &a;
#line 57 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_functionParam95 = i;
#line 57
        sjf_list_heap_iface_model_getat_heap(sjt_parent69, sjt_functionParam95, &child);
#line 7 "lib/sj-lib-ui/model.sj"
        sjt_parent70 = child;
#line 59 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_parent70._vtbl->render(sjt_parent70._parent);
#line 57
        i--;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

#line 62
    sjt_functionParam103 = &_parent->_rect;
#line 62
    sjt_functionParam104 = &scene->windowrect;
#line 62
    sjf_glpopviewport(sjt_functionParam103, sjt_functionParam104);
#line 63
    sjt_functionParam105 = g_glfeature_gl_depth_test;
#line 63
    sjf_gldisable(sjt_functionParam105);

    if (a._refCount == 1) { sjf_list_heap_iface_model_destroy(&a); }
;
}

void sjf_scene3delement_setrect(sjs_scene3delement* _parent, sjs_rect* rect_) {
    bool result3;
    bool sjt_capture7;
    sjs_mat4 sjt_funcold5 = { -1 };
    sjs_mat4 sjt_funcold6 = { -1 };
    sjs_rect* sjt_functionParam31 = 0;
    sjs_rect* sjt_parent31 = 0;

#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent31 = &_parent->_rect;
#line 31 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_functionParam31 = rect_;
#line 31
    sjf_rect_isequal(sjt_parent31, sjt_functionParam31, &sjt_capture7);
#line 32
    result3 = !sjt_capture7;
    if (result3) {
        int32_t sjt_cast4;
        int32_t sjt_cast5;
        float sjt_functionParam34;
        float sjt_functionParam35;
        float sjt_functionParam36;
        float sjt_functionParam37;
        sjs_vec3* sjt_functionParam52 = 0;
        sjs_vec3* sjt_functionParam53 = 0;
        sjs_vec3* sjt_functionParam54 = 0;

        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 31 "lib/sj-lib-ui/scene3dElement.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
#line 34
        sjt_functionParam34 = _parent->fieldofview;
#line 34
        sjt_cast4 = (&_parent->_rect)->h;
#line 34
        sjt_cast5 = (&_parent->_rect)->w;
#line 34
        sjt_functionParam35 = (float)sjt_cast4 / (float)sjt_cast5;
#line 34
        sjt_functionParam36 = _parent->znear;
#line 34
        sjt_functionParam37 = _parent->zfar;
#line 34
        sjf_mat4_perspective(sjt_functionParam34, sjt_functionParam35, sjt_functionParam36, sjt_functionParam37, &sjt_funcold5);
#line 34
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
#line 158 "lib/sj-lib-ui/mat4.sj"
        sjf_mat4_copy(&_parent->projection, &sjt_funcold5);
#line 35 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_functionParam52 = &_parent->camera;
#line 35
        sjt_functionParam53 = &_parent->lookat;
#line 35
        sjt_functionParam54 = &_parent->up;
#line 35
        sjf_mat4_lookatlh(sjt_functionParam52, sjt_functionParam53, sjt_functionParam54, &sjt_funcold6);
#line 35
        if (_parent->view._refCount == 1) { sjf_mat4_destroy(&_parent->view); }
;
#line 133 "lib/sj-lib-ui/mat4.sj"
        sjf_mat4_copy(&_parent->view, &sjt_funcold6);
    }

    if (sjt_funcold5._refCount == 1) { sjf_mat4_destroy(&sjt_funcold5); }
;
    if (sjt_funcold6._refCount == 1) { sjf_mat4_destroy(&sjt_funcold6); }
;
}

void sjf_shader(sjs_shader* _this) {
#line 15 "lib/sj-lib-ui/shader.sj"
    _this->id = shader_load(string_char(&_this->vertex), string_char(&_this->pixel));
}

void sjf_shader_copy(sjs_shader* _this, sjs_shader* _from) {
    _this->vertex._refCount = 1;
#line 7 "lib/sj-lib-ui/shader.sj"
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
#line 25 "lib/sj-lib-ui/shader.sj"
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
#line 15 "lib/sj-lib-ui/shader.sj"
    _this->id = shader_load(string_char(&_this->vertex), string_char(&_this->pixel));
}

void sjf_size(sjs_size* _this) {
}

void sjf_size_addmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    _return->_refCount = 1;
#line 20 "lib/sj-lib-ui/size.sj"
    _return->w = (_parent->w + margin->l) + margin->r;
#line 20
    _return->h = (_parent->h + margin->t) + margin->b;
#line 20
    sjf_size(_return);
}

void sjf_size_addmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 20 "lib/sj-lib-ui/size.sj"
    (*_return)->w = (_parent->w + margin->l) + margin->r;
#line 20
    (*_return)->h = (_parent->h + margin->t) + margin->b;
#line 20
    sjf_size_heap((*_return));
}

void sjf_size_copy(sjs_size* _this, sjs_size* _from) {
#line 1 "lib/sj-lib-ui/size.sj"
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
#line 28 "lib/sj-lib-ui/size.sj"
        (*_return) = (_parent->h == size->h);
    } else {
#line 28 "lib/sj-lib-ui/size.sj"
        (*_return) = false;
    }
}

void sjf_size_max(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    if (_parent->w > maxsize->w) {
#line 13 "lib/sj-lib-ui/size.sj"
        _return->w = _parent->w;
    } else {
#line 13 "lib/sj-lib-ui/size.sj"
        _return->w = maxsize->w;
    }

    if (_parent->h > maxsize->h) {
#line 13 "lib/sj-lib-ui/size.sj"
        _return->h = _parent->h;
    } else {
#line 13 "lib/sj-lib-ui/size.sj"
        _return->h = maxsize->h;
    }

    sjf_size(_return);
}

void sjf_size_max_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    if (_parent->w > maxsize->w) {
#line 13 "lib/sj-lib-ui/size.sj"
        (*_return)->w = _parent->w;
    } else {
#line 13 "lib/sj-lib-ui/size.sj"
        (*_return)->w = maxsize->w;
    }

    if (_parent->h > maxsize->h) {
#line 13 "lib/sj-lib-ui/size.sj"
        (*_return)->h = _parent->h;
    } else {
#line 13 "lib/sj-lib-ui/size.sj"
        (*_return)->h = maxsize->h;
    }

    sjf_size_heap((*_return));
}

void sjf_size_min(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    if (_parent->w < maxsize->w) {
#line 6 "lib/sj-lib-ui/size.sj"
        _return->w = _parent->w;
    } else {
#line 6 "lib/sj-lib-ui/size.sj"
        _return->w = maxsize->w;
    }

    if (_parent->h < maxsize->h) {
#line 6 "lib/sj-lib-ui/size.sj"
        _return->h = _parent->h;
    } else {
#line 6 "lib/sj-lib-ui/size.sj"
        _return->h = maxsize->h;
    }

    sjf_size(_return);
}

void sjf_size_min_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    if (_parent->w < maxsize->w) {
#line 6 "lib/sj-lib-ui/size.sj"
        (*_return)->w = _parent->w;
    } else {
#line 6 "lib/sj-lib-ui/size.sj"
        (*_return)->w = maxsize->w;
    }

    if (_parent->h < maxsize->h) {
#line 6 "lib/sj-lib-ui/size.sj"
        (*_return)->h = _parent->h;
    } else {
#line 6 "lib/sj-lib-ui/size.sj"
        (*_return)->h = maxsize->h;
    }

    sjf_size_heap((*_return));
}

void sjf_size_subtractmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    _return->_refCount = 1;
#line 24 "lib/sj-lib-ui/size.sj"
    _return->w = (_parent->w - margin->l) - margin->r;
#line 24
    _return->h = (_parent->h - margin->t) - margin->b;
#line 24
    sjf_size(_return);
}

void sjf_size_subtractmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 24 "lib/sj-lib-ui/size.sj"
    (*_return)->w = (_parent->w - margin->l) - margin->r;
#line 24
    (*_return)->h = (_parent->h - margin->t) - margin->b;
#line 24
    sjf_size_heap((*_return));
}

void sjf_spherevertexbuffer(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexbuffer_vertex_location_texture_normal* _return) {
    sjs_array_i32 indices = { -1 };
    sjs_vertex_location_texture_normal sjt_call108 = { -1 };
    int32_t sjt_forEnd20;
    int32_t sjt_forEnd22;
    int32_t sjt_forStart20;
    int32_t sjt_forStart22;
    int32_t sjt_functionParam389;
    sjs_vertex_location_texture_normal* sjt_functionParam390 = 0;
    int32_t sjt_functionParam397;
    int32_t sjt_functionParam398;
    int32_t slice;
    sjs_array_vertex_location_texture_normal vertices = { -1 };

#line 108 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjt_functionParam389 = (slices + 1) * (wedges + 1);
#line 108
    sjt_call108._refCount = 1;
#line 108
    sjt_call108.location._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
    sjt_call108.location.x = 0.0f;
#line 3
    sjt_call108.location.y = 0.0f;
#line 4
    sjt_call108.location.z = 0.0f;
#line 4
    sjf_vec3(&sjt_call108.location);
#line 4
    sjt_call108.texture._refCount = 1;
#line 2 "lib/sj-lib-ui/vec2.sj"
    sjt_call108.texture.x = 0.0f;
#line 3
    sjt_call108.texture.y = 0.0f;
#line 3
    sjf_vec2(&sjt_call108.texture);
#line 3
    sjt_call108.normal._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
    sjt_call108.normal.x = 0.0f;
#line 3
    sjt_call108.normal.y = 0.0f;
#line 4
    sjt_call108.normal.z = 0.0f;
#line 4
    sjf_vec3(&sjt_call108.normal);
#line 4
    sjf_vertex_location_texture_normal(&sjt_call108);
#line 108 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjt_functionParam390 = &sjt_call108;
#line 108
    sjf_array_create_vertex_location_texture_normal(sjt_functionParam389, sjt_functionParam390, &vertices);
#line 109
    sjt_forStart20 = 0;
#line 109
    sjt_forEnd20 = slices + 1;
#line 109
    slice = sjt_forStart20;
    while (slice < sjt_forEnd20) {
        float r0;
        float sjt_capture75;
        int32_t sjt_cast23;
        int32_t sjt_cast24;
        int32_t sjt_cast25;
        int32_t sjt_cast26;
        int32_t sjt_forEnd21;
        int32_t sjt_forStart21;
        float sjt_functionParam391;
        float sjt_functionParam392;
        float theta;
        float tv;
        int32_t wedge;
        float y0;

#line 109 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        sjt_cast23 = slice;
#line 102
        sjt_cast24 = slices;
#line 110
        tv = (float)sjt_cast23 / (float)sjt_cast24;
#line 109
        sjt_cast25 = slice;
#line 102
        sjt_cast26 = slices;
#line 111
        theta = ((g_f32_pi * (float)sjt_cast25) / (float)sjt_cast26) + g_f32_pi;
#line 112
        sjt_functionParam391 = theta;
#line 112
        sjf_f32_cos(sjt_functionParam391, &sjt_capture75);
#line 112
        y0 = sjt_capture75 * radius->y;
#line 113
        sjt_functionParam392 = theta;
#line 113
        sjf_f32_sin(sjt_functionParam392, &r0);
#line 114
        sjt_forStart21 = 0;
#line 114
        sjt_forEnd21 = wedges + 1;
#line 114
        wedge = sjt_forStart21;
        while (wedge < sjt_forEnd21) {
            float angle;
            sjs_vec3 normal = { -1 };
            float sjt_capture76;
            float sjt_capture77;
            int32_t sjt_cast27;
            int32_t sjt_cast28;
            int32_t sjt_cast29;
            int32_t sjt_cast30;
            float sjt_functionParam393;
            float sjt_functionParam394;
            int32_t sjt_functionParam395;
            sjs_vertex_location_texture_normal* sjt_functionParam396 = 0;
            sjs_vec3* sjt_parent271 = 0;
            sjs_array_vertex_location_texture_normal* sjt_parent272 = 0;
            float tu;
            sjs_vertex_location_texture_normal v = { -1 };
            float x0;
            float z0;

#line 114 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_cast27 = wedge;
#line 102
            sjt_cast28 = wedges;
#line 115
            tu = (float)sjt_cast27 / (float)sjt_cast28;
#line 114
            sjt_cast29 = wedge;
#line 102
            sjt_cast30 = wedges;
#line 116
            angle = (((2.0f * g_f32_pi) * (float)sjt_cast29) / (float)sjt_cast30) - (1.5f * g_f32_pi);
#line 117
            sjt_functionParam393 = angle;
#line 117
            sjf_f32_sin(sjt_functionParam393, &sjt_capture76);
#line 117
            x0 = (sjt_capture76 * r0) * radius->x;
#line 118
            sjt_functionParam394 = angle;
#line 118
            sjf_f32_cos(sjt_functionParam394, &sjt_capture77);
#line 118
            z0 = (sjt_capture77 * r0) * radius->y;
#line 118
            normal._refCount = 1;
#line 119
            normal.x = x0;
#line 119
            normal.y = y0;
#line 119
            normal.z = z0;
#line 119
            sjf_vec3(&normal);
#line 119
            v._refCount = 1;
#line 119
            v.location._refCount = 1;
#line 122
            v.location.x = x0 + origin->x;
#line 122
            v.location.y = y0 + origin->y;
#line 122
            v.location.z = z0 + origin->z;
#line 122
            sjf_vec3(&v.location);
#line 122
            v.texture._refCount = 1;
#line 123
            v.texture.x = tu;
#line 123
            v.texture.y = tv;
#line 123
            sjf_vec2(&v.texture);
#line 38 "lib/sj-lib-ui/vec3.sj"
            sjt_parent271 = &normal;
#line 38
            sjf_vec3_normalize(sjt_parent271, &v.normal);
#line 38
            sjf_vertex_location_texture_normal(&v);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent272 = &vertices;
#line 126 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam395 = (slice * (wedges + 1)) + wedge;
#line 126
            sjt_functionParam396 = &v;
#line 126
            sjf_array_vertex_location_texture_normal_setat(sjt_parent272, sjt_functionParam395, sjt_functionParam396);
#line 114
            wedge++;

            if (normal._refCount == 1) { sjf_vec3_destroy(&normal); }
;
            if (v._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&v); }
;
        }

#line 109
        slice++;
    }

#line 130
    sjt_functionParam397 = (slices * wedges) * 6;
#line 130
    sjt_functionParam398 = 0;
#line 130
    sjf_array_create_i32(sjt_functionParam397, sjt_functionParam398, &indices);
#line 131
    sjt_forStart22 = 0;
#line 102
    sjt_forEnd22 = slices;
#line 131
    slice = sjt_forStart22;
    while (slice < sjt_forEnd22) {
        int32_t sjt_forEnd23;
        int32_t sjt_forStart23;
        int32_t wedge;

#line 132 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        sjt_forStart23 = 0;
#line 102
        sjt_forEnd23 = wedges;
#line 132
        wedge = sjt_forStart23;
        while (wedge < sjt_forEnd23) {
            int32_t index0;
            int32_t index1;
            int32_t index2;
            int32_t index3;
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
            int32_t sjt_functionParam410;
            sjs_array_i32* sjt_parent273 = 0;
            sjs_array_i32* sjt_parent274 = 0;
            sjs_array_i32* sjt_parent275 = 0;
            sjs_array_i32* sjt_parent276 = 0;
            sjs_array_i32* sjt_parent277 = 0;
            sjs_array_i32* sjt_parent278 = 0;
            int32_t wedge0;
            int32_t wedge1;

#line 132 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            wedge0 = wedge;
#line 134
            wedge1 = wedge + 1;
#line 136
            index0 = (slice * (wedges + 1)) + wedge0;
#line 137
            index1 = (slice * (wedges + 1)) + wedge1;
#line 138
            index2 = ((slice + 1) * (wedges + 1)) + wedge1;
#line 139
            index3 = ((slice + 1) * (wedges + 1)) + wedge0;
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent273 = &indices;
#line 141 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam399 = (((slice * wedges) + wedge) * 6) + 0;
#line 141
            sjt_functionParam400 = index0;
#line 141
            sjf_array_i32_setat(sjt_parent273, sjt_functionParam399, sjt_functionParam400);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent274 = &indices;
#line 142 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam401 = (((slice * wedges) + wedge) * 6) + 1;
#line 142
            sjt_functionParam402 = index1;
#line 142
            sjf_array_i32_setat(sjt_parent274, sjt_functionParam401, sjt_functionParam402);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent275 = &indices;
#line 143 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam403 = (((slice * wedges) + wedge) * 6) + 2;
#line 143
            sjt_functionParam404 = index2;
#line 143
            sjf_array_i32_setat(sjt_parent275, sjt_functionParam403, sjt_functionParam404);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent276 = &indices;
#line 144 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam405 = (((slice * wedges) + wedge) * 6) + 3;
#line 144
            sjt_functionParam406 = index2;
#line 144
            sjf_array_i32_setat(sjt_parent276, sjt_functionParam405, sjt_functionParam406);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent277 = &indices;
#line 145 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam407 = (((slice * wedges) + wedge) * 6) + 4;
#line 145
            sjt_functionParam408 = index3;
#line 145
            sjf_array_i32_setat(sjt_parent277, sjt_functionParam407, sjt_functionParam408);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent278 = &indices;
#line 146 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam409 = (((slice * wedges) + wedge) * 6) + 5;
#line 146
            sjt_functionParam410 = index0;
#line 146
            sjf_array_i32_setat(sjt_parent278, sjt_functionParam409, sjt_functionParam410);
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
    sjf_string_copy(&_return->format, &g_vertex_location_texture_normal_format);
#line 150
    _return->indices._refCount = 1;
#line 150
    sjf_array_i32_copy(&_return->indices, &indices);
#line 150
    _return->vertices._refCount = 1;
#line 150
    sjf_array_vertex_location_texture_normal_copy(&_return->vertices, &vertices);
#line 150
    sjf_vertexbuffer_vertex_location_texture_normal(_return);

    if (indices._refCount == 1) { sjf_array_i32_destroy(&indices); }
;
    if (sjt_call108._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call108); }
;
    if (vertices._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&vertices); }
;
}

void sjf_spherevertexbuffer_heap(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexbuffer_vertex_location_texture_normal** _return) {
    sjs_array_i32 indices = { -1 };
    sjs_vertex_location_texture_normal sjt_call109 = { -1 };
    int32_t sjt_forEnd24;
    int32_t sjt_forEnd26;
    int32_t sjt_forStart24;
    int32_t sjt_forStart26;
    int32_t sjt_functionParam411;
    sjs_vertex_location_texture_normal* sjt_functionParam412 = 0;
    int32_t sjt_functionParam419;
    int32_t sjt_functionParam420;
    int32_t slice;
    sjs_array_vertex_location_texture_normal vertices = { -1 };

#line 108 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjt_functionParam411 = (slices + 1) * (wedges + 1);
#line 108
    sjt_call109._refCount = 1;
#line 108
    sjt_call109.location._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
    sjt_call109.location.x = 0.0f;
#line 3
    sjt_call109.location.y = 0.0f;
#line 4
    sjt_call109.location.z = 0.0f;
#line 4
    sjf_vec3(&sjt_call109.location);
#line 4
    sjt_call109.texture._refCount = 1;
#line 2 "lib/sj-lib-ui/vec2.sj"
    sjt_call109.texture.x = 0.0f;
#line 3
    sjt_call109.texture.y = 0.0f;
#line 3
    sjf_vec2(&sjt_call109.texture);
#line 3
    sjt_call109.normal._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
    sjt_call109.normal.x = 0.0f;
#line 3
    sjt_call109.normal.y = 0.0f;
#line 4
    sjt_call109.normal.z = 0.0f;
#line 4
    sjf_vec3(&sjt_call109.normal);
#line 4
    sjf_vertex_location_texture_normal(&sjt_call109);
#line 108 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjt_functionParam412 = &sjt_call109;
#line 108
    sjf_array_create_vertex_location_texture_normal(sjt_functionParam411, sjt_functionParam412, &vertices);
#line 109
    sjt_forStart24 = 0;
#line 109
    sjt_forEnd24 = slices + 1;
#line 109
    slice = sjt_forStart24;
    while (slice < sjt_forEnd24) {
        float r0;
        float sjt_capture78;
        int32_t sjt_cast31;
        int32_t sjt_cast32;
        int32_t sjt_cast33;
        int32_t sjt_cast34;
        int32_t sjt_forEnd25;
        int32_t sjt_forStart25;
        float sjt_functionParam413;
        float sjt_functionParam414;
        float theta;
        float tv;
        int32_t wedge;
        float y0;

#line 109 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        sjt_cast31 = slice;
#line 102
        sjt_cast32 = slices;
#line 110
        tv = (float)sjt_cast31 / (float)sjt_cast32;
#line 109
        sjt_cast33 = slice;
#line 102
        sjt_cast34 = slices;
#line 111
        theta = ((g_f32_pi * (float)sjt_cast33) / (float)sjt_cast34) + g_f32_pi;
#line 112
        sjt_functionParam413 = theta;
#line 112
        sjf_f32_cos(sjt_functionParam413, &sjt_capture78);
#line 112
        y0 = sjt_capture78 * radius->y;
#line 113
        sjt_functionParam414 = theta;
#line 113
        sjf_f32_sin(sjt_functionParam414, &r0);
#line 114
        sjt_forStart25 = 0;
#line 114
        sjt_forEnd25 = wedges + 1;
#line 114
        wedge = sjt_forStart25;
        while (wedge < sjt_forEnd25) {
            float angle;
            sjs_vec3 normal = { -1 };
            float sjt_capture79;
            float sjt_capture80;
            int32_t sjt_cast35;
            int32_t sjt_cast36;
            int32_t sjt_cast37;
            int32_t sjt_cast38;
            float sjt_functionParam415;
            float sjt_functionParam416;
            int32_t sjt_functionParam417;
            sjs_vertex_location_texture_normal* sjt_functionParam418 = 0;
            sjs_vec3* sjt_parent279 = 0;
            sjs_array_vertex_location_texture_normal* sjt_parent280 = 0;
            float tu;
            sjs_vertex_location_texture_normal v = { -1 };
            float x0;
            float z0;

#line 114 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_cast35 = wedge;
#line 102
            sjt_cast36 = wedges;
#line 115
            tu = (float)sjt_cast35 / (float)sjt_cast36;
#line 114
            sjt_cast37 = wedge;
#line 102
            sjt_cast38 = wedges;
#line 116
            angle = (((2.0f * g_f32_pi) * (float)sjt_cast37) / (float)sjt_cast38) - (1.5f * g_f32_pi);
#line 117
            sjt_functionParam415 = angle;
#line 117
            sjf_f32_sin(sjt_functionParam415, &sjt_capture79);
#line 117
            x0 = (sjt_capture79 * r0) * radius->x;
#line 118
            sjt_functionParam416 = angle;
#line 118
            sjf_f32_cos(sjt_functionParam416, &sjt_capture80);
#line 118
            z0 = (sjt_capture80 * r0) * radius->y;
#line 118
            normal._refCount = 1;
#line 119
            normal.x = x0;
#line 119
            normal.y = y0;
#line 119
            normal.z = z0;
#line 119
            sjf_vec3(&normal);
#line 119
            v._refCount = 1;
#line 119
            v.location._refCount = 1;
#line 122
            v.location.x = x0 + origin->x;
#line 122
            v.location.y = y0 + origin->y;
#line 122
            v.location.z = z0 + origin->z;
#line 122
            sjf_vec3(&v.location);
#line 122
            v.texture._refCount = 1;
#line 123
            v.texture.x = tu;
#line 123
            v.texture.y = tv;
#line 123
            sjf_vec2(&v.texture);
#line 38 "lib/sj-lib-ui/vec3.sj"
            sjt_parent279 = &normal;
#line 38
            sjf_vec3_normalize(sjt_parent279, &v.normal);
#line 38
            sjf_vertex_location_texture_normal(&v);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent280 = &vertices;
#line 126 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam417 = (slice * (wedges + 1)) + wedge;
#line 126
            sjt_functionParam418 = &v;
#line 126
            sjf_array_vertex_location_texture_normal_setat(sjt_parent280, sjt_functionParam417, sjt_functionParam418);
#line 114
            wedge++;

            if (normal._refCount == 1) { sjf_vec3_destroy(&normal); }
;
            if (v._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&v); }
;
        }

#line 109
        slice++;
    }

#line 130
    sjt_functionParam419 = (slices * wedges) * 6;
#line 130
    sjt_functionParam420 = 0;
#line 130
    sjf_array_create_i32(sjt_functionParam419, sjt_functionParam420, &indices);
#line 131
    sjt_forStart26 = 0;
#line 102
    sjt_forEnd26 = slices;
#line 131
    slice = sjt_forStart26;
    while (slice < sjt_forEnd26) {
        int32_t sjt_forEnd27;
        int32_t sjt_forStart27;
        int32_t wedge;

#line 132 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        sjt_forStart27 = 0;
#line 102
        sjt_forEnd27 = wedges;
#line 132
        wedge = sjt_forStart27;
        while (wedge < sjt_forEnd27) {
            int32_t index0;
            int32_t index1;
            int32_t index2;
            int32_t index3;
            int32_t sjt_functionParam421;
            int32_t sjt_functionParam422;
            int32_t sjt_functionParam423;
            int32_t sjt_functionParam424;
            int32_t sjt_functionParam425;
            int32_t sjt_functionParam426;
            int32_t sjt_functionParam427;
            int32_t sjt_functionParam428;
            int32_t sjt_functionParam429;
            int32_t sjt_functionParam430;
            int32_t sjt_functionParam431;
            int32_t sjt_functionParam432;
            sjs_array_i32* sjt_parent281 = 0;
            sjs_array_i32* sjt_parent282 = 0;
            sjs_array_i32* sjt_parent283 = 0;
            sjs_array_i32* sjt_parent284 = 0;
            sjs_array_i32* sjt_parent285 = 0;
            sjs_array_i32* sjt_parent286 = 0;
            int32_t wedge0;
            int32_t wedge1;

#line 132 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            wedge0 = wedge;
#line 134
            wedge1 = wedge + 1;
#line 136
            index0 = (slice * (wedges + 1)) + wedge0;
#line 137
            index1 = (slice * (wedges + 1)) + wedge1;
#line 138
            index2 = ((slice + 1) * (wedges + 1)) + wedge1;
#line 139
            index3 = ((slice + 1) * (wedges + 1)) + wedge0;
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent281 = &indices;
#line 141 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam421 = (((slice * wedges) + wedge) * 6) + 0;
#line 141
            sjt_functionParam422 = index0;
#line 141
            sjf_array_i32_setat(sjt_parent281, sjt_functionParam421, sjt_functionParam422);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent282 = &indices;
#line 142 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam423 = (((slice * wedges) + wedge) * 6) + 1;
#line 142
            sjt_functionParam424 = index1;
#line 142
            sjf_array_i32_setat(sjt_parent282, sjt_functionParam423, sjt_functionParam424);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent283 = &indices;
#line 143 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam425 = (((slice * wedges) + wedge) * 6) + 2;
#line 143
            sjt_functionParam426 = index2;
#line 143
            sjf_array_i32_setat(sjt_parent283, sjt_functionParam425, sjt_functionParam426);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent284 = &indices;
#line 144 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam427 = (((slice * wedges) + wedge) * 6) + 3;
#line 144
            sjt_functionParam428 = index2;
#line 144
            sjf_array_i32_setat(sjt_parent284, sjt_functionParam427, sjt_functionParam428);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent285 = &indices;
#line 145 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam429 = (((slice * wedges) + wedge) * 6) + 4;
#line 145
            sjt_functionParam430 = index3;
#line 145
            sjf_array_i32_setat(sjt_parent285, sjt_functionParam429, sjt_functionParam430);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent286 = &indices;
#line 146 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam431 = (((slice * wedges) + wedge) * 6) + 5;
#line 146
            sjt_functionParam432 = index0;
#line 146
            sjf_array_i32_setat(sjt_parent286, sjt_functionParam431, sjt_functionParam432);
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
    sjf_string_copy(&(*_return)->format, &g_vertex_location_texture_normal_format);
#line 150
    (*_return)->indices._refCount = 1;
#line 150
    sjf_array_i32_copy(&(*_return)->indices, &indices);
#line 150
    (*_return)->vertices._refCount = 1;
#line 150
    sjf_array_vertex_location_texture_normal_copy(&(*_return)->vertices, &vertices);
#line 150
    sjf_vertexbuffer_vertex_location_texture_normal_heap((*_return));

    if (indices._refCount == 1) { sjf_array_i32_destroy(&indices); }
;
    if (sjt_call109._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call109); }
;
    if (vertices._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&vertices); }
;
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy(_return, _parent);
    } else {
        bool sjt_capture69;
        int32_t sjt_capture70;
        sjs_array_char* sjt_parent205 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent205 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent205, &sjt_capture70);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture70) {
            int32_t sjt_capture71;
            sjs_array_char* sjt_parent206 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent206 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent206, &sjt_capture71);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture69 = ((_parent->offset + _parent->count) == sjt_capture71);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture69 = false;
        }

        if (sjt_capture69) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd14;
            int32_t sjt_forStart14;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart14 = 0;
#line 27
            sjt_forEnd14 = item->count;
#line 27
            i = sjt_forStart14;
            while (i < sjt_forEnd14) {
                int32_t sjt_functionParam300;
                char sjt_functionParam301;
                int32_t sjt_functionParam303;
                sjs_array_char* sjt_parent207 = 0;
                sjs_string* sjt_parent209 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent207 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam300 = newcount;
#line 18
                sjt_parent209 = item;
#line 27
                sjt_functionParam303 = i;
#line 27
                sjf_string_getat(sjt_parent209, sjt_functionParam303, &sjt_functionParam301);
#line 27
                sjf_array_char_initat(sjt_parent207, sjt_functionParam300, sjt_functionParam301);
#line 29
                newcount = newcount + 1;
#line 27
                i++;
            }

#line 27
            _return->_refCount = 1;
#line 32
            _return->offset = _parent->offset;
#line 32
            _return->count = newcount;
#line 32
            _return->data._refCount = 1;
#line 32
            sjf_array_char_copy(&_return->data, &_parent->data);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd15;
            int32_t sjt_forStart15;
            int32_t sjt_functionParam304;
            int32_t sjt_functionParam305;
            int32_t sjt_functionParam306;
            sjs_array_char* sjt_parent210 = 0;
            sjs_array_char* sjt_parent211 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent210 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam304 = _parent->offset;
#line 34
            sjt_functionParam305 = _parent->count;
#line 34
            sjt_functionParam306 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent210, sjt_functionParam304, sjt_functionParam305, sjt_functionParam306, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent211 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent211, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart15 = 0;
#line 37
            sjt_forEnd15 = item->count;
#line 37
            i = sjt_forStart15;
            while (i < sjt_forEnd15) {
                int32_t sjt_functionParam307;
                char sjt_functionParam308;
                int32_t sjt_functionParam309;
                sjs_array_char* sjt_parent212 = 0;
                sjs_string* sjt_parent213 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent212 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam307 = newcount;
#line 18
                sjt_parent213 = item;
#line 37
                sjt_functionParam309 = i;
#line 37
                sjf_string_getat(sjt_parent213, sjt_functionParam309, &sjt_functionParam308);
#line 37
                sjf_array_char_initat(sjt_parent212, sjt_functionParam307, sjt_functionParam308);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            _return->_refCount = 1;
#line 42
            _return->offset = 0;
#line 42
            _return->count = newcount;
#line 42
            _return->data._refCount = 1;
#line 42
            sjf_array_char_copy(&_return->data, &newdata);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy((*_return), _parent);
    } else {
        bool sjt_capture72;
        int32_t sjt_capture73;
        sjs_array_char* sjt_parent214 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent214 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent214, &sjt_capture73);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture73) {
            int32_t sjt_capture74;
            sjs_array_char* sjt_parent215 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent215 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent215, &sjt_capture74);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture72 = ((_parent->offset + _parent->count) == sjt_capture74);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture72 = false;
        }

        if (sjt_capture72) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd16;
            int32_t sjt_forStart16;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart16 = 0;
#line 27
            sjt_forEnd16 = item->count;
#line 27
            i = sjt_forStart16;
            while (i < sjt_forEnd16) {
                int32_t sjt_functionParam310;
                char sjt_functionParam311;
                int32_t sjt_functionParam312;
                sjs_array_char* sjt_parent216 = 0;
                sjs_string* sjt_parent217 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent216 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam310 = newcount;
#line 18
                sjt_parent217 = item;
#line 27
                sjt_functionParam312 = i;
#line 27
                sjf_string_getat(sjt_parent217, sjt_functionParam312, &sjt_functionParam311);
#line 27
                sjf_array_char_initat(sjt_parent216, sjt_functionParam310, sjt_functionParam311);
#line 29
                newcount = newcount + 1;
#line 27
                i++;
            }

#line 27
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 27
            (*_return)->_refCount = 1;
#line 32
            (*_return)->offset = _parent->offset;
#line 32
            (*_return)->count = newcount;
#line 32
            (*_return)->data._refCount = 1;
#line 32
            sjf_array_char_copy(&(*_return)->data, &_parent->data);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd17;
            int32_t sjt_forStart17;
            int32_t sjt_functionParam313;
            int32_t sjt_functionParam314;
            int32_t sjt_functionParam315;
            sjs_array_char* sjt_parent218 = 0;
            sjs_array_char* sjt_parent219 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent218 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam313 = _parent->offset;
#line 34
            sjt_functionParam314 = _parent->count;
#line 34
            sjt_functionParam315 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent218, sjt_functionParam313, sjt_functionParam314, sjt_functionParam315, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent219 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent219, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart17 = 0;
#line 37
            sjt_forEnd17 = item->count;
#line 37
            i = sjt_forStart17;
            while (i < sjt_forEnd17) {
                int32_t sjt_functionParam316;
                char sjt_functionParam317;
                int32_t sjt_functionParam318;
                sjs_array_char* sjt_parent220 = 0;
                sjs_string* sjt_parent221 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent220 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam316 = newcount;
#line 18
                sjt_parent221 = item;
#line 37
                sjt_functionParam318 = i;
#line 37
                sjf_string_getat(sjt_parent221, sjt_functionParam318, &sjt_functionParam317);
#line 37
                sjf_array_char_initat(sjt_parent220, sjt_functionParam316, sjt_functionParam317);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 37
            (*_return)->_refCount = 1;
#line 42
            (*_return)->offset = 0;
#line 42
            (*_return)->count = newcount;
#line 42
            (*_return)->data._refCount = 1;
#line 42
            sjf_array_char_copy(&(*_return)->data, &newdata);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 12 "lib/sj-lib-common/string.sj"
    _this->offset = _from->offset;
#line 12
    _this->count = _from->count;
#line 12
    _this->data._refCount = 1;
#line 12
    sjf_array_char_copy(&_this->data, &_from->data);
#line 12
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam302;
    sjs_array_char* sjt_parent208 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent208 = &_parent->data;
#line 64 "lib/sj-lib-common/string.sj"
    sjt_functionParam302 = _parent->offset + index;
#line 64
    sjf_array_char_getat(sjt_parent208, sjt_functionParam302, _return);
}

void sjf_string_hash(sjs_string* _parent, uint32_t* _return) {
#line 148 "lib/sj-lib-common/string.sj"
    #line 147 "lib/sj-lib-common/string.sj"
(*_return) = kh_str_hash_func(((sjs_array*)_parent->data.v)->data + _parent->offset, _parent->count);
return;;
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
#line 73 "lib/sj-lib-common/string.sj"
    sjs_array* arr1 = (sjs_array*)_parent->data.v;
#line 74
    sjs_array* arr2 = (sjs_array*)test->data.v;
#line 75
    if (_parent->count != test->count) {
#line 76
        #line 72 "lib/sj-lib-common/string.sj"
(*_return) = false;
return;;      
#line 77
    }
#line 78
    bool result = memcmp(arr1->data + _parent->offset, arr2->data + test->offset, _parent->count) == 0;
#line 79
    #line 72 "lib/sj-lib-common/string.sj"
(*_return) = result;
return;;      
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    sjs_array_char sjt_funcold1 = { -1 };

#line 133 "lib/sj-lib-common/string.sj"
    result2 = !_parent->_isnullterminated;
    if (result2) {
        int32_t sjt_capture1;
        sjs_array_char* sjt_parent1 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent1 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent1, &sjt_capture1);
        if (((_parent->offset + _parent->count) + 1) > sjt_capture1) {
            int32_t sjt_functionParam1;
            int32_t sjt_functionParam2;
            int32_t sjt_functionParam3;
            sjs_array_char* sjt_parent2 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent2 = &_parent->data;
#line 135 "lib/sj-lib-common/string.sj"
            sjt_functionParam1 = _parent->offset;
#line 135
            sjt_functionParam2 = _parent->count;
#line 135
            sjt_functionParam3 = _parent->count + 1;
#line 135
            sjf_array_char_clone(sjt_parent2, sjt_functionParam1, sjt_functionParam2, sjt_functionParam3, &sjt_funcold1);
#line 135
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 168 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
#line 136 "lib/sj-lib-common/string.sj"
            _parent->offset = 0;
        }

#line 139 "lib/sj-lib-common/string.sj"
        ((sjs_array*)_parent->data.v)->data[_parent->offset + _parent->count] = 0;
#line 141
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return) {
    sjs_array_char a = { -1 };
    int32_t i;
    int32_t sjt_forEnd18;
    int32_t sjt_forStart18;
    void* v;

#line 120 "lib/sj-lib-common/string.sj"
    v = 0;
#line 122
    sjs_array* arr = createarray(1, ((_parent->count - 1) / 256 + 1) * 256);
#line 123
    v = arr;
#line 123
    a._refCount = 1;
#line 125
    a.v = v;
#line 125
    sjf_array_char(&a);
#line 126
    sjt_forStart18 = 0;
#line 126
    sjt_forEnd18 = _parent->count;
#line 126
    i = sjt_forStart18;
    while (i < sjt_forEnd18) {
        int32_t sjt_functionParam319;
        char sjt_functionParam320;
        char sjt_functionParam321;
        int32_t sjt_functionParam322;
        sjs_array_char* sjt_parent226 = 0;
        sjs_array_char* sjt_parent227 = 0;

#line 52 "lib/sj-lib-common/array.sj"
        sjt_parent226 = &a;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam319 = i;
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent227 = &_parent->data;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam322 = i;
#line 126
        sjf_array_char_getat(sjt_parent227, sjt_functionParam322, &sjt_functionParam321);
#line 126
        sjf_char_touppercase(sjt_functionParam321, &sjt_functionParam320);
#line 126
        sjf_array_char_initat(sjt_parent226, sjt_functionParam319, sjt_functionParam320);
#line 126
        i++;
    }

#line 126
    _return->_refCount = 1;
#line 13
    _return->offset = 0;
#line 129
    _return->count = _parent->count;
#line 129
    _return->data._refCount = 1;
#line 129
    sjf_array_char_copy(&_return->data, &a);
#line 16
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);

    if (a._refCount == 1) { sjf_array_char_destroy(&a); }
;
}

void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return) {
    sjs_array_char a = { -1 };
    int32_t i;
    int32_t sjt_forEnd19;
    int32_t sjt_forStart19;
    void* v;

#line 120 "lib/sj-lib-common/string.sj"
    v = 0;
#line 122
    sjs_array* arr = createarray(1, ((_parent->count - 1) / 256 + 1) * 256);
#line 123
    v = arr;
#line 123
    a._refCount = 1;
#line 125
    a.v = v;
#line 125
    sjf_array_char(&a);
#line 126
    sjt_forStart19 = 0;
#line 126
    sjt_forEnd19 = _parent->count;
#line 126
    i = sjt_forStart19;
    while (i < sjt_forEnd19) {
        int32_t sjt_functionParam323;
        char sjt_functionParam324;
        char sjt_functionParam325;
        int32_t sjt_functionParam326;
        sjs_array_char* sjt_parent228 = 0;
        sjs_array_char* sjt_parent229 = 0;

#line 52 "lib/sj-lib-common/array.sj"
        sjt_parent228 = &a;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam323 = i;
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent229 = &_parent->data;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam326 = i;
#line 126
        sjf_array_char_getat(sjt_parent229, sjt_functionParam326, &sjt_functionParam325);
#line 126
        sjf_char_touppercase(sjt_functionParam325, &sjt_functionParam324);
#line 126
        sjf_array_char_initat(sjt_parent228, sjt_functionParam323, sjt_functionParam324);
#line 126
        i++;
    }

#line 126
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 126
    (*_return)->_refCount = 1;
#line 13
    (*_return)->offset = 0;
#line 129
    (*_return)->count = _parent->count;
#line 129
    (*_return)->data._refCount = 1;
#line 129
    sjf_array_char_copy(&(*_return)->data, &a);
#line 16
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));

    if (a._refCount == 1) { sjf_array_char_destroy(&a); }
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
#line 1 "lib/sj-lib-ui/texture.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 1
    _this->id = _from->id;
#line 10
    glid_retain(_this->id);
}

void sjf_texture_destroy(sjs_texture* _this) {
#line 14 "lib/sj-lib-ui/texture.sj"
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
    int32_t h;
    uint32_t id;
    int32_t w;

#line 37 "lib/sj-lib-ui/texture.sj"
    id = (uint32_t)0u;
#line 38
    w = 0;
#line 39
    h = 0;
#line 41
    id = png_texture_load(string_char(filename), &w, &h);
#line 41
    _return->_refCount = 1;
#line 41
    _return->size._refCount = 1;
#line 43
    _return->size.w = w;
#line 43
    _return->size.h = h;
#line 43
    sjf_size(&_return->size);
#line 43
    _return->id = id;
#line 43
    sjf_texture(_return);
}

void sjf_texture_frompng_heap(sjs_string* filename, sjs_texture** _return) {
    int32_t h;
    uint32_t id;
    int32_t w;

#line 37 "lib/sj-lib-ui/texture.sj"
    id = (uint32_t)0u;
#line 38
    w = 0;
#line 39
    h = 0;
#line 41
    id = png_texture_load(string_char(filename), &w, &h);
#line 41
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
#line 41
    (*_return)->_refCount = 1;
#line 41
    (*_return)->size._refCount = 1;
#line 43
    (*_return)->size.w = w;
#line 43
    (*_return)->size.h = h;
#line 43
    sjf_size(&(*_return)->size);
#line 43
    (*_return)->id = id;
#line 43
    sjf_texture_heap((*_return));
}

void sjf_texture_getsize(sjs_texture* _parent, sjs_size* _return) {
    _return->_refCount = 1;
#line 5 "lib/sj-lib-ui/texture.sj"
    _return->w = (&_parent->size)->w;
#line 5
    _return->h = (&_parent->size)->h;
#line 5
    sjf_size(_return);
}

void sjf_texture_getsize_heap(sjs_texture* _parent, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 5 "lib/sj-lib-ui/texture.sj"
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
        _return->offset = 0;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.v = &sjg_string47;
        sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 13:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string48;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 135:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 31;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string49;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 141:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 33;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string50;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 92:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string51;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 93:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 20;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string52;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 213:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string53;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 9:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string54;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 14:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 10;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string55;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 6:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string56;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 7:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string57;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 15:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 21;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string58;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 26:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 15;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string59;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 27:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 10;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string60;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 16:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string61;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 22:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 23;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string62;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 25:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 19;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string63;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 23:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 20;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string64;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 24:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 20;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string65;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 17:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string66;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 18:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 18;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string67;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 20:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 15;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string68;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 21:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string69;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 19:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string70;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 28:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string71;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 1:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string72;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 2:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string73;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 29:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string74;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 30:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 21;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string75;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 12:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string76;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 31:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string77;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 5:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string78;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 71:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 10;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string79;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 94:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string80;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 66:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string81;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 58:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string82;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 34:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 0;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string30;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 70:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string83;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 282:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string84;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 44:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 10;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string85;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 46:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string86;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 218:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 221:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 45:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string89;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 217:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string90;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 255:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 10;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string91;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 251:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 37;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string92;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 73:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 16;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string93;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 286:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 284:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 90:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string94;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 97:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 96:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 270:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string90;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 112:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string95;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 137:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 18;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string96;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 200:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string86;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 126:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 125:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 199:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string89;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 201:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string90;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 138:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string97;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 136:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string98;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 204:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string99;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 209:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 206:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 256:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string97;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 84:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 10;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string100;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 131:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string86;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 146:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 129:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 130:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string89;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 133:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string90;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 86:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string101;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 178:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string86;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 184:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 176:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 177:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string89;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 179:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string90;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 205:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 36;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string102;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 208:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 207:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 254:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string97;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 230:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string103;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 274:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 11;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string104;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 277:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string105;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 219:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 16;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string106;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 49:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string107;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 196:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string108;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 273:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string109;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 278:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string110;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 272:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string111;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 271:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string112;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 276:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string105;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 275:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string113;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 214:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string114;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 234:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string115;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 140:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 11;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string116;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 252:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string117;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 79:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string118;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 253:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string119;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 121:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string120;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 117:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string121;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 89:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 10;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string122;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 106:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string110;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 100:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string111;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 88:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string112;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 104:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string105;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 105:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 11;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string123;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 101:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string113;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 103:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string124;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 76:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string125;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 75:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string126;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 78:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string127;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 80:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string128;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 164:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 11;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string129;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 242:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 18;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string130;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 192:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string131;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 50:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 11;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string132;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 245:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 24;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string133;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 48:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string134;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 150:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string135;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 51:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string136;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 244:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 25;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string137;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 241:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 22;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string138;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 236:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 16;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string139;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 238:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string140;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 237:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string141;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 194:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 20;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string142;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 35:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string143;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 182:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 16;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string144;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 144:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string145;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 174:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string146;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 127:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string147;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 243:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 21;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string148;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 240:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string149;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 239:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 15;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string150;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 267:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string151;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 193:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string152;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 195:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string153;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 191:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string154;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 148:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string155;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 77:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 21;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string156;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 81:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string157;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 82:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 19;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string158;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 67:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 24;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string159;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 68:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string157;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 69:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 19;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string158;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 61:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 22;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string160;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 64:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string157;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 65:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 19;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string158;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 235:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string97;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 36:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string161;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 39:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string157;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 40:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 19;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string158;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 224:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 229:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string162;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 132:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string163;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 260:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string164;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 259:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string165;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 268:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string110;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 258:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string111;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 257:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string112;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 264:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string105;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 263:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string113;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 262:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string166;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 266:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string105;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 210:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string167;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 225:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string168;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 226:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string169;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 231:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string170;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 232:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string169;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 56:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string171;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 72:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 15;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string172;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 285:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 283:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 287:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string173;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 59:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 11;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string174;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 198:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string175;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 143:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 142:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 134:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string98;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 83:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string176;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 128:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string175;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 145:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 147:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 149:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string173;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 85:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string177;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 175:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string175;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 183:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 185:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string88;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 186:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string173;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 41:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string178;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 212:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string179;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 211:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string24;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 215:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string180;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 281:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string181;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 91:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string182;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 54:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string183;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 188:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 11;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string184;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 113:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string185;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 187:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string186;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 118:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string187;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 167:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string188;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 189:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 11;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string189;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 168:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string190;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 248:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string191;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 116:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 16;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string192;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 249:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 10;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string193;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 190:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string194;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 139:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 11;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string195;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 60:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 10;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string196;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 227:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string197;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 107:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string198;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 108:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string199;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 228:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string197;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 55:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string200;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 279:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string201;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 115:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string128;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 102:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string202;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 166:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string203;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 280:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string204;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 52:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string205;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 181:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string206;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 246:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string207;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 180:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string208;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 153:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string209;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 202:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string110;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 170:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string210;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 171:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string211;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 169:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string212;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 173:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string105;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 172:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string213;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 152:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string214;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 111:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string215;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 151:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string110;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 110:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string111;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 109:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string112;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 124:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string105;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 114:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string113;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 74:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string216;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 53:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string217;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 99:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string218;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 247:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string128;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 98:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string219;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 265:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string220;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 95:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string202;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 250:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 18;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string221;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 42:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string222;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 220:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string175;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 222:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string87;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 62:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string127;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 63:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string128;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 43:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string223;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 216:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 11;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string224;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 87:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string225;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 165:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string42;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 269:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 15;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string226;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 261:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string112;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 223:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string227;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 37:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string228;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 38:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string229;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 160:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string230;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 233:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string197;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 158:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 15;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string231;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 162:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string232;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 57:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string233;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 122:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string234;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 123:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string235;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 157:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 15;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string236;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 120:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string237;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 161:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string238;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 119:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string239;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 163:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string240;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 154:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 30;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string241;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 156:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 41;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string242;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 159:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 38;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string243;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 155:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 43;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string244;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 197:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string105;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 203:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 24;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string245;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 47:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string246;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 288:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string112;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 289:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string247;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 32:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string248;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 33:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string249;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 11:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string250;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 3:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string251;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 4:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string252;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 10:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string253;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        default:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 0;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string30;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
    }
}

void sjf_type_asstring_heap(int32_t t, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 2 "lib/sj-lib-common/type.sj"
    (*_return)->offset = 0;
#line 2
    (*_return)->count = 0;
#line 2
    (*_return)->data._refCount = 1;
#line 2
    (*_return)->data.v = &sjg_string30;
#line 2
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

#line 5 "lib/sj-lib-common/type.sj"
    sjt_cast1 = val;
#line 6
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
#line 10 "lib/sj-lib-common/type.sj"
    (*_return) = l == r;
}

void sjf_vec2(sjs_vec2* _this) {
}

void sjf_vec2_asstring(sjs_vec2* _parent, sjs_string* _return) {
    sjs_string sjt_call91 = { -1 };
    sjs_string sjt_call92 = { -1 };
    sjs_string sjt_call93 = { -1 };
    sjs_string sjt_call94 = { -1 };
    float sjt_functionParam374;
    sjs_string* sjt_functionParam375 = 0;
    sjs_string* sjt_functionParam376 = 0;
    float sjt_functionParam377;
    sjs_string* sjt_parent256 = 0;
    sjs_string* sjt_parent257 = 0;

#line 6 "lib/sj-lib-ui/vec2.sj"
    sjt_functionParam374 = _parent->x;
#line 6
    sjf_f32_asstring(sjt_functionParam374, &sjt_call92);
#line 6
    sjt_parent257 = &sjt_call92;
#line 6
    sjt_call93._refCount = 1;
#line 6
    sjt_call93.offset = 0;
#line 6
    sjt_call93.count = 2;
#line 6
    sjt_call93.data._refCount = 1;
#line 6
    sjt_call93.data.v = &sjg_string34;
#line 6
    sjf_array_char(&sjt_call93.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call93._isnullterminated = false;
#line 16
    sjf_string(&sjt_call93);
#line 6 "lib/sj-lib-ui/vec2.sj"
    sjt_functionParam375 = &sjt_call93;
#line 6
    sjf_string_add(sjt_parent257, sjt_functionParam375, &sjt_call91);
#line 6
    sjt_parent256 = &sjt_call91;
#line 6
    sjt_functionParam377 = _parent->y;
#line 6
    sjf_f32_asstring(sjt_functionParam377, &sjt_call94);
#line 6
    sjt_functionParam376 = &sjt_call94;
#line 6
    sjf_string_add(sjt_parent256, sjt_functionParam376, _return);

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
    float sjt_functionParam378;
    sjs_string* sjt_functionParam379 = 0;
    sjs_string* sjt_functionParam380 = 0;
    float sjt_functionParam381;
    sjs_string* sjt_parent258 = 0;
    sjs_string* sjt_parent259 = 0;

#line 6 "lib/sj-lib-ui/vec2.sj"
    sjt_functionParam378 = _parent->x;
#line 6
    sjf_f32_asstring(sjt_functionParam378, &sjt_call96);
#line 6
    sjt_parent259 = &sjt_call96;
#line 6
    sjt_call97._refCount = 1;
#line 6
    sjt_call97.offset = 0;
#line 6
    sjt_call97.count = 2;
#line 6
    sjt_call97.data._refCount = 1;
#line 6
    sjt_call97.data.v = &sjg_string34;
#line 6
    sjf_array_char(&sjt_call97.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call97._isnullterminated = false;
#line 16
    sjf_string(&sjt_call97);
#line 6 "lib/sj-lib-ui/vec2.sj"
    sjt_functionParam379 = &sjt_call97;
#line 6
    sjf_string_add(sjt_parent259, sjt_functionParam379, &sjt_call95);
#line 6
    sjt_parent258 = &sjt_call95;
#line 6
    sjt_functionParam381 = _parent->y;
#line 6
    sjf_f32_asstring(sjt_functionParam381, &sjt_call98);
#line 6
    sjt_functionParam380 = &sjt_call98;
#line 6
    sjf_string_add_heap(sjt_parent258, sjt_functionParam380, _return);

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
#line 1 "lib/sj-lib-ui/vec2.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
}

void sjf_vec2_destroy(sjs_vec2* _this) {
}

void sjf_vec2_getrawsize(int32_t* _return) {
#line 12 "lib/sj-lib-ui/vec2.sj"
    int x = sizeof(float) * 2;
#line 13
    #line 11 "lib/sj-lib-ui/vec2.sj"
(*_return) = x;
return;;
}

void sjf_vec2_heap(sjs_vec2* _this) {
}

void sjf_vec2_rawcopy(sjs_vec2* v, void* p, void** _return) {
#line 19 "lib/sj-lib-ui/vec2.sj"
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
    #line 18 "lib/sj-lib-ui/vec2.sj"
(*_return) = (void*)f;
return;;
}

void sjf_vec3(sjs_vec3* _this) {
}

void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from) {
#line 1 "lib/sj-lib-ui/vec3.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
#line 1
    _this->z = _from->z;
}

void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 49 "lib/sj-lib-ui/vec3.sj"
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
#line 49 "lib/sj-lib-ui/vec3.sj"
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
#line 56 "lib/sj-lib-ui/vec3.sj"
    (*_return) = ((_parent->x * v->x) + (_parent->y * v->y)) + (_parent->z * v->z);
}

void sjf_vec3_getrawsize(int32_t* _return) {
#line 82 "lib/sj-lib-ui/vec3.sj"
    int x = sizeof(float) * 3;
#line 83
    #line 81 "lib/sj-lib-ui/vec3.sj"
(*_return) = x;
return;;
}

void sjf_vec3_heap(sjs_vec3* _this) {
}

void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return) {
    float sjt_functionParam39;
    float t;

#line 39 "lib/sj-lib-ui/vec3.sj"
    sjt_functionParam39 = ((_parent->x * _parent->x) + (_parent->y * _parent->y)) + (_parent->z * _parent->z);
#line 39
    sjf_f32_sqrt(sjt_functionParam39, &t);
#line 39
    _return->_refCount = 1;
#line 41
    _return->x = _parent->x / t;
#line 42
    _return->y = _parent->y / t;
#line 43
    _return->z = _parent->z / t;
#line 43
    sjf_vec3(_return);
}

void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3** _return) {
    float sjt_functionParam40;
    float t;

#line 39 "lib/sj-lib-ui/vec3.sj"
    sjt_functionParam40 = ((_parent->x * _parent->x) + (_parent->y * _parent->y)) + (_parent->z * _parent->z);
#line 39
    sjf_f32_sqrt(sjt_functionParam40, &t);
#line 39
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
#line 39
    (*_return)->_refCount = 1;
#line 41
    (*_return)->x = _parent->x / t;
#line 42
    (*_return)->y = _parent->y / t;
#line 43
    (*_return)->z = _parent->z / t;
#line 43
    sjf_vec3_heap((*_return));
}

void sjf_vec3_rawcopy(sjs_vec3* v, void* p, void** _return) {
#line 89 "lib/sj-lib-ui/vec3.sj"
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
    #line 88 "lib/sj-lib-ui/vec3.sj"
(*_return) = (void*)f;
return;;
}

void sjf_vec3_subtract(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 32 "lib/sj-lib-ui/vec3.sj"
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
#line 32 "lib/sj-lib-ui/vec3.sj"
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
#line 1 "lib/sj-lib-ui/vec4.sj"
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
#line 2 "lib/sj-lib-ui/vertexBufferBuilders.sj"
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
    int32_t sjt_capture39;
    int32_t sjt_capture40;
    int32_t sjt_capture41;

    sjf_vec3_getrawsize(&sjt_capture39);
    sjf_vec2_getrawsize(&sjt_capture40);
    sjf_vec3_getrawsize(&sjt_capture41);
#line 9 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    (*_return) = (sjt_capture39 + sjt_capture40) + sjt_capture41;
}

void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_rawcopy(sjs_vertex_location_texture_normal* v, void* p, void** _return) {
    void* sjt_funcold15;
    void* sjt_funcold16;
    void* sjt_funcold17;
    sjs_vec3* sjt_functionParam171 = 0;
    void* sjt_functionParam172;
    sjs_vec2* sjt_functionParam173 = 0;
    void* sjt_functionParam174;
    sjs_vec3* sjt_functionParam175 = 0;
    void* sjt_functionParam176;

#line 13 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjt_functionParam171 = &v->location;
#line 12
    sjt_functionParam172 = p;
#line 12
    sjf_vec3_rawcopy(sjt_functionParam171, sjt_functionParam172, &sjt_funcold15);
#line 87 "lib/sj-lib-ui/vec3.sj"
    p = sjt_funcold15;
#line 14 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjt_functionParam173 = &v->texture;
#line 12
    sjt_functionParam174 = p;
#line 12
    sjf_vec2_rawcopy(sjt_functionParam173, sjt_functionParam174, &sjt_funcold16);
#line 17 "lib/sj-lib-ui/vec2.sj"
    p = sjt_funcold16;
#line 15 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjt_functionParam175 = &v->normal;
#line 12
    sjt_functionParam176 = p;
#line 12
    sjf_vec3_rawcopy(sjt_functionParam175, sjt_functionParam176, &sjt_funcold17);
#line 87 "lib/sj-lib-ui/vec3.sj"
    p = sjt_funcold17;
#line 12 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    (*_return) = p;
}

void sjf_vertexbuffer_vertex_location_texture_normal(sjs_vertexbuffer_vertex_location_texture_normal* _this) {
#line 102 "lib/sj-lib-ui/vertexBuffer.sj"
    _this->buffer = vertex_buffer_new(string_char(&_this->format));
#line 103
    if (((sjs_array*)_this->indices.v)->count > 0) {
#line 104
        vertex_buffer_push_back_indices(_this->buffer, (GLuint*)((sjs_array*)_this->indices.v)->data, ((sjs_array*)_this->indices.v)->count);
#line 105
    }
#line 107
    if (((sjs_array*)_this->vertices.v)->count > 0) {
#line 108
        int vertexSize;
#line 109
        sjf_vertex_location_texture_normal_getrawsize(&vertexSize);
#line 110
        int verticesSize = ((sjs_array*)_this->vertices.v)->count * vertexSize;
#line 111
        char* t = malloc(verticesSize);
#line 112
        char* buffer = t;
#line 113
        sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)((sjs_array*)_this->vertices.v)->data;
#line 114
        for (int i = 0; i < ((sjs_array*)_this->vertices.v)->count; i++) {
#line 115
            sjf_vertex_location_texture_normal_rawcopy(&p[i], buffer, (void*)&buffer);
#line 116
        }
#line 117
        vertex_buffer_push_back_vertices(_this->buffer, t, ((sjs_array*)_this->vertices.v)->count);
#line 118
        free(t);
#line 119
    }
}

void sjf_vertexbuffer_vertex_location_texture_normal_copy(sjs_vertexbuffer_vertex_location_texture_normal* _this, sjs_vertexbuffer_vertex_location_texture_normal* _from) {
    _this->format._refCount = 1;
#line 7 "lib/sj-lib-ui/vertexBuffer.sj"
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
#line 129 "lib/sj-lib-ui/vertexBuffer.sj"
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
#line 102 "lib/sj-lib-ui/vertexBuffer.sj"
    _this->buffer = vertex_buffer_new(string_char(&_this->format));
#line 103
    if (((sjs_array*)_this->indices.v)->count > 0) {
#line 104
        vertex_buffer_push_back_indices(_this->buffer, (GLuint*)((sjs_array*)_this->indices.v)->data, ((sjs_array*)_this->indices.v)->count);
#line 105
    }
#line 107
    if (((sjs_array*)_this->vertices.v)->count > 0) {
#line 108
        int vertexSize;
#line 109
        sjf_vertex_location_texture_normal_getrawsize(&vertexSize);
#line 110
        int verticesSize = ((sjs_array*)_this->vertices.v)->count * vertexSize;
#line 111
        char* t = malloc(verticesSize);
#line 112
        char* buffer = t;
#line 113
        sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)((sjs_array*)_this->vertices.v)->data;
#line 114
        for (int i = 0; i < ((sjs_array*)_this->vertices.v)->count; i++) {
#line 115
            sjf_vertex_location_texture_normal_rawcopy(&p[i], buffer, (void*)&buffer);
#line 116
        }
#line 117
        vertex_buffer_push_back_vertices(_this->buffer, t, ((sjs_array*)_this->vertices.v)->count);
#line 118
        free(t);
#line 119
    }
}

void sjf_vertexbuffer_vertex_location_texture_normal_render(sjs_vertexbuffer_vertex_location_texture_normal* _parent, int32_t gldrawmode) {
#line 96 "lib/sj-lib-ui/vertexBuffer.sj"
    vertex_buffer_render(_parent->buffer, gldrawmode);
}

void sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture(sjs_vertexbuffer_vertex_location_texture_normal* _parent, sjs_point* screen, sjs_rect* viewport, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_vec2* _return) {
    sjs_mat4 all = { -1 };
    sjs_mat4 allinverse = { -1 };
    int32_t ctriangles;
    int32_t i;
    sjs_vec3 intersection = { -1 };
    sjs_mat4 sjt_call28 = { -1 };
    int32_t sjt_capture47;
    int32_t sjt_cast11;
    int32_t sjt_cast12;
    int32_t sjt_cast13;
    int32_t sjt_cast14;
    int32_t sjt_forEnd12;
    int32_t sjt_forStart12;
    sjs_mat4* sjt_functionParam233 = 0;
    sjs_mat4* sjt_functionParam234 = 0;
    sjs_vec4* sjt_functionParam235 = 0;
    sjs_vec4* sjt_functionParam236 = 0;
    sjs_vec3* sjt_functionParam237 = 0;
    sjs_mat4* sjt_parent137 = 0;
    sjs_mat4* sjt_parent138 = 0;
    sjs_mat4* sjt_parent139 = 0;
    sjs_mat4* sjt_parent140 = 0;
    sjs_mat4* sjt_parent141 = 0;
    sjs_vec3* sjt_parent142 = 0;
    sjs_vec3* sjt_parent143 = 0;
    sjs_array_i32* sjt_parent144 = 0;
    sjs_vec2 start = { -1 };
    sjs_vec2 texture = { -1 };
    sjs_vec3 vflatteneddir = { -1 };
    sjs_vec3 vflattenedorigin1 = { -1 };
    sjs_vec3 vflattenedorigin2 = { -1 };
    sjs_vec3 vpickraydir = { -1 };
    sjs_vec3 vpickrayorig = { -1 };
    sjs_vec4 vprojectedorigin1 = { -1 };
    sjs_vec4 vprojectedorigin2 = { -1 };
    sjs_vec4 vscreenorigin1 = { -1 };
    sjs_vec4 vscreenorigin2 = { -1 };

#line 44 "lib/sj-lib-ui/vertexBuffer.sj"
    intersection._refCount = -1;
#line 45
    texture._refCount = -1;
#line 45
    start._refCount = 1;
#line 49
    sjt_cast11 = screen->x - viewport->x;
#line 49
    sjt_cast12 = viewport->w;
#line 49
    start.x = (((float)sjt_cast11 / (float)sjt_cast12) * 2.0f) - 1.0f;
#line 50
    sjt_cast13 = screen->y - viewport->y;
#line 50
    sjt_cast14 = viewport->h;
#line 50
    start.y = 1.0f - (((float)sjt_cast13 / (float)sjt_cast14) * 2.0f);
#line 50
    sjf_vec2(&start);
#line 50
    vscreenorigin1._refCount = 1;
#line 52
    vscreenorigin1.x = (&start)->x;
#line 52
    vscreenorigin1.y = (&start)->y;
#line 52
    vscreenorigin1.z = 0.0f;
#line 52
    vscreenorigin1.w = 1.0f;
#line 52
    sjf_vec4(&vscreenorigin1);
#line 52
    vscreenorigin2._refCount = 1;
#line 53
    vscreenorigin2.x = (&start)->x;
#line 53
    vscreenorigin2.y = (&start)->y;
#line 53
    vscreenorigin2.z = 1.0f;
#line 53
    vscreenorigin2.w = 1.0f;
#line 53
    sjf_vec4(&vscreenorigin2);
#line 43
    sjt_parent138 = projection;
#line 43
    sjt_functionParam233 = view;
#line 43
    sjf_mat4_multiply(sjt_parent138, sjt_functionParam233, &sjt_call28);
#line 54
    sjt_parent137 = &sjt_call28;
#line 43
    sjt_functionParam234 = world;
#line 43
    sjf_mat4_multiply(sjt_parent137, sjt_functionParam234, &all);
#line 71 "lib/sj-lib-ui/mat4.sj"
    sjt_parent139 = &all;
#line 71
    sjf_mat4_invert(sjt_parent139, &allinverse);
#line 62
    sjt_parent140 = &allinverse;
#line 56 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_functionParam235 = &vscreenorigin1;
#line 56
    sjf_mat4_multiplyvec4(sjt_parent140, sjt_functionParam235, &vprojectedorigin1);
#line 62 "lib/sj-lib-ui/mat4.sj"
    sjt_parent141 = &allinverse;
#line 57 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_functionParam236 = &vscreenorigin2;
#line 57
    sjf_mat4_multiplyvec4(sjt_parent141, sjt_functionParam236, &vprojectedorigin2);
#line 57
    vflattenedorigin1._refCount = 1;
#line 58
    vflattenedorigin1.x = (&vprojectedorigin1)->x / (&vprojectedorigin1)->w;
#line 58
    vflattenedorigin1.y = (&vprojectedorigin1)->y / (&vprojectedorigin1)->w;
#line 58
    vflattenedorigin1.z = (&vprojectedorigin1)->z / (&vprojectedorigin1)->w;
#line 58
    sjf_vec3(&vflattenedorigin1);
#line 58
    vflattenedorigin2._refCount = 1;
#line 59
    vflattenedorigin2.x = (&vprojectedorigin2)->x / (&vprojectedorigin2)->w;
#line 59
    vflattenedorigin2.y = (&vprojectedorigin2)->y / (&vprojectedorigin2)->w;
#line 59
    vflattenedorigin2.z = (&vprojectedorigin2)->z / (&vprojectedorigin2)->w;
#line 59
    sjf_vec3(&vflattenedorigin2);
#line 30 "lib/sj-lib-ui/vec3.sj"
    sjt_parent142 = &vflattenedorigin2;
#line 60 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_functionParam237 = &vflattenedorigin1;
#line 60
    sjf_vec3_subtract(sjt_parent142, sjt_functionParam237, &vflatteneddir);
#line 60
    vpickrayorig._refCount = 1;
#line 62
    sjf_vec3_copy(&vpickrayorig, &vflattenedorigin1);
#line 38 "lib/sj-lib-ui/vec3.sj"
    sjt_parent143 = &vflatteneddir;
#line 38
    sjf_vec3_normalize(sjt_parent143, &vpickraydir);
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent144 = &_parent->indices;
#line 29
    sjf_array_i32_getcount(sjt_parent144, &sjt_capture47);
    if (sjt_capture47 > 0) {
        int32_t sjt_capture48;
        sjs_array_i32* sjt_parent145 = 0;

#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent145 = &_parent->indices;
#line 29
        sjf_array_i32_getcount(sjt_parent145, &sjt_capture48);
#line 65 "lib/sj-lib-ui/vertexBuffer.sj"
        ctriangles = sjt_capture48 / 3;
    } else {
        int32_t sjt_capture49;
        sjs_array_vertex_location_texture_normal* sjt_parent146 = 0;

#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent146 = &_parent->vertices;
#line 29
        sjf_array_vertex_location_texture_normal_getcount(sjt_parent146, &sjt_capture49);
#line 65 "lib/sj-lib-ui/vertexBuffer.sj"
        ctriangles = sjt_capture49 / 3;
    }

#line 66 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_forStart12 = 0;
#line 66
    sjt_forEnd12 = ctriangles;
#line 66
    i = sjt_forStart12;
    while (i < sjt_forEnd12) {
        sjs_vec3 result = { -1 };
        int32_t sjt_capture50;
        int32_t sjt_capture51;
        int32_t sjt_capture52;
        sjs_vec3* sjt_functionParam267 = 0;
        sjs_vec3* sjt_functionParam268 = 0;
        sjs_vec3* sjt_functionParam269 = 0;
        sjs_vec3* sjt_functionParam270 = 0;
        sjs_vec3* sjt_functionParam271 = 0;
        sjs_array_i32* sjt_parent147 = 0;
        sjs_array_i32* sjt_parent151 = 0;
        sjs_array_i32* sjt_parent155 = 0;
        sjs_vertex_location_texture_normal vertex0 = { -1 };
        sjs_vertex_location_texture_normal vertex1 = { -1 };
        sjs_vertex_location_texture_normal vertex2 = { -1 };

#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent147 = &_parent->indices;
#line 29
        sjf_array_i32_getcount(sjt_parent147, &sjt_capture50);
        if (sjt_capture50 > 0) {
            int32_t sjt_functionParam238;
            int32_t sjt_functionParam239;
            sjs_array_vertex_location_texture_normal* sjt_parent148 = 0;
            sjs_array_i32* sjt_parent149 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent148 = &_parent->vertices;
#line 41
            sjt_parent149 = &_parent->indices;
#line 67 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam239 = (i * 3) + 0;
#line 67
            sjf_array_i32_getat(sjt_parent149, sjt_functionParam239, &sjt_functionParam238);
#line 67
            sjf_array_vertex_location_texture_normal_getat(sjt_parent148, sjt_functionParam238, &vertex0);
        } else {
            int32_t sjt_functionParam240;
            sjs_array_vertex_location_texture_normal* sjt_parent150 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent150 = &_parent->vertices;
#line 67 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam240 = (i * 3) + 0;
#line 67
            sjf_array_vertex_location_texture_normal_getat(sjt_parent150, sjt_functionParam240, &vertex0);
        }

#line 29
        sjt_parent151 = &_parent->indices;
#line 29
        sjf_array_i32_getcount(sjt_parent151, &sjt_capture51);
        if (sjt_capture51 > 0) {
            int32_t sjt_functionParam241;
            int32_t sjt_functionParam242;
            sjs_array_vertex_location_texture_normal* sjt_parent152 = 0;
            sjs_array_i32* sjt_parent153 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent152 = &_parent->vertices;
#line 41
            sjt_parent153 = &_parent->indices;
#line 68 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam242 = (i * 3) + 1;
#line 68
            sjf_array_i32_getat(sjt_parent153, sjt_functionParam242, &sjt_functionParam241);
#line 68
            sjf_array_vertex_location_texture_normal_getat(sjt_parent152, sjt_functionParam241, &vertex1);
        } else {
            int32_t sjt_functionParam243;
            sjs_array_vertex_location_texture_normal* sjt_parent154 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent154 = &_parent->vertices;
#line 68 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam243 = (i * 3) + 1;
#line 68
            sjf_array_vertex_location_texture_normal_getat(sjt_parent154, sjt_functionParam243, &vertex1);
        }

#line 29
        sjt_parent155 = &_parent->indices;
#line 29
        sjf_array_i32_getcount(sjt_parent155, &sjt_capture52);
        if (sjt_capture52 > 0) {
            int32_t sjt_functionParam244;
            int32_t sjt_functionParam245;
            sjs_array_vertex_location_texture_normal* sjt_parent156 = 0;
            sjs_array_i32* sjt_parent157 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent156 = &_parent->vertices;
#line 41
            sjt_parent157 = &_parent->indices;
#line 69 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam245 = (i * 3) + 2;
#line 69
            sjf_array_i32_getat(sjt_parent157, sjt_functionParam245, &sjt_functionParam244);
#line 69
            sjf_array_vertex_location_texture_normal_getat(sjt_parent156, sjt_functionParam244, &vertex2);
        } else {
            int32_t sjt_functionParam246;
            sjs_array_vertex_location_texture_normal* sjt_parent158 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent158 = &_parent->vertices;
#line 69 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam246 = (i * 3) + 2;
#line 69
            sjf_array_vertex_location_texture_normal_getat(sjt_parent158, sjt_functionParam246, &vertex2);
        }

#line 72 "lib/sj-lib-ui/vertexBuffer.sj"
        sjt_functionParam267 = &vpickrayorig;
#line 72
        sjt_functionParam268 = &vpickraydir;
#line 72
        sjt_functionParam269 = &(&vertex0)->location;
#line 72
        sjt_functionParam270 = &(&vertex1)->location;
#line 72
        sjt_functionParam271 = &(&vertex2)->location;
#line 72
        sjf_intersecttriangle(sjt_functionParam267, sjt_functionParam268, sjt_functionParam269, sjt_functionParam270, sjt_functionParam271, &result);
        if (((result._refCount != -1 ? &result : 0) != 0)) {
            sjs_vec3* ifValue5 = 0;
            float sjt_capture53;
            float_option sjt_capture54;
            sjs_vec3 sjt_value6 = { -1 };
            sjs_vec2 sjt_value7 = { -1 };

#line 73 "lib/sj-lib-ui/vertexBuffer.sj"
            ifValue5 = (result._refCount != -1 ? &result : 0);
            if ((intersection._refCount != -1 ? &intersection : 0) != 0) {
                sjs_vec3* sjt_capture55 = 0;
                float sjt_value4;

#line 1 "lib/sj-lib-ui/vec3.sj"
                sjt_capture55 = (intersection._refCount != -1 ? &intersection : 0);
#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                sjt_value4 = sjt_capture55->z;
#line 74
                sjt_capture54.isvalid = true;
#line 74
                sjt_capture54.value = sjt_value4;
            } else {
#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                sjt_capture54 = float_empty;
            }

            if (sjt_capture54.isvalid) {
                float_option sjt_getValue1;

                if ((intersection._refCount != -1 ? &intersection : 0) != 0) {
                    sjs_vec3* sjt_capture56 = 0;
                    float sjt_value5;

#line 1 "lib/sj-lib-ui/vec3.sj"
                    sjt_capture56 = (intersection._refCount != -1 ? &intersection : 0);
#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                    sjt_value5 = sjt_capture56->z;
#line 74
                    sjt_getValue1.isvalid = true;
#line 74
                    sjt_getValue1.value = sjt_value5;
                } else {
#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                    sjt_getValue1 = float_empty;
                }

#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                sjt_capture53 = sjt_getValue1.value;
            } else {
#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                sjt_capture53 = 0.0f;
            }

            if (((intersection._refCount != -1 ? &intersection : 0) == 0) || (ifValue5->z < sjt_capture53)) {
                float dtu1;
                float dtu2;
                float dtv1;
                float dtv2;

                sjt_value6._refCount = 1;
#line 75 "lib/sj-lib-ui/vertexBuffer.sj"
                sjf_vec3_copy(&sjt_value6, ifValue5);
#line 75
                if (intersection._refCount == 1) { sjf_vec3_destroy(&intersection); }
;
#line 75
                sjs_vec3* copyoption16 = &sjt_value6;
                if (copyoption16 != 0) {
                    intersection._refCount = 1;
#line 75 "lib/sj-lib-ui/vertexBuffer.sj"
                    sjf_vec3_copy(&intersection, copyoption16);
                } else {
                    intersection._refCount = -1;
                }

#line 80
                dtu1 = (&(&vertex1)->texture)->x - (&(&vertex0)->texture)->x;
#line 81
                dtu2 = (&(&vertex2)->texture)->x - (&(&vertex0)->texture)->x;
#line 82
                dtv1 = (&(&vertex1)->texture)->y - (&(&vertex0)->texture)->y;
#line 83
                dtv2 = (&(&vertex2)->texture)->y - (&(&vertex0)->texture)->y;
#line 83
                sjt_value7._refCount = 1;
#line 85
                sjt_value7.x = ((&(&vertex0)->texture)->x + (ifValue5->x * dtu1)) + (ifValue5->y * dtu2);
#line 86
                sjt_value7.y = ((&(&vertex0)->texture)->y + (ifValue5->x * dtv1)) + (ifValue5->y * dtv2);
#line 86
                sjf_vec2(&sjt_value7);
#line 86
                if (texture._refCount == 1) { sjf_vec2_destroy(&texture); }
;
#line 84
                sjs_vec2* copyoption17 = &sjt_value7;
                if (copyoption17 != 0) {
                    texture._refCount = 1;
#line 84 "lib/sj-lib-ui/vertexBuffer.sj"
                    sjf_vec2_copy(&texture, copyoption17);
                } else {
                    texture._refCount = -1;
                }
            }

            if (sjt_value6._refCount == 1) { sjf_vec3_destroy(&sjt_value6); }
;
            if (sjt_value7._refCount == 1) { sjf_vec2_destroy(&sjt_value7); }
;
        }

#line 66
        i++;

        if (result._refCount == 1) { sjf_vec3_destroy(&result); }
;
        if (vertex0._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&vertex0); }
;
        if (vertex1._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&vertex1); }
;
        if (vertex2._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&vertex2); }
;
    }

#line 43
    sjs_vec2* copyoption18 = (texture._refCount != -1 ? &texture : 0);
    if (copyoption18 != 0) {
        _return->_refCount = 1;
#line 43 "lib/sj-lib-ui/vertexBuffer.sj"
        sjf_vec2_copy(_return, copyoption18);
    } else {
        _return->_refCount = -1;
    }

    if (all._refCount == 1) { sjf_mat4_destroy(&all); }
;
    if (allinverse._refCount == 1) { sjf_mat4_destroy(&allinverse); }
;
    if (intersection._refCount == 1) { sjf_vec3_destroy(&intersection); }
;
    if (sjt_call28._refCount == 1) { sjf_mat4_destroy(&sjt_call28); }
;
    if (start._refCount == 1) { sjf_vec2_destroy(&start); }
;
    if (texture._refCount == 1) { sjf_vec2_destroy(&texture); }
;
    if (vflatteneddir._refCount == 1) { sjf_vec3_destroy(&vflatteneddir); }
;
    if (vflattenedorigin1._refCount == 1) { sjf_vec3_destroy(&vflattenedorigin1); }
;
    if (vflattenedorigin2._refCount == 1) { sjf_vec3_destroy(&vflattenedorigin2); }
;
    if (vpickraydir._refCount == 1) { sjf_vec3_destroy(&vpickraydir); }
;
    if (vpickrayorig._refCount == 1) { sjf_vec3_destroy(&vpickrayorig); }
;
    if (vprojectedorigin1._refCount == 1) { sjf_vec4_destroy(&vprojectedorigin1); }
;
    if (vprojectedorigin2._refCount == 1) { sjf_vec4_destroy(&vprojectedorigin2); }
;
    if (vscreenorigin1._refCount == 1) { sjf_vec4_destroy(&vscreenorigin1); }
;
    if (vscreenorigin2._refCount == 1) { sjf_vec4_destroy(&vscreenorigin2); }
;
}

void sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture_heap(sjs_vertexbuffer_vertex_location_texture_normal* _parent, sjs_point* screen, sjs_rect* viewport, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_vec2** _return) {
    sjs_mat4 all = { -1 };
    sjs_mat4 allinverse = { -1 };
    int32_t ctriangles;
    int32_t i;
    sjs_vec3 intersection = { -1 };
    sjs_mat4 sjt_call29 = { -1 };
    int32_t sjt_capture57;
    int32_t sjt_cast15;
    int32_t sjt_cast16;
    int32_t sjt_cast17;
    int32_t sjt_cast18;
    int32_t sjt_forEnd13;
    int32_t sjt_forStart13;
    sjs_mat4* sjt_functionParam272 = 0;
    sjs_mat4* sjt_functionParam273 = 0;
    sjs_vec4* sjt_functionParam274 = 0;
    sjs_vec4* sjt_functionParam275 = 0;
    sjs_vec3* sjt_functionParam276 = 0;
    sjs_mat4* sjt_parent179 = 0;
    sjs_mat4* sjt_parent180 = 0;
    sjs_mat4* sjt_parent181 = 0;
    sjs_mat4* sjt_parent182 = 0;
    sjs_mat4* sjt_parent183 = 0;
    sjs_vec3* sjt_parent184 = 0;
    sjs_vec3* sjt_parent185 = 0;
    sjs_array_i32* sjt_parent186 = 0;
    sjs_vec2 start = { -1 };
    sjs_vec2 texture = { -1 };
    sjs_vec3 vflatteneddir = { -1 };
    sjs_vec3 vflattenedorigin1 = { -1 };
    sjs_vec3 vflattenedorigin2 = { -1 };
    sjs_vec3 vpickraydir = { -1 };
    sjs_vec3 vpickrayorig = { -1 };
    sjs_vec4 vprojectedorigin1 = { -1 };
    sjs_vec4 vprojectedorigin2 = { -1 };
    sjs_vec4 vscreenorigin1 = { -1 };
    sjs_vec4 vscreenorigin2 = { -1 };

#line 44 "lib/sj-lib-ui/vertexBuffer.sj"
    intersection._refCount = -1;
#line 45
    texture._refCount = -1;
#line 45
    start._refCount = 1;
#line 49
    sjt_cast15 = screen->x - viewport->x;
#line 49
    sjt_cast16 = viewport->w;
#line 49
    start.x = (((float)sjt_cast15 / (float)sjt_cast16) * 2.0f) - 1.0f;
#line 50
    sjt_cast17 = screen->y - viewport->y;
#line 50
    sjt_cast18 = viewport->h;
#line 50
    start.y = 1.0f - (((float)sjt_cast17 / (float)sjt_cast18) * 2.0f);
#line 50
    sjf_vec2(&start);
#line 50
    vscreenorigin1._refCount = 1;
#line 52
    vscreenorigin1.x = (&start)->x;
#line 52
    vscreenorigin1.y = (&start)->y;
#line 52
    vscreenorigin1.z = 0.0f;
#line 52
    vscreenorigin1.w = 1.0f;
#line 52
    sjf_vec4(&vscreenorigin1);
#line 52
    vscreenorigin2._refCount = 1;
#line 53
    vscreenorigin2.x = (&start)->x;
#line 53
    vscreenorigin2.y = (&start)->y;
#line 53
    vscreenorigin2.z = 1.0f;
#line 53
    vscreenorigin2.w = 1.0f;
#line 53
    sjf_vec4(&vscreenorigin2);
#line 43
    sjt_parent180 = projection;
#line 43
    sjt_functionParam272 = view;
#line 43
    sjf_mat4_multiply(sjt_parent180, sjt_functionParam272, &sjt_call29);
#line 54
    sjt_parent179 = &sjt_call29;
#line 43
    sjt_functionParam273 = world;
#line 43
    sjf_mat4_multiply(sjt_parent179, sjt_functionParam273, &all);
#line 71 "lib/sj-lib-ui/mat4.sj"
    sjt_parent181 = &all;
#line 71
    sjf_mat4_invert(sjt_parent181, &allinverse);
#line 62
    sjt_parent182 = &allinverse;
#line 56 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_functionParam274 = &vscreenorigin1;
#line 56
    sjf_mat4_multiplyvec4(sjt_parent182, sjt_functionParam274, &vprojectedorigin1);
#line 62 "lib/sj-lib-ui/mat4.sj"
    sjt_parent183 = &allinverse;
#line 57 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_functionParam275 = &vscreenorigin2;
#line 57
    sjf_mat4_multiplyvec4(sjt_parent183, sjt_functionParam275, &vprojectedorigin2);
#line 57
    vflattenedorigin1._refCount = 1;
#line 58
    vflattenedorigin1.x = (&vprojectedorigin1)->x / (&vprojectedorigin1)->w;
#line 58
    vflattenedorigin1.y = (&vprojectedorigin1)->y / (&vprojectedorigin1)->w;
#line 58
    vflattenedorigin1.z = (&vprojectedorigin1)->z / (&vprojectedorigin1)->w;
#line 58
    sjf_vec3(&vflattenedorigin1);
#line 58
    vflattenedorigin2._refCount = 1;
#line 59
    vflattenedorigin2.x = (&vprojectedorigin2)->x / (&vprojectedorigin2)->w;
#line 59
    vflattenedorigin2.y = (&vprojectedorigin2)->y / (&vprojectedorigin2)->w;
#line 59
    vflattenedorigin2.z = (&vprojectedorigin2)->z / (&vprojectedorigin2)->w;
#line 59
    sjf_vec3(&vflattenedorigin2);
#line 30 "lib/sj-lib-ui/vec3.sj"
    sjt_parent184 = &vflattenedorigin2;
#line 60 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_functionParam276 = &vflattenedorigin1;
#line 60
    sjf_vec3_subtract(sjt_parent184, sjt_functionParam276, &vflatteneddir);
#line 60
    vpickrayorig._refCount = 1;
#line 62
    sjf_vec3_copy(&vpickrayorig, &vflattenedorigin1);
#line 38 "lib/sj-lib-ui/vec3.sj"
    sjt_parent185 = &vflatteneddir;
#line 38
    sjf_vec3_normalize(sjt_parent185, &vpickraydir);
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent186 = &_parent->indices;
#line 29
    sjf_array_i32_getcount(sjt_parent186, &sjt_capture57);
    if (sjt_capture57 > 0) {
        int32_t sjt_capture58;
        sjs_array_i32* sjt_parent187 = 0;

#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent187 = &_parent->indices;
#line 29
        sjf_array_i32_getcount(sjt_parent187, &sjt_capture58);
#line 65 "lib/sj-lib-ui/vertexBuffer.sj"
        ctriangles = sjt_capture58 / 3;
    } else {
        int32_t sjt_capture59;
        sjs_array_vertex_location_texture_normal* sjt_parent188 = 0;

#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent188 = &_parent->vertices;
#line 29
        sjf_array_vertex_location_texture_normal_getcount(sjt_parent188, &sjt_capture59);
#line 65 "lib/sj-lib-ui/vertexBuffer.sj"
        ctriangles = sjt_capture59 / 3;
    }

#line 66 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_forStart13 = 0;
#line 66
    sjt_forEnd13 = ctriangles;
#line 66
    i = sjt_forStart13;
    while (i < sjt_forEnd13) {
        sjs_vec3 result = { -1 };
        int32_t sjt_capture60;
        int32_t sjt_capture61;
        int32_t sjt_capture62;
        sjs_vec3* sjt_functionParam286 = 0;
        sjs_vec3* sjt_functionParam287 = 0;
        sjs_vec3* sjt_functionParam288 = 0;
        sjs_vec3* sjt_functionParam289 = 0;
        sjs_vec3* sjt_functionParam290 = 0;
        sjs_array_i32* sjt_parent189 = 0;
        sjs_array_i32* sjt_parent193 = 0;
        sjs_array_i32* sjt_parent197 = 0;
        sjs_vertex_location_texture_normal vertex0 = { -1 };
        sjs_vertex_location_texture_normal vertex1 = { -1 };
        sjs_vertex_location_texture_normal vertex2 = { -1 };

#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent189 = &_parent->indices;
#line 29
        sjf_array_i32_getcount(sjt_parent189, &sjt_capture60);
        if (sjt_capture60 > 0) {
            int32_t sjt_functionParam277;
            int32_t sjt_functionParam278;
            sjs_array_vertex_location_texture_normal* sjt_parent190 = 0;
            sjs_array_i32* sjt_parent191 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent190 = &_parent->vertices;
#line 41
            sjt_parent191 = &_parent->indices;
#line 67 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam278 = (i * 3) + 0;
#line 67
            sjf_array_i32_getat(sjt_parent191, sjt_functionParam278, &sjt_functionParam277);
#line 67
            sjf_array_vertex_location_texture_normal_getat(sjt_parent190, sjt_functionParam277, &vertex0);
        } else {
            int32_t sjt_functionParam279;
            sjs_array_vertex_location_texture_normal* sjt_parent192 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent192 = &_parent->vertices;
#line 67 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam279 = (i * 3) + 0;
#line 67
            sjf_array_vertex_location_texture_normal_getat(sjt_parent192, sjt_functionParam279, &vertex0);
        }

#line 29
        sjt_parent193 = &_parent->indices;
#line 29
        sjf_array_i32_getcount(sjt_parent193, &sjt_capture61);
        if (sjt_capture61 > 0) {
            int32_t sjt_functionParam280;
            int32_t sjt_functionParam281;
            sjs_array_vertex_location_texture_normal* sjt_parent194 = 0;
            sjs_array_i32* sjt_parent195 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent194 = &_parent->vertices;
#line 41
            sjt_parent195 = &_parent->indices;
#line 68 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam281 = (i * 3) + 1;
#line 68
            sjf_array_i32_getat(sjt_parent195, sjt_functionParam281, &sjt_functionParam280);
#line 68
            sjf_array_vertex_location_texture_normal_getat(sjt_parent194, sjt_functionParam280, &vertex1);
        } else {
            int32_t sjt_functionParam282;
            sjs_array_vertex_location_texture_normal* sjt_parent196 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent196 = &_parent->vertices;
#line 68 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam282 = (i * 3) + 1;
#line 68
            sjf_array_vertex_location_texture_normal_getat(sjt_parent196, sjt_functionParam282, &vertex1);
        }

#line 29
        sjt_parent197 = &_parent->indices;
#line 29
        sjf_array_i32_getcount(sjt_parent197, &sjt_capture62);
        if (sjt_capture62 > 0) {
            int32_t sjt_functionParam283;
            int32_t sjt_functionParam284;
            sjs_array_vertex_location_texture_normal* sjt_parent198 = 0;
            sjs_array_i32* sjt_parent199 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent198 = &_parent->vertices;
#line 41
            sjt_parent199 = &_parent->indices;
#line 69 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam284 = (i * 3) + 2;
#line 69
            sjf_array_i32_getat(sjt_parent199, sjt_functionParam284, &sjt_functionParam283);
#line 69
            sjf_array_vertex_location_texture_normal_getat(sjt_parent198, sjt_functionParam283, &vertex2);
        } else {
            int32_t sjt_functionParam285;
            sjs_array_vertex_location_texture_normal* sjt_parent200 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent200 = &_parent->vertices;
#line 69 "lib/sj-lib-ui/vertexBuffer.sj"
            sjt_functionParam285 = (i * 3) + 2;
#line 69
            sjf_array_vertex_location_texture_normal_getat(sjt_parent200, sjt_functionParam285, &vertex2);
        }

#line 72 "lib/sj-lib-ui/vertexBuffer.sj"
        sjt_functionParam286 = &vpickrayorig;
#line 72
        sjt_functionParam287 = &vpickraydir;
#line 72
        sjt_functionParam288 = &(&vertex0)->location;
#line 72
        sjt_functionParam289 = &(&vertex1)->location;
#line 72
        sjt_functionParam290 = &(&vertex2)->location;
#line 72
        sjf_intersecttriangle(sjt_functionParam286, sjt_functionParam287, sjt_functionParam288, sjt_functionParam289, sjt_functionParam290, &result);
        if (((result._refCount != -1 ? &result : 0) != 0)) {
            sjs_vec3* ifValue6 = 0;
            float sjt_capture63;
            float_option sjt_capture64;
            sjs_vec3 sjt_value10 = { -1 };
            sjs_vec2 sjt_value11 = { -1 };

#line 73 "lib/sj-lib-ui/vertexBuffer.sj"
            ifValue6 = (result._refCount != -1 ? &result : 0);
            if ((intersection._refCount != -1 ? &intersection : 0) != 0) {
                sjs_vec3* sjt_capture65 = 0;
                float sjt_value8;

#line 1 "lib/sj-lib-ui/vec3.sj"
                sjt_capture65 = (intersection._refCount != -1 ? &intersection : 0);
#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                sjt_value8 = sjt_capture65->z;
#line 74
                sjt_capture64.isvalid = true;
#line 74
                sjt_capture64.value = sjt_value8;
            } else {
#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                sjt_capture64 = float_empty;
            }

            if (sjt_capture64.isvalid) {
                float_option sjt_getValue2;

                if ((intersection._refCount != -1 ? &intersection : 0) != 0) {
                    sjs_vec3* sjt_capture66 = 0;
                    float sjt_value9;

#line 1 "lib/sj-lib-ui/vec3.sj"
                    sjt_capture66 = (intersection._refCount != -1 ? &intersection : 0);
#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                    sjt_value9 = sjt_capture66->z;
#line 74
                    sjt_getValue2.isvalid = true;
#line 74
                    sjt_getValue2.value = sjt_value9;
                } else {
#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                    sjt_getValue2 = float_empty;
                }

#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                sjt_capture63 = sjt_getValue2.value;
            } else {
#line 74 "lib/sj-lib-ui/vertexBuffer.sj"
                sjt_capture63 = 0.0f;
            }

            if (((intersection._refCount != -1 ? &intersection : 0) == 0) || (ifValue6->z < sjt_capture63)) {
                float dtu1;
                float dtu2;
                float dtv1;
                float dtv2;

                sjt_value10._refCount = 1;
#line 75 "lib/sj-lib-ui/vertexBuffer.sj"
                sjf_vec3_copy(&sjt_value10, ifValue6);
#line 75
                if (intersection._refCount == 1) { sjf_vec3_destroy(&intersection); }
;
#line 75
                sjs_vec3* copyoption19 = &sjt_value10;
                if (copyoption19 != 0) {
                    intersection._refCount = 1;
#line 75 "lib/sj-lib-ui/vertexBuffer.sj"
                    sjf_vec3_copy(&intersection, copyoption19);
                } else {
                    intersection._refCount = -1;
                }

#line 80
                dtu1 = (&(&vertex1)->texture)->x - (&(&vertex0)->texture)->x;
#line 81
                dtu2 = (&(&vertex2)->texture)->x - (&(&vertex0)->texture)->x;
#line 82
                dtv1 = (&(&vertex1)->texture)->y - (&(&vertex0)->texture)->y;
#line 83
                dtv2 = (&(&vertex2)->texture)->y - (&(&vertex0)->texture)->y;
#line 83
                sjt_value11._refCount = 1;
#line 85
                sjt_value11.x = ((&(&vertex0)->texture)->x + (ifValue6->x * dtu1)) + (ifValue6->y * dtu2);
#line 86
                sjt_value11.y = ((&(&vertex0)->texture)->y + (ifValue6->x * dtv1)) + (ifValue6->y * dtv2);
#line 86
                sjf_vec2(&sjt_value11);
#line 86
                if (texture._refCount == 1) { sjf_vec2_destroy(&texture); }
;
#line 84
                sjs_vec2* copyoption20 = &sjt_value11;
                if (copyoption20 != 0) {
                    texture._refCount = 1;
#line 84 "lib/sj-lib-ui/vertexBuffer.sj"
                    sjf_vec2_copy(&texture, copyoption20);
                } else {
                    texture._refCount = -1;
                }
            }

            if (sjt_value10._refCount == 1) { sjf_vec3_destroy(&sjt_value10); }
;
            if (sjt_value11._refCount == 1) { sjf_vec2_destroy(&sjt_value11); }
;
        }

#line 66
        i++;

        if (result._refCount == 1) { sjf_vec3_destroy(&result); }
;
        if (vertex0._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&vertex0); }
;
        if (vertex1._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&vertex1); }
;
        if (vertex2._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&vertex2); }
;
    }

#line 43
    sjs_vec2* copyoption21 = (texture._refCount != -1 ? &texture : 0);
    if (copyoption21 != 0) {
        (*_return) = 0;
#line 43 "lib/sj-lib-ui/vertexBuffer.sj"
        sjf_vec2_copy((*_return), copyoption21);
    } else {
        (*_return) = 0;
    }

    if (all._refCount == 1) { sjf_mat4_destroy(&all); }
;
    if (allinverse._refCount == 1) { sjf_mat4_destroy(&allinverse); }
;
    if (intersection._refCount == 1) { sjf_vec3_destroy(&intersection); }
;
    if (sjt_call29._refCount == 1) { sjf_mat4_destroy(&sjt_call29); }
;
    if (start._refCount == 1) { sjf_vec2_destroy(&start); }
;
    if (texture._refCount == 1) { sjf_vec2_destroy(&texture); }
;
    if (vflatteneddir._refCount == 1) { sjf_vec3_destroy(&vflatteneddir); }
;
    if (vflattenedorigin1._refCount == 1) { sjf_vec3_destroy(&vflattenedorigin1); }
;
    if (vflattenedorigin2._refCount == 1) { sjf_vec3_destroy(&vflattenedorigin2); }
;
    if (vpickraydir._refCount == 1) { sjf_vec3_destroy(&vpickraydir); }
;
    if (vpickrayorig._refCount == 1) { sjf_vec3_destroy(&vpickrayorig); }
;
    if (vprojectedorigin1._refCount == 1) { sjf_vec4_destroy(&vprojectedorigin1); }
;
    if (vprojectedorigin2._refCount == 1) { sjf_vec4_destroy(&vprojectedorigin2); }
;
    if (vscreenorigin1._refCount == 1) { sjf_vec4_destroy(&vscreenorigin1); }
;
    if (vscreenorigin2._refCount == 1) { sjf_vec4_destroy(&vscreenorigin2); }
;
}

void sjf_windowrenderer(sjs_windowrenderer* _this) {
    sjs_color sjt_call1 = { -1 };
    sjs_color* sjt_functionParam4 = 0;
    int32_t sjt_functionParam5;
    int32_t sjt_functionParam6;
    int32_t sjt_functionParam7;

#line 30 "lib/sj-lib-ui/windowRenderer.sj"
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
    sjt_functionParam4 = &sjt_call1;
#line 65
    sjf_glclearcolor(sjt_functionParam4);
#line 66
    sjt_functionParam5 = g_glblendfunctype_gl_src_alpha;
#line 66
    sjt_functionParam6 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 66
    sjf_glblendfunc(sjt_functionParam5, sjt_functionParam6);
#line 67
    sjt_functionParam7 = g_glfeature_gl_blend;
#line 67
    sjf_glenable(sjt_functionParam7);

    if (sjt_call1._refCount == 1) { sjf_color_destroy(&sjt_call1); }
;
}

void sjf_windowrenderer_copy(sjs_windowrenderer* _this, sjs_windowrenderer* _from) {
#line 71 "lib/sj-lib-ui/windowRenderer.sj"
    _this->ren = _from->ren;
#line 72
    ptr_retain(_this->ren);
#line 73
    _this->win = _from->win;
#line 74
    ptr_retain(_this->win);
}

void sjf_windowrenderer_destroy(sjs_windowrenderer* _this) {
#line 78 "lib/sj-lib-ui/windowRenderer.sj"
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
    int32_t h;
    int32_t w;

#line 8 "lib/sj-lib-ui/windowRenderer.sj"
    w = 0;
#line 9
    h = 0;
#line 11
    SDL_GetRendererOutputSize(_parent->ren, &w, &h);
#line 11
    _return->_refCount = 1;
#line 13
    _return->w = w;
#line 13
    _return->h = h;
#line 13
    sjf_size(_return);
}

void sjf_windowrenderer_getsize_heap(sjs_windowrenderer* _parent, sjs_size** _return) {
    int32_t h;
    int32_t w;

#line 8 "lib/sj-lib-ui/windowRenderer.sj"
    w = 0;
#line 9
    h = 0;
#line 11
    SDL_GetRendererOutputSize(_parent->ren, &w, &h);
#line 11
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
#line 11
    (*_return)->_refCount = 1;
#line 13
    (*_return)->w = w;
#line 13
    (*_return)->h = h;
#line 13
    sjf_size_heap((*_return));
}

void sjf_windowrenderer_heap(sjs_windowrenderer* _this) {
    sjs_color sjt_call2 = { -1 };
    int32_t sjt_functionParam10;
    int32_t sjt_functionParam11;
    sjs_color* sjt_functionParam8 = 0;
    int32_t sjt_functionParam9;

#line 30 "lib/sj-lib-ui/windowRenderer.sj"
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
    sjt_functionParam8 = &sjt_call2;
#line 65
    sjf_glclearcolor(sjt_functionParam8);
#line 66
    sjt_functionParam9 = g_glblendfunctype_gl_src_alpha;
#line 66
    sjt_functionParam10 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 66
    sjf_glblendfunc(sjt_functionParam9, sjt_functionParam10);
#line 67
    sjt_functionParam11 = g_glfeature_gl_blend;
#line 67
    sjf_glenable(sjt_functionParam11);

    if (sjt_call2._refCount == 1) { sjf_color_destroy(&sjt_call2); }
;
}

void sjf_windowrenderer_present(sjs_windowrenderer* _parent) {
#line 24 "lib/sj-lib-ui/windowRenderer.sj"
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
#line 1 "lib/sj-lib-common/log.sj"
    g_loglevel_trace = 0;
#line 1
    g_loglevel_debug = 1;
#line 1
    g_loglevel_info = 2;
#line 1
    g_loglevel_warn = 3;
#line 1
    g_loglevel_error = 4;
#line 1
    g_loglevel_fatal = 5;
#line 1 "lib/sj-lib-ui/borderLayout.sj"
    g_borderposition_fill = 0;
#line 1
    g_borderposition_left = 1;
#line 1
    g_borderposition_right = 2;
#line 1
    g_borderposition_top = 3;
#line 1
    g_borderposition_bottom = 4;
#line 1 "lib/sj-lib-ui/clickGesture.sj"
    g_clickstate_none = 0;
#line 1
    g_clickstate_entered = 1;
#line 1
    g_clickstate_pressed = 2;
#line 1 "lib/sj-lib-ui/flowLayout.sj"
    g_flowlayoutorientation_topbottom = 0;
#line 1
    g_flowlayoutorientation_leftright = 1;
#line 1
    g_flowlayoutorientation_bottomtop = 2;
#line 1
    g_flowlayoutorientation_rightleft = 3;
#line 1 "lib/sj-lib-ui/gl.sj"
    g_glfeature_gl_blend = 0x0BE2;
#line 1
    g_glfeature_gl_cull_face = 0x0B44;
#line 1
    g_glfeature_gl_depth_test = 0x0B71;
#line 1
    g_glfeature_gl_dither = 0x0BD0;
#line 1
    g_glfeature_gl_polygon_offset_fill = 0x8037;
#line 1
    g_glfeature_gl_sample_alpha_to_coverage = 0x809E;
#line 1
    g_glfeature_gl_sample_coverage = 0x80A0;
#line 1
    g_glfeature_gl_scissor_test = 0x0C11;
#line 1
    g_glfeature_gl_stencil_test = 0x0B90;
#line 13
    g_gltexture_gl_texture_2d = 0x0DE1;
#line 13
    g_gltexture_gl_texture_cube_map = 0x8513;
#line 18
    g_gltextureattribute_gl_texture_min_filter = 0x2801;
#line 18
    g_gltextureattribute_gl_texture_mag_filter = 0x2800;
#line 18
    g_gltextureattribute_gl_texture_wrap_s = 0x2802;
#line 18
    g_gltextureattribute_gl_texture_wrap_t = 0x2803;
#line 25
    g_gltexturevalue_gl_clamp_to_edge = 0x812F;
#line 25
    g_gltexturevalue_gl_mirrored_repeat = 0x8370;
#line 25
    g_gltexturevalue_gl_repeat = 0x2901;
#line 25
    g_gltexturevalue_gl_nearest = 0x2600;
#line 25
    g_gltexturevalue_gl_linear = 0x2601;
#line 25
    g_gltexturevalue_gl_nearest_mipmap_nearest = 0x2700;
#line 25
    g_gltexturevalue_gl_linear_mipmap_nearest = 0x2701;
#line 25
    g_gltexturevalue_gl_nearest_mipmap_linear = 0x2702;
#line 25
    g_gltexturevalue_gl_linear_mipmap_linear = 0x2703;
#line 37
    g_gltextureformat_gl_alpha = 0x1906;
#line 37
    g_gltextureformat_gl_luminance = 0x1909;
#line 37
    g_gltextureformat_gl_luminance_alpha = 0x190A;
#line 37
    g_gltextureformat_gl_rgb = 0x1907;
#line 37
    g_gltextureformat_gl_rgba = 0x1908;
#line 45
    g_gltexturetype_gl_unsigned_byte = 0x1401;
#line 45
    g_gltexturetype_gl_unsigned_short_5_6_5 = 0x8363;
#line 45
    g_gltexturetype_gl_unsigned_short_4_4_4_4 = 0x8033;
#line 45
    g_gltexturetype_gl_unsigned_short_5_5_5_1 = 0x8034;
#line 52
    g_glframebufferattachment_gl_color_attachment0 = 0x8CE0;
#line 52
    g_glframebufferattachment_gl_depth_attachment = 0x8D00;
#line 52
    g_glframebufferattachment_gl_stencil_attachment = 0x8D20;
#line 58
    g_glframebuffertexture_gl_texture_2d = 0x0DE1;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_positive_x = 0x8515;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_negative_x = 0x8516;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_positive_y = 0x8517;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_negative_y = 0x8518;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_positive_z = 0x8519;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_negative_z = 0x851A;
#line 68
    g_glrenderbufferformat_gl_rgba4 = 0x8056;
#line 68
    g_glrenderbufferformat_gl_rgb565 = 0x8D62;
#line 68
    g_glrenderbufferformat_gl_rgb5_a1 = 0x8057;
#line 68
    g_glrenderbufferformat_gl_depth_component16 = 0x81A5;
#line 68
    g_glrenderbufferformat_gl_stencil_index8 = 0x8D48;
#line 76
    g_glframebufferstatus_gl_framebuffer_complete = 0x8CD5;
#line 76
    g_glframebufferstatus_gl_framebuffer_incomplete_attachment = 0x8CD6;
#line 76
    g_glframebufferstatus_gl_framebuffer_incomplete_missing_attachment = 0x8CD7;
#line 76
    g_glframebufferstatus_gl_framebuffer_unsupported = 0x8CDD;
#line 83
    g_glblendfunctype_gl_zero = 0;
#line 83
    g_glblendfunctype_gl_one = 1;
#line 83
    g_glblendfunctype_gl_src_color = 0x0300;
#line 83
    g_glblendfunctype_gl_one_minus_src_color = 0x0301;
#line 83
    g_glblendfunctype_gl_dst_color = 0x0306;
#line 83
    g_glblendfunctype_gl_one_minus_dst_color = 0x0307;
#line 83
    g_glblendfunctype_gl_src_alpha = 0x0302;
#line 83
    g_glblendfunctype_gl_one_minus_src_alpha = 0x0303;
#line 83
    g_glblendfunctype_gl_dst_alpha = 0x0304;
#line 83
    g_glblendfunctype_gl_one_minus_dst_alpha = 0x0305;
#line 83
    g_glblendfunctype_gl_constant_color = 0x8001;
#line 83
    g_glblendfunctype_gl_one_minus_constant_color = 0x8002;
#line 83
    g_glblendfunctype_gl_constant_alpha = 0x8003;
#line 83
    g_glblendfunctype_gl_one_minus_constant_alpha = 0x8004;
#line 83
    g_glblendfunctype_gl_src_alpha_saturate = 0x0308;
#line 101
    g_gldrawmode_gl_points = 0x0000;
#line 101
    g_gldrawmode_gl_line_strip = 0x0003;
#line 101
    g_gldrawmode_gl_line_loop = 0x0002;
#line 101
    g_gldrawmode_gl_lines = 0x0001;
#line 101
    g_gldrawmode_gl_triangle_strip = 0x0005;
#line 101
    g_gldrawmode_gl_triangle_fan = 0x0006;
#line 101
    g_gldrawmode_gl_triangles = 0x0004;
#line 36 "lib/sj-lib-ui/gridLayout.sj"
    g_gridunittype_fixed = 0;
#line 36
    g_gridunittype_star = 1;
#line 1 "lib/sj-lib-ui/imageElement.sj"
    g_imagestretch_fill = 0;
#line 1
    g_imagestretch_center = 1;
#line 1
    g_imagestretch_aspectratio = 2;
#line 1 "lib/sj-lib-ui/listLayout.sj"
    g_listlayoutorientation_topbottom = 0;
#line 1
    g_listlayoutorientation_leftright = 1;
#line 1
    g_listlayoutorientation_bottomtop = 2;
#line 1
    g_listlayoutorientation_rightleft = 3;
#line 32 "lib/sj-lib-ui/mouse.sj"
    g_mouseeventtype_move = 0;
#line 32
    g_mouseeventtype_up = 1;
#line 32
    g_mouseeventtype_down = 2;
#line 1 "lib/sj-lib-ui/textElement.sj"
    g_texthorizontal_left = 0;
#line 1
    g_texthorizontal_right = 1;
#line 1
    g_texthorizontal_center = 2;
#line 7
    g_textvertical_top = 0;
#line 7
    g_textvertical_bottom = 1;
#line 7
    g_textvertical_center = 2;
#line 1 "lib/sj-lib-common/f32.sj"
    g_f32_pi = 3.14159265358979323846f;
#line 1 "lib/sj-lib-common/i32.sj"
    g_u32_maxvalue = (uint32_t)4294967295u;
#line 3
    result1 = -1;
#line 3
    g_i32_maxvalue = result1 - 2147483647;
#line 4
    g_i32_minvalue = 2147483647;
#line 10 "lib/sj-lib-common/log.sj"
    g_log_includeall._refCount = -1;
#line 10
    sjt_value1._refCount = 1;
#line 10
    sjf_hash_type_bool(&sjt_value1);
#line 11
    sjs_hash_type_bool* copyoption1 = &sjt_value1;
    if (copyoption1 != 0) {
        g_log_excludeall._refCount = 1;
#line 11 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log_excludeall, copyoption1);
    } else {
        g_log_excludeall._refCount = -1;
    }

#line 11
    g_log._refCount = 1;
#line 13
    g_log.minlevel = g_loglevel_warn;
#line 13
    sjs_hash_type_bool* copyoption8 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption8 != 0) {
        g_log.traceincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.traceincludes, copyoption8);
    } else {
        g_log.traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption9 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption9 != 0) {
        g_log.debugincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.debugincludes, copyoption9);
    } else {
        g_log.debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption10 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption10 != 0) {
        g_log.infoincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.infoincludes, copyoption10);
    } else {
        g_log.infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption11 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption11 != 0) {
        g_log.warnincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.warnincludes, copyoption11);
    } else {
        g_log.warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption12 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption12 != 0) {
        g_log.errorincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.errorincludes, copyoption12);
    } else {
        g_log.errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption13 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption13 != 0) {
        g_log.fatalincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.fatalincludes, copyoption13);
    } else {
        g_log.fatalincludes._refCount = -1;
    }

#line 13
    sjf_log(&g_log);
#line 2 "lib/sj-lib-common/weakptr.sj"
    ptr_init();
#line 3
    weakptr_init();
#line 7 "lib/sj-lib-common/clock.sj"
    g_clocks_per_sec = 0;
#line 9
    g_clocks_per_sec = CLOCKS_PER_SEC;
#line 9
    g_rootwindowrenderer._refCount = 1;
#line 9
    sjf_windowrenderer(&g_rootwindowrenderer);
#line 9
    g_rootscene._refCount = 1;
#line 9
    g_rootscene._size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    g_rootscene._size.w = 0;
#line 3
    g_rootscene._size.h = 0;
#line 3
    sjf_size(&g_rootscene._size);
#line 3
    g_rootscene.model._refCount = 1;
#line 2 "lib/sj-lib-ui/mat4.sj"
    g_rootscene.model.m00 = 0.0f;
#line 3
    g_rootscene.model.m01 = 0.0f;
#line 4
    g_rootscene.model.m02 = 0.0f;
#line 5
    g_rootscene.model.m03 = 0.0f;
#line 6
    g_rootscene.model.m10 = 0.0f;
#line 7
    g_rootscene.model.m11 = 0.0f;
#line 8
    g_rootscene.model.m12 = 0.0f;
#line 9
    g_rootscene.model.m13 = 0.0f;
#line 10
    g_rootscene.model.m20 = 0.0f;
#line 11
    g_rootscene.model.m21 = 0.0f;
#line 12
    g_rootscene.model.m22 = 0.0f;
#line 13
    g_rootscene.model.m23 = 0.0f;
#line 14
    g_rootscene.model.m30 = 0.0f;
#line 15
    g_rootscene.model.m31 = 0.0f;
#line 16
    g_rootscene.model.m32 = 0.0f;
#line 17
    g_rootscene.model.m33 = 0.0f;
#line 17
    sjf_mat4(&g_rootscene.model);
#line 17
    g_rootscene.view._refCount = 1;
#line 2
    g_rootscene.view.m00 = 0.0f;
#line 3
    g_rootscene.view.m01 = 0.0f;
#line 4
    g_rootscene.view.m02 = 0.0f;
#line 5
    g_rootscene.view.m03 = 0.0f;
#line 6
    g_rootscene.view.m10 = 0.0f;
#line 7
    g_rootscene.view.m11 = 0.0f;
#line 8
    g_rootscene.view.m12 = 0.0f;
#line 9
    g_rootscene.view.m13 = 0.0f;
#line 10
    g_rootscene.view.m20 = 0.0f;
#line 11
    g_rootscene.view.m21 = 0.0f;
#line 12
    g_rootscene.view.m22 = 0.0f;
#line 13
    g_rootscene.view.m23 = 0.0f;
#line 14
    g_rootscene.view.m30 = 0.0f;
#line 15
    g_rootscene.view.m31 = 0.0f;
#line 16
    g_rootscene.view.m32 = 0.0f;
#line 17
    g_rootscene.view.m33 = 0.0f;
#line 17
    sjf_mat4(&g_rootscene.view);
#line 17
    g_rootscene.projection._refCount = 1;
#line 2
    g_rootscene.projection.m00 = 0.0f;
#line 3
    g_rootscene.projection.m01 = 0.0f;
#line 4
    g_rootscene.projection.m02 = 0.0f;
#line 5
    g_rootscene.projection.m03 = 0.0f;
#line 6
    g_rootscene.projection.m10 = 0.0f;
#line 7
    g_rootscene.projection.m11 = 0.0f;
#line 8
    g_rootscene.projection.m12 = 0.0f;
#line 9
    g_rootscene.projection.m13 = 0.0f;
#line 10
    g_rootscene.projection.m20 = 0.0f;
#line 11
    g_rootscene.projection.m21 = 0.0f;
#line 12
    g_rootscene.projection.m22 = 0.0f;
#line 13
    g_rootscene.projection.m23 = 0.0f;
#line 14
    g_rootscene.projection.m30 = 0.0f;
#line 15
    g_rootscene.projection.m31 = 0.0f;
#line 16
    g_rootscene.projection.m32 = 0.0f;
#line 17
    g_rootscene.projection.m33 = 0.0f;
#line 17
    sjf_mat4(&g_rootscene.projection);
#line 17
    g_rootscene.windowrect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    g_rootscene.windowrect.x = 0;
#line 3
    g_rootscene.windowrect.y = 0;
#line 4
    g_rootscene.windowrect.w = 0;
#line 5
    g_rootscene.windowrect.h = 0;
#line 5
    sjf_rect(&g_rootscene.windowrect);
#line 5
    sjf_scene2d(&g_rootscene);
#line 5
    g_modelsbyid._refCount = 1;
#line 5
    sjf_hash_string_weak_iface_model(&g_modelsbyid);
#line 5
    g_elementsbyid._refCount = 1;
#line 5
    sjf_hash_string_weak_iface_element(&g_elementsbyid);
#line 5
    g_animator._refCount = 1;
#line 5
    g_animator.animations._refCount = 1;
#line 5
    g_animator.animations.arr._refCount = 1;
#line 27 "lib/sj-lib-common/array.sj"
    g_animator.animations.arr.v = 0;
#line 27
    sjf_array_heap_iface_animation(&g_animator.animations.arr);
#line 27
    sjf_list_heap_iface_animation(&g_animator.animations);
#line 29 "lib/sj-lib-ui/animation.sj"
    g_animator.current = 0;
#line 29
    sjf_animator(&g_animator);
#line 29
    g_blurhorizontalshader._refCount = 1;
#line 29
    g_blurhorizontalshader.vertex._refCount = 1;
#line 1 "lib/sj-lib-ui/blurEffect.sj"
    g_blurhorizontalshader.vertex.offset = 0;
#line 1
    g_blurhorizontalshader.vertex.count = 37;
#line 1
    g_blurhorizontalshader.vertex.data._refCount = 1;
#line 1
    g_blurhorizontalshader.vertex.data.v = &sjg_string1;
#line 1
    sjf_array_char(&g_blurhorizontalshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_blurhorizontalshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_blurhorizontalshader.vertex);
#line 16
    g_blurhorizontalshader.pixel._refCount = 1;
#line 1 "lib/sj-lib-ui/blurEffect.sj"
    g_blurhorizontalshader.pixel.offset = 0;
#line 1
    g_blurhorizontalshader.pixel.count = 45;
#line 1
    g_blurhorizontalshader.pixel.data._refCount = 1;
#line 1
    g_blurhorizontalshader.pixel.data.v = &sjg_string2;
#line 1
    sjf_array_char(&g_blurhorizontalshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_blurhorizontalshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_blurhorizontalshader.pixel);
#line 16
    sjf_shader(&g_blurhorizontalshader);
#line 16
    g_blurverticalshader._refCount = 1;
#line 16
    g_blurverticalshader.vertex._refCount = 1;
#line 2 "lib/sj-lib-ui/blurEffect.sj"
    g_blurverticalshader.vertex.offset = 0;
#line 2
    g_blurverticalshader.vertex.count = 37;
#line 2
    g_blurverticalshader.vertex.data._refCount = 1;
#line 2
    g_blurverticalshader.vertex.data.v = &sjg_string1;
#line 2
    sjf_array_char(&g_blurverticalshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_blurverticalshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_blurverticalshader.vertex);
#line 16
    g_blurverticalshader.pixel._refCount = 1;
#line 2 "lib/sj-lib-ui/blurEffect.sj"
    g_blurverticalshader.pixel.offset = 0;
#line 2
    g_blurverticalshader.pixel.count = 43;
#line 2
    g_blurverticalshader.pixel.data._refCount = 1;
#line 2
    g_blurverticalshader.pixel.data.v = &sjg_string3;
#line 2
    sjf_array_char(&g_blurverticalshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_blurverticalshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_blurverticalshader.pixel);
#line 16
    sjf_shader(&g_blurverticalshader);
#line 16
    g_colors_red._refCount = 1;
#line 2 "lib/sj-lib-ui/color.sj"
    g_colors_red.r = 1.0f;
#line 2
    g_colors_red.g = 0.0f;
#line 2
    g_colors_red.b = 0.0f;
#line 14
    g_colors_red.a = 1.0f;
#line 14
    sjf_color(&g_colors_red);
#line 14
    g_colors_green._refCount = 1;
#line 3
    g_colors_green.r = 0.0f;
#line 3
    g_colors_green.g = 1.0f;
#line 3
    g_colors_green.b = 0.0f;
#line 14
    g_colors_green.a = 1.0f;
#line 14
    sjf_color(&g_colors_green);
#line 14
    g_colors_blue._refCount = 1;
#line 4
    g_colors_blue.r = 0.0f;
#line 4
    g_colors_blue.g = 0.0f;
#line 4
    g_colors_blue.b = 1.0f;
#line 14
    g_colors_blue.a = 1.0f;
#line 14
    sjf_color(&g_colors_blue);
#line 14
    g_colors_black._refCount = 1;
#line 5
    g_colors_black.r = 0.0f;
#line 5
    g_colors_black.g = 0.0f;
#line 5
    g_colors_black.b = 0.0f;
#line 14
    g_colors_black.a = 1.0f;
#line 14
    sjf_color(&g_colors_black);
#line 14
    g_colors_white._refCount = 1;
#line 6
    g_colors_white.r = 1.0f;
#line 6
    g_colors_white.g = 1.0f;
#line 6
    g_colors_white.b = 1.0f;
#line 14
    g_colors_white.a = 1.0f;
#line 14
    sjf_color(&g_colors_white);
#line 14
    g_colors_gray._refCount = 1;
#line 7
    g_colors_gray.r = 0.5f;
#line 7
    g_colors_gray.g = 0.5f;
#line 7
    g_colors_gray.b = 0.5f;
#line 14
    g_colors_gray.a = 1.0f;
#line 14
    sjf_color(&g_colors_gray);
#line 14
    g_fadeshader._refCount = 1;
#line 14
    g_fadeshader.vertex._refCount = 1;
#line 1 "lib/sj-lib-ui/fadeEffect.sj"
    g_fadeshader.vertex.offset = 0;
#line 1
    g_fadeshader.vertex.count = 37;
#line 1
    g_fadeshader.vertex.data._refCount = 1;
#line 1
    g_fadeshader.vertex.data.v = &sjg_string1;
#line 1
    sjf_array_char(&g_fadeshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_fadeshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_fadeshader.vertex);
#line 16
    g_fadeshader.pixel._refCount = 1;
#line 1 "lib/sj-lib-ui/fadeEffect.sj"
    g_fadeshader.pixel.offset = 0;
#line 1
    g_fadeshader.pixel.count = 34;
#line 1
    g_fadeshader.pixel.data._refCount = 1;
#line 1
    g_fadeshader.pixel.data.v = &sjg_string4;
#line 1
    sjf_array_char(&g_fadeshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_fadeshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_fadeshader.pixel);
#line 16
    sjf_shader(&g_fadeshader);
#line 16
    g_fonthash._refCount = 1;
#line 16
    sjf_hash_fontkey_weak_font(&g_fonthash);
#line 16
    g_glviewports._refCount = 1;
#line 16
    g_glviewports.arr._refCount = 1;
#line 27 "lib/sj-lib-common/array.sj"
    g_glviewports.arr.v = 0;
#line 27
    sjf_array_rect(&g_glviewports.arr);
#line 27
    sjf_list_rect(&g_glviewports);
#line 27
    g_glframebuffers._refCount = 1;
#line 27
    g_glframebuffers.arr._refCount = 1;
#line 27
    g_glframebuffers.arr.v = 0;
#line 27
    sjf_array_u32(&g_glframebuffers.arr);
#line 27
    sjf_list_u32(&g_glframebuffers);
#line 340 "lib/sj-lib-ui/gl.sj"
    glid_init();
#line 340
    g_looplastrect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    g_looplastrect.x = 0;
#line 3
    g_looplastrect.y = 0;
#line 4
    g_looplastrect.w = 0;
#line 5
    g_looplastrect.h = 0;
#line 5
    sjf_rect(&g_looplastrect);
#line 3 "lib/sj-lib-ui/loop.sj"
    g_mainloop_lasttick = 0;
#line 4
    g_mainloop_frames = 0;
#line 5
    g_mainloop_showfps = false;
#line 6
    g_mainloop_shouldcontinue = true;
#line 1 "lib/sj-lib-ui/mouse.sj"
    g_mouse_captureelement._parent = 0;
#line 1
    g_boxshader._refCount = 1;
#line 1
    g_boxshader.vertex._refCount = 1;
#line 1 "lib/sj-lib-ui/shader.sj"
    g_boxshader.vertex.offset = 0;
#line 1
    g_boxshader.vertex.count = 37;
#line 1
    g_boxshader.vertex.data._refCount = 1;
#line 1
    g_boxshader.vertex.data.v = &sjg_string5;
#line 1
    sjf_array_char(&g_boxshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_boxshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_boxshader.vertex);
#line 16
    g_boxshader.pixel._refCount = 1;
#line 1 "lib/sj-lib-ui/shader.sj"
    g_boxshader.pixel.offset = 0;
#line 1
    g_boxshader.pixel.count = 37;
#line 1
    g_boxshader.pixel.data._refCount = 1;
#line 1
    g_boxshader.pixel.data.v = &sjg_string6;
#line 1
    sjf_array_char(&g_boxshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_boxshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_boxshader.pixel);
#line 16
    sjf_shader(&g_boxshader);
#line 16
    g_imageshader._refCount = 1;
#line 16
    g_imageshader.vertex._refCount = 1;
#line 2 "lib/sj-lib-ui/shader.sj"
    g_imageshader.vertex.offset = 0;
#line 2
    g_imageshader.vertex.count = 37;
#line 2
    g_imageshader.vertex.data._refCount = 1;
#line 2
    g_imageshader.vertex.data.v = &sjg_string1;
#line 2
    sjf_array_char(&g_imageshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_imageshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_imageshader.vertex);
#line 16
    g_imageshader.pixel._refCount = 1;
#line 2 "lib/sj-lib-ui/shader.sj"
    g_imageshader.pixel.offset = 0;
#line 2
    g_imageshader.pixel.count = 37;
#line 2
    g_imageshader.pixel.data._refCount = 1;
#line 2
    g_imageshader.pixel.data.v = &sjg_string7;
#line 2
    sjf_array_char(&g_imageshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_imageshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_imageshader.pixel);
#line 16
    sjf_shader(&g_imageshader);
#line 16
    g_phongcolorshader._refCount = 1;
#line 16
    g_phongcolorshader.vertex._refCount = 1;
#line 3 "lib/sj-lib-ui/shader.sj"
    g_phongcolorshader.vertex.offset = 0;
#line 3
    g_phongcolorshader.vertex.count = 43;
#line 3
    g_phongcolorshader.vertex.data._refCount = 1;
#line 3
    g_phongcolorshader.vertex.data.v = &sjg_string8;
#line 3
    sjf_array_char(&g_phongcolorshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_phongcolorshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_phongcolorshader.vertex);
#line 16
    g_phongcolorshader.pixel._refCount = 1;
#line 3 "lib/sj-lib-ui/shader.sj"
    g_phongcolorshader.pixel.offset = 0;
#line 3
    g_phongcolorshader.pixel.count = 43;
#line 3
    g_phongcolorshader.pixel.data._refCount = 1;
#line 3
    g_phongcolorshader.pixel.data.v = &sjg_string9;
#line 3
    sjf_array_char(&g_phongcolorshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_phongcolorshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_phongcolorshader.pixel);
#line 16
    sjf_shader(&g_phongcolorshader);
#line 16
    g_phongtextureshader._refCount = 1;
#line 16
    g_phongtextureshader.vertex._refCount = 1;
#line 4 "lib/sj-lib-ui/shader.sj"
    g_phongtextureshader.vertex.offset = 0;
#line 4
    g_phongtextureshader.vertex.count = 47;
#line 4
    g_phongtextureshader.vertex.data._refCount = 1;
#line 4
    g_phongtextureshader.vertex.data.v = &sjg_string10;
#line 4
    sjf_array_char(&g_phongtextureshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_phongtextureshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_phongtextureshader.vertex);
#line 16
    g_phongtextureshader.pixel._refCount = 1;
#line 4 "lib/sj-lib-ui/shader.sj"
    g_phongtextureshader.pixel.offset = 0;
#line 4
    g_phongtextureshader.pixel.count = 47;
#line 4
    g_phongtextureshader.pixel.data._refCount = 1;
#line 4
    g_phongtextureshader.pixel.data.v = &sjg_string11;
#line 4
    sjf_array_char(&g_phongtextureshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_phongtextureshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_phongtextureshader.pixel);
#line 16
    sjf_shader(&g_phongtextureshader);
#line 16
    g_textshader._refCount = 1;
#line 16
    g_textshader.vertex._refCount = 1;
#line 5 "lib/sj-lib-ui/shader.sj"
    g_textshader.vertex.offset = 0;
#line 5
    g_textshader.vertex.count = 41;
#line 5
    g_textshader.vertex.data._refCount = 1;
#line 5
    g_textshader.vertex.data.v = &sjg_string12;
#line 5
    sjf_array_char(&g_textshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_textshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_textshader.vertex);
#line 16
    g_textshader.pixel._refCount = 1;
#line 5 "lib/sj-lib-ui/shader.sj"
    g_textshader.pixel.offset = 0;
#line 5
    g_textshader.pixel.count = 41;
#line 5
    g_textshader.pixel.data._refCount = 1;
#line 5
    g_textshader.pixel.data.v = &sjg_string13;
#line 5
    sjf_array_char(&g_textshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_textshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_textshader.pixel);
#line 16
    sjf_shader(&g_textshader);
#line 16
    g_style._refCount = 1;
#line 16
    sjf_style(&g_style);
#line 16
    g_vertex_location_texture_normal_format._refCount = 1;
#line 1 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    g_vertex_location_texture_normal_format.offset = 0;
#line 1
    g_vertex_location_texture_normal_format.count = 32;
#line 1
    g_vertex_location_texture_normal_format.data._refCount = 1;
#line 1
    g_vertex_location_texture_normal_format.data.v = &sjg_string14;
#line 1
    sjf_array_char(&g_vertex_location_texture_normal_format.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_vertex_location_texture_normal_format._isnullterminated = false;
#line 16
    sjf_string(&g_vertex_location_texture_normal_format);
#line 16
    g_saturateshader._refCount = 1;
#line 16
    g_saturateshader.vertex._refCount = 1;
#line 1 "lib/sj-lib-ui/saturateEffect.sj"
    g_saturateshader.vertex.offset = 0;
#line 1
    g_saturateshader.vertex.count = 37;
#line 1
    g_saturateshader.vertex.data._refCount = 1;
#line 1
    g_saturateshader.vertex.data.v = &sjg_string1;
#line 1
    sjf_array_char(&g_saturateshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_saturateshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_saturateshader.vertex);
#line 16
    g_saturateshader.pixel._refCount = 1;
#line 1 "lib/sj-lib-ui/saturateEffect.sj"
    g_saturateshader.pixel.offset = 0;
#line 1
    g_saturateshader.pixel.count = 38;
#line 1
    g_saturateshader.pixel.data._refCount = 1;
#line 1
    g_saturateshader.pixel.data.v = &sjg_string15;
#line 1
    sjf_array_char(&g_saturateshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_saturateshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_saturateshader.pixel);
#line 16
    sjf_shader(&g_saturateshader);
#line 16
    sjt_call3 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
#line 16
    sjt_call3->_refCount = 1;
#line 16
    sjt_call3->children._refCount = 1;
#line 4 "timer.sj"
    sjt_call3->children.v = createarray(sizeof(sji_element), 2);
#line 4
    sjf_array_heap_iface_element(&sjt_call3->children);
#line 4
    sjs_array_heap_iface_element* array3;
#line 4
    array3 = &sjt_call3->children;
#line 4
    sjt_parent30 = array3;
#line 4
    sjt_functionParam29 = 0;
#line 4
    sjt_call6 = (sjs_scene3delement*)malloc(sizeof(sjs_scene3delement));
#line 4
    sjt_call6->_refCount = 1;
#line 4
    sjt_call6->children._refCount = 1;
#line 6
    sjt_call6->children.v = createarray(sizeof(sji_model), 1);
#line 6
    sjf_array_heap_iface_model(&sjt_call6->children);
#line 6
    sjs_array_heap_iface_model* array2;
#line 6
    array2 = &sjt_call6->children;
#line 6
    sjt_parent85 = array2;
#line 6
    sjt_functionParam107 = 0;
#line 6
    sjt_call11 = (sjs_scene2dmodel*)malloc(sizeof(sjs_scene2dmodel));
#line 6
    sjt_call11->_refCount = 1;
#line 3 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_call11->id._refCount = -1;
#line 103 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjt_functionParam433 = 20;
#line 104
    sjt_functionParam434 = 40;
#line 104
    sjt_call110._refCount = 1;
#line 105
    sjt_call110.x = 0.0f;
#line 105
    sjt_call110.y = 0.0f;
#line 105
    sjt_call110.z = 0.0f;
#line 105
    sjf_vec3(&sjt_call110);
#line 105
    sjt_functionParam435 = &sjt_call110;
#line 105
    sjt_call111._refCount = 1;
#line 106
    sjt_call111.x = 1.0f;
#line 106
    sjt_call111.y = 1.0f;
#line 106
    sjt_call111.z = 1.0f;
#line 106
    sjf_vec3(&sjt_call111);
#line 106
    sjt_functionParam436 = &sjt_call111;
#line 106
    sjf_spherevertexbuffer(sjt_functionParam433, sjt_functionParam434, sjt_functionParam435, sjt_functionParam436, &sjt_call11->vertexbuffer);
#line 106
    sjt_call11->shader._refCount = 1;
#line 7 "timer.sj"
    sjf_shader_copy(&sjt_call11->shader, &g_phongtextureshader);
#line 7
    sjt_call11->texturesize._refCount = 1;
#line 6 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_call11->texturesize.w = 512;
#line 6
    sjt_call11->texturesize.h = 512;
#line 6
    sjf_size(&sjt_call11->texturesize);
#line 6
    sjt_call11->children._refCount = 1;
#line 10 "timer.sj"
    sjt_call11->children.v = createarray(sizeof(sji_element), 2);
#line 10
    sjf_array_heap_iface_element(&sjt_call11->children);
#line 10
    sjs_array_heap_iface_element* array1;
#line 10
    array1 = &sjt_call11->children;
#line 10
    sjt_parent287 = array1;
#line 10
    sjt_functionParam437 = 0;
#line 10
    sjt_call112 = (sjs_imageelement*)malloc(sizeof(sjs_imageelement));
#line 10
    sjt_call112->_refCount = 1;
#line 10
    sjt_call112->image._refCount = 1;
#line 10
    sjt_call120._refCount = 1;
#line 12
    sjt_call120.offset = 0;
#line 12
    sjt_call120.count = 15;
#line 12
    sjt_call120.data._refCount = 1;
#line 12
    sjt_call120.data.v = &sjg_string45;
#line 12
    sjf_array_char(&sjt_call120.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call120._isnullterminated = false;
#line 16
    sjf_string(&sjt_call120);
#line 12 "timer.sj"
    sjt_functionParam464 = &sjt_call120;
#line 12
    sjf_texture_frompng(sjt_functionParam464, &sjt_call112->image.texture);
#line 12
    sjt_call112->image.rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call112->image.rect.x = 0;
#line 3
    sjt_call112->image.rect.y = 0;
#line 4
    sjt_call112->image.rect.w = 0;
#line 5
    sjt_call112->image.rect.h = 0;
#line 5
    sjf_rect(&sjt_call112->image.rect);
#line 5
    sjt_call112->image.margin._refCount = 1;
#line 12 "timer.sj"
    sjt_call112->image.margin.l = 150;
#line 12
    sjt_call112->image.margin.t = 50;
#line 12
    sjt_call112->image.margin.r = 150;
#line 12
    sjt_call112->image.margin.b = 150;
#line 12
    sjf_margin(&sjt_call112->image.margin);
#line 12
    sjf_image(&sjt_call112->image);
#line 12
    sjt_call112->margin._refCount = 1;
#line 2 "lib/sj-lib-ui/margin.sj"
    sjt_call112->margin.l = 0;
#line 3
    sjt_call112->margin.t = 0;
#line 4
    sjt_call112->margin.r = 0;
#line 5
    sjt_call112->margin.b = 0;
#line 5
    sjf_margin(&sjt_call112->margin);
#line 7 "lib/sj-lib-ui/imageElement.sj"
    sjt_call112->stretch = g_imagestretch_fill;
#line 7
    sjt_call112->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call112->_rect.x = 0;
#line 3
    sjt_call112->_rect.y = 0;
#line 4
    sjt_call112->_rect.w = 0;
#line 5
    sjt_call112->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call112->_rect);
#line 12 "lib/sj-lib-ui/imageElement.sj"
    sjt_call112->_imagerenderer._refCount = -1;
#line 12
    sjf_imageelement_heap(sjt_call112);
#line 11 "timer.sj"
    sjt_cast39 = sjt_call112;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_imageelement_as_sji_element(sjt_cast39, &sjt_functionParam438);
    if (sjt_functionParam438._parent != 0) {
        sjt_functionParam438._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent287, sjt_functionParam437, sjt_functionParam438);
#line 10 "timer.sj"
    sjt_parent297 = array1;
#line 10
    sjt_functionParam465 = 1;
#line 10
    sjt_call121 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
#line 10
    sjt_call121->_refCount = 1;
#line 10
    sjt_call121->color._refCount = 1;
#line 14
    sjf_color_copy(&sjt_call121->color, &g_colors_blue);
#line 14
    sjt_call121->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call121->_rect.x = 0;
#line 3
    sjt_call121->_rect.y = 0;
#line 4
    sjt_call121->_rect.w = 0;
#line 5
    sjt_call121->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call121->_rect);
#line 4 "lib/sj-lib-ui/crossHairsElement.sj"
    sjt_call121->_topdownrenderer._refCount = -1;
#line 5
    sjt_call121->_leftrightrenderer._refCount = -1;
#line 5
    sjt_call121->_point._refCount = 1;
#line 2 "lib/sj-lib-ui/point.sj"
    sjt_call121->_point.x = 0;
#line 3
    sjt_call121->_point.y = 0;
#line 3
    sjf_point(&sjt_call121->_point);
#line 3
    sjf_crosshairselement_heap(sjt_call121);
#line 14 "timer.sj"
    sjt_cast48 = sjt_call121;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_crosshairselement_as_sji_element(sjt_cast48, &sjt_functionParam466);
    if (sjt_functionParam466._parent != 0) {
        sjt_functionParam466._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent297, sjt_functionParam465, sjt_functionParam466);
#line 8 "lib/sj-lib-ui/scene2dModel.sj"
    sjt_call11->hasalpha = false;
#line 8
    sjt_call11->center._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
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
#line 2 "lib/sj-lib-ui/size.sj"
    sjt_call11->_innerscene._size.w = 0;
#line 3
    sjt_call11->_innerscene._size.h = 0;
#line 3
    sjf_size(&sjt_call11->_innerscene._size);
#line 3
    sjt_call11->_innerscene.model._refCount = 1;
#line 2 "lib/sj-lib-ui/mat4.sj"
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
#line 2 "lib/sj-lib-ui/rect.sj"
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
#line 2 "lib/sj-lib-ui/mat4.sj"
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
#line 2 "lib/sj-lib-ui/scene3dElement.sj"
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
#line 2 "lib/sj-lib-ui/vec4.sj"
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
#line 2 "lib/sj-lib-ui/size.sj"
    sjt_call11->_framebuffer.size.w = 0;
#line 3
    sjt_call11->_framebuffer.size.h = 0;
#line 3
    sjf_size(&sjt_call11->_framebuffer.size);
#line 3 "lib/sj-lib-ui/framebuffer.sj"
    sjt_call11->_framebuffer.id = (uint32_t)0u;
#line 3
    sjf_framebuffer(&sjt_call11->_framebuffer);
#line 3
    sjt_call11->_texture._refCount = 1;
#line 3
    sjt_call11->_texture.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    sjt_call11->_texture.size.w = 0;
#line 3
    sjt_call11->_texture.size.h = 0;
#line 3
    sjf_size(&sjt_call11->_texture.size);
#line 3 "lib/sj-lib-ui/texture.sj"
    sjt_call11->_texture.id = (uint32_t)0u;
#line 3
    sjf_texture(&sjt_call11->_texture);
#line 3
    sjt_call11->_renderbuffer._refCount = 1;
#line 3
    sjt_call11->_renderbuffer.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    sjt_call11->_renderbuffer.size.w = 0;
#line 3
    sjt_call11->_renderbuffer.size.h = 0;
#line 3
    sjf_size(&sjt_call11->_renderbuffer.size);
#line 3 "lib/sj-lib-ui/renderbuffer.sj"
    sjt_call11->_renderbuffer.id = (uint32_t)0u;
#line 3
    sjf_renderbuffer(&sjt_call11->_renderbuffer);
#line 3
    sjf_scene2dmodel_heap(sjt_call11);
#line 7 "timer.sj"
    sjt_cast6 = sjt_call11;
#line 1 "lib/sj-lib-ui/model.sj"
    sjf_scene2dmodel_as_sji_model(sjt_cast6, &sjt_functionParam108);
    if (sjt_functionParam108._parent != 0) {
        sjt_functionParam108._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_model_initat(sjt_parent85, sjt_functionParam107, sjt_functionParam108);
#line 1
    sjt_call6->camera._refCount = 1;
#line 13 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_call6->camera.x = 0.0f;
#line 13
    sjt_call6->camera.y = 0.0f;
#line 13
    result13 = -5.0f;
#line 13
    sjt_call6->camera.z = result13;
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
#line 2 "lib/sj-lib-ui/mat4.sj"
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
#line 2 "lib/sj-lib-ui/rect.sj"
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
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_scene3delement_as_sji_element(sjt_cast3, &sjt_functionParam30);
    if (sjt_functionParam30._parent != 0) {
        sjt_functionParam30._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent30, sjt_functionParam29, sjt_functionParam30);
#line 4 "timer.sj"
    sjt_parent302 = array3;
#line 4
    sjt_functionParam471 = 1;
#line 4
    sjt_call122 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
#line 4
    sjt_call122->_refCount = 1;
#line 4
    sjt_call122->color._refCount = 1;
#line 21
    sjf_color_copy(&sjt_call122->color, &g_colors_red);
#line 21
    sjt_call122->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call122->_rect.x = 0;
#line 3
    sjt_call122->_rect.y = 0;
#line 4
    sjt_call122->_rect.w = 0;
#line 5
    sjt_call122->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call122->_rect);
#line 4 "lib/sj-lib-ui/crossHairsElement.sj"
    sjt_call122->_topdownrenderer._refCount = -1;
#line 5
    sjt_call122->_leftrightrenderer._refCount = -1;
#line 5
    sjt_call122->_point._refCount = 1;
#line 2 "lib/sj-lib-ui/point.sj"
    sjt_call122->_point.x = 0;
#line 3
    sjt_call122->_point.y = 0;
#line 3
    sjf_point(&sjt_call122->_point);
#line 3
    sjf_crosshairselement_heap(sjt_call122);
#line 21 "timer.sj"
    sjt_cast49 = sjt_call122;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_crosshairselement_as_sji_element(sjt_cast49, &sjt_functionParam472);
    if (sjt_functionParam472._parent != 0) {
        sjt_functionParam472._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent302, sjt_functionParam471, sjt_functionParam472);
#line 1
    sjt_call3->margin._refCount = 1;
#line 2 "lib/sj-lib-ui/margin.sj"
    sjt_call3->margin.l = 0;
#line 3
    sjt_call3->margin.t = 0;
#line 4
    sjt_call3->margin.r = 0;
#line 5
    sjt_call3->margin.b = 0;
#line 5
    sjf_margin(&sjt_call3->margin);
#line 4 "lib/sj-lib-ui/fillLayout.sj"
    sjt_call3->effect._parent = 0;
#line 4
    sjt_call3->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
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
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_filllayout_as_sji_element(sjt_cast2, &g_root);
    if (g_root._parent != 0) {
        g_root._parent->_refCount++;
    }

#line 1
    sjf_runloop();
    main_destroy();
    return 0;
}

void main_destroy() {

    if (g_mouse_captureelement._parent != 0) {
        g_mouse_captureelement._parent->_refCount--;
        if (g_mouse_captureelement._parent->_refCount <= 0) {
            g_mouse_captureelement._vtbl->destroy(g_mouse_captureelement._parent);
            free(g_mouse_captureelement._parent);
        }
    }
    if (g_root._parent != 0) {
        g_root._parent->_refCount--;
        if (g_root._parent->_refCount <= 0) {
            g_root._vtbl->destroy(g_root._parent);
            free(g_root._parent);
        }
    }
    sjt_call11->_refCount--;
    if (sjt_call11->_refCount <= 0) {
        weakptr_release(sjt_call11);
        sjf_scene2dmodel_destroy(sjt_call11);
        free(sjt_call11);
    }
    sjt_call112->_refCount--;
    if (sjt_call112->_refCount <= 0) {
        weakptr_release(sjt_call112);
        sjf_imageelement_destroy(sjt_call112);
        free(sjt_call112);
    }
    sjt_call121->_refCount--;
    if (sjt_call121->_refCount <= 0) {
        weakptr_release(sjt_call121);
        sjf_crosshairselement_destroy(sjt_call121);
        free(sjt_call121);
    }
    sjt_call122->_refCount--;
    if (sjt_call122->_refCount <= 0) {
        weakptr_release(sjt_call122);
        sjf_crosshairselement_destroy(sjt_call122);
        free(sjt_call122);
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
    if (sjt_functionParam108._parent != 0) {
        sjt_functionParam108._parent->_refCount--;
        if (sjt_functionParam108._parent->_refCount <= 0) {
            sjt_functionParam108._vtbl->destroy(sjt_functionParam108._parent);
            free(sjt_functionParam108._parent);
        }
    }
    if (sjt_functionParam30._parent != 0) {
        sjt_functionParam30._parent->_refCount--;
        if (sjt_functionParam30._parent->_refCount <= 0) {
            sjt_functionParam30._vtbl->destroy(sjt_functionParam30._parent);
            free(sjt_functionParam30._parent);
        }
    }
    if (sjt_functionParam438._parent != 0) {
        sjt_functionParam438._parent->_refCount--;
        if (sjt_functionParam438._parent->_refCount <= 0) {
            sjt_functionParam438._vtbl->destroy(sjt_functionParam438._parent);
            free(sjt_functionParam438._parent);
        }
    }
    if (sjt_functionParam466._parent != 0) {
        sjt_functionParam466._parent->_refCount--;
        if (sjt_functionParam466._parent->_refCount <= 0) {
            sjt_functionParam466._vtbl->destroy(sjt_functionParam466._parent);
            free(sjt_functionParam466._parent);
        }
    }
    if (sjt_functionParam472._parent != 0) {
        sjt_functionParam472._parent->_refCount--;
        if (sjt_functionParam472._parent->_refCount <= 0) {
            sjt_functionParam472._vtbl->destroy(sjt_functionParam472._parent);
            free(sjt_functionParam472._parent);
        }
    }
    if (g_animator._refCount == 1) { sjf_animator_destroy(&g_animator); }
;
    if (g_blurhorizontalshader._refCount == 1) { sjf_shader_destroy(&g_blurhorizontalshader); }
;
    if (g_blurverticalshader._refCount == 1) { sjf_shader_destroy(&g_blurverticalshader); }
;
    if (g_boxshader._refCount == 1) { sjf_shader_destroy(&g_boxshader); }
;
    if (g_colors_black._refCount == 1) { sjf_color_destroy(&g_colors_black); }
;
    if (g_colors_blue._refCount == 1) { sjf_color_destroy(&g_colors_blue); }
;
    if (g_colors_gray._refCount == 1) { sjf_color_destroy(&g_colors_gray); }
;
    if (g_colors_green._refCount == 1) { sjf_color_destroy(&g_colors_green); }
;
    if (g_colors_red._refCount == 1) { sjf_color_destroy(&g_colors_red); }
;
    if (g_colors_white._refCount == 1) { sjf_color_destroy(&g_colors_white); }
;
    if (g_elementsbyid._refCount == 1) { sjf_hash_string_weak_iface_element_destroy(&g_elementsbyid); }
;
    if (g_fadeshader._refCount == 1) { sjf_shader_destroy(&g_fadeshader); }
;
    if (g_fonthash._refCount == 1) { sjf_hash_fontkey_weak_font_destroy(&g_fonthash); }
;
    if (g_glframebuffers._refCount == 1) { sjf_list_u32_destroy(&g_glframebuffers); }
;
    if (g_glviewports._refCount == 1) { sjf_list_rect_destroy(&g_glviewports); }
;
    if (g_imageshader._refCount == 1) { sjf_shader_destroy(&g_imageshader); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (g_looplastrect._refCount == 1) { sjf_rect_destroy(&g_looplastrect); }
;
    if (g_modelsbyid._refCount == 1) { sjf_hash_string_weak_iface_model_destroy(&g_modelsbyid); }
;
    if (g_phongcolorshader._refCount == 1) { sjf_shader_destroy(&g_phongcolorshader); }
;
    if (g_phongtextureshader._refCount == 1) { sjf_shader_destroy(&g_phongtextureshader); }
;
    if (g_rootscene._refCount == 1) { sjf_scene2d_destroy(&g_rootscene); }
;
    if (g_rootwindowrenderer._refCount == 1) { sjf_windowrenderer_destroy(&g_rootwindowrenderer); }
;
    if (g_saturateshader._refCount == 1) { sjf_shader_destroy(&g_saturateshader); }
;
    if (g_style._refCount == 1) { sjf_style_destroy(&g_style); }
;
    if (g_textshader._refCount == 1) { sjf_shader_destroy(&g_textshader); }
;
    if (g_vertex_location_texture_normal_format._refCount == 1) { sjf_string_destroy(&g_vertex_location_texture_normal_format); }
;
    if (sjt_call110._refCount == 1) { sjf_vec3_destroy(&sjt_call110); }
;
    if (sjt_call111._refCount == 1) { sjf_vec3_destroy(&sjt_call111); }
;
    if (sjt_call120._refCount == 1) { sjf_string_destroy(&sjt_call120); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
